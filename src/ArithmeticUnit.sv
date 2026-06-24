`timescale 1ns / 1ps
// 算術ユニット
// 乗算ユニット,除算ユニット,その他の演算処理の3つに分けている。

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module ArithmeticUnit
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    input  vuop_back_t   op_in_ari [NUM_OF_ARI_ISSUE],
    output vuop_result_t op_out_ari[NUM_OF_ARI_ISSUE],

    input  vuop_back_t   op_in_div [NUM_OF_DIV_ISSUE],
    output vuop_result_t op_out_div[NUM_OF_DIV_ISSUE],

    output stall_out_div,

    input logic flush_in
);




  genvar balu_idx;
  generate
    for (balu_idx = 0; balu_idx < NUM_OF_ARI_ISSUE; balu_idx++) begin : gen_alu
      ALU basic_alu (
          .clock(clock),
          .reset(reset),
          .flush_in(flush_in),
          .op_in(op_in_ari[balu_idx]),
          .op_out(op_out_ari[balu_idx])
      );
    end
  endgenerate


  genvar dalu_idx;
  generate
    for (dalu_idx = 0; dalu_idx < NUM_OF_DIV_ISSUE; dalu_idx++) begin : gen_dalu
      Divider divider (
          .clock(clock),
          .reset(reset),
          .flush_in(flush_in),
          .op_in(op_in_div[dalu_idx]),
          .op_out(op_out_div[dalu_idx]),
          .stall_out(stall_out_div)
      );
    end
  endgenerate



endmodule
