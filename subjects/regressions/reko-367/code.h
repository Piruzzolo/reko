// code.h
// Generated by decompiling code.bin
// using Reko decompiler version 0.8.2.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals" (80000538 real96 r80000538))
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_2: (fn void ())
	T_2 (in fn800003CC : ptr32)
	T_3 (in signature of fn800003CC : void)
Eq_35: (fn real80 (real96, real96))
	T_35 (in fn80000132 : ptr32)
	T_36 (in signature of fn80000132 : void)
	T_63 (in fn80000132 : ptr32)
	T_96 (in fn80000132 : ptr32)
Eq_42: (fn real80 (real96))
	T_42 (in fn8000018E : ptr32)
	T_43 (in signature of fn8000018E : void)
	T_72 (in fn8000018E : ptr32)
	T_102 (in fn8000018E : ptr32)
Eq_53: (union "Eq_53" (real80 u0) (ptr32 u1))
	T_53 (in fp2Out : Eq_53)
	T_89 (in out fp2_28 : ptr32)
	T_114 (in out fp2_40 : ptr32)
Eq_79: (fn void (real96))
	T_79 (in fn800001F2 : ptr32)
	T_80 (in signature of fn800001F2 : void)
	T_106 (in fn800001F2 : ptr32)
Eq_85: (fn real80 (real96, Eq_53))
	T_85 (in fn800002AE : ptr32)
	T_86 (in signature of fn800002AE : void)
	T_111 (in fn800002AE : ptr32)
Eq_116: (fn void (real96))
	T_116 (in fn8000036C : ptr32)
	T_117 (in signature of fn8000036C : void)
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in fn800003CC : ptr32)
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: (ptr32 (fn T_4 ()))
T_3: (in signature of fn800003CC : void)
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: 
T_4: (in fn800003CC() : void)
  Class: Eq_4
  DataType: void
  OrigDataType: void
T_5: (in fp0 : real80)
  Class: Eq_5
  DataType: real80
  OrigDataType: real80
T_6: (in rArg04 : real96)
  Class: Eq_6
  DataType: real96
  OrigDataType: real96
T_7: (in rArg10 : real96)
  Class: Eq_7
  DataType: real96
  OrigDataType: real96
T_8: (in dwLoc14_16 : word32)
  Class: Eq_8
  DataType: word32
  OrigDataType: word32
T_9: (in 0x00000000 : word32)
  Class: Eq_8
  DataType: word32
  OrigDataType: word32
