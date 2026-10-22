/*
 *  TCC - Tiny C Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
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

#define USING_GLOBALS
#ଅନ୍ତର୍ଭାଵ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା rsym, anon_sym, ind, loc;

ST_DATA Sym *global_ଗଦା;
ST_DATA Sym *local_ଗଦା;
ST_DATA Sym *define_ଗଦା;
ST_DATA Sym *global_label_ଗଦା;
ST_DATA Sym *local_label_ଗଦା;

ସ୍ଥିର Sym *sym_free_first;
ସ୍ଥିର ଶୂନ୍ୟ **sym_pools;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sym_pools;

ସ୍ଥିର Sym *all_cleanups, *pending_gotos;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା local_scope;
ST_DATA ଅକ୍ଷର debug_modes;

ST_DATA SValue *vtop;
ସ୍ଥିର SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() ଯଦି(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା global_ପଦସମଷ୍ଟି;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_vc; /* stack address for implicit struct return storage */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_ind; /* function start address */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_old;
ST_DATA ଅଚଳ ଅକ୍ଷର *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
ସ୍ଥିର CString initstr;

#ଯଦି PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#ନଚେତଯଦି LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#ଅନ୍ୟଥା
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

ସ୍ଥିର ସଂରଚନା switch_t {
    ସଂରଚନା case_t {
        int64_t v1, v2;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ind, ଧାଡ଼ି;
    } **p; ପୂର୍ଣ୍ଣସଂଖ୍ୟା n; /* list of case ranges */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା def_sym; /* default symbol */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nocode_wanted;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bsym;
    ସଂରଚନା scope *scope;
    ସଂରଚନା switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_ସଂଖ୍ୟା 8
/*list of temporary local variables on the stack in current function. */
ସ୍ଥିର ସଂରଚନା temp_local_variable {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_ସଂଖ୍ୟା];
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_temp_local_vars;

ସ୍ଥିର ସଂରଚନା scope {
    ସଂରଚନା scope *prev;
    ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା loc, locorig, ଅଙ୍କ; } vla;
    ସଂରଚନା { Sym *s; ପୂର୍ଣ୍ଣସଂଖ୍ୟା n; } cl;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ମୂଳ_scope;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    Section *sec;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା local_offset;
    Sym *flex_array_ref;
} init_params;

#ଯଦି 1
#define precedence_parser
ସ୍ଥିର ଶୂନ୍ୟ init_prec(ଶୂନ୍ୟ);
#endif

