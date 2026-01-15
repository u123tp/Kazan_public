`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module pcgen
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    output pc_t pc_out,

    // 分岐予測失敗などで,他のモジュールにflushを指示すると同時に,stage1では新しいpcを流し込む.
    input addr_with_valid_t flush_in,

    // stall_inなら新しいpcを発行しない.
    input logic stall_in
);

  // ---------------------------------------------------------
  // stall,flush 処理
  // ---------------------------------------------------------
  // stallとflushのどちらを優先するかは面倒な問題.
  // これはpc_genが全ての中で唯一flushでvalidな命令を出すことによる.
  // ほかのモジュールに関しては,flushされれば基本的に出力もinvalidになるので問題ない(=実質的にstallの要件を満たす)が,
  // pc_genだけは異なる.
  // そのため,stallかつflushの場合,flushで来た新しい値にしつつ,stallでinvalidにする.

  pc_t pc_out_next;
  pc_t pc_out_current;

  // alに入るまでの一意的なid.
  // icacheへは最大3つのリクエストを出すので,4づつ加算して,
  // 最初のリクエストのidはfirst_instr_id, 2つ目のリクエストのidはfirst_instr_id+1,...
  // とする.
  int unsigned first_instr_id;


  always_comb begin
    if (flush_in.valid && stall_in) begin
      // 出力する時にflush_in.addrになるように
      // なんかもうちょい良い方法無いのかこれ.
      pc_out_next = '{
          valid: 0,
          vaddr: flush_in.addr - VADDR_WIDTH'($unsigned(4 * NUM_OF_FETCH)),
          first_instr_id: first_instr_id
      };
    end else if (flush_in.valid) begin
      pc_out_next = '{valid: 1, vaddr: flush_in.addr, first_instr_id: first_instr_id};
    end else if (stall_in) begin
      // ちゃんとvalidのものだけicacheに入れているか.
      pc_out_next = '{valid: 0, vaddr: pc_out_current.vaddr, first_instr_id: first_instr_id};
    end else begin
      pc_out_next = '{
          valid: 1,
          vaddr: pc_out_current.vaddr + VADDR_WIDTH'($unsigned(4 * NUM_OF_FETCH)),
          first_instr_id: first_instr_id
      };
    end
  end

  int fp;
  initial begin
    fp = $fopen("./log/pcgenlog.txt", "w");
  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      pc_out <= '{valid: 1, vaddr: 39'h8000_0000, first_instr_id: 0};
      pc_out_current <= '{valid: 1, vaddr: 39'h8000_0000, first_instr_id: 0};

      first_instr_id <= 0;
    end else begin
      pc_out <= pc_out_next;
      pc_out_current <= pc_out_next;

      first_instr_id <= first_instr_id + 4;
`ifdef PCGENLOG_EN
      $fdisplay(fp, "valid:%b,  vaddr:%010h, firstinstr_id:%016h", pc_out.valid, pc_out.vaddr,
                pc_out.first_instr_id);
`endif
    end
  end
endmodule
