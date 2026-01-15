// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_ITLB_IF__N4_NB4_H_
#define VERILATED_VTOP_ITLB_IF__N4_NB4_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_itlb_if__N4_NB4 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VlUnpacked<VlWide<8>/*229:0*/, 4> res;
    VlUnpacked<VlWide<6>/*168:0*/, 4> req;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_itlb_if__N4_NB4(VTop__Syms* symsp, const char* v__name);
    ~VTop_itlb_if__N4_NB4();
    VL_UNCOPYABLE(VTop_itlb_if__N4_NB4);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_itlb_if__N4_NB4* obj);

#endif  // guard
