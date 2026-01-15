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
// pending bufは満タンにならないように大きめに取る.
// そうすることで,req_inをstallする必要がなくなる.

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
    parameter int unsigned NUM_OF_WAYS = 4,
    parameter int unsigned NUM_OF_SET  = 256,

    parameter int unsigned NUM_OF_REQ_IN  = 2,
    parameter int unsigned NUM_OF_RES_OUT = 2,
    parameter int unsigned NUM_OF_REQ_OUT = NUM_OF_REQ_IN,
    parameter int unsigned NUM_OF_RES_IN  = 2,

    // itlbは0,dtlbは1,l2tlbは2.
    parameter int unsigned TLB_ID = 0
) (
    input logic clock,
    input logic reset,

    // L2TLBにとってのL1TLBとのやり取りや,L1TLBにとってのCPUとのやり取り
    input  tlb_req_t req_in [ NUM_OF_REQ_IN],
    output tlb_res_t res_out[NUM_OF_RES_OUT],

    // L2TLBにとってのpwとのやり取りや,L1TLBにとってのL2TLBとのやり取り.
    output tlb_req_t req_out[NUM_OF_REQ_OUT],
    input  tlb_res_t res_in [ NUM_OF_RES_IN],

    // リクエスト(pwへのリクエスト等)が受け入れ可能かを示す信号を出す.
    // stall_outが無いのはpending_buf=> stall_outをすると,circulartに回路がなるから.
    input logic stall_in[NUM_OF_REQ_OUT],

    output logic stall_out,

    input logic flush_tlb

);

  // TLBポート.
  localparam int unsigned NUM_OF_TLB_READ_PORT = NUM_OF_REQ_IN;
  localparam int unsigned NUM_OF_TLB_WRITE_PORT = NUM_OF_RES_IN;

  // PENDING_BUF
  // icacheでは,ifqのエントリ以上,
  // dcacheではactive list以上である必要がある.
  localparam int unsigned PENDING_BUF_SIZE = 64;
  localparam int unsigned PENDING_BUF_IDX_WIDTH = $clog2(PENDING_BUF_SIZE);

  localparam int unsigned PADDR_MIG_ALIGNED_MSB = PADDR_WIDTH - 1;
  localparam int unsigned PADDR_MIG_ALIGNED_LSB = PAGE_OFFSET_WIDTH;
  localparam int unsigned PADDR_MIG_ALIGNED_CUT0_WIDTH = PADDR_WIDTH - PAGE_OFFSET_WIDTH;

  // 各種パラメータ.
  //localparam int unsigned NUM_OF_WAYS = 4;
  localparam int unsigned WAY_IDX_WIDTH = $clog2(NUM_OF_WAYS);

  //localparam int unsigned NUM_OF_SET = 256;
  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SET);
  localparam int unsigned SET_IDX_LSB = PAGE_OFFSET_WIDTH;
  localparam int unsigned SET_IDX_MSB = SET_IDX_LSB + SET_IDX_WIDTH - 1;

  localparam int unsigned TAG_WIDHT = VADDR_WIDTH - SET_IDX_WIDTH - PAGE_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = VADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + PAGE_OFFSET_WIDTH;

  localparam int unsigned UP_WIDTH = PADDR_WIDTH - PAGE_OFFSET_WIDTH;
  localparam int unsigned UP_MSB = PADDR_WIDTH - 1;
  localparam int unsigned UP_LSB = PAGE_OFFSET_WIDTH;

  localparam int unsigned TMP_BUF_SIZE = 16;
  localparam int unsigned TMP_BUF_IDX_WIDTH = $clog2(TMP_BUF_SIZE);

  localparam int unsigned MISS_BUF_SIZE = 16;
  localparam int unsigned MISS_BUF_IDX_WIDTH = $clog2(MISS_BUF_SIZE);

  localparam int unsigned REQUEST_BUF_SIZE = 4;
  localparam int unsigned REQUEST_BUF_IDX_WIDTH = $clog2(REQUEST_BUF_SIZE);


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

  // -------------------------------------------------------------
  // 出力
  // -------------------------------------------------------------
  // それぞれffを挟まないとcircularになるので.
  tlb_req_t req_out_next[NUM_OF_REQ_OUT];
  tlb_res_t res_out_next[NUM_OF_RES_OUT];

  // -------------------------------------------------------
  // TLB_valid
  // -------------------------------------------------------
  // そのエントリがvalidかはffで保持する.
  logic [NUM_OF_WAYS-1:0][NUM_OF_SET-1:0] tlb_valid;
  logic [NUM_OF_WAYS-1:0][NUM_OF_SET-1:0] tlb_valid_next;


  // ---------------------------------------------------------------
  // tlb_info
  // ---------------------------------------------------------------
  // tagやasidなどのメタ情報
  typedef struct packed {
    logic [TAG_WIDHT-1:0] tag;
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
  logic [$bits(tlb_info_t)/8-1:0] tlb_info_w_mask[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];

  // lvtramの入出力はビット列だが,構造体に変換したものの方が
  tlb_info_t tlb_info_r_data[NUM_OF_WAYS][NUM_OF_TLB_READ_PORT];
  tlb_info_t tlb_info_w_data[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];


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

    // マスクの初期化(使用しないけど)
    for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
      for (int unsigned j = 0; j < NUM_OF_TLB_WRITE_PORT; j++) begin
        tlb_info_w_mask[i][j] = {($bits(tlb_info_t) / 8) {1'b1}};
      end
    end
  end



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
          .w_data(tlb_info_w_bit_data[tlb_info_way_idx]),
          .w_mask(tlb_info_w_mask[tlb_info_way_idx])
      );
    end
  endgenerate

  // -------------------------------------------------------------
  // tlb_data
  // -------------------------------------------------------------
  // 変換先のpaddrが入ってるtlbのデータ本体

  logic tlb_data_r_en[NUM_OF_TLB_READ_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_data_r_ram_idx[NUM_OF_TLB_READ_PORT];
  logic [PADDR_MIG_ALIGNED_CUT0_WIDTH-1:0] tlb_data_r_data[NUM_OF_WAYS][NUM_OF_TLB_READ_PORT];

  logic tlb_data_w_en[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [SET_IDX_WIDTH-1:0] tlb_data_w_ram_idx[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [PADDR_MIG_ALIGNED_CUT0_WIDTH-1:0] tlb_data_w_data[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];
  logic [PADDR_MIG_ALIGNED_CUT0_WIDTH/8-1:0] tlb_data_w_mask[NUM_OF_WAYS][NUM_OF_TLB_WRITE_PORT];

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
          .w_data(tlb_data_w_data[tlb_data_way_idx]),
          .w_mask(tlb_data_w_mask[tlb_data_way_idx])
      );
    end
  endgenerate

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
      for (int unsigned j = 0; j < NUM_OF_TLB_WRITE_PORT; j++) begin
        tlb_data_w_mask[i][j] = {(PADDR_MIG_ALIGNED_CUT0_WIDTH / 8) {1'b1}};
      end
    end
  end


  // -------------------------------------------------------------
  // PLRU TREE
  // -------------------------------------------------------------
  logic [NUM_OF_WAYS-1:0] plru_tree[NUM_OF_SET];
  logic [NUM_OF_WAYS-1:0] plru_tree_next[NUM_OF_SET];

  // plru_treeをアップデートしたら古いものを探索したりする関数.
  TREE_PLRU_FUNC #(.NUM_OF_WAYS(NUM_OF_WAYS)) plru_util ();

  // -------------------------------------
  // pending_buf
  // -------------------------------------
  // res_inに対してすべてのpending_bufのエントリを調べる必要があるので,FFで実装する.
  // 先頭のNUM_OF_REQ_OUT個がMMにリクエストを送っているが、それに対するres_inが途中のエントリにヒットする
  // 可能性があるので,その際は詰める.
  typedef enum logic [1:0] {
    BEFORE_PADDR_REQUEST,
    DURING_PADDR_REQUEST,
    PADDR_VALID
  } pending_buf_state_e;

  typedef struct packed {
    logic valid;
    int unsigned id;
    logic id_sub;
    int unsigned generation;
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
    pending_buf_state_e state;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_page_fault;
    logic pte_a;
    logic pte_d;
  } pending_buf_t;

  pending_buf_t pending_buf[PENDING_BUF_SIZE];
  pending_buf_t pending_buf_next[PENDING_BUF_SIZE];

  int unsigned num_of_entries_in_pb;
  int unsigned num_of_entries_in_pb_next;


  // ------------------------------------
  //
  // -----------------------------------
  // 1サイクル前に入ってきたreq_in.
  // この情報とtlb_infoから読み出したタグ情報などを比較する.
  tlb_req_t req_in_prev[NUM_OF_REQ_IN];


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



  always_comb begin
    // 初期化

    // pending_buf
    pending_buf_next = pending_buf;
    num_of_entries_in_pb_next = num_of_entries_in_pb;


    // 初期化.
    plru_tree_next = plru_tree;
    tlb_valid_next = tlb_valid;

    // ---------------------------------------------------------------
    // res_inのpendign_buf,TLB本体,TLB_infoへの反映
    // ----------------------------------------------------------------
    // res_in => pending_buf_next
    // res_inを反映させて,paddrが戻ってきたpending_bufのエントリをdone_bufに送り,
    // 送ったぶんだけpending_buf_next1を詰めてpendig_buf_next2にする.
    begin
      for (int unsigned pb_idx = 0; pb_idx < PENDING_BUF_SIZE; pb_idx++) begin
        for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
          if (res_in[i].valid) begin

            if (pending_buf_next[pb_idx].valid && res_in[i].id == pending_buf_next[pb_idx].id && 
                 res_in[i].id_sub == pending_buf_next[pb_idx].id_sub && 
                 res_in[i].generation == pending_buf_next[pb_idx].generation) begin
              pending_buf_next[pb_idx].state = PADDR_VALID;
              pending_buf_next[pb_idx].paddr = res_in[i].paddr;
              pending_buf_next[pb_idx].is_page_fault = res_in[i].is_page_fault;
              pending_buf_next[pb_idx].pte_a = res_in[i].pte_a;
              pending_buf_next[pb_idx].pte_d = res_in[i].pte_d;


              // FOR DEBUG
              // if (TLB_ID == 2 && pending_buf_next[pb_idx].vaddr == 39'h3fffffbff8) begin
              //   $display("[LOG][L2TLB] res_in[%0d] valid=%0d id=%0d id_sub=%0d gen=%0d", i,
              //            res_in[i].valid, res_in[i].id, res_in[i].id_sub, res_in[i].generation);
              //   $display("[LOG][L2TLB] res_in[%0d] vaddr=0x%0h paddr=0x%0h", i, res_in[i].vaddr,
              //            res_in[i].paddr);
              //   $display("[LOG][L2TLB] pending_buf_next[%0d] valid=%0d id=%0d id_sub=%0d gen=%0d",
              //            pb_idx, pending_buf_next[pb_idx].valid, pending_buf_next[pb_idx].id,
              //            pending_buf_next[pb_idx].id_sub, pending_buf_next[pb_idx].generation);

              //   $display(
              //       "[LOG][L2TLB] pending_buf_next[%0d] vaddr=0x%0h paddr=0x%0h state=%0d page_fault=%0d pte_a=%0d pte_d=%0d",
              //       pb_idx, pending_buf_next[pb_idx].vaddr, pending_buf_next[pb_idx].paddr,
              //       pending_buf_next[pb_idx].state, pending_buf_next[pb_idx].is_page_fault,
              //       pending_buf_next[pb_idx].pte_a, pending_buf_next[pb_idx].pte_d);
              // end
            end
          end
        end
      end
    end


    // ------------------------------------------------------------------------
    // tlb_info, tlb_data => penging_buf
    // -------------------------------------------------------------------------
    // req_in_prev, tlb_info_r_data, tlb_data_r_data
    // => pending_buf_next
    // tlb本体やtlb_infoの出力を見て,リクエストされたvaddrに対応するエントリが存在するかを確認し,pending_buf_nextに送る
    for (int unsigned i = 0; i < NUM_OF_REQ_IN; i++) begin

      logic way_hit = 0;
      logic [PADDR_WIDTH-1:0] hit_paddr = 0;
      logic hit_pte_a = 0;
      logic hit_pte_d = 0;
      if (req_in_prev[i].valid) begin

        // ヒット時
        for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
          if(tlb_valid[way_idx][req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] && 
             req_in_prev[i].satp == tlb_info_r_data[way_idx][i].satp && 
             req_in_prev[i].vaddr[TAG_MSB:TAG_LSB] == tlb_info_r_data[way_idx][i].tag)begin
            // hit
            way_hit = 1;
            hit_paddr = {tlb_data_r_data[way_idx][i], req_in_prev[i].vaddr[PAGE_OFFSET_WIDTH-1:0]};
            hit_pte_a = tlb_info_r_data[way_idx][i].pte_a;
            hit_pte_d = tlb_info_r_data[way_idx][i].pte_d;
            // plruの更新
            plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]] = plru_util.update_plru_tree(
                plru_tree_next[req_in_prev[i].vaddr[SET_IDX_MSB:SET_IDX_LSB]],
                    WAY_IDX_WIDTH'(way_idx));
          end
        end

        // => pending_buf
        if (way_hit) begin
          // hit
          pending_buf_next[num_of_entries_in_pb_next] = '{
              valid: 1,
              id: req_in_prev[i].id,
              id_sub: req_in_prev[i].id_sub,
              generation: req_in_prev[i].generation,
              satp: req_in_prev[i].satp,
              vaddr: req_in_prev[i].vaddr,
              state: PADDR_VALID,
              paddr: hit_paddr,
              is_page_fault: 0,  // tlbに保存されてる == page_faultでない.
              pte_a: hit_pte_a,
              pte_d: hit_pte_d
          };
        end else begin
          // miss
          pending_buf_next[num_of_entries_in_pb_next] = '{
              valid: 1,
              id: req_in_prev[i].id,
              id_sub: req_in_prev[i].id_sub,
              generation: req_in_prev[i].generation,
              satp: req_in_prev[i].satp,
              vaddr: req_in_prev[i].vaddr,
              state: BEFORE_PADDR_REQUEST,
              paddr: 0,
              is_page_fault: 0,
              pte_a: 0,
              pte_d: 0
          };
        end

        num_of_entries_in_pb_next++;

      end
    end

    // -----------------------------------------------------------------------------
    // res_inでtlb更新.
    // -----------------------------------------------------------------------------

    for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
      for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
        // tlb_data
        tlb_data_w_en[way_idx][i] = 0;
        tlb_data_w_ram_idx[way_idx][i] = 0;
        tlb_data_w_data[way_idx][i] = 0;
        // tlb_info
        tlb_info_w_en[way_idx][i] = 0;
        tlb_info_w_ram_idx[way_idx][i] = 0;
        tlb_info_w_data[way_idx][i] = 0;
      end
    end


    // 下位レイヤからのレスポンスでtlb本体やtlb_info,tlb_validを更新する
    begin
      logic [WAY_IDX_WIDTH-1:0] oldest_way_idx = 0;
      logic [SET_IDX_WIDTH-1:0] res_set_idx = 0;

      for (int unsigned i = 0; i < NUM_OF_RES_IN; i++) begin
        // page_faultならtlb本体は更新しない.
        if (res_in[i].valid && !res_in[i].is_page_fault && get_pma_type(
                res_in[i].paddr
            ) == PMA_MEMORY) begin
          res_set_idx = res_in[i].vaddr[SET_IDX_MSB:SET_IDX_LSB];
          // 最も昔に使われたwayの検索とplru_treeの更新
          oldest_way_idx = plru_util.search_oldest(plru_tree_next[res_set_idx]);
          plru_tree_next[res_set_idx] =
              plru_util.update_plru_tree(plru_tree_next[res_set_idx], oldest_way_idx);
          // tlb_dataへの書き込み
          tlb_data_w_en[oldest_way_idx][i] = 1'b1;
          tlb_data_w_ram_idx[oldest_way_idx][i] = res_set_idx;
          tlb_data_w_data[oldest_way_idx][i] = res_in[i].paddr[PADDR_MIG_ALIGNED_MSB:PADDR_MIG_ALIGNED_LSB];
          // tlb_infoへの書き込み.
          tlb_info_w_en[oldest_way_idx][i] = 1'b1;
          tlb_info_w_ram_idx[oldest_way_idx][i] = res_set_idx;
          tlb_info_w_data[oldest_way_idx][i] = '{
              tag: res_in[i].vaddr[TAG_MSB:TAG_LSB],
              satp: res_in[i].satp,
              pte_a: res_in[i].pte_a,
              pte_d: res_in[i].pte_d
          };
          //
          tlb_valid_next[oldest_way_idx][res_set_idx] = 1'b1;

        end
      end
    end



    // -------------------------------------------------------
    // pendign_buf_next => req_out
    // -------------------------------------------------------
    // pendign_buf_next, stall_in => req_out
    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      req_out_next[i] = '{default: 0};
    end


    for (int unsigned i = 0; i < NUM_OF_REQ_OUT; i++) begin
      if (!stall_in[i]) begin
        for (int unsigned j = 0; j < PENDING_BUF_SIZE; j++) begin
          if (pending_buf_next[j].valid && pending_buf_next[j].state == BEFORE_PADDR_REQUEST) begin
            req_out_next[i] = '{
                valid: 1,
                id: pending_buf_next[j].id,
                id_sub: pending_buf_next[j].id_sub,
                generation: pending_buf_next[j].generation,
                satp: pending_buf_next[j].satp,
                vaddr: pending_buf_next[j].vaddr
            };
            pending_buf_next[j].state = DURING_PADDR_REQUEST;
            // 一つのreq_out[i]を上書きしないように.
            break;
          end
        end

      end

    end


    // -----------------------------------------------------------
    // pending_buf => res_out
    // ----------------------------------------------------------
    // pending_buf_next => res_out
    // 同じpaddrを持つものは1サイクルで同時に返さない.
    // dw単位で同じアドレスかを判定する.結局cacheで順番が入れ替わらないことが重要なので
    begin
      // 初期化
      int unsigned res_out_counter = 0;
      logic [PADDR_WIDTH-1:0] res_out_dw_aligned_paddr_log[NUM_OF_RES_OUT] = '{default: 0};
      logic is_same_paddr_out_exist = 0;
      for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
        res_out_next[i] = '{default: 0, pma_type: PMA_NONE};
      end

      for (int unsigned i = 0; i < PENDING_BUF_SIZE; i++) begin
        if (pending_buf_next[i].valid && pending_buf_next[i].state == PADDR_VALID &&  res_out_counter < NUM_OF_RES_OUT) begin

          // 今までのres_out_nextの中に,pending_buf_nextと同じpaddrを持つものが存在するかどうか.
          is_same_paddr_out_exist = 0;
          for (int unsigned j = 0; j < res_out_counter; j++) begin
            if (res_out_dw_aligned_paddr_log[j] == to_dw_aligned_paddr(
                    pending_buf_next[i].paddr
                )) begin
              is_same_paddr_out_exist = 1;
            end
          end

          // 同じpaddrを持つものがなかったらres_out
          if (!is_same_paddr_out_exist) begin
            res_out_next[res_out_counter] = '{
                valid: 1,
                id: pending_buf_next[i].id,
                id_sub: pending_buf_next[i].id_sub,
                generation: pending_buf_next[i].generation,
                paddr: pending_buf_next[i].paddr,
                vaddr: pending_buf_next[i].vaddr,
                satp: pending_buf_next[i].satp,
                pma_type: get_pma_type(pending_buf_next[i].paddr),
                is_page_fault: pending_buf_next[i].is_page_fault,
                pte_a: pending_buf_next[i].pte_a,
                pte_d: pending_buf_next[i].pte_d
            };
            // logに登録.
            res_out_dw_aligned_paddr_log[res_out_counter] =
                to_dw_aligned_paddr(pending_buf_next[i].paddr);
            // pending_bufからの削除.
            pending_buf_next[i].valid = 0;
            num_of_entries_in_pb_next--;
            res_out_counter++;
          end
        end
      end
    end


    // ---------------------------------------------------------------------
    // pending_buf_nextを詰める.
    // ---------------------------------------------------------------------
    begin
      pending_buf_t pending_buf_tmp[PENDING_BUF_SIZE] = '{default: 0};
      int unsigned invalid_counter = 0;
      for (int unsigned i = 0; i < PENDING_BUF_SIZE; i++) begin
        if (pending_buf_next[i].valid) begin
          pending_buf_tmp[i-invalid_counter] = pending_buf_next[i];
        end else begin
          invalid_counter++;
        end
      end
      pending_buf_next = pending_buf_tmp;
    end



  end


  // ----------------------------------------------------------------------
  // flushによる状態更新(SFENCE_VMA)
  // ----------------------------------------------------------------------
  always_comb begin

    logic req_in_all_invalid = 1;
    tlb_state_next = tlb_state;
    flush_exe = 0;

    // num_of_entries_in_pb_nextを使うとcircular
    if (tlb_state_next == TLB_WAITING_FLUSH && num_of_entries_in_pb == 0 && req_in_all_invalid) begin
      // flush_exe == 1で、次のサイクル立ち上がり時にtlb_validをflush
      flush_exe = 1;
      tlb_state_next = TLB_IDLE;
    end

    // TLB_WAITING_FLUSH => TLB_IDLEの更新は,TLB_IDLE => TLB_WAITING_FLUSHのあとに置くこと.
    // 前に置くと, TLB_IDLE => TLB_WAITING_FLUSH => TLB_IDLEが1度におこって、req_inがpbに反映される前に
    // TLB_WAITING_FLUSH => TLB_IDLE の判定が行われる.
    // TLB_WAITING_FLUSH => TLB_IDLE の判定にreq_inを含めればいいじゃないかとおもうかもしれないが、それだとcircularになる.
    if (flush_tlb && tlb_state_next == TLB_IDLE) begin
      tlb_state_next = TLB_WAITING_FLUSH;
    end

  end

  // -----------------------------------------------------------------------
  // stall_out
  // -----------------------------------------------------------------------
  always_comb begin
    // num_of_pending_buf_nextを使うとcircularになるので,num_of_entries_in_pbを使う.
    stall_out = (tlb_state_next == TLB_WAITING_FLUSH) || 
                (PENDING_BUF_SIZE - num_of_entries_in_pb < 2* NUM_OF_REQ_IN);
  end



  // --------------------------------------------------------------------------
  // req_inに対応する読み込みリクエストをtlb_data,tlb_infoに出す
  // ---------------------------------------------------------------------------
  // req_in
  // => tlb_data_r_en, tlb_data_r_ram_idx,
  //    tlb_info_r_en, tlb_info_r_ram_idx
  // 次のサイクルでの出力をstallがかかったときはなくす必要がある.
  always_comb begin
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

  // FOR DEBUG
  // always_ff @(posedge clock, posedge reset) begin
  //   if (TLB_ID == 2) begin
  //     for (int unsigned i = 0; i < NUM_OF_RES_OUT; i++) begin
  //       if (res_out[i].valid && res_out[i].vaddr == 39'h3fffffbff8 && res_out[i].is_page_fault) begin
  //         // res_out[i] : tlb_res_t
  //         $display("[LOG][L2TLB] res_out[%0d] valid=%0d id=%0d id_sub=%0d gen=%0d", i,
  //                  res_out[i].valid, res_out[i].id, res_out[i].id_sub, res_out[i].generation);
  //         $display("[LOG][L2TLB] res_out[%0d] vaddr=0x%0h paddr=0x%0h satp=0x%0h", i,
  //                  res_out[i].vaddr, res_out[i].paddr, res_out[i].satp);
  //         $display("[LOG][L2TLB] res_out[%0d] pma_type=%0d is_page_fault=%0d pte_a=%0d pte_d=%0d",
  //                  i, res_out[i].pma_type, res_out[i].is_page_fault, res_out[i].pte_a,
  //                  res_out[i].pte_d);
  //       end


  //     end
  //   end
  // end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // tlb
      tlb_valid <= '{default: 0};
      plru_tree <= '{default: 0};

      // pending_buf
      pending_buf <= '{default: 0};
      num_of_entries_in_pb <= 0;

      // req_in
      req_in_prev <= '{default: 0};

      // 出力
      req_out <= '{default: 0};
      res_out <= '{default: 0};
    end else begin
      // tlb
      if (flush_exe) begin
        tlb_valid <= '{default: 0};
      end else begin
        tlb_valid <= tlb_valid_next;
      end
      plru_tree <= plru_tree_next;

      // pending_buf
      pending_buf <= pending_buf_next;
      num_of_entries_in_pb <= num_of_entries_in_pb_next;


      // req_in
      req_in_prev <= req_in;

      // 出力
      req_out <= req_out_next;
      res_out <= res_out_next;

      // state
      tlb_state <= tlb_state_next;
    end
  end




  // FOR DEBUG

  pending_buf_t pending_buf_next0;
  pending_buf_t pending_buf_next1;
  pending_buf_t pending_buf_next2;
  pending_buf_t pending_buf_next3;
  pending_buf_t pending_buf_next4;
  pending_buf_t pending_buf_next5;
  pending_buf_t pending_buf_next6;
  pending_buf_t pending_buf_next7;
  pending_buf_t pending_buf_next8;
  pending_buf_t pending_buf_next9;
  pending_buf_t pending_buf_next10;
  pending_buf_t pending_buf_next11;
  pending_buf_t pending_buf_next12;
  pending_buf_t pending_buf_next13;
  pending_buf_t pending_buf_next14;
  pending_buf_t pending_buf_next15;
  pending_buf_t pending_buf_next16;
  pending_buf_t pending_buf_next17;
  pending_buf_t pending_buf_next18;
  pending_buf_t pending_buf_next19;
  pending_buf_t pending_buf_next20;
  pending_buf_t pending_buf_next21;
  pending_buf_t pending_buf_next22;
  pending_buf_t pending_buf_next23;
  pending_buf_t pending_buf_next24;
  pending_buf_t pending_buf_next25;
  pending_buf_t pending_buf_next26;
  pending_buf_t pending_buf_next27;
  pending_buf_t pending_buf_next28;
  pending_buf_t pending_buf_next29;
  pending_buf_t pending_buf_next30;
  pending_buf_t pending_buf_next31;
  pending_buf_t pending_buf_next32;
  pending_buf_t pending_buf_next33;
  pending_buf_t pending_buf_next34;
  pending_buf_t pending_buf_next35;
  pending_buf_t pending_buf_next36;
  pending_buf_t pending_buf_next37;
  pending_buf_t pending_buf_next38;
  pending_buf_t pending_buf_next39;
  pending_buf_t pending_buf_next40;
  pending_buf_t pending_buf_next41;
  pending_buf_t pending_buf_next42;
  pending_buf_t pending_buf_next43;
  pending_buf_t pending_buf_next44;
  pending_buf_t pending_buf_next45;
  pending_buf_t pending_buf_next46;
  pending_buf_t pending_buf_next47;
  pending_buf_t pending_buf_next48;
  pending_buf_t pending_buf_next49;
  pending_buf_t pending_buf_next50;
  pending_buf_t pending_buf_next51;
  pending_buf_t pending_buf_next52;
  pending_buf_t pending_buf_next53;
  pending_buf_t pending_buf_next54;
  pending_buf_t pending_buf_next55;
  pending_buf_t pending_buf_next56;
  pending_buf_t pending_buf_next57;
  pending_buf_t pending_buf_next58;
  pending_buf_t pending_buf_next59;
  pending_buf_t pending_buf_next60;
  pending_buf_t pending_buf_next61;
  pending_buf_t pending_buf_next62;
  pending_buf_t pending_buf_next63;

  always_comb begin
    pending_buf_next0  = pending_buf_next[0];
    pending_buf_next1  = pending_buf_next[1];
    pending_buf_next2  = pending_buf_next[2];
    pending_buf_next3  = pending_buf_next[3];
    pending_buf_next4  = pending_buf_next[4];
    pending_buf_next5  = pending_buf_next[5];
    pending_buf_next6  = pending_buf_next[6];
    pending_buf_next7  = pending_buf_next[7];
    pending_buf_next8  = pending_buf_next[8];
    pending_buf_next9  = pending_buf_next[9];
    pending_buf_next10 = pending_buf_next[10];
    pending_buf_next11 = pending_buf_next[11];
    pending_buf_next12 = pending_buf_next[12];
    pending_buf_next13 = pending_buf_next[13];
    pending_buf_next14 = pending_buf_next[14];
    pending_buf_next15 = pending_buf_next[15];
    pending_buf_next16 = pending_buf_next[16];
    pending_buf_next17 = pending_buf_next[17];
    pending_buf_next18 = pending_buf_next[18];
    pending_buf_next19 = pending_buf_next[19];
    pending_buf_next20 = pending_buf_next[20];
    pending_buf_next21 = pending_buf_next[21];
    pending_buf_next22 = pending_buf_next[22];
    pending_buf_next23 = pending_buf_next[23];
    pending_buf_next24 = pending_buf_next[24];
    pending_buf_next25 = pending_buf_next[25];
    pending_buf_next26 = pending_buf_next[26];
    pending_buf_next27 = pending_buf_next[27];
    pending_buf_next28 = pending_buf_next[28];
    pending_buf_next29 = pending_buf_next[29];
    pending_buf_next30 = pending_buf_next[30];
    pending_buf_next31 = pending_buf_next[31];
    pending_buf_next32 = pending_buf_next[32];
    pending_buf_next33 = pending_buf_next[33];
    pending_buf_next34 = pending_buf_next[34];
    pending_buf_next35 = pending_buf_next[35];
    pending_buf_next36 = pending_buf_next[36];
    pending_buf_next37 = pending_buf_next[37];
    pending_buf_next38 = pending_buf_next[38];
    pending_buf_next39 = pending_buf_next[39];
    pending_buf_next40 = pending_buf_next[40];
    pending_buf_next41 = pending_buf_next[41];
    pending_buf_next42 = pending_buf_next[42];
    pending_buf_next43 = pending_buf_next[43];
    pending_buf_next44 = pending_buf_next[44];
    pending_buf_next45 = pending_buf_next[45];
    pending_buf_next46 = pending_buf_next[46];
    pending_buf_next47 = pending_buf_next[47];
    pending_buf_next48 = pending_buf_next[48];
    pending_buf_next49 = pending_buf_next[49];
    pending_buf_next50 = pending_buf_next[50];
    pending_buf_next51 = pending_buf_next[51];
    pending_buf_next52 = pending_buf_next[52];
    pending_buf_next53 = pending_buf_next[53];
    pending_buf_next54 = pending_buf_next[54];
    pending_buf_next55 = pending_buf_next[55];
    pending_buf_next56 = pending_buf_next[56];
    pending_buf_next57 = pending_buf_next[57];
    pending_buf_next58 = pending_buf_next[58];
    pending_buf_next59 = pending_buf_next[59];
    pending_buf_next60 = pending_buf_next[60];
    pending_buf_next61 = pending_buf_next[61];
    pending_buf_next62 = pending_buf_next[62];
    pending_buf_next63 = pending_buf_next[63];
  end


endmodule
