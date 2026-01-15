// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_TREE_PLRU_FUNC__N8_H_
#define VERILATED_VTOP_TREE_PLRU_FUNC__N8_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_TREE_PLRU_FUNC__N8 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vlvbound_haa10253c__0;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_TREE_PLRU_FUNC__N8(VTop__Syms* symsp, const char* v__name);
    ~VTop_TREE_PLRU_FUNC__N8();
    VL_UNCOPYABLE(VTop_TREE_PLRU_FUNC__N8);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_TREE_PLRU_FUNC__N8* obj);

#endif  // guard
