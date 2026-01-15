// CSRの実行ユニット.
// とりあえずop_in[0]だけ処理する.CSR_EXEも1だし大丈夫でしょ.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"



module CSRUnit
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
(
    input logic clock,
    input logic reset,

    // op
    input  vuop_back_t   op_in [NUM_OF_CSR_EXE],
    output vuop_result_t op_out[NUM_OF_CSR_EXE],

    // renamerからのcsrコミット通知.
    csru_renamer_if.csru renamer_port,

    input  logic flush_in,
    output logic stall_out,

    csr_csru_if.csru csr_port
);

  vuop_result_t op_out_next[NUM_OF_CSR_EXE];

  // ------------------------------------------------------
  // パラメータ
  // ------------------------------------------------------
  localparam int unsigned CSRQ_SIZE = 8;
  localparam int unsigned CSRQ_IDX_WIDTH = $clog2(CSRQ_SIZE);


  // -------------------------------------------------------
  // csrキュー
  // -------------------------------------------------------
  // どうせリセットするのでとりあえず要素は一つでいい.
  typedef enum logic {
    BEFORE_DONE,
    DONE  // コミットはまだ.
  } csrq_state_e;

  typedef struct packed {
    csrq_state_e state;
    vuop_back_t  op;
  } csrq_t;

  // 要素一つのキュー
  csrq_t csrq[CSRQ_SIZE];
  csrq_t csrq_next[CSRQ_SIZE];
  logic [CSRQ_IDX_WIDTH-1:0] csrq_rp;
  logic [CSRQ_IDX_WIDTH-1:0] csrq_rp_next;
  logic [CSRQ_IDX_WIDTH-1:0] csrq_wp;
  logic [CSRQ_IDX_WIDTH-1:0] csrq_wp_next;
  int unsigned num_of_entries_in_csrq;
  int unsigned num_of_entries_in_csrq_next;


  // 読み込みリクエスト
  logic [XLEN-1:0] old_csr_val;
  // circularにならないように書き込みと分ける.
  always_comb begin
    csr_port.read_req = '{valid: 1, csr_name: csr_name_e'(csrq[csrq_rp].op.imm[11:0])};
  end
  always_comb begin
    old_csr_val = csr_port.read_res.data;
  end

  // renamerでコミットした命令を反映
  always_comb begin
    logic is_write_csr = 0;
    // 初期化
    csrq_next = csrq;
    csrq_rp_next = csrq_rp;
    csrq_wp_next = csrq_wp;
    num_of_entries_in_csrq_next = num_of_entries_in_csrq;


    csr_port.write_req = '{default: 0, csr_name: FFLAGS};
    op_out_next = '{default: 0};

    // 仮実行.
    if (num_of_entries_in_csrq_next != 0 && renamer_port.executable_csr.valid &&
          renamer_port.executable_csr.al_idx == csrq_next[csrq_rp_next].op.al_idx && csrq_next[csrq_rp_next].state == BEFORE_DONE) begin


      op_out_next[0] = '{
          valid: 1,
          opcode: csrq_next[csrq_rp_next].op.opcode,
          op_addr: csrq_next[csrq_rp_next].op.op_addr,
          rd_exist: 1,
          rd : csrq_next[csrq_rp_next].op.rd,
          rd_val: old_csr_val,
          al_idx: csrq_next[csrq_rp_next].op.al_idx,
          actual_taken: 0,
          actual_taken_addr: 0,
          ldst_target_addr: 0,
          is_page_fault: 0,
          is_access_fault: 0
      };
      csrq_next[csrq_rp_next].state = DONE;
    end




    // 本実行.
    for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
      logic [XLEN-1:0] new_csr_val = 0;
      if(num_of_entries_in_csrq_next != 0 &&
      renamer_port.committed_instr[i].valid && renamer_port.committed_instr[i].al_idx == csrq_next[csrq_rp_next].op.al_idx)begin
        case (csrq_next[csrq_rp_next].op.opcode)
          CSRRW: begin
            new_csr_val = csrq_next[csrq_rp_next].op.rs1_val;
          end
          CSRRS: begin
            new_csr_val = csrq_next[csrq_rp_next].op.rs1_val | old_csr_val;
          end
          CSRRC: begin
            new_csr_val = ~csrq_next[csrq_rp_next].op.rs1_val & old_csr_val;
          end
          // rs1をuimmとして用いる.
          CSRRWI: begin
            new_csr_val = XLEN'(unsigned'(csrq_next[csrq_rp_next].op.imm[16:12]));
          end
          CSRRSI: begin
            new_csr_val = XLEN'(unsigned'(csrq_next[csrq_rp_next].op.imm[16:12])) | old_csr_val;
          end
          CSRRCI: begin
            new_csr_val = ~(XLEN'(unsigned'(csrq_next[csrq_rp_next].op.imm[16:12]))) & old_csr_val;
          end
          default: $display("[ERROR][%s,%-d]", `__FILE__, `__LINE__);
        endcase
        // 書き込みの実行.
        csr_port.write_req = '{
            valid: 1,
            csr_name: csr_name_e'(csrq_next[csrq_rp_next].op.imm[11:0]),
            data: new_csr_val
        };
        num_of_entries_in_csrq_next--;
        csrq_rp_next = csrq_rp_next + 1;
      end
    end

    // op_inをcsrqに反映
    if (op_in[0].valid) begin
      csrq_next[csrq_wp_next] = '{state: BEFORE_DONE, op: op_in[0]};
      num_of_entries_in_csrq_next++;
      csrq_wp_next = csrq_wp_next + 1;
    end



  end

  // circular回避のため隔離
  always_comb begin
    if (CSRQ_SIZE - num_of_entries_in_csrq < 2) begin
      stall_out = 1;
    end else begin
      stall_out = 0;
    end
  end



  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // csrq
      csrq <= '{default: 0};
      csrq_rp <= 0;
      csrq_wp <= 0;
      num_of_entries_in_csrq <= 0;

      // 出力
      op_out <= '{default: 0};
    end else if (flush_in) begin
      // csrq
      csrq <= '{default: 0};
      csrq_rp <= 0;
      csrq_wp <= 0;
      num_of_entries_in_csrq <= 0;

      // 出力
      op_out <= '{default: 0};
    end else begin
      // csrq
      csrq <= csrq_next;

      csrq_rp <= csrq_rp_next;
      csrq_wp <= csrq_wp_next;
      num_of_entries_in_csrq <= num_of_entries_in_csrq_next;

      // 出力
      op_out <= op_out_next;
    end
  end

endmodule
