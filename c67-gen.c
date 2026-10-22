/*
 *  TMS320C67xx code generator for TCC
 * 
 *  Copyright (c) 2001, 2002 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#جيڪڏهن_وصف_ٿيل هدف_DEFS_ONLY

/* #define ASSEMBLY_LISTING_C67 */

/* number of available registers */
#وصف_ڪريو NB_REGS            24

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#وصف_ڪريو RC_INT     0x0001	/* generic integer register */
#وصف_ڪريو RC_FLOAT   0x0002	/* generic float register */
#وصف_ڪريو RC_EAX     0x0004
#وصف_ڪريو RC_ST0     0x0008
#وصف_ڪريو RC_ECX     0x0010
#وصف_ڪريو RC_EDX     0x0020
#وصف_ڪريو RC_INT_BSIDE  0x00000040	/* generic integer register  on b side */
#وصف_ڪريو RC_C67_A4     0x00000100
#وصف_ڪريو RC_C67_A5     0x00000200
#وصف_ڪريو RC_C67_B4     0x00000400
#وصف_ڪريو RC_C67_B5     0x00000800
#وصف_ڪريو RC_C67_A6     0x00001000
#وصف_ڪريو RC_C67_A7     0x00002000
#وصف_ڪريو RC_C67_B6     0x00004000
#وصف_ڪريو RC_C67_B7     0x00008000
#وصف_ڪريو RC_C67_A8     0x00010000
#وصف_ڪريو RC_C67_A9     0x00020000
#وصف_ڪريو RC_C67_B8     0x00040000
#وصف_ڪريو RC_C67_B9     0x00080000
#وصف_ڪريو RC_C67_A10    0x00100000
#وصف_ڪريو RC_C67_A11    0x00200000
#وصف_ڪريو RC_C67_B10    0x00400000
#وصف_ڪريو RC_C67_B11    0x00800000
#وصف_ڪريو RC_C67_A12    0x01000000
#وصف_ڪريو RC_C67_A13    0x02000000
#وصف_ڪريو RC_C67_B12    0x04000000
#وصف_ڪريو RC_C67_B13    0x08000000
#وصف_ڪريو RC_IRET    RC_C67_A4	/* function return: integer register */
#وصف_ڪريو RC_IRE2    RC_C67_A5	/* function return: second integer register */
#وصف_ڪريو RC_FRET    RC_C67_A4	/* function return: float register */

/* pretty names for the registers */
تعداد {
    TREG_EAX = 0,		// really A2
    TREG_ECX,			// really A3
    TREG_EDX,			// really B0
    TREG_ST0,			// really B1
    TREG_C67_A4,
    TREG_C67_A5,
    TREG_C67_B4,
    TREG_C67_B5,
    TREG_C67_A6,
    TREG_C67_A7,
    TREG_C67_B6,
    TREG_C67_B7,
    TREG_C67_A8,
    TREG_C67_A9,
    TREG_C67_B8,
    TREG_C67_B9,
    TREG_C67_A10,
    TREG_C67_A11,
    TREG_C67_B10,
    TREG_C67_B11,
    TREG_C67_A12,
    TREG_C67_A13,
    TREG_C67_B12,
    TREG_C67_B13,
};

/* return registers for function */
#وصف_ڪريو REG_IRET TREG_C67_A4	/* single word int return register */
#وصف_ڪريو REG_IRE2 TREG_C67_A5    /* second word return register (for long long) */
#وصف_ڪريو REG_FRET TREG_C67_A4	/* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#وصف_ڪريو PTR_سائيز 4

/* long double size and alignment, in bytes */
#وصف_ڪريو LDOUBLE_سائيز  12
#وصف_ڪريو LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#وصف_ڪريو MAX_ALIGN     8

#وصف_رد CONFIG_TCC_BCHECK

/******************************************************/
#وإلا /* ! TARGET_DEFS_ONLY */
/******************************************************/
#وصف_ڪريو USING_GLOBALS
#ضمن "tcc.h"

ST_معلومات ثابت حرف * ثابت هدف_machine_defs =
    "__C67__\0"
    ;

ST_معلومات ثابت صحيح reg_classes[NB_REGS] = {
    /* eax */ RC_INT | RC_FLOAT | RC_EAX,
    // only allow even regs for floats (allow for doubles)
    /* ecx */ RC_INT | RC_ECX,
    /* edx */ RC_INT | RC_INT_BSIDE | RC_FLOAT | RC_EDX,
    // only allow even regs for floats (allow for doubles)
    /* st0 */ RC_INT | RC_INT_BSIDE | RC_ST0,
    /* A4  */ RC_C67_A4,
    /* A5  */ RC_C67_A5,
    /* B4  */ RC_C67_B4,
    /* B5  */ RC_C67_B5,
    /* A6  */ RC_C67_A6,
    /* A7  */ RC_C67_A7,
    /* B6  */ RC_C67_B6,
    /* B7  */ RC_C67_B7,
    /* A8  */ RC_C67_A8,
    /* A9  */ RC_C67_A9,
    /* B8  */ RC_C67_B8,
    /* B9  */ RC_C67_B9,
    /* A10  */ RC_C67_A10,
    /* A11  */ RC_C67_A11,
    /* B10  */ RC_C67_B10,
    /* B11  */ RC_C67_B11,
    /* A12  */ RC_C67_A10,
    /* A13  */ RC_C67_A11,
    /* B12  */ RC_C67_B10,
    /* B13  */ RC_C67_B11
};

// although tcc thinks it is passing parameters on the stack,
// the C67 really passes up to the first 10 params in special
// regs or regs pairs (for 64 bit params).  So keep track of
// the stack offsets so we can translate to the appropriate 
// reg (pair)

#وصف_ڪريو No_Call_دليلون_Passed_On_ڍير 10
صحيح No_جو_Cur_Func_دليلون;
صحيح Translate_ڍير_منزل_Reg[No_Call_دليلون_Passed_On_ڍير];
صحيح Param_Loc_On_ڍير[No_Call_دليلون_Passed_On_ڍير];
صحيح ڪل_بائيٽون_Pushed_On_ڍير;

#جيڪڏهن_وصف_نه_ٿيل FALSE
# define FALSE 0
# define TRUE 1
#جيڪڏهن_پورو

#وصف_رد BOOL
#وصف_ڪريو BOOL صحيح

#وصف_ڪريو ALWAYS_ASSERT(x) \
افعل {\
   إذا (!(x))\
       tcc_error("internal compiler error file at %s:%d", __FILE__, __LINE__);\
} طالما (0)

/******************************************************/
ساكن بنانشان ڊگهو func_sub_sp_وٿي;
ساكن صحيح func_ret_sub;

ساكن BOOL C67_invert_test;
ساكن صحيح C67_compare_reg;

#جيڪڏهن_وصف_ٿيل ASSEMBLY_LISTING_C67
FILE *f = عدم;
#جيڪڏهن_پورو

فراغ C67_g(صحيح c)
{
    صحيح ind1;
    إذا (nocode_wanted)
        أرجع;
#جيڪڏهن_وصف_ٿيل ASSEMBLY_LISTING_C67
    fprintf(f, " %08X", c);
#جيڪڏهن_پورو
    ind1 = ind + 4;
    إذا (ind1 > (صحيح) cur_متن_section->معلومات_allocated)
	section_realloc(cur_متن_section, ind1);
    cur_متن_section->معلومات[ind] = c & 0xff;
    cur_متن_section->معلومات[ind + 1] = (c >> 8) & 0xff;
    cur_متن_section->معلومات[ind + 2] = (c >> 16) & 0xff;
    cur_متن_section->معلومات[ind + 3] = (c >> 24) & 0xff;
    ind = ind1;
}


