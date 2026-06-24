`timescale 1ns / 1ps
// ストア命令は仮発行のときにシグナルをrenamerに送るので,実行おわっても特に何も返さなくていい
// TODO:割り込み処理

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CSR_PROPS.svh"
`include "Renamer_PROPS.svh"

module Renamer
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CSR_PROPS::*;
  import Renamer_PROPS::*;
(


    input logic clock,
    input logic reset,

    input decoded_op_t op_in_cur[NUM_OF_FETCH],
    output vuop_front_t op_out[NUM_OF_FETCH],

    // 実行が終わった命令.アクティブリストのエントリをdoneに更新するためのフィードバック.
    input vuop_result_t feedback_op[NUM_OF_RESULT_FEEDBACKS],

    // renamer => btb
    // ジャンプやbranchする場合,その結果はbtbに書き込まれる.
    // ただ,別にbtbが予想した通りのアドレスに飛んだときは更新する必要も無いので,mispredictionの時だけ更新すればいいので配列である必要は無い.
    output misprediction_feedback_to_btb_t misprediction_feedback_to_btb,

    // 分岐やジャンプ命令が毎回あたっていたかをフィードバックする.
    output is_taken_feedback_to_pred_t is_taken_feedback_to_pred[NUM_OF_GRADUATE],

    // mispredictionや例外で他のユニットの内容を流す時.
    output addr_with_valid_t flush_from_renamer,

    // lsuとの接続.
    Renamer_LSU_if.renamer lsu_port,

    // csruとの接続
    csru_renamer_if.renamer csru_port,

    // dcacheが満タンなら,stのコミットを抑制
    input logic dcache_noroom,

    // tlbの全エントリ無効化(sfence.vma用)
    output logic flush_tlb,

    //  特権モードの読み書き
    input privilege_level_e priv_rval,
    output priv_w_t priv_w,

    // csrレジスタとの接続
    csr_renamer_if.renamer csr_port,

    // int issue queueでlwtの制御用. 
    output logic [AL_IDX_WIDTH-1:0] al_rp_out,

    output logic stall_out,

    input logic stall_in,

    // 実機ではuartの周波数はcpuのサイクルより小さいので,tx用のfifoが満タンになる可能性がある.
    // よって,fifoが満タンなら,renamerでst命令のコミットを抑制する必要がある.
    input logic tx_fifo_full,

`ifdef VIVADO_COMPILE
    output logic led1,
    // コミットが一つでも成功したら.
    output logic led2,
`endif


    // cacheとやり取りするときに,alをidxとして使ってることが多いので,
    // flushした後に,flush前にcacheにだしたreqに対する返答を受け取っても廃棄できるようにするため.
    output int unsigned generation,

    // fence_iでcacheの内容をinvalidateする.
    output logic invalidate_l1cache,
    input  logic invalidate_l1cache_done



);

  // このモジュールをflushする.
  logic flush_al;

  // vaddrをXLEN幅に展開する.
  function automatic logic [XLEN-1:0] vaddr_to_xlen(input logic [VADDR_WIDTH-1:0] addr);
    vaddr_to_xlen = {{(XLEN - VADDR_WIDTH) {addr[VADDR_WIDTH-1]}}, addr};
  endfunction


  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  decoded_op_t op_in[NUM_OF_FETCH];

  decoded_op_t op_in_pending[NUM_OF_FETCH];
  logic is_pending;
  decoded_op_t op_in_pending_next[NUM_OF_FETCH];
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    op_in_pending_next = op_in_pending;


    if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      op_in_pending_next = op_in_cur;
      is_pending_next = 1;
      op_in = '{default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      op_in = '{default: 0};
    end else if (is_pending) begin
      // stall終了時.
      op_in = op_in_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      op_in = op_in_cur;
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      op_in_pending <= '{default: 0};
      is_pending <= 0;
    end else if (flush_al) begin
      op_in_pending <= '{default: 0};
      is_pending <= 0;
    end else begin
      op_in_pending <= op_in_pending_next;
      is_pending <= is_pending_next;
    end
  end





  // ------------------------------------------------------------------------------------------------------
  // パラメータ
  // ------------------------------------------------------------------------------------------------------
  localparam int unsigned NUM_OF_AL_BANK = NUM_OF_FETCH;
  localparam int unsigned AL_BANK_IDX_WIDTH = $clog2(NUM_OF_AL_BANK);
  localparam int unsigned AL_BANK_SIZE = ACTIVELIST_SIZE / NUM_OF_AL_BANK;
  localparam int unsigned AL_INBANK_IDX_WIDTH = $clog2(AL_BANK_SIZE);

  localparam int unsigned AL_BANK_IDX_LSB = 0;
  localparam int unsigned AL_BANK_IDX_MSB = AL_BANK_IDX_WIDTH - 1;
  localparam int unsigned AL_INBANK_IDX_LSB = AL_BANK_IDX_MSB + 1;
  localparam int unsigned AL_INBANK_IDX_MSB = AL_INBANK_IDX_LSB + AL_INBANK_IDX_WIDTH - 1;



  // 出力
  vuop_front_t op_out_next[NUM_OF_FETCH];


  // --------------------------------------------------------------------------------------------------------------
  // RAT
  // --------------------------------------------------------------------------------------------------------------
  // RAT[論理レジスタ番号] = 物理レジスタ番号
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat_next[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat_init[NUM_OF_LOGREGS];
  // RRAT(Retirement RAT)
  // 卒業したところまでのRAT.投機実行のミス時にRRATをRATにコピーする
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rrat[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rrat_next[NUM_OF_LOGREGS];


  // -------------------------------------------------------------------------------------------------------
  // Active List 
  // -------------------------------------------------------------------------------------------------------
  // op_inから得られて,active listに保存しておく部分

  // 読み書きがsequentialなNUM_OF_FETCH個のポートで行けるので
  logic al_meta_r_en[NUM_OF_AL_BANK];
  logic [AL_INBANK_IDX_WIDTH-1:0] al_meta_r_idx[NUM_OF_AL_BANK];
  logic [$bits(al_meta_t)-1:0] al_meta_r_data_bit[NUM_OF_AL_BANK];

  logic al_meta_w_en[NUM_OF_AL_BANK];
  logic [AL_INBANK_IDX_WIDTH-1:0] al_meta_w_idx[NUM_OF_AL_BANK];
  logic [$bits(al_meta_t)-1:0] al_meta_w_data_bit[NUM_OF_AL_BANK];

  al_meta_t al_meta_r_data_strc[NUM_OF_AL_BANK];
  al_meta_t al_meta_w_data_strc[NUM_OF_AL_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_AL_BANK; i++) begin
      al_meta_r_data_strc[i] = al_meta_r_data_bit[i];
      al_meta_w_data_bit[i]  = al_meta_w_data_strc[i];
    end
  end

  generate
    for (genvar al_bank_idx = 0; al_bank_idx < NUM_OF_AL_BANK; al_bank_idx++) begin : gen_al_meta
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(al_meta_t)),
          .RAM_DEPTH(AL_BANK_SIZE)
      ) al_meta (
          .clock(clock),
          .r_en(al_meta_r_en[al_bank_idx]),
          .r_ram_idx(al_meta_r_idx[al_bank_idx]),
          .r_data(al_meta_r_data_bit[al_bank_idx]),
          .w_en(al_meta_w_en[al_bank_idx]),
          .w_ram_idx(al_meta_w_idx[al_bank_idx]),
          .w_data(al_meta_w_data_bit[al_bank_idx])
      );
    end
  endgenerate



  // // こっちは書き込みのポートがfeedbackの数だけ必要.
  // // readはsequentialにNUM_OF_GRADUATE個

  logic al_result_r_en[NUM_OF_GRADUATE];
  logic [AL_IDX_WIDTH-1:0] al_result_r_idx[NUM_OF_GRADUATE];
  logic [$bits(al_result_t)-1:0] al_result_r_data_bit[NUM_OF_GRADUATE];

  logic al_result_w_en[NUM_OF_RESULT_FEEDBACKS];
  logic [AL_IDX_WIDTH-1:0] al_result_w_idx[NUM_OF_RESULT_FEEDBACKS];
  logic [$bits(al_result_t)-1:0] al_result_w_data_bit[NUM_OF_RESULT_FEEDBACKS];


  al_result_t al_result_r_data_strc[NUM_OF_GRADUATE];
  al_result_t al_result_w_data_strc[NUM_OF_RESULT_FEEDBACKS];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      al_result_r_data_strc[i] = al_result_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
      al_result_w_data_bit[i] = al_result_w_data_strc[i];
    end
  end

  LVTRAM #(
      .RAM_WIDTH($bits(al_result_t)),
      .RAM_DEPTH(ACTIVELIST_SIZE),
      .NUM_OF_READ_PORT(NUM_OF_GRADUATE),
      .NUM_OF_WRITE_PORT(NUM_OF_RESULT_FEEDBACKS)
  ) al_result (
      .clock(clock),
      .reset(reset),
      .r_en(al_result_r_en),
      .r_ram_idx(al_result_r_idx),
      .r_data(al_result_r_data_bit),
      .w_en(al_result_w_en),
      .w_ram_idx(al_result_w_idx),
      .w_data(al_result_w_data_bit)
  );


  // done, amo_ld_done, fencei_sig_made, raw_hazardに関しては,al_metaの更新タイミング(opが入ってきたとき)や
  // al_resultの更新タイミング(feedbackが入ってきたとき)と異なるため,レジスタで保存する. 
  logic al_done[NUM_OF_AL_BANK][AL_BANK_SIZE];
  typedef struct packed {
    logic valid;
    logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx;
    logic [AL_INBANK_IDX_WIDTH-1:0] al_inbank_idx;
  } al_done_update_t;
  // op_inでdoneにするもの
  // al_done_update_t al_done_new_from_op_in[NUM_OF_FETCH];
  // feedback_opからdoneにするもの
  al_done_update_t al_done_new_from_op_feedback[NUM_OF_RESULT_FEEDBACKS];
  // alの先頭がfence_iであるならdoneにアップデートする
  al_done_update_t al_done_new_from_fence_i;

  // 削除
  al_done_update_t al_done_del[NUM_OF_GRADUATE];


  // 
  logic al_amo_ld_done[NUM_OF_AL_BANK][AL_BANK_SIZE];
  typedef struct packed {
    logic valid;
    logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx;
    logic [AL_INBANK_IDX_WIDTH-1:0] al_inbank_idx;
  } al_amo_ld_done_update_t;
  al_amo_ld_done_update_t al_amo_ld_done_new[NUM_OF_RESULT_FEEDBACKS];
  al_amo_ld_done_update_t al_amo_ld_done_del[NUM_OF_GRADUATE];


  // fence_i命令である場合に,cacheをinvalidateするsigを出したかどうか.
  logic al_fencei_sig_made[NUM_OF_AL_BANK][AL_BANK_SIZE];
  typedef struct packed {
    logic valid;
    logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx;
    logic [AL_INBANK_IDX_WIDTH-1:0] al_inbank_idx;
  } al_fencei_sig_made_update_t;
  al_fencei_sig_made_update_t al_fencei_sig_made_new;
  al_fencei_sig_made_update_t al_fencei_sig_made_del[NUM_OF_GRADUATE];

  logic al_raw_hazard[NUM_OF_AL_BANK][AL_BANK_SIZE];
  typedef struct packed {
    logic valid;
    logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx;
    logic [AL_INBANK_IDX_WIDTH-1:0] al_inbank_idx;
  } al_raw_hazard_update_t;
  al_raw_hazard_update_t al_raw_hazard_new;
  al_raw_hazard_update_t al_raw_hazard_del[NUM_OF_GRADUATE];



  // doneかどうかを非同期的に読み出す必要があるので、headsで予め戦闘のものを読み出しておく.
  al_meta_t al_meta_heads[NUM_OF_GRADUATE];
  al_result_t al_result_heads[NUM_OF_GRADUATE];


  logic [VADDR_WIDTH-1:0] al_head_vaddr_debug;
  logic [31:0] al_head_raw_op_debug;
  // (*mark_debug="true"*) committed_ldst_from_al_t committed_instr_debug[NUM_OF_GRADUATE];
  // (*mark_debug="true"*) executable_csr_t executable_csr_debug;
  always_ff @(posedge clock) begin
    if (reset) begin
      al_head_vaddr_debug  <= 0;
      al_head_raw_op_debug <= '0;
      // committed_instr_debug <= '{default: 0};
      // executable_csr_debug  <= 0;
    end else begin
      al_head_vaddr_debug  <= al_meta_heads[0].op_vaddr;
      al_head_raw_op_debug <= al_meta_heads[0].raw_op;
      // committed_instr_debug <= csru_port.committed_instr;
      // executable_csr_debug  <= csru_port.executable_csr;
    end
  end



  // rp,wp
  logic [AL_IDX_WIDTH-1:0] al_rp;
  logic [AL_IDX_WIDTH-1:0] al_wp;
  logic [AL_IDX_WIDTH:0] noei_al;
  logic [AL_IDX_WIDTH-1:0] al_rp_next;
  logic [AL_IDX_WIDTH-1:0] al_wp_next;
  logic [AL_IDX_WIDTH:0] noei_al_next;

  int unsigned num_of_used_al;
  int unsigned num_of_new_al;


  assign lsu_port.al_rp = al_rp;
  assign lsu_port.al_wp = al_wp;

  assign al_rp_out = al_rp;


  // ----------------------------------------------
  // lrsc_lock
  // ----------------------------------------------
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_lr_w;
  } lrsc_lock_t;
  // コミットされた部分までのlrscのロック.
  lrsc_lock_t lrsc_lock;
  lrsc_lock_t lrsc_lock_next;

  // -----------------------------------------
  // FreeList
  // -----------------------------------------
  // Renamerに渡す使用可能な物理レジスタ.
  logic [$clog2(NUM_OF_PHYREGS)-1:0] available_prd[NUM_OF_FETCH];

  // available_prdの内,使用したものがrenamerから伝達される.
  logic prd_used[NUM_OF_FETCH];

  // コミットした命令の論理レジスタに対応するprevious physical registerとphysical register.
  logic committed_rd_valid[NUM_OF_GRADUATE];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_phyreg[NUM_OF_GRADUATE];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_prev_phyreg[NUM_OF_GRADUATE];

  // mispredictionや例外発生時
  logic flush_fl;


  // invalidate
  logic invalidate_l1cache_next;

  FreeList freelist (
      .clock(clock),
      .reset(reset),
      .available_prd(available_prd),
      .prd_used(prd_used),
      .committed_rd_valid(committed_rd_valid),
      .committed_phyreg(committed_phyreg),
      .committed_prev_phyreg(committed_prev_phyreg),
      .flush_in(flush_fl)
  );



  // ----------------------------------------------------------------------------
  // debug log
  // ----------------------------------------------------------------------------
