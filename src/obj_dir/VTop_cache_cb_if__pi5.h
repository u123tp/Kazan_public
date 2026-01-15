// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP_CACHE_CB_IF__PI5_H_
#define VERILATED_VTOP_CACHE_CB_IF__PI5_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop_cache_cb_if__pi5 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    SData/*8:0*/ invalidate_req;
    SData/*11:0*/ invalidate_get_info_req;
    VlWide<3>/*65:0*/ allocate_req;
    VlUnpacked<VlWide<11>/*330:0*/, 2> read_req;
    VlUnpacked<VlWide<11>/*330:0*/, 1> write_req;
    QData/*63:0*/ allocate_res;
    QData/*61:0*/ invalidate_get_info_res;
    VlUnpacked<VlWide<11>/*330:0*/, 3> res_to_tmb;
    VlUnpacked<VlWide<9>/*267:0*/, 2> res_to_wbb;
    VlUnpacked<VlWide<11>/*330:0*/, 3> res_to_mshr;
    VlUnpacked<QData/*62:0*/, 3> mshr_new_state;
    VlUnpacked<VlWide<9>/*267:0*/, 2> res_out;
    VlUnpacked<QData/*57:0*/, 8> mshr_processing_info;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_cache_cb_if__pi5(VTop__Syms* symsp, const char* v__name);
    ~VTop_cache_cb_if__pi5();
    VL_UNCOPYABLE(VTop_cache_cb_if__pi5);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const VTop_cache_cb_if__pi5* obj);

#endif  // guard