/* output a symbol and patch all calls to it */
فراغ gsym_addr(صحيح t, صحيح a)
{
    صحيح n, *ptr;
    طالما (t) {
	ptr = (صحيح *) (cur_متن_section->معلومات + t);
	{
	    Sym *sym;

	    // extract 32 bit address from MVKH/MVKL
	    n = ((*ptr >> 7) & 0xffff);
	    n |= ((*(ptr + 1) >> 7) & 0xffff) << 16;

	    // define a label that will be relocated

	    sym = get_sym_ref(&char_اشارو_type, cur_متن_section, a, 0);
	    greloc(cur_متن_section, sym, t, R_C60LO16);
	    greloc(cur_متن_section, sym, t + 4, R_C60HI16);

	    // clear out where the pointer was

	    *ptr &= ~(0xffff << 7);
	    *(ptr + 1) &= ~(0xffff << 7);
	}
	t = n;
    }
}

// these are regs that tcc doesn't really know about, 
// but assign them unique values so the mapping routines
// can distinguish them

#وصف_ڪريو C67_A0 105
#وصف_ڪريو C67_SP 106
#وصف_ڪريو C67_B3 107
#وصف_ڪريو C67_FP 108
#وصف_ڪريو C67_B2 109
#وصف_ڪريو C67_CREG_ZERO -1	/* Special code for no condition reg test */


صحيح Convert_Reg_منزل_Reg_Class(صحيح r)
{
    // only works for A4-B13

    أرجع RC_C67_A4 << (r - TREG_C67_A4);
}


// map TCC reg to C67 reg number

صحيح C67_map_regn(صحيح r)
{
    إذا (r == 0)			// normal tcc regs
	أرجع 0x2;		// A2
    وإلا إذا (r == 1)		// normal tcc regs
	أرجع 3;		// A3
    وإلا إذا (r == 2)		// normal tcc regs
	أرجع 0;		// B0
    وإلا إذا (r == 3)		// normal tcc regs
	أرجع 1;		// B1
    وإلا إذا (r >= TREG_C67_A4 && r <= TREG_C67_B13)	// these form a pattern of alt pairs
	أرجع (((r & 0xfffffffc) >> 1) | (r & 1)) + 2;
    وإلا إذا (r == C67_A0)
	أرجع 0;		// set to A0 (offset reg)
    وإلا إذا (r == C67_B2)
	أرجع 2;		// set to B2 (offset reg)
    وإلا إذا (r == C67_B3)
	أرجع 3;		// set to B3 (return address reg)
    وإلا إذا (r == C67_SP)
	أرجع 15;		// set to SP (B15) (offset reg)
    وإلا إذا (r == C67_FP)
	أرجع 15;		// set to FP (A15) (offset reg)
    وإلا إذا (r == C67_CREG_ZERO)
	أرجع 0;		// Special code for no condition reg test
    وإلا
	ALWAYS_ASSERT(FALSE);

    أرجع 0;
}

// mapping from tcc reg number to 
// C67 register to condition code field
//
// valid condition code regs are:
//
// tcc reg 2 ->B0 -> 1
// tcc reg 3 ->B1 -> 2
// tcc reg 0 -> A2 -> 5
// tcc reg 1 -> A3 -> X
// tcc reg      B2 -> 3

صحيح C67_map_regc(صحيح r)
{
    إذا (r == 0)			// normal tcc regs
	أرجع 0x5;
    وإلا إذا (r == 2)		// normal tcc regs
	أرجع 0x1;
    وإلا إذا (r == 3)		// normal tcc regs
	أرجع 0x2;
    وإلا إذا (r == C67_B2)	// normal tcc regs
	أرجع 0x3;
    وإلا إذا (r == C67_CREG_ZERO)
	أرجع 0;		// Special code for no condition reg test
    وإلا
	ALWAYS_ASSERT(FALSE);

    أرجع 0;
}


// map TCC reg to C67 reg side A or B

صحيح C67_map_regs(صحيح r)
{
    إذا (r == 0)			// normal tcc regs
	أرجع 0x0;
    وإلا إذا (r == 1)		// normal tcc regs
	أرجع 0x0;
    وإلا إذا (r == 2)		// normal tcc regs
	أرجع 0x1;
    وإلا إذا (r == 3)		// normal tcc regs
	أرجع 0x1;
    وإلا إذا (r >= TREG_C67_A4 && r <= TREG_C67_B13)	// these form a pattern of alt pairs
	أرجع (r & 2) >> 1;
    وإلا إذا (r == C67_A0)
	أرجع 0;		// set to A side 
    وإلا إذا (r == C67_B2)
	أرجع 1;		// set to B side 
    وإلا إذا (r == C67_B3)
	أرجع 1;		// set to B side
    وإلا إذا (r == C67_SP)
	أرجع 0x1;		// set to SP (B15) B side 
    وإلا إذا (r == C67_FP)
	أرجع 0x0;		// set to FP (A15) A side 
    وإلا
	ALWAYS_ASSERT(FALSE);

    أرجع 0;
}

صحيح C67_map_S12(حرف *s)
{
    إذا (لڙي_ڳولا(s, ".S1") != عدم)
	أرجع 0;
    وإلا إذا (strcmp(s, ".S2"))
	أرجع 1;
    وإلا
	ALWAYS_ASSERT(FALSE);

    أرجع 0;
}

صحيح C67_map_D12(حرف *s)
{
    إذا (لڙي_ڳولا(s, ".D1") != عدم)
	أرجع 0;
    وإلا إذا (strcmp(s, ".D2"))
	أرجع 1;
    وإلا
	ALWAYS_ASSERT(FALSE);

    أرجع 0;
}



