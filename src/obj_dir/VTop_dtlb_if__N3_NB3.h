// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_DTLB_IF__N3_NB3_H_
#define VERILATED_VTOP_DTLB_IF__N3_NB3_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_dtlb_if__N3_NB3 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VlUnpacked<VlWide<8>/*229:0*/, 3> res;
    VlUnpacked<VlWide<6>/*168:0*/, 3> req;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_dtlb_if__N3_NB3(VTop__Syms* symsp, const char* v__name);
    ~VTop_dtlb_if__N3_NB3();
    VL_UNCOPYABLE(VTop_dtlb_if__N3_NB3);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_dtlb_if__N3_NB3* obj);

#endif  // guard
