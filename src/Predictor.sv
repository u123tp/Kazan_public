`timescale 1ns / 1ps
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

// 2レベル予測子
// 本体はbramで作って,同時にNUM_OF_FETCHだけreadできるようにマルチバンク化する.
// 書き込みはcommitのときに,前のop_addrと連続かどうかを調べて,連続であればコミット,
// そうでなければ次まで待つという処理を入れる.こうすることで,
//
// 
// 38                     11          4 3         2 1 0
// -----------------------------------------------------
// |                      |  phbt_idx  | bank_idx  |   |
// -----------------------------------------------------
//
// validかどうかの管理はここでなく,pc_bypassの方で行うので,とりあえず全部instrがvalidとする. 
// bramとかあるし,毎サイクル読み込みは電力食って良くないのかもしれない。後で直す。

module Predictor
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
#(
) (
    input logic clock,
    input logic reset,

    // input  logic [ VADDR_WIDTH-1:0] pc_in_cur,

    input program_counter_t pc_in_cur[NUM_OF_FETCH],

    output logic [NUM_OF_FETCH-1:0] pred_taken,

    // 結果のフィードバック
    input is_taken_feedback_to_pred_t feedback[NUM_OF_GRADUATE],

    input logic stall_in,
    input logic flush_in
);

  // ---------------------------------------------------
  // stall用
  // ---------------------------------------------------
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
      is_pending_next = 0;
      pc_in_pending_next = '{default: 0};
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



  // パラメータ.
  localparam int unsigned NUM_OF_BANK = NUM_OF_FETCH;
  localparam int unsigned BANK_IDX_WIDTH = $clog2(NUM_OF_BANK);
  localparam int unsigned BANK_IDX_LSB = 2;
  localparam int unsigned BANK_IDX_MSB = BANK_IDX_LSB + BANK_IDX_WIDTH - 1;

  // 各バンクごとのサイズ.
  localparam int unsigned PBHT_SIZE = 512;
  localparam int unsigned PBHT_IDX_WIDTH = $clog2(PBHT_SIZE);
  localparam int unsigned PBHT_IDX_LSB = BANK_IDX_MSB + 1;
  localparam int unsigned PBHT_IDX_MSB = PBHT_IDX_LSB + PBHT_IDX_WIDTH - 1;

  // 過去何回を記録するか.
  localparam int unsigned HISTORY_DEPTH = 2;
  localparam int unsigned NUM_OF_HISTORY_PATTERNS = 1 << HISTORY_DEPTH;

  // ------------------------------------------------------------------------------------------------
  // pbht
  // ------------------------------------------------------------------------------------------------
  // pattern & branch history table
  // 各idx(addr[PBHT_IDX_MSB:PBHT_IDX_LSB])ごとにそのアドレスに対する現在の過去2回分のカウンタと,
  // そのアドレスでの過去2回分のカウンタのとり方(4通り)に対してそれぞれ次がtakenかの予想を持つ.
  // 要するに,1サイクルで済ませられるようにbhtとphtを合体した.
  // pbht[0]は予測用,pbht[1]はfeedback用.
  typedef struct packed {
    logic [HISTORY_DEPTH-1:0] hist;
    logic [NUM_OF_HISTORY_PATTERNS-1:0] pred;
  } pbht_t;
  // (* ram_style="block" *) pbht_t pbht[2][NUM_OF_BANK][PBHT_SIZE];
  logic pbht_r_en[2][NUM_OF_BANK];
  logic [PBHT_IDX_WIDTH-1:0] pbht_r_idx[2][NUM_OF_BANK];
  logic [$bits(pbht_t)-1:0] pbht_r_data_bit[2][NUM_OF_BANK];

  logic pbht_w_en[NUM_OF_BANK];
  logic [PBHT_IDX_WIDTH-1:0] pbht_w_idx[NUM_OF_BANK];
  logic [$bits(pbht_t)-1:0] pbht_w_data_bit[NUM_OF_BANK];

  pbht_t pbht_r_data_strc[2][NUM_OF_BANK];
  pbht_t pbht_w_data_strc[NUM_OF_BANK];
  always_comb begin
    for (int unsigned i = 0; i < 2; i++) begin
      for (int unsigned j = 0; j < NUM_OF_BANK; j++) begin
        pbht_r_data_strc[i][j] = pbht_r_data_bit[i][j];
      end
    end
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      pbht_w_data_bit[i] = pbht_w_data_strc[i];
    end
  end

  genvar read_port_gen_idx;
  genvar pbht_gen_idx;
  generate
    for (read_port_gen_idx = 0; read_port_gen_idx < 2; read_port_gen_idx++) begin
      for (pbht_gen_idx = 0; pbht_gen_idx < NUM_OF_BANK; pbht_gen_idx++) begin
        ram_1r1w_bram #(
            .RAM_WIDTH($bits(pbht_t)),
            .RAM_DEPTH(PBHT_SIZE)
        ) pbht_ram (
            .clock(clock),
            .r_en(pbht_r_en[read_port_gen_idx][pbht_gen_idx]),
            .r_ram_idx(pbht_r_idx[read_port_gen_idx][pbht_gen_idx]),
            .r_data(pbht_r_data_bit[read_port_gen_idx][pbht_gen_idx]),
            .w_en(pbht_w_en[pbht_gen_idx]),
            .w_ram_idx(pbht_w_idx[pbht_gen_idx]),
            .w_data(pbht_w_data_bit[pbht_gen_idx])
        );
      end
    end
  endgenerate



  // --------------------------------------------------------------------
  // prediction
  // --------------------------------------------------------------------

  // addrをpbhtへのリクエストに使いやすい形に変換.
  // pbhtにリクエストするときのpbht_idx
  // logic [PBHT_IDX_WIDTH-1:0] prediction_pbht_idx[NUM_OF_BANK];
  // bankがidxになるように並び替えるので,出力時に逆変換できるように逆関数を作っておく.
  logic [BANK_IDX_WIDTH-1:0] prediction_bank_idx_to_instr_idx[NUM_OF_BANK];
  logic [BANK_IDX_WIDTH-1:0] prediction_bank_idx_to_instr_idx_prev[NUM_OF_BANK];
  // always_comb begin
  //   prediction_pbht_idx = '{default: 0};
  //   prediction_bank_idx_to_instr_idx = '{default: 0};
  //   for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //     logic [VADDR_WIDTH-1:0] pred_vaddr = VADDR_WIDTH'(pc_in + 4 * i);
  //     prediction_pbht_idx[pred_vaddr[BANK_IDX_MSB:BANK_IDX_LSB]] = pred_vaddr[PBHT_IDX_MSB:PBHT_IDX_LSB];
  //     prediction_bank_idx_to_instr_idx[pred_vaddr[BANK_IDX_MSB:BANK_IDX_LSB]] = BANK_IDX_WIDTH'(i);
  //   end
  // end

  always_comb begin
    // 基本的には毎サイクルすべて読み込む. 
    // invalidかの処理はTop.svで行う.おそらくここでもvalidのビットを持ってきて毎回判別するほうが消費電力的にはいいのかもしれない.
    pbht_r_en[0] = '{default: 1};
    pbht_r_idx[0] = '{default: 0};
    prediction_bank_idx_to_instr_idx = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      automatic logic [VADDR_WIDTH-1:0] op_vaddr = pc_in[i].vaddr;
      pbht_r_idx[0][op_vaddr[BANK_IDX_MSB:BANK_IDX_LSB]] = op_vaddr[PBHT_IDX_MSB:PBHT_IDX_LSB];
      prediction_bank_idx_to_instr_idx[op_vaddr[BANK_IDX_MSB:BANK_IDX_LSB]] = BANK_IDX_WIDTH'(i);
    end
  end

  // pbhtから読み出した内容を結果(pred_taken)に振り分ける. 
  always_comb begin
    pred_taken = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      pred_taken[prediction_bank_idx_to_instr_idx_prev[i]] = pbht_r_data_strc[0][i].pred[pbht_r_data_strc[0][i].hist];
    end
  end


  // 読み出した内容から出力を作る.
  // always_comb begin
  //   pred_taken = '{default: 0};
  //   for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
  //     pred_taken[prediction_bank_idx_to_instr_idx_prev[i]] = prediction_pbht_prev[i].pred[prediction_pbht_prev[i].hist];
  //   end
  // end


  // -----------------------------------------------------------------------
  // feedback 
  // -----------------------------------------------------------------------
  // pbhtのアップデート内容.
  // logic update_pbht_valid[NUM_OF_BANK];
  // logic [PBHT_IDX_WIDTH-1:0] update_pbht_idx[NUM_OF_BANK];
  // pbht_t update_pbht[NUM_OF_BANK];



  // 各バンクごとに一つのfeedbackにする. 
  // かぶったら捨てる.
  typedef struct packed {
    logic valid;
    logic [PBHT_IDX_WIDTH-1:0] pbht_idx;
    logic taken;
  } banked_feedback_t;
  banked_feedback_t banked_feedback[NUM_OF_BANK];
  banked_feedback_t banked_feedback_prev[NUM_OF_BANK];

  // banked_feedback_prevに対応する,pbhtから読み出した内容.
  // pbht_t feedback_pbht_prev[NUM_OF_BANK];



  // ---------------------------------------------------------------
  // feedbackの内容で該当箇所を読み出し
  // ---------------------------------------------------------------
  always_comb begin
    banked_feedback = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      if (feedback[i].valid) begin
        banked_feedback[feedback[i].op_addr[BANK_IDX_MSB:BANK_IDX_LSB]] = '{
            valid: 1,
            pbht_idx: feedback[i].op_addr[PBHT_IDX_MSB:PBHT_IDX_LSB],
            taken: feedback[i].taken
        };
      end
    end

    // 該当箇所の読み出し
    for (int unsigned bank_idx = 0; bank_idx < NUM_OF_BANK; bank_idx++) begin
      if (banked_feedback[bank_idx].valid) begin
        pbht_r_en[1][bank_idx]  = 1;
        pbht_r_idx[1][bank_idx] = banked_feedback[bank_idx].pbht_idx;
      end else begin
        pbht_r_en[1][bank_idx]  = 0;
        pbht_r_idx[1][bank_idx] = 0;
      end
    end
  end


  // ------------------------------------------------------------------------
  // feedbackの内容と,pbhtでそのfeedbackに対応する箇所をマージして,新たなデータをpbhtに書き込む
  // -----------------------------------------------------------------------
  always_comb begin
    automatic logic [HISTORY_DEPTH-1:0] old_hist = 0;
    automatic logic [HISTORY_DEPTH-1:0] new_hist = 0;
    automatic logic [NUM_OF_HISTORY_PATTERNS-1:0] old_pred = 0;
    automatic logic [NUM_OF_HISTORY_PATTERNS-1:0] new_pred = 0;
    pbht_w_en = '{default: 0};
    pbht_w_idx = '{default: 0};
    pbht_w_data_strc = '{default: 0};
    // update_pbht_valid = '{default: 0};
    // update_pbht_idx = '{default: 0};
    // update_pbht = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      if (banked_feedback_prev[i].valid) begin
        // 新しい履歴と新しい分岐予測(new_hist,new_pred)の作成
        old_hist = pbht_r_data_strc[1][i].hist;
        new_hist = {banked_feedback_prev[i].taken, pbht_r_data_strc[1][i].hist[HISTORY_DEPTH-1:1]};
        new_pred = pbht_r_data_strc[1][i].pred;
        new_pred[old_hist] = banked_feedback_prev[i].taken;
        pbht_w_en[i] = 1;
        pbht_w_idx[i] = banked_feedback_prev[i].pbht_idx;
        pbht_w_data_strc[i] = '{hist: new_hist, pred: new_pred};
        // update_pbht,update_pbht_validの作成.
        // update_pbht_valid[i] = 1;
        // update_pbht_idx[i] = banked_feedback_prev[i].pbht_idx;
        // update_pbht[i] = feedback_pbht_prev[i];
        // update_pbht[i].hist = new_hist;
        // update_pbht[i].pred[old_hist] = banked_feedback_prev[i].taken;
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      // pbht <= '{default: '{default: '{default: 0}}};
      // pending
      is_pending <= 0;
      pc_in_pending <= '{default: 0};

      // prediction
      prediction_bank_idx_to_instr_idx_prev <= '{default: 0};

      // feedback
      banked_feedback_prev <= '{default: 0};

      // pbht周りの入出力.
      // feedback_pbht_prev <= '{default: 0};
      // prediction_pbht_prev <= '{default: 0};
    end else begin
      // pending
      is_pending <= is_pending_next;
      pc_in_pending <= pc_in_pending_next;

      // prediction
      prediction_bank_idx_to_instr_idx_prev <= prediction_bank_idx_to_instr_idx;

      // banked_feedback
      banked_feedback_prev <= banked_feedback;

      // pbht周りの入出力.

      // feedbackで上書きする内容を読み出す.
      // for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      //   if (banked_feedback[i].valid) begin
      //     feedback_pbht_prev[i] <= pbht[1][i][banked_feedback[i].pbht_idx];
      //   end else begin
      //     feedback_pbht_prev[i] <= '{default: 0};
      //   end
      // end

      // feedbackでupdate_pbhtで上書き.
      // for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      //   if (update_pbht_valid[i]) begin
      //     for (int unsigned j = 0; j < 2; j++) begin
      //       pbht[j][i][update_pbht_idx[i]] <= update_pbht[i];
      //     end
      //   end
      // end

      // op_inのpredictionを取得
      // for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      //   prediction_pbht_prev[i] <= pbht[0][i][prediction_pbht_idx[i]];
      // end

    end
  end



endmodule
