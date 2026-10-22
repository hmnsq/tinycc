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

#ifdef TARGET_DEFS_ONLY

/* #define ASSEMBLY_LISTING_C67 */

/* number of available registers */
#define NB_REGS            24

/* a register can belong to several classes. The classes must be
   sorted from more general to more precise (see gv2() code which does
   assumptions on it). */
#define RC_INT     0x0001	/* generic integer register */
#define RC_FLOAT   0x0002	/* generic float register */
#define RC_EAX     0x0004
#define RC_ST0     0x0008
#define RC_ECX     0x0010
#define RC_EDX     0x0020
#define RC_INT_BSIDE  0x00000040	/* generic integer register  on b side */
#define RC_C67_A4     0x00000100
#define RC_C67_A5     0x00000200
#define RC_C67_B4     0x00000400
#define RC_C67_B5     0x00000800
#define RC_C67_A6     0x00001000
#define RC_C67_A7     0x00002000
#define RC_C67_B6     0x00004000
#define RC_C67_B7     0x00008000
#define RC_C67_A8     0x00010000
#define RC_C67_A9     0x00020000
#define RC_C67_B8     0x00040000
#define RC_C67_B9     0x00080000
#define RC_C67_A10    0x00100000
#define RC_C67_A11    0x00200000
#define RC_C67_B10    0x00400000
#define RC_C67_B11    0x00800000
#define RC_C67_A12    0x01000000
#define RC_C67_A13    0x02000000
#define RC_C67_B12    0x04000000
#define RC_C67_B13    0x08000000
#define RC_IRET    RC_C67_A4	/* function return: integer register */
#define RC_IRE2    RC_C67_A5	/* function return: second integer register */
#define RC_FRET    RC_C67_A4	/* function return: float register */

/* pretty names for the registers */
ga_nanaa {
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
#define REG_IRET TREG_C67_A4	/* single word int return register */
#define REG_IRE2 TREG_C67_A5    /* second word return register (for long long) */
#define REG_FRET TREG_C67_A4	/* float return register */

/* defined if function parameters must be evaluated in reverse order */
/* #define INVERT_FUNC_PARAMS */

/* defined if structures are passed as pointers. Otherwise structures
   are directly pushed on stack. */
/* #define FUNC_STRUCT_PARAM_AS_PTR */

/* pointer size, in bytes */
#define PTR_SIZE 4

/* long double size and alignment, in bytes */
#define LDOUBLE_SIZE  12
#define LDOUBLE_ALIGN 4
/* maximum alignment (for aligned attribute support) */
#define MAX_ALIGN     8

#undef CONFIG_TCC_BCHECK

/******************************************************/
#បើមិនដូច្នេះ /* ! TARGET_DEFS_ONLY */
/******************************************************/
#define USING_GLOBALS
#include "tcc.h"

ST_DATA const var_na * const target_machine_defs =
    "__C67__\0"
    ;

ST_DATA const ចំនួនគត់ reg_classes[NB_REGS] = {
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

#define NoCallArgsPassedOnStack 10
ចំនួនគត់ NoOfCurFuncArgs;
ចំនួនគត់ TranslateStackToReg[NoCallArgsPassedOnStack];
ចំនួនគត់ ParamLocOnStack[NoCallArgsPassedOnStack];
ចំនួនគត់ TotalBytesPushedOnStack;

#ifndef FALSE
# define FALSE 0
# define TRUE 1
#endif

#undef BOOL
#define BOOL ចំនួនគត់

#define ALWAYS_ASSERT(x) \
do {\
   ប្រសិនបើ (!(x))\
       tcc_error("internal compiler error file at %s:%d", __FILE__, __LINE__);\
} ខណៈពេល (0)

/******************************************************/
static unsigned long func_sub_sp_offset;
static ចំនួនគត់ func_ret_sub;

static BOOL C67_invert_test;
static ចំនួនគត់ C67_compare_reg;

#ifdef ASSEMBLY_LISTING_C67
FILE *f = NULL;
#endif

void C67_g(ចំនួនគត់ c)
{
    ចំនួនគត់ ind1;
    ប្រសិនបើ (nocode_wanted)
        ត្រឡប់;
#ifdef ASSEMBLY_LISTING_C67
    fprintf(f, " %08X", c);
#endif
    ind1 = ind + 4;
    ប្រសិនបើ (ind1 > (ចំនួនគត់) cur_text_section->data_allocated)
	section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c & 0xff;
    cur_text_section->data[ind + 1] = (c >> 8) & 0xff;
    cur_text_section->data[ind + 2] = (c >> 16) & 0xff;
    cur_text_section->data[ind + 3] = (c >> 24) & 0xff;
    ind = ind1;
}


/* output a symbol and patch all calls to it */
void gsym_addr(ចំនួនគត់ t, ចំនួនគត់ a)
{
    ចំនួនគត់ n, *ptr;
    ខណៈពេល (t) {
	ptr = (ចំនួនគត់ *) (cur_text_section->data + t);
	{
	    Sym *sym;

	    // extract 32 bit address from MVKH/MVKL
	    n = ((*ptr >> 7) & 0xffff);
	    n |= ((*(ptr + 1) >> 7) & 0xffff) << 16;

	    // define a label that will be relocated

	    sym = get_sym_ref(&char_pointer_type, cur_text_section, a, 0);
	    greloc(cur_text_section, sym, t, R_C60LO16);
	    greloc(cur_text_section, sym, t + 4, R_C60HI16);

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

#define C67_A0 105
#define C67_SP 106
#define C67_B3 107
#define C67_FP 108
#define C67_B2 109
#define C67_CREG_ZERO -1	/* Special code for no condition reg test */


ចំនួនគត់ ConvertRegToRegClass(ចំនួនគត់ r)
{
    // only works for A4-B13

    ត្រឡប់ RC_C67_A4 << (r - TREG_C67_A4);
}


// map TCC reg to C67 reg number

ចំនួនគត់ C67_map_regn(ចំនួនគត់ r)
{
    ប្រសិនបើ (r == 0)			// normal tcc regs
	ត្រឡប់ 0x2;		// A2
    បើមិនដូច្នេះ ប្រសិនបើ (r == 1)		// normal tcc regs
	ត្រឡប់ 3;		// A3
    បើមិនដូច្នេះ ប្រសិនបើ (r == 2)		// normal tcc regs
	ត្រឡប់ 0;		// B0
    បើមិនដូច្នេះ ប្រសិនបើ (r == 3)		// normal tcc regs
	ត្រឡប់ 1;		// B1
    បើមិនដូច្នេះ ប្រសិនបើ (r >= TREG_C67_A4 && r <= TREG_C67_B13)	// these form a pattern of alt pairs
	ត្រឡប់ (((r & 0xfffffffc) >> 1) | (r & 1)) + 2;
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_A0)
	ត្រឡប់ 0;		// set to A0 (offset reg)
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_B2)
	ត្រឡប់ 2;		// set to B2 (offset reg)
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_B3)
	ត្រឡប់ 3;		// set to B3 (return address reg)
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_SP)
	ត្រឡប់ 15;		// set to SP (B15) (offset reg)
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_FP)
	ត្រឡប់ 15;		// set to FP (A15) (offset reg)
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_CREG_ZERO)
	ត្រឡប់ 0;		// Special code for no condition reg test
    បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

    ត្រឡប់ 0;
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

