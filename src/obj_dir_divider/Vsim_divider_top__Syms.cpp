// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsim_divider_top__pch.h"
#include "Vsim_divider_top.h"
#include "Vsim_divider_top___024root.h"

// FUNCTIONS
Vsim_divider_top__Syms::~Vsim_divider_top__Syms()
{
}

Vsim_divider_top__Syms::Vsim_divider_top__Syms(VerilatedContext* contextp, const char* namep, Vsim_divider_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_threadPoolp{static_cast<VlThreadPool*>(contextp->threadPoolp())}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
