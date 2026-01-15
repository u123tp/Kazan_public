// 整数レジスタのissue queue
// 

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"

module IntIssueQueue
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
#(
    parameter int unsigned NUM_OF_OP_IN = NUM_OF_FETCH
) (
    input logic clock,
    input logic reset,

    input vuop_front_t op_in[NUM_OF_OP_IN],

    // 算術命令のop_out
    output vuop_front_t op_out_ari[NUM_OF_ARI_ISSUE],
    output vuop_front_t op_out_ld[NUM_OF_LD_ISSUE],
    output vuop_front_t op_out_st_amo[NUM_OF_ST_AMO_ISSUE],
    output vuop_front_t op_out_csr[NUM_OF_CSR_ISSUE],

    // 結果のフィードバック. rs1,rs2のreadyを更新する
    input feedback_rd_t feedback[NUM_OF_RESULT_FEEDBACKS],

    // rawハザード発見時にlusから来るフィードバック.
    // ld wait tableの更新用.
    input logic ld_speculative_feedback_valid,
    input logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx,

    // 制御信号
    input logic flush_in,

    // 次の命令を受ける空きが無い(=満タン)か.
    output logic stall_out,
    input  logic stall_in_from_ldst,
    input  logic stall_in_from_csr
);

  // ----------------------------------------------------------------------
  // パラメータ
  // ----------------------------------------------------------------------

  localparam int unsigned IIQ_SIZE = 64;
  localparam int unsigned IIQ_IDX_WIDTH = $clog2(IIQ_SIZE);

  localparam int unsigned NUM_OF_LWT_SETS = 512;
  localparam int unsigned LWT_SET_IDX_WIDTH = $clog2(NUM_OF_LWT_SETS);

  // ---------------------------------------------------------------------
  // 出力
  // ---------------------------------------------------------------------

  vuop_front_t op_out_ari_next[NUM_OF_ARI_ISSUE];
  vuop_front_t op_out_ld_next[NUM_OF_LD_ISSUE];
  vuop_front_t op_out_st_amo_next[NUM_OF_ST_AMO_ISSUE];
  vuop_front_t op_out_csr_next[NUM_OF_CSR_ISSUE];


  // Integer Issue Queue
  typedef struct packed {
    logic valid;
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] op_addr;
    logic rs1_exist;
    logic rs2_exist;
    logic rd_exist;
    logic rs1_ready;
    logic rs2_ready;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] imm;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
  } iiq_t;

  iiq_t iiq[IIQ_SIZE];
  iiq_t iiq_next[IIQ_SIZE];

  int unsigned num_of_iiq_entries;
  int unsigned num_of_iiq_entries_next;

  // busy table
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
  logic lwt_next[NUM_OF_LWT_SETS];

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
  logic [VADDR_WIDTH/8-1:0] pt_w_mask[NUM_OF_FETCH];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      pt_w_mask[i] = {(VADDR_WIDTH / 8) {1'b1}};
    end
  end

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
      .w_data(pt_w_data),
      .w_mask(pt_w_mask)
  );



  always_comb begin

    iiq_next = iiq;
    bt_next = bt;
    num_of_iiq_entries_next = num_of_iiq_entries;

    // lwt
    lwt_next = lwt;
    lwt_counter_next = lwt_counter;



    // op_in => iiq_next, bt_next
    // 新しく入ってきた命令をiiqに入れる.
    for (int unsigned i = 0; i < NUM_OF_OP_IN; i++) begin
      if (op_in[i].valid) begin
        iiq_next[num_of_iiq_entries_next] = '{
            valid: 1,
            opcode: op_in[i].opcode,
            op_addr: op_in[i].op_addr,
            rs1_exist: op_in[i].rs1_exist,
            rs2_exist: op_in[i].rs2_exist,
            rd_exist: op_in[i].rd_exist,
            rs1_ready: ~bt_next[op_in[i].rs1],  // busyで無いなら使用可
            rs2_ready: ~bt_next[op_in[i].rs2],
            rs1: op_in[i].rs1,
            rs2: op_in[i].rs2,
            rd: op_in[i].rd,
            imm: op_in[i].imm,
            al_idx: op_in[i].al_idx
        };
        // 処理中であるとbusy tableに登録する
        if (op_in[i].rd_exist) begin
          bt_next[op_in[i].rd] = 1;
        end
        num_of_iiq_entries_next++;
      end
    end

    // feedback => iiq_next
    for (int unsigned fb_idx = 0; fb_idx < NUM_OF_RESULT_FEEDBACKS; fb_idx++) begin
      for (int unsigned iiq_idx = 0; iiq_idx < IIQ_SIZE; iiq_idx++) begin
        if (iiq_next[iiq_idx].valid && feedback[fb_idx].valid) begin
          if (iiq_next[iiq_idx].rs1_exist && iiq_next[iiq_idx].rs1 == feedback[fb_idx].rd) begin
            iiq_next[iiq_idx].rs1_ready = 1;
          end
          if (iiq_next[iiq_idx].rs2_exist && iiq_next[iiq_idx].rs2 == feedback[fb_idx].rd) begin
            iiq_next[iiq_idx].rs2_ready = 1;
          end
        end
      end
    end

    // feedback => bt_next
    for (int unsigned fb_idx = 0; fb_idx < NUM_OF_RESULT_FEEDBACKS; fb_idx++) begin
      if (feedback[fb_idx].valid) begin
        bt_next[feedback[fb_idx].rd] = 0;
      end
    end



    // ---------------------------------------------------------------------
    // iiq_next => op_out_ari_next, op_out_ld_next, op_out_st_amo_next, op_out_csr_next
    // ----------------------------------------------------------------------
    begin
      int unsigned op_out_ari_next_counter = 0;
      int unsigned op_out_ld_next_counter = 0;
      int unsigned op_out_st_amo_next_counter = 0;
      int unsigned op_out_csr_next_counter = 0;


      op_out_ari_next = '{default: 0};
      op_out_ld_next = '{default: 0};
      op_out_st_amo_next = '{default: 0};
      op_out_csr_next = '{default: 0};


      for (int unsigned i = 0; i < IIQ_SIZE; i++) begin
        if (iiq_next[i].valid  && (~iiq_next[i].rs1_exist || iiq_next[i].rs1_ready) &&
                (~iiq_next[i].rs2_exist || iiq_next[i].rs2_ready)) begin

          if (is_arithmetic_opcode(
                  iiq_next[i].opcode
              ) && op_out_ari_next_counter < NUM_OF_ARI_ISSUE) begin
            // 算術命令の発行.
            op_out_ari_next[op_out_ari_next_counter] = '{
                valid: 1,
                opcode: iiq_next[i].opcode,
                op_addr: iiq_next[i].op_addr,
                rs1_exist: iiq_next[i].rs1_exist,
                rs2_exist: iiq_next[i].rs2_exist,
                rd_exist: iiq_next[i].rd_exist,
                rs1: iiq_next[i].rs1,
                rs2: iiq_next[i].rs2,
                rd: iiq_next[i].rd,
                imm: iiq_next[i].imm,
                al_idx: iiq_next[i].al_idx
            };
            op_out_ari_next_counter++;
            num_of_iiq_entries_next--;
            iiq_next[i].valid = 0;

          end else if (is_ld_opcode(
                  iiq_next[i].opcode
              ) && op_out_ld_next_counter < NUM_OF_LD_ISSUE && !stall_in_from_ldst &&
                  (!lwt_next[iiq_next[i].op_addr[LWT_SET_IDX_WIDTH-1:0]] || i == 0)) begin
            // ld命令の発行.
            // lwtが立っている場合は,バッファの先頭でのみ発行を許可.
            op_out_ld_next[op_out_ld_next_counter] = '{
                valid: 1,
                opcode: iiq_next[i].opcode,
                op_addr: iiq_next[i].op_addr,
                rs1_exist: iiq_next[i].rs1_exist,
                rs2_exist: iiq_next[i].rs2_exist,
                rd_exist: iiq_next[i].rd_exist,
                rs1: iiq_next[i].rs1,
                rs2: iiq_next[i].rs2,
                rd: iiq_next[i].rd,
                imm: iiq_next[i].imm,
                al_idx: iiq_next[i].al_idx
            };
            op_out_ld_next_counter++;
            num_of_iiq_entries_next--;
            iiq_next[i].valid = 0;

          end else if ((is_st_opcode(
                  iiq_next[i].opcode
              ) || is_amo_opcode(
                  iiq_next[i].opcode
              )) && op_out_st_amo_next_counter < NUM_OF_ST_AMO_ISSUE && !stall_in_from_ldst) begin
            // st,amo命令の発行.
            op_out_st_amo_next[op_out_st_amo_next_counter] = '{
                valid: 1,
                opcode: iiq_next[i].opcode,
                op_addr: iiq_next[i].op_addr,
                rs1_exist: iiq_next[i].rs1_exist,
                rs2_exist: iiq_next[i].rs2_exist,
                rd_exist: iiq_next[i].rd_exist,
                rs1: iiq_next[i].rs1,
                rs2: iiq_next[i].rs2,
                rd: iiq_next[i].rd,
                imm: iiq_next[i].imm,
                al_idx: iiq_next[i].al_idx
            };
            op_out_st_amo_next_counter++;
            num_of_iiq_entries_next--;
            iiq_next[i].valid = 0;

          end else if (is_csr_opcode(
                  iiq_next[i].opcode
              ) && i == 0 && op_out_csr_next_counter < NUM_OF_CSR_ISSUE && !stall_in_from_csr) begin
            // csr命令の発行.
            op_out_csr_next[op_out_csr_next_counter] = '{
                valid: 1,
                opcode: iiq_next[i].opcode,
                op_addr: iiq_next[i].op_addr,
                rs1_exist: iiq_next[i].rs1_exist,
                rs2_exist: iiq_next[i].rs2_exist,
                rd_exist: iiq_next[i].rd_exist,
                rs1: iiq_next[i].rs1,
                rs2: iiq_next[i].rs2,
                rd: iiq_next[i].rd,
                imm: iiq_next[i].imm,
                al_idx: iiq_next[i].al_idx
            };
            op_out_csr_next_counter++;
            num_of_iiq_entries_next--;
            iiq_next[i].valid = 0;
          end

        end
      end

    end

    // iiq_next => iiq_next
    // iiq_nextを詰める.
    begin
      iiq_t iiq_tmp[IIQ_SIZE] = '{default: 0};
      int unsigned invalid_counter = 0;
      for (int unsigned i = 0; i < IIQ_SIZE; i++) begin
        if (iiq_next[i].valid) begin
          iiq_tmp[i-invalid_counter] = iiq_next[i];
        end else begin
          invalid_counter++;
        end
      end
      iiq_next = iiq_tmp;
    end

    // pc_tableの更新
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

    // update lwt_nextの更新.
    if (update_lwt) begin
      lwt_next[pt_r_data[0][LWT_SET_IDX_WIDTH-1:0]] = 1;
    end

    // 一定回数でリセット.
    lwt_counter_next++;
    if (lwt_counter_next == 0) begin
      lwt_next = '{default: 0};
    end


    // stall_out
    stall_out = IIQ_SIZE - num_of_iiq_entries_next < NUM_OF_OP_IN;

  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      iiq <= '{default: 0};
      bt <= '{default: 0};
      num_of_iiq_entries <= 0;
      lwt <= '{default: 0};
      update_lwt <= update_lwt_next;
      lwt_counter <= 0;

      // 出力
      op_out_ari <= '{default: 0};
      op_out_ld <= '{default: 0};
      op_out_st_amo <= '{default: 0};
      op_out_csr <= '{default: 0};
    end else if (flush_in) begin

      iiq <= '{default: 0};
      bt <= '{default: 0};
      num_of_iiq_entries <= 0;
      // lwtはflushのたびに消してはならない.
      update_lwt <= update_lwt_next;
      lwt_counter <= lwt_counter_next;

      // 出力
      op_out_ari <= '{default: 0};
      op_out_ld <= '{default: 0};
      op_out_st_amo <= '{default: 0};
      op_out_csr <= '{default: 0};
    end else begin

      iiq <= iiq_next;
      bt <= bt_next;
      num_of_iiq_entries <= num_of_iiq_entries_next;
      lwt <= lwt_next;
      update_lwt <= update_lwt_next;
      lwt_counter <= lwt_counter_next;

      // 出力
      op_out_ari <= op_out_ari_next;
      op_out_ld <= op_out_ld_next;
      op_out_st_amo <= op_out_st_amo_next;
      op_out_csr <= op_out_csr_next;
    end
  end



  // for debug
  iiq_t iiq_next0;
  iiq_t iiq_next1;
  iiq_t iiq_next2;
  iiq_t iiq_next3;
  iiq_t iiq_next4;
  iiq_t iiq_next5;
  iiq_t iiq_next6;
  iiq_t iiq_next7;
  iiq_t iiq_next8;
  iiq_t iiq_next9;
  iiq_t iiq_next10;
  iiq_t iiq_next11;
  iiq_t iiq_next12;
  iiq_t iiq_next13;
  iiq_t iiq_next14;
  iiq_t iiq_next15;
  iiq_t iiq_next16;
  iiq_t iiq_next17;
  iiq_t iiq_next18;
  iiq_t iiq_next19;
  iiq_t iiq_next20;
  iiq_t iiq_next21;
  iiq_t iiq_next22;
  iiq_t iiq_next23;
  iiq_t iiq_next24;
  iiq_t iiq_next25;
  iiq_t iiq_next26;
  iiq_t iiq_next27;
  iiq_t iiq_next28;
  iiq_t iiq_next29;
  iiq_t iiq_next30;
  iiq_t iiq_next31;
  iiq_t iiq_next32;
  iiq_t iiq_next33;
  iiq_t iiq_next34;
  iiq_t iiq_next35;
  iiq_t iiq_next36;
  iiq_t iiq_next37;
  iiq_t iiq_next38;
  iiq_t iiq_next39;
  iiq_t iiq_next40;
  iiq_t iiq_next41;
  iiq_t iiq_next42;
  iiq_t iiq_next43;
  iiq_t iiq_next44;
  iiq_t iiq_next45;
  iiq_t iiq_next46;
  iiq_t iiq_next47;
  iiq_t iiq_next48;
  iiq_t iiq_next49;
  iiq_t iiq_next50;
  iiq_t iiq_next51;
  iiq_t iiq_next52;
  iiq_t iiq_next53;
  iiq_t iiq_next54;
  iiq_t iiq_next55;
  iiq_t iiq_next56;
  iiq_t iiq_next57;
  iiq_t iiq_next58;
  iiq_t iiq_next59;
  iiq_t iiq_next60;
  iiq_t iiq_next61;
  iiq_t iiq_next62;
  iiq_t iiq_next63;

  always_comb begin
    iiq_next0  = iiq_next[0];
    iiq_next1  = iiq_next[1];
    iiq_next2  = iiq_next[2];
    iiq_next3  = iiq_next[3];
    iiq_next4  = iiq_next[4];
    iiq_next5  = iiq_next[5];
    iiq_next6  = iiq_next[6];
    iiq_next7  = iiq_next[7];
    iiq_next8  = iiq_next[8];
    iiq_next9  = iiq_next[9];
    iiq_next10 = iiq_next[10];
    iiq_next11 = iiq_next[11];
    iiq_next12 = iiq_next[12];
    iiq_next13 = iiq_next[13];
    iiq_next14 = iiq_next[14];
    iiq_next15 = iiq_next[15];
    iiq_next16 = iiq_next[16];
    iiq_next17 = iiq_next[17];
    iiq_next18 = iiq_next[18];
    iiq_next19 = iiq_next[19];
    iiq_next20 = iiq_next[20];
    iiq_next21 = iiq_next[21];
    iiq_next22 = iiq_next[22];
    iiq_next23 = iiq_next[23];
    iiq_next24 = iiq_next[24];
    iiq_next25 = iiq_next[25];
    iiq_next26 = iiq_next[26];
    iiq_next27 = iiq_next[27];
    iiq_next28 = iiq_next[28];
    iiq_next29 = iiq_next[29];
    iiq_next30 = iiq_next[30];
    iiq_next31 = iiq_next[31];
    iiq_next32 = iiq_next[32];
    iiq_next33 = iiq_next[33];
    iiq_next34 = iiq_next[34];
    iiq_next35 = iiq_next[35];
    iiq_next36 = iiq_next[36];
    iiq_next37 = iiq_next[37];
    iiq_next38 = iiq_next[38];
    iiq_next39 = iiq_next[39];
    iiq_next40 = iiq_next[40];
    iiq_next41 = iiq_next[41];
    iiq_next42 = iiq_next[42];
    iiq_next43 = iiq_next[43];
    iiq_next44 = iiq_next[44];
    iiq_next45 = iiq_next[45];
    iiq_next46 = iiq_next[46];
    iiq_next47 = iiq_next[47];
    iiq_next48 = iiq_next[48];
    iiq_next49 = iiq_next[49];
    iiq_next50 = iiq_next[50];
    iiq_next51 = iiq_next[51];
    iiq_next52 = iiq_next[52];
    iiq_next53 = iiq_next[53];
    iiq_next54 = iiq_next[54];
    iiq_next55 = iiq_next[55];
    iiq_next56 = iiq_next[56];
    iiq_next57 = iiq_next[57];
    iiq_next58 = iiq_next[58];
    iiq_next59 = iiq_next[59];
    iiq_next60 = iiq_next[60];
    iiq_next61 = iiq_next[61];
    iiq_next62 = iiq_next[62];
    iiq_next63 = iiq_next[63];
  end

  logic bt_next0;
  logic bt_next1;
  logic bt_next2;
  logic bt_next3;
  logic bt_next4;
  logic bt_next5;
  logic bt_next6;
  logic bt_next7;
  logic bt_next8;
  logic bt_next9;
  logic bt_next10;
  logic bt_next11;
  logic bt_next12;
  logic bt_next13;
  logic bt_next14;
  logic bt_next15;
  logic bt_next16;
  logic bt_next17;
  logic bt_next18;
  logic bt_next19;
  logic bt_next20;
  logic bt_next21;
  logic bt_next22;
  logic bt_next23;
  logic bt_next24;
  logic bt_next25;
  logic bt_next26;
  logic bt_next27;
  logic bt_next28;
  logic bt_next29;
  logic bt_next30;
  logic bt_next31;

  always_comb begin
    bt_next0  = bt_next[0];
    bt_next1  = bt_next[1];
    bt_next2  = bt_next[2];
    bt_next3  = bt_next[3];
    bt_next4  = bt_next[4];
    bt_next5  = bt_next[5];
    bt_next6  = bt_next[6];
    bt_next7  = bt_next[7];
    bt_next8  = bt_next[8];
    bt_next9  = bt_next[9];
    bt_next10 = bt_next[10];
    bt_next11 = bt_next[11];
    bt_next12 = bt_next[12];
    bt_next13 = bt_next[13];
    bt_next14 = bt_next[14];
    bt_next15 = bt_next[15];
    bt_next16 = bt_next[16];
    bt_next17 = bt_next[17];
    bt_next18 = bt_next[18];
    bt_next19 = bt_next[19];
    bt_next20 = bt_next[20];
    bt_next21 = bt_next[21];
    bt_next22 = bt_next[22];
    bt_next23 = bt_next[23];
    bt_next24 = bt_next[24];
    bt_next25 = bt_next[25];
    bt_next26 = bt_next[26];
    bt_next27 = bt_next[27];
    bt_next28 = bt_next[28];
    bt_next29 = bt_next[29];
    bt_next30 = bt_next[30];
    bt_next31 = bt_next[31];
  end


endmodule
