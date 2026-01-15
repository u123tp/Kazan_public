`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"
// instruction fetch queue
//
//
// -----------------------------------------------
// |                          |   FETCH_OFFSET   |
// -----------------------------------------------

module IFQ
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
(
    input logic clock,
    input logic reset,


    input cache_res_t icache_result[NUM_OF_RES_FROM_ICACHE],
    input pred_btb_result_t pred_btb_result,

    // TODO: bootloaderからのresの処理を追加.

    // Decoderに渡す内容.
    output ifq_decoder_t ifq_out[NUM_OF_FETCH],

    input  logic stall_in,
    // 次の立ち上がり時に新しい命令を入力する余裕は無いという信号.
    output logic stall_out,

    input logic flush_in,
    // predictionがヒットし,btbで飛び先の予測もついている場合,
    // flush_out をstage1に送りpcを更新, 
    output addr_with_valid_t flush_out,

    input int unsigned generation
);

  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  // cache_res_t icache_result[NUM_OF_RES_FROM_ICACHE];
  // pred_btb_result_t pred_btb_result;

  // cache_res_t icache_result_pending[NUM_OF_RES_FROM_ICACHE];
  // pred_btb_result_t pred_btb_result_pending;
  // logic is_pending;
  // cache_res_t icache_result_pending_next[NUM_OF_RES_FROM_ICACHE];
  // pred_btb_result_t pred_btb_result_pending_next;
  // logic is_pending_next;

  // always_comb begin
  //   is_pending_next = is_pending;
  //   icache_result_pending_next = icache_result_pending;
  //   pred_btb_result_pending_next = pred_btb_result_pending;

  //   if (flush_in) begin
  //     icache_result   = '{default: 0};
  //     pred_btb_result = '{default: 0};
  //     is_pending_next = 0;
  //   end else if (stall_in && !is_pending) begin
  //     // 新たにstallした場合.
  //     icache_result_pending_next = icache_result_cur;
  //     pred_btb_result_pending_next = pred_btb_result_cur;
  //     is_pending_next = 1;
  //     icache_result = '{default: 0};
  //     pred_btb_result = '{default: 0};
  //   end else if (stall_in) begin
  //     // 継続でstallした場合.
  //     icache_result   = '{default: 0};
  //     pred_btb_result = '{default: 0};
  //   end else if (is_pending) begin
  //     // stall終了時.
  //     icache_result   = icache_result_pending;
  //     pred_btb_result = pred_btb_result_pending;
  //     is_pending_next = 0;
  //   end else begin
  //     // 通常時.
  //     icache_result   = icache_result_cur;
  //     pred_btb_result = pred_btb_result_cur;
  //   end
  // end

  // --------------------------------------------
  // パラメータ
  // --------------------------------------------

  localparam int unsigned VADDR_FETCH_ALIGNED_MSB = VADDR_WIDTH - 1;
  localparam int unsigned VADDR_FETCH_ALIGNED_LSB = $clog2(4 * NUM_OF_FETCH);

  localparam int unsigned DW_IDX_IN_FETCH_WIDTH = $clog2(4 * NUM_OF_FETCH / DW_SIZE);
  localparam int unsigned DW_IDX_IN_FETCH_LSB = $clog2(DW_SIZE);
  localparam int unsigned DW_IDX_IN_FETCH_MSB = DW_IDX_IN_FETCH_LSB + DW_IDX_IN_FETCH_WIDTH - 1;

  localparam int unsigned INSTR_SIZE = 4;
  localparam int unsigned NUM_OF_INSTR_IN_DW = DW_SIZE / INSTR_SIZE;

  localparam int unsigned IFQ_SIZE = 16;
  localparam int unsigned IFQ_IDX_WIDTH = $clog2(IFQ_SIZE);

  typedef struct packed {
    logic [VADDR_WIDTH-1:0] first_instr_vaddr;  // 1つ目の命令のアドレス.
    logic [NUM_OF_FETCH-1:0][PADDR_WIDTH-1:0] instr_paddr;  // pmp用.
    int unsigned first_instr_id;
    logic [NUM_OF_FETCH-1:0] pred_taken;
    logic [NUM_OF_FETCH-1:0] btb_hit;
    logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_addr;
    logic [NUM_OF_FETCH-1:0] data_recieved;
    logic [NUM_OF_FETCH-1:0] is_page_fault;
    logic [NUM_OF_FETCH-1:0] is_access_fault;
    // データが有効か.予測分岐がヒットして飛び先が判明した命令以降を無効化するために存在する.
    logic [NUM_OF_FETCH-1:0] data_valid;
    logic [NUM_OF_FETCH-1:0][31:0] data;
  } ifq_t;
  ifq_t ifq[IFQ_SIZE];
  ifq_t ifq_next[IFQ_SIZE];
  logic [IFQ_IDX_WIDTH-1:0] ifq_rp;
  logic [IFQ_IDX_WIDTH-1:0] ifq_wp;
  logic [IFQ_IDX_WIDTH-1:0] ifq_rp_next;
  logic [IFQ_IDX_WIDTH-1:0] ifq_wp_next;
  logic [IFQ_IDX_WIDTH:0] num_of_entries_in_ifq;
  logic [IFQ_IDX_WIDTH:0] num_of_entries_in_ifq_next;


  // 次のサイクルで出力.
  ifq_decoder_t ifq_out_next[NUM_OF_FETCH];


  // icache
  // word単位で分解されたicacheからのres
  typedef struct packed {
    logic valid;
    int unsigned id;
    int unsigned generation;
    logic [VADDR_WIDTH-1:0] vaddr_word_aligned;
    logic [PADDR_WIDTH-1:0] paddr_word_aligned;
    logic is_page_fault;
    logic is_access_fault;
    logic [31:0] data;
  } cache_res_per_word_t;
  cache_res_per_word_t cache_res_per_word[NUM_OF_RES_FROM_ICACHE*2];


  always_comb begin
    logic [NUM_OF_FETCH-1:0] data_valid = '{default: 0};

    ifq_next = ifq;
    ifq_rp_next = ifq_rp;
    ifq_wp_next = ifq_wp;
    num_of_entries_in_ifq_next = num_of_entries_in_ifq;

    flush_out = '{valid: 0, addr: 0};


    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      ifq_out_next[i] = '{valid: 0, default: 0};
    end


    // -------------------------------------------------------
    // pred_btb_resultに基づいたifq_nextの更新
    // --------------------------------------------------------
    if (pred_btb_result.valid) begin
      // predがtakenでbtbもヒットして分岐予測でその飛び先が判別済の場合,
      // それ以降の命令を無効化して,flushする.
      data_valid = '{default: 0};
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        data_valid[i] = 1;
        if (pred_btb_result.pred_taken[i] && pred_btb_result.btb_hit[i]) begin
          flush_out = '{valid: 1, addr: pred_btb_result.btb_addr[i]};
          break;
        end
      end
      ifq_next[ifq_wp_next] = '{
          first_instr_vaddr: pred_btb_result.first_instr_addr,
          instr_paddr: 0,  // dataと一緒にキャッシュから受け取る.
          first_instr_id: pred_btb_result.first_instr_id,
          pred_taken: pred_btb_result.pred_taken,
          btb_hit: pred_btb_result.btb_hit,
          btb_addr: pred_btb_result.btb_addr,
          is_page_fault: 0,
          is_access_fault: 0,
          data_valid: data_valid,
          data_recieved: 0,
          data: 0
      };
      ifq_wp_next = IFQ_IDX_WIDTH'(ifq_wp_next + IFQ_IDX_WIDTH'($unsigned(1)));
      num_of_entries_in_ifq_next++;
    end

    // TODODODODODO
    // for (int unsigned i = 0; i < NUM_OF_RES_FROM_ICACHE; i++) begin
    //   logic [VADDR_WIDTH-1:0] vaddr_word_aligned = 0;
    //   if (icache_result[i].valid == 1 && (icache_result[i].generation == generation)) begin
    //     for (
    //         int unsigned word_idx_in_ir = 0; word_idx_in_ir < NUM_OF_INSTR_IN_DW; word_idx_in_ir++
    //     ) begin
    //       vaddr_word_aligned = icache_result[i].vaddr_dw_aligned + word_idx_in_ir * 4;
    //       for (int unsigned ifq_idx = 0; ifq_idx < IFQ_SIZE; ifq_idx++) begin
    //         for (
    //             int unsigned instr_idx_in_entry = 0;
    //             instr_idx_in_entry < NUM_OF_FETCH;
    //             instr_idx_in_entry++
    //         ) begin
    //           if(vaddr_word_aligned == ifq_next[ifq_idx].first_instr_addr + instr_idx_in_entry*4)begin
    //             ifq_next[ifq_idx].data_recieved[instr_idx_in_entry] = 1;
    //             ifq_next[ifq_idx].data[instr_idx_in_entry] = icache_result[i].data[4*8*word_idx_in_ir+:4*8];
    //           end
    //         end
    //       end
    //     end

    //   end
    // end

    // icache_resultをword単位に分解する.
    for (int unsigned i = 0; i < NUM_OF_RES_FROM_ICACHE; i++) begin
      cache_res_per_word[i*2] = '{
          valid: icache_result[i].valid,
          id: icache_result[i].id,
          generation: icache_result[i].generation,
          vaddr_word_aligned: icache_result[i].vaddr_dw_aligned,
          paddr_word_aligned: icache_result[i].paddr_dw_aligned,
          is_page_fault: icache_result[i].is_page_fault,
          is_access_fault: icache_result[i].is_access_fault,
          data: icache_result[i].data[31:0]
      };
      cache_res_per_word[i*2+1] = '{
          valid: icache_result[i].valid,
          id: icache_result[i].id,
          generation: icache_result[i].generation,
          vaddr_word_aligned: icache_result[i].vaddr_dw_aligned + 4,
          paddr_word_aligned: icache_result[i].paddr_dw_aligned + 4,
          is_page_fault: icache_result[i].is_page_fault,
          is_access_fault: icache_result[i].is_access_fault,
          data: icache_result[i].data[63:32]
      };
    end

    // cache_res_per_word => ifq_next
    for (int unsigned i = 0; i < NUM_OF_RES_FROM_ICACHE * 2; i++) begin
      logic [VADDR_WIDTH-1:0] vaddr_word_aligned = 0;
      if (cache_res_per_word[i].valid == 1 && (cache_res_per_word[i].generation == generation)) begin
        for (int unsigned ifq_idx = 0; ifq_idx < IFQ_SIZE; ifq_idx++) begin
          // 1回のフェッチ（ifqの1エントリ）に対して最大3つのicacheへのリクエストが対応するので,
          // idは3つの連番でかつfirst_instr_idは下位2bitが0なので,以下.
          if (ifq_next[ifq_idx].first_instr_id[31:2] == cache_res_per_word[i].id[31:2]) begin
            for (
                int unsigned instr_idx_in_entry = 0;
                instr_idx_in_entry < NUM_OF_FETCH;
                instr_idx_in_entry++
            ) begin
              if(cache_res_per_word[i].vaddr_word_aligned == ifq_next[ifq_idx].first_instr_vaddr+instr_idx_in_entry*4)begin
                //
                ifq_next[ifq_idx].data_recieved[instr_idx_in_entry] = 1;
                ifq_next[ifq_idx].data[instr_idx_in_entry] = cache_res_per_word[i].data;
                // 対応するpaddr
                ifq_next[ifq_idx].instr_paddr[instr_idx_in_entry] = cache_res_per_word[i].paddr_word_aligned;
                ifq_next[ifq_idx].is_page_fault[instr_idx_in_entry] = cache_res_per_word[i].is_page_fault;
                ifq_next[ifq_idx].is_access_fault[instr_idx_in_entry] = cache_res_per_word[i].is_access_fault;
              end
            end

          end
        end
      end
    end

    // ---------------------------------------------------------------------
    // ifq_nextからの出力
    // ---------------------------------------------------------------------
    // pred_btb_result,icache_resultに基づいた更新をしたifq_nextから,
    // 現在の状態に基づいて命令を後続のステージ(デコーダ)に渡したりする.
    begin
      // 先頭エントリのうち,validな命令に対応するデータを全て受け取ったか.
      logic all_valid_entry_recieved_data = 1;
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (ifq_next[ifq_rp].data_valid[i] && !ifq_next[ifq_rp].data_recieved[i]) begin
          all_valid_entry_recieved_data = 0;
        end
      end

      if (flush_in) begin
        ifq_rp_next = 0;
        ifq_wp_next = 0;
        num_of_entries_in_ifq_next = 0;
      end else if (stall_in) begin
        // stallなら,出力はinvalid,
      end else if (num_of_entries_in_ifq_next != 0 && all_valid_entry_recieved_data) begin
        // ifqが空でなく,先頭エントリがicacheからデータを取得している場合
        for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
          ifq_out_next[i] = '{
              valid: ifq_next[ifq_rp].data_valid[i],
              vaddr:
              VADDR_WIDTH
              '(
              ifq_next[ifq_rp].first_instr_vaddr + VADDR_WIDTH'(unsigned'(4 * i))
              ),
              paddr: ifq_next[ifq_rp].instr_paddr[i],
              data: ifq_next[ifq_rp].data[i],
              pred_taken: ifq_next[ifq_rp].pred_taken[i],
              btb_hit: ifq_next[ifq_rp].btb_hit[i],
              btb_addr: ifq_next[ifq_rp].btb_addr[i],
              is_page_fault: ifq_next[ifq_rp].is_page_fault[i],
              is_access_fault: ifq_next[ifq_rp].is_access_fault[i]
          };
        end
        ifq_rp_next = IFQ_IDX_WIDTH'(ifq_rp + IFQ_IDX_WIDTH'($unsigned(1)));
        num_of_entries_in_ifq_next--;
      end else begin
        // ifqが空か,ifqの先頭エントリのデータが取得出来ていない場合.
        ifq_rp_next = ifq_rp;
      end
    end

    // stall
    // 入ってくるエントリは1/percycleなので.
    stall_out = 32'(num_of_entries_in_ifq_next) == IFQ_SIZE;

  end

  int fp;
  initial begin
    fp = $fopen("./log/ifqlog.txt", "w");
  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin

      // ifq
      ifq <= '{default: 0};
      ifq_wp <= 0;
      ifq_rp <= 0;
      num_of_entries_in_ifq <= 0;

      //出力
      ifq_out <= '{default: 0};

    end else begin

      // ifq
      ifq <= ifq_next;
      ifq_wp <= ifq_wp_next;
      ifq_rp <= ifq_rp_next;
      num_of_entries_in_ifq <= num_of_entries_in_ifq_next;

      //出力
      ifq_out <= ifq_out_next;

`ifdef IFQ_EN
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (ifq_out[i].valid) begin
          $fdisplay(
              fp,
              "[IFQ] i=%0d vaddr=%016h paddr=%016h data=%08h pred=%0d btb_hit=%0d btb_addr=%016h pf=%0d af=%0d",
              i, ifq_out[i].vaddr, ifq_out[i].paddr, ifq_out[i].data, ifq_out[i].pred_taken,
              ifq_out[i].btb_hit, ifq_out[i].btb_addr, ifq_out[i].is_page_fault,
              ifq_out[i].is_access_fault);
        end
      end
`endif
    end
  end


endmodule
