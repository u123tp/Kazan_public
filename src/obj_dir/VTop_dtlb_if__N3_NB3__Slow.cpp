// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop_dtlb_if__N3_NB3.h"

void VTop_dtlb_if__N3_NB3___ctor_var_reset(VTop_dtlb_if__N3_NB3* vlSelf);

VTop_dtlb_if__N3_NB3::VTop_dtlb_if__N3_NB3(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_dtlb_if__N3_NB3___ctor_var_reset(this);
}

void VTop_dtlb_if__N3_NB3::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_dtlb_if__N3_NB3::~VTop_dtlb_if__N3_NB3() {
}
