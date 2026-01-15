// CSR(The RISC-V Instruction Set Manual:Volume II 20250508)
// ハイパーバイザのCSR(上記資料p17)は実装していない.
//
// csr_name_eでは命令上で用いられるcsrのエンコーディングとcsr名を対応させ,
// internal_idx函数でそのエンコーディングやcsr名から,内部レジスタで扱えるように,そのcsrに対応する連番になったインデックスを返す.
// また,それぞれのインデックスから値を読み出したり代入したりする際は,変数名.as_CSR名 としてアクセスする.
// 変数名.as_uint としてビット列としてアクセスすることもできる.
// 変数名.as_csr名 でアクセスしたばあい,csr内部のそれぞれのフィールドに 変数名.as_csr名.フィールド名 でアクセスできる.
`include "COMMON_PARAMS.svh"

`ifndef CSR_DEFS_IFDEF
`define CSR_DEFS_IFDEF

package CSR_PROPS;
  import COMMON_PARAMS::*;

  typedef enum logic [11:0] {
    // Unprivileged Floating-Point CSRs
    // FPUで発生した例外を示す.
    FFLAGS = 12'h001,
    FRM    = 12'h002,
    FCSR   = 12'h003,

    // Unprivileged Vector CSRs
    // ベクトル拡張用
    VSTART = 12'h008,
    VXSAT  = 12'h009,
    VXRM   = 12'h00A,
    VCSR   = 12'h00F,
    VL     = 12'hC30,
    VTYPE  = 12'hC21,
    VLENB  = 12'hC22,

    //Unprivileged ZICFISS Extension CSR
    SSP = 12'h011,

    // Unprivileged Entropy Source Extension CSR
    // 乱数生成用のシード.
    // 使用しない.
    SEED = 12'h015,

    // Unprivileged ZCMT Extension CSR
    // compressed jump table 拡張用.
    // c命令関係無いので使用しない.
    JVT = 12'h017,

    // Unprivileged Counter/Timers
    CYCLE        = 12'hC00,
    TIME         = 12'hC01,
    INSTRET      = 12'hC02,
    HPMCOUNTER3  = 12'hC03,
    HPMCOUNTER4  = 12'hC04,
    HPMCOUNTER5  = 12'hC05,
    HPMCOUNTER6  = 12'hC06,
    HPMCOUNTER7  = 12'hC07,
    HPMCOUNTER8  = 12'hC08,
    HPMCOUNTER9  = 12'hC09,
    HPMCOUNTER10 = 12'hC0A,
    HPMCOUNTER11 = 12'hC0B,
    HPMCOUNTER12 = 12'hC0C,
    HPMCOUNTER13 = 12'hC0D,
    HPMCOUNTER14 = 12'hC0E,
    HPMCOUNTER15 = 12'hC0F,
    HPMCOUNTER16 = 12'hC10,
    HPMCOUNTER17 = 12'hC11,
    HPMCOUNTER18 = 12'hC12,
    HPMCOUNTER19 = 12'hC13,
    HPMCOUNTER20 = 12'hC14,
    HPMCOUNTER21 = 12'hC15,
    HPMCOUNTER22 = 12'hC16,
    HPMCOUNTER23 = 12'hC17,
    HPMCOUNTER24 = 12'hC18,
    HPMCOUNTER25 = 12'hC19,
    HPMCOUNTER26 = 12'hC1A,
    HPMCOUNTER27 = 12'hC1B,
    HPMCOUNTER28 = 12'hC1C,
    HPMCOUNTER29 = 12'hC1D,
    HPMCOUNTER30 = 12'hC1E,
    HPMCOUNTER31 = 12'hC1F,

    // Supervisor Trap Setup
    SSTATUS    = 12'h100,
    SIE        = 12'h104,
    STVEC      = 12'h105,
    SCOUNTEREN = 12'h106,

    // Supervisor Configuration
    SENVCFG = 12'h10A,

    // Supervisor Counter Setup
    SCOUNTINHIBIT = 12'h120,

    // Supervisor Trap Handling
    SSCRATCH  = 12'h140,
    SEPC      = 12'h141,
    SCAUSE    = 12'h142,
    STVAL     = 12'h143,
    SIP       = 12'h144,
    // supervisor level count overflow and mode based filtering
    // 各種カウンタのオーバーフローを通知する.
    SCOUNTOVF = 12'hDA0,

    // Supervisor Protection and Translation
    SATP = 12'h180,

    // Debug/Trace
    // 
    SCONTEXT = 12'h5A8,

    // Supervisor State Enable Registers
    SSTATEEN0 = 12'h10C,
    SSTATEEN1 = 12'h10D,
    SSTATEEN2 = 12'h10E,
    SSTATEEN3 = 12'h10F,

    // Hypervisor, Virtual Supervisor関連のcsrは未実装.

    // Machine Information Registers
    MVENDORID  = 12'hF11,
    MARCHID    = 12'hF12,
    MIMPID     = 12'hF13,
    MHARTID    = 12'hF14,
    // Device tree blobが入る.
    MCONFIGPTR = 12'hF15,

    // Machine Trap Setup
    MSTATUS    = 12'h300,
    MISA       = 12'h301,
    MEDELEG    = 12'h302,
    MIDELEG    = 12'h303,
    MIE        = 12'h304,
    MTVEC      = 12'h305,
    MCOUNTEREN = 12'h306,

    // Machine Trap Handling
    MSCRATCH = 12'h340,
    MEPC     = 12'h341,
    MCAUSE   = 12'h342,
    MTVAL    = 12'h343,
    MIP      = 12'h344,
    // MTINST,MTVAL2はH拡張時しか使用しない.
    MTINST   = 12'h34A,
    MTVAL2   = 12'h34B,

    // Machine Configuration
    MENVCFG = 12'h30A,
    MSECCFG = 12'h747,

    // Machine Memory Protection (PMP)
    PMPCFG0   = 12'h3A0,
    PMPCFG2   = 12'h3A2,
    PMPCFG4   = 12'h3A4,
    PMPCFG6   = 12'h3A6,
    PMPCFG8   = 12'h3A8,
    PMPCFG10  = 12'h3AA,
    PMPCFG12  = 12'h3AC,
    PMPCFG14  = 12'h3AE,
    // 各PMPエントリのアドレス.
    PMPADDR0  = 12'h3B0,
    PMPADDR1  = 12'h3B1,
    PMPADDR2  = 12'h3B2,
    PMPADDR3  = 12'h3B3,
    PMPADDR4  = 12'h3B4,
    PMPADDR5  = 12'h3B5,
    PMPADDR6  = 12'h3B6,
    PMPADDR7  = 12'h3B7,
    PMPADDR8  = 12'h3B8,
    PMPADDR9  = 12'h3B9,
    PMPADDR10 = 12'h3BA,
    PMPADDR11 = 12'h3BB,
    PMPADDR12 = 12'h3BC,
    PMPADDR13 = 12'h3BD,
    PMPADDR14 = 12'h3BE,
    PMPADDR15 = 12'h3BF,
    PMPADDR16 = 12'h3C0,
    PMPADDR17 = 12'h3C1,
    PMPADDR18 = 12'h3C2,
    PMPADDR19 = 12'h3C3,
    PMPADDR20 = 12'h3C4,
    PMPADDR21 = 12'h3C5,
    PMPADDR22 = 12'h3C6,
    PMPADDR23 = 12'h3C7,
    PMPADDR24 = 12'h3C8,
    PMPADDR25 = 12'h3C9,
    PMPADDR26 = 12'h3CA,
    PMPADDR27 = 12'h3CB,
    PMPADDR28 = 12'h3CC,
    PMPADDR29 = 12'h3CD,
    PMPADDR30 = 12'h3CE,
    PMPADDR31 = 12'h3CF,
    PMPADDR32 = 12'h3D0,
    PMPADDR33 = 12'h3D1,
    PMPADDR34 = 12'h3D2,
    PMPADDR35 = 12'h3D3,
    PMPADDR36 = 12'h3D4,
    PMPADDR37 = 12'h3D5,
    PMPADDR38 = 12'h3D6,
    PMPADDR39 = 12'h3D7,
    PMPADDR40 = 12'h3D8,
    PMPADDR41 = 12'h3D9,
    PMPADDR42 = 12'h3DA,
    PMPADDR43 = 12'h3DB,
    PMPADDR44 = 12'h3DC,
    PMPADDR45 = 12'h3DD,
    PMPADDR46 = 12'h3DE,
    PMPADDR47 = 12'h3DF,
    PMPADDR48 = 12'h3E0,
    PMPADDR49 = 12'h3E1,
    PMPADDR50 = 12'h3E2,
    PMPADDR51 = 12'h3E3,
    PMPADDR52 = 12'h3E4,
    PMPADDR53 = 12'h3E5,
    PMPADDR54 = 12'h3E6,
    PMPADDR55 = 12'h3E7,
    PMPADDR56 = 12'h3E8,
    PMPADDR57 = 12'h3E9,
    PMPADDR58 = 12'h3EA,
    PMPADDR59 = 12'h3EB,
    PMPADDR60 = 12'h3EC,
    PMPADDR61 = 12'h3ED,
    PMPADDR62 = 12'h3EE,
    PMPADDR63 = 12'h3EF,

    // Machine State Enable Registers
    MSTATEEN0 = 12'h30C,
    MSTATEEN1 = 12'h30D,
    MSTATEEN2 = 12'h30E,
    MSTATEEN3 = 12'h30F,

    // Machine Non-Maskable Interrupt Handling
    MNSCRATCH = 12'h740,
    MNEPC     = 12'h741,
    MNCAUSE   = 12'h742,
    MNSTATUS  = 12'h744,

    // Machine Counter/Timers
    MCYCLE        = 12'hB00,
    MINSTRET      = 12'hB02,
    MHPMCOUNTER3  = 12'hB03,
    MHPMCOUNTER4  = 12'hB04,
    MHPMCOUNTER5  = 12'hB05,
    MHPMCOUNTER6  = 12'hB06,
    MHPMCOUNTER7  = 12'hB07,
    MHPMCOUNTER8  = 12'hB08,
    MHPMCOUNTER9  = 12'hB09,
    MHPMCOUNTER10 = 12'hB0A,
    MHPMCOUNTER11 = 12'hB0B,
    MHPMCOUNTER12 = 12'hB0C,
    MHPMCOUNTER13 = 12'hB0D,
    MHPMCOUNTER14 = 12'hB0E,
    MHPMCOUNTER15 = 12'hB0F,
    MHPMCOUNTER16 = 12'hB10,
    MHPMCOUNTER17 = 12'hB11,
    MHPMCOUNTER18 = 12'hB12,
    MHPMCOUNTER19 = 12'hB13,
    MHPMCOUNTER20 = 12'hB14,
    MHPMCOUNTER21 = 12'hB15,
    MHPMCOUNTER22 = 12'hB16,
    MHPMCOUNTER23 = 12'hB17,
    MHPMCOUNTER24 = 12'hB18,
    MHPMCOUNTER25 = 12'hB19,
    MHPMCOUNTER26 = 12'hB1A,
    MHPMCOUNTER27 = 12'hB1B,
    MHPMCOUNTER28 = 12'hB1C,
    MHPMCOUNTER29 = 12'hB1D,
    MHPMCOUNTER30 = 12'hB1E,
    MHPMCOUNTER31 = 12'hB1F,

    // Machine Counter Setup
    MCOUNTINHIBIT = 12'h320,
    MHPMEVENT3    = 12'h323,
    MHPMEVENT4    = 12'h324,
    MHPMEVENT5    = 12'h325,
    MHPMEVENT6    = 12'h326,
    MHPMEVENT7    = 12'h327,
    MHPMEVENT8    = 12'h328,
    MHPMEVENT9    = 12'h329,
    MHPMEVENT10   = 12'h32A,
    MHPMEVENT11   = 12'h32B,
    MHPMEVENT12   = 12'h32C,
    MHPMEVENT13   = 12'h32D,
    MHPMEVENT14   = 12'h32E,
    MHPMEVENT15   = 12'h32F,
    MHPMEVENT16   = 12'h330,
    MHPMEVENT17   = 12'h331,
    MHPMEVENT18   = 12'h332,
    MHPMEVENT19   = 12'h333,
    MHPMEVENT20   = 12'h334,
    MHPMEVENT21   = 12'h335,
    MHPMEVENT22   = 12'h336,
    MHPMEVENT23   = 12'h337,
    MHPMEVENT24   = 12'h338,
    MHPMEVENT25   = 12'h339,
    MHPMEVENT26   = 12'h33A,
    MHPMEVENT27   = 12'h33B,
    MHPMEVENT28   = 12'h33C,
    MHPMEVENT29   = 12'h33D,
    MHPMEVENT30   = 12'h33E,
    MHPMEVENT31   = 12'h33F,

    // Debug/Trace Registers (shared with Debug Mode)
    // トリガを指定
    TSELECT  = 12'h7A0,
    TDATA1   = 12'h7A1,
    TDATA2   = 12'h7A2,
    TDATA3   = 12'h7A3,
    MCONTEXT = 12'h7A8,

    // Debug Mode Registers
    DCSR      = 12'h7B0,
    DPC       = 12'h7B1,
    DSCRATCH0 = 12'h7B2,
    DSCRATCH1 = 12'h7B3,

    // Sstc 拡張
    STIMECMP = 12'h14D


  } csr_name_e;

  // csrの命令上で用いられる12bitのインデックスを内部的なレジスタのインデックスに変換する
  function logic [7:0] internal_idx(csr_name_e csr_name);
    case (csr_name)
      FFLAGS: return 0;
      FRM:    return 1;
      FCSR:   return 2;

      // 2. Unprivileged Vector CSRs
      VSTART: return 3;
      VXSAT:  return 4;
      VXRM:   return 5;
      VCSR:   return 6;
      VL:     return 7;
      VTYPE:  return 8;
      VLENB:  return 9;

      // 3. Unprivileged security/entropy/jump-table CSRs
      SSP:  return 10;
      SEED: return 11;
      JVT:  return 12;

      // 4. Unprivileged Counter/Timers
      // cycle => mcycle, instret => minstretのように,
      // これらのcsrはエイリアスとして実装する.
      // CYCLE:        return 13;
      TIME: return 14;
      // INSTRET:      return 15;
      // HPMCOUNTER3:  return 16;
      // HPMCOUNTER4:  return 17;
      // HPMCOUNTER5:  return 18;
      // HPMCOUNTER6:  return 19;
      // HPMCOUNTER7:  return 20;
      // HPMCOUNTER8:  return 21;
      // HPMCOUNTER9:  return 22;
      // HPMCOUNTER10: return 23;
      // HPMCOUNTER11: return 24;
      // HPMCOUNTER12: return 25;
      // HPMCOUNTER13: return 26;
      // HPMCOUNTER14: return 27;
      // HPMCOUNTER15: return 28;
      // HPMCOUNTER16: return 29;
      // HPMCOUNTER17: return 30;
      // HPMCOUNTER18: return 31;
      // HPMCOUNTER19: return 32;
      // HPMCOUNTER20: return 33;
      // HPMCOUNTER21: return 34;
      // HPMCOUNTER22: return 35;
      // HPMCOUNTER23: return 36;
      // HPMCOUNTER24: return 37;
      // HPMCOUNTER25: return 38;
      // HPMCOUNTER26: return 39;
      // HPMCOUNTER27: return 40;
      // HPMCOUNTER28: return 41;
      // HPMCOUNTER29: return 42;
      // HPMCOUNTER30: return 43;
      // HPMCOUNTER31: return 44;

      // 5. Supervisor Trap Setup & State Enable
      // SSTATUS => MSTATUSへのエイリアス.
      // SIE => MIEへのエイリアス.
      STVEC:      return 47;
      SCOUNTEREN: return 48;
      SENVCFG:    return 49;
      // SCOUNTINHIBIT => MCOUNTINHIBITへのエイリアス.

      // 6. Supervisor Trap Handling
      SSCRATCH:  return 51;
      SEPC:      return 52;
      SCAUSE:    return 53;
      STVAL:     return 54;
      // SIP => MIP へのエイリアス.
      SCOUNTOVF: return 56;

      // 7. Supervisor Protection/Translation & Debug
      SATP:     return 57;
      SCONTEXT: return 58;

      // 8. Supervisor State Enable Registers
      SSTATEEN0: return 59;
      SSTATEEN1: return 60;
      SSTATEEN2: return 61;
      SSTATEEN3: return 62;

      // 9. Machine Information
      MVENDORID:  return 63;
      MARCHID:    return 64;
      MIMPID:     return 65;
      MHARTID:    return 66;
      MCONFIGPTR: return 67;

      // 10. Machine Trap Setup
      MSTATUS, SSTATUS: return 68;
      MISA:             return 69;
      MEDELEG:          return 70;
      MIDELEG:          return 71;
      MIE, SIE:         return 72;
      MTVEC:            return 73;
      MCOUNTEREN:       return 74;

      // 11. Machine Trap Handling
      MSCRATCH: return 75;
      MEPC:     return 76;
      MCAUSE:   return 77;
      MTVAL:    return 78;
      MIP, SIP: return 79;
      MTINST:   return 80;
      MTVAL2:   return 81;

      // 12. Machine Configuration
      MENVCFG: return 82;
      MSECCFG: return 83;

      // Machine Memory Protection (PMP)
      PMPCFG0:  return 84;
      PMPCFG2:  return 85;
      PMPCFG4:  return 86;
      PMPCFG6:  return 87;
      PMPCFG8:  return 88;
      PMPCFG10: return 89;
      PMPCFG12: return 90;
      PMPCFG14: return 91;

      // PMP Address registers
      PMPADDR0:  return 92;
      PMPADDR1:  return 93;
      PMPADDR2:  return 94;
      PMPADDR3:  return 95;
      PMPADDR4:  return 96;
      PMPADDR5:  return 97;
      PMPADDR6:  return 98;
      PMPADDR7:  return 99;
      PMPADDR8:  return 100;
      PMPADDR9:  return 101;
      PMPADDR10: return 102;
      PMPADDR11: return 103;
      PMPADDR12: return 104;
      PMPADDR13: return 105;
      PMPADDR14: return 106;
      PMPADDR15: return 107;
      PMPADDR16: return 108;
      PMPADDR17: return 109;
      PMPADDR18: return 110;
      PMPADDR19: return 111;
      PMPADDR20: return 112;
      PMPADDR21: return 113;
      PMPADDR22: return 114;
      PMPADDR23: return 115;
      PMPADDR24: return 116;
      PMPADDR25: return 117;
      PMPADDR26: return 118;
      PMPADDR27: return 119;
      PMPADDR28: return 120;
      PMPADDR29: return 121;
      PMPADDR30: return 122;
      PMPADDR31: return 123;
      PMPADDR32: return 124;
      PMPADDR33: return 125;
      PMPADDR34: return 126;
      PMPADDR35: return 127;
      PMPADDR36: return 128;
      PMPADDR37: return 129;
      PMPADDR38: return 130;
      PMPADDR39: return 131;
      PMPADDR40: return 132;
      PMPADDR41: return 133;
      PMPADDR42: return 134;
      PMPADDR43: return 135;
      PMPADDR44: return 136;
      PMPADDR45: return 137;
      PMPADDR46: return 138;
      PMPADDR47: return 139;
      PMPADDR48: return 140;
      PMPADDR49: return 141;
      PMPADDR50: return 142;
      PMPADDR51: return 143;
      PMPADDR52: return 144;
      PMPADDR53: return 145;
      PMPADDR54: return 146;
      PMPADDR55: return 147;
      PMPADDR56: return 148;
      PMPADDR57: return 149;
      PMPADDR58: return 150;
      PMPADDR59: return 151;
      PMPADDR60: return 152;
      PMPADDR61: return 153;
      PMPADDR62: return 154;
      PMPADDR63: return 155;

      // Machine State Enable Registers
      MSTATEEN0: return 156;
      MSTATEEN1: return 157;
      MSTATEEN2: return 158;
      MSTATEEN3: return 159;

      // Machine Non-Maskable Interrupt Handling
      MNSCRATCH: return 160;
      MNEPC:     return 161;
      MNCAUSE:   return 162;
      MNSTATUS:  return 163;

      // Machine Counter/Timers
      MCYCLE, CYCLE:               return 164;
      MINSTRET, INSTRET:           return 165;
      MHPMCOUNTER3, HPMCOUNTER3:   return 166;
      MHPMCOUNTER4, HPMCOUNTER4:   return 167;
      MHPMCOUNTER5, HPMCOUNTER5:   return 168;
      MHPMCOUNTER6, HPMCOUNTER6:   return 169;
      MHPMCOUNTER7, HPMCOUNTER7:   return 170;
      MHPMCOUNTER8, HPMCOUNTER8:   return 171;
      MHPMCOUNTER9, HPMCOUNTER9:   return 172;
      MHPMCOUNTER10, HPMCOUNTER10: return 173;
      MHPMCOUNTER11, HPMCOUNTER11: return 174;
      MHPMCOUNTER12, HPMCOUNTER12: return 175;
      MHPMCOUNTER13, HPMCOUNTER13: return 176;
      MHPMCOUNTER14, HPMCOUNTER14: return 177;
      MHPMCOUNTER15, HPMCOUNTER15: return 178;
      MHPMCOUNTER16, HPMCOUNTER16: return 179;
      MHPMCOUNTER17, HPMCOUNTER17: return 180;
      MHPMCOUNTER18, HPMCOUNTER18: return 181;
      MHPMCOUNTER19, HPMCOUNTER19: return 182;
      MHPMCOUNTER20, HPMCOUNTER20: return 183;
      MHPMCOUNTER21, HPMCOUNTER21: return 184;
      MHPMCOUNTER22, HPMCOUNTER22: return 185;
      MHPMCOUNTER23, HPMCOUNTER23: return 186;
      MHPMCOUNTER24, HPMCOUNTER24: return 187;
      MHPMCOUNTER25, HPMCOUNTER25: return 188;
      MHPMCOUNTER26, HPMCOUNTER26: return 189;
      MHPMCOUNTER27, HPMCOUNTER27: return 190;
      MHPMCOUNTER28, HPMCOUNTER28: return 191;
      MHPMCOUNTER29, HPMCOUNTER29: return 192;
      MHPMCOUNTER30, HPMCOUNTER30: return 193;
      MHPMCOUNTER31, HPMCOUNTER31: return 194;


      // Machine Counter Setup
      MCOUNTINHIBIT, SCOUNTINHIBIT: return 195;
      MHPMEVENT3:    return 196;
      MHPMEVENT4:    return 197;
      MHPMEVENT5:    return 198;
      MHPMEVENT6:    return 199;
      MHPMEVENT7:    return 200;
      MHPMEVENT8:    return 201;
      MHPMEVENT9:    return 202;
      MHPMEVENT10:   return 203;
      MHPMEVENT11:   return 204;
      MHPMEVENT12:   return 205;
      MHPMEVENT13:   return 206;
      MHPMEVENT14:   return 207;
      MHPMEVENT15:   return 208;
      MHPMEVENT16:   return 209;
      MHPMEVENT17:   return 210;
      MHPMEVENT18:   return 211;
      MHPMEVENT19:   return 212;
      MHPMEVENT20:   return 213;
      MHPMEVENT21:   return 214;
      MHPMEVENT22:   return 215;
      MHPMEVENT23:   return 216;
      MHPMEVENT24:   return 217;
      MHPMEVENT25:   return 218;
      MHPMEVENT26:   return 219;
      MHPMEVENT27:   return 220;
      MHPMEVENT28:   return 221;
      MHPMEVENT29:   return 222;
      MHPMEVENT30:   return 223;
      MHPMEVENT31:   return 224;

      // Debug/Trace Registers
      TSELECT:  return 225;
      TDATA1:   return 226;
      TDATA2:   return 227;
      TDATA3:   return 228;
      MCONTEXT: return 229;

      // Debug Mode Registers
      DCSR:      return 230;
      DPC:       return 231;
      DSCRATCH0: return 232;
      DSCRATCH1: return 233;

      // sstc拡張用.
      STIMECMP: return 234;

      default: return 240;
    endcase
  endfunction

  // -------------------------------------------------------------
  // 1. Unprivileged Floating-Point CSRs
  // -------------------------------------------------------------
  // fcsrはfrm+fflags
  typedef struct packed {
    logic [58:0] reserved0;  // [63:5] 予約
    logic        NV;         // [4]    Invalid operation
    logic        DZ;         // [3]    Divide by zero
    logic        OF;         // [2]    Overflow
    logic        UF;         // [1]    Underflow
    logic        NX;         // [0]    Inexact (rounded)
  } fflags_t;

  function automatic logic [XLEN-1:0] fflags_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] fflags_get_read_mask();
    return {{59{1'b0}}, {5{1'b1}}};
  endfunction


  typedef struct packed {
    logic [63:3] reserved0;  // [63:3] 予約
    logic [2:0]  FRM;        // [2:0]  Rounding mode
  } frm_t;

  function automatic logic [XLEN-1:0] frm_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] frm_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  typedef struct packed {
    logic [63:8] reserved0;  // [63:8] 予約
    logic [2:0]  FRM;        // [7:5]  Rounding mode
    logic        NV;         // [4]    Invalid operation
    logic        DZ;         // [3]    Divide by zero
    logic        OF;         // [2]    Overflow
    logic        UF;         // [1]    Underflow
    logic        NX;         // [0]    Inexact (rounded)
  } fcsr_t;

  function automatic logic [XLEN-1:0] fcsr_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] fcsr_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 2. Unprivileged Vector CSRs
  // -------------------------------------------------------------

  // VSTART: Vector start index
  typedef struct packed {
    logic [63:0] VSTART;  // [63:0] ベクタ命令でトラップが発生した時,どこで発生したか
  } vstart_t;

  function automatic logic [XLEN-1:0] vstart_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vstart_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  // VXSAT: Fixed-point saturation flag
  typedef struct packed {
    logic [63:1] reserved0;  // [63:1] Reserved
    logic VXSAT;  // [0]    固定小数点ベクタ演算が飽和処理を行ったか.
  } vxsat_t;

  function automatic logic [XLEN-1:0] vxsat_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vxsat_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // VXRM: Fixed-point rounding mode
  typedef struct packed {
    logic [63:2] reserved0;  // [63:2] Reserved
    logic [1:0]  VXRM;       // [1:0]  固定小数点ベクタ演算の丸め方式
  } vxrm_t;

  function automatic logic [XLEN-1:0] vxrm_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vxrm_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // VCSR: Vector control and status (VXSAT + VXRM)
  typedef struct packed {
    logic [63:8] reserved0;  // [63:8] Reserved
    logic        VXSAT;      // [7]    Saturation flag
    logic [1:0]  VXRM;       // [6:5]  Rounding mode
    logic [4:0]  reserved1;  // [4:0]  Reserved
  } vcsr_t;

  function automatic logic [XLEN-1:0] vcsr_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vcsr_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // VL: Vector length (number of elements to operate on)
  typedef struct packed {
    logic [63:0] VL;  // [63:0] Current vector length
  } vl_t;

  function automatic logic [XLEN-1:0] vl_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vl_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // VTYPE: Vector type 
  typedef struct packed {
    logic VILL;  // 1 の場合は不正な値と見なす
    logic [XLEN-10:0] reserved0;
    logic VMA;  // マスクされた要素をゼロ化せず無視してOK
    logic VTA;  // VL を超えたテイル要素をゼロ化せず無視してOK
    logic [2:0] VSEW;  // SEW: 要素幅（例：8/16/32/64ビットなど）
    logic [2:0] VLMUL;  // LMUL: ベクタレジスタのグループ化設定
  } vtype_t;

  function automatic logic [XLEN-1:0] vtype_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vtype_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // VLENB: Vector register length in bytes
  typedef struct packed {
    logic [63:0] VLENB;  // [63:0] VLEN/8(VLENのバイト単位)
  } vlenb_t;

  function automatic logic [XLEN-1:0] vlenb_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] vlenb_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 3. Unprivileged Zicfiss extension CSR
  // -------------------------------------------------------------
  // Zicfiss拡張は,リンクレジスタをシャドウスタックに格納・読み出しする命令や,戻りアドレスの整合性を検査する命令を提供
  // シャドウスタックとは,リンクレジスタ（通常は戻りアドレスを保持する）を退避させる必要がある場合に,そのコピーを保存するための第2のスタック

  // SSP: Shadow Stack Pointer
  typedef struct packed {logic [63:0] SSP;} ssp_t;

  function automatic logic [XLEN-1:0] ssp_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] ssp_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 4. Unprivileged Entropy Source Extension CSR
  // -------------------------------------------------------------

  // SEED: Entropy Source Seed Register
  // [63:0] Hardware entropy/PRNG seed output
  typedef struct packed {
    logic [31:0] reserved0;
    logic [1:0] OPST;  // 現在の状態
    logic [5:0] reserved1;
    logic [7:0] CUSTOM;
    logic [15:0] ENTOROPY;  // 16ビットのランダムデータ.
  } seed_t;

  function automatic logic [XLEN-1:0] seed_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] seed_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 5. Unprivileged Zcmt Extension CSR
  // -------------------------------------------------------------
  // Zcmt OSカーネルがテーブルベースの関数呼び出しを高速に処理したいとき

  // JVT: Jump Vector Table Register
  typedef struct packed {
    logic [XLEN-7:0] BASE;
    logic [5:0] MODE;
  } jvt_t;

  function automatic logic [XLEN-1:0] jvt_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] jvt_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 6. Unprivileged Counter/Timers (Zicntr拡張,Zihpm拡張)
  // -------------------------------------------------------------

  // CYCLE: User-level Cycle Counter
  // [63:0] Monotonic cycle count
  typedef struct packed {logic [63:0] CYCLE;} cycle_t;

  function automatic logic [XLEN-1:0] cycle_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] cycle_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // TIME: User-level Time Counter
  // [63:0] Monotonic wall-clock time (mtime)
  typedef struct packed {logic [63:0] TIME;} time_t;

  function automatic logic [XLEN-1:0] time_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] time_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // INSTRET: User-level Instructions Retired Counter
  // [63:0] Number of retired instructions
  typedef struct packed {logic [63:0] INSTRET;} instret_t;

  function automatic logic [XLEN-1:0] instret_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] instret_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // HPMCOUNTER User-level Performance-Monitoring Counter 
  // カウント対象のイベントが実装依存のカウンタ.
  typedef struct packed {logic [63:0] HPMCOUNTER;} hpmcounter_t;

  function automatic logic [XLEN-1:0] hpmcounter_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] hpmcounter_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 7. Supervisor Trap Setup
  // -------------------------------------------------------------

  // SSTATUS: Supervisor Status Register
  typedef struct packed {
    logic SD;                    // Summary Dirty: FS, VS, XS のいずれかが Dirty のとき1。拡張ステートの保存が必要であることを示す。
    logic [28:0] reserved0;  // 予約領域（未使用ビット）
    logic [1:0] UXL;  // ユーザーモードXLEN選択（01=32ビット, 10=64ビット）
    logic [6:0] reserved1;  // 予約領域（未使用ビット）
    logic SDT;                   // Supervisor Disable Trap: Sモードのトラップ禁止ビット。SDT=1 で新たなトラップは予期せぬトラップとなる。
    logic SPELP;                 // Supervisor Previous Expected Landing Pad: Zicfilp用に前回期待ランディングパッド状態を保持。
    logic [2:0] reserved2;  // 予約領域（未使用ビット）
    logic MXR;  // Make eXecutable Readable: Xビットセットページへのロードを許可。
    logic SUM;                   // Supervisor User Memory: U=1 のページへの Sモードメモリアクセスを許可（PUM相当）。
    logic reserved3;  // 予約領域（未使用ビット）
    logic [1:0] XS;              // Extension State Summary: ユーザー拡張ステートのサマリ（Off/Initial/Clean/Dirty）。
    logic [1:0] FS;              // Floating-point State Summary: FPUステートのサマリ（Off/Initial/Clean/Dirty）。
    logic [1:0] reserved4;  // 予約領域（未使用ビット）
    logic [1:0] VS;              // Vector State Summary: ベクトル拡張ステートのサマリ（Off/Initial/Clean/Dirty）。
    logic SPP;                   // Supervisor Previous Privilege: trap前の特権レベル（0=ユーザーモード, 1=Sモード）。
    logic reserved5;  // 予約領域（未使用ビット）
    logic UBE;                   // User Big-Endian: ユーザーモードでビッグエンディアンを使用する場合に1。
    logic SPIE;                  // Supervisor Previous Interrupt Enable: trap前の割り込み許可状態を保持。
    logic [2:0] reserved6;  // 予約領域（未使用ビット）
    logic SIE;  // Supervisor Interrupt Enable: Sモードでの割り込み許可ビット。
    logic reserved7;  // 予約領域（未使用ビット）
  } sstatus_t;

  function automatic logic [XLEN-1:0] sstatus_get_read_mask();
    sstatus_t mask_csr = '1;
    logic [63:0] mask;
    mask_csr.reserved0 = {29{1'b0}};
    mask_csr.reserved1 = {7{1'b0}};
    mask_csr.reserved2 = {3{1'b0}};
    mask_csr.reserved3 = 1'b0;
    mask_csr.reserved4 = {2{1'b0}};
    mask_csr.reserved5 = 1'b0;
    mask_csr.reserved6 = {3{1'b0}};
    mask_csr.reserved7 = 1'b0;

    mask = mask_csr;
    return mask;
  endfunction

  function automatic logic [XLEN-1:0] sstatus_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SIE: Supervisor Interrupt Enable Register
  typedef struct packed {
    logic [49:0] reserved0;
    logic LCOFIE; // COUNTER_OVERFLOW_INTERRUPT;
    logic [2:0] reserved1;
    logic SEIE;     // [9] SUPERVISOR_EXTERNAL_INTERRUPT;
    logic [2:0] reserved2;
    logic STIE;     // [5] SUPERVISOR_TIMER_INTERRUPT;
    logic [2:0] reserved3;
    logic SSIE;  // [1] SUPERVISOR_SOFTWARE_INTERRUPT;
    logic reserved4;
  } sie_t;

  function automatic logic [XLEN-1:0] sie_get_read_mask();
    logic [63:0] mask;
    sie_t mask_csr = '1;
    mask_csr.reserved0 = {50{1'b0}};
    mask_csr.reserved1 = {3{1'b0}};
    mask_csr.reserved2 = 3'b000;
    mask_csr.reserved3 = 3'b000;
    mask_csr.reserved4 = 1'b0;

    mask = mask_csr;
    return mask;
  endfunction

  function automatic logic [XLEN-1:0] sie_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // STVEC: Supervisor Trap Vector Register
  typedef struct packed {
    logic [61:0] BASE;  // 4バイトアラインになっているので下2bitは切り捨ててOK
    logic [1:0] MODE;  // vectoredモードなら非同期割り込みで base + 4*causeがpcに.
  } stvec_t;

  function automatic logic [XLEN-1:0] stvec_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] stvec_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SCOUNTEREN: 
  // 各種カウンタをU_MODEから見れるか
  // Uへの移譲にはmcouterenが1であると同時にscounterenも1である必要がある.
  typedef struct packed {
    logic [31:0] reserved0;
    logic HPM31;
    logic HPM30;
    logic HPM29;
    logic HPM28;
    logic HPM27;
    logic HPM26;
    logic HPM25;
    logic HPM24;
    logic HPM23;
    logic HPM22;
    logic HPM21;
    logic HPM20;
    logic HPM19;
    logic HPM18;
    logic HPM17;
    logic HPM16;
    logic HPM15;
    logic HPM14;
    logic HPM13;
    logic HPM12;
    logic HPM11;
    logic HPM10;
    logic HPM9;
    logic HPM8;
    logic HPM7;
    logic HPM6;
    logic HPM5;
    logic HPM4;
    logic HPM3;
    logic IR;  // Instruction Retired (instret)
    logic TM;  // Timer (bit 1)
    logic CY;  // Cycle (bit 0)
  } scounteren_t;

  function automatic logic [XLEN-1:0] scounteren_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] scounteren_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 8. Supervisor Configuration
  // -------------------------------------------------------------

  typedef struct packed {
    logic [29:0] reserved0;  // 予約ビット: 将来の拡張用、常に0に固定してよい
    logic [1:0]  PMM;         // ポインタマスキングモード (ZJPM拡張) を制御する WARL フィールド  
                              // 下位特権モード (U/VU) でのポインタマスキングを有効／無効にする :contentReference[oaicite:0]{index=0}
    logic [23:0] reserved1;  // 予約ビット: 将来の拡張用、常に0に固定してよい
    logic        CBZE;        // Zicboz 拡張によるキャッシュブロックゼロ命令 (CBO.Z.E) の実行可否を制御する WARL ビット :contentReference[oaicite:1]{index=1}
    logic        CBCFE;       // Zicbom 拡張によるキャッシュブロッククリーン／フラッシュ命令の実行可否を制御する WARL ビット :contentReference[oaicite:2]{index=2}
    logic [1:0]  CBIE;        // Zicbom 拡張によるキャッシュブロック命令の仮想化制御用 WARL フィールド :contentReference[oaicite:3]{index=3}
    logic        SSE;         // Zicfiss 拡張によるシャドウスタック (CFI バックエッジ制御) を有効化する WARL ビット :contentReference[oaicite:4]{index=4}
    logic        LPE;         // Zicfilp 拡張によるランディングパッド (CFI フォワードエッジ制御) を有効化する WARL ビット :contentReference[oaicite:5]{index=5}
    logic reserved2;  // 予約ビット: 将来の拡張用、常に0に固定してよい
    logic FIOM;  // FENCE 命令の I/O 前後セットの解釈を修飾する WARL ビット  
                 // (モード未満特権での FENCE 動作の仮想化) :contentReference[oaicite:6]{index=6}
  } senvcfg_t;

  function automatic logic [XLEN-1:0] senvcfg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] senvcfg_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 9. Supervisor Counter Setup
  // -------------------------------------------------------------

  // scountinhibit: Supervisor Counter Inhibit Register
  typedef struct packed {
    logic [31:0] reserved0;
    logic HPM31;
    logic HPM30;
    logic HPM29;
    logic HPM28;
    logic HPM27;
    logic HPM26;
    logic HPM25;
    logic HPM24;
    logic HPM23;
    logic HPM22;
    logic HPM21;
    logic HPM20;
    logic HPM19;
    logic HPM18;
    logic HPM17;
    logic HPM16;
    logic HPM15;
    logic HPM14;
    logic HPM13;
    logic HPM12;
    logic HPM11;
    logic HPM10;
    logic HPM9;
    logic HPM8;
    logic HPM7;
    logic HPM6;
    logic HPM5;
    logic HPM4;
    logic HPM3;
    logic IR;  // Instruction Retired (instret)
    logic TM;  // Timer (bit 1)
    logic CY;  // Cycle (bit 0)
  } scountinhibit_t;

  function automatic logic [XLEN-1:0] scountinhibit_get_read_mask();
    scountinhibit_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = '0;

    mask_logic = mask;
    return mask_logic;
  endfunction


  function automatic logic [XLEN-1:0] scountinhibit_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 10. Supervisor Trap Handling
  // -------------------------------------------------------------

  // SSCRATCH: Supervisor Scratch Register
  typedef struct packed {
    logic [63:0] SSCRATCH;  // スーパーバイザ用の一時保存用レジスタ.
  } sscratch_t;

  function automatic logic [XLEN-1:0] sscratch_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] sscratch_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SEPC: Supervisor Exception Program Counter
  typedef struct packed {
    logic [63:0] SEPC;  // トラップ後に戻る先のアドレス.
  } sepc_t;

  function automatic logic [XLEN-1:0] sepc_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] sepc_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SCAUSE: Supervisor Cause Register
  typedef struct packed {
    logic INTERRUPT;  // 1が割り込み,0が同期例外.
    logic [XLEN-2:0] EXCEPTION_CODE;  // トラップ原因.
  } scause_t;

  function automatic logic [XLEN-1:0] scause_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] scause_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // STVAL: Supervisor Trap Value Register
  // 例外の種類によって様々な値を保存できるcsr
  typedef struct packed {logic [63:0] STVAL;} stval_t;

  function automatic logic [XLEN-1:0] stval_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] stval_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SIP: Supervisor Interrupt Pending Register
  // スーパバイザ割り込み保留レジスタ.
  // TODO: m割り込みを見えないようにする.
  typedef struct packed {
    logic [53:0] reserved0;
    logic SEIP;  // SUPERVISOR_EXTERNAL_INTERRUPT;
    logic [2:0] reserved1;
    logic STIP;  // SUPERVISOR_TIMER_INTERRUPT;
    logic [2:0] reserved2;
    logic SSIP;  //SUPERVISOR_SOFTWARE_INTERRUPT
    logic reserved3;
  } sip_t;

  function automatic logic [XLEN-1:0] sip_get_read_mask();
    logic [63:0] mask;
    sip_t mask_csr = '1;
    mask_csr.reserved0 = {54{1'b0}};
    mask_csr.reserved1 = 3'b0;
    mask_csr.reserved2 = 3'b0;
    mask_csr.reserved3 = 1'b0;
    mask = mask_csr;
    return mask;
  endfunction


  function automatic logic [XLEN-1:0] sip_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // SCOUNTOVF: Supervisor Counter Overflow Register
  // 32ビットの読み取り専用レジスタで,mhpmevent3 〜 mhpmevent31 の29個のCSR にあるオーバーフロービット(OFビット)のシャドウコピー（影の写し）を保持
  typedef struct packed {logic [63:0] SCOUNTOVF;} scountovf_t;

  function automatic logic [XLEN-1:0] scountovf_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] scountovf_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 11. Supervisor Protection and Translation
  // -------------------------------------------------------------

  // SATP: 仮想アドレスを物理アドレスに変換するため.
  typedef struct packed {
    logic [3:0] MODE;  // アドレス変換なし,Sv32でアドレス変換,Sv39でアドレス変換などのオンオフと種類.
    logic [15:0] ASID;  // コンテキストごとにTLBに設定して,間違ったアドレス変換をしないようにするアレ.
    logic [43:0] PPN;  // 一番始めのPTEのアドレスの一部
  } satp_t;

  function automatic logic [XLEN-1:0] satp_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] satp_get_write_mask(input logic [XLEN-1:0] original_val);
    satp_t tmp = satp_t'(original_val);
    satp_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    if (tmp.MODE != 0 && tmp.MODE != 4'b1000) mask.MODE = '0;

    mask_logic = mask;
    return mask_logic;
  endfunction

  // -------------------------------------------------------------
  // 11. Debug/Trace Registers
  // -------------------------------------------------------------


  // SCONTEXT: Supervisor Context Register
  typedef struct packed {
    logic [63:0] SCONTEXT;  // Context ID for tracing/debugging
  } scontext_t;

  function automatic logic [XLEN-1:0] scontext_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] scontext_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 12. Supervisor State Enable Registers
  // -------------------------------------------------------------

  // SSTATEEN0: Supervisor State Enable Register 0
  typedef struct packed {
    logic [63:0] SSTATEEN;  // Enable bits for supervisor-mode instruction extensions (0-31)
  } sstateen_t;

  function automatic logic [XLEN-1:0] sstateen_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] sstateen_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 21. Machine Information Registers
  // -------------------------------------------------------------

  // MVENDORID:ベンダID
  typedef struct packed {
    logic [31:0] reserved0;  // [63:32] Reserved (0)
    logic [24:0] BANK;       // [31:7]  JEDEC Bank ID
    logic [6:0]  OFFSET;     // [6:0]   JEDEC Manufacturer ID LSB
  } mvendorid_t;

  function automatic logic [XLEN-1:0] mvendorid_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mvendorid_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // MARCHID: アーキテクチャID
  typedef struct packed {
    logic [31:0] reserved0;  // [63:32] Reserved (0)
    logic [31:0] ARCH_ID;    // [31:0]  Architecture ID
  } marchid_t;

  function automatic logic [XLEN-1:0] marchid_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] marchid_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // MIMPID: 実装ID
  typedef struct packed {
    logic [31:0] reserved0;  // [63:32] Reserved (0)
    logic [31:0] IMPL_ID;    // [31:0]  Implementation/Revision ID
  } mimpid_t;

  function automatic logic [XLEN-1:0] mimpid_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mimpid_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // MHARTID: ハートID(単スレッドコアの場合何番目のコアか.)
  typedef struct packed {
    logic [31:0] reserved0;  // [63:32] Reserved (0)
    logic [31:0] HART_ID;    // [31:0]  Hardware thread ID
  } mhartid_t;

  function automatic logic [XLEN-1:0] mhartid_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mhartid_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction


  // MCONFIGPTR: Machine Configuration Pointer
  typedef struct packed {
    logic [63:0] MCONFIGPTR;  // Physical address pointer to platform config
  } mconfigptr_t;

  function automatic logic [XLEN-1:0] mconfigptr_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mconfigptr_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 22. Machine Trap Setup
  // -------------------------------------------------------------

  // MSTATUS: Machine Status Register
  typedef struct packed {
    logic SD;  // [63]   サマリダーティ（FS, VS, XS のいずれかが Dirty のとき1）
    logic [19:0] reserved0;  // [62:43] 予約領域 (WPRI)
    logic MDT;  // [42]   Mモードデバッグトラップ
    logic MPELP;  // [41]   Mモード前回期待ランディングパッド
    logic reserved1;  // [40]   予約領域 (WPRI)
    logic MPV;  // [39]   Mモード前特権レベル有効ビット
    logic GVA;  // [38]   ゲスト仮想アドレスサポート
    logic MBE;  // [37]   Mモードビッグエンディアン
    logic SBE;  // [36]   Sモードビッグエンディアン
    logic [1:0] SXL;  // [35:34] SモードXLEN選択ビット
    logic [1:0] UXL;  // [33:32] ユーザーモードXLEN選択ビット
    logic [6:0] reserved2;  // [31:25] 予約領域 (WPRI)
    logic SDT;  // [24]   Sモードトラップ禁止
    logic SPELP;  // [23]   Sモード前回期待ランディングパッド
    logic TSR;  // [22]   SRETトラップ有効ビット
    logic TW;  // [21]   タイムアウトウェイト
    logic TVM;  // [20]   仮想メモリトラップ禁止
    logic MXR;  // [19]   実行可能ページの読み込み許可
    logic SUM;  // [18]   ユーザーメモリへのSモードアクセス許可
    logic MPRV;  // [17]   アクセス特権レベル変更
    logic [1:0] XS;  // [16:15] 拡張ステートサマリ
    logic [1:0] FS;  // [14:13] 浮動小数点ステートサマリ
    logic [1:0] MPP;  // [12:11] Mモード前特権レベル
    logic [1:0] VS;  // [10:9] ベクトルステートサマリ
    logic SPP;  // [8]     Sモード前特権レベル
    logic MPIE;  // [7]     Mモード前割り込み許可
    logic UBE;  // [6]     ユーザーモードビッグエンディアン
    logic SPIE;  // [5]     Sモード前割り込み許可
    logic reserved3;  // [4]     予約領域 (WPRI)
    logic MIE;  // [3]     Mモード割り込み許可
    logic reserved4;  // [2]     予約領域 (WPRI)
    logic SIE;  // [1]     Sモード割り込み許可
    logic reserved5;  // [0]   予約領域 (WPRI)
  } mstatus_t;

  function automatic logic [XLEN-1:0] mstatus_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mstatus_get_write_mask(input logic [XLEN-1:0] original_val);
    mstatus_t tmp = mstatus_t'(original_val);
    mstatus_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = 20'b0;
    mask.reserved1 = 1'b0;
    mask.SXL = 2'b00;
    mask.UXL = 2'b00;
    mask.reserved2 = 7'b0;
    mask.XS = 2'b11;
    if (tmp.MPP == 2'b10) mask.MPP = 2'b00;
    mask.FS = 2'b11;
    mask.VS = 2'b11;
    mask.reserved3 = 1'b0;
    mask.reserved4 = 1'b0;
    mask.reserved5 = 1'b0;

    mask_logic = mask;
    return mask_logic;
  endfunction


  // MISA: どの拡張をサポートしているかとかを記録しておく.
  typedef struct packed {
    logic [1:0]  MXL;        // [63:62] XLEN識別子
    logic [35:0] reserved0;  // [61:26] 予約領域
    logic        Z;
    logic        Y;
    logic        X;
    logic        W;
    logic        V;
    logic        U;
    logic        T;
    logic        S;
    logic        R;
    logic        Q;
    logic        P;
    logic        O;
    logic        N;          // 
    logic        M;          // M拡張(mul,div)
    logic        L;          // reserved
    logic        K;          // reserved
    logic        J;          // reserved
    logic        I;          // rv32i/rv64i
    logic        H;          // hypervisor
    logic        G;          // reserved
    logic        F;          // F拡張(float)
    logic        E;          // rv32e/rv64e
    logic        D;          // D拡張(double)
    logic        C;          // compressed
    logic        B;          // B extension
    logic        A;          // Atomic extension
  } misa_t;

  function automatic logic [XLEN-1:0] misa_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] misa_get_write_mask(input logic [XLEN-1:0] original_val);
    misa_t tmp = misa_t'(original_val);
    misa_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.MXL = 2'b00;
    mask.reserved0 = '0;
    mask.Z = 1'b0;
    mask.Y = 1'b0;
    mask.X = 1'b0;
    mask.W = 1'b0;
    mask.V = 1'b0;
    mask.U = 1'b0;
    mask.T = 1'b0;
    mask.S = 1'b0;
    mask.R = 1'b0;
    mask.Q = 1'b0;
    mask.P = 1'b0;
    mask.O = 1'b0;
    mask.N = 1'b0;
    mask.M = 1'b0;
    mask.L = 1'b0;
    mask.K = 1'b0;
    mask.J = 1'b0;
    mask.I = 1'b0;
    mask.H = 1'b0;
    mask.G = 1'b0;
    mask.F = 1'b0;
    mask.E = 1'b0;
    mask.D = 1'b0;
    mask.C = 1'b0;
    mask.B = 1'b0;
    mask.A = 1'b0;


    mask_logic = mask;
    return mask_logic;
  endfunction


  // MEDELEG: Machine Exception Delegation Register マシン例外移譲レジスタ
  // mcauseのビットエンコーディングと一致.
  typedef struct packed {
    logic [43:0] reserved0;
    logic HARDWARE_ERROR;
    logic SOFTWARE_CHECK;
    logic reserved1;
    logic DOUBLE_TRAP;
    logic STORE_AMO_PAGE_FAULT;
    logic reserved2;
    logic LOAD_PAGE_FAULT;
    logic INSTRUCTION_PAGE_FAULT;
    logic ENVIRONMENT_CALL_FROM_M_MODE;
    logic reserved3;
    logic ENVIRONMENT_CALL_FROM_S_MODE;
    logic ENVIRONMENT_CALL_FROM_U_MODE;
    logic STORE_AMO_ACCESS_FAULT;
    logic STORE_AMO_ADDRESS_MISALIGNED;
    logic LOAD_ACCESS_FAULT;
    logic LOAD_ADDRESS_MISALIGNED;
    logic BREAK_POINT;
    logic ILLEGAL_INSTRUCTION;
    logic INSTRUCTION_ACCESS_FAULT;
    logic INSTRUCTION_ADDRESS_MISALIGNED;
  } medeleg_t;

  function automatic logic [XLEN-1:0] medeleg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] medeleg_get_write_mask(input logic [XLEN-1:0] original_val);
    medeleg_t tmp = medeleg_t'(original_val);
    medeleg_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = 44'b0;
    mask.reserved1 = 1'b0;
    mask.reserved2 = 1'b0;
    mask.reserved3 = 1'b0;

    mask_logic = mask;
    return mask_logic;
  endfunction

  // MIDELEG: Machine Interrupt Delegation Register マシン割り込み移譲レジスタ.
  // mcauseのinterruptのエンコーディングと一致する.
  typedef struct packed {
    logic [49:0] reserved0;
    logic COUNTER_OVERFLOW_INTERRUPT;
    logic reserved1;
    logic MACHINE_EXTERNAL_INTERRUPT;
    logic reserved2;
    logic SUPERVISOR_EXTERNAL_INTERRUPT;
    logic reserved3;
    logic MACHINE_TIMER_INTERRUPT;
    logic reserved4;
    logic SUPERVISOR_TIMER_INTERRUPT;
    logic reserved5;
    logic MACHINE_SOFTWARE_INTERRUPT;
    logic reserved6;
    logic SUPERVISOR_SOFTWARE_INTERRUPT;
    logic reserved7;
  } mideleg_t;

  function automatic logic [XLEN-1:0] mideleg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mideleg_get_write_mask(input logic [XLEN-1:0] original_val);
    mideleg_t tmp = mideleg_t'(original_val);
    mideleg_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = 50'b0;
    mask.reserved1 = 1'b0;
    mask.reserved2 = 1'b0;
    mask.reserved3 = 1'b0;
    mask.reserved4 = 1'b0;
    mask.reserved5 = 1'b0;
    mask.reserved6 = 1'b0;
    mask.reserved7 = 1'b0;


    mask_logic = mask;
    return mask_logic;
  endfunction

  // MIE: Machine Interrupt Enable Register 
  // マシン割り込み有効レジスタ.
  typedef struct packed {
    logic [49:0] reserved0;
    logic LCOFIE; // COUNTER_OVERFLOW_INTERRUPT;
    logic reserved1;
    logic MEIE;    // MACHINE_EXTERNAL_INTERRUPT;
    logic reserved2;
    logic SEIE;     // SUPERVISOR_EXTERNAL_INTERRUPT;
    logic reserved3;
    logic MTIE;     // MACHINE_TIMER_INTERRUPT;
    logic reserved4;
    logic STIE;     // SUPERVISOR_TIMER_INTERRUPT;
    logic reserved5;
    logic MSIE;    // MACHINE_SOFTWARE_INTERRUPT;
    logic reserved6;
    logic SSIE;  //SUPERVISOR_SOFTWARE_INTERRUPT;
    logic reserved7;
  } mie_t;

  function automatic logic [XLEN-1:0] mie_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mie_get_write_mask(input logic [XLEN-1:0] original_val);
    mie_t tmp = mie_t'(original_val);
    mie_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = 50'b0;
    mask.reserved1 = 1'b0;
    mask.reserved2 = 1'b0;
    mask.reserved3 = 1'b0;
    mask.reserved4 = 1'b0;
    mask.reserved5 = 1'b0;
    mask.reserved6 = 1'b0;
    mask.reserved7 = 1'b0;

    mask_logic = mask;
    return mask_logic;
  endfunction

  // MTVEC: Machine Trap Vector Register
  typedef struct packed {
    logic [XLEN-3:0] BASE;
    logic [1:0] MODE;
  } mtvec_t;

  function automatic logic [XLEN-1:0] mtvec_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mtvec_get_write_mask(input logic [XLEN-1:0] original_val);
    mtvec_t tmp = mtvec_t'(original_val);
    mtvec_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    if (tmp.MODE inside {2'b10, 2'b11}) mask.MODE = 2'b00;

    mask_logic = mask;
    return mask_logic;
  endfunction

  // MCOUNTEREN: Machine Counter Enable Register
  // 下位の特権レベル(S/U)にカウンタを移譲するか.
  // Uへの移譲にはmcouterenが1であると同時にscounterenも1である必要がある.
  typedef struct packed {
    logic [31:0] reserved0;
    logic HPM31;
    logic HPM30;
    logic HPM29;
    logic HPM28;
    logic HPM27;
    logic HPM26;
    logic HPM25;
    logic HPM24;
    logic HPM23;
    logic HPM22;
    logic HPM21;
    logic HPM20;
    logic HPM19;
    logic HPM18;
    logic HPM17;
    logic HPM16;
    logic HPM15;
    logic HPM14;
    logic HPM13;
    logic HPM12;
    logic HPM11;
    logic HPM10;
    logic HPM9;
    logic HPM8;
    logic HPM7;
    logic HPM6;
    logic HPM5;
    logic HPM4;
    logic HPM3;
    logic IR;  // Instruction Retired (instret)
    logic TM;  // Timer (bit 1)
    logic CY;  // Cycle (bit 0)
  } mcounteren_t;

  function automatic logic [XLEN-1:0] mcounteren_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mcounteren_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 23. Machine Trap Handling
  // -------------------------------------------------------------

  // MSCRATCH: Machine Scratch Register
  // トラップ時に一時的なデータを保存するレジスタ.
  typedef struct packed {logic [63:0] MSCRATCH;} mscratch_t;

  function automatic logic [XLEN-1:0] mscratch_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mscratch_get_write_mask(input logic [XLEN-1:0] original_val);
    return {64{1'b1}};
  endfunction

  // MEPC: Machine Exception Program Counter Register
  // トラップ後に戻る先のアドレス.
  typedef struct packed {logic [63:0] MEPC;} mepc_t;

  function automatic logic [XLEN-1:0] mepc_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mepc_get_write_mask(input logic [XLEN-1:0] original_val);
    return {64{1'b1}};
  endfunction

  // MCAUSE: Machine Cause Register
  // 割り込み,例外の原因番号.
  typedef struct packed {
    logic        INTERRUPT;       // bit 63: 1=interrupt, 0=exception
    logic [62:0] EXCEPTION_CODE;  // bits 62–0: exception code
  } mcause_t;

  function automatic logic [XLEN-1:0] mcause_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mcause_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MTVAL: Machine Trap Value Register
  typedef struct packed {logic [63:0] MTVAL;} mtval_t;

  function automatic logic [XLEN-1:0] mtval_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mtval_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MIP: Machine Interrupt Pending Register 
  // マシン割り込み保留レジスタ.
  typedef struct packed {
    logic [49:0] reserved0;
    logic LCOFIP;  // [13] COUNTER_OVERFLOW_INTERRUPT;
    logic reserved1;
    logic MEIP;  // [11] MACHINE_EXTERNAL_INTERRUPT;
    logic reserved2;
    logic SEIP;  // [9] SUPERVISOR_EXTERNAL_INTERRUPT;
    logic reserved3;
    logic MTIP;  // [7] MACHINE_TIMER_INTERRUPT;
    logic reserved4;
    logic STIP;  // [5] SUPERVISOR_TIMER_INTERRUPT;
    logic reserved5;
    logic MSIP;  // [3] MACHINE_SOFTWARE_INTERRUPT;
    logic reserved6;
    logic SSIP;  // [1] SUPERVISOR_SOFTWARE_INTERRUPT
    logic reserved7;
  } mip_t;

  function automatic logic [XLEN-1:0] mip_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mip_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MTINST: Machine Trap Instruction Register
  typedef struct packed {logic [63:0] MTINST;} mtinst_t;

  function automatic logic [XLEN-1:0] mtinst_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mtinst_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MTVAL2: Machine Trap Value Register 2
  typedef struct packed {logic [63:0] MTVAL2;} mtval2_t;

  function automatic logic [XLEN-1:0] mtval2_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mtval2_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 24. Machine Configuration
  // -------------------------------------------------------------

  // MENVCFG: Machine Environment Configuration Register
  // 
  typedef struct packed {
    logic        STCE;       // [63] Sstc 拡張
    logic        PMBTE;      // [62] Svpbmt 拡張によるページ単位メモリ型指定許可
    logic        ADUE;       // [61] Asynchronous Delegation Update Enable（将来拡張用）
    logic        CDE;        // [60] Smcdeleg 拡張によるカウンタ委譲許可
    logic        DTE;        // [59] Debug Trigger Enable（未定義／予約）
    logic [24:0] reserved0;
    logic [1:0]  PMM;        // Ssnpm 拡張による下位特権でのモニタ挙動選択
    logic [23:0] reserved1;
    logic        CBZE;       // Zicboz 拡張で CBO.ZERO 許可
    logic        CBCFE;      // Zicbom 拡張で CBO.CLEAN/FLUSH 許可
    logic [1:0]  CBIE;       // Zicbom 拡張で CBO.INVAL 等を許可
    logic        SSE;        // S-mode での追加 ISA 拡張使用許可 (SSTATEENn)
    logic        LPE;        // [2]    Lazy Page Enable（将来拡張用）
    logic        reserved2;
    logic        FIOM;       // FENCE io,io をメモリにも拡張 (FIOM 拡張)
  } menvcfg_t;

  function automatic logic [XLEN-1:0] menvcfg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] menvcfg_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MSECCFG: Machine Security Configuration Register
  typedef struct packed {
    // [63:10] 予約領域（将来拡張用）
    logic [29:0] reserved0;
    logic [1:0] PMM;
    logic [20:0] reserved1;
    logic MLPE;
    logic SSEED;
    logic USEED;
    logic [4:0] reserved2;
    logic RLB;
    logic MMWP;
    logic MML;
  } mseccfg_t;

  function automatic logic [XLEN-1:0] mseccfg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mseccfg_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 25. Machine Memory Protection
  // -------------------------------------------------------------

  // PMPCFG0: PMP Configuration Register 0
  typedef struct packed {logic [63:0] PMPCFG;} pmpcfg_t;

  function automatic logic [XLEN-1:0] pmpcfg_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] pmpcfg_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // PMPADDR63: PMP Address Register 63
  typedef struct packed {logic [63:0] PMPADDR63;} pmpaddr_t;

  function automatic logic [XLEN-1:0] pmpaddr_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] pmpaddr_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 26. Machine State Enable Registers
  // -------------------------------------------------------------

  // MSTATEEN0: Machine State Enable Register 0
  typedef struct packed {logic [63:0] MSTATEEN;} mstateen_t;

  function automatic logic [XLEN-1:0] mstateen_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mstateen_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 27. Machine Non-Maskable Interrupt Handling
  // -------------------------------------------------------------

  // MNSCRATCH: Machine NMI Scratch Register
  typedef struct packed {logic [63:0] MNSCRATCH;} mnscratch_t;

  function automatic logic [XLEN-1:0] mnscratch_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mnscratch_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MNEPC: Machine NMI Exception Program Counter Register
  typedef struct packed {logic [63:0] MNEPC;} mnepc_t;

  function automatic logic [XLEN-1:0] mnepc_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mnepc_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MNCAUSE: Machine NMI Cause Register
  typedef struct packed {logic [63:0] MNCAUSE;} mncause_t;

  function automatic logic [XLEN-1:0] mncause_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mncause_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MNSTATUS: Machine NMI Status Register
  typedef struct packed {logic [63:0] MNSTATUS;} mnstatus_t;

  function automatic logic [XLEN-1:0] mnstatus_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mnstatus_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 28. Machine Counter/Timers
  // -------------------------------------------------------------


  // MCYCLE: Machine Cycle Counter
  typedef struct packed {logic [63:0] MCYCLE;} mcycle_t;

  function automatic logic [XLEN-1:0] mcycle_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mcycle_get_write_mask(input logic [XLEN-1:0] original_val);
    return {64{1'b1}};
  endfunction

  // MINSTRET: Machine Instructions Retired Counter
  typedef struct packed {logic [63:0] MINSTRET;} minstret_t;

  function automatic logic [XLEN-1:0] minstret_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] minstret_get_write_mask(input logic [XLEN-1:0] original_val);
    return {64{1'b1}};
  endfunction

  // MHPMCOUNTER3: Machine Hardware Performance Counter 
  typedef struct packed {logic [63:0] MHPMCOUNTER;} mhpmcounter_t;

  function automatic logic [XLEN-1:0] mhpmcounter_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mhpmcounter_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {64{1'b1}};
  endfunction

  // -------------------------------------------------------------
  // 29. Machine Counter Setup
  // -------------------------------------------------------------

  // MCOUNTINHIBIT: Machine Counter Inhibit Register
  typedef struct packed {
    logic [31:0] reserved0;
    logic HPM31;
    logic HPM30;
    logic HPM29;
    logic HPM28;
    logic HPM27;
    logic HPM26;
    logic HPM25;
    logic HPM24;
    logic HPM23;
    logic HPM22;
    logic HPM21;
    logic HPM20;
    logic HPM19;
    logic HPM18;
    logic HPM17;
    logic HPM16;
    logic HPM15;
    logic HPM14;
    logic HPM13;
    logic HPM12;
    logic HPM11;
    logic HPM10;
    logic HPM9;
    logic HPM8;
    logic HPM7;
    logic HPM6;
    logic HPM5;
    logic HPM4;
    logic HPM3;
    logic IR;  // Instruction Retired (instret)
    logic TM;  // Timer (bit 1)
    logic CY;  // Cycle (bit 0)
  } mcountinhibit_t;

  function automatic logic [XLEN-1:0] mcountinhibit_get_read_mask();
    mcountinhibit_t mask = '1;
    logic [XLEN-1:0] mask_logic;

    mask.reserved0 = '0;

    mask_logic = mask;
    return mask_logic;
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] mcountinhibit_get_write_mask(
      input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction

  // MHPMEVENT3: Machine HPM Event Selector Register 3
  typedef struct packed {logic [63:0] MHPMEVENT;} mhpmevent_t;

  function automatic logic [XLEN-1:0] mhpmevent_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mhpmevent_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // -------------------------------------------------------------
  // 30. Debug/Trace Registers (shared with Debug Mode)
  // -------------------------------------------------------------
  // とりあえず値を0固定で実装する.

  typedef struct packed {
    logic [63:0] TSELECT;  // bits 63:0  select which data register to access
  } tselect_t;

  function automatic logic [XLEN-1:0] tselect_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] tselect_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // TDATA: Debug/Trace Data Register 
  typedef struct packed {logic [63:0] TDATA;} tdata_t;

  function automatic logic [XLEN-1:0] tdata_get_read_mask();
    return {XLEN{1'b1}};
  endfunction

  function automatic logic [XLEN-1:0] tdata_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // MCONTEXT: Machine Context Save Register
  typedef struct packed {
    logic [63:0] MCONTEXT;  // bits 63:0  holds saved context for debug/halt
  } mcontext_t;

  function automatic logic [XLEN-1:0] mcontext_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] mcontext_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction


  // -------------------------------------------------------------
  // 31. Debug Mode Registers
  // -------------------------------------------------------------
  // 30と同様に0固定.

  // DCSR: Debug Control and Status Register
  typedef struct packed {
    logic [63:0] DCSR;  // bits 63:0  debug status and control flags
  } dcsr_t;

  function automatic logic [XLEN-1:0] dcsr_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] dcsr_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // DPC: Debug PC Register
  typedef struct packed {
    logic [63:0] DPC;  // bits 63:0  program counter for debug resume
  } dpc_t;

  function automatic logic [XLEN-1:0] dpc_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] dpc_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // DSCRATCH0: Debug Scratch Register 0
  typedef struct packed {
    logic [63:0] DSCRATCH;  // bits 63:0  general-purpose debug scratch
  } dscratch_t;

  function automatic logic [XLEN-1:0] dscratch_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] dscratch_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b0}};
  endfunction

  // SSTC

  typedef struct packed {logic [XLEN-1:0] STIMECMP;} stimecmp_t;

  function automatic logic [XLEN-1:0] stimecmp_get_read_mask();
    return {XLEN{1'b1}};
  endfunction


  function automatic logic [XLEN-1:0] stimecmp_get_write_mask(input logic [XLEN-1:0] original_val);
    return {XLEN{1'b1}};
  endfunction


  // csrレジスタ
  typedef union packed {
    logic [XLEN-1:0] as_uint;  // ビットとして直接扱う汎用ビュー

    // --- Unprivileged Floating-Point CSRs ---
    fflags_t as_fflags;  // FFLAGS   = 12'h001
    frm_t    as_frm;     // FRM      = 12'h002
    fcsr_t   as_fcsr;    // FCSR     = 12'h003

    // --- Unprivileged Vector CSRs ---
    vstart_t as_vstart;  // VSTART   = 12'h008
    vxsat_t  as_vxsat;   // VXSAT    = 12'h009
    vxrm_t   as_vxrm;    // VXRM     = 12'h00A
    vcsr_t   as_vcsr;    // VCSR     = 12'h00F
    vl_t     as_vl;      // VL       = 12'hC30
    vtype_t  as_vtype;   // VTYPE    = 12'hC21
    vlenb_t  as_vlenb;   // VLENB    = 12'hC22

    // --- Unprivileged Extensions ---
    ssp_t  as_ssp;   // SSP      = 12'h011 (ZICFISS)
    seed_t as_seed;  // SEED     = 12'h015 (Entropy)
    jvt_t  as_jvt;   // JVT      = 12'h017 (ZCMT)

    // --- Unprivileged Counters/Timers ---
    cycle_t      as_cycle;    // CYCLE       = 12'hC00
    time_t       as_time;     // TIME        = 12'hC01
    instret_t    as_instret;  // INSTRET     = 12'hC02
    hpmcounter_t as_hpm;

    // --- Supervisor Trap Setup ---
    sstatus_t    as_sstatus;     // SSTATUS         = 12'h100
    sie_t        as_sie;         // SIE             = 12'h104
    stvec_t      as_stvec;       // STVEC           = 12'h105
    scounteren_t as_scounteren;  // SCOUNTEREN      = 12'h106

    // --- Supervisor Configuration ---
    senvcfg_t       as_senvcfg;        // SENVCFG         = 12'h10A
    scountinhibit_t as_scountinhibit;  // scountinhibit = 12'h120

    // --- Supervisor Trap Handling ---
    sscratch_t  as_sscratch;  // SSCRATCH        = 12'h140
    sepc_t      as_sepc;      // SEPC            = 12'h141
    scause_t    as_scause;    // SCAUSE          = 12'h142
    stval_t     as_stval;     // STVAL           = 12'h143
    sip_t       as_sip;       // SIP             = 12'h144
    scountovf_t as_scovf;     // SCOUNTOVF       = 12'hDA0

    // --- Supervisor Protection/Translation ---
    satp_t as_satp;  // SATP            = 12'h180

    // --- Debug/Trace Supervisor ---
    scontext_t as_scontext;  // SCONTEXT        = 12'h5A8

    // --- Supervisor State Enable ---
    sstateen_t as_sst_en;

    // --- Machine Information Registers ---
    mvendorid_t  as_mvendorid;   // MVENDORID  = 12'hF11
    marchid_t    as_marchid;     // MARCHID    = 12'hF12
    mimpid_t     as_mimpid;      // MIMPID     = 12'hF13
    mhartid_t    as_mhartid;     // MHARTID    = 12'hF14
    mconfigptr_t as_mconfigptr;  // MCONFIGPTR = 12'hF15

    // --- Machine Trap Setup ---
    mstatus_t    as_mstatus;     // MSTATUS    = 12'h300
    misa_t       as_misa;        // MISA       = 12'h301
    medeleg_t    as_medeleg;     // MEDELEG    = 12'h302
    mideleg_t    as_mideleg;     // MIDELEG    = 12'h303
    mie_t        as_mie;         // MIE        = 12'h304
    mtvec_t      as_mtvec;       // MTVEC      = 12'h305
    mcounteren_t as_mcounteren;  // MCOUNTEREN = 12'h306

    // --- Machine Trap Handling ---
    mscratch_t as_mscratch;  // MSCRATCH   = 12'h340
    mepc_t     as_mepc;      // MEPC       = 12'h341
    mcause_t   as_mcause;    // MCAUSE     = 12'h342
    mtval_t    as_mtval;     // MTVAL      = 12'h343
    mip_t      as_mip;       // MIP        = 12'h344
    mtinst_t   as_mtinst;    // MTINST     = 12'h34A
    mtval2_t   as_mtval2;    // MTVAL2     = 12'h34B

    // --- Machine Configuration ---
    menvcfg_t as_menvcfg;  // MENVCFG    = 12'h30A
    mseccfg_t as_mseccfg;  // MSECCFG    = 12'h747

    // --- Physical Memory Protection (PMP) ---
    pmpcfg_t  as_pmpcfg;
    pmpaddr_t as_pmpaddr;

    // --- Machine State Enable Registers ---
    mstateen_t as_mst_en;

    // --- Non-Maskable Interrupt Handling ---
    mnscratch_t as_mnscratch;  // MNSCRATCH = 12'h740
    mnepc_t     as_mnepc;      // MNEPC     = 12'h741
    mncause_t   as_mncause;    // MNCAUSE   = 12'h742
    mnstatus_t  as_mnstatus;   // MNSTATUS  = 12'h744

    // --- Machine Counter/Timers (shadow) ---
    mcycle_t      as_mcycle;    // MCYCLE        = 12'hB00
    minstret_t    as_minstret;  // MINSTRET      = 12'hB02
    mhpmcounter_t as_mhpm;

    // --- Machine Counter Setup ---
    mcountinhibit_t as_mcountinhibit;  // MCOUNTINHIBIT = 12'h320
    mhpmevent_t    as_mhpmev;

    // --- Debug / Trace Registers (shared) ---
    tselect_t as_tselect;  // TSELECT  = 12'h7A0
    tdata_t as_tdata;
    mcontext_t as_mcontext;  // MCONTEXT = 12'h7A8

    // --- Debug Mode Registers ---
    dcsr_t     as_dcsr;      // DCSR      = 12'h7B0
    dpc_t      as_dpc;       // DPC       = 12'h7B1
    dscratch_t as_dscratch;

    // --- sstc ---
    stimecmp_t as_stimecmp;

  } csr_reg_u;

  // 各種csrに読み込む際のマスクを得る
  function automatic logic [XLEN-1:0] get_read_mask(input csr_name_e csr_name);
    unique case (csr_name)

      // ----------------------------------------
      // Unprivileged Floating-Point CSRs
      // ----------------------------------------
      FFLAGS: return fflags_get_read_mask();
      FRM:    return frm_get_read_mask();
      FCSR:   return fcsr_get_read_mask();

      // ----------------------------------------
      // Unprivileged Vector CSRs
      // ----------------------------------------
      VSTART: return vstart_get_read_mask();
      VXSAT:  return vxsat_get_read_mask();
      VXRM:   return vxrm_get_read_mask();
      VCSR:   return vcsr_get_read_mask();
      VL:     return vl_get_read_mask();
      VTYPE:  return vtype_get_read_mask();
      VLENB:  return vlenb_get_read_mask();

      // ----------------------------------------
      // Unprivileged ZICFISS Extension CSR
      // ----------------------------------------
      SSP: return ssp_get_read_mask();

      // ----------------------------------------
      // Unprivileged Entropy Source Extension CSR
      // ----------------------------------------
      SEED: return seed_get_read_mask();

      // ----------------------------------------
      // Unprivileged ZCMT Extension CSR
      // ----------------------------------------
      JVT: return jvt_get_read_mask();

      // ----------------------------------------
      // Unprivileged Counter/Timers (shadow)
      // ----------------------------------------
      CYCLE: return cycle_get_read_mask();
      TIME: return time_get_read_mask();
      INSTRET: return instret_get_read_mask();
      HPMCOUNTER3,  HPMCOUNTER4, HPMCOUNTER5,  HPMCOUNTER6, HPMCOUNTER7,  HPMCOUNTER8,
      HPMCOUNTER9,  HPMCOUNTER10, HPMCOUNTER11, HPMCOUNTER12, HPMCOUNTER13, HPMCOUNTER14,
      HPMCOUNTER15, HPMCOUNTER16, HPMCOUNTER17, HPMCOUNTER18,  HPMCOUNTER19, HPMCOUNTER20,
      HPMCOUNTER21, HPMCOUNTER22, HPMCOUNTER23, HPMCOUNTER24,   HPMCOUNTER25, HPMCOUNTER26,
      HPMCOUNTER27, HPMCOUNTER28,  HPMCOUNTER29, HPMCOUNTER30,HPMCOUNTER31:
      return hpmcounter_get_read_mask();

      // ----------------------------------------
      // Supervisor Trap Setup
      // ----------------------------------------
      SSTATUS:    return sstatus_get_read_mask();
      SIE:        return sie_get_read_mask();
      STVEC:      return stvec_get_read_mask();
      SCOUNTEREN: return scounteren_get_read_mask();

      // Supervisor Configuration
      SENVCFG: return senvcfg_get_read_mask();

      // Supervisor Counter Setup
      SCOUNTINHIBIT: return scountinhibit_get_read_mask();

      // Supervisor Trap Handling
      SSCRATCH:  return sscratch_get_read_mask();
      SEPC:      return sepc_get_read_mask();
      SCAUSE:    return scause_get_read_mask();
      STVAL:     return stval_get_read_mask();
      SIP:       return sip_get_read_mask();
      SCOUNTOVF: return scountovf_get_read_mask();

      // Supervisor Protection and Translation
      SATP: return satp_get_read_mask();

      // Debug/Trace
      SCONTEXT: return scontext_get_read_mask();

      // Supervisor State Enable Registers
      SSTATEEN0, SSTATEEN1, SSTATEEN2, SSTATEEN3: return sstateen_get_read_mask();

      // ----------------------------------------
      // Machine Information Registers
      // ----------------------------------------
      MVENDORID:  return mvendorid_get_read_mask();
      MARCHID:    return marchid_get_read_mask();
      MIMPID:     return mimpid_get_read_mask();
      MHARTID:    return mhartid_get_read_mask();
      MCONFIGPTR: return mconfigptr_get_read_mask();

      // ----------------------------------------
      // Machine Trap Setup
      // ----------------------------------------
      MSTATUS:    return mstatus_get_read_mask();
      MISA:       return misa_get_read_mask();
      MEDELEG:    return medeleg_get_read_mask();
      MIDELEG:    return mideleg_get_read_mask();
      MIE:        return mie_get_read_mask();
      MTVEC:      return mtvec_get_read_mask();
      MCOUNTEREN: return mcounteren_get_read_mask();

      // Machine Trap Handling
      MSCRATCH: return mscratch_get_read_mask();
      MEPC:     return mepc_get_read_mask();
      MCAUSE:   return mcause_get_read_mask();
      MTVAL:    return mtval_get_read_mask();
      MIP:      return mip_get_read_mask();
      MTINST:   return mtinst_get_read_mask();
      MTVAL2:   return mtval2_get_read_mask();

      // Machine Configuration
      MENVCFG: return menvcfg_get_read_mask();
      MSECCFG: return mseccfg_get_read_mask();

      // ----------------------------------------
      // PMP Config
      // ----------------------------------------
      PMPCFG0, PMPCFG2, PMPCFG4, PMPCFG6, PMPCFG8, PMPCFG10, PMPCFG12, PMPCFG14:
      return pmpcfg_get_read_mask();
      PMPADDR0,  PMPADDR1,  PMPADDR2,  PMPADDR3,
      PMPADDR4,  PMPADDR5,  PMPADDR6,  PMPADDR7,
      PMPADDR8,  PMPADDR9,  PMPADDR10, PMPADDR11,
      PMPADDR12, PMPADDR13, PMPADDR14, PMPADDR15,
      PMPADDR16, PMPADDR17, PMPADDR18, PMPADDR19,
      PMPADDR20, PMPADDR21, PMPADDR22, PMPADDR23,
      PMPADDR24, PMPADDR25, PMPADDR26, PMPADDR27,
      PMPADDR28, PMPADDR29, PMPADDR30, PMPADDR31,
      PMPADDR32, PMPADDR33, PMPADDR34, PMPADDR35,
      PMPADDR36, PMPADDR37, PMPADDR38, PMPADDR39,
      PMPADDR40, PMPADDR41, PMPADDR42, PMPADDR43,
      PMPADDR44, PMPADDR45, PMPADDR46, PMPADDR47,
      PMPADDR48, PMPADDR49, PMPADDR50, PMPADDR51,
      PMPADDR52, PMPADDR53, PMPADDR54, PMPADDR55,
      PMPADDR56, PMPADDR57, PMPADDR58, PMPADDR59,
      PMPADDR60, PMPADDR61, PMPADDR62, PMPADDR63:
      return pmpaddr_get_read_mask();
      // ----------------------------------------
      // Machine State Enable Registers
      // ----------------------------------------
      MSTATEEN0, MSTATEEN1, MSTATEEN2, MSTATEEN3: return mstateen_get_read_mask();
      // ----------------------------------------
      // Machine Non-Maskable Interrupt Handling
      // ----------------------------------------
      MNSCRATCH: return mnscratch_get_read_mask();
      MNEPC: return mnepc_get_read_mask();
      MNCAUSE: return mncause_get_read_mask();
      MNSTATUS: return mnstatus_get_read_mask();

      // ----------------------------------------
      // Machine Counter/Timers (M-mode)
      // ----------------------------------------
      MCYCLE: return mcycle_get_read_mask();
      MINSTRET: return minstret_get_read_mask();
      MHPMCOUNTER3,  MHPMCOUNTER4,
      MHPMCOUNTER5,  MHPMCOUNTER6,
      MHPMCOUNTER7,  MHPMCOUNTER8,
      MHPMCOUNTER9,  MHPMCOUNTER10,
      MHPMCOUNTER11, MHPMCOUNTER12,
      MHPMCOUNTER13, MHPMCOUNTER14,
      MHPMCOUNTER15, MHPMCOUNTER16,
      MHPMCOUNTER17, MHPMCOUNTER18,
      MHPMCOUNTER19, MHPMCOUNTER20,
      MHPMCOUNTER21, MHPMCOUNTER22,
      MHPMCOUNTER23, MHPMCOUNTER24,
      MHPMCOUNTER25, MHPMCOUNTER26,
      MHPMCOUNTER27, MHPMCOUNTER28,
      MHPMCOUNTER29, MHPMCOUNTER30,
      MHPMCOUNTER31:
      return mhpmcounter_get_read_mask();

      // ----------------------------------------
      // Machine Counter Setup
      // ----------------------------------------
      MCOUNTINHIBIT: return mcountinhibit_get_read_mask();
      MHPMEVENT3,  MHPMEVENT4,
      MHPMEVENT5,  MHPMEVENT6,
      MHPMEVENT7,  MHPMEVENT8,
      MHPMEVENT9,  MHPMEVENT10,
      MHPMEVENT11, MHPMEVENT12,
      MHPMEVENT13, MHPMEVENT14,
      MHPMEVENT15, MHPMEVENT16,
      MHPMEVENT17, MHPMEVENT18,
      MHPMEVENT19, MHPMEVENT20,
      MHPMEVENT21, MHPMEVENT22,
      MHPMEVENT23, MHPMEVENT24,
      MHPMEVENT25, MHPMEVENT26,
      MHPMEVENT27, MHPMEVENT28,
      MHPMEVENT29, MHPMEVENT30,
      MHPMEVENT31:
      return mhpmevent_get_read_mask();

      // ----------------------------------------
      // Debug/Trace Registers (shared with Debug Mode)
      // ----------------------------------------
      TSELECT: return tselect_get_read_mask();
      TDATA1, TDATA2, TDATA3: return tdata_get_read_mask();
      MCONTEXT: return mcontext_get_read_mask();

      // Debug Mode Registers
      DCSR:                 return dcsr_get_read_mask();
      DPC:                  return dpc_get_read_mask();
      DSCRATCH0, DSCRATCH1: return dscratch_get_read_mask();

      // ----------------------------------------------------
      // Sstc
      // -----------------------------------------------------
      STIMECMP: return stimecmp_get_read_mask();

      // ----------------------------------------
      // default
      // ----------------------------------------
      default: begin
        // $display("[ERROR][%s,%-0d] get_read_mask: unsupported CSR 0x%0h", `__FILE__, `__LINE__,
        //          csr_name);
        return '0;
      end

    endcase
  endfunction


  // 各種csrに書き込む際のマスクを得る.
  // 各種csrに書き込む際のマスクを得る.
  function automatic logic [XLEN-1:0] get_write_mask(input csr_name_e csr_name,
                                                     input logic [XLEN-1:0] original_val);
    unique case (csr_name)

      // ----------------------------------------
      // Unprivileged Floating-Point CSRs
      // ----------------------------------------
      FFLAGS: return fflags_get_write_mask(original_val);
      FRM:    return frm_get_write_mask(original_val);
      FCSR:   return fcsr_get_write_mask(original_val);

      // ----------------------------------------
      // Unprivileged Vector CSRs
      // ----------------------------------------
      VSTART: return vstart_get_write_mask(original_val);
      VXSAT:  return vxsat_get_write_mask(original_val);
      VXRM:   return vxrm_get_write_mask(original_val);
      VCSR:   return vcsr_get_write_mask(original_val);
      VL:     return vl_get_write_mask(original_val);
      VTYPE:  return vtype_get_write_mask(original_val);
      VLENB:  return vlenb_get_write_mask(original_val);

      // ----------------------------------------
      // Unprivileged ZICFISS Extension CSR
      // ----------------------------------------
      SSP: return ssp_get_write_mask(original_val);

      // ----------------------------------------
      // Unprivileged Entropy Source Extension CSR
      // ----------------------------------------
      SEED: return seed_get_write_mask(original_val);

      // ----------------------------------------
      // Unprivileged ZCMT Extension CSR
      // ----------------------------------------
      JVT: return jvt_get_write_mask(original_val);

      // ----------------------------------------
      // Unprivileged Counter/Timers (shadow)
      // ----------------------------------------
      CYCLE: return cycle_get_write_mask(original_val);
      TIME: return time_get_write_mask(original_val);
      INSTRET: return instret_get_write_mask(original_val);
      HPMCOUNTER3,  HPMCOUNTER4, HPMCOUNTER5,  HPMCOUNTER6, HPMCOUNTER7,  HPMCOUNTER8,
      HPMCOUNTER9,  HPMCOUNTER10, HPMCOUNTER11, HPMCOUNTER12, HPMCOUNTER13, HPMCOUNTER14,
      HPMCOUNTER15, HPMCOUNTER16, HPMCOUNTER17, HPMCOUNTER18,  HPMCOUNTER19, HPMCOUNTER20,
      HPMCOUNTER21, HPMCOUNTER22, HPMCOUNTER23, HPMCOUNTER24,   HPMCOUNTER25, HPMCOUNTER26,
      HPMCOUNTER27, HPMCOUNTER28,  HPMCOUNTER29, HPMCOUNTER30,HPMCOUNTER31:
      return hpmcounter_get_write_mask(original_val);

      // ----------------------------------------
      // Supervisor Trap Setup
      // ----------------------------------------
      SSTATUS:    return sstatus_get_write_mask(original_val);
      SIE:        return sie_get_write_mask(original_val);
      STVEC:      return stvec_get_write_mask(original_val);
      SCOUNTEREN: return scounteren_get_write_mask(original_val);

      // Supervisor Configuration
      SENVCFG: return senvcfg_get_write_mask(original_val);

      // Supervisor Counter Setup
      SCOUNTINHIBIT: return scountinhibit_get_write_mask(original_val);

      // Supervisor Trap Handling
      SSCRATCH:  return sscratch_get_write_mask(original_val);
      SEPC:      return sepc_get_write_mask(original_val);
      SCAUSE:    return scause_get_write_mask(original_val);
      STVAL:     return stval_get_write_mask(original_val);
      SIP:       return sip_get_write_mask(original_val);
      SCOUNTOVF: return scountovf_get_write_mask(original_val);

      // Supervisor Protection and Translation
      SATP: return satp_get_write_mask(original_val);

      // Debug/Trace
      SCONTEXT: return scontext_get_write_mask(original_val);

      // Supervisor State Enable Registers
      SSTATEEN0, SSTATEEN1, SSTATEEN2, SSTATEEN3: return sstateen_get_write_mask(original_val);

      // ----------------------------------------
      // Machine Information Registers
      // ----------------------------------------
      MVENDORID:  return mvendorid_get_write_mask(original_val);
      MARCHID:    return marchid_get_write_mask(original_val);
      MIMPID:     return mimpid_get_write_mask(original_val);
      MHARTID:    return mhartid_get_write_mask(original_val);
      MCONFIGPTR: return mconfigptr_get_write_mask(original_val);

      // ----------------------------------------
      // Machine Trap Setup
      // ----------------------------------------
      MSTATUS:    return mstatus_get_write_mask(original_val);
      MISA:       return misa_get_write_mask(original_val);
      MEDELEG:    return medeleg_get_write_mask(original_val);
      MIDELEG:    return mideleg_get_write_mask(original_val);
      MIE:        return mie_get_write_mask(original_val);
      MTVEC:      return mtvec_get_write_mask(original_val);
      MCOUNTEREN: return mcounteren_get_write_mask(original_val);

      // Machine Trap Handling
      MSCRATCH: return mscratch_get_write_mask(original_val);
      MEPC:     return mepc_get_write_mask(original_val);
      MCAUSE:   return mcause_get_write_mask(original_val);
      MTVAL:    return mtval_get_write_mask(original_val);
      MIP:      return mip_get_write_mask(original_val);
      MTINST:   return mtinst_get_write_mask(original_val);
      MTVAL2:   return mtval2_get_write_mask(original_val);

      // Machine Configuration
      MENVCFG: return menvcfg_get_write_mask(original_val);
      MSECCFG: return mseccfg_get_write_mask(original_val);

      // ----------------------------------------
      // PMP Config
      // ----------------------------------------
      PMPCFG0, PMPCFG2, PMPCFG4, PMPCFG6, PMPCFG8, PMPCFG10, PMPCFG12, PMPCFG14:
      return pmpcfg_get_write_mask(original_val);
      PMPADDR0,  PMPADDR1,  PMPADDR2,  PMPADDR3,
      PMPADDR4,  PMPADDR5,  PMPADDR6,  PMPADDR7,
      PMPADDR8,  PMPADDR9,  PMPADDR10, PMPADDR11,
      PMPADDR12, PMPADDR13, PMPADDR14, PMPADDR15,
      PMPADDR16, PMPADDR17, PMPADDR18, PMPADDR19,
      PMPADDR20, PMPADDR21, PMPADDR22, PMPADDR23,
      PMPADDR24, PMPADDR25, PMPADDR26, PMPADDR27,
      PMPADDR28, PMPADDR29, PMPADDR30, PMPADDR31,
      PMPADDR32, PMPADDR33, PMPADDR34, PMPADDR35,
      PMPADDR36, PMPADDR37, PMPADDR38, PMPADDR39,
      PMPADDR40, PMPADDR41, PMPADDR42, PMPADDR43,
      PMPADDR44, PMPADDR45, PMPADDR46, PMPADDR47,
      PMPADDR48, PMPADDR49, PMPADDR50, PMPADDR51,
      PMPADDR52, PMPADDR53, PMPADDR54, PMPADDR55,
      PMPADDR56, PMPADDR57, PMPADDR58, PMPADDR59,
      PMPADDR60, PMPADDR61, PMPADDR62, PMPADDR63:
      return pmpaddr_get_write_mask(original_val);
      // ----------------------------------------
      // Machine State Enable Registers
      // ----------------------------------------
      MSTATEEN0, MSTATEEN1, MSTATEEN2, MSTATEEN3: return mstateen_get_write_mask(original_val);
      // ----------------------------------------
      // Machine Non-Maskable Interrupt Handling
      // ----------------------------------------
      MNSCRATCH: return mnscratch_get_write_mask(original_val);
      MNEPC: return mnepc_get_write_mask(original_val);
      MNCAUSE: return mncause_get_write_mask(original_val);
      MNSTATUS: return mnstatus_get_write_mask(original_val);

      // ----------------------------------------
      // Machine Counter/Timers (M-mode)
      // ----------------------------------------
      MCYCLE: return mcycle_get_write_mask(original_val);
      MINSTRET: return minstret_get_write_mask(original_val);
      MHPMCOUNTER3,  MHPMCOUNTER4,
      MHPMCOUNTER5,  MHPMCOUNTER6,
      MHPMCOUNTER7,  MHPMCOUNTER8,
      MHPMCOUNTER9,  MHPMCOUNTER10,
      MHPMCOUNTER11, MHPMCOUNTER12,
      MHPMCOUNTER13, MHPMCOUNTER14,
      MHPMCOUNTER15, MHPMCOUNTER16,
      MHPMCOUNTER17, MHPMCOUNTER18,
      MHPMCOUNTER19, MHPMCOUNTER20,
      MHPMCOUNTER21, MHPMCOUNTER22,
      MHPMCOUNTER23, MHPMCOUNTER24,
      MHPMCOUNTER25, MHPMCOUNTER26,
      MHPMCOUNTER27, MHPMCOUNTER28,
      MHPMCOUNTER29, MHPMCOUNTER30,
      MHPMCOUNTER31:
      return mhpmcounter_get_write_mask(original_val);

      // ----------------------------------------
      // Machine Counter Setup
      // ----------------------------------------
      MCOUNTINHIBIT: return mcountinhibit_get_write_mask(original_val);
      MHPMEVENT3,  MHPMEVENT4,
      MHPMEVENT5,  MHPMEVENT6,
      MHPMEVENT7,  MHPMEVENT8,
      MHPMEVENT9,  MHPMEVENT10,
      MHPMEVENT11, MHPMEVENT12,
      MHPMEVENT13, MHPMEVENT14,
      MHPMEVENT15, MHPMEVENT16,
      MHPMEVENT17, MHPMEVENT18,
      MHPMEVENT19, MHPMEVENT20,
      MHPMEVENT21, MHPMEVENT22,
      MHPMEVENT23, MHPMEVENT24,
      MHPMEVENT25, MHPMEVENT26,
      MHPMEVENT27, MHPMEVENT28,
      MHPMEVENT29, MHPMEVENT30,
      MHPMEVENT31:
      return mhpmevent_get_write_mask(original_val);

      // ----------------------------------------
      // Debug/Trace Registers (shared with Debug Mode)
      // ----------------------------------------
      TSELECT: return tselect_get_write_mask(original_val);
      TDATA1, TDATA2, TDATA3: return tdata_get_write_mask(original_val);
      MCONTEXT: return mcontext_get_write_mask(original_val);

      // Debug Mode Registers
      DCSR:                 return dcsr_get_write_mask(original_val);
      DPC:                  return dpc_get_write_mask(original_val);
      DSCRATCH0, DSCRATCH1: return dscratch_get_write_mask(original_val);

      // ---------------------------------------------------------
      // Sstc
      // ----------------------------------------------------------
      STIMECMP: return stimecmp_get_write_mask(original_val);

      // ----------------------------------------
      // default
      // ----------------------------------------
      default: begin
        // $display("[ERROR][%s,%-0d] get_write_mask: unsupported CSR 0x%0h", `__FILE__, `__LINE__,
        //          csr_name);
        return '0;
      end

    endcase
  endfunction


endpackage

`endif
