// TLCS-90.c
// Generated by decompiling TLCS-90.corpus
// using Reko decompiler version 0.8.2.0.

#include "TLCS-90.h"

// 0000: void fn0000(Register cu8 a, Stack ui16 wArg00)
void fn0000(cu8 a, ui16 wArg00)
{
	null = (cu8 *) a;
}

// 02F4: Register word16 fn02F4(Register byte a, Register byte b, Register cu8 c, Register Eq_n de, Register ptr16 hl, Register (ptr16 Eq_n) ix, Register out Eq_n deOut, Register out Eq_n hlOut, Register out Eq_n ixOut)
word16 fn02F4(byte a, byte b, cu8 c, Eq_n de, ptr16 hl, Eq_n * ix, Eq_n & deOut, Eq_n & hlOut, Eq_n & ixOut)
{
	cu8 a_n = (bool) C + (a + ix->bFFFFFFE4);
	ui8 a_n = b ^ ix->bFFFFFFFB;
	ui8 a_n = a_n ^ ix->bFFFFFFFC;
	ui8 a_n = (bool) (a_n < 0x00) + (h + ix->bFFFFFFE5) ^ ix->bFFFFFFFD;
	uint8 a_n = ix->bFFFFFFF6 + (c ^ ix->bFFFFFFFA);
	ix->bFFFFFFF6 = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFF7 + a_n);
	ix->bFFFFFFF7 = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFF8 + a_n);
	ix->bFFFFFFF8 = a_n;
	ix->bFFFFFFF9 = (uint8) ((bool) (a_n < 0x00) + (ix->bFFFFFFF9 + a_n));
	uint8 c_n = ix->bFFFFFFF6;
	uint8 b_n = ix->bFFFFFFF7;
	ui16 hl_n = DPB(hl, ix->bFFFFFFF9, 8);
	byte a_n;
	for (a_n = 0x04; a_n != 0x00; --a_n)
	{
		c_n <<= 0x01;
		b_n = __rcl(b_n, 0x01, (bool) cond(c_n));
		hl_n = hl_n * 0x02 + (b_n < 0x00);
		uint8 h_n = SLICE(hl_n, byte, 8);
		uint8 l_n = (byte) hl_n;
	}
	uint8 a_n = c_n + ix->bFFFFFFDE;
	word16 de_n;
	word16 hl_n;
	word16 ix_n;
	return fn034E(a_n, c_n, b_n, de, l_n, h_n, ix, out de_n, out hl_n, out ix_n);
}

// 034E: Register word16 fn034E(Register uint8 a, Register uint8 c, Register uint8 b, Register Eq_n de, Register uint8 l, Register uint8 h, Register (ptr16 Eq_n) ix, Register out Eq_n deOut, Register out Eq_n hlOut, Register out Eq_n ixOut)
word16 fn034E(uint8 a, uint8 c, uint8 b, Eq_n de, uint8 l, uint8 h, Eq_n * ix, Eq_n & deOut, Eq_n & hlOut, Eq_n & ixOut)
{
	ix->bFFFFFFFA = a;
	word16 de_n;
	word16 hl_n;
	word16 ix_n;
	return fn03B2(a, c, b, de, l, h, ix, wArg24, out de_n, out hl_n, out ix_n);
}

// 039D: void fn039D(Register byte a, Register Eq_n de, Register byte h, Register (ptr16 Eq_n) ix)
void fn039D(byte a, Eq_n de, byte h, Eq_n * ix)
{
	ix->bFFFFFFFD = a ^ h;
	uint8 v12_n = ix->bFFFFFFF6;
	uint8 v14_n = ix->bFFFFFFF7;
	uint8 v16_n = ix->bFFFFFFF8;
	uint8 v18_n = ix->bFFFFFFF9;
	word16 de_n;
	word16 hl_n;
	word16 ix_n;
	fn03B2(0x05, v12_n, v14_n, de, v16_n, v18_n, ix, wArg24, out de_n, out hl_n, out ix_n);
}

// 03AA: void fn03AA()
void fn03AA()
{
}

// 03B2: Register word16 fn03B2(Register uint8 a, Register uint8 c, Register uint8 b, Register Eq_n de, Register uint8 l, Register uint8 h, Register (ptr16 Eq_n) ix, Stack Eq_n wArg24, Register out Eq_n deOut, Register out Eq_n hlOut, Register out Eq_n ixOut)
word16 fn03B2(uint8 a, uint8 c, uint8 b, Eq_n de, uint8 l, uint8 h, Eq_n * ix, Eq_n wArg24, Eq_n & deOut, Eq_n & hlOut, Eq_n & ixOut)
{
}

