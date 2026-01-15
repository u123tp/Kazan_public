// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_csru_renamer_if.h"

VL_ATTR_COLD void VTop_csru_renamer_if___ctor_var_reset(VTop_csru_renamer_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_csru_renamer_if___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->committed_instr[__Vi0] = 0;
    }
    vlSelf->executable_csr = 0;
}
