// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__8(VTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__8\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx;
    Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx = 0;
    // Body
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.Top__DOT__pred_taken = vlSelfRef.Top__DOT__predictor__DOT__pred_taken_next;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.Top__DOT__pc_from_st2_to_st3[0U] = 0U;
        vlSelfRef.Top__DOT__pc_from_st2_to_st3[1U] = 0U;
        vlSelfRef.Top__DOT__pc_from_st2_to_st3[2U] = 0U;
        vlSelfRef.Top__DOT__ifqueue__DOT__num_of_entries_in_ifq = 0U;
        vlSelfRef.Top__DOT__ifqueue__DOT__ifq_wp = 0U;
    } else {
        if (vlSelfRef.Top__DOT__flush_to_st2) {
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[0U] = 0U;
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[1U] = 0U;
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[2U] = 0U;
        } else {
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[0U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[0U];
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[1U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[1U];
            vlSelfRef.Top__DOT__pc_from_st2_to_st3[2U] 
                = vlSelfRef.Top__DOT__pcbypass__DOT__pc_in[2U];
        }
        vlSelfRef.Top__DOT__ifqueue__DOT__num_of_entries_in_ifq 
            = vlSelfRef.Top__DOT__ifqueue__DOT__num_of_entries_in_ifq_next;
        vlSelfRef.Top__DOT__ifqueue__DOT__ifq_wp = vlSelfRef.Top__DOT__ifqueue__DOT__ifq_wp_next;
    }
    Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx 
        = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_prev
        [vlSelfRef.Top__DOT__btb__DOT__btb__DOT__r_ram_idx_prev
        [0U]];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data[0U] 
        = ((0U >= (IData)(Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx))
            ? vlSelfRef.Top__DOT__btb__DOT__btb__DOT__read_raw_data
           [0U][Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx]
            : 0ULL);
    Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx 
        = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_prev
        [vlSelfRef.Top__DOT__btb__DOT__btb__DOT__r_ram_idx_prev
        [1U]];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data[1U] 
        = ((0U >= (IData)(Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx))
            ? vlSelfRef.Top__DOT__btb__DOT__btb__DOT__read_raw_data
           [1U][Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx]
            : 0ULL);
    Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx 
        = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_prev
        [vlSelfRef.Top__DOT__btb__DOT__btb__DOT__r_ram_idx_prev
        [2U]];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data[2U] 
        = ((0U >= (IData)(Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx))
            ? vlSelfRef.Top__DOT__btb__DOT__btb__DOT__read_raw_data
           [2U][Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx]
            : 0ULL);
    Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx 
        = vlSelfRef.Top__DOT__btb__DOT__btb__DOT__lvt_prev
        [vlSelfRef.Top__DOT__btb__DOT__btb__DOT__r_ram_idx_prev
        [3U]];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data[3U] 
        = ((0U >= (IData)(Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx))
            ? vlSelfRef.Top__DOT__btb__DOT__btb__DOT__read_raw_data
           [3U][Top__DOT__btb__DOT__btb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__last_written_sd_cluster_idx]
            : 0ULL);
    if (vlSelfRef.__VdlySet__Top__DOT__btb__DOT__addr_in_prev__v0) {
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[0U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[1U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[2U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[3U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__btb__DOT__addr_in_prev__v4) {
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[0U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[1U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[2U] = 0ULL;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[3U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__btb__DOT__addr_in_prev__v8) {
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__btb__DOT__addr_in_prev__v8;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__btb__DOT__addr_in_prev__v9;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__btb__DOT__addr_in_prev__v10;
        vlSelfRef.Top__DOT__btb__DOT__addr_in_prev[3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__btb__DOT__addr_in_prev__v11;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v0) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v0;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v1;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v2;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v3;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v4;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v5;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v6;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v7;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v8;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v9;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v10;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v11;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xcU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v12;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v13;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v14;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v15;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x10U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v16;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x11U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v17;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x12U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v18;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x13U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v19;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x14U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v20;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x15U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v21;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x16U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v22;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x17U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v23;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x18U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v24;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x19U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v25;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v26;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v27;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v28;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v29;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v30;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x1fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v31;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x20U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v32;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x21U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v33;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x22U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v34;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x23U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v35;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x24U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v36;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x25U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v37;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x26U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v38;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x27U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v39;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x28U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v40;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x29U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v41;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v42;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v43;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v44;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v45;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v46;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x2fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v47;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x30U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v48;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x31U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v49;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x32U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v50;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x33U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v51;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x34U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v52;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x35U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v53;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x36U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v54;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x37U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v55;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x38U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v56;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x39U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v57;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v58;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v59;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v60;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v61;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v62;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x3fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v63;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x40U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v64;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x41U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v65;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x42U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v66;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x43U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v67;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x44U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v68;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x45U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v69;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x46U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v70;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x47U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v71;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x48U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v72;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x49U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v73;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v74;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v75;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v76;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v77;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v78;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x4fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v79;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x50U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v80;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x51U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v81;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x52U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v82;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x53U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v83;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x54U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v84;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x55U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v85;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x56U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v86;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x57U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v87;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x58U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v88;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x59U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v89;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v90;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v91;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v92;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v93;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v94;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x5fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v95;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x60U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v96;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x61U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v97;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x62U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v98;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x63U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v99;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x64U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v100;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x65U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v101;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x66U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v102;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x67U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v103;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x68U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v104;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x69U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v105;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v106;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v107;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v108;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v109;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v110;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x6fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v111;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x70U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v112;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x71U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v113;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x72U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v114;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x73U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v115;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x74U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v116;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x75U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v117;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x76U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v118;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x77U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v119;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x78U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v120;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x79U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v121;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v122;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v123;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v124;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v125;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v126;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x7fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v127;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x80U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v128;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x81U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v129;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x82U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v130;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x83U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v131;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x84U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v132;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x85U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v133;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x86U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v134;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x87U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v135;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x88U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v136;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x89U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v137;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v138;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v139;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v140;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v141;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v142;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x8fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v143;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x90U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v144;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x91U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v145;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x92U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v146;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x93U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v147;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x94U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v148;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x95U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v149;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x96U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v150;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x97U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v151;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x98U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v152;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x99U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v153;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9aU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v154;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9bU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v155;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9cU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v156;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9dU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v157;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9eU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v158;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0x9fU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v159;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v160;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v161;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v162;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v163;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v164;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v165;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v166;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v167;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v168;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xa9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v169;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xaaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v170;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xabU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v171;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xacU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v172;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xadU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v173;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xaeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v174;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xafU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v175;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v176;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v177;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v178;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v179;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v180;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v181;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v182;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v183;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v184;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xb9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v185;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v186;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbbU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v187;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbcU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v188;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbdU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v189;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v190;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xbfU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v191;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v192;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v193;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v194;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v195;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v196;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v197;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v198;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v199;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v200;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xc9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v201;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xcaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v202;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xcbU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v203;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xccU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v204;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xcdU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v205;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xceU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v206;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xcfU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v207;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v208;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v209;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v210;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v211;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v212;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v213;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v214;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v215;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v216;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xd9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v217;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v218;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdbU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v219;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdcU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v220;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xddU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v221;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v222;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xdfU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v223;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v224;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v225;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v226;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v227;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v228;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v229;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v230;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v231;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v232;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xe9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v233;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xeaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v234;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xebU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v235;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xecU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v236;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xedU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v237;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xeeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v238;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xefU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v239;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf0U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v240;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf1U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v241;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf2U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v242;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf3U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v243;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf4U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v244;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf5U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v245;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf6U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v246;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf7U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v247;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf8U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v248;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xf9U] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v249;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfaU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v250;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfbU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v251;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfcU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v252;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfdU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v253;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xfeU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v254;
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[0xffU] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v255;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v256) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v256] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v256;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v257) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v257] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v257;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v258) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v258] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v258;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v259) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v259] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v259;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v260) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v260] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v260;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v261) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v261] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v261;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v262) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v262] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v262;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v263) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v263] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v263;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v264) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v264] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v264;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v265) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v265] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v265;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v266) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v266] 
            = ((0xffffffffffffffdfULL & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
                [vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v266]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v266)) 
                  << 5U));
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v267) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v267] 
            = ((0xffffffffffffff7fULL & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
                [vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v267]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v267)) 
                  << 7U));
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v268) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v268] 
            = ((0xfffffffffffff7ffULL & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
                [vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v268]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v268)) 
                  << 0xbU));
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v269) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v269] 
            = ((0xfffffffffffffdffULL & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
                [vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v269]) 
               | ((QData)((IData)(vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v269)) 
                  << 9U));
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v270) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v270] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v270;
    }
    if (vlSelfRef.__VdlySet__Top__DOT__csrrf__DOT__csr_regs__v271) {
        vlSelfRef.Top__DOT__csrrf__DOT__csr_regs[vlSelfRef.__VdlyDim0__Top__DOT__csrrf__DOT__csr_regs__v271] 
            = vlSelfRef.__VdlyVal__Top__DOT__csrrf__DOT__csr_regs__v271;
    }
    vlSelfRef.Top__DOT__btb__DOT__btb_r_data[0U] = 
        vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data
        [0U];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_data[1U] = 
        vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data
        [1U];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_data[2U] = 
        vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data
        [2U];
    vlSelfRef.Top__DOT__btb__DOT__btb_r_data[3U] = 
        vlSelfRef.Top__DOT__btb__DOT__btb_r_bit_data
        [3U];
    vlSelfRef.Top__DOT__satp = (([&]() {
                vlSelfRef.__Vfunc_get_read_mask__427__csr_name = 0x180U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_mconfigptr_get_read_mask__428__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mconfigptr_get_read_mask__428__Vfuncout;
                                                goto __Vlabel18;
                                            } else {
                                                vlSelfRef.__Vfunc_mhartid_get_read_mask__429__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mhartid_get_read_mask__429__Vfuncout;
                                                goto __Vlabel18;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_mimpid_get_read_mask__430__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mimpid_get_read_mask__430__Vfuncout;
                                                goto __Vlabel18;
                                            } else {
                                                vlSelfRef.__Vfunc_marchid_get_read_mask__431__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_marchid_get_read_mask__431__Vfuncout;
                                                goto __Vlabel18;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_mvendorid_get_read_mask__432__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_mvendorid_get_read_mask__432__Vfuncout;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_scountovf_get_read_mask__433__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_scountovf_get_read_mask__433__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_vl_get_read_mask__434__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_vl_get_read_mask__434__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_vlenb_get_read_mask__435__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_vlenb_get_read_mask__435__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_vtype_get_read_mask__436__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_vtype_get_read_mask__436__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__437__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__437__Vfuncout;
                                goto __Vlabel18;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__438__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__438__Vfuncout;
                                goto __Vlabel18;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__439__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__439__Vfuncout;
                                goto __Vlabel18;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_hpmcounter_get_read_mask__440__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__440__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_instret_get_read_mask__441__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_instret_get_read_mask__441__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_time_get_read_mask__442__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_time_get_read_mask__442__Vfuncout;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_cycle_get_read_mask__443__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_cycle_get_read_mask__443__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__444__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__444__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__445__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__445__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__446__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__446__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__447__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__447__Vfuncout;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_minstret_get_read_mask__448__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_minstret_get_read_mask__448__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_mcycle_get_read_mask__449__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcycle_get_read_mask__449__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_dscratch_get_read_mask__450__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dscratch_get_read_mask__450__Vfuncout;
                                                goto __Vlabel18;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_dpc_get_read_mask__451__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dpc_get_read_mask__451__Vfuncout;
                                                goto __Vlabel18;
                                            } else {
                                                vlSelfRef.__Vfunc_dcsr_get_read_mask__452__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dcsr_get_read_mask__452__Vfuncout;
                                                goto __Vlabel18;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            } else {
                                                vlSelfRef.__Vfunc_mcontext_get_read_mask__453__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mcontext_get_read_mask__453__Vfuncout;
                                                goto __Vlabel18;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__454__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__454__Vfuncout;
                                            goto __Vlabel18;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__455__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__455__Vfuncout;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_tselect_get_read_mask__456__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_tselect_get_read_mask__456__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                                vlSelfRef.__Vfunc_mseccfg_get_read_mask__457__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mseccfg_get_read_mask__457__Vfuncout;
                                                goto __Vlabel18;
                                            } else {
                                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                                goto __Vlabel18;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_mnstatus_get_read_mask__458__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_mnstatus_get_read_mask__458__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_mncause_get_read_mask__459__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_mncause_get_read_mask__459__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_mnepc_get_read_mask__460__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnepc_get_read_mask__460__Vfuncout;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_mnscratch_get_read_mask__461__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnscratch_get_read_mask__461__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_scontext_get_read_mask__462__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_scontext_get_read_mask__462__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_pmpaddr_get_read_mask__463__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__463__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__464__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__464__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__465__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__465__Vfuncout;
                                        goto __Vlabel18;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_pmpcfg_get_read_mask__466__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpcfg_get_read_mask__466__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                            vlSelfRef.__Vfunc_mtval2_get_read_mask__467__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtval2_get_read_mask__467__Vfuncout;
                                            goto __Vlabel18;
                                        } else {
                                            vlSelfRef.__Vfunc_mtinst_get_read_mask__468__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtinst_get_read_mask__468__Vfuncout;
                                            goto __Vlabel18;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_mip_get_read_mask__469__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mip_get_read_mask__469__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_mtval_get_read_mask__470__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mtval_get_read_mask__470__Vfuncout;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_mcause_get_read_mask__471__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcause_get_read_mask__471__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mepc_get_read_mask__472__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mepc_get_read_mask__472__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_mscratch_get_read_mask__473__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mscratch_get_read_mask__473__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__474__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__474__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__475__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__475__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__476__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__476__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmevent_get_read_mask__477__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__477__Vfuncout;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else {
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__478__mask = 0;
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__478__mask_logic = 0;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask 
                                        = (0xffffffffULL 
                                           & vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask);
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask_logic 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__mask_logic;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__478__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mstateen_get_read_mask__479__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mstateen_get_read_mask__479__Vfuncout;
                                    goto __Vlabel18;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_menvcfg_get_read_mask__480__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_menvcfg_get_read_mask__480__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_mcounteren_get_read_mask__481__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcounteren_get_read_mask__481__Vfuncout;
                                        goto __Vlabel18;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mtvec_get_read_mask__482__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mtvec_get_read_mask__482__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_mie_get_read_mask__483__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mie_get_read_mask__483__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_mideleg_get_read_mask__484__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_mideleg_get_read_mask__484__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_medeleg_get_read_mask__485__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_medeleg_get_read_mask__485__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_misa_get_read_mask__486__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_misa_get_read_mask__486__Vfuncout;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_mstatus_get_read_mask__487__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_mstatus_get_read_mask__487__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_satp_get_read_mask__488__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_satp_get_read_mask__488__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                        vlSelfRef.__Vfunc_stimecmp_get_read_mask__489__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                            = vlSelfRef.__Vfunc_stimecmp_get_read_mask__489__Vfuncout;
                                        goto __Vlabel18;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                        goto __Vlabel18;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else {
                                    vlSelf->__Vfunc_sip_get_read_mask__490__mask = 0;
                                    vlSelf->__Vfunc_sip_get_read_mask__490__mask_csr = 0;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr 
                                        = (0x3ffULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr 
                                        = (0xfffffffffffffe3fULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr 
                                        = (0xffffffffffffffe3ULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr 
                                        = (0xfffffffffffffffeULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__mask 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__490__mask_csr;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__490__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__490__mask;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__490__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_stval_get_read_mask__491__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_stval_get_read_mask__491__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_scause_get_read_mask__492__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_scause_get_read_mask__492__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_sepc_get_read_mask__493__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_sepc_get_read_mask__493__Vfuncout;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_sscratch_get_read_mask__494__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_sscratch_get_read_mask__494__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else {
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__495__mask = 0;
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__495__mask_logic = 0;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask 
                                    = (0xffffffffULL 
                                       & vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask);
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask_logic 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__mask_logic;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__495__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_sstateen_get_read_mask__496__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_sstateen_get_read_mask__496__Vfuncout;
                                goto __Vlabel18;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_senvcfg_get_read_mask__497__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_senvcfg_get_read_mask__497__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_scounteren_get_read_mask__498__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_scounteren_get_read_mask__498__Vfuncout;
                                    goto __Vlabel18;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_stvec_get_read_mask__499__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_stvec_get_read_mask__499__Vfuncout;
                                goto __Vlabel18;
                            } else {
                                vlSelf->__Vfunc_sie_get_read_mask__500__mask = 0;
                                vlSelf->__Vfunc_sie_get_read_mask__500__mask_csr = 0;
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr 
                                    = (0x3fffULL & vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr 
                                    = (0xffffffffffffe3ffULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr 
                                    = (0xfffffffffffffe3fULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr 
                                    = (0xffffffffffffffe3ULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr 
                                    = (0xfffffffffffffffeULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__mask 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__500__mask_csr;
                                vlSelfRef.__Vfunc_sie_get_read_mask__500__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__500__mask;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__500__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        } else {
                            vlSelf->__Vfunc_sstatus_get_read_mask__501__mask_csr = 0;
                            vlSelf->__Vfunc_sstatus_get_read_mask__501__mask = 0;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0x80000003ffffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xffffffff01ffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xffffffffff8fffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xfffffffffffdffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xffffffffffffe7ffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xffffffffffffff7fULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xffffffffffffffe3ULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr 
                                = (0xfffffffffffffffeULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask_csr;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__501__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__501__mask;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__501__Vfuncout;
                            goto __Vlabel18;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                        goto __Vlabel18;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                        goto __Vlabel18;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                        goto __Vlabel18;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_jvt_get_read_mask__502__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_jvt_get_read_mask__502__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_seed_get_read_mask__503__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_seed_get_read_mask__503__Vfuncout;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_ssp_get_read_mask__504__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_ssp_get_read_mask__504__Vfuncout;
                            goto __Vlabel18;
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                            goto __Vlabel18;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                    vlSelfRef.__Vfunc_vcsr_get_read_mask__505__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                        = vlSelfRef.__Vfunc_vcsr_get_read_mask__505__Vfuncout;
                                    goto __Vlabel18;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                    goto __Vlabel18;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                                goto __Vlabel18;
                            } else {
                                vlSelfRef.__Vfunc_vxrm_get_read_mask__506__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                    = vlSelfRef.__Vfunc_vxrm_get_read_mask__506__Vfuncout;
                                goto __Vlabel18;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_vxsat_get_read_mask__507__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_vxsat_get_read_mask__507__Vfuncout;
                            goto __Vlabel18;
                        } else {
                            vlSelfRef.__Vfunc_vstart_get_read_mask__508__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_vstart_get_read_mask__508__Vfuncout;
                            goto __Vlabel18;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                        goto __Vlabel18;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                            vlSelfRef.__Vfunc_fcsr_get_read_mask__509__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_fcsr_get_read_mask__509__Vfuncout;
                            goto __Vlabel18;
                        } else {
                            vlSelfRef.__Vfunc_frm_get_read_mask__510__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                                = vlSelfRef.__Vfunc_frm_get_read_mask__510__Vfuncout;
                            goto __Vlabel18;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__427__csr_name))) {
                        vlSelfRef.__Vfunc_fflags_get_read_mask__511__Vfuncout = 0x1fULL;
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout 
                            = vlSelfRef.__Vfunc_fflags_get_read_mask__511__Vfuncout;
                        goto __Vlabel18;
                    } else {
                        vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout = 0ULL;
                        goto __Vlabel18;
                    }
                    __Vlabel18: ;
                }
            }(), vlSelfRef.__Vfunc_get_read_mask__427__Vfuncout) 
                                & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
                                [([&]() {
                vlSelfRef.__Vfunc_internal_idx__512__csr_name = 0x180U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x43U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x42U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x41U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x40U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3fU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x38U;
                                            goto __Vlabel19;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 7U;
                                        goto __Vlabel19;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 9U;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 8U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc2U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc1U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbfU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbeU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbdU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbcU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbbU;
                                        goto __Vlabel19;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbaU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb9U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb8U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb7U;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb6U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb5U;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb4U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb3U;
                                    goto __Vlabel19;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb2U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb1U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xafU;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xaeU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xadU;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xacU;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xabU;
                                    goto __Vlabel19;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xaaU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa9U;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa8U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa7U;
                                    goto __Vlabel19;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa6U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa5U;
                                    goto __Vlabel19;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xeU;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa4U;
                                goto __Vlabel19;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc2U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc1U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbfU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbeU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbdU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbcU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbbU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbaU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb9U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb8U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb7U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb6U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb5U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb4U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb3U;
                                        goto __Vlabel19;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb2U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb1U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xb0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xafU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xaeU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xadU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xacU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xabU;
                                        goto __Vlabel19;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xaaU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa9U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa8U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa7U;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa6U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa5U;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa4U;
                                    goto __Vlabel19;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe9U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe8U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe7U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe6U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe5U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe4U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe3U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe2U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe1U;
                                            goto __Vlabel19;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x53U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa3U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa2U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa1U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xa0U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3aU;
                                            goto __Vlabel19;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9bU;
                                                        goto __Vlabel19;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9aU;
                                                        goto __Vlabel19;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x99U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x98U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x97U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x96U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x95U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x94U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x93U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x92U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x91U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x90U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8fU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8eU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8dU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8cU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8bU;
                                                        goto __Vlabel19;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x8aU;
                                                        goto __Vlabel19;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x89U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x88U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x87U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x86U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x85U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x84U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x83U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x82U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x81U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x80U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7fU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7eU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7dU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7cU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7bU;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x7aU;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x79U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x78U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x77U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x76U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x75U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x74U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x73U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x72U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x71U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x70U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6fU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6eU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6dU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6cU;
                                        goto __Vlabel19;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6bU;
                                                        goto __Vlabel19;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x6aU;
                                                        goto __Vlabel19;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x69U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x68U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x67U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x66U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x65U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x64U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x63U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x62U;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x61U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x60U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5fU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5eU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5dU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5cU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5bU;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x5aU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x59U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x58U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x57U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x56U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x55U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x54U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x51U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x50U;
                                            goto __Vlabel19;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4fU;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4eU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4dU;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4cU;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4bU;
                                    goto __Vlabel19;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xe0U;
                                                    goto __Vlabel19;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xdfU;
                                                    goto __Vlabel19;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xdeU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xddU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xdcU;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xdbU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xdaU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd9U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd8U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd7U;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd6U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd5U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd4U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd3U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd2U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd1U;
                                        goto __Vlabel19;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xd0U;
                                                goto __Vlabel19;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xcfU;
                                                goto __Vlabel19;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xceU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xcdU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xccU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xcbU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xcaU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc9U;
                                        goto __Vlabel19;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc8U;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc7U;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc6U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc5U;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc4U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc3U;
                                    goto __Vlabel19;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9fU;
                                            goto __Vlabel19;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9eU;
                                            goto __Vlabel19;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9dU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x9cU;
                                        goto __Vlabel19;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x52U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4aU;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x49U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x48U;
                                    goto __Vlabel19;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x47U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x46U;
                                    goto __Vlabel19;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x45U;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x44U;
                                goto __Vlabel19;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x39U;
                                goto __Vlabel19;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xeaU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                        goto __Vlabel19;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x4fU;
                                    goto __Vlabel19;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x36U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x35U;
                                    goto __Vlabel19;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x34U;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x33U;
                                goto __Vlabel19;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xc3U;
                                goto __Vlabel19;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3eU;
                                        goto __Vlabel19;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3dU;
                                        goto __Vlabel19;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3cU;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x3bU;
                                    goto __Vlabel19;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x31U;
                                    goto __Vlabel19;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x30U;
                                    goto __Vlabel19;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x2fU;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x48U;
                                goto __Vlabel19;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0x44U;
                            goto __Vlabel19;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                        goto __Vlabel19;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                        goto __Vlabel19;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                        goto __Vlabel19;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xcU;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xbU;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xaU;
                            goto __Vlabel19;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                            goto __Vlabel19;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 6U;
                                    goto __Vlabel19;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                    goto __Vlabel19;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                                goto __Vlabel19;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 5U;
                                goto __Vlabel19;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 4U;
                            goto __Vlabel19;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 3U;
                            goto __Vlabel19;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                        goto __Vlabel19;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 2U;
                            goto __Vlabel19;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 1U;
                            goto __Vlabel19;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__512__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0U;
                        goto __Vlabel19;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__512__Vfuncout = 0xf0U;
                        goto __Vlabel19;
                    }
                    __Vlabel19: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_internal_idx__512__Vfuncout))]);
    vlSymsp->TOP__Top__DOT__csr_renamer_port.mideleg_rdata 
        = (([&]() {
                vlSelfRef.__Vfunc_get_read_mask__513__csr_name = 0x303U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_mconfigptr_get_read_mask__514__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mconfigptr_get_read_mask__514__Vfuncout;
                                                goto __Vlabel20;
                                            } else {
                                                vlSelfRef.__Vfunc_mhartid_get_read_mask__515__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mhartid_get_read_mask__515__Vfuncout;
                                                goto __Vlabel20;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_mimpid_get_read_mask__516__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mimpid_get_read_mask__516__Vfuncout;
                                                goto __Vlabel20;
                                            } else {
                                                vlSelfRef.__Vfunc_marchid_get_read_mask__517__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_marchid_get_read_mask__517__Vfuncout;
                                                goto __Vlabel20;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_mvendorid_get_read_mask__518__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_mvendorid_get_read_mask__518__Vfuncout;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_scountovf_get_read_mask__519__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_scountovf_get_read_mask__519__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_vl_get_read_mask__520__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_vl_get_read_mask__520__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_vlenb_get_read_mask__521__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_vlenb_get_read_mask__521__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_vtype_get_read_mask__522__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_vtype_get_read_mask__522__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__523__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__523__Vfuncout;
                                goto __Vlabel20;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__524__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__524__Vfuncout;
                                goto __Vlabel20;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__525__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__525__Vfuncout;
                                goto __Vlabel20;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_hpmcounter_get_read_mask__526__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__526__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_instret_get_read_mask__527__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_instret_get_read_mask__527__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_time_get_read_mask__528__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_time_get_read_mask__528__Vfuncout;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_cycle_get_read_mask__529__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_cycle_get_read_mask__529__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__530__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__530__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__531__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__531__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__532__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__532__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__533__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__533__Vfuncout;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_minstret_get_read_mask__534__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_minstret_get_read_mask__534__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_mcycle_get_read_mask__535__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcycle_get_read_mask__535__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_dscratch_get_read_mask__536__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dscratch_get_read_mask__536__Vfuncout;
                                                goto __Vlabel20;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_dpc_get_read_mask__537__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dpc_get_read_mask__537__Vfuncout;
                                                goto __Vlabel20;
                                            } else {
                                                vlSelfRef.__Vfunc_dcsr_get_read_mask__538__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dcsr_get_read_mask__538__Vfuncout;
                                                goto __Vlabel20;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            } else {
                                                vlSelfRef.__Vfunc_mcontext_get_read_mask__539__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mcontext_get_read_mask__539__Vfuncout;
                                                goto __Vlabel20;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__540__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__540__Vfuncout;
                                            goto __Vlabel20;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__541__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__541__Vfuncout;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_tselect_get_read_mask__542__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_tselect_get_read_mask__542__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                                vlSelfRef.__Vfunc_mseccfg_get_read_mask__543__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mseccfg_get_read_mask__543__Vfuncout;
                                                goto __Vlabel20;
                                            } else {
                                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                                goto __Vlabel20;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_mnstatus_get_read_mask__544__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_mnstatus_get_read_mask__544__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_mncause_get_read_mask__545__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_mncause_get_read_mask__545__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_mnepc_get_read_mask__546__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnepc_get_read_mask__546__Vfuncout;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_mnscratch_get_read_mask__547__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnscratch_get_read_mask__547__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_scontext_get_read_mask__548__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_scontext_get_read_mask__548__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_pmpaddr_get_read_mask__549__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__549__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__550__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__550__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__551__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__551__Vfuncout;
                                        goto __Vlabel20;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_pmpcfg_get_read_mask__552__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpcfg_get_read_mask__552__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                            vlSelfRef.__Vfunc_mtval2_get_read_mask__553__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtval2_get_read_mask__553__Vfuncout;
                                            goto __Vlabel20;
                                        } else {
                                            vlSelfRef.__Vfunc_mtinst_get_read_mask__554__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtinst_get_read_mask__554__Vfuncout;
                                            goto __Vlabel20;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_mip_get_read_mask__555__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mip_get_read_mask__555__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_mtval_get_read_mask__556__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mtval_get_read_mask__556__Vfuncout;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_mcause_get_read_mask__557__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcause_get_read_mask__557__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mepc_get_read_mask__558__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mepc_get_read_mask__558__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_mscratch_get_read_mask__559__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mscratch_get_read_mask__559__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__560__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__560__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__561__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__561__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__562__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__562__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmevent_get_read_mask__563__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__563__Vfuncout;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else {
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__564__mask = 0;
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__564__mask_logic = 0;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask 
                                        = (0xffffffffULL 
                                           & vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask);
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask_logic 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__mask_logic;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__564__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mstateen_get_read_mask__565__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mstateen_get_read_mask__565__Vfuncout;
                                    goto __Vlabel20;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_menvcfg_get_read_mask__566__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_menvcfg_get_read_mask__566__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_mcounteren_get_read_mask__567__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcounteren_get_read_mask__567__Vfuncout;
                                        goto __Vlabel20;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mtvec_get_read_mask__568__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mtvec_get_read_mask__568__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_mie_get_read_mask__569__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mie_get_read_mask__569__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_mideleg_get_read_mask__570__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_mideleg_get_read_mask__570__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_medeleg_get_read_mask__571__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_medeleg_get_read_mask__571__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_misa_get_read_mask__572__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_misa_get_read_mask__572__Vfuncout;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_mstatus_get_read_mask__573__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_mstatus_get_read_mask__573__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_satp_get_read_mask__574__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_satp_get_read_mask__574__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                        vlSelfRef.__Vfunc_stimecmp_get_read_mask__575__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                            = vlSelfRef.__Vfunc_stimecmp_get_read_mask__575__Vfuncout;
                                        goto __Vlabel20;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                        goto __Vlabel20;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else {
                                    vlSelf->__Vfunc_sip_get_read_mask__576__mask = 0;
                                    vlSelf->__Vfunc_sip_get_read_mask__576__mask_csr = 0;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr 
                                        = (0x3ffULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr 
                                        = (0xfffffffffffffe3fULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr 
                                        = (0xffffffffffffffe3ULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr 
                                        = (0xfffffffffffffffeULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__mask 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__576__mask_csr;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__576__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__576__mask;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__576__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_stval_get_read_mask__577__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_stval_get_read_mask__577__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_scause_get_read_mask__578__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_scause_get_read_mask__578__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_sepc_get_read_mask__579__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_sepc_get_read_mask__579__Vfuncout;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_sscratch_get_read_mask__580__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_sscratch_get_read_mask__580__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else {
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__581__mask = 0;
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__581__mask_logic = 0;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask 
                                    = (0xffffffffULL 
                                       & vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask);
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask_logic 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__mask_logic;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__581__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_sstateen_get_read_mask__582__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_sstateen_get_read_mask__582__Vfuncout;
                                goto __Vlabel20;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_senvcfg_get_read_mask__583__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_senvcfg_get_read_mask__583__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_scounteren_get_read_mask__584__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_scounteren_get_read_mask__584__Vfuncout;
                                    goto __Vlabel20;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_stvec_get_read_mask__585__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_stvec_get_read_mask__585__Vfuncout;
                                goto __Vlabel20;
                            } else {
                                vlSelf->__Vfunc_sie_get_read_mask__586__mask = 0;
                                vlSelf->__Vfunc_sie_get_read_mask__586__mask_csr = 0;
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr 
                                    = (0x3fffULL & vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr 
                                    = (0xffffffffffffe3ffULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr 
                                    = (0xfffffffffffffe3fULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr 
                                    = (0xffffffffffffffe3ULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr 
                                    = (0xfffffffffffffffeULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__mask 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__586__mask_csr;
                                vlSelfRef.__Vfunc_sie_get_read_mask__586__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__586__mask;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__586__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        } else {
                            vlSelf->__Vfunc_sstatus_get_read_mask__587__mask_csr = 0;
                            vlSelf->__Vfunc_sstatus_get_read_mask__587__mask = 0;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0x80000003ffffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xffffffff01ffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xffffffffff8fffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xfffffffffffdffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xffffffffffffe7ffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xffffffffffffff7fULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xffffffffffffffe3ULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr 
                                = (0xfffffffffffffffeULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask_csr;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__587__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__587__mask;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__587__Vfuncout;
                            goto __Vlabel20;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                        goto __Vlabel20;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                        goto __Vlabel20;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                        goto __Vlabel20;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_jvt_get_read_mask__588__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_jvt_get_read_mask__588__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_seed_get_read_mask__589__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_seed_get_read_mask__589__Vfuncout;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_ssp_get_read_mask__590__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_ssp_get_read_mask__590__Vfuncout;
                            goto __Vlabel20;
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                            goto __Vlabel20;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                    vlSelfRef.__Vfunc_vcsr_get_read_mask__591__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                        = vlSelfRef.__Vfunc_vcsr_get_read_mask__591__Vfuncout;
                                    goto __Vlabel20;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                    goto __Vlabel20;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                                goto __Vlabel20;
                            } else {
                                vlSelfRef.__Vfunc_vxrm_get_read_mask__592__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                    = vlSelfRef.__Vfunc_vxrm_get_read_mask__592__Vfuncout;
                                goto __Vlabel20;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_vxsat_get_read_mask__593__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_vxsat_get_read_mask__593__Vfuncout;
                            goto __Vlabel20;
                        } else {
                            vlSelfRef.__Vfunc_vstart_get_read_mask__594__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_vstart_get_read_mask__594__Vfuncout;
                            goto __Vlabel20;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                        goto __Vlabel20;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                            vlSelfRef.__Vfunc_fcsr_get_read_mask__595__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_fcsr_get_read_mask__595__Vfuncout;
                            goto __Vlabel20;
                        } else {
                            vlSelfRef.__Vfunc_frm_get_read_mask__596__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                                = vlSelfRef.__Vfunc_frm_get_read_mask__596__Vfuncout;
                            goto __Vlabel20;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__513__csr_name))) {
                        vlSelfRef.__Vfunc_fflags_get_read_mask__597__Vfuncout = 0x1fULL;
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout 
                            = vlSelfRef.__Vfunc_fflags_get_read_mask__597__Vfuncout;
                        goto __Vlabel20;
                    } else {
                        vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout = 0ULL;
                        goto __Vlabel20;
                    }
                    __Vlabel20: ;
                }
            }(), vlSelfRef.__Vfunc_get_read_mask__513__Vfuncout) 
           & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
           [([&]() {
                vlSelfRef.__Vfunc_internal_idx__598__csr_name = 0x303U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x43U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x42U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x41U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x40U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3fU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x38U;
                                            goto __Vlabel21;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 7U;
                                        goto __Vlabel21;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 9U;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 8U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc2U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc1U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbfU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbeU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbdU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbcU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbbU;
                                        goto __Vlabel21;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbaU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb9U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb8U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb7U;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb6U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb5U;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb4U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb3U;
                                    goto __Vlabel21;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb2U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb1U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xafU;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xaeU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xadU;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xacU;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xabU;
                                    goto __Vlabel21;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xaaU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa9U;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa8U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa7U;
                                    goto __Vlabel21;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa6U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa5U;
                                    goto __Vlabel21;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xeU;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa4U;
                                goto __Vlabel21;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc2U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc1U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbfU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbeU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbdU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbcU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbbU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbaU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb9U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb8U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb7U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb6U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb5U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb4U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb3U;
                                        goto __Vlabel21;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb2U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb1U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xb0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xafU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xaeU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xadU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xacU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xabU;
                                        goto __Vlabel21;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xaaU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa9U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa8U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa7U;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa6U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa5U;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa4U;
                                    goto __Vlabel21;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe9U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe8U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe7U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe6U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe5U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe4U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe3U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe2U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe1U;
                                            goto __Vlabel21;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x53U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa3U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa2U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa1U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xa0U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3aU;
                                            goto __Vlabel21;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9bU;
                                                        goto __Vlabel21;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9aU;
                                                        goto __Vlabel21;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x99U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x98U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x97U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x96U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x95U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x94U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x93U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x92U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x91U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x90U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8fU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8eU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8dU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8cU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8bU;
                                                        goto __Vlabel21;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x8aU;
                                                        goto __Vlabel21;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x89U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x88U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x87U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x86U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x85U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x84U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x83U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x82U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x81U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x80U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7fU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7eU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7dU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7cU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7bU;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x7aU;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x79U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x78U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x77U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x76U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x75U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x74U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x73U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x72U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x71U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x70U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6fU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6eU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6dU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6cU;
                                        goto __Vlabel21;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6bU;
                                                        goto __Vlabel21;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x6aU;
                                                        goto __Vlabel21;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x69U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x68U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x67U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x66U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x65U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x64U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x63U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x62U;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x61U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x60U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5fU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5eU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5dU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5cU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5bU;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x5aU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x59U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x58U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x57U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x56U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x55U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x54U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x51U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x50U;
                                            goto __Vlabel21;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4fU;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4eU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4dU;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4cU;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4bU;
                                    goto __Vlabel21;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xe0U;
                                                    goto __Vlabel21;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xdfU;
                                                    goto __Vlabel21;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xdeU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xddU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xdcU;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xdbU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xdaU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd9U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd8U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd7U;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd6U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd5U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd4U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd3U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd2U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd1U;
                                        goto __Vlabel21;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xd0U;
                                                goto __Vlabel21;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xcfU;
                                                goto __Vlabel21;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xceU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xcdU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xccU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xcbU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xcaU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc9U;
                                        goto __Vlabel21;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc8U;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc7U;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc6U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc5U;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc4U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc3U;
                                    goto __Vlabel21;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9fU;
                                            goto __Vlabel21;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9eU;
                                            goto __Vlabel21;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9dU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x9cU;
                                        goto __Vlabel21;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x52U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4aU;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x49U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x48U;
                                    goto __Vlabel21;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x47U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x46U;
                                    goto __Vlabel21;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x45U;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x44U;
                                goto __Vlabel21;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x39U;
                                goto __Vlabel21;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xeaU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                        goto __Vlabel21;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x4fU;
                                    goto __Vlabel21;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x36U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x35U;
                                    goto __Vlabel21;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x34U;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x33U;
                                goto __Vlabel21;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xc3U;
                                goto __Vlabel21;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3eU;
                                        goto __Vlabel21;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3dU;
                                        goto __Vlabel21;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3cU;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x3bU;
                                    goto __Vlabel21;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x31U;
                                    goto __Vlabel21;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x30U;
                                    goto __Vlabel21;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x2fU;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x48U;
                                goto __Vlabel21;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0x44U;
                            goto __Vlabel21;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                        goto __Vlabel21;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                        goto __Vlabel21;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                        goto __Vlabel21;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xcU;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xbU;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xaU;
                            goto __Vlabel21;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                            goto __Vlabel21;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 6U;
                                    goto __Vlabel21;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                    goto __Vlabel21;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                                goto __Vlabel21;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 5U;
                                goto __Vlabel21;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 4U;
                            goto __Vlabel21;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 3U;
                            goto __Vlabel21;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                        goto __Vlabel21;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 2U;
                            goto __Vlabel21;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 1U;
                            goto __Vlabel21;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__598__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0U;
                        goto __Vlabel21;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__598__Vfuncout = 0xf0U;
                        goto __Vlabel21;
                    }
                    __Vlabel21: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_internal_idx__598__Vfuncout))]);
    vlSymsp->TOP__Top__DOT__csr_renamer_port.mie_rdata 
        = (([&]() {
                vlSelfRef.__Vfunc_get_read_mask__599__csr_name = 0x304U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_mconfigptr_get_read_mask__600__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mconfigptr_get_read_mask__600__Vfuncout;
                                                goto __Vlabel22;
                                            } else {
                                                vlSelfRef.__Vfunc_mhartid_get_read_mask__601__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mhartid_get_read_mask__601__Vfuncout;
                                                goto __Vlabel22;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_mimpid_get_read_mask__602__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mimpid_get_read_mask__602__Vfuncout;
                                                goto __Vlabel22;
                                            } else {
                                                vlSelfRef.__Vfunc_marchid_get_read_mask__603__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_marchid_get_read_mask__603__Vfuncout;
                                                goto __Vlabel22;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_mvendorid_get_read_mask__604__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_mvendorid_get_read_mask__604__Vfuncout;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_scountovf_get_read_mask__605__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_scountovf_get_read_mask__605__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_vl_get_read_mask__606__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_vl_get_read_mask__606__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_vlenb_get_read_mask__607__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_vlenb_get_read_mask__607__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_vtype_get_read_mask__608__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_vtype_get_read_mask__608__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__609__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__609__Vfuncout;
                                goto __Vlabel22;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__610__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__610__Vfuncout;
                                goto __Vlabel22;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__611__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__611__Vfuncout;
                                goto __Vlabel22;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_hpmcounter_get_read_mask__612__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__612__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_instret_get_read_mask__613__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_instret_get_read_mask__613__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_time_get_read_mask__614__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_time_get_read_mask__614__Vfuncout;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_cycle_get_read_mask__615__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_cycle_get_read_mask__615__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__616__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__616__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__617__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__617__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__618__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__618__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__619__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__619__Vfuncout;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_minstret_get_read_mask__620__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_minstret_get_read_mask__620__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_mcycle_get_read_mask__621__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcycle_get_read_mask__621__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_dscratch_get_read_mask__622__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dscratch_get_read_mask__622__Vfuncout;
                                                goto __Vlabel22;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_dpc_get_read_mask__623__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dpc_get_read_mask__623__Vfuncout;
                                                goto __Vlabel22;
                                            } else {
                                                vlSelfRef.__Vfunc_dcsr_get_read_mask__624__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dcsr_get_read_mask__624__Vfuncout;
                                                goto __Vlabel22;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            } else {
                                                vlSelfRef.__Vfunc_mcontext_get_read_mask__625__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mcontext_get_read_mask__625__Vfuncout;
                                                goto __Vlabel22;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__626__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__626__Vfuncout;
                                            goto __Vlabel22;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__627__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__627__Vfuncout;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_tselect_get_read_mask__628__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_tselect_get_read_mask__628__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                                vlSelfRef.__Vfunc_mseccfg_get_read_mask__629__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mseccfg_get_read_mask__629__Vfuncout;
                                                goto __Vlabel22;
                                            } else {
                                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                                goto __Vlabel22;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_mnstatus_get_read_mask__630__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_mnstatus_get_read_mask__630__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_mncause_get_read_mask__631__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_mncause_get_read_mask__631__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_mnepc_get_read_mask__632__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnepc_get_read_mask__632__Vfuncout;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_mnscratch_get_read_mask__633__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnscratch_get_read_mask__633__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_scontext_get_read_mask__634__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_scontext_get_read_mask__634__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_pmpaddr_get_read_mask__635__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__635__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__636__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__636__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__637__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__637__Vfuncout;
                                        goto __Vlabel22;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_pmpcfg_get_read_mask__638__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpcfg_get_read_mask__638__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                            vlSelfRef.__Vfunc_mtval2_get_read_mask__639__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtval2_get_read_mask__639__Vfuncout;
                                            goto __Vlabel22;
                                        } else {
                                            vlSelfRef.__Vfunc_mtinst_get_read_mask__640__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtinst_get_read_mask__640__Vfuncout;
                                            goto __Vlabel22;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_mip_get_read_mask__641__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mip_get_read_mask__641__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_mtval_get_read_mask__642__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mtval_get_read_mask__642__Vfuncout;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_mcause_get_read_mask__643__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcause_get_read_mask__643__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mepc_get_read_mask__644__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mepc_get_read_mask__644__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_mscratch_get_read_mask__645__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mscratch_get_read_mask__645__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__646__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__646__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__647__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__647__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__648__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__648__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmevent_get_read_mask__649__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__649__Vfuncout;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else {
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__650__mask = 0;
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__650__mask_logic = 0;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask 
                                        = (0xffffffffULL 
                                           & vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask);
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask_logic 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__mask_logic;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__650__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mstateen_get_read_mask__651__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mstateen_get_read_mask__651__Vfuncout;
                                    goto __Vlabel22;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_menvcfg_get_read_mask__652__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_menvcfg_get_read_mask__652__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_mcounteren_get_read_mask__653__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcounteren_get_read_mask__653__Vfuncout;
                                        goto __Vlabel22;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mtvec_get_read_mask__654__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mtvec_get_read_mask__654__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_mie_get_read_mask__655__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mie_get_read_mask__655__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_mideleg_get_read_mask__656__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_mideleg_get_read_mask__656__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_medeleg_get_read_mask__657__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_medeleg_get_read_mask__657__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_misa_get_read_mask__658__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_misa_get_read_mask__658__Vfuncout;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_mstatus_get_read_mask__659__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_mstatus_get_read_mask__659__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_satp_get_read_mask__660__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_satp_get_read_mask__660__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                        vlSelfRef.__Vfunc_stimecmp_get_read_mask__661__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                            = vlSelfRef.__Vfunc_stimecmp_get_read_mask__661__Vfuncout;
                                        goto __Vlabel22;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                        goto __Vlabel22;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else {
                                    vlSelf->__Vfunc_sip_get_read_mask__662__mask = 0;
                                    vlSelf->__Vfunc_sip_get_read_mask__662__mask_csr = 0;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr 
                                        = (0x3ffULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr 
                                        = (0xfffffffffffffe3fULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr 
                                        = (0xffffffffffffffe3ULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr 
                                        = (0xfffffffffffffffeULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__mask 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__662__mask_csr;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__662__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__662__mask;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__662__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_stval_get_read_mask__663__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_stval_get_read_mask__663__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_scause_get_read_mask__664__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_scause_get_read_mask__664__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_sepc_get_read_mask__665__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_sepc_get_read_mask__665__Vfuncout;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_sscratch_get_read_mask__666__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_sscratch_get_read_mask__666__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else {
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__667__mask = 0;
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__667__mask_logic = 0;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask 
                                    = (0xffffffffULL 
                                       & vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask);
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask_logic 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__mask_logic;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__667__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_sstateen_get_read_mask__668__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_sstateen_get_read_mask__668__Vfuncout;
                                goto __Vlabel22;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_senvcfg_get_read_mask__669__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_senvcfg_get_read_mask__669__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_scounteren_get_read_mask__670__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_scounteren_get_read_mask__670__Vfuncout;
                                    goto __Vlabel22;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_stvec_get_read_mask__671__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_stvec_get_read_mask__671__Vfuncout;
                                goto __Vlabel22;
                            } else {
                                vlSelf->__Vfunc_sie_get_read_mask__672__mask = 0;
                                vlSelf->__Vfunc_sie_get_read_mask__672__mask_csr = 0;
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr 
                                    = (0x3fffULL & vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr 
                                    = (0xffffffffffffe3ffULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr 
                                    = (0xfffffffffffffe3fULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr 
                                    = (0xffffffffffffffe3ULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr 
                                    = (0xfffffffffffffffeULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__mask 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__672__mask_csr;
                                vlSelfRef.__Vfunc_sie_get_read_mask__672__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__672__mask;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__672__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        } else {
                            vlSelf->__Vfunc_sstatus_get_read_mask__673__mask_csr = 0;
                            vlSelf->__Vfunc_sstatus_get_read_mask__673__mask = 0;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0x80000003ffffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xffffffff01ffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xffffffffff8fffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xfffffffffffdffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xffffffffffffe7ffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xffffffffffffff7fULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xffffffffffffffe3ULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr 
                                = (0xfffffffffffffffeULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask_csr;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__673__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__673__mask;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__673__Vfuncout;
                            goto __Vlabel22;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                        goto __Vlabel22;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                        goto __Vlabel22;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                        goto __Vlabel22;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_jvt_get_read_mask__674__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_jvt_get_read_mask__674__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_seed_get_read_mask__675__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_seed_get_read_mask__675__Vfuncout;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_ssp_get_read_mask__676__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_ssp_get_read_mask__676__Vfuncout;
                            goto __Vlabel22;
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                            goto __Vlabel22;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                    vlSelfRef.__Vfunc_vcsr_get_read_mask__677__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                        = vlSelfRef.__Vfunc_vcsr_get_read_mask__677__Vfuncout;
                                    goto __Vlabel22;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                    goto __Vlabel22;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                                goto __Vlabel22;
                            } else {
                                vlSelfRef.__Vfunc_vxrm_get_read_mask__678__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                    = vlSelfRef.__Vfunc_vxrm_get_read_mask__678__Vfuncout;
                                goto __Vlabel22;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_vxsat_get_read_mask__679__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_vxsat_get_read_mask__679__Vfuncout;
                            goto __Vlabel22;
                        } else {
                            vlSelfRef.__Vfunc_vstart_get_read_mask__680__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_vstart_get_read_mask__680__Vfuncout;
                            goto __Vlabel22;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                        goto __Vlabel22;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                            vlSelfRef.__Vfunc_fcsr_get_read_mask__681__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_fcsr_get_read_mask__681__Vfuncout;
                            goto __Vlabel22;
                        } else {
                            vlSelfRef.__Vfunc_frm_get_read_mask__682__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                                = vlSelfRef.__Vfunc_frm_get_read_mask__682__Vfuncout;
                            goto __Vlabel22;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__599__csr_name))) {
                        vlSelfRef.__Vfunc_fflags_get_read_mask__683__Vfuncout = 0x1fULL;
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout 
                            = vlSelfRef.__Vfunc_fflags_get_read_mask__683__Vfuncout;
                        goto __Vlabel22;
                    } else {
                        vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout = 0ULL;
                        goto __Vlabel22;
                    }
                    __Vlabel22: ;
                }
            }(), vlSelfRef.__Vfunc_get_read_mask__599__Vfuncout) 
           & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
           [([&]() {
                vlSelfRef.__Vfunc_internal_idx__684__csr_name = 0x304U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x43U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x42U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x41U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x40U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3fU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x38U;
                                            goto __Vlabel23;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 7U;
                                        goto __Vlabel23;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 9U;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 8U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc2U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc1U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbfU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbeU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbdU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbcU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbbU;
                                        goto __Vlabel23;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbaU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb9U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb8U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb7U;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb6U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb5U;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb4U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb3U;
                                    goto __Vlabel23;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb2U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb1U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xafU;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xaeU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xadU;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xacU;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xabU;
                                    goto __Vlabel23;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xaaU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa9U;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa8U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa7U;
                                    goto __Vlabel23;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa6U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa5U;
                                    goto __Vlabel23;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xeU;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa4U;
                                goto __Vlabel23;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc2U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc1U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbfU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbeU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbdU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbcU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbbU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbaU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb9U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb8U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb7U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb6U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb5U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb4U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb3U;
                                        goto __Vlabel23;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb2U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb1U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xb0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xafU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xaeU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xadU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xacU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xabU;
                                        goto __Vlabel23;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xaaU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa9U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa8U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa7U;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa6U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa5U;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa4U;
                                    goto __Vlabel23;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe9U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe8U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe7U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe6U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe5U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe4U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe3U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe2U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe1U;
                                            goto __Vlabel23;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x53U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa3U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa2U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa1U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xa0U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3aU;
                                            goto __Vlabel23;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9bU;
                                                        goto __Vlabel23;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9aU;
                                                        goto __Vlabel23;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x99U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x98U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x97U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x96U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x95U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x94U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x93U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x92U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x91U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x90U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8fU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8eU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8dU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8cU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8bU;
                                                        goto __Vlabel23;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x8aU;
                                                        goto __Vlabel23;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x89U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x88U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x87U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x86U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x85U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x84U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x83U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x82U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x81U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x80U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7fU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7eU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7dU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7cU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7bU;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x7aU;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x79U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x78U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x77U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x76U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x75U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x74U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x73U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x72U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x71U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x70U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6fU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6eU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6dU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6cU;
                                        goto __Vlabel23;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6bU;
                                                        goto __Vlabel23;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x6aU;
                                                        goto __Vlabel23;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x69U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x68U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x67U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x66U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x65U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x64U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x63U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x62U;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x61U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x60U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5fU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5eU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5dU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5cU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5bU;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x5aU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x59U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x58U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x57U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x56U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x55U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x54U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x51U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x50U;
                                            goto __Vlabel23;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4fU;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4eU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4dU;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4cU;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4bU;
                                    goto __Vlabel23;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xe0U;
                                                    goto __Vlabel23;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xdfU;
                                                    goto __Vlabel23;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xdeU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xddU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xdcU;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xdbU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xdaU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd9U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd8U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd7U;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd6U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd5U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd4U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd3U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd2U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd1U;
                                        goto __Vlabel23;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xd0U;
                                                goto __Vlabel23;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xcfU;
                                                goto __Vlabel23;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xceU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xcdU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xccU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xcbU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xcaU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc9U;
                                        goto __Vlabel23;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc8U;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc7U;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc6U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc5U;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc4U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc3U;
                                    goto __Vlabel23;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9fU;
                                            goto __Vlabel23;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9eU;
                                            goto __Vlabel23;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9dU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x9cU;
                                        goto __Vlabel23;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x52U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4aU;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x49U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x48U;
                                    goto __Vlabel23;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x47U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x46U;
                                    goto __Vlabel23;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x45U;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x44U;
                                goto __Vlabel23;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x39U;
                                goto __Vlabel23;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xeaU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                        goto __Vlabel23;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x4fU;
                                    goto __Vlabel23;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x36U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x35U;
                                    goto __Vlabel23;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x34U;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x33U;
                                goto __Vlabel23;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xc3U;
                                goto __Vlabel23;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3eU;
                                        goto __Vlabel23;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3dU;
                                        goto __Vlabel23;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3cU;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x3bU;
                                    goto __Vlabel23;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x31U;
                                    goto __Vlabel23;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x30U;
                                    goto __Vlabel23;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x2fU;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x48U;
                                goto __Vlabel23;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0x44U;
                            goto __Vlabel23;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                        goto __Vlabel23;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                        goto __Vlabel23;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                        goto __Vlabel23;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xcU;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xbU;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xaU;
                            goto __Vlabel23;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                            goto __Vlabel23;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 6U;
                                    goto __Vlabel23;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                    goto __Vlabel23;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                                goto __Vlabel23;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 5U;
                                goto __Vlabel23;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 4U;
                            goto __Vlabel23;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 3U;
                            goto __Vlabel23;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                        goto __Vlabel23;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 2U;
                            goto __Vlabel23;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 1U;
                            goto __Vlabel23;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__684__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0U;
                        goto __Vlabel23;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__684__Vfuncout = 0xf0U;
                        goto __Vlabel23;
                    }
                    __Vlabel23: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_internal_idx__684__Vfuncout))]);
    vlSymsp->TOP__Top__DOT__csr_renamer_port.mip_rdata 
        = (([&]() {
                vlSelfRef.__Vfunc_get_read_mask__685__csr_name = 0x344U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_mconfigptr_get_read_mask__686__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mconfigptr_get_read_mask__686__Vfuncout;
                                                goto __Vlabel24;
                                            } else {
                                                vlSelfRef.__Vfunc_mhartid_get_read_mask__687__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mhartid_get_read_mask__687__Vfuncout;
                                                goto __Vlabel24;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_mimpid_get_read_mask__688__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mimpid_get_read_mask__688__Vfuncout;
                                                goto __Vlabel24;
                                            } else {
                                                vlSelfRef.__Vfunc_marchid_get_read_mask__689__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_marchid_get_read_mask__689__Vfuncout;
                                                goto __Vlabel24;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_mvendorid_get_read_mask__690__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_mvendorid_get_read_mask__690__Vfuncout;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_scountovf_get_read_mask__691__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_scountovf_get_read_mask__691__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_vl_get_read_mask__692__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_vl_get_read_mask__692__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_vlenb_get_read_mask__693__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_vlenb_get_read_mask__693__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_vtype_get_read_mask__694__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_vtype_get_read_mask__694__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__695__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__695__Vfuncout;
                                goto __Vlabel24;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__696__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__696__Vfuncout;
                                goto __Vlabel24;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_hpmcounter_get_read_mask__697__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__697__Vfuncout;
                                goto __Vlabel24;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_hpmcounter_get_read_mask__698__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_hpmcounter_get_read_mask__698__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_instret_get_read_mask__699__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_instret_get_read_mask__699__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_time_get_read_mask__700__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_time_get_read_mask__700__Vfuncout;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_cycle_get_read_mask__701__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_cycle_get_read_mask__701__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__702__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__702__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__703__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__703__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__704__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__704__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__705__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmcounter_get_read_mask__705__Vfuncout;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_minstret_get_read_mask__706__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_minstret_get_read_mask__706__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_mcycle_get_read_mask__707__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcycle_get_read_mask__707__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_dscratch_get_read_mask__708__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dscratch_get_read_mask__708__Vfuncout;
                                                goto __Vlabel24;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_dpc_get_read_mask__709__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dpc_get_read_mask__709__Vfuncout;
                                                goto __Vlabel24;
                                            } else {
                                                vlSelfRef.__Vfunc_dcsr_get_read_mask__710__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_dcsr_get_read_mask__710__Vfuncout;
                                                goto __Vlabel24;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            } else {
                                                vlSelfRef.__Vfunc_mcontext_get_read_mask__711__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mcontext_get_read_mask__711__Vfuncout;
                                                goto __Vlabel24;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__712__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__712__Vfuncout;
                                            goto __Vlabel24;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_tdata_get_read_mask__713__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_tdata_get_read_mask__713__Vfuncout;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_tselect_get_read_mask__714__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_tselect_get_read_mask__714__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                                vlSelfRef.__Vfunc_mseccfg_get_read_mask__715__Vfuncout = 0xffffffffffffffffULL;
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                    = vlSelfRef.__Vfunc_mseccfg_get_read_mask__715__Vfuncout;
                                                goto __Vlabel24;
                                            } else {
                                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                                goto __Vlabel24;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_mnstatus_get_read_mask__716__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_mnstatus_get_read_mask__716__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_mncause_get_read_mask__717__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_mncause_get_read_mask__717__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_mnepc_get_read_mask__718__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnepc_get_read_mask__718__Vfuncout;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_mnscratch_get_read_mask__719__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mnscratch_get_read_mask__719__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_scontext_get_read_mask__720__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_scontext_get_read_mask__720__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_pmpaddr_get_read_mask__721__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__721__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__722__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__722__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_pmpaddr_get_read_mask__723__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpaddr_get_read_mask__723__Vfuncout;
                                        goto __Vlabel24;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_pmpcfg_get_read_mask__724__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_pmpcfg_get_read_mask__724__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                            vlSelfRef.__Vfunc_mtval2_get_read_mask__725__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtval2_get_read_mask__725__Vfuncout;
                                            goto __Vlabel24;
                                        } else {
                                            vlSelfRef.__Vfunc_mtinst_get_read_mask__726__Vfuncout = 0xffffffffffffffffULL;
                                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                                = vlSelfRef.__Vfunc_mtinst_get_read_mask__726__Vfuncout;
                                            goto __Vlabel24;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_mip_get_read_mask__727__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mip_get_read_mask__727__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_mtval_get_read_mask__728__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mtval_get_read_mask__728__Vfuncout;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_mcause_get_read_mask__729__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcause_get_read_mask__729__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mepc_get_read_mask__730__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mepc_get_read_mask__730__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_mscratch_get_read_mask__731__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mscratch_get_read_mask__731__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__732__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__732__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__733__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__733__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mhpmevent_get_read_mask__734__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__734__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_mhpmevent_get_read_mask__735__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mhpmevent_get_read_mask__735__Vfuncout;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else {
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__736__mask = 0;
                                    vlSelf->__Vfunc_mcountinhibit_get_read_mask__736__mask_logic = 0;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask 
                                        = (0xffffffffULL 
                                           & vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask);
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask_logic 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask;
                                    vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__mask_logic;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mcountinhibit_get_read_mask__736__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mstateen_get_read_mask__737__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mstateen_get_read_mask__737__Vfuncout;
                                    goto __Vlabel24;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_menvcfg_get_read_mask__738__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_menvcfg_get_read_mask__738__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_mcounteren_get_read_mask__739__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_mcounteren_get_read_mask__739__Vfuncout;
                                        goto __Vlabel24;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mtvec_get_read_mask__740__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mtvec_get_read_mask__740__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_mie_get_read_mask__741__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mie_get_read_mask__741__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_mideleg_get_read_mask__742__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_mideleg_get_read_mask__742__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_medeleg_get_read_mask__743__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_medeleg_get_read_mask__743__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_misa_get_read_mask__744__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_misa_get_read_mask__744__Vfuncout;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_mstatus_get_read_mask__745__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_mstatus_get_read_mask__745__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_satp_get_read_mask__746__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_satp_get_read_mask__746__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                        vlSelfRef.__Vfunc_stimecmp_get_read_mask__747__Vfuncout = 0xffffffffffffffffULL;
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                            = vlSelfRef.__Vfunc_stimecmp_get_read_mask__747__Vfuncout;
                                        goto __Vlabel24;
                                    } else {
                                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                        goto __Vlabel24;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else {
                                    vlSelf->__Vfunc_sip_get_read_mask__748__mask = 0;
                                    vlSelf->__Vfunc_sip_get_read_mask__748__mask_csr = 0;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr 
                                        = (0x3ffULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr 
                                        = (0xfffffffffffffe3fULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr 
                                        = (0xffffffffffffffe3ULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr 
                                        = (0xfffffffffffffffeULL 
                                           & vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr);
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__mask 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__748__mask_csr;
                                    vlSelfRef.__Vfunc_sip_get_read_mask__748__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__748__mask;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_sip_get_read_mask__748__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_stval_get_read_mask__749__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_stval_get_read_mask__749__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_scause_get_read_mask__750__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_scause_get_read_mask__750__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_sepc_get_read_mask__751__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_sepc_get_read_mask__751__Vfuncout;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_sscratch_get_read_mask__752__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_sscratch_get_read_mask__752__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else {
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__753__mask = 0;
                                vlSelf->__Vfunc_scountinhibit_get_read_mask__753__mask_logic = 0;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask 
                                    = (0xffffffffULL 
                                       & vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask);
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask_logic 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask;
                                vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__mask_logic;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_scountinhibit_get_read_mask__753__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_sstateen_get_read_mask__754__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_sstateen_get_read_mask__754__Vfuncout;
                                goto __Vlabel24;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_senvcfg_get_read_mask__755__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_senvcfg_get_read_mask__755__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_scounteren_get_read_mask__756__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_scounteren_get_read_mask__756__Vfuncout;
                                    goto __Vlabel24;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_stvec_get_read_mask__757__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_stvec_get_read_mask__757__Vfuncout;
                                goto __Vlabel24;
                            } else {
                                vlSelf->__Vfunc_sie_get_read_mask__758__mask = 0;
                                vlSelf->__Vfunc_sie_get_read_mask__758__mask_csr = 0;
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr 
                                    = (0x3fffULL & vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr 
                                    = (0xffffffffffffe3ffULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr 
                                    = (0xfffffffffffffe3fULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr 
                                    = (0xffffffffffffffe3ULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr 
                                    = (0xfffffffffffffffeULL 
                                       & vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr);
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__mask 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__758__mask_csr;
                                vlSelfRef.__Vfunc_sie_get_read_mask__758__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__758__mask;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_sie_get_read_mask__758__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        } else {
                            vlSelf->__Vfunc_sstatus_get_read_mask__759__mask_csr = 0;
                            vlSelf->__Vfunc_sstatus_get_read_mask__759__mask = 0;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0x80000003ffffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xffffffff01ffffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xffffffffff8fffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xfffffffffffdffffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xffffffffffffe7ffULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xffffffffffffff7fULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xffffffffffffffe3ULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr 
                                = (0xfffffffffffffffeULL 
                                   & vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr);
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask_csr;
                            vlSelfRef.__Vfunc_sstatus_get_read_mask__759__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__759__mask;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_sstatus_get_read_mask__759__Vfuncout;
                            goto __Vlabel24;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                        goto __Vlabel24;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                        goto __Vlabel24;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                        goto __Vlabel24;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_jvt_get_read_mask__760__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_jvt_get_read_mask__760__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_seed_get_read_mask__761__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_seed_get_read_mask__761__Vfuncout;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_ssp_get_read_mask__762__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_ssp_get_read_mask__762__Vfuncout;
                            goto __Vlabel24;
                        } else {
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                            goto __Vlabel24;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                    vlSelfRef.__Vfunc_vcsr_get_read_mask__763__Vfuncout = 0xffffffffffffffffULL;
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                        = vlSelfRef.__Vfunc_vcsr_get_read_mask__763__Vfuncout;
                                    goto __Vlabel24;
                                } else {
                                    vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                    goto __Vlabel24;
                                }
                            } else {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                                goto __Vlabel24;
                            } else {
                                vlSelfRef.__Vfunc_vxrm_get_read_mask__764__Vfuncout = 0xffffffffffffffffULL;
                                vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                    = vlSelfRef.__Vfunc_vxrm_get_read_mask__764__Vfuncout;
                                goto __Vlabel24;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_vxsat_get_read_mask__765__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_vxsat_get_read_mask__765__Vfuncout;
                            goto __Vlabel24;
                        } else {
                            vlSelfRef.__Vfunc_vstart_get_read_mask__766__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_vstart_get_read_mask__766__Vfuncout;
                            goto __Vlabel24;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                        goto __Vlabel24;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                            vlSelfRef.__Vfunc_fcsr_get_read_mask__767__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_fcsr_get_read_mask__767__Vfuncout;
                            goto __Vlabel24;
                        } else {
                            vlSelfRef.__Vfunc_frm_get_read_mask__768__Vfuncout = 0xffffffffffffffffULL;
                            vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                                = vlSelfRef.__Vfunc_frm_get_read_mask__768__Vfuncout;
                            goto __Vlabel24;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_get_read_mask__685__csr_name))) {
                        vlSelfRef.__Vfunc_fflags_get_read_mask__769__Vfuncout = 0x1fULL;
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout 
                            = vlSelfRef.__Vfunc_fflags_get_read_mask__769__Vfuncout;
                        goto __Vlabel24;
                    } else {
                        vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout = 0ULL;
                        goto __Vlabel24;
                    }
                    __Vlabel24: ;
                }
            }(), vlSelfRef.__Vfunc_get_read_mask__685__Vfuncout) 
           & vlSelfRef.Top__DOT__csrrf__DOT__csr_regs
           [([&]() {
                vlSelfRef.__Vfunc_internal_idx__770__csr_name = 0x344U;
                {
                    if ((0x800U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x40U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x43U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x42U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x41U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x40U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3fU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x38U;
                                            goto __Vlabel25;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 7U;
                                        goto __Vlabel25;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 9U;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 8U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc2U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc1U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbfU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbeU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbdU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbcU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbbU;
                                        goto __Vlabel25;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbaU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb9U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb8U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb7U;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb6U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb5U;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb4U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb3U;
                                    goto __Vlabel25;
                                }
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb2U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb1U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xafU;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xaeU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xadU;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xacU;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xabU;
                                    goto __Vlabel25;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xaaU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa9U;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa8U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa7U;
                                    goto __Vlabel25;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa6U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa5U;
                                    goto __Vlabel25;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xeU;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa4U;
                                goto __Vlabel25;
                            }
                        } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc2U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc1U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbfU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbeU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbdU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbcU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbbU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbaU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb9U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb8U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb7U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb6U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb5U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb4U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb3U;
                                        goto __Vlabel25;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb2U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb1U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xb0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xafU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xaeU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xadU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xacU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xabU;
                                        goto __Vlabel25;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xaaU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa9U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa8U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa7U;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa6U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa5U;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa4U;
                                    goto __Vlabel25;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        }
                    } else if ((0x400U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x20U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((8U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe9U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe8U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe7U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe6U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe5U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe4U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe3U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe2U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe1U;
                                            goto __Vlabel25;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x53U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa3U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa2U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa1U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xa0U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3aU;
                                            goto __Vlabel25;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        }
                    } else if ((0x200U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((0x10U 
                                             & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9bU;
                                                        goto __Vlabel25;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9aU;
                                                        goto __Vlabel25;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x99U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x98U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x97U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x96U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x95U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x94U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x93U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x92U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x91U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x90U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8fU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8eU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8dU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8cU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((0x10U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8bU;
                                                        goto __Vlabel25;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x8aU;
                                                        goto __Vlabel25;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x89U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x88U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x87U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x86U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x85U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x84U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x83U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x82U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x81U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x80U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7fU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7eU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7dU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7cU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7bU;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x7aU;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x79U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x78U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x77U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x76U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x75U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x74U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x73U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x72U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x71U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x70U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6fU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6eU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6dU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6cU;
                                        goto __Vlabel25;
                                    }
                                } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((4U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6bU;
                                                        goto __Vlabel25;
                                                    } else {
                                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x6aU;
                                                        goto __Vlabel25;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x69U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x68U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x67U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x66U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x65U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x64U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x63U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x62U;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x61U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x60U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5fU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5eU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5dU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5cU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5bU;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x5aU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x59U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x58U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x57U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x56U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x55U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x54U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x51U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x50U;
                                            goto __Vlabel25;
                                        }
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4fU;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4eU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4dU;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4cU;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4bU;
                                    goto __Vlabel25;
                                }
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((2U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xe0U;
                                                    goto __Vlabel25;
                                                } else {
                                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xdfU;
                                                    goto __Vlabel25;
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xdeU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xddU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xdcU;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xdbU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xdaU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd9U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd8U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd7U;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd6U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd5U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd4U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd3U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd2U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd1U;
                                        goto __Vlabel25;
                                    }
                                } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xd0U;
                                                goto __Vlabel25;
                                            } else {
                                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xcfU;
                                                goto __Vlabel25;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xceU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xcdU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xccU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xcbU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xcaU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc9U;
                                        goto __Vlabel25;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc8U;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc7U;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc6U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc5U;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc4U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc3U;
                                    goto __Vlabel25;
                                }
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9fU;
                                            goto __Vlabel25;
                                        } else {
                                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9eU;
                                            goto __Vlabel25;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9dU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x9cU;
                                        goto __Vlabel25;
                                    }
                                } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x52U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4aU;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x49U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x48U;
                                    goto __Vlabel25;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x47U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x46U;
                                    goto __Vlabel25;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x45U;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x44U;
                                goto __Vlabel25;
                            }
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        }
                    } else if ((0x100U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x39U;
                                goto __Vlabel25;
                            }
                        } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xeaU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                        goto __Vlabel25;
                                    }
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x4fU;
                                    goto __Vlabel25;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x36U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x35U;
                                    goto __Vlabel25;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x34U;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x33U;
                                goto __Vlabel25;
                            }
                        } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xc3U;
                                goto __Vlabel25;
                            }
                        } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3eU;
                                        goto __Vlabel25;
                                    } else {
                                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3dU;
                                        goto __Vlabel25;
                                    }
                                } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3cU;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x3bU;
                                    goto __Vlabel25;
                                }
                            } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x31U;
                                    goto __Vlabel25;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x30U;
                                    goto __Vlabel25;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x2fU;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x48U;
                                goto __Vlabel25;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0x44U;
                            goto __Vlabel25;
                        }
                    } else if ((0x80U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                        goto __Vlabel25;
                    } else if ((0x40U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                        goto __Vlabel25;
                    } else if ((0x20U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                        goto __Vlabel25;
                    } else if ((0x10U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xcU;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xbU;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xaU;
                            goto __Vlabel25;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                            goto __Vlabel25;
                        }
                    } else if ((8U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 6U;
                                    goto __Vlabel25;
                                } else {
                                    vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                    goto __Vlabel25;
                                }
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            }
                        } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                                goto __Vlabel25;
                            } else {
                                vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 5U;
                                goto __Vlabel25;
                            }
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 4U;
                            goto __Vlabel25;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 3U;
                            goto __Vlabel25;
                        }
                    } else if ((4U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                        goto __Vlabel25;
                    } else if ((2U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 2U;
                            goto __Vlabel25;
                        } else {
                            vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 1U;
                            goto __Vlabel25;
                        }
                    } else if ((1U & (IData)(vlSelfRef.__Vfunc_internal_idx__770__csr_name))) {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0U;
                        goto __Vlabel25;
                    } else {
                        vlSelfRef.__Vfunc_internal_idx__770__Vfuncout = 0xf0U;
                        goto __Vlabel25;
                    }
                    __Vlabel25: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_internal_idx__770__Vfuncout))]);
}
