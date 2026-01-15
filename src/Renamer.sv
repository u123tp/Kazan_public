// ストア命令は仮発行のときにシグナルをrenamerに送るので,実行おわっても特に何も返さなくていい
// TODO:割り込み処理

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CSR_PROPS.svh"

module Renamer
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CSR_PROPS::*;
(
    input logic clock,
    input logic reset,

    input decoded_op_t op_in_cur[NUM_OF_FETCH],
    output vuop_front_t op_out[NUM_OF_FETCH],

    // 実行が終わった命令.アクティブリストのエントリをdoneに更新するためのフィードバック.
    input vuop_result_t feedback_op[NUM_OF_RESULT_FEEDBACKS],

    // renamer => btb
    // ジャンプやbranchする場合,その結果はbtbに書き込まれる.
    // ただ,別にbtbが予想した通りのアドレスに飛んだときは更新する必要も無いので,mispredictionの時だけ更新すればいいので配列である必要は無い.
    output misprediction_feedback_to_btb_t misprediction_feedback_to_btb,

    // 分岐やジャンプ命令が毎回あたっていたかをフィードバックする.
    output is_taken_feedback_to_pred_t is_taken_feedback_to_pred[NUM_OF_GRADUATE],

    // mispredictionや例外で他のユニットの内容を流す時.
    output addr_with_valid_t flush_from_renamer,

    // lsuとの接続.
    Renamer_LSU_if.renamer lsu_port,

    // csruとの接続
    csru_renamer_if.renamer csru_port,

    // dcacheが満タンなら,stのコミットを抑制
    input logic dcache_noroom,

    // tlbの全エントリ無効化(sfence.vma用)
    output logic flush_tlb,

    //  特権モードの読み書き
    input privilege_level_e priv_rval,
    output priv_w_t priv_w,

    // csrレジスタとの接続
    csr_renamer_if.renamer csr_port,

    output logic stall_out,


    input logic stall_in,

    // cacheとやり取りするときに,alをidxとして使ってることが多いので,
    // flushした後に,flush前にcacheにだしたreqに対する返答を受け取っても廃棄できるようにするため.
    output int unsigned generation,

    // fence_iでcacheの内容をinvalidateする.
    output logic invalidate_l1cache,
    input  logic invalidate_l1cache_done

);



  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  decoded_op_t op_in[NUM_OF_FETCH];

  decoded_op_t op_in_pending[NUM_OF_FETCH];
  logic is_pending;
  decoded_op_t op_in_pending_next[NUM_OF_FETCH];
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    op_in_pending_next = op_in_pending;

    if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      op_in_pending_next = op_in_cur;
      is_pending_next = 1;
      op_in = '{default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      op_in = '{default: 0};
    end else if (is_pending) begin
      // stall終了時.
      op_in = op_in_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      op_in = op_in_cur;
    end
  end

  // 出力
  vuop_front_t op_out_next[NUM_OF_FETCH];


  // RAT[論理レジスタ番号] = 物理レジスタ番号
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat_next[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rat_init[NUM_OF_LOGREGS];
  // RRAT(Retirement RAT)
  // 卒業したところまでのRAT.投機実行のミス時にRRATをRATにコピーする
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rrat[NUM_OF_LOGREGS];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] rrat_next[NUM_OF_LOGREGS];

  // Active List
  // 非順序実行において卒業(順序確定)を行うユニット.もしエラーや分岐予測の間違いが存在したらロールバックを行う.
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] addr;  // この命令のアドレス.
    opcode_t opcode;
    logic has_rd;  // この命令がrdを持っているか
    logic [4:0] logical_rd;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rd;
    // この命令の発行以前に,この命令の用いてる論理レジスタに対応していた物理レジスタ.
    logic [$clog2(NUM_OF_PHYREGS)-1:0] previous_physical_rd;
    logic done;  // 処理は終わっているなら1
    logic pred_taken;  // 分岐予想でtakenにしていたか.
    logic [VADDR_WIDTH-1:0] pred_taken_addr;  // pred_takenが1の時,予想された飛び先.pred_taken==0のときは使用しない.
    logic actual_taken;  // 実際にtakenであったか.
    logic [VADDR_WIDTH-1:0] actual_taken_addr; //actual_takenが1の時,実際の飛び先.actual_taken==0のときは使用しない.
    logic misprediction;  // mispredictionが発生したか.
    logic exception;  // 例外発生時.
    logic [5:0] cause;  // mcauseの例外番号.
    logic [XLEN-1:0] tval;

    // 命令
    logic is_page_fault_instr;
    logic is_access_fault_instr;

    // ld,st用フィールド.
    logic raw_hazard;  // LSUでのrawハザード検出されたld命令にセットされる.
    logic fencei_sig_made; // このエントリがfence_i 命令のとき,invalidateのsigは出されたか.
    logic amo_ld_done;  // amo命令のld命令部がresultとして来たか.
    // lr命令を出した時に,あと,tval
    // TOOD:dwからdwじゃないのに変更したのでそれに伴う更新.
    // ldst_target_addrは,lrとかに使うpaddrを入れておくが,
    // page_faultの場合は,符号拡張されたvaddrが入っている
    logic [PADDR_WIDTH-1:0] ldst_target_addr;
    logic is_page_fault_ldst;
    logic is_access_fault_ldst;
    logic target_address_misalignment;

    // illegal instr用.
    logic [31:0] raw_op;

    // FOR DEBUG
    logic has_rs1;
    logic has_rs2;
    logic [4:0] logical_rs1;
    logic [4:0] logical_rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs2;
    logic [XLEN-1:0] rd_val;

  } activelist_t;
  // exception処理
  // 0. Instruction address misalignment (target_address_misaligned)
  // 1. Instruction access fault (is_access_fault_instr)
  // 2. Illegal instruction (opcode)
  // 3. BreakPoint (opcode)
  // 4. Load address misalignment (target_address_misalignment)
  // 5. Load access fault (access_fault_ldst)
  // 6. Store/AMO address misalignment (target_address_misalignment)
  // 7. Store/AMO access fault (access_fault_ldst)
  // 8. Enviroment call from U_MODE (opcode)
  // 9. Enviroment call from S_MODE (opcode)
  // 11. Enviroment call from M_MODE (opcode)
  // 12. Instruction page fault (is_page_fault_instr)
  // 13. Load page fault (is_page_fault_ldst)
  // 15. Store/AMO page fault (is_page_fault_ldst)

  activelist_t al[ACTIVELIST_SIZE];
  activelist_t al_next[ACTIVELIST_SIZE];
  logic [AL_IDX_WIDTH-1:0] al_rp;
  logic [AL_IDX_WIDTH-1:0] al_wp;
  logic [AL_IDX_WIDTH-1:0] al_rp_next;
  logic [AL_IDX_WIDTH-1:0] al_wp_next;

  logic [AL_IDX_WIDTH:0] num_of_entries_in_al;
  logic [AL_IDX_WIDTH:0] num_of_entries_in_al_next;

  logic [AL_IDX_WIDTH-1:0] al_num_new;
  logic [AL_IDX_WIDTH-1:0] al_num_graduated;
  logic al_flush;

  assign lsu_port.al_rp = al_rp;
  assign lsu_port.al_wp = al_wp;


  // ----------------------------------------------
  // lrsc_lock
  // ----------------------------------------------
  typedef struct packed {
    logic valid;
    logic [PADDR_WIDTH-1:0] paddr_dw_aligned;
    logic is_lr_w;
  } lrsc_lock_t;
  // コミットされた部分までのlrscのロック.
  lrsc_lock_t lrsc_lock;
  lrsc_lock_t lrsc_lock_next;

  // -----------------------------------------
  // FreeList
  // -----------------------------------------
  // Renamerに渡す使用可能な物理レジスタ.
  logic [$clog2(NUM_OF_PHYREGS)-1:0] available_prd[NUM_OF_FETCH];

  // available_prdの内,使用したものがrenamerから伝達される.
  logic prd_used[NUM_OF_FETCH];

  // コミットした命令の論理レジスタに対応するprevious physical registerとphysical register.
  logic committed_rd_valid[NUM_OF_GRADUATE];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_phyreg[NUM_OF_GRADUATE];
  logic [$clog2(NUM_OF_PHYREGS)-1:0] committed_prev_phyreg[NUM_OF_GRADUATE];

  // mispredictionや例外発生時
  logic flush_fl;

  // 更新用.
  int unsigned generation_next;

  // invalidate
  logic invalidate_l1cache_next;

  FreeList freelist (
      .clock(clock),
      .reset(reset),
      .available_prd(available_prd),
      .prd_used(prd_used),
      .committed_rd_valid(committed_rd_valid),
      .committed_phyreg(committed_phyreg),
      .committed_prev_phyreg(committed_prev_phyreg),
      .flush_in(flush_fl)
  );

  // => csru
  // committed_ldst_from_al_t csru_port_committed_instr_next[NUM_OF_GRADUATE];
  // executable_csr_t csru_port_executable_csr_next;


  // ------------------------------------------------------------------------
  // instret
  // -------------------------------------------------------------------------
  logic instret_inhibited;
  assign instret_inhibited = csr_port.mcountinhibit_rdata.as_mcountinhibit.IR;



  // ----------------------------------------------------------------------
  // pmp check
  // ----------------------------------------------------------------------
  typedef struct packed {
    logic valid;
    logic R;
    logic W;
    logic X;
    logic L;
  } pmp_result_t;

  function automatic logic pmp_access_fault(
      input logic [PADDR_WIDTH-1:0] target_paddr, input privilege_level_e current_priv,
      input logic is_read, input logic is_write, input logic is_exe);

    logic pmp_exist = 0;
    pmp_result_t pmp_result = '{default: 0};


    for (int unsigned i = 0; i < 64; i++) begin
      logic [7:0] pmpcfg = csr_port.pmpcfg_rdata[i/8].as_uint[(i%8)*8+:8];
      logic L = pmpcfg[7];
      logic [1:0] A = pmpcfg[4:3];
      logic X = pmpcfg[2];
      logic W = pmpcfg[1];
      logic R = pmpcfg[0];

      logic [PADDR_WIDTH-1:0] start_paddr;
      logic [PADDR_WIDTH-1:0] end_paddr;
      int unsigned napot_counter = 0;
      logic [XLEN-1:0] napot_mask = '1;

      case (A)
        2'b00: begin
          start_paddr = '0;
          end_paddr   = '0;
        end

        2'b01: begin  // TOR
          start_paddr = (i == 0) ? '0 : PADDR_WIDTH'(csr_port.pmpaddr_rdata[i-1] << 2);
          end_paddr   = PADDR_WIDTH'(csr_port.pmpaddr_rdata[i] << 2);
          pmp_exist   = 1;
        end

        2'b10: begin  // NA4
          start_paddr = PADDR_WIDTH'(csr_port.pmpaddr_rdata[i] << 2);
          end_paddr   = start_paddr + PADDR_WIDTH'(4);
          pmp_exist   = 1;
        end

        2'b11: begin  // NAPOT
          for (int unsigned j = 0; j < PADDR_WIDTH - 2; j++) begin
            if (csr_port.pmpaddr_rdata[i][j] == 0) break;
            napot_counter++;
            napot_mask[j] = 1'b0;
          end
          start_paddr = PADDR_WIDTH'((csr_port.pmpaddr_rdata[i] & napot_mask) << 2);
          end_paddr   = start_paddr + (PADDR_WIDTH'(1) << (napot_counter + 2));
          pmp_exist   = 1;
        end

        default: begin
          start_paddr = '0;
          end_paddr   = '0;
        end
      endcase

      if (start_paddr <= target_paddr && target_paddr < end_paddr) begin
        pmp_result = '{valid: 1, R: R, W: W, X: X, L: L};
        break;
      end
    end

    //許可 / 不許可の判定

    // 有効な PMP エントリが一つも無い → どの特権レベルでも全部許可
    if (!pmp_exist) begin
      return 0;
    end

    // 少なくとも1つPMPエントリがある

    // マッチしなかった場合
    if (!pmp_result.valid) begin
      if (current_priv == M_MODE) begin
        // M-mode: no-match でも常に許可
        return 0;
      end else begin
        // S/U-mode: no-match は fault
        return 1;
      end
    end

    // M-mode かつ L=0 のエントリ → 制限しない（R/W/X 無視で許可）
    if (current_priv == M_MODE && !pmp_result.L) begin
      return 0;
    end

    // それ以外（S/U-mode 全部 + M-mode & L=1）は R/W/X でチェック
    // 要求されたアクセス種別のすべてについてビットが立っている必要がある
    if (is_read && !pmp_result.R) return 1;
    if (is_write && !pmp_result.W) return 1;
    if (is_exe && !pmp_result.X) return 1;

    return 0;
  endfunction


  // --------------------------------------------------------------------------
  // check_exception
  // --------------------------------------------------------------------------

  typedef struct packed {
    logic valid;
    logic [5:0] cause;
    logic [XLEN-1:0] tval;
  } exception_info_t;

  // コミット前に,その命令がいずれかのexception要件を満たしているかを確認する.
  // 優先順位は.
  // 3. BreakPoint (opcode)
  // 12. Instruction page fault (is_page_fault_instr)
  // 1. Instruction access fault (is_access_fault_instr)
  // 2. Illegal instruction (opcode)
  // 0. Instruction address misalignment (target_address_misaligned)
  // 8. Enviroment call from U_MODE (opcode)
  // 9. Enviroment call from S_MODE (opcode)
  // 11. Enviroment call from M_MODE (opcode)
  // 13. Load page fault (is_page_fault_ldst)
  // 15. Store/AMO page fault (is_page_fault_ldst)
  // 5. Load access fault (access_fault_ldst)
  // 7. Store/AMO access fault (access_fault_ldst)
  // 4. Load address misalignment (target_address_misalignment)
  // 6. Store/AMO address misalignment (target_address_misalignment)
  //
  function automatic exception_info_t check_exception(input activelist_t al_entry);
    exception_info_t exception_result = '{default: 0};


    // $display("=======================================");
    // $display("  [Basic] PC:0x%016h | Op:%-12s | RawOp:0x%08h | Done:%b", al_entry.addr,
    //          al_entry.opcode.name(), al_entry.raw_op, al_entry.done);
    // $display("  [Regs ] HasRd:%b | L_Rd:x%0d -> P_Rd:p%0d (Prev:p%0d) | RdVal:0x%016h",
    //          al_entry.has_rd, al_entry.logical_rd, al_entry.physical_rd,
    //          al_entry.previous_physical_rd, al_entry.rd_val);
    // $display("  [Brnch] Mispred:%b | Pred:%b (Tgt:0x%016h) | Actual:%b (Tgt:0x%016h)",
    //          al_entry.misprediction, al_entry.pred_taken, al_entry.pred_taken_addr,
    //          al_entry.actual_taken, al_entry.actual_taken_addr);
    // $display("  [Excep] Valid:%b | Cause:%2d | Tval:0x%016h | I-PageFault:%b | I-AccFault:%b",
    //          al_entry.exception, al_entry.cause, al_entry.tval, al_entry.is_page_fault_instr,
    //          al_entry.is_access_fault_instr);
    // $display(
    //     "  [LSU  ] TgtPaddr:0x%016h | RawHaz:%b | Misalign:%b | D-PageFault:%b | D-AccFault:%b",
    //     al_entry.ldst_target_addr, al_entry.raw_hazard, al_entry.target_address_misalignment,
    //     al_entry.is_page_fault_ldst, al_entry.is_access_fault_ldst);
    // $display("  [Misc ] FenceI_Sig:%b | AmoLdDone:%b", al_entry.fencei_sig_made,
    //          al_entry.amo_ld_done);



    // 優先順位の低い順番で更新していく.

    // 6. Store/AMO address misalignment
    if (al_entry.target_address_misalignment && (is_st_opcode(
            al_entry.opcode
        ) && is_amo_opcode(
            al_entry.opcode
        ))) begin
      exception_result = '{valid: 1, cause: 6, tval: XLEN'(signed'(al_entry.ldst_target_addr))};
    end

    // 4. Load address misalignment
    if (al_entry.target_address_misalignment && is_ld_opcode(al_entry.opcode)) begin
      exception_result = '{valid: 1, cause: 4, tval: XLEN'(signed'(al_entry.ldst_target_addr))};
    end

    // 7. Store/AMO access fault
    // st/amoからの返却に基づいて更新.
    if (al_entry.is_access_fault_ldst && (is_st_opcode(
            al_entry.opcode
        ) || is_amo_opcode(
            al_entry.opcode
        ))) begin
`ifdef MAINLOG_EN
      $fdisplay(fp_mainlog, "[LOG][Renamer.sv] st/amo access fault by lsu. target_addr:%010h",
                XLEN'(signed'(al_entry.ldst_target_addr)));
`endif
      exception_result = '{valid: 1, cause: 7, tval: XLEN'(signed'(al_entry.ldst_target_addr))};
    end
    // pmpに基づいて更新.
    if ((is_st_opcode(
            al_entry.opcode
        ) || is_amo_opcode(
            al_entry.opcode
        )) && pmp_access_fault(
            al_entry.ldst_target_addr, priv_rval, 0, 1, 0
        )) begin
`ifdef MAINLOG_EN
      $fdisplay(fp_mainlog, "[LOG][Renamer.sv] st/amo access fault by pmp. target_addr:%010h",
                XLEN'(signed'(al_entry.ldst_target_addr)));
`endif
      exception_result = '{valid: 1, cause: 7, tval: XLEN'(signed'(al_entry.addr))};
    end

    // メインメモリの範囲の外にアクセスした場合はaccess_fault


    // 5. load access fault
    // ldからの返却に基づいて更新.
    if (al_entry.is_access_fault_ldst && is_ld_opcode(al_entry.opcode)) begin
      exception_result = '{valid: 1, cause: 5, tval: XLEN'(signed'(al_entry.ldst_target_addr))};
    end
    // pmpに基づいて更新.
    if (is_ld_opcode(
            al_entry.opcode
        ) && pmp_access_fault(
            al_entry.ldst_target_addr, priv_rval, 1, 0, 0
        )) begin
      exception_result = '{valid: 1, cause: 5, tval: XLEN'(signed'(al_entry.addr))};
    end

    // 15. Store/AMO page fault
    if (al_entry.is_page_fault_ldst && (is_st_opcode(
            al_entry.opcode
        ) || is_amo_opcode(
            al_entry.opcode
        ))) begin
      // $display("[LOG][%s,%-d] Store/AMO Page fault ldst_target_addr:%016h", `__FILE__, `__LINE__,
      //          XLEN'(signed'(al_entry.ldst_target_addr[VADDR_WIDTH-1:0])));
      exception_result = '{
          valid: 1,
          cause: 15,
          tval: XLEN'(signed'(al_entry.ldst_target_addr[VADDR_WIDTH-1:0]))
      };
    end


    // 13. Load page fault
    if (al_entry.is_page_fault_ldst && is_ld_opcode(al_entry.opcode)) begin
      exception_result = '{
          valid: 1,
          cause: 13,
          tval: XLEN'(signed'(al_entry.ldst_target_addr[VADDR_WIDTH-1:0]))
      };
    end


    // 11. Enviroment call from M_MODE (opcode)
    if (al_entry.opcode == ECALL && priv_rval == M_MODE) begin
      exception_result = '{valid: 1, cause: 11, tval: 0};
    end


    // 9. Enviroment call from S_MODE (opcode)
    if (al_entry.opcode == ECALL && priv_rval == S_MODE) begin
      exception_result = '{valid: 1, cause: 9, tval: 0};
    end


    // 8. Enviroment call from U_MODE (opcode)
    if (al_entry.opcode == ECALL && priv_rval == U_MODE) begin
      exception_result = '{valid: 1, cause: 8, tval: 0};
    end


    // 0. Instruction address misalignment (target_address_misaligned)
    if (al_entry.target_address_misalignment && (is_jmp_opcode(
            al_entry.opcode
        ) || is_branch_opcode(
            al_entry.opcode
        ))) begin
      exception_result = '{valid: 1, cause: 0, tval: XLEN'(signed'(al_entry.actual_taken_addr))};
    end

    // 2. Illegal instruction

    // 特権命令が不正な特権レベルで実行されている場合は例外とする
    if (al_entry.opcode == MRET) begin
      if (priv_rval != M_MODE) begin
        $display("[LOG][%s,%-d] MRET Exception. Running in %s", `__FILE__, `__LINE__,
                 priv_rval.name());
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
      end
    end

    if (al_entry.opcode == SRET) begin
      if (priv_rval == U_MODE || ((priv_rval == M_MODE) && csr_port.mstatus_rdata.as_mstatus.TSR)) begin
        $display("[LOG][%s,%-d] SRET Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
      end
    end

    // tw
    if (al_entry.opcode == WFI && csr_port.mstatus_rdata.as_mstatus.TW && priv_rval == S_MODE) begin
      $display("[LOG][%s,%-d] WFI while tw  Exception.", `__FILE__, `__LINE__);
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
    end


    // mstatus.tvmであるなら,sfenceはillegalである
    if (al_entry.opcode == SFENCE_VMA) begin
      if (priv_rval == U_MODE || (csr_port.mstatus_rdata.as_mstatus.TVM && priv_rval == S_MODE)) begin
        $display("[LOG][%s,%-d] SFENCE_VMA Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
      end
    end

    // 同様に,mstatus.tvmであるなら,satpへのsモードからのアクセスは禁止される.
    if (is_csr_opcode(
            al_entry.opcode
        ) && csr_name_e'(al_entry.raw_op[31:20]) == SATP && csr_port.mstatus_rdata.as_mstatus.TVM &&
            priv_rval == S_MODE) begin
      $display("[LOG][%s,%-d] SATP ACCESS while in tvm Exception.", `__FILE__, `__LINE__);
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
    end


    // counterenに基づいて,S_MODEからのアクセスを制御する.
    begin
      int unsigned corresponding_bit = 0;
      if (is_csr_opcode(
              al_entry.opcode
          ) && csr_name_e'(al_entry.raw_op[31:20]) inside {CYCLE, TIME, INSTRET,
                                                           [HPMCOUNTER3 : HPMCOUNTER31]}) begin
        case (csr_name_e'(al_entry.raw_op[31:20]))
          CYCLE:        corresponding_bit = 0;
          TIME:         corresponding_bit = 1;
          INSTRET:      corresponding_bit = 2;
          HPMCOUNTER3:  corresponding_bit = 3;
          HPMCOUNTER4:  corresponding_bit = 4;
          HPMCOUNTER5:  corresponding_bit = 5;
          HPMCOUNTER6:  corresponding_bit = 6;
          HPMCOUNTER7:  corresponding_bit = 7;
          HPMCOUNTER8:  corresponding_bit = 8;
          HPMCOUNTER9:  corresponding_bit = 9;
          HPMCOUNTER10: corresponding_bit = 10;
          HPMCOUNTER11: corresponding_bit = 11;
          HPMCOUNTER12: corresponding_bit = 12;
          HPMCOUNTER13: corresponding_bit = 13;
          HPMCOUNTER14: corresponding_bit = 14;
          HPMCOUNTER15: corresponding_bit = 15;
          HPMCOUNTER16: corresponding_bit = 16;
          HPMCOUNTER17: corresponding_bit = 17;
          HPMCOUNTER18: corresponding_bit = 18;
          HPMCOUNTER19: corresponding_bit = 19;
          HPMCOUNTER20: corresponding_bit = 20;
          HPMCOUNTER21: corresponding_bit = 21;
          HPMCOUNTER22: corresponding_bit = 22;
          HPMCOUNTER23: corresponding_bit = 23;
          HPMCOUNTER24: corresponding_bit = 24;
          HPMCOUNTER25: corresponding_bit = 25;
          HPMCOUNTER26: corresponding_bit = 26;
          HPMCOUNTER27: corresponding_bit = 27;
          HPMCOUNTER28: corresponding_bit = 28;
          HPMCOUNTER29: corresponding_bit = 29;
          HPMCOUNTER30: corresponding_bit = 30;
          HPMCOUNTER31: corresponding_bit = 31;
          default:      ;
        endcase

        if (!csr_port.mcounteren_rdata[corresponding_bit] && priv_rval == S_MODE) begin
          $display("[LOG] illegal instr detected in mcounteren restriction.");
          exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
        end

        if((!csr_port.mcounteren_rdata[corresponding_bit] || !csr_port.scounteren_rdata[corresponding_bit])
               && priv_rval == U_MODE)begin
          exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
        end

      end
    end


    // csrへアクセス可能なのは,現在の特権レベルがcsr[9:8]以上であるとき.そうでなければillegal instrに.
    if (is_csr_opcode(al_entry.opcode) && al_entry.raw_op[29:28] > priv_rval) begin
      $display("[LOG][%s,%-d] CSR ACCESS fault Exception.", `__FILE__, `__LINE__);
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
    end

    // is_csr_write
    // riscv-unprivileged.pdf, page50
    begin
      logic is_write_csr = 0;
      if (al_entry.opcode == CSRRW) begin
        is_write_csr = 1;
      end else if (al_entry.opcode inside {CSRRS, CSRRC} && al_entry.raw_op[19:15] != 0) begin
        is_write_csr = 1;
      end else if (al_entry.opcode == CSRRWI) begin
        is_write_csr = 1;
      end else if (al_entry.opcode inside {CSRRSI, CSRRCI} && al_entry.raw_op[19:15] != 0) begin
        is_write_csr = 1;
      end

      // 書き込み専用レジスタに書き込みを行おうとした場合,illegal instrにする.
      if (is_csr_opcode(al_entry.opcode) && al_entry.raw_op[31:30] == 2'b11 && is_write_csr) begin
        $display("[LOG][%s,%-d] CSR WRITE fault Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_entry.raw_op}};
      end
    end

    // 1. Instruction access fault (is_access_fault_instr)
    if (al_entry.is_access_fault_instr) begin
      exception_result = '{valid: 1, cause: 1, tval: XLEN'(signed'(al_entry.addr))};
    end

    // 12. Instruction page fault (is_page_fault_instr)
    if (al_entry.is_page_fault_instr) begin
      exception_result = '{valid: 1, cause: 12, tval: XLEN'(signed'(al_entry.addr))};
    end


    // 3. BreakPoint
    if (al_entry.opcode == EBREAK) begin
      //EBREAKはtval自由.
      exception_result = '{valid: 1, cause: 3, tval: 0};
    end

    return exception_result;

  endfunction

  // ----------------------------------------------------------------------------
  // debug log
  // ----------------------------------------------------------------------------
  int fp_commitlog;
  int fp_mainlog;
  int fp_addrlog;
  initial begin
`ifdef COMMITLOG_EN
    fp_commitlog = $fopen("./log/commitlog.txt", "w");
    fp_addrlog   = $fopen("./log/addrlog.txt", "w");
`endif
`ifdef MAINLOG_EN
    fp_mainlog = $fopen("./log/mainlog.txt", "w");
`endif
  end
  typedef struct packed {
    logic valid;
    logic [38:0] addr;
    opcode_t opcode;
    logic rs1_exist;
    logic rs2_exist;
    logic rd_exist;
    abi_name_e rs1_abi;
    abi_name_e rs2_abi;
    abi_name_e rd_abi;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rd;
    logic [XLEN-1:0] rd_val;
  } commitlog_t;
  commitlog_t commitlog[NUM_OF_GRADUATE];


  always_comb begin


    generation_next           = generation;
    op_out_next               = '{default: 0};

    committed_rd_valid        = '{default: 0};
    committed_phyreg          = '{default: 0};
    committed_prev_phyreg     = '{default: 0};
    flush_fl                  = 1'b0;
    al_flush                  = 1'b0;

    priv_w                    = '{default: 0, val: S_MODE};

    csr_port.sepc_w           = '{default: 0};
    csr_port.scause_w         = '{default: 0};
    csr_port.stval_w          = '{default: 0};
    csr_port.sstatus_w        = '{default: 0};
    csr_port.mepc_w           = '{default: 0};
    csr_port.mcause_w         = '{default: 0};
    csr_port.mtval_w          = '{default: 0};
    csr_port.mstatus_w        = '{default: 0};

    rat_next                  = rat;
    rrat_next                 = rrat;
    al_next                   = al;

    al_rp_next                = al_rp;
    al_wp_next                = al_wp;
    num_of_entries_in_al_next = num_of_entries_in_al;

    // 
    lrsc_lock_next            = lrsc_lock;


    invalidate_l1cache_next   = 0;

    // FORDEBUG
    commitlog                 = '{default: 0};

    // -------------------------------------------------------------
    // op_in => op_out, al_next
    // -------------------------------------------------------------
    // op_inからop_outを製作し,al_nextを更新する.
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      lsu_port.new_instr[i] = '{default: 0, opcode: NOP};
      prd_used[i] = 0;
    end
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      logic [AL_IDX_WIDTH-1:0] al_idx = 0;
      logic [5:0] cause = 0;
      logic [XLEN-1:0] tval = 0;
      pmp_result_t pmp_result = '{default: 0};

      if (op_in[i].valid) begin

        // op_in => op_out
        // ただし以下の命令ではdispatchしない.
        if(op_in[i].opcode inside {MRET, SRET,WFI, FENCE, FENCE_I,SFENCE_VMA, ECALL, EBREAK, ILLEGAL_INSTR})begin
          op_out_next[i] = '{valid: 0, opcode: NOP, default: 0};
        end else begin
          op_out_next[i] = '{
              valid: 1,
              opcode: op_in[i].opcode,
              op_addr: op_in[i].vaddr,
              rs1_exist: op_in[i].rs1_exist,
              rs2_exist: op_in[i].rs2_exist,
              rd_exist: op_in[i].rd_exist,
              rs1: rat_next[op_in[i].rs1],
              rs2: rat_next[op_in[i].rs2],
              rd: op_in[i].rd_exist && op_in[i].rd != 0 ? available_prd[i] : 0,
              imm: op_in[i].imm,
              al_idx: al_wp_next
          };
        end

        // op_in => lsu_port.new_instr
        if (op_in[i].opcode == FENCE) begin
          // TODO: immからsi,so,...の指定
          lsu_port.new_instr[i] = '{
              valid: 1,
              op_addr: op_in[i].vaddr,
              al_idx: al_wp_next,
              opcode: op_in[i].opcode,
              si: 1,
              so: 1,
              sr: 1,
              sw: 1
          };
        end else begin
          lsu_port.new_instr[i] = '{
              valid: 1,
              op_addr: op_in[i].vaddr,
              al_idx: al_wp_next,
              opcode: op_in[i].opcode,
              default: 0
          };
        end


        // op_in => al_next
        // al_nextにop_inを追加する.
        // SRET,MRETは特に処理が無いのでdone==1でいい
        // fenceも前に発行されたst/ldが卒業済なら自動的に役目を終えてるのでdone=1
        if (op_in[i].opcode inside {ILLEGAL_INSTR, ECALL, EBREAK}) begin
          al_next[al_wp_next] = '{
              addr: op_in[i].vaddr,
              opcode: op_in[i].opcode,
              has_rd: op_in[i].rd_exist,
              logical_rd: op_in[i].rd,
              physical_rd: op_in[i].rd != 0 ? available_prd[i] : 0,
              previous_physical_rd: rat_next[op_in[i].rd],
              done: 1,
              pred_taken: op_in[i].pred_taken,
              pred_taken_addr: op_in[i].btb_addr,
              actual_taken: 0,
              actual_taken_addr: 0,
              misprediction: 0,
              exception: 1,
              cause: 0,
              tval: 0,

              is_page_fault_instr: op_in[i].is_page_fault,
              is_access_fault_instr: op_in[i].is_access_fault,

              raw_hazard: 0,
              fencei_sig_made: 0,
              amo_ld_done: 0,
              ldst_target_addr: 0,
              is_page_fault_ldst: 0,
              is_access_fault_ldst: 0,
              target_address_misalignment: 0,

              raw_op: op_in[i].raw_op,

              has_rs1: 0,
              has_rs2: 0,
              logical_rs1: 0,
              logical_rs2: 0,
              physical_rs1: 0,
              physical_rs2: 0,
              rd_val: 0
          };
        end else if (op_in[i].opcode inside {MRET, SRET, WFI, FENCE, SFENCE_VMA}) begin
          // MRET,SRET,FENCEはILLEGAL_INSTR,Ecall,ebreakと同様にdispatchを行わないが,exceptionも無い.
          al_next[al_wp_next] = '{
              addr: op_in[i].vaddr,
              opcode: op_in[i].opcode,
              has_rd: op_in[i].rd_exist,
              logical_rd: op_in[i].rd,
              physical_rd: op_in[i].rd != 0 ? available_prd[i] : 0,
              previous_physical_rd: rat_next[op_in[i].rd],
              done: 1,
              pred_taken: op_in[i].pred_taken,
              pred_taken_addr: op_in[i].btb_addr,
              actual_taken: 0,
              actual_taken_addr: 0,
              misprediction: 0,
              exception: 0,
              cause: 0,
              tval: 0,

              is_page_fault_instr: op_in[i].is_page_fault,
              is_access_fault_instr: op_in[i].is_access_fault,

              raw_hazard: 0,
              fencei_sig_made: 0,
              amo_ld_done: 0,
              ldst_target_addr: 0,
              is_page_fault_ldst: 0,
              is_access_fault_ldst: 0,
              target_address_misalignment: 0,
              raw_op: op_in[i].raw_op,

              has_rs1: 0,
              has_rs2: 0,
              logical_rs1: 0,
              logical_rs2: 0,
              physical_rs1: 0,
              physical_rs2: 0,
              rd_val: 0
          };
        end else if (op_in[i].opcode == FENCE_I) begin
          // FENCE_I はdispatchしないが,fenceより前の命令がすべてコミットしたらl1cacheをinvalidateする処理があるので,
          // 元からdoneにはしない.
          al_next[al_wp_next] = '{
              addr: op_in[i].vaddr,
              opcode: op_in[i].opcode,
              has_rd: 0,
              logical_rd: 0,
              physical_rd: 0,
              previous_physical_rd: 0,
              done: 0,
              pred_taken: op_in[i].pred_taken,
              pred_taken_addr: op_in[i].btb_addr,
              actual_taken: 0,
              actual_taken_addr: 0,
              misprediction: 0,
              exception: 0,
              cause: 0,
              tval: 0,

              is_page_fault_instr: op_in[i].is_page_fault,
              is_access_fault_instr: op_in[i].is_access_fault,
              raw_hazard: 0,
              fencei_sig_made: 0,
              amo_ld_done: 0,
              ldst_target_addr: 0,
              is_page_fault_ldst: 0,
              is_access_fault_ldst: 0,
              target_address_misalignment: 0,
              raw_op: op_in[i].raw_op,


              has_rs1: 0,
              has_rs2: 0,
              logical_rs1: 0,
              logical_rs2: 0,
              physical_rs1: 0,
              physical_rs2: 0,
              rd_val: 0
          };
        end else begin
          // その他普通の命令.
          al_next[al_wp_next] = '{
              addr: op_in[i].vaddr,
              opcode: op_in[i].opcode,
              has_rd: op_in[i].rd_exist,
              logical_rd: op_in[i].rd,
              physical_rd: op_in[i].rd != 0 ? available_prd[i] : 0,
              previous_physical_rd: rat_next[op_in[i].rd],
              done: 0,
              pred_taken: op_in[i].pred_taken,
              pred_taken_addr: op_in[i].btb_addr,
              actual_taken: 0,
              actual_taken_addr: 0,
              misprediction: 0,
              exception: 0,
              cause: 0,
              tval: 0,
              is_page_fault_instr: op_in[i].is_page_fault,
              is_access_fault_instr: op_in[i].is_access_fault,
              raw_hazard: 0,
              fencei_sig_made : 0,
              amo_ld_done: 0,
              ldst_target_addr: 0,
              is_page_fault_ldst: 0,
              is_access_fault_ldst: 0,
              target_address_misalignment: 0,
              raw_op: op_in[i].raw_op,


              has_rs1: op_in[i].rs1_exist,
              has_rs2: op_in[i].rs2_exist,
              logical_rs1: op_in[i].rs1,
              logical_rs2: op_in[i].rs2,
              physical_rs1: rat_next[op_in[i].rs1],
              physical_rs2: rat_next[op_in[i].rs2],
              rd_val: 0
          };
        end

        // いずれの命令にしろ,PMPで指定されている範囲外から取ってきた場合はaccess_faultを出す.
        // TODO:pmp
        if (pmp_access_fault(op_in[i].paddr, priv_rval, 1, 0, 0)) begin
          $display("[LOG][%s,%-d] pmp_result:%b", `__FILE__, `__LINE__, pmp_result);
          al_next[al_wp_next].is_access_fault_instr = 1;
        end


        // al_wpの更新.
        al_wp_next = AL_IDX_WIDTH'(al_wp_next + AL_IDX_WIDTH'(1'b1));
        num_of_entries_in_al_next++;

        // ratの更新をここでしておくと後続の命令のrsを変換できる.
        if (op_in[i].rd_exist && op_in[i].rd != 0) begin
          rat_next[op_in[i].rd] = available_prd[i];
          prd_used[i] = 1;
        end else begin
          prd_used[i] = 0;
        end

      end
    end

    // -------------------------------------------------------------
    // 処理が終了した命令のフィードバックによるアクティブリスト更新処理.
    // -------------------------------------------------------------
    // feedbacks => al_next
    for (int unsigned i = 0; i < NUM_OF_RESULT_FEEDBACKS; i++) begin
      logic [AL_IDX_WIDTH-1:0] al_idx = 0;
      if (feedback_op[i].valid) begin
        al_idx = feedback_op[i].al_idx;

        // amo命令のロードが帰ってきた場合,phyregのrdの更新などは行うが,doneにはしない.
        // なぜなら,amo命令のストア部分が仮実行したときにdoneにするべきだから.
        if (is_amo_opcode(al_next[al_idx].opcode)) begin
          if (al_next[al_idx].amo_ld_done) begin
            // amoのst部
            al_next[al_idx].done = 1;
          end else begin
            // amoのld部
            al_next[al_idx].amo_ld_done = 1;
          end
        end else begin
          al_next[al_idx].done = 1;
          al_next[al_idx].actual_taken = feedback_op[i].actual_taken;
          al_next[al_idx].actual_taken_addr = feedback_op[i].actual_taken_addr;
          al_next[al_idx].ldst_target_addr = feedback_op[i].ldst_target_addr;
          al_next[al_idx].rd_val = feedback_op[i].rd_val;

          // 分岐予測失敗(misprediction)
          // pred_takenとactual_takenが間違っているか,
          // pred_takenかつactual_takenだが,飛び先のアドレスが間違っている場合.
          if(al_next[al_idx].pred_taken != feedback_op[i].actual_taken ||
                   (al_next[al_idx].pred_taken == 1 &&  feedback_op[i].actual_taken == 1 && 
                    al_next[al_idx].pred_taken_addr != feedback_op[i].actual_taken_addr)) begin
            al_next[al_idx].misprediction = 1;
          end


          // jmp,branchの飛び先のmisalignment
          if ((is_jmp_opcode(
                  al_next[al_idx].opcode
              ) || is_branch_opcode(
                  al_next[al_idx].opcode
              )) && feedback_op[i].actual_taken &&
                  feedback_op[i].actual_taken_addr[1:0] != 2'b00) begin
            al_next[al_idx].target_address_misalignment = 1;
          end

          // ld命令の場合,misalignedmentの判別.
          if (is_ld_opcode(al_next[al_idx].opcode)) begin
            case (get_data_size_from_opcode(
                al_next[al_idx].opcode
            ))
              1: begin
                // misalignmentは存在しない.
              end
              2: begin
                if (feedback_op[i].ldst_target_addr[0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              4: begin
                if (feedback_op[i].ldst_target_addr[1:0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              8: begin
                if (feedback_op[i].ldst_target_addr[2:0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              default: $display("[LOG][%s,%-d]", `__FILE__, `__LINE__);
            endcase
          end

          // st,amoのalignment判別.
          if (is_st_opcode(al_next[al_idx].opcode) || is_amo_opcode(al_next[al_idx].opcode)) begin
            case (get_data_size_from_opcode(
                al_next[al_idx].opcode
            ))
              1: begin
                // misalignmentは存在しない.
              end
              2: begin
                if (feedback_op[i].ldst_target_addr[0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              4: begin
                if (feedback_op[i].ldst_target_addr[1:0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              8: begin
                if (feedback_op[i].ldst_target_addr[2:0] != 0) begin
                  al_next[al_idx].target_address_misalignment = 1;
                end
              end
              default: $display("[LOG][%s,%-d]", `__FILE__, `__LINE__);
            endcase
          end

          // ldstのpagefault, access faultの更新.
          al_next[al_idx].is_page_fault_ldst   = feedback_op[i].is_page_fault;
          al_next[al_idx].is_access_fault_ldst = feedback_op[i].is_access_fault;


        end

      end
    end


    // ---------------------------------------------------------
    // al_nextでcacheのinvalidate処理が終わったfence.i命令を更新
    // -----------------------------------------------------------
    // invalidate_doneが帰ってくるときは必ず先頭はfence.iのはずだが一応
    if (al_next[al_rp_next].opcode == FENCE_I && invalidate_l1cache_done) begin
      al_next[al_rp_next].done = 1;
    end


    // -----------------------------------------------------------
    // LSUでのrawハザード検知でのアクティブリスト更新処理
    // -----------------------------------------------------------
    // 本当はrenamerから全体に対してflushの命令を送るのではなく,ld以降の命令のみをやり直せばいいのだが,
    // 実装が面倒なので,そのldの命令より前の命令がコミット終了するまで待ってからflushしてやり直す.
    if (lsu_port.ld_speculative_feedback_valid) begin
      al_next[lsu_port.ld_speculative_feedback_al_idx].raw_hazard = 1;
    end


    // --------------------------------------------------------
    // アクティブリストからの卒業処理等
    // --------------------------------------------------------
    // 具体的にはアクティブリストからの卒業,feedback_to_btb_predの作成,rratの更新,
    begin
      // 処理は種類
      // ① S-Modeで実行されるInterrupt
      // ② M-Modeで実行されるInterrupt
      // ③ S-modeで実行されるexception
      // ④ M-modeで実行されるexception
      // ⑤ lsuでのrawハザード検出
      // ⑥ FENCE_I
      // ⑦ misprediction
      // ⑧ CSR
      // ⑨ SRET
      // ⑩ MRET
      // ⑪ FENCE_VMA
      // ⑫ 通常コミット
      // この内,①,②,③,④,⑤の場合はコミットを行わないが,他の命令では全てコミットされる.
      // この内,⑩以外は(コミットが行われるなら)コミット後にalやflをflushしてbreakする.
      logic commit_op = 0;
      logic flush_al_fl_and_break = 0;

      int unsigned st_commit_counter = 0;
      logic st_commitable = 0;

      int unsigned extracted_cause = 0;

      exception_info_t exception_result = '{default: 0};

      csr_reg_u minstret_next = csr_port.minstret_rdata;



      // => CSRUnit, LSU
      lsu_port.committed_instr = '{default: 0};
      lsu_port.sc_mmio_executable = '{default: 0, opcode: NOP};
      // csru_port_committed_instr_next = '{default: 0};
      // csru_port_executable_csr_next = '{default: 0};
      csru_port.committed_instr = '{default: 0};
      csru_port.executable_csr = '{default: 0};

      // feedback, flush
      misprediction_feedback_to_btb = '{default: 0};
      is_taken_feedback_to_pred = '{default: 0};
      flush_from_renamer = '{default: 0};

      // 特権レベル変更.
      priv_w = '{en: 0, val: M_MODE};

      flush_tlb = 0;


      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin

        // st命令の場合は,commit可能かを確認する.st命令で無いならst_commitableは1.
        st_commitable = !is_st_opcode(al_next[al_rp_next].opcode) ||
            (st_commit_counter < NUM_OF_ST_EXE && !dcache_noroom);

        if (num_of_entries_in_al_next > 0 && al_next[al_rp_next].done && st_commitable) begin
          // 割り込み以外(③~⑫),のalに登録されている命令の処理.
          // $display("[LOG] [%s,%-d] AL Commit Processing. Addr:0x%016h Opcode:%s ", `__FILE__,
          //          `__LINE__, al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name());
          //

          // 例外チェック.
          exception_result = check_exception(al_next[al_rp_next]);
          if (exception_result.valid) begin
            al_next[al_rp_next].exception = 1;
            al_next[al_rp_next].cause = exception_result.cause;
            al_next[al_rp_next].tval = exception_result.tval;
          end



          // mmioは絶対にロールバックすることができない。st命令はコミット後にmmioに出されるからいいが、
          // ldはコミット前にmmioに出される.alの先頭なら確実にコミットするからいいじゃないかと思うかもしれないが、
          // 割り込みという問題がある。mmioにリクエストを出したのに割り込みが入ってmmioへのリクエストをロールバックしたいです,
          // なんてことになったら駄目だ.
          // 割り込みを行える条件に「ALの先頭がld/st命令で無い」を追加する.割り込みを行っては行けないのは,前のサイクルまでに
          // mmioへのld/st命令を実行可能信号をsc_mmio_executableで出している場合で,この場合、このサイクルでの先頭は必ずld/st命令になる.
          // だからalの先頭がld/st命令なら割り込みができないようにする.
          if (!is_ld_opcode(
                  al_next[al_rp_next].opcode
              ) && !is_st_opcode(
                  al_next[al_rp_next].opcode
              ) && ((csr_port.mstatus_rdata.as_mstatus.SIE && priv_rval == S_MODE) ||
                    priv_rval == U_MODE) &&
                  ((csr_port.mideleg_rdata & csr_port.sie_rdata & csr_port.sip_rdata) != 0)) begin
            //① S-Mode割り込み.

            // causeの値を探索.
            for (int unsigned j = 0; j < XLEN; j++) begin
              if (csr_port.mideleg_rdata[j] & csr_port.sie_rdata[j] & csr_port.sip_rdata[j]) begin
                extracted_cause = j;
              end
            end

`ifdef MAINLOG_EN
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Interruption handling in S-MODE Cause:%2d stvec:%016h, current_priv:%b",
                extracted_cause, {csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, priv_rval);
`endif
`ifdef COMMITLOG_EN
            $fdisplay(
                fp_commitlog,
                "[LOG] Interruption handling in S-MODE Cause:%2d stvec:%016h, current_priv:%b, stimecmp:%016h",
                extracted_cause, {csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, priv_rval,
                csr_port.stimecmp_rdata);
`endif

            // $display(
            //     "[LOG] [Renamer.sv] Interruption handling in S-MODE Cause:%2d stvec:%016h, current_priv:%b",
            //     extracted_cause, {csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, priv_rval);
            // $display("[LOG] [Renamer.sv] sie:%016b sip:%016b, mideleg:%016b",
            //          csr_port.sie_rdata[15:0], csr_port.sip_rdata[15:0],
            //          csr_port.mideleg_rdata[15:0]);

            // num_of_entries_in_alが0より大きくないとコードが実行されないので,
            // al_next[al_rp_next]は割り込み処理を行う場合でも必ず存在する.よってal_next[].addrを用いる.
            csr_port.sepc_w.en = 1;
            csr_port.sepc_w.data = XLEN'(signed'(al_next[al_rp_next].addr));

            // scause
            csr_port.scause_w.en = 1;
            csr_port.scause_w.data.as_scause.INTERRUPT = 1;
            csr_port.scause_w.data.as_scause.EXCEPTION_CODE = 63'(extracted_cause);

            // stval
            csr_port.stval_w.en = 1;
            csr_port.stval_w.data.as_stval.STVAL = 0;

            // sstatus
            // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
            csr_port.sstatus_w.en = 1;
            csr_port.sstatus_w.data.as_uint = csr_port.sstatus_rdata.as_uint;
            // 割り込み,例外発生前の特権モード
            csr_port.sstatus_w.data.as_sstatus.SPP = priv_rval[0];
            csr_port.sstatus_w.data.as_sstatus.SPIE = csr_port.sstatus_rdata.as_sstatus.SIE;
            csr_port.sstatus_w.data.as_sstatus.SIE = 0;  // Supervisorレベルの割り込みを禁止.

            // 次のpcを指定.
            flush_from_renamer = '{
                valid: 1,
                addr:
                VADDR_WIDTH
                '(
                {
                csr_port.stvec_rdata.as_stvec.BASE
                ,
                2'b00
                } + (
                (csr_port.stvec_rdata.as_stvec.MODE == 1) ? (4 * extracted_cause) : 0
                )
                )
            };

            // 特権レベルの変更
            priv_w = '{en: 1, val: S_MODE};

            // commit,flush
            commit_op = 0;
            flush_al_fl_and_break = 1;
          end else if (!is_ld_opcode(
                  al_next[al_rp_next].opcode
              ) && !is_st_opcode(
                  al_next[al_rp_next].opcode
              ) && ((priv_rval == M_MODE && csr_port.mstatus_rdata.as_mstatus.MIE) ||
                    priv_rval inside {U_MODE, S_MODE}) &&
                  ((~csr_port.mideleg_rdata) & csr_port.mie_rdata & csr_port.mip_rdata) != 0) begin
            //② M-Mode割り込み.
            // midelegが0,つまり非移譲の時に実行される.

            // causeの値を探索.
            for (int unsigned j = 0; j < XLEN; j++) begin
              if (~csr_port.mideleg_rdata[j] & csr_port.mie_rdata[j] & csr_port.mip_rdata[j]) begin
                extracted_cause = j;
              end
            end

`ifdef MAINLOG_EN
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Interruption handling in M-MODE Cause:%2d mtvec:%016h, current_priv:%b",
                extracted_cause, {csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00}, priv_rval);
`endif
`ifdef COMMITLOG_EN
            $fdisplay(
                fp_commitlog,
                "[LOG] Interruption handling in M-MODE Cause:%2d mtvec:%016h, current_priv:%b",
                extracted_cause, {csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00}, priv_rval);
`endif

            // $display(

            //     "[LOG] [Renamer.sv] Interruption handling in M-MODE Cause:%2d mtvec:%016h, current_priv:%b",
            //     extracted_cause, {csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00}, priv_rval);

            // num_of_entries_in_alが0より大きくないとコードが実行されないので,
            // al_next[al_rp_next]は割り込み処理を行う場合でも必ず存在する.よってal_next[].addrを用いる.
            csr_port.mepc_w.en = 1;
            csr_port.mepc_w.data = XLEN'(signed'(al_next[al_rp_next].addr));

            // mcause
            csr_port.mcause_w.en = 1;
            csr_port.mcause_w.data.as_mcause.INTERRUPT = 1;
            csr_port.mcause_w.data.as_mcause.EXCEPTION_CODE = 63'(extracted_cause);

            // mtval
            csr_port.mtval_w.en = 1;
            csr_port.mtval_w.data.as_mtval.MTVAL = 0;

            // mstatus
            // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
            csr_port.mstatus_w.en = 1;
            csr_port.mstatus_w.data.as_uint = csr_port.mstatus_rdata.as_uint;
            // 割り込み,例外発生前の特権モード
            csr_port.mstatus_w.data.as_mstatus.MPP = priv_rval;
            csr_port.mstatus_w.data.as_mstatus.MPIE = csr_port.mstatus_rdata.as_mstatus.MIE;
            csr_port.mstatus_w.data.as_mstatus.MIE = 0;

            // 次のpcを指定.
            flush_from_renamer = '{
                valid: 1,
                addr:
                VADDR_WIDTH
                '(
                {
                csr_port.mtvec_rdata.as_mtvec.BASE
                ,
                2'b00
                } + (
                (csr_port.mtvec_rdata.as_mtvec.MODE == 1) ? (4 * extracted_cause) : 0
                )
                )
            };


            // 特権レベルの変更
            priv_w = '{en: 1, val: M_MODE};

            // commit,flush
            commit_op = 0;
            flush_al_fl_and_break = 1;
          end else 
          if (al_next[al_rp_next].exception && csr_port.medeleg_rdata.as_uint[al_next[al_rp_next].cause] &&
               (priv_rval == U_MODE || priv_rval ==S_MODE)) begin
            // ③ Sモードに移譲して例外.
`ifdef MAINLOG_EN
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Exception handling in S-MODE OP_Addr:%010h Cause:%2d tval:%016h stvec:%016h, is_page_fault_instr:%b, is_access_fault_instr:%b",
                al_next[al_rp_next].addr, al_next[al_rp_next].cause, al_next[al_rp_next].tval, {
                csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, al_next[al_rp_next].is_page_fault_instr,
                al_next[al_rp_next].is_access_fault_instr);
`endif
`ifdef COMMITLOG_EN
            $fdisplay(
                fp_commitlog,
                "[LOG] Exception handling in S-MODE OP_Addr:%010h Cause:%2d tval:%016h stvec:%016h, is_page_fault_instr:%b, is_access_fault_instr:%b",
                al_next[al_rp_next].addr, al_next[al_rp_next].cause, al_next[al_rp_next].tval, {
                csr_port.stvec_rdata.as_stvec.BASE, 2'b00}, al_next[al_rp_next].is_page_fault_instr,
                al_next[al_rp_next].is_access_fault_instr);
`endif

            // 戻り先のpcの保管.
            csr_port.sepc_w.en = 1;
            csr_port.sepc_w.data.as_sepc.SEPC = XLEN'(signed'(al_next[al_rp_next].addr));

            // scause
            csr_port.scause_w.en = 1;
            csr_port.scause_w.data.as_scause.INTERRUPT = 0;
            csr_port.scause_w.data.as_scause.EXCEPTION_CODE = 63'(al_next[al_rp_next].cause);

            // stval
            csr_port.stval_w.en = 1;
            csr_port.stval_w.data.as_stval.STVAL = al_next[al_rp_next].tval;

            // sstatus
            // 一部を更新するだけなので,前の値を読み出して必要な部分だけ更新したデータを書き込む.
            csr_port.sstatus_w.en = 1;
            csr_port.sstatus_w.data.as_uint = csr_port.sstatus_rdata.as_uint;
            // 割り込み,例外発生前の特権モード
            csr_port.sstatus_w.data.as_sstatus.SPP = priv_rval[0];
            csr_port.sstatus_w.data.as_sstatus.SPIE = csr_port.sstatus_rdata.as_sstatus.SIE;
            csr_port.sstatus_w.data.as_sstatus.SIE = 0;  // Supervisorレベルの割り込みを禁止.

            // 次のpcを指定.
            flush_from_renamer = '{
                valid: 1,
                addr: VADDR_WIDTH'({csr_port.stvec_rdata.as_stvec.BASE, 2'b00})
            };


            // 特権レベルの変更
            priv_w = '{en: 1, val: S_MODE};

            // commit,flush
            commit_op = 0;
            flush_al_fl_and_break = 1;


          end else if (al_next[al_rp_next].exception) begin
            // ④ Mモードで例外
`ifdef MAINLOG_EN
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Exception handling in M-MODE OP_Addr:%010h Cause:%2d tval:%016h stvec:%016h, is_page_fault_instr:%b, is_access_fault_instr:%b",
                al_next[al_rp_next].addr, al_next[al_rp_next].cause, al_next[al_rp_next].tval, {
                csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00}, al_next[al_rp_next].is_page_fault_instr,
                al_next[al_rp_next].is_access_fault_instr);
`endif
`ifdef COMMITLOG_EN
            $fdisplay(
                fp_commitlog,
                "[LOG] [Renamer.sv] Exception handling in M-MODE OP_Addr:%010h Cause:%2d tval:%016h stvec:%016h, is_page_fault_instr:%b, is_access_fault_instr:%b",
                al_next[al_rp_next].addr, al_next[al_rp_next].cause, al_next[al_rp_next].tval, {
                csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00}, al_next[al_rp_next].is_page_fault_instr,
                al_next[al_rp_next].is_access_fault_instr);
`endif
            // mepc
            csr_port.mepc_w.en = 1;
            csr_port.mepc_w.data.as_mepc.MEPC = XLEN'(signed'(al_next[al_rp_next].addr));

            // mcause
            csr_port.mcause_w.en = 1;
            csr_port.mcause_w.data.as_mcause.INTERRUPT = 0;
            csr_port.mcause_w.data.as_mcause.EXCEPTION_CODE = 63'(al_next[al_rp_next].cause);

            // mtval
            csr_port.mtval_w.en = 1;
            csr_port.mtval_w.data.as_mtval.MTVAL = al_next[al_rp_next].tval;

            // mstatus
            csr_port.mstatus_w.en = 1;
            csr_port.mstatus_w.data.as_uint = csr_port.mstatus_rdata.as_uint;
            csr_port.mstatus_w.data.as_mstatus.MPP = priv_rval;  // Machine Previous Priv
            csr_port.mstatus_w.data.as_mstatus.MPIE = csr_port.mstatus_rdata.as_mstatus.MIE;   // 割り込み,例外発生前のMIEがMPIE
            csr_port.mstatus_w.data.as_mstatus.MIE = 0;  // Machine Interrupt Enable

            // 次のpcを指定
            flush_from_renamer = '{
                valid: 1,
                addr: VADDR_WIDTH'({csr_port.mtvec_rdata.as_mtvec.BASE, 2'b00})
            };


            // 特権レベルの変更
            priv_w = '{en: 1, val: M_MODE};

            // commit,flush
            commit_op = 0;
            flush_al_fl_and_break = 1;

          end else if (al_next[al_rp_next].raw_hazard) begin
            // ⑤ LSUでのrawハザード検出
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog,
                      "[LOG] [Renamer.sv] RAW hazard detected. OP_Addr:%010h  AL_idx:%h  Opcode:%s",
                      al_next[al_rp_next].addr, al_rp_next, al_next[al_rp_next].opcode.name());
