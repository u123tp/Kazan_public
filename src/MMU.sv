// MMU Memory Management Unit
// Sv39 を用いてアドレスを変換する.
// 


`include "HART_DEFS.svh"
`include "CSR_PROPS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"


module MMU
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import CACHE_PROPS::*;
#(
) (
    input logic clock,
    input logic reset,

    // ITLB用
    itlb_if.host itlb_port,

    // DTLB用
    dtlb_if.host dtlb_port,

    // pw <=> dキャッシュ のやり取り.
    output cache_req_t req_to_dcache[NUM_OF_PW],
    input cache_res_t res_from_dcache_tmp[NUM_OF_LD_EXE],
    input logic dcache_noroom,

    input int unsigned generation,

    input logic flush_tlb
);

  // -------------------------------------------------
  // リクエストポートのパラメータ.
  // -------------------------------------------------
  localparam int unsigned NUM_OF_REQ_FROM_ITLB = 1;
  localparam int unsigned NUM_OF_REQ_FROM_DTLB = 1;
  localparam int unsigned NUM_OF_REQ_TO_L2TLB = NUM_OF_REQ_FROM_ITLB + NUM_OF_REQ_FROM_DTLB;
  localparam int unsigned NUM_OF_REQ_FROM_L2TLB = NUM_OF_PW;

  // ------------------------------------------------
  // レスポンスポートのパラメータ
  // ------------------------------------------------
  localparam int unsigned NUM_OF_RES_TO_L2TLB = NUM_OF_PW;
  localparam int unsigned NUM_OF_RES_FROM_L2TLB = 2;
  localparam int unsigned NUM_OF_RES_TO_DTLB = NUM_OF_RES_FROM_L2TLB;
  localparam int unsigned NUM_OF_RES_TO_ITLB = NUM_OF_RES_FROM_L2TLB;



  // ------------------------------------------------
  // itlb <=> l2tlb
  // ------------------------------------------------
  tlb_req_t req_from_itlb_to_l2tlb[NUM_OF_REQ_FROM_ITLB];
  tlb_res_t res_from_l2tlb_to_itlb[NUM_OF_RES_TO_ITLB];

  // ------------------------------------------------
  // dtlb <=> l2tlb
  // ------------------------------------------------
  tlb_req_t req_from_dtlb_to_l2tlb[NUM_OF_REQ_FROM_DTLB];
  tlb_res_t res_from_l2tlb_to_dtlb[NUM_OF_RES_TO_DTLB];

  // ----------------------------------------
  // l2tlb <=> pw
  // ----------------------------------------
  tlb_req_t req_from_l2tlb_to_pw[NUM_OF_PW];
  tlb_res_t res_from_pw_to_l2tlb[NUM_OF_PW];

  // -----------------------------------------------
  // dtlb,itlb <=> l2tlb
  // ------------------------------------------------
  // tlb_idについて,L1ITLBはそのまま,L1ITLBはL
  tlb_req_t req_from_l1tlb_to_l2tlb[NUM_OF_REQ_TO_L2TLB];
  tlb_res_t res_from_l2tlb_to_l1tlb[NUM_OF_RES_FROM_L2TLB];

  // ---------------------------------------------
  // stall信号
  // ---------------------------------------------
  logic stall_req_to_pw[NUM_OF_PW];

  logic stall_req_to_l2tlb;
  logic stall_req_from_itlb[NUM_OF_REQ_FROM_ITLB];
  logic stall_req_from_dtlb[NUM_OF_REQ_FROM_DTLB];

  always_comb begin
    stall_req_from_itlb = '{default: stall_req_to_l2tlb};
    stall_req_from_dtlb = '{default: stall_req_to_l2tlb};
  end


  // ------------------------------------------------------------
  // sub_idの設定
  // -------------------------------------------------------------
  tlb_req_t req_to_itlb_from_icache[NUM_OF_REQ_TO_ITLB];
  tlb_req_t req_to_dtlb_from_dcache[NUM_OF_REQ_TO_DTLB];
  always_comb begin
    // itlbがid_sub==0,dtlbがid_sub==1を用いる.

    for (int unsigned i = 0; i < NUM_OF_REQ_TO_ITLB; i++) begin
      req_to_itlb_from_icache[i] = itlb_port.req[i];
      req_to_itlb_from_icache[i].id_sub = 0;
    end

    for (int unsigned i = 0; i < NUM_OF_REQ_TO_DTLB; i++) begin
      req_to_dtlb_from_dcache[i] = dtlb_port.req[i];
      req_to_dtlb_from_dcache[i].id_sub = 1;
    end
  end


  // L1 ITLB
  TLB #(
      .NUM_OF_WAYS(NUM_OF_ITLB_WAYS),
      .NUM_OF_SET(NUM_OF_ITLB_SETS),
      .NUM_OF_REQ_IN(NUM_OF_REQ_TO_ITLB),
      .NUM_OF_RES_OUT(NUM_OF_RES_FROM_ITLB),
      .NUM_OF_REQ_OUT(NUM_OF_REQ_FROM_ITLB),
      .NUM_OF_RES_IN(NUM_OF_RES_TO_ITLB),
      .TLB_ID(0)
  ) l1itlb (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_itlb_from_icache),
      .res_out(itlb_port.res),
      .req_out(req_from_itlb_to_l2tlb),
      .res_in(res_from_l2tlb_to_itlb),
      .stall_in(stall_req_from_itlb),
      .flush_tlb(flush_tlb),
      .stall_out(itlb_port.stall_req_to_itlb)
  );

  // L1 DTLB
  TLB #(
      .NUM_OF_WAYS(NUM_OF_DTLB_WAYS),
      .NUM_OF_SET(NUM_OF_DTLB_SETS),
      .NUM_OF_REQ_IN(NUM_OF_REQ_TO_DTLB),
      .NUM_OF_RES_OUT(NUM_OF_RES_FROM_DTLB),
      .NUM_OF_REQ_OUT(NUM_OF_REQ_FROM_DTLB),
      .NUM_OF_RES_IN(NUM_OF_RES_TO_DTLB),
      .TLB_ID(1)
  ) l1dtlb (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_dtlb_from_dcache),
      .res_out(dtlb_port.res),
      .req_out(req_from_dtlb_to_l2tlb),
      .res_in(res_from_l2tlb_to_dtlb),
      .stall_in(stall_req_from_dtlb),
      .flush_tlb(flush_tlb),
      .stall_out(dtlb_port.stall_req_to_dtlb)
  );


  // L2 TLB
  TLB #(
      .NUM_OF_WAYS(8),
      .NUM_OF_SET(256),
      .NUM_OF_REQ_IN(NUM_OF_REQ_TO_L2TLB),
      .NUM_OF_RES_OUT(NUM_OF_RES_FROM_L2TLB),
      .NUM_OF_REQ_OUT(NUM_OF_REQ_FROM_L2TLB),
      .NUM_OF_RES_IN(NUM_OF_RES_TO_L2TLB),
      .TLB_ID(2)
  ) l2tlb (
      .clock(clock),
      .reset(reset),
      .req_in(req_from_l1tlb_to_l2tlb),
      .res_out(res_from_l2tlb_to_l1tlb),
      .req_out(req_from_l2tlb_to_pw),
      .res_in(res_from_pw_to_l2tlb),
      .stall_in(stall_req_to_pw),
      .flush_tlb(flush_tlb),
      .stall_out(stall_req_to_l2tlb)
  );

  // PW
  genvar pw_idx;
  cache_res_t res_from_dcache[NUM_OF_PW];
  generate
    for (pw_idx = 0; pw_idx < NUM_OF_PW; pw_idx++) begin : gen_pw
      PageWalker #(
          .PW_IDX(pw_idx)
      ) pw (
          .clock(clock),
          .reset(reset),
          .req_from_tlb(req_from_l2tlb_to_pw[pw_idx]),
          .res_to_tlb(res_from_pw_to_l2tlb[pw_idx]),
          .req_to_dcache(req_to_dcache[pw_idx]),
          .res_from_dcache(res_from_dcache[pw_idx]),
          .dcache_noroom(dcache_noroom),
          .generation(generation),
          .stall_out(stall_req_to_pw[pw_idx])
      );
    end
  endgenerate

  // itlb,dtlbとl2tlbの間のやり取りで,itlbとdtlbを調停する.
  always_comb begin
    // itlb,dtlb => l2tlb

    // itlb => l2tlb
    for (int unsigned i = 0; i < NUM_OF_REQ_FROM_ITLB; i++) begin
      req_from_l1tlb_to_l2tlb[i] = '{
          valid: req_from_itlb_to_l2tlb[i].valid,
          id: req_from_itlb_to_l2tlb[i].id,
          id_sub: 0,
          generation: req_from_itlb_to_l2tlb[i].generation,
          satp: req_from_itlb_to_l2tlb[i].satp,
          vaddr: req_from_itlb_to_l2tlb[i].vaddr
      };
    end

    // dtlb => l2tlb
    for (int unsigned i = 0; i < NUM_OF_REQ_FROM_DTLB; i++) begin
      req_from_l1tlb_to_l2tlb[i+NUM_OF_REQ_FROM_ITLB] = '{
          valid: req_from_dtlb_to_l2tlb[i].valid,
          id: req_from_dtlb_to_l2tlb[i].id,
          id_sub: 1,
          generation: req_from_dtlb_to_l2tlb[i].generation,
          satp: req_from_dtlb_to_l2tlb[i].satp,
          vaddr: req_from_dtlb_to_l2tlb[i].vaddr
      };
    end
  end

  always_comb begin
    // l2tlb => itlb,dtlb
    int unsigned itlb_counter = 0;
    int unsigned dtlb_counter = 0;
    res_from_l2tlb_to_itlb = '{default: 0};
    res_from_l2tlb_to_dtlb = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_RES_FROM_L2TLB; i++) begin
      if (res_from_l2tlb_to_l1tlb[i].valid) begin
        if (res_from_l2tlb_to_l1tlb[i].id_sub == 0) begin
          // => itlb
          res_from_l2tlb_to_itlb[itlb_counter] = res_from_l2tlb_to_l1tlb[i];
          itlb_counter++;
        end else if (res_from_l2tlb_to_l1tlb[i].id_sub == 1) begin
          // => dtlb
          res_from_l2tlb_to_dtlb[dtlb_counter] = res_from_l2tlb_to_l1tlb[i];
          dtlb_counter++;
        end
      end
    end
  end

  // PW <= DCACHE
  always_comb begin
    // 初期化
    res_from_dcache = '{default: 0};
    // DCACHEからの返答(res_from_dcache_tmp)をres_from_dcacheに分配する.
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      if (res_from_dcache_tmp[i].valid) begin
        res_from_dcache[res_from_dcache_tmp[i].id] = res_from_dcache_tmp[i];
      end
    end
  end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
    end else begin
    end
  end

endmodule
