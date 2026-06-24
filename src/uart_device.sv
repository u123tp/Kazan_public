`timescale 1ns / 1ps
// uartのデバイス
// 本来のキーボードとかディスプレイの変わりに,
// とりあえずverilatorを走らせたときのstdinとstdoutを用いる.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"

module uart_device
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
(
    input logic clock,
    input logic reset,

    // mmioのld/st処理
    input  device_req_t req_in,
    output device_res_t res_out,

`ifdef VIVADO_COMPILE

    output logic data_print_en,
    output logic [7:0] data_print,

    input logic char_from_uart_valid,
    input logic [7:0] char_from_uart,

    input logic stall_uart_print,
`endif

    output logic irq,

    // 実機ではuartの周波数はcpuのサイクルより小さいので,tx用のfifoが満タンになる可能性がある.
    // よって,fifoが満タンなら,renamerでst命令のコミットを抑制する必要がある.
    output logic tx_fifo_full
);


  // ------------------------------
  // パラメータ
  // ------------------------------
  localparam int unsigned THR_FIFO_SIZE = 16;
  localparam int unsigned THR_FIFO_IDX_WIDTH = $clog2(THR_FIFO_SIZE);

  localparam int unsigned RHR_FIFO_SIZE = 16;
  localparam int unsigned RHR_FIFO_IDX_WIDTH = $clog2(RHR_FIFO_SIZE);

  // このcpuがverilatorかvivadoのどちらでコンパイルされるか.
  // マクロ設定はverilatorの方はmakefileに,vivadoの方は
`ifdef VERILATOR_COMPILE
  import "DPI-C" function void print_char_verilator(input int ch);
  import "DPI-C" function int scan_char_verilator();
`endif


  // Interrupt Enable Register
  // 割り込みが有効かどうか(deviceが割り込みを行うか)を管理するレジスタ.
  typedef struct packed {
    logic [5:0] padding;
    logic tx_interrupt_en;
    logic rx_interrupt_en;
  } ier_t;
  ier_t IER;

  // FIFO Control Register
  typedef struct packed {
    logic [4:0] padding;
    logic [1:0] fifo_clear;
    logic fifo_enable;
  } fcr_t;
  fcr_t FCR;

  // Interrupt Status Register
  logic [7:0] ISR;
  // Line Control Register
  // データサイズやボーレートの初期値設定.
  // とりあえずは,データサイズ8bitに固定.
  typedef struct packed {
    logic devisor_latch_enable;
    logic [4:0] padding;
    logic [1:0] data_size;
  } lcr_t;
  lcr_t LCR;

  // Line Status Register
  // 送受信ができるかとか.
  typedef struct packed {
    logic [1:0] padding0;
    logic have_thr_fifo_room;
    logic [3:0] padding1;
    logic rhr_ready;
  } lsr_t;
  lsr_t LSR;

  // cpuから来たデータをためておくfifo.
  // 空の場合 wp == rp, 満タンの場合 wp+1 == rp
  logic [7:0] thr_fifo[THR_FIFO_SIZE];
  logic [THR_FIFO_IDX_WIDTH-1:0] thr_fifo_rp;
  logic [THR_FIFO_IDX_WIDTH-1:0] thr_fifo_wp;


  assign tx_fifo_full = thr_fifo_wp + THR_FIFO_IDX_WIDTH'(1) == thr_fifo_rp;


  // cpuが読み込むデータをためておくfifo
  logic [7:0] rhr_fifo[RHR_FIFO_SIZE];
  logic [RHR_FIFO_IDX_WIDTH-1:0] rhr_fifo_rp;
  logic [RHR_FIFO_IDX_WIDTH-1:0] rhr_fifo_wp;

  // thr_fifoがemptyの時に,isrへのアクセスがあるか,thr_fifoへの書き込みがあるまではirqを出す.
  logic accessed_to_isr;
  logic accessed_to_isr_next;

  // 毎サイクルscan_cahrを呼ぶと重いので数回に一回だけ呼ぶ. 
  int unsigned cycle_counter;

`ifdef VERILATOR_COMPILE
  int fp;
  initial begin
    fp = $fopen("./log/uart_device_log.txt", "w");
  end
