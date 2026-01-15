// Renamerとcsrrfを接続する.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"


interface csr_renamer_if
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
();

  // renamerが読み込むcsr
  csr_reg_u mideleg_rdata;
  csr_reg_u mip_rdata;
  csr_reg_u mie_rdata;
  csr_reg_u medeleg_rdata;
  csr_reg_u mstatus_rdata;
  csr_reg_u mepc_rdata;
  csr_reg_u mtvec_rdata;
  csr_reg_u mcounteren_rdata;
  csr_reg_u mcountinhibit_rdata;
  csr_reg_u minstret_rdata;

  csr_reg_u sie_rdata;
  csr_reg_u sip_rdata;
  csr_reg_u sstatus_rdata;
  csr_reg_u sepc_rdata;
  csr_reg_u stvec_rdata;
  csr_reg_u scounteren_rdata;


  csr_reg_u pmpcfg_rdata[8];
  csr_reg_u pmpaddr_rdata[64];

  // for debug
  csr_reg_u stimecmp_rdata;

  // 書き込む必要があるcsrレジスタ
  csr_w_t medeleg_w;
  csr_w_t mstatus_w;
  csr_w_t mepc_w;
  csr_w_t mtval_w;
  csr_w_t mcause_w;

  csr_w_t sstatus_w;
  csr_w_t sepc_w;
  csr_w_t stval_w;
  csr_w_t scause_w;

  csr_w_t minstret_w;

  modport renamer(
      // CSR reads visible to the renamer
      input  mideleg_rdata, mip_rdata, mie_rdata,
      medeleg_rdata,
           mstatus_rdata,
           mepc_rdata,
           mtvec_rdata,
           mcounteren_rdata,
           mcountinhibit_rdata,
           minstret_rdata,
           sie_rdata,
           sip_rdata,
           sstatus_rdata,
           sepc_rdata,
           stvec_rdata,
           scounteren_rdata,
           pmpcfg_rdata, pmpaddr_rdata,stimecmp_rdata,

      // CSR writes driven by the renamer
      output medeleg_w, mstatus_w, mepc_w, mtval_w, mcause_w, sstatus_w, sepc_w, stval_w, scause_w,minstret_w
  );

  modport CSRRF(
      // CSR reads visible to the renamer
      output  mideleg_rdata, mip_rdata, mie_rdata,
      medeleg_rdata,
           mstatus_rdata,
           mepc_rdata,
           mtvec_rdata,
           mcounteren_rdata,
           mcountinhibit_rdata,
           minstret_rdata,
           sie_rdata,
           sip_rdata,
           sstatus_rdata,
           sepc_rdata,
           stvec_rdata,
           scounteren_rdata,
           pmpcfg_rdata, pmpaddr_rdata,stimecmp_rdata,

      // CSR writes driven by the renamer
      input medeleg_w, mstatus_w, mepc_w, mtval_w, mcause_w, sstatus_w, sepc_w, stval_w, scause_w, minstret_w
  );


endinterface
