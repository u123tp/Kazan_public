// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024unit.h"
VlUnpacked<std::string, 4> VTop___024unit::__Venumtab_enum_name153;
VlAssocArray<CData/*7:0*/, std::string> VTop___024unit::__Venumtab_enum_name151;

void VTop___024unit___ctor_var_reset(VTop___024unit* vlSelf);

VTop___024unit::VTop___024unit(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop___024unit___ctor_var_reset(this);
}

void VTop___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop___024unit::~VTop___024unit() {
}
