// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_mm_if__N4_NB4.h"

VL_INLINE_OPT void VTop_mm_if__N4_NB4___nba_sequent__TOP__Top__DOT__mm_mmu_port__0(VTop_mm_if__N4_NB4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N4_NB4___nba_sequent__TOP__Top__DOT__mm_mmu_port__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__res__v0 = 0U;
    vlSelfRef.__VdlySet__res__v1 = 0U;
}

VL_INLINE_OPT void VTop_mm_if__N4_NB4___nba_sequent__TOP__Top__DOT__mm_mmu_port__1(VTop_mm_if__N4_NB4* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N4_NB4___nba_sequent__TOP__Top__DOT__mm_mmu_port__1\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlUnpacked<VlWide<7>/*216:0*/, 4> res;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_ZERO_W(217, res[__Vi0]);
    }
    // Body
    if (vlSelfRef.__VdlySet__res__v0) {
        res[0U][0U] = vlSelfRef.__VdlyVal__res__v0[0U];
        res[0U][1U] = vlSelfRef.__VdlyVal__res__v0[1U];
        res[0U][2U] = vlSelfRef.__VdlyVal__res__v0[2U];
        res[0U][3U] = vlSelfRef.__VdlyVal__res__v0[3U];
        res[0U][4U] = vlSelfRef.__VdlyVal__res__v0[4U];
        res[0U][5U] = vlSelfRef.__VdlyVal__res__v0[5U];
        res[0U][6U] = vlSelfRef.__VdlyVal__res__v0[6U];
    }
    if (vlSelfRef.__VdlySet__res__v1) {
        res[1U][0U] = vlSelfRef.__VdlyVal__res__v1[0U];
        res[1U][1U] = vlSelfRef.__VdlyVal__res__v1[1U];
        res[1U][2U] = vlSelfRef.__VdlyVal__res__v1[2U];
        res[1U][3U] = vlSelfRef.__VdlyVal__res__v1[3U];
        res[1U][4U] = vlSelfRef.__VdlyVal__res__v1[4U];
        res[1U][5U] = vlSelfRef.__VdlyVal__res__v1[5U];
        res[1U][6U] = vlSelfRef.__VdlyVal__res__v1[6U];
        res[2U][0U] = vlSelfRef.__VdlyVal__res__v2[0U];
        res[2U][1U] = vlSelfRef.__VdlyVal__res__v2[1U];
        res[2U][2U] = vlSelfRef.__VdlyVal__res__v2[2U];
        res[2U][3U] = vlSelfRef.__VdlyVal__res__v2[3U];
        res[2U][4U] = vlSelfRef.__VdlyVal__res__v2[4U];
        res[2U][5U] = vlSelfRef.__VdlyVal__res__v2[5U];
        res[2U][6U] = vlSelfRef.__VdlyVal__res__v2[6U];
        res[3U][0U] = vlSelfRef.__VdlyVal__res__v3[0U];
        res[3U][1U] = vlSelfRef.__VdlyVal__res__v3[1U];
        res[3U][2U] = vlSelfRef.__VdlyVal__res__v3[2U];
        res[3U][3U] = vlSelfRef.__VdlyVal__res__v3[3U];
        res[3U][4U] = vlSelfRef.__VdlyVal__res__v3[4U];
        res[3U][5U] = vlSelfRef.__VdlyVal__res__v3[5U];
        res[3U][6U] = vlSelfRef.__VdlyVal__res__v3[6U];
    }
}

std::string VL_TO_STRING(const VTop_mm_if__N4_NB4* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N4_NB4::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
