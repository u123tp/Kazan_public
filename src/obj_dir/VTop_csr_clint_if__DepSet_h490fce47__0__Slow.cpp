// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_csr_clint_if.h"

VL_ATTR_COLD void VTop_csr_clint_if___ctor_var_reset(VTop_csr_clint_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_csr_clint_if___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->time_rdata = 0;
    vlSelf->mcountinhibit_rdata = 0;
    vlSelf->stimecmp_rdata = 0;
    vlSelf->menvcfg_rdata = 0;
    VL_ZERO_RESET_W(65, vlSelf->time_w);
    vlSelf->mip_stip = 0;
    vlSelf->mip_mtip = 0;
}