`endif
            // この命令は卒業せずにやり直すが,int issue queueがlwtで実行を止めるので同じことの繰り返しでは無い.
            flush_from_renamer = '{valid: 1, addr: al_next[al_rp_next].addr};
            // commit,flush
            commit_op = 0;
            flush_al_fl_and_break = 1;

          end else if (al_next[al_rp_next].opcode == FENCE_I) begin
            // ⑥ FENCE_I
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] FENCE_I committed. OP_Addr:%010h  AL_idx:%h ",
                      al_next[al_rp_next].addr, al_rp_next,);
`endif
            flush_from_renamer = '{valid: 1, addr: al_next[al_rp_next].addr + 4};
            commit_op = 1;
            flush_al_fl_and_break = 1;
          end else if (al_next[al_rp_next].misprediction) begin
            // ⑦ 予測失敗
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] Addr:%010h, misprediction occured",
                      al_next[al_rp_next].addr);
            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] Addr:%010h, Opcode:%s, rd:%h, rd_val:%016h",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                      al_next[al_rp_next].physical_rd, al_next[al_rp_next].rd_val);
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Addr:%016h, pred_taken:%b, pred_taken_addr:%016h, actual_taken:%b, actual_taken_addr:%016h",
                al_next[al_rp_next].addr, al_next[al_rp_next].pred_taken,
                al_next[al_rp_next].pred_taken_addr, al_next[al_rp_next].actual_taken,
                al_next[al_rp_next].actual_taken_addr);
