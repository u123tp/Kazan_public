// Cacheの汎用モジュール.DCache, ICache, L2Cacheに用いる.
// そのため,vipt, piptいずれにも対応したものにする.
// 
// Arty s7 の bramのバス幅が72bitだったので,64bit(double word)を1単位としてバンク化する.
// 
// キャッシュのラインサイズは512bitで,8bankにする.
//
// mshr_stはtarget_address単位で,mshr_ldはリクエスト単位で管理する.新しいストアリクエストが先行するストアリクエストのtarget_addressと一致
// どちらもmshr内部の順番は問わないが,入って来たときに,先にmshrに入ってるリクエストと照会し,マージしたりバイパスしたりする.
//
//
// ・物理アドレス
//  -----------------------------------------------------------------------
//  |      tag           |   set_index  |         cl_offset               |
//  -----------------------------------------------------------------------
//                                      -----------------------------------
//                                      | dw_in_cl_idx     |       dw     |
//                                      -----------------------------------
//                                                        3 2            0
//                                           ------------------------------
//                                           |dw_in_wb_idx |      dw      |
//                                           ------------------------------
//
//
//
// 基本的に REQ_IN == 3 で,これはtrue-dual-portである.しかし内部的には 2ld+1st / 1cycle となっているので,
// 可能な限り 2LD+1ST で入れたほうが良い.



