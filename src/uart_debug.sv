`timescale 1ns / 1ps

`include "COMMON_PARAMS.svh"

// bufferが空なら,dataをbufに保存して,少しずつuartで送信する.

module uart_debug
  import COMMON_PARAMS::*;
#(
    parameter int unsigned BUF_SIZE = 8,
    parameter int unsigned BAU_RATE = 38400

) (
    input logic clock,
    input logic reset,

    input  logic cts,
    output logic rts,
    input  logic rxd,
    output logic txd,

    // cpuからuartに出力する文字.
    input logic data_in_en,
    input logic [BUF_SIZE-1:0] data_in,

    // 文字の入力
    output logic char_from_uart_valid,
    output logic [7:0] char_from_uart,

    // 次の入力を受け付けない
    output logic stall_out
);

  // -----------------------------------------------------------------
  // パラメータ
  // -----------------------------------------------------------------
  localparam int unsigned BUF_IDX_WIDTH = $clog2(BUF_SIZE);
  localparam int unsigned BAU_DIV = CLK_HZ / BAU_RATE;


  localparam int unsigned BYTE_NUM = BUF_SIZE / 8;

  function automatic logic [BUF_SIZE-1:0] reverse_bytes(input logic [BUF_SIZE-1:0] x);
    for (int unsigned i = 0; i < BYTE_NUM; i++) begin
      reverse_bytes[i*8+:8] = x[(BYTE_NUM-1-i)*8+:8];
    end
  endfunction


  // ----------------------------------------------------------------
  // バッファ本体
  // ----------------------------------------------------------------
  logic buf_empty;
  logic [BUF_SIZE-1:0] data_buf;
  logic [BUF_IDX_WIDTH:0] buf_rp;

  int unsigned bau_counter;


  // 8bitごとに,1'b1を出力=> 1'b0を出力をおこなう.
  // このとき,1'b1を出力したかはstopbit_sentで管理
  logic stopbit_sent;
  logic startbit_sent;


  // 受信は各値の真ん中でサンプリングする.
  localparam int unsigned RX_HALF_BAU_DIV = BAU_DIV / 2;

  typedef enum logic [1:0] {
    RX_IDLE,
    RX_START,
    RX_DATA,
    RX_STOP
  } rx_state_t;

  rx_state_t rx_state;
  int unsigned rx_bau_counter;
  logic [2:0] rx_bit_idx;
  logic [7:0] rx_shift;
  logic rxd_prev;
  logic rxd_sync;


  always_ff @(posedge clock) begin
    if (reset) begin
      buf_empty <= 1;
      data_buf <= '0;
      buf_rp <= 0;
      txd <= 1;
      startbit_sent <= 0;
      stopbit_sent <= 0;
      bau_counter <= 0;
    end else begin

      // 来たデータをバッファに入れる.
      if (buf_empty && data_in_en) begin
        data_buf  <= reverse_bytes(data_in);
        buf_empty <= 0;
      end

      // 分周させて1/BAU_DIVでしか動作させない
      if (bau_counter == BAU_DIV - 1) begin
        bau_counter <= 0;

        // -----------------------------------------------------------------
        // 送信.
        // -----------------------------------------------------------------
        if (!buf_empty) begin
          // 中にデータが残っている場合はrxで送信.

          if (32'(buf_rp) == BUF_SIZE) begin
            // すべて読みだしたのでリセット
            buf_empty <= 1;
            data_buf <= 0;
            buf_rp <= 0;
            // idle時はrxは1.
            txd <= 1;
          end else begin
            if (buf_rp[2:0] == 0 && !startbit_sent) begin
              // stopbitとstartbitの送信処理
              if (!stopbit_sent) begin
                // stopbit
                txd <= 1;
                stopbit_sent <= 1;
              end else begin
                // startbit
                txd <= 0;
                startbit_sent <= 1;
              end
            end else begin
              // startbitやstopbitでない通常データの送信処理. 
              // uartはlsb_firstなので,小さい方から送る.
              txd <= data_buf[BUF_IDX_WIDTH'(buf_rp)];
              buf_rp <= buf_rp + 1;
              startbit_sent <= 0;
              stopbit_sent <= 0;
            end
          end
        end




      end else begin
        bau_counter <= bau_counter + 1;
      end

    end
  end


  always_comb begin
    rts = 1'b0;
    stall_out = !buf_empty || data_in_en;
  end


  // -----------------------------------------------------------------
  // 受信
  // -----------------------------------------------------------------
  // メタステ防止用.
  always_ff @(posedge clock) begin
    if (reset) begin
      rxd_prev <= 1;
      rxd_sync <= 1;
    end else begin
      rxd_prev <= rxd;
      rxd_sync <= rxd_prev;
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      char_from_uart_valid <= 0;
      char_from_uart <= 0;
      rx_state <= RX_IDLE;
      rx_bau_counter <= 0;
      rx_bit_idx <= 0;
      rx_shift <= 0;
    end else begin
      char_from_uart_valid <= 0;

      case (rx_state)
        RX_IDLE: begin
          rx_bau_counter <= 0;
          rx_bit_idx <= 0;
          if (!rxd_sync) begin
            rx_state <= RX_START;
            rx_bau_counter <= RX_HALF_BAU_DIV;
          end
        end

        RX_START: begin
          if (rx_bau_counter == 0) begin
            if (!rxd_sync) begin
              rx_state <= RX_DATA;
              rx_bau_counter <= BAU_DIV - 1;
              rx_bit_idx <= 0;
            end else begin
              rx_state <= RX_IDLE;
            end
          end else begin
            rx_bau_counter <= rx_bau_counter - 1;
          end
        end

        RX_DATA: begin
          if (rx_bau_counter == 0) begin
            rx_shift[rx_bit_idx] <= rxd_sync;
            rx_bau_counter <= BAU_DIV - 1;
            if (rx_bit_idx == 3'd7) begin
              rx_state <= RX_STOP;
            end else begin
              rx_bit_idx <= rx_bit_idx + 1;
            end
          end else begin
            rx_bau_counter <= rx_bau_counter - 1;
          end
        end

        RX_STOP: begin
          if (rx_bau_counter == 0) begin
            if (rxd_sync) begin
              char_from_uart_valid <= 1;
              char_from_uart <= rx_shift;
            end
            rx_state <= RX_IDLE;
          end else begin
            rx_bau_counter <= rx_bau_counter - 1;
          end
        end

        default: begin
          rx_state <= RX_IDLE;
        end
      endcase
    end
  end



endmodule
