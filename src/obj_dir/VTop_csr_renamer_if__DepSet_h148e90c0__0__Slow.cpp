// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_csr_renamer_if.h"

VL_ATTR_COLD void VTop_csr_renamer_if___ctor_var_reset(VTop_csr_renamer_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_csr_renamer_if___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->mideleg_rdata = 0;
    vlSelf->mip_rdata = 0;
    vlSelf->mie_rdata = 0;
    vlSelf->medeleg_rdata = 0;
    vlSelf->mstatus_rdata = 0;
    vlSelf->mepc_rdata = 0;
    vlSelf->mtvec_rdata = 0;
    vlSelf->mcounteren_rdata = 0;
    vlSelf->mcountinhibit_rdata = 0;
    vlSelf->minstret_rdata = 0;
    vlSelf->sie_rdata = 0;
    vlSelf->sip_rdata = 0;
    vlSelf->sstatus_rdata = 0;
    vlSelf->sepc_rdata = 0;
    vlSelf->stvec_rdata = 0;
    vlSelf->scounteren_rdata = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->pmpcfg_rdata[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->pmpaddr_rdata[__Vi0] = 0;
    }
    VL_ZERO_RESET_W(65, vlSelf->medeleg_w);
    VL_ZERO_RESET_W(65, vlSelf->mstatus_w);
    VL_ZERO_RESET_W(65, vlSelf->mepc_w);
    VL_ZERO_RESET_W(65, vlSelf->mtval_w);
    VL_ZERO_RESET_W(65, vlSelf->mcause_w);
    VL_ZERO_RESET_W(65, vlSelf->sstatus_w);
    VL_ZERO_RESET_W(65, vlSelf->sepc_w);
    VL_ZERO_RESET_W(65, vlSelf->stval_w);
    VL_ZERO_RESET_W(65, vlSelf->scause_w);
}
