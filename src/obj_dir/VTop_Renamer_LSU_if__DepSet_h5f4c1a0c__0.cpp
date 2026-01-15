// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop_Renamer_LSU_if.h"

std::string VL_TO_STRING(const VTop_Renamer_LSU_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VTop_Renamer_LSU_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