`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CACHE_PROPS.svh"
`include "CSR_PROPS.svh"
`include "MemoryLayout.svh"


module Cache
  import HART_DEFS::*;
  import CSR_PROPS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CACHE_PROPS::*;
  import MemoryLayout::*;
#(
    // 上位レイヤとのやり取り.
    parameter int unsigned NUM_OF_REQ_IN  = 2,
    parameter int unsigned NUM_OF_RES_OUT = 2,

    // 下位レイヤとのやり取り.
    parameter int unsigned NUM_OF_REQ_OUT = 2,
    parameter int unsigned NUM_OF_RES_IN  = 2,

    // CacheCBで実際に1サイクルに処理するread_req, write_reqの数. 
    parameter int unsigned NUM_OF_CB_READ_REQ  = 2,
    parameter int unsigned NUM_OF_CB_WRITE_REQ = 1,

    // 下位レイヤとやり取りするときに,いくつのDW単位でやり取りすればいいか.
    // 具体的には,メインメモリとは128bitでやり取りするので64bit*2となる.
    // l1キャッシュとl2キャッシュのやり取りの場合は1でいい.
    parameter int unsigned NUM_OF_DW_IN_BULK = 2,

    // キャッシュバッファのパラメータ.
    parameter int unsigned NUM_OF_WAYS = 4,
    parameter int unsigned NUM_OF_SETS = 256,

    // キャッシュラインのサイズ（単位はByte）
    parameter int unsigned CL_SIZE = 64,

    // req_outでdw何個づつ出力するか.
    // 上位レイヤではdw単位でやり取りするが,メインメモリとのやり取りなどは幅がDW_SIZE*2とかになるため.
    parameter int unsigned NUM_OF_DW_IN_REQ_OUT = 2,

    parameter int unsigned REQ_TO_TLB   = 3,
    parameter int unsigned RES_FROM_TLB = 3,


    parameter int unsigned CACHE_CAT = 0


) (
    input logic clock,
    input logic reset,

    // L1CacheにとってはCPUとの,L2CacheにとってはL1Cacheとのやりとり.
    // res_outはdw単位に分割して,各dwがNUM_OF_RES_OUT_PER_DWまで送るが,
    input  cache_req_t req_in [ NUM_OF_REQ_IN],
    output cache_res_t res_out[NUM_OF_RES_OUT],

    // L1CacheにとってはL2Cacheとの,L2Cacheにとってはメインメモリ(につなぐarbiter)とのやりとり.
    output cache_req_t req_out[NUM_OF_REQ_OUT],
    input  cache_res_t res_in [ NUM_OF_RES_IN],

    // tlbとの接続
    output tlb_req_t req_to_tlb[REQ_TO_TLB],
    input tlb_res_t res_from_tlb[RES_FROM_TLB],
    input logic stall_req_to_tlb,

    // 次のサイクル立ち上がりで,上位レイヤから命令が送られて来ないようにする.
    output logic stall_req_in,

    // 次のサイクル立ち上がりで,下位レイヤに命令を送らないようにする.
    // wbb,mshrからのreq_outを抑制する.
    input logic stall_req_out,

    // この命令が来たら,stall_req_inして,このキャッシュの中身を実行し終わった後に,すべてをinvalidate(write_bavk)する.
    input  logic invalidate_all_sig,
    output logic invalidate_all_done_sig
);

  // FOR DEBUG

  int fp_write_back_dump;
  int fp_invalidate_dump;
  int fp_res_out;
  int fp_req_in;

  initial begin
    if (CACHE_CAT == 1) begin
      fp_write_back_dump = $fopen("./log/log_icache_write_back_dump.txt", "w");
      fp_invalidate_dump = $fopen("./log/log_icache_invalidate_dump.txt", "w");
      fp_res_out = $fopen("./log/log_icache_res_out.txt", "w");
      fp_req_in = $fopen("./log/log_icache_req_in.txt", "w");
    end else if (CACHE_CAT == 2) begin
      fp_write_back_dump = $fopen("./log/log_dcache_write_back_dump.txt", "w");
      fp_invalidate_dump = $fopen("./log/log_dcache_invalidate_dump.txt", "w");
      fp_res_out = $fopen("./log/log_dcache_res_out.txt", "w");
      fp_req_in = $fopen("./log/log_dcache_req_in.txt", "w");
    end else if (CACHE_CAT == 3) begin
      fp_write_back_dump = $fopen("./log/log_l2cache_write_back_dump.txt", "w");
      fp_invalidate_dump = $fopen("./log/log_l2cache_invalidate_dump.txt", "w");
      fp_res_out = $fopen("./log/log_l2cache_res_out.txt", "w");
      fp_req_in = $fopen("./log/log_l2cache_req_in.txt", "w");
    end
  end




  // For Debug
  // `define DISP_CACHE_RES(TAG, R) \
  // $display("[%0t] %s\n  valid=%0b id=%0d id_sub=%0d req_policy=%0d cb_req_type=%0d\n  vaddr=0x%h paddr=0x%h data=0x%016h\n", \
  //          $time, TAG, \
  //          (R).valid, (R).id, (R).id_sub, (R).req_policy, (R).cb_req_type, \
  //          (R).vaddr_dw_aligned, (R).paddr_dw_aligned, (R).data)
  // ---------------------------------------------------------
  // パラメータ
  // ---------------------------------------------------------

  // Cache Line
  localparam int unsigned CL_OFFSET_WIDTH = $clog2(
      CL_SIZE
  );
  localparam int unsigned CL_OFFSET_LSB = 0;
  localparam int unsigned CL_OFFSET_MSB = CL_OFFSET_WIDTH - 1;

  // キャッシュラインの中でのdwの数.
  localparam int unsigned NUM_OF_DW_IN_CL = CL_SIZE / DW_SIZE;
  // dw_in_cl_idx
  localparam int unsigned DW_IN_CL_IDX_WIDTH = $clog2(NUM_OF_DW_IN_CL);
  localparam int unsigned DW_IN_CL_IDX_LSB = $clog2(DW_SIZE);
  localparam int unsigned DW_IN_CL_IDX_MSB = DW_IN_CL_IDX_LSB + DW_IN_CL_IDX_WIDTH - 1;

  // 各種のアラインメントされたPADDRを抜き出すためのMSB,LSB
  localparam int unsigned PADDR_CL_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_CL_ALIGNED_LSB = CL_OFFSET_WIDTH;

  localparam int unsigned PADDR_DW_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_DW_ALIGNED_LSB = $clog2(DW_SIZE);



  // SET_IDX
  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SETS);
  localparam int unsigned SET_IDX_MSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH - 1;
  localparam int unsigned SET_IDX_LSB = CL_OFFSET_WIDTH;

  // TAG
  localparam int unsigned TAG_WIDTH = PADDR_WIDTH - SET_IDX_WIDTH - CL_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = PADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH;

  localparam int unsigned WAY_IDX_WIDTH = $clog2(NUM_OF_WAYS);


  // ------------------------------------------------
  // Available Request Queue のパラメータ.
  // ------------------------------------------------
  localparam int unsigned AVAILQ_SIZE = 32;
  localparam int unsigned AVAILQ_IDX_WIDTH = $clog2(AVAILQ_SIZE);

  // --------------------------------------------
  // MSHR のパラメータ.
  // --------------------------------------------
  localparam int unsigned MSHR_SIZE = 8;
  localparam int unsigned MSHR_IDX_WIDTH = $clog2(MSHR_SIZE);

  // 同じアドレス(=同一のMSHR_エントリ)へのREAD,WRITE命令を同時にいくつまで保留出来るか.
  localparam int unsigned MSHR_WRITEQ_SIZE = 4;
  localparam int unsigned MSHR_READQ_SIZE = 8;

  localparam int unsigned MSHR_WRITEQ_IDX_WIDTH = $clog2(MSHR_WRITEQ_SIZE);
  localparam int unsigned MSHR_READQ_IDX_WIDTH = $clog2(MSHR_READQ_SIZE);

  // --------------------------------------------------
  // input stack のパラメータ
  // --------------------------------------------------
  localparam int unsigned IS_SIZE = NUM_OF_DW_IN_CL * MSHR_SIZE;
  localparam int unsigned IS_IDX_WIDTH = $clog2(IS_SIZE);

  // ------------------------------------------------
  // write back buffer のパラメータ
  // -------------------------------------------------
  // write back bufferのサイズ
  // 単位はキャッシュライン.
  // 合計で キャッシュラインのサイズ(512bit) * 4 = 2048 bit

  // 一回のWrite backにおける連結するdwの数.
  // NUM_OF_DW_IN_WB_BLOCK は NUM_OF_REQ_OUT以下である必要がある.
  localparam int unsigned NUM_OF_DW_IN_WB_BLOCK = 2;
  localparam int unsigned DW_IN_WB_BLOCK_IDX_LSB = $clog2(DW_SIZE);
  localparam int unsigned DW_IN_WB_BLOCK_IDX_MSB = DW_IN_WB_BLOCK_IDX_LSB + $clog2(
      NUM_OF_DW_IN_WB_BLOCK
  ) - 1;

  localparam int unsigned NUM_OF_WB_BLOCK_IN_CL = NUM_OF_DW_IN_CL / NUM_OF_DW_IN_WB_BLOCK;

  // wbbの中では,dw単位に分解されて並んでいるので,そのidxの幅.
  localparam int unsigned DW_IN_WBB_IDX_WIDTH = $clog2(MSHR_SIZE * NUM_OF_DW_IN_CL);

  // ----------------------------------------------------
  // TMB のパラメター
  // ----------------------------------------------------
  localparam int unsigned TMB_SIZE = 16;
  localparam int unsigned TMB_IDX_WIDTH = $clog2(TMB_SIZE);

  // ----------------------------------------------------
  // fb
  // ----------------------------------------------------
  localparam int unsigned fb_SIZE = 4;
  localparam int unsigned fb_IDX_WIDTH = $clog2(fb_SIZE);

  // --------------------------------------------------------------------------
  // Cache Buffer のパラメータ.
  // --------------------------------------------------------------------------
  // CacheCBに送るread_reqの数はNUM_OF_CB_READ_REQで示されるが,追加の制約として,
  // 各dw_in_cl_idxにつきリクエストがNUM_OF_CB_READ_PORT個までというものがある.
  // 以下のようにNUM_OF_CB_READ_REQ が NUM_OF_CB_READ_PORT と等しいような場合は,あまりこの制約を考慮しなくていい.

  localparam int unsigned NUM_OF_CB_RW_REQ = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_CB_ALLOCATE_REQ = 1;


  localparam int unsigned NUM_OF_TLB_PORT = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ;


  // --------------------------------------------------------------
  // 出力
  // --------------------------------------------------------------
  // req_out_tmp_nextに次のサイクルでreq_out_tmpに入れるものを入れる
  // req_out_tmpにwbbから読み出したデータをマージしてreq_outとして出力.
  cache_req_t req_out_tmp[NUM_OF_REQ_OUT];
  cache_req_t req_out_tmp_next[NUM_OF_REQ_OUT];


  // ----------------------------------------------------------------
  // Available Request Queue
  // ----------------------------------------------------------------
  // 新しく入ってきたreq_inと,TLB waitingにいたがTLBからresが帰ってきたものを入れる.
  // viptでは,paddrがある方が古い方なので,そっちを優先する.piptだとそもそもtlb_missをすることが無い.
  cache_req_t availq[AVAILQ_SIZE];
  cache_req_t availq_next[AVAILQ_SIZE];
  logic [AVAILQ_IDX_WIDTH-1:0] availq_rp;
  logic [AVAILQ_IDX_WIDTH-1:0] availq_wp;
  logic [AVAILQ_IDX_WIDTH-1:0] availq_rp_next;
  logic [AVAILQ_IDX_WIDTH-1:0] availq_wp_next;
  logic [AVAILQ_IDX_WIDTH:0] num_of_entries_in_availq;
  logic [AVAILQ_IDX_WIDTH:0] num_of_entries_in_availq_next;


  // --------------------------------------------------------------------
  // Input Stack 
  // --------------------------------------------------------------------
  // 初めはres_inから帰ってきたものもavailqに入れていたが,res_inをstallさせようとすると
  // L2Cacheではメインメモリを留めなきゃいけない.流石にそれはアレなのでavailqからres_inを受ける
  // ためだけのキューを分離してinput stackとした.
  // 大きさはDW_IN_CL*MSHR_SIZEになるのでかなり大きい.その代わりres_inに対するstallが不要になる.
  // とりあえずffで作るけど、後でbramに差し替えたい
  cache_req_t is[IS_SIZE];
  cache_req_t is_next[IS_SIZE];
  logic [IS_IDX_WIDTH-1:0] is_rp;
  logic [IS_IDX_WIDTH-1:0] is_wp;
  logic [IS_IDX_WIDTH-1:0] is_rp_next;
  logic [IS_IDX_WIDTH-1:0] is_wp_next;
  logic [IS_IDX_WIDTH:0] num_of_entries_in_is;
  logic [IS_IDX_WIDTH:0] num_of_entries_in_is_next;


  // -------------------------------------------------------------
  // MSHR
  // --------------------------------------------------------------

  // readqの要素.基本的にはcache_res_tを構成出来る最低限の要素が必要.
  // req_type は必ずWRITE_UPDATEになるので不要.
  typedef struct packed {
    // READ命令の内容を上位レイヤに返す場合はリクエストのidが必要.(wbbに書き込むなどの場合は上位レイヤに返さないので必要ない.)
    int unsigned id;
    int unsigned id_sub;
    int unsigned generation;
    // ターゲットとなるdw_in_cl_idx
    logic [DW_IN_CL_IDX_WIDTH-1:0] dw_in_cl_idx;
    logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx;
    req_policy_e req_policy;
  } mshr_readq_t;

  typedef struct packed {
    logic [DW_IN_CL_IDX_WIDTH-1:0] dw_in_cl_idx;
    logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx;
    req_policy_e req_policy;
    logic [63:0] data;
  } mshr_writeq_t;

  // MSHR
  // 基本的にInput stackではdouble word単位で管理する.
  // これは,cbへの書き込みの幅が64bitなのに由来する.
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;

    // resでcpuに返す時に使う.
    // 真っ当に設計されていれば,異なるvaddrが同じpaddrを指すことは無い.
    logic [VADDR_WIDTH-1:0] vaddr_cl_aligned;

    // cb_info関連.
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [$clog2(NUM_OF_WAYS)-1:0] way_idx;


    // 8byte単位でデータがどこにあるのかを管理.
    state_per_dw_t [NUM_OF_DW_IN_CL-1:0] state_per_dw;
    // CBの対応するキャッシュラインで全てのDWが更新されたか
    logic is_all_dw_updated;
    // Write-backする時のために,前のアドレスを保持しておく.
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned_prev;

    // readqとwriteqの内容を混ぜて,順序を管理する
    // 0ならreadqから,1ならwriteqから.
    logic [MSHR_READQ_SIZE+MSHR_WRITEQ_SIZE-1:0] rwq;
    logic [$clog2(MSHR_READQ_SIZE+MSHR_WRITEQ_SIZE)-1:0] rwq_rp;
    logic [$clog2(MSHR_READQ_SIZE+MSHR_WRITEQ_SIZE)-1:0] rwq_wp;


    // read命令とwrite命令のキュー
    mshr_readq_t [MSHR_READQ_SIZE-1:0] readq;
    logic [MSHR_READQ_IDX_WIDTH-1:0] readq_rp;
    logic [MSHR_READQ_IDX_WIDTH-1:0] readq_wp;
    logic [MSHR_READQ_IDX_WIDTH:0] num_of_entries_in_readq;


    mshr_writeq_t [MSHR_WRITEQ_SIZE-1:0] writeq;
    logic [MSHR_WRITEQ_IDX_WIDTH-1:0] writeq_rp;
    logic [MSHR_WRITEQ_IDX_WIDTH-1:0] writeq_wp;
    logic [MSHR_WRITEQ_IDX_WIDTH:0] num_of_entries_in_writeq;
  } mshr_t;
  mshr_t mshr[MSHR_SIZE];
  mshr_t mshr_next[MSHR_SIZE];



  // -----------------------------------------------------------
  // translation miss buffer
  // -----------------------------------------------------------
  // tlbから1サイクルいないに結果が返却されなかった場合,ここに入れられる.
  // 前から順番に並んでいる必要があるが,出ていくのが前からじゃないため,
  // 毎サイクルシフトレジスタみたいに詰める.
  typedef struct packed {
    logic is_page_fault;
    logic is_access_fault;
    cache_req_t req;
  } tmb_t;
  tmb_t tmb[TMB_SIZE];
  tmb_t tmb_next[TMB_SIZE];
  logic [TMB_IDX_WIDTH:0] num_of_entries_in_tmb;
  logic [TMB_IDX_WIDTH:0] num_of_entries_in_tmb_next;


  // -------------------------------------------------------------
  // fault buffer
  // -------------------------------------------------------------
  // fault bufferをcache内部に用意することにした。pagefault, access_faultのエントリを送り返す用のバッファ.
  // tmbから直接res_outに送ると, req_in => tmb_next => res_outでcircularとなると考えられるから。
  // 実際にはcircularで無いのだが,cbに入れるときに,tmbとavailqを比較しなければいけないため,availqとtmbが同じ
  // always_combに入り,req_in => tmbが組み合わせ回路でつながっていると認識される.そのため,fbを一回噛ませる.
  cache_res_t fb;
  cache_res_t fb_next;
  // エントリが有効か.
  logic fb_valid;
  logic fb_valid_next;
  // res_outで使ったか
  logic fb_used;


  // ------------------------------------------------------------
  // write_back_buffer
  // ------------------------------------------------------------

  // wbbを確保するのは,
  // mshrのstate_per_dwを見て,BEFORE_WRITE_BACKの状態だったら,cbからwrite_backするべき内容を読み込むリクエストをavailqに入れてから,
  // 読み取った内容をreq_outとして出力するまでなのでそこまでwbbは量が不要.
  // wbbにアクセスするidxは,wbb[mshr_idx*NUM_OF_DW_IN_CL + dw_idx]
  logic wbb_r_en[NUM_OF_DW_IN_WB_BLOCK];
  logic [$clog2(NUM_OF_DW_IN_CL * MSHR_SIZE)-1:0] wbb_r_ram_idx[NUM_OF_DW_IN_WB_BLOCK];
  logic [DW_SIZE*8-1:0] wbb_r_data[NUM_OF_DW_IN_WB_BLOCK];

  // cb_port.read_reqの数だけ用意しておく.
  logic wbb_w_en[NUM_OF_CB_READ_REQ];
  logic [$clog2(NUM_OF_DW_IN_CL * MSHR_SIZE)-1:0] wbb_w_ram_idx[NUM_OF_CB_READ_REQ];
  logic [DW_SIZE*8-1:0] wbb_w_data[NUM_OF_CB_READ_REQ];
  logic [DW_SIZE-1:0] wbb_w_mask[NUM_OF_CB_READ_REQ];


  LVTRAM #(
      .RAM_WIDTH(DW_SIZE * 8),
      .RAM_DEPTH(NUM_OF_DW_IN_CL * MSHR_SIZE),
      .NUM_OF_READ_PORT(NUM_OF_DW_IN_WB_BLOCK),
      .NUM_OF_WRITE_PORT(NUM_OF_CB_READ_REQ)
  ) wbb (
      .clock(clock),
      .reset(reset),
      .r_en(wbb_r_en),
      .r_ram_idx(wbb_r_ram_idx),
      .r_data(wbb_r_data),
      .w_en(wbb_w_en),
      .w_ram_idx(wbb_w_ram_idx),
      .w_data(wbb_w_data),
      .w_mask(wbb_w_mask)
  );

  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    // dw単位でデータがcbから得られたかを記録する.
    logic [NUM_OF_DW_IN_CL-1:0] data_valid_per_dw;
    // dw単位でデータが書きもどされたかを管理する
    logic [NUM_OF_DW_IN_CL-1:0] data_already_wrote_back;
  } wbb_info_t;
  wbb_info_t wbb_info[MSHR_SIZE];
  wbb_info_t wbb_info_next[MSHR_SIZE];

  // ------------------------------------------------------------------
  // 無効化(Write_back_all)
  // ------------------------------------------------------------------
  // fence.iの実装に際して,すべてを無効化し,dirtyなら書き戻すという処理を実装する.
  // alの先頭にfence.iが来たらdcache,icache両方でこれを行えば良い.
  //
  // write_back_allの場合,stall_req_inを出して新たに命令が入ってこないようにした上で,
  // availqやmshrが空になったあとで,
  // 現在キャッシュに入ってるすべてのdirtyのものをwrite_backする.
  // FENCE.I命令のときに用いる.
  // 信号が来たらCS_WAITING_INVALIDATEに,availq等が空になったらCS_INVALIDATINGに移行.
  // CS_INVALIDATINGでは,availqにwrite_backのreqを送る.
  typedef enum logic [1:0] {
    CS_NORMAL = 2'b00,
    CS_WAITING_INVALIDATE,
    CS_INVALIDATING
  } cache_state_e;
  cache_state_e cache_state;
  cache_state_e cache_state_next;

  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
    state_per_dw_t [NUM_OF_DW_IN_CL-1:0] state_per_dw;
  } invalidate_buf_t;

  invalidate_buf_t invalidate_buf[MSHR_SIZE];
  invalidate_buf_t invalidate_buf_next[MSHR_SIZE];

  int unsigned invalidate_set_counter;
  int unsigned invalidate_set_counter_next;
  int unsigned invalidate_way_counter;
  int unsigned invalidate_way_counter_next;


  // -----------------------------------------------------------------
  // Cache Buffer との接続
  // -----------------------------------------------------------------
  cache_cb_if #(
      .NUM_OF_CB_READ_REQ(NUM_OF_CB_READ_REQ),
      .NUM_OF_CB_WRITE_REQ(NUM_OF_CB_WRITE_REQ),
      .MSHR_SIZE(MSHR_SIZE),
      .CL_SIZE(CL_SIZE),
      .NUM_OF_WAYS(NUM_OF_WAYS),
      .NUM_OF_SETS(NUM_OF_SETS)
  ) cb_port ();


  CacheCB #(
      .NUM_OF_CB_READ_REQ(NUM_OF_CB_READ_REQ),
      .NUM_OF_CB_WRITE_REQ(NUM_OF_CB_WRITE_REQ),
      .MSHR_SIZE(MSHR_SIZE),
      .CL_SIZE(CL_SIZE),
      .NUM_OF_WAYS(NUM_OF_WAYS),
      .NUM_OF_SETS(NUM_OF_SETS),
      .REQ_TO_TLB(REQ_TO_TLB),
      .RES_FROM_TLB(RES_FROM_TLB),
      .CACHE_CAT(CACHE_CAT)
  ) cb (
      .clock(clock),
      .reset(reset),
      .cb_port(cb_port),
      .req_to_tlb(req_to_tlb),
      .res_from_tlb(res_from_tlb)
  );


  // -------------------------------------------------------------------
  // paddrのアライメント用関数
  // -------------------------------------------------------------------

  function automatic logic [PADDR_WIDTH-1:0] to_cl_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] original_paddr);
    return {original_paddr[PADDR_WIDTH-1:CL_OFFSET_WIDTH], CL_OFFSET_WIDTH'(1'b0)};
  endfunction

  function automatic logic [VADDR_WIDTH-1:0] to_cl_aligned_vaddr(
      input logic [VADDR_WIDTH-1:0] original_vaddr);
    return {original_vaddr[VADDR_WIDTH-1:CL_OFFSET_WIDTH], CL_OFFSET_WIDTH'(1'b0)};
  endfunction

  function automatic logic [PADDR_WIDTH-1:0] to_dw_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] original_paddr);
    return {original_paddr[PADDR_WIDTH-1:$clog2(DW_SIZE)], $clog2(DW_SIZE)'(1'b0)};
  endfunction


  // debug
  int unsigned display_counter;


  logic mshr_noroom;
  logic tmb_noroom;
  // あるset_idxを持つsetに対して、同時に大量のallocateが来たら潰れるので,
  // ある程度同じsetが埋まったら止める.
  logic way_noroom;

  typedef enum logic [2:0] {
    FROM_MSHR = 3'b000,
    FROM_TMB = 3'b001,
    FROM_IS = 3'b010,
    FROM_AVAILQ = 3'b011,
    FROM_NONE = 3'b100
  } from_where_t;
  from_where_t from_where;


  // res_outだけ分離しないと,req_inとres_outがつながっているとみなされてcircularになる.
  always_comb begin
    // -------------------------------------------------------------------
    // ①' cb_port.res_out => res_out
    // -------------------------------------------------------------------
    fb_used = 0;
    res_out = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      if (cb_port.res_out[i].valid) begin
        res_out[i] = cb_port.res_out[i];