// 04EE: void fn04EE(Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix)
void fn04EE(Eq_n de, word16 hl, Eq_n * ix)
{
	ix->bFFFFFFDB = 55;
	ix->bFFFFFFDC = ~0x10;
	ix->bFFFFFFDD = 0xC6;
	uint8 c_n = ix->bFFFFFFE6;
	uint8 b_n = ix->bFFFFFFE7;
	ui16 hl_n = DPB(hl, ix->bFFFFFFE9, 8);
	byte a_n;
	for (a_n = 0x04; a_n != 0x00; --a_n)
	{
		c_n <<= 0x01;
		b_n = __rcl(b_n, 0x01, (bool) cond(c_n));
		hl_n = hl_n * 0x02 + (b_n < 0x00);
		byte h_n = SLICE(hl_n, byte, 8);
		byte l_n = (byte) hl_n;
	}
	uint8 a_n = c_n + ix->bFFFFFFF6;
	ix->bFFFFFFFC = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (b_n + ix->bFFFFFFF7);
	ix->bFFFFFFFD = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFF8);
	ix->bFFFFFFFE = a_n;
	ix->bFFFFFFFF = (ui8) ((bool) (a_n < 0x00) + (h_n + ix->bFFFFFFF9));
	cu8 a_n = ix->bFFFFFFE6 + ix->bFFFFFFDA;
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE7 + ix->bFFFFFFDB);
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE8 + ix->bFFFFFFDC);
	byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE9 + ix->bFFFFFFDD);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_n;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_n;
	ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_n;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_n;
	uint8 v43_n = ix->bFFFFFFE9;
	uint8 c_n = ix->bFFFFFFE6;
	uint8 b_n = ix->bFFFFFFE7;
	uint8 l_n = ix->bFFFFFFE8;
	uint8 h_n = v43_n;
	ui16 hl_n = DPB(hl_n, v43_n, 8);
	byte a_n;
	for (a_n = 0x05; a_n != 0x00; --a_n)
	{
		h_n >>= 0x01;
		l_n = __rcr(l_n, 0x01, (bool) cond(h_n));
		b_n = __rcr(b_n, 0x01, (bool) cond(l_n));
		hl_n = DPB(hl_n, l_n, 0);
		c_n = __rcr(c_n, 0x01, (bool) cond(b_n));
	}
	uint8 a_n = c_n + ix->bFFFFFFEA;
	cu8 a_n = (bool) (a_n < 0x00) + (b_n + ix->bFFFFFFEB);
	cu8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFEC);
	ui8 a_n = a_n ^ ix->bFFFFFFFD;
	ui8 a_n = a_n ^ ix->bFFFFFFFE;
	ui8 a_n = h_n + ix->bFFFFFFED + (a_n < 0x00) ^ ix->bFFFFFFFF;
	uint8 a_n = ix->bFFFFFFDE - (a_n ^ ix->bFFFFFFFC);
	ix->bFFFFFFDE = a_n;
	uint8 a_n = ix->bFFFFFFDF - a_n - (a_n < 0x00);
	ix->bFFFFFFDF = a_n;
	uint8 a_n = ix->bFFFFFFE0 - a_n - (a_n < 0x00);
	ix->bFFFFFFE0 = a_n;
	ix->bFFFFFFE1 = ix->bFFFFFFE1 - a_n - (a_n < 0x00);
	uint8 c_n = ix->bFFFFFFDE;
	uint8 b_n = ix->bFFFFFFDF;
	ui16 hl_n = DPB(hl_n, ix->bFFFFFFE1, 8);
	byte a_n;
	for (a_n = 0x04; a_n != 0x00; --a_n)
	{
		c_n <<= 0x01;
		b_n = __rcl(b_n, 0x01, (bool) cond(c_n));
		hl_n = hl_n * 0x02 + (b_n < 0x00);
		byte h_n = SLICE(hl_n, byte, 8);
		byte l_n = (byte) hl_n;
	}
	uint8 a_n = c_n + ix->bFFFFFFEE;
	ix->bFFFFFFFC = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (b_n + ix->bFFFFFFEF);
	ix->bFFFFFFFD = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFF0);
	ix->bFFFFFFFE = a_n;
	ix->bFFFFFFFF = (ui8) ((bool) (a_n < 0x00) + (h_n + ix->bFFFFFFF1));
	cu8 a_n = ix->bFFFFFFDE + ix->bFFFFFFDA;
	uint8 v66_n = ix->bFFFFFFDF;
	fn060E(v66_n, a_n, de, ix, wArg20);
}

