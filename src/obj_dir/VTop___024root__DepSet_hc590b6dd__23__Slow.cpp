// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_hd571e6a2_0;
extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_hd04caa2b_0;

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__23(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__23\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ Top__DOT__unnamedblk3__DOT__res_to_lsu_counter;
    Top__DOT__unnamedblk3__DOT__res_to_lsu_counter = 0;
    IData/*31:0*/ Top__DOT__unnamedblk3__DOT__res_to_mmu_counter;
    Top__DOT__unnamedblk3__DOT__res_to_mmu_counter = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter;
    Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter;
    Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter = 0;
    CData/*0:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0;
    CData/*0:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered = 0;
    // Body
    if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                       [1U] >> 0x3eU)))) {
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [0U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [0U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [0U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [0U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [0U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [0U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [0U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[0U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [0U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [1U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [1U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [1U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [1U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [1U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [1U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [1U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[1U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [1U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [2U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [2U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [2U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [2U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [2U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [2U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [2U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[2U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [2U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [3U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [3U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [3U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [3U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [3U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [3U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [3U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[3U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [3U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [4U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [4U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [4U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [4U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [4U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [4U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [4U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[4U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [4U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [5U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [5U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [5U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [5U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [5U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [5U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [5U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[5U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [5U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [6U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [6U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [6U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [6U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [6U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [6U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [6U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[6U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [6U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [7U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [1U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [7U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [7U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [7U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [1U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [1U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [1U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [7U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [7U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [7U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[7U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [7U][0x26U]);
            }
        }
    }
    if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                       [2U] >> 0x3eU)))) {
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [0U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [0U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [0U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [0U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [0U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [0U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [0U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [0U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[0U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [0U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [1U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [1U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [1U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [1U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [1U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [1U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [1U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [1U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[1U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [1U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [2U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [2U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [2U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [2U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [2U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [2U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [2U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [2U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[2U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [2U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [3U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [3U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [3U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [3U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [3U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [3U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [3U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [3U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[3U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [3U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [4U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [4U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [4U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [4U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [4U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [4U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [4U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [4U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[4U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [4U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [5U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [5U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [5U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [5U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [5U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [5U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [5U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [5U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[5U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [5U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [6U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [6U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [6U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [6U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [6U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [6U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [6U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [6U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[6U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [6U][0x26U]);
            }
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
              [7U][0x2aU] >> 0x15U) & ((0xffffffffffffffULL 
                                        & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                           [2U] >> 6U)) 
                                       == (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                               [7U][0x2aU])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [7U][0x29U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                    [7U][0x28U])) 
                                                    >> 0x1dU))))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0 
                = (7U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                [2U]));
            if (VL_LIKELY(((0x555U >= ((IData)(0x4d6U) 
                                       + (0x1fU & ((IData)(3U) 
                                                   * 
                                                   (7U 
                                                    & (IData)(
                                                              (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                               [2U] 
                                                               >> 3U)))))))))) {
                VL_ASSIGNSEL_WI(1366,3,((IData)(0x4d6U) 
                                        + (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & (IData)(
                                                            (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.mshr_new_state
                                                             [2U] 
                                                             >> 3U)))))), 
                                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                [7U], vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT____Vlvbound_h53380c4f__0);
            }
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 1U;
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x16U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x19U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x26U] >> 0x1cU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [7U][0x27U] << 1U) | 
                              (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                               [7U][0x26U] >> 0x1fU))))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 2U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 5U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 8U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if ((6U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                              [7U][0x27U] >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated = 0U;
            }
            if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk56__DOT__is_all_updated) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[7U][0x26U] 
                    = (0x200000U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                       [7U][0x26U]);
            }
        }
    }
    if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                       >> 0x3fU)))) {
        if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                           >> 0x3eU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x27U] 
                = ((0xffff3fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                    [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                    >> 0x3bU)))][0x27U]) 
                   | (0xc000U & ((IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                          >> 0x39U)) 
                                 << 0xeU)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x24U] 
                = ((0x1fffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                    [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                    >> 0x3bU)))][0x24U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res)) 
                      << 0x1dU));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x25U] 
                = (((IData)((0xffffffffffffffULL & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res)) 
                    >> 3U) | ((IData)(((0xffffffffffffffULL 
                                        & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res) 
                                       >> 0x20U)) << 0x1dU));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x26U] 
                = ((0xffe00000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                    [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                    >> 0x3bU)))][0x26U]) 
                   | ((IData)(((0xffffffffffffffULL 
                                & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res) 
                               >> 0x20U)) >> 3U));
            if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                               >> 0x38U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x26U] 
                    = (0x24800000U | (0x3fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                      [(7U & (IData)(
                                                     (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                      >> 0x3bU)))][0x26U]));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x27U] 
                    = (0x1249U | (0xffffc000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                  [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                  >> 0x3bU)))][0x27U]));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0U] 
                    = (0xffff0000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                       [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                       >> 0x3bU)))][0U]);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0U] 
                    = ((0xffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                        [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                        >> 0x3bU)))][0U]) 
                       | ((IData)((0xffffffffffffffULL 
                                   & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res)) 
                          << 0x10U));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][1U] 
                    = (((IData)((0xffffffffffffffULL 
                                 & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res)) 
                        >> 0x10U) | ((IData)(((0xffffffffffffffULL 
                                               & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res) 
                                              >> 0x20U)) 
                                     << 0x10U));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][2U] 
                    = ((0x100U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                        [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                        >> 0x3bU)))][2U]) 
                       | (0x1ffU & ((IData)(((0xffffffffffffffULL 
                                              & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res) 
                                             >> 0x20U)) 
                                    >> 0x10U)));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][2U] 
                    = (0x100U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                       [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                       >> 0x3bU)))][2U]);
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x26U] 
                    = (0x49000000U | (0x3fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                      [(7U & (IData)(
                                                     (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                      >> 0x3bU)))][0x26U]));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x27U] 
                    = (0x2492U | (0xffffc000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                  [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                  >> 0x3bU)))][0x27U]));
            }
        } else {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x26U] 
                = (0x3fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                   >> 0x3bU)))][0x26U]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                                                                >> 0x3bU)))][0x27U] 
                = (0xffffc000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_res 
                                   >> 0x3bU)))][0x27U]);
        }
    }
    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U] = 0U;
    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[1U] = 0U;
    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U] = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i = 0U;
    {
        while ((8U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)) {
            if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                  [(7U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x2aU] 
                  >> 0x15U) & (0U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                            [(7U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x26U] 
                                            >> 0x16U))))) {
                vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U] 
                    = ((0xfffffe00U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U]) 
                       | ((0x1c0U & (Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i 
                                     << 6U)) | (0x3fU 
                                                & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                   [
                                                   (7U 
                                                    & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x27U] 
                                                   >> 0x10U))));
                vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U] 
                    = ((0x1ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U]) 
                       | ((IData)((0xffffffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                       [
                                                       (7U 
                                                        & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x2aU])) 
                                       << 0x23U) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                        [
                                                        (7U 
                                                         & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x29U])) 
                                        << 3U) | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                  [
                                                                  (7U 
                                                                   & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x28U])) 
                                                  >> 0x1dU))))) 
                          << 9U));
                vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[1U] 
                    = (((IData)((0xffffffffffffffULL 
                                 & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                     [
                                                     (7U 
                                                      & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x2aU])) 
                                     << 0x23U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                   [
                                                                   (7U 
                                                                    & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x29U])) 
                                                   << 3U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                     [
                                                                     (7U 
                                                                      & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x28U])) 
                                                     >> 0x1dU))))) 
                        >> 0x17U) | ((IData)(((0xffffffffffffffULL 
                                               & (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                   [
                                                                   (7U 
                                                                    & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x2aU])) 
                                                   << 0x23U) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                      [
                                                                      (7U 
                                                                       & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x29U])) 
                                                      << 3U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                        [
                                                                        (7U 
                                                                         & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x28U])) 
                                                        >> 0x1dU)))) 
                                              >> 0x20U)) 
                                     << 9U));
                vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U] 
                    = ((2U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U]) 
                       | (3U & ((IData)(((0xffffffffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                              [
                                                              (7U 
                                                               & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x2aU])) 
                                              << 0x23U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                 [
                                                                 (7U 
                                                                  & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x29U])) 
                                                 << 3U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                                                   [
                                                                   (7U 
                                                                    & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x28U])) 
                                                   >> 0x1dU)))) 
                                         >> 0x20U)) 
                                >> 0x17U)));
                vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U] 
                    = (2U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U]);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x26U] 
                    = (0x92400000U | (0x3fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                      [(7U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x26U]));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[(7U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x27U] 
                    = (0x924U | (0xffffc000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                 [(7U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i)][0x27U]));
                goto __Vlabel200;
            }
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk60__DOT__i);
        }
        __Vlabel200: ;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__stall_req_to_l2cache 
        = ((6U > ((IData)(0x20U) - (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq_next))) 
           | ((1U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state)) 
              | (2U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state))));
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [0U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [0U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [0U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [0U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[0U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [0U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [1U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [1U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [1U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [1U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[1U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [1U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [2U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [2U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [2U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [2U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[2U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [2U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [3U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [3U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [3U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [3U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[3U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [3U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [4U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [4U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [4U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [4U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[4U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [4U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [5U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [5U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [5U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [5U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[5U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [5U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [6U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [6U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [6U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [6U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[6U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [6U][0x2aU]);
    }
    if (((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [7U][0x2aU] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
            [7U][0x26U]) >> 0x15U) & (0U == (0xfU & 
                                             (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                                              [7U][9U] 
                                              >> 0xfU)))) 
         & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
                   [7U][0U])))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next[7U][0x2aU] 
            = (0x1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
               [7U][0x2aU]);
    }
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered = 0U;
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [0U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [1U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [2U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [3U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [4U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [5U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [6U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x200000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__mshr_next
         [7U][0x2aU])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [0U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [1U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [2U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [3U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [4U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [5U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [6U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    if ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
         [7U][2U])) {
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next 
            = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next);
    }
    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req = 0U;
    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req = 0U;
    vlSelfRef.Top__DOT__invalidate_l2cache_done_next = 0U;
    if (((IData)(vlSelfRef.Top__DOT__invalidate_l2cache) 
         & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state)))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state_next = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
    } else if ((((((1U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state)) 
                   & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq_next))) 
                  & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_tmb_next))) 
                 & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_is_next))) 
                & (0U == Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state_next = 2U;
    } else if ((((((((2U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state)) 
                     & (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next)) 
                    & (0U == Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_invalidate_buf_next)) 
                   & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_availq_next))) 
                  & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_tmb_next))) 
                 & (0U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__num_of_entries_in_is_next))) 
                & (0U == Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__num_of_entries_in_mshr_next))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state_next = 0U;
        vlSelfRef.Top__DOT__invalidate_l2cache_done_next = 1U;
    }
    if ((2U == (IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cache_state))) {
        if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                           >> 0x3dU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][1U] 
                = (IData)((0xffffffffffffffULL & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                  >> 5U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][2U] 
                = ((0x1000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                    >> 2U)))][2U]) 
                   | (0x1ffffffU & (IData)(((0xffffffffffffffULL 
                                             & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                >> 5U)) 
                                            >> 0x20U))));
            if ((1U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                               >> 1U)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][0U] 
                    = (0x492492U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                    [(7U & (IData)(
                                                   (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                    >> 2U)))][0U]));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][0U] 
                    = (0xffff0000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                       [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                       >> 2U)))][0U]);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][0U] 
                    = ((0xffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                        [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                        >> 2U)))][0U]) 
                       | ((IData)((0xffffffffffffffULL 
                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                      >> 5U))) << 0x10U));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][1U] 
                    = (((IData)((0xffffffffffffffULL 
                                 & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                    >> 5U))) >> 0x10U) 
                       | ((IData)(((0xffffffffffffffULL 
                                    & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                       >> 5U)) >> 0x20U)) 
                          << 0x10U));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][2U] 
                    = ((0x100U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                        [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                        >> 2U)))][2U]) 
                       | (0x1ffU & ((IData)(((0xffffffffffffffULL 
                                              & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                 >> 5U)) 
                                             >> 0x20U)) 
                                    >> 0x10U)));
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][2U] 
                    = (0x100U | vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_info_next
                       [(7U & (IData)((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                       >> 2U)))][2U]);
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[(7U 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                                                >> 2U)))][0U] 
                    = (0x924924U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                    [(7U & (IData)(
                                                   (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_res 
                                                    >> 2U)))][0U]));
            }
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [0U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [0U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0x800U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [0U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [1U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [1U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0x900U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [1U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [2U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [2U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xa00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [2U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [3U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [3U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xb00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [3U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [4U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [4U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xc00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [4U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [5U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [5U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xd00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [5U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [6U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [6U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xe00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [6U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [7U][2U] >> 0x18U) & (0U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                            [7U][0U]))) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req 
                = (0xf00U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [7U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x249249U | (0xff000000U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__invalidate_allocate_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [0U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [0U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [0U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [0U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [0U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [0U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [0U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [0U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [0U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [0U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [0U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [0U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [0U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [0U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] = 0xc0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [0U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [1U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [1U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [1U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [1U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [1U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [1U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [1U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [1U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [1U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [1U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [1U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [1U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [1U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [1U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [1U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [2U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [2U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [2U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [2U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [2U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [2U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [2U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [2U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [2U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [2U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [2U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [2U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [2U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [2U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [2U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [3U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [3U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [3U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [3U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [3U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [3U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [3U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [3U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [3U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [3U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [3U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [3U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [3U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [3U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0xc00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [3U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [4U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [4U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [4U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [4U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [4U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [4U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [4U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [4U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [4U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [4U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [4U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [4U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [4U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [4U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1000U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [4U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [5U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [5U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [5U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [5U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [5U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [5U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [5U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [5U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [5U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [5U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [5U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [5U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [5U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [5U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1400U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [5U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [6U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [6U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [6U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [6U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [6U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [6U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [6U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [6U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [6U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [6U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [6U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [6U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [6U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [6U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1800U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [6U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                     [7U][0U])) & (2U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                               [7U][2U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U])))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [7U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                  [7U][2U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][1U]))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                [7U][2U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (3U | (0xfffffff8U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                         [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 3U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (8ULL + (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                       [7U][2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [7U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (8ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (8ULL + (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                        [7U][2U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x18U | (0xffffffc7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 6U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x10ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x10ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x10ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0xc0U | (0xfffffe3fU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                            [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 9U))) & (2U 
                                                > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x18ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x18ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x18ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x600U | (0xfffff1ffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 0xcU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x20ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x20ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x20ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x3000U | (0xffff8fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                              [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 0xfU))) & (2U 
                                                  > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x28ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x28ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x28ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x18000U | (0xfffc7fffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 0x12U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x30ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x30ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x30ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0xc0000U | (0xffe3ffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                               [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        if (((2U == (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                           [7U][0U] >> 0x15U))) & (2U 
                                                   > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][1U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][2U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][3U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][4U] 
                = ((IData)((0x100000000000000ULL | 
                            (0xffffffffffffffULL & 
                             (0x38ULL + (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                          [7U][2U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][1U]))))))) 
                   << 3U);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][5U] 
                = (((IData)((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U]))))))) 
                    >> 0x1dU) | ((IData)(((0x100000000000000ULL 
                                           | (0xffffffffffffffULL 
                                              & (0x38ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                   [7U][2U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                                    [7U][1U])))))) 
                                          >> 0x20U)) 
                                 << 3U));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][6U] 
                = ((IData)(((0x100000000000000ULL | 
                             (0xffffffffffffffULL & 
                              (0x38ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                           [7U][2U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                                            [7U][1U])))))) 
                            >> 0x20U)) >> 0x1dU);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xffffffc0U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0xc0U | (0xfffffc3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                            [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]));
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U] 
                = (0x3ffU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][7U]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][8U] = 0U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][9U] = 0x1c00U;
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req[(1U 
                                                                                & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU] 
                = (0x400U | vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                   [(1U & Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter)][0xaU]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = (0x600000U | (0xff1fffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                                [7U][0U]));
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__read_req_to_cb_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter = 0U;
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [0U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [0U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
              [0U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [0U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [0U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [1U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [1U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [1U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [1U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [1U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [2U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [2U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [2U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [2U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [2U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [3U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [3U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [3U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [3U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [3U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [4U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [4U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [4U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [4U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [4U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [5U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [5U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [5U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [5U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [5U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [6U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [6U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [6U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [6U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [6U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 1U;
        if ((4U != (7U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                    [7U][0U]))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 3U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 6U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 9U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 0xcU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 0xfU)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 0x12U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((4U != (7U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                          [7U][0U] >> 0x15U)))) {
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all = 0U;
        }
        if ((((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
               [7U][2U] >> 0x18U) & (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__has_written_back_all)) 
             & (1U > Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter))) {
            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req 
                = (0x100U | (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                             [7U][0U] >> 0x18U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][2U] 
                = (0xffffffU & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                   [7U][2U]);
            Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__delete_counter);
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [0U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[0U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [1U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[1U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [2U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[2U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [3U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[3U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [4U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[4U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [5U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[5U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [6U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[6U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
        Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered 
            = (0x40U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
        if ((1U & ((~ (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next
                       [7U][2U] >> 0x18U)) & (~ (IData)(Top__DOT__cachesubsystem__DOT__l2cache__DOT__unnamedblk2__DOT__unnamedblk62__DOT__all_invalidate_entries_registered))))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][0U] 
                = ((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    << 0x1aU) | (0x3000000U & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                                               << 0x18U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][1U] = 0U;
            vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_buf_next[7U][2U] = 0x1000000U;
            if ((3U == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next)) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_set_counter_next);
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next = 0U;
            } else {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__invalidate_way_counter_next);
            }
        }
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_mask
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_mask
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_mask
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_mask
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_mask
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_mask
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_mask
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_mask
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][0U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[0U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][1U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[1U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][2U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[2U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][3U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[3U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][4U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[4U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][5U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[5U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][6U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[6U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][7U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[7U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[0U][8U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[8U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][0U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[0U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][1U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[1U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][2U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[2U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][3U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[3U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][4U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[4U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][5U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[5U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][6U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[6U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][7U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[7U];
    vlSelfRef.Top__DOT__res_to_lsu_from_dcache[1U][8U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[8U];
    Top__DOT__unnamedblk3__DOT__res_to_lsu_counter = 0U;
    if ((0x800U & vlSelfRef.Top__DOT__res_from_dcache
         [0U][8U])) {
        if ((0U == ((vlSelfRef.Top__DOT__res_from_dcache
                     [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                           [0U][6U] 
                                           >> 0xbU)))) {
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][0U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][0U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][1U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][1U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][2U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][2U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][3U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][3U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][4U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][4U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][5U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][5U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][6U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][6U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][7U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][7U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][8U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [0U][8U];
            Top__DOT__unnamedblk3__DOT__res_to_lsu_counter 
                = ((IData)(1U) + Top__DOT__unnamedblk3__DOT__res_to_lsu_counter);
        }
    }
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][0U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[0U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][1U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[1U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][2U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[2U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][3U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[3U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][4U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[4U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][5U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[5U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][6U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[6U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][7U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[7U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[0U][8U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[8U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][0U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[0U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][1U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[1U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][2U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[2U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][3U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[3U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][4U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[4U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][5U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[5U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][6U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[6U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][7U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[7U];
    vlSelfRef.Top__DOT__res_to_mmu_from_dcache[1U][8U] 
        = VTop__ConstPool__CONST_hd571e6a2_0[8U];
    Top__DOT__unnamedblk3__DOT__res_to_mmu_counter = 0U;
    if ((0x800U & vlSelfRef.Top__DOT__res_from_dcache
         [0U][8U])) {
        if ((0U != ((vlSelfRef.Top__DOT__res_from_dcache
                     [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                           [0U][6U] 
                                           >> 0xbU)))) {
            if ((1U == ((vlSelfRef.Top__DOT__res_from_dcache
                         [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                               [0U][6U] 
                                               >> 0xbU)))) {
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][0U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][0U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][1U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][1U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][2U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][2U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][3U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][3U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][4U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][4U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][5U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][5U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][6U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][6U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][7U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][7U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][8U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [0U][8U];
                Top__DOT__unnamedblk3__DOT__res_to_mmu_counter 
                    = ((IData)(1U) + Top__DOT__unnamedblk3__DOT__res_to_mmu_counter);
            }
        }
    }
    if ((0x800U & vlSelfRef.Top__DOT__res_from_dcache
         [1U][8U])) {
        if ((0U == ((vlSelfRef.Top__DOT__res_from_dcache
                     [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                           [1U][6U] 
                                           >> 0xbU)))) {
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][0U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][0U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][1U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][1U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][2U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][2U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][3U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][3U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][4U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][4U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][5U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][5U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][6U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][6U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][7U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][7U];
            vlSelfRef.Top__DOT__res_to_lsu_from_dcache[(1U 
                                                        & Top__DOT__unnamedblk3__DOT__res_to_lsu_counter)][8U] 
                = vlSelfRef.Top__DOT__res_from_dcache
                [1U][8U];
            Top__DOT__unnamedblk3__DOT__res_to_lsu_counter 
                = ((IData)(1U) + Top__DOT__unnamedblk3__DOT__res_to_lsu_counter);
        }
        if ((0U != ((vlSelfRef.Top__DOT__res_from_dcache
                     [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                           [1U][6U] 
                                           >> 0xbU)))) {
            if ((1U == ((vlSelfRef.Top__DOT__res_from_dcache
                         [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__res_from_dcache
                                               [1U][6U] 
                                               >> 0xbU)))) {
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][0U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][0U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][1U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][1U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][2U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][2U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][3U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][3U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][4U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][4U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][5U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][5U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][6U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][6U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][7U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][7U];
                vlSelfRef.Top__DOT__res_to_mmu_from_dcache[(1U 
                                                            & Top__DOT__unnamedblk3__DOT__res_to_mmu_counter)][8U] 
                    = vlSelfRef.Top__DOT__res_from_dcache
                    [1U][8U];
                Top__DOT__unnamedblk3__DOT__res_to_mmu_counter 
                    = ((IData)(1U) + Top__DOT__unnamedblk3__DOT__res_to_mmu_counter);
            }
        }
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_mask
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_mask
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_mask
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_mask[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_mask
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_w_ram_idx
        [3U][0U];
    Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][0U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][1U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][2U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][3U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][4U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][5U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][6U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][7U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[0U][8U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[8U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][0U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][1U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][2U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][3U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][4U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][5U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][6U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][7U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[1U][8U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[8U];
    if ((0x800U & vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
         [0U][8U])) {
        if ((0U == ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                     [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                           [0U][6U] 
                                           >> 0xbU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][0U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][0U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][1U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][1U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][2U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][2U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][3U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][3U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][4U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][4U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][5U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][5U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][6U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][6U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][7U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][7U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][8U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [0U][8U];
            Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter);
        }
    }
    Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][0U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][1U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][2U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][3U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][4U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][5U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][6U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][7U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[0U][8U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[8U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][0U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][1U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][2U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][3U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][4U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][5U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][6U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][7U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[1U][8U] 
        = VTop__ConstPool__CONST_hd04caa2b_0[8U];
    if ((0x800U & vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
         [0U][8U])) {
        if ((0U != ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                     [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                           [0U][6U] 
                                           >> 0xbU)))) {
            if ((1U == ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                         [0U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                               [0U][6U] 
                                               >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][0U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][1U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][2U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][2U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][3U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][3U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][4U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][4U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][5U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][5U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][6U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][6U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][7U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][7U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][8U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [0U][8U];
                Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter 
                    = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter);
            }
        }
    }
    if ((0x800U & vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
         [1U][8U])) {
        if ((0U == ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                     [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                           [1U][6U] 
                                           >> 0xbU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][0U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][0U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][1U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][1U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][2U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][2U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][3U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][3U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][4U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][4U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][5U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][5U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][6U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][6U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][7U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][7U];
            vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_icache[(1U 
                                                                    & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter)][8U] 
                = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                [1U][8U];
            Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter 
                = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_icache_counter);
        }
        if ((0U != ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                     [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                           [1U][6U] 
                                           >> 0xbU)))) {
            if ((1U == ((vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                         [1U][7U] << 0x15U) | (vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                                               [1U][6U] 
                                               >> 0xbU)))) {
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][0U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][0U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][1U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][1U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][2U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][2U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][3U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][3U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][4U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][4U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][5U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][5U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][6U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][6U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][7U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][7U];
                vlSelfRef.Top__DOT__cachesubsystem__DOT__res_to_dcache[(1U 
                                                                        & Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter)][8U] 
                    = vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_l2cache
                    [1U][8U];
                Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter 
                    = ((IData)(1U) + Top__DOT__cachesubsystem__DOT__unnamedblk4__DOT__res_to_dcache_counter);
            }
        }
    }
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__lvt_next[__Vilp1] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__lvt
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__wbb__DOT__bypass_table[1U] = 3U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_en[1U] = 0U;
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
         [0U][0xaU])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_ram_idx[0U] 
            = (0x1ffU & (VL_SHIFTL_III(9,32,32, (0x3fU 
                                                 & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                                                    [0U][4U] 
                                                    >> 9U)), 3U) 
                         + (7U & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                                  [0U][4U] >> 6U))));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_en[0U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[0U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[0U] 
            = (0x3fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                        [0U][4U] >> 9U));
    } else {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[3U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[1U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[2U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[3U] = 0U;
    }
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
         [1U][0xaU])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_ram_idx[1U] 
            = (0x1ffU & (VL_SHIFTL_III(9,32,32, (0x3fU 
                                                 & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                                                    [1U][4U] 
                                                    >> 9U)), 3U) 
                         + (7U & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                                  [1U][4U] >> 6U))));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_data_r_en[1U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[1U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[1U] 
            = (0x3fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.read_req
                        [1U][4U] >> 9U));
    }
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.write_req
         [0U][0xaU])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[2U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[2U] 
            = (0x3fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.write_req
                        [0U][4U] >> 9U));
    }
    if ((2U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[2U])) {
        vlSelfRef.__Vfunc_search_oldest__242__plru_tree_tmp 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__plru_tree
            [(0x3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U])];
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[3U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[3U] 
            = (0x3fU & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.allocate_req[0U]);
        vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_next 
            = ((2U & (IData)(vlSelfRef.__Vfunc_search_oldest__242__plru_tree_tmp))
                ? 1U : 0U);
        vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_current 
            = vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_next;
        vlSelfRef.__Vfunc_search_oldest__242__structured_idx 
            = (4U | (IData)(vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_current));
        vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_next 
            = (3U & ((1U & ((IData)(vlSelfRef.__Vfunc_search_oldest__242__plru_tree_tmp) 
                            >> ([&]() {
                                vlSelfRef.__Vfunc_idx_structured_to_raw__243__structured_idx 
                                    = vlSelfRef.__Vfunc_search_oldest__242__structured_idx;
                                vlSelfRef.__Vfunc_idx_structured_to_raw__243__plru_tree_idx 
                                    = (3U & (((IData)(1U) 
                                              << (1U 
                                                  & ((IData)(vlSelfRef.__Vfunc_idx_structured_to_raw__243__structured_idx) 
                                                     >> 2U))) 
                                             + (IData)(vlSelfRef.__Vfunc_idx_structured_to_raw__243__structured_idx)));
                                vlSelfRef.__Vfunc_idx_structured_to_raw__243__Vfuncout 
                                    = vlSelfRef.__Vfunc_idx_structured_to_raw__243__plru_tree_idx;
                            }(), (IData)(vlSelfRef.__Vfunc_idx_structured_to_raw__243__Vfuncout))))
                      ? ((IData)(1U) + VL_SHIFTL_III(2,32,32, (IData)(vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_current), 1U))
                      : VL_SHIFTL_III(2,32,32, (IData)(vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_current), 1U)));
        vlSelfRef.__Vfunc_search_oldest__242__Vfuncout 
            = vlSelfRef.__Vfunc_search_oldest__242__idx_in_layer_next;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__allocated_way 
            = vlSelfRef.__Vfunc_search_oldest__242__Vfuncout;
    } else {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__allocated_way = 0U;
    }
    if ((0x800U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en[2U] = 1U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx[2U] 
            = (0x3fU & ((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_get_info_req) 
                        >> 2U));
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[0U][0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[1U][0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[2U][0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[3U][0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[0U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[1U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[2U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[3U][0U] = 0U;
    if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
         [0U][4U])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[(3U 
                                                                                & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                                                [0U][2U])][0U] 
            = (0x200000000000ULL | ((0x1ffffffffffeULL 
                                     & (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                         [0U][3U])) 
                                         << 0x13U) 
                                        | (0x7fffffffffffeULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                              [0U][2U])) 
                                              >> 0xdU)))) 
                                    | (QData)((IData)(
                                                      ((3U 
                                                        == 
                                                        (7U 
                                                         & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                            [0U][3U] 
                                                            >> 0x1aU)))
                                                        ? 1U
                                                        : 0U)))));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[(3U 
                                                                                & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                                                [0U][2U])][0U] 
            = (0x3fU & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                        [0U][2U] >> 2U));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[3U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[(3U 
                                                                                & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__write_buf
                                                                                [0U][2U])][0U] = 1U;
    } else {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[3U][0U] = 0U;
    }
    if ((0x100U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_data[(3U 
                                                                                & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req))][0U] = 0ULL;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_ram_idx[(3U 
                                                                                & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req))][0U] 
            = (0x3fU & ((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req) 
                        >> 2U));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_en[(3U 
                                                                                & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.invalidate_req))][0U] = 1U;
    }
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x1ffU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_next[__Vilp2] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx[0U]] = 0U;
    }
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x1ffU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__lvt_next[__Vilp3] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__lvt
            [__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx[0U]] = 0U;
    }
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x197U)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__lvt_next[__Vilp4] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__lvt
            [__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
}
