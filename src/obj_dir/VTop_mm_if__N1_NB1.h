// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_MM_IF__N1_NB1_H_
#define VERILATED_VTOP_MM_IF__N1_NB1_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_mm_if__N1_NB1 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VlUnpacked<VlWide<7>/*217:0*/, 1> req;
    CData/*0:0*/ __VdlySet__res__v0;
    CData/*0:0*/ __VdlySet__res__v1;
    CData/*0:0*/ __VdlySet__res__v2;
    VlWide<7>/*216:0*/ __VdlyVal__res__v1;
    VlUnpacked<VlWide<7>/*216:0*/, 1> res;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_mm_if__N1_NB1(VTop__Syms* symsp, const char* v__name);
    ~VTop_mm_if__N1_NB1();
    VL_UNCOPYABLE(VTop_mm_if__N1_NB1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_mm_if__N1_NB1* obj);

#endif  // guard