`ifdef VERILATOR_COMPILE
  int fp_commitlog;
  int fp_mainlog;
  int fp_addrlog;
  initial begin
`ifdef COMMITLOG_EN
    fp_commitlog = $fopen("./log/commitlog.txt", "w");
    fp_addrlog   = $fopen("./log/addrlog.txt", "w");
`endif
`ifdef MAINLOG_EN
    fp_mainlog = $fopen("./log/mainlog.txt", "w");
`endif
  end
  typedef struct packed {
    logic valid;
    logic [38:0] addr;
    opcode_t opcode;
    logic rs1_exist;
    logic rs2_exist;
    logic rd_exist;
    abi_name_e rs1_abi;
    abi_name_e rs2_abi;
    abi_name_e rd_abi;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rd;
    logic [XLEN-1:0] rd_val;
  } commitlog_t;
  commitlog_t commitlog[NUM_OF_GRADUATE];
  function automatic void dump_decoded_op(input decoded_op_t x);
    $display(
        "{valid:%0d, opcode:%0d, vaddr:0x%0h, paddr:0x%0h, rs1_exist:%0d, rs2_exist:%0d, rd_exist:%0d, rs1:x%0d, rs2:x%0d, rd:x%0d, imm:0x%0h, pred_taken:%0d, btb_hit:%0d, btb_addr:0x%0h, is_page_fault:%0d, is_access_fault:%0d, raw_op:0x%08h}",
        x.valid, x.opcode, x.vaddr, x.paddr, x.rs1_exist, x.rs2_exist, x.rd_exist, x.rs1, x.rs2,
        x.rd, x.imm, x.pred_taken, x.btb_hit, x.btb_addr, x.is_page_fault, x.is_access_fault,
        x.raw_op);
  endfunction
`endif


  // ----------------------------------------------------------------------------------------------------------------------
  // al_meta_heads,al_result_heads を作成
  // ----------------------------------------------------------------------------------------------------------------------
  logic al_heads_valid[NUM_OF_GRADUATE];
  logic al_heads_valid_next[NUM_OF_GRADUATE];
  logic [AL_BANK_IDX_WIDTH-1:0] al_heads_al_bank_idx[NUM_OF_GRADUATE];
  logic [AL_BANK_IDX_WIDTH-1:0] al_heads_al_bank_idx_next[NUM_OF_GRADUATE];
  logic [AL_INBANK_IDX_WIDTH-1:0] al_heads_al_inbank_idx[NUM_OF_GRADUATE];
  logic [AL_INBANK_IDX_WIDTH-1:0] al_heads_al_inbank_idx_next[NUM_OF_GRADUATE];

  always_comb begin
    // 初期化
    al_meta_r_en = '{default: 0};
    al_meta_r_idx = '{default: 0};

    al_result_r_en = '{default: 0};
    al_result_r_idx = '{default: 0};

    al_heads_valid_next = '{default: 0};
    al_heads_al_bank_idx_next = '{default: 0};
    al_heads_al_inbank_idx_next = '{default: 0};


    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      automatic logic [AL_IDX_WIDTH-1:0] al_idx = al_rp_next + AL_IDX_WIDTH'(i);
      automatic logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx = al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB];
      automatic
      logic [AL_INBANK_IDX_WIDTH-1:0]
      al_inbank_idx = al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB];
      if (i < noei_al_next) begin
        // al_meta_headsに置くデータの読み込み.
        al_meta_r_en[al_bank_idx] = 1;
        al_meta_r_idx[al_bank_idx] = al_inbank_idx;

        al_result_r_en[i] = 1;
        al_result_r_idx[i] = al_idx;

        al_heads_valid_next[i] = 1;
        al_heads_al_bank_idx_next[i] = al_bank_idx;
        al_heads_al_inbank_idx_next[i] = al_inbank_idx;
      end
    end
  end

  always_comb begin
    al_meta_heads   = '{default: 0};
    al_result_heads = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      if (al_heads_valid[i]) begin
        al_meta_heads[i] = al_meta_r_data_strc[al_heads_al_bank_idx[i]];
        // opcodeがMRET,SRET等のop_inで入ってきたときに最初からdoneにするような命令の場合,
        // al_resultは存在しないので'{default:0}にしておく.
        if(al_meta_heads[i].opcode inside {ILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMA})begin
          al_result_heads[i] = '{default: 0};
        end else begin
          al_result_heads[i] = al_result_r_data_strc[i];
        end
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      al_heads_valid <= '{default: 0};
      al_heads_al_bank_idx <= '{default: 0};
      al_heads_al_inbank_idx <= '{default: 0};
    end else begin
      al_heads_valid <= al_heads_valid_next;
      al_heads_al_bank_idx <= al_heads_al_bank_idx_next;
      al_heads_al_inbank_idx <= al_heads_al_inbank_idx_next;
    end
  end


  // ----------------------------------------------------------------------------------------------------------------------
  // op_in => new_al_ents, op_out_next
  // ----------------------------------------------------------------------------------------------------------------------
  always_comb begin

    // 新たに入ってきた命令の数
    num_of_new_al = 0;
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      lsu_port.new_instr[i] = '{default: 0, opcode: NOP};
      prd_used[i] = 0;
    end

    // new_al_ents = '{default: 0};
    // al_done_new_from_op_in = '{default: 0};

    // al_metaへの書き込み
    al_meta_w_en = '{default: 0};
    al_meta_w_idx = '{default: 0};
    al_meta_w_data_strc = '{default: 0};

    op_out_next = '{default: 0};
    rat_next = rat;

    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      automatic logic [AL_IDX_WIDTH-1:0] al_idx = 0;
      automatic logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx = 0;
      automatic logic [AL_INBANK_IDX_WIDTH-1:0] al_inbank_idx = 0;
      automatic logic [5:0] cause = 0;
      automatic logic [XLEN-1:0] tval = 0;
      automatic pmp_result_t pmp_result = '{default: 0};

      if (op_in[i].valid) begin
        al_idx = al_wp + AL_IDX_WIDTH'(num_of_new_al);
        al_bank_idx = al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB];
        al_inbank_idx = al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB];

        // op_in => lsu_port.new_instr
        if (op_in[i].opcode == FENCE) begin
          // TODO: immからsi,so,...の指定
          lsu_port.new_instr[i] = '{
              valid: 1,
              op_addr: op_in[i].vaddr,
              al_idx: al_idx,
              opcode: op_in[i].opcode,
              si: 1,
              so: 1,
              sr: 1,
              sw: 1
          };
        end else begin
          lsu_port.new_instr[i] = '{
              valid: 1,
              op_addr: op_in[i].vaddr,
              al_idx: al_idx,
              opcode: op_in[i].opcode,
              default: 0
          };
        end


        // op_in => al_meta
        // al_nextにop_inを追加する.
        // SRET,MRETは特に処理が無いのでdone==1でいい
        // fenceも前に発行されたst/ldが卒業済なら自動的に役目を終えてるのでdone=1
        al_meta_w_en[al_bank_idx] = 1;
        al_meta_w_idx[al_bank_idx] = al_inbank_idx;
        al_meta_w_data_strc[al_bank_idx] = '{
            op_vaddr: op_in[i].vaddr,
            opcode: op_in[i].opcode,
            has_rd: op_in[i].rd_exist,
            logical_rd: op_in[i].rd,
            physical_rd: op_in[i].rd != 0 ? available_prd[i] : 0,
            previous_physical_rd: rat_next[op_in[i].rd],
            pred_taken: op_in[i].pred_taken,
            pred_taken_addr: op_in[i].btb_addr,
            is_page_fault_instr: op_in[i].is_page_fault,
            // いずれの命令にしろ,PMPで指定されている範囲外から取ってきた場合はaccess_faultを出す.
            // TODO: ココらへんのチェックはコミット直前のほうが良い？
            is_access_fault_instr:
            op_in[i].is_access_fault
            ||
            pmp_access_fault
            (
              op_in[i].paddr,
              priv_rval,
              1,
              0,
              0,
              csr_port.pmpcfg_rdata,
              csr_port.pmpaddr_rdata,
              csr_port.mcounteren_rdata
            ),
            raw_op: op_in[i].raw_op,

            has_rs1: op_in[i].rs1_exist,
            has_rs2: op_in[i].rs2_exist,
            logical_rs1: op_in[i].rs1,
            logical_rs2: op_in[i].rs2,
            physical_rs1: rat_next[op_in[i].rs1],
            physical_rs2: rat_next[op_in[i].rs2]
        };


        // op_out_nextの作成. 
        // if (op_in[i].opcode inside {ILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMA}) begin
        //   // ILLEGAL_INSTR, ECALL, EBREAK では,もとからdoneにはしておき,exceptionを出す. 
        //   // MRET, SRET, WFI, FENCE, FENCE_VMA では もとよりdoneにはしておくが,exceptionは出さない.
        //   // exceptionの判定はコミット時に行う.
        //   al_done_new_from_op_in[num_of_new_al] = '{
        //       valid: 1,
        //       al_bank_idx: al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
        //       al_inbank_idx: al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
        //   };
        //   // 出力
        //   op_out_next[i] = '{valid: 0, opcode: NOP, default: 0};
        // end else 
        if (op_in[i].opcode == FENCE_I || op_in[i].opcode inside {ILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMA}) begin
          // ILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMA はopの出力をしない.
          // doneはfeedback_resultの更新のときに立てる.
          // FENCE_Iもopの出力もしない.
          // alの先頭になったらcacheをinvalidateする.
          // al_done_new_from_op_in[num_of_new_al] = '{default: 0};
          // 出力
          op_out_next[i] = '{valid: 0, opcode: NOP, default: 0};
        end else begin
          // その他通常の命令.
          // al_done_new_from_op_in[num_of_new_al] = '{default: 0};
          // 出力.
          op_out_next[i] = '{
              valid: 1,
              opcode: op_in[i].opcode,
              op_addr: op_in[i].vaddr,
              rs1_exist: op_in[i].rs1_exist,
              rs2_exist: op_in[i].rs2_exist,
              rd_exist: op_in[i].rd_exist,
              rs1: rat_next[op_in[i].rs1],
              rs2: rat_next[op_in[i].rs2],
              rd: op_in[i].rd_exist && op_in[i].rd != 0 ? available_prd[i] : 0,
              imm: op_in[i].imm,
              al_idx: al_idx
          };
        end



        // ratの更新をここでしておくと後続の命令のrsを変換できる.
        if (op_in[i].rd_exist && op_in[i].rd != 0) begin
          rat_next[op_in[i].rd] = available_prd[i];
          prd_used[i] = 1;
        end else begin
          prd_used[i] = 0;
        end


        num_of_new_al++;

      end
    end
  end


  // --------------------------------------------------------------------------------------------------------
  // 処理が終了した命令のフィードバックによるアクティブリスト更新処理.
  // ---------------------------------------------------------------------------------------------------------
  always_comb begin
    automatic logic has_set_done_to_special_instr = 0;


    // al_done, al_amo_ld_doneの更新
    al_done_new_from_op_feedback = '{default: 0};
    al_amo_ld_done_new = '{default: 0};

    al_result_w_en = '{default: 0};
    al_result_w_idx = '{default: 0};
    al_result_w_data_strc = '{default: 0};



    for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
      automatic logic [AL_IDX_WIDTH-1:0] al_idx = feedback_op[i].al_idx;
      automatic logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx = al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB];
      automatic
      logic [AL_INBANK_IDX_WIDTH-1:0]
      al_inbank_idx = al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB];

      automatic logic target_address_misalignment = 0;

      if (feedback_op[i].valid) begin

        // amo命令のロードが帰ってきた場合,phyregのrdの更新などは行うが,doneにはしない.
        // なぜなら,amo命令のストア部分が仮実行したときにdoneにするべきだから.
        if (is_amo_opcode(feedback_op[i].opcode)) begin

          //　amo命令でld命令がすでにdoneしていたならamo命令自体をdoneにできる.
          // al_done_new_from_op_feedback[i] = '{
          //     valid: 1,
          //     al_bank_idx: al_bank_idx,
          //     al_inbank_idx: al_inbank_idx
          // };
          // amo命令で,ls命令がfeedbackされた場合,ld_doneをたてる
          // (このあとにamoのst命令部が実行される)


          if (al_amo_ld_done[al_bank_idx][al_inbank_idx]) begin
            // amo命令のldがすでに実行済の場合,amoのst部がdoneにする
            al_done_new_from_op_feedback[i] = '{
                valid: 1,
                al_bank_idx: al_bank_idx,
                al_inbank_idx: al_inbank_idx
            };
          end else begin
            // amoのld命令.
            al_amo_ld_done_new[i] = '{
                valid: 1,
                al_bank_idx: al_bank_idx,
                al_inbank_idx: al_inbank_idx
            };

            al_result_w_en[i] = 1;
            al_result_w_idx[i] = al_idx;
            al_result_w_data_strc[i] = '{
                actual_taken: feedback_op[i].actual_taken,
                actual_taken_addr: feedback_op[i].actual_taken_addr,
                ldst_target_vaddr: feedback_op[i].ldst_target_vaddr,
                ldst_target_paddr: feedback_op[i].ldst_target_paddr,
                is_page_fault_ldst: feedback_op[i].is_page_fault,
                is_access_fault_ldst: feedback_op[i].is_access_fault,
                target_address_misalignment: target_address_misalignment,  // TODO
                rd_val: feedback_op[i].rd_val
            };


          end



        end else begin

          // jmp,branchの飛び先のmisalignment
          if ((is_jmp_opcode(
                  feedback_op[i].opcode
              ) || is_branch_opcode(
                  feedback_op[i].opcode
              )) && feedback_op[i].actual_taken &&
                  feedback_op[i].actual_taken_addr[1:0] != 2'b00) begin
            target_address_misalignment = 1;
          end else if (is_ld_opcode(
                  feedback_op[i].opcode
              ) || is_st_opcode(
                  feedback_op[i].opcode
              ) || is_amo_opcode(
                  feedback_op[i].opcode
              )) begin
            case (get_data_size_from_opcode(
                feedback_op[i].opcode
            ))
              1: begin
                // misalignmentは存在しない.
              end
              2: begin
                if (feedback_op[i].ldst_target_paddr[0] != 0) begin
                  target_address_misalignment = 1;
                end
              end
              4: begin
                if (feedback_op[i].ldst_target_paddr[1:0] != 0) begin
                  target_address_misalignment = 1;
                end
              end
              8: begin
                if (feedback_op[i].ldst_target_paddr[2:0] != 0) begin
                  target_address_misalignment = 1;
                end
              end
              default: $display("[LOG][%s,%-d]", `__FILE__, `__LINE__);
            endcase
          end


          // al_resultに書き込みを行う.
          // ただし,amo命令のst命令は書き込みを行わずにdoneだけ更新する.
          // if (!is_amo_opcode(feedback_op[i].opcode)) begin
          al_result_w_en[i] = 1;
          al_result_w_idx[i] = al_idx;
          al_result_w_data_strc[i] = '{
              actual_taken: feedback_op[i].actual_taken,
              actual_taken_addr: feedback_op[i].actual_taken_addr,
              ldst_target_vaddr: feedback_op[i].ldst_target_vaddr,
              ldst_target_paddr: feedback_op[i].ldst_target_paddr,
              is_page_fault_ldst: feedback_op[i].is_page_fault,
              is_access_fault_ldst: feedback_op[i].is_access_fault,
              target_address_misalignment: target_address_misalignment,
              rd_val: feedback_op[i].rd_val
          };
          // if (feedback_op[i].is_access_fault) begin
          //   dump_vuop_result(feedback_op[i]);
          // end

          // doneを立てる.
          al_done_new_from_op_feedback[i] = '{
              valid: 1,
              al_bank_idx: al_bank_idx,
              al_inbank_idx: al_inbank_idx
          };

        end

      end else begin
        // feedbackがなかった場合,代わりに先頭に存在するILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMAをdoneにする
        // doneにするのとal_resultの更新は必ずセットで行わなければならない.
        // もともとILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMAはop_inが入ってきた時点でdoneにしていたが,それだと
        // al_resultが前のやつのまま残ってしまうので,ここでal_resultの更新とセットでdoneも更新することにする.
        // 更新するのは先頭の一つのみ.これらの命令はどうせcommit時にflushするので.
        if(!has_set_done_to_special_instr && noei_al > 0 &&
            al_meta_heads[0].opcode inside {ILLEGAL_INSTR, ECALL, EBREAK, MRET, SRET, WFI, FENCE, SFENCE_VMA})begin
          al_bank_idx = al_heads_al_bank_idx[0];
          al_inbank_idx = al_heads_al_inbank_idx[0];

          al_result_w_en[i] = 1;
          al_result_w_idx[i] = {al_inbank_idx, al_bank_idx};
          al_result_w_data_strc[i] = '{
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_vaddr: 0,
              ldst_target_paddr: 0,
              is_page_fault_ldst: 0,
              is_access_fault_ldst: 0,
              target_address_misalignment: 0,
              rd_val: 0
          };

          al_done_new_from_op_feedback[i] = '{
              valid: 1,
              al_bank_idx: al_bank_idx,
              al_inbank_idx: al_inbank_idx
          };

          has_set_done_to_special_instr = 1;

        end
      end
    end
  end

  // -----------------------------------------------------------
  // LSUでのrawハザード検知でのアクティブリスト更新処理
  // -----------------------------------------------------------
  // 本当はrenamerから全体に対してflushの命令を送るのではなく,ld以降の命令のみをやり直せばいいのだが,
  // 実装が面倒なので,そのldの命令より前の命令がコミット終了するまで待ってからflushしてやり直す.
  always_comb begin
    al_raw_hazard_new = '{default: 0};
    if (lsu_port.ld_speculative_feedback_valid) begin
      al_raw_hazard_new = '{
          valid: 1,
          al_bank_idx: lsu_port.ld_speculative_feedback_al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
          al_inbank_idx:
          lsu_port.ld_speculative_feedback_al_idx[
          AL_INBANK_IDX_MSB
          :
          AL_INBANK_IDX_LSB
          ]
      };
      // $display("[LOG][Renamer.sv] speculative");
    end
  end




  // ---------------------------------------------------------------------------------------------------------
  // FENCE_Iが先頭ならdoneにする
  // ---------------------------------------------------------------------------------------------------------
  always_comb begin
    al_done_new_from_fence_i = '{default: 0};
    if (noei_al > 0 && al_meta_heads[0].opcode == FENCE_I && invalidate_l1cache_done) begin
      al_done_new_from_fence_i = '{
          valid: 1,
          al_bank_idx: al_rp[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
          al_inbank_idx: al_rp[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
      };
      $display("[LOG][%s,%-d] FENCE_I is done. invalidate_l1cache_done:%0d", `__FILE__, `__LINE__,
               invalidate_l1cache_done);
    end
  end

  always_comb begin
    if (invalidate_l1cache) begin
      $display("[LOG][%s,%-d] invalidate_l1cache is set. noei_al:%0d", `__FILE__, `__LINE__,
               noei_al);
    end
  end


  // ---------------------------------------------------------------------------------------------------------
  // アクティブリストからの卒業処理
  // ---------------------------------------------------------------------------------------------------------

  exception_info_t exception_info[NUM_OF_GRADUATE];

  typedef enum logic [3:0] {
    INTERRUPT_IN_S_MODE,
    INTERRUPT_IN_M_MODE,
    EXCEPTION_IN_S_MODE,
    EXCEPTION_IN_M_MODE,
    RAW_HAZARD_IN_MEM_ADDR,
    COMMIT_FENCE_I,
    COMMIT_MISPREDICTION,
    COMMIT_CSR,
    COMMIT_SRET,
    COMMIT_MRET,
    COMMIT_SFENCE_VMA,
    COMMIT_NORMAL,
    COMMIT_TYPE_NONE
  } commit_type_e;
  commit_type_e commit_type[NUM_OF_GRADUATE];

  // headsの中にコミットされていない命令があるかと,
  // コミットされていな命令がある場合,そのうち最もidxが小さいもの.
  logic not_committed_instr_exist_in_heads;
  int unsigned not_committed_first_instr_idx_in_heads;



  // コミットの種類を判別.
  // 実際の処理は後続のalways_combブロックで行う.
  always_comb begin

    automatic int unsigned st_commit_counter = 0;

    not_committed_instr_exist_in_heads = 0;
    not_committed_first_instr_idx_in_heads = 0;

    commit_type = '{default: COMMIT_TYPE_NONE};

    exception_info = '{default: 0};


    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin


      // st命令の場合は,commit可能かを確認する.st命令で無いならst_commitableは1.
      // NUM_OF_ST_EXEを超える量のコミット,あるいはdcache_noroomである場合,あるいはuartのtx_fifoが満タンの場合
      // においてはst命令をコミットできない
      automatic
      logic
      st_commitable = !is_st_opcode(
          al_meta_heads[i].opcode
      ) || (st_commit_counter < NUM_OF_ST_EXE && !dcache_noroom && !tx_fifo_full);

      automatic logic [AL_IDX_WIDTH-1:0] al_idx = al_rp + AL_IDX_WIDTH'(i);
      automatic logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx = al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB];
      automatic
      logic [AL_INBANK_IDX_WIDTH-1:0]
      al_inbank_idx = al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB];


      // mretとかsfence_vmaとかはもとからal_doneになっているため,前のal_resultの内容を上書きせず,
      // そのまま使用してしまう可能性がある.
      // それらの命令に対しては,renamerより前で発生するexceptionに限定して検知する,
      // 例えばillegal instr,instruction page fault,instrucntion access faultなどである.
      // exception_info[i] = check_exception(
      //   al_meta_heads[i],
      //   al_result_heads[i],
      //   priv_rval,
      //   csr_port.mstatus_rdata,
      //   csr_port.mcounteren_rdata,
      //   csr_port.scounteren_rdata,
      //   csr_port.pmpcfg_rdata,
      //   csr_port.pmpaddr_rdata
      // );
      // if (al_result_heads[i].is_access_fault_ldst) begin
      //   $display("access fault detected. al_idx:%d generation:%h", al_idx, generation);
      //   //   dump_al_meta(al_meta_heads[i]);
      //   //   dump_al_result(al_result_heads[i]);
      // end


      if (noei_al > (AL_IDX_WIDTH+1)'(i) && al_done[al_bank_idx][al_inbank_idx] && st_commitable) begin
        // mretとかsfence_vmaとかはもとからal_doneになっているため,前のal_resultの内容を上書きせず,
        // そのまま使用してしまう可能性がある.
        // それらの命令に対しては,renamerより前で発生するexceptionに限定して検知する,
        // 例えばillegal instr,instruction page fault,instrucntion access faultなどである.
        exception_info[i] = check_exception(
          al_meta_heads[i],
          al_result_heads[i],
          priv_rval,
          csr_port.mstatus_rdata,
          csr_port.mcounteren_rdata,
          csr_port.scounteren_rdata,
          csr_port.pmpcfg_rdata,
          csr_port.pmpaddr_rdata
        );
        if (!is_ld_opcode(
                al_meta_heads[i].opcode
            ) && !is_st_opcode(
                al_meta_heads[i].opcode
            ) && ((csr_port.mstatus_rdata.as_mstatus.SIE && priv_rval == S_MODE) ||
                  priv_rval == U_MODE) &&
                ((csr_port.mideleg_rdata & csr_port.sie_rdata & csr_port.sip_rdata) != 0)) begin
          // ① s_modeでの割り込み.
          commit_type[i] = INTERRUPT_IN_S_MODE;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (!is_ld_opcode(
                al_meta_heads[i].opcode
            ) && !is_st_opcode(
                al_meta_heads[i].opcode
            ) && ((priv_rval == M_MODE && csr_port.mstatus_rdata.as_mstatus.MIE) ||
                  priv_rval inside {U_MODE, S_MODE}) &&
                ((~csr_port.mideleg_rdata) & csr_port.mie_rdata & csr_port.mip_rdata) != 0) begin
          // ② m_modeでの割り込み
          commit_type[i] = INTERRUPT_IN_M_MODE;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if(exception_info[i].valid && csr_port.medeleg_rdata.as_uint[exception_info[i].cause] &&
               (priv_rval == U_MODE || priv_rval ==S_MODE))begin
          // ③ s_modeでの例外処理
          commit_type[i] = EXCEPTION_IN_S_MODE;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (exception_info[i].valid) begin
          // ④ m_modeでの例外処理
          commit_type[i] = EXCEPTION_IN_M_MODE;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (al_raw_hazard[al_bank_idx][al_inbank_idx]) begin
          // ⑤ LSUでメモリ間でのrawハザードが検出された場合
          commit_type[i] = RAW_HAZARD_IN_MEM_ADDR;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          // $display(
          //     "[LOG][%s,%-d] RAW hazard in mem addr is detected. al_bank_idx:%0d, al_inbank_idx:%0d",
          //     `__FILE__, `__LINE__, al_bank_idx, al_inbank_idx);
          break;

        end else if (al_meta_heads[i].opcode == FENCE_I) begin
          // ⑥ FENCE_I命令をコミットする場合.
          commit_type[i] = COMMIT_FENCE_I;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (is_csr_opcode(al_meta_heads[i].opcode)) begin
          // ⑧ csrのコミット
          commit_type[i] = COMMIT_CSR;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (al_meta_heads[i].opcode == MRET) begin
          // ⑨ mretのコミット
          commit_type[i] = COMMIT_MRET;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (al_meta_heads[i].opcode == SRET) begin
          // ⑩ sretのコミット
          commit_type[i] = COMMIT_SRET;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (al_meta_heads[i].opcode == SFENCE_VMA) begin
          // ⑪ sfence_vmaのコミット
          commit_type[i] = COMMIT_SFENCE_VMA;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else if (al_meta_heads[i].pred_taken != al_result_heads[i].actual_taken ||
                (al_meta_heads[i].pred_taken == 1 && al_result_heads[i].actual_taken == 1 &&
                 al_meta_heads[i].pred_taken_addr != al_result_heads[i].actual_taken_addr)) begin
          // ⑦ mispredictionな飛び先を持つ命令をコミットする場合
          // もとはこれをcommit_sretとかの前においていたが,sretがmis_predと判定されたときに(予測子は下位アドレスに基づいているだけなのでされうる),
          // commit_mispredictionとなってはいけない,つまりcommit_sretとなるように,commit_mispredictionは最後のほうに置く.
          commit_type[i] = COMMIT_MISPREDICTION;
          // この命令以降はflushするので,not_committed_instr_exist_in_headsが立たないようにbreakする
          break;

        end else begin
          // ⑫ 通常のコミット
          commit_type[i] = COMMIT_NORMAL;
          if (is_st_opcode(al_meta_heads[i].opcode) || is_amo_opcode(al_meta_heads[i].opcode)) begin
            st_commit_counter++;
          end
        end

      end else begin
        // ⑬コミットを行わない場合
        // これはコミットを行わない最初の命令
        commit_type[i] = COMMIT_TYPE_NONE;

        not_committed_instr_exist_in_heads = 1;
        not_committed_first_instr_idx_in_heads = i;

        // これはコミットをしない最初の命令なので,当然後続の命令もコミットしない.
        break;

      end
    end
  end



  // コミットしない最初の命令から,各moduleに送る信号を作成する
  always_comb begin


    automatic
    logic [AL_IDX_WIDTH-1:0]
    al_idx = al_rp + AL_IDX_WIDTH'(not_committed_first_instr_idx_in_heads);
    automatic logic [AL_BANK_IDX_WIDTH-1:0] al_bank_idx = al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB];
    automatic
    logic [AL_INBANK_IDX_WIDTH-1:0]
    al_inbank_idx = al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB];

    csru_port.executable_csr = '{default: 0};
    lsu_port.sc_mmio_executable = '{default: 0};
    invalidate_l1cache_next = 0;
    al_fencei_sig_made_new = '{default: 0};

    if (not_committed_instr_exist_in_heads) begin
      // この命令をコミットしない場合,それがcsrならcsrがalの先頭に来ている(=発行可能)という意味である
      if (is_csr_opcode(al_meta_heads[not_committed_first_instr_idx_in_heads].opcode)) begin
        csru_port.executable_csr = '{valid: 1, al_idx: al_idx};
      end

      // scとmmioの実行可能性を伝える.
      lsu_port.sc_mmio_executable = '{
          has_lock: lrsc_lock_next.valid,
          lock_paddr: lrsc_lock_next.paddr,
          is_lr_w: lrsc_lock_next.is_lr_w
      };

      // fence_iが先頭でかつ,それが初めての場合はinvalidate_l1cacheをだしてl1cacheをinvalidateする.
      if (al_meta_heads[not_committed_first_instr_idx_in_heads].opcode == FENCE_I && al_fencei_sig_made[al_bank_idx][al_inbank_idx] == 0) begin
        invalidate_l1cache_next = 1;
        al_fencei_sig_made_new = '{
            valid: 1,
            al_bank_idx: al_bank_idx,
            al_inbank_idx: al_inbank_idx
        };
      end
    end
  end




  // commit_typeに基づいて,実際にコミットの処理を行う
  always_comb begin

    // デバッグ用
    automatic abi_name_e rs1_abi = zero;
    automatic abi_name_e rs2_abi = zero;
    automatic abi_name_e rd_abi = zero;

    // => LSU
    lsu_port.committed_instr      = '{default: 0};

    // => csru
    csru_port.committed_instr     = '{default: 0};

    // feedback, flush
    misprediction_feedback_to_btb = '{default: 0};
    is_taken_feedback_to_pred     = '{default: 0};
    flush_from_renamer            = '{default: 0};

    // => csr_regs
    csr_port.mstatus_w            = '{default: 0};
    csr_port.sstatus_w            = '{default: 0};
    csr_port.mepc_w               = '{default: 0};
    csr_port.mcause_w             = '{default: 0};
    csr_port.mtval_w              = '{default: 0};
    csr_port.sepc_w               = '{default: 0};
    csr_port.scause_w             = '{default: 0};
    csr_port.stval_w              = '{default: 0};

    // 特権レベル変更.
    priv_w                        = '{en: 0, val: M_MODE};

    // => Free list
    committed_rd_valid            = '{default: 0};
    committed_phyreg              = '{default: 0};
    committed_prev_phyreg         = '{default: 0};

    // lrsc
    lrsc_lock_next                = lrsc_lock;

    // rrat
    rrat_next                     = rrat;

    // al
    num_of_used_al                = 0;
    al_done_del                   = '{default: 0};
    al_amo_ld_done_del            = '{default: 0};
    al_fencei_sig_made_del        = '{default: 0};
    al_raw_hazard_del             = '{default: 0};

    // 各種flush
    flush_tlb                     = 0;
    flush_al                      = 0;
    flush_fl                      = 0;


    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      automatic logic [5:0] extracted_cause = 0;
      automatic logic [AL_IDX_WIDTH-1:0] al_idx = al_rp + AL_IDX_WIDTH'(i);


      case (commit_type[i])
        INTERRUPT_IN_S_MODE: begin
          // causeの値を探索.
          for (int unsigned j = 0; j < XLEN; j++) begin
            if (csr_port.mideleg_rdata[j] & csr_port.sie_rdata[j] & csr_port.sip_rdata[j]) begin
              extracted_cause = 6'(j);
            end
          end
          // num_of_entries_in_alが0より大きくないとコードが実行されないので,
          // al_next[al_rp_next]は割り込み処理を行う場合でも必ず存在する.よってal_next[].addrを用いる.
          csr_port.sepc_w.en = 1;
          csr_port.sepc_w.data = vaddr_to_xlen(al_meta_heads[i].op_vaddr);

          // scause
          csr_port.scause_w.en = 1;
          csr_port.scause_w.data.as_scause.INTERRUPT = 1;
          csr_port.scause_w.data.as_scause.EXCEPTION_CODE = 63'(extracted_cause);

          // stval
          csr_port.stval_w.en = 1;
          csr_port.stval_w.data.as_stval.STVAL = 0;

          // sstatus
          // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
          csr_port.sstatus_w.en = 1;
          csr_port.sstatus_w.data.as_uint = csr_port.sstatus_rdata.as_uint;
          // 割り込み,例外発生前の特権モード
          csr_port.sstatus_w.data.as_sstatus.SPP = priv_rval[0];
          csr_port.sstatus_w.data.as_sstatus.SPIE = csr_port.sstatus_rdata.as_sstatus.SIE;
          csr_port.sstatus_w.data.as_sstatus.SIE = 0;  // Supervisorレベルの割り込みを禁止.

          // 次のpcを指定.
          flush_from_renamer = '{
              valid: 1,
              addr:
              VADDR_WIDTH
              '(
              {
              csr_port.stvec_rdata.as_stvec.BASE
              ,
              2'b00
              } + (
              (csr_port.stvec_rdata.as_stvec.MODE == 1) ? (4 * extracted_cause) : 0
              )
              )
          };

          // 特権レベルの変更
          priv_w = '{en: 1, val: S_MODE};

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog,
                    "%010h: Interruption handling in S-MODE Cause:%2d stvec:%016h, current_priv:%b",
                    al_meta_heads[i].op_vaddr, extracted_cause, {
                    csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, priv_rval);
          $fflush(fp_mainlog);
