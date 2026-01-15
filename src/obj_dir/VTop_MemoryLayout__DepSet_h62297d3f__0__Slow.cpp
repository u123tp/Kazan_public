// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_MemoryLayout.h"

VL_ATTR_COLD void VTop_MemoryLayout___eval_static__TOP__MemoryLayout(VTop_MemoryLayout* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VTop_MemoryLayout___eval_static__TOP__MemoryLayout\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pma[0U][0U] = 0x2000000U;
    vlSelfRef.pma[0U][1U] = 0U;
    vlSelfRef.pma[0U][2U] = 0x20U;
    vlSelfRef.pma[0U][3U] = 0U;
    vlSelfRef.pma[1U][0U] = 0x20001U;
    vlSelfRef.pma[1U][1U] = 0U;
    vlSelfRef.pma[1U][2U] = 0x40000U;
    vlSelfRef.pma[1U][3U] = 0U;
    vlSelfRef.pma[2U][0U] = 0x8000001U;
    vlSelfRef.pma[2U][1U] = 0U;
    vlSelfRef.pma[2U][2U] = 0x180000U;
    vlSelfRef.pma[2U][3U] = 0U;
    vlSelfRef.pma[3U][0U] = 0x201U;
    vlSelfRef.pma[3U][1U] = 0U;
    vlSelfRef.pma[3U][2U] = 0x200000U;
    vlSelfRef.pma[3U][3U] = 0U;
    vlSelfRef.pma[4U][0U] = 0x10000000U;
    vlSelfRef.pma[4U][1U] = 1U;
    vlSelfRef.pma[4U][2U] = 0x1000000U;
    vlSelfRef.pma[4U][3U] = 0U;
}

VL_ATTR_COLD void VTop_MemoryLayout___ctor_var_reset(VTop_MemoryLayout* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VTop_MemoryLayout___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_ZERO_RESET_W(113, vlSelf->pma[__Vi0]);
    }
}
