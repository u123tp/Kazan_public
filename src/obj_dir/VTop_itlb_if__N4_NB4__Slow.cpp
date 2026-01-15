// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop_itlb_if__N4_NB4.h"

void VTop_itlb_if__N4_NB4___ctor_var_reset(VTop_itlb_if__N4_NB4* vlSelf);

VTop_itlb_if__N4_NB4::VTop_itlb_if__N4_NB4(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_itlb_if__N4_NB4___ctor_var_reset(this);
}

void VTop_itlb_if__N4_NB4::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_itlb_if__N4_NB4::~VTop_itlb_if__N4_NB4() {
}
