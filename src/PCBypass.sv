`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module PCBypass
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    input  pc_t pc_in_cur,
    output pc_t pc_out,

    input  logic stall_in,
    output logic stall_out,
    input  logic flush_in
);
  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  pc_t pc_in;

  pc_t pc_in_pending;
  logic is_pending;
  pc_t pc_in_pending_next;
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    pc_in_pending_next = pc_in_pending;
    if (flush_in) begin
      pc_in = '{valid: 0, default: 0};
    end else if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      pc_in_pending_next = pc_in_cur;
      is_pending_next = 1;
      pc_in = '{valid: 0, default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      pc_in = '{valid: 0, default: 0};
    end else if (is_pending) begin
      // stall終了時.
      pc_in = pc_in_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      pc_in = pc_in_cur;
    end
  end

  always_comb begin
    // キューなどが無いので透過的
    stall_out = stall_in;
  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      pc_out <= '{valid: 0, default: 0};
      is_pending <= 0;
      pc_in_pending <= 0;
    end else if (flush_in) begin
      pc_out <= '{valid: 0, default: 0};
      is_pending <= 0;
      pc_in_pending <= 0;
    end else begin
      pc_out <= pc_in;
      is_pending <= is_pending_next;
      pc_in_pending <= pc_in_pending_next;
    end
  end
endmodule