فراغ C67_asm(ثابت حرف *s, صحيح a, صحيح b, صحيح c)
{
    BOOL xpath;

#جيڪڏهن_وصف_ٿيل ASSEMBLY_LISTING_C67
    إذا (!f) {
	f = fopen("TCC67_out.txt", "wt");
    }
    fprintf(f, "%04X ", ind);
#جيڪڏهن_پورو

    إذا (لڙي_ڳولا(s, "MVKL") == s) {
	C67_g((C67_map_regn(b) << 23) |
	      ((a & 0xffff) << 7) | (0x0a << 2) | (C67_map_regs(b) << 1));
    } وإلا إذا (لڙي_ڳولا(s, "MVKH") == s) {
	C67_g((C67_map_regn(b) << 23) |
	      (((a >> 16) & 0xffff) << 7) |
	      (0x1a << 2) | (C67_map_regs(b) << 1));
    } وإلا إذا (لڙي_ڳولا(s, "STW.D SP POST DEC") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//SP B15
	      (2 << 13) |	//ucst5 (must keep 8 byte boundary !!)
	      (0xa << 9) |	//mode a = post dec ucst
	      (0 << 8) |	//r (LDDW bit 0)
	      (1 << 7) |	//y D1/D2 use B side
	      (7 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STB.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2 A side
	      (3 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STH.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2 A side
	      (5 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STB.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2 A side
	      (3 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STH.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2 A side
	      (5 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STW.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2 A side
	      (7 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STW.D *") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (C67_map_regn(b) << 18) |	//base reg A0
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(b) << 7) |	//y D1/D2 base reg side
	      (7 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STH.D *") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (C67_map_regn(b) << 18) |	//base reg A0
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(b) << 7) |	//y D1/D2 base reg side
	      (5 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STB.D *") == s) {
	C67_g((C67_map_regn(a) << 23) |	//src
	      (C67_map_regn(b) << 18) |	//base reg A0
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(b) << 7) |	//y D1/D2 base reg side
	      (3 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "STW.D +*") == s) {
	ALWAYS_ASSERT(c < 32);
	C67_g((C67_map_regn(a) << 23) |	//src
	      (C67_map_regn(b) << 18) |	//base reg A0
	      (c << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(b) << 7) |	//y D1/D2 base reg side
	      (7 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of src
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDW.D SP PRE INC") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg B15
	      (2 << 13) |	//ucst5 (must keep 8 byte boundary)
	      (9 << 9) |	//mode 9 = pre inc ucst5
	      (0 << 8) |	//r (LDDW bit 0)
	      (1 << 7) |	//y D1/D2  B side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDDW.D SP PRE INC") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg B15
	      (1 << 13) |	//ucst5 (must keep 8 byte boundary)
	      (9 << 9) |	//mode 9 = pre inc ucst5
	      (1 << 8) |	//r (LDDW bit 1)
	      (1 << 7) |	//y D1/D2  B side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDW.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2  A side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDDW.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (1 << 8) |	//r (LDDW bit 1)
	      (0 << 7) |	//y D1/D2  A side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDH.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2  A side
	      (4 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDB.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2  A side
	      (2 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDHU.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2  A side
	      (0 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDBU.D *+SP[A0]") == s) {
	C67_g((C67_map_regn(a) << 23) |	//dst
	      (15 << 18) |	//base reg A15
	      (0 << 13) |	//offset reg A0
	      (5 << 9) |	//mode 5 = pos offset, base reg + off reg
	      (0 << 8) |	//r (LDDW bit 0)
	      (0 << 7) |	//y D1/D2  A side
	      (1 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(a) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDW.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDDW.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (1 << 8) |	//r (LDDW bit 1)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDH.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (4 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDB.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (2 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDHU.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (0 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDBU.D *") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (0 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (1 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "LDW.D +*") == s) {
	C67_g((C67_map_regn(b) << 23) |	//dst
	      (C67_map_regn(a) << 18) |	//base reg A15
	      (1 << 13) |	//cst5
	      (1 << 9) |	//mode 1 = pos cst offset
	      (0 << 8) |	//r (LDDW bit 0)
	      (C67_map_regs(a) << 7) |	//y D1/D2  src side
	      (6 << 4) |	//ldst 3=STB, 5=STH 5, 7=STW, 6=LDW 4=LDH 2=LDB 0=LDHU 1=LDBU 
	      (1 << 2) |	//opcode
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPLTSP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x3a << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPGTSP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x39 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPEQSP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x38 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    }

    وإلا إذا (لڙي_ڳولا(s, "CMPLTDP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x2a << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPGTDP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x29 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPEQDP") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x28 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPLT") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x57 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPGT") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x47 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPEQ") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x53 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPLTU") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x5f << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "CMPGTU") == s) {
	xpath = C67_map_regs(a) ^ C67_map_regs(b);
	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1
	      (xpath << 12) |	//x use cross path for src2
	      (0x4f << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side for reg c
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "B DISP") == s) {
	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//z
	      (a << 7) |	//cnst
	      (0x4 << 2) |	//opcode fixed
	      (0 << 1) |	//S0/S1
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "B.") == s) {
	xpath = C67_map_regs(c) ^ 1;

	C67_g((C67_map_regc(b) << 29) |	//creg
	      (a << 28) |	//inv
	      (0 << 23) |	//dst
	      (C67_map_regn(c) << 18) |	//src2
	      (0 << 13) |	//
	      (xpath << 12) |	//x cross path if !B side
	      (0xd << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (1 << 1) |	//must be S2
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "MV.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (0 << 13) |	//src1 (cst5)
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x2 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SPTRUNC.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0xb << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "DPTRUNC.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      ((C67_map_regn(b) + 1) << 18) |	//src2   WEIRD CPU must specify odd reg for some reason
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x1 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "INTSP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2   
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x4a << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "INTSPU.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2  
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x49 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "INTDP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2  
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x39 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "INTDPU.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      ((C67_map_regn(b) + 1) << 18) |	//src2   WEIRD CPU must specify odd reg for some reason
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x3b << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SPDP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (0 << 13) |	//src1 NA
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x2 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "DPSP.L") == s) {
	ALWAYS_ASSERT(C67_map_regs(b) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      ((C67_map_regn(b) + 1) << 18) |	//src2 WEIRD CPU must specify odd reg for some reason
	      (0 << 13) |	//src1 NA
	      (0 << 12) |	//x cross path if opposite sides
	      (0x9 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "ADD.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x3 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SUB.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x7 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "OR.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x7f << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "AND.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x7b << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "XOR.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x6f << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "ADDSP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x10 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "ADDDP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x18 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SUBSP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x11 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SUBDP.L") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x19 << 5) |	//opcode
	      (0x6 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "MPYSP.M") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x1c << 7) |	//opcode
	      (0x0 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "MPYDP.M") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2 (possible x path)
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x0e << 7) |	//opcode
	      (0x0 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "MPYI.M") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(a) == C67_map_regs(c));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1 (cst5)
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x4 << 7) |	//opcode
	      (0x0 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SHR.S") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x37 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SHRU.S") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x27 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "SHL.S") == s) {
	xpath = C67_map_regs(b) ^ C67_map_regs(c);

	ALWAYS_ASSERT(C67_map_regs(c) == C67_map_regs(a));

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(c) << 23) |	//dst
	      (C67_map_regn(b) << 18) |	//src2
	      (C67_map_regn(a) << 13) |	//src1 
	      (xpath << 12) |	//x cross path if opposite sides
	      (0x33 << 6) |	//opcode
	      (0x8 << 2) |	//opcode fixed
	      (C67_map_regs(c) << 1) |	//side of dest
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "||ADDK") == s) {
	xpath = 0;		// no xpath required just use the side of the src/dst

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(b) << 23) |	//dst
	      (a << 07) |	//scst16
	      (0x14 << 2) |	//opcode fixed
	      (C67_map_regs(b) << 1) |	//side of dst
	      (1 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "ADDK") == s) {
	xpath = 0;		// no xpath required just use the side of the src/dst

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(b) << 23) |	//dst
	      (a << 07) |	//scst16
	      (0x14 << 2) |	//opcode fixed
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } وإلا إذا (لڙي_ڳولا(s, "NOP") == s) {
	C67_g(((a - 1) << 13) |	//no of cycles
	      (0 << 0));	//parallel
    } وإلا
	ALWAYS_ASSERT(FALSE);

#جيڪڏهن_وصف_ٿيل ASSEMBLY_LISTING_C67
    fprintf(f, " %s %d %d %d\n", s, a, b, c);
#جيڪڏهن_پورو

}

//r=reg to load, fr=from reg, symbol for relocation, constant

فراغ C67_MVKL(صحيح r, صحيح fc)
{
    C67_asm("MVKL.", fc, r, 0);
}

فراغ C67_MVKH(صحيح r, صحيح fc)
{
    C67_asm("MVKH.", fc, r, 0);
}

فراغ C67_STB_SP_A0(صحيح r)
{
    C67_asm("STB.D *+SP[A0]", r, 0, 0);	// STB  r,*+SP[A0]
}

فراغ C67_STH_SP_A0(صحيح r)
{
    C67_asm("STH.D *+SP[A0]", r, 0, 0);	// STH  r,*+SP[A0]
}

فراغ C67_STW_SP_A0(صحيح r)
{
    C67_asm("STW.D *+SP[A0]", r, 0, 0);	// STW  r,*+SP[A0]
}

فراغ C67_STB_PTR(صحيح r, صحيح r2)
{
    C67_asm("STB.D *", r, r2, 0);	// STB  r, *r2
}

فراغ C67_STH_PTR(صحيح r, صحيح r2)
{
    C67_asm("STH.D *", r, r2, 0);	// STH  r, *r2
}

فراغ C67_STW_PTR(صحيح r, صحيح r2)
{
    C67_asm("STW.D *", r, r2, 0);	// STW  r, *r2
}

فراغ C67_STW_PTR_PRE_INC(صحيح r, صحيح r2, صحيح n)
{
    C67_asm("STW.D +*", r, r2, n);	// STW  r, *+r2
}

فراغ C67_ڌڪو(صحيح r)
{
    C67_asm("STW.D SP POST DEC", r, 0, 0);	// STW  r,*SP--
}

فراغ C67_LDW_SP_A0(صحيح r)
{
    C67_asm("LDW.D *+SP[A0]", r, 0, 0);	// LDW  *+SP[A0],r
}

فراغ C67_LDDW_SP_A0(صحيح r)
{
    C67_asm("LDDW.D *+SP[A0]", r, 0, 0);	// LDDW  *+SP[A0],r
}

فراغ C67_LDH_SP_A0(صحيح r)
{
    C67_asm("LDH.D *+SP[A0]", r, 0, 0);	// LDH  *+SP[A0],r
}

فراغ C67_LDB_SP_A0(صحيح r)
{
    C67_asm("LDB.D *+SP[A0]", r, 0, 0);	// LDB  *+SP[A0],r
}

فراغ C67_LDHU_SP_A0(صحيح r)
{
    C67_asm("LDHU.D *+SP[A0]", r, 0, 0);	// LDHU  *+SP[A0],r
}

فراغ C67_LDBU_SP_A0(صحيح r)
{
    C67_asm("LDBU.D *+SP[A0]", r, 0, 0);	// LDBU  *+SP[A0],r
}

فراغ C67_LDW_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDW.D *", r, r2, 0);	// LDW  *r,r2
}

فراغ C67_LDDW_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDDW.D *", r, r2, 0);	// LDDW  *r,r2
}

فراغ C67_LDH_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDH.D *", r, r2, 0);	// LDH  *r,r2
}

فراغ C67_LDB_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDB.D *", r, r2, 0);	// LDB  *r,r2
}

