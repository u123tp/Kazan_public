// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_dtlb_if__N3_NB3.h"

VL_ATTR_COLD void VTop_dtlb_if__N3_NB3___ctor_var_reset(VTop_dtlb_if__N3_NB3* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_dtlb_if__N3_NB3___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        VL_ZERO_RESET_W(169, vlSelf->req[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        VL_ZERO_RESET_W(230, vlSelf->res[__Vi0]);
    }
}
