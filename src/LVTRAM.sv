

`timescale 1ns / 1ps
// LVTRAM
// 読み込みポート,書き込みポートの数を自由に設定できるRAM
// ただし,bram(sram,lutram)は読み込みポート数*書き込みポート数だけ必要.
// https://msyksphinz.hatenablog.com/entry/2023/12/07/040000
// 
// 同じクロックでramの同じアドレスに対して書き込みと読み込みを同時に行う時,
// 書き込みから読み込みにデータをバイパスすることを保証する.
// 複数回書き込みが行われた場合は最もwrite_port_idxの大きいものを返す.
// vivadoではRW_ADDR_COLLISIONをyesにすればそれは保証されるが,sramへの移植も考えてバイパス回路を実装する.
// 
// TODO: interfaceでつなげるべきだったなこれ.
// というか全体的に読みにくすぎる.write_portとかread_portとか.
//
// マスクは無い.

module LVTRAM #(
    parameter int unsigned RAM_WIDTH = 100,
    parameter int unsigned RAM_DEPTH = 64,
    // RAM_WIDTH_BYTEはマスク用なのでバイト単位で切り上げ.
    // parameter int unsigned RAM_WIDTH_BYTE = (RAM_WIDTH+7) / 8,
    parameter int unsigned RAM_IDX_WIDTH = $clog2(RAM_DEPTH),

    parameter int unsigned NUM_OF_READ_PORT  = 4,
    parameter int unsigned NUM_OF_WRITE_PORT = 7,

    // tohostの確認の為.
    parameter int unsigned IS_DCACHE = 0,

    // lutramかbramか.
    parameter logic IS_BRAM = 1
) (
    input logic clock,
    input logic reset,


    input logic r_en[NUM_OF_READ_PORT],
    input logic [RAM_IDX_WIDTH-1:0] r_ram_idx[NUM_OF_READ_PORT],
    output logic [RAM_WIDTH-1:0] r_data[NUM_OF_READ_PORT],

    input logic w_en[NUM_OF_WRITE_PORT],
    input logic [RAM_IDX_WIDTH-1:0] w_ram_idx[NUM_OF_WRITE_PORT],
    input logic [RAM_WIDTH-1:0] w_data[NUM_OF_WRITE_PORT]
);

  localparam int unsigned NUM_OF_BANKS = NUM_OF_READ_PORT * NUM_OF_WRITE_PORT;

  // 同じデータを保存しているバンクをまとめたクラスタ(Same Data Cluster)に含まれるバンクの数.
  // これはNUM_OF_READ_PORTと等しい.
  // 1つのクラスタにはNUM_OF_READ_PORT個のバンクが含まれる.
  localparam int unsigned NUM_OF_BANK_IN_SD_CLUSTER = NUM_OF_READ_PORT;
  localparam int unsigned NUM_OF_SD_CLUSTER = NUM_OF_WRITE_PORT;

  localparam int unsigned SD_CLUSTER_IDX_WIDTH = (NUM_OF_SD_CLUSTER == 1) ? 1 : $clog2(
      NUM_OF_SD_CLUSTER
  );
  localparam int unsigned  BANK_IN_SD_CLUSTER_IDX_WIDTH = (NUM_OF_BANK_IN_SD_CLUSTER == 1) ? 1 : $clog2(
      NUM_OF_BANK_IN_SD_CLUSTER
  );


  // --------------------------------------------------------
  // RAM本体
  // --------------------------------------------------------
  // 1R+1Wのramを並べる.
  // (* ram_style = "block" *)
  // logic [RAM_WIDTH-1:0] ram[NUM_OF_SD_CLUSTER][NUM_OF_BANK_IN_SD_CLUSTER][RAM_DEPTH];

  // r_data_multiway[read_port_idx][write_port_idx]
  logic [RAM_WIDTH-1:0] r_data_multiway[NUM_OF_BANK_IN_SD_CLUSTER][NUM_OF_SD_CLUSTER];

  genvar ram_write_port_idx;
  genvar ram_read_port_idx;

  generate
    for (
        ram_read_port_idx = 0; ram_read_port_idx < NUM_OF_BANK_IN_SD_CLUSTER; ram_read_port_idx++
    ) begin : g_read_port_idx
      for (
          ram_write_port_idx = 0; ram_write_port_idx < NUM_OF_SD_CLUSTER; ram_write_port_idx++
      ) begin : g_write_port_idx
        if (IS_BRAM) begin : g_bram
          // bram
          ram_1r1w_bram #(
              .RAM_WIDTH(RAM_WIDTH),
              .RAM_DEPTH(RAM_DEPTH)
          ) dualport_ram (
              .clock(clock),
              .r_en(r_en[ram_read_port_idx]),
              .r_ram_idx(r_ram_idx[ram_read_port_idx]),
              .r_data(r_data_multiway[ram_read_port_idx][ram_write_port_idx]),
              .w_en(w_en[ram_write_port_idx]),
              .w_ram_idx(w_ram_idx[ram_write_port_idx]),
              .w_data(w_data[ram_write_port_idx])
          );
        end else begin : g_lutram
          // lut
          ram_1r1w_lutram #(
              .RAM_WIDTH(RAM_WIDTH),
              .RAM_DEPTH(RAM_DEPTH)
          ) dualport_ram (
              .clock(clock),
              .r_en(r_en[ram_read_port_idx]),
              .r_ram_idx(r_ram_idx[ram_read_port_idx]),
              .r_data(r_data_multiway[ram_read_port_idx][ram_write_port_idx]),
              .w_en(w_en[ram_write_port_idx]),
              .w_ram_idx(w_ram_idx[ram_write_port_idx]),
              .w_data(w_data[ram_write_port_idx])
          );
        end
      end
    end
  endgenerate

  // ------------------------------------------------------
  // LVT (Live Value Table)
  // ------------------------------------------------------
  // ram_idxに対応するデータがどのnr1w_blockに存在するかを記録するテーブル.
  // 4R+4Wが必要なのでlutramではなくffで実装.
  logic [SD_CLUSTER_IDX_WIDTH-1:0] lvt[RAM_DEPTH];

  typedef struct packed {
    logic valid;
    logic [RAM_IDX_WIDTH-1:0] ram_idx;
    logic [SD_CLUSTER_IDX_WIDTH-1:0] cluster_idx;
  } lvt_update_t;

  lvt_update_t lvt_update[NUM_OF_WRITE_PORT];

  // そのときにlvt参照に用いる前サイクルでのr_ram_idx_prev
  logic [RAM_IDX_WIDTH-1:0] r_ram_idx_prev[NUM_OF_READ_PORT];

  // read_raw_data, lvt => r_data
  always_comb begin
    for (int unsigned read_port_idx = 0; read_port_idx < NUM_OF_READ_PORT; read_port_idx++) begin
      automatic
      logic [SD_CLUSTER_IDX_WIDTH-1:0]
      last_written_sd_cluster_idx = lvt[r_ram_idx_prev[read_port_idx]];
      r_data[read_port_idx] = r_data_multiway[read_port_idx][last_written_sd_cluster_idx];
    end
  end

  // lvtのアップデート
  always_comb begin
    // lvt_next = lvt;
    // for (
    //     int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
    // ) begin
    //   if (w_en[write_port_idx]) begin
    //     lvt_next[w_ram_idx[write_port_idx]] = SD_CLUSTER_IDX_WIDTH'(write_port_idx);
    //   end
    // end

    lvt_update = '{default: 0};
    for (
        int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
    ) begin
      if (w_en[write_port_idx]) begin
        lvt_update[write_port_idx] = '{
            valid: 1,
            ram_idx: w_ram_idx[write_port_idx],
            cluster_idx: SD_CLUSTER_IDX_WIDTH'(write_port_idx)
        };
      end
    end

  end


  always_ff @(posedge clock) begin
    if (reset) begin
      lvt <= '{default: 0};
      r_ram_idx_prev <= '{default: 0};
    end else begin

      // 更新.
      for (
          int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
      ) begin
        if (lvt_update[write_port_idx].valid) begin
          lvt[lvt_update[write_port_idx].ram_idx] <= lvt_update[write_port_idx].cluster_idx;
        end
      end
      r_ram_idx_prev <= r_ram_idx;


    end
  end



endmodule
