// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_mm_if__N1_NB1.h"

VL_INLINE_OPT void VTop_mm_if__N1_NB1___nba_sequent__TOP__Top__DOT__mm_cachesubsystem_port__0(VTop_mm_if__N1_NB1* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N1_NB1___nba_sequent__TOP__Top__DOT__mm_cachesubsystem_port__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__res__v0 = 0U;
    vlSelfRef.__VdlySet__res__v1 = 0U;
    vlSelfRef.__VdlySet__res__v2 = 0U;
}

VL_INLINE_OPT void VTop_mm_if__N1_NB1___nba_sequent__TOP__Top__DOT__mm_cachesubsystem_port__1(VTop_mm_if__N1_NB1* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N1_NB1___nba_sequent__TOP__Top__DOT__mm_cachesubsystem_port__1\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__res__v0) {
        vlSelfRef.res[0U][0U] = 0U;
        vlSelfRef.res[0U][1U] = 0U;
        vlSelfRef.res[0U][2U] = 0U;
        vlSelfRef.res[0U][3U] = 0U;
        vlSelfRef.res[0U][4U] = 0U;
        vlSelfRef.res[0U][5U] = 0U;
        vlSelfRef.res[0U][6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__res__v1) {
        vlSelfRef.res[0U][0U] = vlSelfRef.__VdlyVal__res__v1[0U];
        vlSelfRef.res[0U][1U] = vlSelfRef.__VdlyVal__res__v1[1U];
        vlSelfRef.res[0U][2U] = vlSelfRef.__VdlyVal__res__v1[2U];
        vlSelfRef.res[0U][3U] = vlSelfRef.__VdlyVal__res__v1[3U];
        vlSelfRef.res[0U][4U] = vlSelfRef.__VdlyVal__res__v1[4U];
        vlSelfRef.res[0U][5U] = vlSelfRef.__VdlyVal__res__v1[5U];
        vlSelfRef.res[0U][6U] = vlSelfRef.__VdlyVal__res__v1[6U];
    }
    if (vlSelfRef.__VdlySet__res__v2) {
        vlSelfRef.res[0U][0U] = 0U;
        vlSelfRef.res[0U][1U] = 0U;
        vlSelfRef.res[0U][2U] = 0U;
        vlSelfRef.res[0U][3U] = 0U;
        vlSelfRef.res[0U][4U] = 0U;
        vlSelfRef.res[0U][5U] = 0U;
        vlSelfRef.res[0U][6U] = 0U;
    }
}

std::string VL_TO_STRING(const VTop_mm_if__N1_NB1* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_mm_if__N1_NB1::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
