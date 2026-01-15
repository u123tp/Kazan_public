// TLBとのやり取りやfenceによる仲裁,
// LDQ,STQが循環バッファとして実装できるのは,登録はrename時にin-orderで行われ,
// 削除もコミットでインオーダーに行われるからである.
//
// TODO: access_faultのチェック.
//
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "COMMON_FUNCS.svh"
`include "CSR_PROPS.svh"
`include "CACHE_PROPS.svh"
`include "MemoryLayout.svh"


module LSU
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import COMMON_FUNCS::*;
  import CSR_PROPS::*;
  import CACHE_PROPS::*;
  import MemoryLayout::*;
#(

) (
    input logic clock,
    input logic reset,

    // stにamoを統合しているのは,amoの命令の数があまり多く無いと思い,毎回2ポート用意するのを避けたかったから.
    input vuop_back_t op_ld_in[NUM_OF_LD_ISSUE],
    input vuop_back_t op_st_amo_in[NUM_OF_ST_AMO_ISSUE],

    output vuop_result_t op_ld_out[NUM_OF_LD_EXE],
    output vuop_result_t op_st_out[NUM_OF_ST_EXE],


    // ld,stにしろmmioはalの先頭でないと実行されないので,2つ以上が同時に実行されることはない.
    output vuop_result_t op_mmio_out,


    // => Renamer
    Renamer_LSU_if.lsu renamer_port,

    // => Int Issue Queue
    // load waiting tableの更新.
    output logic ld_speculative_feedback_valid,
    output logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx,

    // DTLB
    dtlb_if.client tlb_port,

    // DCache
    output cache_req_t req_to_dcache[NUM_OF_LD_EXE+NUM_OF_ST_EXE],
    input cache_res_t res_from_dcache[NUM_OF_LD_EXE],
    input logic dcache_noroom,

    // clint
    output device_req_t req_to_clint,
    input  device_res_t res_from_clint,

    // plic及びplicにつながっている外部device(uartなど)
    output device_req_t req_to_plic,
    input  device_res_t res_from_plic,


    // CSR =>
    csr_reg_u satp,

    // M-modeならアドレス変換を行わない.
    privilege_level_e priv_rval,

    // ↓コミット以上に入ってくることはないんだから不要では？
    // renamerへのstallは必要
    // とりあえずldqとstqのサイズを64にしたのであふれることは無い.
    // リソース的には後で変えた方がいい.
    // output logic stall_out,

    input logic flush_in,

    input int unsigned generation
);


  localparam int unsigned BYTE_IN_DW_LSB = 0;
  localparam int unsigned BYTE_IN_DW_MSB = $clog2(DW_SIZE) - 1;

  localparam int unsigned SSB_SIZE = 16;

  localparam int unsigned ARL_SIZE = 8;
  localparam int unsigned LSRL_SIZE = 8;

  localparam int unsigned LDQ_IDX_WIDTH = $clog2(LDQ_SIZE);
  localparam int unsigned STQ_IDX_WIDTH = $clog2(STQ_SIZE);
  localparam int unsigned FENCEQ_IDX_WIDTH = $clog2(FENCEQ_SIZE);

  localparam int unsigned SSB_IDX_WIDTH = $clog2(SSB_SIZE);
  localparam int unsigned ARL_IDX_WIDTH = $clog2(ARL_SIZE);
  localparam int unsigned LSRL_IDX_WIDTH = $clog2(LSRL_SIZE);

  // 1サイクルにstq,ldqから取り出されて,バイパスされるかcacheに入力される命令の数.
  // localparam int unsigned NUM_OF_LD_EXE = 2;
  // localparam int unsigned NUM_OF_ST_EXE = 1;

  // 
  localparam int unsigned NUM_OF_LD_CACHE_REQ = NUM_OF_LD_EXE;
  localparam int unsigned NUM_OF_ST_CACHE_REQ = NUM_OF_ST_EXE;

  localparam int unsigned NUM_OF_CACHE_REQ = NUM_OF_LD_CACHE_REQ + NUM_OF_ST_CACHE_REQ;

  localparam int unsigned NUM_OF_CACHE_RES = NUM_OF_LD_EXE;

  // とりあえず,DTLBの入力も出力も,issueの数に合わせる.
  localparam int unsigned NUM_OF_DTLB_REQ = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;
  localparam int unsigned NUM_OF_DTLB_RES = NUM_OF_LD_ISSUE + NUM_OF_ST_AMO_ISSUE;

  // 各キューのramPortの数
  // キャッシュへのread_reqはffに保存してあるアドレスだけで実行可能だが,
  // キャッシュへのwrite_reqはデータを伴うためramから読み出す必要がある.
  // バイパスが成功した場合,cache_resと同様にldqから命令のデータを読み出してresultとしてalに送るので,
  // cache_resと競合するので,cache_resを抑制する必要がある.
  // amoのバイパスが成功した場合は,次のサイクル立ち上がりのcacheからのresを抑制し,stqに書き込むのでSTQ_WRITE_PORTには
  // max(NUM_OF_LD_CACHE_REQ, NUM_OFCACHE_RES)個をNUM_OF_ST_AMO_ISSUE個の他に持つ必要ある.

  // キャッシュから読み込んだデータが帰ってきたときに,opの他の内容を読み込んでalに返す.
  localparam int unsigned NUM_OF_LDQ_READ_PORT = NUM_OF_LD_EXE;
  // op_in_st_amoの数(amoがldにも登録されるため) + op_in_ldの数.
  localparam int unsigned NUM_OF_LDQ_WRITE_PORT = NUM_OF_ST_AMO_ISSUE + NUM_OF_LD_ISSUE;

  // ldへのバイパス用 + キャッシュへの書き込みデータの読み込み(ssb的な)
  localparam int unsigned NUM_OF_STQ_READ_PORT = NUM_OF_LD_EXE + NUM_OF_ST_CACHE_REQ;
  // op_inの数 + キャッシュから読み込んだamo命令のロード結果を（演算した後に）保存する.
  localparam int unsigned NUM_OF_STQ_WRITE_PORT = NUM_OF_ST_AMO_ISSUE + NUM_OF_CACHE_RES;


  // -------------------------------------------------------
  //出力
  // --------------------------------------------------------

  vuop_result_t op_ld_out_next[NUM_OF_LD_EXE];
  vuop_result_t op_st_out_next[NUM_OF_ST_EXE];

  // 各エントリの状態
  // store命令はコミット後にキャッシュに命令を送るので状態がldと異なる.
  typedef enum logic [3:0] {
    LD_BEFORE_ARRIVE = 4'b0000,
    LD_BEFORE_TLB_REQUEST = 4'b0001,
    LD_DURING_TLB_REQUEST = 4'b0010,
    LD_BEFORE_CACHE_REQUEST = 4'b0011,
    LD_DURING_REQUEST = 4'b0100,
    LD_DONE =4'b0101, // キャッシュから読み出しが終わって,alやrfにfeedbackしたがコミットがまだ
    // LD_DONEの段階ではRAWハザードが判明すればロールバックが必要になりうる.

    // page_faultの場合.
    LD_PAGE_FAULT   = 4'b0110,
    LD_ACCESS_FAULT = 4'b0111,

    // MMIO
    LD_BEFORE_MMIO_REQUEST = 4'b1000

  } ld_state_t;

  typedef enum logic [3:0] {
    ST_BEFORE_ARRIVE = 4'b0000,
    ST_BEFORE_TLB_REQUEST = 4'b0001,
    ST_DURING_TLB_REQUEST = 4'b0010,
    // amo命令の場合,ld命令によってrs2を更新してからしか実行できないため,このステージが間に入る.
    // tlbからの返信でpaddrを得るより前にamoのload命令でrs2を得ることは無い.それは,st命令のpaddrは対応するld命令
    // のtarget_paddrと同時に更新されて、そのあとにload命令が発行されて、その結果からstqを更新する.
    ST_AMO_WAITING_RS2 = 4'b0011,
    // scは直前の命令がコミットして,lrsc_lockの状態が明らかになるまでST_CONDITIONAL_WAITINGににして仮実行させないことにした.
    ST_CONDITIONAL_WAITING = 4'b0100,
    ST_BEFORE_EXE = 4'b0101,  // paddrを得てから,stを実行するまで.
    ST_DONE = 4'b0110,  // コミットがまだ.

    ST_PAGE_FAULT   = 4'b0111,
    ST_ACCESS_FAULT = 4'b1000,

    // MMIO
    ST_BEFORE_MMIO_REQUEST = 4'b1001,
    // st命令の場合,本来はdoneの後にcacheに送られるが,
    // mmioでは状態がST_BEFORE_MMIO_REQUEST => ST_MMIO_DONE の時に送られるのでST_DONEと区別する.
    ST_MMIO_DONE = 4'b1010
  } st_state_t;

  // キャッシュへのリクエスト出力.
  cache_req_t req_to_dcache_next[NUM_OF_LD_EXE+NUM_OF_ST_EXE];

  // --------------------------------------------------------
  // load queue
  // --------------------------------------------------------
  // 入った後にデータをldqに保存する.
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] op_addr;  // FOR DEBUG
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    ld_state_t state;
    // TLBに入れる前はtlbに入れるためのvaddr,TLBから帰ってきた後はpaddrが入ってる.
    // 長さはvaddrのほうがpaadrより短いのでPADDR_WIDTH
    logic [PADDR_WIDTH-1:0] addr;
    opcode_t opcode;
    // この命令がld命令なら,対応するst命令のstq_idxを保存しておいて,cache_resが戻ってくるときのstqエントリのアプデに用いる.
    logic [STQ_IDX_WIDTH-1:0] amo_corresponding_stq_idx;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    // ld_exeしたときに,先行するst命令のうち,ST_DONEのものを保存する.
    // ココらへんは,addrとの共用体で実装しても良いかもね.
    logic [XLEN-1:0] bypass_data;
    logic [XLEN/8-1:0] bypass_data_mask;
  } ldq_t;

  ldq_t [LDQ_SIZE-1:0] ldq;
  ldq_t [LDQ_SIZE-1:0] ldq_next;

  logic [LDQ_IDX_WIDTH-1:0] ldq_rp;
  logic [LDQ_IDX_WIDTH-1:0] ldq_wp;
  logic [LDQ_IDX_WIDTH-1:0] ldq_rp_next;
  logic [LDQ_IDX_WIDTH-1:0] ldq_wp_next;
  logic [LDQ_IDX_WIDTH:0] num_of_entries_in_ldq;
  logic [LDQ_IDX_WIDTH:0] num_of_entries_in_ldq_next;

  // ------------------------------------------------
  // store queue
  // ------------------------------------------------
  typedef struct packed {
    logic [VADDR_WIDTH-1:0] op_addr;  // FOR DEBUG
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    st_state_t state;
    logic [PADDR_WIDTH-1:0] addr;
    opcode_t opcode;
    // この命令がamo命令の場合,対応するld命令が実行済か.
    logic amo_ready;
    // sc命令のためにrdは必要.
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] rs2_val;
    logic [XLEN/8-1:0] rs2_val_mask;
    // コミット時に実行しないように
    logic sc_success;
  } stq_t;

  stq_t stq[STQ_SIZE];
  stq_t stq_next[STQ_SIZE];

  logic [STQ_IDX_WIDTH-1:0] stq_rp;
  logic [STQ_IDX_WIDTH-1:0] stq_wp;
  logic [STQ_IDX_WIDTH-1:0] stq_rp_next;
  logic [STQ_IDX_WIDTH-1:0] stq_wp_next;
  logic [STQ_IDX_WIDTH:0] num_of_entries_in_stq;
  logic [STQ_IDX_WIDTH:0] num_of_entries_in_stq_next;


  // -----------------------------------------------
  // fence queue, fence table
  // -----------------------------------------------
  typedef struct packed {
    logic valid;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    // このfenceよりal_idxが後ろにあるld命令をブロックするか.
    logic block_suc_ld;
    logic block_suc_st;
  } fenceq_t;

  fenceq_t fenceq[FENCEQ_SIZE];
  fenceq_t fenceq_next[FENCEQ_SIZE];
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_rp;
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_wp;
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_rp_next;
  logic [FENCEQ_IDX_WIDTH-1:0] fenceq_wp_next;
  logic [FENCEQ_IDX_WIDTH:0] num_of_entries_in_fenceq;
  logic [FENCEQ_IDX_WIDTH:0] num_of_entries_in_fenceq_next;

  // fence table
  // fenceqを,al_idxから参照できる形に変形したもの.
  // あるal_idxを持つ命令がldならfenceによってブロックされるとき,ft[al_idx].ld_blocked == 1.
  typedef struct packed {
    logic ld_blocked;
    logic st_blocked;
  } ft_t;
  ft_t ft[ACTIVELIST_SIZE];



  // ------------------------------------------------------------
  // ld_speculative_feedback
  // ------------------------------------------------------------
  // lsu <=> renamerでのループを解消するために, lsu => renamerの内容をalwaysffで1サイクル遅らせる.
  logic ld_speculative_feedback_valid_next;
  logic [AL_IDX_WIDTH-1:0] ld_speculative_feedback_al_idx_next;
  // logic st_tentative_executed_valid_next[NUM_OF_DTLB_RES];
  // logic [AL_IDX_WIDTH-1:0] st_tentative_executed_al_idx_next[NUM_OF_DTLB_RES];



  //　現在のalにおいて,al_idx_leftがal_idx_rightより古いものか
  function automatic logic is_left_older(logic [AL_IDX_WIDTH-1:0] al_idx_left,
                                         logic [AL_IDX_WIDTH-1:0] al_idx_right);
    logic [AL_IDX_WIDTH-1:0] al_rp = renamer_port.al_rp;
    logic [AL_IDX_WIDTH-1:0] al_wp = renamer_port.al_wp;
    return (al_rp<=al_idx_left && al_idx_left<al_idx_right && al_idx_right<=al_wp) ||
           (al_wp <= al_rp && al_rp <= al_idx_left && al_idx_left < al_idx_right) ||
           (al_idx_right <= al_wp && al_wp<=al_rp && al_rp<= al_idx_left) ||
           (al_idx_left < al_idx_right && al_idx_right <= al_wp && al_wp<=al_rp);
  endfunction


  // amo命令double wordの計算部分を実行する.
  function automatic logic [XLEN-1:0] amo_calc_dw(opcode_t opcode, logic [XLEN-1:0] rs1_mem_val,
                                                  logic [XLEN-1:0] rs2_val);
    // rs1_mem_valはld命令でアドレスがrs1にある内容を読み出したもの,rs2valは普通にレジスタrs2に入っていたデータ.
    logic [XLEN-1:0] rd;
    case (opcode)
      AMOSWAP_D: rd = rs2_val;
      AMOADD_D:  rd = rs1_mem_val + rs2_val;
      AMOXOR_D:  rd = rs1_mem_val ^ rs2_val;
      AMOAND_D:  rd = rs1_mem_val & rs2_val;
      AMOOR_D:   rd = rs1_mem_val | rs2_val;
      AMOMIN_D:  rd = signed'(rs1_mem_val) < signed'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMAX_D:  rd = signed'(rs1_mem_val) > signed'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMINU_D: rd = unsigned'(rs1_mem_val) < unsigned'(rs2_val) ? rs1_mem_val : rs2_val;
      AMOMAXU_D: rd = unsigned'(rs1_mem_val) > unsigned'(rs2_val) ? rs1_mem_val : rs2_val;
      default:   $display("[ERROR] [%s,%d]", `__FILE__, `__LINE__);
    endcase
    return rd;
  endfunction

  // amo命令wordの計算
  function automatic logic [31:0] amo_calc_w(opcode_t opcode, logic [31:0] rs1_mem_val,
                                             logic [31:0] rs2_val);
    logic [31:0] result;
    case (opcode)
      AMOSWAP_W: result = rs2_val;
      AMOADD_W: result = rs1_mem_val + rs2_val;
      AMOXOR_W: result = rs1_mem_val ^ rs2_val;
      AMOAND_W: result = rs1_mem_val & rs2_val;
      AMOOR_W: result = rs1_mem_val | rs2_val;
      AMOMIN_W: result = signed'(32'(rs1_mem_val)) < signed'(32'(rs2_val)) ? rs1_mem_val : rs2_val;
      AMOMAX_W: result = signed'(32'(rs1_mem_val)) > signed'(32'(rs2_val)) ? rs1_mem_val : rs2_val;
      AMOMINU_W:
      result = unsigned'(32'(rs1_mem_val)) < unsigned'(32'(rs2_val)) ? rs1_mem_val : rs2_val;
      AMOMAXU_W:
      result = unsigned'(32'(rs1_mem_val)) > unsigned'(32'(rs2_val)) ? rs1_mem_val : rs2_val;
      default: $display("[ERROR] [%s,%d]", `__FILE__, `__LINE__);
    endcase
    return result;
  endfunction


  function automatic logic [PADDR_WIDTH-1:0] to_dw_aligned_paddr(
      input logic [PADDR_WIDTH-1:0] paddr_origin);
    return {paddr_origin[PADDR_WIDTH-1:$clog2(DW_SIZE)], {$clog2(DW_SIZE) {1'b0}}};
  endfunction



  always_comb begin
    // commitされたst命令のstq_idx
    logic committed_stq_valid[NUM_OF_ST_EXE] = '{default: 0};
    opcode_t committed_stq_opcode[NUM_OF_ST_EXE] = '{default: NOP};
    logic [XLEN-1:0] committed_stq_data[NUM_OF_ST_EXE] = '{default: 0};
    logic [PADDR_WIDTH-1:0] committed_stq_paddr_dw_aligned[NUM_OF_ST_EXE] = '{default: 0};

    // => renamer
    // st命令をST_DONEにするときに,rawハザードが無いかチェックし,あったらrenamerにフィードバックする.
    ld_speculative_feedback_valid_next = 0;
    ld_speculative_feedback_al_idx_next    =0;
    // ST_DONEになったら仮実行済とし,renamerのdoneを1にする.
    // st_tentative_executed_valid_next = '{default: 0};
    // st_tentative_executed_al_idx_next = '{default: 0};

    // ldq
    ldq_next = ldq;
    ldq_rp_next = ldq_rp;
    ldq_wp_next = ldq_wp;
    num_of_entries_in_ldq_next = num_of_entries_in_ldq;

    // stq
    stq_next = stq;
    stq_rp_next = stq_rp;
    stq_wp_next = stq_wp;
    num_of_entries_in_stq_next = num_of_entries_in_stq;

    // fenceq 
    fenceq_next = fenceq;
    fenceq_rp_next = fenceq_rp;
    fenceq_wp_next = fenceq_wp;
    num_of_entries_in_fenceq_next = num_of_entries_in_fenceq;



    for (int unsigned i = 0; i < NUM_OF_CACHE_REQ; i++) begin
      req_to_dcache_next[i] = '{
          valid: 0,
          default: 0,
          req_policy: REQ_POLICY_NONE,
          cb_req_type: CB_REQ_TYPE_NONE
      };
    end
    for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
      op_ld_out_next[i] = '{default: 0, opcode: NOP, valid: 0};
    end
    for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
      op_st_out_next[i] = '{default: 0, opcode: NOP, valid: 0};
    end

    op_mmio_out = '{default: 0, opcode: NOP};



    // --------------------------------------------------------
    // alに入ってきたinstrをldq,stq,fenceqに反映させる
    // --------------------------------------------------------
    // new_instr => ldq_next, stq_next, fenceq_next
    // activelistに新しく入ってきた命令をldqとstqに登録する.
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      if (renamer_port.new_instr[i].valid) begin
        if (is_ld_opcode(renamer_port.new_instr[i].opcode)) begin
          // ld命令.
          ldq_next[ldq_wp_next] = '{
              op_addr: renamer_port.new_instr[i].op_addr,
              al_idx: renamer_port.new_instr[i].al_idx,
              state: LD_BEFORE_ARRIVE,
              addr: 0,
              opcode: renamer_port.new_instr[i].opcode,
              amo_corresponding_stq_idx: 0,
              rd: 0,
              bypass_data: 0,
              bypass_data_mask: 0
          };
          ldq_wp_next = LDQ_IDX_WIDTH'(32'(ldq_wp_next) + 1);
          num_of_entries_in_ldq_next++;
        end else if (is_st_opcode(renamer_port.new_instr[i].opcode)) begin
          // st命令.
          stq_next[stq_wp_next] = '{
              op_addr: renamer_port.new_instr[i].op_addr,
              al_idx: renamer_port.new_instr[i].al_idx,
              state: ST_BEFORE_ARRIVE,
              addr: 0,
              opcode: renamer_port.new_instr[i].opcode,
              amo_ready: 0,
              rd: 0,
              rs2_val: 0,
              rs2_val_mask: 0,
              sc_success: 0
          };
          stq_wp_next = STQ_IDX_WIDTH'(32'(stq_wp_next) + 1);
          num_of_entries_in_stq_next++;
        end else if (is_amo_opcode(renamer_port.new_instr[i].opcode)) begin
          // amo命令.
          ldq_next[ldq_wp_next] = '{
              op_addr: renamer_port.new_instr[i].op_addr,
              al_idx: renamer_port.new_instr[i].al_idx,
              state: LD_BEFORE_ARRIVE,
              addr: 0,
              opcode: renamer_port.new_instr[i].opcode,
              amo_corresponding_stq_idx: stq_wp_next,
              rd: 0,
              bypass_data: 0,
              bypass_data_mask: 0
          };
          stq_next[stq_wp_next] = '{
              op_addr: renamer_port.new_instr[i].op_addr,
              al_idx: renamer_port.new_instr[i].al_idx,
              state: ST_BEFORE_ARRIVE,
              addr: 0,
              opcode: renamer_port.new_instr[i].opcode,
              amo_ready: 0,
              rd: 0,
              rs2_val: 0,
              rs2_val_mask: 0,
              sc_success: 0
          };
          ldq_wp_next = LDQ_IDX_WIDTH'(32'(ldq_wp_next) + 1);
          num_of_entries_in_ldq_next++;
          stq_wp_next = STQ_IDX_WIDTH'(32'(stq_wp_next) + 1);
          num_of_entries_in_stq_next++;
        end else if (renamer_port.new_instr[i].opcode == FENCE) begin
          // fence命令.
          fenceq_next[fenceq_wp_next] = '{
              valid: 1,
              al_idx: renamer_port.new_instr[i].al_idx,
              block_suc_ld: renamer_port.new_instr[i].sr || renamer_port.new_instr[i].si,
              block_suc_st: renamer_port.new_instr[i].sw || renamer_port.new_instr[i].so
          };
          fenceq_wp_next = FENCEQ_IDX_WIDTH'(32'(fenceq_wp_next) + 1);
          num_of_entries_in_fenceq_next++;
        end
      end
    end


    // -------------------------------------------------------
    // fence tableの製作
    // -------------------------------------------------------
    // fenceq_next => ft
    // fenceqから,al_idxを持つ命令がブロックされているかを引ける索引ftを製作.
    begin
      logic ld_blocked_by_fence = 0;
      logic st_blocked_by_fence = 0;
      int unsigned fence_counter = 0;
      for (int unsigned i = 0; i < ACTIVELIST_SIZE; i++) begin
        logic [AL_IDX_WIDTH-1:0] al_idx = renamer_port.al_rp + AL_IDX_WIDTH'(i);
        logic [FENCEQ_IDX_WIDTH-1:0] fenceq_idx = FENCEQ_IDX_WIDTH'(32'(fenceq_rp_next) + fence_counter);
        if (fenceq_next[fenceq_idx].valid && fenceq_next[fenceq_idx].al_idx == al_idx) begin
          if (fenceq_next[fenceq_idx].block_suc_ld) begin
            ld_blocked_by_fence = 1;
          end
          if (fenceq_next[fenceq_idx].block_suc_st) begin
            st_blocked_by_fence = 1;
          end
          fence_counter++;
        end
        ft[al_idx] = '{ld_blocked: ld_blocked_by_fence, st_blocked: st_blocked_by_fence};
      end
    end

    // ---------------------------------------------------------------
    // op_in_ld の内容をldqに反映させる.
    // ----------------------------------------------------------------
    // op_in_ld
    // => ldqff_next, ldqram_w_en, ldqram_w_ram_idx, ldqram_w_data
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_LD_ISSUE; i++) begin
        if (op_ld_in[i].valid) begin
          for (int unsigned j = 0; j < num_of_entries_in_ldq_next; j++) begin
            ldq_idx = LDQ_IDX_WIDTH'(32'(ldq_rp_next) + j);
            if (ldq_next[ldq_idx].al_idx == op_ld_in[i].al_idx) begin
              // ldqの更新.
              if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin
                // paddrが判明している場合.
                if (get_device_name(
                        PADDR_WIDTH'(op_ld_in[i].rs1_val + op_ld_in[i].imm)
                    ) == DN_DRAM) begin
                  // メインメモリのpaddr.
                  ldq_next[ldq_idx].state = LD_BEFORE_CACHE_REQUEST;
                end else if (get_device_name(
                        PADDR_WIDTH'(op_ld_in[i].rs1_val + op_ld_in[i].imm)
                    ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
                  // deviceのpaddr
                  ldq_next[ldq_idx].state = LD_BEFORE_MMIO_REQUEST;
                end else begin
                  // メインメモリ,deviceで無い場合,access_fault
                  ldq_next[ldq_idx].state = LD_ACCESS_FAULT;
                end
              end else begin
                ldq_next[ldq_idx].state = LD_BEFORE_TLB_REQUEST;
              end

              // tlbで変換する対象のアドレス.
              // 物理アドレスが来ても仮想アドレスが来ても,とりあえず.addrに入れる.
              ldq_next[ldq_idx].addr = PADDR_WIDTH'(op_ld_in[i].rs1_val + op_ld_in[i].imm);
              ldq_next[ldq_idx].opcode = op_ld_in[i].opcode;
              ldq_next[ldq_idx].rd = op_ld_in[i].rd;

            end
          end
        end
      end
    end

    // ----------------------------------------------------------------
    // op_st_amo_inをldq,stqに反映
    // ---------------------------------------------------------------
    // op_st_amo_in
    // => stqff_next, stqram_w_en, stqram_w_ram_idx, stqram_w_data
    // st命令はstqに,amo命令はstqとldqの両方に.
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx = 0;
      // ld_already_executed = 0;
      // raw_order = 0;
      // addr_dw_aligned_match = 0;

      for (int unsigned i = 0; i < NUM_OF_ST_AMO_ISSUE; i++) begin
        logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
        if (op_st_amo_in[i].valid) begin

          // stq_nextに追加.
          for (int unsigned j = 0; j < num_of_entries_in_stq_next; j++) begin
            stq_idx = STQ_IDX_WIDTH'(32'(stq_rp_next) + j);
            if (stq_next[stq_idx].al_idx == op_st_amo_in[i].al_idx) begin

              // stqの更新.
              if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin

                // paddrが来る場合,
                if (get_device_name(
                        PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm)
                    ) == DN_DRAM) begin
                  // dramの範囲の場合.
                  if (is_sc_opcode(op_st_amo_in[i].opcode)) begin
                    stq_next[stq_idx].state = ST_CONDITIONAL_WAITING;
                  end else if (is_amo_opcode(op_st_amo_in[i].opcode)) begin
                    stq_next[stq_idx].state = ST_AMO_WAITING_RS2;
                  end else begin
                    stq_next[stq_idx].state = ST_BEFORE_EXE;
                  end
                end else if (get_device_name(
                        PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm)
                    ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
                  // device mmio
                  stq_next[stq_idx].state = ST_BEFORE_MMIO_REQUEST;
                end else begin
                  // 不正なpaddr
                  stq_next[stq_idx].state = ST_ACCESS_FAULT;
                end
              end else begin
                //vaddrが来る.
                stq_next[stq_idx].state = ST_BEFORE_TLB_REQUEST;
              end

              stq_next[stq_idx].addr = PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);
              byte_in_dw_idx = stq_next[stq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB];
              stq_next[stq_idx].rd = op_st_amo_in[i].rd;

              // stはdw単位で管理する.rs2_valの値がある位置とマスクの位置を合わせて,マスクして楽に値を取り出せるようにする
              // (op_inのrs2_valは右に詰められているため.)
              stq_next[stq_idx].rs2_val = '0;
              stq_next[stq_idx].rs2_val_mask = '0;
              case (op_st_amo_in[i].opcode)
                SB: begin
                  stq_next[stq_idx].rs2_val[byte_in_dw_idx*8+:8] = op_st_amo_in[i].rs2_val[7:0];
                  stq_next[stq_idx].rs2_val_mask[byte_in_dw_idx+:1] = 1'b1;
                end
                SH: begin
                  stq_next[stq_idx].rs2_val[byte_in_dw_idx*8+:16]   = op_st_amo_in[i].rs2_val[15:0];
                  stq_next[stq_idx].rs2_val_mask[byte_in_dw_idx+:2] = 2'b11;
                end
                SW,SC_W, AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W, AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W: begin
                  stq_next[stq_idx].rs2_val[byte_in_dw_idx*8+:32]   = op_st_amo_in[i].rs2_val[31:0];
                  stq_next[stq_idx].rs2_val_mask[byte_in_dw_idx+:4] = 4'b1111;
                end
                SD,SC_D, AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D, AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D: begin
                  stq_next[stq_idx].rs2_val = op_st_amo_in[i].rs2_val;
                  stq_next[stq_idx].rs2_val_mask = 8'b1111_1111;
                end
                default: ;
              endcase


            end
          end

          // ldq_nextに追加.
          if (is_amo_opcode(op_st_amo_in[i].opcode)) begin
            for (int unsigned k = 0; k < num_of_entries_in_ldq_next; k++) begin
              ldq_idx = LDQ_IDX_WIDTH'(32'(ldq_rp_next) + k);
              if (ldq_next[ldq_idx].al_idx == op_st_amo_in[i].al_idx) begin
                // ldqの更新.
                if (priv_rval == M_MODE || satp.as_satp.MODE == 0 || MMU_DISABLED) begin
                  if (get_device_name(
                          PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm)
                      ) == DN_DRAM) begin
                    ldq_next[ldq_idx].state = LD_BEFORE_CACHE_REQUEST;
                  end else if (get_device_name(
                          PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm)
                      ) inside {DN_BOOTLOADER, DN_CLINT, DN_PLIC, DN_UART}) begin
                    ldq_next[ldq_idx].state = LD_BEFORE_MMIO_REQUEST;
                  end else begin
                    ldq_next[ldq_idx].state = LD_ACCESS_FAULT;
                  end
                end else begin
                  // paddrが不明な場合.
                  ldq_next[ldq_idx].state = LD_BEFORE_TLB_REQUEST;
                end


                // tlbで変換する対象のアドレス.
                ldq_next[ldq_idx].addr = PADDR_WIDTH'(op_st_amo_in[i].rs1_val + op_st_amo_in[i].imm);
                ldq_next[ldq_idx].rd = op_st_amo_in[i].rd;
              end
            end
          end


        end
      end
    end

    // --------------------------------------------------------------
    // renamer_port からのsc,mmioの実行.
    // --------------------------------------------------------------
    // sc の実行.
    begin
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
      if (renamer_port.sc_mmio_executable.valid && renamer_port.sc_mmio_executable.opcode inside {SC_D, SC_W}) begin
        for (int unsigned i = 0; i < num_of_entries_in_stq_next; i++) begin
          stq_idx = STQ_IDX_WIDTH'(stq_rp_next + STQ_IDX_WIDTH'(i));
          // 該当するstqのエントリの探索.
          if (stq_next[stq_idx].al_idx == renamer_port.sc_mmio_executable.al_idx && 
              stq_next[stq_idx].state == ST_CONDITIONAL_WAITING) begin
            // scが成功か失敗かを判別.
            if (!renamer_port.sc_mmio_executable.has_lock || to_dw_aligned_paddr(
                    stq_next[stq_idx].addr
                ) == renamer_port.sc_mmio_executable.lock_paddr_dw_aligned &&
                    !(stq_next[stq_idx].opcode == SC_D &&
                      renamer_port.sc_mmio_executable.is_lr_w)) begin
              // sc成功時
              stq_next[stq_idx].sc_success = 1;
              stq_next[stq_idx].state = ST_BEFORE_EXE;
            end else begin
              // sc失敗時
              stq_next[stq_idx].sc_success = 0;
              stq_next[stq_idx].state = ST_BEFORE_EXE;
            end
          end
        end
      end
    end

    // mmioへのst命令の実行.
    // amo命令でmmioを弄ることは想定しない.
    req_to_clint = '{default: 0};
    req_to_plic  = '{default: 0};

    begin
      // stqの探索.
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
      if (renamer_port.sc_mmio_executable.valid && is_st_opcode(
              renamer_port.sc_mmio_executable.opcode
          )) begin
        for (int unsigned i = 0; i < num_of_entries_in_stq_next; i++) begin
          stq_idx = STQ_IDX_WIDTH'(stq_rp_next + STQ_IDX_WIDTH'(i));
          // 対応する実行前のmmioリクエストの特定（存在する場合のみ）
          if (stq_next[stq_idx].al_idx == renamer_port.sc_mmio_executable.al_idx && 
              stq_next[stq_idx].state == ST_BEFORE_MMIO_REQUEST) begin

            // 今は,dw_alignedされたアドレスに対してrs2_valを定めている,つまり,byte単位のstoreなら,
            // dw_alignedされたアドレスに対応する8byte分のデータの中の,1byte分だけが有効になっている.
            // これはcacheでの処理を楽にするため.しかし,mmioではその部分だけ取り出してやる必要がある.

            // どのdeviceかによって送り先が変わる.
            // xv6はclintとデータのやり取りをしないので重要でない,plicは32bit単位で,uartは8bit単位でデータをやり取りする.
            case (get_device_name(
                stq_next[stq_idx].addr
            ))
              DN_CLINT: begin
                req_to_clint = '{
                    valid: 1,
                    id: 0,  // stはid不要.
                    paddr: stq_next[stq_idx].addr,
                    is_write: 1,
                    data: stq_next[stq_idx].rs2_val
                };
              end
              DN_PLIC: begin
                req_to_plic = '{
                    valid: 1,
                    id: 0,  // stはid不要.
                    paddr: stq_next[stq_idx].addr,
                    is_write: 1,
                    data: {
                      32'b0,
                      stq_next[
                      stq_idx
                      ].rs2_val[
                      stq_next[stq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8
                      +:
                      32
                      ]
                    }

                };
              end
              DN_UART: begin
                req_to_plic = '{
                    valid: 1,
                    id: 0,  // stはid不要.
                    paddr: stq_next[stq_idx].addr,
                    is_write: 1,
                    data: {
                      56'b0,
                      stq_next[
                      stq_idx
                      ].rs2_val[
                      stq_next[stq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8
                      +:
                      8
                      ]
                    }

                };
              end
              default: ;
            endcase

            // renamerへ終了を伝えるための出力
            op_mmio_out = '{
                valid: 1,
                opcode: stq_next[stq_idx].opcode,
                op_addr: stq_next[stq_idx].op_addr,
                rd_exist: 0,
                rd: 0,
                rd_val: 0,
                al_idx: stq_next[stq_idx].al_idx,
                actual_taken: 0,
                actual_taken_addr: 0,
                ldst_target_addr: stq_next[stq_idx].addr,
                is_page_fault: 0,
                is_access_fault: 0
            };

            stq_next[stq_idx].state = ST_MMIO_DONE;
          end
        end
      end
    end

    // mmioへのld命令の実行.
    // mmioは絶対にロールバックすることができない。st命令はコミット後にmmioに出されるからいいが、
    // ldはコミット前にmmioに出される.alの先頭なら確実にコミットするからいいじゃないかと思うかもしれないが、
    // 割り込みという問題がある。mmioにリクエストを出したのに割り込みが入ってmmioへのリクエストをロールバックしたいです,
    // なんてことになったら駄目だ.
    // 割り込みを行える条件に「ALの先頭がld/st命令で無い」を追加する.割り込みを行っては行けないのは,前のサイクルまでに
    // mmioへのld/st命令を実行可能信号を出している場合で,この場合、このサイクルでの先頭は必ずld/st命令になる.
    // だからalの先頭がld/st命令なら割り込みができないようにする.
    // 以上の仕組みをrenamerで実装したので,ここでは普通に実行して良い.
    begin
      // ldqの探索.
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      if (renamer_port.sc_mmio_executable.valid && is_ld_opcode(
              renamer_port.sc_mmio_executable.opcode
          )) begin
        for (int unsigned i = 0; i < num_of_entries_in_ldq_next; i++) begin
          ldq_idx = LDQ_IDX_WIDTH'(ldq_rp_next + LDQ_IDX_WIDTH'(i));
          // 対応する実行前のmmioリクエストの特定（存在する場合のみ）
          if (ldq_next[ldq_idx].al_idx == renamer_port.sc_mmio_executable.al_idx && 
              ldq_next[ldq_idx].state == LD_BEFORE_MMIO_REQUEST) begin
            // どのdeviceかによって送り先が変わる.
            case (get_device_name(
                ldq_next[ldq_idx].addr
            ))
              DN_CLINT: begin
                req_to_clint = '{
                    valid: 1,
                    id: 32'(unsigned'(ldq_idx)),  // stはid不要.
                    paddr: ldq_next[ldq_idx].addr,
                    is_write: 0,
                    data: 0
                };
              end
              DN_PLIC: begin
                req_to_plic = '{
                    valid: 1,
                    id: 32'(unsigned'(ldq_idx)),  // stはid不要.
                    paddr: ldq_next[ldq_idx].addr,
                    is_write: 0,
                    data: 0
                };
              end
              DN_UART: begin
                req_to_plic = '{
                    valid: 1,
                    id: 32'(unsigned'(ldq_idx)),  // stはid不要.
                    paddr: ldq_next[ldq_idx].addr,
                    is_write: 0,
                    data: 0
                };
              end
              default: ;
            endcase
            ldq_next[ldq_idx].state = LD_DURING_REQUEST;
          end
        end
      end
    end

    // ------------------------------------------------------
    // deviceからのresを反映
    // -------------------------------------------------------
    // とりあえず現状では,mmio命令は先頭に来るまでlsuからreqが出されないので,
    // 同時に2つ以上のmmioにリクエストを送らない. よって2つ以上のレスポンスが同時に帰ってくることはない。
    // これなら1つのop_mmio_ld_outにしてもおそらく問題ない.
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      logic [XLEN-1:0] recieved_data_from_dev = 0;

      if (res_from_clint.valid || res_from_plic.valid) begin

        if (res_from_clint.valid) begin
          ldq_idx = LDQ_IDX_WIDTH'(res_from_clint.id);
          recieved_data_from_dev = res_from_clint.data;
        end else if (res_from_plic.valid) begin
          ldq_idx = LDQ_IDX_WIDTH'(res_from_plic.id);
          recieved_data_from_dev = res_from_plic.data;
        end

        op_mmio_out = '{
            valid: 1,
            opcode: ldq_next[ldq_idx].opcode,
            op_addr: ldq_next[ldq_idx].op_addr,
            rd_exist: 1,
            rd: ldq_next[ldq_idx].rd,
            rd_val: recieved_data_from_dev,
            al_idx: ldq_next[ldq_idx].al_idx,
            actual_taken: 0,
            actual_taken_addr: 0,
            ldst_target_addr: ldq_next[ldq_idx].addr,
            is_page_fault: 0,
            is_access_fault : 0
        };
        ldq_next[ldq_idx].state = LD_DONE;
      end
    end

    // ----------------------------------------------------
    // tlbからの返却をldq,stqに反映.
    // ----------------------------------------------------
    // tlb_port.res => ldq_ff, stq_ff
    // dtlbからの返却でldq,stqのpaddr_dw_alignedを更新.
    // idに関しては,id<LDQ_SIZEでldqへのres,id>=LDQ_SIZEでstqへのres
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;

      for (int unsigned i = 0; i < NUM_OF_DTLB_RES; i++) begin
        if (tlb_port.res[i].valid && tlb_port.res[i].generation == generation) begin

          // 
          // $display(
          //     "[LOG][LSU.sv] TLB RES ID:%0d PADDR:0x%0h, VADDR:0x%0h, PAGE_FAULT:%0b PTE_A:0x%0h PTE_D:0x%0h",
          //     tlb_port.res[i].id, tlb_port.res[i].paddr, tlb_port.res[i].vaddr,
          //     tlb_port.res[i].is_page_fault, tlb_port.res[i].pte_a, tlb_port.res[i].pte_d);

          if (tlb_port.res[i].id < LDQ_SIZE) begin
            // ld 命令のリクエストのレスポンス.
            // tlb_port.res => ldq_next
            ldq_idx = LDQ_IDX_WIDTH'(tlb_port.res[i].id);

            // tlbの返却による状態更新を行うが,access_fault,page_faultの場合,tvalでvaddrを使うので,
            // tlbの返却で.addrを更新しないようにする.
            if (tlb_port.res[i].is_page_fault || tlb_port.res[i].pte_a == 0) begin
              // page_fault時.
              // pte_a が0の場合もここに含まれる.svade拡張なので.
              ldq_next[ldq_idx].state = LD_PAGE_FAULT;
              // page_faultのログ出力.
              // if (tlb_port.res[i].is_page_fault) begin
              //   $display("[LOG][LSU.sv] This entry is page_fault");
              // end else if (tlb_port.res[i].pte_a == 0) begin
              //   $display("[LOG][LSU.sv] This exists, but pte_a == 0");
              // end
            end else if (tlb_port.res[i].pma_type == PMA_MEMORY) begin
              // pma_memory
              ldq_next[ldq_idx].addr  = tlb_port.res[i].paddr;
              ldq_next[ldq_idx].state = LD_BEFORE_CACHE_REQUEST;
            end else if (tlb_port.res[i].pma_type == PMA_MMIO) begin
              // mmioアクセス時.
              ldq_next[ldq_idx].addr  = tlb_port.res[i].paddr;
              ldq_next[ldq_idx].state = LD_BEFORE_MMIO_REQUEST;
            end else begin
              // access fault時
              // pma_typeがPMA_MMIOでもPMA_MEMORYでも無い場合はaccess_faultになる.
              ldq_next[ldq_idx].state = LD_ACCESS_FAULT;
              // $display("[LOG][LSU.sv] LD_ACCESS_FAULT detected.");
            end


          end else if (tlb_port.res[i].id < LDQ_SIZE + STQ_SIZE) begin
            // st命令のリクエストのレスポンス
            // tlb_port.res => stq_next
            stq_idx = STQ_IDX_WIDTH'(tlb_port.res[i].id - LDQ_SIZE);


            // tlbの返却による状態更新を行うが,access_fault,page_faultの場合,tvalでvaddrを使うので,
            // tlbの返却で.addrを更新しないようにする.
            if (tlb_port.res[i].is_page_fault || tlb_port.res[i].pte_a == 0 || tlb_port.res[i].pte_d == 0) begin
              // page_fault時.
              // svade拡張なので,a,dビットによるpage_faultもここに含まれる.
              stq_next[stq_idx].state = ST_PAGE_FAULT;
              // pagefaultのログ出力
              // if (tlb_port.res[i].is_page_fault) begin
              //   $display("[LOG][LSU.sv] This entry is page_fault");
              // end else if (tlb_port.res[i].pte_a == 0) begin
              //   $display("[LOG][LSU.sv] This exists, but pte_a == 0");
              // end else if (tlb_port.res[i].pte_d == 0) begin
              //   $display("[LOG][LSU.sv] This exists, but pte_d == 0");
              // end
            end else if (tlb_port.res[i].pma_type == PMA_MEMORY) begin
              // メインメモリへのアクセス.
              stq_next[stq_idx].addr = tlb_port.res[i].paddr;
              // この時点でpaddrが判明したので,stの種類に応じて状態遷移
              if (is_sc_opcode(stq_next[stq_idx].opcode)) begin
                stq_next[stq_idx].state = ST_CONDITIONAL_WAITING;
              end else begin
                stq_next[stq_idx].state = ST_BEFORE_EXE;
              end
            end else if (tlb_port.res[i].pma_type == PMA_MMIO) begin
              // mmioへのアクセス.
              stq_next[stq_idx].addr  = tlb_port.res[i].paddr;
              stq_next[stq_idx].state = ST_BEFORE_MMIO_REQUEST;
            end else begin
              // access fault時
              stq_next[stq_idx].state = ST_ACCESS_FAULT;
              // $display("[LOG][LSU.sv] ST_ACCESS_FAULT detected.");
            end


          end else begin
            // amo命令のtlbレスポンス
            ldq_idx = LDQ_IDX_WIDTH'(tlb_port.res[i].id - LDQ_SIZE - STQ_SIZE);
            stq_idx = ldq_next[ldq_idx].amo_corresponding_stq_idx;

            if (tlb_port.res[i].is_page_fault) begin
              // page fault時.
              ldq_next[ldq_idx].state = LD_PAGE_FAULT;
              stq_next[stq_idx].state = ST_PAGE_FAULT;
            end else if (tlb_port.res[i].pma_type != PMA_MEMORY) begin
              // access fault時
              ldq_next[ldq_idx].state = LD_ACCESS_FAULT;
              stq_next[stq_idx].state = ST_ACCESS_FAULT;
            end else begin
              // ldqの更新
              ldq_next[ldq_idx].addr  = tlb_port.res[i].paddr;
              ldq_next[ldq_idx].state = LD_BEFORE_CACHE_REQUEST;

              // stqの更新
              stq_next[stq_idx].addr  = tlb_port.res[i].paddr;
              stq_next[stq_idx].state = ST_AMO_WAITING_RS2;
            end
          end
        end
      end
    end

    // ---------------------------------------------------------
    // dtlbへの出力
    // ---------------------------------------------------------
    // ldqから2つ,stqから1つずつのリクエストを出す.
    // (ldのissueとstのissueと同じ数)
    // id < LDQ_SIZE で ld 命令のリクエスト.
    // LDQ_SIZE <= id < LDQ_SIZE + STQ_SIZE で st命令のリクエスト.
    // LDQ_SIZE + STQ_SIZE <= id でamo命令のリクエスト.
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;

      int unsigned ldq_tlb_counter = 0;
      int unsigned stq_tlb_counter = 0;

      for (int unsigned i = 0; i < NUM_OF_DTLB_REQ; i++) begin
        tlb_port.req[i] = '{default: 0};
      end

      if (!tlb_port.stall_req_to_dtlb) begin
        // readyは存在しない.その代わりtlbのpending_bufを大きく取ること.
        // if (tlb_port.ready)
        // ldq_next => tlb_port.req
        for (int unsigned i = 0; i < num_of_entries_in_ldq_next; i++) begin
          ldq_idx = LDQ_IDX_WIDTH'(32'(ldq_rp_next) + i);
          if (ldq_next[ldq_idx].state == LD_BEFORE_TLB_REQUEST && ldq_tlb_counter<NUM_OF_LD_ISSUE) begin
            tlb_port.req[ldq_tlb_counter] = '{
                valid: 1,
                id:
                is_amo_opcode
                (
                  ldq_next[ldq_idx].opcode
                ) ?
                32'(LDQ_SIZE + STQ_SIZE + 32'(ldq_idx))
                : 32'(
                ldq_idx
                ),
                id_sub: 1,
                generation: generation,
                satp: satp,
                vaddr: VADDR_WIDTH'(ldq_next[ldq_idx].addr)
            };
            ldq_next[ldq_idx].state = LD_DURING_TLB_REQUEST;
            ldq_tlb_counter++;
          end
        end

        // stq_next => tlb_port.req
        // amo系はldからのみtlbのリクエストを出す.(stに入ってるamo命令からはtlbにreqを出さない)
        for (int unsigned i = 0; i < num_of_entries_in_stq_next; i++) begin
          stq_idx = STQ_IDX_WIDTH'(32'(stq_rp_next) + i);
          if (stq_next[stq_idx].state == ST_BEFORE_TLB_REQUEST && stq_tlb_counter<NUM_OF_ST_AMO_ISSUE && 
              !is_amo_opcode(
                  stq_next[stq_idx].opcode
              )) begin
            tlb_port.req[NUM_OF_LD_ISSUE+stq_tlb_counter] = '{
                valid: 1,
                id: 32'(LDQ_SIZE + 32'(stq_idx)),
                id_sub: 1,
                generation: generation,
                satp: satp,
                vaddr: VADDR_WIDTH'(stq_next[stq_idx].addr)
            };
            stq_next[stq_idx].state = ST_DURING_TLB_REQUEST;
            stq_tlb_counter++;
          end
        end
      end
    end

    // ---------------------------------------------------------------------
    // コミットした命令をldq,stq,fenceqから削除, req_to_dcacheのst命令の製作.
    // ----------------------------------------------------------------------
    // committed_instr => ldq_next, stq_next, fenceq_next、, req_to_dcache
    // コミットした命令をldq,stq,fenceqから排除する
    // また,コミットしたst命令に関してはcache_reqとしてcacheに送る.
    // dcacheがいっぱいの場合,renamerでのコミットを抑制することでストア命令が
    // req_to_dcacheを次のサイクルに出すのを控える。
    // ldのreq_to_dcacheは,lsuで制御する.
    begin
      int unsigned st_commit_counter = 0;

      logic sc_failed = 0;

      // committed_istrの反映.
      for (int unsigned i = 0; i < NUM_OF_GRADUATE; i++) begin
        if (renamer_port.committed_instr[i].valid) begin
          // 削除されるのはldq,stq,fenceqの先頭から.
          // uniqueで無いのはamoのため.

          // LDQ からの削除
          if (num_of_entries_in_ldq_next >0 && renamer_port.committed_instr[i].al_idx == ldq_next[ldq_rp_next].al_idx) begin
            // ldq
            ldq_rp_next = ldq_rp_next + 1;
            num_of_entries_in_ldq_next--;
          end

          // STQからの削除.
          if (num_of_entries_in_stq_next>0 && renamer_port.committed_instr[i].al_idx == stq_next[stq_rp_next].al_idx) begin
            // commitしたものは,req_to_dcacheで送る
            // st_commit_counter < NUM_OF_ST_EXEは,alで卒業するst命令の最大数をNUM_OF_ST_EXEで指定しているから問題ない.
            // $display(
            //     "[LOG] [%s,%-d] st commit(st exe). OP_addr:%016h opcode:%s target_addr:%016h data:%016h, sc_success:%b",
            //     `__FILE__, `__LINE__, stq_next[stq_rp_next].op_addr,
            //     stq_next[stq_rp_next].opcode.name(), stq_next[stq_rp_next].addr,
            //     stq_next[stq_rp_next].rs2_val, stq_next[stq_rp_next].sc_success);

            // sc命令でかつfailした時と,st命令がmmioへのリクエストのときはcacheにreqを送らない.
            if ((!is_sc_opcode(
                    stq_next[stq_rp_next].opcode
                ) || stq_next[stq_rp_next].sc_success) &&
                    stq_next[stq_rp_next].state != ST_MMIO_DONE) begin
              // get_req_policyにamo
              req_to_dcache_next[st_commit_counter] = '{
                  valid: 1,
                  id: 0,  // 使用しない為.
                  id_sub: 0,
                  generation: 0,  //st命令は返答が無いのでgenerationは不要.
                  req_policy: get_write_req_policy(stq_next[stq_rp_next].opcode),
                  cb_req_type: WRITE_REQ_FROM_UPPER,
                  vaddr_dw_aligned: 0,
                  paddr_valid: 1,
                  paddr_dw_aligned: to_dw_aligned_paddr(stq_next[stq_rp_next].addr),
                  byte_in_dw_idx: stq_next[stq_rp_next].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB],
                  satp: satp,
                  data: stq_next[stq_rp_next].rs2_val
              };
              st_commit_counter++;
            end

            // stqから削除.
            stq_rp_next = stq_rp_next + 1;
            num_of_entries_in_stq_next--;
          end

          // FENCEQからの削除
          if (num_of_entries_in_fenceq_next >0 && renamer_port.committed_instr[i].al_idx == fenceq_next[fenceq_rp_next].al_idx) begin
            // fenceq
            fenceq_next[fenceq_rp_next].valid = 0;
            fenceq_rp_next = fenceq_rp_next + 1;
            num_of_entries_in_fenceq_next--;
          end
        end
      end


    end

    // ---------------------------------------------------
    // st命令の実行.
    // ---------------------------------------------------
    //
    begin
      // RAWハザード検出用パラメータ.
      logic ld_already_executed = 0;
      logic raw_order = 0;
      logic addr_dw_aligned_match = 0;

      logic ready_to_exe_stq_valid[NUM_OF_ST_EXE] = '{default: 0};
      logic [STQ_IDX_WIDTH-1:0] ready_to_exe_stq_idx[NUM_OF_ST_EXE] = '{default: 0};
      int unsigned ready_to_exe_stq_counter = 0;


      // stq内部の実行可能なst命令の抽出.
      for (int unsigned i = 0; i < num_of_entries_in_stq_next; i++) begin
        logic [STQ_IDX_WIDTH-1:0] stq_idx = stq_rp_next + STQ_IDX_WIDTH'(i);
        // exeできるldをready_to_exeに登録.
        if(stq_next[stq_idx].state == ST_BEFORE_EXE && !ft[stq_next[stq_idx].al_idx].st_blocked  && 
           ready_to_exe_stq_counter<NUM_OF_ST_EXE)begin
          ready_to_exe_stq_valid[ready_to_exe_stq_counter] = 1;
          ready_to_exe_stq_idx[ready_to_exe_stq_counter]   = stq_idx;
          ready_to_exe_stq_counter++;
        end
      end

      // この時点で,RAWハザードが存在するかの確認(=stの実行)を行う.
      // 比較は面倒なのでdw単位で行う.
      for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
        logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
        logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
        stq_idx = ready_to_exe_stq_idx[i];

        if (ready_to_exe_stq_valid[i]) begin

          // RAWハザードの探索.
          for (int unsigned k = 0; k < num_of_entries_in_ldq_next; k++) begin
            ldq_idx = LDQ_IDX_WIDTH'(32'(ldq_rp_next) + k);
            // ldqのうち,有効で,st命令よりも前に発行されているものを探す.
            ld_already_executed = ldq_next[ldq_idx].state inside {LD_DURING_REQUEST, LD_DONE};
            raw_order = is_left_older(stq_next[stq_idx].al_idx, ldq_next[ldq_idx].al_idx);
            addr_dw_aligned_match = to_dw_aligned_paddr(stq_next[stq_idx].addr) ==
                to_dw_aligned_paddr(ldq_next[ldq_idx].addr);

            // rawハザードが発生してるかのログ.
            // $display(
            //     "[LOG] [%s,%-d] raw hazard check st_op_addr:%016h ld_op_addr:%016h ld_already_executed:%b raw_order:%b addr_dw_aligned_match:%b",
            //     `__FILE__, `__LINE__, stq_next[stq_idx].op_addr, ldq_next[ldq_idx].op_addr,
            //     ld_already_executed, raw_order, addr_dw_aligned_match);

            if (ld_already_executed && raw_order && addr_dw_aligned_match) begin
              // ヒットしたらint issue queueとrenamerにフィードバックする.
              // どうせそっからやり直すので一番古いldエントリ一つで良い.
              ld_speculative_feedback_valid_next  = 1;
              ld_speculative_feedback_al_idx_next = ldq_next[ldq_idx].al_idx;
              break;
            end
          end


          // RAWハザードが起こるか起こらないかに関わらずstは実行する.
          // SCの場合は,lrsc_lockによってrdが変わる.
          if (stq_next[stq_idx].opcode inside {SC_W, SC_D}) begin
            // scはrd有りでresult_opを出す.
            op_st_out_next[i] = '{
                valid: 1,
                opcode: stq_next[stq_idx].opcode,
                op_addr: stq_next[stq_idx].op_addr,
                rd_exist: 1,
                rd: stq_next[stq_idx].rd,
                rd_val: stq_next[stq_idx].sc_success ? 0 : 1,
                al_idx: stq_next[stq_idx].al_idx,
                actual_taken: 0,
                actual_taken_addr: 0,
                ldst_target_addr: stq_next[stq_idx].addr,
                is_page_fault: 0,
                is_access_fault: 0
            };

          end else begin
            // 普通のst命令
            op_st_out_next[i] = '{
                valid: 1,
                opcode: stq_next[stq_idx].opcode,
                op_addr: stq_next[stq_idx].op_addr,
                rd_exist: 0,
                rd: 0,
                rd_val: 0,
                al_idx: stq_next[stq_idx].al_idx,
                actual_taken: 0,
                actual_taken_addr: 0,
                ldst_target_addr: stq_next[stq_idx].addr,
                is_page_fault: 0,
                is_access_fault: 0
            };
          end


          stq_next[stq_idx].state = ST_DONE;

          // ld_speculative_feedbackの上書きを防ぐ為にここでstの実行を中止する.
          // 異なるstに対してハザードを検出すると,より古いldに対するflushを上書きして消してしまうことも有るためbreak.
          if (ld_speculative_feedback_valid_next == 1) begin
            break;
          end


        end
      end

    end


    // -------------------------------------------------
    // ld命令の実行
    // -------------------------------------------------
    // ldq_next => req_to_dcache
    // バイパス可能なstが存在しなければキャッシュに送る.
    begin
      // exeすることができるldq_idxを特定.
      logic ready_to_exe_ldq_valid[NUM_OF_LD_EXE] = '{default: 0};
      logic [LDQ_IDX_WIDTH-1:0] ready_to_exe_ldq_idx[NUM_OF_LD_EXE] = '{default: 0};
      int unsigned ready_to_exe_ldq_counter = 0;

      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        op_ld_out_next[i] = '{valid: 0, opcode: NOP, default: 0};
      end


      // exeすることができるldq_idxを特定.
      for (int unsigned i = 0; i < num_of_entries_in_ldq_next; i++) begin
        logic [LDQ_IDX_WIDTH-1:0] ldq_idx = ldq_rp_next + LDQ_IDX_WIDTH'(i);

        // exeできるldをready_to_exeに登録.
        // dcacheに空きがないなら実行しない
        if(ldq_next[ldq_idx].state == LD_BEFORE_CACHE_REQUEST && !ft[ldq_next[ldq_idx].al_idx].ld_blocked  && 
           ready_to_exe_ldq_counter<NUM_OF_LD_EXE && !dcache_noroom)begin
          ready_to_exe_ldq_valid[ready_to_exe_ldq_counter] = 1;
          ready_to_exe_ldq_idx[ready_to_exe_ldq_counter]   = ldq_idx;
          ready_to_exe_ldq_counter++;
        end
      end

      // ld命令の実行.
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        logic [LDQ_IDX_WIDTH-1:0] ldq_idx = ready_to_exe_ldq_idx[i];
        logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;

        logic st_has_done = 0;
        logic is_st_before_ld = 0;
        logic is_same_paddr_dw_aligned = 0;
        // TODO: バイパスはとりあえず無し.
        // なぜなら,先行するstと部分的にかぶってるものが存在するかもしれないので.
        // まあそれだけ抜き出せば良いんだけど面倒なので後回し.

        // ldの実行.
        if (ready_to_exe_ldq_valid[i]) begin


          // このldよりも前に実行されたが、まだキャッシュに送られていないst命令を一時的に個々に保存しておく.
          // キャッシュから帰ってきたときにそのデータをマージする.
          for (int unsigned j = 0; j < num_of_entries_in_stq_next; j++) begin
            stq_idx = stq_rp_next + STQ_IDX_WIDTH'(j);
            // stが終了済みで,ldよりstが前にあり,ldとstが同じときにバイパスを行う.
            st_has_done = stq_next[stq_idx].state == ST_DONE &&
                (!is_sc_opcode(stq_next[stq_idx].opcode) || stq_next[stq_idx].sc_success);
            is_st_before_ld = is_left_older(stq_next[stq_idx].al_idx, ldq_next[ldq_idx].al_idx);
            is_same_paddr_dw_aligned = to_dw_aligned_paddr(stq_next[stq_idx].addr) ==
                to_dw_aligned_paddr(ldq_next[ldq_idx].addr);

            // $display(
            //     "[LOG] [%s,%-d] LD executed LD_op_addr:%016h opcode:%s st_op_addr:%016h st_has_done:%b is_st_before_ld:%b, sc_failed:%b",
            //     `__FILE__, `__LINE__, ldq_next[ldq_idx].op_addr, ldq_next[ldq_idx].opcode.name(),
            //     stq_next[stq_idx].op_addr, st_has_done, is_st_before_ld,
            //     stq_next[stq_idx].sc_failed);

            if (st_has_done && is_st_before_ld && is_same_paddr_dw_aligned) begin
              for (int unsigned k = 0; k < XLEN / 8; k++) begin
                if (stq_next[stq_idx].rs2_val_mask[k]) begin
                  ldq_next[ldq_idx].bypass_data_mask[k] = 1'b1;
                  ldq_next[ldq_idx].bypass_data[k*8+:8] = stq_next[stq_idx].rs2_val[k*8+:8];
                end
              end
            end
          end

          // $display(
          //     "[LOG] [%s,%-d] LD executed OP_Addr:%016h opcode:%s bypass_data_mask:%08b bypass_data:%016h",
          //     `__FILE__, `__LINE__, ldq_next[ldq_idx].op_addr, ldq_next[ldq_idx].opcode.name(),
          //     ldq_next[ldq_idx].bypass_data_mask, ldq_next[ldq_idx].bypass_data);


          // stがコミットされて,req_to_cacheに入ったあとに,ld命令の実行可能性やバイパスなどを調べているので,
          // インデックスは[NUM_OF_LD_EXE+i]になる.
          req_to_dcache_next[NUM_OF_ST_EXE+i] = '{
              valid: 1,
              id: 32'(ldq_idx),
              id_sub: 0,
              generation: generation,
              req_policy: get_read_req_policy(ldq_next[ldq_idx].opcode),
              cb_req_type: READ_REQ_FROM_UPPER,
              vaddr_dw_aligned: 0,
              paddr_valid: 1,
              paddr_dw_aligned: to_dw_aligned_paddr(ldq_next[ldq_idx].addr),
              byte_in_dw_idx: ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB],
              satp: satp,
              data: 0
          };
          ldq_next[ldq_idx].state = LD_DURING_REQUEST;
        end

      end
    end


    // -------------------------------------------------------------------------------------
    //  cache_resの内容をstへの書き込み(amo系のld命令)と,op_ld_out(ロード命令の結果返却)に分別
    // --------------------------------------------------------------------------------------

    // readのreqだけ帰ってくるので,それに対応するld命令がamo系かの判別をする.
    for (int unsigned i = 0; i < NUM_OF_CACHE_RES; i++) begin
      // もしflush前と同じidのものが帰ってきたらどうする.
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = LDQ_IDX_WIDTH'(res_from_dcache[i].id);
      logic [XLEN-1:0] cache_data_dw_aligned = 0;
      logic [XLEN-1:0] ld_data = 0;
      logic [$clog2(DW_SIZE)-1:0] byte_in_dw_idx = 0;
      // マスク
      if (res_from_dcache[i].valid && (res_from_dcache[i].generation == generation)) begin
        // cache_resのidがldq_idxになっている.
        // amo,非amoともに,読み出した値をop_ld_outとしてop_outで出力する.

        // cacheの入出力は64bit単位で行われるため.とりあえずここにいれて,
        // 後で必要なものを抜き出してbypassed_dataとマージする.
        cache_data_dw_aligned = res_from_dcache[i].data;

        // $display("[LOG] [%s,%-d] opcode:%s rd:%h paddr:%016h byte_in_dw_idx", `__FILE__, `__LINE__,
        //          ldq_next[ldq_idx].opcode.name(), ldq_next[ldq_idx].rd,
        //          res_from_dcache[i].paddr_dw_aligned, res_from_dcache[i].byte_in_dw_idx);


        // もし先行するst命令で,これの読み込み位置と一致するものが存在する場合,
        // その値で上書きを行う
        // このld命令より前にあるst命令で,
        for (int unsigned j = 0; j < XLEN / 8; j++) begin
          if (ldq_next[ldq_idx].bypass_data_mask[j]) begin
            cache_data_dw_aligned[j*8+:8] = ldq_next[ldq_idx].bypass_data[j*8+:8];
          end
        end


        // $display(
        //     "[LOG] [%s,%-d] OP_Addr:%010h opcode:%s rd:%h target_paddr:%0h14, cache_data_dw_aligned:%016h",
        //     `__FILE__, `__LINE__, ldq_next[ldq_idx].op_addr, ldq_next[ldq_idx].opcode.name(),
        //     ldq_next[ldq_idx].rd, ldq_next[ldq_idx].addr, cache_data_dw_aligned);

        case (ldq_next[ldq_idx].opcode)
          LB: begin
            ld_data = XLEN'($signed(cache_data_dw_aligned[
                                    ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:8]));
          end
          LH: begin
            ld_data = XLEN'($signed(cache_data_dw_aligned[
                                    ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:16]));
          end
          LW: begin
            ld_data = XLEN'($signed(cache_data_dw_aligned[
                                    ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:32]));
          end
          LD: begin
            ld_data = cache_data_dw_aligned;
          end
          LBU: begin
            ld_data = XLEN'($unsigned(cache_data_dw_aligned[
                                      ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:8]));
          end
          LHU: begin
            ld_data = XLEN'($unsigned(cache_data_dw_aligned[ldq_next[ldq_idx].addr[
                                                            BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:16]));
          end
          LWU: begin
            ld_data = XLEN'($unsigned(cache_data_dw_aligned[ldq_next[ldq_idx].addr[
                                                            BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:32]));
          end
          LR_W, AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W, AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W:begin
            ld_data = XLEN'($signed(cache_data_dw_aligned[
                                    ldq_next[ldq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB]*8+:32]));
          end
          LR_D, AMOSWAP_D, AMOADD_D, AMOXOR_D, AMOAND_D, AMOOR_D, AMOMIN_D, AMOMAX_D, AMOMINU_D, AMOMAXU_D: begin
            ld_data = cache_data_dw_aligned;
          end
          default: ;
        endcase

        // $display(
        //     "[LOG] [%s,%-d] res recieved from d$. op_addr:%016h opcode:%s rd:%h data_addr:%016h ld_data:%016h",
        //     `__FILE__, `__LINE__, ldq_next[ldq_idx].op_addr, ldq_next[ldq_idx].opcode.name(),
        //     ldq_next[ldq_idx].rd, ldq_next[ldq_idx].addr, ld_data);

        // 出力.
        op_ld_out_next[i] = '{
            valid: 1,
            opcode: ldq_next[ldq_idx].opcode,
            op_addr: ldq_next[ldq_idx].op_addr,
            rd_exist: 1,
            rd: ldq_next[ldq_idx].rd,
            rd_val: ld_data,
            al_idx: ldq_next[ldq_idx].al_idx,
            actual_taken: 0,
            actual_taken_addr: 0,
            ldst_target_addr: ldq_next[ldq_idx].addr,
            is_page_fault: 0,
            is_access_fault: 0
        };
        ldq_next[ldq_idx].state = LD_DONE;

        if (is_amo_opcode(ldq_next[ldq_idx].opcode)) begin
          // amo系のld命令である場合,op_outに追加でstqの更新も行う.
          stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].amo_ready = 1;
          byte_in_dw_idx = stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].addr[BYTE_IN_DW_MSB:BYTE_IN_DW_LSB];
          // 計算してrs2の更新
          if(ldq_next[ldq_idx].opcode inside {AMOSWAP_W, AMOADD_W, AMOXOR_W, AMOAND_W, AMOOR_W, AMOMIN_W, AMOMAX_W, AMOMINU_W, AMOMAXU_W})begin
            // 32bit
            stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].rs2_val[byte_in_dw_idx*8+:32] = amo_calc_w(
              ldq_next[ldq_idx].opcode,
              ld_data[31:0],
              stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].rs2_val[byte_in_dw_idx*8+:32]
            );
          end else begin
            // 64bit
            stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].rs2_val = amo_calc_dw(
              ldq_next[ldq_idx].opcode,
              ld_data,
              stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].rs2_val
            );
          end

          // また,この時点で必要なrs2が手に入ったので,状態の更新
          stq_next[ldq_next[ldq_idx].amo_corresponding_stq_idx].state = ST_BEFORE_EXE;
        end

      end
    end

    // ----------------------------------------------------
    // page_faultな命令の出力
    // ----------------------------------------------------
    // op_st_out_next, op_ld_out_nextに空きがあれば,page_faultなldqやstqのエントリをDONEにする.
    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        if (!op_ld_out_next[i].valid) begin
          for (int unsigned j = 0; j < num_of_entries_in_ldq_next; j++) begin
            ldq_idx = LDQ_IDX_WIDTH'(ldq_rp_next + LDQ_IDX_WIDTH'(j));
            if (ldq_next[ldq_idx].state == LD_PAGE_FAULT) begin

              // $display("[LOG][%s,%-d] page fault ldst_target_addr:%010h", `__FILE__, `__LINE__,
              //          PADDR_WIDTH'(signed'(ldq_next[ldq_idx].addr)));
              op_ld_out_next[i] = '{
                  valid: 1,
                  opcode: ldq_next[ldq_idx].opcode,
                  op_addr: ldq_next[ldq_idx].op_addr,
                  rd_exist: 1,
                  rd: ldq_next[ldq_idx].rd,
                  rd_val: 0,
                  al_idx: ldq_next[ldq_idx].al_idx,
                  actual_taken: 0,
                  actual_taken_addr: 0,
                  ldst_target_addr:
                  PADDR_WIDTH
                  '(
                  signed'(ldq_next[ldq_idx].addr)
                  ),  // tvalで使用するのでvaddr
                  is_page_fault: 1,
                  is_access_fault: 0
              };
              ldq_next[ldq_idx].state = LD_DONE;
              break;
            end
          end
        end
      end
    end

    begin
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
        if (!op_st_out_next[i].valid) begin
          for (int unsigned j = 0; j < num_of_entries_in_stq_next; j++) begin
            stq_idx = STQ_IDX_WIDTH'(stq_rp_next + STQ_IDX_WIDTH'(j));
            if (stq_next[stq_idx].state == ST_PAGE_FAULT) begin

              // $display("[LOG][%s,%-d] page fault ldst_target_addr:%010h", `__FILE__, `__LINE__,
              //          PADDR_WIDTH'(signed'(stq_next[stq_idx].addr)));
              op_st_out_next[i] = '{
                  valid: 1,
                  opcode: stq_next[stq_idx].opcode,
                  op_addr: stq_next[stq_idx].op_addr,
                  rd_exist: 1,
                  rd: stq_next[stq_idx].rd,
                  rd_val: 0,
                  al_idx: stq_next[stq_idx].al_idx,
                  actual_taken: 0,
                  actual_taken_addr: 0,
                  ldst_target_addr:
                  PADDR_WIDTH
                  '(
                  signed'(stq_next[stq_idx].addr)
                  ),  // tvalで使用するのでvaddr
                  is_page_fault: 1,
                  is_access_fault: 0
              };
              stq_next[stq_idx].state = ST_DONE;
              break;
            end
          end
        end
      end
    end

    // ----------------------------------------------------------
    //access faultな命令の出力
    // -----------------------------------------------------------

    begin
      logic [LDQ_IDX_WIDTH-1:0] ldq_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_LD_EXE; i++) begin
        if (!op_ld_out_next[i].valid) begin
          for (int unsigned j = 0; j < num_of_entries_in_ldq_next; j++) begin
            ldq_idx = LDQ_IDX_WIDTH'(ldq_rp_next + LDQ_IDX_WIDTH'(j));
            if (ldq_next[ldq_idx].state == LD_ACCESS_FAULT) begin

              // $display("[LOG][%s,%-d] access fault ldst_target_addr:%010h", `__FILE__, `__LINE__,
              //          PADDR_WIDTH'(signed'(ldq_next[ldq_idx].addr)));
              op_ld_out_next[i] = '{
                  valid: 1,
                  opcode: ldq_next[ldq_idx].opcode,
                  op_addr: ldq_next[ldq_idx].op_addr,
                  rd_exist: 1,
                  rd: ldq_next[ldq_idx].rd,
                  rd_val: 0,
                  al_idx: ldq_next[ldq_idx].al_idx,
                  actual_taken: 0,
                  actual_taken_addr: 0,
                  ldst_target_addr:
                  PADDR_WIDTH
                  '(
                  signed'(ldq_next[ldq_idx].addr)
                  ),  // tvalで使用するのでvaddr
                  is_page_fault: 0,
                  is_access_fault: 1
              };
              ldq_next[ldq_idx].state = LD_DONE;
              break;
            end
          end
        end
      end
    end

    begin
      logic [STQ_IDX_WIDTH-1:0] stq_idx = 0;
      for (int unsigned i = 0; i < NUM_OF_ST_EXE; i++) begin
        if (!op_st_out_next[i].valid) begin
          for (int unsigned j = 0; j < num_of_entries_in_stq_next; j++) begin
            stq_idx = STQ_IDX_WIDTH'(stq_rp_next + STQ_IDX_WIDTH'(j));
            if (stq_next[stq_idx].state == ST_ACCESS_FAULT) begin
              // $display("[LOG][%s,%-d] access fault ldst_target_addr:%010h", `__FILE__, `__LINE__,
              //          PADDR_WIDTH'(signed'(stq_next[stq_idx].addr)));
              op_st_out_next[i] = '{
                  valid: 1,
                  opcode: stq_next[stq_idx].opcode,
                  op_addr: stq_next[stq_idx].op_addr,
                  rd_exist: 1,
                  rd: stq_next[stq_idx].rd,
                  rd_val: 0,
                  al_idx: stq_next[stq_idx].al_idx,
                  actual_taken: 0,
                  actual_taken_addr: 0,
                  ldst_target_addr:
                  PADDR_WIDTH
                  '(
                  signed'(stq_next[stq_idx].addr)
                  ),  // tvalで使用するのでvaddr
                  is_page_fault: 0,
                  is_access_fault: 1
              };
              stq_next[stq_idx].state = ST_DONE;
              break;
            end
          end
        end
      end
    end

  end




  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // ldq
      ldq <= '{default: 0};
      ldq_rp <= 0;
      ldq_wp <= 0;
      num_of_entries_in_ldq <= 0;

      // stq
      stq <= '{default: 0};
      stq_rp <= 0;
      stq_wp <= 0;
      num_of_entries_in_stq <= 0;

      // fenceq
      fenceq <= '{default: 0};
      fenceq_rp <= 0;
      fenceq_wp <= 0;
      num_of_entries_in_fenceq <= 0;


      // lrsc
      // lrsc_lock <= '{default: 0};

      // // => renamer
      // renamer_port.st_tentative_executed_valid <= '{default: 0};
      // renamer_port.st_tentative_executed_al_idx <= '{default: 0};
      renamer_port.ld_speculative_feedback_valid <= 0;
      renamer_port.ld_speculative_feedback_al_idx <= '{default: 0};

      // => int issue queue
      ld_speculative_feedback_valid <= 0;
      ld_speculative_feedback_al_idx <= '{default: 0};

      // 出力
      op_ld_out <= '{default: 0};
      op_st_out <= '{default: 0};
      req_to_dcache <= '{default: 0};
    end else if (flush_in) begin

      // ldq
      ldq <= '{default: 0};
      ldq_rp <= 0;
      ldq_wp <= 0;
      num_of_entries_in_ldq <= 0;

      // stq
      stq <= '{default: 0};
      stq_rp <= 0;
      stq_wp <= 0;
      num_of_entries_in_stq <= 0;

      // fenceq
      fenceq <= '{default: 0};
      fenceq_rp <= 0;
      fenceq_wp <= 0;
      num_of_entries_in_fenceq <= 0;

      // lrsc_lock
      // interruptとかでリセットされても多分大丈夫.
      // lrscって理由なく失敗していいらしいし.
      //  lrsc_lock <= '{default: 0};

      // => renamer
      // renamer_port.st_tentative_executed_valid <= '{default: 0};
      // renamer_port.st_tentative_executed_al_idx <= '{default: 0};
      renamer_port.ld_speculative_feedback_valid <= 0;
      renamer_port.ld_speculative_feedback_al_idx <= '{default: 0};

      // => int issue queue
      ld_speculative_feedback_valid <= 0;
      ld_speculative_feedback_al_idx <= '{default: 0};


      // 出力
      op_ld_out <= '{default: 0};
      op_st_out <= '{default: 0};
      // flushされるのと同じタイミングでstを実行(コミット)した場合,次の立ち上がりでコミット可能です！なので次の立ち上がりでdcacheにreqを出してください！！
      // という命令をrenamerからlsuに送っていると同時に,renamerはldのmispredictionでflushしてくださいという司令も送っているので,それによって上書きされる.
      // だからreq_to_dcache_nextは出力する.古いread_reqはgenerationで判断できるから出しても問題ないし.
      req_to_dcache <= req_to_dcache_next;

    end else begin
      // ldq
      ldq <= ldq_next;
      ldq_rp <= ldq_rp_next;
      ldq_wp <= ldq_wp_next;
      num_of_entries_in_ldq <= num_of_entries_in_ldq_next;

      // stq
      stq <= stq_next;
      stq_rp <= stq_rp_next;
      stq_wp <= stq_wp_next;
      num_of_entries_in_stq <= num_of_entries_in_stq_next;

      // fenceq
      fenceq <= fenceq_next;
      fenceq_rp <= fenceq_rp_next;
      fenceq_wp <= fenceq_wp_next;
      num_of_entries_in_fenceq <= num_of_entries_in_fenceq_next;

      // lrsc_lock
      // lrsc_lock <= lrsc_lock_next;

      // => renamer
      // renamer_port.st_tentative_executed_valid <= st_tentative_executed_valid_next;
      // renamer_port.st_tentative_executed_al_idx <= st_tentative_executed_al_idx_next;
      renamer_port.ld_speculative_feedback_valid <= ld_speculative_feedback_valid_next;
      renamer_port.ld_speculative_feedback_al_idx <= ld_speculative_feedback_al_idx_next;

      // int issue queue
      ld_speculative_feedback_valid <= ld_speculative_feedback_valid_next;
      ld_speculative_feedback_al_idx <= ld_speculative_feedback_al_idx_next;

      // 出力
      op_ld_out <= op_ld_out_next;
      op_st_out <= op_st_out_next;
      req_to_dcache <= req_to_dcache_next;
    end
  end


  // FOR DEBUG

  stq_t stq_next0;
  stq_t stq_next1;
  stq_t stq_next2;
  stq_t stq_next3;
  stq_t stq_next4;
  stq_t stq_next5;
  stq_t stq_next6;
  stq_t stq_next7;
  stq_t stq_next8;
  stq_t stq_next9;
  stq_t stq_next10;
  stq_t stq_next11;
  stq_t stq_next12;
  stq_t stq_next13;
  stq_t stq_next14;
  stq_t stq_next15;
  stq_t stq_next16;
  stq_t stq_next17;
  stq_t stq_next18;
  stq_t stq_next19;
  stq_t stq_next20;
  stq_t stq_next21;
  stq_t stq_next22;
  stq_t stq_next23;
  stq_t stq_next24;
  stq_t stq_next25;
  stq_t stq_next26;
  stq_t stq_next27;
  stq_t stq_next28;
  stq_t stq_next29;
  stq_t stq_next30;
  stq_t stq_next31;
  stq_t stq_next32;
  stq_t stq_next33;
  stq_t stq_next34;
  stq_t stq_next35;
  stq_t stq_next36;
  stq_t stq_next37;
  stq_t stq_next38;
  stq_t stq_next39;
  stq_t stq_next40;
  stq_t stq_next41;
  stq_t stq_next42;
  stq_t stq_next43;
  stq_t stq_next44;
  stq_t stq_next45;
  stq_t stq_next46;
  stq_t stq_next47;
  stq_t stq_next48;
  stq_t stq_next49;
  stq_t stq_next50;
  stq_t stq_next51;
  stq_t stq_next52;
  stq_t stq_next53;
  stq_t stq_next54;
  stq_t stq_next55;
  stq_t stq_next56;
  stq_t stq_next57;
  stq_t stq_next58;
  stq_t stq_next59;
  stq_t stq_next60;
  stq_t stq_next61;
  stq_t stq_next62;
  stq_t stq_next63;

  always_comb begin
    stq_next0 = stq_next[0];
  end
  always_comb begin
    stq_next1 = stq_next[1];
  end
  always_comb begin
    stq_next2 = stq_next[2];
  end
  always_comb begin
    stq_next3 = stq_next[3];
  end
  always_comb begin
    stq_next4 = stq_next[4];
  end
  always_comb begin
    stq_next5 = stq_next[5];
  end
  always_comb begin
    stq_next6 = stq_next[6];
  end
  always_comb begin
    stq_next7 = stq_next[7];
  end
  always_comb begin
    stq_next8 = stq_next[8];
  end
  always_comb begin
    stq_next9 = stq_next[9];
  end
  always_comb begin
    stq_next10 = stq_next[10];
  end
  always_comb begin
    stq_next11 = stq_next[11];
  end
  always_comb begin
    stq_next12 = stq_next[12];
  end
  always_comb begin
    stq_next13 = stq_next[13];
  end
  always_comb begin
    stq_next14 = stq_next[14];
  end
  always_comb begin
    stq_next15 = stq_next[15];
  end
  always_comb begin
    stq_next16 = stq_next[16];
  end
  always_comb begin
    stq_next17 = stq_next[17];
  end
  always_comb begin
    stq_next18 = stq_next[18];
  end
  always_comb begin
    stq_next19 = stq_next[19];
  end
  always_comb begin
    stq_next20 = stq_next[20];
  end
  always_comb begin
    stq_next21 = stq_next[21];
  end
  always_comb begin
    stq_next22 = stq_next[22];
  end
  always_comb begin
    stq_next23 = stq_next[23];
  end
  always_comb begin
    stq_next24 = stq_next[24];
  end
  always_comb begin
    stq_next25 = stq_next[25];
  end
  always_comb begin
    stq_next26 = stq_next[26];
  end
  always_comb begin
    stq_next27 = stq_next[27];
  end
  always_comb begin
    stq_next28 = stq_next[28];
  end
  always_comb begin
    stq_next29 = stq_next[29];
  end
  always_comb begin
    stq_next30 = stq_next[30];
  end
  always_comb begin
    stq_next31 = stq_next[31];
  end
  always_comb begin
    stq_next32 = stq_next[32];
  end
  always_comb begin
    stq_next33 = stq_next[33];
  end
  always_comb begin
    stq_next34 = stq_next[34];
  end
  always_comb begin
    stq_next35 = stq_next[35];
  end
  always_comb begin
    stq_next36 = stq_next[36];
  end
  always_comb begin
    stq_next37 = stq_next[37];
  end
  always_comb begin
    stq_next38 = stq_next[38];
  end
  always_comb begin
    stq_next39 = stq_next[39];
  end
  always_comb begin
    stq_next40 = stq_next[40];
  end
  always_comb begin
    stq_next41 = stq_next[41];
  end
  always_comb begin
    stq_next42 = stq_next[42];
  end
  always_comb begin
    stq_next43 = stq_next[43];
  end
  always_comb begin
    stq_next44 = stq_next[44];
  end
  always_comb begin
    stq_next45 = stq_next[45];
  end
  always_comb begin
    stq_next46 = stq_next[46];
  end
  always_comb begin
    stq_next47 = stq_next[47];
  end
  always_comb begin
    stq_next48 = stq_next[48];
  end
  always_comb begin
    stq_next49 = stq_next[49];
  end
  always_comb begin
    stq_next50 = stq_next[50];
  end
  always_comb begin
    stq_next51 = stq_next[51];
  end
  always_comb begin
    stq_next52 = stq_next[52];
  end
  always_comb begin
    stq_next53 = stq_next[53];
  end
  always_comb begin
    stq_next54 = stq_next[54];
  end
  always_comb begin
    stq_next55 = stq_next[55];
  end
  always_comb begin
    stq_next56 = stq_next[56];
  end
  always_comb begin
    stq_next57 = stq_next[57];
  end
  always_comb begin
    stq_next58 = stq_next[58];
  end
  always_comb begin
    stq_next59 = stq_next[59];
  end
  always_comb begin
    stq_next60 = stq_next[60];
  end
  always_comb begin
    stq_next61 = stq_next[61];
  end
  always_comb begin
    stq_next62 = stq_next[62];
  end
  always_comb begin
    stq_next63 = stq_next[63];
  end


endmodule