// 0607: void fn0607(Register byte a, Register Eq_n de, Register (ptr16 Eq_n) ix)
void fn0607(byte a, Eq_n de, Eq_n * ix)
{
	cu8 a_n = a + ix->bFFFFFFDA;
	uint8 v9_n = ix->bFFFFFFDF;
	fn060E(v9_n, a_n, de, ix, wArg20);
}

// 060E: void fn060E(Register uint8 a, Register cu8 c, Register Eq_n de, Register (ptr16 Eq_n) ix, Stack Eq_n wArg20)
void fn060E(uint8 a, cu8 c, Eq_n de, Eq_n * ix, Eq_n wArg20)
{
	do
	{
		cu8 a_n = (bool) C + (a + ix->bFFFFFFDB);
		cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE0 + ix->bFFFFFFDC);
		byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE1 + ix->bFFFFFFDD);
		ix->bFFFFFFFC = ix->bFFFFFFFC ^ c;
		ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_n;
		ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_n;
		ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_n;
		uint8 c_n = ix->bFFFFFFDE;
		uint8 b_n = ix->bFFFFFFDF;
		uint8 l_n = ix->bFFFFFFE0;
		uint8 h_n = ix->bFFFFFFE1;
		byte a_n;
		for (a_n = 0x05; a_n != 0x00; --a_n)
		{
			h_n >>= 0x01;
			l_n = __rcr(l_n, 0x01, (bool) cond(h_n));
			b_n = __rcr(b_n, 0x01, (bool) cond(l_n));
			c_n = __rcr(c_n, 0x01, (bool) cond(b_n));
		}
		cu8 a_n = c_n + ix->bFFFFFFF2;
		cu8 a_n = (bool) (a_n < 0x00) + (b_n + ix->bFFFFFFF3);
		cu8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFF4);
		ui8 a_n = a_n ^ ix->bFFFFFFFD;
		ui8 a_n = a_n ^ ix->bFFFFFFFE;
		ui8 a_n = h_n + ix->bFFFFFFF5 + (a_n < 0x00) ^ ix->bFFFFFFFF;
		uint8 a_n = ix->bFFFFFFE6 - (a_n ^ ix->bFFFFFFFC);
		ix->bFFFFFFE6 = a_n;
		uint8 a_n = ix->bFFFFFFE7 - a_n - (a_n < 0x00);
		ix->bFFFFFFE7 = a_n;
		uint8 a_n = ix->bFFFFFFE8 - a_n - (a_n < 0x00);
		ix->bFFFFFFE8 = a_n;
		ix->bFFFFFFE9 = ix->bFFFFFFE9 - a_n - (a_n < 0x00);
		cu8 v44_n = ix->bFFFFFFDA;
		ix->bFFFFFFDA = v44_n + 0x47;
		cu8 a_n = (bool) (v44_n < 0x47) + (ix->bFFFFFFDB + 0x86);
		ix->bFFFFFFDB = a_n;
		cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFDC + 200);
		ix->bFFFFFFDC = a_n;
		ix->bFFFFFFDD = (bool) (a_n < 0x00) + (ix->bFFFFFFDD + 0x61);
		cu8 v48_n = ix->bFFFFFFE2;
		cu8 a_n = (bool) (v48_n < ~0x00) + (ix->bFFFFFFE3 + ~0x00);
		cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE4 + ~0x00);
		byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE5 + ~0x00);
		ix->bFFFFFFE2 = v48_n + ~0x00;
		ix->bFFFFFFE3 = a_n;
		ix->bFFFFFFE4 = a_n;
		ix->bFFFFFFE5 = a_n;
		c = v48_n + ~0x00;
		a = a_n | a_n | a_n | v48_n + ~0x00;
		C.u0 = false;
	} while (a != 0x00);
	Eq_n hl_n = fp + 0x0C;
	word16 bc_n;
	for (bc_n = 0x04; bc_n != 0x00; --bc_n)
	{
		*de = *hl_n;
		hl_n = (word32) hl_n + 0x01;
		de = (word32) de + 0x01;
	}
	Eq_n de_n = wArg20;
	Eq_n hl_n = fp + 0x04;
	word16 bc_n;
	for (bc_n = 0x04; bc_n != 0x00; --bc_n)
	{
		*de_n = *hl_n;
		hl_n = (word32) hl_n + 0x01;
		de_n = (word32) de_n + 0x01;
	}
}

// 0805: void fn0805(Register byte a)
void fn0805(byte a)
{
	__disable_interrupts();
	fn0823(wLoc02);
	fn0822();
	__halt();
}

