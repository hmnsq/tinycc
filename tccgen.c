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

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ rsym, anon_sym, ind, loc;

ST_ದತ್ತಾಂಶ Sym *global_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *local_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *define_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *global_label_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *local_label_ರಾಶಿ;

ಸ್ಥಿರ Sym *sym_free_ಮೊದಲ;
ಸ್ಥಿರ ಶೂನ್ಯ **sym_pools;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ nb_sym_pools;

ಸ್ಥಿರ Sym *all_cleanups, *pending_gotos;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ local_scope;
ST_ದತ್ತಾಂಶ ಅಕ್ಷರ debug_modes;

ST_ದತ್ತಾಂಶ SValue *vtop;
ಸ್ಥಿರ SValue _vstack[1 + VSTACK_ಗಾತ್ರ];
#ವ್ಯಾಖ್ಯಾನಿಸು vstack (_vstack + 1)

ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ nocode_wanted; /* no code generation wanted */
#ವ್ಯಾಖ್ಯಾನಿಸು NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#ವ್ಯಾಖ್ಯಾನಿಸು ದತ್ತಾಂಶ_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂಕೇತ_OFF_ಬಿಟ್ 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂಕೇತ_OFF() ಆದರೆ(!nocode_wanted)(nocode_wanted |= ಸಂಕೇತ_OFF_ಬಿಟ್)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂಕೇತ_ON() (nocode_wanted &= ~ಸಂಕೇತ_OFF_ಬಿಟ್)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#ವ್ಯಾಖ್ಯಾನಿಸು NOEVAL_ಮುಖವಾಡ 0x0000FFFF
#ವ್ಯಾಖ್ಯಾನಿಸು NOEVAL_WANTED (nocode_wanted & NOEVAL_ಮುಖವಾಡ)

/* no code output when parsing constant expressions */
#ವ್ಯಾಖ್ಯಾನಿಸು CONST_WANTED_ಬಿಟ್  0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು CONST_WANTED_ಮುಖವಾಡ 0x0FFF0000
#ವ್ಯಾಖ್ಯಾನಿಸು CONST_WANTED  (nocode_wanted & CONST_WANTED_ಮುಖವಾಡ)

ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ global_ಅಭಿವ್ಯಕ್ತಿ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ದತ್ತಾಂಶ CType func_vt; /* current function return type (used by return instruction) */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_var; /* true if current function is variadic (used by return instruction) */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_vc; /* stack address for implicit struct return storage */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_ind; /* function start address */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ func_old;
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *funcname;
ST_ದತ್ತಾಂಶ CType int_type, func_old_type, char_type, char_ಸೂಚಕ_type;
ಸ್ಥಿರ CString initstr;

