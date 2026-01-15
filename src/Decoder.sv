`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"

module Decoder
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
#(
) (
    input logic clock,
    input logic reset,

    // Fetcher から送られてきた内容.
    input ifq_decoder_t fetched_content_cur[NUM_OF_FETCH],

    // 出力.
    output decoded_op_t decoded_op[NUM_OF_FETCH],

    // 分岐予測で飛んでいたアドレスが間違えていた場合など,
    // Decoderより前のステージの内容をflushしてpcを新しい値に設定する.
    output addr_with_valid_t mispred_mod,

    input  logic stall_in,
    output logic stall_out,
    input  logic flush_in
);


  // ---------------------------------------
  // stall用.
  // ---------------------------------------
  ifq_decoder_t fetched_content[NUM_OF_FETCH];

  ifq_decoder_t fetched_content_pending[NUM_OF_FETCH];
  logic is_pending;
  ifq_decoder_t fetched_content_pending_next[NUM_OF_FETCH];
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    fetched_content_pending_next = fetched_content_pending;

    if (flush_in) begin
      fetched_content = '{default: 0};
      is_pending_next = 0;
    end else if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      fetched_content_pending_next = fetched_content_cur;
      is_pending_next = 1;
      fetched_content = '{default: 0};
    end else if (stall_in) begin
      // 継続でstallした場合.
      fetched_content = '{default: 0};
    end else if (is_pending) begin
      // stall終了時.
      fetched_content = fetched_content_pending;
      is_pending_next = 0;
    end else begin
      // 通常時.
      fetched_content = fetched_content_cur;
    end
  end

  always_comb begin
    stall_out = stall_in;
  end

  // ------------------------
  // 出力
  // ------------------------
  decoded_op_t decoded_op_next[NUM_OF_FETCH];


  // instrを各要素に分解するための変数.
  logic [6:0] opcode[NUM_OF_FETCH];
  logic [2:0] funct3[NUM_OF_FETCH];
  logic [6:0] funct7[NUM_OF_FETCH];
  logic [4:0] rs1[NUM_OF_FETCH];
  logic [4:0] rs2[NUM_OF_FETCH];
  logic [4:0] rd[NUM_OF_FETCH];
  logic [XLEN-1:0] imm_i[NUM_OF_FETCH];  // I-type命令用即値
  logic [XLEN-1:0] imm_iu[NUM_OF_FETCH];
  logic [XLEN-1:0] imm_s[NUM_OF_FETCH];  // S-type命令用即値
  logic [XLEN-1:0] imm_b[NUM_OF_FETCH];  // B-type命令用即値
  logic [XLEN-1:0] imm_u[NUM_OF_FETCH];  // U-type命令用即値
  logic [XLEN-1:0] imm_j[NUM_OF_FETCH];  // J-type命令用即値
  logic [VADDR_WIDTH-1:0] vaddr[NUM_OF_FETCH];
  logic [PADDR_WIDTH-1:0] paddr[NUM_OF_FETCH];
  logic pred_taken[NUM_OF_FETCH];
  logic btb_hit[NUM_OF_FETCH];
  logic [VADDR_WIDTH-1:0] btb_addr[NUM_OF_FETCH];



  // instrを各要素に分解する.
  always_comb begin
    for (int i = 0; i < NUM_OF_FETCH; i++) begin
      logic [31:0] fdata = fetched_content[i].data;
      vaddr[i] = fetched_content[i].vaddr;
      paddr[i] = fetched_content[i].paddr;
      opcode[i] = fdata[6:0];
      funct3[i] = fdata[14:12];
      funct7[i] = fdata[31:25];
      rs1[i] = fdata[19:15];
      rs2[i] = fdata[24:20];
      rd[i] = fdata[11:7];
      imm_i[i] = XLEN'($signed(fdata[31:20]));
      imm_iu[i] = XLEN'($unsigned(fdata[31:20]));
      imm_s[i] = XLEN'($signed({fdata[31:25], fdata[11:7]}));
      imm_b[i] = XLEN'($signed({fdata[31], fdata[7], fdata[30:25], fdata[11:8], 1'b0}));
      imm_u[i] = XLEN'($signed({fdata[31:12], 12'b0}));
      imm_j[i] = XLEN'($signed({fdata[31], fdata[19:12], fdata[20], fdata[30:21], 1'b0}));
      pred_taken[i] = fetched_content[i].pred_taken;
      btb_hit[i] = fetched_content[i].btb_hit;
      btb_addr[i] = fetched_content[i].btb_addr;
    end
  end


  always_comb begin
    // 初期化.どの位置でもrs1,rs2,rdの位置は共通.
    for (int i = 0; i < NUM_OF_FETCH; i++) begin
      decoded_op_next[i] = '{
          valid       : 0,
          vaddr: vaddr[i],
          paddr: paddr[i],
          opcode      : NOP,
          rs1: rs1[i],
          rs2: rs2[i],
          rd: rd[i],
          pred_taken: pred_taken[i],
          btb_hit: btb_hit[i],
          btb_addr: btb_addr[i],
          raw_op: fetched_content[i].data,
          is_page_fault: fetched_content[i].is_page_fault,
          is_access_fault: fetched_content[i].is_access_fault,
          default: 0
      };
    end
    mispred_mod = '{valid: 0, addr: 0};

    // フェッチした内容に基づいてデコードしていく.
    for (int i = 0; i < NUM_OF_FETCH; i++) begin
      if (fetched_content[i].valid) begin
        decoded_op_next[i].valid = 1;
        casez ({
          opcode[i], funct3[i], funct7[i]
        })
          // 即値ロード命令.
          17'b0110111_???_???????: begin
            decoded_op_next[i].opcode = LUI;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_u[i];
          end
          17'b0010111_???_???????: begin
            decoded_op_next[i].opcode = AUIPC;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_u[i];
          end

          // ジャンプ系命令.
          17'b1101111_???_???????: begin
            decoded_op_next[i].opcode = JAL;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_j[i];
          end
          17'b1100111_000_???????: begin
            decoded_op_next[i].opcode = JALR;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end

          // 分岐命令.
          17'b1100011_000_???????: begin
            decoded_op_next[i].opcode = BEQ;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end
          17'b1100011_001_???????: begin
            decoded_op_next[i].opcode = BNE;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end
          17'b1100011_100_???????: begin
            decoded_op_next[i].opcode = BLT;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end
          17'b1100011_101_???????: begin
            decoded_op_next[i].opcode = BGE;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end
          17'b1100011_110_???????: begin
            decoded_op_next[i].opcode = BLTU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end
          17'b1100011_111_???????: begin
            decoded_op_next[i].opcode = BGEU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_b[i];
          end

          // ロード系命令.
          17'b0000011_000_???????: begin
            decoded_op_next[i].opcode = LB;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_001_???????: begin
            decoded_op_next[i].opcode = LH;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_010_???????: begin
            decoded_op_next[i].opcode = LW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_011_???????: begin
            decoded_op_next[i].opcode = LD;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_100_???????: begin
            decoded_op_next[i].opcode = LBU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_101_???????: begin
            decoded_op_next[i].opcode = LHU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0000011_110_???????: begin
            decoded_op_next[i].opcode = LWU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end

          // ストア系命令
          17'b0100011_000_???????: begin
            decoded_op_next[i].opcode = SB;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_s[i];
          end
          17'b0100011_001_???????: begin
            decoded_op_next[i].opcode = SH;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_s[i];
          end
          17'b0100011_010_???????: begin
            decoded_op_next[i].opcode = SW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_s[i];
          end
          17'b0100011_011_???????: begin
            decoded_op_next[i].opcode = SD;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_s[i];
          end

          // 算術命令
          17'b0010011_000_???????: begin
            decoded_op_next[i].opcode = ADDI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0010011_010_???????: begin
            decoded_op_next[i].opcode = SLTI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0010011_011_???????: begin
            decoded_op_next[i].opcode = SLTIU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0010011_100_???????: begin
            decoded_op_next[i].opcode = XORI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0010011_110_???????: begin
            decoded_op_next[i].opcode = ORI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0010011_111_???????: begin
            decoded_op_next[i].opcode = ANDI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          // SLLI、SRLI,SRAIは一応I-typeだがshamtの値が64bitでのみ下位6bitとなり,
          // 通常のimm_iをshmatとして指定をするとSRAIで不都合が起こるのでSRAIに合わせる形でビットマスクをする.
          17'b0010011_001_000000?: begin
            decoded_op_next[i].opcode = SLLI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b111111;
          end
          17'b0010011_101_000000?: begin
            decoded_op_next[i].opcode = SRLI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b111111;
          end
          17'b0010011_101_010000?: begin
            decoded_op_next[i].opcode = SRAI;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b111111;
          end

          // 算術命令(非即値)
          17'b0110011_000_0000000: begin
            decoded_op_next[i].opcode = ADD;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_000_0100000: begin
            decoded_op_next[i].opcode = SUB;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_001_0000000: begin
            decoded_op_next[i].opcode = SLL;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_010_0000000: begin
            decoded_op_next[i].opcode = SLT;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_011_0000000: begin
            decoded_op_next[i].opcode = SLTU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_100_0000000: begin
            decoded_op_next[i].opcode = XOR;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_101_0000000: begin
            decoded_op_next[i].opcode = SRL;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_101_0100000: begin
            decoded_op_next[i].opcode = SRA;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_110_0000000: begin
            decoded_op_next[i].opcode = OR;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_111_0000000: begin
            decoded_op_next[i].opcode = AND;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          // https://stackoverflow.com/questions/56717361/what-is-meant-by-fence-tso-in-the-risc-v-isa?utm_source=chatgpt.com
          // によるとfence.tsoはfence rw rwを少し条件をゆるくしたものなのでfence.tsoのかわりにfence rw rwをやれば十分
          // あとpause1はhintなのでnopでいい。
          // pauseのようなhint命令はfence w,∅　と同じ意味であり,これはsuccが存在しないので,何も意味していない。
          // 実際の操作の時にpred,succが空なら何もしないようにしておけばpauseの実装はOK.
          // 以上から,FENCE, FENCE.TSO, PAUSEの実装はFENCE実装だけしてれば良い。
          17'b0001111_000_???????: begin
            decoded_op_next[i].opcode = FENCE;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = imm_i[i];
          end

          // ECALL,EBREAK,MRET,SRET,WFI,FENCE_VMA
          17'b1110011_000_???????: begin
            casez (imm_i[i][11:0])
              12'b000000000000: begin
                decoded_op_next[i].opcode = ECALL;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = 'b0;
              end
              12'b000000000001: begin
                decoded_op_next[i].opcode = EBREAK;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = 'b0;
              end
              12'b0001000_00010: begin
                decoded_op_next[i].opcode = SRET;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = imm_i[i];
              end
              12'b0011000_00010: begin
                decoded_op_next[i].opcode = MRET;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = imm_i[i];
              end
              12'b0001000_00101: begin
                // WFIをNOPとして実装する.
                decoded_op_next[i].opcode = WFI;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = imm_i[i];
              end
              12'b0001001?????: begin
                decoded_op_next[i].opcode = SFENCE_VMA;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = imm_i[i];
              end
              default: begin
                decoded_op_next[i].opcode = ILLEGAL_INSTR;
                decoded_op_next[i].rs1_exist = 0;
                decoded_op_next[i].rs2_exist = 0;
                decoded_op_next[i].rd_exist = 0;
                decoded_op_next[i].imm = 0;
              end
            endcase
          end


          17'b0011011_000_???????: begin
            decoded_op_next[i].opcode = ADDIW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b0011011_001_0000000: begin
            decoded_op_next[i].opcode = SLLIW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b11111;
          end
          17'b0011011_101_0000000: begin
            decoded_op_next[i].opcode = SRLIW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b11111;
          end
          17'b0011011_101_0100000: begin
            decoded_op_next[i].opcode = SRAIW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i] & 'b11111;
          end
          17'b0111011_000_0000000: begin
            decoded_op_next[i].opcode = ADDW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0111011_000_0100000: begin
            decoded_op_next[i].opcode = SUBW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0111011_001_0000000: begin
            decoded_op_next[i].opcode = SLLW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0111011_101_0000000: begin
            decoded_op_next[i].opcode = SRLW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0111011_101_0100000: begin
            decoded_op_next[i].opcode = SRAW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          // RV64 Zifencei 標準拡張
          17'b0001111_001_???????: begin
            decoded_op_next[i].opcode = FENCE_I;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = 'b0;
          end

          // RV64 Zicsr 標準拡張
          17'b1110011_001_???????: begin
            decoded_op_next[i].opcode = CSRRW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b1110011_010_???????: begin
            decoded_op_next[i].opcode = CSRRS;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end
          17'b1110011_011_???????: begin
            decoded_op_next[i].opcode = CSRRC;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = imm_i[i];
          end

          // https://five-embeddev.com/riscv-user-isa-manual/Priv-v1.12/csr.html
          17'b1110011_101_???????: begin
            decoded_op_next[i].opcode = CSRRWI;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = {47'b0, rs1[i], imm_i[i][11:0]};  //  47+5+12 
          end
          17'b1110011_110_???????: begin
            decoded_op_next[i].opcode = CSRRSI;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = {47'b0, rs1[i], imm_i[i][11:0]};  //  47+5+12 
          end
          17'b1110011_111_???????: begin
            decoded_op_next[i].opcode = CSRRCI;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = {47'b0, rs1[i], imm_i[i][11:0]};  //  47+5+12 
          end

          // ---------------------------------------------------------------------
          // M拡張
          // ----------------------------------------------------------------------
          17'b0110011_000_0000001: begin
            decoded_op_next[i].opcode = MUL;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_001_0000001: begin
            decoded_op_next[i].opcode = MULH;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0110011_010_0000001: begin
            decoded_op_next[i].opcode = MULHSU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_011_0000001: begin
            decoded_op_next[i].opcode = MULHU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_100_0000001: begin
            decoded_op_next[i].opcode = DIV;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end
          17'b0110011_101_0000001: begin
            decoded_op_next[i].opcode = DIVU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0110011_110_0000001: begin
            decoded_op_next[i].opcode = REM;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0110011_111_0000001: begin
            decoded_op_next[i].opcode = REMU;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0111011_000_0000001: begin
            decoded_op_next[i].opcode = MULW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0111011_100_0000001: begin
            decoded_op_next[i].opcode = DIVW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          17'b0111011_101_0000001: begin
            decoded_op_next[i].opcode = DIVUW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          17'b0111011_110_0000001: begin
            decoded_op_next[i].opcode = REMW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          17'b0111011_111_0000001: begin
            decoded_op_next[i].opcode = REMUW;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          // ----------------------------------------------------------------------
          // A拡張
          // ----------------------------------------------------------------------

          17'b0101111_010_00010??: begin
            decoded_op_next[i].opcode = LR_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_00011??: begin
            decoded_op_next[i].opcode = SC_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_00001??: begin
            decoded_op_next[i].opcode = AMOSWAP_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_00000??: begin
            decoded_op_next[i].opcode = AMOADD_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_00100??: begin
            decoded_op_next[i].opcode = AMOXOR_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_01100??: begin
            decoded_op_next[i].opcode = AMOAND_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_01000??: begin
            decoded_op_next[i].opcode = AMOOR_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          17'b0101111_010_10000??: begin
            decoded_op_next[i].opcode = AMOMIN_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_10100??: begin
            decoded_op_next[i].opcode = AMOMAX_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_11000??: begin
            decoded_op_next[i].opcode = AMOMINU_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_010_11100??: begin
            decoded_op_next[i].opcode = AMOMAXU_W;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_00010??: begin
            decoded_op_next[i].opcode = LR_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_00011??: begin
            decoded_op_next[i].opcode = SC_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          17'b0101111_011_00001??: begin
            decoded_op_next[i].opcode = AMOSWAP_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_00000??: begin
            decoded_op_next[i].opcode = AMOADD_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_00100??: begin
            decoded_op_next[i].opcode = AMOXOR_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_01100??: begin
            decoded_op_next[i].opcode = AMOAND_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_01000??: begin
            decoded_op_next[i].opcode = AMOOR_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_10000??: begin
            decoded_op_next[i].opcode = AMOMIN_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_10100??: begin
            decoded_op_next[i].opcode = AMOMAX_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_11000??: begin
            decoded_op_next[i].opcode = AMOMINU_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end

          17'b0101111_011_11100??: begin
            decoded_op_next[i].opcode = AMOMAXU_D;
            decoded_op_next[i].rs1_exist = 1;
            decoded_op_next[i].rs2_exist = 1;
            decoded_op_next[i].rd_exist = 1;
            decoded_op_next[i].imm = 'b0;
          end


          default: begin
            decoded_op_next[i].opcode = ILLEGAL_INSTR;
            decoded_op_next[i].rs1_exist = 0;
            decoded_op_next[i].rs2_exist = 0;
            decoded_op_next[i].rd_exist = 0;
            decoded_op_next[i].imm = {{32{1'b0}}, fetched_content[i].data};
          end
        endcase

        // predictor,btbが両方ヒットしたが、間違いであったことがデコーダで判明するのは次のパターンがある
        //・実は非分岐命令,非ジャンプ命令だった
        //・分岐命令で,btbで予測した飛び先は誤りだった
        // また,これに加えて 
        // ・分岐命令でpredictorがtakenとしたが,btbがヒットしなかった.

        if (!is_branch_opcode(
                decoded_op_next[i].opcode
            ) && !is_jmp_opcode(
                decoded_op_next[i].opcode
            ) && pred_taken[i] && btb_hit[i]) begin
          //・predでもbtbでもヒットして,飛んでしまったが,実は非分岐命令,非ジャンプ命令だった
          mispred_mod = '{valid: 1, addr: vaddr[i] + VADDR_WIDTH'(4)};
          break;
        end else if (is_branch_opcode(
                decoded_op_next[i].opcode
            ) && pred_taken[i] && btb_hit[i] &&
                btb_addr[i] != vaddr[i] + imm_b[i][VADDR_WIDTH-1:0]) begin
          //・分岐命令で,btbで予測した飛び先は誤りだった
          mispred_mod = '{valid: 1, addr: vaddr[i] + imm_b[i][VADDR_WIDTH-1:0]};
          break;
        end else if (is_branch_opcode(
                decoded_op_next[i].opcode
            ) && pred_taken[i] && !btb_hit[i]) begin
          // ・分岐命令でpredictorがtakenとしたが,btbがヒットしなかった,そのため,decoderで実際の飛び先を計算した.
          mispred_mod = '{valid: 1, addr: vaddr[i] + VADDR_WIDTH'(decoded_op_next[i].imm)};
          break;
        end

      end
    end
  end

  int fp;
  initial begin
    fp = $fopen("./log/decoderlog.txt", "w");
  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      fetched_content_pending <= '{default: 0};
      is_pending <= 0;

      // 出力
      decoded_op <= '{default: 0};
    end else if (flush_in) begin
      fetched_content_pending <= '{default: 0};
      is_pending <= 0;

      // 出力
      decoded_op <= '{default: 0};

      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (decoded_op[i].valid) begin
`ifdef DECODERLOG_EN
          $fdisplay(
              fp,
              "[DECODED] i=%0d op=%0d vaddr=%016h paddr=%016h raw=%08h rs1(%0d)=%0d rs2(%0d)=%0d rd(%0d)=%0d imm=%016h pred=%0d hit=%0d btb=%016h pf=%0d af=%0d",
              i, decoded_op[i].opcode, decoded_op[i].vaddr, decoded_op[i].paddr,
              decoded_op[i].raw_op, decoded_op[i].rs1_exist, decoded_op[i].rs1,
              decoded_op[i].rs2_exist, decoded_op[i].rs2, decoded_op[i].rd_exist, decoded_op[i].rd,
              decoded_op[i].imm, decoded_op[i].pred_taken, decoded_op[i].btb_hit,
              decoded_op[i].btb_addr, decoded_op[i].is_page_fault, decoded_op[i].is_access_fault);
`endif
        end
      end
    end else begin
      fetched_content_pending <= fetched_content_pending_next;
      is_pending <= is_pending_next;

      // 出力
      decoded_op <= decoded_op_next;

      for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
        if (decoded_op[i].valid) begin
`ifdef DECODERLOG_EN
          $fdisplay(
              fp,
              "[DECODED] i=%0d op=%0d vaddr=%016h paddr=%016h raw=%08h rs1(%0d)=%0d rs2(%0d)=%0d rd(%0d)=%0d imm=%016h pred=%0d hit=%0d btb=%016h pf=%0d af=%0d",
              i, decoded_op[i].opcode, decoded_op[i].vaddr, decoded_op[i].paddr,
              decoded_op[i].raw_op, decoded_op[i].rs1_exist, decoded_op[i].rs1,
              decoded_op[i].rs2_exist, decoded_op[i].rs2, decoded_op[i].rd_exist, decoded_op[i].rd,
              decoded_op[i].imm, decoded_op[i].pred_taken, decoded_op[i].btb_hit,
              decoded_op[i].btb_addr, decoded_op[i].is_page_fault, decoded_op[i].is_access_fault);
`endif
        end
      end

    end
  end

endmodule