// 0822: void fn0822()
void fn0822()
{
	fn0823(wLoc02);
}

// 0823: void fn0823(Stack word16 wArg00)
void fn0823(word16 wArg00)
{
}

// 0C1D: void fn0C1D(Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix, Stack word16 wArg00)
void fn0C1D(Eq_n de, word16 hl, Eq_n * ix, word16 wArg00)
{
	uint8 c_n = ix->bFFFFFFE6;
	uint8 b_n = ix->bFFFFFFE7;
	byte * hl_n = DPB(hl, ix->bFFFFFFE9, 8);
	byte a_n;
	for (a_n = 0x04; a_n != 0x00; --a_n)
	{
		c_n <<= 0x01;
		b_n = __rcl(b_n, 0x01, (bool) cond(c_n));
		hl_n = hl_n * 0x02 + (b_n < 0x00);
	}
	fn0C35(c_n, b_n, de, hl_n, ix);
}

// 0C35: void fn0C35(Register uint8 c, Register uint8 b, Register Eq_n de, Register (ptr16 byte) hl, Register (ptr16 Eq_n) ix)
void fn0C35(uint8 c, uint8 b, Eq_n de, byte * hl, Eq_n * ix)
{
	uint8 a_n = c + ix->bFFFFFFF6;
	ix->bFFFFFFFC = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (b + ix->bFFFFFFF7);
	ix->bFFFFFFFD = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (l + ix->bFFFFFFF8);
	ix->bFFFFFFFE = a_n;
	ix->bFFFFFFFF = (ui8) ((bool) (a_n < 0x00) + (h + ix->bFFFFFFF9));
	cu8 a_n = ix->bFFFFFFE6 + ix->bFFFFFFDA;
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE7 + ix->bFFFFFFDB);
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE8 + ix->bFFFFFFDC);
	byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE9 + ix->bFFFFFFDD);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_n;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_n;
	ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_n;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_n;
	uint8 v32_n = ix->bFFFFFFE6;
	uint8 v33_n = ix->bFFFFFFE7;
	word16 hl_n = DPB(hl, ix->bFFFFFFE9, 8);
	fn0C9D(0x05, v32_n, v33_n, de, hl_n, ix);
}

// 0C39: void fn0C39(Register uint8 a, Register byte b, Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix)
void fn0C39(uint8 a, byte b, Eq_n de, word16 hl, Eq_n * ix)
{
	ix->bFFFFFFFC = a;
	uint8 a_n = (bool) C + (b + ix->bFFFFFFF7);
	ix->bFFFFFFFD = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (l + ix->bFFFFFFF8);
	ix->bFFFFFFFE = a_n;
	ix->bFFFFFFFF = (ui8) ((bool) (a_n < 0x00) + (h + ix->bFFFFFFF9));
	cu8 a_n = ix->bFFFFFFE6 + ix->bFFFFFFDA;
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE7 + ix->bFFFFFFDB);
	word16 hl_n = DPB(hl, (bool) ((bool) (a_n < 0x00) + (ix->bFFFFFFE8 + ix->bFFFFFFDC) < 0x00) + (ix->bFFFFFFE9 + ix->bFFFFFFDD), 8);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_n;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_n;
	uint8 v28_n = ix->bFFFFFFFE;
	fn0C80(v28_n, de, hl_n, ix);
}

// 0C80: void fn0C80(Register uint8 a, Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix)
void fn0C80(uint8 a, Eq_n de, word16 hl, Eq_n * ix)
{
	ix->bFFFFFFFE = a ^ l;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ h;
	uint8 v14_n = ix->bFFFFFFE6;
	uint8 v16_n = ix->bFFFFFFE7;
	word16 hl_n = DPB(hl, ix->bFFFFFFE9, 8);
	fn0C9D(0x05, v14_n, v16_n, de, hl_n, ix);
}

