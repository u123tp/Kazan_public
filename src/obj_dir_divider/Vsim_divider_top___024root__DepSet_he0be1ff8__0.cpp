// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_divider_top.h for the primary calling header

#include "Vsim_divider_top__pch.h"
#include "Vsim_divider_top___024root.h"

extern const VlWide<10>/*319:0*/ Vsim_divider_top__ConstPool__CONST_h7c08bc10_0;

VL_INLINE_OPT void Vsim_divider_top___024root___ico_sequent__TOP__0(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<5>/*159:0*/ __Vtemp_17;
    VlWide<5>/*159:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<5>/*159:0*/ __Vtemp_25;
    VlWide<5>/*159:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<5>/*159:0*/ __Vtemp_33;
    VlWide<5>/*159:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<5>/*159:0*/ __Vtemp_41;
    VlWide<5>/*159:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<5>/*159:0*/ __Vtemp_48;
    VlWide<5>/*159:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<5>/*159:0*/ __Vtemp_52;
    VlWide<5>/*159:0*/ __Vtemp_53;
    VlWide<5>/*159:0*/ __Vtemp_56;
    VlWide<5>/*159:0*/ __Vtemp_57;
    VlWide<5>/*159:0*/ __Vtemp_58;
    VlWide<5>/*159:0*/ __Vtemp_64;
    VlWide<5>/*159:0*/ __Vtemp_70;
    VlWide<5>/*159:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<5>/*159:0*/ __Vtemp_77;
    VlWide<5>/*159:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_81;
    VlWide<5>/*159:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_89;
    VlWide<3>/*95:0*/ __Vtemp_90;
    // Body
    vlSelf->sim_divider_top__DOT__op_in[0U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[0U];
    vlSelf->sim_divider_top__DOT__op_in[1U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[1U];
    vlSelf->sim_divider_top__DOT__op_in[2U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[2U];
    vlSelf->sim_divider_top__DOT__op_in[3U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[3U];
    vlSelf->sim_divider_top__DOT__op_in[4U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[4U];
    vlSelf->sim_divider_top__DOT__op_in[5U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[5U];
    vlSelf->sim_divider_top__DOT__op_in[6U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[6U];
    vlSelf->sim_divider_top__DOT__op_in[7U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[7U];
    vlSelf->sim_divider_top__DOT__op_in[8U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[8U];
    vlSelf->sim_divider_top__DOT__op_in[9U] = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[9U];
    vlSelf->sim_divider_top__DOT__op_in[7U] = ((0x7fffffffU 
                                                & vlSelf->sim_divider_top__DOT__op_in[7U]) 
                                               | ((IData)(
                                                          (1ULL 
                                                           | (((QData)((IData)(vlSelf->req_valid)) 
                                                               << 0x30U) 
                                                              | ((QData)((IData)(vlSelf->req_opcode)) 
                                                                 << 0x28U)))) 
                                                  << 0x1fU));
    vlSelf->sim_divider_top__DOT__op_in[8U] = (((IData)(
                                                        (1ULL 
                                                         | (((QData)((IData)(vlSelf->req_valid)) 
                                                             << 0x30U) 
                                                            | ((QData)((IData)(vlSelf->req_opcode)) 
                                                               << 0x28U)))) 
                                                >> 1U) 
                                               | ((IData)(
                                                          ((1ULL 
                                                            | (((QData)((IData)(vlSelf->req_valid)) 
                                                                << 0x30U) 
                                                               | ((QData)((IData)(vlSelf->req_opcode)) 
                                                                  << 0x28U))) 
                                                           >> 0x20U)) 
                                                  << 0x1fU));
    vlSelf->sim_divider_top__DOT__op_in[9U] = (0xffffU 
                                               & ((IData)(
                                                          ((1ULL 
                                                            | (((QData)((IData)(vlSelf->req_valid)) 
                                                                << 0x30U) 
                                                               | ((QData)((IData)(vlSelf->req_opcode)) 
                                                                  << 0x28U))) 
                                                           >> 0x20U)) 
                                                  >> 1U));
    vlSelf->sim_divider_top__DOT__op_in[1U] = (0x7ffU 
                                               & vlSelf->sim_divider_top__DOT__op_in[1U]);
    vlSelf->sim_divider_top__DOT__op_in[2U] = 0U;
    vlSelf->sim_divider_top__DOT__op_in[3U] = ((IData)(vlSelf->req_rs2) 
                                               << 0xbU);
    vlSelf->sim_divider_top__DOT__op_in[4U] = (((IData)(vlSelf->req_rs2) 
                                                >> 0x15U) 
                                               | ((IData)(
                                                          (vlSelf->req_rs2 
                                                           >> 0x20U)) 
                                                  << 0xbU));
    vlSelf->sim_divider_top__DOT__op_in[5U] = (((IData)(
                                                        (vlSelf->req_rs2 
                                                         >> 0x20U)) 
                                                >> 0x15U) 
                                               | ((IData)(vlSelf->req_rs1) 
                                                  << 0xbU));
    vlSelf->sim_divider_top__DOT__op_in[6U] = (((IData)(vlSelf->req_rs1) 
                                                >> 0x15U) 
                                               | ((IData)(
                                                          (vlSelf->req_rs1 
                                                           >> 0x20U)) 
                                                  << 0xbU));
    vlSelf->sim_divider_top__DOT__op_in[7U] = (0x60000000U 
                                               | ((0x80000000U 
                                                   & vlSelf->sim_divider_top__DOT__op_in[7U]) 
                                                  | ((IData)(
                                                             (vlSelf->req_rs1 
                                                              >> 0x20U)) 
                                                     >> 0x15U)));
    vlSelf->sim_divider_top__DOT__op_in[0U] = 0U;
    vlSelf->sim_divider_top__DOT__op_in[1U] = (0xfffff800U 
                                               & vlSelf->sim_divider_top__DOT__op_in[1U]);
    vlSelf->sim_divider_top__DOT__op_out[0U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[1U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[2U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[3U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[4U] = (0xe00U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U] 
                                                   << 1U));
    vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[6U] = (((IData)(
                                                         (0x7fffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U]))))) 
                                                 << 0x13U) 
                                                | ((0x40000U 
                                                    & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
                                                       >> 0xbU)) 
                                                   | (0x3f000U 
                                                      & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
                                                         << 1U))));
    vlSelf->sim_divider_top__DOT__op_out[7U] = ((0xfc000000U 
                                                 & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                    << 0x13U)) 
                                                | (((IData)(
                                                            (0x7fffffffffULL 
                                                             & (((QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U]))))) 
                                                    >> 0xdU) 
                                                   | ((IData)(
                                                              ((0x7fffffffffULL 
                                                                & (((QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U])))) 
                                                               >> 0x20U)) 
                                                      << 0x13U)));
    vlSelf->sim_divider_top__DOT__op_out[8U] = (3U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 0xdU));
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[5U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[6U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[7U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[8U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[9U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U];
    vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__div_state;
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_negative;
    vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb;
    vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit;
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_idx;
    if ((4U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state)))) {
            VL_WRITEF("[ERROR]\n");
        } else if (VL_UNLIKELY((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state)))) {
            VL_WRITEF("[ERROR]\n");
        } else {
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            if ((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                    >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0x800U | (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]));
            } else if ((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                           >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else if ((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                           >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0xfffff800U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffU | (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]));
            } else if (VL_LIKELY((0x49U == (0xffU & 
                                            (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                             >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else {
                VL_WRITEF("[ERROR][Divider.sv] overflow opcode error\n");
                vlSelf->sim_divider_top__DOT__op_out[8U] 
                    = (3U & vlSelf->sim_divider_top__DOT__op_out[8U]);
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            }
        }
    } else if ((2U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        if ((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            if (((((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                       >> 7U))) || 
                   (0x43U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                       >> 7U)))) || 
                  (0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                      >> 7U)))) || 
                 (0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                     >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffff000U | vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0xffffffffU;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffU | vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else if (((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                    >> 0xbU)))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                  << 0x35U) | (((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                << 0x15U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                  >> 0xbU)))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                                << 0x35U) 
                                               | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                     >> 0xbU))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                     << 0x35U) | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                     >> 0xbU))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (VL_LIKELY(((0x49U == (0xffU 
                                             & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                >> 7U))) 
                                  || (0x4aU == (0xffU 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 7U)))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                  << 0x15U) 
                                                 | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                    >> 0xbU)))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                << 0x15U) 
                                               | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                  >> 0xbU)))) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                              << 0x15U) 
                                                             | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                                >> 0xbU))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                   << 0x15U) 
                                                  | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                     >> 0xbU))) 
                                   >> 0x20U)) >> 0x14U));
            } else {
                VL_WRITEF("[ERROR][Divider.sv] divided by 0 opcode error\n");
            }
        } else {
            VL_ADD_W(5, __Vtemp_11, vlSelf->sim_divider_top__DOT__divider__DOT__pr_s, vlSelf->sim_divider_top__DOT__divider__DOT__pr_c);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                = __Vtemp_11[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                = __Vtemp_11[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                = __Vtemp_11[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                = __Vtemp_11[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                = (7U & __Vtemp_11[4U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            VL_SUB_W(3, __Vtemp_13, vlSelf->sim_divider_top__DOT__divider__DOT__q_positive, vlSelf->sim_divider_top__DOT__divider__DOT__q_negative);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                = __Vtemp_13[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                = __Vtemp_13[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                = (3U & __Vtemp_13[2U]);
            if ((0U != ((((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                           | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U]) 
                          | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U]) 
                         | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U]) 
                        | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U]))) {
                if ((1U & vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U])) {
                    if ((1U & (~ (vlSelf->sim_divider_top__DOT__divider__DOT__z[4U] 
                                  >> 2U)))) {
                        if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative) {
                            VL_EXTENDS_WW(131,65, __Vtemp_17, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                            VL_SUB_W(5, __Vtemp_18, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_17);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                                = __Vtemp_18[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                                = __Vtemp_18[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                                = __Vtemp_18[2U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                                = __Vtemp_18[3U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                                = (7U & __Vtemp_18[4U]);
                            __Vtemp_21[0U] = 1U;
                            __Vtemp_21[1U] = 0U;
                            __Vtemp_21[2U] = 0U;
                            VL_ADD_W(3, __Vtemp_22, __Vtemp_21, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                                = __Vtemp_22[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                                = __Vtemp_22[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                                = (3U & __Vtemp_22[2U]);
                        } else {
                            VL_EXTENDS_WW(131,65, __Vtemp_25, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                            VL_ADD_W(5, __Vtemp_26, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_25);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                                = __Vtemp_26[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                                = __Vtemp_26[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                                = __Vtemp_26[2U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                                = __Vtemp_26[3U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                                = (7U & __Vtemp_26[4U]);
                            __Vtemp_29[0U] = 1U;
                            __Vtemp_29[1U] = 0U;
                            __Vtemp_29[2U] = 0U;
                            VL_SUB_W(3, __Vtemp_30, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q, __Vtemp_29);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                                = __Vtemp_30[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                                = __Vtemp_30[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                                = (3U & __Vtemp_30[2U]);
                        }
                    }
                } else if ((4U & vlSelf->sim_divider_top__DOT__divider__DOT__z[4U])) {
                    if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative) {
                        VL_EXTENDS_WW(131,65, __Vtemp_33, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                        VL_ADD_W(5, __Vtemp_34, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_33);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                            = __Vtemp_34[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                            = __Vtemp_34[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                            = __Vtemp_34[2U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                            = __Vtemp_34[3U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                            = (7U & __Vtemp_34[4U]);
                        __Vtemp_37[0U] = 1U;
                        __Vtemp_37[1U] = 0U;
                        __Vtemp_37[2U] = 0U;
                        VL_SUB_W(3, __Vtemp_38, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q, __Vtemp_37);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                            = __Vtemp_38[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                            = __Vtemp_38[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                            = (3U & __Vtemp_38[2U]);
                    } else {
                        VL_EXTENDS_WW(131,65, __Vtemp_41, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                        VL_SUB_W(5, __Vtemp_42, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_41);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                            = __Vtemp_42[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                            = __Vtemp_42[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                            = __Vtemp_42[2U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                            = __Vtemp_42[3U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                            = (7U & __Vtemp_42[4U]);
                        __Vtemp_45[0U] = 1U;
                        __Vtemp_45[1U] = 0U;
                        __Vtemp_45[2U] = 0U;
                        VL_ADD_W(3, __Vtemp_46, __Vtemp_45, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                            = __Vtemp_46[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                            = __Vtemp_46[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                            = (3U & __Vtemp_46[2U]);
                    }
                }
            }
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            if (((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                     >> 7U))) || (0x43U 
                                                  == 
                                                  (0xffU 
                                                   & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                      >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]) 
                                   >> 0x20U)) >> 0x14U));
            } else if (((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (VL_LIKELY(((0x49U == (0xffU 
                                             & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                >> 7U))) 
                                  || (0x4aU == (0xffU 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 7U)))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]) 
                                   >> 0x20U)) >> 0x14U));
            } else {
                VL_WRITEF("[ERROR][Divider.sv] divide opcode error\n");
            }
        }
    } else if ((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[0U] 
            = (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] 
               << 7U);
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[1U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[2U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[3U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[4U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[0U] 
            = (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] 
               << 7U);
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[1U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[2U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[3U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[4U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U] 
                             << 7U));
        if ((0U == vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next)) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 2U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next = 0U;
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 1U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                = (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                   - (IData)(2U));
        }
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper 
            = (0xffU & (((0x89U >= (0xffU & ((IData)(3U) 
                                             + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                          ? (((0U == (0x1fU & ((IData)(3U) 
                                               + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                               ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[
                                       (((IData)(7U) 
                                         + (0xffU & 
                                            ((IData)(3U) 
                                             + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           ((IData)(3U) 
                                            + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                               + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))) 
                             | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[
                                (7U & (((IData)(3U) 
                                        + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                           + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)) 
                                       >> 5U))] >> 
                                (0x1fU & ((IData)(3U) 
                                          + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                             + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))
                          : 0U) + ((0x89U >= (0xffU 
                                              & ((IData)(3U) 
                                                 + 
                                                 (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                                    ? (((0U == (0x1fU 
                                                & ((IData)(3U) 
                                                   + 
                                                   (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                    + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                                         ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[
                                                 (((IData)(7U) 
                                                   + 
                                                   (0xffU 
                                                    & ((IData)(3U) 
                                                       + 
                                                       (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                        + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                       + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))) 
                                       | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[
                                          (7U & (((IData)(3U) 
                                                  + 
                                                  (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                   + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)) 
                                                 >> 5U))] 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 + 
                                                 (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))
                                    : 0U)));
        vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative 
            = (1U & ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper) 
                     >> 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper_abs 
            = (0xffU & ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative)
                         ? ((IData)(1U) + (~ (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper)))
                         : (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper)));
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb 
            = (0x7fU & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper_abs));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] = 0U;
        if ((0U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
             [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
             [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb])) {
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] = 0U;
        } else if ((1U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                    [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                    [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb])) {
            VL_EXTENDS_WW(131,65, __Vtemp_48, vlSelf->sim_divider_top__DOT__divider__DOT__d);
            VL_SHIFTL_WWI(131,131,32, __Vtemp_49, __Vtemp_48, vlSelf->sim_divider_top__DOT__divider__DOT__q_idx);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_49[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_49[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_49[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_49[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_49[4U]);
        } else if (VL_LIKELY((2U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                              [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                              [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb]))) {
            __Vtemp_51[0U] = (vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] 
                              << 1U);
            __Vtemp_51[1U] = ((vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] 
                               >> 0x1fU) | (vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] 
                                            << 1U));
            __Vtemp_51[2U] = ((vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] 
                               >> 0x1fU) | (vlSelf->sim_divider_top__DOT__divider__DOT__d[2U] 
                                            << 1U));
            VL_EXTENDS_WW(131,66, __Vtemp_52, __Vtemp_51);
            VL_SHIFTL_WWI(131,131,32, __Vtemp_53, __Vtemp_52, vlSelf->sim_divider_top__DOT__divider__DOT__q_idx);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_53[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_53[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_53[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_53[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_53[4U]);
        } else {
            VL_WRITEF("[ERROR][Divider.sv] table check error\n");
        }
        if (((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative) 
             ^ (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__d_negative))) {
            vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h9f7d7aa7__0 
                = vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb];
            if (VL_LIKELY((0x41U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx)))) {
                VL_ASSIGNSEL_WI(66,2,(0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx), vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next, vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h9f7d7aa7__0);
            }
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h45da49ca__0 
                = vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb];
            __Vtemp_56[0U] = 1U;
            __Vtemp_56[1U] = 0U;
            __Vtemp_56[2U] = 0U;
            __Vtemp_56[3U] = 0U;
            __Vtemp_56[4U] = 0U;
            __Vtemp_57[0U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U]);
            __Vtemp_57[1U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U]);
            __Vtemp_57[2U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U]);
            __Vtemp_57[3U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U]);
            __Vtemp_57[4U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U]);
            VL_ADD_W(5, __Vtemp_58, __Vtemp_56, __Vtemp_57);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_58[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_58[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_58[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_58[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_58[4U]);
            if (VL_LIKELY((0x41U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx)))) {
                VL_ASSIGNSEL_WI(66,2,(0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx), vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next, vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h45da49ca__0);
            }
        }
        VL_SEL_WWII(131,262, __Vtemp_64, ([&]() {
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i = 0U;
                    while ((0x83U > vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) {
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0 
                            = ((((0x82U >= (0xffU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                 && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                           (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                ^ ((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) 
                               ^ ((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))));
                        if (VL_LIKELY((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[
                                          (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[
                                    (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0) 
                                      << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)));
                        }
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0 
                            = (((((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                 & ((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) 
                                | (((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                   & ((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                      && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                                (7U 
                                                 & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))))) 
                               | (((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                  & ((0x82U >= (0xffU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                     && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                               (7U 
                                                & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))));
                        if (VL_LIKELY((0x83U >= (0xffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[
                                          (7U & (((IData)(1U) 
                                                  + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i) 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & 
                                            ((IData)(1U) 
                                             + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[
                                    (7U & (((IData)(1U) 
                                            + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i) 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0) 
                                      << (0x1fU & ((IData)(1U) 
                                                   + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))));
                        }
                        vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                            = ((IData)(1U) + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i);
                    }
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[0U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[1U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[2U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[3U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[4U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] 
                            << 3U) | vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[4U]);
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[5U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[6U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[7U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[8U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] 
                            >> 0x1dU) | (0x38U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[4U] 
                                                  << 3U)));
                }(), vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout), 0x83U, 0x83U);
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] 
            = __Vtemp_64[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] 
            = __Vtemp_64[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] 
            = __Vtemp_64[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] 
            = __Vtemp_64[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] 
            = (7U & __Vtemp_64[4U]);
        VL_SEL_WWII(131,262, __Vtemp_70, ([&]() {
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i = 0U;
                    while ((0x83U > vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) {
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0 
                            = ((((0x82U >= (0xffU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                 && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                           (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                ^ ((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) 
                               ^ ((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))));
                        if (VL_LIKELY((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[
                                          (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[
                                    (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0) 
                                      << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)));
                        }
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0 
                            = (((((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                 & ((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) 
                                | (((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                   & ((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                      && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                                (7U 
                                                 & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))))) 
                               | (((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                  & ((0x82U >= (0xffU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                     && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                               (7U 
                                                & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))));
                        if (VL_LIKELY((0x83U >= (0xffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[
                                          (7U & (((IData)(1U) 
                                                  + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i) 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & 
                                            ((IData)(1U) 
                                             + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[
                                    (7U & (((IData)(1U) 
                                            + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i) 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0) 
                                      << (0x1fU & ((IData)(1U) 
                                                   + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))));
                        }
                        vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                            = ((IData)(1U) + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i);
                    }
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[0U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[1U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[2U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[3U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[4U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] 
                            << 3U) | vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[4U]);
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[5U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[6U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[7U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[8U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] 
                            >> 0x1dU) | (0x38U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[4U] 
                                                  << 3U)));
                }(), vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout), 0U, 0x83U);
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
            = __Vtemp_70[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
            = __Vtemp_70[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
            = __Vtemp_70[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
            = __Vtemp_70[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
            = (7U & __Vtemp_70[4U]);
    } else if ((0x8000U & vlSelf->sim_divider_top__DOT__op_in[9U])) {
        if (((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                 >> 7U))) || (0x44U 
                                              == (0xffU 
                                                  & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                                     >> 7U))))) {
            VL_EXTENDS_WQ(131,64, __Vtemp_72, (((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                                << 0x35U) 
                                               | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                     >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_72[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_72[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_72[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_72[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_72[4U]);
            VL_EXTENDS_WQ(65,64, __Vtemp_74, (((QData)((IData)(
                                                               vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                               << 0x35U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                                    >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_74[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_74[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_74[2U]);
        } else if (((0x43U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))) || 
                    (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))))) {
            __Vtemp_76[0U] = (IData)((((QData)((IData)(
                                                       vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                        >> 0xbU))));
            __Vtemp_76[1U] = (IData)(((((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                        << 0x35U) | 
                                       (((QData)((IData)(
                                                         vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                         << 0x15U) 
                                        | ((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                           >> 0xbU))) 
                                      >> 0x20U));
            __Vtemp_76[2U] = 0U;
            VL_EXTENDS_WW(131,65, __Vtemp_77, __Vtemp_76);
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_77[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_77[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_77[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_77[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_77[4U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = (IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__op_in[5U])) 
                            << 0x35U) | (((QData)((IData)(
                                                          vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                          << 0x15U) 
                                         | ((QData)((IData)(
                                                            vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                            >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = (IData)(((((QData)((IData)(vlSelf->sim_divider_top__DOT__op_in[5U])) 
                             << 0x35U) | (((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                           << 0x15U) 
                                          | ((QData)((IData)(
                                                             vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                             >> 0xbU))) 
                           >> 0x20U));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] = 0U;
        } else if (((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))) || 
                    (0x49U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))))) {
            VL_EXTENDS_WI(131,32, __Vtemp_79, ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                                << 0x15U) 
                                               | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                                  >> 0xbU)));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_79[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_79[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_79[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_79[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_79[4U]);
            VL_EXTENDS_WI(65,32, __Vtemp_81, ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                               << 0x15U) 
                                              | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                                 >> 0xbU)));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_81[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_81[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_81[2U]);
        } else if (VL_LIKELY(((0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                                  >> 7U))) 
                              || (0x4aU == (0xffU & 
                                            (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U)))))) {
            VL_EXTENDS_WQ(131,33, __Vtemp_83, (QData)((IData)(
                                                              ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                                                << 0x15U) 
                                                               | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                                                  >> 0xbU)))));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_83[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_83[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_83[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_83[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_83[4U]);
            VL_EXTENDS_WQ(65,33, __Vtemp_85, (QData)((IData)(
                                                             ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                                               << 0x15U) 
                                                              | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                                                 >> 0xbU)))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_85[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_85[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_85[2U]);
        } else {
            VL_WRITEF("[ERROR][Divider.sv] divide opcode error\n");
        }
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[0U] 
            = vlSelf->sim_divider_top__DOT__op_in[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[1U] 
            = vlSelf->sim_divider_top__DOT__op_in[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[2U] 
            = vlSelf->sim_divider_top__DOT__op_in[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[3U] 
            = vlSelf->sim_divider_top__DOT__op_in[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[4U] 
            = vlSelf->sim_divider_top__DOT__op_in[4U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[5U] 
            = vlSelf->sim_divider_top__DOT__op_in[5U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[6U] 
            = vlSelf->sim_divider_top__DOT__op_in[6U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[7U] 
            = vlSelf->sim_divider_top__DOT__op_in[7U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[8U] 
            = vlSelf->sim_divider_top__DOT__op_in[8U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[9U] 
            = vlSelf->sim_divider_top__DOT__op_in[9U];
        if ((0U == ((vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                     | vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U]) 
                    | vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]))) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 3U;
        } else if ((((((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                           >> 7U))) 
                       | (0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U)))) 
                      & (0x8000000000000000ULL == (
                                                   ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                                    << 0x35U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                                       << 0x15U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                         >> 0xbU))))) 
                     & (0xffffffffffffffffULL == (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                   << 0x35U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                                      << 0x15U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                                        >> 0xbU))))) 
                    | ((((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U))) 
                         | (0x49U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                               >> 7U)))) 
                        & (0x80000000U == ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                            << 0x15U) 
                                           | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                              >> 0xbU)))) 
                       & (0xffffffffU == ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                           << 0x15U) 
                                          | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                             >> 0xbU)))))) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 4U;
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next 
                = (1U & vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            __Vtemp_88[0U] = 1U;
            __Vtemp_88[1U] = 0U;
            __Vtemp_88[2U] = 0U;
            __Vtemp_89[0U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U]);
            __Vtemp_89[1U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U]);
            __Vtemp_89[2U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            VL_ADD_W(3, __Vtemp_90, __Vtemp_88, __Vtemp_89);
            if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next) {
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    = __Vtemp_90[0U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    = __Vtemp_90[1U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                    = (1U & __Vtemp_90[2U]);
            } else {
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                    = (1U & vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = 0U;
            {
                while ((0x41U > vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i)) {
                    if (((0x40U >= (0x7fU & ((IData)(0x40U) 
                                             - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i))) 
                         && (1U & (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[
                                   (3U & (((IData)(0x40U) 
                                           - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i) 
                                          >> 5U))] 
                                   >> (0x1fU & ((IData)(0x40U) 
                                                - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i)))))) {
                        vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
                            = ((IData)(0x40U) - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i);
                        goto __Vlabel1;
                    }
                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i 
                        = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i);
                }
                __Vlabel1: ;
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[0U] 
                = (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                   << 5U);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[1U] 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    >> 0x1bU) | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                                 << 5U));
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[2U] 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    >> 0x1bU) | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                                 << 5U));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next 
                = ((0x45U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))
                    ? (0x1fU & (((0U == (0x1fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))
                                  ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[
                                          (((IData)(4U) 
                                            + (0x7fU 
                                               & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)))) 
                                | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[
                                   (3U & (vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
                                          >> 5U))] 
                                   >> (0x1fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))))
                    : 0U);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i = 0U;
            {
                while ((0x82U > vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i)) {
                    if (((1U & (vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                                >> 2U)) != ((0x82U 
                                             >= (0xffU 
                                                 & ((IData)(0x81U) 
                                                    - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i))) 
                                            && (1U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__z_next[
                                                   (7U 
                                                    & (((IData)(0x81U) 
                                                        - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x81U) 
                                                       - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i))))))) {
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                            = ((IData)(0x81U) - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i);
                        goto __Vlabel2;
                    }
                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i 
                        = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i);
                }
                __Vlabel2: ;
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                    > vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)
                    ? (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                       - vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)
                    : 0U);
            if ((1U & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next)) {
                vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                    = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next);
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 1U;
        }
    }
    if (vlSelf->flush_in) {
        vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
        vlSelf->sim_divider_top__DOT__op_out[8U] = 
            (3U & vlSelf->sim_divider_top__DOT__op_out[8U]);
    }
    vlSelf->stall_out = (0U != (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next));
    vlSelf->resp_valid = (1U & (vlSelf->sim_divider_top__DOT__op_out[8U] 
                                >> 2U));
    vlSelf->resp_opcode = (0xffU & ((vlSelf->sim_divider_top__DOT__op_out[8U] 
                                     << 6U) | (vlSelf->sim_divider_top__DOT__op_out[7U] 
                                               >> 0x1aU)));
    vlSelf->resp_value = (((QData)((IData)(vlSelf->sim_divider_top__DOT__op_out[6U])) 
                           << 0x34U) | (((QData)((IData)(
                                                         vlSelf->sim_divider_top__DOT__op_out[5U])) 
                                         << 0x14U) 
                                        | ((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_out[4U])) 
                                           >> 0xcU)));
}

void Vsim_divider_top___024root___eval_ico(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsim_divider_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vsim_divider_top___024root___eval_triggers__ico(Vsim_divider_top___024root* vlSelf);

bool Vsim_divider_top___024root___eval_phase__ico(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsim_divider_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsim_divider_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsim_divider_top___024root___eval_act(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__12(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__12\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__13(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__13\n"); );
    // Body
    vlSelf->sim_divider_top__DOT__divider__DOT__div_state 
        = ((IData)(vlSelf->reset) ? 0U : (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__14(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__14\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[0U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[2U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[3U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[4U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[4U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[5U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[6U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[7U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[8U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
            = Vsim_divider_top__ConstPool__CONST_h7c08bc10_0[9U];
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[3U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[4U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[4U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[5U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[6U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[7U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[8U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[9U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__15(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__15\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__z[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__z[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__z[2U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__z[3U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__z[4U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__z[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__z[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__z[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__z[3U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__z[4U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__16(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__16\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__d[2U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__d[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__17(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__17\n"); );
    // Body
    vlSelf->sim_divider_top__DOT__divider__DOT__d_negative 
        = ((1U & (~ (IData)(vlSelf->reset))) && (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__18(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__18\n"); );
    // Body
    vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb 
        = ((IData)(vlSelf->reset) ? 0U : (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__19(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__19\n"); );
    // Body
    vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit 
        = ((IData)(vlSelf->reset) ? 0U : vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next);
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__20(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__20\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__21(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__21\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[2U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[2U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__22(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__22\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[2U] = 0U;
    } else {
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[0U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[1U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[2U] 
            = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[2U];
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__23(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__23\n"); );
    // Body
    vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
        = ((IData)(vlSelf->reset) ? 0U : vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next);
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__36(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__36\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<5>/*159:0*/ __Vtemp_14;
    VlWide<5>/*159:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<5>/*159:0*/ __Vtemp_22;
    VlWide<5>/*159:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<5>/*159:0*/ __Vtemp_30;
    VlWide<5>/*159:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<5>/*159:0*/ __Vtemp_38;
    VlWide<5>/*159:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<5>/*159:0*/ __Vtemp_45;
    VlWide<5>/*159:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<5>/*159:0*/ __Vtemp_49;
    VlWide<5>/*159:0*/ __Vtemp_50;
    VlWide<5>/*159:0*/ __Vtemp_53;
    VlWide<5>/*159:0*/ __Vtemp_54;
    VlWide<5>/*159:0*/ __Vtemp_55;
    VlWide<5>/*159:0*/ __Vtemp_61;
    VlWide<5>/*159:0*/ __Vtemp_67;
    VlWide<5>/*159:0*/ __Vtemp_69;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<5>/*159:0*/ __Vtemp_74;
    VlWide<5>/*159:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<5>/*159:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    // Body
    vlSelf->sim_divider_top__DOT__op_out[0U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[1U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[2U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[3U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[4U] = (0xe00U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U] 
                                                   << 1U));
    vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
    vlSelf->sim_divider_top__DOT__op_out[6U] = (((IData)(
                                                         (0x7fffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U]))))) 
                                                 << 0x13U) 
                                                | ((0x40000U 
                                                    & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
                                                       >> 0xbU)) 
                                                   | (0x3f000U 
                                                      & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U] 
                                                         << 1U))));
    vlSelf->sim_divider_top__DOT__op_out[7U] = ((0xfc000000U 
                                                 & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                    << 0x13U)) 
                                                | (((IData)(
                                                            (0x7fffffffffULL 
                                                             & (((QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U]))))) 
                                                    >> 0xdU) 
                                                   | ((IData)(
                                                              ((0x7fffffffffULL 
                                                                & (((QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U])) 
                                                                    << 0x20U) 
                                                                   | (QData)((IData)(
                                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U])))) 
                                                               >> 0x20U)) 
                                                      << 0x13U)));
    vlSelf->sim_divider_top__DOT__op_out[8U] = (3U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 0xdU));
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[5U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[6U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[7U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[8U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[8U];
    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[9U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U];
    vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__div_state;
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__z[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_negative;
    vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb;
    vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit;
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
    vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_positive[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[0U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[0U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[1U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[1U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[2U] 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_negative[2U];
    vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
        = vlSelf->sim_divider_top__DOT__divider__DOT__q_idx;
    if ((4U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state)))) {
            VL_WRITEF("[ERROR]\n");
        } else if (VL_UNLIKELY((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state)))) {
            VL_WRITEF("[ERROR]\n");
        } else {
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            if ((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                    >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0x800U | (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]));
            } else if ((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                           >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else if ((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                           >> 7U)))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0xfffff800U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffU | (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]));
            } else if (VL_LIKELY((0x49U == (0xffU & 
                                            (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                             >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else {
                VL_WRITEF("[ERROR][Divider.sv] overflow opcode error\n");
                vlSelf->sim_divider_top__DOT__op_out[8U] 
                    = (3U & vlSelf->sim_divider_top__DOT__op_out[8U]);
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0U;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]);
            }
        }
    } else if ((2U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        if ((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            if (((((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                       >> 7U))) || 
                   (0x43U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                       >> 7U)))) || 
                  (0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                      >> 7U)))) || 
                 (0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                     >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = (0xfffff000U | vlSelf->sim_divider_top__DOT__op_out[4U]);
                vlSelf->sim_divider_top__DOT__op_out[5U] = 0xffffffffU;
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = (0xfffU | vlSelf->sim_divider_top__DOT__op_out[6U]);
            } else if (((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                    >> 0xbU)))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                  << 0x35U) | (((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                << 0x15U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                  >> 0xbU)))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                                << 0x35U) 
                                               | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                     >> 0xbU))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[7U])) 
                                     << 0x35U) | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U])) 
                                                     >> 0xbU))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (VL_LIKELY(((0x49U == (0xffU 
                                             & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                >> 7U))) 
                                  || (0x4aU == (0xffU 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 7U)))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                  << 0x15U) 
                                                 | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                    >> 0xbU)))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                << 0x15U) 
                                               | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                  >> 0xbU)))) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                              << 0x15U) 
                                                             | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                                >> 0xbU))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 ((vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[6U] 
                                                   << 0x15U) 
                                                  | (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[5U] 
                                                     >> 0xbU))) 
                                   >> 0x20U)) >> 0x14U));
            } else {
                VL_WRITEF("[ERROR][Divider.sv] divided by 0 opcode error\n");
            }
        } else {
            VL_ADD_W(5, __Vtemp_8, vlSelf->sim_divider_top__DOT__divider__DOT__pr_s, vlSelf->sim_divider_top__DOT__divider__DOT__pr_c);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                = __Vtemp_8[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                = __Vtemp_8[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                = __Vtemp_8[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                = __Vtemp_8[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                = (7U & __Vtemp_8[4U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
            VL_SUB_W(3, __Vtemp_10, vlSelf->sim_divider_top__DOT__divider__DOT__q_positive, vlSelf->sim_divider_top__DOT__divider__DOT__q_negative);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                = __Vtemp_10[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                = __Vtemp_10[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                = (3U & __Vtemp_10[2U]);
            if ((0U != ((((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                           | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U]) 
                          | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U]) 
                         | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U]) 
                        | vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U]))) {
                if ((1U & vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U])) {
                    if ((1U & (~ (vlSelf->sim_divider_top__DOT__divider__DOT__z[4U] 
                                  >> 2U)))) {
                        if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative) {
                            VL_EXTENDS_WW(131,65, __Vtemp_14, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                            VL_SUB_W(5, __Vtemp_15, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_14);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                                = __Vtemp_15[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                                = __Vtemp_15[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                                = __Vtemp_15[2U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                                = __Vtemp_15[3U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                                = (7U & __Vtemp_15[4U]);
                            __Vtemp_18[0U] = 1U;
                            __Vtemp_18[1U] = 0U;
                            __Vtemp_18[2U] = 0U;
                            VL_ADD_W(3, __Vtemp_19, __Vtemp_18, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                                = __Vtemp_19[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                                = __Vtemp_19[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                                = (3U & __Vtemp_19[2U]);
                        } else {
                            VL_EXTENDS_WW(131,65, __Vtemp_22, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                            VL_ADD_W(5, __Vtemp_23, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_22);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                                = __Vtemp_23[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                                = __Vtemp_23[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                                = __Vtemp_23[2U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                                = __Vtemp_23[3U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                                = (7U & __Vtemp_23[4U]);
                            __Vtemp_26[0U] = 1U;
                            __Vtemp_26[1U] = 0U;
                            __Vtemp_26[2U] = 0U;
                            VL_SUB_W(3, __Vtemp_27, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q, __Vtemp_26);
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                                = __Vtemp_27[0U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                                = __Vtemp_27[1U];
                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                                = (3U & __Vtemp_27[2U]);
                        }
                    }
                } else if ((4U & vlSelf->sim_divider_top__DOT__divider__DOT__z[4U])) {
                    if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative) {
                        VL_EXTENDS_WW(131,65, __Vtemp_30, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                        VL_ADD_W(5, __Vtemp_31, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_30);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                            = __Vtemp_31[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                            = __Vtemp_31[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                            = __Vtemp_31[2U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                            = __Vtemp_31[3U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                            = (7U & __Vtemp_31[4U]);
                        __Vtemp_34[0U] = 1U;
                        __Vtemp_34[1U] = 0U;
                        __Vtemp_34[2U] = 0U;
                        VL_SUB_W(3, __Vtemp_35, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q, __Vtemp_34);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                            = __Vtemp_35[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                            = __Vtemp_35[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                            = (3U & __Vtemp_35[2U]);
                    } else {
                        VL_EXTENDS_WW(131,65, __Vtemp_38, vlSelf->sim_divider_top__DOT__divider__DOT__d);
                        VL_SUB_W(5, __Vtemp_39, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r, __Vtemp_38);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U] 
                            = __Vtemp_39[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U] 
                            = __Vtemp_39[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[2U] 
                            = __Vtemp_39[2U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[3U] 
                            = __Vtemp_39[3U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[4U] 
                            = (7U & __Vtemp_39[4U]);
                        __Vtemp_42[0U] = 1U;
                        __Vtemp_42[1U] = 0U;
                        __Vtemp_42[2U] = 0U;
                        VL_ADD_W(3, __Vtemp_43, __Vtemp_42, vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q);
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U] 
                            = __Vtemp_43[0U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U] 
                            = __Vtemp_43[1U];
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[2U] 
                            = (3U & __Vtemp_43[2U]);
                    }
                }
            }
            vlSelf->sim_divider_top__DOT__op_out[8U] 
                = (4U | vlSelf->sim_divider_top__DOT__op_out[8U]);
            if (((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                     >> 7U))) || (0x43U 
                                                  == 
                                                  (0xffU 
                                                   & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                      >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U])) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q[0U]) 
                                   >> 0x20U)) >> 0x14U));
            } else if (((0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                            >> 7U))) 
                        || (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                               >> 7U))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)((((QData)((IData)(
                                                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])))) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])))) 
                        >> 0x14U) | ((IData)(((((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]))) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)(((((QData)((IData)(
                                                     vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]))) 
                                   >> 0x20U)) >> 0x14U));
            } else if (VL_LIKELY(((0x49U == (0xffU 
                                             & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                >> 7U))) 
                                  || (0x4aU == (0xffU 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__op_executing[9U] 
                                                   >> 7U)))))) {
                vlSelf->sim_divider_top__DOT__op_out[4U] 
                    = ((0xfffU & vlSelf->sim_divider_top__DOT__op_out[4U]) 
                       | ((IData)(VL_EXTENDS_QI(64,32, 
                                                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])) 
                          << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[5U] 
                    = (((IData)(VL_EXTENDS_QI(64,32, 
                                              vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U])) 
                        >> 0x14U) | ((IData)((VL_EXTENDS_QI(64,32, 
                                                            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]) 
                                              >> 0x20U)) 
                                     << 0xcU));
                vlSelf->sim_divider_top__DOT__op_out[6U] 
                    = ((0xfffff000U & vlSelf->sim_divider_top__DOT__op_out[6U]) 
                       | ((IData)((VL_EXTENDS_QI(64,32, 
                                                 vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r[0U]) 
                                   >> 0x20U)) >> 0x14U));
            } else {
                VL_WRITEF("[ERROR][Divider.sv] divide opcode error\n");
            }
        }
    } else if ((1U & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state))) {
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[0U] 
            = (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] 
               << 7U);
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[1U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[2U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[3U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[4U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[0U] 
            = (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] 
               << 7U);
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[1U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[2U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[3U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] 
                             << 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[4U] 
            = ((vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U] 
                >> 0x19U) | (vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U] 
                             << 7U));
        if ((0U == vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next)) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 2U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next = 0U;
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 1U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                = (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                   - (IData)(2U));
        }
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper 
            = (0xffU & (((0x89U >= (0xffU & ((IData)(3U) 
                                             + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                          ? (((0U == (0x1fU & ((IData)(3U) 
                                               + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                               ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[
                                       (((IData)(7U) 
                                         + (0xffU & 
                                            ((IData)(3U) 
                                             + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))) 
                                        >> 5U)] << 
                                       ((IData)(0x20U) 
                                        - (0x1fU & 
                                           ((IData)(3U) 
                                            + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                               + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))) 
                             | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s[
                                (7U & (((IData)(3U) 
                                        + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                           + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)) 
                                       >> 5U))] >> 
                                (0x1fU & ((IData)(3U) 
                                          + (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                             + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))
                          : 0U) + ((0x89U >= (0xffU 
                                              & ((IData)(3U) 
                                                 + 
                                                 (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                                    ? (((0U == (0x1fU 
                                                & ((IData)(3U) 
                                                   + 
                                                   (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                    + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit))))
                                         ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[
                                                 (((IData)(7U) 
                                                   + 
                                                   (0xffU 
                                                    & ((IData)(3U) 
                                                       + 
                                                       (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                        + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))) 
                                                  >> 5U)] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                       + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))) 
                                       | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c[
                                          (7U & (((IData)(3U) 
                                                  + 
                                                  (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                   + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)) 
                                                 >> 5U))] 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 + 
                                                 (vlSelf->sim_divider_top__DOT__divider__DOT__q_idx 
                                                  + vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit)))))
                                    : 0U)));
        vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative 
            = (1U & ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper) 
                     >> 7U));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper_abs 
            = (0xffU & ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative)
                         ? ((IData)(1U) + (~ (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper)))
                         : (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper)));
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb 
            = (0x7fU & (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper_abs));
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] = 0U;
        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] = 0U;
        if ((0U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
             [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
             [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb])) {
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] = 0U;
        } else if ((1U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                    [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                    [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb])) {
            VL_EXTENDS_WW(131,65, __Vtemp_45, vlSelf->sim_divider_top__DOT__divider__DOT__d);
            VL_SHIFTL_WWI(131,131,32, __Vtemp_46, __Vtemp_45, vlSelf->sim_divider_top__DOT__divider__DOT__q_idx);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_46[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_46[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_46[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_46[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_46[4U]);
        } else if (VL_LIKELY((2U == vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                              [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                              [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb]))) {
            __Vtemp_48[0U] = (vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] 
                              << 1U);
            __Vtemp_48[1U] = ((vlSelf->sim_divider_top__DOT__divider__DOT__d[0U] 
                               >> 0x1fU) | (vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] 
                                            << 1U));
            __Vtemp_48[2U] = ((vlSelf->sim_divider_top__DOT__divider__DOT__d[1U] 
                               >> 0x1fU) | (vlSelf->sim_divider_top__DOT__divider__DOT__d[2U] 
                                            << 1U));
            VL_EXTENDS_WW(131,66, __Vtemp_49, __Vtemp_48);
            VL_SHIFTL_WWI(131,131,32, __Vtemp_50, __Vtemp_49, vlSelf->sim_divider_top__DOT__divider__DOT__q_idx);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_50[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_50[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_50[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_50[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_50[4U]);
        } else {
            VL_WRITEF("[ERROR][Divider.sv] table check error\n");
        }
        if (((IData)(vlSelf->sim_divider_top__DOT__divider__DOT__shifted_pr_negative) 
             ^ (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__d_negative))) {
            vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h9f7d7aa7__0 
                = vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb];
            if (VL_LIKELY((0x41U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx)))) {
                VL_ASSIGNSEL_WI(66,2,(0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx), vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next, vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h9f7d7aa7__0);
            }
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h45da49ca__0 
                = vlSelf->sim_divider_top__DOT__divider__DOT__pdtable
                [vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb]
                [vlSelf->sim_divider_top__DOT__divider__DOT__pr_normalized_sb];
            __Vtemp_53[0U] = 1U;
            __Vtemp_53[1U] = 0U;
            __Vtemp_53[2U] = 0U;
            __Vtemp_53[3U] = 0U;
            __Vtemp_53[4U] = 0U;
            __Vtemp_54[0U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U]);
            __Vtemp_54[1U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U]);
            __Vtemp_54[2U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U]);
            __Vtemp_54[3U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U]);
            __Vtemp_54[4U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U]);
            VL_ADD_W(5, __Vtemp_55, __Vtemp_53, __Vtemp_54);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U] 
                = __Vtemp_55[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U] 
                = __Vtemp_55[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U] 
                = __Vtemp_55[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U] 
                = __Vtemp_55[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U] 
                = (7U & __Vtemp_55[4U]);
            if (VL_LIKELY((0x41U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx)))) {
                VL_ASSIGNSEL_WI(66,2,(0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx), vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next, vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h45da49ca__0);
            }
        }
        VL_SEL_WWII(131,262, __Vtemp_61, ([&]() {
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i = 0U;
                    while ((0x83U > vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) {
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0 
                            = ((((0x82U >= (0xffU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                 && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                           (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                ^ ((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) 
                               ^ ((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))));
                        if (VL_LIKELY((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[
                                          (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[
                                    (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0) 
                                      << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)));
                        }
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0 
                            = (((((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                 & ((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) 
                                | (((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                   & ((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                      && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                                (7U 
                                                 & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))))) 
                               | (((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                  & ((0x82U >= (0xffU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)) 
                                     && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a[
                                               (7U 
                                                & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))));
                        if (VL_LIKELY((0x83U >= (0xffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[
                                          (7U & (((IData)(1U) 
                                                  + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i) 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & 
                                            ((IData)(1U) 
                                             + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i)))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[
                                    (7U & (((IData)(1U) 
                                            + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i) 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0) 
                                      << (0x1fU & ((IData)(1U) 
                                                   + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i))));
                        }
                        vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i 
                            = ((IData)(1U) + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i);
                    }
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[0U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[1U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[2U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[3U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[4U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] 
                            << 3U) | vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum[4U]);
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[5U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[0U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[6U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[1U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[7U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[2U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout[8U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[3U] 
                            >> 0x1dU) | (0x38U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry[4U] 
                                                  << 3U)));
                }(), vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout), 0x83U, 0x83U);
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] 
            = __Vtemp_61[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] 
            = __Vtemp_61[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] 
            = __Vtemp_61[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] 
            = __Vtemp_61[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] 
            = (7U & __Vtemp_61[4U]);
        VL_SEL_WWII(131,262, __Vtemp_67, ([&]() {
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_c[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[0U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[1U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[2U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[3U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[4U] 
                        = vlSelf->sim_divider_top__DOT__divider__DOT__pr_s[4U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[4U] = 0U;
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i = 0U;
                    while ((0x83U > vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) {
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0 
                            = ((((0x82U >= (0xffU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                 && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                           (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                  >> 5U))] 
                                           >> (0x1fU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                ^ ((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) 
                               ^ ((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))));
                        if (VL_LIKELY((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[
                                          (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[
                                    (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0) 
                                      << (0x1fU & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)));
                        }
                        vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0 
                            = (((((0x82U >= (0xffU 
                                             & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                  && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                            (7U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                            >> (0x1fU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                 & ((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) 
                                | (((0x82U >= (0xffU 
                                               & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                    && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b[
                                              (7U & 
                                               (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                >> 5U))] 
                                              >> (0x1fU 
                                                  & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                   & ((0x82U >= (0xffU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                      && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                                (7U 
                                                 & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                    >> 5U))] 
                                                >> 
                                                (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))))) 
                               | (((0x82U >= (0xffU 
                                              & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                   && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c[
                                             (7U & 
                                              (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                               >> 5U))] 
                                             >> (0x1fU 
                                                 & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                  & ((0x82U >= (0xffU 
                                                & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)) 
                                     && (1U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a[
                                               (7U 
                                                & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                                                   >> 5U))] 
                                               >> (0x1fU 
                                                   & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))));
                        if (VL_LIKELY((0x83U >= (0xffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))))) {
                            vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[
                                          (7U & (((IData)(1U) 
                                                  + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i) 
                                                 >> 5U))] 
                                = (((~ ((IData)(1U) 
                                        << (0x1fU & 
                                            ((IData)(1U) 
                                             + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i)))) 
                                    & vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[
                                    (7U & (((IData)(1U) 
                                            + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i) 
                                           >> 5U))]) 
                                   | ((IData)(vlSelf->sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0) 
                                      << (0x1fU & ((IData)(1U) 
                                                   + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i))));
                        }
                        vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i 
                            = ((IData)(1U) + vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i);
                    }
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[0U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[0U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[1U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[1U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[2U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[2U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[3U] 
                        = vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[3U];
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[4U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] 
                            << 3U) | vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum[4U]);
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[5U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[0U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[6U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[1U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[7U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[2U] 
                            >> 0x1dU) | (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] 
                                         << 3U));
                    vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout[8U] 
                        = ((vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[3U] 
                            >> 0x1dU) | (0x38U & (vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry[4U] 
                                                  << 3U)));
                }(), vlSelf->__Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout), 0U, 0x83U);
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
            = __Vtemp_67[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
            = __Vtemp_67[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
            = __Vtemp_67[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
            = __Vtemp_67[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
            = (7U & __Vtemp_67[4U]);
    } else if ((0x8000U & vlSelf->sim_divider_top__DOT__op_in[9U])) {
        if (((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                 >> 7U))) || (0x44U 
                                              == (0xffU 
                                                  & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                                     >> 7U))))) {
            VL_EXTENDS_WQ(131,64, __Vtemp_69, (((QData)((IData)(
                                                                vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                                << 0x35U) 
                                               | (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                                   << 0x15U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                     >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_69[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_69[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_69[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_69[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_69[4U]);
            VL_EXTENDS_WQ(65,64, __Vtemp_71, (((QData)((IData)(
                                                               vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                               << 0x35U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                                    >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_71[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_71[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_71[2U]);
        } else if (((0x43U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))) || 
                    (0x45U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))))) {
            __Vtemp_73[0U] = (IData)((((QData)((IData)(
                                                       vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                        >> 0xbU))));
            __Vtemp_73[1U] = (IData)(((((QData)((IData)(
                                                        vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                        << 0x35U) | 
                                       (((QData)((IData)(
                                                         vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                         << 0x15U) 
                                        | ((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                           >> 0xbU))) 
                                      >> 0x20U));
            __Vtemp_73[2U] = 0U;
            VL_EXTENDS_WW(131,65, __Vtemp_74, __Vtemp_73);
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_74[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_74[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_74[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_74[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_74[4U]);
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = (IData)((((QData)((IData)(vlSelf->sim_divider_top__DOT__op_in[5U])) 
                            << 0x35U) | (((QData)((IData)(
                                                          vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                          << 0x15U) 
                                         | ((QData)((IData)(
                                                            vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                            >> 0xbU))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = (IData)(((((QData)((IData)(vlSelf->sim_divider_top__DOT__op_in[5U])) 
                             << 0x35U) | (((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                           << 0x15U) 
                                          | ((QData)((IData)(
                                                             vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                             >> 0xbU))) 
                           >> 0x20U));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] = 0U;
        } else if (((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))) || 
                    (0x49U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                        >> 7U))))) {
            VL_EXTENDS_WI(131,32, __Vtemp_76, ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                                << 0x15U) 
                                               | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                                  >> 0xbU)));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_76[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_76[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_76[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_76[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_76[4U]);
            VL_EXTENDS_WI(65,32, __Vtemp_78, ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                               << 0x15U) 
                                              | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                                 >> 0xbU)));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_78[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_78[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_78[2U]);
        } else if (VL_LIKELY(((0x48U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                                  >> 7U))) 
                              || (0x4aU == (0xffU & 
                                            (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U)))))) {
            VL_EXTENDS_WQ(131,33, __Vtemp_80, (QData)((IData)(
                                                              ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                                                << 0x15U) 
                                                               | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                                                  >> 0xbU)))));
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U] 
                = __Vtemp_80[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U] 
                = __Vtemp_80[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U] 
                = __Vtemp_80[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U] 
                = __Vtemp_80[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                = (7U & __Vtemp_80[4U]);
            VL_EXTENDS_WQ(65,33, __Vtemp_82, (QData)((IData)(
                                                             ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                                               << 0x15U) 
                                                              | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                                                 >> 0xbU)))));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                = __Vtemp_82[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U] 
                = __Vtemp_82[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U] 
                = (1U & __Vtemp_82[2U]);
        } else {
            VL_WRITEF("[ERROR][Divider.sv] divide opcode error\n");
        }
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[0U] 
            = vlSelf->sim_divider_top__DOT__op_in[0U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[1U] 
            = vlSelf->sim_divider_top__DOT__op_in[1U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[2U] 
            = vlSelf->sim_divider_top__DOT__op_in[2U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[3U] 
            = vlSelf->sim_divider_top__DOT__op_in[3U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[4U] 
            = vlSelf->sim_divider_top__DOT__op_in[4U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[5U] 
            = vlSelf->sim_divider_top__DOT__op_in[5U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[6U] 
            = vlSelf->sim_divider_top__DOT__op_in[6U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[7U] 
            = vlSelf->sim_divider_top__DOT__op_in[7U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[8U] 
            = vlSelf->sim_divider_top__DOT__op_in[8U];
        vlSelf->sim_divider_top__DOT__divider__DOT__op_executing_next[9U] 
            = vlSelf->sim_divider_top__DOT__op_in[9U];
        if ((0U == ((vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U] 
                     | vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U]) 
                    | vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]))) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 3U;
        } else if ((((((0x42U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                           >> 7U))) 
                       | (0x44U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U)))) 
                      & (0x8000000000000000ULL == (
                                                   ((QData)((IData)(
                                                                    vlSelf->sim_divider_top__DOT__op_in[7U])) 
                                                    << 0x35U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->sim_divider_top__DOT__op_in[6U])) 
                                                       << 0x15U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                         >> 0xbU))))) 
                     & (0xffffffffffffffffULL == (((QData)((IData)(
                                                                   vlSelf->sim_divider_top__DOT__op_in[5U])) 
                                                   << 0x35U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->sim_divider_top__DOT__op_in[4U])) 
                                                      << 0x15U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->sim_divider_top__DOT__op_in[3U])) 
                                                        >> 0xbU))))) 
                    | ((((0x47U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                             >> 7U))) 
                         | (0x49U == (0xffU & (vlSelf->sim_divider_top__DOT__op_in[9U] 
                                               >> 7U)))) 
                        & (0x80000000U == ((vlSelf->sim_divider_top__DOT__op_in[6U] 
                                            << 0x15U) 
                                           | (vlSelf->sim_divider_top__DOT__op_in[5U] 
                                              >> 0xbU)))) 
                       & (0xffffffffU == ((vlSelf->sim_divider_top__DOT__op_in[4U] 
                                           << 0x15U) 
                                          | (vlSelf->sim_divider_top__DOT__op_in[3U] 
                                             >> 0xbU)))))) {
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 4U;
        } else {
            vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next 
                = (1U & vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            __Vtemp_85[0U] = 1U;
            __Vtemp_85[1U] = 0U;
            __Vtemp_85[2U] = 0U;
            __Vtemp_86[0U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U]);
            __Vtemp_86[1U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U]);
            __Vtemp_86[2U] = (~ vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            VL_ADD_W(3, __Vtemp_87, __Vtemp_85, __Vtemp_86);
            if (vlSelf->sim_divider_top__DOT__divider__DOT__d_negative_next) {
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    = __Vtemp_87[0U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    = __Vtemp_87[1U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                    = (1U & __Vtemp_87[2U]);
            } else {
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[0U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    = vlSelf->sim_divider_top__DOT__divider__DOT__d_next[1U];
                vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                    = (1U & vlSelf->sim_divider_top__DOT__divider__DOT__d_next[2U]);
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = 0U;
            {
                while ((0x41U > vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i)) {
                    if (((0x40U >= (0x7fU & ((IData)(0x40U) 
                                             - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i))) 
                         && (1U & (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[
                                   (3U & (((IData)(0x40U) 
                                           - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i) 
                                          >> 5U))] 
                                   >> (0x1fU & ((IData)(0x40U) 
                                                - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i)))))) {
                        vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
                            = ((IData)(0x40U) - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i);
                        goto __Vlabel3;
                    }
                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i 
                        = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i);
                }
                __Vlabel3: ;
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[0U] 
                = (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                   << 5U);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[1U] 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[0U] 
                    >> 0x1bU) | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                                 << 5U));
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[2U] 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[1U] 
                    >> 0x1bU) | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs[2U] 
                                 << 5U));
            vlSelf->sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next 
                = ((0x45U >= (0x7fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))
                    ? (0x1fU & (((0U == (0x1fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))
                                  ? 0U : (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[
                                          (((IData)(4U) 
                                            + (0x7fU 
                                               & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)) 
                                           >> 5U)] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)))) 
                                | (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend[
                                   (3U & (vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next 
                                          >> 5U))] 
                                   >> (0x1fU & vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next))))
                    : 0U);
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i = 0U;
            {
                while ((0x82U > vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i)) {
                    if (((1U & (vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U] 
                                >> 2U)) != ((0x82U 
                                             >= (0xffU 
                                                 & ((IData)(0x81U) 
                                                    - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i))) 
                                            && (1U 
                                                & (vlSelf->sim_divider_top__DOT__divider__DOT__z_next[
                                                   (7U 
                                                    & (((IData)(0x81U) 
                                                        - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x81U) 
                                                       - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i))))))) {
                        vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                            = ((IData)(0x81U) - vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i);
                        goto __Vlabel4;
                    }
                    vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i 
                        = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i);
                }
                __Vlabel4: ;
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                = ((vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                    > vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)
                    ? (vlSelf->sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit 
                       - vlSelf->sim_divider_top__DOT__divider__DOT__d_shift_digit_next)
                    : 0U);
            if ((1U & vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next)) {
                vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next 
                    = ((IData)(1U) + vlSelf->sim_divider_top__DOT__divider__DOT__q_idx_next);
            }
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[0U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[0U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[1U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[1U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[2U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[2U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[3U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[3U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_s_next[4U] 
                = vlSelf->sim_divider_top__DOT__divider__DOT__z_next[4U];
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[3U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__pr_c_next[4U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_positive_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[0U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[1U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__q_negative_next[2U] = 0U;
            vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 1U;
        }
    }
    if (vlSelf->flush_in) {
        vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next = 0U;
        vlSelf->sim_divider_top__DOT__op_out[8U] = 
            (3U & vlSelf->sim_divider_top__DOT__op_out[8U]);
    }
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__37(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__37\n"); );
    // Body
    vlSelf->stall_out = (0U != (IData)(vlSelf->sim_divider_top__DOT__divider__DOT__div_state_next));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__38(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__38\n"); );
    // Body
    vlSelf->resp_valid = (1U & (vlSelf->sim_divider_top__DOT__op_out[8U] 
                                >> 2U));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__39(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__39\n"); );
    // Body
    vlSelf->resp_opcode = (0xffU & ((vlSelf->sim_divider_top__DOT__op_out[8U] 
                                     << 6U) | (vlSelf->sim_divider_top__DOT__op_out[7U] 
                                               >> 0x1aU)));
}

VL_INLINE_OPT void Vsim_divider_top___024root___nba_sequent__TOP__40(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___nba_sequent__TOP__40\n"); );
    // Body
    vlSelf->resp_value = (((QData)((IData)(vlSelf->sim_divider_top__DOT__op_out[6U])) 
                           << 0x34U) | (((QData)((IData)(
                                                         vlSelf->sim_divider_top__DOT__op_out[5U])) 
                                         << 0x14U) 
                                        | ((QData)((IData)(
                                                           vlSelf->sim_divider_top__DOT__op_out[4U])) 
                                           >> 0xcU)));
}

void Vsim_divider_top___024root___eval_triggers__act(Vsim_divider_top___024root* vlSelf);

bool Vsim_divider_top___024root___eval_phase__act(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsim_divider_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsim_divider_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vsim_divider_top___024root___eval_nba(Vsim_divider_top___024root* vlSelf);

bool Vsim_divider_top___024root___eval_phase__nba(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsim_divider_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_divider_top___024root___dump_triggers__ico(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_divider_top___024root___dump_triggers__nba(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_divider_top___024root___dump_triggers__act(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_divider_top___024root___eval(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsim_divider_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/ishida/Documents/Kazan2/src/sim_divider_top.sv", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsim_divider_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsim_divider_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/ishida/Documents/Kazan2/src/sim_divider_top.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsim_divider_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/ishida/Documents/Kazan2/src/sim_divider_top.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsim_divider_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsim_divider_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsim_divider_top___024root___eval_debug_assertions(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->flush_in & 0xfeU))) {
        Verilated::overWidthError("flush_in");}
    if (VL_UNLIKELY((vlSelf->req_valid & 0xfeU))) {
        Verilated::overWidthError("req_valid");}
}
#endif  // VL_DEBUG
