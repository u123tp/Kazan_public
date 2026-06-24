`timescale 1ns / 1ps
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

    input program_counter_t pc_in[NUM_OF_FETCH],
    input logic [NUM_OF_FETCH-1:0] pred_taken,
    input logic [NUM_OF_FETCH-1:0] btb_hit,
    input logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_addr,

    input cache_res128_t icache_result[NUM_OF_RES_FROM_ICACHE],
    // input pred_btb_result_t pred_btb_result,

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


  // --------------------------------------------
  // パラメータ
  // --------------------------------------------

  localparam int unsigned VADDR_FETCH_ALIGNED_MSB = VADDR_WIDTH - 1;
  localparam int unsigned VADDR_FETCH_ALIGNED_LSB = $clog2(4 * NUM_OF_FETCH);

  localparam int unsigned DW_IDX_IN_FETCH_WIDTH = $clog2(4 * NUM_OF_FETCH / DW_SIZE);
  localparam int unsigned DW_IDX_IN_FETCH_LSB = $clog2(DW_SIZE);
  localparam int unsigned DW_IDX_IN_FETCH_MSB = DW_IDX_IN_FETCH_LSB + DW_IDX_IN_FETCH_WIDTH - 1;

  // localparam int unsigned INSTR_SIZE = 4;
  // localparam int unsigned NUM_OF_INSTR_IN_DW = DW_SIZE / INSTR_SIZE;

  localparam int unsigned IFQ_SIZE = 4;
  localparam int unsigned IFQ_IDX_WIDTH = $clog2(IFQ_SIZE);


  // -----------------------------------------------------------------------------------------------------------------------
  // ifq
  // -----------------------------------------------------------------------------------------------------------------------

  logic [IFQ_IDX_WIDTH-1:0] ifq_rp;
  logic [IFQ_IDX_WIDTH-1:0] ifq_wp;
  logic [IFQ_IDX_WIDTH:0] noei_ifq;



  // icacheが
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] first_instr_vaddr;  // 1つ目の命令のアドレス.8byteアライン.
    logic [NUM_OF_FETCH-1:0] instr_valid;
    // logic [NUM_OF_FETCH-1:0][PADDR_WIDTH-1:0] instr_paddr;  // pmp用.
    int unsigned fetch_id;
    logic [NUM_OF_FETCH-1:0] pred_taken;
    logic [NUM_OF_FETCH-1:0] btb_hit;
    logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_addr;
  } ifq_meta_t;
  ifq_meta_t ifq_meta[IFQ_SIZE];

  // 新しいifqのエントリ
  ifq_meta_t new_ifq_meta;
  logic new_ifq_exist;

  // 削除するifqのエントリ
  int unsigned num_of_used_ifq;

  // 非同期的に読み込みをおこなうifqのフィールド
  typedef struct packed {
    logic data_recieved;
    logic [PADDR_WIDTH-1:0] first_instr_paddr;
    logic is_page_fault;
    logic is_access_fault;
    logic [NUM_OF_FETCH-1:0][31:0] data;
  } ifq_cache_result_t;
  ifq_cache_result_t ifq_cache_result[IFQ_SIZE];

  logic new_ifq_cache_result_valid[NUM_OF_RES_FROM_ICACHE];
  logic [IFQ_IDX_WIDTH-1:0] new_ifq_cache_result_idx[NUM_OF_RES_FROM_ICACHE];
  ifq_cache_result_t new_ifq_cache_result[NUM_OF_RES_FROM_ICACHE];


  // 次のサイクルで出力.
  ifq_decoder_t ifq_out_next[NUM_OF_FETCH];


  // -----------------------------------------------------------------------------------
  // pred_btb_resultに基づいたifq更新用のifq_newを作成>
  // -----------------------------------------------------------------------------------
  always_comb begin
    // logic [NUM_OF_FETCH-1:0] data_valid = '{default: 0};

    new_ifq_meta = '{default: 0};
    new_ifq_exist = 0;

    flush_out = '{default: 0};

    //
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      if (pc_in[i].valid) begin
        new_ifq_exist = 1;
      end
    end

    begin
      automatic logic [NUM_OF_FETCH-1:0] instr_valid = '{default: 0};
      if (new_ifq_exist) begin
        // predがtakenでbtbもヒットして分岐予測でその飛び先が判別済の場合,
        // それ以降の命令を無効化して,flushする.
        for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
          if (pc_in[i].valid) begin
            instr_valid[i] = 1;
            if (pred_taken[i] && btb_hit[i]) begin
              flush_out = '{valid: 1, addr: btb_addr[i]};
              break;
            end
          end
        end
        new_ifq_meta = '{
            first_instr_vaddr: pc_in[0].vaddr,
            instr_valid: instr_valid,
            fetch_id: pc_in[0].fetch_id,
            pred_taken: pred_taken,
            btb_hit: btb_hit,
            btb_addr: btb_addr
        };
      end
    end
  end

  // ------------------------------------------------------------------------------------------------------
  // icache_result からifqのアップデート内容を作成.
  // ------------------------------------------------------------------------------------------------------
  always_comb begin

    automatic logic [IFQ_IDX_WIDTH-1:0] ifq_idx = 0;
    //
    new_ifq_cache_result_valid = '{default: 0};
    new_ifq_cache_result_idx = '{default: 0};
    new_ifq_cache_result = '{default: 0};

    for (int unsigned cache_port = 0; cache_port < NUM_OF_RES_FROM_ICACHE; cache_port++) begin
      if (icache_result[cache_port].valid) begin

        // if (icache_result[cache_port].is_page_fault) begin
        //   $display("[LOG][IFQ.sv] cache_result pf");
        // end
        // if (icache_result[cache_port].is_access_fault) begin
        //   $display("[LOG][IFQ.sv] cache_result af");
        // end
        // if (icache_result[cache_port].data == 0 && icache_result[cache_port].is_page_fault) begin
        //   $display("[LOG][IFQ.sv] data:0 and pf first_instr_paddr:%0h noei_ifq",
        //            icache_result[cache_port].paddr_dw_aligned, noei_ifq);
        //   $display("stall_in:%b   flush_in:%b", stall_in, flush_in);
        //   dump_ifq_meta();
        //   dump_icache_result();
        // end

        // すでにicache_result[cache_port]に対応するデータがifqに入っている場合
        for (int unsigned i = 0; i < IFQ_SIZE; i++) begin
          if (i < noei_ifq) begin
            ifq_idx = ifq_rp + IFQ_IDX_WIDTH'(i);
            if (ifq_meta[ifq_idx].fetch_id == icache_result[cache_port].id && generation == icache_result[cache_port].generation) begin
              new_ifq_cache_result_valid[cache_port] = 1;
              new_ifq_cache_result_idx[cache_port] = ifq_idx;
              new_ifq_cache_result[cache_port] = '{
                  data_recieved: 1,
                  first_instr_paddr: icache_result[cache_port].paddr_db_aligned,
                  is_page_fault: icache_result[cache_port].is_page_fault,
                  is_access_fault: icache_result[cache_port].is_access_fault,
                  data: icache_result[cache_port].data
              };
            end
          end
        end

        // icache_reult[cache_port]がに対応するpred_resultなどが同時に来るとき
        if (new_ifq_exist) begin
          if (new_ifq_meta.fetch_id == icache_result[cache_port].id) begin
            new_ifq_cache_result_valid[cache_port] = 1;
            new_ifq_cache_result_idx[cache_port] = ifq_wp;
            new_ifq_cache_result[cache_port] = '{
                data_recieved: 1,
                first_instr_paddr: icache_result[cache_port].paddr_db_aligned,
                is_page_fault: icache_result[cache_port].is_page_fault,
                is_access_fault: icache_result[cache_port].is_access_fault,
                data: icache_result[cache_port].data
            };
          end
        end

      end
    end
  end



  // -----------------------------------------------------------------------------------------
  // ifqから出力を作成
  // -----------------------------------------------------------------------------------------

  always_comb begin
    num_of_used_ifq = 0;
    ifq_out_next = '{default: 0};

    // flush_inでもなく,stall_inでもなく,かつifqにエントリが存在する場合だけ出力.
    if (!flush_in && !stall_in && noei_ifq > 0 && ifq_cache_result[ifq_rp].data_recieved) begin
      // 出力する場合
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (ifq_meta[ifq_rp].instr_valid[i]) begin
          ifq_out_next[i] = '{
              valid: 1,
              vaddr:
              VADDR_WIDTH
              '(
              ifq_meta[ifq_rp].first_instr_vaddr + VADDR_WIDTH'(unsigned'(4 * i))
              ),
              paddr: ifq_cache_result[ifq_rp].first_instr_paddr + PADDR_WIDTH'(unsigned'(4 * i)),
              data: ifq_cache_result[ifq_rp].data[i],
              pred_taken: ifq_meta[ifq_rp].pred_taken[i],
              btb_hit: ifq_meta[ifq_rp].btb_hit[i],
              btb_addr: ifq_meta[ifq_rp].btb_addr[i],
              is_page_fault: ifq_cache_result[ifq_rp].is_page_fault,
              is_access_fault: ifq_cache_result[ifq_rp].is_access_fault
          };
          /*  if (ifq_cache_result[ifq_rp].data[i] == 0 && ifq_cache_result[ifq_rp].is_page_fault) begin
            $display("[LOG][IFQ.sv] data 0 and pf");
          end */
        end
      end
      num_of_used_ifq++;
    end
  end



  // -----------------------------------------------------------------------------------------
  // stallの作成
  // -----------------------------------------------------------------------------------------
  always_comb begin
    // 次のサイクルで
    stall_out = 32'(noei_ifq) + 32'(new_ifq_exist) - 32'(num_of_used_ifq) == IFQ_SIZE;
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      ifq_meta <= '{default: 0};
      ifq_rp <= 0;
      ifq_wp <= 0;
      noei_ifq <= 0;

      ifq_cache_result <= '{default: 0};

      // ifq_outの作成
      ifq_out <= '{default: 0};

    end else if (flush_in) begin
      // flush_in

      ifq_meta <= '{default: 0};
      ifq_rp <= 0;
      ifq_wp <= 0;
      noei_ifq <= 0;

      ifq_cache_result <= '{default: 0};

      // ifq_outの作成
      ifq_out <= '{default: 0};
    end else begin

      // ifq_meta
      if (new_ifq_exist) begin
        ifq_meta[ifq_wp] <= new_ifq_meta;
        ifq_cache_result[ifq_wp] <= '{default: 0};
      end
      ifq_rp   <= ifq_rp + IFQ_IDX_WIDTH'(num_of_used_ifq);
      ifq_wp   <= ifq_wp + new_ifq_exist;
      noei_ifq <= noei_ifq + IFQ_IDX_WIDTH'(new_ifq_exist) - IFQ_IDX_WIDTH'(num_of_used_ifq);

      // ifq_cache_result
      for (int unsigned i = 0; i < NUM_OF_RES_FROM_ICACHE; i++) begin
        if (new_ifq_cache_result_valid[i]) begin
          ifq_cache_result[new_ifq_cache_result_idx[i]] <= new_ifq_cache_result[i];
        end
      end

      // ifq_outの作成
      ifq_out <= ifq_out_next;

    end
  end



  // ----------------------------------------------------------------------------------------------------------
  // FOR DEBUG 
  // ----------------------------------------------------------------------------------------------------------
`ifdef VERILATOR_COMPILE
  int fp;
  initial begin
    fp = $fopen("./log/ifq.log", "w");
  end


  function automatic void dump_ifq_meta();
    $fdisplay(fp, "===== dump_ifq_meta =====");
    $fdisplay(fp, "ifq_rp=%0d ifq_wp=%0d noei_ifq=%0d", ifq_rp, ifq_wp, noei_ifq);

    for (int unsigned i = 0; i < IFQ_SIZE; i++) begin
      $display(

          "ifq_meta[%0d] { first_instr_vaddr:0x%0h, instr_valid:0b%b, fetch_id:%0d, pred_taken:0b%b, btb_hit:0b%b }",
          i, ifq_meta[i].first_instr_vaddr, ifq_meta[i].instr_valid, ifq_meta[i].fetch_id,
          ifq_meta[i].pred_taken, ifq_meta[i].btb_hit);

      for (int unsigned j = 0; j < NUM_OF_FETCH; j++) begin
        $fdisplay(fp, "  ifq_meta[%0d].btb_addr[%0d] = 0x%0h", i, j, ifq_meta[i].btb_addr[j]);
      end
    end
  endfunction


  function automatic void dump_icache_result();
    $fdisplay(fp, "===== dump_icache_result =====");

    for (int unsigned i = 0; i < NUM_OF_RES_FROM_ICACHE; i++) begin
      $display(

          "icache_result[%0d] { valid:%0d, id:%0d, paddr_dw_aligned:0x%0h, is_page_fault:%0d, is_access_fault:%0d }",
          i, icache_result[i].valid, icache_result[i].id, icache_result[i].paddr_db_aligned,
          icache_result[i].is_page_fault, icache_result[i].is_access_fault);

      for (int unsigned j = 0; j < NUM_OF_FETCH; j++) begin
        $display("  icache_result[%0d].data[%0d] = 0x%08h", i, j, icache_result[i].data[j]);
      end
    end
  endfunction


  function automatic void dump_ifq_decoder(input ifq_decoder_t x);
    $fdisplay(
        fp,
        "{valid:%0d, vaddr:0x%0h, paddr:0x%0h, data:0x%08h, pred_taken:%0d, btb_hit:%0d, is_page_fault:%0d, is_access_fault:%0d, btb_addr:0x%0h}",
        x.valid, x.vaddr, x.paddr, x.data, x.pred_taken, x.btb_hit, x.is_page_fault,
        x.is_access_fault, x.btb_addr);
  endfunction

  int unsigned counter;
  always_ff @(posedge clock) begin
    if (reset) begin
      counter <= 0;
    end else begin
      counter <= counter + 1;
      // 
      // for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      //   if (ifq_out[i].valid) begin
      //     dump_ifq_decoder(ifq_out[i]);
      //   end
      // end

      // if (counter == 1000000) begin
      //   dump_ifq_meta();
      //   dump_icache_result();
      // end



    end
  end
`endif

endmodule
