// ページウォーカー
//
// TODO: pteの属性で条件分岐.
//
//
// TODO: xv6を動かすために,aビットとdビットを無視している。
// 後で有効にする.



// ・変換元の仮想アドレス
// 38      30 29         21 20             12 11            0
// -----------------------------------------------------------
// |  VPN[2] |   VPN[1]    |     VPN[0]      |   page offset |
// -----------------------------------------------------------
//
// ・PTE
//  63 62 61 60     54 53     28 27     19 18     10 9   8 7 6 5 4 3 2 1 0
// ------------------------------------------------------------------------
//  |N| PBMT|Reserved |  PPN[2] |  PPN[1] |  PPN[0] | RSW |D|A|G|U|X|W|R|V| 
// ------------------------------------------------------------------------

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

`include "CSR_PROPS.svh"
`include "MemoryLayout.svh"

`include "CACHE_PROPS.svh"

module PageWalker
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import MemoryLayout::*;
  import CACHE_PROPS::*;
#(
    parameter int unsigned PW_IDX = 0
) (
    input logic clock,
    input logic reset,

    // tlbとのやり取り.
    input  tlb_req_t req_from_tlb,
    output tlb_res_t res_to_tlb,

    // キャッシュとのやり取り.
    output cache_req_t req_to_dcache,
    input cache_res_t res_from_dcache,
    input logic dcache_noroom,

    input int unsigned generation,

    output logic stall_out
);

  //
  localparam int unsigned DW_OFFSET_WIDTH = $clog2(DW_SIZE);

  localparam int unsigned DW_IN_MM_PORT_IDX_WIDTH = $clog2(NUM_OF_DW_IN_MM_PORT);

  localparam int unsigned DW_IN_MM_PORT_IDX_MSB = DW_IN_MM_PORT_IDX_WIDTH + DW_OFFSET_WIDTH - 1;
  localparam int unsigned DW_IN_MM_PORT_IDX_LSB = DW_OFFSET_WIDTH;

  // ---------------------------------------------
  // FSM用.
  // ---------------------------------------------
  // 普段はidle状態で,tlbからreqが来たらbefore_request_level2に移行する.
  // 最後のlevel0に対する応答に変換先のページアドレスが含まれている.
  typedef enum logic [2:0] {
    IDLE = 3'b000,
    BEFORE_REQEST_LEVEL2 = 3'b001,
    WAITING_RESPONSE_LEVEL2 = 3'b010,
    BEFORE_REQUEST_LEVEL1 = 3'b011,
    WAITING_RESPONSE_LEVEL1 = 3'b100,
    BEFORE_REQUEST_LEVEL0 = 3'b101,
    WAITING_RESPONSE_LEVEL0 = 3'b110
  } pw_state_e;
  pw_state_e state;
  pw_state_e state_next;


  // ----------------------------------------------
  // PTE
  // ----------------------------------------------
  typedef struct packed {
    logic        N;
    logic [1:0]  PBMT;
    logic [6:0]  reserved0;
    logic [25:0] PPN2;
    logic [8:0]  PPN1;
    logic [8:0]  PPN0;
    logic [1:0]  RSW;
    logic        D;
    logic        A;
    logic        G;
    logic        U;
    logic        X;
    logic        W;
    logic        R;
    logic        V;
  } PTE_t;

  // ----------------------------------------
  // req_from_tlb の内容を保存
  // ----------------------------------------
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] vaddr;
    // vaddrをvpnとpage_offsetに分解.
    logic [2:0][8:0] vpn;
    // 4KiByte
    logic [11:0] page_offset;
    csr_reg_u satp;
    int unsigned id;
    logic id_sub;
    int unsigned generation;
  } tlb_req_info_t;

  tlb_req_info_t tlb_req_info;
  tlb_req_info_t tlb_req_info_next;

  // cicularを避けるために必要.
  cache_req_t req_to_dcache_next;


  // pte
  logic [PADDR_WIDTH-1:0] level2_pte_paddr;
  logic [PADDR_WIDTH-1:0] level1_pte_paddr;
  logic [PADDR_WIDTH-1:0] level0_pte_paddr;

  logic [PADDR_WIDTH-1:0] level2_pte_paddr_next;
  logic [PADDR_WIDTH-1:0] level1_pte_paddr_next;
  logic [PADDR_WIDTH-1:0] level0_pte_paddr_next;


  function automatic logic [PADDR_WIDTH-1:0] to_mig_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] paddr);
    return {paddr[PADDR_WIDTH-1:4], 4'b0};
  endfunction



  always_comb begin

    PTE_t pte2 = '{default: 0};
    PTE_t pte1 = '{default: 0};
    PTE_t pte0 = '{default: 0};

    logic [PADDR_WIDTH-1:0] page_paddr = 0;

    level2_pte_paddr_next = level2_pte_paddr;
    level1_pte_paddr_next = level1_pte_paddr;
    level0_pte_paddr_next = level0_pte_paddr;

    // tlbからのリクエストを処理中の間保存しておく.
    tlb_req_info_next = tlb_req_info;

    state_next = state;

    // 出力.
    req_to_dcache_next = '{
        default: 0,
        req_policy: REQ_POLICY_NONE,
        cb_req_type: CB_REQ_TYPE_NONE
    };
    res_to_tlb = '{default: 0, pma_type: PMA_NONE};



    unique case (state)
      IDLE: begin
        if (req_from_tlb.valid) begin
          tlb_req_info_next = '{
              vaddr: req_from_tlb.vaddr,
              vpn: '{
                  req_from_tlb.vaddr[38:30],
                  req_from_tlb.vaddr[29:21],
                  req_from_tlb.vaddr[20:12]
              },
              page_offset: req_from_tlb.vaddr[11:0],
              satp: req_from_tlb.satp,
              id: req_from_tlb.id,
              id_sub: req_from_tlb.id_sub,
              generation: req_from_tlb.generation
          };
          state_next = BEFORE_REQEST_LEVEL2;
        end
      end

      BEFORE_REQEST_LEVEL2: begin
        if (!dcache_noroom) begin
          // 送信可能な場合.

          level2_pte_paddr_next = {
            tlb_req_info_next.satp.as_satp.PPN, tlb_req_info_next.vpn[2], 3'b000
          };
          req_to_dcache_next = '{
              valid: 1,
              id: PW_IDX,
              id_sub: 1,  // mmuからのリクエストはid_subが1.
              generation:
              0,  // dcacheに出したリクエストを破棄することは無いので使用しない.
              req_policy: READ_DOUBLE_WORD,
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_dw_aligned: 0,
              paddr_valid: 1,
              paddr_dw_aligned: level2_pte_paddr_next,
              byte_in_dw_idx: 0,
              satp: 0,
              data: 0
          };

          state_next = WAITING_RESPONSE_LEVEL2;
        end
      end

      WAITING_RESPONSE_LEVEL2: begin
        if (res_from_dcache.valid) begin
          // resの受取.
          pte2 = PTE_t'(res_from_dcache.data);

          // FOR DEBUG
          // if (tlb_req_info_next.vaddr == 39'h80205c30) begin
          //   $display("pte2 raw      = 0x%016h", pte2);
          //   $display("pte2 flags    : V=%0d R=%0d W=%0d X=%0d U=%0d G=%0d A=%0d D=%0d", pte2.V,
          //            pte2.R, pte2.W, pte2.X, pte2.U, pte2.G, pte2.A, pte2.D);
          //   $display("pte2 RSW      = 0x%0h", pte2.RSW);
          //   $display("pte2 PPN      : PPN2=0x%0h PPN1=0x%0h PPN0=0x%0h", pte2.PPN2, pte2.PPN1,
          //            pte2.PPN0);
          //   $display("pte2 N/PBMT   : N=%0d PBMT=0x%0h", pte2.N, pte2.PBMT);
          //   $display("pte2 reserved0= 0x%0h", pte2.reserved0);
          // end


          if (!pte2.V || (!pte2.R && pte2.W)) begin
            //page fault
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: 0,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 1,
                // pte_a: pte2.A,
                // pte_d: pte2.D
                pte_a:
                0,
                pte_d: 0
            };
            state_next = IDLE;
          end else if (pte2.V && (pte2.R || pte2.X)) begin
            // giga pageの場合.(リーフ)
            page_paddr = {
              pte2.PPN2,
              tlb_req_info_next.vpn[1],
              tlb_req_info_next.vpn[0],
              tlb_req_info_next.page_offset
            };
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: page_paddr,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 0,
                // pte_a: pte2.A,
                // pte_d: pte2.D
                pte_a:
                1,
                pte_d: 1
            };
            state_next = IDLE;
          end else begin
            // giga pageで無い場合(非リーフ.)
            level1_pte_paddr_next = {
              {pte2.PPN2, pte2.PPN1, pte2.PPN0}, tlb_req_info_next.vpn[1], 3'b000
            };
            // 状態遷移
            state_next = BEFORE_REQUEST_LEVEL1;
          end

        end
      end

      BEFORE_REQUEST_LEVEL1: begin
        if (!dcache_noroom) begin
          req_to_dcache_next = '{
              valid: 1,
              id: PW_IDX,
              id_sub: 1,  // mmuからのリクエストはid_subが1.
              generation: 0,
              req_policy: READ_DOUBLE_WORD,
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_dw_aligned: 0,
              paddr_valid: 1,
              paddr_dw_aligned: level1_pte_paddr,
              byte_in_dw_idx: 0,
              satp: 0,
              data: 0
          };

          state_next = WAITING_RESPONSE_LEVEL1;
        end
      end

      WAITING_RESPONSE_LEVEL1: begin
        if (res_from_dcache.valid) begin
          // resの受取.
          pte1 = PTE_t'(res_from_dcache.data);

          // FOR DEBUG
          // if (tlb_req_info_next.vaddr == 39'h80205c30) begin
          //   $display("pte1 raw      = 0x%016h", pte1);
          //   $display("pte1 flags    : V=%0d R=%0d W=%0d X=%0d U=%0d G=%0d A=%0d D=%0d", pte1.V,
          //            pte1.R, pte1.W, pte1.X, pte1.U, pte1.G, pte1.A, pte1.D);
          //   $display("pte1 RSW      = 0x%0h", pte1.RSW);
          //   $display("pte1 PPN      : PPN2=0x%0h PPN1=0x%0h PPN0=0x%0h", pte1.PPN2, pte1.PPN1,
          //            pte1.PPN0);
          //   $display("pte1 N/PBMT   : N=%0d PBMT=0x%0h", pte1.N, pte1.PBMT);
          //   $display("pte1 reserved0= 0x%0h", pte1.reserved0);
          // end

          // リーフ,非リーフ,page_faultに場合分け.
          if (!pte1.V || (!pte1.R && pte1.W)) begin
            // page fault
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: 0,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 1,
                // pte_a: pte1.A,
                // pte_d: pte1.D
                pte_a:
                0,
                pte_d: 0
            };
            state_next = IDLE;
          end else if (pte1.V && (pte1.R || pte1.X)) begin
            // mega pageの場合.
            page_paddr = {
              pte1.PPN2, pte1.PPN1, tlb_req_info_next.vpn[0], tlb_req_info_next.page_offset
            };
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: page_paddr,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 0,
                // pte_a: pte1.A,
                // pte_d: pte1.D
                pte_a:
                1,
                pte_d: 1
            };
            state_next = IDLE;
          end else begin
            // mega pageで無い場合.(非リーフ)
            level0_pte_paddr_next = {
              {pte1.PPN2, pte1.PPN1, pte1.PPN0}, tlb_req_info_next.vpn[0], 3'b000
            };
            // 状態遷移
            state_next = BEFORE_REQUEST_LEVEL0;
          end



        end
      end

      BEFORE_REQUEST_LEVEL0: begin
        if (!dcache_noroom) begin
          req_to_dcache_next = '{
              valid: 1,
              id: PW_IDX,
              id_sub: 1,  // mmuからのリクエストはid_subが1.
              generation: 0,
              req_policy: READ_DOUBLE_WORD,
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_dw_aligned: 0,
              paddr_valid: 1,
              paddr_dw_aligned: level0_pte_paddr,
              byte_in_dw_idx: 0,
              satp: 0,
              data: 0
          };
          state_next = WAITING_RESPONSE_LEVEL0;
        end
      end

      WAITING_RESPONSE_LEVEL0: begin
        if (res_from_dcache.valid) begin
          pte0 = PTE_t'(res_from_dcache.data);

          // FOR DEBUG
          // if (tlb_req_info_next.vaddr == 39'h80205c30) begin
          //   $display("pte0 raw      = 0x%016h", pte0);
          //   $display("pte0 flags    : V=%0d R=%0d W=%0d X=%0d U=%0d G=%0d A=%0d D=%0d", pte0.V,
          //            pte0.R, pte0.W, pte0.X, pte0.U, pte0.G, pte0.A, pte0.D);
          //   $display("pte0 RSW      = 0x%0h", pte0.RSW);
          //   $display("pte0 PPN      : PPN2=0x%0h PPN1=0x%0h PPN0=0x%0h", pte0.PPN2, pte0.PPN1,
          //            pte0.PPN0);
          //   $display("pte0 N/PBMT   : N=%0d PBMT=0x%0h", pte0.N, pte0.PBMT);
          //   $display("pte0 reserved0= 0x%0h", pte0.reserved0);
          // end


          if (pte0.V && (pte0.R || pte0.X)) begin
            page_paddr = {{pte0.PPN2, pte0.PPN1, pte0.PPN0}, tlb_req_info_next.page_offset};
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: page_paddr,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 0,
                // pte_a: pte0.A,
                // pte_d: pte0.D
                pte_a:
                1,
                pte_d: 1
            };
            state_next = IDLE;
          end else begin
            res_to_tlb = '{
                valid: 1,
                id: tlb_req_info_next.id,
                id_sub: tlb_req_info_next.id_sub,
                generation: tlb_req_info_next.generation,
                paddr: 0,
                vaddr: tlb_req_info_next.vaddr,
                satp: tlb_req_info_next.satp,
                pma_type: PMA_NONE,
                is_page_fault: 1,
                // pte_a: pte0.A,
                // pte_d: pte0.D
                pte_a:
                1,
                pte_d: 1
            };
            state_next = IDLE;
          end
        end
      end

    endcase

    // stall
    stall_out = state_next != IDLE;
  end

  // for debug 
  int fp;
  initial begin
    fp = $fopen($sformatf("./log/pwlog%0d.txt", PW_IDX), "w");
  end

  // always_ff @(posedge clock, posedge reset) begin
  //   if (res_to_tlb.valid && res_to_tlb.vaddr == 39'h3fffffbff8) begin
  //     // res_to_tlb : tlb_res_t
  //     $display("[LOG] res_to_tlb valid=%0d id=%0d id_sub=%0d gen=%0d", res_to_tlb.valid,
  //              res_to_tlb.id, res_to_tlb.id_sub, res_to_tlb.generation);

  //     $display("[LOG] res_to_tlb vaddr=0x%0h paddr=0x%0h satp=0x%0h", res_to_tlb.vaddr,
  //              res_to_tlb.paddr, res_to_tlb.satp);

  //     $display("[LOG] res_to_tlb pma_type=%0d is_page_fault=%0d pte_a=%0d pte_d=%0d",
  //              res_to_tlb.pma_type, res_to_tlb.is_page_fault, res_to_tlb.pte_a, res_to_tlb.pte_d);

  //   end
  // end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      state <= IDLE;

      // 
      tlb_req_info <= '{default: 0};
      req_to_dcache <= '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};

      // pte paddr
      level2_pte_paddr <= 0;
      level1_pte_paddr <= 0;
      level0_pte_paddr <= 0;
    end else begin
      state <= state_next;

      // 
      tlb_req_info <= tlb_req_info_next;
      req_to_dcache <= req_to_dcache_next;

      // pte_paddr
      level2_pte_paddr <= level2_pte_paddr_next;
      level1_pte_paddr <= level1_pte_paddr_next;
      level0_pte_paddr <= level0_pte_paddr_next;

      if (res_to_tlb.valid) begin
`ifdef PCGENLOG_EN
        $fdisplay(
            fp,
            "[LOG] res_to_tlb: id=%0d id_sub=%0d gen=%0d vaddr=%h paddr=%h asid=%0d pma=%0d pf=%0d A=%0d D=%0d",
            res_to_tlb.id, res_to_tlb.id_sub, res_to_tlb.generation, res_to_tlb.vaddr,
            res_to_tlb.paddr, res_to_tlb.asid, res_to_tlb.pma_type, res_to_tlb.is_page_fault,
            res_to_tlb.pte_a, res_to_tlb.pte_d);
`endif
      end
    end
  end
endmodule