ចំនួនគត់ C67_map_regc(ចំនួនគត់ r)
{
    ប្រសិនបើ (r == 0)			// normal tcc regs
	ត្រឡប់ 0x5;
    បើមិនដូច្នេះ ប្រសិនបើ (r == 2)		// normal tcc regs
	ត្រឡប់ 0x1;
    បើមិនដូច្នេះ ប្រសិនបើ (r == 3)		// normal tcc regs
	ត្រឡប់ 0x2;
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_B2)	// normal tcc regs
	ត្រឡប់ 0x3;
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_CREG_ZERO)
	ត្រឡប់ 0;		// Special code for no condition reg test
    បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

    ត្រឡប់ 0;
}


// map TCC reg to C67 reg side A or B

ចំនួនគត់ C67_map_regs(ចំនួនគត់ r)
{
    ប្រសិនបើ (r == 0)			// normal tcc regs
	ត្រឡប់ 0x0;
    បើមិនដូច្នេះ ប្រសិនបើ (r == 1)		// normal tcc regs
	ត្រឡប់ 0x0;
    បើមិនដូច្នេះ ប្រសិនបើ (r == 2)		// normal tcc regs
	ត្រឡប់ 0x1;
    បើមិនដូច្នេះ ប្រសិនបើ (r == 3)		// normal tcc regs
	ត្រឡប់ 0x1;
    បើមិនដូច្នេះ ប្រសិនបើ (r >= TREG_C67_A4 && r <= TREG_C67_B13)	// these form a pattern of alt pairs
	ត្រឡប់ (r & 2) >> 1;
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_A0)
	ត្រឡប់ 0;		// set to A side 
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_B2)
	ត្រឡប់ 1;		// set to B side 
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_B3)
	ត្រឡប់ 1;		// set to B side
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_SP)
	ត្រឡប់ 0x1;		// set to SP (B15) B side 
    បើមិនដូច្នេះ ប្រសិនបើ (r == C67_FP)
	ត្រឡប់ 0x0;		// set to FP (A15) A side 
    បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

    ត្រឡប់ 0;
}

ចំនួនគត់ C67_map_S12(var_na *s)
{
    ប្រសិនបើ (strstr(s, ".S1") != NULL)
	ត្រឡប់ 0;
    បើមិនដូច្នេះ ប្រសិនបើ (strcmp(s, ".S2"))
	ត្រឡប់ 1;
    បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

    ត្រឡប់ 0;
}

ចំនួនគត់ C67_map_D12(var_na *s)
{
    ប្រសិនបើ (strstr(s, ".D1") != NULL)
	ត្រឡប់ 0;
    បើមិនដូច្នេះ ប្រសិនបើ (strcmp(s, ".D2"))
	ត្រឡប់ 1;
    បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

    ត្រឡប់ 0;
}



void C67_asm(const var_na *s, ចំនួនគត់ a, ចំនួនគត់ b, ចំនួនគត់ c)
{
    BOOL xpath;

#ifdef ASSEMBLY_LISTING_C67
    ប្រសិនបើ (!f) {
	f = fopen("TCC67_out.txt", "wt");
    }
    fprintf(f, "%04X ", ind);
#endif

    ប្រសិនបើ (strstr(s, "MVKL") == s) {
	C67_g((C67_map_regn(b) << 23) |
	      ((a & 0xffff) << 7) | (0x0a << 2) | (C67_map_regs(b) << 1));
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "MVKH") == s) {
	C67_g((C67_map_regn(b) << 23) |
	      (((a >> 16) & 0xffff) << 7) |
	      (0x1a << 2) | (C67_map_regs(b) << 1));
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STW.D SP POST DEC") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STB.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STH.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STB.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STH.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STW.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STW.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STH.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STB.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "STW.D +*") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDW.D SP PRE INC") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDDW.D SP PRE INC") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDW.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDDW.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDH.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDB.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDHU.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDBU.D *+SP[A0]") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDW.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDDW.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDH.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDB.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDHU.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDBU.D *") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "LDW.D +*") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPLTSP") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPGTSP") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPEQSP") == s) {
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

    បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPLTDP") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPGTDP") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPEQDP") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPLT") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPGT") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPEQ") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPLTU") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "CMPGTU") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "B DISP") == s) {
	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//z
	      (a << 7) |	//cnst
	      (0x4 << 2) |	//opcode fixed
	      (0 << 1) |	//S0/S1
	      (0 << 0));	//parallel
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "B.") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "MV.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SPTRUNC.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "DPTRUNC.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "INTSP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "INTSPU.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "INTDP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "INTDPU.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SPDP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "DPSP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "ADD.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SUB.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "OR.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "AND.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "XOR.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "ADDSP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "ADDDP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SUBSP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SUBDP.L") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "MPYSP.M") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "MPYDP.M") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "MPYI.M") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SHR.S") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SHRU.S") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "SHL.S") == s) {
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
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "||ADDK") == s) {
	xpath = 0;		// no xpath required just use the side of the src/dst

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(b) << 23) |	//dst
	      (a << 07) |	//scst16
	      (0x14 << 2) |	//opcode fixed
	      (C67_map_regs(b) << 1) |	//side of dst
	      (1 << 0));	//parallel
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "ADDK") == s) {
	xpath = 0;		// no xpath required just use the side of the src/dst

	C67_g((0 << 29) |	//creg
	      (0 << 28) |	//inv
	      (C67_map_regn(b) << 23) |	//dst
	      (a << 07) |	//scst16
	      (0x14 << 2) |	//opcode fixed
	      (C67_map_regs(b) << 1) |	//side of dst
	      (0 << 0));	//parallel
    } បើមិនដូច្នេះ ប្រសិនបើ (strstr(s, "NOP") == s) {
	C67_g(((a - 1) << 13) |	//no of cycles
	      (0 << 0));	//parallel
    } បើមិនដូច្នេះ
	ALWAYS_ASSERT(FALSE);

#ifdef ASSEMBLY_LISTING_C67
    fprintf(f, " %s %d %d %d\n", s, a, b, c);
#endif

}

//r=reg to load, fr=from reg, symbol for relocation, constant

void C67_MVKL(ចំនួនគត់ r, ចំនួនគត់ fc)
{
    C67_asm("MVKL.", fc, r, 0);
}

