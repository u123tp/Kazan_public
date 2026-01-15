// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__28(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__28\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlUnpacked<VlWide<5>/*150:0*/, 4> Top__DOT__renamer__DOT__commitlog;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_ZERO_W(151, Top__DOT__renamer__DOT__commitlog[__Vi0]);
    }
    CData/*4:0*/ Top__DOT__renamer__DOT__unnamedblk7__DOT__unnamedblk8__DOT__pmp_result;
    Top__DOT__renamer__DOT__unnamedblk7__DOT__unnamedblk8__DOT__pmp_result = 0;
    IData/*31:0*/ Top__DOT__renamer__DOT__unnamedblk9__DOT__i;
    Top__DOT__renamer__DOT__unnamedblk9__DOT__i = 0;
    CData/*0:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0;
    CData/*0:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 0;
    IData/*31:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter = 0;
    CData/*0:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commitable;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commitable = 0;
    IData/*31:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0;
    VlWide<3>/*70:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result;
    VL_ZERO_W(71, Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result);
    QData/*63:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__minstret_next;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__minstret_next = 0;
    IData/*31:0*/ Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i = 0;
    QData/*63:0*/ Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val;
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<5>/*159:0*/ __Vtemp_5;
    CData/*31:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<7>/*223:0*/ __Vtemp_12;
    VlWide<13>/*415:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<7>/*223:0*/ __Vtemp_21;
    VlWide<13>/*415:0*/ __Vtemp_25;
    VlWide<6>/*191:0*/ __Vtemp_30;
    VlWide<6>/*191:0*/ __Vtemp_32;
    VlWide<13>/*415:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<7>/*223:0*/ __Vtemp_46;
    VlWide<13>/*415:0*/ __Vtemp_52;
    VlWide<13>/*415:0*/ __Vtemp_54;
    CData/*31:0*/ __Vtemp_55;
    VlWide<13>/*415:0*/ __Vtemp_56;
    VlWide<13>/*415:0*/ __Vtemp_58;
    std::string __Vtemp_71;
    // Body
    Top__DOT__renamer__DOT__unnamedblk7__DOT__unnamedblk8__DOT__pmp_result = 0U;
    if ((0x10U & vlSelfRef.Top__DOT__renamer__DOT__op_in
         [3U][8U])) {
        __Vtemp_2[1U] = ((0xff000000U & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][8U] 
                                          << 0x1cU) 
                                         | (0xf000000U 
                                            & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][7U] 
                                               >> 4U)))) 
                         | (IData)((((0xfffffffffe0000ULL 
                                      & (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                          [3U][7U])) 
                                          << 0x1cU) 
                                         | (0xffffffffffe0000ULL 
                                            & ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                               [3U][6U])) 
                                               >> 4U)))) 
                                     | (QData)((IData)(
                                                       ((0x1c000U 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                            [3U][4U] 
                                                            >> 0xcU)) 
                                                        | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                            [
                                                            (0x1fU 
                                                             & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][4U] 
                                                                >> 0x15U))] 
                                                            << 7U) 
                                                           | vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                           [
                                                           (0x1fU 
                                                            & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                               [3U][4U] 
                                                               >> 0x10U))]))))) 
                                    >> 0x20U)));
        __Vtemp_5[2U] = (((IData)(((0xfffffffffe0000ULL 
                                    & (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][7U])) 
                                        << 0x1cU) | 
                                       (0xffffffffffe0000ULL 
                                        & ((QData)((IData)(
                                                           vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                           [3U][6U])) 
                                           >> 4U)))) 
                                   | (QData)((IData)(
                                                     ((0x1c000U 
                                                       & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                          [3U][4U] 
                                                          >> 0xcU)) 
                                                      | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                          [
                                                          (0x1fU 
                                                           & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][4U] 
                                                              >> 0x15U))] 
                                                          << 7U) 
                                                         | vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                         [
                                                         (0x1fU 
                                                          & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                             [3U][4U] 
                                                             >> 0x10U))])))))) 
                          << 0xdU) | (((((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][4U] 
                                          >> 0x1aU) 
                                         & (0U != (0x1fU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                      [3U][4U] 
                                                      >> 0xbU))))
                                         ? (0x7fU & 
                                            vlSelfRef.Top__DOT__renamer__DOT__available_prd
                                            [3U]) : 0U) 
                                       << 6U) | ((IData)(
                                                         ((((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                            [3U][4U])) 
                                                            << 0x35U) 
                                                           | (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][3U])) 
                                                               << 0x15U) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][2U])) 
                                                                 >> 0xbU))) 
                                                          >> 0x20U)) 
                                                 >> 0x1aU)));
        __Vtemp_6 = (((((((((0x61U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][8U] 
                                                 << 4U) 
                                                | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][7U] 
                                                   >> 0x1cU)))) 
                            | (0x62U == (0xffU & ((
                                                   vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][8U] 
                                                   << 4U) 
                                                  | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                     [3U][7U] 
                                                     >> 0x1cU))))) 
                           | (0x63U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                  [3U][8U] 
                                                  << 4U) 
                                                 | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                    [3U][7U] 
                                                    >> 0x1cU))))) 
                          | (0x32U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][8U] 
                                                 << 4U) 
                                                | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][7U] 
                                                   >> 0x1cU))))) 
                         | (0x37U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][8U] 
                                                << 4U) 
                                               | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                  [3U][7U] 
                                                  >> 0x1cU))))) 
                        | (0x64U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][8U] 
                                               << 4U) 
                                              | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][7U] 
                                                 >> 0x1cU))))) 
                       | (0x35U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][8U] 
                                              << 4U) 
                                             | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][7U] 
                                                >> 0x1cU))))) 
                      | (0x36U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                             [3U][8U] 
                                             << 4U) 
                                            | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][7U] 
                                               >> 0x1cU))))) 
                     | (0x65U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                            [3U][8U] 
                                            << 4U) 
                                           | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][7U] 
                                              >> 0x1cU)))));
        if (__Vtemp_6) {
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][0U] = 0U;
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][1U] = 0U;
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][2U] = 0U;
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][3U] = 0U;
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][4U] = 0U;
        } else {
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][0U] 
                = (((IData)((((QData)((IData)(vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][4U])) 
                              << 0x35U) | (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                            [3U][3U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][2U])) 
                                              >> 0xbU)))) 
                    << 6U) | (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_wp_next));
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][1U] 
                = (((IData)((((QData)((IData)(vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][4U])) 
                              << 0x35U) | (((QData)((IData)(
                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                            [3U][3U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][2U])) 
                                              >> 0xbU)))) 
                    >> 0x1aU) | ((IData)(((((QData)((IData)(
                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                            [3U][4U])) 
                                            << 0x35U) 
                                           | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                               [3U][3U])) 
                                               << 0x15U) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                 [3U][2U])) 
                                                 >> 0xbU))) 
                                          >> 0x20U)) 
                                 << 6U));
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][2U] 
                = __Vtemp_5[2U];
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][3U] 
                = (((IData)(((0xfffffffffe0000ULL & 
                              (((QData)((IData)(vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][7U])) 
                                << 0x1cU) | (0xffffffffffe0000ULL 
                                             & ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][6U])) 
                                                >> 4U)))) 
                             | (QData)((IData)(((0x1c000U 
                                                 & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                    [3U][4U] 
                                                    >> 0xcU)) 
                                                | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                    [
                                                    (0x1fU 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][4U] 
                                                        >> 0x15U))] 
                                                    << 7U) 
                                                   | vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                   [
                                                   (0x1fU 
                                                    & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                       [3U][4U] 
                                                       >> 0x10U))])))))) 
                    >> 0x13U) | (__Vtemp_2[1U] << 0xdU));
            vlSelfRef.Top__DOT__renamer__DOT__op_out_next[3U][4U] 
                = (0x2000U | (__Vtemp_2[1U] >> 0x13U));
        }
        vlSymsp->TOP__Top__DOT__renamer_lsu_port.new_instr[3U] 
            = ((0x32U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                    [3U][8U] << 4U) 
                                   | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                      [3U][7U] >> 0x1cU))))
                ? (0x200000000000000ULL | ((0x1fffffffffc0000ULL 
                                            & (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][7U])) 
                                                << 0x1dU) 
                                               | (0x1ffffffffffc0000ULL 
                                                  & ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][6U])) 
                                                     >> 3U)))) 
                                           | (QData)((IData)(
                                                             (0xfU 
                                                              | (((IData)(vlSelfRef.Top__DOT__renamer__DOT__al_wp_next) 
                                                                  << 0xcU) 
                                                                 | (0xff0U 
                                                                    & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                        [3U][8U] 
                                                                        << 8U) 
                                                                       | (0xf0U 
                                                                          & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                             [3U][7U] 
                                                                             >> 0x18U))))))))))
                : (0x200000000000000ULL | ((0x1fffffffffc0000ULL 
                                            & (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][7U])) 
                                                << 0x1dU) 
                                               | (0x1ffffffffffc0000ULL 
                                                  & ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][6U])) 
                                                     >> 3U)))) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelfRef.Top__DOT__renamer__DOT__al_wp_next) 
                                                               << 0xcU) 
                                                              | (0xff0U 
                                                                 & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][8U] 
                                                                     << 8U) 
                                                                    | (0xf0U 
                                                                       & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                          [3U][7U] 
                                                                          >> 0x18U))))))))));
        __Vtemp_8[0U] = (2U | (((IData)((0x7fffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                             [3U][7U])) 
                                             << 0xbU) 
                                            | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                               [3U][6U])) 
                                               >> 0x15U)))) 
                                << 0x1eU) | (((0x3fc00000U 
                                               & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][8U] 
                                                   << 0x1aU) 
                                                  | (0x3c00000U 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][7U] 
                                                        >> 6U)))) 
                                              | ((0x200000U 
                                                  & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                     [3U][4U] 
                                                     >> 5U)) 
                                                 | (0x1f0000U 
                                                    & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                       [3U][4U] 
                                                       << 5U)))) 
                                             | ((((0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                       [3U][4U] 
                                                       >> 0xbU)))
                                                   ? 
                                                  (0x7fU 
                                                   & vlSelfRef.Top__DOT__renamer__DOT__available_prd
                                                   [3U])
                                                   : 0U) 
                                                 << 9U) 
                                                | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                    [
                                                    (0x1fU 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][4U] 
                                                        >> 0xbU))] 
                                                    << 2U) 
                                                   | (1U 
                                                      & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][2U] 
                                                         >> 0xaU)))))));
        __Vtemp_12[6U] = ((((IData)((0x7fffffffffULL 
                                     & (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][7U])) 
                                         << 0xbU) | 
                                        ((QData)((IData)(
                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][6U])) 
                                         >> 0x15U)))) 
                            >> 7U) | (0x6000000U & 
                                      ((IData)(((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][7U])) 
                                                     << 0xbU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][6U])) 
                                                       >> 0x15U))) 
                                                >> 0x20U)) 
                                       << 0x19U))) 
                          | (0xf8000000U & ((IData)(
                                                    ((0x7fffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                          [3U][7U])) 
                                                          << 0xbU) 
                                                         | ((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                            [3U][6U])) 
                                                            >> 0x15U))) 
                                                     >> 0x20U)) 
                                            << 0x19U)));
        __Vtemp_16[9U] = ((0x3ffc00U & ((IData)((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][1U])) 
                                                       >> 2U)))) 
                                        << 0xaU)) | 
                          (0xffc00000U & ((IData)((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][2U])) 
                                                       << 0x1eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                         [3U][1U])) 
                                                         >> 2U)))) 
                                          << 0xaU)));
        __Vtemp_16[0xaU] = (((0x3e0000U & (__Vtemp_8[0U] 
                                           << 0x11U)) 
                             | (((IData)((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][2U])) 
                                              << 0x1eU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][1U])) 
                                                >> 2U)))) 
                                 >> 0x16U) | (0x3ffc00U 
                                              & ((IData)(
                                                         ((0x7fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][2U])) 
                                                               << 0x1eU) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][1U])) 
                                                                 >> 2U))) 
                                                          >> 0x20U)) 
                                                 << 0xaU)))) 
                            | (0xffc00000U & (__Vtemp_8[0U] 
                                              << 0x11U)));
        __Vtemp_17[0U] = (2U | (((IData)((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][7U])) 
                                              << 0xbU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][6U])) 
                                                >> 0x15U)))) 
                                 << 0x1eU) | (((0x3fc00000U 
                                                & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                    [3U][8U] 
                                                    << 0x1aU) 
                                                   | (0x3c00000U 
                                                      & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][7U] 
                                                         >> 6U)))) 
                                               | ((0x200000U 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                      [3U][4U] 
                                                      >> 5U)) 
                                                  | (0x1f0000U 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][4U] 
                                                        << 5U)))) 
                                              | ((((0U 
                                                    != 
                                                    (0x1fU 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][4U] 
                                                        >> 0xbU)))
                                                    ? 
                                                   (0x7fU 
                                                    & vlSelfRef.Top__DOT__renamer__DOT__available_prd
                                                    [3U])
                                                    : 0U) 
                                                  << 9U) 
                                                 | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                                     [
                                                     (0x1fU 
                                                      & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][4U] 
                                                         >> 0xbU))] 
                                                     << 2U) 
                                                    | (1U 
                                                       & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                          [3U][2U] 
                                                          >> 0xaU)))))));
        __Vtemp_21[6U] = ((((IData)((0x7fffffffffULL 
                                     & (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][7U])) 
                                         << 0xbU) | 
                                        ((QData)((IData)(
                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                         [3U][6U])) 
                                         >> 0x15U)))) 
                            >> 7U) | (0x6000000U & 
                                      ((IData)(((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][7U])) 
                                                     << 0xbU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][6U])) 
                                                       >> 0x15U))) 
                                                >> 0x20U)) 
                                       << 0x19U))) 
                          | (0xf8000000U & ((IData)(
                                                    ((0x7fffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                          [3U][7U])) 
                                                          << 0xbU) 
                                                         | ((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                            [3U][6U])) 
                                                            >> 0x15U))) 
                                                     >> 0x20U)) 
                                            << 0x19U)));
        __Vtemp_25[9U] = ((0x3ffc00U & ((IData)((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][1U])) 
                                                       >> 2U)))) 
                                        << 0xaU)) | 
                          (0xffc00000U & ((IData)((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][2U])) 
                                                       << 0x1eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                         [3U][1U])) 
                                                         >> 2U)))) 
                                          << 0xaU)));
        __Vtemp_25[0xaU] = (((0x3e0000U & (__Vtemp_17[0U] 
                                           << 0x11U)) 
                             | (((IData)((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][2U])) 
                                              << 0x1eU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][1U])) 
                                                >> 2U)))) 
                                 >> 0x16U) | (0x3ffc00U 
                                              & ((IData)(
                                                         ((0x7fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][2U])) 
                                                               << 0x1eU) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][1U])) 
                                                                 >> 2U))) 
                                                          >> 0x20U)) 
                                                 << 0xaU)))) 
                            | (0xffc00000U & (__Vtemp_17[0U] 
                                              << 0x11U)));
        __Vtemp_30[4U] = ((0x7ffU & ((IData)((0x7fffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                  [3U][2U])) 
                                                  << 0x1eU) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                    [3U][1U])) 
                                                    >> 2U)))) 
                                     >> 0xcU)) | ((0x8000000U 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                      [3U][2U] 
                                                      << 0x11U)) 
                                                  | ((0xff800U 
                                                      & ((IData)(
                                                                 (0x7fffffffffULL 
                                                                  & (((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][2U])) 
                                                                      << 0x1eU) 
                                                                     | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][1U])) 
                                                                        >> 2U)))) 
                                                         >> 0xcU)) 
                                                     | ((IData)(
                                                                ((0x7fffffffffULL 
                                                                  & (((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][2U])) 
                                                                      << 0x1eU) 
                                                                     | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][1U])) 
                                                                        >> 2U))) 
                                                                 >> 0x20U)) 
                                                        << 0x14U))));
        __Vtemp_32[5U] = ((0x1fe0000U & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][8U] 
                                          << 0x15U) 
                                         | (0x1e0000U 
                                            & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][7U] 
                                               >> 0xbU)))) 
                          | (0x7ffU & ((IData)(((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][1U])) 
                                                       >> 2U))) 
                                                >> 0x20U)) 
                                       >> 0xcU)));
        __Vtemp_37[0xbU] = (((0x3f8000U & ((IData)(
                                                   (0x7fffffffffULL 
                                                    & (((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                        [3U][7U])) 
                                                        << 0xbU) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                          [3U][6U])) 
                                                          >> 0x15U)))) 
                                           << 0xfU)) 
                             | (__Vtemp_32[5U] >> 0xaU)) 
                            | (0xffc00000U & ((IData)(
                                                      (0x7fffffffffULL 
                                                       & (((QData)((IData)(
                                                                           vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                           [3U][7U])) 
                                                           << 0xbU) 
                                                          | ((QData)((IData)(
                                                                             vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                             [3U][6U])) 
                                                             >> 0x15U)))) 
                                              << 0xfU)));
        __Vtemp_41[2U] = ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                           [(0x1fU & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                      [3U][4U] >> 0xbU))] 
                           << 0x12U) | ((0x10000U & 
                                         (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][2U] 
                                          << 6U)) | 
                                        (((IData)((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][2U])) 
                                                       << 0x1eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                         [3U][1U])) 
                                                         >> 2U)))) 
                                          >> 0x17U) 
                                         | ((IData)(
                                                    ((0x7fffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                          [3U][2U])) 
                                                          << 0x1eU) 
                                                         | ((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                            [3U][1U])) 
                                                            >> 2U))) 
                                                     >> 0x20U)) 
                                            << 9U))));
        __Vtemp_46[5U] = (((IData)((0x7fffffffffULL 
                                    & (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][7U])) 
                                        << 0xbU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][6U])) 
                                        >> 0x15U)))) 
                           << 0x19U) | ((0xfffff800U 
                                         & ((0x1fe0000U 
                                             & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][8U] 
                                                 << 0x15U) 
                                                | (0x1e0000U 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                      [3U][7U] 
                                                      >> 0xbU)))) 
                                            | ((0x10000U 
                                                & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][4U] 
                                                   >> 0xaU)) 
                                               | (0xf800U 
                                                  & vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                  [3U][4U])))) 
                                        | ((0x7f0U 
                                            & (((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                     [3U][4U] 
                                                     >> 0xbU)))
                                                 ? 
                                                (0x7fU 
                                                 & vlSelfRef.Top__DOT__renamer__DOT__available_prd
                                                 [3U])
                                                 : 0U) 
                                               << 4U)) 
                                           | (__Vtemp_41[2U] 
                                              >> 0x15U))));
        __Vtemp_52[9U] = ((0x3ffc00U & ((IData)((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][1U])) 
                                                       >> 2U)))) 
                                        << 0xaU)) | 
                          (0xffc00000U & ((IData)((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][2U])) 
                                                       << 0x1eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                         [3U][1U])) 
                                                         >> 2U)))) 
                                          << 0xaU)));
        if ((0x37U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                 [3U][8U] << 4U) | 
                                (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                 [3U][7U] >> 0x1cU))))) {
            __Vtemp_54[2U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                              [3U][0U] << 0x1aU);
            __Vtemp_54[8U] = 0U;
            __Vtemp_54[0xaU] = ((__Vtemp_30[4U] >> 0xaU) 
                                | (__Vtemp_32[5U] << 0x16U));
            __Vtemp_54[0xbU] = __Vtemp_37[0xbU];
            __Vtemp_54[0xcU] = (((IData)((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][7U])) 
                                              << 0xbU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][6U])) 
                                                >> 0x15U)))) 
                                 >> 0x11U) | (0x3f8000U 
                                              & ((IData)(
                                                         ((0x7fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][7U])) 
                                                               << 0xbU) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][6U])) 
                                                                 >> 0x15U))) 
                                                          >> 0x20U)) 
                                                 << 0xfU)));
        } else {
            __Vtemp_54[2U] = ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                               [3U][0U] << 0x1aU) | 
                              ((0xffffc000U & ((0x3000000U 
                                                & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][4U] 
                                                   >> 3U)) 
                                               | (0xffc000U 
                                                  & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                     [3U][4U] 
                                                     >> 2U)))) 
                               | ((vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                   [(0x1fU & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][4U] 
                                              >> 0x15U))] 
                                   << 7U) | vlSelfRef.Top__DOT__renamer__DOT__rat_next
                                  [(0x1fU & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                             [3U][4U] 
                                             >> 0x10U))])));
            __Vtemp_54[8U] = 0U;
            __Vtemp_54[0xaU] = (((1U & ((IData)((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                     [3U][2U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                       [3U][1U])) 
                                                       >> 2U)))) 
                                        >> 0x16U)) 
                                 | (0x3ffffeU & (__Vtemp_41[2U] 
                                                 << 1U))) 
                                | (__Vtemp_46[5U] << 0x16U));
            __Vtemp_54[0xbU] = ((__Vtemp_46[5U] >> 0xaU) 
                                | (0xffc00000U & ((IData)(
                                                          (0x7fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][7U])) 
                                                               << 0xbU) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][6U])) 
                                                                 >> 0x15U)))) 
                                                  << 0xfU)));
            __Vtemp_54[0xcU] = (((IData)((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                              [3U][7U])) 
                                              << 0xbU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                [3U][6U])) 
                                                >> 0x15U)))) 
                                 >> 0x11U) | (0x3f8000U 
                                              & ((IData)(
                                                         ((0x7fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][7U])) 
                                                               << 0xbU) 
                                                              | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][6U])) 
                                                                 >> 0x15U))) 
                                                          >> 0x20U)) 
                                                 << 0xfU)));
        }
        __Vtemp_55 = (((((0x61U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][8U] 
                                              << 4U) 
                                             | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][7U] 
                                                >> 0x1cU)))) 
                         | (0x62U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][8U] 
                                                << 4U) 
                                               | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                  [3U][7U] 
                                                  >> 0x1cU))))) 
                        | (0x63U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][8U] 
                                               << 4U) 
                                              | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][7U] 
                                                 >> 0x1cU))))) 
                       | (0x32U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                              [3U][8U] 
                                              << 4U) 
                                             | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                [3U][7U] 
                                                >> 0x1cU))))) 
                      | (0x64U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                             [3U][8U] 
                                             << 4U) 
                                            | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][7U] 
                                               >> 0x1cU)))));
        if (__Vtemp_55) {
            __Vtemp_56[5U] = ((0x2000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                             [3U][1U] 
                                             << 0x18U)) 
                              | (0x1000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][1U] 
                                               << 0x18U)));
            __Vtemp_56[6U] = 0U;
        } else {
            __Vtemp_56[5U] = ((0x37U == (0xffU & ((
                                                   vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][8U] 
                                                   << 4U) 
                                                  | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                     [3U][7U] 
                                                     >> 0x1cU))))
                               ? ((0x2000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][1U] 
                                                 << 0x18U)) 
                                  | (0x1000000U & (
                                                   vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][1U] 
                                                   << 0x18U)))
                               : ((0x2000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                 [3U][1U] 
                                                 << 0x18U)) 
                                  | (0x1000000U & (
                                                   vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                   [3U][1U] 
                                                   << 0x18U))));
            __Vtemp_56[6U] = 0U;
        }
        if ((((0x65U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                   [3U][8U] << 4U) 
                                  | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                     [3U][7U] >> 0x1cU)))) 
              | (0x35U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                     [3U][8U] << 4U) 
                                    | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                       [3U][7U] >> 0x1cU))))) 
             | (0x36U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                    [3U][8U] << 4U) 
                                   | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                      [3U][7U] >> 0x1cU)))))) {
            __Vtemp_58[0U] = 0U;
            __Vtemp_58[1U] = 0U;
            __Vtemp_58[2U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                              [3U][0U] << 0x1aU);
            __Vtemp_58[3U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                              [3U][0U] >> 6U);
            __Vtemp_58[4U] = 0U;
            __Vtemp_58[5U] = ((0x2000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                             [3U][1U] 
                                             << 0x18U)) 
                              | (0x1000000U & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                               [3U][1U] 
                                               << 0x18U)));
            __Vtemp_58[6U] = 0U;
            __Vtemp_58[7U] = 0U;
            __Vtemp_58[8U] = 1U;
            __Vtemp_58[9U] = __Vtemp_16[9U];
            __Vtemp_58[0xbU] = (((__Vtemp_8[0U] >> 0xfU) 
                                 | (0x3e0000U & ((IData)(
                                                         (0x7fffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                              [3U][7U])) 
                                                              << 0xbU) 
                                                             | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][6U])) 
                                                                >> 0x15U)))) 
                                                 << 0xfU))) 
                                | (__Vtemp_12[6U] << 0x16U));
        } else if (__Vtemp_55) {
            __Vtemp_58[0U] = 0U;
            __Vtemp_58[1U] = 0U;
            __Vtemp_58[2U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                              [3U][0U] << 0x1aU);
            __Vtemp_58[3U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                              [3U][0U] >> 6U);
            __Vtemp_58[4U] = 0U;
            __Vtemp_58[5U] = __Vtemp_56[5U];
            __Vtemp_58[6U] = __Vtemp_56[6U];
            __Vtemp_58[7U] = 0U;
            __Vtemp_58[8U] = 0U;
            __Vtemp_58[9U] = __Vtemp_25[9U];
            __Vtemp_58[0xbU] = (((__Vtemp_17[0U] >> 0xfU) 
                                 | (0x3e0000U & ((IData)(
                                                         (0x7fffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                              [3U][7U])) 
                                                              << 0xbU) 
                                                             | ((QData)((IData)(
                                                                                vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                                [3U][6U])) 
                                                                >> 0x15U)))) 
                                                 << 0xfU))) 
                                | (__Vtemp_21[6U] << 0x16U));
        } else {
            __Vtemp_58[0U] = 0U;
            __Vtemp_58[1U] = 0U;
            __Vtemp_58[2U] = __Vtemp_54[2U];
            if ((0x37U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                     [3U][8U] << 4U) 
                                    | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                       [3U][7U] >> 0x1cU))))) {
                __Vtemp_58[3U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                  [3U][0U] >> 6U);
                __Vtemp_58[4U] = 0U;
                __Vtemp_58[5U] = __Vtemp_56[5U];
                __Vtemp_58[6U] = __Vtemp_56[6U];
                __Vtemp_58[7U] = 0U;
                __Vtemp_58[8U] = __Vtemp_54[8U];
                __Vtemp_58[9U] = ((0x3ffc00U & ((IData)(
                                                        (0x7fffffffffULL 
                                                         & (((QData)((IData)(
                                                                             vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                             [3U][2U])) 
                                                             << 0x1eU) 
                                                            | ((QData)((IData)(
                                                                               vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                               [3U][1U])) 
                                                               >> 2U)))) 
                                                << 0xaU)) 
                                  | (__Vtemp_30[4U] 
                                     << 0x16U));
            } else {
                __Vtemp_58[3U] = (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                  [3U][0U] >> 6U);
                __Vtemp_58[4U] = 0U;
                __Vtemp_58[5U] = __Vtemp_56[5U];
                __Vtemp_58[6U] = __Vtemp_56[6U];
                __Vtemp_58[7U] = 0U;
                __Vtemp_58[8U] = __Vtemp_54[8U];
                __Vtemp_58[9U] = __Vtemp_52[9U];
            }
            __Vtemp_58[0xbU] = __Vtemp_54[0xbU];
        }
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][0U] 
            = __Vtemp_58[0U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][1U] 
            = __Vtemp_58[1U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][2U] 
            = __Vtemp_58[2U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][3U] 
            = __Vtemp_58[3U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][4U] 
            = __Vtemp_58[4U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][5U] 
            = __Vtemp_58[5U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][6U] 
            = __Vtemp_58[6U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][7U] 
            = __Vtemp_58[7U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][8U] 
            = __Vtemp_58[8U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][9U] 
            = __Vtemp_58[9U];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][0xaU] 
            = ((((0x65U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                      [3U][8U] << 4U) 
                                     | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                        [3U][7U] >> 0x1cU)))) 
                 | (0x35U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                        [3U][8U] << 4U) 
                                       | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][7U] 
                                          >> 0x1cU))))) 
                | (0x36U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                       [3U][8U] << 4U) 
                                      | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                         [3U][7U] >> 0x1cU)))))
                ? __Vtemp_16[0xaU] : (__Vtemp_55 ? 
                                      __Vtemp_25[0xaU]
                                       : __Vtemp_54[0xaU]));
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][0xbU] 
            = __Vtemp_58[0xbU];
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][0xcU] 
            = ((((0x65U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                      [3U][8U] << 4U) 
                                     | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                        [3U][7U] >> 0x1cU)))) 
                 | (0x35U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                        [3U][8U] << 4U) 
                                       | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                          [3U][7U] 
                                          >> 0x1cU))))) 
                | (0x36U == (0xffU & ((vlSelfRef.Top__DOT__renamer__DOT__op_in
                                       [3U][8U] << 4U) 
                                      | (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                         [3U][7U] >> 0x1cU)))))
                ? (__Vtemp_12[6U] >> 0xaU) : (__Vtemp_55
                                               ? (__Vtemp_21[6U] 
                                                  >> 0xaU)
                                               : __Vtemp_54[0xcU]));
        if (VL_UNLIKELY((([&]() {
                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_exe = 0U;
                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_write = 0U;
                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_read = 1U;
                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__current_priv 
                                = vlSelfRef.Top__DOT__priv__DOT__current_priv;
                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__target_paddr 
                                = (0xffffffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                       [3U][6U])) 
                                       << 0x23U) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                        [3U][5U])) 
                                        << 3U) | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                                  [3U][4U])) 
                                                  >> 0x1dU))));
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__L = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__A = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__X = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__W = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__R = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist = 0;
                            vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result = 0;
                            {
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i = 0U;
                                {
                                    while ((0x40U > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg 
                                            = (0xffU 
                                               & (IData)(
                                                         (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpcfg_rdata
                                                          [
                                                          (7U 
                                                           & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i 
                                                              >> 3U))] 
                                                          >> 
                                                          (0x38U 
                                                           & VL_SHIFTL_III(6,32,32, vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i, 3U)))));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__L 
                                            = (1U & 
                                               ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                >> 7U));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__A 
                                            = (3U & 
                                               ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                >> 3U));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__X 
                                            = (1U & 
                                               ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                >> 2U));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__W 
                                            = (1U & 
                                               ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                >> 1U));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__R 
                                            = (1U & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg));
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0U;
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0xffffffffffffffffULL;
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0U;
                                                {
                                                    while (
                                                           (0x36U 
                                                            > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(
                                                                          (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                           [
                                                                           (0x3fU 
                                                                            & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)] 
                                                                           >> 
                                                                           (0x3fU 
                                                                            & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)))))) {
                                                            goto __Vlabel220;
                                                        }
                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter 
                                                            = 
                                                            ((IData)(1U) 
                                                             + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter);
                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask 
                                                            = 
                                                            ((~ 
                                                              (1ULL 
                                                               << 
                                                               (0x3fU 
                                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j))) 
                                                             & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask);
                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j 
                                                            = 
                                                            ((IData)(1U) 
                                                             + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j);
                                                    }
                                                    __Vlabel220: ;
                                                }
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & VL_SHIFTL_QQI(56,64,32, 
                                                                     (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                      [
                                                                      (0x3fU 
                                                                       & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)] 
                                                                      & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask), 2U));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                        + 
                                                        VL_SHIFTL_QQI(56,56,32, 1ULL, 
                                                                      ((IData)(2U) 
                                                                       + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter))));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist = 1U;
                                            } else {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & VL_SHIFTL_QQI(56,64,32, 
                                                                     vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                     [
                                                                     (0x3fU 
                                                                      & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)], 2U));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & (4ULL 
                                                        + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist = 1U;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                = (
                                                   (0U 
                                                    == vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)
                                                    ? 0ULL
                                                    : 
                                                   (0xffffffffffffffULL 
                                                    & VL_SHIFTL_QQI(56,64,32, 
                                                                    vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                    [
                                                                    (0x3fU 
                                                                     & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i 
                                                                        - (IData)(1U)))], 2U)));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                = (0xffffffffffffffULL 
                                                   & VL_SHIFTL_QQI(56,64,32, 
                                                                   vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                   [
                                                                   (0x3fU 
                                                                    & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i)], 2U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist = 1U;
                                        } else {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0ULL;
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0ULL;
                                        }
                                        if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                              <= vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__target_paddr) 
                                             & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__target_paddr 
                                                < vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr))) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result 
                                                = (0x10U 
                                                   | ((((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__R) 
                                                        << 3U) 
                                                       | ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__W) 
                                                          << 2U)) 
                                                      | (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__X) 
                                                          << 1U) 
                                                         | (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__unnamedblk2__DOT__L))));
                                            goto __Vlabel219;
                                        }
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i 
                                            = ((IData)(1U) 
                                               + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__unnamedblk1__DOT__i);
                                    }
                                    __Vlabel219: ;
                                }
                                if ((1U & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_exist)))) {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 0U;
                                    goto __Vlabel218;
                                }
                                if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result) 
                                              >> 4U)))) {
                                    if ((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__current_priv))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 0U;
                                        goto __Vlabel218;
                                    } else {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 1U;
                                        goto __Vlabel218;
                                    }
                                }
                                if (((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__current_priv)) 
                                     & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result)))) {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 0U;
                                    goto __Vlabel218;
                                }
                                if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_read) 
                                     & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result) 
                                           >> 3U)))) {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 1U;
                                    goto __Vlabel218;
                                }
                                if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_write) 
                                     & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result) 
                                           >> 2U)))) {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 1U;
                                    goto __Vlabel218;
                                }
                                if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__is_exe) 
                                     & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__pmp_result) 
                                           >> 1U)))) {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 1U;
                                    goto __Vlabel218;
                                }
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout = 0U;
                                __Vlabel218: ;
                            }
                        }(), (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__6__Vfuncout))))) {
            VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,979] pmp_result:%b\n",0,
                         5,Top__DOT__renamer__DOT__unnamedblk7__DOT__unnamedblk8__DOT__pmp_result);
            vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][5U] 
                = (0x1000000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                   [vlSelfRef.Top__DOT__renamer__DOT__al_wp_next][5U]);
        }
        vlSelfRef.Top__DOT__renamer__DOT__al_wp_next 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_wp_next)));
        vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next 
            = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next)));
        if (((vlSelfRef.Top__DOT__renamer__DOT__op_in
              [3U][4U] >> 0x1aU) & (0U != (0x1fU & 
                                           (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                            [3U][4U] 
                                            >> 0xbU))))) {
            vlSelfRef.Top__DOT__renamer__DOT__rat_next[(0x1fU 
                                                        & (vlSelfRef.Top__DOT__renamer__DOT__op_in
                                                           [3U][4U] 
                                                           >> 0xbU))] 
                = vlSelfRef.Top__DOT__renamer__DOT__available_prd
                [3U];
            vlSelfRef.Top__DOT__renamer__DOT__prd_used[3U] = 1U;
        } else {
            vlSelfRef.Top__DOT__renamer__DOT__prd_used[3U] = 0U;
        }
    }
    Top__DOT__renamer__DOT__unnamedblk9__DOT__i = 0U;
    while ((7U > Top__DOT__renamer__DOT__unnamedblk9__DOT__i)) {
        vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx = 0U;
        if ((vlSelfRef.Top__DOT__result_op2[((6U >= 
                                              (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                              ? (7U 
                                                 & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                              : 0U)][6U] 
             >> 0x1fU)) {
            vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx 
                = (0x3fU & (vlSelfRef.Top__DOT__result_op2
                            [((6U >= (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                               ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                               : 0U)][3U] >> 2U));
            if (([&]() {
                        vlSelfRef.__Vfunc_is_amo_opcode__7__opcode 
                            = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                        >> 7U));
                        vlSelfRef.__Vfunc_is_amo_opcode__7__Vfuncout 
                            = ((((((((((((((((((0x4dU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode)) 
                                               | (0x4eU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                              | (0x4fU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                             | (0x50U 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                            | (0x51U 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                           | (0x52U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                          | (0x53U 
                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                         | (0x54U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                        | (0x55U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                       | (0x58U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                      | (0x59U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                     | (0x5aU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                    | (0x5bU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                   | (0x5cU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                  | (0x5dU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                 | (0x5eU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                                | (0x5fU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode))) 
                               | (0x60U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__opcode)));
                    }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__7__Vfuncout))) {
                if ((0x200000U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                     [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][5U])) {
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU] 
                        = (0x40000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU]);
                } else {
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][5U] 
                        = (0x200000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][5U]);
                }
            } else {
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU] 
                    = (0x40000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                       [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU]);
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][9U] 
                    = ((0xfffffdffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][9U]) 
                       | (0x200U & (vlSelfRef.Top__DOT__result_op2
                                    [((6U >= (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                       ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                       : 0U)][3U] << 8U)));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][8U] 
                    = ((3U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][8U]) 
                       | ((IData)((0x7fffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__result_op2
                                                       [
                                                       ((6U 
                                                         >= 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                         ? 
                                                        (7U 
                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                         : 0U)][3U])) 
                                       << 0x26U) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__result_op2
                                                        [
                                                        ((6U 
                                                          >= 
                                                          (7U 
                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                          ? 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                          : 0U)][2U])) 
                                        << 6U) | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__result_op2
                                                                  [
                                                                  ((6U 
                                                                    >= 
                                                                    (7U 
                                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                    ? 
                                                                   (7U 
                                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                    : 0U)][1U])) 
                                                  >> 0x1aU))))) 
                          << 2U));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][9U] 
                    = ((0xfffffe00U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][9U]) 
                       | (((IData)((0x7fffffffffULL 
                                    & (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__result_op2
                                                        [
                                                        ((6U 
                                                          >= 
                                                          (7U 
                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                          ? 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                          : 0U)][3U])) 
                                        << 0x26U) | 
                                       (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__result_op2
                                                         [
                                                         ((6U 
                                                           >= 
                                                           (7U 
                                                            & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                           ? 
                                                          (7U 
                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                           : 0U)][2U])) 
                                         << 6U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__result_op2
                                                                   [
                                                                   ((6U 
                                                                     >= 
                                                                     (7U 
                                                                      & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                     ? 
                                                                    (7U 
                                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                     : 0U)][1U])) 
                                                   >> 0x1aU))))) 
                           >> 0x1eU) | ((IData)(((0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__result_op2
                                                                      [
                                                                      ((6U 
                                                                        >= 
                                                                        (7U 
                                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                        ? 
                                                                       (7U 
                                                                        & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                        : 0U)][3U])) 
                                                      << 0x26U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__result_op2
                                                                         [
                                                                         ((6U 
                                                                           >= 
                                                                           (7U 
                                                                            & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                           ? 
                                                                          (7U 
                                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                           : 0U)][2U])) 
                                                         << 6U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.Top__DOT__result_op2
                                                                           [
                                                                           ((6U 
                                                                             >= 
                                                                             (7U 
                                                                              & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                             ? 
                                                                            (7U 
                                                                             & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                             : 0U)][1U])) 
                                                           >> 0x1aU)))) 
                                                 >> 0x20U)) 
                                        << 2U)));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                    = ((0x1fffffffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]) 
                       | ((IData)((0xffffffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__result_op2
                                                       [
                                                       ((6U 
                                                         >= 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                         ? 
                                                        (7U 
                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                         : 0U)][1U])) 
                                       << 0x1eU) | 
                                      ((QData)((IData)(
                                                       vlSelfRef.Top__DOT__result_op2
                                                       [
                                                       ((6U 
                                                         >= 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                         ? 
                                                        (7U 
                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                         : 0U)][0U])) 
                                       >> 2U)))) << 0x1dU));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][4U] 
                    = (((IData)((0xffffffffffffffULL 
                                 & (((QData)((IData)(
                                                     vlSelfRef.Top__DOT__result_op2
                                                     [
                                                     ((6U 
                                                       >= 
                                                       (7U 
                                                        & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                       ? 
                                                      (7U 
                                                       & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                       : 0U)][1U])) 
                                     << 0x1eU) | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__result_op2
                                                                  [
                                                                  ((6U 
                                                                    >= 
                                                                    (7U 
                                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                    ? 
                                                                   (7U 
                                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                    : 0U)][0U])) 
                                                  >> 2U)))) 
                        >> 3U) | ((IData)(((0xffffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelfRef.Top__DOT__result_op2
                                                                [
                                                                ((6U 
                                                                  >= 
                                                                  (7U 
                                                                   & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                  ? 
                                                                 (7U 
                                                                  & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                  : 0U)][1U])) 
                                                << 0x1eU) 
                                               | ((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__result_op2
                                                                  [
                                                                  ((6U 
                                                                    >= 
                                                                    (7U 
                                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                    ? 
                                                                   (7U 
                                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                    : 0U)][0U])) 
                                                  >> 2U))) 
                                           >> 0x20U)) 
                                  << 0x1dU));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][5U] 
                    = ((0xffe00000U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][5U]) 
                       | ((IData)(((0xffffffffffffffULL 
                                    & (((QData)((IData)(
                                                        vlSelfRef.Top__DOT__result_op2
                                                        [
                                                        ((6U 
                                                          >= 
                                                          (7U 
                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                          ? 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                          : 0U)][1U])) 
                                        << 0x1eU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.Top__DOT__result_op2
                                                        [
                                                        ((6U 
                                                          >= 
                                                          (7U 
                                                           & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                          ? 
                                                         (7U 
                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                          : 0U)][0U])) 
                                        >> 2U))) >> 0x20U)) 
                          >> 3U));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0U] 
                    = (IData)((((QData)((IData)(vlSelfRef.Top__DOT__result_op2
                                                [((6U 
                                                   >= 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                   ? 
                                                  (7U 
                                                   & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                   : 0U)][5U])) 
                                << 0x38U) | (((QData)((IData)(
                                                              vlSelfRef.Top__DOT__result_op2
                                                              [
                                                              ((6U 
                                                                >= 
                                                                (7U 
                                                                 & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                ? 
                                                               (7U 
                                                                & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                : 0U)][4U])) 
                                              << 0x18U) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__result_op2
                                                                [
                                                                ((6U 
                                                                  >= 
                                                                  (7U 
                                                                   & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                  ? 
                                                                 (7U 
                                                                  & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                  : 0U)][3U])) 
                                                >> 8U))));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][1U] 
                    = (IData)(((((QData)((IData)(vlSelfRef.Top__DOT__result_op2
                                                 [(
                                                   (6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][5U])) 
                                 << 0x38U) | (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__result_op2
                                                               [
                                                               ((6U 
                                                                 >= 
                                                                 (7U 
                                                                  & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                 ? 
                                                                (7U 
                                                                 & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                 : 0U)][4U])) 
                                               << 0x18U) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.Top__DOT__result_op2
                                                                 [
                                                                 ((6U 
                                                                   >= 
                                                                   (7U 
                                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                   ? 
                                                                  (7U 
                                                                   & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                   : 0U)][3U])) 
                                                 >> 8U))) 
                               >> 0x20U));
                if ((((1U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                             [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU] 
                             >> 0x11U)) != (1U & (vlSelfRef.Top__DOT__result_op2
                                                  [
                                                  ((6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][3U] 
                                                  >> 1U))) 
                     | (((vlSelfRef.Top__DOT__renamer__DOT__al_next
                          [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU] 
                          >> 0x11U) & (vlSelfRef.Top__DOT__result_op2
                                       [((6U >= (7U 
                                                 & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                          ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                          : 0U)][3U] 
                                       >> 1U)) & ((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xaU])) 
                                                       << 0x16U) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                         [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][9U])) 
                                                         >> 0xaU))) 
                                                  != 
                                                  (0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__result_op2
                                                                       [
                                                                       ((6U 
                                                                         >= 
                                                                         (7U 
                                                                          & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                         ? 
                                                                        (7U 
                                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                         : 0U)][3U])) 
                                                       << 0x26U) 
                                                      | (((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__result_op2
                                                                          [
                                                                          ((6U 
                                                                            >= 
                                                                            (7U 
                                                                             & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                            ? 
                                                                           (7U 
                                                                            & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                            : 0U)][2U])) 
                                                          << 6U) 
                                                         | ((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__result_op2
                                                                            [
                                                                            ((6U 
                                                                              >= 
                                                                              (7U 
                                                                               & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                                              ? 
                                                                             (7U 
                                                                              & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                                              : 0U)][1U])) 
                                                            >> 0x1aU)))))))) {
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][8U] 
                        = (2U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][8U]);
                }
                if ((((([&]() {
                                        vlSelfRef.__Vfunc_is_jmp_opcode__8__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                  >> 7U));
                                        vlSelfRef.__Vfunc_is_jmp_opcode__8__Vfuncout 
                                            = ((0x2eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__8__opcode)) 
                                               | (0x2fU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__8__opcode)));
                                    }(), (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__8__Vfuncout)) 
                       | ([&]() {
                                        vlSelfRef.__Vfunc_is_branch_opcode__9__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                  >> 7U));
                                        vlSelfRef.__Vfunc_is_branch_opcode__9__Vfuncout 
                                            = (((((
                                                   (0x28U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode)) 
                                                   | (0x29U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode))) 
                                                  | (0x2aU 
                                                     == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode))) 
                                                 | (0x2bU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode))) 
                                                | (0x2cU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode))) 
                                               | (0x2dU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__opcode)));
                                    }(), (IData)(vlSelfRef.__Vfunc_is_branch_opcode__9__Vfuncout))) 
                      & (vlSelfRef.Top__DOT__result_op2
                         [((6U >= (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                            ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                            : 0U)][3U] >> 1U)) & (0U 
                                                  != 
                                                  (3U 
                                                   & (vlSelfRef.Top__DOT__result_op2
                                                      [
                                                      ((6U 
                                                        >= 
                                                        (7U 
                                                         & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                        ? 
                                                       (7U 
                                                        & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                        : 0U)][1U] 
                                                      >> 0x1aU))))) {
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                        = (0x4000000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                }
                if (([&]() {
                            vlSelfRef.__Vfunc_is_ld_opcode__10__opcode 
                                = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                            >> 7U));
                            vlSelfRef.__Vfunc_is_ld_opcode__10__Vfuncout 
                                = (((((((((0x1dU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode)) 
                                          | (0x1eU 
                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                         | (0x1fU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                        | (0x20U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                       | (0x21U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                      | (0x22U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                     | (0x23U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                    | (0x4bU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode))) 
                                   | (0x56U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__opcode)));
                        }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__10__Vfuncout))) {
                    if ((1U | ((((1U == ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 8U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 8U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 8U;
                                                                        goto __Vlabel221;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                        goto __Vlabel221;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                    goto __Vlabel221;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                        goto __Vlabel221;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                        goto __Vlabel221;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                goto __Vlabel221;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                goto __Vlabel221;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                goto __Vlabel221;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 8U;
                                                                        goto __Vlabel221;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                        goto __Vlabel221;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 2U;
                                                                    goto __Vlabel221;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 1U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                    goto __Vlabel221;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 2U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 1U;
                                                                goto __Vlabel221;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 8U;
                                                                goto __Vlabel221;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 4U;
                                                                            goto __Vlabel221;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 2U;
                                                                            goto __Vlabel221;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__11__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 1U;
                                                                        goto __Vlabel221;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                        goto __Vlabel221;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                    goto __Vlabel221;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                                goto __Vlabel221;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout = 0U;
                                                            goto __Vlabel221;
                                                        }
                                                        __Vlabel221: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__11__Vfuncout)) 
                                 | (2U == ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 8U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 8U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 8U;
                                                                        goto __Vlabel222;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                        goto __Vlabel222;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                    goto __Vlabel222;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                        goto __Vlabel222;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                        goto __Vlabel222;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                goto __Vlabel222;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                goto __Vlabel222;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                goto __Vlabel222;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 8U;
                                                                        goto __Vlabel222;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                        goto __Vlabel222;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 2U;
                                                                    goto __Vlabel222;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 1U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                    goto __Vlabel222;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 2U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 1U;
                                                                goto __Vlabel222;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 8U;
                                                                goto __Vlabel222;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 4U;
                                                                            goto __Vlabel222;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 2U;
                                                                            goto __Vlabel222;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__12__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 1U;
                                                                        goto __Vlabel222;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                        goto __Vlabel222;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                    goto __Vlabel222;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                                goto __Vlabel222;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout = 0U;
                                                            goto __Vlabel222;
                                                        }
                                                        __Vlabel222: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__12__Vfuncout))) 
                                | (4U == ([&]() {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode 
                                                    = 
                                                    (0xffU 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                        >> 7U));
                                                {
                                                    if (
                                                        (0x80U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                    } else if (
                                                               (0x40U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                        if (
                                                            (0x20U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 8U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 8U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 8U;
                                                                    goto __Vlabel223;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                    goto __Vlabel223;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (4U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                goto __Vlabel223;
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                    goto __Vlabel223;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                    goto __Vlabel223;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                            goto __Vlabel223;
                                                        }
                                                    } else if (
                                                               (0x20U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                            goto __Vlabel223;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                            goto __Vlabel223;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 8U;
                                                                    goto __Vlabel223;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                    goto __Vlabel223;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 2U;
                                                                goto __Vlabel223;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 1U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                goto __Vlabel223;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 2U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 1U;
                                                            goto __Vlabel223;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 8U;
                                                            goto __Vlabel223;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                            if (
                                                                (4U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 4U;
                                                                        goto __Vlabel223;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 2U;
                                                                        goto __Vlabel223;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__13__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 1U;
                                                                    goto __Vlabel223;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                    goto __Vlabel223;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                                goto __Vlabel223;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                            goto __Vlabel223;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout = 0U;
                                                        goto __Vlabel223;
                                                    }
                                                    __Vlabel223: ;
                                                }
                                            }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__13__Vfuncout))) 
                               | (8U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 8U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 8U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 8U;
                                                                goto __Vlabel224;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                                goto __Vlabel224;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                            goto __Vlabel224;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                                goto __Vlabel224;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                                goto __Vlabel224;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                        goto __Vlabel224;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                        goto __Vlabel224;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                        goto __Vlabel224;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 8U;
                                                                goto __Vlabel224;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                                goto __Vlabel224;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 2U;
                                                            goto __Vlabel224;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 1U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                            goto __Vlabel224;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 2U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 1U;
                                                        goto __Vlabel224;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 8U;
                                                        goto __Vlabel224;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 4U;
                                                                    goto __Vlabel224;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 2U;
                                                                    goto __Vlabel224;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__14__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 1U;
                                                                goto __Vlabel224;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                                goto __Vlabel224;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                            goto __Vlabel224;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                        goto __Vlabel224;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout = 0U;
                                                    goto __Vlabel224;
                                                }
                                                __Vlabel224: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__14__Vfuncout))))) {
                        if ((1U != ([&]() {
                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                  >> 7U));
                                        {
                                            if ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                            } else if (
                                                       (0x40U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                if (
                                                    (0x20U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 8U;
                                                        goto __Vlabel225;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 8U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 8U;
                                                            goto __Vlabel225;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                            goto __Vlabel225;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                        goto __Vlabel225;
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                        goto __Vlabel225;
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                            goto __Vlabel225;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                            goto __Vlabel225;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                    goto __Vlabel225;
                                                }
                                            } else if (
                                                       (0x20U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                    goto __Vlabel225;
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                    goto __Vlabel225;
                                                } else if (
                                                           (4U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 8U;
                                                            goto __Vlabel225;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                            goto __Vlabel225;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 2U;
                                                        goto __Vlabel225;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 1U;
                                                        goto __Vlabel225;
                                                    }
                                                } else if (
                                                           (2U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                        goto __Vlabel225;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 2U;
                                                        goto __Vlabel225;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 1U;
                                                    goto __Vlabel225;
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 8U;
                                                    goto __Vlabel225;
                                                }
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 4U;
                                                                goto __Vlabel225;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 2U;
                                                                goto __Vlabel225;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__15__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 1U;
                                                            goto __Vlabel225;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                            goto __Vlabel225;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                        goto __Vlabel225;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                    goto __Vlabel225;
                                                }
                                            } else {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout = 0U;
                                                goto __Vlabel225;
                                            }
                                            __Vlabel225: ;
                                        }
                                    }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__15__Vfuncout))) {
                            if ((2U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 8U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 8U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 8U;
                                                                goto __Vlabel226;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                                goto __Vlabel226;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                            goto __Vlabel226;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                                goto __Vlabel226;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                                goto __Vlabel226;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                        goto __Vlabel226;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                        goto __Vlabel226;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                        goto __Vlabel226;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 8U;
                                                                goto __Vlabel226;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                                goto __Vlabel226;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 2U;
                                                            goto __Vlabel226;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 1U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                            goto __Vlabel226;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 2U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 1U;
                                                        goto __Vlabel226;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 8U;
                                                        goto __Vlabel226;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 4U;
                                                                    goto __Vlabel226;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 2U;
                                                                    goto __Vlabel226;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__16__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 1U;
                                                                goto __Vlabel226;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                                goto __Vlabel226;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                            goto __Vlabel226;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                        goto __Vlabel226;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout = 0U;
                                                    goto __Vlabel226;
                                                }
                                                __Vlabel226: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__16__Vfuncout))) {
                                if ((4U & vlSelfRef.Top__DOT__result_op2
                                     [((6U >= (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                        ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                        : 0U)][0U])) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else if ((4U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 8U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 8U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 8U;
                                                                goto __Vlabel227;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                                goto __Vlabel227;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                            goto __Vlabel227;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                                goto __Vlabel227;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                                goto __Vlabel227;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                        goto __Vlabel227;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                        goto __Vlabel227;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                        goto __Vlabel227;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 8U;
                                                                goto __Vlabel227;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                                goto __Vlabel227;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 2U;
                                                            goto __Vlabel227;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 1U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                            goto __Vlabel227;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 2U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 1U;
                                                        goto __Vlabel227;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 8U;
                                                        goto __Vlabel227;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 4U;
                                                                    goto __Vlabel227;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 2U;
                                                                    goto __Vlabel227;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__17__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 1U;
                                                                goto __Vlabel227;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                                goto __Vlabel227;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                            goto __Vlabel227;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                        goto __Vlabel227;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout = 0U;
                                                    goto __Vlabel227;
                                                }
                                                __Vlabel227: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__17__Vfuncout))) {
                                if ((0U != (3U & (vlSelfRef.Top__DOT__result_op2
                                                  [
                                                  ((6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][0U] 
                                                  >> 2U)))) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else if (VL_LIKELY(((8U 
                                                   == 
                                                   ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 8U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 8U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 8U;
                                                                        goto __Vlabel228;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                        goto __Vlabel228;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                    goto __Vlabel228;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                        goto __Vlabel228;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                        goto __Vlabel228;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                goto __Vlabel228;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                goto __Vlabel228;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                goto __Vlabel228;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 8U;
                                                                        goto __Vlabel228;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                        goto __Vlabel228;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 2U;
                                                                    goto __Vlabel228;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 1U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                    goto __Vlabel228;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 2U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 1U;
                                                                goto __Vlabel228;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 8U;
                                                                goto __Vlabel228;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 4U;
                                                                            goto __Vlabel228;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 2U;
                                                                            goto __Vlabel228;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__18__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 1U;
                                                                        goto __Vlabel228;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                        goto __Vlabel228;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                    goto __Vlabel228;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                                goto __Vlabel228;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout = 0U;
                                                            goto __Vlabel228;
                                                        }
                                                        __Vlabel228: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__18__Vfuncout))))) {
                                if ((0U != (7U & (vlSelfRef.Top__DOT__result_op2
                                                  [
                                                  ((6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][0U] 
                                                  >> 2U)))) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else {
                                VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,1068]\n",0);
                            }
                        }
                    }
                }
                if ((([&]() {
                                vlSelfRef.__Vfunc_is_st_opcode__19__opcode 
                                    = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_st_opcode__19__Vfuncout 
                                    = ((((((0x24U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode)) 
                                           | (0x25U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode))) 
                                          | (0x26U 
                                             == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode))) 
                                         | (0x27U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode))) 
                                        | (0x4cU == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode))) 
                                       | (0x57U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__19__Vfuncout)) 
                     | ([&]() {
                                vlSelfRef.__Vfunc_is_amo_opcode__20__opcode 
                                    = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_amo_opcode__20__Vfuncout 
                                    = (((((((((((((
                                                   (((((0x4dU 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode)) 
                                                       | (0x4eU 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                      | (0x4fU 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                     | (0x50U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                    | (0x51U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                   | (0x52U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                  | (0x53U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                 | (0x54U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                                | (0x55U 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                               | (0x58U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                              | (0x59U 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                             | (0x5aU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                            | (0x5bU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                           | (0x5cU 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                          | (0x5dU 
                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                         | (0x5eU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                        | (0x5fU == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode))) 
                                       | (0x60U == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__20__Vfuncout)))) {
                    if ((1U | ((((1U == ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 8U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 8U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 8U;
                                                                        goto __Vlabel229;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                        goto __Vlabel229;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                    goto __Vlabel229;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                        goto __Vlabel229;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                        goto __Vlabel229;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                goto __Vlabel229;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                goto __Vlabel229;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                goto __Vlabel229;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 8U;
                                                                        goto __Vlabel229;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                        goto __Vlabel229;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 2U;
                                                                    goto __Vlabel229;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 1U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                    goto __Vlabel229;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 2U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 1U;
                                                                goto __Vlabel229;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 8U;
                                                                goto __Vlabel229;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 4U;
                                                                            goto __Vlabel229;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 2U;
                                                                            goto __Vlabel229;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__21__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 1U;
                                                                        goto __Vlabel229;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                        goto __Vlabel229;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                    goto __Vlabel229;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                                goto __Vlabel229;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout = 0U;
                                                            goto __Vlabel229;
                                                        }
                                                        __Vlabel229: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__21__Vfuncout)) 
                                 | (2U == ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 8U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 8U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 8U;
                                                                        goto __Vlabel230;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                        goto __Vlabel230;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                    goto __Vlabel230;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                        goto __Vlabel230;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                        goto __Vlabel230;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                goto __Vlabel230;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                goto __Vlabel230;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                goto __Vlabel230;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 8U;
                                                                        goto __Vlabel230;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                        goto __Vlabel230;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 2U;
                                                                    goto __Vlabel230;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 1U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                    goto __Vlabel230;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 2U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 1U;
                                                                goto __Vlabel230;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 8U;
                                                                goto __Vlabel230;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 4U;
                                                                            goto __Vlabel230;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 2U;
                                                                            goto __Vlabel230;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__22__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 1U;
                                                                        goto __Vlabel230;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                        goto __Vlabel230;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                    goto __Vlabel230;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                                goto __Vlabel230;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout = 0U;
                                                            goto __Vlabel230;
                                                        }
                                                        __Vlabel230: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__22__Vfuncout))) 
                                | (4U == ([&]() {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode 
                                                    = 
                                                    (0xffU 
                                                     & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                        >> 7U));
                                                {
                                                    if (
                                                        (0x80U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                    } else if (
                                                               (0x40U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                        if (
                                                            (0x20U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 8U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 8U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 8U;
                                                                    goto __Vlabel231;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                    goto __Vlabel231;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (4U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                goto __Vlabel231;
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                    goto __Vlabel231;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                    goto __Vlabel231;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                            goto __Vlabel231;
                                                        }
                                                    } else if (
                                                               (0x20U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                            goto __Vlabel231;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                            goto __Vlabel231;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 8U;
                                                                    goto __Vlabel231;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                    goto __Vlabel231;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 2U;
                                                                goto __Vlabel231;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 1U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                goto __Vlabel231;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 2U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 1U;
                                                            goto __Vlabel231;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 8U;
                                                            goto __Vlabel231;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                            if (
                                                                (4U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 4U;
                                                                        goto __Vlabel231;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 2U;
                                                                        goto __Vlabel231;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__23__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 1U;
                                                                    goto __Vlabel231;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                    goto __Vlabel231;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                                goto __Vlabel231;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                            goto __Vlabel231;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout = 0U;
                                                        goto __Vlabel231;
                                                    }
                                                    __Vlabel231: ;
                                                }
                                            }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__23__Vfuncout))) 
                               | (8U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 8U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 8U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 8U;
                                                                goto __Vlabel232;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                                goto __Vlabel232;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                            goto __Vlabel232;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                                goto __Vlabel232;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                                goto __Vlabel232;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                        goto __Vlabel232;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                        goto __Vlabel232;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                        goto __Vlabel232;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 8U;
                                                                goto __Vlabel232;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                                goto __Vlabel232;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 2U;
                                                            goto __Vlabel232;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 1U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                            goto __Vlabel232;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 2U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 1U;
                                                        goto __Vlabel232;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 8U;
                                                        goto __Vlabel232;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 4U;
                                                                    goto __Vlabel232;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 2U;
                                                                    goto __Vlabel232;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__24__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 1U;
                                                                goto __Vlabel232;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                                goto __Vlabel232;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                            goto __Vlabel232;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                        goto __Vlabel232;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout = 0U;
                                                    goto __Vlabel232;
                                                }
                                                __Vlabel232: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__24__Vfuncout))))) {
                        if ((1U != ([&]() {
                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                  >> 7U));
                                        {
                                            if ((0x80U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                            } else if (
                                                       (0x40U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                if (
                                                    (0x20U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 8U;
                                                        goto __Vlabel233;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 8U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 8U;
                                                            goto __Vlabel233;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                            goto __Vlabel233;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                        goto __Vlabel233;
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                        goto __Vlabel233;
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                            goto __Vlabel233;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                            goto __Vlabel233;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                    goto __Vlabel233;
                                                }
                                            } else if (
                                                       (0x20U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                    goto __Vlabel233;
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                    goto __Vlabel233;
                                                } else if (
                                                           (4U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 8U;
                                                            goto __Vlabel233;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                            goto __Vlabel233;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 2U;
                                                        goto __Vlabel233;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 1U;
                                                        goto __Vlabel233;
                                                    }
                                                } else if (
                                                           (2U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                        goto __Vlabel233;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 2U;
                                                        goto __Vlabel233;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 1U;
                                                    goto __Vlabel233;
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 8U;
                                                    goto __Vlabel233;
                                                }
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 4U;
                                                                goto __Vlabel233;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 2U;
                                                                goto __Vlabel233;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__25__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 1U;
                                                            goto __Vlabel233;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                            goto __Vlabel233;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                        goto __Vlabel233;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                    goto __Vlabel233;
                                                }
                                            } else {
                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout = 0U;
                                                goto __Vlabel233;
                                            }
                                            __Vlabel233: ;
                                        }
                                    }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__25__Vfuncout))) {
                            if ((2U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 8U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 8U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 8U;
                                                                goto __Vlabel234;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                                goto __Vlabel234;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                            goto __Vlabel234;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                                goto __Vlabel234;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                                goto __Vlabel234;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                        goto __Vlabel234;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                        goto __Vlabel234;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                        goto __Vlabel234;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 8U;
                                                                goto __Vlabel234;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                                goto __Vlabel234;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 2U;
                                                            goto __Vlabel234;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 1U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                            goto __Vlabel234;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 2U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 1U;
                                                        goto __Vlabel234;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 8U;
                                                        goto __Vlabel234;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 4U;
                                                                    goto __Vlabel234;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 2U;
                                                                    goto __Vlabel234;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__26__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 1U;
                                                                goto __Vlabel234;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                                goto __Vlabel234;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                            goto __Vlabel234;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                        goto __Vlabel234;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout = 0U;
                                                    goto __Vlabel234;
                                                }
                                                __Vlabel234: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__26__Vfuncout))) {
                                if ((4U & vlSelfRef.Top__DOT__result_op2
                                     [((6U >= (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                        ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                        : 0U)][0U])) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else if ((4U == ([&]() {
                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                      >> 7U));
                                            {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                } else if (
                                                           (0x40U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 8U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 8U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 8U;
                                                                goto __Vlabel235;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                                goto __Vlabel235;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                            goto __Vlabel235;
                                                        } else if (
                                                                   (2U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                                goto __Vlabel235;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                                goto __Vlabel235;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                        goto __Vlabel235;
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                        goto __Vlabel235;
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                        goto __Vlabel235;
                                                    } else if (
                                                               (4U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (2U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            if (
                                                                (1U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 8U;
                                                                goto __Vlabel235;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                                goto __Vlabel235;
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 2U;
                                                            goto __Vlabel235;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 1U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else if (
                                                               (2U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                            goto __Vlabel235;
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 2U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 1U;
                                                        goto __Vlabel235;
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 8U;
                                                        goto __Vlabel235;
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                        if (
                                                            (4U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                            if (
                                                                (2U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 4U;
                                                                    goto __Vlabel235;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 2U;
                                                                    goto __Vlabel235;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__27__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 1U;
                                                                goto __Vlabel235;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                                goto __Vlabel235;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                            goto __Vlabel235;
                                                        }
                                                    } else {
                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                        goto __Vlabel235;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout = 0U;
                                                    goto __Vlabel235;
                                                }
                                                __Vlabel235: ;
                                            }
                                        }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__27__Vfuncout))) {
                                if ((0U != (3U & (vlSelfRef.Top__DOT__result_op2
                                                  [
                                                  ((6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][0U] 
                                                  >> 2U)))) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else if (VL_LIKELY(((8U 
                                                   == 
                                                   ([&]() {
                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][0xbU] 
                                                            >> 7U));
                                                    {
                                                        if (
                                                            (0x80U 
                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                        } else if (
                                                                   (0x40U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                            if (
                                                                (0x20U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 8U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else if (
                                                                       (0x10U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 8U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 8U;
                                                                        goto __Vlabel236;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                        goto __Vlabel236;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                    goto __Vlabel236;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                        goto __Vlabel236;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                        goto __Vlabel236;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                goto __Vlabel236;
                                                            }
                                                        } else if (
                                                                   (0x20U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                goto __Vlabel236;
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                goto __Vlabel236;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 8U;
                                                                        goto __Vlabel236;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                        goto __Vlabel236;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 2U;
                                                                    goto __Vlabel236;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 1U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else if (
                                                                       (2U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                    goto __Vlabel236;
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 2U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 1U;
                                                                goto __Vlabel236;
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 8U;
                                                                goto __Vlabel236;
                                                            }
                                                        } else if (
                                                                   (0x10U 
                                                                    & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                            if (
                                                                (8U 
                                                                 & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                if (
                                                                    (4U 
                                                                     & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 4U;
                                                                            goto __Vlabel236;
                                                                        } else {
                                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 2U;
                                                                            goto __Vlabel236;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelfRef.__Vfunc_get_data_size_from_opcode__28__opcode))) {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 1U;
                                                                        goto __Vlabel236;
                                                                    } else {
                                                                        vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                        goto __Vlabel236;
                                                                    }
                                                                } else {
                                                                    vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                    goto __Vlabel236;
                                                                }
                                                            } else {
                                                                vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                                goto __Vlabel236;
                                                            }
                                                        } else {
                                                            vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout = 0U;
                                                            goto __Vlabel236;
                                                        }
                                                        __Vlabel236: ;
                                                    }
                                                }(), vlSelfRef.__Vfunc_get_data_size_from_opcode__28__Vfuncout))))) {
                                if ((0U != (7U & (vlSelfRef.Top__DOT__result_op2
                                                  [
                                                  ((6U 
                                                    >= 
                                                    (7U 
                                                     & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                                    ? 
                                                   (7U 
                                                    & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                                    : 0U)][0U] 
                                                  >> 2U)))) {
                                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                                        = (0x4000000U 
                                           | vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]);
                                }
                            } else {
                                VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,1095]\n",0);
                            }
                        }
                    }
                }
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                    = ((0xefffffffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]) 
                       | (0x10000000U & (vlSelfRef.Top__DOT__result_op2
                                         [((6U >= (7U 
                                                   & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                            ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                            : 0U)][0U] 
                                         << 0x1bU)));
                vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U] 
                    = ((0xf7ffffffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                        [vlSelfRef.Top__DOT__renamer__DOT__unnamedblk9__DOT__unnamedblk10__DOT__al_idx][3U]) 
                       | (0x8000000U & (vlSelfRef.Top__DOT__result_op2
                                        [((6U >= (7U 
                                                  & Top__DOT__renamer__DOT__unnamedblk9__DOT__i))
                                           ? (7U & Top__DOT__renamer__DOT__unnamedblk9__DOT__i)
                                           : 0U)][0U] 
                                        << 0x1bU)));
            }
        }
        Top__DOT__renamer__DOT__unnamedblk9__DOT__i 
            = ((IData)(1U) + Top__DOT__renamer__DOT__unnamedblk9__DOT__i);
    }
    if (((0x37U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                             [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                             >> 7U))) & (IData)(vlSelfRef.Top__DOT__fence_i_done))) {
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
            = (0x40000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU]);
    }
    if (vlSymsp->TOP__Top__DOT__renamer_lsu_port.ld_speculative_feedback_valid) {
        vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSymsp->TOP__Top__DOT__renamer_lsu_port.ld_speculative_feedback_al_idx][5U] 
            = (0x800000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
               [vlSymsp->TOP__Top__DOT__renamer_lsu_port.ld_speculative_feedback_al_idx][5U]);
    }
    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commitable = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U] = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U] = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[2U] = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__minstret_next 
        = vlSymsp->TOP__Top__DOT__csr_renamer_port.minstret_rdata;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.committed_instr[0U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.committed_instr[1U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.committed_instr[2U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.committed_instr[3U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[0U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[1U] = 0U;
    vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[2U] = 0U;
    vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr[0U] = 0U;
    vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr[1U] = 0U;
    vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr[2U] = 0U;
    vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr[3U] = 0U;
    vlSymsp->TOP__Top__DOT__csru_renamer_port.executable_csr = 0U;
    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[0U] = 0U;
    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[1U] = 0U;
    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U] = 0U;
    vlSelfRef.Top__DOT__is_taken_feedback_to_pred[0U] = 0ULL;
    vlSelfRef.Top__DOT__is_taken_feedback_to_pred[1U] = 0ULL;
    vlSelfRef.Top__DOT__is_taken_feedback_to_pred[2U] = 0ULL;
    vlSelfRef.Top__DOT__is_taken_feedback_to_pred[3U] = 0ULL;
    vlSelfRef.Top__DOT__flush_from_renamer = 0ULL;
    vlSelfRef.Top__DOT__priv_w = 3U;
    vlSelfRef.Top__DOT__flush_tlb = 0U;
    Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i = 0U;
    {
        while ((4U > Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)) {
            Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commitable 
                = (1U & ((~ ([&]() {
                                vlSelfRef.__Vfunc_is_st_opcode__29__opcode 
                                    = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_st_opcode__29__Vfuncout 
                                    = ((((((0x24U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode)) 
                                           | (0x25U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode))) 
                                          | (0x26U 
                                             == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode))) 
                                         | (0x27U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode))) 
                                        | (0x4cU == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode))) 
                                       | (0x57U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__29__Vfuncout))) 
                         | ((1U > Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter) 
                            & (~ (IData)(vlSelfRef.Top__DOT__stall_out_from_dcache)))));
            if ((((0U < (IData)(vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next)) 
                  & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                     >> 0x12U)) & (IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commitable))) {
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[1U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][1U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][3U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][4U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[6U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[7U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[8U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[9U] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xaU] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU] 
                    = vlSelfRef.Top__DOT__renamer__DOT__al_next
                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU];
                vlSelf->__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit = 0;
                vlSelf->__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 0;
                VL_ZERO_RESET_W(71, vlSelf->__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result);
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] = 0U;
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] = 0U;
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0U;
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1aU) & (([&]() {
                                    vlSelfRef.__Vfunc_is_st_opcode__31__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_st_opcode__31__Vfuncout 
                                        = ((((((0x24U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode)) 
                                               | (0x25U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode))) 
                                              | (0x26U 
                                                 == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode))) 
                                             | (0x27U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode))) 
                                            | (0x4cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode))) 
                                           | (0x57U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__31__Vfuncout)) 
                                   & ([&]() {
                                    vlSelfRef.__Vfunc_is_amo_opcode__32__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_amo_opcode__32__Vfuncout 
                                        = (((((((((
                                                   (((((((((0x4dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode)) 
                                                           | (0x4eU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                          | (0x4fU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                         | (0x50U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                        | (0x51U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                       | (0x52U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                      | (0x53U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                     | (0x54U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                    | (0x55U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                   | (0x58U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                  | (0x59U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                 | (0x5aU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                                | (0x5bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                               | (0x5cU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                              | (0x5dU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                             | (0x5eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                            | (0x5fU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode))) 
                                           | (0x60U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__32__Vfuncout))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,56, 
                                                (0xffffffffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,56, 
                                                 (0xffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x46U;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1aU) & ([&]() {
                                vlSelfRef.__Vfunc_is_ld_opcode__33__opcode 
                                    = (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_ld_opcode__33__Vfuncout 
                                    = (((((((((0x1dU 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode)) 
                                              | (0x1eU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                             | (0x1fU 
                                                == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                            | (0x20U 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                           | (0x21U 
                                              == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                          | (0x22U 
                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                         | (0x23U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                        | (0x4bU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode))) 
                                       | (0x56U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__33__Vfuncout)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,56, 
                                                (0xffffffffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,56, 
                                                 (0xffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x44U;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1bU) & (([&]() {
                                    vlSelfRef.__Vfunc_is_st_opcode__34__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_st_opcode__34__Vfuncout 
                                        = ((((((0x24U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode)) 
                                               | (0x25U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode))) 
                                              | (0x26U 
                                                 == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode))) 
                                             | (0x27U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode))) 
                                            | (0x4cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode))) 
                                           | (0x57U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__34__Vfuncout)) 
                                   | ([&]() {
                                    vlSelfRef.__Vfunc_is_amo_opcode__35__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_amo_opcode__35__Vfuncout 
                                        = (((((((((
                                                   (((((((((0x4dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode)) 
                                                           | (0x4eU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                          | (0x4fU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                         | (0x50U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                        | (0x51U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                       | (0x52U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                      | (0x53U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                     | (0x54U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                    | (0x55U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                   | (0x58U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                  | (0x59U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                 | (0x5aU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                                | (0x5bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                               | (0x5cU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                              | (0x5dU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                             | (0x5eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                            | (0x5fU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode))) 
                                           | (0x60U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__35__Vfuncout))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,56, 
                                                (0xffffffffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,56, 
                                                 (0xffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x47U;
                }
                if (((([&]() {
                                    vlSelfRef.__Vfunc_is_st_opcode__36__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_st_opcode__36__Vfuncout 
                                        = ((((((0x24U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode)) 
                                               | (0x25U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode))) 
                                              | (0x26U 
                                                 == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode))) 
                                             | (0x27U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode))) 
                                            | (0x4cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode))) 
                                           | (0x57U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__36__Vfuncout)) 
                      | ([&]() {
                                    vlSelfRef.__Vfunc_is_amo_opcode__37__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_amo_opcode__37__Vfuncout 
                                        = (((((((((
                                                   (((((((((0x4dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode)) 
                                                           | (0x4eU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                          | (0x4fU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                         | (0x50U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                        | (0x51U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                       | (0x52U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                      | (0x53U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                     | (0x54U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                    | (0x55U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                   | (0x58U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                  | (0x59U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                 | (0x5aU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                                | (0x5bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                               | (0x5cU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                              | (0x5dU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                             | (0x5eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                            | (0x5fU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode))) 
                                           | (0x60U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__37__Vfuncout))) 
                     & ([&]() {
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_exe = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_write = 1U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_read = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__current_priv 
                                    = vlSelfRef.Top__DOT__priv__DOT__current_priv;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__target_paddr 
                                    = (0xffffffffffffffULL 
                                       & (((QData)((IData)(
                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                           << 0x23U) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                              << 3U) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                >> 0x1dU))));
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__L = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__A = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__X = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__W = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__R = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result = 0;
                                {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist = 0U;
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result = 0U;
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i = 0U;
                                    {
                                        while ((0x40U 
                                                > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg 
                                                = (0xffU 
                                                   & (IData)(
                                                             (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpcfg_rdata
                                                              [
                                                              (7U 
                                                               & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i 
                                                                  >> 3U))] 
                                                              >> 
                                                              (0x38U 
                                                               & VL_SHIFTL_III(6,32,32, vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i, 3U)))));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__L 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__A 
                                                = (3U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 3U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__X 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 2U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__W 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 1U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__R 
                                                = (1U 
                                                   & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0U;
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0xffffffffffffffffULL;
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0U;
                                                    {
                                                        while (
                                                               (0x36U 
                                                                > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(
                                                                              (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                               [
                                                                               (0x3fU 
                                                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)] 
                                                                               >> 
                                                                               (0x3fU 
                                                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)))))) {
                                                                goto __Vlabel240;
                                                            }
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter 
                                                                = 
                                                                ((IData)(1U) 
                                                                 + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter);
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask 
                                                                = 
                                                                ((~ 
                                                                  (1ULL 
                                                                   << 
                                                                   (0x3fU 
                                                                    & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j))) 
                                                                 & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask);
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j 
                                                                = 
                                                                ((IData)(1U) 
                                                                 + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j);
                                                        }
                                                        __Vlabel240: ;
                                                    }
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & VL_SHIFTL_QQI(56,64,32, 
                                                                         (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                          [
                                                                          (0x3fU 
                                                                           & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)] 
                                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask), 2U));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                            + 
                                                            VL_SHIFTL_QQI(56,56,32, 1ULL, 
                                                                          ((IData)(2U) 
                                                                           + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter))));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist = 1U;
                                                } else {
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & VL_SHIFTL_QQI(56,64,32, 
                                                                         vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                         [
                                                                         (0x3fU 
                                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)], 2U));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & (4ULL 
                                                            + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                    = 
                                                    ((0U 
                                                      == vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)
                                                      ? 0ULL
                                                      : 
                                                     (0xffffffffffffffULL 
                                                      & VL_SHIFTL_QQI(56,64,32, 
                                                                      vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                      [
                                                                      (0x3fU 
                                                                       & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i 
                                                                          - (IData)(1U)))], 2U)));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & VL_SHIFTL_QQI(56,64,32, 
                                                                     vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                     [
                                                                     (0x3fU 
                                                                      & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i)], 2U));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist = 1U;
                                            } else {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0ULL;
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0ULL;
                                            }
                                            if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                  <= vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__target_paddr) 
                                                 & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__target_paddr 
                                                    < vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result 
                                                    = 
                                                    (0x10U 
                                                     | ((((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__R) 
                                                          << 3U) 
                                                         | ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__W) 
                                                            << 2U)) 
                                                        | (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__X) 
                                                            << 1U) 
                                                           | (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__unnamedblk2__DOT__L))));
                                                goto __Vlabel239;
                                            }
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i 
                                                = ((IData)(1U) 
                                                   + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__unnamedblk1__DOT__i);
                                        }
                                        __Vlabel239: ;
                                    }
                                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_exist)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 0U;
                                        goto __Vlabel238;
                                    }
                                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result) 
                                                  >> 4U)))) {
                                        if ((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__current_priv))) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 0U;
                                            goto __Vlabel238;
                                        } else {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 1U;
                                            goto __Vlabel238;
                                        }
                                    }
                                    if (((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__current_priv)) 
                                         & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 0U;
                                        goto __Vlabel238;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_read) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result) 
                                               >> 3U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 1U;
                                        goto __Vlabel238;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_write) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result) 
                                               >> 2U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 1U;
                                        goto __Vlabel238;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__is_exe) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__pmp_result) 
                                               >> 1U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 1U;
                                        goto __Vlabel238;
                                    }
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout = 0U;
                                    __Vlabel238: ;
                                }
                            }(), (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__38__Vfuncout)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                       >> 0xfU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x47U;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1bU) & ([&]() {
                                vlSelfRef.__Vfunc_is_ld_opcode__39__opcode 
                                    = (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_ld_opcode__39__Vfuncout 
                                    = (((((((((0x1dU 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode)) 
                                              | (0x1eU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                             | (0x1fU 
                                                == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                            | (0x20U 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                           | (0x21U 
                                              == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                          | (0x22U 
                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                         | (0x23U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                        | (0x4bU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode))) 
                                       | (0x56U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__39__Vfuncout)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,56, 
                                                (0xffffffffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,56, 
                                                 (0xffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x45U;
                }
                if ((([&]() {
                                vlSelfRef.__Vfunc_is_ld_opcode__40__opcode 
                                    = (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_ld_opcode__40__Vfuncout 
                                    = (((((((((0x1dU 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode)) 
                                              | (0x1eU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                             | (0x1fU 
                                                == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                            | (0x20U 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                           | (0x21U 
                                              == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                          | (0x22U 
                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                         | (0x23U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                        | (0x4bU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode))) 
                                       | (0x56U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__40__Vfuncout)) 
                     & ([&]() {
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_exe = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_write = 0U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_read = 1U;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__current_priv 
                                    = vlSelfRef.Top__DOT__priv__DOT__current_priv;
                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__target_paddr 
                                    = (0xffffffffffffffULL 
                                       & (((QData)((IData)(
                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                           << 0x23U) 
                                          | (((QData)((IData)(
                                                              vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                              << 3U) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                >> 0x1dU))));
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__L = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__A = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__X = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__W = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__R = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist = 0;
                                vlSelf->__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result = 0;
                                {
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist = 0U;
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result = 0U;
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i = 0U;
                                    {
                                        while ((0x40U 
                                                > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg 
                                                = (0xffU 
                                                   & (IData)(
                                                             (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpcfg_rdata
                                                              [
                                                              (7U 
                                                               & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i 
                                                                  >> 3U))] 
                                                              >> 
                                                              (0x38U 
                                                               & VL_SHIFTL_III(6,32,32, vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i, 3U)))));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__L 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__A 
                                                = (3U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 3U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__X 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 2U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__W 
                                                = (1U 
                                                   & ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg) 
                                                      >> 1U));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__R 
                                                = (1U 
                                                   & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__pmpcfg));
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter = 0U;
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask = 0xffffffffffffffffULL;
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0U;
                                                    {
                                                        while (
                                                               (0x36U 
                                                                > vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(
                                                                              (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                               [
                                                                               (0x3fU 
                                                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)] 
                                                                               >> 
                                                                               (0x3fU 
                                                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j)))))) {
                                                                goto __Vlabel243;
                                                            }
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter 
                                                                = 
                                                                ((IData)(1U) 
                                                                 + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter);
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask 
                                                                = 
                                                                ((~ 
                                                                  (1ULL 
                                                                   << 
                                                                   (0x3fU 
                                                                    & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j))) 
                                                                 & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask);
                                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j 
                                                                = 
                                                                ((IData)(1U) 
                                                                 + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j);
                                                        }
                                                        __Vlabel243: ;
                                                    }
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & VL_SHIFTL_QQI(56,64,32, 
                                                                         (vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                          [
                                                                          (0x3fU 
                                                                           & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)] 
                                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_mask), 2U));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                            + 
                                                            VL_SHIFTL_QQI(56,56,32, 1ULL, 
                                                                          ((IData)(2U) 
                                                                           + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__napot_counter))));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist = 1U;
                                                } else {
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & VL_SHIFTL_QQI(56,64,32, 
                                                                         vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                         [
                                                                         (0x3fU 
                                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)], 2U));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                        = 
                                                        (0xffffffffffffffULL 
                                                         & (4ULL 
                                                            + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr));
                                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist = 1U;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__A))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                    = 
                                                    ((0U 
                                                      == vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)
                                                      ? 0ULL
                                                      : 
                                                     (0xffffffffffffffULL 
                                                      & VL_SHIFTL_QQI(56,64,32, 
                                                                      vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                      [
                                                                      (0x3fU 
                                                                       & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i 
                                                                          - (IData)(1U)))], 2U)));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr 
                                                    = 
                                                    (0xffffffffffffffULL 
                                                     & VL_SHIFTL_QQI(56,64,32, 
                                                                     vlSymsp->TOP__Top__DOT__csr_renamer_port.pmpaddr_rdata
                                                                     [
                                                                     (0x3fU 
                                                                      & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i)], 2U));
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist = 1U;
                                            } else {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr = 0ULL;
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr = 0ULL;
                                            }
                                            if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__start_paddr 
                                                  <= vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__target_paddr) 
                                                 & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__target_paddr 
                                                    < vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__end_paddr))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result 
                                                    = 
                                                    (0x10U 
                                                     | ((((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__R) 
                                                          << 3U) 
                                                         | ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__W) 
                                                            << 2U)) 
                                                        | (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__X) 
                                                            << 1U) 
                                                           | (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__unnamedblk2__DOT__L))));
                                                goto __Vlabel242;
                                            }
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i 
                                                = ((IData)(1U) 
                                                   + vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__unnamedblk1__DOT__i);
                                        }
                                        __Vlabel242: ;
                                    }
                                    if ((1U & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_exist)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 0U;
                                        goto __Vlabel241;
                                    }
                                    if ((1U & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result) 
                                                  >> 4U)))) {
                                        if ((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__current_priv))) {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 0U;
                                            goto __Vlabel241;
                                        } else {
                                            vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 1U;
                                            goto __Vlabel241;
                                        }
                                    }
                                    if (((3U == (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__current_priv)) 
                                         & (~ (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 0U;
                                        goto __Vlabel241;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_read) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result) 
                                               >> 3U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 1U;
                                        goto __Vlabel241;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_write) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result) 
                                               >> 2U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 1U;
                                        goto __Vlabel241;
                                    }
                                    if (((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__is_exe) 
                                         & (~ ((IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__pmp_result) 
                                               >> 1U)))) {
                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 1U;
                                        goto __Vlabel241;
                                    }
                                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout = 0U;
                                    __Vlabel241: ;
                                }
                            }(), (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__pmp_access_fault__41__Vfuncout)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                       >> 0xfU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x45U;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1cU) & (([&]() {
                                    vlSelfRef.__Vfunc_is_st_opcode__42__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_st_opcode__42__Vfuncout 
                                        = ((((((0x24U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode)) 
                                               | (0x25U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode))) 
                                              | (0x26U 
                                                 == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode))) 
                                             | (0x27U 
                                                == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode))) 
                                            | (0x4cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode))) 
                                           | (0x57U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__42__Vfuncout)) 
                                   | ([&]() {
                                    vlSelfRef.__Vfunc_is_amo_opcode__43__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_amo_opcode__43__Vfuncout 
                                        = (((((((((
                                                   (((((((((0x4dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode)) 
                                                           | (0x4eU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                          | (0x4fU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                         | (0x50U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                        | (0x51U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                       | (0x52U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                      | (0x53U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                     | (0x54U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                    | (0x55U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                   | (0x58U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                  | (0x59U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                 | (0x5aU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                                | (0x5bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                               | (0x5cU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                              | (0x5dU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                             | (0x5eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                            | (0x5fU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode))) 
                                           | (0x60U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__43__Vfuncout))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x4fU;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1cU) & ([&]() {
                                vlSelfRef.__Vfunc_is_ld_opcode__44__opcode 
                                    = (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_ld_opcode__44__Vfuncout 
                                    = (((((((((0x1dU 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode)) 
                                              | (0x1eU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                             | (0x1fU 
                                                == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                            | (0x20U 
                                               == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                           | (0x21U 
                                              == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                          | (0x22U 
                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                         | (0x23U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                        | (0x4bU == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode))) 
                                       | (0x56U == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__44__Vfuncout)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                        << 3U) 
                                                       | ((QData)((IData)(
                                                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                          >> 0x1dU))))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) 
                                                      << 0x23U) 
                                                     | (((QData)((IData)(
                                                                         vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[4U])) 
                                                         << 3U) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                                           >> 0x1dU))))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x4dU;
                }
                if ((IData)(((0x1a80U == (0x7f80U & 
                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                             & (3U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x4bU;
                }
                if ((IData)(((0x1a80U == (0x7f80U & 
                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                             & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x49U;
                }
                if ((IData)(((0x1a80U == (0x7f80U & 
                                          vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                             & (0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x48U;
                }
                if (((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                      >> 0x1aU) & (([&]() {
                                    vlSelfRef.__Vfunc_is_jmp_opcode__45__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_jmp_opcode__45__Vfuncout 
                                        = ((0x2eU == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__45__opcode)) 
                                           | (0x2fU 
                                              == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__45__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__45__Vfuncout)) 
                                   | ([&]() {
                                    vlSelfRef.__Vfunc_is_branch_opcode__46__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_branch_opcode__46__Vfuncout 
                                        = ((((((0x28U 
                                                == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode)) 
                                               | (0x29U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode))) 
                                              | (0x2aU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode))) 
                                             | (0x2bU 
                                                == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode))) 
                                            | (0x2cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode))) 
                                           | (0x2dU 
                                              == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_branch_opcode__46__Vfuncout))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[9U])) 
                                                     << 0x1eU) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[8U])) 
                                                       >> 2U)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[9U])) 
                                                      << 0x1eU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[8U])) 
                                                        >> 2U)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x40U;
                }
                if ((0x61U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                        >> 7U)))) {
                    if (VL_UNLIKELY(((3U != (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) {
                        __Vtemp_71 = VTop___024unit::__Venumtab_enum_name153
                            [vlSelfRef.Top__DOT__priv__DOT__current_priv];
                        VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,538] MRET Exception. Running in %@\n",0,
                                     -1,&(__Vtemp_71));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                            = (IData)((QData)((IData)(
                                                      ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                        << 6U) 
                                                       | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                          >> 0x1aU)))));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                            = (IData)(((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                         << 6U) 
                                                        | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                           >> 0x1aU)))) 
                                       >> 0x20U));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                    }
                }
                if ((0x62U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                        >> 7U)))) {
                    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                                      | ((3U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                                         & (IData)(
                                                   (vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                                    >> 0x16U))))))) {
                        VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,546] SRET Exception.\n",0);
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                            = (IData)((QData)((IData)(
                                                      ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                        << 6U) 
                                                       | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                          >> 0x1aU)))));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                            = (IData)(((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                         << 6U) 
                                                        | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                           >> 0x1aU)))) 
                                       >> 0x20U));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                    }
                }
                if (VL_UNLIKELY((((IData)(((0x3180U 
                                            == (0x7f80U 
                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                           & (vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                              >> 0x15U))) 
                                  & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))))) {
                    VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,553] WFI while tw  Exception.\n",0);
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)((QData)((IData)((
                                                   (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                    << 6U) 
                                                   | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                      >> 0x1aU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)(((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                     << 6U) 
                                                    | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                       >> 0x1aU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                }
                if ((0x64U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                        >> 7U)))) {
                    if (VL_UNLIKELY((((0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                                      | ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                                  >> 0x14U)) 
                                         & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))))) {
                        VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,561] SFENCE_VMA Exception.\n",0);
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                            = (IData)((QData)((IData)(
                                                      ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                        << 6U) 
                                                       | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                          >> 0x1aU)))));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                            = (IData)(((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                         << 6U) 
                                                        | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                           >> 0x1aU)))) 
                                       >> 0x20U));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                    }
                }
                if (VL_UNLIKELY(((((IData)(((0x600000U 
                                             == (0x3ffc000U 
                                                 & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                            & ([&]() {
                                                    vlSelfRef.__Vfunc_is_csr_opcode__47__opcode 
                                                        = 
                                                        (0xffU 
                                                         & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                            >> 7U));
                                                    vlSelfRef.__Vfunc_is_csr_opcode__47__Vfuncout 
                                                        = 
                                                        ((((((0x38U 
                                                              == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode)) 
                                                             | (0x39U 
                                                                == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode))) 
                                                            | (0x3aU 
                                                               == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode))) 
                                                           | (0x3bU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode))) 
                                                          | (0x3cU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode))) 
                                                         | (0x3dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__opcode)));
                                                }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__47__Vfuncout)))) 
                                   & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                              >> 0x14U))) 
                                  & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))))) {
                    VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,571] SATP ACCESS while in tvm Exception.\n",0);
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)((QData)((IData)((
                                                   (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                    << 6U) 
                                                   | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                      >> 0x1aU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)(((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                     << 6U) 
                                                    | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                       >> 0x1aU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                }
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit = 0U;
                if ((([&]() {
                                vlSelfRef.__Vfunc_is_csr_opcode__48__opcode 
                                    = (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_csr_opcode__48__Vfuncout 
                                    = ((((((0x38U == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode)) 
                                           | (0x39U 
                                              == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode))) 
                                          | (0x3aU 
                                             == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode))) 
                                         | (0x3bU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode))) 
                                        | (0x3cU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode))) 
                                       | (0x3dU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__48__Vfuncout)) 
                     & ((((0xc00U == (0xfffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                >> 0xeU))) 
                          | (0xc01U == (0xfffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                  >> 0xeU)))) 
                         | (0xc02U == (0xfffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                 >> 0xeU)))) 
                        | ((0xc03U <= (0xfffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                 >> 0xeU))) 
                           & (0xc1fU >= (0xfffU & (
                                                   vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                   >> 0xeU))))))) {
                    if ((0x2000000U & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) {
                        if ((0x1000000U & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) {
                            if ((1U & (~ (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                          >> 0x17U)))) {
                                if ((1U & (~ (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                              >> 0x16U)))) {
                                    if ((1U & (~ (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                  >> 0x15U)))) {
                                        if ((1U & (~ 
                                                   (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                    >> 0x14U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                     >> 0x13U)))) {
                                                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit 
                                                    = 
                                                    ((0x40000U 
                                                      & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                      ? 
                                                     ((0x20000U 
                                                       & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                       ? 
                                                      ((0x10000U 
                                                        & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                        ? 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x1fU
                                                          : 0x1eU)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x1dU
                                                          : 0x1cU))
                                                        : 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x1bU
                                                          : 0x1aU)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x19U
                                                          : 0x18U)))
                                                       : 
                                                      ((0x10000U 
                                                        & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                        ? 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x17U
                                                          : 0x16U)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x15U
                                                          : 0x14U))
                                                        : 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x13U
                                                          : 0x12U)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0x11U
                                                          : 0x10U))))
                                                      : 
                                                     ((0x20000U 
                                                       & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                       ? 
                                                      ((0x10000U 
                                                        & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                        ? 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0xfU
                                                          : 0xeU)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0xdU
                                                          : 0xcU))
                                                        : 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 0xbU
                                                          : 0xaU)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 9U
                                                          : 8U)))
                                                       : 
                                                      ((0x10000U 
                                                        & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                        ? 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 7U
                                                          : 6U)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 5U
                                                          : 4U))
                                                        : 
                                                       ((0x8000U 
                                                         & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                         ? 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 3U
                                                          : 2U)
                                                         : 
                                                        ((0x4000U 
                                                          & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])
                                                          ? 1U
                                                          : 0U)))));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (VL_UNLIKELY((((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mcounteren_rdata 
                                                  >> 
                                                  (0x3fU 
                                                   & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit)))) 
                                      & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))))) {
                        VL_WRITEF_NX("[LOG] illegal instr detected in mcounteren restriction.\n",0);
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                            = (IData)((QData)((IData)(
                                                      ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                        << 6U) 
                                                       | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                          >> 0x1aU)))));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                            = (IData)(((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                         << 6U) 
                                                        | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                           >> 0x1aU)))) 
                                       >> 0x20U));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                    }
                    if ((((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mcounteren_rdata 
                                      >> (0x3fU & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit)))) 
                          | (~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.scounteren_rdata 
                                        >> (0x3fU & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk4__DOT__corresponding_bit))))) 
                         & (0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))) {
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                            = (IData)((QData)((IData)(
                                                      ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                        << 6U) 
                                                       | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                          >> 0x1aU)))));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                            = (IData)(((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                         << 6U) 
                                                        | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                           >> 0x1aU)))) 
                                       >> 0x20U));
                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                    }
                }
                if (VL_UNLIKELY(((([&]() {
                                        vlSelfRef.__Vfunc_is_csr_opcode__49__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                  >> 7U));
                                        vlSelfRef.__Vfunc_is_csr_opcode__49__Vfuncout 
                                            = (((((
                                                   (0x38U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode)) 
                                                   | (0x39U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode))) 
                                                  | (0x3aU 
                                                     == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode))) 
                                                 | (0x3bU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode))) 
                                                | (0x3cU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode))) 
                                               | (0x3dU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__opcode)));
                                    }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__49__Vfuncout)) 
                                  & ((3U & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                            >> 0x16U)) 
                                     > (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))))) {
                    VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,635] CSR ACCESS fault Exception.\n",0);
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)((QData)((IData)((
                                                   (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                    << 6U) 
                                                   | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                      >> 0x1aU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)(((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                     << 6U) 
                                                    | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                       >> 0x1aU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                }
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 0U;
                if ((0x38U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                        >> 7U)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 1U;
                } else if ((((0x39U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                 >> 7U))) 
                             | (0x3aU == (0xffU & (
                                                   vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                   >> 7U)))) 
                            & (0U != (0x1fU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                               >> 9U))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 1U;
                } else if ((0x3bU == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                               >> 7U)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 1U;
                } else if ((((0x3cU == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                 >> 7U))) 
                             | (0x3dU == (0xffU & (
                                                   vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                   >> 7U)))) 
                            & (0U != (0x1fU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                               >> 9U))))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr = 1U;
                }
                if (VL_UNLIKELY((((IData)(((0x3000000U 
                                            == (0x3000000U 
                                                & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U])) 
                                           & ([&]() {
                                                vlSelfRef.__Vfunc_is_csr_opcode__50__opcode 
                                                    = 
                                                    (0xffU 
                                                     & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                                        >> 7U));
                                                vlSelfRef.__Vfunc_is_csr_opcode__50__Vfuncout 
                                                    = 
                                                    ((((((0x38U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode)) 
                                                         | (0x39U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode))) 
                                                        | (0x3aU 
                                                           == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode))) 
                                                       | (0x3bU 
                                                          == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode))) 
                                                      | (0x3cU 
                                                         == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode))) 
                                                     | (0x3dU 
                                                        == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__opcode)));
                                            }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__50__Vfuncout)))) 
                                  & (IData)(vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__unnamedblk5__DOT__is_write_csr))))) {
                    VL_WRITEF_NX("[LOG][/home/ishida/Documents/Kazan/src/Renamer.sv,655] CSR WRITE fault Exception.\n",0);
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)((QData)((IData)((
                                                   (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                    << 6U) 
                                                   | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                      >> 0x1aU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)(((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[3U] 
                                                     << 6U) 
                                                    | (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[2U] 
                                                       >> 0x1aU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x42U;
                }
                if ((0x1000000U & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                       >> 0xfU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x41U;
                }
                if ((0x2000000U & vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[5U])) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                       >> 0xfU)))));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x4cU;
                }
                if ((0x36U == (0xffU & (vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__al_entry[0xbU] 
                                        >> 7U)))) {
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U] = 0U;
                    vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U] = 0x43U;
                }
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[0U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[0U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[1U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[1U];
                vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[2U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__exception_result[2U];
                Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[0U];
                Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[1U];
                Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[2U] 
                    = vlSelfRef.__Vfunc_Top__DOT__renamer__DOT__check_exception__30__Vfuncout[2U];
                if ((0x40U & Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[2U])) {
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U] 
                        = (1U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U]);
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                        = ((0x3ffffffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U]) 
                           | (Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[2U] 
                              << 0x1aU));
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U] 
                        = ((0x3ffffffU & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U]) 
                           | ((IData)((((QData)((IData)(
                                                        Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U])))) 
                              << 0x1aU));
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U] 
                        = (((IData)((((QData)((IData)(
                                                      Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U])))) 
                            >> 6U) | ((IData)(((((QData)((IData)(
                                                                 Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U]))) 
                                               >> 0x20U)) 
                                      << 0x1aU));
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                        = ((0xfc000000U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U]) 
                           | ((IData)(((((QData)((IData)(
                                                         Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          Top__DOT__renamer__DOT__unnamedblk11__DOT__exception_result[0U]))) 
                                       >> 0x20U)) >> 6U));
                }
                if (((((~ ([&]() {
                                            vlSelfRef.__Vfunc_is_ld_opcode__51__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_is_ld_opcode__51__Vfuncout 
                                                = (
                                                   ((((((((0x1dU 
                                                           == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode)) 
                                                          | (0x1eU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                         | (0x1fU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                        | (0x20U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                       | (0x21U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                      | (0x22U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                     | (0x23U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                    | (0x4bU 
                                                       == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode))) 
                                                   | (0x56U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__opcode)));
                                        }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__51__Vfuncout))) 
                       & (~ ([&]() {
                                            vlSelfRef.__Vfunc_is_st_opcode__52__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_is_st_opcode__52__Vfuncout 
                                                = (
                                                   (((((0x24U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode)) 
                                                       | (0x25U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode))) 
                                                      | (0x26U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode))) 
                                                     | (0x27U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode))) 
                                                    | (0x4cU 
                                                       == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode))) 
                                                   | (0x57U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__opcode)));
                                        }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__52__Vfuncout)))) 
                      & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                   >> 1U)) & (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))) 
                         | (0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)))) 
                     & (0ULL != ((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                  & vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata) 
                                 & vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata)))) {
                    if ((1U & (((IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata) 
                                & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata)) 
                               & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata)))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 1U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 1U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 1U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 1U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 2U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 2U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 2U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 2U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 3U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 3U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 3U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 3U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 4U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 4U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 4U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 4U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 5U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 5U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 5U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 5U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 6U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 6U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 6U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 6U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 7U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 7U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 7U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 7U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 8U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 8U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 8U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 8U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 9U)) & (IData)(
                                                           (vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                                            >> 9U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 9U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 9U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xaU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xaU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xaU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xaU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xbU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xbU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xbU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xbU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xcU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xcU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xcU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xcU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xdU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xdU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xdU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xdU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xeU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xeU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xeU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xeU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0xfU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0xfU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0xfU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xfU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x10U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x10U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x10U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x10U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x11U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x11U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x11U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x11U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x12U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x12U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x12U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x12U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x13U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x13U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x13U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x13U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x14U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x14U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x14U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x14U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x15U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x15U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x15U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x15U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x16U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x16U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x16U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x16U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x17U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x17U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x17U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x17U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x18U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x18U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x18U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x18U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x19U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x19U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x19U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x19U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1aU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1aU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1bU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1bU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1cU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1cU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1dU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1dU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1eU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1eU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x1fU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x1fU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x1fU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1fU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x20U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x20U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x20U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x20U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x21U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x21U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x21U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x21U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x22U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x22U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x22U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x22U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x23U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x23U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x23U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x23U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x24U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x24U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x24U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x24U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x25U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x25U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x25U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x25U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x26U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x26U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x26U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x26U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x27U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x27U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x27U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x27U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x28U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x28U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x28U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x28U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x29U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x29U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x29U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x29U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2aU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2aU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2bU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2bU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2cU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2cU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2dU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2dU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2eU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2eU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x2fU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x2fU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x2fU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2fU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x30U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x30U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x30U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x30U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x31U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x31U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x31U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x31U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x32U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x32U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x32U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x32U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x33U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x33U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x33U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x33U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x34U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x34U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x34U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x34U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x35U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x35U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x35U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x35U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x36U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x36U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x36U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x36U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x37U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x37U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x37U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x37U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x38U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x38U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x38U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x38U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x39U)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x39U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x39U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x39U;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x3aU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x3aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x3aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3aU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x3bU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x3bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x3bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3bU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x3cU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x3cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x3cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3cU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x3dU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x3dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x3dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3dU;
                    }
                    if ((1U & (((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                         >> 0x3eU)) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata 
                                           >> 0x3eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata 
                                          >> 0x3eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3eU;
                    }
                    if ((IData)((((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                   & vlSymsp->TOP__Top__DOT__csr_renamer_port.sie_rdata) 
                                  & vlSymsp->TOP__Top__DOT__csr_renamer_port.sip_rdata) 
                                 >> 0x3fU))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3fU;
                    }
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[2U] 
                        = (1U | vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[2U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                       >> 0xfU)))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[0U] 
                        = (IData)((QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[1U] 
                        = (0x80000000U | (IData)(((QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)) 
                                                  >> 0x20U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[0U] = 0U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[1U] = 0U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = ((0xfffffeffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]) 
                           | (0x100U & ((IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv) 
                                        << 8U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = ((0xffffffdfU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]) 
                           | (0x20U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                                >> 1U)) 
                                       << 5U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (0xfffffffdU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & ((0x7ffffffffcULL 
                                                  & vlSymsp->TOP__Top__DOT__csr_renamer_port.stvec_rdata) 
                                                 + 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.stvec_rdata)))
                                                   ? 
                                                  VL_SHIFTL_QQI(64,64,32, (QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)), 2U)
                                                   : 0ULL))));
                    vlSelfRef.Top__DOT__priv_w = 5U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if (((((~ ([&]() {
                                            vlSelfRef.__Vfunc_is_ld_opcode__53__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_is_ld_opcode__53__Vfuncout 
                                                = (
                                                   ((((((((0x1dU 
                                                           == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode)) 
                                                          | (0x1eU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                         | (0x1fU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                        | (0x20U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                       | (0x21U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                      | (0x22U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                     | (0x23U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                    | (0x4bU 
                                                       == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode))) 
                                                   | (0x56U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__opcode)));
                                        }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__53__Vfuncout))) 
                              & (~ ([&]() {
                                            vlSelfRef.__Vfunc_is_st_opcode__54__opcode 
                                                = (0xffU 
                                                   & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                      >> 7U));
                                            vlSelfRef.__Vfunc_is_st_opcode__54__Vfuncout 
                                                = (
                                                   (((((0x24U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode)) 
                                                       | (0x25U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode))) 
                                                      | (0x26U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode))) 
                                                     | (0x27U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode))) 
                                                    | (0x4cU 
                                                       == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode))) 
                                                   | (0x57U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__opcode)));
                                        }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__54__Vfuncout)))) 
                             & (((3U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                                 & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                            >> 3U))) 
                                | ((0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                                   | (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) 
                            & (0ULL != (((~ vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata) 
                                         & vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata) 
                                        & vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata)))) {
                    if ((1U & (((~ (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata)) 
                                & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata)) 
                               & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata)))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 1U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 1U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 1U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 1U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 2U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 2U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 2U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 2U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 3U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 3U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 3U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 3U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 4U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 4U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 4U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 4U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 5U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 5U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 5U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 5U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 6U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 6U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 6U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 6U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 7U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 7U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 7U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 7U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 8U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 8U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 8U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 8U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 9U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 9U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 9U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 9U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xaU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xaU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xaU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xaU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xbU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xbU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xbU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xbU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xcU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xcU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xcU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xcU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xdU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xdU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xdU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xdU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xeU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xeU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xeU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xeU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0xfU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0xfU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0xfU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0xfU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x10U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x10U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x10U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x10U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x11U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x11U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x11U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x11U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x12U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x12U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x12U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x12U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x13U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x13U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x13U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x13U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x14U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x14U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x14U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x14U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x15U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x15U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x15U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x15U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x16U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x16U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x16U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x16U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x17U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x17U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x17U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x17U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x18U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x18U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x18U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x18U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x19U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x19U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x19U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x19U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1aU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1aU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1bU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1bU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1cU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1cU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1dU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1dU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1eU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1eU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x1fU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x1fU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x1fU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x1fU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x20U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x20U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x20U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x20U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x21U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x21U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x21U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x21U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x22U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x22U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x22U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x22U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x23U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x23U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x23U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x23U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x24U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x24U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x24U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x24U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x25U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x25U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x25U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x25U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x26U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x26U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x26U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x26U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x27U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x27U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x27U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x27U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x28U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x28U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x28U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x28U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x29U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x29U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x29U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x29U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2aU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2aU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2bU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2bU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2cU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2cU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2dU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2dU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2eU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2eU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x2fU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x2fU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x2fU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x2fU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x30U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x30U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x30U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x30U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x31U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x31U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x31U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x31U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x32U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x32U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x32U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x32U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x33U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x33U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x33U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x33U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x34U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x34U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x34U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x34U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x35U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x35U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x35U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x35U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x36U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x36U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x36U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x36U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x37U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x37U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x37U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x37U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x38U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x38U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x38U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x38U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x39U))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x39U))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x39U))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x39U;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x3aU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x3aU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x3aU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3aU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x3bU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x3bU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x3bU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3bU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x3cU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x3cU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x3cU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3cU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x3dU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x3dU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x3dU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3dU;
                    }
                    if ((1U & (((~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                            >> 0x3eU))) 
                                & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                           >> 0x3eU))) 
                               & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                          >> 0x3eU))))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3eU;
                    }
                    if ((IData)((((~ (vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
                                      >> 0x3fU)) & 
                                  (vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
                                   >> 0x3fU)) & (vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
                                                 >> 0x3fU)))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause = 0x3fU;
                    }
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[2U] 
                        = (1U | vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[2U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                       >> 0xfU)))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[0U] 
                        = (IData)((QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[1U] 
                        = (0x80000000U | (IData)(((QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)) 
                                                  >> 0x20U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[0U] = 0U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[1U] = 0U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = ((0xffffe7ffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]) 
                           | ((IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv) 
                              << 0xbU));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = ((0xffffff7fU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]) 
                           | (0x80U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                                >> 3U)) 
                                       << 7U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (0xfffffff7U & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & ((0x7ffffffffcULL 
                                                  & vlSymsp->TOP__Top__DOT__csr_renamer_port.mtvec_rdata) 
                                                 + 
                                                 ((1U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mtvec_rdata)))
                                                   ? 
                                                  VL_SHIFTL_QQI(64,64,32, (QData)((IData)(Top__DOT__renamer__DOT__unnamedblk11__DOT__extracted_cause)), 2U)
                                                   : 0ULL))));
                    vlSelfRef.Top__DOT__priv_w = 7U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if (((vlSelfRef.Top__DOT__renamer__DOT__al_next
                             [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U] 
                             & (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.medeleg_rdata 
                                        >> (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                                            >> 0x1aU)))) 
                            & ((0U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv)) 
                               | (1U == (IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv))))) {
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[2U] 
                        = (1U | vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[2U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                       >> 0xfU)))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_w[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[1U] 
                        = (0x7fffffffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[1U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[0U] 
                        = (IData)((QData)((IData)((
                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                                                   >> 0x1aU))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[1U] 
                        = ((0x80000000U & vlSymsp->TOP__Top__DOT__csr_renamer_port.scause_w[1U]) 
                           | (IData)(((QData)((IData)(
                                                      (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                                                       >> 0x1aU))) 
                                      >> 0x20U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[0U] 
                        = (IData)((((QData)((IData)(
                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U])) 
                                    << 0x26U) | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U])) 
                                                  << 6U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                                    >> 0x1aU))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[1U] 
                        = (IData)(((((QData)((IData)(
                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U])) 
                                     << 0x26U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U])) 
                                                   << 6U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                                     >> 0x1aU))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.stval_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = ((0xfffffeffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]) 
                           | (0x100U & ((IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv) 
                                        << 8U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = ((0xffffffdfU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]) 
                           | (0x20U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                                >> 1U)) 
                                       << 5U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (0xfffffffdU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7ffffffffcULL 
                                              & vlSymsp->TOP__Top__DOT__csr_renamer_port.stvec_rdata));
                    vlSelfRef.Top__DOT__priv_w = 5U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((1U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U])) {
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[2U] 
                        = (1U | vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[2U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[0U] 
                        = (IData)(VL_EXTENDS_QQ(64,39, 
                                                (0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                       >> 0xfU)))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_w[1U] 
                        = (IData)((VL_EXTENDS_QQ(64,39, 
                                                 (0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU)))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[1U] 
                        = (0x7fffffffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[1U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[0U] 
                        = (IData)((QData)((IData)((
                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                                                   >> 0x1aU))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[1U] 
                        = ((0x80000000U & vlSymsp->TOP__Top__DOT__csr_renamer_port.mcause_w[1U]) 
                           | (IData)(((QData)((IData)(
                                                      (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U] 
                                                       >> 0x1aU))) 
                                      >> 0x20U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[0U] 
                        = (IData)((((QData)((IData)(
                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U])) 
                                    << 0x26U) | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U])) 
                                                  << 6U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                                    >> 0x1aU))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[1U] 
                        = (IData)(((((QData)((IData)(
                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][7U])) 
                                     << 0x26U) | (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][6U])) 
                                                   << 6U) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                                     >> 0x1aU))) 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mtval_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = ((0xffffe7ffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]) 
                           | ((IData)(vlSelfRef.Top__DOT__priv__DOT__current_priv) 
                              << 0xbU));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = ((0xffffff7fU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]) 
                           | (0x80U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                                >> 3U)) 
                                       << 7U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (0xfffffff7U & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7ffffffffcULL 
                                              & vlSymsp->TOP__Top__DOT__csr_renamer_port.mtvec_rdata));
                    vlSelfRef.Top__DOT__priv_w = 7U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((0x800000U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) {
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                  << 0x11U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                    >> 0xfU))));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 0U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((0x37U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                               >> 7U)))) {
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                   << 0x31U) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU))))));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((2U & vlSelfRef.Top__DOT__renamer__DOT__al_next
                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U])) {
                    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[0U] 
                        = (IData)((0x7fffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])) 
                                       << 0x1eU) | 
                                      ((QData)((IData)(
                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U])) 
                                       >> 2U))));
                    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[1U] 
                        = (((IData)((0x7fffffffffULL 
                                     & (((QData)((IData)(
                                                         vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                         << 0x11U) 
                                        | ((QData)((IData)(
                                                           vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                           >> 0xfU)))) 
                            << 7U) | (IData)(((0x7fffffffffULL 
                                               & (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])) 
                                                   << 0x1eU) 
                                                  | ((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U])) 
                                                     >> 2U))) 
                                              >> 0x20U)));
                    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U] 
                        = ((0x4000U & vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U]) 
                           | (0x7fffU & (((IData)((0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                       << 0x11U) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                         >> 0xfU)))) 
                                          >> 0x19U) 
                                         | ((IData)(
                                                    ((0x7fffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                          [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                          << 0x11U) 
                                                         | ((QData)((IData)(
                                                                            vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                            >> 0xfU))) 
                                                     >> 0x20U)) 
                                            << 7U))));
                    vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U] 
                        = ((0x3fffU & vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U]) 
                           | (0x7fffU & (((0x200U & 
                                           vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])
                                           ? 1U : 0U) 
                                         << 0xeU)));
                    vlSelfRef.Top__DOT__is_taken_feedback_to_pred[(3U 
                                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                        = (0x10000000000ULL | ((0xfffffffffeULL 
                                                & (((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                    << 0x12U) 
                                                   | (0x3fffffffffffeULL 
                                                      & ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                         >> 0xeU)))) 
                                               | (QData)((IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U] 
                                                                     >> 9U))))));
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & ((0x200U 
                                                  & vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])) 
                                                   << 0x3eU) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U])) 
                                                      << 0x1eU) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][8U])) 
                                                        >> 2U)))
                                                  : 
                                                 (4ULL 
                                                  + 
                                                  (((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                    << 0x31U) 
                                                   | (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                       << 0x11U) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                         >> 0xfU)))))));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if (([&]() {
                            vlSelfRef.__Vfunc_is_csr_opcode__55__opcode 
                                = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                            >> 7U));
                            vlSelfRef.__Vfunc_is_csr_opcode__55__Vfuncout 
                                = ((((((0x38U == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode)) 
                                       | (0x39U == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode))) 
                                      | (0x3aU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode))) 
                                     | (0x3bU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode))) 
                                    | (0x3cU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode))) 
                                   | (0x3dU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__opcode)));
                        }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__55__Vfuncout))) {
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                   << 0x31U) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU))))));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((0x61U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                               >> 7U)))) {
                    vlSelfRef.Top__DOT__priv_w = (4U 
                                                  | (3U 
                                                     & (IData)(
                                                               (vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                                                >> 0xbU))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = ((0xfffffff7U & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]) 
                           | (8U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_rdata 
                                             >> 7U)) 
                                    << 3U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (0x80U | vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U] 
                        = (0xffffe7ffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.mstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & vlSymsp->TOP__Top__DOT__csr_renamer_port.mepc_rdata));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((0x62U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                               >> 7U)))) {
                    vlSelfRef.Top__DOT__priv_w = (4U 
                                                  | (1U 
                                                     & (IData)(
                                                               (vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                                                >> 8U))));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (IData)(vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[1U] 
                        = (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                   >> 0x20U));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[2U] = 1U;
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = ((0xfffffffdU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]) 
                           | (2U & ((IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_rdata 
                                             >> 5U)) 
                                    << 1U)));
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (0x20U | vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]);
                    vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U] 
                        = (0xfffffeffU & vlSymsp->TOP__Top__DOT__csr_renamer_port.sstatus_w[0U]);
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & vlSymsp->TOP__Top__DOT__csr_renamer_port.sepc_rdata));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else if ((0x64U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                               >> 7U)))) {
                    vlSelfRef.Top__DOT__flush_tlb = 1U;
                    vlSelfRef.Top__DOT__flush_from_renamer 
                        = (0x8000000000ULL | (0x7fffffffffULL 
                                              & (4ULL 
                                                 + 
                                                 (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                   << 0x31U) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU))))));
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 1U;
                } else {
                    if (([&]() {
                                vlSelfRef.__Vfunc_is_st_opcode__56__opcode 
                                    = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                >> 7U));
                                vlSelfRef.__Vfunc_is_st_opcode__56__Vfuncout 
                                    = ((((((0x24U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode)) 
                                           | (0x25U 
                                              == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode))) 
                                          | (0x26U 
                                             == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode))) 
                                         | (0x27U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode))) 
                                        | (0x4cU == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode))) 
                                       | (0x57U == (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__opcode)));
                            }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__56__Vfuncout))) {
                        Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter 
                            = ((IData)(1U) + Top__DOT__renamer__DOT__unnamedblk11__DOT__st_commit_counter);
                    }
                    if ((([&]() {
                                    vlSelfRef.__Vfunc_is_branch_opcode__57__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_branch_opcode__57__Vfuncout 
                                        = ((((((0x28U 
                                                == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode)) 
                                               | (0x29U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode))) 
                                              | (0x2aU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode))) 
                                             | (0x2bU 
                                                == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode))) 
                                            | (0x2cU 
                                               == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode))) 
                                           | (0x2dU 
                                              == (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_branch_opcode__57__Vfuncout)) 
                         | ([&]() {
                                    vlSelfRef.__Vfunc_is_jmp_opcode__58__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_jmp_opcode__58__Vfuncout 
                                        = ((0x2eU == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__58__opcode)) 
                                           | (0x2fU 
                                              == (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__58__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_jmp_opcode__58__Vfuncout)))) {
                        vlSelfRef.Top__DOT__is_taken_feedback_to_pred[(3U 
                                                                       & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                            = (0x10000000000ULL | (
                                                   (0xfffffffffeULL 
                                                    & (((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                        << 0x12U) 
                                                       | (0x3fffffffffffeULL 
                                                          & ((QData)((IData)(
                                                                             vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                             [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                             >> 0xeU)))) 
                                                   | (QData)((IData)(
                                                                     (1U 
                                                                      & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][9U] 
                                                                         >> 9U))))));
                    }
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op = 1U;
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break = 0U;
                }
            } else {
                if (([&]() {
                            vlSelfRef.__Vfunc_is_csr_opcode__59__opcode 
                                = (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                            >> 7U));
                            vlSelfRef.__Vfunc_is_csr_opcode__59__Vfuncout 
                                = ((((((0x38U == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode)) 
                                       | (0x39U == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode))) 
                                      | (0x3aU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode))) 
                                     | (0x3bU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode))) 
                                    | (0x3cU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode))) 
                                   | (0x3dU == (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__opcode)));
                        }(), (IData)(vlSelfRef.__Vfunc_is_csr_opcode__59__Vfuncout))) {
                    vlSymsp->TOP__Top__DOT__csru_renamer_port.executable_csr 
                        = (0x40U | (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_rp_next));
                }
                vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[0U] 
                    = (IData)(vlSelfRef.Top__DOT__renamer__DOT__lrsc_lock_next);
                vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[1U] 
                    = ((0xfc000000U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                       << 0x13U)) | (IData)(
                                                            (vlSelfRef.Top__DOT__renamer__DOT__lrsc_lock_next 
                                                             >> 0x20U)));
                vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[2U] 
                    = ((0x1fcU & vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[2U]) 
                       | (3U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                >> 0xdU)));
                vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[2U] 
                    = ((3U & vlSymsp->TOP__Top__DOT__renamer_lsu_port.sc_mmio_executable[2U]) 
                       | (0x1fcU & (0x100U | ((IData)(vlSelfRef.Top__DOT__renamer__DOT__al_rp_next) 
                                              << 2U))));
                if (((0x37U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                         >> 7U))) & 
                     (~ (vlSelfRef.Top__DOT__renamer__DOT__al_next
                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U] 
                         >> 0x16U)))) {
                    vlSelfRef.Top__DOT__renamer__DOT__invalidate_l1cache_next = 1U;
                    vlSelfRef.Top__DOT__renamer__DOT__al_next[vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U] 
                        = (0x400000U | vlSelfRef.Top__DOT__renamer__DOT__al_next
                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U]);
                }
                goto __Vlabel237;
            }
            if (Top__DOT__renamer__DOT__unnamedblk11__DOT__commit_op) {
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][0U] 
                    = (IData)((((QData)((IData)(vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0U]))));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][1U] 
                    = (IData)(((((QData)((IData)(vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                 [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                             [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0U]))) 
                               >> 0x20U));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U] 
                    = ((0xfc000000U & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U]) 
                       | ((0x3e00000U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                         << 0x14U)) 
                          | ((0x1fff80U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U] 
                                           << 7U)) 
                             | (0x7fU & ((vlSelfRef.Top__DOT__renamer__DOT__al_next
                                          [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                          << 6U) | 
                                         (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                          [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                                          >> 0x1aU))))));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U] 
                    = ((0x83ffffffU & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U]) 
                       | (0x7c000000U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U] 
                                         << 0xcU)));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U] 
                    = ((0x7fffffffU & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][2U]) 
                       | (0x80000000U & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U] 
                                         << 0xcU)));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U] 
                    = ((0xfffffff0U & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U]) 
                       | (0xfU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U] 
                                  >> 0x14U)));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U] 
                    = ((0xffff800fU & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U]) 
                       | (0xfffffff0U & ((0x7f80U & 
                                          vlSelfRef.Top__DOT__renamer__DOT__al_next
                                          [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU]) 
                                         | ((0x60U 
                                             & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][2U] 
                                                >> 0x13U)) 
                                            | (0x10U 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                  >> 2U))))));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U] 
                    = ((0x7fffU & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][3U]) 
                       | ((IData)((0x7fffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                       << 0x11U) | 
                                      ((QData)((IData)(
                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                       >> 0xfU)))) 
                          << 0xfU));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][4U] 
                    = ((0x400000U & Top__DOT__renamer__DOT__commitlog
                        [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][4U]) 
                       | (0x7fffffU & (((IData)((0x7fffffffffULL 
                                                 & (((QData)((IData)(
                                                                     vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                     << 0x11U) 
                                                    | ((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                       [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                       >> 0xfU)))) 
                                        >> 0x11U) | 
                                       ((IData)(((0x7fffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xcU])) 
                                                      << 0x11U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU])) 
                                                        >> 0xfU))) 
                                                 >> 0x20U)) 
                                        << 0xfU))));
                Top__DOT__renamer__DOT__commitlog[(3U 
                                                   & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][4U] 
                    = (0x400000U | Top__DOT__renamer__DOT__commitlog
                       [(3U & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)][4U]);
                if (((vlSelfRef.Top__DOT__renamer__DOT__al_next
                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                      >> 6U) & (0U != (0x7fU & ((vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                 [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                 << 6U) 
                                                | (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                                                   >> 0x1aU)))))) {
                    vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid[(3U 
                                                                          & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] = 1U;
                    vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[(3U 
                                                                        & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                        = (0x7fU & ((vlSelfRef.Top__DOT__renamer__DOT__al_next
                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                     << 6U) | (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                                               >> 0x1aU)));
                    vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[(3U 
                                                                             & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                        = (0x7fU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                                    >> 0x13U));
                    vlSelfRef.Top__DOT__renamer__DOT__rrat_next[(0x1fU 
                                                                 & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                                    >> 1U))] 
                        = (0x7fU & ((vlSelfRef.Top__DOT__renamer__DOT__al_next
                                     [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                     << 6U) | (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xaU] 
                                               >> 0x1aU)));
                } else {
                    vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid[(3U 
                                                                          & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] = 0U;
                    vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[(3U 
                                                                        & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] = 0U;
                    vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[(3U 
                                                                             & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] = 0U;
                }
                if ((((([&]() {
                                        vlSelfRef.__Vfunc_is_ld_opcode__60__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                  >> 7U));
                                        vlSelfRef.__Vfunc_is_ld_opcode__60__Vfuncout 
                                            = (((((
                                                   ((((0x1dU 
                                                       == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode)) 
                                                      | (0x1eU 
                                                         == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                     | (0x1fU 
                                                        == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                    | (0x20U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                   | (0x21U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                  | (0x22U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                 | (0x23U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                                | (0x4bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode))) 
                                               | (0x56U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__opcode)));
                                    }(), (IData)(vlSelfRef.__Vfunc_is_ld_opcode__60__Vfuncout)) 
                       | ([&]() {
                                        vlSelfRef.__Vfunc_is_st_opcode__61__opcode 
                                            = (0xffU 
                                               & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                  >> 7U));
                                        vlSelfRef.__Vfunc_is_st_opcode__61__Vfuncout 
                                            = (((((
                                                   (0x24U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode)) 
                                                   | (0x25U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode))) 
                                                  | (0x26U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode))) 
                                                 | (0x27U 
                                                    == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode))) 
                                                | (0x4cU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode))) 
                                               | (0x57U 
                                                  == (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__opcode)));
                                    }(), (IData)(vlSelfRef.__Vfunc_is_st_opcode__61__Vfuncout))) 
                      | ([&]() {
                                    vlSelfRef.__Vfunc_is_amo_opcode__62__opcode 
                                        = (0xffU & 
                                           (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                            [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                            >> 7U));
                                    vlSelfRef.__Vfunc_is_amo_opcode__62__Vfuncout 
                                        = (((((((((
                                                   (((((((((0x4dU 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode)) 
                                                           | (0x4eU 
                                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                          | (0x4fU 
                                                             == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                         | (0x50U 
                                                            == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                        | (0x51U 
                                                           == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                       | (0x52U 
                                                          == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                      | (0x53U 
                                                         == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                     | (0x54U 
                                                        == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                    | (0x55U 
                                                       == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                   | (0x58U 
                                                      == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                  | (0x59U 
                                                     == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                 | (0x5aU 
                                                    == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                                | (0x5bU 
                                                   == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                               | (0x5cU 
                                                  == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                              | (0x5dU 
                                                 == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                             | (0x5eU 
                                                == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                            | (0x5fU 
                                               == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode))) 
                                           | (0x60U 
                                              == (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__opcode)));
                                }(), (IData)(vlSelfRef.__Vfunc_is_amo_opcode__62__Vfuncout))) 
                     & (([&]() {
                                    vlSelfRef.__Vfunc_to_dw_aligned_paddr__63__paddr 
                                        = (0xffffffffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                               [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                               << 0x23U) 
                                              | (((QData)((IData)(
                                                                  vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                  [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][4U])) 
                                                  << 3U) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                    [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][3U])) 
                                                    >> 0x1dU))));
                                    vlSelfRef.__Vfunc_to_dw_aligned_paddr__63__Vfuncout 
                                        = (0xfffffffffffff8ULL 
                                           & vlSelfRef.__Vfunc_to_dw_aligned_paddr__63__paddr);
                                }(), vlSelfRef.__Vfunc_to_dw_aligned_paddr__63__Vfuncout) 
                        == (0xffffffffffffffULL & (vlSelfRef.Top__DOT__renamer__DOT__lrsc_lock_next 
                                                   >> 1U))))) {
                    vlSelfRef.Top__DOT__renamer__DOT__lrsc_lock_next = 0ULL;
                }
                if (((0x4bU == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                         >> 7U))) | 
                     (0x56U == (0xffU & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                         [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                         >> 7U))))) {
                    vlSelfRef.Top__DOT__renamer__DOT__lrsc_lock_next 
                        = (0x200000000000000ULL | (
                                                   (([&]() {
                                        vlSelfRef.__Vfunc_to_dw_aligned_paddr__64__paddr 
                                            = (0xffffffffffffffULL 
                                               & (((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                   [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][5U])) 
                                                   << 0x23U) 
                                                  | (((QData)((IData)(
                                                                      vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                      [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][4U])) 
                                                      << 3U) 
                                                     | ((QData)((IData)(
                                                                        vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                        [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][3U])) 
                                                        >> 0x1dU))));
                                        vlSelfRef.__Vfunc_to_dw_aligned_paddr__64__Vfuncout 
                                            = (0xfffffffffffff8ULL 
                                               & vlSelfRef.__Vfunc_to_dw_aligned_paddr__64__paddr);
                                    }(), vlSelfRef.__Vfunc_to_dw_aligned_paddr__64__Vfuncout) 
                                                    << 1U) 
                                                   | (QData)((IData)(
                                                                     ((0x4bU 
                                                                       == 
                                                                       (0xffU 
                                                                        & (vlSelfRef.Top__DOT__renamer__DOT__al_next
                                                                           [vlSelfRef.Top__DOT__renamer__DOT__al_rp_next][0xbU] 
                                                                           >> 7U)))
                                                                       ? 1U
                                                                       : 0U)))));
                }
                if ((1U & (~ (IData)((vlSymsp->TOP__Top__DOT__csr_renamer_port.mcountinhibit_rdata 
                                      >> 2U))))) {
                    Top__DOT__renamer__DOT__unnamedblk11__DOT__minstret_next 
                        = (1ULL + Top__DOT__renamer__DOT__unnamedblk11__DOT__minstret_next);
                }
                vlSymsp->TOP__Top__DOT__renamer_lsu_port.committed_instr[(3U 
                                                                          & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                    = (0x40U | (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_rp_next));
                vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr[(3U 
                                                                           & Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i)] 
                    = (0x40U | (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_rp_next));
                vlSelfRef.Top__DOT__renamer__DOT__al_rp_next 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__renamer__DOT__al_rp_next)));
                vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next 
                    = (0x7fU & ((IData)(vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next) 
                                - (IData)(1U)));
            }
            if (Top__DOT__renamer__DOT__unnamedblk11__DOT__flush_al_fl_and_break) {
                vlSelfRef.Top__DOT__renamer__DOT__al_wp_next = 0U;
                vlSelfRef.Top__DOT__renamer__DOT__al_rp_next = 0U;
                vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next = 0U;
                vlSelfRef.Top__DOT__renamer__DOT__flush_fl = 1U;
                vlSelfRef.Top__DOT__renamer__DOT__al_flush = 1U;
                vlSelfRef.Top__DOT__renamer__DOT__generation_next 
                    = ((IData)(1U) + vlSelfRef.Top__DOT__renamer__DOT__generation_next);
                goto __Vlabel237;
            } else {
                vlSelfRef.Top__DOT__renamer__DOT__flush_fl = 0U;
                vlSelfRef.Top__DOT__renamer__DOT__al_flush = 0U;
            }
            Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i 
                = ((IData)(1U) + Top__DOT__renamer__DOT__unnamedblk11__DOT__unnamedblk12__DOT__i);
        }
        __Vlabel237: ;
    }
    vlSelfRef.Top__DOT__stall_from_st5_to_st4 = (4U 
                                                 > 
                                                 ((IData)(0x40U) 
                                                  - (IData)(vlSelfRef.Top__DOT__renamer__DOT__num_of_entries_in_al_next)));
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][1U];
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[__Vilp1] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[__Vilp2] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[__Vilp3] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt
            [__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[__Vilp4] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt
            [__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb__DOT__genblk1__BRA__3__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[0U][0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[0U][1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[1U][0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[1U][1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[2U][0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[2U][1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[3U][0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data[3U][1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_data
        [3U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[0U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[1U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[2U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][3U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[3U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][4U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[4U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][5U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[5U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][6U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[6U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[0U][7U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__res_to_tlb[7U];
    vlSelfRef.Top__DOT__mmu__DOT__stall_req_to_pw[0U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__0__KET____DOT__pw__stall_out;
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[0U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[1U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[2U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][3U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[3U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][4U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[4U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][5U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[5U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][6U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[6U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[1U][7U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__res_to_tlb[7U];
    vlSelfRef.Top__DOT__mmu__DOT__stall_req_to_pw[1U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__1__KET____DOT__pw__stall_out;
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[0U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[1U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[2U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][3U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[3U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][4U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[4U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][5U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[5U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][6U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[6U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[2U][7U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__res_to_tlb[7U];
    vlSelfRef.Top__DOT__mmu__DOT__stall_req_to_pw[2U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__2__KET____DOT__pw__stall_out;
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][0U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[0U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][1U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[1U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][2U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[2U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][3U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[3U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][4U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[4U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][5U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[5U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][6U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[6U];
    vlSelfRef.Top__DOT__mmu__DOT__res_from_pw_to_l2tlb[3U][7U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__res_to_tlb[7U];
    vlSelfRef.Top__DOT__mmu__DOT__stall_req_to_pw[3U] 
        = vlSelfRef.Top__DOT__mmu__DOT____Vcellout__gen_pw__BRA__3__KET____DOT__pw__stall_out;
    IData/*31:0*/ __Vilp5;
    __Vilp5 = 0U;
    while ((__Vilp5 <= 0x5fU)) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[__Vilp5] 
            = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl
            [__Vilp5];
        __Vilp5 = ((IData)(1U) + __Vilp5);
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [0U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [0U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[0U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0;
        }
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg
             [0U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[0U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [1U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [1U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[1U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0;
        }
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg
             [1U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[1U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [2U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [2U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[2U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0;
        }
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg
             [2U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[2U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0;
        }
    }
    IData/*31:0*/ __Vilp6;
    __Vilp6 = 0U;
    while ((__Vilp6 <= 0x5fU)) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[__Vilp6] 
            = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl
            [__Vilp6];
        __Vilp6 = ((IData)(1U) + __Vilp6);
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__prd_used[0U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__available_prd
             [0U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__available_prd[0U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__prd_used[1U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__available_prd
             [1U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__available_prd[1U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__prd_used[2U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__available_prd
             [2U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__available_prd[2U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__prd_used[3U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__available_prd
             [3U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__available_prd[3U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h54e8007c__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [0U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [0U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[0U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [1U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [1U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[1U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [2U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [2U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[2U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0;
        }
    }
    if (vlSelfRef.Top__DOT__renamer__DOT__committed_rd_valid
        [3U]) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0 = 1U;
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0 = 0U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [3U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[3U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h1bdf5d22__0;
        }
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg
             [3U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_phyreg[3U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hd4251764__0;
        }
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0 = 1U;
        if ((0x5fU >= vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg
             [3U])) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[vlSelfRef.Top__DOT__renamer__DOT__committed_prev_phyreg[3U]] 
                = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_h3bd83929__0;
        }
    }
    vlSelfRef.Top__DOT__btb__DOT__btb_w_data[0U] = 0ULL;
    vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U] = 0U;
    vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx[0U] = 0U;
    if ((0x4000U & vlSelfRef.Top__DOT__misprediction_feedback_to_btb[2U])) {
        vlSelfRef.Top__DOT__btb__DOT__btb_w_data[0U] 
            = (0x2000000000000ULL | (((QData)((IData)(
                                                      (0x3ffU 
                                                       & (vlSelfRef.Top__DOT__misprediction_feedback_to_btb[1U] 
                                                          >> 0x12U)))) 
                                      << 0x27U) | (0x7fffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__misprediction_feedback_to_btb[1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelfRef.Top__DOT__misprediction_feedback_to_btb[0U]))))));
        vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U] = 1U;
        vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx[0U] 
            = (0x1ffU & (vlSelfRef.Top__DOT__misprediction_feedback_to_btb[1U] 
                         >> 9U));
    }
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[0U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[0U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[1U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[1U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[2U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[2U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[3U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[3U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[4U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[4U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[5U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[5U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[6U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[6U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][0U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][0U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][1U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][1U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][2U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][2U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][3U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][3U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][4U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][4U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][5U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][5U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][6U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][6U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][7U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][7U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][8U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][8U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_next[7U][9U] 
        = vlSelfRef.Top__DOT__csru__DOT__csrq[7U][9U];
    vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next = vlSelfRef.Top__DOT__csru__DOT__csrq_rp;
    vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next = vlSelfRef.Top__DOT__csru__DOT__csrq_wp;
    vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
        = vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq;
    vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U] = 0U;
    vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U] = 0U;
    vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] = 1U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][0U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][1U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][2U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][3U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][4U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][5U] = 0U;
    vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][6U] = 0U;
    if (((((0U != vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next) 
           & ((IData)(vlSymsp->TOP__Top__DOT__csru_renamer_port.executable_csr) 
              >> 6U)) & ((0x3fU & (IData)(vlSymsp->TOP__Top__DOT__csru_renamer_port.executable_csr)) 
                         == (0x3fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                      >> 8U)))) & (~ 
                                                   (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                    [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                    >> 0x16U)))) {
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][0U] = 0U;
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][1U] = 0U;
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][2U] = 0U;
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][3U] 
            = (0xfffffffcU & vlSelfRef.Top__DOT__csru__DOT__op_out_next
               [0U][3U]);
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][3U] 
            = ((0xffffff03U & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][3U]) | (0xfcU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                      >> 6U)));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][3U] 
            = ((0xffU & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][3U]) | ((IData)((((QData)((IData)(
                                                       vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U])))) 
                             << 8U));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][4U] 
            = (((IData)((((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U])))) 
                >> 0x18U) | ((IData)(((((QData)((IData)(
                                                        vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))) 
                                      >> 0x20U)) << 8U));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][5U] 
            = ((0xffffff00U & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][5U]) | ((IData)(((((QData)((IData)(
                                                        vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))) 
                                      >> 0x20U)) >> 0x18U));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][5U] 
            = ((0xffff00ffU & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][5U]) | (0xffffff00U & (0x8000U 
                                            | (0x7f00U 
                                               & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U] 
                                                  >> 6U)))));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][5U] 
            = ((0xffffU & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][5U]) | ((IData)((0x7fffffffffULL 
                                      & (((QData)((IData)(
                                                          vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                          [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U])) 
                                          << 0x1aU) 
                                         | ((QData)((IData)(
                                                            vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][8U])) 
                                            >> 6U)))) 
                             << 0x10U));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][6U] 
            = ((0xff800000U & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][6U]) | (((IData)((0x7fffffffffULL 
                                       & (((QData)((IData)(
                                                           vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                           [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U])) 
                                           << 0x1aU) 
                                          | ((QData)((IData)(
                                                             vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                             [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][8U])) 
                                             >> 6U)))) 
                              >> 0x10U) | ((IData)(
                                                   ((0x7fffffffffULL 
                                                     & (((QData)((IData)(
                                                                         vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                         [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U])) 
                                                         << 0x1aU) 
                                                        | ((QData)((IData)(
                                                                           vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                           [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][8U])) 
                                                           >> 6U))) 
                                                    >> 0x20U)) 
                                           << 0x10U)));
        vlSelfRef.Top__DOT__csru__DOT__op_out_next[0U][6U] 
            = ((0x7fffffU & vlSelfRef.Top__DOT__csru__DOT__op_out_next
                [0U][6U]) | (0xff800000U & (0x80000000U 
                                            | (0x7f800000U 
                                               & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                  << 0xaU)))));
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
            = (0x400000U | vlSelfRef.Top__DOT__csru__DOT__csrq_next
               [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U]);
    }
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0ULL;
    if ((((0U != vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next) 
          & (vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
             [0U] >> 6U)) & ((0x3fU & vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
                              [0U]) == (0x3fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                 [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                 >> 8U))))) {
        if ((0x38U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                    [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                    << 0x32U) | (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                  << 0x12U) | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                               [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                               >> 0xeU)));
        } else if ((0x39U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                     [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                     << 0x32U) | (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                   << 0x12U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                >> 0xeU))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3aU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                        [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                        << 0x32U) | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                      << 0x12U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                   >> 0xeU)))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3bU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                            >> 0x1aU))));
        } else if ((0x3cU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                             [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                             >> 0x1aU)))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if (VL_LIKELY(((0x3dU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                  >> 0xdU)))))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                >> 0x1aU))))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else {
            VL_WRITEF_NX("[ERROR][/home/ishida/Documents/Kazan/src/CSRUnit.sv,138]\n",0);
        }
        vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
            = (vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
               - (IData)(1U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U] 
            = (IData)(Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val);
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U] 
            = (IData)((Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                       >> 0x20U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = ((0x1000U & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]) 
               | (0xfffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                            >> 0xeU)));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = (0x1000U | vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
        vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next)));
    }
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0ULL;
    if ((((0U != vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next) 
          & (vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
             [1U] >> 6U)) & ((0x3fU & vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
                              [1U]) == (0x3fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                 [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                 >> 8U))))) {
        if ((0x38U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                    [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                    << 0x32U) | (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                  << 0x12U) | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                               [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                               >> 0xeU)));
        } else if ((0x39U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                     [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                     << 0x32U) | (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                   << 0x12U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                >> 0xeU))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3aU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                        [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                        << 0x32U) | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                      << 0x12U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                   >> 0xeU)))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3bU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                            >> 0x1aU))));
        } else if ((0x3cU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                             [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                             >> 0x1aU)))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if (VL_LIKELY(((0x3dU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                  >> 0xdU)))))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                >> 0x1aU))))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else {
            VL_WRITEF_NX("[ERROR][/home/ishida/Documents/Kazan/src/CSRUnit.sv,138]\n",0);
        }
        vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
            = (vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
               - (IData)(1U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U] 
            = (IData)(Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val);
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U] 
            = (IData)((Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                       >> 0x20U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = ((0x1000U & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]) 
               | (0xfffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                            >> 0xeU)));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = (0x1000U | vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
        vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next)));
    }
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0ULL;
    if ((((0U != vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next) 
          & (vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
             [2U] >> 6U)) & ((0x3fU & vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
                              [2U]) == (0x3fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                 [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                 >> 8U))))) {
        if ((0x38U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                    [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                    << 0x32U) | (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                  << 0x12U) | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                               [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                               >> 0xeU)));
        } else if ((0x39U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                     [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                     << 0x32U) | (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                   << 0x12U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                >> 0xeU))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3aU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                        [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                        << 0x32U) | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                      << 0x12U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                   >> 0xeU)))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3bU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                            >> 0x1aU))));
        } else if ((0x3cU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                             [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                             >> 0x1aU)))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if (VL_LIKELY(((0x3dU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                  >> 0xdU)))))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                >> 0x1aU))))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else {
            VL_WRITEF_NX("[ERROR][/home/ishida/Documents/Kazan/src/CSRUnit.sv,138]\n",0);
        }
        vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
            = (vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
               - (IData)(1U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U] 
            = (IData)(Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val);
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U] 
            = (IData)((Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                       >> 0x20U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = ((0x1000U & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]) 
               | (0xfffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                            >> 0xeU)));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = (0x1000U | vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
        vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next)));
    }
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0ULL;
    if ((((0U != vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next) 
          & (vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
             [3U] >> 6U)) & ((0x3fU & vlSymsp->TOP__Top__DOT__csru_renamer_port.committed_instr
                              [3U]) == (0x3fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                 [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                 >> 8U))))) {
        if ((0x38U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                    [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                    << 0x32U) | (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                  << 0x12U) | ((QData)((IData)(
                                                               vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                               [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                               >> 0xeU)));
        } else if ((0x39U == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                     [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                     << 0x32U) | (((QData)((IData)(
                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                   << 0x12U) | ((QData)((IData)(
                                                                vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                >> 0xeU))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3aU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (((QData)((IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                        [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][7U])) 
                        << 0x32U) | (((QData)((IData)(
                                                      vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                      [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][6U])) 
                                      << 0x12U) | ((QData)((IData)(
                                                                   vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                                   [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][5U])) 
                                                   >> 0xeU)))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if ((0x3bU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                            >> 0x1aU))));
        } else if ((0x3cU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                       [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                       >> 0xdU)))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                             [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                             >> 0x1aU)))) 
                   | (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else if (VL_LIKELY(((0x3dU == (0xffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                  [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][9U] 
                                                  >> 0xdU)))))) {
            Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                = ((~ (QData)((IData)((0x1fU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                                                [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                                                >> 0x1aU))))) 
                   & (((QData)((IData)(vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[1U])) 
                       << 0x20U) | (QData)((IData)(
                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.read_res[0U]))));
        } else {
            VL_WRITEF_NX("[ERROR][/home/ishida/Documents/Kazan/src/CSRUnit.sv,138]\n",0);
        }
        vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
            = (vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
               - (IData)(1U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U] 
            = (IData)(Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val);
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U] 
            = (IData)((Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val 
                       >> 0x20U));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = ((0x1000U & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]) 
               | (0xfffU & (vlSelfRef.Top__DOT__csru__DOT__csrq_next
                            [vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next][1U] 
                            >> 0xeU)));
        vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U] 
            = (0x1000U | vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
        vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_rp_next)));
    }
    if ((0x200000U & vlSelfRef.Top__DOT__op_rs_ready_csr
         [0U][9U])) {
        vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next 
            = ((IData)(1U) + vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq_next);
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][0U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][0U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][1U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][1U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][2U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][2U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][3U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][3U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][4U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][4U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][5U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][5U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][6U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][6U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][7U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][7U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][8U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][8U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_next[vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next][9U] 
            = vlSelfRef.Top__DOT__op_rs_ready_csr[0U][9U];
        vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.Top__DOT__csru__DOT__csrq_wp_next)));
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state_next 
        = vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__flush_exe = 0U;
    if (((1U == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state_next)) 
         & (0U == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__num_of_entries_in_pb))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__flush_exe = 1U;
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state_next = 0U;
    }
    if (((IData)(vlSelfRef.Top__DOT__flush_tlb) & (0U 
                                                   == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state_next)))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_state_next = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state_next 
        = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__flush_exe = 0U;
    if (((1U == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state_next)) 
         & (0U == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__num_of_entries_in_pb))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__flush_exe = 1U;
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state_next = 0U;
    }
    if (((IData)(vlSelfRef.Top__DOT__flush_tlb) & (0U 
                                                   == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state_next)))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_state_next = 1U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state_next 
        = vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__flush_exe = 0U;
    if (((1U == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state_next)) 
         & (0U == vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__num_of_entries_in_pb))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__flush_exe = 1U;
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state_next = 0U;
    }
    if (((IData)(vlSelfRef.Top__DOT__flush_tlb) & (0U 
                                                   == (IData)(vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state_next)))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_state_next = 1U;
    }
    vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending_next 
        = vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending;
    vlSelfRef.Top__DOT__decoder__DOT__is_pending_next 
        = vlSelfRef.Top__DOT__decoder__DOT__is_pending;
    if ((1U & (IData)((vlSelfRef.Top__DOT__flush_from_renamer 
                       >> 0x27U)))) {
        vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending_next = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__is_pending_next = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][0U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][1U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][2U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][3U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][4U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][0U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][1U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][2U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][3U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][4U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][0U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][1U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][2U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][3U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][4U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][0U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][1U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][2U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][3U] = 0U;
        vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][4U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][0U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][1U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][2U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][3U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][4U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][5U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][0U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][1U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][2U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][3U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][4U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][5U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][0U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][1U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][2U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][3U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][4U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][5U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][0U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][1U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][2U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][3U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][4U] = 0U;
        vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][5U] = 0U;
    } else {
        if (vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending) {
            vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending_next = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][0U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][1U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][2U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][3U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][4U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [0U][4U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][0U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [1U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][1U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [1U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][2U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [1U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][3U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [1U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][4U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_ld_pending
                [1U][4U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][0U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo_pending
                [0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][1U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo_pending
                [0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][2U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo_pending
                [0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][3U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo_pending
                [0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][4U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo_pending
                [0U][4U];
        } else {
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][0U] 
                = vlSelfRef.Top__DOT__issued_op_ld[0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][1U] 
                = vlSelfRef.Top__DOT__issued_op_ld[0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][2U] 
                = vlSelfRef.Top__DOT__issued_op_ld[0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][3U] 
                = vlSelfRef.Top__DOT__issued_op_ld[0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[0U][4U] 
                = vlSelfRef.Top__DOT__issued_op_ld[0U][4U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][0U] 
                = vlSelfRef.Top__DOT__issued_op_ld[1U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][1U] 
                = vlSelfRef.Top__DOT__issued_op_ld[1U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][2U] 
                = vlSelfRef.Top__DOT__issued_op_ld[1U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][3U] 
                = vlSelfRef.Top__DOT__issued_op_ld[1U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_ld[1U][4U] 
                = vlSelfRef.Top__DOT__issued_op_ld[1U][4U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][0U] 
                = vlSelfRef.Top__DOT__issued_op_st_amo
                [0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][1U] 
                = vlSelfRef.Top__DOT__issued_op_st_amo
                [0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][2U] 
                = vlSelfRef.Top__DOT__issued_op_st_amo
                [0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][3U] 
                = vlSelfRef.Top__DOT__issued_op_st_amo
                [0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo[0U][4U] 
                = vlSelfRef.Top__DOT__issued_op_st_amo
                [0U][4U];
        }
        if (((IData)(vlSelfRef.Top__DOT__stall_from_st5_to_st4) 
             & (~ (IData)(vlSelfRef.Top__DOT__decoder__DOT__is_pending)))) {
            vlSelfRef.Top__DOT__decoder__DOT__is_pending_next = 1U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][0U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][1U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][2U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][3U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][4U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][5U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][0U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][1U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][2U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][3U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][4U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][5U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][0U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][1U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][2U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][3U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][4U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][5U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][0U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][1U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][2U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][3U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][4U] = 0U;
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][5U] = 0U;
        } else {
            if ((1U & (~ (IData)(vlSelfRef.Top__DOT__stall_from_st5_to_st4)))) {
                if (vlSelfRef.Top__DOT__decoder__DOT__is_pending) {
                    vlSelfRef.Top__DOT__decoder__DOT__is_pending_next = 0U;
                }
            }
            if (vlSelfRef.Top__DOT__stall_from_st5_to_st4) {
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][0U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][1U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][2U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][3U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][4U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][5U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][0U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][1U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][2U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][3U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][4U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][5U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][0U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][1U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][2U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][3U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][4U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][5U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][0U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][1U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][2U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][3U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][4U] = 0U;
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][5U] = 0U;
            } else if (vlSelfRef.Top__DOT__decoder__DOT__is_pending) {
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][0U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][1U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][2U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][3U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][4U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][5U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [0U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][0U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][1U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][2U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][3U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][4U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][5U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [1U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][0U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][1U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][2U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][3U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][4U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][5U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [2U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][0U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][1U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][2U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][3U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][4U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][5U] 
                    = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
                    [3U][5U];
            } else {
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][0U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][1U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][2U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][3U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][4U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[0U][5U] 
                    = vlSelfRef.Top__DOT__raw_op[0U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][0U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][1U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][2U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][3U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][4U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[1U][5U] 
                    = vlSelfRef.Top__DOT__raw_op[1U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][0U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][1U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][2U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][3U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][4U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[2U][5U] 
                    = vlSelfRef.Top__DOT__raw_op[2U][5U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][0U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][0U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][1U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][1U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][2U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][2U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][3U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][3U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][4U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][4U];
                vlSelfRef.Top__DOT__decoder__DOT__fetched_content[3U][5U] 
                    = vlSelfRef.Top__DOT__raw_op[3U][5U];
            }
        }
        if (((2U > ((IData)(8U) - vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq)) 
             & (~ (IData)(vlSelfRef.Top__DOT__intprf__DOT__is_csr_pending)))) {
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][0U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][1U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][2U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][3U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][4U] = 0U;
        } else if ((2U > ((IData)(8U) - vlSelfRef.Top__DOT__csru__DOT__num_of_entries_in_csrq))) {
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][0U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][1U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][2U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][3U] = 0U;
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][4U] = 0U;
        } else if (vlSelfRef.Top__DOT__intprf__DOT__is_csr_pending) {
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][0U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_csr_pending
                [0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][1U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_csr_pending
                [0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][2U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_csr_pending
                [0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][3U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_csr_pending
                [0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][4U] 
                = vlSelfRef.Top__DOT__intprf__DOT__op_in_csr_pending
                [0U][4U];
        } else {
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][0U] 
                = vlSelfRef.Top__DOT__issued_op_csr
                [0U][0U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][1U] 
                = vlSelfRef.Top__DOT__issued_op_csr
                [0U][1U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][2U] 
                = vlSelfRef.Top__DOT__issued_op_csr
                [0U][2U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][3U] 
                = vlSelfRef.Top__DOT__issued_op_csr
                [0U][3U];
            vlSelfRef.Top__DOT__intprf__DOT__op_in_csr[0U][4U] 
                = vlSelfRef.Top__DOT__issued_op_csr
                [0U][4U];
        }
    }
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][0U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][0U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][1U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][1U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][2U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][2U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][3U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][3U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][4U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][4U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][5U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [0U][5U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][0U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][0U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][1U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][1U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][2U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][2U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][3U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][3U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][4U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][4U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][5U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [1U][5U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][0U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][0U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][1U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][1U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][2U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][2U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][3U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][3U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][4U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][4U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][5U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [2U][5U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][0U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][0U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][1U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][1U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][2U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][2U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][3U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][3U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][4U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][4U];
    vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][5U] 
        = vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending
        [3U][5U];
    if ((1U & (~ (IData)((vlSelfRef.Top__DOT__flush_from_renamer 
                          >> 0x27U))))) {
        if (((IData)(vlSelfRef.Top__DOT__stall_from_st5_to_st4) 
             & (~ (IData)(vlSelfRef.Top__DOT__decoder__DOT__is_pending)))) {
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][0U] 
                = vlSelfRef.Top__DOT__raw_op[0U][0U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][1U] 
                = vlSelfRef.Top__DOT__raw_op[0U][1U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][2U] 
                = vlSelfRef.Top__DOT__raw_op[0U][2U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][3U] 
                = vlSelfRef.Top__DOT__raw_op[0U][3U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][4U] 
                = vlSelfRef.Top__DOT__raw_op[0U][4U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[0U][5U] 
                = vlSelfRef.Top__DOT__raw_op[0U][5U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][0U] 
                = vlSelfRef.Top__DOT__raw_op[1U][0U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][1U] 
                = vlSelfRef.Top__DOT__raw_op[1U][1U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][2U] 
                = vlSelfRef.Top__DOT__raw_op[1U][2U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][3U] 
                = vlSelfRef.Top__DOT__raw_op[1U][3U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][4U] 
                = vlSelfRef.Top__DOT__raw_op[1U][4U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[1U][5U] 
                = vlSelfRef.Top__DOT__raw_op[1U][5U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][0U] 
                = vlSelfRef.Top__DOT__raw_op[2U][0U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][1U] 
                = vlSelfRef.Top__DOT__raw_op[2U][1U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][2U] 
                = vlSelfRef.Top__DOT__raw_op[2U][2U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][3U] 
                = vlSelfRef.Top__DOT__raw_op[2U][3U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][4U] 
                = vlSelfRef.Top__DOT__raw_op[2U][4U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[2U][5U] 
                = vlSelfRef.Top__DOT__raw_op[2U][5U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][0U] 
                = vlSelfRef.Top__DOT__raw_op[3U][0U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][1U] 
                = vlSelfRef.Top__DOT__raw_op[3U][1U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][2U] 
                = vlSelfRef.Top__DOT__raw_op[3U][2U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][3U] 
                = vlSelfRef.Top__DOT__raw_op[3U][3U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][4U] 
                = vlSelfRef.Top__DOT__raw_op[3U][4U];
            vlSelfRef.Top__DOT__decoder__DOT__fetched_content_pending_next[3U][5U] 
                = vlSelfRef.Top__DOT__raw_op[3U][5U];
        }
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_data[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_w_bit_data
        [3U][1U];
    IData/*31:0*/ __Vilp7;
    __Vilp7 = 0U;
    while ((__Vilp7 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[__Vilp7] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt
            [__Vilp7];
        __Vilp7 = ((IData)(1U) + __Vilp7);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__0__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    IData/*31:0*/ __Vilp8;
    __Vilp8 = 0U;
    while ((__Vilp8 <= 0x3fU)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[__Vilp8] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt
            [__Vilp8];
        __Vilp8 = ((IData)(1U) + __Vilp8);
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__lvt_next[vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[1U]] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [2U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[2U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_en
          [3U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__cb_info_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__1__KET____DOT__cb_info__DOT__bypass_table[3U] = 3U;
    }
    IData/*31:0*/ __Vilp9;
    __Vilp9 = 0U;
    while ((__Vilp9 <= 0x34U)) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt_next[__Vilp9] 
            = vlSelfRef.Top__DOT__cachesubsystem__DOT__dcache__DOT__cb__DOT__genblk1__BRA__2__KET____DOT__cb_info__DOT__lvt
            [__Vilp9];
        __Vilp9 = ((IData)(1U) + __Vilp9);
    }
}
