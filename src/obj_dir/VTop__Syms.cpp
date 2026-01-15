// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop__pch.h"
#include "VTop.h"
#include "VTop___024root.h"
#include "VTop_csru_renamer_if.h"
#include "VTop_Renamer_LSU_if.h"
#include "VTop_csr_clint_if.h"
#include "VTop_csr_renamer_if.h"
#include "VTop_csr_csru_if.h"
#include "VTop_csr_plic_if.h"
#include "VTop_dtlb_if__N3_NB3.h"
#include "VTop_itlb_if__N4_NB4.h"
#include "VTop_mm_if__N4_NB4.h"
#include "VTop_mm_if__N1_NB1.h"
#include "VTop_MemoryLayout.h"
#include "VTop_TREE_PLRU_FUNC__N8.h"
#include "VTop_cache_cb_if__pi5.h"
#include "VTop___024unit.h"

// FUNCTIONS
VTop__Syms::~VTop__Syms()
{
}

VTop__Syms::VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_threadPoolp{static_cast<VlThreadPool*>(contextp->threadPoolp())}
    // Setup module instances
    , TOP{this, namep}
    , TOP__MemoryLayout{this, Verilated::catName(namep, "MemoryLayout")}
    , TOP__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port{this, Verilated::catName(namep, "Top.cachesubsystem.dcache.cb_port")}
    , TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port{this, Verilated::catName(namep, "Top.cachesubsystem.icache.cb_port")}
    , TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port{this, Verilated::catName(namep, "Top.cachesubsystem.l2cache.cb_port")}
    , TOP__Top__DOT__csr_clint_port{this, Verilated::catName(namep, "Top.csr_clint_port")}
    , TOP__Top__DOT__csr_csru_port{this, Verilated::catName(namep, "Top.csr_csru_port")}
    , TOP__Top__DOT__csr_plic_port{this, Verilated::catName(namep, "Top.csr_plic_port")}
    , TOP__Top__DOT__csr_renamer_port{this, Verilated::catName(namep, "Top.csr_renamer_port")}
    , TOP__Top__DOT__csru_renamer_port{this, Verilated::catName(namep, "Top.csru_renamer_port")}
    , TOP__Top__DOT__dtlb_port{this, Verilated::catName(namep, "Top.dtlb_port")}
    , TOP__Top__DOT__itlb_port{this, Verilated::catName(namep, "Top.itlb_port")}
    , TOP__Top__DOT__mm_cachesubsystem_port{this, Verilated::catName(namep, "Top.mm_cachesubsystem_port")}
    , TOP__Top__DOT__mm_mmu_port{this, Verilated::catName(namep, "Top.mm_mmu_port")}
    , TOP__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util{this, Verilated::catName(namep, "Top.mmu.l2tlb.plru_util")}
    , TOP__Top__DOT__renamer_lsu_port{this, Verilated::catName(namep, "Top.renamer_lsu_port")}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
        // Check resources
        Verilated::stackCheck(85318);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__MemoryLayout = &TOP__MemoryLayout;
    TOP.__PVT__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port = &TOP__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port;
    TOP.__PVT__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port = &TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port;
    TOP.__PVT__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port = &TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port;
    TOP.__PVT__Top__DOT__csr_clint_port = &TOP__Top__DOT__csr_clint_port;
    TOP.__PVT__Top__DOT__csr_csru_port = &TOP__Top__DOT__csr_csru_port;
    TOP.__PVT__Top__DOT__csr_plic_port = &TOP__Top__DOT__csr_plic_port;
    TOP.__PVT__Top__DOT__csr_renamer_port = &TOP__Top__DOT__csr_renamer_port;
    TOP.__PVT__Top__DOT__csru_renamer_port = &TOP__Top__DOT__csru_renamer_port;
    TOP.__PVT__Top__DOT__dtlb_port = &TOP__Top__DOT__dtlb_port;
    TOP.__PVT__Top__DOT__itlb_port = &TOP__Top__DOT__itlb_port;
    TOP.__PVT__Top__DOT__mm_cachesubsystem_port = &TOP__Top__DOT__mm_cachesubsystem_port;
    TOP.__PVT__Top__DOT__mm_mmu_port = &TOP__Top__DOT__mm_mmu_port;
    TOP.__PVT__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util = &TOP__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util;
    TOP.__PVT__Top__DOT__renamer_lsu_port = &TOP__Top__DOT__renamer_lsu_port;
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__MemoryLayout.__Vconfigure(true);
    TOP__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port.__Vconfigure(true);
    TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port.__Vconfigure(false);
    TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port.__Vconfigure(false);
    TOP__Top__DOT__csr_clint_port.__Vconfigure(true);
    TOP__Top__DOT__csr_csru_port.__Vconfigure(true);
    TOP__Top__DOT__csr_plic_port.__Vconfigure(true);
    TOP__Top__DOT__csr_renamer_port.__Vconfigure(true);
    TOP__Top__DOT__csru_renamer_port.__Vconfigure(true);
    TOP__Top__DOT__dtlb_port.__Vconfigure(true);
    TOP__Top__DOT__itlb_port.__Vconfigure(true);
    TOP__Top__DOT__mm_cachesubsystem_port.__Vconfigure(true);
    TOP__Top__DOT__mm_mmu_port.__Vconfigure(true);
    TOP__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util.__Vconfigure(true);
    TOP__Top__DOT__renamer_lsu_port.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
