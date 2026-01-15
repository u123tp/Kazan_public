// csrのレジスタファイルとplicのやり取り.

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"

interface csr_plic_if
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
();


  // plicが書き込むcsr.
  logic mip_meip;
  logic mip_seip;

  modport plic(output mip_meip, mip_seip);
  modport csr(input mip_meip, mip_seip);


endinterface
