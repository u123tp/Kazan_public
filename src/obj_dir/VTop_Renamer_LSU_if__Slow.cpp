// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_Renamer_LSU_if.h"
#include "VTop__Syms.h"

void VTop_Renamer_LSU_if___ctor_var_reset(VTop_Renamer_LSU_if* vlSelf);

VTop_Renamer_LSU_if::VTop_Renamer_LSU_if(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_Renamer_LSU_if___ctor_var_reset(this);
}

void VTop_Renamer_LSU_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_Renamer_LSU_if::~VTop_Renamer_LSU_if() {
}
