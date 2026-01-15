// PLIC (Platform Level Interrupt Controller)
// 本来はtimeは時間依存にするべきなのだろうが、とりあえずサイクルごとにカウントアップにする.


`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"
`include "MemoryLayout.svh"

module PLIC
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
  import MemoryLayout::*;
(
    input logic clock,
    input logic reset,

    // lsuから出されるmmioのld/st
    input  device_req_t req_in,
    output device_res_t res_out,

    // csrとの接続.
    csr_plic_if.plic csr_port
);

  // uart
  device_req_t req_to_uart;
  device_res_t res_from_uart;
  logic irq_from_uart;
  uart_device ud (
      .clock(clock),
      .reset(reset),
      .req_in(req_to_uart),
      .res_out(res_from_uart),
      .irq(irq_from_uart)
  );

  // --------------------------------------------------------------------------
  // plic mmio
  // ---------------------------------------------------------------------------
  // plicはxv6ではuart(irq=10)とvirtio(irq=1)しか使用しないので,0~15までを保持すれば十分.
  // PLIC領域の相対アドレスで [0x0,0x1000) に4byte単位でpriorityを保存
  logic [15:0][31:0] plic_priority;
  // [0x1000,0x1080) に1bit単位でpendingを保持
  logic [15:0] plic_pending;

  // context0はhart0のM_MODE, context1はhart0のS_MODE, context2はhart1のM_MODE...みたいな感じで続くが,
  // xv6ではS_MODEの割り込みしか使用せず,Kazanではhart0のみが実装されているので,context1のみを実装.
  // 各割り込みが有効か.
  // [0x2080,0x2100)
  logic [15:0] plic_senable;
  // 各割り込みの受け付ける閾値
  // [0x0020_1000,0x0020_1004)
  logic [31:0] plic_spriority;
  // [0x0020_1004,0x0020_1008)
  // logic [31:0] plic_claim;

  logic [15:0][31:0] plic_priority_next;
  logic [15:0] plic_pending_next;
  logic [15:0] plic_senable_next;
  logic [31:0] plic_spriority_next;
  // logic [31:0] plic_claim_next;

  logic [PADDR_WIDTH-1:0] paddr_base = PADDR_WIDTH'(32'h0c00_0000);

  //
  device_res_t res_out_next;

  logic [15:0] in_service;
  logic [15:0] in_service_next;



  // req_inのアドレスに基づいて,どこへの命令かを判別する
  always_comb begin

    logic interrupt_exist = 0;
    logic [31:0] highest_priority = 0;
    logic [3:0] highest_priority_idx = 0;
    // 初期化
    req_to_uart = '{default: 0};
    res_out_next = '{default: 0};

    plic_priority_next = plic_priority;
    plic_pending_next = plic_pending;
    plic_senable_next = plic_senable;
    plic_spriority_next = plic_spriority;
    // plic_claim_next = plic_claim;
    in_service_next = in_service;


    // deviceのirqでplic_pendingを制御する.
    // in_service中はplic_completeは0になって,in_serviceを0にした時,つまりcompleteをosが出した
    // ときにまだirqが来ていれば,plic_pendingは再び1になる.
    if (irq_from_uart && !in_service[10]) begin
      // $display("[LOG][PLIC.sv] irq_from_uart detected");
      plic_pending_next[10] = 1;
    end

    // 
    if (req_in.valid) begin
      case (get_device_name(
          req_in.paddr
      ))
        DN_PLIC: begin
          // xv6ではplic mmioへのアクセスは32bit単位で行われるため,それを前提で組む.

          if(req_in.paddr >= paddr_base && req_in.paddr <paddr_base+PADDR_WIDTH'(unsigned'(32'h1000)))begin
            // plic_priority
            if (req_in.is_write) begin
              plic_priority_next[req_in.paddr[5:2]] = req_in.data[31:0];
            end else begin
              res_out_next = '{
                  valid: 1,
                  id: req_in.id,
                  data: {32'b0, plic_priority_next[req_in.paddr[5:2]]}
              };

            end

          end else if(req_in.paddr >= paddr_base+PADDR_WIDTH'(unsigned'(32'h1000)) && 
                      req_in.paddr <paddr_base+PADDR_WIDTH'(unsigned'(32'h1080)))begin
            //plic_pending
            if (req_in.is_write) begin
              // plic_pendingはデバイス側が立てて,claimの受信で落とすものなので,
              // 基本的に書き込みは無視でOK.
              // plic_pending_next = req_in.data[15:0];
            end else begin
              res_out_next = '{valid: 1, id: req_in.id, data: {48'b0, plic_pending_next}};
            end

          end  else if(req_in.paddr >= paddr_base+PADDR_WIDTH'(unsigned'(32'h2080)) && 
                      req_in.paddr <paddr_base+PADDR_WIDTH'(unsigned'(32'h2100)))begin
            //plic_senable
            if (req_in.is_write) begin
              plic_senable_next = req_in.data[15:0];
            end else begin
              res_out_next = '{valid: 1, id: req_in.id, data: {48'b0, plic_senable_next}};
            end

          end else if(req_in.paddr >= paddr_base+PADDR_WIDTH'(unsigned'(32'h0020_1000)) && 
                      req_in.paddr <paddr_base+PADDR_WIDTH'(unsigned'(32'h0020_1004)))begin
            // plic_spriority
            if (req_in.is_write) begin
              plic_spriority_next = req_in.data[31:0];
            end else begin
              res_out_next = '{valid: 1, id: req_in.id, data: {32'b0, plic_spriority_next}};
            end

          end else if(req_in.paddr >= paddr_base+PADDR_WIDTH'(unsigned'(32'h0020_1004)) && 
                      req_in.paddr <paddr_base+PADDR_WIDTH'(unsigned'(32'h0020_1008)))begin
            // plic_claim
            if (req_in.is_write) begin
              // cpu => device 方向の場合, complete
              in_service_next[req_in.data[3:0]] = 0;
              // $display("[LOG][PLIC.sv] in_service_next[%0d] off", req_in.data[3:0]);
            end else begin
              // device => cpu 方向. claim
              // 立ってるビットがなくてもresを返す必要がある.その際のdataは0.
              for (int unsigned i = 1; i < 16; i++) begin
                if(plic_pending_next[i] && !in_service_next[i]&&
                    plic_senable_next[i] && plic_priority_next[i] > plic_spriority_next &&
                    highest_priority < plic_priority_next[i])begin
                  interrupt_exist = 1;
                  highest_priority = plic_priority_next[i];
                  highest_priority_idx = 4'(i);
                end
              end

              if (interrupt_exist) begin
                plic_pending_next[highest_priority_idx] = 0;
                in_service_next[highest_priority_idx] = 1;
                res_out_next = '{
                    valid: 1,
                    id: req_in.id,
                    data: 64'(unsigned'(highest_priority_idx))
                };
                // $display("[LOG][PLIC.sv] in_service_next[%0d] on", highest_priority_idx);
              end else begin
                res_out_next = '{valid: 1, id: req_in.id, data: 0};
              end

            end
          end

        end

        DN_UART: req_to_uart = req_in;

        default: begin
          // bootloader,dram,clint他に対する書き込みは無視.
          // なんかxv6はclintのmmioレジスタを使用していないのか？
          // タイマ割り込み用のタイマはsstc拡張だからcsrから操作するし.
        end
      endcase

    end



    // 現在の設計では,lsuから同時に二つ以上のリクエストがplicに送られることは無いので,
    // res_out_nextをここで上書きしてしまう恐れは無い.
    if (res_from_uart.valid) begin
      res_out_next = res_from_uart;
    end

    // irq => mip
    // このplicはcontext1,つまりs_modeでのみ外部割り込みを受け付けるので,seipを1に.
    csr_port.mip_seip = 0;
    for (int unsigned i = 1; i < 16; i++) begin
      if (plic_pending_next[i] && !in_service_next[i] &&
      plic_senable_next[i] &&
      (plic_priority_next[i] > plic_spriority_next)) begin
        // $display("[LOG][PLIC.sv] seip is on i:%d", i);
        csr_port.mip_seip = 1;
      end
    end

    csr_port.mip_meip = 0;


  end


  // FOR DEBUG
  // logic csr_port_mip_seip_prev;
  // logic irq_from_uart_prev;
  // always_ff @(posedge clock, posedge reset) begin
  // if (plic_pending_next[10] && !plic_pending[10]) begin
  //   $display("[LOG][PLIC.sv] plic_pending[10] up");
  //   $display(
  //       "[LOG][PLIC.sv] inservice[10]:%b, plic_senable[10]:%b, plic_priority[10]:%016h, plic_spriority:%016h",
  //       in_service[10], plic_senable[10], plic_priority[10], plic_spriority);
  // end
  // if (!plic_pending_next[10] && plic_pending[10]) begin
  //   $display("[LOG][PLIC.sv] plic_pending[10] down");
  //   $display(
  //       "[LOG][PLIC.sv] inservice[10]:%b, plic_senable[10]:%b, plic_priority[10]:%016h, plic_spriority:%016h",
  //       in_service[10], plic_senable[10], plic_priority[10], plic_spriority);
  // end


  // if (csr_port.mip_seip && !csr_port_mip_seip_prev) begin
  //   $display("[LOG][PLIC.sv] csr_port.mie_seip up");
  // end
  // if (!csr_port.mip_seip && csr_port_mip_seip_prev) begin
  //   $display("[LOG][PLIC.sv] csr_port.mie_seip down");
  // end


  // if (irq_from_uart && !irq_from_uart_prev) begin
  //   $display("[LOG][PLIC.sv] irq_from_uart up");
  //   $display(
  //       "[LOG][PLIC.sv] inservice[10]:%b, plic_senable[10]:%b, plic_priority[10]:%016h, plic_spriority:%016h",
  //       in_service[10], plic_senable[10], plic_priority[10], plic_spriority);
  // end
  // if (!irq_from_uart && irq_from_uart_prev) begin
  //   $display("[LOG][PLIC.sv] irq_from_uart down");
  //   $display(
  //       "[LOG][PLIC.sv] inservice[10]:%b, plic_senable[10]:%b, plic_priority[10]:%016h, plic_spriority:%016h",
  //       in_service[10], plic_senable[10], plic_priority[10], plic_spriority);
  // end

  //   csr_port_mip_seip_prev <= csr_port.mip_seip;
  //   irq_from_uart_prev <= irq_from_uart;
  // end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      res_out <= '{default: 0};

      // plic mmioレジスタ
      plic_priority <= 0;
      plic_pending <= 0;
      plic_senable <= 0;
      plic_spriority <= 0;
      // plic_claim <= 0;

      //
      in_service <= 0;
    end else begin
      res_out <= res_out_next;

      // plic mmioレジスタ
      plic_priority <= plic_priority_next;
      plic_pending <= plic_pending_next;
      plic_senable <= plic_senable_next;
      plic_spriority <= plic_spriority_next;
      // plic_claim <= plic_claim_next;

      //
      in_service <= in_service_next;
    end
  end

endmodule