`endif



  // 割り込み
  always_comb begin
    irq = 0;


    // TX側の割り込み.
    // CPU => device で,文字を出力する.
    // thr_fifoがemptyの時に,isrへのアクセスがあるか,thr_fifoへの書き込みがあるまではirqを出す.
    if (IER.tx_interrupt_en && thr_fifo_rp == thr_fifo_wp && !accessed_to_isr) begin
      irq = 1;
    end

    // RX側の割り込み.
    // device => CPU で文字を入力する.
    // rhr_fifoに読み込める状態のデータがある間は割り込みのclaimを出す.

    if (IER.rx_interrupt_en && rhr_fifo_rp != rhr_fifo_wp) begin
      // $display("[LOG][uart_device.sv] rhr_fifo is not empty");
      irq = 1;
      // if (counter_next == 0) begin
      //   $display("rhr_fifo_rp:%d, rhr_fifo_wp:%d, fifo[%d]:%d", rhr_fifo_rp, rhr_fifo_wp,
      //            rhr_fifo_rp, rhr_fifo[rhr_fifo_rp]);
      // end

    end else if (!IER.rx_interrupt_en && rhr_fifo_rp != rhr_fifo_wp) begin
      // $display("[LOG][uart_device.sv] rhr_fifo is not empty,but not enabled");
    end
  end

  // LSR
  always_comb begin
    LSR = 0;
    if (thr_fifo_wp + THR_FIFO_IDX_WIDTH'(1) != thr_fifo_rp) begin
      LSR.have_thr_fifo_room = 1;
    end else begin
      LSR.have_thr_fifo_room = 0;
    end

    if (rhr_fifo_wp != rhr_fifo_rp) begin
      LSR.rhr_ready = 1;
    end else begin
      LSR.rhr_ready = 0;
    end
  end


  // FOR DEBUG
  // always_ff @(posedge clock) begin
  //   if (req_in.valid) begin
  //     $fdisplay(fp, "[LOG][DEV] req_in valid=%0d id=%0d paddr=0x%0h is_write=%0d data=0x%0h",
  //               req_in.valid, req_in.id, req_in.paddr, req_in.is_write, req_in.data);
  //   end
  //   if (res_out.valid) begin
  //     $fdisplay(fp, "[LOG][DEV] res_out valid=%0d id=%0d data=0x%0h", res_out.valid, res_out.id,
  //               res_out.data);
  //   end
  // end


  always_ff @(posedge clock) begin
    if (reset) begin
      // 各種レジスタ.
      IER <= 0;
      FCR <= 0;
      ISR <= 0;
      LCR <= 0;

      // thr_fifo
      thr_fifo <= '{default: 0};
      thr_fifo_rp <= 0;
      thr_fifo_wp <= 0;

      // rhr_fifo
      rhr_fifo <= '{default: 0};
      rhr_fifo_rp <= 0;
      rhr_fifo_wp <= 0;

      // accessed_to_isr
      accessed_to_isr <= 0;

      // cycle_counter
      cycle_counter <= 0;

`ifdef VIVADO_COMPILE
      data_print_en <= 0;
      data_print <= 0;
`endif

    end else begin
      // thr_fifoの内容をprintする
      if (thr_fifo_rp != thr_fifo_wp
`ifdef VIVADO_COMPILE
          && !stall_uart_print
`endif
      ) begin
`ifdef VERILATOR_COMPILE
        // ここでverilatorでthrfifoの内容をプリントする.
        print_char_verilator(32'(unsigned'(thr_fifo[thr_fifo_rp])));
`endif
`ifdef VIVADO_COMPILE
        // vivadoでthr_fifoの内容をプリントする.
        data_print_en <= 1;
        data_print <= thr_fifo[thr_fifo_rp];
`endif
        // 初めてthr_fifoが空になった時にaccessed_isrが立っていたらリセット
        if (thr_fifo_rp + THR_FIFO_IDX_WIDTH'(1) == thr_fifo_wp) begin
          accessed_to_isr <= 0;
        end
        thr_fifo_rp <= thr_fifo_rp + THR_FIFO_IDX_WIDTH'(1);
      end else begin
`ifdef VIVADO_COMPILE
        data_print_en <= 0;
        data_print <= 0;