فراغ C67_LDHU_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDHU.D *", r, r2, 0);	// LDHU  *r,r2
}

فراغ C67_LDBU_PTR(صحيح r, صحيح r2)
{
    C67_asm("LDBU.D *", r, r2, 0);	// LDBU  *r,r2
}

فراغ C67_LDW_PTR_PRE_INC(صحيح r, صحيح r2)
{
    C67_asm("LDW.D +*", r, r2, 0);	// LDW  *+r,r2
}

فراغ C67_ڪڍو(صحيح r)
{
    C67_asm("LDW.D SP PRE INC", r, 0, 0);	// LDW  *++SP,r
}

فراغ C67_ڪڍو_DW(صحيح r)
{
    C67_asm("LDDW.D SP PRE INC", r, 0, 0);	// LDDW  *++SP,r
}

فراغ C67_CMPLT(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPLT.L1", s1, s2, dst);
}

فراغ C67_CMPGT(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPGT.L1", s1, s2, dst);
}

فراغ C67_CMPEQ(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPEQ.L1", s1, s2, dst);
}

فراغ C67_CMPLTU(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPLTU.L1", s1, s2, dst);
}

فراغ C67_CMPGTU(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPGTU.L1", s1, s2, dst);
}


فراغ C67_CMPLTSP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPLTSP.S1", s1, s2, dst);
}

فراغ C67_CMPGTSP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPGTSP.S1", s1, s2, dst);
}

فراغ C67_CMPEQSP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPEQSP.S1", s1, s2, dst);
}

فراغ C67_CMPLTDP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPLTDP.S1", s1, s2, dst);
}

فراغ C67_CMPGTDP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPGTDP.S1", s1, s2, dst);
}

فراغ C67_CMPEQDP(صحيح s1, صحيح s2, صحيح dst)
{
    C67_asm("CMPEQDP.S1", s1, s2, dst);
}


فراغ C67_IREG_B_REG(صحيح inv, صحيح r1, صحيح r2)	// [!R] B  r2
{
    C67_asm("B.S2", inv, r1, r2);
}


// call with how many 32 bit words to skip
// (0 would branch to the branch instruction)

فراغ C67_B_DISP(صحيح disp)	//  B  +2  Branch with constant displacement
{
    // Branch point is relative to the 8 word fetch packet
    //
    // we will assume the text section always starts on an 8 word (32 byte boundary)
    //
    // so add in how many words into the fetch packet the branch is


    C67_asm("B DISP", disp + ((ind & 31) >> 2), 0, 0);
}

فراغ C67_NOP(صحيح n)
{
    C67_asm("NOP", n, 0, 0);
}

فراغ C67_ADDK(صحيح n, صحيح r)
{
    ALWAYS_ASSERT(مطلق_قدر(n) < 32767);

    C67_asm("ADDK", n, r, 0);
}

فراغ C67_ADDK_PARALLEL(صحيح n, صحيح r)
{
    ALWAYS_ASSERT(مطلق_قدر(n) < 32767);

    C67_asm("||ADDK", n, r, 0);
}

فراغ C67_Adjust_ADDK(صحيح *inst, صحيح n)
{
    ALWAYS_ASSERT(مطلق_قدر(n) < 32767);

    *inst = (*inst & (~(0xffff << 7))) | ((n & 0xffff) << 7);
}

فراغ C67_MV(صحيح r, صحيح v)
{
    C67_asm("MV.L", 0, r, v);
}


فراغ C67_DPTRUNC(صحيح r, صحيح v)
{
    C67_asm("DPTRUNC.L", 0, r, v);
}

فراغ C67_SPTRUNC(صحيح r, صحيح v)
{
    C67_asm("SPTRUNC.L", 0, r, v);
}

فراغ C67_INTSP(صحيح r, صحيح v)
{
    C67_asm("INTSP.L", 0, r, v);
}

فراغ C67_INTDP(صحيح r, صحيح v)
{
    C67_asm("INTDP.L", 0, r, v);
}

فراغ C67_INTSPU(صحيح r, صحيح v)
{
    C67_asm("INTSPU.L", 0, r, v);
}

فراغ C67_INTDPU(صحيح r, صحيح v)
{
    C67_asm("INTDPU.L", 0, r, v);
}

فراغ C67_SPDP(صحيح r, صحيح v)
{
    C67_asm("SPDP.L", 0, r, v);
}

فراغ C67_DPSP(صحيح r, صحيح v)	// note regs must be on the same side
{
    C67_asm("DPSP.L", 0, r, v);
}

فراغ C67_جوڙيو(صحيح r, صحيح v)
{
    C67_asm("ADD.L", v, r, v);
}

فراغ C67_SUB(صحيح r, صحيح v)
{
    C67_asm("SUB.L", v, r, v);
}

فراغ C67_AND(صحيح r, صحيح v)
{
    C67_asm("AND.L", v, r, v);
}

فراغ C67_OR(صحيح r, صحيح v)
{
    C67_asm("OR.L", v, r, v);
}

فراغ C67_XOR(صحيح r, صحيح v)
{
    C67_asm("XOR.L", v, r, v);
}

فراغ C67_ADDSP(صحيح r, صحيح v)
{
    C67_asm("ADDSP.L", v, r, v);
}

فراغ C67_SUBSP(صحيح r, صحيح v)
{
    C67_asm("SUBSP.L", v, r, v);
}

فراغ C67_MPYSP(صحيح r, صحيح v)
{
    C67_asm("MPYSP.M", v, r, v);
}

فراغ C67_ADDDP(صحيح r, صحيح v)
{
    C67_asm("ADDDP.L", v, r, v);
}

فراغ C67_SUBDP(صحيح r, صحيح v)
{
    C67_asm("SUBDP.L", v, r, v);
}

