`timescale 1ns / 1ps
// 新しいtop

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"
`include "CACHE_PROPS.svh"

module Top (

`ifdef VIVADO_COMPILE
    // pmod出力
    output logic rts,
    input  logic cts,
    input  logic rxd,
    output logic txd,

    output logic led0,
    output logic led1,
    output logic led2,

    // axi_icache_port
    output logic axi_icache_port_awuser,
    output logic axi_icache_port_aruser,

    output logic [ 5:0] axi_icache_port_awid,
    output logic [48:0] axi_icache_port_awaddr,
    output logic [ 7:0] axi_icache_port_awlen,
    output logic [ 2:0] axi_icache_port_awsize,
    output logic [ 1:0] axi_icache_port_awburst,
    output logic        axi_icache_port_awlock,
    output logic [ 3:0] axi_icache_port_awcache,
    output logic [ 2:0] axi_icache_port_awprot,
    output logic        axi_icache_port_awvalid,
    input  logic        axi_icache_port_awready,

    output logic [127:0] axi_icache_port_wdata,
    output logic [ 15:0] axi_icache_port_wstrb,
    output logic         axi_icache_port_wlast,
    output logic         axi_icache_port_wvalid,
    input  logic         axi_icache_port_wready,

    input  logic [5:0] axi_icache_port_bid,
    input  logic [1:0] axi_icache_port_bresp,
    input  logic       axi_icache_port_bvalid,
    output logic       axi_icache_port_bready,

    output logic [ 5:0] axi_icache_port_arid,
    output logic [48:0] axi_icache_port_araddr,
    output logic [ 7:0] axi_icache_port_arlen,
    output logic [ 2:0] axi_icache_port_arsize,
    output logic [ 1:0] axi_icache_port_arburst,
    output logic        axi_icache_port_arlock,
    output logic [ 3:0] axi_icache_port_arcache,
    output logic [ 2:0] axi_icache_port_arprot,
    output logic        axi_icache_port_arvalid,
    input  logic        axi_icache_port_arready,

    input  logic [  5:0] axi_icache_port_rid,
    input  logic [127:0] axi_icache_port_rdata,
    input  logic [  1:0] axi_icache_port_rresp,
    input  logic         axi_icache_port_rlast,
    input  logic         axi_icache_port_rvalid,
    output logic         axi_icache_port_rready,

    output logic [3:0] axi_icache_port_awqos,
    output logic [3:0] axi_icache_port_arqos,

    // axi_dcache_port
    output logic axi_dcache_port_awuser,
    output logic axi_dcache_port_aruser,

    output logic [ 5:0] axi_dcache_port_awid,
    output logic [48:0] axi_dcache_port_awaddr,
    output logic [ 7:0] axi_dcache_port_awlen,
    output logic [ 2:0] axi_dcache_port_awsize,
    output logic [ 1:0] axi_dcache_port_awburst,
    output logic        axi_dcache_port_awlock,
    output logic [ 3:0] axi_dcache_port_awcache,
    output logic [ 2:0] axi_dcache_port_awprot,
    output logic        axi_dcache_port_awvalid,
    input  logic        axi_dcache_port_awready,

    output logic [63:0] axi_dcache_port_wdata,
    output logic [ 7:0] axi_dcache_port_wstrb,
    output logic        axi_dcache_port_wlast,
    output logic        axi_dcache_port_wvalid,
    input  logic        axi_dcache_port_wready,

    input  logic [5:0] axi_dcache_port_bid,
    input  logic [1:0] axi_dcache_port_bresp,
    input  logic       axi_dcache_port_bvalid,
    output logic       axi_dcache_port_bready,

    output logic [ 5:0] axi_dcache_port_arid,
    output logic [48:0] axi_dcache_port_araddr,
    output logic [ 7:0] axi_dcache_port_arlen,
    output logic [ 2:0] axi_dcache_port_arsize,
    output logic [ 1:0] axi_dcache_port_arburst,
    output logic        axi_dcache_port_arlock,
    output logic [ 3:0] axi_dcache_port_arcache,
    output logic [ 2:0] axi_dcache_port_arprot,
    output logic        axi_dcache_port_arvalid,
    input  logic        axi_dcache_port_arready,

    input  logic [ 5:0] axi_dcache_port_rid,
    input  logic [63:0] axi_dcache_port_rdata,
    input  logic [ 1:0] axi_dcache_port_rresp,
    input  logic        axi_dcache_port_rlast,
    input  logic        axi_dcache_port_rvalid,
    output logic        axi_dcache_port_rready,

    output logic [3:0] axi_dcache_port_awqos,
    output logic [3:0] axi_dcache_port_arqos,
`endif

`ifdef VERILATOR_COMPILE
    input logic inv_dump_sig,
`endif

    input logic clock_in,
    input logic reset_in

);
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import CACHE_PROPS::*;




  // ----------------------------------------------------------------------------------
  // cpu,clock,cpu_resetの設定
  // ----------------------------------------------------------------------------------
  logic cpu_clock;
  (* MARK_DEBUG = "true" *) logic cpu_reset;

  assign cpu_clock = clock_in;
  assign cpu_reset = reset_in;

  // -----------------------------------------------------------------
  // uart接続
  // -----------------------------------------------------------------
  // 変えるな.
  localparam int unsigned DEBUG_BUF_SIZE = 8;
  (*mark_debug="true"*) logic data_print_en;
  (*mark_debug="true"*) logic [DEBUG_BUF_SIZE-1:0] data_print;
  (*mark_debug="true"*) logic char_from_uart_valid;
  (*mark_debug="true"*) logic [7:0] char_from_uart;

  // -----------------------------------------------------------------------
  // op,pcなどの流れ
  // -----------------------------------------------------------------------
  // stage1 => stage2
  // pc_t pc_from_st1_to_st2;

  program_counter_t pc_from_st1_to_st2[NUM_OF_FETCH];

  // stage2 => stage3
  logic [NUM_OF_FETCH-1:0] pred_taken;
  logic [NUM_OF_FETCH-1:0] btb_hit_valid;
  logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_hit_addr;
  // pc_t pc_from_st2_to_st3;
  program_counter_t pc_from_st2_to_st3[NUM_OF_FETCH];
  pred_btb_result_t pred_btb_result;

  // stage3 => stage4
  ifq_decoder_t raw_op[NUM_OF_FETCH];

  // stage4 => stage5
  decoded_op_t decoded_op[NUM_OF_FETCH];

  // stage5 => stage6
  vuop_front_t renamed_op[NUM_OF_FETCH];

  // Stage6 => Stage7
  vuop_front_t issued_op_ari[NUM_OF_ARI_ISSUE];
  vuop_front_t issued_op_div[NUM_OF_DIV_ISSUE];
  vuop_front_t issued_op_ld[NUM_OF_LD_ISSUE];
  vuop_front_t issued_op_st_amo[NUM_OF_ST_AMO_ISSUE];
  vuop_front_t issued_op_csr[NUM_OF_CSR_ISSUE];

  // stage7 => stage8
  vuop_back_t op_rs_ready_ari[NUM_OF_ARI_ISSUE];
  vuop_back_t op_rs_ready_div[NUM_OF_DIV_ISSUE];
  vuop_back_t op_rs_ready_ld[NUM_OF_LD_ISSUE];
  vuop_back_t op_rs_ready_st_amo[NUM_OF_ST_AMO_ISSUE];
  vuop_back_t op_rs_ready_csr[NUM_OF_CSR_ISSUE];

  // stage8 => 
  vuop_result_t result_op_ari[NUM_OF_ARI_EXE];
  vuop_result_t result_op_div[NUM_OF_DIV_EXE];
  vuop_result_t result_op_ld[NUM_OF_LD_EXE];
  vuop_result_t result_op_st[NUM_OF_ST_EXE];
  vuop_result_t result_op_mmio;
  vuop_result_t result_op_csr[NUM_OF_CSR_EXE];
  vuop_result_t result_op[NUM_OF_RESULT_FEEDBACKS];

  // Decoder -> decoded_op -> Renamer -> (Renamer_LSU_if.new_instr) -> LSU -> Top.result_op(_ld) -> Top.result_op -> (Renamer) -> flush → IFQ/Decoder …
  // のループを断ち切るために,result_op2 <= result_op をalways_ffで更新する.
  vuop_result_t result_op2[NUM_OF_RESULT_FEEDBACKS];

  // result_op2 => Int Issue Queue
  feedback_rd_t result_feedback_rd[NUM_OF_RESULT_FEEDBACKS];


  logic flush_prev;
  always_ff @(posedge cpu_clock) begin
    if (cpu_reset) begin
      flush_prev <= 0;
    end else begin
      flush_prev <= flush_from_renamer.valid;
    end
  end


  // -----------------------------------------------------------------------
  // feedback, internal connect
  // -----------------------------------------------------------------------
  // フィードバックや各モジュール間の情報伝達

  // renamerやcacheへのリクエスト送信時に参照.
  privilege_level_e priv_rval;

  // renamer => predictor 
  is_taken_feedback_to_pred_t is_taken_feedback_to_pred[NUM_OF_GRADUATE];

  // renamer => btb
  misprediction_feedback_to_btb_t misprediction_feedback_to_btb;


  // LSU => Renamer, Int Issue Queue
  logic ld_speculative_feedback_valid;
  logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx;

  // Renamer => INt issue queue
  // csr,lwtが有効なld命令などをin_orderに発行するため.
  logic [AL_IDX_WIDTH-1:0] al_rp;

  // Renamer <=> CSR
  csr_renamer_if csr_renamer_port ();

  // Renamer <=> csru
  csru_renamer_if csru_renamer_port ();

  // Renamer <=> LSU
  Renamer_LSU_if renamer_lsu_port ();

  // Renamer <=> Priv
  priv_w_t priv_w;

  // 


  // CSRUnit <=> CSR
  csr_csru_if csr_csru_port ();


  // -----------------------------------------------------------
  // CLINT, PLIC
  // -----------------------------------------------------------

  // LSU <=> CSR
  csr_reg_u satp;

  // PLIC <=> CSR
  csr_plic_if csr_plic_port ();

  // CLINT <=> CSR
  csr_clint_if csr_clint_port ();

  // clint <=> LSU
  device_req_t req_to_clint;
  device_res_t res_from_clint;

  // plic <=> LSU
  device_req_t req_to_plic;
  device_res_t res_from_plic;

  // -----------------------------------------------------------
  // Cache, TLB, メインメモリ, bootloader
  // ------------------------------------------------------------
  // DCache
  cache_req64_t req_to_dcache[NUM_OF_REQ_TO_DCACHE];
  cache_res64_t res_from_dcache[NUM_OF_RES_FROM_DCACHE];

  // dcacheは,mmuのやり取りとlsuのやり取りに分解.
  // DCache <=> MMU
  cache_req64_t req_to_dcache_from_mmu;
  // 正直そんなにmmuのリクエストがdcacheから帰ってくる頻度は高くないので,res_to_lsu_from_dcacheに合わせる
  cache_res64_t res_to_mmu_from_dcache[NUM_OF_LD_EXE];

  // DCache <=> LSU
  cache_req64_t req_to_dcache_from_lsu[NUM_OF_LD_EXE+NUM_OF_ST_EXE];
  cache_res64_t res_to_lsu_from_dcache[NUM_OF_LD_EXE];
  logic stall_out_from_dcache;

  always_comb begin
    // sub_idが0ならlsuからのreq, sub_idが1ならmmuからのreq

    // req_to_dcache_from_mmu, req_to_dcache_from_lsu => req_to_dcache
    for (int unsigned i = 0; i < NUM_OF_LD_EXE + NUM_OF_ST_EXE; i++) begin
      req_to_dcache[i] = req_to_dcache_from_lsu[i];
      req_to_dcache[i].id_sub = 0;
    end
    // pwが今は一つだけなので
    // req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE] = req_to_dcache_from_mmu;
    for (int unsigned i = 0; i < NUM_OF_PW; i++) begin
      req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE+i] = req_to_dcache_from_mmu;
      req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE+i].id_sub = 1;
    end

    // res_from_dcache => res_to_lsu_from_dcache, res_to_mmu_from_dcache
    res_to_lsu_from_dcache = '{default: 0};
    res_to_mmu_from_dcache = '{default: 0};
    begin
      automatic int unsigned res_to_lsu_counter = 0;
      automatic int unsigned res_to_mmu_counter = 0;
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        if (res_from_dcache[i].valid) begin
          case (res_from_dcache[i].id_sub)
            0: begin
              res_to_lsu_from_dcache[res_to_lsu_counter] = res_from_dcache[i];
              res_to_lsu_counter++;
            end
            1: begin
              res_to_mmu_from_dcache[res_to_mmu_counter] = res_from_dcache[i];
              res_to_mmu_counter++;
            end
            default: ;
          endcase
        end
      end
    end
  end



  // ICache
  cache_req128_t req_to_icache[NUM_OF_REQ_TO_ICACHE];
  cache_res128_t res_from_icache[NUM_OF_RES_FROM_ICACHE];
  logic stall_out_from_icache;

  // Boot loader
  bootloader_req_t req_to_bootloader;
  bootloader_res_t res_from_bootloader;


  // TLB
  dtlb_if #(
      .NUM_OF_REQ(NUM_OF_REQ_TO_DTLB),
      .NUM_OF_RES(NUM_OF_RES_FROM_DTLB)
  ) dtlb_port ();

  // NUM_OF_REQ_TO_ITLBが1でなく2になる理由がわからん.
  itlb_if #(
      .NUM_OF_REQ(NUM_OF_REQ_TO_ITLB),
      .NUM_OF_RES(NUM_OF_RES_FROM_ITLB)
  ) itlb_port ();

  // icache <=> メインメモリ
  mm_icache_if #(
      .NUM_OF_REQS(NUM_OF_REQ_FROM_ICACHE_TO_MM),
      .NUM_OF_RES (NUM_OF_RES_FROM_MM_TO_ICACHE)
  ) mm_icache_port ();

  // dcache <=> メインメモリ
  mm_dcache_if #(
      .NUM_OF_REQS(NUM_OF_REQ_FROM_DCACHE_TO_MM),
      .NUM_OF_RES (NUM_OF_RES_FROM_MM_TO_DCACHE)
  ) mm_dcache_port ();

  BootLoader bl (
      .clock  (cpu_clock),
      .reset  (cpu_reset),
      .req_in (req_to_bootloader),
      .res_out(res_from_bootloader)
  );

  // ----------------------------------------------------------------------
  // stall
  // ----------------------------------------------------------------------


  // st2
  logic stall_out_from_pcbypass;
  logic stall_from_st2_to_st1;
  assign stall_from_st2_to_st1 = stall_out_from_pcbypass || stall_out_from_icache;
  // st3
  logic stall_from_st3_to_st2;
  logic stall_from_st4_to_st3;
  logic stall_from_st5_to_st4;
  logic stall_from_st6_to_st5;
  // stage8でari,ldst,csrのunitに分かれるが,ari,csrは詰まることが無いのでstallしなくていい.
  logic stall_from_st7_to_st6_ldst;
  logic stall_from_st7_to_st6_csr;
  logic stall_from_st7_to_st6_div;

  logic stall_from_st8_to_st7_ldst;
  logic stall_from_st8_to_st7_div;
  assign stall_from_st8_to_st7_ldst = 0;

  logic stall_from_st8_to_st7_csr;

  logic stall_append_to_al;

  // 実機ではuartの周波数はcpuのサイクルより小さいので,tx用のfifoが満タンになる可能性がある.
  // よって,fifoが満タンなら,renamerでst命令のコミットを抑制する必要がある.
  logic tx_fifo_full;


  // uartでの出力を抑制する.
  logic stall_from_uart_debug;