`endif



        end

        INTERRUPT_IN_M_MODE: begin
          // causeの値を探索.
          for (int unsigned j = 0; j < XLEN; j++) begin
            if (~csr_port.mideleg_rdata[j] & csr_port.mie_rdata[j] & csr_port.mip_rdata[j]) begin
              extracted_cause = 6'(j);
            end
          end

          // num_of_entries_in_alが0より大きくないとコードが実行されないので,
          // al_next[al_rp_next]は割り込み処理を行う場合でも必ず存在する.よってal_next[].addrを用いる.
          csr_port.mepc_w.en = 1;
          csr_port.mepc_w.data = vaddr_to_xlen(al_meta_heads[i].op_vaddr);

          // mcause
          csr_port.mcause_w.en = 1;
          csr_port.mcause_w.data.as_mcause.INTERRUPT = 1;
          csr_port.mcause_w.data.as_mcause.EXCEPTION_CODE = 63'(extracted_cause);

          // mtval
          csr_port.mtval_w.en = 1;
          csr_port.mtval_w.data.as_mtval.MTVAL = 0;

          // mstatus
          // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
          csr_port.mstatus_w.en = 1;
          csr_port.mstatus_w.data.as_uint = csr_port.mstatus_rdata.as_uint;
          // 割り込み,例外発生前の特権モード
          csr_port.mstatus_w.data.as_mstatus.MPP = priv_rval;
          csr_port.mstatus_w.data.as_mstatus.MPIE = csr_port.mstatus_rdata.as_mstatus.MIE;
          csr_port.mstatus_w.data.as_mstatus.MIE = 0;

          // 次のpcを指定.
          flush_from_renamer = '{
              valid: 1,
              addr:
              VADDR_WIDTH
              '(
              {
              csr_port.mtvec_rdata.as_mtvec.BASE
              ,
              2'b00
              } + (
              (csr_port.mtvec_rdata.as_mtvec.MODE == 1) ? (4 * extracted_cause) : 0
              )
              )
          };


          // 特権レベルをM_MODEに変更.
          priv_w = '{en: 1, val: M_MODE};

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog,
                    "%010h: Interruption handling in M-MODE Cause:%2d mtvec:%016h, current_priv:%b",
                    al_meta_heads[i].op_vaddr, exception_info[i].cause, exception_info[i].tval,
                    priv_rval);
          $fflush(fp_mainlog);
`endif



        end

        EXCEPTION_IN_S_MODE: begin
          // 戻り先のpcの保管.
          csr_port.sepc_w.en = 1;
          csr_port.sepc_w.data.as_sepc.SEPC = vaddr_to_xlen(al_meta_heads[i].op_vaddr);

          // scause
          csr_port.scause_w.en = 1;
          csr_port.scause_w.data.as_scause.INTERRUPT = 0;
          csr_port.scause_w.data.as_scause.EXCEPTION_CODE = 63'(exception_info[i].cause);

          // stval
          csr_port.stval_w.en = 1;
          csr_port.stval_w.data.as_stval.STVAL = exception_info[i].tval;

          // sstatus
          // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
          csr_port.sstatus_w.en = 1;
          csr_port.sstatus_w.data.as_uint = csr_port.sstatus_rdata.as_uint;
          // 割り込み,例外発生前の特権モード
          csr_port.sstatus_w.data.as_sstatus.SPP = priv_rval[0];
          csr_port.sstatus_w.data.as_sstatus.SPIE = csr_port.sstatus_rdata.as_sstatus.SIE;
          csr_port.sstatus_w.data.as_sstatus.SIE = 0;  // Supervisorレベルの割り込みを禁止.

          // 次のpcを指定.
          flush_from_renamer = '{
              valid: 1,
              addr: VADDR_WIDTH'({csr_port.stvec_rdata.as_stvec.BASE, 2'b00})
          };


          // 特権レベルの変更
          priv_w = '{en: 1, val: S_MODE};