// 0C9D: void fn0C9D(Register byte a, Register uint8 c, Register uint8 b, Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix)
void fn0C9D(byte a, uint8 c, uint8 b, Eq_n de, word16 hl, Eq_n * ix)
{
	do
	{
		h >>= 0x01;
		l = __rcr(l, 0x01, (bool) cond(h));
		b = __rcr(b, 0x01, (bool) cond(l));
		hl = DPB(hl, l, 0);
		c = __rcr(c, 0x01, (bool) cond(b));
		--a;
	} while (a != 0x00);
	cu8 a_n = c + ix->bFFFFFFEA;
	cu8 a_n = (bool) (a_n < 0x00) + (b + ix->bFFFFFFEB);
	cu8 a_n = (bool) (a_n < 0x00) + (l + ix->bFFFFFFEC);
	ui8 a_n = a_n ^ ix->bFFFFFFFD;
	ui8 a_n = a_n ^ ix->bFFFFFFFE;
	ui8 a_n = h + ix->bFFFFFFED + (a_n < 0x00) ^ ix->bFFFFFFFF;
	uint8 a_n = ix->bFFFFFFDE - (a_n ^ ix->bFFFFFFFC);
	ix->bFFFFFFDE = a_n;
	uint8 a_n = ix->bFFFFFFDF - a_n - (a_n < 0x00);
	ix->bFFFFFFDF = a_n;
	uint8 a_n = ix->bFFFFFFE0 - a_n - (a_n < 0x00);
	ix->bFFFFFFE0 = a_n;
	ix->bFFFFFFE1 = ix->bFFFFFFE1 - a_n - (a_n < 0x00);
	uint8 v31_n = ix->bFFFFFFDE;
	uint8 v32_n = ix->bFFFFFFDF;
	ui16 hl_n = DPB(hl, ix->bFFFFFFE1, 8);
	fn0D00(0x04, v32_n, v31_n, de, hl_n, ix);
}

// 0CB7: void fn0CB7(Register byte b, Register byte c, Register Eq_n de, Register word16 hl, Register (ptr16 Eq_n) ix)
void fn0CB7(byte b, byte c, Eq_n de, word16 hl, Eq_n * ix)
{
	ui8 a_n = b ^ ix->bFFFFFFFD;
	ui8 a_n = l ^ ix->bFFFFFFFE;
	ui8 a_n = (bool) C + (h + ix->bFFFFFFED) ^ ix->bFFFFFFFF;
	uint8 a_n = ix->bFFFFFFDE - (c ^ ix->bFFFFFFFC);
	ix->bFFFFFFDE = a_n;
	uint8 a_n = ix->bFFFFFFDF - a_n - (a_n < 0x00);
	ix->bFFFFFFDF = a_n;
	uint8 a_n = ix->bFFFFFFE0 - a_n - (a_n < 0x00);
	ix->bFFFFFFE0 = a_n;
	ix->bFFFFFFE1 = ix->bFFFFFFE1 - a_n - (a_n < 0x00);
	uint8 v25_n = ix->bFFFFFFDE;
	uint8 v26_n = ix->bFFFFFFDF;
	ui16 hl_n = DPB(hl, ix->bFFFFFFE1, 8);
	fn0D00(0x04, v26_n, v25_n, de, hl_n, ix);
}

