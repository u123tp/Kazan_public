// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CSR_PLIC_IF_H_
#define VERILATED_VTOP_CSR_PLIC_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_csr_plic_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ mip_meip;
    CData/*0:0*/ mip_seip;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_csr_plic_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_csr_plic_if();
    VL_UNCOPYABLE(VTop_csr_plic_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_csr_plic_if* obj);

#endif  // guard
