`timescale 1ns / 1ps


module resetn_release_debounce #(
    parameter int unsigned DEBOUNCE_CYCLES = 1_000_000
) (
    input  logic clock,
    input  logic resetn_raw,   // 外部ボタンなど。active-low
    output logic resetn_clean  // 自作CPUへ渡すresetn
);

  localparam int unsigned CNT_MAX = DEBOUNCE_CYCLES;

  logic sync1;
  logic sync2;
  int unsigned cnt;

  // メタステを防止するために二段FFにする
  always_ff @(posedge clock or negedge resetn_raw) begin
    if (!resetn_raw) begin
      sync1 <= 1'b0;
      sync2 <= 1'b0;
    end else begin
      sync1 <= 1'b1;
      sync2 <= sync1;
    end
  end

  /*
     * reset解除を遅延する。
     * 途中で resetn_raw が 0 に戻ったら async reset で即やり直し。
     */
  always_ff @(posedge clock or negedge resetn_raw) begin
    if (!resetn_raw) begin
      cnt          <= '0;
      resetn_clean <= 1'b0;
    end else begin
      if (!sync2) begin
        cnt          <= '0;
        resetn_clean <= 1'b0;
      end else if (!resetn_clean) begin
        if (cnt >= CNT_MAX) begin
          resetn_clean <= 1'b1;
        end else begin
          cnt <= cnt + 1'b1;
        end
      end
    end
  end

endmodule