// 0D00: void fn0D00(Register byte a, Register uint8 b, Register uint8 c, Register Eq_n de, Register ui16 hl, Register (ptr16 Eq_n) ix)
void fn0D00(byte a, uint8 b, uint8 c, Eq_n de, ui16 hl, Eq_n * ix)
{
	do
	{
		c <<= 0x01;
		b = __rcl(b, 0x01, (bool) cond(c));
		hl = hl * 0x02 + (b < 0x00);
		byte l_n = (byte) hl;
		byte h_n = SLICE(hl, byte, 8);
		--a;
	} while (a != 0x00);
	uint8 a_n = c + ix->bFFFFFFEE;
	ix->bFFFFFFFC = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (b + ix->bFFFFFFEF);
	ix->bFFFFFFFD = a_n;
	uint8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFF0);
	ix->bFFFFFFFE = a_n;
	ix->bFFFFFFFF = (ui8) ((bool) (a_n < 0x00) + (h_n + ix->bFFFFFFF1));
	cu8 a_n = ix->bFFFFFFDE + ix->bFFFFFFDA;
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFDF + ix->bFFFFFFDB);
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE0 + ix->bFFFFFFDC);
	byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE1 + ix->bFFFFFFDD);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_n;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_n;
	ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_n;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_n;
	uint8 c_n = ix->bFFFFFFDE;
	uint8 b_n = ix->bFFFFFFDF;
	uint8 l_n = ix->bFFFFFFE0;
	uint8 h_n = ix->bFFFFFFE1;
	byte a_n;
	for (a_n = 0x05; a_n != 0x00; --a_n)
	{
		h_n >>= 0x01;
		l_n = __rcr(l_n, 0x01, (bool) cond(h_n));
		b_n = __rcr(b_n, 0x01, (bool) cond(l_n));
		c_n = __rcr(c_n, 0x01, (bool) cond(b_n));
	}
	cu8 a_n = c_n + ix->bFFFFFFF2;
	cu8 a_n = (bool) (a_n < 0x00) + (b_n + ix->bFFFFFFF3);
	cu8 a_n = (bool) (a_n < 0x00) + (l_n + ix->bFFFFFFF4);
	ui8 a_n = a_n ^ ix->bFFFFFFFD;
	ui8 a_n = a_n ^ ix->bFFFFFFFE;
	ui8 a_n = h_n + ix->bFFFFFFF5 + (a_n < 0x00) ^ ix->bFFFFFFFF;
	uint8 a_n = ix->bFFFFFFE6 - (a_n ^ ix->bFFFFFFFC);
	ix->bFFFFFFE6 = a_n;
	uint8 a_n = ix->bFFFFFFE7 - a_n - (a_n < 0x00);
	ix->bFFFFFFE7 = a_n;
	uint8 a_n = ix->bFFFFFFE8 - a_n - (a_n < 0x00);
	ix->bFFFFFFE8 = a_n;
	ix->bFFFFFFE9 = ix->bFFFFFFE9 - a_n - (a_n < 0x00);
	cu8 v52_n = ix->bFFFFFFDA;
	ix->bFFFFFFDA = v52_n + 0x47;
	cu8 a_n = (bool) (v52_n < 0x47) + (ix->bFFFFFFDB + 0x86);
	ix->bFFFFFFDB = a_n;
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFDC + 200);
	ix->bFFFFFFDC = a_n;
	ix->bFFFFFFDD = (bool) (a_n < 0x00) + (ix->bFFFFFFDD + 0x61);
	cu8 v56_n = ix->bFFFFFFE2;
	cu8 a_n = (bool) (v56_n < ~0x00) + (ix->bFFFFFFE3 + ~0x00);
	cu8 a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE4 + ~0x00);
	byte a_n = (bool) (a_n < 0x00) + (ix->bFFFFFFE5 + ~0x00);
	ix->bFFFFFFE2 = v56_n + ~0x00;
	ix->bFFFFFFE3 = a_n;
	ix->bFFFFFFE4 = a_n;
	ix->bFFFFFFE5 = a_n;
	uint8 a_n = a_n | a_n | a_n | v56_n + ~0x00;
	if (a_n != 0x00)
		fn060E(a_n, v56_n + ~0x00, de, ix, wArg20);
	else
		fn0E13(de, ix, wArg20);
}

// 0DFC: void fn0DFC(Register cu8 c, Register cu8 b, Register Eq_n de, Register byte h, Register cu8 l, Register (ptr16 Eq_n) ix)
void fn0DFC(cu8 c, cu8 b, Eq_n de, byte h, cu8 l, Eq_n * ix)
{
	ix->bFFFFFFE2 = c;
	ix->bFFFFFFE3 = b;
	ix->bFFFFFFE4 = l;
	ix->bFFFFFFE5 = h;
	uint8 a_n = h | l | b | c;
	if (a_n != 0x00)
		fn060E(a_n, c, de, ix, wArg20);
	else
		fn0E13(de, ix, wArg20);
}

// 0E13: void fn0E13(Register Eq_n de, Register (ptr16 Eq_n) ix, Stack Eq_n wArg20)
void fn0E13(Eq_n de, Eq_n * ix, Eq_n wArg20)
{
	Eq_n hl_n = fp + 0x0C;
	word16 bc_n;
	for (bc_n = 0x04; bc_n != 0x00; --bc_n)
	{
		*de = *hl_n;
		hl_n = (word32) hl_n + 0x01;
		++de;
	}
	Eq_n de_n = wArg20;
	Eq_n hl_n = fp + 0x04;
	word16 bc_n;
	for (bc_n = 0x04; bc_n != 0x00; --bc_n)
	{
		*de_n = *hl_n;
		hl_n = (word32) hl_n + 0x01;
		++de_n;
	}
}

// 0F9A: void fn0F9A(Stack word16 wArg00)
void fn0F9A(word16 wArg00)
{
}