#ಆದರೆ PTR_ಗಾತ್ರ == 4
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ಗಾತ್ರ_T (VT_INT | VT_UNSIGNED)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_PTRDIFF_T VT_INT
#ಅಥವಾಆದರೆ LONG_ಗಾತ್ರ == 4
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ಗಾತ್ರ_T (VT_LLONG | VT_UNSIGNED)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_PTRDIFF_T VT_LLONG
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ಗಾತ್ರ_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ರಚನೆ switch_t {
    ರಚನೆ case_t {
        int64_t v1, v2;
        ಪೂರ್ಣಾಂಕ ind, ಸಾಲು;
    } **p; ಪೂರ್ಣಾಂಕ n; /* list of case ranges */
    ಪೂರ್ಣಾಂಕ def_sym; /* default symbol */
    ಪೂರ್ಣಾಂಕ nocode_wanted;
    ಪೂರ್ಣಾಂಕ *bsym;
    ರಚನೆ scope *scope;
    ರಚನೆ switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ತಾತ್ಕಾಲಿಕ_LOCAL_VARIABLE_ಸಂಖ್ಯೆ 8
/*list of temporary local variables on the stack in current function. */
ಸ್ಥಿರ ರಚನೆ ತಾತ್ಕಾಲಿಕ_local_variable {
	ಪೂರ್ಣಾಂಕ location; //offset on stack. Svalue.c.i
	ಗಿಡ್ಡ ಗಾತ್ರ_2;
	ಗಿಡ್ಡ align;
} arr_ತಾತ್ಕಾಲಿಕ_local_vars[MAX_ತಾತ್ಕಾಲಿಕ_LOCAL_VARIABLE_ಸಂಖ್ಯೆ];
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ nb_ತಾತ್ಕಾಲಿಕ_local_vars;

ಸ್ಥಿರ ರಚನೆ scope {
    ರಚನೆ scope *prev;
    ರಚನೆ { ಪೂರ್ಣಾಂಕ loc, locorig, ಅಂಕೆ; } vla;
    ರಚನೆ { Sym *s; ಪೂರ್ಣಾಂಕ n; } cl;
    ಪೂರ್ಣಾಂಕ *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ಬೇರು_scope;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    Section *sec;
    ಪೂರ್ಣಾಂಕ local_ಸ್ಥಾನಾಂತರ;
    Sym *flex_array_ref;
} init_params;

#ಆದರೆ 1
#ವ್ಯಾಖ್ಯಾನಿಸು precedence_parser
ಸ್ಥಿರ ಶೂನ್ಯ init_prec(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ ಖಂಡ(ಪೂರ್ಣಾಂಕ flags);
#ವ್ಯಾಖ್ಯಾನಿಸು STMT_ಅಭಿವ್ಯಕ್ತಿ 1
#ವ್ಯಾಖ್ಯಾನಿಸು STMT_COMPOUND 2

ಸ್ಥಿರ ಶೂನ್ಯ gen_cast(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ gen_cast_s(ಪೂರ್ಣಾಂಕ t);
ಸ್ಥಿರ ಸಾಲೊಳಗೆ CType *pointed_type(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ check_restrict_type(CType *type);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ type_qualifiers(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ parse_btype_qualify(CType *type, ಪೂರ್ಣಾಂಕ qualifiers);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_compatible_types(CType *type1, CType *type2);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_btype(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ ignore_label);
ಸ್ಥಿರ CType *type_decl(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ *v, ಪೂರ್ಣಾಂಕ td);
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಅಭಿವ್ಯಕ್ತಿ_type(CType *type);
ಸ್ಥಿರ ಶೂನ್ಯ init_putv(init_params *p, CType *type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c);
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer(init_params *p, CType *type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c, ಪೂರ್ಣಾಂಕ flags);
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer_alloc(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ has_init, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ scope);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ decl(ಪೂರ್ಣಾಂಕ l);
ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_eq(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ vpush_type_ಗಾತ್ರ(CType *type, ಪೂರ್ಣಾಂಕ *a);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_compatible_unqualified_types(CType *type1, CType *type2);
ಸ್ಥಿರ ಸಾಲೊಳಗೆ int64_t ಅಭಿವ್ಯಕ್ತಿ_const64(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ vpush64(ಪೂರ್ಣಾಂಕ ty, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v);
ಸ್ಥಿರ ಶೂನ್ಯ vpush(CType *type);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gvtst(ಪೂರ್ಣಾಂಕ inv, ಪೂರ್ಣಾಂಕ t);
ಸ್ಥಿರ ಶೂನ್ಯ gen_inline_functions(TCCState *s);
ಸ್ಥಿರ ಶೂನ್ಯ free_inline_functions(TCCState *s);
ಸ್ಥಿರ ಶೂನ್ಯ skip_or_save_ಖಂಡ(TokenString **str);
ಸ್ಥಿರ ಶೂನ್ಯ gv_dup(ಶೂನ್ಯ);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ get_ತಾತ್ಕಾಲಿಕ_local_var(ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2,ಪೂರ್ಣಾಂಕ align,ಪೂರ್ಣಾಂಕ *r2);
ಸ್ಥಿರ ಶೂನ್ಯ cast_error(CType *st, CType *dt);
ಸ್ಥಿರ ಶೂನ್ಯ ಕೊನೆ_switch(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ do_Static_assert(ಶೂನ್ಯ);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಂಕ t)
{
  ಆದರೆ (t) {
    gsym_addr(t, ind);
    ಸಂಕೇತ_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gind()
{
  ಪೂರ್ಣಾಂಕ t = ind;
  ಸಂಕೇತ_ON();
  ಆದರೆ (debug_modes)
    tcc_tcov_ಖಂಡ_begin(tcc_state);
  ಹಿಂತಿರುಗಿ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ಸ್ಥಿರ ಶೂನ್ಯ gjmp_addr_acs(ಪೂರ್ಣಾಂಕ t)
{
  gjmp_addr(t);
  ಸಂಕೇತ_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gjmp_acs(ಪೂರ್ಣಾಂಕ t)
{
  t = gjmp(t);
  ಸಂಕೇತ_OFF();
  ಹಿಂತಿರುಗಿ t;
}

/* These are #undef'd at the end of this file */
#ವ್ಯಾಖ್ಯಾನಿಸು gjmp_addr gjmp_addr_acs
#ವ್ಯಾಖ್ಯಾನಿಸು gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN ಪೂರ್ಣಾಂಕ is_float(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ bt = t & VT_BTYPE;
    ಹಿಂತಿರುಗಿ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ is_integer_btype(ಪೂರ್ಣಾಂಕ bt)
{
    ಹಿಂತಿರುಗಿ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ btype_ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ bt)
{
    ಹಿಂತಿರುಗಿ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_ಗಾತ್ರ : 0;
}

/* returns function return register from type */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ R_RET(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ (!is_float(t))
        ಹಿಂತಿರುಗಿ REG_IRET;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ಆದರೆ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಹಿಂತಿರುಗಿ TREG_ST0;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    ಆದರೆ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಹಿಂತಿರುಗಿ REG_IRET;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ REG_FRET;
}

/* returns 2nd function return register, if any */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ R2_RET(ಪೂರ್ಣಾಂಕ t)
{
    t &= VT_BTYPE;
#ಆದರೆ PTR_ಗಾತ್ರ == 4
    ಆದರೆ (t == VT_LLONG)
        ಹಿಂತಿರುಗಿ REG_IRE2;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
    ಆದರೆ (t == VT_QLONG)
        ಹಿಂತಿರುಗಿ REG_IRE2;
    ಆದರೆ (t == VT_QFLOAT)
        ಹಿಂತಿರುಗಿ REG_FRE2;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    ಆದರೆ (t == VT_LDOUBLE)
        ಹಿಂತಿರುಗಿ REG_IRE2;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ VT_CONST;
}

/* returns true for two-word types */
#ವ್ಯಾಖ್ಯಾನಿಸು USING_TWO_ಪದಗಳು(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ಸ್ಥಿರ ಶೂನ್ಯ PUT_R_RET(SValue *sv, ಪೂರ್ಣಾಂಕ t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ RC_RET(ಪೂರ್ಣಾಂಕ t)
{
    ಹಿಂತಿರುಗಿ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ RC_TYPE(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ (!is_float(t))
        ಹಿಂತಿರುಗಿ RC_INT;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ಆದರೆ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಹಿಂತಿರುಗಿ RC_ST0;
    ಆದರೆ ((t & VT_BTYPE) == VT_QFLOAT)
        ಹಿಂತಿರುಗಿ RC_FRET;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    ಆದರೆ ((t & VT_BTYPE) == VT_LDOUBLE)
        ಹಿಂತಿರುಗಿ RC_INT;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ RC2_TYPE(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ rc)
{
    ಆದರೆ (!USING_TWO_ಪದಗಳು(t))
        ಹಿಂತಿರುಗಿ 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_IRE2
    ಆದರೆ (rc == RC_IRET)
        ಹಿಂತಿರುಗಿ RC_IRE2;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_FRE2
    ಆದರೆ (rc == RC_FRET)
        ಹಿಂತಿರುಗಿ RC_FRE2;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (rc & RC_FLOAT)
        ಹಿಂತಿರುಗಿ RC_FLOAT;
    ಹಿಂತಿರುಗಿ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC ಪೂರ್ಣಾಂಕ ieee_finite(ದ್ವಿಗುಣ d)
{
    ಪೂರ್ಣಾಂಕ p[4];
    ಸ್ಮರಣೆ_ನಕಲು(p, &d, ಗಾತ್ರ(ದ್ವಿಗುಣ));
    ಹಿಂತಿರುಗಿ ((ಚಿಹ್ನೆರಹಿತ)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC ಶೂನ್ಯ test_lvalue(ಶೂನ್ಯ)
{
    ಆದರೆ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC ಶೂನ್ಯ check_vstack(ಶೂನ್ಯ)
{
    ಆದರೆ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (ಪೂರ್ಣಾಂಕ)(vtop - vstack + 1));
}

#ಆದರೆ 0
/* dump 'b' vstack entries starting with 'a'  */
ಶೂನ್ಯ pv (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *lbl, ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        ಬರೆ("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (ಪೂರ್ಣಾಂಕ)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ psyms(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, Sym *s, Sym *ಕೊನೆಯ)
{
    ಬರೆ("%-8s scope         v        c        r   type.t\n", ಸಂದೇಶ);
    ಆಗ (s && s != ಕೊನೆಯ) {
        ಬರೆ("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ type_ಗಮ್ಯ_str(ಅಕ್ಷರ *buf, ಪೂರ್ಣಾಂಕ buf_ಗಾತ್ರ, CType *type, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *varstr);

/* print type */
ಸ್ಥಿರ ಶೂನ್ಯ ptype(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, CType *type, ಪೂರ್ಣಾಂಕ v)
{
    ಅಕ್ಷರ buf[500];
    type_ಗಮ್ಯ_str(buf, ಗಾತ್ರ(buf), type,
        (v & ~SYM_ಕ್ಷೇತ್ರ) ? get_tok_str(v, ಖಾಲಿ) : ಖಾಲಿ);
    ಬರೆ("%s : %s;\n", ಸಂದೇಶ, buf);
}
#ಆದರೆ_ಅಂತ್ಯ

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC ಶೂನ್ಯ tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, ಗಾತ್ರ *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ಆದರೆ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_ಸೂಚಕ_type = char_type;
    mk_ಸೂಚಕ(&char_ಸೂಚಕ_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ precedence_parser
    init_prec();
#ಆದರೆ_ಅಂತ್ಯ
    cstr_new(&initstr);
}

ST_FUNC ಪೂರ್ಣಾಂಕ tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_ಮೊದಲ_ANOM;
    nocode_wanted = ದತ್ತಾಂಶ_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_ಅಭಿವ್ಯಕ್ತಿ = 0;

    tcc_debug_ಆರಂಭ(s1);
    tcc_tcov_ಆರಂಭ (s1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    arm_init(s1);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
    ಬರೆ("%s: **** new file\n", file->filename);
#ಆದರೆ_ಅಂತ್ಯ
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_ಅಂಕೆ | PARSE_FLAG_TOK_STR;
    ಮುಂದಿನ();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ಆದರೆ TCC_EH_ಚೌಕಟ್ಟು
    tcc_eh_ಚೌಕಟ್ಟು_ಕೊನೆ(s1);
#ಆದರೆ_ಅಂತ್ಯ
    tcc_debug_ಕೊನೆ(s1);
    tcc_tcov_ಕೊನೆ(s1);
    ಹಿಂತಿರುಗಿ 0;
}

ST_FUNC ಶೂನ್ಯ tccgen_ಮುಕ್ತಾಯ(TCCState *s1)
{
    tcc_debug_ಕೊನೆ(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_ತೆಗೆ(&global_ರಾಶಿ, ಖಾಲಿ, 0);
    sym_ತೆಗೆ(&local_ರಾಶಿ, ಖಾಲಿ, 0);
    /* free preprocessor macros */
    free_ನಿರೂಪಿಸುತ್ತದೆ(ಖಾಲಿ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_ದತ್ತಾಂಶ, &nb_stk_ದತ್ತಾಂಶ);
    ಆಗ (cur_switch)
        ಕೊನೆ_switch();
    local_scope = 0;
    loop_scope = ಖಾಲಿ;
    all_cleanups = ಖಾಲಿ;
    pending_gotos = ಖಾಲಿ;
    nb_ತಾತ್ಕಾಲಿಕ_local_vars = 0;
    global_label_ರಾಶಿ = ಖಾಲಿ;
    local_label_ರಾಶಿ = ಖಾಲಿ;
    cur_ಪಠ್ಯ_section = ಖಾಲಿ;
    sym_free_ಮೊದಲ = ಖಾಲಿ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ಆದರೆ (!s || !s->c)
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
  ಹಿಂತಿರುಗಿ &((ElfSym *)symtab_section->ದತ್ತಾಂಶ)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC ಶೂನ್ಯ update_storage(Sym *sym)
{
    ElfSym *esym;
    ಪೂರ್ಣಾಂಕ sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ಆದರೆ (!esym)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ಆದರೆ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sym->a.weak)
        sym_bind = STB_WEAK;
    ಇಲ್ಲದಿದ್ದರೆ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ಆದರೆ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ಆದರೆ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ 0
    ಬರೆ("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ಖಾಲಿ),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#ಆದರೆ_ಅಂತ್ಯ
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC ಶೂನ್ಯ put_extern_sym2(Sym *sym, ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ,
                            addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2,
                            ಪೂರ್ಣಾಂಕ can_ಕೂಡಿಸು_underscore)
{
    ಪೂರ್ಣಾಂಕ sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    ಅಕ್ಷರ buf1[256];

    ಆದರೆ (!sym->c) {
        name = get_tok_str(sym->v, ಖಾಲಿ);
        t = sym->type.t;
        ಆದರೆ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ಆದರೆ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t & VT_TLS) {
            sym_type = STT_TLS;
        } ಇಲ್ಲದಿದ್ದರೆ {
            sym_type = STT_OBJECT;
        }
        ಆದರೆ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ಇಲ್ಲದಿದ್ದರೆ
            sym_bind = STB_GLOBAL;
        other = 0;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        ಆದರೆ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ಆದರೆ (ref->a.nodecorate) {
                can_ಕೂಡಿಸು_underscore = 0;
            }
            ಆದರೆ (ref->f.func_call == FUNC_STDCALL && can_ಕೂಡಿಸು_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_ವಾದಗಳು * PTR_ಗಾತ್ರ);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_ಕೂಡಿಸು_underscore = 0;
            }
        }
#ಆದರೆ_ಅಂತ್ಯ

        ಆದರೆ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ಖಾಲಿ);
            can_ಕೂಡಿಸು_underscore = 0;
        }

        ಆದರೆ (tcc_state->leading_underscore && can_ಕೂಡಿಸು_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, ಗಾತ್ರ(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, ಮೌಲ್ಯ, ಗಾತ್ರ_2, info, other, sh_ಅಂಕೆ, name);

        ಆದರೆ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_ಅಂಕೆ, sym_bind, sym_type);

    } ಇಲ್ಲದಿದ್ದರೆ {
        esym = elfsym(sym);
        esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
        esym->st_ಗಾತ್ರ = ಗಾತ್ರ_2;
        esym->st_shndx = sh_ಅಂಕೆ;
    }
    update_storage(sym);
}

ST_FUNC ಶೂನ್ಯ put_extern_sym(Sym *sym, Section *s, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಆದರೆ (nocode_wanted && (NODATA_WANTED || (s && s == cur_ಪಠ್ಯ_section)))
        ಹಿಂತಿರುಗಿ;
    put_extern_sym2(sym, s ? s->sh_ಅಂಕೆ : SHN_UNDEF, ಮೌಲ್ಯ, ಗಾತ್ರ_2, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC ಶೂನ್ಯ greloca(Section *s, Sym *sym, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type,
                     addr_t addend)
{
    ಪೂರ್ಣಾಂಕ c = 0;

    ಆದರೆ (nocode_wanted && s == cur_ಪಠ್ಯ_section)
        ಹಿಂತಿರುಗಿ;

    ಆದರೆ (sym) {
        ಆದರೆ (0 == sym->c) {
            put_extern_sym(sym, ಖಾಲಿ, 0, 0);
            ಆದರೆ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ಆಗ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, ಸ್ಥಾನಾಂತರ, type, c, addend);
}

#ಆದರೆ PTR_ಗಾತ್ರ == 4
ST_FUNC ಶೂನ್ಯ greloc(Section *s, Sym *sym, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type)
{
    greloca(s, sym, ಸ್ಥಾನಾಂತರ, type, 0);
}
#ಆದರೆ_ಅಂತ್ಯ

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ಸ್ಥಿರ Sym *__sym_malloc(ಶೂನ್ಯ)
{
    Sym *sym_pool, *sym, *ಕೊನೆಯ_sym;
    ಪೂರ್ಣಾಂಕ i;

    sym_pool = tcc_malloc(SYM_POOL_NB * ಗಾತ್ರ(Sym));
    dynarray_ಕೂಡಿಸು(&sym_pools, &nb_sym_pools, sym_pool);

    ಕೊನೆಯ_sym = sym_free_ಮೊದಲ;
    sym = sym_pool;
    ಗಾಗಿ(i = 0; i < SYM_POOL_NB; i++) {
        sym->ಮುಂದಿನ = ಕೊನೆಯ_sym;
        ಕೊನೆಯ_sym = sym;
        sym++;
    }
    sym_free_ಮೊದಲ = ಕೊನೆಯ_sym;
    ಹಿಂತಿರುಗಿ ಕೊನೆಯ_sym;
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ Sym *sym_malloc(ಶೂನ್ಯ)
{
    Sym *sym;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SYM_DEBUG
    sym = sym_free_ಮೊದಲ;
    ಆದರೆ (!sym)
        sym = __sym_malloc();
    sym_free_ಮೊದಲ = sym->ಮುಂದಿನ;
    ಹಿಂತಿರುಗಿ sym;
#ಇಲ್ಲದಿದ್ದರೆ
    sym = tcc_malloc(ಗಾತ್ರ(Sym));
    ಹಿಂತಿರುಗಿ sym;
#ಆದರೆ_ಅಂತ್ಯ
}

ST_INLN ಶೂನ್ಯ sym_free(Sym *sym)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SYM_DEBUG
    sym->ಮುಂದಿನ = sym_free_ಮೊದಲ;
    sym_free_ಮೊದಲ = sym;
#ಇಲ್ಲದಿದ್ದರೆ
    tcc_free(sym);
#ಆದರೆ_ಅಂತ್ಯ
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, ಗಾತ್ರ *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    ಹಿಂತಿರುಗಿ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, ಪೂರ್ಣಾಂಕ v)
{
    ಆಗ (s) {
        ಆದರೆ (s->v == v)
            ಹಿಂತಿರುಗಿ s;
        s = s->prev;
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

/* structure lookup */
ST_INLN Sym *struct_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v)
{
    v -= TOK_IDENT;
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)v >= (ಚಿಹ್ನೆರಹಿತ)(tok_ident - TOK_IDENT))
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v)
{
    v -= TOK_IDENT;
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)v >= (ಚಿಹ್ನೆರಹಿತ)(tok_ident - TOK_IDENT))
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ sym_link(Sym *s, ಪೂರ್ಣಾಂಕ yes)
{
    TokenSym *ts = ಕೋಷ್ಟಕ_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ಆದರೆ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ಇಲ್ಲದಿದ್ದರೆ
        ps = &ts->sym_identifier;
    ಆದರೆ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ಇಲ್ಲದಿದ್ದರೆ {
        *ps = s->prev_tok;
    }
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ಹಿಂತಿರುಗಿ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, CType *type, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ c)
{
    Sym *s, **ps;
    ಆದರೆ (local_ರಾಶಿ)
        ps = &local_ರಾಶಿ;
    ಇಲ್ಲದಿದ್ದರೆ
        ps = &global_ರಾಶಿ;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ಆದರೆ ((v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ಆದರೆ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ಖಾಲಿ));
    }
    ಹಿಂತಿರುಗಿ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ರಾಶಿ, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ಆದರೆ (v < SYM_ಮೊದಲ_ANOM) {
        ps = &ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ಆಗ (*ps != ಖಾಲಿ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    ಹಿಂತಿರುಗಿ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC ಶೂನ್ಯ sym_ತೆಗೆ(Sym **ptop, Sym *b, ಪೂರ್ಣಾಂಕ keep)
{
    Sym *s, *ss;
    ಪೂರ್ಣಾಂಕ v;

    s = *ptop;
    ಆಗ(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ಆದರೆ ((v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM)
            sym_link(s, 0);
	ಆದರೆ (!keep)
	    sym_free(s);
        s = ss;
    }
    ಆದರೆ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v)
{
    v -= TOK_IDENT;
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)v >= (ಚಿಹ್ನೆರಹಿತ)(tok_ident - TOK_IDENT))
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_ident[v]->sym_label;
}

ST_FUNC Sym *label_ತಳ್ಳು(Sym **ptop, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->sym_label;
    ಆದರೆ (ptop == &global_label_ರಾಶಿ) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ಆಗ (*ps != ಖಾಲಿ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    ಹಿಂತಿರುಗಿ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC ಶೂನ್ಯ label_ತೆಗೆ(Sym **ptop, Sym *slast, ಪೂರ್ಣಾಂಕ keep)
{
    Sym *s, *s1;
    ಗಾಗಿ(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ಆದರೆ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ಖಾಲಿ));
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ಖಾಲಿ));
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_ಪಠ್ಯ_section, s->jind, 1);
            }
        }
        /* remove label */
        ಆದರೆ (s->r != LABEL_GONE)
            ಕೋಷ್ಟಕ_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ಆದರೆ (!keep)
            sym_free(s);
        ಇಲ್ಲದಿದ್ದರೆ
            s->r = LABEL_GONE;
    }
    ಆದರೆ (!keep)
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

    ಆದರೆ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~ಸಂಕೇತ_OFF_ಬಿಟ್))
        gv(RC_INT);
}

ಸ್ಥಿರ ಶೂನ್ಯ vsetc(CType *type, ಪೂರ್ಣಾಂಕ r, CValue *vc)
{
    ಆದರೆ (vtop >= vstack + (VSTACK_ಗಾತ್ರ - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ಖಾಲಿ;
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
    ಪೂರ್ಣಾಂಕ v;
    v = vtop->r & VT_VALMASK;
#ಆದರೆ defined(TCC_ಗುರಿ_I386) || defined(TCC_ಗುರಿ_X86_64)
    /* for x86, we need to pop the FP stack */
    ಆದರೆ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (v == VT_CMP) {
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
ಸ್ಥಿರ ಶೂನ್ಯ vpush64(ಪೂರ್ಣಾಂಕ ty, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ಖಾಲಿ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC ಶೂನ್ಯ vpushi(ಪೂರ್ಣಾಂಕ v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ಸ್ಥಿರ ಶೂನ್ಯ vpushs(addr_t v)
{
    vpush64(VT_ಗಾತ್ರ_T, v);
}

/* push long long constant */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ vpushll(ದೀರ್ಘ ದೀರ್ಘ v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC ಶೂನ್ಯ vset(CType *type, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ಸ್ಥಿರ ಶೂನ್ಯ vseti(ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ಖಾಲಿ;
    vset(&type, r, v);
}

ST_FUNC ಶೂನ್ಯ vpushv(SValue *v)
{
    ಆದರೆ (vtop >= vstack + (VSTACK_ಗಾತ್ರ - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ಸ್ಥಿರ ಶೂನ್ಯ vdup(ಶೂನ್ಯ)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC ಶೂನ್ಯ vrotb(ಪೂರ್ಣಾಂಕ n)
{
    SValue tmp;
    ಆದರೆ (--n < 1)
        ಹಿಂತಿರುಗಿ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, ಗಾತ್ರ *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC ಶೂನ್ಯ vrott(ಪೂರ್ಣಾಂಕ n)
{
    SValue tmp;
    ಆದರೆ (--n < 1)
        ಹಿಂತಿರುಗಿ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, ಗಾತ್ರ *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC ಶೂನ್ಯ vrev(ಪೂರ್ಣಾಂಕ n)
{
    ಪೂರ್ಣಾಂಕ i;
    SValue tmp;
    vcheck_cmp();
    ಗಾಗಿ (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC ಶೂನ್ಯ vset_VT_CMP(ಪೂರ್ಣಾಂಕ op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ಸ್ಥಿರ ಶೂನ್ಯ vset_VT_JMP(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ op = vtop->cmp_op;

    ಆದರೆ (vtop->jtrue || vtop->jfalse) {
        ಪೂರ್ಣಾಂಕ origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        ಪೂರ್ಣಾಂಕ inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ಆದರೆ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ಸ್ಥಿರ ಶೂನ್ಯ gvtst_ಗಣ(ಪೂರ್ಣಾಂಕ inv, ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ *p;

    ಆದರೆ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ಆದರೆ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gvtst(ಪೂರ್ಣಾಂಕ inv, ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ op, x, u;

    gvtst_ಗಣ(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ಆದರೆ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ಆದರೆ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ಹಿಂತಿರುಗಿ t;
}

/* generate a zero or nozero test */
ಸ್ಥಿರ ಶೂನ್ಯ gen_test_zero(ಪೂರ್ಣಾಂಕ op)
{
    ಆದರೆ (vtop->r == VT_CMP) {
        ಪೂರ್ಣಾಂಕ j;
        ಆದರೆ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
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
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ತಳ್ಳು(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2);
    ಹಿಂತಿರುಗಿ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ಸ್ಥಿರ ಶೂನ್ಯ vpush_ref(CType *type, Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    vpushsym(type, get_sym_ref(type, sec, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(ಪೂರ್ಣಾಂಕ v, CType *type)
{
    Sym *s;

    s = sym_ಕಂಡುಹಿಡಿ(v);
    ಆದರೆ (!s) {
        /* push forward reference */
        s = global_identifier_ತಳ್ಳು(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ಹಿಂತಿರುಗಿ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(ಪೂರ್ಣಾಂಕ v)
{
    CType ct = { VT_ASM_FUNC, ಖಾಲಿ };
    ಹಿಂತಿರುಗಿ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC ಶೂನ್ಯ vpush_helper_func(ಪೂರ್ಣಾಂಕ v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ ವಿಲೀನ_symattr(ರಚನೆ SymAttr *sa, ರಚನೆ SymAttr *sa1)
{
    ಆದರೆ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ಆದರೆ (sa1->visibility != STV_DEFAULT) {
	ಪೂರ್ಣಾಂಕ vis = sa->visibility;
	ಆದರೆ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ ವಿಲೀನ_funcattr(ರಚನೆ FuncAttr *fa, ರಚನೆ FuncAttr *fa1)
{
    ಆದರೆ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ಆದರೆ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ಆದರೆ (fa1->func_ವಾದಗಳು && !fa->func_ವಾದಗಳು)
      fa->func_ವಾದಗಳು = fa1->func_ವಾದಗಳು;
    ಆದರೆ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ಆದರೆ (fa1->func_ctor)
      fa->func_ctor = 1;
    ಆದರೆ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ ವಿಲೀನ_attr(AttributeDef *ad, AttributeDef *ad1)
{
    ವಿಲೀನ_symattr(&ad->a, &ad1->a);
    ವಿಲೀನ_funcattr(&ad->f, &ad1->f);

    ಆದರೆ (ad1->section)
      ad->section = ad1->section;
    ಆದರೆ (ad1->alias_ಗುರಿ)
      ad->alias_ಗುರಿ = ad1->alias_ಗುರಿ;
    ಆದರೆ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ಆದರೆ (ad1->attr_ಬಹುಲಕ)
      ad->attr_ಬಹುಲಕ = ad1->attr_ಬಹುಲಕ;
}

/* Merge some type attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ patch_type(Sym *sym, CType *type)
{
    ಆದರೆ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ಆದರೆ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ಖಾಲಿ));
        sym->type.t &= ~VT_EXTERN;
    }

    ಆದರೆ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ಆದರೆ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ಆದರೆ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ಖಾಲಿ));

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        ಪೂರ್ಣಾಂಕ static_proto = sym->type.t & VT_STATIC;
        ಪೂರ್ಣಾಂಕ ft1 = sym->type.ref->f.func_type;
        ಪೂರ್ಣಾಂಕ ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ಆದರೆ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ಖಾಲಿ));

        /* set 'inline' if both agree or if one has static */
        ಆದರೆ ((type->t | sym->type.t) & VT_INLINE) {
            ಆದರೆ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ಆದರೆ (0 == (type->t & VT_EXTERN)) {
            ರಚನೆ FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ಆದರೆ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            ವಿಲೀನ_funcattr(&sym->type.ref->f, &f);
        } ಇಲ್ಲದಿದ್ದರೆ {
            sym->type.t &= ~VT_INLINE | static_proto;
            ಆದರೆ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ಆದರೆ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ಖಾಲಿ));
    }
}

/* Merge some storage attributes.  */
ಸ್ಥಿರ ಶೂನ್ಯ patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ಆದರೆ (type)
        patch_type(sym, type);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ಖಾಲಿ));
#ಆದರೆ_ಅಂತ್ಯ
    ವಿಲೀನ_symattr(&sym->a, &ad->a);
    ಆದರೆ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ಸ್ಥಿರ Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ಆದರೆ ((s->v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM)
        sym_link(s, 1);
    ಹಿಂತಿರುಗಿ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ಸ್ಥಿರ ಶೂನ್ಯ move_ref_ಗಮ್ಯ_global(Sym *s)
{
    Sym *l, **lp;
    ಪೂರ್ಣಾಂಕ n, bt;

    bt = s->type.t & VT_BTYPE;
    ಆದರೆ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ಹಿಂತಿರುಗಿ;

    ಗಾಗಿ (s = s->type.ref, n = 0; s; s = s->ಮುಂದಿನ) {
        ಗಾಗಿ (lp = &local_ರಾಶಿ; !!(l = *lp); lp = &l->prev) {
            ಆದರೆ (l == s) {
                *lp = s->prev;
                s->prev = global_ರಾಶಿ, global_ರಾಶಿ = s;
                ಆದರೆ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_ಗಮ್ಯ_global(s);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಆದರೆ ((s->v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_ಕ್ಷೇತ್ರ;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_ಕ್ಷೇತ್ರ;
                    }
                }
                ಆದರೆ (bt != VT_PTR)
                    n = 1;
                ನಿಲ್ಲಿಸು;
            }
        }
        ಆದರೆ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            ನಿಲ್ಲಿಸು;
    }
}

/* define a new external reference to a symbol 'v' */
ಸ್ಥಿರ Sym *external_sym(ಪೂರ್ಣಾಂಕ v, CType *type, ಪೂರ್ಣಾಂಕ r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_ಕಂಡುಹಿಡಿ(v);
    ಆಗ (s && s->sym_scope)
        s = s->prev_tok;

    ಆದರೆ (!s) {
        /* push forward reference */
        s = global_identifier_ತಳ್ಳು(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ಇಲ್ಲದಿದ್ದರೆ {
        patch_storage(s, ad, type);
    }
    ಆದರೆ (local_ರಾಶಿ) {
        /* make sure that type->ref is on global stack */
        move_ref_ಗಮ್ಯ_global(s);
        /* put into local scope */
        sym_copy(s, &local_ರಾಶಿ);
    }
    ಹಿಂತಿರುಗಿ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC ಶೂನ್ಯ save_regs(ಪೂರ್ಣಾಂಕ n)
{
    SValue *p, *p1;
    ಗಾಗಿ(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC ಶೂನ್ಯ save_reg(ಪೂರ್ಣಾಂಕ r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC ಶೂನ್ಯ save_reg_upstack(ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ n)
{
    ಪೂರ್ಣಾಂಕ l, ಗಾತ್ರ_2, align, bt, r2;
    SValue *p, *p1, sv;

    ಆದರೆ ((r &= VT_VALMASK) >= VT_CONST)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    l = r2 = 0;
    ಗಾಗಿ(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ಆದರೆ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ಆದರೆ (!l) {
                bt = p->type.t & VT_BTYPE;
                ಆದರೆ (bt == VT_VOID)
                    ಮುಂದುವರಿ;
                ಆದರೆ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sv.type, &align);
                l = get_ತಾತ್ಕಾಲಿಕ_local_var(ಗಾತ್ರ_2, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ಖಾಲಿ;
                store(p->r & VT_VALMASK, &sv);
#ಆದರೆ defined(TCC_ಗುರಿ_I386) || defined(TCC_ಗುರಿ_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ಆದರೆ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#ಆದರೆ_ಅಂತ್ಯ
                /* special long long case */
                ಆದರೆ (p->r2 < VT_CONST && USING_TWO_ಪದಗಳು(bt)) {
                    sv.c.i += PTR_ಗಾತ್ರ;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ಆದರೆ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ಇಲ್ಲದಿದ್ದರೆ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ಖಾಲಿ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC ಪೂರ್ಣಾಂಕ get_reg_ex(ಪೂರ್ಣಾಂಕ rc, ಪೂರ್ಣಾಂಕ rc2)
{
    ಪೂರ್ಣಾಂಕ r;
    SValue *p;
    
    ಗಾಗಿ(r=0;r<NB_REGS;r++) {
        ಆದರೆ (reg_classes[r] & rc2) {
            ಪೂರ್ಣಾಂಕ n;
            n=0;
            ಗಾಗಿ(p = vstack; p <= vtop; p++) {
                ಆದರೆ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ಆದರೆ (n <= 1)
                ಹಿಂತಿರುಗಿ r;
        }
    }
    ಹಿಂತಿರುಗಿ get_reg(rc);
}
#ಆದರೆ_ಅಂತ್ಯ

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC ಪೂರ್ಣಾಂಕ get_reg(ಪೂರ್ಣಾಂಕ rc)
{
    ಪೂರ್ಣಾಂಕ r;
    SValue *p;

    /* find a free register */
    ಗಾಗಿ(r=0;r<NB_REGS;r++) {
        ಆದರೆ (reg_classes[r] & rc) {
            ಆದರೆ (nocode_wanted)
                ಹಿಂತಿರುಗಿ r;
            ಗಾಗಿ(p=vstack;p<=vtop;p++) {
                ಆದರೆ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    ಹೋಗು notfound;
            }
            ಹಿಂತಿರುಗಿ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    ಗಾಗಿ(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ಆದರೆ (r < VT_CONST && (reg_classes[r] & rc))
            ಹೋಗು save_ಸಿಕ್ಕಿತು;
        r = p->r & VT_VALMASK;
        ಆದರೆ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_ಸಿಕ್ಕಿತು:
            save_reg(r);
            ಹಿಂತಿರುಗಿ r;
        }
    }
    /* Should never comes here */
    ಹಿಂತಿರುಗಿ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ get_ತಾತ್ಕಾಲಿಕ_local_var(ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2,ಪೂರ್ಣಾಂಕ align, ಪೂರ್ಣಾಂಕ *r2)
{
    ಪೂರ್ಣಾಂಕ i;
    ರಚನೆ ತಾತ್ಕಾಲಿಕ_local_variable *ತಾತ್ಕಾಲಿಕ_var;
    SValue *p;
    ಪೂರ್ಣಾಂಕ r;
    ಚಿಹ್ನೆರಹಿತ ಬಳಸಿದ = 0;

    /* mark locations that are still in use */
    ಗಾಗಿ (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ಆದರೆ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ಆದರೆ (r >= 0 && r < MAX_ತಾತ್ಕಾಲಿಕ_LOCAL_VARIABLE_ಸಂಖ್ಯೆ)
	        ಬಳಸಿದ |= 1<<r;
	}
    }
    ಗಾಗಿ (i=0;i<nb_ತಾತ್ಕಾಲಿಕ_local_vars;i++) {
	ತಾತ್ಕಾಲಿಕ_var=&arr_ತಾತ್ಕಾಲಿಕ_local_vars[i];
	ಆದರೆ(!(ಬಳಸಿದ & 1<<i)
	 && ತಾತ್ಕಾಲಿಕ_var->ಗಾತ್ರ_2>=ಗಾತ್ರ_2
	 && ತಾತ್ಕಾಲಿಕ_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ಹಿಂತಿರುಗಿ ತಾತ್ಕಾಲಿಕ_var->location;
	}
    }
    loc = (loc - ಗಾತ್ರ_2) & -align;
    ಆದರೆ (nb_ತಾತ್ಕಾಲಿಕ_local_vars<MAX_ತಾತ್ಕಾಲಿಕ_LOCAL_VARIABLE_ಸಂಖ್ಯೆ) {
	ತಾತ್ಕಾಲಿಕ_var=&arr_ತಾತ್ಕಾಲಿಕ_local_vars[i];
	ತಾತ್ಕಾಲಿಕ_var->location=loc;
	ತಾತ್ಕಾಲಿಕ_var->ಗಾತ್ರ_2=ಗಾತ್ರ_2;
	ತಾತ್ಕಾಲಿಕ_var->align=align;
	nb_ತಾತ್ಕಾಲಿಕ_local_vars++;
	ಹೋಗು ret_tmp;
    }
    *r2 = VT_CONST;
    ಹಿಂತಿರುಗಿ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ಸ್ಥಿರ ಶೂನ್ಯ move_reg(ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ s, ಪೂರ್ಣಾಂಕ t)
{
    SValue sv;

    ಆದರೆ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ಖಾಲಿ;
        sv.r = s;
        sv.c.i = 0;
        ತುಂಬು(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC ಶೂನ್ಯ gaddrof(ಶೂನ್ಯ)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ಆದರೆ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounded_ptr_ಕೂಡಿಸು(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ಆದರೆ (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_ಕೂಡಿಸು);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_ಪಠ್ಯ_section->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ - ಗಾತ್ರ(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ಸ್ಥಿರ ಶೂನ್ಯ gen_bounded_ptr_deref(ಶೂನ್ಯ)
{
    addr_t func;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align;
    ElfW_Rel *rel;
    Sym *sym;

    ಆದರೆ (nocode_wanted)
        ಹಿಂತಿರುಗಿ;

    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
    ಆಯ್ಕೆ(ಗಾತ್ರ_2) {
    ಸ್ಥಿತಿ  1: func = TOK___bound_ptr_indir1; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ  2: func = TOK___bound_ptr_indir2; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ  4: func = TOK___bound_ptr_indir4; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ  8: func = TOK___bound_ptr_indir8; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 12: func = TOK___bound_ptr_indir12; ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 16: func = TOK___bound_ptr_indir16; ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        /* may happen with struct member access */
        ಹಿಂತಿರುಗಿ;
    }
    sym = external_helper_sym(func);
    ಆದರೆ (!sym->c)
        put_extern_sym(sym, ಖಾಲಿ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_ಪಠ್ಯ_section->reloc->ದತ್ತಾಂಶ + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ಸ್ಥಿರ ಶೂನ್ಯ gbound(ಶೂನ್ಯ)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ಆದರೆ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ಆದರೆ (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_ಕೂಡಿಸು();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC ಶೂನ್ಯ gbound_ವಾದಗಳು(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು)
{
    ಪೂರ್ಣಾಂಕ i, v;
    SValue *sv;

    ಗಾಗಿ (i = 1; i <= nb_ವಾದಗಳು; ++i)
        ಆದರೆ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_ವಾದಗಳು;
    ಆದರೆ (sv->r & VT_SYM) {
        v = sv->sym->v;
        ಆದರೆ (v == TOK_setjmp
          || v == TOK__setjmp
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#ಆದರೆ_ಅಂತ್ಯ
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_ಕೂಡಿಸು_epilog = 1;
        }
        ಆದರೆ (v == TOK_alloca)
            func_bound_ಕೂಡಿಸು_epilog = 1;
#ಆದರೆ TARGETOS_NetBSD
        ಆದರೆ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#ಆದರೆ_ಅಂತ್ಯ
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ಸ್ಥಿರ ಶೂನ್ಯ ಕೂಡಿಸು_local_bounds(Sym *s, Sym *e)
{
    ಗಾಗಿ (; s != e; s = s->prev) {
        ಆದರೆ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ಮುಂದುವರಿ;
        /* Add arrays/structs/unions because we always take address */
        ಆದರೆ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_ಕೂಡಿಸು(lbounds_section,
                                                 2 * ಗಾತ್ರ(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = ಗಾತ್ರ_2;
        }
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* add debug info for locals or function parameters, optionally
   register bounds */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_debug_ಕೊನೆ_scope(Sym *b, ಪೂರ್ಣಾಂಕ bounds)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (tcc_state->do_bounds_check && bounds)
        ಕೂಡಿಸು_local_bounds(local_ರಾಶಿ, b);
#ಆದರೆ_ಅಂತ್ಯ
    tcc_ಕೂಡಿಸು_debug_info (tcc_state, local_ರಾಶಿ, b);
}

/* increment an lvalue pointer */
ಸ್ಥಿರ ಶೂನ್ಯ incr_ಸ್ಥಾನಾಂತರ(ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ)
{
    ಪೂರ್ಣಾಂಕ t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(ಸ್ಥಾನಾಂತರ);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ಸ್ಥಿರ ಶೂನ್ಯ incr_bf_adr(ಪೂರ್ಣಾಂಕ o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_ಸ್ಥಾನಾಂತರ(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ಸ್ಥಿರ ಶೂನ್ಯ ತುಂಬು_packed_bf(CType *type, ಪೂರ್ಣಾಂಕ ಬಿಟ್_pos, ಪೂರ್ಣಾಂಕ ಬಿಟ್_ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ n, o, ಬಿಟ್ಟುಗಳು;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    ಬಿಟ್ಟುಗಳು = 0, o = ಬಿಟ್_pos >> 3, ಬಿಟ್_pos &= 7;
    ಮಾಡು {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - ಬಿಟ್_pos;
        ಆದರೆ (n > ಬಿಟ್_ಗಾತ್ರ_2)
            n = ಬಿಟ್_ಗಾತ್ರ_2;
        ಆದರೆ (ಬಿಟ್_pos)
            vpushi(ಬಿಟ್_pos), gen_op(TOK_SHR), ಬಿಟ್_pos = 0; // X B Y
        ಆದರೆ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ಆದರೆ (ಬಿಟ್ಟುಗಳು)
            vpushi(ಬಿಟ್ಟುಗಳು), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        ಬಿಟ್ಟುಗಳು += n, ಬಿಟ್_ಗಾತ್ರ_2 -= n, o = 1;
    } ಆಗ (ಬಿಟ್_ಗಾತ್ರ_2);
    vswap(), vpop();
    ಆದರೆ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - ಬಿಟ್ಟುಗಳು;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ಸ್ಥಿರ ಶೂನ್ಯ store_packed_bf(ಪೂರ್ಣಾಂಕ ಬಿಟ್_pos, ಪೂರ್ಣಾಂಕ ಬಿಟ್_ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ ಬಿಟ್ಟುಗಳು, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    ಬಿಟ್ಟುಗಳು = 0, o = ಬಿಟ್_pos >> 3, ಬಿಟ್_pos &= 7;
    ಮಾಡು {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ಆದರೆ (ಬಿಟ್ಟುಗಳು)
            vpushi(ಬಿಟ್ಟುಗಳು), gen_op(TOK_SHR);
        ಆದರೆ (ಬಿಟ್_pos)
            vpushi(ಬಿಟ್_pos), gen_op(TOK_SHL);
        n = 8 - ಬಿಟ್_pos;
        ಆದರೆ (n > ಬಿಟ್_ಗಾತ್ರ_2)
            n = ಬಿಟ್_ಗಾತ್ರ_2;
        ಆದರೆ (n < 8) {
            m = ((1 << n) - 1) << ಬಿಟ್_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        ಬಿಟ್ಟುಗಳು += n, ಬಿಟ್_ಗಾತ್ರ_2 -= n, ಬಿಟ್_pos = 0, o = 1;
    } ಆಗ (ಬಿಟ್_ಗಾತ್ರ_2);
    vpop(), vpop();
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ adjust_bf(SValue *sv, ಪೂರ್ಣಾಂಕ ಬಿಟ್_pos, ಪೂರ್ಣಾಂಕ ಬಿಟ್_ಗಾತ್ರ_2)
{
    ಪೂರ್ಣಾಂಕ t;
    ಆದರೆ (0 == sv->type.ref)
        ಹಿಂತಿರುಗಿ 0;
    t = sv->type.ref->auxtype;
    ಆದರೆ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ಹಿಂತಿರುಗಿ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC ಪೂರ್ಣಾಂಕ gv(ಪೂರ್ಣಾಂಕ rc)
{
    ಪೂರ್ಣಾಂಕ r, r2, r_ok, r2_ok, rc2, bt;
    ಪೂರ್ಣಾಂಕ ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2, ಗಾತ್ರ_2, align;

    /* NOTE: get_reg can modify vstack[] */
    ಆದರೆ (vtop->type.t & VT_BITFIELD) {
        CType type;

        ಬಿಟ್_pos = ಬಿಟ್_POS(vtop->type.t);
        ಬಿಟ್_ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_ಮುಖವಾಡ;

        type.ref = ಖಾಲಿ;
        type.t = vtop->type.t & VT_UNSIGNED;
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2);

        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ಇಲ್ಲದಿದ್ದರೆ
            type.t |= VT_INT;

        ಆದರೆ (r == VT_STRUCT) {
            ತುಂಬು_packed_bf(&type, ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪೂರ್ಣಾಂಕ ಬಿಟ್ಟುಗಳು = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(ಬಿಟ್ಟುಗಳು - (ಬಿಟ್_pos + ಬಿಟ್_ಗಾತ್ರ_2));
            gen_op(TOK_SHL);
            vpushi(ಬಿಟ್ಟುಗಳು - ಬಿಟ್_ಗಾತ್ರ_2);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ;
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
            ಆದರೆ (NODATA_WANTED)
                ಗಾತ್ರ_2 = 0, align = 1;
            ಸ್ಥಾನಾಂತರ = section_ಕೂಡಿಸು(p.sec, ಗಾತ್ರ_2, align);
            vpush_ref(&vtop->type, p.sec, ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2);
	    vswap();
	    init_putv(&p, &vtop->type, ಸ್ಥಾನಾಂತರ);
	    vtop->r |= VT_LVAL;
        }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (vtop->r & VT_MUSTBOUND) 
            gbound();
#ಆದರೆ_ಅಂತ್ಯ

        bt = vtop->type.t & VT_BTYPE;
        ಆದರೆ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ಹಿಂತಿರುಗಿ vtop->r;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
        /* XXX mega hack */
        ಆದರೆ (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#ಆದರೆ_ಅಂತ್ಯ
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        ಆದರೆ (!r_ok || !r2_ok) {

            ಆದರೆ (!r_ok) {
                ಆದರೆ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ಇಲ್ಲದಿದ್ದರೆ
                    r = get_reg(rc);
            }

            ಆದರೆ (rc2) {
                ಪೂರ್ಣಾಂಕ ತುಂಬು_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                ಪೂರ್ಣಾಂಕ original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    ತುಂಬು(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = ತುಂಬು_type;
                    ತುಂಬು(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_ಸ್ಥಾನಾಂತರ(PTR_ಗಾತ್ರ);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* move registers */
                    ಆದರೆ (!r_ok)
                        ತುಂಬು(r, vtop);
                    ಆದರೆ (r2_ok && vtop->r2 < VT_CONST)
                        ಹೋಗು ಮುಗಿದ;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                ತುಂಬು(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            ಮುಗಿದ:
                vtop->type.t = original_type;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                ತುಂಬು(r, vtop);
            }
        }
        vtop->r = r;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_C67
        /* uses register pairs for doubles */
        ಆದರೆ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#ಆದರೆ_ಅಂತ್ಯ
    }
    ಹಿಂತಿರುಗಿ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC ಶೂನ್ಯ gv2(ಪೂರ್ಣಾಂಕ rc1, ಪೂರ್ಣಾಂಕ rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ಆದರೆ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ಆದರೆ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ಆದರೆ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ಆದರೆ PTR_ಗಾತ್ರ == 4
/* expand 64bit on stack in two ints */
ST_FUNC ಶೂನ್ಯ lexpand(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ಆದರೆ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ಇಲ್ಲದಿದ್ದರೆ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ PTR_ಗಾತ್ರ == 4
/* build a long long from two ints */
ಸ್ಥಿರ ಶೂನ್ಯ lbuild(ಪೂರ್ಣಾಂಕ t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#ಆದರೆ_ಅಂತ್ಯ

/* convert stack entry to register and duplicate its value in another
ರಿಜಿಸ್ಟರ್*/
ಸ್ಥಿರ ಶೂನ್ಯ gv_dup(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t, rc, r;

    t = vtop->type.t;
#ಆದರೆ PTR_ಗಾತ್ರ == 4
    ಆದರೆ ((t & VT_BTYPE) == VT_LLONG) {
        ಆದರೆ (t & VT_BITFIELD) {
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
        ಹಿಂತಿರುಗಿ;
    }
#ಆದರೆ_ಅಂತ್ಯ
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    ತುಂಬು(r, vtop);
    vtop->r = r;
}

#ಆದರೆ PTR_ಗಾತ್ರ == 4
/* generate CPU independent (unsigned) long long operations */
ಸ್ಥಿರ ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ t, a, b, op1, c, i;
    ಪೂರ್ಣಾಂಕ func;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ reg_iret = REG_IRET;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ reg_lret = REG_IRE2;
    SValue tmp;

    ಆಯ್ಕೆ(op) {
    ಸ್ಥಿತಿ '/':
    ಸ್ಥಿತಿ TOK_PDIV:
        func = TOK___divdi3;
        ಹೋಗು gen_func;
    ಸ್ಥಿತಿ TOK_UDIV:
        func = TOK___udivdi3;
        ಹೋಗು gen_func;
    ಸ್ಥಿತಿ '%':
        func = TOK___moddi3;
        ಹೋಗು gen_mod_func;
    ಸ್ಥಿತಿ TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#ಆದರೆ_ಅಂತ್ಯ
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '^':
    ಸ್ಥಿತಿ '&':
    ಸ್ಥಿತಿ '|':
    ಸ್ಥಿತಿ '*':
    ಸ್ಥಿತಿ '+':
    ಸ್ಥಿತಿ '-':
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
        ಆದರೆ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            ಗಾಗಿ(i=0;i<4;i++)
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
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ಆದರೆ (op == '+')
                op1 = TOK_ADDC1;
            ಇಲ್ಲದಿದ್ದರೆ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ಇಲ್ಲದಿದ್ದರೆ {
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
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SAR:
    ಸ್ಥಿತಿ TOK_SHR:
    ಸ್ಥಿತಿ TOK_SHL:
        ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (ಪೂರ್ಣಾಂಕ)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ಆದರೆ (op != TOK_SHL)
                vswap();
            ಆದರೆ (c >= 32) {
                /* stack: L H */
                vpop();
                ಆದರೆ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ಆದರೆ (op != TOK_SAR) {
                    vpushi(0);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ಇಲ್ಲದಿದ್ದರೆ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ಆದರೆ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ಇಲ್ಲದಿದ್ದರೆ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ಆದರೆ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ಇಲ್ಲದಿದ್ದರೆ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ಆದರೆ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* XXX: should provide a faster fallback on x86 ? */
            ಆಯ್ಕೆ(op) {
            ಸ್ಥಿತಿ TOK_SAR:
                func = TOK___ashrdi3;
                ಹೋಗು gen_func;
            ಸ್ಥಿತಿ TOK_SHR:
                func = TOK___lshrdi3;
                ಹೋಗು gen_func;
            ಸ್ಥಿತಿ TOK_SHL:
                func = TOK___ashldi3;
                ಹೋಗು gen_func;
            }
        }
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
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
        ಆದರೆ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ಆದರೆ (op1 == TOK_LT)
            op1 = TOK_LE;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_GT)
            op1 = TOK_GE;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ಆದರೆ (op == TOK_NE) {
            b = gvtst(0, 0);
        } ಇಲ್ಲದಿದ್ದರೆ {
            a = gvtst(1, 0);
            ಆದರೆ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ಆದರೆ (op1 == TOK_LT)
            op1 = TOK_ULT;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_LE)
            op1 = TOK_ULE;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_GT)
            op1 = TOK_UGT;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ಆದರೆ 0//def TCC_TARGET_I386
        ಆದರೆ (op == TOK_NE) { gsym(b); ನಿಲ್ಲಿಸು; }
        ಆದರೆ (op == TOK_EQ) { gsym(a); ನಿಲ್ಲಿಸು; }
#ಆದರೆ_ಅಂತ್ಯ
        gvtst_ಗಣ(1, a);
        gvtst_ಗಣ(0, b);
        ನಿಲ್ಲಿಸು;
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* normalize values */
ಸ್ಥಿರ uint64_t value64(uint64_t l1, ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_ಗಾತ್ರ == 8 && (t & VT_BTYPE) == VT_PTR))
        ಹಿಂತಿರುಗಿ l1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t & VT_UNSIGNED)
        ಹಿಂತಿರುಗಿ (uint32_t)l1;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ (uint32_t)l1 | -(l1 & 0x80000000);
}

ಸ್ಥಿರ uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ಹಿಂತಿರುಗಿ (a ^ b) >> 63 ? -x : x;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gen_opic_lt(uint64_t a, uint64_t b)
{
    ಹಿಂತಿರುಗಿ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ಸ್ಥಿರ ಶೂನ್ಯ gen_opic(ಪೂರ್ಣಾಂಕ op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    ಪೂರ್ಣಾಂಕ t1 = v1->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಂಕ t2 = v2->type.t & VT_BTYPE;
    ಪೂರ್ಣಾಂಕ c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ಪೂರ್ಣಾಂಕ c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    ಪೂರ್ಣಾಂಕ shm = (t1 == VT_LLONG) ? 63 : 31;
    ಪೂರ್ಣಾಂಕ r;

    ಆದರೆ (c1 && c2) {
        ಆಯ್ಕೆ(op) {
        ಸ್ಥಿತಿ '+': l1 += l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '-': l1 -= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '&': l1 &= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '^': l1 ^= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '|': l1 |= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '*': l1 *= l2; ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TOK_PDIV:
        ಸ್ಥಿತಿ '/':
        ಸ್ಥಿತಿ '%':
        ಸ್ಥಿತಿ TOK_UDIV:
        ಸ್ಥಿತಿ TOK_UMOD:
            /* if division by zero, generate explicit division */
            ಆದರೆ (l2 == 0) {
                ಆದರೆ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                ಹೋಗು general_case;
            }
            ಆಯ್ಕೆ(op) {
            ಪೂರ್ವನಿಯೋಜಿತ: l1 = gen_opic_sdiv(l1, l2); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_UDIV: l1 = l1 / l2; ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_UMOD: l1 = l1 % l2; ನಿಲ್ಲಿಸು;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SHL: l1 <<= (l2 & shm); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SHR: l1 >>= (l2 & shm); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            ನಿಲ್ಲಿಸು;
            /* tests */
        ಸ್ಥಿತಿ TOK_ULT: l1 = l1 < l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGE: l1 = l1 >= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_EQ: l1 = l1 == l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NE: l1 = l1 != l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ULE: l1 = l1 <= l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UGT: l1 = l1 > l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LT: l1 = gen_opic_lt(l1, l2); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GE: l1 = !gen_opic_lt(l1, l2); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LE: l1 = !gen_opic_lt(l2, l1); ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_GT: l1 = gen_opic_lt(l2, l1); ನಿಲ್ಲಿಸು;
            /* logical */
        ಸ್ಥಿತಿ TOK_LAND: l1 = l1 && l2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_LOR: l1 = l1 || l2; ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಹೋಗು general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* if commutative ops, put c2 as constant */
        ಆದರೆ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ಆದರೆ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ಆದರೆ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ಆದರೆ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                ಪೂರ್ಣಾಂಕ n = -1;
                ಆದರೆ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    ಹೋಗು general_case;
                }
                ಆಗ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ಆದರೆ (op == '*')
                    op = TOK_SHL;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_PDIV)
                    op = TOK_SAR;
                ಇಲ್ಲದಿದ್ದರೆ
                    op = TOK_SHR;
            }
            ಹೋಗು general_case;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ಆದರೆ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ಆದರೆ ((ಪೂರ್ಣಾಂಕ)l2 != l2)
	        ಹೋಗು general_case;
            vtop--;
            vtop->c.i = l2;
        } ಇಲ್ಲದಿದ್ದರೆ {
        general_case:
                /* call low level op generator */
                ಆದರೆ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_ಗಾತ್ರ == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ಇಲ್ಲದಿದ್ದರೆ
                    gen_opi(op);
        }
        ಆದರೆ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ಆದರೆ defined TCC_ಗುರಿ_X86_64 || defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_ARM64
# define gen_negf gen_opf
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
ಶೂನ್ಯ gen_negf(ಪೂರ್ಣಾಂಕ op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ಇಲ್ಲದಿದ್ದರೆ
/* XXX: implement in gen_opf() for other backends too */
ಶೂನ್ಯ gen_negf(ಪೂರ್ಣಾಂಕ op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2, bt;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ಆದರೆ defined TCC_ಗುರಿ_X86_64 || defined TCC_ಗುರಿ_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ಆದರೆ (bt == VT_LDOUBLE)
        ಗಾತ್ರ_2 = 10;
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (nocode_wanted) /* save_reg() wont work */
        ಹೋಗು gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(ಗಾತ್ರ_2 - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#ಆದರೆ_ಅಂತ್ಯ

/* generate a floating point operation with constant propagation */
ಸ್ಥಿರ ಶೂನ್ಯ gen_opif(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ c1, c2, i, bt;
    SValue *v1, *v2;
#ಆದರೆ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    ಅಸ್ಥಿರ
#ಆದರೆ_ಅಂತ್ಯ
    ದೀರ್ಘ ದ್ವಿಗುಣ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ಆದರೆ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ಆದರೆ (c1 && c2) {
        ಆದರೆ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ಇಲ್ಲದಿದ್ದರೆ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ಆದರೆ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            ಹೋಗು general_case;
        ಆಯ್ಕೆ(op) {
        ಸ್ಥಿತಿ '+': f1 += f2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '-': f1 -= f2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '*': f1 *= f2; ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '/': 
            ಆದರೆ (f2 == 0.0) {
                ಒಕ್ಕೂಟ { ದಶಮಾಂಶ f; ಚಿಹ್ನೆರಹಿತ u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ಆದರೆ (!CONST_WANTED)
                    ಹೋಗು general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ಆದರೆ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ಇಲ್ಲದಿದ್ದರೆ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                ನಿಲ್ಲಿಸು;
            }
            f1 /= f2;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NEG:
            f1 = -f1;
            ಹೋಗು unary_ಫಲಿತಾಂಶ;
        ಸ್ಥಿತಿ TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ಹಿಂತಿರುಗಿ;
        ಸ್ಥಿತಿ TOK_NE:
            i = f1 != f2;
	    ಹೋಗು make_int;
        ಸ್ಥಿತಿ TOK_LT:
            i = f1 < f2;
	    ಹೋಗು make_int;
        ಸ್ಥಿತಿ TOK_GE:
            i = f1 >= f2;
	    ಹೋಗು make_int;
        ಸ್ಥಿತಿ TOK_LE:
            i = f1 <= f2;
	    ಹೋಗು make_int;
        ಸ್ಥಿತಿ TOK_GT:
            i = f1 > f2;
	    ಹೋಗು make_int;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಹೋಗು general_case;
        }
        vtop--;
    unary_ಫಲಿತಾಂಶ:
        /* XXX: overflow test ? */
        ಆದರೆ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            v1->c.ld = f1;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
    general_case:
        ಆದರೆ (op == TOK_NEG) {
            gen_negf(op);
        } ಇಲ್ಲದಿದ್ದರೆ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ಸ್ಥಿರ ಶೂನ್ಯ type_ಗಮ್ಯ_str(ಅಕ್ಷರ *buf, ಪೂರ್ಣಾಂಕ buf_ಗಾತ್ರ,
                 CType *type, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *varstr)
{
    ಪೂರ್ಣಾಂಕ bt, v, t;
    Sym *s, *sa;
    ಅಕ್ಷರ buf1[256];
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ಆದರೆ (t & VT_EXTERN)
        pstrcat(buf, buf_ಗಾತ್ರ, "extern ");
    ಆದರೆ (t & VT_STATIC)
        pstrcat(buf, buf_ಗಾತ್ರ, "static ");
    ಆದರೆ (t & VT_TYPEDEF)
        pstrcat(buf, buf_ಗಾತ್ರ, "typedef ");
    ಆದರೆ (t & VT_INLINE)
        pstrcat(buf, buf_ಗಾತ್ರ, "inline ");
    ಆದರೆ (bt != VT_PTR) {
        ಆದರೆ (t & VT_RESTRICT)
            pstrcat(buf, buf_ಗಾತ್ರ, "restrict ");
        ಆದರೆ (t & VT_VOLATILE)
            pstrcat(buf, buf_ಗಾತ್ರ, "volatile ");
        ಆದರೆ (t & VT_CONSTANT)
            pstrcat(buf, buf_ಗಾತ್ರ, "const ");
    }
    ಆದರೆ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_ಗಾತ್ರ, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_ಗಾತ್ರ -= ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(buf);
    buf += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(buf);

    ಆಯ್ಕೆ(bt) {
    ಸ್ಥಿತಿ VT_VOID:
        tstr = "void";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_BOOL:
        tstr = "_Bool";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_BYTE:
        tstr = "char";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_SHORT:
        tstr = "short";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_INT:
        tstr = "int";
        ಹೋಗು maybe_long;
    ಸ್ಥಿತಿ VT_LLONG:
        tstr = "long long";
    maybe_long:
        ಆದರೆ (t & VT_LONG)
            tstr = "long";
        ಆದರೆ (!IS_ENUM(t))
            ಹೋಗು ಕೂಡಿಸು_tstr;
        tstr = "enum ";
        ಹೋಗು tstruct;
    ಸ್ಥಿತಿ VT_FLOAT:
        tstr = "float";
        ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_DOUBLE:
        tstr = "double";
        ಆದರೆ (!(t & VT_LONG))
            ಹೋಗು ಕೂಡಿಸು_tstr;
    ಸ್ಥಿತಿ VT_LDOUBLE:
        tstr = "long double";
    ಕೂಡಿಸು_tstr:
        pstrcat(buf, buf_ಗಾತ್ರ, tstr);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_STRUCT:
        tstr = "struct ";
        ಆದರೆ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_ಗಾತ್ರ, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ಆದರೆ (v >= SYM_ಮೊದಲ_ANOM)
            pstrcat(buf, buf_ಗಾತ್ರ, "<anonymous>");
        ಇಲ್ಲದಿದ್ದರೆ
            pstrcat(buf, buf_ಗಾತ್ರ, get_tok_str(v, ಖಾಲಿ));
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ಆದರೆ (varstr && '*' == *varstr) {
            pstrcat(buf1, ಗಾತ್ರ(buf1), "(");
            pstrcat(buf1, ಗಾತ್ರ(buf1), varstr);
            pstrcat(buf1, ಗಾತ್ರ(buf1), ")");
        }
        pstrcat(buf1, ಗಾತ್ರ(buf1), "(");
        sa = s->ಮುಂದಿನ;
        ಆಗ (sa != ಖಾಲಿ) {
            ಅಕ್ಷರ buf2[256];
            type_ಗಮ್ಯ_str(buf2, ಗಾತ್ರ(buf2), &sa->type, ಖಾಲಿ);
            pstrcat(buf1, ಗಾತ್ರ(buf1), buf2);
            sa = sa->ಮುಂದಿನ;
            ಆದರೆ (sa)
                pstrcat(buf1, ಗಾತ್ರ(buf1), ", ");
        }
        ಆದರೆ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, ಗಾತ್ರ(buf1), ", ...");
        pstrcat(buf1, ಗಾತ್ರ(buf1), ")");
        type_ಗಮ್ಯ_str(buf, buf_ಗಾತ್ರ, &s->type, buf1);
        ಹೋಗು no_var;
    ಸ್ಥಿತಿ VT_PTR:
        s = type->ref;
        ಆದರೆ (t & (VT_ARRAY|VT_VLA)) {
            ಆದರೆ (varstr && '*' == *varstr)
                snprintf(buf1, ಗಾತ್ರ(buf1), "(%s)[%d]", varstr, s->c);
            ಇಲ್ಲದಿದ್ದರೆ
                snprintf(buf1, ಗಾತ್ರ(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_ಗಮ್ಯ_str(buf, buf_ಗಾತ್ರ, &s->type, buf1);
            ಹೋಗು no_var;
        }
        pstrcpy(buf1, ಗಾತ್ರ(buf1), "*");
        ಆದರೆ (t & VT_RESTRICT)
            pstrcat(buf1, ಗಾತ್ರ(buf1), "restrict ");
        ಆದರೆ (t & VT_CONSTANT)
            pstrcat(buf1, ಗಾತ್ರ(buf1), "const ");
        ಆದರೆ (t & VT_VOLATILE)
            pstrcat(buf1, ಗಾತ್ರ(buf1), "volatile ");
        ಆದರೆ (varstr)
            pstrcat(buf1, ಗಾತ್ರ(buf1), varstr);
        type_ಗಮ್ಯ_str(buf, buf_ಗಾತ್ರ, &s->type, buf1);
        ಹೋಗು no_var;
    }
    ಆದರೆ (varstr) {
        pstrcat(buf, buf_ಗಾತ್ರ, " ");
        pstrcat(buf, buf_ಗಾತ್ರ, varstr);
    }
 no_var: ;
}

ಸ್ಥಿರ ಶೂನ್ಯ type_incompatibility_error(CType* st, CType* dt, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* fmt)
{
    ಅಕ್ಷರ buf1[256], buf2[256];
    type_ಗಮ್ಯ_str(buf1, ಗಾತ್ರ(buf1), st, ಖಾಲಿ);
    type_ಗಮ್ಯ_str(buf2, ಗಾತ್ರ(buf2), dt, ಖಾಲಿ);
    tcc_error(fmt, buf1, buf2);
}

ಸ್ಥಿರ ಶೂನ್ಯ type_incompatibility_warning(CType* st, CType* dt, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* fmt)
{
    ಅಕ್ಷರ buf1[256], buf2[256];
    type_ಗಮ್ಯ_str(buf1, ಗಾತ್ರ(buf1), st, ಖಾಲಿ);
    type_ಗಮ್ಯ_str(buf2, ಗಾತ್ರ(buf2), dt, ಖಾಲಿ);
    tcc_warning(fmt, buf1, buf2);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pointed_ಗಾತ್ರ(CType *type)
{
    ಪೂರ್ಣಾಂಕ align;
    ಹಿಂತಿರುಗಿ type_ಗಾತ್ರ(pointed_type(type), &align);
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ is_null_ಸೂಚಕ(SValue *p)
{
    ಆದರೆ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ಹಿಂತಿರುಗಿ 0;
    ಹಿಂತಿರುಗಿ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_ಗಾತ್ರ == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ಆದರೆ (s1->f.func_call != s2->f.func_call)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ಹಿಂತಿರುಗಿ 0;
    ಗಾಗಿ (;;) {
        ಆದರೆ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ಹಿಂತಿರುಗಿ 0;
        ಆದರೆ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ಹಿಂತಿರುಗಿ 1;
        s1 = s1->ಮುಂದಿನ;
        s2 = s2->ಮುಂದಿನ;
        ಆದರೆ (!s1)
            ಹಿಂತಿರುಗಿ !s2;
        ಆದರೆ (!s2)
            ಹಿಂತಿರುಗಿ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ compare_types(CType *type1, CType *type2, ಪೂರ್ಣಾಂಕ unqualified)
{
    ಪೂರ್ಣಾಂಕ bt1, t1, t2;

    ಆದರೆ (IS_ENUM(type1->t)) {
        ಆದರೆ (IS_ENUM(type2->t))
            ಹಿಂತಿರುಗಿ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ಆದರೆ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ಆದರೆ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ಆದರೆ (t1 != t2)
        ಹಿಂತಿರುಗಿ 0;

    ಆದರೆ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ಹಿಂತಿರುಗಿ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ಆದರೆ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ಆದರೆ (unqualified && (t1 & VT_ARRAY))
            ಹಿಂತಿರುಗಿ compare_types(type1, type2, 1);
        ಹಿಂತಿರುಗಿ is_compatible_types(type1, type2);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_STRUCT) {
        ಹಿಂತಿರುಗಿ (type1->ref == type2->ref);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_FUNC) {
        ಹಿಂತಿರುಗಿ is_compatible_func(type1, type2);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಹಿಂತಿರುಗಿ 1;
    }
}

#ವ್ಯಾಖ್ಯಾನಿಸು CMP_OP 'C'
#ವ್ಯಾಖ್ಯಾನಿಸು ಸರಿಸು_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ combine_types(CType *dest, SValue *op1, SValue *op2, ಪೂರ್ಣಾಂಕ op)
{
    CType *type1, *type2, type;
    ಪೂರ್ಣಾಂಕ t1, t2, bt1, bt2;
    ಪೂರ್ಣಾಂಕ ret = 1;

    /* for shifts, 'combine' only left operand */
    ಆದರೆ (op == ಸರಿಸು_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ಖಾಲಿ;

    ಆದರೆ (bt1 == VT_VOID || bt2 == VT_VOID) {
        ಆದರೆ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_PTR || bt2 == VT_PTR) {
        ಆದರೆ (op == '+') {
          ಆದರೆ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_null_ಸೂಚಕ (op2)) type = *type1;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_null_ಸೂಚಕ (op1)) type = *type2;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ಆದರೆ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ಇಲ್ಲದಿದ್ದರೆ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            ಪೂರ್ಣಾಂಕ pbt1 = pt1->t & VT_BTYPE;
            ಪೂರ್ಣಾಂಕ pbt2 = pt2->t & VT_BTYPE;
            ಪೂರ್ಣಾಂಕ newquals, copied = 0;
            ಆದರೆ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ಆದರೆ (op != '?' && op != CMP_OP)
                  ret = 0;
                ಇಲ್ಲದಿದ್ದರೆ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ಆದರೆ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ಆದರೆ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ಆದರೆ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ಆದರೆ (!copied)
                      type.ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ಆದರೆ (op == CMP_OP)
          type.t = VT_ಗಾತ್ರ_T;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ಆದರೆ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_float(bt1) || is_float(bt2)) {
        ಆದರೆ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ಇಲ್ಲದಿದ್ದರೆ {
            type.t = VT_FLOAT;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ಆದರೆ (bt1 == VT_LLONG)
          type.t &= t1;
        ಆದರೆ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ಆದರೆ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ಆದರೆ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || ಬಿಟ್_ಗಾತ್ರ(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || ಬಿಟ್_ಗಾತ್ರ(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ಆದರೆ (dest)
      *dest = type;
    ಹಿಂತಿರುಗಿ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC ಶೂನ್ಯ gen_op(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ t1, t2, bt1, bt2, t;
    CType type1, combtype;
    ಪೂರ್ಣಾಂಕ op_class = op;

    ಆದರೆ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = ಸರಿಸು_OP;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ಆದರೆ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ಆದರೆ (bt2 == VT_FUNC) {
	    mk_ಸೂಚಕ(&vtop->type);
	    gaddrof();
	}
	ಆದರೆ (bt1 == VT_FUNC) {
	    vswap();
	    mk_ಸೂಚಕ(&vtop->type);
	    gaddrof();
	    vswap();
	}
	ಹೋಗು redo;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        ಪೂರ್ಣಾಂಕ align;
        ಆದರೆ (op_class == CMP_OP)
            ಹೋಗು std_op;
        /* if both pointers, then it must be the '-' op */
        ಆದರೆ (bt1 == VT_PTR && bt2 == VT_PTR) {
            ಆದರೆ (op != '-')
                ಹೋಗು op_err;
            vpush_type_ಗಾತ್ರ(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* exactly one pointer : must be '+' or '-'. */
            ಆದರೆ (op != '-' && op != '+')
                ಹೋಗು op_err;
            /* Put pointer as first operand */
            ಆದರೆ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ಆದರೆ PTR_ಗಾತ್ರ == 4
            ಆದರೆ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#ಆದರೆ_ಅಂತ್ಯ
            type1 = vtop[-1].type;
            vpush_type_ಗಾತ್ರ(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
            ಆದರೆ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ಆದರೆ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_ಕೂಡಿಸು();
            } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* floats can only be used for a few operations */
        ಆದರೆ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            ಹೋಗು op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ಆದರೆ (op_class == ಸರಿಸು_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ಆದರೆ (t & VT_UNSIGNED) {
            ಆದರೆ (op == TOK_SAR)
                op = TOK_SHR;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == '/')
                op = TOK_UDIV;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == '%')
                op = TOK_UMOD;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_LT)
                op = TOK_ULT;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_GT)
                op = TOK_UGT;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_LE)
                op = TOK_ULE;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ಆದರೆ (is_float(t))
            gen_opif(op);
        ಇಲ್ಲದಿದ್ದರೆ
            gen_opic(op);
        ಆದರೆ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ಇಲ್ಲದಿದ್ದರೆ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ಆದರೆ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ಆದರೆ defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64 || defined TCC_ಗುರಿ_ARM
#ವ್ಯಾಖ್ಯಾನಿಸು gen_cvt_itof1 gen_cvt_itof
#ಇಲ್ಲದಿದ್ದರೆ
/* generic itof for unsigned long long case */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cvt_itof1(ಪೂರ್ಣಾಂಕ t)
{
    ಆದರೆ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ಆದರೆ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#ಆದರೆ_ಅಂತ್ಯ
        ಇಲ್ಲದಿದ್ದರೆ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ಇಲ್ಲದಿದ್ದರೆ {
        gen_cvt_itof(t);
    }
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64
#ವ್ಯಾಖ್ಯಾನಿಸು gen_cvt_ftoi1 gen_cvt_ftoi
#ಇಲ್ಲದಿದ್ದರೆ
/* generic ftoi for unsigned long long case */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cvt_ftoi1(ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ st;
    ಆದರೆ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ಆದರೆ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ಆದರೆ LDOUBLE_ಗಾತ್ರ != 8
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#ಆದರೆ_ಅಂತ್ಯ
        ಇಲ್ಲದಿದ್ದರೆ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ಇಲ್ಲದಿದ್ದರೆ {
        gen_cvt_ftoi(t);
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* special delayed cast for char/short */
ಸ್ಥಿರ ಶೂನ್ಯ force_charshort_cast(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    ಪೂರ್ಣಾಂಕ dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_cast_s(ಪೂರ್ಣಾಂಕ t)
{
    CType type;
    type.t = t;
    type.ref = ಖಾಲಿ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ಸ್ಥಿರ ಶೂನ್ಯ gen_cast(CType *type)
{
    ಪೂರ್ಣಾಂಕ sbt, dbt, sf, df, c;
    ಪೂರ್ಣಾಂಕ dbt_bt, sbt_bt, ds, ss, ಬಿಟ್ಟುಗಳು, trunc;

    /* special delayed cast for char/short */
    ಆದರೆ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ಆದರೆ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ಆದರೆ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ಆದರೆ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ಆದರೆ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ಆದರೆ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            ಹೋಗು ಮುಗಿದ;
        }
        ಆದರೆ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ಆದರೆ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ಆದರೆ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ಆದರೆ (df) {
                ಆದರೆ (sbt_bt == VT_LLONG) {
                    ಆದರೆ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ಇಲ್ಲದಿದ್ದರೆ
                        vtop->c.ld = -(ದೀರ್ಘ ದ್ವಿಗುಣ)-vtop->c.i;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(!sf) {
                    ಆದರೆ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ಇಲ್ಲದಿದ್ದರೆ
                        vtop->c.ld = -(ದೀರ್ಘ ದ್ವಿಗುಣ)-(uint32_t)vtop->c.i;
                }

                ಆದರೆ (dbt == VT_FLOAT)
                    vtop->c.f = (ದಶಮಾಂಶ)vtop->c.ld;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dbt == VT_DOUBLE)
                    vtop->c.d = (ದ್ವಿಗುಣ)vtop->c.ld;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ(sf) {
                    ಆದರೆ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ಇಲ್ಲದಿದ್ದರೆ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sbt_bt == VT_LLONG || (PTR_ಗಾತ್ರ == 8 && sbt == VT_PTR))
                    ;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ಇಲ್ಲದಿದ್ದರೆ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ಆದರೆ (dbt_bt == VT_LLONG || (PTR_ಗಾತ್ರ == 8 && dbt == VT_PTR))
                    ;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ಇಲ್ಲದಿದ್ದರೆ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ಆದರೆ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            ಹೋಗು ಮುಗಿದ;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            ಹೋಗು ಮುಗಿದ;
        }

        /* cannot generate code for global or static initializers */
        ಆದರೆ (nocode_wanted & ದತ್ತಾಂಶ_ONLY_WANTED) {
            ಆದರೆ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            ಹೋಗು ಮುಗಿದ;
        }

        /* non constant case: generate code */
        ಆದರೆ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            ಹೋಗು ಮುಗಿದ;
        }

        ಆದರೆ (sf || df) {
            ಆದರೆ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* convert fp to int */
                sbt = dbt;
                ಆದರೆ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                ಹೋಗು again; /* may need char/short cast */
            }
            ಹೋಗು ಮುಗಿದ;
        }

        ds = btype_ಗಾತ್ರ(dbt_bt);
        ss = btype_ಗಾತ್ರ(sbt_bt);
        ಆದರೆ (ds == 0 || ss == 0)
            ಹೋಗು error;

        /* same size and no sign conversion needed */
        ಆದರೆ (ds == ss && ds >= 4)
            ಹೋಗು ಮುಗಿದ;
        ಆದರೆ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ಆದರೆ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_ಗಾತ್ರ == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #ವ್ಯಾಖ್ಯಾನಿಸು ALLOW_SUBTYPE_ACCESS 1

        ಆದರೆ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ಆದರೆ (ds <= ss)
                ಹೋಗು ಮುಗಿದ;
            /* ss <= 4 here */
            ಆದರೆ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                ಹೋಗು ಮುಗಿದ; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ಆದರೆ PTR_ಗಾತ್ರ == 4
        ಆದರೆ (ds == 8) {
            /* generate high word */
            ಆದರೆ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ಇಲ್ಲದಿದ್ದರೆ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#ಅಥವಾಆದರೆ PTR_ಗಾತ್ರ == 8
        ಆದರೆ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ಆದರೆ (sbt & VT_UNSIGNED) {
#ಆದರೆ defined(TCC_ಗುರಿ_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ಇಲ್ಲದಿದ್ದರೆ
                ಹೋಗು ಮುಗಿದ;
#ಆದರೆ_ಅಂತ್ಯ
            } ಇಲ್ಲದಿದ್ದರೆ {
                gen_cvt_sxtw();
                ಹೋಗು ಮುಗಿದ;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ಆದರೆ !defined(TCC_ಗುರಿ_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ {
            ss = 4;
        }
#ಆದರೆ_ಅಂತ್ಯ

        ಆದರೆ (ds >= ss)
            ಹೋಗು ಮುಗಿದ;
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64 || defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64
    ಆದರೆ (ss == 4) {
        gen_cvt_csti(dbt);
        ಹೋಗು ಮುಗಿದ;
    }
#ಆದರೆ_ಅಂತ್ಯ
        ಬಿಟ್ಟುಗಳು = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(ಬಿಟ್ಟುಗಳು);
        gen_op(TOK_SHL);
        vpushi(ಬಿಟ್ಟುಗಳು - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
ಮುಗಿದ:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC ಪೂರ್ಣಾಂಕ type_ಗಾತ್ರ(CType *type, ಪೂರ್ಣಾಂಕ *a)
{
    Sym *s;
    ಪೂರ್ಣಾಂಕ bt;

    bt = type->t & VT_BTYPE;
    ಆದರೆ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ಹಿಂತಿರುಗಿ s->c;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_PTR) {
        ಆದರೆ (type->t & VT_ARRAY) {
            ಪೂರ್ಣಾಂಕ ts;
            s = type->ref;
            ts = type_ಗಾತ್ರ(&s->type, a);
            ಆದರೆ (s->c < 0)
                ಹಿಂತಿರುಗಿ s->c;
            ಹಿಂತಿರುಗಿ ts * s->c;
        } ಇಲ್ಲದಿದ್ದರೆ {
            *a = PTR_ಗಾತ್ರ;
            ಹಿಂತಿರುಗಿ PTR_ಗಾತ್ರ;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ಹಿಂತಿರುಗಿ -1; /* incomplete enum */
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ಹಿಂತಿರುಗಿ LDOUBLE_ಗಾತ್ರ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_DOUBLE || bt == VT_LLONG) {
#ಆದರೆ (defined TCC_ಗುರಿ_I386 && !defined TCC_ಗುರಿ_PE) \
 || (defined TCC_ಗುರಿ_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ಇಲ್ಲದಿದ್ದರೆ
        *a = 8;
#ಆದರೆ_ಅಂತ್ಯ
        ಹಿಂತಿರುಗಿ 8;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ಹಿಂತಿರುಗಿ 4;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_SHORT) {
        *a = 2;
        ಹಿಂತಿರುಗಿ 2;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ಹಿಂತಿರುಗಿ 16;
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* char, void, function, _Bool */
        *a = 1;
        ಹಿಂತಿರುಗಿ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ಸ್ಥಿರ ಶೂನ್ಯ vpush_type_ಗಾತ್ರ(CType *type, ಪೂರ್ಣಾಂಕ *a)
{
    ಆದರೆ (type->t & VT_VLA) {
        type_ಗಾತ್ರ(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, a);
        ಆದರೆ (ಗಾತ್ರ_2 < 0)
            tcc_error("unknown type size");
        vpushs(ಗಾತ್ರ_2);
    }
}

/* return the pointed type of t */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ CType *pointed_type(CType *type)
{
    ಹಿಂತಿರುಗಿ &type->ref->type;
}

ಸ್ಥಿರ ಶೂನ್ಯ check_restrict_type(CType *type)
{
    ಆಗ ((type->t & VT_BTYPE) == VT_PTR) {
        ಆದರೆ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ಆದರೆ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ type_qualifiers(CType *type)
{
    ಆಗ (type->t & VT_ARRAY)
        type = pointed_type(type);
    ಹಿಂತಿರುಗಿ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC ಶೂನ್ಯ mk_ಸೂಚಕ(CType *type)
{
    Sym *s;
    s = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_compatible_types(CType *type1, CType *type2)
{
    ಹಿಂತಿರುಗಿ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ಹಿಂತಿರುಗಿ compare_types(type1,type2,1);
}

ಸ್ಥಿರ ಶೂನ್ಯ cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ಸ್ಥಿರ ಶೂನ್ಯ verify_ನಿಯೋಜಿಸು_cast(CType *dt)
{
    CType *st, *type1, *type2;
    ಪೂರ್ಣಾಂಕ dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ಆದರೆ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    ಆಯ್ಕೆ(dbt) {
    ಸ್ಥಿತಿ VT_VOID:
        ಆದರೆ (sbt != dbt)
            tcc_error("assignment to void expression");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ಆದರೆ (is_null_ಸೂಚಕ(vtop))
            ನಿಲ್ಲಿಸು;
        /* accept implicit pointer to integer cast with warning */
        ಆದರೆ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            ನಿಲ್ಲಿಸು;
        }
        type1 = pointed_type(dt);
        ಆದರೆ (sbt == VT_PTR)
            type2 = pointed_type(st);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ಇಲ್ಲದಿದ್ದರೆ
            ಹೋಗು error;
        ಆದರೆ (is_compatible_types(type1, type2))
            ನಿಲ್ಲಿಸು;
        ಗಾಗಿ (qualwarn = lvl = 0;; ++lvl) {
            ಆದರೆ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ಆದರೆ (dbt != VT_PTR || sbt != VT_PTR)
                ನಿಲ್ಲಿಸು;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ಆದರೆ (!is_compatible_unqualified_types(type1, type2)) {
            ಆದರೆ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ಇಲ್ಲದಿದ್ದರೆ {
                tcc_warning("assignment from incompatible pointer type");
                ನಿಲ್ಲಿಸು;
            }
        }
        ಆದರೆ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_BYTE:
    ಸ್ಥಿತಿ VT_SHORT:
    ಸ್ಥಿತಿ VT_INT:
    ಸ್ಥಿತಿ VT_LLONG:
        ಆದರೆ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (sbt == VT_STRUCT) {
            ಹೋಗು case_VT_STRUCT;
        }
        /* XXX: more tests */
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ VT_STRUCT:
    case_VT_STRUCT:
        ಆದರೆ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        ನಿಲ್ಲಿಸು;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_ನಿಯೋಜಿಸು_cast(CType *dt)
{
    verify_ನಿಯೋಜಿಸು_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC ಶೂನ್ಯ vstore(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ sbt, dbt, ft, r, ಗಾತ್ರ_2, align, ಬಿಟ್_ಗಾತ್ರ_2, ಬಿಟ್_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_ನಿಯೋಜಿಸು_cast(&vtop[-1].type);

    ಆದರೆ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#ಆದರೆ_ಅಂತ್ಯ
        vtop->type.t = VT_PTR;
        gaddrof();
        /*ಮೂಲ*/
        vswap();
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (vtop->r & VT_MUSTBOUND)
            gbound();
#ಆದರೆ_ಅಂತ್ಯ
        vtop->type.t = VT_PTR;
        gaddrof();

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_NATIVE_STRUCT_COPY
        ಆದರೆ (1
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#ಆದರೆ_ಅಂತ್ಯ
            ) {
            gen_struct_copy(ಗಾತ್ರ_2);
        } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
        {
            /* type size */
            vpushi(ಗಾತ್ರ_2);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_EABI
            ಆದರೆ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        ಬಿಟ್_pos = ಬಿಟ್_POS(ft);
        ಬಿಟ್_ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_ಮುಖವಾಡ;

        ಆದರೆ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2);
        ಆದರೆ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ಆದರೆ (r == VT_STRUCT) {
            store_packed_bf(ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮುಖವಾಡ = (1ULL << ಬಿಟ್_ಗಾತ್ರ_2) - 1;
            ಆದರೆ (dbt != VT_BOOL) {
                /* mask source */
                ಆದರೆ (dbt == VT_LLONG)
                    vpushll(ಮುಖವಾಡ);
                ಇಲ್ಲದಿದ್ದರೆ
                    vpushi((ಚಿಹ್ನೆರಹಿತ)ಮುಖವಾಡ);
                gen_op('&');
            }
            /* shift source */
            vpushi(ಬಿಟ್_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            ಆದರೆ (dbt == VT_LLONG)
                vpushll(~(ಮುಖವಾಡ << ಬಿಟ್_pos));
            ಇಲ್ಲದಿದ್ದರೆ
                vpushi(~((ಚಿಹ್ನೆರಹಿತ)ಮುಖವಾಡ << ಬಿಟ್_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (dbt == VT_VOID) {
        --vtop;
    } ಇಲ್ಲದಿದ್ದರೆ {
            /* optimize char/short casts */
            delayed_cast = 0;
            ಆದರೆ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ಆದರೆ ((vtop->r & VT_MUSTCAST)
                    && btype_ಗಾತ್ರ(dbt) > btype_ಗಾತ್ರ(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ಇಲ್ಲದಿದ್ದರೆ {
                gen_cast(&vtop[-1].type);
            }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
            /* bound check case */
            ಆದರೆ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#ಆದರೆ_ಅಂತ್ಯ
            gv(RC_TYPE(dbt)); /* generate value */

            ಆದರೆ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ಆದರೆ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ಖಾಲಿ;
                ತುಂಬು(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ಆದರೆ (USING_TWO_ಪದಗಳು(dbt)) {
                ಪೂರ್ಣಾಂಕ ತುಂಬು_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = ತುಂಬು_type;
                store(r, vtop - 1);
                vswap();
                incr_ಸ್ಥಾನಾಂತರ(PTR_ಗಾತ್ರ);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC ಶೂನ್ಯ inc(ಪೂರ್ಣಾಂಕ post, ಪೂರ್ಣಾಂಕ c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ಆದರೆ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ಆದರೆ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
    /* read the string */
    ಆದರೆ (tok != TOK_STR)
        expect(ಸಂದೇಶ);
    cstr_reset(&initstr);
    ಆಗ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.ದತ್ತಾಂಶ, -1);
        ಮುಂದಿನ();
    }
    cstr_ccat(&initstr, '\0');
    ಹಿಂತಿರುಗಿ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC ಪೂರ್ಣಾಂಕ exact_log2p1(ಪೂರ್ಣಾಂಕ i)
{
  ಪೂರ್ಣಾಂಕ ret;
  ಆದರೆ (!i)
    ಹಿಂತಿರುಗಿ 0;
  ಗಾಗಿ (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ಆದರೆ (i >= 1 << 4)
    ret += 4, i >>= 4;
  ಆದರೆ (i >= 1 << 2)
    ret += 2, i >>= 2;
  ಆದರೆ (i >= 1 << 1)
    ret++;
  ಹಿಂತಿರುಗಿ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_attribute(AttributeDef *ad)
{
    ಪೂರ್ಣಾಂಕ t, n;
    ಅಕ್ಷರ *astr;
    AttributeDef ad_tmp;
    
redo:
    ಆದರೆ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (ಖಾಲಿ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    ಮುಂದಿನ();
    skip('(');
    skip('(');
    ಆಗ (tok != ')') {
        ಆದರೆ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        ಮುಂದಿನ();
        ಆಯ್ಕೆ(t) {
	ಸ್ಥಿತಿ TOK_CLEANUP1:
	ಸ್ಥಿತಿ TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_ಕಂಡುಹಿಡಿ(tok);
	    ಆದರೆ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    ಮುಂದಿನ();
            skip(')');
	    ನಿಲ್ಲಿಸು;
	}
        ಸ್ಥಿತಿ TOK_CONSTRUCTOR1:
        ಸ್ಥಿತಿ TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_DESTRUCTOR1:
        ಸ್ಥಿತಿ TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ALWAYS_INLINE1:
        ಸ್ಥಿತಿ TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SECTION1:
        ಸ್ಥಿತಿ TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->ದತ್ತಾಂಶ;
            n = tcc_state->nb_sections;
            ad->section = ಕಂಡುಹಿಡಿ_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ALIAS1:
        ಸ್ಥಿತಿ TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->ದತ್ತಾಂಶ;
            /* save string as token, for later */
            ad->alias_ಗುರಿ = tok_alloc_const(astr);
            skip(')');
            ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_VISIBILITY1:
	ಸ್ಥಿತಿ TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->ದತ್ತಾಂಶ;
	    ಆದರೆ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_ಆಂತರಿಕ;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ಇಲ್ಲದಿದ್ದರೆ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ALIGNED1:
        ಸ್ಥಿತಿ TOK_ALIGNED2:
            ಆದರೆ (tok == '(') {
                ಮುಂದಿನ();
                n = ಅಭಿವ್ಯಕ್ತಿ_const();
                ಆದರೆ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ಇಲ್ಲದಿದ್ದರೆ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ಆದರೆ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_PACKED1:
        ಸ್ಥಿತಿ TOK_PACKED2:
            ad->a.packed = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_WEAK1:
        ಸ್ಥಿತಿ TOK_WEAK2:
            ad->a.weak = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NODEBUG1:
        ಸ್ಥಿತಿ TOK_NODEBUG2:
            ad->a.nodebug = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_USED1:
        ಸ್ಥಿತಿ TOK_USED2:
        ಸ್ಥಿತಿ TOK_UNUSED1:
        ಸ್ಥಿತಿ TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_CONST1:
        ಸ್ಥಿತಿ TOK_CONST2:
        ಸ್ಥಿತಿ TOK_CONST3:
        ಸ್ಥಿತಿ TOK_PURE1:
        ಸ್ಥಿತಿ TOK_PURE2:
	    /* ignored */
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NOINLINE:
	    /* ignored */
	    ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_FORMAT1:
        ಸ್ಥಿತಿ TOK_FORMAT2:
	    /* ignored */
            ಹೋಗು skip_param;
        ಸ್ಥಿತಿ TOK_NORETURN1:
        ಸ್ಥಿತಿ TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_CDECL1:
        ಸ್ಥಿತಿ TOK_CDECL2:
        ಸ್ಥಿತಿ TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_STDCALL1:
        ಸ್ಥಿತಿ TOK_STDCALL2:
        ಸ್ಥಿತಿ TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
        ಸ್ಥಿತಿ TOK_REGPARM1:
        ಸ್ಥಿತಿ TOK_REGPARM2:
            skip('(');
            n = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಆದರೆ (n > 3) 
                n = 3;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (n < 0)
                n = 0;
            ಆದರೆ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_FASTCALL1:
        ಸ್ಥಿತಿ TOK_FASTCALL2:
        ಸ್ಥಿತಿ TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_THISCALL1:
        ಸ್ಥಿತಿ TOK_THISCALL2:
        ಸ್ಥಿತಿ TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ TOK_ಬಹುಲಕ:
            skip('(');
            ಆಯ್ಕೆ(tok) {
                ಸ್ಥಿತಿ TOK_ಬಹುಲಕ_DI:
                    ad->attr_ಬಹುಲಕ = VT_LLONG + 1;
                    ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ TOK_ಬಹುಲಕ_QI:
                    ad->attr_ಬಹುಲಕ = VT_BYTE + 1;
                    ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ TOK_ಬಹುಲಕ_HI:
                    ad->attr_ಬಹುಲಕ = VT_SHORT + 1;
                    ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ TOK_ಬಹುಲಕ_SI:
                ಸ್ಥಿತಿ TOK_ಬಹುಲಕ_ಶಬ್ದ:
                    ad->attr_ಬಹುಲಕ = VT_INT + 1;
                    ನಿಲ್ಲಿಸು;
                ಪೂರ್ವನಿಯೋಜಿತ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ಖಾಲಿ));
                    ನಿಲ್ಲಿಸು;
            }
            ಮುಂದಿನ();
            skip(')');
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NODECORATE:
            ad->a.nodecorate = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ಖಾಲಿ));
            /* skip parameters */
skip_param:
            ಆದರೆ (tok == '(') {
                ಪೂರ್ಣಾಂಕ parenthesis = 0;
                ಮಾಡು {
                    ಆದರೆ (tok == '(') 
                        parenthesis++;
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == ')') 
                        parenthesis--;
                    ಮುಂದಿನ();
                } ಆಗ (parenthesis && tok != -1);
            }
            ನಿಲ್ಲಿಸು;
        }
        ಆದರೆ (tok != ',')
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
    }
    skip(')');
    skip(')');
    ಹೋಗು redo;
}

ಸ್ಥಿರ Sym * ಕಂಡುಹಿಡಿ_ಕ್ಷೇತ್ರ (CType *type, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ *cumofs)
{
    Sym *s = type->ref;
    ಪೂರ್ಣಾಂಕ v1 = v | SYM_ಕ್ಷೇತ್ರ;
    ಆದರೆ (!(v & SYM_ಕ್ಷೇತ್ರ)) { /* top-level call */
        ಆದರೆ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ಆದರೆ (v < TOK_UIDENT)
            expect("field name");
        ಆದರೆ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ಆಗ ((s = s->ಮುಂದಿನ) != ಖಾಲಿ) {
        ಆದರೆ (s->v == v1) {
            *cumofs = s->c;
            ಹಿಂತಿರುಗಿ s;
        }
        ಆದರೆ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_ಮೊದಲ_ANOM | SYM_ಕ್ಷೇತ್ರ)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = ಕಂಡುಹಿಡಿ_ಕ್ಷೇತ್ರ (&s->type, v1, cumofs);
            ಆದರೆ (ret) {
                *cumofs += s->c;
                ಹಿಂತಿರುಗಿ ret;
            }
        }
    }
    ಆದರೆ (!(v & SYM_ಕ್ಷೇತ್ರ))
        tcc_error("field not found: %s", get_tok_str(v, ಖಾಲಿ));
    ಹಿಂತಿರುಗಿ s;
}

ಸ್ಥಿರ ಶೂನ್ಯ check_fields (CType *type, ಪೂರ್ಣಾಂಕ check)
{
    Sym *s = type->ref;

    ಆಗ ((s = s->ಮುಂದಿನ) != ಖಾಲಿ) {
        ಪೂರ್ಣಾಂಕ v = s->v & ~SYM_ಕ್ಷೇತ್ರ;
        ಆದರೆ (v < SYM_ಮೊದಲ_ANOM) {
            TokenSym *ts = ಕೋಷ್ಟಕ_ident[v - TOK_IDENT];
            ಆದರೆ (check && (ts->tok & SYM_ಕ್ಷೇತ್ರ))
                tcc_error("duplicate member '%s'", get_tok_str(v, ಖಾಲಿ));
            ts->tok ^= SYM_ಕ್ಷೇತ್ರ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ struct_layout(CType *type, AttributeDef *ad)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, maxalign, ಸ್ಥಾನಾಂತರ, c, ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2;
    ಪೂರ್ಣಾಂಕ packed, a, bt, prevbt, prev_ಬಿಟ್_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ pcc = !tcc_state->ms_bitfields;
    ಪೂರ್ಣಾಂಕ pragma_pack = *tcc_state->pack_ರಾಶಿ_ptr;
    Sym *f;

    maxalign = 1;
    ಸ್ಥಾನಾಂತರ = 0;
    c = 0;
    ಬಿಟ್_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_ಬಿಟ್_ಗಾತ್ರ = 0;

//#define BF_DEBUG

    ಗಾಗಿ (f = type->ref->ಮುಂದಿನ; f; f = f->ಮುಂದಿನ) {
        ಆದರೆ (f->type.t & VT_BITFIELD)
            ಬಿಟ್_ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(f->type.t);
        ಇಲ್ಲದಿದ್ದರೆ
            ಬಿಟ್_ಗಾತ್ರ_2 = -1;
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ಆದರೆ (pcc && ಬಿಟ್_ಗಾತ್ರ_2 == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ಇಲ್ಲದಿದ್ದರೆ {
            /* in pcc mode, attribute packed overrides if set. */
            ಆದರೆ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ಆದರೆ (pragma_pack) {
                packed = 1;
                ಆದರೆ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ಆದರೆ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ಆದರೆ (a)
            align = a;

        ಆದರೆ (type->ref->type.t == VT_UNION) {
	    ಆದರೆ (pcc && ಬಿಟ್_ಗಾತ್ರ_2 >= 0)
	        ಗಾತ್ರ_2 = (ಬಿಟ್_ಗಾತ್ರ_2 + 7) >> 3;
	    ಸ್ಥಾನಾಂತರ = 0;
	    ಆದರೆ (ಗಾತ್ರ_2 > c)
	        c = ಗಾತ್ರ_2;

	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 < 0) {
            ಆದರೆ (pcc)
                c += (ಬಿಟ್_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    ಸ್ಥಾನಾಂತರ = c;
	    ಆದರೆ (ಗಾತ್ರ_2 > 0)
	        c += ಗಾತ್ರ_2;
	    ಬಿಟ್_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_ಬಿಟ್_ಗಾತ್ರ = 0;

	} ಇಲ್ಲದಿದ್ದರೆ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ಆದರೆ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 == 0) {
            new_ಕ್ಷೇತ್ರ:
		    c = (c + ((ಬಿಟ್_pos + 7) >> 3) + align - 1) & -align;
		    ಬಿಟ್_pos = 0;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (f->a.aligned) {
                    ಹೋಗು new_ಕ್ಷೇತ್ರ;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!packed) {
                    ಪೂರ್ಣಾಂಕ a8 = align * 8;
	            ಪೂರ್ಣಾಂಕ ofs = ((c * 8 + ಬಿಟ್_pos) % a8 + ಬಿಟ್_ಗಾತ್ರ_2 + a8 - 1) / a8;
                    ಆದರೆ (ofs > ಗಾತ್ರ_2 / align)
                        ಹೋಗು new_ಕ್ಷೇತ್ರ;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ಆದರೆ (ಗಾತ್ರ_2 == 8 && ಬಿಟ್_ಗಾತ್ರ_2 <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, ಗಾತ್ರ_2 = 4;

                ಆಗ (ಬಿಟ್_pos >= align * 8)
                    c += align, ಬಿಟ್_pos -= align * 8;
                ಸ್ಥಾನಾಂತರ = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ಆದರೆ (f->v & SYM_ಮೊದಲ_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ಇಲ್ಲದಿದ್ದರೆ {
		bt = f->type.t & VT_BTYPE;
		ಆದರೆ ((ಬಿಟ್_pos + ಬಿಟ್_ಗಾತ್ರ_2 > ಗಾತ್ರ_2 * 8)
                    || (ಬಿಟ್_ಗಾತ್ರ_2 > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    ಸ್ಥಾನಾಂತರ = c;
		    ಬಿಟ್_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 || prev_ಬಿಟ್_ಗಾತ್ರ)
		        c += ಗಾತ್ರ_2;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_ಬಿಟ್_ಗಾತ್ರ = ಬಿಟ್_ಗಾತ್ರ_2;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ಸರಿಸು))
		        | (ಬಿಟ್_pos << VT_STRUCT_ಸರಿಸು);
	    ಬಿಟ್_pos += ಬಿಟ್_ಗಾತ್ರ_2;
	}
	ಆದರೆ (align > maxalign)
	    maxalign = align;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BF_DEBUG
	ಬರೆ("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_ಕ್ಷೇತ್ರ, ಖಾಲಿ), ಸ್ಥಾನಾಂತರ, ಗಾತ್ರ_2, align);
	ಆದರೆ (f->type.t & VT_BITFIELD) {
	    ಬರೆ(" pos %-2d bits %-2d",
                    ಬಿಟ್_POS(f->type.t),
                    ಬಿಟ್_ಗಾತ್ರ(f->type.t)
                    );
	}
	ಬರೆ("\n");
#ಆದರೆ_ಅಂತ್ಯ

        f->c = ಸ್ಥಾನಾಂತರ;
	f->r = 0;
    }

    ಆದರೆ (pcc)
        c += (ಬಿಟ್_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ಆದರೆ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ಆದರೆ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ಆದರೆ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BF_DEBUG
    ಬರೆ("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#ಆದರೆ_ಅಂತ್ಯ

    /* check whether we can access bitfields by their type */
    ಗಾಗಿ (f = type->ref->ಮುಂದಿನ; f; f = f->ಮುಂದಿನ) {
        ಪೂರ್ಣಾಂಕ s, px, cx, c0;
        CType t;

        ಆದರೆ (0 == (f->type.t & VT_BITFIELD))
            ಮುಂದುವರಿ;
        f->type.ref = f;
        f->auxtype = -1;
        ಬಿಟ್_ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(f->type.t);
        ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 == 0)
            ಮುಂದುವರಿ;
        ಬಿಟ್_pos = ಬಿಟ್_POS(f->type.t);
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&f->type, &align);

        ಆದರೆ (ಬಿಟ್_pos + ಬಿಟ್_ಗಾತ್ರ_2 <= ಗಾತ್ರ_2 * 8 && f->c + ಗಾತ್ರ_2 <= c
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
            && !(f->c & (align - 1))
#ಆದರೆ_ಅಂತ್ಯ
            )
            ಮುಂದುವರಿ;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        ಗಾಗಿ (;;) {
            px = f->c * 8 + ಬಿಟ್_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ಆದರೆ (c0 == cx)
                ನಿಲ್ಲಿಸು;
            s = (px + ಬಿಟ್_ಗಾತ್ರ_2 + 7) >> 3;
            ಆದರೆ (s > 4) {
                t.t = VT_LLONG;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s > 2) {
                t.t = VT_INT;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s > 1) {
                t.t = VT_SHORT;
            } ಇಲ್ಲದಿದ್ದರೆ {
                t.t = VT_BYTE;
            }
            s = type_ಗಾತ್ರ(&t, &align);
            c0 = cx;
        }

        ಆದರೆ (px + ಬಿಟ್_ಗಾತ್ರ_2 <= s * 8 && cx + s <= c
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
            && !(cx & (align - 1))
#ಆದರೆ_ಅಂತ್ಯ
            ) {
            /* update offset and bit position */
            f->c = cx;
            ಬಿಟ್_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ಸರಿಸು))
		        | (ಬಿಟ್_pos << VT_STRUCT_ಸರಿಸು);
            ಆದರೆ (s != ಗಾತ್ರ_2)
                f->auxtype = t.t;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BF_DEBUG
            ಬರೆ("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_ಕ್ಷೇತ್ರ, ಖಾಲಿ),
                cx, s, align, px, ಬಿಟ್_ಗಾತ್ರ_2);
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BF_DEBUG
            ಬರೆ("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_ಕ್ಷೇತ್ರ, ಖಾಲಿ));
#ಆದರೆ_ಅಂತ್ಯ
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಒಳ_range(ದೀರ್ಘ ದೀರ್ಘ n, ಪೂರ್ಣಾಂಕ t)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ m = (1ULL << (btype_ಗಾತ್ರ(t & VT_BTYPE) * 8 - 1)) - 1;
    ಆದರೆ (t & VT_UNSIGNED)
        ಹಿಂತಿರುಗಿ n <= (m << 1) + 1;
    ಹಿಂತಿರುಗಿ n >= -(ದೀರ್ಘ ದೀರ್ಘ)m - 1 && n <= (ದೀರ್ಘ ದೀರ್ಘ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ಸ್ಥಿರ ಶೂನ್ಯ struct_decl(CType *type, ಪೂರ್ಣಾಂಕ u)
{
    ಪೂರ್ಣಾಂಕ v, c, ಗಾತ್ರ_2, align, flexible;
    ಪೂರ್ಣಾಂಕ ಬಿಟ್_ಗಾತ್ರ_2, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, ಗಾತ್ರ ad);
    ಮುಂದಿನ();
    parse_attribute(&ad);

    v = 0;
    ಆದರೆ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, ಮುಂದಿನ();

    bt = ut = 0;
    ಆದರೆ (u == VT_ENUM) {
        ut = VT_INT;
        ಆದರೆ (tok == ':') { /* C2x enum : <type> ... */
            ಮುಂದಿನ();
            ಆದರೆ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ಆದರೆ (v) {
        /* struct already defined ? return it */
        s = struct_ಕಂಡುಹಿಡಿ(v);
        ಆದರೆ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ಆದರೆ (u == s->type.t)
                ಹೋಗು do_decl;
            ಆದರೆ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                ಹೋಗು do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ಖಾಲಿ));
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ಖಾಲಿ;
    /* we put an undefined size for struct/union */
    s = sym_ತಳ್ಳು(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ಆದರೆ (tok == '{') {
        ಮುಂದಿನ();
        ಆದರೆ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->ಮುಂದಿನ;
        ಆದರೆ (u == VT_ENUM) {
            ದೀರ್ಘ ದೀರ್ಘ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ಆದರೆ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            ಗಾಗಿ(;;) {
                v = tok;
                ಆದರೆ (v < TOK_UIDENT)
                    expect("identifier");
                ಮುಂದಿನ();
                ಆದರೆ (tok == '=') {
                    ಮುಂದಿನ();
		    ll = ಅಭಿವ್ಯಕ್ತಿ_const64();
                }
                ಆದರೆ (bt && !ಒಳ_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ಖಾಲಿ));
                ss = sym_ತಳ್ಳು(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->ಮುಂದಿನ;
                ಆದರೆ (ll < nl)
                    nl = ll;
                ಆದರೆ (ll > pl)
                    pl = ll;
                ಆದರೆ (tok != ',')
                    ನಿಲ್ಲಿಸು;
                ಮುಂದಿನ();
                ll++;
                /* NOTE: we accept a trailing comma */
                ಆದರೆ (tok == '}')
                    ನಿಲ್ಲಿಸು;
            }
            skip('}');

            ಆದರೆ (bt) {
                t.t = bt;
                s->c = 2;
                ಹೋಗು enum_ಮುಗಿದ;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ಆದರೆ (nl >= 0) {
                ಆದರೆ (pl != (ಚಿಹ್ನೆರಹಿತ)pl)
                    t.t = (LONG_ಗಾತ್ರ==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pl != (ಪೂರ್ಣಾಂಕ)pl || nl != (ಪೂರ್ಣಾಂಕ)nl)
                t.t = (LONG_ಗಾತ್ರ==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            ಗಾಗಿ (ss = s->ಮುಂದಿನ; ss; ss = ss->ಮುಂದಿನ) {
                ll = ss->enum_val;
                ಆದರೆ (ll == (ಪೂರ್ಣಾಂಕ)ll) /* default is int if it fits */
                    ಮುಂದುವರಿ;
                ಆದರೆ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ಆದರೆ (ll == (ಚಿಹ್ನೆರಹಿತ)ll)
                        ಮುಂದುವರಿ;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_ಗಾತ್ರ==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_ಮುಗಿದ:
            s->type.t = type->t = t.t | VT_ENUM;

        } ಇಲ್ಲದಿದ್ದರೆ {
            c = 0;
            flexible = 0;
            ಆಗ (tok != '}') {
                ಆದರೆ (!parse_btype(&btype, &ad1, 0)) {
                    ಆದರೆ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ಮುಂದುವರಿ;
                    }
		    skip(';');
		    ಮುಂದುವರಿ;
		}
                ಆಗ (1) {
		    ಆದರೆ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ಖಾಲಿ));
                    ಬಿಟ್_ಗಾತ್ರ_2 = -1;
                    v = 0;
                    type1 = btype;
                    ಆದರೆ (tok != ':') {
			ಆದರೆ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_ನೇರ);
                        ಆದರೆ (v == 0) {
                    	    ಆದರೆ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ಇಲ್ಲದಿದ್ದರೆ {
				ಪೂರ್ಣಾಂಕ v = btype.ref->v;
				ಆದರೆ ((v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM) {
				    ಆದರೆ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ಆದರೆ (type_ಗಾತ್ರ(&type1, &align) < 0) {
			    ಆದರೆ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ಇಲ್ಲದಿದ್ದರೆ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ಖಾಲಿ));
                        }
                        ಆದರೆ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ಖಾಲಿ));
                    }
                    ಆದರೆ (tok == ':') {
                        ಮುಂದಿನ();
                        ಬಿಟ್_ಗಾತ್ರ_2 = ಅಭಿವ್ಯಕ್ತಿ_const();
                        /* XXX: handle v = 0 case for messages */
                        ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ಖಾಲಿ));
                        ಆದರೆ (v && ಬಿಟ್_ಗಾತ್ರ_2 == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ಖಾಲಿ));
			parse_attribute(&ad1);
                    }
                    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&type1, &align);
                    ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ಆದರೆ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = ಗಾತ್ರ_2 * 8;
                        ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ಖಾಲಿ));
                        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 == bsize
				    && !*tcc_state->pack_ರಾಶಿ_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಬಿಟ್_ಗಾತ್ರ_2 == 64) {
                            tcc_error("field width 64 not implemented");
                        } ಇಲ್ಲದಿದ್ದರೆ {
                            type1.t = (type1.t & ~VT_STRUCT_ಮುಖವಾಡ)
                                | VT_BITFIELD
                                | ((ಚಿಹ್ನೆರಹಿತ)ಬಿಟ್_ಗಾತ್ರ_2 << (VT_STRUCT_ಸರಿಸು + 6));
                        }
                    }
                    ಆದರೆ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ಆದರೆ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 ಬಿಟ್_ಗಾತ್ರ_2 >= 0)) {
		        v = anon_sym++;
		    }
                    ಆದರೆ (v) {
                        ss = sym_ತಳ್ಳು(v | SYM_ಕ್ಷೇತ್ರ, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->ಮುಂದಿನ;
                    }
                    ಆದರೆ (tok == ';' || tok == TOK_EOF)
                        ನಿಲ್ಲಿಸು;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ಆದರೆ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ಆದರೆ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ sym_ಗಮ್ಯ_attr(AttributeDef *ad, Sym *s)
{
    ವಿಲೀನ_symattr(&ad->a, &s->a);
    ವಿಲೀನ_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_btype_qualify(CType *type, ಪೂರ್ಣಾಂಕ qualifiers)
{
    ಆಗ (type->t & VT_ARRAY) {
        type->ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ಆದರೆ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_btype(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ ignore_label)
{
    ಪೂರ್ಣಾಂಕ t, u, bt, st, type_ಸಿಕ್ಕಿತು, typespec_ಸಿಕ್ಕಿತು, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, ಗಾತ್ರ(AttributeDef));
    type_ಸಿಕ್ಕಿತು = 0;
    typespec_ಸಿಕ್ಕಿತು = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ಖಾಲಿ;

    ಆಗ(1) {
        ಆಯ್ಕೆ(tok) {
        ಸ್ಥಿತಿ TOK_EXTENSION:
            /* currently, we really ignore extension */
            ಮುಂದಿನ();
            ಮುಂದುವರಿ;

            /* basic types */
        ಸ್ಥಿತಿ TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            ಮುಂದಿನ();
        basic_type1:
            ಆದರೆ (u == VT_SHORT || u == VT_LONG) {
                ಆದರೆ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (bt != -1 || (st != -1 && u != VT_INT))
                    ಹೋಗು tmbt;
                ಆದರೆ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    ಹೋಗು tmbt;
                bt = u;
            }
            ಆದರೆ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_ಸಿಕ್ಕಿತು = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_VOID:
            u = VT_VOID;
            ಹೋಗು basic_type;
        ಸ್ಥಿತಿ TOK_SHORT:
            u = VT_SHORT;
            ಹೋಗು basic_type;
        ಸ್ಥಿತಿ TOK_INT:
            u = VT_INT;
            ಹೋಗು basic_type;
        ಸ್ಥಿತಿ TOK_ALIGNAS:
            { ಪೂರ್ಣಾಂಕ n;
              AttributeDef ad1;
              ಮುಂದಿನ();
              skip('(');
              memset(&ad1, 0, ಗಾತ್ರ(AttributeDef));
              ಆದರೆ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ಆದರೆ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ಇಲ್ಲದಿದ್ದರೆ
                    type_ಗಾತ್ರ(&type1, &n);
              } ಇಲ್ಲದಿದ್ದರೆ {
                  n = ಅಭಿವ್ಯಕ್ತಿ_const();
                  ಆದರೆ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ TOK_LONG:
            ಆದರೆ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ಇಲ್ಲದಿದ್ದರೆ {
                u = VT_LONG;
                ಹೋಗು basic_type;
            }
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_BOOL:
            u = VT_BOOL;
            ಹೋಗು basic_type;
        ಸ್ಥಿತಿ TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        ಸ್ಥಿತಿ TOK_FLOAT:
            u = VT_FLOAT;
            ಹೋಗು basic_type;
        ಸ್ಥಿತಿ TOK_DOUBLE:
            ಆದರೆ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ಇಲ್ಲದಿದ್ದರೆ {
                u = VT_DOUBLE;
                ಹೋಗು basic_type;
            }
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            ಹೋಗು basic_type1;
        ಸ್ಥಿತಿ TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            ಹೋಗು basic_type2;
        ಸ್ಥಿತಿ TOK_UNION:
            struct_decl(&type1, VT_UNION);
            ಹೋಗು basic_type2;

            /* type modifiers */
        ಸ್ಥಿತಿ TOK__Atomic:
            ಮುಂದಿನ();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ಆದರೆ (tok == '(') {
                parse_ಅಭಿವ್ಯಕ್ತಿ_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ಆದರೆ (type1.ref)
                    sym_ಗಮ್ಯ_attr(ad, type1.ref);
                ಹೋಗು basic_type2;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_CONST1:
        ಸ್ಥಿತಿ TOK_CONST2:
        ಸ್ಥಿತಿ TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_VOLATILE1:
        ಸ್ಥಿತಿ TOK_VOLATILE2:
        ಸ್ಥಿತಿ TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SIGNED1:
        ಸ್ಥಿತಿ TOK_SIGNED2:
        ಸ್ಥಿತಿ TOK_SIGNED3:
            ಆದರೆ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            ಮುಂದಿನ();
            typespec_ಸಿಕ್ಕಿತು = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_RESTRICT1:
        ಸ್ಥಿತಿ TOK_RESTRICT2:
        ಸ್ಥಿತಿ TOK_RESTRICT3:
            t |= VT_RESTRICT;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_ರಿಜಿಸ್ಟರ್:
        ಸ್ಥಿತಿ TOK_AUTO:
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_UNSIGNED:
            ಆದರೆ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            ಮುಂದಿನ();
            typespec_ಸಿಕ್ಕಿತು = 1;
            ನಿಲ್ಲಿಸು;

            /* storage */
        ಸ್ಥಿತಿ TOK_EXTERN:
            g = VT_EXTERN;
            ಹೋಗು storage;
        ಸ್ಥಿತಿ TOK_STATIC:
            g = VT_STATIC;
            ಹೋಗು storage;
        ಸ್ಥಿತಿ TOK_TYPEDEF:
            g = VT_TYPEDEF;
            ಹೋಗು storage;
       storage:
            ಆದರೆ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_INLINE1:
        ಸ್ಥಿತಿ TOK_INLINE2:
        ಸ್ಥಿತಿ TOK_INLINE3:
            t |= VT_INLINE;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_NORETURN3:
            ಮುಂದಿನ();
            ad->f.func_noreturn = 1;
            ನಿಲ್ಲಿಸು;
            /* GNUC attribute */
        ಸ್ಥಿತಿ TOK_ATTRIBUTE1:
        ಸ್ಥಿತಿ TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ಆದರೆ (ad->attr_ಬಹುಲಕ) {
                u = ad->attr_ಬಹುಲಕ -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ಮುಂದುವರಿ;
            /* GNUC typeof */
        ಸ್ಥಿತಿ TOK_TYPEOF1:
        ಸ್ಥಿತಿ TOK_TYPEOF2:
        ಸ್ಥಿತಿ TOK_TYPEOF3:
            ಮುಂದಿನ();
            parse_ಅಭಿವ್ಯಕ್ತಿ_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ಆದರೆ (type1.ref) {
                sym_ಗಮ್ಯ_attr(ad, type1.ref);
                ಆದರೆ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            ಹೋಗು basic_type2;
        ಸ್ಥಿತಿ TOK_THREAD_LOCAL:
        ಸ್ಥಿತಿ TOK___thread:
            ಆದರೆ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಆದರೆ (typespec_ಸಿಕ್ಕಿತು)
                ಹೋಗು the_ಕೊನೆ;
            s = sym_ಕಂಡುಹಿಡಿ(tok);
            ಆದರೆ (!s || !(s->type.t & VT_TYPEDEF))
                ಹೋಗು the_ಕೊನೆ;

            n = tok, ಮುಂದಿನ();
            ಆದರೆ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                ಹೋಗು the_ಕೊನೆ;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ಆದರೆ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ಆದರೆ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_ಗಮ್ಯ_attr(ad, s);
            typespec_ಸಿಕ್ಕಿತು = 1;
            st = bt = -2;
            ನಿಲ್ಲಿಸು;
        }
        type_ಸಿಕ್ಕಿತು = 1;
    }
the_ಕೊನೆ:
    ಆದರೆ (tcc_state->char_is_unsigned) {
        ಆದರೆ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ಆದರೆ (bt == VT_LONG)
        t |= LONG_ಗಾತ್ರ == 8 ? VT_LLONG : VT_INT;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_USING_DOUBLE_FOR_LDOUBLE
    ಆದರೆ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#ಆದರೆ_ಅಂತ್ಯ
    type->t = t;
    check_restrict_type(type);
    ಹಿಂತಿರುಗಿ type_ಸಿಕ್ಕಿತು;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ಆದರೆ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_ಸೂಚಕ(pt);
    }
}

/* apply the conversions required for an expression value */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ convert_ಅಭಿವ್ಯಕ್ತಿ_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(ಶೂನ್ಯ)
{
    skip('(');
    ಹಿಂತಿರುಗಿ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_label_instr(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ v;
    ಅಕ್ಷರ *astr;

    ಮುಂದಿನ();
    astr = parse_asm_str()->ದತ್ತಾಂಶ;
    skip(')');
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಬರೆ("asm_alias: \"%s\"\n", astr);
#ಆದರೆ_ಅಂತ್ಯ
    v = tok_alloc_const(astr);
    ಹಿಂತಿರುಗಿ v;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ post_type(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ storage, ಪೂರ್ಣಾಂಕ td)
{
    ಪೂರ್ಣಾಂಕ n, l, t1, arg_ಗಾತ್ರ, align;
    Sym **plast, *s, *ಮೊದಲ, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ *vla_array_str = ಖಾಲಿ;

    ಆದರೆ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        ಮುಂದಿನ();
	ಆದರೆ (TYPE_ನೇರ == (td & (TYPE_ನೇರ|TYPE_ABSTRACT)))
	  ಹಿಂತಿರುಗಿ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ರಾಶಿ ? &local_ರಾಶಿ : &global_ರಾಶಿ;
        ++local_scope;
        sr = sym_push2(ps, SYM_ಕ್ಷೇತ್ರ, 0, 0);

	ಆದರೆ (tok == ')')
	  l = 0;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (td & (TYPE_ನೇರ|TYPE_ABSTRACT)) {
            sym_ತೆಗೆ(ps, sr->prev, 0);
            --local_scope;
	    ವಿಲೀನ_attr (ad, &ad1);
	    ಹಿಂತಿರುಗಿ 0;
	} ಇಲ್ಲದಿದ್ದರೆ
	  l = FUNC_OLD;

        ಮೊದಲ = ಖಾಲಿ;
        plast = &ಮೊದಲ;
        arg_ಗಾತ್ರ = 0;
        ಆದರೆ (l) {
            ಗಾಗಿ(;;) {
                /* read param name and compute offset */
                ಆದರೆ (l != FUNC_OLD) {
                    ಆದರೆ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        ನಿಲ್ಲಿಸು;
                    type_decl(&pt, &ad1, &n, TYPE_ನೇರ | TYPE_ABSTRACT | TYPE_PARAM);
                    ಆದರೆ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ಆದರೆ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_ಕ್ಷೇತ್ರ;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ಖಾಲಿ;
                    ಮುಂದಿನ();
                }
                ಆದರೆ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_ಗಾತ್ರ += (type_ಗಾತ್ರ(&pt, &align) + PTR_ಗಾತ್ರ - 1) / PTR_ಗಾತ್ರ;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ತಳ್ಳು(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->ಮುಂದಿನ;
                ಆದರೆ (tok == ')')
                    ನಿಲ್ಲಿಸು;
                skip(',');
                ಆದರೆ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    ಮುಂದಿನ();
                    ನಿಲ್ಲಿಸು;
                }
		ಆದರೆ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ಇಲ್ಲದಿದ್ದರೆ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ಆದರೆ (tok == '[') {
            ಮುಂದಿನ();
            skip(']'); /* only handle simple "[]" */
            mk_ಸೂಚಕ(type);
        }
        ad->f.func_ವಾದಗಳು = arg_ಗಾತ್ರ;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->ಮುಂದಿನ = ಮೊದಲ;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_ತೆಗೆ(ps, sr, 1);
        --local_scope;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '[') {
	ಪೂರ್ಣಾಂಕ saved_nocode_wanted = nocode_wanted;
        ಪೂರ್ಣಾಂಕ array_qualifiers = 0;
        /* array definition */
        ಮುಂದಿನ();
        n = -1;
        t1 = 0;
        ಆದರೆ (td & TYPE_PARAM) ಆಗ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    ಆಯ್ಕೆ (tok) {
	    ಸ್ಥಿತಿ TOK_CONST1: ಸ್ಥಿತಿ TOK_CONST2: ಸ್ಥಿತಿ TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		ಮುಂದಿನ();
		ಮುಂದುವರಿ;
	    ಸ್ಥಿತಿ TOK_VOLATILE1: ಸ್ಥಿತಿ TOK_VOLATILE2: ಸ್ಥಿತಿ TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		ಮುಂದಿನ();
		ಮುಂದುವರಿ;
	    ಸ್ಥಿತಿ TOK_RESTRICT1: ಸ್ಥಿತಿ TOK_RESTRICT2: ಸ್ಥಿತಿ TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		ಮುಂದಿನ();
		ಮುಂದುವರಿ;
	    ಸ್ಥಿತಿ TOK_STATIC:
	    ಸ್ಥಿತಿ '*':
		ಮುಂದಿನ();
		ಮುಂದುವರಿ;
	    ಪೂರ್ವನಿಯೋಜಿತ:
		ನಿಲ್ಲಿಸು;
	    }
            ಆದರೆ (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_ಖಂಡ(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		ಮುಂದಿನ();
	        gexpr();
		ಕೊನೆ_macro();
		ಮುಂದಿನ();
		ಹೋಗು check;
            }
            ನಿಲ್ಲಿಸು;

	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok != ']') {
            ಆದರೆ (!local_ರಾಶಿ || (storage & VT_STATIC))
                vpushi(ಅಭಿವ್ಯಕ್ತಿ_const());
            ಇಲ್ಲದಿದ್ದರೆ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ಆದರೆ (n < 0)
                    tcc_error("invalid array size");
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_ನೇರ|TYPE_ABSTRACT)) | TYPE_NEST);

        ಆದರೆ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ಆದರೆ ((type->t & VT_BTYPE) == VT_VOID
            || type_ಗಾತ್ರ(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ಆದರೆ (t1 & VT_VLA) {
            ಆದರೆ (n < 0) {
		ಆದರೆ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ಇಲ್ಲದಿದ್ದರೆ {
                loc -= type_ಗಾತ್ರ(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_ಗಾತ್ರ(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        ಆದರೆ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ಆದರೆ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ಆದರೆ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ಇಲ್ಲದಿದ್ದರೆ
	        tok_str_free_str(vla_array_str);
	}
    }
    ಹಿಂತಿರುಗಿ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ಸ್ಥಿರ CType *type_decl(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ *v, ಪೂರ್ಣಾಂಕ td)
{
    CType *post, *ret;
    ಪೂರ್ಣಾಂಕ qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ಆಗ (tok == '*') {
        qualifiers = 0;
    redo:
        ಮುಂದಿನ();
        ಆಯ್ಕೆ(tok) {
        ಸ್ಥಿತಿ TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            ಹೋಗು redo;
        ಸ್ಥಿತಿ TOK_CONST1:
        ಸ್ಥಿತಿ TOK_CONST2:
        ಸ್ಥಿತಿ TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            ಹೋಗು redo;
        ಸ್ಥಿತಿ TOK_VOLATILE1:
        ಸ್ಥಿತಿ TOK_VOLATILE2:
        ಸ್ಥಿತಿ TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            ಹೋಗು redo;
        ಸ್ಥಿತಿ TOK_RESTRICT1:
        ಸ್ಥಿತಿ TOK_RESTRICT2:
        ಸ್ಥಿತಿ TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            ಹೋಗು redo;
	/* XXX: clarify attribute handling */
	ಸ್ಥಿತಿ TOK_ATTRIBUTE1:
	ಸ್ಥಿತಿ TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    ನಿಲ್ಲಿಸು;
        }
        mk_ಸೂಚಕ(type);
        type->t |= qualifiers;
	ಆದರೆ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ಆದರೆ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ಆದರೆ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ಇಲ್ಲದಿದ್ದರೆ
	  ಹೋಗು abstract;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_IDENT && (td & TYPE_ನೇರ)) {
	/* type identifier */
	*v = tok;
	ಮುಂದಿನ();
    } ಇಲ್ಲದಿದ್ದರೆ {
  abstract:
	ಆದರೆ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_ನೇರ|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ಹಿಂತಿರುಗಿ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC ಶೂನ್ಯ indir(ಶೂನ್ಯ)
{
    ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ಹಿಂತಿರುಗಿ;
        expect("pointer");
    }
    ಆದರೆ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ಆದರೆ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#ಆದರೆ_ಅಂತ್ಯ
    }
}

/* pass a parameter to a function and do type checking and casting */
ಸ್ಥಿರ ಶೂನ್ಯ gfunc_param_typed(Sym *func, Sym *arg)
{
    ಪೂರ್ಣಾಂಕ func_type;
    CType type;

    func_type = func->f.func_type;
    ಆದರೆ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ಖಾಲಿ)) {
        /* default casting : only need to convert float to double */
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (arg == ಖಾಲಿ) {
        tcc_error("too many arguments to function");
    } ಇಲ್ಲದಿದ್ದರೆ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_ನಿಯೋಜಿಸು_cast(&type);
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
    ಪೂರ್ಣಾಂಕ n;
    AttributeDef ad;

    skip('(');
    ಆದರೆ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಅಭಿವ್ಯಕ್ತಿ_type(type, gexpr);
    }
    skip(')');
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_type(CType *type)
{
    AttributeDef ad;
    ಪೂರ್ಣಾಂಕ n;

    ಆದರೆ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_builtin_params(ಪೂರ್ಣಾಂಕ nc, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ವಾದಗಳು)
{
    ಅಕ್ಷರ c, sep = '(';
    CType type;
    ಆದರೆ (nc)
        nocode_wanted++;
    ಮುಂದಿನ();
    ಆದರೆ (*ವಾದಗಳು == 0)
	skip(sep);
    ಆಗ ((c = *ವಾದಗಳು++)) {
	skip(sep);
	sep = ',';
        ಆದರೆ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ಮುಂದುವರಿ;
        }
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        type.ref = ಖಾಲಿ;
        type.t = 0;
	ಆಯ್ಕೆ (c) {
	    ಸ್ಥಿತಿ 'e':
		ಮುಂದುವರಿ;
	    ಸ್ಥಿತಿ 'V':
                type.t = VT_CONSTANT;
	    ಸ್ಥಿತಿ 'v':
                type.t |= VT_VOID;
                mk_ಸೂಚಕ (&type);
                ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 'S':
                type.t = VT_CONSTANT;
	    ಸ್ಥಿತಿ 's':
                type.t |= char_type.t;
                mk_ಸೂಚಕ (&type);
                ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 'i':
                type.t = VT_INT;
                ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 'l':
                type.t = VT_ಗಾತ್ರ_T;
                ನಿಲ್ಲಿಸು;
	    ಪೂರ್ವನಿಯೋಜಿತ:
                ನಿಲ್ಲಿಸು;
	}
        gen_ನಿಯೋಜಿಸು_cast(&type);
    }
    skip(')');
    ಆದರೆ (nc)
        nocode_wanted--;
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_atomic(ಪೂರ್ಣಾಂಕ atok)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    ಅಕ್ಷರ buf[40];
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ templates[] = {
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
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾದರಿ = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ಖಾಲಿ;
    ಗಾತ್ರ_2 = 0; /* pacify compiler */
    ಮುಂದಿನ();
    skip('(');
    ಗಾಗಿ (arg = 0;;) {
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        ಆಯ್ಕೆ (ಮಾದರಿ[arg]) {
        ಸ್ಥಿತಿ 'a':
        ಸ್ಥಿತಿ 'A':
            atom_ptr = &vtop->type;
            ಆದರೆ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(atom, &align);
            ಆದರೆ (ಗಾತ್ರ_2 > 8
                || (ಗಾತ್ರ_2 & (ಗಾತ್ರ_2 - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_ಗಾತ್ರ(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ 'p':
            ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_ಗಾತ್ರ(pointed_type(&vtop->type), &align) != ಗಾತ್ರ_2)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_ನಿಯೋಜಿಸು_cast(atom_ptr);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'v':
            gen_ನಿಯೋಜಿಸು_cast(atom);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'l':
            indir();
            gen_ನಿಯೋಜಿಸು_cast(atom);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'm':
            gen_ನಿಯೋಜಿಸು_cast(&int_type);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 'b':
            ct.t = VT_BOOL;
            gen_ನಿಯೋಜಿಸು_cast(&ct);
            ನಿಲ್ಲಿಸು;
        }
        ಆದರೆ ('.' == ಮಾದರಿ[++arg])
            ನಿಲ್ಲಿಸು;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    ಆಯ್ಕೆ (ಮಾದರಿ[arg + 1]) {
    ಸ್ಥಿತಿ 'b':
        ct.t = VT_BOOL;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 'v':
        ct = *atom;
        ನಿಲ್ಲಿಸು;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), ಗಾತ್ರ_2);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ಆದರೆ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ಇಲ್ಲದಿದ್ದರೆ
        vtop->type.t = VT_INT;
#ಆದರೆ_ಅಂತ್ಯ
    }
    gen_cast(&ct);
    ಆದರೆ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC ಶೂನ್ಯ unary(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ n, t, align, ಗಾತ್ರ_2, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ಆದರೆ (debug_modes)
        tcc_debug_ಸಾಲು(tcc_state), tcc_tcov_check_ಸಾಲು (tcc_state, 1);

    type.ref = ಖಾಲಿ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_ಮುಂದಿನ:
    ಆಯ್ಕೆ(tok) {
    ಸ್ಥಿತಿ TOK_EXTENSION:
        ಮುಂದಿನ();
        ಹೋಗು tok_ಮುಂದಿನ;
    ಸ್ಥಿತಿ TOK_LCHAR:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        t = VT_SHORT|VT_UNSIGNED;
        ಹೋಗು ತಳ್ಳು_tokc;
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ TOK_CINT:
    ಸ್ಥಿತಿ TOK_CCHAR: 
	t = VT_INT;
 ತಳ್ಳು_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CLLONG:
        t = VT_LLONG;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CFLOAT:
        t = VT_FLOAT;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CDOUBLE:
        t = VT_DOUBLE;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CLDOUBLE:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ಇಲ್ಲದಿದ್ದರೆ
        t = VT_LDOUBLE;
#ಆದರೆ_ಅಂತ್ಯ
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CLONG:
        t = (LONG_ಗಾತ್ರ == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK_CULONG:
        t = (LONG_ಗಾತ್ರ == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	ಹೋಗು ತಳ್ಳು_tokc;
    ಸ್ಥಿತಿ TOK___FUNCTION__:
        ಆದರೆ (!gnu_ext)
            ಹೋಗು tok_identifier;
        /* fall thru */
    ಸ್ಥಿತಿ TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.ಗಾತ್ರ_2 = tokcstr.ಗಾತ್ರ_2;
        tokc.str.ದತ್ತಾಂಶ = tokcstr.ದತ್ತಾಂಶ;
        ಹೋಗು case_TOK_STR;
    ಸ್ಥಿತಿ TOK_LSTR:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        t = VT_SHORT | VT_UNSIGNED;
#ಇಲ್ಲದಿದ್ದರೆ
        t = VT_INT;
#ಆದರೆ_ಅಂತ್ಯ
        ಹೋಗು str_init;
    ಸ್ಥಿತಿ TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ಆದರೆ (tcc_state->warn_write_ಅಕ್ಷರಸರಣಿಗಳು & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_ಸೂಚಕ(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, ಗಾತ್ರ(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SOTYPE:
    ಸ್ಥಿತಿ '(':
        t = tok;
        ಮುಂದಿನ();
        /* cast ? */
        ಆದರೆ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ಆದರೆ (tok == '{') {
                    /* data is allocated locally by default */
                ಆದರೆ (global_ಅಭಿವ್ಯಕ್ತಿ)
                    r = VT_CONST;
                ಇಲ್ಲದಿದ್ದರೆ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ಆದರೆ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, ಗಾತ್ರ(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ಹಿಂತಿರುಗಿ;
            } ಇಲ್ಲದಿದ್ದರೆ {
                unary();
                gen_cast(&type);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '{') {
	    ಪೂರ್ಣಾಂಕ saved_nocode_wanted = nocode_wanted;
            ಆದರೆ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ಆದರೆ (0 == local_scope)
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
            ಖಂಡ(STMT_ಅಭಿವ್ಯಕ್ತಿ);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ಆದರೆ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ಇಲ್ಲದಿದ್ದರೆ {
            gexpr();
            skip(')');
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '*':
        ಮುಂದಿನ();
        unary();
        indir();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '&':
        ಮುಂದಿನ();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ಆದರೆ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_ಸೂಚಕ(&vtop->type);
        gaddrof();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '!':
        ಮುಂದಿನ();
        unary();
        gen_test_zero(TOK_EQ);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '~':
        ಮುಂದಿನ();
        unary();
        vpushi(-1);
        gen_op('^');
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '+':
        ಮುಂದಿನ();
        unary();
        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ಆದರೆ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_SIZEOF:
    ಸ್ಥಿತಿ TOK_ALIGNOF1:
    ಸ್ಥಿತಿ TOK_ALIGNOF2:
    ಸ್ಥಿತಿ TOK_ALIGNOF3:
        t = tok;
        ಮುಂದಿನ();
        ಆದರೆ (tok == '(')
            tok = TOK_SOTYPE;
        ಅಭಿವ್ಯಕ್ತಿ_type(&type, unary);
        ಆದರೆ (t == TOK_SIZEOF) {
            vpush_type_ಗಾತ್ರ(&type, &align);
            gen_cast_s(VT_ಗಾತ್ರ_T);
        } ಇಲ್ಲದಿದ್ದರೆ {
            type_ಗಾತ್ರ(&type, &align);
            s = ಖಾಲಿ;
            ಆದರೆ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ಆದರೆ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_builtin_ಆರಿಸು_ಅಭಿವ್ಯಕ್ತಿ:
	{
	    int64_t c;
	    ಮುಂದಿನ();
	    skip('(');
	    c = ಅಭಿವ್ಯಕ್ತಿ_const64();
	    skip(',');
	    ಆದರೆ (!c) {
		nocode_wanted++;
	    }
	    ಅಭಿವ್ಯಕ್ತಿ_eq();
	    ಆದರೆ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ಆದರೆ (c) {
		nocode_wanted++;
	    }
	    ಅಭಿವ್ಯಕ್ತಿ_eq();
	    ಆದರೆ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        ಸಂಕೇತ_OFF();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_builtin_ಚೌಕಟ್ಟು_ವಿಳಾಸ:
    ಸ್ಥಿತಿ TOK_builtin_return_ವಿಳಾಸ:
        {
            ಪೂರ್ಣಾಂಕ tok1 = tok;
            ಪೂರ್ಣಾಂಕ level;
            ಮುಂದಿನ();
            skip('(');
            level = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಆದರೆ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_ಸೂಚಕ(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ಆಗ (level--) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
                vpushi(2*PTR_ಗಾತ್ರ);
                gen_op('-');
#ಆದರೆ_ಅಂತ್ಯ
                mk_ಸೂಚಕ(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ಆದರೆ (tok1 == TOK_builtin_return_ವಿಳಾಸ) {
                // assume return address is just above frame pointer on stack
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
                vpushi(2*PTR_ಗಾತ್ರ);
                gen_op('+');
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
                vpushi(PTR_ಗಾತ್ರ);
                gen_op('-');
#ಇಲ್ಲದಿದ್ದರೆ
                vpushi(PTR_ಗಾತ್ರ);
                gen_op('+');
#ಆದರೆ_ಅಂತ್ಯ
                mk_ಸೂಚಕ(&vtop->type);
                indir();
            }
        }
        ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    ಸ್ಥಿತಿ TOK_builtin_va_ಆರಂಭ:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ಆದರೆ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ಆದರೆ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_ಆರಂಭ();
	vstore();
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಸ್ಥಿತಿ TOK_builtin_va_ಆರಂಭ:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ಆದರೆ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ಆದರೆ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_ಸೂಚಕ_type;
	vtop->c.i += 8;
	vstore();
        ನಿಲ್ಲಿಸು;
#ಇಲ್ಲದಿದ್ದರೆ
    ಸ್ಥಿತಿ TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
    ಸ್ಥಿತಿ TOK_builtin_va_ಆರಂಭ: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_ಆರಂಭ();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ನಿಲ್ಲಿಸು;
    }
    ಸ್ಥಿತಿ TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        ನಿಲ್ಲಿಸು;
    }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
    ಸ್ಥಿತಿ TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ನಿಲ್ಲಿಸು;
    }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    ಸ್ಥಿತಿ TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ನಿಲ್ಲಿಸು;
    }
#ಆದರೆ_ಅಂತ್ಯ

    /* atomic operations */
    ಸ್ಥಿತಿ TOK___atomic_store:
    ಸ್ಥಿತಿ TOK_atomic_ತುಂಬು:
    ಸ್ಥಿತಿ TOK___atomic_exchange:
    ಸ್ಥಿತಿ TOK___atomic_compare_exchange:
    ಸ್ಥಿತಿ TOK_atomic_fetch_ಕೂಡಿಸು:
    ಸ್ಥಿತಿ TOK___atomic_fetch_sub:
    ಸ್ಥಿತಿ TOK___atomic_fetch_or:
    ಸ್ಥಿತಿ TOK___atomic_fetch_xor:
    ಸ್ಥಿತಿ TOK___atomic_fetch_and:
    ಸ್ಥಿತಿ TOK___atomic_fetch_nand:
    ಸ್ಥಿತಿ TOK_atomic_ಕೂಡಿಸು_fetch:
    ಸ್ಥಿತಿ TOK___atomic_sub_fetch:
    ಸ್ಥಿತಿ TOK___atomic_or_fetch:
    ಸ್ಥಿತಿ TOK___atomic_xor_fetch:
    ಸ್ಥಿತಿ TOK___atomic_and_fetch:
    ಸ್ಥಿತಿ TOK___atomic_nand_fetch:
        parse_atomic(tok);
        ನಿಲ್ಲಿಸು;

    /* pre operations */
    ಸ್ಥಿತಿ TOK_INC:
    ಸ್ಥಿತಿ TOK_DEC:
        t = tok;
        ಮುಂದಿನ();
        unary();
        inc(0, t);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
        ಮುಂದಿನ();
        unary();
	ಆದರೆ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ಇಲ್ಲದಿದ್ದರೆ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LAND:
        ಆದರೆ (!gnu_ext)
            ಹೋಗು tok_identifier;
        ಮುಂದಿನ();
        /* allow to take the address of a label */
        ಆದರೆ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_ಕಂಡುಹಿಡಿ(tok);
        ಆದರೆ (!s) {
            s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok, LABEL_FORWARD);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ಆದರೆ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_ಸೂಚಕ(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_GENERIC:
    {
	CType controlling_type;
	ಪೂರ್ಣಾಂಕ has_default = 0;
	ಪೂರ್ಣಾಂಕ has_ಹೊಂದಿಕೆ = 0;
	ಪೂರ್ಣಾಂಕ learn = 0;
	TokenString *str = ಖಾಲಿ;
	ಪೂರ್ಣಾಂಕ saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_ಮುಖವಾಡ;

        ಮುಂದಿನ();
	skip('(');
	ಅಭಿವ್ಯಕ್ತಿ_type(&controlling_type, ಅಭಿವ್ಯಕ್ತಿ_eq);
	convert_ಅಭಿವ್ಯಕ್ತಿ_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        ಗಾಗಿ (;;) {
	    learn = 0;
	    skip(',');
	    ಆದರೆ (tok == TOK_DEFAULT) {
		ಆದರೆ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ಆದರೆ (!has_ಹೊಂದಿಕೆ)
		    learn = 1;
		ಮುಂದಿನ();
	    } ಇಲ್ಲದಿದ್ದರೆ {
		ಪೂರ್ಣಾಂಕ v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ಆದರೆ (compare_types(&controlling_type, &type, 0)) {
		    ಆದರೆ (has_ಹೊಂದಿಕೆ) {
		      tcc_error("type match twice");
		    }
		    has_ಹೊಂದಿಕೆ = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ಆದರೆ (learn) {
		ಆದರೆ (str)
		    tok_str_free(str);
		skip_or_save_ಖಂಡ(&str);
	    } ಇಲ್ಲದಿದ್ದರೆ {
		skip_or_save_ಖಂಡ(ಖಾಲಿ);
	    }
	    ಆದರೆ (tok == ')')
		ನಿಲ್ಲಿಸು;
	}
	ಆದರೆ (!str) {
	    ಅಕ್ಷರ buf[60];
	    type_ಗಮ್ಯ_str(buf, ಗಾತ್ರ buf, &controlling_type, ಖಾಲಿ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	ಮುಂದಿನ();
	ಅಭಿವ್ಯಕ್ತಿ_eq();
	ಆದರೆ (tok != TOK_EOF)
	    expect(",");
	ಕೊನೆ_macro();
        ಮುಂದಿನ();
	ನಿಲ್ಲಿಸು;
    }
    // special qnan , snan and infinity values
    ಸ್ಥಿತಿ TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK___SNAN__:
	n = 0x7f800001;
	ಹೋಗು special_math_val;
    ಸ್ಥಿತಿ TOK___INF__:
	n = 0x7f800000;
	ಹೋಗು special_math_val;

    ಪೂರ್ವನಿಯೋಜಿತ:
    tok_identifier:
        ಆದರೆ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        ಮುಂದಿನ();
        s = sym_ಕಂಡುಹಿಡಿ(t);
        ಆದರೆ (!s || IS_ASM_SYM(s)) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = get_tok_str(t, ಖಾಲಿ);
            ಆದರೆ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ಆದರೆ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ಆದರೆ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ಆದರೆ (r & VT_SYM) {
            vtop->c.i = 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            ಆದರೆ (s->a.dllimport) {
                mk_ಸೂಚಕ(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        ನಿಲ್ಲಿಸು;
    }
    
    /* post operations */
    ಆಗ (1) {
        ಆದರೆ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '.' || tok == TOK_ARROW) {
            ಪೂರ್ಣಾಂಕ qualifiers, cumofs;
            /*ಕ್ಷೇತ್ರ*/ 
            ಆದರೆ (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            ಮುಂದಿನ();
	    s = ಕಂಡುಹಿಡಿ_ಕ್ಷೇತ್ರ(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_ಸೂಚಕ_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            ಆದರೆ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ಆದರೆ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ಆದರೆ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#ಆದರೆ_ಅಂತ್ಯ
            }
            ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '[') {
            ಮುಂದಿನ();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '(') {
            SValue ret;
            Sym *sa;
            ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ಆದರೆ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        ಹೋಗು error_func;
                } ಇಲ್ಲದಿದ್ದರೆ {
                error_func:
                    expect("function pointer");
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            ಮುಂದಿನ();
            sa = s->ಮುಂದಿನ; /* first parameter */
            nb_ವಾದಗಳು = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ಆದರೆ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ಆದರೆ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&s->type, &align);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ಆದರೆ (ಗಾತ್ರ_2 < 16)
                    ಆಗ (ಗಾತ್ರ_2 & (ಗಾತ್ರ_2 - 1))
                        ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 | (ಗಾತ್ರ_2 - 1)) + 1;
#ಆದರೆ_ಅಂತ್ಯ
                    loc = (loc - ಗಾತ್ರ_2) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
                    ಆದರೆ (tcc_state->do_bounds_check)
                        --loc;
#ಆದರೆ_ಅಂತ್ಯ
                    ret.c = vtop->c;
                    ಆದರೆ (ret_nregs < 0)
                      vtop--;
                    ಇಲ್ಲದಿದ್ದರೆ
                      nb_ವಾದಗಳು++;
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ಆದರೆ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ಖಾಲಿ;
            ಆದರೆ (tok != ')') {
                r = tcc_state->ಹಿಮ್ಮುಖ_funcargs;
                ಗಾಗಿ(;;) {
                    ಆದರೆ (r) {
                        skip_or_save_ಖಂಡ(&p2);
                        p2->prev = p, p = p2;
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ಅಭಿವ್ಯಕ್ತಿ_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_ವಾದಗಳು++;
                    ಆದರೆ (sa)
                        sa = sa->ಮುಂದಿನ;
                    ಆದರೆ (tok == ')')
                        ನಿಲ್ಲಿಸು;
                    skip(',');
                }
            }
            ಆದರೆ (sa)
                tcc_error("too few arguments to function");

            ಆದರೆ (p) { /* with reverse_funcargs */
                ಗಾಗಿ (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    ಮಾಡು {
                        sa = sa->ಮುಂದಿನ, p2 = p2->prev;
                    } ಆಗ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), ಮುಂದಿನ();
                    ಅಭಿವ್ಯಕ್ತಿ_eq();
                    gfunc_param_typed(s, sa);
                    ಕೊನೆ_macro();
                }
                vrev(n);
            }

            ಮುಂದಿನ();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_ವಾದಗಳು);

            ಆದರೆ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
                arch_transfer_ret_regs(1);
#ಆದರೆ_ಅಂತ್ಯ
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* return value */
                n = ret_nregs;
                ಆಗ (n > 1) {
                    ಪೂರ್ಣಾಂಕ rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    ಗಾಗಿ (r = 0; r < NB_REGS; ++r)
                        ಆದರೆ (reg_classes[r] & rc)
                            ನಿಲ್ಲಿಸು;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ಆದರೆ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    ಪೂರ್ಣಾಂಕ addr, ಸ್ಥಾನಾಂತರ;

                    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    ಗಾತ್ರ_2 = (ಗಾತ್ರ_2 + regsize - 1) & -regsize;
                    ಆದರೆ (ret_align > align)
                        align = ret_align;
                    loc = (loc - ಗಾತ್ರ_2) & -align;
                    addr = loc;
                    ಸ್ಥಾನಾಂತರ = 0;
                    ಗಾಗಿ (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + ಸ್ಥಾನಾಂತರ);
                        vswap();
                        vstore();
                        vtop--;
                        ಆದರೆ (--ret_nregs == 0)
                          ನಿಲ್ಲಿಸು;
                        ಸ್ಥಾನಾಂತರ += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                ಆದರೆ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ಇಲ್ಲದಿದ್ದರೆ
                    vtop->type.t = VT_INT;
#ಆದರೆ_ಅಂತ್ಯ
                }
            }
            ಆದರೆ (s->f.func_noreturn) {
                ಆದರೆ (debug_modes)
	            tcc_tcov_ಖಂಡ_ಕೊನೆ(tcc_state, -1);
                ಸಂಕೇತ_OFF();
	    }
        } ಇಲ್ಲದಿದ್ದರೆ {
            ನಿಲ್ಲಿಸು;
        }
    }
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ precedence_parser /* original top-down parser */

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_prod(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;

    unary();
    ಆಗ ((t = tok) == '*' || t == '/' || t == '%') {
        ಮುಂದಿನ();
        unary();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_prod();
    ಆಗ ((t = tok) == '+' || t == '-') {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_prod();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_ಸರಿಸು(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ();
    ಆಗ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmp(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_ಸರಿಸು();
    ಆಗ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_ಸರಿಸು();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmpeq(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;

    ಅಭಿವ್ಯಕ್ತಿ_cmp();
    ಆಗ ((t = tok) == TOK_EQ || t == TOK_NE) {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_cmp();
        gen_op(t);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_and(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_cmpeq();
    ಆಗ (tok == '&') {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_cmpeq();
        gen_op('&');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_xor(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_and();
    ಆಗ (tok == '^') {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_and();
        gen_op('^');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_or(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_xor();
    ಆಗ (tok == '|') {
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_xor();
        gen_op('|');
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಂಕ op);

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_land(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_or();
    ಆದರೆ (tok == TOK_LAND)
        ಅಭಿವ್ಯಕ್ತಿ_landor(tok);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_lor(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_land();
    ಆದರೆ (tok == TOK_LOR)
        ಅಭಿವ್ಯಕ್ತಿ_landor(tok);
}

# define ಅಭಿವ್ಯಕ್ತಿ_landor_ಮುಂದಿನ(op) op == TOK_LAND ? ಅಭಿವ್ಯಕ್ತಿ_or() : ಅಭಿವ್ಯಕ್ತಿ_land()
#ಇಲ್ಲದಿದ್ದರೆ /* defined precedence_parser */
# define ಅಭಿವ್ಯಕ್ತಿ_landor_ಮುಂದಿನ(op) unary(), ಅಭಿವ್ಯಕ್ತಿ_infix(precedence(op) + 1)
# define ಅಭಿವ್ಯಕ್ತಿ_lor() unary(), ಅಭಿವ್ಯಕ್ತಿ_infix(1)

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ precedence(ಪೂರ್ಣಾಂಕ tok)
{
    ಆಯ್ಕೆ (tok) {
        ಸ್ಥಿತಿ TOK_LOR: ಹಿಂತಿರುಗಿ 1;
        ಸ್ಥಿತಿ TOK_LAND: ಹಿಂತಿರುಗಿ 2;
	ಸ್ಥಿತಿ '|': ಹಿಂತಿರುಗಿ 3;
	ಸ್ಥಿತಿ '^': ಹಿಂತಿರುಗಿ 4;
	ಸ್ಥಿತಿ '&': ಹಿಂತಿರುಗಿ 5;
	ಸ್ಥಿತಿ TOK_EQ: ಸ್ಥಿತಿ TOK_NE: ಹಿಂತಿರುಗಿ 6;
 relat: ಸ್ಥಿತಿ TOK_ULT: ಸ್ಥಿತಿ TOK_UGE: ಹಿಂತಿರುಗಿ 7;
	ಸ್ಥಿತಿ TOK_SHL: ಸ್ಥಿತಿ TOK_SAR: ಹಿಂತಿರುಗಿ 8;
	ಸ್ಥಿತಿ '+': ಸ್ಥಿತಿ '-': ಹಿಂತಿರುಗಿ 9;
	ಸ್ಥಿತಿ '*': ಸ್ಥಿತಿ '/': ಸ್ಥಿತಿ '%': ಹಿಂತಿರುಗಿ 10;
	ಪೂರ್ವನಿಯೋಜಿತ:
	    ಆದರೆ (tok >= TOK_ULE && tok <= TOK_GT)
	        ಹೋಗು relat;
	    ಹಿಂತಿರುಗಿ 0;
    }
}
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ prec[256];
ಸ್ಥಿರ ಶೂನ್ಯ init_prec(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#ವ್ಯಾಖ್ಯಾನಿಸು precedence(i) ((ಚಿಹ್ನೆರಹಿತ)i < 256 ? prec[i] : 0)

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಂಕ op);

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_infix(ಪೂರ್ಣಾಂಕ p)
{
    ಪೂರ್ಣಾಂಕ t = tok, p2;
    ಆಗ ((p2 = precedence(t)) >= p) {
        ಆದರೆ (t == TOK_LOR || t == TOK_LAND) {
            ಅಭಿವ್ಯಕ್ತಿ_landor(t);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಮುಂದಿನ();
            unary();
            ಆದರೆ (precedence(tok) > p2)
              ಅಭಿವ್ಯಕ್ತಿ_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ condition_3way(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ c = -1;
    ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ಹಿಂತಿರುಗಿ c;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_landor(ಪೂರ್ಣಾಂಕ op)
{
    ಪೂರ್ಣಾಂಕ t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    ಗಾಗಿ(;;) {
        c = f ? i : condition_3way();
        ಆದರೆ (c < 0)
            save_regs(1), cc = 0;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c != i)
            nocode_wanted++, f = 1;
        ಆದರೆ (tok != op)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (c < 0)
            t = gvtst(i, t);
        ಇಲ್ಲದಿದ್ದರೆ
            vpop();
        ಮುಂದಿನ();
        ಅಭಿವ್ಯಕ್ತಿ_landor_ಮುಂದಿನ(op);
    }
    ಆದರೆ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ಇಲ್ಲದಿದ್ದರೆ {
        gvtst_ಗಣ(i, t);
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ is_cond_bool(SValue *sv)
{
    ಆದರೆ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ಹಿಂತಿರುಗಿ (ಚಿಹ್ನೆರಹಿತ)sv->c.i < 2;
    ಆದರೆ (sv->r == VT_CMP)
        ಹಿಂತಿರುಗಿ 1;
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cond(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    ಅಭಿವ್ಯಕ್ತಿ_lor();
    ಆದರೆ (tok == '?') {
        ಮುಂದಿನ();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ಆದರೆ (!g) {
            ಆದರೆ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ಇಲ್ಲದಿದ್ದರೆ {
                vpop();
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ಆದರೆ (c == 0)
          nocode_wanted++;
        ಆದರೆ (!g)
          gexpr();

        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_ಸೂಚಕ(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ಆದರೆ (g) {
            u = tt;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ಇಲ್ಲದಿದ್ದರೆ
          u = 0;

        ಆದರೆ (c == 0)
          nocode_wanted--;
        ಆದರೆ (c == 1)
          nocode_wanted++;
        skip(':');
        ಅಭಿವ್ಯಕ್ತಿ_cond();

        ಆದರೆ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_ಸೂಚಕ(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ಆದರೆ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ಆದರೆ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_ಗಣ(0, t1);
            gvtst_ಗಣ(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            ಹಿಂತಿರುಗಿ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ಆದರೆ (c != 1) {
            gen_cast(&type);
            ಆದರೆ (islv) {
                mk_ಸೂಚಕ(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ಆದರೆ (USING_TWO_ಪದಗಳು(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ಆದರೆ (c < 0) {
            ಆದರೆ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ಆದರೆ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
ಕಾರ್ಯಾಂಶ*/
        ಆದರೆ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ಆದರೆ (islv) {
                mk_ಸೂಚಕ(&vtop->type);
                gaddrof();
            }
        }

        ಆದರೆ (c < 0) {
            ಆದರೆ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ಆದರೆ (islv)
          indir();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_eq(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;
    
    ಅಭಿವ್ಯಕ್ತಿ_cond();
    ಆದರೆ ((t = tok) == '=' || TOK_ನಿಯೋಜಿಸು(t)) {
        test_lvalue();
        ಮುಂದಿನ();
        ಆದರೆ (t == '=') {
            ಅಭಿವ್ಯಕ್ತಿ_eq();
        } ಇಲ್ಲದಿದ್ದರೆ {
            vdup();
            ಅಭಿವ್ಯಕ್ತಿ_eq();
            gen_op(TOK_ನಿಯೋಜಿಸು_OP(t));
        }
        vstore();
    }
}

ST_FUNC ಶೂನ್ಯ gexpr(ಶೂನ್ಯ)
{
    ಅಭಿವ್ಯಕ್ತಿ_eq();
    ಆದರೆ (tok == ',') {
        ಮಾಡು {
            vpop();
            ಮುಂದಿನ();
            ಅಭಿವ್ಯಕ್ತಿ_eq();
        } ಆಗ (tok == ',');

        /* convert array & function to pointer */
        convert_ಅಭಿವ್ಯಕ್ತಿ_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ಆದರೆ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ಆದರೆ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ಸ್ಥಿರ ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_const1(ಶೂನ್ಯ)
{
    nocode_wanted += CONST_WANTED_ಬಿಟ್;
    ಅಭಿವ್ಯಕ್ತಿ_cond();
    nocode_wanted -= CONST_WANTED_ಬಿಟ್;
}

/* parse an integer constant and return its value. */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ int64_t ಅಭಿವ್ಯಕ್ತಿ_const64(ಶೂನ್ಯ)
{
    int64_t c;
    ಅಭಿವ್ಯಕ್ತಿ_const1();
    ಆದರೆ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ಹಿಂತಿರುಗಿ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC ಪೂರ್ಣಾಂಕ ಅಭಿವ್ಯಕ್ತಿ_const(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ c;
    int64_t wc = ಅಭಿವ್ಯಕ್ತಿ_const64();
    c = wc;
    ಆದರೆ (c != wc && (ಚಿಹ್ನೆರಹಿತ)c != wc)
        tcc_error("constant exceeds 32 bit");
    ಹಿಂತಿರುಗಿ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_ARM64
ಸ್ಥಿರ ಶೂನ್ಯ gfunc_return(CType *func_type)
{
    ಆದರೆ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        ಪೂರ್ಣಾಂಕ ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ಆದರೆ (ret_nregs < 0) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
            arch_transfer_ret_regs(0);
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_ಸೂಚಕ(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* returning structure packed into registers */
            ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, addr, align, rc, n;
            ಗಾತ್ರ_2 = type_ಗಾತ್ರ(func_type,&align);
            ಆದರೆ (ret_nregs * regsize > ಗಾತ್ರ_2 ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ಆದರೆ (ret_nregs * regsize > ಗಾತ್ರ_2)
		    ಗಾತ್ರ_2 = ret_nregs * regsize;
		ಆದರೆ (ret_align > align)
		    align = ret_align;
                loc = (loc - ಗಾತ್ರ_2) & -align;
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
            ಗಾಗಿ (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_ಸ್ಥಾನಾಂತರ(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ check_func_return(ಶೂನ್ಯ)
{
    ಆದರೆ ((func_vt.t & VT_BTYPE) == VT_VOID)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ case_cmp(uint64_t a, uint64_t b)
{
    ಆದರೆ (cur_switch->sv.type.t & VT_UNSIGNED)
        ಹಿಂತಿರುಗಿ a < b ? -1 : a > b;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ case_cmp_qs(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *pa, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *pb)
{
    ಹಿಂತಿರುಗಿ case_cmp((*(ರಚನೆ case_t**)pa)->v1, (*(ರಚನೆ case_t**)pb)->v1);
}

ಸ್ಥಿರ ಶೂನ್ಯ case_ವಿಂಗಡಿಸು(ರಚನೆ switch_t *sw)
{
    ರಚನೆ case_t **p;
    ಆದರೆ (sw->n < 2)
        ಹಿಂತಿರುಗಿ;
    qsort(sw->p, sw->n, ಗಾತ್ರ *sw->p, case_cmp_qs);
    p = sw->p;
    ಆಗ (p < sw->p + sw->n - 1) {
        ಆದರೆ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            ಪೂರ್ಣಾಂಕ l1 = p[0]->ಸಾಲು, l2 = p[1]->ಸಾಲು;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * ಗಾತ್ರ *p);
        } ಇಲ್ಲದಿದ್ದರೆ
            ++p;
    }
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ gcase(ರಚನೆ case_t **ತಳ, ಪೂರ್ಣಾಂಕ len, ಪೂರ್ಣಾಂಕ dsym)
{
    ರಚನೆ case_t *p;
    ಪೂರ್ಣಾಂಕ t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ಆದರೆ (t != VT_LLONG)
        t = VT_INT;
    ಆಗ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = ತಳ[l2];
        vdup(), vpush64(t, p->v2);
        ಆದರೆ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ಆದರೆ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ಇಲ್ಲದಿದ್ದರೆ
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(ತಳ, l2, dsym);
            gsym(e);
        }
        ++l2, ತಳ += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    ಹಿಂತಿರುಗಿ gjmp(dsym);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಕೊನೆ_switch(ಶೂನ್ಯ)
{
    ರಚನೆ switch_t *sw = cur_switch;
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
    ಆಗ (sv >= vstack) {
        ಆದರೆ (sv->sym && (sv->r & VT_LVAL)) {
            ಪೂರ್ಣಾಂಕ align, ಗಾತ್ರ_2 = type_ಗಾತ್ರ(&sv->type, &align);
            ಪೂರ್ಣಾಂಕ r2, l = get_ತಾತ್ಕಾಲಿಕ_local_var(ಗಾತ್ರ_2, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    ಗಾಗಿ (; cls != stop; cls = cls->ಮುಂದಿನ) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_ಸೂಚಕ(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


ಸ್ಥಿರ ಶೂನ್ಯ try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    ಪೂರ್ಣಾಂಕ ocd, ccd;

    ಆದರೆ (!cur_scope->cl.s)
	ಹಿಂತಿರುಗಿ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_ಕ್ಷೇತ್ರ : 0;
    ಗಾಗಿ (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->ಮುಂದಿನ)
      ;
    ಗಾಗಿ (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->ಮುಂದಿನ)
      ;
    ಗಾಗಿ (; cc != oc; cc = cc->ಮುಂದಿನ, oc = oc->ಮುಂದಿನ, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ಸ್ಥಿರ ಶೂನ್ಯ ಖಂಡ_cleanup(ರಚನೆ scope *o)
{
    ಪೂರ್ಣಾಂಕ jmp = 0;
    Sym *g, **pg;
    ಗಾಗಿ (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ಆದರೆ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->ಮುಂದಿನ;
            ಆದರೆ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ಆದರೆ (!o->cl.n)
                ಹೋಗು remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } ಇಲ್ಲದಿದ್ದರೆ {
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

ಸ್ಥಿರ ಶೂನ್ಯ vla_restore(ಪೂರ್ಣಾಂಕ loc)
{
    ಆದರೆ (loc)
        gen_vla_sp_restore(loc);
}

ಸ್ಥಿರ ಶೂನ್ಯ vla_leave(ರಚನೆ scope *o)
{
    ರಚನೆ scope *c = cur_scope, *v = ಖಾಲಿ;
    ಗಾಗಿ (; c != o && c; c = c->prev)
      ಆದರೆ (c->vla.ಅಂಕೆ)
        v = c;
    ಆದರೆ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ಸ್ಥಿರ ಶೂನ್ಯ new_scope(ರಚನೆ scope *o)
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

ಸ್ಥಿರ ಶೂನ್ಯ prev_scope(ರಚನೆ scope *o, ಪೂರ್ಣಾಂಕ is_ಅಭಿವ್ಯಕ್ತಿ)
{
    vla_leave(o->prev);

    ಆದರೆ (o->cl.s != o->prev->cl.s)
        ಖಂಡ_cleanup(o->prev);

    ಆದರೆ (debug_modes)
        tcc_debug_ಕೊನೆ_scope(o->lstk, !is_ಅಭಿವ್ಯಕ್ತಿ);

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
ಸ್ಥಿರ ಶೂನ್ಯ leave_scope(ರಚನೆ scope *o)
{
    ಆದರೆ (!o)
        ಹಿಂತಿರುಗಿ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ಸ್ಥಿರ ಶೂನ್ಯ new_scope_s(ರಚನೆ scope *o)
{
    o->lstk = local_ರಾಶಿ;
    ++local_scope;
}

ಸ್ಥಿರ ಶೂನ್ಯ prev_scope_s(ರಚನೆ scope *o)
{
    sym_ತೆಗೆ(&local_ರಾಶಿ, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ಸ್ಥಿರ ಶೂನ್ಯ lblock(ಪೂರ್ಣಾಂಕ *bsym, ಪೂರ್ಣಾಂಕ *csym)
{
    ರಚನೆ scope *lo = loop_scope, *co = cur_scope;
    ಪೂರ್ಣಾಂಕ *b = co->bsym, *c = co->csym;
    ಆದರೆ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    ಖಂಡ(0);
    co->bsym = b;
    ಆದರೆ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ಸ್ಥಿರ ಶೂನ್ಯ gexpr_decl(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ v = decl(VT_JMP);
    ಆದರೆ (v > 1 && tok != ';') {
        Sym *s = sym_ಕಂಡುಹಿಡಿ(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (v)
            skip(';');
        gexpr();
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ ಖಂಡ(ಪೂರ್ಣಾಂಕ flags)
{
    ಪೂರ್ಣಾಂಕ a, b, c, d, e, t;
    ರಚನೆ scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ಆದರೆ (TOK_HAS_ಮೌಲ್ಯ(t))
        ಹೋಗು ಅಭಿವ್ಯಕ್ತಿ;
    ಮುಂದಿನ();

    ಆದರೆ (debug_modes)
        tcc_tcov_check_ಸಾಲು (tcc_state, 0), tcc_tcov_ಖಂಡ_begin (tcc_state);

    ಆದರೆ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        ಖಂಡ(0);
        ಆದರೆ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            ಮುಂದಿನ();
            ಖಂಡ(0);
            gsym(d); /* patch else jmp */
        } ಇಲ್ಲದಿದ್ದರೆ {
            gsym(a);
        }
        prev_scope_s(&o);

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_WHILE) {
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

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == '{') {
        ಆದರೆ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ಆಗ (tok == TOK_LABEL) {
            ಮಾಡು {
                ಮುಂದಿನ();
                ಆದರೆ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ತಳ್ಳು(&local_label_ರಾಶಿ, tok, LABEL_DECLARED);
                ಮುಂದಿನ();
            } ಆಗ (tok == ',');
            skip(';');
        }

        ಆಗ (tok != '}') {
	    decl(VT_LOCAL);
            ಆದರೆ (tok != '}') {
                ಖಂಡ(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_ಅಭಿವ್ಯಕ್ತಿ);
        ಆದರೆ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ಆದರೆ (local_scope)
            ಮುಂದಿನ();
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!nocode_wanted)
            check_func_return();

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ಆದರೆ (tok != ';') {
            gexpr();
            ಆದರೆ (b) {
                gen_ನಿಯೋಜಿಸು_cast(&func_vt);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ಬೇರು_scope);
        ಆದರೆ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ಆದರೆ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ಆದರೆ (debug_modes)
	    tcc_tcov_ಖಂಡ_ಕೊನೆ (tcc_state, -1);
        ಸಂಕೇತ_OFF();

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_BREAK) {
        /* compute jump */
        ಆದರೆ (!cur_scope->bsym)
            tcc_error("cannot break");
        ಆದರೆ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ಇಲ್ಲದಿದ್ದರೆ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_CONTINUE) {
        /* compute jump */
        ಆದರೆ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ಆದರೆ (tok != ';') {
            /* c99 for-loop init decl? */
            ಆದರೆ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ಆದರೆ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ಆದರೆ (tok != ')') {
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

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_DO) {
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

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_SWITCH) {
        ರಚನೆ switch_t *sw;

        sw = tcc_mallocz(ಗಾತ್ರ *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ಆದರೆ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ಖಾಲಿ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ಆದರೆ (sw->nocode_wanted)
            ಹೋಗು skip_switch;
        case_ವಿಂಗಡಿಸು(sw);
        sw->bsym = ಖಾಲಿ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ಆದರೆ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ಇಲ್ಲದಿದ್ದರೆ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        ಕೊನೆ_switch();

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_CASE) {
        ರಚನೆ case_t *cr;
        ಆದರೆ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(ಗಾತ್ರ(ರಚನೆ case_t));
        dynarray_ಕೂಡಿಸು(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(ಅಭಿವ್ಯಕ್ತಿ_const64(), t);
        ಆದರೆ (tok == TOK_DOTS && gnu_ext) {
            ಮುಂದಿನ();
            cr->v2 = value64(ಅಭಿವ್ಯಕ್ತಿ_const64(), t);
            ಆದರೆ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ಆದರೆ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->ಸಾಲು = file->ಸಾಲು_ಅಂಕೆ;
        skip(':');
        ಹೋಗು ಖಂಡ_after_label;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_DEFAULT) {
        ಆದರೆ (!cur_switch)
            expect("switch");
        ಆದರೆ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        ಹೋಗು ಖಂಡ_after_label;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ಆದರೆ (tok == '*' && gnu_ext) {
            /* computed goto */
            ಮುಂದಿನ();
            gexpr();
            ಆದರೆ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_UIDENT) {
	    s = label_ಕಂಡುಹಿಡಿ(tok);
	    /* put forward definition if needed */
            ಆದರೆ (!s)
              s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok, LABEL_FORWARD);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ಆದರೆ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ಆದರೆ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_ಕ್ಷೇತ್ರ, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->ಮುಂದಿನ, SYM_ಕ್ಷೇತ್ರ, 0, 0);
                    pending_gotos->ಮುಂದಿನ = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ಇಲ್ಲದಿದ್ದರೆ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    ಮುಂದಿನ();

        } ಇಲ್ಲದಿದ್ದರೆ {
            expect("label identifier");
        }
        skip(';');

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    ಮುಂದಿನ();
            s = label_ಕಂಡುಹಿಡಿ(t);
            ಆದರೆ (s) {
                ಆದರೆ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ಖಾಲಿ));
                s->r = LABEL_DEFINED;
		ಆದರೆ (s->ಮುಂದಿನ) {
		    Sym *pcl; /* pending cleanup goto */
		    ಗಾಗಿ (pcl = s->ಮುಂದಿನ; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_ತೆಗೆ(&s->ಮುಂದಿನ, ಖಾಲಿ, 0);
		} ಇಲ್ಲದಿದ್ದರೆ
		  gsym(s->jnext);
            } ಇಲ್ಲದಿದ್ದರೆ {
                s = label_ತಳ್ಳು(&global_label_ರಾಶಿ, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    ಖಂಡ_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ಖಾಲಿ);

            ಆದರೆ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ಆದರೆ (tok != '}') {
                ಆದರೆ (0 == (flags & STMT_COMPOUND))
                    ಹೋಗು again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* expression case */
            ಆದರೆ (t != ';') {
                unget_tok(t);
    ಅಭಿವ್ಯಕ್ತಿ:
                ಆದರೆ (flags & STMT_ಅಭಿವ್ಯಕ್ತಿ) {
                    vpop();
                    gexpr();
                } ಇಲ್ಲದಿದ್ದರೆ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ಆದರೆ (debug_modes)
        tcc_tcov_check_ಸಾಲು (tcc_state, 0), tcc_tcov_ಖಂಡ_ಕೊನೆ (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ಸ್ಥಿರ ಶೂನ್ಯ skip_or_save_ಖಂಡ(TokenString **str)
{
    ಪೂರ್ಣಾಂಕ braces = tok == '{';
    ಪೂರ್ಣಾಂಕ level = 0;
    ಆದರೆ (str)
      *str = tok_str_alloc();

    ಆಗ (1) {
	ಪೂರ್ಣಾಂಕ t = tok;
        ಆದರೆ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             ನಿಲ್ಲಿಸು;
	ಆದರೆ (t == TOK_EOF) {
	     ಆದರೆ (str || level > 0)
	       tcc_error("unexpected end of file");
	     ಇಲ್ಲದಿದ್ದರೆ
	       ನಿಲ್ಲಿಸು;
	}
	ಆದರೆ (str)
	  tok_str_ಕೂಡಿಸು_tok(*str);
	ಮುಂದಿನ();
	ಆದರೆ (t == '{' || t == '(' || t == '[') {
	    level++;
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == '}' || t == ')' || t == ']') {
	    level--;
	    ಆದರೆ (level == 0 && braces && t == '}')
	      ನಿಲ್ಲಿಸು;
	}
    }
    ಆದರೆ (str)
	tok_str_ಕೂಡಿಸು(*str, TOK_EOF);
}

#ವ್ಯಾಖ್ಯಾನಿಸು ಅಭಿವ್ಯಕ್ತಿ_CONST 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಭಿವ್ಯಕ್ತಿ_ANY   2

ಸ್ಥಿರ ಶೂನ್ಯ parse_init_elem(ಪೂರ್ಣಾಂಕ ಅಭಿವ್ಯಕ್ತಿ_type)
{
    ಪೂರ್ಣಾಂಕ saved_global_ಅಭಿವ್ಯಕ್ತಿ;
    ಆಯ್ಕೆ(ಅಭಿವ್ಯಕ್ತಿ_type) {
    ಸ್ಥಿತಿ ಅಭಿವ್ಯಕ್ತಿ_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_ಅಭಿವ್ಯಕ್ತಿ = global_ಅಭಿವ್ಯಕ್ತಿ;
        global_ಅಭಿವ್ಯಕ್ತಿ = 1;
        ಅಭಿವ್ಯಕ್ತಿ_const1();
        global_ಅಭಿವ್ಯಕ್ತಿ = saved_global_ಅಭಿವ್ಯಕ್ತಿ;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ಆದರೆ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_ಮೊದಲ_ANOM))
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#ಆದರೆ_ಅಂತ್ಯ
           )
            tcc_error("initializer element is not constant");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ ಅಭಿವ್ಯಕ್ತಿ_ANY:
        ಅಭಿವ್ಯಕ್ತಿ_eq();
        ನಿಲ್ಲಿಸು;
    }
}

#ಆದರೆ 1
ಸ್ಥಿರ ಶೂನ್ಯ init_assert(init_params *p, ಪೂರ್ಣಾಂಕ ಸ್ಥಾನಾಂತರ)
{
    ಆದರೆ (p->sec ? !NODATA_WANTED && ಸ್ಥಾನಾಂತರ > p->sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ
               : !nocode_wanted && ಸ್ಥಾನಾಂತರ > p->local_ಸ್ಥಾನಾಂತರ)
        tcc_ಆಂತರಿಕ_error("initializer overflow");
}
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು init_assert(sec, ಸ್ಥಾನಾಂತರ)
#ಆದರೆ_ಅಂತ್ಯ

/* put zeros for variable based init */
ಸ್ಥಿರ ಶೂನ್ಯ init_putz(init_params *p, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    init_assert(p, c + ಗಾತ್ರ_2);
    ಆದರೆ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ಇಲ್ಲದಿದ್ದರೆ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(ಗಾತ್ರ_2);
#ಆದರೆ defined TCC_ಗುರಿ_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#ಆದರೆ_ಅಂತ್ಯ
        gfunc_call(3);
    }
}

#ವ್ಯಾಖ್ಯಾನಿಸು DIF_ಮೊದಲ     1
#ವ್ಯಾಖ್ಯಾನಿಸು DIF_ಗಾತ್ರ_ONLY 2
#ವ್ಯಾಖ್ಯಾನಿಸು DIF_HAVE_ELEM 4
#ವ್ಯಾಖ್ಯಾನಿಸು DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
ಸ್ಥಿರ ಶೂನ್ಯ decl_design_delrels(Section *sec, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ElfW_Rel *rel, *rel2, *rel_ಕೊನೆ;
    ಆದರೆ (!sec || !sec->reloc)
        ಹಿಂತಿರುಗಿ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->ದತ್ತಾಂಶ;
    rel_ಕೊನೆ = (ElfW_Rel*)(sec->reloc->ದತ್ತಾಂಶ + sec->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    ಆಗ (rel < rel_ಕೊನೆ) {
        ಆದರೆ (rel->r_ಸ್ಥಾನಾಂತರ >= c && rel->r_ಸ್ಥಾನಾಂತರ < c + ಗಾತ್ರ_2) {
            sec->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ -= ಗಾತ್ರ *rel;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (rel2 != rel)
                ಸ್ಮರಣೆ_ನಕಲು(rel2, rel, ಗಾತ್ರ *rel);
            ++rel2;
        }
        ++rel;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ decl_design_flex(init_params *p, Sym *ref, ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ)
{
    ಆದರೆ (ref == p->flex_array_ref) {
        ಆದರೆ (ಸೂಚ್ಯಂಕ >= ref->c)
            ref->c = ಸೂಚ್ಯಂಕ + 1;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ref->c < 0 && ಸೂಚ್ಯಂಕ >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ decl_designator(init_params *p, CType *type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c,
                           Sym **cur_ಕ್ಷೇತ್ರ, ಪೂರ್ಣಾಂಕ flags, ಪೂರ್ಣಾಂಕ al)
{
    Sym *s, *f;
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ, ಸೂಚ್ಯಂಕ_ಕೊನೆಯ, align, l, nb_elems, elem_ಗಾತ್ರ;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ corig = c;

    elem_ಗಾತ್ರ = 0;
    nb_elems = 1;

    ಆದರೆ (flags & DIF_HAVE_ELEM)
        ಹೋಗು no_designator;

    ಆದರೆ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, ಮುಂದಿನ();
        ಆದರೆ (tok == ':')
            ಹೋಗು struct_ಕ್ಷೇತ್ರ;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ಆಗ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ಆದರೆ (tok == '[') {
            ಆದರೆ (!(type->t & VT_ARRAY))
                expect("array type");
            ಮುಂದಿನ();
            ಸೂಚ್ಯಂಕ = ಸೂಚ್ಯಂಕ_ಕೊನೆಯ = ಅಭಿವ್ಯಕ್ತಿ_const();
            ಆದರೆ (tok == TOK_DOTS && gnu_ext) {
                ಮುಂದಿನ();
                ಸೂಚ್ಯಂಕ_ಕೊನೆಯ = ಅಭಿವ್ಯಕ್ತಿ_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, ಸೂಚ್ಯಂಕ_ಕೊನೆಯ);
            ಆದರೆ (ಸೂಚ್ಯಂಕ < 0 || ಸೂಚ್ಯಂಕ_ಕೊನೆಯ >= s->c || ಸೂಚ್ಯಂಕ_ಕೊನೆಯ < ಸೂಚ್ಯಂಕ)
	        tcc_error("index exceeds array bounds or range is empty");
            ಆದರೆ (cur_ಕ್ಷೇತ್ರ)
		(*cur_ಕ್ಷೇತ್ರ)->c = ಸೂಚ್ಯಂಕ_ಕೊನೆಯ;
            type = pointed_type(type);
            elem_ಗಾತ್ರ = type_ಗಾತ್ರ(type, &align);
            c += ಸೂಚ್ಯಂಕ * elem_ಗಾತ್ರ;
            nb_elems = ಸೂಚ್ಯಂಕ_ಕೊನೆಯ - ಸೂಚ್ಯಂಕ + 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪೂರ್ಣಾಂಕ cumofs;
            ಮುಂದಿನ();
            l = tok;
        struct_ಕ್ಷೇತ್ರ:
            ಮುಂದಿನ();
	    f = ಕಂಡುಹಿಡಿ_ಕ್ಷೇತ್ರ(type, l, &cumofs);
            ಆದರೆ (cur_ಕ್ಷೇತ್ರ)
                *cur_ಕ್ಷೇತ್ರ = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_ಕ್ಷೇತ್ರ = ಖಾಲಿ;
    }
    ಆದರೆ (!cur_ಕ್ಷೇತ್ರ) {
        ಆದರೆ (tok == '=') {
            ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!gnu_ext) {
	    expect("=");
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
    no_designator:
        ಆದರೆ (type->t & VT_ARRAY) {
	    ಸೂಚ್ಯಂಕ = (*cur_ಕ್ಷೇತ್ರ)->c;
            s = type->ref;
            decl_design_flex(p, s, ಸೂಚ್ಯಂಕ);
            ಆದರೆ (ಸೂಚ್ಯಂಕ >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_ಗಾತ್ರ = type_ಗಾತ್ರ(type, &align);
            c += ಸೂಚ್ಯಂಕ * elem_ಗಾತ್ರ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            f = *cur_ಕ್ಷೇತ್ರ;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ಆಗ (f && (f->v & SYM_ಮೊದಲ_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_ಕ್ಷೇತ್ರ = f = f->ಮುಂದಿನ;
            ಆದರೆ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ಆದರೆ (!elem_ಗಾತ್ರ) /* for structs */
        elem_ಗಾತ್ರ = type_ಗಾತ್ರ(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ಆದರೆ (!(flags & DIF_ಗಾತ್ರ_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_ಗಾತ್ರ * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_ಮೊದಲ);

    ಆದರೆ (!(flags & DIF_ಗಾತ್ರ_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        ಪೂರ್ಣಾಂಕ i;
        ಆದರೆ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_ಗಾತ್ರ;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ಆದರೆ (p->sec)
            vpush_ref(type, p->sec, c, elem_ಗಾತ್ರ);
        ಇಲ್ಲದಿದ್ದರೆ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        ಗಾಗಿ (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_ಗಾತ್ರ * i);
	}
        vpop();
    }

    c += nb_elems * elem_ಗಾತ್ರ;
    ಆದರೆ (c - corig > al)
      al = c - corig;
    ಹಿಂತಿರುಗಿ al;
}

ಸ್ಥಿರ ಶೂನ್ಯ write_ldouble(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *d, ಶೂನ್ಯ *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_CROSS_TEST
    ಆದರೆ (LDOUBLE_ಗಾತ್ರ >= 10) {
        ದ್ವಿಗುಣ b = *(ದೀರ್ಘ ದ್ವಿಗುಣ*)s;
        s = &b;
#ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (ಗಾತ್ರ (ದೀರ್ಘ ದ್ವಿಗುಣ) == 8 && LDOUBLE_ಗಾತ್ರ >= 10) {
#ಆದರೆ_ಅಂತ್ಯ
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        ಪೂರ್ಣಾಂಕ e = m >> 48;
        ಪೂರ್ಣಾಂಕ f = e >> 4 & 0x7FF;
        m <<= 11;
        ಆದರೆ (0 == f) {
            ಆದರೆ (0 == m)
                ಹೋಗು ಗಣ;
            ಗಾಗಿ (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ಆದರೆ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    ಗಣ:
    #ಆದರೆ (defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #ಅಥವಾಆದರೆ LDOUBLE_ಗಾತ್ರ == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ಆದರೆ_ಅಂತ್ಯ
        ;
    } ಇಲ್ಲದಿದ್ದರೆ {
    #ಆದರೆ LDOUBLE_ಗಾತ್ರ == 8
        /* long double -> double */
        ದ್ವಿಗುಣ b = *(ದೀರ್ಘ ದ್ವಿಗುಣ*)s;
        ಸ್ಮರಣೆ_ನಕಲು(d, &b, 8);
    #ಅಥವಾಆದರೆ (__i386__ || __x86_64__) && (defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64)
        /* extended -> extended */
        ಸ್ಮರಣೆ_ನಕಲು(d, s, 10);
    #ಅಥವಾಆದರೆ (__i386__ || __x86_64__) && (defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        ಪೂರ್ಣಾಂಕ e = *(uint16_t*)((ಅಕ್ಷರ*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ಅಥವಾಆದರೆ (__aarch64__ || __riscv) && (defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((ಅಕ್ಷರ*)s + 6);
        ಪೂರ್ಣಾಂಕ e = read16le((ಅಕ್ಷರ*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ಇಲ್ಲದಿದ್ದರೆ
        /* unknown */
        ಆದರೆ (ಗಾತ್ರ (ದೀರ್ಘ ದ್ವಿಗುಣ) == LDOUBLE_ಗಾತ್ರ)
            ಸ್ಮರಣೆ_ನಕಲು(d, s, LDOUBLE_ಗಾತ್ರ);
    #ಆದರೆ_ಅಂತ್ಯ
    }
}

/* store a value or an expression directly in global data or in local array */
ಸ್ಥಿರ ಶೂನ್ಯ init_putv(init_params *p, CType *type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c)
{
    ಪೂರ್ಣಾಂಕ bt;
    ಶೂನ್ಯ *ptr;
    CType dtype;
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, &align);
    ಆದರೆ (type->t & VT_BITFIELD)
        ಗಾತ್ರ_2 = (ಬಿಟ್_POS(type->t) + ಬಿಟ್_ಗಾತ್ರ(type->t) + 7) / 8;
    init_assert(p, c + ಗಾತ್ರ_2);

    ಆದರೆ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_ನಿಯೋಜಿಸು_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ಆದರೆ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_ಗಾತ್ರ == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_ಮೊದಲ_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ಆದರೆ (NODATA_WANTED) {
            vtop--;
            ಹಿಂತಿರುಗಿ;
        }

        ptr = sec->ದತ್ತಾಂಶ + c;
        val = vtop->c.i;

	ಆದರೆ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_ಮೊದಲ_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->ದತ್ತಾಂಶ + esym->st_ಮೌಲ್ಯ + (ಪೂರ್ಣಾಂಕ)vtop->c.i, ಗಾತ್ರ_2);
	    ಆದರೆ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ relofs = ssec->reloc->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
		ಆಗ (relofs >= ಗಾತ್ರ(*rel)) {
                    relofs -= ಗಾತ್ರ(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->ದತ್ತಾಂಶ + relofs);
		    ಆದರೆ (rel->r_ಸ್ಥಾನಾಂತರ >= esym->st_ಮೌಲ್ಯ + ಗಾತ್ರ_2)
		      ಮುಂದುವರಿ;
		    ಆದರೆ (rel->r_ಸ್ಥಾನಾಂತರ < esym->st_ಮೌಲ್ಯ)
		      ನಿಲ್ಲಿಸು;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_ಸ್ಥಾನಾಂತರ - esym->st_ಮೌಲ್ಯ,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ಆದರೆ PTR_ಗಾತ್ರ == 8
				   rel->r_addend
#ಇಲ್ಲದಿದ್ದರೆ
				   0
#ಆದರೆ_ಅಂತ್ಯ
				  );
		}
	    }
	} ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (type->t & VT_BITFIELD) {
                ಪೂರ್ಣಾಂಕ ಬಿಟ್_pos, ಬಿಟ್_ಗಾತ್ರ_2, ಬಿಟ್ಟುಗಳು, n;
                ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, v, m;
                ಬಿಟ್_pos = ಬಿಟ್_POS(vtop->type.t);
                ಬಿಟ್_ಗಾತ್ರ_2 = ಬಿಟ್_ಗಾತ್ರ(vtop->type.t);
                p = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ*)ptr + (ಬಿಟ್_pos >> 3);
                ಬಿಟ್_pos &= 7, ಬಿಟ್ಟುಗಳು = 0;
                ಆಗ (ಬಿಟ್_ಗಾತ್ರ_2) {
                    n = 8 - ಬಿಟ್_pos;
                    ಆದರೆ (n > ಬಿಟ್_ಗಾತ್ರ_2)
                        n = ಬಿಟ್_ಗಾತ್ರ_2;
                    v = val >> ಬಿಟ್ಟುಗಳು << ಬಿಟ್_pos;
                    m = ((1 << n) - 1) << ಬಿಟ್_pos;
                    *p = (*p & ~m) | (v & m);
                    ಬಿಟ್ಟುಗಳು += n, ಬಿಟ್_ಗಾತ್ರ_2 -= n, ಬಿಟ್_pos = 0, ++p;
                }
            } ಇಲ್ಲದಿದ್ದರೆ
            ಆಯ್ಕೆ(bt) {
	    ಸ್ಥಿತಿ VT_BOOL:
		*(ಅಕ್ಷರ *)ptr = val != 0;
                ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ VT_BYTE:
		*(ಅಕ್ಷರ *)ptr = val;
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ VT_SHORT:
                write16le(ptr, val);
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ VT_FLOAT:
                write32le(ptr, val);
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ VT_DOUBLE:
                write64le(ptr, val);
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		ನಿಲ್ಲಿಸು;

#ಆದರೆ PTR_ಗಾತ್ರ == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    ಸ್ಥಿತಿ VT_LLONG:
	    ಸ್ಥಿತಿ VT_PTR:
	        ಆದರೆ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_ದತ್ತಾಂಶ_PTR, val);
	        ಇಲ್ಲದಿದ್ದರೆ
	          write64le(ptr, val);
	        ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ VT_INT:
                write32le(ptr, val);
                ನಿಲ್ಲಿಸು;
#ಇಲ್ಲದಿದ್ದರೆ
	    ಸ್ಥಿತಿ VT_LLONG:
                write64le(ptr, val);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ VT_PTR:
            ಸ್ಥಿತಿ VT_INT:
	        ಆದರೆ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_ದತ್ತಾಂಶ_PTR);
	        write32le(ptr, val);
	        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
	    ಪೂರ್ವನಿಯೋಜಿತ:
                //tcc_internal_error("unexpected type");
                ನಿಲ್ಲಿಸು;
	    }
	}
        vtop--;
    } ಇಲ್ಲದಿದ್ದರೆ {
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
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer(init_params *p, CType *type, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ c, ಪೂರ್ಣಾಂಕ flags)
{
    ಪೂರ್ಣಾಂಕ len, n, no_oblock, i;
    ಪೂರ್ಣಾಂಕ size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ಆದರೆ (debug_modes && !(flags & DIF_ಗಾತ್ರ_ONLY) && !p->sec)
        tcc_debug_ಸಾಲು(tcc_state), tcc_tcov_check_ಸಾಲು (tcc_state, 1);

    ಆದರೆ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_ಗಾತ್ರ_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        ಪೂರ್ಣಾಂಕ ncw_prev = nocode_wanted;
        ಆದರೆ ((flags & DIF_ಗಾತ್ರ_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? ಅಭಿವ್ಯಕ್ತಿ_ANY : ಅಭಿವ್ಯಕ್ತಿ_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ಆದರೆ (type->t & VT_ARRAY) {
        no_oblock = 1;
        ಆದರೆ (((flags & DIF_ಮೊದಲ) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_ಗಾತ್ರ(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        ಆದರೆ ((tok == TOK_LSTR && 
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ಇಲ್ಲದಿದ್ದರೆ
             (t1->t & VT_BTYPE) == VT_INT
#ಆದರೆ_ಅಂತ್ಯ
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ಆದರೆ (size1 != (tok == TOK_STR ? 1 : ಗಾತ್ರ(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ಆಗ (tok == TOK_STR || tok == TOK_LSTR) {
                ಆದರೆ (initstr.ಗಾತ್ರ_2)
                  initstr.ಗಾತ್ರ_2 -= size1;
                ಆದರೆ (tok == TOK_STR)
                  len += tokc.str.ಗಾತ್ರ_2;
                ಇಲ್ಲದಿದ್ದರೆ
                  len += tokc.str.ಗಾತ್ರ_2 / ಗಾತ್ರ(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.ದತ್ತಾಂಶ, tokc.str.ಗಾತ್ರ_2);
                ಮುಂದಿನ();
            }
            ಆದರೆ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.ಗಾತ್ರ_2 = initstr.ಗಾತ್ರ_2;
                tokc.str.ದತ್ತಾಂಶ = initstr.ದತ್ತಾಂಶ;
                ಹೋಗು do_init_array;
            }

            decl_design_flex(p, s, len);
            ಆದರೆ (!(flags & DIF_ಗಾತ್ರ_ONLY)) {
                ಪೂರ್ಣಾಂಕ nb = n, ch;
                ಆದರೆ (len < nb)
                    nb = len;
                ಆದರೆ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ಆದರೆ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ಆದರೆ (!NODATA_WANTED)
                      ಸ್ಮರಣೆ_ನಕಲು(p->sec->ದತ್ತಾಂಶ + c, initstr.ದತ್ತಾಂಶ, nb);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಗಾಗಿ(i=0;i<n;i++) {
                        ಆದರೆ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ಆದರೆ (flags & DIF_CLEAR)
                            ನಿಲ್ಲಿಸು;
                          ಆದರೆ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            ನಿಲ್ಲಿಸು;
                          }
                          ch = 0;
                        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (size1 == 1)
                          ch = ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)initstr.ದತ್ತಾಂಶ)[i];
                        ಇಲ್ಲದಿದ್ದರೆ
                          ch = ((nwchar_t *)initstr.ದತ್ತಾಂಶ)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ಆದರೆ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ಆದರೆ (!(flags & (DIF_CLEAR | DIF_ಗಾತ್ರ_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ಆಗ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ಆದರೆ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ಆದರೆ (no_oblock && len >= n*size1)
		        ನಿಲ್ಲಿಸು;
		} ಇಲ್ಲದಿದ್ದರೆ {
		    ಆದರೆ (s->type.t == VT_UNION)
		        f = ಖಾಲಿ;
		    ಇಲ್ಲದಿದ್ದರೆ
		        f = f->ಮುಂದಿನ;
		    ಆದರೆ (no_oblock && f == ಖಾಲಿ)
		        ನಿಲ್ಲಿಸು;
		}

		ಆದರೆ (tok == '}')
		    ನಿಲ್ಲಿಸು;
		skip(',');
	    }
        }
        ಆದರೆ (!no_oblock)
            skip('}');

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        ಹೋಗು one_elem;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ಆದರೆ ((flags & DIF_ಮೊದಲ) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->ಮುಂದಿನ;
        n = s->c;
        size1 = 1;
	ಹೋಗು do_init_list;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '{') {
        ಆದರೆ (flags & DIF_HAVE_ELEM)
          skip(';');
        ಮುಂದಿನ();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ಇಲ್ಲದಿದ್ದರೆ one_elem: ಆದರೆ ((flags & DIF_ಗಾತ್ರ_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ಆದರೆ (flags & DIF_HAVE_ELEM)
            vpop();
        ಇಲ್ಲದಿದ್ದರೆ
            skip_or_save_ಖಂಡ(ಖಾಲಿ);

    } ಇಲ್ಲದಿದ್ದರೆ {
	ಆದರೆ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ಆದರೆ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? ಅಭಿವ್ಯಕ್ತಿ_ANY : ಅಭಿವ್ಯಕ್ತಿ_CONST);
	}
        ಆದರೆ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_ಗಾತ್ರ(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ಇಲ್ಲದಿದ್ದರೆ
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
ಸ್ಥಿರ ಶೂನ್ಯ decl_initializer_alloc(CType *type, AttributeDef *ad, ಪೂರ್ಣಾಂಕ r, 
                                   ಪೂರ್ಣಾಂಕ has_init, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ scope)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, align, addr;
    TokenString *init_str = ಖಾಲಿ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ saved_nocode_wanted = nocode_wanted;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಪೂರ್ಣಾಂಕ bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#ಆದರೆ_ಅಂತ್ಯ
    init_params p = {0};

    ಆದರೆ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_ಕಂಡುಹಿಡಿ(v);
        ಆದರೆ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ಆದರೆ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ಹಿಂತಿರುಗಿ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ಆದರೆ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= ದತ್ತಾಂಶ_ONLY_WANTED;

    flexible_array = ಖಾಲಿ;
    ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ಆದರೆ (ಗಾತ್ರ_2 < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ಆದರೆ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ಆದರೆ (IS_BT_ARRAY(type->t))
            type->ref = sym_ತಳ್ಳು(SYM_ಕ್ಷೇತ್ರ, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ಕ್ಷೇತ್ರ = type->ref->ಮುಂದಿನ;
        ಆದರೆ (ಕ್ಷೇತ್ರ) {
            ಆಗ (ಕ್ಷೇತ್ರ->ಮುಂದಿನ)
                ಕ್ಷೇತ್ರ = ಕ್ಷೇತ್ರ->ಮುಂದಿನ;
            ಆದರೆ (ಕ್ಷೇತ್ರ->type.t & VT_ARRAY && ಕ್ಷೇತ್ರ->type.ref->c < 0) {
                flexible_array = ಕ್ಷೇತ್ರ;
                p.flex_array_ref = ಕ್ಷೇತ್ರ->type.ref;
                ಗಾತ್ರ_2 = -1;
            }
        }
    }

    ಆದರೆ (ಗಾತ್ರ_2 < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ಆದರೆ (!has_init)
            ಹೋಗು err_ಗಾತ್ರ;
        ಆದರೆ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ಆಗ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_ಕೂಡಿಸು_tok(init_str);
                ಮುಂದಿನ();
            }
            tok_str_ಕೂಡಿಸು(init_str, TOK_EOF);
        } ಇಲ್ಲದಿದ್ದರೆ
            skip_or_save_ಖಂಡ(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        ಮುಂದಿನ();
        decl_initializer(&p, type, 0, DIF_ಮೊದಲ | DIF_ಗಾತ್ರ_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        ಮುಂದಿನ();

        /* if still unknown size, error */
        ಗಾತ್ರ_2 = type_ಗಾತ್ರ(type, &align);
        ಆದರೆ (ಗಾತ್ರ_2 < 0)
    err_ಗಾತ್ರ:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ಆದರೆ (flexible_array && flexible_array->type.ref->c > 0)
            ಗಾತ್ರ_2 += flexible_array->type.ref->c
                    * pointed_ಗಾತ್ರ(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ಆದರೆ (ad->a.aligned) {
	ಪೂರ್ಣಾಂಕ speca = 1 << (ad->a.aligned - 1);
        ಆದರೆ (speca > align)
            align = speca;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ad->a.packed) {
        align = 1;
    }

    ಆದರೆ (!v && NODATA_WANTED)
        ಗಾತ್ರ_2 = 0, align = 1;

    ಆದರೆ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ಖಾಲಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#ಆದರೆ_ಅಂತ್ಯ
        loc = (loc - ಗಾತ್ರ_2) & -align;
        addr = loc;
        p.local_ಸ್ಥಾನಾಂತರ = addr + ಗಾತ್ರ_2;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (v) {
            /* local variable */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_ASM
	    ಆದರೆ (ad->asm_label) {
		ಪೂರ್ಣಾಂಕ reg = asm_parse_regvar(ad->asm_label);
		ಆದರೆ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#ಆದರೆ_ಅಂತ್ಯ
            sym = sym_ತಳ್ಳು(v, type, r, addr);
	    ಆದರೆ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_ಕ್ಷೇತ್ರ | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->ಮುಂದಿನ = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* push local reference */
            vset(type, r, addr);
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        CType *tp = type;
        ಪೂರ್ಣಾಂಕ is_const;

        ಆಗ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ಆದರೆ (!sec) {
            ಆದರೆ (type->t & VT_TLS) {
                sec = ಕಂಡುಹಿಡಿ_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_const) {
		sec = rodata_section;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (has_init) {
		sec = ದತ್ತಾಂಶ_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tcc_state->nocommon)
                sec = bss_section;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ಆದರೆ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ಆದರೆ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (bcheck)
            ಗಾತ್ರ_2 = ಗಾತ್ರ_2 + 1; /* add padding */
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (sec) {
	    addr = section_ಕೂಡಿಸು(sec, ಗಾತ್ರ_2, align);
        } ಇಲ್ಲದಿದ್ದರೆ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ಆದರೆ (v) {
            ಆದರೆ (!sym) {
                sym = sym_ತಳ್ಳು(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ಖಾಲಿ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, ಗಾತ್ರ_2);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* push global reference */
            vpush_ref(type, sec, addr, ಗಾತ್ರ_2);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ಆದರೆ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, R_ದತ್ತಾಂಶ_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_ಕೂಡಿಸು(bounds_section, 2 * ಗಾತ್ರ(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = ಗಾತ್ರ_2 - 1;
        }
#ಆದರೆ_ಅಂತ್ಯ
    }

    ಆದರೆ (type->t & VT_VLA) {
        ಪೂರ್ಣಾಂಕ a;

        ಆದರೆ (has_init)
            tcc_error("variable length array cannot be initialized");

        ಆದರೆ (NODATA_WANTED)
            ಹೋಗು no_alloc;

        /* save before-VLA stack pointer if needed */
        ಆದರೆ (cur_scope->vla.ಅಂಕೆ == 0) {
            ಆದರೆ (cur_scope->prev && cur_scope->prev->vla.ಅಂಕೆ) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } ಇಲ್ಲದಿದ್ದರೆ {
                gen_vla_sp_save(loc -= PTR_ಗಾತ್ರ);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_ಗಾತ್ರ(type, &a);
        gen_vla_alloc(type, a);
#ಆದರೆ defined TCC_ಗುರಿ_PE && defined TCC_ಗುರಿ_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_ಫಲಿತಾಂಶ(addr), addr = (loc -= PTR_ಗಾತ್ರ);
#ಆದರೆ_ಅಂತ್ಯ
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.ಅಂಕೆ++;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_ಮೊದಲ);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ಆದರೆ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ಆದರೆ (init_str) {
        ಕೊನೆ_macro();
        ಮುಂದಿನ();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ಸ್ಥಿರ ಶೂನ್ಯ func_vla_arg_ಸಂಕೇತ(Sym *arg)
{
    ಪೂರ್ಣಾಂಕ align;
    TokenString *vla_array_tok = ಖಾಲಿ;

    ಆದರೆ (arg->type.ref)
        func_vla_arg_ಸಂಕೇತ(arg->type.ref);

    ಆದರೆ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_ಗಾತ್ರ(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	ಮುಂದಿನ();
	gexpr();
	ಕೊನೆ_macro();
	ಮುಂದಿನ();
	vpush_type_ಗಾತ್ರ(&arg->type.ref->type, &align);
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

    ಗಾಗಿ (arg = sym->type.ref->ಮುಂದಿನ; arg; arg = arg->ಮುಂದಿನ)
        ಆದರೆ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_ಸಂಕೇತ(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_ಗಣ_param(Sym *s, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ byref)
{
    s = sym_ಕಂಡುಹಿಡಿ(s->v);
    ಆದರೆ (!s) /* unnamed parameters, not enabled */
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    s->c = c;
    ಆದರೆ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ಹಿಂತಿರುಗಿ s;
}

/* push parameters (and their types), last first */
ಸ್ಥಿರ ಶೂನ್ಯ sym_ತಳ್ಳು_params(Sym *ref)
{
    Sym *s = ref;
    ಆಗ (s->ಮುಂದಿನ)
        s = s->ಮುಂದಿನ;
    ಆಗ (s != ref) {
        ಆದರೆ ((s->v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM)
            sym_copy(s, &local_ರಾಶಿ);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ಸ್ಥಿರ ಶೂನ್ಯ gen_function(Sym *sym)
{
    ರಚನೆ scope f = { 0 };

    cur_scope = ಬೇರು_scope = &f;
    nocode_wanted = 0;

    ind = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    ಆದರೆ (sym->a.aligned) {
	ಗಾತ್ರ_t newoff = section_ಕೂಡಿಸು(cur_ಪಠ್ಯ_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ಖಾಲಿ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_ಪಠ್ಯ_section, ind, 0);

    ಆದರೆ (sym->type.ref->f.func_ctor)
        ಕೂಡಿಸು_array (tcc_state, ".init_array", sym->c);
    ಆದರೆ (sym->type.ref->f.func_dtor)
        ಕೂಡಿಸು_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ರಾಶಿ, SYM_ಕ್ಷೇತ್ರ, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ತಳ್ಳು_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_ತಾತ್ಕಾಲಿಕ_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    ಖಂಡ(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_ಕೊನೆ_scope(ಖಾಲಿ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_ಗಾತ್ರ = ind - func_ind;
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;

    sym_ತೆಗೆ(&local_ರಾಶಿ, ಖಾಲಿ, 0);
    label_ತೆಗೆ(&global_label_ರಾಶಿ, ಖಾಲಿ, 0);
    sym_ತೆಗೆ(&all_cleanups, ಖಾಲಿ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_ಪಠ್ಯ_section = ಖಾಲಿ;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = ದತ್ತಾಂಶ_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    ಮುಂದಿನ();
}

ಸ್ಥಿರ ಶೂನ್ಯ gen_inline_functions(TCCState *s)
{
    Sym *sym;
    ಪೂರ್ಣಾಂಕ inline_generated, i;
    ರಚನೆ InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    ಮಾಡು {
        inline_generated = 0;
        ಗಾಗಿ (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ಆದರೆ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ಖಾಲಿ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                ಮುಂದಿನ();
                cur_ಪಠ್ಯ_section = ಪಠ್ಯ_section;
                gen_function(sym);
                ಕೊನೆ_macro();

                inline_generated = 1;
            }
        }
    } ಆಗ (inline_generated);
    tcc_close();
}

ಸ್ಥಿರ ಶೂನ್ಯ free_inline_functions(TCCState *s)
{
    ಪೂರ್ಣಾಂಕ i;
    /* free tokens of unused inline functions */
    ಗಾಗಿ (i = 0; i < s->nb_inline_fns; ++i) {
        ರಚನೆ InlineFunc *fn = s->inline_fns[i];
        ಆದರೆ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ಸ್ಥಿರ ಶೂನ್ಯ do_Static_assert(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ c;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ;

    ಮುಂದಿನ();
    skip('(');
    c = ಅಭಿವ್ಯಕ್ತಿ_const();
    ಸಂದೇಶ = "_Static_assert fail";
    ಆದರೆ (tok == ',') {
        ಮುಂದಿನ();
        ಸಂದೇಶ = parse_mult_str("string constant")->ದತ್ತಾಂಶ;
    }
    skip(')');
    ಆದರೆ (c == 0)
        tcc_error("%s", ಸಂದೇಶ);
    skip(';');
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ಸ್ಥಿರ ಶೂನ್ಯ pe_check_linkage(CType *type, AttributeDef *ad)
{
    ಆದರೆ (!ad->a.dllimport && !ad->a.dllexport)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ಆದರೆ (type->t & VT_TYPEDEF) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ad->a.dllimport) {
        ಆದರೆ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ಇಲ್ಲದಿದ್ದರೆ
            type->t |= VT_EXTERN;
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ decl(ಪೂರ್ಣಾಂಕ l)
{
    ಪೂರ್ಣಾಂಕ v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ಆಗ (1) {

        oldint = 0;
        ಆದರೆ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ಆದರೆ (l == VT_JMP)
                ಹಿಂತಿರುಗಿ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ಆದರೆ (tok == ';' && l != VT_CMP) {
                ಮುಂದಿನ();
                ಮುಂದುವರಿ;
            }
            ಆದರೆ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ಮುಂದುವರಿ;
            }
            ಆದರೆ (l != VT_CONST)
                ನಿಲ್ಲಿಸು;
            ಆದರೆ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ಮುಂದುವರಿ;
            }
            ಆದರೆ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (tok != TOK_EOF)
                    expect("declaration");
                ನಿಲ್ಲಿಸು;
            }
        }

        ಆದರೆ (tok == ';') {
            ಆದರೆ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_ಮೊದಲ_ANOM)
                ; /* struct decl with named tag */
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (IS_ENUM(btype.t))
                ; /* enum decl */
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_warning("useless type defines no instances");
            ಆದರೆ (l == VT_JMP)
                ಹಿಂತಿರುಗಿ 1;
            ಮುಂದಿನ();
            ಮುಂದುವರಿ;
        }

        ಆಗ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_ನೇರ | TYPE_PARAM : TYPE_ನೇರ);
            /*ptype("decl", &type, v);*/
            ಆದರೆ ((type.t & VT_BTYPE) == VT_FUNC) {
                ಆದರೆ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ಆದರೆ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ಆದರೆ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ಆದರೆ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ಇಲ್ಲದಿದ್ದರೆ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (oldint) {
                tcc_warning("type defaults to int");
            }

            ಆದರೆ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ಆದರೆ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ಆದರೆ (tok == '{')
                    expect(";");
            #ಆದರೆ_ಅಂತ್ಯ
            }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            pe_check_linkage(&type, &ad);
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ (tok == '{') {
                ಆದರೆ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ಆದರೆ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                ವಿಲೀನ_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                ಗಾಗಿ (sa = sym->type.ref; (sa = sa->ಮುಂದಿನ) != ಖಾಲಿ;) {
                    ಆದರೆ (!(sa->v & ~SYM_ಕ್ಷೇತ್ರ))
                        expect("identifier");
                    ಆದರೆ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ಆದರೆ (sym->type.t & VT_INLINE) {
                    ರಚನೆ InlineFunc *fn;
                    fn = tcc_malloc(ಗಾತ್ರ *fn + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_ಕೂಡಿಸು(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_ಖಂಡ(&fn->func_str);
                } ಇಲ್ಲದಿದ್ದರೆ {
                    /* compute text section */
                    cur_ಪಠ್ಯ_section = ಪಠ್ಯ_section;
                    ಆದರೆ (ad.section) {
                        cur_ಪಠ್ಯ_section = ad.section;
                        ಆದರೆ (ad.new_section)
                            ad.section->sh_flags = ಪಠ್ಯ_section->sh_flags;
                    }
                    gen_function(sym);
                }
                ನಿಲ್ಲಿಸು;
            } ಇಲ್ಲದಿದ್ದರೆ {
                has_init = 0;
		ಆದರೆ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    ಗಾಗಿ (sym = func_vt.ref->ಮುಂದಿನ; sym; sym = sym->ಮುಂದಿನ)
			ಆದರೆ ((sym->v & ~SYM_ಕ್ಷೇತ್ರ) == v)
			    ಹೋಗು ಸಿಕ್ಕಿತು;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ಖಾಲಿ));
                ಸಿಕ್ಕಿತು:
		    ಆದರೆ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ಖಾಲಿ));
		    ಆದರೆ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ಖಾಲಿ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_ಕಂಡುಹಿಡಿ(v);
                    ಆದರೆ (sym && sym->sym_scope == local_scope) {
                        ಆದರೆ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ಖಾಲಿ));
                        sym->type = type;
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        sym = sym_ತಳ್ಳು(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ಆದರೆ ((type.t & VT_BTYPE) == VT_FUNC)
                      ವಿಲೀನ_funcattr(&sym->type.ref->f, &ad.f);
                    ಆದರೆ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ಇಲ್ಲದಿದ್ದರೆ {
                    r = 0;
                    ಆದರೆ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        ವಿಲೀನ_funcattr(&type.ref->f, &ad.f);
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ಆದರೆ (tok == '=')
                        has_init = 1;

                    ಆದರೆ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ಆದರೆ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ಇಲ್ಲದಿದ್ದರೆ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ಆದರೆ (has_init)
                            ಮುಂದಿನ();
                        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ಆದರೆ (ad.alias_ಗುರಿ && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_ಕಂಡುಹಿಡಿ(ad.alias_ಗುರಿ));
                        ಆದರೆ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_ಕಂಡುಹಿಡಿ(v), esym->st_shndx,
                                        esym->st_ಮೌಲ್ಯ, esym->st_ಗಾತ್ರ, 1);
                    }
                }
                ಆದರೆ (tok != ',') {
                    ಆದರೆ (l == VT_JMP)
                        ಹಿಂತಿರುಗಿ has_init ? v : 1;
                    skip(';');
                    ನಿಲ್ಲಿಸು;
                }
                ಮುಂದಿನ();
            }
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* ------------------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು gjmp_addr
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು gjmp
/* ------------------------------------------------------------------------- */
