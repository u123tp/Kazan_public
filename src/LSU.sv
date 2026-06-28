`timescale 1ns / 1ps
// TLBとのやり取りやfenceによる仲裁,
// LDQ,STQが循環バッファとして実装できるのは,登録はrename時にin-orderで行われ,
// 削除もコミットでインオーダーに行われるからである.
//
// TODO: ldとstが同時にcacheにリクエストした場合,キャッシュ内部でstからldにバイパス.
// TODO: misalignment時の処理.

// mmioへのld命令の実行.
// mmioは絶対にロールバックすることができない。st命令はコミット後にmmioに出されるからいいが、
// ldはコミット前にmmioに出される.alの先頭なら確実にコミットするからいいじゃないかと思うかもしれないが、
// 割り込みという問題がある。mmioにリクエストを出したのに割り込みが入ってmmioへのリクエストをロールバックしたいです,
// なんてことになったら駄目だ.
// 割り込みを行える条件に「ALの先頭がld/st命令で無い」を追加する.割り込みを行っては行けないのは,前のサイクルまでに
// mmioへのld/st命令を実行可能信号を出している場合で,この場合、このサイクルでの先頭は必ずld/st命令になる.
// だからalの先頭がld/st命令なら割り込みができないようにする.
// 以上の仕組みをrenamerで実装したので,ここでは普通に実行して良い.



`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CSR_PROPS.svh"
`include "CACHE_PROPS.svh"
`include "MemoryLayout.svh"


module LSU
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CSR_PROPS::*;
  import CACHE_PROPS::*;
  import MemoryLayout::*;
