// INT Physical Register Files
// p0だけは書きこみされても常に0.
//
// opを5個同時に処理しなければ行けないので,分散メモリ.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module INTPRF
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    input vuop_front_t op_in_ari[NUM_OF_ARI_ISSUE],
    input vuop_front_t op_in_ld_cur[NUM_OF_LD_ISSUE],
    input vuop_front_t op_in_st_amo_cur[NUM_OF_ST_AMO_ISSUE],
    input vuop_front_t op_in_csr_cur[NUM_OF_CSR_ISSUE],

    output vuop_back_t op_out_ari[NUM_OF_ARI_ISSUE],
    output vuop_back_t op_out_ld[NUM_OF_LD_ISSUE],
    output vuop_back_t op_out_st_amo[NUM_OF_ST_AMO_ISSUE],
    output vuop_back_t op_out_csr[NUM_OF_CSR_ISSUE],

    // 結果のフィードバック.これで更新する.
    input vuop_result_t op_feedback[NUM_OF_RESULT_FEEDBACKS],

    input logic stall_in_from_ldst,
    input logic stall_in_from_csr,

    output logic stall_out_ldst,
    output logic stall_out_csr,

    input logic flush_in


);
  // ---------------------------------------
  // stall_in_ldst用.
  // ---------------------------------------
  vuop_front_t op_in_ld[NUM_OF_LD_ISSUE];
  vuop_front_t op_in_st_amo[NUM_OF_ST_AMO_ISSUE];

  vuop_front_t op_in_ld_pending[NUM_OF_LD_ISSUE];
  vuop_front_t op_in_st_amo_pending[NUM_OF_ST_AMO_ISSUE];
  logic is_ldst_pending;

  vuop_front_t op_in_ld_pending_next[NUM_OF_LD_ISSUE];
  vuop_front_t op_in_st_amo_pending_next[NUM_OF_ST_AMO_ISSUE];
  logic is_ldst_pending_next;

  always_comb begin
    is_ldst_pending_next = is_ldst_pending;
    op_in_ld_pending_next = op_in_ld_pending;
    op_in_st_amo_pending_next = op_in_st_amo_pending;

    if (flush_in) begin
      op_in_ld             = '{default: 0};
      op_in_st_amo         = '{default: 0};
      is_ldst_pending_next = 0;
    end else if (stall_in_from_ldst && !is_ldst_pending) begin
      // 新たにstallした場合.
      op_in_ld_pending_next     = op_in_ld_cur;
      op_in_st_amo_pending_next = op_in_st_amo_cur;
      is_ldst_pending_next      = 1;

      op_in_ld                  = '{default: 0};
      op_in_st_amo              = '{default: 0};
    end else if (stall_in_from_ldst) begin
      // 継続でstallした場合.
      op_in_ld = '{default: 0};
      op_in_st_amo = '{default: 0};
    end else if (is_ldst_pending) begin
      // stall終了時.
      op_in_ld             = op_in_ld_pending;
      op_in_st_amo         = op_in_st_amo_pending;
      is_ldst_pending_next = 0;
    end else begin
      // 通常時.
      op_in_ld = op_in_ld_cur;
      op_in_st_amo = op_in_st_amo_cur;

    end
  end

  always_comb begin
    stall_out_ldst = stall_in_from_ldst;
  end


  // ---------------------------------------
  // stall_in_csr用.
  // ---------------------------------------
  vuop_front_t op_in_csr[NUM_OF_CSR_ISSUE];

  vuop_front_t op_in_csr_pending[NUM_OF_CSR_ISSUE];
  logic is_csr_pending;

  vuop_front_t op_in_csr_pending_next[NUM_OF_CSR_ISSUE];
  logic is_csr_pending_next;

  always_comb begin
    is_csr_pending_next = is_csr_pending;
    op_in_csr_pending_next = op_in_csr_pending;

    if (flush_in) begin
      op_in_csr           = '{default: 0};
      is_csr_pending_next = 0;
    end else if (stall_in_from_csr && !is_csr_pending) begin
      // 新たにstallした場合.
      op_in_csr_pending_next = op_in_csr_cur;
      is_csr_pending_next    = 1;

      op_in_csr              = '{default: 0};
    end else if (stall_in_from_csr) begin
      // 継続でstallした場合.
      op_in_csr = '{default: 0};
    end else if (is_csr_pending) begin
      // stall終了時.
      op_in_csr           = op_in_csr_pending;
      is_csr_pending_next = 0;
    end else begin
      // 通常時.
      op_in_csr = op_in_csr_cur;

    end
  end

  always_comb begin
    stall_out_csr = stall_in_from_csr;
  end



  // --------------------------------------------------
  //パラメータ
  // --------------------------------------------------
  localparam int unsigned NUM_OF_PHYREG_READ_PORT = 2 * NUM_OF_ISSUE;
  localparam int unsigned NUM_OF_PHYREG_WRITE_PORT = NUM_OF_RESULT_FEEDBACKS;


  // ------------------------------------------------------
  // PHYREG
  // ------------------------------------------------------
  logic phyreg_r_en[NUM_OF_PHYREG_READ_PORT];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] phyreg_r_ram_idx[NUM_OF_PHYREG_READ_PORT];
  logic [XLEN-1:0] phyreg_r_data[NUM_OF_PHYREG_READ_PORT];

  logic phyreg_w_en[NUM_OF_PHYREG_WRITE_PORT];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] phyreg_w_ram_idx[NUM_OF_PHYREG_WRITE_PORT];
  logic [XLEN-1:0] phyreg_w_data[NUM_OF_PHYREG_WRITE_PORT];
  logic [XLEN/8-1:0] phyreg_w_mask[NUM_OF_PHYREG_WRITE_PORT];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_PHYREG_WRITE_PORT; i++) begin
      phyreg_w_mask[i] = {(XLEN / 8) {1'b1}};
    end
  end

  LVTRAM #(
      .RAM_WIDTH(XLEN),
      .RAM_DEPTH(NUM_OF_PHYREGS),
      .NUM_OF_READ_PORT(NUM_OF_PHYREG_READ_PORT),
      .NUM_OF_WRITE_PORT(NUM_OF_PHYREG_WRITE_PORT)
  ) phyreg (
      .clock(clock),
      .reset(reset),
      .r_en(phyreg_r_en),
      .r_ram_idx(phyreg_r_ram_idx),
      .r_data(phyreg_r_data),
      .w_en(phyreg_w_en),
      .w_ram_idx(phyreg_w_ram_idx),
      .w_data(phyreg_w_data),
      .w_mask(phyreg_w_mask)
  );

  // -----------------------------------------------------
  // op_in_prev
  // -----------------------------------------------------
  vuop_front_t op_in_ari_prev[NUM_OF_ARI_ISSUE];
  vuop_front_t op_in_ld_prev[NUM_OF_LD_ISSUE];
  vuop_front_t op_in_st_amo_prev[NUM_OF_ST_AMO_ISSUE];
  vuop_front_t op_in_csr_prev[NUM_OF_CSR_ISSUE];


  // op_in_ari, op_in_ld, op_in_csr
  // => phyreg_r_en, phyreg_r_ram_idx
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_ARI_ISSUE; i++) begin
      phyreg_r_en[i*2] = 1;
      phyreg_r_ram_idx[i*2] = op_in_ari[i].rs1;
      phyreg_r_en[i*2+1] = 1;
      phyreg_r_ram_idx[i*2+1] = op_in_ari[i].rs2;
    end
    for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+i*2] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+i*2] = op_in_ld[i].rs1;
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+i*2+1] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+i*2+1] = op_in_ld[i].rs2;
    end
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2] = op_in_st_amo[i].rs1;
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2+1] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2+1] = op_in_st_amo[i].rs2;
    end
    for (int unsigned i = 0; i < NUM_OF_CSR_ISSUE; i++) begin
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2] = op_in_csr[i].rs1;
      phyreg_r_en[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2+1] = 1;
      phyreg_r_ram_idx[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2+1] = op_in_csr[i].rs2;
    end
  end

  // phyreg_r_data
  // => op_out
  always_comb begin
    // => op_out_ari
    for (int unsigned i = 0; i < NUM_OF_ARI_ISSUE; i++) begin
      op_out_ari[i] = '{
          valid: op_in_ari_prev[i].valid,
          opcode: op_in_ari_prev[i].opcode,
          op_addr: op_in_ari_prev[i].op_addr,
          rs1_exist: op_in_ari_prev[i].rs1_exist,
          rs2_exist: op_in_ari_prev[i].rs2_exist,
          rd_exist: op_in_ari_prev[i].rd_exist,
          rs1: op_in_ari_prev[i].rs1,
          rs2: op_in_ari_prev[i].rs2,
          rd: op_in_ari_prev[i].rd,
          rs1_val: phyreg_r_data[i*2],
          rs2_val: phyreg_r_data[i*2+1],
          imm: op_in_ari_prev[i].imm,
          al_idx: op_in_ari_prev[i].al_idx,
          actual_taken: 0,
          actual_taken_addr: 0
      };
    end
    // => op_out_ld
    for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
      op_out_ld[i] = '{
          valid: op_in_ld_prev[i].valid,
          opcode: op_in_ld_prev[i].opcode,
          op_addr: op_in_ld_prev[i].op_addr,
          rs1_exist: op_in_ld_prev[i].rs1_exist,
          rs2_exist: op_in_ld_prev[i].rs2_exist,
          rd_exist: op_in_ld_prev[i].rd_exist,
          rs1: op_in_ld_prev[i].rs1,
          rs2: op_in_ld_prev[i].rs2,
          rd: op_in_ld_prev[i].rd,
          rs1_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+i*2],
          rs2_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+i*2+1],
          imm: op_in_ld_prev[i].imm,
          al_idx: op_in_ld_prev[i].al_idx,
          actual_taken: 0,
          actual_taken_addr: 0
      };
    end
    // => op_st_amo
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      op_out_st_amo[i] = '{
          valid: op_in_st_amo_prev[i].valid,
          opcode: op_in_st_amo_prev[i].opcode,
          op_addr: op_in_st_amo_prev[i].op_addr,
          rs1_exist: op_in_st_amo_prev[i].rs1_exist,
          rs2_exist: op_in_st_amo_prev[i].rs2_exist,
          rd_exist: op_in_st_amo_prev[i].rd_exist,
          rs1: op_in_st_amo_prev[i].rs1,
          rs2: op_in_st_amo_prev[i].rs2,
          rd: op_in_st_amo_prev[i].rd,
          rs1_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2],
          rs2_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+i*2+1],
          imm: op_in_st_amo_prev[i].imm,
          al_idx: op_in_st_amo_prev[i].al_idx,
          actual_taken: 0,
          actual_taken_addr: 0
      };
    end

    // => op_out_csr
    for (int unsigned i = 0; i < NUM_OF_CSR_ISSUE; i++) begin
      op_out_csr[i] = '{
          valid: op_in_csr_prev[i].valid,
          opcode: op_in_csr_prev[i].opcode,
          op_addr: op_in_csr_prev[i].op_addr,
          rs1_exist: op_in_csr_prev[i].rs1_exist,
          rs2_exist: op_in_csr_prev[i].rs2_exist,
          rd_exist: op_in_csr_prev[i].rd_exist,
          rs1: op_in_csr_prev[i].rs1,
          rs2: op_in_csr_prev[i].rs2,
          rd: op_in_csr_prev[i].rd,
          rs1_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2],
          rs2_val: phyreg_r_data[NUM_OF_ARI_ISSUE*2+NUM_OF_LD_ISSUE*2+NUM_OF_ST_AMO_ISSUE*2+i*2+1],
          imm: op_in_csr_prev[i].imm,
          al_idx: op_in_csr_prev[i].al_idx,
          actual_taken: 0,
          actual_taken_addr: 0
      };
    end
  end

  // -------------------------------------------------
  // feedback
  // -------------------------------------------------
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
      if (op_feedback[i].valid && op_feedback[i].rd != 0) begin
        phyreg_w_en[i] = 1;
        phyreg_w_ram_idx[i] = op_feedback[i].rd;
        phyreg_w_data[i] = op_feedback[i].rd_val;
      end else begin
        phyreg_w_en[i] = 0;
        phyreg_w_ram_idx[i] = 0;
        phyreg_w_data[i] = 0;
      end
    end
  end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin

      // stall
      is_ldst_pending <= 0;
      op_in_ld_pending <= '{default: 0};
      op_in_st_amo_pending <= '{default: 0};

      // _prevのリセット
      op_in_ari_prev <= '{default: 0};
      op_in_ld_prev <= '{default: 0};
      op_in_st_amo_prev <= '{default: 0};
      op_in_csr_prev <= '{default: 0};
    end else if (flush_in) begin
      // stall用
      is_ldst_pending <= 0;
      op_in_ld_pending <= '{default: 0};
      op_in_st_amo_pending <= '{default: 0};
      // レジスタはflushでも削除しない

      //
      op_in_ari_prev <= '{default: 0};
      op_in_ld_prev <= '{default: 0};
      op_in_st_amo_prev <= '{default: 0};
      op_in_csr_prev <= '{default: 0};
    end else begin
      // stall用.
      is_ldst_pending <= is_ldst_pending_next;
      op_in_ld_pending <= op_in_ld_pending_next;
      op_in_st_amo_pending <= op_in_st_amo_pending_next;


      //
      op_in_ari_prev <= op_in_ari;
      op_in_ld_prev <= op_in_ld;
      op_in_st_amo_prev <= op_in_st_amo;
      op_in_csr_prev <= op_in_csr;
    end
  end


endmodule
