// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__37(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__37\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v0 = 0U;
    vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__r_ram_idx_prev[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
            [0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__r_ram_idx_prev[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
            [1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__r_ram_idx_prev[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb_r_ram_idx
            [0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__r_ram_idx_prev[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb_r_ram_idx
            [1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__r_ram_idx_prev[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb_r_ram_idx
            [0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__r_ram_idx_prev[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb_r_ram_idx
            [1U];
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][1U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][2U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][3U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][4U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][5U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][6U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][7U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][8U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][9U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xaU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xbU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xcU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xdU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xeU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0xfU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x10U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x11U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x12U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x13U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x14U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x15U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x16U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x17U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x18U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x19U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x1fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x20U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x21U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x22U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x23U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x24U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x25U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x26U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x27U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x28U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x29U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x2fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x30U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x31U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x32U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x33U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x34U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x35U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x36U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x37U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x38U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x39U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][0x3fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][1U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][2U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][3U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][4U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][5U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][6U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][7U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][8U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][9U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xaU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xbU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xcU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xdU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xeU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0xfU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x10U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x11U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x12U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x13U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x14U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x15U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x16U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x17U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x18U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x19U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x1fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x20U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x21U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x22U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x23U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x24U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x25U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x26U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x27U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x28U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x29U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x2fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x30U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x31U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x32U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x33U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x34U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x35U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x36U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x37U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x38U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x39U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][0x3fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][1U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][2U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][3U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][4U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][5U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][6U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][7U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][8U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][9U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xaU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xbU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xcU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xdU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xeU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0xfU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x10U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x11U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x12U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x13U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x14U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x15U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x16U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x17U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x18U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x19U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x1fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x20U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x21U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x22U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x23U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x24U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x25U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x26U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x27U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x28U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x29U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x2fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x30U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x31U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x32U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x33U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x34U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x35U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x36U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x37U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x38U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x39U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][0x3fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][1U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][2U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][3U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][4U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][5U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][6U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][7U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][8U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][9U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xaU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xbU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xcU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xdU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xeU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0xfU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x10U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x11U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x12U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x13U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x14U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x15U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x16U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x17U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x18U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x19U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x1fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x20U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x21U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x22U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x23U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x24U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x25U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x26U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x27U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x28U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x29U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x2fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x30U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x31U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x32U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x33U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x34U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x35U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x36U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x37U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x38U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x39U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3aU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3bU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3cU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3dU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3eU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][0x3fU] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x40U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x40U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x41U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x41U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x42U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x42U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x43U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x43U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x44U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x44U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x45U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x45U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x46U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x46U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x47U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x47U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x48U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x48U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x49U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x49U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x4fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x4fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x50U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x50U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x51U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x51U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x52U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x52U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x53U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x53U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x54U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x54U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x55U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x55U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x56U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x56U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x57U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x57U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x58U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x58U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x59U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x59U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x5fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x5fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x60U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x60U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x61U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x61U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x62U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x62U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x63U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x63U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x64U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x64U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x65U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x65U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x66U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x66U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x67U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x67U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x68U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x68U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x69U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x69U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x6fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x6fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x70U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x70U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x71U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x71U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x72U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x72U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x73U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x73U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x74U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x74U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x75U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x75U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x76U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x76U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x77U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x77U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x78U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x78U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x79U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x79U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x7fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x7fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x80U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x80U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x81U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x81U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x82U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x82U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x83U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x83U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x84U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x84U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x85U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x85U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x86U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x86U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x87U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x87U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x88U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x88U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x89U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x89U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x8fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x8fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x90U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x90U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x91U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x91U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x92U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x92U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x93U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x93U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x94U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x94U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x95U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x95U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x96U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x96U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x97U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x97U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x98U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x98U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x99U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x99U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x9fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x9fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xa9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xa9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xaaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xaaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xabU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xabU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xacU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xacU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xadU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xadU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xaeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xaeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xafU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xafU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xb9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xb9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xbfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xbfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xc9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xc9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xcaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xcaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xcbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xcbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xcdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xcdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xcfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xcfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xd9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xd9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xdfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xdfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xe9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xe9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xeaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xeaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xedU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xedU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xeeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xeeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xefU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xefU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xf9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xf9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xfeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xfeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0xffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0xffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x100U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x100U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x101U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x101U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x102U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x102U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x103U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x103U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x104U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x104U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x105U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x105U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x106U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x106U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x107U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x107U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x108U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x108U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x109U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x109U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x10fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x10fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x110U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x110U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x111U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x111U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x112U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x112U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x113U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x113U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x114U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x114U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x115U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x115U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x116U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x116U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x117U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x117U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x118U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x118U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x119U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x119U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x11fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x11fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x120U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x120U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x121U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x121U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x122U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x122U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x123U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x123U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x124U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x124U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x125U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x125U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x126U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x126U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x127U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x127U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x128U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x128U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x129U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x129U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x12fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x12fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x130U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x130U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x131U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x131U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x132U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x132U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x133U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x133U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x134U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x134U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x135U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x135U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x136U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x136U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x137U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x137U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x138U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x138U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x139U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x139U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x13fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x13fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x140U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x140U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x141U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x141U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x142U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x142U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x143U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x143U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x144U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x144U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x145U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x145U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x146U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x146U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x147U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x147U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x148U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x148U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x149U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x149U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x14fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x14fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x150U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x150U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x151U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x151U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x152U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x152U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x153U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x153U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x154U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x154U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x155U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x155U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x156U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x156U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x157U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x157U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x158U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x158U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x159U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x159U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x15fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x15fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x160U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x160U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x161U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x161U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x162U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x162U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x163U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x163U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x164U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x164U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x165U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x165U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x166U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x166U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x167U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x167U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x168U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x168U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x169U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x169U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x16fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x16fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x170U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x170U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x171U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x171U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x172U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x172U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x173U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x173U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x174U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x174U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x175U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x175U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x176U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x176U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x177U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x177U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x178U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x178U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x179U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x179U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x17fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x17fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x180U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x180U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x181U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x181U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x182U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x182U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x183U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x183U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x184U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x184U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x185U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x185U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x186U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x186U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x187U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x187U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x188U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x188U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x189U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x189U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x18fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x18fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x190U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x190U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x191U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x191U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x192U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x192U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x193U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x193U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x194U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x194U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x195U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x195U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x196U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x196U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x197U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x197U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x198U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x198U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x199U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x199U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x19fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x19fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1a9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1a9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1aaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1aaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1abU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1abU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1acU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1acU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1adU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1adU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1aeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1aeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1afU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1afU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1b9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1b9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1baU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1baU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1bbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1bbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1bcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1bcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1bdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1bdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1beU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1beU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1bfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1bfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1c9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1c9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1caU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1caU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1cbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1cbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1cdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1cdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1cfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1cfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1d9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1d9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1daU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1daU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1dbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1dbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1dcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1dcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1deU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1deU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1dfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1dfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1e9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1e9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1eaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1eaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1edU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1edU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1eeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1eeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1efU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1efU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1f9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1f9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1faU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1faU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1fbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1fbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1fcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1fcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1fdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1fdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1feU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1feU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[0x1ffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[0x1ffU] = 0U;
    } else {
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x3fU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt[__Vilp1] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_next
                [__Vilp1];
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
        IData/*31:0*/ __Vilp2;
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x3fU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt_prev[__Vilp2] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__wbb__DOT__lvt
                [__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        IData/*31:0*/ __Vilp3;
        __Vilp3 = 0U;
        while ((__Vilp3 <= 0x3fU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt[__Vilp3] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_next
                [__Vilp3];
            __Vilp3 = ((IData)(1U) + __Vilp3);
        }
        IData/*31:0*/ __Vilp4;
        __Vilp4 = 0U;
        while ((__Vilp4 <= 0x3fU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt_prev[__Vilp4] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__wbb__DOT__lvt
                [__Vilp4];
            __Vilp4 = ((IData)(1U) + __Vilp4);
        }
        if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
            [0U]) {
            if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffffff00ULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | (IData)((IData)((0xffU 
                                                  & (IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                            [0U])))));
            }
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffff00ffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 8U))))) 
                                  << 8U));
            }
            if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffff00ffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x10U))))) 
                                  << 0x10U));
            }
            if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffff00ffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x18U))))) 
                                  << 0x18U));
            }
            if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffff00ffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x20U))))) 
                                  << 0x20U));
            }
            if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffff00ffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x28U))))) 
                                  << 0x28U));
            }
            if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xff00ffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x30U))))) 
                                  << 0x30U));
            }
            if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x38U))))) 
                                  << 0x38U));
            }
            if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffffff00ULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | (IData)((IData)((0xffU 
                                                  & (IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                            [0U])))));
            }
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffff00ffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 8U))))) 
                                  << 8U));
            }
            if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffff00ffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x10U))))) 
                                  << 0x10U));
            }
            if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffff00ffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x18U))))) 
                                  << 0x18U));
            }
            if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffff00ffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x20U))))) 
                                  << 0x20U));
            }
            if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffff00ffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x28U))))) 
                                  << 0x28U));
            }
            if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xff00ffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x30U))))) 
                                  << 0x30U));
            }
            if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] 
                    = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [0U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [0U] 
                                                              >> 0x38U))))) 
                                  << 0x38U));
            }
        }
        if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
            [1U]) {
            if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffffff00ULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | (IData)((IData)((0xffU 
                                                  & (IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                            [1U])))));
            }
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffff00ffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 8U))))) 
                                  << 8U));
            }
            if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffff00ffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x10U))))) 
                                  << 0x10U));
            }
            if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffff00ffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x18U))))) 
                                  << 0x18U));
            }
            if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffff00ffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x20U))))) 
                                  << 0x20U));
            }
            if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffff00ffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x28U))))) 
                                  << 0x28U));
            }
            if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xff00ffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x30U))))) 
                                  << 0x30U));
            }
            if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x38U))))) 
                                  << 0x38U));
            }
            if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffffff00ULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | (IData)((IData)((0xffU 
                                                  & (IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                            [1U])))));
            }
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffff00ffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 8U))))) 
                                  << 8U));
            }
            if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffff00ffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x10U))))) 
                                  << 0x10U));
            }
            if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffff00ffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x18U))))) 
                                  << 0x18U));
            }
            if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffff00ffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x20U))))) 
                                  << 0x20U));
            }
            if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffff00ffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x28U))))) 
                                  << 0x28U));
            }
            if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xff00ffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x30U))))) 
                                  << 0x30U));
            }
            if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram[1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] 
                    = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                        [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                        [1U]]) | ((QData)((IData)((0xffU 
                                                   & (IData)(
                                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                              [1U] 
                                                              >> 0x38U))))) 
                                  << 0x38U));
            }
        }
        if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
            [0U]) {
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                 [0U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [0U]];
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [0U]];
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [0U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [0U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [0U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [0U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [0U]];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [1U][0U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [0U]];
            }
        } else {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][0U] = 0ULL;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[0U][1U] = 0ULL;
        }
        if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
            [1U]) {
            if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                 [1U])) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [1U]];
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [0U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][0U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [1U]];
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
                if ((1U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffff00ULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | (IData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                   [
                                                                   (1U 
                                                                    & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                    [1U])])))));
                }
                if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffff00ffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 8U))))) 
                                         << 8U));
                }
                if ((4U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffff00ffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x10U))))) 
                                         << 0x10U));
                }
                if ((8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffff00ffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x18U))))) 
                                         << 0x18U));
                }
                if ((0x10U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffff00ffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x20U))))) 
                                         << 0x20U));
                }
                if ((0x20U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffff00ffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x28U))))) 
                                         << 0x28U));
                }
                if ((0x40U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xff00ffffffffffffULL & 
                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x30U))))) 
                                         << 0x30U));
                }
                if ((0x80U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_mask
                     [1U])) {
                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                        = ((0xffffffffffffffULL & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data
                            [1U][1U]) | ((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_data
                                                                     [
                                                                     (1U 
                                                                      & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table
                                                                      [1U])] 
                                                                     >> 0x38U))))) 
                                         << 0x38U));
                }
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [0U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [1U]];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__ram
                    [1U][1U][vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                    [1U]];
            }
        } else {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][0U] = 0ULL;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__read_raw_data[1U][1U] = 0ULL;
        }
        IData/*31:0*/ __Vilp5;
        __Vilp5 = 0U;
        while ((__Vilp5 <= 0x1ffU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt[__Vilp5] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_next
                [__Vilp5];
            __Vilp5 = ((IData)(1U) + __Vilp5);
        }
        IData/*31:0*/ __Vilp6;
        __Vilp6 = 0U;
        while ((__Vilp6 <= 0x1ffU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_prev[__Vilp6] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt
                [__Vilp6];
            __Vilp6 = ((IData)(1U) + __Vilp6);
        }
    }
}

extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_hd04caa2b_0;
extern const VlWide<11>/*351:0*/ VTop__ConstPool__CONST_h287f6670_0;
extern const VlWide<11>/*351:0*/ VTop__ConstPool__CONST_h55e331fb_0;

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__38(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__38\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3);
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4);
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5);
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3);
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4);
    VlWide<11>/*330:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5;
    VL_ZERO_W(331, __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14);
    VlWide<3>/*88:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15;
    VL_ZERO_W(89, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14);
    VlWide<3>/*72:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15;
    VL_ZERO_W(73, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30);
    VlWide<11>/*332:0*/ __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31;
    VL_ZERO_W(333, __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31);
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x20U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x21U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x22U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x23U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x24U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x25U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x26U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x27U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x28U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x29U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x2fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x30U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x31U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x32U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x33U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x34U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x35U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x36U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x37U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x38U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x39U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x3fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x40U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x40U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x41U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x41U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x42U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x42U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x43U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x43U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x44U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x44U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x45U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x45U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x46U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x46U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x47U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x47U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x48U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x48U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x49U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x49U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x4fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x4fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x50U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x50U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x51U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x51U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x52U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x52U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x53U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x53U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x54U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x54U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x55U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x55U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x56U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x56U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x57U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x57U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x58U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x58U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x59U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x59U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x5fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x5fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x60U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x60U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x61U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x61U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x62U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x62U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x63U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x63U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x64U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x64U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x65U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x65U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x66U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x66U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x67U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x67U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x68U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x68U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x69U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x69U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x6fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x6fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x70U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x70U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x71U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x71U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x72U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x72U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x73U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x73U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x74U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x74U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x75U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x75U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x76U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x76U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x77U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x77U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x78U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x78U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x79U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x79U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x7fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x7fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x80U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x80U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x81U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x81U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x82U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x82U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x83U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x83U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x84U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x84U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x85U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x85U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x86U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x86U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x87U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x87U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x88U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x88U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x89U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x89U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x8fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x8fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x90U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x90U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x91U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x91U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x92U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x92U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x93U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x93U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x94U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x94U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x95U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x95U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x96U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x96U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x97U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x97U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x98U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x98U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x99U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x99U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x9fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x9fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xa9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xa9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xaaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xaaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xabU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xabU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xacU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xacU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xadU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xadU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xaeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xaeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xafU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xafU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xb9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xb9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xbfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xbfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xc9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xc9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xcaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xcaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xcbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xcbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xcdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xcdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xcfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xcfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xd9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xd9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xdfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xdfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xe9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xe9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xeaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xeaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xedU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xedU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xeeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xeeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xefU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xefU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xf9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xf9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xfeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xfeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0xffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0xffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x100U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x100U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x101U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x101U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x102U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x102U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x103U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x103U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x104U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x104U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x105U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x105U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x106U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x106U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x107U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x107U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x108U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x108U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x109U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x109U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x10fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x10fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x110U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x110U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x111U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x111U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x112U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x112U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x113U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x113U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x114U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x114U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x115U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x115U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x116U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x116U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x117U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x117U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x118U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x118U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x119U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x119U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x11fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x11fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x120U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x120U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x121U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x121U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x122U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x122U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x123U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x123U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x124U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x124U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x125U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x125U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x126U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x126U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x127U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x127U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x128U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x128U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x129U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x129U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x12fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x12fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x130U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x130U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x131U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x131U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x132U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x132U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x133U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x133U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x134U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x134U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x135U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x135U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x136U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x136U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x137U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x137U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x138U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x138U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x139U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x139U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x13fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x13fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x140U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x140U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x141U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x141U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x142U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x142U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x143U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x143U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x144U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x144U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x145U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x145U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x146U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x146U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x147U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x147U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x148U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x148U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x149U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x149U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x14fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x14fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x150U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x150U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x151U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x151U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x152U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x152U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x153U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x153U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x154U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x154U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x155U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x155U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x156U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x156U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x157U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x157U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x158U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x158U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x159U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x159U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x15fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x15fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x160U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x160U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x161U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x161U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x162U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x162U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x163U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x163U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x164U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x164U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x165U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x165U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x166U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x166U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x167U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x167U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x168U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x168U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x169U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x169U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x16fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x16fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x170U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x170U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x171U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x171U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x172U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x172U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x173U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x173U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x174U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x174U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x175U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x175U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x176U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x176U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x177U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x177U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x178U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x178U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x179U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x179U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x17fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x17fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x180U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x180U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x181U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x181U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x182U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x182U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x183U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x183U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x184U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x184U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x185U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x185U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x186U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x186U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x187U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x187U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x188U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x188U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x189U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x189U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x18fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x18fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x190U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x190U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x191U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x191U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x192U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x192U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x193U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x193U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x194U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x194U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x195U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x195U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x196U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x196U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x197U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x197U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x198U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x198U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x199U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x199U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19aU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19bU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19cU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19dU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19eU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x19fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x19fU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1a9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1a9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1aaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1aaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1abU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1abU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1acU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1acU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1adU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1adU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1aeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1aeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1afU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1afU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1b9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1b9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1baU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1baU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1bbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1bbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1bcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1bcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1bdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1bdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1beU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1beU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1bfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1bfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1c9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1c9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1caU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1caU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1cbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1cbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ccU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1cdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1cdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ceU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1cfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1cfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1d9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1d9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1daU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1daU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1dbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1dbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1dcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1dcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ddU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1deU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1deU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1dfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1dfU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1e9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1e9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1eaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1eaU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ebU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ecU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1edU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1edU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1eeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1eeU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1efU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1efU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f4U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f5U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f6U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f7U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f8U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1f9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1f9U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1faU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1faU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1fbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1fbU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1fcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1fcU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1fdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1fdU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1feU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1feU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[0x1ffU] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[0x1ffU] = 0U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v0 = 1U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v0 = 1U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v0 = 1U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v0 = 1U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v0 = 1U;
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v0 = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_tmb = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_wp = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_rp = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_rp = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_wp = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_is = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[0U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[1U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[2U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[3U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[4U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[5U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[6U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[7U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[8U] 
            = VTop__ConstPool__CONST_hd04caa2b_0[8U];
    } else {
        IData/*31:0*/ __Vilp1;
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x1ffU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt[__Vilp1] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_next
                [__Vilp1];
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
        IData/*31:0*/ __Vilp2;
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x1ffU)) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt_prev[__Vilp2] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__lvt
                [__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][0U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][1U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][2U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][3U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][4U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][5U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][6U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][7U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][8U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][9U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [0U][0xaU];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v2 = 1U;
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][0U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][1U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][2U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][3U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][4U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][5U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][6U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][7U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][8U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][9U];
        vlSelfRef.__VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp__v3[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__req_out_tmp_next
            [1U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [0U][0xaU];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3 = 1U;
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [1U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp_next
            [2U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [0U][0xaU];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3 = 1U;
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [1U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp_next
            [2U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [0U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [0U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [0U][2U];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8 = 1U;
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [1U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [1U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [1U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [2U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [2U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [2U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [3U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [3U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [3U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [4U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [4U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [4U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [5U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [5U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [5U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [6U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [6U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [6U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [7U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [7U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
            [7U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [0U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [0U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [0U][2U];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8 = 1U;
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [1U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [1U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [1U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [2U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [2U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [2U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [3U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [3U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [3U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [4U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [4U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [4U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [5U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [5U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [5U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [6U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [6U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [6U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [7U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [7U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
            [7U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0U][0xaU];
        vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16 = 1U;
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [1U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [2U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [3U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [4U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [5U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [6U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [7U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [8U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [9U][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xaU][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xbU][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xcU][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xdU][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xeU][0xaU];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[0U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][0U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[1U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][1U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[2U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][2U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[3U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][3U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[4U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][4U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[5U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][5U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[6U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][6U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[7U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][7U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[8U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][8U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[9U] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][9U];
        __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[0xaU] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb_next
            [0xfU][0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_tmb 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_tmb_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_wp 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_wp_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_rp 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__availq_rp_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_rp 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_rp_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_wp 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__is_wp_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_is 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_is_next;
        if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_used) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[0U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[0U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[1U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[1U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[2U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[2U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[3U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[3U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[4U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[4U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[5U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[5U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[6U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[6U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[7U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[7U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[8U] 
                = VTop__ConstPool__CONST_hd04caa2b_0[8U];
        } else {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[0U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[0U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[1U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[1U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[2U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[2U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[3U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[3U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[4U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[4U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[5U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[5U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[6U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[6U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[7U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[7U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb[8U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_next[8U];
        }
    }
    vlSelfRef.Top__DOT__invalidate_l2cache_done = (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.reset))) 
                                                   && (IData)(vlSelfRef.Top__DOT__invalidate_l2cache_done_next));
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.Top__DOT__invalidate_l2cache = vlSelfRef.Top__DOT__invalidate_l2cache_next;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_valid 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_used))) 
                                                   && (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__fb_valid_next)));
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v0) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[0U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v3[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[1U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v4[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp[2U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__icache__DOT__req_out_tmp__v5[0xaU];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v0) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][0U] 
            = VTop__ConstPool__CONST_h287f6670_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][1U] 
            = VTop__ConstPool__CONST_h287f6670_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][2U] 
            = VTop__ConstPool__CONST_h287f6670_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][3U] 
            = VTop__ConstPool__CONST_h287f6670_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][4U] 
            = VTop__ConstPool__CONST_h287f6670_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][5U] 
            = VTop__ConstPool__CONST_h287f6670_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][6U] 
            = VTop__ConstPool__CONST_h287f6670_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][7U] 
            = VTop__ConstPool__CONST_h287f6670_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][8U] 
            = VTop__ConstPool__CONST_h287f6670_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][9U] 
            = VTop__ConstPool__CONST_h287f6670_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][0xaU] 
            = VTop__ConstPool__CONST_h287f6670_0[0xaU];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[0U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v3[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[1U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v4[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp[2U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__dcache__DOT__req_out_tmp__v5[0xaU];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v0) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[0U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v8[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[1U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v9[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[2U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v10[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[3U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v11[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[4U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v12[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[5U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v13[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[6U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v14[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf[7U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf__v15[2U];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v0) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[0U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v8[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[1U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v9[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[2U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v10[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[3U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v11[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[4U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v12[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[5U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v13[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[6U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v14[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info[7U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info__v15[2U];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v0) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][0U] 
            = VTop__ConstPool__CONST_h55e331fb_0[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][1U] 
            = VTop__ConstPool__CONST_h55e331fb_0[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][2U] 
            = VTop__ConstPool__CONST_h55e331fb_0[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][3U] 
            = VTop__ConstPool__CONST_h55e331fb_0[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][4U] 
            = VTop__ConstPool__CONST_h55e331fb_0[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][5U] 
            = VTop__ConstPool__CONST_h55e331fb_0[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][6U] 
            = VTop__ConstPool__CONST_h55e331fb_0[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][7U] 
            = VTop__ConstPool__CONST_h55e331fb_0[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][8U] 
            = VTop__ConstPool__CONST_h55e331fb_0[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][9U] 
            = VTop__ConstPool__CONST_h55e331fb_0[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][0xaU] 
            = VTop__ConstPool__CONST_h55e331fb_0[0xaU];
    }
    if (vlSelfRef.__VdlySet__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v16[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[1U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v17[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[2U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v18[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[3U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v19[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[4U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v20[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[5U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v21[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[6U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v22[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[7U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v23[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[8U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v24[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[9U][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v25[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xaU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v26[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xbU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v27[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xcU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v28[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xdU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v29[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xeU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v30[0xaU];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][0U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[0U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][1U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[1U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][2U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[2U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][3U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[3U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][4U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[4U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][5U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[5U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][6U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[6U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][7U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[7U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][8U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[8U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][9U] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[9U];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb[0xfU][0xaU] 
            = __VdlyVal__Top__DOT__cachesubsystem__DOT__l2cache__DOT__tmb__v31[0xaU];
    }
}
