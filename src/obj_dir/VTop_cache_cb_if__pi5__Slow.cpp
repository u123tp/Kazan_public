// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop_cache_cb_if__pi5.h"

void VTop_cache_cb_if__pi5___ctor_var_reset(VTop_cache_cb_if__pi5* vlSelf);

VTop_cache_cb_if__pi5::VTop_cache_cb_if__pi5(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_cache_cb_if__pi5___ctor_var_reset(this);
}

void VTop_cache_cb_if__pi5::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_cache_cb_if__pi5::~VTop_cache_cb_if__pi5() {
}
