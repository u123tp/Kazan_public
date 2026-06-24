// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim_divider_top.h for the primary calling header

#ifndef VERILATED_VSIM_DIVIDER_TOP___024ROOT_H_
#define VERILATED_VSIM_DIVIDER_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class Vsim_divider_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim_divider_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*2:0*/ sim_divider_top__DOT__divider__DOT__div_state_next;
        VlWide<10>/*303:0*/ sim_divider_top__DOT__divider__DOT__op_executing_next;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__z_next;
        VlWide<3>/*64:0*/ sim_divider_top__DOT__divider__DOT__d_next;
        CData/*0:0*/ sim_divider_top__DOT__divider__DOT__d_negative_next;
        CData/*4:0*/ sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb_next;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__d_shift_digit_next;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__pr_s_next;
        VlWide<3>/*65:0*/ sim_divider_top__DOT__divider__DOT__q_positive_next;
        VlWide<3>/*65:0*/ sim_divider_top__DOT__divider__DOT__q_negative_next;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__q_idx_next;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__q_idx;
        VlWide<3>/*65:0*/ sim_divider_top__DOT__divider__DOT__q_negative;
        VlWide<3>/*65:0*/ sim_divider_top__DOT__divider__DOT__q_positive;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__pr_s;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__d_shift_digit;
        CData/*4:0*/ sim_divider_top__DOT__divider__DOT__d_normalized_frac_sb;
        CData/*0:0*/ sim_divider_top__DOT__divider__DOT__d_negative;
        VlWide<3>/*64:0*/ sim_divider_top__DOT__divider__DOT__d;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__z;
        VlWide<10>/*303:0*/ sim_divider_top__DOT__divider__DOT__op_executing;
        CData/*2:0*/ sim_divider_top__DOT__divider__DOT__div_state;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__pr_c;
        VlWide<9>/*258:0*/ sim_divider_top__DOT__op_out;
        VL_OUT64(resp_value,63,0);
        VL_IN8(req_valid,0,0);
        VL_IN8(req_opcode,7,0);
        VL_IN64(req_rs1,63,0);
        VL_IN64(req_rs2,63,0);
        VL_OUT8(resp_valid,0,0);
        VL_OUT8(resp_opcode,7,0);
        VL_OUT8(stall_out,0,0);
        VlWide<10>/*303:0*/ sim_divider_top__DOT__op_in;
        VL_IN8(flush_in,0,0);
        CData/*6:0*/ sim_divider_top__DOT__divider__DOT__pr_normalized_sb;
        CData/*0:0*/ sim_divider_top__DOT__divider__DOT__shifted_pr_negative;
        CData/*7:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper;
        CData/*7:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__shifted_pr_upper_abs;
        CData/*0:0*/ sim_divider_top__DOT__divider__DOT____Vlvbound_h2cae4469__0;
        CData/*0:0*/ sim_divider_top__DOT__divider__DOT____Vlvbound_h52c173ac__0;
        CData/*1:0*/ sim_divider_top__DOT__divider__DOT____Vlvbound_h9f7d7aa7__0;
        CData/*1:0*/ sim_divider_top__DOT__divider__DOT____Vlvbound_h45da49ca__0;
        VlWide<3>/*64:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__pm;
        VlWide<5>/*137:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_s;
        VlWide<5>/*137:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__lower_extended_shifted_pr_c;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__z_shift_digit;
        VlWide<3>/*69:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__d_abs_extend;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__r;
        VlWide<3>/*65:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__q;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ sim_divider_top__DOT__divider__DOT__unnamedblk2__DOT__unnamedblk4__DOT__i;
        VlWide<9>/*261:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__Vfuncout;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__a;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__b;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__c;
        IData/*31:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__unnamedblk1__DOT__i;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__sum;
        VlWide<5>/*131:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__0__carry;
        VlWide<9>/*261:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__Vfuncout;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__a;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__b;
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__c;
        IData/*31:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__unnamedblk1__DOT__i;
    };
    struct {
        VlWide<5>/*130:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__sum;
        VlWide<5>/*131:0*/ __Vfunc_sim_divider_top__DOT__divider__DOT__csa__1__carry;
        VlUnpacked<VlUnpacked<CData/*1:0*/, 128>, 32> sim_divider_top__DOT__divider__DOT__pdtable;
        VlWide<5>/*130:0*/ sim_divider_top__DOT__divider__DOT__pr_c_next;
        VL_IN8(reset,0,0);
        VL_IN8(clock,0,0);
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;
    VlMTaskVertex __Vm_mtaskstate_39;
    VlMTaskVertex __Vm_mtaskstate_42;
    VlMTaskVertex __Vm_mtaskstate_final__nba;

    // INTERNAL VARIABLES
    Vsim_divider_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsim_divider_top___024root(Vsim_divider_top__Syms* symsp, const char* v__name);
    ~Vsim_divider_top___024root();
    VL_UNCOPYABLE(Vsim_divider_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
