// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_RENAMER_LSU_IF_H_
#define VERILATED_VTOP_RENAMER_LSU_IF_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_Renamer_LSU_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ld_speculative_feedback_valid;
    CData/*5:0*/ ld_speculative_feedback_al_idx;
    VlWide<3>/*72:0*/ sc_mmio_executable;
    VlUnpacked<QData/*57:0*/, 4> new_instr;
    VlUnpacked<CData/*6:0*/, 4> committed_instr;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_Renamer_LSU_if(VTop__Syms* symsp, const char* v__name);
    ~VTop_Renamer_LSU_if();
    VL_UNCOPYABLE(VTop_Renamer_LSU_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_Renamer_LSU_if* obj);

#endif  // guard
