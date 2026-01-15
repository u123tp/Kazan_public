// メモリのレイアウト
// mmioかどうかなどの情報を保持する
// xv6 for qemuのレイアウトは以下.
// 0000 1000 -- boot ROM, provided by qemu
// 0200 0000 -- CLINT
// 0C00 0000 -- PLIC
// 1000 0000 -- uart0 
// 1000 1000 -- virtio disk 
// 8000 0000 -- boot ROMがここにマシンモードで飛ぶ
//             -カーネルはここでカーネルをロードする
// unused RAM after 80000000.
//
// 上記以外の場所は,vacantにアクセスしたとしてチェック.
// 今はとりあえず、メモリの属性を返すことにしているが、そのうちuncachebleとかの
// フィールド単位で管理するようにする.これは,今はメモリの属性とそれらのフィールドの区分が一致しているからである.

`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"

`ifndef MEMORY_LAYOUT_IFDEF
`define MEMORY_LAYOUT_IFDEF

package MemoryLayout;
  import COMMON_PARAMS::*;
  import HART_DEFS::*;

  localparam int unsigned NUM_OF_PMA = 5;

  typedef struct packed {
    logic [PADDR_WIDTH-1:0] start_addr;
    logic [PADDR_WIDTH-1:0] size;
    logic is_mmio;
    // logic cacheble;
    // logic executable;
  } pma_t;

  pma_t pma[NUM_OF_PMA] = '{
      // ブートローダ
      '{
          start_addr: PADDR_WIDTH'(unsigned'(32'h0000_1000)),
          size: PADDR_WIDTH'(unsigned'(32'h0100_0000)),
          is_mmio: 0
      },
      // CLINT
      '{
          start_addr: PADDR_WIDTH'(unsigned'(32'h0200_0000)),
          size: PADDR_WIDTH'(unsigned'(32'h0001_0000)),
          is_mmio: 1
      },
      // PLIC
      '{
          start_addr: PADDR_WIDTH'(32'h0c00_0000),
          size: PADDR_WIDTH'(32'h0400_0000),
          is_mmio: 1
      },
      // UART0
      '{
          start_addr: PADDR_WIDTH'(32'h1000_0000),
          size: PADDR_WIDTH'(32'h0000_0100),
          is_mmio: 1
      },
      // RAM
      '{
          start_addr: PADDR_WIDTH'(32'h8000_0000),
          size: PADDR_WIDTH'(32'h8800_0000),
          is_mmio: 0
      }
  };

  function automatic int unsigned get_pma_idx(input logic [PADDR_WIDTH-1:0] paddr_origin);
    for (int unsigned i = 0; i < 5; i++) begin
      if (pma[i].start_addr <= paddr_origin && paddr_origin < pma[i].start_addr + pma[i].size) begin
        return i;
      end
    end
    return 99;
  endfunction

  // そのメモリの属性を返す.
  function automatic pma_type_e get_pma_type(input logic [PADDR_WIDTH-1:0] paddr_origin);
    int unsigned pma_idx = get_pma_idx(paddr_origin);
    if (pma_idx == 99) begin
      return PMA_NONE;
    end else begin
      if (pma[pma_idx].is_mmio) begin
        return PMA_MMIO;
      end else begin
        return PMA_MEMORY;
      end
    end
  endfunction


  // デバイス名を返す. lsuとかでどのデバイスにアクセスすればいいかの判別とかに使う.
  function automatic device_name_e get_device_name(input logic [PADDR_WIDTH-1:0] paddr_origin);
    int unsigned pma_idx = get_pma_idx(paddr_origin);
    case (pma_idx)
      0: return DN_BOOTLOADER;
      1: return DN_CLINT;
      2: return DN_PLIC;
      3: return DN_UART;
      4: return DN_DRAM;
      default: return DN_NONE;
    endcase
  endfunction




endpackage

`endif
