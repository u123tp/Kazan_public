`include "COMMON_PARAMS.svh"
`include "HART_DEFS.svh"
`include "COMMON_FUNCS.svh"
`include "CSR_PROPS.svh"


package Renamer_PROPS;
  import COMMON_PARAMS::*;
  import HART_DEFS::*;
  import COMMON_FUNCS::*;
  import CSR_PROPS::*;


  typedef struct packed {
    logic [VADDR_WIDTH-1:0] op_vaddr;  // この命令のアドレス.
    opcode_t opcode;
    logic has_rd;  // この命令がrdを持っているか
    logic [4:0] logical_rd;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rd;
    // この命令の発行以前に,この命令の用いてる論理レジスタに対応していた物理レジスタ.
    logic [$clog2(NUM_OF_PHYREGS)-1:0] previous_physical_rd;

    logic pred_taken;  // 分岐予想でtakenにしていたか.
    logic [VADDR_WIDTH-1:0] pred_taken_addr;  // pred_takenが1の時,予想された飛び先.pred_taken==0のときは使用しない.

    // 命令
    logic is_page_fault_instr;
    logic is_access_fault_instr;

    // illegal instr用.
    logic [31:0] raw_op;

    // FOR DEBUG
    logic has_rs1;
    logic has_rs2;
    logic [4:0] logical_rs1;
    logic [4:0] logical_rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] physical_rs2;


  } al_meta_t;


  typedef struct packed {
    logic actual_taken;  // 実際にtakenであったか.
    logic [VADDR_WIDTH-1:0] actual_taken_addr; //actual_takenが1の時,実際の飛び先.actual_taken==0のときは使用しない.

    // ld,st用フィールド.
    // tval用のldst_target_addr
    logic [VADDR_WIDTH-1:0] ldst_target_vaddr;
    // pmp,lr/sc用のldst_target_addr
    logic [PADDR_WIDTH-1:0] ldst_target_paddr;


    logic is_page_fault_ldst;
    logic is_access_fault_ldst;
    logic target_address_misalignment;


    // FOR DEBUG
    logic [XLEN-1:0] rd_val;

  } al_result_t;


  task automatic dump_al_meta(input al_meta_t x);
    $display("========== AL_META DUMP ==========");
    $display("  op_vaddr              = 0x%0h", x.op_vaddr);
    $display("  opcode                = %0d / 0x%0h", x.opcode, x.opcode);
    $display("  has_rd                = %0d", x.has_rd);
    $display("  logical_rd            = x%0d", x.logical_rd);
    $display("  physical_rd           = %0d", x.physical_rd);
    $display("  previous_physical_rd  = %0d", x.previous_physical_rd);
    $display("  pred_taken            = %0d", x.pred_taken);
    $display("  pred_taken_addr       = 0x%0h", x.pred_taken_addr);
    $display("  is_page_fault_instr   = %0d", x.is_page_fault_instr);
    $display("  is_access_fault_instr = %0d", x.is_access_fault_instr);
    $display("  raw_op                = 0x%08h", x.raw_op);
    $display("  has_rs1               = %0d", x.has_rs1);
    $display("  has_rs2               = %0d", x.has_rs2);
    $display("  logical_rs1           = x%0d", x.logical_rs1);
    $display("  logical_rs2           = x%0d", x.logical_rs2);
    $display("  physical_rs1          = %0d", x.physical_rs1);
    $display("  physical_rs2          = %0d", x.physical_rs2);
    $display("==================================");
  endtask

  task automatic dump_al_result(input al_result_t x);
    $display("========== AL_RESULT DUMP ==========");
    $display("  actual_taken                 = %0d", x.actual_taken);
    $display("  actual_taken_addr            = 0x%0h", x.actual_taken_addr);
    $display("  ldst_target_vaddr            = 0x%0h", x.ldst_target_vaddr);
    $display("  ldst_target_paddr            = 0x%0h", x.ldst_target_paddr);
    $display("  is_page_fault_ldst           = %0d", x.is_page_fault_ldst);
    $display("  is_access_fault_ldst         = %0d", x.is_access_fault_ldst);
    $display("  target_address_misalignment  = %0d", x.target_address_misalignment);
    $display("  rd_val                       = 0x%0h", x.rd_val);
    $display("=====================================");
  endtask



  typedef struct packed {
    logic valid;
    logic [5:0] cause;
    logic [XLEN-1:0] tval;
  } exception_info_t;

  typedef struct packed {
    logic valid;
    logic R;
    logic W;
    logic X;
    logic L;
  } pmp_result_t;

  // ----------------------------------------------------------------------------------------------------------
  // pmp check
  // ----------------------------------------------------------------------------------------------------------

  function automatic logic pmp_access_fault(
      input logic [PADDR_WIDTH-1:0] target_paddr, input privilege_level_e current_priv,
      input logic is_read, input logic is_write, input logic is_exe,
      input csr_reg_u pmpcfg_rdata[NUM_OF_PMPCFG], input csr_reg_u pmpaddr_rdata[NUM_OF_PMPCFG*8],
      input csr_reg_u mcounteren_rdata);

    logic pmp_exist = 0;
    pmp_result_t pmp_result = '{default: 0};


    for (int unsigned i = 0; i < NUM_OF_PMPCFG * 8; i++) begin
      logic [7:0] pmpcfg = pmpcfg_rdata[i/8].as_uint[(i%8)*8+:8];
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
          // 無効領域
          start_paddr = '0;
          end_paddr   = '0;
        end

        2'b01: begin  // TOR
          start_paddr = (i == 0) ? '0 : PADDR_WIDTH'(pmpaddr_rdata[i-1] << 2);
          end_paddr   = PADDR_WIDTH'(pmpaddr_rdata[i] << 2);
          pmp_exist   = 1;
        end

        2'b10: begin  // NA4
          start_paddr = PADDR_WIDTH'(pmpaddr_rdata[i] << 2);
          end_paddr   = start_paddr + PADDR_WIDTH'(4);
          pmp_exist   = 1;
        end

        2'b11: begin  // NAPOT
          for (int unsigned j = 0; j < PADDR_WIDTH - 2; j++) begin
            if (pmpaddr_rdata[i][j] == 0) break;
            napot_counter++;
            napot_mask[j] = 1'b0;
          end
          start_paddr = PADDR_WIDTH'((pmpaddr_rdata[i] & napot_mask) << 2);
          end_paddr   = start_paddr + (PADDR_WIDTH'(1) << (napot_counter + 2));
          pmp_exist   = 1;
        end

        default: begin
          // エラー
          $display("[ERROR][Renamer.sv] pmp address matching error");
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


  // robから卒業するときにexceptionがあるかをチェックする.
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
  // mretとかsfence_vmaとかはもとからal_doneになっているため,前のal_resultの内容を上書きせず,
  // そのまま使用してしまう可能性がある.
  // それらの命令に対しては,renamerより前で発生するexceptionに限定して検知する,
  // 例えばillegal instr,instruction page fault,instrucntion access faultなどである.

  function automatic exception_info_t check_exception(
      input al_meta_t al_meta, input al_result_t al_result, input privilege_level_e priv_rval,
      input csr_reg_u mstatus_rdata, input csr_reg_u mcounteren_rdata,
      input csr_reg_u scounteren_rdata, input csr_reg_u pmpcfg_rdata[NUM_OF_PMPCFG],
      input csr_reg_u pmpaddr_rdata[NUM_OF_PMPCFG*8]);

    exception_info_t exception_result = '{default: 0};

    // ---------------------------------------------------------------------------------------------
    // 6. Store/AMO address misalignment
    // ----------------------------------------------------------------------------------------------
    if (al_result.target_address_misalignment && (is_st_opcode(
            al_meta.opcode
        ) || is_amo_opcode(
            al_meta.opcode
        ))) begin
      exception_result = '{
          valid: 1,
          cause: 6,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // ----------------------------------------------------------------------------------------------
    // 4. Load address misalignment
    // ----------------------------------------------------------------------------------------------
    if (al_result.target_address_misalignment && is_ld_opcode(al_meta.opcode)) begin
      exception_result = '{
          valid: 1,
          cause: 4,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // ----------------------------------------------------------------------------------------------
    // 7. Store/AMO access fault
    // ----------------------------------------------------------------------------------------------
    // st/amoからの返却に基づいて更新.
    if (al_result.is_access_fault_ldst && (is_st_opcode(
            al_meta.opcode
        ) || is_amo_opcode(
            al_meta.opcode
        ))) begin
      exception_result = '{
          valid: 1,
          cause: 7,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end
    // pmpに基づいて更新.
    if ((is_st_opcode(
            al_meta.opcode
        ) || is_amo_opcode(
            al_meta.opcode
        )) && pmp_access_fault(
            al_result.ldst_target_paddr,
            priv_rval,
            0,
            1,
            0,
            pmpcfg_rdata,
            pmpaddr_rdata,
            mcounteren_rdata
        )) begin

      exception_result = '{
          valid: 1,
          cause: 7,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // メインメモリの範囲の外にアクセスした場合はaccess_fault

    // ----------------------------------------------------------------------------------------------
    // 5. load access fault
    // ----------------------------------------------------------------------------------------------
    // ldからの返却に基づいて更新.
    if (al_result.is_access_fault_ldst && is_ld_opcode(al_meta.opcode)) begin
      $display("priv: %b", priv_rval);
      $display("[LOG][Renamer_PROPS.svh] ld access fault Exception. tval:%d",
               XLEN'(signed'(al_result.ldst_target_paddr)));
      // dump_activelist_entry(al_entry);
      // $finish();
      exception_result = '{
          valid: 1,
          cause: 5,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end
    // pmpに基づいて更新.
    if (is_ld_opcode(
            al_meta.opcode
        ) && pmp_access_fault(
            al_result.ldst_target_paddr,
            priv_rval,
            1,
            0,
            0,
            pmpcfg_rdata,
            pmpaddr_rdata,
            mcounteren_rdata
        )) begin
      exception_result = '{
          valid: 1,
          cause: 5,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // ----------------------------------------------------------------------------------------------
    // 15. Store/AMO page fault
    // ----------------------------------------------------------------------------------------------
    if (al_result.is_page_fault_ldst && (is_st_opcode(
            al_meta.opcode
        ) || is_amo_opcode(
            al_meta.opcode
        ))) begin
      exception_result = '{
          valid: 1,
          cause: 15,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // ----------------------------------------------------------------------------------------------
    // 13. Load page fault
    // ----------------------------------------------------------------------------------------------
    if (al_result.is_page_fault_ldst && is_ld_opcode(al_meta.opcode)) begin
      exception_result = '{
          valid: 1,
          cause: 13,
          tval: XLEN'(signed'(al_result.ldst_target_paddr))
      };
    end

    // ---------------------------------------------------------------------------------------------
    // 11. Enviroment call from M_MODE (opcode)
    // ---------------------------------------------------------------------------------------------
    if (al_meta.opcode == ECALL && priv_rval == M_MODE) begin
      exception_result = '{valid: 1, cause: 11, tval: 0};
    end

    // ---------------------------------------------------------------------------------------------
    // 9. Enviroment call from S_MODE (opcode)
    // ---------------------------------------------------------------------------------------------
    if (al_meta.opcode == ECALL && priv_rval == S_MODE) begin
      exception_result = '{valid: 1, cause: 9, tval: 0};
    end

    // ---------------------------------------------------------------------------------------------
    // 8. Enviroment call from U_MODE (opcode)
    // ---------------------------------------------------------------------------------------------
    if (al_meta.opcode == ECALL && priv_rval == U_MODE) begin
      exception_result = '{valid: 1, cause: 8, tval: 0};
    end

    // --------------------------------------------------------------------------------------------
    // 0. Instruction address misalignment (target_address_misaligned)
    // --------------------------------------------------------------------------------------------
    if (al_result.target_address_misalignment && (is_jmp_opcode(
            al_meta.opcode
        ) || is_branch_opcode(
            al_meta.opcode
        ))) begin
      exception_result = '{
          valid: 1,
          cause: 0,
          tval: XLEN'(signed'(al_result.actual_taken_addr))
      };
    end


    // ----------------------------------------------------------------------------------------------
    // 2. Illegal instruction
    // ----------------------------------------------------------------------------------------------
    // opcodeがILLEGAL_INSTRならcauseはIllegal instruction
    if (al_meta.opcode == ILLEGAL_INSTR) begin
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
      $display("[LOG][Renamer_PROPS.svh] The instruction can't be decoded. raw_op:%08h",
               al_meta.raw_op);
    end

    // 特権命令が不正な特権レベルで実行されている場合はillegal instr例外とする
    if (al_meta.opcode == MRET) begin
      if (priv_rval != M_MODE) begin
        $display("[LOG][Renamer_PROPS.svh] MRET Exception. Running in %s", `__FILE__, `__LINE__,
                 priv_rval.name());
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
      end
    end

    if (al_meta.opcode == SRET) begin
      if (priv_rval == U_MODE || ((priv_rval == M_MODE) && mstatus_rdata.as_mstatus.TSR)) begin
        $display("[LOG][Renamer_PROPS.svh] SRET Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
      end
    end

    // tw
    if (al_meta.opcode == WFI && mstatus_rdata.as_mstatus.TW && priv_rval == S_MODE) begin
      $display("[LOG][%s,%-d] WFI while tw  Exception.", `__FILE__, `__LINE__);
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
    end


    // mstatus.tvmであるなら,sfenceはillegalである
    if (al_meta.opcode == SFENCE_VMA) begin
      if (priv_rval == U_MODE || (mstatus_rdata.as_mstatus.TVM && priv_rval == S_MODE)) begin
        $display("[LOG][%s,%-d] SFENCE_VMA Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
      end
    end

    // 同様に,mstatus.tvmであるなら,satpへのsモードからのアクセスは禁止される.
    if (is_csr_opcode(
            al_meta.opcode
        ) && csr_name_e'(al_meta.raw_op[31:20]) == SATP && mstatus_rdata.as_mstatus.TVM &&
            priv_rval == S_MODE) begin
      $display("[LOG][%s,%-d] SATP ACCESS while in tvm Exception.", `__FILE__, `__LINE__);
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
    end


    // counterenに基づいて,S_MODEからのアクセスを制御する.
    begin
      int unsigned corresponding_bit = 0;
      if (is_csr_opcode(
              al_meta.opcode
          ) && csr_name_e'(al_meta.raw_op[31:20]) inside {CYCLE, TIME, INSTRET,
                                                          [HPMCOUNTER3 : HPMCOUNTER31]}) begin

        case (csr_name_e'(al_meta.raw_op[31:20]))
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

        if (!mcounteren_rdata[corresponding_bit] && priv_rval == S_MODE) begin
          $display("[LOG] illegal instr detected in mcounteren restriction.");
          exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
        end

        if((!mcounteren_rdata[corresponding_bit] || !scounteren_rdata[corresponding_bit])
               && priv_rval == U_MODE)begin
          $display("[LOG][Renaer_PROPS.svh] mcounteren error");
          exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
        end

      end
    end


    // csrへアクセス可能なのは,現在の特権レベルがcsr[9:8]以上であるとき.そうでなければillegal instrに.
    if (is_csr_opcode(al_meta.opcode) && al_meta.raw_op[29:28] > priv_rval) begin
      // TODO: コメントアウト.
      $display("priv: %b", priv_rval);
      $display("[LOG][%s,%-d] CSR ACCESS fault Exception.", `__FILE__, `__LINE__);
      // dump_activelist_entry(al_entry);
      // $finish;
      exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
    end

    // is_csr_write
    // riscv-unprivileged.pdf, page50
    begin
      logic is_write_csr = 0;
      if (al_meta.opcode == CSRRW) begin
        is_write_csr = 1;
      end else if (al_meta.opcode inside {CSRRS, CSRRC} && al_meta.raw_op[19:15] != 0) begin
        is_write_csr = 1;
      end else if (al_meta.opcode == CSRRWI) begin
        is_write_csr = 1;
      end else if (al_meta.opcode inside {CSRRSI, CSRRCI} && al_meta.raw_op[19:15] != 0) begin
        is_write_csr = 1;
      end

      // 書き込み専用レジスタに書き込みを行おうとした場合,illegal instrにする.
      if (is_csr_opcode(al_meta.opcode) && al_meta.raw_op[31:30] == 2'b11 && is_write_csr) begin
        $display("[LOG][%s,%-d] CSR WRITE fault Exception.", `__FILE__, `__LINE__);
        exception_result = '{valid: 1, cause: 2, tval: {32'b0, al_meta.raw_op}};
      end
    end

    // -------------------------------------------------------------------------------------
    // 1. Instruction access fault (is_access_fault_instr)
    // -------------------------------------------------------------------------------------
    if (al_meta.is_access_fault_instr) begin
      exception_result = '{valid: 1, cause: 1, tval: XLEN'(signed'(al_meta.op_vaddr))};
    end

    // ------------------------------------------------------------------------------------
    // 12. Instruction page fault (is_page_fault_instr)
    // ------------------------------------------------------------------------------------
    if (al_meta.is_page_fault_instr) begin
      exception_result = '{valid: 1, cause: 12, tval: XLEN'(signed'(al_meta.op_vaddr))};
    end

    // ------------------------------------------------------------------------------------
    // 3. BreakPoint
    // ------------------------------------------------------------------------------------

    if (al_meta.opcode == EBREAK) begin
      //EBREAKはtval自由.
      exception_result = '{valid: 1, cause: 3, tval: 0};
    end


    // if (exception_result.valid) begin
    //   $display("[LOG][Renamer_PROPS.svh] %0h cause:%d tval:%016h", al_meta.op_vaddr,
    //            exception_result.cause, exception_result.tval);
    // end

    return exception_result;

  endfunction



endpackage
