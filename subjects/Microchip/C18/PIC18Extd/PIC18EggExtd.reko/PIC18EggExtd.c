// PIC18EggExtd.c
// Generated by decompiling PIC18EggExtd.hex
// using Reko decompiler version 0.8.2.0.

#include "PIC18EggExtd.h"

// 00000000: void fn00000000()
void fn00000000()
{
	Stack[0x01].ptr0000 = 0x0148;
	fn00000E(0x00, 0x00);
}

// 00000E: void fn00000E(Register Eq_n FSR0, Register word24 TBLPTR)
void fn00000E(Eq_n FSR0, word24 TBLPTR)
{
	__tblrd(TBLPTR, 0x01);
	0x00->b00C5 = TABLAT;
	__tblrd(TBLPTR, 0x01);
	0x00->b00C6 = TABLAT;
	byte TBLPTRL_n = 0x06;
	byte TBLPTRH_n = 0x00;
	byte TBLPTRU_n = 0x00;
	Eq_n Z_n = cond(TABLAT);
	while (true)
	{
		if (!Z_n && 0x00->b00C5 == 0x00)
			return;
		__tblrd(TBLPTR, 0x01);
		0x00->b00C0 = TABLAT;
		__tblrd(TBLPTR, 0x01);
		0x00->b00C1 = TABLAT;
		__tblrd(TBLPTR, 0x01);
		0x00->b00C2 = TABLAT;
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		0x00->b00C3 = TABLAT;
		__tblrd(TBLPTR, 0x01);
		0x00->b00C4 = TABLAT;
		__tblrd(TBLPTR, 0x01);
		__tblrd(TBLPTR, 0x01);
		globals->b00C7 = TBLPTRL_n;
		globals->b00C8 = TBLPTRH_n;
		globals->b00C9 = TBLPTRU_n;
		0x00->b00C3 = 0x00->b00C3;
		Eq_n Z_n = cond(0x00->b00C3);
l000080:
		if (Z_n)
			break;
		0x00->b00C4 = 0x00->b00C4;
		if (0x00->b00C4 != 0x00)
			break;
		TBLPTRL_n = globals->b00C7;
		TBLPTRH_n = globals->b00C8;
		TBLPTRU_n = globals->b00C9;
		0x00->b00C5 = 0x00->b00C5 - 0x01;
		0x00->b00C6 = 0x00->b00C6 - !cond(0x00->b00C5);
		Z_n = cond(0x00->b00C6);
	}
	while (true)
	{
		__tblrd(TBLPTR, 0x01);
		*FSR0 = TABLAT;
		0x00->b00C3 = 0x00->b00C3 - 0x01;
		++FSR0;
		Z_n = cond(0x00->b00C3);
		if (0x00->b00C3 < 0x00)
			break;
		0x00->b00C4 = 0x00->b00C4 - 0x01;
	}
	goto l000080;
}

// 0000D0: void fn0000D0(Register byte LATB, Register byte FSR2L, Register ptr16 FSR2, Register (ptr16 byte) FSR1)
void fn0000D0(byte LATB, byte FSR2L, ptr16 FSR2, byte * FSR1)
{
	*FSR1 = FSR2L;
	while (*(FSR2 - 0x02) != 0x00)
	{
		if ((0x00->b00CA & 0x01) != 0x00)
		{
			0x00->b00CA = 0x00->b00CA & ~0x01;
			if ((LATB & 0x01) != 0x00)
				LATB |= 0x80;
			else
				LATB &= 0x7F;
		}
	}
}

// 000128: void fn000128(Register cu8 WREG, Register cu8 FSR0L, Register cu8 FSR0H, Register Eq_n FSR0)
void fn000128(cu8 WREG, cu8 FSR0L, cu8 FSR0H, Eq_n FSR0)
{
	while (FSR0H < WREG)
	{
		*FSR0 = 0x00;
		FSR0 = (word32) FSR0 + 0x01;
	}
	while (FSR0L < PRODL)
	{
		*FSR0 = 0x00;
		FSR0 = (word32) FSR0 + 0x01;
	}
}

