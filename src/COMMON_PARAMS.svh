// 各種パラメータの設定.

`ifndef COMMON_PARAMS_IFDEF
`define COMMON_PARAMS_IFDEF

// -----------------------------------
// デバッグ用パラメータ
// -----------------------------------
// コメントアウトするとログを取らなくなる.
// コミットログ.
// `ifndef COMMITLOG_EN
// `define COMMITLOG_EN
// `endif

// // メインログ(詳細なコミットログ).
// `ifndef MAINLOG_EN
// `define MAINLOG_EN
// `endif

// `ifndef PCGENLOG_EN
// `define PCGENLOG_EN
// `endif

// // cacheのwrite_back
// `ifndef CACHE_WB_EN
// `define CACHE_WB_EN
// `endif

// // cacheのinvalidate
// `ifndef CACHE_INV_EN
// `define CACHE_INV_EN
// `endif

// cacheのres_out
// `ifndef CACHE_RES_OUT_EN
// `define CACHE_RES_OUT_EN
// `endif

// // cacheのreq_in
// `ifndef CACHE_REQ_IN_EN
// `define CACHE_REQ_IN_EN
// `endif

// // ifq
// `ifndef IFQ_EN
// `define IFQ_EN
// `endif

// // decoder
// `ifndef DECODERLOG_EN
// `define DECODERLOG_EN
// `endif

// // pw
// `ifndef PW_EN
// `define PW_EN
// `endif

// mainmermoy
// `ifndef MMLOG_EN
// `define MMLOG_EN
// `endif


// uart device
// `ifndef UARTLOG_EN
// `define UARTLOG_EN
// `endif

// CSR RF 
// `ifndef CSRRFLOG_EN
// `define CSRRFLOG_EN
// `endif

