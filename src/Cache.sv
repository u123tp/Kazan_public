`timescale 1ns / 1ps
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
//                                      | db_in_cl_idx     |       dw     |
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

`define MAX(a, b) (((a) > (b)) ? (a) : (b))


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
    parameter int unsigned NUM_OF_REQ_OUT = 1,
    parameter int unsigned NUM_OF_RES_IN  = 1,

    // CacheCBで実際に1サイクルに処理するread_req, write_reqの数. 
    parameter int unsigned NUM_OF_CB_READ_REQ  = 1,
    parameter int unsigned NUM_OF_CB_WRITE_REQ = 1,

    // 下位レイヤとやり取りするときに,いくつのDW単位でやり取りすればいいか.
    // 具体的には,メインメモリとは128bitでやり取りするので64bit*2となる.
    // l1キャッシュとl2キャッシュのやり取りの場合は1でいい.
    // parameter int unsigned NUM_OF_DW_IN_BULK = 2,

    // キャッシュバッファのパラメータ.
    parameter int unsigned NUM_OF_WAYS = 2,

    // 良くは無いがとりあえずこれでlutを抑える.
    // 他が終わったらキャッシュの設計をやり直す.
    parameter int unsigned NUM_OF_SETS = 32,

    // キャッシュラインのサイズ（単位はByte）
    parameter int unsigned CL_SIZE = 32,

    // req_outでdw何個づつ出力するか.
    // 上位レイヤではdw単位でやり取りするが,メインメモリとのやり取りなどは幅がDW_SIZE*2とかになるため.
    // parameter int unsigned NUM_OF_DW_IN_REQ_OUT = 2,

    parameter int unsigned REQ_TO_TLB   = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ,
    parameter int unsigned RES_FROM_TLB = REQ_TO_TLB,

    // reqのデータサイズを64bitと128bitで切り返る.
    parameter type cache_req_t = cache_req64_t,
    parameter type cache_res_t = cache_res64_t,
    // 単位はbyte
    parameter int unsigned DATA_BULK_SIZE = 8,

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
    output logic invalidate_all_done_sig,

    output logic data_print_en,
    output logic [255:0] data_print
);

  // Cache Line
  localparam int unsigned CL_OFFSET_WIDTH = $clog2(CL_SIZE);
  localparam int unsigned CL_OFFSET_LSB = 0;
  localparam int unsigned CL_OFFSET_MSB = CL_OFFSET_WIDTH - 1;

  // // キャッシュラインの中でのdwの数.
  // localparam int unsigned NUM_OF_DB_IN_CL = CL_SIZE / DW_SIZE;
  // // db_in_cl_idx
  // localparam int unsigned DW_IN_CL_IDX_WIDTH = $clog2(NUM_OF_DB_IN_CL);
  // localparam int unsigned DW_IN_CL_IDX_LSB = $clog2(DW_SIZE);
  // localparam int unsigned DW_IN_CL_IDX_MSB = DW_IN_CL_IDX_LSB + DW_IN_CL_IDX_WIDTH - 1;

  // キャッシュラインの中での,DATA_BULKの数.
  // data_bulkはreqで要求されるデータのサイズ.128と64がある.
  localparam int unsigned NUM_OF_DB_IN_CL = CL_SIZE / DATA_BULK_SIZE;
  localparam int unsigned DB_IN_CL_IDX_WIDTH = $clog2(NUM_OF_DB_IN_CL);
  localparam int unsigned DB_IN_CL_IDX_LSB = $clog2(DATA_BULK_SIZE);
  localparam int unsigned DB_IN_CL_IDX_MSB = DB_IN_CL_IDX_LSB + DB_IN_CL_IDX_WIDTH - 1;

  // 各種のアラインメントされたPADDRを抜き出すためのMSB,LSB
  localparam int unsigned PADDR_CL_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_CL_ALIGNED_LSB = CL_OFFSET_WIDTH;

  // localparam int unsigned PADDR_DW_ALIGNED_MSB = PADDR_WIDTH - 1;
  // localparam int unsigned PADDR_DW_ALIGNED_LSB = $clog2(DW_SIZE);

  localparam int unsigned PADDR_DB_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_DB_ALIGNED_LSB = $clog2(DATA_BULK_SIZE);

  // SET_IDX
  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SETS);
  localparam int unsigned SET_IDX_MSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH - 1;
  localparam int unsigned SET_IDX_LSB = CL_OFFSET_WIDTH;

  // TAG
  localparam int unsigned TAG_WIDTH = PADDR_WIDTH - SET_IDX_WIDTH - CL_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = PADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + CL_OFFSET_WIDTH;

  // localparam int unsigned WAY_IDX_WIDTH = $clog2(NUM_OF_WAYS);
  localparam int unsigned WAY_IDX_WIDTH = NUM_OF_WAYS == 1 ? 1 : $clog2(NUM_OF_WAYS);


  // --------------------------------------------
  // MSHR のパラメータ.
  // --------------------------------------------
  localparam int unsigned NUM_OF_MSHR = 2;
  localparam int unsigned MSHR_IDX_WIDTH = $clog2(NUM_OF_MSHR);

  // 各mshrエントリが保有するreqqの大きさ.
  localparam int unsigned MSHR_REQQ_SIZE = 4;
  localparam int unsigned MSHR_REQQ_IDX_WIDTH = $clog2(MSHR_REQQ_SIZE);

  // 1サイクルで削除するmshrエントリの数
  localparam int unsigned NUM_OF_DELETE_MSHR_ENT = 1;


  // ----------------------------------------------------------------------
  // Available Request Queue
  // ----------------------------------------------------------------------
  // aq_idxにアクセスするときには,バンク化して,バンク番号はaq_idx[AQ_BANK_IDX_WIDTH+:AQ_INBANK_IDX_WIDTH],
  // aq_idx[AQ_BANK_IDX_WIDTH-1:0]として
  localparam int unsigned NUM_OF_AQ_BANK = 1 << $clog2(
      max_32(NUM_OF_REQ_IN, NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ)
  );
  localparam int unsigned AQ_SIZE = 4;

  localparam int unsigned AQ_BANK_IDX_WIDTH = $clog2(NUM_OF_AQ_BANK);
  localparam int unsigned AQ_BANK_IDX_LSB = 0;
  localparam int unsigned AQ_BANK_IDX_MSB = AQ_BANK_IDX_WIDTH - 1;
  localparam int unsigned AQ_INBANK_IDX_WIDTH = $clog2(AQ_SIZE);
  localparam int unsigned AQ_INBANK_IDX_LSB = AQ_BANK_IDX_MSB + 1;
  localparam int unsigned AQ_INBANK_IDX_MSB = AQ_INBANK_IDX_LSB + AQ_INBANK_IDX_WIDTH - 1;

  // --------------------------------------------------
  // input stack
  // --------------------------------------------------
  // TODO: IS_BANK_SIZE * NUM_OF_IS_BANK >= NUM_OF_DB_IN_CL * NUM_OF_MSHR であれば良いので
  //       後で改変する.
  localparam int unsigned NUM_OF_IS_BANK = 1 << $clog2(NUM_OF_RES_IN);
  localparam int unsigned IS_BANK_SIZE = NUM_OF_DB_IN_CL * NUM_OF_MSHR;

  localparam int unsigned IS_BANK_IDX_WIDTH = $clog2(NUM_OF_IS_BANK);
  localparam int unsigned IS_BANK_IDX_LSB = 0;
  localparam int unsigned IS_BANK_IDX_MSB = IS_BANK_IDX_WIDTH - 1;

  // NUM_OF_RES_INが1だと,上の式では[MSB:LSB]が[-1:0]になってしまうので,NUM_OF_RES_INが1の場合にそれが[0:0]となるようなパラメータを導入する
  // ただ実際,NUM_OF_RES_INが1ならis_idx[MSB:LSB]の変わりに0を用いる.このような特別な変数を用いるのはコンパイルエラーを防ぐため.
  localparam int unsigned IS_BANK_IDX_LSB_MOD = 0;
  localparam int unsigned IS_BANK_IDX_MSB_MOD = IS_BANK_IDX_WIDTH == 0 ? 0 : IS_BANK_IDX_WIDTH - 1;



  localparam int unsigned IS_INBANK_IDX_WIDTH = $clog2(IS_BANK_SIZE);
  localparam int unsigned IS_INBANK_IDX_LSB = IS_BANK_IDX_MSB + 1;
  localparam int unsigned IS_INBANK_IDX_MSB = IS_INBANK_IDX_LSB + IS_INBANK_IDX_WIDTH - 1;


  // --------------------------------------------------------------------------
  // Translation Miss Buffer
  // --------------------------------------------------------------------------
  localparam int unsigned NUM_OF_TMB_BANK = 1 << $clog2(NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ);
  localparam int unsigned TMB_BANK_IDX_WIDTH = $clog2(NUM_OF_TMB_BANK);
  localparam int unsigned TMB_BANK_SIZE = 4;
  localparam int unsigned TMB_INBANK_IDX_WIDTH = $clog2(TMB_BANK_SIZE);

  localparam int unsigned TMB_BANK_IDX_LSB = 0;
  localparam int unsigned TMB_BANK_IDX_MSB = TMB_BANK_IDX_WIDTH - 1;
  localparam int unsigned TMB_INBANK_IDX_LSB = TMB_BANK_IDX_MSB + 1;
  localparam int unsigned TMB_INBANK_IDX_MSB = TMB_INBANK_IDX_LSB + TMB_INBANK_IDX_WIDTH - 1;


  // ------------------------------------------------
  // write back buffer のパラメータ
  // -------------------------------------------------

  localparam int unsigned NUM_OF_WBB_BANK = 1 << $clog2(
      max_32(NUM_OF_REQ_OUT, NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ)
  );
  localparam int unsigned WBB_BANK_IDX_WIDTH = $clog2(NUM_OF_WBB_BANK);

  // とりあえず,wbbのbankにすべてのwrite_backのリクエストが収まるようにする. 
  // 大した大きさでは無いので
  localparam int unsigned WBB_BANK_SIZE = NUM_OF_MSHR * NUM_OF_DB_IN_CL / NUM_OF_WBB_BANK;
  localparam int unsigned WBB_INBANK_IDX_WIDTH = $clog2(WBB_BANK_SIZE);

  localparam int unsigned WBB_BANK_IDX_LSB = 0;
  localparam int unsigned WBB_BANK_IDX_MSB = WBB_BANK_IDX_WIDTH - 1;
  localparam int unsigned WBB_INBANK_IDX_LSB = WBB_BANK_IDX_MSB + 1;
  localparam int unsigned WBB_INBANK_IDX_MSB = WBB_INBANK_IDX_LSB + WBB_INBANK_IDX_WIDTH - 1;


  // --------------------------------------------------------------------------
  // Cache Buffer のパラメータ.
  // --------------------------------------------------------------------------
  // CacheCBに送るread_reqの数はNUM_OF_CB_READ_REQで示されるが,追加の制約として,
  // 各db_in_cl_idxにつきリクエストがNUM_OF_CB_READ_PORT個までというものがある.
  // 以下のようにNUM_OF_CB_READ_REQ が NUM_OF_CB_READ_PORT と等しいような場合は,あまりこの制約を考慮しなくていい.

  localparam int unsigned NUM_OF_CB_RW_REQ = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ;
  localparam int unsigned NUM_OF_CB_ALLOCATE_REQ = 1;

  // localparam int unsigned NUM_OF_TLB_PORT = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ;




  // ---------------------------------------------------------------------------------------------------------
  // 各種パラメータが束縛条件に違反していないかを確認
  // ---------------------------------------------------------------------------------------------------------
  initial begin
    // read_reqに対する返答はそのままres_outにつながるので,
    // NUM_OF_RES_OUT >= NUM_OF_CB_READ_REQ である必要がある.
    if (NUM_OF_RES_OUT < NUM_OF_CB_READ_REQ) begin
      $fatal(1, "[ERROR] [Cache.sv] NUM_OF_RES_OUT (%0d) must be >= NUM_OF_CB_READ_REQ (%0d)",
             NUM_OF_RES_OUT, NUM_OF_CB_READ_REQ);
    end
  end


  // ----------------------------------------------------------------
  // Available Request Queue
  // ----------------------------------------------------------------
  // 新しく入ってきたreq_inを入れる.
  // viptでは,paddrがある方が古い方なので,そっちを優先する.piptだとそもそもtlb_missをすることが無い.

  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_rp;
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_wp;
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH:0] noei_aq;

  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_rp_next;
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_wp_next;
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH:0] noei_aq_next;

  // 新しいaqのエントリ. 
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH:0] new_aq_counter;
  // cb_port.read_req, cb_port.write_req に入れて使うaqエントリの数.
  logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH:0] num_of_used_aq;


  logic aq_r_en[NUM_OF_AQ_BANK];
  logic [AQ_INBANK_IDX_WIDTH-1:0] aq_r_idx[NUM_OF_AQ_BANK];
  logic [$bits(cache_req_t)-1:0] aq_r_data_bit[NUM_OF_AQ_BANK];

  logic aq_w_en[NUM_OF_AQ_BANK];
  logic [AQ_INBANK_IDX_WIDTH-1:0] aq_w_idx[NUM_OF_AQ_BANK];
  logic [$bits(cache_req_t)-1:0] aq_w_data_bit[NUM_OF_AQ_BANK];

  cache_req_t aq_r_data_strc[NUM_OF_AQ_BANK];
  cache_req_t aq_w_data_strc[NUM_OF_AQ_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_AQ_BANK; i++) begin
      aq_r_data_strc[i] = aq_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_AQ_BANK; i++) begin
      aq_w_data_bit[i] = aq_w_data_strc[i];
    end
  end

  // NUM_OF_AQ_BANK = 1 << $clog2(max_32(NUM_OF_REQ_IN, NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ)
  generate
    for (genvar aq_bank_idx = 0; aq_bank_idx < NUM_OF_AQ_BANK; aq_bank_idx++) begin : gen_availq
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(cache_req_t)),
          .RAM_DEPTH(AQ_SIZE)
      ) avail_queue (
          .clock(clock),
          .r_en(aq_r_en[aq_bank_idx]),
          .r_ram_idx(aq_r_idx[aq_bank_idx]),
          .r_data(aq_r_data_bit[aq_bank_idx]),
          .w_en(aq_w_en[aq_bank_idx]),
          .w_ram_idx(aq_w_idx[aq_bank_idx]),
          .w_data(aq_w_data_bit[aq_bank_idx])
      );
    end
  endgenerate

  // availqの先頭NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ個をaq_headsに保持することで非同期的に読み出せる.
  cache_req_t aq_heads[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];


  // -----------------------------------------------------------------------------------------------------
  // Input Stack
  // -----------------------------------------------------------------------------------------------------
  // 初めはres_inから帰ってきたものもavailqに入れていたが,res_inをstallさせようとすると
  // L2Cacheではメインメモリを留めなきゃいけない.流石にそれはアレなのでavailqからres_inを受ける
  // ためだけのキューを分離してinput stackとした.
  // 大きさはDW_IN_CL*NUM_OF_MSHRになるのでかなり大きい.
  // bank_idxはis_idx[IS_BANK_IDX_WIDTH-1:0]であり,
  // inbank_idxはis_idx[IS_BANK_IDX_WIDTH+:IS_INBANK_IDX_WIDTH]で表される.

  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0] is_rp;
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0] is_wp;
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH:0] noei_is;

  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0] is_rp_next;
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0] is_wp_next;
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH:0] noei_is_next;

  // 新しいisのエントリの数.res_inで入ってきたresの数.
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH:0] num_of_new_is;
  // cb_port.read_req, cb_port.write_req に入れて使うisエントリの数.
  logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH:0] num_of_used_is;

  logic is_r_en[NUM_OF_IS_BANK];
  logic [IS_INBANK_IDX_WIDTH-1:0] is_r_idx[NUM_OF_IS_BANK];
  logic [$bits(cache_res_t)-1:0] is_r_data_bit[NUM_OF_IS_BANK];

  // 
  logic is_w_en[NUM_OF_IS_BANK];
  logic [IS_INBANK_IDX_WIDTH-1:0] is_w_idx[NUM_OF_IS_BANK];
  logic [$bits(cache_res_t)-1:0] is_w_data_bit[NUM_OF_IS_BANK];

  cache_res_t is_r_data_strc[NUM_OF_IS_BANK];
  cache_res_t is_w_data_strc[NUM_OF_IS_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_IS_BANK; i++) begin
      is_r_data_strc[i] = is_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_IS_BANK; i++) begin
      is_w_data_bit[i] = is_w_data_strc[i];
    end
  end

  generate
    for (
        genvar is_bank_idx = 0; is_bank_idx < NUM_OF_IS_BANK; is_bank_idx++
    ) begin : gen_input_stack
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(cache_res_t)),
          .RAM_DEPTH(IS_BANK_SIZE)
      ) input_stack (
          .clock(clock),
          .r_en(is_r_en[is_bank_idx]),
          .r_ram_idx(is_r_idx[is_bank_idx]),
          .r_data(is_r_data_bit[is_bank_idx]),
          .w_en(is_w_en[is_bank_idx]),
          .w_ram_idx(is_w_idx[is_bank_idx]),
          .w_data(is_w_data_bit[is_bank_idx])
      );
    end
  endgenerate

  // input stackの先頭NUM_OF_CB_WRITE_REQ個を保持することで非同期的に読み出せる.
  cache_res_t is_heads[NUM_OF_CB_WRITE_REQ];


  // -----------------------------------------------------------------------------------------------------
  // MSHR
  // -----------------------------------------------------------------------------------------------------
  // mshr_reqq
  // 設計ではreq queue自体は各mshrがMSHR_REQQ_SIZEの大きさのものを持つことになっているが、内部的には一つの3read+3writeの
  // LVTRAMで実装する.idxは{mshr_reqq_idx_width+mshr_idx_width}でアクセスする.
  logic unified_reqq_r_en[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [MSHR_REQQ_IDX_WIDTH+MSHR_IDX_WIDTH-1:0] unified_reqq_r_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [$bits(cache_req_t)-1:0] unified_reqq_r_data_bit[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  logic unified_reqq_w_en[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [MSHR_REQQ_IDX_WIDTH+MSHR_IDX_WIDTH-1:0] unified_reqq_w_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [$bits(cache_req_t)-1:0] unified_reqq_w_data_bit[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  cache_req_t unified_reqq_r_data_strc[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  cache_req_t unified_reqq_w_data_strc[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      unified_reqq_r_data_strc[i] = unified_reqq_r_data_bit[i];
      unified_reqq_w_data_bit[i]  = unified_reqq_w_data_strc[i];
    end
  end

  LVTRAM #(
      .RAM_WIDTH($bits(cache_req_t)),
      .RAM_DEPTH(NUM_OF_MSHR * MSHR_REQQ_SIZE),
      .NUM_OF_READ_PORT(NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ),
      .NUM_OF_WRITE_PORT(NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ)
  ) unified_mshr_reqq (
      .clock(clock),
      .reset(reset),
      .r_en(unified_reqq_r_en),
      .r_ram_idx(unified_reqq_r_idx),
      .r_data(unified_reqq_r_data_bit),
      .w_en(unified_reqq_w_en),
      .w_ram_idx(unified_reqq_w_idx),
      .w_data(unified_reqq_w_data_bit)
  );

  // MSHR
  // 基本的にInput stackではdouble word単位で管理する.
  // これは,cbへの書き込みの幅が64bitなのに由来する.
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;

    // resでcpuに返す時に使う.
    // 真っ当に設計されていれば,異なるvaddrが同じpaddrを指すことは無い.
    // logic [VADDR_WIDTH-1:0] vaddr_cl_aligned;

    // cb_info関連.
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;


    // data_bulk単位でデータがどこにあるのかを管理.
    state_per_db_t [NUM_OF_DB_IN_CL-1:0] state_per_db;
    // CBの対応するキャッシュラインで全てのDWが更新されたか
    // logic is_all_db_updated;
    // Write-backする時のために,前のアドレスを保持しておく.
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned_prev;

    // 
    // logic [MSHR_REQQ_IDX_WIDTH-1:0] reqq_rp;
    // logic [MSHR_REQQ_IDX_WIDTH-1:0] reqq_wp;
    // logic [MSHR_REQQ_IDX_WIDTH:0]   noei_reqq;
  } mshr_info_t;
  mshr_info_t mshr_info[NUM_OF_MSHR];

  typedef struct packed {
    logic [MSHR_REQQ_IDX_WIDTH-1:0] reqq_rp;
    logic [MSHR_REQQ_IDX_WIDTH-1:0] reqq_wp;
    logic [MSHR_REQQ_IDX_WIDTH:0]   noei_reqq;
  } mshr_info_reqq_t;
  mshr_info_reqq_t mshr_info_reqq[NUM_OF_MSHR];
  mshr_info_reqq_t mshr_info_reqq_next[NUM_OF_MSHR];

  // 各mshrのstate_per_dbがすべてCB_UPDATEDになるかどうか.
  logic mshr_is_all_db_updated[NUM_OF_MSHR];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      automatic logic is_all_db_updated = 1;
      for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
        if (mshr_info[i].state_per_db[j] != CB_UPDATED) begin
          is_all_db_updated = 0;
        end
      end
      mshr_is_all_db_updated[i] = is_all_db_updated;
    end
  end

  // 新しいmshrエントリの内容とそのmshr_idx
  mshr_info_t new_mshr_info[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [MSHR_IDX_WIDTH-1:0] new_mshr_info_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  // mshr_idxからそこに新しいmshrエントリがあるかを引く
  logic is_new_mshr[NUM_OF_MSHR];

  // 削除するエントリ
  logic delete_mshr_idx_valid[NUM_OF_DELETE_MSHR_ENT];
  logic [MSHR_IDX_WIDTH-1:0] delete_mshr_idx[NUM_OF_DELETE_MSHR_ENT];


  // state_per_dbのアップデート
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx;
  } new_mshr_state_t;

  // このmshrに存在するすべてのdwのstateをまとめてアップデートする.
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
  } new_mshr_state_entire_t;

  // 状態更新用
  new_mshr_state_entire_t mshr_entire_update_to_before_cb_alloc;
  new_mshr_state_entire_t mshr_entire_update_to_during_cb_alloc;
  new_mshr_state_entire_t mshr_entire_update_to_before_wb;
  new_mshr_state_t mshr_update_to_during_wb[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  new_mshr_state_entire_t mshr_entire_update_to_before_request;

  // during_write_back => before_request
  new_mshr_state_t mshr_update_to_before_request[NUM_OF_REQ_OUT];

  new_mshr_state_t mshr_update_to_during_request[NUM_OF_REQ_OUT];

  new_mshr_state_t mshr_update_to_cb_updated[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  // reqqに新たに入ってくるリクエストの数
  logic [MSHR_REQQ_IDX_WIDTH:0] num_of_new_ents_to_reqq[NUM_OF_MSHR];
  // reqqでcb_port.read_req,cb_port.write_reqに送ることで使用したエントリの数
  int unsigned num_of_used_reqq[NUM_OF_MSHR];


  // allocateしたことによって得られるway_idx,paddr_cl_aligned_prevなどのデータ
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned_prev;
  } mshr_allocate_info_t;
  mshr_allocate_info_t mshr_allocate_info;


  // データを下位レイヤから取得するbefore_requestのものをfifoをして保存しておく.
  typedef struct packed {
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx;
  } mshr_state_fifo_t;

  mshr_state_fifo_t mshr_before_req_fifo[NUM_OF_MSHR*NUM_OF_DB_IN_CL];
  logic [DB_IN_CL_IDX_WIDTH+MSHR_IDX_WIDTH-1:0] mshr_before_req_fifo_rp;
  logic [DB_IN_CL_IDX_WIDTH+MSHR_IDX_WIDTH-1:0] mshr_before_req_fifo_wp;
  logic [DB_IN_CL_IDX_WIDTH+MSHR_IDX_WIDTH:0] noei_mshr_before_req_fifo;

  // reqqから出す内容を非同期的に読み出せるように保存しておくバッファ
  cache_req_t reqq_heads[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  // reqq_headsが所属するそれぞれのmshrのmshr_idx
  logic [MSHR_IDX_WIDTH-1:0] reqq_heads_mshr_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [MSHR_IDX_WIDTH-1:0] reqq_heads_mshr_idx_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];


  // --------------------------------------------------------------------------------------------------------
  // translation miss buffer
  // --------------------------------------------------------------------------------------------------------
  // 3read(cacheCBへのリクエスト)+3write(tlbからの返却)
  logic tmb_paddr_r_en[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_r_idx[NUM_OF_TMB_BANK];
  logic [PADDR_WIDTH-1:0] tmb_paddr_r_data[NUM_OF_TMB_BANK];

  logic tmb_paddr_w_en[RES_FROM_TLB];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_w_idx[RES_FROM_TLB];
  logic [PADDR_WIDTH-1:0] tmb_paddr_w_data[RES_FROM_TLB];

  LVTRAM #(
      .RAM_WIDTH(PADDR_WIDTH),
      .RAM_DEPTH(NUM_OF_TMB_BANK * TMB_BANK_SIZE),
      .NUM_OF_READ_PORT(NUM_OF_TMB_BANK),
      .NUM_OF_WRITE_PORT(RES_FROM_TLB)
  ) tmb_paddr (
      .clock(clock),
      .reset(reset),
      .r_en(tmb_paddr_r_en),
      .r_ram_idx(tmb_paddr_r_idx),
      .r_data(tmb_paddr_r_data),
      .w_en(tmb_paddr_w_en),
      .w_ram_idx(tmb_paddr_w_idx),
      .w_data(tmb_paddr_w_data)
  );

  // write 命令かどうかを保存する.(dirty bit が1でwrite命令ならpagefaultを出すため)
  logic tmb_is_write[NUM_OF_TMB_BANK][TMB_BANK_SIZE];
  logic tmb_is_write_next[NUM_OF_TMB_BANK][TMB_BANK_SIZE];

  logic tmb_is_pf[NUM_OF_TMB_BANK][TMB_BANK_SIZE];
  logic tmb_is_pf_next[NUM_OF_TMB_BANK][TMB_BANK_SIZE];

  logic tmb_is_af[NUM_OF_TMB_BANK][TMB_BANK_SIZE];
  logic tmb_is_af_next[NUM_OF_TMB_BANK][TMB_BANK_SIZE];

  // tmb_reqの方はbank化して,それぞれが1サイクルに1read+1writeとなるようにする.
  logic tmb_req_r_en[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_req_r_idx[NUM_OF_TMB_BANK];
  logic [$bits(cache_req_t)-1:0] tmb_req_r_data_bit[NUM_OF_TMB_BANK];

  // 
  logic tmb_req_w_en[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_req_w_idx[NUM_OF_TMB_BANK];
  logic [$bits(cache_req_t)-1:0] tmb_req_w_data_bit[NUM_OF_TMB_BANK];

  cache_req_t tmb_req_r_data_strc[NUM_OF_TMB_BANK];
  cache_req_t tmb_req_w_data_strc[NUM_OF_TMB_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      tmb_req_r_data_strc[i] = tmb_req_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      tmb_req_w_data_bit[i] = tmb_req_w_data_strc[i];
    end
  end

  generate
    for (
        genvar tmb_bank_idx = 0; tmb_bank_idx < NUM_OF_TMB_BANK; tmb_bank_idx++
    ) begin : gen_tmb_reqs
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(cache_req_t)),
          .RAM_DEPTH(TMB_BANK_SIZE)
      ) tmb_reqs (
          .clock(clock),
          .r_en(tmb_req_r_en[tmb_bank_idx]),
          .r_ram_idx(tmb_req_r_idx[tmb_bank_idx]),
          .r_data(tmb_req_r_data_bit[tmb_bank_idx]),
          .w_en(tmb_req_w_en[tmb_bank_idx]),
          .w_ram_idx(tmb_req_w_idx[tmb_bank_idx]),
          .w_data(tmb_req_w_data_bit[tmb_bank_idx])
      );
    end
  endgenerate

  // 新たにtmbに入ってくるエントリ

  // 次にキャッシュに送るもの,faultとしてresoutするものをそれぞれfifoで管理する.
  // ただし,同じアドレスに対する操作で順序が崩れるのは望ましくない.tlbからの返却は同じアドレスに対しては
  // リクエストを送った順に帰ってくる.tmbからも同じアドレスに対しての操作では順番が崩れないように,
  // バンクごとではなく,統一したfifoで順番を管理する. 

  // --------------------------------------------------------------------------------------------
  // tmb_paddr_valid_fifo
  // --------------------------------------------------------------------------------------------

  // paddrが帰ってきてcbにリクエストが出せるもの
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo[TMB_BANK_SIZE*NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_rp;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_wp;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH:0] noei_tmb_paddr_valid_fifo;

  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_next[TMB_BANK_SIZE*NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_rp_next;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_wp_next;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH:0] noei_tmb_paddr_valid_fifo_next;

  // paddr_validのキューで先頭にあるリクエスト.
  // ただし,bankが被るまでの先頭を出す.
  cache_req_t tmb_paddr_valid_fifo_heads[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  // tmb_paddr_valid_fifoに新たに追加するエントリ
  typedef struct packed {
    logic valid;
    logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx;
    logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx;
  } tmb_paddr_valid_fifo_new_t;
  tmb_paddr_valid_fifo_new_t tmb_paddr_valid_fifo_new[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  int unsigned num_of_new_paddr_valid_fifo;

  // tmb_paddr_valid_fifoから削除する量
  // rpをnum_of_used_tmb_paddr_validだけ進める. 
  int unsigned num_of_used_tmb_paddr_valid_fifo;


  // ---------------------------------------------------------------------------------------------------------
  // tmb_fault_fifo
  // ---------------------------------------------------------------------------------------------------------
  // access fault,page faultのもの.
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo[TMB_BANK_SIZE*NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_rp;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_wp;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH:0] noei_tmb_fault_fifo;

  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_next[TMB_BANK_SIZE*NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_rp_next;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_wp_next;
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH:0] noei_tmb_fault_fifo_next;

  // tmb_fault_fifoのキューで先頭にあるリクエスト
  cache_req_t tmb_fault_fifo_heads[NUM_OF_RES_OUT];


  typedef struct packed {
    logic valid;
    logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx;
    logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx;
  } tmb_fault_fifo_new_t;

  // 新しいfault_fifo
  // 前に詰められている.
  tmb_fault_fifo_new_t tmb_fault_fifo_new[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  int unsigned num_of_new_tmb_fault_fifo;

  // res_outに出力して削除できるfault_fifoのエントリの数
  int unsigned num_of_used_tmb_fault_fifo;

  // --------------------------------------------------------------------------------------------------------
  // tmb_free_fifo
  // --------------------------------------------------------------------------------------------------------
  // 現在使用していないtmbのidx.
  // tlbに対するリクエストのidに用いる. 
  // なぜならば,tlbからの返却をtmbに入れるときにvaddrなどでtmbのどのエントリに対応するかを検索しなくてもいいようにするため
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo[NUM_OF_TMB_BANK][TMB_BANK_SIZE];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo_rp[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo_wp[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH:0] noei_tmb_free_fifo[NUM_OF_TMB_BANK];

  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo_next[NUM_OF_TMB_BANK][TMB_BANK_SIZE];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo_rp_next[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_free_fifo_wp_next[NUM_OF_TMB_BANK];
  logic [TMB_INBANK_IDX_WIDTH:0] noei_tmb_free_fifo_next[NUM_OF_TMB_BANK];

  // tmb_free_fifoに新たに追加するエントリ.
  typedef struct packed {
    logic valid;
    logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx;
    logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx;
  } tmb_free_fifo_new_t;

  // cacheCBから帰ってきたものの送り先がtmb以外の場合,すぐにtmb_idxを開放する
  // 各BANKごとに一つしかcacheCBから帰ってこない. 
  tmb_free_fifo_new_t tmb_free_fifo_new_non_tmb[NUM_OF_TMB_BANK];
  // tmb_free_fifo_new_non_tmbの数. 
  int unsigned num_of_tmb_free_fifo_new_non_tmb[NUM_OF_TMB_BANK];

  // tmbに入ってきたものは,それをcacheCBに再度送るときに開放する.
  tmb_free_fifo_new_t tmb_free_fifo_new_tmb[NUM_OF_TMB_BANK];
  int unsigned num_of_tmb_free_fifo_new_tmb[NUM_OF_TMB_BANK];

  // tmbのfaultを開放するときにもtmb_idxは開放される
  tmb_free_fifo_new_t tmb_free_fifo_new_fault[NUM_OF_TMB_BANK];
  int unsigned num_of_tmb_free_fifo_new_fault[NUM_OF_TMB_BANK];

  // それぞれ使用した数.
  // 最大1つしか使用しないため,
  int unsigned num_of_tmb_free_fifo_used[NUM_OF_TMB_BANK];

  // 前のサイクルで送ったtlbリクエストのtmb_idxは保存しておく必要がある.
  // 前NUM_OF_CB_READ_REQ個がread_req,後ろNUM_OF_CB_WRITE_REQ個がwrite_req.
  logic reserved_tmb_idx_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] reserved_tmb_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  logic reserved_tmb_idx_valid_prev[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] reserved_tmb_idx_prev[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];


  // ------------------------------------------------------------
  // write_back_buffer
  // ------------------------------------------------------------
  // NUM_OF_WBB_BANK = max(NUM_OF_REQ_OUT,NUM_OF_CB_REQ)
  // 書き込みがCB_REQ個,読み込みがNUM_OF_REQ_OUT個

  logic wbb_r_en[NUM_OF_WBB_BANK];
  logic [WBB_INBANK_IDX_WIDTH-1:0] wbb_r_idx[NUM_OF_WBB_BANK];
  logic [$bits(cache_res_t)-1:0] wbb_r_data_bit[NUM_OF_WBB_BANK];

  // 
  logic wbb_w_en[NUM_OF_WBB_BANK];
  logic [WBB_INBANK_IDX_WIDTH-1:0] wbb_w_idx[NUM_OF_WBB_BANK];
  logic [$bits(cache_res_t)-1:0] wbb_w_data_bit[NUM_OF_WBB_BANK];

  cache_res_t wbb_r_data_strc[NUM_OF_WBB_BANK];
  cache_res_t wbb_w_data_strc[NUM_OF_WBB_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_WBB_BANK; i++) begin
      wbb_r_data_strc[i] = wbb_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_WBB_BANK; i++) begin
      wbb_w_data_bit[i] = wbb_w_data_strc[i];
    end
  end

  generate
    for (genvar wbb_bank_idx = 0; wbb_bank_idx < NUM_OF_WBB_BANK; wbb_bank_idx++) begin : gen_wbb
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(cache_res_t)),
          .RAM_DEPTH(WBB_BANK_SIZE)
      ) wbb (
          .clock(clock),
          .r_en(wbb_r_en[wbb_bank_idx]),
          .r_ram_idx(wbb_r_idx[wbb_bank_idx]),
          .r_data(wbb_r_data_bit[wbb_bank_idx]),
          .w_en(wbb_w_en[wbb_bank_idx]),
          .w_ram_idx(wbb_w_idx[wbb_bank_idx]),
          .w_data(wbb_w_data_bit[wbb_bank_idx])
      );
    end
  endgenerate

  // 下WBB_BANK_IDX_WIDTH桁がwbb_bank_idx, 上WBB_INBANK_IDX_WIDTH桁がwbb_inbank_idx.
  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_rp;
  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_wp;
  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH:0] noei_wbb;

  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_rp_next;
  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_wp_next;
  logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH:0] noei_wbb_next;

  // wbb_rp,wbb_wp更新のために,使用されたwbbエントリの数を記録.
  int unsigned noei_wbb_used;
  int unsigned noei_wbb_returned;

  // 読み出したデータが有効か. 
  // 別にnoei_wbb_usedがあれば不要だがあると便利なので.
  logic wbb_r_valid_next[NUM_OF_REQ_OUT];
  logic wbb_r_valid[NUM_OF_REQ_OUT];
  // wbb_r_[i]に入力したbank_idx
  logic [WBB_BANK_IDX_WIDTH-1:0] wbb_r_bank_idx[NUM_OF_REQ_OUT];
  logic [WBB_BANK_IDX_WIDTH-1:0] wbb_r_bank_idx_next[NUM_OF_REQ_OUT];


  // -----------------------------------------------------------------
  // Cache Buffer との接続
  // -----------------------------------------------------------------
  cache_cb_if #(
      .NUM_OF_CB_READ_REQ(NUM_OF_CB_READ_REQ),
      .NUM_OF_CB_WRITE_REQ(NUM_OF_CB_WRITE_REQ),
      .MSHR_SIZE(NUM_OF_MSHR),
      .CL_SIZE(CL_SIZE),
      .TMB_BANK_IDX_WIDTH(TMB_BANK_IDX_WIDTH),
      .TMB_INBANK_IDX_WIDTH(TMB_INBANK_IDX_WIDTH),
      .NUM_OF_WAYS(NUM_OF_WAYS),
      .NUM_OF_SETS(NUM_OF_SETS),
      .cache_req_t(cache_req_t),
      .cache_res_t(cache_res_t),
      .DATA_BULK_SIZE(DATA_BULK_SIZE)
  ) cb_port ();


  CacheCB #(
      .NUM_OF_CB_READ_REQ(NUM_OF_CB_READ_REQ),
      .NUM_OF_CB_WRITE_REQ(NUM_OF_CB_WRITE_REQ),
      .MSHR_SIZE(NUM_OF_MSHR),
      .CL_SIZE(CL_SIZE),
      .TMB_BANK_IDX_WIDTH(TMB_BANK_IDX_WIDTH),
      .TMB_INBANK_IDX_WIDTH(TMB_INBANK_IDX_WIDTH),
      .NUM_OF_WAYS(NUM_OF_WAYS),
      .NUM_OF_SETS(NUM_OF_SETS),
      .REQ_TO_TLB(REQ_TO_TLB),
      .RES_FROM_TLB(RES_FROM_TLB),
      .cache_req_t(cache_req_t),
      .cache_res_t(cache_res_t),
      .DATA_BULK_SIZE(DATA_BULK_SIZE),
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


  function automatic void dump_cache_req(input cache_req_t req);
    $display(
        "========== CACHE_REQ DUMP ==========\nvalid=%0b\nid=%0d id_sub=%0d generation=%0d\nreq_policy=%s cb_req_type=%s\nvaddr_db_aligned=0x%0h\npaddr_valid=%0b paddr_db_aligned=0x%0h\nbyte_in_db_idx=%0d\nsatp=0x%0h\ndata=0x%0h",
        req.valid, req.id, req.id_sub, req.generation, req.req_policy.name(),
        req.cb_req_type.name(), req.vaddr_db_aligned, req.paddr_valid, req.paddr_db_aligned,
        req.byte_in_db_idx, req.satp, req.data);
  endfunction

  function automatic void dump_cache_res(input cache_res_t res);
    $display(
        "========== CACHE_RES DUMP ==========\nvalid=%0b\nid=%0d id_sub=%0d generation=%0d\nis_page_fault=%0b is_access_fault=%0b\nreq_policy=%s cb_req_type=%s\nvaddr_db_aligned=0x%0h\npaddr_db_aligned=0x%0h\nbyte_in_db_idx=%0d\ndata=0x%0h",
        res.valid, res.id, res.id_sub, res.generation, res.is_page_fault, res.is_access_fault,
        res.req_policy.name(), res.cb_req_type.name(), res.vaddr_db_aligned, res.paddr_db_aligned,
        res.byte_in_db_idx, res.data);
  endfunction




  // -----------------------------------------------------------------------------------------------------------------------
  // tmb_paddr_valid_fifo_heads,tmb_fault_fifo_fifo_heads　の作成.
  // -----------------------------------------------------------------------------------------------------------------------
  // tmbから読み込んで,paddr_valid_headsに送るか,fault_fifoに送るか. 
  // typedef enum logic [1:0] {
  //   TO_PADDR_VALID,
  //   TO_FAULT,
  //   TO_NONE
  // } tmb_dest_e;
  // tmb_dest_e tmb_dest[NUM_OF_TMB_BANK];
  // tmb_dest_e tmb_dest_next[NUM_OF_TMB_BANK];

  // tmb_paddr_fifo_headsについて,それぞれが有効かとbank_idxを保存する.
  logic tmb_paddr_valid_fifo_heads_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_heads_bank_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic tmb_paddr_valid_fifo_heads_valid_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_BANK_IDX_WIDTH-1:0] tmb_paddr_valid_fifo_heads_bank_idx_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];


  logic tmb_fault_fifo_heads_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_heads_bank_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic tmb_fault_fifo_heads_valid_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [TMB_BANK_IDX_WIDTH-1:0] tmb_fault_fifo_heads_bank_idx_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  always_comb begin
    // 1バンクにつき一つまでの読み込みなので,使用したらチェックする.
    automatic logic tmb_bank_used[NUM_OF_TMB_BANK] = '{default: 0};


    tmb_req_r_en = '{default: 0};
    tmb_req_r_idx = '{default: 0};

    tmb_paddr_r_en = '{default: 0};
    tmb_paddr_r_idx = '{default: 0};

    tmb_paddr_valid_fifo_heads_valid_next = '{default: 0};
    tmb_paddr_valid_fifo_heads_bank_idx_next = '{default: 0};

    tmb_fault_fifo_heads_valid_next = '{default: 0};
    tmb_fault_fifo_heads_bank_idx_next = '{default: 0};

    // tmb_paddr_valid_fifo_headsの作成.
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;

      if (32'(noei_tmb_paddr_valid_fifo_next) > i) begin

        tmb_inbank_idx = tmb_paddr_valid_fifo_next[tmb_paddr_valid_fifo_rp_next+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];
        tmb_bank_idx = tmb_paddr_valid_fifo_next[tmb_paddr_valid_fifo_rp_next+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];


        // すでにそのbankが使用済なら読み込みを行わない.
        if (tmb_bank_used[tmb_bank_idx]) begin
          break;
        end

        // tmb_reqの内容を読み出し
        tmb_req_r_en[tmb_bank_idx] = 1;
        tmb_req_r_idx[tmb_bank_idx] = tmb_inbank_idx;

        // tmb_paddrの内容を読み出し
        tmb_paddr_r_en[tmb_bank_idx] = 1;
        tmb_paddr_r_idx[tmb_bank_idx] = {tmb_inbank_idx, tmb_bank_idx};


        // 次のサイクルでheadsを構成するときに使うtmb_bank_idxの登録
        tmb_paddr_valid_fifo_heads_valid_next[i] = 1;
        tmb_paddr_valid_fifo_heads_bank_idx_next[i] = tmb_bank_idx;

        tmb_bank_used[tmb_bank_idx] = 1;
      end
    end

    // tmb_fault_fifo_fifo_headsの作成
    for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      if (32'(noei_tmb_fault_fifo_next) > i) begin
        tmb_inbank_idx = tmb_fault_fifo_next[tmb_fault_fifo_rp_next+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];
        tmb_bank_idx = tmb_fault_fifo_next[tmb_fault_fifo_rp_next+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];

        // すでにそのbankが使用済なら読み込みを行わない
        // tmb_reqのポート制約により.
        if (tmb_bank_used[tmb_bank_idx]) begin
          break;
        end

        // bramのtmb_reqからtmb_fault_fifo_headsに使用するための情報のidxを指定
        tmb_req_r_en[tmb_bank_idx] = 1;
        tmb_req_r_idx[tmb_bank_idx] = tmb_inbank_idx;

        // tmb_paddrの内容を読み出し
        tmb_paddr_r_en[tmb_bank_idx] = 1;
        tmb_paddr_r_idx[tmb_bank_idx] = {tmb_inbank_idx, tmb_bank_idx};

        // 次のサイクルでheadsを構成するときに使うtmb_bank_idxの登録
        tmb_fault_fifo_heads_valid_next[i] = 1;
        tmb_fault_fifo_heads_bank_idx_next[i] = tmb_bank_idx;

        tmb_bank_used[tmb_bank_idx] = 1;
      end
    end
  end

  // tmb_paddr_valid_fifo_heads,tmb_fault_fifo_headsの作成.
  always_comb begin
    automatic int unsigned tmb_paddr_valid_counter = 0;
    automatic int unsigned tmb_fault_counter = 0;
    tmb_paddr_valid_fifo_heads = '{default: 0};
    tmb_fault_fifo_heads = '{default: 0};


    // tmb_paddr_valid_fifo
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      automatic
      logic [TMB_BANK_IDX_WIDTH-1:0]
      tmb_bank_idx = tmb_paddr_valid_fifo_heads_bank_idx[i];
      if (tmb_paddr_valid_fifo_heads_valid[i]) begin
        /*          tmb_paddr_valid_fifo_heads[i] = tmb_req_r_data_strc[tmb_bank_idx];
        tmb_paddr_valid_fifo_heads[i].paddr_db_aligned = tmb_paddr_r_data[tmb_bank_idx];
        tmb_paddr_valid_fifo_heads[i].paddr_valid = 1;  */
        tmb_paddr_valid_fifo_heads[i] = '{
            valid: 1,
            id: tmb_req_r_data_strc[tmb_bank_idx].id,
            id_sub: tmb_req_r_data_strc[tmb_bank_idx].id_sub,
            generation: tmb_req_r_data_strc[tmb_bank_idx].generation,
            req_policy: tmb_req_r_data_strc[tmb_bank_idx].req_policy,
            cb_req_type: tmb_req_r_data_strc[tmb_bank_idx].cb_req_type,
            vaddr_db_aligned: tmb_req_r_data_strc[tmb_bank_idx].vaddr_db_aligned,
            paddr_valid: 1,
            paddr_db_aligned: tmb_paddr_r_data[tmb_bank_idx],
            byte_in_db_idx: tmb_req_r_data_strc[tmb_bank_idx].byte_in_db_idx,
            satp: tmb_req_r_data_strc[tmb_bank_idx].satp,
            data: tmb_req_r_data_strc[tmb_bank_idx].data
        };
      end
    end

    // tmb_fault_fifo
    for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = tmb_fault_fifo_heads_bank_idx[i];
      if (tmb_fault_fifo_heads_valid[i]) begin
        tmb_fault_fifo_heads[i] = tmb_req_r_data_strc[tmb_bank_idx];
        tmb_fault_fifo_heads[i].paddr_db_aligned = tmb_paddr_r_data[tmb_bank_idx];
        tmb_fault_fifo_heads[i].paddr_valid = 1;
      end
    end

  end

  always_ff @(posedge clock) begin
    if (reset) begin
      //tmb_dest <= '{default: TO_NONE};
      tmb_paddr_valid_fifo_heads_valid <= '{default: 0};
      tmb_paddr_valid_fifo_heads_bank_idx <= '{default: 0};

      tmb_fault_fifo_heads_valid <= '{default: 0};
      tmb_fault_fifo_heads_bank_idx <= '{default: 0};
    end else begin
      // tmb_dest <= tmb_dest_next;

      tmb_paddr_valid_fifo_heads_valid <= tmb_paddr_valid_fifo_heads_valid_next;
      tmb_paddr_valid_fifo_heads_bank_idx <= tmb_paddr_valid_fifo_heads_bank_idx_next;

      tmb_fault_fifo_heads_valid <= tmb_fault_fifo_heads_valid_next;
      tmb_fault_fifo_heads_bank_idx <= tmb_fault_fifo_heads_bank_idx_next;
    end
  end


  // -------------------------------------------------------------------------------------------------------------------
  // reqq_headsの作成
  // -------------------------------------------------------------------------------------------------------------------

  // reqq_heads[i]がvalidかどうか.(reqq_headsを構成するときに用いる)
  logic reqq_heads_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic reqq_heads_valid_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  always_comb begin
    automatic int unsigned mshr_avail_req_counter = 0;
    unified_reqq_r_en = '{default: 0};
    unified_reqq_r_idx = '{default: 0};

    // reqq_heads[i]に対応するmshr_idx
    reqq_heads_mshr_idx_next = '{default: 0};
    reqq_heads_valid_next = '{default: 0};

    // とりあえず各mshrから1サイクルに一つでいいや.後で変更する.
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (mshr_info[i].valid && mshr_is_all_db_updated[i] && mshr_info_reqq_next[i].noei_reqq != 0
            && mshr_avail_req_counter < NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ) begin

        unified_reqq_r_en[mshr_avail_req_counter] = 1;
        unified_reqq_r_idx[mshr_avail_req_counter] = {
          MSHR_IDX_WIDTH'(i), mshr_info_reqq_next[i].reqq_rp
        };

        reqq_heads_mshr_idx_next[mshr_avail_req_counter] = MSHR_IDX_WIDTH'(i);
        reqq_heads_valid_next[mshr_avail_req_counter] = 1;

        mshr_avail_req_counter++;
      end
    end
  end

  // 前のサイクルで出したリクエストからreqq_headsを作成する.
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (reqq_heads_valid[i]) begin
        reqq_heads[i] = unified_reqq_r_data_strc[i];
      end else begin
        reqq_heads[i] = '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      reqq_heads_mshr_idx <= '{default: 0};
      reqq_heads_valid <= '{default: 0};
    end else begin
      reqq_heads_mshr_idx <= reqq_heads_mshr_idx_next;
      reqq_heads_valid <= reqq_heads_valid_next;
    end
  end

  // ------------------------------------------------------------------------------------------------------------------
  // aq_headsの作成
  // ------------------------------------------------------------------------------------------------------------------
  // aq_headsのうち,validかどうか.
  logic aq_heads_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic aq_heads_valid_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [AQ_BANK_IDX_WIDTH-1:0] aq_heads_bank_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  logic [AQ_BANK_IDX_WIDTH-1:0] aq_heads_bank_idx_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];


  always_comb begin
    aq_heads_valid_next = '{default: 0};
    aq_heads_bank_idx_next = '{default: 0};

    // 初期化
    aq_r_en = '{default: 0};
    aq_r_idx = '{default: 0};


    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      // noei_aq,aq_rp でなく noei_aq_next,aq_rp_nextに基づいてheadsを作成する. 
      // noei_aq,aq_rp に基づいて作成してしまうと二重にリクエストを出してしまうから.
      automatic logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_idx = 0;
      automatic logic [AQ_INBANK_IDX_WIDTH-1:0] aq_inbank_idx = 0;
      automatic logic [AQ_BANK_IDX_WIDTH-1:0] aq_bank_idx = 0;

      if (i < noei_aq_next) begin
        // aq_bank_idx,aq_inbank_idxの作成.
        aq_idx = aq_rp_next + (AQ_INBANK_IDX_WIDTH + AQ_BANK_IDX_WIDTH)'(i);
        aq_inbank_idx = aq_idx[AQ_INBANK_IDX_MSB:AQ_INBANK_IDX_LSB];
        aq_bank_idx = aq_idx[AQ_BANK_IDX_MSB:AQ_BANK_IDX_LSB];

        // 読み込み
        aq_r_en[aq_bank_idx] = 1;
        aq_r_idx[aq_bank_idx] = aq_inbank_idx;

        //
        aq_heads_valid_next[i] = 1;
        aq_heads_bank_idx_next[i] = aq_bank_idx;
      end
    end
  end

  // 前のサイクルで読み込んだ内容をaq_headsに反映
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (aq_heads_valid[i]) begin
        aq_heads[i] = aq_r_data_strc[aq_heads_bank_idx[i]];
      end else begin
        aq_heads[i] = '{default: 0, req_policy: REQ_POLICY_NONE, cb_req_type: CB_REQ_TYPE_NONE};
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      aq_heads_valid <= '{default: 0};
      aq_heads_bank_idx <= '{default: 0};
    end else begin
      aq_heads_valid <= aq_heads_valid_next;
      aq_heads_bank_idx <= aq_heads_bank_idx_next;
    end
  end


  // ---------------------------------------------------------------------------------------------------------------------
  // is_headsの作成
  // ---------------------------------------------------------------------------------------------------------------------
  // logic is_heads_valid[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  // logic is_heads_valid_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  // logic [IS_BANK_IDX_WIDTH-1:0] is_heads_bank_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];
  // logic [IS_BANK_IDX_WIDTH-1:0] is_heads_bank_idx_next[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ];

  int unsigned num_of_is_heads_ent;
  int unsigned num_of_is_heads_ent_next;

  always_comb begin
    // 同じバンクから2readはできないので,使用したバンクを管理.
    automatic logic is_bank_used[NUM_OF_IS_BANK] = '{default: 0};
    // is_headsの中で有効なエントリ.
    num_of_is_heads_ent_next = 0;

    // is_heads_valid_next = '{default: 0};
    // is_heads_bank_idx_next = '{default: 0};

    // 初期化
    is_r_en = '{default: 0};
    is_r_idx = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin

      // is_bank_idx,is_inbank_idxの作成.
      automatic
      logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0]
      is_idx = is_rp_next + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH)'(i);
      automatic
      logic [IS_INBANK_IDX_WIDTH-1:0]
      is_inbank_idx = is_idx[IS_INBANK_IDX_MSB:IS_INBANK_IDX_LSB];
      automatic
      int unsigned
      is_bank_idx = IS_BANK_IDX_WIDTH == 0 ? 0 : 32'(is_idx[IS_BANK_IDX_MSB_MOD:IS_BANK_IDX_LSB_MOD]);

      // もしbankが衝突しそうなら,その手前で打ち切る.
      if (is_bank_used[is_bank_idx] || i >= noei_is_next) begin
        break;
      end else begin
        // 読み込み
        is_r_en[is_bank_idx] = 1;
        is_r_idx[is_bank_idx] = is_inbank_idx;

        // 使用したbankを記録.
        is_bank_used[is_bank_idx] = 1;

        // is_headに入れる数を記録
        num_of_is_heads_ent_next++;
      end

    end
  end

  // 前のサイクルで読み込んだ内容をis_headsに反映
  always_comb begin
    is_heads = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      automatic
      logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0]
      is_idx = is_rp + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH)'(i);
      // automatic
      // logic [IS_BANK_IDX_WIDTH-1:0]
      // is_bank_idx = is_idx[IS_BANK_IDX_MSB:IS_BANK_IDX_LSB];
      automatic
      int unsigned
      is_bank_idx = IS_BANK_IDX_WIDTH == 0 ? 0 : 32'(is_idx[IS_BANK_IDX_MSB_MOD:IS_BANK_IDX_LSB_MOD]);
      if (i < num_of_is_heads_ent) begin
        is_heads[i] = is_r_data_strc[is_bank_idx];
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      num_of_is_heads_ent <= 0;
    end else begin
      num_of_is_heads_ent <= num_of_is_heads_ent_next;
    end
  end

  // -------------------------------------------------------------------------------------------------------------------
  // reserved_tmb_idx の作成
  // -------------------------------------------------------------------------------------------------------------------
  // cb_port.read_req, cb_port.write_reqに合わせて, reserved_tmb_idx, reserved_tmb_idx_prevを作成する. 


  // ラウンドロビン用のパラメータ
  logic [TMB_BANK_IDX_WIDTH-1:0] rr_tmb_bank_idx;
  int unsigned num_of_used_tmb_free;

  always_comb begin
    num_of_tmb_free_fifo_used = '{default: 0};
    num_of_used_tmb_free = 0;

    reserved_tmb_idx_valid = '{default: 0};
    reserved_tmb_idx = '{default: 0};

    // cb_port.read_reqに対して,paddrがvalidであるかないかに関わらずtmb_idxを貸し出す.
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      if (cb_port.read_req[i].valid && !cb_port.read_req[i].paddr_valid) begin
        tmb_bank_idx = rr_tmb_bank_idx + TMB_BANK_IDX_WIDTH'(num_of_used_tmb_free);

        // reserved_tmb_idx 
        reserved_tmb_idx_valid[i] = 1;
        reserved_tmb_idx[i] = {
          tmb_free_fifo[tmb_bank_idx][tmb_free_fifo_rp[tmb_bank_idx]], tmb_bank_idx
        };

        num_of_tmb_free_fifo_used[tmb_bank_idx] = 1;
        num_of_used_tmb_free++;
      end
    end

    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      if (cb_port.write_req[i].valid && !cb_port.write_req[i].paddr_valid) begin
        tmb_bank_idx = rr_tmb_bank_idx + (TMB_BANK_IDX_WIDTH)'(num_of_used_tmb_free);

        //reserved_tmb_idx
        reserved_tmb_idx_valid[NUM_OF_CB_READ_REQ+i] = 1;
        reserved_tmb_idx[NUM_OF_CB_READ_REQ+i] = {
          tmb_free_fifo[tmb_bank_idx][tmb_free_fifo_rp[tmb_bank_idx]], tmb_bank_idx
        };

        num_of_tmb_free_fifo_used[tmb_bank_idx] = 1;
        num_of_used_tmb_free++;
      end
    end
  end

  // reserved_tmbをcacheCBに渡す.
  always_comb begin
    cb_port.reserved_tmb_idx = reserved_tmb_idx;
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      rr_tmb_bank_idx <= 0;
      reserved_tmb_idx_valid_prev <= '{default: 0};
      reserved_tmb_idx_prev <= '{default: 0};
    end else begin
      rr_tmb_bank_idx <= rr_tmb_bank_idx + TMB_BANK_IDX_WIDTH'(num_of_used_tmb_free);
      reserved_tmb_idx_valid_prev <= reserved_tmb_idx_valid;
      reserved_tmb_idx_prev <= reserved_tmb_idx;
    end
  end



  // ------------------------------------------------------------------------------------------------------------------
  // wbb,mshr,invalidate_bufからreq_outを作成
  // ------------------------------------------------------------------------------------------------------------------
  cache_req_t req_out_from_mshr_next[NUM_OF_REQ_OUT];
  cache_req_t req_out_from_mshr[NUM_OF_REQ_OUT];

  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx;
  } req_out_available_mshr_ents_t;


  typedef enum logic {
    REQ_OUT_FROM_WBB,
    REQ_OUT_FROM_MSHR
  } req_out_from_e;

  typedef struct packed {
    logic valid;
    req_out_from_e req_out_from;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx;

    // wbb用パラメータ
    logic [WBB_BANK_IDX_WIDTH-1:0] wbb_bank_idx;
  } req_out_stat_t;

  req_out_stat_t req_out_stat[NUM_OF_REQ_OUT];
  req_out_stat_t req_out_stat_next[NUM_OF_REQ_OUT];

  always_comb begin

    // 
    automatic req_out_available_mshr_ents_t mshr_ents_to_req_out[NUM_OF_REQ_OUT] = '{default: 0};
    automatic int unsigned mshr_before_req_pick_counter = 0;
    automatic int unsigned mshr_before_req_counter = 0;
    automatic logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_idx = 0;
    automatic logic [WBB_BANK_IDX_WIDTH-1:0] wbb_bank_idx = 0;
    automatic logic [WBB_INBANK_IDX_WIDTH-1:0] wbb_inbank_idx = 0;
    automatic logic [MSHR_IDX_WIDTH-1:0] mshr_idx = 0;
    automatic logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx = 0;


    // 初期化
    req_out_from_mshr_next = '{default: 0};
    req_out_stat_next = '{default: 0};

    // wbbからの読み込み.
    wbb_r_en = '{default: 0};
    wbb_r_idx = '{default: 0};
    noei_wbb_used = 0;

    mshr_update_to_during_request = '{default: 0};

    // mshrのうち,BEFORE_REQUESTのものを最大NUM_OF_REQ_OUT個抽出する,
    // fifoとかにした方が計算量少なくて良いかもしれない.
    if (!stall_req_out) begin

      // mshrの内,before_reqでリクエストを送るべきエントリをmshr_ents_to_req_outとしてリストアップする.
      mshr_ents_to_req_out = '{default: 0};
      mshr_before_req_pick_counter = 0;
      mshr_before_req_counter = 0;


      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
          if(mshr_info[i].valid && mshr_info[i].state_per_db[j] == BEFORE_REQUEST && mshr_before_req_pick_counter <NUM_OF_REQ_OUT)begin
            mshr_ents_to_req_out[mshr_before_req_pick_counter] = '{
                valid: 1,
                mshr_idx: MSHR_IDX_WIDTH'(i),
                db_in_cl_idx: DB_IN_CL_IDX_WIDTH'(j)
            };
            mshr_before_req_pick_counter++;
          end
        end
      end


      // wbbの内容を書き戻すreq_outを出す.
      // wbbからのリクエストをmshrからのリクエストより優先する.
      for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
        if (i < noei_wbb) begin
          // wbbからライトバックのために出すリクエストの読み込み準備

          wbb_idx = wbb_rp + (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH)'(i);
          wbb_bank_idx = wbb_idx[WBB_BANK_IDX_MSB:WBB_BANK_IDX_LSB];
          wbb_inbank_idx = wbb_idx[WBB_INBANK_IDX_MSB:WBB_INBANK_IDX_LSB];

          // wbbで読み出す場所を指定する.
          wbb_r_en[wbb_bank_idx] = 1;
          wbb_r_idx[wbb_bank_idx] = wbb_inbank_idx;

          req_out_stat_next[i] = '{
              valid: 1,
              req_out_from: REQ_OUT_FROM_WBB,
              mshr_idx:
              0, // wbbからの読み込みは,内容を読み込んだあとでないとmshr_idxがわからないので0にする
              db_in_cl_idx: 0,
              wbb_bank_idx: wbb_bank_idx
          };

          // 次のサイクルでreq_outを成形するのに用いる.
          // wbb_r_valid_next[i] = 1;
          // wbb_r_bank_idx_next[i] = wbb_bank_idx;

          noei_wbb_used++;
        end else if (mshr_ents_to_req_out[mshr_before_req_counter].valid) begin
          // mshrからcb_updatedにするために出すリクエスト準備.

          mshr_idx = mshr_ents_to_req_out[mshr_before_req_counter].mshr_idx;
          db_in_cl_idx = mshr_ents_to_req_out[mshr_before_req_counter].db_in_cl_idx;
          mshr_idx = mshr_ents_to_req_out[mshr_before_req_counter].mshr_idx;
          db_in_cl_idx = mshr_ents_to_req_out[mshr_before_req_counter].db_in_cl_idx;

          // req_out_mshr_idx_next[mshr_before_req_counter] = mshr_ents_to_req_out[mshr_before_req_counter].mshr_idx;
          // req_out_db_in_cl_idx_next[mshr_before_req_counter] = mshr_ents_to_req_out[mshr_before_req_counter].db_in_cl_idx;

          // 出力するreq_outの作成
          req_out_from_mshr_next[i] = '{
              valid: 1,
              id:
              32'(
              mshr_info[mshr_idx].way_idx
              ),  // write_updateでtagを更新するため,isから出るwrite_updateはway_idxを予めもたせる必要があるので,idに埋め込む.
              id_sub: 0,
              generation: 0,
              req_policy: DATA_BULK_SIZE == 8 ? READ_DOUBLE_WORD : READ_QUAD_WORD,
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_db_aligned: 0,  // paddr_validなのでvaddrは不要.
              paddr_valid: 1,
              paddr_db_aligned:
              mshr_info[mshr_idx].paddr_cl_aligned
              +
              db_in_cl_idx
              *
              DATA_BULK_SIZE,
              byte_in_db_idx: 0,  // 必ずdwにalignされているので.
              satp: 0,  // paddrが判明されているので不要.
              data: 0
          };

          req_out_stat_next[i] = '{
              valid: 1,
              req_out_from: REQ_OUT_FROM_MSHR,
              mshr_idx: mshr_idx,
              db_in_cl_idx: db_in_cl_idx,
              wbb_bank_idx: 0
          };

          // wbbみたいに次のサイクルで状態更新すると,同じエントリのrequestを2回送ってしまうからここで更新
          // ただ,wbbと状態更新のタイミングが異なるのは少し気持ち悪いかもしれない.
          mshr_update_to_during_request[i] = '{
              valid: 1,
              mshr_idx: mshr_idx,
              db_in_cl_idx: db_in_cl_idx
          };

          mshr_before_req_counter++;
        end
      end
    end


  end

  // 前のalways_combで前サイクルに取得した情報からreq_outを作成.
  always_comb begin
    //
    automatic logic [WBB_BANK_IDX_WIDTH-1:0] wbb_bank_idx = 0;

    // automatic int unsigned mshr_before_req_counter = 0;
    req_out = '{default: 0};

    // 状態更新
    // mshr_update_to_during_request = '{default: 0};
    mshr_update_to_before_request = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      if (req_out_stat[i].valid) begin
        if (req_out_stat[i].req_out_from == REQ_OUT_FROM_WBB) begin
          // wbb からのwrite_backリクエスト
          // automatic logic [WBB_BANK_IDX_WIDTH-1:0] wbb_bank_idx = wbb_r_bank_idx[i];
          wbb_bank_idx = req_out_stat[i].wbb_bank_idx;
          req_out[i] = '{
              valid: 1,
              id: wbb_r_data_strc[wbb_bank_idx].id,
              id_sub: wbb_r_data_strc[wbb_bank_idx].id_sub,
              generation: wbb_r_data_strc[wbb_bank_idx].generation,
              req_policy: DATA_BULK_SIZE == 8 ? WRITE_DOUBLE_WORD : WRITE_QUAD_WORD,
              cb_req_type: WRITE_REQ_FROM_UPPER,
              vaddr_db_aligned: 0,
              paddr_valid: 1,
              paddr_db_aligned: wbb_r_data_strc[wbb_bank_idx].paddr_db_aligned,
              byte_in_db_idx: 0,
              satp: 0,
              data: wbb_r_data_strc[wbb_bank_idx].data
          };

          // 状態をDURINT_WRITE_BACKからBEFORE_REQUESTに更新
          mshr_update_to_before_request[i] = '{
              valid: 1,
              mshr_idx: MSHR_IDX_WIDTH'(wbb_r_data_strc[wbb_bank_idx].id),
              db_in_cl_idx:
              wbb_r_data_strc[
              wbb_bank_idx
              ].paddr_db_aligned[
              DB_IN_CL_IDX_MSB
              :
              DB_IN_CL_IDX_LSB
              ]
          };


          // $display("[LOG][Cache.sv] wbb writeback");
          // dump_cache_req(req_out[i]);

        end else if (req_out_stat[i].req_out_from == REQ_OUT_FROM_MSHR) begin
          // mshrからのリクエスト 
          req_out[i] = req_out_from_mshr[i];

          // 状態をDURING_REQUESTに更新
          // mshr_update_to_during_request[i] = '{
          //     valid: 1,
          //     mshr_idx: req_out_stat[i].mshr_idx,
          //     db_in_cl_idx: req_out_stat[i].db_in_cl_idx
          // };

          // mshr_before_req_counter++;
        end
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      req_out_from_mshr <= '{default: 0};

      req_out_stat <= '{default: 0};

    end else begin
      req_out_from_mshr <= req_out_from_mshr_next;

      req_out_stat <= req_out_stat_next;

    end
  end


  // ------------------------------------------------------------------------------------------------------------------
  // cb_port.res_to_tmb から新たにtmbにエントリを追加する.
  // ------------------------------------------------------------------------------------------------------------------
  always_comb begin
    tmb_req_w_en = '{default: 0};
    tmb_req_w_idx = '{default: 0};
    tmb_req_w_data_strc = '{default: 0};
    tmb_is_write_next = tmb_is_write;

    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      if (cb_port.res_to_tmb[i].valid) begin
        tmb_bank_idx = reserved_tmb_idx_prev[i][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];
        tmb_inbank_idx = reserved_tmb_idx_prev[i][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];

        tmb_req_w_en[tmb_bank_idx] = 1;
        tmb_req_w_idx[tmb_bank_idx] = tmb_inbank_idx;
        tmb_req_w_data_strc[tmb_bank_idx] = cb_port.res_to_tmb[i];

        // write命令かを記録する.
        tmb_is_write_next[tmb_bank_idx][tmb_inbank_idx] =
            is_write_policy(cb_port.res_to_tmb[i].req_policy);
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
        for (int unsigned j = 0; j < TMB_BANK_SIZE; j++) begin
          tmb_is_write[i][j] <= 0;
        end
      end
    end else begin
      tmb_is_write <= tmb_is_write_next;
    end
  end

  // ------------------------------------------------------------------------------------------------------------------
  // tmb_free_fifo_non_tmbの作成
  // ------------------------------------------------------------------------------------------------------------------
  // cacheCBからの返答がtmb以外に向けたものの場合,tmb_free_fifoにtmb_idxを戻す
  // res_from_tlbの内容から直接tmb_freeに戻すものを決めないのは,1サイクルでtlbが戻ってきた場合は必ずtmb_idxは開放されるが,
  // tmbに入っているものに対して戻ってきたtlbレスポンスの場合,そのtmbエントリが開放されるのはcacheCBに再度リクエストを送ったときとなり,
  // tlbが帰ってくるタイミングと異なるから.
  always_comb begin
    automatic logic tmb_freed[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ] = '{default: 0};
    tmb_free_fifo_new_non_tmb = '{default: 0};
    num_of_tmb_free_fifo_new_non_tmb = '{default: 0};

    // cb_portでvalidなもののうち,res_to_tmb以外の出力をtmb_freedに記録する.
    // なぜならば,res_to_tmb以外であればreserved_tmb_idxを開放する必要があるからだ.
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (reserved_tmb_idx_valid_prev[i] && !cb_port.res_to_tmb[i].valid) begin
        tmb_freed[i] = 1;
      end
    end

    // tmb_freedからtmb_free_fifo_new_non_tmb
    // tmb_bank_idxは被らない.なぜならtmb_idxを割り当てるときは,tmb_free_fifoの各バンクから1つづつ取るから.
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      if (tmb_freed[i]) begin
        tmb_bank_idx = reserved_tmb_idx_prev[i][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];
        tmb_free_fifo_new_non_tmb[tmb_bank_idx] = '{
            valid: 1,
            tmb_bank_idx: tmb_bank_idx,
            tmb_inbank_idx: reserved_tmb_idx_prev[i][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB]
        };
        num_of_tmb_free_fifo_new_non_tmb[tmb_bank_idx]++;
      end
    end

  end



  // -----------------------------------------------------------------------------
  // tlbから帰ってきたデータをtmbに反映させる.
  // -----------------------------------------------------------------------------
  // ただし,tmbに入っていないものは除外する必要がある.
  always_comb begin
    // automatic int unsigned
    // 初期化
    tmb_paddr_w_en = '{default: 0};
    tmb_paddr_w_idx = '{default: 0};
    tmb_paddr_w_data = '{default: 0};

    tmb_is_pf_next = tmb_is_pf;
    tmb_is_af_next = tmb_is_af;

    // paddr_valid_fifo,fault_fifoの新しいエントリの初期化
    tmb_fault_fifo_new = '{default: 0};
    num_of_new_tmb_fault_fifo = 0;
    num_of_new_paddr_valid_fifo = 0;
    tmb_paddr_valid_fifo_new = '{default: 0};

    // res_from_tlb.id は{tmb_inbank_idx,tmb_bank_idx}である.
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin

      // tmb_bank_idx,tmb_inbank_idx
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      automatic logic is_page_fault = 0;
      automatic logic is_access_fault = 0;

      // 1サイクルで帰ってきたものは,tmbに入っていないもの. 
      automatic logic is_in_tmb = 1;
      for (int unsigned j = 0; j < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; j++) begin
        if(res_from_tlb[i].valid && reserved_tmb_idx_valid_prev[j] && 
                (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(res_from_tlb[i].id) == reserved_tmb_idx_prev[j])begin
          is_in_tmb = 0;
        end
      end


      if (res_from_tlb[i].valid && is_in_tmb) begin

        tmb_bank_idx = res_from_tlb[i].id[TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];
        tmb_inbank_idx = res_from_tlb[i].id[TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];

        // svade拡張なので,pte_a,pte_dが0ならpage faultを起こす.
        is_page_fault = res_from_tlb[i].is_page_fault || res_from_tlb[i].pte_a == 0 || 
                                        (tmb_is_write[tmb_bank_idx][tmb_inbank_idx] && res_from_tlb[i].pte_d == 0);
        // is_access_fault = res_from_tlb[i].pma_type != PMA_MEMORY;

        // page_faultの場合,自動的にafと判定されてしまうが,
        // pfの方を優先する.
        if (!is_page_fault) begin
          is_access_fault = res_from_tlb[i].pma_type != PMA_MEMORY;
        end

        // page
        // if (is_access_fault) begin
        //   $display("[LOG][Cache.sv] af pma_type is %s, paddr is %0h",
        //            res_from_tlb[i].pma_type.name(), res_from_tlb[i].paddr);
        // end
        // if (is_page_fault) begin
        //   $display("[LOG][Cache.sv] pagefault, paddr is %0h", res_from_tlb[i].pma_type.name(),
        //            res_from_tlb[i].paddr);
        // end

`ifdef VERILATOR_COMPILE
        $fdisplay(fp_tlb_res, "icache vaddr:%0h paddr:%0h pf:%b af:%b", res_from_tlb[i].vaddr,
                  res_from_tlb[i].paddr, is_page_fault, is_access_fault);
`endif

        // paddrの更新(lvtram)
        tmb_paddr_w_en[i]   = 1;
        tmb_paddr_w_idx[i]  = {tmb_inbank_idx, tmb_bank_idx};
        tmb_paddr_w_data[i] = res_from_tlb[i].paddr;



        // tmb_paddr_valid_fifo, tmb_fault_fifoの更新
        if (is_page_fault || is_access_fault) begin
          // faultな場合
          tmb_is_pf_next[tmb_bank_idx][tmb_inbank_idx] = is_page_fault;
          tmb_is_af_next[tmb_bank_idx][tmb_inbank_idx] = is_access_fault;
          // page faultとaccess faultの更新
          // tmb_fault_fifo_newは前から詰める.

          tmb_fault_fifo_new[num_of_new_tmb_fault_fifo] = '{
              valid: 1,
              tmb_bank_idx: tmb_bank_idx,
              tmb_inbank_idx: tmb_inbank_idx
          };
          num_of_new_tmb_fault_fifo++;
        end else begin
          // faultでない場合
          tmb_paddr_valid_fifo_new[num_of_new_paddr_valid_fifo] = '{
              valid: 1,
              tmb_bank_idx: tmb_bank_idx,
              tmb_inbank_idx: tmb_inbank_idx
          };
          num_of_new_paddr_valid_fifo++;
        end

      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
        tmb_is_af[i] <= '{default: 0};
        tmb_is_pf[i] <= '{default: 0};
      end
    end else begin
      tmb_is_af <= tmb_is_af_next;
      tmb_is_pf <= tmb_is_pf_next;
    end
  end




  // -----------------------------------------------------------------------------------------------------
  // res_to_wbbをwbbに反映させる
  // -----------------------------------------------------------------------------------------------------
  int unsigned wbb_counter;
  always_comb begin
    // 初期化
    wbb_w_en = '{default: 0};
    wbb_w_idx = '{default: 0};
    wbb_w_data_strc = '{default: 0};

    wbb_counter = 0;
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      automatic logic [WBB_INBANK_IDX_WIDTH+WBB_BANK_IDX_WIDTH-1:0] wbb_idx = 0;

      automatic logic [WBB_INBANK_IDX_WIDTH-1:0] wbb_inbank_idx = 0;
      automatic logic [WBB_BANK_IDX_WIDTH-1:0] wbb_bank_idx = 0;
      if (cb_port.res_to_wbb[i].valid) begin
        wbb_idx = wbb_wp + (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH)'(wbb_counter);

        wbb_inbank_idx = wbb_idx[WBB_INBANK_IDX_MSB:WBB_INBANK_IDX_LSB];
        wbb_bank_idx = wbb_idx[WBB_BANK_IDX_MSB:WBB_BANK_IDX_LSB];

        // wbbへの書き込み.
        wbb_w_en[wbb_bank_idx] = 1;
        wbb_w_idx[wbb_bank_idx] = wbb_inbank_idx;
        wbb_w_data_strc[wbb_bank_idx] = cb_port.res_to_wbb[i];

        wbb_counter++;
      end
    end
  end



  // ----------------------------------------------------------------------------------------------------------------------------
  // res_in => input stack
  // ----------------------------------------------------------------------------------------------------------------------------
  // res_inで下位レイヤからの返信をinput stackに
  always_comb begin

    num_of_new_is = 0;

    is_w_en = '{default: 0};
    is_w_idx = '{default: 0};
    is_w_data_strc = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
      automatic logic [IS_INBANK_IDX_WIDTH+IS_BANK_IDX_WIDTH-1:0] is_idx = 0;
      automatic logic [IS_INBANK_IDX_WIDTH-1:0] is_inbank_idx = 0;
      automatic int unsigned is_bank_idx = 0;
      if (res_in[i].valid) begin
        is_idx = is_wp + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH)'(num_of_new_is);
        is_inbank_idx = is_idx[IS_INBANK_IDX_MSB:IS_INBANK_IDX_LSB];
        is_bank_idx = IS_BANK_IDX_WIDTH == 0 ? 0 : 32'(is_idx[IS_BANK_IDX_MSB_MOD:IS_BANK_IDX_LSB_MOD]);

        // input stackへの書き込み
        is_w_en[is_bank_idx] = 1;
        is_w_idx[is_bank_idx] = is_inbank_idx;
        is_w_data_strc[is_bank_idx] = res_in[i];

        num_of_new_is++;
      end
    end
  end

  // --------------------------------------------------------------------------------------------------------------------
  // cb_port.res_to_mshr => mshr
  // --------------------------------------------------------------------------------------------------------------------
  // cacheCBから読み出した結果をmshrに格納. 

  // 新しいmshrエントリの数.(後でmshr_noroomを求めるのに使用する.)
  int unsigned new_mshr_ent_counter;
  always_comb begin

    // すでに存在するmshrのエントリへの追加のエントリなのか.
    automatic logic is_existing_mshr_ent[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ] = '{default: 0};
    // すでに存在する場合はそのmshr_idx,存在しない場合は新たに割り当てられたmshr_idxを保存する.
    automatic
    logic [MSHR_IDX_WIDTH-1:0]
    res_dest_mshr_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ] = '{default: 0};
    // そのmshrエントリの中で,このリクエストを格納するreqq_idx.
    automatic
    logic [MSHR_REQQ_IDX_WIDTH-1:0]
    res_dest_reqq_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ] = '{default: 0};

    // 空いているmshrを先頭からNUM_OF_CB_READ_REQ+NUM_OC_CB_WRITE_REQ個取り出す
    automatic
    logic [MSHR_IDX_WIDTH-1:0]
    free_mshr_idx[NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ] = '{default: 0};
    automatic int unsigned free_mshr_counter = 0;
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (!mshr_info[i].valid && free_mshr_counter < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ) begin
        free_mshr_idx[free_mshr_counter] = MSHR_IDX_WIDTH'(i);
        free_mshr_counter++;
      end
    end

    // 新しいmshrエントリの数のカウンタ.
    new_mshr_ent_counter = 0;
    num_of_new_ents_to_reqq = '{default: 0};

    // 新しいmshrエントリ
    new_mshr_info = '{default: 0};
    new_mshr_info_idx = '{default: 0};
    is_new_mshr = '{default: 0};

    unified_reqq_w_en = '{default: 0};
    unified_reqq_w_idx = '{default: 0};
    unified_reqq_w_data_strc = '{default: 0};





    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin

      if (cb_port.res_to_mshr[i].valid) begin
        // mshrエントリに対して走査し,同じpaddrを持つmshrエントリがすでに存在するかを調べる.
        for (int unsigned mshr_idx = 0; mshr_idx < NUM_OF_MSHR; mshr_idx++) begin
          if (mshr_info[mshr_idx].valid && mshr_info[mshr_idx].paddr_cl_aligned == to_cl_aligned_paddr(
                  cb_port.res_to_mshr[i].paddr_db_aligned
              )) begin
            is_existing_mshr_ent[i] = 1;
            res_dest_mshr_idx[i] = MSHR_IDX_WIDTH'(mshr_idx);
            res_dest_reqq_idx[i] = mshr_info_reqq[mshr_idx].reqq_wp;
          end
        end

        // このres_to_mshrより前にあるres_to_mshrに被りがあるかを調べる.
        for (int unsigned j = 0; j < i; j++) begin
          if (cb_port.res_to_mshr[j].valid && to_cl_aligned_paddr(
                  cb_port.res_to_mshr[i].paddr_db_aligned
              ) == to_cl_aligned_paddr(
                  cb_port.res_to_mshr[j].paddr_db_aligned
              )) begin
            is_existing_mshr_ent[i] = 1;
            res_dest_mshr_idx[i] = res_dest_mshr_idx[j];
            // 被りがある場合,それより一つあとにリクエストを格納する.
            res_dest_reqq_idx[i] = res_dest_reqq_idx[j] + MSHR_REQQ_IDX_WIDTH'(1);
          end
        end

        // 新たなエントリを割り当てる必要がある場合は空いているmshr_idxを引っ張ってくる.
        if (!is_existing_mshr_ent[i]) begin
          is_existing_mshr_ent[i] = 0;
          res_dest_mshr_idx[i] = free_mshr_idx[new_mshr_ent_counter];
          res_dest_reqq_idx[i] = 0;
          new_mshr_ent_counter++;
        end

      end
    end


    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (cb_port.res_to_mshr[i].valid) begin
        if (!is_existing_mshr_ent[i]) begin
          // 新たなmshrエントリを確保して入れる場合.
          new_mshr_info_idx[i] = res_dest_mshr_idx[i];
          new_mshr_info[i] = '{
              valid: 1,
              paddr_cl_aligned: to_cl_aligned_paddr(cb_port.res_to_mshr[i].paddr_db_aligned),
              set_idx: cb_port.res_to_mshr[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB],
              way_idx: 0,
              state_per_db: '{default: BEFORE_CB_ALLOCATION},
              paddr_cl_aligned_prev: 0
          };
          is_new_mshr[new_mshr_info_idx[i]] = 1;

        end

        // 新たにmshrにエントリを作る場合も,更新するだけの場合もreqqに新たに一つエントリを追加する.
        unified_reqq_w_en[i] = 1;
        unified_reqq_w_idx[i] = {res_dest_mshr_idx[i], res_dest_reqq_idx[i]};
        unified_reqq_w_data_strc[i] = cb_port.res_to_mshr[i];

        num_of_new_ents_to_reqq[res_dest_mshr_idx[i]] = num_of_new_ents_to_reqq[res_dest_mshr_idx[i]] + 1;

      end
    end

  end


  // ----------------------------------------------------------------------------------------------------------------------
  // tmb, req_in,availq, is, mshr => cb_port.req_in 
  // ----------------------------------------------------------------------------------------------------------------------
  // tmb, req_in, availq, is, mshr のどれかからcb_port.read_req,cb_port.write_reqにreqを送る.
  // tmbからでは,同じpaddrを返すものについては必ず前から順番に返されるので,そのtmbの中で
  // paddrが有効なものを前から処理しても,同じpaddrを持つreqの間で順番が崩れることは無い.
  // 一方でavailqの場合,(paddrを見ないで処理するなら)前から処理していってもpaddrが重なる可能性がある.
  // そのため,read_req,write_reqがどちらかがいっぱいで、次のreqをスキップしなきゃいけないような状態に
  // なったらそこで内止める.まあ paddrみるよううにすれば問題ないのか？
  //
  // まず,mshr,tmb,is,availq,req_in のどこからcbに送るのかを判断する.
  // 優先順位は mshr => is => tmb => availq => req_in
  // tmb_noroomはpaddrがわからない可能性がある入力、つまりavailqからのみ有効.
  // mshr_noroomはhitしない可能性があるもの、つまりavailq,tmbからの入力に有効
  // req_inは直接入力されない場合,availqの末尾に追加する.
  //
  // cacheCBにおいて同一サイクルでは,read命令 => write命令で処理されるため,
  // write命令をcb_portに入力したら,そこで打ち切ることで,write命令より後ろのread命令を入力させない.
  // 今はwrite命令が1サイクルに1つだからこれでいいけど,もう少し改良の余地あり.
  //
  // TODO:** とりあえず今は,write命令送ったらそこで終了とする.
  // 理由は,lsuからvaddrが来ていないから.後でlsuからvaddrもリクエストで一緒に送るように改造する.
  // あと、今どうサイクルでwrite_port => read_portの内容を送った場合,writeportからreadportにバイパスされない.


  // read_req_from_ibとマージして cb_port.read_req に入力.
  cache_req_t read_req_normal[NUM_OF_CB_READ_REQ];



  // あるset_idxを持つsetに対して、同時に大量のallocateが来たら潰れるので,
  // ある程度同じsetが埋まったら止める.
  logic way_noroom;


  // from_whereからcb_port.read_req,cb_port.write_reqを出す
  // req_inのうち,使用したものを記録し,使用しなかったものはavailqに入れる.
  logic req_in_used[NUM_OF_REQ_IN];
  int unsigned num_of_used_req_in;


  // 各種noroomを求める

  // mshr_noroom
  logic mshr_noroom;
  always_comb begin
    // 最悪の場合(NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ個のリクエストがmshrに行く)でも大丈夫なように設計.

    // mshrのエントリ自体がNUM_OF_MSHRを超える可能性がある
    automatic logic mshr_noroom_mshr_ent = 0;
    // reqqがMSHR_REQQ_SIZEを超える可能性がある.
    automatic logic mshr_noroom_reqq = 0;
    automatic int unsigned noei_mshr = 0;
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (mshr_info[i].valid) begin
        noei_mshr++;
      end
    end
    mshr_noroom_mshr_ent = NUM_OF_MSHR - noei_mshr < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ + new_mshr_ent_counter;

    // reqqが最大数を超える可能性がある場合もmshr_noroomとなる.
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if(MSHR_REQQ_SIZE - 32'(mshr_info_reqq[i].noei_reqq) < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ + 32'(num_of_new_ents_to_reqq[i]))begin
        mshr_noroom_reqq = 1;
      end
    end

    mshr_noroom = mshr_noroom_mshr_ent || mshr_noroom_reqq;


  end


  // noei_tmb_free_fifo, num_of_tmb_free_fifo_used => tmb_noroom
  logic tmb_noroom;
  always_comb begin
    // tmb_reserved_idxを配布できるかを考える.
    // noie_tmb_free - num_of_tmb_free_fifo_usedをもとに,次に何が来ても大丈夫なように,各バンク1つ以上の空きがあればnoroomでないと判断.
    tmb_noroom = 0;
    for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      if (32'(noei_tmb_free_fifo[i]) < 1) begin
        tmb_noroom = 1;
      end
    end
  end

  // way_noroom
  // 今回はNUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ=3,NUM_OF_WAY=4なので大丈夫だが,NUM_OF_WAYが小さいとずっとway_noroomになる可能性がある
  always_comb begin

    // 各setごとに新しく確保されるwayはサイクルごとに1つ.
    automatic logic way_counter_per_set[NUM_OF_SETS] = '{default: 0};
    way_noroom = 0;


    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (mshr_info[i].valid) begin
        way_counter_per_set[mshr_info[i].set_idx] = 1;
      end
    end
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (new_mshr_info[i].valid) begin
        way_counter_per_set[new_mshr_info[i].set_idx] = 1;
      end
    end


    for (int unsigned i = 0; i < NUM_OF_SETS; i++) begin
      // 各setごとに新しく確保されるwayはサイクルごとに1つなので,余ってるwayが1つよりすくなければway_noroomとする.
      if (NUM_OF_WAYS < 1 + 32'(way_counter_per_set[i])) begin
        way_noroom = 1;
      end
    end
  end



  // どこからcb_port.read_req,cb_port.write_reqを出すかを決定する
  // (from_whereを決める)
  typedef enum logic [2:0] {
    FROM_REQ_IN,
    FROM_MSHR_WB,
    FROM_MSHR_REQ,
    FROM_TMB,
    FROM_IS,
    FROM_AVAILQ,
    FROM_NONE
  } from_where_t;
  from_where_t from_where;
  from_where_t from_where_prev;
  always_ff @(posedge clock) begin
    if (reset) begin
      from_where_prev <= FROM_NONE;
    end else begin
      from_where_prev <= from_where;
    end
  end

  cache_req_t read_req_prev[NUM_OF_CB_READ_REQ];
  cache_req_t write_req_prev[NUM_OF_CB_WRITE_REQ];

  always_ff @(posedge clock) begin
    if (reset) begin
      read_req_prev  <= '{default: 0};
      write_req_prev <= '{default: 0};
    end else begin
      read_req_prev  <= cb_port.read_req;
      write_req_prev <= cb_port.write_req;
    end
  end

  // 同一のsetに対して複数の新しいmshrエントリを確保する可能性を排除する.
  // つまりあるsetに対しては1サイクル最大1つまでしかallocしないようにする.
  // これは新たにmshrエントリを確保する可能性のあるreq_inとavailqに対してもに使用される.
  // paddrがvalidかどうかが異なったらそこで打ち切る.
  typedef struct packed {
    logic valid;
    logic paddr_valid;
    logic [PADDR_WIDTH-1:0] addr;
    csr_reg_u satp;
  } way_alloc_log_t;
  way_alloc_log_t way_alloc_log[`MAX(NUM_OF_CB_READ_REQ+NUM_OF_CB_WRITE_REQ,NUM_OF_REQ_IN)];

  logic req_in_valid_and_write_back_processing;

  always_comb begin


    tmb_free_fifo_new_tmb = '{default: 0};
    from_where = FROM_NONE;

    mshr_update_to_during_wb = '{default: 0};
    way_alloc_log = '{default: 0};

    // 初期化
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      read_req_normal[i] = '{
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

    begin
      automatic logic req_in_valid_exist = 0;
      automatic logic [SET_IDX_WIDTH-1:0] set_idx = 0;
      // 有効なreq_in[i]に対して,同じsetでwrite_back中のものが存在する.
      req_in_valid_and_write_back_processing = 0;
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        if (req_in[i].valid) begin
          req_in_valid_exist = 1;
          // set_idx = req_in[i].paddr_valid ? 
          //     aq_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : aq_heads[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

          // TODO:これを上の記述からこっちに変えたら途中で止まった。なぜ.
          set_idx = req_in[i].paddr_valid ? 
            req_in[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : req_in[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

          // mshr内での探索
          for (int unsigned j = 0; j < NUM_OF_MSHR; j++) begin
            if(mshr_info[j].valid && mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
              req_in_valid_and_write_back_processing = 1;
            end
          end
          // res_to_mshr内での探索.
          for (int unsigned j = 0; j < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; j++) begin
            if(new_mshr_info[j].valid && new_mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
              req_in_valid_and_write_back_processing = 1;
            end
          end
        end
      end

      if (req_in_valid_exist && !mshr_noroom && !tmb_noroom && !way_noroom && !req_in_valid_and_write_back_processing) begin
        from_where = FROM_REQ_IN;
      end
    end

    // availq
    // availqからのリクエストのアドレスが、他の丁度いまwrite_back中のアドレスと一致すると、
    // write_backしながらrequestすることになるので,それが起こらないのように同じset_idxを持つものがmshr_nextに
    // すでにあるなら,availqから発行はしない.
    // これは,res_to_mshrをmshr_nextに反映してから行わないと,res_to_mshrに入ってるリクエストに対しての確認が漏れるので注意.
    begin
      automatic logic write_back_processing = 0;
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        automatic
        logic [SET_IDX_WIDTH-1:0]
        set_idx = aq_heads[i].paddr_valid ? 
            aq_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : aq_heads[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

        for (int unsigned j = 0; j < NUM_OF_MSHR; j++) begin
          if(mshr_info[j].valid && mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
            write_back_processing = 1;
          end
        end
        for (int unsigned j = 0; j < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; j++) begin
          if(new_mshr_info[j].valid && new_mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
            write_back_processing = 1;
          end
        end
      end

      if (noei_aq != 0 && !mshr_noroom && !tmb_noroom && !way_noroom && !write_back_processing) begin
        from_where = FROM_AVAILQ;
      end
    end

    // tmb
    begin
      // availqと同様にwrite_back中に読み書きしないように
      automatic logic write_back_processing = 0;
      automatic logic [SET_IDX_WIDTH-1:0] set_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        set_idx = tmb_paddr_valid_fifo_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];
        for (int unsigned j = 0; j < NUM_OF_MSHR; j++) begin
          if(mshr_info[j].valid && mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
            write_back_processing = 1;
          end
        end
        for (int unsigned j = 0; j < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; j++) begin
          if(new_mshr_info[j].valid && new_mshr_info[j].paddr_cl_aligned[SET_IDX_MSB:SET_IDX_LSB] == set_idx)begin
            write_back_processing = 1;
          end
        end
      end

      if (noei_tmb_paddr_valid_fifo != 0 && !mshr_noroom && !way_noroom && !write_back_processing) begin
        from_where = FROM_TMB;
      end
    end

    // is
    if (noei_is != 0) begin
      from_where = FROM_IS;
      // if (CACHE_CAT == 3) begin
      //   $display("[LOG] FROM_IS");
      // end
    end

    // mshrから(write_back)
    for (int unsigned mshr_idx = 0; mshr_idx < NUM_OF_MSHR; mshr_idx++) begin
      for (int unsigned db_in_cl_idx = 0; db_in_cl_idx < NUM_OF_DB_IN_CL; db_in_cl_idx++) begin
        if (mshr_info[mshr_idx].valid && mshr_info[mshr_idx].state_per_db[db_in_cl_idx] == BEFORE_WRITE_BACK) begin
          from_where = FROM_MSHR_WB;
        end
      end
    end

    // mshrから (read命令, write命令)
    // if (reqq_heads[0].valid) begin
    //   from_where = FROM_MSHR_REQ;
    // end
    // reqq_heads
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (mshr_info[i].valid && mshr_is_all_db_updated[i] && mshr_info_reqq[i].noei_reqq != 0) begin
        from_where = FROM_MSHR_REQ;
      end
    end

    if (stall_req_to_tlb) begin
      // tlbからstall_outが出ている場合,問答無用でstallする.
      from_where = FROM_NONE;
    end


    // 各種使用量の初期化.
    req_in_used = '{default: 0};
    num_of_used_req_in = 0;
    num_of_used_aq = 0;
    num_of_used_tmb_paddr_valid_fifo = 0;
    num_of_used_is = 0;
    num_of_used_reqq = '{default: 0};

    num_of_tmb_free_fifo_new_tmb = '{default: 0};
    begin
      automatic int unsigned read_req_to_cb_counter = 0;
      automatic int unsigned write_req_to_cb_counter = 0;

      automatic logic [TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH-1:0] tmb_idx = 0;
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;

      automatic logic set_idx_dup = 0;
      automatic logic not_same_set = 0;
      // paddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
      automatic logic paddr_same_cl = 0;
      // vaddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
      automatic logic vaddr_same_cl = 0;

      // req_in,availqからの入力はset_idxがかぶらないようにする. 
      case (from_where)
        FROM_MSHR_WB: begin
          read_req_to_cb_counter  = 0;
          write_req_to_cb_counter = 0;
          for (int unsigned mshr_idx = 0; mshr_idx < NUM_OF_MSHR; mshr_idx++) begin
            for (
                int unsigned db_in_cl_idx = 0; db_in_cl_idx < NUM_OF_DB_IN_CL; db_in_cl_idx++
            ) begin
              if (mshr_info[mshr_idx].valid) begin
                if (mshr_info[mshr_idx].state_per_db[db_in_cl_idx] == BEFORE_WRITE_BACK && read_req_to_cb_counter<NUM_OF_CB_READ_REQ) begin
                  // availqにwrite-back用のread命令を詰める.
                  // write_backするときにはすでにpaddrのcb_infoは新しいpaddrに変更されているので、
                  // paddr_cl_aligned_prevは用いない.その代わり,idにmshr_idxを入れて、そのidを用いてwbbでどのpaddrに対する
                  // 書き戻しなのかを判断する.
                  read_req_normal[read_req_to_cb_counter] = '{
                      valid: 1,
                      id: mshr_idx,  // IDにmshr_idx
                      id_sub: 0,
                      generation: 0,
                      req_policy: DATA_BULK_SIZE == 8 ? READ_DOUBLE_WORD : READ_QUAD_WORD,
                      cb_req_type: READ_WRITE_BACK,
                      vaddr_db_aligned: 0,
                      paddr_valid: 1,
                      paddr_db_aligned:
                      mshr_info[mshr_idx].paddr_cl_aligned_prev
                      +
                      db_in_cl_idx
                      *
                      DATA_BULK_SIZE,
                      byte_in_db_idx: 0,  // write_backはdw単位の為0.
                      satp: 0,
                      data: 0
                  };
                  // state_per_dbのアップデート.
                  mshr_update_to_during_wb[read_req_to_cb_counter] = '{
                      valid: 1,
                      mshr_idx: MSHR_IDX_WIDTH'(mshr_idx),
                      db_in_cl_idx: DB_IN_CL_IDX_WIDTH'(db_in_cl_idx)
                  };
                  read_req_to_cb_counter++;
                end
              end
            end
          end
        end
        FROM_MSHR_REQ: begin
          // mshr => cb_port.read_req(read命令, write命令)
          // すべてのdwがCB_UPDATEDになったら,readqやwriteqに溜まっている命令をavailqに送れる.
          read_req_to_cb_counter  = 0;
          write_req_to_cb_counter = 0;
          for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
            // if (i == 0 && !reqq_heads[i].valid && CACHE_CAT == 3) begin
            //   $display("[ERROR] reqq invalid");
            // end
            if (reqq_heads[i].valid) begin
              if (is_read_policy(
                      reqq_heads[i].req_policy
                  ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
                // read_req
                read_req_normal[read_req_to_cb_counter] = '{
                    valid: 1,
                    id: reqq_heads[i].id,
                    id_sub: reqq_heads[i].id_sub,
                    generation: reqq_heads[i].generation,
                    req_policy: reqq_heads[i].req_policy,
                    cb_req_type: READ_REQ_FROM_UPPER,
                    vaddr_db_aligned: reqq_heads[i].vaddr_db_aligned,
                    paddr_valid: 1,
                    paddr_db_aligned: reqq_heads[i].paddr_db_aligned,
                    byte_in_db_idx: reqq_heads[i].byte_in_db_idx,
                    satp: 0,
                    data: 0
                };
                num_of_used_reqq[reqq_heads_mshr_idx[i]]++;
                read_req_to_cb_counter++;
              end else if (is_write_policy(
                      reqq_heads[i].req_policy
                  ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin
                // write_req
                cb_port.write_req[write_req_to_cb_counter] = '{
                    valid: 1,
                    id: reqq_heads[i].id,
                    id_sub: reqq_heads[i].id_sub,
                    generation: reqq_heads[i].generation,
                    req_policy: reqq_heads[i].req_policy,
                    cb_req_type: WRITE_REQ_FROM_UPPER,
                    vaddr_db_aligned: reqq_heads[i].vaddr_db_aligned,
                    paddr_valid: 1,
                    paddr_db_aligned: reqq_heads[i].paddr_db_aligned,
                    byte_in_db_idx: reqq_heads[i].byte_in_db_idx,
                    satp: 0,
                    data: reqq_heads[i].data
                };
                num_of_used_reqq[reqq_heads_mshr_idx[i]]++;
                write_req_to_cb_counter++;
                // writeしたのでbreak
                break;
              end
            end
          end
        end

        FROM_TMB: begin
          read_req_to_cb_counter  = 0;
          write_req_to_cb_counter = 0;
          for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin



            if (tmb_paddr_valid_fifo_heads[i].valid && is_read_policy(
                    tmb_paddr_valid_fifo_heads[i].req_policy
                ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin


              // tmb_bank_idxとtmb_inbank_idxの作成.
              tmb_inbank_idx = 
              tmb_paddr_valid_fifo[tmb_paddr_valid_fifo_rp+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];
              tmb_bank_idx =
              tmb_paddr_valid_fifo[tmb_paddr_valid_fifo_rp+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];

              // $display("[LOG][Cache.sv] read req from tmb");
              // dump_cache_req(tmb_paddr_valid_fifo_heads[i]);

              // cb_port.read_reqに入力
              read_req_normal[read_req_to_cb_counter] = tmb_paddr_valid_fifo_heads[i];

              // tmbから1つ出力することで開放されるtmb_idxをtmb_free_fifo_new_tmbに追加.
              tmb_free_fifo_new_tmb[tmb_bank_idx] = '{
                  valid: 1,
                  tmb_bank_idx: tmb_bank_idx,
                  tmb_inbank_idx: tmb_inbank_idx
              };
              num_of_tmb_free_fifo_new_tmb[tmb_bank_idx]++;

              num_of_used_tmb_paddr_valid_fifo++;
              read_req_to_cb_counter++;
            end else if (tmb_paddr_valid_fifo_heads[i].valid && is_write_policy(
                    tmb_paddr_valid_fifo_heads[i].req_policy
                ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin

              // tmb_bank_idxとtmb_inbank_idxの作成.
              tmb_idx = tmb_paddr_valid_fifo[tmb_paddr_valid_fifo_rp+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)];
              tmb_inbank_idx = tmb_idx[TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];
              tmb_bank_idx = tmb_idx[TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];


              // $display("[LOG][Cache.sv] write req from tmb");
              // dump_cache_req(tmb_paddr_valid_fifo_heads[i]);

              // cb_port.write_reqに入力.
              cb_port.write_req[write_req_to_cb_counter] = tmb_paddr_valid_fifo_heads[i];

              // tmbから1つ出力することで開放されるtmb_idxをtmb_free_fifo_new_tmbに追加.
              tmb_free_fifo_new_tmb[tmb_bank_idx] = '{
                  valid: 1,
                  tmb_bank_idx: tmb_bank_idx,
                  tmb_inbank_idx: tmb_inbank_idx
              };
              num_of_tmb_free_fifo_new_tmb[tmb_bank_idx]++;

              num_of_used_tmb_paddr_valid_fifo++;
              write_req_to_cb_counter++;
              break;
            end
          end
        end

        FROM_IS: begin
          // is => cb_port.read_req, cb_port.write_req
          for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
            // res_inで帰ってきたものなので,write_reqしか存在しない.
            if (is_heads[i].valid) begin
              // $display("cb_port.write_req from input stack     paddr_db_aligned:%h\n",
              //          is_heads[i].paddr_db_aligned);
              cb_port.write_req[i] = '{
                  valid: 1,
                  id: is_heads[i].id,
                  id_sub: 0,
                  generation: is_heads[i].generation,
                  req_policy: DATA_BULK_SIZE == 8 ? WRITE_DOUBLE_WORD : WRITE_QUAD_WORD,
                  cb_req_type: WRITE_UPDATE,
                  vaddr_db_aligned: 0,
                  paddr_valid: 1,
                  paddr_db_aligned: is_heads[i].paddr_db_aligned,
                  byte_in_db_idx: 0,
                  satp: 0,
                  data: is_heads[i].data
              };
              num_of_used_is++;
              break;
            end
          end
        end

        FROM_AVAILQ: begin
          read_req_to_cb_counter  = 0;
          write_req_to_cb_counter = 0;
          // automatic logic set_idx_log_valid[NUM_OF_REQ_IN] = '{default: 0};
          // automatic logic [SET_IDX_WIDTH-1:0] set_idx_log[NUM_OF_REQ_IN] = '{default: 0};

          for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
            // 同じサイクルの中で,先行する命令と同じset_idxの場合,set_idx_dupとして,実行しない.
            // 順序管理が面倒になるので.
            set_idx_dup = 0;
            // これより先行するリクエストの中で,同じset_idxであり,かつ新しくmshrエントリを確保する可能性があるものが存在するかの判定.
            for (int unsigned j = 0; j < i; j++) begin
              // 同じset_idxでないならOK
              not_same_set = way_alloc_log[j].addr[SET_IDX_MSB:SET_IDX_LSB] != (aq_heads[i].paddr_valid ? 
               aq_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : aq_heads[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB]);
              // paddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
              paddr_same_cl = way_alloc_log[j].paddr_valid && aq_heads[i].paddr_valid 
                          && way_alloc_log[j].addr[PADDR_WIDTH-1:SET_IDX_LSB] == aq_heads[i].paddr_db_aligned[PADDR_WIDTH-1:SET_IDX_LSB] 
                          && way_alloc_log[j].satp == aq_heads[i].satp;
              // vaddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
              vaddr_same_cl = !way_alloc_log[j].paddr_valid && !aq_heads[i].paddr_valid 
                          && way_alloc_log[j].addr[VADDR_WIDTH-1:SET_IDX_LSB] == aq_heads[i].vaddr_db_aligned[VADDR_WIDTH-1:SET_IDX_LSB] 
                          && way_alloc_log[j].satp == aq_heads[i].satp;

              if (!not_same_set && !paddr_same_cl && !vaddr_same_cl) begin
                set_idx_dup = 1;
              end
            end
            if (set_idx_dup) begin
              break;
            end

            // cb_port.reqへの入力.
            if ((noei_aq - num_of_used_aq != 0) && is_read_policy(
                    aq_heads[i].req_policy
                ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
              // read_reqをcb_port.req_inへ入力.
              read_req_normal[read_req_to_cb_counter] = aq_heads[i];

              way_alloc_log[i] = '{
                  valid: 1,
                  paddr_valid: aq_heads[i].paddr_valid,
                  addr:
                  aq_heads[i].paddr_valid
                  ?
                  aq_heads[i].paddr_db_aligned
                  :
                  PADDR_WIDTH
                  '(
                  aq_heads[i].vaddr_db_aligned
                  ),
                  satp: aq_heads[i].satp
              };

              // set_idx_log_valid[i] = 1;
              // set_idx_log[i] = aq_heads[i].paddr_valid ? 
              //                   aq_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : aq_heads[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

              num_of_used_aq++;
              read_req_to_cb_counter++;
            end else if ((noei_aq - num_of_used_aq != 0) && is_write_policy(
                    aq_heads[i].req_policy
                ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin
              // write_reqをcb_port.req_inへ入力
              cb_port.write_req[write_req_to_cb_counter] = aq_heads[i];

              // set_idx_log_valid[i] = 1;
              // set_idx_log[i] = aq_heads[i].paddr_valid ? 
              //                   aq_heads[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : aq_heads[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];
              way_alloc_log[i] = '{
                  valid: 1,
                  paddr_valid: aq_heads[i].paddr_valid,
                  addr:
                  aq_heads[i].paddr_valid
                  ?
                  aq_heads[i].paddr_db_aligned
                  :
                  PADDR_WIDTH
                  '(
                  aq_heads[i].vaddr_db_aligned
                  ),
                  satp: aq_heads[i].satp
              };

              num_of_used_aq++;
              write_req_to_cb_counter++;
              break;
            end else begin
              // readかwriteに空きがあっても、飛ばしたりなど順番を崩して実行を行うことはしない.
              break;
            end
          end
        end

        FROM_REQ_IN: begin
          // req_in
          read_req_to_cb_counter  = 0;
          write_req_to_cb_counter = 0;
          // automatic logic set_idx_log_valid[NUM_OF_REQ_IN] = '{default: 0};
          // automatic logic [SET_IDX_WIDTH-1:0] set_idx_log[NUM_OF_REQ_IN] = '{default: 0};
          for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
            // 同じサイクルの中で,先行する命令と同じset_idxの場合,set_idx_dupとして,実行しない.
            // 順序管理が面倒になるので.
            set_idx_dup = 0;

            for (int unsigned j = 0; j < i; j++) begin
              // 同じset_idxでないならOK
              not_same_set = way_alloc_log[j].addr[SET_IDX_MSB:SET_IDX_LSB] != (req_in[i].paddr_valid ? 
               req_in[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : req_in[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB]);
              // paddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
              paddr_same_cl = way_alloc_log[j].paddr_valid && req_in[i].paddr_valid 
                          && way_alloc_log[j].addr[PADDR_WIDTH-1:SET_IDX_LSB] == req_in[i].paddr_db_aligned[PADDR_WIDTH-1:SET_IDX_LSB] 
                          && way_alloc_log[j].satp == req_in[i].satp;
              // vaddrを用いている場合で,先行する命令と同じset_idxではあるが,新たにmshrエントリは確保しない(同じclに入る)場合はOK
              vaddr_same_cl = !way_alloc_log[j].paddr_valid && !req_in[i].paddr_valid 
                          && way_alloc_log[j].addr[VADDR_WIDTH-1:SET_IDX_LSB] == req_in[i].vaddr_db_aligned[VADDR_WIDTH-1:SET_IDX_LSB] 
                          && way_alloc_log[j].satp == req_in[i].satp;

              if (!not_same_set && !paddr_same_cl && !vaddr_same_cl) begin
                set_idx_dup = 1;
              end
            end
            if (set_idx_dup) begin
              break;
            end

            // cb_port.reqへの入力.
            if (req_in[i].valid && is_read_policy(
                    req_in[i].req_policy
                ) && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
              // read_reqをcb_port.req_inへ入力.
              read_req_normal[read_req_to_cb_counter] = req_in[i];

              way_alloc_log[i] = '{
                  valid: 1,
                  paddr_valid: req_in[i].paddr_valid,
                  addr:
                  req_in[i].paddr_valid
                  ?
                  req_in[i].paddr_db_aligned
                  :
                  PADDR_WIDTH
                  '(
                  req_in[i].vaddr_db_aligned
                  ),
                  satp: req_in[i].satp
              };

              // set_idx_log_valid[i] = 1;
              // set_idx_log[i] = req_in[i].paddr_valid ? 
              //                   req_in[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : req_in[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

              req_in_used[i] = 1;
              num_of_used_req_in++;
              read_req_to_cb_counter++;
            end else if (req_in[i].valid && is_write_policy(
                    req_in[i].req_policy
                ) && write_req_to_cb_counter < NUM_OF_CB_WRITE_REQ) begin
              // write_reqをcb_port.req_inへ入力
              cb_port.write_req[write_req_to_cb_counter] = req_in[i];

              way_alloc_log[i] = '{
                  valid: 1,
                  paddr_valid: req_in[i].paddr_valid,
                  addr:
                  req_in[i].paddr_valid
                  ?
                  req_in[i].paddr_db_aligned
                  :
                  PADDR_WIDTH
                  '(
                  req_in[i].vaddr_db_aligned
                  ),
                  satp: req_in[i].satp
              };

              // set_idx_log_valid[i] = 1;
              // set_idx_log[i] = req_in[i].paddr_valid ? 
              //                   req_in[i].paddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB] : req_in[i].vaddr_db_aligned[SET_IDX_MSB:SET_IDX_LSB];

              req_in_used[i] = 1;
              num_of_used_req_in++;
              write_req_to_cb_counter++;
              // writeで中断.
              break;
            end else begin
              break;
            end
          end
        end
        default: begin

        end
      endcase
    end

  end

  // ---------------------------------------------------------------------------------------------------------------
  // req_in_used => availq
  // ---------------------------------------------------------------------------------------------------------------
  // req_inのうち,cb_port.read_req,cb_port.write_reqに入れなかったものをavailqに入れる.
  always_comb begin
    automatic logic [AQ_INBANK_IDX_WIDTH+AQ_BANK_IDX_WIDTH-1:0] aq_idx = 0;
    automatic logic [AQ_INBANK_IDX_WIDTH-1:0] aq_inbank_idx = 0;
    automatic logic [AQ_BANK_IDX_WIDTH-1:0] aq_bank_idx = 0;
    // 初期化
    new_aq_counter = 0;
    aq_w_en = '{default: 0};
    aq_w_idx = '{default: 0};
    aq_w_data_strc = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
      if (req_in[i].valid && !req_in_used[i]) begin
        // availqに入れる. 
        aq_idx = aq_wp + (AQ_INBANK_IDX_WIDTH + AQ_BANK_IDX_WIDTH)'(new_aq_counter);
        aq_inbank_idx = aq_idx[AQ_INBANK_IDX_MSB:AQ_INBANK_IDX_LSB];
        aq_bank_idx = aq_idx[AQ_BANK_IDX_MSB:AQ_BANK_IDX_LSB];

        // availqに書き込み.
        aq_w_en[aq_bank_idx] = 1;
        aq_w_idx[aq_bank_idx] = aq_inbank_idx;
        aq_w_data_strc[aq_bank_idx] = req_in[i];

        new_aq_counter++;
      end
    end
  end



  // ------------------------------------------------------------------------------------------------------------------------
  // res_outの作成
  // ------------------------------------------------------------------------------------------------------------------------
  always_comb begin
    automatic logic res_out_exist[NUM_OF_RES_OUT] = '{default: 0};
    automatic int unsigned tmb_fault_res_out_counter = 0;


    // tmbからfaultを出すことによってtmb_free_fifo_new_faultを初期化
    tmb_free_fifo_new_fault = '{default: 0};
    num_of_tmb_free_fifo_new_fault = '{default: 0};

    num_of_used_tmb_fault_fifo = 0;

    res_out = '{default: 0};

    // cb_port.res_out => res_out
    // cb_port.res_outの数がNUM_OF_CB_READ_REQなので,NUM_OF_CB_READ_REQ<=NUM_OF_RES_OUTである必要がある. 
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      if (cb_port.res_out[i].valid) begin
        res_out[i] = cb_port.res_out[i];
        res_out_exist[i] = 1;

      end
    end

    // tmb_fault_fifo_heads => res_out
    for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      automatic logic [TMB_INBANK_IDX_WIDTH-1:0] tmb_inbank_idx = 0;
      automatic logic [TMB_BANK_IDX_WIDTH-1:0] tmb_bank_idx = 0;
      if (!res_out_exist[i] && tmb_fault_fifo_heads[tmb_fault_res_out_counter].valid) begin

        // tmb_bank_idx,tmb_inbank_idxの作成
        tmb_inbank_idx = tmb_fault_fifo[32'(tmb_fault_fifo_rp)+tmb_fault_res_out_counter][TMB_INBANK_IDX_MSB:TMB_INBANK_IDX_LSB];
        tmb_bank_idx = tmb_fault_fifo[32'(tmb_fault_fifo_rp)+tmb_fault_res_out_counter][TMB_BANK_IDX_MSB:TMB_BANK_IDX_LSB];

        // res_outでの出力.
        res_out[i] = '{
            valid: 1,
            id: tmb_fault_fifo_heads[tmb_fault_res_out_counter].id,
            id_sub: 0,
            generation: tmb_fault_fifo_heads[tmb_fault_res_out_counter].generation,
            is_page_fault: tmb_is_pf[tmb_bank_idx][tmb_inbank_idx],
            is_access_fault: tmb_is_af[tmb_bank_idx][tmb_inbank_idx],
            req_policy: tmb_fault_fifo_heads[tmb_fault_res_out_counter].req_policy,
            cb_req_type: tmb_fault_fifo_heads[tmb_fault_res_out_counter].cb_req_type,
            vaddr_db_aligned: tmb_fault_fifo_heads[tmb_fault_res_out_counter].vaddr_db_aligned,
            paddr_db_aligned: tmb_fault_fifo_heads[tmb_fault_res_out_counter].paddr_db_aligned,
            byte_in_db_idx: tmb_fault_fifo_heads[tmb_fault_res_out_counter].byte_in_db_idx,
            data: 0
        };

        // num_of_tmb_free_fifo_new_fault
        tmb_free_fifo_new_fault[tmb_bank_idx] = '{
            valid: 1,
            tmb_bank_idx: tmb_bank_idx,
            tmb_inbank_idx: tmb_inbank_idx
        };
        num_of_tmb_free_fifo_new_fault[tmb_bank_idx]++;

        // tmb_fault_fifoから使用した数の記録
        num_of_used_tmb_fault_fifo++;

        tmb_fault_res_out_counter++;
      end
    end
  end


  // ---------------------------------------------------------------------------------------------------------
  // state_per_dbの更新
  // --------------------------------------------------------------------------------------------------------
  always_comb begin
    automatic logic is_all_updated = 1;
    // mshr_update_to_during_wb  = '{default: 0};
    mshr_update_to_cb_updated = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (cb_port.mshr_new_state[i].valid) begin
        // if (CACHE_CAT == 3) begin
        //   $display("mshr_new_state[%d]   paddr_cl_aligned:%h   db_in_cl_idx:%d   state_per_db:%s",
        //            i, cb_port.mshr_new_state[i].paddr_cl_aligned,
        //            cb_port.mshr_new_state[i].db_in_cl_idx,
        //            cb_port.mshr_new_state[i].state_per_db.name());
        // end
        // if( cb_port.mshr_new_state[i].valid && cb_port.mshr_new_state[i].paddr_cl_aligned == 0 && cb_port.mshr_new_state[i].db_in_cl_idx == 0)begin
        //   // dump_mshr_info();
        // end
        for (int unsigned mshr_idx = 0; mshr_idx < NUM_OF_MSHR; mshr_idx++) begin
          if(mshr_info[mshr_idx].valid && cb_port.mshr_new_state[i].paddr_cl_aligned == mshr_info[mshr_idx].paddr_cl_aligned)begin

            // state_per_dbで送られてくる値に更新.
            // mshr_next[mshr_idx].state_per_db[cb_port.mshr_new_state[i].db_in_cl_idx] = cb_port.mshr_new_state[i].state_per_db;

            if (cb_port.mshr_new_state[i].state_per_db == DURING_WRITE_BACK) begin
              // $display("mshr_new_state is DURING_WRITE_BACK    mshr_idx:%d    db_in_cl_idx:%d\n",
              //          mshr_idx, cb_port.mshr_new_state[i].db_in_cl_idx);
              /* mshr_update_to_during_wb[i] = '{
                  valid: 1,
                  mshr_idx: MSHR_IDX_WIDTH'(mshr_idx),
                  db_in_cl_idx: cb_port.mshr_new_state[i].db_in_cl_idx
              }; */
            end else if (cb_port.mshr_new_state[i].state_per_db == CB_UPDATED) begin
              // $display("mshr_new_state is CB_UPDATED    mshr_idx:%d    db_in_cl_idx:%d\n",
              //          mshr_idx, cb_port.mshr_new_state[i].db_in_cl_idx);
              mshr_update_to_cb_updated[i] = '{
                  valid: 1,
                  mshr_idx: MSHR_IDX_WIDTH'(mshr_idx),
                  db_in_cl_idx: cb_port.mshr_new_state[i].db_in_cl_idx
              };
            end

          end
        end
      end
    end
  end


  // ---------------------------------------------------------------
  // cb_port.mshr_cl_aligned_paddrの作成.
  // ---------------------------------------------------------------
  // 処理中のmshrに対応するpaddrを送ることで,cacheCBの方でアドレスが被ったらres_to_mshrに振り分ける.
  // こうすることで,mshrの処理が終わる(all_updatedになる)前に後続の命令が
  // 勝手にcbの内容を読むことで同じアドレスに対するrwの順番が崩れるのを防止する.
  always_comb begin
    // 初期化
    for (int unsigned mshr_idx = 0; mshr_idx < NUM_OF_MSHR; mshr_idx++) begin
      cb_port.mshr_processing_info[mshr_idx] = '{default: 0};
    end
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      cb_port.mshr_processing_info[i] = '{default: 0};
      if (mshr_info[i].valid && (!mshr_is_all_db_updated[i]  || mshr_info_reqq[i].noei_reqq != 0)) begin
        cb_port.mshr_processing_info[i] = '{
            valid: 1'b1,
            is_all_db_updated: mshr_is_all_db_updated[i],
            paddr_cl_aligned: mshr_info[i].paddr_cl_aligned
        };
      end
    end
  end


  // -----------------------------------------------------------------------
  // MSHR から cb_port.allocate_req を出して,cbでwayを確保する.
  // cb_port.allocate_res => MSHR
  // ------------------------------------------------------------------------
  always_comb begin
    mshr_allocate_info = '{default: 0};
    mshr_entire_update_to_before_wb = '{default: 0};
    mshr_entire_update_to_before_request = '{default: 0};
    mshr_entire_update_to_before_cb_alloc = '{default: 0};

    // cb_port.allocate_res => MSHR
    // wbb_infoの確保.
    if (cb_port.allocate_res.valid) begin
      if (cb_port.allocate_res.success) begin
        // allocateに成功した場合.
        mshr_allocate_info = '{
            valid: 1,
            mshr_idx: cb_port.allocate_res.mshr_idx,
            way_idx: cb_port.allocate_res.way_idx,
            paddr_cl_aligned_prev: cb_port.allocate_res.paddr_cl_aligned_prev
        };

        if (cb_port.allocate_res.wb_need) begin
          // write_backが必要なら BEFORE_WRITE_BACKの状態に.
          mshr_entire_update_to_before_wb = '{valid: 1, mshr_idx: cb_port.allocate_res.mshr_idx};
        end else begin
          // write backが不要ならすぐに下位レイヤにデータを取りに行くために,BEFORE_REQUESTの状態に.
          mshr_entire_update_to_before_request = '{
              valid: 1,
              mshr_idx: cb_port.allocate_res.mshr_idx
          };
        end
      end else begin
        // allocateに失敗した場合,状態を戻す.
        // mshr_next[cb_port.allocate_res.mshr_idx].state_per_db = '{default: BEFORE_CB_ALLOCATION};
        mshr_entire_update_to_before_cb_alloc = '{
            valid: 1,
            mshr_idx: cb_port.allocate_res.mshr_idx
        };
      end
    end

  end

  // MSHR => cb_port.allocate_req
  // mshrの中で,cb_allocateionがまだのものを選んで,allocate_reqを送る.
  always_comb begin
    mshr_entire_update_to_during_cb_alloc = '{default: 0};
    cb_port.allocate_req = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      if (mshr_info[i].valid && mshr_info[i].state_per_db[0] == BEFORE_CB_ALLOCATION) begin
        cb_port.allocate_req = '{
            valid: 1,
            paddr_cl_aligned: mshr_info[i].paddr_cl_aligned,
            mshr_idx: MSHR_IDX_WIDTH'(i),
            set_idx: mshr_info[i].set_idx
        };
        // mshr_next[i].state_per_db = '{default: DURING_CB_ALLOCATION};
        mshr_entire_update_to_during_cb_alloc = '{valid: 1, mshr_idx: MSHR_IDX_WIDTH'(i)};
        break;
      end
    end

  end


  // -----------------------------------------------------------------------------------------------------------------------------
  // mshrのエントリ削除
  // -----------------------------------------------------------------------------------------------------------------------------
  always_comb begin
    automatic int unsigned num_of_del = 0;

    // 削除するmshrの指定.
    delete_mshr_idx_valid = '{default: 0};
    delete_mshr_idx = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      automatic logic is_all_cb_updated = 1;
      if (mshr_info[i].valid) begin
        // すべてがcb_updatedかを調べる
        for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
          if (mshr_info[i].state_per_db[j] != CB_UPDATED) begin
            is_all_cb_updated = 0;
          end
        end

        if (is_all_cb_updated && mshr_info_reqq_next[i].noei_reqq == 0) begin
          delete_mshr_idx_valid[num_of_del] = 1;
          delete_mshr_idx[num_of_del] = MSHR_IDX_WIDTH'(i);
          num_of_del++;
        end

        if (num_of_del == NUM_OF_DELETE_MSHR_ENT) begin
          break;
        end
      end
    end
  end



  // ------------------------------------------------------------
  // Invalidate (Write_back_all)
  // ------------------------------------------------------------
  // fence.iの実装に際して,すべてを無効化し,dirtyなら書き戻すという処理を実装する.
  // alの先頭にfence.iが来たらdcache,icache両方でこれを行えば良い.
  //
  // write_back_allの場合,stall_req_inを出して新たに命令が入ってこないようにした上で,
  // availqやmshrが空になったあとで,
  // 現在キャッシュに入ってるすべてのdirtyのものをwrite_backする.
  // FENCE.I命令のときに用いる.
  // 信号が来たらCS_WAITING_INVALIDATEに,availq等が空になったらCS_INVALIDATINGに移行.
  // CS_INVALIDATINGでは,availqにwrite_backのreqを送る.

  // cb_port.read_reqのibからの入力
  cache_req_t read_req_from_ib[NUM_OF_CB_READ_REQ];

  typedef enum logic [1:0] {
    CS_NORMAL,
    CS_WAITING_INVALIDATE,
    CS_INVALIDATING
  } cache_state_e;
  cache_state_e cache_state;
  cache_state_e cache_state_next;

  //
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
    state_per_db_t [NUM_OF_DB_IN_CL-1:0] state_per_db;
  } invalidate_buf_t;

  // invalidate_buf本体
  invalidate_buf_t invalidate_buf[NUM_OF_MSHR];

  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] ib_idx;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
  } new_ib_ent_t;
  // 新しいinvalidate bufのエントリ.
  new_ib_ent_t new_ib_ent;
  // 削除するibのエントリ.
  logic ib_delete_valid;
  logic [MSHR_IDX_WIDTH-1:0] ib_delete_idx;

  // invalidate_bufのアップデート内容.
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] ib_idx;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    state_per_db_t state_per_db;  // すべてのdwで共通.
  } invalidate_buf_update_t;

  // paddr_cl_aligned の取得によるinvalidate_bufの更新
  invalidate_buf_update_t ib_update_paddr;

  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] ib_idx;
  } invalidate_buf_update_entire_state_t;
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] ib_idx;
    logic [DB_IN_CL_IDX_WIDTH-1:0] db_in_cl_idx;
  } invalidate_buf_update_state_t;
  invalidate_buf_update_entire_state_t ib_update_entire_to_during_cb_alloc;
  invalidate_buf_update_state_t ib_update_to_during_wb[NUM_OF_CB_READ_REQ];


  int unsigned invalidate_set_counter;
  int unsigned invalidate_set_counter_next;
  int unsigned invalidate_way_counter;
  int unsigned invalidate_way_counter_next;


  // 全てのキャッシュの内容を書き戻してinvalidateする.
  // はじめに,cb_infoの内容を取得し,dirtyなら,write_backのためのread_reqをcbに送る.
  // そのcl内の情報をwirte_backし終わったらinvalidate_reqでそのclを無効化する.



  always_comb begin
    // この２つについては,fifoでないのでこの下でエントリ数を計算する.
    // 要するに,stateの決定に用いる値で,availqのエントリ数のように常に正しいものでは無い.

    automatic int unsigned read_req_to_cb_counter = 0;

    automatic int unsigned delete_counter = 0;
    automatic logic has_written_back_all = 0;

    automatic logic all_invalidate_entries_registered = 0;

    //
    cache_state_next = cache_state;

    ib_update_paddr = '{default: 0, state_per_db: BEFORE_WRITE_BACK};

    // ibの状態更新
    ib_update_entire_to_during_cb_alloc = '{default: 0};
    ib_update_to_during_wb = '{default: 0};

    // ibにエントリの追加と削除
    new_ib_ent = '{default: 0};
    ib_delete_valid = 0;
    ib_delete_idx = 0;



    // set_counter,way_counter
    invalidate_set_counter_next = invalidate_set_counter;
    invalidate_way_counter_next = invalidate_way_counter;

    // cb_portへのreqの初期化
    cb_port.invalidate_get_info_req = '{default: 0};
    cb_port.invalidate_req = '{default: 0};
    read_req_from_ib = '{default: 0};


    invalidate_all_done_sig = 0;

    begin

      automatic logic mshr_empty = 1;
      automatic int unsigned noei_invalidate_buf = 0;
      automatic logic tmb_fully_empty = 1;

      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        if (mshr_info[i].valid) begin
          mshr_empty = 0;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        if (invalidate_buf[i].valid) begin
          noei_invalidate_buf++;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
        if (noei_tmb_free_fifo[i] != (TMB_INBANK_IDX_WIDTH + 1)'(TMB_BANK_SIZE)) begin
          tmb_fully_empty = 0;
        end
      end

      // 次のstateの決定.
      if (invalidate_all_sig && cache_state == CS_NORMAL) begin
        cache_state_next = CS_WAITING_INVALIDATE;
        invalidate_set_counter_next = 0;
        invalidate_way_counter_next = 0;
      end else if(cache_state == CS_WAITING_INVALIDATE && noei_aq == 0 &&
                tmb_fully_empty && noei_is == 0 && mshr_empty)begin
        // invalidate の開始.
        cache_state_next = CS_INVALIDATING;
      end else if(cache_state== CS_INVALIDATING &&
                invalidate_set_counter_next == NUM_OF_SETS &&
                noei_invalidate_buf == 0 && noei_aq == 0 &&
                tmb_fully_empty && noei_is == 0 && mshr_empty)begin
        // 終了したのでNORMALに戻して通常の処理を再開する
        // このとき,invalidate_way_couter は NUM_OF_WAYSになる.(NUM_OF_WAYS-1ではない)
        cache_state_next = CS_NORMAL;
        invalidate_all_done_sig = 1;
      end

    end

    // invalidate_bufを使って,cbの全てを無効化,及び書き戻しを行う.
    if (cache_state == CS_INVALIDATING) begin

      // cb_portからの情報リクエストのレスポンス.
      if (cb_port.invalidate_get_info_res.valid) begin
        ib_update_paddr = '{
            valid: 1,
            ib_idx: cb_port.invalidate_get_info_res.invalidate_buf_idx,
            paddr_cl_aligned: cb_port.invalidate_get_info_res.paddr_cl_aligned,
            state_per_db:
            cb_port.invalidate_get_info_res.dirty
            ?
            BEFORE_WRITE_BACK
            :
            BEFORE_REQUEST
        };
      end


      // cb_port.に情報のリクエスト
      // 情報をリクエスト中のときの状態は DURING_CB_ALLOCATION を使う.
      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        if(invalidate_buf[i].valid && invalidate_buf[i].state_per_db[0] == BEFORE_CB_ALLOCATION )begin
          // cb_portへ
          cb_port.invalidate_get_info_req = '{
              valid: 1,
              invalidate_buf_idx: MSHR_IDX_WIDTH'(i),
              set_idx: invalidate_buf[i].set_idx,
              way_idx: invalidate_buf[i].way_idx
          };
          ib_update_entire_to_during_cb_alloc = '{valid: 1, ib_idx: MSHR_IDX_WIDTH'(i)};
          break;
        end
      end

      // cb_port.read_reqにwrite_backのリクエストを送る.

      read_req_to_cb_counter = 0;
      for (int unsigned ib_idx = 0; ib_idx < NUM_OF_MSHR; ib_idx++) begin
        for (int unsigned db_in_cl_idx = 0; db_in_cl_idx < NUM_OF_DB_IN_CL; db_in_cl_idx++) begin
          if (invalidate_buf[ib_idx].state_per_db[db_in_cl_idx] == BEFORE_WRITE_BACK && read_req_to_cb_counter < NUM_OF_CB_READ_REQ) begin
            read_req_from_ib[read_req_to_cb_counter] = '{
                valid: 1,
                id:
                ib_idx, // wbbとinvalidate_bufのidxは共通なので,res_to_wbbがどのwbbかを判別するのに使う.
                id_sub: 0,
                generation: 0,
                req_policy: DATA_BULK_SIZE == 8 ? READ_DOUBLE_WORD : READ_QUAD_WORD,
                cb_req_type: READ_WRITE_BACK,
                vaddr_db_aligned: 0,
                paddr_valid: 1,
                paddr_db_aligned:
                invalidate_buf[ib_idx].paddr_cl_aligned
                +
                db_in_cl_idx
                *
                DATA_BULK_SIZE,
                byte_in_db_idx: 0,
                satp: 0,
                data: 0
            };
            ib_update_to_during_wb[read_req_to_cb_counter] = '{
                valid: 1,
                ib_idx: MSHR_IDX_WIDTH'(ib_idx),
                db_in_cl_idx: DB_IN_CL_IDX_WIDTH'(db_in_cl_idx)
            };
            read_req_to_cb_counter++;
          end
        end
      end


      // invalidate_bufのエントリで,全ての内容をwrite_backしたもの(BEFORE_REQUESTのもの)を削除
      begin
        delete_counter = 0;
        has_written_back_all = 0;
        for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
          has_written_back_all = 1;
          for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
            if (invalidate_buf[i].state_per_db[j] != BEFORE_REQUEST) begin
              has_written_back_all = 0;
            end
          end

          // invalidate_bufのエントリ削除.
          // invalidate_reqを送らないといけないので,1サイクルに消せるのは1つまで.
          if (invalidate_buf[i].valid && has_written_back_all) begin
            cb_port.invalidate_req = '{
                valid: 1,
                set_idx: invalidate_buf[i].set_idx,
                way_idx: invalidate_buf[i].way_idx
            };
            ib_delete_valid = 1;
            ib_delete_idx = MSHR_IDX_WIDTH'(i);
            break;
          end
        end
      end

      // 空きに新しいエントリを追加.
      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        // すでに全てののラインについて走査が終わっている,あるいはinvalidate_bufに入っているか.

        all_invalidate_entries_registered = invalidate_set_counter_next == NUM_OF_SETS;
        if (!invalidate_buf[i].valid && !all_invalidate_entries_registered) begin
          new_ib_ent = '{
              valid: 1,
              ib_idx: MSHR_IDX_WIDTH'(i),
              set_idx: SET_IDX_WIDTH'(invalidate_set_counter_next),
              way_idx: WAY_IDX_WIDTH'(invalidate_way_counter_next)
          };
          // way_counterとset_counterを更新.
          if (invalidate_way_counter_next == NUM_OF_WAYS - 1) begin
            invalidate_set_counter_next = invalidate_set_counter_next + 1;
            invalidate_way_counter_next = 0;
          end else begin
            invalidate_way_counter_next = invalidate_way_counter_next + 1;
          end
          break;
        end
      end

      // wbbでreq_outで書き出しが終わったら,DURING_WRITE_BACK => BEFORE_REQUEST
      // この処理はwbbの処理の方で行われる.

    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      cache_state <= CS_NORMAL;
      invalidate_set_counter <= 0;
      invalidate_way_counter <= 0;
    end else begin
      cache_state <= cache_state_next;
      invalidate_set_counter <= invalidate_set_counter_next;
      invalidate_way_counter <= invalidate_way_counter_next;

      // invalidate_bufに新規エントリの追加
      if (new_ib_ent.valid) begin
        invalidate_buf[new_ib_ent.ib_idx] <= '{
            valid: 1,
            paddr_cl_aligned: 0,
            set_idx: new_ib_ent.set_idx,
            way_idx: new_ib_ent.way_idx,
            state_per_db: '{default: BEFORE_CB_ALLOCATION}
        };
      end

      // invalidate_bufからエントリの削除
      if (ib_delete_valid) begin
        invalidate_buf[ib_delete_idx] <= '{default: 0};
      end

      // paddr_cl_alignedの取得による更新,及びdirtyならBEFORE_WRITE_BACKに,そうでないならBEFORE_REQUESTに状態を更新.
      if (ib_update_paddr.valid) begin
        invalidate_buf[ib_update_paddr.ib_idx].paddr_cl_aligned <= ib_update_paddr.paddr_cl_aligned;
        invalidate_buf[ib_update_paddr.ib_idx].state_per_db <= '{
            default: ib_update_paddr.state_per_db
        };
      end

      // BEFORE_CB_ALLOCATION => DURING_CB_ALLOCATION
      if (ib_update_entire_to_during_cb_alloc.valid) begin
        invalidate_buf[ib_update_entire_to_during_cb_alloc.ib_idx].state_per_db <= '{
            default: DURING_CB_ALLOCATION
        };
      end

      // BEFORE_WRITE_BACK => DURING_WRITE_BACK
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
        if (ib_update_to_during_wb[i].valid) begin
          invalidate_buf[ib_update_to_during_wb[i].ib_idx].state_per_db[ib_update_to_during_wb[i].db_in_cl_idx] <= DURING_WRITE_BACK;
        end
      end


      // DURING_WRITE_BACK => BEFORE_REQUEST
      for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
        if (mshr_update_to_before_request[i].valid) begin
          invalidate_buf[mshr_update_to_before_request[i].mshr_idx].state_per_db[mshr_update_to_before_request[i].db_in_cl_idx] <= BEFORE_REQUEST;
        end
      end

    end
  end


  // ----------------------------------------------------------------------------------------------------------
  // cb_port.read_reqの作成
  // ----------------------------------------------------------------------------------------------------------
  // read_req_from_ibとread_req_normalをマージしてcb_port.read_reqにする. 
  always_comb begin
    if (cache_state == CS_INVALIDATING) begin
      cb_port.read_req = read_req_from_ib;
    end else begin
      cb_port.read_req = read_req_normal;
    end
  end


  // ---------------------------------------------------------------------------------------------------------------------------
  // stall
  // ---------------------------------------------------------------------------------------------------------------------------
  always_comb begin
    // availqに十分なスペースがなかった場合,あとinvalidate中はstallする.
    stall_req_in = (AQ_SIZE - 32'(noei_aq_next) < NUM_OF_REQ_IN)
        ||  cache_state inside {CS_WAITING_INVALIDATE, CS_INVALIDATING};
  end


  // ---------------------------------------------------------------------------------------------------------------------
  // aq_next, is_next, wbb_next, tmb_next
  // ---------------------------------------------------------------------------------------------------------------------
  // aq_rp_nextからaq_headsを作るため,aqは_nextが必要だが,wbbなどは別にwbb_headsとかを作らないので_nextは本来不要
  // ただ,ものによって_nextがあったりなかったりするのもややこしいのでwbb_rp_nextとかも作る.
  always_comb begin
    // avail queue
    aq_rp_next = aq_rp + (AQ_BANK_IDX_WIDTH + AQ_INBANK_IDX_WIDTH)'(num_of_used_aq);
    aq_wp_next = aq_wp + (AQ_BANK_IDX_WIDTH + AQ_INBANK_IDX_WIDTH)'(new_aq_counter);
    noei_aq_next = noei_aq + (AQ_BANK_IDX_WIDTH + AQ_INBANK_IDX_WIDTH + 1)'(new_aq_counter)
                  - (AQ_BANK_IDX_WIDTH + AQ_INBANK_IDX_WIDTH + 1)'(num_of_used_aq);

    // input stack
    is_rp_next = is_rp + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH)'(num_of_used_is);
    is_wp_next = is_wp + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH)'(num_of_new_is);
    noei_is_next = noei_is + (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH+ 1)'(num_of_new_is) 
                  - (IS_INBANK_IDX_WIDTH + IS_BANK_IDX_WIDTH+ 1)'(num_of_used_is);

    // wbb
    wbb_rp_next = wbb_rp + (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH)'(noei_wbb_used);
    wbb_wp_next = wbb_wp + (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH)'(wbb_counter);
    noei_wbb_next= noei_wbb + (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH + 1)'(wbb_counter) 
                    - (WBB_INBANK_IDX_WIDTH + WBB_BANK_IDX_WIDTH + 1)'(noei_wbb_used);


    // tmb_paddr_valid
    tmb_paddr_valid_fifo_next = tmb_paddr_valid_fifo;
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (tmb_paddr_valid_fifo_new[i].valid) begin
        tmb_paddr_valid_fifo_next[tmb_paddr_valid_fifo_wp+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)] = {
          tmb_paddr_valid_fifo_new[i].tmb_inbank_idx, tmb_paddr_valid_fifo_new[i].tmb_bank_idx
        };
      end
    end
    tmb_paddr_valid_fifo_rp_next = tmb_paddr_valid_fifo_rp + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(num_of_used_tmb_paddr_valid_fifo);
    tmb_paddr_valid_fifo_wp_next = tmb_paddr_valid_fifo_wp + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(num_of_new_paddr_valid_fifo);
    noei_tmb_paddr_valid_fifo_next = noei_tmb_paddr_valid_fifo + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH+1)'(num_of_new_paddr_valid_fifo) 
                                    - (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH+1)'(num_of_used_tmb_paddr_valid_fifo);


    // tmb_fault_fifo
    tmb_fault_fifo_next = tmb_fault_fifo;
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      if (tmb_fault_fifo_new[i].valid) begin
        tmb_fault_fifo_next[tmb_fault_fifo_wp+(TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(i)] = {
          tmb_fault_fifo_new[i].tmb_inbank_idx, tmb_fault_fifo_new[i].tmb_bank_idx
        };
      end
    end
    tmb_fault_fifo_wp_next = tmb_fault_fifo_wp + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(num_of_new_tmb_fault_fifo);
    tmb_fault_fifo_rp_next = tmb_fault_fifo_rp + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH)'(num_of_used_tmb_fault_fifo);
    noei_tmb_fault_fifo_next = noei_tmb_fault_fifo + (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH+1)'(num_of_new_tmb_fault_fifo)
                               - (TMB_INBANK_IDX_WIDTH+TMB_BANK_IDX_WIDTH+1)'(num_of_used_tmb_fault_fifo);


    // tmb_free_fifo
    tmb_free_fifo_next = tmb_free_fifo;
    for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      if (tmb_free_fifo_new_non_tmb[i].valid) begin
        tmb_free_fifo_next[tmb_free_fifo_new_non_tmb[i].tmb_bank_idx][tmb_free_fifo_wp[i]] = tmb_free_fifo_new_non_tmb[i].tmb_inbank_idx;
      end
      if (tmb_free_fifo_new_tmb[i].valid) begin
        tmb_free_fifo_next[tmb_free_fifo_new_tmb[i].tmb_bank_idx][tmb_free_fifo_wp[i]+TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_non_tmb[i])] = 
            tmb_free_fifo_new_tmb[i].tmb_inbank_idx;
      end
      if (tmb_free_fifo_new_fault[i].valid) begin
        tmb_free_fifo_next[tmb_free_fifo_new_fault[i].tmb_bank_idx][tmb_free_fifo_wp[i]
                  +TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_non_tmb[i])+TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_tmb[i])] = 
            tmb_free_fifo_new_fault[i].tmb_inbank_idx;
      end
    end
    for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      tmb_free_fifo_rp_next[i] = tmb_free_fifo_rp[i] + TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_used[i]);
      tmb_free_fifo_wp_next[i] = tmb_free_fifo_wp[i] + TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_non_tmb[i]) 
                                  +  TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_tmb[i]) + TMB_INBANK_IDX_WIDTH'(num_of_tmb_free_fifo_new_fault[i]);
      noei_tmb_free_fifo_next[i] = noei_tmb_free_fifo[i] + (TMB_INBANK_IDX_WIDTH+1)'(num_of_tmb_free_fifo_new_non_tmb[i])
                                + (TMB_INBANK_IDX_WIDTH+1)'(num_of_tmb_free_fifo_new_tmb[i]) + (TMB_INBANK_IDX_WIDTH+1)'(num_of_tmb_free_fifo_new_fault[i])
                                - (TMB_INBANK_IDX_WIDTH+1)'(num_of_tmb_free_fifo_used[i]);
    end

    // mshr_info_reqq
    // num_of_new_ents_to_reqq ,num_of_used_reqq から reqq_rp, reqq_wp,noei_reqqの更新.
    mshr_info_reqq_next = mshr_info_reqq;
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      // 新規エントリの場合,invalidなmshrのreqq_rp,reqq_wpを右辺として更新が行われるが,
      // 消去するときにrp,wp,noeiが0なので問題はない.
      if (is_new_mshr[i]) begin
        // 新しいmshrエントリ
        mshr_info_reqq_next[i].reqq_rp   = 0;
        mshr_info_reqq_next[i].reqq_wp   = MSHR_REQQ_IDX_WIDTH'(num_of_new_ents_to_reqq[i]);
        mshr_info_reqq_next[i].noei_reqq = num_of_new_ents_to_reqq[i];
      end else begin
        // 既存のmshrエントリ
        mshr_info_reqq_next[i].reqq_rp = mshr_info_reqq[i].reqq_rp + MSHR_REQQ_IDX_WIDTH'(num_of_used_reqq[i]);
        mshr_info_reqq_next[i].reqq_wp = mshr_info_reqq[i].reqq_wp + MSHR_REQQ_IDX_WIDTH'(num_of_new_ents_to_reqq[i]);
        mshr_info_reqq_next[i].noei_reqq = mshr_info_reqq[i].noei_reqq + (MSHR_REQQ_IDX_WIDTH+1)'(num_of_new_ents_to_reqq[i]) 
                                  - (MSHR_REQQ_IDX_WIDTH+1)'(num_of_used_reqq[i]);
      end
    end


  end

  // -----------------------------------------------------------------------------------------------------
  // availq, tmb, input stack
  // -----------------------------------------------------------------------------------------------------

  always_ff @(posedge clock) begin
    if (reset) begin
      // availq
      aq_rp <= 0;
      aq_wp <= 0;
      noei_aq <= 0;

      // input stack
      is_rp <= 0;
      is_wp <= 0;
      noei_is <= 0;

      // wbb
      wbb_rp <= 0;
      wbb_wp <= 0;
      noei_wbb <= 0;

      // tmb_paddr_valid
      tmb_paddr_valid_fifo <= '{default: 0};
      tmb_paddr_valid_fifo_rp <= 0;
      tmb_paddr_valid_fifo_wp <= 0;
      noei_tmb_paddr_valid_fifo <= 0;

      // tmb_fault_fifo
      tmb_fault_fifo <= '{default: 0};
      tmb_fault_fifo_rp <= 0;
      tmb_fault_fifo_wp <= 0;
      noei_tmb_fault_fifo <= 0;

      // tmb_free_fifo
      for (int unsigned i = 0; i < TMB_BANK_SIZE; i++) begin
        for (int unsigned j = 0; j < NUM_OF_TMB_BANK; j++) begin
          tmb_free_fifo[j][i] <= TMB_INBANK_IDX_WIDTH'(i);
        end
      end
      tmb_free_fifo_rp <= '{default: 0};
      tmb_free_fifo_wp <= '{default: 0};
      for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
        noei_tmb_free_fifo[i] <= (TMB_INBANK_IDX_WIDTH + 1)'(TMB_BANK_SIZE);
      end

      // mshr
      mshr_info_reqq <= '{default: 0};
      mshr_info <= '{default: 0};

    end else begin

      // availq
      aq_rp <= aq_rp_next;
      aq_wp <= aq_wp_next;
      noei_aq <= noei_aq_next;

      // input stack
      is_rp <= is_rp_next;
      is_wp <= is_wp_next;
      noei_is <= noei_is_next;

      // aq,isと異なり,wbb,tmb

      // wbb
      wbb_rp <= wbb_rp_next;
      wbb_wp <= wbb_wp_next;
      noei_wbb <= noei_wbb_next;

      // tmb

      // tmb_paddr_valid
      tmb_paddr_valid_fifo <= tmb_paddr_valid_fifo_next;
      tmb_paddr_valid_fifo_rp <= tmb_paddr_valid_fifo_rp_next;
      tmb_paddr_valid_fifo_wp <= tmb_paddr_valid_fifo_wp_next;
      noei_tmb_paddr_valid_fifo <= noei_tmb_paddr_valid_fifo_next;

      // tmb_fault_fifo
      tmb_fault_fifo <= tmb_fault_fifo_next;
      tmb_fault_fifo_rp <= tmb_fault_fifo_rp_next;
      tmb_fault_fifo_wp <= tmb_fault_fifo_wp_next;
      noei_tmb_fault_fifo <= noei_tmb_fault_fifo_next;


      // tmb_free_fifo
      tmb_free_fifo <= tmb_free_fifo_next;
      tmb_free_fifo_rp <= tmb_free_fifo_rp_next;
      tmb_free_fifo_wp <= tmb_free_fifo_wp_next;
      noei_tmb_free_fifo <= noei_tmb_free_fifo_next;


      // mshr_info_reqq
      // num_of_new_ents_to_reqq ,num_of_used_reqq から reqq_rp, reqq_wp,noei_reqqの更新.
      mshr_info_reqq <= mshr_info_reqq_next;

      // mshr_info

      // 新規エントリの追加
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        if (new_mshr_info[i].valid) begin
          mshr_info[new_mshr_info_idx[i]] <= new_mshr_info[i];
        end
      end

      // エントリの削除
      for (int unsigned i = 0; i < NUM_OF_DELETE_MSHR_ENT; i++) begin
        if (delete_mshr_idx_valid[i]) begin
          mshr_info[delete_mshr_idx[i]] <= '{default: 0};
        end
      end



      // allocateした内容で更新
      if (mshr_allocate_info.valid) begin
        mshr_info[mshr_allocate_info.mshr_idx].way_idx <= mshr_allocate_info.way_idx;
        mshr_info[mshr_allocate_info.mshr_idx].paddr_cl_aligned_prev <= mshr_allocate_info.paddr_cl_aligned_prev;
      end

      // 状態更新
      // => BEFORE_CB_ALLOCATION
      if (mshr_entire_update_to_before_cb_alloc.valid) begin
        for (int unsigned i = 0; i < NUM_OF_DB_IN_CL; i++) begin
          mshr_info[mshr_entire_update_to_before_cb_alloc.mshr_idx].state_per_db[i] <= BEFORE_CB_ALLOCATION;
        end
      end

      // BEFORE_CB_ALLOCATION => DURING_CB_ALLOCATION
      if (mshr_entire_update_to_during_cb_alloc.valid) begin
        for (int unsigned i = 0; i < NUM_OF_DB_IN_CL; i++) begin
          mshr_info[mshr_entire_update_to_during_cb_alloc.mshr_idx].state_per_db[i] <= DURING_CB_ALLOCATION;
        end
      end

      // DURING_CB_ALLOCATION => BEFORE_WRITE_BACK
      if (mshr_entire_update_to_before_wb.valid) begin
        for (int unsigned i = 0; i < NUM_OF_DB_IN_CL; i++) begin
          mshr_info[mshr_entire_update_to_before_wb.mshr_idx].state_per_db[i] <= BEFORE_WRITE_BACK;
        end
      end

      // BEFORE_WRITE_BACK => DURING_WRITE_BACK
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        if (mshr_update_to_during_wb[i].valid) begin
          mshr_info[mshr_update_to_during_wb[i].mshr_idx].state_per_db[mshr_update_to_during_wb[i].db_in_cl_idx] <= DURING_WRITE_BACK;
        end
      end

      // DURING_CB_ALLOCATION => BEFORE_REQUEST 
      if (mshr_entire_update_to_before_request.valid) begin
        for (int unsigned i = 0; i < NUM_OF_DB_IN_CL; i++) begin
          mshr_info[mshr_entire_update_to_before_request.mshr_idx].state_per_db[i] <= BEFORE_REQUEST;
        end
      end

      // DURING_WRITE_BACK => BEFORE_REQUEST
      for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
        if (mshr_update_to_before_request[i].valid) begin
          mshr_info[mshr_update_to_before_request[i].mshr_idx].state_per_db[mshr_update_to_before_request[i].db_in_cl_idx] <= BEFORE_REQUEST;
        end
      end

      // BEFORE_REQUEST => DURING_REQUEST
      for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
        if (mshr_update_to_during_request[i].valid) begin
          mshr_info[mshr_update_to_during_request[i].mshr_idx].state_per_db[mshr_update_to_during_request[i].db_in_cl_idx] <= DURING_REQUEST;
        end
      end

      // DURING_REQUEST => CB_UPDATED
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        if (mshr_update_to_cb_updated[i].valid) begin
          mshr_info[mshr_update_to_cb_updated[i].mshr_idx].state_per_db[mshr_update_to_cb_updated[i].db_in_cl_idx] <= CB_UPDATED;
        end
      end

    end
  end



  // -----------------------------------------------------------------------------------------------------------------------------------
  // FOR DEBUG
  // -----------------------------------------------------------------------------------------------------------------------------------
  // (* mark_debug = "true" *) logic dbg_reset_seen;
  // (* mark_debug = "true" *) logic [7:0] dbg_reset_count;
  // (* mark_debug = "true" *) logic [3:0] dbg_noei_tmb_free_fifo0;
  // (* mark_debug = "true" *) logic [3:0] dbg_noei_tmb_free_fifo0_direct;

  // assign dbg_noei_tmb_free_fifo0_direct = noei_tmb_free_fifo[0];

  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     dbg_reset_seen <= 1'b1;
  //     dbg_reset_count <= dbg_reset_count + 1'b1;
  //     dbg_noei_tmb_free_fifo0 <= 4'd15;
  //   end else begin
  //     dbg_noei_tmb_free_fifo0 <= noei_tmb_free_fifo[0];
  //   end
  // end

`ifdef VERILATOR_COMPILE
  int fp_req_in;
  int fp_res_out;
  int fp_req_out;
  int fp_res_in;

  int fp_tlb_res;

  initial begin
    if (CACHE_CAT == 1) begin
      // icache
      fp_req_in  = $fopen("./log/icache_req_in.log", "w");
      fp_res_out = $fopen("./log/icache_res_out.log", "w");
      fp_req_out = $fopen("./log/icache_req_out.log", "w");
      fp_res_in  = $fopen("./log/icache_res_in.log", "w");

      fp_tlb_res = $fopen("./log/icache_tlb_res", "w");

    end else if (CACHE_CAT == 2) begin
      // dcache
      fp_req_in  = $fopen("./log/dcache_req_in.log", "w");
      fp_res_out = $fopen("./log/dcache_res_out.log", "w");
      fp_req_out = $fopen("./log/dcache_req_out.log", "w");
      fp_res_in  = $fopen("./log/dcache_res_in.log", "w");

      fp_tlb_res = $fopen("./log/dcache_tlb_res", "w");

    end
  end
`endif


  task automatic dump_reqq_heads();
    $display("========== dump_reqq_heads ==========");
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      $display("reqq_heads[%0d]:", i);
      $display("  valid            = %0d", reqq_heads[i].valid);
      $display("  id               = %0d", reqq_heads[i].id);
      $display("  id_sub           = %0d", reqq_heads[i].id_sub);
      $display("  generation       = %0d", reqq_heads[i].generation);
      $display("  req_policy       = %s", reqq_heads[i].req_policy.name());
      $display("  cb_req_type      = %s", reqq_heads[i].cb_req_type.name());
      $display("  vaddr_db_aligned = 0x%0h", reqq_heads[i].vaddr_db_aligned);
      $display("  paddr_valid      = %0d", reqq_heads[i].paddr_valid);
      $display("  paddr_db_aligned = 0x%0h", reqq_heads[i].paddr_db_aligned);
      $display("  byte_in_db_idx   = %0d", reqq_heads[i].byte_in_db_idx);
      $display("  satp.raw         = 0x%0h", reqq_heads[i].satp);
      $display("  data             = 0x%0h", reqq_heads[i].data);

      if (i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ) begin
        $display("  reqq_heads_valid = %0d", reqq_heads_valid[i]);
        $display("  mshr_idx         = %0d", reqq_heads_mshr_idx[i]);
      end
      $display("");
    end
  endtask



  task automatic dump_mshr_info();
    int i, j;
    string dw_states;

    begin
      $display("========== dump_mshr_info ==========");
      for (i = 0; i < NUM_OF_MSHR; i++) begin
        dw_states = "";
        for (j = 0; j < NUM_OF_DB_IN_CL; j++) begin
          if (j != 0) dw_states = {dw_states, ", "};
          dw_states = {dw_states, $sformatf("[%0d]=%s", j, mshr_info[i].state_per_db[j].name())};
        end

        $display("mshr_info[%0d]:", i);
        $display("  valid                = %0d", mshr_info[i].valid);
        $display("  paddr_cl_aligned     = 0x%0h", mshr_info[i].paddr_cl_aligned);
        $display("  set_idx              = 0x%0h", mshr_info[i].set_idx);
        $display("  way_idx              = 0x%0h", mshr_info[i].way_idx);
        $display("  paddr_cl_aligned_prev= 0x%0h", mshr_info[i].paddr_cl_aligned_prev);
        $display("  reqq_rp              = %0d", mshr_info_reqq[i].reqq_rp);
        $display("  reqq_wp              = %0d", mshr_info_reqq[i].reqq_wp);
        $display("  noei_reqq            = %0d", mshr_info_reqq[i].noei_reqq);
        $display("  state_per_db         = { %s }", dw_states);
      end
      $display("====================================");
    end
  endtask

  int unsigned debug_counter;
  always_ff @(posedge clock) begin
    if (reset) begin
      debug_counter <= 0;
    end else begin
      debug_counter <= debug_counter + 1;

      // 
      // if (debug_counter == 100000 && CACHE_CAT == 3) begin
      //   dump_mshr_info();
      //   // dump_reqq_heads();
      //   $display("===================================================");
      //   $display("from_where:%s", from_where.name());
      //   $display("noei_is: %d", noei_is);
      //   $display("noei_aq: %d", noei_aq);
      //   $display("unified_reqq_r_idx[0]:%h", unified_reqq_r_idx[0]);
      //   $display("tmb_noroom: %d", tmb_noroom);
      //   for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
      //     $display("noei_tmb_free_fifo[%d] %d", i, noei_tmb_free_fifo[i]);
      //   end
      //   $display("===================================================");
      // end

      // if (CACHE_CAT == 3) begin
      //   for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      //     if (mshr_is_all_db_updated[i] && mshr_info[i].paddr_cl_aligned == 56'h80000000) begin
      //       dump_mshr_info();
      //       $display("noei_aq:%d", noei_aq);
      //     end
      //   end
      // end

      // if (CACHE_CAT == 1 && stall_req_in) begin
      //   $display("icache req_in stall");
      // end
      // if (CACHE_CAT == 2 && stall_req_in) begin
      //   $display("dcache req_in stall");
      // end
      // if (CACHE_CAT == 3 && stall_req_in) begin
      //   $display("l2cache req_in stall");
      // end

      // req_in
      // for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
      //   if (req_in[i].valid) begin
      //     $fdisplay(
      //         fp_req_in,
      //         "i=%0d id=%0d req_policy:%s,req_type:%s vaddr=%h paddr_valid=%0b paddr=%h data=%h",
      //         i, req_in[i].id, req_in[i].req_policy.name(), req_in[i].cb_req_type.name(),
      //         req_in[i].vaddr_db_aligned, req_in[i].paddr_valid, req_in[i].paddr_db_aligned,
      //         req_in[i].data);
      //     $fflush(fp_req_in);
      //   end
      // end

      // res_out
      // for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      //   if (res_out[i].valid) begin
      //     $fdisplay(
      //         fp_res_out,
      //         "i=%0d id=%0d pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_db_idx=%0d data=%016h pf=%b af=%b",
      //         i, res_out[i].id, res_out[i].is_page_fault, res_out[i].is_access_fault,
      //         res_out[i].req_policy.name(), res_out[i].cb_req_type.name(),
      //         res_out[i].vaddr_db_aligned, res_out[i].paddr_db_aligned, res_out[i].byte_in_db_idx,
      //         res_out[i].data, res_out[i].is_page_fault, res_out[i].is_access_fault);
      //     $fflush(fp_res_out);
      //   end
      // end

      // // req_out
      // for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      //   if (req_out[i].valid) begin
      //     $fdisplay(
      //         fp_req_out,
      //         "i=%0d id=%0d req_policy:%s,req_type:%s vaddr=%h paddr_valid=%0b paddr=%h data=%h",
      //         i, req_out[i].id, req_out[i].req_policy.name(), req_out[i].cb_req_type.name(),
      //         req_out[i].vaddr_db_aligned, req_out[i].paddr_valid, req_out[i].paddr_db_aligned,
      //         req_out[i].data);
      //     $fflush(fp_req_out);
      //   end
      // end

      // // res_in
      // for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
      //   if (res_in[i].valid) begin
      //     $fdisplay(
      //         fp_res_in,
      //         "i=%0d id=%0d pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_db_idx=%0d data=%016h",
      //         i, res_in[i].id, res_in[i].is_page_fault, res_in[i].is_access_fault,
      //         res_in[i].req_policy.name(), res_in[i].cb_req_type.name(), res_in[i].vaddr_db_aligned,
      //         res_in[i].paddr_db_aligned, res_in[i].byte_in_db_idx, res_in[i].data);
      //     $fflush(fp_res_in);
      //   end
      // end

      // // req_in
      // for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
      //   if (req_in[i].valid && req_in[i].vaddr_db_aligned == 39'h00800006d0) begin
      //     $display(
      //         "req_in i=%0d id=%0d req_policy:%s,req_type:%s vaddr=%h paddr_valid=%0b paddr=%h data=%h",
      //         i, req_in[i].id, req_in[i].req_policy.name(), req_in[i].cb_req_type.name(),
      //         req_in[i].vaddr_db_aligned, req_in[i].paddr_valid, req_in[i].paddr_db_aligned,
      //         req_in[i].data);
      //     $fflush(fp_req_in);
      //   end
      // end

      // // res_out
      // for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      //   if (res_out[i].valid && res_out[i].vaddr_db_aligned == 39'h0080001620 && CACHE_CAT == 1) begin
      //     $display(
      //         "res_out i=%0d id=%0d pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_db_idx=%0d data=%016h pf=%b af=%b",
      //         i, res_out[i].id, res_out[i].is_page_fault, res_out[i].is_access_fault,
      //         res_out[i].req_policy.name(), res_out[i].cb_req_type.name(),
      //         res_out[i].vaddr_db_aligned, res_out[i].paddr_db_aligned, res_out[i].byte_in_db_idx,
      //         res_out[i].data, res_out[i].is_page_fault, res_out[i].is_access_fault);
      //     $fflush(fp_res_out);
      //   end
      // end

      // // req_out
      // for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      //   if (req_out[i].valid && req_out[i].vaddr_db_aligned == 39'h00800006d0) begin
      //     $display(
      //         "req_out i=%0d id=%0d req_policy:%s,req_type:%s vaddr=%h paddr_valid=%0b paddr=%h data=%h",
      //         i, req_out[i].id, req_out[i].req_policy.name(), req_out[i].cb_req_type.name(),
      //         req_out[i].vaddr_db_aligned, req_out[i].paddr_valid, req_out[i].paddr_db_aligned,
      //         req_out[i].data);
      //     $fflush(fp_req_out);
      //   end
      // end

      // // res_in
      // for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
      //   if (res_in[i].valid && res_in[i].vaddr_db_aligned == 39'h00800006d0) begin
      //     $display(

      //         "res_in i=%0d id=%0d pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr=%016h paddr=%016h byte_in_db_idx=%0d data=%016h",
      //         i, res_in[i].id, res_in[i].is_page_fault, res_in[i].is_access_fault,
      //         res_in[i].req_policy.name(), res_in[i].cb_req_type.name(), res_in[i].vaddr_db_aligned,
      //         res_in[i].paddr_db_aligned, res_in[i].byte_in_db_idx, res_in[i].data);
      //     $fflush(fp_res_in);
      //   end
      // end



    end
  end


  always_comb begin
    // 
    // if (from_where_prev == FROM_TMB) begin
    //   $display("============FROM_TMB============");
    //   for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
    //     dump_cache_res(res_out[i]);
    //   end
    // end

    // if(from_where inside {FROM_REQ_IN,FROM_AVAILQ})begin
    //   for(int unsigned i=0; i<NUM_OF_CB_READ;i++)begin
    //   if(read_req_prev[i].valid && !read_req_prev[i].is_paddr)begin

    //   end
    // end
  end

  // 4bitをASCIIの16進文字に変換する
  function automatic logic [7:0] hex_nibble_to_ascii(input logic [3:0] nibble);
    begin
      if (nibble < 4'd10) begin
        return 8'h30 + {4'h0, nibble};  // '0' - '9'
      end else begin
        return 8'h41 + {4'h0, nibble - 4'd10};  // 'A' - 'F'
      end
    end
  endfunction


`ifdef VIVADO_COMPILE
  int unsigned dcounter;
  always_ff @(posedge clock) begin
    if (reset) begin
      dcounter <= 0;
      data_print_en <= 0;
      data_print <= 0;
    end else begin
      dcounter <= dcounter + 1;
      data_print_en <= 0;
      for (int unsigned b = 0; b < NUM_OF_TMB_BANK; b++) begin
        if (num_of_tmb_free_fifo_new_non_tmb[b] != 0 ||
            num_of_tmb_free_fifo_new_tmb[b]     != 0 ||
            num_of_tmb_free_fifo_new_fault[b]   != 0 ||
            num_of_tmb_free_fifo_used[b]        != 0 || 
            32'(noei_tmb_free_fifo[b]) != TMB_BANK_SIZE ) begin

          data_print_en <= 1;

          // Format:
          // \n\r B<bank> N<nontmb> T<tmb> F<fault> U<used>
          //
          // 例: B0N0T1F0U1
          data_print[7:0] <= 8'h0a;
          data_print[15:8] <= 8'h0d;

          data_print[23:16] <= "B";
          data_print[31:24] <= hex_nibble_to_ascii(4'(b));

          data_print[39:32] <= "N";
          data_print[47:40] <= hex_nibble_to_ascii(4'(num_of_tmb_free_fifo_new_non_tmb[b]));

          data_print[55:48] <= "T";
          data_print[63:56] <= hex_nibble_to_ascii(4'(num_of_tmb_free_fifo_new_tmb[b]));

          data_print[71:64] <= "F";
          data_print[79:72] <= hex_nibble_to_ascii(4'(num_of_tmb_free_fifo_new_fault[b]));

          data_print[87:80] <= "U";
          data_print[95:88] <= hex_nibble_to_ascii(4'(num_of_tmb_free_fifo_used[b]));

          // ついでに index も見る。不要ならここから下は消してOK。
          data_print[103:96] <= " ";

          data_print[111:104] <= "Q";
          data_print[119:112] <= hex_nibble_to_ascii(4'(noei_tmb_free_fifo[b]));

          data_print[127:120] <= "q";
          data_print[135:128] <= hex_nibble_to_ascii(4'(noei_tmb_free_fifo_next[b]));

          data_print[143:136] <= "R";
          data_print[151:144] <= hex_nibble_to_ascii(4'(tmb_free_fifo_rp[b]));

          data_print[159:152] <= "W";
          data_print[167:160] <= hex_nibble_to_ascii(4'(tmb_free_fifo_wp[b]));

          data_print[255:168] <= '0;
        end
      end
    end
  end


`endif

  // `ifdef VIVADO_COMPILE
  //   always_ff @(posedge clock) begin
  //     if (reset) begin
  //       data_print_en <= 0;
  //       data_print    <= '0;
  //     end else begin
  //       data_print_en <= 0;
  //       data_print    <= '0;

  //       for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
  //         if (req_in[i].valid) begin
  //           data_print_en       <= 1;

  //           // 32 chars:
  //           // R0P1Q3C1I0G0V12345678A9ABCDEF\r\n
  //           //
  //           // 注意:
  //           // 先頭文字を data_print[255:248] に置く。
  //           // 末尾文字を data_print[7:0] に置く。

  //           data_print[255:248] <= "R";
  //           data_print[247:240] <= hex_nibble_to_ascii(4'(i));

  //           data_print[239:232] <= "P";
  //           data_print[231:224] <= hex_nibble_to_ascii({3'b000, req_in[i].paddr_valid});

  //           data_print[223:216] <= "Q";
  //           data_print[215:208] <= hex_nibble_to_ascii(4'(req_in[i].req_policy));

  //           data_print[207:200] <= "C";
  //           data_print[199:192] <= hex_nibble_to_ascii({1'b0, req_in[i].cb_req_type});

  //           data_print[191:184] <= "I";
  //           data_print[183:176] <= hex_nibble_to_ascii(req_in[i].id[3:0]);

  //           data_print[175:168] <= "G";
  //           data_print[167:160] <= hex_nibble_to_ascii(req_in[i].generation[3:0]);

  //           data_print[159:152] <= "V";
  //           data_print[151:144] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[31:28]);
  //           data_print[143:136] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[27:24]);
  //           data_print[135:128] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[23:20]);
  //           data_print[127:120] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[19:16]);
  //           data_print[119:112] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[15:12]);
  //           data_print[111:104] <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[11:8]);
  //           data_print[103:96]  <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[7:4]);
  //           data_print[95:88]   <= hex_nibble_to_ascii(req_in[i].vaddr_db_aligned[3:0]);

  //           data_print[87:80]   <= "A";
  //           data_print[79:72]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[31:28]);
  //           data_print[71:64]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[27:24]);
  //           data_print[63:56]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[23:20]);
  //           data_print[55:48]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[19:16]);
  //           data_print[47:40]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[15:12]);
  //           data_print[39:32]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[11:8]);
  //           data_print[31:24]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[7:4]);
  //           data_print[23:16]   <= hex_nibble_to_ascii(req_in[i].paddr_db_aligned[3:0]);

  //           data_print[15:8]    <= 8'h0d;
  //           data_print[7:0]     <= 8'h0a;

  //           break;
  //         end
  //       end
  //     end
  //   end
  // `endif


  // -----------------------------------------------------------------
  // FOR DEBUG
  // -----------------------------------------------------------------


  logic res_in_q_valid[NUM_OF_RES_IN];

  always_ff @(posedge clock) begin
    if (reset) begin
      res_in_q_valid <= '{default: 0};
    end else begin
      for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
        res_in_q_valid[i] <= res_in[i].valid;
      end
    end
  end

  logic res_out_q_valid[NUM_OF_RES_OUT];

  always_ff @(posedge clock) begin
    if (reset) begin
      res_out_q_valid <= '{default: 0};
    end else begin
      for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
        res_out_q_valid[i] <= res_out[i].valid;
      end
    end
  end

  logic mshr_info_valid[NUM_OF_MSHR];
  logic [MSHR_REQQ_IDX_WIDTH:0] mahr_info_reqq_noei_reqq[NUM_OF_MSHR];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
      mshr_info_valid[i] = mshr_info[i].valid;
      mahr_info_reqq_noei_reqq[i] = mshr_info_reqq[i].noei_reqq;
    end
  end




  // (*mark_debug="true"*) logic req_in_valid_debug[NUM_OF_REQ_IN];
  // (*mark_debug="true"*) logic req_in_paddr_valid_debug[NUM_OF_REQ_IN];
  // (*mark_debug="true"*) logic [PADDR_WIDTH-1:0] req_in_paddr_debug[NUM_OF_REQ_IN];
  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     req_in_valid_debug <= '{default: 0};
  //     req_in_paddr_valid_debug <= '{default: 0};
  //     req_in_paddr_debug <= '{default: 0};
  //   end else begin
  //     for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
  //       req_in_valid_debug[i] <= req_in[i].valid;
  //       req_in_paddr_valid_debug[i] <= req_in[i].paddr_valid;
  //       req_in_paddr_debug[i] <= req_in[i].paddr_db_aligned;
  //     end
  //   end
  // end

  // =================================================================================================
  // Periodic Cache Logger
  //   - CACHE_CAT == 1 : ./log/icache.log
  //   - CACHE_CAT == 2 : ./log/dcache.log
  //   - 1000 cyclesごとに "w" で開くので, 毎回ログファイルを作り直す/上書きする
  //   - Verilator / simulation 用. 合成対象外.
  // =================================================================================================
  // synthesis translate_off


  int unsigned cache_periodic_log_cycle;
  integer cache_periodic_log_fp;
  integer cache_periodic_log_status;

  initial begin
    // ./log が無いと $fopen が失敗するため.
    // これはVerilatorでは普通に使える.
    cache_periodic_log_status = $system("mkdir -p ./log");
  end

  task automatic cache_periodic_log_dump_req(input integer fp, input string label,
                                             input int unsigned idx, input cache_req_t r);
    begin
      $fdisplay(
          fp,
          "%s[%0d]: valid=%0b id=%0d id_sub=%0d gen=%0d req_policy=%s cb_req_type=%s vaddr_dw=0x%0h paddr_valid=%0b paddr_dw=0x%0h byte_idx=%0d satp=0x%0h data=0x%016h",
          label, idx, r.valid, r.id, r.id_sub, r.generation, r.req_policy.name(),
          r.cb_req_type.name(), r.vaddr_db_aligned, r.paddr_valid, r.paddr_db_aligned,
          r.byte_in_db_idx, r.satp, r.data);
    end
  endtask

  task automatic cache_periodic_log_dump_res(input integer fp, input string label,
                                             input int unsigned idx, input cache_res_t r);
    begin
      $fdisplay(
          fp,
          "%s[%0d]: valid=%0b id=%0d id_sub=%0d gen=%0d pf=%0b af=%0b req_policy=%s cb_req_type=%s vaddr_dw=0x%0h paddr_dw=0x%0h byte_idx=%0d data=0x%016h",
          label, idx, r.valid, r.id, r.id_sub, r.generation, r.is_page_fault, r.is_access_fault,
          r.req_policy.name(), r.cb_req_type.name(), r.vaddr_db_aligned, r.paddr_db_aligned,
          r.byte_in_db_idx, r.data);
    end
  endtask

  task automatic cache_periodic_log_dump_tlb_req(input integer fp, input string label,
                                                 input int unsigned idx, input tlb_req_t r);
    begin
      $fdisplay(fp, "%s[%0d]: valid=%0b id=%0d id_sub=%0d gen=%0d vaddr=0x%0h satp=0x%0h", label,
                idx, r.valid, r.id, r.id_sub, r.generation, r.vaddr, r.satp);
    end
  endtask

  task automatic cache_periodic_log_dump_tlb_res(input integer fp, input string label,
                                                 input int unsigned idx, input tlb_res_t r);
    begin
      $fdisplay(
          fp,
          "%s[%0d]: valid=%0b id=%0d id_sub=%0d gen=%0d vaddr=0x%0h paddr=0x%0h pma=%s pf=%0b pte_a=%0b pte_d=%0b satp=0x%0h",
          label, idx, r.valid, r.id, r.id_sub, r.generation, r.vaddr, r.paddr, r.pma_type.name(),
          r.is_page_fault, r.pte_a, r.pte_d, r.satp);
    end
  endtask

  task automatic cache_periodic_log_dump_mshr(input integer fp);
    string dw_states;
    begin
      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- MSHR ----------------");

      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        dw_states = "";
        for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
          if (j != 0) dw_states = {dw_states, ", "};
          dw_states = {dw_states, $sformatf("[%0d]=%s", j, mshr_info[i].state_per_db[j].name())};
        end

        $fdisplay(
            fp,
            "mshr[%0d]: valid=%0b paddr_cl=0x%0h set=0x%0h way=0x%0h prev_paddr_cl=0x%0h all_updated=%0b reqq_rp=%0d reqq_wp=%0d noei_reqq=%0d states={%s}",
            i, mshr_info[i].valid, mshr_info[i].paddr_cl_aligned, mshr_info[i].set_idx,
            mshr_info[i].way_idx, mshr_info[i].paddr_cl_aligned_prev, mshr_is_all_db_updated[i],
            mshr_info_reqq[i].reqq_rp, mshr_info_reqq[i].reqq_wp, mshr_info_reqq[i].noei_reqq,
            dw_states);
      end

      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        cache_periodic_log_dump_req(fp, "reqq_heads", i, reqq_heads[i]);
        $fdisplay(fp, "reqq_heads_mshr_idx[%0d]=%0d", i, reqq_heads_mshr_idx[i]);
      end

      $fdisplay(fp, "mshr_before_req_fifo: rp=%0d wp=%0d noei=%0d", mshr_before_req_fifo_rp,
                mshr_before_req_fifo_wp, noei_mshr_before_req_fifo);
    end
  endtask

  task automatic cache_periodic_log_dump_invalidate(input integer fp);
    string ib_states;
    begin
      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- INVALIDATE ----------------");
      $fdisplay(
          fp,
          "invalidate_all_sig=%0b invalidate_all_done_sig=%0b cache_state=%s set_counter=%0d way_counter=%0d",
          invalidate_all_sig, invalidate_all_done_sig, cache_state.name(), invalidate_set_counter,
          invalidate_way_counter);

      for (int unsigned i = 0; i < NUM_OF_MSHR; i++) begin
        ib_states = "";
        for (int unsigned j = 0; j < NUM_OF_DB_IN_CL; j++) begin
          if (j != 0) ib_states = {ib_states, ", "};
          ib_states = {
            ib_states, $sformatf("[%0d]=%s", j, invalidate_buf[i].state_per_db[j].name())
          };
        end

        $fdisplay(fp,
                  "invalidate_buf[%0d]: valid=%0b paddr_cl=0x%0h set=0x%0h way=0x%0h states={%s}",
                  i, invalidate_buf[i].valid, invalidate_buf[i].paddr_cl_aligned,
                  invalidate_buf[i].set_idx, invalidate_buf[i].way_idx, ib_states);
      end

      $fdisplay(fp, "cb.invalidate_get_info_req: valid=%0b ib_idx=%0d set=%0d way=%0d",
                cb_port.invalidate_get_info_req.valid,
                cb_port.invalidate_get_info_req.invalidate_buf_idx,
                cb_port.invalidate_get_info_req.set_idx, cb_port.invalidate_get_info_req.way_idx);

      $fdisplay(fp, "cb.invalidate_req: valid=%0b set=%0d way=%0d", cb_port.invalidate_req.valid,
                cb_port.invalidate_req.set_idx, cb_port.invalidate_req.way_idx);
    end
  endtask

  task automatic cache_periodic_log_dump_one_cache(input integer fp, input int unsigned cyc);
    begin
      $fdisplay(
          fp,
          "=================================================================================================");
      if (CACHE_CAT == 1) begin
        $fdisplay(fp, "ICACHE periodic log");
      end else if (CACHE_CAT == 2) begin
        $fdisplay(fp, "DCACHE periodic log");
      end else begin
        $fdisplay(fp, "CACHE periodic log: CACHE_CAT=%0d", CACHE_CAT);
      end
      $fdisplay(fp, "cycle=%0d time=%0t", cyc, $time);
      $fdisplay(
          fp,
          "CACHE_CAT=%0d NUM_OF_REQ_IN=%0d NUM_OF_RES_OUT=%0d NUM_OF_REQ_OUT=%0d NUM_OF_RES_IN=%0d",
          CACHE_CAT, NUM_OF_REQ_IN, NUM_OF_RES_OUT, NUM_OF_REQ_OUT, NUM_OF_RES_IN);
      $fdisplay(fp, "NUM_OF_WAYS=%0d NUM_OF_SETS=%0d CL_SIZE=%0d NUM_OF_DB_IN_CL=%0d", NUM_OF_WAYS,
                NUM_OF_SETS, CL_SIZE, NUM_OF_DB_IN_CL);
      $fdisplay(fp, "reset=%0b stall_req_in=%0b stall_req_out=%0b stall_req_to_tlb=%0b", reset,
                stall_req_in, stall_req_out, stall_req_to_tlb);
      $fdisplay(fp, "from_where=%s from_where_prev=%s cache_state=%s", from_where.name(),
                from_where_prev.name(), cache_state.name());

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- FIFO / QUEUE COUNTERS ----------------");
      $fdisplay(
          fp,
          "AQ : rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | new=%0d used=%0d",
          aq_rp, aq_wp, noei_aq, aq_rp_next, aq_wp_next, noei_aq_next, new_aq_counter,
          num_of_used_aq);
      $fdisplay(
          fp,
          "IS : rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | new=%0d used=%0d",
          is_rp, is_wp, noei_is, is_rp_next, is_wp_next, noei_is_next, num_of_new_is,
          num_of_used_is);
      $fdisplay(
          fp,
          "WBB: rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | used=%0d returned=%0d",
          wbb_rp, wbb_wp, noei_wbb, wbb_rp_next, wbb_wp_next, noei_wbb_next, noei_wbb_used,
          noei_wbb_returned);

      $fdisplay(
          fp,
          "TMB paddr_valid_fifo: rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | new=%0d used=%0d",
          tmb_paddr_valid_fifo_rp, tmb_paddr_valid_fifo_wp, noei_tmb_paddr_valid_fifo,
          tmb_paddr_valid_fifo_rp_next, tmb_paddr_valid_fifo_wp_next,
          noei_tmb_paddr_valid_fifo_next, num_of_new_paddr_valid_fifo,
          num_of_used_tmb_paddr_valid_fifo);

      $fdisplay(
          fp,
          "TMB fault_fifo: rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | new=%0d used=%0d",
          tmb_fault_fifo_rp, tmb_fault_fifo_wp, noei_tmb_fault_fifo, tmb_fault_fifo_rp_next,
          tmb_fault_fifo_wp_next, noei_tmb_fault_fifo_next, num_of_new_tmb_fault_fifo,
          num_of_used_tmb_fault_fifo);

      for (int unsigned i = 0; i < NUM_OF_TMB_BANK; i++) begin
        $fdisplay(
            fp,
            "TMB free_fifo[%0d]: rp=%0d wp=%0d noei=%0d | next_rp=%0d next_wp=%0d next_noei=%0d | used=%0d new_non_tmb=%0d new_tmb=%0d new_fault=%0d",
            i, tmb_free_fifo_rp[i], tmb_free_fifo_wp[i], noei_tmb_free_fifo[i],
            tmb_free_fifo_rp_next[i], tmb_free_fifo_wp_next[i], noei_tmb_free_fifo_next[i],
            num_of_tmb_free_fifo_used[i], num_of_tmb_free_fifo_new_non_tmb[i],
            num_of_tmb_free_fifo_new_tmb[i], num_of_tmb_free_fifo_new_fault[i]);
      end

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- UPPER <=> CACHE ----------------");
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        cache_periodic_log_dump_req(fp, "req_in", i, req_in[i]);
      end
      for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
        cache_periodic_log_dump_res(fp, "res_out", i, res_out[i]);
      end

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- CACHE <=> LOWER ----------------");
      for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
        cache_periodic_log_dump_req(fp, "req_out", i, req_out[i]);
      end
      for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
        cache_periodic_log_dump_res(fp, "res_in", i, res_in[i]);
      end

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- CACHE <=> TLB ----------------");
      for (int unsigned i = 0; i < REQ_TO_TLB; i++) begin
        cache_periodic_log_dump_tlb_req(fp, "req_to_tlb", i, req_to_tlb[i]);
      end
      for (int unsigned i = 0; i < RES_FROM_TLB; i++) begin
        cache_periodic_log_dump_tlb_res(fp, "res_from_tlb", i, res_from_tlb[i]);
      end

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- CB PORT REQ/RES ----------------");
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
        cache_periodic_log_dump_req(fp, "cb.read_req", i, cb_port.read_req[i]);
        cache_periodic_log_dump_req(fp, "read_req_prev", i, read_req_prev[i]);
        cache_periodic_log_dump_res(fp, "cb.res_out", i, cb_port.res_out[i]);
        cache_periodic_log_dump_res(fp, "cb.res_to_wbb", i, cb_port.res_to_wbb[i]);
      end

      // for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      //   cache_periodic_log_dump_req(fp, "cb.write_req", i, cb_port.write_req[i]);
      //   cache_periodic_log_dump_req(fp, "write_req_prev", i, write_req_prev[i]);

      //   $fdisplay(
      //       fp,
      //       "write_buf[%0d]: valid=%0b req_policy=%s cb_req_type=%s tag=0x%0h dw_idx=%0d byte_idx=%0d set=%0d way=%0d data=0x%016h",
      //       i, write_buf[i].valid, write_buf[i].req_policy.name(), write_buf[i].cb_req_type.name(),
      //       write_buf[i].tag, write_buf[i].db_in_cl_idx, write_buf[i].byte_in_db_idx,
      //       write_buf[i].set_idx, write_buf[i].way_idx, write_buf[i].data);
      // end

      // for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      //   cache_periodic_log_dump_res(fp, "cb.res_to_mshr", i, cb_port.res_to_mshr[i]);
      //   cache_periodic_log_dump_res(fp, "cb.res_to_tmb", i, cb_port.res_to_tmb[i]);
      //   $fdisplay(fp, "cb.mshr_new_state[%0d]: valid=%0b paddr_cl=0x%0h dw_idx=%0d state=%s", i,
      //             cb_port.mshr_new_state[i].valid, cb_port.mshr_new_state[i].paddr_cl_aligned,
      //             cb_port.mshr_new_state[i].db_in_cl_idx,
      //             cb_port.mshr_new_state[i].state_per_db.name());
      // end

      $fdisplay(fp, "");
      $fdisplay(fp, "---------------- HEADS ----------------");
      for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
        cache_periodic_log_dump_req(fp, "aq_heads", i, aq_heads[i]);
        cache_periodic_log_dump_req(fp, "tmb_paddr_valid_fifo_heads", i,
                                    tmb_paddr_valid_fifo_heads[i]);
      end

      for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
        cache_periodic_log_dump_req(fp, "tmb_fault_fifo_heads", i, tmb_fault_fifo_heads[i]);
      end

      for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
        cache_periodic_log_dump_res(fp, "is_heads", i, is_heads[i]);
      end

      cache_periodic_log_dump_mshr(fp);
      cache_periodic_log_dump_invalidate(fp);

      $fdisplay(
          fp,
          "=================================================================================================");
    end
  endtask

  always @(posedge clock) begin
    if (reset) begin
      cache_periodic_log_cycle <= 0;
    end else begin
      cache_periodic_log_cycle <= cache_periodic_log_cycle + 1;

      // if (((cache_periodic_log_cycle + 1) % 1000) == 0) begin
      //   if (CACHE_CAT == 1) begin
      //     cache_periodic_log_fp = $fopen("./log/icache.log", "w");
      //     if (cache_periodic_log_fp != 0) begin
      //       cache_periodic_log_dump_one_cache(cache_periodic_log_fp, cache_periodic_log_cycle + 1);
      //       $fclose(cache_periodic_log_fp);
      //     end
      //   end else if (CACHE_CAT == 2) begin
      //     cache_periodic_log_fp = $fopen("./log/dcache.log", "w");
      //     if (cache_periodic_log_fp != 0) begin
      //       cache_periodic_log_dump_one_cache(cache_periodic_log_fp, cache_periodic_log_cycle + 1);
      //       $fclose(cache_periodic_log_fp);
      //     end
      //   end
      // end
    end
  end

  // synthesis translate_on

endmodule
