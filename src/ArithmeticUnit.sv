// 算術ユニット
// aluを束ねてflushに対応させているだけ.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module ArithmeticUnit
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    input  vuop_back_t   op_in [NUM_OF_ARI_ISSUE],
    output vuop_result_t op_out[NUM_OF_ARI_ISSUE],

    input logic flush_in
);


  vuop_result_t op_out_next[NUM_OF_ARI_ISSUE];


  genvar alu_idx;
  generate
    for (alu_idx = 0; alu_idx < NUM_OF_ARI_ISSUE; alu_idx++) begin : gen_alu
      ALU alu (
          .op_in (op_in[alu_idx]),
          .op_out(op_out_next[alu_idx])
      );
    end
  endgenerate

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      op_out <= '{default: 0};
    end else if (flush_in) begin
      op_out <= '{default: 0};
    end else begin
      op_out <= op_out_next;
    end
  end


endmodule