// 164F: void fn164F(Register cu8 a, Register byte b, Register byte c, Register byte h, Register (ptr16 Eq_n) ix, Stack Eq_n wArg13, Stack (ptr16 Eq_n) wArg1B)
void fn164F(cu8 a, byte b, byte c, byte h, Eq_n * ix, Eq_n wArg13, Eq_n * wArg1B)
{
	ix->bFFFFFFEC = a;
	ix->bFFFFFFED = ix->bFFFFFFF9 - h - C;
	byte a_n = ix->bFFFFFFF9 - ix->bFFFFFFFD - (ix->bFFFFFFF8 - ix->bFFFFFFFC < 0x00);
	cu8 a_n = c - wArg1B->b0000;
	ptr16 hl_n = DPB(&wArg1B->b0001, a_n, 8);
	Eq_n de_n;
	word16 hl_n;
	struct Eq_n * ix_n;
	word16 bc_n = fn02F4(a_n, b - wArg1B->b0001 - (a_n < 0x00), a_n, wArg13, hl_n, ix, out de_n, out hl_n, out ix_n);
	uint8 b_n = SLICE(bc_n, byte, 8);
	uint8 c_n = (byte) bc_n;
	if ((byte) hl_n != 0x00)
	{
		struct Eq_n * v30_n = fp->ptr0015;
		struct Eq_n * v33_n = fp->ptr0013;
		byte v31_n = v30_n->b0000;
		byte v32_n = v30_n->b0001;
		byte v36_n = v33_n->b0001;
		cu8 a_n = v31_n - v33_n->b0000;
		ix_n->bFFFFFFEC = a_n;
		ix_n->bFFFFFFED = v32_n - v36_n - (a_n < 0x00);
		struct Eq_n * v38_n = fp->ptr001F;
		struct Eq_n * v41_n = fp->ptr000C;
		cu8 v39_n = v38_n->b0000;
		byte v40_n = v38_n->b0001;
		byte v43_n = v41_n->b0001;
		cu8 a_n = v39_n - v41_n->b0000;
		ix_n->bFFFFFFEA = a_n;
		ix_n->bFFFFFFEB = v40_n - v43_n - (a_n < 0x00);
		struct Eq_n * v44_n = fp->ptr0019;
		cu8 a_n = v31_n - v44_n->b0000;
		struct Eq_n * v47_n = fp->ptr0023;
		byte a_n = v32_n - v44_n->b0001 - (a_n < 0x00);
		byte a_n = v40_n - v47_n->b0001 - (v39_n - v47_n->b0000 < 0x00);
		*(fp - 0x04) = fp->w0011;
		ptr16 v51_n = fp->ptr000F;
		*(fp - 0x06) = v51_n;
		*(fp - 0x08) = DPB(bc_n, a_n, 8);
		Eq_n de_n = DPB(de_n, a_n, 8);
		*(fp - 0x0A) = (union Eq_n *) de_n;
		Eq_n de_n;
		word16 hl_n;
		struct Eq_n * ix_n;
		word16 bc_n = fn02F4(a_n, a_n, a_n, de_n, v51_n, ix_n, out de_n, out hl_n, out ix_n);
		uint8 b_n = SLICE(bc_n, byte, 8);
		uint8 c_n = (byte) bc_n;
		if ((byte) v51_n != 0x00)
		{
			byte * hl_n = DPB(hl_n, 0x00, 0);
			fn0C35(c_n, b_n, de_n, hl_n, ix_n);
		}
		else
		{
			byte * hl_n = DPB(hl_n, 0x03, 0);
			fn0C35(c_n, b_n, de_n, hl_n, ix_n);
		}
	}
	else
	{
		byte * hl_n = DPB(hl_n, 0x03, 0);
		fn0C35(c_n, b_n, de_n, hl_n, ix_n);
	}
}

// 1873: void fn1873(Register uint8 b, Register uint8 c, Register Eq_n de, Register byte h, Register (ptr16 Eq_n) ix, Stack (ptr16 Eq_n) wArg13)
void fn1873(uint8 b, uint8 c, Eq_n de, byte h, Eq_n * ix, Eq_n * wArg13)
{
	wArg13->b0000 = c;
	wArg13->b0001 = b;
	byte * hl_n = DPB(&wArg13->b0001, 0x02, 0);
	fn0C35(c, b, de, hl_n, ix);
}

// 1BA4: void fn1BA4(Register byte a, Register word16 bc, Register word16 de, Register ui16 hl, Register (ptr16 Eq_n) ix, Stack word16 wArg00, Stack word16 wArg10, Stack word16 wArg1D, Stack word16 wArg1F)
void fn1BA4(byte a, word16 bc, word16 de, ui16 hl, Eq_n * ix, word16 wArg00, word16 wArg10, word16 wArg1D, word16 wArg1F)
{
	fn0805(a);
	byte l_n = (byte) wArg1D;
	ui16 hl_n = hl * 0x08 + DPB(de, h, 8) + bc;
	Eq_n de_n = DPB(wArg00, l_n, 0);
	cu8 a_n = 0x03 - l_n;
	if (a_n < 0x00)
		fn1BF9(bc, de_n, ix);
	else
	{
		switch (a_n)
		{
		case 0x00:
			fn0000(a_n, hl_n);
			return;
		}
	}
}