T_10: (in rLoc24 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_11: (in dwLoc10 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_12: (in DPB(rLoc24, dwLoc10, 0) : real96)
  Class: Eq_12
  DataType: real96
  OrigDataType: real96
T_13: (in (real80) DPB(rLoc24, dwLoc10, 0) : real80)
  Class: Eq_5
  DataType: real80
  OrigDataType: real80
T_14: (in 0x00000001 : word32)
  Class: Eq_14
  DataType: word32
  OrigDataType: word32
T_15: (in dwLoc14_16 + 0x00000001 : word32)
  Class: Eq_8
  DataType: word32
  OrigDataType: word32
T_16: (in (real80) dwLoc14_16 : real80)
  Class: Eq_16
  DataType: real80
  OrigDataType: real80
T_17: (in (real96) (real80) dwLoc14_16 : real96)
  Class: Eq_7
  DataType: real96
  OrigDataType: real96
T_18: (in (real96) (real80) dwLoc14_16 >= rArg10 : bool)
  Class: Eq_18
  DataType: bool
  OrigDataType: bool
T_19: (in fp0 : real80)
  Class: Eq_19
  DataType: real80
  OrigDataType: real80
T_20: (in rArg04 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_21: (in dwLoc14_18 : int32)
  Class: Eq_21
  DataType: int32
  OrigDataType: int32
T_22: (in 1 : int32)
  Class: Eq_21
  DataType: int32
  OrigDataType: int32
T_23: (in rLoc24 : real96)
  Class: Eq_23
  DataType: real96
  OrigDataType: real96
T_24: (in dwLoc10 : word32)
  Class: Eq_24
  DataType: word32
  OrigDataType: word32
T_25: (in DPB(rLoc24, dwLoc10, 0) : real96)
  Class: Eq_25
  DataType: real96
  OrigDataType: real96
T_26: (in (real80) DPB(rLoc24, dwLoc10, 0) : real80)
  Class: Eq_19
  DataType: real80
  OrigDataType: real80
T_27: (in 0x00000001 : word32)
  Class: Eq_27
  DataType: word32
  OrigDataType: word32
T_28: (in dwLoc14_18 + 0x00000001 : word32)
  Class: Eq_21
  DataType: int32
  OrigDataType: int32
T_29: (in (real80) dwLoc14_18 : real80)
  Class: Eq_29
  DataType: real80
  OrigDataType: real80
T_30: (in (real96) (real80) dwLoc14_18 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_31: (in (real96) (real80) dwLoc14_18 > rArg04 : bool)
  Class: Eq_31
  DataType: bool
  OrigDataType: bool
T_32: (in rArg04 : real96)
  Class: Eq_32
  DataType: real96
  OrigDataType: real96
T_33: (in dwLoc20_25 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_34: (in 3 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_35: (in fn80000132 : ptr32)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: (ptr32 (fn T_41 (T_38, T_40)))
T_36: (in signature of fn80000132 : void)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: 
T_37: (in (real80) rArg04 : real80)
  Class: Eq_37
  DataType: real80
  OrigDataType: real80
T_38: (in (real96) (real80) rArg04 : real96)
  Class: Eq_6
  DataType: real96
  OrigDataType: real96
T_39: (in (real80) dwLoc20_25 : real80)
  Class: Eq_39
  DataType: real80
  OrigDataType: real80
T_40: (in (real96) (real80) dwLoc20_25 : real96)
  Class: Eq_7
  DataType: real96
  OrigDataType: real96
T_41: (in fn80000132((real96) (real80) rArg04, (real96) (real80) dwLoc20_25) : real80)
  Class: Eq_41
  DataType: real80
  OrigDataType: real80
T_42: (in fn8000018E : ptr32)
  Class: Eq_42
  DataType: (ptr32 Eq_42)
  OrigDataType: (ptr32 (fn T_46 (T_45)))
T_43: (in signature of fn8000018E : void)
  Class: Eq_42
  DataType: (ptr32 Eq_42)
  OrigDataType: 
T_44: (in (real80) dwLoc20_25 : real80)
  Class: Eq_44
  DataType: real80
  OrigDataType: real80
T_45: (in (real96) (real80) dwLoc20_25 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_46: (in fn8000018E((real96) (real80) dwLoc20_25) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_47: (in 0x00000002 : word32)
  Class: Eq_47
  DataType: word32
  OrigDataType: word32
T_48: (in dwLoc20_25 + 0x00000002 : word32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_49: (in 100 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_50: (in dwLoc20_25 > 100 : bool)
  Class: Eq_50
  DataType: bool
  OrigDataType: bool
T_51: (in fp0 : real80)
  Class: Eq_51
  DataType: real80
  OrigDataType: real80
T_52: (in rArg04 : real96)
  Class: Eq_52
  DataType: real96
  OrigDataType: real96
T_53: (in fp2Out : Eq_53)
  Class: Eq_53
  DataType: Eq_53
  OrigDataType: ptr32
T_54: (in dwLoc20_24 : int32)
  Class: Eq_54
  DataType: int32
  OrigDataType: int32
T_55: (in 2 : int32)
  Class: Eq_54
  DataType: int32
  OrigDataType: int32
T_56: (in fp2_102 : real80)
  Class: Eq_56
  DataType: real80
  OrigDataType: real80
T_57: (in fp2 : real80)
  Class: Eq_57
  DataType: real80
  OrigDataType: real80
T_58: (in *fp2Out : real80)
  Class: Eq_57
  DataType: real80
  OrigDataType: real80
T_59: (in rLoc3C : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_60: (in dwLoc10 : word32)
  Class: Eq_60
  DataType: word32
  OrigDataType: word32
T_61: (in DPB(rLoc3C, dwLoc10, 0) : real96)
  Class: Eq_61
  DataType: real96
  OrigDataType: real96
T_62: (in (real80) DPB(rLoc3C, dwLoc10, 0) : real80)
  Class: Eq_51
  DataType: real80
  OrigDataType: real80
T_63: (in fn80000132 : ptr32)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: (ptr32 (fn T_68 (T_65, T_67)))
T_64: (in (real80) rArg04 : real80)
  Class: Eq_64
  DataType: real80
  OrigDataType: real80
T_65: (in (real96) (real80) rArg04 : real96)
  Class: Eq_6
  DataType: real96
  OrigDataType: real96
T_66: (in (real80) dwLoc20_24 : real80)
  Class: Eq_66
  DataType: real80
  OrigDataType: real80
T_67: (in (real96) (real80) dwLoc20_24 : real96)
  Class: Eq_7
  DataType: real96
  OrigDataType: real96
T_68: (in fn80000132((real96) (real80) rArg04, (real96) (real80) dwLoc20_24) : real80)
  Class: Eq_41
  DataType: real80
  OrigDataType: real80
T_69: (in v19_59 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_70: (in (real80) dwLoc20_24 : real80)
  Class: Eq_70
  DataType: real80
  OrigDataType: real80
T_71: (in (real96) (real80) dwLoc20_24 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_72: (in fn8000018E : ptr32)
  Class: Eq_42
  DataType: (ptr32 Eq_42)
  OrigDataType: (ptr32 (fn T_73 (T_69)))
T_73: (in fn8000018E(v19_59) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_74: (in 0x00000002 : word32)
  Class: Eq_74
  DataType: word32
  OrigDataType: word32
T_75: (in dwLoc20_24 + 0x00000002 : word32)
  Class: Eq_54
  DataType: int32
  OrigDataType: int32
T_76: (in 100 : int32)
  Class: Eq_54
  DataType: int32
  OrigDataType: int32
T_77: (in dwLoc20_24 > 100 : bool)
  Class: Eq_77
  DataType: bool
  OrigDataType: bool
T_78: (in rArg04 : real96)
  Class: Eq_78
  DataType: real96
  OrigDataType: real96
T_79: (in fn800001F2 : ptr32)
  Class: Eq_79
  DataType: (ptr32 Eq_79)
  OrigDataType: (ptr32 (fn T_83 (T_82)))
T_80: (in signature of fn800001F2 : void)
  Class: Eq_79
  DataType: (ptr32 Eq_79)
  OrigDataType: 
T_81: (in (real80) rArg04 : real80)
  Class: Eq_81
  DataType: real80
  OrigDataType: real80
T_82: (in (real96) (real80) rArg04 : real96)
  Class: Eq_32
  DataType: real96
  OrigDataType: real96
T_83: (in fn800001F2((real96) (real80) rArg04) : void)
  Class: Eq_83
  DataType: void
  OrigDataType: void
T_84: (in fp2_28 : real80)
  Class: Eq_84
  DataType: real80
  OrigDataType: real80
T_85: (in fn800002AE : ptr32)
  Class: Eq_85
  DataType: (ptr32 Eq_85)
  OrigDataType: (ptr32 (fn T_90 (T_88, T_89)))
T_86: (in signature of fn800002AE : void)
  Class: Eq_85
  DataType: (ptr32 Eq_85)
  OrigDataType: 
T_87: (in (real80) rArg04 : real80)
  Class: Eq_87
  DataType: real80
  OrigDataType: real80
T_88: (in (real96) (real80) rArg04 : real96)
  Class: Eq_52
  DataType: real96
  OrigDataType: real96
T_89: (in out fp2_28 : ptr32)
  Class: Eq_53
  DataType: Eq_53
  OrigDataType: (union (real80 u0) (ptr32 u1))
T_90: (in fn800002AE((real96) (real80) rArg04, out fp2_28) : real80)
  Class: Eq_90
  DataType: real80
  OrigDataType: real80
T_91: (in v6_9 : real96)
  Class: Eq_91
  DataType: real96
  OrigDataType: real96
T_92: (in 80000538 : ptr32)
  Class: Eq_92
  DataType: (ptr32 real96)
  OrigDataType: (ptr32 (struct (0 T_93 t0000)))
T_93: (in Mem0[0x80000538:real96] : real96)
  Class: Eq_93
  DataType: real96
  OrigDataType: real96
T_94: (in (real80) Mem0[0x80000538:real96] : real80)
  Class: Eq_94
  DataType: real80
  OrigDataType: real80
T_95: (in (real96) (real80) Mem0[0x80000538:real96] : real96)
  Class: Eq_91
  DataType: real96
  OrigDataType: real96
T_96: (in fn80000132 : ptr32)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: (ptr32 (fn T_101 (T_98, T_100)))
T_97: (in (real80) v6_9 : real80)
  Class: Eq_97
  DataType: real80
  OrigDataType: real80
T_98: (in (real96) (real80) v6_9 : real96)
  Class: Eq_6
  DataType: real96
  OrigDataType: real96
T_99: (in (real80) v6_9 : real80)
  Class: Eq_99
  DataType: real80
  OrigDataType: real80
T_100: (in (real96) (real80) v6_9 : real96)
  Class: Eq_7
  DataType: real96
  OrigDataType: real96
T_101: (in fn80000132((real96) (real80) v6_9, (real96) (real80) v6_9) : real80)
  Class: Eq_41
  DataType: real80
  OrigDataType: real80
T_102: (in fn8000018E : ptr32)
  Class: Eq_42
  DataType: (ptr32 Eq_42)
  OrigDataType: (ptr32 (fn T_105 (T_104)))
T_103: (in (real80) v6_9 : real80)
  Class: Eq_103
  DataType: real80
  OrigDataType: real80
T_104: (in (real96) (real80) v6_9 : real96)
  Class: Eq_20
  DataType: real96
  OrigDataType: real96
T_105: (in fn8000018E((real96) (real80) v6_9) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_106: (in fn800001F2 : ptr32)
  Class: Eq_79
  DataType: (ptr32 Eq_79)
  OrigDataType: (ptr32 (fn T_109 (T_108)))
T_107: (in (real80) v6_9 : real80)
  Class: Eq_107
  DataType: real80
  OrigDataType: real80
T_108: (in (real96) (real80) v6_9 : real96)
  Class: Eq_32
  DataType: real96
  OrigDataType: real96
T_109: (in fn800001F2((real96) (real80) v6_9) : void)
  Class: Eq_83
  DataType: void
  OrigDataType: void
T_110: (in fp2_40 : real80)
  Class: Eq_110
  DataType: real80
  OrigDataType: real80
T_111: (in fn800002AE : ptr32)
  Class: Eq_85
  DataType: (ptr32 Eq_85)
  OrigDataType: (ptr32 (fn T_115 (T_113, T_114)))
T_112: (in (real80) v6_9 : real80)
  Class: Eq_112
  DataType: real80
  OrigDataType: real80
T_113: (in (real96) (real80) v6_9 : real96)
  Class: Eq_52
  DataType: real96
  OrigDataType: real96
T_114: (in out fp2_40 : ptr32)
  Class: Eq_53
  DataType: Eq_53
  OrigDataType: (union (real80 u0) (ptr32 u1))
T_115: (in fn800002AE((real96) (real80) v6_9, out fp2_40) : real80)
  Class: Eq_90
  DataType: real80
  OrigDataType: real80
T_116: (in fn8000036C : ptr32)
  Class: Eq_116
  DataType: (ptr32 Eq_116)
  OrigDataType: (ptr32 (fn T_120 (T_119)))
T_117: (in signature of fn8000036C : void)
  Class: Eq_116
  DataType: (ptr32 Eq_116)
  OrigDataType: 
T_118: (in (real80) v6_9 : real80)
  Class: Eq_118
  DataType: real80
  OrigDataType: real80
T_119: (in (real96) (real80) v6_9 : real96)
  Class: Eq_78
  DataType: real96
  OrigDataType: real96
T_120: (in fn8000036C((real96) (real80) v6_9) : void)
  Class: Eq_120
  DataType: void
  OrigDataType: void
*/
typedef struct Globals {
	real96 r80000538;	// 80000538
} Eq_1;

typedef void (Eq_2)();

typedef real80 (Eq_35)(real96, real96);

typedef real80 (Eq_42)(real96);

typedef union Eq_53 {
	real80 u0;
	ptr32 u1;
} Eq_53;

typedef void (Eq_79)(real96);

typedef real80 (Eq_85)(real96, Eq_53);

typedef void (Eq_116)(real96);