void C67_MVKH(ចំនួនគត់ r, ចំនួនគត់ fc)
{
    C67_asm("MVKH.", fc, r, 0);
}

void C67_STB_SP_A0(ចំនួនគត់ r)
{
    C67_asm("STB.D *+SP[A0]", r, 0, 0);	// STB  r,*+SP[A0]
}

void C67_STH_SP_A0(ចំនួនគត់ r)
{
    C67_asm("STH.D *+SP[A0]", r, 0, 0);	// STH  r,*+SP[A0]
}

void C67_STW_SP_A0(ចំនួនគត់ r)
{
    C67_asm("STW.D *+SP[A0]", r, 0, 0);	// STW  r,*+SP[A0]
}

void C67_STB_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("STB.D *", r, r2, 0);	// STB  r, *r2
}

void C67_STH_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("STH.D *", r, r2, 0);	// STH  r, *r2
}

void C67_STW_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("STW.D *", r, r2, 0);	// STW  r, *r2
}

void C67_STW_PTR_PRE_INC(ចំនួនគត់ r, ចំនួនគត់ r2, ចំនួនគត់ n)
{
    C67_asm("STW.D +*", r, r2, n);	// STW  r, *+r2
}

void C67_PUSH(ចំនួនគត់ r)
{
    C67_asm("STW.D SP POST DEC", r, 0, 0);	// STW  r,*SP--
}

void C67_LDW_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDW.D *+SP[A0]", r, 0, 0);	// LDW  *+SP[A0],r
}

void C67_LDDW_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDDW.D *+SP[A0]", r, 0, 0);	// LDDW  *+SP[A0],r
}

void C67_LDH_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDH.D *+SP[A0]", r, 0, 0);	// LDH  *+SP[A0],r
}

void C67_LDB_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDB.D *+SP[A0]", r, 0, 0);	// LDB  *+SP[A0],r
}

void C67_LDHU_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDHU.D *+SP[A0]", r, 0, 0);	// LDHU  *+SP[A0],r
}

void C67_LDBU_SP_A0(ចំនួនគត់ r)
{
    C67_asm("LDBU.D *+SP[A0]", r, 0, 0);	// LDBU  *+SP[A0],r
}

void C67_LDW_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDW.D *", r, r2, 0);	// LDW  *r,r2
}

void C67_LDDW_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDDW.D *", r, r2, 0);	// LDDW  *r,r2
}

void C67_LDH_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDH.D *", r, r2, 0);	// LDH  *r,r2
}

void C67_LDB_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDB.D *", r, r2, 0);	// LDB  *r,r2
}

void C67_LDHU_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDHU.D *", r, r2, 0);	// LDHU  *r,r2
}

void C67_LDBU_PTR(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDBU.D *", r, r2, 0);	// LDBU  *r,r2
}

void C67_LDW_PTR_PRE_INC(ចំនួនគត់ r, ចំនួនគត់ r2)
{
    C67_asm("LDW.D +*", r, r2, 0);	// LDW  *+r,r2
}

void C67_POP(ចំនួនគត់ r)
{
    C67_asm("LDW.D SP PRE INC", r, 0, 0);	// LDW  *++SP,r
}

void C67_POP_DW(ចំនួនគត់ r)
{
    C67_asm("LDDW.D SP PRE INC", r, 0, 0);	// LDDW  *++SP,r
}

void C67_CMPLT(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPLT.L1", s1, s2, dst);
}

void C67_CMPGT(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPGT.L1", s1, s2, dst);
}

void C67_CMPEQ(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPEQ.L1", s1, s2, dst);
}

void C67_CMPLTU(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPLTU.L1", s1, s2, dst);
}

void C67_CMPGTU(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPGTU.L1", s1, s2, dst);
}


void C67_CMPLTSP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPLTSP.S1", s1, s2, dst);
}

void C67_CMPGTSP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPGTSP.S1", s1, s2, dst);
}

void C67_CMPEQSP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPEQSP.S1", s1, s2, dst);
}

void C67_CMPLTDP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPLTDP.S1", s1, s2, dst);
}

void C67_CMPGTDP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPGTDP.S1", s1, s2, dst);
}

void C67_CMPEQDP(ចំនួនគត់ s1, ចំនួនគត់ s2, ចំនួនគត់ dst)
{
    C67_asm("CMPEQDP.S1", s1, s2, dst);
}


void C67_IREG_B_REG(ចំនួនគត់ inv, ចំនួនគត់ r1, ចំនួនគត់ r2)	// [!R] B  r2
{
    C67_asm("B.S2", inv, r1, r2);
}


// call with how many 32 bit words to skip
// (0 would branch to the branch instruction)

void C67_B_DISP(ចំនួនគត់ disp)	//  B  +2  Branch with constant displacement
{
    // Branch point is relative to the 8 word fetch packet
    //
    // we will assume the text section always starts on an 8 word (32 byte boundary)
    //
    // so add in how many words into the fetch packet the branch is


    C67_asm("B DISP", disp + ((ind & 31) >> 2), 0, 0);
}

void C67_NOP(ចំនួនគត់ n)
{
    C67_asm("NOP", n, 0, 0);
}

void C67_ADDK(ចំនួនគត់ n, ចំនួនគត់ r)
{
    ALWAYS_ASSERT(abs(n) < 32767);

    C67_asm("ADDK", n, r, 0);
}

void C67_ADDK_PARALLEL(ចំនួនគត់ n, ចំនួនគត់ r)
{
    ALWAYS_ASSERT(abs(n) < 32767);

    C67_asm("||ADDK", n, r, 0);
}

void C67_Adjust_ADDK(ចំនួនគត់ *inst, ចំនួនគត់ n)
{
    ALWAYS_ASSERT(abs(n) < 32767);

    *inst = (*inst & (~(0xffff << 7))) | ((n & 0xffff) << 7);
}

void C67_MV(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("MV.L", 0, r, v);
}


void C67_DPTRUNC(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("DPTRUNC.L", 0, r, v);
}

void C67_SPTRUNC(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SPTRUNC.L", 0, r, v);
}

void C67_INTSP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("INTSP.L", 0, r, v);
}

void C67_INTDP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("INTDP.L", 0, r, v);
}

void C67_INTSPU(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("INTSPU.L", 0, r, v);
}

void C67_INTDPU(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("INTDPU.L", 0, r, v);
}

void C67_SPDP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SPDP.L", 0, r, v);
}

void C67_DPSP(ចំនួនគត់ r, ចំនួនគត់ v)	// note regs must be on the same side
{
    C67_asm("DPSP.L", 0, r, v);
}

void C67_ADD(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("ADD.L", v, r, v);
}

void C67_SUB(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SUB.L", v, r, v);
}

void C67_AND(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("AND.L", v, r, v);
}

void C67_OR(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("OR.L", v, r, v);
}