// 1BDE: void fn1BDE(Register word16 bc, Register Eq_n de, Register (ptr16 Eq_n) ix)
void fn1BDE(word16 bc, Eq_n de, Eq_n * ix)
{
	++ix->bFFFFFFE9;
	ix->bFFFFFFFF = ix->bFFFFFFE9;
	fn1BF9(bc, de, ix);
}

// 1BF9: void fn1BF9(Register word16 bc, Register Eq_n de, Register (ptr16 Eq_n) ix)
void fn1BF9(word16 bc, Eq_n de, Eq_n * ix)
{
	cu8 v4_n = ix->bFFFFFFF7;
	ix->bFFFFFFF7 = v4_n + 0x09;
	ix->bFFFFFFF8 = (bool) (v4_n < 0x09) + ix->bFFFFFFF8;
	++ix->bFFFFFFF5;
	word16 bc_n;
	Eq_n hl_n = 0x0823;
	do
	{
		*de = *hl_n;
		++hl_n;
		de = (word32) de + 0x01;
		--bc_n;
	} while (bc_n != 0x00);
}

// 1C89: void fn1C89(Register byte a, Register byte c, Stack word16 wArg00)
void fn1C89(byte a, byte c, word16 wArg00)
{
}

// 22A6: void fn22A6(Register word16 bc, Register (ptr16 Eq_n) ix, Stack word16 wArg03, Stack word16 wArg05, Stack (ptr16 Eq_n) wArg07, Stack ptr16 wArg0D, Stack word16 wArg10)
void fn22A6(word16 bc, Eq_n * ix, word16 wArg03, word16 wArg05, Eq_n * wArg07, ptr16 wArg0D, word16 wArg10)
{
	ix->bFFFFFFFC = ix->bFFFFFFF7;
	ix->bFFFFFFFD = 0x00;
	struct Eq_n * hl_n = DPB(wArg10 + (wArg05 + 0x01), 0x00, 8) * 0x08 + DPB(wArg05 + 0x01, 0x00, 8) + bc;
	ix->bFFFFFFF8 = hl_n->b0002;
	ix->bFFFFFFF9 = hl_n->b0003;
	struct Eq_n * hl_n = DPB(wArg10 + (wArg05 + 0x03), 0x00, 8) * 0x08 + DPB(wArg05 + 0x03, 0x00, 8) + DPB(bc, (wArg0D + DPB(bc, SLICE(DPB(wArg10 + (wArg05 + 0x02), 0x00, 8) * 0x02 + DPB(bc, 0x00, 8), byte, 8), 8))->b0001, 8);
	byte v49_n = hl_n->b0000;
	byte v50_n = hl_n->b0001;
	fn03AA();
	wArg07->b0000 = v49_n;
	wArg07->b0001 = v50_n;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	wArg07->b0002 = v50_n;
}

// 3E2D: void fn3E2D(Register word16 bc, Register (ptr16 Eq_n) ix, Stack word16 wArg03, Stack word16 wArg05, Stack (ptr16 Eq_n) wArg07, Stack ptr16 wArg0D, Stack word16 wArg10)
void fn3E2D(word16 bc, Eq_n * ix, word16 wArg03, word16 wArg05, Eq_n * wArg07, ptr16 wArg0D, word16 wArg10)
{
	ix->bFFFFFFFC = ix->bFFFFFFF7;
	ix->bFFFFFFFD = 0x00;
	struct Eq_n * hl_n = DPB(wArg10 + (wArg05 + 0x01), 0x00, 8) * 0x08 + DPB(wArg05 + 0x01, 0x00, 8) + bc;
	ix->bFFFFFFF8 = hl_n->b0002;
	ix->bFFFFFFF9 = hl_n->b0003;
	struct Eq_n * hl_n = DPB(wArg10 + (wArg05 + 0x03), 0x00, 8) * 0x08 + DPB(wArg05 + 0x03, 0x00, 8) + DPB(bc, (wArg0D + DPB(bc, SLICE(DPB(wArg10 + (wArg05 + 0x02), 0x00, 8) * 0x02 + DPB(bc, 0x00, 8), byte, 8), 8))->b0001, 8);
	byte v49_n = hl_n->b0000;
	byte v50_n = hl_n->b0001;
	fn03AA();
	wArg07->b0000 = v49_n;
	wArg07->b0001 = v50_n;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	wArg07->b0002 = v50_n;
}

