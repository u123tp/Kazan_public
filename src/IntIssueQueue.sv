
`timescale 1ns / 1ps
// 整数レジスタのissue queue
// 
// TODO:bank_idx = al_idx[BANK_IDX_WIDHT-1:0] とする.これはLSUでも同様のバンクの分け方を行うことで,lsuがバンク化できるようになるから.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"

module IntIssueQueue
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
#(
) (
    input logic clock,
    input logic reset,

    input vuop_front_t op_in[NUM_OF_FETCH],

    // 算術命令のop_out
    output vuop_front_t op_out_ari[NUM_OF_ARI_ISSUE],
    output vuop_front_t op_out_div[NUM_OF_DIV_ISSUE],
    output vuop_front_t op_out_ld[NUM_OF_LD_ISSUE],
    output vuop_front_t op_out_st_amo[NUM_OF_ST_AMO_ISSUE],
    output vuop_front_t op_out_csr[NUM_OF_CSR_ISSUE],

    // 結果のフィードバック. rs1,rs2のreadyを更新する
    input feedback_rd_t feedback[NUM_OF_RESULT_FEEDBACKS],

    // rawハザード発見時にlusから来るフィードバック.
    // ld wait tableの更新用.
    input logic ld_speculative_feedback_valid,
    input logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx,

    // renamerからal_rpを受け取る. 
    // lwtでin_orderになっているものは,このal_rpとal_idxが一致したときに発行可能となる. 
    input logic [AL_IDX_WIDTH-1:0] al_rp,

    // 制御信号
    input logic flush_in,

    // 次の命令を受ける空きが無い(=満タン)か.
    output logic stall_out,

    // stallが1の場合,次のサイクル立ち上がりでop_outを出さないようにする.
    input logic stall_in_from_ldst,
    input logic stall_in_from_csr,
    input logic stall_in_from_div,

    // FORDEBUG
    input int unsigned generation
);

  // ----------------------------------------------------------------------
  // パラメータ
  // ----------------------------------------------------------------------

  // バンクごとのiiqのサイズ.
  // 今は16なので全部で16*4=64個格納できるが,後で8に落とす
  localparam int unsigned IIQ_SIZE = 4;
  localparam int unsigned IIQ_IDX_WIDTH = $clog2(IIQ_SIZE);

  localparam int unsigned NUM_OF_LWT_SETS = 64;
  localparam int unsigned LWT_SET_IDX_WIDTH = $clog2(NUM_OF_LWT_SETS);
  // opは4byte単位なので下2bitは切り捨て
  localparam int unsigned LWT_IDX_LSB = 2;
  localparam int unsigned LWT_IDX_MSB = LWT_IDX_LSB + LWT_SET_IDX_WIDTH - 1;


  localparam int unsigned NUM_OF_BANK = NUM_OF_FETCH;
  localparam int unsigned BANK_IDX_WIDTH = $clog2(NUM_OF_BANK);


  // ----------------------------------------------------------------------------------------
  // iiq
  // ----------------------------------------------------------------------------------------

  // Integer Issue Queue
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] op_addr;
    opcode_t opcode;
    logic rd_exist;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] imm;
  } iiq_data_t;


  typedef struct packed {
    logic valid;
    opcode_type_e op_type;
    logic rs1_exist;
    logic rs2_exist;
    // logic rs1_ready;
    // logic rs2_ready;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs2;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    logic [LWT_SET_IDX_WIDTH-1:0] lwt_idx;
  } iiq_meta_t;

  // (* ram_style="block" *) iiq_data_t iiq_data[NUM_OF_BANK][IIQ_SIZE];

  logic iiq_data_r_en[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH-1:0] iiq_data_r_idx[NUM_OF_BANK];
  logic [$bits(iiq_data_t)-1:0] iiq_data_r_data_bit[NUM_OF_BANK];

  logic iiq_data_w_en[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH-1:0] iiq_data_w_idx[NUM_OF_BANK];
  logic [$bits(iiq_data_t)-1:0] iiq_data_w_data_bit[NUM_OF_BANK];

  // 入出力はbit列なので構造体に変換したものをこのモジュールでは操作する.
  iiq_data_t iiq_data_r_data_strc[NUM_OF_BANK];
  iiq_data_t iiq_data_w_data_strc[NUM_OF_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      iiq_data_r_data_strc[i] = iiq_data_r_data_bit[i];
      iiq_data_w_data_bit[i]  = iiq_data_w_data_strc[i];
    end
  end

  genvar iiq_data_bank_idx;
  generate
    for (iiq_data_bank_idx = 0; iiq_data_bank_idx < NUM_OF_BANK; iiq_data_bank_idx++) begin
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(iiq_data_t)),
          .RAM_DEPTH(IIQ_SIZE)
      ) iiq_data_ram (
          .clock(clock),
          .r_en(iiq_data_r_en[iiq_data_bank_idx]),
          .r_ram_idx(iiq_data_r_idx[iiq_data_bank_idx]),
          .r_data(iiq_data_r_data_bit[iiq_data_bank_idx]),
          .w_en(iiq_data_w_en[iiq_data_bank_idx]),
          .w_ram_idx(iiq_data_w_idx[iiq_data_bank_idx]),
          .w_data(iiq_data_w_data_bit[iiq_data_bank_idx])
      );
    end
  endgenerate

  iiq_meta_t iiq_meta[NUM_OF_BANK][IIQ_SIZE];
  iiq_meta_t iiq_meta_next[NUM_OF_BANK][IIQ_SIZE];


  // 読み出したデータ.
  // op_iiq_dataはalways_ffで読み取るが,
  // op_iiq_metaはiiq_meta_nextからop_iiq_meta_nextを作ってそれをalways_ffでop_iiq_meta<= op_iiq_meta_nextとする
  // iiq_data_t op_iiq_data[NUM_OF_BANK];
  iiq_meta_t op_iiq_meta[NUM_OF_BANK];
  iiq_meta_t op_iiq_meta_next[NUM_OF_BANK];


  logic iiq_issue_valid[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH-1:0] iiq_issue_rp[NUM_OF_BANK];
  logic iiq_issue_valid_next[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH-1:0] iiq_issue_rp_next[NUM_OF_BANK];
  // ラウンドロビン用にbank_idxをどこから始めるかを記録しておく.
  logic [BANK_IDX_WIDTH-1:0] iiq_issue_bank_idx;

  // --------------------------------------------------------------
  // iiqのどこが空いているかを示すfreelist
  // --------------------------------------------------------------
  logic [IIQ_IDX_WIDTH-1:0] freelist[NUM_OF_BANK][IIQ_SIZE];
  logic [IIQ_IDX_WIDTH-1:0] freelist_rp[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH-1:0] freelist_wp[NUM_OF_BANK];
  logic [IIQ_IDX_WIDTH:0] noei_freelist[NUM_OF_BANK];

  typedef struct packed {
    logic valid;
    logic [IIQ_IDX_WIDTH-1:0] iiq_idx;
  } freelist_update_t;
  logic freelist_used[NUM_OF_BANK];
  freelist_update_t freelist_freed[NUM_OF_BANK];


  // --------------------------------------------------------------------------------
  // busy table
  // --------------------------------------------------------------------------------
  // 現在まだ結果がレジスタファイルに反映されていない物理レジスタ一覧.
  // 逆に0なら既に準備ができているので,rsとして使用できる.
  logic bt[NUM_OF_PHYREGS];
  logic bt_next[NUM_OF_PHYREGS];


  // -----------------------------------------------------------
  // load_wait_table
  // -----------------------------------------------------------
  // これが1になっているld命令は,投機的に発行せず,バッファの先頭に来るまで待つ.
  // なぜならこれが1な時点で一回ミスをしているということだから.
  // あと,lwtは定期的にリセットする.
  // とりあえずダイレクトマップで作ったけど,本当は4wayとかで作ったほうがいいかも.
  // ただ,別に予測ミスってもin order で発行されるだけだしそこまでのペナルティじゃないからこのままダイレクトマップでもいいかも.
  // op_addrの下位ビットでインデックスを決定する.
  logic lwt[NUM_OF_LWT_SETS];

  // 今回のサイクルでlwtをアップデートするか.
  logic update_lwt;
  logic update_lwt_next;

  logic [10:0] lwt_counter;
  logic [10:0] lwt_counter_next;

  // ----------------------------------------------------------------------------
  // pc_talbe
  // ----------------------------------------------------------------------------
  // ld_speculative_al_idxからpcを特定するためにal_idxに対応するpcを用意しておく.
  // opが入ってきたときに登録され,lsuで実行されるのは必ず上書き登録されるので,flushは不要.
  logic pt_r_en[1];
  logic [AL_IDX_WIDTH-1:0] pt_r_ram_idx[1];
  logic [VADDR_WIDTH-1:0] pt_r_data[1];

  logic pt_w_en[NUM_OF_FETCH];
  logic [AL_IDX_WIDTH-1:0] pt_w_ram_idx[NUM_OF_FETCH];
  logic [VADDR_WIDTH-1:0] pt_w_data[NUM_OF_FETCH];


  LVTRAM #(
      .RAM_WIDTH(VADDR_WIDTH),
      .RAM_DEPTH(ACTIVELIST_SIZE),
      .NUM_OF_READ_PORT(1),
      .NUM_OF_WRITE_PORT(NUM_OF_FETCH)
  ) pc_table (
      .clock(clock),
      .reset(reset),
      .r_en(pt_r_en),
      .r_ram_idx(pt_r_ram_idx),
      .r_data(pt_r_data),
      .w_en(pt_w_en),
      .w_ram_idx(pt_w_ram_idx),
      .w_data(pt_w_data)
  );



  always_comb begin

    // iiq_meta,bt
    iiq_meta_next = iiq_meta;
    bt_next = bt;

    freelist_used = '{default: 0};


    // -------------------------------------------------------------------------------
    // 新しく入ってきた命令をiiqに入れる.
    // -------------------------------------------------------------------------------
    // op_in => iiq_next, bt_next
    iiq_data_w_en = '{default: 0};
    iiq_data_w_idx = '{default: 0};
    iiq_data_w_data_strc = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = op_in[i].al_idx[BANK_IDX_WIDTH-1:0];
      if (op_in[i].valid) begin
        // iiq_dataへの書き込み.
        iiq_data_w_en[bank_idx] = 1;
        iiq_data_w_idx[bank_idx] = freelist[bank_idx][freelist_rp[bank_idx]];
        iiq_data_w_data_strc[bank_idx] = '{
            op_addr: op_in[i].op_addr,
            opcode: op_in[i].opcode,
            rd_exist: op_in[i].rd_exist,
            rd: op_in[i].rd,
            imm: op_in[i].imm
        };
        // iiq_metaへの書き込み.
        iiq_meta_next[bank_idx][freelist[bank_idx][freelist_rp[bank_idx]]] = '{
            valid: 1,
            op_type: get_opcode_type(op_in[i].opcode),
            rs1_exist: op_in[i].rs1_exist,
            rs2_exist: op_in[i].rs2_exist,
            rs1: op_in[i].rs1,
            rs2: op_in[i].rs2,
            al_idx: op_in[i].al_idx,
            lwt_idx: op_in[i].op_addr[LWT_IDX_MSB:LWT_IDX_LSB]
        };

        // freelistを使用した通知
        freelist_used[bank_idx] = 1;

        // btの更新.
        if (op_in[i].rd_exist && op_in[i].rd != 0) begin
          bt_next[op_in[i].rd] = 1;
          if (op_in[i].rd == 26) begin
            //  $display("[LOG][IntIssueQueue.sv] bt[26] on generation:%h", generation);
          end
        end
      end
    end

    // ----------------------------------------------------------------------------------------------
    // feedback => bt_next
    // ----------------------------------------------------------------------------------------------

    // feedback => bt_next
    for (int unsigned fb_idx = 0; fb_idx < NUM_OF_RESULT_FEEDBACKS; fb_idx++) begin
      if (feedback[fb_idx].valid) begin
        bt_next[feedback[fb_idx].rd] = 0;
        if (feedback[fb_idx].rd == 26) begin
          // $display("[LOG][IntIssueQueue.sv] bt[26] off generation:%h", generation);
        end
      end
    end


    // ---------------------------------------------------------------------
    // iiq_meta_next => data_to_read
    // ---------------------------------------------------------------------
    // 
    begin
      automatic int unsigned ari_counter = 0;
      automatic int unsigned div_counter = 0;
      automatic int unsigned ld_counter = 0;
      automatic int unsigned stamo_counter = 0;
      automatic int unsigned csr_counter = 0;

      iiq_data_r_en = '{default: 0};
      iiq_data_r_idx = '{default: 0};
      op_iiq_meta_next = '{default: 0};
      freelist_freed = '{default: 0};

      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        // ラウンドロビンでbank_idxの開始を決める.
        automatic
        logic [BANK_IDX_WIDTH-1:0]
        bank_idx = BANK_IDX_WIDTH'(iiq_issue_bank_idx + BANK_IDX_WIDTH'(i));
        automatic iiq_meta_t iiq_ent = iiq_meta_next[bank_idx][iiq_issue_rp[bank_idx]];

        // rs1,rs2がそれぞれデータがint prfに来ているか.
        // 前サイクルでなるべくrpがrs1,rs2ともにreadyとなっているものを探すように努力するが,
        // だからといってrpがrs1,rs2ともにreadyなものを指定できない場合もある(すべてのエントリがreadyでないなど)
        // そのため,ここでもreadyかを確認する.
        automatic
        logic
        rs_ready_to_issue = (!iiq_ent.rs1_exist || !bt_next[iiq_ent.rs1]) && (!iiq_ent.rs2_exist || !bt_next[iiq_ent.rs2]);


        // 次の命令が各種命令ごとに実行可能か.
        automatic
        logic
        ari_issue_ava = iiq_ent.op_type != ARITH_OPCODE || ari_counter < NUM_OF_ARI_ISSUE;
        automatic
        logic
        div_issue_ava = iiq_ent.op_type != DIV_OPCODE || (div_counter < NUM_OF_DIV_ISSUE && !stall_in_from_div);
        automatic
        logic
        ld_issue_ava = iiq_ent.op_type != LD_OPCODE || (ld_counter < NUM_OF_LD_ISSUE && !stall_in_from_ldst);
        automatic
        logic
        stamo_issue_ava = iiq_ent.op_type != STAMO_OPCODE || (stamo_counter < NUM_OF_ST_AMO_ISSUE && !stall_in_from_ldst);
        automatic
        logic
        csr_issue_ava = iiq_ent.op_type != CSR_OPCODE || (csr_counter < NUM_OF_CSR_ISSUE && !stall_in_from_csr) ;

        if (iiq_issue_valid[bank_idx] && rs_ready_to_issue &&ari_issue_ava && div_issue_ava && ld_issue_ava && stamo_issue_ava && csr_issue_ava) begin
          // iiq_dataの読み取り.
          iiq_data_r_en[bank_idx] = 1;
          iiq_data_r_idx[bank_idx] = iiq_issue_rp[bank_idx];

          op_iiq_meta_next[bank_idx] = iiq_meta[bank_idx][iiq_issue_rp[bank_idx]];
          // freelistに戻す. 
          freelist_freed[bank_idx] = '{valid: 1, iiq_idx: iiq_issue_rp[bank_idx]};
          // iiq_metaのこのエントリの部分を無効化.
          iiq_meta_next[bank_idx][iiq_issue_rp[bank_idx]].valid = 0;

          case (iiq_ent.op_type)
            ARITH_OPCODE: begin
              ari_counter = ari_counter + 1;
            end
            DIV_OPCODE: begin
              div_counter = div_counter + 1;
            end
            LD_OPCODE: begin
              ld_counter = ld_counter + 1;
            end
            STAMO_OPCODE: begin
              stamo_counter = stamo_counter + 1;
            end
            CSR_OPCODE: begin
              csr_counter = csr_counter + 1;
            end
            default: begin
              $display("[ERROR][IntIssueQueue.sv] invalid opcode");
            end
          endcase
        end
      end


      // iiq_issue_rpの更新
      // iiqを最大でバンクごとに4つまで探索し,発行可能なrpで止まる.
      // 基本的にrpの更新では,このサイクルで成立するならば次のサイクルでも成立する条件のみで照合を行う.
      // よってstall信号などは,実際にiiq_data_r_enとかを作る方の処理で照会する.
      begin
        automatic iiq_meta_t iiq_ent;
        automatic logic csr_issue_avail = 0;
        automatic logic ld_issue_avail = 0;

        // iiq_issue_rp_nextは使用していなくても次に行く方式. 
        iiq_issue_valid_next = '{default: 0};
        iiq_issue_rp_next = iiq_issue_rp;

        for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
          for (int unsigned i = 0; i < 4; i++) begin
            iiq_issue_rp_next[bank_idx] = iiq_issue_rp_next[bank_idx] + IIQ_IDX_WIDTH'(1);
            iiq_ent = iiq_meta_next[bank_idx][iiq_issue_rp_next[bank_idx]];
            // csr場合の発行可能かの条件.
            csr_issue_avail = iiq_ent.op_type != CSR_OPCODE || (iiq_ent.al_idx == al_rp);
            // ldの場合の発行可能かの条件
            ld_issue_avail = iiq_ent.op_type != LD_OPCODE || (!lwt[iiq_ent.lwt_idx] || al_rp == iiq_ent.al_idx);
            // ld_issue_avail = 1;
            // 発行可能であれば,そこでrpの更新を終了する.
            if(iiq_ent.valid && (!iiq_ent.rs1_exist || !bt_next[iiq_ent.rs1]) && (!iiq_ent.rs2_exist || !bt_next[iiq_ent.rs2]) 
              && csr_issue_avail && ld_issue_avail)begin
              iiq_issue_valid_next[bank_idx] = 1;
              break;
            end
          end
        end
      end

    end


  end

  // -------------------------------------------------------------------------
  // pc_talbeの更新.
  // -------------------------------------------------------------------------
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      if (op_in[i].valid) begin
        pt_w_en[i] = 1;
        pt_w_ram_idx[i] = op_in[i].al_idx;
        pt_w_data[i] = op_in[i].op_addr;
      end else begin
        pt_w_en[i] = 0;
        pt_w_ram_idx[i] = 0;
        pt_w_data[i] = 0;
      end
    end
  end

  // -------------------------------------------------------------------------
  // lwtの更新
  // -------------------------------------------------------------------------
  always_comb begin
    // 次サイクルにlwt_nextを更新するための用意.
    // 複数サイクルかけるのは,lwtを更新する前に,それに対応するpaddrを同期ramから取り出すのに1サイクルかかるから.
    if (ld_speculative_feedback_valid) begin
      pt_r_en[0] = 1;
      pt_r_ram_idx[0] = ld_speculative_feedback_al_idx;
      update_lwt_next = 1;
    end else begin
      pt_r_en[0] = 0;
      pt_r_ram_idx[0] = 0;
      update_lwt_next = 0;
    end
  end
  always_comb begin

  end

  // ----------------------------------------------------------------------------
  // stall
  // ----------------------------------------------------------------------------
  always_comb begin
    stall_out = 0;
    for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
      if (noei_freelist[bank_idx] < 2) begin
        stall_out = 1;
      end
    end
  end

  // ------------------------------------------------------------------------------------------------
  // op_iiq_data, op_iiq_meta から op_out の作成
  // ------------------------------------------------------------------------------------------------
  always_comb begin
    automatic int unsigned ari_counter = 0;
    automatic int unsigned div_counter = 0;
    automatic int unsigned ld_counter = 0;
    automatic int unsigned stamo_counter = 0;
    automatic int unsigned csr_counter = 0;
    op_out_ari = '{default: 0};
    op_out_div = '{default: 0};
    op_out_ld = '{default: 0};
    op_out_st_amo = '{default: 0};
    op_out_csr = '{default: 0};
    for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
      automatic vuop_front_t op = '{default: 0, opcode: NOP};
      if (op_iiq_meta[bank_idx].valid) begin
        op = '{
            valid: 1,
            opcode: iiq_data_r_data_strc[bank_idx].opcode,
            op_addr: iiq_data_r_data_strc[bank_idx].op_addr,
            rs1_exist: op_iiq_meta[bank_idx].rs1_exist,
            rs2_exist: op_iiq_meta[bank_idx].rs2_exist,
            rd_exist: iiq_data_r_data_strc[bank_idx].rd_exist,
            rs1: op_iiq_meta[bank_idx].rs1,
            rs2: op_iiq_meta[bank_idx].rs2,
            rd: iiq_data_r_data_strc[bank_idx].rd,
            imm: iiq_data_r_data_strc[bank_idx].imm,
            al_idx: op_iiq_meta[bank_idx].al_idx
        };
        if (op_iiq_meta[bank_idx].op_type == ARITH_OPCODE) begin
          if (ari_counter < NUM_OF_ARI_ISSUE) begin
            op_out_ari[ari_counter] = op;
            ari_counter++;
          end

        end else if (op_iiq_meta[bank_idx].op_type == DIV_OPCODE) begin
          if (div_counter < NUM_OF_DIV_ISSUE) begin
            op_out_div[div_counter] = op;
            div_counter++;
          end
        end else if (op_iiq_meta[bank_idx].op_type == LD_OPCODE) begin
          if (ld_counter < NUM_OF_LD_ISSUE) begin
            op_out_ld[ld_counter] = op;
            ld_counter++;
          end

        end else if (op_iiq_meta[bank_idx].op_type == STAMO_OPCODE) begin
          if (stamo_counter < NUM_OF_ST_AMO_ISSUE) begin
            op_out_st_amo[stamo_counter] = op;
            stamo_counter++;
          end

        end else if (op_iiq_meta[bank_idx].op_type == CSR_OPCODE) begin
          if (csr_counter < NUM_OF_CSR_ISSUE) begin
            op_out_csr[csr_counter] = op;
            csr_counter++;
          end
        end
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin

      // lwt 
      update_lwt <= 0;
      lwt_counter <= 0;
      lwt <= '{default: 0};

      // bt
      bt <= '{default: 0};

      // iiq
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        for (int unsigned j = 0; j < IIQ_SIZE; j++) begin
          iiq_meta[i][j] <= '0;
        end
      end


      // op_iiq
      op_iiq_meta <= '{default: '0};

      // freelist
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        for (int unsigned iiq_idx = 0; iiq_idx < IIQ_SIZE; iiq_idx++) begin
          freelist[bank_idx][iiq_idx] <= IIQ_IDX_WIDTH'(iiq_idx);
        end
      end
      freelist_rp <= '{default: 0};
      freelist_wp <= '{default: 0};
      // noei_freelist <= '{default: (IIQ_IDX_WIDTH + 1)'(IIQ_SIZE)};
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        noei_freelist[bank_idx] <= (IIQ_IDX_WIDTH + 1)'(IIQ_SIZE);
      end

      // iiq_issue
      iiq_issue_valid <= '{default: 0};
      iiq_issue_rp <= '{default: 0};
      iiq_issue_bank_idx <= 0;

    end else if (flush_in) begin
      // lwt 
      update_lwt <= 0;
      // flushではlwtをリセットしない.
      // lwt_counter <= 0;
      // lwt <= '{default: 0};

      // bt
      bt <= '{default: 0};

      // iiq
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        for (int unsigned j = 0; j < IIQ_SIZE; j++) begin
          iiq_meta[i][j] <= '0;
        end
      end

      // op_iiq
      op_iiq_meta <= '{default: '0};

      // freelist
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        for (int unsigned iiq_idx = 0; iiq_idx < IIQ_SIZE; iiq_idx++) begin
          freelist[bank_idx][iiq_idx] <= IIQ_IDX_WIDTH'(iiq_idx);
        end
      end
      freelist_rp <= '{default: 0};
      freelist_wp <= '{default: 0};
      // noei_freelist <= '{default: (IIQ_IDX_WIDTH + 1)'(IIQ_SIZE)};
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        noei_freelist[bank_idx] <= (IIQ_IDX_WIDTH + 1)'(IIQ_SIZE);
      end

      // iiq_issue
      iiq_issue_valid <= '{default: 0};
      iiq_issue_rp <= '{default: 0};
      iiq_issue_bank_idx <= 0;


    end else begin


      // lwt
      update_lwt  <= update_lwt_next;
      lwt_counter <= lwt_counter + 1;
      if (lwt_counter == 0) begin
        lwt <= '{default: 0};
      end else begin
        if (update_lwt) begin
          lwt[pt_r_data[0][LWT_IDX_MSB:LWT_IDX_LSB]] <= 1;
        end
      end

      // bt
      bt <= bt_next;

      // iiq_metaの更新
      iiq_meta <= iiq_meta_next;

      // op_iiq_meta
      op_iiq_meta <= op_iiq_meta_next;

      // freelist
      // freelistから取り出した分の処理.
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        if (freelist_used[bank_idx]) begin
          freelist_rp[bank_idx] <= freelist_rp[bank_idx] + IIQ_IDX_WIDTH'(1);
        end
      end
      // freelistに戻した分の処理. 
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        if (freelist_freed[bank_idx].valid) begin
          freelist[bank_idx][freelist_wp[bank_idx]] <= freelist_freed[bank_idx].iiq_idx;
          freelist_wp[bank_idx] <= freelist_wp[bank_idx] + IIQ_IDX_WIDTH'(1);
        end
      end
      // freelistのエントリ数の計算
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
        noei_freelist[bank_idx] <= noei_freelist[bank_idx] - (IIQ_IDX_WIDTH+1)'(freelist_used[bank_idx]) + (IIQ_IDX_WIDTH+1)'(freelist_freed[bank_idx].valid);
      end


      // iiq_issue
      iiq_issue_valid <= iiq_issue_valid_next;
      iiq_issue_rp <= iiq_issue_rp_next;
      iiq_issue_bank_idx <= iiq_issue_bank_idx + 1;

    end
  end




  // FORDEBG

  task automatic dump_uop(input string tag, input int unsigned lane, input vuop_front_t u);
    // opcode_t の文字列化が無いなら hex で出す（必要なら関数を追加）
    $display(
        "[%0t] %s[%0d] pc=%h opcode=%h rs1e=%0d rs2e=%0d rde=%0d rs1=%0d rs2=%0d rd=%0d imm=%h al=%0d",
        $time, tag, lane, u.op_addr, u.opcode, u.rs1_exist, u.rs2_exist, u.rd_exist, u.rs1, u.rs2,
        u.rd, u.imm, u.al_idx);
  endtask

  task automatic dump_iiq_meta_entry(input int unsigned bank_idx, input int unsigned iiq_idx,
                                     input iiq_meta_t m);
    $display(
        "[%0t]  meta b=%0d i=%0d v=%0d type=%s rs1e=%0d rs1=%0d rs2e=%0d rs2=%0d al=%0d lwt=%0d",
        $time, bank_idx, iiq_idx, m.valid, m.op_type.name(), m.rs1_exist, m.rs1, m.rs2_exist,
        m.rs2, m.al_idx, m.lwt_idx);
  endtask

  task automatic dump_vuop_front(input vuop_front_t op);
    $display(
        "[LOG] v=%0d pc=%h opcode=%h rs1e=%0d rs2e=%0d rde=%0d rs1=%0d rs2=%0d rd=%0d imm=%h al=%0d",
        op.valid, op.op_addr, op.opcode, op.rs1_exist, op.rs2_exist, op.rd_exist, op.rs1, op.rs2,
        op.rd, op.imm, op.al_idx);
  endtask




endmodule