`ifdef CACHE_RES_OUT_EN
        $fdisplay(
            fp_res_out,
            "[LOG] [Cache.sv] res_out[%0d] : pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_dw_idx=%0d data=%016h",
            i, res_out[i].is_page_fault, res_out[i].is_access_fault, res_out[i].req_policy.name(),
            res_out[i].cb_req_type.name(), res_out[i].vaddr_dw_aligned,
            res_out[i].paddr_dw_aligned, res_out[i].byte_in_dw_idx, res_out[i].data);
`endif
      end else if (fb_valid && !fb_used) begin
        // res_outが空いている場合,fbから持ってくる.
        res_out[i] = fb;
        fb_used = 1;
`ifdef CACHE_RES_OUT_EN
        $fdisplay(
            fp_res_out,
            "[LOG] [Cache.sv] res_out[%0d] : pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_dw_idx=%0d data=%016h",
            i, res_out[i].is_page_fault, res_out[i].is_access_fault, res_out[i].req_policy.name(),
            res_out[i].cb_req_type.name(), res_out[i].vaddr_dw_aligned,
            res_out[i].paddr_dw_aligned, res_out[i].byte_in_dw_idx, res_out[i].data);
`endif
      end
    end

  end

  always_comb begin

    int unsigned req_out_counter = 0;
    mshr_noroom = 0;
    tmb_noroom  = 0;
    way_noroom  = 0;

    // 初期化
    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      req_out_tmp_next[i] = '{
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end

    // mshr
    mshr_next = mshr;

    // wbb
    wbb_info_next = wbb_info;

    // availq
    availq_next = availq;
    availq_rp_next = availq_rp;
    availq_wp_next = availq_wp;
    num_of_entries_in_availq_next = num_of_entries_in_availq;

    // is
    is_next = is;
    is_rp_next = is_rp;
    is_wp_next = is_wp;
    num_of_entries_in_is_next = num_of_entries_in_is;

    // tmb
    tmb_next = tmb;
    num_of_entries_in_tmb_next = num_of_entries_in_tmb;

    // fb
    fb_next = fb;
    fb_valid_next = fb_valid;

    // cache_state
    cache_state_next = cache_state;
    invalidate_buf_next = invalidate_buf;
    invalidate_set_counter_next = invalidate_set_counter;
    invalidate_way_counter_next = invalidate_way_counter;



    // -----------------------------------------------------------------
    // ⑩'wbb => req_out
    // -----------------------------------------------------------------
    begin
      logic all_dw_in_wb_block_updated_but_not_sent = 1;
      logic wbb_used = 0;

      wbb_r_en = '{default: 0};
      wbb_r_ram_idx = '{default: 0};
      if (!stall_req_out) begin

        for (int unsigned cl_idx = 0; cl_idx < MSHR_SIZE; cl_idx++) begin
          // Write backをブロック単位で走査する.
          if (wbb_info[cl_idx].valid) begin
            for (
                int unsigned wb_block_idx = 0; wb_block_idx < NUM_OF_WB_BLOCK_IN_CL; wb_block_idx++
            ) begin

              // NUM_OF_DW_IN_WB_BLOCK個のdwを一つのブロックとして,そのブロックの中のdwがすべて
              // データが得られている状態でかつまだreq_outで出力していない時に,そのブロックごと出力する.
              all_dw_in_wb_block_updated_but_not_sent = 1;
              for (
                  int unsigned dw_idx_in_wb_block = 0;
                  dw_idx_in_wb_block < NUM_OF_DW_IN_WB_BLOCK;
                  dw_idx_in_wb_block++
              ) begin
                // まだデータがvalidでないときと,すでにwrite_back済なら無効.
                if (!wbb_info_next[cl_idx].data_valid_per_dw[wb_block_idx*NUM_OF_DW_IN_WB_BLOCK+dw_idx_in_wb_block] || 
                  wbb_info_next[cl_idx].data_already_wrote_back[wb_block_idx*NUM_OF_DW_IN_WB_BLOCK+dw_idx_in_wb_block]) begin
                  all_dw_in_wb_block_updated_but_not_sent = 0;
                end
              end

              // write_back可能なものが見つかった場合write-backする
              if (all_dw_in_wb_block_updated_but_not_sent && req_out_counter+NUM_OF_DW_IN_WB_BLOCK <= NUM_OF_REQ_OUT &&
                !wbb_used) begin
                for (
                    int unsigned dw_idx_in_wb_block = 0;
                    dw_idx_in_wb_block < NUM_OF_DW_IN_WB_BLOCK;
                    dw_idx_in_wb_block++
                ) begin
                  wbb_r_en[dw_idx_in_wb_block] = 1;
                  wbb_r_ram_idx[dw_idx_in_wb_block] = DW_IN_WBB_IDX_WIDTH'(cl_idx * NUM_OF_DW_IN_CL + wb_block_idx*NUM_OF_DW_IN_WB_BLOCK + dw_idx_in_wb_block);
                  wbb_info_next[cl_idx].data_already_wrote_back[wb_block_idx*NUM_OF_DW_IN_WB_BLOCK+dw_idx_in_wb_block] = 1;
                  // req_out_tmp_nextに書き込んでおき,次のサイクルでwbbから読み出したデータをマージする.
                  req_out_tmp_next[req_out_counter] = '{
                      valid: 1,
                      id: 0,
                      id_sub: 0,
                      generation: 0,
                      req_policy: WRITE_DOUBLE_WORD,
                      cb_req_type: WRITE_REQ_FROM_UPPER,
                      vaddr_dw_aligned: 0,
                      paddr_valid: 1,
                      byte_in_dw_idx: 0,
                      paddr_dw_aligned:
                      wbb_info_next[cl_idx].paddr_cl_aligned
                      +
                      PADDR_WIDTH
                      '(
                      wb_block_idx * NUM_OF_DW_IN_WB_BLOCK + PADDR_WIDTH'(dw_idx_in_wb_block)
                      ) * 8,
                      satp: 0,
                      data: 0
                  };
                  req_out_counter++;
                  // mshrとinvalidate_bufは構造上,どちらか一方しか使用されない.
                  // そのため片方は必ずinvalidであり,使用するときには初期化されるので自由にいじって良い.
                  // mshrのステータス更新.
                  mshr_next[cl_idx].state_per_dw[ wb_block_idx * NUM_OF_DW_IN_WB_BLOCK + dw_idx_in_wb_block] = BEFORE_REQUEST;
                  // invalidate_bufのステータス更新.
                  // mshrと同じstateを使っているので,BEFORE_REQUESTとなっているが、実質的にはDONE.
                  invalidate_buf_next[cl_idx].state_per_dw[wb_block_idx * NUM_OF_DW_IN_WB_BLOCK + dw_idx_in_wb_block] = BEFORE_REQUEST;
                  wbb_used = 1;
                end
              end
            end

          end
        end

        // wbbがすべて送信されたclが存在する場合、それに対応するwbb_infoを削除.
        for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
          if (&wbb_info_next[i].data_already_wrote_back) begin
            wbb_info_next[i].valid = 0;
          end
        end


      end
    end


    // -----------------------------------------------------------------
    // tmb => fb
    // -----------------------------------------------------------------
    // fbが空なら補充する.
    for (int unsigned i = 0; i < TMB_SIZE; i++) begin
      if (!fb_valid_next && tmb_next[i].req.valid && (tmb_next[i].is_page_fault || tmb_next[i].is_access_fault )) begin
        //
        fb_next = '{
            valid: 1,
            id: tmb_next[i].req.id,
            id_sub: tmb_next[i].req.id_sub,
            generation: tmb_next[i].req.generation,
            is_page_fault: tmb_next[i].is_page_fault,
            is_access_fault: tmb_next[i].is_access_fault,
            req_policy: tmb_next[i].req.req_policy,
            cb_req_type: tmb_next[i].req.cb_req_type,
            vaddr_dw_aligned: tmb_next[i].req.vaddr_dw_aligned,
            paddr_dw_aligned: 0,
            byte_in_dw_idx: 0,
            data: 0
        };
        tmb_next[i] = '{default: 0};
        fb_valid_next = 1;
        num_of_entries_in_tmb_next--;
      end
    end


    // -------------------------------------------------------------------
    // ②' cb_port.res_to_tmb => tmb
    // -------------------------------------------------------------------
    begin
      // tmb_noroomでcb_port.res_to_tlbを制御しているので,空いているtmbが存在していることを前提として良い.
      logic [TMB_IDX_WIDTH-1:0] not_used_tmb_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
        // tmbは穴あきのバッファなので,空いているtmbのエントリを探索.
        for (int unsigned j = 0; j < TMB_SIZE; j++) begin
          if (!tmb_next[j].req.valid) begin
            not_used_tmb_idx = TMB_IDX_WIDTH'(j);
          end
        end
        // 空いてる場所にエントリを挿入.
        if (cb_port.res_to_tmb[i].valid) begin
          tmb_next[not_used_tmb_idx] = '{
              is_page_fault: 0,
              is_access_fault: 0,
              req: cb_port.res_to_tmb[i]
          };
          num_of_entries_in_tmb_next++;
        end
      end
    end

    tmb_noroom = TMB_SIZE - 32'(num_of_entries_in_tmb_next) < NUM_OF_CB_RW_REQ;

    // -------------------------------------------------------------------------
    // res_from_tlb => tmb
    // -------------------------------------------------------------------------
    // tlbからのpaddr返却をtmbに反映する.
    for (int unsigned i = 0; i < NUM_OF_CB_RW_REQ; i++) begin
      for (int unsigned j = 0; j < TMB_SIZE; j++) begin
        if (tmb_next[j].req.valid && tmb_next[j].req.id == res_from_tlb[i].id && tmb_next[j].req.generation == res_from_tlb[i].generation) begin
          // $display(
          //     "[LOG] [Cache.sv] TLB RES vaddr:0x%0h paddr:0x%0h page_fault:%b pte_a:%b pte_d: %d",
          //     tmb_next[j].req.vaddr_dw_aligned, res_from_tlb[i].paddr,
          //     res_from_tlb[i].is_page_fault, res_from_tlb[i].pte_a, res_from_tlb[i].pte_d);
          tmb_next[j].req.paddr_valid = 1;
          tmb_next[j].req.paddr_dw_aligned = res_from_tlb[i].paddr;
          // PMA_MEMORY以外へのアクセスの場合access faultを出す.
          tmb_next[j].is_access_fault = res_from_tlb[i].pma_type != PMA_MEMORY;
          tmb_next[j].is_page_fault = res_from_tlb[i].is_page_fault;
          // Svade拡張なので,ここでpage_faultの判定をする.
          // tmbに入るリクエストは上位レイヤからのリクエストのみで,updateやwrite_backするデータのreadなどは入らない
          // だから,page_faultにセットしたことによって,本来ならtmb => fb => res_out とならないもの(updateやwrite_back)が
          // この経路をたどるのではないかという心配は無い.
          if (res_from_tlb[i].pte_a == 0 || (res_from_tlb[i].pte_d == 0 && is_write_policy(
                  tmb_next[j].req.req_policy
              ))) begin
            tmb_next[j].is_page_fault = 1;
          end
        end
      end
    end


    // -------------------------------------------------------------------
    // ③' cb_port.res_to_wbb => wbb
    // -------------------------------------------------------------------
    wbb_w_en = '{default: 0};
    wbb_w_ram_idx = '{default: 0};
    wbb_w_data = '{default: 0};
    wbb_w_mask = '{default: 0};
    begin
      logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
        mshr_idx = MSHR_IDX_WIDTH'(cb_port.res_to_wbb[i].id);
        if (cb_port.res_to_wbb[i].valid) begin
          mshr_idx = MSHR_IDX_WIDTH'(cb_port.res_to_wbb[i].id);
          // wbbの中でどのcl_idxのものに対応するのか分かったら,書き込みを開始する.
          wbb_w_en[i] = 1;
          wbb_w_ram_idx[i] = DW_IN_WBB_IDX_WIDTH'(mshr_idx*NUM_OF_DW_IN_CL + 32'(cb_port.res_to_wbb[i].paddr_dw_aligned[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB]));
          wbb_w_data[i] = cb_port.res_to_wbb[i].data;
          wbb_w_mask[i] = {DW_SIZE{1'b1}};
          // wbb_infoの更新
          wbb_info_next[mshr_idx].data_valid_per_dw[cb_port.res_to_wbb[i].paddr_dw_aligned[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB]] = 1;
        end
      end
    end

    // -------------------------------------------------------------------
    // ④' cb_port.res_to_mshr => MSHR
    // -------------------------------------------------------------------
    // mshrのエントリを新規作成,追加する
    begin
      // 初期化.
      logic exist_in_mshr = 0;
      logic [MSHR_IDX_WIDTH-1:0] existing_mshr_idx = 0;
      mshr_readq_t [MSHR_READQ_SIZE-1:0] new_readq;
      mshr_writeq_t [MSHR_WRITEQ_SIZE-1:0] new_writeq;
      for (int unsigned i = 0; i < MSHR_READQ_SIZE; i++) begin
        new_readq[i] = '{default: 0, req_policy: REQ_POLICY_NONE};
      end
      for (int unsigned i = 0; i < MSHR_WRITEQ_SIZE; i++) begin
        new_writeq[i] = '{default: 0, req_policy: REQ_POLICY_NONE};
      end

      for (int unsigned i = 0; i < NUM_OF_CB_RW_REQ; i++) begin
        if (cb_port.res_to_mshr[i].valid) begin
          // まず,mshrにres_to_mshrのpaddrに対応するものが存在するかを確認する.
          // Cache.svの方でmshrの状態でmshrに入っているか入っていないかを判断するのに,
          // こっちではmshr_nextの状態で判断するのは,同じサイクルで先行する命令が新たに
          // mshr_nextにエントリを作ったときのことを考えてのこと.

          exist_in_mshr = 0;
          existing_mshr_idx = 0;
          for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
            if (mshr_next[mshr_idx].valid && mshr_next[mshr_idx].paddr_cl_aligned == to_cl_aligned_paddr(
                    cb_port.res_to_mshr[i].paddr_dw_aligned
                )) begin
              exist_in_mshr = 1;
              existing_mshr_idx = MSHR_IDX_WIDTH'(mshr_idx);
            end
          end

          // For Debug
          if (display_counter < 6) begin
            // $display(
            //     "exist_in_mshr:%b existing_mshr_idx:%0d mshr_next[existing_mshr_idx].valid:%0d\n",
            //     exist_in_mshr, existing_mshr_idx, mshr_next[existing_mshr_idx].valid);
            // `DISP_CACHE_RES("cb_port.res_to_mshr[i]", cb_port.res_to_mshr[i]);
          end


          if (exist_in_mshr) begin

            // mshrに存在した場合,そのエントリに追加する.
            if (is_read_policy(cb_port.res_to_mshr[i].req_policy)) begin
              // read命令をreadqに加える
              mshr_next[existing_mshr_idx].readq[mshr_next[existing_mshr_idx].readq_wp] = '{
                  id: cb_port.res_to_mshr[i].id,
                  id_sub: cb_port.res_to_mshr[i].id_sub,
                  generation: cb_port.res_to_mshr[i].generation,
                  dw_in_cl_idx:
                  cb_port.res_to_mshr[
                  i
                  ].paddr_dw_aligned[
                  DW_IN_CL_IDX_MSB
                  :
                  DW_IN_CL_IDX_LSB
                  ],
                  byte_in_dw_idx: cb_port.res_to_mshr[i].byte_in_dw_idx,
                  req_policy: cb_port.res_to_mshr[i].req_policy
              };
              mshr_next[existing_mshr_idx].readq_wp = MSHR_READQ_IDX_WIDTH'(mshr_next[existing_mshr_idx].readq_wp + MSHR_READQ_IDX_WIDTH'(1));
              mshr_next[existing_mshr_idx].num_of_entries_in_readq++;
              mshr_next[existing_mshr_idx].rwq[mshr_next[existing_mshr_idx].rwq_wp] = 0;
              mshr_next[existing_mshr_idx].rwq_wp = mshr_next[existing_mshr_idx].rwq_wp + 1;
            end else begin
              // write命令をwriteqに加える
              mshr_next[existing_mshr_idx].writeq[mshr_next[existing_mshr_idx].writeq_wp] = '{
                  dw_in_cl_idx:
                  cb_port.res_to_mshr[
                  i
                  ].paddr_dw_aligned[
                  DW_IN_CL_IDX_MSB
                  :
                  DW_IN_CL_IDX_LSB
                  ],
                  byte_in_dw_idx: cb_port.res_to_mshr[i].byte_in_dw_idx,
                  req_policy: cb_port.res_to_mshr[i].req_policy,
                  data: cb_port.res_to_mshr[i].data
              };
              mshr_next[existing_mshr_idx].writeq_wp = MSHR_WRITEQ_IDX_WIDTH'(mshr_next[existing_mshr_idx].writeq_wp + MSHR_WRITEQ_IDX_WIDTH'(1));
              mshr_next[existing_mshr_idx].num_of_entries_in_writeq++;
              mshr_next[existing_mshr_idx].rwq[mshr_next[existing_mshr_idx].rwq_wp] = 1;
              mshr_next[existing_mshr_idx].rwq_wp = mshr_next[existing_mshr_idx].rwq_wp + 1;
            end
          end else begin
            // mshrに存在しなかった場合,新たにmshrのエントリを確保する
            // res_to_mshrの内容を反映したreadq,writeqを作る.
            for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
              if (!mshr_next[mshr_idx].valid) begin
                // 新たにmshrエントリを追加
                mshr_next[mshr_idx] = '{
                    valid: 1,
                    paddr_cl_aligned: to_cl_aligned_paddr(cb_port.res_to_mshr[i].paddr_dw_aligned),
                    vaddr_cl_aligned: to_cl_aligned_vaddr(cb_port.res_to_mshr[i].vaddr_dw_aligned),
                    set_idx: cb_port.res_to_mshr[i].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB],
                    way_idx: 0,  // まだallocateしていない為不明
                    state_per_dw: '{default: BEFORE_CB_ALLOCATION},
                    is_all_dw_updated: 0,
                    paddr_cl_aligned_prev: 0,  //まだallocateしていない為不明
                    rwq: '{default: 0},
                    rwq_rp: 0,
                    rwq_wp: 0,
                    readq: new_readq,
                    readq_rp: 0,
                    readq_wp: 0,
                    num_of_entries_in_readq: 0,
                    writeq: new_writeq,
                    writeq_rp: 0,
                    writeq_wp: 0,
                    num_of_entries_in_writeq: 0
                };

                // res_to_mshrの内容をreadq,writeqに反映する.
                if (is_read_policy(cb_port.res_to_mshr[i].req_policy)) begin
                  mshr_next[mshr_idx].readq[0] = '{
                      id: cb_port.res_to_mshr[i].id,
                      id_sub: cb_port.res_to_mshr[i].id_sub,
                      generation: cb_port.res_to_mshr[i].generation,
                      dw_in_cl_idx:
                      cb_port.res_to_mshr[
                      i
                      ].paddr_dw_aligned[
                      DW_IN_CL_IDX_MSB
                      :
                      DW_IN_CL_IDX_LSB
                      ],
                      byte_in_dw_idx: cb_port.res_to_mshr[i].byte_in_dw_idx,
                      req_policy: cb_port.res_to_mshr[i].req_policy
                  };
                  mshr_next[mshr_idx].readq_wp = 1;
                  mshr_next[mshr_idx].num_of_entries_in_readq = 1;
                  mshr_next[mshr_idx].rwq[0] = 0;
                  mshr_next[mshr_idx].rwq_wp = 1;
                end else begin
                  mshr_next[mshr_idx].writeq[0] = '{
                      dw_in_cl_idx:
                      cb_port.res_to_mshr[
                      i
                      ].paddr_dw_aligned[
                      DW_IN_CL_IDX_MSB
                      :
                      DW_IN_CL_IDX_LSB
                      ],
                      byte_in_dw_idx: cb_port.res_to_mshr[i].byte_in_dw_idx,
                      req_policy: cb_port.res_to_mshr[i].req_policy,
                      data: cb_port.res_to_mshr[i].data
                  };
                  mshr_next[mshr_idx].writeq_wp = 1;
                  mshr_next[mshr_idx].num_of_entries_in_writeq = 1;
                  mshr_next[mshr_idx].rwq[0] = 1;
                  mshr_next[mshr_idx].rwq_wp = 1;
                end
                break;
              end
            end


          end
        end
      end
    end


    // mshr_next => mshr_noroom
    // 次のサイクルでmshrに対する入力が無い(=このサイクルでcbに対してリクエストを行わない)ことを要求する.
    begin
      int unsigned mshr_coutner = 0;
      mshr_noroom = 0;
      for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
        if (mshr_next[mshr_idx].valid) begin
          mshr_coutner++;
          if(MSHR_READQ_SIZE - 32'(mshr_next[mshr_idx].num_of_entries_in_readq) < NUM_OF_CB_RW_REQ ||
            MSHR_WRITEQ_SIZE - 32'(mshr_next[mshr_idx].num_of_entries_in_writeq) < NUM_OF_CB_RW_REQ)begin
            mshr_noroom = 1;
          end
        end  // if (from_where != FROM_NONE) begin
        //   $display("[LOG] [%s,%d] FROM_WHERE:%s", `__FILE__, `__LINE__, from_where.name());
        // end
      end

      if (MSHR_SIZE - mshr_coutner < NUM_OF_CB_RW_REQ) begin
        mshr_noroom = 1;
      end

    end

    // mshr_next => way_noroom
    // あるsetに対してwayの空きが十分に無いなら,新たにallocateする可能性があるもの,すなわちavailqとtmbからの出力を抑える.
    begin
      logic [WAY_IDX_WIDTH:0] way_counter_per_set[NUM_OF_SETS] = '{default: 0};
      way_noroom = 0;
      for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
        if (mshr_next[i].valid) begin
          way_counter_per_set[mshr_next[i].set_idx]++;
        end
      end
      for (int unsigned i = 0; i < NUM_OF_SETS; i++) begin
        if (NUM_OF_WAYS - 32'(way_counter_per_set[i]) < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ) begin
          way_noroom = 1;
        end
      end
    end

    // -------------------------------------------------------------------
    // ⑤' res_in => is
    // -------------------------------------------------------------------
    for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
      if (res_in[i].valid) begin
        is_next[is_wp_next] = '{
            valid: 1,
            id: res_in[i].id,
            id_sub: 0,
            generation: 0,
            req_policy: WRITE_DOUBLE_WORD,
            cb_req_type: WRITE_UPDATE,
            vaddr_dw_aligned: 0,  // 使用しない.
            paddr_valid: 1,
            paddr_dw_aligned: res_in[i].paddr_dw_aligned,
            byte_in_dw_idx: res_in[i].byte_in_dw_idx,
            satp: 0,
            data: res_in[i].data
        };
        is_wp_next = IS_IDX_WIDTH'(is_wp_next + IS_IDX_WIDTH'(1));
        num_of_entries_in_is_next++;
      end
    end

    // -----------------------------------------------------------------------
    // ⑥' req_in => availq
    // -----------------------------------------------------------------------
    for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
      if (req_in[i].valid) begin
