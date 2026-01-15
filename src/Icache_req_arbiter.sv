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
    input pc_t  pc_from_st1_cur,

    // icacheへのreqとbootloaderへのreqを分別する.
    output cache_req_t req_to_icache[NUM_OF_REQ_TO_ICACHE],
    output bootloader_req_t req_to_bootloader,

    input int unsigned generation,
    input privilege_level_e priv_rval,
    input csr_reg_u satp,

    input logic stall_in

);

  // ---------------------------------------------------
  // stall用
  // ---------------------------------------------------
  // 一見icacheに対する入力はstallしなくても良い様に思えるが、icacheからのresをstallする手段が無いので,
  // ここでstallしておく必要がある.stallしないと,「btbやpredictorでstallされている命令」に対応する命令が,
  // icacheに入れられ,まだそれらがbtbやpredictorでstallしているうちにresponseがicacheから帰ってくる.
  // こうなると,ifqに入る前にcache_resを得ることになり,処理ができないのでデータが行き場所を失う.

  pc_t pc_from_st1;

  pc_t pc_from_st1_pending;
  logic is_pending;
  pc_t pc_from_st1_pending_next;
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    pc_from_st1_pending_next = pc_from_st1_pending;

    if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      pc_from_st1_pending_next = pc_from_st1_cur;
      is_pending_next = 1;
      pc_from_st1 = 0;
    end else if (stall_in) begin
      // 継続でstallした場合.
      pc_from_st1 = 0;
    end else if (is_pending) begin
      // stall終了時.
      pc_from_st1 = pc_from_st1_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      pc_from_st1 = pc_from_st1_cur;
    end
  end

  logic is_bootloader;


  // Icacheの入力.
  always_comb begin
    // 1サイクルのfetchの中には4つのwordが含まれる.
    // pc_from_st1.addrがdwアラインメントされているかどうかは未定.
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
    if (priv_rval == M_MODE && get_device_name(
            PADDR_WIDTH'(pc_from_st1.vaddr)
        ) == DN_BOOTLOADER) begin
      is_bootloader = 1;
    end else begin
      is_bootloader = 0;
    end

    if (pc_from_st1.valid) begin
      if (pc_from_st1.vaddr[2] != 0) begin
        // dwアラインメントされていない場合.
        if (is_bootloader) begin
          req_to_bootloader = '{
              valid: 1,
              id: pc_from_st1.first_instr_id,
              paddr: PADDR_WIDTH'(pc_from_st1.vaddr)
          };
        end else begin
          // bootloaderでない場合,普通のdramへのリクエストと解釈.
          for (int unsigned i = 0; i < 3; i++) begin
            req_to_icache[i] = '{
                valid: pc_from_st1.valid,
                id: pc_from_st1.first_instr_id + i,
                id_sub: 0,
                generation: generation,
                req_policy: READ_DOUBLE_WORD,
                cb_req_type: READ_REQ_FROM_UPPER,
                vaddr_dw_aligned: pc_from_st1.vaddr + i * 8 - 4,
                paddr_valid:
                priv_rval
                ==
                M_MODE
                ||
                satp.as_satp.MODE
                == 0 ||
                MMU_DISABLED
                ?
                1
                : 0,  // m_modeならアドレス変換を行わない.
                // m_modeなら元からpaddrが有効
                paddr_dw_aligned:
                PADDR_WIDTH
                '(
                pc_from_st1.vaddr
                ) +
                PADDR_WIDTH
                '(
                i * 8 - 4
                ),
                byte_in_dw_idx: 0,
                satp: satp,
                data: 0
            };
          end
        end

      end else begin
        // dwアラインメントされている場合.
        if (is_bootloader) begin
          req_to_bootloader = '{
              valid: 1,
              id: pc_from_st1.first_instr_id,
              paddr: PADDR_WIDTH'(pc_from_st1.vaddr)
          };
        end else begin
          for (int unsigned i = 0; i < 2; i++) begin
            req_to_icache[i] = '{
                valid: pc_from_st1.valid,
                id: pc_from_st1.first_instr_id + i,
                id_sub: 0,
                generation: generation,
                req_policy: READ_DOUBLE_WORD,
                cb_req_type: READ_REQ_FROM_UPPER,
                vaddr_dw_aligned: pc_from_st1.vaddr + i * 8,
                paddr_valid:
                priv_rval
                ==
                M_MODE
                ||
                satp.as_satp.MODE
                == 0 ||
                MMU_DISABLED
                ?
                1
                : 0,  // m_modeならアドレス変換を行わない.
                // m_modeなら元からpaddrが有効
                paddr_dw_aligned:
                PADDR_WIDTH
                '(
                pc_from_st1.vaddr
                ) +
                PADDR_WIDTH
                '(
                i * 8
                ),
                byte_in_dw_idx: 0,
                satp: satp,
                data: 0
            };
          end
        end
      end
    end

  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      pc_from_st1_pending <= '{default: 0};
      is_pending <= 0;
    end else begin
      pc_from_st1_pending <= pc_from_st1_pending_next;
      is_pending <= is_pending_next;
    end
  end


endmodule
