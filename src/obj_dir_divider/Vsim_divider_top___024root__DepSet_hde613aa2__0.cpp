// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_divider_top.h for the primary calling header

#include "Vsim_divider_top__pch.h"
#include "Vsim_divider_top__Syms.h"
#include "Vsim_divider_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_divider_top___024root___dump_triggers__ico(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_divider_top___024root___eval_triggers__ico(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_divider_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_divider_top___024root___dump_triggers__act(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsim_divider_top___024root___eval_triggers__act(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_divider_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vsim_divider_top___024root____Vthread__nba__0(void* voidSelf, bool even_cycle);
void Vsim_divider_top___024root____Vthread__nba__1(void* voidSelf, bool even_cycle);

void Vsim_divider_top___024root___eval_nba(Vsim_divider_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root___eval_nba\n"); );
    // Body
    vlSymsp->__Vm_even_cycle__nba = !vlSymsp->__Vm_even_cycle__nba;
    vlSymsp->__Vm_threadPoolp->workerp(0)->addTask(&Vsim_divider_top___024root____Vthread__nba__0, vlSelf, vlSymsp->__Vm_even_cycle__nba);
    Vsim_divider_top___024root____Vthread__nba__1(vlSelf, vlSymsp->__Vm_even_cycle__nba);
    Verilated::mtaskId(0);
    vlSelf->__Vm_mtaskstate_final__nba.waitUntilUpstreamDone(vlSymsp->__Vm_even_cycle__nba);
}

void Vsim_divider_top___024root___nba_sequent__TOP__14(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__20(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__21(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__17(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__18(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__23(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__36(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__40(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__38(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__37(Vsim_divider_top___024root* vlSelf);

void Vsim_divider_top___024root____Vthread__nba__0(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root____Vthread__nba__0\n"); );
    // Body
    Vsim_divider_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsim_divider_top___024root*>(voidSelf);
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Verilated::mtaskId(17);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__14(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(23);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__20(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(24);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__21(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(20);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__17(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(21);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__18(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(26);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__23(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.waitUntilUpstreamDone(even_cycle);
    Verilated::mtaskId(39);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__36(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_42.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(43);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__40(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(41);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__38(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::mtaskId(40);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__37(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_final__nba.signalUpstreamDone(even_cycle);
}

void Vsim_divider_top___024root___nba_sequent__TOP__12(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__15(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__16(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__22(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__13(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__19(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___nba_sequent__TOP__39(Vsim_divider_top___024root* vlSelf);

void Vsim_divider_top___024root____Vthread__nba__1(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_divider_top___024root____Vthread__nba__1\n"); );
    // Body
    Vsim_divider_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsim_divider_top___024root*>(voidSelf);
    Vsim_divider_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Verilated::mtaskId(15);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__12(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(18);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__15(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(19);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__16(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(25);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__22(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(16);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__13(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    Verilated::mtaskId(22);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__19(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_39.signalUpstreamDone(even_cycle);
    vlSelf->__Vm_mtaskstate_42.waitUntilUpstreamDone(even_cycle);
    Verilated::mtaskId(42);
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsim_divider_top___024root___nba_sequent__TOP__39(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    vlSelf->__Vm_mtaskstate_final__nba.signalUpstreamDone(even_cycle);
}