`endif
            // btbの更新用
            // 予測が失敗して,かつ実際にはtakenだった場合のみbtbは更新される.
            misprediction_feedback_to_btb = '{
                valid: al_next[al_rp_next].actual_taken ? 1 : 0,
                op_addr: al_next[al_rp_next].addr,
                dest_addr: al_next[al_rp_next].actual_taken_addr
            };

            // predictorの更新用.
            is_taken_feedback_to_pred[i] = '{
                valid: 1,
                op_addr: al_next[al_rp_next].addr,
                taken: al_next[al_rp_next].actual_taken
            };

            // この命令までは卒業したのでアクティブリストに入っている後続の命令は消していい.
            flush_from_renamer = '{
                valid: 1,
                addr:
                al_next[al_rp_next].actual_taken
                ?
                al_next[al_rp_next].actual_taken_addr
                :
                al_next[al_rp_next].addr
                +
                VADDR_WIDTH
                '(
                $unsigned(4)
                )
            };

            // commit,flush
            commit_op = 1;
            flush_al_fl_and_break = 1;
          end else if (is_csr_opcode(al_next[al_rp_next].opcode)) begin
            // ⑧ CSR
            // この命令までは卒業したのでアクティブリストに入っている後続の命令は消していい.
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] OP_Addr:%010h, csr commit done",
                      al_next[al_rp_next].addr);
            $fdisplay(fp_mainlog,
                      "[LOG] [Renamer.sv] OP_Addr:%010h, Opcode:%s, rd:%h, rd_val:%016h",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                      al_next[al_rp_next].physical_rd, al_next[al_rp_next].rd_val);
`endif
            flush_from_renamer = '{
                valid: 1,
                addr: al_next[al_rp_next].addr + VADDR_WIDTH'($unsigned(4))
            };

            // commit,flush
            commit_op = 1;
            flush_al_fl_and_break = 1;

          end else if (al_next[al_rp_next].opcode == MRET) begin
            // ⑩ MRET
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog,
                      "[LOG] [Renamer.sv] MRET. OP_Addr:%010h Opcode:%s mepc:%016h new_priv:%b",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                      csr_port.mepc_rdata.as_mepc.MEPC, csr_port.mstatus_rdata.as_mstatus.MPP);
