// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CSR_CSRU_IF_H_
#define VERILATED_VTOP_CSR_CSRU_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_csr_csru_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    SData/*12:0*/ read_req;
    VlWide<3>/*64:0*/ read_res;
    VlWide<3>/*76:0*/ write_req;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_csr_csru_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_csr_csru_if();
    VL_UNCOPYABLE(VTop_csr_csru_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_csr_csru_if* obj);

#endif  // guard