فراغ C67_MPYDP(صحيح r, صحيح v)
{
    C67_asm("MPYDP.M", v, r, v);
}

فراغ C67_MPYI(صحيح r, صحيح v)
{
    C67_asm("MPYI.M", v, r, v);
}

فراغ C67_SHL(صحيح r, صحيح v)
{
    C67_asm("SHL.S", r, v, v);
}

فراغ C67_SHRU(صحيح r, صحيح v)
{
    C67_asm("SHRU.S", r, v, v);
}

فراغ C67_SHR(صحيح r, صحيح v)
{
    C67_asm("SHR.S", r, v, v);
}



/* load 'r' from value 'sv' */
فراغ ڀريو(صحيح r, SValue * sv)
{
    صحيح v, t, ft, fc, fr, سائيز = 0, element;
    BOOL Unsigned = FALSE;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t;
    fc = sv->c.i;

    v = fr & VT_VALMASK;
    إذا (fr & VT_LVAL) {
	إذا (v == VT_LLOCAL) {
	    v1.type.t = VT_INT;
	    v1.r = VT_LOCAL | VT_LVAL;
	    v1.c.i = fc;
	    ڀريو(r, &v1);
	    fr = r;
	} وإلا إذا ((ft & VT_BTYPE) == VT_LDOUBLE) {
	    tcc_error("long double not supported");
	} وإلا إذا ((ft & VT_TYPE) == VT_BYTE) {
	    سائيز = 1;
	} وإلا إذا ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
	    سائيز = 1;
	    Unsigned = TRUE;
	} وإلا إذا ((ft & VT_TYPE) == VT_SHORT) {
	    سائيز = 2;
	} وإلا إذا ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
	    سائيز = 2;
	    Unsigned = TRUE;
	} وإلا إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
	    سائيز = 8;
	} وإلا {
	    سائيز = 4;
	}

	// check if fc is a positive reference on the stack, 
	// if it is tcc is referencing what it thinks is a parameter
	// on the stack, so check if it is really in a register.


	إذا (v == VT_LOCAL && fc > 0) {
	    صحيح ڍير_pos = 8;

	    لكل (t = 0; t < No_Call_دليلون_Passed_On_ڍير; t++) {
		إذا (fc == ڍير_pos)
		    اكسر;

		ڍير_pos += Translate_ڍير_منزل_Reg[t];
	    }

	    // param has been pushed on stack, get it like a local var

	    fc = Param_Loc_On_ڍير[t] - 8;
	}

	إذا ((fr & VT_VALMASK) < VT_CONST)	// check for pure indirect
	{
	    إذا (سائيز == 1) {
		إذا (Unsigned)
		    C67_LDBU_PTR(v, r);	// LDBU  *v,r
		وإلا
		    C67_LDB_PTR(v, r);	// LDB  *v,r
	    } وإلا إذا (سائيز == 2) {
		إذا (Unsigned)
		    C67_LDHU_PTR(v, r);	// LDHU  *v,r
		وإلا
		    C67_LDH_PTR(v, r);	// LDH  *v,r
	    } وإلا إذا (سائيز == 4) {
		C67_LDW_PTR(v, r);	// LDW  *v,r
	    } وإلا إذا (سائيز == 8) {
		C67_LDDW_PTR(v, r);	// LDDW  *v,r
	    }

	    C67_NOP(4);		// NOP 4
	    أرجع;
	} وإلا إذا (fr & VT_SYM) {
	    greloc(cur_متن_section, sv->sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_متن_section, sv->sym, ind + 4, R_C60HI16);


	    C67_MVKL(C67_A0, fc);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, fc);	//r=reg to load,  constant


	    إذا (سائيز == 1) {
		إذا (Unsigned)
		    C67_LDBU_PTR(C67_A0, r);	// LDBU  *A0,r
		وإلا
		    C67_LDB_PTR(C67_A0, r);	// LDB  *A0,r
	    } وإلا إذا (سائيز == 2) {
		إذا (Unsigned)
		    C67_LDHU_PTR(C67_A0, r);	// LDHU  *A0,r
		وإلا
		    C67_LDH_PTR(C67_A0, r);	// LDH  *A0,r
	    } وإلا إذا (سائيز == 4) {
		C67_LDW_PTR(C67_A0, r);	// LDW  *A0,r
	    } وإلا إذا (سائيز == 8) {
		C67_LDDW_PTR(C67_A0, r);	// LDDW  *A0,r
	    }

	    C67_NOP(4);		// NOP 4
	    أرجع;
	} وإلا {
	    element = سائيز;

	    // divide offset in bytes to create element index
	    C67_MVKL(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant

	    إذا (سائيز == 1) {
		إذا (Unsigned)
		    C67_LDBU_SP_A0(r);	// LDBU  r, SP[A0]
		وإلا
		    C67_LDB_SP_A0(r);	// LDB  r, SP[A0]
	    } وإلا إذا (سائيز == 2) {
		إذا (Unsigned)
		    C67_LDHU_SP_A0(r);	// LDHU  r, SP[A0]
		وإلا
		    C67_LDH_SP_A0(r);	// LDH  r, SP[A0]
	    } وإلا إذا (سائيز == 4) {
		C67_LDW_SP_A0(r);	// LDW  r, SP[A0]
	    } وإلا إذا (سائيز == 8) {
		C67_LDDW_SP_A0(r);	// LDDW  r, SP[A0]
	    }


	    C67_NOP(4);		// NOP 4
	    أرجع;
	}
    } وإلا {
	إذا (v == VT_CONST) {
	    إذا (fr & VT_SYM) {
		greloc(cur_متن_section, sv->sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_متن_section, sv->sym, ind + 4, R_C60HI16);
	    }
	    C67_MVKL(r, fc);	//r=reg to load, constant
	    C67_MVKH(r, fc);	//r=reg to load, constant
	} وإلا إذا (v == VT_LOCAL) {
	    C67_MVKL(r, fc + 8);	//r=reg to load, constant C67 stack points to next free
	    C67_MVKH(r, fc + 8);	//r=reg to load, constant
	    C67_جوڙيو(C67_FP, r);	// MV v,r   v -> r
	} وإلا إذا (v == VT_CMP) {
	    C67_MV(C67_compare_reg, r);	// MV v,r   v -> r
	} وإلا إذا (v == VT_JMP || v == VT_JMPI) {
	    t = v & 1;
	    C67_B_DISP(4);	//  Branch with constant displacement, skip over this branch, load, nop, load
	    C67_MVKL(r, t);	//  r=reg to load, 0 or 1 (do this while branching)
	    C67_NOP(4);		//  NOP 4
	    gsym(fc);		//  modifies other branches to branch here
	    C67_MVKL(r, t ^ 1);	//  r=reg to load, 0 or 1
	} وإلا إذا (v != r) {
	    C67_MV(v, r);	// MV v,r   v -> r

	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_MV(v + 1, r + 1);	// MV v,r   v -> r
	}
    }
}


