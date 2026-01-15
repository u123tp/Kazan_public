// Branch Target Buffer
// 
// 39bitの[10:2]をインデックスとして,[20:11]をタグとして用いる.(下2桁はalignされる)
// あくまで予想なので絶対に当たる必要は無いので,タグを短くして節約する.
// 
// とりあえずダイレクトマップで行く.後でセットアソシエイティブに変えるかも.
//

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module BTB
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input clock,
    input reset,

    input logic [VADDR_WIDTH-1:0] first_instr_addr_cur,

    output logic [NUM_OF_FETCH-1:0] hit,
    output logic [NUM_OF_FETCH-1:0][VADDR_WIDTH-1:0] addr_out,

    input misprediction_feedback_to_btb_t feedback,

    input logic stall_in,
    input logic flush_in
);

  // ---------------------------------------------------
  // stall用
  // ---------------------------------------------------
  logic [VADDR_WIDTH-1:0] first_instr_addr;

  logic [VADDR_WIDTH-1:0] first_instr_addr_pending;
  logic is_pending;
  logic [VADDR_WIDTH-1:0] first_instr_addr_pending_next;
  logic is_pending_next;

  always_comb begin
    is_pending_next = is_pending;
    first_instr_addr_pending_next = first_instr_addr_pending;

    if (flush_in) begin
      first_instr_addr = 0;
    end else if (stall_in && !is_pending) begin
      // 新たにstallした場合.
      first_instr_addr_pending_next = first_instr_addr_cur;
      is_pending_next = 1;
      first_instr_addr = 0;
    end else if (stall_in) begin
      // 継続でstallした場合.
      first_instr_addr = 0;
    end else if (is_pending) begin
      // stall終了時.
      first_instr_addr = first_instr_addr_pending;
      is_pending_next  = 0;
    end else begin
      // 通常時.
      first_instr_addr = first_instr_addr_cur;
    end
  end

  // --------------------------------------------------
  // パラメータ
  // --------------------------------------------------
  localparam int unsigned NUM_OF_BTB_ENTRIES = 512;
  localparam int unsigned TAG_WIDTH = 10;

  // BTB
  localparam int unsigned BTB_IDX_WIDTH = $clog2(NUM_OF_BTB_ENTRIES);
  localparam int unsigned BTB_IDX_LSB = 2;
  localparam int unsigned BTB_IDX_MSB = BTB_IDX_LSB + BTB_IDX_WIDTH - 1;


  localparam int unsigned TAG_LSB = BTB_IDX_MSB + 1;
  localparam int unsigned TAG_MSB = TAG_LSB + TAG_WIDTH - 1;


  // BTB用パラメータ.
  localparam int unsigned NUM_OF_BTB_READ_PORT = NUM_OF_FETCH;
  // mispredictionの時しかbtbを更新しないため.
  localparam int unsigned NUM_OF_BTB_WRITE_PORT = 1;

  // --------------------------------------------------
  // btb本体
  // --------------------------------------------------
  typedef struct packed {
    logic valid;
    logic [TAG_WIDTH-1:0] tag;
    logic [VADDR_WIDTH-1:0] target_addr;
  } btb_t;
  btb_t btb_table[NUM_OF_BTB_ENTRIES];

  // 
  logic btb_r_en[NUM_OF_BTB_READ_PORT];
  logic [BTB_IDX_WIDTH-1:0] btb_r_ram_idx[NUM_OF_BTB_READ_PORT];
  logic [$bits(btb_t)-1:0] btb_r_bit_data[NUM_OF_BTB_READ_PORT];

  logic btb_w_en[NUM_OF_BTB_WRITE_PORT];
  logic [BTB_IDX_WIDTH-1:0] btb_w_ram_idx[NUM_OF_BTB_WRITE_PORT];
  logic [$bits(btb_t)-1:0] btb_w_bit_data[NUM_OF_BTB_WRITE_PORT];
  logic [$bits(btb_t)/8-1:0] btb_w_mask[NUM_OF_BTB_WRITE_PORT];

  // lvtramの入力系がbit列なので構造体を扱う場合は変換が必要.
  // ビット列のbtb_r_bit_dataに対して,こちらは構造体の形になっている.
  btb_t btb_r_data[NUM_OF_BTB_READ_PORT];
  btb_t btb_w_data[NUM_OF_BTB_WRITE_PORT];

  always_comb begin
    for (int unsigned port_idx = 0; port_idx < NUM_OF_BTB_READ_PORT; port_idx++) begin
      btb_r_data[port_idx] = btb_t'(btb_r_bit_data[port_idx]);
    end
    for (int unsigned port_idx = 0; port_idx < NUM_OF_BTB_WRITE_PORT; port_idx++) begin
      btb_w_bit_data[port_idx] = btb_w_data[port_idx];
    end

    for (int unsigned i = 0; i < NUM_OF_BTB_WRITE_PORT; i++) begin
      btb_w_mask[i] = {($bits(btb_t) / 8) {1'b1}};
    end

  end


  LVTRAM #(
      .RAM_WIDTH($bits(btb_t)),
      .RAM_DEPTH(NUM_OF_BTB_ENTRIES),
      .NUM_OF_READ_PORT(NUM_OF_BTB_READ_PORT),
      .NUM_OF_WRITE_PORT(NUM_OF_BTB_WRITE_PORT)
  ) btb (
      .clock(clock),
      .reset(reset),
      .r_en(btb_r_en),
      .r_ram_idx(btb_r_ram_idx),
      .r_data(btb_r_bit_data),
      .w_en(btb_w_en),
      .w_ram_idx(btb_w_ram_idx),
      .w_data(btb_w_bit_data),
      .w_mask(btb_w_mask)
  );


  // first_instr_addrを分解.
  logic [VADDR_WIDTH-1:0] addr_in[NUM_OF_FETCH];
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      addr_in[i] = first_instr_addr + i * 4;
    end
  end

  // タグ確認用.
  logic [VADDR_WIDTH-1:0] addr_in_prev[NUM_OF_FETCH];

  // addr_inの入力.
  always_comb begin
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      btb_r_en[i] = 1;
      btb_r_ram_idx[i] = addr_in[i][BTB_IDX_MSB:BTB_IDX_LSB];
    end
  end

  // 読み出した内容を出力用に加工.
  always_comb begin
    hit = '{default: 0};
    addr_out = '{default: 0};
    for (int unsigned i = 0; i < NUM_OF_FETCH; i++) begin
      if (btb_r_data[i].valid && addr_in_prev[i][TAG_MSB:TAG_LSB] == btb_r_data[i].tag) begin
        hit[i] = 1;
        addr_out[i] = btb_r_data[i].target_addr;
      end
    end
  end

  // 更新.
  always_comb begin
    btb_w_en = '{default: 0};
    btb_w_ram_idx = '{default: 0};
    btb_w_data = '{default: 0};
    if (feedback.valid) begin
      btb_w_en[0] = 1;
      btb_w_ram_idx[0] = feedback.op_addr[BTB_IDX_MSB:BTB_IDX_LSB];
      btb_w_data[0] = '{
          valid: 1,
          tag: feedback.op_addr[TAG_MSB:TAG_LSB],
          target_addr: feedback.dest_addr
      };
    end
  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // pending
      is_pending <= 0;
      first_instr_addr_pending <= 0;

      addr_in_prev <= '{default: 0};

    end else if (flush_in) begin
      // pending
      is_pending <= 0;
      first_instr_addr_pending <= 0;

      addr_in_prev <= '{default: 0};

    end else begin
      //pending
      is_pending <= is_pending_next;
      first_instr_addr_pending <= first_instr_addr_pending_next;

      addr_in_prev <= addr_in;
    end
  end


endmodule
