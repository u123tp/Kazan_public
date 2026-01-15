// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop__pch.h"
#include "VTop___024unit.h"

VL_ATTR_COLD void VTop___024unit___ctor_var_reset(VTop___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  VTop___024unit___ctor_var_reset\n"); );
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__Venumtab_enum_name151.atDefault() = std::string{};
    vlSelf->__Venumtab_enum_name151.at(0) = std::string{"NOP"};
    vlSelf->__Venumtab_enum_name151.at(1) = std::string{"ADD"};
    vlSelf->__Venumtab_enum_name151.at(2) = std::string{"SUB"};
    vlSelf->__Venumtab_enum_name151.at(3) = std::string{"SLL"};
    vlSelf->__Venumtab_enum_name151.at(4) = std::string{"SLT"};
    vlSelf->__Venumtab_enum_name151.at(5) = std::string{"OR"};
    vlSelf->__Venumtab_enum_name151.at(6) = std::string{"AND"};
    vlSelf->__Venumtab_enum_name151.at(7) = std::string{"XOR"};
    vlSelf->__Venumtab_enum_name151.at(8) = std::string{"SRL"};
    vlSelf->__Venumtab_enum_name151.at(9) = std::string{"SRA"};
    vlSelf->__Venumtab_enum_name151.at(10) = std::string{"SLTU"};
    vlSelf->__Venumtab_enum_name151.at(11) = std::string{"ADDW"};
    vlSelf->__Venumtab_enum_name151.at(12) = std::string{"SUBW"};
    vlSelf->__Venumtab_enum_name151.at(13) = std::string{"SLLW"};
    vlSelf->__Venumtab_enum_name151.at(14) = std::string{"SRLW"};
    vlSelf->__Venumtab_enum_name151.at(15) = std::string{"SRAW"};
    vlSelf->__Venumtab_enum_name151.at(16) = std::string{"ADDI"};
    vlSelf->__Venumtab_enum_name151.at(17) = std::string{"SLTI"};
    vlSelf->__Venumtab_enum_name151.at(18) = std::string{"SLTIU"};
    vlSelf->__Venumtab_enum_name151.at(19) = std::string{"XORI"};
    vlSelf->__Venumtab_enum_name151.at(20) = std::string{"ORI"};
    vlSelf->__Venumtab_enum_name151.at(21) = std::string{"ANDI"};
    vlSelf->__Venumtab_enum_name151.at(22) = std::string{"SLLI"};
    vlSelf->__Venumtab_enum_name151.at(23) = std::string{"SRLI"};
    vlSelf->__Venumtab_enum_name151.at(24) = std::string{"SRAI"};
    vlSelf->__Venumtab_enum_name151.at(25) = std::string{"SRAIW"};
    vlSelf->__Venumtab_enum_name151.at(26) = std::string{"ADDIW"};
    vlSelf->__Venumtab_enum_name151.at(27) = std::string{"SLLIW"};
    vlSelf->__Venumtab_enum_name151.at(28) = std::string{"SRLIW"};
    vlSelf->__Venumtab_enum_name151.at(29) = std::string{"LB"};
    vlSelf->__Venumtab_enum_name151.at(30) = std::string{"LH"};
    vlSelf->__Venumtab_enum_name151.at(31) = std::string{"LW"};
    vlSelf->__Venumtab_enum_name151.at(32) = std::string{"LD"};
    vlSelf->__Venumtab_enum_name151.at(33) = std::string{"LBU"};
    vlSelf->__Venumtab_enum_name151.at(34) = std::string{"LHU"};
    vlSelf->__Venumtab_enum_name151.at(35) = std::string{"LWU"};
    vlSelf->__Venumtab_enum_name151.at(36) = std::string{"SB"};
    vlSelf->__Venumtab_enum_name151.at(37) = std::string{"SH"};
    vlSelf->__Venumtab_enum_name151.at(38) = std::string{"SW"};
    vlSelf->__Venumtab_enum_name151.at(39) = std::string{"SD"};
    vlSelf->__Venumtab_enum_name151.at(40) = std::string{"BEQ"};
    vlSelf->__Venumtab_enum_name151.at(41) = std::string{"BNE"};
    vlSelf->__Venumtab_enum_name151.at(42) = std::string{"BLT"};
    vlSelf->__Venumtab_enum_name151.at(43) = std::string{"BGE"};
    vlSelf->__Venumtab_enum_name151.at(44) = std::string{"BLTU"};
    vlSelf->__Venumtab_enum_name151.at(45) = std::string{"BGEU"};
    vlSelf->__Venumtab_enum_name151.at(46) = std::string{"JAL"};
    vlSelf->__Venumtab_enum_name151.at(47) = std::string{"JALR"};
    vlSelf->__Venumtab_enum_name151.at(48) = std::string{"LUI"};
    vlSelf->__Venumtab_enum_name151.at(49) = std::string{"AUIPC"};
    vlSelf->__Venumtab_enum_name151.at(50) = std::string{"FENCE"};
    vlSelf->__Venumtab_enum_name151.at(51) = std::string{"FENCE_TSO"};
    vlSelf->__Venumtab_enum_name151.at(52) = std::string{"PAUSE"};
    vlSelf->__Venumtab_enum_name151.at(53) = std::string{"ECALL"};
    vlSelf->__Venumtab_enum_name151.at(54) = std::string{"EBREAK"};
    vlSelf->__Venumtab_enum_name151.at(55) = std::string{"FENCE_I"};
    vlSelf->__Venumtab_enum_name151.at(56) = std::string{"CSRRW"};
    vlSelf->__Venumtab_enum_name151.at(57) = std::string{"CSRRS"};
    vlSelf->__Venumtab_enum_name151.at(58) = std::string{"CSRRC"};
    vlSelf->__Venumtab_enum_name151.at(59) = std::string{"CSRRWI"};
    vlSelf->__Venumtab_enum_name151.at(60) = std::string{"CSRRSI"};
    vlSelf->__Venumtab_enum_name151.at(61) = std::string{"CSRRCI"};
    vlSelf->__Venumtab_enum_name151.at(62) = std::string{"MUL"};
    vlSelf->__Venumtab_enum_name151.at(63) = std::string{"MULH"};
    vlSelf->__Venumtab_enum_name151.at(64) = std::string{"MULHSU"};
    vlSelf->__Venumtab_enum_name151.at(65) = std::string{"MULHU"};
    vlSelf->__Venumtab_enum_name151.at(66) = std::string{"DIV"};
    vlSelf->__Venumtab_enum_name151.at(67) = std::string{"DIVU"};
    vlSelf->__Venumtab_enum_name151.at(68) = std::string{"REM"};
    vlSelf->__Venumtab_enum_name151.at(69) = std::string{"REMU"};
    vlSelf->__Venumtab_enum_name151.at(70) = std::string{"MULW"};
    vlSelf->__Venumtab_enum_name151.at(71) = std::string{"DIVW"};
    vlSelf->__Venumtab_enum_name151.at(72) = std::string{"DIVUW"};
    vlSelf->__Venumtab_enum_name151.at(73) = std::string{"REMW"};
    vlSelf->__Venumtab_enum_name151.at(74) = std::string{"REMUW"};
    vlSelf->__Venumtab_enum_name151.at(75) = std::string{"LR_W"};
    vlSelf->__Venumtab_enum_name151.at(76) = std::string{"SC_W"};
    vlSelf->__Venumtab_enum_name151.at(77) = std::string{"AMOSWAP_W"};
    vlSelf->__Venumtab_enum_name151.at(78) = std::string{"AMOADD_W"};
    vlSelf->__Venumtab_enum_name151.at(79) = std::string{"AMOXOR_W"};
    vlSelf->__Venumtab_enum_name151.at(80) = std::string{"AMOAND_W"};
    vlSelf->__Venumtab_enum_name151.at(81) = std::string{"AMOOR_W"};
    vlSelf->__Venumtab_enum_name151.at(82) = std::string{"AMOMIN_W"};
    vlSelf->__Venumtab_enum_name151.at(83) = std::string{"AMOMAX_W"};
    vlSelf->__Venumtab_enum_name151.at(84) = std::string{"AMOMINU_W"};
    vlSelf->__Venumtab_enum_name151.at(85) = std::string{"AMOMAXU_W"};
    vlSelf->__Venumtab_enum_name151.at(86) = std::string{"LR_D"};
    vlSelf->__Venumtab_enum_name151.at(87) = std::string{"SC_D"};
    vlSelf->__Venumtab_enum_name151.at(88) = std::string{"AMOSWAP_D"};
    vlSelf->__Venumtab_enum_name151.at(89) = std::string{"AMOADD_D"};
    vlSelf->__Venumtab_enum_name151.at(90) = std::string{"AMOXOR_D"};
    vlSelf->__Venumtab_enum_name151.at(91) = std::string{"AMOAND_D"};
    vlSelf->__Venumtab_enum_name151.at(92) = std::string{"AMOOR_D"};
    vlSelf->__Venumtab_enum_name151.at(93) = std::string{"AMOMIN_D"};
    vlSelf->__Venumtab_enum_name151.at(94) = std::string{"AMOMAX_D"};
    vlSelf->__Venumtab_enum_name151.at(95) = std::string{"AMOMINU_D"};
    vlSelf->__Venumtab_enum_name151.at(96) = std::string{"AMOMAXU_D"};
    vlSelf->__Venumtab_enum_name151.at(97) = std::string{"MRET"};
    vlSelf->__Venumtab_enum_name151.at(98) = std::string{"SRET"};
    vlSelf->__Venumtab_enum_name151.at(99) = std::string{"WFI"};
    vlSelf->__Venumtab_enum_name151.at(100) = std::string{"SFENCE_VMA"};
    vlSelf->__Venumtab_enum_name151.at(101) = std::string{"ILLEGAL_INSTR"};
    for (int __Vi = 0; __Vi < 4; ++__Vi) {
        vlSelf->__Venumtab_enum_name153[__Vi] = std::string{};
    }
    vlSelf->__Venumtab_enum_name153[0] = std::string{"U_MODE"};
    vlSelf->__Venumtab_enum_name153[1] = std::string{"S_MODE"};
    vlSelf->__Venumtab_enum_name153[3] = std::string{"M_MODE"};
}
