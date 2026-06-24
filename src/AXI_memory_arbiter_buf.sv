

`timescale 1ns / 1ps

// icache,dcacheからmmへのリクエストをaxi4に変換するモジュール.
// このcpuで用いられているstallと,axi4のreadyでは方式が異なる.
// このcpuで用いられているstallは,次のサイクルにリクエストを受け入れることができないということを意味する. 
// axi4のreadyは,送信側はとりあえずvalidなリクエストを送り,その後にvalid & readyを確認することで,それが1なら送信成功となる.
// この際,readyに基づいてvalidを決めるということはaxi4の規約により禁止されている.
// そこら辺の差異をこのモジュールのバッファで吸収する.
//
// また,逐次実行するため,複数のリクエストを同時に出さない.
// なぜなら,複数のリクエストを出すと,ps側で実行の順番が前後するから.
//

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"

module AXI_memory_arbiter_buf
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;
#(
    // このモジュールのbufはaxiへのプロトコル変更に必要なだけなのでそこまで大きくなくて良い.
    parameter int unsigned CACHE_BUF_SIZE = 8,

    // 実際にpsにaxi経由でリクエストするときのbaseのアドレス.
    // ps側で確保されているdramのアドレスは0x1000_0000 ~ 0x4fff_ffff
    parameter int unsigned AXI_BASE_ADDR = 32'h1000_0000,
    parameter int unsigned BUF_SIZE = 256,

    parameter type mm_req_t = mm_req64_t,
    parameter type mm_res_t = mm_res64_t,

    parameter type axi_req_t = axi_req64_t,
    parameter type axi_res_t = axi_res64_t,
    // byte単位.
    parameter int unsigned DATA_SIZE = 8,

    parameter int unsigned NUM_OF_REQ_FROM_CACHE = 1,
    parameter int unsigned NUM_OF_RES_TO_CACHE   = 1,

    parameter int unsigned DEBUG_BUF_SIZE = 256
) (
    input logic clock,
    input logic reset,

    // 今はNUM_OF_REQ_FROM_CACHE,NUM_OF_RES_TO_CACHEは両方とも1.
    input mm_req_t req_from_cache[NUM_OF_REQ_FROM_CACHE],
    output mm_res_t res_to_cache[NUM_OF_RES_TO_CACHE],
    output logic ready_to_cache,

    output axi_req_t req_to_dram,
    input  axi_res_t res_from_dram

);

  mm_req_t cache_port0;
  always_ff @(posedge clock) begin
    if (reset) begin
      cache_port0 <= '0;
    end else begin
      cache_port0 <= req_from_cache[0];
    end
  end

  // -------------------------------------------------------------------------------------------------------
  // パラメータ
  // ------------------------------------------------------------------------------------------------------
  localparam int unsigned CACHE_BUF_IDX_WIDTH = $clog2(CACHE_BUF_SIZE);

  localparam int unsigned NUM_OF_CACHE_BUF_BANK = NUM_OF_REQ_FROM_CACHE;
  localparam int unsigned CACHE_BUF_BANK_IDX_WIDTH = $clog2(NUM_OF_CACHE_BUF_BANK);

  localparam int unsigned CACHE_BUF_BANK_SIZE = CACHE_BUF_SIZE / NUM_OF_CACHE_BUF_BANK;
  localparam int unsigned CACHE_BUF_INBANK_IDX_WIDTH = $clog2(CACHE_BUF_BANK_SIZE);

  localparam int unsigned CACHE_BUF_BANK_IDX_LSB = 0;
  localparam int unsigned CACHE_BUF_BANK_IDX_MSB = CACHE_BUF_BANK_IDX_LSB + CACHE_BUF_BANK_IDX_WIDTH - 1;
  localparam int unsigned CACHE_BUF_INBANK_IDX_LSB = CACHE_BUF_BANK_IDX_MSB + 1;
  localparam int unsigned CACHE_BUF_INBANK_IDX_MSB = CACHE_BUF_INBANK_IDX_LSB + CACHE_BUF_INBANK_IDX_WIDTH - 1;

  localparam int unsigned CACHE_BUF_BANK_IDX_LSB_MOD = 0;
  localparam int unsigned CACHE_BUF_BANK_IDX_MSB_MOD = NUM_OF_CACHE_BUF_BANK == 1 ? 0 : CACHE_BUF_BANK_IDX_LSB + CACHE_BUF_BANK_IDX_WIDTH - 1;

  // 0x8000_0000がこのcpuではbaseだが,psにリクエストする際は0x1000_0000がbaseになるので.
  localparam int unsigned ADDR_OFFSET = 32'h8000_0000 - AXI_BASE_ADDR;


  // -------------------------------------------------------------------------------------------------------
  //　バッファ本体
  // -------------------------------------------------------------------------------------------------------
  // 読み取りはdramと接続するもので,ポートは1つに固定.
  logic cache_buf_r_en[NUM_OF_CACHE_BUF_BANK];
  logic [CACHE_BUF_INBANK_IDX_WIDTH-1:0] cache_buf_r_idx[NUM_OF_CACHE_BUF_BANK];
  logic [($bits(mm_req_t)-1):0] cache_buf_r_data_bit[NUM_OF_CACHE_BUF_BANK];

  // 書き込みはcache_portからのもので,ポートはNUM_OF_CACHE_REQ_OUT個用意する.
  logic cache_buf_w_en[NUM_OF_CACHE_BUF_BANK];
  logic [CACHE_BUF_INBANK_IDX_WIDTH-1:0] cache_buf_w_idx[NUM_OF_CACHE_BUF_BANK];
  logic [($bits(mm_req_t)-1):0] cache_buf_w_data_bit[NUM_OF_CACHE_BUF_BANK];

  mm_req_t cache_buf_r_data_strc[NUM_OF_CACHE_BUF_BANK];
  mm_req_t cache_buf_w_data_strc[NUM_OF_CACHE_BUF_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CACHE_BUF_BANK; i++) begin
      cache_buf_w_data_bit[i]  = cache_buf_w_data_strc[i];
      cache_buf_r_data_strc[i] = cache_buf_r_data_bit[i];
    end
  end

  generate
    for (genvar i = 0; i < NUM_OF_CACHE_BUF_BANK; i++) begin : gen_cache_buf
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(mm_req_t)),
          .RAM_DEPTH(CACHE_BUF_BANK_SIZE)
      ) cache_buf (
          .clock(clock),
          .r_en(cache_buf_r_en[i]),
          .r_ram_idx(cache_buf_r_idx[i]),
          .r_data(cache_buf_r_data_bit[i]),
          .w_en(cache_buf_w_en[i]),
          .w_ram_idx(cache_buf_w_idx[i]),
          .w_data(cache_buf_w_data_bit[i])
      );
    end
  endgenerate

  logic [CACHE_BUF_IDX_WIDTH-1:0] cache_buf_rp;
  logic [CACHE_BUF_IDX_WIDTH-1:0] cache_buf_wp;
  logic [CACHE_BUF_IDX_WIDTH:0] noei_cache_buf;
  logic [CACHE_BUF_IDX_WIDTH-1:0] cache_buf_rp_next;
  logic [CACHE_BUF_IDX_WIDTH-1:0] cache_buf_wp_next;
  logic [CACHE_BUF_IDX_WIDTH:0] noei_cache_buf_next;

  logic [$clog2(NUM_OF_REQ_FROM_CACHE):0] num_of_new_cache_req;
  logic num_of_used_cache_req;

  // axiで送るときに確認
  logic cache_buf_r_en_prev[NUM_OF_CACHE_BUF_BANK];


  // aw,wが片方だけおくられた場合に記録しておく
  logic during_w_addr_request;
  logic during_w_data_request;
  logic during_w_addr_request_next;
  logic during_w_data_request_next;

  logic during_w_request;
  logic during_w_request_next;
  logic during_r_request;
  logic during_r_request_next;


  // ----------------------------------------------------------------------------------------------------
  // 現在リクエスト中のreqの保持
  // ----------------------------------------------------------------------------------------------------

  mm_req_t requesting_cache_req;
  mm_req_t requesting_cache_req_next;


  // -------------------------------------------------------------------------------------------------
  // 変換関数
  // -------------------------------------------------------------------------------------------------
  localparam int unsigned UART_BYTES = BUF_SIZE / 8;
  localparam int unsigned HEX_BITS = BUF_SIZE / 2;
  localparam int unsigned HEX_DIGITS = UART_BYTES;


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


  // HEX_BITS bitの値を、BUF_SIZE bitのUART送信用ASCII列に変換する
  function automatic logic [BUF_SIZE-1:0] hex_bits_to_uart_ascii(input logic [HEX_BITS-1:0] value);
    logic [BUF_SIZE-1:0] result;
    logic [3:0] nibble;

    int unsigned i;

    begin
      result = '0;

      // 上位nibbleから順にASCII化する
      for (i = 0; i < HEX_DIGITS; i++) begin
        nibble = value[(HEX_DIGITS-1-i)*4+:4];
        result[i*8+:8] = hex_nibble_to_ascii(nibble);
      end

      return result;
    end
  endfunction

  // ----------------------------------------------------------------------------------------------------
  // cacheからのリクエストを書き込み.
  // ----------------------------------------------------------------------------------------------------
  always_comb begin
    num_of_new_cache_req = 0;
    cache_buf_w_en = '{default: 0};
    cache_buf_w_idx = '{default: 0};
    cache_buf_w_data_strc = '{default: 0};

    // data_print_en = 0;
    // data_print = 0;

    for (int unsigned i = 0; i < NUM_OF_REQ_FROM_CACHE; i++) begin
      automatic
      logic [CACHE_BUF_IDX_WIDTH-1:0]
      cache_idx = cache_buf_wp + CACHE_BUF_IDX_WIDTH'(num_of_new_cache_req);
      automatic
      logic [CACHE_BUF_INBANK_IDX_WIDTH-1:0]
      cache_inbank_idx = cache_idx[CACHE_BUF_INBANK_IDX_MSB:CACHE_BUF_INBANK_IDX_LSB];
      automatic
      int unsigned
      cache_bank_idx = NUM_OF_CACHE_BUF_BANK == 1 ? 0 : 32'(cache_idx[CACHE_BUF_BANK_IDX_MSB_MOD:CACHE_BUF_BANK_IDX_LSB_MOD]);

      if (req_from_cache[i].valid) begin
        // data_print_en = 1;
        // data_print[7:0] = 8'h0a;
        // data_print[23:8] = 16'h4141;


        cache_buf_w_en[cache_bank_idx] = 1;
        cache_buf_w_idx[cache_bank_idx] = cache_inbank_idx;
        cache_buf_w_data_strc[cache_bank_idx] = req_from_cache[i];
        num_of_new_cache_req++;
      end
    end

  end



  // ----------------------------------------------------------------------------------------------------
  // cache_bufからaxiへのリクエストの読み出し.
  // ----------------------------------------------------------------------------------------------------
  typedef struct packed {
    logic valid;
    int unsigned bank_idx;
    logic [CACHE_BUF_INBANK_IDX_WIDTH-1:0] inbank_idx;
  } cache_buf_read_idx_t;
  cache_buf_read_idx_t cache_buf_read_idx;
  cache_buf_read_idx_t cache_buf_read_idx_prev;

  // 次サイクルで使う,cache_bufの先頭のデータを読み出すためのidxとかの情報を入力.
  always_comb begin
    // 初期化
    automatic
    int unsigned
    cache_buf_bank_idx = NUM_OF_CACHE_BUF_BANK == 1 ? 0 : 32'(cache_buf_rp_next[CACHE_BUF_BANK_IDX_MSB_MOD:CACHE_BUF_BANK_IDX_LSB_MOD]);
    automatic
    logic [CACHE_BUF_INBANK_IDX_WIDTH-1:0]
    cache_buf_inbank_idx = cache_buf_rp_next[CACHE_BUF_INBANK_IDX_MSB:CACHE_BUF_INBANK_IDX_LSB];

    cache_buf_r_en = '{default: 0};
    cache_buf_r_idx = '{default: 0};
    cache_buf_read_idx = '{default: 0};

    if (noei_cache_buf_next > 0) begin
      cache_buf_r_en[cache_buf_bank_idx] = 1;
      cache_buf_r_idx[cache_buf_bank_idx] = cache_buf_inbank_idx;
      cache_buf_read_idx = '{
          valid: 1,
          bank_idx: cache_buf_bank_idx,
          inbank_idx: cache_buf_inbank_idx
      };
    end

  end



  always_comb begin
    // 初期化

    req_to_dram.awuser = 0;
    req_to_dram.awqos = 0;
    req_to_dram.awid = 0;
    req_to_dram.awaddr = 0;
    req_to_dram.awlen = 0;
    req_to_dram.awsize = 0;
    req_to_dram.awburst = 0;
    req_to_dram.awlock = 0;
    req_to_dram.awcache = 0;
    req_to_dram.awprot = 0;
    req_to_dram.awvalid = 0;

    req_to_dram.wdata = 0;
    req_to_dram.wstrb = 0;
    req_to_dram.wlast = 0;
    req_to_dram.wvalid = 0;

    req_to_dram.arqos = 0;
    req_to_dram.aruser = 0;
    req_to_dram.arid = 0;
    req_to_dram.araddr = 0;
    req_to_dram.arlen = 0;
    req_to_dram.arsize = 0;
    req_to_dram.arburst = 0;
    req_to_dram.arlock = 0;
    req_to_dram.arcache = 0;
    req_to_dram.arprot = 0;
    req_to_dram.arvalid = 0;


    if (cache_buf_r_en_prev[cache_buf_read_idx_prev.bank_idx]) begin
      // 現在リクエスト中でない場合のみ,新たなリクエストを送る.
      if (!during_r_request && !during_w_request) begin
        if (cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx].is_write) begin
          // write(cacheからのリクエストは無いけど)

          if (!during_w_addr_request) begin
            // アドレスの内容がまだ送信していない場合,アドレスの内容を送る.
            req_to_dram.awuser = 0;
            req_to_dram.awid = 0;
            req_to_dram.awaddr = 49'(cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx].paddr_mig_aligned) 
                                  - 49'(ADDR_OFFSET);
            req_to_dram.awlen = 0;
            if (DATA_SIZE == 8) begin
              req_to_dram.awsize = 3'b011;  // 64bitなので011.
            end else if (DATA_SIZE == 16) begin
              req_to_dram.awsize = 3'b100;  // 128bitなので100.
            end
            req_to_dram.awburst = 2'b01;  // INCR
            req_to_dram.awlock  = 0;
            req_to_dram.awcache = 0;
            req_to_dram.awprot  = 3'b001;
            req_to_dram.awvalid = 1;

          end
          if (!during_w_data_request) begin
            // データを送信していない場合,データを送る.
            req_to_dram.wdata  = cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx].data;
            req_to_dram.wstrb  = '1;
            req_to_dram.wlast  = 1;  // 1回の転送で完結するので常に1.
            req_to_dram.wvalid = 1;
          end

        end else begin
          if (!during_r_request) begin
            // read
            req_to_dram.aruser = 0;
            req_to_dram.arid = 0;
            req_to_dram.araddr = 49'(cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx].paddr_mig_aligned)
                                   - 49'(ADDR_OFFSET);
            // burstの転送回数. 0=> 1beat, 1 => 2beat, 15 => 16beat
            req_to_dram.arlen = 0;
            // 1beatあたりの転送サイズ. 000 => 1Byte, 001 => 2Byte, 011 => 8Byte
            if (DATA_SIZE == 8) begin
              req_to_dram.arsize = 3'b011;
            end else if (DATA_SIZE == 16) begin
              req_to_dram.arsize = 3'b100;
            end
            // Burstのアドレスの進み方. 00(FIXED) => 全ビート同アドレス, 01(INCR) => beatごとにアドレスが増える.
            req_to_dram.arburst = 2'b01;
            // lrscのlrに相当する.
            req_to_dram.arlock  = 0;
            // transactionのキャッシュ属性. 
            // arcache[0]=>
            req_to_dram.arcache = 4'b0000;
            // 保護属性.arprot[0]=>都県命令か,aprot[1]=>non-secureか,aprot[2]=>命令アクセスかどうか.
            req_to_dram.arprot  = 3'b000;
            req_to_dram.arvalid = 1;

          end
        end
      end
    end
  end



  // -----------------------------------------------------------------------------------------------------------
  // リクエストの送信が成功したかの確認,及びリクエスト中かどうかのフラグ管理
  // ------------------------------------------------------------------------------------------------------------
  always_comb begin

    // writeのreq
    num_of_used_cache_req = 0;
    during_w_addr_request_next = during_w_addr_request;
    during_w_data_request_next = during_w_data_request;
    during_w_request_next = during_w_request;
    during_r_request_next = during_r_request;
    requesting_cache_req_next = requesting_cache_req;

    if (req_to_dram.awvalid && res_from_dram.awready) begin
      during_w_addr_request_next = 1;
    end
    if (req_to_dram.wvalid && res_from_dram.wready) begin
      during_w_data_request_next = 1;
    end
    // w,aw両方の成功が確定した瞬間
    if (during_w_addr_request_next  && during_w_data_request_next &&
        (!during_w_addr_request || !during_w_data_request)) begin
      num_of_used_cache_req = 1;
      during_w_request_next = 1;
      requesting_cache_req_next = cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx];
    end


    // readのreq
    if (req_to_dram.arvalid && res_from_dram.arready) begin
      num_of_used_cache_req = 1;
      during_r_request_next = 1;
      requesting_cache_req_next = cache_buf_r_data_strc[cache_buf_read_idx_prev.bank_idx];
    end

    // ---------------------------------------------------------------------------------------------------
    // メインメモリからの返却
    // ---------------------------------------------------------------------------------------------------

    res_to_cache = '{default: 0};
    if (res_from_dram.bvalid) begin
      // 書き込みリクエストが帰ってきたとき.
      during_w_addr_request_next = 0;
      during_w_data_request_next = 0;
      during_w_request_next = 0;
      during_r_request_next = 0;
      requesting_cache_req_next = '0;

      // cache_port.resを返す必要はない.
      if (res_from_dram.bresp != 2'b00 && res_from_dram.bresp != 2'b01) begin
        $display("[ERROR][AXI_memory_arbiter_buf.sv] response error in axi request.");
        // $finish;
      end
    end else if (res_from_dram.rvalid) begin
      // 読み込みリクエストが帰ってきたとき,
      during_w_addr_request_next = 0;
      during_w_data_request_next = 0;
      during_w_request_next = 0;
      during_r_request_next = 0;
      requesting_cache_req_next = '0;

      if (res_from_dram.rresp == 2'b00 || res_from_dram.rresp == 2'b01) begin
        res_to_cache[0] = '{
            valid: 1,
            id: requesting_cache_req.id,
            id_sub: requesting_cache_req.id_sub,
            paddr_mig_aligned: requesting_cache_req.paddr_mig_aligned,
            data: res_from_dram.rdata
        };
      end else begin
        $display("[ERROR][AXI_memory_arbiter_buf.sv] response error in axi request.");
        // $finish;
      end
    end


  end


  // ----------------------------------------------------------------------------------------------------------------
  // wp,rpの_nextの作成
  // ----------------------------------------------------------------------------------------------------------------
  always_comb begin
    cache_buf_wp_next = cache_buf_wp + CACHE_BUF_IDX_WIDTH'(num_of_new_cache_req);
    cache_buf_rp_next = cache_buf_rp + CACHE_BUF_IDX_WIDTH'(num_of_used_cache_req);
    noei_cache_buf_next = noei_cache_buf + (CACHE_BUF_IDX_WIDTH+1)'(num_of_new_cache_req) - (CACHE_BUF_IDX_WIDTH+1)'(num_of_used_cache_req);
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      cache_buf_read_idx_prev <= '{default: 0};
    end else begin
      cache_buf_read_idx_prev <= cache_buf_read_idx;
    end
  end




  // ----------------------------------------------------------------------------------------------------
  // readyの作成,固定値の出力
  // ----------------------------------------------------------------------------------------------------
  always_comb begin
    ready_to_cache = CACHE_BUF_SIZE - 32'(noei_cache_buf_next) >= NUM_OF_REQ_FROM_CACHE;

    // 
    req_to_dram.rready = 1;
    req_to_dram.bready = 1;
  end

  // ----------------------------------------------------------------------------------------------------
  // cache_bufの更新
  // ----------------------------------------------------------------------------------------------------

  always_ff @(posedge clock) begin
    if (reset) begin
      cache_buf_rp <= 0;
      cache_buf_wp <= 0;
      noei_cache_buf <= 0;

      cache_buf_r_en_prev <= '{default: 0};

      during_w_addr_request <= 0;
      during_w_data_request <= 0;
      during_w_request <= 0;
      during_r_request <= 0;
      requesting_cache_req <= '0;
    end else begin
      cache_buf_rp <= cache_buf_rp_next;
      cache_buf_wp <= cache_buf_wp_next;
      noei_cache_buf <= noei_cache_buf_next;

      cache_buf_r_en_prev <= cache_buf_r_en;

      // during_*
      during_w_addr_request <= during_w_addr_request_next;
      during_w_data_request <= during_w_data_request_next;
      during_w_request <= during_w_request_next;
      during_r_request <= during_r_request_next;
      requesting_cache_req <= requesting_cache_req_next;

    end
  end


  // -----------------------------------------------------------------------------------------
  // FOR DEBUG
  // -----------------------------------------------------------------------------------------


  // logic axi_cache_port_rvalid_debug;
  // logic axi_cache_port_arvalid_debug;
  // logic axi_cache_port_arready_debug;
  // logic [48:0] axi_cache_port_araddr_debug;


  // logic [31:0] requesting_cache_req_id_debug;
  // logic [63:0] axi_cache_port_rdata_debug;
  // logic [1:0] axi_cache_port_rresp_debug;

  // // awポート
  // (*mark_debug="true"*) logic [48:0] awaddr_debug;
  // (*mark_debug="true"*) logic awready_debug;
  // (*mark_debug="true"*) logic awvalid_debug;

  // // wポート
  // (*mark_debug="true"*) logic [63:0] wdata_debug;
  // (*mark_debug="true"*) logic wready_debug;
  // (*mark_debug="true"*) logic wvalid_debug;

  // // bポート.
  // (*mark_debug="true"*) logic [1:0] bresp_debug;
  // (*mark_debug="true"*) logic bready_debug;
  // (*mark_debug="true"*) logic bvalid_debug;


  always_ff @(posedge clock) begin
    if (reset) begin
      // axi_cache_port_rvalid_debug   <= 0;
      // axi_cache_port_arvalid_debug  <= 0;
      // axi_cache_port_arready_debug  <= 0;
      // axi_cache_port_araddr_debug   <= 0;

      // axi_cache_port_wready_debug   <= 0;
      // requesting_cache_req_id_debug <= '0;
      //  axi_cache_port_rdata_debug <= '0;
      // axi_cache_port_rresp_debug <= '0;

      // awaddr_debug  <= 0;
      // awready_debug <= 0;
      // awvalid_debug <= 0;

      // wdata_debug   <= 0;
      // wready_debug  <= 0;
      // wvalid_debug  <= 0;

      // bresp_debug   <= 0;
      // bready_debug  <= 0;
      // bvalid_debug  <= 0;

    end else begin
      // axi_cache_port_rvalid_debug   <= axi_cache_port.rvalid;
      // axi_cache_port_arvalid_debug  <= axi_cache_port.arvalid;
      // axi_cache_port_arready_debug  <= axi_cache_port.arready;
      // axi_cache_port_araddr_debug   <= axi_cache_port.araddr;


      // axi_cache_port_wready_debug   <= axi_cache_port.wready;
      // requesting_cache_req_id_debug <= requesting_cache_req.id;
      //     axi_cache_port_rdata_debug <= axi_cache_port.rdata;
      // axi_cache_port_rresp_debug <= axi_cache_port.rresp;

      // awaddr_debug  <= axi_cache_port.awaddr;
      // awready_debug <= axi_cache_port.awready;
      // awvalid_debug <= axi_cache_port.awvalid;

      // wdata_debug   <= axi_cache_port.wdata;
      // wready_debug  <= axi_cache_port.wready;
      // wvalid_debug  <= axi_cache_port.wvalid;

      // bresp_debug   <= axi_cache_port.bresp;
      // bready_debug  <= axi_cache_port.bready;
      // bvalid_debug  <= axi_cache_port.bvalid;
    end
  end


endmodule
