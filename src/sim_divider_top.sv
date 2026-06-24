`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"

module sim_divider_top
  import COMMON_PARAMS::*;
  import HART_DEFS::*;
(
    input logic clock,
    input logic reset,
    input logic flush_in,

    // C++からの除算命令入力
    input logic            req_valid,
    input logic [     7:0] req_opcode,
    input logic [XLEN-1:0] req_rs1,
    input logic [XLEN-1:0] req_rs2,

    // Dividerの状態
    output logic stall_out,

    // 結果
    output logic            resp_valid,
    output logic [     7:0] resp_opcode,
    output logic [XLEN-1:0] resp_value
);

  vuop_back_t op_in;
  vuop_result_t op_out;

  always_comb begin
    // 検証で使用しないフィールドも含めて初期化
    op_in                   = '0;

    op_in.valid             = req_valid;
    op_in.opcode            = opcode_t'(req_opcode);

    op_in.op_addr           = '0;

    op_in.rs1_exist         = 1'b1;
    op_in.rs2_exist         = 1'b1;
    op_in.rd_exist          = 1'b1;

    op_in.rs1               = '0;
    op_in.rs2               = '0;
    op_in.rd                = '0;

    op_in.rs1_val           = req_rs1;
    op_in.rs2_val           = req_rs2;

    op_in.imm               = '0;
    op_in.al_idx            = '0;

    op_in.actual_taken      = 1'b0;
    op_in.actual_taken_addr = '0;
  end

  Divider divider (
      .clock    (clock),
      .reset    (reset),
      .flush_in (flush_in),
      .op_in    (op_in),
      .op_out   (op_out),
      .stall_out(stall_out)
  );

  assign resp_valid  = op_out.valid;
  assign resp_opcode = op_out.opcode;
  assign resp_value  = op_out.rd_val;

endmodule
