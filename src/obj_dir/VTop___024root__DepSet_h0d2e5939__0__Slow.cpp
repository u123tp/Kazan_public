// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP__0(VTop___024root* vlSelf);
VL_ATTR_COLD void VTop___024root___eval_initial__TOP__1(VTop___024root* vlSelf);
extern const VlWide<8>/*255:0*/ VTop__ConstPool__CONST_h1e479923_0;
extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_h9abed4c7_0;
extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_hd834ace5_0;
extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_ha0532d57_0;
extern const VlWide<9>/*287:0*/ VTop__ConstPool__CONST_he57c5f75_0;
extern const VlWide<10>/*319:0*/ VTop__ConstPool__CONST_ha6b81edf_0;
extern const VlWide<10>/*319:0*/ VTop__ConstPool__CONST_h360917e9_0;
extern const VlWide<8>/*255:0*/ VTop__ConstPool__CONST_hc34b18f8_0;

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ Top__DOT__pcgen__DOT__fp;
    Top__DOT__pcgen__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__ifqueue__DOT__fp;
    Top__DOT__ifqueue__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__decoder__DOT__fp;
    Top__DOT__decoder__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__mmu__DOT__gen_pw__BRA__0__KET____DOT__pw__DOT__fp;
    Top__DOT__mmu__DOT__gen_pw__BRA__0__KET____DOT__pw__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__mmu__DOT__gen_pw__BRA__1__KET____DOT__pw__DOT__fp;
    Top__DOT__mmu__DOT__gen_pw__BRA__1__KET____DOT__pw__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__mmu__DOT__gen_pw__BRA__2__KET____DOT__pw__DOT__fp;
    Top__DOT__mmu__DOT__gen_pw__BRA__2__KET____DOT__pw__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__mmu__DOT__gen_pw__BRA__3__KET____DOT__pw__DOT__fp;
    Top__DOT__mmu__DOT__gen_pw__BRA__3__KET____DOT__pw__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__icache__DOT__fp_write_back_dump;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_write_back_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__icache__DOT__fp_invalidate_dump;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_invalidate_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__icache__DOT__fp_res_out;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_res_out = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__icache__DOT__fp_req_in;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_req_in = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_write_back_dump;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_write_back_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_invalidate_dump;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_invalidate_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_res_out;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_res_out = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_req_in;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_req_in = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_write_back_dump;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_write_back_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_invalidate_dump;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_invalidate_dump = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_res_out;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_res_out = 0;
    IData/*31:0*/ Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_req_in;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_req_in = 0;
    IData/*31:0*/ Top__DOT__csrrf__DOT__fp;
    Top__DOT__csrrf__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__plic__DOT__ud__DOT__fp;
    Top__DOT__plic__DOT__ud__DOT__fp = 0;
    IData/*31:0*/ Top__DOT__mm__DOT__unnamedblk1__DOT__i;
    Top__DOT__mm__DOT__unnamedblk1__DOT__i = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<5>/*159:0*/ __Vtemp_3;
    VlWide<7>/*223:0*/ __Vtemp_4;
    VlWide<7>/*223:0*/ __Vtemp_5;
    VlWide<7>/*223:0*/ __Vtemp_6;
    VlWide<7>/*223:0*/ __Vtemp_7;
    VlWide<7>/*223:0*/ __Vtemp_8;
    VlWide<5>/*159:0*/ __Vtemp_9;
    VlWide<7>/*223:0*/ __Vtemp_10;
    VlWide<6>/*191:0*/ __Vtemp_11;
    // Body
    VTop___024root___eval_initial__TOP__0(vlSelf);
    VTop___024root___eval_initial__TOP__1(vlSelf);
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][0U] 
        = VTop__ConstPool__CONST_h1e479923_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][1U] 
        = VTop__ConstPool__CONST_h1e479923_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][2U] 
        = VTop__ConstPool__CONST_h1e479923_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][3U] 
        = VTop__ConstPool__CONST_h1e479923_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][4U] 
        = VTop__ConstPool__CONST_h1e479923_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][5U] 
        = VTop__ConstPool__CONST_h1e479923_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][6U] 
        = VTop__ConstPool__CONST_h1e479923_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT____Vcellinp__l2cache__res_from_tlb[0U][7U] 
        = VTop__ConstPool__CONST_h1e479923_0[7U];
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x6e6c6f67U;
    __Vtemp_1[2U] = 0x70636765U;
    __Vtemp_1[3U] = 0x6c6f672fU;
    __Vtemp_1[4U] = 0x2e2fU;
    Top__DOT__pcgen__DOT__fp = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                                           , std::string{"w"});
    ;
    __Vtemp_2[0U] = 0x2e747874U;
    __Vtemp_2[1U] = 0x716c6f67U;
    __Vtemp_2[2U] = 0x672f6966U;
    __Vtemp_2[3U] = 0x2e2f6c6fU;
    Top__DOT__ifqueue__DOT__fp = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(4, __Vtemp_2)
                                             , std::string{"w"});
    ;
    __Vtemp_3[0U] = 0x2e747874U;
    __Vtemp_3[1U] = 0x726c6f67U;
    __Vtemp_3[2U] = 0x636f6465U;
    __Vtemp_3[3U] = 0x672f6465U;
    __Vtemp_3[4U] = 0x2e2f6c6fU;
    Top__DOT__decoder__DOT__fp = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_3)
                                             , std::string{"w"});
    ;
    Top__DOT__mmu__DOT__gen_pw__BRA__0__KET____DOT__pw__DOT__fp 
        = VL_FOPEN_NN(std::string{"./log/pwlog0.txt"}
                      , std::string{"w"});
    ;
    Top__DOT__mmu__DOT__gen_pw__BRA__1__KET____DOT__pw__DOT__fp 
        = VL_FOPEN_NN(std::string{"./log/pwlog1.txt"}
                      , std::string{"w"});
    ;
    Top__DOT__mmu__DOT__gen_pw__BRA__2__KET____DOT__pw__DOT__fp 
        = VL_FOPEN_NN(std::string{"./log/pwlog2.txt"}
                      , std::string{"w"});
    ;
    Top__DOT__mmu__DOT__gen_pw__BRA__3__KET____DOT__pw__DOT__fp 
        = VL_FOPEN_NN(std::string{"./log/pwlog3.txt"}
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_write_back_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(9, VTop__ConstPool__CONST_h9abed4c7_0)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_invalidate_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(9, VTop__ConstPool__CONST_hd834ace5_0)
                      , std::string{"w"});
    ;
    __Vtemp_4[0U] = 0x2e747874U;
    __Vtemp_4[1U] = 0x5f6f7574U;
    __Vtemp_4[2U] = 0x5f726573U;
    __Vtemp_4[3U] = 0x61636865U;
    __Vtemp_4[4U] = 0x675f6963U;
    __Vtemp_4[5U] = 0x672f6c6fU;
    __Vtemp_4[6U] = 0x2e2f6c6fU;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_res_out 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_4)
                      , std::string{"w"});
    ;
    __Vtemp_5[0U] = 0x2e747874U;
    __Vtemp_5[1U] = 0x715f696eU;
    __Vtemp_5[2U] = 0x655f7265U;
    __Vtemp_5[3U] = 0x63616368U;
    __Vtemp_5[4U] = 0x6f675f69U;
    __Vtemp_5[5U] = 0x6f672f6cU;
    __Vtemp_5[6U] = 0x2e2f6cU;
    Top__DOT__cachesubsystem__DOT__icache__DOT__fp_req_in 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_5)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_write_back_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(9, VTop__ConstPool__CONST_ha0532d57_0)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_invalidate_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(9, VTop__ConstPool__CONST_he57c5f75_0)
                      , std::string{"w"});
    ;
    __Vtemp_6[0U] = 0x2e747874U;
    __Vtemp_6[1U] = 0x5f6f7574U;
    __Vtemp_6[2U] = 0x5f726573U;
    __Vtemp_6[3U] = 0x61636865U;
    __Vtemp_6[4U] = 0x675f6463U;
    __Vtemp_6[5U] = 0x672f6c6fU;
    __Vtemp_6[6U] = 0x2e2f6c6fU;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_res_out 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_6)
                      , std::string{"w"});
    ;
    __Vtemp_7[0U] = 0x2e747874U;
    __Vtemp_7[1U] = 0x715f696eU;
    __Vtemp_7[2U] = 0x655f7265U;
    __Vtemp_7[3U] = 0x63616368U;
    __Vtemp_7[4U] = 0x6f675f64U;
    __Vtemp_7[5U] = 0x6f672f6cU;
    __Vtemp_7[6U] = 0x2e2f6cU;
    Top__DOT__cachesubsystem__DOT__dcache__DOT__fp_req_in 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_7)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_write_back_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(10, VTop__ConstPool__CONST_ha6b81edf_0)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_invalidate_dump 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(10, VTop__ConstPool__CONST_h360917e9_0)
                      , std::string{"w"});
    ;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_res_out 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(8, VTop__ConstPool__CONST_hc34b18f8_0)
                      , std::string{"w"});
    ;
    __Vtemp_8[0U] = 0x2e747874U;
    __Vtemp_8[1U] = 0x715f696eU;
    __Vtemp_8[2U] = 0x655f7265U;
    __Vtemp_8[3U] = 0x63616368U;
    __Vtemp_8[4U] = 0x675f6c32U;
    __Vtemp_8[5U] = 0x672f6c6fU;
    __Vtemp_8[6U] = 0x2e2f6c6fU;
    Top__DOT__cachesubsystem__DOT__l2cache__DOT__fp_req_in 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(7, __Vtemp_8)
                      , std::string{"w"});
    ;
    __Vtemp_9[0U] = 0x2e747874U;
    __Vtemp_9[1U] = 0x666c6f67U;
    __Vtemp_9[2U] = 0x63737272U;
    __Vtemp_9[3U] = 0x6c6f672fU;
    __Vtemp_9[4U] = 0x2e2fU;
    Top__DOT__csrrf__DOT__fp = VL_FOPEN_MCD_N(VL_CVT_PACK_STR_NW(5, __Vtemp_9));
    ;
    __Vtemp_10[0U] = 0x2e747874U;
    __Vtemp_10[1U] = 0x5f6c6f67U;
    __Vtemp_10[2U] = 0x76696365U;
    __Vtemp_10[3U] = 0x745f6465U;
    __Vtemp_10[4U] = 0x2f756172U;
    __Vtemp_10[5U] = 0x2f6c6f67U;
    __Vtemp_10[6U] = 0x2eU;
    Top__DOT__plic__DOT__ud__DOT__fp = VL_FOPEN_NN(
                                                   VL_CVT_PACK_STR_NW(7, __Vtemp_10)
                                                   , 
                                                   std::string{"w"});
    ;
    __Vtemp_11[0U] = 0x2e686578U;
    __Vtemp_11[1U] = 0x726e656cU;
    __Vtemp_11[2U] = 0x782f6b65U;
    __Vtemp_11[3U] = 0x6c2f6865U;
    __Vtemp_11[4U] = 0x65726e65U;
    __Vtemp_11[5U] = 0x2e2e2f6bU;
    VL_READMEM_N(true, 32, 4194304, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_11)
                 ,  &(vlSelfRef.Top__DOT__mm__DOT__mem_tmp)
                 , 0, ~0ULL);
    Top__DOT__mm__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x100000U > Top__DOT__mm__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.Top__DOT__mm__DOT__mem[(0xfffffU 
                                          & Top__DOT__mm__DOT__unnamedblk1__DOT__i)][0U] 
            = vlSelfRef.Top__DOT__mm__DOT__mem_tmp[
            (0x3fffffU & VL_SHIFTL_III(22,32,32, Top__DOT__mm__DOT__unnamedblk1__DOT__i, 2U))];
        vlSelfRef.Top__DOT__mm__DOT__mem[(0xfffffU 
                                          & Top__DOT__mm__DOT__unnamedblk1__DOT__i)][1U] 
            = vlSelfRef.Top__DOT__mm__DOT__mem_tmp[
            (0x3fffffU & ((IData)(1U) + VL_SHIFTL_III(22,32,32, Top__DOT__mm__DOT__unnamedblk1__DOT__i, 2U)))];
        vlSelfRef.Top__DOT__mm__DOT__mem[(0xfffffU 
                                          & Top__DOT__mm__DOT__unnamedblk1__DOT__i)][2U] 
            = vlSelfRef.Top__DOT__mm__DOT__mem_tmp[
            (0x3fffffU & ((IData)(2U) + VL_SHIFTL_III(22,32,32, Top__DOT__mm__DOT__unnamedblk1__DOT__i, 2U)))];
        vlSelfRef.Top__DOT__mm__DOT__mem[(0xfffffU 
                                          & Top__DOT__mm__DOT__unnamedblk1__DOT__i)][3U] 
            = vlSelfRef.Top__DOT__mm__DOT__mem_tmp[
            (0x3fffffU & ((IData)(3U) + VL_SHIFTL_III(22,32,32, Top__DOT__mm__DOT__unnamedblk1__DOT__i, 2U)))];
        Top__DOT__mm__DOT__unnamedblk1__DOT__i = ((IData)(1U) 
                                                  + Top__DOT__mm__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP__0(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP__0\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i;
    Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8531__Vfuncout;
    __Vfunc_internal_idx__8531__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8531__csr_name;
    __Vfunc_internal_idx__8531__csr_name = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8532__Vfuncout;
    __Vfunc_internal_idx__8532__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8532__csr_name;
    __Vfunc_internal_idx__8532__csr_name = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8533__Vfuncout;
    __Vfunc_internal_idx__8533__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8533__csr_name;
    __Vfunc_internal_idx__8533__csr_name = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8534__Vfuncout;
    __Vfunc_internal_idx__8534__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8534__csr_name;
    __Vfunc_internal_idx__8534__csr_name = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8535__Vfuncout;
    __Vfunc_internal_idx__8535__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8535__csr_name;
    __Vfunc_internal_idx__8535__csr_name = 0;
    CData/*7:0*/ __Vfunc_internal_idx__8536__Vfuncout;
    __Vfunc_internal_idx__8536__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_internal_idx__8536__csr_name;
    __Vfunc_internal_idx__8536__csr_name = 0;
    // Body
    vlSelfRef.Top__DOT__btb__DOT__btb_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__btb__DOT__btb_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__btb__DOT__btb_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__btb__DOT__btb_r_en[3U] = 1U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0U] = 0U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[1U] = 1U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[2U] = 2U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[3U] = 3U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[4U] = 4U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[5U] = 5U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[6U] = 6U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[7U] = 7U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[8U] = 8U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[9U] = 9U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xaU] = 0xaU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xbU] = 0xbU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xcU] = 0xcU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xdU] = 0xdU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xeU] = 0xeU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0xfU] = 0xfU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x10U] = 0x10U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x11U] = 0x11U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x12U] = 0x12U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x13U] = 0x13U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x14U] = 0x14U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x15U] = 0x15U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x16U] = 0x16U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x17U] = 0x17U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x18U] = 0x18U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x19U] = 0x19U;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1aU] = 0x1aU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1bU] = 0x1bU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1cU] = 0x1cU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1dU] = 0x1dU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1eU] = 0x1eU;
    vlSelfRef.Top__DOT__renamer__DOT__rat_init[0x1fU] = 0x1fU;
    Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x60U > Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i)) {
        if ((0x20U > Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i)) {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hfb81767b__0 = 0U;
            if (VL_LIKELY(((0x5fU >= (0x7fU & Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i))))) {
                vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_init[(0x7fU 
                                                                          & Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i)] 
                    = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hfb81767b__0;
            }
        } else {
            vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hfb81767b__1 = 1U;
            if (VL_LIKELY(((0x5fU >= (0x7fU & Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i))))) {
                vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT__fl_init[(0x7fU 
                                                                          & Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i)] 
                    = vlSelfRef.Top__DOT__renamer__DOT__freelist__DOT____Vlvbound_hfb81767b__1;
            }
        }
        Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + Top__DOT__renamer__DOT__freelist__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[0U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[1U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[2U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[3U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[4U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[5U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_w_mask[6U] = 0xffU;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[3U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[4U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[5U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[6U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[7U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[8U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[9U] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[0xaU] = 1U;
    vlSelfRef.Top__DOT__intprf__DOT__phyreg_r_en[0xbU] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[3U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_data_r_en[3U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[3U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1itlb__DOT__tlb_info_r_en[3U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_data_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[2U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l1dtlb__DOT__tlb_info_r_en[2U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_data_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en[0U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en[1U] = 0U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en[0U] = 1U;
    vlSelfRef.Top__DOT__mmu__DOT__l2tlb__DOT__tlb_info_r_en[1U] = 1U;
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][0U] 
        = VTop__ConstPool__CONST_h1e479923_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][1U] 
        = VTop__ConstPool__CONST_h1e479923_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][2U] 
        = VTop__ConstPool__CONST_h1e479923_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][3U] 
        = VTop__ConstPool__CONST_h1e479923_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][4U] 
        = VTop__ConstPool__CONST_h1e479923_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][5U] 
        = VTop__ConstPool__CONST_h1e479923_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][6U] 
        = VTop__ConstPool__CONST_h1e479923_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[0U][7U] 
        = VTop__ConstPool__CONST_h1e479923_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][0U] 
        = VTop__ConstPool__CONST_h1e479923_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][1U] 
        = VTop__ConstPool__CONST_h1e479923_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][2U] 
        = VTop__ConstPool__CONST_h1e479923_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][3U] 
        = VTop__ConstPool__CONST_h1e479923_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][4U] 
        = VTop__ConstPool__CONST_h1e479923_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][5U] 
        = VTop__ConstPool__CONST_h1e479923_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][6U] 
        = VTop__ConstPool__CONST_h1e479923_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[1U][7U] 
        = VTop__ConstPool__CONST_h1e479923_0[7U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][0U] 
        = VTop__ConstPool__CONST_h1e479923_0[0U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][1U] 
        = VTop__ConstPool__CONST_h1e479923_0[1U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][2U] 
        = VTop__ConstPool__CONST_h1e479923_0[2U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][3U] 
        = VTop__ConstPool__CONST_h1e479923_0[3U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][4U] 
        = VTop__ConstPool__CONST_h1e479923_0[4U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][5U] 
        = VTop__ConstPool__CONST_h1e479923_0[5U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][6U] 
        = VTop__ConstPool__CONST_h1e479923_0[6U];
    vlSelfRef.Top__DOT__cachesubsystem__DOT__res_from_dtlb_dummy[2U][7U] 
        = VTop__ConstPool__CONST_h1e479923_0[7U];
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0xffU)) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[__Vilp1] = 0ULL;
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8531__csr_name = 0x301U;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x43U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x42U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x41U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x40U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x3fU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x38U;
                                        goto __Vlabel372;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 7U;
                                    goto __Vlabel372;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 9U;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 8U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xc2U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xc1U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xc0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbfU;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbeU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbdU;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xbcU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xbbU;
                                    goto __Vlabel372;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbaU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb9U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb8U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb7U;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb6U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb5U;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xb4U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xb3U;
                                goto __Vlabel372;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb2U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb1U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xafU;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xaeU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xadU;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xacU;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xabU;
                                goto __Vlabel372;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xaaU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa9U;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xa8U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xa7U;
                                goto __Vlabel372;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xa6U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xa5U;
                                goto __Vlabel372;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xeU;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xa4U;
                            goto __Vlabel372;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xc2U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xc1U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xc0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xbfU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xbeU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xbdU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbcU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xbbU;
                                        goto __Vlabel372;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xbaU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xb9U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb8U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb7U;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb6U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb5U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb4U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xb3U;
                                    goto __Vlabel372;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xb2U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xb1U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xb0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xafU;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xaeU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xadU;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xacU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xabU;
                                    goto __Vlabel372;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xaaU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xa9U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa8U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa7U;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa6U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa5U;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xa4U;
                                goto __Vlabel372;
                            }
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xe9U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xe8U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xe7U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xe6U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xe5U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xe4U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xe3U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xe2U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xe1U;
                                        goto __Vlabel372;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x53U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xa3U;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xa2U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa1U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xa0U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x3aU;
                                        goto __Vlabel372;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x9bU;
                                                    goto __Vlabel372;
                                                } else {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x9aU;
                                                    goto __Vlabel372;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x99U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x98U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x97U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x96U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x95U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x94U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x93U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x92U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x91U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x90U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x8fU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x8eU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x8dU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x8cU;
                                        goto __Vlabel372;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x8bU;
                                                    goto __Vlabel372;
                                                } else {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x8aU;
                                                    goto __Vlabel372;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x89U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x88U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x87U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x86U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x85U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x84U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x83U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x82U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x81U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x80U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x7fU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x7eU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x7dU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x7cU;
                                        goto __Vlabel372;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x7bU;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x7aU;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x79U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x78U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x77U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x76U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x75U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x74U;
                                        goto __Vlabel372;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x73U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x72U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x71U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x70U;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x6fU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x6eU;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x6dU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x6cU;
                                    goto __Vlabel372;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x6bU;
                                                    goto __Vlabel372;
                                                } else {
                                                    __Vfunc_internal_idx__8531__Vfuncout = 0x6aU;
                                                    goto __Vlabel372;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x69U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x68U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x67U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x66U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x65U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x64U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x63U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x62U;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x61U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x60U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x5fU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x5eU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x5dU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x5cU;
                                        goto __Vlabel372;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0x5bU;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x5aU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x59U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x58U;
                                        goto __Vlabel372;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0x57U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x56U;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x55U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x54U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x51U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x50U;
                                        goto __Vlabel372;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x4fU;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x4eU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x4dU;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x4cU;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x4bU;
                                goto __Vlabel372;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xe0U;
                                                goto __Vlabel372;
                                            } else {
                                                __Vfunc_internal_idx__8531__Vfuncout = 0xdfU;
                                                goto __Vlabel372;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xdeU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xddU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xdcU;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xdbU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xdaU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xd9U;
                                        goto __Vlabel372;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xd8U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xd7U;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xd6U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xd5U;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xd4U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xd3U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xd2U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xd1U;
                                    goto __Vlabel372;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xd0U;
                                            goto __Vlabel372;
                                        } else {
                                            __Vfunc_internal_idx__8531__Vfuncout = 0xcfU;
                                            goto __Vlabel372;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xceU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xcdU;
                                        goto __Vlabel372;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xccU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xcbU;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xcaU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xc9U;
                                    goto __Vlabel372;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xc8U;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0xc7U;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xc6U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xc5U;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xc4U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xc3U;
                                goto __Vlabel372;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x9fU;
                                        goto __Vlabel372;
                                    } else {
                                        __Vfunc_internal_idx__8531__Vfuncout = 0x9eU;
                                        goto __Vlabel372;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x9dU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x9cU;
                                    goto __Vlabel372;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x52U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x4aU;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x49U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x48U;
                                goto __Vlabel372;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x47U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x46U;
                                goto __Vlabel372;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x45U;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x44U;
                            goto __Vlabel372;
                        }
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x39U;
                            goto __Vlabel372;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xeaU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                    goto __Vlabel372;
                                }
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x4fU;
                                goto __Vlabel372;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x36U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x35U;
                                goto __Vlabel372;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x34U;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x33U;
                            goto __Vlabel372;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xc3U;
                            goto __Vlabel372;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x3eU;
                                    goto __Vlabel372;
                                } else {
                                    __Vfunc_internal_idx__8531__Vfuncout = 0x3dU;
                                    goto __Vlabel372;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x3cU;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x3bU;
                                goto __Vlabel372;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x31U;
                                goto __Vlabel372;
                            }
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0x30U;
                                goto __Vlabel372;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x2fU;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0x48U;
                            goto __Vlabel372;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 0x44U;
                        goto __Vlabel372;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                    goto __Vlabel372;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                    goto __Vlabel372;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                    goto __Vlabel372;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xcU;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xbU;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xaU;
                        goto __Vlabel372;
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                        goto __Vlabel372;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                                __Vfunc_internal_idx__8531__Vfuncout = 6U;
                                goto __Vlabel372;
                            } else {
                                __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                                goto __Vlabel372;
                            }
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                            __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                            goto __Vlabel372;
                        } else {
                            __Vfunc_internal_idx__8531__Vfuncout = 5U;
                            goto __Vlabel372;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 4U;
                        goto __Vlabel372;
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 3U;
                        goto __Vlabel372;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                    goto __Vlabel372;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                        __Vfunc_internal_idx__8531__Vfuncout = 2U;
                        goto __Vlabel372;
                    } else {
                        __Vfunc_internal_idx__8531__Vfuncout = 1U;
                        goto __Vlabel372;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8531__csr_name))) {
                    __Vfunc_internal_idx__8531__Vfuncout = 0U;
                    goto __Vlabel372;
                } else {
                    __Vfunc_internal_idx__8531__Vfuncout = 0xf0U;
                    goto __Vlabel372;
                }
                __Vlabel372: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8531__Vfuncout))] = 0x8000000000001001ULL;
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8532__csr_name = 0x300U;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x43U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x42U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x41U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x40U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x3fU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x38U;
                                        goto __Vlabel373;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 7U;
                                    goto __Vlabel373;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 9U;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 8U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xc2U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xc1U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xc0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbfU;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbeU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbdU;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xbcU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xbbU;
                                    goto __Vlabel373;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbaU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb9U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb8U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb7U;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb6U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb5U;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xb4U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xb3U;
                                goto __Vlabel373;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb2U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb1U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xafU;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xaeU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xadU;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xacU;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xabU;
                                goto __Vlabel373;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xaaU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa9U;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xa8U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xa7U;
                                goto __Vlabel373;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xa6U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xa5U;
                                goto __Vlabel373;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xeU;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xa4U;
                            goto __Vlabel373;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xc2U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xc1U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xc0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xbfU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xbeU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xbdU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbcU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xbbU;
                                        goto __Vlabel373;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xbaU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xb9U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb8U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb7U;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb6U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb5U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb4U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xb3U;
                                    goto __Vlabel373;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xb2U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xb1U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xb0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xafU;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xaeU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xadU;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xacU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xabU;
                                    goto __Vlabel373;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xaaU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xa9U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa8U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa7U;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa6U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa5U;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xa4U;
                                goto __Vlabel373;
                            }
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xe9U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xe8U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xe7U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xe6U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xe5U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xe4U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xe3U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xe2U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xe1U;
                                        goto __Vlabel373;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x53U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xa3U;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xa2U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa1U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xa0U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x3aU;
                                        goto __Vlabel373;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x9bU;
                                                    goto __Vlabel373;
                                                } else {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x9aU;
                                                    goto __Vlabel373;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x99U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x98U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x97U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x96U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x95U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x94U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x93U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x92U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x91U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x90U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x8fU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x8eU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x8dU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x8cU;
                                        goto __Vlabel373;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x8bU;
                                                    goto __Vlabel373;
                                                } else {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x8aU;
                                                    goto __Vlabel373;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x89U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x88U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x87U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x86U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x85U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x84U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x83U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x82U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x81U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x80U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x7fU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x7eU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x7dU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x7cU;
                                        goto __Vlabel373;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x7bU;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x7aU;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x79U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x78U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x77U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x76U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x75U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x74U;
                                        goto __Vlabel373;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x73U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x72U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x71U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x70U;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x6fU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x6eU;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x6dU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x6cU;
                                    goto __Vlabel373;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x6bU;
                                                    goto __Vlabel373;
                                                } else {
                                                    __Vfunc_internal_idx__8532__Vfuncout = 0x6aU;
                                                    goto __Vlabel373;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x69U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x68U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x67U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x66U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x65U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x64U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x63U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x62U;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x61U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x60U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x5fU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x5eU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x5dU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x5cU;
                                        goto __Vlabel373;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0x5bU;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x5aU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x59U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x58U;
                                        goto __Vlabel373;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0x57U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x56U;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x55U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x54U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x51U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x50U;
                                        goto __Vlabel373;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x4fU;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x4eU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x4dU;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x4cU;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x4bU;
                                goto __Vlabel373;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xe0U;
                                                goto __Vlabel373;
                                            } else {
                                                __Vfunc_internal_idx__8532__Vfuncout = 0xdfU;
                                                goto __Vlabel373;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xdeU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xddU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xdcU;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xdbU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xdaU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xd9U;
                                        goto __Vlabel373;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xd8U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xd7U;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xd6U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xd5U;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xd4U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xd3U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xd2U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xd1U;
                                    goto __Vlabel373;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xd0U;
                                            goto __Vlabel373;
                                        } else {
                                            __Vfunc_internal_idx__8532__Vfuncout = 0xcfU;
                                            goto __Vlabel373;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xceU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xcdU;
                                        goto __Vlabel373;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xccU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xcbU;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xcaU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xc9U;
                                    goto __Vlabel373;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xc8U;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0xc7U;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xc6U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xc5U;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xc4U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xc3U;
                                goto __Vlabel373;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x9fU;
                                        goto __Vlabel373;
                                    } else {
                                        __Vfunc_internal_idx__8532__Vfuncout = 0x9eU;
                                        goto __Vlabel373;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x9dU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x9cU;
                                    goto __Vlabel373;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x52U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x4aU;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x49U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x48U;
                                goto __Vlabel373;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x47U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x46U;
                                goto __Vlabel373;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x45U;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x44U;
                            goto __Vlabel373;
                        }
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x39U;
                            goto __Vlabel373;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xeaU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                    goto __Vlabel373;
                                }
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x4fU;
                                goto __Vlabel373;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x36U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x35U;
                                goto __Vlabel373;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x34U;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x33U;
                            goto __Vlabel373;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xc3U;
                            goto __Vlabel373;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x3eU;
                                    goto __Vlabel373;
                                } else {
                                    __Vfunc_internal_idx__8532__Vfuncout = 0x3dU;
                                    goto __Vlabel373;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x3cU;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x3bU;
                                goto __Vlabel373;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x31U;
                                goto __Vlabel373;
                            }
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0x30U;
                                goto __Vlabel373;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x2fU;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0x48U;
                            goto __Vlabel373;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 0x44U;
                        goto __Vlabel373;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                    goto __Vlabel373;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                    goto __Vlabel373;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                    goto __Vlabel373;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xcU;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xbU;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xaU;
                        goto __Vlabel373;
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                        goto __Vlabel373;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                                __Vfunc_internal_idx__8532__Vfuncout = 6U;
                                goto __Vlabel373;
                            } else {
                                __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                                goto __Vlabel373;
                            }
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                            __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                            goto __Vlabel373;
                        } else {
                            __Vfunc_internal_idx__8532__Vfuncout = 5U;
                            goto __Vlabel373;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 4U;
                        goto __Vlabel373;
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 3U;
                        goto __Vlabel373;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                    goto __Vlabel373;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                        __Vfunc_internal_idx__8532__Vfuncout = 2U;
                        goto __Vlabel373;
                    } else {
                        __Vfunc_internal_idx__8532__Vfuncout = 1U;
                        goto __Vlabel373;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8532__csr_name))) {
                    __Vfunc_internal_idx__8532__Vfuncout = 0U;
                    goto __Vlabel373;
                } else {
                    __Vfunc_internal_idx__8532__Vfuncout = 0xf0U;
                    goto __Vlabel373;
                }
                __Vlabel373: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8532__Vfuncout))] = 0xa00000000ULL;
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8533__csr_name = 0x306U;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x43U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x42U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x41U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x40U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x3fU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x38U;
                                        goto __Vlabel374;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 7U;
                                    goto __Vlabel374;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 9U;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 8U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xc2U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xc1U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xc0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbfU;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbeU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbdU;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xbcU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xbbU;
                                    goto __Vlabel374;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbaU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb9U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb8U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb7U;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb6U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb5U;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xb4U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xb3U;
                                goto __Vlabel374;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb2U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb1U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xafU;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xaeU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xadU;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xacU;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xabU;
                                goto __Vlabel374;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xaaU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa9U;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xa8U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xa7U;
                                goto __Vlabel374;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xa6U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xa5U;
                                goto __Vlabel374;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xeU;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xa4U;
                            goto __Vlabel374;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xc2U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xc1U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xc0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xbfU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xbeU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xbdU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbcU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xbbU;
                                        goto __Vlabel374;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xbaU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xb9U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb8U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb7U;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb6U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb5U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb4U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xb3U;
                                    goto __Vlabel374;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xb2U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xb1U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xb0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xafU;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xaeU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xadU;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xacU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xabU;
                                    goto __Vlabel374;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xaaU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xa9U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa8U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa7U;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa6U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa5U;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xa4U;
                                goto __Vlabel374;
                            }
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xe9U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xe8U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xe7U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xe6U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xe5U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xe4U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xe3U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xe2U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xe1U;
                                        goto __Vlabel374;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x53U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xa3U;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xa2U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa1U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xa0U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x3aU;
                                        goto __Vlabel374;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x9bU;
                                                    goto __Vlabel374;
                                                } else {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x9aU;
                                                    goto __Vlabel374;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x99U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x98U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x97U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x96U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x95U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x94U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x93U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x92U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x91U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x90U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x8fU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x8eU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x8dU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x8cU;
                                        goto __Vlabel374;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x8bU;
                                                    goto __Vlabel374;
                                                } else {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x8aU;
                                                    goto __Vlabel374;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x89U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x88U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x87U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x86U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x85U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x84U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x83U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x82U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x81U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x80U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x7fU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x7eU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x7dU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x7cU;
                                        goto __Vlabel374;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x7bU;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x7aU;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x79U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x78U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x77U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x76U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x75U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x74U;
                                        goto __Vlabel374;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x73U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x72U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x71U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x70U;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x6fU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x6eU;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x6dU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x6cU;
                                    goto __Vlabel374;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x6bU;
                                                    goto __Vlabel374;
                                                } else {
                                                    __Vfunc_internal_idx__8533__Vfuncout = 0x6aU;
                                                    goto __Vlabel374;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x69U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x68U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x67U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x66U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x65U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x64U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x63U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x62U;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x61U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x60U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x5fU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x5eU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x5dU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x5cU;
                                        goto __Vlabel374;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0x5bU;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x5aU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x59U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x58U;
                                        goto __Vlabel374;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0x57U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x56U;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x55U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x54U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x51U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x50U;
                                        goto __Vlabel374;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x4fU;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x4eU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x4dU;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x4cU;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x4bU;
                                goto __Vlabel374;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xe0U;
                                                goto __Vlabel374;
                                            } else {
                                                __Vfunc_internal_idx__8533__Vfuncout = 0xdfU;
                                                goto __Vlabel374;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xdeU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xddU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xdcU;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xdbU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xdaU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xd9U;
                                        goto __Vlabel374;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xd8U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xd7U;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xd6U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xd5U;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xd4U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xd3U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xd2U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xd1U;
                                    goto __Vlabel374;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xd0U;
                                            goto __Vlabel374;
                                        } else {
                                            __Vfunc_internal_idx__8533__Vfuncout = 0xcfU;
                                            goto __Vlabel374;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xceU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xcdU;
                                        goto __Vlabel374;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xccU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xcbU;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xcaU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xc9U;
                                    goto __Vlabel374;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xc8U;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0xc7U;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xc6U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xc5U;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xc4U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xc3U;
                                goto __Vlabel374;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x9fU;
                                        goto __Vlabel374;
                                    } else {
                                        __Vfunc_internal_idx__8533__Vfuncout = 0x9eU;
                                        goto __Vlabel374;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x9dU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x9cU;
                                    goto __Vlabel374;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x52U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x4aU;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x49U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x48U;
                                goto __Vlabel374;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x47U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x46U;
                                goto __Vlabel374;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x45U;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x44U;
                            goto __Vlabel374;
                        }
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x39U;
                            goto __Vlabel374;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xeaU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                    goto __Vlabel374;
                                }
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x4fU;
                                goto __Vlabel374;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x36U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x35U;
                                goto __Vlabel374;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x34U;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x33U;
                            goto __Vlabel374;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xc3U;
                            goto __Vlabel374;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x3eU;
                                    goto __Vlabel374;
                                } else {
                                    __Vfunc_internal_idx__8533__Vfuncout = 0x3dU;
                                    goto __Vlabel374;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x3cU;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x3bU;
                                goto __Vlabel374;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x31U;
                                goto __Vlabel374;
                            }
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0x30U;
                                goto __Vlabel374;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x2fU;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0x48U;
                            goto __Vlabel374;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 0x44U;
                        goto __Vlabel374;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                    goto __Vlabel374;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                    goto __Vlabel374;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                    goto __Vlabel374;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xcU;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xbU;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xaU;
                        goto __Vlabel374;
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                        goto __Vlabel374;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                                __Vfunc_internal_idx__8533__Vfuncout = 6U;
                                goto __Vlabel374;
                            } else {
                                __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                                goto __Vlabel374;
                            }
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                            __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                            goto __Vlabel374;
                        } else {
                            __Vfunc_internal_idx__8533__Vfuncout = 5U;
                            goto __Vlabel374;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 4U;
                        goto __Vlabel374;
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 3U;
                        goto __Vlabel374;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                    goto __Vlabel374;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                        __Vfunc_internal_idx__8533__Vfuncout = 2U;
                        goto __Vlabel374;
                    } else {
                        __Vfunc_internal_idx__8533__Vfuncout = 1U;
                        goto __Vlabel374;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8533__csr_name))) {
                    __Vfunc_internal_idx__8533__Vfuncout = 0U;
                    goto __Vlabel374;
                } else {
                    __Vfunc_internal_idx__8533__Vfuncout = 0xf0U;
                    goto __Vlabel374;
                }
                __Vlabel374: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8533__Vfuncout))] = 7ULL;
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8534__csr_name = 0x106U;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x43U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x42U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x41U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x40U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x3fU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x38U;
                                        goto __Vlabel375;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 7U;
                                    goto __Vlabel375;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 9U;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 8U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xc2U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xc1U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xc0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbfU;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbeU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbdU;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xbcU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xbbU;
                                    goto __Vlabel375;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbaU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb9U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb8U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb7U;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb6U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb5U;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xb4U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xb3U;
                                goto __Vlabel375;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb2U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb1U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xafU;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xaeU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xadU;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xacU;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xabU;
                                goto __Vlabel375;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xaaU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa9U;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xa8U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xa7U;
                                goto __Vlabel375;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xa6U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xa5U;
                                goto __Vlabel375;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xeU;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xa4U;
                            goto __Vlabel375;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xc2U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xc1U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xc0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xbfU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xbeU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xbdU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbcU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xbbU;
                                        goto __Vlabel375;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xbaU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xb9U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb8U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb7U;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb6U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb5U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb4U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xb3U;
                                    goto __Vlabel375;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xb2U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xb1U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xb0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xafU;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xaeU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xadU;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xacU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xabU;
                                    goto __Vlabel375;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xaaU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xa9U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa8U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa7U;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa6U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa5U;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xa4U;
                                goto __Vlabel375;
                            }
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xe9U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xe8U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xe7U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xe6U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xe5U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xe4U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xe3U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xe2U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xe1U;
                                        goto __Vlabel375;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x53U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xa3U;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xa2U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa1U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xa0U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x3aU;
                                        goto __Vlabel375;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x9bU;
                                                    goto __Vlabel375;
                                                } else {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x9aU;
                                                    goto __Vlabel375;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x99U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x98U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x97U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x96U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x95U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x94U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x93U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x92U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x91U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x90U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x8fU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x8eU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x8dU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x8cU;
                                        goto __Vlabel375;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x8bU;
                                                    goto __Vlabel375;
                                                } else {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x8aU;
                                                    goto __Vlabel375;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x89U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x88U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x87U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x86U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x85U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x84U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x83U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x82U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x81U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x80U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x7fU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x7eU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x7dU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x7cU;
                                        goto __Vlabel375;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x7bU;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x7aU;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x79U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x78U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x77U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x76U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x75U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x74U;
                                        goto __Vlabel375;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x73U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x72U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x71U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x70U;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x6fU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x6eU;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x6dU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x6cU;
                                    goto __Vlabel375;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x6bU;
                                                    goto __Vlabel375;
                                                } else {
                                                    __Vfunc_internal_idx__8534__Vfuncout = 0x6aU;
                                                    goto __Vlabel375;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x69U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x68U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x67U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x66U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x65U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x64U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x63U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x62U;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x61U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x60U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x5fU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x5eU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x5dU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x5cU;
                                        goto __Vlabel375;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0x5bU;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x5aU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x59U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x58U;
                                        goto __Vlabel375;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0x57U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x56U;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x55U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x54U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x51U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x50U;
                                        goto __Vlabel375;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x4fU;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x4eU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x4dU;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x4cU;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x4bU;
                                goto __Vlabel375;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xe0U;
                                                goto __Vlabel375;
                                            } else {
                                                __Vfunc_internal_idx__8534__Vfuncout = 0xdfU;
                                                goto __Vlabel375;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xdeU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xddU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xdcU;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xdbU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xdaU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xd9U;
                                        goto __Vlabel375;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xd8U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xd7U;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xd6U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xd5U;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xd4U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xd3U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xd2U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xd1U;
                                    goto __Vlabel375;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xd0U;
                                            goto __Vlabel375;
                                        } else {
                                            __Vfunc_internal_idx__8534__Vfuncout = 0xcfU;
                                            goto __Vlabel375;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xceU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xcdU;
                                        goto __Vlabel375;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xccU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xcbU;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xcaU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xc9U;
                                    goto __Vlabel375;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xc8U;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0xc7U;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xc6U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xc5U;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xc4U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xc3U;
                                goto __Vlabel375;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x9fU;
                                        goto __Vlabel375;
                                    } else {
                                        __Vfunc_internal_idx__8534__Vfuncout = 0x9eU;
                                        goto __Vlabel375;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x9dU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x9cU;
                                    goto __Vlabel375;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x52U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x4aU;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x49U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x48U;
                                goto __Vlabel375;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x47U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x46U;
                                goto __Vlabel375;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x45U;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x44U;
                            goto __Vlabel375;
                        }
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x39U;
                            goto __Vlabel375;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xeaU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                    goto __Vlabel375;
                                }
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x4fU;
                                goto __Vlabel375;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x36U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x35U;
                                goto __Vlabel375;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x34U;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x33U;
                            goto __Vlabel375;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xc3U;
                            goto __Vlabel375;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x3eU;
                                    goto __Vlabel375;
                                } else {
                                    __Vfunc_internal_idx__8534__Vfuncout = 0x3dU;
                                    goto __Vlabel375;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x3cU;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x3bU;
                                goto __Vlabel375;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x31U;
                                goto __Vlabel375;
                            }
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0x30U;
                                goto __Vlabel375;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x2fU;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0x48U;
                            goto __Vlabel375;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 0x44U;
                        goto __Vlabel375;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                    goto __Vlabel375;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                    goto __Vlabel375;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                    goto __Vlabel375;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xcU;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xbU;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xaU;
                        goto __Vlabel375;
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                        goto __Vlabel375;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                                __Vfunc_internal_idx__8534__Vfuncout = 6U;
                                goto __Vlabel375;
                            } else {
                                __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                                goto __Vlabel375;
                            }
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                            __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                            goto __Vlabel375;
                        } else {
                            __Vfunc_internal_idx__8534__Vfuncout = 5U;
                            goto __Vlabel375;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 4U;
                        goto __Vlabel375;
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 3U;
                        goto __Vlabel375;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                    goto __Vlabel375;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                        __Vfunc_internal_idx__8534__Vfuncout = 2U;
                        goto __Vlabel375;
                    } else {
                        __Vfunc_internal_idx__8534__Vfuncout = 1U;
                        goto __Vlabel375;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8534__csr_name))) {
                    __Vfunc_internal_idx__8534__Vfuncout = 0U;
                    goto __Vlabel375;
                } else {
                    __Vfunc_internal_idx__8534__Vfuncout = 0xf0U;
                    goto __Vlabel375;
                }
                __Vlabel375: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8534__Vfuncout))] = 7ULL;
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8535__csr_name = 0x320U;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x43U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x42U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x41U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x40U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x3fU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x38U;
                                        goto __Vlabel376;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 7U;
                                    goto __Vlabel376;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 9U;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 8U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xc2U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xc1U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xc0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbfU;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbeU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbdU;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xbcU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xbbU;
                                    goto __Vlabel376;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbaU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb9U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb8U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb7U;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb6U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb5U;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xb4U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xb3U;
                                goto __Vlabel376;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb2U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb1U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xafU;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xaeU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xadU;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xacU;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xabU;
                                goto __Vlabel376;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xaaU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa9U;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xa8U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xa7U;
                                goto __Vlabel376;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xa6U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xa5U;
                                goto __Vlabel376;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xeU;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xa4U;
                            goto __Vlabel376;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xc2U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xc1U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xc0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xbfU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xbeU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xbdU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbcU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xbbU;
                                        goto __Vlabel376;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xbaU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xb9U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb8U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb7U;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb6U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb5U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb4U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xb3U;
                                    goto __Vlabel376;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xb2U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xb1U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xb0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xafU;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xaeU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xadU;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xacU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xabU;
                                    goto __Vlabel376;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xaaU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xa9U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa8U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa7U;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa6U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa5U;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xa4U;
                                goto __Vlabel376;
                            }
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xe9U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xe8U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xe7U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xe6U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xe5U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xe4U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xe3U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xe2U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xe1U;
                                        goto __Vlabel376;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x53U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xa3U;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xa2U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa1U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xa0U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x3aU;
                                        goto __Vlabel376;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x9bU;
                                                    goto __Vlabel376;
                                                } else {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x9aU;
                                                    goto __Vlabel376;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x99U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x98U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x97U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x96U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x95U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x94U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x93U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x92U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x91U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x90U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x8fU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x8eU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x8dU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x8cU;
                                        goto __Vlabel376;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x8bU;
                                                    goto __Vlabel376;
                                                } else {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x8aU;
                                                    goto __Vlabel376;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x89U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x88U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x87U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x86U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x85U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x84U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x83U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x82U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x81U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x80U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x7fU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x7eU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x7dU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x7cU;
                                        goto __Vlabel376;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x7bU;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x7aU;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x79U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x78U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x77U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x76U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x75U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x74U;
                                        goto __Vlabel376;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x73U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x72U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x71U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x70U;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x6fU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x6eU;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x6dU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x6cU;
                                    goto __Vlabel376;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x6bU;
                                                    goto __Vlabel376;
                                                } else {
                                                    __Vfunc_internal_idx__8535__Vfuncout = 0x6aU;
                                                    goto __Vlabel376;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x69U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x68U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x67U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x66U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x65U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x64U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x63U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x62U;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x61U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x60U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x5fU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x5eU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x5dU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x5cU;
                                        goto __Vlabel376;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0x5bU;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x5aU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x59U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x58U;
                                        goto __Vlabel376;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0x57U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x56U;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x55U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x54U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x51U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x50U;
                                        goto __Vlabel376;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x4fU;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x4eU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x4dU;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x4cU;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x4bU;
                                goto __Vlabel376;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xe0U;
                                                goto __Vlabel376;
                                            } else {
                                                __Vfunc_internal_idx__8535__Vfuncout = 0xdfU;
                                                goto __Vlabel376;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xdeU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xddU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xdcU;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xdbU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xdaU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xd9U;
                                        goto __Vlabel376;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xd8U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xd7U;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xd6U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xd5U;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xd4U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xd3U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xd2U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xd1U;
                                    goto __Vlabel376;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xd0U;
                                            goto __Vlabel376;
                                        } else {
                                            __Vfunc_internal_idx__8535__Vfuncout = 0xcfU;
                                            goto __Vlabel376;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xceU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xcdU;
                                        goto __Vlabel376;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xccU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xcbU;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xcaU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xc9U;
                                    goto __Vlabel376;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xc8U;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0xc7U;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xc6U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xc5U;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xc4U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xc3U;
                                goto __Vlabel376;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x9fU;
                                        goto __Vlabel376;
                                    } else {
                                        __Vfunc_internal_idx__8535__Vfuncout = 0x9eU;
                                        goto __Vlabel376;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x9dU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x9cU;
                                    goto __Vlabel376;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x52U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x4aU;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x49U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x48U;
                                goto __Vlabel376;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x47U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x46U;
                                goto __Vlabel376;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x45U;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x44U;
                            goto __Vlabel376;
                        }
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x39U;
                            goto __Vlabel376;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xeaU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                    goto __Vlabel376;
                                }
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x4fU;
                                goto __Vlabel376;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x36U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x35U;
                                goto __Vlabel376;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x34U;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x33U;
                            goto __Vlabel376;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xc3U;
                            goto __Vlabel376;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x3eU;
                                    goto __Vlabel376;
                                } else {
                                    __Vfunc_internal_idx__8535__Vfuncout = 0x3dU;
                                    goto __Vlabel376;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x3cU;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x3bU;
                                goto __Vlabel376;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x31U;
                                goto __Vlabel376;
                            }
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0x30U;
                                goto __Vlabel376;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x2fU;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0x48U;
                            goto __Vlabel376;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 0x44U;
                        goto __Vlabel376;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                    goto __Vlabel376;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                    goto __Vlabel376;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                    goto __Vlabel376;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xcU;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xbU;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xaU;
                        goto __Vlabel376;
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                        goto __Vlabel376;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                                __Vfunc_internal_idx__8535__Vfuncout = 6U;
                                goto __Vlabel376;
                            } else {
                                __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                                goto __Vlabel376;
                            }
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                            __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                            goto __Vlabel376;
                        } else {
                            __Vfunc_internal_idx__8535__Vfuncout = 5U;
                            goto __Vlabel376;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 4U;
                        goto __Vlabel376;
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 3U;
                        goto __Vlabel376;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                    goto __Vlabel376;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                        __Vfunc_internal_idx__8535__Vfuncout = 2U;
                        goto __Vlabel376;
                    } else {
                        __Vfunc_internal_idx__8535__Vfuncout = 1U;
                        goto __Vlabel376;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8535__csr_name))) {
                    __Vfunc_internal_idx__8535__Vfuncout = 0U;
                    goto __Vlabel376;
                } else {
                    __Vfunc_internal_idx__8535__Vfuncout = 0xf0U;
                    goto __Vlabel376;
                }
                __Vlabel376: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8535__Vfuncout))] = 0ULL;
    vlSelfRef.Top__DOT__csrrf__DOT__csr_regs_init[([&]() {
            __Vfunc_internal_idx__8536__csr_name = 0x30aU;
            {
                if ((0x800U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((0x400U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x200U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x43U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x42U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x41U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x40U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x3fU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x38U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 7U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 9U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 8U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xc2U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xc1U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xc0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbfU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbeU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbdU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xbcU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xbbU;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbaU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb8U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb7U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb6U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb5U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xb4U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xb3U;
                                goto __Vlabel377;
                            }
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb2U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb1U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xafU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xaeU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xadU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xacU;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xabU;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xaaU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa9U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xa8U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xa7U;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xa6U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xa5U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xeU;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xa4U;
                            goto __Vlabel377;
                        }
                    } else if ((0x200U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xc2U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xc1U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xc0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xbfU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xbeU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xbdU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbcU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xbbU;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xbaU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xb9U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb8U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb7U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb6U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb5U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb4U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xb3U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xb2U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xb1U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xb0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xafU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xaeU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xadU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xacU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xabU;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xaaU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xa9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa8U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa7U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa6U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa5U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xa4U;
                                goto __Vlabel377;
                            }
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x400U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((0x200U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (4U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xe9U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xe8U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xe7U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xe6U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xe5U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xe4U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xe3U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xe2U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xe1U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x53U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xa3U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xa2U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa1U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xa0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x3aU;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x200U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else if ((8U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x9bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x9aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x99U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x98U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x97U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x96U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x95U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x94U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x93U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x92U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x91U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x90U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x8fU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x8eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x8dU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x8cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x8bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x8aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x89U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x88U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x87U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x86U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x85U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x84U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x83U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x82U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x81U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x80U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x7fU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x7eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x7dU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x7cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x7bU;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x7aU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x79U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x78U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x77U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x76U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x75U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x74U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x73U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x72U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x71U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x70U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x6fU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x6eU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x6dU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x6cU;
                                    goto __Vlabel377;
                                }
                            } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((2U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x6bU;
                                                    goto __Vlabel377;
                                                } else {
                                                    __Vfunc_internal_idx__8536__Vfuncout = 0x6aU;
                                                    goto __Vlabel377;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x69U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x68U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x67U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x66U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x65U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x64U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((4U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x63U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x62U;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x61U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x60U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x5fU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x5eU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x5dU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x5cU;
                                        goto __Vlabel377;
                                    }
                                } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0x5bU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x5aU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x59U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x58U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0x57U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x56U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x55U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x54U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x51U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x50U;
                                        goto __Vlabel377;
                                    }
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x4fU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x4eU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x4dU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x4cU;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x4bU;
                                goto __Vlabel377;
                            }
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xe0U;
                                                goto __Vlabel377;
                                            } else {
                                                __Vfunc_internal_idx__8536__Vfuncout = 0xdfU;
                                                goto __Vlabel377;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xdeU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xddU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xdcU;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xdbU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xdaU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xd9U;
                                        goto __Vlabel377;
                                    }
                                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xd8U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xd7U;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xd6U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xd5U;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xd4U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xd3U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xd2U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xd1U;
                                    goto __Vlabel377;
                                }
                            } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xd0U;
                                            goto __Vlabel377;
                                        } else {
                                            __Vfunc_internal_idx__8536__Vfuncout = 0xcfU;
                                            goto __Vlabel377;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xceU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xcdU;
                                        goto __Vlabel377;
                                    }
                                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xccU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xcbU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xcaU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xc9U;
                                    goto __Vlabel377;
                                }
                            } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xc8U;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0xc7U;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xc6U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xc5U;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xc4U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xc3U;
                                goto __Vlabel377;
                            }
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x9fU;
                                        goto __Vlabel377;
                                    } else {
                                        __Vfunc_internal_idx__8536__Vfuncout = 0x9eU;
                                        goto __Vlabel377;
                                    }
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x9dU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x9cU;
                                    goto __Vlabel377;
                                }
                            } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x52U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x4aU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x49U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x48U;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x47U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x46U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x45U;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x44U;
                            goto __Vlabel377;
                        }
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((0x100U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x39U;
                            goto __Vlabel377;
                        }
                    } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xeaU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                    goto __Vlabel377;
                                }
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x4fU;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x36U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x35U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x34U;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x33U;
                            goto __Vlabel377;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xc3U;
                            goto __Vlabel377;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x3eU;
                                    goto __Vlabel377;
                                } else {
                                    __Vfunc_internal_idx__8536__Vfuncout = 0x3dU;
                                    goto __Vlabel377;
                                }
                            } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x3cU;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x3bU;
                                goto __Vlabel377;
                            }
                        } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x31U;
                                goto __Vlabel377;
                            }
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0x30U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x2fU;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0x48U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 0x44U;
                        goto __Vlabel377;
                    }
                } else if ((0x80U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x40U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x20U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((0x10U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xcU;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xbU;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xaU;
                        goto __Vlabel377;
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                        goto __Vlabel377;
                    }
                } else if ((8U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                                __Vfunc_internal_idx__8536__Vfuncout = 6U;
                                goto __Vlabel377;
                            } else {
                                __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                                goto __Vlabel377;
                            }
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        }
                    } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                            __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                            goto __Vlabel377;
                        } else {
                            __Vfunc_internal_idx__8536__Vfuncout = 5U;
                            goto __Vlabel377;
                        }
                    } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 4U;
                        goto __Vlabel377;
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 3U;
                        goto __Vlabel377;
                    }
                } else if ((4U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                } else if ((2U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                        __Vfunc_internal_idx__8536__Vfuncout = 2U;
                        goto __Vlabel377;
                    } else {
                        __Vfunc_internal_idx__8536__Vfuncout = 1U;
                        goto __Vlabel377;
                    }
                } else if ((1U & (IData)(__Vfunc_internal_idx__8536__csr_name))) {
                    __Vfunc_internal_idx__8536__Vfuncout = 0U;
                    goto __Vlabel377;
                } else {
                    __Vfunc_internal_idx__8536__Vfuncout = 0xf0U;
                    goto __Vlabel377;
                }
                __Vlabel377: ;
            }
        }(), (IData)(__Vfunc_internal_idx__8536__Vfuncout))] = 0x1000000000000000ULL;
}
