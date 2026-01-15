// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VTop.h"

// INCLUDE MODULE CLASSES
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

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTop* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MULTI-THREADING
    VlThreadPool* __Vm_threadPoolp;
    bool __Vm_even_cycle__ico = false;
    bool __Vm_even_cycle__act = false;
    bool __Vm_even_cycle__nba = false;

    // MODULE INSTANCE STATE
    VTop___024root                 TOP;
    VTop_MemoryLayout              TOP__MemoryLayout;
    VTop_cache_cb_if__pi5          TOP__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port;
    VTop_cache_cb_if__pi5          TOP__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port;
    VTop_cache_cb_if__pi5          TOP__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port;
    VTop_csr_clint_if              TOP__Top__DOT__csr_clint_port;
    VTop_csr_csru_if               TOP__Top__DOT__csr_csru_port;
    VTop_csr_plic_if               TOP__Top__DOT__csr_plic_port;
    VTop_csr_renamer_if            TOP__Top__DOT__csr_renamer_port;
    VTop_csru_renamer_if           TOP__Top__DOT__csru_renamer_port;
    VTop_dtlb_if__N3_NB3           TOP__Top__DOT__dtlb_port;
    VTop_itlb_if__N4_NB4           TOP__Top__DOT__itlb_port;
    VTop_mm_if__N1_NB1             TOP__Top__DOT__mm_cachesubsystem_port;
    VTop_mm_if__N4_NB4             TOP__Top__DOT__mm_mmu_port;
    VTop_TREE_PLRU_FUNC__N8        TOP__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util;
    VTop_Renamer_LSU_if            TOP__Top__DOT__renamer_lsu_port;
    VTop___024unit                 TOP____024unit;

    // CONSTRUCTORS
    VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp);
    ~VTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
