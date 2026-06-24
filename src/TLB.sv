`timescale 1ns / 1ps
// L2TLB
//
// L1DTLB,L1ITLBから,それぞれ1サイクルに1つまでの入力を受け付ける.
//
//
// ・仮想アドレス
//  38                       20 19            12 11                0
//  ----------------------------------------------------------------
//  |     tag                  |   set_idx      |   offset in page |
//  ----------------------------------------------------------------
//
// ・物理アドレス
//  55                                            12 11                      0
//  ------------------------------------------------------------------------------
//  |              paddr_page_aligned_cut0          |       offset in page       |
//  ------------------------------------------------------------------------------
//
//
// [重要]Cacheでの順序を保護するため、「1サイクルで同じpaddrを二回以上返却しない」というルールを設ける.
// これは,もし①tmbの中のエントリと②ちょうどavailqから発行されたものの２つが存在するとき、これらの両方に
// 同時にpaddrを返すと,本来の実行順は①=>②なのにも関わらず反対になりうるからである.
//
// TODO: この設計は筋が良くない.本来ならMSHR的に同じリクエストはマージするべきだができていない.
// これだと,近いアドレスが同時に大量に変換命令が出されたとき,pending_bufが埋まって実質的にブロッキングtlbになる.
// とりあえず動けばいいのでこれで行く.リソースも問題なさそうだし.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"
`include "COMMON_FUNCS.svh"
`include "MemoryLayout.svh"

module TLB
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import COMMON_FUNCS::*;
  import MemoryLayout::*;
#(
    parameter int unsigned NUM_OF_WAYS = 1,
    parameter int unsigned NUM_OF_SET  = 256,

    parameter int unsigned NUM_OF_PORT = 1,
    parameter int unsigned NUM_OF_REQ_IN = NUM_OF_PORT,
    parameter int unsigned NUM_OF_RES_OUT = NUM_OF_PORT,
    // REQ_OUTの数とRES_INの数は1で固定.

    // PORT_FOR_ID[i]が1なら,res_out[i]はid_sub=1のためのポート. 
    // PORT_FOR_ID[i]が0なら,res_out[i]はid_sub=0のためのポート.
    parameter logic [NUM_OF_PORT-1:0] RES_PORT_FOR_SUBID = '0,

    // itlbは0,dtlbは1,l2tlbは2.
    parameter int unsigned TLB_ID = 0
) (
    input logic clock,
    input logic reset,

    // L2TLBにとってのL1TLBとのやり取りや,L1TLBにとってのCPUとのやり取り
    input  tlb_req_t req_in [ NUM_OF_REQ_IN],
    output tlb_res_t res_out[NUM_OF_RES_OUT],

    // L2TLBにとってのpwとのやり取りや,L1TLBにとってのL2TLBとのやり取り.
    output tlb_req_t req_out,
    input  tlb_res_t res_in,

    // 次のサイクル立ち上がりでこのモジュールが下位レイヤにreq_outを出さないようにする.
    input logic stall_req_out,

    // 次のサイクルで,このモジュールの上位モジュールが,このレイヤに対してreqを送ってこないようにする.
    output logic stall_req_in,

    input logic flush_tlb

);

  // TLBポート.
  localparam int unsigned NUM_OF_TLB_READ_PORT = NUM_OF_REQ_IN;
  localparam int unsigned NUM_OF_TLB_WRITE_PORT = 1;

  // PENDING_BUF
  // icacheでは,ifqのエントリ以上,
  // TODO: 4より小さくすると無理になる.
  // 各バンクのサイズと,バンク内インデックスの幅.
  localparam int unsigned PB_BANK_SIZE = 4;
  localparam int unsigned PB_IN_BANK_IDX_WIDTH = $clog2(PB_BANK_SIZE);

  // バンクの数とバンクのidxの幅.
  localparam int unsigned NUM_OF_PB_BANK = NUM_OF_REQ_IN;
  localparam int unsigned PB_BANK_IDX_WIDTH = NUM_OF_PB_BANK == 1 ? 1 : $clog2(NUM_OF_PB_BANK);

  // バンクのidxとバンク内のidxを纏めて表したもの.
  // 下$clog2(NUM_OF_REQ_IN)がBANK_IDXを,それに続くPB_IN_BANK_IDX_WIDTH bitがPB_IN_BANK_IDXを表す.
  localparam int unsigned PB_UNIFIED_IDX_WIDTH = PB_IN_BANK_IDX_WIDTH + PB_BANK_IDX_WIDTH;
  // pbを統合した仮想的なpbのサイズ.ただし,$clog2(NUM_OF_REQ_IN)で切り上げてるのでidxに対応しない要素が存在することに注意.
  localparam int unsigned PB_UNIFIED_SIZE = 1 << PB_UNIFIED_IDX_WIDTH;
  localparam int unsigned PB_BANK_IDX_LSB = 0;
  localparam int unsigned PB_BANK_IDX_MSB = PB_BANK_IDX_LSB + PB_BANK_IDX_WIDTH - 1;
  localparam int unsigned PB_IN_BANK_IDX_LSB = PB_BANK_IDX_MSB + 1;
  localparam int unsigned PB_IN_BANK_IDX_MSB = PB_IN_BANK_IDX_LSB + PB_IN_BANK_IDX_WIDTH - 1;

  localparam int unsigned PADDR_MIG_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_MIG_ALIGNED_LSB = PAGE_OFFSET_WIDTH;
  localparam int unsigned PADDR_MIG_ALIGNED_CUT0_WIDTH = PADDR_WIDTH - PAGE_OFFSET_WIDTH;

  // 各種パラメータ.
  localparam int unsigned WAY_IDX_WIDTH = NUM_OF_WAYS == 1 ? 1 : $clog2(NUM_OF_WAYS);


  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SET);
  localparam int unsigned SET_IDX_LSB = PAGE_OFFSET_WIDTH;
  localparam int unsigned SET_IDX_MSB = SET_IDX_LSB + SET_IDX_WIDTH - 1;

  localparam int unsigned TAG_WIDTH = VADDR_WIDTH - SET_IDX_WIDTH - PAGE_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = VADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + PAGE_OFFSET_WIDTH;

  localparam int unsigned UP_WIDTH = PADDR_WIDTH - PAGE_OFFSET_WIDTH;
  localparam int unsigned UP_MSB = PADDR_WIDTH - 1;
  localparam int unsigned UP_LSB = PAGE_OFFSET_WIDTH;


  localparam int unsigned NUM_OF_VADDR_ARBITER_HEADS = 8;
  localparam int unsigned VADDR_ARBITER_GROUP_IDX_WIDTH = $clog2(NUM_OF_VADDR_ARBITER_HEADS);
  // 下3bitは異なっていてもデータ的にかぶっている可能性があるので切り捨てる. 
  localparam int unsigned VADDR_ARBITER_GROUP_IDX_LSB = 3;
  localparam int unsigned VADDR_ARBITER_GROUP_IDX_MSB = VADDR_ARBITER_GROUP_IDX_LSB + VADDR_ARBITER_GROUP_IDX_WIDTH - 1;

  localparam logic [PB_UNIFIED_IDX_WIDTH:0] VADDR_ARBITER_NULL = (PB_UNIFIED_IDX_WIDTH+1)'(PB_UNIFIED_SIZE);


  // ----------------------------------------------------------
  // flush_tlbのための状態
  // ----------------------------------------------------------
  typedef enum logic [1:0] {
    TLB_IDLE,
    TLB_WAITING_FLUSH
  } tlb_state_e;
  tlb_state_e tlb_state;
  tlb_state_e tlb_state_next;

  logic flush_exe;

  int unsigned tlb_generation;

  // -------------------------------------------------------
  // TLB_valid
  // -------------------------------------------------------
  // そのエントリがvalidかはffで保持する.
  logic [NUM_OF_WAYS-1:0][NUM_OF_SET-1:0] tlb_valid;
  logic [NUM_OF_WAYS-1:0][NUM_OF_SET-1:0] tlb_valid_next;

  // -------------------------------------------------------------------------------------------------------
  // tlb_info
  // -------------------------------------------------------------------------------------------------------
  // tagやasidなどのメタ情報
  typedef struct packed {
    logic [TAG_WIDTH-1:0] tag;
    // xv6がasidが0固定でppnでアドレス空間を判別する必要がある？っぽいのでsatpを使う.
    // logic [15:0] asid;
    csr_reg_u satp;
    // pte
    logic pte_a;
    logic pte_d;
  } tlb_info_t;

  logic tlb_info_r_en[NUM_OF_TLB_READ_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_info_r_ram_idx[NUM_OF_TLB_READ_PORT];
  logic [$bits(tlb_info_t)-1:0] tlb_info_r_bit_data[NUM_OF_WAYS][NUM_OF_TLB_READ_PORT];

  logic tlb_info_w_en[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_info_w_ram_idx[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [$bits(tlb_info_t)-1:0] tlb_info_w_bit_data[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];

  // lvtramの入出力はビット列だが,構造体に変換したものの方のほうが扱いやすいので変換する.
  tlb_info_t tlb_info_r_data[NUM_OF_WAYS][NUM_OF_TLB_READ_PORT];
  tlb_info_t tlb_info_w_data[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];


  // lvtramで使用できるように構造体とビット列を変換.
  always_comb begin

    // tlb_info_r_bit_data => tlb_info_r_data
    for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
      for (int unsigned port_idx = 0; port_idx < NUM_OF_TLB_READ_PORT; port_idx++) begin
        tlb_info_r_data[way_idx][port_idx] = tlb_info_t'(tlb_info_r_bit_data[way_idx][port_idx]);
      end
    end

    // tlb_info_w_data => tlb_info_w_bit_data
    for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
      for (int unsigned port_idx = 0; port_idx < NUM_OF_TLB_WRITE_PORT; port_idx++) begin
        tlb_info_w_bit_data[way_idx][port_idx] = tlb_info_w_data[way_idx][port_idx];
      end
    end

  end


  // tlb_infoの本体.
  genvar tlb_info_way_idx;
  generate
    for (tlb_info_way_idx = 0; tlb_info_way_idx < NUM_OF_WAYS; tlb_info_way_idx++) begin
      LVTRAM #(
          .RAM_WIDTH($bits(tlb_info_t)),
          .RAM_DEPTH(NUM_OF_SET),
          .NUM_OF_READ_PORT(NUM_OF_TLB_READ_PORT),
          .NUM_OF_WRITE_PORT(NUM_OF_TLB_WRITE_PORT)
      ) tlb_info (
          .clock(clock),
          .reset(reset),
          .r_en(tlb_info_r_en),
          .r_ram_idx(tlb_info_r_ram_idx),
          .r_data(tlb_info_r_bit_data[tlb_info_way_idx]),
          .w_en(tlb_info_w_en[tlb_info_way_idx]),
          .w_ram_idx(tlb_info_w_ram_idx[tlb_info_way_idx]),
          .w_data(tlb_info_w_bit_data[tlb_info_way_idx])
      );
    end
  endgenerate

  // ----------------------------------------------------------------------------------------------------------------
  // tlb_data
  // ----------------------------------------------------------------------------------------------------------------
  // 変換先のpaddrが入ってるtlbのデータ本体

  logic tlb_data_r_en[NUM_OF_TLB_READ_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_data_r_ram_idx[NUM_OF_TLB_READ_PORT];
  logic [PADDR_MIG_ALIGNED_CUT0_WIDTH-1:0] tlb_data_r_data[NUM_OF_WAYS][NUM_OF_TLB_READ_PORT];

  logic tlb_data_w_en[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_data_w_ram_idx[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [PADDR_MIG_ALIGNED_CUT0_WIDTH-1:0] tlb_data_w_data[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];

  genvar tlb_data_way_idx;
  generate
    for (tlb_data_way_idx = 0; tlb_data_way_idx < NUM_OF_WAYS; tlb_data_way_idx++) begin
      LVTRAM #(
          .RAM_WIDTH(PADDR_MIG_ALIGNED_CUT0_WIDTH),
          .RAM_DEPTH(NUM_OF_SET),
          .NUM_OF_READ_PORT(NUM_OF_TLB_READ_PORT),
          .NUM_OF_WRITE_PORT(NUM_OF_TLB_WRITE_PORT)
      ) tlb_data (
          .clock(clock),
          .reset(reset),
          .r_en(tlb_data_r_en),
          .r_ram_idx(tlb_data_r_ram_idx),
          .r_data(tlb_data_r_data[tlb_data_way_idx]),
          .w_en(tlb_data_w_en[tlb_data_way_idx]),
          .w_ram_idx(tlb_data_w_ram_idx[tlb_data_way_idx]),
          .w_data(tlb_data_w_data[tlb_data_way_idx])
      );
    end
  endgenerate




  // -------------------------------------------------------------
  // PLRU TREE
  // -------------------------------------------------------------
  logic [NUM_OF_WAYS-1:0] plru_tree[NUM_OF_SET];
  logic [NUM_OF_WAYS-1:0] plru_tree_next[NUM_OF_SET];

  // plru_treeをアップデートしたら古いものを探索したりする関数.
  TREE_PLRU_FUNC #(.NUM_OF_WAYS(NUM_OF_WAYS)) plru_util ();

  // ------------------------------------------------------------------------------------------
  // pending_buf
  // ------------------------------------------------------------------------------------------
  // res_inに対してすべてのpending_bufのエントリを調べる必要があるので,FFで実装する.
  // 先頭のNUM_OF_REQ_OUT個がMMにリクエストを送っているが、それに対するres_inが途中のエントリにヒットする
  // 可能性があるので,その際は詰める.
  // typedef enum logic [1:0] {
  //   BEFORE_PADDR_REQUEST,
  //   DURING_PADDR_REQUEST,
  //   PADDR_VALID
  // } pending_buf_state_e;


  // 以下の①~③を統合したもの.新しくreq_inで情報を詰めるときに用いる.
  typedef struct packed {
    // logic valid;
    int unsigned id;
    logic id_sub;
    int unsigned generation;
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
    // pending_buf_state_e state;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_page_fault;
    logic pte_a;
    logic pte_d;
  } pending_buf_t;

  // pending_bufは３つに区分される.
  // ① req_inで書き込み,res_outで読み込む
  // ② req_inで書き込み,req_outで読み込む.
  // ③ res_inで書き込み,res_outで読み込む.
  // ④ id_sub

  typedef struct packed {
    int unsigned id;
    logic id_sub;
    int unsigned generation;
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
    // いきなりtlb本体でhitしたが,順序保持の関係ですぐにres_outできない場合はここにpaddr他を保存する.
    // resin_resoutにこれを保存するとresinのポートと合わせて2writeにする必要があるのでリソースを多く使用するため.
    logic has_paddr;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_page_fault;
    logic pte_a;
    logic pte_d;
  } pending_buf_req_in_res_out_t;

  typedef struct packed {
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
  } pending_buf_req_in_req_out_t;

  typedef struct packed {
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_page_fault;
    logic pte_a;
    logic pte_d;
  } pending_buf_res_in_res_out_t;

  typedef struct packed {
    logic valid;
    logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx;
    logic has_paddr;
    logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] va_grp_idx;
  } pb_entries_t;

  // logic pending_buf_valid[PENDING_BUF_SIZE];
  // pending_buf_t pending_buf[PENDING_BUF_SIZE];

  logic new_pb_entries_valid[NUM_OF_REQ_IN];
  pb_entries_t new_pb_entries_from_tlb_list[NUM_OF_REQ_IN];
  pending_buf_t new_pb_entries[NUM_OF_REQ_IN];


  // --------------------------------------------------------------------------------------------------------------------
  // ① req_inでデータを入れて,res_outで出すpending_buf
  // --------------------------------------------------------------------------------------------------------------------

  (* ram_style = "distributed" *)
  pending_buf_req_in_res_out_t pb_reqin_resout[NUM_OF_REQ_IN][PB_BANK_SIZE];

  // 次のサイクル立ち上がりで,pb_reqin_resoutからどのデータをres_outのために読み込んでres_out1に入れるかを指定する
  typedef struct packed {
    logic valid;
    // logic [PB_BANK_IDX_WIDTH-1:0] bank_idx;
    logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx;
  } data_to_resout_select_t;
  data_to_resout_select_t data_to_resout_select[NUM_OF_RES_OUT];

  logic paddr_valid_rotate[NUM_OF_PB_BANK];


  // res_outで出すためにpb_reqin_resoutから読み込んだデータ.
  logic data_to_res_out_valid[NUM_OF_RES_OUT];
  pending_buf_req_in_res_out_t data_to_res_out1[NUM_OF_RES_OUT];

  // --------------------------------------------------------------------------------------------------------------------
  // ② req_inでデータを入れて,req_outで出すpending_buf
  // --------------------------------------------------------------------------------------------------------------------
  (* ram_style = "distributed" *)
  pending_buf_req_in_req_out_t pb_reqin_reqout[NUM_OF_REQ_IN][PB_BANK_SIZE];

  // 次のサイクル立ち上がりときにpb_reqin_reqoutから読み出すデータのidxをpb_reqin_reqout_issue_idxに,
  // 読み出したデータをpb_reqin_reqout_issueに.
  typedef struct packed {
    logic valid;
    logic [PB_BANK_IDX_WIDTH-1:0] bank_idx;
    logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx;
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
  } data_to_req_out_t;
  data_to_req_out_t data_to_reqout;

  // data_to_reqoutで読み出すのがどこのデータかを指定.
  typedef struct packed {
    logic valid;
    logic [PB_BANK_IDX_WIDTH-1:0] bank_idx;
    logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx;
  } data_to_reqout_select_t;
  // 各バンクに対してreq_outで読み出す位置を指定する.
  data_to_reqout_select_t data_to_reqout_select;


  // --------------------------------------------------------------------------------------------------------------------
  // ③ res_inでデータを入れて,res_outで出すpending_buf
  // --------------------------------------------------------------------------------------------------------------------
  // 
  (* ram_style = "distributed" *)
  pending_buf_res_in_res_out_t pb_resin_resout[NUM_OF_REQ_IN][PB_BANK_SIZE];

  typedef struct packed {
    logic valid;
    logic [PB_BANK_IDX_WIDTH-1:0] bank_idx;
    logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_page_fault;
    logic pte_a;
    logic pte_d;
  } res_in_update_t;
  res_in_update_t resin_update;

  // res_outのデータ.
  pending_buf_res_in_res_out_t data_to_res_out2[NUM_OF_RES_OUT];


  // どのエントリをpbからreq_outするか,res_outするか.
  pb_entries_t res_out_from_pb_list[NUM_OF_RES_OUT];

  // -------------------------------------------------------------------------------------------------------------------
  // ④ id_sub
  // -------------------------------------------------------------------------------------------------------------------
  // どれをresoutするかをalways_comb内で決めるときに参照するのでFFで実装する.
  logic pb_id_sub[NUM_OF_PB_BANK][PB_BANK_SIZE];

  // --------------------------------------------------------------------------------------------------------------------
  // エントリを各種状態ごとにまとめるリスト.
  // --------------------------------------------------------------------------------------------------------------------
  // 以下の循環バッファは満タンかを調べる必要はない.
  // ① pb_free_list[rp]にあるpbのエントリidxに新たなエントリを入れる.同時にpb_bofore_sendにそのエントリを追加する
  // ② pb_before_send_listにあるエントリから選んでreq_outを送る.
  // ③ レスポンスが帰ってきたらpb_paddr_valid_listにそのエントリを追加. 
  // ④ pb_paddr_valid_list[rp]から読んで上位レイヤに返す.

  // 使用していないpbのidxを保管しておくリスト. 
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_list[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_rp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_wp[NUM_OF_REQ_IN];
  // 各循環バッファのエントリ数
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_free[NUM_OF_REQ_IN];

  // req_outを送っていないもののリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_list[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_rp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_wp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_before_send[NUM_OF_REQ_IN];

  // res_inを受取,paddr_validなエントリのリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_list[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_rp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_wp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_paddr_valid[NUM_OF_REQ_IN];


  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_list_tmp[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_rp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_wp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_free_tmp[NUM_OF_REQ_IN];

  // req_outを送っていないもののリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_list_tmp[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_rp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_wp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_before_send_tmp[NUM_OF_REQ_IN];

  // res_inを受取,paddr_validなエントリのリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_list_tmp[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_rp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_wp_tmp[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_paddr_valid_tmp[NUM_OF_REQ_IN];

  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_list_next[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_rp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_free_wp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_free_next[NUM_OF_REQ_IN];

  // req_outを送っていないもののリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_list_next[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_rp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_before_send_wp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_before_send_next[NUM_OF_REQ_IN];

  // res_inを受取,paddr_validなエントリのリスト
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_list_next[NUM_OF_REQ_IN][PB_BANK_SIZE];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_rp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH-1:0] pb_paddr_valid_wp_next[NUM_OF_REQ_IN];
  logic [PB_IN_BANK_IDX_WIDTH:0] noei_pb_paddr_valid_next[NUM_OF_REQ_IN];


  // ---------------------------------------------------
  // pbへの振り分け用に前サイクルのreq_inを持っておく.
  // ---------------------------------------------------
  // 1サイクル前に入ってきたreq_in.
  // この情報とtlb_infoから読み出したタグ情報などを比較する.
  tlb_req_t req_in_prev[NUM_OF_REQ_IN];

  //  -------------------------------------------------------------------------------------
  // 同じアドレスを先に入ったものから返すための情報
  // -------------------------------------------------------------------------------------
  // そもそもなんで1サイクルに2回同じpaddr返すのがだめなんだっけ?
  // キャッシュにおいて,同じアドレスを対象としたldst命令で,先行する命令AがTMBに,あとから来たBがちょうどTLBやキャッシュにリクエストを出したとき,
  // A,Bに同時にpaddrが帰って来るとBが先に処理されてしまう.
  // 以下ではvaddrの下位8byteを表す3bit分を切り捨てた物の,下位4bit(=$clog2(NUM_OF_VADDR_ARBITER_HEADS))の間で順序が保存されるようにする. 
  // 具体的には単連結リストを用いる
  // vaddr_arbiter_heads,あるいはvaddr_arbiter_ele_laterについて,値としてPB_UNIFIED_SIZEが保存されていた場合はそれが末尾を示す.
  // headが末尾であれば先行する同じ下位4bitを持つものは存在しないのでそれはres_outして良いが,末尾でなければ先行するリクエストを先に処理する.

  // 一番最初の要素.なければPB_UNIFIED_SIZE.
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_heads[NUM_OF_VADDR_ARBITER_HEADS];
  // 一番最後の要素.なければPB_UNIFIED_SIZE.
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_tails[NUM_OF_VADDR_ARBITER_HEADS];
  // 時間的に後ろの要素へのポインタを持った単連結リスト.
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_ele_later[PB_UNIFIED_SIZE];

  // 各pending_bufはどのvaddr_arbiter_groupに属するのか
  logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] pb_to_vaddr_arbiter_grp[NUM_OF_PB_BANK][PB_BANK_SIZE];



  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_heads_tmp[NUM_OF_VADDR_ARBITER_HEADS];
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_tails_tmp[NUM_OF_VADDR_ARBITER_HEADS];
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_ele_later_tmp[PB_UNIFIED_SIZE];
  logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] pb_to_vaddr_arbiter_grp_tmp[NUM_OF_PB_BANK][PB_BANK_SIZE];

  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_heads_next[NUM_OF_VADDR_ARBITER_HEADS];
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_tails_next[NUM_OF_VADDR_ARBITER_HEADS];
  logic [PB_UNIFIED_IDX_WIDTH:0] vaddr_arbiter_ele_later_next[PB_UNIFIED_SIZE];
  logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] pb_to_vaddr_arbiter_grp_next[NUM_OF_PB_BANK][PB_BANK_SIZE];

  // --------------------------------------
  // paddr,vaddrのアラインメント用関数.
  // --------------------------------------

  function automatic logic [VADDR_WIDTH-1:0] to_vaddr_page_aligned(
      input logic [VADDR_WIDTH-1:0] vaddr_origin);
    return {vaddr_origin[VADDR_WIDTH-1:PAGE_OFFSET_WIDTH], PAGE_OFFSET_WIDTH'(1'b0)};
  endfunction

  function automatic logic [PADDR_WIDTH-1:0] to_paddr_page_aligned(
      input logic [PADDR_WIDTH-1:0] paddr_origin);
    return {paddr_origin[PADDR_WIDTH-1:PAGE_OFFSET_WIDTH], PAGE_OFFSET_WIDTH'(1'b0)};

  endfunction


  // --------------------------------------------------------------------------------------
  // req_in_prevの分別, res_outの作成.
  // --------------------------------------------------------------------------------------
  // circular回避のためにreq_in_prevからres_outに出力するものをpbに入れるものは分離する必要がある. 
  // しかし,headsなど共有すべき値があるので,このブロックで一回分類を行う.
  always_comb begin
    // コピーの作成
    vaddr_arbiter_heads_tmp      = vaddr_arbiter_heads;
    vaddr_arbiter_tails_tmp      = vaddr_arbiter_tails;
    vaddr_arbiter_ele_later_tmp  = vaddr_arbiter_ele_later;
    pb_to_vaddr_arbiter_grp_tmp  = pb_to_vaddr_arbiter_grp;
    pb_free_list_tmp             = pb_free_list;
    pb_free_rp_tmp               = pb_free_rp;
    pb_free_wp_tmp               = pb_free_wp;
    noei_pb_free_tmp             = noei_pb_free;
    pb_before_send_list_tmp      = pb_before_send_list;
    pb_before_send_rp_tmp        = pb_before_send_rp;
    pb_before_send_wp_tmp        = pb_before_send_wp;
    noei_pb_before_send_tmp      = noei_pb_before_send;
    pb_paddr_valid_list_tmp      = pb_paddr_valid_list;
    pb_paddr_valid_rp_tmp        = pb_paddr_valid_rp;
    pb_paddr_valid_wp_tmp        = pb_paddr_valid_wp;
    noei_pb_paddr_valid_tmp      = noei_pb_paddr_valid;


    res_out                      = '{default: 0};
    new_pb_entries_from_tlb_list = '{default: 0};
    new_pb_entries               = '{default: 0};



    for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
      // ヒットするwayが存在するか,及びその際のデータ.
      automatic logic way_hit = 0;
      automatic logic [PADDR_WIDTH-1:0] hit_paddr = 0;
      automatic logic hit_pte_a = 0;
      automatic logic hit_pte_d = 0;

      // vaddr_arbiterで同じグループに先行する命令が存在するか.
      automatic logic does_preceed_exist = 0;

      // pbに入れたか. 
      automatic logic added_to_pb = 0;

      automatic
      logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0]
      vaddr_arbiter_grp_idx = req_in_prev[i].vaddr[VADDR_ARBITER_GROUP_IDX_MSB:VADDR_ARBITER_GROUP_IDX_LSB];
      automatic
      logic [PB_IN_BANK_IDX_WIDTH-1:0]
      in_bank_idx = pb_free_list_tmp[i][pb_free_rp_tmp[i]];


      if (req_in_prev[i].valid) begin

        // hitするwayが存在するかを確認する.
        // TODO: asidだけの照合でも動いたので後で改変.
        for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
          if(tlb_valid[way_idx][req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] && 
             req_in_prev[i].satp == tlb_info_r_data[way_idx][i].satp && 
             req_in_prev[i].vaddr[TAG_MSB:TAG_LSB] == tlb_info_r_data[way_idx][i].tag)begin
            // hit
            way_hit   = 1;
            hit_paddr = {tlb_data_r_data[way_idx][i], req_in_prev[i].vaddr[PAGE_OFFSET_WIDTH-1:0]};
            hit_pte_a = tlb_info_r_data[way_idx][i].pte_a;
            hit_pte_d = tlb_info_r_data[way_idx][i].pte_d;
          end
        end

        // vaddr_arbiterで先行する命令が見つかるか.
        does_preceed_exist = vaddr_arbiter_heads_tmp[req_in_prev[i].vaddr[VADDR_ARBITER_GROUP_IDX_MSB:VADDR_ARBITER_GROUP_IDX_LSB]] 
                                  != VADDR_ARBITER_NULL;


        // way_hit && !does_preceed_existの場合は,後ろのalways_combで処理を行う.(ciculartを避けるため)
        if (way_hit && !does_preceed_exist) begin
          res_out[i] = '{
              valid: 1,
              id: req_in_prev[i].id,
              id_sub: req_in_prev[i].id_sub,
              generation: req_in_prev[i].generation,
              vaddr: req_in_prev[i].vaddr,
              paddr: hit_paddr,
              satp: req_in_prev[i].satp,
              pma_type: get_pma_type(hit_paddr),
              is_page_fault: 0,  // tlbに保存されてる == page_faultでない.
              pte_a: hit_pte_a,
              pte_d: hit_pte_d
          };
        end else if (way_hit && does_preceed_exist) begin
          // hitするが,先行する命令に同じvaddrグループのものが存在する場合,pbに入れる.
          new_pb_entries_from_tlb_list[i] = '{
              valid: 1,
              in_bank_idx: in_bank_idx,
              has_paddr: 1,
              va_grp_idx:
              req_in_prev[
              i
              ].vaddr[
              VADDR_ARBITER_GROUP_IDX_MSB
              :
              VADDR_ARBITER_GROUP_IDX_LSB
              ]
          };
          new_pb_entries[i] = '{
              id: req_in_prev[i].id,
              id_sub: req_in_prev[i].id_sub,
              generation: req_in_prev[i].generation,
              satp: req_in_prev[i].satp,
              vaddr: req_in_prev[i].vaddr,
              paddr: hit_paddr,
              is_page_fault: 0,
              pte_a: hit_pte_a,
              pte_d: hit_pte_d
          };
          // この際,いきなりpb_vaddr_validに入れる必要がある.
          // free_listの先頭を使用する.
          pb_free_rp_tmp[i] = pb_free_rp_tmp[i] + PB_IN_BANK_IDX_WIDTH'(1);
          noei_pb_free_tmp[i] = noei_pb_free_tmp[i] - (PB_IN_BANK_IDX_WIDTH + 1)'(1);
          // paddr_valid_listの末尾に追加する.
          pb_paddr_valid_list_tmp[i][pb_paddr_valid_wp_tmp[i]] = in_bank_idx;
          pb_paddr_valid_wp_tmp[i] = PB_IN_BANK_IDX_WIDTH'(pb_paddr_valid_wp_tmp[i] + PB_IN_BANK_IDX_WIDTH'(1));
          noei_pb_paddr_valid_tmp[i] = noei_pb_paddr_valid_tmp[i] + (PB_IN_BANK_IDX_WIDTH + 1)'(1);
          added_to_pb = 1;
        end else if (!way_hit) begin
          // miss時にはpending_bufに入れる.
          new_pb_entries_from_tlb_list[i] = '{
              valid: 1,
              in_bank_idx: in_bank_idx,
              has_paddr: 0,
              va_grp_idx:
              req_in_prev[
              i
              ].vaddr[
              VADDR_ARBITER_GROUP_IDX_MSB
              :
              VADDR_ARBITER_GROUP_IDX_LSB
              ]
          };
          new_pb_entries[i] = '{
              id: req_in_prev[i].id,
              id_sub: req_in_prev[i].id_sub,
              generation: req_in_prev[i].generation,
              satp: req_in_prev[i].satp,
              vaddr: req_in_prev[i].vaddr,
              paddr: 0,
              is_page_fault: 0,
              pte_a: 0,
              pte_d: 0
          };
          // freelistから先頭の要素を読み出す
          pb_free_rp_tmp[i] = pb_free_rp_tmp[i] + PB_IN_BANK_IDX_WIDTH'(1);
          noei_pb_free_tmp[i] = noei_pb_free_tmp[i] - (PB_IN_BANK_IDX_WIDTH + 1)'(1);
          // before_send_listの末尾に追加する.
          pb_before_send_list_tmp[i][pb_before_send_wp_tmp[i]] = in_bank_idx;
          pb_before_send_wp_tmp[i] = pb_before_send_wp_tmp[i] + PB_IN_BANK_IDX_WIDTH'(1);
          noei_pb_before_send_tmp[i] = noei_pb_before_send_tmp[i] + (PB_IN_BANK_IDX_WIDTH + 1)'(1);
          added_to_pb = 1;
        end

        // pbに追加された場合,vaddr_arbiterへの追加処理を行う.
        if (added_to_pb) begin
          // PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_tails[vaddr_arbiter_grp_idx])でキャストする必要があるのは末尾を表すのは
          // PB_UNIFIED_SIZEという値であるから.

          // 末尾の要素が存在するならその要素が新しく入れる要素を指すようにする.
          if (vaddr_arbiter_tails_tmp[vaddr_arbiter_grp_idx] != VADDR_ARBITER_NULL) begin
            vaddr_arbiter_ele_later_tmp[PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_tails_tmp[vaddr_arbiter_grp_idx])] = {
              1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
            };
          end
          // 末尾の要素を新しく入るものに.
          vaddr_arbiter_tails_tmp[vaddr_arbiter_grp_idx] = {
            1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
          };
          // 先頭の要素が存在しないなら新しく入れる要素を指すようにする.
          if (vaddr_arbiter_heads_tmp[vaddr_arbiter_grp_idx] == VADDR_ARBITER_NULL) begin
            vaddr_arbiter_heads_tmp[vaddr_arbiter_grp_idx] = {
              1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
            };
          end
          // 新しく追加する要素が末尾を指すように. 
          vaddr_arbiter_ele_later_tmp[{in_bank_idx, PB_BANK_IDX_WIDTH'(i)}] = VADDR_ARBITER_NULL;
          // pbのidx => vaddr_arbiter_grp_idx の変換表の作成. 
          pb_to_vaddr_arbiter_grp_tmp[i][in_bank_idx] = vaddr_arbiter_grp_idx;
        end

      end
    end


    // -------------------------------------------------------------------------------------
    // data_to_res_out => res_out
    // --------------------------------------------------------------------------------------
    // data_to_res_outをres_outにマージする.
    // ここで,data_to_res_outでres_outを上書きしているように見えるが,実際はreq_in_prev[i]がinvalidのところ,
    // つまり空いているところに詰めているだけなので大丈夫.
    for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
      if (data_to_res_out_valid[i] && !req_in_prev[i].valid) begin
        // 順序の関係でtlbでヒットしたあとにも関わらずすぐにres_outできなかった場合,
        // paddrの内容はdata_to_res_out1の方に保存されている.
        if (data_to_res_out1[i].has_paddr) begin
          res_out[i] = '{
              valid: 1,
              id: data_to_res_out1[i].id,
              id_sub: data_to_res_out1[i].id_sub,
              generation: data_to_res_out1[i].generation,
              paddr: data_to_res_out1[i].paddr,
              vaddr: data_to_res_out1[i].vaddr,
              satp: data_to_res_out1[i].satp,
              pma_type: get_pma_type(data_to_res_out1[i].paddr),
              is_page_fault: data_to_res_out1[i].is_page_fault,
              pte_a: data_to_res_out1[i].pte_a,
              pte_d: data_to_res_out1[i].pte_d
          };
        end else begin
          // resinで得た情報を返す場合.
          res_out[i] = '{
              valid: 1,
              id: data_to_res_out1[i].id,
              id_sub: data_to_res_out1[i].id_sub,
              generation: data_to_res_out1[i].generation,
              paddr: {
                data_to_res_out2[i].paddr[PADDR_WIDTH-1:12], data_to_res_out1[i].vaddr[11:0]
              },
              vaddr: data_to_res_out1[i].vaddr,
              satp: data_to_res_out1[i].satp,
              pma_type: get_pma_type(data_to_res_out2[i].paddr),
              is_page_fault: data_to_res_out2[i].is_page_fault,
              pte_a: data_to_res_out2[i].pte_a,
              pte_d: data_to_res_out2[i].pte_d
          };
        end
      end
    end


  end

  int unsigned reqout_rr_counter;
  int unsigned reqout_rr_counter_next;


  // ------------------------------------------------------------------------
  // tlb_info, tlb_data, => penging_buf
  // tlb_info, tlb_data, data_to_res_out => res_out
  // -------------------------------------------------------------------------
  always_comb begin

    automatic int unsigned res_out_counter = 0;

    plru_tree_next = plru_tree;
    // new_pb_entries_from_tlb_list = '{default: 0};
    // new_pb_entries = '{default: 0};


    // free_list
    pb_free_list_next = pb_free_list_tmp;
    pb_free_rp_next = pb_free_rp_tmp;
    pb_free_wp_next = pb_free_wp_tmp;
    noei_pb_free_next = noei_pb_free_tmp;

    // before_send_lit
    pb_before_send_list_next = pb_before_send_list_tmp;
    pb_before_send_rp_next = pb_before_send_rp_tmp;
    pb_before_send_wp_next = pb_before_send_wp_tmp;
    noei_pb_before_send_next = noei_pb_before_send_tmp;

    // paddr_valid_list
    pb_paddr_valid_list_next = pb_paddr_valid_list_tmp;
    pb_paddr_valid_rp_next = pb_paddr_valid_rp_tmp;
    pb_paddr_valid_wp_next = pb_paddr_valid_wp_tmp;
    noei_pb_paddr_valid_next = noei_pb_paddr_valid_tmp;

    // vaddr_arbiter
    vaddr_arbiter_heads_next = vaddr_arbiter_heads_tmp;
    vaddr_arbiter_tails_next = vaddr_arbiter_tails_tmp;
    vaddr_arbiter_ele_later_next = vaddr_arbiter_ele_later_tmp;
    pb_to_vaddr_arbiter_grp_next = pb_to_vaddr_arbiter_grp_tmp;

    // -------------------------------------------------------------------------------------
    // tlb_info, tlb_data => pending_buf, res_out
    // --------------------------------------------------------------------------------------
    // for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
    //   // TODO: 現在の仕様だと、同一サイクルに同じアドレスのリクエストが来たとき,つまりreq_in[i]とreq_in[j]で同じアドレスの場合
    //   // 同じアドレスの複数返却を防げていないのでどうにかする.
    //   // ヒットするwayが存在するか,及びその際のデータ.
    //   logic way_hit = 0;
    //   logic [PADDR_WIDTH-1:0] hit_paddr = 0;
    //   logic hit_pte_a = 0;
    //   logic hit_pte_d = 0;

    //   // vaddr_arbiterで同じグループに先行する命令が存在するか.
    //   logic does_preceed_exist = 0;

    //   // pbに入れたか. 
    //   logic added_to_pb = 0;

    //   logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] vaddr_arbiter_grp_idx = 0;
    //   logic [PB_IN_BANK_IDX_WIDTH-1:0] in_bank_idx = pb_free_list_next[i][pb_free_rp_next[i]];



    //   if (req_in_prev[i].valid) begin

    //     // hitするwayが存在するかを確認する.
    //     // TODO: asidだけの照合でも動いたので後で改変.
    //     for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
    //       if(tlb_valid[way_idx][req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] && 
    //          req_in_prev[i].satp == tlb_info_r_data[way_idx][i].satp && 
    //          req_in_prev[i].vaddr[TAG_MSB:TAG_LSB] == tlb_info_r_data[way_idx][i].tag)begin
    //         // hit
    //         way_hit = 1;
    //         hit_paddr = {tlb_data_r_data[way_idx][i], req_in_prev[i].vaddr[PAGE_OFFSET_WIDTH-1:0]};
    //         hit_pte_a = tlb_info_r_data[way_idx][i].pte_a;
    //         hit_pte_d = tlb_info_r_data[way_idx][i].pte_d;
    //         // plruの更新
    //         plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] = plru_util.update_plru_tree(
    //             plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]],
    //                 WAY_IDX_WIDTH'(way_idx));
    //       end
    //     end

    //     // vaddr_arbiterで先行する命令が見つかるか.
    //     does_preceed_exist = vaddr_arbiter_heads_next[req_in_prev[i].vaddr[VADDR_ARBITER_GROUP_IDX_MSB:VADDR_ARBITER_GROUP_IDX_LSB]] 
    //                               != (PB_UNIFIED_IDX_WIDTH+1)'(PB_UNIFIED_SIZE);


    //     // way_hit && !does_preceed_existの場合は,後ろのalways_combで処理を行う.(ciculartを避けるため)
    //     if (way_hit && does_preceed_exist) begin
    //       // hitするが,先行する命令に同じvaddrグループのものが存在する場合,pbに入れる.
    //       // この際,いきなりpb_vaddr_validに入れる必要がある.
    //       new_pb_entries_from_tlb_list[i] = '{
    //           valid: 1,
    //           in_bank_idx: in_bank_idx,
    //           has_paddr: 1,
    //           va_grp_idx:
    //           req_in_prev[
    //           i
    //           ].vaddr[
    //           VADDR_ARBITER_GROUP_IDX_MSB
    //           :
    //           VADDR_ARBITER_GROUP_IDX_LSB
    //           ]
    //       };
    //       new_pb_entries[i] = '{
    //           id: req_in_prev[i].id,
    //           id_sub: req_in_prev[i].id_sub,
    //           generation: req_in_prev[i].generation,
    //           satp: req_in_prev[i].satp,
    //           vaddr: req_in_prev[i].vaddr,
    //           paddr: hit_paddr,
    //           is_page_fault: 0,
    //           pte_a: hit_pte_a,
    //           pte_d: hit_pte_d
    //       };
    //       // free_listの先頭を使用する.
    //       pb_free_rp_next[i] = PB_IN_BANK_IDX_WIDTH'(pb_free_rp_next[i] + 1);
    //       noei_pb_free_next[i] = (PB_IN_BANK_IDX_WIDTH + 1)'(noei_pb_free_next[i] - 1);
    //       // paddr_valid_listの末尾に追加する.
    //       pb_paddr_valid_list_next[i][pb_paddr_valid_wp_next[i]] = in_bank_idx;
    //       pb_paddr_valid_wp_next[i] = PB_IN_BANK_IDX_WIDTH'(pb_paddr_valid_wp_next[i] + PB_IN_BANK_IDX_WIDTH'(1));
    //       noei_pb_paddr_valid_next[i] = (PB_IN_BANK_IDX_WIDTH + 1)'(noei_pb_paddr_valid_next[i] + 1);
    //       added_to_pb = 1;
    //     end else if (!way_hit) begin
    //       // miss時にはpending_bufに入れる.
    //       new_pb_entries_from_tlb_list[i] = '{
    //           valid: 1,
    //           in_bank_idx: in_bank_idx,
    //           has_paddr: 0,
    //           va_grp_idx:
    //           req_in_prev[
    //           i
    //           ].vaddr[
    //           VADDR_ARBITER_GROUP_IDX_MSB
    //           :
    //           VADDR_ARBITER_GROUP_IDX_LSB
    //           ]
    //       };
    //       new_pb_entries[i] = '{
    //           id: req_in_prev[i].id,
    //           id_sub: req_in_prev[i].id_sub,
    //           generation: req_in_prev[i].generation,
    //           satp: req_in_prev[i].satp,
    //           vaddr: req_in_prev[i].vaddr,
    //           paddr: 0,
    //           is_page_fault: 0,
    //           pte_a: 0,
    //           pte_d: 0
    //       };
    //       // freelistから先頭の要素を読み出す
    //       pb_free_rp_next[i] = PB_IN_BANK_IDX_WIDTH'(pb_free_rp_next[i] + 1);
    //       noei_pb_free_next[i] = (PB_IN_BANK_IDX_WIDTH + 1)'(noei_pb_free_next[i] - 1);
    //       // before_send_listの末尾に追加する.
    //       pb_before_send_list_next[i][pb_before_send_wp_next[i]] = in_bank_idx;
    //       pb_before_send_wp_next[i] = PB_IN_BANK_IDX_WIDTH'(pb_before_send_wp_next[i] + 1);
    //       noei_pb_before_send_next[i] = (PB_IN_BANK_IDX_WIDTH + 1)'(noei_pb_before_send_next[i] + 1);
    //       added_to_pb = 1;
    //     end

    //     // pbに追加された場合,vaddr_arbiterへの追加処理を行う.
    //     if (added_to_pb) begin
    //       // vaddr_arbiterに追加
    //       vaddr_arbiter_grp_idx = req_in_prev[i].vaddr[VADDR_ARBITER_GROUP_IDX_MSB:VADDR_ARBITER_GROUP_IDX_LSB];
    //       // PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_tails[vaddr_arbiter_grp_idx])でキャストする必要があるのは末尾を表すのは
    //       // PB_UNIFIED_SIZEという値であるから.

    //       // 末尾の要素が存在するならその要素が新しく入れる要素を指すようにする.
    //       if (vaddr_arbiter_tails_next[vaddr_arbiter_grp_idx] != VADDR_ARBITER_NULL) begin
    //         vaddr_arbiter_ele_later_next[PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_tails_next[vaddr_arbiter_grp_idx])] = {
    //           1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
    //         };
    //       end
    //       // 末尾の要素を新しく入るものに.
    //       vaddr_arbiter_tails_next[vaddr_arbiter_grp_idx] = {
    //         1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
    //       };
    //       // 先頭の要素が存在しないなら新しく入れる要素を指すようにする.
    //       if (vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx] == VADDR_ARBITER_NULL) begin
    //         vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx] = {
    //           1'b0, in_bank_idx, PB_BANK_IDX_WIDTH'(i)
    //         };
    //       end
    //       // 新しく追加する要素が末尾を指すように. 
    //       vaddr_arbiter_ele_later_next[{in_bank_idx, PB_BANK_IDX_WIDTH'(i)}] = VADDR_ARBITER_NULL;
    //       // pbのidx => vaddr_arbiter_grp_idx の変換表の作成. 
    //       pb_to_vaddr_arbiter_grp_next[i][in_bank_idx] = vaddr_arbiter_grp_idx;
    //     end

    //   end
    // end

    // -----------------------------------------------------------------------------
    // res_inでtlb更新.
    // -----------------------------------------------------------------------------
    begin
      // 初期化
      tlb_valid_next = tlb_valid;
      for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
        // tlb_data
        tlb_data_w_en[way_idx][0] = 0;
        tlb_data_w_ram_idx[way_idx][0] = 0;
        tlb_data_w_data[way_idx][0] = 0;
        // tlb_info
        tlb_info_w_en[way_idx][0] = 0;
        tlb_info_w_ram_idx[way_idx][0] = 0;
        tlb_info_w_data[way_idx][0] = 0;
      end

      begin
        automatic logic [WAY_IDX_WIDTH-1:0] oldest_way_idx = 0;
        automatic logic [SET_IDX_WIDTH-1:0] res_set_idx = 0;

        // for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
        // page_faultならtlb本体は更新しない.
        if (res_in.valid && res_in.generation == tlb_generation && !res_in.is_page_fault && get_pma_type(
                res_in.paddr
            ) == PMA_MEMORY) begin
          res_set_idx = res_in.vaddr[SET_IDX_MSB:SET_IDX_LSB];
          // 最も昔に使われたwayの検索とplru_treeの更新
          // TODO: 本当はこっちでもplrutreeの更新が必要だが一時的にコメントアウトする.
          // oldest_way_idx = plru_util.search_oldest(plru_tree_next[res_set_idx]);
          // plru_tree_next[res_set_idx] =
          //     plru_util.update_plru_tree(plru_tree_next[res_set_idx], oldest_way_idx);
          // tlb_dataへの書き込み
          tlb_data_w_en[oldest_way_idx][0] = 1'b1;
          tlb_data_w_ram_idx[oldest_way_idx][0] = res_set_idx;
          tlb_data_w_data[oldest_way_idx][0] = res_in.paddr[PADDR_MIG_ALIGNED_MSB:PADDR_MIG_ALIGNED_LSB];
          // tlb_infoへの書き込み.
          tlb_info_w_en[oldest_way_idx][0] = 1'b1;
          tlb_info_w_ram_idx[oldest_way_idx][0] = res_set_idx;
          tlb_info_w_data[oldest_way_idx][0] = '{
              tag: res_in.vaddr[TAG_MSB:TAG_LSB],
              satp: res_in.satp,
              pte_a: res_in.pte_a,
              pte_d: res_in.pte_d
          };
          //
          tlb_valid_next[oldest_way_idx][res_set_idx] = 1'b1;
        end
      end
    end


    // -----------------------------------------------------------------------------------------------------------------
    // pb_reqin_reqout から出すreq_outをどれにするか選ぶ.
    // -----------------------------------------------------------------------------------------------------------------
    // pb_reqin_resoutのどれを読み出すかを決定し,data_to_reqout_selectに保存.
    // 実際にはalways_ffで読み出しを行う.
    begin
      automatic int unsigned req_out_counter = 0;
      data_to_reqout_select  = '{default: 0};
      reqout_rr_counter_next = reqout_rr_counter;

      // TODO: 今の実装だと前の方のバンクから集中して取ることになるので後でラウンドロビンにする.
      if (!stall_req_out) begin
        for (int unsigned bank_idx = 0; bank_idx < NUM_OF_PB_BANK; bank_idx++) begin
          if (noei_pb_before_send[bank_idx] != 0) begin
            data_to_reqout_select = '{
                valid: 1,
                bank_idx: PB_BANK_IDX_WIDTH'(bank_idx),
                in_bank_idx: pb_before_send_list_next[bank_idx][pb_before_send_rp[bank_idx]]
            };

            // before_send_listから読み出し
            pb_before_send_rp_next[bank_idx] = pb_before_send_rp_next[bank_idx] + PB_IN_BANK_IDX_WIDTH'(1);
            noei_pb_before_send_next[bank_idx] = noei_pb_before_send_next[bank_idx]-(PB_IN_BANK_IDX_WIDTH+1)'(1);

            reqout_rr_counter_next++;

            // 1つしかreq_outしないのでbreak
            break;
          end
        end
      end
    end


    // ----------------------------------------------------------------------------------------------------------------
    // res_inで pending_bufの更新
    // ----------------------------------------------------------------------------------------------------------------
    // resin_updateの作成.実際の更新はalways_ffで行う.
    begin
      automatic logic [PB_BANK_IDX_WIDTH-1:0] bank_idx = res_in.id[PB_BANK_IDX_MSB:PB_BANK_IDX_LSB];
      resin_update = '{default: 0};
      if (res_in.valid && res_in.generation == tlb_generation) begin
        resin_update = '{
            valid: 1,
            bank_idx: bank_idx,
            in_bank_idx: res_in.id[PB_IN_BANK_IDX_MSB:PB_IN_BANK_IDX_LSB],
            paddr: res_in.paddr,
            is_page_fault: res_in.is_page_fault,
            pte_a: res_in.pte_a,
            pte_d: res_in.pte_d
        };
        // paddr_valid
        pb_paddr_valid_list_next[bank_idx][pb_paddr_valid_wp_next[bank_idx]] = res_in.id[PB_IN_BANK_IDX_MSB:PB_IN_BANK_IDX_LSB];
        pb_paddr_valid_wp_next[bank_idx] = pb_paddr_valid_wp_next[bank_idx] + PB_IN_BANK_IDX_WIDTH'(1);
        noei_pb_paddr_valid_next[bank_idx] = noei_pb_paddr_valid_next[bank_idx]+(PB_IN_BANK_IDX_WIDTH+1)'(1);
      end
    end


    // -----------------------------------------------------------------------------------------------------------------
    // 次のサイクル立ち上がりでpbから出すres_outを決めるためにdata_to_resout_selectを決める.
    // -----------------------------------------------------------------------------------------------------------------
    data_to_resout_select = '{default: 0};
    paddr_valid_rotate = '{default: 0};

    // そもそもなんで1サイクルに2回同じpaddr返すのがだめなんだっけ?
    // 同じアドレスを対象としたldst命令で,先行する命令AがTMBに,あとから来たBがちょうどTLBやキャッシュにリクエストを出したとき,
    // A,Bに同時にpaddrが帰って来るとBが先に処理されてしまう.
    for (int unsigned bank_idx = 0; bank_idx < NUM_OF_RES_OUT; bank_idx++) begin

      // vaddr_arbiterで先頭にあるかを確かめる.
      automatic
      logic [PB_UNIFIED_IDX_WIDTH-1:0]
      pb_unified_idx = {
        pb_paddr_valid_list[bank_idx][pb_paddr_valid_rp[bank_idx]], PB_BANK_IDX_WIDTH'(bank_idx)
      };
      automatic
      logic [PB_IN_BANK_IDX_WIDTH-1:0]
      in_bank_idx = pb_unified_idx[PB_IN_BANK_IDX_MSB:PB_IN_BANK_IDX_LSB];
      automatic
      logic
      is_head = vaddr_arbiter_heads[pb_to_vaddr_arbiter_grp[bank_idx][in_bank_idx]] == {1'b0,pb_unified_idx};
      automatic
      logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0]
      vaddr_arbiter_grp_idx = pb_to_vaddr_arbiter_grp[bank_idx][in_bank_idx];
      automatic
      logic [PB_UNIFIED_IDX_WIDTH:0]
      vaddr_arbiter_head = vaddr_arbiter_heads[vaddr_arbiter_grp_idx];

      // pb_paddr_validにres_out可能なエントリが存在し,かつそれがvaddr_arbiterで先頭の場合はres_outすることができる.
      // if (!req_in[bank_idx].valid && noei_pb_paddr_valid[bank_idx] != 0) begin
      if (!req_in[bank_idx].valid && noei_pb_paddr_valid[bank_idx] != 0  && RES_PORT_FOR_SUBID[bank_idx] == pb_id_sub[bank_idx][in_bank_idx]) begin
        if (is_head) begin
          // すべての条件を満たすならres_outで出力.
          data_to_resout_select[bank_idx] = '{valid: 1, in_bank_idx: in_bank_idx};

          // paddr_valid_listから読み込出す.
          pb_paddr_valid_rp_next[bank_idx] = pb_paddr_valid_rp_next[bank_idx] + PB_IN_BANK_IDX_WIDTH'(1);
          noei_pb_paddr_valid_next[bank_idx] =noei_pb_paddr_valid_next[bank_idx]- (PB_IN_BANK_IDX_WIDTH+1)'(1);

          // freelistに戻す. 
          pb_free_list_next[bank_idx][pb_free_wp_next[bank_idx]] = in_bank_idx;
          pb_free_wp_next[bank_idx] = PB_IN_BANK_IDX_WIDTH'(pb_free_wp_next[bank_idx] + PB_IN_BANK_IDX_WIDTH'(1));
          noei_pb_free_next[bank_idx] = noei_pb_free_next[bank_idx] + (PB_IN_BANK_IDX_WIDTH + 1)'(1);

          // vaddr_arbiterから削除.
          // ここでvaddr_arbiter_headがnullになる心配はない.最低でも今からresoutするエントリがあるから普通にnullの分切り捨てていい.

          // この要素が末尾の要素の場合,tail=NULLにする必要がある.
          if (vaddr_arbiter_ele_later_next[PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx])] == VADDR_ARBITER_NULL) begin
            vaddr_arbiter_tails_next[vaddr_arbiter_grp_idx] = VADDR_ARBITER_NULL;
          end

          // headsを付け替える.
          if (vaddr_arbiter_ele_later_next[PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx])] != VADDR_ARBITER_NULL) begin
            // vaddr_arbiter_headsがこの要素の次の要素を指すように付け替える.
            vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx] = vaddr_arbiter_ele_later_next[PB_UNIFIED_IDX_WIDTH'(vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx])];
          end else begin
            // この要素の次の要素が無いので,NULLを指すようにする.
            vaddr_arbiter_heads_next[vaddr_arbiter_grp_idx] = VADDR_ARBITER_NULL;
          end

        end else begin
          // 他の条件は満たしているが,is_headでない場合,そのエントリ(paddr_validの一番先頭)をpaddr_validの一番後ろに持ってくる. 
          paddr_valid_rotate[bank_idx] = 1;
          // rotate
          pb_paddr_valid_list_next[bank_idx][pb_paddr_valid_wp_next[bank_idx]] = pb_paddr_valid_list_next[bank_idx][pb_paddr_valid_rp_next[bank_idx]];
          pb_paddr_valid_rp_next[bank_idx] =pb_paddr_valid_rp_next[bank_idx] + PB_IN_BANK_IDX_WIDTH'(1);
          pb_paddr_valid_wp_next[bank_idx] = pb_paddr_valid_wp_next[bank_idx] +PB_IN_BANK_IDX_WIDTH'(1);

        end
      end
    end



    // ----------------------------------------------------------------------
    // flushによる状態更新(SFENCE_VMA)
    // ----------------------------------------------------------------------
    begin
      automatic logic all_pb_empty = 1;
      tlb_state_next = tlb_state;
      flush_exe = 0;

      // すべて空かを確認
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        if (noei_pb_free[i] != (PB_IN_BANK_IDX_WIDTH + 1)'(PB_BANK_SIZE)) begin
          all_pb_empty = 0;
        end
      end

      // num_of_entries_in_pb_nextを使うとcircular
      if (tlb_state == TLB_WAITING_FLUSH && all_pb_empty) begin
        // flush_exe == 1で、次のサイクル立ち上がり時にtlb_validをflush
        flush_exe = 1;
        tlb_state_next = TLB_IDLE;
      end

      // TLB_WAITING_FLUSH => TLB_IDLEの更新は,TLB_IDLE => TLB_WAITING_FLUSHのあとに置くこと.
      // 前に置くと, TLB_IDLE => TLB_WAITING_FLUSH => TLB_IDLEが1度におこって、req_inがpbに反映される前に
      // TLB_WAITING_FLUSH => TLB_IDLE の判定が行われる.
      // TLB_WAITING_FLUSH => TLB_IDLE の判定にreq_inを含めればいいじゃないかとおもうかもしれないが、それだとcircularになる.
      if (flush_tlb && tlb_state == TLB_IDLE) begin
        tlb_state_next = TLB_WAITING_FLUSH;
      end

    end


  end

  always_comb begin
    // -----------------------------------------------------------------------
    // stall_out
    // -----------------------------------------------------------------------
    begin
      // freeなpbが2未満のbankが存在した場合,stallする. 
      // circularにならないように,noei_pb_free[i]を用いているが,最悪の場合を考えると,
      // req_prevがvalid,reqがvalidで2つ使用するので,3つ目（次のサイクルで来るreq_in）もvalidで,pb_freeから1つも出ていかないと仮定できる.
      // 3つ目をキャンセルする条件は,3つ以上の空きがないこと.
      automatic logic no_room = 0;
      for (int unsigned i = 0; i < NUM_OF_PORT; i++) begin
        if (noei_pb_free[i] < 3) begin
          no_room = 1;
        end
      end
      // TODO: これtlb_stateで判定する必要ある？
      // なんでとめるんだっけ.
      stall_req_in = (tlb_state == TLB_WAITING_FLUSH) || flush_tlb || no_room;
      // stall_req_in = no_room;

      // if (stall_req_in) begin
      //   $display("[LOG][%0t | %0.3f] stall_req_in", $time, $realtime);
      // end else begin
      //   $display("[LOG][%0t | %0.3f] not_stall_req_in", $time, $realtime);
      // end
    end

  end

  // --------------------------------------------------------------------------
  // req_outの出力
  // --------------------------------------------------------------------------
  always_comb begin

    // data_to_reqout(pb_reqin_reqoutから読み出したデータ)からreq_outを作成.
    req_out = '{default: 0};
    if (data_to_reqout.valid) begin
      req_out = '{
          valid: 1,
          id: {
            {(32 - PB_IN_BANK_IDX_WIDTH - PB_BANK_IDX_WIDTH) {1'b0}},
            data_to_reqout.in_bank_idx,
            data_to_reqout.bank_idx
          },
          id_sub: 0,
          generation: tlb_generation,
          satp: data_to_reqout.satp,
          vaddr: data_to_reqout.vaddr
      };
    end
  end

  // --------------------------------------------------------------------------
  // req_in => tlb_data,tlb_info
  // ---------------------------------------------------------------------------
  // cicular回避のために分離.
  always_comb begin

    // req_in
    // => tlb_data_r_en, tlb_data_r_ram_idx,
    //    tlb_info_r_en, tlb_info_r_ram_idx
    // 次のサイクルでの出力をstallがかかったときはなくす必要がある.
    begin
      // 初期化
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        // tlb_data
        tlb_data_r_en[i] = 0;
        tlb_data_r_ram_idx[i] = 0;
        // tlb_info
        tlb_info_r_en[i] = 0;
        tlb_info_r_ram_idx[i] = 0;
      end

      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        // tlb_info
        tlb_info_r_en[i] = 1;
        tlb_info_r_ram_idx[i] = req_in[i].vaddr[SET_IDX_MSB:SET_IDX_LSB];
        // tlb_data
        tlb_data_r_en[i] = 1;
        tlb_data_r_ram_idx[i] = req_in[i].vaddr[SET_IDX_MSB:SET_IDX_LSB];
      end

    end
  end

  // ------------------------------------------------------------------------------------------------------------
  // res_outの作成
  // ------------------------------------------------------------------------------------------------------------
  // ciculart回避のために分離.
  // always_comb begin
  //   res_out = '{default: 0};

  //   // -------------------------------------------------------------------------------------
  //   // tlb_info, tlb_data => pending_buf, res_out
  //   // --------------------------------------------------------------------------------------
  //   for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
  //     // TODO: 現在の仕様だと、同一サイクルに同じアドレスのリクエストが来たとき,つまりreq_in[i]とreq_in[j]で同じアドレスの場合
  //     // 同じアドレスの複数返却を防げていないのでどうにかする.
  //     // ヒットするwayが存在するか,及びその際のデータ.
  //     logic way_hit = 0;
  //     logic [PADDR_WIDTH-1:0] hit_paddr = 0;
  //     logic hit_pte_a = 0;
  //     logic hit_pte_d = 0;

  //     // vaddr_arbiterで同じグループに先行する命令が存在するか.
  //     logic does_preceed_exist = 0;

  //     logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] vaddr_arbiter_grp_idx = 0;

  //     if (req_in_prev[i].valid) begin

  //       // hitするwayが存在するかを確認する.
  //       // TODO: asidだけの照合でも動いたので後で改変.
  //       for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
  //         if(tlb_valid[way_idx][req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] && 
  //            req_in_prev[i].satp == tlb_info_r_data[way_idx][i].satp && 
  //            req_in_prev[i].vaddr[TAG_MSB:TAG_LSB] == tlb_info_r_data[way_idx][i].tag)begin
  //           // hit
  //           way_hit   = 1;
  //           hit_paddr = {tlb_data_r_data[way_idx][i], req_in_prev[i].vaddr[PAGE_OFFSET_WIDTH-1:0]};
  //           hit_pte_a = tlb_info_r_data[way_idx][i].pte_a;
  //           hit_pte_d = tlb_info_r_data[way_idx][i].pte_d;
  //           // plruの更新
  //           // plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] = plru_util.update_plru_tree(
  //           //     plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]],
  //           //         WAY_IDX_WIDTH'(way_idx));
  //         end
  //       end

  //       // vaddr_arbiterで先行する命令が見つかるか.
  //       // ここでは,同じサイクルでdoes_proceed_exist==1であるものが反映されていない. 
  //       // しかし,本当にアドレスが一致するのであればそれは両方ともdoes_preceed_existが同じ値を取るべきなので
  //       // does_proceed_exist==1であるものが反映されていなくても問題はない.
  //       // 
  //       does_preceed_exist = vaddr_arbiter_heads[req_in_prev[i].vaddr[VADDR_ARBITER_GROUP_IDX_MSB:VADDR_ARBITER_GROUP_IDX_LSB]] 
  //                                 != (PB_UNIFIED_IDX_WIDTH+1)'(PB_UNIFIED_SIZE);


  //       if (way_hit && !does_preceed_exist) begin
  //         // hitしてかつ先行する命令に同じvaddrグループのものが存在しない場合,直接res_outに.
  //         // 他の場合は前のalways_combのブロックでpbに入れる.
  //         res_out[i] = '{
  //             valid: 1,
  //             id: req_in_prev[i].id,
  //             id_sub: req_in_prev[i].id_sub,
  //             generation: req_in_prev[i].generation,
  //             vaddr: req_in_prev[i].vaddr,
  //             paddr: hit_paddr,
  //             satp: req_in_prev[i].satp,
  //             pma_type: get_pma_type(hit_paddr),
  //             is_page_fault: 0,  // tlbに保存されてる == page_faultでない.
  //             pte_a: hit_pte_a,
  //             pte_d: hit_pte_d
  //         };
  //       end

  //     end
  //   end

  //   // -------------------------------------------------------------------------------------
  //   // data_to_res_out => res_out
  //   // --------------------------------------------------------------------------------------
  //   // data_to_res_outをres_outにマージする.
  //   // ここで,data_to_res_outでres_outを上書きしているように見えるが,実際はreq_in_prev[i]がinvalidのところ,
  //   // つまり空いているところに詰めているだけなので大丈夫.
  //   for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
  //     if (data_to_res_out_valid[i] && !req_in_prev[i].valid) begin
  //       // 順序の関係でtlbでヒットしたあとにも関わらずすぐにres_outできなかった場合,
  //       // paddrの内容はdata_to_res_out1の方に保存されている.
  //       if (data_to_res_out1[i].has_paddr) begin
  //         res_out[i] = '{
  //             valid: 1,
  //             id: data_to_res_out1[i].id,
  //             id_sub: data_to_res_out1[i].id_sub,
  //             generation: data_to_res_out1[i].generation,
  //             paddr: data_to_res_out1[i].paddr,
  //             vaddr: data_to_res_out1[i].vaddr,
  //             satp: data_to_res_out1[i].satp,
  //             pma_type: get_pma_type(data_to_res_out1[i].paddr),
  //             is_page_fault: data_to_res_out1[i].is_page_fault,
  //             pte_a: data_to_res_out1[i].pte_a,
  //             pte_d: data_to_res_out1[i].pte_d
  //         };
  //       end else begin
  //         // resinで得た情報を返す場合.
  //         res_out[i] = '{
  //             valid: 1,
  //             id: data_to_res_out1[i].id,
  //             id_sub: data_to_res_out1[i].id_sub,
  //             generation: data_to_res_out1[i].generation,
  //             paddr: {
  //               data_to_res_out2[i].paddr[PADDR_WIDTH-1:12], data_to_res_out1[i].vaddr[11:0]
  //             },
  //             vaddr: data_to_res_out1[i].vaddr,
  //             satp: data_to_res_out1[i].satp,
  //             pma_type: get_pma_type(data_to_res_out2[i].paddr),
  //             is_page_fault: data_to_res_out2[i].is_page_fault,
  //             pte_a: data_to_res_out2[i].pte_a,
  //             pte_d: data_to_res_out2[i].pte_d
  //         };
  //       end
  //     end
  //   end


  // end

  always_ff @(posedge clock) begin
    if (reset) begin

      // req_in
      req_in_prev <= '{default: 0};

      // tlb関係
      tlb_state <= TLB_IDLE;
      plru_tree <= '{default: 0};
      tlb_valid <= '{default: 0};
      tlb_generation <= 0;

      // pending_buf
      // pb_reqin_resout, pb_reqin_reqoutはlutramなので初期化しない.
      for (int unsigned i = 0; i < NUM_OF_PB_BANK; i++) begin
        pb_id_sub[i] <= '{default: 0};
      end


      // free_list
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        for (int unsigned j = 0; j < PB_BANK_SIZE; j++) begin
          pb_free_list[i][j] <= PB_IN_BANK_IDX_WIDTH'(j);
        end
      end
      pb_free_rp   <= '{default: 0};
      pb_free_wp   <= '{default: 0};
      noei_pb_free <= '{default: (PB_IN_BANK_IDX_WIDTH + 1)'(PB_BANK_SIZE)};

      // before_send_list
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        pb_before_send_list[i] <= '{default: 0};
      end
      pb_before_send_rp   <= '{default: 0};
      pb_before_send_wp   <= '{default: 0};
      noei_pb_before_send <= '{default: 0};

      // paddr_valid_list
      //  pb_paddr_valid_list <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        pb_paddr_valid_list[i] <= '{default: 0};
      end
      pb_paddr_valid_rp <= '{default: 0};
      pb_paddr_valid_wp <= '{default: 0};
      noei_pb_paddr_valid <= '{default: 0};

      // vaddr_arbiter
      vaddr_arbiter_heads <= '{default: VADDR_ARBITER_NULL};
      vaddr_arbiter_tails <= '{default: VADDR_ARBITER_NULL};
      vaddr_arbiter_ele_later <= '{default: VADDR_ARBITER_NULL};
      // pb_to_vaddr_arbiter_grp <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_PB_BANK; i++) begin
        pb_to_vaddr_arbiter_grp[i] <= '{default: 0};
      end

      // 読み出しデータ
      data_to_reqout <= '{default: 0};
      data_to_res_out_valid <= '{default: 0};
      data_to_res_out1 <= '{default: 0};
      data_to_res_out2 <= '{default: 0};

      reqout_rr_counter <= 0;

    end else if (flush_exe) begin
      // $display("[LOG][TLB.sv] TLB flush_exe");
      // req_in
      req_in_prev    <= '{default: 0};

      // tlb関係
      tlb_state      <= TLB_IDLE;
      plru_tree      <= '{default: 0};
      tlb_valid      <= '{default: 0};
      tlb_generation <= tlb_generation + 1;

      // pending_buf
      // pb_reqin_resout, pb_reqin_reqoutはlutramなので初期化しない.
      // pb_id_sub      <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_PB_BANK; i++) begin
        pb_id_sub[i] <= '{default: 0};
      end

      // free_list
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        for (int unsigned j = 0; j < PB_BANK_SIZE; j++) begin
          pb_free_list[i][j] <= PB_IN_BANK_IDX_WIDTH'(j);
        end
      end
      pb_free_rp   <= '{default: 0};
      pb_free_wp   <= '{default: 0};
      noei_pb_free <= '{default: (PB_IN_BANK_IDX_WIDTH + 1)'(PB_BANK_SIZE)};

      // before_send_list
      // pb_before_send_list     <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        pb_before_send_list[i] <= '{default: 0};
      end
      pb_before_send_rp   <= '{default: 0};
      pb_before_send_wp   <= '{default: 0};
      noei_pb_before_send <= '{default: 0};

      // paddr_valid_list
      // pb_paddr_valid_list     <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
        pb_paddr_valid_list[i] <= '{default: 0};
      end
      pb_paddr_valid_rp       <= '{default: 0};
      pb_paddr_valid_wp       <= '{default: 0};
      noei_pb_paddr_valid     <= '{default: 0};

      // vaddr_arbiter
      vaddr_arbiter_heads     <= '{default: VADDR_ARBITER_NULL};
      vaddr_arbiter_tails     <= '{default: VADDR_ARBITER_NULL};
      vaddr_arbiter_ele_later <= '{default: VADDR_ARBITER_NULL};
      // pb_to_vaddr_arbiter_grp <= '{default: '{default: 0}};
      for (int unsigned i = 0; i < NUM_OF_PB_BANK; i++) begin
        pb_to_vaddr_arbiter_grp[i] <= '{default: 0};
      end


      // 読み出しデータ
      data_to_reqout        <= '{default: 0};
      data_to_res_out_valid <= '{default: 0};
      data_to_res_out1      <= '{default: 0};
      data_to_res_out2      <= '{default: 0};

    end else begin
      // req_in
      req_in_prev             <= req_in;

      // tlb関係
      tlb_state               <= tlb_state_next;
      plru_tree               <= plru_tree_next;
      tlb_valid               <= tlb_valid_next;

      // free_list
      pb_free_list            <= pb_free_list_next;
      pb_free_rp              <= pb_free_rp_next;
      pb_free_wp              <= pb_free_wp_next;
      noei_pb_free            <= noei_pb_free_next;

      // before_send_list
      pb_before_send_list     <= pb_before_send_list_next;
      pb_before_send_rp       <= pb_before_send_rp_next;
      pb_before_send_wp       <= pb_before_send_wp_next;
      noei_pb_before_send     <= noei_pb_before_send_next;

      // paddr_valid_list
      pb_paddr_valid_list     <= pb_paddr_valid_list_next;
      pb_paddr_valid_rp       <= pb_paddr_valid_rp_next;
      pb_paddr_valid_wp       <= pb_paddr_valid_wp_next;
      noei_pb_paddr_valid     <= noei_pb_paddr_valid_next;

      // vaddr_arbiter
      vaddr_arbiter_heads     <= vaddr_arbiter_heads_next;
      vaddr_arbiter_tails     <= vaddr_arbiter_tails_next;
      vaddr_arbiter_ele_later <= vaddr_arbiter_ele_later_next;
      pb_to_vaddr_arbiter_grp <= pb_to_vaddr_arbiter_grp_next;

      reqout_rr_counter       <= reqout_rr_counter_next;



      // 各種pbにエントリを追加.
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_REQ_IN; bank_idx++) begin
        automatic logic [VADDR_ARBITER_GROUP_IDX_WIDTH-1:0] vaddr_arbiter_grp_idx = 0;
        if (new_pb_entries_from_tlb_list[bank_idx].valid) begin
          pb_reqin_resout[bank_idx][new_pb_entries_from_tlb_list[bank_idx].in_bank_idx] <= '{
              id: new_pb_entries[bank_idx].id,
              id_sub: new_pb_entries[bank_idx].id_sub,
              generation: new_pb_entries[bank_idx].generation,
              satp: new_pb_entries[bank_idx].satp,
              vaddr: new_pb_entries[bank_idx].vaddr,
              has_paddr: new_pb_entries_from_tlb_list[bank_idx].has_paddr,
              paddr: new_pb_entries[bank_idx].paddr,
              is_page_fault: new_pb_entries[bank_idx].is_page_fault,
              pte_a: new_pb_entries[bank_idx].pte_a,
              pte_d: new_pb_entries[bank_idx].pte_d
          };
          pb_reqin_reqout[bank_idx][new_pb_entries_from_tlb_list[bank_idx].in_bank_idx] <= '{
              satp: new_pb_entries[bank_idx].satp,
              vaddr: new_pb_entries[bank_idx].vaddr
          };
          pb_id_sub[bank_idx][new_pb_entries_from_tlb_list[bank_idx].in_bank_idx] <= new_pb_entries[bank_idx].id_sub;
        end
      end

      // resin_updateによるpb_resin_resoutのアップデート
      if (resin_update.valid) begin
        pb_resin_resout[resin_update.bank_idx][resin_update.in_bank_idx] <= '{
            paddr: resin_update.paddr,
            is_page_fault: resin_update.is_page_fault,
            pte_a: resin_update.pte_a,
            pte_d: resin_update.pte_d
        };
      end

      // data_to_reqoutの作成
      // reqin_reqout から出す.
      begin
        automatic logic [PB_BANK_IDX_WIDTH-1:0] bank_idx = data_to_reqout_select.bank_idx;
        if (data_to_reqout_select.valid) begin

          data_to_reqout <= '{
              valid: 1,
              bank_idx: bank_idx,
              in_bank_idx: data_to_reqout_select.in_bank_idx,
              satp: pb_reqin_reqout[bank_idx][data_to_reqout_select.in_bank_idx].satp,
              vaddr: pb_reqin_reqout[bank_idx][data_to_reqout_select.in_bank_idx].vaddr
          };
          // バイパス
          for (int unsigned i = 0; i < NUM_OF_PB_BANK; i++) begin
            if(new_pb_entries_from_tlb_list[i].valid && PB_BANK_IDX_WIDTH'(i) == bank_idx && 
                new_pb_entries_from_tlb_list[i].in_bank_idx == data_to_reqout_select.in_bank_idx)begin
              data_to_reqout <= '{
                  valid: 1,
                  bank_idx: bank_idx,
                  in_bank_idx: new_pb_entries_from_tlb_list[i].in_bank_idx,
                  satp: new_pb_entries[bank_idx].satp,
                  vaddr: new_pb_entries[bank_idx].vaddr
              };
            end
          end

        end else begin
          data_to_reqout <= '{default: 0};
        end
      end



      // data_to_resoutの作成.
      for (int unsigned bank_idx = 0; bank_idx < NUM_OF_RES_OUT; bank_idx++) begin
        automatic
        logic [PB_IN_BANK_IDX_WIDTH-1:0]
        in_bank_idx = data_to_resout_select[bank_idx].in_bank_idx;
        if (data_to_resout_select[bank_idx].valid) begin
          data_to_res_out_valid[bank_idx] <= 1;
          data_to_res_out1[bank_idx] <= pb_reqin_resout[bank_idx][in_bank_idx];
          data_to_res_out2[bank_idx] <= pb_resin_resout[bank_idx][in_bank_idx];
          // バイパス
          // reqinからの更新をバイパス.

          if(new_pb_entries_from_tlb_list[bank_idx].valid &&  
                new_pb_entries_from_tlb_list[bank_idx].in_bank_idx == in_bank_idx)begin
            data_to_res_out1[bank_idx] <= '{
                id: new_pb_entries[bank_idx].id,
                id_sub: new_pb_entries[bank_idx].id_sub,
                generation: new_pb_entries[bank_idx].generation,
                satp: new_pb_entries[bank_idx].satp,
                vaddr: new_pb_entries[bank_idx].vaddr,
                has_paddr: new_pb_entries_from_tlb_list[bank_idx].has_paddr,
                paddr: new_pb_entries[bank_idx].paddr,
                is_page_fault: new_pb_entries[bank_idx].is_page_fault,
                pte_a: new_pb_entries[bank_idx].pte_a,
                pte_d: new_pb_entries[bank_idx].pte_d
            };
          end
          // resinからの更新をバイパス.
          if(resin_update.valid && resin_update.bank_idx == PB_BANK_IDX_WIDTH'(bank_idx) && resin_update.in_bank_idx == in_bank_idx)begin
            data_to_res_out2[bank_idx] <= '{
                paddr: resin_update.paddr,
                is_page_fault: resin_update.is_page_fault,
                pte_a: resin_update.pte_a,
                pte_d: resin_update.pte_d
            };
          end
        end else begin
          data_to_res_out_valid[bank_idx] <= 0;
          data_to_res_out1[bank_idx] <= '{default: 0};
          data_to_res_out2[bank_idx] <= '{default: 0};
        end
      end

    end
  end


  //FOEDEBUG
  // always_ff @(posedge clock) begin
  //   for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
  //     if (res_out[i].valid && res_out[i].vaddr == 39'h1400) begin
  //       automatic tlb_res_t r = res_out[i];
  //       if (r.valid) begin
  //         $display(
  //             "[LOG][MMU.sv] res_out[%0d] valid=%0b id=%0d sub=%0b gen=%0d vaddr=%h paddr=%h satp=%h pma=%0d pf=%0b a=%0b d=%0b",
  //             i, r.valid, r.id, r.id_sub, r.generation, r.vaddr, r.paddr, r.satp, r.pma_type,
  //             r.is_page_fault, r.pte_a, r.pte_d);
  //       end
  //     end
  //   end
  // end


  int unsigned counter;

  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     counter <= 0;
  //   end else begin
  //     if (counter % 2000000 == 0) begin
  //       for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin
  //         $display("[TLB] noei_pb_free[%d]:%d\n", i, noei_pb_free[i]);
  //       end
  //     end
  //   end

  //   counter <= counter + 1;


  // end


endmodule
