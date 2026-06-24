`timescale 1ns / 1ps
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module pcgen
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    output program_counter_t pc_out[NUM_OF_FETCH],

    // 分岐予測失敗などで,他のモジュールにflushを指示すると同時に,stage1では新しいpcを流し込む.
    input addr_with_valid_t flush_in,

    // stall_inなら新しいpcを発行しない.
    input logic stall_in
);

  localparam int unsigned FETCH_SIZE = 4 * NUM_OF_FETCH;
  localparam int unsigned FETCH_SIZE_WIDTH = $clog2(FETCH_SIZE);

  // ---------------------------------------------------------
  // stall,flush 処理
  // ---------------------------------------------------------
  // stallとflushのどちらを優先するかは面倒な問題.
  // これはpc_genが全ての中で唯一flushでvalidな命令を出すことによる.
  // ほかのモジュールに関しては,flushされれば基本的に出力もinvalidになるので問題ない(=実質的にstallの要件を満たす)が,
  // pc_genだけは異なる.
  // そのため,stallかつflushの場合,flushで来た新しい値にしつつ,stallでinvalidにする.

  program_counter_t pc_out_next[NUM_OF_FETCH];

  // 各サイクルでの先頭のvaddrと,各サイクルごとのfetch_id
  logic [VADDR_WIDTH-1:0] first_instr_vaddr;
  int unsigned fetch_id;
  logic [VADDR_WIDTH-1:0] first_instr_vaddr_next;
  int unsigned fetch_id_next;

  // always_comb begin
  //   if (flush_in.valid && flush_in.addr == 0) begin
  //     $display("[LOG][pcgen.sv] 0 flush");
  //   end
  // end

  always_comb begin

    automatic logic [VADDR_WIDTH-1:0] instr_vaddr = 0;
    automatic logic [VADDR_WIDTH-1:0] instr_vaddr_fetch_aligned = 0;

    // pc_out[NUM_OF_FETCH]について,pc_out[i]は
    // 
    if (flush_in.valid && stall_in) begin
      // flush_inが入ってきたが,stallの場合は何もしない.
      pc_out_next = '{default: 0};

      // _nextの作成
      first_instr_vaddr_next = flush_in.addr;
      fetch_id_next = fetch_id + 1;
    end else if (flush_in.valid) begin
      // flush_inが入ってきた場合.
      instr_vaddr = flush_in.addr;

      // すべての出力はNUM_OF_FETCH*4byte単位でalignされている.これはNUM_OF_FETCHが2だから32*2 bitだからである.
      instr_vaddr_fetch_aligned = {
        flush_in.addr[VADDR_WIDTH-1:FETCH_SIZE_WIDTH], {FETCH_SIZE_WIDTH{1'b0}}
      };

      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (instr_vaddr[FETCH_SIZE_WIDTH-1:0] > FETCH_SIZE_WIDTH'(i) * 4) begin
          pc_out_next[i] = '{
              valid: 0,
              vaddr: instr_vaddr_fetch_aligned + i * 4,
              fetch_id: fetch_id
          };
        end else begin
          pc_out_next[i] = '{
              valid: 1,
              vaddr: instr_vaddr_fetch_aligned + i * 4,
              fetch_id: fetch_id
          };
        end
      end

      // _nextの作成
      first_instr_vaddr_next = instr_vaddr_fetch_aligned + 4 * NUM_OF_FETCH;
      fetch_id_next = fetch_id + 1;
    end else if (stall_in) begin
      // 何もしない.
      pc_out_next = '{default: 0};

      // _nextの作成
      first_instr_vaddr_next = first_instr_vaddr;
      fetch_id_next = fetch_id + 1;
    end else begin
      // 普通に出力する場合.
      instr_vaddr = first_instr_vaddr;
      instr_vaddr_fetch_aligned = {
        first_instr_vaddr[VADDR_WIDTH-1:FETCH_SIZE_WIDTH], {FETCH_SIZE_WIDTH {1'b0}}
      };
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (instr_vaddr[FETCH_SIZE_WIDTH-1:0] > FETCH_SIZE_WIDTH'(i) * 4) begin
          pc_out_next[i] = '{
              valid: 0,
              vaddr: instr_vaddr_fetch_aligned + i * 4,
              fetch_id: fetch_id
          };
        end else begin
          pc_out_next[i] = '{
              valid: 1,
              vaddr: instr_vaddr_fetch_aligned + i * 4,
              fetch_id: fetch_id
          };
        end
      end

      // _nextの作成
      first_instr_vaddr_next = instr_vaddr_fetch_aligned + 4 * NUM_OF_FETCH;
      fetch_id_next = fetch_id + 1;
    end
  end

  // int fp;
  // initial begin
  //   fp = $fopen("./log/pcgenlog.txt", "w");
  // end

  (*mark_debug="true"*) program_counter_t pc_out_debug[NUM_OF_FETCH];

  always_ff @(posedge clock) begin
    if (reset) begin

      // pcの出力
      pc_out <= '{default: 0};
      pc_out_debug <= '{default: 0};

      // vaddr及びfetch_id
      first_instr_vaddr <= 39'h8000_0000;
      fetch_id <= 0;
    end else begin
      pc_out <= pc_out_next;
      pc_out_debug <= pc_out_next;

      // 
      first_instr_vaddr <= first_instr_vaddr_next;
      fetch_id <= fetch_id_next;

`ifdef PCGENLOG_EN
      $fdisplay(fp, "valid:%b,  vaddr:%010h, firstfetch_id:%016h", pc_out.valid, pc_out.vaddr,
                pc_out.fetch_id);
`endif
    end

  end





endmodule
