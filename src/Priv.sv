// 特権モードの管理するだけ.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"

module Priv
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
(
    input logic clock,
    input logic reset,
    output privilege_level_e priv_rval,
    input priv_w_t priv_w
);
  privilege_level_e current_priv;

  assign priv_rval = current_priv;

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // 起動時は M_MODE
      current_priv <= M_MODE;
    end else begin
      if (priv_w.en) begin
        current_priv <= priv_w.val;
      end
    end
  end
endmodule
