// HartTopで使用される構造体やインターフェイスなどの定義.

`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"

`ifndef COMMON_DEFS_IFDEF
`define COMMON_DEFS_IFDEF

package HART_DEFS;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;

  // 命令の種類
  typedef enum logic [7:0] {
    //** RV64I Base Instruction Set **//

    // NOP
    NOP = 8'h00,

    // 算術命令
    ADD  = 8'h01,
    SUB  = 8'h02,
    SLL  = 8'h03,
    SLT  = 8'h04,
    OR   = 8'h05,
    AND  = 8'h06,
    XOR  = 8'h07,
    SRL  = 8'h08,
    SRA  = 8'h09,
    SLTU = 8'h0A,
    ADDW = 8'h0B,
    SUBW = 8'h0C,
    SLLW = 8'h0D,
    SRLW = 8'h0E,
    SRAW = 8'h0F,

    // 即値算術命令
    ADDI  = 8'h10,
    SLTI  = 8'h11,
    SLTIU = 8'h12,
    XORI  = 8'h13,
    ORI   = 8'h14,
    ANDI  = 8'h15,
    SLLI  = 8'h16,
    SRLI  = 8'h17,
    SRAI  = 8'h18,
    SRAIW = 8'h19,
    ADDIW = 8'h1A,
    SLLIW = 8'h1B,
    SRLIW = 8'h1C,

    // ロード命令
    LB  = 8'h1D,
    LH  = 8'h1E,
    LW  = 8'h1F,
    LD  = 8'h20,
    LBU = 8'h21,
    LHU = 8'h22,
    LWU = 8'h23,

    // ストア命令
    SB = 8'h24,
    SH = 8'h25,
    SW = 8'h26,
    SD = 8'h27,

    // 分岐命令
    BEQ  = 8'h28,
    BNE  = 8'h29,
    BLT  = 8'h2A,
    BGE  = 8'h2B,
    BLTU = 8'h2C,
    BGEU = 8'h2D,

    // ジャンプ命令
    JAL  = 8'h2E,
    JALR = 8'h2F,

    // 即値部分算術命令
    LUI   = 8'h30,
    AUIPC = 8'h31,

    // メモリ順序命令
    FENCE     = 8'h32,
    FENCE_TSO = 8'h33,
    PAUSE     = 8'h34,

    // 環境命令
    ECALL  = 8'h35,
    EBREAK = 8'h36,

    // RV64 Zifencei Standard Extension
    FENCE_I = 8'h37,

    // RV64 Zicsr Standard Extension
    CSRRW  = 8'h38,
    CSRRS  = 8'h39,
    CSRRC  = 8'h3A,
    CSRRWI = 8'h3B,
    CSRRSI = 8'h3C,
    CSRRCI = 8'h3D,

    // RV64M Standard Extension
    MUL    = 8'h3E,
    MULH   = 8'h3F,
    MULHSU = 8'h40,
    MULHU  = 8'h41,
    DIV    = 8'h42,
    DIVU   = 8'h43,
    REM    = 8'h44,
    REMU   = 8'h45,
    MULW   = 8'h46,
    DIVW   = 8'h47,
    DIVUW  = 8'h48,
    REMW   = 8'h49,
    REMUW  = 8'h4A,

    // RV64A Standard Extension (Atomic)
    LR_W      = 8'h4B,
    SC_W      = 8'h4C,
    AMOSWAP_W = 8'h4D,
    AMOADD_W  = 8'h4E,
    AMOXOR_W  = 8'h4F,
    AMOAND_W  = 8'h50,
    AMOOR_W   = 8'h51,
    AMOMIN_W  = 8'h52,
    AMOMAX_W  = 8'h53,
    AMOMINU_W = 8'h54,
    AMOMAXU_W = 8'h55,
    LR_D      = 8'h56,
    SC_D      = 8'h57,
    AMOSWAP_D = 8'h58,
    AMOADD_D  = 8'h59,
    AMOXOR_D  = 8'h5A,
    AMOAND_D  = 8'h5B,
    AMOOR_D   = 8'h5C,
    AMOMIN_D  = 8'h5D,
    AMOMAX_D  = 8'h5E,
    AMOMINU_D = 8'h5F,
    AMOMAXU_D = 8'h60,

    // トラップ復帰命令(特権命令)
    MRET = 8'h61,
    SRET = 8'h62,

    // 割り込み管理命令(特権命令)
    WFI = 8'h63,

    // スーパバイザメモリ管理命令(特権命令)
    SFENCE_VMA = 8'h64,

    // デコーダで不正な命令を検知した時用.
    ILLEGAL_INSTR = 8'h65
  } opcode_t;


  // 特権モード.
  typedef enum logic [1:0] {
    U_MODE = 2'b00,
    S_MODE = 2'b01,
    M_MODE = 2'b11
  } privilege_level_e;

  // ロード命令かストア命令か
  typedef enum logic {
    LOAD,
    STORE
  } ldst_type_e;

  typedef enum logic [1:0] {
    BYTE,
    HALF_WORD,
    WORD,
    DOUBLE_WORD
  } data_size_t;

  //-------------------------------------
  // 流されるデータの形式
  //-------------------------------------

  // Decoder ~ Renamer で仕様するuop
  typedef struct packed {
    logic valid;
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] vaddr;
    logic [PADDR_WIDTH-1:0] paddr;  // pmpの確認用.
    logic rs1_exist;  // rs1が存在するか.リネーミングするかを判別するのに使う.
    logic rs2_exist;
    logic rd_exist;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rd;
    logic [XLEN-1:0] imm;
    logic pred_taken;
    logic btb_hit;
    logic [VADDR_WIDTH-1:0] btb_addr;
    logic is_page_fault;
    logic is_access_fault;
    logic [31:0] raw_op;
  } decoded_op_t;

  // Renamer ~ レジスタファイル で仕様するuop
  typedef struct packed {
    logic valid;
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] op_addr;
    // rs1,rs2が
    logic rs1_exist;
    logic rs2_exist;
    logic rd_exist;
    // 現在のrs1,rs2の値が物理レジスタで有効か.
    // OoO実行だと順序が崩れるので,rs1,rs2が有効になったあとに実行しないと駄目.
    // DistoributorがReservationStationにいれるときにBusyTableを確認して,その中に入っている
    // つまり他の命令のrdとして使用中なら0(invalid)にする.
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] imm;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
  } vuop_front_t;

  // レジスタファイル以降のuop
  // vuop_front_tにレジスタの内容(XLEN bit)が入ってる.
  typedef struct packed {
    logic valid;
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] op_addr;
    // rs1,rs2が
    logic rs1_exist;
    logic rs2_exist;
    logic rd_exist;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs1;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rs2;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] rs1_val;  // レジスタから取り出したrs1の値.
    logic [XLEN-1:0] rs2_val;
    logic [XLEN-1:0] imm;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    logic actual_taken;  // 実際に飛ぶときに1
    logic [VADDR_WIDTH-1:0] actual_taken_addr;  // 実際に飛ぶときの飛び先.
  } vuop_back_t;

  typedef struct packed {
    logic valid;
    opcode_t opcode;
    logic [VADDR_WIDTH-1:0] op_addr;
    logic rd_exist;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
    logic [XLEN-1:0] rd_val;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    logic actual_taken;  // 実際に飛ぶときに1
    logic [VADDR_WIDTH-1:0] actual_taken_addr;  // 実際に飛ぶときの飛び先.
    // lrが読み込んだデータのあるpadrが必要.(これらにはdw_alignedのものを用いる)
    // あと,misalignedもalに入れる時に判別する.(これが必要なので,dwalignedで無いpaddrが必要.)
    // あと,pmpの判断も行う.
    // あと,pagefault時のアドレス格納にも使う.
    logic [PADDR_WIDTH-1:0] ldst_target_addr;
    // ldst用.
    logic is_page_fault;
    logic is_access_fault;
  } vuop_result_t;


  // btb,predictor => ifq
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] first_instr_addr;
    int unsigned first_instr_id;
    logic [NUM_OF_FETCH-1:0] pred_taken;
    logic [NUM_OF_FETCH-1:0] btb_hit;
    logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] btb_addr;
  } pred_btb_result_t;

  // ifq => Decoder の引数.
  typedef struct packed {
    logic                   valid;
    logic [VADDR_WIDTH-1:0] vaddr;
    logic [PADDR_WIDTH-1:0] paddr;
    logic [31:0]            data;
    logic                   pred_taken;       // 予測子でtakenなら1
    logic                   btb_hit;          // btbでヒットしたら1
    logic                   is_page_fault;
    logic                   is_access_fault;
    logic [VADDR_WIDTH-1:0] btb_addr;
  } ifq_decoder_t;

  // --------------------------------------------
  // フィードバック
  // --------------------------------------------

  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] vaddr;
    int unsigned first_instr_id;
  } pc_t;

  // flushするときに,どこからfetchし直すかをstage1に伝えたり,
  // st1=> st2でpcの受け渡しをするときに使ったりする.
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] addr;
  } addr_with_valid_t;

  // Renamer => BTB
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] op_addr;
    logic [VADDR_WIDTH-1:0] dest_addr;  // 飛ぶ先のアドレス
  } misprediction_feedback_to_btb_t;

  // Renamer => BTB
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] op_addr;
    logic taken;  //飛んだか.
  } is_taken_feedback_to_pred_t;


  // 有効になったrdを返すフィードバック.
  // 各種のキューとBusyTableに利用可能になったレジスタを伝えるのに使用する.
  typedef struct packed {
    logic                              valid;
    logic [$clog2(NUM_OF_PHYREGS)-1:0] rd;
  } feedback_rd_t;


  // active listの新しいエントリをLSUに通知する
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] op_addr;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
    opcode_t opcode;
    // fence用
    logic si;
    logic so;
    logic sr;
    logic sw;
  } new_ldst_to_al_t;

  // active listのコミットをLSUに通知する.
  typedef struct packed {
    logic valid;
    logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
  } committed_ldst_from_al_t;


  typedef struct packed {
    logic valid;
    logic [AL_IDX_WIDTH-1:0] al_idx;
  } executable_csr_t;

  // Renamerから,LSUで発見されたint issue queueの投機失敗を通知し,ld_wait_tableを更新する.
  typedef struct packed {
    logic valid;
    logic [VADDR_WIDTH-1:0] vaddr;
  } update_lwt_t;


  // ---------------------------
  // DCacheへの入力
  // ---------------------------
  // Stage7 => Dcache でdcacheにデータをリクエストする形式.
  // typedef struct packed {
  //   logic valid;
  //   opcode_t opcode;
  //   logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
  //   logic [PADDR_WIDTH-1:0] target_paddr;  // ロード対象,ストア対象のアドレス
  //   logic [XLEN-1:0] data_w;
  //   logic [15:0] asid;  // dcacheに入れた直後にasidが更新される可能性があるので,ここで渡しておくべき.
  // } dcache_in_t;

  // // dcacheから戻ってくるデータの形式.
  // typedef struct packed {
  //   logic valid;
  //   logic [$clog2(ACTIVELIST_SIZE)-1:0] al_idx;
  //   logic [XLEN-1:0] rdata;
  // } dcache_out_t;


  // ICacheへの入力.


  // PMA
  typedef enum logic [1:0] {
    PMA_MMIO,
    PMA_MEMORY,
    PMA_NONE
  } pma_type_e;

  // mmioで使用するdeviceの名前
  typedef enum logic [2:0] {
    DN_BOOTLOADER,
    DN_CLINT,
    DN_PLIC,
    DN_UART,
    DN_DRAM,
    DN_NONE
  } device_name_e;

  // ----------------------------------------------------------------------
  // tlbの入出力
  // ----------------------------------------------------------------------
  typedef struct packed {
    logic valid;
    int unsigned id;
    logic id_sub;
    int unsigned generation;
    csr_reg_u satp;
    logic [VADDR_WIDTH-1:0] vaddr;
  } tlb_req_t;

  typedef struct packed {
    logic valid;
    int unsigned id;
    logic id_sub;
    int unsigned generation;
    logic [PADDR_WIDTH-1:0] paddr;
    logic [VADDR_WIDTH-1:0] vaddr;
    // logic [15:0] asid;
    csr_reg_u satp;
    pma_type_e pma_type;
    logic is_page_fault;
    // pteのAccessedビットとDirtyビット.
    logic pte_a;
    logic pte_d;
  } tlb_res_t;


  // csrへの書き込み
  typedef struct packed {
    logic en;
    csr_reg_u data;
  } csr_w_t;

  typedef struct packed {
    logic en;
    privilege_level_e val;
  } priv_w_t;


  // メインメモリ
  typedef struct packed {
    logic valid;
    int unsigned id;

    // MIGとのやり取りの単位である128bitごとにalignされた物理アドレス.
    logic [PADDR_WIDTH-1:0] paddr_mig_aligned;

    logic is_write;
    logic [127:0] data;
  } mm_req_t;

  // resで戻ってくるのはreadのreqを出した場合のみ.
  typedef struct packed {
    logic valid;
    int unsigned id;

    logic [PADDR_WIDTH-1:0] paddr_mig_aligned;

    logic [127:0] data;
  } mm_res_t;

  // ------------------------------------------
  // mmioデバイスとの接続
  // ------------------------------------------
  typedef struct packed {
    logic valid;
    int unsigned id;
    logic [PADDR_WIDTH-1:0] paddr;
    logic is_write;
    logic [XLEN-1:0] data;
  } device_req_t;

  typedef struct packed {
    logic valid;
    int unsigned id;
    logic [XLEN-1:0] data;
  } device_res_t;

  // -------------------------------------------
  // bootloaderとの接続
  // -------------------------------------------
  typedef struct packed {
    logic valid;
    int unsigned id;
    logic [PADDR_WIDTH-1:0] paddr;
  } bootloader_req_t;

  typedef struct packed {
    logic valid;
    int unsigned id;
    logic [32*NUM_OF_FETCH-1:0] data;
  } bootloader_res_t;


  // レジスタのabi名
  typedef enum logic [4:0] {
    zero,
    ra,
    sp,
    gp,
    tp,
    t0,
    t1,
    t2,
    s0,
    s1,
    a0,
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7,
    s8,
    s9,
    s10,
    s11,
    t3,
    t4,
    t5,
    t6
  } abi_name_e;

endpackage


`endif
