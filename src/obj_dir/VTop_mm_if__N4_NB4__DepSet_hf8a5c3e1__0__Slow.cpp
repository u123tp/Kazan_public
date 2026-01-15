// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_mm_if__N4_NB4.h"

VL_ATTR_COLD void VTop_mm_if__N4_NB4___ctor_var_reset(VTop_mm_if__N4_NB4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N4_NB4___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_ZERO_RESET_W(218, vlSelf->req[__Vi0]);
    }
    VL_ZERO_RESET_W(217, vlSelf->__VdlyVal__res__v0);
    vlSelf->__VdlySet__res__v0 = 0;
    VL_ZERO_RESET_W(217, vlSelf->__VdlyVal__res__v1);
    vlSelf->__VdlySet__res__v1 = 0;
    VL_ZERO_RESET_W(217, vlSelf->__VdlyVal__res__v2);
    VL_ZERO_RESET_W(217, vlSelf->__VdlyVal__res__v3);
}