`ifdef MAINLOG_EN
          $fdisplay(
              fp_mainlog,
              "%010h: Exception handling in S-MODE Cause:%2d stvec:%016h raw_op:%016h current_priv:%b",
              al_meta_heads[i].op_vaddr, exception_info[i].cause, exception_info[i].tval,
              al_meta_heads[i].raw_op, priv_rval);
          $fflush(fp_mainlog);
`endif





        end

        EXCEPTION_IN_M_MODE: begin

          // mepc
          csr_port.mepc_w.en = 1;
          csr_port.mepc_w.data.as_mepc.MEPC = vaddr_to_xlen(al_meta_heads[i].op_vaddr);

          // mcause
          csr_port.mcause_w.en = 1;
          csr_port.mcause_w.data.as_mcause.INTERRUPT = 0;
          csr_port.mcause_w.data.as_mcause.EXCEPTION_CODE = 63'(exception_info[i].cause);

          // mtval
          csr_port.mtval_w.en = 1;
          csr_port.mtval_w.data.as_mtval.MTVAL = exception_info[i].tval;

          // mstatus
          csr_port.mstatus_w.en = 1;
          csr_port.mstatus_w.data.as_uint = csr_port.mstatus_rdata.as_uint;
          csr_port.mstatus_w.data.as_mstatus.MPP = priv_rval;  // Machine Previous Priv
          csr_port.mstatus_w.data.as_mstatus.MPIE = csr_port.mstatus_rdata.as_mstatus.MIE;   // 割り込み,例外発生前のMIEがMPIE
          csr_port.mstatus_w.data.as_mstatus.MIE = 0;  // Machine Interrupt Enable

          // 次のpcを指定
          flush_from_renamer = '{
              valid: 1,
              addr: VADDR_WIDTH'({csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00})
          };

          // 特権レベルの変更
          priv_w = '{en: 1, val: M_MODE};


