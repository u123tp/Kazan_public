// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop_mm_if__N1_NB1.h"

void VTop_mm_if__N1_NB1___ctor_var_reset(VTop_mm_if__N1_NB1* vlSelf);

VTop_mm_if__N1_NB1::VTop_mm_if__N1_NB1(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_mm_if__N1_NB1___ctor_var_reset(this);
}

void VTop_mm_if__N1_NB1::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_mm_if__N1_NB1::~VTop_mm_if__N1_NB1() {
}
