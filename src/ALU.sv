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
    input  vuop_back_t   op_in,
    output vuop_result_t op_out
);
  import HART_DEFS::*;
  import COMMON_PARAMS::*;


  always_comb begin
    logic [31:0] rs1_val_32 = 0;
    logic [31:0] rs2_val_32 = 0;
    logic [31:0] rd_val_32 = 0;
    logic [127:0] rd_val_128 = 0;

    logic rs1_signed = 0;
    logic [XLEN-1:0] rs1_unsigned = 0;

    op_out = '{
        valid: op_in.valid,
        opcode: op_in.opcode,
        op_addr: op_in.op_addr,
        rd_exist: op_in.rd_exist,
        rd: op_in.rd,
        rd_val: 0,
        al_idx: op_in.al_idx,
        actual_taken: 0,
        actual_taken_addr: 0,
        ldst_target_addr: 0,
        is_page_fault : 0,
        is_access_fault: 0
    };


    case (op_in.opcode)
      LUI: begin
        // Decoderでimmはシフト済
        op_out.rd_val = XLEN'($signed(op_in.imm));

      end
      AUIPC: begin
        op_out.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($signed(op_in.imm));

      end

      // ジャンプ命令
      JAL: begin
        op_out.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($unsigned(4));

        op_out.actual_taken = 1;
        op_out.actual_taken_addr =
            VADDR_WIDTH'(XLEN'(unsigned'(op_in.op_addr)) + XLEN'($signed(op_in.imm)));
      end

      JALR: begin
        op_out.rd_val = XLEN'(unsigned'(op_in.op_addr)) + XLEN'($unsigned(4));

        op_out.actual_taken = 1;
        // TODO: 丸め込みが必要？？？
        op_out.actual_taken_addr =
            VADDR_WIDTH'(op_in.rs1_val + XLEN'($signed(op_in.imm))) & ~VADDR_WIDTH'(1);
      end

      // 分岐命令
      BEQ: begin
        if (op_in.rs1_val == op_in.rs2_val) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end
      BNE: begin
        if (op_in.rs1_val != op_in.rs2_val) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end
      BLT: begin
        if ($signed(op_in.rs1_val) < $signed(op_in.rs2_val)) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end
      BGE: begin
        if ($signed(op_in.rs1_val) >= $signed(op_in.rs2_val)) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end
      BLTU: begin
        if ($unsigned(op_in.rs1_val) < $unsigned(op_in.rs2_val)) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end
      BGEU: begin
        if ($unsigned(op_in.rs1_val) >= $unsigned(op_in.rs2_val)) begin
          op_out.actual_taken_addr = VADDR_WIDTH'(op_in.op_addr + VADDR_WIDTH'($signed(op_in.imm)));
          op_out.actual_taken = 1;
        end else begin
          op_out.actual_taken = 0;
        end
      end

      // 即値算術命令
      ADDI: begin
        op_out.rd_val = op_in.rs1_val + XLEN'($signed(op_in.imm));

      end
      SLTI: begin
        op_out.rd_val = $signed(op_in.rs1_val) < XLEN'($signed(op_in.imm)) ? 1 : 0;

      end
      SLTIU: begin
        op_out.rd_val = $unsigned(op_in.rs1_val) < XLEN'($signed(op_in.imm)) ? 1 : 0;

      end
      XORI: begin
        op_out.rd_val = op_in.rs1_val ^ XLEN'($signed(op_in.imm));

      end
      ORI: begin
        op_out.rd_val = op_in.rs1_val | XLEN'($signed(op_in.imm));

      end
      ANDI: begin
        op_out.rd_val = op_in.rs1_val & XLEN'($signed(op_in.imm));

      end
      // RV64ではI型の即値の下位6bitを用いる.RV32では下位5bit
      SLLI: begin
        op_out.rd_val = op_in.rs1_val << $unsigned(op_in.imm[5:0]);

      end
      SRLI: begin
        op_out.rd_val = op_in.rs1_val >> $unsigned(op_in.imm[5:0]);

      end
      SRAI: begin
        op_out.rd_val = $signed(op_in.rs1_val) >>> $unsigned(op_in.imm[5:0]);
      end

      ADDIW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) + 32'($signed(op_in.imm)))));
      end
      // Shift Left Logical Immidiate Word
      // slliw, srliw,sraiwはshmatが下位5bit
      SLLIW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) << $unsigned(op_in.imm[4:0]))));
      end
      // Shift Right Logical Immidiate Word
      SRLIW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) >> $unsigned(op_in.imm[4:0]))));
      end

      // Shift Right Arithmetric Immidiate Word
      SRAIW: begin
        op_out.rd_val =
            XLEN'($signed(32'($signed(32'(op_in.rs1_val)) >>> $unsigned(op_in.imm[4:0]))));
      end

      // 算術命令
      ADD: begin
        op_out.rd_val = op_in.rs1_val + op_in.rs2_val;

      end
      SUB: begin
        op_out.rd_val = op_in.rs1_val - op_in.rs2_val;
      end

      SLL: begin
        op_out.rd_val = op_in.rs1_val << $unsigned(op_in.rs2_val[5:0]);
      end

      SLT: begin
        op_out.rd_val = $signed(op_in.rs1_val) < $signed(op_in.rs2_val) ? 1 : 0;
      end

      OR: begin
        op_out.rd_val = op_in.rs1_val | op_in.rs2_val;
      end

      AND: begin
        op_out.rd_val = op_in.rs1_val & op_in.rs2_val;
      end

      XOR: begin
        op_out.rd_val = op_in.rs1_val ^ op_in.rs2_val;
      end

      // 論理右シフト.
      SRL: begin
        op_out.rd_val = $unsigned(op_in.rs1_val) >> $unsigned(op_in.rs2_val[5:0]);
      end

      // 算術右シフト
      SRA: begin
        op_out.rd_val = $signed(op_in.rs1_val) >>> $unsigned(op_in.rs2_val[5:0]);
      end

      SLTU: begin
        op_out.rd_val = $unsigned(op_in.rs1_val) < $unsigned(op_in.rs2_val) ? 1 : 0;
      end

      ADDW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) + 32'(op_in.rs2_val))));
      end

      SUBW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) - 32'(op_in.rs2_val))));
      end

      SLLW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) << $unsigned(op_in.rs2_val[4:0]))));
      end

      SRAW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) >>> $unsigned(op_in.rs2_val[4:0]))));
      end

      SRLW: begin
        op_out.rd_val = XLEN'($signed(32'(32'(op_in.rs1_val) >> $unsigned(op_in.rs2_val[4:0]))));
      end

      // M拡張
      MUL: begin
        op_out.rd_val = XLEN'((signed'(op_in.rs1_val)) * (signed'(op_in.rs2_val)));
      end

      MULH: begin
        rd_val_128 = signed'(op_in.rs1_val) * signed'(op_in.rs2_val);
        op_out.rd_val = rd_val_128[XLEN*2-1:XLEN];
      end

      MULHSU: begin
        // rs1を符号付き,rs2を符号なしの値として解釈し,その結果を符号付きとして計算する.
        // rdにはその結果の上位XLENビットが格納される.
        rd_val_128 = (signed'(op_in.rs1_val) * signed'({{1{1'b0}}, op_in.rs2_val}));
        op_out.rd_val = rd_val_128[XLEN*2-1:XLEN];
      end

      MULHU: begin
        rd_val_128 = unsigned'(op_in.rs1_val) * unsigned'(op_in.rs2_val);
        op_out.rd_val = rd_val_128[XLEN*2-1:XLEN];
      end

      DIV: begin
        if (op_in.rs2_val == 0) begin
          // 0除算なら-1(全ビットが1)にする
          op_out.rd_val = {XLEN{1'b1}};
        end else if (op_in.rs1_val == {1'b1, {(XLEN - 1) {1'b0}}} &&
                op_in.rs2_val == {XLEN{1'b1}}) begin
          // 2の補数表示だと,負数のほうが表せる数が多い.
          // 例えば, -128 ~ 127 を表せる場合だと, -128 / -1 = 128 はオーバーフローする.
          // 最小値は0と同じように補数をとっても同じ数字に戻る.
          op_out.rd_val = op_in.rs1_val;
        end else begin
          op_out.rd_val = signed'(op_in.rs1_val) / signed'(op_in.rs2_val);
        end
      end

      DIVU: begin
        if (op_in.rs2_val == 0) begin
          // 0除算
          op_out.rd_val = {XLEN{1'b1}};
        end else begin
          op_out.rd_val = unsigned'(op_in.rs1_val) / unsigned'(op_in.rs2_val);
        end
      end

      REM: begin
        if (op_in.rs2_val == 0) begin
          // 0除算の場合,被除数をそのまま.
          op_out.rd_val = op_in.rs1_val;
        end else if( op_in.rs1_val == {1'b1, {(XLEN - 1) {1'b0}}} &&
                op_in.rs2_val == {XLEN{1'b1}})begin
          // 2の補数表示だと,負数のほうが表せる数が多い.
          // 例えば, -128 ~ 127 を表せる場合だと, -128 / -1 はオーバーフロー.
          op_out.rd_val = 0;
        end else begin
          op_out.rd_val = signed'(op_in.rs1_val) % signed'(op_in.rs2_val);
        end
      end

      REMU: begin
        if (op_in.rs2_val == 0) begin
          // 0除算
          op_out.rd_val = op_in.rs1_val;
        end else begin
          op_out.rd_val = unsigned'(op_in.rs1_val) % unsigned'(op_in.rs2_val);
        end
      end

      MULW: begin
        rs1_val_32 = 32'(op_in.rs1_val);
        rs2_val_32 = 32'(op_in.rs2_val);
        rd_val_32 = 32'(signed'(op_in.rs1_val[31:0]) * signed'(op_in.rs2_val[31:0]));
        op_out.rd_val = XLEN'(signed'(rd_val_32));
      end

      DIVW: begin
        rs1_val_32 = 32'(op_in.rs1_val);
        rs2_val_32 = 32'(op_in.rs2_val);
        if (rs2_val_32 == 0) begin
          // 0除算
          op_out.rd_val = {XLEN{1'b1}};
        end else if (rs1_val_32 == {1'b1, (31)'(1'b0)} && rs2_val_32 == 32'(signed'(1'b1))) begin
          // 2の補数表示だと,負数のほうが表せる数が多い.
          // 例えば, -128 ~ 127 を表せる場合だと, -128 / -1 はオーバーフロー.
          op_out.rd_val = XLEN'(signed'(rs1_val_32));
        end else begin
          op_out.rd_val = XLEN'(signed'(signed'(rs1_val_32) / signed'(rs2_val_32)));
        end
      end

      DIVUW: begin
        rs1_val_32 = 32'(op_in.rs1_val);
        rs2_val_32 = 32'(op_in.rs2_val);
        if (rs2_val_32 == 0) begin
          // 0除算
          op_out.rd_val = {XLEN{1'b1}};
        end else begin
          op_out.rd_val = XLEN'(signed'(unsigned'(rs1_val_32) / unsigned'(rs2_val_32)));
        end
      end

      REMW: begin
        rs1_val_32 = 32'(op_in.rs1_val);
        rs2_val_32 = 32'(op_in.rs2_val);
        if (rs2_val_32 == 0) begin
          // 0除算
          op_out.rd_val = op_in.rs1_val;
        end else if (rs1_val_32 == {1'b1, (31)'(1'b0)} && rs2_val_32 == 32'(signed'(1'b1))) begin
          // 2の補数表示だと,負数のほうが表せる数が多い.
          // 例えば, -128 ~ 127 を表せる場合だと, -128 / -1 はオーバーフロー.
          op_out.rd_val = 0;
        end else begin
          op_out.rd_val = XLEN'(signed'(signed'(rs1_val_32) % signed'(rs2_val_32)));
        end
      end

      REMUW: begin
        rs1_val_32 = 32'(op_in.rs1_val);
        rs2_val_32 = 32'(op_in.rs2_val);
        if (rs2_val_32 == 0) begin
          // 0除算
          op_out.rd_val = op_in.rs1_val;
        end else begin
          op_out.rd_val = XLEN'(signed'(unsigned'(rs1_val_32) % unsigned'(rs2_val_32)));
        end
      end

      default: ;
    endcase

    // For Debug
    // if (op_in.valid) begin
    //   $display(
    //       "[LOG] [%s,%-d] addr:%016h, opcode:%s, rs1:%h(%016h), rs2:%h(%016h), imm:%016h rd:%h(%016h) ActualTaken:%b, ActualTakenAddr:%016h",
    //       `__FILE__, `__LINE__, op_in.op_addr, op_in.opcode.name(), op_in.rs1, op_in.rs1_val,
    //       op_in.rs2, op_in.rs2_val, op_in.imm, op_in.rd, op_out.rd_val, op_out.actual_taken,
    //       op_out.actual_taken_addr);
    // end
  end

endmodule