`ifdef MAINLOG_EN
          $fdisplay(
              fp_mainlog,
              "%010h: Exception handling in M-MODE Cause:%2d mtvec:%016h raw_op:%016h current_priv:%b",
              al_meta_heads[i].op_vaddr, extracted_cause, {
              csr_port.stvec_rdata.as_mtvec.BASE, 2'b00}, al_meta_heads[i].raw_op, priv_rval);
          $fflush(fp_mainlog);
`endif



        end

        RAW_HAZARD_IN_MEM_ADDR: begin
          // この命令は卒業せずにやり直すが,int issue queueがlwtで実行を止めるので同じことの繰り返しでは無い.
          flush_from_renamer = '{valid: 1, addr: al_meta_heads[i].op_vaddr};
        end

        COMMIT_FENCE_I: begin
          flush_from_renamer = '{valid: 1, addr: al_meta_heads[i].op_vaddr + 4};

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:FENCE_I", al_meta_heads[i].op_vaddr);
          $fflush(fp_mainlog);
`endif
        end

        COMMIT_MISPREDICTION: begin
          // btbの更新用
          // 予測が失敗して,かつ実際にはtakenだった場合のみbtbは更新される.
          misprediction_feedback_to_btb = '{
              valid: al_result_heads[i].actual_taken ? 1 : 0,
              op_addr: al_meta_heads[i].op_vaddr,
              dest_addr: al_result_heads[i].actual_taken_addr
          };

          // predictorの更新用.
          is_taken_feedback_to_pred[i] = '{
              valid: 1,
              op_addr: al_meta_heads[i].op_vaddr,
              taken: al_result_heads[i].actual_taken
          };

          // この命令までは卒業したのでアクティブリストに入っている後続の命令は消していい.
          flush_from_renamer = '{
              valid: 1,
              addr:
              al_result_heads[i].actual_taken
              ?
              al_result_heads[i].actual_taken_addr
              :
              al_meta_heads[i].op_vaddr
              +
              VADDR_WIDTH
              '(
              $unsigned(4)
              )
          };

        end

        COMMIT_CSR: begin
          flush_from_renamer = '{
              valid: 1,
              addr: al_meta_heads[i].op_vaddr + VADDR_WIDTH'($unsigned(4))
          };

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:%s commit CSR rd:%h, rd_val:%016h",
                    al_meta_heads[i].op_vaddr, al_meta_heads[i].opcode.name(),
                    al_meta_heads[i].physical_rd, al_result_heads[i].rd_val);
          $fflush(fp_mainlog);
`endif


        end

        COMMIT_MRET: begin
          priv_w.en = 1;
          priv_w.val = HART_DEFS::privilege_level_e'(csr_port.mstatus_rdata.as_mstatus.MPP);

          // mstatus
          csr_port.mstatus_w.en = 1;
          csr_port.mstatus_w.data = csr_port.mstatus_rdata;
          csr_port.mstatus_w.data.as_mstatus.MIE = csr_port.mstatus_rdata.as_mstatus.MPIE;
          csr_port.mstatus_w.data.as_mstatus.MPIE = 1;
          csr_port.mstatus_w.data.as_mstatus.MPP = 2'b00;

          // mepcに保存した値から再開させる.
          flush_from_renamer = '{valid: 1, addr: VADDR_WIDTH'(csr_port.mepc_rdata.as_mepc.MEPC)};

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:MRET commit", al_meta_heads[i].op_vaddr);
          $fflush(fp_mainlog);
