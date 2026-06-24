`timescale 1ns / 1ps
// バンク化されたram
// r_idxは必ずそれぞれ別のバンクを指す必要がある.
// 例えば,4bankなら,r_idx[0]は下二桁が00,r_idx[1]は下二桁が01,r_idx[2]は下二桁が10,r_idx[3]は下二桁が11,

module BankedRamLUT #(
    parameter int unsigned NUM_OF_BANKS = 4,
    parameter int unsigned NUM_OF_READ = NUM_OF_BANKS,
    parameter int unsigned NUM_OF_WRITE = NUM_OF_READ,
    parameter int unsigned RAM_WIDTH = 64,
    parameter int unsigned NUM_OF_SETS = 64,
    parameter int unsigned PRE_ALLOCATE_BUF_SIZE = NUM_OF_BANKS,
    parameter int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SETS)
) (
    input logic clock,
    input logic reset,

    input logic r_en[NUM_OF_READ],
    input logic [SET_IDX_WIDTH-1:0] r_idx[NUM_OF_READ],
    output logic [RAM_WIDTH-1:0] r_data[NUM_OF_READ],

    input logic w_en[NUM_OF_WRITE],
    input logic [SET_IDX_WIDTH-1:0] w_idx[NUM_OF_WRITE],
    input logic [RAM_WIDTH-1:0] w_data[NUM_OF_WRITE],

    // 次のサイクルで書き込みを受け付けない.
    output logic stall_write
);


  // パラメータ
  localparam int unsigned BANK_IDX_WIDTH = $clog2(NUM_OF_BANKS);

  localparam int unsigned SETS_PER_BANK = NUM_OF_SETS / NUM_OF_BANKS;
  localparam int unsigned SETS_PER_BANK_IDX_WIDTH = $clog2(SETS_PER_BANK);

  localparam int unsigned PRE_ALLOCATE_BUF_IDX_WIDTH = $clog2(PRE_ALLOCATE_BUF_SIZE);
  localparam int unsigned PRE_ALLOCATE_BUF_COUNT_WIDTH = PRE_ALLOCATE_BUF_IDX_WIDTH + 1;

  // パラメータ確認
  always_comb begin
    // 一度にNUM_OF_BANKSの数だけ書き込みが最大であるので,PRE_ALLOCATE_BUF_SIZEは実際に書き込む1つ分引いたもの以上である必要がある.
    assert (PRE_ALLOCATE_BUF_SIZE > NUM_OF_BANKS - 1)
    else $fatal(1, "PRE_ALLOCATE_BUF_SIZE is too small");
  end

  (* ram_style = "distributed" *) logic [RAM_WIDTH-1:0] ram[NUM_OF_BANKS][SETS_PER_BANK];

  // バンクに入れられなかったときに入れるバッファ.
  // 今は書き込みの数とPRE_ALLOCATE_BUFの数がほとんど変わらないから全部コピーして毎サイクル更新する.
  logic [RAM_WIDTH-1:0] pre_allocate_buf_data[PRE_ALLOCATE_BUF_SIZE];
  logic [RAM_WIDTH-1:0] pre_allocate_buf_data_next[PRE_ALLOCATE_BUF_SIZE];
  logic [SET_IDX_WIDTH-1:0] pre_allocate_buf_idx[PRE_ALLOCATE_BUF_SIZE];
  logic [SET_IDX_WIDTH-1:0] pre_allocate_buf_idx_next[PRE_ALLOCATE_BUF_SIZE];
  logic [PRE_ALLOCATE_BUF_IDX_WIDTH-1:0] pre_allocate_buf_rp;
  logic [PRE_ALLOCATE_BUF_IDX_WIDTH-1:0] pre_allocate_buf_wp;
  logic [PRE_ALLOCATE_BUF_IDX_WIDTH:0] noei_pre_allocate_buf;
  logic [PRE_ALLOCATE_BUF_IDX_WIDTH:0] noei_pre_allocate_buf_next;

  // w_idx,w_dataを入れ替えて次に書き込みやすい形にする
  typedef struct packed {
    logic valid;
    logic [SETS_PER_BANK_IDX_WIDTH-1:0] idx;
    logic [RAM_WIDTH-1:0] data;
  } data_to_write_t;
  data_to_write_t data_to_write[NUM_OF_BANKS];

  int unsigned num_of_new_pre_allocate_buf_entries;
  int unsigned num_of_deleted_pre_allocate_buf_entries;

  always_comb begin
    num_of_new_pre_allocate_buf_entries = 0;
    num_of_deleted_pre_allocate_buf_entries = 0;
    pre_allocate_buf_data_next = pre_allocate_buf_data;
    pre_allocate_buf_idx_next = pre_allocate_buf_idx;
    data_to_write = '{default: 0};

    // 最大でもpre_allocate_bufからの書き込みはNUM_OF_BANK個
    for (int unsigned i = 0; i < NUM_OF_BANKS; i++) begin
      if (i < noei_pre_allocate_buf) begin
        if(!data_to_write[pre_allocate_buf_idx[pre_allocate_buf_rp+PRE_ALLOCATE_BUF_IDX_WIDTH'(i)][BANK_IDX_WIDTH-1:0]].valid)begin
          // data_to_writeがまだ空なら書き込む
          data_to_write[pre_allocate_buf_idx[pre_allocate_buf_rp+PRE_ALLOCATE_BUF_IDX_WIDTH'(i)][BANK_IDX_WIDTH-1:0]] = '{
              valid: 1,
              idx:
              pre_allocate_buf_idx[
              pre_allocate_buf_rp+PRE_ALLOCATE_BUF_IDX_WIDTH'(i)
              ][
              BANK_IDX_WIDTH
              +:
              SETS_PER_BANK_IDX_WIDTH
              ],
              data: pre_allocate_buf_data[pre_allocate_buf_rp+PRE_ALLOCATE_BUF_IDX_WIDTH'(i)]
          };
          num_of_deleted_pre_allocate_buf_entries++;
        end else begin
          // fifoなので,書き込めないものが見つかったらそこでpre_allocate_bufからの書き込みは中断する.
          break;
        end
      end
    end

    for (int unsigned i = 0; i < NUM_OF_WRITE; i++) begin
      if (w_en[i]) begin
        if (!data_to_write[w_idx[i][BANK_IDX_WIDTH-1:0]].valid) begin
          // data_to_writeに直接追加.
          data_to_write[w_idx[i][BANK_IDX_WIDTH-1:0]] = '{
              valid: 1,
              idx: w_idx[i][BANK_IDX_WIDTH+:SETS_PER_BANK_IDX_WIDTH],
              data: w_data[i]
          };
        end else begin
          // すでに対応するポートに書き込まれているので,一時的にpre_allocate_bufに退避
          pre_allocate_buf_idx_next[PRE_ALLOCATE_BUF_IDX_WIDTH'(32'(pre_allocate_buf_wp)+num_of_new_pre_allocate_buf_entries)] = w_idx[i];
          pre_allocate_buf_data_next[PRE_ALLOCATE_BUF_IDX_WIDTH'(32'(pre_allocate_buf_wp)+num_of_new_pre_allocate_buf_entries)] = w_data[i];
          num_of_new_pre_allocate_buf_entries++;
        end
      end
    end

    noei_pre_allocate_buf_next = PRE_ALLOCATE_BUF_COUNT_WIDTH'(32'(noei_pre_allocate_buf) + num_of_new_pre_allocate_buf_entries - num_of_deleted_pre_allocate_buf_entries);
    // 次のサイクルで書き込みリクエストが来ないように
    stall_write = NUM_OF_WRITE > PRE_ALLOCATE_BUF_SIZE - 32'(noei_pre_allocate_buf_next);

  end



  always_ff @(posedge clock) begin
    if (reset) begin
      pre_allocate_buf_rp   <= 0;
      pre_allocate_buf_wp   <= 0;
      noei_pre_allocate_buf <= 0;

      pre_allocate_buf_data <= '{default: 0};
      pre_allocate_buf_idx  <= '{default: 0};

    end else begin
      pre_allocate_buf_rp <= PRE_ALLOCATE_BUF_IDX_WIDTH'(32'(pre_allocate_buf_rp)+num_of_deleted_pre_allocate_buf_entries);
      pre_allocate_buf_wp <= PRE_ALLOCATE_BUF_IDX_WIDTH'(32'(pre_allocate_buf_wp)+num_of_new_pre_allocate_buf_entries);
      noei_pre_allocate_buf <= noei_pre_allocate_buf_next;

      pre_allocate_buf_data <= pre_allocate_buf_data_next;
      pre_allocate_buf_idx <= pre_allocate_buf_idx_next;

      // ram本体への書き込み.
      for (int unsigned i = 0; i < NUM_OF_BANKS; i++) begin
        if (data_to_write[i].valid) begin
          ram[i][data_to_write[i].idx] <= data_to_write[i].data;
        end
      end

      // ramからの読み込み.
      for (int unsigned i = 0; i < NUM_OF_READ; i++) begin
        if (r_en[i]) begin
          r_data[i] <= ram[i][r_idx[i][BANK_IDX_WIDTH+:SETS_PER_BANK_IDX_WIDTH]];
        end
      end

    end
  end
endmodule