/* store register 'r' in lvalue 'v' */
فراغ store(صحيح r, SValue * v)
{
    صحيح fr, bt, ft, fc, سائيز, t, element;

    ft = v->type.t;
    fc = v->c.i;
    fr = v->r & VT_VALMASK;
    bt = ft & VT_BTYPE;
    /* XXX: incorrect if float reg to reg */

    إذا (bt == VT_LDOUBLE) {
	tcc_error("long double not supported");
    } وإلا {
	إذا (bt == VT_SHORT)
	    سائيز = 2;
	وإلا إذا (bt == VT_BYTE)
	    سائيز = 1;
	وإلا إذا (bt == VT_DOUBLE)
	    سائيز = 8;
	وإلا
	    سائيز = 4;

	إذا ((v->r & VT_VALMASK) == VT_CONST) {
	    /* constant memory reference */

	    إذا (v->r & VT_SYM) {
		greloc(cur_متن_section, v->sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_متن_section, v->sym, ind + 4, R_C60HI16);
	    }
	    C67_MVKL(C67_A0, fc);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, fc);	//r=reg to load,  constant

	    إذا (سائيز == 1)
		C67_STB_PTR(r, C67_A0);	// STB  r, *A0
	    وإلا إذا (سائيز == 2)
		C67_STH_PTR(r, C67_A0);	// STH  r, *A0
	    وإلا إذا (سائيز == 4 || سائيز == 8)
		C67_STW_PTR(r, C67_A0);	// STW  r, *A0

	    إذا (سائيز == 8)
		C67_STW_PTR_PRE_INC(r + 1, C67_A0, 1);	// STW  r, *+A0[1]
	} وإلا إذا ((v->r & VT_VALMASK) == VT_LOCAL) {
	    // check case of storing to passed argument that
	    // tcc thinks is on the stack but for C67 is
	    // passed as a reg.  However it may have been
	    // saved to the stack, if that reg was required
	    // for a call to a child function

	    إذا (fc > 0)		// argument ??
	    {
		// walk through sizes and figure which param

		صحيح ڍير_pos = 8;

		لكل (t = 0; t < No_Call_دليلون_Passed_On_ڍير; t++) {
		    إذا (fc == ڍير_pos)
			اكسر;

		    ڍير_pos += Translate_ڍير_منزل_Reg[t];
		}

		// param has been pushed on stack, get it like a local var
		fc = Param_Loc_On_ڍير[t] - 8;
	    }

	    إذا (سائيز == 8)
		element = 4;
	    وإلا
		element = سائيز;

	    // divide offset in bytes to create word index
	    C67_MVKL(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant



	    إذا (سائيز == 1)
		C67_STB_SP_A0(r);	// STB  r, SP[A0]
	    وإلا إذا (سائيز == 2)
		C67_STH_SP_A0(r);	// STH  r, SP[A0]
	    وإلا إذا (سائيز == 4 || سائيز == 8)
		C67_STW_SP_A0(r);	// STW  r, SP[A0]

	    إذا (سائيز == 8) {
		C67_ADDK(1, C67_A0);	//  ADDK 1,A0
		C67_STW_SP_A0(r + 1);	//  STW  r, SP[A0]
	    }
	} وإلا {
	    إذا (سائيز == 1)
		C67_STB_PTR(r, fr);	// STB  r, *fr
	    وإلا إذا (سائيز == 2)
		C67_STH_PTR(r, fr);	// STH  r, *fr
	    وإلا إذا (سائيز == 4 || سائيز == 8)
		C67_STW_PTR(r, fr);	// STW  r, *fr

	    إذا (سائيز == 8) {
		C67_STW_PTR_PRE_INC(r + 1, fr, 1);	// STW  r, *+fr[1]
	    }
	}
    }
}

/* 'is_jmp' is '1' if it is a jump */
ساكن فراغ gcall_or_jmp(صحيح is_jmp)
{
    صحيح r;
    Sym *sym;

    إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
	/* constant case */
	إذا (vtop->r & VT_SYM) {
	    /* relocation case */

	    // get add into A0, then start the jump B3

	    greloc(cur_متن_section, vtop->sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_متن_section, vtop->sym, ind + 4, R_C60HI16);

	    C67_MVKL(C67_A0, 0);	//r=reg to load, constant
	    C67_MVKH(C67_A0, 0);	//r=reg to load, constant
	    C67_IREG_B_REG(0, C67_CREG_ZERO, C67_A0);	//  B.S2x  A0

	    إذا (is_jmp) {
		C67_NOP(5);	// simple jump, just put NOP
	    } وإلا {
		// Call, must load return address into B3 during delay slots

		sym = get_sym_ref(&char_اشارو_type, cur_متن_section, ind + 12, 0);	// symbol for return address
		greloc(cur_متن_section, sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_متن_section, sym, ind + 4, R_C60HI16);
		C67_MVKL(C67_B3, 0);	//r=reg to load, constant
		C67_MVKH(C67_B3, 0);	//r=reg to load, constant
		C67_NOP(3);	// put remaining NOPs
	    }
	} وإلا {
	    /* put an empty PC32 relocation */
	    ALWAYS_ASSERT(FALSE);
	}
    } وإلا {
	/* otherwise, indirect call */
	r = gv(RC_INT);
	C67_IREG_B_REG(0, C67_CREG_ZERO, r);	//  B.S2x  r

	إذا (is_jmp) {
	    C67_NOP(5);		// simple jump, just put NOP
	} وإلا {
	    // Call, must load return address into B3 during delay slots

	    sym = get_sym_ref(&char_اشارو_type, cur_متن_section, ind + 12, 0);	// symbol for return address
	    greloc(cur_متن_section, sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_متن_section, sym, ind + 4, R_C60HI16);
	    C67_MVKL(C67_B3, 0);	//r=reg to load, constant
	    C67_MVKH(C67_B3, 0);	//r=reg to load, constant
	    C67_NOP(3);		// put remaining NOPs
	}
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *ret_align, صحيح *regsize) {
    *ret_align = 1; // Never have to re-align return values for x86-64
    أرجع 0;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
فراغ gfunc_call(صحيح nb_دليلون)
{
    صحيح i, r, سائيز = 0;
    صحيح دليلون_sizes[No_Call_دليلون_Passed_On_ڍير];

    إذا (nb_دليلون > No_Call_دليلون_Passed_On_ڍير) {
	tcc_error("more than 10 function params not currently supported");
	// handle more than 10, put some on the stack
    }

    لكل (i = 0; i < nb_دليلون; i++) {
	إذا ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
	    ALWAYS_ASSERT(FALSE);
	} وإلا {
	    /* simple type (currently always same size) */
	    /* XXX: implicit cast ? */


	    إذا ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
		tcc_error("long long not supported");
	    } وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
		tcc_error("long double not supported");
	    } وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE) {
		سائيز = 8;
	    } وإلا {
		سائيز = 4;
	    }

	    // put the parameter into the corresponding reg (pair)

	    r = gv(RC_C67_A4 << (2 * i));

	    // must put on stack because with 1 pass compiler , no way to tell
	    // if an up coming nested call might overwrite these regs

	    C67_ڌڪو(r);

	    إذا (سائيز == 8) {
		C67_STW_PTR_PRE_INC(r + 1, C67_SP, 3);	// STW  r, *+SP[3] (go back and put the other)
	    }
	    دليلون_sizes[i] = سائيز;
	}
	vtop--;
    }
    // POP all the params on the stack into registers for the
    // immediate call (in reverse order)

    لكل (i = nb_دليلون - 1; i >= 0; i--) {

	إذا (دليلون_sizes[i] == 8)
	    C67_ڪڍو_DW(TREG_C67_A4 + i * 2);
	وإلا
	    C67_ڪڍو(TREG_C67_A4 + i * 2);
    }
    gcall_or_jmp(0);
    vtop--;
}


// to be compatible with Code Composer for the C67
// the first 10 parameters must be passed in registers
// (pairs for 64 bits) starting wit; A4:A5, then B4:B5 and
// ending with B12:B13.
//
// When a call is made, if the caller has its parameters
// in regs A4-B13 these must be saved before/as the call 
// parameters are loaded and restored upon return (or if/when needed).

