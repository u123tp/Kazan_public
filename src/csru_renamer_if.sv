

`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"


interface csru_renamer_if
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
();


  committed_ldst_from_al_t committed_instr[NUM_OF_GRADUATE];
  executable_csr_t executable_csr;

  modport renamer(output committed_instr, executable_csr);
  modport csru(input committed_instr, executable_csr);

endinterface
