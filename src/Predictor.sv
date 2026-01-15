`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

// 2レベル予測子
// 予想は組み合わせ回路,更新は順序回路

module Predictor
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
#(
) (
    input logic clock,
    input logic reset,

    input  logic [ VADDR_WIDTH-1:0] first_instr_addr_cur,
    output logic [NUM_OF_FETCH-1:0] pred_taken,

    // 結果のフィードバック
    input is_taken_feedback_to_pred_t feedback[NUM_OF_GRADUATE],

    input logic stall_in,
    input logic flush_in
);

  // ---------------------------------------------------
  // stall用
  // ---------------------------------------------------
  logic [VADDR_WIDTH-1:0] first_instr_addr;

  logic [VADDR_WIDTH-1:0] first_instr_addr_pending;
  logic is_pending;
  logic [VADDR_WIDTH-1:0] first_instr_addr_pending_next;
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    first_instr_addr_pending_next = first_instr_addr_pending;

    if (flush_in) begin
      first_instr_addr = 0;
    end else if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      first_instr_addr_pending_next = first_instr_addr_cur;
      is_pending_next = 1;
      first_instr_addr = 0;
    end else if (stall_in) begin
      // 継続でstallした場合.
      first_instr_addr = 0;
    end else if (is_pending) begin
      // stall終了時.
      first_instr_addr = first_instr_addr_pending;
      is_pending_next  = 0;
    end else begin
      // 通常時.
      first_instr_addr = first_instr_addr_cur;
    end
  end


  localparam int unsigned NUM_OF_BHT_ENTRIES = 1024;
  localparam int unsigned BHT_INDEX_WIDTH = $clog2(NUM_OF_BHT_ENTRIES);
  localparam int unsigned BHT_HISTORY_DEPTH = 4;
  localparam int unsigned PHT_INDEX_WIDTH = $clog2(NUM_OF_BHT_ENTRIES * (2 ** BHT_HISTORY_DEPTH));


  logic [VADDR_WIDTH-1:0] addr_in[NUM_OF_FETCH];


  // BHTはaddrの[2 +: BHT_INDEX_WIDTH]の10bitをインデックスとして過去4回(16通り)でそのaddrに対してtakenかnot_takenの履歴を持つ
  // BHTで得られたその16通りの履歴ごとに,addrの[2 +: BHT_INDEX_WIDTH]ごとのpred_counterが存在する.
  // PHTにtakenかnottakenかの履歴が2bitの飽和カウンタとして保存してある.
  // 0b11: Strong taken, 0b10: Weak taken, 0b01 Weak not taken, 0b00 Strong not taken
  logic [BHT_HISTORY_DEPTH-1:0] BHT[NUM_OF_BHT_ENTRIES];
  logic [1:0] PHT[NUM_OF_BHT_ENTRIES*(2**BHT_HISTORY_DEPTH)];

  logic [NUM_OF_FETCH-1:0] pred_taken_next;

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      addr_in[i] = VADDR_WIDTH'(first_instr_addr + 4 * i);
    end

    for (int i = 0; i < NUM_OF_FETCH; i++) begin
      if (PHT[{addr_in[i][2 +: BHT_INDEX_WIDTH], BHT[addr_in[i][2 +: BHT_INDEX_WIDTH]]}] == 2'b11 || PHT[{addr_in[i][2 +: BHT_INDEX_WIDTH], BHT[addr_in[i][2 +: BHT_INDEX_WIDTH]]}] == 2'b10) begin
        pred_taken_next[i] = 1;
      end else begin
        pred_taken_next[i] = 0;
      end
    end
  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      BHT <= '{default: 0};
      PHT <= '{default: 0};
    end else begin
      // フィードバックからPHT,BHTの更新
      for (int i = 0; i < NUM_OF_GRADUATE; i++) begin
        logic [PHT_INDEX_WIDTH-1:0] pht_index = {
          feedback[i].op_addr[2+:BHT_INDEX_WIDTH], BHT[feedback[i].op_addr[2+:BHT_INDEX_WIDTH]]
        };
        if (feedback[i].valid) begin
          if (feedback[i].taken && PHT[{feedback[i].op_addr[2 +: BHT_INDEX_WIDTH], BHT[feedback[i].op_addr[2 +: BHT_INDEX_WIDTH]]}] != 2'b11) begin
            // takenの場合
            PHT[pht_index] <= PHT[pht_index] + 2'b01;
          end else if (!feedback[i].taken && 
            PHT[{feedback[i].op_addr[2 +: BHT_INDEX_WIDTH], BHT[feedback[i].op_addr[2 +: BHT_INDEX_WIDTH]]}] != 2'b00) begin
            // not takenの場合
            PHT[pht_index] <= PHT[pht_index] - 2'b01;
          end
          // BHTの更新
          BHT[feedback[i].op_addr[2+:BHT_INDEX_WIDTH]] <= {
            BHT[feedback[i].op_addr[2+:BHT_INDEX_WIDTH]][2:0], feedback[i].taken
          };
        end
      end

      // 結果の出力.
      pred_taken <= pred_taken_next;
    end
  end

endmodule
