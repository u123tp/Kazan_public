// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
#include "svdpi.h"

class VTop__Syms;
class VTop___024root;
class VTop_MemoryLayout;
class VTop_Renamer_LSU_if;
class VTop_TREE_PLRU_FUNC__N8;
class VTop___024unit;
class VTop_cache_cb_if__pi5;
class VTop_csr_clint_if;
class VTop_csr_csru_if;
class VTop_csr_plic_if;
class VTop_csr_renamer_if;
class VTop_csru_renamer_if;
class VTop_dtlb_if__N3_NB3;
class VTop_itlb_if__N4_NB4;
class VTop_mm_if__N1_NB1;
class VTop_mm_if__N4_NB4;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VTop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VTop__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&inv_dump_sig,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&clock,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    VTop_MemoryLayout* const __PVT__MemoryLayout;
    VTop___024unit* const __PVT____024unit;
    VTop_csr_renamer_if* const __PVT__Top__DOT__csr_renamer_port;
    VTop_csru_renamer_if* const __PVT__Top__DOT__csru_renamer_port;
    VTop_Renamer_LSU_if* const __PVT__Top__DOT__renamer_lsu_port;
    VTop_csr_csru_if* const __PVT__Top__DOT__csr_csru_port;
    VTop_csr_plic_if* const __PVT__Top__DOT__csr_plic_port;
    VTop_csr_clint_if* const __PVT__Top__DOT__csr_clint_port;
    VTop_dtlb_if__N3_NB3* const __PVT__Top__DOT__dtlb_port;
    VTop_itlb_if__N4_NB4* const __PVT__Top__DOT__itlb_port;
    VTop_mm_if__N4_NB4* const __PVT__Top__DOT__mm_mmu_port;
    VTop_mm_if__N1_NB1* const __PVT__Top__DOT__mm_cachesubsystem_port;
    VTop_TREE_PLRU_FUNC__N8* const __PVT__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util;
    VTop_cache_cb_if__pi5* const __PVT__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port;
    VTop_cache_cb_if__pi5* const __PVT__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port;
    VTop_cache_cb_if__pi5* const __PVT__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VTop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VTop(VerilatedContext* contextp, const char* name = "TOP");
    explicit VTop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VTop();
  private:
    VL_UNCOPYABLE(VTop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
