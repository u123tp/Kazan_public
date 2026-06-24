`timescale 1ns / 1ps
// ALU
// デコーダーでimmを,ビットを並び替え無くても,拡張すればすぐに使えるように32bitで統一して整えられている.
//

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"

module ALU
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
(
    input logic clock,
    input logic reset,
    input logic flush_in,
    input vuop_back_t op_in,
    output vuop_result_t op_out
);
  import HART_DEFS::*;
  import COMMON_PARAMS::*;


  (* use_dsp = "yes" *) logic signed [2*XLEN+1:0] mul_result_ext;

  vuop_result_t op_out_next;

  always_comb begin
    automatic logic [31:0] rs1_val_32 = 0;
    automatic logic [31:0] rs2_val_32 = 0;
    automatic logic [31:0] rd_val_32 = 0;
    automatic logic [127:0] rd_val_128 = 0;

    automatic logic rs1_signed = 0;
    automatic logic [XLEN-1:0] rs1_unsigned = 0;

    automatic logic mul_rs1_signed = 0;
    automatic logic mul_rs2_signed = 0;
    automatic logic mul_higher = 0;

    automatic logic signed [XLEN:0] mul_rs1_ext = 0;
    automatic logic signed [XLEN:0] mul_rs2_ext = 0;




    mul_result_ext = 0;

    op_out_next = '{
        valid: op_in.valid,
        opcode: op_in.opcode,
        op_addr: op_in.op_addr,
        rd_exist: op_in.rd_exist,
        rd: op_in.rd,
        rd_val: 0,
        al_idx: op_in.al_idx,
        actual_taken: 0,
        actual_taken_addr: 0,
        ldst_target_vaddr: 0,
        ldst_target_paddr: 0,
        is_page_fault : 0,
        is_access_fault: 0
    };


    case (op_in.opcode)
      LUI: begin
        // Decoderでimmはシフト済
        op_out_next.rd_val = XLEN'($signed(op_in.imm));

      end
      AUIPC: begin
        op_out_next.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($signed(op_in.imm));

      end

      // ジャンプ命令
      JAL: begin
        op_out_next.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($unsigned(4));

        op_out_next.actual_taken = 1;
        op_out_next.actual_taken_addr =
            VADDR_WIDTH'(XLEN'(unsigned'(op_in.op_addr)) + XLEN'($signed(op_in.imm)));
      end

      JALR: begin
        op_out_next.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($unsigned(4));

        op_out_next.actual_taken = 1;
        // TODO: 丸め込みが必要？？？
        op_out_next.actual_taken_addr =
            VADDR_WIDTH'(op_in.rs1_val + XLEN'($signed(op_in.imm))) & ~VADDR_WIDTH'(1);
      end

      // 分岐命令
      BEQ: begin
        if (op_in.rs1_val == op_in.rs2_val) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end
      BNE: begin
        if (op_in.rs1_val != op_in.rs2_val) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end
      BLT: begin
        if ($signed(op_in.rs1_val) < $signed(op_in.rs2_val)) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end
      BGE: begin
        if ($signed(op_in.rs1_val) >= $signed(op_in.rs2_val)) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end
      BLTU: begin
        if ($unsigned(op_in.rs1_val) < $unsigned(op_in.rs2_val)) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end
      BGEU: begin
        if ($unsigned(op_in.rs1_val) >= $unsigned(op_in.rs2_val)) begin
          op_out_next.actual_taken_addr =
              VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out_next.actual_taken = 1;
        end else begin
          op_out_next.actual_taken = 0;
        end
      end

      // 即値算術命令
      ADDI: begin
        op_out_next.rd_val = op_in.rs1_val + XLEN'($signed(op_in.imm));

      end
      SLTI: begin
        op_out_next.rd_val = $signed(op_in.rs1_val) < XLEN'($signed(op_in.imm)) ? 1 : 0;

      end
      SLTIU: begin
        op_out_next.rd_val = $unsigned(op_in.rs1_val) < XLEN'($signed(op_in.imm)) ? 1 : 0;

      end
      XORI: begin
        op_out_next.rd_val = op_in.rs1_val ^ XLEN'($signed(op_in.imm));

      end
      ORI: begin
        op_out_next.rd_val = op_in.rs1_val | XLEN'($signed(op_in.imm));

      end
      ANDI: begin
        op_out_next.rd_val = op_in.rs1_val & XLEN'($signed(op_in.imm));

      end
      // RV64ではI型の即値の下位6bitを用いる.RV32では下位5bit
      SLLI: begin
        op_out_next.rd_val = op_in.rs1_val << $unsigned(op_in.imm[5:0]);

      end
      SRLI: begin
        op_out_next.rd_val = op_in.rs1_val >> $unsigned(op_in.imm[5:0]);

      end
      SRAI: begin
        op_out_next.rd_val = $signed(op_in.rs1_val) >>> $unsigned(op_in.imm[5:0]);
      end

      ADDIW: begin
        op_out_next.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) + 32'($signed(op_in.imm)))));
      end
      // Shift Left Logical Immidiate Word
      // slliw, srliw,sraiwはshmatが下位5bit
      SLLIW: begin
        op_out_next.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) << $unsigned(op_in.imm[4:0]))));
      end
      // Shift Right Logical Immidiate Word
      SRLIW: begin
        op_out_next.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) >> $unsigned(op_in.imm[4:0]))));
      end

      // Shift Right Arithmetric Immidiate Word
      SRAIW: begin
        op_out_next.rd_val =
            XLEN'($signed(32'($signed(32'(op_in.rs1_val)) >>> $unsigned(op_in.imm[4:0]))));
      end

      // 算術命令
      ADD: begin
        op_out_next.rd_val = op_in.rs1_val + op_in.rs2_val;

      end
      SUB: begin
        op_out_next.rd_val = op_in.rs1_val - op_in.rs2_val;
      end

      SLL: begin
        op_out_next.rd_val = op_in.rs1_val << $unsigned(op_in.rs2_val[5:0]);
      end

      SLT: begin
        op_out_next.rd_val = $signed(op_in.rs1_val) < $signed(op_in.rs2_val) ? 1 : 0;
      end

      OR: begin
        op_out_next.rd_val = op_in.rs1_val | op_in.rs2_val;
      end

      AND: begin
        op_out_next.rd_val = op_in.rs1_val & op_in.rs2_val;
      end

      XOR: begin
        op_out_next.rd_val = op_in.rs1_val ^ op_in.rs2_val;
      end

      // 論理右シフト.
      SRL: begin
        op_out_next.rd_val = $unsigned(op_in.rs1_val) >> $unsigned(op_in.rs2_val[5:0]);
      end

      // 算術右シフト
      SRA: begin
        op_out_next.rd_val = $signed(op_in.rs1_val) >>> $unsigned(op_in.rs2_val[5:0]);
      end

      SLTU: begin
        op_out_next.rd_val = $unsigned(op_in.rs1_val) < $unsigned(op_in.rs2_val) ? 1 : 0;
      end

      ADDW: begin
        op_out_next.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) + 32'(op_in.rs2_val))));
      end

      SUBW: begin
        op_out_next.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) - 32'(op_in.rs2_val))));
      end

      SLLW: begin
        op_out_next.rd_val =
            XLEN'($signed(32'(32'(op_in.rs1_val) << $unsigned(op_in.rs2_val[4:0]))));
      end

      SRAW: begin
        op_out_next.rd_val =
            XLEN'($signed(32'(32'(op_in.rs1_val) >>> $unsigned(op_in.rs2_val[4:0]))));
      end

      SRLW: begin
        op_out_next.rd_val =
            XLEN'($signed(32'(32'(op_in.rs1_val) >> $unsigned(op_in.rs2_val[4:0]))));
      end

      // M拡張
      MUL, MULH, MULHSU, MULHU, MULW: begin
        //
        case (op_in.opcode)
          MUL: begin
            mul_higher  = 1'b0;
            mul_rs1_ext = $signed({1'b0, op_in.rs1_val});
            mul_rs2_ext = $signed({1'b0, op_in.rs2_val});
          end
          MULH: begin
            mul_higher  = 1'b1;
            mul_rs1_ext = $signed({op_in.rs1_val[XLEN-1], op_in.rs1_val});
            mul_rs2_ext = $signed({op_in.rs2_val[XLEN-1], op_in.rs2_val});
          end
          MULHSU: begin
            mul_higher  = 1'b1;
            mul_rs1_ext = $signed({op_in.rs1_val[XLEN-1], op_in.rs1_val});
            mul_rs2_ext = $signed({1'b0, op_in.rs2_val});
          end
          MULHU: begin
            mul_higher  = 1'b1;
            mul_rs1_ext = $signed({1'b0, op_in.rs1_val});
            mul_rs2_ext = $signed({1'b0, op_in.rs2_val});
          end
          MULW: begin
            mul_higher  = 0;
            mul_rs1_ext = (XLEN + 1)'($signed(op_in.rs1_val[31:0]));
            mul_rs2_ext = (XLEN + 1)'($signed(op_in.rs2_val[31:0]));
          end
          default: begin
          end
        endcase

        mul_result_ext = mul_rs1_ext * mul_rs2_ext;

        if (mul_higher) begin
          op_out_next.rd_val = mul_result_ext[XLEN*2-1:XLEN];
        end else begin
          op_out_next.rd_val = mul_result_ext[XLEN-1:0];
        end

      end


      default: ;
    endcase

    // For Debug
    // if (op_in.valid) begin
    //   $display(
    //       "[LOG] [%s,%-d] addr:%016h, opcode:%s, rs1:%h(%016h), rs2:%h(%016h), imm:%016h rd:%h(%016h) ActualTaken:%b, ActualTakenAddr:%016h",
    //       `__FILE__, `__LINE__, op_in.op_addr, op_in.opcode.name(), op_in.rs1, op_in.rs1_val,
    //       op_in.rs2, op_in.rs2_val, op_in.imm, op_in.rd, op_out_next.rd_val, op_out_next.actual_taken,
    //       op_out_next.actual_taken_addr);
    // end
  end

  always_ff @(posedge clock) begin
    if (reset) begin
      op_out <= '{opcode: NOP, default: 0};
    end else if (flush_in) begin
      op_out <= '{opcode: NOP, default: 0};
    end else begin
      op_out <= op_out_next;
    end
  end


endmodule
