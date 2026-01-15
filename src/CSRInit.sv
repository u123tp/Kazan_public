
// 234個のCSRレジスタの値,及び読み書きの属性を初期化するためのレジスタ.


`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"


module CSRInit
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
(
    output csr_reg_u csr_regs_init[256]
);



  always_comb begin
    misa_t misa_init = '{MXL: 2'b10, A: 1'b1, M: 1'b1, default: 0};
    mstatus_t mstatus_init = '{UXL: 2'b10, SXL: 2'b10, default: 0};

    // counter
    mcounteren_t mcounteren_init = '{IR: 1, TM: 1, CY: 1, default: 0};
    scounteren_t scounteren_init = '{IR: 1, TM: 1, CY: 1, default: 0};
    mcountinhibit_t mcountinhibit_init = '{default: 0};

    // menvcfg
    // Smcdeleg拡張をつける.
    menvcfg_t menvcfg_init = '{CDE: 1, default: 0};

    // pmp
    // pmpの一番最初のエントリをtorにして,pmpaddr0の範囲をメインメモリ全体にする
    // こうすることで、起動時にpmpによるプロテクトを回避する.
    pmpcfg_t pmpcfg0_init = {{56{1'b0}}, 8'b0_00_01_111};
    pmpaddr_t pmpaddr0_init = (16 * 1024 * 1024) >> 2;

    // stimecmp
    // 設定し直さないかぎり割り込みが起こらないように最大値に.
    stimecmp_t stimecmp_init = 64'hffff_ffff_ffff_ffff;


    csr_regs_init = '{default: 0};
    csr_regs_init[internal_idx(MISA)] = misa_init;
    csr_regs_init[internal_idx(MSTATUS)] = mstatus_init;
    csr_regs_init[internal_idx(MCOUNTEREN)] = mcounteren_init;
    csr_regs_init[internal_idx(SCOUNTEREN)] = scounteren_init;
    csr_regs_init[internal_idx(MCOUNTINHIBIT)] = mcountinhibit_init;
    csr_regs_init[internal_idx(MENVCFG)] = menvcfg_init;
    csr_regs_init[internal_idx(PMPCFG0)] = pmpcfg0_init;
    csr_regs_init[internal_idx(PMPADDR0)] = pmpaddr0_init;
    csr_regs_init[internal_idx(STIMECMP)] = stimecmp_init;
  end

endmodule
