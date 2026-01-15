// ICache, DCache, L2Cacheをまとめたもの.
// MMIOアクセスもここで行う.
//
// i$は 1req/1cycle,で1reqのデータサイズは32*4=128bit
// d$は 2req/1cycle,で1reqのデータサイズは64bit
// i$,d$ <=> l2$ は512bit
// 
// icache はvipt
// dcache は piptで tlbとcacheが直列で並んでおり, tlbの結果によってmmioへのアクセスとキャッシュへのアクセスに分岐する.
//
// L2CacheとMIGとのやり取りにおいて,Arty s7は 16bit*8(バースト長) で128biyのやり取りをおこなうべきだが,
// ここでは簡易化のために64bitごとにやり取りをおこなう.つまり半分を捨てる.
// TODO:128bit単位でやり取りができるようにする.
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
    parameter int unsigned CL_SIZE = 64,

    parameter int unsigned MIG_PORT_WIDTH = 16
) (
    input logic clock,
    input logic reset,

    // instruction cache subsystem用
    input  cache_req_t req_to_icache  [  NUM_OF_REQ_TO_ICACHE],
    output cache_res_t res_from_icache[NUM_OF_RES_FROM_ICACHE],

    // data cache subsystem 用
    input  cache_req_t req_to_dcache  [  NUM_OF_REQ_TO_DCACHE],
    output cache_res_t res_from_dcache[NUM_OF_RES_FROM_DCACHE],

    // tlbとの接続
    itlb_if.client itlb_port,

    // MainMemoryとの接続.
    mm_if.client mm_port,

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
    output logic invalidate_l2cache_done
);

  // 
  // MSHRで用いるために,cache line単位でアラインされたpaddrを抜き出すためのMSBとLSB

  localparam int unsigned CL_OFFSET_WIDTH = $clog2(CL_SIZE);
  localparam int unsigned CL_ALIGNED_PADDR_MSB = PADDR_WIDTH - 1;
  localparam int unsigned CL_ALIGNED_PADDR_LSB = CL_OFFSET_WIDTH;

  // icache, dcache, l2cache のresやreqの数は互いに相互依存している.
  // 例えば,l2cacheのcbに対するread_reqの数は,icacheとdcacheのres_inの数の最小値である.
  // 逆に言えば,icacheのres_inの数やdcacheのres_inの数は,l2cacheのcb_read_reqの数以上である.
  // 基本的にreqはavailqが緩衝バッファとしての役割を果たすが,resはそのようなものが無いからである.
  // いや,isがあるか.

  // ------------------------------------------------
  // Cacheのreq_inとreq_outのパラメータ
  // ------------------------------------------------
  // NUM_OF_REQ_TO_ICACHE,NUM_OF_REQ_TO_DCACHEは外部から与えられる.
  localparam int unsigned NUM_OF_ICACHE_REQ_IN = NUM_OF_REQ_TO_ICACHE;
  localparam int unsigned NUM_OF_DCACHE_REQ_IN = NUM_OF_REQ_TO_DCACHE;
  localparam int unsigned NUM_OF_ICACHE_REQ_OUT = 3;
  localparam int unsigned NUM_OF_DCACHE_REQ_OUT = 3;
  localparam int unsigned NUM_OF_L2CACHE_REQ_IN = NUM_OF_ICACHE_REQ_OUT + NUM_OF_DCACHE_REQ_OUT;
  localparam int unsigned NUM_OF_L2CACHE_REQ_OUT = NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE * NUM_OF_DW_IN_MM_PORT;

  // ------------------------------------------------
  // cacheのres_inとres_outのパラメータ
  // ------------------------------------------------
  // 最後の*2はdramからの返却とbootloaderからの返却が有るからそれを考慮して.
  localparam int unsigned NUM_OF_L2CACHE_RES_IN = NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE * NUM_OF_DW_IN_MM_PORT *2;
  localparam int unsigned NUM_OF_L2CACHE_RES_OUT = 2;
  localparam int unsigned NUM_OF_ICACHE_RES_IN = NUM_OF_L2CACHE_RES_OUT;
  localparam int unsigned NUM_OF_DCACHE_RES_IN = NUM_OF_L2CACHE_RES_OUT;
  localparam int unsigned NUM_OF_ICACHE_RES_OUT = NUM_OF_RES_FROM_ICACHE;
  localparam int unsigned NUM_OF_DCACHE_RES_OUT = NUM_OF_RES_FROM_DCACHE;

  // ------------------------------------------------
  // cacheのcb_req_read,cb_req_writeのパラメータ
  // ------------------------------------------------
  localparam int unsigned NUM_OF_L2CACHE_CB_READ_REQ = NUM_OF_L2CACHE_RES_OUT;
  localparam int unsigned NUM_OF_L2CACHE_CB_WRITE_REQ = 1;

  // ------------------------------------------------
  // 各キャッシュのサイズパラメータ
  // ------------------------------------------------
  // TODO* ページサイズとlc,setの関係を注意.
  localparam int unsigned NUM_OF_ICACHE_WAYS = 4;
  localparam int unsigned NUM_OF_ICACHE_SETS = 64;
  localparam int unsigned ICACHE_CL_SIZE = 64;


  localparam int unsigned NUM_OF_DCACHE_WAYS = 4;
  localparam int unsigned NUM_OF_DCACHE_SETS = 64;
  localparam int unsigned DCACHE_CL_SIZE = 64;

  localparam int unsigned NUM_OF_L2CACHE_WAYS = 4;
  localparam int unsigned NUM_OF_L2CACHE_SETS = 64;
  localparam int unsigned L2CACHE_CL_SIZE = 64;




  // ---------------------------------------------------
  // icache
  // ---------------------------------------------------
  // viptであるので,tlbをcacheに入れる前に通す必要が無い.

  cache_req_t req_from_icache[NUM_OF_ICACHE_REQ_OUT];
  cache_res_t res_to_icache[NUM_OF_ICACHE_RES_IN];
  logic stall_req_to_itlb;


  // ----------------------------------------------------
  // dcache
  // -----------------------------------------------------

  cache_req_t req_from_dcache[NUM_OF_DCACHE_REQ_OUT];
  cache_res_t res_to_dcache[NUM_OF_DCACHE_RES_IN];
  logic stall_req_to_dtlb;


  // --------------------------------------------------------
  // L2Cache
  // --------------------------------------------------------
  cache_req_t req_to_l2cache[NUM_OF_L2CACHE_REQ_IN];
  cache_res_t res_from_l2cache[NUM_OF_L2CACHE_RES_OUT];

  cache_req_t req_from_l2cache[NUM_OF_L2CACHE_REQ_OUT];
  cache_res_t res_to_l2cache[NUM_OF_L2CACHE_RES_IN];



  // --------------------
  // stall 割当
  // --------------------
  logic stall_req_from_icache;

  logic stall_req_from_dcache;

  logic stall_req_to_l2cache;
  logic stall_req_from_l2cache;

  // stallの配線.
  always_comb begin
    stall_req_from_icache  = stall_req_to_l2cache;
    // icacheの上位への返却(=IFQへの返却)は止める必要が無い

    stall_req_from_dcache  = stall_req_to_l2cache;

    stall_req_from_l2cache = !mm_port.ready;
  end





  // ---------------------------------------------------------------
  // L2Cache <=> ICache,DCache
  // ---------------------------------------------------------------
  // req_from_icache, req_from_dcacheには,それぞれで一意なidとは別にsub_idを持っており,
  // これが1ならDCacheからのリクエスト, 0ならICacheからのリクエスト.

  // req_from_icache, req_from_dcache => req_to_l2cache
  always_comb begin
    // 初期化.
    for (int unsigned i = 0; i < NUM_OF_L2CACHE_REQ_IN; i++) begin
      req_to_l2cache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end
    // ICache => L2Cache
    for (int unsigned i = 0; i < NUM_OF_ICACHE_REQ_OUT; i++) begin
      req_to_l2cache[i] = req_from_icache[i];
      req_to_l2cache[i].id_sub = 0;
    end
    // DCache => L2Cache
    for (int unsigned i = 0; i < NUM_OF_DCACHE_REQ_OUT; i++) begin
      req_to_l2cache[NUM_OF_ICACHE_REQ_OUT+i] = req_from_dcache[i];
      req_to_l2cache[NUM_OF_ICACHE_REQ_OUT+i].id_sub = 1;
    end
  end

  // res_from_l2cache => res_to_icache, res_to_dcache
  always_comb begin
    int unsigned res_to_icache_counter = 0;
    int unsigned res_to_dcache_counter = 0;
    // 初期化
    for (int unsigned i = 0; i < NUM_OF_ICACHE_RES_IN; i++) begin
      res_to_icache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end
    for (int unsigned i = 0; i < NUM_OF_DCACHE_RES_IN; i++) begin
      res_to_dcache[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end


    for (int unsigned i = 0; i < NUM_OF_L2CACHE_RES_OUT; i++) begin
      if (res_from_l2cache[i].valid) begin
        if (res_from_l2cache[i].id_sub == 0) begin
          // icacheからのリクエストの返却
          res_to_icache[res_to_icache_counter] = res_from_l2cache[i];
          res_to_icache_counter++;
        end else if (res_from_l2cache[i].id_sub == 1) begin
          // dcacheからのリクエストの返却.
          res_to_dcache[res_to_dcache_counter] = res_from_l2cache[i];
          res_to_dcache_counter++;
        end
      end
    end

  end

  // -----------------------------------------------------------------
  // MainMemory, BootLoader <=> L2Cache
  // ------------------------------------------------------------------

  // L2Cache => MainMemory
  // L2Cacheからの出力はすべてwrite命令か,すべてread命令かの二択でかつ,どちらも連番のものである.
  // 具体的には,req_out一つあたりでは64bitを扱うが,req_out全体では連続した128bitのreadかwriteの命令が来る.
  // これはメインメモリのポートの幅に合わせるためである.
  // よって送るリクエストは一つでいい.
  // TODO: これはNUM_OF_MM_PORT_CONNECTED_TO_L2CACHEが1の時のみ通用する稚拙な実装である.
  always_comb begin
    int unsigned mm_port_counter = 0;
    // 初期化
    for (int unsigned i = 0; i < NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE; i++) begin
      mm_port.req[i] = '{default: 0};
    end


    // リクエストを送る場合.
    // req_from_l2cacheはNUM_OF_MM_PORT_CONNECTED_TO_L2CACHE*NUM_OF_DW_IN_MM_PORT個あり,
    // 必ず連番になっている.
    for (int unsigned i = 0; i < NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE; i++) begin
      if (req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT].valid) begin
        if (is_read_policy(req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT].req_policy)) begin
          // read命令.
          mm_port.req[mm_port_counter] = '{
              valid: 1,
              id: 0,
              paddr_mig_aligned: req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT].paddr_dw_aligned,
              is_write: 0,
              data: 0
          };
        end else begin
          // write命令(書き込みリクエスト)
          mm_port.req[mm_port_counter] = '{
              valid: 1,
              id: 0,  // 戻って来ないしidは不要
              paddr_mig_aligned: req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT].paddr_dw_aligned,
              is_write: 1,
              data: {
                req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT+1].data,
                req_from_l2cache[i*NUM_OF_DW_IN_MM_PORT].data
              }
          };
        end
        mm_port_counter++;
      end
    end




  end

  // MainMemory => L2Cache
  always_comb begin
    // 初期化
    for (int unsigned i = 0; i < NUM_OF_L2CACHE_RES_IN; i++) begin
      res_to_l2cache[i] = '{
          valid: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE,
          default: 0
      };
    end

    // dramからの返却
    // little endianであるので,[MSB:LSB]みたいな感じでsvで普通に使ってるビット列と同じように,
    // 左側が上位アドレスで右側に下位アドレスがある.
    for (
        int unsigned port_idx = 0; port_idx < NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE; port_idx++
    ) begin
      if (mm_port.res[port_idx].valid) begin
        for (int unsigned i = 0; i < NUM_OF_DW_IN_MM_PORT; i++) begin
          res_to_l2cache[port_idx*NUM_OF_DW_IN_MM_PORT+i] = '{
              valid: 1,
              id: 0,
              id_sub: 0,
              generation: 0,
              req_policy: WRITE_DOUBLE_WORD,
              cb_req_type: WRITE_UPDATE,
              vaddr_dw_aligned: 0,
              paddr_dw_aligned: mm_port.res[port_idx].paddr_mig_aligned + i * DW_SIZE,
              byte_in_dw_idx: 0,
              data: mm_port.res[port_idx].data[i*DW_SIZE*8+:DW_SIZE*8],
              is_page_fault: 0,
              is_access_fault: 0
          };
        end
      end
    end



  end

  // -----------------------------
  // icache
  // ------------------------------
  Cache #(
      .NUM_OF_REQ_IN(NUM_OF_REQ_TO_ICACHE),
      .NUM_OF_RES_OUT(NUM_OF_RES_FROM_ICACHE),
      .NUM_OF_REQ_OUT(NUM_OF_ICACHE_REQ_OUT),
      .NUM_OF_RES_IN(NUM_OF_ICACHE_RES_IN),
      .NUM_OF_DW_IN_BULK(1),
      .NUM_OF_WAYS(NUM_OF_ICACHE_WAYS),
      .NUM_OF_SETS(NUM_OF_ICACHE_SETS),
      .CL_SIZE(ICACHE_CL_SIZE),
      .REQ_TO_TLB(NUM_OF_REQ_TO_ITLB),
      .RES_FROM_TLB(NUM_OF_RES_FROM_ITLB),
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
      .invalidate_all_done_sig(invalidate_icache_done)
  );


  // -------------------------------
  // dcache
  // --------------------------------
  // dcacheはdtlbに接続しない(LSUがdtlbに接続する)ため,ダミー
  tlb_req_t req_to_dtlb_dummy[NUM_OF_REQ_TO_DTLB];
  tlb_res_t res_from_dtlb_dummy[NUM_OF_RES_FROM_DTLB];
  logic stall_req_to_dtlb_dummy;
  always_comb begin
    // tlbからの返却は全部0にしておく.
    res_from_dtlb_dummy = '{default: 0};
    stall_req_to_dtlb   = 0;
  end


  Cache #(
      .NUM_OF_REQ_IN(NUM_OF_DCACHE_REQ_IN),
      .NUM_OF_RES_OUT(NUM_OF_DCACHE_RES_OUT),
      .NUM_OF_REQ_OUT(NUM_OF_DCACHE_REQ_OUT),
      .NUM_OF_RES_IN(NUM_OF_DCACHE_RES_IN),
      .NUM_OF_CB_READ_REQ(),
      .NUM_OF_CB_WRITE_REQ(),
      .NUM_OF_DW_IN_BULK(1),
      .NUM_OF_WAYS(NUM_OF_DCACHE_WAYS),
      .NUM_OF_SETS(NUM_OF_DCACHE_SETS),
      .CL_SIZE(DCACHE_CL_SIZE),
      .REQ_TO_TLB(NUM_OF_REQ_TO_DTLB),
      .RES_FROM_TLB(NUM_OF_RES_FROM_DTLB),
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
      .invalidate_all_done_sig(invalidate_dcache_done)
  );


  // --------------------------------
  // L2 Cache
  // --------------------------------
  // l2cacheはtlbに接続しないのでダミー
  tlb_req_t req_to_l2tlb_dummy[1];
  tlb_res_t res_from_l2tlb_dummy[1];
  logic stall_req_to_l2tlb_dummy;
  always_comb begin
    // tlbからの返却は全部0にしておく.
    res_from_l2tlb_dummy = '{default: 0};
    stall_req_to_l2tlb_dummy = 0;
  end

  Cache #(
      .NUM_OF_REQ_IN(NUM_OF_L2CACHE_REQ_IN),
      .NUM_OF_RES_OUT(NUM_OF_L2CACHE_RES_OUT),
      .NUM_OF_REQ_OUT(NUM_OF_L2CACHE_REQ_OUT),
      .NUM_OF_RES_IN(NUM_OF_L2CACHE_RES_IN),
      .NUM_OF_DW_IN_BULK(NUM_OF_DW_IN_MM_PORT),
      .NUM_OF_WAYS(NUM_OF_L2CACHE_WAYS),
      .NUM_OF_SETS(NUM_OF_L2CACHE_SETS),
      .CL_SIZE(L2CACHE_CL_SIZE),
      .REQ_TO_TLB(1),
      .RES_FROM_TLB(1),
      .CACHE_CAT(3)
  ) l2cache (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_l2cache),
      .res_out(res_from_l2cache),
      .req_out(req_from_l2cache),
      .res_in(res_to_l2cache),
      .req_to_tlb(req_to_l2tlb_dummy),
      .res_from_tlb(res_from_l2tlb_dummy),
      .stall_req_to_tlb(stall_req_to_l2tlb_dummy),
      //.tlb_ready(l2tlb_ready),
      // l2cacheから出されるstall信号.
      .stall_req_in(stall_req_to_l2cache),
      // l2cacheに入力されるstall信号.
      .stall_req_out(stall_req_from_l2cache),
      .invalidate_all_sig(invalidate_l2cache),
      .invalidate_all_done_sig(invalidate_l2cache_done)
  );



endmodule