#(

) (
    input logic clock,
    input logic reset,

    // stにamoを統合しているのは,amoの命令の数があまり多く無いと思い,毎回2ポート用意するのを避けたかったから.
    input vuop_back_t op_ld_in[NUM_OF_LD_ISSUE],
    input vuop_back_t op_st_amo_in[NUM_OF_ST_AMO_ISSUE],

    output vuop_result_t op_ld_out[NUM_OF_LD_EXE],
    output vuop_result_t op_st_out[NUM_OF_ST_EXE],


    // ld,stにしろmmioはalの先頭でないと実行されないので,2つ以上が同時に実行されることはない.
    // output vuop_result_t op_mmio_out,


    // => Renamer
    Renamer_LSU_if.lsu renamer_port,

    // => Int Issue Queue
    // load waiting tableの更新.
    output logic ld_speculative_feedback_valid,
    output logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx,

    // DTLB
    dtlb_if.client tlb_port,

    // DCache
    output cache_req64_t req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE],
    input cache_res64_t res_from_dcache[NUM_OF_LD_EXE],
    input logic dcache_noroom,

    // clint
    output device_req_t req_to_clint,
    input  device_res_t res_from_clint,

    // plic及びplicにつながっている外部device(uartなど)
    output device_req_t req_to_plic,
    input  device_res_t res_from_plic,


    // CSR =>
    csr_reg_u satp,

    // M-modeならアドレス変換を行わない.
    privilege_level_e priv_rval,

    // ↓コミット以上に入ってくることはないんだから不要では？
    // renamerへのstallは必要
    // とりあえずldqとstqのサイズを64にしたのであふれることは無い.
    // リソース的には後で変えた方がいい.
    // output logic stall_out,

    input logic flush_in,

    input int unsigned generation,

    output logic stall_append_to_al
);


  //   // FOR DEBUG
  //   function automatic device_name_e get_device_name(
  //     input logic [PADDR_WIDTH-1:0] paddr_origin
  // );

  //   // bootloader:
  //   // start = 0x0000_1000
  //   // size  = 0x0100_0000
  //   // end   = 0x0100_1000
  //   if (PADDR_WIDTH'(64'h0000_0000_0000_1000) <= paddr_origin &&
  //       paddr_origin < PADDR_WIDTH'(64'h0000_0000_0100_1000)) begin
  //     return DN_BOOTLOADER;
  //   end

  //   // CLINT:
  //   // start = 0x0200_0000
  //   // size  = 0x0001_0000
  //   // end   = 0x0201_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_0200_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_0201_0000)) begin
  //     return DN_CLINT;
  //   end

  //   // PLIC:
  //   // start = 0x0c00_0000
  //   // size  = 0x0400_0000
  //   // end   = 0x1000_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_0c00_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_1000_0000)) begin
  //     return DN_PLIC;
  //   end

  //   // UART0:
  //   // start = 0x1000_0000
  //   // size  = 0x0000_0100
  //   // end   = 0x1000_0100
  //   else if (PADDR_WIDTH'(64'h0000_0000_1000_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0000_1000_0100)) begin
  //     return DN_UART;
  //   end

  //   // RAM:
  //   // start = 0x8000_0000
  //   // size  = 0x8800_0000
  //   // end   = 0x1_0800_0000
  //   else if (PADDR_WIDTH'(64'h0000_0000_8000_0000) <= paddr_origin &&
  //            paddr_origin < PADDR_WIDTH'(64'h0000_0001_0800_0000)) begin
  //     return DN_DRAM;
  //   end

  //   else begin
  //     return DN_NONE;
  //   endd

  // endfunction

  // // 性能調整用パラメータ.
  // // 各バンクごとのldq,stqのサイズ.
  // // 本当はLDQは8*4=32くらいほしいが,LUT喰うのでとりあえず4*4=16.
  // localparam int unsigned LDQ_BANK_SIZE = 4;
  // localparam int unsigned STQ_BANK_SIZE = 2;
  // // fenceqだけはバンク化しないので全体のサイズ.8以上にしないと壊れる?
  // localparam int unsigned FENCEQ_SIZE = 8;


  localparam int unsigned BYTE_IN_DW_LSB = 0;
  localparam int unsigned BYTE_IN_DW_MSB = $clog2(DW_SIZE) - 1;


  localparam int unsigned LDQ_INBANK_IDX_WIDTH = $clog2(LDQ_BANK_SIZE);
  localparam int unsigned STQ_INBANK_IDX_WIDTH = $clog2(STQ_BANK_SIZE);
  localparam int unsigned FENCEQ_IDX_WIDTH = $clog2(FENCEQ_SIZE);

  // 
  localparam int unsigned NUM_OF_LD_CACHE_REQ = NUM_OF_LD_EXE;
  localparam int unsigned NUM_OF_ST_CACHE_REQ = NUM_OF_ST_EXE;

  localparam int unsigned NUM_OF_CACHE_REQ = NUM_OF_LD_CACHE_REQ + NUM_OF_ST_CACHE_REQ;

  localparam int unsigned NUM_OF_CACHE_RES = NUM_OF_LD_EXE;

  // とりあえず,DTLBの入力も出力も,issueの数に合わせる.
  localparam int unsigned NUM_OF_DTLB_REQ = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;
  localparam int unsigned NUM_OF_DTLB_RES = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;

  // 各キューのramPortの数
  // キャッシュへのread_reqはffに保存してあるアドレスだけで実行可能だが,
  // キャッシュへのwrite_reqはデータを伴うためramから読み出す必要がある.
  // バイパスが成功した場合,cache_resと同様にldqから命令のデータを読み出してresultとしてalに送るので,
  // cache_resと競合するので,cache_resを抑制する必要がある.
  // amoのバイパスが成功した場合は,次のサイクル立ち上がりのcacheからのresを抑制し,stqに書き込むのでSTQ_WRITE_PORTには
  // max(NUM_OF_LD_CACHE_REQ, NUM_OFCACHE_RES)個をNUM_OF_ST_AMO_ISSUE個の他に持つ必要ある.

  // // キャッシュから読み込んだデータが帰ってきたときに,opの他の内容を読み込んでalに返す.
  // localparam int unsigned NUM_OF_LDQ_READ_PORT = NUM_OF_LD_EXE;
  // // op_in_st_amoの数(amoがldにも登録されるため) + op_in_ldの数.
  // localparam int unsigned NUM_OF_LDQ_WRITE_PORT = NUM_OF_ST_AMO_ISSUE + NUM_OF_LD_ISSUE;

  // // ldへのバイパス用 + キャッシュへの書き込みデータの読み込み(ssb的な)
  // localparam int unsigned NUM_OF_STQ_READ_PORT = NUM_OF_LD_EXE + NUM_OF_ST_CACHE_REQ;
  // // op_inの数 + キャッシュから読み込んだamo命令のロード結果を（演算した後に）保存する.
  // localparam int unsigned NUM_OF_STQ_WRITE_PORT = NUM_OF_ST_AMO_ISSUE + NUM_OF_CACHE_RES;

  localparam int unsigned NUM_OF_EXE = NUM_OF_LD_EXE + NUM_OF_ST_EXE;
  localparam int unsigned NUM_OF_BANK = NUM_OF_FETCH;
  localparam int unsigned BANK_IDX_WIDTH = $clog2(NUM_OF_BANK);


  localparam int unsigned BYPASS_MAX = 4;


  // -------------------------------------------------------
  //出力
  // --------------------------------------------------------

  cache_req64_t req_to_dcache_ld[NUM_OF_LD_EXE];
  cache_req64_t req_to_dcache_st[NUM_OF_ST_EXE];
  cache_req64_t req_to_dcache_next[NUM_OF_LD_EXE+NUM_OF_ST_EXE];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      req_to_dcache_next[i] = req_to_dcache_ld[i];
    end
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      req_to_dcache_next[NUM_OF_LD_EXE+i] = req_to_dcache_st[i];
    end
  end
  always_ff @(posedge clock) begin
    if (reset) begin
      req_to_dcache <= '{default: 0};
    end else if (flush_in) begin
      // flushした場合、原理的にはそのflushと同じサイクルだが、例外を起こした命令より前の命令が
      // stとしてコミットした場合があり,その時のコミットはreq_to_dcache_nextに入る. 
      // この内容はしっかりキャッシュに送ってやる必要がある. 
      req_to_dcache <= req_to_dcache_next;
    end else begin
      req_to_dcache <= req_to_dcache_next;
    end
  end

  // ld命令とst命令で別々に出力し,後でreq_to_plicにマージする
  // mmioに同時に複数の命令が出されることがないのでこの手法を用いることができる. 
  device_req_t req_to_plic_ld;
  device_req_t req_to_plic_st;
  device_req_t req_to_clint_ld;
  device_req_t req_to_clint_st;
  always_comb begin
    req_to_plic  = '{default: 0};
    req_to_clint = '{default: 0};
    if (req_to_plic_ld.valid) begin
      req_to_plic = req_to_plic_ld;
    end
    if (req_to_plic_st.valid) begin
      req_to_plic = req_to_plic_st;
    end
    if (req_to_clint_ld.valid) begin
      req_to_clint = req_to_clint_ld;
    end
    if (req_to_clint_st.valid) begin
      req_to_clint = req_to_clint_st;
    end
  end

  // -------------------------------------------------------------------------------------------------------
  // 各エントリの状態
  // -------------------------------------------------------------------------------------------------------
  // store命令はコミット後にキャッシュに命令を送るので状態がldと異なる.
  typedef enum logic [3:0] {
    LD_BEFORE_ARRIVE,
    LD_BEFORE_TLB_REQUEST,
    LD_DURING_TLB_REQUEST,

    LD_BEFORE_CACHE_REQUEST,
    LD_BEFORE_CACHE_REQUEST_AMO,
    LD_BEFORE_MMIO_REQUEST,

    LD_DURING_CACHE_REQUEST,
    LD_DURING_CACHE_REQUEST_AMO,
    LD_DURING_MMIO_REQUEST,

    LD_DONE,

    LD_PAGE_FAULT,
    LD_ACCESS_FAULT,

    LD_NONE

  } ld_state_t;

  typedef enum logic [3:0] {
    ST_BEFORE_ARRIVE,
    ST_BEFORE_TLB_REQUEST,
    ST_BEFORE_TLB_REQUEST_CONDITIONAL,

    ST_DURING_TLB_REQUEST,
    ST_DURING_TLB_REQUEST_CONDITIONAL,

    // amo命令の場合,ld命令によってrs2を更新してからしか実行できないため,このステージが間に入る.
    // tlbからの返信でpaddrを得るより前にamoのload命令でrs2を得ることは無い.それは,st命令のpaddrは対応するld命令
    // のtarget_paddrと同時に更新されて、そのあとにload命令が発行されて、その結果からstqを更新する.
    ST_AMO_WAITING_RS2,

    // scは直前の命令がコミットして,lrsc_lockの状態が明らかになるまでST_BEFORE_EXE_CONDITIONALににして仮実行させないことにした.
    ST_BEFORE_EXE_CONDITIONAL,
    ST_BEFORE_MMIO_EXE,
    ST_BEFORE_EXE,  // paddrを得てから,stを実行するまで.

    // ST_DONEはコミットを待機している状態
    ST_DONE,
    // 
    ST_DONE_NO_OUT,

    ST_PAGE_FAULT,
    ST_ACCESS_FAULT,

    ST_NONE
  } st_state_t;


  // --------------------------------------------------------------
  // ldq_op_out
  // --------------------------------------------------------------
  // ldqがバンク化できるのは,iiqでの発行が同じようにバンク化されているから. 
  // al_idx%4 == i であるならバンクiに入る.

  // cacheから戻ってきたデータと一緒にして,op_outを作成するためのデータをまとめたもの.
  typedef struct packed {
    opcode_t opcode;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [VADDR_WIDTH-1:0] op_vaddr;
    logic [VADDR_WIDTH-1:0] target_vaddr;
  } ldq_op_out_t;

  logic ldq_op_out_r_en[NUM_OF_RES_FROM_DCACHE][NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_op_out_r_idx[NUM_OF_RES_FROM_DCACHE][NUM_OF_BANK];
  logic [$bits(ldq_op_out_t)-1:0] ldq_op_out_r_data_bit[NUM_OF_RES_FROM_DCACHE][NUM_OF_BANK];

  logic ldq_op_out_w_en[NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_op_out_w_idx[NUM_OF_BANK];
  logic [$bits(ldq_op_out_t)-1:0] ldq_op_out_w_data_bit[NUM_OF_BANK];

  ldq_op_out_t ldq_op_out_w_data_strc[NUM_OF_BANK];
  ldq_op_out_t ldq_op_out_r_data_strc[NUM_OF_RES_FROM_DCACHE][NUM_OF_BANK];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      ldq_op_out_w_data_bit[i] = ldq_op_out_w_data_strc[i];
    end
    for (int unsigned i = 0; i < NUM_OF_RES_FROM_DCACHE; i++) begin
      for (int unsigned j = 0; j < NUM_OF_BANK; j++) begin
        ldq_op_out_r_data_strc[i][j] = ldq_op_out_r_data_bit[i][j];
      end
    end
  end

  generate
    for (
        genvar ldq_op_out_gen_idx = 0; ldq_op_out_gen_idx < NUM_OF_BANK; ldq_op_out_gen_idx++
    ) begin : g_ldq_op_out
      for (
          genvar cache_res_idx = 0; cache_res_idx < NUM_OF_RES_FROM_DCACHE; cache_res_idx++
      ) begin : g_ldq_op_out
        ram_1r1w_bram #(
            .RAM_WIDTH($bits(ldq_op_out_t)),
            .RAM_DEPTH(LDQ_BANK_SIZE)
        ) ldq_op_out_ram (
            .clock(clock),
            .r_en(ldq_op_out_r_en[cache_res_idx][ldq_op_out_gen_idx]),
            .r_ram_idx(ldq_op_out_r_idx[cache_res_idx][ldq_op_out_gen_idx]),
            .r_data(ldq_op_out_r_data_bit[cache_res_idx][ldq_op_out_gen_idx]),
            .w_en(ldq_op_out_w_en[ldq_op_out_gen_idx]),
            .w_ram_idx(ldq_op_out_w_idx[ldq_op_out_gen_idx]),
            .w_data(ldq_op_out_w_data_bit[ldq_op_out_gen_idx])
        );
      end
    end
  endgenerate


  // --------------------------------------------------------------
  // ldq_tlb
  // --------------------------------------------------------------

  // tlbにリクエストするときに必要な内容.
  typedef struct packed {
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] target_vaddr;
  } ldq_tlb_t;

  logic ldq_tlb_r_en[NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_tlb_r_idx[NUM_OF_BANK];
  logic [$bits(ldq_tlb_t)-1:0] ldq_tlb_r_data_bit[NUM_OF_BANK];

  logic ldq_tlb_w_en[NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_tlb_w_idx[NUM_OF_BANK];
  logic [$bits(ldq_tlb_t)-1:0] ldq_tlb_w_data_bit[NUM_OF_BANK];

  ldq_tlb_t ldq_tlb_w_data_strc[NUM_OF_BANK];
  ldq_tlb_t ldq_tlb_r_data_strc[NUM_OF_BANK];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      ldq_tlb_r_data_strc[i] = ldq_tlb_r_data_bit[i];
      ldq_tlb_w_data_bit[i]  = ldq_tlb_w_data_strc[i];
    end
  end

  genvar ldq_tlb_gen_idx;
  generate
    for (ldq_tlb_gen_idx = 0; ldq_tlb_gen_idx < NUM_OF_BANK; ldq_tlb_gen_idx++) begin
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(ldq_tlb_t)),
          .RAM_DEPTH(LDQ_BANK_SIZE)
      ) ldq_op_out_ram (
          .clock(clock),
          .r_en(ldq_tlb_r_en[ldq_tlb_gen_idx]),
          .r_ram_idx(ldq_tlb_r_idx[ldq_tlb_gen_idx]),
          .r_data(ldq_tlb_r_data_bit[ldq_tlb_gen_idx]),
          .w_en(ldq_tlb_w_en[ldq_tlb_gen_idx]),
          .w_ram_idx(ldq_tlb_w_idx[ldq_tlb_gen_idx]),
          .w_data(ldq_tlb_w_data_bit[ldq_tlb_gen_idx])
      );
    end
  endgenerate


  // --------------------------------------------------------
  // ldq_cache_bypass
  // --------------------------------------------------------
  // cacheから読み込んだデータをためておく.4バンク化することで,読み取ってop_outとして出すときに平準化するが,
  // 入力はキャッシュからの変換なので,どのバンクに対応するものが来るかの予測は難しく,キャッシュのレスポンスの数だけ書き込みポートを持つ. 

  typedef struct packed {
    logic [7:0]  bypass_mask;
    logic [63:0] data;
  } ldq_cache_bypass_t;

  logic ldq_bypass_r_en[NUM_OF_CACHE_RES][NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_bypass_r_idx[NUM_OF_CACHE_RES][NUM_OF_BANK];
  logic [$bits(ldq_cache_bypass_t)-1:0] ldq_bypass_r_data_bit[NUM_OF_CACHE_RES][NUM_OF_BANK];

  logic ldq_bypass_w_en[NUM_OF_BANK];
  logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_bypass_w_idx[NUM_OF_BANK];
  logic [$bits(ldq_cache_bypass_t)-1:0] ldq_bypass_w_data_bit[NUM_OF_BANK];


  ldq_cache_bypass_t ldq_bypass_r_data_strc[NUM_OF_CACHE_RES][NUM_OF_BANK];
  ldq_cache_bypass_t ldq_bypass_w_data_strc[NUM_OF_BANK];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      for (int unsigned j = 0; j < NUM_OF_BANK; j++) begin
        ldq_bypass_r_data_strc[i][j] = ldq_bypass_r_data_bit[i][j];
      end
    end
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      ldq_bypass_w_data_bit[i] = ldq_bypass_w_data_strc[i];
    end
  end

  generate
    for (
        genvar cache_res_idx = 0; cache_res_idx < NUM_OF_CACHE_RES; cache_res_idx++
    ) begin : g_ldq_op_out_ram
      for (
          genvar ldq_bank_idx = 0; ldq_bank_idx < NUM_OF_BANK; ldq_bank_idx++
      ) begin : g_ldq_op_out_ram
        ram_1r1w_bram #(
            .RAM_WIDTH($bits(ldq_cache_bypass_t)),
            .RAM_DEPTH(LDQ_BANK_SIZE)
        ) ldq_op_out_ram (
            .clock(clock),
            .r_en(ldq_bypass_r_en[cache_res_idx][ldq_bank_idx]),
            .r_ram_idx(ldq_bypass_r_idx[cache_res_idx][ldq_bank_idx]),
            .r_data(ldq_bypass_r_data_bit[cache_res_idx][ldq_bank_idx]),
            .w_en(ldq_bypass_w_en[ldq_bank_idx]),
            .w_ram_idx(ldq_bypass_w_idx[ldq_bank_idx]),
            .w_data(ldq_bypass_w_data_bit[ldq_bank_idx])
        );
      end
    end
  endgenerate

  // -------------------------------------------------------
  // ldq_paddr
  // --------------------------------------------------------
  // st命令の実行時とかに参照されるので,ffで実装する. 
  logic [PADDR_WIDTH-1:0] ldq_paddr[NUM_OF_BANK][LDQ_BANK_SIZE];

  // ldqpaddrに入る情報と,paddrを手に入れたことで判明する次の状態. 
  // 例えば,before_reqとしてキャッシュにリクエストする手前のものとして保持することもあるし,
  // mmioへのアクセスならbeforemmio_reqとして保持する.またpfであることが判明した場合はLD_PFとして,
  // op_outされるのを待つ.
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
    logic [PADDR_WIDTH-1:0] paddr;
  } ldq_paddr_update_t;

  // ldq_updateは,入ってくるときにpaddrがすでに有効な環境なら入ってきたときに,
  // そうでないならtlbからの返却で使用する.
  // satpを書き換えたときやsret,mretを使用したときなどにはflushが入るので,
  // オーバーラップして両方が同時に起こり上書きされるといったようなことは起こり得ない.
  ldq_paddr_update_t ldq_paddr_update_op_in[NUM_OF_LD_ISSUE+NUM_OF_ST_AMO_ISSUE];
  ldq_paddr_update_t ldq_paddr_update_dtlb[NUM_OF_DTLB_RES];


  // ----------------------------------------------------------------
  // ldq_mask
  // ----------------------------------------------------------------
  logic [DW_SIZE-1:0] ldq_mask[NUM_OF_BANK][LDQ_BANK_SIZE];

  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
    logic [DW_SIZE-1:0] mask;
  } ldq_mask_update_t;

  ldq_mask_update_t ldq_mask_update[NUM_OF_LD_ISSUE+NUM_OF_ST_AMO_ISSUE];

  // -----------------------------------------------------------------
  // ldq_state
  // -----------------------------------------------------------------
  ld_state_t ldq_state[NUM_OF_BANK][LDQ_BANK_SIZE];


  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
    ld_state_t next_state;
  } ldq_state_update_t;

  // NONEからBEFORE_ARRIVEへ
  ldq_state_update_t ldq_alloc_update[NUM_OF_FETCH];

  // op_inが入ってきたことによる遷移
  // アドレス変換が有効ならLD_BEFORE_TLB_REQUESTに,
  // そうでない場合は物理アドレスに応じてBEFORE_CACHE_REQ,BEFORE_MMIO_REQ,ACCESS_FAULTに
  ldq_state_update_t ldq_op_in_update[NUM_OF_LD_ISSUE+NUM_OF_ST_AMO_ISSUE];

  // TLBでリクエストを出したときに,BEFORE_TLB_REQからDURING_TLB_REQに推移
  ldq_state_update_t ldq_tlb_req_update[NUM_OF_LD_ISSUE];

  // TLBのリクエストが帰ってきたことによる,DURING_TLB_REQから,
  // BEFORE_CACHE_REQ,BEFORE_MMIO_REQ,PAGE_FAULT, ACCESS_FAULTのいずれかに繊維.
  ldq_state_update_t ldq_tlb_res_update[NUM_OF_DTLB_RES];

  // リクエストを出したことによる,BEFORE_CACHE_REQからDURING_CACHE_REQ,
  // あるいはBEFORE_MMIO_REQからDURING_MMIO_REQへの遷移
  ldq_state_update_t ldq_req_out_update[NUM_OF_LD_EXE];

  // キャッシュからデータが帰ってきたときに, DURING_CACHE_REQ,DURING_MMIO_REQから
  // LD_DONEへの遷移.
  ldq_state_update_t ldq_done_update[NUM_OF_CACHE_RES];

  // alでコミットしたときに削除することによる,
  // LD_DONEからLD_NONEへの遷移.
  ldq_state_update_t ldq_delete_update[NUM_OF_GRADUATE];


  // ----------------------------------------------------------------------------------------
  // stq
  // -----------------------------------------------------------------------------------------


  // --------------------------------------------------------------
  // stq_op_out
  // --------------------------------------------------------------
  // 正直なところ,stqが今のところ1つしか同時に入ってこないし,バンク化する必要性は薄いが将来への
  // 拡張性とかldqとフォーマットを整えるために導入する.

  // cacheから戻ってきたデータと一緒にして,op_outを作成するためのデータをまとめたもの.
  typedef struct packed {
    opcode_t opcode;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [VADDR_WIDTH-1:0] op_vaddr;
    logic [VADDR_WIDTH-1:0] target_vaddr;
  } stq_op_out_t;

  logic stq_op_out_r_en[NUM_OF_BANK];
  logic [STQ_INBANK_IDX_WIDTH-1:0] stq_op_out_r_idx[NUM_OF_BANK];
  logic [$bits(stq_op_out_t)-1:0] stq_op_out_r_data_bit[NUM_OF_BANK];

  logic stq_op_out_w_en[NUM_OF_BANK];
  logic [STQ_INBANK_IDX_WIDTH-1:0] stq_op_out_w_idx[NUM_OF_BANK];
  logic [$bits(stq_op_out_t)-1:0] stq_op_out_w_data_bit[NUM_OF_BANK];

  stq_op_out_t stq_op_out_w_data_strc[NUM_OF_BANK];
  stq_op_out_t stq_op_out_r_data_strc[NUM_OF_BANK];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      stq_op_out_r_data_strc[i] = stq_op_out_r_data_bit[i];
      stq_op_out_w_data_bit[i]  = stq_op_out_w_data_strc[i];
    end
  end

  generate
    for (
        genvar stq_op_out_gen_idx = 0; stq_op_out_gen_idx < NUM_OF_BANK; stq_op_out_gen_idx++
    ) begin : g_stq_op_out_ram
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(stq_op_out_t)),
          .RAM_DEPTH(STQ_BANK_SIZE)
      ) stq_op_out_ram (
          .clock(clock),
          .r_en(stq_op_out_r_en[stq_op_out_gen_idx]),
          .r_ram_idx(stq_op_out_r_idx[stq_op_out_gen_idx]),
          .r_data(stq_op_out_r_data_bit[stq_op_out_gen_idx]),
          .w_en(stq_op_out_w_en[stq_op_out_gen_idx]),
          .w_ram_idx(stq_op_out_w_idx[stq_op_out_gen_idx]),
          .w_data(stq_op_out_w_data_bit[stq_op_out_gen_idx])
      );
    end
  endgenerate

  // ----------------------------------------------------------------------------------
  // stq_tlb
  // ----------------------------------------------------------------------------------


  // tlbにリクエストするときに必要な内容.
  typedef struct packed {
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] target_vaddr;
  } stq_tlb_t;

  logic stq_tlb_r_en[NUM_OF_BANK];
  logic [STQ_INBANK_IDX_WIDTH-1:0] stq_tlb_r_idx[NUM_OF_BANK];
  logic [$bits(stq_tlb_t)-1:0] stq_tlb_r_data_bit[NUM_OF_BANK];

  logic stq_tlb_w_en[NUM_OF_BANK];
  logic [STQ_INBANK_IDX_WIDTH-1:0] stq_tlb_w_idx[NUM_OF_BANK];
  logic [$bits(stq_tlb_t)-1:0] stq_tlb_w_data_bit[NUM_OF_BANK];

  stq_tlb_t stq_tlb_w_data_strc[NUM_OF_BANK];
  stq_tlb_t stq_tlb_r_data_strc[NUM_OF_BANK];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      stq_tlb_r_data_strc[i] = stq_tlb_r_data_bit[i];
      stq_tlb_w_data_bit[i]  = stq_tlb_w_data_strc[i];
    end
  end

  genvar stq_tlb_gen_idx;
  generate
    for (stq_tlb_gen_idx = 0; stq_tlb_gen_idx < NUM_OF_BANK; stq_tlb_gen_idx++) begin : g_stq_tlb
      ram_1r1w_bram #(
          .RAM_WIDTH($bits(stq_tlb_t)),
          .RAM_DEPTH(STQ_BANK_SIZE)
      ) stq_tlb (
          .clock(clock),
          .r_en(stq_tlb_r_en[stq_tlb_gen_idx]),
          .r_ram_idx(stq_tlb_r_idx[stq_tlb_gen_idx]),
          .r_data(stq_tlb_r_data_bit[stq_tlb_gen_idx]),
          .w_en(stq_tlb_w_en[stq_tlb_gen_idx]),
          .w_ram_idx(stq_tlb_w_idx[stq_tlb_gen_idx]),
          .w_data(stq_tlb_w_data_bit[stq_tlb_gen_idx])
      );
    end
  endgenerate


  // --------------------------------------------------------------------------------------
  // stq rs2
  // --------------------------------------------------------------------------------------
  // stq_rs2は入力としてはop_in(1)とcacheから帰ってくるamo(2)の二系統の合計3書き込みと
  // cacheに出す1読み込みを持つ.
  // アクセスに際してはバンク化せず,{stq_idx,stq_bank_idx}でアクセスする.

  logic stq_rs2_r_en[NUM_OF_ST_EXE];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_rs2_r_idx[NUM_OF_ST_EXE];
  logic [63:0] stq_rs2_r_data[NUM_OF_ST_EXE];

  logic stq_rs2_w_en[NUM_OF_ST_AMO_ISSUE+NUM_OF_CACHE_RES];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_rs2_w_idx[NUM_OF_ST_AMO_ISSUE+NUM_OF_CACHE_RES];
  logic [63:0] stq_rs2_w_data[NUM_OF_ST_AMO_ISSUE+NUM_OF_CACHE_RES];

  logic stq_rs2_w_en_op_in[NUM_OF_ST_AMO_ISSUE];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_rs2_w_idx_op_in[NUM_OF_ST_AMO_ISSUE];
  logic [63:0] stq_rs2_w_data_op_in[NUM_OF_ST_AMO_ISSUE];

  logic stq_rs2_w_en_amo_res[NUM_OF_CACHE_RES];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_rs2_w_idx_amo_res[NUM_OF_CACHE_RES];
  logic [63:0] stq_rs2_w_data_amo_res[NUM_OF_CACHE_RES];

  // op_inから直接書き込む部分と,cacheからのamoのld部分で読み込んだもの.
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      stq_rs2_w_en[i]   = stq_rs2_w_en_op_in[i];
      stq_rs2_w_idx[i]  = stq_rs2_w_idx_op_in[i];
      stq_rs2_w_data[i] = stq_rs2_w_data_op_in[i];
    end
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      stq_rs2_w_en[NUM_OF_ST_AMO_ISSUE+i]   = stq_rs2_w_en_amo_res[i];
      stq_rs2_w_idx[NUM_OF_ST_AMO_ISSUE+i]  = stq_rs2_w_idx_amo_res[i];
      stq_rs2_w_data[NUM_OF_ST_AMO_ISSUE+i] = stq_rs2_w_data_amo_res[i];
    end
  end

  LVTRAM #(
      .RAM_WIDTH(64),
      .RAM_DEPTH(STQ_BANK_SIZE * NUM_OF_BANK),
      .NUM_OF_READ_PORT(NUM_OF_ST_EXE),
      .NUM_OF_WRITE_PORT(NUM_OF_ST_AMO_ISSUE + NUM_OF_CACHE_RES)
  ) ldq_op_out_ram (
      .clock(clock),
      .reset(reset),
      .r_en(stq_rs2_r_en),
      .r_ram_idx(stq_rs2_r_idx),
      .r_data(stq_rs2_r_data),
      .w_en(stq_rs2_w_en),
      .w_ram_idx(stq_rs2_w_idx),
      .w_data(stq_rs2_w_data)
  );


  // ------------------------------------------------------------------------------------------------------------
  // stq_rs2_bypass
  // ------------------------------------------------------------------------------------------------------------
  // bypassのときはbyte単位で別々のstqエントリにアクセスするので,byte単位でバンクを作る.
  // 書き込みはstq_rs2と共通.
  // 読み込みのidxは, {ldq_idx,ldq_bank_idx}になる.読み込みポートの数は NUM_OF_LD_EXE


  logic stq_rs2_bypass_r_en[8][NUM_OF_LD_EXE];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_rs2_bypass_r_idx[8][NUM_OF_LD_EXE];
  logic [7:0] stq_rs2_bypass_r_data[8][NUM_OF_LD_EXE];

  logic [7:0] stq_rs2_bypass_w_data_byte[8][NUM_OF_ST_AMO_ISSUE+NUM_OF_CACHE_RES];

  always_comb begin
    for (int unsigned w_idx = 0; w_idx < NUM_OF_ST_AMO_ISSUE + NUM_OF_CACHE_RES; w_idx++) begin
      for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
        stq_rs2_bypass_w_data_byte[byte_idx][w_idx] = stq_rs2_w_data[w_idx][byte_idx*8+:8];
      end
    end
  end


  generate
    for (genvar byte_idx = 0; byte_idx < 8; byte_idx++) begin : g_stq_rs2_bypass
      LVTRAM #(
          .RAM_WIDTH(8),
          .RAM_DEPTH(STQ_BANK_SIZE * NUM_OF_BANK),
          .NUM_OF_READ_PORT(NUM_OF_LD_EXE),
          .NUM_OF_WRITE_PORT(NUM_OF_ST_AMO_ISSUE + NUM_OF_CACHE_RES)
      ) stq_rs2_bypass (
          .clock(clock),
          .reset(reset),
          .r_en(stq_rs2_bypass_r_en[byte_idx]),
          .r_ram_idx(stq_rs2_bypass_r_idx[byte_idx]),
          .r_data(stq_rs2_bypass_r_data[byte_idx]),
          .w_en(stq_rs2_w_en),
          .w_ram_idx(stq_rs2_w_idx),
          .w_data(stq_rs2_bypass_w_data_byte[byte_idx])
      );
    end
  endgenerate

  // --------------------------------------------------------------------------------------------------------------
  // stq_amo_rs2
  // --------------------------------------------------------------------------------------------------------------
  // op_inでかきこんで,cacheから帰ってきたamoの結果と演算した結果をstq_rs2に入れる. 
  // 完全な1w+2r
  // st_amo_issueの数が1なので,シンプルなバンク化で実装できる
  typedef struct packed {
    opcode_t opcode;  // amo計算用
    logic [63:0] data;
  } stq_amo_rs2_t;
  logic stq_amo_rs2_r_en[NUM_OF_CACHE_RES];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_amo_rs2_r_idx[NUM_OF_CACHE_RES];
  logic [$bits(stq_amo_rs2_t)-1:0] stq_amo_rs2_r_data_bit[NUM_OF_CACHE_RES];

  logic stq_amo_rs2_w_en[NUM_OF_ST_AMO_ISSUE];
  logic [STQ_INBANK_IDX_WIDTH+BANK_IDX_WIDTH-1:0] stq_amo_rs2_w_idx[NUM_OF_ST_AMO_ISSUE];
  logic [$bits(stq_amo_rs2_t)-1:0] stq_amo_rs2_w_data_bit[NUM_OF_ST_AMO_ISSUE];

  stq_amo_rs2_t stq_amo_rs2_r_data_strc[NUM_OF_CACHE_RES];
  stq_amo_rs2_t stq_amo_rs2_w_data_strc[NUM_OF_ST_AMO_ISSUE];

  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      stq_amo_rs2_r_data_strc[i] = stq_amo_rs2_r_data_bit[i];
    end
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      stq_amo_rs2_w_data_bit[i] = stq_amo_rs2_w_data_strc[i];
    end
  end

  LVTRAM #(
      .RAM_WIDTH($bits(stq_amo_rs2_t)),
      .RAM_DEPTH(STQ_BANK_SIZE * NUM_OF_BANK),
      .NUM_OF_READ_PORT(NUM_OF_CACHE_RES),
      .NUM_OF_WRITE_PORT(NUM_OF_ST_AMO_ISSUE)
  ) stq_amo_rs2 (
      .clock(clock),
      .reset(reset),
      .r_en(stq_amo_rs2_r_en),
      .r_ram_idx(stq_amo_rs2_r_idx),
      .r_data(stq_amo_rs2_r_data_bit),
      .w_en(stq_amo_rs2_w_en),
      .w_ram_idx(stq_amo_rs2_w_idx),
      .w_data(stq_amo_rs2_w_data_bit)
  );


  // ------------------------------------------------------------------------------------------------------------
  // stq_paddr, stq_to_al_idx, stq_mask,stq_state
  // ------------------------------------------------------------------------------------------------------------
  // 各種FFで実装されるstqのフィールド
  // 

  // st命令の実行時とかに参照されるので,ffで実装する. 
  logic [PADDR_WIDTH-1:0] stq_paddr[NUM_OF_BANK][STQ_BANK_SIZE];

  // ldqpaddrに入る情報と,paddrを手に入れたことで判明する次の状態. 
  // 例えば,before_reqとしてキャッシュにリクエストする手前のものとして保持することもあるし,
  // mmioへのアクセスならbeforemmio_reqとして保持する.またpfであることが判明した場合はLD_PFとして,
  // op_outされるのを待つ.
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    logic [PADDR_WIDTH-1:0] paddr;
  } stq_paddr_update_t;

  // ldq_updateは,入ってくるときにpaddrがすでに有効な環境なら入ってきたときに,
  // そうでないならtlbからの返却で使用する.
  // satpを書き換えたときやsret,mretを使用したときなどにはflushが入るので,
  // オーバーラップして両方が同時に起こり上書きされるといったようなことは起こり得ない.
  stq_paddr_update_t stq_paddr_update_op_in[NUM_OF_ST_AMO_ISSUE];
  stq_paddr_update_t stq_paddr_update_dtlb[NUM_OF_DTLB_RES];


  // アドレスとdw_alignedしたときに,データのどこの位置が有効かをbyte単位で管理する. 
  // 例えば,下3bitが3'b011でstore half wordの場合, 8'b0001_1000 となる. 
  logic [7:0] stq_mask[NUM_OF_BANK][STQ_BANK_SIZE];


  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    logic [DW_SIZE-1:0] mask;
  } stq_mask_update_t;

  stq_mask_update_t stq_mask_update[NUM_OF_ST_AMO_ISSUE];

  // 各stqエントリの状態.
  st_state_t stq_state[NUM_OF_BANK][STQ_BANK_SIZE];

  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    st_state_t next_state;
  } stq_state_update_t;


  // ST_NONEからST_BEFORE_ARRIVEへ
  stq_state_update_t stq_alloc_update[NUM_OF_FETCH];

  // op_inが入ってきたことによる遷移
  // アドレス変換が有効ならST_BEFORE_TLB_REQUEST,ST_BEFORE_TLB_REQUEST_COND, ST_AMO_WAITING に,
  // そうでない場合は物理アドレスに応じてBEFORE_EXE,BEFORE_EXE_COND,BEFORE_EXE_MMIO,ACCESS_FAULTに遷移する
  stq_state_update_t stq_op_in_update[NUM_OF_ST_AMO_ISSUE];

  // TLBでリクエストを出したときに,BEFORE_TLB_REQ=>DURING_TLB_REQ, BEFORE_TLB_REQ_COND => DURING_TLB_REQ_CONDに推移
  stq_state_update_t stq_tlb_req_update[NUM_OF_ST_AMO_ISSUE];

  // 
  stq_state_update_t stq_tlb_res_update[NUM_OF_DTLB_RES];

  // amo命令で対応するldのデータが帰ってきたときに,amo_waiting_rs2からST_BEFORE_EXEに
  stq_state_update_t stq_amo_get_rs2_update[NUM_OF_CACHE_RES];

  // stを実行してBBEFORE_EXEからST_DONEへ遷移.
  stq_state_update_t stq_exe_done_update[NUM_OF_ST_EXE];


  // alでコミットしたときに削除する.
  stq_state_update_t stq_delete_update[NUM_OF_GRADUATE];


  // -------------------------------------------------------------------------
  //  al_idx to ldq,stq idx
  // -------------------------------------------------------------------------
  // al_idxをldq_idxに変換する.
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  } al_to_ldq_idx_t;
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } al_to_stq_idx_t;

  al_to_ldq_idx_t al_to_ldq_idx[ACTIVELIST_SIZE];
  al_to_stq_idx_t al_to_stq_idx[ACTIVELIST_SIZE];

  // ldq_bank_idx,ldq_idx から al_idx を得る関数的に用いる.
  logic [AL_IDX_WIDTH-1:0] ldq_to_al_idx[NUM_OF_BANK][LDQ_BANK_SIZE];
  // stq_bank_idx,stq_idxからal_idxを取得.
  logic [AL_IDX_WIDTH-1:0] stq_to_al_idx[NUM_OF_BANK][STQ_BANK_SIZE];

  // 上の関数と逆関数の更新用のパラメタ.
  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  } al_ldq_conv_update_t;

  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } al_stq_conv_update_t;

  al_ldq_conv_update_t al_ldq_conv_new[NUM_OF_FETCH];
  al_stq_conv_update_t al_stq_conv_new[NUM_OF_FETCH];

  al_ldq_conv_update_t al_ldq_conv_del[NUM_OF_GRADUATE];
  al_stq_conv_update_t al_stq_conv_del[NUM_OF_GRADUATE];


  // ---------------------------------------------------------------------------------------------
  // amo_ldq_idx_to_stq_idx
  // ---------------------------------------------------------------------------------------------
  // amo命令のレスポンスがキャッシュから帰ってきたときに,そのid(ldq_bank_idx,ldq_idx)から
  // それがamo命令か,そうならどのstqに対応するかを変換するテーブル
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } amo_ldq_to_stq_t;
  amo_ldq_to_stq_t amo_ldq_to_stq[NUM_OF_BANK][LDQ_BANK_SIZE];

  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  } amo_ldq_to_stq_update_t;

  // typedef struct packed {
  //   logic valid;
  //   logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
  //   logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  // } amo_ldq_to_stq_del_t;

  amo_ldq_to_stq_update_t amo_ldq_to_stq_new[NUM_OF_FETCH];
  // 削除はal_ldq_conv_delを流用する.


  // -----------------------------------------------
  // fence queue, fence table
  // -----------------------------------------------


  typedef struct packed {
    logic valid;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    // このfenceよりal_idxが後ろにあるld命令をブロックするか.
    logic block_suc_ld;
    logic block_suc_st;
  } fenceq_t;

  fenceq_t fenceq[FENCEQ_SIZE];
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_rp;
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_wp;
  logic [FENCEQ_IDX_WIDTH:0] noei_fenceq;


  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    logic block_suc_ld;
    logic block_suc_st;
  } fenceq_update_t;
  fenceq_t fenceq_update[NUM_OF_BANK];

  int unsigned num_of_new_fence;
  int unsigned num_of_del_fence;

  // fence table
  // fenceqを,al_idxから参照できる形に変形したもの.
  // あるal_idxを持つ命令がldならfenceによってブロックされるとき,ft[al_idx].ld_blocked == 1.
  typedef struct packed {
    logic ld_blocked;
    logic st_blocked;
  } ft_t;
  ft_t ft[ACTIVELIST_SIZE];


  // ------------------------------------------------------------
  // ld_speculative_feedback
  // ------------------------------------------------------------
  // lsu <=> renamerでのループを解消するために, lsu => renamerの内容をalwaysffで1サイクル遅らせる.
  logic ld_speculative_feedback_valid_next;
  logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx_next;



  //　現在のalにおいて,al_idx_leftがal_idx_rightより古いものか 
  function automatic logic is_left_older(logic [AL_IDX_WIDTH-1:0] al_idx_left,
                                         logic [AL_IDX_WIDTH-1:0] al_idx_right);
    // ここでは,ある特定のalのエントリを引数として受け渡しているので,alにはエントリが存在する,
    // つまりrp==wpなら空ではなく満タンとして考える.
    automatic logic [AL_IDX_WIDTH-1:0] al_rp = renamer_port.al_rp;
    automatic logic [AL_IDX_WIDTH-1:0] al_wp = renamer_port.al_wp;
    return (al_rp<=al_idx_left && al_idx_left<al_idx_right && al_idx_right<al_wp) ||
           (al_wp <= al_rp && al_rp <= al_idx_left && al_idx_left < al_idx_right) ||
           (al_idx_right < al_wp && al_wp <= al_rp && al_rp<= al_idx_left) ||
           (al_idx_left < al_idx_right && al_idx_right < al_wp && al_wp<=al_rp);
  endfunction


  function automatic logic [63:0] amo_calc(opcode_t opcode, logic [63:0] rs1_mem_val,
                                           logic [63:0] rs2_val);
    logic [63:0] result;
    case (opcode)
      AMOSWAP_D: result = rs2_val;
      AMOADD_D: result = rs1_mem_val + rs2_val;
      AMOXOR_D: result = rs1_mem_val ^ rs2_val;
      AMOAND_D: result = rs1_mem_val & rs2_val;
      AMOOR_D: result = rs1_mem_val | rs2_val;
      AMOMIN_D: result = signed'(rs1_mem_val) < signed'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMAX_D: result = signed'(rs1_mem_val) > signed'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMINU_D: result = unsigned'(rs1_mem_val) < unsigned'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMAXU_D: result = unsigned'(rs1_mem_val) > unsigned'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOSWAP_W: result = 64'(signed'(rs2_val[31:0]));
      AMOADD_W: result = 64'(signed'(rs1_mem_val[31:0] + rs2_val[31:0]));
      AMOXOR_W: result = 64'(signed'(rs1_mem_val[31:0] ^ rs2_val[31:0]));
      AMOAND_W: result = 64'(signed'(rs1_mem_val[31:0] & rs2_val[31:0]));
      AMOOR_W: result = 64'(signed'(rs1_mem_val[31:0] | rs2_val[31:0]));
      AMOMIN_W:
      result = signed'(rs1_mem_val[31:0]) < signed'(rs2_val[31:0]) ? 64'(signed'(rs1_mem_val[31:0])) : 64'(signed'(rs2_val[31:0]));
      AMOMAX_W:
      result = signed'(rs1_mem_val[31:0]) > signed'(rs2_val[31:0]) ?  64'(signed'(rs1_mem_val[31:0])) : 64'(signed'(rs2_val[31:0]));
      AMOMINU_W:
      result = unsigned'(rs1_mem_val[31:0]) < unsigned'(rs2_val[31:0]) ?  64'(signed'(rs1_mem_val[31:0])) : 64'(signed'(rs2_val[31:0]));
      AMOMAXU_W:
      result = unsigned'(rs1_mem_val[31:0]) > unsigned'(rs2_val[31:0]) ?  64'(signed'(rs1_mem_val[31:0])) : 64'(signed'(rs2_val[31:0]));
      default: $display("[ERROR] [%s,%d]", `__FILE__, `__LINE__);
    endcase
    return result;
  endfunction

  function automatic logic [PADDR_WIDTH-1:0] to_dw_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] paddr_origin);
    return {paddr_origin[PADDR_WIDTH-1:$clog2(DW_SIZE)], {$clog2(DW_SIZE) {1'b0}}};
  endfunction


  // ------------------------------------------------------------------------------------------------------------------
  // feceqからfence tableの作成
  // ------------------------------------------------------------------------------------------------------------------
  always_comb begin
    // 新しいfenceから探索していくことで
    // st,ldそれぞれについて,ブロックしてくるfenceの内,最も古いもののal_idxを**_oldest_block_al_idxとする
    automatic logic ld_oldest_block_valid = 0;
    automatic logic st_oldest_block_valid = 0;
    automatic logic [AL_IDX_WIDTH-1:0] ld_oldest_block_al_idx = 0;
    automatic logic [AL_IDX_WIDTH-1:0] st_oldest_block_al_idx = 0;
    ft = '{default: 0};
    for (int unsigned i = 0; i < FENCEQ_SIZE; i++) begin
      automatic logic [FENCEQ_IDX_WIDTH-1:0] fenceq_idx = fenceq_rp + FENCEQ_IDX_WIDTH'(i);
      if (fenceq_idx == fenceq_wp) begin
        break;
      end
      if (!ld_oldest_block_valid && fenceq[fenceq_idx].block_suc_ld) begin
        ld_oldest_block_valid  = 1;
        ld_oldest_block_al_idx = fenceq[fenceq_idx].al_idx;
      end
      if (!st_oldest_block_valid && fenceq[fenceq_idx].block_suc_st) begin
        st_oldest_block_valid  = 1;
        st_oldest_block_al_idx = fenceq[fenceq_idx].al_idx;
      end
    end

    // ftの作成.
    begin
      automatic logic ld_blocked = 0;
      automatic logic st_blocked = 0;
      for (int unsigned i = 0; i < ACTIVELIST_SIZE; i++) begin
        automatic logic [AL_IDX_WIDTH-1:0] al_idx = renamer_port.al_rp + AL_IDX_WIDTH'(i);
        if (ld_oldest_block_valid && al_idx == ld_oldest_block_al_idx) begin
          ld_blocked = 1;
        end
        if (st_oldest_block_valid && al_idx == st_oldest_block_al_idx) begin
          st_blocked = 1;
        end
        ft[al_idx] = '{ld_blocked: ld_blocked, st_blocked: st_blocked};
      end
    end
  end


  // ------------------------------------------------------------------------------------------
  // ldq,stqのでそれぞれ,
  // ldq,stqで空いているエントリを探す&stallするべきかを判別する
  // ------------------------------------------------------------------------------------------
  // 走査する先頭のldq_idx,stq_idx.毎サイクル1ずつずれる. 
  logic [LDQ_INBANK_IDX_WIDTH-1:0] rr_ldq_idx;
  logic [STQ_INBANK_IDX_WIDTH-1:0] rr_stq_idx;

  typedef struct packed {
    logic valid;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  } ldq_ent_t;

  typedef struct packed {
    logic valid;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } stq_ent_t;

  // ldqの内,以下の状態のものをそれぞれ各バンクごとに一つ用意する.
  // 各処理では以下から好きなものを選んで使用する.
  // TODO: ただ,少し問題なのは,今は各処理がラウンドロビン用のbank_idxを持っておりそこからbank_idx+1,bank_idx+2と
  // 探索していく形になっている.各処理で使われるラウンドロビン用のbank_idxをずらしていく周期と,ここで使用しているrr_ldq_idxの周期が
  // 重なった場合偏りを生み出すことになる.まあ,動くしそこまで問題でも無い.時間があったらどうにかする.
  ldq_ent_t ldq_free_avail[NUM_OF_BANK];
  ldq_ent_t ldq_before_tlb_avail[NUM_OF_BANK];
  ldq_ent_t ldq_before_cache_req_avail[NUM_OF_BANK];
  ldq_ent_t ldq_before_mmio_req_avail[NUM_OF_BANK];
  ldq_ent_t ldq_pf_avail[NUM_OF_BANK];
  ldq_ent_t ldq_af_avail[NUM_OF_BANK];

  // stq版
  stq_ent_t stq_free_avail[NUM_OF_BANK];
  stq_ent_t stq_before_tlb_avail[NUM_OF_BANK];
  stq_ent_t stq_before_tlb_cond_avail[NUM_OF_BANK];
  stq_ent_t stq_before_exe_avail[NUM_OF_BANK];
  stq_ent_t stq_before_exe_cond_avail[NUM_OF_BANK];
  stq_ent_t stq_before_mmio_exe_avail[NUM_OF_BANK];
  stq_ent_t stq_pf_avail[NUM_OF_BANK];
  stq_ent_t stq_af_avail[NUM_OF_BANK];

  int unsigned ld_free_counter[NUM_OF_BANK];
  int unsigned st_free_counter[NUM_OF_BANK];


  always_comb begin
    // automatic int unsigned ld_free_counter[NUM_OF_BANK] = '{default: 0};
    // automatic int unsigned st_free_counter[NUM_OF_BANK] = '{default: 0};
    ld_free_counter            = '{default: 0};
    st_free_counter            = '{default: 0};


    ldq_free_avail             = '{default: '0};
    ldq_before_tlb_avail       = '{default: '0};
    ldq_before_cache_req_avail = '{default: '0};
    ldq_before_mmio_req_avail  = '{default: '0};
    ldq_pf_avail               = '{default: '0};
    ldq_af_avail               = '{default: '0};

    stq_free_avail             = '{default: '0};
    stq_before_tlb_avail       = '{default: '0};
    stq_before_tlb_cond_avail  = '{default: '0};
    stq_before_exe_avail       = '{default: '0};
    stq_before_exe_cond_avail  = '{default: '0};
    stq_before_mmio_exe_avail  = '{default: '0};
    stq_pf_avail               = '{default: '0};
    stq_af_avail               = '{default: '0};

    // ldの各種availを作成.
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      for (int unsigned j = 0; j < LDQ_BANK_SIZE; j++) begin
        automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = rr_ldq_idx + LDQ_INBANK_IDX_WIDTH'(j);
        if (ldq_state[i][ldq_idx] == LD_NONE) begin
          ldq_free_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
          ld_free_counter[i]++;
        end else if (ldq_state[i][ldq_idx] == LD_BEFORE_TLB_REQUEST) begin
          ldq_before_tlb_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
        end else if (ldq_state[i][ldq_idx] == LD_BEFORE_CACHE_REQUEST && !ft[ldq_to_al_idx[i][ldq_idx]].ld_blocked) begin
          ldq_before_cache_req_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
        end else if (ldq_state[i][ldq_idx] == LD_BEFORE_MMIO_REQUEST && renamer_port.al_rp == ldq_to_al_idx[i][ldq_idx] 
                    && !ft[ldq_to_al_idx[i][ldq_idx]].ld_blocked) begin
          ldq_before_mmio_req_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
        end else if (ldq_state[i][ldq_idx] == LD_PAGE_FAULT) begin
          ldq_pf_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
        end else if (ldq_state[i][ldq_idx] == LD_ACCESS_FAULT) begin
          ldq_af_avail[i] = '{valid: 1, ldq_idx: ldq_idx};
        end
      end
    end

    // st
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      for (int unsigned j = 0; j < STQ_BANK_SIZE; j++) begin
        automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = rr_stq_idx + STQ_INBANK_IDX_WIDTH'(j);
        if (stq_state[i][stq_idx] == ST_NONE) begin
          stq_free_avail[i] = '{valid: 1, stq_idx: stq_idx};
          st_free_counter[i]++;
        end else if (stq_state[i][stq_idx] == ST_BEFORE_TLB_REQUEST) begin
          stq_before_tlb_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if (stq_state[i][stq_idx] == ST_BEFORE_TLB_REQUEST_CONDITIONAL) begin
          stq_before_tlb_cond_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if (stq_state[i][stq_idx] == ST_BEFORE_EXE && !ft[stq_to_al_idx[i][stq_idx]].st_blocked) begin
          stq_before_exe_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if(stq_state[i][stq_idx] == ST_BEFORE_EXE_CONDITIONAL && renamer_port.al_rp == stq_to_al_idx[i][stq_idx]
              && !ft[stq_to_al_idx[i][stq_idx]].st_blocked) begin
          // scはalの先頭にあれば実行はできる.成功かどうかは実行時に判断する.
          stq_before_exe_cond_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if (stq_state[i][stq_idx] == ST_BEFORE_MMIO_EXE && renamer_port.al_rp == stq_to_al_idx[i][stq_idx]
              && !ft[stq_to_al_idx[i][stq_idx]].st_blocked) begin
          stq_before_mmio_exe_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if (stq_state[i][stq_idx] == ST_PAGE_FAULT) begin
          stq_pf_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end else if (stq_state[i][stq_idx] == ST_ACCESS_FAULT) begin
          stq_af_avail[i] = '{valid: 1, stq_idx: stq_idx};
        end
      end
    end

    // stall信号を出す
    // いずれかのバンクの空き1以下なら次のサイクルで入ってくるのを止める. 
    // 最悪のパターンでは今のサイクルで1つ使用し,次のサイクルでも1つ使用するため. 
    stall_append_to_al = 0;
    for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
      if (st_free_counter[i] <= 1 || ld_free_counter[i] <= 1) begin
        stall_append_to_al = 1;
      end
    end
    if (FENCEQ_SIZE - 32'(noei_fenceq) <= NUM_OF_FETCH) begin
      stall_append_to_al = 1;
    end
  end

  logic stall_append_to_al_prev;
  always_ff @(posedge clock) begin
    if (reset) begin
      stall_append_to_al_prev <= 0;
    end else if (flush_in) begin
      stall_append_to_al_prev <= stall_append_to_al;
    end else begin
      stall_append_to_al_prev <= stall_append_to_al;
    end
  end
  always_comb begin
    // if (stall_append_to_al && !stall_append_to_al_prev) begin
    //   $display("[LOG][LSU.sv] stall_append_to_al on");
    // end
    // if (!stall_append_to_al && stall_append_to_al_prev) begin
    //   $display("[LOG][LSU.sv] stall_append_to_al off");
    // end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      rr_ldq_idx <= 0;
      rr_stq_idx <= 0;
    end else if (flush_in) begin
      rr_ldq_idx <= 0;
      rr_stq_idx <= 0;
    end else begin
      rr_ldq_idx <= rr_ldq_idx + 1;
      rr_stq_idx <= rr_stq_idx + 1;
      // dump_ldq_state();
      // dump_stq_state();
      // for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
      //   if (op_ld_in[i].valid) dump_op(op_ld_in[i]);
      // end
      // for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      //   if (op_st_amo_in[i].valid) dump_op(op_st_amo_in[i]);
      // end
    end
  end

  // ---------------------------------------------------------------------
  // alに入ってきたinstrをldq,stq,fenceqに反映
  // ---------------------------------------------------------------------
  always_comb begin

    // 初期化.
    al_ldq_conv_new = '{default: 0};
    al_stq_conv_new = '{default: 0};
    amo_ldq_to_stq_new = '{default: 0};

    ldq_alloc_update = '{default: 0};
    stq_alloc_update = '{default: 0};

    fenceq_update = '{default: 0};
    num_of_new_fence = 0;

    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      // bank_idxはal_idxの下位BANK_IDX_WIDTH桁を抜き出して用いることでirfからop_inが来たときも1アクセス/1バンクにすることができる.
      // これは,int issue queueでそうなるように発行しているから.
      automatic
      logic [BANK_IDX_WIDTH-1:0]
      bank_idx = renamer_port.new_instr[i].al_idx[BANK_IDX_WIDTH-1:0];

      if (renamer_port.new_instr[i].valid) begin
        if (is_ld_opcode(renamer_port.new_instr[i].opcode)) begin
          // ld命令をldqに追加する.
          // あくまでrenamerからldqでのスペースを確保するように通知が来ただけなので,
          // 実際にldq_op_outとかにデータを入れるのはop_inでデータが来たとき.
          // ここでは,al_idx=>ldq_idxの変換関数をつくってstateをBEFORE_ARRIVEにするだけ.
          // ldq_free_availは切れそうになったらstallされるため必ず存在するので,確認不要.
          al_ldq_conv_new[bank_idx] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              bank_idx: bank_idx,
              ldq_idx: ldq_free_avail[bank_idx].ldq_idx
          };
          ldq_alloc_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_free_avail[bank_idx].ldq_idx,
              next_state: LD_BEFORE_ARRIVE
          };
        end else if (is_st_opcode(renamer_port.new_instr[i].opcode)) begin
          // st命令をstqに追加する.
          al_stq_conv_new[bank_idx] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              bank_idx: bank_idx,
              stq_idx: stq_free_avail[bank_idx].stq_idx
          };
          // 情報をBEFORE_ARRIVEに更新.
          stq_alloc_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_free_avail[bank_idx].stq_idx,
              next_state: ST_BEFORE_ARRIVE
          };
        end else if (is_amo_opcode(renamer_port.new_instr[i].opcode)) begin
          // amo命令をldq,stq両方に追加する.
          al_ldq_conv_new[bank_idx] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              bank_idx: bank_idx,
              ldq_idx: ldq_free_avail[bank_idx].ldq_idx
          };
          al_stq_conv_new[bank_idx] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              bank_idx: bank_idx,
              stq_idx: stq_free_avail[bank_idx].stq_idx
          };
          // amo命令の場合はamo_ldq_to_stq_newに登録する必要がある.
          amo_ldq_to_stq_new[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_free_avail[bank_idx].ldq_idx,
              stq_bank_idx: bank_idx,
              stq_idx: stq_free_avail[bank_idx].stq_idx
          };
          // 状態をBEFORE_ARRIVEに更新.
          ldq_alloc_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_free_avail[bank_idx].ldq_idx,
              next_state: LD_BEFORE_ARRIVE
          };
          stq_alloc_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_free_avail[bank_idx].stq_idx,
              next_state: ST_BEFORE_ARRIVE
          };
        end else if (renamer_port.new_instr[i].opcode == FENCE) begin
          // fenceqに追加
          fenceq_update[num_of_new_fence] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              block_suc_ld: renamer_port.new_instr[i].sr || renamer_port.new_instr[i].si,
              block_suc_st: renamer_port.new_instr[i].sw || renamer_port.new_instr[i].so
          };
          num_of_new_fence++;
        end
      end
    end
  end


  int unsigned degbug_counter_ld[NUM_OF_BANK];
  int unsigned degbug_counter_st[NUM_OF_BANK];
  int unsigned degbug_counter[NUM_OF_BANK];

  // -----------------------------------------------------------------------------------------------------------------------
  // op_in_ld,op_st_amo_in から ldqへのアップデート内容を作成
  // -----------------------------------------------------------------------------------------------------------------------
  always_comb begin
    degbug_counter_ld = '{default: 0};
    // 初期化
    ldq_paddr_update_op_in = '{default: 0};

    ldq_op_in_update = '{default: 0};

    ldq_tlb_w_en = '{default: 0};
    ldq_tlb_w_idx = '{default: 0};
    ldq_tlb_w_data_strc = '{default: 0};

    ldq_op_out_w_en = '{default: 0};
    ldq_op_out_w_idx = '{default: 0};
    ldq_op_out_w_data_strc = '{default: 0};

    ldq_mask_update = '{default: 0};

    // op_in_ld から ldqへのアップデート内容を作成
    for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
      if (op_ld_in[i].valid) begin
        automatic
        logic [LDQ_INBANK_IDX_WIDTH-1:0]
        ldq_idx = al_to_ldq_idx[op_ld_in[i].al_idx].ldq_idx;
        // iiqで調整しているのでbank_idxが被ることは無い.
        automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = op_ld_in[i].al_idx[BANK_IDX_WIDTH-1:0];

        // vaddr
        automatic
        logic [VADDR_WIDTH-1:0]
        target_vaddr = VADDR_WIDTH'(op_ld_in[i].rs1_val + op_ld_in[i].imm);

        automatic logic [7:0] ld_mask = 0;

        // ldq_op_outの更新. 
        ldq_op_out_w_en[bank_idx] = 1;
        ldq_op_out_w_idx[bank_idx] = ldq_idx;
        ldq_op_out_w_data_strc[bank_idx] = '{
            opcode: op_ld_in[i].opcode,
            rd: op_ld_in[i].rd,
            op_vaddr: op_ld_in[i].op_addr,
            target_vaddr: target_vaddr
        };

        // ldq_maskの作成
        case (op_ld_in[i].opcode)
          LB, LBU: ld_mask = 8'b0000_0001;
          LH, LHU: ld_mask = 8'b0000_0011;
          LW, LWU, LR_W: ld_mask = 8'b0000_1111;
          LD, LR_D: ld_mask = 8'b1111_1111;
          default: $display("[ERROR][LSU.sv]");
        endcase
        ld_mask = ld_mask << target_vaddr[2:0];



        // ldq_maskの作成
        ldq_mask_update[i] = '{
            valid: 1,
            ldq_bank_idx: bank_idx,
            ldq_idx: ldq_idx,
            mask: ld_mask
        };

        // DEBUG
        degbug_counter_ld[bank_idx] = degbug_counter_ld[bank_idx] + 1;

        // アドレス変換が有効か無効かで遷移先が異なる.
        if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin
          // paddrが判明している場合.
          automatic
          logic [PADDR_WIDTH-1:0]
          target_paddr = PADDR_WIDTH'(op_ld_in[i].rs1_val + op_ld_in[i].imm);
          // dump_op(op_ld_in[i]);

          // ldq_paddrをアップデート.
          ldq_paddr_update_op_in[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              paddr: target_paddr
          };

          // 状態の遷移
          ldq_op_in_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_NONE
          };
          if (get_device_name(target_paddr) == DN_DRAM) begin
            // メインメモリのpaddr.
            ldq_op_in_update[i].next_state = LD_BEFORE_CACHE_REQUEST;
            // $display("\n[LOG][LSU.sv] before_cache_request\n");
            // dump_op(op_ld_in[i]);
          end else if (get_device_name(
                  target_paddr
              ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
            ldq_op_in_update[i].next_state = LD_BEFORE_MMIO_REQUEST;
            // $display("\n[LOG][LSU.sv] before_mmio_request\n");
            // dump_op(op_ld_in[i]);
          end else begin
            // メインメモリ,deviceで無い場合,access_fault
            ldq_op_in_update[i].next_state = LD_ACCESS_FAULT;

            // $display("\n[LOG][LSU.sv] access_fault deteced in op_ld_in");
            // $display("[LOG][LSU.sv] priv_rval:%d  satp->MODE:%d  MMU_DISABLED:%b", priv_rval,
            //          satp.as_satp.MODE, MMU_DISABLED);
            // $display("[LOG][LSU.sv] target_paddr:0x%h", target_paddr);
            // $display("[LOG][LSU.sv] op_vaddr:0x%h\n rs1_val:%h imm:%h", op_ld_in[i].op_addr,
            //          op_ld_in[i].rs1_val, op_ld_in[i].imm);
            // dump_op(op_ld_in[i]);
            // $finish();
          end
        end else begin
          // paddrが判明していない場合
          // ldq_tlb_updateが存在すれば,自動的に次のstateはBEFORE_TLB_REQUEST

          // ldq_tlbにvaddrを入れる
          ldq_tlb_w_en[bank_idx] = 1;
          ldq_tlb_w_idx[bank_idx] = ldq_idx;
          ldq_tlb_w_data_strc[bank_idx] = '{
              opcode: op_ld_in[i].opcode,
              target_vaddr: target_vaddr
          };

          // 状態の更新.
          ldq_op_in_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_BEFORE_TLB_REQUEST
          };
        end
      end
    end

    // op_in_st_amoのうち,amo命令からldqへのアップデート内容を作成.
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      if (op_st_amo_in[i].valid && is_amo_opcode(op_st_amo_in[i].opcode)) begin
        automatic
        logic [LDQ_INBANK_IDX_WIDTH-1:0]
        ldq_idx = al_to_ldq_idx[op_st_amo_in[i].al_idx].ldq_idx;
        // iiqで調整しているのでbank_idxが被ることは無い.
        automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = op_st_amo_in[i].al_idx[BANK_IDX_WIDTH-1:0];

        automatic
        logic [VADDR_WIDTH-1:0]
        target_vaddr = VADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);
        automatic logic [7:0] ld_mask = 0;

        // ldq_op_outへの書き込み.
        ldq_op_out_w_en[bank_idx] = 1;
        ldq_op_out_w_idx[bank_idx] = ldq_idx;
        ldq_op_out_w_data_strc[bank_idx] = '{
            opcode: op_st_amo_in[i].opcode,
            rd: op_st_amo_in[i].rd,
            op_vaddr: op_st_amo_in[i].op_addr,
            target_vaddr: target_vaddr
        };



        // ldq_maskの作成
        // 投棄実行をしているので,misalignmentなtarget_vaddrを用いることがある
        // しかし,それをcacheに投げてしまうと,cache内部で不正な命令としてつまってしまう.
        // TODO: ここでmisalignmentを出す
        // とりあえずは,target_vaddrがmisalignedの場合はシフトしないという方法を使う.
        case (op_st_amo_in[i].opcode)
          AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
          AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:
          ld_mask = 8'b0000_1111;
          AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
          AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D:
          ld_mask = 8'b1111_1111;
          default: $display("[ERROR][LSU.sv]");
        endcase

        ld_mask = ld_mask << target_vaddr[2:0];
        // ldq_maskの作成
        ldq_mask_update[NUM_OF_LD_ISSUE+i] = '{
            valid: 1,
            ldq_bank_idx: bank_idx,
            ldq_idx: ldq_idx,
            mask: ld_mask
        };

        // DEBUG
        degbug_counter_ld[bank_idx] = degbug_counter_ld[bank_idx] + 1;


        if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin
          // paddrが判明している場合.
          automatic
          logic [PADDR_WIDTH-1:0]
          target_paddr = PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);

          // paddrのアップデート.
          ldq_paddr_update_op_in[NUM_OF_LD_ISSUE+i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              paddr: target_paddr
          };

          // 状態の遷移
          ldq_op_in_update[NUM_OF_LD_ISSUE+i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_NONE
          };
          if (get_device_name(target_paddr) == DN_DRAM) begin
            // メインメモリのpaddr.
            ldq_op_in_update[NUM_OF_LD_ISSUE+i].next_state = LD_BEFORE_CACHE_REQUEST;
          end else if (get_device_name(
                  target_paddr
              ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
            // deviceのpaddr
            ldq_op_in_update[NUM_OF_LD_ISSUE+i].next_state = LD_BEFORE_MMIO_REQUEST;
          end else begin
            // メインメモリ,deviceで無い場合,access_fault
            ldq_op_in_update[NUM_OF_LD_ISSUE+i].next_state = LD_ACCESS_FAULT;
            // $display("[LOG][LSU.sv] access_fault deteced in op_st_amo_in\n");
          end
        end else begin
          // paddrが判明していない場合.

          // ldq_tlbの更新.
          ldq_tlb_w_en[bank_idx] = 1;
          ldq_tlb_w_idx[bank_idx] = ldq_idx;
          ldq_tlb_w_data_strc[bank_idx] = '{
              opcode: op_st_amo_in[i].opcode,
              target_vaddr: target_vaddr
          };

          // 状態の更新.
          ldq_op_in_update[NUM_OF_LD_ISSUE+i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_BEFORE_TLB_REQUEST
          };


        end
      end
    end
  end

  // -----------------------------------------------------------------------------------------
  // op_st_amo_in から stqへのアップデート内容を作成
  // -----------------------------------------------------------------------------------------
  //(*mark_debug="true"*) logic st_af_detected;
  always_comb begin
    degbug_counter_st = '{default: 0};
    //
    stq_paddr_update_op_in = '{default: 0};
    stq_mask_update = '{default: 0};
    stq_op_in_update = '{default: 0};

    stq_tlb_w_en = '{default: 0};
    stq_tlb_w_idx = '{default: 0};
    stq_tlb_w_data_strc = '{default: 0};

    stq_op_out_w_en = '{default: 0};
    stq_op_out_w_idx = '{default: 0};
    stq_op_out_w_data_strc = '{default: 0};

    stq_amo_rs2_w_en = '{default: 0};
    stq_amo_rs2_w_idx = '{default: 0};
    stq_amo_rs2_w_data_strc = '{default: 0};

    stq_rs2_w_en_op_in = '{default: 0};
    stq_rs2_w_idx_op_in = '{default: 0};
    stq_rs2_w_data_op_in = '{default: 0};

    //(*mark_debug="true"*) logic st_af_detected = 0;


    // op_st_amo_inからstq_tlbの作成
    for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
      automatic
      logic [STQ_INBANK_IDX_WIDTH-1:0]
      stq_idx = al_to_stq_idx[op_st_amo_in[i].al_idx].stq_idx;
      // iiqで調整しているのでbank_idxが被ることは無い.
      automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = op_st_amo_in[i].al_idx[BANK_IDX_WIDTH-1:0];

      automatic
      logic [VADDR_WIDTH-1:0]
      target_vaddr = VADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);
      automatic logic [7:0] st_mask = 0;


      automatic logic [PADDR_WIDTH-1:0] target_paddr = 0;
      if (op_st_amo_in[i].valid) begin


        // stq_op_outへの書き込み.
        stq_op_out_w_en[bank_idx] = 1;
        stq_op_out_w_idx[bank_idx] = stq_idx;
        stq_op_out_w_data_strc[bank_idx] = '{
            opcode: op_st_amo_in[i].opcode,
            rd: op_st_amo_in[i].rd,
            op_vaddr: op_st_amo_in[i].op_addr,
            target_vaddr: target_vaddr
        };


        // stq_rs2,(とstq_rs2_bypass)に入れる.
        stq_rs2_w_en_op_in[i] = 1;
        stq_rs2_w_idx_op_in[i] = {stq_idx, bank_idx};
        // dw単位に揃えてからstq_rs2に書き込む. 
        stq_rs2_w_data_op_in[i] = 64'(op_st_amo_in[i].rs2_val << (target_vaddr[2:0] * 8));

        // stq_amo_rs2に書き込み.別にamoじゃない命令が書き込んでも影響は無い. 
        stq_amo_rs2_w_en[i] = 1;
        stq_amo_rs2_w_idx[i] = {stq_idx, bank_idx};
        stq_amo_rs2_w_data_strc[i] = '{
            opcode: op_st_amo_in[i].opcode,
            data: op_st_amo_in[i].rs2_val
        };

        // FORDEBG
        degbug_counter_st[bank_idx] = degbug_counter_st[bank_idx] + 1;

        // stq_maskの作成
        case (op_st_amo_in[i].opcode)
          SB: st_mask = 8'b0000_0001;
          SH: st_mask = 8'b0000_0011;
          SW, SC_W, AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
          AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:
          st_mask = 8'b0000_1111;
          SD, SC_D, AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
          AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D:
          st_mask = 8'b1111_1111;
          default: $display("[ERROR][LSU.sv]");
        endcase

        st_mask = st_mask << target_vaddr[2:0];
        // stq_maskの作成
        stq_mask_update[i] = '{
            valid: 1,
            stq_bank_idx: bank_idx,
            stq_idx: stq_idx,
            mask: st_mask
        };

        if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin
          // paddrが判明している場合.
          target_paddr = PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);

          // stq_paddrの更新
          stq_paddr_update_op_in[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              paddr: target_paddr
          };

          // opcodeやpaddrの場所による,次の状態の指定. 
          stq_op_in_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_NONE
          };
          if (is_sc_opcode(op_st_amo_in[i].opcode)) begin
            stq_op_in_update[i].next_state = ST_BEFORE_EXE_CONDITIONAL;
          end else if (is_amo_opcode(op_st_amo_in[i].opcode)) begin
            stq_op_in_update[i].next_state = ST_AMO_WAITING_RS2;
          end else if (get_device_name(target_paddr) == DN_DRAM) begin
            // メインメモリのpaddr.
            stq_op_in_update[i].next_state = ST_BEFORE_EXE;
          end else if (get_device_name(
                  target_paddr
              ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
            // deviceのpaddr
            stq_op_in_update[i].next_state = ST_BEFORE_MMIO_EXE;
          end else begin
            // メインメモリ,deviceで無い場合,access_fault
            stq_op_in_update[i].next_state = ST_ACCESS_FAULT;
            //st_af_detected = 1;
          end
        end else begin
          // paddrが判明していない場合.

          // stq_tlbのアップデート.
          stq_tlb_w_en[bank_idx] = 1;
          stq_tlb_w_idx[bank_idx] = stq_idx;
          stq_tlb_w_data_strc[bank_idx] = '{
              opcode: op_st_amo_in[i].opcode,
              target_vaddr: target_vaddr
          };

          // 状態の繊維.
          stq_op_in_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_BEFORE_TLB_REQUEST
          };
          // stの次の状態はopcodeによってことなる.
          if (is_amo_opcode(op_st_amo_in[i].opcode)) begin
            stq_op_in_update[i].next_state = ST_AMO_WAITING_RS2;
          end else if (op_st_amo_in[i].opcode inside {SC_W, SC_D}) begin
            stq_op_in_update[i].next_state = ST_BEFORE_TLB_REQUEST_CONDITIONAL;
          end else begin
            stq_op_in_update[i].next_state = ST_BEFORE_TLB_REQUEST;
          end
        end
      end
    end
  end

  // --------------------------------------------------------------------------------------------------
  // ldq,stqからtlbへリクエスト
  // --------------------------------------------------------------------------------------------------
  // TODO: 今はldから2出力,stから1出力になっているが,片方が空になったときもその制約が続いてる. 
  // 効率上げるために,どっちか0になったらその制約を解くようにしてもいいかも.
  // tlbのリクエストを出すbank_idxの先頭.例えば,ldqから二個,stqから1個をtlbにリクエストを出すなら
  // ldqのbank_idxはbank_idx,bank_idx+1,stqのbank_idxはbank_idx+2みたいな感じ. 
  // tlb_req_rr_baseは毎サイクル1つづつ動いていく.
  logic [BANK_IDX_WIDTH-1:0] tlb_req_rr_base_bank_idx;


  typedef struct packed {
    logic valid;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
  } tlb_ld_req_info_t;

  typedef struct packed {
    logic valid;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
  } tlb_st_req_info_t;

  tlb_ld_req_info_t tlb_ld_req_info[NUM_OF_LD_EXE];
  tlb_st_req_info_t tlb_st_req_info[NUM_OF_ST_EXE];

  tlb_ld_req_info_t tlb_ld_req_info_prev[NUM_OF_LD_EXE];
  tlb_st_req_info_t tlb_st_req_info_prev[NUM_OF_ST_EXE];


  always_comb begin
    automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = 0;
    automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = 0;
    automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = 0;

    tlb_ld_req_info = '{default: 0};
    tlb_st_req_info = '{default: 0};

    ldq_tlb_req_update = '{default: 0};
    stq_tlb_req_update = '{default: 0};

    ldq_tlb_r_en = '{default: 0};
    ldq_tlb_r_idx = '{default: 0};

    stq_tlb_r_en = '{default: 0};
    stq_tlb_r_idx = '{default: 0};



    // 次のサイクルでdtlbにリクエストを出す. 
    if (!tlb_port.stall_req_to_dtlb) begin

      // ldqからのリクエストの内容を読み出す
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        // bank_idx,ldq_idx
        bank_idx = tlb_req_rr_base_bank_idx + BANK_IDX_WIDTH'(i);
        ldq_idx  = ldq_before_tlb_avail[bank_idx].ldq_idx;
        // 状態がBEFORE_TLB_REQならtlb_reqを送る.
        if (ldq_before_tlb_avail[bank_idx].valid) begin
          // ldq_tlbからtlbに送る内容を読み出す.
          ldq_tlb_r_en[bank_idx] = 1;
          ldq_tlb_r_idx[bank_idx] = ldq_idx;
          // 次のサイクルでtlbに送り出すためのデータ.
          tlb_ld_req_info[i] = '{valid: 1, ldq_idx: ldq_idx, bank_idx: bank_idx};
          // 状態の更新. 
          ldq_tlb_req_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_DURING_TLB_REQUEST
          };
        end


      end

      // stqからのリクエストの内容を読み出す
      for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
        // bank_idx,ldq_idx
        bank_idx = tlb_req_rr_base_bank_idx + BANK_IDX_WIDTH'(NUM_OF_LD_EXE) + BANK_IDX_WIDTH'(i);

        // 状態がBEFORE_TLB_REQならtlb_reqを送る.
        if (stq_before_tlb_avail[bank_idx].valid) begin
          stq_idx = stq_before_tlb_avail[bank_idx].stq_idx;
          stq_tlb_r_en[bank_idx] = 1;
          stq_tlb_r_idx[bank_idx] = stq_idx;
          tlb_st_req_info[i] = '{valid: 1, stq_idx: stq_idx, bank_idx: bank_idx};
          // 状態の更新. 
          stq_tlb_req_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_DURING_TLB_REQUEST
          };
        end else if (stq_before_tlb_cond_avail[bank_idx].valid) begin
          stq_idx = stq_before_tlb_cond_avail[bank_idx].stq_idx;
          stq_tlb_r_en[bank_idx] = 1;
          stq_tlb_r_idx[bank_idx] = stq_idx;
          tlb_st_req_info[i] = '{valid: 1, stq_idx: stq_idx, bank_idx: bank_idx};
          // 状態の更新. 
          stq_tlb_req_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_DURING_TLB_REQUEST_CONDITIONAL
          };
        end

      end
    end
  end


  // リクエストする情報を受け取ったら,tlb_port.reqを作成.
  // amo命令はldのvaddr_avail_fifoにのみ入れることにする(stのvaddr_avail_fifoには入れない)
  // {ldq_idx,bank_idx}がldのid, {stq_idx,bank_idx}+LDQ_BANK_SIZE*NUM_OF_BANKがstのid,
  // {ldq_idx,bank_idx}+ LDQ_BANK_SIZE*NUM_OF_BANK+STQ_BANK_SIZE*NUM_OF_BANKがamoのid.
  // id < LDQ_BANK_SIZE*NUM_OF_BANK で ld 命令のリクエスト.
  // LDQ_BANK_SIZE*NUM_OF_BANK <= id < LDQ_BANK_SIZE*NUM_OF_BANK + STQ_BANK_SIZE*NUM_OF_BANK で st命令のリクエスト.
  // LDQ_BANK_SIZE*NUM_OF_BANK + STQ_BANK_SIZE*NUM_OF_BANK <= id でamo命令のリクエスト.
  always_comb begin
    tlb_port.req = '{default: 0};

    // ldのreq を作成.
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = tlb_ld_req_info_prev[i].bank_idx;
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = tlb_ld_req_info_prev[i].ldq_idx;
      automatic int unsigned not_amo_id = 32'({ldq_idx, bank_idx});
      automatic
      int unsigned
      amo_id = 32'({ldq_idx, bank_idx}) + LDQ_BANK_SIZE * NUM_OF_BANK + STQ_BANK_SIZE * NUM_OF_BANK;
      if (tlb_ld_req_info_prev[i].valid) begin
        tlb_port.req[i] = '{
            valid: 1,
            id: is_amo_opcode(ldq_tlb_r_data_strc[bank_idx].opcode) ? amo_id : not_amo_id,
            id_sub: 1,
            generation: generation,
            satp: satp,
            vaddr: ldq_tlb_r_data_strc[bank_idx].target_vaddr
        };
      end
    end

    // stのreqを作成.
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = tlb_st_req_info_prev[i].bank_idx;
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = tlb_st_req_info_prev[i].stq_idx;
      if (tlb_st_req_info_prev[i].valid) begin
        tlb_port.req[NUM_OF_LD_EXE+i] = '{
            valid: 1,
            id: 32'({stq_idx, bank_idx}) + LDQ_BANK_SIZE * NUM_OF_BANK,
            id_sub: 1,
            generation: generation,
            satp: satp,
            vaddr: stq_tlb_r_data_strc[bank_idx].target_vaddr
        };
      end
    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      tlb_req_rr_base_bank_idx <= 0;
      tlb_ld_req_info_prev <= '{default: 0};
      tlb_st_req_info_prev <= '{default: 0};
    end else if (flush_in) begin
      tlb_req_rr_base_bank_idx <= 0;
      tlb_ld_req_info_prev <= '{default: 0};
      tlb_st_req_info_prev <= '{default: 0};
    end else begin
      tlb_req_rr_base_bank_idx <= tlb_req_rr_base_bank_idx + 1;
      tlb_ld_req_info_prev <= tlb_ld_req_info;
      tlb_st_req_info_prev <= tlb_st_req_info;
    end
  end

  // --------------------------------------------------------------------------------------------------
  // tlbからのレスポンスをldq,stqに反映
  // --------------------------------------------------------------------------------------------------
  always_comb begin
    ldq_paddr_update_dtlb = '{default: 0};
    stq_paddr_update_dtlb = '{default: 0};

    ldq_tlb_res_update = '{default: 0};
    stq_tlb_res_update = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin

      automatic logic [BANK_IDX_WIDTH-1:0] bank_idx = 0;
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = 0;


      automatic int unsigned raw_id = 0;
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = 0;


      if (tlb_port.res[i].valid && tlb_port.res[i].generation == generation) begin
        if (tlb_port.res[i].id < LDQ_BANK_SIZE * NUM_OF_BANK) begin
          // ld命令のtlbリクエストが返還されたとき
          bank_idx = tlb_port.res[i].id[BANK_IDX_WIDTH-1:0];
          ldq_idx = tlb_port.res[i].id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];

          // paddrのアップデート内容.
          ldq_paddr_update_dtlb[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              paddr: tlb_port.res[i].paddr
          };

          // 状態遷移
          ldq_tlb_res_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_NONE
          };
          if (tlb_port.res[i].is_page_fault || tlb_port.res[i].pte_a == 0) begin
            // page_fault時.
            // pte_a が0の場合もここに含まれる.svade拡張なので.
            ldq_tlb_res_update[i].next_state = LD_PAGE_FAULT;
          end else if (tlb_port.res[i].pma_type == PMA_MEMORY) begin
            // pma_memory
            ldq_tlb_res_update[i].next_state = LD_BEFORE_CACHE_REQUEST;
          end else if (tlb_port.res[i].pma_type == PMA_MMIO) begin
            // mmioアクセス時.
            ldq_tlb_res_update[i].next_state = LD_BEFORE_MMIO_REQUEST;
          end else begin
            // access fault時
            // pma_typeがPMA_MMIOでもPMA_MEMORYでも無い場合はaccess_faultになる.
            $display("[ERROR][LSU.sv] ld access fault happened when tlb res returned.\n");
            $display("[TLB][%0d] valid=%0b id=%0d id_sub=%0b gen=%0d", i, tlb_port.res[i].valid,
                     tlb_port.res[i].id, tlb_port.res[i].id_sub, tlb_port.res[i].generation);
            $display("          paddr=0x%0h vaddr=0x%0h satp=0x%0h pma_type=%0d",
                     tlb_port.res[i].paddr, tlb_port.res[i].vaddr, tlb_port.res[i].satp,
                     tlb_port.res[i].pma_type);
            $display("          is_page_fault=%0b pte_a=%0b pte_d=%0b",
                     tlb_port.res[i].is_page_fault, tlb_port.res[i].pte_a, tlb_port.res[i].pte_d);
            ldq_tlb_res_update[i].next_state = LD_ACCESS_FAULT;
          end
        end else if (tlb_port.res[i].id < LDQ_BANK_SIZE * NUM_OF_BANK + STQ_BANK_SIZE * NUM_OF_BANK) begin
          // st命令のtlbリクエストに対するレスポンスが来たとき.
          raw_id = tlb_port.res[i].id - LDQ_BANK_SIZE * NUM_OF_BANK;
          bank_idx = raw_id[BANK_IDX_WIDTH-1:0];
          stq_idx = raw_id[BANK_IDX_WIDTH+:STQ_INBANK_IDX_WIDTH];
          stq_paddr_update_dtlb[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              paddr: tlb_port.res[i].paddr
          };

          // 状態の更新.
          stq_tlb_res_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_NONE
          };
          if (tlb_port.res[i].is_page_fault || tlb_port.res[i].pte_a == 0 || tlb_port.res[i].pte_d == 0) begin
            // page_fault時.
            // svade拡張なので,a,dビットによるpage_faultもここに含まれる.
            stq_tlb_res_update[i].next_state = ST_PAGE_FAULT;
          end else if (tlb_port.res[i].pma_type == PMA_MEMORY 
            && stq_state[bank_idx][stq_idx] == ST_DURING_TLB_REQUEST_CONDITIONAL) begin
            // store_conditional系の命令が来た場合,
            stq_tlb_res_update[i].next_state = ST_BEFORE_EXE_CONDITIONAL;
          end else if (tlb_port.res[i].pma_type == PMA_MEMORY) begin
            stq_tlb_res_update[i].next_state = ST_BEFORE_EXE;
          end else if (tlb_port.res[i].pma_type == PMA_MMIO) begin
            // mmioへのアクセス.
            stq_tlb_res_update[i].next_state = ST_BEFORE_MMIO_EXE;
          end else begin
            // access fault時
            stq_tlb_res_update[i].next_state = ST_ACCESS_FAULT;
          end
        end else begin
          // amo命令のtlbリクエストに対するレスポンスが来たとき. 
          // amoのアドレスリクエストはldqから出されるので,
          // idは STQ_BANK_SIZE * NUM_OF_BANK - LDQ_BANK_SIZE * NUM_OF_BANK + {ldq_idx,bank_idx} になる.

          raw_id = tlb_port.res[i].id - STQ_BANK_SIZE * NUM_OF_BANK - LDQ_BANK_SIZE * NUM_OF_BANK;
          bank_idx = raw_id[BANK_IDX_WIDTH-1:0];
          ldq_idx = raw_id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];
          // ldq,stqでbank_idxは同じ(al_idx%4で決まるからamoなら当然一致)
          stq_idx = amo_ldq_to_stq[bank_idx][ldq_idx].stq_idx;

          // paddrの更新用パラメータ.
          ldq_paddr_update_dtlb[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              paddr: tlb_port.res[i].paddr
          };
          stq_paddr_update_dtlb[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              paddr: tlb_port.res[i].paddr
          };

          // ldq,stqのstate更新用
          ldq_tlb_res_update[i] = '{
              valid: 1,
              ldq_bank_idx: bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_BEFORE_CACHE_REQUEST
          };
          stq_tlb_res_update[i] = '{
              valid: 1,
              stq_bank_idx: bank_idx,
              stq_idx: stq_idx,
              next_state: ST_NONE
          };
          // stはST＿AMO_WAITING_RS2のまま動かない.
          // 動くのは,ld命令がキャシュからデータをとってきて,rs2に入れたあと.
          if (tlb_port.res[i].is_page_fault || tlb_port.res[i].pte_a == 0) begin
            // page_fault時.
            // pte_a が0の場合もここに含まれる.svade拡張なので.
            ldq_tlb_res_update[i].next_state = LD_PAGE_FAULT;
            stq_tlb_res_update[i].next_state = ST_PAGE_FAULT;

          end else if (tlb_port.res[i].pma_type == PMA_MEMORY) begin
            // 普通にdramにアクセスしたとき.一番ノーマル
            ldq_tlb_res_update[i].next_state = LD_BEFORE_CACHE_REQUEST;
            stq_tlb_res_update[i].next_state = ST_AMO_WAITING_RS2;

          end else if (tlb_port.res[i].pma_type == PMA_MMIO) begin
            // mmioアクセス時.
            // そもそもmmioにamo命令でアクセスすることない?
            ldq_tlb_res_update[i].next_state = LD_NONE;
            stq_tlb_res_update[i].next_state = ST_NONE;
            $display("[ERROR][LSU.sv]");

          end else begin
            // access fault時
            // pma_typeがPMA_MMIOでもPMA_MEMORYでも無い場合はaccess_faultになる.
            ldq_tlb_res_update[i].next_state = LD_ACCESS_FAULT;
            stq_tlb_res_update[i].next_state = ST_ACCESS_FAULT;

          end

        end
      end
    end
  end

  // ---------------------------------------------------------------------------------------------------
  // ldを実行. (mmio命令も含む)
  // ---------------------------------------------------------------------------------------------------
  // ldq_exe_rr_bank_idxとldq_exe_rr_bank_idx+1のldqに入っているld命令を実行.
  // ldq_exe_rr_bank_idxは1サイクルで一つずつ加算.
  logic [BANK_IDX_WIDTH-1:0] ldq_exe_rr_bank_idx;


  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    logic [AL_IDX_WIDTH-1:0] al_idx;
  } bypass_info_t;

  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } bypass_byte_info_t;
  // byte単位でのbypass_info
  bypass_byte_info_t bypass_byte_info[NUM_OF_LD_EXE][8];
  bypass_byte_info_t bypass_byte_info_prev[NUM_OF_LD_EXE][8];

  // 実行したld命令のldq_idx,ldq_bank_idxを保存しておく. 
  // これは,次のサイクルでldq_bypass_dataに入れるため.
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
  } executed_ld_info_t;
  executed_ld_info_t executed_ld_info[NUM_OF_LD_EXE];
  executed_ld_info_t executed_ld_info_prev[NUM_OF_LD_EXE];

  always_comb begin
    // 初期化.
    executed_ld_info = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      for (int unsigned j = 0; j < 8; j++) begin
        bypass_byte_info[i][j] = 0;
      end
    end

    req_to_dcache_ld = '{default: 0};
    req_to_clint_ld = '{default: 0};
    req_to_plic_ld = '{default: 0};

    ldq_req_out_update = '{default: 0};

    for (int unsigned i = 0; i < 8; i++) begin
      stq_rs2_bypass_r_en[i]  = '{default: 0};
      stq_rs2_bypass_r_idx[i] = '{default: 0};
    end

    for (int unsigned i = 0; i < 8; i++) begin
      for (int unsigned j = 0; j < NUM_OF_LD_EXE; j++) begin
        stq_rs2_bypass_r_en[i][j]  = 0;
        stq_rs2_bypass_r_idx[i][j] = 0;
      end
    end

    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin

      // 実行するld命令に対して,stq[stq_bank_idx][stq_idx]がバイパスを行うか.
      automatic logic is_bypass[NUM_OF_BANK][STQ_BANK_SIZE];

      // is_bypassで4つ以下なら,bypass_infoに入れて,バイパスを行う.
      // バイパス元が4つ以下ならバイパスするが,5以上ならパスする.
      // これは計算量を抑えるため.
      automatic bypass_info_t bypass_info[BYPASS_MAX] = '{default: 0};
      automatic int unsigned bypass_info_counter = 0;

      // 前のst命令に依存性があるが,バイパスが不可能か.
      automatic logic bypass_incident = 0;

      // このサイクルにcacheに出すst命令で同じpaddrのものがあれば中止する
      automatic logic paddr_dup = 0;

      automatic logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx = ldq_exe_rr_bank_idx + BANK_IDX_WIDTH'(i);

      // mmioが有効ならmmioを優先.そうじゃないなら普通のreqのldq_idxを入れる. 
      // ここでvalid,つまり有効なエントリがあるかを見ているが,実際に実行するかを判断するときに
      // もう一度見るので,ldq_before_cache_reqのvalidを見なくて問題ない.
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = 0;


      for (int unsigned j = 0; j < NUM_OF_BANK; j++) begin
        is_bypass[j] = '{default: 0};
      end


      if (ldq_before_mmio_req_avail[ldq_bank_idx].valid) begin
        ldq_idx = ldq_before_mmio_req_avail[ldq_bank_idx].ldq_idx;
      end else begin
        ldq_idx = ldq_before_cache_req_avail[ldq_bank_idx].ldq_idx;
      end



      // このld命令の依存性を確認し,is_bypassを作成.
      for (int unsigned stq_bank_idx = 0; stq_bank_idx < NUM_OF_BANK; stq_bank_idx++) begin
        for (int unsigned stq_idx = 0; stq_idx < STQ_BANK_SIZE; stq_idx++) begin
          // stは終了済みか,stはこのld命令より前のものか,stとldは同じアドレスを共有しているかを調べる.
          automatic logic st_has_done = stq_state[stq_bank_idx][stq_idx] == ST_DONE;
          automatic
          logic
          is_st_before_ld = is_left_older(
              stq_to_al_idx[stq_bank_idx][stq_idx], ldq_to_al_idx[ldq_bank_idx][ldq_idx]
          );
          automatic
          logic
          is_same_paddr_db_aligned = to_dw_aligned_paddr(
              stq_paddr[stq_bank_idx][stq_idx]
          ) == to_dw_aligned_paddr(
              ldq_paddr[ldq_bank_idx][ldq_idx]
          );
          if (st_has_done && is_st_before_ld && is_same_paddr_db_aligned) begin
            is_bypass[stq_bank_idx][stq_idx] = 1;
          end
        end
      end

      // is_bypassからbpass_info,bypass_incidentを作成.
      // 途中でbreakするのはbypass_infoの配列外書き込みを避けるため.
      // bypass_maxの回数より多くbypassする場合は,実行を失敗させる.
      for (int unsigned j = 0; j < NUM_OF_BANK; j++) begin
        for (int unsigned k = 0; k < STQ_BANK_SIZE; k++) begin
          if (is_bypass[j][k]) begin
            if (bypass_info_counter >= BYPASS_MAX) begin
              bypass_incident = 1;
              break;
            end
            bypass_info[bypass_info_counter] = '{
                valid: 1,
                bank_idx: BANK_IDX_WIDTH'(j),
                stq_idx: STQ_INBANK_IDX_WIDTH'(k),
                al_idx: stq_to_al_idx[j][k]
            };
            bypass_info_counter++;
          end
        end
        if (bypass_incident) break;
      end

      // このサイクルに実行されるst命令(コミットされてdcacheに出されるのではなくてあくまでexe)で同じpaddrのものがあれば中止する.
      // なぜならこのサイクルで新しくdoneに入るが,それはbypass_incidentでチェックされない.
      for (int unsigned st_idx = 0; st_idx < NUM_OF_ST_EXE; st_idx++) begin
        automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = st_exe_info[st_idx].bank_idx;
        automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = st_exe_info[st_idx].stq_idx;
        if (st_exe_info[st_idx].valid && to_dw_aligned_paddr(
                stq_paddr[stq_bank_idx][stq_idx]
            ) == to_dw_aligned_paddr(
                ldq_paddr[ldq_bank_idx][ldq_idx]
            )) begin
          paddr_dup = 1;
          //  $display("[LOG][LSU.sv] dup to st_exe_info detected.");
        end
      end

      // このサイクルで出力されるst命令(実行ではない)は,このサイクルの立ち上がりときにすでにstateがST_NONEになっている. 
      // ldは組み合わせ回路で出力されるので,ST_NONEを参照することになって,バイパスがされない. 
      // なので,st_ent_dcache_prevに対してもpaddr_dupを確認 
      for (int unsigned st_idx = 0; st_idx < NUM_OF_ST_EXE; st_idx++) begin
        automatic
        logic [BANK_IDX_WIDTH-1:0]
        stq_bank_idx = st_ent_to_dcache_prev[st_idx].stq_bank_idx;
        automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = st_ent_to_dcache_prev[st_idx].stq_idx;
        if (st_ent_to_dcache_prev[st_idx].valid && to_dw_aligned_paddr(
                stq_paddr[stq_bank_idx][stq_idx]
            ) == to_dw_aligned_paddr(
                ldq_paddr[ldq_bank_idx][ldq_idx]
            )) begin
          paddr_dup = 1;
          // $display("[LOG][LSU.sv] dup to st_ent_to_dcach_prev detected. paddr:%h",
          //          ldq_paddr[ldq_bank_idx][ldq_idx]);
        end
      end

      // BEFORE_REQUESTでかつ,バイパス可能(或いは不要)ならldを実行
      // TODO: mmioまで止めなくてもいいかも.
      if ((ldq_before_cache_req_avail[ldq_bank_idx].valid || ldq_before_mmio_req_avail[ldq_bank_idx].valid) 
          && !bypass_incident && !dcache_noroom && !paddr_dup) begin


        // FOR DEBUG
        if (ldq_paddr[ldq_bank_idx][ldq_idx] == 56'h801feb50) begin
          // 
          // $display("[LOG][LSU.sv] ld req to 0x801feb50 detected.");
          // dump_ldq_state();
          // dump_stq_state();
        end


        // 実行情報を記録
        executed_ld_info[i] = '{valid: 1, ldq_bank_idx: ldq_bank_idx, ldq_idx: ldq_idx};

        // どこからバイパスするためのデータを持ってくるのかを特定する.
        for (int unsigned j = 0; j < BYPASS_MAX; j++) begin
          if (bypass_info[j].valid) begin
            for (int unsigned k = 0; k < 8; k++) begin
              automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = bypass_info[j].bank_idx;
              automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = bypass_info[j].stq_idx;

              // 初めてのbypass_byte_infoのエントリか,あるいは既存のエントリよりも若いエントリの場合はアップデートする.
              // (ただし,バイパス先とバイパスもとが両方maskされている=有効な場合に限る.)
              automatic
              logic
              should_bypass = stq_mask[stq_bank_idx][stq_idx][k] && ldq_mask[ldq_bank_idx][ldq_idx][k];
              automatic
              logic
              better_bypass = !bypass_byte_info[i][k].valid || is_left_older(
                  stq_to_al_idx[bypass_byte_info[i][k].bank_idx][bypass_byte_info[i][k].stq_idx],
                  stq_to_al_idx[stq_bank_idx][stq_idx]
              );
              if (better_bypass && should_bypass) begin
                // 
                bypass_byte_info[i][k] = '{
                    valid: 1,
                    al_idx: stq_to_al_idx[stq_bank_idx][stq_idx],
                    bank_idx: stq_bank_idx,
                    stq_idx: stq_idx
                };
              end
            end
          end
        end

        // rs2_bypassからバイパスするデータを読み出す.
        for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
          stq_rs2_bypass_r_en[byte_idx][i] = 1;
          stq_rs2_bypass_r_idx[byte_idx][i] = {
            bypass_byte_info[i][byte_idx].stq_idx, bypass_byte_info[i][byte_idx].bank_idx
          };
        end

        // ld命令を実際にキャッシュに出す.
        begin
          automatic int unsigned mask_counter = 0;
          automatic req_policy_e req_policy_tmp = REQ_POLICY_NONE;
          for (int unsigned j = 0; j < 8; j++) begin
            if (ldq_mask[ldq_bank_idx][ldq_idx][j]) begin
              mask_counter++;
            end
          end
          case (mask_counter)
            1: req_policy_tmp = READ_BYTE;
            2: req_policy_tmp = READ_HALF_WORD;
            4: req_policy_tmp = READ_WORD;
            8: req_policy_tmp = READ_DOUBLE_WORD;
            default: begin
              // TODO: 本当はmisalignmentなので,そのエラーをつけてそっちに送る必要がある.
              // ただ,xv6で正しいプログラムならミスアラインメントが出てこないのでとりあえずこれで実行する.
              req_policy_tmp = READ_BYTE;
              // $display("[ERROR][LSU.sv] req_policy error in ld. mask_coutner:%d, ldq_mask:%b",
              //          mask_counter, ldq_mask[ldq_bank_idx][ldq_idx]);
            end
          endcase


          // mmioはバイパスしないが、それを見分ける回路を作るのも面倒だし,
          // cacheへのリクエストとmmioへのリクエストは同様にここで扱っちゃってよい. 
          // ldq_idxもmmioを優先で作ったので,ここでも同様にmmio優先.
          if (ldq_before_mmio_req_avail[ldq_bank_idx].valid) begin
            case (get_device_name(
                ldq_paddr[ldq_bank_idx][ldq_idx]
            ))
              DN_CLINT: begin
                req_to_clint_ld = '{
                    valid: 1,
                    id: 32'(unsigned'({ldq_idx, ldq_bank_idx})),
                    paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
                    is_write: 0,
                    data: 0
                };
              end
              DN_PLIC: begin
                req_to_plic_ld = '{
                    valid: 1,
                    id: 32'(unsigned'({ldq_idx, ldq_bank_idx})),
                    paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
                    is_write: 0,
                    data: 0
                };
              end
              DN_UART: begin
                req_to_plic_ld = '{
                    valid: 1,
                    id: 32'(unsigned'({ldq_idx, ldq_bank_idx})),
                    paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
                    is_write: 0,
                    data: 0
                };
              end
              default: ;
            endcase
          end else begin
            req_to_dcache_ld[i] = '{
                valid: 1,
                id: 32'({ldq_idx, ldq_bank_idx}),
                id_sub: 0,
                generation: generation,
                req_policy: req_policy_tmp,
                cb_req_type: READ_REQ_FROM_UPPER,
                vaddr_db_aligned: 0,
                paddr_valid: 1,
                paddr_db_aligned: to_dw_aligned_paddr(ldq_paddr[ldq_bank_idx][ldq_idx]),
                byte_in_db_idx: ldq_paddr[ldq_bank_idx][ldq_idx][2:0],
                satp: satp,
                data: 0
            };
          end
        end

        // ldが実行された場合,状態をDURING_REQUESTに遷移
        ldq_req_out_update[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            next_state:
            ldq_before_mmio_req_avail[ldq_bank_idx].valid
            ?
            LD_DURING_MMIO_REQUEST
            :
            LD_DURING_CACHE_REQUEST
        };
      end



    end
  end

  // 前サイクルにstq_rs2_bypassにリクエストしたbypassのデータを受け取って,ldq_bypassに保存する.
  always_comb begin
    ldq_bypass_w_en = '{default: 0};
    ldq_bypass_w_idx = '{default: 0};
    ldq_bypass_w_data_strc = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      automatic logic [63:0] bypass_data_from_rs2 = 0;
      automatic logic [7:0] bypass_data_mask = 0;
      if (executed_ld_info_prev[i].valid) begin

        // 前段でrs2にリクエストした内容で実際にバイパスデータを組み立てる.
        for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
          if (bypass_byte_info_prev[i][byte_idx].valid) begin
            bypass_data_from_rs2[byte_idx*8+:8] = stq_rs2_bypass_r_data[byte_idx][i];
            bypass_data_mask[byte_idx] = 1;
          end else begin
            // ldで使用しない部分は0で埋める.
            bypass_data_from_rs2[byte_idx*8+:8] = 8'b0000_0000;
            bypass_data_mask[byte_idx] = 0;
          end
        end

        // ldq_bypass キャッシュからldが帰ってきたときにマージする用のバイパスデータを保存する.
        ldq_bypass_w_en[executed_ld_info_prev[i].ldq_bank_idx] = 1;
        ldq_bypass_w_idx[executed_ld_info_prev[i].ldq_bank_idx] = executed_ld_info_prev[i].ldq_idx;
        ldq_bypass_w_data_strc[executed_ld_info_prev[i].ldq_bank_idx] = '{
            bypass_mask: bypass_data_mask,
            data: bypass_data_from_rs2
        };

      end

    end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      ldq_exe_rr_bank_idx <= 0;
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        bypass_byte_info_prev[i] <= '{default: 0};
      end
      executed_ld_info_prev <= '{default: 0};
    end else if (flush_in) begin
      ldq_exe_rr_bank_idx <= 0;
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        bypass_byte_info_prev[i] <= '{default: 0};
      end
      executed_ld_info_prev <= '{default: 0};
    end else begin
      ldq_exe_rr_bank_idx   <= ldq_exe_rr_bank_idx + 1;
      bypass_byte_info_prev <= bypass_byte_info;
      executed_ld_info_prev <= executed_ld_info;
    end
  end


  // ---------------------------------------------------------------------------------------------------------
  // st命令の実行(sc,mmioも含む)
  // pf, afの出力.
  // ---------------------------------------------------------------------------------------------------------
  // ラウンドロビン用のbank_idxは毎サイクル1ずつ加算される. 
  logic [BANK_IDX_WIDTH-1:0] stq_exe_rr_bank_idx;


  // 実行したst命令の内容. 
  // op_out_stを作成するのがbramからデータを読み出す影響で1サイクル遅れるのでそれ用に_prevがある.
  typedef enum logic [2:0] {
    ST_EXE,
    SC_EXE,
    ST_MMIO_EXE,
    ST_PF,
    ST_AF
  } st_exe_type_e;

  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
    st_exe_type_e st_exe_type;
    logic is_sc;
    logic sc_success;
  } st_exe_info_t;
  st_exe_info_t st_exe_info[NUM_OF_ST_EXE];
  st_exe_info_t st_exe_info_prev[NUM_OF_ST_EXE];

  always_comb begin
    ld_speculative_feedback_valid_next = 0;
    ld_speculative_feedback_al_idx_next = 0;

    stq_op_out_r_en = '{default: 0};
    stq_op_out_r_idx = '{default: 0};

    st_exe_info = '{default: 0};
    stq_exe_done_update = '{default: 0};


    for (int unsigned st_exe_idx = 0; st_exe_idx < NUM_OF_ST_EXE; st_exe_idx++) begin
      automatic
      logic [BANK_IDX_WIDTH-1:0]
      stq_bank_idx = stq_exe_rr_bank_idx + BANK_IDX_WIDTH'(st_exe_idx);
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = 0;

      automatic logic ld_already_executed = 0;
      automatic logic raw_order = 0;
      automatic logic addr_dw_aligned_match = 0;
      automatic logic better_choice = 0;


      automatic int unsigned mask_size = 0;
      automatic logic is_word_sc = 0;
      automatic logic sc_success = 0;

      // ストア可能ならストアする
      if(stq_before_exe_cond_avail[stq_bank_idx].valid || stq_before_mmio_exe_avail[stq_bank_idx].valid 
        || stq_before_exe_avail[stq_bank_idx].valid)begin


        // 優先順位はsc,mmio,普通のst
        if (stq_before_exe_cond_avail[stq_bank_idx].valid) begin
          stq_idx = stq_before_exe_cond_avail[stq_bank_idx].stq_idx;
        end else if (stq_before_mmio_exe_avail[stq_bank_idx].valid) begin
          stq_idx = stq_before_mmio_exe_avail[stq_bank_idx].stq_idx;
        end else begin
          stq_idx = stq_before_exe_avail[stq_bank_idx].stq_idx;
        end

        // rawハザードの発生を確認
        // mmioの場合はそもそもin_orderに行われるので必要ないが,
        // mmioのときだけ省いても回路の大きさは変わらないので.
        // 条件を満たすld命令の中で,最も古いものをflushする必要がある

        for (int unsigned ldq_bank_idx = 0; ldq_bank_idx < NUM_OF_BANK; ldq_bank_idx++) begin
          for (int unsigned ldq_idx = 0; ldq_idx < LDQ_BANK_SIZE; ldq_idx++) begin

            // ldqのうち,有効で,st命令よりも前に発行されているものを探す.

            ld_already_executed = ldq_state[ldq_bank_idx][ldq_idx] inside {LD_DURING_CACHE_REQUEST, LD_DONE};

            raw_order = is_left_older(stq_to_al_idx[stq_bank_idx][stq_idx],
                                      ldq_to_al_idx[ldq_bank_idx][ldq_idx]);

            addr_dw_aligned_match = to_dw_aligned_paddr(stq_paddr[stq_bank_idx][stq_idx]) ==
                to_dw_aligned_paddr(ldq_paddr[ldq_bank_idx][ldq_idx]);

            // 初めて検出したraw違反か,前に検出したldより古いものである場合のみld_speculative_feedbackを更新する.
            better_choice = !ld_speculative_feedback_valid_next || is_left_older(
                ldq_to_al_idx[ldq_bank_idx][ldq_idx], ld_speculative_feedback_al_idx_next);


            if (ld_already_executed && raw_order && addr_dw_aligned_match && better_choice) begin
              // ヒットしたらint issue queueとrenamerにフィードバックする.
              // $display("[LOG][LSU.sv] ld retry addr:%h", to_dw_aligned_paddr(
              //          ldq_paddr[ldq_bank_idx][ldq_idx]));
              ld_speculative_feedback_valid_next  = 1;
              ld_speculative_feedback_al_idx_next = ldq_to_al_idx[ldq_bank_idx][ldq_idx];
            end
          end
        end


        // stq_bank_idxを選んだときと同様に,scが優先. 
        // mmioと普通のstは,リクエストはコミット時に行なわれるので,ここでの処理は同じであり,共通化可能.
        if (stq_before_exe_cond_avail[stq_bank_idx].valid) begin
          // sc命令を実行.
          // scが成功したかを判定する.
          mask_size  = 0;
          is_word_sc = 0;
          sc_success = 0;

          // scがwordがdwかを判定.
          for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
            if (stq_mask[stq_bank_idx][stq_idx][byte_idx]) mask_size = mask_size + 1;
          end
          is_word_sc = mask_size == 4;

          // scとlrは同じ大きさである必要がある.あと同じアドレス.
          sc_success = (is_word_sc == renamer_port.sc_mmio_executable.is_lr_w) 
                  && (stq_paddr[stq_bank_idx][stq_idx] == renamer_port.sc_mmio_executable.lock_paddr);


          // 
          st_exe_info[st_exe_idx] = '{
              valid: 1,
              bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              st_exe_type: SC_EXE,
              is_sc: 1,
              sc_success: sc_success
          };

          // stq_op_outに読み取り.
          // renamerはal_idxを順番に読み取るので,複数のstがcommitしてもbankがかぶることはない.
          stq_op_out_r_en[stq_bank_idx] = 1;
          stq_op_out_r_idx[stq_bank_idx] = stq_idx;

          // 状態遷移
          stq_exe_done_update[st_exe_idx] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: sc_success ? ST_DONE : ST_DONE_NO_OUT
          };

        end else begin
          // 普通のst,mmio
          stq_op_out_r_en[stq_bank_idx] = 1;
          stq_op_out_r_idx[stq_bank_idx] = stq_idx;
          st_exe_info[st_exe_idx] = '{
              valid: 1,
              bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              st_exe_type: stq_before_mmio_exe_avail[stq_bank_idx].valid ? ST_MMIO_EXE : ST_EXE,
              is_sc: 0,
              sc_success: 0
          };

          // 状態遷移
          stq_exe_done_update[st_exe_idx] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: ST_DONE
          };
        end

      end else if (stq_pf_avail[stq_bank_idx].valid || stq_af_avail[stq_bank_idx].valid) begin
        // pf, afが発生した場合,rawハザードをld_speculative_feedbackを送ろうが送るまいが,そのldがコミットされる前に
        // pf,afによる例外が発生するのでld_speculative_feedbackは送っても送らなくてもいい. 
        if (stq_pf_avail[stq_bank_idx].valid) begin
          stq_idx = stq_pf_avail[stq_bank_idx].stq_idx;

          // op_out用のデータ取得.
          stq_op_out_r_en[stq_bank_idx] = 1;
          stq_op_out_r_idx[stq_bank_idx] = stq_idx;

          st_exe_info[st_exe_idx] = '{
              valid: 1,
              bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              st_exe_type: ST_PF,
              is_sc: 0,
              sc_success: 0
          };

          // 状態遷移
          stq_exe_done_update[st_exe_idx] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: ST_DONE_NO_OUT
          };

        end else begin
          stq_idx = stq_af_avail[stq_bank_idx].stq_idx;

          // op_out用のデータ取得.
          stq_op_out_r_en[stq_bank_idx] = 1;
          stq_op_out_r_idx[stq_bank_idx] = stq_idx;

          st_exe_info[st_exe_idx] = '{
              valid: 1,
              bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              st_exe_type: ST_AF,
              is_sc: 0,
              sc_success: 0
          };

          // 状態遷移
          stq_exe_done_update[st_exe_idx] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: ST_DONE_NO_OUT
          };
        end


      end
    end
  end

  always_comb begin
    op_st_out = '{default: 0};
    // 
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      if (st_exe_info_prev[i].valid) begin
        if (st_exe_info_prev[i].st_exe_type == ST_EXE) begin
          // 普通のstore
          op_st_out[i] = '{
              valid: 1,
              opcode: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].opcode,
              op_addr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].op_vaddr,
              rd_exist: 0,
              rd: 0,
              rd_val: 0,
              al_idx: stq_to_al_idx[st_exe_info_prev[i].bank_idx][st_exe_info_prev[i].stq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr:
              stq_paddr[
              st_exe_info_prev[i].bank_idx
              ][
              st_exe_info_prev[i].stq_idx
              ],
              ldst_target_vaddr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 0
          };
        end else if (st_exe_info_prev[i].st_exe_type == SC_EXE) begin
          // store_conditional
          op_st_out[i] = '{
              valid: 1,
              opcode: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].opcode,
              op_addr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].op_vaddr,
              rd_exist: 1,
              rd: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].rd,
              rd_val: st_exe_info_prev[i].sc_success ? 0 : 1,
              al_idx: stq_to_al_idx[st_exe_info_prev[i].bank_idx][st_exe_info_prev[i].stq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr:
              stq_paddr[
              st_exe_info_prev[i].bank_idx
              ][
              st_exe_info_prev[i].stq_idx
              ],
              ldst_target_vaddr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 0
          };
        end else if (st_exe_info_prev[i].st_exe_type == ST_MMIO_EXE) begin
          // store mmio
          op_st_out[i] = '{
              valid: 1,
              opcode: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].opcode,
              op_addr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].op_vaddr,
              rd_exist: 0,
              rd: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].rd,
              rd_val: 0,
              al_idx: stq_to_al_idx[st_exe_info_prev[i].bank_idx][st_exe_info_prev[i].stq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr:
              stq_paddr[
              st_exe_info_prev[i].bank_idx
              ][
              st_exe_info_prev[i].stq_idx
              ],
              ldst_target_vaddr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 0
          };
        end else if (st_exe_info_prev[i].st_exe_type == ST_PF) begin
          op_st_out[i] = '{
              valid: 1,
              opcode: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].opcode,
              op_addr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].op_vaddr,
              rd_exist: 0,
              rd: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].rd,
              rd_val: 0,
              al_idx: stq_to_al_idx[st_exe_info_prev[i].bank_idx][st_exe_info_prev[i].stq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr:
              stq_paddr[
              st_exe_info_prev[i].bank_idx
              ][
              st_exe_info_prev[i].stq_idx
              ],
              ldst_target_vaddr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].target_vaddr,
              is_page_fault: 1,
              is_access_fault: 0
          };
        end else if (st_exe_info_prev[i].st_exe_type == ST_AF) begin
          op_st_out[i] = '{
              valid: 1,
              opcode: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].opcode,
              op_addr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].op_vaddr,
              rd_exist: 0,
              rd: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].rd,
              rd_val: 0,
              al_idx: stq_to_al_idx[st_exe_info_prev[i].bank_idx][st_exe_info_prev[i].stq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr:
              stq_paddr[
              st_exe_info_prev[i].bank_idx
              ][
              st_exe_info_prev[i].stq_idx
              ],
              ldst_target_vaddr: stq_op_out_r_data_strc[st_exe_info_prev[i].bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 1
          };
        end
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      st_exe_info_prev <= '{default: 0};
      ld_speculative_feedback_valid <= 0;
      ld_speculative_feedback_al_idx <= 0;
      renamer_port.ld_speculative_feedback_valid <= 0;
      renamer_port.ld_speculative_feedback_al_idx <= 0;
      stq_exe_rr_bank_idx <= 0;
    end else if (flush_in) begin
      st_exe_info_prev <= '{default: 0};
      ld_speculative_feedback_valid <= 0;
      ld_speculative_feedback_al_idx <= 0;
      renamer_port.ld_speculative_feedback_valid <= 0;
      renamer_port.ld_speculative_feedback_al_idx <= 0;
      stq_exe_rr_bank_idx <= 0;
    end else begin
      st_exe_info_prev <= st_exe_info;
      ld_speculative_feedback_valid <= ld_speculative_feedback_valid_next;
      ld_speculative_feedback_al_idx <= ld_speculative_feedback_al_idx_next;
      renamer_port.ld_speculative_feedback_valid <= ld_speculative_feedback_valid_next;
      renamer_port.ld_speculative_feedback_al_idx <= ld_speculative_feedback_al_idx_next;
      stq_exe_rr_bank_idx <= stq_exe_rr_bank_idx + 1;
    end
  end


  // ------------------------------------------------------------------------------------------------------------------------------
  // キャッシュから帰ってきたldの実行結果(mmioも含む)をマージしてop_ld_outとして出力.
  // 空いているところにpf,afの出力も入れる.
  // ------------------------------------------------------------------------------------------------------------------------------
  logic [BANK_IDX_WIDTH-1:0] rr_ldq_fault_base_bank_idx;

  // mmio_resは一時的にmmioからのresを保存しておくためのバッファ.
  // op_ld_outの枠が空いたら,mmio_res_usedにして,mmio_resからmmio_res_outに値を移す.
  device_res_t mmio_res;
  device_res_t mmio_res_prev;
  // device_res_t mmio_res_out[NUM_OF_CACHE_RES];
  logic mmio_res_used;
  // int unsigned mmio_res_out_idx;

  typedef enum logic [1:0] {
    FROM_CACHE,
    FROM_MMIO,
    FROM_PF,
    FROM_AF
  } ld_from_where_e;
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx;
    logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx;
    ld_from_where_e ld_from_where;
  } ld_op_out_info_t;
  ld_op_out_info_t ld_op_out_info[NUM_OF_CACHE_RES];
  ld_op_out_info_t ld_op_out_info_prev[NUM_OF_CACHE_RES];


  cache_res64_t res_from_dcache_prev[NUM_OF_RES_FROM_DCACHE];

  // res_from_cache,res_from_plic,res_from_clintからレスポンスを生成.
  always_comb begin

    mmio_res_used = 0;

    ld_op_out_info = '{default: 0};

    ldq_done_update = '{default: 0};
    stq_amo_get_rs2_update = '{default: 0};
    ;
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      ldq_bypass_r_en[i]  = '{default: 0};
      ldq_bypass_r_idx[i] = '{default: 0};
    end
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      ldq_bypass_r_idx[i] = '{default: 0};
    end
    for (int unsigned i = 0; i < NUM_OF_RES_FROM_DCACHE; i++) begin
      ldq_op_out_r_en[i]  = '{default: 0};
      ldq_op_out_r_idx[i] = '{default: 0};
    end
    stq_amo_rs2_r_en  = '{default: 0};
    stq_amo_rs2_r_idx = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      automatic logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx = 0;
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = 0;
      automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = 0;
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = 0;

      if (res_from_dcache[i].valid && (res_from_dcache[i].generation == generation)) begin
        // cache_resのidがldq_idxになっている.
        // amo,非amoともに,読み出した値をop_ld_outとしてop_outで出力する.

        // ldq_bank_idx,ldq_idxの作成.
        ldq_bank_idx = res_from_dcache[i].id[BANK_IDX_WIDTH-1:0];
        ldq_idx = res_from_dcache[i].id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];

        // バイパスに用いる用に保存しておいたデータの読み出し.
        ldq_bypass_r_en[i][ldq_bank_idx] = 1;
        ldq_bypass_r_idx[i][ldq_bank_idx] = ldq_idx;

        // 出力用に保存しておいたデータの読み出し. 
        ldq_op_out_r_en[i][ldq_bank_idx] = 1;
        ldq_op_out_r_idx[i][ldq_bank_idx] = ldq_idx;

        // amoの場合,stq_rs2,stq_rs2_bypassに値を保存するが,それはバイパス用のデータを取得した次のサイクルで行う.
        // このサイクルでは状態のアップデートと,amo_rs2から計算用のデータを撮ってくる.
        if (amo_ldq_to_stq[ldq_bank_idx][ldq_idx].valid) begin
          stq_bank_idx = amo_ldq_to_stq[ldq_bank_idx][ldq_idx].stq_bank_idx;
          stq_idx = amo_ldq_to_stq[ldq_bank_idx][ldq_idx].stq_idx;

          // stが実行できるように状態遷移
          stq_amo_get_rs2_update[i] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: ST_BEFORE_EXE
          };

          // amo_rs2へamoのrs2フィールどを取得.
          stq_amo_rs2_r_en[i] = 1;
          stq_amo_rs2_r_idx[i] = {stq_idx, stq_bank_idx};
        end

        // ld_op_out_infoの作成
        ld_op_out_info[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            ld_from_where: FROM_CACHE
        };

        // ldq_stateのupdate
        ldq_done_update[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            next_state : LD_DONE
        };

      end else if (mmio_res.valid && !mmio_res_used) begin
        // res_from_dcacheに空きがあってmmio_resが存在するなら,mmio_resをop_ld_outで出力する. 
        // そのためのデータをldq_op_outにリクエスト
        ldq_bank_idx = mmio_res.id[BANK_IDX_WIDTH-1:0];
        ldq_idx = mmio_res.id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];

        // op_out用の情報読み取り.
        ldq_op_out_r_en[i][ldq_bank_idx] = 1;
        ldq_op_out_r_idx[i][ldq_bank_idx] = ldq_idx;

        mmio_res_used = 1;

        // ld_op_out_infoの作成
        ld_op_out_info[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            ld_from_where: FROM_MMIO
        };

        // ldq_stateのupdate
        ldq_done_update[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            next_state : LD_DONE
        };



      end else if (ldq_pf_avail[rr_ldq_fault_base_bank_idx+BANK_IDX_WIDTH'(i)].valid) begin
        // page faultが存在する場合.
        ldq_bank_idx = rr_ldq_fault_base_bank_idx + BANK_IDX_WIDTH'(i);
        ldq_idx = ldq_pf_avail[rr_ldq_fault_base_bank_idx+BANK_IDX_WIDTH'(i)].ldq_idx;

        // op_out用の情報読み取り.
        ldq_op_out_r_en[i][ldq_bank_idx] = 1;
        ldq_op_out_r_idx[i][ldq_bank_idx] = ldq_idx;

        // ld_op_out_infoの作成
        ld_op_out_info[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            ld_from_where: FROM_PF
        };

        // ldq_stateのupdate
        ldq_done_update[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            next_state : LD_DONE
        };




      end else if (ldq_af_avail[rr_ldq_fault_base_bank_idx+BANK_IDX_WIDTH'(i)].valid) begin
        // access faultが存在する場合.
        ldq_bank_idx = rr_ldq_fault_base_bank_idx + BANK_IDX_WIDTH'(i);
        ldq_idx = ldq_af_avail[rr_ldq_fault_base_bank_idx+BANK_IDX_WIDTH'(i)].ldq_idx;

        // op_out用の情報読み取り.
        ldq_op_out_r_en[i][ldq_bank_idx] = 1;
        ldq_op_out_r_idx[i][ldq_bank_idx] = ldq_idx;

        // ld_op_out_infoの作成
        ld_op_out_info[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            ld_from_where: FROM_AF
        };

        // ldq_stateのupdate
        ldq_done_update[i] = '{
            valid: 1,
            ldq_bank_idx: ldq_bank_idx,
            ldq_idx: ldq_idx,
            next_state : LD_DONE
        };

      end

    end


  end

  // 前サイクルのキャッシュからのresを,読み出したバイパス用データとマージしてop_outとして出力する. 
  always_comb begin

    stq_rs2_w_en_amo_res = '{default: 0};
    stq_rs2_w_idx_amo_res = '{default: 0};
    stq_rs2_w_data_amo_res = '{default: 0};

    op_ld_out = '{default: 0};

    // cacheからよみだされたデータも,ldq_bypassに入れていたデータも,ldq_maskもdw_alignedされたpaddrに
    // 対するものなのでそのまま素直にマージできる. 
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      automatic logic [63:0] data_dw_aligned = 0;
      // automatic
      // logic [BANK_IDX_WIDTH-1:0]
      // ldq_bank_idx = res_from_dcache_prev[i].id[BANK_IDX_WIDTH-1:0];
      // automatic
      // logic [LDQ_INBANK_IDX_WIDTH-1:0]
      // ldq_idx = res_from_dcache_prev[i].id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];
      automatic logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx = ld_op_out_info_prev[i].ldq_bank_idx;
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = ld_op_out_info_prev[i].ldq_idx;

      automatic logic [63:0] ld_result_data = 0;

      automatic logic [63:0] calced_data = 0;


      if (ld_op_out_info_prev[i].valid) begin
        if (ld_op_out_info_prev[i].ld_from_where == FROM_CACHE) begin
          // 普通のキャッシュから読み出した内容をop_outする場合.


          // if (ldq_paddr[ldq_bank_idx][ldq_idx] == 56'h801feb50) begin
          //   $display("[LOG][LSU.sv] data_dw_aligned(before bypass):%h", data_dw_aligned);
          // end

          data_dw_aligned = res_from_dcache_prev[i].data;
          // ldq_maskは,data_dw_alignedのうち,どれをld_result_dataとして返すかを記録してある.
          for (int unsigned j = 0; j < 8; j++) begin
            if (ldq_bypass_r_data_strc[i][ldq_bank_idx].bypass_mask[j]) begin
              data_dw_aligned[j*8+:8] = ldq_bypass_r_data_strc[i][ldq_bank_idx].data[j*8+:8];
            end
          end

          // if (ldq_paddr[ldq_bank_idx][ldq_idx] == 56'h801feb50) begin
          //   $display("[LOG][LSU.sv] data_dw_aligned(bypassed):%h", data_dw_aligned);
          // end

          // data_dw_aligned をpaddrの下位に応じてシフトすることで,ldで本当に取得するべきデータを得る.
          ld_result_data = data_dw_aligned >> (ldq_paddr[ldq_bank_idx][ldq_idx][2:0] * 8);

          // 
          case (ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode)
            LB: ld_result_data = 64'(signed'(ld_result_data[7:0]));
            LBU: ld_result_data = 64'(unsigned'(ld_result_data[7:0]));
            LH: ld_result_data = 64'(signed'(ld_result_data[15:0]));
            LHU: ld_result_data = 64'(unsigned'(ld_result_data[15:0]));
            LW,LR_W,AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
          AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:
            ld_result_data = 64'(signed'(ld_result_data[31:0]));
            LWU: ld_result_data = 64'(unsigned'(ld_result_data[31:0]));
            LD,LR_D,AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
          AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D :
            ld_result_data = ld_result_data;
            default: $display("[ERROR][LSU.sv]");
          endcase

          // amoなら,stq_rs2,stq_rs2_bypassのデータを計算してアップデートする.
          if (amo_ldq_to_stq[ldq_bank_idx][ldq_idx].valid) begin
            // そのデータを用いて,amoの演算を行う. 
            calced_data = amo_calc(stq_amo_rs2_r_data_strc[i].opcode, ld_result_data,
                                   stq_amo_rs2_r_data_strc[i].data);
            stq_rs2_w_en_amo_res[i] = 1;
            stq_rs2_w_idx_amo_res[i] = {
              amo_ldq_to_stq[ldq_bank_idx][ldq_idx].stq_idx,
              amo_ldq_to_stq[ldq_bank_idx][ldq_idx].stq_bank_idx
            };
            // dw単位に揃えてから書き込み.
            stq_rs2_w_data_amo_res[i] = 64'(calced_data << (ldq_paddr[ldq_bank_idx][ldq_idx][2:0]*8));
          end




          // op_ld_out
          op_ld_out[i] = '{
              valid: 1,
              opcode: ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode,
              op_addr: ldq_op_out_r_data_strc[i][ldq_bank_idx].op_vaddr,
              rd_exist: 1,
              rd: ldq_op_out_r_data_strc[i][ldq_bank_idx].rd,
              rd_val: ld_result_data,
              al_idx: ldq_to_al_idx[ldq_bank_idx][ldq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
              ldst_target_vaddr: ldq_op_out_r_data_strc[i][ldq_bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 0
          };
        end else if (ld_op_out_info_prev[i].ld_from_where == FROM_MMIO) begin
          // mmio_res_outからop_ld_outに
          ldq_bank_idx = mmio_res_prev.id[BANK_IDX_WIDTH-1:0];
          ldq_idx = mmio_res_prev.id[BANK_IDX_WIDTH+:LDQ_INBANK_IDX_WIDTH];

          data_dw_aligned = mmio_res_prev.data;


          // data_dw_aligned をpaddrの下位に応じてシフトすることで,ldで本当に取得するべきデータを得る.
          // automatic
          // logic [63:0]
          // ld_result_data = data_dw_aligned >> (ldq_paddr[ldq_bank_idx][ldq_idx][2:0] * 8);
          ld_result_data = mmio_res_prev.data;



          // 
          case (ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode)
            LB: ld_result_data = 64'(signed'(ld_result_data[7:0]));
            LBU: ld_result_data = 64'(unsigned'(ld_result_data[7:0]));
            LH: ld_result_data = 64'(signed'(ld_result_data[15:0]));
            LHU: ld_result_data = 64'(unsigned'(ld_result_data[15:0]));
            LW,LR_W,AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
          AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:
            ld_result_data = 64'(signed'(ld_result_data[31:0]));
            LWU: ld_result_data = 64'(unsigned'(ld_result_data[31:0]));
            LD,LR_D,AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
          AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D :
            ld_result_data = ld_result_data;
            default: $display("[ERROR][LSU.sv]");
          endcase


          op_ld_out[i] = '{
              valid: 1,
              opcode: ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode,
              op_addr: ldq_op_out_r_data_strc[i][ldq_bank_idx].op_vaddr,
              rd_exist: 1,
              rd: ldq_op_out_r_data_strc[i][ldq_bank_idx].rd,
              rd_val: ld_result_data,
              al_idx: ldq_to_al_idx[ldq_bank_idx][ldq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
              ldst_target_vaddr: ldq_op_out_r_data_strc[i][ldq_bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 0
          };
        end else if (ld_op_out_info_prev[i].ld_from_where == FROM_PF) begin
          ldq_bank_idx = ld_op_out_info_prev[i].ldq_bank_idx;
          ldq_idx = ld_op_out_info_prev[i].ldq_idx;

          op_ld_out[i] = '{
              valid: 1,
              opcode: ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode,
              op_addr: ldq_op_out_r_data_strc[i][ldq_bank_idx].op_vaddr,
              rd_exist: 1,
              rd: ldq_op_out_r_data_strc[i][ldq_bank_idx].rd,
              rd_val: 0,
              al_idx: ldq_to_al_idx[ldq_bank_idx][ldq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
              ldst_target_vaddr: ldq_op_out_r_data_strc[i][ldq_bank_idx].target_vaddr,
              is_page_fault: 1,
              is_access_fault: 0
          };

        end else if (ld_op_out_info_prev[i].ld_from_where == FROM_AF) begin
          ldq_bank_idx = ld_op_out_info_prev[i].ldq_bank_idx;
          ldq_idx = ld_op_out_info_prev[i].ldq_idx;

          op_ld_out[i] = '{
              valid: 1,
              opcode: ldq_op_out_r_data_strc[i][ldq_bank_idx].opcode,
              op_addr: ldq_op_out_r_data_strc[i][ldq_bank_idx].op_vaddr,
              rd_exist: 1,
              rd: ldq_op_out_r_data_strc[i][ldq_bank_idx].rd,
              rd_val: 0,
              al_idx: ldq_to_al_idx[ldq_bank_idx][ldq_idx],
              actual_taken: 0,
              actual_taken_addr: 0,
              ldst_target_paddr: ldq_paddr[ldq_bank_idx][ldq_idx],
              ldst_target_vaddr: ldq_op_out_r_data_strc[i][ldq_bank_idx].target_vaddr,
              is_page_fault: 0,
              is_access_fault: 1
          };
        end
      end
    end

  end


  // mmioの結果をmmio_resに保存.
  // mmioのreqが同時に二つ以上実行されることはないので上書きされる心配はない.
  always_ff @(posedge clock) begin
    if (reset) begin
      mmio_res <= '{default: 0};
      mmio_res_prev <= '{default: 0};
      res_from_dcache_prev <= '{default: 0};
      ld_op_out_info_prev <= '{default: 0};
      rr_ldq_fault_base_bank_idx <= 0;
    end else if (flush_in) begin
      mmio_res <= '{default: 0};
      // TODO: あとで消す？？
      mmio_res_prev <= '{default: 0};
      res_from_dcache_prev <= '{default: 0};
      ld_op_out_info_prev <= '{default: 0};
      rr_ldq_fault_base_bank_idx <= 0;
    end else begin
      // mmio_res
      if (res_from_clint.valid) begin
        mmio_res <= res_from_clint;
      end
      if (res_from_plic.valid) begin
        mmio_res <= res_from_plic;
      end
      if (mmio_res_used) begin
        mmio_res <= '{default: 0};
      end

      mmio_res_prev <= mmio_res;

      // 
      res_from_dcache_prev <= res_from_dcache;

      ld_op_out_info_prev <= ld_op_out_info;
      rr_ldq_fault_base_bank_idx <= rr_ldq_fault_base_bank_idx + 1;
    end
  end


  // --------------------------------------------------------------------------------------------------------
  // コミットが終わった命令を削除し,st命令をキャッシュに送る
  // --------------------------------------------------------------------------------------------------------
  // 今はNUM_OF_ST_CACHE_REQが1なので,stq_rs2をマルチバンクにしなくても成立しているが,
  // NUM_OF_ST_CACHE_REQが2以上になったときに
  typedef struct packed {
    logic valid;
    logic [BANK_IDX_WIDTH-1:0] stq_bank_idx;
    logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx;
  } st_ent_to_dcache_t;
  st_ent_to_dcache_t st_ent_to_dcache[NUM_OF_ST_CACHE_REQ];
  st_ent_to_dcache_t st_ent_to_dcache_prev[NUM_OF_ST_CACHE_REQ];

  always_comb begin
    automatic int unsigned st_done_commit_counter = 0;

    stq_rs2_r_en = '{default: 0};
    stq_rs2_r_idx = '{default: 0};

    st_ent_to_dcache = '{default: 0};

    stq_delete_update = '{default: 0};
    ldq_delete_update = '{default: 0};

    al_ldq_conv_del = '{default: 0};
    al_stq_conv_del = '{default: 0};

    num_of_del_fence = 0;

    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      automatic logic [AL_IDX_WIDTH-1:0] al_idx = renamer_port.committed_instr[i].al_idx;
      automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = al_to_stq_idx[al_idx].stq_bank_idx;
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = al_to_stq_idx[al_idx].stq_idx;

      automatic logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx = al_to_ldq_idx[al_idx].ldq_bank_idx;
      automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = al_to_ldq_idx[al_idx].ldq_idx;

      if (renamer_port.committed_instr[i].valid) begin



        if (al_to_stq_idx[al_idx].valid) begin
          // st命令(amo)の卒業.
          // renamerでst命令は1サイクルに1つまでしか卒業しないように制御している.
          // automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = al_to_stq_idx[al_idx].stq_bank_idx;
          // automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = al_to_stq_idx[al_idx].stq_idx;

          // stqからエントリを削除.
          stq_delete_update[i] = '{
              valid: 1,
              stq_bank_idx: stq_bank_idx,
              stq_idx: stq_idx,
              next_state: ST_NONE
          };

          // idx変換の削除
          al_stq_conv_del[i] = '{
              valid: 1,
              al_idx: al_idx,
              bank_idx: stq_bank_idx,
              stq_idx: stq_idx
          };


          // ST_DONEなら出力,ST_DONE_NOOUTならキャッシュへの出力を行わない.
          // SCの失敗ときとかPF,AFとか.
          if (stq_state[stq_bank_idx][stq_idx] == ST_DONE) begin
            // cacheに送るためにrs2のデータを読み出し.
            stq_rs2_r_en[st_done_commit_counter] = 1;
            stq_rs2_r_idx[st_done_commit_counter] = {stq_idx, stq_bank_idx};

            // dcahceに送る内容の指定.
            st_ent_to_dcache[st_done_commit_counter] = '{
                valid: 1,
                stq_bank_idx: stq_bank_idx,
                stq_idx: stq_idx
            };

            st_done_commit_counter++;
          end
        end


        if (al_to_ldq_idx[al_idx].valid) begin
          // ld命令(amo)のがコミットした場合,ldqから削除.
          // automatic logic [BANK_IDX_WIDTH-1:0] ldq_bank_idx = al_to_ldq_idx[al_idx].ldq_bank_idx;
          // automatic logic [LDQ_INBANK_IDX_WIDTH-1:0] ldq_idx = al_to_ldq_idx[al_idx].ldq_idx;

          // idx変換の削除
          al_ldq_conv_del[i] = '{
              valid: 1,
              al_idx: al_idx,
              bank_idx: ldq_bank_idx,
              ldq_idx: ldq_idx
          };

          // 状態の遷移
          ldq_delete_update[i] = '{
              valid: 1,
              ldq_bank_idx: ldq_bank_idx,
              ldq_idx: ldq_idx,
              next_state: LD_NONE
          };
        end

        if(fenceq[fenceq_rp+FENCEQ_IDX_WIDTH'(num_of_del_fence)].valid 
                    && fenceq[fenceq_rp+FENCEQ_IDX_WIDTH'(num_of_del_fence)].al_idx == al_idx)begin
          // fence命令がコミットした場合,fenceqから削除.
          num_of_del_fence++;
        end


      end
    end
  end

  always_comb begin
    req_to_dcache_st = '{default: 0};
    req_to_clint_st  = '{default: 0};
    req_to_plic_st   = '{default: 0};

    for (int unsigned i = 0; i < NUM_OF_ST_CACHE_REQ; i++) begin
      automatic logic [BANK_IDX_WIDTH-1:0] stq_bank_idx = st_ent_to_dcache_prev[i].stq_bank_idx;
      automatic logic [STQ_INBANK_IDX_WIDTH-1:0] stq_idx = st_ent_to_dcache_prev[i].stq_idx;
      automatic logic [63:0] rs2_val = stq_rs2_r_data[i];

      // req_policyをmaskから作成.
      automatic req_policy_e req_policy_st = REQ_POLICY_NONE;
      automatic int unsigned mask_counter = 0;
      for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
        if (stq_mask[stq_bank_idx][stq_idx][byte_idx]) begin
          mask_counter++;
        end
      end


      case (mask_counter)
        1: req_policy_st = WRITE_BYTE;
        2: req_policy_st = WRITE_HALF_WORD;
        4: req_policy_st = WRITE_WORD;
        8: req_policy_st = WRITE_DOUBLE_WORD;
        default: begin
          // TODO: ldと同様に,本当はmisalignmentなので,そのエラーをつけてそっちに送る必要がある.
          // ただ,xv6で正しいプログラムならミスアラインメントが出てこないのでとりあえずこれで実行する.
          req_policy_st = WRITE_BYTE;
          // $display("[ERROR][LSU.sv] st mask counter error in st. mask_counter:%d stq_mask:%b",
          //          mask_counter, stq_mask[stq_bank_idx][stq_idx]);
        end
      endcase

      if (st_ent_to_dcache_prev[i].valid) begin

        case (get_device_name(
            stq_paddr[stq_bank_idx][stq_idx]
        ))
          DN_DRAM: begin
            // sc失敗時には書き込みを行わない
            req_to_dcache_st[i] = '{
                valid: 1,
                id: 0,  // 使用しない為.
                id_sub: 0,
                generation: 0,  //st命令は返答が無いのでgenerationは不要.
                req_policy: req_policy_st,
                cb_req_type: WRITE_REQ_FROM_UPPER,
                vaddr_db_aligned: 0,
                paddr_valid: 1,
                paddr_db_aligned: to_dw_aligned_paddr(stq_paddr[stq_bank_idx][stq_idx]),
                byte_in_db_idx: stq_paddr[stq_bank_idx][stq_idx][BYTE_IN_DW_MSB:BYTE_IN_DW_LSB],
                satp: satp,
                data: rs2_val
            };
          end
          DN_CLINT: begin
            req_to_clint_st = '{
                valid: 1,
                id: 0,  // stはid不要.
                paddr: stq_paddr[stq_bank_idx][stq_idx],
                is_write: 1,
                data: rs2_val
            };
          end
          DN_PLIC: begin
            req_to_plic_st = '{
                valid: 1,
                id: 0,  // stはid不要.
                paddr: stq_paddr[stq_bank_idx][stq_idx],
                is_write: 1,
                data: {
                  32'b0,
                  rs2_val[stq_paddr[stq_bank_idx][stq_idx][BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:32]
                }
            };
          end
          DN_UART: begin
            req_to_plic_st = '{
                valid: 1,
                id: 0,  // stはid不要.
                paddr: stq_paddr[stq_bank_idx][stq_idx],
                is_write: 1,
                data: {
                  56'b0,
                  rs2_val[stq_paddr[stq_bank_idx][stq_idx][BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:8]
                }
            };
          end
          default: ;
        endcase
      end
    end
  end


  always_ff @(posedge clock) begin
    if (reset) begin
      st_ent_to_dcache_prev <= '{default: 0};
    end else if (flush_in) begin
      // flushと同時にコミットされたst命令はしっかりとcacheに送らないと行けないので.
      st_ent_to_dcache_prev <= st_ent_to_dcache;
    end else begin
      st_ent_to_dcache_prev <= st_ent_to_dcache;
    end
  end

  // ------------------------------------------------------------------------------------------------------------------
  // fenceqのアップデート
  // ------------------------------------------------------------------------------------------------------------------
  always_ff @(posedge clock) begin
    if (reset) begin
      fenceq <= '{default: 0};
      fenceq_rp <= 0;
      fenceq_wp <= 0;
      noei_fenceq <= 0;
    end else if (flush_in) begin
      fenceq <= '{default: 0};
      fenceq_rp <= 0;
      fenceq_wp <= 0;
      noei_fenceq <= 0;
    end else begin
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (i < num_of_new_fence) begin
          fenceq[fenceq_wp+FENCEQ_IDX_WIDTH'(i)] <= fenceq_update[i];
        end
      end

      fenceq_wp <= fenceq_wp + FENCEQ_IDX_WIDTH'(num_of_new_fence);
      fenceq_rp <= fenceq_rp + FENCEQ_IDX_WIDTH'(num_of_del_fence);
      noei_fenceq <= noei_fenceq + (FENCEQ_IDX_WIDTH + 1)'(num_of_new_fence) -  (FENCEQ_IDX_WIDTH + 1)'(num_of_del_fence);
    end
  end

  // ------------------------------------------------------------------------------------------------------------------
  // al_to_ldq_idx, al_to_stq_idx, ldq_to_al_idx, stq_to_al_idx, amo_ldq_to_stqの作成.
  // ------------------------------------------------------------------------------------------------------------------
  always_ff @(posedge clock) begin
    if (reset) begin
      al_to_ldq_idx <= '{default: 0};
      al_to_stq_idx <= '{default: 0};
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        ldq_to_al_idx[i]  <= '{default: 0};
        stq_to_al_idx[i]  <= '{default: 0};
        amo_ldq_to_stq[i] <= '{default: 0};
      end
    end else if (flush_in) begin
      al_to_ldq_idx <= '{default: 0};
      al_to_stq_idx <= '{default: 0};
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        ldq_to_al_idx[i]  <= '{default: 0};
        stq_to_al_idx[i]  <= '{default: 0};
        amo_ldq_to_stq[i] <= '{default: 0};
      end
    end else begin

      // al_idxとldq_idxを変換するテーブルの更新.
      // 削除
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_ldq_conv_del[i].valid) begin
          al_to_ldq_idx[al_ldq_conv_del[i].al_idx] <= '{default: 0};
          ldq_to_al_idx[al_ldq_conv_del[i].bank_idx][al_ldq_conv_del[i].ldq_idx] <= 0;
        end
      end
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (al_ldq_conv_new[i].valid) begin
          al_to_ldq_idx[al_ldq_conv_new[i].al_idx] <= '{
              valid: 1,
              ldq_bank_idx: al_ldq_conv_new[i].bank_idx,
              ldq_idx: al_ldq_conv_new[i].ldq_idx
          };
          ldq_to_al_idx[al_ldq_conv_new[i].bank_idx][al_ldq_conv_new[i].ldq_idx] <= al_ldq_conv_new[i].al_idx;
        end
      end


      // al_idxとstq_idxを変換するテーブルの更新.
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_stq_conv_del[i].valid) begin
          al_to_stq_idx[al_stq_conv_del[i].al_idx] <= '{default: 0};
          stq_to_al_idx[al_stq_conv_del[i].bank_idx][al_stq_conv_del[i].stq_idx] <= 0;
        end
      end
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (al_stq_conv_new[i].valid) begin
          al_to_stq_idx[al_stq_conv_new[i].al_idx] <= '{
              valid: 1,
              stq_bank_idx: al_stq_conv_new[i].bank_idx,
              stq_idx: al_stq_conv_new[i].stq_idx
          };
          stq_to_al_idx[al_stq_conv_new[i].bank_idx][al_stq_conv_new[i].stq_idx] <= al_stq_conv_new[i].al_idx;
        end
      end


      // amo_ldq_idx_to_stq_idx
      // エントリ削除
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (al_ldq_conv_del[i].valid) begin
          amo_ldq_to_stq[al_ldq_conv_del[i].bank_idx][al_ldq_conv_del[i].ldq_idx] <= '{default: 0};
        end
      end
      // 新しいエントリ
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (amo_ldq_to_stq_new[i].valid) begin
          amo_ldq_to_stq[amo_ldq_to_stq_new[i].ldq_bank_idx][amo_ldq_to_stq_new[i].ldq_idx] <= '{
              valid: 1,
              stq_bank_idx: amo_ldq_to_stq_new[i].stq_bank_idx,
              stq_idx: amo_ldq_to_stq_new[i].stq_idx
          };
        end
      end


    end
  end


  // ldq,stqの更新.
  always_ff @(posedge clock) begin
    if (reset) begin

      // ldqのクリア,stqのクリア
      // ldq_state <= '{default: '{default: LD_NONE}};
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        ldq_state[i] <= '{default: LD_NONE};
        stq_state[i] <= '{default: ST_NONE};
      end


    end else if (flush_in) begin

      // ldqのクリア,stqのクリア
      // ldq_state <= '{default: '{default: LD_NONE}};
      for (int unsigned i = 0; i < NUM_OF_BANK; i++) begin
        ldq_state[i] <= '{default: LD_NONE};
        stq_state[i] <= '{default: ST_NONE};
      end

    end else begin

      // ----------------------------------------------------------------------------------------
      // ldq_maskの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE; i++) begin
        if (ldq_mask_update[i].valid) begin
          ldq_mask[ldq_mask_update[i].ldq_bank_idx][ldq_mask_update[i].ldq_idx] <= ldq_mask_update[i].mask;
        end
      end

      // ----------------------------------------------------------------------------------------
      // stq_maskの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
        if (stq_mask_update[i].valid) begin
          stq_mask[stq_mask_update[i].stq_bank_idx][stq_mask_update[i].stq_idx] <= stq_mask_update[i].mask;
        end
      end

      // ----------------------------------------------------------------------------------------
      // ldq_paddrの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE; i++) begin
        if (ldq_paddr_update_op_in[i].valid) begin
          ldq_paddr[ldq_paddr_update_op_in[i].ldq_bank_idx][ldq_paddr_update_op_in[i].ldq_idx] <= ldq_paddr_update_op_in[i].paddr;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
        if (ldq_paddr_update_dtlb[i].valid) begin
          ldq_paddr[ldq_paddr_update_dtlb[i].ldq_bank_idx][ldq_paddr_update_dtlb[i].ldq_idx] <= ldq_paddr_update_dtlb[i].paddr;
        end
      end

      // ----------------------------------------------------------------------------------------
      // stq_paddrの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
        if (stq_paddr_update_op_in[i].valid) begin
          stq_paddr[stq_paddr_update_op_in[i].stq_bank_idx][stq_paddr_update_op_in[i].stq_idx] <= stq_paddr_update_op_in[i].paddr;
        end
      end
      for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
        if (stq_paddr_update_dtlb[i].valid) begin
          stq_paddr[stq_paddr_update_dtlb[i].stq_bank_idx][stq_paddr_update_dtlb[i].stq_idx] <= stq_paddr_update_dtlb[i].paddr;
        end
      end

      // ----------------------------------------------------------------------------------------
      // ldq_stateの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (ldq_alloc_update[i].valid) begin
          ldq_state[ldq_alloc_update[i].ldq_bank_idx][ldq_alloc_update[i].ldq_idx] <= ldq_alloc_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE; i++) begin
        if (ldq_op_in_update[i].valid) begin
          ldq_state[ldq_op_in_update[i].ldq_bank_idx][ldq_op_in_update[i].ldq_idx] <= ldq_op_in_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
        if (ldq_tlb_req_update[i].valid) begin
          ldq_state[ldq_tlb_req_update[i].ldq_bank_idx][ldq_tlb_req_update[i].ldq_idx] <= ldq_tlb_req_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
        if (ldq_tlb_res_update[i].valid) begin
          ldq_state[ldq_tlb_res_update[i].ldq_bank_idx][ldq_tlb_res_update[i].ldq_idx] <= ldq_tlb_res_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        if (ldq_req_out_update[i].valid) begin
          ldq_state[ldq_req_out_update[i].ldq_bank_idx][ldq_req_out_update[i].ldq_idx] <= ldq_req_out_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
        if (ldq_done_update[i].valid) begin
          ldq_state[ldq_done_update[i].ldq_bank_idx][ldq_done_update[i].ldq_idx] <= ldq_done_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (ldq_delete_update[i].valid) begin
          ldq_state[ldq_delete_update[i].ldq_bank_idx][ldq_delete_update[i].ldq_idx] <= ldq_delete_update[i].next_state;
        end
      end


      // ----------------------------------------------------------------------------------------
      // stq_stateの更新
      // ----------------------------------------------------------------------------------------
      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (stq_alloc_update[i].valid) begin
          stq_state[stq_alloc_update[i].stq_bank_idx][stq_alloc_update[i].stq_idx] <= stq_alloc_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
        if (stq_op_in_update[i].valid) begin
          stq_state[stq_op_in_update[i].stq_bank_idx][stq_op_in_update[i].stq_idx] <= stq_op_in_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
        if (stq_tlb_req_update[i].valid) begin
          stq_state[stq_tlb_req_update[i].stq_bank_idx][stq_tlb_req_update[i].stq_idx] <= stq_tlb_req_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
        if (stq_tlb_res_update[i].valid) begin
          stq_state[stq_tlb_res_update[i].stq_bank_idx][stq_tlb_res_update[i].stq_idx] <= stq_tlb_res_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
        if (stq_amo_get_rs2_update[i].valid) begin
          stq_state[stq_amo_get_rs2_update[i].stq_bank_idx][stq_amo_get_rs2_update[i].stq_idx] <= stq_amo_get_rs2_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
        if (stq_exe_done_update[i].valid) begin
          stq_state[stq_exe_done_update[i].stq_bank_idx][stq_exe_done_update[i].stq_idx] <= stq_exe_done_update[i].next_state;
        end
      end

      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (stq_delete_update[i].valid) begin
          stq_state[stq_delete_update[i].stq_bank_idx][stq_delete_update[i].stq_idx] <= stq_delete_update[i].next_state;
        end
      end

    end
  end









  // ============================================================
  // Debug dump helpers for LDQ/STQ
  // ============================================================

  function automatic string ld_state_to_str(input ld_state_t s);
    case (s)
      LD_BEFORE_ARRIVE:            return "LD_BEFORE_ARRIVE";
      LD_BEFORE_TLB_REQUEST:       return "LD_BEFORE_TLB_REQUEST";
      LD_DURING_TLB_REQUEST:       return "LD_DURING_TLB_REQUEST";
      LD_BEFORE_CACHE_REQUEST:     return "LD_BEFORE_CACHE_REQUEST";
      LD_BEFORE_CACHE_REQUEST_AMO: return "LD_BEFORE_CACHE_REQUEST_AMO";
      LD_BEFORE_MMIO_REQUEST:      return "LD_BEFORE_MMIO_REQUEST";
      LD_DURING_CACHE_REQUEST:     return "LD_DURING_CACHE_REQUEST";
      LD_DURING_CACHE_REQUEST_AMO: return "LD_DURING_CACHE_REQUEST_AMO";
      LD_DURING_MMIO_REQUEST:      return "LD_DURING_MMIO_REQUEST";
      LD_DONE:                     return "LD_DONE";
      LD_PAGE_FAULT:               return "LD_PAGE_FAULT";
      LD_ACCESS_FAULT:             return "LD_ACCESS_FAULT";
      LD_NONE:                     return "LD_NONE";
      default:                     return "LD_STATE_UNKNOWN";
    endcase
  endfunction

  function automatic string st_state_to_str(input st_state_t s);
    case (s)
      ST_BEFORE_ARRIVE:                  return "ST_BEFORE_ARRIVE";
      ST_BEFORE_TLB_REQUEST:             return "ST_BEFORE_TLB_REQUEST";
      ST_BEFORE_TLB_REQUEST_CONDITIONAL: return "ST_BEFORE_TLB_REQUEST_CONDITIONAL";
      ST_DURING_TLB_REQUEST:             return "ST_DURING_TLB_REQUEST";
      ST_DURING_TLB_REQUEST_CONDITIONAL: return "ST_DURING_TLB_REQUEST_CONDITIONAL";
      ST_AMO_WAITING_RS2:                return "ST_AMO_WAITING_RS2";
      ST_BEFORE_EXE_CONDITIONAL:         return "ST_BEFORE_EXE_CONDITIONAL";
      ST_BEFORE_MMIO_EXE:                return "ST_BEFORE_MMIO_EXE";
      ST_BEFORE_EXE:                     return "ST_BEFORE_EXE";
      ST_DONE:                           return "ST_DONE";
      ST_DONE_NO_OUT:                    return "ST_DONE_NO_OUT";
      ST_PAGE_FAULT:                     return "ST_PAGE_FAULT";
      ST_ACCESS_FAULT:                   return "ST_ACCESS_FAULT";
      ST_NONE:                           return "ST_NONE";
      default:                           return "ST_STATE_UNKNOWN";
    endcase
  endfunction

  task automatic dump_ldq_state();
    $display("\n========== LDQ DUMP ==========");
    $display(" time=%0t gen=%0d stall_append_to_al=%0b al_rp=%0d al_wp=%0d", $time, generation,
             stall_append_to_al, renamer_port.al_rp, renamer_port.al_wp);

    for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
      $display("  [LDQ bank %0d] free_counter=%0d", b, ld_free_counter[b]);
      for (int unsigned i = 0; i < LDQ_BANK_SIZE; i++) begin

        $display(
            "    ldq[%0d][%0d] state=%0s(%0d) al_valid=%0b al_idx=%0d paddr=%h mask=%02h", b, i,
            ld_state_to_str(ldq_state[b][i]), ldq_state[b][i],
            al_to_ldq_idx[ldq_to_al_idx[b][i]].valid,  // 逆引きが壊れてないかの簡易確認
            ldq_to_al_idx[b][i], ldq_paddr[b][i], ldq_mask[b][i]);

      end
    end
  endtask

  task automatic dump_stq_state();
    $display("\n========== STQ DUMP ==========");
    $display(" time=%0t gen=%0d stall_append_to_al=%0b al_rp=%0d al_wp=%0d", $time, generation,
             stall_append_to_al, renamer_port.al_rp, renamer_port.al_wp);

    for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
      $display("  [STQ bank %0d] free_counter=%0d", b, st_free_counter[b]);
      for (int unsigned i = 0; i < STQ_BANK_SIZE; i++) begin

        $display(
            "    stq[%0d][%0d] state=%0s(%0d) al_valid=%0b al_idx=%0d paddr=%h mask=%02h", b, i,
            st_state_to_str(stq_state[b][i]), stq_state[b][i],
            al_to_stq_idx[stq_to_al_idx[b][i]].valid,  // 逆引きが壊れてないかの簡易確認
            stq_to_al_idx[b][i], stq_paddr[b][i], stq_mask[b][i]);

      end
    end
  endtask

  task automatic dump_op(input vuop_back_t u);
    $display("\n========== VUOP_BACK DUMP ==========");
    $display("  valid=%0b  %s", u.valid, u.opcode.name());
    $display("  op_addr=%h  al_idx=%0d", u.op_addr, u.al_idx);

    $display("  rs1_exist=%0b rs2_exist=%0b rd_exist=%0b", u.rs1_exist, u.rs2_exist, u.rd_exist);
    $display("  rs1=%0d rs2=%0d rd=%0d", u.rs1, u.rs2, u.rd);
    $display("  rs1_val=%h rs2_val=%h imm=%h", u.rs1_val, u.rs2_val, u.imm);

    $display("  actual_taken=%0b actual_taken_addr=%h", u.actual_taken, u.actual_taken_addr);
  endtask

  task automatic dump_vuop_result(input vuop_result_t r);
    begin
      $display("========== VUOP_RESULT DUMP ==========");

      $display("  valid              = %0b", r.valid);
      $display("  opcode             = %0d / 0x%0h", r.opcode, r.opcode);
      $display("  op_addr            = 0x%0h", r.op_addr);

      $display("  rd_exist           = %0b", r.rd_exist);
      $display("  rd                 = %0d", r.rd);
      $display("  rd_val             = 0x%0h", r.rd_val);

      $display("  al_idx             = %0d", r.al_idx);

      $display("  actual_taken       = %0b", r.actual_taken);
      $display("  actual_taken_addr  = 0x%0h", r.actual_taken_addr);

      $display("  ldst_target_paddr  = 0x%0h", r.ldst_target_paddr);
      $display("  ldst_target_vaddr  = 0x%0h", r.ldst_target_vaddr);

      $display("  is_page_fault      = %0b", r.is_page_fault);
      $display("  is_access_fault    = %0b", r.is_access_fault);

      $display("======================================");
    end
  endtask


  // ============================================================
  // Debug watcher: dump LDQ/STQ when state arrays changed
  // (sample on negedge so posedge-updated state is visible)
  // ============================================================


  ld_state_t ldq_state_dbg_prev[NUM_OF_BANK][LDQ_BANK_SIZE];
  st_state_t stq_state_dbg_prev[NUM_OF_BANK][STQ_BANK_SIZE];
  logic dbg_state_watch_inited;

