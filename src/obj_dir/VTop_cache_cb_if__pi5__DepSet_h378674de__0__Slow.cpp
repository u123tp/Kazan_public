// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_cache_cb_if__pi5.h"

VL_ATTR_COLD void VTop_cache_cb_if__pi5___ctor_var_reset(VTop_cache_cb_if__pi5* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VTop_cache_cb_if__pi5___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(331, vlSelf->read_req[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        VL_ZERO_RESET_W(331, vlSelf->write_req[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        VL_ZERO_RESET_W(331, vlSelf->res_to_tmb[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(268, vlSelf->res_to_wbb[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        VL_ZERO_RESET_W(331, vlSelf->res_to_mshr[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_ZERO_RESET_W(268, vlSelf->res_out[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->mshr_new_state[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->mshr_processing_info[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(66, vlSelf->allocate_req);
    vlSelf->allocate_res = 0;
    vlSelf->invalidate_get_info_req = 0;
    vlSelf->invalidate_get_info_res = 0;
    vlSelf->invalidate_req = 0;
}
