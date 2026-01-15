// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_MemoryLayout.h"
#include "VTop__Syms.h"

void VTop_MemoryLayout___ctor_var_reset(VTop_MemoryLayout* vlSelf);

VTop_MemoryLayout::VTop_MemoryLayout(VTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_MemoryLayout___ctor_var_reset(this);
}

void VTop_MemoryLayout::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTop_MemoryLayout::~VTop_MemoryLayout() {
}
