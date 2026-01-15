// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop_csr_plic_if.h"

void VTop_csr_plic_if___ctor_var_reset(VTop_csr_plic_if* vlSelf);

VTop_csr_plic_if::VTop_csr_plic_if(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_csr_plic_if___ctor_var_reset(this);
}

void VTop_csr_plic_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_csr_plic_if::~VTop_csr_plic_if() {
}