ସ୍ଥିର ଶୂନ୍ୟ block(ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
#define STMT_ପଦସମଷ୍ଟି 1
#define STMT_COMPOUND 2

ସ୍ଥିର ଶୂନ୍ୟ gen_cast(CType *type);
ସ୍ଥିର ଶୂନ୍ୟ gen_cast_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ସ୍ଥିର ଧାଡ଼ିଭିତରେ CType *pointed_type(CType *type);
ସ୍ଥିର ଶୂନ୍ୟ check_restrict_type(CType *type);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା type_qualifiers(CType *type);
ସ୍ଥିର ଶୂନ୍ୟ parse_btype_qualify(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା qualifiers);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_compatible_types(CType *type1, CType *type2);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_btype(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ignore_label);
ସ୍ଥିର CType *type_decl(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା td);
ସ୍ଥିର ଶୂନ୍ୟ parse_ପଦସମଷ୍ଟି_type(CType *type);
ସ୍ଥିର ଶୂନ୍ୟ init_putv(init_params *p, CType *type, unsigned long c);
ସ୍ଥିର ଶୂନ୍ୟ decl_initializer(init_params *p, CType *type, unsigned long c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
ସ୍ଥିର ଶୂନ୍ୟ decl_initializer_alloc(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା has_init, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା scope);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା decl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା l);
ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_eq(ଶୂନ୍ୟ);
ସ୍ଥିର ଶୂନ୍ୟ vpush_type_size(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *a);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_compatible_unqualified_types(CType *type1, CType *type2);
ସ୍ଥିର ଧାଡ଼ିଭିତରେ int64_t ପଦସମଷ୍ଟି_const64(ଶୂନ୍ୟ);
ସ୍ଥିର ଶୂନ୍ୟ vpush64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ty, unsigned long long v);
ସ୍ଥିର ଶୂନ୍ୟ vpush(CType *type);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gvtst(ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ସ୍ଥିର ଶୂନ୍ୟ gen_inline_functions(TCCState *s);
ସ୍ଥିର ଶୂନ୍ୟ free_inline_functions(TCCState *s);
ସ୍ଥିର ଶୂନ୍ୟ skip_or_save_block(TokenString **str);
ସ୍ଥିର ଶୂନ୍ୟ gv_dup(ଶୂନ୍ୟ);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_temp_local_var(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା align,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *r2);
ସ୍ଥିର ଶୂନ୍ୟ cast_error(CType *st, CType *dt);
ସ୍ଥିର ଶୂନ୍ୟ end_switch(ଶୂନ୍ୟ);
ସ୍ଥିର ଶୂନ୍ୟ do_Static_assert(ଶୂନ୍ୟ);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC ଶୂନ୍ୟ gsym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
  ଯଦି (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gind()
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = ind;
  CODE_ON();
  ଯଦି (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  ଫେରନ୍ତୁ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ସ୍ଥିର ଶୂନ୍ୟ gjmp_addr_acs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_acs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
  t = gjmp(t);
  CODE_OFF();
  ଫେରନ୍ତୁ t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_float(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt = t & VT_BTYPE;
    ଫେରନ୍ତୁ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_integer_btype(ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt)
{
    ଫେରନ୍ତୁ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା btype_size(ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt)
{
    ଫେରନ୍ତୁ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା R_RET(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି (!is_float(t))
        ଫେରନ୍ତୁ REG_IRET;
#ifdef TCC_TARGET_X86_64
    ଯଦି ((t & VT_BTYPE) == VT_LDOUBLE)
        ଫେରନ୍ତୁ TREG_ST0;
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
    ଯଦି ((t & VT_BTYPE) == VT_LDOUBLE)
        ଫେରନ୍ତୁ REG_IRET;
#endif
    ଫେରନ୍ତୁ REG_FRET;
}

/* returns 2nd function return register, if any */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା R2_RET(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    t &= VT_BTYPE;
#ଯଦି PTR_SIZE == 4
    ଯଦି (t == VT_LLONG)
        ଫେରନ୍ତୁ REG_IRE2;
#ନଚେତଯଦି defined TCC_TARGET_X86_64
    ଯଦି (t == VT_QLONG)
        ଫେରନ୍ତୁ REG_IRE2;
    ଯଦି (t == VT_QFLOAT)
        ଫେରନ୍ତୁ REG_FRE2;
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
    ଯଦି (t == VT_LDOUBLE)
        ଫେରନ୍ତୁ REG_IRE2;
#endif
    ଫେରନ୍ତୁ VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_ଶବ୍ଦଗୁଡ଼ିକ(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ସ୍ଥିର ଶୂନ୍ୟ PUT_R_RET(SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା RC_RET(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଫେରନ୍ତୁ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା RC_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି (!is_float(t))
        ଫେରନ୍ତୁ RC_INT;
#ifdef TCC_TARGET_X86_64
    ଯଦି ((t & VT_BTYPE) == VT_LDOUBLE)
        ଫେରନ୍ତୁ RC_ST0;
    ଯଦି ((t & VT_BTYPE) == VT_QFLOAT)
        ଫେରନ୍ତୁ RC_FRET;
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
    ଯଦି ((t & VT_BTYPE) == VT_LDOUBLE)
        ଫେରନ୍ତୁ RC_INT;
#endif
    ଫେରନ୍ତୁ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା RC2_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc)
{
    ଯଦି (!USING_TWO_ଶବ୍ଦଗୁଡ଼ିକ(t))
        ଫେରନ୍ତୁ 0;
#ifdef RC_IRE2
    ଯଦି (rc == RC_IRET)
        ଫେରନ୍ତୁ RC_IRE2;
#endif
#ifdef RC_FRE2
    ଯଦି (rc == RC_FRET)
        ଫେରନ୍ତୁ RC_FRE2;
#endif
    ଯଦି (rc & RC_FLOAT)
        ଫେରନ୍ତୁ RC_FLOAT;
    ଫେରନ୍ତୁ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା ieee_finite(ଦ୍ୱିଗୁଣ d)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା p[4];
    memcpy(p, &d, ଆକାର(ଦ୍ୱିଗୁଣ));
    ଫେରନ୍ତୁ ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC ଶୂନ୍ୟ test_lvalue(ଶୂନ୍ୟ)
{
    ଯଦି (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC ଶୂନ୍ୟ check_vstack(ଶୂନ୍ୟ)
{
    ଯଦି (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(vtop - vstack + 1));
}

#ଯଦି 0
/* dump 'b' vstack entries starting with 'a'  */
ଶୂନ୍ୟ pv (ଅଚଳ ଅକ୍ଷର *lbl, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ psyms(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", ସନ୍ଦେଶ);
    ଯେତେବେଳେ (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ type_to_str(ଅକ୍ଷର *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା buf_size, CType *type, ଅଚଳ ଅକ୍ଷର *varstr);

/* print type */
ସ୍ଥିର ଶୂନ୍ୟ ptype(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ, CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    ଅକ୍ଷର buf[500];
    type_to_str(buf, ଆକାର(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, ଖାଲି) : ଖାଲି);
    printf("%s : %s;\n", ସନ୍ଦେଶ, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC ଶୂନ୍ୟ tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, ଆକାର *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ଯଦି (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ଠେଲ(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_ପଦସମଷ୍ଟି = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_ଅଙ୍କ | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ଯଦି TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    ଫେରନ୍ତୁ 0;
}

ST_FUNC ଶୂନ୍ୟ tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_କାଢ଼(&global_ଗଦା, ଖାଲି, 0);
    sym_କାଢ଼(&local_ଗଦା, ଖାଲି, 0);
    /* free preprocessor macros */
    free_defines(ଖାଲି);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    ଯେତେବେଳେ (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = ଖାଲି;
    all_cleanups = ଖାଲି;
    pending_gotos = ଖାଲି;
    nb_temp_local_vars = 0;
    global_label_ଗଦା = ଖାଲି;
    local_label_ଗଦା = ଖାଲି;
    cur_text_section = ଖାଲି;
    sym_free_first = ଖାଲି;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ଯଦି (!s || !s->c)
    ଫେରନ୍ତୁ ଖାଲି;
  ଫେରନ୍ତୁ &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC ଶୂନ୍ୟ update_storage(Sym *sym)
{
    ElfSym *esym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ଯଦି (!esym)
        ଫେରନ୍ତୁ;

    ଯଦି (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ଯଦି (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ଅନ୍ୟଥା ଯଦି (sym->a.weak)
        sym_bind = STB_WEAK;
    ଅନ୍ୟଥା
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ଯଦି (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    ଯଦି (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ଯଦି (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#ଯଦି 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ଖାଲି),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#endif
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC ଶୂନ୍ୟ put_extern_sym2(Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ,
                            addr_t ମୂଲ୍ୟ, unsigned long size,
                            ପୂର୍ଣ୍ଣସଂଖ୍ୟା can_add_underscore)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ଅଚଳ ଅକ୍ଷର *name;
    ଅକ୍ଷର buf1[256];

    ଯଦି (!sym->c) {
        name = get_tok_str(sym->v, ଖାଲି);
        t = sym->type.t;
        ଯଦି ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ଅନ୍ୟଥା ଯଦି ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ଯଦି (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ଅନ୍ୟଥା ଯଦି (t & VT_TLS) {
            sym_type = STT_TLS;
        } ଅନ୍ୟଥା {
            sym_type = STT_OBJECT;
        }
        ଯଦି (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ଅନ୍ୟଥା
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        ଯଦି (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ଯଦି (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            ଯଦି (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        ଯଦି (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ଖାଲି);
            can_add_underscore = 0;
        }

        ଯଦି (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, ଆକାର(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, ମୂଲ୍ୟ, size, info, other, sh_ଅଙ୍କ, name);

        ଯଦି (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_ଅଙ୍କ, sym_bind, sym_type);

    } ଅନ୍ୟଥା {
        esym = elfsym(sym);
        esym->st_ମୂଲ୍ୟ = ମୂଲ୍ୟ;
        esym->st_size = size;
        esym->st_shndx = sh_ଅଙ୍କ;
    }
    update_storage(sym);
}

ST_FUNC ଶୂନ୍ୟ put_extern_sym(Sym *sym, Section *s, addr_t ମୂଲ୍ୟ, unsigned long size)
{
    ଯଦି (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        ଫେରନ୍ତୁ;
    put_extern_sym2(sym, s ? s->sh_ଅଙ୍କ : SHN_UNDEF, ମୂଲ୍ୟ, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC ଶୂନ୍ୟ greloca(Section *s, Sym *sym, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type,
                     addr_t addend)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 0;

    ଯଦି (nocode_wanted && s == cur_text_section)
        ଫେରନ୍ତୁ;

    ଯଦି (sym) {
        ଯଦି (0 == sym->c) {
            put_extern_sym(sym, ଖାଲି, 0, 0);
            ଯଦି (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ଯେତେବେଳେ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#ଯଦି PTR_SIZE == 4
ST_FUNC ଶୂନ୍ୟ greloc(Section *s, Sym *sym, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ସ୍ଥିର Sym *__sym_malloc(ଶୂନ୍ୟ)
{
    Sym *sym_pool, *sym, *last_sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    sym_pool = tcc_malloc(SYM_POOL_NB * ଆକାର(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    ପାଇଁ(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    ଫେରନ୍ତୁ last_sym;
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ Sym *sym_malloc(ଶୂନ୍ୟ)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    ଯଦି (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    ଫେରନ୍ତୁ sym;
#ଅନ୍ୟଥା
    sym = tcc_malloc(ଆକାର(Sym));
    ଫେରନ୍ତୁ sym;
#endif
}

ST_INLN ଶୂନ୍ୟ sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#ଅନ୍ୟଥା
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, ଆକାର *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    ଫେରନ୍ତୁ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    ଯେତେବେଳେ (s) {
        ଯଦି (s->v == v)
            ଫେରନ୍ତୁ s;
        s = s->prev;
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

/* structure lookup */
ST_INLN Sym *struct_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    v -= TOK_IDENT;
    ଯଦି ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ଫେରନ୍ତୁ ଖାଲି;
    ଫେରନ୍ତୁ table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    v -= TOK_IDENT;
    ଯଦି ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ଫେରନ୍ତୁ ଖାଲି;
    ଫେରନ୍ତୁ table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ sym_link(Sym *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ଯଦି (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ଅନ୍ୟଥା
        ps = &ts->sym_identifier;
    ଯଦି (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ଅନ୍ୟଥା {
        *ps = s->prev_tok;
    }
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ଫେରନ୍ତୁ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    Sym *s, **ps;
    ଯଦି (local_ଗଦା)
        ps = &local_ଗଦା;
    ଅନ୍ୟଥା
        ps = &global_ଗଦା;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ଯଦି ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ଯଦି (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ଖାଲି));
    }
    ଫେରନ୍ତୁ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ଗଦା, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ଯଦି (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ଯେତେବେଳେ (*ps != ଖାଲି && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    ଫେରନ୍ତୁ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC ଶୂନ୍ୟ sym_କାଢ଼(Sym **ptop, Sym *b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା keep)
{
    Sym *s, *ss;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;

    s = *ptop;
    ଯେତେବେଳେ(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ଯଦି ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	ଯଦି (!keep)
	    sym_free(s);
        s = ss;
    }
    ଯଦି (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    v -= TOK_IDENT;
    ଯଦି ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ଫେରନ୍ତୁ ଖାଲି;
    ଫେରନ୍ତୁ table_ident[v]->sym_label;
}

ST_FUNC Sym *label_ଠେଲ(Sym **ptop, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    ଯଦି (ptop == &global_label_ଗଦା) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ଯେତେବେଳେ (*ps != ଖାଲି)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    ଫେରନ୍ତୁ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC ଶୂନ୍ୟ label_କାଢ଼(Sym **ptop, Sym *slast, ପୂର୍ଣ୍ଣସଂଖ୍ୟା keep)
{
    Sym *s, *s1;
    ପାଇଁ(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ଯଦି (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ଖାଲି));
        } ଅନ୍ୟଥା ଯଦି (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ଖାଲି));
        } ଅନ୍ୟଥା {
            ଯଦି (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        ଯଦି (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ଯଦି (!keep)
            sym_free(s);
        ଅନ୍ୟଥା
            s->r = LABEL_GONE;
    }
    ଯଦି (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ସ୍ଥିର ଶୂନ୍ୟ vcheck_cmp(ଶୂନ୍ୟ)
{
    /* cannot let cpu flags if other instruction are generated. Also
       avoid leaving VT_JMP anywhere except on the top of the stack
       because it would complicate the code generator.

       Don't do this when nocode_wanted.  vtop might come from
       !nocode_wanted regions (see 88_codeopt.c) and transforming
       it to a register without actually generating code is wrong
       as their value might still be used for real.  All values
       we push under nocode_wanted will eventually be popped
       again, so that the VT_CMP/VT_JMP value will be in vtop
       when code is unsuppressed again. */

    /* However if it's just automatic suppression via CODE_OFF/ON()
       then it seems that we better let things work undisturbed.
       How can it work at all under nocode_wanted?  Well, gv() will
       actually clear it at the gsym() in load()/VT_JMP in the
       generator backends */

    ଯଦି (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

ସ୍ଥିର ଶୂନ୍ୟ vsetc(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, CValue *vc)
{
    ଯଦି (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ଖାଲି;
}

ST_FUNC ଶୂନ୍ୟ vswap(ଶୂନ୍ୟ)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC ଶୂନ୍ୟ vpop(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
    v = vtop->r & VT_VALMASK;
#ଯଦି defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    ଯଦି (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ଅନ୍ୟଥା
#endif
    ଯଦି (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ସ୍ଥିର ଶୂନ୍ୟ vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ସ୍ଥିର ଶୂନ୍ୟ vpush64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ଖାଲି;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC ଶୂନ୍ୟ vpushi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ସ୍ଥିର ଶୂନ୍ୟ vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC ଶୂନ୍ୟ vset(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ସ୍ଥିର ଶୂନ୍ୟ vseti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ଖାଲି;
    vset(&type, r, v);
}

ST_FUNC ଶୂନ୍ୟ vpushv(SValue *v)
{
    ଯଦି (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ସ୍ଥିର ଶୂନ୍ୟ vdup(ଶୂନ୍ୟ)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC ଶୂନ୍ୟ vrotb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    SValue tmp;
    ଯଦି (--n < 1)
        ଫେରନ୍ତୁ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, ଆକାର *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC ଶୂନ୍ୟ vrott(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    SValue tmp;
    ଯଦି (--n < 1)
        ଫେରନ୍ତୁ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, ଆକାର *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC ଶୂନ୍ୟ vrev(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    SValue tmp;
    vcheck_cmp();
    ପାଇଁ (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC ଶୂନ୍ୟ vset_VT_CMP(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ସ୍ଥିର ଶୂନ୍ୟ vset_VT_JMP(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op = vtop->cmp_op;

    ଯଦି (vtop->jtrue || vtop->jfalse) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ଅନ୍ୟଥା {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ଯଦି (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ସ୍ଥିର ଶୂନ୍ୟ gvtst_set(ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p;

    ଯଦି (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ଯଦି (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gvtst(ପୂର୍ଣ୍ଣସଂଖ୍ୟା inv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ଯଦି (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ଯଦି (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ଅନ୍ୟଥା ଯଦି (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ଫେରନ୍ତୁ t;
}

/* generate a zero or nozero test */
ସ୍ଥିର ଶୂନ୍ୟ gen_test_zero(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ଯଦି (vtop->r == VT_CMP) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;
        ଯଦି (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ଅନ୍ୟଥା {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC ଶୂନ୍ୟ vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ଠେଲ(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    ଫେରନ୍ତୁ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ସ୍ଥିର ଶୂନ୍ୟ vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    ଯଦି (!s) {
        /* push forward reference */
        s = global_identifier_ଠେଲ(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ଅନ୍ୟଥା ଯଦି (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ଫେରନ୍ତୁ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    CType ct = { VT_ASM_FUNC, ଖାଲି };
    ଫେରନ୍ତୁ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC ଶୂନ୍ୟ vpush_helper_func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ସ୍ଥିର ଶୂନ୍ୟ merge_symattr(ସଂରଚନା SymAttr *sa, ସଂରଚନା SymAttr *sa1)
{
    ଯଦି (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ଯଦି (sa1->visibility != STV_DEFAULT) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା vis = sa->visibility;
	ଯଦି (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ସ୍ଥିର ଶୂନ୍ୟ merge_funcattr(ସଂରଚନା FuncAttr *fa, ସଂରଚନା FuncAttr *fa1)
{
    ଯଦି (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ଯଦି (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ଯଦି (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    ଯଦି (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ଯଦି (fa1->func_ctor)
      fa->func_ctor = 1;
    ଯଦି (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ସ୍ଥିର ଶୂନ୍ୟ merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    ଯଦି (ad1->section)
      ad->section = ad1->section;
    ଯଦି (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    ଯଦି (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ଯଦି (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
ସ୍ଥିର ଶୂନ୍ୟ patch_type(Sym *sym, CType *type)
{
    ଯଦି (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ଯଦି (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ଖାଲି));
        sym->type.t &= ~VT_EXTERN;
    }

    ଯଦି (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ଯଦି ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ଯଦି (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ଖାଲି));

    } ଅନ୍ୟଥା ଯଦି ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା static_proto = sym->type.t & VT_STATIC;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ft1 = sym->type.ref->f.func_type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ଯଦି ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ଖାଲି));

        /* set 'inline' if both agree or if one has static */
        ଯଦି ((type->t | sym->type.t) & VT_INLINE) {
            ଯଦି (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ଯଦି (0 == (type->t & VT_EXTERN)) {
            ସଂରଚନା FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ଯଦି (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } ଅନ୍ୟଥା {
            sym->type.t &= ~VT_INLINE | static_proto;
            ଯଦି (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ଅନ୍ୟଥା {
        ଯଦି ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ଯଦି ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ଖାଲି));
    }
}

/* Merge some storage attributes.  */
ସ୍ଥିର ଶୂନ୍ୟ patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ଯଦି (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    ଯଦି (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ଖାଲି));
#endif
    merge_symattr(&sym->a, &ad->a);
    ଯଦି (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ସ୍ଥିର Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ଯଦି ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    ଫେରନ୍ତୁ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ସ୍ଥିର ଶୂନ୍ୟ move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, bt;

    bt = s->type.t & VT_BTYPE;
    ଯଦି (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ଫେରନ୍ତୁ;

    ପାଇଁ (s = s->type.ref, n = 0; s; s = s->next) {
        ପାଇଁ (lp = &local_ଗଦା; !!(l = *lp); lp = &l->prev) {
            ଯଦି (l == s) {
                *lp = s->prev;
                s->prev = global_ଗଦା, global_ଗଦା = s;
                ଯଦି (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } ଅନ୍ୟଥା {
                    ଯଦି ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                ଯଦି (bt != VT_PTR)
                    n = 1;
                ଭାଙ୍ଗ;
            }
        }
        ଯଦି (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            ଭାଙ୍ଗ;
    }
}

/* define a new external reference to a symbol 'v' */
ସ୍ଥିର Sym *external_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    ଯେତେବେଳେ (s && s->sym_scope)
        s = s->prev_tok;

    ଯଦି (!s) {
        /* push forward reference */
        s = global_identifier_ଠେଲ(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ଅନ୍ୟଥା {
        patch_storage(s, ad, type);
    }
    ଯଦି (local_ଗଦା) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_ଗଦା);
    }
    ଫେରନ୍ତୁ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC ଶୂନ୍ୟ save_regs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    SValue *p, *p1;
    ପାଇଁ(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC ଶୂନ୍ୟ save_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC ଶୂନ୍ୟ save_reg_upstack(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା l, size, align, bt, r2;
    SValue *p, *p1, sv;

    ଯଦି ((r &= VT_VALMASK) >= VT_CONST)
        ଫେରନ୍ତୁ;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    l = r2 = 0;
    ପାଇଁ(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ଯଦି ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ଯଦି (!l) {
                bt = p->type.t & VT_BTYPE;
                ଯଦି (bt == VT_VOID)
                    ଜାରି;
                ଯଦି ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ଖାଲି;
                store(p->r & VT_VALMASK, &sv);
#ଯଦି defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ଯଦି (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                ଯଦି (p->r2 < VT_CONST && USING_TWO_ଶବ୍ଦଗୁଡ଼ିକ(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ଯଦି (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ଅନ୍ୟଥା {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ଖାଲି;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_reg_ex(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc2)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    SValue *p;
    
    ପାଇଁ(r=0;r<NB_REGS;r++) {
        ଯଦି (reg_classes[r] & rc2) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
            n=0;
            ପାଇଁ(p = vstack; p <= vtop; p++) {
                ଯଦି ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ଯଦି (n <= 1)
                ଫେରନ୍ତୁ r;
        }
    }
    ଫେରନ୍ତୁ get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    SValue *p;

    /* find a free register */
    ପାଇଁ(r=0;r<NB_REGS;r++) {
        ଯଦି (reg_classes[r] & rc) {
            ଯଦି (nocode_wanted)
                ଫେରନ୍ତୁ r;
            ପାଇଁ(p=vstack;p<=vtop;p++) {
                ଯଦି ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    ଯାଅ notfound;
            }
            ଫେରନ୍ତୁ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    ପାଇଁ(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ଯଦି (r < VT_CONST && (reg_classes[r] & rc))
            ଯାଅ save_found;
        r = p->r & VT_VALMASK;
        ଯଦି (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            ଫେରନ୍ତୁ r;
        }
    }
    /* Should never comes here */
    ଫେରନ୍ତୁ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_temp_local_var(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size,ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *r2)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ସଂରଚନା temp_local_variable *temp_var;
    SValue *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    unsigned used = 0;

    /* mark locations that are still in use */
    ପାଇଁ (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ଯଦି (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ଯଦି (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_ସଂଖ୍ୟା)
	        used |= 1<<r;
	}
    }
    ପାଇଁ (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	ଯଦି(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ଫେରନ୍ତୁ temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    ଯଦି (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_ସଂଖ୍ୟା) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	ଯାଅ ret_tmp;
    }
    *r2 = VT_CONST;
    ଫେରନ୍ତୁ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ସ୍ଥିର ଶୂନ୍ୟ move_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    SValue sv;

    ଯଦି (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ଖାଲି;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC ଶୂନ୍ୟ gaddrof(ଶୂନ୍ୟ)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ଯଦି ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ସ୍ଥିର ଶୂନ୍ୟ gen_bounded_ptr_add(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ଯଦି (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK___bound_ptr_add);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - ଆକାର(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ସ୍ଥିର ଶୂନ୍ୟ gen_bounded_ptr_deref(ଶୂନ୍ୟ)
{
    addr_t func;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align;
    ElfW_Rel *rel;
    Sym *sym;

    ଯଦି (nocode_wanted)
        ଫେରନ୍ତୁ;

    size = type_size(&vtop->type, &align);
    ବାଛ(size) {
    ସ୍ଥିତି  1: func = TOK___bound_ptr_indir1; ଭାଙ୍ଗ;
    ସ୍ଥିତି  2: func = TOK___bound_ptr_indir2; ଭାଙ୍ଗ;
    ସ୍ଥିତି  4: func = TOK___bound_ptr_indir4; ଭାଙ୍ଗ;
    ସ୍ଥିତି  8: func = TOK___bound_ptr_indir8; ଭାଙ୍ଗ;
    ସ୍ଥିତି 12: func = TOK___bound_ptr_indir12; ଭାଙ୍ଗ;
    ସ୍ଥିତି 16: func = TOK___bound_ptr_indir16; ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        /* may happen with struct member access */
        ଫେରନ୍ତୁ;
    }
    sym = external_helper_sym(func);
    ଯଦି (!sym->c)
        put_extern_sym(sym, ଖାଲି, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ସ୍ଥିର ଶୂନ୍ୟ gbound(ଶୂନ୍ୟ)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ଯଦି (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ଯଦି (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_add();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC ଶୂନ୍ୟ gbound_args(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, v;
    SValue *sv;

    ପାଇଁ (i = 1; i <= nb_args; ++i)
        ଯଦି (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    ଯଦି (sv->r & VT_SYM) {
        v = sv->sym->v;
        ଯଦି (v == TOK_setjmp
          || v == TOK__setjmp
#ifndef TCC_TARGET_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#endif
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_add_epilog = 1;
        }
        ଯଦି (v == TOK_alloca)
            func_bound_add_epilog = 1;
#ଯଦି TARGETOS_NetBSD
        ଯଦି (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ସ୍ଥିର ଶୂନ୍ୟ add_local_bounds(Sym *s, Sym *e)
{
    ପାଇଁ (; s != e; s = s->prev) {
        ଯଦି (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ଜାରି;
        /* Add arrays/structs/unions because we always take address */
        ଯଦି ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * ଆକାର(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
ସ୍ଥିର ଶୂନ୍ୟ tcc_debug_end_scope(Sym *b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bounds)
{
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_ଗଦା, b);
#endif
    tcc_add_debug_info (tcc_state, local_ଗଦା, b);
}

/* increment an lvalue pointer */
ସ୍ଥିର ଶୂନ୍ୟ incr_offset(ପୂର୍ଣ୍ଣସଂଖ୍ୟା offset)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ସ୍ଥିର ଶୂନ୍ୟ incr_bf_adr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ସ୍ଥିର ଶୂନ୍ୟ load_packed_bf(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_pos, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    କର {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        ଯଦି (n > bit_size)
            n = bit_size;
        ଯଦି (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        ଯଦି (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ଯଦି (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } ଯେତେବେଳେ (bit_size);
    vswap(), vpop();
    ଯଦି (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ସ୍ଥିର ଶୂନ୍ୟ store_packed_bf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_pos, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    କର {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ଯଦି (bits)
            vpushi(bits), gen_op(TOK_SHR);
        ଯଦି (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        ଯଦି (n > bit_size)
            n = bit_size;
        ଯଦି (n < 8) {
            m = ((1 << n) - 1) << bit_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        bits += n, bit_size -= n, bit_pos = 0, o = 1;
    } ଯେତେବେଳେ (bit_size);
    vpop(), vpop();
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା adjust_bf(SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_pos, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ଯଦି (0 == sv->type.ref)
        ଫେରନ୍ତୁ 0;
    t = sv->type.ref->auxtype;
    ଯଦି (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ଫେରନ୍ତୁ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, r2, r_ok, r2_ok, rc2, bt;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    ଯଦି (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = ଖାଲି;
        type.t = vtop->type.t & VT_UNSIGNED;
        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ଅନ୍ୟଥା
            type.t |= VT_INT;

        ଯଦି (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } ଅନ୍ୟଥା {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(bits - (bit_pos + bit_size));
            gen_op(TOK_SHL);
            vpushi(bits - bit_size);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } ଅନ୍ୟଥା {
        ଯଦି (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            ଯଦି (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        ଯଦି (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ଫେରନ୍ତୁ vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        ଯଦି (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#endif
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        ଯଦି (!r_ok || !r2_ok) {

            ଯଦି (!r_ok) {
                ଯଦି (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ଅନ୍ୟଥା
                    r = get_reg(rc);
            }

            ଯଦି (rc2) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ଅନ୍ୟଥା ଯଦି (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = load_type;
                    load(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_offset(PTR_SIZE);
                } ଅନ୍ୟଥା {
                    /* move registers */
                    ଯଦି (!r_ok)
                        load(r, vtop);
                    ଯଦି (r2_ok && vtop->r2 < VT_CONST)
                        ଯାଅ done;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                load(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            done:
                vtop->type.t = original_type;
            } ଅନ୍ୟଥା {
                ଯଦି (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        ଯଦି (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    ଫେରନ୍ତୁ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC ଶୂନ୍ୟ gv2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ଯଦି (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ଯଦି ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ଅନ୍ୟଥା {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ଯଦି ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ଯଦି PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC ଶୂନ୍ୟ lexpand(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ଯଦି (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ଅନ୍ୟଥା ଯଦି (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ଅନ୍ୟଥା {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#ଯଦି PTR_SIZE == 4
/* build a long long from two ints */
ସ୍ଥିର ଶୂନ୍ୟ lbuild(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
ସ୍ଥିର ଶୂନ୍ୟ gv_dup(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, rc, r;

    t = vtop->type.t;
#ଯଦି PTR_SIZE == 4
    ଯଦି ((t & VT_BTYPE) == VT_LLONG) {
        ଯଦି (t & VT_BITFIELD) {
            gv(RC_INT);
            t = vtop->type.t;
        }
        lexpand();
        gv_dup();
        vswap();
        vrotb(3);
        gv_dup();
        vrotb(4);
        /* stack: H L L1 H1 */
        lbuild(t);
        vrotb(3);
        vrotb(3);
        vswap();
        lbuild(t);
        vswap();
        ଫେରନ୍ତୁ;
    }
#endif
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    load(r, vtop);
    vtop->r = r;
}

#ଯଦି PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
ସ୍ଥିର ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, a, b, op1, c, i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    ବାଛ(op) {
    ସ୍ଥିତି '/':
    ସ୍ଥିତି TOK_PDIV:
        func = TOK___divdi3;
        ଯାଅ gen_func;
    ସ୍ଥିତି TOK_UDIV:
        func = TOK___udivdi3;
        ଯାଅ gen_func;
    ସ୍ଥିତି '%':
        func = TOK___moddi3;
        ଯାଅ gen_mod_func;
    ସ୍ଥିତି TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#ifdef TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#endif
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '^':
    ସ୍ଥିତି '&':
    ସ୍ଥିତି '|':
    ସ୍ଥିତି '*':
    ସ୍ଥିତି '+':
    ସ୍ଥିତି '-':
        //pv("gen_opl A",0,2);
        t = vtop->type.t;
        vswap();
        lexpand();
        vrotb(3);
        lexpand();
        /* stack: L1 H1 L2 H2 */
        tmp = vtop[0];
        vtop[0] = vtop[-3];
        vtop[-3] = tmp;
        tmp = vtop[-2];
        vtop[-2] = vtop[-3];
        vtop[-3] = tmp;
        vswap();
        /* stack: H1 H2 L1 L2 */
        //pv("gen_opl B",0,4);
        ଯଦି (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            ପାଇଁ(i=0;i<4;i++)
                vrotb(6);
            /* stack: ML MH H1 H2 L1 L2 */
            tmp = vtop[0];
            vtop[0] = vtop[-2];
            vtop[-2] = tmp;
            /* stack: ML MH H1 L2 H2 L1 */
            gen_op('*');
            vrotb(3);
            vrotb(3);
            gen_op('*');
            /* stack: ML MH M1 M2 */
            gen_op('+');
            gen_op('+');
        } ଅନ୍ୟଥା ଯଦି (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ଯଦି (op == '+')
                op1 = TOK_ADDC1;
            ଅନ୍ୟଥା
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ଅନ୍ୟଥା {
            gen_op(op);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            /* stack: (L1 op L2) H1 H2 */
            gen_op(op);
            /* stack: (L1 op L2) (H1 op H2) */
        }
        /* stack: L H */
        lbuild(t);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SAR:
    ସ୍ଥିତି TOK_SHR:
    ସ୍ଥିତି TOK_SHL:
        ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ଯଦି (op != TOK_SHL)
                vswap();
            ଯଦି (c >= 32) {
                /* stack: L H */
                vpop();
                ଯଦି (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ଯଦି (op != TOK_SAR) {
                    vpushi(0);
                } ଅନ୍ୟଥା {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ଅନ୍ୟଥା {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ଯଦି (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ଅନ୍ୟଥା
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ଯଦି (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ଅନ୍ୟଥା
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ଯଦି (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ଅନ୍ୟଥା {
            /* XXX: should provide a faster fallback on x86 ? */
            ବାଛ(op) {
            ସ୍ଥିତି TOK_SAR:
                func = TOK___ashrdi3;
                ଯାଅ gen_func;
            ସ୍ଥିତି TOK_SHR:
                func = TOK___lshrdi3;
                ଯାଅ gen_func;
            ସ୍ଥିତି TOK_SHL:
                func = TOK___ashldi3;
                ଯାଅ gen_func;
            }
        }
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        /* compare operations */
        t = vtop->type.t;
        vswap();
        lexpand();
        vrotb(3);
        lexpand();
        /* stack: L1 H1 L2 H2 */
        tmp = vtop[-1];
        vtop[-1] = vtop[-2];
        vtop[-2] = tmp;
        /* stack: L1 L2 H1 H2 */
        ଯଦି (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ଯଦି (op1 == TOK_LT)
            op1 = TOK_LE;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_GT)
            op1 = TOK_GE;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ଯଦି (op == TOK_NE) {
            b = gvtst(0, 0);
        } ଅନ୍ୟଥା {
            a = gvtst(1, 0);
            ଯଦି (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ଯଦି (op1 == TOK_LT)
            op1 = TOK_ULT;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_LE)
            op1 = TOK_ULE;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_GT)
            op1 = TOK_UGT;
        ଅନ୍ୟଥା ଯଦି (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ଯଦି 0//def TCC_TARGET_I386
        ଯଦି (op == TOK_NE) { gsym(b); ଭାଙ୍ଗ; }
        ଯଦି (op == TOK_EQ) { gsym(a); ଭାଙ୍ଗ; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        ଭାଙ୍ଗ;
    }
}
#endif

/* normalize values */
ସ୍ଥିର uint64_t value64(uint64_t l1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        ଫେରନ୍ତୁ l1;
    ଅନ୍ୟଥା ଯଦି (t & VT_UNSIGNED)
        ଫେରନ୍ତୁ (uint32_t)l1;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ (uint32_t)l1 | -(l1 & 0x80000000);
}

ସ୍ଥିର uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ଫେରନ୍ତୁ (a ^ b) >> 63 ? -x : x;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gen_opic_lt(uint64_t a, uint64_t b)
{
    ଫେରନ୍ତୁ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ସ୍ଥିର ଶୂନ୍ୟ gen_opic(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t1 = v1->type.t & VT_BTYPE;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t2 = v2->type.t & VT_BTYPE;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା shm = (t1 == VT_LLONG) ? 63 : 31;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;

    ଯଦି (c1 && c2) {
        ବାଛ(op) {
        ସ୍ଥିତି '+': l1 += l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '-': l1 -= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '&': l1 &= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '^': l1 ^= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '|': l1 |= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '*': l1 *= l2; ଭାଙ୍ଗ;

        ସ୍ଥିତି TOK_PDIV:
        ସ୍ଥିତି '/':
        ସ୍ଥିତି '%':
        ସ୍ଥିତି TOK_UDIV:
        ସ୍ଥିତି TOK_UMOD:
            /* if division by zero, generate explicit division */
            ଯଦି (l2 == 0) {
                ଯଦି (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                ଯାଅ general_case;
            }
            ବାଛ(op) {
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ: l1 = gen_opic_sdiv(l1, l2); ଭାଙ୍ଗ;
            ସ୍ଥିତି '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_UDIV: l1 = l1 / l2; ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_UMOD: l1 = l1 % l2; ଭାଙ୍ଗ;
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SHL: l1 <<= (l2 & shm); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SHR: l1 >>= (l2 & shm); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            ଭାଙ୍ଗ;
            /* tests */
        ସ୍ଥିତି TOK_ULT: l1 = l1 < l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_UGE: l1 = l1 >= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_EQ: l1 = l1 == l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NE: l1 = l1 != l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ULE: l1 = l1 <= l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_UGT: l1 = l1 > l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LT: l1 = gen_opic_lt(l1, l2); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GE: l1 = !gen_opic_lt(l1, l2); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LE: l1 = !gen_opic_lt(l2, l1); ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_GT: l1 = gen_opic_lt(l2, l1); ଭାଙ୍ଗ;
            /* logical */
        ସ୍ଥିତି TOK_LAND: l1 = l1 && l2; ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_LOR: l1 = l1 || l2; ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଯାଅ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ଅନ୍ୟଥା {
        /* if commutative ops, put c2 as constant */
        ଯଦି (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ଯଦି (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ଅନ୍ୟଥା ଯଦି (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ଯଦି (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ଅନ୍ୟଥା ଯଦି (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ଅନ୍ୟଥା ଯଦି (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ଯଦି (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = -1;
                ଯଦି (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    ଯାଅ general_case;
                }
                ଯେତେବେଳେ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ଯଦି (op == '*')
                    op = TOK_SHL;
                ଅନ୍ୟଥା ଯଦି (op == TOK_PDIV)
                    op = TOK_SAR;
                ଅନ୍ୟଥା
                    op = TOK_SHR;
            }
            ଯାଅ general_case;
        } ଅନ୍ୟଥା ଯଦି (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ଯଦି (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)l2 != l2)
	        ଯାଅ general_case;
            vtop--;
            vtop->c.i = l2;
        } ଅନ୍ୟଥା {
        general_case:
                /* call low level op generator */
                ଯଦି (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ଅନ୍ୟଥା
                    gen_opi(op);
        }
        ଯଦି (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ଯଦି defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#ନଚେତଯଦି defined TCC_TARGET_ARM
ଶୂନ୍ୟ gen_negf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ଅନ୍ୟଥା
/* XXX: implement in gen_opf() for other backends too */
ଶୂନ୍ୟ gen_negf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ଯଦି defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ଯଦି (bt == VT_LDOUBLE)
        size = 10;
#endif
    ଯଦି (nocode_wanted) /* save_reg() wont work */
        ଯାଅ gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(size - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#endif

/* generate a floating point operation with constant propagation */
ସ୍ଥିର ଶୂନ୍ୟ gen_opif(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c1, c2, i, bt;
    SValue *v1, *v2;
#ଯଦି defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    ଅସ୍ଥିର
#endif
    long ଦ୍ୱିଗୁଣ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ଯଦି (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ଯଦି (c1 && c2) {
        ଯଦି (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ଅନ୍ୟଥା {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ଯଦି (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            ଯାଅ general_case;
        ବାଛ(op) {
        ସ୍ଥିତି '+': f1 += f2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '-': f1 -= f2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '*': f1 *= f2; ଭାଙ୍ଗ;
        ସ୍ଥିତି '/': 
            ଯଦି (f2 == 0.0) {
                ସଂଘ { ଦଶମିକ f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ଯଦି (!CONST_WANTED)
                    ଯାଅ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ଯଦି (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ଅନ୍ୟଥା
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                ଭାଙ୍ଗ;
            }
            f1 /= f2;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NEG:
            f1 = -f1;
            ଯାଅ unary_result;
        ସ୍ଥିତି TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ଫେରନ୍ତୁ;
        ସ୍ଥିତି TOK_NE:
            i = f1 != f2;
	    ଯାଅ make_int;
        ସ୍ଥିତି TOK_LT:
            i = f1 < f2;
	    ଯାଅ make_int;
        ସ୍ଥିତି TOK_GE:
            i = f1 >= f2;
	    ଯାଅ make_int;
        ସ୍ଥିତି TOK_LE:
            i = f1 <= f2;
	    ଯାଅ make_int;
        ସ୍ଥିତି TOK_GT:
            i = f1 > f2;
	    ଯାଅ make_int;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଯାଅ general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        ଯଦି (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ଅନ୍ୟଥା {
            v1->c.ld = f1;
        }
    } ଅନ୍ୟଥା {
    general_case:
        ଯଦି (op == TOK_NEG) {
            gen_negf(op);
        } ଅନ୍ୟଥା {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ସ୍ଥିର ଶୂନ୍ୟ type_to_str(ଅକ୍ଷର *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା buf_size,
                 CType *type, ଅଚଳ ଅକ୍ଷର *varstr)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt, v, t;
    Sym *s, *sa;
    ଅକ୍ଷର buf1[256];
    ଅଚଳ ଅକ୍ଷର *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ଯଦି (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    ଯଦି (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    ଯଦି (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    ଯଦି (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    ଯଦି (bt != VT_PTR) {
        ଯଦି (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        ଯଦି (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        ଯଦି (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    ଯଦି (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    ବାଛ(bt) {
    ସ୍ଥିତି VT_VOID:
        tstr = "void";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_BOOL:
        tstr = "_Bool";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_BYTE:
        tstr = "char";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_SHORT:
        tstr = "short";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_INT:
        tstr = "int";
        ଯାଅ maybe_long;
    ସ୍ଥିତି VT_LLONG:
        tstr = "long long";
    maybe_long:
        ଯଦି (t & VT_LONG)
            tstr = "long";
        ଯଦି (!IS_ENUM(t))
            ଯାଅ add_tstr;
        tstr = "enum ";
        ଯାଅ tstruct;
    ସ୍ଥିତି VT_FLOAT:
        tstr = "float";
        ଯାଅ add_tstr;
    ସ୍ଥିତି VT_DOUBLE:
        tstr = "double";
        ଯଦି (!(t & VT_LONG))
            ଯାଅ add_tstr;
    ସ୍ଥିତି VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_STRUCT:
        tstr = "struct ";
        ଯଦି (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ଯଦି (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        ଅନ୍ୟଥା
            pstrcat(buf, buf_size, get_tok_str(v, ଖାଲି));
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ଯଦି (varstr && '*' == *varstr) {
            pstrcat(buf1, ଆକାର(buf1), "(");
            pstrcat(buf1, ଆକାର(buf1), varstr);
            pstrcat(buf1, ଆକାର(buf1), ")");
        }
        pstrcat(buf1, ଆକାର(buf1), "(");
        sa = s->next;
        ଯେତେବେଳେ (sa != ଖାଲି) {
            ଅକ୍ଷର buf2[256];
            type_to_str(buf2, ଆକାର(buf2), &sa->type, ଖାଲି);
            pstrcat(buf1, ଆକାର(buf1), buf2);
            sa = sa->next;
            ଯଦି (sa)
                pstrcat(buf1, ଆକାର(buf1), ", ");
        }
        ଯଦି (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, ଆକାର(buf1), ", ...");
        pstrcat(buf1, ଆକାର(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        ଯାଅ no_var;
    ସ୍ଥିତି VT_PTR:
        s = type->ref;
        ଯଦି (t & (VT_ARRAY|VT_VLA)) {
            ଯଦି (varstr && '*' == *varstr)
                snprintf(buf1, ଆକାର(buf1), "(%s)[%d]", varstr, s->c);
            ଅନ୍ୟଥା
                snprintf(buf1, ଆକାର(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            ଯାଅ no_var;
        }
        pstrcpy(buf1, ଆକାର(buf1), "*");
        ଯଦି (t & VT_RESTRICT)
            pstrcat(buf1, ଆକାର(buf1), "restrict ");
        ଯଦି (t & VT_CONSTANT)
            pstrcat(buf1, ଆକାର(buf1), "const ");
        ଯଦି (t & VT_VOLATILE)
            pstrcat(buf1, ଆକାର(buf1), "volatile ");
        ଯଦି (varstr)
            pstrcat(buf1, ଆକାର(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        ଯାଅ no_var;
    }
    ଯଦି (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

ସ୍ଥିର ଶୂନ୍ୟ type_incompatibility_error(CType* st, CType* dt, ଅଚଳ ଅକ୍ଷର* fmt)
{
    ଅକ୍ଷର buf1[256], buf2[256];
    type_to_str(buf1, ଆକାର(buf1), st, ଖାଲି);
    type_to_str(buf2, ଆକାର(buf2), dt, ଖାଲି);
    tcc_error(fmt, buf1, buf2);
}

ସ୍ଥିର ଶୂନ୍ୟ type_incompatibility_warning(CType* st, CType* dt, ଅଚଳ ଅକ୍ଷର* fmt)
{
    ଅକ୍ଷର buf1[256], buf2[256];
    type_to_str(buf1, ଆକାର(buf1), st, ଖାଲି);
    type_to_str(buf2, ଆକାର(buf2), dt, ଖାଲି);
    tcc_warning(fmt, buf1, buf2);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pointed_size(CType *type)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align;
    ଫେରନ୍ତୁ type_size(pointed_type(type), &align);
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_null_pointer(SValue *p)
{
    ଯଦି ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ଫେରନ୍ତୁ 0;
    ଫେରନ୍ତୁ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ଯଦି (s1->f.func_call != s2->f.func_call)
        ଫେରନ୍ତୁ 0;
    ଯଦି (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ଫେରନ୍ତୁ 0;
    ପାଇଁ (;;) {
        ଯଦି (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ଫେରନ୍ତୁ 0;
        ଯଦି (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ଫେରନ୍ତୁ 1;
        s1 = s1->next;
        s2 = s2->next;
        ଯଦି (!s1)
            ଫେରନ୍ତୁ !s2;
        ଯଦି (!s2)
            ଫେରନ୍ତୁ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା compare_types(CType *type1, CType *type2, ପୂର୍ଣ୍ଣସଂଖ୍ୟା unqualified)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt1, t1, t2;

    ଯଦି (IS_ENUM(type1->t)) {
        ଯଦି (IS_ENUM(type2->t))
            ଫେରନ୍ତୁ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ଅନ୍ୟଥା ଯଦି (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ଯଦି (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ଯଦି ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ଯଦି (t1 != t2)
        ଫେରନ୍ତୁ 0;

    ଯଦି ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ଫେରନ୍ତୁ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ଯଦି (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ଯଦି (unqualified && (t1 & VT_ARRAY))
            ଫେରନ୍ତୁ compare_types(type1, type2, 1);
        ଫେରନ୍ତୁ is_compatible_types(type1, type2);
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_STRUCT) {
        ଫେରନ୍ତୁ (type1->ref == type2->ref);
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_FUNC) {
        ଫେରନ୍ତୁ is_compatible_func(type1, type2);
    } ଅନ୍ୟଥା {
        ଫେରନ୍ତୁ 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା combine_types(CType *dest, SValue *op1, SValue *op2, ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    CType *type1, *type2, type;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t1, t2, bt1, bt2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = 1;

    /* for shifts, 'combine' only left operand */
    ଯଦି (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ଖାଲି;

    ଯଦି (bt1 == VT_VOID || bt2 == VT_VOID) {
        ଯଦି (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_PTR || bt2 == VT_PTR) {
        ଯଦି (op == '+') {
          ଯଦି (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ଅନ୍ୟଥା ଯଦି (is_null_pointer (op2)) type = *type1;
        ଅନ୍ୟଥା ଯଦି (is_null_pointer (op1)) type = *type2;
        ଅନ୍ୟଥା ଯଦି (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ଯଦି ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ଅନ୍ୟଥା ଯଦି (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ଅନ୍ୟଥା {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା pbt1 = pt1->t & VT_BTYPE;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା pbt2 = pt2->t & VT_BTYPE;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା newquals, copied = 0;
            ଯଦି (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ଯଦି (op != '?' && op != CMP_OP)
                  ret = 0;
                ଅନ୍ୟଥା
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ଯଦି (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ଯଦି ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ଠେଲ(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ଯଦି (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ଯଦି (!copied)
                      type.ref = sym_ଠେଲ(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ଠେଲ(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ଯଦି (op == CMP_OP)
          type.t = VT_SIZE_T;
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ଯଦି (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ଅନ୍ୟଥା ଯଦି (is_float(bt1) || is_float(bt2)) {
        ଯଦି (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ଅନ୍ୟଥା ଯଦି (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ଅନ୍ୟଥା {
            type.t = VT_FLOAT;
        }
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ଯଦି (bt1 == VT_LLONG)
          type.t &= t1;
        ଯଦି (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ଯଦି ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ଅନ୍ୟଥା {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ଯଦି (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ଯଦି (dest)
      *dest = type;
    ଫେରନ୍ତୁ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC ଶୂନ୍ୟ gen_op(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t1, t2, bt1, bt2, t;
    CType type1, combtype;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op_class = op;

    ଯଦି (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    ଅନ୍ୟଥା ଯଦି (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ଯଦି (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ଯଦି (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	ଯଦି (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	ଯାଅ redo;
    } ଅନ୍ୟଥା ଯଦି (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ଅନ୍ୟଥା ଯଦି (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା align;
        ଯଦି (op_class == CMP_OP)
            ଯାଅ std_op;
        /* if both pointers, then it must be the '-' op */
        ଯଦି (bt1 == VT_PTR && bt2 == VT_PTR) {
            ଯଦି (op != '-')
                ଯାଅ op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ଅନ୍ୟଥା {
            /* exactly one pointer : must be '+' or '-'. */
            ଯଦି (op != '-' && op != '+')
                ଯାଅ op_err;
            /* Put pointer as first operand */
            ଯଦି (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ଯଦି PTR_SIZE == 4
            ଯଦି (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            ଯଦି (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ଯଦି (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } ଅନ୍ୟଥା
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ଅନ୍ୟଥା {
        /* floats can only be used for a few operations */
        ଯଦି (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            ଯାଅ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ଯଦି (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ଯଦି (t & VT_UNSIGNED) {
            ଯଦି (op == TOK_SAR)
                op = TOK_SHR;
            ଅନ୍ୟଥା ଯଦି (op == '/')
                op = TOK_UDIV;
            ଅନ୍ୟଥା ଯଦି (op == '%')
                op = TOK_UMOD;
            ଅନ୍ୟଥା ଯଦି (op == TOK_LT)
                op = TOK_ULT;
            ଅନ୍ୟଥା ଯଦି (op == TOK_GT)
                op = TOK_UGT;
            ଅନ୍ୟଥା ଯଦି (op == TOK_LE)
                op = TOK_ULE;
            ଅନ୍ୟଥା ଯଦି (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ଯଦି (is_float(t))
            gen_opif(op);
        ଅନ୍ୟଥା
            gen_opic(op);
        ଯଦି (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ଅନ୍ୟଥା {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ଯଦି (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ଯଦି defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#ଅନ୍ୟଥା
/* generic itof for unsigned long long case */
ସ୍ଥିର ଶୂନ୍ୟ gen_cvt_itof1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ଯଦି ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ଯଦି (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ଯଦି LDOUBLE_SIZE != 8
        ଅନ୍ୟଥା ଯଦି (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        ଅନ୍ୟଥା
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ଅନ୍ୟଥା {
        gen_cvt_itof(t);
    }
}
#endif

#ଯଦି defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#ଅନ୍ୟଥା
/* generic ftoi for unsigned long long case */
ସ୍ଥିର ଶୂନ୍ୟ gen_cvt_ftoi1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା st;
    ଯଦି (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ଯଦି (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ଯଦି LDOUBLE_SIZE != 8
        ଅନ୍ୟଥା ଯଦି (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        ଅନ୍ୟଥା
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ଅନ୍ୟଥା {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
ସ୍ଥିର ଶୂନ୍ୟ force_charshort_cast(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ସ୍ଥିର ଶୂନ୍ୟ gen_cast_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    CType type;
    type.t = t;
    type.ref = ଖାଲି;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ସ୍ଥିର ଶୂନ୍ୟ gen_cast(CType *type)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sbt, dbt, sf, df, c;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    ଯଦି (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ଯଦି (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ଯଦି (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ଯଦି (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ଯଦି (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ଯଦି (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            ଯାଅ done;
        }
        ଯଦି (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ଯଦି (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ଯଦି (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ଅନ୍ୟଥା ଯଦି (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ଯଦି (df) {
                ଯଦି (sbt_bt == VT_LLONG) {
                    ଯଦି ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ଅନ୍ୟଥା
                        vtop->c.ld = -(long ଦ୍ୱିଗୁଣ)-vtop->c.i;
                } ଅନ୍ୟଥା ଯଦି(!sf) {
                    ଯଦି ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ଅନ୍ୟଥା
                        vtop->c.ld = -(long ଦ୍ୱିଗୁଣ)-(uint32_t)vtop->c.i;
                }

                ଯଦି (dbt == VT_FLOAT)
                    vtop->c.f = (ଦଶମିକ)vtop->c.ld;
                ଅନ୍ୟଥା ଯଦି (dbt == VT_DOUBLE)
                    vtop->c.d = (ଦ୍ୱିଗୁଣ)vtop->c.ld;
            } ଅନ୍ୟଥା ଯଦି (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ଅନ୍ୟଥା {
                ଯଦି(sf) {
                    ଯଦି (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ଅନ୍ୟଥା
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ଅନ୍ୟଥା ଯଦି (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                ଅନ୍ୟଥା ଯଦି (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ଅନ୍ୟଥା
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ଯଦି (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                ଅନ୍ୟଥା ଯଦି (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ଅନ୍ୟଥା {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ଯଦି (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            ଯାଅ done;

        } ଅନ୍ୟଥା ଯଦି (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            ଯାଅ done;
        }

        /* cannot generate code for global or static initializers */
        ଯଦି (nocode_wanted & DATA_ONLY_WANTED) {
            ଯଦି (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            ଯାଅ done;
        }

        /* non constant case: generate code */
        ଯଦି (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            ଯାଅ done;
        }

        ଯଦି (sf || df) {
            ଯଦି (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ଅନ୍ୟଥା ଯଦି (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ଅନ୍ୟଥା {
                /* convert fp to int */
                sbt = dbt;
                ଯଦି (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                ଯାଅ again; /* may need char/short cast */
            }
            ଯାଅ done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        ଯଦି (ds == 0 || ss == 0)
            ଯାଅ error;

        /* same size and no sign conversion needed */
        ଯଦି (ds == ss && ds >= 4)
            ଯାଅ done;
        ଯଦି (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ଯଦି (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        ଯଦି (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ଯଦି (ds <= ss)
                ଯାଅ done;
            /* ss <= 4 here */
            ଯଦି (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                ଯାଅ done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ଯଦି PTR_SIZE == 4
        ଯଦି (ds == 8) {
            /* generate high word */
            ଯଦି (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ଅନ୍ୟଥା {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ଅନ୍ୟଥା ଯଦି (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#ନଚେତଯଦି PTR_SIZE == 8
        ଯଦି (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ଯଦି (sbt & VT_UNSIGNED) {
#ଯଦି defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ଅନ୍ୟଥା
                ଯାଅ done;
#endif
            } ଅନ୍ୟଥା {
                gen_cvt_sxtw();
                ଯାଅ done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ଅନ୍ୟଥା ଯଦି (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ଯଦି !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } ଅନ୍ୟଥା {
            ss = 4;
        }
#endif

        ଯଦି (ds >= ss)
            ଯାଅ done;
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ଯଦି (ss == 4) {
        gen_cvt_csti(dbt);
        ଯାଅ done;
    }
#endif
        bits = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(bits);
        gen_op(TOK_SHL);
        vpushi(bits - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
done:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା type_size(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *a)
{
    Sym *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt;

    bt = type->t & VT_BTYPE;
    ଯଦି (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ଫେରନ୍ତୁ s->c;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_PTR) {
        ଯଦି (type->t & VT_ARRAY) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            ଯଦି (s->c < 0)
                ଫେରନ୍ତୁ s->c;
            ଫେରନ୍ତୁ ts * s->c;
        } ଅନ୍ୟଥା {
            *a = PTR_SIZE;
            ଫେରନ୍ତୁ PTR_SIZE;
        }
    } ଅନ୍ୟଥା ଯଦି (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ଫେରନ୍ତୁ -1; /* incomplete enum */
    } ଅନ୍ୟଥା ଯଦି (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ଫେରନ୍ତୁ LDOUBLE_SIZE;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_DOUBLE || bt == VT_LLONG) {
#ଯଦି (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ଅନ୍ୟଥା
        *a = 8;
#endif
        ଫେରନ୍ତୁ 8;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ଫେରନ୍ତୁ 4;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_SHORT) {
        *a = 2;
        ଫେରନ୍ତୁ 2;
    } ଅନ୍ୟଥା ଯଦି (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ଫେରନ୍ତୁ 16;
    } ଅନ୍ୟଥା {
        /* char, void, function, _Bool */
        *a = 1;
        ଫେରନ୍ତୁ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ସ୍ଥିର ଶୂନ୍ୟ vpush_type_size(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *a)
{
    ଯଦି (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ଅନ୍ୟଥା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା size = type_size(type, a);
        ଯଦି (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ CType *pointed_type(CType *type)
{
    ଫେରନ୍ତୁ &type->ref->type;
}

ସ୍ଥିର ଶୂନ୍ୟ check_restrict_type(CType *type)
{
    ଯେତେବେଳେ ((type->t & VT_BTYPE) == VT_PTR) {
        ଯଦି ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ଯଦି (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା type_qualifiers(CType *type)
{
    ଯେତେବେଳେ (type->t & VT_ARRAY)
        type = pointed_type(type);
    ଫେରନ୍ତୁ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC ଶୂନ୍ୟ mk_pointer(CType *type)
{
    Sym *s;
    s = sym_ଠେଲ(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_compatible_types(CType *type1, CType *type2)
{
    ଫେରନ୍ତୁ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ଫେରନ୍ତୁ compare_types(type1,type2,1);
}

ସ୍ଥିର ଶୂନ୍ୟ cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ସ୍ଥିର ଶୂନ୍ୟ verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ଯଦି (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    ବାଛ(dbt) {
    ସ୍ଥିତି VT_VOID:
        ଯଦି (sbt != dbt)
            tcc_error("assignment to void expression");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ଯଦି (is_null_pointer(vtop))
            ଭାଙ୍ଗ;
        /* accept implicit pointer to integer cast with warning */
        ଯଦି (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            ଭାଙ୍ଗ;
        }
        type1 = pointed_type(dt);
        ଯଦି (sbt == VT_PTR)
            type2 = pointed_type(st);
        ଅନ୍ୟଥା ଯଦି (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ଅନ୍ୟଥା
            ଯାଅ error;
        ଯଦି (is_compatible_types(type1, type2))
            ଭାଙ୍ଗ;
        ପାଇଁ (qualwarn = lvl = 0;; ++lvl) {
            ଯଦି ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ଯଦି (dbt != VT_PTR || sbt != VT_PTR)
                ଭାଙ୍ଗ;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ଯଦି (!is_compatible_unqualified_types(type1, type2)) {
            ଯଦି ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ଅନ୍ୟଥା ଯଦି (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ଅନ୍ୟଥା {
                tcc_warning("assignment from incompatible pointer type");
                ଭାଙ୍ଗ;
            }
        }
        ଯଦି (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_BYTE:
    ସ୍ଥିତି VT_SHORT:
    ସ୍ଥିତି VT_INT:
    ସ୍ଥିତି VT_LLONG:
        ଯଦି (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ଅନ୍ୟଥା ଯଦି (sbt == VT_STRUCT) {
            ଯାଅ case_VT_STRUCT;
        }
        /* XXX: more tests */
        ଭାଙ୍ଗ;
    ସ୍ଥିତି VT_STRUCT:
    case_VT_STRUCT:
        ଯଦି (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        ଭାଙ୍ଗ;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC ଶୂନ୍ୟ vstore(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    ଯଦି (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        ଯଦି (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } ଅନ୍ୟଥା
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            ଯଦି(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ଅନ୍ୟଥା ଯଦି(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ଅନ୍ୟଥା
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ଅନ୍ୟଥା ଯଦି (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        ଯଦି (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        ଯଦି (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ଯଦି (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } ଅନ୍ୟଥା {
            unsigned long long mask = (1ULL << bit_size) - 1;
            ଯଦି (dbt != VT_BOOL) {
                /* mask source */
                ଯଦି (dbt == VT_LLONG)
                    vpushll(mask);
                ଅନ୍ୟଥା
                    vpushi((unsigned)mask);
                gen_op('&');
            }
            /* shift source */
            vpushi(bit_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            ଯଦି (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            ଅନ୍ୟଥା
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ଅନ୍ୟଥା ଯଦି (dbt == VT_VOID) {
        --vtop;
    } ଅନ୍ୟଥା {
            /* optimize char/short casts */
            delayed_cast = 0;
            ଯଦି ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ଯଦି ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ଅନ୍ୟଥା {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            ଯଦି (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            ଯଦି (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ଯଦି ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ଖାଲି;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ଯଦି (USING_TWO_ଶବ୍ଦଗୁଡ଼ିକ(dbt)) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ଅନ୍ୟଥା {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC ଶୂନ୍ୟ inc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା post, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ଯଦି (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ଯଦି (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
    /* read the string */
    ଯଦି (tok != TOK_STR)
        expect(ସନ୍ଦେଶ);
    cstr_reset(&initstr);
    ଯେତେବେଳେ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    ଫେରନ୍ତୁ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା exact_log2p1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
  ଯଦି (!i)
    ଫେରନ୍ତୁ 0;
  ପାଇଁ (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ଯଦି (i >= 1 << 4)
    ret += 4, i >>= 4;
  ଯଦି (i >= 1 << 2)
    ret += 2, i >>= 2;
  ଯଦି (i >= 1 << 1)
    ret++;
  ଫେରନ୍ତୁ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ସ୍ଥିର ଶୂନ୍ୟ parse_attribute(AttributeDef *ad)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, n;
    ଅକ୍ଷର *astr;
    AttributeDef ad_tmp;
    
redo:
    ଯଦି (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ଫେରନ୍ତୁ;
    ଯଦି (ଖାଲି == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    ଯେତେବେଳେ (tok != ')') {
        ଯଦି (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        ବାଛ(t) {
	ସ୍ଥିତି TOK_CLEANUP1:
	ସ୍ଥିତି TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    ଯଦି (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ଅନ୍ୟଥା ଯଦି ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    ଭାଙ୍ଗ;
	}
        ସ୍ଥିତି TOK_CONSTRUCTOR1:
        ସ୍ଥିତି TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_DESTRUCTOR1:
        ସ୍ଥିତି TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ALWAYS_INLINE1:
        ସ୍ଥିତି TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SECTION1:
        ସ୍ଥିତି TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ALIAS1:
        ସ୍ଥିତି TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_VISIBILITY1:
	ସ୍ଥିତି TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    ଯଦି (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ଅନ୍ୟଥା ଯଦି (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ଅନ୍ୟଥା ଯଦି (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    ଅନ୍ୟଥା ଯଦି (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ଅନ୍ୟଥା
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ALIGNED1:
        ସ୍ଥିତି TOK_ALIGNED2:
            ଯଦି (tok == '(') {
                next();
                n = ପଦସମଷ୍ଟି_const();
                ଯଦି (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ଅନ୍ୟଥା {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ଯଦି (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_PACKED1:
        ସ୍ଥିତି TOK_PACKED2:
            ad->a.packed = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_WEAK1:
        ସ୍ଥିତି TOK_WEAK2:
            ad->a.weak = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NODEBUG1:
        ସ୍ଥିତି TOK_NODEBUG2:
            ad->a.nodebug = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_USED1:
        ସ୍ଥିତି TOK_USED2:
        ସ୍ଥିତି TOK_UNUSED1:
        ସ୍ଥିତି TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_CONST1:
        ସ୍ଥିତି TOK_CONST2:
        ସ୍ଥିତି TOK_CONST3:
        ସ୍ଥିତି TOK_PURE1:
        ସ୍ଥିତି TOK_PURE2:
	    /* ignored */
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NOINLINE:
	    /* ignored */
	    ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_FORMAT1:
        ସ୍ଥିତି TOK_FORMAT2:
	    /* ignored */
            ଯାଅ skip_param;
        ସ୍ଥିତି TOK_NORETURN1:
        ସ୍ଥିତି TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_CDECL1:
        ସ୍ଥିତି TOK_CDECL2:
        ସ୍ଥିତି TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_STDCALL1:
        ସ୍ଥିତି TOK_STDCALL2:
        ସ୍ଥିତି TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            ଭାଙ୍ଗ;
#ifdef TCC_TARGET_I386
        ସ୍ଥିତି TOK_REGPARM1:
        ସ୍ଥିତି TOK_REGPARM2:
            skip('(');
            n = ପଦସମଷ୍ଟି_const();
            ଯଦି (n > 3) 
                n = 3;
            ଅନ୍ୟଥା ଯଦି (n < 0)
                n = 0;
            ଯଦି (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_FASTCALL1:
        ସ୍ଥିତି TOK_FASTCALL2:
        ସ୍ଥିତି TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_THISCALL1:
        ସ୍ଥିତି TOK_THISCALL2:
        ସ୍ଥିତି TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            ଭାଙ୍ଗ;
#endif
        ସ୍ଥିତି TOK_MODE:
            skip('(');
            ବାଛ(tok) {
                ସ୍ଥିତି TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    ଭାଙ୍ଗ;
                ସ୍ଥିତି TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    ଭାଙ୍ଗ;
                ସ୍ଥିତି TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    ଭାଙ୍ଗ;
                ସ୍ଥିତି TOK_MODE_SI:
                ସ୍ଥିତି TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    ଭାଙ୍ଗ;
                ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ଖାଲି));
                    ଭାଙ୍ଗ;
            }
            next();
            skip(')');
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NODECORATE:
            ad->a.nodecorate = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ଖାଲି));
            /* skip parameters */
skip_param:
            ଯଦି (tok == '(') {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା parenthesis = 0;
                କର {
                    ଯଦି (tok == '(') 
                        parenthesis++;
                    ଅନ୍ୟଥା ଯଦି (tok == ')') 
                        parenthesis--;
                    next();
                } ଯେତେବେଳେ (parenthesis && tok != -1);
            }
            ଭାଙ୍ଗ;
        }
        ଯଦି (tok != ',')
            ଭାଙ୍ଗ;
        next();
    }
    skip(')');
    skip(')');
    ଯାଅ redo;
}

ସ୍ଥିର Sym * find_field (CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *cumofs)
{
    Sym *s = type->ref;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v1 = v | SYM_FIELD;
    ଯଦି (!(v & SYM_FIELD)) { /* top-level call */
        ଯଦି ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ଯଦି (v < TOK_UIDENT)
            expect("field name");
        ଯଦି (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ଯେତେବେଳେ ((s = s->next) != ଖାଲି) {
        ଯଦି (s->v == v1) {
            *cumofs = s->c;
            ଫେରନ୍ତୁ s;
        }
        ଯଦି ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            ଯଦି (ret) {
                *cumofs += s->c;
                ଫେରନ୍ତୁ ret;
            }
        }
    }
    ଯଦି (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, ଖାଲି));
    ଫେରନ୍ତୁ s;
}

ସ୍ଥିର ଶୂନ୍ୟ check_fields (CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା check)
{
    Sym *s = type->ref;

    ଯେତେବେଳେ ((s = s->next) != ଖାଲି) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = s->v & ~SYM_FIELD;
        ଯଦି (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            ଯଦି (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, ଖାଲି));
            ts->tok ^= SYM_FIELD;
        } ଅନ୍ୟଥା ଯଦି ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ struct_layout(CType *type, AttributeDef *ad)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, maxalign, offset, c, bit_pos, bit_size;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା packed, a, bt, prevbt, prev_bit_size;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pcc = !tcc_state->ms_bitfields;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pragma_pack = *tcc_state->pack_ଗଦା_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    ପାଇଁ (f = type->ref->next; f; f = f->next) {
        ଯଦି (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        ଅନ୍ୟଥା
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ଯଦି (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ଅନ୍ୟଥା {
            /* in pcc mode, attribute packed overrides if set. */
            ଯଦି (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ଯଦି (pragma_pack) {
                packed = 1;
                ଯଦି (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ଯଦି (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ଯଦି (a)
            align = a;

        ଯଦି (type->ref->type.t == VT_UNION) {
	    ଯଦି (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    ଯଦି (size > c)
	        c = size;

	} ଅନ୍ୟଥା ଯଦି (bit_size < 0) {
            ଯଦି (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    ଯଦି (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} ଅନ୍ୟଥା {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ଯଦି (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ଯଦି (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } ଅନ୍ୟଥା ଯଦି (f->a.aligned) {
                    ଯାଅ new_field;
                } ଅନ୍ୟଥା ଯଦି (!packed) {
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a8 = align * 8;
	            ପୂର୍ଣ୍ଣସଂଖ୍ୟା ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    ଯଦି (ofs > size / align)
                        ଯାଅ new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ଯଦି (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                ଯେତେବେଳେ (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ଯଦି (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ଅନ୍ୟଥା {
		bt = f->type.t & VT_BTYPE;
		ଯଦି ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ଯଦି (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ଯଦି (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	ଯଦି (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, ଖାଲି), offset, size, align);
	ଯଦି (f->type.t & VT_BITFIELD) {
	    printf(" pos %-2d bits %-2d",
                    BIT_POS(f->type.t),
                    BIT_SIZE(f->type.t)
                    );
	}
	printf("\n");
#endif

        f->c = offset;
	f->r = 0;
    }

    ଯଦି (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ଯଦି (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ଯଦି (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ଯଦି (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    ପାଇଁ (f = type->ref->next; f; f = f->next) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, px, cx, c0;
        CType t;

        ଯଦି (0 == (f->type.t & VT_BITFIELD))
            ଜାରି;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        ଯଦି (bit_size == 0)
            ଜାରି;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        ଯଦି (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            ଜାରି;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        ପାଇଁ (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ଯଦି (c0 == cx)
                ଭାଙ୍ଗ;
            s = (px + bit_size + 7) >> 3;
            ଯଦି (s > 4) {
                t.t = VT_LLONG;
            } ଅନ୍ୟଥା ଯଦି (s > 2) {
                t.t = VT_INT;
            } ଅନ୍ୟଥା ଯଦି (s > 1) {
                t.t = VT_SHORT;
            } ଅନ୍ୟଥା {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        ଯଦି (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            ଯଦି (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, ଖାଲି),
                cx, s, align, px, bit_size);
#endif
        } ଅନ୍ୟଥା {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, ଖାଲି));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା in_range(long long n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    ଯଦି (t & VT_UNSIGNED)
        ଫେରନ୍ତୁ n <= (m << 1) + 1;
    ଫେରନ୍ତୁ n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ସ୍ଥିର ଶୂନ୍ୟ struct_decl(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା u)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, c, size, align, flexible;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, ଆକାର ad);
    next();
    parse_attribute(&ad);

    v = 0;
    ଯଦି (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    ଯଦି (u == VT_ENUM) {
        ut = VT_INT;
        ଯଦି (tok == ':') { /* C2x enum : <type> ... */
            next();
            ଯଦି (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ଯଦି (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        ଯଦି (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ଯଦି (u == s->type.t)
                ଯାଅ do_decl;
            ଯଦି (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                ଯାଅ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ଖାଲି));
        }
    } ଅନ୍ୟଥା {
        ଯଦି (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ଖାଲି;
    /* we put an undefined size for struct/union */
    s = sym_ଠେଲ(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ଯଦି (tok == '{') {
        next();
        ଯଦି (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        ଯଦି (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ଯଦି (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            ପାଇଁ(;;) {
                v = tok;
                ଯଦି (v < TOK_UIDENT)
                    expect("identifier");
                next();
                ଯଦି (tok == '=') {
                    next();
		    ll = ପଦସମଷ୍ଟି_const64();
                }
                ଯଦି (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ଖାଲି));
                ss = sym_ଠେଲ(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                ଯଦି (ll < nl)
                    nl = ll;
                ଯଦି (ll > pl)
                    pl = ll;
                ଯଦି (tok != ',')
                    ଭାଙ୍ଗ;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                ଯଦି (tok == '}')
                    ଭାଙ୍ଗ;
            }
            skip('}');

            ଯଦି (bt) {
                t.t = bt;
                s->c = 2;
                ଯାଅ enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ଯଦି (nl >= 0) {
                ଯଦି (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ଅନ୍ୟଥା ଯଦି (pl != (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)pl || nl != (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            ପାଇଁ (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                ଯଦି (ll == (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)ll) /* default is int if it fits */
                    ଜାରି;
                ଯଦି (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ଯଦି (ll == (unsigned)ll)
                        ଜାରି;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } ଅନ୍ୟଥା {
            c = 0;
            flexible = 0;
            ଯେତେବେଳେ (tok != '}') {
                ଯଦି (!parse_btype(&btype, &ad1, 0)) {
                    ଯଦି (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ଜାରି;
                    }
		    skip(';');
		    ଜାରି;
		}
                ଯେତେବେଳେ (1) {
		    ଯଦି (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ଖାଲି));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    ଯଦି (tok != ':') {
			ଯଦି (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        ଯଦି (v == 0) {
                    	    ଯଦି ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ଅନ୍ୟଥା {
				ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = btype.ref->v;
				ଯଦି ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    ଯଦି (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ଯଦି (type_size(&type1, &align) < 0) {
			    ଯଦି ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ଅନ୍ୟଥା
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ଖାଲି));
                        }
                        ଯଦି ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ଖାଲି));
                    }
                    ଯଦି (tok == ':') {
                        next();
                        bit_size = ପଦସମଷ୍ଟି_const();
                        /* XXX: handle v = 0 case for messages */
                        ଯଦି (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ଖାଲି));
                        ଯଦି (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ଖାଲି));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    ଯଦି (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ଯଦି (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        ଯଦି (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ଖାଲି));
                        } ଅନ୍ୟଥା ଯଦି (bit_size == bsize
				    && !*tcc_state->pack_ଗଦା_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ଅନ୍ୟଥା ଯଦି (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } ଅନ୍ୟଥା {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    ଯଦି (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ଯଦି (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    ଯଦି (v) {
                        ss = sym_ଠେଲ(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    ଯଦି (tok == ';' || tok == TOK_EOF)
                        ଭାଙ୍ଗ;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ଯଦି (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ଯଦି (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ସ୍ଥିର ଶୂନ୍ୟ parse_btype_qualify(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା qualifiers)
{
    ଯେତେବେଳେ (type->t & VT_ARRAY) {
        type->ref = sym_ଠେଲ(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ଯଦି (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_btype(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ignore_label)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, ଆକାର(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ଖାଲି;

    ଯେତେବେଳେ(1) {
        ବାଛ(tok) {
        ସ୍ଥିତି TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            ଜାରି;

            /* basic types */
        ସ୍ଥିତି TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            ଯଦି (u == VT_SHORT || u == VT_LONG) {
                ଯଦି (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ଅନ୍ୟଥା {
                ଯଦି (bt != -1 || (st != -1 && u != VT_INT))
                    ଯାଅ tmbt;
                ଯଦି ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    ଯାଅ tmbt;
                bt = u;
            }
            ଯଦି (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_VOID:
            u = VT_VOID;
            ଯାଅ basic_type;
        ସ୍ଥିତି TOK_SHORT:
            u = VT_SHORT;
            ଯାଅ basic_type;
        ସ୍ଥିତି TOK_INT:
            u = VT_INT;
            ଯାଅ basic_type;
        ସ୍ଥିତି TOK_ALIGNAS:
            { ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, ଆକାର(AttributeDef));
              ଯଦି (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ଯଦି (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ଅନ୍ୟଥା
                    type_size(&type1, &n);
              } ଅନ୍ୟଥା {
                  n = ପଦସମଷ୍ଟି_const();
                  ଯଦି (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ଜାରି;
        ସ୍ଥିତି TOK_LONG:
            ଯଦି ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ଅନ୍ୟଥା ଯଦି ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ଅନ୍ୟଥା {
                u = VT_LONG;
                ଯାଅ basic_type;
            }
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_BOOL:
            u = VT_BOOL;
            ଯାଅ basic_type;
        ସ୍ଥିତି TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        ସ୍ଥିତି TOK_FLOAT:
            u = VT_FLOAT;
            ଯାଅ basic_type;
        ସ୍ଥିତି TOK_DOUBLE:
            ଯଦି ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ଅନ୍ୟଥା {
                u = VT_DOUBLE;
                ଯାଅ basic_type;
            }
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            ଯାଅ basic_type1;
        ସ୍ଥିତି TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            ଯାଅ basic_type2;
        ସ୍ଥିତି TOK_UNION:
            struct_decl(&type1, VT_UNION);
            ଯାଅ basic_type2;

            /* type modifiers */
        ସ୍ଥିତି TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ଯଦି (tok == '(') {
                parse_ପଦସମଷ୍ଟି_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ଯଦି (type1.ref)
                    sym_to_attr(ad, type1.ref);
                ଯାଅ basic_type2;
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_CONST1:
        ସ୍ଥିତି TOK_CONST2:
        ସ୍ଥିତି TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_VOLATILE1:
        ସ୍ଥିତି TOK_VOLATILE2:
        ସ୍ଥିତି TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SIGNED1:
        ସ୍ଥିତି TOK_SIGNED2:
        ସ୍ଥିତି TOK_SIGNED3:
            ଯଦି ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_RESTRICT1:
        ସ୍ଥିତି TOK_RESTRICT2:
        ସ୍ଥିତି TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_REGISTER:
        ସ୍ଥିତି TOK_AUTO:
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_UNSIGNED:
            ଯଦି ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            ଭାଙ୍ଗ;

            /* storage */
        ସ୍ଥିତି TOK_EXTERN:
            g = VT_EXTERN;
            ଯାଅ storage;
        ସ୍ଥିତି TOK_STATIC:
            g = VT_STATIC;
            ଯାଅ storage;
        ସ୍ଥିତି TOK_TYPEDEF:
            g = VT_TYPEDEF;
            ଯାଅ storage;
       storage:
            ଯଦି (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_INLINE1:
        ସ୍ଥିତି TOK_INLINE2:
        ସ୍ଥିତି TOK_INLINE3:
            t |= VT_INLINE;
            next();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            ଭାଙ୍ଗ;
            /* GNUC attribute */
        ସ୍ଥିତି TOK_ATTRIBUTE1:
        ସ୍ଥିତି TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ଯଦି (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ଜାରି;
            /* GNUC typeof */
        ସ୍ଥିତି TOK_TYPEOF1:
        ସ୍ଥିତି TOK_TYPEOF2:
        ସ୍ଥିତି TOK_TYPEOF3:
            next();
            parse_ପଦସମଷ୍ଟି_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ଯଦି (type1.ref) {
                sym_to_attr(ad, type1.ref);
                ଯଦି (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            ଯାଅ basic_type2;
        ସ୍ଥିତି TOK_THREAD_LOCAL:
        ସ୍ଥିତି TOK___thread:
            ଯଦି (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଯଦି (typespec_found)
                ଯାଅ the_end;
            s = sym_find(tok);
            ଯଦି (!s || !(s->type.t & VT_TYPEDEF))
                ଯାଅ the_end;

            n = tok, next();
            ଯଦି (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                ଯାଅ the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ଯଦି (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ଯଦି (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            ଭାଙ୍ଗ;
        }
        type_found = 1;
    }
the_end:
    ଯଦି (tcc_state->char_is_unsigned) {
        ଯଦି ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ଯଦି (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    ଯଦି (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    ଫେରନ୍ତୁ type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ଯଦି ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(ଶୂନ୍ୟ)
{
    skip('(');
    ଫେରନ୍ତୁ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_label_instr(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
    ଅକ୍ଷର *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    ଫେରନ୍ତୁ v;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା post_type(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା storage, ପୂର୍ଣ୍ଣସଂଖ୍ୟା td)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *vla_array_str = ଖାଲି;

    ଯଦି (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	ଯଦି (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  ଫେରନ୍ତୁ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ଗଦା ? &local_ଗଦା : &global_ଗଦା;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	ଯଦି (tok == ')')
	  l = 0;
	ଅନ୍ୟଥା ଯଦି (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ଅନ୍ୟଥା ଯଦି (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_କାଢ଼(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    ଫେରନ୍ତୁ 0;
	} ଅନ୍ୟଥା
	  l = FUNC_OLD;

        first = ଖାଲି;
        plast = &first;
        arg_size = 0;
        ଯଦି (l) {
            ପାଇଁ(;;) {
                /* read param name and compute offset */
                ଯଦି (l != FUNC_OLD) {
                    ଯଦି ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        ଭାଙ୍ଗ;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    ଯଦି ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ଯଦି (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } ଅନ୍ୟଥା {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ଖାଲି;
                    next();
                }
                ଯଦି (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ଠେଲ(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                ଯଦି (tok == ')')
                    ଭାଙ୍ଗ;
                skip(',');
                ଯଦି (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    ଭାଙ୍ଗ;
                }
		ଯଦି (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ଅନ୍ୟଥା
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ଯଦି (tok == '[') {
            next();
            skip(']'); /* only handle simple "[]" */
            mk_pointer(type);
        }
        ad->f.func_args = arg_size;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->next = first;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_କାଢ଼(ps, sr, 1);
        --local_scope;

    } ଅନ୍ୟଥା ଯଦି (tok == '[') {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_nocode_wanted = nocode_wanted;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        ଯଦି (td & TYPE_PARAM) ଯେତେବେଳେ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    ବାଛ (tok) {
	    ସ୍ଥିତି TOK_CONST1: ସ୍ଥିତି TOK_CONST2: ସ୍ଥିତି TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		ଜାରି;
	    ସ୍ଥିତି TOK_VOLATILE1: ସ୍ଥିତି TOK_VOLATILE2: ସ୍ଥିତି TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		ଜାରି;
	    ସ୍ଥିତି TOK_RESTRICT1: ସ୍ଥିତି TOK_RESTRICT2: ସ୍ଥିତି TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		ଜାରି;
	    ସ୍ଥିତି TOK_STATIC:
	    ସ୍ଥିତି '*':
		next();
		ଜାରି;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		ଭାଙ୍ଗ;
	    }
            ଯଦି (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_block(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		next();
	        gexpr();
		end_macro();
		next();
		ଯାଅ check;
            }
            ଭାଙ୍ଗ;

	} ଅନ୍ୟଥା ଯଦି (tok != ']') {
            ଯଦି (!local_ଗଦା || (storage & VT_STATIC))
                vpushi(ପଦସମଷ୍ଟି_const());
            ଅନ୍ୟଥା {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ଯଦି (n < 0)
                    tcc_error("invalid array size");
            } ଅନ୍ୟଥା {
                ଯଦି (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        ଯଦି ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ଯଦି ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ଯଦି (t1 & VT_VLA) {
            ଯଦି (n < 0) {
		ଯଦି  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ଅନ୍ୟଥା {
                loc -= type_size(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_size(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        ଯଦି (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ଠେଲ(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ଯଦି (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ଯଦି ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ଅନ୍ୟଥା
	        tok_str_free_str(vla_array_str);
	}
    }
    ଫେରନ୍ତୁ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ସ୍ଥିର CType *type_decl(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା td)
{
    CType *post, *ret;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ଯେତେବେଳେ (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        ବାଛ(tok) {
        ସ୍ଥିତି TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            ଯାଅ redo;
        ସ୍ଥିତି TOK_CONST1:
        ସ୍ଥିତି TOK_CONST2:
        ସ୍ଥିତି TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            ଯାଅ redo;
        ସ୍ଥିତି TOK_VOLATILE1:
        ସ୍ଥିତି TOK_VOLATILE2:
        ସ୍ଥିତି TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            ଯାଅ redo;
        ସ୍ଥିତି TOK_RESTRICT1:
        ସ୍ଥିତି TOK_RESTRICT2:
        ସ୍ଥିତି TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            ଯାଅ redo;
	/* XXX: clarify attribute handling */
	ସ୍ଥିତି TOK_ATTRIBUTE1:
	ସ୍ଥିତି TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    ଭାଙ୍ଗ;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	ଯଦି (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ଯଦି (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ଯଦି (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ଅନ୍ୟଥା
	  ଯାଅ abstract;
    } ଅନ୍ୟଥା ଯଦି (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } ଅନ୍ୟଥା {
  abstract:
	ଯଦି (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ଫେରନ୍ତୁ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC ଶୂନ୍ୟ indir(ଶୂନ୍ୟ)
{
    ଯଦି ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ଫେରନ୍ତୁ;
        expect("pointer");
    }
    ଯଦି (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ଯଦି (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
ସ୍ଥିର ଶୂନ୍ୟ gfunc_param_typed(Sym *func, Sym *arg)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_type;
    CType type;

    func_type = func->f.func_type;
    ଯଦି (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ଖାଲି)) {
        /* default casting : only need to convert float to double */
        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ଅନ୍ୟଥା ଯଦି (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ଅନ୍ୟଥା ଯଦି (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ଅନ୍ୟଥା ଯଦି (arg == ଖାଲି) {
        tcc_error("too many arguments to function");
    } ଅନ୍ୟଥା {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_type(CType *type, ଶୂନ୍ୟ (*ପଦସମଷ୍ଟି_fn)(ଶୂନ୍ୟ))
{
    nocode_wanted++;
    ପଦସମଷ୍ଟି_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ସ୍ଥିର ଶୂନ୍ୟ parse_ପଦସମଷ୍ଟି_type(CType *type)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
    AttributeDef ad;

    skip('(');
    ଯଦି (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ଅନ୍ୟଥା {
        ପଦସମଷ୍ଟି_type(type, gexpr);
    }
    skip(')');
}

ସ୍ଥିର ଶୂନ୍ୟ parse_type(CType *type)
{
    AttributeDef ad;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;

    ଯଦି (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ସ୍ଥିର ଶୂନ୍ୟ parse_builtin_params(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nc, ଅଚଳ ଅକ୍ଷର *args)
{
    ଅକ୍ଷର c, sep = '(';
    CType type;
    ଯଦି (nc)
        nocode_wanted++;
    next();
    ଯଦି (*args == 0)
	skip(sep);
    ଯେତେବେଳେ ((c = *args++)) {
	skip(sep);
	sep = ',';
        ଯଦି (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ଜାରି;
        }
        ପଦସମଷ୍ଟି_eq();
        type.ref = ଖାଲି;
        type.t = 0;
	ବାଛ (c) {
	    ସ୍ଥିତି 'e':
		ଜାରି;
	    ସ୍ଥିତି 'V':
                type.t = VT_CONSTANT;
	    ସ୍ଥିତି 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                ଭାଙ୍ଗ;
	    ସ୍ଥିତି 'S':
                type.t = VT_CONSTANT;
	    ସ୍ଥିତି 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                ଭାଙ୍ଗ;
	    ସ୍ଥିତି 'i':
                type.t = VT_INT;
                ଭାଙ୍ଗ;
	    ସ୍ଥିତି 'l':
                type.t = VT_SIZE_T;
                ଭାଙ୍ଗ;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                ଭାଙ୍ଗ;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    ଯଦି (nc)
        nocode_wanted--;
}

ସ୍ଥିର ଶୂନ୍ୟ parse_atomic(ପୂର୍ଣ୍ଣସଂଖ୍ୟା atok)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    ଅକ୍ଷର buf[40];
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *ଅଚଳ templates[] = {
        /*
         * Each entry consists of callback and function template.
         * The template represents argument types and return type.
         *
         * ? void (return-only)
         * b bool
         * a atomic
         * A read-only atomic
         * p pointer to memory
         * v value
         * l load pointer
         * s save pointer
         * m memory model
         */

        /* keep in order of appearance in tcctok.h: */
        /* __atomic_store */            "alm.?",
        /* __atomic_load */             "Asm.v",
        /* __atomic_exchange */         "alsm.v",
        /* __atomic_compare_exchange */ "aplbmm.b",
        /* __atomic_fetch_add */        "avm.v",
        /* __atomic_fetch_sub */        "avm.v",
        /* __atomic_fetch_or */         "avm.v",
        /* __atomic_fetch_xor */        "avm.v",
        /* __atomic_fetch_and */        "avm.v",
        /* __atomic_fetch_nand */       "avm.v",
        /* __atomic_and_fetch */        "avm.v",
        /* __atomic_sub_fetch */        "avm.v",
        /* __atomic_or_fetch */         "avm.v",
        /* __atomic_xor_fetch */        "avm.v",
        /* __atomic_and_fetch */        "avm.v",
        /* __atomic_nand_fetch */       "avm.v"
    };
    ଅଚଳ ଅକ୍ଷର *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ଖାଲି;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    ପାଇଁ (arg = 0;;) {
        ପଦସମଷ୍ଟି_eq();
        ବାଛ (template[arg]) {
        ସ୍ଥିତି 'a':
        ସ୍ଥିତି 'A':
            atom_ptr = &vtop->type;
            ଯଦି ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            ଯଦି (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            ଭାଙ୍ଗ;

        ସ୍ଥିତି 'p':
            ଯଦି ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'v':
            gen_assign_cast(atom);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'l':
            indir();
            gen_assign_cast(atom);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'm':
            gen_assign_cast(&int_type);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            ଭାଙ୍ଗ;
        }
        ଯଦି ('.' == template[++arg])
            ଭାଙ୍ଗ;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    ବାଛ (template[arg + 1]) {
    ସ୍ଥିତି 'b':
        ct.t = VT_BOOL;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 'v':
        ct = *atom;
        ଭାଙ୍ଗ;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ଯଦି (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ଅନ୍ୟଥା
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    ଯଦି (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC ଶୂନ୍ୟ unary(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ଯଦି (debug_modes)
        tcc_debug_ଧାଡ଼ି(tcc_state), tcc_tcov_check_ଧାଡ଼ି (tcc_state, 1);

    type.ref = ଖାଲି;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    ବାଛ(tok) {
    ସ୍ଥିତି TOK_EXTENSION:
        next();
        ଯାଅ tok_next;
    ସ୍ଥିତି TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        ଯାଅ ଠେଲ_tokc;
#endif
    ସ୍ଥିତି TOK_CINT:
    ସ୍ଥିତି TOK_CCHAR: 
	t = VT_INT;
 ଠେଲ_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CLLONG:
        t = VT_LLONG;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CFLOAT:
        t = VT_FLOAT;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CDOUBLE:
        t = VT_DOUBLE;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ଅନ୍ୟଥା
        t = VT_LDOUBLE;
#endif
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	ଯାଅ ଠେଲ_tokc;
    ସ୍ଥିତି TOK___FUNCTION__:
        ଯଦି (!gnu_ext)
            ଯାଅ tok_identifier;
        /* fall thru */
    ସ୍ଥିତି TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ଯାଅ case_TOK_STR;
    ସ୍ଥିତି TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#ଅନ୍ୟଥା
        t = VT_INT;
#endif
        ଯାଅ str_init;
    ସ୍ଥିତି TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ଯଦି (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, ଆକାର(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SOTYPE:
    ସ୍ଥିତି '(':
        t = tok;
        next();
        /* cast ? */
        ଯଦି (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ଯଦି (tok == '{') {
                    /* data is allocated locally by default */
                ଯଦି (global_ପଦସମଷ୍ଟି)
                    r = VT_CONST;
                ଅନ୍ୟଥା
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ଯଦି (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, ଆକାର(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ଅନ୍ୟଥା ଯଦି (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ଫେରନ୍ତୁ;
            } ଅନ୍ୟଥା {
                unary();
                gen_cast(&type);
            }
        } ଅନ୍ୟଥା ଯଦି (tok == '{') {
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_nocode_wanted = nocode_wanted;
            ଯଦି (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ଯଦି (0 == local_scope)
                tcc_error("statement expression outside of function");
            /* save all registers */
            save_regs(0);
            /* statement expression : we do not accept break/continue
               inside as GCC does.  We do retain the nocode_wanted state,
	       as statement expressions can't ever be entered from the
	       outside, so any reactivation of code emission (from labels
	       or loop heads) can be disabled again after the end of it. */
            /* default return value is (void) */
            vpushi(0), vtop->type.t = VT_VOID;
            block(STMT_ପଦସମଷ୍ଟି);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ଯଦି (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ଅନ୍ୟଥା {
            gexpr();
            skip(')');
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '*':
        next();
        unary();
        indir();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ଯଦି ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ଯଦି (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '+':
        next();
        unary();
        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ଯଦି (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_SIZEOF:
    ସ୍ଥିତି TOK_ALIGNOF1:
    ସ୍ଥିତି TOK_ALIGNOF2:
    ସ୍ଥିତି TOK_ALIGNOF3:
        t = tok;
        next();
        ଯଦି (tok == '(')
            tok = TOK_SOTYPE;
        ପଦସମଷ୍ଟି_type(&type, unary);
        ଯଦି (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } ଅନ୍ୟଥା {
            type_size(&type, &align);
            s = ଖାଲି;
            ଯଦି (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ଯଦି (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_builtin_choose_ପଦସମଷ୍ଟି:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = ପଦସମଷ୍ଟି_const64();
	    skip(',');
	    ଯଦି (!c) {
		nocode_wanted++;
	    }
	    ପଦସମଷ୍ଟି_eq();
	    ଯଦି (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ଯଦି (c) {
		nocode_wanted++;
	    }
	    ପଦସମଷ୍ଟି_eq();
	    ଯଦି (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_builtin_frame_address:
    ସ୍ଥିତି TOK_builtin_return_address:
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok1 = tok;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା level;
            next();
            skip('(');
            level = ପଦସମଷ୍ଟି_const();
            ଯଦି (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ଯେତେବେଳେ (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ଯଦି (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#ଅନ୍ୟଥା
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        ଭାଙ୍ଗ;
#ifdef TCC_TARGET_RISCV64
    ସ୍ଥିତି TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ଯଦି (r == VT_LLOCAL)
            r = VT_LOCAL;
        ଯଦି (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        ଭାଙ୍ଗ;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    ସ୍ଥିତି TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ଯଦି (r == VT_LLOCAL)
            r = VT_LOCAL;
        ଯଦି (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        ଭାଙ୍ଗ;
#ଅନ୍ୟଥା
    ସ୍ଥିତି TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	ଭାଙ୍ଗ;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    ସ୍ଥିତି TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ଭାଙ୍ଗ;
    }
    ସ୍ଥିତି TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        ଭାଙ୍ଗ;
    }
#endif
#ifdef TCC_TARGET_ARM64
    ସ୍ଥିତି TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ଭାଙ୍ଗ;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    ସ୍ଥିତି TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ଭାଙ୍ଗ;
    }
#endif

    /* atomic operations */
    ସ୍ଥିତି TOK___atomic_store:
    ସ୍ଥିତି TOK___atomic_load:
    ସ୍ଥିତି TOK___atomic_exchange:
    ସ୍ଥିତି TOK___atomic_compare_exchange:
    ସ୍ଥିତି TOK___atomic_fetch_add:
    ସ୍ଥିତି TOK___atomic_fetch_sub:
    ସ୍ଥିତି TOK___atomic_fetch_or:
    ସ୍ଥିତି TOK___atomic_fetch_xor:
    ସ୍ଥିତି TOK___atomic_fetch_and:
    ସ୍ଥିତି TOK___atomic_fetch_nand:
    ସ୍ଥିତି TOK___atomic_add_fetch:
    ସ୍ଥିତି TOK___atomic_sub_fetch:
    ସ୍ଥିତି TOK___atomic_or_fetch:
    ସ୍ଥିତି TOK___atomic_xor_fetch:
    ସ୍ଥିତି TOK___atomic_and_fetch:
    ସ୍ଥିତି TOK___atomic_nand_fetch:
        parse_atomic(tok);
        ଭାଙ୍ଗ;

    /* pre operations */
    ସ୍ଥିତି TOK_INC:
    ସ୍ଥିତି TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '-':
        next();
        unary();
	ଯଦି (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ଅନ୍ୟଥା {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LAND:
        ଯଦି (!gnu_ext)
            ଯାଅ tok_identifier;
        next();
        /* allow to take the address of a label */
        ଯଦି (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        ଯଦି (!s) {
            s = label_ଠେଲ(&global_label_ଗଦା, tok, LABEL_FORWARD);
        } ଅନ୍ୟଥା {
            ଯଦି (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ଯଦି ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_GENERIC:
    {
	CType controlling_type;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା has_default = 0;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା has_match = 0;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା learn = 0;
	TokenString *str = ଖାଲି;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	ପଦସମଷ୍ଟି_type(&controlling_type, ପଦସମଷ୍ଟି_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        ପାଇଁ (;;) {
	    learn = 0;
	    skip(',');
	    ଯଦି (tok == TOK_DEFAULT) {
		ଯଦି (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ଯଦି (!has_match)
		    learn = 1;
		next();
	    } ଅନ୍ୟଥା {
		ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ଯଦି (compare_types(&controlling_type, &type, 0)) {
		    ଯଦି (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ଯଦି (learn) {
		ଯଦି (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } ଅନ୍ୟଥା {
		skip_or_save_block(ଖାଲି);
	    }
	    ଯଦି (tok == ')')
		ଭାଙ୍ଗ;
	}
	ଯଦି (!str) {
	    ଅକ୍ଷର buf[60];
	    type_to_str(buf, ଆକାର buf, &controlling_type, ଖାଲି);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	ପଦସମଷ୍ଟି_eq();
	ଯଦି (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	ଭାଙ୍ଗ;
    }
    // special qnan , snan and infinity values
    ସ୍ଥିତି TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK___SNAN__:
	n = 0x7f800001;
	ଯାଅ special_math_val;
    ସ୍ଥିତି TOK___INF__:
	n = 0x7f800000;
	ଯାଅ special_math_val;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
    tok_identifier:
        ଯଦି (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        ଯଦି (!s || IS_ASM_SYM(s)) {
            ଅଚଳ ଅକ୍ଷର *name = get_tok_str(t, ଖାଲି);
            ଯଦି (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ଯଦି (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ଯଦି ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ଯଦି (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            ଯଦି (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } ଅନ୍ୟଥା ଯଦି (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        ଭାଙ୍ଗ;
    }
    
    /* post operations */
    ଯେତେବେଳେ (1) {
        ଯଦି (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } ଅନ୍ୟଥା ଯଦି (tok == '.' || tok == TOK_ARROW) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା qualifiers, cumofs;
            /* field */ 
            ଯଦି (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            next();
	    s = find_field(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_pointer_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            ଯଦି (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ଯଦି (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ଯଦି (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } ଅନ୍ୟଥା ଯଦି (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ଅନ୍ୟଥା ଯଦି (tok == '(') {
            SValue ret;
            Sym *sa;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ଯଦି ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ଯଦି ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ଯଦି ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        ଯାଅ error_func;
                } ଅନ୍ୟଥା {
                error_func:
                    expect("function pointer");
                }
            } ଅନ୍ୟଥା {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ଯଦି ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ଯଦି (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ଯଦି (size < 16)
                    ଯେତେବେଳେ (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    ଯଦି (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    ଯଦି (ret_nregs < 0)
                      vtop--;
                    ଅନ୍ୟଥା
                      nb_args++;
                }
            } ଅନ୍ୟଥା {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ଯଦି (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ଖାଲି;
            ଯଦି (tok != ')') {
                r = tcc_state->reverse_funcargs;
                ପାଇଁ(;;) {
                    ଯଦି (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } ଅନ୍ୟଥା {
                        ପଦସମଷ୍ଟି_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    ଯଦି (sa)
                        sa = sa->next;
                    ଯଦି (tok == ')')
                        ଭାଙ୍ଗ;
                    skip(',');
                }
            }
            ଯଦି (sa)
                tcc_error("too few arguments to function");

            ଯଦି (p) { /* with reverse_funcargs */
                ପାଇଁ (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    କର {
                        sa = sa->next, p2 = p2->prev;
                    } ଯେତେବେଳେ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    ପଦସମଷ୍ଟି_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            ଯଦି (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } ଅନ୍ୟଥା {
                /* return value */
                n = ret_nregs;
                ଯେତେବେଳେ (n > 1) {
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    ପାଇଁ (r = 0; r < NB_REGS; ++r)
                        ଯଦି (reg_classes[r] & rc)
                            ଭାଙ୍ଗ;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ଯଦି (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    ଯଦି (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    ପାଇଁ (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        ଯଦି (--ret_nregs == 0)
                          ଭାଙ୍ଗ;
                        offset += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                ଯଦି (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ଅନ୍ୟଥା
                    vtop->type.t = VT_INT;
#endif
                }
            }
            ଯଦି (s->f.func_noreturn) {
                ଯଦି (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } ଅନ୍ୟଥା {
            ଭାଙ୍ଗ;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_prod(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    unary();
    ଯେତେବେଳେ ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_sum(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    ପଦସମଷ୍ଟି_prod();
    ଯେତେବେଳେ ((t = tok) == '+' || t == '-') {
        next();
        ପଦସମଷ୍ଟି_prod();
        gen_op(t);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_shift(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    ପଦସମଷ୍ଟି_sum();
    ଯେତେବେଳେ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        ପଦସମଷ୍ଟି_sum();
        gen_op(t);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_cmp(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    ପଦସମଷ୍ଟି_shift();
    ଯେତେବେଳେ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        ପଦସମଷ୍ଟି_shift();
        gen_op(t);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_cmpeq(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    ପଦସମଷ୍ଟି_cmp();
    ଯେତେବେଳେ ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        ପଦସମଷ୍ଟି_cmp();
        gen_op(t);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_and(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_cmpeq();
    ଯେତେବେଳେ (tok == '&') {
        next();
        ପଦସମଷ୍ଟି_cmpeq();
        gen_op('&');
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_xor(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_and();
    ଯେତେବେଳେ (tok == '^') {
        next();
        ପଦସମଷ୍ଟି_and();
        gen_op('^');
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_or(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_xor();
    ଯେତେବେଳେ (tok == '|') {
        next();
        ପଦସମଷ୍ଟି_xor();
        gen_op('|');
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_landor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_land(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_or();
    ଯଦି (tok == TOK_LAND)
        ପଦସମଷ୍ଟି_landor(tok);
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_lor(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_land();
    ଯଦି (tok == TOK_LOR)
        ପଦସମଷ୍ଟି_landor(tok);
}

# define ପଦସମଷ୍ଟି_landor_next(op) op == TOK_LAND ? ପଦସମଷ୍ଟି_or() : ପଦସମଷ୍ଟି_land()
#ଅନ୍ୟଥା /* defined precedence_parser */
# define ପଦସମଷ୍ଟି_landor_next(op) unary(), ପଦସମଷ୍ଟି_infix(precedence(op) + 1)
# define ପଦସମଷ୍ଟି_lor() unary(), ପଦସମଷ୍ଟି_infix(1)

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା precedence(ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok)
{
    ବାଛ (tok) {
        ସ୍ଥିତି TOK_LOR: ଫେରନ୍ତୁ 1;
        ସ୍ଥିତି TOK_LAND: ଫେରନ୍ତୁ 2;
	ସ୍ଥିତି '|': ଫେରନ୍ତୁ 3;
	ସ୍ଥିତି '^': ଫେରନ୍ତୁ 4;
	ସ୍ଥିତି '&': ଫେରନ୍ତୁ 5;
	ସ୍ଥିତି TOK_EQ: ସ୍ଥିତି TOK_NE: ଫେରନ୍ତୁ 6;
 relat: ସ୍ଥିତି TOK_ULT: ସ୍ଥିତି TOK_UGE: ଫେରନ୍ତୁ 7;
	ସ୍ଥିତି TOK_SHL: ସ୍ଥିତି TOK_SAR: ଫେରନ୍ତୁ 8;
	ସ୍ଥିତି '+': ସ୍ଥିତି '-': ଫେରନ୍ତୁ 9;
	ସ୍ଥିତି '*': ସ୍ଥିତି '/': ସ୍ଥିତି '%': ଫେରନ୍ତୁ 10;
	ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
	    ଯଦି (tok >= TOK_ULE && tok <= TOK_GT)
	        ଯାଅ relat;
	    ଫେରନ୍ତୁ 0;
    }
}
ସ୍ଥିର unsigned ଅକ୍ଷର prec[256];
ସ୍ଥିର ଶୂନ୍ୟ init_prec(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_landor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_infix(ପୂର୍ଣ୍ଣସଂଖ୍ୟା p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = tok, p2;
    ଯେତେବେଳେ ((p2 = precedence(t)) >= p) {
        ଯଦି (t == TOK_LOR || t == TOK_LAND) {
            ପଦସମଷ୍ଟି_landor(t);
        } ଅନ୍ୟଥା {
            next();
            unary();
            ଯଦି (precedence(tok) > p2)
              ପଦସମଷ୍ଟି_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା condition_3way(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = -1;
    ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ଫେରନ୍ତୁ c;
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_landor(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    ପାଇଁ(;;) {
        c = f ? i : condition_3way();
        ଯଦି (c < 0)
            save_regs(1), cc = 0;
        ଅନ୍ୟଥା ଯଦି (c != i)
            nocode_wanted++, f = 1;
        ଯଦି (tok != op)
            ଭାଙ୍ଗ;
        ଯଦି (c < 0)
            t = gvtst(i, t);
        ଅନ୍ୟଥା
            vpop();
        next();
        ପଦସମଷ୍ଟି_landor_next(op);
    }
    ଯଦି (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ଅନ୍ୟଥା {
        gvtst_set(i, t);
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_cond_bool(SValue *sv)
{
    ଯଦି ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ଫେରନ୍ତୁ (unsigned)sv->c.i < 2;
    ଯଦି (sv->r == VT_CMP)
        ଫେରନ୍ତୁ 1;
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_cond(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    ପଦସମଷ୍ଟି_lor();
    ଯଦି (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ଯଦି (!g) {
            ଯଦି (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ଅନ୍ୟଥା {
                vpop();
            }
        } ଅନ୍ୟଥା ଯଦି (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ଯଦି (c == 0)
          nocode_wanted++;
        ଯଦି (!g)
          gexpr();

        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ଯଦି (g) {
            u = tt;
        } ଅନ୍ୟଥା ଯଦି (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ଅନ୍ୟଥା
          u = 0;

        ଯଦି (c == 0)
          nocode_wanted--;
        ଯଦି (c == 1)
          nocode_wanted++;
        skip(':');
        ପଦସମଷ୍ଟି_cond();

        ଯଦି ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ଯଦି (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ଯଦି (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_set(0, t1);
            gvtst_set(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            ଫେରନ୍ତୁ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ଯଦି (c != 1) {
            gen_cast(&type);
            ଯଦି (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ଯଦି (USING_TWO_ଶବ୍ଦଗୁଡ଼ିକ(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ଯଦି (c < 0) {
            ଯଦି (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ଯଦି (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        ଯଦି (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ଯଦି (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        ଯଦି (c < 0) {
            ଯଦି (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ଯଦି (islv)
          indir();
    }
}

ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_eq(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    
    ପଦସମଷ୍ଟି_cond();
    ଯଦି ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        ଯଦି (t == '=') {
            ପଦସମଷ୍ଟି_eq();
        } ଅନ୍ୟଥା {
            vdup();
            ପଦସମଷ୍ଟି_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC ଶୂନ୍ୟ gexpr(ଶୂନ୍ୟ)
{
    ପଦସମଷ୍ଟି_eq();
    ଯଦି (tok == ',') {
        କର {
            vpop();
            next();
            ପଦସମଷ୍ଟି_eq();
        } ଯେତେବେଳେ (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ଯଦି ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ଯଦି (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ସ୍ଥିର ଶୂନ୍ୟ ପଦସମଷ୍ଟି_const1(ଶୂନ୍ୟ)
{
    nocode_wanted += CONST_WANTED_BIT;
    ପଦସମଷ୍ଟି_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ int64_t ପଦସମଷ୍ଟି_const64(ଶୂନ୍ୟ)
{
    int64_t c;
    ପଦସମଷ୍ଟି_const1();
    ଯଦି ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ଫେରନ୍ତୁ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପଦସମଷ୍ଟି_const(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    int64_t wc = ପଦସମଷ୍ଟି_const64();
    c = wc;
    ଯଦି (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    ଫେରନ୍ତୁ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
ସ୍ଥିର ଶୂନ୍ୟ gfunc_return(CType *func_type)
{
    ଯଦି ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ଯଦି (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } ଅନ୍ୟଥା ଯଦି (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ଅନ୍ୟଥା {
            /* returning structure packed into registers */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, addr, align, rc, n;
            size = type_size(func_type,&align);
            ଯଦି (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ଯଦି (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		ଯଦି (ret_align > align)
		    align = ret_align;
                loc = (loc - size) & -align;
                addr = loc;
                type = *func_type;
                vset(&type, VT_LOCAL | VT_LVAL, addr);
                vswap();
                vstore();
                vpop();
                vset(&ret_type, VT_LOCAL | VT_LVAL, addr);
            }
            vtop->type = ret_type;
            rc = RC_RET(ret_type.t);
            //printf("struct return: n:%d t:%02x rc:%02x\n", ret_nregs, ret_type.t, rc);
            ପାଇଁ (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_offset(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } ଅନ୍ୟଥା {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

ସ୍ଥିର ଶୂନ୍ୟ check_func_return(ଶୂନ୍ୟ)
{
    ଯଦି ((func_vt.t & VT_BTYPE) == VT_VOID)
        ଫେରନ୍ତୁ;
    ଯଦି ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ଅନ୍ୟଥା {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା case_cmp(uint64_t a, uint64_t b)
{
    ଯଦି (cur_switch->sv.type.t & VT_UNSIGNED)
        ଫେରନ୍ତୁ a < b ? -1 : a > b;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା case_cmp_qs(ଅଚଳ ଶୂନ୍ୟ *pa, ଅଚଳ ଶୂନ୍ୟ *pb)
{
    ଫେରନ୍ତୁ case_cmp((*(ସଂରଚନା case_t**)pa)->v1, (*(ସଂରଚନା case_t**)pb)->v1);
}

ସ୍ଥିର ଶୂନ୍ୟ case_sort(ସଂରଚନା switch_t *sw)
{
    ସଂରଚନା case_t **p;
    ଯଦି (sw->n < 2)
        ଫେରନ୍ତୁ;
    qsort(sw->p, sw->n, ଆକାର *sw->p, case_cmp_qs);
    p = sw->p;
    ଯେତେବେଳେ (p < sw->p + sw->n - 1) {
        ଯଦି (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା l1 = p[0]->ଧାଡ଼ି, l2 = p[1]->ଧାଡ଼ି;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ଅନ୍ୟଥା ଯଦି (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * ଆକାର *p);
        } ଅନ୍ୟଥା
            ++p;
    }
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା gcase(ସଂରଚନା case_t **base, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dsym)
{
    ସଂରଚନା case_t *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ଯଦି (t != VT_LLONG)
        t = VT_INT;
    ଯେତେବେଳେ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        ଯଦି (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ଅନ୍ୟଥା {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ଯଦି (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ଅନ୍ୟଥା
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(base, l2, dsym);
            gsym(e);
        }
        ++l2, base += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    ଫେରନ୍ତୁ gjmp(dsym);
}

ସ୍ଥିର ଶୂନ୍ୟ end_switch(ଶୂନ୍ୟ)
{
    ସଂରଚନା switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ସ୍ଥିର ଶୂନ୍ୟ save_lvalues(ଶୂନ୍ୟ)
{
    SValue *sv = vtop;
    ଯେତେବେଳେ (sv >= vstack) {
        ଯଦି (sv->sym && (sv->r & VT_LVAL)) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା align, size = type_size(&sv->type, &align);
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    ପାଇଁ (; cls != stop; cls = cls->next) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_pointer(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


ସ୍ଥିର ଶୂନ୍ୟ try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ocd, ccd;

    ଯଦି (!cur_scope->cl.s)
	ଫେରନ୍ତୁ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    ପାଇଁ (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    ପାଇଁ (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    ପାଇଁ (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ସ୍ଥିର ଶୂନ୍ୟ block_cleanup(ସଂରଚନା scope *o)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା jmp = 0;
    Sym *g, **pg;
    ପାଇଁ (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ଯଦି (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            ଯଦି (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ଯଦି (!o->cl.n)
                ଯାଅ remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } ଅନ୍ୟଥା {
    remove_pending:
            *pg = g->prev;
            sym_free(g);
        }
    }
    gsym(jmp);
    try_call_scope_cleanup(o->cl.s);
}

/* ------------------------------------------------------------------------- */
/* VLA */

ସ୍ଥିର ଶୂନ୍ୟ vla_restore(ପୂର୍ଣ୍ଣସଂଖ୍ୟା loc)
{
    ଯଦି (loc)
        gen_vla_sp_restore(loc);
}

ସ୍ଥିର ଶୂନ୍ୟ vla_leave(ସଂରଚନା scope *o)
{
    ସଂରଚନା scope *c = cur_scope, *v = ଖାଲି;
    ପାଇଁ (; c != o && c; c = c->prev)
      ଯଦି (c->vla.ଅଙ୍କ)
        v = c;
    ଯଦି (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ସ୍ଥିର ଶୂନ୍ୟ new_scope(ସଂରଚନା scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.ଅଙ୍କ = 0;

    /* record local declaration stack position */
    o->lstk = local_ଗଦା;
    o->llstk = local_label_ଗଦା;
    ++local_scope;
}

ସ୍ଥିର ଶୂନ୍ୟ prev_scope(ସଂରଚନା scope *o, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_ପଦସମଷ୍ଟି)
{
    vla_leave(o->prev);

    ଯଦି (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    ଯଦି (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_ପଦସମଷ୍ଟି);

    /* pop locally defined labels */
    label_କାଢ଼(&local_label_ଗଦା, o->llstk, is_ପଦସମଷ୍ଟି);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_କାଢ଼(&local_ଗଦା, o->lstk, is_ପଦସମଷ୍ଟି);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ସ୍ଥିର ଶୂନ୍ୟ leave_scope(ସଂରଚନା scope *o)
{
    ଯଦି (!o)
        ଫେରନ୍ତୁ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ସ୍ଥିର ଶୂନ୍ୟ new_scope_s(ସଂରଚନା scope *o)
{
    o->lstk = local_ଗଦା;
    ++local_scope;
}

ସ୍ଥିର ଶୂନ୍ୟ prev_scope_s(ସଂରଚନା scope *o)
{
    sym_କାଢ଼(&local_ଗଦା, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ସ୍ଥିର ଶୂନ୍ୟ lblock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bsym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *csym)
{
    ସଂରଚନା scope *lo = loop_scope, *co = cur_scope;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *b = co->bsym, *c = co->csym;
    ଯଦି (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    ଯଦି (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ସ୍ଥିର ଶୂନ୍ୟ gexpr_decl(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = decl(VT_JMP);
    ଯଦି (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ଅନ୍ୟଥା {
        ଯଦି (v)
            skip(';');
        gexpr();
    }
}

ସ୍ଥିର ଶୂନ୍ୟ block(ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b, c, d, e, t;
    ସଂରଚନା scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ଯଦି (TOK_HAS_ମୂଲ୍ୟ(t))
        ଯାଅ ପଦସମଷ୍ଟି;
    next();

    ଯଦି (debug_modes)
        tcc_tcov_check_ଧାଡ଼ି (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    ଯଦି (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        ଯଦି (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } ଅନ୍ୟଥା {
            gsym(a);
        }
        prev_scope_s(&o);

    } ଅନ୍ୟଥା ଯଦି (t == TOK_WHILE) {
        new_scope_s(&o);
        d = gind();
        skip('(');
        gexpr();
        a = gvtst(1, 0);
        skip(')');
        b = 0;
        lblock(&a, &b);
        gjmp_addr(d);
        gsym_addr(b, d);
        gsym(a);
        prev_scope_s(&o);

    } ଅନ୍ୟଥା ଯଦି (t == '{') {
        ଯଦି (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ଯେତେବେଳେ (tok == TOK_LABEL) {
            କର {
                next();
                ଯଦି (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ଠେଲ(&local_label_ଗଦା, tok, LABEL_DECLARED);
                next();
            } ଯେତେବେଳେ (tok == ',');
            skip(';');
        }

        ଯେତେବେଳେ (tok != '}') {
	    decl(VT_LOCAL);
            ଯଦି (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_ପଦସମଷ୍ଟି);
        ଯଦି (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ଯଦି (local_scope)
            next();
        ଅନ୍ୟଥା ଯଦି (!nocode_wanted)
            check_func_return();

    } ଅନ୍ୟଥା ଯଦି (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ଯଦି (tok != ';') {
            gexpr();
            ଯଦି (b) {
                gen_assign_cast(&func_vt);
            } ଅନ୍ୟଥା {
                ଯଦି (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ଅନ୍ୟଥା ଯଦି (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ଅନ୍ୟଥା ଯଦି (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ମୂଳ_scope);
        ଯଦି (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ଯଦି (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ଯଦି (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } ଅନ୍ୟଥା ଯଦି (t == TOK_BREAK) {
        /* compute jump */
        ଯଦି (!cur_scope->bsym)
            tcc_error("cannot break");
        ଯଦି (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ଅନ୍ୟଥା
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ଅନ୍ୟଥା ଯଦି (t == TOK_CONTINUE) {
        /* compute jump */
        ଯଦି (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ଅନ୍ୟଥା ଯଦି (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ଯଦି (tok != ';') {
            /* c99 for-loop init decl? */
            ଯଦି (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ଯଦି (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ଯଦି (tok != ')') {
            e = gjmp(0);
            d = gind();
            gexpr();
            vpop();
            gjmp_addr(c);
            gsym(e);
        }
        skip(')');
        lblock(&a, &b);
        gjmp_addr(d);
        gsym_addr(b, d);
        gsym(a);
        prev_scope(&o, 0);

    } ଅନ୍ୟଥା ଯଦି (t == TOK_DO) {
        new_scope_s(&o);
        a = b = 0;
        d = gind();
        lblock(&a, &b);
        gsym(b);
        skip(TOK_WHILE);
        skip('(');
	gexpr();
        c = gvtst(0, 0);
        skip(')');
        skip(';');
	gsym_addr(c, d);
        gsym(a);
        prev_scope_s(&o);

    } ଅନ୍ୟଥା ଯଦି (t == TOK_SWITCH) {
        ସଂରଚନା switch_t *sw;

        sw = tcc_mallocz(ଆକାର *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ଯଦି (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ଖାଲି);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ଯଦି (sw->nocode_wanted)
            ଯାଅ skip_switch;
        case_sort(sw);
        sw->bsym = ଖାଲି; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ଯଦି (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ଅନ୍ୟଥା
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } ଅନ୍ୟଥା ଯଦି (t == TOK_CASE) {
        ସଂରଚନା case_t *cr;
        ଯଦି (!cur_switch)
            expect("switch");
        cr = tcc_malloc(ଆକାର(ସଂରଚନା case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(ପଦସମଷ୍ଟି_const64(), t);
        ଯଦି (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(ପଦସମଷ୍ଟି_const64(), t);
            ଯଦି (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ଯଦି (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->ଧାଡ଼ି = file->ଧାଡ଼ି_ଅଙ୍କ;
        skip(':');
        ଯାଅ block_after_label;

    } ଅନ୍ୟଥା ଯଦି (t == TOK_DEFAULT) {
        ଯଦି (!cur_switch)
            expect("switch");
        ଯଦି (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        ଯାଅ block_after_label;

    } ଅନ୍ୟଥା ଯଦି (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ଯଦି (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            ଯଦି ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ଅନ୍ୟଥା ଯଦି (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            ଯଦି (!s)
              s = label_ଠେଲ(&global_label_ଗଦା, tok, LABEL_FORWARD);
            ଅନ୍ୟଥା ଯଦି (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ଯଦି (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ଯଦି (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ଅନ୍ୟଥା {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } ଅନ୍ୟଥା {
            expect("label identifier");
        }
        skip(';');

    } ଅନ୍ୟଥା ଯଦି (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ଅନ୍ୟଥା {
        ଯଦି (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            ଯଦି (s) {
                ଯଦି (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ଖାଲି));
                s->r = LABEL_DEFINED;
		ଯଦି (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    ପାଇଁ (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_କାଢ଼(&s->next, ଖାଲି, 0);
		} ଅନ୍ୟଥା
		  gsym(s->jnext);
            } ଅନ୍ୟଥା {
                s = label_ଠେଲ(&global_label_ଗଦା, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ଖାଲି);

            ଯଦି (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ଯଦି (tok != '}') {
                ଯଦି (0 == (flags & STMT_COMPOUND))
                    ଯାଅ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ଅନ୍ୟଥା {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ଅନ୍ୟଥା {
            /* expression case */
            ଯଦି (t != ';') {
                unget_tok(t);
    ପଦସମଷ୍ଟି:
                ଯଦି (flags & STMT_ପଦସମଷ୍ଟି) {
                    vpop();
                    gexpr();
                } ଅନ୍ୟଥା {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ଯଦି (debug_modes)
        tcc_tcov_check_ଧାଡ଼ି (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ସ୍ଥିର ଶୂନ୍ୟ skip_or_save_block(TokenString **str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା braces = tok == '{';
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା level = 0;
    ଯଦି (str)
      *str = tok_str_alloc();

    ଯେତେବେଳେ (1) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = tok;
        ଯଦି (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             ଭାଙ୍ଗ;
	ଯଦି (t == TOK_EOF) {
	     ଯଦି (str || level > 0)
	       tcc_error("unexpected end of file");
	     ଅନ୍ୟଥା
	       ଭାଙ୍ଗ;
	}
	ଯଦି (str)
	  tok_str_add_tok(*str);
	next();
	ଯଦି (t == '{' || t == '(' || t == '[') {
	    level++;
	} ଅନ୍ୟଥା ଯଦି (t == '}' || t == ')' || t == ']') {
	    level--;
	    ଯଦି (level == 0 && braces && t == '}')
	      ଭାଙ୍ଗ;
	}
    }
    ଯଦି (str)
	tok_str_add(*str, TOK_EOF);
}

#define ପଦସମଷ୍ଟି_CONST 1
#define ପଦସମଷ୍ଟି_ANY   2

ସ୍ଥିର ଶୂନ୍ୟ parse_init_elem(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପଦସମଷ୍ଟି_type)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_global_ପଦସମଷ୍ଟି;
    ବାଛ(ପଦସମଷ୍ଟି_type) {
    ସ୍ଥିତି ପଦସମଷ୍ଟି_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_ପଦସମଷ୍ଟି = global_ପଦସମଷ୍ଟି;
        global_ପଦସମଷ୍ଟି = 1;
        ପଦସମଷ୍ଟି_const1();
        global_ପଦସମଷ୍ଟି = saved_global_ପଦସମଷ୍ଟି;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ଯଦି (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି ପଦସମଷ୍ଟି_ANY:
        ପଦସମଷ୍ଟି_eq();
        ଭାଙ୍ଗ;
    }
}

#ଯଦି 1
ସ୍ଥିର ଶୂନ୍ୟ init_assert(init_params *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା offset)
{
    ଯଦି (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#ଅନ୍ୟଥା
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
ସ୍ଥିର ଶୂନ୍ୟ init_putz(init_params *p, unsigned long c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    init_assert(p, c + size);
    ଯଦି (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ଅନ୍ୟଥା {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#ଯଦି defined TCC_TARGET_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#endif
        gfunc_call(3);
    }
}

#define DIF_FIRST     1
#define DIF_SIZE_ONLY 2
#define DIF_HAVE_ELEM 4
#define DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
ସ୍ଥିର ଶୂନ୍ୟ decl_design_delrels(Section *sec, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    ଯଦି (!sec || !sec->reloc)
        ଫେରନ୍ତୁ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    ଯେତେବେଳେ (rel < rel_end) {
        ଯଦି (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= ଆକାର *rel;
        } ଅନ୍ୟଥା {
            ଯଦି (rel2 != rel)
                memcpy(rel2, rel, ଆକାର *rel);
            ++rel2;
        }
        ++rel;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ decl_design_flex(init_params *p, Sym *ref, ପୂର୍ଣ୍ଣସଂଖ୍ୟା index)
{
    ଯଦି (ref == p->flex_array_ref) {
        ଯଦି (index >= ref->c)
            ref->c = index + 1;
    } ଅନ୍ୟଥା ଯଦି (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags, ପୂର୍ଣ୍ଣସଂଖ୍ୟା al)
{
    Sym *s, *f;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    ଯଦି (flags & DIF_HAVE_ELEM)
        ଯାଅ no_designator;

    ଯଦି (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        ଯଦି (tok == ':')
            ଯାଅ struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ଯେତେବେଳେ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ଯଦି (tok == '[') {
            ଯଦି (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = ପଦସମଷ୍ଟି_const();
            ଯଦି (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = ପଦସମଷ୍ଟି_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            ଯଦି (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            ଯଦି (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } ଅନ୍ୟଥା {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            ଯଦି (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = ଖାଲି;
    }
    ଯଦି (!cur_field) {
        ଯଦି (tok == '=') {
            next();
        } ଅନ୍ୟଥା ଯଦି (!gnu_ext) {
	    expect("=");
        }
    } ଅନ୍ୟଥା {
    no_designator:
        ଯଦି (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            ଯଦି (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } ଅନ୍ୟଥା {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ଯେତେବେଳେ (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            ଯଦି (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ଯଦି (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ଯଦି (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    ଯଦି (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
        ଯଦି (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ଯଦି (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        ଅନ୍ୟଥା
	    vset(type, VT_LOCAL|VT_LVAL, c);
        ପାଇଁ (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    ଯଦି (c - corig > al)
      al = c - corig;
    ଫେରନ୍ତୁ al;
}

ସ୍ଥିର ଶୂନ୍ୟ write_ldouble(unsigned ଅକ୍ଷର *d, ଶୂନ୍ୟ *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    ଯଦି (LDOUBLE_SIZE >= 10) {
        ଦ୍ୱିଗୁଣ b = *(long ଦ୍ୱିଗୁଣ*)s;
        s = &b;
#ଅନ୍ୟଥା
    ଯଦି (ଆକାର (long ଦ୍ୱିଗୁଣ) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = m >> 48;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f = e >> 4 & 0x7FF;
        m <<= 11;
        ଯଦି (0 == f) {
            ଯଦି (0 == m)
                ଯାଅ set;
            ପାଇଁ (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ଯଦି (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #ଯଦି (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #ନଚେତଯଦି LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } ଅନ୍ୟଥା {
    #ଯଦି LDOUBLE_SIZE == 8
        /* long double -> double */
        ଦ୍ୱିଗୁଣ b = *(long ଦ୍ୱିଗୁଣ*)s;
        memcpy(d, &b, 8);
    #ନଚେତଯଦି (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #ନଚେତଯଦି (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = *(uint16_t*)((ଅକ୍ଷର*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ନଚେତଯଦି (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((ଅକ୍ଷର*)s + 6);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା e = read16le((ଅକ୍ଷର*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ଅନ୍ୟଥା
        /* unknown */
        ଯଦି (ଆକାର (long ଦ୍ୱିଗୁଣ) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
ସ୍ଥିର ଶୂନ୍ୟ init_putv(init_params *p, CType *type, unsigned long c)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bt;
    ଶୂନ୍ୟ *ptr;
    CType dtype;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    ଯଦି (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    ଯଦି (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ଯଦି ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ଯଦି (NODATA_WANTED) {
            vtop--;
            ଫେରନ୍ତୁ;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	ଯଦି ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_FIRST_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->data + esym->st_ମୂଲ୍ୟ + (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)vtop->c.i, size);
	    ଯଦି (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		ଯେତେବେଳେ (relofs >= ଆକାର(*rel)) {
                    relofs -= ଆକାର(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    ଯଦି (rel->r_offset >= esym->st_ମୂଲ୍ୟ + size)
		      ଜାରି;
		    ଯଦି (rel->r_offset < esym->st_ମୂଲ୍ୟ)
		      ଭାଙ୍ଗ;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_ମୂଲ୍ୟ,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ଯଦି PTR_SIZE == 8
				   rel->r_addend
#ଅନ୍ୟଥା
				   0
#endif
				  );
		}
	    }
	} ଅନ୍ୟଥା {
            ଯଦି (type->t & VT_BITFIELD) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit_pos, bit_size, bits, n;
                unsigned ଅକ୍ଷର *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned ଅକ୍ଷର*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                ଯେତେବେଳେ (bit_size) {
                    n = 8 - bit_pos;
                    ଯଦି (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } ଅନ୍ୟଥା
            ବାଛ(bt) {
	    ସ୍ଥିତି VT_BOOL:
		*(ଅକ୍ଷର *)ptr = val != 0;
                ଭାଙ୍ଗ;
	    ସ୍ଥିତି VT_BYTE:
		*(ଅକ୍ଷର *)ptr = val;
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି VT_SHORT:
                write16le(ptr, val);
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି VT_FLOAT:
                write32le(ptr, val);
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି VT_DOUBLE:
                write64le(ptr, val);
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		ଭାଙ୍ଗ;

#ଯଦି PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    ସ୍ଥିତି VT_LLONG:
	    ସ୍ଥିତି VT_PTR:
	        ଯଦି (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        ଅନ୍ୟଥା
	          write64le(ptr, val);
	        ଭାଙ୍ଗ;
            ସ୍ଥିତି VT_INT:
                write32le(ptr, val);
                ଭାଙ୍ଗ;
#ଅନ୍ୟଥା
	    ସ୍ଥିତି VT_LLONG:
                write64le(ptr, val);
                ଭାଙ୍ଗ;
            ସ୍ଥିତି VT_PTR:
            ସ୍ଥିତି VT_INT:
	        ଯଦି (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        ଭାଙ୍ଗ;
#endif
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                //tcc_internal_error("unexpected type");
                ଭାଙ୍ଗ;
	    }
	}
        vtop--;
    } ଅନ୍ୟଥା {
        vset(&dtype, VT_LOCAL|VT_LVAL, c);
        vswap();
        vstore();
        vpop();
    }
}

/* 't' contains the type and storage info. 'c' is the offset of the
   object in section 'sec'. If 'sec' is NULL, it means stack based
   allocation. 'flags & DIF_FIRST' is true if array '{' must be read (multi
   dimension implicit array init handling). 'flags & DIF_SIZE_ONLY' is true if
   size only evaluation is wanted (only for arrays). */
ସ୍ଥିର ଶୂନ୍ୟ decl_initializer(init_params *p, CType *type, unsigned long c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, n, no_oblock, i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ଯଦି (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_ଧାଡ଼ି(tcc_state), tcc_tcov_check_ଧାଡ଼ି (tcc_state, 1);

    ଯଦି (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_SIZE_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ncw_prev = nocode_wanted;
        ଯଦି ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? ପଦସମଷ୍ଟି_ANY : ପଦସମଷ୍ଟି_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ଯଦି (type->t & VT_ARRAY) {
        no_oblock = 1;
        ଯଦି (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_size(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        ଯଦି ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ଅନ୍ୟଥା
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ଯଦି (size1 != (tok == TOK_STR ? 1 : ଆକାର(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ଯେତେବେଳେ (tok == TOK_STR || tok == TOK_LSTR) {
                ଯଦି (initstr.size)
                  initstr.size -= size1;
                ଯଦି (tok == TOK_STR)
                  len += tokc.str.size;
                ଅନ୍ୟଥା
                  len += tokc.str.size / ଆକାର(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            ଯଦି (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                ଯାଅ do_init_array;
            }

            decl_design_flex(p, s, len);
            ଯଦି (!(flags & DIF_SIZE_ONLY)) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb = n, ch;
                ଯଦି (len < nb)
                    nb = len;
                ଯଦି (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ଯଦି (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ଯଦି (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } ଅନ୍ୟଥା {
                    ପାଇଁ(i=0;i<n;i++) {
                        ଯଦି (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ଯଦି (flags & DIF_CLEAR)
                            ଭାଙ୍ଗ;
                          ଯଦି (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            ଭାଙ୍ଗ;
                          }
                          ch = 0;
                        } ଅନ୍ୟଥା ଯଦି (size1 == 1)
                          ch = ((unsigned ଅକ୍ଷର *)initstr.data)[i];
                        ଅନ୍ୟଥା
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ଯଦି (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } ଅନ୍ୟଥା {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ଯଦି (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ଯେତେବେଳେ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ଯଦି (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ଯଦି (no_oblock && len >= n*size1)
		        ଭାଙ୍ଗ;
		} ଅନ୍ୟଥା {
		    ଯଦି (s->type.t == VT_UNION)
		        f = ଖାଲି;
		    ଅନ୍ୟଥା
		        f = f->next;
		    ଯଦି (no_oblock && f == ଖାଲି)
		        ଭାଙ୍ଗ;
		}

		ଯଦି (tok == '}')
		    ଭାଙ୍ଗ;
		skip(',');
	    }
        }
        ଯଦି (!no_oblock)
            skip('}');

    } ଅନ୍ୟଥା ଯଦି ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        ଯାଅ one_elem;

    } ଅନ୍ୟଥା ଯଦି ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ଯଦି ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	ଯାଅ do_init_list;

    } ଅନ୍ୟଥା ଯଦି (tok == '{') {
        ଯଦି (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ଅନ୍ୟଥା one_elem: ଯଦି ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ଯଦି (flags & DIF_HAVE_ELEM)
            vpop();
        ଅନ୍ୟଥା
            skip_or_save_block(ଖାଲି);

    } ଅନ୍ୟଥା {
	ଯଦି (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ଯଦି (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? ପଦସମଷ୍ଟି_ANY : ପଦସମଷ୍ଟି_CONST);
	}
        ଯଦି (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ଅନ୍ୟଥା
            init_putv(p, type, c);
    }
}

/* parse an initializer for type 't' if 'has_init' is non zero, and
   allocate space in local or global data space ('r' is either
   VT_LOCAL or VT_CONST). If 'v' is non zero, then an associated
   variable 'v' of scope 'scope' is declared before initializers
   are parsed. If 'v' is zero, then a reference to the new object
   is put in the value stack. If 'has_init' is 2, a special parsing
   is done to handle string constants. */
ସ୍ଥିର ଶୂନ୍ୟ decl_initializer_alloc(CType *type, AttributeDef *ad, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, 
                                   ପୂର୍ଣ୍ଣସଂଖ୍ୟା has_init, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା scope)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, align, addr;
    TokenString *init_str = ଖାଲି;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    ଯଦି (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        ଯଦି (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ଯଦି (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ଫେରନ୍ତୁ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ଯଦି (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = ଖାଲି;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ଯଦି (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ଯଦି (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ଯଦି (IS_BT_ARRAY(type->t))
            type->ref = sym_ଠେଲ(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ଅନ୍ୟଥା ଯଦି (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        ଯଦି (field) {
            ଯେତେବେଳେ (field->next)
                field = field->next;
            ଯଦି (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    ଯଦି (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ଯଦି (!has_init)
            ଯାଅ err_size;
        ଯଦି (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ଯେତେବେଳେ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } ଅନ୍ୟଥା
            skip_or_save_block(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        next();
        decl_initializer(&p, type, 0, DIF_FIRST | DIF_SIZE_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        next();

        /* if still unknown size, error */
        size = type_size(type, &align);
        ଯଦି (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ଯଦି (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ଯଦି (ad->a.aligned) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା speca = 1 << (ad->a.aligned - 1);
        ଯଦି (speca > align)
            align = speca;
    } ଅନ୍ୟଥା ଯଦି (ad->a.packed) {
        align = 1;
    }

    ଯଦି (!v && NODATA_WANTED)
        size = 0, align = 1;

    ଯଦି ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ଖାଲି;
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        ଯଦି (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    ଯଦି (ad->asm_label) {
		ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg = asm_parse_regvar(ad->asm_label);
		ଯଦି (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_ଠେଲ(v, type, r, addr);
	    ଯଦି (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ଅନ୍ୟଥା {
            /* push local reference */
            vset(type, r, addr);
        }
    } ଅନ୍ୟଥା {
        CType *tp = type;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_const;

        ଯେତେବେଳେ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ଯଦି (!sec) {
            ଯଦି (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ଅନ୍ୟଥା ଯଦି (is_const) {
		sec = rodata_section;
            } ଅନ୍ୟଥା ଯଦି (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ଅନ୍ୟଥା ଯଦି (tcc_state->nocommon)
                sec = bss_section;
        } ଅନ୍ୟଥା ଯଦି (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ଯଦି (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ଯଦି (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        ଯଦି (bcheck)
            size = size + 1; /* add padding */
#endif
        ଯଦି (sec) {
	    addr = section_add(sec, size, align);
        } ଅନ୍ୟଥା {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ଯଦି (v) {
            ଯଦି (!sym) {
                sym = sym_ଠେଲ(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ଖାଲି);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } ଅନ୍ୟଥା {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ଯଦି (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * ଆକାର(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    ଯଦି (type->t & VT_VLA) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;

        ଯଦି (has_init)
            tcc_error("variable length array cannot be initialized");

        ଯଦି (NODATA_WANTED)
            ଯାଅ no_alloc;

        /* save before-VLA stack pointer if needed */
        ଯଦି (cur_scope->vla.ଅଙ୍କ == 0) {
            ଯଦି (cur_scope->prev && cur_scope->prev->vla.ଅଙ୍କ) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } ଅନ୍ୟଥା {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#ଯଦି defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.ଅଙ୍କ++;
    } ଅନ୍ୟଥା ଯଦି (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ଯଦି (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ଯଦି (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ସ୍ଥିର ଶୂନ୍ୟ func_vla_arg_code(Sym *arg)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା align;
    TokenString *vla_array_tok = ଖାଲି;

    ଯଦି (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    ଯଦି ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_size(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	next();
	gexpr();
	end_macro();
	next();
	vpush_type_size(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

ସ୍ଥିର ଶୂନ୍ୟ func_vla_arg(Sym *sym)
{
    Sym *arg;

    ପାଇଁ (arg = sym->type.ref->next; arg; arg = arg->next)
        ଯଦି ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା byref)
{
    s = sym_find(s->v);
    ଯଦି (!s) /* unnamed parameters, not enabled */
        ଫେରନ୍ତୁ ଖାଲି;
    s->c = c;
    ଯଦି (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ଫେରନ୍ତୁ s;
}

/* push parameters (and their types), last first */
ସ୍ଥିର ଶୂନ୍ୟ sym_ଠେଲ_params(Sym *ref)
{
    Sym *s = ref;
    ଯେତେବେଳେ (s->next)
        s = s->next;
    ଯେତେବେଳେ (s != ref) {
        ଯଦି ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_ଗଦା);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ସ୍ଥିର ଶୂନ୍ୟ gen_function(Sym *sym)
{
    ସଂରଚନା scope f = { 0 };

    cur_scope = ମୂଳ_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    ଯଦି (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ଖାଲି);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    ଯଦି (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    ଯଦି (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ଗଦା, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ଠେଲ_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(ଖାଲି, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_କାଢ଼(&local_ଗଦା, ଖାଲି, 0);
    label_କାଢ଼(&global_label_ଗଦା, ଖାଲି, 0);
    sym_କାଢ଼(&all_cleanups, ଖାଲି, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = ଖାଲି;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = DATA_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    next();
}

ସ୍ଥିର ଶୂନ୍ୟ gen_inline_functions(TCCState *s)
{
    Sym *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା inline_generated, i;
    ସଂରଚନା InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    କର {
        inline_generated = 0;
        ପାଇଁ (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ଯଦି (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ଖାଲି;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } ଯେତେବେଳେ (inline_generated);
    tcc_close();
}

ସ୍ଥିର ଶୂନ୍ୟ free_inline_functions(TCCState *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    /* free tokens of unused inline functions */
    ପାଇଁ (i = 0; i < s->nb_inline_fns; ++i) {
        ସଂରଚନା InlineFunc *fn = s->inline_fns[i];
        ଯଦି (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ସ୍ଥିର ଶୂନ୍ୟ do_Static_assert(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ;

    next();
    skip('(');
    c = ପଦସମଷ୍ଟି_const();
    ସନ୍ଦେଶ = "_Static_assert fail";
    ଯଦି (tok == ',') {
        next();
        ସନ୍ଦେଶ = parse_mult_str("string constant")->data;
    }
    skip(')');
    ଯଦି (c == 0)
        tcc_error("%s", ସନ୍ଦେଶ);
    skip(';');
}

#ifdef TCC_TARGET_PE
ସ୍ଥିର ଶୂନ୍ୟ pe_check_linkage(CType *type, AttributeDef *ad)
{
    ଯଦି (!ad->a.dllimport && !ad->a.dllexport)
        ଫେରନ୍ତୁ;
    ଯଦି (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ଯଦି (type->t & VT_TYPEDEF) {
        ଅଚଳ ଅକ୍ଷର *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ଅନ୍ୟଥା ଯଦି (ad->a.dllimport) {
        ଯଦି ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ଅନ୍ୟଥା
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା decl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା l)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ଯେତେବେଳେ (1) {

        oldint = 0;
        ଯଦି (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ଯଦି (l == VT_JMP)
                ଫେରନ୍ତୁ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ଯଦି (tok == ';' && l != VT_CMP) {
                next();
                ଜାରି;
            }
            ଯଦି (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ଜାରି;
            }
            ଯଦି (l != VT_CONST)
                ଭାଙ୍ଗ;
            ଯଦି (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ଜାରି;
            }
            ଯଦି (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ଅନ୍ୟଥା {
                ଯଦି (tok != TOK_EOF)
                    expect("declaration");
                ଭାଙ୍ଗ;
            }
        }

        ଯଦି (tok == ';') {
            ଯଦି ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            ଅନ୍ୟଥା ଯଦି (IS_ENUM(btype.t))
                ; /* enum decl */
            ଅନ୍ୟଥା
                tcc_warning("useless type defines no instances");
            ଯଦି (l == VT_JMP)
                ଫେରନ୍ତୁ 1;
            next();
            ଜାରି;
        }

        ଯେତେବେଳେ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            ଯଦି ((type.t & VT_BTYPE) == VT_FUNC) {
                ଯଦି ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ଯଦି (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ଯଦି ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ଯଦି (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ଅନ୍ୟଥା
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ଅନ୍ୟଥା ଯଦି (oldint) {
                tcc_warning("type defaults to int");
            }

            ଯଦି (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ଯଦି 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ଯଦି (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            ଯଦି (tok == '{') {
                ଯଦି (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ଯଦି ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                ପାଇଁ (sa = sym->type.ref; (sa = sa->next) != ଖାଲି;) {
                    ଯଦି (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    ଯଦି (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ଯଦି (sym->type.t & VT_INLINE) {
                    ସଂରଚନା InlineFunc *fn;
                    fn = tcc_malloc(ଆକାର *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } ଅନ୍ୟଥା {
                    /* compute text section */
                    cur_text_section = text_section;
                    ଯଦି (ad.section) {
                        cur_text_section = ad.section;
                        ଯଦି (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                ଭାଙ୍ଗ;
            } ଅନ୍ୟଥା {
                has_init = 0;
		ଯଦି (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    ପାଇଁ (sym = func_vt.ref->next; sym; sym = sym->next)
			ଯଦି ((sym->v & ~SYM_FIELD) == v)
			    ଯାଅ found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ଖାଲି));
                found:
		    ଯଦି (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ଖାଲି));
		    ଯଦି (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ଖାଲି));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ଅନ୍ୟଥା ଯଦି (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    ଯଦି (sym && sym->sym_scope == local_scope) {
                        ଯଦି (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ଖାଲି));
                        sym->type = type;
                    } ଅନ୍ୟଥା {
                        sym = sym_ଠେଲ(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ଯଦି ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    ଯଦି (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ଅନ୍ୟଥା ଯଦି ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ଅନ୍ୟଥା {
                    r = 0;
                    ଯଦି ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } ଅନ୍ୟଥା ଯଦି (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ଯଦି (tok == '=')
                        has_init = 1;

                    ଯଦି (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ଅନ୍ୟଥା {
                        ଯଦି (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ଅନ୍ୟଥା
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ଯଦି (has_init)
                            next();
                        ଅନ୍ୟଥା ଯଦି (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ଯଦି (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        ଯଦି (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_ମୂଲ୍ୟ, esym->st_size, 1);
                    }
                }
                ଯଦି (tok != ',') {
                    ଯଦି (l == VT_JMP)
                        ଫେରନ୍ତୁ has_init ? v : 1;
                    skip(';');
                    ଭାଙ୍ଗ;
                }
                next();
            }
        }
    }
    ଫେରନ୍ତୁ 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