void C67_XOR(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("XOR.L", v, r, v);
}

void C67_ADDSP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("ADDSP.L", v, r, v);
}

void C67_SUBSP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SUBSP.L", v, r, v);
}

void C67_MPYSP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("MPYSP.M", v, r, v);
}

void C67_ADDDP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("ADDDP.L", v, r, v);
}

void C67_SUBDP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SUBDP.L", v, r, v);
}

void C67_MPYDP(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("MPYDP.M", v, r, v);
}

void C67_MPYI(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("MPYI.M", v, r, v);
}

void C67_SHL(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SHL.S", r, v, v);
}

void C67_SHRU(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SHRU.S", r, v, v);
}

void C67_SHR(ចំនួនគត់ r, ចំនួនគត់ v)
{
    C67_asm("SHR.S", r, v, v);
}



/* load 'r' from value 'sv' */
void load(ចំនួនគត់ r, SValue * sv)
{
    ចំនួនគត់ v, t, ft, fc, fr, size = 0, element;
    BOOL Unsigned = FALSE;
    SValue v1;

    fr = sv->r;
    ft = sv->type.t;
    fc = sv->c.i;

    v = fr & VT_VALMASK;
    ប្រសិនបើ (fr & VT_LVAL) {
	ប្រសិនបើ (v == VT_LLOCAL) {
	    v1.type.t = VT_INT;
	    v1.r = VT_LOCAL | VT_LVAL;
	    v1.c.i = fc;
	    load(r, &v1);
	    fr = r;
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_BTYPE) == VT_LDOUBLE) {
	    tcc_error("long double not supported");
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_TYPE) == VT_BYTE) {
	    size = 1;
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_TYPE) == (VT_BYTE | VT_UNSIGNED)) {
	    size = 1;
	    Unsigned = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_TYPE) == VT_SHORT) {
	    size = 2;
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_TYPE) == (VT_SHORT | VT_UNSIGNED)) {
	    size = 2;
	    Unsigned = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE) {
	    size = 8;
	} បើមិនដូច្នេះ {
	    size = 4;
	}

	// check if fc is a positive reference on the stack, 
	// if it is tcc is referencing what it thinks is a parameter
	// on the stack, so check if it is really in a register.


	ប្រសិនបើ (v == VT_LOCAL && fc > 0) {
	    ចំនួនគត់ stack_pos = 8;

	    សម្រាប់ (t = 0; t < NoCallArgsPassedOnStack; t++) {
		ប្រសិនបើ (fc == stack_pos)
		    bha_nga;

		stack_pos += TranslateStackToReg[t];
	    }

	    // param has been pushed on stack, get it like a local var

	    fc = ParamLocOnStack[t] - 8;
	}

	ប្រសិនបើ ((fr & VT_VALMASK) < VT_CONST)	// check for pure indirect
	{
	    ប្រសិនបើ (size == 1) {
		ប្រសិនបើ (Unsigned)
		    C67_LDBU_PTR(v, r);	// LDBU  *v,r
		បើមិនដូច្នេះ
		    C67_LDB_PTR(v, r);	// LDB  *v,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 2) {
		ប្រសិនបើ (Unsigned)
		    C67_LDHU_PTR(v, r);	// LDHU  *v,r
		បើមិនដូច្នេះ
		    C67_LDH_PTR(v, r);	// LDH  *v,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 4) {
		C67_LDW_PTR(v, r);	// LDW  *v,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 8) {
		C67_LDDW_PTR(v, r);	// LDDW  *v,r
	    }

	    C67_NOP(4);		// NOP 4
	    ត្រឡប់;
	} បើមិនដូច្នេះ ប្រសិនបើ (fr & VT_SYM) {
	    greloc(cur_text_section, sv->sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_text_section, sv->sym, ind + 4, R_C60HI16);


	    C67_MVKL(C67_A0, fc);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, fc);	//r=reg to load,  constant


	    ប្រសិនបើ (size == 1) {
		ប្រសិនបើ (Unsigned)
		    C67_LDBU_PTR(C67_A0, r);	// LDBU  *A0,r
		បើមិនដូច្នេះ
		    C67_LDB_PTR(C67_A0, r);	// LDB  *A0,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 2) {
		ប្រសិនបើ (Unsigned)
		    C67_LDHU_PTR(C67_A0, r);	// LDHU  *A0,r
		បើមិនដូច្នេះ
		    C67_LDH_PTR(C67_A0, r);	// LDH  *A0,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 4) {
		C67_LDW_PTR(C67_A0, r);	// LDW  *A0,r
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 8) {
		C67_LDDW_PTR(C67_A0, r);	// LDDW  *A0,r
	    }

	    C67_NOP(4);		// NOP 4
	    ត្រឡប់;
	} បើមិនដូច្នេះ {
	    element = size;

	    // divide offset in bytes to create element index
	    C67_MVKL(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant

	    ប្រសិនបើ (size == 1) {
		ប្រសិនបើ (Unsigned)
		    C67_LDBU_SP_A0(r);	// LDBU  r, SP[A0]
		បើមិនដូច្នេះ
		    C67_LDB_SP_A0(r);	// LDB  r, SP[A0]
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 2) {
		ប្រសិនបើ (Unsigned)
		    C67_LDHU_SP_A0(r);	// LDHU  r, SP[A0]
		បើមិនដូច្នេះ
		    C67_LDH_SP_A0(r);	// LDH  r, SP[A0]
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 4) {
		C67_LDW_SP_A0(r);	// LDW  r, SP[A0]
	    } បើមិនដូច្នេះ ប្រសិនបើ (size == 8) {
		C67_LDDW_SP_A0(r);	// LDDW  r, SP[A0]
	    }


	    C67_NOP(4);		// NOP 4
	    ត្រឡប់;
	}
    } បើមិនដូច្នេះ {
	ប្រសិនបើ (v == VT_CONST) {
	    ប្រសិនបើ (fr & VT_SYM) {
		greloc(cur_text_section, sv->sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_text_section, sv->sym, ind + 4, R_C60HI16);
	    }
	    C67_MVKL(r, fc);	//r=reg to load, constant
	    C67_MVKH(r, fc);	//r=reg to load, constant
	} បើមិនដូច្នេះ ប្រសិនបើ (v == VT_LOCAL) {
	    C67_MVKL(r, fc + 8);	//r=reg to load, constant C67 stack points to next free
	    C67_MVKH(r, fc + 8);	//r=reg to load, constant
	    C67_ADD(C67_FP, r);	// MV v,r   v -> r
	} បើមិនដូច្នេះ ប្រសិនបើ (v == VT_CMP) {
	    C67_MV(C67_compare_reg, r);	// MV v,r   v -> r
	} បើមិនដូច្នេះ ប្រសិនបើ (v == VT_JMP || v == VT_JMPI) {
	    t = v & 1;
	    C67_B_DISP(4);	//  Branch with constant displacement, skip over this branch, load, nop, load
	    C67_MVKL(r, t);	//  r=reg to load, 0 or 1 (do this while branching)
	    C67_NOP(4);		//  NOP 4
	    gsym(fc);		//  modifies other branches to branch here
	    C67_MVKL(r, t ^ 1);	//  r=reg to load, 0 or 1
	} បើមិនដូច្នេះ ប្រសិនបើ (v != r) {
	    C67_MV(v, r);	// MV v,r   v -> r

	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_MV(v + 1, r + 1);	// MV v,r   v -> r
	}
    }
}


