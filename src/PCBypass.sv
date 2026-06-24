`timescale 1ns / 1ps
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module PCBypass
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    input program_counter_t pc_in_cur[NUM_OF_FETCH],
    output program_counter_t pc_out[NUM_OF_FETCH],

    input  logic stall_in,
    output logic stall_out,
    input  logic flush_in
);
  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  program_counter_t pc_in[NUM_OF_FETCH];

  program_counter_t pc_in_pending[NUM_OF_FETCH];
  logic is_pending;
  program_counter_t pc_in_pending_next[NUM_OF_FETCH];
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    pc_in_pending_next = pc_in_pending;
    if (flush_in) begin
      pc_in = '{default: 0};
    end else if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      pc_in_pending_next = pc_in_cur;
      is_pending_next = 1;
      pc_in = '{default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      pc_in = '{default: 0};
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

  always_ff @(posedge clock) begin
    if (reset) begin
      pc_out <= '{default: 0};
      is_pending <= 0;
      pc_in_pending <= '{default: 0};
    end else if (flush_in) begin
      pc_out <= '{default: 0};
      is_pending <= 0;
      pc_in_pending <= '{default: 0};
    end else begin
      pc_out <= pc_in;
      is_pending <= is_pending_next;
      pc_in_pending <= pc_in_pending_next;
    end
  end
endmodule
