// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSIM_DIVIDER_TOP__SYMS_H_
#define VERILATED_VSIM_DIVIDER_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsim_divider_top.h"

// INCLUDE MODULE CLASSES
#include "Vsim_divider_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsim_divider_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsim_divider_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MULTI-THREADING
    VlThreadPool* __Vm_threadPoolp;
    bool __Vm_even_cycle__ico = false;
    bool __Vm_even_cycle__act = false;
    bool __Vm_even_cycle__nba = false;

    // MODULE INSTANCE STATE
    Vsim_divider_top___024root     TOP;

    // CONSTRUCTORS
    Vsim_divider_top__Syms(VerilatedContext* contextp, const char* namep, Vsim_divider_top* modelp);
    ~Vsim_divider_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
