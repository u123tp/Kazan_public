//
// VIPT CacheのCache Core.
//
//
// ・仮想アドレス
//                                                  2              0
//  ------------------------------------------------------------------
//  |                |   set_index  |    dw_idx    |   dw_offset     |
//  ------------------------------------------------------------------
//                                   <---------cl_offset------------>
//
//
// ・物理アドレス
//  55                 12 11           6 5            3 2              0
//  ----------------------------------------------------------------------
//  |      tag           |   set_index  |    dw_idx    |      dw_offset  |
//  ----------------------------------------------------------------------
//                                        <---------cl_offset------------>
//
// VIPTではキャッシュラインをdw単位で分割し,更にway単位で分割.
// PIPTではキャッシュラインをdw単位で分割.
// 
// 
// CBへのアクセスの種類は4つ
// ・読み込み => read from upper,write-back
// ・書き込み => write from upper, transfer from is
// どちらも前にあるもののほうが優先度は高い.
// 
// データは以下の様に遷移する.
// 一度_organizedを経由するのは,always_ffでbramの読み取りを行うときに[NUM_OF_DW_IN_CL][NUM_OF_CB_READ_PORT]の形である必要があるから.
// cb_port.read_req 
// => read_req_organized
// ==(クロック立ち上がり)==> cb_read_result(cbから読み出したデータ本体), cb_info_result(cb_infoから読み出した対応するメタデータ)
// => res_out, tmb, mshr,...
//
// ここで, cb_port.read_req自体を[NUM_OF_DW_IN_CL][NUM_OF_CB_READ_PORT]にしないのは,cb_port.read_reqの数が
// cb_infoの読み込みポート数等の制約も同時に受けるため.cb_infoの読み込みポート数のほうが少ないので,cb_port.read_reqを
// [NUM_OF_DW_IN_CL][NUM_OF_CB_READ_PORT]にすると常にそれなりの数の遊びが出てしまう.
// ただ,[NUM_OF_DW_IN_CL][NUM_OF_CB_READ_PORT]にすると順番の情報が失われる


