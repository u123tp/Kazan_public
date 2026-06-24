`timescale 1ns / 1ps
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"
`include "CSR_PROPS.svh"
`include "MemoryLayout.svh"

module Icache_req_arbiter
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
  import CSR_PROPS::*;
  import MemoryLayout::*;
(
    input logic clock,
    input logic reset,
    input program_counter_t pc_in_cur[NUM_OF_FETCH],

    // icacheへのreqとbootloaderへのreqを分別する.
    output cache_req128_t req_to_icache[NUM_OF_REQ_TO_ICACHE],
    output bootloader_req_t req_to_bootloader,

    input int unsigned generation,
    input privilege_level_e priv_rval,
    input csr_reg_u satp,

    input logic stall_in,

    output logic data_print_en,
    output logic [255:0] data_print

);

  // // FOR DEBUG
  //   function automatic device_name_e get_device_name(
  //     input logic [PADDR_WIDTH-1:0] paddr_origin
  // );

  //   // bootloader:
  //   // start = 0x0000_1000
  //   // size  = 0x0100_0000
  //   // end   = 0x0100_1000
  //   if (PADDR_WIDTH'(64'h0000_0000_0000_1000) <= paddr_origin &&
  //       paddr_origin < PADDR_WIDTH'(64'h0000_0000_0100_1000)) begin
  //     return DN_BOOTLOADER;
  //   end

  //   // CLINT:
  //   // start = 0x0200_0000
  //   // size  = 0x0001_0000
  //   // end   = 0x0201_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_0200_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_0201_0000)) begin
  //     return DN_CLINT;
  //   end

  //   // PLIC:
  //   // start = 0x0c00_0000
  //   // size  = 0x0400_0000
  //   // end   = 0x1000_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_0c00_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_1000_0000)) begin
  //     return DN_PLIC;
  //   end

  //   // UART0:
  //   // start = 0x1000_0000
  //   // size  = 0x0000_0100
  //   // end   = 0x1000_0100
  //   else if (PADDR_WIDTH'(64'h0000_0000_1000_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_1000_0100)) begin
  //     return DN_UART;
  //   end

  //   // RAM:
  //   // start = 0x8000_0000
  //   // size  = 0x8800_0000
  //   // end   = 0x1_0800_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_8000_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0001_0800_0000)) begin
  //     return DN_DRAM;
  //   end

  //   else begin
  //     return DN_NONE;
  //   end

  // endfunction

  // ---------------------------------------------------
  // stall用
  // ---------------------------------------------------
  // 一見icacheに対する入力はstallしなくても良い様に思えるが、icacheからのresをstallする手段が無いので,
  // ここでstallしておく必要がある.stallしないと,「btbやpredictorでstallされている命令」に対応する命令が,
  // icacheに入れられ,まだそれらがbtbやpredictorでstallしているうちにresponseがicacheから帰ってくる.
  // こうなると,ifqに入る前にcache_resを得ることになり,処理ができないのでデータが行き場所を失う.

  program_counter_t pc_in[NUM_OF_FETCH];

  program_counter_t pc_in_pending[NUM_OF_FETCH];
  logic is_pending;
  program_counter_t pc_in_pending_next[NUM_OF_FETCH];
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    pc_in_pending_next = pc_in_pending;

    if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      pc_in_pending_next = pc_in_cur;
      is_pending_next = 1;
      pc_in = '{default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      pc_in = '{default: 0};
    end else if (is_pending) begin
      // stall終了時.
      pc_in = pc_in_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      pc_in = pc_in_cur;
    end
  end


  // 4bitをASCIIの16進文字に変換する
  function automatic logic [7:0] hex_nibble_to_ascii(input logic [3:0] nibble);
    begin
      if (nibble < 4'd10) begin
        return 8'h30 + {4'h0, nibble};  // '0' - '9'
      end else begin
        return 8'h41 + {4'h0, nibble - 4'd10};  // 'A' - 'F'
      end
    end
  endfunction


  logic is_bootloader;


  // Icacheの入力.
  always_comb begin
    // 1サイクルのfetchの中には4つのwordが含まれる.
    // pc_in.addrがdwアラインメントされているかどうかは未定.
    // そのため,dwアラインメントされている場合は出すリクエストの数は2つ.
    // dwアラインメントされていない場合は3つ.
    for (int unsigned i = 0; i < NUM_OF_REQ_TO_ICACHE; i++) begin
      req_to_icache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end
    req_to_bootloader = '{default: 0};

    // bootloaderのコードかの判定
    if (priv_rval == M_MODE && get_device_name(PADDR_WIDTH'(pc_in[0].vaddr)) == DN_BOOTLOADER) begin
      is_bootloader = 1;
    end else begin
      is_bootloader = 0;
    end



    begin
      automatic logic valid_exist_in_dw = 0;
      automatic logic paddr_valid = 0;

      // dwの中に有効な命令が存在するか.
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (pc_in[i].valid) begin
          valid_exist_in_dw = 1;
        end
      end

      if (valid_exist_in_dw) begin
        if (priv_rval == M_MODE && get_device_name(
                PADDR_WIDTH'(pc_in[0].vaddr)
            ) == DN_BOOTLOADER) begin
          // ブートローダー
          req_to_bootloader = '{
              valid: 1,
              id: pc_in[0].fetch_id,
              paddr: PADDR_WIDTH'(pc_in[0].vaddr)
          };
        end else begin
          // dram(非ブートローダー)
          paddr_valid =  priv_rval ==  M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED?  1: 0;
          req_to_icache[0] = '{
              valid: 1,
              id:
              pc_in[
              0
              ].fetch_id,  // 先頭のエントリはvalidかinvalidかに関わらずvaddrとfetch_idを持っているのでそれを用いる.
              id_sub: 0,
              generation: generation,
              req_policy: READ_QUAD_WORD,
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_db_aligned:
              pc_in[
              0
              ].vaddr,  // 先頭のエントリがalignedされているので,invalidでもそれを用いる.
              paddr_valid: paddr_valid,  // m_modeならアドレス変換を行わない.
              // m_modeなら元からpaddrが有効
              paddr_db_aligned:
              PADDR_WIDTH
              '(
              pc_in[0].vaddr
              ),
              byte_in_db_idx: 0,
              satp: satp,
              data: 0
          };

        end


      end

    end

  end


  always_ff @(posedge clock) begin
    if (reset) begin
      pc_in_pending <= '{default: 0};
      is_pending <= 0;
    end else begin
      pc_in_pending <= pc_in_pending_next;
      is_pending <= is_pending_next;
    end
  end


  int unsigned counter;
  logic [39:0] vaddr40;
  assign vaddr40 = {1'b0, pc_in[0].vaddr};
  always_ff @(posedge clock) begin
    if (reset) begin
      data_print_en <= 0;
      data_print <= 0;
      counter <= 0;
    end else begin
      counter <= counter + 1;
      if (counter[23:0] == 0) begin
        data_print_en <= 1;
        data_print[7:0] <= 8'h0a;
        data_print[15:8] <= 8'h0d;
        data_print[23:16] <= hex_nibble_to_ascii(4'(priv_rval));
        data_print[31:24] <= hex_nibble_to_ascii(satp.as_satp.MODE);
        data_print[39:32] <= hex_nibble_to_ascii(4'(MMU_DISABLED));
        data_print[47:40] <= hex_nibble_to_ascii(4'(req_to_icache[0].valid));
        for (int unsigned j = 0; j < 10; j++) begin
          data_print[48+j*8+:8] <= hex_nibble_to_ascii(vaddr40[j*4+:4]);
        end
      end else begin
        data_print_en <= 0;
      end
    end
  end


endmodule
