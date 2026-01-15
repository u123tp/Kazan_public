// DCache.svとDCacheTable.svの通信に用いる構造体等を定義する.

`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"
`include "CSR_PROPS.svh"

`ifndef DCACHE_PROPS_IFDEF
`define DCACHE_PROPS_IFDEF


package CACHE_PROPS;
  import COMMON_PARAMS::*;
  import HART_DEFS::*;
  import CSR_PROPS::*;

  // --------------------------------------------------------------------------
  // MSHRのステータス
  // --------------------------------------------------------------------------
  // mshrのエントリに対応するinput stackのエントリは,mshrの入っている場所と同じ位置(idx)に存在する.
  // キャッシュライン64Byteを8つのdw単位のバンクに分割したものの状態.
  // dw単位で状態を管理.
  typedef enum logic [2:0] {
    BEFORE_CB_ALLOCATION = 3'b000,  // cbの確保には1サイクルかかるので,それが完了するまでのステータス
    DURING_CB_ALLOCATION = 3'b001,
    BEFORE_WRITE_BACK = 3'b010,  //
    DURING_WRITE_BACK = 3'b011,  //
    BEFORE_REQUEST = 3'b100,  //
    DURING_REQUEST = 3'b101,  // リクエスト中.
    CB_UPDATED = 3'b110,  // リクエストの内容がcbに反映された状態.
    STATE_PER_DW_NONE = 3'b111
  } state_per_dw_t;

  // ----------------------------------------------------------------
  // reqのマスクと符号拡張ポリシー
  // ----------------------------------------------------------------
  typedef enum logic [3:0] {
    READ_BYTE = 4'b0000,
    READ_HALF_WORD = 4'b0001,
    READ_WORD = 4'b0010,
    READ_DOUBLE_WORD = 4'b0011,
    WRITE_BYTE = 4'b0100,
    WRITE_HALF_WORD = 4'b0101,
    WRITE_WORD = 4'b0110,
    WRITE_DOUBLE_WORD = 4'b0111,
    REQ_POLICY_NONE = 4'b1000
  } req_policy_e;



  // ----------------------------------------------------------
  // CBから読み出したものの送り先.
  // ----------------------------------------------------------
  typedef enum logic [2:0] {
    READ_WRITE_BACK = 3'b000,  // CBから読み込んで,write-backの為に下位レイヤに内容を送る
    READ_REQ_FROM_UPPER = 3'b001,  // 上位レイヤからの読み込みリクエスト
    WRITE_UPDATE = 3'b010,         // リクエストに対する下位レイヤからの返答で新しい情報にcbをアップデートする
    WRITE_REQ_FROM_UPPER = 3'b011,  // 上位レイヤからの書き込みリクエスト
    CB_REQ_TYPE_NONE = 3'b100
  } cb_req_type_e;


  // ---------------------------------------------------------------------
  // Cacheの入出力
  // ---------------------------------------------------------------------
  // CPU <=> L1Cache, L1Cache <=> L2Cache のやり取りの構造体
  // availqにもcache_req_t の形で入れる.
  // すべてのリクエストは64bit単位で行う.
  typedef struct packed {
    logic valid;

    // Cache_Subsystemに入れるときにつけられる一意な番号.ROBの番号とか.
    // キャッシュから更に下位レイヤに送ったreqが戻ってきたときは,cbをアップデートするだけなのでidのようなものは不要.
    int unsigned id;
    // dcache => l2cache か icache => l2cache かの判断に用いる.
    // そのため,dcacheから出ていくreqやicacheから出ていくreq以外には用いない.
    // これlogicでよくね?
    int unsigned id_sub;


    // flushしてもcacheに出したreqは消さないので,
    // flush前のread_reqに対するresを受け取らないようにgenerationで管理する.
    int unsigned generation;

    req_policy_e  req_policy;
    cb_req_type_e cb_req_type;

    logic [VADDR_WIDTH-1:0] vaddr_dw_aligned;
    // piptならpaddr_valid==1でpaddrを渡す(この時vaddrは使用しない).viptならpaddr_valid==0
    logic paddr_valid;
    logic [PADDR_WIDTH-1:0] paddr_dw_aligned;
    logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx;


    // viptならsatpを用いてキャッシュの内部でtlbを探索する.
    csr_reg_u satp;
    logic [XLEN-1:0] data;
  } cache_req_t;

  typedef struct packed {
    logic valid;
    int unsigned id;
    int unsigned id_sub;
    int unsigned generation;

    // page_faultを起こすようなリクエストの場合.
    logic is_page_fault;
    // access faultを起こすようなリクエストだった場合
    logic is_access_fault;

    req_policy_e  req_policy;
    cb_req_type_e cb_req_type;

    logic [VADDR_WIDTH-1:0] vaddr_dw_aligned;
    logic [PADDR_WIDTH-1:0] paddr_dw_aligned;
    logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx;
    logic [63:0] data;
  } cache_res_t;



endpackage

`endif
