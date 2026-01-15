`include "HART_DEFS.svh"
`include "COMMON_PARAMS.svh"
`include "CSR_PROPS.svh"



module CSRRF
  import HART_DEFS::*;
  import COMMON_PARAMS::*;
  import CSR_PROPS::*;
(
    input logic clock,
    input logic reset,

    output csr_reg_u satp_out,

    // renamer
    csr_renamer_if.CSRRF renamer_port,

    // csrexe
    csr_csru_if.csrrf csru_port,

    // plic
    csr_plic_if.csr plic_port,

    // clint
    csr_clint_if.csr clint_port
);

  // 本体.
  csr_reg_u csr_regs[256];
  csr_reg_u csr_regs_init[256];

  logic [XLEN-1:0] old_csr_val;
  logic [XLEN-1:0] new_csr_val;
  logic [XLEN-1:0] new_masked_csr_val;

  logic cycle_inhibited;
  always_comb begin
    cycle_inhibited = csr_regs[internal_idx(MCOUNTINHIBIT)].as_mcountinhibit.CY;
  end


  CSRInit csrinit (.csr_regs_init(csr_regs_init));

  // csru_port.write_req
  always_comb begin
    // write_maskはnew_csr_valの内,書き込み可能な所だけ1になっている.
    // 0の部分にはold_csr_valを柄う.
    logic [XLEN-1:0] write_mask;
    old_csr_val = csr_regs[internal_idx(csru_port.write_req.csr_name)];
    new_csr_val = csru_port.write_req.data;
    write_mask = get_write_mask(csru_port.write_req.csr_name, csru_port.write_req.data);
    new_masked_csr_val = (new_csr_val & write_mask) | (old_csr_val & ~write_mask);
  end

  // csr_unit
  always_comb begin
    csru_port.read_res = '{default: 0};
    if (csru_port.read_req.valid) begin
      csru_port.read_res = '{
          valid: 1,
          data:
          get_read_mask
          (
            csru_port.read_req.csr_name
          ) &
          csr_regs[internal_idx(csru_port.read_req.csr_name)]
      };
    end
  end

  always_comb begin
    // satp
    satp_out = get_read_mask(SATP) & csr_regs[internal_idx(SATP)];

    // renamer
    renamer_port.mideleg_rdata = get_read_mask(MIDELEG) & csr_regs[internal_idx(MIDELEG)];
    renamer_port.mie_rdata = get_read_mask(MIE) & csr_regs[internal_idx(MIE)];
    renamer_port.mip_rdata = get_read_mask(MIP) & csr_regs[internal_idx(MIP)];
    renamer_port.medeleg_rdata = get_read_mask(MEDELEG) & csr_regs[internal_idx(MEDELEG)];
    renamer_port.mstatus_rdata = get_read_mask(MSTATUS) & csr_regs[internal_idx(MSTATUS)];
    renamer_port.mepc_rdata = get_read_mask(MEPC) & csr_regs[internal_idx(MEPC)];
    renamer_port.mtvec_rdata = get_read_mask(MTVEC) & csr_regs[internal_idx(MTVEC)];
    renamer_port.mcounteren_rdata = get_read_mask(MCOUNTEREN) & csr_regs[internal_idx(MCOUNTEREN)];
    renamer_port.mcountinhibit_rdata = get_read_mask(MCOUNTINHIBIT) &
        csr_regs[internal_idx(MCOUNTINHIBIT)];
    renamer_port.minstret_rdata = get_read_mask(MINSTRET) & csr_regs[internal_idx(MINSTRET)];

    renamer_port.sie_rdata = get_read_mask(SIE) & csr_regs[internal_idx(SIE)];
    renamer_port.sip_rdata = get_read_mask(SIP) & csr_regs[internal_idx(SIP)];
    renamer_port.sstatus_rdata = get_read_mask(SSTATUS) & csr_regs[internal_idx(SSTATUS)];
    renamer_port.sepc_rdata = get_read_mask(SEPC) & csr_regs[internal_idx(SEPC)];
    renamer_port.stvec_rdata = get_read_mask(STVEC) & csr_regs[internal_idx(STVEC)];
    renamer_port.scounteren_rdata = get_read_mask(SCOUNTEREN) & csr_regs[internal_idx(SCOUNTEREN)];
    renamer_port.stimecmp_rdata = get_read_mask(STIMECMP) & csr_regs[internal_idx(STIMECMP)];

    renamer_port.pmpcfg_rdata[0] = get_read_mask(PMPCFG0) & csr_regs[internal_idx(PMPCFG0)];
    renamer_port.pmpcfg_rdata[1] = get_read_mask(PMPCFG2) & csr_regs[internal_idx(PMPCFG2)];
    renamer_port.pmpcfg_rdata[2] = get_read_mask(PMPCFG4) & csr_regs[internal_idx(PMPCFG4)];
    renamer_port.pmpcfg_rdata[3] = get_read_mask(PMPCFG6) & csr_regs[internal_idx(PMPCFG6)];
    renamer_port.pmpcfg_rdata[4] = get_read_mask(PMPCFG8) & csr_regs[internal_idx(PMPCFG8)];
    renamer_port.pmpcfg_rdata[5] = get_read_mask(PMPCFG10) & csr_regs[internal_idx(PMPCFG10)];
    renamer_port.pmpcfg_rdata[6] = get_read_mask(PMPCFG12) & csr_regs[internal_idx(PMPCFG12)];
    renamer_port.pmpcfg_rdata[7] = get_read_mask(PMPCFG14) & csr_regs[internal_idx(PMPCFG14)];

    renamer_port.pmpaddr_rdata[0] = get_read_mask(PMPADDR0) & csr_regs[internal_idx(PMPADDR0)];
    renamer_port.pmpaddr_rdata[1] = get_read_mask(PMPADDR1) & csr_regs[internal_idx(PMPADDR1)];
    renamer_port.pmpaddr_rdata[2] = get_read_mask(PMPADDR2) & csr_regs[internal_idx(PMPADDR2)];
    renamer_port.pmpaddr_rdata[3] = get_read_mask(PMPADDR3) & csr_regs[internal_idx(PMPADDR3)];
    renamer_port.pmpaddr_rdata[4] = get_read_mask(PMPADDR4) & csr_regs[internal_idx(PMPADDR4)];
    renamer_port.pmpaddr_rdata[5] = get_read_mask(PMPADDR5) & csr_regs[internal_idx(PMPADDR5)];
    renamer_port.pmpaddr_rdata[6] = get_read_mask(PMPADDR6) & csr_regs[internal_idx(PMPADDR6)];
    renamer_port.pmpaddr_rdata[7] = get_read_mask(PMPADDR7) & csr_regs[internal_idx(PMPADDR7)];
    renamer_port.pmpaddr_rdata[8] = get_read_mask(PMPADDR8) & csr_regs[internal_idx(PMPADDR8)];
    renamer_port.pmpaddr_rdata[9] = get_read_mask(PMPADDR9) & csr_regs[internal_idx(PMPADDR9)];
    renamer_port.pmpaddr_rdata[10] = get_read_mask(PMPADDR10) & csr_regs[internal_idx(PMPADDR10)];
    renamer_port.pmpaddr_rdata[11] = get_read_mask(PMPADDR11) & csr_regs[internal_idx(PMPADDR11)];
    renamer_port.pmpaddr_rdata[12] = get_read_mask(PMPADDR12) & csr_regs[internal_idx(PMPADDR12)];
    renamer_port.pmpaddr_rdata[13] = get_read_mask(PMPADDR13) & csr_regs[internal_idx(PMPADDR13)];
    renamer_port.pmpaddr_rdata[14] = get_read_mask(PMPADDR14) & csr_regs[internal_idx(PMPADDR14)];
    renamer_port.pmpaddr_rdata[15] = get_read_mask(PMPADDR15) & csr_regs[internal_idx(PMPADDR15)];
    renamer_port.pmpaddr_rdata[16] = get_read_mask(PMPADDR16) & csr_regs[internal_idx(PMPADDR16)];
    renamer_port.pmpaddr_rdata[17] = get_read_mask(PMPADDR17) & csr_regs[internal_idx(PMPADDR17)];
    renamer_port.pmpaddr_rdata[18] = get_read_mask(PMPADDR18) & csr_regs[internal_idx(PMPADDR18)];
    renamer_port.pmpaddr_rdata[19] = get_read_mask(PMPADDR19) & csr_regs[internal_idx(PMPADDR19)];
    renamer_port.pmpaddr_rdata[20] = get_read_mask(PMPADDR20) & csr_regs[internal_idx(PMPADDR20)];
    renamer_port.pmpaddr_rdata[21] = get_read_mask(PMPADDR21) & csr_regs[internal_idx(PMPADDR21)];
    renamer_port.pmpaddr_rdata[22] = get_read_mask(PMPADDR22) & csr_regs[internal_idx(PMPADDR22)];
    renamer_port.pmpaddr_rdata[23] = get_read_mask(PMPADDR23) & csr_regs[internal_idx(PMPADDR23)];
    renamer_port.pmpaddr_rdata[24] = get_read_mask(PMPADDR24) & csr_regs[internal_idx(PMPADDR24)];
    renamer_port.pmpaddr_rdata[25] = get_read_mask(PMPADDR25) & csr_regs[internal_idx(PMPADDR25)];
    renamer_port.pmpaddr_rdata[26] = get_read_mask(PMPADDR26) & csr_regs[internal_idx(PMPADDR26)];
    renamer_port.pmpaddr_rdata[27] = get_read_mask(PMPADDR27) & csr_regs[internal_idx(PMPADDR27)];
    renamer_port.pmpaddr_rdata[28] = get_read_mask(PMPADDR28) & csr_regs[internal_idx(PMPADDR28)];
    renamer_port.pmpaddr_rdata[29] = get_read_mask(PMPADDR29) & csr_regs[internal_idx(PMPADDR29)];
    renamer_port.pmpaddr_rdata[30] = get_read_mask(PMPADDR30) & csr_regs[internal_idx(PMPADDR30)];
    renamer_port.pmpaddr_rdata[31] = get_read_mask(PMPADDR31) & csr_regs[internal_idx(PMPADDR31)];
    renamer_port.pmpaddr_rdata[32] = get_read_mask(PMPADDR32) & csr_regs[internal_idx(PMPADDR32)];
    renamer_port.pmpaddr_rdata[33] = get_read_mask(PMPADDR33) & csr_regs[internal_idx(PMPADDR33)];
    renamer_port.pmpaddr_rdata[34] = get_read_mask(PMPADDR34) & csr_regs[internal_idx(PMPADDR34)];
    renamer_port.pmpaddr_rdata[35] = get_read_mask(PMPADDR35) & csr_regs[internal_idx(PMPADDR35)];
    renamer_port.pmpaddr_rdata[36] = get_read_mask(PMPADDR36) & csr_regs[internal_idx(PMPADDR36)];
    renamer_port.pmpaddr_rdata[37] = get_read_mask(PMPADDR37) & csr_regs[internal_idx(PMPADDR37)];
    renamer_port.pmpaddr_rdata[38] = get_read_mask(PMPADDR38) & csr_regs[internal_idx(PMPADDR38)];
    renamer_port.pmpaddr_rdata[39] = get_read_mask(PMPADDR39) & csr_regs[internal_idx(PMPADDR39)];
    renamer_port.pmpaddr_rdata[40] = get_read_mask(PMPADDR40) & csr_regs[internal_idx(PMPADDR40)];
    renamer_port.pmpaddr_rdata[41] = get_read_mask(PMPADDR41) & csr_regs[internal_idx(PMPADDR41)];
    renamer_port.pmpaddr_rdata[42] = get_read_mask(PMPADDR42) & csr_regs[internal_idx(PMPADDR42)];
    renamer_port.pmpaddr_rdata[43] = get_read_mask(PMPADDR43) & csr_regs[internal_idx(PMPADDR43)];
    renamer_port.pmpaddr_rdata[44] = get_read_mask(PMPADDR44) & csr_regs[internal_idx(PMPADDR44)];
    renamer_port.pmpaddr_rdata[45] = get_read_mask(PMPADDR45) & csr_regs[internal_idx(PMPADDR45)];
    renamer_port.pmpaddr_rdata[46] = get_read_mask(PMPADDR46) & csr_regs[internal_idx(PMPADDR46)];
    renamer_port.pmpaddr_rdata[47] = get_read_mask(PMPADDR47) & csr_regs[internal_idx(PMPADDR47)];
    renamer_port.pmpaddr_rdata[48] = get_read_mask(PMPADDR48) & csr_regs[internal_idx(PMPADDR48)];
    renamer_port.pmpaddr_rdata[49] = get_read_mask(PMPADDR49) & csr_regs[internal_idx(PMPADDR49)];
    renamer_port.pmpaddr_rdata[50] = get_read_mask(PMPADDR50) & csr_regs[internal_idx(PMPADDR50)];
    renamer_port.pmpaddr_rdata[51] = get_read_mask(PMPADDR51) & csr_regs[internal_idx(PMPADDR51)];
    renamer_port.pmpaddr_rdata[52] = get_read_mask(PMPADDR52) & csr_regs[internal_idx(PMPADDR52)];
    renamer_port.pmpaddr_rdata[53] = get_read_mask(PMPADDR53) & csr_regs[internal_idx(PMPADDR53)];
    renamer_port.pmpaddr_rdata[54] = get_read_mask(PMPADDR54) & csr_regs[internal_idx(PMPADDR54)];
    renamer_port.pmpaddr_rdata[55] = get_read_mask(PMPADDR55) & csr_regs[internal_idx(PMPADDR55)];
    renamer_port.pmpaddr_rdata[56] = get_read_mask(PMPADDR56) & csr_regs[internal_idx(PMPADDR56)];
    renamer_port.pmpaddr_rdata[57] = get_read_mask(PMPADDR57) & csr_regs[internal_idx(PMPADDR57)];
    renamer_port.pmpaddr_rdata[58] = get_read_mask(PMPADDR58) & csr_regs[internal_idx(PMPADDR58)];
    renamer_port.pmpaddr_rdata[59] = get_read_mask(PMPADDR59) & csr_regs[internal_idx(PMPADDR59)];
    renamer_port.pmpaddr_rdata[60] = get_read_mask(PMPADDR60) & csr_regs[internal_idx(PMPADDR60)];
    renamer_port.pmpaddr_rdata[61] = get_read_mask(PMPADDR61) & csr_regs[internal_idx(PMPADDR61)];
    renamer_port.pmpaddr_rdata[62] = get_read_mask(PMPADDR62) & csr_regs[internal_idx(PMPADDR62)];
    renamer_port.pmpaddr_rdata[63] = get_read_mask(PMPADDR63) & csr_regs[internal_idx(PMPADDR63)];


    // PLIC

    // CLINT
    clint_port.time_rdata = get_read_mask(TIME) & csr_regs[internal_idx(TIME)];
    clint_port.mcountinhibit_rdata = get_read_mask(MCOUNTINHIBIT) &
        csr_regs[internal_idx(MCOUNTINHIBIT)];
    clint_port.stimecmp_rdata = get_read_mask(STIMECMP) & csr_regs[internal_idx(STIMECMP)];
    clint_port.menvcfg_rdata = get_read_mask(MENVCFG) & csr_regs[internal_idx(MENVCFG)];

  end

  always_ff @(posedge clock, posedge reset) begin
    if (reset) begin
      // 初期化.
      csr_regs <= csr_regs_init;
    end else begin
      // renamerからの書き込み.
      if (renamer_port.medeleg_w.en) begin
        csr_regs[internal_idx(MEDELEG)] <= renamer_port.medeleg_w.data;
      end
      if (renamer_port.mstatus_w.en) begin
        csr_regs[internal_idx(MSTATUS)] <= renamer_port.mstatus_w.data;
      end
      if (renamer_port.mepc_w.en) begin
        csr_regs[internal_idx(MEPC)] <= renamer_port.mepc_w.data;
      end
      if (renamer_port.mtval_w.en) begin
        csr_regs[internal_idx(MTVAL)] <= renamer_port.mtval_w.data;
      end
      if (renamer_port.mcause_w.en) begin
        csr_regs[internal_idx(MCAUSE)] <= renamer_port.mcause_w.data;
      end
      if (renamer_port.sstatus_w.en) begin
        csr_regs[internal_idx(SSTATUS)] <= renamer_port.sstatus_w.data;
      end
      if (renamer_port.sepc_w.en) begin
        csr_regs[internal_idx(SEPC)] <= renamer_port.sepc_w.data;
      end
      if (renamer_port.stval_w.en) begin
        csr_regs[internal_idx(STVAL)] <= renamer_port.stval_w.data;
      end
      if (renamer_port.scause_w.en) begin
        csr_regs[internal_idx(SCAUSE)] <= renamer_port.scause_w.data;
      end

      // clintからの書き込み
      if (clint_port.time_w.en) begin
        csr_regs[internal_idx(TIME)] <= clint_port.time_w.data;
      end
      csr_regs[internal_idx(MIP)].as_mip.STIP <= clint_port.mip_stip;
      csr_regs[internal_idx(MIP)].as_mip.MTIP <= clint_port.mip_mtip;

      // plicからの書き込み
      csr_regs[internal_idx(MIP)].as_mip.MEIP <= plic_port.mip_meip;
      csr_regs[internal_idx(MIP)].as_mip.SEIP <= plic_port.mip_seip;

      // csrunit からの書き込み.
      if (csru_port.write_req.valid) begin
        csr_regs[internal_idx(csru_port.write_req.csr_name)] <= new_masked_csr_val;
      end


      // cycleの更新.
      begin
        if (!cycle_inhibited) begin
          csr_regs[internal_idx(MCYCLE)] <= csr_regs[internal_idx(MCYCLE)] + 1;
        end
      end


    end
  end


  // -------------------
  // FOR DEBUG
  // -------------------
  csr_reg_u csr_regs_prev[256];
  always_ff @(posedge clock, posedge reset) begin
    csr_regs_prev <= csr_regs;
  end

  int fp;
  initial begin
    fp = $fopen("./log/csrrflog.txt");
  end
  always_ff @(posedge clock, posedge reset) begin
`ifdef CSRRFLOG_EN
    // if (csr_regs[internal_idx(MIP)]) begin
    //   $fdisplay(fp, "%b %b %b %b", csr_regs[internal_idx(MIE)][9], csr_regs[internal_idx(MIP)][9],csr_regs[internal_idx(SIE)][9], csr_regs[internal_idx(SIP)][9]);
    //   $fdisplay(fp, "%b", csr_regs[internal_idx(MIP)][10]);
    //   $fdisplay(fp, "%b", csr_regs[internal_idx(SIE)][10]);
    //   $fdisplay(fp, "%b", csr_regs[internal_idx(SIP)][10]);
    //   $fdisplay(fp, "");
    // end
    if (csr_regs[internal_idx(
            MIP
        )].as_mip.SEIP && !csr_regs_prev[internal_idx(
            MIP
        )].as_mip.SEIP) begin
      $display(
          "[LOG][CSRRF.sv] mip.seip up. MIE:%016b, SIE:%016b, MIDELEG:%016b, mstatus.mie is %b, mstatus.sie is %b",
          csr_regs[internal_idx(MIE)][15:0], csr_regs[internal_idx(SIE)][15:0],
          csr_regs[internal_idx(MIDELEG)][15:0], csr_regs[internal_idx(MSTATUS)].as_mstatus.MIE,
          csr_regs[internal_idx(MSTATUS)].as_mstatus.SIE);
    end
    if (!csr_regs[internal_idx(
            MIP
        )].as_mip.SEIP && csr_regs_prev[internal_idx(
            MIP
        )].as_mip.SEIP) begin
      $display(
          "[LOG][CSRRF.sv] mip.seip down. MIE:%016b, SIE:%016b, MIDELEG:%016b, mstatus.mie is %b, mstatus.sie is %b",
          csr_regs[internal_idx(MIE)][15:0], csr_regs[internal_idx(SIE)][15:0],
          csr_regs[internal_idx(MIDELEG)][15:0], csr_regs[internal_idx(MSTATUS)].as_mstatus.MIE,
          csr_regs[internal_idx(MSTATUS)].as_mstatus.SIE);
    end
`endif
  end

  logic [XLEN-1:0] mtvec_val;
  assign mtvec_val = csr_regs[internal_idx(MTVEC)];
  logic [XLEN-1:0] mstatus_val;
  assign mstatus_val = csr_regs[internal_idx(MSTATUS)];
  logic [XLEN-1:0] mscratch_val;
  assign mscratch_val = csr_regs[internal_idx(MSCRATCH)];



endmodule

