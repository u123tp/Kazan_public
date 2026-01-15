// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CSRU_RENAMER_IF_H_
#define VERILATED_VTOP_CSRU_RENAMER_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_csru_renamer_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*6:0*/ executable_csr;
    VlUnpacked<CData/*6:0*/, 4> committed_instr;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_csru_renamer_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_csru_renamer_if();
    VL_UNCOPYABLE(VTop_csru_renamer_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_csru_renamer_if* obj);

#endif  // guard