`ifdef CACHE_RES_IN_EN
        $fdisplay(fp_req_in,
                  "i=%0d req_policy:%s,req_type:%s vaddr=%h paddr_valid=%0b paddr=%h data=%h", i,
                  req_in[i].req_policy.name(), req_in[i].cb_req_type.name(),
                  req_in[i].vaddr_dw_aligned, req_in[i].paddr_valid, req_in[i].paddr_dw_aligned,
                  req_in[i].data);
`endif
        availq_next[availq_wp_next] = req_in[i];
        availq_wp_next = AVAILQ_IDX_WIDTH'(availq_wp_next + AVAILQ_IDX_WIDTH'(1));
        num_of_entries_in_availq_next++;
      end
    end



    //-------------------------------------------------------------------------
    // ⑧' tmb, availq, is, mshr => cb_port.req_in
    // ------------------------------------------------------------------------
    // tmbかavailqのどちらかからcb_port.read_req,cb_port.write_reqにreqを送る.
    // tmbからでは,同じpaddrを返すものについては必ず前から順番に返されるので,そのtmbの中で
    // paddrが有効なものを前から処理しても,同じpaddrを持つreqの間で順番が崩れることは無い.
    // 一方でavailqの場合,(paddrを見ないで処理するなら)前から処理していってもpaddrが重なる可能性がある.
    // そのため,read_req,write_reqがどちらかがいっぱいで、次のreqをスキップしなきゃいけないような状態に
    // なったらそこで内止める.まあ paddrみるよううにすれば問題ないのか？
    //
    // まず,mshr,tmb,is,availqのどこからcbに送るのかを判断する.
    // 優先順位は mshr => is => tmb => availq
    // tmb_noroomはpaddrがわからない可能性がある入力、つまりavailqからのみ有効.
    // mshr_noroomはhitしない可能性があるもの、つまりavailq,tmbからの入力に有効
    // 
    // 同一サイクルで,同じアドレスに対してのwrite命令 => read命令となるような組み合わせでcbに送らない.
    // read命令を送るときに,同じサイクル,同じアドレスで先行するwrite命令があったら送らない.
    // TODO:** とりあえず今は,write命令送ったらそこで終了とする.
    // 理由は,lsuからvaddrが来ていないから.後でlsuからvaddrもリクエストで一緒に送るように改造する.
    // あと、今どうサイクルでwrite_port => read_portの内容を送った場合,writeportからreadportにバイパスされない.
    begin

      int unsigned read_req_to_cb_counter = 0;
      int unsigned write_req_to_cb_counter = 0;



      // availq用
      logic set_idx_log_valid[NUM_OF_CB_RW_REQ] = '{default: 0};
      logic [SET_IDX_WIDTH-1:0] set_idx_log[NUM_OF_CB_RW_REQ] = '{default: 0};
      logic set_idx_dup = 0;

      from_where = FROM_NONE;

      // 初期化
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
        cb_port.read_req[i] = '{
            valid: 0,
            req_policy: REQ_POLICY_NONE,
            cb_req_type: CB_REQ_TYPE_NONE,
            default: 0
        };
      end
      for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
        cb_port.write_req[i] = '{
            valid: 0,
            req_policy: REQ_POLICY_NONE,
            cb_req_type: CB_REQ_TYPE_NONE,
            default: 0
        };
      end

      //availq
      // availqからのリクエストのアドレスが、他の丁度いまwrite_back中のアドレスと一致すると、
      // write_backしながらrequestすることになるので,それが起こらないのように同じset_idxを持つものがmshr_nextに
      // すでにあるなら,availqから発行はしない.
      // これは,res_to_mshrをmshr_nextに反映してから行わないと,res_to_mshrに入ってるリクエストに対しての確認が漏れるので注意.
      begin
        logic write_back_processing = 0;
        logic [SET_IDX_WIDTH-1:0] set_idx = 0;
        logic [AVAILQ_IDX_WIDTH-1:0] availq_idx = 0;
        for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
          availq_idx = AVAILQ_IDX_WIDTH'(availq_rp_next + AVAILQ_IDX_WIDTH'(i));
          set_idx = availq_next[availq_idx].paddr_valid ? 
            availq_next[availq_idx].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB] : availq_next[availq_idx].vaddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];
          for (int unsigned j = 0; j < MSHR_SIZE; j++) begin
            if(mshr_next[j].valid && mshr_next[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
              write_back_processing = 1;
            end
          end
        end

        if (num_of_entries_in_availq_next != 0 && !mshr_noroom && !tmb_noroom && !way_noroom && !write_back_processing) begin
          from_where = FROM_AVAILQ;
        end
      end

      // tmb
      begin
        logic write_back_processing = 0;
        logic [SET_IDX_WIDTH-1:0] set_idx = 0;
        for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
          set_idx = tmb_next[i].req.paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];
          for (int unsigned j = 0; j < MSHR_SIZE; j++) begin
            if(mshr_next[j].valid && mshr_next[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
              write_back_processing = 1;
            end
          end
        end

        if (num_of_entries_in_tmb_next != 0 && !mshr_noroom && !way_noroom && !write_back_processing) begin
          for (int unsigned i = 0; i < TMB_SIZE; i++) begin
            if (tmb_next[i].req.valid && tmb_next[i].req.paddr_valid && !tmb_next[i].is_page_fault) begin
              from_where = FROM_TMB;
            end
          end
        end
      end

      // is
      if (num_of_entries_in_is_next != 0) begin
        from_where = FROM_IS;
      end

      // mshrから(write_back)
      for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
        for (int unsigned dw_in_cl_idx = 0; dw_in_cl_idx < NUM_OF_DW_IN_CL; dw_in_cl_idx++) begin
          if (mshr_next[mshr_idx].valid && mshr_next[mshr_idx].state_per_dw[dw_in_cl_idx] == BEFORE_WRITE_BACK) begin
            from_where = FROM_MSHR;
          end
        end
      end

      // mshrから (read命令, write命令)
      for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
        if (mshr_next[i].valid && mshr_next[i].is_all_dw_updated && 
            ((mshr_next[i].num_of_entries_in_readq + mshr_next[i].num_of_entries_in_writeq) != 0)) begin
          from_where = FROM_MSHR;
        end
      end

      // TLBからstall_outが出ている場合,問答無用でstall
      if (stall_req_to_tlb) begin
        from_where = FROM_NONE;
      end



      // if (from_where != FROM_NONE) begin
      //   $display("[LOG] [%s,%d] FROM_WHERE:%s", `__FILE__, `__LINE__, from_where.name());
      // end

      // availq, is, tmb, mshr => cb
      case (from_where)
        FROM_AVAILQ: begin
          // availq => cb_port.read_req, cb_port.write_req
          for (int unsigned i = 0; i < NUM_OF_CB_RW_REQ; i++) begin
            // $display(
            //     "[LOG] [%s,%d] from_availq num_of_entries_in_availq_next:%d, req_policy:%s, target_paddr:%016h is_read_policy:%b, is_write_policy:%b, read_req_to_cb_couter:%d, write_req_to_cb_counter:%d,",
            //     `__FILE__, `__LINE__, num_of_entries_in_availq_next,
            //     availq_next[availq_rp_next].req_policy,
            //     availq_next[availq_rp_next].paddr_dw_aligned, is_read_policy(
            //     availq_next[availq_rp_next].req_policy), is_write_policy(
            //     availq_next[availq_rp_next].req_policy), read_req_to_cb_counter,
            //     write_req_to_cb_counter);

            // 同じサイクルの中で,先行する命令と同じset_idxの場合,set_idx_dupとして,実行しない.
            // TODO:tmbにも同じものを設置.
            set_idx_dup = 0;
            for (int unsigned j = 0; j < i; j++) begin
              if(set_idx_log_valid[j] && (set_idx_log[j] == (availq_next[availq_rp_next].paddr_valid ? 
              availq_next[availq_rp_next].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB] : availq_next[availq_rp_next].vaddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB])))begin
                set_idx_dup = 1;
              end
            end
            if (set_idx_dup) begin
              break;
            end

            if ((num_of_entries_in_availq_next != 0) && is_read_policy(
                    availq_next[availq_rp_next].req_policy
                ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
              // read_reqをcb_port.req_inへ入力.
              cb_port.read_req[read_req_to_cb_counter] = availq_next[availq_rp_next];
              set_idx_log_valid[i] = 1;
              set_idx_log[i] = availq_next[availq_rp_next].paddr_valid ? 
                              availq_next[availq_rp_next].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB] : availq_next[availq_rp_next].vaddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];

              availq_rp_next = AVAILQ_IDX_WIDTH'(availq_rp_next + AVAILQ_IDX_WIDTH'(1));
              num_of_entries_in_availq_next--;
              read_req_to_cb_counter++;


            end else if ((num_of_entries_in_availq_next != 0) && is_write_policy(
                    availq_next[availq_rp_next].req_policy
                ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin
              // write_reqをcb_port.req_inへ入力
              cb_port.write_req[write_req_to_cb_counter] = availq_next[availq_rp_next];
              set_idx_log_valid[i] = 1;
              set_idx_log[i] = availq_next[availq_rp_next].paddr_valid ? 
                              availq_next[availq_rp_next].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB] : availq_next[availq_rp_next].vaddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];

              availq_rp_next = AVAILQ_IDX_WIDTH'(availq_rp_next + AVAILQ_IDX_WIDTH'(1));
              num_of_entries_in_availq_next--;
              write_req_to_cb_counter++;
              // TODO:**
              break;
            end else begin
              // $display(
              //     "[LOG] [%s,%-d] from_where is FROM_AVAILQ, but something is wrong. num_of_availq_entries_next:%d",
              //     `__FILE__, `__LINE__, num_of_entries_in_availq_next);
              break;
            end
          end
        end
        FROM_TMB: begin
          // tmb => cb_port.read_req, cb_port.write_req
          for (int unsigned i = 0; i < TMB_SIZE; i++) begin
            if(tmb_next[i].req.valid && tmb_next[i].req.paddr_valid && !tmb_next[i].is_page_fault)begin
              if (is_read_policy(
                      tmb_next[i].req.req_policy
                  ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
                cb_port.read_req[read_req_to_cb_counter] = tmb_next[i].req;
                read_req_to_cb_counter++;
                tmb_next[i].req.valid = 0;
                num_of_entries_in_tmb_next--;
              end else if (is_write_policy(
                      tmb_next[i].req.req_policy
                  ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin
                // tmb => cb_port.write_req
                cb_port.write_req[write_req_to_cb_counter] = tmb_next[i].req;
                write_req_to_cb_counter++;
                tmb_next[i].req.valid = 0;
                num_of_entries_in_tmb_next--;
                // TODO:**
                break;
              end
            end
          end
        end
        FROM_IS: begin
          // is => cb_port.read_req, cb_port.write_req
          for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
            // res_inで帰ってきたものなので,write_reqしか存在しない.
            if (num_of_entries_in_is_next != 0) begin
              cb_port.write_req[i] = is_next[is_rp_next];
              is_next[is_rp_next].valid = 0;
              is_rp_next = is_rp_next + IS_IDX_WIDTH'(1);
              num_of_entries_in_is_next--;
              // TODO:**
              break;
            end
          end
        end
        FROM_MSHR: begin
          // mshr => cb_port.read_req(write_back)
          for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
            for (
                int unsigned dw_in_cl_idx = 0; dw_in_cl_idx < NUM_OF_DW_IN_CL; dw_in_cl_idx++
            ) begin
              if (mshr_next[mshr_idx].valid) begin
                if (mshr_next[mshr_idx].state_per_dw[dw_in_cl_idx] == BEFORE_WRITE_BACK && read_req_to_cb_counter<NUM_OF_CB_READ_REQ) begin
                  // availqにwrite-back用のread命令を詰める.
                  // write_backするときにはすでにpaddrのcb_infoは新しいpaddrに変更されているので、
                  // paddr_cl_aligned_prevは用いない.その代わり,idにmshr_idxを入れて、そのidを用いてwbbでどのpaddrに対する
                  // 書き戻しなのかを判断する.
                  cb_port.read_req[read_req_to_cb_counter] = '{
                      valid: 1,
                      id: mshr_idx,  // IDにmshr_idx
                      id_sub: 0,
                      generation: 0,
                      req_policy: READ_DOUBLE_WORD,
                      cb_req_type: READ_WRITE_BACK,
                      vaddr_dw_aligned: 0,
                      paddr_valid: 1,
                      paddr_dw_aligned:
                      mshr_next[mshr_idx].paddr_cl_aligned
                      +
                      dw_in_cl_idx
                      *
                      DW_SIZE,
                      byte_in_dw_idx: 0,  // write_backはdw単位の為0.
                      satp: 0,
                      data: 0
                  };
                  mshr_next[mshr_idx].state_per_dw[dw_in_cl_idx] = DURING_WRITE_BACK;
                  read_req_to_cb_counter++;
                end
              end
            end
          end

          // mshr => cb_port.read_req(read命令, write命令)
          // すべてのdwがCB_UPDATEDになったら,readqやwriteqに溜まっている命令をavailqに送れる.
          for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
            if (mshr_next[i].valid && mshr_next[i].is_all_dw_updated) begin
              if (mshr_next[i].num_of_entries_in_readq != 0 && mshr_next[i].rwq[mshr_next[i].rwq_rp] == 0 &&
                    read_req_to_cb_counter<NUM_OF_CB_READ_REQ) begin
                // readq => cb_port.read_req
                cb_port.read_req[read_req_to_cb_counter] = '{
                    valid: 1,
                    id: mshr_next[i].readq[mshr_next[i].readq_rp].id,
                    id_sub: mshr_next[i].readq[mshr_next[i].readq_rp].id_sub,
                    generation: mshr_next[i].readq[mshr_next[i].readq_rp].generation,
                    req_policy: mshr_next[i].readq[mshr_next[i].readq_rp].req_policy,
                    cb_req_type: READ_REQ_FROM_UPPER,
                    vaddr_dw_aligned:
                    mshr_next[i].vaddr_cl_aligned
                    +
                    mshr_next[i].readq[mshr_next[i].readq_rp].dw_in_cl_idx
                    *
                    DW_SIZE,
                    paddr_valid: 1,
                    paddr_dw_aligned:
                    mshr_next[i].paddr_cl_aligned
                    +
                    mshr_next[i].readq[mshr_next[i].readq_rp].dw_in_cl_idx
                    *
                    DW_SIZE,
                    byte_in_dw_idx: mshr_next[i].readq[mshr_next[i].readq_rp].byte_in_dw_idx,
                    satp: 0,
                    data: 0
                };
                mshr_next[i].readq_rp = MSHR_READQ_IDX_WIDTH'(mshr_next[i].readq_rp + MSHR_READQ_IDX_WIDTH'(1'b1));
                mshr_next[i].num_of_entries_in_readq--;
                read_req_to_cb_counter++;
                mshr_next[i].rwq_rp = mshr_next[i].rwq_rp + 1;
              end else if(mshr_next[i].num_of_entries_in_writeq != 0 && mshr_next[i].rwq[mshr_next[i].rwq_rp] == 1 &&
                    write_req_to_cb_counter<NUM_OF_CB_WRITE_REQ) begin
                // writeq => cb_port.write_req
                cb_port.write_req[write_req_to_cb_counter] = '{
                    valid: 1,
                    id: 0,  // writeq命令は書き込むだけだから
                    id_sub: 0,
                    generation: 0,
                    req_policy: mshr_next[i].writeq[mshr_next[i].writeq_rp].req_policy,
                    cb_req_type: WRITE_REQ_FROM_UPPER,
                    vaddr_dw_aligned:
                    mshr_next[i].vaddr_cl_aligned
                    +
                    mshr_next[i].writeq[mshr_next[i].writeq_rp].dw_in_cl_idx
                    *
                    DW_SIZE,
                    paddr_valid: 1,
                    paddr_dw_aligned:
                    mshr_next[i].paddr_cl_aligned
                    +
                    mshr_next[i].writeq[mshr_next[i].writeq_rp].dw_in_cl_idx
                    *
                    DW_SIZE,
                    byte_in_dw_idx: mshr_next[i].writeq[mshr_next[i].writeq_rp].byte_in_dw_idx,
                    satp: 0,
                    data: mshr_next[i].writeq[mshr_next[i].writeq_rp].data
                };
                mshr_next[i].writeq_rp = MSHR_WRITEQ_IDX_WIDTH'(mshr_next[i].writeq_rp + MSHR_WRITEQ_IDX_WIDTH'(1'b1));
                mshr_next[i].num_of_entries_in_writeq--;
                write_req_to_cb_counter++;
                mshr_next[i].rwq_rp = mshr_next[i].rwq_rp + 1;

                // TODO:**
                break;
              end
            end
          end
        end
        default: begin
          // fuck
        end
      endcase

    end


    // ---------------------------------------------------------
    // tmbを詰める
    // ---------------------------------------------------------
    // tmbは入ってきた順番に並んでる必要がある一方,出ていくのが前から順番では無いので,
    // 歯抜けの分を詰める
    begin
      tmb_t tmb_tmp[TMB_SIZE] = '{default: 0};
      int unsigned tmb_invalid_counter = 0;
      for (int unsigned i = 0; i < TMB_SIZE; i++) begin
        if (tmb_next[i].req.valid) begin
          tmb_tmp[i-tmb_invalid_counter] = tmb_next[i];
        end else begin
          tmb_invalid_counter++;
        end
      end
      tmb_next = tmb_tmp;
    end

    // -----------------------------------------------------------------------
    // ⑨' MSHR => req_out
    // ------------------------------------------------------------------------

    for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
      if (mshr_next[mshr_idx].valid && !stall_req_out) begin
        for (
            int unsigned dw_idx_bulk_aligned = 0;
            dw_idx_bulk_aligned < NUM_OF_DW_IN_CL;
            dw_idx_bulk_aligned += NUM_OF_DW_IN_BULK
        ) begin
          // 必ずNUM_OF_DW_IN_BULK単位で出力される
          if(mshr_next[mshr_idx].state_per_dw[dw_idx_bulk_aligned] == BEFORE_REQUEST && 
            req_out_counter+NUM_OF_DW_IN_BULK <=NUM_OF_REQ_OUT)begin
            for (int unsigned i = 0; i < NUM_OF_DW_IN_BULK; i++) begin
              req_out_tmp_next[req_out_counter] = '{
                  valid: 1,
                  // 戻ってきたread_resはcbのアップデートに用いるだけで,paddrも判明しているためtlbにリクエストも出さないので,idは不要
                  id:
                  0,
                  id_sub: 0,
                  generation: 0,
                  req_policy: READ_DOUBLE_WORD,
                  cb_req_type: READ_REQ_FROM_UPPER,
                  vaddr_dw_aligned: 0,
                  paddr_valid: 1,
                  paddr_dw_aligned:
                  mshr_next[mshr_idx].paddr_cl_aligned
                  + (
                  (PADDR_WIDTH'($unsigned(dw_idx_bulk_aligned)) + PADDR_WIDTH'($unsigned(i))) << 3
                  ),
                  byte_in_dw_idx: 0,
                  satp: 0,
                  data: 0
              };
              req_out_counter++;
              mshr_next[mshr_idx].state_per_dw[dw_idx_bulk_aligned+i] = DURING_REQUEST;
            end
          end

        end
      end

    end



    // ------------------------------------------------------------------------
    // ⑪' MSHRのstate_per_dwの更新
    // ------------------------------------------------------------------------
    begin
      logic is_all_updated = 1;
      for (int unsigned i = 0; i < NUM_OF_CB_RW_REQ; i++) begin
        if (cb_port.mshr_new_state[i].valid) begin
          for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
            if(mshr_next[mshr_idx].valid && cb_port.mshr_new_state[i].paddr_cl_aligned == mshr_next[mshr_idx].paddr_cl_aligned)begin

              // state_per_dwで送られてくる値に更新.
              mshr_next[mshr_idx].state_per_dw[cb_port.mshr_new_state[i].dw_in_cl_idx] = cb_port.mshr_new_state[i].state_per_dw;

              //この更新で,もしcl内部のすべてのdwがUPDATEDになったら,is_all_dw_updatedとする
              is_all_updated = 1;
              for (int unsigned dw_idx = 0; dw_idx < NUM_OF_DW_IN_CL; dw_idx++) begin
                if (mshr_next[mshr_idx].state_per_dw[dw_idx] != CB_UPDATED) begin
                  is_all_updated = 0;
                end
              end


              if (is_all_updated) begin
                mshr_next[mshr_idx].is_all_dw_updated = 1;
              end

            end
          end
        end
      end
    end



    // -----------------------------------------------------------------------
    // ⑫' MSHR => cb_port.allocate_req
    //     cb_port.allocate_res => MSHR
    // ------------------------------------------------------------------------
    begin

      // cb_port.allocate_res => MSHR
      // wbb_infoの確保.
      if (cb_port.allocate_res.valid) begin
        if (cb_port.allocate_res.success) begin
          mshr_next[cb_port.allocate_res.mshr_idx].way_idx = cb_port.allocate_res.way_idx;
          mshr_next[cb_port.allocate_res.mshr_idx].paddr_cl_aligned_prev = cb_port.allocate_res.paddr_cl_aligned_prev;
          if (cb_port.allocate_res.wb_need) begin
            mshr_next[cb_port.allocate_res.mshr_idx].state_per_dw = '{default: BEFORE_WRITE_BACK};
            wbb_info_next[cb_port.allocate_res.mshr_idx] = '{
                valid: 1,
                paddr_cl_aligned: cb_port.allocate_res.paddr_cl_aligned_prev,
                data_valid_per_dw : 0,
                data_already_wrote_back: 0
            };
          end else begin
            mshr_next[cb_port.allocate_res.mshr_idx].state_per_dw = '{default: BEFORE_REQUEST};
          end
        end else begin
          // allocateに失敗した場合,状態を戻す.
          mshr_next[cb_port.allocate_res.mshr_idx].state_per_dw = '{default: BEFORE_CB_ALLOCATION};
        end
      end

      // MSHR => cb_port.allocate_req
      cb_port.allocate_req = '{default: 0};
      for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
        if (mshr_next[i].valid && mshr_next[i].state_per_dw[0] == BEFORE_CB_ALLOCATION) begin
          cb_port.allocate_req = '{
              valid: 1,
              paddr_cl_aligned: mshr_next[i].paddr_cl_aligned,
              mshr_idx: MSHR_IDX_WIDTH'(i),
              set_idx: mshr_next[i].set_idx
          };
          mshr_next[i].state_per_dw = '{default: DURING_CB_ALLOCATION};
          break;
        end
      end

    end


    // ------------------------------------------------------------
    // stall
    // -------------------------------------------------------------
    // availqに十分なスペースがなかった場合,あとinvalidate中はstallする.
    stall_req_in = (AVAILQ_SIZE - 32'(num_of_entries_in_availq_next) < NUM_OF_REQ_IN)
        ||  cache_state inside {CS_WAITING_INVALIDATE, CS_INVALIDATING};


    // ------------------------------------------------------------
    // MSHRのエントリ削除
    // ------------------------------------------------------------
    // mshr_nextではなく,mshrの状態の基づいてres_outかres_to_mshrかを判別している.
    // よって,mshr_nextがres_to_mshrの反映を行う前にエントリを削除してしまうと,
    // 行き場の無いres_to_mshrが生まれることになる.
    // そのため,mshrのエントリ削除は最後に行われる必要がある.
    for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
      if(mshr_next[i].valid && mshr_next[i].is_all_dw_updated && mshr_next[i].num_of_entries_in_readq == 0 && mshr_next[i].num_of_entries_in_writeq == 0)begin
        // 削除
        // $display("[LOG] mshr_next[%d] was deleted", i);
        mshr_next[i].valid = 0;
      end
    end

    // ------------------------------------------------------------
    // Invalidate (Write_back_all)
    // ------------------------------------------------------------
    // 全てのキャッシュの内容を書き戻してinvalidateする.
    // はじめに,cb_infoの内容を取得し,dirtyなら,write_backのためのread_reqをcbに送る.
    // そのcl内の情報をwirte_backし終わったらinvalidate_reqでそのclを無効化する.

    begin
      // この２つについては,fifoでないのでこの下でエントリ数を計算する.
      // 要するに,stateの決定に用いる値で,availqのエントリ数のように常に正しいものでは無い.
      int unsigned num_of_entries_in_mshr_next = 0;
      int unsigned num_of_entries_in_invalidate_buf_next = 0;

      int unsigned invalidate_allocate_counter = 0;
      int unsigned read_req_to_cb_counter = 0;
      int unsigned delete_counter = 0;
      logic has_written_back_all = 0;
      logic all_invalidate_entries_registered = 0;

      for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
        if (mshr_next[i].valid) begin
          num_of_entries_in_mshr_next++;
        end
      end

      for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
        if (invalidate_buf_next[i].valid) begin
          num_of_entries_in_invalidate_buf_next++;
        end
      end

      // cb_portへのreqの初期化
      cb_port.invalidate_get_info_req = '{default: 0};
      cb_port.invalidate_req = '{default: 0};
      invalidate_all_done_sig = 0;

      // 次のstateの決定.
      if (invalidate_all_sig && cache_state == CS_NORMAL) begin
        cache_state_next = CS_WAITING_INVALIDATE;
        invalidate_set_counter_next = 0;
        invalidate_way_counter_next = 0;
      end else if(cache_state == CS_WAITING_INVALIDATE && num_of_entries_in_availq_next == 0 &&
                num_of_entries_in_tmb_next == 0 && num_of_entries_in_is_next == 0 && num_of_entries_in_mshr_next ==0)begin
        // invalidate の開始.
        cache_state_next = CS_INVALIDATING;
      end else if(cache_state== CS_INVALIDATING &&
                invalidate_set_counter_next == NUM_OF_SETS &&
                num_of_entries_in_invalidate_buf_next == 0 && num_of_entries_in_availq_next == 0 &&
                num_of_entries_in_tmb_next == 0 && num_of_entries_in_is_next == 0 && num_of_entries_in_mshr_next ==0)begin
        // 終了したのでNORMALに戻して通常の処理を再開する
        // このとき,invalidate_way_couter は NUM_OF_WAYSになる.(NUM_OF_WAYS-1ではない)
        cache_state_next = CS_NORMAL;
        invalidate_all_done_sig = 1;
      end

      // invalidate_bufを使って,cbの全てを無効化,及び書き戻しを行う.
      if (cache_state == CS_INVALIDATING) begin

        // cb_portからの情報リクエストのレスポンス.
        if (cb_port.invalidate_get_info_res.valid) begin
          invalidate_buf_next[cb_port.invalidate_get_info_res.invalidate_buf_idx].paddr_cl_aligned = cb_port.invalidate_get_info_res.paddr_cl_aligned;

`ifdef CACHE_INV_EN
          $fdisplay(fp_invalidate_dump, "[%0t] invalidate_get_info_res", $time);
          $fdisplay(fp_invalidate_dump, "  valid            = %0b",
                    cb_port.invalidate_get_info_res.valid);
          $fdisplay(fp_invalidate_dump, "  dirty            = %0b",
                    cb_port.invalidate_get_info_res.dirty);
          $fdisplay(fp_invalidate_dump, "  cl_valid         = %0b",
                    cb_port.invalidate_get_info_res.cl_valid);
          $fdisplay(fp_invalidate_dump, "  paddr_cl_aligned = 0x%016h",
                    cb_port.invalidate_get_info_res.paddr_cl_aligned);
          $fdisplay(fp_invalidate_dump, "  invalidate_buf_idx = %0d",
                    cb_port.invalidate_get_info_res.invalidate_buf_idx);
`endif
          // dirtyの場合,書き戻す必要がある.
          if (cb_port.invalidate_get_info_res.dirty) begin
            invalidate_buf_next[cb_port.invalidate_get_info_res.invalidate_buf_idx].state_per_dw = '{
                default: BEFORE_WRITE_BACK
            };
            // wbb_infoの確保.
            wbb_info_next[cb_port.invalidate_get_info_res.invalidate_buf_idx] = '{
                valid: 1,
                paddr_cl_aligned: cb_port.invalidate_get_info_res.paddr_cl_aligned,
                data_valid_per_dw: 0,
                data_already_wrote_back: 0
            };
          end else begin
            invalidate_buf_next[cb_port.invalidate_get_info_res.invalidate_buf_idx].state_per_dw = '{
                default: BEFORE_REQUEST
            };
          end
        end


        // cb_port.に情報のリクエスト
        for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
          if(invalidate_buf_next[i].valid && invalidate_buf_next[i].state_per_dw[0] == BEFORE_CB_ALLOCATION &&
            invalidate_allocate_counter < 1)begin
            // cb_portへ
            cb_port.invalidate_get_info_req = '{
                valid: 1,
                invalidate_buf_idx: MSHR_IDX_WIDTH'(i),
                set_idx: invalidate_buf_next[i].set_idx,
                way_idx: invalidate_buf_next[i].way_idx
            };
            invalidate_buf_next[i].state_per_dw = '{default: DURING_CB_ALLOCATION};
            invalidate_allocate_counter++;
          end
        end

        // cb_port.read_reqにwrite_backのリクエストを送る.
        for (
            int unsigned invalidate_buf_idx = 0;
            invalidate_buf_idx < MSHR_SIZE;
            invalidate_buf_idx++
        ) begin
          for (int unsigned dw_in_cl_idx = 0; dw_in_cl_idx < NUM_OF_DW_IN_CL; dw_in_cl_idx++) begin
            if (invalidate_buf_next[invalidate_buf_idx].state_per_dw[dw_in_cl_idx] == BEFORE_WRITE_BACK && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
              cb_port.read_req[read_req_to_cb_counter] = '{
                  valid: 1,
                  id:
                  invalidate_buf_idx, // wbbとinvalidate_bufのidxは共通なので,res_to_wbbがどのwbbかを判別するのに使う.
                  id_sub: 0,
                  generation: 0,
                  req_policy: READ_DOUBLE_WORD,
                  cb_req_type: READ_WRITE_BACK,
                  vaddr_dw_aligned: 0,
                  paddr_valid: 1,
                  paddr_dw_aligned:
                  invalidate_buf_next[invalidate_buf_idx].paddr_cl_aligned
                  +
                  dw_in_cl_idx
                  * 8,
                  byte_in_dw_idx: 0,
                  satp: 0,
                  data: 0
              };
              invalidate_buf_next[invalidate_buf_idx].state_per_dw[dw_in_cl_idx] = DURING_WRITE_BACK;
              read_req_to_cb_counter++;
            end
          end
        end

        // invalidate_bufのエントリで,全ての内容をwrite_backしたもの(BEFORE_REQUESTのもの)を削除
        delete_counter = 0;
        for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
          has_written_back_all = 1;
          for (int unsigned j = 0; j < NUM_OF_DW_IN_CL; j++) begin
            if (invalidate_buf_next[i].state_per_dw[j] != BEFORE_REQUEST) begin
              has_written_back_all = 0;
            end
          end

          // invalidate_bufのエントリ削除.
          // invalidate_reqを送らないといけないので,1サイクルに消せるのは1つまで.
          if (invalidate_buf_next[i].valid && has_written_back_all && delete_counter < 1) begin
            cb_port.invalidate_req = '{
                valid: 1,
                set_idx: invalidate_buf_next[i].set_idx,
                way_idx: invalidate_buf_next[i].way_idx
            };
            invalidate_buf_next[i].valid = 0;
            delete_counter++;
          end
        end

        // 空きに新しいエントリを追加.
        for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
          // すでに全てののラインについて走査が終わっている,あるいはinvalidate_bufに入っているか.
          all_invalidate_entries_registered = invalidate_set_counter_next == NUM_OF_SETS;
          if (!invalidate_buf_next[i].valid && !all_invalidate_entries_registered) begin
            invalidate_buf_next[i] = '{
                valid: 1,
                paddr_cl_aligned: 0,
                set_idx: SET_IDX_WIDTH'(invalidate_set_counter_next),
                way_idx: WAY_IDX_WIDTH'(invalidate_way_counter_next),
                state_per_dw: '{default: BEFORE_CB_ALLOCATION}
            };
            if (invalidate_way_counter_next == NUM_OF_WAYS - 1) begin
              invalidate_set_counter_next = invalidate_set_counter_next + 1;
              invalidate_way_counter_next = 0;
            end else begin
              invalidate_way_counter_next = invalidate_way_counter_next + 1;
            end
          end
        end

        // wbbでreq_outで書き出しが終わったら,DURING_WRITE_BACK => BEFORE_REQUEST
        // この処理はwbbの処理の方で行われる.

      end

    end

  end



  // ---------------------------------------------------------------
  // req_out_tmp => req_out
  // ---------------------------------------------------------------
  // wbbの為にreq_out_tmpにwbbのデータをマージして出力.

  always_comb begin
    // 初期化
    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      req_out[i] = '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};
    end

    // wirte_backのreq_outの場合,wbbから読み出したデータをマージして出力.
    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      req_out[i] = req_out_tmp[i];
      if (req_out_tmp[i].valid && req_out_tmp[i].cb_req_type == WRITE_REQ_FROM_UPPER) begin
        req_out[i] = req_out_tmp[i];
        req_out[i].data = wbb_r_data[req_out_tmp[i].paddr_dw_aligned[DW_IN_WB_BLOCK_IDX_MSB:DW_IN_WB_BLOCK_IDX_LSB]];
