// Cache.sv <=> CacheCB.sv
//
//  ----------------------------------------------------------------------
//  |      tag           |   set_index  |   dw_in_cl_idx  |    dw_offset |
//  ----------------------------------------------------------------------
//  ----------------------------------------------------------------------
//  |                                   |          cl_offset             |
//  ----------------------------------------------------------------------
//                                       <-------Cache Line------------->
// 
//


`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"
`include "CSR_PROPS.svh"


interface cache_cb_if #(
    parameter int unsigned NUM_OF_CB_WRITE_REQ = 1,
    parameter int unsigned NUM_OF_CB_READ_REQ  = 2,

    parameter int unsigned MSHR_SIZE = 8,

    // Byte単位.
    parameter int unsigned CL_SIZE = 64,

    parameter int unsigned NUM_OF_WAYS = 4,
    parameter int unsigned NUM_OF_SETS = 64
);
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
  import CSR_PROPS::*;

  // Cache Line
  localparam int unsigned CL_OFFSET_WIDTH = $clog2(CL_SIZE);
  localparam int unsigned CL_OFFSET_LSB = 0;
  localparam int unsigned CL_OFFSET_MSB = CL_OFFSET_WIDTH - 1;

  // キャッシュラインの中でのdwの数.
  localparam int unsigned NUM_OF_DW_IN_CL = CL_SIZE / DW_SIZE;
  // dw_in_cl_idx
  localparam int unsigned DW_IN_CL_IDX_WIDTH = $clog2(NUM_OF_DW_IN_CL);
  localparam int unsigned DW_IN_CL_IDX_MSB = DW_IN_CL_IDX_WIDTH + $clog2(DW_SIZE) - 1;
  localparam int unsigned DW_IN_CL_IDX_LSB = $clog2(DW_SIZE);

  // MSHRで用いるために,cache line単位でアラインされたpaddrを抜き出すためのMSBとLSB
  localparam int unsigned CL_ALIGNED_PADDR_MSB = PADDR_WIDTH - 1;
  localparam int unsigned CL_ALIGNED_PADDR_LSB = CL_OFFSET_WIDTH;

  // SET_IDX
  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SETS);
  localparam int unsigned SET_IDX_MSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH - 1;
  localparam int unsigned SET_IDX_LSB = CL_OFFSET_WIDTH;

  // TAG
  localparam int unsigned TAG_WIDTH = PADDR_WIDTH - SET_IDX_WIDTH - CL_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = PADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH;

  // WAY_IDX
  localparam int unsigned WAY_IDX_WIDTH = $clog2(NUM_OF_WAYS);

  // TLB_PORT
  localparam int unsigned NUM_OF_TLB_PORT = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ;

  // MSHR
  localparam int unsigned MSHR_IDX_WIDTH = $clog2(MSHR_SIZE);

  // -----------------------------------------------------------
  // Cache.sv <=> CacheCB.sv の Read, Write の Req,Res
  // -----------------------------------------------------------
  cache_req_t read_req[NUM_OF_CB_READ_REQ];
  cache_req_t write_req[NUM_OF_CB_WRITE_REQ];

  // tlbから1サイクルで帰ってこなかった場合.
  cache_req_t res_to_tmb[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  cache_res_t res_to_wbb[NUM_OF_CB_READ_REQ];

  cache_req_t res_to_mshr[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  cache_res_t res_out[NUM_OF_CB_READ_REQ];


  // TODO: wbb


  // -------------------------------------------------------------
  // MSHR情報のやり取り
  // -------------------------------------------------------------
  // CacheCB.sv => Cache.sv
  // MSHRのstate_per_dwのうち,
  // BEFORE_WRITE_BACK => DURING_WRITE_BACK
  // DURING_REQUEST => CB_UPDATED
  // の2つはcbからデータを読み込んだとき,cbにデータを書き込んだときに更新するため,
  // Cache.svとCacheCB.svの間でデータのやり取りが必要.
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [DW_IN_CL_IDX_WIDTH-1:0] dw_in_cl_idx;
    state_per_dw_t state_per_dw;
  } mshr_new_state_t;
  mshr_new_state_t mshr_new_state[NUM_OF_CB_WRITE_REQ+NUM_OF_CB_READ_REQ];

  // 現在のmshrエントリが処理中のpaddr
  typedef struct packed {
    logic valid;
    logic is_all_dw_updated;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
  } mshr_processing_info_t;
  mshr_processing_info_t mshr_processing_info[MSHR_SIZE];

  // -------------------------------------------------------------
  // mshrに対応する新しいキャッシュラインの確保.
  // -------------------------------------------------------------
  // 新しいcbエントリの確保リクエスト.
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [SET_IDX_WIDTH-1:0] set_idx;
  } allocate_req_t;

  // 確保されたcbエントリに関する情報.
  typedef struct packed {
    logic valid;
    logic success;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
    logic wb_need;  // キャッシュラインがdirtyならwrite_backが必要.
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned_prev;  // 書き戻すために前のpaddrを記録.
  } allocate_res_t;



  // cb_info のポート数は限られおり,cb_infoのポートのNUM_OF_REQ個はCBのリクエスト処理に使われるので,
  // allocationに使えるcb_infoのポートは1つだけ.よってresは配列にしない.
  // 一方で,バッファがあるのでreqはまとめて送っていいい.
  allocate_req_t allocate_req;
  allocate_res_t allocate_res;

  // invalidate_
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] invalidate_buf_idx;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
  } invalidate_get_info_req_t;

  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [MSHR_IDX_WIDTH-1:0] invalidate_buf_idx;
    logic dirty;
    // validはこのresが有効か,cl_validはcb_data,cb_infoが有効か.
    logic cl_valid;
  } invalidate_get_info_res_t;

  invalidate_get_info_req_t invalidate_get_info_req;
  invalidate_get_info_res_t invalidate_get_info_res;

  typedef struct packed {
    logic valid;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
  } invalidate_req_t;

  invalidate_req_t invalidate_req;


  modport cache_buffer(
      input allocate_req, read_req, write_req, mshr_processing_info, invalidate_get_info_req,invalidate_req,
      output allocate_res, res_to_tmb, res_out, res_to_mshr, res_to_wbb, mshr_new_state,invalidate_get_info_res
  );

  modport cache_main(
      output allocate_req, read_req, write_req, mshr_processing_info, invalidate_get_info_req,invalidate_req,
      input allocate_res, res_to_tmb, res_out, res_to_mshr, res_to_wbb, mshr_new_state,invalidate_get_info_res
  );

endinterface