/* generate function prolog of type 't' */
فراغ gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    صحيح addr, align, سائيز, func_call, i;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    إذا ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
	func_vc = addr;
	addr += 4;
    }

    No_جو_Cur_Func_دليلون = 0;

    /* define parameters */
    طالما ((sym = sym->ايندڙ) != عدم) {
	type = &sym->type;
	gfunc_سيٽ_param(sym, addr, 0);
	سائيز = type_سائيز(type, &align);
	سائيز = (سائيز + 3) & ~3;

	// keep track of size of arguments so
	// we can translate where tcc thinks they
	// are on the stack into the appropriate reg

	Translate_ڍير_منزل_Reg[No_جو_Cur_Func_دليلون] = سائيز;
	No_جو_Cur_Func_دليلون++;

#جيڪڏهن_وصف_ٿيل FUNC_STRUCT_PARAM_AS_PTR
	/* structs are passed as pointer */
	إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
	    سائيز = 4;
	}
#جيڪڏهن_پورو
	addr += سائيز;
    }
    func_ret_sub = 0;
    /* pascal type call ? */
    إذا (func_call == FUNC_STDCALL)
	func_ret_sub = addr - 8;

    C67_MV(C67_FP, C67_A0);	//  move FP -> A0
    C67_MV(C67_SP, C67_FP);	//  move SP -> FP

    // place all the args passed in regs onto the stack

    loc = 0;
    لكل (i = 0; i < No_جو_Cur_Func_دليلون; i++) {

	Param_Loc_On_ڍير[i] = loc;	// remember where the param is
	loc += -8;

	C67_ڌڪو(TREG_C67_A4 + i * 2);

	إذا (Translate_ڍير_منزل_Reg[i] == 8) {
	    C67_STW_PTR_PRE_INC(TREG_C67_A4 + i * 2 + 1, C67_SP, 3);	// STW  r, *+SP[1] (go back and put the other)
	}
    }

    ڪل_بائيٽون_Pushed_On_ڍير = -loc;

    func_sub_sp_وٿي = ind;	// remember where we put the stack instruction 
    C67_ADDK(0, C67_SP);	//  ADDK.L2 loc,SP  (just put zero temporarily)

    C67_ڌڪو(C67_A0);
    C67_ڌڪو(C67_B3);
}

/* generate function epilog */
فراغ gfunc_epilog(فراغ)
{
    {
	صحيح local = (-loc + 7) & -8;	// stack must stay aligned to 8 bytes for LDDW instr
	C67_ڪڍو(C67_B3);
	C67_NOP(4);		// NOP wait for load
	C67_IREG_B_REG(0, C67_CREG_ZERO, C67_B3);	//  B.S2  B3
	C67_ڪڍو(C67_FP);
	C67_ADDK(local, C67_SP);	//  ADDK.L2 loc,SP  
	C67_Adjust_ADDK((صحيح *) (cur_متن_section->معلومات +
				 func_sub_sp_وٿي),
			-local + ڪل_بائيٽون_Pushed_On_ڍير);
	C67_NOP(3);		// NOP 
    }
}

ST_FUNC فراغ gen_fill_nops(صحيح بائيٽون)
{
    إذا ((بائيٽون & 3))
      tcc_error("alignment of code section not multiple of 4");
    طالما (بائيٽون > 0) {
	C67_NOP(4);
	بائيٽون -= 4;
    }
}

/* generate a jump to a label */
صحيح gjmp(صحيح t)
{
    صحيح ind1 = ind;
    إذا (nocode_wanted)
        أرجع t;

    C67_MVKL(C67_A0, t);	//r=reg to load,  constant
    C67_MVKH(C67_A0, t);	//r=reg to load,  constant
    C67_IREG_B_REG(0, C67_CREG_ZERO, C67_A0);	// [!R] B.S2x  A0
    C67_NOP(5);
    أرجع ind1;
}

/* generate a jump to a fixed address */
فراغ gjmp_addr(صحيح a)
{
    Sym *sym;
    // I guess this routine is used for relative short
    // local jumps, for now just handle it as the general
    // case

    // define a label that will be relocated

    sym = get_sym_ref(&char_اشارو_type, cur_متن_section, a, 0);
    greloc(cur_متن_section, sym, ind, R_C60LO16);
    greloc(cur_متن_section, sym, ind + 4, R_C60HI16);

    gjmp(0);			// place a zero there later the symbol will be added to it
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t)
{
        صحيح ind1;
        صحيح inv = op & 1;
        إذا (nocode_wanted)
            أرجع t;

	/* fast case : can jump directly since flags are set */
	// C67 uses B2 sort of as flags register
	ind1 = ind;
	C67_MVKL(C67_A0, t);	//r=reg to load, constant
	C67_MVKH(C67_A0, t);	//r=reg to load, constant

	إذا (C67_compare_reg != TREG_EAX &&	// check if not already in a conditional test reg
	    C67_compare_reg != TREG_EDX &&
	    C67_compare_reg != TREG_ST0 && C67_compare_reg != C67_B2) {
	    C67_MV(C67_compare_reg, C67_B2);
	    C67_compare_reg = C67_B2;
	}

	C67_IREG_B_REG(C67_invert_test ^ inv, C67_compare_reg, C67_A0);	// [!R] B.S2x  A0
	C67_NOP(5);
	t = ind1;		//return where we need to patch

        أرجع t;
}

ST_FUNC صحيح gjmp_append(صحيح n0, صحيح t)
{
    إذا (n0) {
            صحيح n = n0, *p;
	    /* insert vtop->c jump list in t */

	    // I guess the idea is to traverse to the
	    // null at the end of the list and store t
	    // there
	    طالما (n != 0) {
		p = (صحيح *) (cur_متن_section->معلومات + n);

		// extract 32 bit address from MVKH/MVKL
		n = ((*p >> 7) & 0xffff);
		n |= ((*(p + 1) >> 7) & 0xffff) << 16;
	    }
	    *p |= (t & 0xffff) << 7;
	    *(p + 1) |= ((t >> 16) & 0xffff) << 7;
	    t = n0;
    }
    أرجع t;
}

