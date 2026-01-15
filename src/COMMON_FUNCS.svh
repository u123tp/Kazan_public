// 様々な場所で使う関数の中で,個々のパラメータに依存しない関数郡

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CACHE_PROPS.svh"

`ifndef COMMON_FUNCS
`define COMMON_FUNCS

package COMMON_FUNCS;

  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CACHE_PROPS::*;

  // 命令判別用関数.
  function automatic logic is_arithmetic_opcode(opcode_t opcode);
    if(opcode inside {ADD,SUB,SLL,SLT,OR,AND,XOR,SRL,SRA,SLTU,ADDW,SUBW,SLLW,SRLW,SRAW,
                      ADDI,SLTI,SLTIU,XORI,ORI,ANDI,SLLI,SRLI,SRAI,SRAIW,ADDIW,SLLIW,SRLIW,
                      BEQ,BNE,BLT,BGE,BLTU,BGEU,
                      JAL,JALR,LUI,AUIPC,
                      MUL,MULH,MULHSU,MULHU,DIV,DIVU,REM,REMU,MULW,DIVW,DIVUW,REMW,REMUW})begin
      return 1;
    end
    return 0;
  endfunction

  // 分岐命令
  function automatic logic is_branch_opcode(opcode_t opcode);
    if (opcode inside {BEQ, BNE, BLT, BGE, BLTU, BGEU}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  // ジャンプ命令
  function automatic logic is_jmp_opcode(opcode_t opcode);
    if (opcode inside {JAL, JALR}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_ld_opcode(opcode_t opcode);
    if (opcode inside {LB, LH, LW, LD, LBU, LHU, LWU, LR_W, LR_D}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_st_opcode(opcode_t opcode);
    if (opcode inside {SB, SH, SW, SD, SC_W, SC_D}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_lr_opcode(opcode_t opcode);
    if (opcode inside {LR_W, LR_D}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_sc_opcode(opcode_t opcode);
    if (opcode inside {SC_W, SC_D}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_csr_opcode(opcode_t opcode);
    if (opcode inside {CSRRW, CSRRS, CSRRC, CSRRWI, CSRRSI, CSRRCI}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_amo_opcode(opcode_t opcode);
    if(opcode inside {
      AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
      AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W,
      AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
      AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D
    })begin
      return 1;
    end else begin
      return 0;
    end
  endfunction

  function automatic logic is_lrsc_opcode(opcode_t opcode);
    if (opcode inside {LR_W, SC_W, LR_D, SC_D}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction


  function automatic req_policy_e get_read_req_policy(opcode_t opcode);
    case (opcode)
      LB, LBU: begin
        return READ_BYTE;
      end
      LH, LHU: begin
        return READ_HALF_WORD;
      end
      LW, LWU, LR_W,  AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
      AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:begin
        return READ_WORD;
      end
      LD, LR_D, AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
      AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D : begin
        return READ_DOUBLE_WORD;
      end
      default: begin
        $display("[ERROR] [%s,%0d] get_read_req_policy(%s)", `__FILE__, `__LINE__, opcode.name());
        return REQ_POLICY_NONE;

      end

    endcase
  endfunction


  function automatic req_policy_e get_write_req_policy(opcode_t opcode);
    case (opcode)
      SB: begin
        return WRITE_BYTE;
      end
      SH: begin
        return WRITE_HALF_WORD;
      end
      SW, SC_W,
      AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
      AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W: begin
        return WRITE_WORD;
      end
      SD, SC_D,
      AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
      AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D: begin
        return WRITE_DOUBLE_WORD;
      end
      default: begin
        $display("[ERROR] [%s,%0d] Unexpected value was passed over to get_write_req_policy()",
                 `__FILE__, `__LINE__);
        return REQ_POLICY_NONE;
      end
    endcase
  endfunction



  // opcode => データサイズ
  function automatic int unsigned get_data_size_from_opcode(opcode_t opcode);
    case (opcode)
      LB, LBU, SB: return 1;
      LH, LHU, SH: return 2;
      LW, LWU, SW, LR_W, SC_W, AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W,
      AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:
      return 4;
      LD,SD, LR_D,SC_D,  AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D,
      AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D:
      return 8;
      default: return 0;
    endcase
  endfunction



  // 命令がwrite命令かread命令かの判別.
  function automatic logic is_write_policy(input req_policy_e req_policy_origin);
    if (req_policy_origin inside {WRITE_BYTE, WRITE_HALF_WORD, WRITE_WORD, WRITE_DOUBLE_WORD}) begin
      return 1;
    end else begin
      return 0;
    end

  endfunction

  function automatic logic is_read_policy(input req_policy_e req_policy_origin);
    if (req_policy_origin inside {READ_BYTE, READ_HALF_WORD, READ_WORD, READ_DOUBLE_WORD}) begin
      return 1;
    end else begin
      return 0;
    end
  endfunction




  // 比較
  function automatic logic [31:0] max_32(input logic [31:0] a, input logic [31:0] b);
    if (a > b) begin
      return a;
    end else begin
      return b;
    end
  endfunction

  function automatic logic [31:0] min_32(input logic [31:0] a, input logic [31:0] b);
    if (a < b) begin
      return a;
    end else begin
      return b;
    end
  endfunction


  // paddrのalign

  function automatic logic [PADDR_WIDTH-1:0] to_dw_aligned_paddr(logic [PADDR_WIDTH-1:0] paddr);
    return {paddr[PADDR_WIDTH-1:3], 3'b000};
  endfunction




endpackage

`endif
