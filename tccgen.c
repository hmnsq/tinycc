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
#ಅನ್ತರ್ಭಾವ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA ಪೂರ್ಣಾಙ್ಕ rsym, anon_sym, ind, loc;

ST_DATA Sym *global_ರಾಶಿ;
ST_DATA Sym *local_ರಾಶಿ;
ST_DATA Sym *define_ರಾಶಿ;
ST_DATA Sym *global_label_ರಾಶಿ;
ST_DATA Sym *local_label_ರಾಶಿ;

ಸ್ಥಿರ Sym *sym_free_first;
ಸ್ಥಿರ ಶೂನ್ಯ **sym_pools;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ nb_sym_pools;

ಸ್ಥಿರ Sym *all_cleanups, *pending_gotos;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ local_scope;
ST_DATA ವರ್ಣ debug_modes;

ST_DATA SValue *vtop;
ಸ್ಥಿರ SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA ಪೂರ್ಣಾಙ್ಕ nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() ಯದಿ(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA ಪೂರ್ಣಾಙ್ಕ global_ಅಭಿವ್ಯಕ್ತಿ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_vc; /* stack address for implicit struct return storage */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_ind; /* function start address */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ func_old;
ST_DATA ಧ್ರುವ ವರ್ಣ *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
ಸ್ಥಿರ CString initstr;

#ಯದಿ PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#ನೋಚೇದ್ಯದಿ LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#ಅನ್ಯಥಾ
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

ಸ್ಥಿರ ಸಂರಚನಾ switch_t {
    ಸಂರಚನಾ case_t {
        int64_t v1, v2;
        ಪೂರ್ಣಾಙ್ಕ ind, ಸಾಲು;
    } **p; ಪೂರ್ಣಾಙ್ಕ n; /* list of case ranges */
    ಪೂರ್ಣಾಙ್ಕ def_sym; /* default symbol */
    ಪೂರ್ಣಾಙ್ಕ nocode_wanted;
    ಪೂರ್ಣಾಙ್ಕ *bsym;
    ಸಂರಚನಾ scope *scope;
    ಸಂರಚನಾ switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_ಸಂಖ್ಯೆ 8
/*list of temporary local variables on the stack in current function. */
ಸ್ಥಿರ ಸಂರಚನಾ temp_local_variable {
	ಪೂರ್ಣಾಙ್ಕ location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_ಸಂಖ್ಯೆ];
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ nb_temp_local_vars;

ಸ್ಥಿರ ಸಂರಚನಾ scope {
    ಸಂರಚನಾ scope *prev;
    ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ loc, locorig, ಅಂಕೆ; } vla;
    ಸಂರಚನಾ { Sym *s; ಪೂರ್ಣಾಙ್ಕ n; } cl;
    ಪೂರ್ಣಾಙ್ಕ *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ಬೇರು_scope;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    Section *sec;
    ಪೂರ್ಣಾಙ್ಕ local_offset;
    Sym *flex_array_ref;
} init_params;

#ಯದಿ 1
#define precedence_parser
ಸ್ಥಿರ ಶೂನ್ಯ init_prec(ಶೂನ್ಯ);
#endif

ಸ್ಥಿರ ಶೂನ್ಯ block(ಪೂರ್ಣಾಙ್ಕ flags);
#define STMT_ಅಭಿವ್ಯಕ್ತಿ 1
#define STMT_COMPOUND 2

ಸ್ಥಿರ ಶೂನ್ಯ gen_cast(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ gen_cast_s(ಪೂರ್ಣಾಙ್ಕ t);
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ CType *pointed_type(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ check_restrict_type(CType *type);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ type_qualifiers(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ parse_btype_qualify(CType *type, ಪೂರ್ಣಾಙ್ಕ qualifiers);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_compatible_types(CType *type1, CType *type2);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_btype(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ ignore_label);
ಸ್ಥಿರ CType *type_decl(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ *v, ಪೂರ್ಣಾಙ್ಕ td);
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಅಭಿವ್ಯಕ್ತಿ_type(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ init_putv(init_params *p, CType *type, unsigned long c);
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer(init_params *p, CType *type, unsigned long c, ಪೂರ್ಣಾಙ್ಕ flags);
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer_alloc(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ has_init, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ scope);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ decl(ಪೂರ್ಣಾಙ್ಕ l);
ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_eq(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ vpush_type_size(CType *type, ಪೂರ್ಣಾಙ್ಕ *a);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_compatible_unqualified_types(CType *type1, CType *type2);
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ int64_t ಅಭಿವ್ಯಕ್ತಿ_const64(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ vpush64(ಪೂರ್ಣಾಙ್ಕ ty, unsigned long long v);
ಸ್ಥಿರ ಶೂನ್ಯ vpush(CType *type);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gvtst(ಪೂರ್ಣಾಙ್ಕ inv, ಪೂರ್ಣಾಙ್ಕ t);
ಸ್ಥಿರ ಶೂನ್ಯ gen_inline_functions(TCCState *s);
ಸ್ಥಿರ ಶೂನ್ಯ free_inline_functions(TCCState *s);
ಸ್ಥಿರ ಶೂನ್ಯ skip_or_save_block(TokenString **str);
ಸ್ಥಿರ ಶೂನ್ಯ gv_dup(ಶೂನ್ಯ);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ get_temp_local_var(ಪೂರ್ಣಾಙ್ಕ size,ಪೂರ್ಣಾಙ್ಕ align,ಪೂರ್ಣಾಙ್ಕ *r2);
ಸ್ಥಿರ ಶೂನ್ಯ cast_error(CType *st, CType *dt);
ಸ್ಥಿರ ಶೂನ್ಯ end_switch(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ do_Static_assert(ಶೂನ್ಯ);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಙ್ಕ t)
{
  ಯದಿ (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gind()
{
  ಪೂರ್ಣಾಙ್ಕ t = ind;
  CODE_ON();
  ಯದಿ (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  ಪ್ರತ್ಯಾಗಮ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ಸ್ಥಿರ ಶೂನ್ಯ gjmp_addr_acs(ಪೂರ್ಣಾಙ್ಕ t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gjmp_acs(ಪೂರ್ಣಾಙ್ಕ t)
{
  t = gjmp(t);
  CODE_OFF();
  ಪ್ರತ್ಯಾಗಮ t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN ಪೂರ್ಣಾಙ್ಕ is_float(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ bt = t & VT_BTYPE;
    ಪ್ರತ್ಯಾಗಮ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ is_integer_btype(ಪೂರ್ಣಾಙ್ಕ bt)
{
    ಪ್ರತ್ಯಾಗಮ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ btype_size(ಪೂರ್ಣಾಙ್ಕ bt)
{
    ಪ್ರತ್ಯಾಗಮ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ R_RET(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (!is_float(t))
        ಪ್ರತ್ಯಾಗಮ REG_IRET;
#ifdef TCC_TARGET_X86_64
    ಯದಿ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಪ್ರತ್ಯಾಗಮ TREG_ST0;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    ಯದಿ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಪ್ರತ್ಯಾಗಮ REG_IRET;
#endif
    ಪ್ರತ್ಯಾಗಮ REG_FRET;
}

/* returns 2nd function return register, if any */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ R2_RET(ಪೂರ್ಣಾಙ್ಕ t)
{
    t &= VT_BTYPE;
#ಯದಿ PTR_SIZE == 4
    ಯದಿ (t == VT_LLONG)
        ಪ್ರತ್ಯಾಗಮ REG_IRE2;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
    ಯದಿ (t == VT_QLONG)
        ಪ್ರತ್ಯಾಗಮ REG_IRE2;
    ಯದಿ (t == VT_QFLOAT)
        ಪ್ರತ್ಯಾಗಮ REG_FRE2;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    ಯದಿ (t == VT_LDOUBLE)
        ಪ್ರತ್ಯಾಗಮ REG_IRE2;
#endif
    ಪ್ರತ್ಯಾಗಮ VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_ಪದಗಳು(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ಸ್ಥಿರ ಶೂನ್ಯ PUT_R_RET(SValue *sv, ಪೂರ್ಣಾಙ್ಕ t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ RC_RET(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪ್ರತ್ಯಾಗಮ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ RC_TYPE(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ (!is_float(t))
        ಪ್ರತ್ಯಾಗಮ RC_INT;
#ifdef TCC_TARGET_X86_64
    ಯದಿ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಪ್ರತ್ಯಾಗಮ RC_ST0;
    ಯದಿ ((t & VT_BTYPE) == VT_QFLOAT)
        ಪ್ರತ್ಯಾಗಮ RC_FRET;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    ಯದಿ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಪ್ರತ್ಯಾಗಮ RC_INT;
#endif
    ಪ್ರತ್ಯಾಗಮ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ RC2_TYPE(ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ rc)
{
    ಯದಿ (!USING_TWO_ಪದಗಳು(t))
        ಪ್ರತ್ಯಾಗಮ 0;
#ifdef RC_IRE2
    ಯದಿ (rc == RC_IRET)
        ಪ್ರತ್ಯಾಗಮ RC_IRE2;
#endif
#ifdef RC_FRE2
    ಯದಿ (rc == RC_FRET)
        ಪ್ರತ್ಯಾಗಮ RC_FRE2;
#endif
    ಯದಿ (rc & RC_FLOAT)
        ಪ್ರತ್ಯಾಗಮ RC_FLOAT;
    ಪ್ರತ್ಯಾಗಮ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ ieee_finite(ದ್ವಿಗುಣ d)
{
    ಪೂರ್ಣಾಙ್ಕ p[4];
    memcpy(p, &d, ಪರಿಮಾಣ(ದ್ವಿಗುಣ));
    ಪ್ರತ್ಯಾಗಮ ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC ಶೂನ್ಯ test_lvalue(ಶೂನ್ಯ)
{
    ಯದಿ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC ಶೂನ್ಯ check_vstack(ಶೂನ್ಯ)
{
    ಯದಿ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (ಪೂರ್ಣಾಙ್ಕ)(vtop - vstack + 1));
}

#ಯದಿ 0
/* dump 'b' vstack entries starting with 'a'  */
ಶೂನ್ಯ pv (ಧ್ರುವ ವರ್ಣ *lbl, ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (ಪೂರ್ಣಾಙ್ಕ)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ psyms(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", ಸಂದೇಶ);
    ಯಾವತ್ (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ type_to_str(ವರ್ಣ *buf, ಪೂರ್ಣಾಙ್ಕ buf_size, CType *type, ಧ್ರುವ ವರ್ಣ *varstr);

/* print type */
ಸ್ಥಿರ ಶೂನ್ಯ ptype(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ, CType *type, ಪೂರ್ಣಾಙ್ಕ v)
{
    ವರ್ಣ buf[500];
    type_to_str(buf, ಪರಿಮಾಣ(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, ರಿಕ್ತ) : ರಿಕ್ತ);
    printf("%s : %s;\n", ಸಂದೇಶ, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC ಶೂನ್ಯ tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, ಪರಿಮಾಣ *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ಯದಿ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ತಳ್ಳು(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_ಅಭಿವ್ಯಕ್ತಿ = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_ಅಂಕೆ | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ಯದಿ TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    ಪ್ರತ್ಯಾಗಮ 0;
}

ST_FUNC ಶೂನ್ಯ tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_ತೆಗೆ(&global_ರಾಶಿ, ರಿಕ್ತ, 0);
    sym_ತೆಗೆ(&local_ರಾಶಿ, ರಿಕ್ತ, 0);
    /* free preprocessor macros */
    free_defines(ರಿಕ್ತ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    ಯಾವತ್ (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = ರಿಕ್ತ;
    all_cleanups = ರಿಕ್ತ;
    pending_gotos = ರಿಕ್ತ;
    nb_temp_local_vars = 0;
    global_label_ರಾಶಿ = ರಿಕ್ತ;
    local_label_ರಾಶಿ = ರಿಕ್ತ;
    cur_text_section = ರಿಕ್ತ;
    sym_free_first = ರಿಕ್ತ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ಯದಿ (!s || !s->c)
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
  ಪ್ರತ್ಯಾಗಮ &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC ಶೂನ್ಯ update_storage(Sym *sym)
{
    ElfSym *esym;
    ಪೂರ್ಣಾಙ್ಕ sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ಯದಿ (!esym)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ಯದಿ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ಅನ್ಯಥಾ ಯದಿ (sym->a.weak)
        sym_bind = STB_WEAK;
    ಅನ್ಯಥಾ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ಯದಿ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    ಯದಿ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ಯದಿ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#ಯದಿ 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ರಿಕ್ತ),
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

ST_FUNC ಶೂನ್ಯ put_extern_sym2(Sym *sym, ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ,
                            addr_t ಮೌಲ್ಯ, unsigned long size,
                            ಪೂರ್ಣಾಙ್ಕ can_add_underscore)
{
    ಪೂರ್ಣಾಙ್ಕ sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ಧ್ರುವ ವರ್ಣ *name;
    ವರ್ಣ buf1[256];

    ಯದಿ (!sym->c) {
        name = get_tok_str(sym->v, ರಿಕ್ತ);
        t = sym->type.t;
        ಯದಿ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ಅನ್ಯಥಾ ಯದಿ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ಯದಿ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ಅನ್ಯಥಾ ಯದಿ (t & VT_TLS) {
            sym_type = STT_TLS;
        } ಅನ್ಯಥಾ {
            sym_type = STT_OBJECT;
        }
        ಯದಿ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ಅನ್ಯಥಾ
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        ಯದಿ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ಯದಿ (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            ಯದಿ (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        ಯದಿ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ರಿಕ್ತ);
            can_add_underscore = 0;
        }

        ಯದಿ (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, ಪರಿಮಾಣ(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, ಮೌಲ್ಯ, size, info, other, sh_ಅಂಕೆ, name);

        ಯದಿ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_ಅಂಕೆ, sym_bind, sym_type);

    } ಅನ್ಯಥಾ {
        esym = elfsym(sym);
        esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
        esym->st_size = size;
        esym->st_shndx = sh_ಅಂಕೆ;
    }
    update_storage(sym);
}

ST_FUNC ಶೂನ್ಯ put_extern_sym(Sym *sym, Section *s, addr_t ಮೌಲ್ಯ, unsigned long size)
{
    ಯದಿ (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        ಪ್ರತ್ಯಾಗಮ;
    put_extern_sym2(sym, s ? s->sh_ಅಂಕೆ : SHN_UNDEF, ಮೌಲ್ಯ, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC ಶೂನ್ಯ greloca(Section *s, Sym *sym, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type,
                     addr_t addend)
{
    ಪೂರ್ಣಾಙ್ಕ c = 0;

    ಯದಿ (nocode_wanted && s == cur_text_section)
        ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (sym) {
        ಯದಿ (0 == sym->c) {
            put_extern_sym(sym, ರಿಕ್ತ, 0, 0);
            ಯದಿ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ಯಾವತ್ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#ಯದಿ PTR_SIZE == 4
ST_FUNC ಶೂನ್ಯ greloc(Section *s, Sym *sym, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ಸ್ಥಿರ Sym *__sym_malloc(ಶೂನ್ಯ)
{
    Sym *sym_pool, *sym, *last_sym;
    ಪೂರ್ಣಾಙ್ಕ i;

    sym_pool = tcc_malloc(SYM_POOL_NB * ಪರಿಮಾಣ(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    ಪ್ರತಿ(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    ಪ್ರತ್ಯಾಗಮ last_sym;
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ Sym *sym_malloc(ಶೂನ್ಯ)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    ಯದಿ (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    ಪ್ರತ್ಯಾಗಮ sym;
#ಅನ್ಯಥಾ
    sym = tcc_malloc(ಪರಿಮಾಣ(Sym));
    ಪ್ರತ್ಯಾಗಮ sym;
#endif
}

ST_INLN ಶೂನ್ಯ sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#ಅನ್ಯಥಾ
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, ಪರಿಮಾಣ *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    ಪ್ರತ್ಯಾಗಮ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, ಪೂರ್ಣಾಙ್ಕ v)
{
    ಯಾವತ್ (s) {
        ಯದಿ (s->v == v)
            ಪ್ರತ್ಯಾಗಮ s;
        s = s->prev;
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

/* structure lookup */
ST_INLN Sym *struct_find(ಪೂರ್ಣಾಙ್ಕ v)
{
    v -= TOK_IDENT;
    ಯದಿ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(ಪೂರ್ಣಾಙ್ಕ v)
{
    v -= TOK_IDENT;
    ಯದಿ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ sym_link(Sym *s, ಪೂರ್ಣಾಙ್ಕ yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ಯದಿ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ಅನ್ಯಥಾ
        ps = &ts->sym_identifier;
    ಯದಿ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ಅನ್ಯಥಾ {
        *ps = s->prev_tok;
    }
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ಪ್ರತ್ಯಾಗಮ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, CType *type, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ c)
{
    Sym *s, **ps;
    ಯದಿ (local_ರಾಶಿ)
        ps = &local_ರಾಶಿ;
    ಅನ್ಯಥಾ
        ps = &global_ರಾಶಿ;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ಯದಿ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ಯದಿ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ರಿಕ್ತ));
    }
    ಪ್ರತ್ಯಾಗಮ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ರಾಶಿ, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ಯದಿ (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ಯಾವತ್ (*ps != ರಿಕ್ತ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    ಪ್ರತ್ಯಾಗಮ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC ಶೂನ್ಯ sym_ತೆಗೆ(Sym **ptop, Sym *b, ಪೂರ್ಣಾಙ್ಕ keep)
{
    Sym *s, *ss;
    ಪೂರ್ಣಾಙ್ಕ v;

    s = *ptop;
    ಯಾವತ್(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ಯದಿ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	ಯದಿ (!keep)
	    sym_free(s);
        s = ss;
    }
    ಯದಿ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(ಪೂರ್ಣಾಙ್ಕ v)
{
    v -= TOK_IDENT;
    ಯದಿ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ table_ident[v]->sym_label;
}

ST_FUNC Sym *label_ತಳ್ಳು(Sym **ptop, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    ಯದಿ (ptop == &global_label_ರಾಶಿ) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ಯಾವತ್ (*ps != ರಿಕ್ತ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    ಪ್ರತ್ಯಾಗಮ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC ಶೂನ್ಯ label_ತೆಗೆ(Sym **ptop, Sym *slast, ಪೂರ್ಣಾಙ್ಕ keep)
{
    Sym *s, *s1;
    ಪ್ರತಿ(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ಯದಿ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ರಿಕ್ತ));
        } ಅನ್ಯಥಾ ಯದಿ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ರಿಕ್ತ));
        } ಅನ್ಯಥಾ {
            ಯದಿ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        ಯದಿ (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ಯದಿ (!keep)
            sym_free(s);
        ಅನ್ಯಥಾ
            s->r = LABEL_GONE;
    }
    ಯದಿ (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ಸ್ಥಿರ ಶೂನ್ಯ vcheck_cmp(ಶೂನ್ಯ)
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

    ಯದಿ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

ಸ್ಥಿರ ಶೂನ್ಯ vsetc(CType *type, ಪೂರ್ಣಾಙ್ಕ r, CValue *vc)
{
    ಯದಿ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ರಿಕ್ತ;
}

ST_FUNC ಶೂನ್ಯ vswap(ಶೂನ್ಯ)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC ಶೂನ್ಯ vpop(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v;
    v = vtop->r & VT_VALMASK;
#ಯದಿ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    ಯದಿ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ಅನ್ಯಥಾ
#endif
    ಯದಿ (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ಸ್ಥಿರ ಶೂನ್ಯ vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ಸ್ಥಿರ ಶೂನ್ಯ vpush64(ಪೂರ್ಣಾಙ್ಕ ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ರಿಕ್ತ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC ಶೂನ್ಯ vpushi(ಪೂರ್ಣಾಙ್ಕ v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ಸ್ಥಿರ ಶೂನ್ಯ vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC ಶೂನ್ಯ vset(CType *type, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ಸ್ಥಿರ ಶೂನ್ಯ vseti(ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ರಿಕ್ತ;
    vset(&type, r, v);
}

ST_FUNC ಶೂನ್ಯ vpushv(SValue *v)
{
    ಯದಿ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ಸ್ಥಿರ ಶೂನ್ಯ vdup(ಶೂನ್ಯ)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC ಶೂನ್ಯ vrotb(ಪೂರ್ಣಾಙ್ಕ n)
{
    SValue tmp;
    ಯದಿ (--n < 1)
        ಪ್ರತ್ಯಾಗಮ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, ಪರಿಮಾಣ *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC ಶೂನ್ಯ vrott(ಪೂರ್ಣಾಙ್ಕ n)
{
    SValue tmp;
    ಯದಿ (--n < 1)
        ಪ್ರತ್ಯಾಗಮ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, ಪರಿಮಾಣ *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC ಶೂನ್ಯ vrev(ಪೂರ್ಣಾಙ್ಕ n)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    SValue tmp;
    vcheck_cmp();
    ಪ್ರತಿ (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC ಶೂನ್ಯ vset_VT_CMP(ಪೂರ್ಣಾಙ್ಕ op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ಸ್ಥಿರ ಶೂನ್ಯ vset_VT_JMP(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ op = vtop->cmp_op;

    ಯದಿ (vtop->jtrue || vtop->jfalse) {
        ಪೂರ್ಣಾಙ್ಕ origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        ಪೂರ್ಣಾಙ್ಕ inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ಅನ್ಯಥಾ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ಯದಿ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ಸ್ಥಿರ ಶೂನ್ಯ gvtst_set(ಪೂರ್ಣಾಙ್ಕ inv, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ *p;

    ಯದಿ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ಯದಿ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gvtst(ಪೂರ್ಣಾಙ್ಕ inv, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ಯದಿ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ಯದಿ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ಅನ್ಯಥಾ ಯದಿ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ಪ್ರತ್ಯಾಗಮ t;
}

/* generate a zero or nozero test */
ಸ್ಥಿರ ಶೂನ್ಯ gen_test_zero(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಯದಿ (vtop->r == VT_CMP) {
        ಪೂರ್ಣಾಙ್ಕ j;
        ಯದಿ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ಅನ್ಯಥಾ {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC ಶೂನ್ಯ vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    ಪೂರ್ಣಾಙ್ಕ v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ತಳ್ಳು(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    ಪ್ರತ್ಯಾಗಮ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ಸ್ಥಿರ ಶೂನ್ಯ vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(ಪೂರ್ಣಾಙ್ಕ v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    ಯದಿ (!s) {
        /* push forward reference */
        s = global_identifier_ತಳ್ಳು(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ಅನ್ಯಥಾ ಯದಿ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ಪ್ರತ್ಯಾಗಮ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(ಪೂರ್ಣಾಙ್ಕ v)
{
    CType ct = { VT_ASM_FUNC, ರಿಕ್ತ };
    ಪ್ರತ್ಯಾಗಮ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC ಶೂನ್ಯ vpush_helper_func(ಪೂರ್ಣಾಙ್ಕ v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ merge_symattr(ಸಂರಚನಾ SymAttr *sa, ಸಂರಚನಾ SymAttr *sa1)
{
    ಯದಿ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ಯದಿ (sa1->visibility != STV_DEFAULT) {
	ಪೂರ್ಣಾಙ್ಕ vis = sa->visibility;
	ಯದಿ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ merge_funcattr(ಸಂರಚನಾ FuncAttr *fa, ಸಂರಚನಾ FuncAttr *fa1)
{
    ಯದಿ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ಯದಿ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ಯದಿ (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    ಯದಿ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ಯದಿ (fa1->func_ctor)
      fa->func_ctor = 1;
    ಯದಿ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    ಯದಿ (ad1->section)
      ad->section = ad1->section;
    ಯದಿ (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    ಯದಿ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ಯದಿ (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ patch_type(Sym *sym, CType *type)
{
    ಯದಿ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ಯದಿ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ರಿಕ್ತ));
        sym->type.t &= ~VT_EXTERN;
    }

    ಯದಿ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ಯದಿ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ಯದಿ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ರಿಕ್ತ));

    } ಅನ್ಯಥಾ ಯದಿ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        ಪೂರ್ಣಾಙ್ಕ static_proto = sym->type.t & VT_STATIC;
        ಪೂರ್ಣಾಙ್ಕ ft1 = sym->type.ref->f.func_type;
        ಪೂರ್ಣಾಙ್ಕ ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ಯದಿ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ರಿಕ್ತ));

        /* set 'inline' if both agree or if one has static */
        ಯದಿ ((type->t | sym->type.t) & VT_INLINE) {
            ಯದಿ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ಯದಿ (0 == (type->t & VT_EXTERN)) {
            ಸಂರಚನಾ FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ಯದಿ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } ಅನ್ಯಥಾ {
            sym->type.t &= ~VT_INLINE | static_proto;
            ಯದಿ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ಅನ್ಯಥಾ {
        ಯದಿ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ಯದಿ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ರಿಕ್ತ));
    }
}

/* Merge some storage attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ಯದಿ (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    ಯದಿ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ರಿಕ್ತ));
#endif
    merge_symattr(&sym->a, &ad->a);
    ಯದಿ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ಸ್ಥಿರ Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ಯದಿ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    ಪ್ರತ್ಯಾಗಮ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ಸ್ಥಿರ ಶೂನ್ಯ move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    ಪೂರ್ಣಾಙ್ಕ n, bt;

    bt = s->type.t & VT_BTYPE;
    ಯದಿ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ಪ್ರತ್ಯಾಗಮ;

    ಪ್ರತಿ (s = s->type.ref, n = 0; s; s = s->next) {
        ಪ್ರತಿ (lp = &local_ರಾಶಿ; !!(l = *lp); lp = &l->prev) {
            ಯದಿ (l == s) {
                *lp = s->prev;
                s->prev = global_ರಾಶಿ, global_ರಾಶಿ = s;
                ಯದಿ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } ಅನ್ಯಥಾ {
                    ಯದಿ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                ಯದಿ (bt != VT_PTR)
                    n = 1;
                ಭಙ್ಗ;
            }
        }
        ಯದಿ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            ಭಙ್ಗ;
    }
}

/* define a new external reference to a symbol 'v' */
ಸ್ಥಿರ Sym *external_sym(ಪೂರ್ಣಾಙ್ಕ v, CType *type, ಪೂರ್ಣಾಙ್ಕ r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    ಯಾವತ್ (s && s->sym_scope)
        s = s->prev_tok;

    ಯದಿ (!s) {
        /* push forward reference */
        s = global_identifier_ತಳ್ಳು(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ಅನ್ಯಥಾ {
        patch_storage(s, ad, type);
    }
    ಯದಿ (local_ರಾಶಿ) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_ರಾಶಿ);
    }
    ಪ್ರತ್ಯಾಗಮ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC ಶೂನ್ಯ save_regs(ಪೂರ್ಣಾಙ್ಕ n)
{
    SValue *p, *p1;
    ಪ್ರತಿ(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC ಶೂನ್ಯ save_reg(ಪೂರ್ಣಾಙ್ಕ r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC ಶೂನ್ಯ save_reg_upstack(ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ n)
{
    ಪೂರ್ಣಾಙ್ಕ l, size, align, bt, r2;
    SValue *p, *p1, sv;

    ಯದಿ ((r &= VT_VALMASK) >= VT_CONST)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    l = r2 = 0;
    ಪ್ರತಿ(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ಯದಿ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ಯದಿ (!l) {
                bt = p->type.t & VT_BTYPE;
                ಯದಿ (bt == VT_VOID)
                    ಅನುವರ್ತ;
                ಯದಿ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ರಿಕ್ತ;
                store(p->r & VT_VALMASK, &sv);
#ಯದಿ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ಯದಿ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                ಯದಿ (p->r2 < VT_CONST && USING_TWO_ಪದಗಳು(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ಯದಿ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ಅನ್ಯಥಾ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ರಿಕ್ತ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ get_reg_ex(ಪೂರ್ಣಾಙ್ಕ rc, ಪೂರ್ಣಾಙ್ಕ rc2)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    SValue *p;
    
    ಪ್ರತಿ(r=0;r<NB_REGS;r++) {
        ಯದಿ (reg_classes[r] & rc2) {
            ಪೂರ್ಣಾಙ್ಕ n;
            n=0;
            ಪ್ರತಿ(p = vstack; p <= vtop; p++) {
                ಯದಿ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ಯದಿ (n <= 1)
                ಪ್ರತ್ಯಾಗಮ r;
        }
    }
    ಪ್ರತ್ಯಾಗಮ get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ get_reg(ಪೂರ್ಣಾಙ್ಕ rc)
{
    ಪೂರ್ಣಾಙ್ಕ r;
    SValue *p;

    /* find a free register */
    ಪ್ರತಿ(r=0;r<NB_REGS;r++) {
        ಯದಿ (reg_classes[r] & rc) {
            ಯದಿ (nocode_wanted)
                ಪ್ರತ್ಯಾಗಮ r;
            ಪ್ರತಿ(p=vstack;p<=vtop;p++) {
                ಯದಿ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    ಗಚ್ಛ notfound;
            }
            ಪ್ರತ್ಯಾಗಮ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    ಪ್ರತಿ(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ಯದಿ (r < VT_CONST && (reg_classes[r] & rc))
            ಗಚ್ಛ save_found;
        r = p->r & VT_VALMASK;
        ಯದಿ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            ಪ್ರತ್ಯಾಗಮ r;
        }
    }
    /* Should never comes here */
    ಪ್ರತ್ಯಾಗಮ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ get_temp_local_var(ಪೂರ್ಣಾಙ್ಕ size,ಪೂರ್ಣಾಙ್ಕ align, ಪೂರ್ಣಾಙ್ಕ *r2)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಸಂರಚನಾ temp_local_variable *temp_var;
    SValue *p;
    ಪೂರ್ಣಾಙ್ಕ r;
    unsigned used = 0;

    /* mark locations that are still in use */
    ಪ್ರತಿ (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ಯದಿ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ಯದಿ (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_ಸಂಖ್ಯೆ)
	        used |= 1<<r;
	}
    }
    ಪ್ರತಿ (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	ಯದಿ(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ಪ್ರತ್ಯಾಗಮ temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    ಯದಿ (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_ಸಂಖ್ಯೆ) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	ಗಚ್ಛ ret_tmp;
    }
    *r2 = VT_CONST;
    ಪ್ರತ್ಯಾಗಮ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ಸ್ಥಿರ ಶೂನ್ಯ move_reg(ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ s, ಪೂರ್ಣಾಙ್ಕ t)
{
    SValue sv;

    ಯದಿ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ರಿಕ್ತ;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC ಶೂನ್ಯ gaddrof(ಶೂನ್ಯ)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ಯದಿ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounded_ptr_add(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ಯದಿ (save) {
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
    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - ಪರಿಮಾಣ(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounded_ptr_deref(ಶೂನ್ಯ)
{
    addr_t func;
    ಪೂರ್ಣಾಙ್ಕ size, align;
    ElfW_Rel *rel;
    Sym *sym;

    ಯದಿ (nocode_wanted)
        ಪ್ರತ್ಯಾಗಮ;

    size = type_size(&vtop->type, &align);
    ವಿಕಲ್ಪ(size) {
    ಪಕ್ಷ  1: func = TOK___bound_ptr_indir1; ಭಙ್ಗ;
    ಪಕ್ಷ  2: func = TOK___bound_ptr_indir2; ಭಙ್ಗ;
    ಪಕ್ಷ  4: func = TOK___bound_ptr_indir4; ಭಙ್ಗ;
    ಪಕ್ಷ  8: func = TOK___bound_ptr_indir8; ಭಙ್ಗ;
    ಪಕ್ಷ 12: func = TOK___bound_ptr_indir12; ಭಙ್ಗ;
    ಪಕ್ಷ 16: func = TOK___bound_ptr_indir16; ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        /* may happen with struct member access */
        ಪ್ರತ್ಯಾಗಮ;
    }
    sym = external_helper_sym(func);
    ಯದಿ (!sym->c)
        put_extern_sym(sym, ರಿಕ್ತ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ಸ್ಥಿರ ಶೂನ್ಯ gbound(ಶೂನ್ಯ)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ಯದಿ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ಯದಿ (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC ಶೂನ್ಯ gbound_args(ಪೂರ್ಣಾಙ್ಕ nb_args)
{
    ಪೂರ್ಣಾಙ್ಕ i, v;
    SValue *sv;

    ಪ್ರತಿ (i = 1; i <= nb_args; ++i)
        ಯದಿ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    ಯದಿ (sv->r & VT_SYM) {
        v = sv->sym->v;
        ಯದಿ (v == TOK_setjmp
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
        ಯದಿ (v == TOK_alloca)
            func_bound_add_epilog = 1;
#ಯದಿ TARGETOS_NetBSD
        ಯದಿ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ಸ್ಥಿರ ಶೂನ್ಯ add_local_bounds(Sym *s, Sym *e)
{
    ಪ್ರತಿ (; s != e; s = s->prev) {
        ಯದಿ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ಅನುವರ್ತ;
        /* Add arrays/structs/unions because we always take address */
        ಯದಿ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * ಪರಿಮಾಣ(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_end_scope(Sym *b, ಪೂರ್ಣಾಙ್ಕ bounds)
{
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_ರಾಶಿ, b);
#endif
    tcc_add_debug_info (tcc_state, local_ರಾಶಿ, b);
}

/* increment an lvalue pointer */
ಸ್ಥಿರ ಶೂನ್ಯ incr_offset(ಪೂರ್ಣಾಙ್ಕ offset)
{
    ಪೂರ್ಣಾಙ್ಕ t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ಸ್ಥಿರ ಶೂನ್ಯ incr_bf_adr(ಪೂರ್ಣಾಙ್ಕ o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ಸ್ಥಿರ ಶೂನ್ಯ load_packed_bf(CType *type, ಪೂರ್ಣಾಙ್ಕ bit_pos, ಪೂರ್ಣಾಙ್ಕ bit_size)
{
    ಪೂರ್ಣಾಙ್ಕ n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    ಕುರು {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        ಯದಿ (n > bit_size)
            n = bit_size;
        ಯದಿ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        ಯದಿ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ಯದಿ (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } ಯಾವತ್ (bit_size);
    vswap(), vpop();
    ಯದಿ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ಸ್ಥಿರ ಶೂನ್ಯ store_packed_bf(ಪೂರ್ಣಾಙ್ಕ bit_pos, ಪೂರ್ಣಾಙ್ಕ bit_size)
{
    ಪೂರ್ಣಾಙ್ಕ bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    ಕುರು {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ಯದಿ (bits)
            vpushi(bits), gen_op(TOK_SHR);
        ಯದಿ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        ಯದಿ (n > bit_size)
            n = bit_size;
        ಯದಿ (n < 8) {
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
    } ಯಾವತ್ (bit_size);
    vpop(), vpop();
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ adjust_bf(SValue *sv, ಪೂರ್ಣಾಙ್ಕ bit_pos, ಪೂರ್ಣಾಙ್ಕ bit_size)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    ಯದಿ (0 == sv->type.ref)
        ಪ್ರತ್ಯಾಗಮ 0;
    t = sv->type.ref->auxtype;
    ಯದಿ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ಪ್ರತ್ಯಾಗಮ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gv(ಪೂರ್ಣಾಙ್ಕ rc)
{
    ಪೂರ್ಣಾಙ್ಕ r, r2, r_ok, r2_ok, rc2, bt;
    ಪೂರ್ಣಾಙ್ಕ bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    ಯದಿ (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = ರಿಕ್ತ;
        type.t = vtop->type.t & VT_UNSIGNED;
        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ಅನ್ಯಥಾ
            type.t |= VT_INT;

        ಯದಿ (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } ಅನ್ಯಥಾ {
        ಯದಿ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            ಯದಿ (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        ಯದಿ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ಪ್ರತ್ಯಾಗಮ vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        ಯದಿ (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        ಯದಿ (!r_ok || !r2_ok) {

            ಯದಿ (!r_ok) {
                ಯದಿ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ಅನ್ಯಥಾ
                    r = get_reg(rc);
            }

            ಯದಿ (rc2) {
                ಪೂರ್ಣಾಙ್ಕ load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                ಪೂರ್ಣಾಙ್ಕ original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ಅನ್ಯಥಾ ಯದಿ (vtop->r & VT_LVAL) {
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
                } ಅನ್ಯಥಾ {
                    /* move registers */
                    ಯದಿ (!r_ok)
                        load(r, vtop);
                    ಯದಿ (r2_ok && vtop->r2 < VT_CONST)
                        ಗಚ್ಛ done;
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
            } ಅನ್ಯಥಾ {
                ಯದಿ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        ಯದಿ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    ಪ್ರತ್ಯಾಗಮ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC ಶೂನ್ಯ gv2(ಪೂರ್ಣಾಙ್ಕ rc1, ಪೂರ್ಣಾಙ್ಕ rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ಯದಿ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ಯದಿ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ಅನ್ಯಥಾ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ಯದಿ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ಯದಿ PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC ಶೂನ್ಯ lexpand(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ಯದಿ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ಅನ್ಯಥಾ ಯದಿ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ಅನ್ಯಥಾ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#ಯದಿ PTR_SIZE == 4
/* build a long long from two ints */
ಸ್ಥಿರ ಶೂನ್ಯ lbuild(ಪೂರ್ಣಾಙ್ಕ t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
ಸ್ಥಿರ ಶೂನ್ಯ gv_dup(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t, rc, r;

    t = vtop->type.t;
#ಯದಿ PTR_SIZE == 4
    ಯದಿ ((t & VT_BTYPE) == VT_LLONG) {
        ಯದಿ (t & VT_BITFIELD) {
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
        ಪ್ರತ್ಯಾಗಮ;
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

#ಯದಿ PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
ಸ್ಥಿರ ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ t, a, b, op1, c, i;
    ಪೂರ್ಣಾಙ್ಕ func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    ವಿಕಲ್ಪ(op) {
    ಪಕ್ಷ '/':
    ಪಕ್ಷ TOK_PDIV:
        func = TOK___divdi3;
        ಗಚ್ಛ gen_func;
    ಪಕ್ಷ TOK_UDIV:
        func = TOK___udivdi3;
        ಗಚ್ಛ gen_func;
    ಪಕ್ಷ '%':
        func = TOK___moddi3;
        ಗಚ್ಛ gen_mod_func;
    ಪಕ್ಷ TOK_UMOD:
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
        ಭಙ್ಗ;
    ಪಕ್ಷ '^':
    ಪಕ್ಷ '&':
    ಪಕ್ಷ '|':
    ಪಕ್ಷ '*':
    ಪಕ್ಷ '+':
    ಪಕ್ಷ '-':
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
        ಯದಿ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            ಪ್ರತಿ(i=0;i<4;i++)
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
        } ಅನ್ಯಥಾ ಯದಿ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ಯದಿ (op == '+')
                op1 = TOK_ADDC1;
            ಅನ್ಯಥಾ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ಅನ್ಯಥಾ {
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
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SAR:
    ಪಕ್ಷ TOK_SHR:
    ಪಕ್ಷ TOK_SHL:
        ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (ಪೂರ್ಣಾಙ್ಕ)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ಯದಿ (op != TOK_SHL)
                vswap();
            ಯದಿ (c >= 32) {
                /* stack: L H */
                vpop();
                ಯದಿ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ಯದಿ (op != TOK_SAR) {
                    vpushi(0);
                } ಅನ್ಯಥಾ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ಅನ್ಯಥಾ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ಯದಿ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ಅನ್ಯಥಾ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ಯದಿ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ಅನ್ಯಥಾ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ಯದಿ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ಅನ್ಯಥಾ {
            /* XXX: should provide a faster fallback on x86 ? */
            ವಿಕಲ್ಪ(op) {
            ಪಕ್ಷ TOK_SAR:
                func = TOK___ashrdi3;
                ಗಚ್ಛ gen_func;
            ಪಕ್ಷ TOK_SHR:
                func = TOK___lshrdi3;
                ಗಚ್ಛ gen_func;
            ಪಕ್ಷ TOK_SHL:
                func = TOK___ashldi3;
                ಗಚ್ಛ gen_func;
            }
        }
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
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
        ಯದಿ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ಯದಿ (op1 == TOK_LT)
            op1 = TOK_LE;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_GT)
            op1 = TOK_GE;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ಯದಿ (op == TOK_NE) {
            b = gvtst(0, 0);
        } ಅನ್ಯಥಾ {
            a = gvtst(1, 0);
            ಯದಿ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ಯದಿ (op1 == TOK_LT)
            op1 = TOK_ULT;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_LE)
            op1 = TOK_ULE;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_GT)
            op1 = TOK_UGT;
        ಅನ್ಯಥಾ ಯದಿ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ಯದಿ 0//def TCC_TARGET_I386
        ಯದಿ (op == TOK_NE) { gsym(b); ಭಙ್ಗ; }
        ಯದಿ (op == TOK_EQ) { gsym(a); ಭಙ್ಗ; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        ಭಙ್ಗ;
    }
}
#endif

/* normalize values */
ಸ್ಥಿರ uint64_t value64(uint64_t l1, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        ಪ್ರತ್ಯಾಗಮ l1;
    ಅನ್ಯಥಾ ಯದಿ (t & VT_UNSIGNED)
        ಪ್ರತ್ಯಾಗಮ (uint32_t)l1;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ (uint32_t)l1 | -(l1 & 0x80000000);
}

ಸ್ಥಿರ uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ಪ್ರತ್ಯಾಗಮ (a ^ b) >> 63 ? -x : x;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gen_opic_lt(uint64_t a, uint64_t b)
{
    ಪ್ರತ್ಯಾಗಮ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ಸ್ಥಿರ ಶೂನ್ಯ gen_opic(ಪೂರ್ಣಾಙ್ಕ op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    ಪೂರ್ಣಾಙ್ಕ t1 = v1->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ t2 = v2->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಙ್ಕ c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ಪೂರ್ಣಾಙ್ಕ c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    ಪೂರ್ಣಾಙ್ಕ shm = (t1 == VT_LLONG) ? 63 : 31;
    ಪೂರ್ಣಾಙ್ಕ r;

    ಯದಿ (c1 && c2) {
        ವಿಕಲ್ಪ(op) {
        ಪಕ್ಷ '+': l1 += l2; ಭಙ್ಗ;
        ಪಕ್ಷ '-': l1 -= l2; ಭಙ್ಗ;
        ಪಕ್ಷ '&': l1 &= l2; ಭಙ್ಗ;
        ಪಕ್ಷ '^': l1 ^= l2; ಭಙ್ಗ;
        ಪಕ್ಷ '|': l1 |= l2; ಭಙ್ಗ;
        ಪಕ್ಷ '*': l1 *= l2; ಭಙ್ಗ;

        ಪಕ್ಷ TOK_PDIV:
        ಪಕ್ಷ '/':
        ಪಕ್ಷ '%':
        ಪಕ್ಷ TOK_UDIV:
        ಪಕ್ಷ TOK_UMOD:
            /* if division by zero, generate explicit division */
            ಯದಿ (l2 == 0) {
                ಯದಿ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                ಗಚ್ಛ general_case;
            }
            ವಿಕಲ್ಪ(op) {
            ಸ್ವಭಾವ: l1 = gen_opic_sdiv(l1, l2); ಭಙ್ಗ;
            ಪಕ್ಷ '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); ಭಙ್ಗ;
            ಪಕ್ಷ TOK_UDIV: l1 = l1 / l2; ಭಙ್ಗ;
            ಪಕ್ಷ TOK_UMOD: l1 = l1 % l2; ಭಙ್ಗ;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SHL: l1 <<= (l2 & shm); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SHR: l1 >>= (l2 & shm); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            ಭಙ್ಗ;
            /* tests */
        ಪಕ್ಷ TOK_ULT: l1 = l1 < l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGE: l1 = l1 >= l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_EQ: l1 = l1 == l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NE: l1 = l1 != l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ULE: l1 = l1 <= l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UGT: l1 = l1 > l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LT: l1 = gen_opic_lt(l1, l2); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GE: l1 = !gen_opic_lt(l1, l2); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LE: l1 = !gen_opic_lt(l2, l1); ಭಙ್ಗ;
        ಪಕ್ಷ TOK_GT: l1 = gen_opic_lt(l2, l1); ಭಙ್ಗ;
            /* logical */
        ಪಕ್ಷ TOK_LAND: l1 = l1 && l2; ಭಙ್ಗ;
        ಪಕ್ಷ TOK_LOR: l1 = l1 || l2; ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಗಚ್ಛ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ಅನ್ಯಥಾ {
        /* if commutative ops, put c2 as constant */
        ಯದಿ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ಯದಿ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ಅನ್ಯಥಾ ಯದಿ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ಯದಿ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ಅನ್ಯಥಾ ಯದಿ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ಅನ್ಯಥಾ ಯದಿ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ಯದಿ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                ಪೂರ್ಣಾಙ್ಕ n = -1;
                ಯದಿ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    ಗಚ್ಛ general_case;
                }
                ಯಾವತ್ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ಯದಿ (op == '*')
                    op = TOK_SHL;
                ಅನ್ಯಥಾ ಯದಿ (op == TOK_PDIV)
                    op = TOK_SAR;
                ಅನ್ಯಥಾ
                    op = TOK_SHR;
            }
            ಗಚ್ಛ general_case;
        } ಅನ್ಯಥಾ ಯದಿ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ಯದಿ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ)l2 != l2)
	        ಗಚ್ಛ general_case;
            vtop--;
            vtop->c.i = l2;
        } ಅನ್ಯಥಾ {
        general_case:
                /* call low level op generator */
                ಯದಿ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ಅನ್ಯಥಾ
                    gen_opi(op);
        }
        ಯದಿ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ಯದಿ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
ಶೂನ್ಯ gen_negf(ಪೂರ್ಣಾಙ್ಕ op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ಅನ್ಯಥಾ
/* XXX: implement in gen_opf() for other backends too */
ಶೂನ್ಯ gen_negf(ಪೂರ್ಣಾಙ್ಕ op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    ಪೂರ್ಣಾಙ್ಕ align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ಯದಿ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ಯದಿ (bt == VT_LDOUBLE)
        size = 10;
#endif
    ಯದಿ (nocode_wanted) /* save_reg() wont work */
        ಗಚ್ಛ gv2;
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
ಸ್ಥಿರ ಶೂನ್ಯ gen_opif(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ c1, c2, i, bt;
    SValue *v1, *v2;
#ಯದಿ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    ಚಞ್ಚಲ
#endif
    long ದ್ವಿಗುಣ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ಯದಿ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ಯದಿ (c1 && c2) {
        ಯದಿ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ಅನ್ಯಥಾ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ಯದಿ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            ಗಚ್ಛ general_case;
        ವಿಕಲ್ಪ(op) {
        ಪಕ್ಷ '+': f1 += f2; ಭಙ್ಗ;
        ಪಕ್ಷ '-': f1 -= f2; ಭಙ್ಗ;
        ಪಕ್ಷ '*': f1 *= f2; ಭಙ್ಗ;
        ಪಕ್ಷ '/': 
            ಯದಿ (f2 == 0.0) {
                ಸಙ್ಘ { ಭಿನ್ನ f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ಯದಿ (!CONST_WANTED)
                    ಗಚ್ಛ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ಯದಿ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ಅನ್ಯಥಾ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                ಭಙ್ಗ;
            }
            f1 /= f2;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NEG:
            f1 = -f1;
            ಗಚ್ಛ unary_result;
        ಪಕ್ಷ TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ಪ್ರತ್ಯಾಗಮ;
        ಪಕ್ಷ TOK_NE:
            i = f1 != f2;
	    ಗಚ್ಛ make_int;
        ಪಕ್ಷ TOK_LT:
            i = f1 < f2;
	    ಗಚ್ಛ make_int;
        ಪಕ್ಷ TOK_GE:
            i = f1 >= f2;
	    ಗಚ್ಛ make_int;
        ಪಕ್ಷ TOK_LE:
            i = f1 <= f2;
	    ಗಚ್ಛ make_int;
        ಪಕ್ಷ TOK_GT:
            i = f1 > f2;
	    ಗಚ್ಛ make_int;
        ಸ್ವಭಾವ:
            ಗಚ್ಛ general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        ಯದಿ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ಅನ್ಯಥಾ {
            v1->c.ld = f1;
        }
    } ಅನ್ಯಥಾ {
    general_case:
        ಯದಿ (op == TOK_NEG) {
            gen_negf(op);
        } ಅನ್ಯಥಾ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ಸ್ಥಿರ ಶೂನ್ಯ type_to_str(ವರ್ಣ *buf, ಪೂರ್ಣಾಙ್ಕ buf_size,
                 CType *type, ಧ್ರುವ ವರ್ಣ *varstr)
{
    ಪೂರ್ಣಾಙ್ಕ bt, v, t;
    Sym *s, *sa;
    ವರ್ಣ buf1[256];
    ಧ್ರುವ ವರ್ಣ *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ಯದಿ (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    ಯದಿ (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    ಯದಿ (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    ಯದಿ (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    ಯದಿ (bt != VT_PTR) {
        ಯದಿ (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        ಯದಿ (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        ಯದಿ (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    ಯದಿ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    ವಿಕಲ್ಪ(bt) {
    ಪಕ್ಷ VT_VOID:
        tstr = "void";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_BOOL:
        tstr = "_Bool";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_BYTE:
        tstr = "char";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_SHORT:
        tstr = "short";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_INT:
        tstr = "int";
        ಗಚ್ಛ maybe_long;
    ಪಕ್ಷ VT_LLONG:
        tstr = "long long";
    maybe_long:
        ಯದಿ (t & VT_LONG)
            tstr = "long";
        ಯದಿ (!IS_ENUM(t))
            ಗಚ್ಛ add_tstr;
        tstr = "enum ";
        ಗಚ್ಛ tstruct;
    ಪಕ್ಷ VT_FLOAT:
        tstr = "float";
        ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_DOUBLE:
        tstr = "double";
        ಯದಿ (!(t & VT_LONG))
            ಗಚ್ಛ add_tstr;
    ಪಕ್ಷ VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_STRUCT:
        tstr = "struct ";
        ಯದಿ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ಯದಿ (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        ಅನ್ಯಥಾ
            pstrcat(buf, buf_size, get_tok_str(v, ರಿಕ್ತ));
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ಯದಿ (varstr && '*' == *varstr) {
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), "(");
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), varstr);
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), ")");
        }
        pstrcat(buf1, ಪರಿಮಾಣ(buf1), "(");
        sa = s->next;
        ಯಾವತ್ (sa != ರಿಕ್ತ) {
            ವರ್ಣ buf2[256];
            type_to_str(buf2, ಪರಿಮಾಣ(buf2), &sa->type, ರಿಕ್ತ);
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), buf2);
            sa = sa->next;
            ಯದಿ (sa)
                pstrcat(buf1, ಪರಿಮಾಣ(buf1), ", ");
        }
        ಯದಿ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), ", ...");
        pstrcat(buf1, ಪರಿಮಾಣ(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        ಗಚ್ಛ no_var;
    ಪಕ್ಷ VT_PTR:
        s = type->ref;
        ಯದಿ (t & (VT_ARRAY|VT_VLA)) {
            ಯದಿ (varstr && '*' == *varstr)
                snprintf(buf1, ಪರಿಮಾಣ(buf1), "(%s)[%d]", varstr, s->c);
            ಅನ್ಯಥಾ
                snprintf(buf1, ಪರಿಮಾಣ(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            ಗಚ್ಛ no_var;
        }
        pstrcpy(buf1, ಪರಿಮಾಣ(buf1), "*");
        ಯದಿ (t & VT_RESTRICT)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), "restrict ");
        ಯದಿ (t & VT_CONSTANT)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), "const ");
        ಯದಿ (t & VT_VOLATILE)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), "volatile ");
        ಯದಿ (varstr)
            pstrcat(buf1, ಪರಿಮಾಣ(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        ಗಚ್ಛ no_var;
    }
    ಯದಿ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

ಸ್ಥಿರ ಶೂನ್ಯ type_incompatibility_error(CType* st, CType* dt, ಧ್ರುವ ವರ್ಣ* fmt)
{
    ವರ್ಣ buf1[256], buf2[256];
    type_to_str(buf1, ಪರಿಮಾಣ(buf1), st, ರಿಕ್ತ);
    type_to_str(buf2, ಪರಿಮಾಣ(buf2), dt, ರಿಕ್ತ);
    tcc_error(fmt, buf1, buf2);
}

ಸ್ಥಿರ ಶೂನ್ಯ type_incompatibility_warning(CType* st, CType* dt, ಧ್ರುವ ವರ್ಣ* fmt)
{
    ವರ್ಣ buf1[256], buf2[256];
    type_to_str(buf1, ಪರಿಮಾಣ(buf1), st, ರಿಕ್ತ);
    type_to_str(buf2, ಪರಿಮಾಣ(buf2), dt, ರಿಕ್ತ);
    tcc_warning(fmt, buf1, buf2);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pointed_size(CType *type)
{
    ಪೂರ್ಣಾಙ್ಕ align;
    ಪ್ರತ್ಯಾಗಮ type_size(pointed_type(type), &align);
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ is_null_pointer(SValue *p)
{
    ಯದಿ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಪ್ರತ್ಯಾಗಮ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ಯದಿ (s1->f.func_call != s2->f.func_call)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಪ್ರತಿ (;;) {
        ಯದಿ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ಪ್ರತ್ಯಾಗಮ 0;
        ಯದಿ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ಪ್ರತ್ಯಾಗಮ 1;
        s1 = s1->next;
        s2 = s2->next;
        ಯದಿ (!s1)
            ಪ್ರತ್ಯಾಗಮ !s2;
        ಯದಿ (!s2)
            ಪ್ರತ್ಯಾಗಮ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ compare_types(CType *type1, CType *type2, ಪೂರ್ಣಾಙ್ಕ unqualified)
{
    ಪೂರ್ಣಾಙ್ಕ bt1, t1, t2;

    ಯದಿ (IS_ENUM(type1->t)) {
        ಯದಿ (IS_ENUM(type2->t))
            ಪ್ರತ್ಯಾಗಮ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ಅನ್ಯಥಾ ಯದಿ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ಯದಿ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ಯದಿ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ಯದಿ (t1 != t2)
        ಪ್ರತ್ಯಾಗಮ 0;

    ಯದಿ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ಪ್ರತ್ಯಾಗಮ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ಯದಿ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ಯದಿ (unqualified && (t1 & VT_ARRAY))
            ಪ್ರತ್ಯಾಗಮ compare_types(type1, type2, 1);
        ಪ್ರತ್ಯಾಗಮ is_compatible_types(type1, type2);
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_STRUCT) {
        ಪ್ರತ್ಯಾಗಮ (type1->ref == type2->ref);
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_FUNC) {
        ಪ್ರತ್ಯಾಗಮ is_compatible_func(type1, type2);
    } ಅನ್ಯಥಾ {
        ಪ್ರತ್ಯಾಗಮ 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ combine_types(CType *dest, SValue *op1, SValue *op2, ಪೂರ್ಣಾಙ್ಕ op)
{
    CType *type1, *type2, type;
    ಪೂರ್ಣಾಙ್ಕ t1, t2, bt1, bt2;
    ಪೂರ್ಣಾಙ್ಕ ret = 1;

    /* for shifts, 'combine' only left operand */
    ಯದಿ (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ರಿಕ್ತ;

    ಯದಿ (bt1 == VT_VOID || bt2 == VT_VOID) {
        ಯದಿ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_PTR || bt2 == VT_PTR) {
        ಯದಿ (op == '+') {
          ಯದಿ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ಅನ್ಯಥಾ ಯದಿ (is_null_pointer (op2)) type = *type1;
        ಅನ್ಯಥಾ ಯದಿ (is_null_pointer (op1)) type = *type2;
        ಅನ್ಯಥಾ ಯದಿ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ಯದಿ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ಅನ್ಯಥಾ ಯದಿ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ಅನ್ಯಥಾ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            ಪೂರ್ಣಾಙ್ಕ pbt1 = pt1->t & VT_BTYPE;
            ಪೂರ್ಣಾಙ್ಕ pbt2 = pt2->t & VT_BTYPE;
            ಪೂರ್ಣಾಙ್ಕ newquals, copied = 0;
            ಯದಿ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ಯದಿ (op != '?' && op != CMP_OP)
                  ret = 0;
                ಅನ್ಯಥಾ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ಯದಿ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ಯದಿ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ತಳ್ಳು(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ಯದಿ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ಯದಿ (!copied)
                      type.ref = sym_ತಳ್ಳು(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ತಳ್ಳು(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ಯದಿ (op == CMP_OP)
          type.t = VT_SIZE_T;
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ಯದಿ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ಅನ್ಯಥಾ ಯದಿ (is_float(bt1) || is_float(bt2)) {
        ಯದಿ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ಅನ್ಯಥಾ {
            type.t = VT_FLOAT;
        }
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ಯದಿ (bt1 == VT_LLONG)
          type.t &= t1;
        ಯದಿ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ಯದಿ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ಅನ್ಯಥಾ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ಯದಿ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ಯದಿ (dest)
      *dest = type;
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC ಶೂನ್ಯ gen_op(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ t1, t2, bt1, bt2, t;
    CType type1, combtype;
    ಪೂರ್ಣಾಙ್ಕ op_class = op;

    ಯದಿ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    ಅನ್ಯಥಾ ಯದಿ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ಯದಿ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ಯದಿ (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	ಯದಿ (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	ಗಚ್ಛ redo;
    } ಅನ್ಯಥಾ ಯದಿ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ಅನ್ಯಥಾ ಯದಿ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        ಪೂರ್ಣಾಙ್ಕ align;
        ಯದಿ (op_class == CMP_OP)
            ಗಚ್ಛ std_op;
        /* if both pointers, then it must be the '-' op */
        ಯದಿ (bt1 == VT_PTR && bt2 == VT_PTR) {
            ಯದಿ (op != '-')
                ಗಚ್ಛ op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ಅನ್ಯಥಾ {
            /* exactly one pointer : must be '+' or '-'. */
            ಯದಿ (op != '-' && op != '+')
                ಗಚ್ಛ op_err;
            /* Put pointer as first operand */
            ಯದಿ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ಯದಿ PTR_SIZE == 4
            ಯದಿ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            ಯದಿ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ಯದಿ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } ಅನ್ಯಥಾ
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ಅನ್ಯಥಾ {
        /* floats can only be used for a few operations */
        ಯದಿ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            ಗಚ್ಛ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ಯದಿ (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ಯದಿ (t & VT_UNSIGNED) {
            ಯದಿ (op == TOK_SAR)
                op = TOK_SHR;
            ಅನ್ಯಥಾ ಯದಿ (op == '/')
                op = TOK_UDIV;
            ಅನ್ಯಥಾ ಯದಿ (op == '%')
                op = TOK_UMOD;
            ಅನ್ಯಥಾ ಯದಿ (op == TOK_LT)
                op = TOK_ULT;
            ಅನ್ಯಥಾ ಯದಿ (op == TOK_GT)
                op = TOK_UGT;
            ಅನ್ಯಥಾ ಯದಿ (op == TOK_LE)
                op = TOK_ULE;
            ಅನ್ಯಥಾ ಯದಿ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ಯದಿ (is_float(t))
            gen_opif(op);
        ಅನ್ಯಥಾ
            gen_opic(op);
        ಯದಿ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ಅನ್ಯಥಾ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ಯದಿ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ಯದಿ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#ಅನ್ಯಥಾ
/* generic itof for unsigned long long case */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cvt_itof1(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಯದಿ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ಯದಿ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ಯದಿ LDOUBLE_SIZE != 8
        ಅನ್ಯಥಾ ಯದಿ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        ಅನ್ಯಥಾ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ಅನ್ಯಥಾ {
        gen_cvt_itof(t);
    }
}
#endif

#ಯದಿ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#ಅನ್ಯಥಾ
/* generic ftoi for unsigned long long case */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cvt_ftoi1(ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ st;
    ಯದಿ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ಯದಿ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ಯದಿ LDOUBLE_SIZE != 8
        ಅನ್ಯಥಾ ಯದಿ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        ಅನ್ಯಥಾ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ಅನ್ಯಥಾ {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
ಸ್ಥಿರ ಶೂನ್ಯ force_charshort_cast(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    ಪೂರ್ಣಾಙ್ಕ dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_cast_s(ಪೂರ್ಣಾಙ್ಕ t)
{
    CType type;
    type.t = t;
    type.ref = ರಿಕ್ತ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cast(CType *type)
{
    ಪೂರ್ಣಾಙ್ಕ sbt, dbt, sf, df, c;
    ಪೂರ್ಣಾಙ್ಕ dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    ಯದಿ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ಯದಿ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ಯದಿ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ಯದಿ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ಯದಿ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ಯದಿ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            ಗಚ್ಛ done;
        }
        ಯದಿ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ಯದಿ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ಯದಿ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ಅನ್ಯಥಾ ಯದಿ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ಯದಿ (df) {
                ಯದಿ (sbt_bt == VT_LLONG) {
                    ಯದಿ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ಅನ್ಯಥಾ
                        vtop->c.ld = -(long ದ್ವಿಗುಣ)-vtop->c.i;
                } ಅನ್ಯಥಾ ಯದಿ(!sf) {
                    ಯದಿ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ಅನ್ಯಥಾ
                        vtop->c.ld = -(long ದ್ವಿಗುಣ)-(uint32_t)vtop->c.i;
                }

                ಯದಿ (dbt == VT_FLOAT)
                    vtop->c.f = (ಭಿನ್ನ)vtop->c.ld;
                ಅನ್ಯಥಾ ಯದಿ (dbt == VT_DOUBLE)
                    vtop->c.d = (ದ್ವಿಗುಣ)vtop->c.ld;
            } ಅನ್ಯಥಾ ಯದಿ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ಅನ್ಯಥಾ {
                ಯದಿ(sf) {
                    ಯದಿ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ಅನ್ಯಥಾ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ಅನ್ಯಥಾ ಯದಿ (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                ಅನ್ಯಥಾ ಯದಿ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ಅನ್ಯಥಾ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ಯದಿ (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                ಅನ್ಯಥಾ ಯದಿ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ಅನ್ಯಥಾ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ಯದಿ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            ಗಚ್ಛ done;

        } ಅನ್ಯಥಾ ಯದಿ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            ಗಚ್ಛ done;
        }

        /* cannot generate code for global or static initializers */
        ಯದಿ (nocode_wanted & DATA_ONLY_WANTED) {
            ಯದಿ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            ಗಚ್ಛ done;
        }

        /* non constant case: generate code */
        ಯದಿ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            ಗಚ್ಛ done;
        }

        ಯದಿ (sf || df) {
            ಯದಿ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ಅನ್ಯಥಾ ಯದಿ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ಅನ್ಯಥಾ {
                /* convert fp to int */
                sbt = dbt;
                ಯದಿ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                ಗಚ್ಛ again; /* may need char/short cast */
            }
            ಗಚ್ಛ done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        ಯದಿ (ds == 0 || ss == 0)
            ಗಚ್ಛ error;

        /* same size and no sign conversion needed */
        ಯದಿ (ds == ss && ds >= 4)
            ಗಚ್ಛ done;
        ಯದಿ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ಯದಿ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        ಯದಿ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ಯದಿ (ds <= ss)
                ಗಚ್ಛ done;
            /* ss <= 4 here */
            ಯದಿ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                ಗಚ್ಛ done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ಯದಿ PTR_SIZE == 4
        ಯದಿ (ds == 8) {
            /* generate high word */
            ಯದಿ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ಅನ್ಯಥಾ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ಅನ್ಯಥಾ ಯದಿ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#ನೋಚೇದ್ಯದಿ PTR_SIZE == 8
        ಯದಿ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ಯದಿ (sbt & VT_UNSIGNED) {
#ಯದಿ defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ಅನ್ಯಥಾ
                ಗಚ್ಛ done;
#endif
            } ಅನ್ಯಥಾ {
                gen_cvt_sxtw();
                ಗಚ್ಛ done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ಅನ್ಯಥಾ ಯದಿ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ಯದಿ !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } ಅನ್ಯಥಾ {
            ss = 4;
        }
#endif

        ಯದಿ (ds >= ss)
            ಗಚ್ಛ done;
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ಯದಿ (ss == 4) {
        gen_cvt_csti(dbt);
        ಗಚ್ಛ done;
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
ST_FUNC ಪೂರ್ಣಾಙ್ಕ type_size(CType *type, ಪೂರ್ಣಾಙ್ಕ *a)
{
    Sym *s;
    ಪೂರ್ಣಾಙ್ಕ bt;

    bt = type->t & VT_BTYPE;
    ಯದಿ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ಪ್ರತ್ಯಾಗಮ s->c;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_PTR) {
        ಯದಿ (type->t & VT_ARRAY) {
            ಪೂರ್ಣಾಙ್ಕ ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            ಯದಿ (s->c < 0)
                ಪ್ರತ್ಯಾಗಮ s->c;
            ಪ್ರತ್ಯಾಗಮ ts * s->c;
        } ಅನ್ಯಥಾ {
            *a = PTR_SIZE;
            ಪ್ರತ್ಯಾಗಮ PTR_SIZE;
        }
    } ಅನ್ಯಥಾ ಯದಿ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ಪ್ರತ್ಯಾಗಮ -1; /* incomplete enum */
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ಪ್ರತ್ಯಾಗಮ LDOUBLE_SIZE;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_DOUBLE || bt == VT_LLONG) {
#ಯದಿ (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ಅನ್ಯಥಾ
        *a = 8;
#endif
        ಪ್ರತ್ಯಾಗಮ 8;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ಪ್ರತ್ಯಾಗಮ 4;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_SHORT) {
        *a = 2;
        ಪ್ರತ್ಯಾಗಮ 2;
    } ಅನ್ಯಥಾ ಯದಿ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ಪ್ರತ್ಯಾಗಮ 16;
    } ಅನ್ಯಥಾ {
        /* char, void, function, _Bool */
        *a = 1;
        ಪ್ರತ್ಯಾಗಮ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ಸ್ಥಿರ ಶೂನ್ಯ vpush_type_size(CType *type, ಪೂರ್ಣಾಙ್ಕ *a)
{
    ಯದಿ (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ಅನ್ಯಥಾ {
        ಪೂರ್ಣಾಙ್ಕ size = type_size(type, a);
        ಯದಿ (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ CType *pointed_type(CType *type)
{
    ಪ್ರತ್ಯಾಗಮ &type->ref->type;
}

ಸ್ಥಿರ ಶೂನ್ಯ check_restrict_type(CType *type)
{
    ಯಾವತ್ ((type->t & VT_BTYPE) == VT_PTR) {
        ಯದಿ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ಯದಿ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ type_qualifiers(CType *type)
{
    ಯಾವತ್ (type->t & VT_ARRAY)
        type = pointed_type(type);
    ಪ್ರತ್ಯಾಗಮ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC ಶೂನ್ಯ mk_pointer(CType *type)
{
    Sym *s;
    s = sym_ತಳ್ಳು(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_compatible_types(CType *type1, CType *type2)
{
    ಪ್ರತ್ಯಾಗಮ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ಪ್ರತ್ಯಾಗಮ compare_types(type1,type2,1);
}

ಸ್ಥಿರ ಶೂನ್ಯ cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ಸ್ಥಿರ ಶೂನ್ಯ verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    ಪೂರ್ಣಾಙ್ಕ dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ಯದಿ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    ವಿಕಲ್ಪ(dbt) {
    ಪಕ್ಷ VT_VOID:
        ಯದಿ (sbt != dbt)
            tcc_error("assignment to void expression");
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ಯದಿ (is_null_pointer(vtop))
            ಭಙ್ಗ;
        /* accept implicit pointer to integer cast with warning */
        ಯದಿ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            ಭಙ್ಗ;
        }
        type1 = pointed_type(dt);
        ಯದಿ (sbt == VT_PTR)
            type2 = pointed_type(st);
        ಅನ್ಯಥಾ ಯದಿ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ಅನ್ಯಥಾ
            ಗಚ್ಛ error;
        ಯದಿ (is_compatible_types(type1, type2))
            ಭಙ್ಗ;
        ಪ್ರತಿ (qualwarn = lvl = 0;; ++lvl) {
            ಯದಿ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ಯದಿ (dbt != VT_PTR || sbt != VT_PTR)
                ಭಙ್ಗ;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ಯದಿ (!is_compatible_unqualified_types(type1, type2)) {
            ಯದಿ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ಅನ್ಯಥಾ ಯದಿ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ಅನ್ಯಥಾ {
                tcc_warning("assignment from incompatible pointer type");
                ಭಙ್ಗ;
            }
        }
        ಯದಿ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_BYTE:
    ಪಕ್ಷ VT_SHORT:
    ಪಕ್ಷ VT_INT:
    ಪಕ್ಷ VT_LLONG:
        ಯದಿ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ಅನ್ಯಥಾ ಯದಿ (sbt == VT_STRUCT) {
            ಗಚ್ಛ case_VT_STRUCT;
        }
        /* XXX: more tests */
        ಭಙ್ಗ;
    ಪಕ್ಷ VT_STRUCT:
    case_VT_STRUCT:
        ಯದಿ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        ಭಙ್ಗ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC ಶೂನ್ಯ vstore(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    ಯದಿ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        ಯದಿ (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } ಅನ್ಯಥಾ
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            ಯದಿ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ಅನ್ಯಥಾ ಯದಿ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ಅನ್ಯಥಾ
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ಅನ್ಯಥಾ ಯದಿ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        ಯದಿ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        ಯದಿ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ಯದಿ (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } ಅನ್ಯಥಾ {
            unsigned long long mask = (1ULL << bit_size) - 1;
            ಯದಿ (dbt != VT_BOOL) {
                /* mask source */
                ಯದಿ (dbt == VT_LLONG)
                    vpushll(mask);
                ಅನ್ಯಥಾ
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
            ಯದಿ (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            ಅನ್ಯಥಾ
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ಅನ್ಯಥಾ ಯದಿ (dbt == VT_VOID) {
        --vtop;
    } ಅನ್ಯಥಾ {
            /* optimize char/short casts */
            delayed_cast = 0;
            ಯದಿ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ಯದಿ ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ಅನ್ಯಥಾ {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            ಯದಿ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            ಯದಿ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ಯದಿ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ರಿಕ್ತ;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ಯದಿ (USING_TWO_ಪದಗಳು(dbt)) {
                ಪೂರ್ಣಾಙ್ಕ load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ಅನ್ಯಥಾ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC ಶೂನ್ಯ inc(ಪೂರ್ಣಾಙ್ಕ post, ಪೂರ್ಣಾಙ್ಕ c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ಯದಿ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ಯದಿ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
    /* read the string */
    ಯದಿ (tok != TOK_STR)
        expect(ಸಂದೇಶ);
    cstr_reset(&initstr);
    ಯಾವತ್ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    ಪ್ರತ್ಯಾಗಮ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ exact_log2p1(ಪೂರ್ಣಾಙ್ಕ i)
{
  ಪೂರ್ಣಾಙ್ಕ ret;
  ಯದಿ (!i)
    ಪ್ರತ್ಯಾಗಮ 0;
  ಪ್ರತಿ (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ಯದಿ (i >= 1 << 4)
    ret += 4, i >>= 4;
  ಯದಿ (i >= 1 << 2)
    ret += 2, i >>= 2;
  ಯದಿ (i >= 1 << 1)
    ret++;
  ಪ್ರತ್ಯಾಗಮ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_attribute(AttributeDef *ad)
{
    ಪೂರ್ಣಾಙ್ಕ t, n;
    ವರ್ಣ *astr;
    AttributeDef ad_tmp;
    
redo:
    ಯದಿ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (ರಿಕ್ತ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    ಯಾವತ್ (tok != ')') {
        ಯದಿ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        ವಿಕಲ್ಪ(t) {
	ಪಕ್ಷ TOK_CLEANUP1:
	ಪಕ್ಷ TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    ಯದಿ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ಅನ್ಯಥಾ ಯದಿ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    ಭಙ್ಗ;
	}
        ಪಕ್ಷ TOK_CONSTRUCTOR1:
        ಪಕ್ಷ TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_DESTRUCTOR1:
        ಪಕ್ಷ TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ALWAYS_INLINE1:
        ಪಕ್ಷ TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SECTION1:
        ಪಕ್ಷ TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ALIAS1:
        ಪಕ್ಷ TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            ಭಙ್ಗ;
	ಪಕ್ಷ TOK_VISIBILITY1:
	ಪಕ್ಷ TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    ಯದಿ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ಅನ್ಯಥಾ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ALIGNED1:
        ಪಕ್ಷ TOK_ALIGNED2:
            ಯದಿ (tok == '(') {
                next();
                n = ಅಭಿವ್ಯಕ್ತಿ_const();
                ಯದಿ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ಅನ್ಯಥಾ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ಯದಿ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_PACKED1:
        ಪಕ್ಷ TOK_PACKED2:
            ad->a.packed = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_WEAK1:
        ಪಕ್ಷ TOK_WEAK2:
            ad->a.weak = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NODEBUG1:
        ಪಕ್ಷ TOK_NODEBUG2:
            ad->a.nodebug = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_USED1:
        ಪಕ್ಷ TOK_USED2:
        ಪಕ್ಷ TOK_UNUSED1:
        ಪಕ್ಷ TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_CONST1:
        ಪಕ್ಷ TOK_CONST2:
        ಪಕ್ಷ TOK_CONST3:
        ಪಕ್ಷ TOK_PURE1:
        ಪಕ್ಷ TOK_PURE2:
	    /* ignored */
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NOINLINE:
	    /* ignored */
	    ಭಙ್ಗ;
        ಪಕ್ಷ TOK_FORMAT1:
        ಪಕ್ಷ TOK_FORMAT2:
	    /* ignored */
            ಗಚ್ಛ skip_param;
        ಪಕ್ಷ TOK_NORETURN1:
        ಪಕ್ಷ TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_CDECL1:
        ಪಕ್ಷ TOK_CDECL2:
        ಪಕ್ಷ TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_STDCALL1:
        ಪಕ್ಷ TOK_STDCALL2:
        ಪಕ್ಷ TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            ಭಙ್ಗ;
#ifdef TCC_TARGET_I386
        ಪಕ್ಷ TOK_REGPARM1:
        ಪಕ್ಷ TOK_REGPARM2:
            skip('(');
            n = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಯದಿ (n > 3) 
                n = 3;
            ಅನ್ಯಥಾ ಯದಿ (n < 0)
                n = 0;
            ಯದಿ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_FASTCALL1:
        ಪಕ್ಷ TOK_FASTCALL2:
        ಪಕ್ಷ TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_THISCALL1:
        ಪಕ್ಷ TOK_THISCALL2:
        ಪಕ್ಷ TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            ಭಙ್ಗ;
#endif
        ಪಕ್ಷ TOK_MODE:
            skip('(');
            ವಿಕಲ್ಪ(tok) {
                ಪಕ್ಷ TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    ಭಙ್ಗ;
                ಪಕ್ಷ TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    ಭಙ್ಗ;
                ಪಕ್ಷ TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    ಭಙ್ಗ;
                ಪಕ್ಷ TOK_MODE_SI:
                ಪಕ್ಷ TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    ಭಙ್ಗ;
                ಸ್ವಭಾವ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ರಿಕ್ತ));
                    ಭಙ್ಗ;
            }
            next();
            skip(')');
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NODECORATE:
            ad->a.nodecorate = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ರಿಕ್ತ));
            /* skip parameters */
skip_param:
            ಯದಿ (tok == '(') {
                ಪೂರ್ಣಾಙ್ಕ parenthesis = 0;
                ಕುರು {
                    ಯದಿ (tok == '(') 
                        parenthesis++;
                    ಅನ್ಯಥಾ ಯದಿ (tok == ')') 
                        parenthesis--;
                    next();
                } ಯಾವತ್ (parenthesis && tok != -1);
            }
            ಭಙ್ಗ;
        }
        ಯದಿ (tok != ',')
            ಭಙ್ಗ;
        next();
    }
    skip(')');
    skip(')');
    ಗಚ್ಛ redo;
}

ಸ್ಥಿರ Sym * find_field (CType *type, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ *cumofs)
{
    Sym *s = type->ref;
    ಪೂರ್ಣಾಙ್ಕ v1 = v | SYM_FIELD;
    ಯದಿ (!(v & SYM_FIELD)) { /* top-level call */
        ಯದಿ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ಯದಿ (v < TOK_UIDENT)
            expect("field name");
        ಯದಿ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ಯಾವತ್ ((s = s->next) != ರಿಕ್ತ) {
        ಯದಿ (s->v == v1) {
            *cumofs = s->c;
            ಪ್ರತ್ಯಾಗಮ s;
        }
        ಯದಿ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            ಯದಿ (ret) {
                *cumofs += s->c;
                ಪ್ರತ್ಯಾಗಮ ret;
            }
        }
    }
    ಯದಿ (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, ರಿಕ್ತ));
    ಪ್ರತ್ಯಾಗಮ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ check_fields (CType *type, ಪೂರ್ಣಾಙ್ಕ check)
{
    Sym *s = type->ref;

    ಯಾವತ್ ((s = s->next) != ರಿಕ್ತ) {
        ಪೂರ್ಣಾಙ್ಕ v = s->v & ~SYM_FIELD;
        ಯದಿ (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            ಯದಿ (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, ರಿಕ್ತ));
            ts->tok ^= SYM_FIELD;
        } ಅನ್ಯಥಾ ಯದಿ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ struct_layout(CType *type, AttributeDef *ad)
{
    ಪೂರ್ಣಾಙ್ಕ size, align, maxalign, offset, c, bit_pos, bit_size;
    ಪೂರ್ಣಾಙ್ಕ packed, a, bt, prevbt, prev_bit_size;
    ಪೂರ್ಣಾಙ್ಕ pcc = !tcc_state->ms_bitfields;
    ಪೂರ್ಣಾಙ್ಕ pragma_pack = *tcc_state->pack_ರಾಶಿ_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    ಪ್ರತಿ (f = type->ref->next; f; f = f->next) {
        ಯದಿ (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        ಅನ್ಯಥಾ
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ಯದಿ (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ಅನ್ಯಥಾ {
            /* in pcc mode, attribute packed overrides if set. */
            ಯದಿ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ಯದಿ (pragma_pack) {
                packed = 1;
                ಯದಿ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ಯದಿ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ಯದಿ (a)
            align = a;

        ಯದಿ (type->ref->type.t == VT_UNION) {
	    ಯದಿ (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    ಯದಿ (size > c)
	        c = size;

	} ಅನ್ಯಥಾ ಯದಿ (bit_size < 0) {
            ಯದಿ (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    ಯದಿ (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} ಅನ್ಯಥಾ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ಯದಿ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ಯದಿ (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } ಅನ್ಯಥಾ ಯದಿ (f->a.aligned) {
                    ಗಚ್ಛ new_field;
                } ಅನ್ಯಥಾ ಯದಿ (!packed) {
                    ಪೂರ್ಣಾಙ್ಕ a8 = align * 8;
	            ಪೂರ್ಣಾಙ್ಕ ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    ಯದಿ (ofs > size / align)
                        ಗಚ್ಛ new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ಯದಿ (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                ಯಾವತ್ (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ಯದಿ (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ಅನ್ಯಥಾ {
		bt = f->type.t & VT_BTYPE;
		ಯದಿ ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ಯದಿ (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ಯದಿ (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	ಯದಿ (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, ರಿಕ್ತ), offset, size, align);
	ಯದಿ (f->type.t & VT_BITFIELD) {
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

    ಯದಿ (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ಯದಿ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ಯದಿ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ಯದಿ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    ಪ್ರತಿ (f = type->ref->next; f; f = f->next) {
        ಪೂರ್ಣಾಙ್ಕ s, px, cx, c0;
        CType t;

        ಯದಿ (0 == (f->type.t & VT_BITFIELD))
            ಅನುವರ್ತ;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        ಯದಿ (bit_size == 0)
            ಅನುವರ್ತ;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        ಯದಿ (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            ಅನುವರ್ತ;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        ಪ್ರತಿ (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ಯದಿ (c0 == cx)
                ಭಙ್ಗ;
            s = (px + bit_size + 7) >> 3;
            ಯದಿ (s > 4) {
                t.t = VT_LLONG;
            } ಅನ್ಯಥಾ ಯದಿ (s > 2) {
                t.t = VT_INT;
            } ಅನ್ಯಥಾ ಯದಿ (s > 1) {
                t.t = VT_SHORT;
            } ಅನ್ಯಥಾ {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        ಯದಿ (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            ಯದಿ (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, ರಿಕ್ತ),
                cx, s, align, px, bit_size);
#endif
        } ಅನ್ಯಥಾ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, ರಿಕ್ತ));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ in_range(long long n, ಪೂರ್ಣಾಙ್ಕ t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    ಯದಿ (t & VT_UNSIGNED)
        ಪ್ರತ್ಯಾಗಮ n <= (m << 1) + 1;
    ಪ್ರತ್ಯಾಗಮ n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ಸ್ಥಿರ ಶೂನ್ಯ struct_decl(CType *type, ಪೂರ್ಣಾಙ್ಕ u)
{
    ಪೂರ್ಣಾಙ್ಕ v, c, size, align, flexible;
    ಪೂರ್ಣಾಙ್ಕ bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, ಪರಿಮಾಣ ad);
    next();
    parse_attribute(&ad);

    v = 0;
    ಯದಿ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    ಯದಿ (u == VT_ENUM) {
        ut = VT_INT;
        ಯದಿ (tok == ':') { /* C2x enum : <type> ... */
            next();
            ಯದಿ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ಯದಿ (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        ಯದಿ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ಯದಿ (u == s->type.t)
                ಗಚ್ಛ do_decl;
            ಯದಿ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                ಗಚ್ಛ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ರಿಕ್ತ));
        }
    } ಅನ್ಯಥಾ {
        ಯದಿ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ರಿಕ್ತ;
    /* we put an undefined size for struct/union */
    s = sym_ತಳ್ಳು(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ಯದಿ (tok == '{') {
        next();
        ಯದಿ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        ಯದಿ (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ಯದಿ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            ಪ್ರತಿ(;;) {
                v = tok;
                ಯದಿ (v < TOK_UIDENT)
                    expect("identifier");
                next();
                ಯದಿ (tok == '=') {
                    next();
		    ll = ಅಭಿವ್ಯಕ್ತಿ_const64();
                }
                ಯದಿ (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ರಿಕ್ತ));
                ss = sym_ತಳ್ಳು(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                ಯದಿ (ll < nl)
                    nl = ll;
                ಯದಿ (ll > pl)
                    pl = ll;
                ಯದಿ (tok != ',')
                    ಭಙ್ಗ;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                ಯದಿ (tok == '}')
                    ಭಙ್ಗ;
            }
            skip('}');

            ಯದಿ (bt) {
                t.t = bt;
                s->c = 2;
                ಗಚ್ಛ enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ಯದಿ (nl >= 0) {
                ಯದಿ (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ಅನ್ಯಥಾ ಯದಿ (pl != (ಪೂರ್ಣಾಙ್ಕ)pl || nl != (ಪೂರ್ಣಾಙ್ಕ)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            ಪ್ರತಿ (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                ಯದಿ (ll == (ಪೂರ್ಣಾಙ್ಕ)ll) /* default is int if it fits */
                    ಅನುವರ್ತ;
                ಯದಿ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ಯದಿ (ll == (unsigned)ll)
                        ಅನುವರ್ತ;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } ಅನ್ಯಥಾ {
            c = 0;
            flexible = 0;
            ಯಾವತ್ (tok != '}') {
                ಯದಿ (!parse_btype(&btype, &ad1, 0)) {
                    ಯದಿ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ಅನುವರ್ತ;
                    }
		    skip(';');
		    ಅನುವರ್ತ;
		}
                ಯಾವತ್ (1) {
		    ಯದಿ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ರಿಕ್ತ));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    ಯದಿ (tok != ':') {
			ಯದಿ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        ಯದಿ (v == 0) {
                    	    ಯದಿ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ಅನ್ಯಥಾ {
				ಪೂರ್ಣಾಙ್ಕ v = btype.ref->v;
				ಯದಿ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    ಯದಿ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ಯದಿ (type_size(&type1, &align) < 0) {
			    ಯದಿ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ಅನ್ಯಥಾ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ರಿಕ್ತ));
                        }
                        ಯದಿ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ರಿಕ್ತ));
                    }
                    ಯದಿ (tok == ':') {
                        next();
                        bit_size = ಅಭಿವ್ಯಕ್ತಿ_const();
                        /* XXX: handle v = 0 case for messages */
                        ಯದಿ (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ರಿಕ್ತ));
                        ಯದಿ (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ರಿಕ್ತ));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    ಯದಿ (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ಯದಿ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        ಯದಿ (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ರಿಕ್ತ));
                        } ಅನ್ಯಥಾ ಯದಿ (bit_size == bsize
				    && !*tcc_state->pack_ರಾಶಿ_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ಅನ್ಯಥಾ ಯದಿ (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } ಅನ್ಯಥಾ {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    ಯದಿ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ಯದಿ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    ಯದಿ (v) {
                        ss = sym_ತಳ್ಳು(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    ಯದಿ (tok == ';' || tok == TOK_EOF)
                        ಭಙ್ಗ;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ಯದಿ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ಯದಿ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_btype_qualify(CType *type, ಪೂರ್ಣಾಙ್ಕ qualifiers)
{
    ಯಾವತ್ (type->t & VT_ARRAY) {
        type->ref = sym_ತಳ್ಳು(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ಯದಿ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_btype(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ ignore_label)
{
    ಪೂರ್ಣಾಙ್ಕ t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, ಪರಿಮಾಣ(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ರಿಕ್ತ;

    ಯಾವತ್(1) {
        ವಿಕಲ್ಪ(tok) {
        ಪಕ್ಷ TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            ಅನುವರ್ತ;

            /* basic types */
        ಪಕ್ಷ TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            ಯದಿ (u == VT_SHORT || u == VT_LONG) {
                ಯದಿ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ಅನ್ಯಥಾ {
                ಯದಿ (bt != -1 || (st != -1 && u != VT_INT))
                    ಗಚ್ಛ tmbt;
                ಯದಿ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    ಗಚ್ಛ tmbt;
                bt = u;
            }
            ಯದಿ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_VOID:
            u = VT_VOID;
            ಗಚ್ಛ basic_type;
        ಪಕ್ಷ TOK_SHORT:
            u = VT_SHORT;
            ಗಚ್ಛ basic_type;
        ಪಕ್ಷ TOK_INT:
            u = VT_INT;
            ಗಚ್ಛ basic_type;
        ಪಕ್ಷ TOK_ALIGNAS:
            { ಪೂರ್ಣಾಙ್ಕ n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, ಪರಿಮಾಣ(AttributeDef));
              ಯದಿ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ಯದಿ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ಅನ್ಯಥಾ
                    type_size(&type1, &n);
              } ಅನ್ಯಥಾ {
                  n = ಅಭಿವ್ಯಕ್ತಿ_const();
                  ಯದಿ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ಅನುವರ್ತ;
        ಪಕ್ಷ TOK_LONG:
            ಯದಿ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ಅನ್ಯಥಾ ಯದಿ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ಅನ್ಯಥಾ {
                u = VT_LONG;
                ಗಚ್ಛ basic_type;
            }
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_BOOL:
            u = VT_BOOL;
            ಗಚ್ಛ basic_type;
        ಪಕ್ಷ TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        ಪಕ್ಷ TOK_FLOAT:
            u = VT_FLOAT;
            ಗಚ್ಛ basic_type;
        ಪಕ್ಷ TOK_DOUBLE:
            ಯದಿ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ಅನ್ಯಥಾ {
                u = VT_DOUBLE;
                ಗಚ್ಛ basic_type;
            }
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            ಗಚ್ಛ basic_type1;
        ಪಕ್ಷ TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            ಗಚ್ಛ basic_type2;
        ಪಕ್ಷ TOK_UNION:
            struct_decl(&type1, VT_UNION);
            ಗಚ್ಛ basic_type2;

            /* type modifiers */
        ಪಕ್ಷ TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ಯದಿ (tok == '(') {
                parse_ಅಭಿವ್ಯಕ್ತಿ_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ಯದಿ (type1.ref)
                    sym_to_attr(ad, type1.ref);
                ಗಚ್ಛ basic_type2;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_CONST1:
        ಪಕ್ಷ TOK_CONST2:
        ಪಕ್ಷ TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_VOLATILE1:
        ಪಕ್ಷ TOK_VOLATILE2:
        ಪಕ್ಷ TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SIGNED1:
        ಪಕ್ಷ TOK_SIGNED2:
        ಪಕ್ಷ TOK_SIGNED3:
            ಯದಿ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_RESTRICT1:
        ಪಕ್ಷ TOK_RESTRICT2:
        ಪಕ್ಷ TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_REGISTER:
        ಪಕ್ಷ TOK_AUTO:
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_UNSIGNED:
            ಯದಿ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            ಭಙ್ಗ;

            /* storage */
        ಪಕ್ಷ TOK_EXTERN:
            g = VT_EXTERN;
            ಗಚ್ಛ storage;
        ಪಕ್ಷ TOK_STATIC:
            g = VT_STATIC;
            ಗಚ್ಛ storage;
        ಪಕ್ಷ TOK_TYPEDEF:
            g = VT_TYPEDEF;
            ಗಚ್ಛ storage;
       storage:
            ಯದಿ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_INLINE1:
        ಪಕ್ಷ TOK_INLINE2:
        ಪಕ್ಷ TOK_INLINE3:
            t |= VT_INLINE;
            next();
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            ಭಙ್ಗ;
            /* GNUC attribute */
        ಪಕ್ಷ TOK_ATTRIBUTE1:
        ಪಕ್ಷ TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ಯದಿ (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ಅನುವರ್ತ;
            /* GNUC typeof */
        ಪಕ್ಷ TOK_TYPEOF1:
        ಪಕ್ಷ TOK_TYPEOF2:
        ಪಕ್ಷ TOK_TYPEOF3:
            next();
            parse_ಅಭಿವ್ಯಕ್ತಿ_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ಯದಿ (type1.ref) {
                sym_to_attr(ad, type1.ref);
                ಯದಿ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            ಗಚ್ಛ basic_type2;
        ಪಕ್ಷ TOK_THREAD_LOCAL:
        ಪಕ್ಷ TOK___thread:
            ಯದಿ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಯದಿ (typespec_found)
                ಗಚ್ಛ the_end;
            s = sym_find(tok);
            ಯದಿ (!s || !(s->type.t & VT_TYPEDEF))
                ಗಚ್ಛ the_end;

            n = tok, next();
            ಯದಿ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                ಗಚ್ಛ the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ಯದಿ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ಯದಿ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            ಭಙ್ಗ;
        }
        type_found = 1;
    }
the_end:
    ಯದಿ (tcc_state->char_is_unsigned) {
        ಯದಿ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ಯದಿ (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    ಯದಿ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    ಪ್ರತ್ಯಾಗಮ type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ಯದಿ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(ಶೂನ್ಯ)
{
    skip('(');
    ಪ್ರತ್ಯಾಗಮ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_label_instr(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v;
    ವರ್ಣ *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    ಪ್ರತ್ಯಾಗಮ v;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ post_type(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ storage, ಪೂರ್ಣಾಙ್ಕ td)
{
    ಪೂರ್ಣಾಙ್ಕ n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ *vla_array_str = ರಿಕ್ತ;

    ಯದಿ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	ಯದಿ (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  ಪ್ರತ್ಯಾಗಮ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ರಾಶಿ ? &local_ರಾಶಿ : &global_ರಾಶಿ;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	ಯದಿ (tok == ')')
	  l = 0;
	ಅನ್ಯಥಾ ಯದಿ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ಅನ್ಯಥಾ ಯದಿ (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_ತೆಗೆ(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    ಪ್ರತ್ಯಾಗಮ 0;
	} ಅನ್ಯಥಾ
	  l = FUNC_OLD;

        first = ರಿಕ್ತ;
        plast = &first;
        arg_size = 0;
        ಯದಿ (l) {
            ಪ್ರತಿ(;;) {
                /* read param name and compute offset */
                ಯದಿ (l != FUNC_OLD) {
                    ಯದಿ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        ಭಙ್ಗ;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    ಯದಿ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ಯದಿ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } ಅನ್ಯಥಾ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ರಿಕ್ತ;
                    next();
                }
                ಯದಿ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ತಳ್ಳು(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                ಯದಿ (tok == ')')
                    ಭಙ್ಗ;
                skip(',');
                ಯದಿ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    ಭಙ್ಗ;
                }
		ಯದಿ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ಅನ್ಯಥಾ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ಯದಿ (tok == '[') {
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
        sym_ತೆಗೆ(ps, sr, 1);
        --local_scope;

    } ಅನ್ಯಥಾ ಯದಿ (tok == '[') {
	ಪೂರ್ಣಾಙ್ಕ saved_nocode_wanted = nocode_wanted;
        ಪೂರ್ಣಾಙ್ಕ array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        ಯದಿ (td & TYPE_PARAM) ಯಾವತ್ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    ವಿಕಲ್ಪ (tok) {
	    ಪಕ್ಷ TOK_CONST1: ಪಕ್ಷ TOK_CONST2: ಪಕ್ಷ TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		ಅನುವರ್ತ;
	    ಪಕ್ಷ TOK_VOLATILE1: ಪಕ್ಷ TOK_VOLATILE2: ಪಕ್ಷ TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		ಅನುವರ್ತ;
	    ಪಕ್ಷ TOK_RESTRICT1: ಪಕ್ಷ TOK_RESTRICT2: ಪಕ್ಷ TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		ಅನುವರ್ತ;
	    ಪಕ್ಷ TOK_STATIC:
	    ಪಕ್ಷ '*':
		next();
		ಅನುವರ್ತ;
	    ಸ್ವಭಾವ:
		ಭಙ್ಗ;
	    }
            ಯದಿ (tok != ']') {
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
		ಗಚ್ಛ check;
            }
            ಭಙ್ಗ;

	} ಅನ್ಯಥಾ ಯದಿ (tok != ']') {
            ಯದಿ (!local_ರಾಶಿ || (storage & VT_STATIC))
                vpushi(ಅಭಿವ್ಯಕ್ತಿ_const());
            ಅನ್ಯಥಾ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ಯದಿ (n < 0)
                    tcc_error("invalid array size");
            } ಅನ್ಯಥಾ {
                ಯದಿ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        ಯದಿ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ಯದಿ ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ಯದಿ (t1 & VT_VLA) {
            ಯದಿ (n < 0) {
		ಯದಿ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ಅನ್ಯಥಾ {
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
        ಯದಿ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ತಳ್ಳು(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ಯದಿ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ಯದಿ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ಅನ್ಯಥಾ
	        tok_str_free_str(vla_array_str);
	}
    }
    ಪ್ರತ್ಯಾಗಮ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ಸ್ಥಿರ CType *type_decl(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ *v, ಪೂರ್ಣಾಙ್ಕ td)
{
    CType *post, *ret;
    ಪೂರ್ಣಾಙ್ಕ qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ಯಾವತ್ (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        ವಿಕಲ್ಪ(tok) {
        ಪಕ್ಷ TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            ಗಚ್ಛ redo;
        ಪಕ್ಷ TOK_CONST1:
        ಪಕ್ಷ TOK_CONST2:
        ಪಕ್ಷ TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            ಗಚ್ಛ redo;
        ಪಕ್ಷ TOK_VOLATILE1:
        ಪಕ್ಷ TOK_VOLATILE2:
        ಪಕ್ಷ TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            ಗಚ್ಛ redo;
        ಪಕ್ಷ TOK_RESTRICT1:
        ಪಕ್ಷ TOK_RESTRICT2:
        ಪಕ್ಷ TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            ಗಚ್ಛ redo;
	/* XXX: clarify attribute handling */
	ಪಕ್ಷ TOK_ATTRIBUTE1:
	ಪಕ್ಷ TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    ಭಙ್ಗ;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	ಯದಿ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ಯದಿ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ಯದಿ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ಅನ್ಯಥಾ
	  ಗಚ್ಛ abstract;
    } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } ಅನ್ಯಥಾ {
  abstract:
	ಯದಿ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC ಶೂನ್ಯ indir(ಶೂನ್ಯ)
{
    ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ಪ್ರತ್ಯಾಗಮ;
        expect("pointer");
    }
    ಯದಿ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ಯದಿ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
ಸ್ಥಿರ ಶೂನ್ಯ gfunc_param_typed(Sym *func, Sym *arg)
{
    ಪೂರ್ಣಾಙ್ಕ func_type;
    CType type;

    func_type = func->f.func_type;
    ಯದಿ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ರಿಕ್ತ)) {
        /* default casting : only need to convert float to double */
        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ಅನ್ಯಥಾ ಯದಿ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ಅನ್ಯಥಾ ಯದಿ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ಅನ್ಯಥಾ ಯದಿ (arg == ರಿಕ್ತ) {
        tcc_error("too many arguments to function");
    } ಅನ್ಯಥಾ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_type(CType *type, ಶೂನ್ಯ (*ಅಭಿವ್ಯಕ್ತಿ_fn)(ಶೂನ್ಯ))
{
    nocode_wanted++;
    ಅಭಿವ್ಯಕ್ತಿ_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಅಭಿವ್ಯಕ್ತಿ_type(CType *type)
{
    ಪೂರ್ಣಾಙ್ಕ n;
    AttributeDef ad;

    skip('(');
    ಯದಿ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ಅನ್ಯಥಾ {
        ಅಭಿವ್ಯಕ್ತಿ_type(type, gexpr);
    }
    skip(')');
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_type(CType *type)
{
    AttributeDef ad;
    ಪೂರ್ಣಾಙ್ಕ n;

    ಯದಿ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_builtin_params(ಪೂರ್ಣಾಙ್ಕ nc, ಧ್ರುವ ವರ್ಣ *args)
{
    ವರ್ಣ c, sep = '(';
    CType type;
    ಯದಿ (nc)
        nocode_wanted++;
    next();
    ಯದಿ (*args == 0)
	skip(sep);
    ಯಾವತ್ ((c = *args++)) {
	skip(sep);
	sep = ',';
        ಯದಿ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ಅನುವರ್ತ;
        }
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        type.ref = ರಿಕ್ತ;
        type.t = 0;
	ವಿಕಲ್ಪ (c) {
	    ಪಕ್ಷ 'e':
		ಅನುವರ್ತ;
	    ಪಕ್ಷ 'V':
                type.t = VT_CONSTANT;
	    ಪಕ್ಷ 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                ಭಙ್ಗ;
	    ಪಕ್ಷ 'S':
                type.t = VT_CONSTANT;
	    ಪಕ್ಷ 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                ಭಙ್ಗ;
	    ಪಕ್ಷ 'i':
                type.t = VT_INT;
                ಭಙ್ಗ;
	    ಪಕ್ಷ 'l':
                type.t = VT_SIZE_T;
                ಭಙ್ಗ;
	    ಸ್ವಭಾವ:
                ಭಙ್ಗ;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    ಯದಿ (nc)
        nocode_wanted--;
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_atomic(ಪೂರ್ಣಾಙ್ಕ atok)
{
    ಪೂರ್ಣಾಙ್ಕ size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    ವರ್ಣ buf[40];
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ templates[] = {
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
    ಧ್ರುವ ವರ್ಣ *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ರಿಕ್ತ;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    ಪ್ರತಿ (arg = 0;;) {
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        ವಿಕಲ್ಪ (template[arg]) {
        ಪಕ್ಷ 'a':
        ಪಕ್ಷ 'A':
            atom_ptr = &vtop->type;
            ಯದಿ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            ಯದಿ (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            ಭಙ್ಗ;

        ಪಕ್ಷ 'p':
            ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            ಭಙ್ಗ;
        ಪಕ್ಷ 'v':
            gen_assign_cast(atom);
            ಭಙ್ಗ;
        ಪಕ್ಷ 'l':
            indir();
            gen_assign_cast(atom);
            ಭಙ್ಗ;
        ಪಕ್ಷ 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            ಭಙ್ಗ;
        ಪಕ್ಷ 'm':
            gen_assign_cast(&int_type);
            ಭಙ್ಗ;
        ಪಕ್ಷ 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            ಭಙ್ಗ;
        }
        ಯದಿ ('.' == template[++arg])
            ಭಙ್ಗ;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    ವಿಕಲ್ಪ (template[arg + 1]) {
    ಪಕ್ಷ 'b':
        ct.t = VT_BOOL;
        ಭಙ್ಗ;
    ಪಕ್ಷ 'v':
        ct = *atom;
        ಭಙ್ಗ;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ಯದಿ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ಅನ್ಯಥಾ
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    ಯದಿ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC ಶೂನ್ಯ unary(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ಯದಿ (debug_modes)
        tcc_debug_ಸಾಲು(tcc_state), tcc_tcov_check_ಸಾಲು (tcc_state, 1);

    type.ref = ರಿಕ್ತ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    ವಿಕಲ್ಪ(tok) {
    ಪಕ್ಷ TOK_EXTENSION:
        next();
        ಗಚ್ಛ tok_next;
    ಪಕ್ಷ TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        ಗಚ್ಛ ತಳ್ಳು_tokc;
#endif
    ಪಕ್ಷ TOK_CINT:
    ಪಕ್ಷ TOK_CCHAR: 
	t = VT_INT;
 ತಳ್ಳು_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CLLONG:
        t = VT_LLONG;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CFLOAT:
        t = VT_FLOAT;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CDOUBLE:
        t = VT_DOUBLE;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ಅನ್ಯಥಾ
        t = VT_LDOUBLE;
#endif
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	ಗಚ್ಛ ತಳ್ಳು_tokc;
    ಪಕ್ಷ TOK___FUNCTION__:
        ಯದಿ (!gnu_ext)
            ಗಚ್ಛ tok_identifier;
        /* fall thru */
    ಪಕ್ಷ TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ಗಚ್ಛ case_TOK_STR;
    ಪಕ್ಷ TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#ಅನ್ಯಥಾ
        t = VT_INT;
#endif
        ಗಚ್ಛ str_init;
    ಪಕ್ಷ TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ಯದಿ (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, ಪರಿಮಾಣ(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SOTYPE:
    ಪಕ್ಷ '(':
        t = tok;
        next();
        /* cast ? */
        ಯದಿ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ಯದಿ (tok == '{') {
                    /* data is allocated locally by default */
                ಯದಿ (global_ಅಭಿವ್ಯಕ್ತಿ)
                    r = VT_CONST;
                ಅನ್ಯಥಾ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ಯದಿ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, ಪರಿಮಾಣ(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ಅನ್ಯಥಾ ಯದಿ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ಪ್ರತ್ಯಾಗಮ;
            } ಅನ್ಯಥಾ {
                unary();
                gen_cast(&type);
            }
        } ಅನ್ಯಥಾ ಯದಿ (tok == '{') {
	    ಪೂರ್ಣಾಙ್ಕ saved_nocode_wanted = nocode_wanted;
            ಯದಿ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ಯದಿ (0 == local_scope)
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
            block(STMT_ಅಭಿವ್ಯಕ್ತಿ);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ಯದಿ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ಅನ್ಯಥಾ {
            gexpr();
            skip(')');
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ '*':
        next();
        unary();
        indir();
        ಭಙ್ಗ;
    ಪಕ್ಷ '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ಯದಿ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        ಭಙ್ಗ;
    ಪಕ್ಷ '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        ಭಙ್ಗ;
    ಪಕ್ಷ '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        ಭಙ್ಗ;
    ಪಕ್ಷ '+':
        next();
        unary();
        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ಯದಿ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_SIZEOF:
    ಪಕ್ಷ TOK_ALIGNOF1:
    ಪಕ್ಷ TOK_ALIGNOF2:
    ಪಕ್ಷ TOK_ALIGNOF3:
        t = tok;
        next();
        ಯದಿ (tok == '(')
            tok = TOK_SOTYPE;
        ಅಭಿವ್ಯಕ್ತಿ_type(&type, unary);
        ಯದಿ (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } ಅನ್ಯಥಾ {
            type_size(&type, &align);
            s = ರಿಕ್ತ;
            ಯದಿ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ಯದಿ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_builtin_choose_ಅಭಿವ್ಯಕ್ತಿ:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = ಅಭಿವ್ಯಕ್ತಿ_const64();
	    skip(',');
	    ಯದಿ (!c) {
		nocode_wanted++;
	    }
	    ಅಭಿವ್ಯಕ್ತಿ_eq();
	    ಯದಿ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ಯದಿ (c) {
		nocode_wanted++;
	    }
	    ಅಭಿವ್ಯಕ್ತಿ_eq();
	    ಯದಿ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_builtin_frame_address:
    ಪಕ್ಷ TOK_builtin_return_address:
        {
            ಪೂರ್ಣಾಙ್ಕ tok1 = tok;
            ಪೂರ್ಣಾಙ್ಕ level;
            next();
            skip('(');
            level = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಯದಿ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ಯಾವತ್ (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ಯದಿ (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#ಅನ್ಯಥಾ
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        ಭಙ್ಗ;
#ifdef TCC_TARGET_RISCV64
    ಪಕ್ಷ TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ಯದಿ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ಯದಿ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        ಭಙ್ಗ;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    ಪಕ್ಷ TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ಯದಿ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ಯದಿ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        ಭಙ್ಗ;
#ಅನ್ಯಥಾ
    ಪಕ್ಷ TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	ಭಙ್ಗ;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    ಪಕ್ಷ TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ಭಙ್ಗ;
    }
    ಪಕ್ಷ TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        ಭಙ್ಗ;
    }
#endif
#ifdef TCC_TARGET_ARM64
    ಪಕ್ಷ TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ಭಙ್ಗ;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    ಪಕ್ಷ TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ಭಙ್ಗ;
    }
#endif

    /* atomic operations */
    ಪಕ್ಷ TOK___atomic_store:
    ಪಕ್ಷ TOK___atomic_load:
    ಪಕ್ಷ TOK___atomic_exchange:
    ಪಕ್ಷ TOK___atomic_compare_exchange:
    ಪಕ್ಷ TOK___atomic_fetch_add:
    ಪಕ್ಷ TOK___atomic_fetch_sub:
    ಪಕ್ಷ TOK___atomic_fetch_or:
    ಪಕ್ಷ TOK___atomic_fetch_xor:
    ಪಕ್ಷ TOK___atomic_fetch_and:
    ಪಕ್ಷ TOK___atomic_fetch_nand:
    ಪಕ್ಷ TOK___atomic_add_fetch:
    ಪಕ್ಷ TOK___atomic_sub_fetch:
    ಪಕ್ಷ TOK___atomic_or_fetch:
    ಪಕ್ಷ TOK___atomic_xor_fetch:
    ಪಕ್ಷ TOK___atomic_and_fetch:
    ಪಕ್ಷ TOK___atomic_nand_fetch:
        parse_atomic(tok);
        ಭಙ್ಗ;

    /* pre operations */
    ಪಕ್ಷ TOK_INC:
    ಪಕ್ಷ TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
        next();
        unary();
	ಯದಿ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ಅನ್ಯಥಾ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LAND:
        ಯದಿ (!gnu_ext)
            ಗಚ್ಛ tok_identifier;
        next();
        /* allow to take the address of a label */
        ಯದಿ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        ಯದಿ (!s) {
            s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok, LABEL_FORWARD);
        } ಅನ್ಯಥಾ {
            ಯದಿ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ಯದಿ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_GENERIC:
    {
	CType controlling_type;
	ಪೂರ್ಣಾಙ್ಕ has_default = 0;
	ಪೂರ್ಣಾಙ್ಕ has_match = 0;
	ಪೂರ್ಣಾಙ್ಕ learn = 0;
	TokenString *str = ರಿಕ್ತ;
	ಪೂರ್ಣಾಙ್ಕ saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	ಅಭಿವ್ಯಕ್ತಿ_type(&controlling_type, ಅಭಿವ್ಯಕ್ತಿ_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        ಪ್ರತಿ (;;) {
	    learn = 0;
	    skip(',');
	    ಯದಿ (tok == TOK_DEFAULT) {
		ಯದಿ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ಯದಿ (!has_match)
		    learn = 1;
		next();
	    } ಅನ್ಯಥಾ {
		ಪೂರ್ಣಾಙ್ಕ v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ಯದಿ (compare_types(&controlling_type, &type, 0)) {
		    ಯದಿ (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ಯದಿ (learn) {
		ಯದಿ (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } ಅನ್ಯಥಾ {
		skip_or_save_block(ರಿಕ್ತ);
	    }
	    ಯದಿ (tok == ')')
		ಭಙ್ಗ;
	}
	ಯದಿ (!str) {
	    ವರ್ಣ buf[60];
	    type_to_str(buf, ಪರಿಮಾಣ buf, &controlling_type, ರಿಕ್ತ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	ಅಭಿವ್ಯಕ್ತಿ_eq();
	ಯದಿ (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	ಭಙ್ಗ;
    }
    // special qnan , snan and infinity values
    ಪಕ್ಷ TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK___SNAN__:
	n = 0x7f800001;
	ಗಚ್ಛ special_math_val;
    ಪಕ್ಷ TOK___INF__:
	n = 0x7f800000;
	ಗಚ್ಛ special_math_val;

    ಸ್ವಭಾವ:
    tok_identifier:
        ಯದಿ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        ಯದಿ (!s || IS_ASM_SYM(s)) {
            ಧ್ರುವ ವರ್ಣ *name = get_tok_str(t, ರಿಕ್ತ);
            ಯದಿ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ಯದಿ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ಯದಿ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ಯದಿ (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            ಯದಿ (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } ಅನ್ಯಥಾ ಯದಿ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        ಭಙ್ಗ;
    }
    
    /* post operations */
    ಯಾವತ್ (1) {
        ಯದಿ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } ಅನ್ಯಥಾ ಯದಿ (tok == '.' || tok == TOK_ARROW) {
            ಪೂರ್ಣಾಙ್ಕ qualifiers, cumofs;
            /* field */ 
            ಯದಿ (tok == TOK_ARROW) 
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
            ಯದಿ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ಯದಿ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ಯದಿ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } ಅನ್ಯಥಾ ಯದಿ (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ಅನ್ಯಥಾ ಯದಿ (tok == '(') {
            SValue ret;
            Sym *sa;
            ಪೂರ್ಣಾಙ್ಕ nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ಯದಿ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        ಗಚ್ಛ error_func;
                } ಅನ್ಯಥಾ {
                error_func:
                    expect("function pointer");
                }
            } ಅನ್ಯಥಾ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ಯದಿ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ಯದಿ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ಯದಿ (size < 16)
                    ಯಾವತ್ (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    ಯದಿ (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    ಯದಿ (ret_nregs < 0)
                      vtop--;
                    ಅನ್ಯಥಾ
                      nb_args++;
                }
            } ಅನ್ಯಥಾ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ಯದಿ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ರಿಕ್ತ;
            ಯದಿ (tok != ')') {
                r = tcc_state->reverse_funcargs;
                ಪ್ರತಿ(;;) {
                    ಯದಿ (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } ಅನ್ಯಥಾ {
                        ಅಭಿವ್ಯಕ್ತಿ_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    ಯದಿ (sa)
                        sa = sa->next;
                    ಯದಿ (tok == ')')
                        ಭಙ್ಗ;
                    skip(',');
                }
            }
            ಯದಿ (sa)
                tcc_error("too few arguments to function");

            ಯದಿ (p) { /* with reverse_funcargs */
                ಪ್ರತಿ (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    ಕುರು {
                        sa = sa->next, p2 = p2->prev;
                    } ಯಾವತ್ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    ಅಭಿವ್ಯಕ್ತಿ_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            ಯದಿ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } ಅನ್ಯಥಾ {
                /* return value */
                n = ret_nregs;
                ಯಾವತ್ (n > 1) {
                    ಪೂರ್ಣಾಙ್ಕ rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    ಪ್ರತಿ (r = 0; r < NB_REGS; ++r)
                        ಯದಿ (reg_classes[r] & rc)
                            ಭಙ್ಗ;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ಯದಿ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    ಪೂರ್ಣಾಙ್ಕ addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    ಯದಿ (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    ಪ್ರತಿ (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        ಯದಿ (--ret_nregs == 0)
                          ಭಙ್ಗ;
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
                ಯದಿ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ಅನ್ಯಥಾ
                    vtop->type.t = VT_INT;
#endif
                }
            }
            ಯದಿ (s->f.func_noreturn) {
                ಯದಿ (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } ಅನ್ಯಥಾ {
            ಭಙ್ಗ;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_prod(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;

    unary();
    ಯಾವತ್ ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_sum(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_prod();
    ಯಾವತ್ ((t = tok) == '+' || t == '-') {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_prod();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_shift(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_sum();
    ಯಾವತ್ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_sum();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmp(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_shift();
    ಯಾವತ್ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_shift();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmpeq(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_cmp();
    ಯಾವತ್ ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_cmp();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_and(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_cmpeq();
    ಯಾವತ್ (tok == '&') {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_cmpeq();
        gen_op('&');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_xor(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_and();
    ಯಾವತ್ (tok == '^') {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_and();
        gen_op('^');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_or(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_xor();
    ಯಾವತ್ (tok == '|') {
        next();
        ಅಭಿವ್ಯಕ್ತಿ_xor();
        gen_op('|');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಙ್ಕ op);

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_land(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_or();
    ಯದಿ (tok == TOK_LAND)
        ಅಭಿವ್ಯಕ್ತಿ_landor(tok);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_lor(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_land();
    ಯದಿ (tok == TOK_LOR)
        ಅಭಿವ್ಯಕ್ತಿ_landor(tok);
}

# define ಅಭಿವ್ಯಕ್ತಿ_landor_next(op) op == TOK_LAND ? ಅಭಿವ್ಯಕ್ತಿ_or() : ಅಭಿವ್ಯಕ್ತಿ_land()
#ಅನ್ಯಥಾ /* defined precedence_parser */
# define ಅಭಿವ್ಯಕ್ತಿ_landor_next(op) unary(), ಅಭಿವ್ಯಕ್ತಿ_infix(precedence(op) + 1)
# define ಅಭಿವ್ಯಕ್ತಿ_lor() unary(), ಅಭಿವ್ಯಕ್ತಿ_infix(1)

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ precedence(ಪೂರ್ಣಾಙ್ಕ tok)
{
    ವಿಕಲ್ಪ (tok) {
        ಪಕ್ಷ TOK_LOR: ಪ್ರತ್ಯಾಗಮ 1;
        ಪಕ್ಷ TOK_LAND: ಪ್ರತ್ಯಾಗಮ 2;
	ಪಕ್ಷ '|': ಪ್ರತ್ಯಾಗಮ 3;
	ಪಕ್ಷ '^': ಪ್ರತ್ಯಾಗಮ 4;
	ಪಕ್ಷ '&': ಪ್ರತ್ಯಾಗಮ 5;
	ಪಕ್ಷ TOK_EQ: ಪಕ್ಷ TOK_NE: ಪ್ರತ್ಯಾಗಮ 6;
 relat: ಪಕ್ಷ TOK_ULT: ಪಕ್ಷ TOK_UGE: ಪ್ರತ್ಯಾಗಮ 7;
	ಪಕ್ಷ TOK_SHL: ಪಕ್ಷ TOK_SAR: ಪ್ರತ್ಯಾಗಮ 8;
	ಪಕ್ಷ '+': ಪಕ್ಷ '-': ಪ್ರತ್ಯಾಗಮ 9;
	ಪಕ್ಷ '*': ಪಕ್ಷ '/': ಪಕ್ಷ '%': ಪ್ರತ್ಯಾಗಮ 10;
	ಸ್ವಭಾವ:
	    ಯದಿ (tok >= TOK_ULE && tok <= TOK_GT)
	        ಗಚ್ಛ relat;
	    ಪ್ರತ್ಯಾಗಮ 0;
    }
}
ಸ್ಥಿರ unsigned ವರ್ಣ prec[256];
ಸ್ಥಿರ ಶೂನ್ಯ init_prec(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಙ್ಕ op);

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_infix(ಪೂರ್ಣಾಙ್ಕ p)
{
    ಪೂರ್ಣಾಙ್ಕ t = tok, p2;
    ಯಾವತ್ ((p2 = precedence(t)) >= p) {
        ಯದಿ (t == TOK_LOR || t == TOK_LAND) {
            ಅಭಿವ್ಯಕ್ತಿ_landor(t);
        } ಅನ್ಯಥಾ {
            next();
            unary();
            ಯದಿ (precedence(tok) > p2)
              ಅಭಿವ್ಯಕ್ತಿ_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ condition_3way(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ c = -1;
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ಪ್ರತ್ಯಾಗಮ c;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಙ್ಕ op)
{
    ಪೂರ್ಣಾಙ್ಕ t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    ಪ್ರತಿ(;;) {
        c = f ? i : condition_3way();
        ಯದಿ (c < 0)
            save_regs(1), cc = 0;
        ಅನ್ಯಥಾ ಯದಿ (c != i)
            nocode_wanted++, f = 1;
        ಯದಿ (tok != op)
            ಭಙ್ಗ;
        ಯದಿ (c < 0)
            t = gvtst(i, t);
        ಅನ್ಯಥಾ
            vpop();
        next();
        ಅಭಿವ್ಯಕ್ತಿ_landor_next(op);
    }
    ಯದಿ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ಅನ್ಯಥಾ {
        gvtst_set(i, t);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ is_cond_bool(SValue *sv)
{
    ಯದಿ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ಪ್ರತ್ಯಾಗಮ (unsigned)sv->c.i < 2;
    ಯದಿ (sv->r == VT_CMP)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cond(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    ಅಭಿವ್ಯಕ್ತಿ_lor();
    ಯದಿ (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ಯದಿ (!g) {
            ಯದಿ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ಅನ್ಯಥಾ {
                vpop();
            }
        } ಅನ್ಯಥಾ ಯದಿ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ಯದಿ (c == 0)
          nocode_wanted++;
        ಯದಿ (!g)
          gexpr();

        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ಯದಿ (g) {
            u = tt;
        } ಅನ್ಯಥಾ ಯದಿ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ಅನ್ಯಥಾ
          u = 0;

        ಯದಿ (c == 0)
          nocode_wanted--;
        ಯದಿ (c == 1)
          nocode_wanted++;
        skip(':');
        ಅಭಿವ್ಯಕ್ತಿ_cond();

        ಯದಿ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ಯದಿ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ಯದಿ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            ಪ್ರತ್ಯಾಗಮ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ಯದಿ (c != 1) {
            gen_cast(&type);
            ಯದಿ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ಯದಿ (USING_TWO_ಪದಗಳು(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ಯದಿ (c < 0) {
            ಯದಿ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ಯದಿ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        ಯದಿ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ಯದಿ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        ಯದಿ (c < 0) {
            ಯದಿ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ಯದಿ (islv)
          indir();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_eq(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    
    ಅಭಿವ್ಯಕ್ತಿ_cond();
    ಯದಿ ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        ಯದಿ (t == '=') {
            ಅಭಿವ್ಯಕ್ತಿ_eq();
        } ಅನ್ಯಥಾ {
            vdup();
            ಅಭಿವ್ಯಕ್ತಿ_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC ಶೂನ್ಯ gexpr(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_eq();
    ಯದಿ (tok == ',') {
        ಕುರು {
            vpop();
            next();
            ಅಭಿವ್ಯಕ್ತಿ_eq();
        } ಯಾವತ್ (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ಯದಿ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ಯದಿ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_const1(ಶೂನ್ಯ)
{
    nocode_wanted += CONST_WANTED_BIT;
    ಅಭಿವ್ಯಕ್ತಿ_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ int64_t ಅಭಿವ್ಯಕ್ತಿ_const64(ಶೂನ್ಯ)
{
    int64_t c;
    ಅಭಿವ್ಯಕ್ತಿ_const1();
    ಯದಿ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ಪ್ರತ್ಯಾಗಮ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ ಅಭಿವ್ಯಕ್ತಿ_const(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    int64_t wc = ಅಭಿವ್ಯಕ್ತಿ_const64();
    c = wc;
    ಯದಿ (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    ಪ್ರತ್ಯಾಗಮ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
ಸ್ಥಿರ ಶೂನ್ಯ gfunc_return(CType *func_type)
{
    ಯದಿ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        ಪೂರ್ಣಾಙ್ಕ ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ಯದಿ (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } ಅನ್ಯಥಾ ಯದಿ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ಅನ್ಯಥಾ {
            /* returning structure packed into registers */
            ಪೂರ್ಣಾಙ್ಕ size, addr, align, rc, n;
            size = type_size(func_type,&align);
            ಯದಿ (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ಯದಿ (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		ಯದಿ (ret_align > align)
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
            ಪ್ರತಿ (n = ret_nregs; --n > 0;) {
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
    } ಅನ್ಯಥಾ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

ಸ್ಥಿರ ಶೂನ್ಯ check_func_return(ಶೂನ್ಯ)
{
    ಯದಿ ((func_vt.t & VT_BTYPE) == VT_VOID)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ಅನ್ಯಥಾ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ case_cmp(uint64_t a, uint64_t b)
{
    ಯದಿ (cur_switch->sv.type.t & VT_UNSIGNED)
        ಪ್ರತ್ಯಾಗಮ a < b ? -1 : a > b;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ case_cmp_qs(ಧ್ರುವ ಶೂನ್ಯ *pa, ಧ್ರುವ ಶೂನ್ಯ *pb)
{
    ಪ್ರತ್ಯಾಗಮ case_cmp((*(ಸಂರಚನಾ case_t**)pa)->v1, (*(ಸಂರಚನಾ case_t**)pb)->v1);
}

ಸ್ಥಿರ ಶೂನ್ಯ case_sort(ಸಂರಚನಾ switch_t *sw)
{
    ಸಂರಚನಾ case_t **p;
    ಯದಿ (sw->n < 2)
        ಪ್ರತ್ಯಾಗಮ;
    qsort(sw->p, sw->n, ಪರಿಮಾಣ *sw->p, case_cmp_qs);
    p = sw->p;
    ಯಾವತ್ (p < sw->p + sw->n - 1) {
        ಯದಿ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            ಪೂರ್ಣಾಙ್ಕ l1 = p[0]->ಸಾಲು, l2 = p[1]->ಸಾಲು;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ಅನ್ಯಥಾ ಯದಿ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * ಪರಿಮಾಣ *p);
        } ಅನ್ಯಥಾ
            ++p;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ gcase(ಸಂರಚನಾ case_t **base, ಪೂರ್ಣಾಙ್ಕ len, ಪೂರ್ಣಾಙ್ಕ dsym)
{
    ಸಂರಚನಾ case_t *p;
    ಪೂರ್ಣಾಙ್ಕ t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ಯದಿ (t != VT_LLONG)
        t = VT_INT;
    ಯಾವತ್ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        ಯದಿ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ಅನ್ಯಥಾ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ಯದಿ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ಅನ್ಯಥಾ
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
    ಪ್ರತ್ಯಾಗಮ gjmp(dsym);
}

ಸ್ಥಿರ ಶೂನ್ಯ end_switch(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ಸ್ಥಿರ ಶೂನ್ಯ save_lvalues(ಶೂನ್ಯ)
{
    SValue *sv = vtop;
    ಯಾವತ್ (sv >= vstack) {
        ಯದಿ (sv->sym && (sv->r & VT_LVAL)) {
            ಪೂರ್ಣಾಙ್ಕ align, size = type_size(&sv->type, &align);
            ಪೂರ್ಣಾಙ್ಕ r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    ಪ್ರತಿ (; cls != stop; cls = cls->next) {
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


ಸ್ಥಿರ ಶೂನ್ಯ try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    ಪೂರ್ಣಾಙ್ಕ ocd, ccd;

    ಯದಿ (!cur_scope->cl.s)
	ಪ್ರತ್ಯಾಗಮ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    ಪ್ರತಿ (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    ಪ್ರತಿ (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    ಪ್ರತಿ (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ಸ್ಥಿರ ಶೂನ್ಯ block_cleanup(ಸಂರಚನಾ scope *o)
{
    ಪೂರ್ಣಾಙ್ಕ jmp = 0;
    Sym *g, **pg;
    ಪ್ರತಿ (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ಯದಿ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            ಯದಿ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ಯದಿ (!o->cl.n)
                ಗಚ್ಛ remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } ಅನ್ಯಥಾ {
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

ಸ್ಥಿರ ಶೂನ್ಯ vla_restore(ಪೂರ್ಣಾಙ್ಕ loc)
{
    ಯದಿ (loc)
        gen_vla_sp_restore(loc);
}

ಸ್ಥಿರ ಶೂನ್ಯ vla_leave(ಸಂರಚನಾ scope *o)
{
    ಸಂರಚನಾ scope *c = cur_scope, *v = ರಿಕ್ತ;
    ಪ್ರತಿ (; c != o && c; c = c->prev)
      ಯದಿ (c->vla.ಅಂಕೆ)
        v = c;
    ಯದಿ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ಸ್ಥಿರ ಶೂನ್ಯ new_scope(ಸಂರಚನಾ scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.ಅಂಕೆ = 0;

    /* record local declaration stack position */
    o->lstk = local_ರಾಶಿ;
    o->llstk = local_label_ರಾಶಿ;
    ++local_scope;
}

ಸ್ಥಿರ ಶೂನ್ಯ prev_scope(ಸಂರಚನಾ scope *o, ಪೂರ್ಣಾಙ್ಕ is_ಅಭಿವ್ಯಕ್ತಿ)
{
    vla_leave(o->prev);

    ಯದಿ (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    ಯದಿ (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_ಅಭಿವ್ಯಕ್ತಿ);

    /* pop locally defined labels */
    label_ತೆಗೆ(&local_label_ರಾಶಿ, o->llstk, is_ಅಭಿವ್ಯಕ್ತಿ);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_ತೆಗೆ(&local_ರಾಶಿ, o->lstk, is_ಅಭಿವ್ಯಕ್ತಿ);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ಸ್ಥಿರ ಶೂನ್ಯ leave_scope(ಸಂರಚನಾ scope *o)
{
    ಯದಿ (!o)
        ಪ್ರತ್ಯಾಗಮ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ಸ್ಥಿರ ಶೂನ್ಯ new_scope_s(ಸಂರಚನಾ scope *o)
{
    o->lstk = local_ರಾಶಿ;
    ++local_scope;
}

ಸ್ಥಿರ ಶೂನ್ಯ prev_scope_s(ಸಂರಚನಾ scope *o)
{
    sym_ತೆಗೆ(&local_ರಾಶಿ, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ಸ್ಥಿರ ಶೂನ್ಯ lblock(ಪೂರ್ಣಾಙ್ಕ *bsym, ಪೂರ್ಣಾಙ್ಕ *csym)
{
    ಸಂರಚನಾ scope *lo = loop_scope, *co = cur_scope;
    ಪೂರ್ಣಾಙ್ಕ *b = co->bsym, *c = co->csym;
    ಯದಿ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    ಯದಿ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ಸ್ಥಿರ ಶೂನ್ಯ gexpr_decl(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ v = decl(VT_JMP);
    ಯದಿ (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ಅನ್ಯಥಾ {
        ಯದಿ (v)
            skip(';');
        gexpr();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ block(ಪೂರ್ಣಾಙ್ಕ flags)
{
    ಪೂರ್ಣಾಙ್ಕ a, b, c, d, e, t;
    ಸಂರಚನಾ scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ಯದಿ (TOK_HAS_ಮೌಲ್ಯ(t))
        ಗಚ್ಛ ಅಭಿವ್ಯಕ್ತಿ;
    next();

    ಯದಿ (debug_modes)
        tcc_tcov_check_ಸಾಲು (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    ಯದಿ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        ಯದಿ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } ಅನ್ಯಥಾ {
            gsym(a);
        }
        prev_scope_s(&o);

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_WHILE) {
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

    } ಅನ್ಯಥಾ ಯದಿ (t == '{') {
        ಯದಿ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ಯಾವತ್ (tok == TOK_LABEL) {
            ಕುರು {
                next();
                ಯದಿ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ತಳ್ಳು(&local_label_ರಾಶಿ, tok, LABEL_DECLARED);
                next();
            } ಯಾವತ್ (tok == ',');
            skip(';');
        }

        ಯಾವತ್ (tok != '}') {
	    decl(VT_LOCAL);
            ಯದಿ (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_ಅಭಿವ್ಯಕ್ತಿ);
        ಯದಿ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ಯದಿ (local_scope)
            next();
        ಅನ್ಯಥಾ ಯದಿ (!nocode_wanted)
            check_func_return();

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ಯದಿ (tok != ';') {
            gexpr();
            ಯದಿ (b) {
                gen_assign_cast(&func_vt);
            } ಅನ್ಯಥಾ {
                ಯದಿ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ಅನ್ಯಥಾ ಯದಿ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ಅನ್ಯಥಾ ಯದಿ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ಬೇರು_scope);
        ಯದಿ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ಯದಿ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ಯದಿ (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_BREAK) {
        /* compute jump */
        ಯದಿ (!cur_scope->bsym)
            tcc_error("cannot break");
        ಯದಿ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ಅನ್ಯಥಾ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_CONTINUE) {
        /* compute jump */
        ಯದಿ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ಯದಿ (tok != ';') {
            /* c99 for-loop init decl? */
            ಯದಿ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ಯದಿ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ಯದಿ (tok != ')') {
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

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_DO) {
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

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_SWITCH) {
        ಸಂರಚನಾ switch_t *sw;

        sw = tcc_mallocz(ಪರಿಮಾಣ *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ಯದಿ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ರಿಕ್ತ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ಯದಿ (sw->nocode_wanted)
            ಗಚ್ಛ skip_switch;
        case_sort(sw);
        sw->bsym = ರಿಕ್ತ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ಯದಿ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ಅನ್ಯಥಾ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_CASE) {
        ಸಂರಚನಾ case_t *cr;
        ಯದಿ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(ಪರಿಮಾಣ(ಸಂರಚನಾ case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(ಅಭಿವ್ಯಕ್ತಿ_const64(), t);
        ಯದಿ (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(ಅಭಿವ್ಯಕ್ತಿ_const64(), t);
            ಯದಿ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ಯದಿ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
        skip(':');
        ಗಚ್ಛ block_after_label;

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_DEFAULT) {
        ಯದಿ (!cur_switch)
            expect("switch");
        ಯದಿ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        ಗಚ್ಛ block_after_label;

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ಯದಿ (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            ಯದಿ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            ಯದಿ (!s)
              s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok, LABEL_FORWARD);
            ಅನ್ಯಥಾ ಯದಿ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ಯದಿ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ಯದಿ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ಅನ್ಯಥಾ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } ಅನ್ಯಥಾ {
            expect("label identifier");
        }
        skip(';');

    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ಅನ್ಯಥಾ {
        ಯದಿ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            ಯದಿ (s) {
                ಯದಿ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ರಿಕ್ತ));
                s->r = LABEL_DEFINED;
		ಯದಿ (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    ಪ್ರತಿ (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_ತೆಗೆ(&s->next, ರಿಕ್ತ, 0);
		} ಅನ್ಯಥಾ
		  gsym(s->jnext);
            } ಅನ್ಯಥಾ {
                s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ರಿಕ್ತ);

            ಯದಿ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ಯದಿ (tok != '}') {
                ಯದಿ (0 == (flags & STMT_COMPOUND))
                    ಗಚ್ಛ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ಅನ್ಯಥಾ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ಅನ್ಯಥಾ {
            /* expression case */
            ಯದಿ (t != ';') {
                unget_tok(t);
    ಅಭಿವ್ಯಕ್ತಿ:
                ಯದಿ (flags & STMT_ಅಭಿವ್ಯಕ್ತಿ) {
                    vpop();
                    gexpr();
                } ಅನ್ಯಥಾ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ಯದಿ (debug_modes)
        tcc_tcov_check_ಸಾಲು (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ಸ್ಥಿರ ಶೂನ್ಯ skip_or_save_block(TokenString **str)
{
    ಪೂರ್ಣಾಙ್ಕ braces = tok == '{';
    ಪೂರ್ಣಾಙ್ಕ level = 0;
    ಯದಿ (str)
      *str = tok_str_alloc();

    ಯಾವತ್ (1) {
	ಪೂರ್ಣಾಙ್ಕ t = tok;
        ಯದಿ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             ಭಙ್ಗ;
	ಯದಿ (t == TOK_EOF) {
	     ಯದಿ (str || level > 0)
	       tcc_error("unexpected end of file");
	     ಅನ್ಯಥಾ
	       ಭಙ್ಗ;
	}
	ಯದಿ (str)
	  tok_str_add_tok(*str);
	next();
	ಯದಿ (t == '{' || t == '(' || t == '[') {
	    level++;
	} ಅನ್ಯಥಾ ಯದಿ (t == '}' || t == ')' || t == ']') {
	    level--;
	    ಯದಿ (level == 0 && braces && t == '}')
	      ಭಙ್ಗ;
	}
    }
    ಯದಿ (str)
	tok_str_add(*str, TOK_EOF);
}

#define ಅಭಿವ್ಯಕ್ತಿ_CONST 1
#define ಅಭಿವ್ಯಕ್ತಿ_ANY   2

ಸ್ಥಿರ ಶೂನ್ಯ parse_init_elem(ಪೂರ್ಣಾಙ್ಕ ಅಭಿವ್ಯಕ್ತಿ_type)
{
    ಪೂರ್ಣಾಙ್ಕ saved_global_ಅಭಿವ್ಯಕ್ತಿ;
    ವಿಕಲ್ಪ(ಅಭಿವ್ಯಕ್ತಿ_type) {
    ಪಕ್ಷ ಅಭಿವ್ಯಕ್ತಿ_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_ಅಭಿವ್ಯಕ್ತಿ = global_ಅಭಿವ್ಯಕ್ತಿ;
        global_ಅಭಿವ್ಯಕ್ತಿ = 1;
        ಅಭಿವ್ಯಕ್ತಿ_const1();
        global_ಅಭಿವ್ಯಕ್ತಿ = saved_global_ಅಭಿವ್ಯಕ್ತಿ;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ಯದಿ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        ಭಙ್ಗ;
    ಪಕ್ಷ ಅಭಿವ್ಯಕ್ತಿ_ANY:
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        ಭಙ್ಗ;
    }
}

#ಯದಿ 1
ಸ್ಥಿರ ಶೂನ್ಯ init_assert(init_params *p, ಪೂರ್ಣಾಙ್ಕ offset)
{
    ಯದಿ (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#ಅನ್ಯಥಾ
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
ಸ್ಥಿರ ಶೂನ್ಯ init_putz(init_params *p, unsigned long c, ಪೂರ್ಣಾಙ್ಕ size)
{
    init_assert(p, c + size);
    ಯದಿ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ಅನ್ಯಥಾ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#ಯದಿ defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
ಸ್ಥಿರ ಶೂನ್ಯ decl_design_delrels(Section *sec, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    ಯದಿ (!sec || !sec->reloc)
        ಪ್ರತ್ಯಾಗಮ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    ಯಾವತ್ (rel < rel_end) {
        ಯದಿ (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= ಪರಿಮಾಣ *rel;
        } ಅನ್ಯಥಾ {
            ಯದಿ (rel2 != rel)
                memcpy(rel2, rel, ಪರಿಮಾಣ *rel);
            ++rel2;
        }
        ++rel;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ decl_design_flex(init_params *p, Sym *ref, ಪೂರ್ಣಾಙ್ಕ index)
{
    ಯದಿ (ref == p->flex_array_ref) {
        ಯದಿ (index >= ref->c)
            ref->c = index + 1;
    } ಅನ್ಯಥಾ ಯದಿ (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, ಪೂರ್ಣಾಙ್ಕ flags, ಪೂರ್ಣಾಙ್ಕ al)
{
    Sym *s, *f;
    ಪೂರ್ಣಾಙ್ಕ index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    ಯದಿ (flags & DIF_HAVE_ELEM)
        ಗಚ್ಛ no_designator;

    ಯದಿ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        ಯದಿ (tok == ':')
            ಗಚ್ಛ struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ಯಾವತ್ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ಯದಿ (tok == '[') {
            ಯದಿ (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಯದಿ (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = ಅಭಿವ್ಯಕ್ತಿ_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            ಯದಿ (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            ಯದಿ (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            ಯದಿ (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = ರಿಕ್ತ;
    }
    ಯದಿ (!cur_field) {
        ಯದಿ (tok == '=') {
            next();
        } ಅನ್ಯಥಾ ಯದಿ (!gnu_ext) {
	    expect("=");
        }
    } ಅನ್ಯಥಾ {
    no_designator:
        ಯದಿ (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            ಯದಿ (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } ಅನ್ಯಥಾ {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ಯಾವತ್ (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            ಯದಿ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ಯದಿ (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ಯದಿ (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    ಯದಿ (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        ಪೂರ್ಣಾಙ್ಕ i;
        ಯದಿ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ಯದಿ (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        ಅನ್ಯಥಾ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        ಪ್ರತಿ (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    ಯದಿ (c - corig > al)
      al = c - corig;
    ಪ್ರತ್ಯಾಗಮ al;
}

ಸ್ಥಿರ ಶೂನ್ಯ write_ldouble(unsigned ವರ್ಣ *d, ಶೂನ್ಯ *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    ಯದಿ (LDOUBLE_SIZE >= 10) {
        ದ್ವಿಗುಣ b = *(long ದ್ವಿಗುಣ*)s;
        s = &b;
#ಅನ್ಯಥಾ
    ಯದಿ (ಪರಿಮಾಣ (long ದ್ವಿಗುಣ) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        ಪೂರ್ಣಾಙ್ಕ e = m >> 48;
        ಪೂರ್ಣಾಙ್ಕ f = e >> 4 & 0x7FF;
        m <<= 11;
        ಯದಿ (0 == f) {
            ಯದಿ (0 == m)
                ಗಚ್ಛ set;
            ಪ್ರತಿ (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ಯದಿ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #ಯದಿ (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #ನೋಚೇದ್ಯದಿ LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } ಅನ್ಯಥಾ {
    #ಯದಿ LDOUBLE_SIZE == 8
        /* long double -> double */
        ದ್ವಿಗುಣ b = *(long ದ್ವಿಗುಣ*)s;
        memcpy(d, &b, 8);
    #ನೋಚೇದ್ಯದಿ (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #ನೋಚೇದ್ಯದಿ (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        ಪೂರ್ಣಾಙ್ಕ e = *(uint16_t*)((ವರ್ಣ*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ನೋಚೇದ್ಯದಿ (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((ವರ್ಣ*)s + 6);
        ಪೂರ್ಣಾಙ್ಕ e = read16le((ವರ್ಣ*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ಅನ್ಯಥಾ
        /* unknown */
        ಯದಿ (ಪರಿಮಾಣ (long ದ್ವಿಗುಣ) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
ಸ್ಥಿರ ಶೂನ್ಯ init_putv(init_params *p, CType *type, unsigned long c)
{
    ಪೂರ್ಣಾಙ್ಕ bt;
    ಶೂನ್ಯ *ptr;
    CType dtype;
    ಪೂರ್ಣಾಙ್ಕ size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    ಯದಿ (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    ಯದಿ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ಯದಿ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ಯದಿ (NODATA_WANTED) {
            vtop--;
            ಪ್ರತ್ಯಾಗಮ;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	ಯದಿ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_ಮೌಲ್ಯ + (ಪೂರ್ಣಾಙ್ಕ)vtop->c.i, size);
	    ಯದಿ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		ಯಾವತ್ (relofs >= ಪರಿಮಾಣ(*rel)) {
                    relofs -= ಪರಿಮಾಣ(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    ಯದಿ (rel->r_offset >= esym->st_ಮೌಲ್ಯ + size)
		      ಅನುವರ್ತ;
		    ಯದಿ (rel->r_offset < esym->st_ಮೌಲ್ಯ)
		      ಭಙ್ಗ;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_ಮೌಲ್ಯ,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ಯದಿ PTR_SIZE == 8
				   rel->r_addend
#ಅನ್ಯಥಾ
				   0
#endif
				  );
		}
	    }
	} ಅನ್ಯಥಾ {
            ಯದಿ (type->t & VT_BITFIELD) {
                ಪೂರ್ಣಾಙ್ಕ bit_pos, bit_size, bits, n;
                unsigned ವರ್ಣ *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned ವರ್ಣ*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                ಯಾವತ್ (bit_size) {
                    n = 8 - bit_pos;
                    ಯದಿ (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } ಅನ್ಯಥಾ
            ವಿಕಲ್ಪ(bt) {
	    ಪಕ್ಷ VT_BOOL:
		*(ವರ್ಣ *)ptr = val != 0;
                ಭಙ್ಗ;
	    ಪಕ್ಷ VT_BYTE:
		*(ವರ್ಣ *)ptr = val;
		ಭಙ್ಗ;
	    ಪಕ್ಷ VT_SHORT:
                write16le(ptr, val);
		ಭಙ್ಗ;
	    ಪಕ್ಷ VT_FLOAT:
                write32le(ptr, val);
		ಭಙ್ಗ;
	    ಪಕ್ಷ VT_DOUBLE:
                write64le(ptr, val);
		ಭಙ್ಗ;
	    ಪಕ್ಷ VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		ಭಙ್ಗ;

#ಯದಿ PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    ಪಕ್ಷ VT_LLONG:
	    ಪಕ್ಷ VT_PTR:
	        ಯದಿ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        ಅನ್ಯಥಾ
	          write64le(ptr, val);
	        ಭಙ್ಗ;
            ಪಕ್ಷ VT_INT:
                write32le(ptr, val);
                ಭಙ್ಗ;
#ಅನ್ಯಥಾ
	    ಪಕ್ಷ VT_LLONG:
                write64le(ptr, val);
                ಭಙ್ಗ;
            ಪಕ್ಷ VT_PTR:
            ಪಕ್ಷ VT_INT:
	        ಯದಿ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        ಭಙ್ಗ;
#endif
	    ಸ್ವಭಾವ:
                //tcc_internal_error("unexpected type");
                ಭಙ್ಗ;
	    }
	}
        vtop--;
    } ಅನ್ಯಥಾ {
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
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer(init_params *p, CType *type, unsigned long c, ಪೂರ್ಣಾಙ್ಕ flags)
{
    ಪೂರ್ಣಾಙ್ಕ len, n, no_oblock, i;
    ಪೂರ್ಣಾಙ್ಕ size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ಯದಿ (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_ಸಾಲು(tcc_state), tcc_tcov_check_ಸಾಲು (tcc_state, 1);

    ಯದಿ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        ಪೂರ್ಣಾಙ್ಕ ncw_prev = nocode_wanted;
        ಯದಿ ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? ಅಭಿವ್ಯಕ್ತಿ_ANY : ಅಭಿವ್ಯಕ್ತಿ_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ಯದಿ (type->t & VT_ARRAY) {
        no_oblock = 1;
        ಯದಿ (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        ಯದಿ ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ಅನ್ಯಥಾ
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ಯದಿ (size1 != (tok == TOK_STR ? 1 : ಪರಿಮಾಣ(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ಯಾವತ್ (tok == TOK_STR || tok == TOK_LSTR) {
                ಯದಿ (initstr.size)
                  initstr.size -= size1;
                ಯದಿ (tok == TOK_STR)
                  len += tokc.str.size;
                ಅನ್ಯಥಾ
                  len += tokc.str.size / ಪರಿಮಾಣ(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            ಯದಿ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                ಗಚ್ಛ do_init_array;
            }

            decl_design_flex(p, s, len);
            ಯದಿ (!(flags & DIF_SIZE_ONLY)) {
                ಪೂರ್ಣಾಙ್ಕ nb = n, ch;
                ಯದಿ (len < nb)
                    nb = len;
                ಯದಿ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ಯದಿ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ಯದಿ (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } ಅನ್ಯಥಾ {
                    ಪ್ರತಿ(i=0;i<n;i++) {
                        ಯದಿ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ಯದಿ (flags & DIF_CLEAR)
                            ಭಙ್ಗ;
                          ಯದಿ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            ಭಙ್ಗ;
                          }
                          ch = 0;
                        } ಅನ್ಯಥಾ ಯದಿ (size1 == 1)
                          ch = ((unsigned ವರ್ಣ *)initstr.data)[i];
                        ಅನ್ಯಥಾ
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ಯದಿ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } ಅನ್ಯಥಾ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ಯದಿ (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ಯಾವತ್ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ಯದಿ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ಯದಿ (no_oblock && len >= n*size1)
		        ಭಙ್ಗ;
		} ಅನ್ಯಥಾ {
		    ಯದಿ (s->type.t == VT_UNION)
		        f = ರಿಕ್ತ;
		    ಅನ್ಯಥಾ
		        f = f->next;
		    ಯದಿ (no_oblock && f == ರಿಕ್ತ)
		        ಭಙ್ಗ;
		}

		ಯದಿ (tok == '}')
		    ಭಙ್ಗ;
		skip(',');
	    }
        }
        ಯದಿ (!no_oblock)
            skip('}');

    } ಅನ್ಯಥಾ ಯದಿ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        ಗಚ್ಛ one_elem;

    } ಅನ್ಯಥಾ ಯದಿ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ಯದಿ ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	ಗಚ್ಛ do_init_list;

    } ಅನ್ಯಥಾ ಯದಿ (tok == '{') {
        ಯದಿ (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ಅನ್ಯಥಾ one_elem: ಯದಿ ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ಯದಿ (flags & DIF_HAVE_ELEM)
            vpop();
        ಅನ್ಯಥಾ
            skip_or_save_block(ರಿಕ್ತ);

    } ಅನ್ಯಥಾ {
	ಯದಿ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ಯದಿ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? ಅಭಿವ್ಯಕ್ತಿ_ANY : ಅಭಿವ್ಯಕ್ತಿ_CONST);
	}
        ಯದಿ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ಅನ್ಯಥಾ
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
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer_alloc(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಙ್ಕ r, 
                                   ಪೂರ್ಣಾಙ್ಕ has_init, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ scope)
{
    ಪೂರ್ಣಾಙ್ಕ size, align, addr;
    TokenString *init_str = ರಿಕ್ತ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    ಪೂರ್ಣಾಙ್ಕ bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    ಯದಿ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        ಯದಿ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ಯದಿ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ಪ್ರತ್ಯಾಗಮ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ಯದಿ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = ರಿಕ್ತ;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ಯದಿ (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ಯದಿ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ಯದಿ (IS_BT_ARRAY(type->t))
            type->ref = sym_ತಳ್ಳು(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ಅನ್ಯಥಾ ಯದಿ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        ಯದಿ (field) {
            ಯಾವತ್ (field->next)
                field = field->next;
            ಯದಿ (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    ಯದಿ (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ಯದಿ (!has_init)
            ಗಚ್ಛ err_size;
        ಯದಿ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ಯಾವತ್ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } ಅನ್ಯಥಾ
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
        ಯದಿ (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ಯದಿ (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ಯದಿ (ad->a.aligned) {
	ಪೂರ್ಣಾಙ್ಕ speca = 1 << (ad->a.aligned - 1);
        ಯದಿ (speca > align)
            align = speca;
    } ಅನ್ಯಥಾ ಯದಿ (ad->a.packed) {
        align = 1;
    }

    ಯದಿ (!v && NODATA_WANTED)
        size = 0, align = 1;

    ಯದಿ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ರಿಕ್ತ;
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        ಯದಿ (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    ಯದಿ (ad->asm_label) {
		ಪೂರ್ಣಾಙ್ಕ reg = asm_parse_regvar(ad->asm_label);
		ಯದಿ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_ತಳ್ಳು(v, type, r, addr);
	    ಯದಿ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ಅನ್ಯಥಾ {
            /* push local reference */
            vset(type, r, addr);
        }
    } ಅನ್ಯಥಾ {
        CType *tp = type;
        ಪೂರ್ಣಾಙ್ಕ is_const;

        ಯಾವತ್ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ಯದಿ (!sec) {
            ಯದಿ (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ಅನ್ಯಥಾ ಯದಿ (is_const) {
		sec = rodata_section;
            } ಅನ್ಯಥಾ ಯದಿ (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ಅನ್ಯಥಾ ಯದಿ (tcc_state->nocommon)
                sec = bss_section;
        } ಅನ್ಯಥಾ ಯದಿ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ಯದಿ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ಯದಿ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (bcheck)
            size = size + 1; /* add padding */
#endif
        ಯದಿ (sec) {
	    addr = section_add(sec, size, align);
        } ಅನ್ಯಥಾ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ಯದಿ (v) {
            ಯದಿ (!sym) {
                sym = sym_ತಳ್ಳು(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ರಿಕ್ತ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } ಅನ್ಯಥಾ {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ಯದಿ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * ಪರಿಮಾಣ(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    ಯದಿ (type->t & VT_VLA) {
        ಪೂರ್ಣಾಙ್ಕ a;

        ಯದಿ (has_init)
            tcc_error("variable length array cannot be initialized");

        ಯದಿ (NODATA_WANTED)
            ಗಚ್ಛ no_alloc;

        /* save before-VLA stack pointer if needed */
        ಯದಿ (cur_scope->vla.ಅಂಕೆ == 0) {
            ಯದಿ (cur_scope->prev && cur_scope->prev->vla.ಅಂಕೆ) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } ಅನ್ಯಥಾ {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#ಯದಿ defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.ಅಂಕೆ++;
    } ಅನ್ಯಥಾ ಯದಿ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ಯದಿ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ಯದಿ (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ಸ್ಥಿರ ಶೂನ್ಯ func_vla_arg_code(Sym *arg)
{
    ಪೂರ್ಣಾಙ್ಕ align;
    TokenString *vla_array_tok = ರಿಕ್ತ;

    ಯದಿ (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    ಯದಿ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

ಸ್ಥಿರ ಶೂನ್ಯ func_vla_arg(Sym *sym)
{
    Sym *arg;

    ಪ್ರತಿ (arg = sym->type.ref->next; arg; arg = arg->next)
        ಯದಿ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ byref)
{
    s = sym_find(s->v);
    ಯದಿ (!s) /* unnamed parameters, not enabled */
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    s->c = c;
    ಯದಿ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ಪ್ರತ್ಯಾಗಮ s;
}

/* push parameters (and their types), last first */
ಸ್ಥಿರ ಶೂನ್ಯ sym_ತಳ್ಳು_params(Sym *ref)
{
    Sym *s = ref;
    ಯಾವತ್ (s->next)
        s = s->next;
    ಯಾವತ್ (s != ref) {
        ಯದಿ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_ರಾಶಿ);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ಸ್ಥಿರ ಶೂನ್ಯ gen_function(Sym *sym)
{
    ಸಂರಚನಾ scope f = { 0 };

    cur_scope = ಬೇರು_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    ಯದಿ (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ರಿಕ್ತ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    ಯದಿ (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    ಯದಿ (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ರಾಶಿ, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ತಳ್ಳು_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(ರಿಕ್ತ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_ತೆಗೆ(&local_ರಾಶಿ, ರಿಕ್ತ, 0);
    label_ತೆಗೆ(&global_label_ರಾಶಿ, ರಿಕ್ತ, 0);
    sym_ತೆಗೆ(&all_cleanups, ರಿಕ್ತ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = ರಿಕ್ತ;
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

ಸ್ಥಿರ ಶೂನ್ಯ gen_inline_functions(TCCState *s)
{
    Sym *sym;
    ಪೂರ್ಣಾಙ್ಕ inline_generated, i;
    ಸಂರಚನಾ InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    ಕುರು {
        inline_generated = 0;
        ಪ್ರತಿ (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ಯದಿ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ರಿಕ್ತ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } ಯಾವತ್ (inline_generated);
    tcc_close();
}

ಸ್ಥಿರ ಶೂನ್ಯ free_inline_functions(TCCState *s)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    /* free tokens of unused inline functions */
    ಪ್ರತಿ (i = 0; i < s->nb_inline_fns; ++i) {
        ಸಂರಚನಾ InlineFunc *fn = s->inline_fns[i];
        ಯದಿ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ಸ್ಥಿರ ಶೂನ್ಯ do_Static_assert(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ;

    next();
    skip('(');
    c = ಅಭಿವ್ಯಕ್ತಿ_const();
    ಸಂದೇಶ = "_Static_assert fail";
    ಯದಿ (tok == ',') {
        next();
        ಸಂದೇಶ = parse_mult_str("string constant")->data;
    }
    skip(')');
    ಯದಿ (c == 0)
        tcc_error("%s", ಸಂದೇಶ);
    skip(';');
}

#ifdef TCC_TARGET_PE
ಸ್ಥಿರ ಶೂನ್ಯ pe_check_linkage(CType *type, AttributeDef *ad)
{
    ಯದಿ (!ad->a.dllimport && !ad->a.dllexport)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ಯದಿ (type->t & VT_TYPEDEF) {
        ಧ್ರುವ ವರ್ಣ *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ಅನ್ಯಥಾ ಯದಿ (ad->a.dllimport) {
        ಯದಿ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ಅನ್ಯಥಾ
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ decl(ಪೂರ್ಣಾಙ್ಕ l)
{
    ಪೂರ್ಣಾಙ್ಕ v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ಯಾವತ್ (1) {

        oldint = 0;
        ಯದಿ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ಯದಿ (l == VT_JMP)
                ಪ್ರತ್ಯಾಗಮ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ಯದಿ (tok == ';' && l != VT_CMP) {
                next();
                ಅನುವರ್ತ;
            }
            ಯದಿ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ಅನುವರ್ತ;
            }
            ಯದಿ (l != VT_CONST)
                ಭಙ್ಗ;
            ಯದಿ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ಅನುವರ್ತ;
            }
            ಯದಿ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ಅನ್ಯಥಾ {
                ಯದಿ (tok != TOK_EOF)
                    expect("declaration");
                ಭಙ್ಗ;
            }
        }

        ಯದಿ (tok == ';') {
            ಯದಿ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            ಅನ್ಯಥಾ ಯದಿ (IS_ENUM(btype.t))
                ; /* enum decl */
            ಅನ್ಯಥಾ
                tcc_warning("useless type defines no instances");
            ಯದಿ (l == VT_JMP)
                ಪ್ರತ್ಯಾಗಮ 1;
            next();
            ಅನುವರ್ತ;
        }

        ಯಾವತ್ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            ಯದಿ ((type.t & VT_BTYPE) == VT_FUNC) {
                ಯದಿ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ಯದಿ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ಯದಿ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ಯದಿ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ಅನ್ಯಥಾ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ಅನ್ಯಥಾ ಯದಿ (oldint) {
                tcc_warning("type defaults to int");
            }

            ಯದಿ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ಯದಿ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ಯದಿ (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            ಯದಿ (tok == '{') {
                ಯದಿ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ಯದಿ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                ಪ್ರತಿ (sa = sym->type.ref; (sa = sa->next) != ರಿಕ್ತ;) {
                    ಯದಿ (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    ಯದಿ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ಯದಿ (sym->type.t & VT_INLINE) {
                    ಸಂರಚನಾ InlineFunc *fn;
                    fn = tcc_malloc(ಪರಿಮಾಣ *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } ಅನ್ಯಥಾ {
                    /* compute text section */
                    cur_text_section = text_section;
                    ಯದಿ (ad.section) {
                        cur_text_section = ad.section;
                        ಯದಿ (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                ಭಙ್ಗ;
            } ಅನ್ಯಥಾ {
                has_init = 0;
		ಯದಿ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    ಪ್ರತಿ (sym = func_vt.ref->next; sym; sym = sym->next)
			ಯದಿ ((sym->v & ~SYM_FIELD) == v)
			    ಗಚ್ಛ found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ರಿಕ್ತ));
                found:
		    ಯದಿ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ರಿಕ್ತ));
		    ಯದಿ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ರಿಕ್ತ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ಅನ್ಯಥಾ ಯದಿ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    ಯದಿ (sym && sym->sym_scope == local_scope) {
                        ಯದಿ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ರಿಕ್ತ));
                        sym->type = type;
                    } ಅನ್ಯಥಾ {
                        sym = sym_ತಳ್ಳು(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ಯದಿ ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    ಯದಿ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ಅನ್ಯಥಾ ಯದಿ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ಅನ್ಯಥಾ {
                    r = 0;
                    ಯದಿ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } ಅನ್ಯಥಾ ಯದಿ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ಯದಿ (tok == '=')
                        has_init = 1;

                    ಯದಿ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ಅನ್ಯಥಾ {
                        ಯದಿ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ಅನ್ಯಥಾ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ಯದಿ (has_init)
                            next();
                        ಅನ್ಯಥಾ ಯದಿ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ಯದಿ (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        ಯದಿ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_ಮೌಲ್ಯ, esym->st_size, 1);
                    }
                }
                ಯದಿ (tok != ',') {
                    ಯದಿ (l == VT_JMP)
                        ಪ್ರತ್ಯಾಗಮ has_init ? v : 1;
                    skip(';');
                    ಭಙ್ಗ;
                }
                next();
            }
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
