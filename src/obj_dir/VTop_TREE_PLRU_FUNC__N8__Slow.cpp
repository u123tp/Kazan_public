// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_TREE_PLRU_FUNC__N8.h"
#include "VTop__Syms.h"

void VTop_TREE_PLRU_FUNC__N8___ctor_var_reset(VTop_TREE_PLRU_FUNC__N8* vlSelf);

VTop_TREE_PLRU_FUNC__N8::VTop_TREE_PLRU_FUNC__N8(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_TREE_PLRU_FUNC__N8___ctor_var_reset(this);
}

void VTop_TREE_PLRU_FUNC__N8::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_TREE_PLRU_FUNC__N8::~VTop_TREE_PLRU_FUNC__N8() {
}
