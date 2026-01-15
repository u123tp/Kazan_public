`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

interface Renamer_LSU_if ();
  import HART_DEFS::*;
  import COMMON_PARAMS::*;

  //LSUでの設定に合わせる.
  localparam int unsigned NUM_OF_DTLB_RES = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;

  // ------------------------------------------------------
  // AL => LSU
  // ------------------------------------------------------
  // Active List に新しく入ってきた命令と卒業する命令
  new_ldst_to_al_t new_instr[NUM_OF_FETCH];
  committed_ldst_from_al_t committed_instr[NUM_OF_GRADUATE];

  // scやmmioがalの先頭に来たことを通知し,scなら今ロックしているアドレスを伝える.
  // typedef struct packed {
  //   logic valid;
  //   logic [AL_IDX_WIDTH-1:0] al_idx;
  //   logic [PADDR_WIDTH-1:0] paddr_dw_aligned;
  //   logic is_lr_w;  // dwかwか.
  // } sc_executable_t;
  // // alの先頭に来た時に,sc命令に実行可能と成否を伝える.
  // sc_executable_t sc_executable;

  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
    opcode_t opcode;
    logic has_lock;
    logic [PADDR_WIDTH-1:0] lock_paddr_dw_aligned;
    logic is_lr_w;  // ロックの大きさがwordかdouble wordか.
  } sc_mmio_executable_t;
  sc_mmio_executable_t sc_mmio_executable;

  // al
  logic [AL_IDX_WIDTH-1:0] al_rp;
  logic [AL_IDX_WIDTH-1:0] al_wp;

  // -------------------------------------------------------
  // LSU => AL
  // -------------------------------------------------------

  // rawハザード発見時のint issue queue,activelistに送るためのフィードバック.
  // 非amo命令はpaddrがわかった時に,amo命令はldの実行が終わったときに仮実行される.
  logic ld_speculative_feedback_valid;
  logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx;

  // lsuで仮実行されたst命令.
  // amo系でなければpaddrが得られたとき,amo系ならldで得た値との計算結果が反映されてかつpaddrが得られたとき.
  // logic st_tentative_executed_valid[NUM_OF_DTLB_RES];
  // logic [AL_IDX_WIDTH-1:0] st_tentative_executed_al_idx[NUM_OF_DTLB_RES];

  modport renamer(
      output new_instr, committed_instr, al_rp, al_wp, sc_mmio_executable,
      input ld_speculative_feedback_valid, ld_speculative_feedback_al_idx
  );
  modport lsu(
      input new_instr, committed_instr, al_rp, al_wp, sc_mmio_executable,
      output ld_speculative_feedback_valid, ld_speculative_feedback_al_idx
  );


endinterface

