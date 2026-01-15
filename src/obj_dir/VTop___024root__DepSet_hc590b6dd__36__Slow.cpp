// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__39(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__39\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*38:0*/ Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff;
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0;
    CData/*0:0*/ Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data;
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 0;
    // Body
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[1U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xdU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xdU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [1U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [1U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[1U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [1U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xdU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xdU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [1U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xdU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xdU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xdU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [1U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [1U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xdU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xdU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xdU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [1U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [1U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [1U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xd0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xdU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xdU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xdU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xdU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [1U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [1U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xdU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xdU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xdU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xdU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xdU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xdU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [1U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [1U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [1U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [1U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [1U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xd0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xdU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xdU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[1U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xeU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xeU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [1U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [1U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[1U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [1U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xeU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xeU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [1U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xeU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xeU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xeU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [1U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [1U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xeU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xeU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xeU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [1U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [1U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [1U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xe0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xeU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xeU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xeU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xeU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [1U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [1U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xeU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xeU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xeU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xeU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xeU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xeU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [1U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [1U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [1U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [1U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [1U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xe0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xeU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xeU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[1U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xfU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xfU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [1U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [1U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[1U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [1U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xfU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xfU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [1U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xfU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xfU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xfU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [1U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [1U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xfU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xfU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xfU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [1U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [1U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [1U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [1U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [1U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xf0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[2U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xfU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xfU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xfU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xfU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [1U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [1U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xfU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xfU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xfU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [1U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xfU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xfU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xfU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [1U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [1U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [1U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [1U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [1U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [1U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [1U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [1U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [1U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [1U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [1U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xf0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [1U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[3U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xfU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xfU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [0U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = (IData)((((QData)((IData)((1U & (
                                                   vlSelfRef.Top__DOT__res_from_icache
                                                   [2U][5U] 
                                                   >> 9U)))) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][0U]))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = ((0xfffffffeU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U]) 
                   | (IData)(((((QData)((IData)((1U 
                                                 & (vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][5U] 
                                                    >> 9U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][0U]))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = ((1U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U]) 
                   | ((IData)((((QData)((IData)((3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U))))) 
                                << 0x39U) | ((0x1fffffffffffffeULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  << 0x1eU) 
                                                 | (0x3ffffffffffffffeULL 
                                                    & ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__res_from_icache
                                                                       [2U][2U])) 
                                                       >> 2U)))) 
                                             | (QData)((IData)(
                                                               (1U 
                                                                & (vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][5U] 
                                                                   >> 0xaU))))))) 
                      << 1U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = (((IData)((((QData)((IData)((3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U))))) 
                              << 0x39U) | ((0x1fffffffffffffeULL 
                                            & (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][3U])) 
                                                << 0x1eU) 
                                               | (0x3ffffffffffffffeULL 
                                                  & ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][2U])) 
                                                     >> 2U)))) 
                                           | (QData)((IData)(
                                                             (1U 
                                                              & (vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][5U] 
                                                                 >> 0xaU))))))) 
                    >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                            (3U 
                                                             & (IData)(
                                                                       (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                                        >> 2U))))) 
                                            << 0x39U) 
                                           | ((0x1fffffffffffffeULL 
                                               & (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x1eU) 
                                                  | (0x3ffffffffffffffeULL 
                                                     & ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 2U)))) 
                                              | (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][5U] 
                                                                    >> 0xaU)))))) 
                                          >> 0x20U)) 
                                 << 1U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = (IData)((((QData)((IData)((1U & (
                                                   vlSelfRef.Top__DOT__res_from_icache
                                                   [2U][5U] 
                                                   >> 9U)))) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][1U]))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffeU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (IData)(((((QData)((IData)((1U 
                                                 & (vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][5U] 
                                                    >> 9U)))) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][1U]))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((1U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((((QData)((IData)((3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U))))) 
                                << 0x39U) | ((0x1fffffffffffffeULL 
                                              & ((4ULL 
                                                  + 
                                                  (((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][3U])) 
                                                    << 0x3dU) 
                                                   | (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__res_from_icache
                                                                       [2U][3U])) 
                                                       << 0x1dU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__res_from_icache
                                                                         [2U][2U])) 
                                                         >> 3U)))) 
                                                 << 1U)) 
                                             | (QData)((IData)(
                                                               (1U 
                                                                & (vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][5U] 
                                                                   >> 0xaU))))))) 
                      << 1U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = (((IData)((((QData)((IData)((3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U))))) 
                              << 0x39U) | ((0x1fffffffffffffeULL 
                                            & ((4ULL 
                                                + (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][3U])) 
                                                    << 0x3dU) 
                                                   | (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__res_from_icache
                                                                       [2U][3U])) 
                                                       << 0x1dU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__res_from_icache
                                                                         [2U][2U])) 
                                                         >> 3U)))) 
                                               << 1U)) 
                                           | (QData)((IData)(
                                                             (1U 
                                                              & (vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][5U] 
                                                                 >> 0xaU))))))) 
                    >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                            (3U 
                                                             & (IData)(
                                                                       (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                                        >> 2U))))) 
                                            << 0x39U) 
                                           | ((0x1fffffffffffffeULL 
                                               & ((4ULL 
                                                   + 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     << 0x3dU) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][3U])) 
                                                        << 0x1dU) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__res_from_icache
                                                                          [2U][2U])) 
                                                          >> 3U)))) 
                                                  << 1U)) 
                                              | (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][5U] 
                                                                    >> 0xaU)))))) 
                                          >> 0x20U)) 
                                 << 1U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [1U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [1U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [1U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [1U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [1U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [1U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [1U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [1U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [1U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [1U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x10000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[1U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [1U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [1U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [1U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [1U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [1U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [1U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [1U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [1U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [1U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x10000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[1U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [1U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [2U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [2U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [2U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [2U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [2U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [2U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [2U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [2U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [2U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [2U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x20000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[2U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [2U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [2U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [2U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [2U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [2U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [2U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [2U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [2U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [2U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x20000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[2U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [2U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [3U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [3U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [3U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [3U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [3U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [3U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [3U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [3U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [3U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [3U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x30000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[3U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [3U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [3U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [3U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [3U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [3U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [3U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [3U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [3U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [3U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x30000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[3U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [3U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [4U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [4U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [4U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [4U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [4U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [4U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [4U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [4U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [4U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [4U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x40000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[4U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [4U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [4U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [4U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [4U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [4U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [4U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [4U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [4U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [4U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x40000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[4U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [4U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [5U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [5U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [5U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [5U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [5U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [5U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [5U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [5U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [5U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [5U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x50000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[5U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [5U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [5U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [5U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [5U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [5U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [5U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [5U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [5U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [5U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x50000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[5U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [5U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [6U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [6U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [6U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [6U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [6U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [6U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [6U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [6U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [6U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [6U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x60000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[6U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [6U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [6U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [6U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [6U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [6U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [6U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [6U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [6U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [6U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x60000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[6U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [6U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [7U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [7U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [7U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [7U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [7U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [7U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [7U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [7U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [7U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [7U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x70000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[7U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [7U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [7U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [7U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [7U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [7U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [7U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [7U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [7U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [7U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x70000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[7U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [7U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [8U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [8U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [8U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [8U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [8U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [8U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [8U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [8U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [8U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [8U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x80000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[8U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [8U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [8U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [8U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [8U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [8U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [8U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [8U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [8U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [8U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x80000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[8U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [8U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [9U][2U] << 0xfU) 
                                       | (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                          [9U][1U] 
                                          >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [9U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [9U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [9U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [9U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [9U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [9U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [9U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [9U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0x90000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[9U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [9U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [9U][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [9U][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [9U][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [9U][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [9U][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [9U][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [9U][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [9U][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0x90000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[9U][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [9U][0U] | ((IData)(1U) << (3U & (IData)(
                                                            (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                             >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xaU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xaU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xaU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xaU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xaU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xaU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xaU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xaU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xaU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xaU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xa0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xaU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xaU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xaU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xaU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xaU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xaU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xaU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xaU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xaU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xaU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xa0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xaU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xaU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xbU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xbU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xbU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xbU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xbU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xbU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xbU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xbU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xbU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xbU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xb0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xbU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xbU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xbU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xbU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xbU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xbU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xbU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xbU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xbU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xbU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xb0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xbU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xbU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xcU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xcU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xcU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xcU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xcU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xcU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xcU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xcU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xcU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xcU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xc0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xcU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xcU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xcU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xcU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xcU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xcU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xcU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xcU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xcU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xcU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xc0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xcU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xcU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xdU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xdU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xdU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xdU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xdU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xdU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xdU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xdU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xdU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xdU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xd0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xdU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xdU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xdU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xdU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xdU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xdU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xdU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xdU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xdU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xdU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xd0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xdU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xdU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xeU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xeU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xeU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xeU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xeU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xeU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xeU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xeU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xeU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xeU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xe0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xeU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xeU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xeU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xeU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xeU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xeU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xeU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xeU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xeU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xeU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xe0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xeU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xeU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff = 0ULL;
    if ((((vlSelfRef.Top__DOT__res_from_icache[2U][8U] 
           >> 0xbU) & ((0x3fffffffU & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xfU][2U] 
                                        << 0xfU) | 
                                       (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                        [0xfU][1U] 
                                        >> 0x11U))) 
                       == (0x3fffffffU & ((vlSelfRef.Top__DOT__res_from_icache
                                           [2U][8U] 
                                           << 0x13U) 
                                          | (vlSelfRef.Top__DOT__res_from_icache
                                             [2U][7U] 
                                             >> 0xdU))))) 
         & (((vlSelfRef.Top__DOT__res_from_icache[2U][6U] 
              << 0x15U) | (vlSelfRef.Top__DOT__res_from_icache
                           [2U][5U] >> 0xbU)) == vlSelfRef.Top__DOT__generation))) {
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xfU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xfU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__res_from_icache
                                                      [2U][5U])) 
                                      << 0x25U) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][4U])) 
                                                    << 5U) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      >> 0x1bU))))) 
             & ((0x7fffffffffULL & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U])) 
                                     << 0x25U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xfU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xfU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xfU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((((QData)((IData)(
                                                        vlSelfRef.Top__DOT__res_from_icache
                                                        [2U][5U])) 
                                        << 0x25U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__res_from_icache
                                                         [2U][4U])) 
                                         << 5U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xfU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xfU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xfU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U] 
                = (IData)(((0x3fffffffffffffcULL & 
                            (((QData)((IData)(vlSelfRef.Top__DOT__res_from_icache
                                              [2U][3U])) 
                              << 0x1fU) | (0x7ffffffffffffffcULL 
                                           & ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][2U])) 
                                              >> 1U)))) 
                           | (QData)((IData)((3U & 
                                              (vlSelfRef.Top__DOT__res_from_icache
                                               [2U][5U] 
                                               >> 9U))))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (IData)((((0x3fffffffffffffcULL 
                                & (((QData)((IData)(
                                                    vlSelfRef.Top__DOT__res_from_icache
                                                    [2U][3U])) 
                                    << 0x1fU) | (0x7ffffffffffffffcULL 
                                                 & ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__res_from_icache
                                                                    [2U][2U])) 
                                                    >> 1U)))) 
                               | (QData)((IData)((3U 
                                                  & (vlSelfRef.Top__DOT__res_from_icache
                                                     [2U][5U] 
                                                     >> 9U))))) 
                              >> 0x20U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U]) 
                   | (0xfc000000U & (0xf0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[4U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_had59030b__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xfU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xfU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
        if ((((0x7fffffffffULL & (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                   [0xfU][1U])) 
                                   << 0x18U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                [0xfU][0U])) 
                                                >> 8U))) 
              <= (0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][5U])) 
                                              << 0x25U) 
                                             | (((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][4U])) 
                                                 << 5U) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   >> 0x1bU)))))) 
             & ((0x7fffffffffULL & (4ULL + (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__res_from_icache
                                                             [2U][5U])) 
                                             << 0x25U) 
                                            | (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][4U])) 
                                                << 5U) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__res_from_icache
                                                                  [2U][3U])) 
                                                  >> 0x1bU))))) 
                < (0x7fffffffffULL & (0x10ULL + (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                  [0xfU][1U])) 
                                                  << 0x38U) 
                                                 | (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                     [0xfU][1U])) 
                                                     << 0x18U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                                       [0xfU][0U])) 
                                                       >> 8U)))))))) {
            Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                = (0x7fffffffffULL & ((4ULL + (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][5U])) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][4U])) 
                                                   << 5U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__res_from_icache
                                                                     [2U][3U])) 
                                                     >> 0x1bU)))) 
                                      - (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                          [0xfU][1U])) 
                                          << 0x38U) 
                                         | (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                             [0xfU][1U])) 
                                             << 0x18U) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                                                               [0xfU][0U])) 
                                               >> 8U)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U] 
                = vlSelfRef.Top__DOT__res_from_icache
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((0xfffffffcU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | (3U & (vlSelfRef.Top__DOT__res_from_icache
                            [2U][5U] >> 9U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U] 
                = ((3U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U]) 
                   | ((IData)((0xffffffffffffffULL 
                               & (4ULL + (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__res_from_icache
                                                           [2U][3U])) 
                                           << 0x3dU) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__res_from_icache
                                                              [2U][3U])) 
                                              << 0x1dU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__res_from_icache
                                                                [2U][2U])) 
                                                >> 3U)))))) 
                      << 2U));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0xfc000000U & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (((IData)((0xffffffffffffffULL 
                                & (4ULL + (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__res_from_icache
                                                            [2U][3U])) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__res_from_icache
                                                               [2U][3U])) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__res_from_icache
                                                                 [2U][2U])) 
                                                 >> 3U)))))) 
                       >> 0x1eU) | ((IData)(((0xffffffffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__res_from_icache
                                                                   [2U][3U])) 
                                                   << 0x3dU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__res_from_icache
                                                                      [2U][3U])) 
                                                      << 0x1dU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__res_from_icache
                                                                        [2U][2U])) 
                                                        >> 3U))))) 
                                             >> 0x20U)) 
                                    << 2U)));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U] 
                = ((0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U]) 
                   | (0xfc000000U & (0xf0000000U | 
                                     (0xc000000U & 
                                      ((IData)((Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                >> 2U)) 
                                       << 0x1aU)))));
            vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U] 
                = (1U & (vlSelfRef.Top__DOT__res_from_icache
                         [2U][8U] >> 0xbU));
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][2U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[2U];
            vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word[5U][3U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT____Vlvbound_hdccc447a__0[3U];
            vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next[0xfU][0U] 
                = (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                   [0xfU][0U] | ((IData)(1U) << (3U 
                                                 & (IData)(
                                                           (Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__vaddr_diff 
                                                            >> 2U)))));
        }
    }
    Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 1U;
    if ((1U & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                >> 4U) & (~ vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                          [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U])))) {
        Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 0U;
    }
    if ((1U & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                >> 5U) & (~ (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                             [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                             >> 1U))))) {
        Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 0U;
    }
    if ((1U & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                >> 6U) & (~ (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                             [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                             >> 2U))))) {
        Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 0U;
    }
    if ((1U & ((vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                >> 7U) & (~ (vlSelfRef.Top__DOT__ifqueue__DOT__ifq_meta_next
                             [vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp][0U] 
                             >> 3U))))) {
        Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data = 0U;
    }
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[0U][0U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[0U][1U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[0U][2U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[1U][0U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[1U][1U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[1U][2U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[2U][0U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[2U][1U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[2U][2U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[3U][0U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[3U][1U] = 0U;
    vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[3U][2U] = 0U;
    if (((IData)(vlSelfRef.Top__DOT__flush_to_st3) 
         | (IData)(vlSelfRef.Top__DOT__stall_from_st5_to_st4))) {
        vlSelfRef.Top__DOT__ifqueue__DOT__new_ifq_read_exist = 0U;
    } else if ((((IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp) 
                 != (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_wp)) 
                & (IData)(Top__DOT__ifqueue__DOT__unnamedblk1__DOT__unnamedblk6__DOT__all_valid_entry_recieved_data))) {
        vlSelfRef.Top__DOT__ifqueue__DOT__new_ifq_read_exist = 1U;
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [0U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [0U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [0U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [0U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [0U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [0U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [0U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [0U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [0U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [0U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [0U][2U] >> 0x1aU))][2U]);
        }
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [1U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [1U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [1U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [1U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [1U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [1U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [1U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [1U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [1U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [1U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [1U][2U] >> 0x1aU))][2U]);
        }
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [2U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [2U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [2U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [2U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [2U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [2U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [2U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [2U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [2U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [2U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [2U][2U] >> 0x1aU))][2U]);
        }
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [3U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [3U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [3U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [3U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [3U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [3U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [3U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [3U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [3U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [3U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [3U][2U] >> 0x1aU))][2U]);
        }
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [4U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [4U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [4U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [4U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [4U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [4U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [4U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [4U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [4U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [4U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [4U][2U] >> 0x1aU))][2U]);
        }
        if ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
             [5U][3U] & ((vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                          [5U][2U] >> 0x1cU) == (IData)(vlSelfRef.Top__DOT__ifqueue__DOT__ifq_rp)))) {
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [5U][2U] 
                                                              >> 0x1aU))][0U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [5U][0U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [5U][2U] 
                                                              >> 0x1aU))][1U] 
                = vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                [5U][1U];
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [5U][2U] 
                                                              >> 0x1aU))][2U] 
                = ((0x4000000U & vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                    [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                            [5U][2U] >> 0x1aU))][2U]) 
                   | (0x3ffffffU & vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                      [5U][2U]));
            vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data[(3U 
                                                           & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                                                              [5U][2U] 
                                                              >> 0x1aU))][2U] 
                = (0x4000000U | vlSelfRef.Top__DOT__ifqueue__DOT__bypass_data
                   [(3U & (vlSelfRef.Top__DOT__ifqueue__DOT__cache_res_per_word
                           [5U][2U] >> 0x1aU))][2U]);
        }
    } else {
        vlSelfRef.Top__DOT__ifqueue__DOT__new_ifq_read_exist = 0U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][1U];
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[__Vilp1] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[__Vilp2] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[__Vilp3] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt
            [__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[__Vilp4] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt
            [__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][0U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][1U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][2U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][3U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][4U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][5U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[0U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[0U][4U] 
        = (0xffffff7fU & vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
           [0U][4U]);
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][0U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][1U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][2U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][3U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][4U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][5U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[1U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[1U][4U] 
        = (0xffffff7fU & vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
           [1U][4U]);
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][0U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][1U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][2U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][3U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][4U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][5U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[2U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[2U][4U] 
        = (0xffffff7fU & vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
           [2U][4U]);
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][0U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][1U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][2U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][3U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][4U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][5U] 
        = vlSymsp->TOP__Top__DOT__itlb_port.req[3U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache[3U][4U] 
        = (0xffffff7fU & vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
           [3U][4U]);
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_data
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[0U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [0U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[1U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [1U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[2U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [2U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data[3U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_data
        [3U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_data[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_data[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_data
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[0U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [0U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[1U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [1U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[2U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [2U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data[3U][1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_data
        [3U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__flush_to_pcgen = 0ULL;
    if ((1U & (IData)((vlSelfRef.Top__DOT__flush_from_ifq 
                       >> 0x27U)))) {
        vlSelfRef.Top__DOT__flush_to_pcgen = vlSelfRef.Top__DOT__flush_from_ifq;
    }
    if ((1U & (IData)((vlSelfRef.Top__DOT__flush_from_decoder 
                       >> 0x27U)))) {
        vlSelfRef.Top__DOT__flush_to_pcgen = vlSelfRef.Top__DOT__flush_from_decoder;
    }
    if ((1U & (IData)((vlSelfRef.Top__DOT__flush_from_renamer 
                       >> 0x27U)))) {
        vlSelfRef.Top__DOT__flush_to_pcgen = vlSelfRef.Top__DOT__flush_from_renamer;
    }
    vlSelfRef.Top__DOT__flush_to_st2 = (IData)(((vlSelfRef.Top__DOT__flush_from_ifq 
                                                 >> 0x27U) 
                                                | (IData)(vlSelfRef.Top__DOT__flush_to_st3)));
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 0ULL;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 0ULL;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] = 0ULL;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] = 0ULL;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] = 0ULL;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [0U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [0U]));
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] 
            = (0x8000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_mask
                                                      [1U])) 
                                      << 0x2eU) | vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data
                                     [1U]));
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[3U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[0U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [0U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[1U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [1U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[2U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [2U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_ram_idx[3U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [3U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[3U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[0U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [0U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[1U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [1U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[2U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [2U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_ram_idx[3U] 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_itlb_from_icache
                    [3U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [0U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [1U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [2U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_w_bit_data
        [3U][1U][2U];
    IData/*31:0*/ __Vilp5;
    __Vilp5 = 0U;
    while ((__Vilp5 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[__Vilp5] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt
            [__Vilp5];
        __Vilp5 = ((IData)(1U) + __Vilp5);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp6;
    __Vilp6 = 0U;
    while ((__Vilp6 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[__Vilp6] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt
            [__Vilp6];
        __Vilp6 = ((IData)(1U) + __Vilp6);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp7;
    __Vilp7 = 0U;
    while ((__Vilp7 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[__Vilp7] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt
            [__Vilp7];
        __Vilp7 = ((IData)(1U) + __Vilp7);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp8;
    __Vilp8 = 0U;
    while ((__Vilp8 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt_next[__Vilp8] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt
            [__Vilp8];
        __Vilp8 = ((IData)(1U) + __Vilp8);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp9;
    __Vilp9 = 0U;
    while ((__Vilp9 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__lvt_next[__Vilp9] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__lvt
            [__Vilp9];
        __Vilp9 = ((IData)(1U) + __Vilp9);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp10;
    __Vilp10 = 0U;
    while ((__Vilp10 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[__Vilp10] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt
            [__Vilp10];
        __Vilp10 = ((IData)(1U) + __Vilp10);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp11;
    __Vilp11 = 0U;
    while ((__Vilp11 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[__Vilp11] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt
            [__Vilp11];
        __Vilp11 = ((IData)(1U) + __Vilp11);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    IData/*31:0*/ __Vilp12;
    __Vilp12 = 0U;
    while ((__Vilp12 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__lvt_next[__Vilp12] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__lvt
            [__Vilp12];
        __Vilp12 = ((IData)(1U) + __Vilp12);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [0U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [1U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [2U][1U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][0U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][0U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][0U][2U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][1U][0U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][1U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_data[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_w_bit_data
        [3U][1U][2U];
    IData/*31:0*/ __Vilp13;
    __Vilp13 = 0U;
    while ((__Vilp13 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[__Vilp13] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt
            [__Vilp13];
        __Vilp13 = ((IData)(1U) + __Vilp13);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0ULL;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    IData/*31:0*/ __Vilp14;
    __Vilp14 = 0U;
    while ((__Vilp14 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[__Vilp14] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt
            [__Vilp14];
        __Vilp14 = ((IData)(1U) + __Vilp14);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0ULL;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    IData/*31:0*/ __Vilp15;
    __Vilp15 = 0U;
    while ((__Vilp15 <= 0x7fU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[__Vilp15] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt
            [__Vilp15];
        __Vilp15 = ((IData)(1U) + __Vilp15);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0ULL;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0ULL;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [0U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [0U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_mask
                                                      [1U])) 
                                      << 0x2cU) | vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_data
                                     [1U]));
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT____Vlvbound_ha9f720e6__0;
    }
    IData/*31:0*/ __Vilp16;
    __Vilp16 = 0U;
    while ((__Vilp16 <= 0x5bU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt_next[__Vilp16] 
            = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__lvt
            [__Vilp16];
        __Vilp16 = ((IData)(1U) + __Vilp16);
    }
}
