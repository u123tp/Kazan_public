// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CSR_CLINT_IF_H_
#define VERILATED_VTOP_CSR_CLINT_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_csr_clint_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ mip_stip;
    CData/*0:0*/ mip_mtip;
    QData/*63:0*/ time_rdata;
    QData/*63:0*/ mcountinhibit_rdata;
    QData/*63:0*/ stimecmp_rdata;
    QData/*63:0*/ menvcfg_rdata;
    VlWide<3>/*64:0*/ time_w;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_csr_clint_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_csr_clint_if();
    VL_UNCOPYABLE(VTop_csr_clint_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_csr_clint_if* obj);

#endif  // guard