/* store register 'r' in lvalue 'v' */
void store(ចំនួនគត់ r, SValue * v)
{
    ចំនួនគត់ fr, bt, ft, fc, size, t, element;

    ft = v->type.t;
    fc = v->c.i;
    fr = v->r & VT_VALMASK;
    bt = ft & VT_BTYPE;
    /* XXX: incorrect if float reg to reg */

    ប្រសិនបើ (bt == VT_LDOUBLE) {
	tcc_error("long double not supported");
    } បើមិនដូច្នេះ {
	ប្រសិនបើ (bt == VT_SHORT)
	    size = 2;
	បើមិនដូច្នេះ ប្រសិនបើ (bt == VT_BYTE)
	    size = 1;
	បើមិនដូច្នេះ ប្រសិនបើ (bt == VT_DOUBLE)
	    size = 8;
	បើមិនដូច្នេះ
	    size = 4;

	ប្រសិនបើ ((v->r & VT_VALMASK) == VT_CONST) {
	    /* constant memory reference */

	    ប្រសិនបើ (v->r & VT_SYM) {
		greloc(cur_text_section, v->sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_text_section, v->sym, ind + 4, R_C60HI16);
	    }
	    C67_MVKL(C67_A0, fc);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, fc);	//r=reg to load,  constant

	    ប្រសិនបើ (size == 1)
		C67_STB_PTR(r, C67_A0);	// STB  r, *A0
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 2)
		C67_STH_PTR(r, C67_A0);	// STH  r, *A0
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 4 || size == 8)
		C67_STW_PTR(r, C67_A0);	// STW  r, *A0

	    ប្រសិនបើ (size == 8)
		C67_STW_PTR_PRE_INC(r + 1, C67_A0, 1);	// STW  r, *+A0[1]
	} បើមិនដូច្នេះ ប្រសិនបើ ((v->r & VT_VALMASK) == VT_LOCAL) {
	    // check case of storing to passed argument that
	    // tcc thinks is on the stack but for C67 is
	    // passed as a reg.  However it may have been
	    // saved to the stack, if that reg was required
	    // for a call to a child function

	    ប្រសិនបើ (fc > 0)		// argument ??
	    {
		// walk through sizes and figure which param

		ចំនួនគត់ stack_pos = 8;

		សម្រាប់ (t = 0; t < NoCallArgsPassedOnStack; t++) {
		    ប្រសិនបើ (fc == stack_pos)
			bha_nga;

		    stack_pos += TranslateStackToReg[t];
		}

		// param has been pushed on stack, get it like a local var
		fc = ParamLocOnStack[t] - 8;
	    }

	    ប្រសិនបើ (size == 8)
		element = 4;
	    បើមិនដូច្នេះ
		element = size;

	    // divide offset in bytes to create word index
	    C67_MVKL(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant
	    C67_MVKH(C67_A0, (fc / element) + 8 / element);	//r=reg to load,  constant



	    ប្រសិនបើ (size == 1)
		C67_STB_SP_A0(r);	// STB  r, SP[A0]
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 2)
		C67_STH_SP_A0(r);	// STH  r, SP[A0]
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 4 || size == 8)
		C67_STW_SP_A0(r);	// STW  r, SP[A0]

	    ប្រសិនបើ (size == 8) {
		C67_ADDK(1, C67_A0);	//  ADDK 1,A0
		C67_STW_SP_A0(r + 1);	//  STW  r, SP[A0]
	    }
	} បើមិនដូច្នេះ {
	    ប្រសិនបើ (size == 1)
		C67_STB_PTR(r, fr);	// STB  r, *fr
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 2)
		C67_STH_PTR(r, fr);	// STH  r, *fr
	    បើមិនដូច្នេះ ប្រសិនបើ (size == 4 || size == 8)
		C67_STW_PTR(r, fr);	// STW  r, *fr

	    ប្រសិនបើ (size == 8) {
		C67_STW_PTR_PRE_INC(r + 1, fr, 1);	// STW  r, *+fr[1]
	    }
	}
    }
}

/* 'is_jmp' is '1' if it is a jump */
static void gcall_or_jmp(ចំនួនគត់ is_jmp)
{
    ចំនួនគត់ r;
    Sym *sym;

    ប្រសិនបើ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
	/* constant case */
	ប្រសិនបើ (vtop->r & VT_SYM) {
	    /* relocation case */

	    // get add into A0, then start the jump B3

	    greloc(cur_text_section, vtop->sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_text_section, vtop->sym, ind + 4, R_C60HI16);

	    C67_MVKL(C67_A0, 0);	//r=reg to load, constant
	    C67_MVKH(C67_A0, 0);	//r=reg to load, constant
	    C67_IREG_B_REG(0, C67_CREG_ZERO, C67_A0);	//  B.S2x  A0

	    ប្រសិនបើ (is_jmp) {
		C67_NOP(5);	// simple jump, just put NOP
	    } បើមិនដូច្នេះ {
		// Call, must load return address into B3 during delay slots

		sym = get_sym_ref(&char_pointer_type, cur_text_section, ind + 12, 0);	// symbol for return address
		greloc(cur_text_section, sym, ind, R_C60LO16);	// rem the inst need to be patched
		greloc(cur_text_section, sym, ind + 4, R_C60HI16);
		C67_MVKL(C67_B3, 0);	//r=reg to load, constant
		C67_MVKH(C67_B3, 0);	//r=reg to load, constant
		C67_NOP(3);	// put remaining NOPs
	    }
	} បើមិនដូច្នេះ {
	    /* put an empty PC32 relocation */
	    ALWAYS_ASSERT(FALSE);
	}
    } បើមិនដូច្នេះ {
	/* otherwise, indirect call */
	r = gv(RC_INT);
	C67_IREG_B_REG(0, C67_CREG_ZERO, r);	//  B.S2x  r

	ប្រសិនបើ (is_jmp) {
	    C67_NOP(5);		// simple jump, just put NOP
	} បើមិនដូច្នេះ {
	    // Call, must load return address into B3 during delay slots

	    sym = get_sym_ref(&char_pointer_type, cur_text_section, ind + 12, 0);	// symbol for return address
	    greloc(cur_text_section, sym, ind, R_C60LO16);	// rem the inst need to be patched
	    greloc(cur_text_section, sym, ind + 4, R_C60HI16);
	    C67_MVKL(C67_B3, 0);	//r=reg to load, constant
	    C67_MVKH(C67_B3, 0);	//r=reg to load, constant
	    C67_NOP(3);		// put remaining NOPs
	}
    }
}

