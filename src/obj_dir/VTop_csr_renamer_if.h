// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CSR_RENAMER_IF_H_
#define VERILATED_VTOP_CSR_RENAMER_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_csr_renamer_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    QData/*63:0*/ mideleg_rdata;
    QData/*63:0*/ mip_rdata;
    QData/*63:0*/ mie_rdata;
    QData/*63:0*/ medeleg_rdata;
    QData/*63:0*/ mstatus_rdata;
    QData/*63:0*/ mepc_rdata;
    QData/*63:0*/ mtvec_rdata;
    QData/*63:0*/ mcounteren_rdata;
    QData/*63:0*/ mcountinhibit_rdata;
    QData/*63:0*/ minstret_rdata;
    QData/*63:0*/ sie_rdata;
    QData/*63:0*/ sip_rdata;
    QData/*63:0*/ sstatus_rdata;
    QData/*63:0*/ sepc_rdata;
    QData/*63:0*/ stvec_rdata;
    QData/*63:0*/ scounteren_rdata;
    VlWide<3>/*64:0*/ mstatus_w;
    VlWide<3>/*64:0*/ mepc_w;
    VlWide<3>/*64:0*/ mtval_w;
    VlWide<3>/*64:0*/ mcause_w;
    VlWide<3>/*64:0*/ sstatus_w;
    VlWide<3>/*64:0*/ sepc_w;
    VlWide<3>/*64:0*/ stval_w;
    VlWide<3>/*64:0*/ scause_w;
    VlUnpacked<QData/*63:0*/, 8> pmpcfg_rdata;
    VlUnpacked<QData/*63:0*/, 64> pmpaddr_rdata;
    VlWide<3>/*64:0*/ medeleg_w;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_csr_renamer_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_csr_renamer_if();
    VL_UNCOPYABLE(VTop_csr_renamer_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_csr_renamer_if* obj);

#endif  // guard