`ifdef PRINT_IPC

  // -------------------------------------------------------------------=
  // stallしている時間の割合(Debug)
  // -------------------------------------------------------------------=
  csr_reg_u mcycle;
  csr_reg_u minstret;

  // 各stage自身が生成したstall
  logic stall_out_from_pcbypass_local;
  logic stall_out_from_icache_local;
  logic stall_from_st2_to_st1_local;
  logic stall_from_st3_to_st2_local;
  logic stall_from_st4_to_st3_local;
  logic stall_from_st5_to_st4_local;
  logic stall_from_st6_to_st5_local;
  logic stall_from_st7_to_st6_ldst_local;
  logic stall_from_st7_to_st6_csr_local;
  logic stall_from_st7_to_st6_div_local;
  logic stall_from_st8_to_st7_ldst_local;
  logic stall_from_st8_to_st7_div_local;
  logic stall_from_st8_to_st7_csr_local;
  logic stall_append_to_al_local;
  logic stall_out_from_dcache_local;


  always_comb begin
    stall_out_from_pcbypass_local = stall_out_from_pcbypass && !stall_from_st3_to_st2;
    stall_out_from_icache_local = stall_out_from_icache && !stall_from_st3_to_st2;

    stall_from_st2_to_st1_local =
        (stall_out_from_pcbypass || stall_out_from_icache) && !stall_from_st3_to_st2;

    stall_from_st3_to_st2_local = stall_from_st3_to_st2 && !stall_from_st4_to_st3;

    stall_from_st4_to_st3_local =
        stall_from_st4_to_st3 && !(stall_from_st5_to_st4 || stall_append_to_al);

    stall_from_st5_to_st4_local =
        stall_from_st5_to_st4 && !(stall_from_st6_to_st5 || stall_append_to_al);

    stall_from_st6_to_st5_local =
        stall_from_st6_to_st5 &&
        !(stall_from_st7_to_st6_ldst ||
          stall_from_st7_to_st6_csr  ||
          stall_from_st7_to_st6_div);

    stall_from_st7_to_st6_ldst_local = stall_from_st7_to_st6_ldst && !stall_from_st8_to_st7_ldst;

    stall_from_st7_to_st6_csr_local = stall_from_st7_to_st6_csr && !stall_from_st8_to_st7_csr;

    stall_from_st7_to_st6_div_local = stall_from_st7_to_st6_div && !stall_from_st8_to_st7_div;

    stall_from_st8_to_st7_ldst_local = stall_from_st8_to_st7_ldst;
    stall_from_st8_to_st7_div_local = stall_from_st8_to_st7_div;
    stall_from_st8_to_st7_csr_local = stall_from_st8_to_st7_csr;

    stall_append_to_al_local = stall_append_to_al;

    stall_out_from_dcache_local = stall_out_from_dcache;
    stall_out_from_icache_local = stall_out_from_icache;
  end

  logic [XLEN-1:0] stall_out_from_pcbypass_local_counter;
  logic [XLEN-1:0] stall_out_from_icache_local_counter;
  logic [XLEN-1:0] stall_from_st2_to_st1_local_counter;
  logic [XLEN-1:0] stall_from_st3_to_st2_local_counter;
  logic [XLEN-1:0] stall_from_st4_to_st3_local_counter;
  logic [XLEN-1:0] stall_from_st5_to_st4_local_counter;
  logic [XLEN-1:0] stall_from_st6_to_st5_local_counter;
  logic [XLEN-1:0] stall_from_st7_to_st6_ldst_local_counter;
  logic [XLEN-1:0] stall_from_st7_to_st6_csr_local_counter;
  logic [XLEN-1:0] stall_from_st7_to_st6_div_local_counter;
  logic [XLEN-1:0] stall_from_st8_to_st7_ldst_local_counter;
  logic [XLEN-1:0] stall_from_st8_to_st7_div_local_counter;
  logic [XLEN-1:0] stall_from_st8_to_st7_csr_local_counter;
  logic [XLEN-1:0] stall_append_to_al_local_counter;
  logic [XLEN-1:0] stall_out_from_dcache_local_counter;

  task automatic display_ratio_real(input string name, input logic [XLEN-1:0] counter);
    real ratio;
    begin
      if (mcycle != 0) begin
        ratio = $itor(counter) / $itor(mcycle);
      end else begin
        ratio = 0.0;
      end

      $display("  %-32s count=%0d ratio=%0f", name, counter, ratio);
    end
  endtask

  real ipc_real;

  always_comb begin
    if (mcycle != 0) begin
      ipc_real = $itor(minstret) / $itor(mcycle);
    end else begin
      ipc_real = 0.0;
    end
  end

  always_ff @(posedge cpu_clock) begin
    if (cpu_reset) begin
      stall_out_from_pcbypass_local_counter    <= '0;
      stall_out_from_icache_local_counter      <= '0;
      stall_from_st2_to_st1_local_counter      <= '0;
      stall_from_st3_to_st2_local_counter      <= '0;
      stall_from_st4_to_st3_local_counter      <= '0;
      stall_from_st5_to_st4_local_counter      <= '0;
      stall_from_st6_to_st5_local_counter      <= '0;
      stall_from_st7_to_st6_ldst_local_counter <= '0;
      stall_from_st7_to_st6_csr_local_counter  <= '0;
      stall_from_st7_to_st6_div_local_counter  <= '0;
      stall_from_st8_to_st7_ldst_local_counter <= '0;
      stall_from_st8_to_st7_div_local_counter  <= '0;
      stall_from_st8_to_st7_csr_local_counter  <= '0;
      stall_append_to_al_local_counter         <= '0;
      stall_out_from_dcache_local_counter      <= '0;

    end else begin
      stall_out_from_pcbypass_local_counter <=
          stall_out_from_pcbypass_local_counter + XLEN'(stall_out_from_pcbypass_local);

      stall_out_from_icache_local_counter <=
          stall_out_from_icache_local_counter + XLEN'(stall_out_from_icache_local);

      stall_from_st2_to_st1_local_counter <=
          stall_from_st2_to_st1_local_counter + XLEN'(stall_from_st2_to_st1_local);

      stall_from_st3_to_st2_local_counter <=
          stall_from_st3_to_st2_local_counter + XLEN'(stall_from_st3_to_st2_local);

      stall_from_st4_to_st3_local_counter <=
          stall_from_st4_to_st3_local_counter + XLEN'(stall_from_st4_to_st3_local);

      stall_from_st5_to_st4_local_counter <=
          stall_from_st5_to_st4_local_counter + XLEN'(stall_from_st5_to_st4_local);

      stall_from_st6_to_st5_local_counter <=
          stall_from_st6_to_st5_local_counter + XLEN'(stall_from_st6_to_st5_local);

      stall_from_st7_to_st6_ldst_local_counter <=
          stall_from_st7_to_st6_ldst_local_counter + XLEN'(stall_from_st7_to_st6_ldst_local);

      stall_from_st7_to_st6_csr_local_counter <=
          stall_from_st7_to_st6_csr_local_counter + XLEN'(stall_from_st7_to_st6_csr_local);

      stall_from_st7_to_st6_div_local_counter <=
          stall_from_st7_to_st6_div_local_counter + XLEN'(stall_from_st7_to_st6_div_local);

      stall_from_st8_to_st7_ldst_local_counter <=
          stall_from_st8_to_st7_ldst_local_counter + XLEN'(stall_from_st8_to_st7_ldst_local);

      stall_from_st8_to_st7_div_local_counter <=
          stall_from_st8_to_st7_div_local_counter + XLEN'(stall_from_st8_to_st7_div_local);

      stall_from_st8_to_st7_csr_local_counter <=
          stall_from_st8_to_st7_csr_local_counter + XLEN'(stall_from_st8_to_st7_csr_local);

      stall_append_to_al_local_counter <=
          stall_append_to_al_local_counter + XLEN'(stall_append_to_al_local);

      stall_out_from_dcache_local_counter <=
          stall_out_from_dcache_local_counter + XLEN'(stall_out_from_dcache_local);


      if ((mcycle != 0) && ((mcycle % 64'd1000_0000) == 0)) begin
        $display("============================================================");
        $display("[LOCAL_STALL_COUNTER] mcycle=%0d minstret=%0d ipc=%0f", mcycle, minstret,
                 ipc_real);
        $display("------------------------------------------------------------");

        display_ratio_real("st2_pcbypass_local", stall_out_from_pcbypass_local_counter);
        display_ratio_real("st2_icache_local", stall_out_from_icache_local_counter);
        display_ratio_real("st2_to_st1_local", stall_from_st2_to_st1_local_counter);
        display_ratio_real("st3_to_st2_local", stall_from_st3_to_st2_local_counter);
        display_ratio_real("st4_to_st3_local", stall_from_st4_to_st3_local_counter);
        display_ratio_real("st5_to_st4_local", stall_from_st5_to_st4_local_counter);
        display_ratio_real("st6_to_st5_local", stall_from_st6_to_st5_local_counter);
        display_ratio_real("st7_to_st6_ldst_local", stall_from_st7_to_st6_ldst_local_counter);
        display_ratio_real("st7_to_st6_csr_local", stall_from_st7_to_st6_csr_local_counter);
        display_ratio_real("st7_to_st6_div_local", stall_from_st7_to_st6_div_local_counter);
        display_ratio_real("st8_to_st7_ldst_local", stall_from_st8_to_st7_ldst_local_counter);
        display_ratio_real("st8_to_st7_div_local", stall_from_st8_to_st7_div_local_counter);
        display_ratio_real("st8_to_st7_csr_local", stall_from_st8_to_st7_csr_local_counter);
        display_ratio_real("append_to_al_local", stall_append_to_al_local_counter);
        display_ratio_real("dcache_local", stall_out_from_dcache_local_counter);
        display_ratio_real("dcache_local", stall_out_from_icache_local_counter);

        $display("============================================================");
      end
    end
  end

`endif
  // ----------------------------------------------------------------------
  // flush
  // ----------------------------------------------------------------------
  // flush命令の発生元.
  addr_with_valid_t flush_from_ifq;
  addr_with_valid_t flush_from_decoder;
  addr_with_valid_t flush_from_renamer;

  // 各モジュールのflush_inに上のをつなげる.
  // => st1
  addr_with_valid_t flush_to_pcgen;
  always_comb begin
    // 古いpcに対するflushのほうが優先される.
    flush_to_pcgen = '{default: 0};
    if (flush_from_ifq.valid) begin
      flush_to_pcgen = flush_from_ifq;
    end
    if (flush_from_decoder.valid) begin
      flush_to_pcgen = flush_from_decoder;
    end
    if (flush_from_renamer.valid) begin
      flush_to_pcgen = flush_from_renamer;
    end
  end
  // => st2
  logic flush_to_st2;
  assign flush_to_st2 = flush_from_ifq.valid || flush_from_decoder.valid || flush_from_renamer.valid;
  // => st3
  logic flush_to_st3;
  assign flush_to_st3 = flush_from_decoder.valid || flush_from_renamer.valid;
  // => st4
  logic flush_to_st4;
  assign flush_to_st4 = flush_from_renamer.valid;
  // => st6
  logic flush_to_st6;
  assign flush_to_st6 = flush_from_renamer.valid;
  // => st7
  logic flush_to_st7;
  assign flush_to_st7 = flush_from_renamer.valid;
  // => st8
  logic flush_to_st8;
  assign flush_to_st8 = flush_from_renamer.valid;
  // => st9
  logic flush_to_st9;
  assign flush_to_st9 = flush_from_renamer.valid;

  // renamer => tlb
  // sfence.vma用.
  logic flush_tlb;

  // cacheに入ってしまったread_reqはflushできないので,
  // flush後にflush前に出したread_reqを受け取ってしまわないように
  // flush時にrenamerでgenerationをカウントアップ.
  int unsigned generation;

  // fence_iのための信号.

  logic fence_i_exe;
  logic fence_i_done;
  logic fence_i_done_next;

  logic invalidate_icache;
  logic invalidate_icache_done_sig;
  //  logic invalidate_icache_done_next;

  logic invalidate_dcache;
  logic invalidate_dcache_done_sig;
  //  logic invalidate_dcache_done_next;

  logic invalidate_l2cache;
  logic invalidate_l2cache_done;
  logic invalidate_l2cache_done_next;



  // -----------------------------------------------------------------------
  // Stage1
  // -----------------------------------------------------------------------
  pcgen pcgen (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .pc_out(pc_from_st1_to_st2),
      .flush_in(flush_to_pcgen),
      .stall_in(stall_from_st2_to_st1)
  );



  // ------------------------------------------------------------------------
  // Stage2 
  // ------------------------------------------------------------------------

  // Icacheの入力を調整.
  logic data_print_en_ira_fake;
  logic [255:0] data_print_ira_fake;
  Icache_req_arbiter irb (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .pc_in_cur(pc_from_st1_to_st2),
      .req_to_icache(req_to_icache),
      .req_to_bootloader(req_to_bootloader),
      .generation(generation),
      .priv_rval(priv_rval),
      .satp(satp),
      .stall_in(stall_from_st3_to_st2),
      .data_print_en(data_print_en_ira_fake),
      .data_print(data_print_ira_fake)
  );


  // predictor,btb,pcbypassは常に同じpcに対して動作しているので,stall_outはpcbypassにまとめる.
  // 同様にして,pcgenから来たpcがvalidかもpcbypassが判断する.
  Predictor predictor (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .pc_in_cur(pc_from_st1_to_st2),
      .pred_taken(pred_taken),
      .feedback(is_taken_feedback_to_pred),
      .stall_in(stall_from_st3_to_st2),
      .flush_in(flush_to_st2)
  );

  BTB btb (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .pc_in_cur(pc_from_st1_to_st2),
      .hit(btb_hit_valid),
      .addr_out(btb_hit_addr),
      .feedback(misprediction_feedback_to_btb),
      .stall_in(stall_from_st3_to_st2),
      .flush_in(flush_to_st2)
  );

  PCBypass pcbypass (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .pc_in_cur(pc_from_st1_to_st2),
      .pc_out(pc_from_st2_to_st3),
      .stall_in(stall_from_st3_to_st2),
      .stall_out(stall_out_from_pcbypass),
      .flush_in(flush_to_st2)
  );


  // -------------------------------------------------------------------------
  // Stage3 
  // ------------------------------------------------------------------------
  IFQ ifqueue (
      .clock(cpu_clock),
      .reset(cpu_reset),

      // 予測子とかからの入力
      .pc_in(pc_from_st2_to_st3),
      .pred_taken(pred_taken),
      .btb_hit(btb_hit_valid),
      .btb_addr(btb_hit_addr),

      // icacheからの入力.
      .icache_result(res_from_icache),

      .ifq_out(raw_op),
      .stall_in(stall_from_st4_to_st3),
      .stall_out(stall_from_st3_to_st2),
      .flush_in(flush_to_st3),
      .flush_out(flush_from_ifq),
      .generation(generation)
  );

  // --------------------------------------------------------------------------
  // Stage4
  // --------------------------------------------------------------------------
  Decoder decoder (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .fetched_content_cur(raw_op),
      .decoded_op(decoded_op),
      .mispred_mod(flush_from_decoder),
      .stall_in(stall_from_st5_to_st4 || stall_append_to_al),
      .stall_out(stall_from_st4_to_st3),
      .flush_in(flush_to_st4)
  );

  logic stall_append_to_al_prev;
  logic stall_from_st5_to_st4_prev;
  decoded_op_t decoded_op_prev[NUM_OF_FETCH];
  always_ff @(posedge cpu_clock) begin
    if (cpu_reset) begin
      stall_append_to_al_prev <= 0;
      stall_from_st5_to_st4_prev <= 0;
      decoded_op_prev <= '{default: 0};
    end else begin

      stall_append_to_al_prev <= stall_append_to_al;
      stall_from_st5_to_st4_prev <= stall_from_st5_to_st4;
      decoded_op_prev <= decoded_op;

    end
  end

  // --------------------------------------------------------------------------
  // Stage5
  // --------------------------------------------------------------------------
  Renamer renamer (

      .clock      (cpu_clock),
      .reset      (cpu_reset),
      .op_in_cur  (decoded_op),
      .op_out     (renamed_op),
      .feedback_op(result_op2),

      // 
      .dcache_noroom                (stall_out_from_dcache),
      // pred,btb
      .misprediction_feedback_to_btb(misprediction_feedback_to_btb),
      .is_taken_feedback_to_pred    (is_taken_feedback_to_pred),

      // 特権モードの読み書き
      .priv_rval(priv_rval),
      .priv_w   (priv_w),

      .al_rp_out(al_rp),

      .flush_tlb(flush_tlb),

      // LSUとの接続.
      .lsu_port(renamer_lsu_port),

      // csruとの接続
      .csru_port(csru_renamer_port),

      // CSRとの接続
      .csr_port(csr_renamer_port),

      .flush_from_renamer(flush_from_renamer),
      .stall_in(stall_from_st6_to_st5 || stall_append_to_al),
      .stall_out(stall_from_st5_to_st4),
      .tx_fifo_full(tx_fifo_full),

`ifdef VIVADO_COMPILE
      .led1(led1),
      .led2(led2),
`endif

      .generation(generation),
      .invalidate_l1cache(fence_i_exe),
      .invalidate_l1cache_done(fence_i_done)
  );

  // --------------------------------------------------------------------------
  // Stage6
  // --------------------------------------------------------------------------
  IntIssueQueue intissuequeue (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .op_in(renamed_op),
      .feedback(result_feedback_rd),
      .ld_speculative_feedback_valid(ld_speculative_feedback_valid),
      .ld_speculative_feedback_al_idx(ld_speculative_feedback_al_idx),
      .op_out_ari(issued_op_ari),
      .op_out_div(issued_op_div),
      .op_out_ld(issued_op_ld),
      .op_out_st_amo(issued_op_st_amo),
      .op_out_csr(issued_op_csr),
      .al_rp(al_rp),
      .flush_in(flush_to_st6),
      .stall_out(stall_from_st6_to_st5),
      .stall_in_from_ldst(stall_from_st7_to_st6_ldst),
      .stall_in_from_csr(stall_from_st7_to_st6_csr),
      .stall_in_from_div(stall_from_st7_to_st6_div),

      // FORDEBUG
      .generation(generation)
  );

  // --------------------------------------------------------------------------
  // Stage7
  // --------------------------------------------------------------------------
  INTPRF intprf (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .op_in_ari(issued_op_ari),
      .op_in_div_cur(issued_op_div),
      .op_in_ld_cur(issued_op_ld),
      .op_in_st_amo_cur(issued_op_st_amo),
      .op_in_csr_cur(issued_op_csr),
      .op_out_ari(op_rs_ready_ari),
      .op_out_div(op_rs_ready_div),
      .op_out_ld(op_rs_ready_ld),
      .op_out_st_amo(op_rs_ready_st_amo),
      .op_out_csr(op_rs_ready_csr),
      .op_feedback(result_op2),
      .stall_in_from_ldst(stall_from_st8_to_st7_ldst),
      .stall_in_from_csr(stall_from_st8_to_st7_csr),
      .stall_in_from_div(stall_from_st8_to_st7_div),
      .stall_out_ldst(stall_from_st7_to_st6_ldst),
      .stall_out_csr(stall_from_st7_to_st6_csr),
      .stall_out_div(stall_from_st7_to_st6_div),
      .flush_in(flush_to_st7)
  );

  // --------------------------------------------------------------------------
  // Stage8
  // --------------------------------------------------------------------------
  ArithmeticUnit au (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .op_in_ari(op_rs_ready_ari),
      .op_out_ari(result_op_ari),
      .op_in_div(op_rs_ready_div),
      .op_out_div(result_op_div),
      .flush_in(flush_to_st8),
      .stall_out_div(stall_from_st8_to_st7_div)
  );

  LSU lsu (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .op_ld_in(op_rs_ready_ld),
      .op_st_amo_in(op_rs_ready_st_amo),
      .op_ld_out(result_op_ld),
      .op_st_out(result_op_st),

      // .op_mmio_out(result_op_mmio),

      // alとの接続.
      .renamer_port(renamer_lsu_port),

      // Int Issue Queueとの接続
      .ld_speculative_feedback_valid (ld_speculative_feedback_valid),
      .ld_speculative_feedback_al_idx(ld_speculative_feedback_al_idx),

      // DTLB
      .tlb_port(dtlb_port),

      // DCache
      .req_to_dcache  (req_to_dcache_from_lsu),
      .res_from_dcache(res_to_lsu_from_dcache),
      .dcache_noroom  (stall_out_from_dcache),

      // clint
      .req_to_clint  (req_to_clint),
      .res_from_clint(res_from_clint),

      // plic
      .req_to_plic  (req_to_plic),
      .res_from_plic(res_from_plic),

      // CSR
      .satp(satp),

      // priv
      .priv_rval(priv_rval),

      //.stall_out(stall_from_st8_to_st7_ldst),
      .flush_in(flush_to_st8),

      .generation(generation),

      .stall_append_to_al(stall_append_to_al)

  );

  CSRUnit csru (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .op_in(op_rs_ready_csr),
      .op_out(result_op_csr),
      .renamer_port(csru_renamer_port),
      .flush_in(flush_to_st8),
      .csr_port(csr_csru_port),
      .stall_out(stall_from_st8_to_st7_csr)
  );



  // result_op_ari, result_op_ld, result_op_csr
  // => result_op
  always_comb begin
    result_op = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_ARI_EXE; i++) begin
      result_op[i] = result_op_ari[i];
    end
    for (int unsigned i = 0; i < NUM_OF_DIV_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+i] = result_op_div[i];
    end
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_DIV_EXE+i] = result_op_ld[i];
    end
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_DIV_EXE+NUM_OF_LD_EXE+i] = result_op_st[i];
    end
    for (int unsigned i = 0; i < NUM_OF_CSR_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_DIV_EXE+NUM_OF_LD_EXE+NUM_OF_ST_EXE+i] = result_op_csr[i];
    end
  end

  // -------------------------------------------------------------------------
  // Stage9
  // ------------------------------------------------------------------------
  // Decoder -> decoded_op -> Renamer -> (Renamer_LSU_if.new_instr) -> LSU -> Top.result_op(_ld) -> Top.result_op -> (Renamer) -> flush → IFQ/Decoder …
  // のループを断ち切るために,result_op2 <= result_op をalways_ffで更新する.
  always_ff @(posedge cpu_clock) begin
    if (cpu_reset) begin
      result_op2 <= '{default: '0};
    end else if (flush_to_st9) begin
      result_op2 <= '{default: '0};
    end else begin
      result_op2 <= result_op;
    end
  end

  // result_op2 => feedback_rd
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
      if (result_op2[i].valid && result_op2[i].rd_exist) begin
        result_feedback_rd[i] = '{valid: 1, rd: result_op2[i].rd};
      end else begin
        result_feedback_rd[i] = '{default: 0};
      end
    end
  end

  // --------------------------------------------------------------------------
  // MMU
  // --------------------------------------------------------------------------
  MMU mmu (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .itlb_port(itlb_port),
      .dtlb_port(dtlb_port),
      .req_to_dcache(req_to_dcache_from_mmu),
      .res_from_dcache_tmp(res_to_mmu_from_dcache),
      .dcache_noroom(stall_out_from_dcache),
      .generation(generation),
      .flush_tlb(flush_tlb)
  );

  // --------------------------------------------------------------------------
  // Cache
  // --------------------------------------------------------------------------
  logic data_print_en_cache_subsystem_fake;
  logic [255:0] data_print_cache_subsystem_fake;
  CacheSubsystem cachesubsystem (
      .clock(cpu_clock),
      .reset(cpu_reset),

      .req_to_icache  (req_to_icache),
      .res_from_icache(res_from_icache),
      .req_to_dcache  (req_to_dcache),
      .res_from_dcache(res_from_dcache),

      .itlb_port(itlb_port),

      .mm_icache_port(mm_icache_port),
      .mm_dcache_port(mm_dcache_port),

      .stall_req_to_icache(stall_out_from_icache),
      .stall_req_to_dcache(stall_out_from_dcache),

      .invalidate_icache(invalidate_icache),
      .invalidate_icache_done(invalidate_icache_done_sig),
      .invalidate_dcache(invalidate_dcache),
      .invalidate_dcache_done(invalidate_dcache_done_sig),
      .invalidate_l2cache(invalidate_l2cache),
      .invalidate_l2cache_done(invalidate_l2cache_done_next),

      .data_print_en(data_print_en_cache_subsystem_fake),
      .data_print(data_print_cache_subsystem_fake)
  );


  // --------------------------------------------------------------------------
  // CSRレジスタ
  // --------------------------------------------------------------------------
  CSRRF csrrf (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .renamer_port(csr_renamer_port),
      .csru_port(csr_csru_port),
      .satp_out(satp),
      .plic_port(csr_plic_port),
      .clint_port(csr_clint_port),
      .mcycle(mcycle),
      .minstret(minstret)
  );

  // -------------------------------------------------------------------------
  // PLIC, CLINT
  // --------------------------------------------------------------------------
  PLIC plic (
      .clock  (cpu_clock),
      .reset  (cpu_reset),
      .req_in (req_to_plic),
      .res_out(res_from_plic),
`ifdef VIVADO_COMPILE


      .data_print_en(data_print_en),
      .data_print(data_print),

      .char_from_uart_valid(char_from_uart_valid),
      .char_from_uart(char_from_uart),
      .stall_uart_print(stall_from_uart_debug),
`endif
      .csr_port(csr_plic_port),
      .tx_fifo_full(tx_fifo_full)
  );

  CLINT clint (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .csr_port(csr_clint_port)
  );


  // --------------------------------------------------------------------------
  // priv
  // --------------------------------------------------------------------------
  Priv priv (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .priv_rval(priv_rval),
      .priv_w(priv_w)
  );

  // ----------------------------------------------------------------------------
  // メインメモリ
  // -----------------------------------------------------------------------------
  // 動かすのがverilatorの場合はMainMemory.svを使用するが,fpgaで動かすならmigを用いてddr3を使用するため.
  logic dump_mm;