/* Return the number of registers needed to return the struct, or 0 if
   returning via struct pointer. */
ST_FUNC ចំនួនគត់ gfunc_sret(CType *vt, ចំនួនគត់ variadic, CType *ret, ចំនួនគត់ *ret_align, ចំនួនគត់ *regsize) {
    *ret_align = 1; // Never have to re-align return values for x86-64
    ត្រឡប់ 0;
}

/* generate function call with address in (vtop->t, vtop->c) and free function
   context. Stack entry is popped */
void gfunc_call(ចំនួនគត់ nb_args)
{
    ចំនួនគត់ i, r, size = 0;
    ចំនួនគត់ args_sizes[NoCallArgsPassedOnStack];

    ប្រសិនបើ (nb_args > NoCallArgsPassedOnStack) {
	tcc_error("more than 10 function params not currently supported");
	// handle more than 10, put some on the stack
    }

    សម្រាប់ (i = 0; i < nb_args; i++) {
	ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_STRUCT) {
	    ALWAYS_ASSERT(FALSE);
	} បើមិនដូច្នេះ {
	    /* simple type (currently always same size) */
	    /* XXX: implicit cast ? */


	    ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_LLONG) {
		tcc_error("long long not supported");
	    } បើមិនដូច្នេះ ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_LDOUBLE) {
		tcc_error("long double not supported");
	    } បើមិនដូច្នេះ ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE) {
		size = 8;
	    } បើមិនដូច្នេះ {
		size = 4;
	    }

	    // put the parameter into the corresponding reg (pair)

	    r = gv(RC_C67_A4 << (2 * i));

	    // must put on stack because with 1 pass compiler , no way to tell
	    // if an up coming nested call might overwrite these regs

	    C67_PUSH(r);

	    ប្រសិនបើ (size == 8) {
		C67_STW_PTR_PRE_INC(r + 1, C67_SP, 3);	// STW  r, *+SP[3] (go back and put the other)
	    }
	    args_sizes[i] = size;
	}
	vtop--;
    }
    // POP all the params on the stack into registers for the
    // immediate call (in reverse order)

    សម្រាប់ (i = nb_args - 1; i >= 0; i--) {

	ប្រសិនបើ (args_sizes[i] == 8)
	    C67_POP_DW(TREG_C67_A4 + i * 2);
	បើមិនដូច្នេះ
	    C67_POP(TREG_C67_A4 + i * 2);
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
void gfunc_prolog(Sym *func_sym)
{
    CType *func_type = &func_sym->type;
    ចំនួនគត់ addr, align, size, func_call, i;
    Sym *sym;
    CType *type;

    sym = func_type->ref;
    func_call = sym->f.func_call;
    addr = 8;
    /* if the function returns a structure, then add an
       implicit pointer parameter */
    ប្រសិនបើ ((func_vt.t & VT_BTYPE) == VT_STRUCT) {
	func_vc = addr;
	addr += 4;
    }

    NoOfCurFuncArgs = 0;

    /* define parameters */
    ខណៈពេល ((sym = sym->next) != NULL) {
	type = &sym->type;
	gfunc_set_param(sym, addr, 0);
	size = type_size(type, &align);
	size = (size + 3) & ~3;

	// keep track of size of arguments so
	// we can translate where tcc thinks they
	// are on the stack into the appropriate reg

	TranslateStackToReg[NoOfCurFuncArgs] = size;
	NoOfCurFuncArgs++;

#ifdef FUNC_STRUCT_PARAM_AS_PTR
	/* structs are passed as pointer */
	ប្រសិនបើ ((type->t & VT_BTYPE) == VT_STRUCT) {
	    size = 4;
	}
#endif
	addr += size;
    }
    func_ret_sub = 0;
    /* pascal type call ? */
    ប្រសិនបើ (func_call == FUNC_STDCALL)
	func_ret_sub = addr - 8;

    C67_MV(C67_FP, C67_A0);	//  move FP -> A0
    C67_MV(C67_SP, C67_FP);	//  move SP -> FP

    // place all the args passed in regs onto the stack

    loc = 0;
    សម្រាប់ (i = 0; i < NoOfCurFuncArgs; i++) {

	ParamLocOnStack[i] = loc;	// remember where the param is
	loc += -8;

	C67_PUSH(TREG_C67_A4 + i * 2);

	ប្រសិនបើ (TranslateStackToReg[i] == 8) {
	    C67_STW_PTR_PRE_INC(TREG_C67_A4 + i * 2 + 1, C67_SP, 3);	// STW  r, *+SP[1] (go back and put the other)
	}
    }

    TotalBytesPushedOnStack = -loc;

    func_sub_sp_offset = ind;	// remember where we put the stack instruction 
    C67_ADDK(0, C67_SP);	//  ADDK.L2 loc,SP  (just put zero temporarily)

    C67_PUSH(C67_A0);
    C67_PUSH(C67_B3);
}

/* generate function epilog */
void gfunc_epilog(void)
{
    {
	ចំនួនគត់ local = (-loc + 7) & -8;	// stack must stay aligned to 8 bytes for LDDW instr
	C67_POP(C67_B3);
	C67_NOP(4);		// NOP wait for load
	C67_IREG_B_REG(0, C67_CREG_ZERO, C67_B3);	//  B.S2  B3
	C67_POP(C67_FP);
	C67_ADDK(local, C67_SP);	//  ADDK.L2 loc,SP  
	C67_Adjust_ADDK((ចំនួនគត់ *) (cur_text_section->data +
				 func_sub_sp_offset),
			-local + TotalBytesPushedOnStack);
	C67_NOP(3);		// NOP 
    }
}

ST_FUNC void gen_fill_nops(ចំនួនគត់ bytes)
{
    ប្រសិនបើ ((bytes & 3))
      tcc_error("alignment of code section not multiple of 4");
    ខណៈពេល (bytes > 0) {
	C67_NOP(4);
	bytes -= 4;
    }
}

/* generate a jump to a label */
ចំនួនគត់ gjmp(ចំនួនគត់ t)
{
    ចំនួនគត់ ind1 = ind;
    ប្រសិនបើ (nocode_wanted)
        ត្រឡប់ t;

    C67_MVKL(C67_A0, t);	//r=reg to load,  constant
    C67_MVKH(C67_A0, t);	//r=reg to load,  constant
    C67_IREG_B_REG(0, C67_CREG_ZERO, C67_A0);	// [!R] B.S2x  A0
    C67_NOP(5);
    ត្រឡប់ ind1;
}

/* generate a jump to a fixed address */
void gjmp_addr(ចំនួនគត់ a)
{
    Sym *sym;
    // I guess this routine is used for relative short
    // local jumps, for now just handle it as the general
    // case

    // define a label that will be relocated

    sym = get_sym_ref(&char_pointer_type, cur_text_section, a, 0);
    greloc(cur_text_section, sym, ind, R_C60LO16);
    greloc(cur_text_section, sym, ind + 4, R_C60HI16);

    gjmp(0);			// place a zero there later the symbol will be added to it
}

/* generate a test. set 'inv' to invert test. Stack entry is popped */
ST_FUNC ចំនួនគត់ gjmp_cond(ចំនួនគត់ op, ចំនួនគត់ t)
{
        ចំនួនគត់ ind1;
        ចំនួនគត់ inv = op & 1;
        ប្រសិនបើ (nocode_wanted)
            ត្រឡប់ t;

	/* fast case : can jump directly since flags are set */
	// C67 uses B2 sort of as flags register
	ind1 = ind;
	C67_MVKL(C67_A0, t);	//r=reg to load, constant
	C67_MVKH(C67_A0, t);	//r=reg to load, constant

	ប្រសិនបើ (C67_compare_reg != TREG_EAX &&	// check if not already in a conditional test reg
	    C67_compare_reg != TREG_EDX &&
	    C67_compare_reg != TREG_ST0 && C67_compare_reg != C67_B2) {
	    C67_MV(C67_compare_reg, C67_B2);
	    C67_compare_reg = C67_B2;
	}

	C67_IREG_B_REG(C67_invert_test ^ inv, C67_compare_reg, C67_A0);	// [!R] B.S2x  A0
	C67_NOP(5);
	t = ind1;		//return where we need to patch

        ត្រឡប់ t;
}

ST_FUNC ចំនួនគត់ gjmp_append(ចំនួនគត់ n0, ចំនួនគត់ t)
{
    ប្រសិនបើ (n0) {
            ចំនួនគត់ n = n0, *p;
	    /* insert vtop->c jump list in t */

	    // I guess the idea is to traverse to the
	    // null at the end of the list and store t
	    // there
	    ខណៈពេល (n != 0) {
		p = (ចំនួនគត់ *) (cur_text_section->data + n);

		// extract 32 bit address from MVKH/MVKL
		n = ((*p >> 7) & 0xffff);
		n |= ((*(p + 1) >> 7) & 0xffff) << 16;
	    }
	    *p |= (t & 0xffff) << 7;
	    *(p + 1) |= ((t >> 16) & 0xffff) << 7;
	    t = n0;
    }
    ត្រឡប់ t;
}

/* generate an integer binary operation */
void gen_opi(ចំនួនគត់ op)
{
    ចំនួនគត់ r, fr, opc, t;

    switch (op) {
    pak_sa '+':
    pak_sa TOK_ADDC1:		/* add with carry generation */
	opc = 0;
      gen_op8:


// C67 can't do const compares, must load into a reg
// so just go to gv2 directly - tktk



	ប្រសិនបើ (op >= TOK_ULT && op <= TOK_GT)
	    gv2(RC_INT_BSIDE, RC_INT);	// make sure r (src1) is on the B Side of CPU
	បើមិនដូច្នេះ
	    gv2(RC_INT, RC_INT);

	r = vtop[-1].r;
	fr = vtop[0].r;

	C67_compare_reg = C67_B2;


	ប្រសិនបើ (op == TOK_LT) {
	    C67_CMPLT(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_GE) {
	    C67_CMPLT(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_GT) {
	    C67_CMPGT(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_LE) {
	    C67_CMPGT(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_EQ) {
	    C67_CMPEQ(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_NE) {
	    C67_CMPEQ(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_ULT) {
	    C67_CMPLTU(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_UGE) {
	    C67_CMPLTU(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_UGT) {
	    C67_CMPGTU(r, fr, C67_B2);
	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_ULE) {
	    C67_CMPGTU(r, fr, C67_B2);
	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == '+')
	    C67_ADD(fr, r);	// ADD  r,fr,r
	បើមិនដូច្នេះ ប្រសិនបើ (op == '-')
	    C67_SUB(fr, r);	// SUB  r,fr,r
	បើមិនដូច្នេះ ប្រសិនបើ (op == '&')
	    C67_AND(fr, r);	// AND  r,fr,r
	បើមិនដូច្នេះ ប្រសិនបើ (op == '|')
	    C67_OR(fr, r);	// OR  r,fr,r
	បើមិនដូច្នេះ ប្រសិនបើ (op == '^')
	    C67_XOR(fr, r);	// XOR  r,fr,r
	បើមិនដូច្នេះ
	    ALWAYS_ASSERT(FALSE);

	vtop--;
	ប្រសិនបើ (op >= TOK_ULT && op <= TOK_GT)
            vset_VT_CMP(0x80);
	bha_nga;
    pak_sa '-':
    pak_sa TOK_SUBC1:		/* sub with carry generation */
	opc = 5;
	goto gen_op8;
    pak_sa TOK_ADDC2:		/* add with carry use */
	opc = 2;
	goto gen_op8;
    pak_sa TOK_SUBC2:		/* sub with carry use */
	opc = 3;
	goto gen_op8;
    pak_sa '&':
	opc = 4;
	goto gen_op8;
    pak_sa '^':
	opc = 6;
	goto gen_op8;
    pak_sa '|':
	opc = 1;
	goto gen_op8;
    pak_sa '*':
    pak_sa TOK_UMULL:
	gv2(RC_INT, RC_INT);
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_MPYI(fr, r);	// 32 bit multiply  fr,r,fr
	C67_NOP(8);		// NOP 8 for worst case
	bha_nga;
    pak_sa TOK_SHL:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHL(fr, r);		// arithmetic/logical shift
	bha_nga;

    pak_sa TOK_SHR:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHRU(fr, r);	// logical shift
	bha_nga;

    pak_sa TOK_SAR:
	gv2(RC_INT_BSIDE, RC_INT_BSIDE);	// shift amount must be on same side as dst
	r = vtop[-1].r;
	fr = vtop[0].r;
	vtop--;
	C67_SHR(fr, r);		// arithmetic shift
	bha_nga;

    pak_sa '/':
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
	bha_nga;
    pak_sa TOK_UDIV:
    pak_sa TOK_PDIV:
	t = TOK__divu;
	goto call_func;
    pak_sa '%':
	t = TOK__remi;
	goto call_func;
    pak_sa TOK_UMOD:
	t = TOK__remu;
	goto call_func;

    default:
	opc = 7;
	goto gen_op8;
    }
}

/* generate a floating point operation 'v = t1 op t2' instruction. The
   two operands are guaranteed to have the same floating point type */
/* XXX: need to use ST1 too */
void gen_opf(ចំនួនគត់ op)
{
    ចំនួនគត់ ft, fc, fr, r;

    ប្រសិនបើ (op >= TOK_ULT && op <= TOK_GT)
	gv2(RC_EDX, RC_EAX);	// make sure src2 is on b side
    បើមិនដូច្នេះ
	gv2(RC_FLOAT, RC_FLOAT);	// make sure src2 is on b side

    ft = vtop->type.t;
    fc = vtop->c.i;
    r = vtop->r;
    fr = vtop[-1].r;


    ប្រសិនបើ ((ft & VT_BTYPE) == VT_LDOUBLE)
	tcc_error("long doubles not supported");

    ប្រសិនបើ (op >= TOK_ULT && op <= TOK_GT) {

	r = vtop[-1].r;
	fr = vtop[0].r;

	C67_compare_reg = C67_B2;

	ប្រសិនបើ (op == TOK_LT) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPLTDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPLTSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_GE) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPLTDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPLTSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_GT) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPGTDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPGTSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_LE) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPGTDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPGTSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_EQ) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPEQDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPEQSP(r, fr, C67_B2);

	    C67_invert_test = FALSE;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == TOK_NE) {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE)
		C67_CMPEQDP(r, fr, C67_B2);
	    បើមិនដូច្នេះ
		C67_CMPEQSP(r, fr, C67_B2);

	    C67_invert_test = TRUE;
	} បើមិនដូច្នេះ {
	    ALWAYS_ASSERT(FALSE);
	}
        vset_VT_CMP(0x80);
    } បើមិនដូច្នេះ {
	ប្រសិនបើ (op == '+') {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_ADDDP(r, fr);	// ADD  fr,r,fr
		C67_NOP(6);
	    } បើមិនដូច្នេះ {
		C67_ADDSP(r, fr);	// ADD  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == '-') {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_SUBDP(r, fr);	// SUB  fr,r,fr
		C67_NOP(6);
	    } បើមិនដូច្នេះ {
		C67_SUBSP(r, fr);	// SUB  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == '*') {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE) {
		C67_MPYDP(r, fr);	// MPY  fr,r,fr
		C67_NOP(9);
	    } បើមិនដូច្នេះ {
		C67_MPYSP(r, fr);	// MPY  fr,r,fr
		C67_NOP(3);
	    }
	    vtop--;
	} បើមិនដូច្នេះ ប្រសិនបើ (op == '/') {
	    ប្រសិនបើ ((ft & VT_BTYPE) == VT_DOUBLE) {
		// must call intrinsic DP floating point divide
		vswap();
		/* call generic idiv function */
		vpush_helper_func(TOK__divd);
		vrott(3);
		gfunc_call(2);
		vpushi(0);
		vtop->r = REG_FRET;
		vtop->r2 = REG_IRE2;

	    } បើមិនដូច្នេះ {
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
	} បើមិនដូច្នេះ
	    ALWAYS_ASSERT(FALSE);


    }
}


/* convert integers to fp 't' type. Must handle 'int', 'unsigned int'
   and 'long long' cases. */
void gen_cvt_itof(ចំនួនគត់ t)
{
    ចំនួនគត់ r;

    gv(RC_INT);
    r = vtop->r;

    ប្រសិនបើ ((t & VT_BTYPE) == VT_DOUBLE) {
	ប្រសិនបើ (t & VT_UNSIGNED)
	    C67_INTDPU(r, r);
	បើមិនដូច្នេះ
	    C67_INTDP(r, r);

	C67_NOP(4);
	vtop->type.t = VT_DOUBLE;
    } បើមិនដូច្នេះ {
	ប្រសិនបើ (t & VT_UNSIGNED)
	    C67_INTSPU(r, r);
	បើមិនដូច្នេះ
	    C67_INTSP(r, r);
	C67_NOP(3);
	vtop->type.t = VT_FLOAT;
    }

}

/* convert fp to int 't' type */
/* XXX: handle long long case */
void gen_cvt_ftoi(ចំនួនគត់ t)
{
    ចំនួនគត់ r;

    gv(RC_FLOAT);
    r = vtop->r;

    ប្រសិនបើ (t != VT_INT)
	tcc_error("long long not supported");
    បើមិនដូច្នេះ {
	ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE) {
	    C67_DPTRUNC(r, r);
	    C67_NOP(3);
	} បើមិនដូច្នេះ {
	    C67_SPTRUNC(r, r);
	    C67_NOP(3);
	}

	vtop->type.t = VT_INT;

    }
}

/* convert from one floating point type to another */
void gen_cvt_ftof(ចំនួនគត់ t)
{
    ចំនួនគត់ r, r2;

    ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_DOUBLE &&
	(t & VT_BTYPE) == VT_FLOAT) {
	// convert double to float

	gv(RC_FLOAT);		// get it in a register pair

	r = vtop->r;

	C67_DPSP(r, r);		// convert it to SP same register
	C67_NOP(3);

	vtop->type.t = VT_FLOAT;
	vtop->r2 = VT_CONST;	// set this as unused
    } បើមិនដូច្នេះ ប្រសិនបើ ((vtop->type.t & VT_BTYPE) == VT_FLOAT &&
	       (t & VT_BTYPE) == VT_DOUBLE) {
	// convert float to double

	gv(RC_FLOAT);		// get it in a register

	r = vtop->r;

	ប្រសិនបើ (r == TREG_EAX) {	// make sure the paired reg is avail
	    r2 = get_reg(RC_ECX);
	} បើមិនដូច្នេះ ប្រសិនបើ (r == TREG_EDX) {
	    r2 = get_reg(RC_ST0);
	} បើមិនដូច្នេះ {
	    ALWAYS_ASSERT(FALSE);
            r2 = 0; /* avoid warning */
        }

	C67_SPDP(r, r);		// convert it to DP same register
	C67_NOP(1);

	vtop->type.t = VT_DOUBLE;
	vtop->r2 = r2;		// set this as unused
    } បើមិនដូច្នេះ {
	ALWAYS_ASSERT(FALSE);
    }
}

/* computed goto support */
void ggoto(void)
{
    gcall_or_jmp(1);
    vtop--;
}

/* Save the stack pointer onto the stack and return the location of its address */
ST_FUNC void gen_vla_sp_save(ចំនួនគត់ addr) {
    tcc_error("variable length arrays unsupported for this target");
}

/* Restore the SP from a location on the stack */
ST_FUNC void gen_vla_sp_restore(ចំនួនគត់ addr) {
    tcc_error("variable length arrays unsupported for this target");
}

/* Subtract from the stack pointer, and push the resulting value onto the stack */
ST_FUNC void gen_vla_alloc(CType *type, ចំនួនគត់ align) {
    tcc_error("variable length arrays unsupported for this target");
}

/* end of C67 code generator */
/*************************************************************/
#endif
/*************************************************************/