`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"




module CacheCB
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
#(
    // WRITEのリクエスト数とREADのリクエスト数
    // CB本体のreadポートとwriteポートの数でもある.
    parameter int unsigned NUM_OF_CB_READ_REQ  = 2,
    parameter int unsigned NUM_OF_CB_WRITE_REQ = 1,


    parameter int unsigned MSHR_SIZE = 8,
    parameter int unsigned CL_SIZE   = 64,

    parameter int unsigned NUM_OF_WAYS = 4,
    parameter int unsigned NUM_OF_SETS = 64,

    parameter int unsigned REQ_TO_TLB   = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ,
    parameter int unsigned RES_FROM_TLB = NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ,

    parameter int unsigned CACHE_CAT = 0
) (
    input logic clock,
    input logic reset,

    cache_cb_if.cache_buffer cb_port,

    output tlb_req_t req_to_tlb  [  REQ_TO_TLB],
    input  tlb_res_t res_from_tlb[RES_FROM_TLB]
);

  // ---------------------------------------------------------
  // パラメータ
  // --------------------------------------------------------
  // MSHR
  localparam int unsigned MSHR_IDX_WIDTH = $clog2(MSHR_SIZE);

  // ------------------------------------------------------
  // ポート数
  // -------------------------------------------------------
  // cb_infoへの1サイクルあたりの問い合わせ数
  // 今回はリクエストが最大でも2R+1Wしか無いので
  localparam int unsigned NUM_OF_REQ = NUM_OF_CB_WRITE_REQ + NUM_OF_CB_READ_REQ;

  localparam int unsigned NUM_OF_TLB_PORT = NUM_OF_REQ;


  // cb_info ポート数
  // read_reqとwrite_reqの数の合計はNUM_OF_REQ, それに毎サイクル1つallocate_req用に用意する.
  localparam int unsigned NUM_OF_CB_INFO_READ_PORT = NUM_OF_REQ + 1;
  // write_bufからの書き込み時に更新する.あと,allocate_req用
  localparam int unsigned NUM_OF_CB_INFO_WRITE_PORT = NUM_OF_CB_WRITE_REQ + 1;

  localparam int unsigned NUM_OF_DW_IN_CL = CL_SIZE / DW_SIZE;


  localparam int unsigned CACHE_RAM_IDX_WIDTH = $clog2(NUM_OF_SETS) + $clog2(NUM_OF_DW_IN_CL);


  // ------------------------------------------------------------
  // 物理アドレスの分解用パラメータ
  // ------------------------------------------------------------

  // DW_OFFSET
  localparam int unsigned DW_OFFSET_WIDTH = $clog2(DW_SIZE);
  localparam int unsigned DW_OFFSET_MSB = DW_OFFSET_WIDTH - 1;
  localparam int unsigned DW_OFFSET_LSB = 0;

  // DW_IN_CL_IDX
  localparam int unsigned DW_IN_CL_IDX_WIDTH = $clog2(NUM_OF_DW_IN_CL);
  localparam int unsigned DW_IN_CL_IDX_MSB = DW_IN_CL_IDX_WIDTH + DW_OFFSET_WIDTH - 1;
  localparam int unsigned DW_IN_CL_IDX_LSB = DW_OFFSET_WIDTH;

  // SET_IDX
  localparam int unsigned SET_IDX_WIDTH = $clog2(NUM_OF_SETS);
  localparam int unsigned SET_IDX_MSB = SET_IDX_WIDTH + DW_IN_CL_IDX_WIDTH + DW_OFFSET_WIDTH - 1;
  localparam int unsigned SET_IDX_LSB = DW_IN_CL_IDX_WIDTH + DW_OFFSET_WIDTH;

  // TAG
  localparam int unsigned TAG_WIDTH = PADDR_WIDTH - SET_IDX_WIDTH - DW_IN_CL_IDX_WIDTH - DW_OFFSET_WIDTH;
  localparam int unsigned TAG_MSB = PADDR_WIDTH - 1;
  localparam int unsigned TAG_LSB = SET_IDX_WIDTH + DW_IN_CL_IDX_WIDTH + DW_OFFSET_WIDTH;

  localparam int unsigned WAY_IDX_WIDTH = $clog2(NUM_OF_WAYS);

  // Cache Line
  localparam int unsigned CL_OFFSET_WIDTH = $clog2(CL_SIZE);
  localparam int unsigned CL_OFFSET_LSB = 0;
  localparam int unsigned CL_OFFSET_MSB = CL_OFFSET_WIDTH - 1;

  // Cache Line サイズで整列させられたpaddrのスライス用パラメータ.
  localparam int unsigned CL_ALIGNED_PADDR_MSB = PADDR_WIDTH - 1;
  localparam int unsigned CL_ALIGNED_PADDR_LSB = CL_OFFSET_WIDTH;

  // --------------------------------------------------------------------------------------
  // cb_info
  // --------------------------------------------------------------------------------------
  // cb_infoの読み書きのポート数について,
  // 読み込み => 毎ターンのリクエスト3つ分の読み込み.
  // 書き込み => write_reqがwrite_bufに入るたびに,paddr,tag,dirtyを更新する.
  //
  // MSHRにエントリが確保されるときにcb_infoを確保すると,最大でリクエストの数だけ同時に新たなcb_infoを確保する必要がある
  // これはcb_infoの書き込みポートの数を超えるため,行えない.
  // よって,write_bufによって初めて書き込まるときにcb_infoの更新を行う.
  // MSHRにエントリを確保してからcb_infoの更新が起こるまでにアクセスされたら駄目ではないかという疑問が起こるが,
  // それはprocessing tableで処理中のフラグを立てといてアクセスしないようにしておけば大丈夫だろう.
  // つまり,processing tableに指定されているcbエントリに対応するcb_infoの情報は参照してはならない.
  //

  // cb_validとことなり,cb_infoは大きいのでlvtramで製作する.
  typedef struct packed {
    logic valid;
    logic [TAG_WIDTH-1:0] tag;
    // dirtyが1なら,ストア命令で新たにdataが上書きされてるので,上書きされるときにwrite-backする.
    logic dirty;
  } cb_info_t;

  // cache buffer のメタ情報管理体
  // ポート幅len(cb_info_t) * 深さNUM_OF_SETS の 3R+1W のramを NUM_OF_WAYS個用意する.
  logic cb_info_r_en[NUM_OF_CB_INFO_READ_PORT];
  logic [SET_IDX_WIDTH-1:0] cb_info_r_ram_idx[NUM_OF_CB_INFO_READ_PORT];
  logic [$bits(cb_info_t)-1:0] cb_info_r_bit_data[NUM_OF_WAYS][NUM_OF_CB_INFO_READ_PORT];

  logic cb_info_w_en[NUM_OF_WAYS][NUM_OF_CB_INFO_WRITE_PORT];
  logic [SET_IDX_WIDTH-1:0] cb_info_w_ram_idx[NUM_OF_WAYS][NUM_OF_CB_INFO_WRITE_PORT];
  logic [$bits(cb_info_t)-1:0] cb_info_w_bit_data[NUM_OF_WAYS][NUM_OF_CB_INFO_WRITE_PORT];
  logic [$bits(cb_info_t)/8-1:0] cb_info_w_mask[NUM_OF_WAYS][NUM_OF_CB_INFO_WRITE_PORT];

  // lvtramの入力系がbit列なので構造体を扱う場合は変換が必要.
  // ビット列のcb_info_r_bit_dataに対して,こちらは構造体の形になっている.
  cb_info_t cb_info_r_data[NUM_OF_WAYS][NUM_OF_CB_INFO_READ_PORT];
  cb_info_t cb_info_w_data[NUM_OF_WAYS][NUM_OF_CB_INFO_WRITE_PORT];

  always_comb begin
    for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
      for (int unsigned port_idx = 0; port_idx < NUM_OF_CB_INFO_READ_PORT; port_idx++) begin
        cb_info_r_data[way_idx][port_idx] = cb_info_t'(cb_info_r_bit_data[way_idx][port_idx]);
      end
    end

    for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
      for (int unsigned port_idx = 0; port_idx < NUM_OF_CB_INFO_WRITE_PORT; port_idx++) begin
        cb_info_w_bit_data[way_idx][port_idx] = cb_info_w_data[way_idx][port_idx];
      end
    end

    for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
      for (int unsigned j = 0; j < NUM_OF_CB_INFO_WRITE_PORT; j++) begin
        cb_info_w_mask[i][j] = {($bits(cb_info_t) / 8) {1'b1}};
      end
    end
  end


  // 指定したset_idxに対して,すべてのwayでcb_infoを取り出すので,wayごとにバンク化し,
  // すべてのバンクでset_idxに対応する情報を得るため,すべてのバンクに対して同じread命令を送る.
  // 一方で,write命令ではどれか一つのwayしか更新しないため,更新するwayでのみcb_info_w_en[way_idx]を1にする.
  genvar cb_info_gen_way_idx;
  generate
    for (cb_info_gen_way_idx = 0; cb_info_gen_way_idx < NUM_OF_WAYS; cb_info_gen_way_idx++) begin
      LVTRAM #(
          .RAM_WIDTH($bits(cb_info_t)),
          .RAM_DEPTH(NUM_OF_SETS),
          .NUM_OF_READ_PORT(NUM_OF_CB_INFO_READ_PORT),
          .NUM_OF_WRITE_PORT(NUM_OF_CB_INFO_WRITE_PORT)
      ) cb_info (
          .clock(clock),
          .reset(reset),
          .r_en(cb_info_r_en),
          .r_ram_idx(cb_info_r_ram_idx),
          .r_data(cb_info_r_bit_data[cb_info_gen_way_idx]),
          .w_en(cb_info_w_en[cb_info_gen_way_idx]),
          .w_ram_idx(cb_info_w_ram_idx[cb_info_gen_way_idx]),
          .w_data(cb_info_w_bit_data[cb_info_gen_way_idx]),
          .w_mask(cb_info_w_mask[cb_info_gen_way_idx])
      );
    end
  endgenerate

  // ----------------------------------------------------------------------------------------------
  // cb_data
  // ----------------------------------------------------------------------------------------------
  // 幅が8Byte * 深さがNUM_OF_SETS*NUM_OF_DW_IN_CL の 2R+1W のramを NUM_OF_WAYS だけ用意する.
  // cb[way_idx][set_idx*NUM_OF_DW_IN_CL+dw_in_cl_idx] でアクセスする.

  logic cb_data_r_en[NUM_OF_CB_READ_REQ];
  logic [SET_IDX_WIDTH+DW_IN_CL_IDX_WIDTH-1:0] cb_data_r_ram_idx[NUM_OF_CB_READ_REQ];
  logic [DW_SIZE*8-1:0] cb_data_r_data[NUM_OF_WAYS][NUM_OF_CB_READ_REQ];

  logic cb_data_w_en[NUM_OF_WAYS][NUM_OF_CB_WRITE_REQ];
  logic [SET_IDX_WIDTH+DW_IN_CL_IDX_WIDTH-1:0] cb_data_w_ram_idx[NUM_OF_WAYS][NUM_OF_CB_WRITE_REQ];
  logic [DW_SIZE*8-1:0] cb_data_w_data[NUM_OF_WAYS][NUM_OF_CB_WRITE_REQ];
  logic [DW_SIZE-1:0] cb_data_w_mask[NUM_OF_WAYS][NUM_OF_CB_WRITE_REQ];

  genvar cb_gen_way_idx;
  generate
    for (cb_gen_way_idx = 0; cb_gen_way_idx < NUM_OF_WAYS; cb_gen_way_idx++) begin
      LVTRAM #(
          .RAM_WIDTH(DW_SIZE * 8),
          .RAM_DEPTH(NUM_OF_SETS * NUM_OF_DW_IN_CL),
          .NUM_OF_READ_PORT(NUM_OF_CB_READ_REQ),
          .NUM_OF_WRITE_PORT(NUM_OF_CB_WRITE_REQ)
      ) cb_data (
          .clock(clock),
          .reset(reset),
          .r_en(cb_data_r_en),
          .r_ram_idx(cb_data_r_ram_idx),
          .r_data(cb_data_r_data[cb_gen_way_idx]),
          .w_en(cb_data_w_en[cb_gen_way_idx]),
          .w_ram_idx(cb_data_w_ram_idx[cb_gen_way_idx]),
          .w_data(cb_data_w_data[cb_gen_way_idx]),
          .w_mask(cb_data_w_mask[cb_gen_way_idx])
      );
    end

  endgenerate


  // ----------------------------------------------------
  // plru-tree
  // ----------------------------------------------------
  // plru本体
  logic [NUM_OF_WAYS-1:0] plru_tree[NUM_OF_SETS];
  logic [NUM_OF_WAYS-1:0] plru_tree_next[NUM_OF_SETS];
  // plru_treeの操作用のライブラリ.
  TREE_PLRU_FUNC #(.NUM_OF_WAYS(NUM_OF_WAYS)) plru_util ();

  // 今の実装では2つのalways_combのブロックがある.cbへのリクエストと,
  // cbからのリクエストである.2つを統合するとcicularになったりするので面倒.



  // -------------------------------------------------------------------
  // 結果を TLB miss buf, MSHR,等に振り分けるために一時的に用意する変数.
  // -------------------------------------------------------------------
  // 前のサイクルで出したリクエスト.
  cache_req_t read_req_prev[NUM_OF_CB_READ_REQ];
  cache_req_t write_req_prev[NUM_OF_CB_WRITE_REQ];

  // 新しくwayを確保するためのreqを一時的に保存する.
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_cl_aligned;
    logic [MSHR_IDX_WIDTH-1:0] mshr_idx;
    logic [SET_IDX_WIDTH-1:0] set_idx;
  } allocate_req_t;
  allocate_req_t allocate_req_prev;
  // 新しく確保されたwayを一時的に保存
  logic [WAY_IDX_WIDTH-1:0] allocated_way;
  logic [WAY_IDX_WIDTH-1:0] allocated_way_prev;



  // ---------------------------------------------------------
  // write_buf
  // ---------------------------------------------------------
  // 次のサイクルで実際にcbへ書き込みを行う内容とその対象となる場所.
  typedef struct packed {
    logic valid;

    // マスクを行うために必要.
    req_policy_e  req_policy;
    // cb_infoのdirtyを更新するために必要
    cb_req_type_e cb_req_type;

    logic [TAG_WIDTH-1:0] tag;
    logic [DW_IN_CL_IDX_WIDTH-1:0] dw_in_cl_idx;
    logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx;

    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
    logic [63:0] data;
  } write_buf_t;

  write_buf_t write_buf[NUM_OF_CB_WRITE_REQ];
  // write_buf_t write_buf_next[NUM_OF_CB_WRITE_REQ];

  // ---------------------------------------------------------------------
  // invalidate_
  // ----------------------------------------------------------------------
  typedef struct packed {
    logic valid;
    logic [MSHR_IDX_WIDTH-1:0] invalidate_buf_idx;
    logic [SET_IDX_WIDTH-1:0] set_idx;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
  } invalidate_get_info_req_t;


  invalidate_get_info_req_t invalidate_get_info_req_prev;


  // -------------------------------------------------------------
  // tlb_port.res の中に引数のidを持った結果が含まれているかを確認
  // -------------------------------------------------------------
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr;
  } tlb_search_result_t;

  typedef struct packed {
    logic valid;
    logic [WAY_IDX_WIDTH-1:0] way_idx;
  } way_search_result_t;


  function automatic tlb_search_result_t tlb_res_search_by_id(int unsigned id,
                                                              int unsigned generation);
    tlb_search_result_t tlb_search_result = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_TLB_PORT; i++) begin
      if (res_from_tlb[i].valid && res_from_tlb[i].id == id && res_from_tlb[i].generation == generation) begin
        tlb_search_result.valid = 1;
        tlb_search_result.paddr = res_from_tlb[i].paddr;
      end
    end
    return tlb_search_result;

  endfunction




  // -------------------------------------------------------------------
  // paddrのアライメント用関数
  // -------------------------------------------------------------------

  function automatic logic [PADDR_WIDTH-1:0] to_cl_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] original_paddr);
    return {original_paddr[PADDR_WIDTH-1:CL_OFFSET_WIDTH], CL_OFFSET_WIDTH'(1'b0)};
  endfunction

  function automatic logic [PADDR_WIDTH-1:0] to_dw_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] original_paddr);
    return {original_paddr[PADDR_WIDTH-1:$clog2(DW_SIZE)], $clog2(DW_SIZE)'(1'b0)};
  endfunction



  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // tlb, cb_info, cb_data への入力.
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // icache,dcacheにおけるtlb_idについて
  // availqに入っているreqはcb_req_typeで４つに分けられるが,そのうち,READ_WRITE_BACK,WRITE_UPDATEの２つは
  // 必ずpaddr_valid==1であるため,tlb_idは不要.残りのREAD_REQ_FROM_UPPER,WRITE_REQ_FROM_UPPERはcache_reqのidに合わせて於けば
  // 自然と一意になる.(ただし,itlbとdtlbの間で調停は必要)
  // l2cacheではそもそも全てpaddr_valid==1であるため気にする必要は無い.
  always_comb begin
    req_to_tlb = '{default: 0};


    // cb_info, cb_data, tlb_portの初期化.
    cb_info_r_en = '{default: 0};
    cb_info_r_ram_idx = '{default: 0};

    cb_data_r_en = '{default: 0};
    cb_data_r_ram_idx = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
      cb_data_w_en[i] = '{default: 0};
      cb_data_w_ram_idx[i] = '{default: 0};
      cb_data_w_data[i] = '{default: 0};
      cb_data_w_mask[i] = '{default: 0};
    end

    for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
      for (int unsigned j = 0; j < NUM_OF_CB_WRITE_REQ; j++) begin
        cb_info_w_en[i][j] = 0;
        cb_info_w_ram_idx[i][j] = 0;
        cb_info_w_data[i][j] = '{default: 0};
      end
    end


    // --------------------------------------------------------------------------------
    // cb_port.read_req
    // => cb_data_r_en, cb_data_r_ram_idx, cb_info_r_en, cb_info_r_ram_idx, 
    // --------------------------------------------------------------------------------
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      if (cb_port.read_req[i].valid) begin
        // cb_info
        cb_info_r_en[i] = 1;
        cb_info_r_ram_idx[i] = cb_port.read_req[i].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];
        // cb本体.
        cb_data_r_en[i] = 1;
        cb_data_r_ram_idx[i] = CACHE_RAM_IDX_WIDTH'(cb_port.read_req[i].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB]*NUM_OF_DW_IN_CL) + 
                        CACHE_RAM_IDX_WIDTH'(cb_port.read_req[i].paddr_dw_aligned[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB]);

        // paddrが判明していなければtlbに突っ込む.
        if (!cb_port.read_req[i].paddr_valid) begin
          req_to_tlb[i] = '{
              valid: 1,
              id: cb_port.read_req[i].id,
              id_sub: 1,
              generation: cb_port.read_req[i].generation,
              satp: cb_port.read_req[i].satp,
              vaddr: cb_port.read_req[i].vaddr_dw_aligned
          };
        end
      end
    end

    // --------------------------------------------------------------------------------
    // cb_port.write_req
    // => cb_info_r_en, cb_info_r_ram_idx
    // --------------------------------------------------------------------------------
    // cb_port.write_reqからcb本体のlvtramの入力の形に整える.
    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      if (cb_port.write_req[i].valid) begin
        // cb_info
        cb_info_r_en[NUM_OF_CB_READ_REQ+i] = 1;
        cb_info_r_ram_idx[NUM_OF_CB_READ_REQ+i] = cb_port.write_req[i].paddr_dw_aligned[SET_IDX_MSB:SET_IDX_LSB];

        // paddrが判明していなければtlbに突っ込む.
        if (!cb_port.write_req[i].paddr_valid) begin
          req_to_tlb[NUM_OF_CB_READ_REQ+i] = '{
              valid: 1,
              id: cb_port.write_req[i].id,
              id_sub: 1,
              generation: cb_port.read_req[i].generation,
              satp: cb_port.write_req[i].satp,
              vaddr: cb_port.write_req[i].vaddr_dw_aligned
          };
        end
      end
    end

    // --------------------------------------------------------------------------------
    // cb_port.allocate_req => cb_info_r_en, cb_info_r_ram_idx
    // --------------------------------------------------------------------------------
    // 指定されたmshrに対応する新しいキャッシュラインを確保する
    if (cb_port.allocate_req.valid) begin
      // 最も古いwayを取得し,plru_treeを更新
      // 一回だけなのでこのような実装だが,2つ以上を同時にallocateするなら二番目に古いものを探索する関数がいる.
      allocated_way = plru_util.search_oldest(plru_tree[cb_port.allocate_req.set_idx]);
      // cb_infoの読み込み.
      cb_info_r_en[NUM_OF_REQ] = 1'b1;
      cb_info_r_ram_idx[NUM_OF_REQ] = cb_port.allocate_req.set_idx;

    end else begin
      allocated_way = 0;
    end



    // --------------------------------------------------------------------------------
    // write_buf => cb_data_w_en, cb_data_w_ram_idx, cb_data_w_data
    //              cb_info_w_en, cb_info_w_ram_idx, cb_info_w_ram_idx
    // --------------------------------------------------------------------------------
    // 書き込みの実行.
    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      int write_length = 0;
      if (write_buf[i].valid) begin
        // $display("CACHE_CAT: %d", CACHE_CAT);
        // $display("write_buf[%0d] = {", i);
        // $display("  valid          = %0b", write_buf[i].valid);
        // $display("  req_policy     = %0d", write_buf[i].req_policy);
        // $display("  cb_req_type    = %0d", write_buf[i].cb_req_type);
        // $display("  tag            = %h", write_buf[i].tag);
        // $display("  dw_in_cl_idx   = %0d", write_buf[i].dw_in_cl_idx);
        // $display("  byte_in_dw_idx = %0d", write_buf[i].byte_in_dw_idx);
        // $display("  set_idx        = %0d", write_buf[i].set_idx);
        // $display("  way_idx        = %0d", write_buf[i].way_idx);
        // $display("  data           = %h", write_buf[i].data);
        // $display("}");

        // cb本体への書き込み.
        cb_data_w_en[write_buf[i].way_idx][i] = 1;
        cb_data_w_ram_idx[write_buf[i].way_idx][i] = CACHE_RAM_IDX_WIDTH'(write_buf[i].set_idx * NUM_OF_DW_IN_CL) + 
                                                CACHE_RAM_IDX_WIDTH'(write_buf[i].dw_in_cl_idx);
        cb_data_w_data[write_buf[i].way_idx][i] = write_buf[i].data;

        // マスクの製作.
        cb_data_w_mask[write_buf[i].way_idx][i] = 8'b0000_0000;
        case (write_buf[i].req_policy)
          WRITE_BYTE: write_length = 1;
          WRITE_HALF_WORD: write_length = 2;
          WRITE_WORD: write_length = 4;
          WRITE_DOUBLE_WORD: write_length = 8;
          default: write_length = 8;
        endcase
        for (int unsigned j = 0; j < write_length; j++) begin
          cb_data_w_mask[write_buf[i].way_idx][i][write_buf[i].byte_in_dw_idx+$clog2(DW_SIZE)'(j)] =
              1'b1;
        end

        // cb_infoの更新はwrite_bufで書き込むときに行う.
        // そのclに対して最後の書き込みがupperからのrequestなら書き戻す必要があるのでdirtyとする.
        cb_info_w_en[write_buf[i].way_idx][i] = 1;
        cb_info_w_ram_idx[write_buf[i].way_idx][i] = write_buf[i].set_idx;
        // TODO: 1を0で上書きする可能性はないか？write_updateがおこなわれたあとにwrite_req_from_upperとなる可能性が高い？
        cb_info_w_data[write_buf[i].way_idx][i] = '{
            valid: 1,
            tag: write_buf[i].tag,
            dirty: write_buf[i].cb_req_type == WRITE_REQ_FROM_UPPER ? 1 : 0
        };
      end
    end

    // --------------------------------------------------------------------------------
    // cb_port.invalidate_get_info_req => cb_info_r_**
    // cb_port.invalidate_req => cb_info_w_**
    // --------------------------------------------------------------------------------
    // cb_port.invalidate_get_info_req => cb_info
    // cacheがinvalidate_allのモードでは,基本的に読み込み処理(cb_port.read_req)しか使用しない為,
    // cb_port.write_reqに対応するcb_infoの読み込みポートが空いてるのでそれを使用する.
    if (cb_port.invalidate_get_info_req.valid) begin
      cb_info_r_en[NUM_OF_CB_READ_REQ] = 1;
      cb_info_r_ram_idx[NUM_OF_CB_READ_REQ] = cb_port.invalidate_get_info_req.set_idx;
    end

    // invalidate_reqで実際にエントリを削除する.
    // これについても,本来だったらwrite_bufが使用するcb_info_wを使用する.
    if (cb_port.invalidate_req.valid) begin
      cb_info_w_en[cb_port.invalidate_req.way_idx][0] = 1;
      cb_info_w_ram_idx[cb_port.invalidate_req.way_idx][0] = cb_port.invalidate_req.set_idx;
      cb_info_w_data[cb_port.invalidate_req.way_idx][0] = '{valid: 0, tag: 0, dirty: 0};

    end

  end


  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // tlb, cb_data,cb_infoから読み込んだデータの振り分け.
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  always_comb begin
    // res_to_wbb, res_out, res_to_mshr, res_to_tmbの初期化
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      cb_port.res_to_wbb[i] = '{
          default: 0,
          cb_req_type: CB_REQ_TYPE_NONE,
          req_policy: REQ_POLICY_NONE
      };
      cb_port.res_out[i] = '{
          default: 0,
          cb_req_type: CB_REQ_TYPE_NONE,
          req_policy: REQ_POLICY_NONE
      };
    end
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ + NUM_OF_CB_WRITE_REQ; i++) begin
      cb_port.res_to_tmb[i] = '{
          default: 0,
          cb_req_type: CB_REQ_TYPE_NONE,
          req_policy: REQ_POLICY_NONE
      };
      cb_port.res_to_mshr[i] = '{
          default: 0,
          cb_req_type: CB_REQ_TYPE_NONE,
          req_policy: REQ_POLICY_NONE
      };
      cb_port.mshr_new_state[i] = '{default: 0, state_per_dw : STATE_PER_DW_NONE};
    end
    cb_port.allocate_res = '{default: 0};


    plru_tree_next = plru_tree;

    // write_buf_next の初期化
    write_buf = '{default: 0};

    // ------------------------------------------------------------------------------
    // read_req_prev => res_to_tmb, res_to_mshr, res_out, res_to_wbb
    // ------------------------------------------------------------------------------
    for (int unsigned i = 0; i < NUM_OF_CB_READ_REQ; i++) begin
      tlb_search_result_t tlb_search_result = tlb_res_search_by_id(
          read_req_prev[i].id, read_req_prev[i].generation
      );
      logic read_req_paddr_valid = 0;
      logic [PADDR_WIDTH-1:0] read_req_paddr = 0;
      way_search_result_t way_search_result = '{default: 0};
      logic is_processing = 0;
      int unsigned ld_data_length = 0;
      logic is_signed_extension = 0;
      logic [XLEN-1:0] ld_data = 0;

      // => paddrが有効か,そしてそのpaddrの値
      if (read_req_prev[i].paddr_valid) begin
        read_req_paddr_valid = 1;
        read_req_paddr = read_req_prev[i].paddr_dw_aligned;
      end else if (tlb_search_result.valid) begin
        read_req_paddr_valid = 1;
        read_req_paddr = tlb_search_result.paddr;
      end

      // 有効なエントリのうちタグに一致するものが存在するか.
      for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
        if (read_req_paddr[TAG_MSB:TAG_LSB] == cb_info_r_data[way_idx][i].tag && cb_info_r_data[way_idx][i].valid) begin
          way_search_result = '{valid: 1, way_idx: WAY_IDX_WIDTH'(way_idx)};
          // plru_treeのアップデート
          plru_tree_next[read_req_paddr[SET_IDX_MSB:SET_IDX_LSB]] = plru_util.update_plru_tree(
              plru_tree_next[read_req_paddr[SET_IDX_MSB:SET_IDX_LSB]], WAY_IDX_WIDTH'(way_idx));
        end
      end

      // mshrで処理中かの判定.
      for (int unsigned j = 0; j < MSHR_SIZE; j++) begin
        if (cb_port.mshr_processing_info[j].valid && !cb_port.mshr_processing_info[j].is_all_dw_updated &&
          cb_port.mshr_processing_info[j].paddr_cl_aligned == to_cl_aligned_paddr(
                read_req_paddr
            )) begin
          is_processing = 1;
        end
      end

      // req_policyに基づいて,拡張したりしてld_dataを作成する.
      // verilogはスライスが定数でないと駄目なので,一つひとつやってく.
      // 拡張はCache.svで,bypassdataとマージした後にやるのでここでは切り出すだけ.
      ld_data = '0;
      case (read_req_prev[i].req_policy)
        READ_BYTE: begin
          ld_data[read_req_prev[i].byte_in_dw_idx*8+:8] = 8'
              ($signed(
               cb_data_r_data[way_search_result.way_idx][i][read_req_prev[i].byte_in_dw_idx*8+:8]));
        end
        READ_HALF_WORD: begin
          ld_data[read_req_prev[i].byte_in_dw_idx*8+:16] =
              16'($signed(cb_data_r_data[way_search_result.way_idx][i][
                          read_req_prev[i].byte_in_dw_idx*8+:16]));
        end
        READ_WORD: begin
          ld_data[read_req_prev[i].byte_in_dw_idx*8+:32] =
              32'($signed(cb_data_r_data[way_search_result.way_idx][i][
                          read_req_prev[i].byte_in_dw_idx*8+:32]));
        end
        READ_DOUBLE_WORD: begin
          ld_data = cb_data_r_data[way_search_result.way_idx][i];
        end
        default: ;
      endcase


      if (read_req_prev[i].valid) begin
        if (read_req_prev[i].cb_req_type == READ_WRITE_BACK) begin
          // Write-Backの為に読み込んだ場合,res_to_wbb
          // すでにpaddrが判明しているので,tlbのミスはありえない,
          // またキャッシュラインの確保もされているのでタグが必ずヒットする.
          cb_port.res_to_wbb[i] = '{
              valid: 1,
              id: read_req_prev[i].id,
              id_sub: read_req_prev[i].id_sub,
              generation: read_req_prev[i].generation,
              is_page_fault: 0,
              is_access_fault: 0,
              req_policy: read_req_prev[i].req_policy,
              cb_req_type: read_req_prev[i].cb_req_type,
              vaddr_dw_aligned: read_req_prev[i].vaddr_dw_aligned,
              paddr_dw_aligned: read_req_prev[i].paddr_dw_aligned,
              byte_in_dw_idx: read_req_prev[i].byte_in_dw_idx,
              data: ld_data
          };
          cb_port.mshr_new_state[i] = '{
              valid: 1,
              paddr_cl_aligned: to_cl_aligned_paddr(read_req_prev[i].paddr_dw_aligned),
              dw_in_cl_idx: read_req_prev[i].paddr_dw_aligned[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB],
              state_per_dw: BEFORE_REQUEST
          };
        end else if (read_req_paddr_valid && way_search_result.valid && !is_processing) begin
          // タグがヒットするものが存在して,かつそれがmshrで処理中でないならres_out
          cb_port.res_out[i] = '{
              valid: 1,
              id: read_req_prev[i].id,
              id_sub: read_req_prev[i].id_sub,
              generation: read_req_prev[i].generation,
              is_page_fault: 0,
              is_access_fault: 0,
              req_policy: read_req_prev[i].req_policy,
              cb_req_type: read_req_prev[i].cb_req_type,
              vaddr_dw_aligned: read_req_prev[i].vaddr_dw_aligned,
              paddr_dw_aligned: read_req_prev[i].paddr_dw_aligned,
              byte_in_dw_idx: read_req_prev[i].byte_in_dw_idx,
              data: ld_data
          };
        end else if (read_req_paddr_valid) begin
          // タグがヒットするものが存在するが,それがmshrに存在する(=処理中),
          // あるいはそもそもタグがヒットするものが存在しなかった場合はres_to_mshr
          cb_port.res_to_mshr[i] = read_req_prev[i];
          if (!read_req_prev[i].paddr_valid) begin
            // paddrが分かっていなかったが,tlbからの返却で初めて分かった場合はそれを反映
            cb_port.res_to_mshr[i].paddr_valid = 1;
            cb_port.res_to_mshr[i].paddr_dw_aligned = tlb_search_result.paddr;
          end

        end else begin
          // tlbからpaddrが帰ってきてないのでタグ比較ができないものはres_to_tmb
          cb_port.res_to_tmb[i] = read_req_prev[i];
        end
      end

    end

    // -----------------------------------------------------------------------------
    // write_req_prev => res_to_tmb, res_to_mshr, res_to_wbb, mshr_new_state
    // -----------------------------------------------------------------------------
    for (int unsigned i = 0; i < NUM_OF_CB_WRITE_REQ; i++) begin
      tlb_search_result_t tlb_search_result = tlb_res_search_by_id(
          write_req_prev[i].id, write_req_prev[i].generation
      );
      logic write_req_paddr_valid = 0;
      logic [PADDR_WIDTH-1:0] write_req_paddr = 0;
      way_search_result_t way_search_result = '{default: 0};
      logic is_processing = 0;

      // => paddrが有効か,そしてそのpaddrの値
      if (write_req_prev[i].paddr_valid) begin
        write_req_paddr_valid = 1;
        write_req_paddr = write_req_prev[i].paddr_dw_aligned;
      end else if (tlb_search_result.valid) begin
        write_req_paddr_valid = 1;
        write_req_paddr = tlb_search_result.paddr;
      end

      // 有効なエントリのうちタグに一致するものが存在するか.
      for (int unsigned way_idx = 0; way_idx < NUM_OF_WAYS; way_idx++) begin
        if (write_req_paddr[TAG_MSB:TAG_LSB] == cb_info_r_data[way_idx][NUM_OF_CB_READ_REQ+i].tag && 
            cb_info_r_data[way_idx][NUM_OF_CB_READ_REQ+i].valid) begin
          way_search_result = '{valid: 1, way_idx: WAY_IDX_WIDTH'(way_idx)};
          plru_tree_next[write_req_paddr[SET_IDX_MSB:SET_IDX_LSB]] = plru_util.update_plru_tree(
              plru_tree_next[write_req_paddr[SET_IDX_MSB:SET_IDX_LSB]], WAY_IDX_WIDTH'(way_idx));
        end
      end

      // mshrで処理中かの判定.
      for (int unsigned j = 0; j < MSHR_SIZE; j++) begin
        if (cb_port.mshr_processing_info[j].valid &&  !cb_port.mshr_processing_info[j].is_all_dw_updated &&
            cb_port.mshr_processing_info[j].paddr_cl_aligned == to_cl_aligned_paddr(
                write_req_paddr
            )) begin
          is_processing = 1;
        end
      end


      if (write_req_prev[i].valid) begin

        if (write_req_prev[i].cb_req_type == WRITE_UPDATE) begin
          // 下位レイヤからのUPDATE用のデータが帰ってきたので書き込む.
          // mshr_new_stateで state_per_dwを DURING_REQUESTからCB_UPDATEDに
          cb_port.mshr_new_state[NUM_OF_CB_READ_REQ+i] = '{
              valid: 1,
              paddr_cl_aligned: to_cl_aligned_paddr(write_req_prev[i].paddr_dw_aligned),
              dw_in_cl_idx: write_req_prev[i].paddr_dw_aligned[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB],
              state_per_dw: CB_UPDATED
          };
          write_buf[i] = '{
              valid: 1,
              req_policy: write_req_prev[i].req_policy,
              cb_req_type: write_req_prev[i].cb_req_type,
              tag: write_req_paddr[TAG_MSB:TAG_LSB],
              dw_in_cl_idx: write_req_paddr[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB],
              byte_in_dw_idx: write_req_prev[i].byte_in_dw_idx,
              set_idx: write_req_paddr[SET_IDX_MSB:SET_IDX_LSB],
              way_idx: way_search_result.way_idx,  //TODO
              data: write_req_prev[i].data
          };
        end else if (write_req_paddr_valid && way_search_result.valid && !is_processing) begin
          // タグがヒットするものが存在し,かつmshrで処理中で無い場合,
          // write_buf_nextに書き込んで,次のサイクルでcb_data,cb_infoに反映させる.
          write_buf[i] = '{
              valid: 1,
              req_policy: write_req_prev[i].req_policy,
              cb_req_type: write_req_prev[i].cb_req_type,
              tag: write_req_paddr[TAG_MSB:TAG_LSB],
              dw_in_cl_idx: write_req_paddr[DW_IN_CL_IDX_MSB:DW_IN_CL_IDX_LSB],
              byte_in_dw_idx: write_req_prev[i].byte_in_dw_idx,
              set_idx: write_req_paddr[SET_IDX_MSB:SET_IDX_LSB],
              way_idx: way_search_result.way_idx,  //TODO
              data: write_req_prev[i].data
          };
        end else if (write_req_paddr_valid) begin
          // タグがヒットするが,mshrで処理中の場合, mshrに追加し,
          // そもそもタグがヒットしない場合はmshrに新規追加.
          cb_port.res_to_mshr[NUM_OF_CB_READ_REQ+i] = write_req_prev[i];
          if (!write_req_prev[i].paddr_valid) begin
            // paddrが分かっていなかったが,tlbからの返却で初めて分かった場合はそれを反映
            cb_port.res_to_mshr[NUM_OF_CB_READ_REQ+i].paddr_valid = 1;
            cb_port.res_to_mshr[NUM_OF_CB_READ_REQ+i].paddr_dw_aligned = tlb_search_result.paddr;
          end
        end else begin
          // 
          cb_port.res_to_tmb[NUM_OF_CB_READ_REQ+i] = write_req_prev[i];
        end
      end
    end



    // --------------------------------------------------------------------------------
    // allocate_req_prev => cb_port.allocate_res
    // --------------------------------------------------------------------------------
    // ここで,mshrで使用中かを判別する.cb_info_r_**でリクエストを出す時に判別すると、
    // その時におけるmshr_nextの状態が反映されない.
    // 一方でここでmshrが使用中かを判別すれば, allocate_resによってmshr_nextが作られるので,
    // 反映漏れが無い.
    begin
      logic allocation_success = 1;
      // 初期化
      for (int unsigned i = 0; i < NUM_OF_WAYS; i++) begin
        cb_info_w_en[i][NUM_OF_CB_WRITE_REQ] = 0;
        cb_info_w_ram_idx[i][NUM_OF_CB_WRITE_REQ] = 0;
        cb_info_w_data[i][NUM_OF_CB_WRITE_REQ] = '{default: 0};
      end

      if (allocate_req_prev.valid) begin

        // mshrで使用済ならallocateは失敗
        for (int unsigned i = 0; i < MSHR_SIZE; i++) begin
          if(cb_port.mshr_processing_info[i].valid &&
          { cb_info_r_data[allocated_way_prev][NUM_OF_REQ].tag,
              allocate_req_prev.set_idx,
              CL_OFFSET_WIDTH'(1'b0)
          } == cb_port.mshr_processing_info[i].paddr_cl_aligned)begin
            // allocation失敗.
            allocation_success = 0;
          end
        end

        if (allocation_success) begin
          cb_port.allocate_res = '{
              valid: 1,
              success: 1,
              mshr_idx: allocate_req_prev.mshr_idx,
              way_idx: allocated_way_prev,
              wb_need: cb_info_r_data[allocated_way_prev][NUM_OF_REQ].dirty,
              // paddrはtagとset_idxから生成する.
              paddr_cl_aligned_prev: {
                cb_info_r_data[allocated_way_prev][NUM_OF_REQ].tag,
                allocate_req_prev.set_idx,
                CL_OFFSET_WIDTH'(1'b0)
              }
          };
          // cb_infoに新しいエントリを更新

          cb_info_w_en[allocated_way_prev][NUM_OF_CB_WRITE_REQ] = 1;
          cb_info_w_ram_idx[allocated_way_prev][NUM_OF_CB_WRITE_REQ] = allocate_req_prev.set_idx;
          cb_info_w_data[allocated_way_prev][NUM_OF_CB_WRITE_REQ] = '{
              valid: 1,
              tag: allocate_req_prev.paddr_cl_aligned[TAG_MSB:TAG_LSB],
              dirty: 0
          };

        end else begin
          cb_port.allocate_res = '{
              valid: 1,
              success: 0,
              mshr_idx: allocate_req_prev.mshr_idx,
              way_idx: allocated_way_prev,
              wb_need: cb_info_r_data[allocated_way_prev][NUM_OF_REQ].dirty,
              // paddrはtagとset_idxから生成する.
              paddr_cl_aligned_prev: {
                cb_info_r_data[allocated_way_prev][NUM_OF_REQ].tag,
                allocate_req_prev.set_idx,
                CL_OFFSET_WIDTH'(1'b0)
              }
          };
        end

      end
    end


    // ------------------------------------------------------------------------------
    // => cb_port.invalidate_get_info_res
    // ------------------------------------------------------------------------------

    // cb_port.resの初期化
    cb_port.invalidate_get_info_res = '{default: 0};

    // cb_info_rから読み取ったデータをcb_port.invalidate_get_info_resで返す.
    if (invalidate_get_info_req_prev.valid) begin
      cb_port.invalidate_get_info_res = '{
          valid: 1,
          paddr_cl_aligned: {
            cb_info_r_data[invalidate_get_info_req_prev.way_idx][NUM_OF_CB_READ_REQ].tag,
            invalidate_get_info_req_prev.set_idx,
            {CL_OFFSET_WIDTH{1'b0}}
          },
          invalidate_buf_idx: invalidate_get_info_req_prev.invalidate_buf_idx,
          dirty: cb_info_r_data[invalidate_get_info_req_prev.way_idx][NUM_OF_CB_READ_REQ].dirty,
          cl_valid: cb_info_r_data[invalidate_get_info_req_prev.way_idx][NUM_OF_CB_READ_REQ].valid
      };
    end


  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // req_prev
      read_req_prev <= '{default: 0};
      write_req_prev <= '{default: 0};
      allocate_req_prev <= '{default: 0};
      allocated_way_prev <= 0;


      // plru-tree
      plru_tree <= '{default: 0};

      // invalidate
      invalidate_get_info_req_prev <= 0;

    end else begin
      // req_prev
      read_req_prev <= cb_port.read_req;
      write_req_prev <= cb_port.write_req;
      allocate_req_prev <= cb_port.allocate_req;
      allocated_way_prev <= allocated_way;

      // plru-tree
      plru_tree <= plru_tree_next;

      // invalidate
      invalidate_get_info_req_prev <= cb_port.invalidate_get_info_req;

    end
  end


endmodule
