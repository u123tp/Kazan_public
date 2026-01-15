
`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"


interface csr_clint_if
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
();

  // clintが読み出すcsr
  csr_reg_u time_rdata;
  csr_reg_u mcountinhibit_rdata;
  csr_reg_u stimecmp_rdata;
  csr_reg_u menvcfg_rdata;

  // clintが書き込むcsr
  csr_w_t time_w;
  logic mip_stip;
  logic mip_mtip;

  modport csr(
      output time_rdata, mcountinhibit_rdata, stimecmp_rdata, menvcfg_rdata,
      input time_w, mip_stip, mip_mtip
  );
  modport clint(
      input time_rdata, mcountinhibit_rdata, stimecmp_rdata, menvcfg_rdata,
      output time_w, mip_stip, mip_mtip
  );

endinterface