package COMMON_PARAMS;

  // --------------------------------
  // 基礎設定(固定)
  // --------------------------------
  // 1サイクルでフェッチする命令の数.
  localparam int unsigned NUM_OF_FETCH = 4;
  // SV39
  localparam int unsigned VADDR_WIDTH = 39;
  localparam int unsigned PADDR_WIDTH = 56;

  // ページサイズは4KiB
  localparam int unsigned PAGESIZE = 4096;
  localparam int unsigned PAGE_OFFSET_WIDTH = $clog2(PAGESIZE);

  // Double-wordのサイズ.64bit=8Byte
  localparam int unsigned DW_SIZE = 8;

  // 型のサイズ
  localparam int unsigned INT_SIZE = 32;

  // レジスタ長
  localparam int unsigned XLEN = 64;
  localparam int unsigned WORD_SIZE = 32;
  localparam int unsigned DWORD_SIZE = 64;

  // 論理レジスタの数.
  localparam int unsigned NUM_OF_LOGREGS = 32;

  // メモリサイズ(Byte)
  // DRAMが32bitなのでMEMORYSIZE1をあまり大きくしないこと.
  // 16MiByte
  localparam logic [PADDR_WIDTH-1:0] MEMORY_SIZE = 16 * 1024 * 1024;

  localparam logic [PADDR_WIDTH-1:0] DRAM_BASE = PADDR_WIDTH'(32'h8000_0000);

  // ----------------------------------------
  // 性能パラメータ
  // ----------------------------------------

  // Active Listのサイズ(=最大in flight数)
  localparam int unsigned ACTIVELIST_SIZE = 64;


  // 物理レジスタの数.
  // arithmetic register と robが別々ではなく,一つの物理レジスタになっているタイプなので,
  // 物理レジスタの数 >= activelistのサイズ + 論理レジスタの数 である必要がある.
  localparam int unsigned NUM_OF_PHYREGS = ACTIVELIST_SIZE + 32;
  localparam int unsigned PHYREGS_IDX_WIDTH = $clog2(NUM_OF_PHYREGS);


  // アドレス変換を行わない場合(テスト用)
  localparam logic MMU_DISABLED = 0;

  // メインメモリのサイズ(Byte単位)
  localparam int unsigned MM_SIZE = 16 * 1024 * 1024;

  // ページウォーカーの数.
  localparam int unsigned NUM_OF_PW = 4;


  // キャッシュの性能パラメターはsetサイズ+clsizeがpageサイズを越えないように注意.
  // ICache性能パラメータ
  localparam int unsigned NUM_OF_ICACHE_WAY = 4;
  localparam int unsigned NUM_OF_ICACHE_SET = 64;
  localparam int unsigned ICACHE_MSHR_SIZE = 8;

  // DCache性能パラメータ.
  localparam int unsigned NUM_OF_DCACHE_WAY = 4;
  localparam int unsigned NUM_OF_DCACHE_SET = 64;
  localparam int unsigned DCACHE_MSHR_SIZE = 8;

  // ITLB
  localparam int unsigned NUM_OF_ITLB_WAYS = 4;
  localparam int unsigned NUM_OF_ITLB_SETS = 128;

  // DTLB
  localparam int unsigned NUM_OF_DTLB_WAYS = 4;
  localparam int unsigned NUM_OF_DTLB_SETS = 128;


  // -------------------------------------------------------------
  // Active List
  // --------------------------------------------------------------
  // アクティブリストのエントリ数.
  // ROB
  localparam int unsigned AL_IDX_WIDTH = $clog2(ACTIVELIST_SIZE);

  // 1サイクルで卒業する命令の数.基本的には NUM_OF_FETCH に同じ.
  localparam int unsigned NUM_OF_GRADUATE = 4;

  localparam int unsigned NUM_OF_TENTATIVE_ISSUE_OUT = 4;

  // --------------------------------------------------------------
  // Int Issue Queue
  // --------------------------------------------------------------
  // 発行数
  localparam int unsigned NUM_OF_ARI_ISSUE = 2;
  localparam int unsigned NUM_OF_CSR_ISSUE = 1;
  localparam int unsigned NUM_OF_LD_ISSUE = 2;
  localparam int unsigned NUM_OF_ST_AMO_ISSUE = 1;

  localparam int unsigned NUM_OF_LDST_ISSUE = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;
  localparam int unsigned NUM_OF_ISSUE = NUM_OF_ARI_ISSUE + NUM_OF_CSR_ISSUE + NUM_OF_LDST_ISSUE;

  // active listでこれ
  localparam int unsigned LDQ_SIZE = 64;
  localparam int unsigned STQ_SIZE = 64;
  localparam int unsigned FENCEQ_SIZE = 64;

  // ------------------------------------------------------------
  // 各実行ユニットの実行数
  // ------------------------------------------------------------
  localparam int unsigned NUM_OF_ARI_EXE = NUM_OF_ARI_ISSUE;
  localparam int unsigned NUM_OF_CSR_EXE = NUM_OF_CSR_ISSUE;

  // 1サイクルにSTQから何個のst命令を実行するか.
  // 1サイクルにNUM_OF_ST_EXEより多くのst命令を卒業させることはできない.
  localparam int unsigned NUM_OF_ST_EXE = 1;
  localparam int unsigned NUM_OF_LD_EXE = 2;

  // mmioの実行.


  // 
  localparam int unsigned NUM_OF_DCACHE_OUT = 2;

  // ld,stにしろmmioはalの先頭でないと実行されないので,2つ以上が同時に実行されることはない.
  localparam int unsigned NUM_OF_MMIO_EXE = 1;

  // 実行ユニットの出力ポートの合計が最大のフィードバック数.
  localparam int unsigned NUM_OF_RESULT_FEEDBACKS = NUM_OF_ARI_EXE + NUM_OF_LD_EXE + NUM_OF_ST_EXE + NUM_OF_MMIO_EXE + NUM_OF_CSR_EXE;

  // ---------------------------------
  // DCacheのパラメータ
  // ---------------------------------
  localparam int unsigned DCACHE_LINE_SIZE = 512;


  localparam int unsigned DCAHCE_WAY_IDX_WIDTH = $clog2(NUM_OF_DCACHE_WAY);
  localparam int unsigned DCACHE_SET_IDX_WIDTH = $clog2(NUM_OF_DCACHE_SET);

  localparam int unsigned NUM_OF_DCACHE_CB_READ_REQ = NUM_OF_LD_EXE;
  localparam int unsigned NUM_OF_DCACHE_CB_WRITE_REQ = NUM_OF_ST_EXE;


  // Dcacheからの返却はnum_of_ld_exeにするのは,入力と大きさを合わせてボトルネックにならないようにするため.
  // なお,st命令からは返却が無いためその分のres用ポートは用意していない.
  // あと,PWをdcacheをつなぐことにしたのでその分reqの数を増やす.
  localparam int unsigned NUM_OF_REQ_TO_DCACHE = NUM_OF_LD_EXE + NUM_OF_ST_EXE + NUM_OF_PW;
  localparam int unsigned NUM_OF_RES_FROM_DCACHE = NUM_OF_DCACHE_CB_READ_REQ;


  // --------------------------------
  // ICacheのパラメータ
  // --------------------------------
  localparam int unsigned ICACHE_LINE_SIZE = 512;

  localparam int unsigned ICAHCE_WAY_IDX_WIDTH = $clog2(NUM_OF_ICACHE_WAY);
  localparam int unsigned ICACHE_SET_IDX_WIDTH = $clog2(NUM_OF_ICACHE_SET);

  localparam int unsigned NUM_OF_ICACHE_CB_READ_REQ = 3;
  // キャッシュのアップデート用に書き込みは必要.
  localparam int unsigned NUM_OF_ICACHE_CB_WRITE_REQ = 1;


  // Cacheで取り扱うDW単位で,一つのDWの中にいくつの命令が入っているのか.
  localparam int unsigned NUM_OF_DW_IN_FETCH = 2;
  // pcがdwアラインメントされていると仮定した場合,リクエストは2つだが,
  // pcがdwアラインメントされていない場合,リクエストは3つになる.
  localparam int unsigned NUM_OF_REQ_TO_ICACHE = 3;
  // page_fault時にtmbからのレスポンスの分+1.
  localparam int unsigned NUM_OF_RES_FROM_ICACHE = NUM_OF_ICACHE_CB_READ_REQ;


  // ------------------------------------------------
  // L2Cacheのパラメータ
  // -------------------------------------------------
  localparam int unsigned NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE = 1;


  // --------------------------------------------------
  // メインメモリ
  // --------------------------------------------------
  localparam int unsigned NUM_OF_DW_IN_MM_PORT = 2;



  // --------------------------------------------------------
  // ITLB
  // --------------------------------------------------------
  localparam int unsigned NUM_OF_REQ_TO_ITLB = NUM_OF_ICACHE_CB_READ_REQ + NUM_OF_ICACHE_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_RES_FROM_ITLB = NUM_OF_REQ_TO_ITLB;


  // --------------------------------------------------------
  // DTLB
  // --------------------------------------------------------

  localparam int unsigned NUM_OF_REQ_TO_DTLB = NUM_OF_DCACHE_CB_READ_REQ + NUM_OF_DCACHE_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_RES_FROM_DTLB = NUM_OF_REQ_TO_DTLB;

endpackage

`endif