`endif
      end

      // rhr_fifoに空きがあればscanした内容をrhr_fifoに反映させる.
      // TODO: scanするのは,毎回何文字もやるのは負担が大きいので1024サイクルに一つにしておく.
      // ↑これやるとireclaimが実行サれない？
      begin
`ifdef VERILATOR_COMPILE
        // cの関数は重いので1000サイクルに1回.
        automatic int scanned_data = 0;
        if (rhr_fifo_wp + RHR_FIFO_IDX_WIDTH'(1) != rhr_fifo_rp && (cycle_counter % 1000 == 0)) begin
          scanned_data = scan_char_verilator();
          if (scanned_data != -1) begin
            rhr_fifo[rhr_fifo_wp] <= 8'(scanned_data);
            rhr_fifo_wp <= rhr_fifo_wp + RHR_FIFO_IDX_WIDTH'(1);
          end
        end
`endif

`ifdef VIVADO_COMPILE
        // vivadoの場合,毎サイクル確認する.
        if (char_from_uart_valid) begin
          rhr_fifo[rhr_fifo_wp] <= char_from_uart;
          rhr_fifo_wp <= rhr_fifo_wp + RHR_FIFO_IDX_WIDTH'(1);
        end
`endif

      end



      // 0x1000_0000がuart0の位置なので,それをベースに考える
      res_out <= '{default: 0};
      if (req_in.valid) begin
        if (req_in.is_write) begin
          // write命令の場合,res_outは不要.
          if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0000))) begin
            thr_fifo[thr_fifo_wp] <= 8'(req_in.data);
            thr_fifo_wp <= thr_fifo_wp + THR_FIFO_IDX_WIDTH'(1);
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0001))) begin
            IER <= 8'(req_in.data);
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0002))) begin
            FCR <= 8'(req_in.data);
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0003))) begin
            LCR <= 8'(req_in.data);
          end else begin
            $display("[ERROR] [uart_device.sv] invalid req");
          end

          // case (req_in.paddr)
          //   PADDR_WIDTH'(unsigned'(32'h1000_0000)): begin
          //     thr_fifo[thr_fifo_wp] <= 8'(req_in.data);
          //     thr_fifo_wp <= THR_FIFO_IDX_WIDTH'(thr_fifo_wp + 1);
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0001)): begin
          //     IER <= 8'(req_in.data);
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0002)): begin
          //     FCR <= 8'(req_in.data);
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0003)): begin
          //     LCR <= 8'(req_in.data);
          //   end
          //   default: $display("[ERROR] [uart_device.sv] invalid req");
          // endcase
        end else begin
          // read命令の場合,res_outを返す
          //res_out <= '{valid: 1, id: req_in.id, data: 0};
          res_out.valid <= 1;
          res_out.id <= req_in.id;
          res_out.data <= 0;
          if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0000))) begin
            res_out.data <= XLEN'(unsigned'(rhr_fifo[rhr_fifo_rp]));
            rhr_fifo_rp  <= rhr_fifo_rp + RHR_FIFO_IDX_WIDTH'(1);
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0001))) begin
            res_out.data <= XLEN'(unsigned'(IER));
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0002))) begin
            // isrの読み込みを行った場合,accessed_to_isrを立てる.
            res_out.data <= XLEN'(unsigned'(ISR));
            accessed_to_isr <= 1;
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0003))) begin
            res_out.data <= XLEN'(unsigned'(LCR));
          end else if (req_in.paddr == PADDR_WIDTH'(unsigned'(32'h1000_0005))) begin
            res_out.data <= XLEN'(unsigned'(LSR));
          end else begin
            $display("[ERROR] [uart_device.sv] invalid req");
          end

          // case (req_in.paddr)
          //   PADDR_WIDTH'(unsigned'(32'h1000_0000)): begin
          //     res_out.data <= XLEN'(unsigned'(rhr_fifo[rhr_fifo_rp]));
          //     rhr_fifo_rp  <= RHR_FIFO_IDX_WIDTH'(rhr_fifo_rp + 1);
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0001)): begin
          //     res_out.data <= XLEN'(unsigned'(IER));
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0002)): begin
          //     // isrの読み込みを行った場合,accessed_to_isrを立てる.
          //     res_out.data <= XLEN'(unsigned'(ISR));
          //     accessed_to_isr <= 1;
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0003)): begin
          //     res_out.data <= XLEN'(unsigned'(LCR));
          //   end
          //   PADDR_WIDTH'(unsigned'(32'h1000_0005)): begin
          //     res_out.data <= XLEN'(unsigned'(LSR));
          //   end
          //   default: $display("[ERROR] [uart_device.sv] invalid req");
          // endcase
        end
      end


      // cycle_counter 
      cycle_counter <= cycle_counter + 1;


    end

  end


endmodule
