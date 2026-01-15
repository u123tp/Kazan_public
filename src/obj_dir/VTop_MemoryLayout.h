// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_MEMORYLAYOUT_H_
#define VERILATED_VTOP_MEMORYLAYOUT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_MemoryLayout final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VlUnpacked<VlWide<4>/*112:0*/, 5> pma;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_MemoryLayout(VTop__Syms* symsp, const char* v__name);
    ~VTop_MemoryLayout();
    VL_UNCOPYABLE(VTop_MemoryLayout);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