`endif



        end

        COMMIT_SRET: begin
          //元の特権モードに戻る.
          priv_w.en = 1;
          // SPPはu-mode,s-modeのみなので
          priv_w.val = HART_DEFS::privilege_level_e'({1'b0, csr_port.sstatus_rdata.as_sstatus.SPP});

          // sstatus
          csr_port.sstatus_w.en = 1;
          csr_port.sstatus_w.data = csr_port.sstatus_rdata;
          csr_port.sstatus_w.data.as_mstatus.SIE = csr_port.sstatus_rdata.as_mstatus.SPIE;
          csr_port.sstatus_w.data.as_mstatus.SPIE = 1;
          csr_port.sstatus_w.data.as_mstatus.SPP = 1'b0;

          // sepcに保存した値から再開.
          flush_from_renamer = '{valid: 1, addr: VADDR_WIDTH'(csr_port.sepc_rdata.as_sepc.SEPC)};


`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:SRET commit ", al_meta_heads[i].op_vaddr);
          $fflush(fp_mainlog);
`endif



        end

        COMMIT_SFENCE_VMA: begin
          flush_tlb = 1;
          flush_from_renamer = '{
              valid: 1,
              addr: VADDR_WIDTH'(al_meta_heads[i].op_vaddr + VADDR_WIDTH'(4))
          };

`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:SFENCE_VMA commit", al_meta_heads[i].op_vaddr);
          $fflush(fp_mainlog);
`endif


        end

        COMMIT_NORMAL: begin
          // predictorの更新用.
          if (is_branch_opcode(
                  al_meta_heads[i].opcode
              ) || is_jmp_opcode(
                  al_meta_heads[i].opcode
              )) begin
            is_taken_feedback_to_pred[i] = '{
                valid: 1,
                op_addr: al_meta_heads[i].op_vaddr,
                taken: al_result_heads[i].actual_taken
            };
          end


`ifdef MAINLOG_EN
          $fdisplay(fp_mainlog, "%010h: Opcode:%s normal commit", al_meta_heads[i].op_vaddr,
                    al_meta_heads[i].opcode.name());
          $fflush(fp_mainlog);
`endif

        end

        COMMIT_TYPE_NONE: begin

        end

        default: begin
          $display("[ERROR][Renamer.sv] Invalid commit type");

        end

      endcase




      // コミット処理.
      case (commit_type[i])
        INTERRUPT_IN_S_MODE, INTERRUPT_IN_M_MODE, EXCEPTION_IN_S_MODE,EXCEPTION_IN_M_MODE,RAW_HAZARD_IN_MEM_ADDR, COMMIT_TYPE_NONE:begin
          // コミット処理を行わない.
        end

        COMMIT_FENCE_I, COMMIT_MISPREDICTION, COMMIT_CSR, COMMIT_SRET, COMMIT_MRET, COMMIT_SFENCE_VMA, COMMIT_NORMAL:begin
          // コミット処理を行う.

          // flへの物理レジスタ返却,rratの更新.
          // x0がrdなら返却不要.
          if (al_meta_heads[i].has_rd && al_meta_heads[i].physical_rd != 0) begin
            committed_rd_valid[i] = 1;
            committed_phyreg[i] = al_meta_heads[i].physical_rd;
            committed_prev_phyreg[i] = al_meta_heads[i].previous_physical_rd;
            rrat_next[al_meta_heads[i].logical_rd] = al_meta_heads[i].physical_rd;
          end else begin
            committed_rd_valid[i] = 0;
            committed_phyreg[i] = 0;
            committed_prev_phyreg[i] = 0;
          end

          // lrsc_lockに登録.
          if ((is_ld_opcode(
                  al_meta_heads[i].opcode
              ) || is_st_opcode(
                  al_meta_heads[i].opcode
              ) || is_amo_opcode(
                  al_meta_heads[i].opcode
              )) && to_dw_aligned_paddr(
                  al_result_heads[i].ldst_target_paddr
              ) == lrsc_lock_next.paddr) begin
            //アドレスがlrsc_lockと一致していた場合は無効化.
            lrsc_lock_next = '{default: 0};
          end
          if (al_meta_heads[i].opcode inside {LR_W, LR_D}) begin
            lrsc_lock_next = '{
                valid: 1,
                paddr: al_result_heads[i].ldst_target_paddr,
                is_lr_w: al_meta_heads[i].opcode == LR_W ? 1 : 0
            };
          end

          // al_rpから使用したエントリ数を記録.
          num_of_used_al++;

          // lsuに卒業した命令の通知.
          lsu_port.committed_instr[i] = '{valid: 1, al_idx: al_idx};
          csru_port.committed_instr[i] = '{valid: 1, al_idx: al_idx};

          // al_done,al_amo_ld_doneの削除
          al_done_del[i] = '{
              valid: 1,
              al_bank_idx: al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
              al_inbank_idx: al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
          };
          al_amo_ld_done_del[i] = '{
              valid: 1,
              al_bank_idx: al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
              al_inbank_idx: al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
          };
          al_fencei_sig_made_del[i] = '{
              valid: 1,
              al_bank_idx: al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
              al_inbank_idx: al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
          };
          al_raw_hazard_del[i] = '{
              valid: 1,
              al_bank_idx: al_idx[AL_BANK_IDX_MSB:AL_BANK_IDX_LSB],
              al_inbank_idx: al_idx[AL_INBANK_IDX_MSB:AL_INBANK_IDX_LSB]
          };

`ifdef VERILATOR_COMPILE
`ifdef COMMITLOG_EN
          begin
            rs1_abi = abi_name_e'(al_meta_heads[i].logical_rs1);
            rs2_abi = abi_name_e'(al_meta_heads[i].logical_rs2);
            rd_abi  = abi_name_e'(al_meta_heads[i].logical_rd);
            $fdisplay(fp_commitlog, "0x%010h: %10s  rs1:%4s  rs2:%4s  rd:%4s  rd_val=0x%016h",
                      al_meta_heads[i].op_vaddr, al_meta_heads[i].opcode.name(),
                      al_meta_heads[i].has_rs1 ? rs1_abi.name() : "_",
                      al_meta_heads[i].has_rs1 ? rs2_abi.name() : "_",
                      al_meta_heads[i].has_rd ? rd_abi.name() : "_", al_result_heads[i].rd_val);
            $fflush(fp_commitlog);
          end
`endif
`endif


        end

        default: begin
          $display("[ERROR][Renamer.sv] ");
        end
      endcase

      // alのflush
      if (flush_from_renamer.valid) begin
        flush_fl = 1;
        flush_al = 1;
        break;
      end

      // if (commit_type[i] != COMMIT_NORMAL) begin
      //   break;
      // end


    end
  end

  //--------------------------------------------------------------------------------------------------------------------
  // stall
  //--------------------------------------------------------------------------------------------------------------------
  always_comb begin
    stall_out = ACTIVELIST_SIZE - 32'(noei_al_next) < NUM_OF_FETCH || stall_in;
  end



  // 初期化用のrat_initを作成.
  // x0 => p0, x1 => p1
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_LOGREGS; i++) begin
      rat_init[i] = $clog2(NUM_OF_PHYREGS)'(i);
    end
  end


  // -------------------------------------------------------------------------------------------------------
  // al_rp_next, al_wp_next等の作成
  // -------------------------------------------------------------------------------------------------------
  always_comb begin
    if (flush_al) begin
      al_rp_next   = 0;
      al_wp_next   = 0;
      noei_al_next = 0;
    end else begin
      al_rp_next   = al_rp + AL_IDX_WIDTH'(num_of_used_al);
      al_wp_next   = al_wp + AL_IDX_WIDTH'(num_of_new_al);
      noei_al_next = noei_al + AL_IDX_WIDTH'(num_of_new_al) - AL_IDX_WIDTH'(num_of_used_al);
    end
  end
`ifdef VIVADO_COMPILE
  always_ff @(posedge clock) begin
    if (reset) begin
      led2 <= 0;
    end else begin
      if (num_of_used_al > 0) begin
        led2 <= 1;
      end
    end
  end
  // コミットが増え続けている間はつく.
  assign led1 = num_of_used_al > 0;
