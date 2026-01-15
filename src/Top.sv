// 新しいtop

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"
`include "CACHE_PROPS.svh"

module Top (
    input logic clock,
    input logic reset,

    input logic inv_dump_sig
);
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import CACHE_PROPS::*;

  // -----------------------------------------------------------------------
  // op,pcなどの流れ
  // -----------------------------------------------------------------------
  // stage1 => stage2
  pc_t pc_from_st1_to_st2;

  // stage2 => stage3
  logic [NUM_OF_FETCH-1:0] pred_taken;
  logic [NUM_OF_FETCH-1:0] btb_hit_valid;
  logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_hit_addr;
  pc_t pc_from_st2_to_st3;
  pred_btb_result_t pred_btb_result;

  // stage3 => stage4
  ifq_decoder_t raw_op[NUM_OF_FETCH];

  // stage4 => stage5
  decoded_op_t decoded_op[NUM_OF_FETCH];

  // stage5 => stage6
  vuop_front_t renamed_op[NUM_OF_FETCH];

  // Stage6 => Stage7
  vuop_front_t issued_op_ari[NUM_OF_ARI_ISSUE];
  vuop_front_t issued_op_ld[NUM_OF_LD_ISSUE];
  vuop_front_t issued_op_st_amo[NUM_OF_ST_AMO_ISSUE];
  vuop_front_t issued_op_csr[NUM_OF_CSR_ISSUE];

  // stage7 => stage8
  vuop_back_t op_rs_ready_ari[NUM_OF_ARI_ISSUE];
  vuop_back_t op_rs_ready_ld[NUM_OF_LD_ISSUE];
  vuop_back_t op_rs_ready_st_amo[NUM_OF_ST_AMO_ISSUE];
  vuop_back_t op_rs_ready_csr[NUM_OF_CSR_ISSUE];

  // stage8 => 
  vuop_result_t result_op_ari[NUM_OF_ARI_EXE];
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

  // Renamer <=> INt issue queue
  // csr命令を発行してもいいか
  logic csr_ready;
  logic [AL_IDX_WIDTH-1:0] csr_ready_al_idx;

  // Renamer <=> CSR
  csr_renamer_if csr_renamer_port ();

  // Renamer <=> csru
  csru_renamer_if csru_renamer_port ();

  // Renamer <=> LSU
  Renamer_LSU_if renamer_lsu_port ();

  // Renamer <=> Priv
  priv_w_t priv_w;


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
  cache_req_t req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE+NUM_OF_PW];
  cache_res_t res_from_dcache[NUM_OF_LD_EXE];

  // DCache <=> MMU
  cache_req_t req_to_dcache_from_mmu[NUM_OF_PW];
  // 正直そんなにmmuのリクエストがdcacheから帰ってくる頻度は高くないので,res_to_lsu_from_dcacheに合わせる
  cache_res_t res_to_mmu_from_dcache[NUM_OF_LD_EXE];

  // DCache <=> LSU
  cache_req_t req_to_dcache_from_lsu[NUM_OF_LD_EXE+NUM_OF_ST_EXE];
  cache_res_t res_to_lsu_from_dcache[NUM_OF_LD_EXE];
  logic stall_out_from_dcache;

  always_comb begin
    // sub_idが0ならlsuからのreq, sub_idが1ならmmuからのreq

    // req_to_dcache_from_mmu, req_to_dcache_from_lsu => req_to_dcache
    for (int unsigned i = 0; i < NUM_OF_LD_EXE + NUM_OF_ST_EXE; i++) begin
      req_to_dcache[i] = req_to_dcache_from_lsu[i];
    end
    for (int unsigned i = 0; i < NUM_OF_PW; i++) begin
      req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE+i] = req_to_dcache_from_mmu[i];
    end

    // res_from_dcache => res_to_lsu_from_dcache, res_to_mmu_from_dcache
    res_to_lsu_from_dcache = '{default: 0};
    res_to_mmu_from_dcache = '{default: 0};
    begin
      int unsigned res_to_lsu_counter = 0;
      int unsigned res_to_mmu_counter = 0;
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
  cache_req_t req_to_icache[NUM_OF_REQ_TO_ICACHE];
  cache_res_t res_from_icache[NUM_OF_RES_FROM_ICACHE];
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

  // メインメモリ <=> MMU(L2TLB)
  mm_if #(
      .NUM_OF_REQS(NUM_OF_PW),
      .NUM_OF_RES (NUM_OF_PW)
  ) mm_mmu_port ();

  // メインメモリ <=> CacheSubsystem(L2Cache)
  mm_if #(
      .NUM_OF_REQS(NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE),
      .NUM_OF_RES (NUM_OF_MM_PORT_CONNECTED_TO_L2CACHE)
  ) mm_cachesubsystem_port ();


  BootLoader bl (
      .clock  (clock),
      .reset  (reset),
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
  logic stall_from_st8_to_st7_ldst;
  assign stall_from_st8_to_st7_ldst = 0;

  logic stall_from_st8_to_st7_csr;


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

  logic fence_i_exe;
  logic fence_i_done;

  logic invalidate_icache;
  logic invalidate_icache_done;
  logic invalidate_icache_done_next;

  logic invalidate_dcache;
  logic invalidate_dcache_done;
  logic invalidate_dcache_done_next;

  logic invalidate_l2cache;
  logic invalidate_l2cache_done;
  logic invalidate_l2cache_done_next;

  // -----------------------------------------------------------------------
  // Stage1
  // -----------------------------------------------------------------------
  pcgen pcgen (
      .clock(clock),
      .reset(reset),
      .pc_out(pc_from_st1_to_st2),
      .flush_in(flush_to_pcgen),
      .stall_in(stall_from_st2_to_st1)
  );

  // ------------------------------------------------------------------------
  // Stage2 
  // ------------------------------------------------------------------------

  // Icacheの入力を調整.
  Icache_req_arbiter irb (
      .clock(clock),
      .reset(reset),
      .pc_from_st1_cur(pc_from_st1_to_st2),
      .req_to_icache(req_to_icache),
      .req_to_bootloader(req_to_bootloader),
      .generation(generation),
      .priv_rval(priv_rval),
      .satp(satp),
      .stall_in(stall_from_st3_to_st2)
  );


  // predictor,btb,pcbypassは常に同じpcに対して動作しているので,stall_outはpcbypassにまとめる.
  // 同様にして,pcgenから来たpcがvalidかもpcbypassが判断する.
  Predictor predictor (
      .clock(clock),
      .reset(reset),
      .first_instr_addr_cur(pc_from_st1_to_st2.vaddr),
      .pred_taken(pred_taken),
      .feedback(is_taken_feedback_to_pred),
      .stall_in(stall_from_st3_to_st2),
      .flush_in(flush_to_st2)
  );

  BTB btb (
      .clock(clock),
      .reset(reset),
      .first_instr_addr_cur(pc_from_st1_to_st2.vaddr),
      .hit(btb_hit_valid),
      .addr_out(btb_hit_addr),
      .feedback(misprediction_feedback_to_btb),
      .stall_in(stall_from_st3_to_st2),
      .flush_in(flush_to_st2)
  );

  PCBypass pcbypass (
      .clock(clock),
      .reset(reset),
      .pc_in_cur(pc_from_st1_to_st2),
      .pc_out(pc_from_st2_to_st3),
      .stall_in(stall_from_st3_to_st2),
      .stall_out(stall_out_from_pcbypass),
      .flush_in(flush_to_st2)
  );

  // stage2の出力をstage3のために束ねる
  // pred_taken, btb_hit_valid, btb_hit_addr,pc_from_st2_to_st3
  // => pred_btb_result
  always_comb begin
    pred_btb_result = '{
        valid: pc_from_st2_to_st3.valid,
        first_instr_addr: pc_from_st2_to_st3.vaddr,
        first_instr_id: pc_from_st2_to_st3.first_instr_id,
        pred_taken: pred_taken,
        btb_hit: btb_hit_valid,
        btb_addr: btb_hit_addr
    };
  end


  // -------------------------------------------------------------------------
  // Stage3 
  // ------------------------------------------------------------------------
  IFQ ifqueue (
      .clock(clock),
      .reset(reset),
      .icache_result(res_from_icache),
      .pred_btb_result(pred_btb_result),
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
      .clock(clock),
      .reset(reset),
      .fetched_content_cur(raw_op),
      .decoded_op(decoded_op),
      .mispred_mod(flush_from_decoder),
      .stall_in(stall_from_st5_to_st4),
      .stall_out(stall_from_st4_to_st3),
      .flush_in(flush_to_st4)
  );

  // --------------------------------------------------------------------------
  // Stage5
  // --------------------------------------------------------------------------
  Renamer renamer (
      .clock      (clock),
      .reset      (reset),
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

      .flush_tlb(flush_tlb),

      // LSUとの接続.
      .lsu_port(renamer_lsu_port),

      // csruとの接続
      .csru_port(csru_renamer_port),

      // CSRとの接続
      .csr_port(csr_renamer_port),

      .flush_from_renamer(flush_from_renamer),
      .stall_in(stall_from_st6_to_st5),
      .stall_out(stall_from_st5_to_st4),

      .generation(generation),
      .invalidate_l1cache(fence_i_exe),
      .invalidate_l1cache_done(fence_i_done)
  );

  // --------------------------------------------------------------------------
  // Stage6
  // --------------------------------------------------------------------------
  IntIssueQueue intissuequeue (
      .clock(clock),
      .reset(reset),
      .op_in(renamed_op),
      .feedback(result_feedback_rd),
      .ld_speculative_feedback_valid(ld_speculative_feedback_valid),
      .ld_speculative_feedback_al_idx(ld_speculative_feedback_al_idx),
      .op_out_ari(issued_op_ari),
      .op_out_ld(issued_op_ld),
      .op_out_st_amo(issued_op_st_amo),
      .op_out_csr(issued_op_csr),
      .flush_in(flush_to_st6),
      .stall_out(stall_from_st6_to_st5),
      .stall_in_from_ldst(stall_from_st7_to_st6_ldst),
      .stall_in_from_csr(stall_from_st7_to_st6_csr)
  );

  // --------------------------------------------------------------------------
  // Stage7
  // --------------------------------------------------------------------------
  INTPRF intprf (
      .clock(clock),
      .reset(reset),
      .op_in_ari(issued_op_ari),
      .op_in_ld_cur(issued_op_ld),
      .op_in_st_amo_cur(issued_op_st_amo),
      .op_in_csr_cur(issued_op_csr),
      .op_out_ari(op_rs_ready_ari),
      .op_out_ld(op_rs_ready_ld),
      .op_out_st_amo(op_rs_ready_st_amo),
      .op_out_csr(op_rs_ready_csr),
      .op_feedback(result_op2),
      .stall_in_from_ldst(stall_from_st8_to_st7_ldst),
      .stall_in_from_csr(stall_from_st8_to_st7_csr),
      .stall_out_ldst(stall_from_st7_to_st6_ldst),
      .stall_out_csr(stall_from_st7_to_st6_csr),
      .flush_in(flush_to_st7)
  );

  // --------------------------------------------------------------------------
  // Stage8
  // --------------------------------------------------------------------------
  ArithmeticUnit au (
      .clock(clock),
      .reset(reset),
      .op_in(op_rs_ready_ari),
      .op_out(result_op_ari),
      .flush_in(flush_to_st8)
  );

  LSU lsu (
      .clock(clock),
      .reset(reset),
      .op_ld_in(op_rs_ready_ld),
      .op_st_amo_in(op_rs_ready_st_amo),
      .op_ld_out(result_op_ld),
      .op_st_out(result_op_st),

      .op_mmio_out(result_op_mmio),

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

      .generation(generation)

  );

  CSRUnit csru (
      .clock(clock),
      .reset(reset),
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
    for (int unsigned i = 0; i < NUM_OF_ARI_EXE; i++) begin
      result_op[i] = result_op_ari[i];
    end
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+i] = result_op_ld[i];
    end
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_LD_EXE+i] = result_op_st[i];
    end
    for (int unsigned i = 0; i < NUM_OF_MMIO_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_LD_EXE+NUM_OF_ST_EXE+i] = result_op_mmio;
    end
    for (int unsigned i = 0; i < NUM_OF_CSR_EXE; i++) begin
      result_op[NUM_OF_ARI_EXE+NUM_OF_LD_EXE+NUM_OF_ST_EXE+NUM_OF_MMIO_EXE+i] = result_op_csr[i];
    end
  end

  // -------------------------------------------------------------------------
  // Stage9
  // ------------------------------------------------------------------------
  // Decoder -> decoded_op -> Renamer -> (Renamer_LSU_if.new_instr) -> LSU -> Top.result_op(_ld) -> Top.result_op -> (Renamer) -> flush → IFQ/Decoder …
  // のループを断ち切るために,result_op2 <= result_op をalways_ffで更新する.
  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
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
      .clock(clock),
      .reset(reset),
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
  CacheSubsystem cachesubsystem (
      .clock(clock),
      .reset(reset),
      .req_to_icache(req_to_icache),
      .res_from_icache(res_from_icache),
      .req_to_dcache(req_to_dcache),
      .res_from_dcache(res_from_dcache),
      .itlb_port(itlb_port),
      .mm_port(mm_cachesubsystem_port),
      .stall_req_to_icache(stall_out_from_icache),
      .stall_req_to_dcache(stall_out_from_dcache),
      .invalidate_icache(invalidate_icache),
      .invalidate_icache_done(invalidate_icache_done_next),
      .invalidate_dcache(invalidate_dcache),
      .invalidate_dcache_done(invalidate_dcache_done_next),
      .invalidate_l2cache(invalidate_l2cache),
      .invalidate_l2cache_done(invalidate_l2cache_done_next)
  );


  // --------------------------------------------------------------------------
  // CSRレジスタ
  // --------------------------------------------------------------------------
  CSRRF csrrf (
      .clock(clock),
      .reset(reset),
      .renamer_port(csr_renamer_port),
      .csru_port(csr_csru_port),
      .satp_out(satp),
      .plic_port(csr_plic_port),
      .clint_port(csr_clint_port)
  );

  // -------------------------------------------------------------------------
  // PLIC, CLINT
  // --------------------------------------------------------------------------
  PLIC plic (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_plic),
      .res_out(res_from_plic),
      .csr_port(csr_plic_port)
  );

  CLINT clint (
      .clock(clock),
      .reset(reset),
      .csr_port(csr_clint_port)
  );


  // --------------------------------------------------------------------------
  // priv
  // --------------------------------------------------------------------------
  Priv priv (
      .clock(clock),
      .reset(reset),
      .priv_rval(priv_rval),
      .priv_w(priv_w)
  );

  // ----------------------------------------------------------------------------
  // メインメモリ
  // -----------------------------------------------------------------------------
  logic dump_mm;
  MainMemory mm (
      .clock(clock),
      .reset(reset),
      .tlb_port(mm_mmu_port),
      .cache_port(mm_cachesubsystem_port),
      .dump_mm(dump_mm)
  );

  // --------------------------------------------
  // FENCE_I用
  // ----------------------------------------------
  // circular回避のための_next


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      invalidate_icache_done  <= 0;
      invalidate_dcache_done  <= 0;
      invalidate_l2cache_done <= 0;

    end else begin
      invalidate_icache_done  <= invalidate_icache_done_next;
      invalidate_dcache_done  <= invalidate_dcache_done_next;
      invalidate_l2cache_done <= invalidate_l2cache_done_next;
    end
  end

  logic invalidate_dcache_from_fence_i;
  logic invalidate_dcache_from_fence_i_next;

  logic invalidate_icache_next;

  typedef enum logic [1:0] {
    FENCEI_IDLE,
    INVALIDATING,
    HALF_DONE  // icache,dcacheのいずれかが終了.
  } fencei_state_t;
  fencei_state_t fencei_state;
  fencei_state_t fencei_state_next;

  always_comb begin
    fencei_state_next = fencei_state;
    fence_i_done = 0;

    invalidate_icache_next = 0;
    invalidate_dcache_from_fence_i_next = 0;


    case (fencei_state)
      FENCEI_IDLE: begin
        if (fence_i_exe) begin
          fencei_state_next = INVALIDATING;
          invalidate_icache_next = 1;
          invalidate_dcache_from_fence_i_next = 1;
        end
      end
      INVALIDATING: begin
        if (invalidate_icache_done && invalidate_dcache_done) begin
          fencei_state_next = FENCEI_IDLE;
          fence_i_done = 1;
        end else if (invalidate_icache_done || invalidate_dcache_done) begin
          fencei_state_next = HALF_DONE;
        end
      end
      HALF_DONE: begin
        if (invalidate_icache_done || invalidate_dcache_done) begin
          fencei_state_next = FENCEI_IDLE;
          fence_i_done = 1;
        end
      end
      default: ;
    endcase


  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      fencei_state <= FENCEI_IDLE;
    end else begin
      fencei_state <= fencei_state_next;
      invalidate_dcache_from_fence_i <= invalidate_dcache_from_fence_i_next;
      invalidate_icache <= invalidate_icache_next;
    end
  end

  // ------------------------------------------------------------------------------
  // FOR DEBUG
  // ------------------------------------------------------------------------------
  // キャッシュの内容を書き戻して,メインメモリの内容をdump
  typedef enum logic [2:0] {
    DUMP_IDLE,
    BEFORE_INVALIDATING_DCACHE,
    INVALIDATING_DCACHE,
    BEFORE_INVALIDATING_L2CACHE,
    INVALIDATING_L2CACHE,
    DONE
  } dump_state_e;
  dump_state_e dump_state;
  dump_state_e dump_state_next;


  logic invalidate_dcache_from_dump;
  logic invalidate_dcache_from_dump_next;

  logic invalidate_l2cache_next;


  always_comb begin
    dump_state_next = dump_state;
    invalidate_dcache_from_dump_next = 0;
    invalidate_l2cache_next = 0;
    dump_mm = 0;

    case (dump_state)
      DUMP_IDLE: begin
        if (inv_dump_sig) begin
          dump_state_next = BEFORE_INVALIDATING_DCACHE;
        end
      end
      BEFORE_INVALIDATING_DCACHE: begin
        invalidate_dcache_from_dump_next = 1;
        dump_state_next = INVALIDATING_DCACHE;
      end
      INVALIDATING_DCACHE: begin
        if (invalidate_dcache_done) begin
          dump_state_next = BEFORE_INVALIDATING_L2CACHE;
        end
      end
      BEFORE_INVALIDATING_L2CACHE: begin
        invalidate_l2cache_next = 1;
        dump_state_next = INVALIDATING_L2CACHE;
      end
      INVALIDATING_L2CACHE: begin
        if (invalidate_l2cache_done) begin
          dump_state_next = DONE;
        end
      end
      DONE: begin
        // dump.
        dump_mm = 1;
        dump_state_next = DUMP_IDLE;
      end
      default: ;
    endcase
  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      dump_state <= DUMP_IDLE;
    end else begin
      dump_state <= dump_state_next;
      invalidate_dcache_from_dump <= invalidate_dcache_from_dump_next;
      invalidate_l2cache <= invalidate_l2cache_next;
    end
  end


  assign invalidate_dcache = invalidate_dcache_from_dump || invalidate_dcache_from_fence_i;


endmodule