`endif
            priv_w.en = 1;
            priv_w.val = HART_DEFS::privilege_level_e'(csr_port.mstatus_rdata.as_mstatus.MPP);

            // mstatus
            csr_port.mstatus_w.en = 1;
            csr_port.mstatus_w.data = csr_port.mstatus_rdata;
            csr_port.mstatus_w.data.as_mstatus.MIE = csr_port.mstatus_rdata.as_mstatus.MPIE;
            csr_port.mstatus_w.data.as_mstatus.MPIE = 1;
            csr_port.mstatus_w.data.as_mstatus.MPP = 2'b00;

            // mepcに保存した値から再開させる.
            flush_from_renamer = '{
                valid: 1,
                addr: VADDR_WIDTH'(csr_port.mepc_rdata.as_mepc.MEPC)
            };

            // commit,flush
            commit_op = 1;
            flush_al_fl_and_break = 1;

          end else if (al_next[al_rp_next].opcode == SRET) begin
            // ⑨ SRET
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog,
                      "[LOG] [Renamer.sv] SRET. OP_Addr:%010h Opcode:%s sepc:%016h new_priv:%b",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                      csr_port.sepc_rdata.as_sepc.SEPC, csr_port.sstatus_rdata.as_sstatus.SPP);
`endif
            //元の特権モードに戻る.
            priv_w.en = 1;
            // SPPはu-mode,s-modeのみなので
            priv_w.val = HART_DEFS::privilege_level_e'({
              1'b0, csr_port.sstatus_rdata.as_sstatus.SPP
            });

            // sstatus
            csr_port.sstatus_w.en = 1;
            csr_port.sstatus_w.data = csr_port.sstatus_rdata;
            csr_port.sstatus_w.data.as_mstatus.SIE = csr_port.sstatus_rdata.as_mstatus.SPIE;
            csr_port.sstatus_w.data.as_mstatus.SPIE = 1;
            csr_port.sstatus_w.data.as_mstatus.SPP = 1'b0;

            // sepcに保存した値から再開.
            flush_from_renamer = '{
                valid: 1,
                addr: VADDR_WIDTH'(csr_port.sepc_rdata.as_sepc.SEPC)
            };

            // commit,flush
            commit_op = 1;
            flush_al_fl_and_break = 1;
          end else if (al_next[al_rp_next].opcode == SFENCE_VMA) begin
            // ⑪ SFENCE_VMA
