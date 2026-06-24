// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_divider_top.h for the primary calling header

#include "Vsim_divider_top__pch.h"
#include "Vsim_divider_top__Syms.h"
#include "Vsim_divider_top___024root.h"

void Vsim_divider_top___024root___ctor_var_reset(Vsim_divider_top___024root* vlSelf);

Vsim_divider_top___024root::Vsim_divider_top___024root(Vsim_divider_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __Vm_mtaskstate_39(6U)
    , __Vm_mtaskstate_42(1U)
    , __Vm_mtaskstate_final__nba(2U)
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsim_divider_top___024root___ctor_var_reset(this);
}

void Vsim_divider_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsim_divider_top___024root::~Vsim_divider_top___024root() {
}
