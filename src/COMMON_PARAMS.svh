// 各種パラメータの設定.

`ifndef COMMON_PARAMS_IFDEF
`define COMMON_PARAMS_IFDEF

`ifndef VIVADO_COMPILE
`define VIVADO_COMPILE
`endif

// `ifndef VERILATOR_COMPILE
// `define VERILATOR_COMPILE
// `endif



// -----------------------------------
// デバッグ用パラメータ
// -----------------------------------

// // // // コメントアウトするとログを取らなくなる.
// // // コミットログ.
// `ifndef COMMITLOG_EN
// `define COMMITLOG_EN
// `endif

// // // // // メインログ(詳細なコミットログ).
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

// // cacheのreq_in
// `ifndef LSU_LOG
// `define LSU_LOG
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

// パラメタでかくした場合. 
`ifndef PRINT_IPC
`define PRINT_IPC
`endif

package COMMON_PARAMS;

  localparam int unsigned CLK_HZ = 17_856_964;

  // --------------------------------
  // 基礎設定
  // --------------------------------
  // 1サイクルでフェッチする命令の数.
  localparam int unsigned NUM_OF_FETCH = 4;
  localparam int unsigned NUM_OF_INSTR_IN_FETCH = NUM_OF_FETCH;

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

  // DW単位に含まれる命令の数
  localparam int unsigned INSTR_SIZE = 4;
  localparam int unsigned NUM_OF_INSTR_IN_DW = 2;
  localparam int unsigned NUM_OF_DW_IN_FETCH = NUM_OF_INSTR_IN_FETCH / NUM_OF_INSTR_IN_DW;

  // レジスタ長
  localparam int unsigned XLEN = 64;
  localparam int unsigned WORD_SIZE = 32;
  localparam int unsigned DWORD_SIZE = 64;

  // 論理レジスタの数.
  localparam int unsigned NUM_OF_LOGREGS = 32;

  // ----------------------------------------
  // 性能パラメータ
  // ----------------------------------------

  // Active Listのサイズ(=最大in flight数)
  // localparam int unsigned ACTIVELIST_SIZE = 8;
  localparam int unsigned ACTIVELIST_SIZE = 32;


  // 物理レジスタの数.
  // arithmetic register と robが別々ではなく,一つの物理レジスタになっているタイプなので,
  // 物理レジスタの数 >= activelistのサイズ + 論理レジスタの数 である必要がある.
  localparam int unsigned NUM_OF_PHYREGS = ACTIVELIST_SIZE + NUM_OF_LOGREGS;
  localparam int unsigned PHYREGS_IDX_WIDTH = $clog2(NUM_OF_PHYREGS);


  // アドレス変換を行わない場合(テスト用)
  localparam logic MMU_DISABLED = 0;


  // ページウォーカーの数.
  // TODO: 今の実装だと1固定なので後でMMUを改変.
  localparam int unsigned NUM_OF_PW = 1;

  // -------------------------------------------------------------
  // Active List
  // --------------------------------------------------------------
  // アクティブリストのエントリ数.
  // ROB
  localparam int unsigned AL_IDX_WIDTH = $clog2(ACTIVELIST_SIZE);

  // 1サイクルで卒業する命令の数.基本的には NUM_OF_FETCH に同じ.
  localparam int unsigned NUM_OF_GRADUATE = NUM_OF_FETCH;


  // --------------------------------------------------------------
  // Int Issue Queue
  // --------------------------------------------------------------
  // iiq自体のサイズ.
  // 実際のサイズはこれにNUM_OF_FETCHをかけたもの.
  localparam int unsigned IIQ_SIZE = 8;
  // 発行数
  // localparam int unsigned NUM_OF_ARI_ISSUE = 1;
  localparam int unsigned NUM_OF_ARI_ISSUE = 2;
  localparam int unsigned NUM_OF_DIV_ISSUE = 1;

  localparam int unsigned NUM_OF_CSR_ISSUE = 1;

  localparam int unsigned NUM_OF_LD_ISSUE = 1;
  localparam int unsigned NUM_OF_ST_AMO_ISSUE = 1;

  localparam int unsigned NUM_OF_LDST_ISSUE = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;
  localparam int unsigned NUM_OF_ISSUE = NUM_OF_ARI_ISSUE + NUM_OF_DIV_ISSUE + NUM_OF_CSR_ISSUE + NUM_OF_LDST_ISSUE;

  // ------------------------------------------------------------
  // 各実行ユニットの実行数
  // ------------------------------------------------------------
  localparam int unsigned NUM_OF_ARI_EXE = NUM_OF_ARI_ISSUE;
  localparam int unsigned NUM_OF_DIV_EXE = NUM_OF_DIV_ISSUE;
  localparam int unsigned NUM_OF_CSR_EXE = NUM_OF_CSR_ISSUE;

  // 1サイクルにSTQから何個のst命令を実行するか.
  // 1サイクルにNUM_OF_ST_EXEより多くのst命令を卒業させることはできない.
  localparam int unsigned NUM_OF_ST_EXE = 1;
  localparam int unsigned NUM_OF_LD_EXE = 1;

  // 
  localparam int unsigned NUM_OF_DCACHE_OUT = 1;

  // ld,stにしろmmioはalの先頭でないと実行されないので,2つ以上が同時に実行されることはない.
  // localparam int unsigned NUM_OF_MMIO_EXE = 1;

  // 実行ユニットの出力ポートの合計が最大のフィードバック数.
  localparam int unsigned NUM_OF_RESULT_FEEDBACKS = NUM_OF_ARI_EXE + NUM_OF_DIV_EXE + NUM_OF_LD_EXE + NUM_OF_ST_EXE +  NUM_OF_CSR_EXE;


  // --------------------------------------------------------------=
  // LSU
  // --------------------------------------------------------------=
  // 性能調整用パラメータ.
  // 各バンクごとのldq,stqのサイズ.
  // 本当はLDQは8*4=32くらいほしいが,LUT喰うのでとりあえず4*4=16.
  localparam int unsigned LDQ_BANK_SIZE = 8;
  localparam int unsigned STQ_BANK_SIZE = 8;
  // fenceqだけはバンク化しないので全体のサイズ.8以上にしないと壊れる?
  localparam int unsigned FENCEQ_SIZE = 8;

  // ------------------------------------------------------------------------------------------
  // pmp
  // ------------------------------------------------------------------------------------------
  // pmpcfgの数. pmpaddrはこれの8倍.
  localparam int unsigned NUM_OF_PMPCFG = 1;



  // ---------------------------------
  // DCacheのパラメータ
  // ---------------------------------
  localparam int unsigned NUM_OF_DCACHE_CB_READ_REQ = 1;
  localparam int unsigned NUM_OF_DCACHE_CB_WRITE_REQ = 1;


  // Dcacheからの返却はnum_of_ld_exeにするのは,入力と大きさを合わせてボトルネックにならないようにするため.
  // なお,st命令からは返却が無いためその分のres用ポートは用意していない.
  // あと,PWをdcacheをつなぐことにしたのでその分reqの数を増やす.
  localparam int unsigned NUM_OF_REQ_TO_DCACHE = NUM_OF_LD_EXE + NUM_OF_ST_EXE + NUM_OF_PW;
  localparam int unsigned NUM_OF_RES_FROM_DCACHE = NUM_OF_LD_EXE;


  // DCacheからメインメモリへのリクエスト.
  // localparam int unsigned NUM_OF_DCACHE_REQ_OUT = 1;
  // localparam int unsigned NUM_OF_DCACHE_RES_IN = 1;

  localparam int unsigned NUM_OF_REQ_FROM_DCACHE_TO_MM = 1;
  localparam int unsigned NUM_OF_RES_FROM_MM_TO_DCACHE = NUM_OF_REQ_FROM_DCACHE_TO_MM;


  // --------------------------------
  // ICacheのパラメータ
  // --------------------------------
  localparam int unsigned NUM_OF_REQ_TO_ICACHE = 1;
  localparam int unsigned NUM_OF_RES_FROM_ICACHE = NUM_OF_REQ_TO_ICACHE;


  localparam int unsigned NUM_OF_ICACHE_CB_READ_REQ = NUM_OF_REQ_TO_ICACHE;
  // キャッシュのアップデート用に書き込みは必要.
  localparam int unsigned NUM_OF_ICACHE_CB_WRITE_REQ = 1;

  // Icacheからメインメモリへのリクエスト.
  // localparam int unsigned NUM_OF_ICACHE_REQ_OUT = 1;
  // localparam int unsigned NUM_OF_ICACHE_RES_IN = NUM_OF_ICACHE_REQ_OUT;

  localparam int unsigned NUM_OF_REQ_FROM_ICACHE_TO_MM = 1;
  localparam int unsigned NUM_OF_RES_FROM_MM_TO_ICACHE = NUM_OF_REQ_FROM_ICACHE_TO_MM;

  // ------------------------------------------------
  // L2Cacheのパラメータ
  // -------------------------------------------------
  // 今l2cache消したので,NUM_OF_MM_PORT_CONNECTED_TO_L2Cache はNUM_OF_REQ_OUT_FROM_ICAHCE+NUM_OF_REQ_OUT_FROM_DCACHE
  // localparam int unsigned NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE = 2;


  // --------------------------------------------------------
  // ITLB
  // --------------------------------------------------------
  // localparam int unsigned NUM_OF_REQ_TO_ITLB = NUM_OF_ICACHE_CB_READ_REQ + NUM_OF_ICACHE_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_REQ_TO_ITLB = NUM_OF_ICACHE_CB_READ_REQ + NUM_OF_ICACHE_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_RES_FROM_ITLB = NUM_OF_REQ_TO_ITLB;


  // --------------------------------------------------------
  // DTLB
  // --------------------------------------------------------
  // NUM_OF_REQ_TO_DTLB = 3
  localparam int unsigned NUM_OF_REQ_TO_DTLB = NUM_OF_DCACHE_CB_READ_REQ + NUM_OF_DCACHE_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_RES_FROM_DTLB = NUM_OF_REQ_TO_DTLB;


endpackage

`endif