`endif



  // -------------------------------------------------------------------------------------------------------
  // active list, rat
  // -------------------------------------------------------------------------------------------------------
  always_ff @(posedge clock) begin
    if (reset) begin
      // rat,rrat
      rat <= rat_init;
      rrat <= rat_init;

      al_rp <= 0;
      al_wp <= 0;
      noei_al <= 0;


      for (int unsigned i = 0; i < NUM_OF_AL_BANK; i++) begin
        al_done[i] <= '{default: 0};
        al_amo_ld_done[i] <= '{default: 0};
        al_fencei_sig_made[i] <= '{default: 0};
        al_raw_hazard[i] <= '{default: 0};
      end

    end else if (flush_al) begin
      // rat
      rat <= rrat_next;
      rrat <= rrat_next;

      al_rp <= 0;
      al_wp <= 0;
      noei_al <= 0;

      for (int unsigned i = 0; i < NUM_OF_AL_BANK; i++) begin
        al_done[i] <= '{default: 0};
        al_amo_ld_done[i] <= '{default: 0};
        al_fencei_sig_made[i] <= '{default: 0};
        al_raw_hazard[i] <= '{default: 0};
      end

    end else begin
      // rat
      rat <= rat_next;
      rrat <= rrat_next;


      // al
      al_rp <= al_rp_next;
      al_wp <= al_wp_next;
      noei_al <= noei_al_next;


      // al_done
      // al_doneを立てる
      // for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      //   if (al_done_new_from_op_in[i].valid) begin
      //     al_done[al_done_new_from_op_in[i].al_bank_idx][al_done_new_from_op_in[i].al_inbank_idx] <= 1;
      //   end
      // end
      for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
        if (al_done_new_from_op_feedback[i].valid) begin
          al_done[al_done_new_from_op_feedback[i].al_bank_idx][al_done_new_from_op_feedback[i].al_inbank_idx] <= 1;
        end
      end
      if (al_done_new_from_fence_i.valid) begin
        al_done[al_done_new_from_fence_i.al_bank_idx][al_done_new_from_fence_i.al_inbank_idx] <= 1;
      end

      // al_doneを削除
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_done_del[i].valid) begin
          al_done[al_done_del[i].al_bank_idx][al_done_del[i].al_inbank_idx] <= 0;
        end
      end

      // al_amo_ld_done
      for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
        if (al_amo_ld_done_new[i].valid) begin
          al_amo_ld_done[al_amo_ld_done_new[i].al_bank_idx][al_amo_ld_done_new[i].al_inbank_idx] <= 1;
        end
      end
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_amo_ld_done_del[i].valid) begin
          al_amo_ld_done[al_amo_ld_done_del[i].al_bank_idx][al_amo_ld_done_del[i].al_inbank_idx] <= 0;
        end
      end


      // al_fencei_sig_made
      // al_fencei_sig_madeを立てる
      if (al_fencei_sig_made_new.valid) begin
        al_fencei_sig_made[al_fencei_sig_made_new.al_bank_idx][al_fencei_sig_made_new.al_inbank_idx] <= 1;
      end

      // al_fencei_sig_madeを削除
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_fencei_sig_made_del[i].valid) begin
          al_fencei_sig_made[al_fencei_sig_made_del[i].al_bank_idx][al_fencei_sig_made_del[i].al_inbank_idx] <= 0;
        end
      end

      // al_raw_hazard
      if (al_raw_hazard_new.valid) begin
        al_raw_hazard[al_raw_hazard_new.al_bank_idx][al_raw_hazard_new.al_inbank_idx] <= 1;
      end
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_raw_hazard_del[i].valid) begin
          al_raw_hazard[al_raw_hazard_del[i].al_bank_idx][al_raw_hazard_del[i].al_inbank_idx] <= 0;
        end
      end


    end
  end

  // --------------------------------------------------------------------------------------------------
  // minstret, generation
  // --------------------------------------------------------------------------------------------------
  always_ff @(posedge clock) begin
    if (reset) begin
      lrsc_lock <= '{default: 0};

      // invalidate_l1_cache
      invalidate_l1cache <= 0;

      // minstretの更新
      csr_port.minstret_w <= '{en: 1, data: 0};

      // generationの更新
      generation <= 0;

      //　op_outの出力
      op_out <= '{default: 0};
    end else if (flush_al) begin
      //lrsc
      lrsc_lock <= lrsc_lock_next;

      // invalidate_l1_cache
      invalidate_l1cache <= 0;

      // minstretの更新
      if (!csr_port.mcountinhibit_rdata.as_mcountinhibit.IR) begin
        csr_port.minstret_w <= '{en: 1, data: csr_port.minstret_rdata + XLEN'(num_of_used_al)};
      end

      // generationの更新
      generation <= generation + 1;

      //　op_outの出力
      op_out <= '{default: 0};
    end else begin
      // lrsc
      lrsc_lock <= lrsc_lock_next;

      // invalidate_l1_cache
      invalidate_l1cache <= invalidate_l1cache_next;

      // invalidate_l1_cache
      if (!csr_port.mcountinhibit_rdata.as_mcountinhibit.IR) begin
        csr_port.minstret_w <= '{en: 1, data: csr_port.minstret_rdata + XLEN'(num_of_used_al)};
      end

      // generationの更新
      generation <= generation;

      //　op_outの出力
      op_out <= op_out_next;
    end
  end



  // ------------------------------------------------------------
  // debug dump
  // ------------------------------------------------------------
  task automatic dump_al_meta_one(input int unsigned idx, input al_meta_t x);
    $display(
        "  al_meta_heads[%0d] {op_vaddr:0x%0h, opcode:%s, has_rd:%0d, logical_rd:%0d, physical_rd:%0d, prev_physical_rd:%0d, pred_taken:%0d, pred_taken_addr:0x%0h, is_page_fault_instr:%0d, is_access_fault_instr:%0d, raw_op:0x%08h}",
        idx, x.op_vaddr, x.opcode.name(), x.has_rd, x.logical_rd, x.physical_rd,
        x.previous_physical_rd, x.pred_taken, x.pred_taken_addr, x.is_page_fault_instr,
        x.is_access_fault_instr, x.raw_op);
  endtask

  task automatic dump_al_result_one(input int unsigned idx, input al_result_t x);
    $display(
        "  al_result_heads[%0d] {actual_taken:%0d, actual_taken_addr:0x%0h, ldst_target_paddr:0x%0h, ldst_target_vaddr:0x%0h, is_page_fault_ldst:%0d, is_access_fault_ldst:%0d, target_address_misalignment:%0d}",
        idx, x.actual_taken, x.actual_taken_addr, x.ldst_target_paddr, x.ldst_target_vaddr,
        x.is_page_fault_ldst, x.is_access_fault_ldst, x.target_address_misalignment);
  endtask

  task automatic dump_al_all();
    $display("============================================================");
    $display("[AL DUMP] time=%0t", $time);
    $display("  al_rp=%0d  al_wp=%0d  noei_al=%0d", al_rp, al_wp, noei_al);
    $display("  al_rp_next=%0d  al_wp_next=%0d  noei_al_next=%0d", al_rp_next, al_wp_next,
             noei_al_next);
    $display("  al_heads_valid=%p", al_heads_valid);
    $display("  al_heads_al_bank_idx=%p", al_heads_al_bank_idx);

    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      $display("------------------------------------------------------------");
      $display("head[%0d]: valid=%0d bank_idx=%0d", i, al_heads_valid[i], al_heads_al_bank_idx[i]);
      dump_al_meta_one(i, al_meta_heads[i]);
      dump_al_result_one(i, al_result_heads[i]);
    end

    $display("------------------------------------------------------------");
    for (int unsigned bank = 0; bank < NUM_OF_AL_BANK; bank++) begin
      $display("bank[%0d] done=%p", bank, al_done[bank]);
      $display("bank[%0d] amo_ld_done=%p", bank, al_amo_ld_done[bank]);
      $display("bank[%0d] fencei_sig_made=%p", bank, al_fencei_sig_made[bank]);
      $display("bank[%0d] raw_hazard=%p", bank, al_raw_hazard[bank]);
    end
    $display("============================================================");
  endtask

  int unsigned debug_counter;
  always_ff @(posedge clock) begin
    if (reset) begin
      debug_counter <= 0;
    end else begin
      debug_counter <= debug_counter + 1;

      // debug_counter が 1000000 に到達するサイクルで表示したいなら 999999 を見る
      // if (debug_counter == 1299999) begin
      //   $display("debug_counter=%0d", debug_counter + 1);
      //   dump_al_all();
      // end
    end
  end


  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     // 何もしない
  //   end else begin
  //     for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //       if (op_in[i].valid && op_in[i].vaddr == 39'h3ffffff148) begin
  //         $display("\n[LOG][Renamer.sv] hit op_in[%0d] at time=%0t", i, $time);
  //         dump_decoded_op(op_in[i]);
  //       end
  //     end
  //   end
  // end


  // 一つでも命令がコミットした場合はledをオンにする.
  // `ifdef VIVADO_COMPILE
  //   always_ff @(posedge clock) begin
  //     if (reset) begin
  //       white_led <= 0;
  //     end else begin
  //       if (num_of_used_al) begin
  //         white_led <= 1;
  //       end
  //     end
  //   end
  // `endif


  // (* mark_debug="true" *) logic dbg_flush_valid;
  // (* mark_debug="true" *) logic [38:0] dbg_flush_addr;
  // (* mark_debug="true" *) logic [3:0] dbg_commit_type0;
  // (* mark_debug="true" *) logic dbg_exception_valid0;
  // (* mark_debug="true" *) logic [3:0] dbg_exception_cause0;
  // (* mark_debug="true" *) logic [38:0] dbg_al_op_vaddr0;
  // (* mark_debug="true" *) opcode_t dbg_al_opcode0;
  // (* mark_debug="true" *) logic [63:0] dbg_mtvec;
  // (* mark_debug="true" *) logic [63:0] dbg_stvec;
  // (* mark_debug="true" *) logic [63:0] dbg_mepc;
  // (* mark_debug="true" *) logic [63:0] dbg_sepc;

  // assign dbg_flush_valid      = flush_from_renamer.valid;
  // assign dbg_flush_addr       = flush_from_renamer.addr;
  // assign dbg_commit_type0     = commit_type[0];
  // assign dbg_exception_valid0 = exception_info[0].valid;
  // assign dbg_exception_cause0 = exception_info[0].cause[3:0];
  // assign dbg_al_op_vaddr0     = al_meta_heads[0].op_vaddr;
  // assign dbg_al_opcode0       = al_meta_heads[0].opcode;
  // assign dbg_mtvec            = csr_port.mtvec_rdata.as_uint;
  // assign dbg_stvec            = csr_port.stvec_rdata.as_uint;
  // assign dbg_mepc             = csr_port.mepc_rdata.as_uint;
  // assign dbg_sepc             = csr_port.sepc_rdata.as_uint;


  task automatic dump_vuop_result(input vuop_result_t r);
    begin
      $display("========== VUOP_RESULT DUMP ==========");

      $display("  valid              = %0b", r.valid);
      $display("  opcode             = %0d / 0x%0h", r.opcode, r.opcode);
      $display("  op_addr            = 0x%0h", r.op_addr);

      $display("  rd_exist           = %0b", r.rd_exist);
      $display("  rd                 = %0d", r.rd);
      $display("  rd_val             = 0x%0h", r.rd_val);

      $display("  al_idx             = %0d", r.al_idx);

      $display("  actual_taken       = %0b", r.actual_taken);
      $display("  actual_taken_addr  = 0x%0h", r.actual_taken_addr);

      $display("  ldst_target_paddr  = 0x%0h", r.ldst_target_paddr);
      $display("  ldst_target_vaddr  = 0x%0h", r.ldst_target_vaddr);

      $display("  is_page_fault      = %0b", r.is_page_fault);
      $display("  is_access_fault    = %0b", r.is_access_fault);

      $display("======================================");
    end
  endtask

  // ------------------------------------------------------------
  // realtime renamer dump
  // 100 cycleごとに ./log/realtime_renamer.log を上書き作成する
  // ------------------------------------------------------------
// `ifdef VERILATOR_COMPILE

//   localparam int unsigned REALTIME_RENAMER_DUMP_PERIOD = 1000;

//   longint unsigned realtime_renamer_cycle;
//   int realtime_renamer_fp;

