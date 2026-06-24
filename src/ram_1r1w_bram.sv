`timescale 1ns / 1ps

module ram_1r1w_bram #(
    parameter int unsigned RAM_WIDTH     = 64,
    parameter int unsigned RAM_DEPTH     = 512,
    parameter int unsigned RAM_IDX_WIDTH = $clog2(RAM_DEPTH),

    // この容量以上ならURAMを使用する。単位はbit。
    parameter longint unsigned URAM_MIN_BITS = 32 * 64
) (
    input logic clock,

    // 読み出しポート
    input  logic                     r_en,
    input  logic [RAM_IDX_WIDTH-1:0] r_ram_idx,
    output logic [    RAM_WIDTH-1:0] r_data,

    // 書き込みポート
    input logic                     w_en,
    input logic [RAM_IDX_WIDTH-1:0] w_ram_idx,
    input logic [    RAM_WIDTH-1:0] w_data
);

  localparam longint unsigned RAM_BITS = longint'(RAM_WIDTH) * RAM_DEPTH;

  localparam bit USE_URAM = RAM_BITS >= URAM_MIN_BITS;

  // RAM出力
  logic [RAM_WIDTH-1:0] r_data_tmp;

  // バイパス判定用
  logic r_en_prev;
  logic [RAM_IDX_WIDTH-1:0] r_ram_idx_prev;
  logic w_en_prev;
  logic [RAM_IDX_WIDTH-1:0] w_ram_idx_prev;
  logic [RAM_WIDTH-1:0] w_data_prev;

  /*
   * 同じサイクルに同じアドレスをread/writeした場合、
   * 次サイクルの出力を新しい書き込みデータにする。
   */
  always_comb begin
    if (r_en_prev && w_en_prev && (w_ram_idx_prev == r_ram_idx_prev)) begin
      r_data = w_data_prev;
    end else begin
      r_data = r_data_tmp;
    end
  end

  always_ff @(posedge clock) begin
    r_en_prev      <= r_en;
    r_ram_idx_prev <= r_ram_idx;

    w_en_prev      <= w_en;
    w_ram_idx_prev <= w_ram_idx;
    w_data_prev    <= w_data;
  end

  generate
    if (USE_URAM) begin : g_uram

      (* ram_style = "ultra" *)
      logic [RAM_WIDTH-1:0] ram[0:RAM_DEPTH-1];

      always_ff @(posedge clock) begin
        if (r_en) begin
          r_data_tmp <= ram[r_ram_idx];
        end

        if (w_en) begin
          ram[w_ram_idx] <= w_data;
        end
      end

    end else begin : g_bram

      (* ram_style = "block" *)
      logic [RAM_WIDTH-1:0] ram[0:RAM_DEPTH-1];

      always_ff @(posedge clock) begin
        if (r_en) begin
          r_data_tmp <= ram[r_ram_idx];
        end

        if (w_en) begin
          ram[w_ram_idx] <= w_data;
        end
      end

    end
  endgenerate

endmodule