`ifdef MAINLOG_EN
            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] SFENCE_VMA. OP_Addr:%010h Opcode:%s ",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name());
`endif
            // TLBのエントリをすべて無効にした上で,flush_from_renamerを送る.

            flush_tlb = 1;

            flush_from_renamer = '{
                valid: 1,
                addr: VADDR_WIDTH'(al_next[al_rp_next].addr + VADDR_WIDTH'(4))
            };

            commit_op = 1;
            flush_al_fl_and_break = 1;

          end else begin
            // ⑫ 通常コミット.
`ifdef MAINLOG_EN
            $fdisplay(
                fp_mainlog,
                "[LOG] [Renamer.sv] Normal commit done.AL_idx:%h Addr:%016h Opcode:%s PredTaken:%b, PredTakenAddr:%016h ActualTaken:%b, ActualTakenAddr:%016h Misprediction:%b",
                al_rp_next, al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                al_next[al_rp_next].pred_taken, al_next[al_rp_next].pred_taken_addr,
                al_next[al_rp_next].actual_taken, al_next[al_rp_next].actual_taken_addr,
                al_next[al_rp_next].misprediction);

            $fdisplay(fp_mainlog, "[LOG] [Renamer.sv] OP_Addr:%010h, normal commit done",
                      al_next[al_rp_next].addr);
            $fdisplay(fp_mainlog,
                      "[LOG] [Renamer.sv] OP_Addr:%010h, Opcode:%s, rd:%h, rd_val:%016h",
                      al_next[al_rp_next].addr, al_next[al_rp_next].opcode.name(),
                      al_next[al_rp_next].physical_rd, al_next[al_rp_next].rd_val);
`endif
            if (is_st_opcode(al_next[al_rp_next].opcode)) begin
              st_commit_counter++;
            end

            // predictorの更新用.
            if (is_branch_opcode(
                    al_next[al_rp_next].opcode
                ) || is_jmp_opcode(
                    al_next[al_rp_next].opcode
                )) begin
              is_taken_feedback_to_pred[i] = '{
                  valid: 1,
                  op_addr: al_next[al_rp_next].addr,
                  taken: al_next[al_rp_next].actual_taken
              };
            end

            // commit,flush
            commit_op = 1;
            flush_al_fl_and_break = 0;

          end



        end else begin
          // この命令をコミットしない場合.


          // この命令をコミットしない場合,それがcsrならcsrがalの先頭に来ている(=発行可能)という意味である
          if (is_csr_opcode(al_next[al_rp_next].opcode)) begin
            csru_port.executable_csr = '{valid: 1, al_idx: al_rp_next};
          end

          // scなら実行可能性を伝える
          // if (al_next[al_rp_next].opcode inside {SC_W, SC_D}) begin
          //   lsu_port.sc_executable = '{
          //       valid: 1,
          //       al_idx: al_rp_next,
          //       paddr_dw_aligned: lrsc_lock_next.paddr_dw_aligned,
          //       is_lr_w: lrsc_lock_next.is_lr_w
          //   };
          // end

          // scとmmioの実行可能性を伝える.
          lsu_port.sc_mmio_executable = '{
              valid: 1,
              al_idx: al_rp_next,
              opcode: al_next[al_rp_next].opcode,
              has_lock: lrsc_lock_next.valid,
              lock_paddr_dw_aligned: lrsc_lock_next.paddr_dw_aligned,
              is_lr_w: lrsc_lock_next.is_lr_w
          };

          // fence_iが先頭でかつ,それが初めての場合はinvalidate_l1cacheをだしてl1cacheをinvalidateする.
          if (al_next[al_rp_next].opcode == FENCE_I && al_next[al_rp_next].fencei_sig_made == 0) begin
            invalidate_l1cache_next = 1;
            al_next[al_rp_next].fencei_sig_made = 1;
          end

          // 当然後続の命令もコミットしないためbreak
          break;


        end

        // ----------------------------------------------------------------------
        // commit,flush処理
        // ----------------------------------------------------------------------
        // commit_op==1 なら commit 処理を行う
        if (commit_op) begin

          // ログの出力
          commitlog[i] = '{
              valid: 1,
              addr: al_next[al_rp_next].addr,
              opcode: al_next[al_rp_next].opcode,
              rs1_exist: al_next[al_rp_next].has_rs1,
              rs2_exist: al_next[al_rp_next].has_rs2,
              rd_exist: al_next[al_rp_next].has_rd,
              rs1_abi: abi_name_e'(al_next[al_rp_next].logical_rs1),
              rs2_abi : abi_name_e'(al_next[al_rp_next].logical_rs2),
              rd_abi  : abi_name_e'(al_next[al_rp_next].logical_rd),
              physical_rs1: al_next[al_rp_next].physical_rs1,
              physical_rs2: al_next[al_rp_next].physical_rs2,
              physical_rd: al_next[al_rp_next].physical_rd,
              rd_val : al_next[al_rp_next].rd_val
          };


          // flへの物理レジスタ返却,rratの更新.
          // x0がrdなら返却不要.
          if (al_next[al_rp_next].has_rd && al_next[al_rp_next].physical_rd != 0) begin
            committed_rd_valid[i] = 1;
            committed_phyreg[i] = al_next[al_rp_next].physical_rd;
            committed_prev_phyreg[i] = al_next[al_rp_next].previous_physical_rd;
            rrat_next[al_next[al_rp_next].logical_rd] = al_next[al_rp_next].physical_rd;
          end else begin
            committed_rd_valid[i] = 0;
            committed_phyreg[i] = 0;
            committed_prev_phyreg[i] = 0;
          end

          // lrsc_lockに登録.
          if ((is_ld_opcode(
                  al_next[al_rp_next].opcode
              ) || is_st_opcode(
                  al_next[al_rp_next].opcode
              ) || is_amo_opcode(
                  al_next[al_rp_next].opcode
              )) && to_dw_aligned_paddr(
                  al_next[al_rp_next].ldst_target_addr
              ) == lrsc_lock_next.paddr_dw_aligned) begin
            //アドレスがlrsc_lockと一致していた場合は無効化.
            lrsc_lock_next = '{default: 0};
          end
          if (al_next[al_rp_next].opcode inside {LR_W, LR_D}) begin
            lrsc_lock_next = '{
                valid: 1,
                paddr_dw_aligned: to_dw_aligned_paddr(al_next[al_rp_next].ldst_target_addr),
                is_lr_w: al_next[al_rp_next].opcode == LR_W ? 1 : 0
            };
          end

          // mintretの更新
          if (!instret_inhibited) begin
            // csrでmcountinhibitを変更した後はflushするので,
            // 「一つのサイクルで1つ目でmcoutinhibitを書き換えたけど、反映は次のサイクルからなので、
            // 本来カウントアップされないその後の命令がカウントアップされる」みたいな事態は存在しない.
            minstret_next = minstret_next + 1;
          end

          // lsuに卒業した命令の通知.
          lsu_port.committed_instr[i] = '{valid: 1, al_idx: al_rp_next};
          csru_port.committed_instr[i] = '{valid: 1, al_idx: al_rp_next};

          // alから先頭のエントリを削除.
          al_rp_next = AL_IDX_WIDTH'(32'(al_rp_next) + 1);
          num_of_entries_in_al_next--;
        end

        // al,flをflushしてbreak
        if (flush_al_fl_and_break) begin
          al_wp_next = 0;
          al_rp_next = 0;
          num_of_entries_in_al_next = 0;
          flush_fl = 1;
          al_flush = 1;
          generation_next++;
          break;
        end else begin
          flush_fl = 0;
          al_flush = 0;
        end
      end

      // minstretの更新.
      csr_port.minstret_w = '{en: 1, data: minstret_next};
    end

    // ----------------------------------
    // stall_out
    // ----------------------------------
    begin
      // 
      // logic sinterrupt_detected = 0;
      // logic minterrupt_detected = 0;
      // sinterrupt_detected =   csr_port.mstatus_rdata.as_mstatus.SIE &&
      //       ((csr_port.mideleg_rdata & csr_port.sie_rdata & csr_port.sip_rdata) != 0) &&
      //       (priv_rval inside {U_MODE,S_MODE});
      // minterrupt_detected = csr_port.mstatus_rdata.as_mstatus.MIE &&
      //                 ((csr_port.mie_rdata & csr_port.mip_rdata) != 0) ;
      stall_out = ACTIVELIST_SIZE - 32'(num_of_entries_in_al_next) < NUM_OF_FETCH;

    end


  end

  // 初期化用のrat_initを作成.
  // x0 => p0, x1 => p1
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_LOGREGS; i++) begin
      rat_init[i] = $clog2(NUM_OF_PHYREGS)'(i);
    end
  end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      //stall
      op_in_pending <= '{default: 0};
      is_pending <= 0;

      //lrsc
      lrsc_lock <= '{default: 0};

      //rat
      rat <= rat_init;
      rrat <= rat_init;


      // csru
      // csru_port.committed_instr <= '{default: 0};
      // csru_port.executable_csr <= '{default: 0};


      // active list
      al <= '{default: 0};
      al_wp <= 0;
      al_rp <= 0;
      num_of_entries_in_al <= 0;

      // 出力
      generation <= 0;
      invalidate_l1cache <= 0;
      op_out <= '{default: 0};
    end else if (al_flush) begin
      //stall
      op_in_pending <= '{default: 0};
      is_pending <= 0;

      // lrsc
      // 理由もなく失敗していいらしいので,
      lrsc_lock <= '{default: 0};

      // flushする時,rrat_nextを反映
      rat <= rrat_next;
      rrat <= rrat_next;

      // csru
      // csru_port.committed_instr <= '{default: 0};
      // csru_port.executable_csr <= '{default: 0};


      // active list
      al <= '{default: 0};
      al_wp <= 0;
      al_rp <= 0;
      num_of_entries_in_al <= 0;

      // 出力
      generation <= generation_next;
      invalidate_l1cache <= 0;
      op_out <= '{default: 0};


    end else begin
      //stall
      op_in_pending <= op_in_pending_next;
      is_pending <= is_pending_next;

      // lrsc
      lrsc_lock <= lrsc_lock_next;

      // rat,rrat
      rat <= rat_next;
      rrat <= rrat_next;

      // csru
      // csru_port.committed_instr <= csru_port_committed_instr_next;
      // csru_port.executable_csr <= csru_port_executable_csr_next;

      // active list
      al <= al_next;
      al_wp <= al_wp_next;
      al_rp <= al_rp_next;
      num_of_entries_in_al <= num_of_entries_in_al_next;

      // 出力
      generation <= generation_next;
      invalidate_l1cache <= invalidate_l1cache_next;
      op_out <= op_out_next;


    end


    // FORDEBUG
