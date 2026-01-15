// CLINT (Core Local Interrupt)

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"

module CLINT
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
(
    input logic clock,
    input logic reset,

    // clint mmioレジスタはxv6で使用しないので,reqも無い.

    // csr
    csr_clint_if.clint csr_port
);


  // csrのtimeレジスタの他に,clint mmio レジスタとしてmtimeを持っているが,
  // 実際にはcsrのtimeレジスタのエイリアスで構わない.
  logic [63:0] mtime;

  // mtimecmpは,csrレジスタとして実装されるstimecmpとはことなり,clintのレジスタとして実装される.
  // まあ,xv6ではmtimecmpは使用しない.
  logic [63:0] mtimecmp;


  always_comb begin
    // 初期化
    mtime = csr_port.time_rdata;

    // タイマ割り込み(M_MODE,S_MODE)
    csr_port.mip_mtip = mtime >= mtimecmp;
    if (csr_port.menvcfg_rdata.as_menvcfg.STCE &&  mtime >= csr_port.stimecmp_rdata.as_stimecmp.STIMECMP) begin
      // $display("[LOG] stime interrupt\n");
      csr_port.mip_stip = 1;
    end else begin
      csr_port.mip_stip = 0;
    end


    // タイマのカウントアップ
    if (!csr_port.mcountinhibit_rdata.as_mcountinhibit.TM) begin
      csr_port.time_w = '{en: 1, data: csr_port.time_rdata + 1};
    end else begin
      csr_port.time_w = '{en: 0, default: 0};
    end


  end


  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      mtimecmp <= 64'hffff_ffff_ffff_ffff;
    end else begin

    end
  end

endmodule