`ifdef VERILATOR_COMPILE
  int fp_lsu_log;
  initial begin
    fp_lsu_log = $fopen("./log/lsu_log.txt", "w");
  end
  task automatic dump_ldq_state_f();
    if (fp_lsu_log == 0) begin
      $display("[ERROR][LSU] dump_ldq_state_f: fp_lsu_log == 0");
      return;
    end

    $fdisplay(fp_lsu_log, "\n========== LDQ DUMP ==========");
    $fdisplay(fp_lsu_log, " time=%0t gen=%0d stall_append_to_al=%0b al_rp=%0d al_wp=%0d", $time,
              generation, stall_append_to_al, renamer_port.al_rp, renamer_port.al_wp);

    for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
      $fdisplay(fp_lsu_log, "  [LDQ bank %0d] free_counter=%0d", b, ld_free_counter[b]);
      for (int unsigned i = 0; i < LDQ_BANK_SIZE; i++) begin
        $fdisplay(
            fp_lsu_log,
            "    ldq[%0d][%0d] state=%0s(%0d) al_valid=%0b al_idx=%0d paddr=%h mask=%02h", b, i,
            ld_state_to_str(ldq_state[b][i]), ldq_state[b][i],
            al_to_ldq_idx[ldq_to_al_idx[b][i]].valid,  // 逆引きが壊れてないかの簡易確認
            ldq_to_al_idx[b][i], ldq_paddr[b][i], ldq_mask[b][i]);
      end
    end

    $fflush(fp_lsu_log);
  endtask

  task automatic dump_stq_state_f();
    if (fp_lsu_log == 0) begin
      $display("[ERROR][LSU] dump_stq_state_f: fp_lsu_log == 0");
      return;
    end

    $fdisplay(fp_lsu_log, "\n========== STQ DUMP ==========");
    $fdisplay(fp_lsu_log, " time=%0t gen=%0d stall_append_to_al=%0b al_rp=%0d al_wp=%0d", $time,
              generation, stall_append_to_al, renamer_port.al_rp, renamer_port.al_wp);

    for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
      $fdisplay(fp_lsu_log, "  [STQ bank %0d] free_counter=%0d", b, st_free_counter[b]);
      for (int unsigned i = 0; i < STQ_BANK_SIZE; i++) begin
        $fdisplay(
            fp_lsu_log,
            "    stq[%0d][%0d] state=%0s(%0d) al_valid=%0b al_idx=%0d paddr=%h mask=%02h", b, i,
            st_state_to_str(stq_state[b][i]), stq_state[b][i],
            al_to_stq_idx[stq_to_al_idx[b][i]].valid,  // 逆引きが壊れてないかの簡易確認
            stq_to_al_idx[b][i], stq_paddr[b][i], stq_mask[b][i]);
      end
    end

    $fflush(fp_lsu_log);
  endtask
`endif

  // (*mark_debug="true" *) vuop_back_t op_st_amo_in_deubg;
  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     op_st_amo_in_deubg <= '0;
  //   end else begin
  //     op_st_amo_in_deubg <= op_st_amo_in[0];
  //   end
  // end

  // (*mark_debug="true"*) vuop_back_t op_ld_in0_debug;
  // always_ff @(posedge clock) begin
  //   if (reset) begin
  //     op_ld_in0_debug <= '0;
  //   end else begin
  //     op_ld_in0_debug <= op_ld_in[0];
  //   end
  // end

  // always_comb begin
  //   for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
  //     if (op_ld_in[i].valid && op_ld_in[i].op_addr == 39'h800025e8) begin
  //       dump_op(op_ld_in[i]);
  //     end
  //   end

  //   for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //     if (op_ld_out[i].valid && op_ld_out[i].op_addr == 39'h800025e8) begin
  //       dump_vuop_result(op_ld_out[i]);
  //     end
  //   end
  // end



  // ------------------------------------------------------------
  // realtime LSU dump
  // 1000 cycleごとに ./log/realtime_lsu.log を上書き作成する
  // endmodule の直前に貼る
  // ------------------------------------------------------------
  // `ifdef VERILATOR_COMPILE

  //   localparam int unsigned REALTIME_LSU_DUMP_PERIOD = 1000;

  //   longint unsigned realtime_lsu_cycle;
  //   int realtime_lsu_fp;

  //   function automatic string realtime_lsu_ld_state_name(input ld_state_t s);
  //     case (s)
  //       LD_BEFORE_ARRIVE:            return "LD_BEFORE_ARRIVE";
  //       LD_BEFORE_TLB_REQUEST:       return "LD_BEFORE_TLB_REQUEST";
  //       LD_DURING_TLB_REQUEST:       return "LD_DURING_TLB_REQUEST";
  //       LD_BEFORE_CACHE_REQUEST:     return "LD_BEFORE_CACHE_REQUEST";
  //       LD_BEFORE_CACHE_REQUEST_AMO: return "LD_BEFORE_CACHE_REQUEST_AMO";
  //       LD_BEFORE_MMIO_REQUEST:      return "LD_BEFORE_MMIO_REQUEST";
  //       LD_DURING_CACHE_REQUEST:     return "LD_DURING_CACHE_REQUEST";
  //       LD_DURING_CACHE_REQUEST_AMO: return "LD_DURING_CACHE_REQUEST_AMO";
  //       LD_DURING_MMIO_REQUEST:      return "LD_DURING_MMIO_REQUEST";
  //       LD_DONE:                     return "LD_DONE";
  //       LD_PAGE_FAULT:               return "LD_PAGE_FAULT";
  //       LD_ACCESS_FAULT:             return "LD_ACCESS_FAULT";
  //       LD_NONE:                     return "LD_NONE";
  //       default:                     return "LD_STATE_UNKNOWN";
  //     endcase
  //   endfunction

  //   function automatic string realtime_lsu_st_state_name(input st_state_t s);
  //     case (s)
  //       ST_BEFORE_ARRIVE:                  return "ST_BEFORE_ARRIVE";
  //       ST_BEFORE_TLB_REQUEST:             return "ST_BEFORE_TLB_REQUEST";
  //       ST_BEFORE_TLB_REQUEST_CONDITIONAL: return "ST_BEFORE_TLB_REQUEST_CONDITIONAL";
  //       ST_DURING_TLB_REQUEST:             return "ST_DURING_TLB_REQUEST";
  //       ST_DURING_TLB_REQUEST_CONDITIONAL: return "ST_DURING_TLB_REQUEST_CONDITIONAL";
  //       ST_AMO_WAITING_RS2:                return "ST_AMO_WAITING_RS2";
  //       ST_BEFORE_EXE_CONDITIONAL:         return "ST_BEFORE_EXE_CONDITIONAL";
  //       ST_BEFORE_MMIO_EXE:                return "ST_BEFORE_MMIO_EXE";
  //       ST_BEFORE_EXE:                     return "ST_BEFORE_EXE";
  //       ST_DONE:                           return "ST_DONE";
  //       ST_DONE_NO_OUT:                    return "ST_DONE_NO_OUT";
  //       ST_PAGE_FAULT:                     return "ST_PAGE_FAULT";
  //       ST_ACCESS_FAULT:                   return "ST_ACCESS_FAULT";
  //       ST_NONE:                           return "ST_NONE";
  //       default:                           return "ST_STATE_UNKNOWN";
  //     endcase
  //   endfunction

  //   task automatic realtime_lsu_dump_vuop_back_f(input int unsigned fp, input string name,
  //                                                input int unsigned idx, input vuop_back_t u);
  //     $fdisplay(fp, "%s[%0d]: valid=%0d opcode=%s op_addr=0x%010h al_idx=%0d", name, idx, u.valid,
  //               u.opcode.name(), u.op_addr, u.al_idx);
  //     $fdisplay(fp, "  rs1_exist=%0d rs2_exist=%0d rd_exist=%0d rs1=%0d rs2=%0d rd=%0d", u.rs1_exist,
  //               u.rs2_exist, u.rd_exist, u.rs1, u.rs2, u.rd);
  //     $fdisplay(fp, "  rs1_val=0x%016h rs2_val=0x%016h imm=0x%016h", u.rs1_val, u.rs2_val, u.imm);
  //     $fdisplay(fp, "  actual_taken=%0d actual_taken_addr=0x%010h", u.actual_taken,
  //               u.actual_taken_addr);
  //   endtask

  //   task automatic realtime_lsu_dump_vuop_result_f(input int unsigned fp, input string name,
  //                                                  input int unsigned idx, input vuop_result_t r);
  //     $fdisplay(fp, "%s[%0d]: valid=%0d opcode=%s op_addr=0x%010h al_idx=%0d", name, idx, r.valid,
  //               r.opcode.name(), r.op_addr, r.al_idx);
  //     $fdisplay(fp, "  rd_exist=%0d rd=%0d rd_val=0x%016h", r.rd_exist, r.rd, r.rd_val);
  //     $fdisplay(fp, "  ldst_vaddr=0x%010h ldst_paddr=0x%010h pf=%0d af=%0d", r.ldst_target_vaddr,
  //               r.ldst_target_paddr, r.is_page_fault, r.is_access_fault);
  //     $fdisplay(fp, "  actual_taken=%0d actual_taken_addr=0x%010h", r.actual_taken,
  //               r.actual_taken_addr);
  //   endtask

  //   task automatic realtime_lsu_dump_file(input longint unsigned cyc);
  //     realtime_lsu_fp = $fopen("./log/realtime_lsu.log", "w");

  //     if (realtime_lsu_fp == 0) begin
  //       $display("[REALTIME_LSU_DUMP][ERROR] cannot open ./log/realtime_lsu.log");
  //     end else begin
  //       $fdisplay(realtime_lsu_fp, "============================================================");
  //       $fdisplay(realtime_lsu_fp, "[REALTIME_LSU_DUMP] time=%0t cycle=%0d generation=0x%08h", $time,
  //                 cyc, generation);
  //       $fdisplay(realtime_lsu_fp, "------------------------------------------------------------");

  //       $fdisplay(
  //           realtime_lsu_fp,
  //           "global: reset=%0d flush_in=%0d stall_append_to_al=%0d stall_prev=%0d dcache_noroom=%0d",
  //           reset, flush_in, stall_append_to_al, stall_append_to_al_prev, dcache_noroom);

  //       $fdisplay(
  //           realtime_lsu_fp,
  //           "renamer_port: al_rp=%0d al_wp=%0d sc_mmio_exec.has_lock=%0d lock_paddr=0x%010h is_lr_w=%0d",
  //           renamer_port.al_rp, renamer_port.al_wp, renamer_port.sc_mmio_executable.has_lock,
  //           renamer_port.sc_mmio_executable.lock_paddr, renamer_port.sc_mmio_executable.is_lr_w);

  //       $fdisplay(realtime_lsu_fp,
  //                 "ld_spec_feedback: now_valid=%0d now_al_idx=%0d next_valid=%0d next_al_idx=%0d",
  //                 ld_speculative_feedback_valid, ld_speculative_feedback_al_idx,
  //                 ld_speculative_feedback_valid_next, ld_speculative_feedback_al_idx_next);

  //       $fdisplay(
  //           realtime_lsu_fp,
  //           "rr: rr_ldq_idx=%0d rr_stq_idx=%0d tlb_req_rr_base_bank_idx=%0d ldq_exe_rr_bank_idx=%0d stq_exe_rr_bank_idx=%0d rr_ldq_fault_base_bank_idx=%0d",
  //           rr_ldq_idx, rr_stq_idx, tlb_req_rr_base_bank_idx, ldq_exe_rr_bank_idx,
  //           stq_exe_rr_bank_idx, rr_ldq_fault_base_bank_idx);

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== INPUT OPS ====================");

  //       for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
  //         realtime_lsu_dump_vuop_back_f(realtime_lsu_fp, "op_ld_in", i, op_ld_in[i]);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
  //         realtime_lsu_dump_vuop_back_f(realtime_lsu_fp, "op_st_amo_in", i, op_st_amo_in[i]);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== OUTPUT OPS TO RENAMER ====================");

  //       for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //         realtime_lsu_dump_vuop_result_f(realtime_lsu_fp, "op_ld_out", i, op_ld_out[i]);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //         realtime_lsu_dump_vuop_result_f(realtime_lsu_fp, "op_st_out", i, op_st_out[i]);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== RENAMER NEW/COMMIT ====================");

  //       for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "new_instr[%0d]: valid=%0d opcode=%s al_idx=%0d op_addr=0x%010h fence(si=%0d so=%0d sr=%0d sw=%0d)",
  //             i, renamer_port.new_instr[i].valid, renamer_port.new_instr[i].opcode.name(),
  //             renamer_port.new_instr[i].al_idx, renamer_port.new_instr[i].op_addr,
  //             renamer_port.new_instr[i].si, renamer_port.new_instr[i].so,
  //             renamer_port.new_instr[i].sr, renamer_port.new_instr[i].sw);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
  //         $fdisplay(realtime_lsu_fp, "committed_instr[%0d]: valid=%0d al_idx=%0d", i,
  //                   renamer_port.committed_instr[i].valid, renamer_port.committed_instr[i].al_idx);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== LDQ STATE ====================");

  //       for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "[LDQ bank %0d] free_counter=%0d free_avail(valid=%0d idx=%0d) before_tlb(valid=%0d idx=%0d) before_cache(valid=%0d idx=%0d) before_mmio(valid=%0d idx=%0d) pf(valid=%0d idx=%0d) af(valid=%0d idx=%0d)",
  //             b, ld_free_counter[b], ldq_free_avail[b].valid, ldq_free_avail[b].ldq_idx,
  //             ldq_before_tlb_avail[b].valid, ldq_before_tlb_avail[b].ldq_idx,
  //             ldq_before_cache_req_avail[b].valid, ldq_before_cache_req_avail[b].ldq_idx,
  //             ldq_before_mmio_req_avail[b].valid, ldq_before_mmio_req_avail[b].ldq_idx,
  //             ldq_pf_avail[b].valid, ldq_pf_avail[b].ldq_idx, ldq_af_avail[b].valid,
  //             ldq_af_avail[b].ldq_idx);

  //         for (int unsigned i = 0; i < LDQ_BANK_SIZE; i++) begin
  //           $fdisplay(
  //               realtime_lsu_fp,
  //               "  ldq[%0d][%0d]: state=%0s(%0d) al_idx=%0d al_valid=%0d paddr=0x%010h mask=0x%02h ft(ld_blocked=%0d st_blocked=%0d) amo_to_stq(valid=%0d st_bank=%0d st_idx=%0d)",
  //               b, i, realtime_lsu_ld_state_name(ldq_state[b][i]), ldq_state[b][i],
  //               ldq_to_al_idx[b][i], al_to_ldq_idx[ldq_to_al_idx[b][i]].valid, ldq_paddr[b][i],
  //               ldq_mask[b][i], ft[ldq_to_al_idx[b][i]].ld_blocked,
  //               ft[ldq_to_al_idx[b][i]].st_blocked, amo_ldq_to_stq[b][i].valid,
  //               amo_ldq_to_stq[b][i].stq_bank_idx, amo_ldq_to_stq[b][i].stq_idx);
  //         end
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== STQ STATE ====================");

  //       for (int unsigned b = 0; b < NUM_OF_BANK; b++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "[STQ bank %0d] free_counter=%0d free_avail(valid=%0d idx=%0d) before_tlb(valid=%0d idx=%0d) before_tlb_cond(valid=%0d idx=%0d) before_exe(valid=%0d idx=%0d) before_exe_cond(valid=%0d idx=%0d) before_mmio(valid=%0d idx=%0d) pf(valid=%0d idx=%0d) af(valid=%0d idx=%0d)",
  //             b, st_free_counter[b], stq_free_avail[b].valid, stq_free_avail[b].stq_idx,
  //             stq_before_tlb_avail[b].valid, stq_before_tlb_avail[b].stq_idx,
  //             stq_before_tlb_cond_avail[b].valid, stq_before_tlb_cond_avail[b].stq_idx,
  //             stq_before_exe_avail[b].valid, stq_before_exe_avail[b].stq_idx,
  //             stq_before_exe_cond_avail[b].valid, stq_before_exe_cond_avail[b].stq_idx,
  //             stq_before_mmio_exe_avail[b].valid, stq_before_mmio_exe_avail[b].stq_idx,
  //             stq_pf_avail[b].valid, stq_pf_avail[b].stq_idx, stq_af_avail[b].valid,
  //             stq_af_avail[b].stq_idx);

  //         for (int unsigned i = 0; i < STQ_BANK_SIZE; i++) begin
  //           $fdisplay(
  //               realtime_lsu_fp,
  //               "  stq[%0d][%0d]: state=%0s(%0d) al_idx=%0d al_valid=%0d paddr=0x%010h mask=0x%02h ft(ld_blocked=%0d st_blocked=%0d)",
  //               b, i, realtime_lsu_st_state_name(stq_state[b][i]), stq_state[b][i],
  //               stq_to_al_idx[b][i], al_to_stq_idx[stq_to_al_idx[b][i]].valid, stq_paddr[b][i],
  //               stq_mask[b][i], ft[stq_to_al_idx[b][i]].ld_blocked,
  //               ft[stq_to_al_idx[b][i]].st_blocked);
  //         end
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp,
  //                 "==================== AL <-> LDQ/STQ CONVERSION ====================");

  //       for (int unsigned i = 0; i < ACTIVELIST_SIZE; i++) begin
  //         if (al_to_ldq_idx[i].valid || al_to_stq_idx[i].valid) begin
  //           $fdisplay(
  //               realtime_lsu_fp,
  //               "al_idx[%0d]: ldq(valid=%0d bank=%0d idx=%0d) stq(valid=%0d bank=%0d idx=%0d) ft(ld_blocked=%0d st_blocked=%0d)",
  //               i, al_to_ldq_idx[i].valid, al_to_ldq_idx[i].ldq_bank_idx, al_to_ldq_idx[i].ldq_idx,
  //               al_to_stq_idx[i].valid, al_to_stq_idx[i].stq_bank_idx, al_to_stq_idx[i].stq_idx,
  //               ft[i].ld_blocked, ft[i].st_blocked);
  //         end
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== TLB REQ/RES ====================");

  //       $fdisplay(realtime_lsu_fp, "tlb_port.stall_req_to_dtlb=%0d", tlb_port.stall_req_to_dtlb);

  //       for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "tlb_ld_req_info[%0d]: now(valid=%0d bank=%0d ldq_idx=%0d) prev(valid=%0d bank=%0d ldq_idx=%0d)",
  //             i, tlb_ld_req_info[i].valid, tlb_ld_req_info[i].bank_idx, tlb_ld_req_info[i].ldq_idx,
  //             tlb_ld_req_info_prev[i].valid, tlb_ld_req_info_prev[i].bank_idx,
  //             tlb_ld_req_info_prev[i].ldq_idx);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "tlb_st_req_info[%0d]: now(valid=%0d bank=%0d stq_idx=%0d) prev(valid=%0d bank=%0d stq_idx=%0d)",
  //             i, tlb_st_req_info[i].valid, tlb_st_req_info[i].bank_idx, tlb_st_req_info[i].stq_idx,
  //             tlb_st_req_info_prev[i].valid, tlb_st_req_info_prev[i].bank_idx,
  //             tlb_st_req_info_prev[i].stq_idx);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_DTLB_REQ; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "tlb_req[%0d]: valid=%0d id=%0d id_sub=%0d gen=0x%08h vaddr=0x%010h", i,
  //                   tlb_port.req[i].valid, tlb_port.req[i].id, tlb_port.req[i].id_sub,
  //                   tlb_port.req[i].generation, tlb_port.req[i].vaddr);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "tlb_res[%0d]: valid=%0d id=%0d id_sub=%0d gen=0x%08h vaddr=0x%010h paddr=0x%010h pf=%0d pte_a=%0d pte_d=%0d pma_type=%0d",
  //             i, tlb_port.res[i].valid, tlb_port.res[i].id, tlb_port.res[i].id_sub,
  //             tlb_port.res[i].generation, tlb_port.res[i].vaddr, tlb_port.res[i].paddr,
  //             tlb_port.res[i].is_page_fault, tlb_port.res[i].pte_a, tlb_port.res[i].pte_d,
  //             tlb_port.res[i].pma_type);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== DCACHE REQ/RES ====================");

  //       for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "req_to_dcache_ld[%0d]: valid=%0d id=%0d gen=0x%08h type=%0d paddr_valid=%0d paddr_dw=0x%010h byte_idx=%0d data=0x%016h",
  //             i, req_to_dcache_ld[i].valid, req_to_dcache_ld[i].id, req_to_dcache_ld[i].generation,
  //             req_to_dcache_ld[i].cb_req_type, req_to_dcache_ld[i].paddr_valid,
  //             req_to_dcache_ld[i].paddr_db_aligned, req_to_dcache_ld[i].byte_in_db_idx,
  //             req_to_dcache_ld[i].data);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "req_to_dcache_st[%0d]: valid=%0d id=%0d gen=0x%08h type=%0d paddr_valid=%0d paddr_dw=0x%010h byte_idx=%0d data=0x%016h",
  //             i, req_to_dcache_st[i].valid, req_to_dcache_st[i].id, req_to_dcache_st[i].generation,
  //             req_to_dcache_st[i].cb_req_type, req_to_dcache_st[i].paddr_valid,
  //             req_to_dcache_st[i].paddr_db_aligned, req_to_dcache_st[i].byte_in_db_idx,
  //             req_to_dcache_st[i].data);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_CACHE_REQ; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "req_to_dcache_next[%0d]: valid=%0d id=%0d gen=0x%08h type=%0d paddr_valid=%0d paddr_dw=0x%010h byte_idx=%0d data=0x%016h",
  //             i, req_to_dcache_next[i].valid, req_to_dcache_next[i].id,
  //             req_to_dcache_next[i].generation, req_to_dcache_next[i].cb_req_type,
  //             req_to_dcache_next[i].paddr_valid, req_to_dcache_next[i].paddr_db_aligned,
  //             req_to_dcache_next[i].byte_in_db_idx, req_to_dcache_next[i].data);

  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "req_to_dcache_reg[%0d]:  valid=%0d id=%0d gen=0x%08h type=%0d paddr_valid=%0d paddr_dw=0x%010h byte_idx=%0d data=0x%016h",
  //             i, req_to_dcache[i].valid, req_to_dcache[i].id, req_to_dcache[i].generation,
  //             req_to_dcache[i].cb_req_type, req_to_dcache[i].paddr_valid,
  //             req_to_dcache[i].paddr_db_aligned, req_to_dcache[i].byte_in_db_idx,
  //             req_to_dcache[i].data);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "res_from_dcache[%0d]:      valid=%0d id=%0d gen=0x%08h data=0x%016h", i,
  //                   res_from_dcache[i].valid, res_from_dcache[i].id, res_from_dcache[i].generation,
  //                   res_from_dcache[i].data);

  //         $fdisplay(realtime_lsu_fp,
  //                   "res_from_dcache_prev[%0d]: valid=%0d id=%0d gen=0x%08h data=0x%016h", i,
  //                   res_from_dcache_prev[i].valid, res_from_dcache_prev[i].id,
  //                   res_from_dcache_prev[i].generation, res_from_dcache_prev[i].data);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== MMIO REQ/RES ====================");

  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_clint_ld: valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_clint_ld.valid, req_to_clint_ld.id, req_to_clint_ld.paddr,
  //                 req_to_clint_ld.is_write, req_to_clint_ld.data);
  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_clint_st: valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_clint_st.valid, req_to_clint_st.id, req_to_clint_st.paddr,
  //                 req_to_clint_st.is_write, req_to_clint_st.data);
  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_plic_ld:  valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_plic_ld.valid, req_to_plic_ld.id, req_to_plic_ld.paddr,
  //                 req_to_plic_ld.is_write, req_to_plic_ld.data);
  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_plic_st:  valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_plic_st.valid, req_to_plic_st.id, req_to_plic_st.paddr,
  //                 req_to_plic_st.is_write, req_to_plic_st.data);

  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_clint:    valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_clint.valid, req_to_clint.id, req_to_clint.paddr, req_to_clint.is_write,
  //                 req_to_clint.data);
  //       $fdisplay(realtime_lsu_fp,
  //                 "req_to_plic:     valid=%0d id=%0d paddr=0x%010h is_write=%0d data=0x%016h",
  //                 req_to_plic.valid, req_to_plic.id, req_to_plic.paddr, req_to_plic.is_write,
  //                 req_to_plic.data);

  //       $fdisplay(realtime_lsu_fp, "res_from_clint:  valid=%0d id=%0d data=0x%016h",
  //                 res_from_clint.valid, res_from_clint.id, res_from_clint.data);
  //       $fdisplay(realtime_lsu_fp, "res_from_plic:   valid=%0d id=%0d data=0x%016h",
  //                 res_from_plic.valid, res_from_plic.id, res_from_plic.data);
  //       $fdisplay(realtime_lsu_fp, "mmio_res:        valid=%0d id=%0d data=0x%016h used=%0d",
  //                 mmio_res.valid, mmio_res.id, mmio_res.data, mmio_res_used);
  //       $fdisplay(realtime_lsu_fp, "mmio_res_prev:   valid=%0d id=%0d data=0x%016h",
  //                 mmio_res_prev.valid, mmio_res_prev.id, mmio_res_prev.data);

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== LD EXEC / OUT INFO ====================");

  //       for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "executed_ld_info[%0d]: now(valid=%0d bank=%0d ldq_idx=%0d) prev(valid=%0d bank=%0d ldq_idx=%0d)",
  //             i, executed_ld_info[i].valid, executed_ld_info[i].ldq_bank_idx,
  //             executed_ld_info[i].ldq_idx, executed_ld_info_prev[i].valid,
  //             executed_ld_info_prev[i].ldq_bank_idx, executed_ld_info_prev[i].ldq_idx);

  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "ld_op_out_info[%0d]: now(valid=%0d bank=%0d ldq_idx=%0d from=%s) prev(valid=%0d bank=%0d ldq_idx=%0d from=%s)",
  //             i, ld_op_out_info[i].valid, ld_op_out_info[i].ldq_bank_idx, ld_op_out_info[i].ldq_idx,
  //             ld_op_out_info[i].ld_from_where.name(), ld_op_out_info_prev[i].valid,
  //             ld_op_out_info_prev[i].ldq_bank_idx, ld_op_out_info_prev[i].ldq_idx,
  //             ld_op_out_info_prev[i].ld_from_where.name());

  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_done_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_done_update[i].valid, ldq_done_update[i].ldq_bank_idx,
  //                   ldq_done_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_done_update[i].next_state), ldq_done_update[i].next_state);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp,
  //                 "==================== ST EXEC / COMMIT TO DCACHE ====================");

  //       for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "st_exe_info[%0d]: now(valid=%0d bank=%0d stq_idx=%0d type=%s is_sc=%0d sc_success=%0d) prev(valid=%0d bank=%0d stq_idx=%0d type=%s is_sc=%0d sc_success=%0d)",
  //             i, st_exe_info[i].valid, st_exe_info[i].bank_idx, st_exe_info[i].stq_idx,
  //             st_exe_info[i].st_exe_type.name(), st_exe_info[i].is_sc, st_exe_info[i].sc_success,
  //             st_exe_info_prev[i].valid, st_exe_info_prev[i].bank_idx, st_exe_info_prev[i].stq_idx,
  //             st_exe_info_prev[i].st_exe_type.name(), st_exe_info_prev[i].is_sc,
  //             st_exe_info_prev[i].sc_success);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_exe_done_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_exe_done_update[i].valid, stq_exe_done_update[i].stq_bank_idx,
  //                   stq_exe_done_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_exe_done_update[i].next_state), stq_exe_done_update[i].next_state);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_CACHE_REQ; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "st_ent_to_dcache[%0d]: now(valid=%0d bank=%0d stq_idx=%0d) prev(valid=%0d bank=%0d stq_idx=%0d)",
  //             i, st_ent_to_dcache[i].valid, st_ent_to_dcache[i].stq_bank_idx,
  //             st_ent_to_dcache[i].stq_idx, st_ent_to_dcache_prev[i].valid,
  //             st_ent_to_dcache_prev[i].stq_bank_idx, st_ent_to_dcache_prev[i].stq_idx);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== STATE UPDATE SIGNALS ====================");

  //       for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_alloc_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_alloc_update[i].valid, ldq_alloc_update[i].ldq_bank_idx,
  //                   ldq_alloc_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_alloc_update[i].next_state), ldq_alloc_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_alloc_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_alloc_update[i].valid, stq_alloc_update[i].stq_bank_idx,
  //                   stq_alloc_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_alloc_update[i].next_state), stq_alloc_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "al_ldq_conv_new[%0d]: valid=%0d al_idx=%0d bank=%0d ldq_idx=%0d", i,
  //                   al_ldq_conv_new[i].valid, al_ldq_conv_new[i].al_idx, al_ldq_conv_new[i].bank_idx,
  //                   al_ldq_conv_new[i].ldq_idx);

  //         $fdisplay(realtime_lsu_fp,
  //                   "al_stq_conv_new[%0d]: valid=%0d al_idx=%0d bank=%0d stq_idx=%0d", i,
  //                   al_stq_conv_new[i].valid, al_stq_conv_new[i].al_idx, al_stq_conv_new[i].bank_idx,
  //                   al_stq_conv_new[i].stq_idx);

  //         $fdisplay(
  //             realtime_lsu_fp,
  //             "amo_ldq_to_stq_new[%0d]: valid=%0d ld_bank=%0d ld_idx=%0d st_bank=%0d st_idx=%0d", i,
  //             amo_ldq_to_stq_new[i].valid, amo_ldq_to_stq_new[i].ldq_bank_idx,
  //             amo_ldq_to_stq_new[i].ldq_idx, amo_ldq_to_stq_new[i].stq_bank_idx,
  //             amo_ldq_to_stq_new[i].stq_idx);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_op_in_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_op_in_update[i].valid, ldq_op_in_update[i].ldq_bank_idx,
  //                   ldq_op_in_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_op_in_update[i].next_state), ldq_op_in_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_paddr_update_op_in[%0d]: valid=%0d bank=%0d ldq_idx=%0d paddr=0x%010h", i,
  //                   ldq_paddr_update_op_in[i].valid, ldq_paddr_update_op_in[i].ldq_bank_idx,
  //                   ldq_paddr_update_op_in[i].ldq_idx, ldq_paddr_update_op_in[i].paddr);

  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_mask_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d mask=0x%02h", i,
  //                   ldq_mask_update[i].valid, ldq_mask_update[i].ldq_bank_idx,
  //                   ldq_mask_update[i].ldq_idx, ldq_mask_update[i].mask);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_op_in_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_op_in_update[i].valid, stq_op_in_update[i].stq_bank_idx,
  //                   stq_op_in_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_op_in_update[i].next_state), stq_op_in_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_paddr_update_op_in[%0d]: valid=%0d bank=%0d stq_idx=%0d paddr=0x%010h", i,
  //                   stq_paddr_update_op_in[i].valid, stq_paddr_update_op_in[i].stq_bank_idx,
  //                   stq_paddr_update_op_in[i].stq_idx, stq_paddr_update_op_in[i].paddr);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_mask_update[%0d]: valid=%0d bank=%0d stq_idx=%0d mask=0x%02h", i,
  //                   stq_mask_update[i].valid, stq_mask_update[i].stq_bank_idx,
  //                   stq_mask_update[i].stq_idx, stq_mask_update[i].mask);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_tlb_req_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_tlb_req_update[i].valid, ldq_tlb_req_update[i].ldq_bank_idx,
  //                   ldq_tlb_req_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_tlb_req_update[i].next_state), ldq_tlb_req_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_req_out_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_req_out_update[i].valid, ldq_req_out_update[i].ldq_bank_idx,
  //                   ldq_req_out_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_req_out_update[i].next_state), ldq_req_out_update[i].next_state);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_tlb_req_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_tlb_req_update[i].valid, stq_tlb_req_update[i].stq_bank_idx,
  //                   stq_tlb_req_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_tlb_req_update[i].next_state), stq_tlb_req_update[i].next_state);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_tlb_res_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_tlb_res_update[i].valid, ldq_tlb_res_update[i].ldq_bank_idx,
  //                   ldq_tlb_res_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_tlb_res_update[i].next_state), ldq_tlb_res_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_tlb_res_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_tlb_res_update[i].valid, stq_tlb_res_update[i].stq_bank_idx,
  //                   stq_tlb_res_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_tlb_res_update[i].next_state), stq_tlb_res_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_paddr_update_dtlb[%0d]: valid=%0d bank=%0d ldq_idx=%0d paddr=0x%010h", i,
  //                   ldq_paddr_update_dtlb[i].valid, ldq_paddr_update_dtlb[i].ldq_bank_idx,
  //                   ldq_paddr_update_dtlb[i].ldq_idx, ldq_paddr_update_dtlb[i].paddr);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_paddr_update_dtlb[%0d]: valid=%0d bank=%0d stq_idx=%0d paddr=0x%010h", i,
  //                   stq_paddr_update_dtlb[i].valid, stq_paddr_update_dtlb[i].stq_bank_idx,
  //                   stq_paddr_update_dtlb[i].stq_idx, stq_paddr_update_dtlb[i].paddr);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_amo_get_rs2_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_amo_get_rs2_update[i].valid, stq_amo_get_rs2_update[i].stq_bank_idx,
  //                   stq_amo_get_rs2_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_amo_get_rs2_update[i].next_state), stq_amo_get_rs2_update[i].next_state);
  //       end

  //       for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
  //         $fdisplay(realtime_lsu_fp,
  //                   "ldq_delete_update[%0d]: valid=%0d bank=%0d ldq_idx=%0d next=%0s(%0d)", i,
  //                   ldq_delete_update[i].valid, ldq_delete_update[i].ldq_bank_idx,
  //                   ldq_delete_update[i].ldq_idx, realtime_lsu_ld_state_name(
  //                   ldq_delete_update[i].next_state), ldq_delete_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "stq_delete_update[%0d]: valid=%0d bank=%0d stq_idx=%0d next=%0s(%0d)", i,
  //                   stq_delete_update[i].valid, stq_delete_update[i].stq_bank_idx,
  //                   stq_delete_update[i].stq_idx, realtime_lsu_st_state_name(
  //                   stq_delete_update[i].next_state), stq_delete_update[i].next_state);

  //         $fdisplay(realtime_lsu_fp,
  //                   "al_ldq_conv_del[%0d]: valid=%0d al_idx=%0d bank=%0d ldq_idx=%0d", i,
  //                   al_ldq_conv_del[i].valid, al_ldq_conv_del[i].al_idx, al_ldq_conv_del[i].bank_idx,
  //                   al_ldq_conv_del[i].ldq_idx);

  //         $fdisplay(realtime_lsu_fp,
  //                   "al_stq_conv_del[%0d]: valid=%0d al_idx=%0d bank=%0d stq_idx=%0d", i,
  //                   al_stq_conv_del[i].valid, al_stq_conv_del[i].al_idx, al_stq_conv_del[i].bank_idx,
  //                   al_stq_conv_del[i].stq_idx);
  //       end

  //       $fdisplay(realtime_lsu_fp, "");
  //       $fdisplay(realtime_lsu_fp, "==================== FENCEQ ====================");

  //       $fdisplay(
  //           realtime_lsu_fp,
  //           "fenceq_rp=%0d fenceq_wp=%0d noei_fenceq=%0d num_of_new_fence=%0d num_of_del_fence=%0d",
  //           fenceq_rp, fenceq_wp, noei_fenceq, num_of_new_fence, num_of_del_fence);

  //       for (int unsigned i = 0; i < FENCEQ_SIZE; i++) begin
  //         $fdisplay(
  //             realtime_lsu_fp, "fenceq[%0d]: valid=%0d al_idx=%0d block_suc_ld=%0d block_suc_st=%0d",
  //             i, fenceq[i].valid, fenceq[i].al_idx, fenceq[i].block_suc_ld, fenceq[i].block_suc_st);
  //       end

  //       $fdisplay(realtime_lsu_fp, "============================================================");
  //       $fflush(realtime_lsu_fp);
  //       $fclose(realtime_lsu_fp);
  //     end
  //   endtask

  //   always @(posedge clock) begin
  //     if (reset) begin
  //       realtime_lsu_cycle <= 0;
  //     end else begin
  //       realtime_lsu_cycle <= realtime_lsu_cycle + 1;

  //       if (((realtime_lsu_cycle + 1) % 64'(REALTIME_LSU_DUMP_PERIOD)) == 0) begin
  //         realtime_lsu_dump_file(realtime_lsu_cycle + 1);
  //       end
  //     end
  //   end

  // `endif



endmodule