`ifdef CACHE_WB_EN
        $fdisplay(
            fp_write_back_dump,
            "[%0t] req_out[%0d]: v=%0b id=%0d sub=%0d gen=%0d policy=%0d type=%0d vaddr=%h pvalid=%0b paddr=%h byte=%0d data=%h",
            $time, i, req_out[i].valid, req_out[i].id, req_out[i].id_sub, req_out[i].generation,
            req_out[i].req_policy, req_out[i].cb_req_type, req_out[i].vaddr_dw_aligned,
            req_out[i].paddr_valid, req_out[i].paddr_dw_aligned, req_out[i].byte_in_dw_idx,
            req_out[i].data
            // satp は定義にあわせて req_out[i].satp.xxx にする
        );
`endif
      end
    end
  end

  // ---------------------------------------------------------------
  // cb_port.mshr_cl_aligned_paddrの作成.
  // ---------------------------------------------------------------
  always_comb begin
    // おそらくこれをmshr_nextからやるとcicularになるので.mshrから行う(重要)
    // 処理中のmshrに対応するpaddrを送ることで,mshrの処理が終わる(all_updatedになる)前に後続の命令が
    // 勝手にcbの内容を読むことで同じアドレスに対するrwの順番が崩れるのを防止する.
    // 初期化
    for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
      cb_port.mshr_processing_info[mshr_idx] = '{default: 0};
    end
    for (int unsigned mshr_idx = 0; mshr_idx < MSHR_SIZE; mshr_idx++) begin
      if (mshr[mshr_idx].valid && !mshr[mshr_idx].is_all_dw_updated) begin
        cb_port.mshr_processing_info[mshr_idx] = '{
            valid: mshr[mshr_idx].valid,
            is_all_dw_updated: mshr[mshr_idx].is_all_dw_updated,
            paddr_cl_aligned: mshr[mshr_idx].paddr_cl_aligned
        };
      end
    end
  end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      mshr <= '{default: 0};
      wbb_info <= '{default: 0};

      // availq
      availq <= '{default: 0};
      availq_rp <= 0;
      availq_wp <= 0;
      num_of_entries_in_availq <= 0;

      // tmb
      tmb <= '{default: 0};
      num_of_entries_in_tmb <= 0;

      // fb
      fb_valid <= 0;
      fb <= '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};

      // is
      is <= '{default: 0};
      is_rp <= 0;
      is_wp <= 0;
      num_of_entries_in_is <= 0;

      // invalidate_buf
      cache_state <= CS_NORMAL;
      invalidate_set_counter <= 0;
      invalidate_way_counter <= 0;
      invalidate_buf <= '{default: 0};

      // 出力
      req_out_tmp <= '{default: 0};

      display_counter <= 0;
    end else begin
      // MSHR
      mshr <= mshr_next;

      // wbb
      wbb_info <= wbb_info_next;

      // availq
      availq <= availq_next;
      availq_rp <= availq_rp_next;
      availq_wp <= availq_wp_next;
      num_of_entries_in_availq <= num_of_entries_in_availq_next;

      // tmb
      tmb <= tmb_next;
      num_of_entries_in_tmb <= num_of_entries_in_tmb_next;

      // fb
      if (fb_used) begin
        fb_valid <= 0;
        fb <= '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};
      end else begin
        fb_valid <= fb_valid_next;
        fb <= fb_next;
      end


      // is
      is <= is_next;
      is_rp <= is_rp_next;
      is_wp <= is_wp_next;
      num_of_entries_in_is <= num_of_entries_in_is_next;

      // invalidate_buf
      cache_state <= cache_state_next;
      invalidate_set_counter <= invalidate_set_counter_next;
      invalidate_way_counter <= invalidate_way_counter_next;
      invalidate_buf <= invalidate_buf_next;

      // 出力
      req_out_tmp <= req_out_tmp_next;


      display_counter <= display_counter + 1;
    end
  end

endmodule
