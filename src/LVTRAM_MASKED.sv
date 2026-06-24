`timescale 1ns / 1ps

// LVTRAM_MASKEDでは,lvtramをbyte単位に分割し,byte単位で更新できるようにする.
// 具体的にはmaskを用いて,対応するbyteだけを更新する.
// LVTMASKEDでは,入力は8bitの倍数である必要がある.

module LVTRAM_MASKED #(
    parameter int unsigned RAM_WIDTH = 64,
    parameter int unsigned RAM_DEPTH = 128,
    // RAM_WIDTH_BYTEはマスク用なのでバイト単位で切り上げ.
    parameter int unsigned RAM_BYTE_WIDTH = (RAM_WIDTH+7) / 8,
    parameter int unsigned RAM_IDX_WIDTH = $clog2(RAM_DEPTH),

    parameter int unsigned NUM_OF_READ_PORT  = 2,
    parameter int unsigned NUM_OF_WRITE_PORT = 2,

    // tohostの確認の為.
    parameter int unsigned IS_DCACHE = 0)(
    input logic clock,
    input logic reset,

    input logic r_en[NUM_OF_READ_PORT],
    input logic [RAM_IDX_WIDTH-1:0] r_ram_idx[NUM_OF_READ_PORT],
    output logic [RAM_WIDTH-1:0] r_data[NUM_OF_READ_PORT],

    input logic w_en[NUM_OF_WRITE_PORT],
    input logic [RAM_IDX_WIDTH-1:0] w_ram_idx[NUM_OF_WRITE_PORT],
    input logic [RAM_WIDTH-1:0] w_data[NUM_OF_WRITE_PORT],
    input logic [RAM_BYTE_WIDTH-1:0] w_mask[NUM_OF_WRITE_PORT]
);

  // byte単位にlvtを持つ.
  logic [7:0] r_data_byte[RAM_BYTE_WIDTH][NUM_OF_READ_PORT];
  logic [7:0] w_data_byte[RAM_BYTE_WIDTH][NUM_OF_WRITE_PORT];
  logic w_en_byte[RAM_BYTE_WIDTH][NUM_OF_WRITE_PORT];

  always_comb begin
    for (int unsigned port_idx = 0; port_idx < NUM_OF_READ_PORT; port_idx++) begin
      for (int unsigned byte_idx = 0; byte_idx < RAM_BYTE_WIDTH; byte_idx++) begin
        r_data[port_idx][8*byte_idx+:8] = r_data_byte[byte_idx][port_idx];
      end
    end


    for (int unsigned port_idx = 0; port_idx < NUM_OF_WRITE_PORT; port_idx++) begin
      for (int unsigned byte_idx = 0; byte_idx < RAM_BYTE_WIDTH; byte_idx++) begin
        w_data_byte[byte_idx][port_idx] = w_data[port_idx][byte_idx*8+:8];
        w_en_byte[byte_idx][port_idx]   = w_en[port_idx] & w_mask[port_idx][byte_idx];
      end

    end
  end


  genvar byte_idx;
  generate
    for (byte_idx = 0; byte_idx < RAM_BYTE_WIDTH; byte_idx++) begin
      LVTRAM #(
          .RAM_WIDTH(8),
          .RAM_DEPTH(RAM_DEPTH),
          .NUM_OF_READ_PORT(NUM_OF_READ_PORT),
          .NUM_OF_WRITE_PORT(NUM_OF_WRITE_PORT)
      ) lvt_byte (
          .clock(clock),
          .reset(reset),

          .r_en(r_en),
          .r_ram_idx(r_ram_idx),
          .r_data(r_data_byte[byte_idx]),

          .w_en(w_en_byte[byte_idx]),
          .w_ram_idx(w_ram_idx),
          .w_data(w_data_byte[byte_idx])
      );

    end
  endgenerate


endmodule


