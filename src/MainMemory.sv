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
    mm_if.host tlb_port,
    mm_if.host cache_port,

    input logic dump_mm
);

  // 本当は処理待ちを置いておくキューとかが必要なんだろうけど,とりあえず遅れなしですべて返せるのでそれで実装.

  //16Byte=128bit単位で管理する.
  // 16KiB分のメモリ
  // 16MiB分のメモリ

  localparam int unsigned MEM_SIZE = 1024 * 1024;

  localparam int unsigned MEM_BLOCK_OFFSET_WIDTH = $clog2(16);
  localparam int unsigned MEM_BLOCK_OFFSET_LSB = 0;
  localparam int unsigned MEM_BLOCK_OFFSET_MSB = MEM_BLOCK_OFFSET_LSB + MEM_BLOCK_OFFSET_WIDTH - 1;

  localparam int unsigned MEM_BLOCK_IDX_WIDTH = $clog2(MEM_SIZE);
  localparam int unsigned MEM_BLOCK_IDX_LSB = MEM_BLOCK_OFFSET_MSB + 1;
  localparam int unsigned MEM_BLOCK_IDX_MSB = MEM_BLOCK_IDX_LSB + MEM_BLOCK_IDX_WIDTH - 1;


  logic [127:0] mem[MEM_SIZE];
  logic [31:0] mem_tmp[MEM_SIZE*4];

  initial begin
    // $readmemh("./riscv-tests-hex/rv64ui-v-add.hex", mem_tmp);
    $readmemh("../kernel/hex/kernel.hex", mem_tmp);
    for (int unsigned i = 0; i < MEM_SIZE; i++) begin
      for (int unsigned j = 0; j < 4; j++) begin
        mem[i][32*j+:32] = mem_tmp[4*i+j];
      end
    end
  end

  // For DEBUG
  logic [127:0] data0;
  assign data0 = mem[0];
  logic [127:0] data1;
  assign data1 = mem[1];
  logic [127:0] data2;
  assign data2 = mem[2];
  logic [127:0] data3;
  assign data3 = mem[3];
  logic [127:0] data4;
  assign data4 = mem[4];
  logic [127:0] data5;
  assign data5 = mem[5];
  logic [127:0] data6;
  assign data6 = mem[6];
  logic [127:0] data7;
  assign data7 = mem[7];

  always_comb begin
    // 仮メインメモリは詰まらない
    tlb_port.ready   = 1;
    cache_port.ready = 1;
  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
    end else begin

      // tlb_port
      for (int unsigned i = 0; i < NUM_OF_PW; i++) begin
        if (tlb_port.req[i].valid) begin
          if (tlb_port.req[i].is_write) begin
            // 書き込み
            mem[tlb_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]]<= tlb_port.req[i].data;
            tlb_port.res[i] <= '{default: 0};
          end else begin
            // 読み込み

            tlb_port.res[i] <= '{
                valid: 1,
                id: tlb_port.req[i].id,
                paddr_mig_aligned: tlb_port.req[i].paddr_mig_aligned,
                data: mem[tlb_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]]
            };
          end
        end else begin
          tlb_port.res[i] <= '{default: 0};
        end
      end

      // cache_port
      for (int unsigned i = 0; i < NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE; i++) begin
        if (cache_port.req[i].valid) begin
          if (cache_port.req[i].is_write) begin
            // 書き込み
            mem[cache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]] <= cache_port.req[i].data;
            cache_port.res[i] <= '{default: 0};
          end else begin
            // 読み込み
            // リトルエンディアン.
            cache_port.res[i] <= '{
                valid: 1,
                id: cache_port.req[i].id,
                paddr_mig_aligned: cache_port.req[i].paddr_mig_aligned,
                data: mem[cache_port.req[i].paddr_mig_aligned[MEM_BLOCK_IDX_MSB:MEM_BLOCK_IDX_LSB]]
            };
          end
        end else begin
          cache_port.res[i] <= '{default: 0};
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

endmodule
