// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__94(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__94\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[0U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[1U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[2U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[3U][0U] = 0U;
    if ((2U & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__write_buf
         [0U][4U])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[(3U 
                                                                                & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__write_buf
                                                                                [0U][2U])][0U] 
            = (0x3fU & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__write_buf
                        [0U][2U] >> 2U));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[3U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[(3U 
                                                                                & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__write_buf
                                                                                [0U][2U])][0U] = 1U;
    } else {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[0U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[1U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[2U][0U] = 0U;
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[3U][0U] = 0U;
    }
    if ((0x100U & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.invalidate_req))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx[(3U 
                                                                                & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.invalidate_req))][0U] 
            = (0x3fU & ((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.invalidate_req) 
                        >> 2U));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en[(3U 
                                                                                & (IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.invalidate_req))][0U] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en[1U] = 0U;
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
         [0U][0xaU])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx[0U] 
            = (0x1ffU & (VL_SHIFTL_III(9,32,32, (0x3fU 
                                                 & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                    [0U][4U] 
                                                    >> 9U)), 3U) 
                         + (7U & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                  [0U][4U] >> 6U))));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en[0U] = 1U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][3U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][4U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][5U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][3U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][4U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][5U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][3U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][4U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][5U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][1U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][2U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][3U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][4U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[3U][5U] = 0U;
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
         [0U][0xaU])) {
        if ((1U & (~ (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                      [0U][5U] >> 0x1bU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][0U] 
                = (IData)((0x7fffffffffULL & (((QData)((IData)(
                                                               vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                               [0U][7U])) 
                                               << 0x24U) 
                                              | (((QData)((IData)(
                                                                  vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                  [0U][6U])) 
                                                  << 4U) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                    [0U][5U])) 
                                                    >> 0x1cU)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][1U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][1U]) | (IData)(((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                              [0U][7U])) 
                                              << 0x24U) 
                                             | (((QData)((IData)(
                                                                 vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                 [0U][6U])) 
                                                 << 4U) 
                                                | ((QData)((IData)(
                                                                   vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                   [0U][5U])) 
                                                   >> 0x1cU)))) 
                                         >> 0x20U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][1U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][1U]) | ((IData)((((QData)((IData)(
                                                           vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                           [0U][3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [0U][2U])))) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][2U] 
                = (((IData)((((QData)((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                              [0U][3U])) 
                              << 0x20U) | (QData)((IData)(
                                                          vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                          [0U][2U])))) 
                    >> 0x19U) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [0U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                             [0U][2U]))) 
                                          >> 0x20U)) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][3U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][3U]) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [0U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                             [0U][2U]))) 
                                          >> 0x20U)) 
                                 >> 0x19U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][3U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][3U]) | (0xffffff80U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                 [0U][8U] 
                                                 << 0x1dU) 
                                                | (0x1fffff80U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                      [0U][7U] 
                                                      >> 3U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][4U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][4U]) | (0x7fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                          [0U][8U] 
                                          >> 3U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][4U] 
                = (0x80U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [0U][4U]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][4U] 
                = ((0xffU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][4U]) | (0xffffff00U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                 [0U][0xaU] 
                                                 << 0x1eU) 
                                                | (0x3fffff00U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                      [0U][9U] 
                                                      >> 2U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][5U] 
                = ((0x100U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [0U][5U]) | (0xffU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                          [0U][0xaU] 
                                          >> 2U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[0U][5U] 
                = (0x100U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [0U][5U]);
        }
    }
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
         [1U][0xaU])) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx[1U] 
            = (0x1ffU & (VL_SHIFTL_III(9,32,32, (0x3fU 
                                                 & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                    [1U][4U] 
                                                    >> 9U)), 3U) 
                         + (7U & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                  [1U][4U] >> 6U))));
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en[1U] = 1U;
        if ((1U & (~ (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                      [1U][5U] >> 0x1bU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][0U] 
                = (IData)((0x7fffffffffULL & (((QData)((IData)(
                                                               vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                               [1U][7U])) 
                                               << 0x24U) 
                                              | (((QData)((IData)(
                                                                  vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                  [1U][6U])) 
                                                  << 4U) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                    [1U][5U])) 
                                                    >> 0x1cU)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][1U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][1U]) | (IData)(((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                              [1U][7U])) 
                                              << 0x24U) 
                                             | (((QData)((IData)(
                                                                 vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                 [1U][6U])) 
                                                 << 4U) 
                                                | ((QData)((IData)(
                                                                   vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                                   [1U][5U])) 
                                                   >> 0x1cU)))) 
                                         >> 0x20U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][1U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][1U]) | ((IData)((((QData)((IData)(
                                                           vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                           [1U][3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [1U][2U])))) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][2U] 
                = (((IData)((((QData)((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                              [1U][3U])) 
                              << 0x20U) | (QData)((IData)(
                                                          vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                          [1U][2U])))) 
                    >> 0x19U) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [1U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                             [1U][2U]))) 
                                          >> 0x20U)) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][3U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][3U]) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                            [1U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                             [1U][2U]))) 
                                          >> 0x20U)) 
                                 >> 0x19U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][3U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][3U]) | (0xffffff80U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                 [1U][8U] 
                                                 << 0x1dU) 
                                                | (0x1fffff80U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                      [1U][7U] 
                                                      >> 3U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][4U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][4U]) | (0x7fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                          [1U][8U] 
                                          >> 3U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][4U] 
                = (0x80U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [1U][4U]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][4U] 
                = ((0xffU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][4U]) | (0xffffff00U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                 [1U][0xaU] 
                                                 << 0x1eU) 
                                                | (0x3fffff00U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                      [1U][9U] 
                                                      >> 2U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][5U] 
                = ((0x100U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [1U][5U]) | (0xffU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                          [1U][0xaU] 
                                          >> 2U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[1U][5U] 
                = (0x100U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [1U][5U]);
        }
    }
    if ((0x400U & vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
         [0U][0xaU])) {
        if ((1U & (~ (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                      [0U][5U] >> 0x1bU)))) {
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][0U] 
                = (IData)((0x7fffffffffULL & (((QData)((IData)(
                                                               vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                               [0U][7U])) 
                                               << 0x24U) 
                                              | (((QData)((IData)(
                                                                  vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                                  [0U][6U])) 
                                                  << 4U) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                                    [0U][5U])) 
                                                    >> 0x1cU)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][1U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][1U]) | (IData)(((0x7fffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                              [0U][7U])) 
                                              << 0x24U) 
                                             | (((QData)((IData)(
                                                                 vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                                 [0U][6U])) 
                                                 << 4U) 
                                                | ((QData)((IData)(
                                                                   vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                                   [0U][5U])) 
                                                   >> 0x1cU)))) 
                                         >> 0x20U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][1U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][1U]) | ((IData)((((QData)((IData)(
                                                           vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                           [0U][3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                            [0U][2U])))) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][2U] 
                = (((IData)((((QData)((IData)(vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                              [0U][3U])) 
                              << 0x20U) | (QData)((IData)(
                                                          vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                          [0U][2U])))) 
                    >> 0x19U) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                            [0U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                             [0U][2U]))) 
                                          >> 0x20U)) 
                                 << 7U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][3U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][3U]) | ((IData)(((((QData)((IData)(
                                                            vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                            [0U][3U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                             [0U][2U]))) 
                                          >> 0x20U)) 
                                 >> 0x19U));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][3U] 
                = ((0x7fU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][3U]) | (0xffffff80U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                 [0U][8U] 
                                                 << 0x1dU) 
                                                | (0x1fffff80U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                                      [0U][7U] 
                                                      >> 3U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][4U] 
                = ((0xffffff80U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][4U]) | (0x7fU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.read_req
                                          [0U][8U] 
                                          >> 3U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][4U] 
                = (0x80U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [2U][4U]);
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][4U] 
                = ((0xffU & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][4U]) | (0xffffff00U & ((vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                 [0U][0xaU] 
                                                 << 0x1eU) 
                                                | (0x3fffff00U 
                                                   & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                                      [0U][9U] 
                                                      >> 2U)))));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][5U] 
                = ((0x100U & vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                    [2U][5U]) | (0xffU & (vlSymsp->TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.write_req
                                          [0U][0xaU] 
                                          >> 2U)));
            vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb[2U][5U] 
                = (0x100U | vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
                   [2U][5U]);
        }
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_ram_idx[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_ram_idx
        [3U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [0U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [0U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [1U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [1U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [2U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [2U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en[0U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [3U][0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__cb_info__w_en[1U] 
        = vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_info_w_en
        [3U][1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__0__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__1__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__2__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [0U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_en
          [1U] & vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__cb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__cb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__cachesubsystem__DOT__icache__DOT__cb__DOT__genblk2__BRA__3__KET____DOT__cb_data__DOT__bypass_table[1U] = 2U;
    }
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][0U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][0U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][1U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][1U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][2U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][2U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][3U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][3U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][4U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][4U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[0U][5U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [0U][5U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][0U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][0U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][1U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][1U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][2U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][2U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][3U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][3U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][4U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][4U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[1U][5U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [1U][5U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][0U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][0U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][1U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][1U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][2U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][2U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][3U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][3U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][4U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][4U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[2U][5U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [2U][5U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][0U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][0U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][1U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][1U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][2U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][2U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][3U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][3U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][4U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][4U];
    vlSymsp->TOP__Top__DOT__itlb_port.req[3U][5U] = 
        vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellout__icache__req_to_tlb
        [3U][5U];
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
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__95(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__95\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<7>/*223:0*/ Top__DOT____Vlvbound_hc0428dcd__0;
    VL_ZERO_W(224, Top__DOT____Vlvbound_hc0428dcd__0);
    VlWide<7>/*223:0*/ Top__DOT____Vlvbound_h9b7c3d89__0;
    VL_ZERO_W(224, Top__DOT____Vlvbound_h9b7c3d89__0);
    VlWide<7>/*223:0*/ Top__DOT____Vlvbound_hbd101bae__0;
    VL_ZERO_W(224, Top__DOT____Vlvbound_hbd101bae__0);
    VlWide<7>/*223:0*/ Top__DOT____Vlvbound_h4e78b4a0__0;
    VL_ZERO_W(224, Top__DOT____Vlvbound_h4e78b4a0__0);
    VlWide<7>/*223:0*/ Top__DOT____Vlvbound_h8ca1ffd1__0;
    VL_ZERO_W(224, Top__DOT____Vlvbound_h8ca1ffd1__0);
    QData/*49:0*/ Top__DOT__btb__DOT____Vlvbound_hc4c9566f__0;
    Top__DOT__btb__DOT____Vlvbound_hc4c9566f__0 = 0;
    QData/*63:0*/ Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val;
    Top__DOT__csru__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__new_csr_val = 0;
    VlWide<6>/*168:0*/ Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0;
    VL_ZERO_W(169, Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0);
    // Body
    vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending_next 
        = vlSelfRef.Top__DOT__intprf__DOT__is_ldst_pending;
    vlSelfRef.Top__DOT__decoder__DOT__is_pending_next 
        = vlSelfRef.Top__DOT__decoder__DOT__is_pending;
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
    vlSelfRef.Top__DOT__btb__DOT__btb_w_data[0U] = 0ULL;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x5fU)) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl_next[__Vilp1] 
            = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__rfl
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
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
    IData/*31:0*/ __Vilp2;
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x5fU)) {
        vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_next[__Vilp2] 
            = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
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
        } else if ((1U & (~ (IData)(vlSelfRef.Top__DOT__stall_from_st5_to_st4)))) {
            if (vlSelfRef.Top__DOT__decoder__DOT__is_pending) {
                vlSelfRef.Top__DOT__decoder__DOT__is_pending_next = 0U;
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
    Top__DOT____Vlvbound_hc0428dcd__0[0U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][0U];
    Top__DOT____Vlvbound_hc0428dcd__0[1U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][1U];
    Top__DOT____Vlvbound_hc0428dcd__0[2U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][2U];
    Top__DOT____Vlvbound_hc0428dcd__0[3U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][3U];
    Top__DOT____Vlvbound_hc0428dcd__0[4U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][4U];
    Top__DOT____Vlvbound_hc0428dcd__0[5U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][5U];
    Top__DOT____Vlvbound_hc0428dcd__0[6U] = vlSelfRef.Top__DOT__result_op_ari
        [0U][6U];
    vlSelfRef.Top__DOT__result_op[0U][0U] = Top__DOT____Vlvbound_hc0428dcd__0[0U];
    vlSelfRef.Top__DOT__result_op[0U][1U] = Top__DOT____Vlvbound_hc0428dcd__0[1U];
    vlSelfRef.Top__DOT__result_op[0U][2U] = Top__DOT____Vlvbound_hc0428dcd__0[2U];
    vlSelfRef.Top__DOT__result_op[0U][3U] = Top__DOT____Vlvbound_hc0428dcd__0[3U];
    vlSelfRef.Top__DOT__result_op[0U][4U] = Top__DOT____Vlvbound_hc0428dcd__0[4U];
    vlSelfRef.Top__DOT__result_op[0U][5U] = Top__DOT____Vlvbound_hc0428dcd__0[5U];
    vlSelfRef.Top__DOT__result_op[0U][6U] = Top__DOT____Vlvbound_hc0428dcd__0[6U];
    Top__DOT____Vlvbound_hc0428dcd__0[0U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][0U];
    Top__DOT____Vlvbound_hc0428dcd__0[1U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][1U];
    Top__DOT____Vlvbound_hc0428dcd__0[2U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][2U];
    Top__DOT____Vlvbound_hc0428dcd__0[3U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][3U];
    Top__DOT____Vlvbound_hc0428dcd__0[4U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][4U];
    Top__DOT____Vlvbound_hc0428dcd__0[5U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][5U];
    Top__DOT____Vlvbound_hc0428dcd__0[6U] = vlSelfRef.Top__DOT__result_op_ari
        [1U][6U];
    vlSelfRef.Top__DOT__result_op[1U][0U] = Top__DOT____Vlvbound_hc0428dcd__0[0U];
    vlSelfRef.Top__DOT__result_op[1U][1U] = Top__DOT____Vlvbound_hc0428dcd__0[1U];
    vlSelfRef.Top__DOT__result_op[1U][2U] = Top__DOT____Vlvbound_hc0428dcd__0[2U];
    vlSelfRef.Top__DOT__result_op[1U][3U] = Top__DOT____Vlvbound_hc0428dcd__0[3U];
    vlSelfRef.Top__DOT__result_op[1U][4U] = Top__DOT____Vlvbound_hc0428dcd__0[4U];
    vlSelfRef.Top__DOT__result_op[1U][5U] = Top__DOT____Vlvbound_hc0428dcd__0[5U];
    vlSelfRef.Top__DOT__result_op[1U][6U] = Top__DOT____Vlvbound_hc0428dcd__0[6U];
    Top__DOT____Vlvbound_h9b7c3d89__0[0U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][0U];
    Top__DOT____Vlvbound_h9b7c3d89__0[1U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][1U];
    Top__DOT____Vlvbound_h9b7c3d89__0[2U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][2U];
    Top__DOT____Vlvbound_h9b7c3d89__0[3U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][3U];
    Top__DOT____Vlvbound_h9b7c3d89__0[4U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][4U];
    Top__DOT____Vlvbound_h9b7c3d89__0[5U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][5U];
    Top__DOT____Vlvbound_h9b7c3d89__0[6U] = vlSelfRef.Top__DOT__result_op_ld
        [0U][6U];
    vlSelfRef.Top__DOT__result_op[2U][0U] = Top__DOT____Vlvbound_h9b7c3d89__0[0U];
    vlSelfRef.Top__DOT__result_op[2U][1U] = Top__DOT____Vlvbound_h9b7c3d89__0[1U];
    vlSelfRef.Top__DOT__result_op[2U][2U] = Top__DOT____Vlvbound_h9b7c3d89__0[2U];
    vlSelfRef.Top__DOT__result_op[2U][3U] = Top__DOT____Vlvbound_h9b7c3d89__0[3U];
    vlSelfRef.Top__DOT__result_op[2U][4U] = Top__DOT____Vlvbound_h9b7c3d89__0[4U];
    vlSelfRef.Top__DOT__result_op[2U][5U] = Top__DOT____Vlvbound_h9b7c3d89__0[5U];
    vlSelfRef.Top__DOT__result_op[2U][6U] = Top__DOT____Vlvbound_h9b7c3d89__0[6U];
    Top__DOT____Vlvbound_h9b7c3d89__0[0U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][0U];
    Top__DOT____Vlvbound_h9b7c3d89__0[1U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][1U];
    Top__DOT____Vlvbound_h9b7c3d89__0[2U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][2U];
    Top__DOT____Vlvbound_h9b7c3d89__0[3U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][3U];
    Top__DOT____Vlvbound_h9b7c3d89__0[4U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][4U];
    Top__DOT____Vlvbound_h9b7c3d89__0[5U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][5U];
    Top__DOT____Vlvbound_h9b7c3d89__0[6U] = vlSelfRef.Top__DOT__result_op_ld
        [1U][6U];
    vlSelfRef.Top__DOT__result_op[3U][0U] = Top__DOT____Vlvbound_h9b7c3d89__0[0U];
    vlSelfRef.Top__DOT__result_op[3U][1U] = Top__DOT____Vlvbound_h9b7c3d89__0[1U];
    vlSelfRef.Top__DOT__result_op[3U][2U] = Top__DOT____Vlvbound_h9b7c3d89__0[2U];
    vlSelfRef.Top__DOT__result_op[3U][3U] = Top__DOT____Vlvbound_h9b7c3d89__0[3U];
    vlSelfRef.Top__DOT__result_op[3U][4U] = Top__DOT____Vlvbound_h9b7c3d89__0[4U];
    vlSelfRef.Top__DOT__result_op[3U][5U] = Top__DOT____Vlvbound_h9b7c3d89__0[5U];
    vlSelfRef.Top__DOT__result_op[3U][6U] = Top__DOT____Vlvbound_h9b7c3d89__0[6U];
    Top__DOT____Vlvbound_hbd101bae__0[0U] = vlSelfRef.Top__DOT__result_op_st
        [0U][0U];
    Top__DOT____Vlvbound_hbd101bae__0[1U] = vlSelfRef.Top__DOT__result_op_st
        [0U][1U];
    Top__DOT____Vlvbound_hbd101bae__0[2U] = vlSelfRef.Top__DOT__result_op_st
        [0U][2U];
    Top__DOT____Vlvbound_hbd101bae__0[3U] = vlSelfRef.Top__DOT__result_op_st
        [0U][3U];
    Top__DOT____Vlvbound_hbd101bae__0[4U] = vlSelfRef.Top__DOT__result_op_st
        [0U][4U];
    Top__DOT____Vlvbound_hbd101bae__0[5U] = vlSelfRef.Top__DOT__result_op_st
        [0U][5U];
    Top__DOT____Vlvbound_hbd101bae__0[6U] = vlSelfRef.Top__DOT__result_op_st
        [0U][6U];
    vlSelfRef.Top__DOT__result_op[4U][0U] = Top__DOT____Vlvbound_hbd101bae__0[0U];
    vlSelfRef.Top__DOT__result_op[4U][1U] = Top__DOT____Vlvbound_hbd101bae__0[1U];
    vlSelfRef.Top__DOT__result_op[4U][2U] = Top__DOT____Vlvbound_hbd101bae__0[2U];
    vlSelfRef.Top__DOT__result_op[4U][3U] = Top__DOT____Vlvbound_hbd101bae__0[3U];
    vlSelfRef.Top__DOT__result_op[4U][4U] = Top__DOT____Vlvbound_hbd101bae__0[4U];
    vlSelfRef.Top__DOT__result_op[4U][5U] = Top__DOT____Vlvbound_hbd101bae__0[5U];
    vlSelfRef.Top__DOT__result_op[4U][6U] = Top__DOT____Vlvbound_hbd101bae__0[6U];
    Top__DOT____Vlvbound_h4e78b4a0__0[0U] = vlSelfRef.Top__DOT__result_op_mmio[0U];
    Top__DOT____Vlvbound_h4e78b4a0__0[1U] = vlSelfRef.Top__DOT__result_op_mmio[1U];
    Top__DOT____Vlvbound_h4e78b4a0__0[2U] = vlSelfRef.Top__DOT__result_op_mmio[2U];
    Top__DOT____Vlvbound_h4e78b4a0__0[3U] = vlSelfRef.Top__DOT__result_op_mmio[3U];
    Top__DOT____Vlvbound_h4e78b4a0__0[4U] = vlSelfRef.Top__DOT__result_op_mmio[4U];
    Top__DOT____Vlvbound_h4e78b4a0__0[5U] = vlSelfRef.Top__DOT__result_op_mmio[5U];
    Top__DOT____Vlvbound_h4e78b4a0__0[6U] = vlSelfRef.Top__DOT__result_op_mmio[6U];
    vlSelfRef.Top__DOT__result_op[5U][0U] = Top__DOT____Vlvbound_h4e78b4a0__0[0U];
    vlSelfRef.Top__DOT__result_op[5U][1U] = Top__DOT____Vlvbound_h4e78b4a0__0[1U];
    vlSelfRef.Top__DOT__result_op[5U][2U] = Top__DOT____Vlvbound_h4e78b4a0__0[2U];
    vlSelfRef.Top__DOT__result_op[5U][3U] = Top__DOT____Vlvbound_h4e78b4a0__0[3U];
    vlSelfRef.Top__DOT__result_op[5U][4U] = Top__DOT____Vlvbound_h4e78b4a0__0[4U];
    vlSelfRef.Top__DOT__result_op[5U][5U] = Top__DOT____Vlvbound_h4e78b4a0__0[5U];
    vlSelfRef.Top__DOT__result_op[5U][6U] = Top__DOT____Vlvbound_h4e78b4a0__0[6U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[0U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][0U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[1U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][1U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[2U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][2U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[3U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][3U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[4U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][4U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[5U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][5U];
    Top__DOT____Vlvbound_h8ca1ffd1__0[6U] = vlSelfRef.Top__DOT__result_op_csr
        [0U][6U];
    vlSelfRef.Top__DOT__result_op[6U][0U] = Top__DOT____Vlvbound_h8ca1ffd1__0[0U];
    vlSelfRef.Top__DOT__result_op[6U][1U] = Top__DOT____Vlvbound_h8ca1ffd1__0[1U];
    vlSelfRef.Top__DOT__result_op[6U][2U] = Top__DOT____Vlvbound_h8ca1ffd1__0[2U];
    vlSelfRef.Top__DOT__result_op[6U][3U] = Top__DOT____Vlvbound_h8ca1ffd1__0[3U];
    vlSelfRef.Top__DOT__result_op[6U][4U] = Top__DOT____Vlvbound_h8ca1ffd1__0[4U];
    vlSelfRef.Top__DOT__result_op[6U][5U] = Top__DOT____Vlvbound_h8ca1ffd1__0[5U];
    vlSelfRef.Top__DOT__result_op[6U][6U] = Top__DOT____Vlvbound_h8ca1ffd1__0[6U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][0U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][1U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][2U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][3U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][4U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[0U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][0U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][1U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][2U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][3U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][4U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][5U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[0U][4U] 
        = (0x80U | vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
           [0U][4U]);
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][0U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][1U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][2U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][3U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][4U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[1U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][0U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][1U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][2U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][3U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][4U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][5U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[1U][4U] 
        = (0x80U | vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
           [1U][4U]);
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][0U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][1U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][2U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][3U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][4U];
    Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U] 
        = vlSymsp->TOP__Top__DOT__dtlb_port.req[2U][5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][0U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[0U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][1U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[1U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][2U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[2U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][3U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[3U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][4U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[4U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][5U] 
        = Top__DOT__mmu__DOT____Vlvbound_h6111bb41__0[5U];
    vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache[2U][4U] 
        = (0x80U | vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
           [2U][4U]);
    IData/*31:0*/ __Vilp3;
    __Vilp3 = 0U;
    while ((__Vilp3 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[__Vilp3] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt
            [__Vilp3];
        __Vilp3 = ((IData)(1U) + __Vilp3);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp4;
    __Vilp4 = 0U;
    while ((__Vilp4 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[__Vilp4] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt
            [__Vilp4];
        __Vilp4 = ((IData)(1U) + __Vilp4);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp5;
    __Vilp5 = 0U;
    while ((__Vilp5 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt_next[__Vilp5] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt
            [__Vilp5];
        __Vilp5 = ((IData)(1U) + __Vilp5);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp6;
    __Vilp6 = 0U;
    while ((__Vilp6 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[__Vilp6] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt
            [__Vilp6];
        __Vilp6 = ((IData)(1U) + __Vilp6);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp7;
    __Vilp7 = 0U;
    while ((__Vilp7 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[__Vilp7] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt
            [__Vilp7];
        __Vilp7 = ((IData)(1U) + __Vilp7);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp8;
    __Vilp8 = 0U;
    while ((__Vilp8 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[__Vilp8] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt
            [__Vilp8];
        __Vilp8 = ((IData)(1U) + __Vilp8);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx[3U]] = 3U;
    }
    IData/*31:0*/ __Vilp9;
    __Vilp9 = 0U;
    while ((__Vilp9 <= 0xffU)) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt_next[__Vilp9] 
            = vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt
            [__Vilp9];
        __Vilp9 = ((IData)(1U) + __Vilp9);
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
        [0U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx[0U]] = 0U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
        [1U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx[1U]] = 1U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
        [2U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx[2U]] = 2U;
    }
    if (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
        [3U]) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__lvt_next[vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx[3U]] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__tlb_info__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__6__KET____DOT__tlb_info__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__tlb_info__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk1__BRA__7__KET____DOT__tlb_info__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__4__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__4__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[0U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[0U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[0U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[0U] = 7U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[1U] = 4U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[1U] = 5U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [2U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[1U] = 6U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_en
          [3U]) & (vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT____Vcellinp__genblk2__BRA__5__KET____DOT__tlb_data__w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__genblk2__BRA__5__KET____DOT__tlb_data__DOT__bypass_table[1U] = 7U;
    }
    vlSelfRef.Top__DOT__irb__DOT__is_pending_next = vlSelfRef.Top__DOT__irb__DOT__is_pending;
    vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[0U] 
        = vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending[0U];
    vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[1U] 
        = vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending[1U];
    vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[2U] 
        = vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending[2U];
    if (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
         & (~ (IData)(vlSelfRef.Top__DOT__irb__DOT__is_pending)))) {
        vlSelfRef.Top__DOT__irb__DOT__is_pending_next = 1U;
        vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[0U] 
            = vlSelfRef.Top__DOT__pc_from_st1_to_st2[0U];
        vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[1U] 
            = vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U];
        vlSelfRef.Top__DOT__irb__DOT__pc_from_st1_pending_next[2U] 
            = vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U];
    } else if ((1U & (~ (IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2)))) {
        if (vlSelfRef.Top__DOT__irb__DOT__is_pending) {
            vlSelfRef.Top__DOT__irb__DOT__is_pending_next = 0U;
        }
    }
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
    Top__DOT__btb__DOT____Vlvbound_hc4c9566f__0 = vlSelfRef.Top__DOT__btb__DOT__btb_w_data
        [0U];
    vlSelfRef.Top__DOT__btb__DOT__btb_w_bit_data[0U] 
        = Top__DOT__btb__DOT____Vlvbound_hc4c9566f__0;
    IData/*31:0*/ __Vilp10;
    __Vilp10 = 0U;
    while ((__Vilp10 <= 0x194U)) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_next[__Vilp10] 
            = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt
            [__Vilp10];
        __Vilp10 = ((IData)(1U) + __Vilp10);
    }
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__96(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__96\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*38:0*/ Top__DOT__predictor__DOT__first_instr_addr;
    Top__DOT__predictor__DOT__first_instr_addr = 0;
    QData/*38:0*/ Top__DOT__btb__DOT__first_instr_addr;
    Top__DOT__btb__DOT__first_instr_addr = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_h4d549968__0;
    Top__DOT__intprf__DOT____Vlvbound_h4d549968__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0;
    Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_hb4dd70ba__0;
    Top__DOT__intprf__DOT____Vlvbound_hb4dd70ba__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_hb50f7a69__0;
    Top__DOT__intprf__DOT____Vlvbound_hb50f7a69__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_h0dc5a57f__0;
    Top__DOT__intprf__DOT____Vlvbound_h0dc5a57f__0 = 0;
    CData/*6:0*/ Top__DOT__intprf__DOT____Vlvbound_h0dcaf5b0__0;
    Top__DOT__intprf__DOT____Vlvbound_h0dcaf5b0__0 = 0;
    CData/*6:0*/ Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0 = 0;
    CData/*6:0*/ Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0 = 0;
    QData/*63:0*/ Top__DOT__csrrf__DOT__new_csr_val;
    Top__DOT__csrrf__DOT__new_csr_val = 0;
    QData/*63:0*/ Top__DOT__csrrf__DOT__unnamedblk1__DOT__write_mask;
    Top__DOT__csrrf__DOT__unnamedblk1__DOT__write_mask = 0;
    SData/*11:0*/ __Vfunc_get_write_mask__256__csr_name;
    __Vfunc_get_write_mask__256__csr_name = 0;
    QData/*63:0*/ __Vfunc_get_write_mask__256__original_val;
    __Vfunc_get_write_mask__256__original_val = 0;
    QData/*63:0*/ __Vfunc_mie_get_write_mask__312__tmp;
    __Vfunc_mie_get_write_mask__312__tmp = 0;
    QData/*63:0*/ __Vfunc_mideleg_get_write_mask__313__tmp;
    __Vfunc_mideleg_get_write_mask__313__tmp = 0;
    QData/*63:0*/ __Vfunc_medeleg_get_write_mask__314__tmp;
    __Vfunc_medeleg_get_write_mask__314__tmp = 0;
    QData/*63:0*/ __Vfunc_misa_get_write_mask__315__tmp;
    __Vfunc_misa_get_write_mask__315__tmp = 0;
    // Body
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0x195U;
    while ((__Vilp1 <= 0x1ffU)) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_next[__Vilp1] 
            = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt
            [__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U]) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_next[vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx[0U]] = 0U;
    }
    Top__DOT__intprf__DOT____Vlvbound_h4d549968__0 
        = (0x7fU & (vlSelfRef.Top__DOT__issued_op_ari
                    [0U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[0U] 
        = Top__DOT__intprf__DOT____Vlvbound_h4d549968__0;
    Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0 
        = (0x7fU & (vlSelfRef.Top__DOT__issued_op_ari
                    [0U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[1U] 
        = Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0;
    Top__DOT__intprf__DOT____Vlvbound_h4d549968__0 
        = (0x7fU & (vlSelfRef.Top__DOT__issued_op_ari
                    [1U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[2U] 
        = Top__DOT__intprf__DOT____Vlvbound_h4d549968__0;
    Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0 
        = (0x7fU & (vlSelfRef.Top__DOT__issued_op_ari
                    [1U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[3U] 
        = Top__DOT__intprf__DOT____Vlvbound_h1c1e6994__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_ld
                    [0U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[4U] 
        = Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_ld
                    [0U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[5U] 
        = Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_ld
                    [1U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[6U] 
        = Top__DOT__intprf__DOT____Vlvbound_hd0c163b7__0;
    Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_ld
                    [1U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[7U] 
        = Top__DOT__intprf__DOT____Vlvbound_hd0c0b2c8__0;
    Top__DOT__intprf__DOT____Vlvbound_hb4dd70ba__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo
                    [0U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[8U] 
        = Top__DOT__intprf__DOT____Vlvbound_hb4dd70ba__0;
    Top__DOT__intprf__DOT____Vlvbound_hb50f7a69__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_st_amo
                    [0U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[9U] 
        = Top__DOT__intprf__DOT____Vlvbound_hb50f7a69__0;
    Top__DOT__intprf__DOT____Vlvbound_h0dc5a57f__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_csr
                    [0U][2U] >> 0x14U));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[0xaU] 
        = Top__DOT__intprf__DOT____Vlvbound_h0dc5a57f__0;
    Top__DOT__intprf__DOT____Vlvbound_h0dcaf5b0__0 
        = (0x7fU & (vlSelfRef.Top__DOT__intprf__DOT__op_in_csr
                    [0U][2U] >> 0xdU));
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx[0xbU] 
        = Top__DOT__intprf__DOT____Vlvbound_h0dcaf5b0__0;
    vlSelfRef.Top__DOT__csrrf__DOT__old_csr_val = vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
        [([&]() {
            vlSelfRef.__Vfunc_internal_idx__255__csr_name 
                = (0xfffU & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
            {
                if ((0x800U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x43U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x42U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x41U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x40U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3fU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x38U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 7U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 9U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 8U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc2U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc1U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbfU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbeU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbdU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbcU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbbU;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbaU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb8U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb7U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb6U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb5U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb4U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb3U;
                                goto __Vlabel377;
                            }
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb2U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb1U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xafU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xaeU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xadU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xacU;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xabU;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xaaU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa9U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa8U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa7U;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa6U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa5U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xeU;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa4U;
                            goto __Vlabel377;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc2U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc1U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbfU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbeU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbdU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbcU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbbU;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbaU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb9U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb8U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb7U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb6U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb5U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb4U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb3U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb2U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb1U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xb0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xafU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xaeU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xadU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xacU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xabU;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xaaU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa8U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa7U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa6U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa5U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa4U;
                                goto __Vlabel377;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe9U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe8U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe7U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe6U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe5U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe4U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe3U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe2U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe1U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x53U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa3U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa2U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa1U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xa0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3aU;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x99U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x98U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x97U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x96U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x95U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x94U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x93U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x92U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x91U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x90U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8fU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8dU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x8aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x89U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x88U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x87U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x86U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x85U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x84U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x83U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x82U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x81U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x80U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7fU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7dU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7bU;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x7aU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x79U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x78U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x77U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x76U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x75U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x74U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x73U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x72U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x71U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x70U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6fU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6eU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6dU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6cU;
                                    goto __Vlabel377;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x6aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x69U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x68U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x67U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x66U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x65U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x64U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x63U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x62U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x61U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x60U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5fU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5dU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5bU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x5aU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x59U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x58U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x57U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x56U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x55U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x54U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x51U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x50U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4fU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4eU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4dU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4cU;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4bU;
                                goto __Vlabel377;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xe0U;
                                                goto __Vlabel377;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xdfU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xdeU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xddU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xdcU;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xdbU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xdaU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd8U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd7U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd6U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd5U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd4U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd3U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd2U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd1U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xd0U;
                                            goto __Vlabel377;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xcfU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xceU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xcdU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xccU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xcbU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xcaU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc9U;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc8U;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc7U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc6U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc5U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc4U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc3U;
                                goto __Vlabel377;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9fU;
                                        goto __Vlabel377;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9eU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9dU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x9cU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x52U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4aU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x49U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x48U;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x47U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x46U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x45U;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x44U;
                            goto __Vlabel377;
                        }
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x39U;
                            goto __Vlabel377;
                        }
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xeaU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x4fU;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x36U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x35U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x34U;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x33U;
                            goto __Vlabel377;
                        }
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xc3U;
                            goto __Vlabel377;
                        }
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3eU;
                                    goto __Vlabel377;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3dU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3cU;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x3bU;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x31U;
                                goto __Vlabel377;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x30U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x2fU;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x48U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0x44U;
                        goto __Vlabel377;
                    }
                } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xcU;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xbU;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xaU;
                        goto __Vlabel377;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 6U;
                                goto __Vlabel377;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 5U;
                            goto __Vlabel377;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 4U;
                        goto __Vlabel377;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 3U;
                        goto __Vlabel377;
                    }
                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 2U;
                        goto __Vlabel377;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 1U;
                        goto __Vlabel377;
                    }
                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__255__csr_name))) {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0U;
                    goto __Vlabel377;
                } else {
                    vlSelfRef.__Vfunc_internal_idx__255__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                }
                __Vlabel377: ;
            }
        }(), (IData)(vlSelfRef.__Vfunc_internal_idx__255__Vfuncout))];
    Top__DOT__csrrf__DOT__new_csr_val = (((QData)((IData)(
                                                          vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U])));
    __Vfunc_get_write_mask__256__original_val = (((QData)((IData)(
                                                                  vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[0U])));
    __Vfunc_get_write_mask__256__csr_name = (0xfffU 
                                             & vlSymsp->TOP__Top__DOT__csr_csru_port.write_req[2U]);
    {
        if ((0x800U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((0x400U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x200U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_mconfigptr_get_write_mask__257__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_mconfigptr_get_write_mask__257__Vfuncout;
                                    goto __Vlabel378;
                                } else {
                                    vlSelfRef.__Vfunc_mhartid_get_write_mask__258__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhartid_get_write_mask__258__Vfuncout;
                                    goto __Vlabel378;
                                }
                            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_mimpid_get_write_mask__259__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_mimpid_get_write_mask__259__Vfuncout;
                                    goto __Vlabel378;
                                } else {
                                    vlSelfRef.__Vfunc_marchid_get_write_mask__260__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_marchid_get_write_mask__260__Vfuncout;
                                    goto __Vlabel378;
                                }
                            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_mvendorid_get_write_mask__261__Vfuncout = 0ULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_mvendorid_get_write_mask__261__Vfuncout;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_scountovf_get_write_mask__262__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountovf_get_write_mask__262__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_vl_get_write_mask__263__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_vl_get_write_mask__263__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_vlenb_get_write_mask__264__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_vlenb_get_write_mask__264__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_vtype_get_write_mask__265__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_vtype_get_write_mask__265__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_hpmcounter_get_write_mask__266__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_hpmcounter_get_write_mask__266__Vfuncout;
                    goto __Vlabel378;
                } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_hpmcounter_get_write_mask__267__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_hpmcounter_get_write_mask__267__Vfuncout;
                    goto __Vlabel378;
                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_hpmcounter_get_write_mask__268__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_hpmcounter_get_write_mask__268__Vfuncout;
                    goto __Vlabel378;
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_hpmcounter_get_write_mask__269__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_hpmcounter_get_write_mask__269__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_instret_get_write_mask__270__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_instret_get_write_mask__270__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_time_get_write_mask__271__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_time_get_write_mask__271__Vfuncout;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_cycle_get_write_mask__272__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_cycle_get_write_mask__272__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((0x200U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__273__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__273__Vfuncout;
                        goto __Vlabel378;
                    } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__274__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__274__Vfuncout;
                        goto __Vlabel378;
                    } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__275__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__275__Vfuncout;
                        goto __Vlabel378;
                    } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__276__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mhpmcounter_get_write_mask__276__Vfuncout;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_minstret_get_write_mask__277__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_minstret_get_write_mask__277__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_mcycle_get_write_mask__278__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mcycle_get_write_mask__278__Vfuncout;
                        goto __Vlabel378;
                    }
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            }
        } else if ((0x400U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((0x200U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_dscratch_get_write_mask__279__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_dscratch_get_write_mask__279__Vfuncout;
                                    goto __Vlabel378;
                                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_dpc_get_write_mask__280__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_dpc_get_write_mask__280__Vfuncout;
                                    goto __Vlabel378;
                                } else {
                                    vlSelfRef.__Vfunc_dcsr_get_write_mask__281__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_dcsr_get_write_mask__281__Vfuncout;
                                    goto __Vlabel378;
                                }
                            } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                } else {
                                    vlSelfRef.__Vfunc_mcontext_get_write_mask__282__Vfuncout = 0ULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcontext_get_write_mask__282__Vfuncout;
                                    goto __Vlabel378;
                                }
                            } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_tdata_get_write_mask__283__Vfuncout = 0ULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_tdata_get_write_mask__283__Vfuncout;
                                goto __Vlabel378;
                            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_tdata_get_write_mask__284__Vfuncout = 0ULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_tdata_get_write_mask__284__Vfuncout;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_tselect_get_write_mask__285__Vfuncout = 0ULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_tselect_get_write_mask__285__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                    vlSelfRef.__Vfunc_mseccfg_get_write_mask__286__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                        = vlSelfRef.__Vfunc_mseccfg_get_write_mask__286__Vfuncout;
                                    goto __Vlabel378;
                                } else {
                                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                    goto __Vlabel378;
                                }
                            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_mnstatus_get_write_mask__287__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_mnstatus_get_write_mask__287__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_mncause_get_write_mask__288__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_mncause_get_write_mask__288__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_mnepc_get_write_mask__289__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mnepc_get_write_mask__289__Vfuncout;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_mnscratch_get_write_mask__290__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mnscratch_get_write_mask__290__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_scontext_get_write_mask__291__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_scontext_get_write_mask__291__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            }
        } else if ((0x200U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_pmpaddr_get_write_mask__292__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_pmpaddr_get_write_mask__292__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_pmpaddr_get_write_mask__293__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_pmpaddr_get_write_mask__293__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_pmpaddr_get_write_mask__294__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_pmpaddr_get_write_mask__294__Vfuncout;
                            goto __Vlabel378;
                        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_pmpcfg_get_write_mask__295__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_pmpcfg_get_write_mask__295__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                                vlSelfRef.__Vfunc_mtval2_get_write_mask__296__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_mtval2_get_write_mask__296__Vfuncout;
                                goto __Vlabel378;
                            } else {
                                vlSelfRef.__Vfunc_mtinst_get_write_mask__297__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                    = vlSelfRef.__Vfunc_mtinst_get_write_mask__297__Vfuncout;
                                goto __Vlabel378;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_mip_get_write_mask__298__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mip_get_write_mask__298__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_mtval_get_write_mask__299__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mtval_get_write_mask__299__Vfuncout;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_mcause_get_write_mask__300__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mcause_get_write_mask__300__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mepc_get_write_mask__301__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mepc_get_write_mask__301__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_mscratch_get_write_mask__302__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mscratch_get_write_mask__302__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmevent_get_write_mask__303__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmevent_get_write_mask__303__Vfuncout;
                        goto __Vlabel378;
                    } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmevent_get_write_mask__304__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmevent_get_write_mask__304__Vfuncout;
                        goto __Vlabel378;
                    } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mhpmevent_get_write_mask__305__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mhpmevent_get_write_mask__305__Vfuncout;
                        goto __Vlabel378;
                    } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_mhpmevent_get_write_mask__306__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mhpmevent_get_write_mask__306__Vfuncout;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_mcountinhibit_get_write_mask__307__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mcountinhibit_get_write_mask__307__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mstateen_get_write_mask__308__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mstateen_get_write_mask__308__Vfuncout;
                        goto __Vlabel378;
                    } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_menvcfg_get_write_mask__309__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_menvcfg_get_write_mask__309__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_mcounteren_get_write_mask__310__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_mcounteren_get_write_mask__310__Vfuncout;
                            goto __Vlabel378;
                        }
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mtvec_get_write_mask__311__original_val 
                            = __Vfunc_get_write_mask__256__original_val;
                        vlSelf->__Vfunc_mtvec_get_write_mask__311__tmp = 0;
                        vlSelf->__Vfunc_mtvec_get_write_mask__311__mask = 0;
                        vlSelf->__Vfunc_mtvec_get_write_mask__311__mask_logic = 0;
                        vlSelfRef.__Vfunc_mtvec_get_write_mask__311__tmp 
                            = vlSelfRef.__Vfunc_mtvec_get_write_mask__311__original_val;
                        vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask = 0xffffffffffffffffULL;
                        if (((2U == (3U & (IData)(vlSelfRef.__Vfunc_mtvec_get_write_mask__311__tmp))) 
                             | (3U == (3U & (IData)(vlSelfRef.__Vfunc_mtvec_get_write_mask__311__tmp))))) {
                            vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask 
                                = (0xfffffffffffffffcULL 
                                   & vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask);
                        }
                        vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask_logic 
                            = vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask;
                        vlSelfRef.__Vfunc_mtvec_get_write_mask__311__Vfuncout 
                            = vlSelfRef.__Vfunc_mtvec_get_write_mask__311__mask_logic;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mtvec_get_write_mask__311__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__original_val 
                            = __Vfunc_get_write_mask__256__original_val;
                        __Vfunc_mie_get_write_mask__312__tmp = 0;
                        vlSelf->__Vfunc_mie_get_write_mask__312__mask = 0;
                        vlSelf->__Vfunc_mie_get_write_mask__312__mask_logic = 0;
                        __Vfunc_mie_get_write_mask__312__tmp 
                            = vlSelfRef.__Vfunc_mie_get_write_mask__312__original_val;
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0x3fffULL & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xffffffffffffefffULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xfffffffffffffbffULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xfffffffffffffeffULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xffffffffffffffbfULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xffffffffffffffefULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xfffffffffffffffbULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask 
                            = (0xfffffffffffffffeULL 
                               & vlSelfRef.__Vfunc_mie_get_write_mask__312__mask);
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__mask_logic 
                            = vlSelfRef.__Vfunc_mie_get_write_mask__312__mask;
                        vlSelfRef.__Vfunc_mie_get_write_mask__312__Vfuncout 
                            = vlSelfRef.__Vfunc_mie_get_write_mask__312__mask_logic;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mie_get_write_mask__312__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__original_val 
                            = __Vfunc_get_write_mask__256__original_val;
                        __Vfunc_mideleg_get_write_mask__313__tmp = 0;
                        vlSelf->__Vfunc_mideleg_get_write_mask__313__mask = 0;
                        vlSelf->__Vfunc_mideleg_get_write_mask__313__mask_logic = 0;
                        __Vfunc_mideleg_get_write_mask__313__tmp 
                            = vlSelfRef.__Vfunc_mideleg_get_write_mask__313__original_val;
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0x3fffULL & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xffffffffffffefffULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xfffffffffffffbffULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xfffffffffffffeffULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xffffffffffffffbfULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xffffffffffffffefULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xfffffffffffffffbULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask 
                            = (0xfffffffffffffffeULL 
                               & vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask);
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask_logic 
                            = vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask;
                        vlSelfRef.__Vfunc_mideleg_get_write_mask__313__Vfuncout 
                            = vlSelfRef.__Vfunc_mideleg_get_write_mask__313__mask_logic;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_mideleg_get_write_mask__313__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__original_val 
                            = __Vfunc_get_write_mask__256__original_val;
                        __Vfunc_medeleg_get_write_mask__314__tmp = 0;
                        vlSelf->__Vfunc_medeleg_get_write_mask__314__mask = 0;
                        vlSelf->__Vfunc_medeleg_get_write_mask__314__mask_logic = 0;
                        __Vfunc_medeleg_get_write_mask__314__tmp 
                            = vlSelfRef.__Vfunc_medeleg_get_write_mask__314__original_val;
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask 
                            = (0xfffffULL & vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask);
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask 
                            = (0xfffffffffffdffffULL 
                               & vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask);
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask 
                            = (0xffffffffffffbfffULL 
                               & vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask);
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask 
                            = (0xfffffffffffffbffULL 
                               & vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask);
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask_logic 
                            = vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask;
                        vlSelfRef.__Vfunc_medeleg_get_write_mask__314__Vfuncout 
                            = vlSelfRef.__Vfunc_medeleg_get_write_mask__314__mask_logic;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_medeleg_get_write_mask__314__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_misa_get_write_mask__315__original_val 
                        = __Vfunc_get_write_mask__256__original_val;
                    __Vfunc_misa_get_write_mask__315__tmp = 0;
                    vlSelf->__Vfunc_misa_get_write_mask__315__mask = 0;
                    vlSelf->__Vfunc_misa_get_write_mask__315__mask_logic = 0;
                    __Vfunc_misa_get_write_mask__315__tmp 
                        = vlSelfRef.__Vfunc_misa_get_write_mask__315__original_val;
                    vlSelfRef.__Vfunc_misa_get_write_mask__315__mask = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_misa_get_write_mask__315__mask = 0ULL;
                    vlSelfRef.__Vfunc_misa_get_write_mask__315__mask_logic 
                        = vlSelfRef.__Vfunc_misa_get_write_mask__315__mask;
                    vlSelfRef.__Vfunc_misa_get_write_mask__315__Vfuncout 
                        = vlSelfRef.__Vfunc_misa_get_write_mask__315__mask_logic;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_misa_get_write_mask__315__Vfuncout;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__original_val 
                        = __Vfunc_get_write_mask__256__original_val;
                    vlSelf->__Vfunc_mstatus_get_write_mask__316__tmp = 0;
                    vlSelf->__Vfunc_mstatus_get_write_mask__316__mask = 0;
                    vlSelf->__Vfunc_mstatus_get_write_mask__316__mask_logic = 0;
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__tmp 
                        = vlSelfRef.__Vfunc_mstatus_get_write_mask__316__original_val;
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0x800007ffffffffffULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0xfffffeffffffffffULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0xfffffff001ffffffULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0x18000ULL | vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    if ((2U == (3U & (IData)((vlSelfRef.__Vfunc_mstatus_get_write_mask__316__tmp 
                                              >> 0xbU))))) {
                        vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                            = (0xffffffffffffe7ffULL 
                               & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    }
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0x6000ULL | vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0x600ULL | vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0xffffffffffffffefULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0xfffffffffffffffbULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask 
                        = (0xfffffffffffffffeULL & vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask);
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask_logic 
                        = vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask;
                    vlSelfRef.__Vfunc_mstatus_get_write_mask__316__Vfuncout 
                        = vlSelfRef.__Vfunc_mstatus_get_write_mask__316__mask_logic;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_mstatus_get_write_mask__316__Vfuncout;
                    goto __Vlabel378;
                }
            } else {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            }
        } else if ((0x100U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_satp_get_write_mask__317__original_val 
                        = __Vfunc_get_write_mask__256__original_val;
                    vlSelf->__Vfunc_satp_get_write_mask__317__tmp = 0;
                    vlSelf->__Vfunc_satp_get_write_mask__317__mask = 0;
                    vlSelf->__Vfunc_satp_get_write_mask__317__mask_logic = 0;
                    vlSelfRef.__Vfunc_satp_get_write_mask__317__tmp 
                        = vlSelfRef.__Vfunc_satp_get_write_mask__317__original_val;
                    vlSelfRef.__Vfunc_satp_get_write_mask__317__mask = 0xffffffffffffffffULL;
                    if (((0U != (0xfU & (IData)((vlSelfRef.__Vfunc_satp_get_write_mask__317__tmp 
                                                 >> 0x3cU)))) 
                         & (8U != (0xfU & (IData)((vlSelfRef.__Vfunc_satp_get_write_mask__317__tmp 
                                                   >> 0x3cU)))))) {
                        vlSelfRef.__Vfunc_satp_get_write_mask__317__mask 
                            = (0xfffffffffffffffULL 
                               & vlSelfRef.__Vfunc_satp_get_write_mask__317__mask);
                    }
                    vlSelfRef.__Vfunc_satp_get_write_mask__317__mask_logic 
                        = vlSelfRef.__Vfunc_satp_get_write_mask__317__mask;
                    vlSelfRef.__Vfunc_satp_get_write_mask__317__Vfuncout 
                        = vlSelfRef.__Vfunc_satp_get_write_mask__317__mask_logic;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_satp_get_write_mask__317__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                            vlSelfRef.__Vfunc_stimecmp_get_write_mask__318__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                                = vlSelfRef.__Vfunc_stimecmp_get_write_mask__318__Vfuncout;
                            goto __Vlabel378;
                        } else {
                            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                            goto __Vlabel378;
                        }
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_sip_get_write_mask__319__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_sip_get_write_mask__319__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_stval_get_write_mask__320__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_stval_get_write_mask__320__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_scause_get_write_mask__321__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_scause_get_write_mask__321__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_sepc_get_write_mask__322__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_sepc_get_write_mask__322__Vfuncout;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_sscratch_get_write_mask__323__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_sscratch_get_write_mask__323__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_scountinhibit_get_write_mask__324__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_scountinhibit_get_write_mask__324__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_sstateen_get_write_mask__325__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_sstateen_get_write_mask__325__Vfuncout;
                    goto __Vlabel378;
                } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_senvcfg_get_write_mask__326__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_senvcfg_get_write_mask__326__Vfuncout;
                        goto __Vlabel378;
                    }
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_scounteren_get_write_mask__327__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_scounteren_get_write_mask__327__Vfuncout;
                        goto __Vlabel378;
                    }
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_stvec_get_write_mask__328__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_stvec_get_write_mask__328__Vfuncout;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_sie_get_write_mask__329__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_sie_get_write_mask__329__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            } else {
                vlSelfRef.__Vfunc_sstatus_get_write_mask__330__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_sstatus_get_write_mask__330__Vfuncout;
                goto __Vlabel378;
            }
        } else if ((0x80U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
            goto __Vlabel378;
        } else if ((0x40U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
            goto __Vlabel378;
        } else if ((0x20U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
            goto __Vlabel378;
        } else if ((0x10U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_jvt_get_write_mask__331__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_jvt_get_write_mask__331__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_seed_get_write_mask__332__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_seed_get_write_mask__332__Vfuncout;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_ssp_get_write_mask__333__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_ssp_get_write_mask__333__Vfuncout;
                goto __Vlabel378;
            } else {
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                goto __Vlabel378;
            }
        } else if ((8U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                        vlSelfRef.__Vfunc_vcsr_get_write_mask__334__Vfuncout = 0xffffffffffffffffULL;
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                            = vlSelfRef.__Vfunc_vcsr_get_write_mask__334__Vfuncout;
                        goto __Vlabel378;
                    } else {
                        vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                        goto __Vlabel378;
                    }
                } else {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                }
            } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
                    goto __Vlabel378;
                } else {
                    vlSelfRef.__Vfunc_vxrm_get_write_mask__335__Vfuncout = 0xffffffffffffffffULL;
                    vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                        = vlSelfRef.__Vfunc_vxrm_get_write_mask__335__Vfuncout;
                    goto __Vlabel378;
                }
            } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_vxsat_get_write_mask__336__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_vxsat_get_write_mask__336__Vfuncout;
                goto __Vlabel378;
            } else {
                vlSelfRef.__Vfunc_vstart_get_write_mask__337__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_vstart_get_write_mask__337__Vfuncout;
                goto __Vlabel378;
            }
        } else if ((4U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
            goto __Vlabel378;
        } else if ((2U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
                vlSelfRef.__Vfunc_fcsr_get_write_mask__338__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_fcsr_get_write_mask__338__Vfuncout;
                goto __Vlabel378;
            } else {
                vlSelfRef.__Vfunc_frm_get_write_mask__339__Vfuncout = 0xffffffffffffffffULL;
                vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                    = vlSelfRef.__Vfunc_frm_get_write_mask__339__Vfuncout;
                goto __Vlabel378;
            }
        } else if ((1U & (IData)(__Vfunc_get_write_mask__256__csr_name))) {
            vlSelfRef.__Vfunc_fflags_get_write_mask__340__Vfuncout = 0xffffffffffffffffULL;
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout 
                = vlSelfRef.__Vfunc_fflags_get_write_mask__340__Vfuncout;
            goto __Vlabel378;
        } else {
            vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout = 0ULL;
            goto __Vlabel378;
        }
        __Vlabel378: ;
    }
    Top__DOT__csrrf__DOT__unnamedblk1__DOT__write_mask 
        = vlSelfRef.__Vfunc_get_write_mask__256__Vfuncout;
    vlSelfRef.Top__DOT__csrrf__DOT__new_masked_csr_val 
        = ((Top__DOT__csrrf__DOT__new_csr_val & Top__DOT__csrrf__DOT__unnamedblk1__DOT__write_mask) 
           | (vlSelfRef.Top__DOT__csrrf__DOT__old_csr_val 
              & (~ Top__DOT__csrrf__DOT__unnamedblk1__DOT__write_mask)));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[2U] = 0U;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [0U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[0U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [1U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[1U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [2U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx[2U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_h0ac96390__0;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[2U] = 0U;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [0U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[0U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [1U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[1U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0;
    Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0 
        = (0x7fU & (vlSelfRef.Top__DOT__mmu__DOT__req_to_dtlb_from_dcache
                    [2U][0U] >> 0xcU));
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx[2U] 
        = Top__DOT__mmu__DOT__l1dtlb__DOT____Vlvbound_hdf8574c7__0;
    vlSelfRef.Top__DOT__btb__DOT__is_pending_next = vlSelfRef.Top__DOT__btb__DOT__is_pending;
    vlSelfRef.Top__DOT__pcbypass__DOT__is_pending_next 
        = vlSelfRef.Top__DOT__pcbypass__DOT__is_pending;
    vlSelfRef.Top__DOT__btb__DOT__first_instr_addr_pending_next 
        = vlSelfRef.Top__DOT__btb__DOT__first_instr_addr_pending;
    vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[0U] 
        = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[0U];
    vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[1U] 
        = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[1U];
    vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[2U] 
        = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[2U];
    if ((1U & (~ (IData)(vlSelfRef.Top__DOT__flush_to_st2)))) {
        if (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
             & (~ (IData)(vlSelfRef.Top__DOT__btb__DOT__is_pending)))) {
            vlSelfRef.Top__DOT__btb__DOT__is_pending_next = 1U;
            vlSelfRef.Top__DOT__btb__DOT__first_instr_addr_pending_next 
                = (0x7fffffffffULL & (((QData)((IData)(
                                                       vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U]))));
        } else if ((1U & (~ (IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2)))) {
            if (vlSelfRef.Top__DOT__btb__DOT__is_pending) {
                vlSelfRef.Top__DOT__btb__DOT__is_pending_next = 0U;
            }
        }
        if (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
             & (~ (IData)(vlSelfRef.Top__DOT__pcbypass__DOT__is_pending)))) {
            vlSelfRef.Top__DOT__pcbypass__DOT__is_pending_next = 1U;
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[0U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[0U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[1U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending_next[2U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U];
        } else if ((1U & (~ (IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2)))) {
            if (vlSelfRef.Top__DOT__pcbypass__DOT__is_pending) {
                vlSelfRef.Top__DOT__pcbypass__DOT__is_pending_next = 0U;
            }
        }
    }
    if (vlSelfRef.Top__DOT__flush_to_st2) {
        vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U] = 0U;
        vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U] = 0U;
        vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U] = 0U;
        Top__DOT__predictor__DOT__first_instr_addr = 0ULL;
        Top__DOT__btb__DOT__first_instr_addr = 0ULL;
    } else {
        if (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
             & (~ (IData)(vlSelfRef.Top__DOT__pcbypass__DOT__is_pending)))) {
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U] = 0U;
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U] = 0U;
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U] = 0U;
        } else if (vlSelfRef.Top__DOT__stall_from_st3_to_st2) {
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U] = 0U;
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U] = 0U;
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U] = 0U;
        } else if (vlSelfRef.Top__DOT__pcbypass__DOT__is_pending) {
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[0U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[1U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in_pending[2U];
        } else {
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[0U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U];
            vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U] 
                = vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U];
        }
        Top__DOT__predictor__DOT__first_instr_addr 
            = (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
                & (~ (IData)(vlSelfRef.Top__DOT__predictor__DOT__is_pending)))
                ? 0ULL : ((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2)
                           ? 0ULL : (0x7fffffffffULL 
                                     & ((IData)(vlSelfRef.Top__DOT__predictor__DOT__is_pending)
                                         ? vlSelfRef.Top__DOT__predictor__DOT__first_instr_addr_pending
                                         : (((QData)((IData)(
                                                             vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U])))))));
        Top__DOT__btb__DOT__first_instr_addr = (((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2) 
                                                 & (~ (IData)(vlSelfRef.Top__DOT__btb__DOT__is_pending)))
                                                 ? 0ULL
                                                 : 
                                                ((IData)(vlSelfRef.Top__DOT__stall_from_st3_to_st2)
                                                  ? 0ULL
                                                  : 
                                                 (0x7fffffffffULL 
                                                  & ((IData)(vlSelfRef.Top__DOT__btb__DOT__is_pending)
                                                      ? vlSelfRef.Top__DOT__btb__DOT__first_instr_addr_pending
                                                      : 
                                                     (((QData)((IData)(
                                                                       vlSelfRef.Top__DOT__pc_from_st1_to_st2[2U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelfRef.Top__DOT__pc_from_st1_to_st2[1U])))))));
    }
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0U;
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [1U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[1U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [2U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[2U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [3U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [3U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[3U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [4U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [4U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[4U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [5U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [5U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[5U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [6U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [6U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[6U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [7U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [7U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[7U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [8U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [8U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[8U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [9U] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [9U] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[9U] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xaU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xaU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xaU] = 0xeU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [0U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 8U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [1U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 9U;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [2U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [2U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0xaU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [3U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [3U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0xbU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [4U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [4U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0xcU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [5U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [5U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0xdU;
    }
    if (((vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en
          [0xbU] & vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_en
          [6U]) & (vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_ram_idx
                   [0xbU] == vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_ram_idx
                   [6U]))) {
        vlSelfRef.Top__DOT__intprf__DOT__phyreg__DOT__bypass_table[0xbU] = 0xeU;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__0__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__0__KET____DOT__tlb_data__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__1__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__1__KET____DOT__tlb_data__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__2__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__2__KET____DOT__tlb_data__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk2__BRA__3__KET____DOT__tlb_data__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk2__BRA__3__KET____DOT__tlb_data__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__0__KET____DOT__tlb_info__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__1__KET____DOT__tlb_info__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__2__KET____DOT__tlb_info__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[2U] = 0U;
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [0U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [0U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[0U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [1U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [1U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[1U] = 3U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [0U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [0U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en
          [2U] & vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_en
          [1U]) & (vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_ram_idx
                   [2U] == vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__tlb_info__w_ram_idx
                   [1U]))) {
        vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__genblk1__BRA__3__KET____DOT__tlb_info__DOT__bypass_table[2U] = 3U;
    }
    vlSelfRef.Top__DOT__predictor__DOT__addr_in[0U] 
        = Top__DOT__predictor__DOT__first_instr_addr;
    vlSelfRef.Top__DOT__predictor__DOT__addr_in[1U] 
        = (0x7fffffffffULL & (4ULL + Top__DOT__predictor__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__predictor__DOT__addr_in[2U] 
        = (0x7fffffffffULL & (8ULL + Top__DOT__predictor__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__predictor__DOT__addr_in[3U] 
        = (0x7fffffffffULL & (0xcULL + Top__DOT__predictor__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next 
        = ((0xeU & (IData)(vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next)) 
           | ((3U == vlSelfRef.Top__DOT__predictor__DOT__PHT
               [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                      [0U] >> 2U)) 
                             << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                 [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                     [0U] >> 2U)))])]) 
              | (2U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                 [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                        [0U] >> 2U)) 
                               << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                   [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                       [0U] >> 2U)))])])));
    vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next 
        = ((0xdU & (IData)(vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next)) 
           | (((3U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                       [1U] >> 2U)) 
                              << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                  [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                      [1U] >> 2U)))])]) 
               | (2U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                  [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                         [1U] >> 2U)) 
                                << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                    [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                        [1U] >> 2U)))])])) 
              << 1U));
    vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next 
        = ((0xbU & (IData)(vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next)) 
           | (((3U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                       [2U] >> 2U)) 
                              << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                  [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                      [2U] >> 2U)))])]) 
               | (2U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                  [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                         [2U] >> 2U)) 
                                << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                    [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                        [2U] >> 2U)))])])) 
              << 2U));
    vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next 
        = ((7U & (IData)(vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next)) 
           | (((3U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                       [3U] >> 2U)) 
                              << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                  [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                      [3U] >> 2U)))])]) 
               | (2U == vlSelfRef.Top__DOT__predictor__DOT__PHT
                  [((0x3ff0U & ((IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                         [3U] >> 2U)) 
                                << 4U)) | vlSelfRef.Top__DOT__predictor__DOT__BHT
                    [(0x3ffU & (IData)((vlSelfRef.Top__DOT__predictor__DOT__addr_in
                                        [3U] >> 2U)))])])) 
              << 3U));
    vlSelfRef.Top__DOT__btb__DOT__addr_in[0U] = Top__DOT__btb__DOT__first_instr_addr;
    vlSelfRef.Top__DOT__btb__DOT__addr_in[1U] = (0x7fffffffffULL 
                                                 & (4ULL 
                                                    + Top__DOT__btb__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__btb__DOT__addr_in[2U] = (0x7fffffffffULL 
                                                 & (8ULL 
                                                    + Top__DOT__btb__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__btb__DOT__addr_in[3U] = (0x7fffffffffULL 
                                                 & (0xcULL 
                                                    + Top__DOT__btb__DOT__first_instr_addr));
    vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx[0U] 
        = (0x1ffU & (IData)((vlSelfRef.Top__DOT__btb__DOT__addr_in
                             [0U] >> 2U)));
    vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx[1U] 
        = (0x1ffU & (IData)((vlSelfRef.Top__DOT__btb__DOT__addr_in
                             [1U] >> 2U)));
    vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx[2U] 
        = (0x1ffU & (IData)((vlSelfRef.Top__DOT__btb__DOT__addr_in
                             [2U] >> 2U)));
    vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx[3U] 
        = (0x1ffU & (IData)((vlSelfRef.Top__DOT__btb__DOT__addr_in
                             [3U] >> 2U)));
    vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[0U] = 0U;
    vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[1U] = 0U;
    vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[2U] = 0U;
    vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[3U] = 0U;
    if (((vlSelfRef.Top__DOT__btb__DOT__btb_r_en[0U] 
          & vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U]) 
         & (vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx
            [0U] == vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx
            [0U]))) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[0U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__btb__DOT__btb_r_en[1U] 
          & vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U]) 
         & (vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx
            [1U] == vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx
            [0U]))) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[1U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__btb__DOT__btb_r_en[2U] 
          & vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U]) 
         & (vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx
            [2U] == vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx
            [0U]))) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[2U] = 2U;
    }
    if (((vlSelfRef.Top__DOT__btb__DOT__btb_r_en[3U] 
          & vlSelfRef.Top__DOT__btb__DOT__btb_w_en[0U]) 
         & (vlSelfRef.Top__DOT__btb__DOT__btb_r_ram_idx
            [3U] == vlSelfRef.Top__DOT__btb__DOT__btb_w_ram_idx
            [0U]))) {
        vlSelfRef.Top__DOT__btb__DOT__btb__DOT__bypass_table[3U] = 2U;
    }
}
