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
// NOTION: マスクはRAM_WIDTHが2の累乗のときのみ有効.

module LVTRAM #(
    parameter int unsigned RAM_WIDTH = 64,
    parameter int unsigned RAM_DEPTH = 128,
    parameter int unsigned RAM_WIDTH_BYTE = RAM_WIDTH / 8,
    parameter int unsigned RAM_IDX_WIDTH = $clog2(RAM_DEPTH),

    parameter int unsigned NUM_OF_READ_PORT  = 2,
    parameter int unsigned NUM_OF_WRITE_PORT = 2,

    // tohostの確認の為.
    parameter int unsigned IS_DCACHE = 0
) (
    input logic clock,
    input logic reset,

    input logic r_en[NUM_OF_READ_PORT],
    input logic [RAM_IDX_WIDTH-1:0] r_ram_idx[NUM_OF_READ_PORT],
    output logic [RAM_WIDTH-1:0] r_data[NUM_OF_READ_PORT],

    input logic w_en[NUM_OF_WRITE_PORT],
    input logic [RAM_IDX_WIDTH-1:0] w_ram_idx[NUM_OF_WRITE_PORT],
    input logic [RAM_WIDTH-1:0] w_data[NUM_OF_WRITE_PORT],
    input logic [RAM_WIDTH_BYTE-1:0] w_mask[NUM_OF_WRITE_PORT]
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

  // ram_widthが2の累乗か.
  localparam logic IS_RAM_WIDTH_POWER = ((RAM_WIDTH & (RAM_WIDTH - 1)) == 32'b0);

  // --------------------------------------------------------
  // RAM本体
  // --------------------------------------------------------
  // 1R+1Wのramを並べる.
  (* ram_style = "distributed" *)
  logic [RAM_WIDTH-1:0] ram[NUM_OF_SD_CLUSTER][NUM_OF_BANK_IN_SD_CLUSTER][RAM_DEPTH];

  // ------------------------------------------------------
  // LVT (Live Value Table)
  // ------------------------------------------------------
  // ram_idxに対応するデータがどのnr1w_blockに存在するかを記録するテーブル.
  // 4R+4Wが必要なのでlutramではなくffで実装.
  logic [SD_CLUSTER_IDX_WIDTH-1:0] lvt[RAM_DEPTH];
  logic [SD_CLUSTER_IDX_WIDTH-1:0] lvt_next[RAM_DEPTH];
  logic [SD_CLUSTER_IDX_WIDTH-1:0] lvt_prev[RAM_DEPTH];

  // 各read命令に対してバイパスを行うか,行う場合はどのwrite_portからか
  typedef struct packed {
    logic valid;
    logic [SD_CLUSTER_IDX_WIDTH-1:0] sd_cluster_idx;
  } bypass_table_t;
  bypass_table_t bypass_table[NUM_OF_READ_PORT];


  // 各read port ごとに すべてのnr1w_blockから一つづデータをよみだしてread_raw_dataとする.
  // このnr1w_block個のデータからlvtの内容に従って一つに絞る.
  logic [RAM_WIDTH-1:0] read_raw_data[NUM_OF_READ_PORT][NUM_OF_WRITE_PORT];
  // そのときにlvt参照に用いる前サイクルでのr_ram_idx_prev
  logic [RAM_IDX_WIDTH-1:0] r_ram_idx_prev[NUM_OF_READ_PORT];

  // read_raw_data, lvt => r_data
  always_comb begin
    for (int unsigned read_port_idx = 0; read_port_idx < NUM_OF_READ_PORT; read_port_idx++) begin
      logic [SD_CLUSTER_IDX_WIDTH-1:0] last_written_sd_cluster_idx = lvt_prev[r_ram_idx_prev[read_port_idx]];
      r_data[read_port_idx] = read_raw_data[read_port_idx][last_written_sd_cluster_idx];
    end
  end

  // lvtのアップデート
  always_comb begin
    lvt_next = lvt;
    for (
        int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
    ) begin
      if (w_en[write_port_idx]) begin
        lvt_next[w_ram_idx[write_port_idx]] = SD_CLUSTER_IDX_WIDTH'(write_port_idx);
      end
    end

  end

  // bypasss_tableの作成
  // 今のwriteの入力の内, readの入力とアドレスが同じものがあればバイパスする.
  always_comb begin
    bypass_table = '{default: 0};

    for (int unsigned read_port_idx = 0; read_port_idx < NUM_OF_READ_PORT; read_port_idx++) begin
      for (
          int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
      ) begin
        if (r_en[read_port_idx] && w_en[write_port_idx] && r_ram_idx[read_port_idx] == w_ram_idx[write_port_idx]) begin
          bypass_table[read_port_idx] = '{
              valid: 1,
              sd_cluster_idx: SD_CLUSTER_IDX_WIDTH'(write_port_idx)
          };
        end
      end
    end

  end




  /* verilator lint_off BLKSEQ */

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      lvt = '{default: 0};
      lvt_prev = '{default: 0};
      ram = '{default: '{default: '{default: 0}}};
    end else begin

      // 更新.
      lvt = lvt_next;
      lvt_prev = lvt;

      // w_data => ram
      for (
          int unsigned write_port_idx = 0; write_port_idx < NUM_OF_WRITE_PORT; write_port_idx++
      ) begin
        if (w_en[write_port_idx]) begin
          for (int unsigned i = 0; i < NUM_OF_READ_PORT; i++) begin
            // RAM_WIDTH が2の累乗にならない場合はmaskを使用しない.
            if (IS_RAM_WIDTH_POWER) begin
              for (int unsigned byte_idx = 0; byte_idx < RAM_WIDTH_BYTE; byte_idx++) begin
                if (w_mask[write_port_idx][byte_idx]) begin
                  ram[write_port_idx][i][w_ram_idx[write_port_idx]][byte_idx*8+:8] = w_data[write_port_idx][byte_idx*8+:8];
                end
              end
            end else begin
              //
              ram[write_port_idx][i][w_ram_idx[write_port_idx]] = w_data[write_port_idx];
            end
          end
        end
      end

      // ram => read_raw_data
      for (int unsigned read_port_idx = 0; read_port_idx < NUM_OF_READ_PORT; read_port_idx++) begin
        if (r_en[read_port_idx]) begin
          if (bypass_table[read_port_idx].valid) begin
            // バイパスする場合,面倒なのでread_raw_dataのすべてのwrite_port_idxを書けばいい
            for (
                int unsigned sd_cluster_idx = 0;
                sd_cluster_idx < NUM_OF_WRITE_PORT;
                sd_cluster_idx++
            ) begin
              // read_raw_data[read_port_idx][sd_cluster_idx] = w_data[bypass_table[read_port_idx].sd_cluster_idx];
              read_raw_data[read_port_idx][sd_cluster_idx] = ram[sd_cluster_idx][read_port_idx][r_ram_idx[read_port_idx]];
              if (IS_RAM_WIDTH_POWER) begin
                for (int unsigned byte_idx = 0; byte_idx < RAM_WIDTH; byte_idx++) begin
                  if (w_mask[sd_cluster_idx][byte_idx]) begin
                    read_raw_data[read_port_idx][sd_cluster_idx][byte_idx*8+:8] = w_data[bypass_table[read_port_idx].sd_cluster_idx][byte_idx*8+:8];
                  end
                end
              end else begin
                read_raw_data[read_port_idx][sd_cluster_idx] = w_data[bypass_table[read_port_idx].sd_cluster_idx];
              end
            end
          end else begin
            // バイパスしない場合.
            for (
                int unsigned sd_cluster_idx = 0;
                sd_cluster_idx < NUM_OF_WRITE_PORT;
                sd_cluster_idx++
            ) begin
              read_raw_data[read_port_idx][sd_cluster_idx] = ram[sd_cluster_idx][read_port_idx][r_ram_idx[read_port_idx]];
            end
          end
        end else begin
          read_raw_data[read_port_idx] = '{default: 0};
        end
      end

      // r_ram_idx => r_ram_idx_prev
      r_ram_idx_prev = r_ram_idx;

    end
  end

  /* verilator lint_on BLKSEQ */



endmodule
