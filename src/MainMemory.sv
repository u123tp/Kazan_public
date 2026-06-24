`timescale 1ns / 1ps
// メインメモリ
// とりあえず,64Byte(=512bit)単位でキャッシュとやり取りする.
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"


module MainMemory
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
(
    input logic clock,
    input logic reset,
    mm_icache_if.host icache_port,
    mm_dcache_if.host dcache_port,

    input logic dump_mm
);

  // 本当は処理待ちを置いておくキューとかが必要なんだろうけど,とりあえず遅れなしですべて返せるのでそれで実装.

  // 16MiB分のメモリ
  // osの方でも大きさ指定があるので、変えるときはそっちも変えること.
  localparam int unsigned MEM_SIZE = 1024 * 1024 * 2;


  localparam int unsigned MEM_BLOCK_OFFSET_WIDTH = $clog2(8);
  localparam int unsigned MEM_BLOCK_OFFSET_LSB = 0;
  localparam int unsigned MEM_BLOCK_OFFSET_MSB = MEM_BLOCK_OFFSET_LSB + MEM_BLOCK_OFFSET_WIDTH - 1;

  localparam int unsigned MEM_BLOCK_IDX_WIDTH = $clog2(MEM_SIZE);
  localparam int unsigned MEM_BLOCK_IDX_LSB = MEM_BLOCK_OFFSET_MSB + 1;
  localparam int unsigned MEM_BLOCK_IDX_MSB = MEM_BLOCK_IDX_LSB + MEM_BLOCK_IDX_WIDTH - 1;

  // メモリ本体
  logic [63:0] mem[MEM_SIZE];

  // kernel.hexを読み込む
  logic [31:0] mem_tmp[MEM_SIZE*2];
  initial begin
    // $readmemh("./riscv-tests-hex/rv64ua-v-amoadd_d.hex", mem_tmp);
    $readmemh("../kernel/hex/kernel.hex", mem_tmp);
    for (int unsigned i = 0; i < MEM_SIZE; i++) begin
      for (int unsigned j = 0; j < 2; j++) begin
        mem[i][32*j+:32] = mem_tmp[2*i+j];
      end
    end
  end

  always_comb begin
    // 仮メインメモリは詰まらない
    icache_port.ready = 1;
    dcache_port.ready = 1;
  end


  always_ff @(posedge clock) begin
    if (reset) begin
    end else begin

      // icache_port
      for (int unsigned i = 0; i < NUM_OF_REQ_FROM_ICACHE_TO_MM; i++) begin
        if (icache_port.req[i].valid) begin
          if (icache_port.req[i].is_write) begin

            // 書き込み(icacheは書き込み無いけど)
            mem[icache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]] <= icache_port.req[i].data[63:0];
            mem[icache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]+1] <= icache_port.req[i].data[127:64];

            icache_port.res[i] <= '{default: 0};
          end else begin
            // 読み込み
            // リトルエンディアン.
            icache_port.res[i] <= '{
                valid: 1,
                id: icache_port.req[i].id,
                id_sub: icache_port.req[i].id_sub,
                paddr_mig_aligned: icache_port.req[i].paddr_mig_aligned,
                data: {
                  mem[icache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]+1],
                  mem[icache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]]
                }
            };
          end
        end else begin
          // リクエストが無い場合.
          icache_port.res[i] <= '{default: 0};
        end
      end

      // dcache_port
      for (int unsigned i = 0; i < NUM_OF_REQ_FROM_DCACHE_TO_MM; i++) begin
        if (dcache_port.req[i].valid) begin
          if (dcache_port.req[i].is_write) begin

            // 書き込み
            mem[dcache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]] <= dcache_port.req[i].data;
            dcache_port.res[i] <= '{default: 0};
          end else begin
            // 読み込み
            // リトルエンディアン.
            dcache_port.res[i] <= '{
                valid: 1,
                id: dcache_port.req[i].id,
                id_sub: dcache_port.req[i].id_sub,
                paddr_mig_aligned: dcache_port.req[i].paddr_mig_aligned,
                data:
                mem[
                dcache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]
                ]
            };
          end
        end else begin
          // リクエストが無い場合.
          dcache_port.res[i] <= '{default: 0};
        end
      end


    end
  end


  // FOR DEBUG

  always_comb begin
    integer fp = 0;
    if (dump_mm) begin
`ifdef MMLOG_EN
      fp = $fopen("./log/log_memdump.hex", "w");
      $fdisplay(fp, "0f 0e 0d 0c  0b 0a 09 08  07 06 05 04  03 02 01 00");
      for (int unsigned i = 0; i < MEM_SIZE; i++) begin
        // mem[i] が [127:0] の 128bit と仮定
        $fdisplay(fp, "%h %h %h %h  %h %h %h %h  %h %h %h %h  %h %h %h %h  0x%016h",
                  mem[i][127:120], mem[i][119:112], mem[i][111:104], mem[i][103:96], mem[i][95:88],
                  mem[i][87:80], mem[i][79:72], mem[i][71:64], mem[i][63:56], mem[i][55:48],
                  mem[i][47:40], mem[i][39:32], mem[i][31:24], mem[i][23:16], mem[i][15:8],
                  mem[i][7:0], 32'h8000_0000 + i * 16);
      end
`endif
    end
  end

  // always_comb begin
  //   for (int unsigned i = 0; i < NUM_OF_ICACHE_REQ_OUT; i++) begin
  //     if (icache_port.req[i].valid && icache_port.req[i].paddr_mig_aligned == 0) begin

  //       $display("[ERROR][Mainmemory.sv] paddr is 0");
  //       $finish;
  //     end
  //   end
  // end

endmodule