/* generate an integer binary operation */
فراغ gen_opi(صحيح op)
{
    صحيح r, fr, opc, t;

    بدل (op) {
    حالة '+':
    حالة TOK_ADDC1:		/* add with carry generation */
	opc = 0;
      gen_op8:


// C67 can't do const compares, must load into a reg
// so just go to gv2 directly - tktk



	إذا (op >= TOK_ULT && op <= TOK_GT)
	    gv2(RC_INT_BSIDE, RC_INT);	// make sure r (src1) is on the B Side of CPU
	وإلا
	    gv2(RC_INT, RC_INT);

	r = vtop[-1].r;
	fr = vtop[0].r;

	C67_compare_reg = C67_B2;


	إذا (op == TOK_LT) {
	    C67_CMPLT(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_GE) {
	    C67_CMPLT(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_GT) {
	    C67_CMPGT(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_LE) {
	    C67_CMPGT(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_EQ) {
	    C67_CMPEQ(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_NE) {
	    C67_CMPEQ(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_ULT) {
	    C67_CMPLTU(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_UGE) {
	    C67_CMPLTU(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_UGT) {
	    C67_CMPGTU(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_ULE) {
	    C67_CMPGTU(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} وإلا إذا (op == '+')
	    C67_جوڙيو(fr, r);	// ADD  r,fr,r
	وإلا إذا (op == '-')
	    C67_SUB(fr, r);	// SUB  r,fr,r
	وإلا إذا (op == '&')
	    C67_AND(fr, r);	// AND  r,fr,r
	وإلا إذا (op == '|')
	    C67_OR(fr, r);	// OR  r,fr,r
	وإلا إذا (op == '^')
	    C67_XOR(fr, r);	// XOR  r,fr,r
	وإلا
	    ALWAYS_ASSERT(FALSE);

	vtop--;
	إذا (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(0x80);
	اكسر;
    حالة '-':
    حالة TOK_SUBC1:		/* sub with carry generation */
	opc = 5;
	اذهب gen_op8;
    حالة TOK_ADDC2:		/* add with carry use */
	opc = 2;
	اذهب gen_op8;
    حالة TOK_SUBC2:		/* sub with carry use */
	opc = 3;
	اذهب gen_op8;
    حالة '&':
	opc = 4;
	اذهب gen_op8;
    حالة '^':
	opc = 6;
	اذهب gen_op8;
    حالة '|':
	opc = 1;
	اذهب gen_op8;
    حالة '*':
    حالة TOK_UMULL:
	gv2(RC_INT, RC_INT);
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_MPYI(fr, r);	// 32 bit multiply  fr,r,fr
	C67_NOP(8);		// NOP 8 for worst case
	اكسر;
    حالة TOK_SHL:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHL(fr, r);		// arithmetic/logical shift
	اكسر;

    حالة TOK_SHR:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHRU(fr, r);	// logical shift
	اكسر;

    حالة TOK_SAR:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHR(fr, r);		// arithmetic shift
	اكسر;

    حالة '/':
	t = TOK__divi;
      call_func:
	vswap();
	/* call generic idiv function */
	vpush_helper_func(t);
	vrott(3);
	gfunc_call(2);
	vpushi(0);
	vtop->r = REG_IRET;
	vtop->r2 = VT_CONST;
	اكسر;
    حالة TOK_UDIV:
    حالة TOK_PDIV:
	t = TOK__divu;
	اذهب call_func;
    حالة '%':
	t = TOK__remi;
	اذهب call_func;
    حالة TOK_UMOD:
	t = TOK__remu;
	اذهب call_func;

    افتراضي:
	opc = 7;
	اذهب gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
فراغ gen_opf(صحيح op)
{
    صحيح ft, fc, fr, r;

    إذا (op >= TOK_ULT && op <= TOK_GT)
	gv2(RC_EDX, RC_EAX);	// make sure src2 is on b side
    وإلا
	gv2(RC_FLOAT, RC_FLOAT);	// make sure src2 is on b side

    ft = vtop->type.t;
    fc = vtop->c.i;
    r = vtop->r;
    fr = vtop[-1].r;


    إذا ((ft & VT_BTYPE) == VT_LDOUBLE)
	tcc_error("long doubles not supported");

    إذا (op >= TOK_ULT && op <= TOK_GT) {

	r = vtop[-1].r;
	fr = vtop[0].r;

	C67_compare_reg = C67_B2;

	إذا (op == TOK_LT) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPLTDP(r, fr, C67_B2);
	    وإلا
		C67_CMPLTSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_GE) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPLTDP(r, fr, C67_B2);
	    وإلا
		C67_CMPLTSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_GT) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPGTDP(r, fr, C67_B2);
	    وإلا
		C67_CMPGTSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_LE) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPGTDP(r, fr, C67_B2);
	    وإلا
		C67_CMPGTSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} وإلا إذا (op == TOK_EQ) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPEQDP(r, fr, C67_B2);
	    وإلا
		C67_CMPEQSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} وإلا إذا (op == TOK_NE) {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPEQDP(r, fr, C67_B2);
	    وإلا
		C67_CMPEQSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} وإلا {
	    ALWAYS_ASSERT(FALSE);
	}
        vset_VT_CMP(0x80);
    } وإلا {
	إذا (op == '+') {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_ADDDP(r, fr);	// ADD  fr,r,fr
		C67_NOP(6);
	    } وإلا {
		C67_ADDSP(r, fr);	// ADD  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} وإلا إذا (op == '-') {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_SUBDP(r, fr);	// SUB  fr,r,fr
		C67_NOP(6);
	    } وإلا {
		C67_SUBSP(r, fr);	// SUB  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} وإلا إذا (op == '*') {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_MPYDP(r, fr);	// MPY  fr,r,fr
		C67_NOP(9);
	    } وإلا {
		C67_MPYSP(r, fr);	// MPY  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} وإلا إذا (op == '/') {
	    إذا ((ft & VT_BTYPE) == VT_DOUBLE) {
		// must call intrinsic DP floating point divide
		vswap();
		/* call generic idiv function */
		vpush_helper_func(TOK__divd);
		vrott(3);
		gfunc_call(2);
		vpushi(0);
		vtop->r = REG_FRET;
		vtop->r2 = REG_IRE2;

	    } وإلا {
		// must call intrinsic SP floating point divide
		vswap();
		/* call generic idiv function */
		vpush_helper_func(TOK__divf);
		vrott(3);
		gfunc_call(2);
		vpushi(0);
		vtop->r = REG_FRET;
		vtop->r2 = VT_CONST;
	    }
	} وإلا
	    ALWAYS_ASSERT(FALSE);


    }
}


/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
فراغ gen_cvt_itof(صحيح t)
{
    صحيح r;

    gv(RC_INT);
    r = vtop->r;

    إذا ((t & VT_BTYPE) == VT_DOUBLE) {
	إذا (t & VT_UNSIGNED)
	    C67_INTDPU(r, r);
	وإلا
	    C67_INTDP(r, r);

	C67_NOP(4);
	vtop->type.t = VT_DOUBLE;
    } وإلا {
	إذا (t & VT_UNSIGNED)
	    C67_INTSPU(r, r);
	وإلا
	    C67_INTSP(r, r);
	C67_NOP(3);
	vtop->type.t = VT_FLOAT;
    }

}

/* convert fp to int 't' type */
/* XXX: handle long long case */
فراغ gen_cvt_ftoi(صحيح t)
{
    صحيح r;

    gv(RC_FLOAT);
    r = vtop->r;

    إذا (t != VT_INT)
	tcc_error("long long not supported");
    وإلا {
	إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE) {
	    C67_DPTRUNC(r, r);
	    C67_NOP(3);
	} وإلا {
	    C67_SPTRUNC(r, r);
	    C67_NOP(3);
	}

	vtop->type.t = VT_INT;

    }
}

/* convert from one floating point type to another */
فراغ gen_cvt_ftof(صحيح t)
{
    صحيح r, r2;

    إذا ((vtop->type.t & VT_BTYPE) == VT_DOUBLE &&
	(t & VT_BTYPE) == VT_FLOAT) {
	// convert double to float

	gv(RC_FLOAT);		// get it in a register pair

	r = vtop->r;

	C67_DPSP(r, r);		// convert it to SP same register
	C67_NOP(3);

	vtop->type.t = VT_FLOAT;
	vtop->r2 = VT_CONST;	// set this as unused
    } وإلا إذا ((vtop->type.t & VT_BTYPE) == VT_FLOAT &&
	       (t & VT_BTYPE) == VT_DOUBLE) {
	// convert float to double

	gv(RC_FLOAT);		// get it in a register

	r = vtop->r;

	إذا (r == TREG_EAX) {	// make sure the paired reg is avail
	    r2 = get_reg(RC_ECX);
	} وإلا إذا (r == TREG_EDX) {
	    r2 = get_reg(RC_ST0);
	} وإلا {
	    ALWAYS_ASSERT(FALSE);
            r2 = 0; /* avoid warning */
        }

	C67_SPDP(r, r);		// convert it to DP same register
	C67_NOP(1);

	vtop->type.t = VT_DOUBLE;
	vtop->r2 = r2;		// set this as unused
    } وإلا {
	ALWAYS_ASSERT(FALSE);
    }
}

/* computed goto support */
فراغ ggoto(فراغ)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC فراغ gen_vla_sp_save(صحيح addr) {
    tcc_error("variable length arrays unsupported for this target");
}

/* Restore the SP from a location on the stack */
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr) {
    tcc_error("variable length arrays unsupported for this target");
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align) {
    tcc_error("variable length arrays unsupported for this target");
}

/* end of C67 code generator */
/*************************************************************/
#جيڪڏهن_پورو
/*************************************************************/
