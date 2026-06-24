// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsim_divider_top__pch.h"

//============================================================
// Constructors

Vsim_divider_top::Vsim_divider_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsim_divider_top__Syms(contextp(), _vcname__, this)}
    , resp_value{vlSymsp->TOP.resp_value}
    , req_valid{vlSymsp->TOP.req_valid}
    , req_opcode{vlSymsp->TOP.req_opcode}
    , req_rs1{vlSymsp->TOP.req_rs1}
    , req_rs2{vlSymsp->TOP.req_rs2}
    , resp_valid{vlSymsp->TOP.resp_valid}
    , resp_opcode{vlSymsp->TOP.resp_opcode}
    , stall_out{vlSymsp->TOP.stall_out}
    , flush_in{vlSymsp->TOP.flush_in}
    , reset{vlSymsp->TOP.reset}
    , clock{vlSymsp->TOP.clock}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsim_divider_top::Vsim_divider_top(const char* _vcname__)
    : Vsim_divider_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsim_divider_top::~Vsim_divider_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsim_divider_top___024root___eval_debug_assertions(Vsim_divider_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vsim_divider_top___024root___eval_static(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___eval_initial(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___eval_settle(Vsim_divider_top___024root* vlSelf);
void Vsim_divider_top___024root___eval(Vsim_divider_top___024root* vlSelf);

void Vsim_divider_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsim_divider_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsim_divider_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsim_divider_top___024root___eval_static(&(vlSymsp->TOP));
        Vsim_divider_top___024root___eval_initial(&(vlSymsp->TOP));
        Vsim_divider_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsim_divider_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsim_divider_top::eventsPending() { return false; }

uint64_t Vsim_divider_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsim_divider_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsim_divider_top___024root___eval_final(Vsim_divider_top___024root* vlSelf);

VL_ATTR_COLD void Vsim_divider_top::final() {
    Vsim_divider_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsim_divider_top::hierName() const { return vlSymsp->name(); }
const char* Vsim_divider_top::modelName() const { return "Vsim_divider_top"; }
unsigned Vsim_divider_top::threads() const { return 2; }
void Vsim_divider_top::prepareClone() const { contextp()->prepareClone(); }
void Vsim_divider_top::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vsim_divider_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsim_divider_top::trace()' called on model that was Verilated without --trace option");
}