`ifdef COMMITLOG_EN
    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      if (commitlog[i].valid) begin
        $fdisplay(fp_commitlog,
                  "0x%010h: %6s  rs1:%4s\(%s\)   rs2:%4s\(%s\)   rd:%4s\(%s\) \(0x%016h\)",
                  commitlog[i].addr, commitlog[i].opcode.name(),
                  commitlog[i].rs1_exist ? commitlog[i].rs1_abi.name() : "_",
                  commitlog[i].rs1_exist ? $sformatf("p%02d", commitlog[i].physical_rs1) : "___",
                  commitlog[i].rs2_exist ? commitlog[i].rs2_abi.name() : "_",
                  commitlog[i].rs2_exist ? $sformatf("p%02d", commitlog[i].physical_rs2) : "___",
                  commitlog[i].rd_exist ? commitlog[i].rd_abi.name() : "_",
                  commitlog[i].rd_exist ? $sformatf("p%02d", commitlog[i].physical_rd) : "___",
                  commitlog[i].rd_val);
        $fdisplay(fp_addrlog, "0x%08h", commitlog[i].addr);
      end
    end
`endif

  end



  // FOR DEBUG
  // FOR DEBUG
  activelist_t al_next0;
  activelist_t al_next1;
  activelist_t al_next2;
  activelist_t al_next3;
  activelist_t al_next4;
  activelist_t al_next5;
  activelist_t al_next6;
  activelist_t al_next7;
  activelist_t al_next8;
  activelist_t al_next9;
  activelist_t al_next10;
  activelist_t al_next11;
  activelist_t al_next12;
  activelist_t al_next13;
  activelist_t al_next14;
  activelist_t al_next15;
  activelist_t al_next16;
  activelist_t al_next17;
  activelist_t al_next18;
  activelist_t al_next19;
  activelist_t al_next20;
  activelist_t al_next21;
  activelist_t al_next22;
  activelist_t al_next23;
  activelist_t al_next24;
  activelist_t al_next25;
  activelist_t al_next26;
  activelist_t al_next27;
  activelist_t al_next28;
  activelist_t al_next29;
  activelist_t al_next30;
  activelist_t al_next31;
  activelist_t al_next32;
  activelist_t al_next33;
  activelist_t al_next34;
  activelist_t al_next35;
  activelist_t al_next36;
  activelist_t al_next37;
  activelist_t al_next38;
  activelist_t al_next39;
  activelist_t al_next40;
  activelist_t al_next41;
  activelist_t al_next42;
  activelist_t al_next43;
  activelist_t al_next44;
  activelist_t al_next45;
  activelist_t al_next46;
  activelist_t al_next47;
  activelist_t al_next48;
  activelist_t al_next49;
  activelist_t al_next50;
  activelist_t al_next51;
  activelist_t al_next52;
  activelist_t al_next53;
  activelist_t al_next54;
  activelist_t al_next55;
  activelist_t al_next56;
  activelist_t al_next57;
  activelist_t al_next58;
  activelist_t al_next59;
  activelist_t al_next60;
  activelist_t al_next61;
  activelist_t al_next62;
  activelist_t al_next63;

  always_comb begin
    al_next0  = al_next[0];
    al_next1  = al_next[1];
    al_next2  = al_next[2];
    al_next3  = al_next[3];
    al_next4  = al_next[4];
    al_next5  = al_next[5];
    al_next6  = al_next[6];
    al_next7  = al_next[7];
    al_next8  = al_next[8];
    al_next9  = al_next[9];
    al_next10 = al_next[10];
    al_next11 = al_next[11];
    al_next12 = al_next[12];
    al_next13 = al_next[13];
    al_next14 = al_next[14];
    al_next15 = al_next[15];
    al_next16 = al_next[16];
    al_next17 = al_next[17];
    al_next18 = al_next[18];
    al_next19 = al_next[19];
    al_next20 = al_next[20];
    al_next21 = al_next[21];
    al_next22 = al_next[22];
    al_next23 = al_next[23];
    al_next24 = al_next[24];
    al_next25 = al_next[25];
    al_next26 = al_next[26];
    al_next27 = al_next[27];
    al_next28 = al_next[28];
    al_next29 = al_next[29];
    al_next30 = al_next[30];
    al_next31 = al_next[31];
    al_next32 = al_next[32];
    al_next33 = al_next[33];
    al_next34 = al_next[34];
    al_next35 = al_next[35];
    al_next36 = al_next[36];
    al_next37 = al_next[37];
    al_next38 = al_next[38];
    al_next39 = al_next[39];
    al_next40 = al_next[40];
    al_next41 = al_next[41];
    al_next42 = al_next[42];
    al_next43 = al_next[43];
    al_next44 = al_next[44];
    al_next45 = al_next[45];
    al_next46 = al_next[46];
    al_next47 = al_next[47];
    al_next48 = al_next[48];
    al_next49 = al_next[49];
    al_next50 = al_next[50];
    al_next51 = al_next[51];
    al_next52 = al_next[52];
    al_next53 = al_next[53];
    al_next54 = al_next[54];
    al_next55 = al_next[55];
    al_next56 = al_next[56];
    al_next57 = al_next[57];
    al_next58 = al_next[58];
    al_next59 = al_next[59];
    al_next60 = al_next[60];
    al_next61 = al_next[61];
    al_next62 = al_next[62];
    al_next63 = al_next[63];
  end

endmodule