//   task automatic realtime_renamer_dump_al_meta(input int unsigned fp, input int unsigned head_i,
//                                                input al_meta_t x);
//     $fdisplay(fp, "    META: op_vaddr=0x%010h opcode=%s raw_op=0x%08h", x.op_vaddr,
//               x.opcode.name(), x.raw_op);
//     $fdisplay(fp, "          has_rd=%0d logical_rd=%0d physical_rd=%0d prev_physical_rd=%0d",
//               x.has_rd, x.logical_rd, x.physical_rd, x.previous_physical_rd);
//     $fdisplay(fp, "          has_rs1=%0d logical_rs1=%0d physical_rs1=%0d", x.has_rs1,
//               x.logical_rs1, x.physical_rs1);
//     $fdisplay(fp, "          has_rs2=%0d logical_rs2=%0d physical_rs2=%0d", x.has_rs2,
//               x.logical_rs2, x.physical_rs2);
//     $fdisplay(fp, "          pred_taken=%0d pred_taken_addr=0x%010h instr_pf=%0d instr_af=%0d",
//               x.pred_taken, x.pred_taken_addr, x.is_page_fault_instr, x.is_access_fault_instr);
//   endtask

//   task automatic realtime_renamer_dump_al_result(input int unsigned fp, input int unsigned head_i,
//                                                  input al_result_t x);
//     $fdisplay(fp, "    RESULT: actual_taken=%0d actual_taken_addr=0x%010h rd_val=0x%016h",
//               x.actual_taken, x.actual_taken_addr, x.rd_val);
//     $fdisplay(fp, "            ldst_vaddr=0x%010h ldst_paddr=0x%010h", x.ldst_target_vaddr,
//               x.ldst_target_paddr);
//     $fdisplay(fp, "            ldst_pf=%0d ldst_af=%0d misalign=%0d", x.is_page_fault_ldst,
//               x.is_access_fault_ldst, x.target_address_misalignment);
//   endtask

//   task automatic realtime_renamer_dump_file(input longint unsigned cyc);
//     realtime_renamer_fp = $fopen("./log/realtime_renamer.log", "w");

//     if (realtime_renamer_fp == 0) begin
//       $display("[REALTIME_RENAMER_DUMP][ERROR] cannot open ./log/realtime_renamer.log");
//     end else begin
//       $fdisplay(realtime_renamer_fp,
//                 "============================================================");
//       $fdisplay(realtime_renamer_fp, "[REALTIME_RENAMER_DUMP] time=%0t cycle=%0d generation=0x%08h",
//                 $time, cyc, generation);
//       $fdisplay(realtime_renamer_fp,
//                 "------------------------------------------------------------");

//       $fdisplay(realtime_renamer_fp, "rp/wp/noei: al_rp=%0d al_wp=%0d noei_al=%0d", al_rp, al_wp,
//                 noei_al);
//       $fdisplay(realtime_renamer_fp, "next      : al_rp_next=%0d al_wp_next=%0d noei_al_next=%0d",
//                 al_rp_next, al_wp_next, noei_al_next);
//       $fdisplay(realtime_renamer_fp, "new/used  : num_of_new_al=%0d num_of_used_al=%0d",
//                 num_of_new_al, num_of_used_al);

//       $fdisplay(
//           realtime_renamer_fp,
//           "stall/flush: stall_in=%0d stall_out=%0d flush_al=%0d flush_from_renamer.valid=%0d addr=0x%010h",
//           stall_in, stall_out, flush_al, flush_from_renamer.valid, flush_from_renamer.addr);

//       $fdisplay(
//           realtime_renamer_fp,
//           "cache/tlb: invalidate_l1cache=%0d invalidate_l1cache_next=%0d invalidate_l1cache_done=%0d flush_tlb=%0d",
//           invalidate_l1cache, invalidate_l1cache_next, invalidate_l1cache_done, flush_tlb);

//       $fdisplay(realtime_renamer_fp, "pending: is_pending=%0d is_pending_next=%0d", is_pending,
//                 is_pending_next);

//       $fdisplay(realtime_renamer_fp, "");
//       $fdisplay(realtime_renamer_fp, "==================== AL HEADS ====================");

//       for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
//         automatic logic [AL_IDX_WIDTH-1:0] head_al_idx;
//         automatic logic [AL_BANK_IDX_WIDTH-1:0] head_bank;
//         automatic logic [AL_INBANK_IDX_WIDTH-1:0] head_inbank;

//         head_bank   = al_heads_al_bank_idx[i];
//         head_inbank = al_heads_al_inbank_idx[i];
//         head_al_idx = {head_inbank, head_bank};

//         $fdisplay(realtime_renamer_fp,
//                   "------------------------------------------------------------");
//         $fdisplay(realtime_renamer_fp,
//                   "HEAD[%0d]: valid=%0d al_idx=%0d bank=%0d inbank=%0d commit_type=%s", i,
//                   al_heads_valid[i], head_al_idx, head_bank, head_inbank, commit_type[i].name());

//         $fdisplay(realtime_renamer_fp,
//                   "         done=%0d amo_ld_done=%0d fencei_sig_made=%0d raw_hazard=%0d",
//                   al_done[head_bank][head_inbank], al_amo_ld_done[head_bank][head_inbank],
//                   al_fencei_sig_made[head_bank][head_inbank],
//                   al_raw_hazard[head_bank][head_inbank]);

//         realtime_renamer_dump_al_meta(realtime_renamer_fp, i, al_meta_heads[i]);
//         realtime_renamer_dump_al_result(realtime_renamer_fp, i, al_result_heads[i]);

//         $fdisplay(realtime_renamer_fp, "    exception_info: valid=%0d cause=%0d tval=0x%016h",
//                   exception_info[i].valid, exception_info[i].cause, exception_info[i].tval);
//       end

//       $fdisplay(realtime_renamer_fp, "");
//       $fdisplay(realtime_renamer_fp, "==================== AL STATUS ARRAYS ====================");

//       for (int unsigned bank = 0; bank < NUM_OF_AL_BANK; bank++) begin
//         $fwrite(realtime_renamer_fp, "bank[%0d] al_done             : ", bank);
//         for (int unsigned idx = 0; idx < AL_BANK_SIZE; idx++) begin
//           $fwrite(realtime_renamer_fp, "%0d", al_done[bank][idx]);
//         end
//         $fdisplay(realtime_renamer_fp, "");

//         $fwrite(realtime_renamer_fp, "bank[%0d] al_amo_ld_done      : ", bank);
//         for (int unsigned idx = 0; idx < AL_BANK_SIZE; idx++) begin
//           $fwrite(realtime_renamer_fp, "%0d", al_amo_ld_done[bank][idx]);
//         end
//         $fdisplay(realtime_renamer_fp, "");

//         $fwrite(realtime_renamer_fp, "bank[%0d] al_fencei_sig_made  : ", bank);
//         for (int unsigned idx = 0; idx < AL_BANK_SIZE; idx++) begin
//           $fwrite(realtime_renamer_fp, "%0d", al_fencei_sig_made[bank][idx]);
//         end
//         $fdisplay(realtime_renamer_fp, "");

//         $fwrite(realtime_renamer_fp, "bank[%0d] al_raw_hazard       : ", bank);
//         for (int unsigned idx = 0; idx < AL_BANK_SIZE; idx++) begin
//           $fwrite(realtime_renamer_fp, "%0d", al_raw_hazard[bank][idx]);
//         end
//         $fdisplay(realtime_renamer_fp, "");
//       end

//       $fdisplay(realtime_renamer_fp, "");
//       $fdisplay(realtime_renamer_fp, "==================== AL UPDATE SIGNALS ====================");

//       for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
//         $fdisplay(
//             realtime_renamer_fp,
//             "feedback[%0d]: valid=%0d opcode=%s al_idx=%0d op_addr=0x%010h rd=%0d rd_val=0x%016h",
//             i, feedback_op[i].valid, feedback_op[i].opcode.name(), feedback_op[i].al_idx,
//             feedback_op[i].op_addr, feedback_op[i].rd, feedback_op[i].rd_val);

//         $fdisplay(
//             realtime_renamer_fp, "  al_done_new_from_feedback: valid=%0d bank=%0d inbank=%0d",
//             al_done_new_from_op_feedback[i].valid, al_done_new_from_op_feedback[i].al_bank_idx,
//             al_done_new_from_op_feedback[i].al_inbank_idx);

//         $fdisplay(realtime_renamer_fp, "  al_result_w: en=%0d idx=%0d", al_result_w_en[i],
//                   al_result_w_idx[i]);
//       end

//       $fdisplay(realtime_renamer_fp, "fence_i_done_update: valid=%0d bank=%0d inbank=%0d",
//                 al_done_new_from_fence_i.valid, al_done_new_from_fence_i.al_bank_idx,
//                 al_done_new_from_fence_i.al_inbank_idx);

//       $fdisplay(realtime_renamer_fp, "fencei_sig_made_new: valid=%0d bank=%0d inbank=%0d",
//                 al_fencei_sig_made_new.valid, al_fencei_sig_made_new.al_bank_idx,
//                 al_fencei_sig_made_new.al_inbank_idx);

//       $fdisplay(realtime_renamer_fp, "raw_hazard_new: valid=%0d bank=%0d inbank=%0d",
//                 al_raw_hazard_new.valid, al_raw_hazard_new.al_bank_idx,
//                 al_raw_hazard_new.al_inbank_idx);

//       $fdisplay(realtime_renamer_fp, "");
//       $fdisplay(realtime_renamer_fp, "==================== DELETE SIGNALS ====================");

//       for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
//         $fdisplay(
//             realtime_renamer_fp,
//             "del[%0d]: done(valid=%0d bank=%0d inbank=%0d) amo(valid=%0d bank=%0d inbank=%0d) fencei(valid=%0d bank=%0d inbank=%0d) raw(valid=%0d bank=%0d inbank=%0d)",
//             i, al_done_del[i].valid, al_done_del[i].al_bank_idx, al_done_del[i].al_inbank_idx,
//             al_amo_ld_done_del[i].valid, al_amo_ld_done_del[i].al_bank_idx,
//             al_amo_ld_done_del[i].al_inbank_idx, al_fencei_sig_made_del[i].valid,
//             al_fencei_sig_made_del[i].al_bank_idx, al_fencei_sig_made_del[i].al_inbank_idx,
//             al_raw_hazard_del[i].valid, al_raw_hazard_del[i].al_bank_idx,
//             al_raw_hazard_del[i].al_inbank_idx);
//       end

//       $fdisplay(realtime_renamer_fp,
//                 "============================================================");
//       $fflush(realtime_renamer_fp);
//       $fclose(realtime_renamer_fp);
//     end
//   endtask

//   always @(posedge clock) begin
//     if (reset) begin
//       realtime_renamer_cycle <= 0;
//     end else begin
//       realtime_renamer_cycle <= realtime_renamer_cycle + 1;

//       if (((realtime_renamer_cycle + 1) % 64'(REALTIME_RENAMER_DUMP_PERIOD)) == 0) begin
//         realtime_renamer_dump_file(realtime_renamer_cycle + 1);
//       end
//     end
//   end

// `endif

endmodule