`ifdef VERILATOR_COMPILE
  MainMemory mm (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .icache_port(mm_icache_port),
      .dcache_port(mm_dcache_port),
      .dump_mm(dump_mm)
  );
`endif




  // fpga用のメモリとの通信
  // kv260ではps側のaxi_portに接続してddr3を用いる.
`ifdef VIVADO_COMPILE

  assign led0 = 1;

  // ------------------------------------------------------------------------------------------------------------------------------------
  // メモリ調停とキャッシュの接続.
  // ------------------------------------------------------------------------------------------------------------------------------------

  mm_req128_t req_from_icache_to_mm[NUM_OF_REQ_FROM_ICACHE_TO_MM];
  mm_res128_t res_from_mm_to_icache[NUM_OF_RES_FROM_MM_TO_ICACHE];
  mm_req64_t req_from_dcache_to_mm[NUM_OF_REQ_FROM_DCACHE_TO_MM];
  mm_res64_t res_from_mm_to_dcache[NUM_OF_RES_FROM_MM_TO_DCACHE];
  logic ready_from_mm_to_icache;
  logic ready_from_mm_to_dcache;
  always_comb begin
    // icacheとmmの接続.
    mm_icache_port.req = req_from_icache_to_mm;
    mm_icache_port.ready = ready_from_mm_to_icache;
    res_from_mm_to_icache = mm_icache_port.res;

    // dcacheとmmの接続.
    mm_dcache_port.req = req_from_dcache_to_mm;
    mm_dcache_port.ready = ready_from_mm_to_dcache;
    res_from_mm_to_dcache = mm_dcache_port.res;
  end

  // ------------------------------------------------------------------------------------------------------------------------------------
  // メモリ調停とdramの接続
  // ------------------------------------------------------------------------------------------------------------------------------------
  axi_req128_t req_from_icache_to_dram;
  axi_res128_t res_from_dram_to_icache;
  axi_req64_t req_from_dcache_to_dram;
  axi_res64_t res_from_dram_to_dcache;
  always_comb begin
    // ---------------------------------------------------------------------------------------
    // icacheのメモリ調停と,dramの接続
    // ---------------------------------------------------------------------------------------
    // Write address channel: ICache -> DRAM
    axi_icache_port_awuser  = req_from_icache_to_dram.awuser;
    axi_icache_port_awid    = req_from_icache_to_dram.awid;
    axi_icache_port_awaddr  = req_from_icache_to_dram.awaddr;
    axi_icache_port_awlen   = req_from_icache_to_dram.awlen;
    axi_icache_port_awsize  = req_from_icache_to_dram.awsize;
    axi_icache_port_awburst = req_from_icache_to_dram.awburst;
    axi_icache_port_awlock  = req_from_icache_to_dram.awlock;
    axi_icache_port_awcache = req_from_icache_to_dram.awcache;
    axi_icache_port_awprot  = req_from_icache_to_dram.awprot;
    axi_icache_port_awqos   = req_from_icache_to_dram.awqos;
    axi_icache_port_awvalid = req_from_icache_to_dram.awvalid;

    // Write address ready: DRAM -> ICache
    res_from_dram_to_icache.awready = axi_icache_port_awready;

    // Write data channel: ICache -> DRAM
    axi_icache_port_wdata  = req_from_icache_to_dram.wdata;
    axi_icache_port_wstrb  = req_from_icache_to_dram.wstrb;
    axi_icache_port_wlast  = req_from_icache_to_dram.wlast;
    axi_icache_port_wvalid = req_from_icache_to_dram.wvalid;

    // Write data ready: DRAM -> ICache
    res_from_dram_to_icache.wready = axi_icache_port_wready;

    // Write response channel
    res_from_dram_to_icache.bid    = axi_icache_port_bid;
    res_from_dram_to_icache.bresp  = axi_icache_port_bresp;
    res_from_dram_to_icache.bvalid = axi_icache_port_bvalid;

    // ICache -> DRAM
    axi_icache_port_bready = req_from_icache_to_dram.bready;

    // Read address channel: ICache -> DRAM
    axi_icache_port_aruser  = req_from_icache_to_dram.aruser;
    axi_icache_port_arid    = req_from_icache_to_dram.arid;
    axi_icache_port_araddr  = req_from_icache_to_dram.araddr;
    axi_icache_port_arlen   = req_from_icache_to_dram.arlen;
    axi_icache_port_arsize  = req_from_icache_to_dram.arsize;
    axi_icache_port_arburst = req_from_icache_to_dram.arburst;
    axi_icache_port_arlock  = req_from_icache_to_dram.arlock;
    axi_icache_port_arcache = req_from_icache_to_dram.arcache;
    axi_icache_port_arprot  = req_from_icache_to_dram.arprot;
    axi_icache_port_arqos   = req_from_icache_to_dram.arqos;
    axi_icache_port_arvalid = req_from_icache_to_dram.arvalid;

    // Read address ready: DRAM -> ICache
    res_from_dram_to_icache.arready = axi_icache_port_arready;

    // Read data channel: DRAM -> ICache
    res_from_dram_to_icache.rid    = axi_icache_port_rid;
    res_from_dram_to_icache.rdata  = axi_icache_port_rdata;
    res_from_dram_to_icache.rresp  = axi_icache_port_rresp;
    res_from_dram_to_icache.rlast  = axi_icache_port_rlast;
    res_from_dram_to_icache.rvalid = axi_icache_port_rvalid;

    // ICache -> DRAM
    axi_icache_port_rready = req_from_icache_to_dram.rready;

    // ------------------------------------------------------------------------------------------------
    // dcacheのメモリ調停と,dramの接続
    // ------------------------------------------------------------------------------------------------
    // Write address channel: DCache -> DRAM
    axi_dcache_port_awuser  = req_from_dcache_to_dram.awuser;
    axi_dcache_port_awid    = req_from_dcache_to_dram.awid;
    axi_dcache_port_awaddr  = req_from_dcache_to_dram.awaddr;
    axi_dcache_port_awlen   = req_from_dcache_to_dram.awlen;
    axi_dcache_port_awsize  = req_from_dcache_to_dram.awsize;
    axi_dcache_port_awburst = req_from_dcache_to_dram.awburst;
    axi_dcache_port_awlock  = req_from_dcache_to_dram.awlock;
    axi_dcache_port_awcache = req_from_dcache_to_dram.awcache;
    axi_dcache_port_awprot  = req_from_dcache_to_dram.awprot;
    axi_dcache_port_awqos   = req_from_dcache_to_dram.awqos;
    axi_dcache_port_awvalid = req_from_dcache_to_dram.awvalid;

    // DRAM -> DCache
    res_from_dram_to_dcache.awready = axi_dcache_port_awready;

    // Write data channel: DCache -> DRAM
    axi_dcache_port_wdata  = req_from_dcache_to_dram.wdata;
    axi_dcache_port_wstrb  = req_from_dcache_to_dram.wstrb;
    axi_dcache_port_wlast  = req_from_dcache_to_dram.wlast;
    axi_dcache_port_wvalid = req_from_dcache_to_dram.wvalid;

    // DRAM -> DCache
    res_from_dram_to_dcache.wready = axi_dcache_port_wready;

    // Write response channel
    res_from_dram_to_dcache.bid    = axi_dcache_port_bid;
    res_from_dram_to_dcache.bresp  = axi_dcache_port_bresp;
    res_from_dram_to_dcache.bvalid = axi_dcache_port_bvalid;

    // DCache -> DRAM
    axi_dcache_port_bready = req_from_dcache_to_dram.bready;

    // Read address channel: DCache -> DRAM
    axi_dcache_port_aruser  = req_from_dcache_to_dram.aruser;
    axi_dcache_port_arid    = req_from_dcache_to_dram.arid;
    axi_dcache_port_araddr  = req_from_dcache_to_dram.araddr;
    axi_dcache_port_arlen   = req_from_dcache_to_dram.arlen;
    axi_dcache_port_arsize  = req_from_dcache_to_dram.arsize;
    axi_dcache_port_arburst = req_from_dcache_to_dram.arburst;
    axi_dcache_port_arlock  = req_from_dcache_to_dram.arlock;
    axi_dcache_port_arcache = req_from_dcache_to_dram.arcache;
    axi_dcache_port_arprot  = req_from_dcache_to_dram.arprot;
    axi_dcache_port_arqos   = req_from_dcache_to_dram.arqos;
    axi_dcache_port_arvalid = req_from_dcache_to_dram.arvalid;

    // DRAM -> DCache
    res_from_dram_to_dcache.arready = axi_dcache_port_arready;

    // Read data channel: DRAM -> DCache
    res_from_dram_to_dcache.rid    = axi_dcache_port_rid;
    res_from_dram_to_dcache.rdata  = axi_dcache_port_rdata;
    res_from_dram_to_dcache.rresp  = axi_dcache_port_rresp;
    res_from_dram_to_dcache.rlast  = axi_dcache_port_rlast;
    res_from_dram_to_dcache.rvalid = axi_dcache_port_rvalid;

    // DCache -> DRAM
    axi_dcache_port_rready = req_from_dcache_to_dram.rready;
  end

  uart_debug #(
      .BUF_SIZE(DEBUG_BUF_SIZE)
  ) ud (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .cts(cts),
      .rts(rts),
      .rxd(rxd),
      .txd(txd),
      .data_in_en(data_print_en),
      .data_in(data_print),
      .char_from_uart_valid(char_from_uart_valid),
      .char_from_uart(char_from_uart),
      .stall_out(stall_from_uart_debug)
  );
  // iacacheとdramとの接続
  AXI_memory_arbiter_buf #(
      .CACHE_BUF_SIZE(8),
      .mm_req_t(mm_req128_t),
      .mm_res_t(mm_res128_t),
      .axi_req_t(axi_req128_t),
      .axi_res_t(axi_res128_t),
      .DATA_SIZE(16),
      .NUM_OF_REQ_FROM_CACHE(NUM_OF_REQ_FROM_ICACHE_TO_MM),
      .NUM_OF_RES_TO_CACHE(NUM_OF_RES_FROM_MM_TO_ICACHE),
      .DEBUG_BUF_SIZE(DEBUG_BUF_SIZE)
  ) axi_icache_memory_arbiter_buf (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .req_from_cache(req_from_icache_to_mm),
      .res_to_cache(res_from_mm_to_icache),
      .ready_to_cache(ready_from_mm_to_icache),
      .req_to_dram(req_from_icache_to_dram),
      .res_from_dram(res_from_dram_to_icache)

  );

  // dcacheとdramとの接続.
  AXI_memory_arbiter_buf #(
      .CACHE_BUF_SIZE(8),
      .mm_req_t(mm_req64_t),
      .mm_res_t(mm_res64_t),
      .axi_req_t(axi_req64_t),
      .axi_res_t(axi_res64_t),
      .DATA_SIZE(8),
      .NUM_OF_REQ_FROM_CACHE(NUM_OF_REQ_FROM_DCACHE_TO_MM),
      .NUM_OF_RES_TO_CACHE(NUM_OF_RES_FROM_MM_TO_DCACHE),
      .DEBUG_BUF_SIZE(DEBUG_BUF_SIZE)
  ) axi_dcache_memory_arbiter_buf (
      .clock(cpu_clock),
      .reset(cpu_reset),
      .req_from_cache(req_from_dcache_to_mm),
      .res_to_cache(res_from_mm_to_dcache),
      .ready_to_cache(ready_from_mm_to_dcache),
      .req_to_dram(req_from_dcache_to_dram),
      .res_from_dram(res_from_dram_to_dcache)
  );

`endif


  // --------------------------------------------
  // FENCE_I用
  // ----------------------------------------------
  // circular回避のための_next

  logic fencei_ic_done_seen, fencei_ic_done_seen_next;
  logic fencei_dc_done_seen, fencei_dc_done_seen_next;

  always_comb begin
    invalidate_dcache = fence_i_exe;
    invalidate_icache = fence_i_exe;
  end

  // invalidateが終了したかを見る.
  always_comb begin
    fencei_ic_done_seen_next = fencei_ic_done_seen;
    fencei_dc_done_seen_next = fencei_dc_done_seen;
    fence_i_done_next = 0;

    if (invalidate_icache_done_sig) begin
      fencei_ic_done_seen_next = 1;
    end

    if (invalidate_dcache_done_sig) begin
      fencei_dc_done_seen_next = 1;
    end

    if (fencei_ic_done_seen_next && fencei_dc_done_seen_next) begin
      // 両方ともinvalidateが終了したとき,そのサイクルだけfence_i_doneの信号を送る.
      fencei_ic_done_seen_next = 0;
      fencei_dc_done_seen_next = 0;
      fence_i_done_next = 1;
    end
  end

  always_ff @(posedge cpu_clock) begin
    if (cpu_reset) begin
      fencei_dc_done_seen <= 0;
      fencei_ic_done_seen <= 0;
      fence_i_done <= 0;
    end else begin
      fencei_dc_done_seen <= fencei_dc_done_seen_next;
      fencei_ic_done_seen <= fencei_ic_done_seen_next;
      fence_i_done <= fence_i_done_next;
    end
  end


  //   always_ff @(posedge cpu_clock, posedge cpu_reset) begin
  //     if (cpu_reset) begin
  //       invalidate_icache_done  <= 0;
  //       invalidate_dcache_done  <= 0;
  //       invalidate_l2cache_done <= 0;

  //     end else begin
  //       invalidate_icache_done  <= invalidate_icache_done_next;
  //       invalidate_dcache_done  <= invalidate_dcache_done_next;
  //       invalidate_l2cache_done <= invalidate_l2cache_done_next;
  //     end
  //   end

  //   logic invalidate_dcache_from_fence_i;
  //   logic invalidate_dcache_from_fence_i_next;

  //   logic invalidate_icache_next;

  //   typedef enum logic [1:0] {
  //     FENCEI_IDLE,
  //     INVALIDATING,
  //     HALF_DONE  // icache,dcacheのいずれかが終了.
  //   } fencei_state_t;
  //   fencei_state_t fencei_state;
  //   fencei_state_t fencei_state_next;

  //   always_comb begin
  //     fencei_state_next = fencei_state;
  //     fence_i_done = 0;

  //     invalidate_icache_next = 0;
  //     invalidate_dcache_from_fence_i_next = 0;


  //     case (fencei_state)
  //       FENCEI_IDLE: begin
  //         if (fence_i_exe) begin
  //           fencei_state_next = INVALIDATING;
  //           invalidate_icache_next = 1;
  //           invalidate_dcache_from_fence_i_next = 1;
  //           $display("move to INVALIDATING");
  //         end
  //       end
  //       INVALIDATING: begin
  //         if (invalidate_icache_done && invalidate_dcache_done) begin
  //           fencei_state_next = FENCEI_IDLE;
  //           fence_i_done = 1;
  //           $display("move to FENCEI_IDLE1");
  //         end else if (invalidate_icache_done || invalidate_dcache_done) begin
  //           fencei_state_next = HALF_DONE;
  //           $display("move to HALF_DONE");
  //         end
  //       end
  //       HALF_DONE: begin
  //         if (invalidate_icache_done && invalidate_dcache_done) begin
  //           fencei_state_next = FENCEI_IDLE;
  //           fence_i_done = 1;
  //           $display("move to FENCEI_IDLE2");
  //         end
  //       end
  //       default: ;
  //     endcase


  //   end

  //   always_ff @(posedge cpu_clock, posedge cpu_reset) begin
  //     if (cpu_reset) begin
  //       fencei_state <= FENCEI_IDLE;
  //     end else begin
  //       fencei_state <= fencei_state_next;
  //       invalidate_dcache_from_fence_i <= invalidate_dcache_from_fence_i_next;
  //       invalidate_icache <= invalidate_icache_next;
  //     end
  //   end

  //   // ------------------------------------------------------------------------------
  //   // FOR DEBUG
  //   // ------------------------------------------------------------------------------
  //   // キャッシュの内容を書き戻して,メインメモリの内容をdump
  //   typedef enum logic [2:0] {
  //     DUMP_IDLE,
  //     BEFORE_INVALIDATING_DCACHE,
  //     INVALIDATING_DCACHE,
  //     BEFORE_INVALIDATING_L2CACHE,
  //     INVALIDATING_L2CACHE,
  //     DONE
  //   } dump_state_e;
  //   dump_state_e dump_state;
  //   dump_state_e dump_state_next;


  //   logic invalidate_dcache_from_dump;
  //   logic invalidate_dcache_from_dump_next;

  //   logic invalidate_l2cache_next;


  //   always_comb begin
  //     dump_state_next = dump_state;
  //     invalidate_dcache_from_dump_next = 0;
  //     invalidate_l2cache_next = 0;
  //     dump_mm = 0;

  // `ifdef VERILATOR_COMPILE

  //     case (dump_state)
  //       DUMP_IDLE: begin
  //         if (inv_dump_sig) begin
  //           dump_state_next = BEFORE_INVALIDATING_DCACHE;
  //         end
  //       end
  //       BEFORE_INVALIDATING_DCACHE: begin
  //         invalidate_dcache_from_dump_next = 1;
  //         dump_state_next = INVALIDATING_DCACHE;
  //       end
  //       INVALIDATING_DCACHE: begin
  //         if (invalidate_dcache_done) begin
  //           dump_state_next = BEFORE_INVALIDATING_L2CACHE;
  //         end
  //       end
  //       BEFORE_INVALIDATING_L2CACHE: begin
  //         invalidate_l2cache_next = 1;
  //         dump_state_next = INVALIDATING_L2CACHE;
  //       end
  //       INVALIDATING_L2CACHE: begin
  //         if (invalidate_l2cache_done) begin
  //           dump_state_next = DONE;
  //         end
  //       end
  //       DONE: begin
  //         // dump.
  //         dump_mm = 1;
  //         dump_state_next = DUMP_IDLE;
  //       end
  //       default: ;
  //     endcase

  // `endif

  //   end

  //   always_ff @(posedge cpu_clock, posedge cpu_reset) begin
  //     if (cpu_reset) begin
  //       dump_state <= DUMP_IDLE;
  //     end else begin
  //       dump_state <= dump_state_next;
  //       invalidate_dcache_from_dump <= invalidate_dcache_from_dump_next;
  //       invalidate_l2cache <= invalidate_l2cache_next;
  //     end
  //   end

  //   assign invalidate_dcache = invalidate_dcache_from_dump || invalidate_dcache_from_fence_i;


  // `ifdef VERILATOR_COMPILE

  //   // ============================================================
  //   // DEBUG TRACE:
  //   //   Trace the instruction whose instruction address is 0x80001000
  //   //   while Top.generation == 0x44.
  //   //
  //   // Paste this block just before "endmodule" in Top.sv.
  //   // ============================================================

  //   localparam logic [VADDR_WIDTH-1:0] DBG_TRACE_OP_ADDR = VADDR_WIDTH'(64'h0000_0000_8000_1000);

  //   // logの generation:00000044 が16進表示ならこれで正しい。
  //   // もし「10進の44」を見たいなら 32'h44 を 32'd44 に変える。
  //   localparam int unsigned DBG_TRACE_GEN = 32'h48;

  //   int unsigned dbg_trace_cycle;
  //   int dbg_trace_fp;
  //   logic dbg_trace_in_target_gen;

  //   initial begin
  //     dbg_trace_fp = $fopen("./log/trace_op_80001000_gen44.log", "w");
  //     if (dbg_trace_fp == 0) begin
  //       $display("[TRACE80001000][ERROR] failed to open ./log/trace_op_80001000_gen44.log");
  //     end
  //   end

  //   task automatic dbg_trace_msg(input string s);
  //     begin
  //       $display("%s", s);
  //       if (dbg_trace_fp != 0) begin
  //         $fdisplay(dbg_trace_fp, "%s", s);
  //         $fflush(dbg_trace_fp);
  //       end
  //     end
  //   endtask

  //   task automatic dbg_trace_separator(input string tag);
  //     begin
  //       if (dbg_trace_fp != 0) begin
  //         $fdisplay(dbg_trace_fp, "============================================================");
  //         $fdisplay(dbg_trace_fp,
  //                   "[TRACE80001000][%s] time=%0t cycle=%0d gen=0x%08x minstret=%016h priv=%0b", tag,
  //                   $time, dbg_trace_cycle, generation, csr_renamer_port.minstret_rdata, priv_rval);
  //         $fdisplay(
  //             dbg_trace_fp,
  //             "  flush_ifq=%0d flush_dec=%0d flush_ren=%0d flush_to_st8=%0d flush_to_st9=%0d flush_pcgen.valid=%0d flush_pcgen.addr=0x%0h",
  //             flush_from_ifq.valid, flush_from_decoder.valid, flush_from_renamer.valid, flush_to_st8,
  //             flush_to_st9, flush_to_pcgen.valid, flush_to_pcgen.addr);
  //         $fdisplay(dbg_trace_fp, "------------------------------------------------------------");
  //         $fflush(dbg_trace_fp);
  //       end

  //       $display("============================================================");
  //       $display("[TRACE80001000][%s] time=%0t cycle=%0d gen=0x%08x minstret=%016h priv=%0b", tag,
  //                $time, dbg_trace_cycle, generation, csr_renamer_port.minstret_rdata, priv_rval);
  //       $display(
  //           "  flush_ifq=%0d flush_dec=%0d flush_ren=%0d flush_to_st8=%0d flush_to_st9=%0d flush_pcgen.valid=%0d flush_pcgen.addr=0x%0h",
  //           flush_from_ifq.valid, flush_from_decoder.valid, flush_from_renamer.valid, flush_to_st8,
  //           flush_to_st9, flush_to_pcgen.valid, flush_to_pcgen.addr);
  //       $display("------------------------------------------------------------");
  //     end
  //   endtask

  //   task automatic dbg_dump_pc(input string where, input int unsigned idx, input program_counter_t x);
  //     begin
  //       if (x.valid && x.vaddr == DBG_TRACE_OP_ADDR) begin
  //         $display("[TRACE80001000][%s][%0d] PC valid=%0d vaddr=0x%0h fetch_id=%0d", where, idx,
  //                  x.valid, x.vaddr, x.fetch_id);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(dbg_trace_fp, "[TRACE80001000][%s][%0d] PC valid=%0d vaddr=0x%0h fetch_id=%0d",
  //                     where, idx, x.valid, x.vaddr, x.fetch_id);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_ifq_dec(input string where, input int unsigned idx,
  //                                   input ifq_decoder_t x);
  //     begin
  //       if (x.valid && x.vaddr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][%s][%0d] IFQ_DEC valid=%0d vaddr=0x%0h paddr=0x%0h raw=0x%08h pred_taken=%0d btb_hit=%0d btb_addr=0x%0h pf=%0d af=%0d",
  //             where, idx, x.valid, x.vaddr, x.paddr, x.data, x.pred_taken, x.btb_hit, x.btb_addr,
  //             x.is_page_fault, x.is_access_fault);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][%s][%0d] IFQ_DEC valid=%0d vaddr=0x%0h paddr=0x%0h raw=0x%08h pred_taken=%0d btb_hit=%0d btb_addr=0x%0h pf=%0d af=%0d",
  //               where, idx, x.valid, x.vaddr, x.paddr, x.data, x.pred_taken, x.btb_hit, x.btb_addr,
  //               x.is_page_fault, x.is_access_fault);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_decoded(input string where, input int unsigned idx, input decoded_op_t x);
  //     begin
  //       if (x.valid && x.vaddr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][%s][%0d] DECODED valid=%0d opcode=%0d vaddr=0x%0h paddr=0x%0h raw=0x%08h rs1e=%0d rs2e=%0d rde=%0d rs1=x%0d rs2=x%0d rd=x%0d imm=0x%0h pred_taken=%0d btb_hit=%0d btb_addr=0x%0h pf=%0d af=%0d",
  //             where, idx, x.valid, x.opcode, x.vaddr, x.paddr, x.raw_op, x.rs1_exist, x.rs2_exist,
  //             x.rd_exist, x.rs1, x.rs2, x.rd, x.imm, x.pred_taken, x.btb_hit, x.btb_addr,
  //             x.is_page_fault, x.is_access_fault);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][%s][%0d] DECODED valid=%0d opcode=%0d vaddr=0x%0h paddr=0x%0h raw=0x%08h rs1e=%0d rs2e=%0d rde=%0d rs1=x%0d rs2=x%0d rd=x%0d imm=0x%0h pred_taken=%0d btb_hit=%0d btb_addr=0x%0h pf=%0d af=%0d",
  //               where, idx, x.valid, x.opcode, x.vaddr, x.paddr, x.raw_op, x.rs1_exist, x.rs2_exist,
  //               x.rd_exist, x.rs1, x.rs2, x.rd, x.imm, x.pred_taken, x.btb_hit, x.btb_addr,
  //               x.is_page_fault, x.is_access_fault);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_front(input string where, input int unsigned idx, input vuop_front_t x);
  //     begin
  //       if (x.valid && x.op_addr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][%s][%0d] FRONT valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rs1e=%0d rs2e=%0d rde=%0d prs1=%0d prs2=%0d prd=%0d imm=0x%0h",
  //             where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rs1_exist, x.rs2_exist,
  //             x.rd_exist, x.rs1, x.rs2, x.rd, x.imm);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][%s][%0d] FRONT valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rs1e=%0d rs2e=%0d rde=%0d prs1=%0d prs2=%0d prd=%0d imm=0x%0h",
  //               where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rs1_exist, x.rs2_exist,
  //               x.rd_exist, x.rs1, x.rs2, x.rd, x.imm);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_back(input string where, input int unsigned idx, input vuop_back_t x);
  //     begin
  //       if (x.valid && x.op_addr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][%s][%0d] BACK valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rs1e=%0d rs2e=%0d rde=%0d prs1=%0d prs2=%0d prd=%0d rs1_val=0x%016h rs2_val=0x%016h imm=0x%0h actual_taken=%0d actual_taken_addr=0x%0h",
  //             where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rs1_exist, x.rs2_exist,
  //             x.rd_exist, x.rs1, x.rs2, x.rd, x.rs1_val, x.rs2_val, x.imm, x.actual_taken,
  //             x.actual_taken_addr);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][%s][%0d] BACK valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rs1e=%0d rs2e=%0d rde=%0d prs1=%0d prs2=%0d prd=%0d rs1_val=0x%016h rs2_val=0x%016h imm=0x%0h actual_taken=%0d actual_taken_addr=0x%0h",
  //               where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rs1_exist, x.rs2_exist,
  //               x.rd_exist, x.rs1, x.rs2, x.rd, x.rs1_val, x.rs2_val, x.imm, x.actual_taken,
  //               x.actual_taken_addr);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_result(input string where, input int unsigned idx, input vuop_result_t x);
  //     begin
  //       if (x.valid && x.op_addr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][%s][%0d] RESULT valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rde=%0d prd=%0d rd_val=0x%016h actual_taken=%0d actual_taken_addr=0x%0h ldst_paddr=0x%0h ldst_vaddr=0x%0h pf=%0d af=%0d",
  //             where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rd_exist, x.rd, x.rd_val,
  //             x.actual_taken, x.actual_taken_addr, x.ldst_target_paddr, x.ldst_target_vaddr,
  //             x.is_page_fault, x.is_access_fault);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][%s][%0d] RESULT valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d rde=%0d prd=%0d rd_val=0x%016h actual_taken=%0d actual_taken_addr=0x%0h ldst_paddr=0x%0h ldst_vaddr=0x%0h pf=%0d af=%0d",
  //               where, idx, x.valid, x.opcode, x.op_addr, x.al_idx, x.rd_exist, x.rd, x.rd_val,
  //               x.actual_taken, x.actual_taken_addr, x.ldst_target_paddr, x.ldst_target_vaddr,
  //               x.is_page_fault, x.is_access_fault);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   task automatic dbg_dump_renamer_lsu_new_instr(input int unsigned idx);
  //     begin
  //       if (renamer_lsu_port.new_instr[idx].valid &&
  //             renamer_lsu_port.new_instr[idx].op_addr == DBG_TRACE_OP_ADDR) begin
  //         $display(
  //             "[TRACE80001000][RENAMER_LSU_NEW][%0d] valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d si=%0d so=%0d sr=%0d sw=%0d",
  //             idx, renamer_lsu_port.new_instr[idx].valid, renamer_lsu_port.new_instr[idx].opcode,
  //             renamer_lsu_port.new_instr[idx].op_addr, renamer_lsu_port.new_instr[idx].al_idx,
  //             renamer_lsu_port.new_instr[idx].si, renamer_lsu_port.new_instr[idx].so,
  //             renamer_lsu_port.new_instr[idx].sr, renamer_lsu_port.new_instr[idx].sw);
  //         if (dbg_trace_fp != 0) begin
  //           $fdisplay(
  //               dbg_trace_fp,
  //               "[TRACE80001000][RENAMER_LSU_NEW][%0d] valid=%0d opcode=%0d op_addr=0x%0h al_idx=%0d si=%0d so=%0d sr=%0d sw=%0d",
  //               idx, renamer_lsu_port.new_instr[idx].valid, renamer_lsu_port.new_instr[idx].opcode,
  //               renamer_lsu_port.new_instr[idx].op_addr, renamer_lsu_port.new_instr[idx].al_idx,
  //               renamer_lsu_port.new_instr[idx].si, renamer_lsu_port.new_instr[idx].so,
  //               renamer_lsu_port.new_instr[idx].sr, renamer_lsu_port.new_instr[idx].sw);
  //           $fflush(dbg_trace_fp);
  //         end
  //       end
  //     end
  //   endtask

  //   always_ff @(posedge cpu_clock) begin
  //     if (cpu_reset) begin
  //       dbg_trace_cycle <= 0;
  //       dbg_trace_in_target_gen <= 0;
  //     end else begin
  //       dbg_trace_cycle <= dbg_trace_cycle + 1;

  //       // generation entering/leaving marker
  //       if (generation == DBG_TRACE_GEN && !dbg_trace_in_target_gen) begin
  //         dbg_trace_separator("ENTER_TARGET_GENERATION");
  //         dbg_trace_in_target_gen <= 1;
  //       end else if (generation != DBG_TRACE_GEN && dbg_trace_in_target_gen) begin
  //         dbg_trace_separator("LEAVE_TARGET_GENERATION");
  //         dbg_trace_in_target_gen <= 0;
  //       end

  //       // generation == 0x44 の間だけ追跡
  //       if (generation == DBG_TRACE_GEN) begin

  //         // flushは対象命令と直接関係なくても重要なので、generation 0x44中は出す
  //         if (flush_from_ifq.valid || flush_from_decoder.valid || flush_from_renamer.valid ||
  //               flush_to_st2 || flush_to_st3 || flush_to_st4 || flush_to_st6 ||
  //               flush_to_st7 || flush_to_st8 || flush_to_st9) begin
  //           dbg_trace_separator("FLUSH_EVENT");
  //         end

  //         // Stage1 -> Stage2 PC
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_pc("ST1_TO_ST2_PC", i, pc_from_st1_to_st2[i]);
  //         end

  //         // Stage2 -> Stage3 PC
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_pc("ST2_TO_ST3_PC", i, pc_from_st2_to_st3[i]);
  //         end

  //         // Stage3 -> Stage4 IFQ output
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_ifq_dec("RAW_OP_IFQ_TO_DECODER", i, raw_op[i]);
  //         end

  //         // Stage4 -> Stage5 Decoder output
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_decoded("DECODED_OP", i, decoded_op[i]);
  //         end

  //         // Stage5 -> Stage6 Renamer output
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_front("RENAMED_OP", i, renamed_op[i]);
  //         end

  //         // Renamer -> LSU side-table allocation
  //         for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
  //           dbg_dump_renamer_lsu_new_instr(i);
  //         end

  //         // Stage6 -> Stage7 Issue outputs
  //         for (int unsigned i = 0; i < NUM_OF_ARI_ISSUE; i++) begin
  //           dbg_dump_front("ISSUED_ARI", i, issued_op_ari[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
  //           dbg_dump_front("ISSUED_LD", i, issued_op_ld[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
  //           dbg_dump_front("ISSUED_ST_AMO", i, issued_op_st_amo[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_CSR_ISSUE; i++) begin
  //           dbg_dump_front("ISSUED_CSR", i, issued_op_csr[i]);
  //         end

  //         // Stage7 -> Stage8 physical register read output
  //         for (int unsigned i = 0; i < NUM_OF_ARI_ISSUE; i++) begin
  //           dbg_dump_back("RS_READY_ARI", i, op_rs_ready_ari[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
  //           dbg_dump_back("RS_READY_LD", i, op_rs_ready_ld[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
  //           dbg_dump_back("RS_READY_ST_AMO", i, op_rs_ready_st_amo[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_CSR_ISSUE; i++) begin
  //           dbg_dump_back("RS_READY_CSR", i, op_rs_ready_csr[i]);
  //         end

  //         // Stage8 execution results before merge
  //         for (int unsigned i = 0; i < NUM_OF_ARI_EXE; i++) begin
  //           dbg_dump_result("RESULT_ARI_RAW", i, result_op_ari[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
  //           dbg_dump_result("RESULT_LD_RAW", i, result_op_ld[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
  //           dbg_dump_result("RESULT_ST_RAW", i, result_op_st[i]);
  //         end
  //         for (int unsigned i = 0; i < NUM_OF_CSR_EXE; i++) begin
  //           dbg_dump_result("RESULT_CSR_RAW", i, result_op_csr[i]);
  //         end

  //         // Merged feedback before Stage9 register
  //         for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
  //           dbg_dump_result("RESULT_MERGED_RESULT_OP", i, result_op[i]);
  //         end

  //         // Registered feedback actually returned to Renamer
  //         for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
  //           dbg_dump_result("RESULT_TO_RENAMER_RESULT_OP2", i, result_op2[i]);
  //         end

  //       end
  //     end
  //   end

  // `endif

endmodule
