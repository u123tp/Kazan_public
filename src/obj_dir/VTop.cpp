// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTop__pch.h"

//============================================================
// Constructors

VTop::VTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTop__Syms(contextp(), _vcname__, this)}
    , inv_dump_sig{vlSymsp->TOP.inv_dump_sig}
    , reset{vlSymsp->TOP.reset}
    , clock{vlSymsp->TOP.clock}
    , __PVT__MemoryLayout{vlSymsp->TOP.__PVT__MemoryLayout}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , __PVT__Top__DOT__csr_renamer_port{vlSymsp->TOP.__PVT__Top__DOT__csr_renamer_port}
    , __PVT__Top__DOT__csru_renamer_port{vlSymsp->TOP.__PVT__Top__DOT__csru_renamer_port}
    , __PVT__Top__DOT__renamer_lsu_port{vlSymsp->TOP.__PVT__Top__DOT__renamer_lsu_port}
    , __PVT__Top__DOT__csr_csru_port{vlSymsp->TOP.__PVT__Top__DOT__csr_csru_port}
    , __PVT__Top__DOT__csr_plic_port{vlSymsp->TOP.__PVT__Top__DOT__csr_plic_port}
    , __PVT__Top__DOT__csr_clint_port{vlSymsp->TOP.__PVT__Top__DOT__csr_clint_port}
    , __PVT__Top__DOT__dtlb_port{vlSymsp->TOP.__PVT__Top__DOT__dtlb_port}
    , __PVT__Top__DOT__itlb_port{vlSymsp->TOP.__PVT__Top__DOT__itlb_port}
    , __PVT__Top__DOT__mm_mmu_port{vlSymsp->TOP.__PVT__Top__DOT__mm_mmu_port}
    , __PVT__Top__DOT__mm_cachesubsystem_port{vlSymsp->TOP.__PVT__Top__DOT__mm_cachesubsystem_port}
    , __PVT__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util{vlSymsp->TOP.__PVT__Top__DOT__mmu__DOT__l2tlb__DOT__plru_util}
    , __PVT__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port{vlSymsp->TOP.__PVT__Top__DOT__cachesubsystem__DOT__icache__DOT__cb_port}
    , __PVT__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port{vlSymsp->TOP.__PVT__Top__DOT__cachesubsystem__DOT__dcache__DOT__cb_port}
    , __PVT__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port{vlSymsp->TOP.__PVT__Top__DOT__cachesubsystem__DOT__l2cache__DOT__cb_port}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTop::VTop(const char* _vcname__)
    : VTop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTop::~VTop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf);
#endif  // VL_DEBUG
void VTop___024root___eval_static(VTop___024root* vlSelf);
void VTop___024root___eval_initial(VTop___024root* vlSelf);
void VTop___024root___eval_settle(VTop___024root* vlSelf);
void VTop___024root___eval(VTop___024root* vlSelf);

void VTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTop___024root___eval_static(&(vlSymsp->TOP));
        VTop___024root___eval_initial(&(vlSymsp->TOP));
        VTop___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTop::eventsPending() { return false; }

uint64_t VTop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTop___024root___eval_final(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop::final() {
    VTop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTop::hierName() const { return vlSymsp->name(); }
const char* VTop::modelName() const { return "VTop"; }
unsigned VTop::threads() const { return 3; }
void VTop::prepareClone() const { contextp()->prepareClone(); }
void VTop::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}
