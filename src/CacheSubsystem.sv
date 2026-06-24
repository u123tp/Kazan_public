`timescale 1ns / 1ps
// はじめはL2Cacheも実装していたが,リソースの制約から削除した
// 
//

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CACHE_PROPS.svh"
`include "CSR_PROPS.svh"
`include "MemoryLayout.svh"


module CacheSubsystem
  import HART_DEFS::*;
  import CSR_PROPS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CACHE_PROPS::*;
  import MemoryLayout::*;
#(

    // キャッシュラインのサイズ（単位はByte）
    // parameter int unsigned CL_SIZE = 64,

    // parameter int unsigned MIG_PORT_WIDTH = 16
) (
    input logic clock,
    input logic reset,

    // instruction cache subsystem用
    input  cache_req128_t req_to_icache  [  NUM_OF_REQ_TO_ICACHE],
    output cache_res128_t res_from_icache[NUM_OF_RES_FROM_ICACHE],

    // data cache subsystem 用
    input  cache_req64_t req_to_dcache  [  NUM_OF_REQ_TO_DCACHE],
    output cache_res64_t res_from_dcache[NUM_OF_RES_FROM_DCACHE],

    // tlbとの接続
    itlb_if.client itlb_port,

    // MainMemoryとの接続.
    mm_icache_if.client mm_icache_port,
    mm_dcache_if.client mm_dcache_port,

    // stall
    output logic stall_req_to_icache,
    output logic stall_req_to_dcache,

    // icache,dcacheを書き戻ししてinvalidate
    // icacheは書き戻ししないので衝突は無い.
    input  logic invalidate_icache,
    output logic invalidate_icache_done,

    input  logic invalidate_dcache,
    output logic invalidate_dcache_done,

    input  logic invalidate_l2cache,
    output logic invalidate_l2cache_done,

    output logic data_print_en,
    output logic [255:0] data_print
);



  // icache, dcache, l2cache のresやreqの数は互いに相互依存している.
  // 例えば,l2cacheのcbに対するread_reqの数は,icacheとdcacheのres_inの数の最小値である.
  // 逆に言えば,icacheのres_inの数やdcacheのres_inの数は,l2cacheのcb_read_reqの数以上である.
  // 基本的にreqはavailqが緩衝バッファとしての役割を果たすが,resはそのようなものが無いからである.
  // いや,isがあるか.

  // ------------------------------------------------
  // Cacheのreq_inとreq_outのパラメータ
  // ------------------------------------------------
  // NUM_OF_REQ_TO_ICACHE,NUM_OF_REQ_TO_DCACHEは外部から与えられる.
  localparam int unsigned NUM_OF_ICACHE_REQ_IN = NUM_OF_REQ_TO_ICACHE;  // 3
  localparam int unsigned NUM_OF_DCACHE_REQ_IN = NUM_OF_REQ_TO_DCACHE;  // 3

  // ------------------------------------------------
  // cacheのres_inとres_outのパラメータ
  // ------------------------------------------------
  // 最後の*2はdramからの返却とbootloaderからの返却が有るからそれを考慮して.
  // localparam int unsigned NUM_OF_L2CACHE_RES_IN = NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE;
  // // TODO: あとで1に変える.
  // localparam int unsigned NUM_OF_L2CACHE_RES_OUT = 1;
  // localparam int unsigned NUM_OF_ICACHE_RES_IN = NUM_OF_L2CACHE_RES_OUT;
  // localparam int unsigned NUM_OF_DCACHE_RES_IN = NUM_OF_L2CACHE_RES_OUT;
  // 今は2でとりあえず.
  localparam int unsigned NUM_OF_ICACHE_REQ_OUT = NUM_OF_REQ_FROM_ICACHE_TO_MM;
  localparam int unsigned NUM_OF_DCACHE_REQ_OUT = NUM_OF_REQ_FROM_DCACHE_TO_MM;
  localparam int unsigned NUM_OF_ICACHE_RES_IN = NUM_OF_ICACHE_REQ_OUT;
  localparam int unsigned NUM_OF_DCACHE_RES_IN = NUM_OF_DCACHE_REQ_OUT;
  localparam int unsigned NUM_OF_ICACHE_RES_OUT = NUM_OF_RES_FROM_ICACHE;
  localparam int unsigned NUM_OF_DCACHE_RES_OUT = NUM_OF_RES_FROM_DCACHE;



  // ------------------------------------------------
  // 各キャッシュのサイズパラメータ
  // ------------------------------------------------
  // TODO* ページサイズとcl,setの関係を注意.
  // まあdcacheは実質的にviptでなくpiptなのでページサイズ超えても問題は無いかも?
  localparam int unsigned NUM_OF_ICACHE_WAYS = 1;
  localparam int unsigned NUM_OF_ICACHE_SETS = 128;
  localparam int unsigned ICACHE_CL_SIZE = 32;

  localparam int unsigned NUM_OF_DCACHE_WAYS = 1;
  localparam int unsigned NUM_OF_DCACHE_SETS = 128;
  localparam int unsigned DCACHE_CL_SIZE = 32;


  // ---------------------------------------------------
  // icache
  // ---------------------------------------------------
  // viptであるので,tlbをcacheに入れる前に通す必要が無い.

  cache_req128_t req_from_icache[NUM_OF_ICACHE_REQ_OUT];
  cache_res128_t res_to_icache[NUM_OF_ICACHE_RES_IN];
  logic stall_req_to_itlb;


  // ----------------------------------------------------
  // dcache
  // -----------------------------------------------------

  cache_req64_t req_from_dcache[NUM_OF_DCACHE_REQ_OUT];
  cache_res64_t res_to_dcache[NUM_OF_DCACHE_RES_IN];
  logic stall_req_to_dtlb;



  // --------------------
  // stall 割当
  // --------------------
  logic stall_req_from_icache;
  logic stall_req_from_dcache;

  // stallの配線.
  always_comb begin
    stall_req_from_icache = !mm_icache_port.ready;
    stall_req_from_dcache = !mm_dcache_port.ready;
  end


  // ------------------------------------------------------------------------------
  // icache, dcache => mm
  // ------------------------------------------------------------------------------
  always_comb begin
    mm_icache_port.req = '{default: 0};
    mm_dcache_port.req = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_ICACHE_REQ_OUT; i++) begin
      if (req_from_icache[i].valid) begin
        if (is_read_policy(req_from_icache[i].req_policy)) begin
          // read req
          mm_icache_port.req[i] = '{
              valid: 1,
              id: req_from_icache[i].id,
              id_sub: 0,
              paddr_mig_aligned: req_from_icache[i].paddr_db_aligned,
              is_write: is_write_policy(req_from_icache[i].req_policy),
              data: req_from_icache[i].data
          };
        end else begin
          // writ req
          mm_icache_port.req[i] = '{
              valid: 1,
              id: 0,  // 戻って来ないしidは不要
              id_sub: 0,
              paddr_mig_aligned: req_from_icache[i].paddr_db_aligned,
              is_write: 1,
              data: req_from_icache[i].data
          };
        end
      end
    end

    for (int unsigned i = 0; i < NUM_OF_DCACHE_REQ_OUT; i++) begin
      if (req_from_dcache[i].valid) begin
        if (is_read_policy(req_from_dcache[i].req_policy)) begin
          // read req
          mm_dcache_port.req[i] = '{
              valid: 1,
              id: req_from_dcache[i].id,
              id_sub: 0,
              paddr_mig_aligned: req_from_dcache[i].paddr_db_aligned,
              is_write: is_write_policy(req_from_dcache[i].req_policy),
              data: req_from_dcache[i].data
          };
        end else begin
          // writ req
          mm_dcache_port.req[i] = '{
              valid: 1,
              id: 0,  // 戻って来ないしidは不要
              id_sub: 0,
              paddr_mig_aligned: req_from_dcache[i].paddr_db_aligned,
              is_write: 1,
              data: req_from_dcache[i].data
          };
        end
      end
    end

  end



  // always_comb begin
  //   int unsigned mm_port_counter = 0;
  //   mm_port.req = '{default: 0};

  //   // icache => mm
  //   for (int unsigned i = 0; i < NUM_OF_ICACHE_REQ_OUT; i++) begin
  //     if (req_from_icache[i].valid) begin
  //       if (is_read_policy(req_from_icache[i].req_policy)) begin
  //         // read
  //         mm_port.req[mm_port_counter] = '{
  //             valid: 1,
  //             id: req_from_icache[i].id,
  //             id_sub: 0,
  //             paddr_mig_aligned: req_from_icache[i].paddr_db_aligned,
  //             is_write: 0,
  //             data: 0
  //         };
  //         // mm_port.req[mm_port_counter].id_sub = 0;
  //         mm_port_counter++;
  //       end else begin
  //         // if(req_from_icache[i].paddr_db_aligned == 56'h80801000 && req_from_icache[i].data == 64'h80800000)begin
  //         //   $display("[LOG][Cache_subsystem.sv] 80800000 is from_icache");
  //         // end
  //         // write
  //         mm_port.req[mm_port_counter] = '{
  //             valid: 1,
  //             id: 0,  // 戻って来ないしidは不要
  //             id_sub: 0,
  //             paddr_mig_aligned: req_from_icache[i].paddr_db_aligned,
  //             is_write: 1,
  //             data: req_from_icache[i].data
  //         };
  //         mm_port_counter++;
  //       end
  //     end
  //   end

  //   // dcache => mm
  //   for (int unsigned i = 0; i < NUM_OF_DCACHE_REQ_OUT; i++) begin
  //     if (req_from_dcache[i].valid) begin
  //       if (is_read_policy(req_from_dcache[i].req_policy)) begin
  //         // read
  //         mm_port.req[mm_port_counter] = '{
  //             valid: 1,
  //             id: req_from_dcache[i].id,
  //             id_sub: 1,  // dcacheからなので
  //             paddr_mig_aligned: req_from_dcache[i].paddr_db_aligned,
  //             is_write: 0,
  //             data: 0
  //         };
  //         mm_port_counter++;
  //       end else begin
  //         // write
  //         // if (req_from_dcache[i].paddr_db_aligned == 56'h80001000) begin
  //         //   $display("[LOG][CacheSubsystem.sv] 0x%0h is written to 0x80001000",
  //         //            req_from_dcache[i].data);
  //         // end
  //         mm_port.req[mm_port_counter] = '{
  //             valid: 1,
  //             id: 0,  // 戻って来ないしidは不要
  //             id_sub: 1,
  //             paddr_mig_aligned: req_from_dcache[i].paddr_db_aligned,
  //             is_write: 1,
  //             data: req_from_dcache[i].data
  //         };
  //         mm_port_counter++;
  //       end
  //     end
  //   end


  // end


  // ------------------------------------------------------------------------------ 
  // mm => icache, dcache 
  // ------------------------------------------------------------------------------

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_ICACHE_RES_IN; i++) begin
      res_to_icache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end

    for (int unsigned i = 0; i < NUM_OF_DCACHE_REQ_OUT; i++) begin
      res_to_dcache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end


    for (int unsigned i = 0; i < NUM_OF_ICACHE_RES_IN; i++) begin
      if (mm_icache_port.res[i].valid) begin
        res_to_icache[i] = '{
            valid: 1,
            id: mm_icache_port.res[i].id,
            id_sub: 0,
            generation: 0,
            req_policy: WRITE_QUAD_WORD,
            cb_req_type: WRITE_UPDATE,
            vaddr_db_aligned: 0,
            paddr_db_aligned: mm_icache_port.res[i].paddr_mig_aligned,
            byte_in_db_idx: 0,
            data: mm_icache_port.res[i].data,
            is_page_fault: 0,
            is_access_fault: 0
        };
      end
    end

    for (int unsigned i = 0; i < NUM_OF_DCACHE_RES_IN; i++) begin
      if (mm_dcache_port.res[i].valid) begin
        res_to_dcache[i] = '{
            valid: 1,
            id: mm_dcache_port.res[i].id,
            id_sub: 0,
            generation: 0,
            req_policy: WRITE_DOUBLE_WORD,
            cb_req_type: WRITE_UPDATE,
            vaddr_db_aligned: 0,
            paddr_db_aligned: mm_dcache_port.res[i].paddr_mig_aligned,
            byte_in_db_idx: 0,
            data: mm_dcache_port.res[i].data,
            is_page_fault: 0,
            is_access_fault: 0
        };
      end
    end
  end


  // always_comb begin
  //   int unsigned res_to_icache_counter = 0;
  //   int unsigned res_to_dcache_counter = 0;
  //   // 初期化
  //   for (int unsigned i = 0; i < NUM_OF_ICACHE_RES_IN; i++) begin
  //     res_to_icache[i] = '{
  //         default: 0,
  //         req_policy: REQ_POLICY_NONE,
  //         cb_req_type: CB_REQ_TYPE_NONE
  //     };
  //   end
  //   for (int unsigned i = 0; i < NUM_OF_DCACHE_RES_IN; i++) begin
  //     res_to_dcache[i] = '{
  //         default: 0,
  //         req_policy: REQ_POLICY_NONE,
  //         cb_req_type: CB_REQ_TYPE_NONE
  //     };
  //   end

  //   for (int unsigned i = 0; i < NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE; i++) begin
  //     if (mm_port.res[i].valid) begin
  //       if (mm_port.res[i].id_sub == 0) begin
  //         // icacheへのリクエストの返却
  //         res_to_icache[res_to_icache_counter] = '{
  //             valid: 1,
  //             id: mm_port.res[i].id,
  //             id_sub: 0,
  //             generation: 0,
  //             req_policy: WRITE_DOUBLE_WORD,
  //             cb_req_type: WRITE_UPDATE,
  //             vaddr_dw_aligned: 0,
  //             paddr_db_aligned: mm_port.res[i].paddr_mig_aligned,
  //             byte_in_dw_idx: 0,
  //             data: mm_port.res[i].data,
  //             is_page_fault: 0,
  //             is_access_fault: 0
  //         };
  //         res_to_icache_counter++;
  //       end else if (mm_port.res[i].id_sub == 1) begin
  //         // dcacheへのリクエストの返却.
  //         // res_to_dcache[res_to_dcache_counter] = mm_port.res[i];
  //         // res_to_dcache_counter++;
  //         res_to_dcache[res_to_dcache_counter] = '{
  //             valid: 1,
  //             id: mm_port.res[i].id,
  //             id_sub: 0,
  //             generation: 0,
  //             req_policy: WRITE_DOUBLE_WORD,
  //             cb_req_type: WRITE_UPDATE,
  //             vaddr_dw_aligned: 0,
  //             paddr_db_aligned: mm_port.res[i].paddr_mig_aligned,
  //             byte_in_dw_idx: 0,
  //             data: mm_port.res[i].data,
  //             is_page_fault: 0,
  //             is_access_fault: 0
  //         };
  //         res_to_dcache_counter++;
  //       end
  //     end
  //   end

  // end

  // -----------------------------
  // icache
  // ------------------------------
  Cache #(
      .NUM_OF_REQ_IN(NUM_OF_ICACHE_REQ_IN),
      .NUM_OF_RES_OUT(NUM_OF_ICACHE_RES_OUT),
      .NUM_OF_REQ_OUT(NUM_OF_ICACHE_REQ_OUT),
      .NUM_OF_RES_IN(NUM_OF_ICACHE_RES_IN),
      .NUM_OF_CB_READ_REQ(NUM_OF_ICACHE_CB_READ_REQ),
      .NUM_OF_CB_WRITE_REQ(NUM_OF_ICACHE_CB_WRITE_REQ),
      .NUM_OF_WAYS(NUM_OF_ICACHE_WAYS),
      .NUM_OF_SETS(NUM_OF_ICACHE_SETS),
      .CL_SIZE(ICACHE_CL_SIZE),
      .REQ_TO_TLB(NUM_OF_REQ_TO_ITLB),
      .RES_FROM_TLB(NUM_OF_RES_FROM_ITLB),
      .cache_req_t(cache_req128_t),
      .cache_res_t(cache_res128_t),
      .DATA_BULK_SIZE(16),
      .CACHE_CAT(1)
  ) icache (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_icache),
      .res_out(res_from_icache),
      .req_out(req_from_icache),
      .res_in(res_to_icache),
      .req_to_tlb(itlb_port.req),
      .res_from_tlb(itlb_port.res),
      .stall_req_to_tlb(itlb_port.stall_req_to_itlb),
      // icacheから出されるstall信号.
      .stall_req_in(stall_req_to_icache),
      // icacheに入力されるstall信号.
      .stall_req_out(stall_req_from_icache),
      .invalidate_all_sig(invalidate_icache),
      .invalidate_all_done_sig(invalidate_icache_done),

      .data_print_en(data_print_en),
      .data_print(data_print)
  );


  // -------------------------------
  // dcache
  // --------------------------------
  // dcacheはdtlbに接続しない(LSUがdtlbに接続する)ため,ダミー
  tlb_req_t req_to_dtlb_dummy[NUM_OF_REQ_TO_DTLB];
  tlb_res_t res_from_dtlb_dummy[NUM_OF_RES_FROM_DTLB];
  logic stall_req_to_dtlb_dummy;

  logic data_print_en_fake;
  logic [255:0] data_print_fake;
  always_comb begin
    // tlbからの返却は全部0にしておく.
    res_from_dtlb_dummy = '{default: 0};
    stall_req_to_dtlb_dummy = 0;
  end


  Cache #(
      .NUM_OF_REQ_IN(NUM_OF_DCACHE_REQ_IN),
      .NUM_OF_RES_OUT(NUM_OF_DCACHE_RES_OUT),
      .NUM_OF_REQ_OUT(NUM_OF_DCACHE_REQ_OUT),
      .NUM_OF_RES_IN(NUM_OF_DCACHE_RES_IN),
      .NUM_OF_CB_READ_REQ(NUM_OF_DCACHE_CB_READ_REQ),  // 本当は2ほしい
      .NUM_OF_CB_WRITE_REQ(NUM_OF_DCACHE_CB_WRITE_REQ),
      .NUM_OF_WAYS(NUM_OF_DCACHE_WAYS),
      .NUM_OF_SETS(NUM_OF_DCACHE_SETS),
      .CL_SIZE(DCACHE_CL_SIZE),
      .REQ_TO_TLB(NUM_OF_REQ_TO_DTLB),
      .RES_FROM_TLB(NUM_OF_RES_FROM_DTLB),
      .cache_req_t(cache_req64_t),
      .cache_res_t(cache_res64_t),
      .DATA_BULK_SIZE(8),
      .CACHE_CAT(2)
  ) dcache (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_dcache),
      .res_out(res_from_dcache),
      .req_out(req_from_dcache),
      .res_in(res_to_dcache),
      .req_to_tlb(req_to_dtlb_dummy),
      .res_from_tlb(res_from_dtlb_dummy),
      .stall_req_to_tlb(stall_req_to_dtlb_dummy),
      // dcacheから出されるstall信号.
      .stall_req_in(stall_req_to_dcache),
      // dcacheに入力されるstall信号.
      .stall_req_out(stall_req_from_dcache),
      .invalidate_all_sig(invalidate_dcache),
      .invalidate_all_done_sig(invalidate_dcache_done),
      .data_print_en(data_print_en_fake),
      .data_print(data_print_fake)
  );




endmodule
