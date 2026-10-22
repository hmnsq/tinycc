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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_ਅੰਕੜੇ ਪੂਰਨ rsym, anon_sym, ind, loc;

ST_ਅੰਕੜੇ Sym *global_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *local_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *define_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *global_label_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *local_label_ਢੇਰ;

ਸਥਿਰ Sym *sym_free_ਪਹਿਲਾ;
ਸਥਿਰ ਖਾਲੀ **sym_pools;
ਸਥਿਰ ਪੂਰਨ nb_sym_pools;

ਸਥਿਰ Sym *all_cleanups, *pending_gotos;
ਸਥਿਰ ਪੂਰਨ local_scope;
ST_ਅੰਕੜੇ ਅੱਖਰ debug_modes;

ST_ਅੰਕੜੇ SValue *vtop;
ਸਥਿਰ SValue _vstack[1 + VSTACK_ਮਾਪ];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ vstack (_vstack + 1)

ST_ਅੰਕੜੇ ਪੂਰਨ nocode_wanted; /* no code generation wanted */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅੰਕੜੇ_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੋਡ_OFF_ਦੋਆਧਾਰੀ_ਅੰਕ 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੋਡ_OFF() ਜੇ(!nocode_wanted)(nocode_wanted |= ਕੋਡ_OFF_ਦੋਆਧਾਰੀ_ਅੰਕ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੋਡ_ON() (nocode_wanted &= ~ਕੋਡ_OFF_ਦੋਆਧਾਰੀ_ਅੰਕ)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOEVAL_ਨਕਾਬ 0x0000FFFF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOEVAL_WANTED (nocode_wanted & NOEVAL_ਨਕਾਬ)

/* no code output when parsing constant expressions */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONST_WANTED_ਦੋਆਧਾਰੀ_ਅੰਕ  0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONST_WANTED_ਨਕਾਬ 0x0FFF0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONST_WANTED  (nocode_wanted & CONST_WANTED_ਨਕਾਬ)

ST_ਅੰਕੜੇ ਪੂਰਨ global_ਵਿਅੰਜਕ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ਅੰਕੜੇ CType func_vt; /* current function return type (used by return instruction) */
ST_ਅੰਕੜੇ ਪੂਰਨ func_var; /* true if current function is variadic (used by return instruction) */
ST_ਅੰਕੜੇ ਪੂਰਨ func_vc; /* stack address for implicit struct return storage */
ST_ਅੰਕੜੇ ਪੂਰਨ func_ind; /* function start address */
ਸਥਿਰ ਪੂਰਨ func_old;
ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ *funcname;
ST_ਅੰਕੜੇ CType int_type, func_old_type, char_type, char_ਸੂਚਕ_type;
ਸਥਿਰ CString initstr;

#ਜੇ PTR_ਮਾਪ == 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ਮਾਪ_T (VT_INT | VT_UNSIGNED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_PTRDIFF_T VT_INT
#ਜਾਂਜੇ LONG_ਮਾਪ == 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ਮਾਪ_T (VT_LLONG | VT_UNSIGNED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_PTRDIFF_T VT_LLONG
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ਮਾਪ_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਬਣਤਰ switch_t {
    ਬਣਤਰ case_t {
        int64_t v1, v2;
        ਪੂਰਨ ind, ਸਤਰ;
    } **p; ਪੂਰਨ n; /* list of case ranges */
    ਪੂਰਨ def_sym; /* default symbol */
    ਪੂਰਨ nocode_wanted;
    ਪੂਰਨ *bsym;
    ਬਣਤਰ scope *scope;
    ਬਣਤਰ switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ਆਰਜ਼ੀ_LOCAL_VARIABLE_ਸੰਖਿਆ 8
/*list of temporary local variables on the stack in current function. */
ਸਥਿਰ ਬਣਤਰ ਆਰਜ਼ੀ_local_variable {
	ਪੂਰਨ location; //offset on stack. Svalue.c.i
	ਛੋਟਾ ਮਾਪ;
	ਛੋਟਾ align;
} arr_ਆਰਜ਼ੀ_local_vars[MAX_ਆਰਜ਼ੀ_LOCAL_VARIABLE_ਸੰਖਿਆ];
ਸਥਿਰ ਪੂਰਨ nb_ਆਰਜ਼ੀ_local_vars;

ਸਥਿਰ ਬਣਤਰ scope {
    ਬਣਤਰ scope *prev;
    ਬਣਤਰ { ਪੂਰਨ loc, locorig, ਅੰਕ; } vla;
    ਬਣਤਰ { Sym *s; ਪੂਰਨ n; } cl;
    ਪੂਰਨ *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ਜੜ੍ਹ_scope;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    Section *sec;
    ਪੂਰਨ local_ਵਿੱਥ;
    Sym *flex_array_ref;
} init_params;

#ਜੇ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ precedence_parser
ਸਥਿਰ ਖਾਲੀ init_prec(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ ਖੰਡ(ਪੂਰਨ flags);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STMT_ਵਿਅੰਜਕ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STMT_COMPOUND 2

ਸਥਿਰ ਖਾਲੀ gen_cast(CType *type);
ਸਥਿਰ ਖਾਲੀ gen_cast_s(ਪੂਰਨ t);
ਸਥਿਰ ਸਤਰਅੰਦਰ CType *pointed_type(CType *type);
ਸਥਿਰ ਖਾਲੀ check_restrict_type(CType *type);
ਸਥਿਰ ਪੂਰਨ type_qualifiers(CType *type);
ਸਥਿਰ ਖਾਲੀ parse_btype_qualify(CType *type, ਪੂਰਨ qualifiers);
ਸਥਿਰ ਪੂਰਨ is_compatible_types(CType *type1, CType *type2);
ਸਥਿਰ ਪੂਰਨ parse_btype(CType *type, AttributeDef *ad, ਪੂਰਨ ignore_label);
ਸਥਿਰ CType *type_decl(CType *type, AttributeDef *ad, ਪੂਰਨ *v, ਪੂਰਨ td);
ਸਥਿਰ ਖਾਲੀ parse_ਵਿਅੰਜਕ_type(CType *type);
ਸਥਿਰ ਖਾਲੀ init_putv(init_params *p, CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c);
ਸਥਿਰ ਖਾਲੀ decl_initializer(init_params *p, CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c, ਪੂਰਨ flags);
ਸਥਿਰ ਖਾਲੀ decl_initializer_alloc(CType *type, AttributeDef *ad, ਪੂਰਨ r, ਪੂਰਨ has_init, ਪੂਰਨ v, ਪੂਰਨ scope);
ਸਥਿਰ ਪੂਰਨ decl(ਪੂਰਨ l);
ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_eq(ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ vpush_type_ਮਾਪ(CType *type, ਪੂਰਨ *a);
ਸਥਿਰ ਪੂਰਨ is_compatible_unqualified_types(CType *type1, CType *type2);
ਸਥਿਰ ਸਤਰਅੰਦਰ int64_t ਵਿਅੰਜਕ_const64(ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ vpush64(ਪੂਰਨ ty, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v);
ਸਥਿਰ ਖਾਲੀ vpush(CType *type);
ਸਥਿਰ ਪੂਰਨ gvtst(ਪੂਰਨ inv, ਪੂਰਨ t);
ਸਥਿਰ ਖਾਲੀ gen_inline_functions(TCCState *s);
ਸਥਿਰ ਖਾਲੀ free_inline_functions(TCCState *s);
ਸਥਿਰ ਖਾਲੀ skip_or_save_ਖੰਡ(TokenString **str);
ਸਥਿਰ ਖਾਲੀ gv_dup(ਖਾਲੀ);
ਸਥਿਰ ਪੂਰਨ get_ਆਰਜ਼ੀ_local_var(ਪੂਰਨ ਮਾਪ,ਪੂਰਨ align,ਪੂਰਨ *r2);
ਸਥਿਰ ਖਾਲੀ cast_error(CType *st, CType *dt);
ਸਥਿਰ ਖਾਲੀ ਸਿਰਾ_switch(ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ do_Static_assert(ਖਾਲੀ);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC ਖਾਲੀ gsym(ਪੂਰਨ t)
{
  ਜੇ (t) {
    gsym_addr(t, ind);
    ਕੋਡ_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ਸਥਿਰ ਪੂਰਨ gind()
{
  ਪੂਰਨ t = ind;
  ਕੋਡ_ON();
  ਜੇ (debug_modes)
    tcc_tcov_ਖੰਡ_begin(tcc_state);
  ਵਾਪਸ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ਸਥਿਰ ਖਾਲੀ gjmp_addr_acs(ਪੂਰਨ t)
{
  gjmp_addr(t);
  ਕੋਡ_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ਸਥਿਰ ਪੂਰਨ gjmp_acs(ਪੂਰਨ t)
{
  t = gjmp(t);
  ਕੋਡ_OFF();
  ਵਾਪਸ t;
}

/* These are #undef'd at the end of this file */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gjmp_addr gjmp_addr_acs
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN ਪੂਰਨ is_float(ਪੂਰਨ t)
{
    ਪੂਰਨ bt = t & VT_BTYPE;
    ਵਾਪਸ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ is_integer_btype(ਪੂਰਨ bt)
{
    ਵਾਪਸ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ਸਥਿਰ ਪੂਰਨ btype_ਮਾਪ(ਪੂਰਨ bt)
{
    ਵਾਪਸ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_ਮਾਪ : 0;
}

/* returns function return register from type */
ਸਥਿਰ ਪੂਰਨ R_RET(ਪੂਰਨ t)
{
    ਜੇ (!is_float(t))
        ਵਾਪਸ REG_IRET;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਜੇ ((t & VT_BTYPE) == VT_LDOUBLE)
        ਵਾਪਸ TREG_ST0;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਜੇ ((t & VT_BTYPE) == VT_LDOUBLE)
        ਵਾਪਸ REG_IRET;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ REG_FRET;
}

/* returns 2nd function return register, if any */
ਸਥਿਰ ਪੂਰਨ R2_RET(ਪੂਰਨ t)
{
    t &= VT_BTYPE;
#ਜੇ PTR_ਮਾਪ == 4
    ਜੇ (t == VT_LLONG)
        ਵਾਪਸ REG_IRE2;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਜੇ (t == VT_QLONG)
        ਵਾਪਸ REG_IRE2;
    ਜੇ (t == VT_QFLOAT)
        ਵਾਪਸ REG_FRE2;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਜੇ (t == VT_LDOUBLE)
        ਵਾਪਸ REG_IRE2;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ VT_CONST;
}

/* returns true for two-word types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_TWO_ਸ਼ਬਦ(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ਸਥਿਰ ਖਾਲੀ PUT_R_RET(SValue *sv, ਪੂਰਨ t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ਸਥਿਰ ਪੂਰਨ RC_RET(ਪੂਰਨ t)
{
    ਵਾਪਸ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ਸਥਿਰ ਪੂਰਨ RC_TYPE(ਪੂਰਨ t)
{
    ਜੇ (!is_float(t))
        ਵਾਪਸ RC_INT;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਜੇ ((t & VT_BTYPE) == VT_LDOUBLE)
        ਵਾਪਸ RC_ST0;
    ਜੇ ((t & VT_BTYPE) == VT_QFLOAT)
        ਵਾਪਸ RC_FRET;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਜੇ ((t & VT_BTYPE) == VT_LDOUBLE)
        ਵਾਪਸ RC_INT;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ਸਥਿਰ ਪੂਰਨ RC2_TYPE(ਪੂਰਨ t, ਪੂਰਨ rc)
{
    ਜੇ (!USING_TWO_ਸ਼ਬਦ(t))
        ਵਾਪਸ 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_IRE2
    ਜੇ (rc == RC_IRET)
        ਵਾਪਸ RC_IRE2;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_FRE2
    ਜੇ (rc == RC_FRET)
        ਵਾਪਸ RC_FRE2;
#ਜੇ_ਅੰਤ
    ਜੇ (rc & RC_FLOAT)
        ਵਾਪਸ RC_FLOAT;
    ਵਾਪਸ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC ਪੂਰਨ ieee_finite(ਦੁੱਗਣਾ d)
{
    ਪੂਰਨ p[4];
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(p, &d, ਆਕਾਰ(ਦੁੱਗਣਾ));
    ਵਾਪਸ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC ਖਾਲੀ test_lvalue(ਖਾਲੀ)
{
    ਜੇ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC ਖਾਲੀ check_vstack(ਖਾਲੀ)
{
    ਜੇ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (ਪੂਰਨ)(vtop - vstack + 1));
}

#ਜੇ 0
/* dump 'b' vstack entries starting with 'a'  */
ਖਾਲੀ pv (ਅਚਲ ਅੱਖਰ *lbl, ਪੂਰਨ a, ਪੂਰਨ b)
{
    ਪੂਰਨ i;
    ਲਈ (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        ਲਿਖੋ("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (ਪੂਰਨ)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ psyms(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, Sym *s, Sym *ਆਖਰੀ)
{
    ਲਿਖੋ("%-8s scope         v        c        r   type.t\n", ਸੁਨੇਹਾ);
    ਜਦੋਂ (s && s != ਆਖਰੀ) {
        ਲਿਖੋ("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ਸਥਿਰ ਖਾਲੀ type_ਮੰਜ਼ਿਲ_str(ਅੱਖਰ *buf, ਪੂਰਨ buf_ਮਾਪ, CType *type, ਅਚਲ ਅੱਖਰ *varstr);

/* print type */
ਸਥਿਰ ਖਾਲੀ ptype(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, CType *type, ਪੂਰਨ v)
{
    ਅੱਖਰ buf[500];
    type_ਮੰਜ਼ਿਲ_str(buf, ਆਕਾਰ(buf), type,
        (v & ~SYM_ਖੇਤਰ) ? get_tok_str(v, ਨਿਰਾ) : ਨਿਰਾ);
    ਲਿਖੋ("%s : %s;\n", ਸੁਨੇਹਾ, buf);
}
#ਜੇ_ਅੰਤ

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC ਖਾਲੀ tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, ਆਕਾਰ *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ਜੇ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_ਸੂਚਕ_type = char_type;
    mk_ਸੂਚਕ(&char_ਸੂਚਕ_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ precedence_parser
    init_prec();
#ਜੇ_ਅੰਤ
    cstr_new(&initstr);
}

ST_FUNC ਪੂਰਨ tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_ਪਹਿਲਾ_ANOM;
    nocode_wanted = ਅੰਕੜੇ_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_ਵਿਅੰਜਕ = 0;

    tcc_debug_ਸ਼ੁਰੂ(s1);
    tcc_tcov_ਸ਼ੁਰੂ (s1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    arm_init(s1);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
    ਲਿਖੋ("%s: **** new file\n", file->filename);
#ਜੇ_ਅੰਤ
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_ਅੰਕ | PARSE_FLAG_TOK_STR;
    ਅਗਲਾ();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ਜੇ TCC_EH_ਚੌਖਟਾ
    tcc_eh_ਚੌਖਟਾ_ਸਿਰਾ(s1);
#ਜੇ_ਅੰਤ
    tcc_debug_ਸਿਰਾ(s1);
    tcc_tcov_ਸਿਰਾ(s1);
    ਵਾਪਸ 0;
}

ST_FUNC ਖਾਲੀ tccgen_ਅੰਤ(TCCState *s1)
{
    tcc_debug_ਸਿਰਾ(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_ਕੱਢੋ(&global_ਢੇਰ, ਨਿਰਾ, 0);
    sym_ਕੱਢੋ(&local_ਢੇਰ, ਨਿਰਾ, 0);
    /* free preprocessor macros */
    free_ਨਿਰਧਾਰਤ_ਕਰਦਾ(ਨਿਰਾ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_ਅੰਕੜੇ, &nb_stk_ਅੰਕੜੇ);
    ਜਦੋਂ (cur_switch)
        ਸਿਰਾ_switch();
    local_scope = 0;
    loop_scope = ਨਿਰਾ;
    all_cleanups = ਨਿਰਾ;
    pending_gotos = ਨਿਰਾ;
    nb_ਆਰਜ਼ੀ_local_vars = 0;
    global_label_ਢੇਰ = ਨਿਰਾ;
    local_label_ਢੇਰ = ਨਿਰਾ;
    cur_ਪਾਠ_section = ਨਿਰਾ;
    sym_free_ਪਹਿਲਾ = ਨਿਰਾ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ਜੇ (!s || !s->c)
    ਵਾਪਸ ਨਿਰਾ;
  ਵਾਪਸ &((ElfSym *)symtab_section->ਅੰਕੜੇ)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC ਖਾਲੀ update_storage(Sym *sym)
{
    ElfSym *esym;
    ਪੂਰਨ sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ਜੇ (!esym)
        ਵਾਪਸ;

    ਜੇ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ਜੇ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ਨਹੀਂਤਾਂ ਜੇ (sym->a.weak)
        sym_bind = STB_WEAK;
    ਨਹੀਂਤਾਂ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ਜੇ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ਜੇ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#ਜੇ_ਅੰਤ

#ਜੇ 0
    ਲਿਖੋ("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ਨਿਰਾ),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#ਜੇ_ਅੰਤ
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC ਖਾਲੀ put_extern_sym2(Sym *sym, ਪੂਰਨ sh_ਅੰਕ,
                            addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ,
                            ਪੂਰਨ can_ਜੋੜੋ_underscore)
{
    ਪੂਰਨ sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ਅਚਲ ਅੱਖਰ *name;
    ਅੱਖਰ buf1[256];

    ਜੇ (!sym->c) {
        name = get_tok_str(sym->v, ਨਿਰਾ);
        t = sym->type.t;
        ਜੇ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ਨਹੀਂਤਾਂ ਜੇ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ਜੇ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ਨਹੀਂਤਾਂ ਜੇ (t & VT_TLS) {
            sym_type = STT_TLS;
        } ਨਹੀਂਤਾਂ {
            sym_type = STT_OBJECT;
        }
        ਜੇ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ਨਹੀਂਤਾਂ
            sym_bind = STB_GLOBAL;
        other = 0;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        ਜੇ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ਜੇ (ref->a.nodecorate) {
                can_ਜੋੜੋ_underscore = 0;
            }
            ਜੇ (ref->f.func_call == FUNC_STDCALL && can_ਜੋੜੋ_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_ਦਲੀਲਾਂ * PTR_ਮਾਪ);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_ਜੋੜੋ_underscore = 0;
            }
        }
#ਜੇ_ਅੰਤ

        ਜੇ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ਨਿਰਾ);
            can_ਜੋੜੋ_underscore = 0;
        }

        ਜੇ (tcc_state->leading_underscore && can_ਜੋੜੋ_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, ਆਕਾਰ(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, ਮੁੱਲ, ਮਾਪ, info, other, sh_ਅੰਕ, name);

        ਜੇ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_ਅੰਕ, sym_bind, sym_type);

    } ਨਹੀਂਤਾਂ {
        esym = elfsym(sym);
        esym->st_ਮੁੱਲ = ਮੁੱਲ;
        esym->st_ਮਾਪ = ਮਾਪ;
        esym->st_shndx = sh_ਅੰਕ;
    }
    update_storage(sym);
}

ST_FUNC ਖਾਲੀ put_extern_sym(Sym *sym, Section *s, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਜੇ (nocode_wanted && (NODATA_WANTED || (s && s == cur_ਪਾਠ_section)))
        ਵਾਪਸ;
    put_extern_sym2(sym, s ? s->sh_ਅੰਕ : SHN_UNDEF, ਮੁੱਲ, ਮਾਪ, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC ਖਾਲੀ greloca(Section *s, Sym *sym, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type,
                     addr_t addend)
{
    ਪੂਰਨ c = 0;

    ਜੇ (nocode_wanted && s == cur_ਪਾਠ_section)
        ਵਾਪਸ;

    ਜੇ (sym) {
        ਜੇ (0 == sym->c) {
            put_extern_sym(sym, ਨਿਰਾ, 0, 0);
            ਜੇ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ਜਦੋਂ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, ਵਿੱਥ, type, c, addend);
}

#ਜੇ PTR_ਮਾਪ == 4
ST_FUNC ਖਾਲੀ greloc(Section *s, Sym *sym, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type)
{
    greloca(s, sym, ਵਿੱਥ, type, 0);
}
#ਜੇ_ਅੰਤ

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ਸਥਿਰ Sym *__sym_malloc(ਖਾਲੀ)
{
    Sym *sym_pool, *sym, *ਆਖਰੀ_sym;
    ਪੂਰਨ i;

    sym_pool = tcc_malloc(SYM_POOL_NB * ਆਕਾਰ(Sym));
    dynarray_ਜੋੜੋ(&sym_pools, &nb_sym_pools, sym_pool);

    ਆਖਰੀ_sym = sym_free_ਪਹਿਲਾ;
    sym = sym_pool;
    ਲਈ(i = 0; i < SYM_POOL_NB; i++) {
        sym->ਅਗਲਾ = ਆਖਰੀ_sym;
        ਆਖਰੀ_sym = sym;
        sym++;
    }
    sym_free_ਪਹਿਲਾ = ਆਖਰੀ_sym;
    ਵਾਪਸ ਆਖਰੀ_sym;
}

ਸਥਿਰ ਸਤਰਅੰਦਰ Sym *sym_malloc(ਖਾਲੀ)
{
    Sym *sym;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SYM_DEBUG
    sym = sym_free_ਪਹਿਲਾ;
    ਜੇ (!sym)
        sym = __sym_malloc();
    sym_free_ਪਹਿਲਾ = sym->ਅਗਲਾ;
    ਵਾਪਸ sym;
#ਨਹੀਂਤਾਂ
    sym = tcc_malloc(ਆਕਾਰ(Sym));
    ਵਾਪਸ sym;
#ਜੇ_ਅੰਤ
}

ST_INLN ਖਾਲੀ sym_free(Sym *sym)
{
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SYM_DEBUG
    sym->ਅਗਲਾ = sym_free_ਪਹਿਲਾ;
    sym_free_ਪਹਿਲਾ = sym;
#ਨਹੀਂਤਾਂ
    tcc_free(sym);
#ਜੇ_ਅੰਤ
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, ਪੂਰਨ v, ਪੂਰਨ t, ਪੂਰਨ c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, ਆਕਾਰ *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    ਵਾਪਸ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, ਪੂਰਨ v)
{
    ਜਦੋਂ (s) {
        ਜੇ (s->v == v)
            ਵਾਪਸ s;
        s = s->prev;
    }
    ਵਾਪਸ ਨਿਰਾ;
}

/* structure lookup */
ST_INLN Sym *struct_ਲੱਭੋ(ਪੂਰਨ v)
{
    v -= TOK_IDENT;
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)v >= (ਬਿਨਾਨਿਸ਼ਾਨੀ)(tok_ident - TOK_IDENT))
        ਵਾਪਸ ਨਿਰਾ;
    ਵਾਪਸ ਸਾਰਣੀ_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_ਲੱਭੋ(ਪੂਰਨ v)
{
    v -= TOK_IDENT;
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)v >= (ਬਿਨਾਨਿਸ਼ਾਨੀ)(tok_ident - TOK_IDENT))
        ਵਾਪਸ ਨਿਰਾ;
    ਵਾਪਸ ਸਾਰਣੀ_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ sym_link(Sym *s, ਪੂਰਨ yes)
{
    TokenSym *ts = ਸਾਰਣੀ_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ਜੇ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ਨਹੀਂਤਾਂ
        ps = &ts->sym_identifier;
    ਜੇ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ਨਹੀਂਤਾਂ {
        *ps = s->prev_tok;
    }
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ਵਾਪਸ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ਧੱਕੋ(ਪੂਰਨ v, CType *type, ਪੂਰਨ r, ਪੂਰਨ c)
{
    Sym *s, **ps;
    ਜੇ (local_ਢੇਰ)
        ps = &local_ਢੇਰ;
    ਨਹੀਂਤਾਂ
        ps = &global_ਢੇਰ;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ਜੇ ((v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ਜੇ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ਨਿਰਾ));
    }
    ਵਾਪਸ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ਧੱਕੋ(ਪੂਰਨ v, ਪੂਰਨ t, ਪੂਰਨ c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ਢੇਰ, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ਜੇ (v < SYM_ਪਹਿਲਾ_ANOM) {
        ps = &ਸਾਰਣੀ_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ਜਦੋਂ (*ps != ਨਿਰਾ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    ਵਾਪਸ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC ਖਾਲੀ sym_ਕੱਢੋ(Sym **ptop, Sym *b, ਪੂਰਨ keep)
{
    Sym *s, *ss;
    ਪੂਰਨ v;

    s = *ptop;
    ਜਦੋਂ(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ਜੇ ((v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM)
            sym_link(s, 0);
	ਜੇ (!keep)
	    sym_free(s);
        s = ss;
    }
    ਜੇ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_ਲੱਭੋ(ਪੂਰਨ v)
{
    v -= TOK_IDENT;
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)v >= (ਬਿਨਾਨਿਸ਼ਾਨੀ)(tok_ident - TOK_IDENT))
        ਵਾਪਸ ਨਿਰਾ;
    ਵਾਪਸ ਸਾਰਣੀ_ident[v]->sym_label;
}

ST_FUNC Sym *label_ਧੱਕੋ(Sym **ptop, ਪੂਰਨ v, ਪੂਰਨ flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &ਸਾਰਣੀ_ident[v - TOK_IDENT]->sym_label;
    ਜੇ (ptop == &global_label_ਢੇਰ) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ਜਦੋਂ (*ps != ਨਿਰਾ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    ਵਾਪਸ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC ਖਾਲੀ label_ਕੱਢੋ(Sym **ptop, Sym *slast, ਪੂਰਨ keep)
{
    Sym *s, *s1;
    ਲਈ(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ਜੇ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ਨਿਰਾ));
        } ਨਹੀਂਤਾਂ ਜੇ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ਨਿਰਾ));
        } ਨਹੀਂਤਾਂ {
            ਜੇ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_ਪਾਠ_section, s->jind, 1);
            }
        }
        /* remove label */
        ਜੇ (s->r != LABEL_GONE)
            ਸਾਰਣੀ_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ਜੇ (!keep)
            sym_free(s);
        ਨਹੀਂਤਾਂ
            s->r = LABEL_GONE;
    }
    ਜੇ (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ਸਥਿਰ ਖਾਲੀ vcheck_cmp(ਖਾਲੀ)
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

    ਜੇ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~ਕੋਡ_OFF_ਦੋਆਧਾਰੀ_ਅੰਕ))
        gv(RC_INT);
}

ਸਥਿਰ ਖਾਲੀ vsetc(CType *type, ਪੂਰਨ r, CValue *vc)
{
    ਜੇ (vtop >= vstack + (VSTACK_ਮਾਪ - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ਨਿਰਾ;
}

ST_FUNC ਖਾਲੀ vswap(ਖਾਲੀ)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC ਖਾਲੀ vpop(ਖਾਲੀ)
{
    ਪੂਰਨ v;
    v = vtop->r & VT_VALMASK;
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386) || defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
    /* for x86, we need to pop the FP stack */
    ਜੇ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    ਜੇ (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ਸਥਿਰ ਖਾਲੀ vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ਸਥਿਰ ਖਾਲੀ vpush64(ਪੂਰਨ ty, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ਨਿਰਾ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC ਖਾਲੀ vpushi(ਪੂਰਨ v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ਸਥਿਰ ਖਾਲੀ vpushs(addr_t v)
{
    vpush64(VT_ਮਾਪ_T, v);
}

/* push long long constant */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ vpushll(ਲੰਮਾ ਲੰਮਾ v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC ਖਾਲੀ vset(CType *type, ਪੂਰਨ r, ਪੂਰਨ v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ਸਥਿਰ ਖਾਲੀ vseti(ਪੂਰਨ r, ਪੂਰਨ v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ਨਿਰਾ;
    vset(&type, r, v);
}

ST_FUNC ਖਾਲੀ vpushv(SValue *v)
{
    ਜੇ (vtop >= vstack + (VSTACK_ਮਾਪ - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ਸਥਿਰ ਖਾਲੀ vdup(ਖਾਲੀ)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC ਖਾਲੀ vrotb(ਪੂਰਨ n)
{
    SValue tmp;
    ਜੇ (--n < 1)
        ਵਾਪਸ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, ਆਕਾਰ *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC ਖਾਲੀ vrott(ਪੂਰਨ n)
{
    SValue tmp;
    ਜੇ (--n < 1)
        ਵਾਪਸ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, ਆਕਾਰ *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC ਖਾਲੀ vrev(ਪੂਰਨ n)
{
    ਪੂਰਨ i;
    SValue tmp;
    vcheck_cmp();
    ਲਈ (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC ਖਾਲੀ vset_VT_CMP(ਪੂਰਨ op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ਸਥਿਰ ਖਾਲੀ vset_VT_JMP(ਖਾਲੀ)
{
    ਪੂਰਨ op = vtop->cmp_op;

    ਜੇ (vtop->jtrue || vtop->jfalse) {
        ਪੂਰਨ origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        ਪੂਰਨ inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ਨਹੀਂਤਾਂ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ਜੇ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ਸਥਿਰ ਖਾਲੀ gvtst_ਸੈੱਟ(ਪੂਰਨ inv, ਪੂਰਨ t)
{
    ਪੂਰਨ *p;

    ਜੇ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ਜੇ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ਸਥਿਰ ਪੂਰਨ gvtst(ਪੂਰਨ inv, ਪੂਰਨ t)
{
    ਪੂਰਨ op, x, u;

    gvtst_ਸੈੱਟ(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ਜੇ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ਜੇ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ਨਹੀਂਤਾਂ ਜੇ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ਵਾਪਸ t;
}

/* generate a zero or nozero test */
ਸਥਿਰ ਖਾਲੀ gen_test_zero(ਪੂਰਨ op)
{
    ਜੇ (vtop->r == VT_CMP) {
        ਪੂਰਨ j;
        ਜੇ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ਨਹੀਂਤਾਂ {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC ਖਾਲੀ vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਪੂਰਨ v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ਧੱਕੋ(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, ਵਿੱਥ, ਮਾਪ);
    ਵਾਪਸ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ਸਥਿਰ ਖਾਲੀ vpush_ref(CType *type, Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    vpushsym(type, get_sym_ref(type, sec, ਵਿੱਥ, ਮਾਪ));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(ਪੂਰਨ v, CType *type)
{
    Sym *s;

    s = sym_ਲੱਭੋ(v);
    ਜੇ (!s) {
        /* push forward reference */
        s = global_identifier_ਧੱਕੋ(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ਨਹੀਂਤਾਂ ਜੇ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ਵਾਪਸ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(ਪੂਰਨ v)
{
    CType ct = { VT_ASM_FUNC, ਨਿਰਾ };
    ਵਾਪਸ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC ਖਾਲੀ vpush_helper_func(ਪੂਰਨ v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ਸਥਿਰ ਖਾਲੀ ਮਿਲਾਓ_symattr(ਬਣਤਰ SymAttr *sa, ਬਣਤਰ SymAttr *sa1)
{
    ਜੇ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ਜੇ (sa1->visibility != STV_DEFAULT) {
	ਪੂਰਨ vis = sa->visibility;
	ਜੇ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ਸਥਿਰ ਖਾਲੀ ਮਿਲਾਓ_funcattr(ਬਣਤਰ FuncAttr *fa, ਬਣਤਰ FuncAttr *fa1)
{
    ਜੇ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ਜੇ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ਜੇ (fa1->func_ਦਲੀਲਾਂ && !fa->func_ਦਲੀਲਾਂ)
      fa->func_ਦਲੀਲਾਂ = fa1->func_ਦਲੀਲਾਂ;
    ਜੇ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ਜੇ (fa1->func_ctor)
      fa->func_ctor = 1;
    ਜੇ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ਸਥਿਰ ਖਾਲੀ ਮਿਲਾਓ_attr(AttributeDef *ad, AttributeDef *ad1)
{
    ਮਿਲਾਓ_symattr(&ad->a, &ad1->a);
    ਮਿਲਾਓ_funcattr(&ad->f, &ad1->f);

    ਜੇ (ad1->section)
      ad->section = ad1->section;
    ਜੇ (ad1->alias_ਨਿਸ਼ਾਨਾ)
      ad->alias_ਨਿਸ਼ਾਨਾ = ad1->alias_ਨਿਸ਼ਾਨਾ;
    ਜੇ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ਜੇ (ad1->attr_ਬਹੁਲਕ)
      ad->attr_ਬਹੁਲਕ = ad1->attr_ਬਹੁਲਕ;
}

/* Merge some type attributes.  */
ਸਥਿਰ ਖਾਲੀ patch_type(Sym *sym, CType *type)
{
    ਜੇ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ਜੇ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ਨਿਰਾ));
        sym->type.t &= ~VT_EXTERN;
    }

    ਜੇ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ਜੇ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ਜੇ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ਨਿਰਾ));

    } ਨਹੀਂਤਾਂ ਜੇ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        ਪੂਰਨ static_proto = sym->type.t & VT_STATIC;
        ਪੂਰਨ ft1 = sym->type.ref->f.func_type;
        ਪੂਰਨ ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ਜੇ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ਨਿਰਾ));

        /* set 'inline' if both agree or if one has static */
        ਜੇ ((type->t | sym->type.t) & VT_INLINE) {
            ਜੇ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ਜੇ (0 == (type->t & VT_EXTERN)) {
            ਬਣਤਰ FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ਜੇ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            ਮਿਲਾਓ_funcattr(&sym->type.ref->f, &f);
        } ਨਹੀਂਤਾਂ {
            sym->type.t &= ~VT_INLINE | static_proto;
            ਜੇ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ਨਹੀਂਤਾਂ {
        ਜੇ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ਜੇ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ਨਿਰਾ));
    }
}

/* Merge some storage attributes.  */
ਸਥਿਰ ਖਾਲੀ patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ਜੇ (type)
        patch_type(sym, type);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ਨਿਰਾ));
#ਜੇ_ਅੰਤ
    ਮਿਲਾਓ_symattr(&sym->a, &ad->a);
    ਜੇ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ਸਥਿਰ Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ਜੇ ((s->v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM)
        sym_link(s, 1);
    ਵਾਪਸ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ਸਥਿਰ ਖਾਲੀ move_ref_ਮੰਜ਼ਿਲ_global(Sym *s)
{
    Sym *l, **lp;
    ਪੂਰਨ n, bt;

    bt = s->type.t & VT_BTYPE;
    ਜੇ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ਵਾਪਸ;

    ਲਈ (s = s->type.ref, n = 0; s; s = s->ਅਗਲਾ) {
        ਲਈ (lp = &local_ਢੇਰ; !!(l = *lp); lp = &l->prev) {
            ਜੇ (l == s) {
                *lp = s->prev;
                s->prev = global_ਢੇਰ, global_ਢੇਰ = s;
                ਜੇ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_ਮੰਜ਼ਿਲ_global(s);
                } ਨਹੀਂਤਾਂ {
                    ਜੇ ((s->v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_ਖੇਤਰ;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_ਖੇਤਰ;
                    }
                }
                ਜੇ (bt != VT_PTR)
                    n = 1;
                ਰੋਕੋ;
            }
        }
        ਜੇ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            ਰੋਕੋ;
    }
}

/* define a new external reference to a symbol 'v' */
ਸਥਿਰ Sym *external_sym(ਪੂਰਨ v, CType *type, ਪੂਰਨ r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_ਲੱਭੋ(v);
    ਜਦੋਂ (s && s->sym_scope)
        s = s->prev_tok;

    ਜੇ (!s) {
        /* push forward reference */
        s = global_identifier_ਧੱਕੋ(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ਨਹੀਂਤਾਂ {
        patch_storage(s, ad, type);
    }
    ਜੇ (local_ਢੇਰ) {
        /* make sure that type->ref is on global stack */
        move_ref_ਮੰਜ਼ਿਲ_global(s);
        /* put into local scope */
        sym_copy(s, &local_ਢੇਰ);
    }
    ਵਾਪਸ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC ਖਾਲੀ save_regs(ਪੂਰਨ n)
{
    SValue *p, *p1;
    ਲਈ(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC ਖਾਲੀ save_reg(ਪੂਰਨ r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC ਖਾਲੀ save_reg_upstack(ਪੂਰਨ r, ਪੂਰਨ n)
{
    ਪੂਰਨ l, ਮਾਪ, align, bt, r2;
    SValue *p, *p1, sv;

    ਜੇ ((r &= VT_VALMASK) >= VT_CONST)
        ਵਾਪਸ;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    l = r2 = 0;
    ਲਈ(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ਜੇ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ਜੇ (!l) {
                bt = p->type.t & VT_BTYPE;
                ਜੇ (bt == VT_VOID)
                    ਜਾਰੀ;
                ਜੇ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                ਮਾਪ = type_ਮਾਪ(&sv.type, &align);
                l = get_ਆਰਜ਼ੀ_local_var(ਮਾਪ, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ਨਿਰਾ;
                store(p->r & VT_VALMASK, &sv);
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386) || defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ਜੇ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#ਜੇ_ਅੰਤ
                /* special long long case */
                ਜੇ (p->r2 < VT_CONST && USING_TWO_ਸ਼ਬਦ(bt)) {
                    sv.c.i += PTR_ਮਾਪ;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ਜੇ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ਨਹੀਂਤਾਂ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ਨਿਰਾ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC ਪੂਰਨ get_reg_ex(ਪੂਰਨ rc, ਪੂਰਨ rc2)
{
    ਪੂਰਨ r;
    SValue *p;
    
    ਲਈ(r=0;r<NB_REGS;r++) {
        ਜੇ (reg_classes[r] & rc2) {
            ਪੂਰਨ n;
            n=0;
            ਲਈ(p = vstack; p <= vtop; p++) {
                ਜੇ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ਜੇ (n <= 1)
                ਵਾਪਸ r;
        }
    }
    ਵਾਪਸ get_reg(rc);
}
#ਜੇ_ਅੰਤ

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC ਪੂਰਨ get_reg(ਪੂਰਨ rc)
{
    ਪੂਰਨ r;
    SValue *p;

    /* find a free register */
    ਲਈ(r=0;r<NB_REGS;r++) {
        ਜੇ (reg_classes[r] & rc) {
            ਜੇ (nocode_wanted)
                ਵਾਪਸ r;
            ਲਈ(p=vstack;p<=vtop;p++) {
                ਜੇ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    ਜਾਓ notfound;
            }
            ਵਾਪਸ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    ਲਈ(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ਜੇ (r < VT_CONST && (reg_classes[r] & rc))
            ਜਾਓ save_ਮਿਲਿਆ;
        r = p->r & VT_VALMASK;
        ਜੇ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_ਮਿਲਿਆ:
            save_reg(r);
            ਵਾਪਸ r;
        }
    }
    /* Should never comes here */
    ਵਾਪਸ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ਸਥਿਰ ਪੂਰਨ get_ਆਰਜ਼ੀ_local_var(ਪੂਰਨ ਮਾਪ,ਪੂਰਨ align, ਪੂਰਨ *r2)
{
    ਪੂਰਨ i;
    ਬਣਤਰ ਆਰਜ਼ੀ_local_variable *ਆਰਜ਼ੀ_var;
    SValue *p;
    ਪੂਰਨ r;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਰਤਿਆ = 0;

    /* mark locations that are still in use */
    ਲਈ (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ਜੇ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ਜੇ (r >= 0 && r < MAX_ਆਰਜ਼ੀ_LOCAL_VARIABLE_ਸੰਖਿਆ)
	        ਵਰਤਿਆ |= 1<<r;
	}
    }
    ਲਈ (i=0;i<nb_ਆਰਜ਼ੀ_local_vars;i++) {
	ਆਰਜ਼ੀ_var=&arr_ਆਰਜ਼ੀ_local_vars[i];
	ਜੇ(!(ਵਰਤਿਆ & 1<<i)
	 && ਆਰਜ਼ੀ_var->ਮਾਪ>=ਮਾਪ
	 && ਆਰਜ਼ੀ_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ਵਾਪਸ ਆਰਜ਼ੀ_var->location;
	}
    }
    loc = (loc - ਮਾਪ) & -align;
    ਜੇ (nb_ਆਰਜ਼ੀ_local_vars<MAX_ਆਰਜ਼ੀ_LOCAL_VARIABLE_ਸੰਖਿਆ) {
	ਆਰਜ਼ੀ_var=&arr_ਆਰਜ਼ੀ_local_vars[i];
	ਆਰਜ਼ੀ_var->location=loc;
	ਆਰਜ਼ੀ_var->ਮਾਪ=ਮਾਪ;
	ਆਰਜ਼ੀ_var->align=align;
	nb_ਆਰਜ਼ੀ_local_vars++;
	ਜਾਓ ret_tmp;
    }
    *r2 = VT_CONST;
    ਵਾਪਸ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ਸਥਿਰ ਖਾਲੀ move_reg(ਪੂਰਨ r, ਪੂਰਨ s, ਪੂਰਨ t)
{
    SValue sv;

    ਜੇ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ਨਿਰਾ;
        sv.r = s;
        sv.c.i = 0;
        ਲੱਦੋ(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC ਖਾਲੀ gaddrof(ਖਾਲੀ)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ਜੇ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ਸਥਿਰ ਖਾਲੀ gen_bounded_ptr_ਜੋੜੋ(ਖਾਲੀ)
{
    ਪੂਰਨ save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ਜੇ (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_ਜੋੜੋ);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_ਪਾਠ_section->reloc->ਅੰਕੜੇ_ਵਿੱਥ - ਆਕਾਰ(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ਸਥਿਰ ਖਾਲੀ gen_bounded_ptr_deref(ਖਾਲੀ)
{
    addr_t func;
    ਪੂਰਨ ਮਾਪ, align;
    ElfW_Rel *rel;
    Sym *sym;

    ਜੇ (nocode_wanted)
        ਵਾਪਸ;

    ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
    ਚੋਣ(ਮਾਪ) {
    ਹਾਲਤ  1: func = TOK___bound_ptr_indir1; ਰੋਕੋ;
    ਹਾਲਤ  2: func = TOK___bound_ptr_indir2; ਰੋਕੋ;
    ਹਾਲਤ  4: func = TOK___bound_ptr_indir4; ਰੋਕੋ;
    ਹਾਲਤ  8: func = TOK___bound_ptr_indir8; ਰੋਕੋ;
    ਹਾਲਤ 12: func = TOK___bound_ptr_indir12; ਰੋਕੋ;
    ਹਾਲਤ 16: func = TOK___bound_ptr_indir16; ਰੋਕੋ;
    ਮੂਲ:
        /* may happen with struct member access */
        ਵਾਪਸ;
    }
    sym = external_helper_sym(func);
    ਜੇ (!sym->c)
        put_extern_sym(sym, ਨਿਰਾ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_ਪਾਠ_section->reloc->ਅੰਕੜੇ + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ਸਥਿਰ ਖਾਲੀ gbound(ਖਾਲੀ)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ਜੇ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ਜੇ (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_ਜੋੜੋ();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC ਖਾਲੀ gbound_ਦਲੀਲਾਂ(ਪੂਰਨ nb_ਦਲੀਲਾਂ)
{
    ਪੂਰਨ i, v;
    SValue *sv;

    ਲਈ (i = 1; i <= nb_ਦਲੀਲਾਂ; ++i)
        ਜੇ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_ਦਲੀਲਾਂ;
    ਜੇ (sv->r & VT_SYM) {
        v = sv->sym->v;
        ਜੇ (v == TOK_setjmp
          || v == TOK__setjmp
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#ਜੇ_ਅੰਤ
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_ਜੋੜੋ_epilog = 1;
        }
        ਜੇ (v == TOK_alloca)
            func_bound_ਜੋੜੋ_epilog = 1;
#ਜੇ TARGETOS_NetBSD
        ਜੇ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#ਜੇ_ਅੰਤ
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ਸਥਿਰ ਖਾਲੀ ਜੋੜੋ_local_bounds(Sym *s, Sym *e)
{
    ਲਈ (; s != e; s = s->prev) {
        ਜੇ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ਜਾਰੀ;
        /* Add arrays/structs/unions because we always take address */
        ਜੇ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_ਜੋੜੋ(lbounds_section,
                                                 2 * ਆਕਾਰ(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = ਮਾਪ;
        }
    }
}
#ਜੇ_ਅੰਤ

/* add debug info for locals or function parameters, optionally
   register bounds */
ਸਥਿਰ ਖਾਲੀ tcc_debug_ਸਿਰਾ_scope(Sym *b, ਪੂਰਨ bounds)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (tcc_state->do_bounds_check && bounds)
        ਜੋੜੋ_local_bounds(local_ਢੇਰ, b);
#ਜੇ_ਅੰਤ
    tcc_ਜੋੜੋ_debug_info (tcc_state, local_ਢੇਰ, b);
}

/* increment an lvalue pointer */
ਸਥਿਰ ਖਾਲੀ incr_ਵਿੱਥ(ਪੂਰਨ ਵਿੱਥ)
{
    ਪੂਰਨ t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(ਵਿੱਥ);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ਸਥਿਰ ਖਾਲੀ incr_bf_adr(ਪੂਰਨ o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_ਵਿੱਥ(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ਸਥਿਰ ਖਾਲੀ ਲੱਦੋ_packed_bf(CType *type, ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
{
    ਪੂਰਨ n, o, ਬਿੱਟ;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    ਬਿੱਟ = 0, o = ਦੋਆਧਾਰੀ_ਅੰਕ_pos >> 3, ਦੋਆਧਾਰੀ_ਅੰਕ_pos &= 7;
    ਕਰੋ {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
        ਜੇ (n > ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
            n = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_pos)
            vpushi(ਦੋਆਧਾਰੀ_ਅੰਕ_pos), gen_op(TOK_SHR), ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0; // X B Y
        ਜੇ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ਜੇ (ਬਿੱਟ)
            vpushi(ਬਿੱਟ), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        ਬਿੱਟ += n, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 -= n, o = 1;
    } ਜਦੋਂ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
    vswap(), vpop();
    ਜੇ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - ਬਿੱਟ;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ਸਥਿਰ ਖਾਲੀ store_packed_bf(ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
{
    ਪੂਰਨ ਬਿੱਟ, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    ਬਿੱਟ = 0, o = ਦੋਆਧਾਰੀ_ਅੰਕ_pos >> 3, ਦੋਆਧਾਰੀ_ਅੰਕ_pos &= 7;
    ਕਰੋ {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ਜੇ (ਬਿੱਟ)
            vpushi(ਬਿੱਟ), gen_op(TOK_SHR);
        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_pos)
            vpushi(ਦੋਆਧਾਰੀ_ਅੰਕ_pos), gen_op(TOK_SHL);
        n = 8 - ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
        ਜੇ (n > ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
            n = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
        ਜੇ (n < 8) {
            m = ((1 << n) - 1) << ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        ਬਿੱਟ += n, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 -= n, ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0, o = 1;
    } ਜਦੋਂ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
    vpop(), vpop();
}

ਸਥਿਰ ਪੂਰਨ adjust_bf(SValue *sv, ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
{
    ਪੂਰਨ t;
    ਜੇ (0 == sv->type.ref)
        ਵਾਪਸ 0;
    t = sv->type.ref->auxtype;
    ਜੇ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ਵਾਪਸ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC ਪੂਰਨ gv(ਪੂਰਨ rc)
{
    ਪੂਰਨ r, r2, r_ok, r2_ok, rc2, bt;
    ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2, ਮਾਪ, align;

    /* NOTE: get_reg can modify vstack[] */
    ਜੇ (vtop->type.t & VT_BITFIELD) {
        CType type;

        ਦੋਆਧਾਰੀ_ਅੰਕ_pos = ਦੋਆਧਾਰੀ_ਅੰਕ_POS(vtop->type.t);
        ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_ਨਕਾਬ;

        type.ref = ਨਿਰਾ;
        type.t = vtop->type.t & VT_UNSIGNED;
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);

        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ਨਹੀਂਤਾਂ
            type.t |= VT_INT;

        ਜੇ (r == VT_STRUCT) {
            ਲੱਦੋ_packed_bf(&type, ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
        } ਨਹੀਂਤਾਂ {
            ਪੂਰਨ ਬਿੱਟ = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(ਬਿੱਟ - (ਦੋਆਧਾਰੀ_ਅੰਕ_pos + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2));
            gen_op(TOK_SHL);
            vpushi(ਬਿੱਟ - ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } ਨਹੀਂਤਾਂ {
        ਜੇ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ;
            ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
            ਜੇ (NODATA_WANTED)
                ਮਾਪ = 0, align = 1;
            ਵਿੱਥ = section_ਜੋੜੋ(p.sec, ਮਾਪ, align);
            vpush_ref(&vtop->type, p.sec, ਵਿੱਥ, ਮਾਪ);
	    vswap();
	    init_putv(&p, &vtop->type, ਵਿੱਥ);
	    vtop->r |= VT_LVAL;
        }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (vtop->r & VT_MUSTBOUND) 
            gbound();
#ਜੇ_ਅੰਤ

        bt = vtop->type.t & VT_BTYPE;
        ਜੇ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ਵਾਪਸ vtop->r;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
        /* XXX mega hack */
        ਜੇ (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#ਜੇ_ਅੰਤ
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        ਜੇ (!r_ok || !r2_ok) {

            ਜੇ (!r_ok) {
                ਜੇ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ਨਹੀਂਤਾਂ
                    r = get_reg(rc);
            }

            ਜੇ (rc2) {
                ਪੂਰਨ ਲੱਦੋ_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                ਪੂਰਨ original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    ਲੱਦੋ(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ਨਹੀਂਤਾਂ ਜੇ (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = ਲੱਦੋ_type;
                    ਲੱਦੋ(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_ਵਿੱਥ(PTR_ਮਾਪ);
                } ਨਹੀਂਤਾਂ {
                    /* move registers */
                    ਜੇ (!r_ok)
                        ਲੱਦੋ(r, vtop);
                    ਜੇ (r2_ok && vtop->r2 < VT_CONST)
                        ਜਾਓ ਪੂਰਾ;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                ਲੱਦੋ(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            ਪੂਰਾ:
                vtop->type.t = original_type;
            } ਨਹੀਂਤਾਂ {
                ਜੇ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                ਲੱਦੋ(r, vtop);
            }
        }
        vtop->r = r;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_C67
        /* uses register pairs for doubles */
        ਜੇ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#ਜੇ_ਅੰਤ
    }
    ਵਾਪਸ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC ਖਾਲੀ gv2(ਪੂਰਨ rc1, ਪੂਰਨ rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ਜੇ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ਜੇ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ਨਹੀਂਤਾਂ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ਜੇ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ਜੇ PTR_ਮਾਪ == 4
/* expand 64bit on stack in two ints */
ST_FUNC ਖਾਲੀ lexpand(ਖਾਲੀ)
{
    ਪੂਰਨ u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ਜੇ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ਨਹੀਂਤਾਂ ਜੇ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ਨਹੀਂਤਾਂ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#ਜੇ_ਅੰਤ

#ਜੇ PTR_ਮਾਪ == 4
/* build a long long from two ints */
ਸਥਿਰ ਖਾਲੀ lbuild(ਪੂਰਨ t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#ਜੇ_ਅੰਤ

/* convert stack entry to register and duplicate its value in another
ਰਜਿਸਟਰ*/
ਸਥਿਰ ਖਾਲੀ gv_dup(ਖਾਲੀ)
{
    ਪੂਰਨ t, rc, r;

    t = vtop->type.t;
#ਜੇ PTR_ਮਾਪ == 4
    ਜੇ ((t & VT_BTYPE) == VT_LLONG) {
        ਜੇ (t & VT_BITFIELD) {
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
        ਵਾਪਸ;
    }
#ਜੇ_ਅੰਤ
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    ਲੱਦੋ(r, vtop);
    vtop->r = r;
}

#ਜੇ PTR_ਮਾਪ == 4
/* generate CPU independent (unsigned) long long operations */
ਸਥਿਰ ਖਾਲੀ gen_opl(ਪੂਰਨ op)
{
    ਪੂਰਨ t, a, b, op1, c, i;
    ਪੂਰਨ func;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ reg_iret = REG_IRET;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ reg_lret = REG_IRE2;
    SValue tmp;

    ਚੋਣ(op) {
    ਹਾਲਤ '/':
    ਹਾਲਤ TOK_PDIV:
        func = TOK___divdi3;
        ਜਾਓ gen_func;
    ਹਾਲਤ TOK_UDIV:
        func = TOK___udivdi3;
        ਜਾਓ gen_func;
    ਹਾਲਤ '%':
        func = TOK___moddi3;
        ਜਾਓ gen_mod_func;
    ਹਾਲਤ TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#ਜੇ_ਅੰਤ
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        ਰੋਕੋ;
    ਹਾਲਤ '^':
    ਹਾਲਤ '&':
    ਹਾਲਤ '|':
    ਹਾਲਤ '*':
    ਹਾਲਤ '+':
    ਹਾਲਤ '-':
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
        ਜੇ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            ਲਈ(i=0;i<4;i++)
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
        } ਨਹੀਂਤਾਂ ਜੇ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ਜੇ (op == '+')
                op1 = TOK_ADDC1;
            ਨਹੀਂਤਾਂ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ਨਹੀਂਤਾਂ {
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
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SAR:
    ਹਾਲਤ TOK_SHR:
    ਹਾਲਤ TOK_SHL:
        ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (ਪੂਰਨ)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ਜੇ (op != TOK_SHL)
                vswap();
            ਜੇ (c >= 32) {
                /* stack: L H */
                vpop();
                ਜੇ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ਜੇ (op != TOK_SAR) {
                    vpushi(0);
                } ਨਹੀਂਤਾਂ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ਨਹੀਂਤਾਂ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ਜੇ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ਨਹੀਂਤਾਂ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ਜੇ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ਨਹੀਂਤਾਂ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ਜੇ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ਨਹੀਂਤਾਂ {
            /* XXX: should provide a faster fallback on x86 ? */
            ਚੋਣ(op) {
            ਹਾਲਤ TOK_SAR:
                func = TOK___ashrdi3;
                ਜਾਓ gen_func;
            ਹਾਲਤ TOK_SHR:
                func = TOK___lshrdi3;
                ਜਾਓ gen_func;
            ਹਾਲਤ TOK_SHL:
                func = TOK___ashldi3;
                ਜਾਓ gen_func;
            }
        }
        ਰੋਕੋ;
    ਮੂਲ:
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
        ਜੇ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ਜੇ (op1 == TOK_LT)
            op1 = TOK_LE;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_GT)
            op1 = TOK_GE;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ਜੇ (op == TOK_NE) {
            b = gvtst(0, 0);
        } ਨਹੀਂਤਾਂ {
            a = gvtst(1, 0);
            ਜੇ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ਜੇ (op1 == TOK_LT)
            op1 = TOK_ULT;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_LE)
            op1 = TOK_ULE;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_GT)
            op1 = TOK_UGT;
        ਨਹੀਂਤਾਂ ਜੇ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ਜੇ 0//def TCC_TARGET_I386
        ਜੇ (op == TOK_NE) { gsym(b); ਰੋਕੋ; }
        ਜੇ (op == TOK_EQ) { gsym(a); ਰੋਕੋ; }
#ਜੇ_ਅੰਤ
        gvtst_ਸੈੱਟ(1, a);
        gvtst_ਸੈੱਟ(0, b);
        ਰੋਕੋ;
    }
}
#ਜੇ_ਅੰਤ

/* normalize values */
ਸਥਿਰ uint64_t value64(uint64_t l1, ਪੂਰਨ t)
{
    ਜੇ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_ਮਾਪ == 8 && (t & VT_BTYPE) == VT_PTR))
        ਵਾਪਸ l1;
    ਨਹੀਂਤਾਂ ਜੇ (t & VT_UNSIGNED)
        ਵਾਪਸ (uint32_t)l1;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ (uint32_t)l1 | -(l1 & 0x80000000);
}

ਸਥਿਰ uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ਵਾਪਸ (a ^ b) >> 63 ? -x : x;
}

ਸਥਿਰ ਪੂਰਨ gen_opic_lt(uint64_t a, uint64_t b)
{
    ਵਾਪਸ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ਸਥਿਰ ਖਾਲੀ gen_opic(ਪੂਰਨ op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    ਪੂਰਨ t1 = v1->type.t & VT_BTYPE;
    ਪੂਰਨ t2 = v2->type.t & VT_BTYPE;
    ਪੂਰਨ c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ਪੂਰਨ c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    ਪੂਰਨ shm = (t1 == VT_LLONG) ? 63 : 31;
    ਪੂਰਨ r;

    ਜੇ (c1 && c2) {
        ਚੋਣ(op) {
        ਹਾਲਤ '+': l1 += l2; ਰੋਕੋ;
        ਹਾਲਤ '-': l1 -= l2; ਰੋਕੋ;
        ਹਾਲਤ '&': l1 &= l2; ਰੋਕੋ;
        ਹਾਲਤ '^': l1 ^= l2; ਰੋਕੋ;
        ਹਾਲਤ '|': l1 |= l2; ਰੋਕੋ;
        ਹਾਲਤ '*': l1 *= l2; ਰੋਕੋ;

        ਹਾਲਤ TOK_PDIV:
        ਹਾਲਤ '/':
        ਹਾਲਤ '%':
        ਹਾਲਤ TOK_UDIV:
        ਹਾਲਤ TOK_UMOD:
            /* if division by zero, generate explicit division */
            ਜੇ (l2 == 0) {
                ਜੇ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                ਜਾਓ general_case;
            }
            ਚੋਣ(op) {
            ਮੂਲ: l1 = gen_opic_sdiv(l1, l2); ਰੋਕੋ;
            ਹਾਲਤ '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); ਰੋਕੋ;
            ਹਾਲਤ TOK_UDIV: l1 = l1 / l2; ਰੋਕੋ;
            ਹਾਲਤ TOK_UMOD: l1 = l1 % l2; ਰੋਕੋ;
            }
            ਰੋਕੋ;
        ਹਾਲਤ TOK_SHL: l1 <<= (l2 & shm); ਰੋਕੋ;
        ਹਾਲਤ TOK_SHR: l1 >>= (l2 & shm); ਰੋਕੋ;
        ਹਾਲਤ TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            ਰੋਕੋ;
            /* tests */
        ਹਾਲਤ TOK_ULT: l1 = l1 < l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGE: l1 = l1 >= l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_EQ: l1 = l1 == l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_NE: l1 = l1 != l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_ULE: l1 = l1 <= l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_UGT: l1 = l1 > l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_LT: l1 = gen_opic_lt(l1, l2); ਰੋਕੋ;
        ਹਾਲਤ TOK_GE: l1 = !gen_opic_lt(l1, l2); ਰੋਕੋ;
        ਹਾਲਤ TOK_LE: l1 = !gen_opic_lt(l2, l1); ਰੋਕੋ;
        ਹਾਲਤ TOK_GT: l1 = gen_opic_lt(l2, l1); ਰੋਕੋ;
            /* logical */
        ਹਾਲਤ TOK_LAND: l1 = l1 && l2; ਰੋਕੋ;
        ਹਾਲਤ TOK_LOR: l1 = l1 || l2; ਰੋਕੋ;
        ਮੂਲ:
            ਜਾਓ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ਨਹੀਂਤਾਂ {
        /* if commutative ops, put c2 as constant */
        ਜੇ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ਜੇ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ਨਹੀਂਤਾਂ ਜੇ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ਜੇ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ਨਹੀਂਤਾਂ ਜੇ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ਨਹੀਂਤਾਂ ਜੇ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ਜੇ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                ਪੂਰਨ n = -1;
                ਜੇ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    ਜਾਓ general_case;
                }
                ਜਦੋਂ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ਜੇ (op == '*')
                    op = TOK_SHL;
                ਨਹੀਂਤਾਂ ਜੇ (op == TOK_PDIV)
                    op = TOK_SAR;
                ਨਹੀਂਤਾਂ
                    op = TOK_SHR;
            }
            ਜਾਓ general_case;
        } ਨਹੀਂਤਾਂ ਜੇ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ਜੇ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ਜੇ ((ਪੂਰਨ)l2 != l2)
	        ਜਾਓ general_case;
            vtop--;
            vtop->c.i = l2;
        } ਨਹੀਂਤਾਂ {
        general_case:
                /* call low level op generator */
                ਜੇ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_ਮਾਪ == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ਨਹੀਂਤਾਂ
                    gen_opi(op);
        }
        ਜੇ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 || defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
# define gen_negf gen_opf
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
ਖਾਲੀ gen_negf(ਪੂਰਨ op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ਨਹੀਂਤਾਂ
/* XXX: implement in gen_opf() for other backends too */
ਖਾਲੀ gen_negf(ਪੂਰਨ op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    ਪੂਰਨ align, ਮਾਪ, bt;
    ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 || defined TCC_ਨਿਸ਼ਾਨਾ_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ਜੇ (bt == VT_LDOUBLE)
        ਮਾਪ = 10;
#ਜੇ_ਅੰਤ
    ਜੇ (nocode_wanted) /* save_reg() wont work */
        ਜਾਓ gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(ਮਾਪ - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#ਜੇ_ਅੰਤ

/* generate a floating point operation with constant propagation */
ਸਥਿਰ ਖਾਲੀ gen_opif(ਪੂਰਨ op)
{
    ਪੂਰਨ c1, c2, i, bt;
    SValue *v1, *v2;
#ਜੇ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    ਅਸਥਿਰ
#ਜੇ_ਅੰਤ
    ਲੰਮਾ ਦੁੱਗਣਾ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ਜੇ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ਜੇ (c1 && c2) {
        ਜੇ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ਨਹੀਂਤਾਂ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ਜੇ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            ਜਾਓ general_case;
        ਚੋਣ(op) {
        ਹਾਲਤ '+': f1 += f2; ਰੋਕੋ;
        ਹਾਲਤ '-': f1 -= f2; ਰੋਕੋ;
        ਹਾਲਤ '*': f1 *= f2; ਰੋਕੋ;
        ਹਾਲਤ '/': 
            ਜੇ (f2 == 0.0) {
                ਸੰਘ { ਦਸ਼ਮਲਵ f; ਬਿਨਾਨਿਸ਼ਾਨੀ u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ਜੇ (!CONST_WANTED)
                    ਜਾਓ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ਜੇ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ਨਹੀਂਤਾਂ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                ਰੋਕੋ;
            }
            f1 /= f2;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NEG:
            f1 = -f1;
            ਜਾਓ unary_ਨਤੀਜਾ;
        ਹਾਲਤ TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ਵਾਪਸ;
        ਹਾਲਤ TOK_NE:
            i = f1 != f2;
	    ਜਾਓ make_int;
        ਹਾਲਤ TOK_LT:
            i = f1 < f2;
	    ਜਾਓ make_int;
        ਹਾਲਤ TOK_GE:
            i = f1 >= f2;
	    ਜਾਓ make_int;
        ਹਾਲਤ TOK_LE:
            i = f1 <= f2;
	    ਜਾਓ make_int;
        ਹਾਲਤ TOK_GT:
            i = f1 > f2;
	    ਜਾਓ make_int;
        ਮੂਲ:
            ਜਾਓ general_case;
        }
        vtop--;
    unary_ਨਤੀਜਾ:
        /* XXX: overflow test ? */
        ਜੇ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ਨਹੀਂਤਾਂ {
            v1->c.ld = f1;
        }
    } ਨਹੀਂਤਾਂ {
    general_case:
        ਜੇ (op == TOK_NEG) {
            gen_negf(op);
        } ਨਹੀਂਤਾਂ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ਸਥਿਰ ਖਾਲੀ type_ਮੰਜ਼ਿਲ_str(ਅੱਖਰ *buf, ਪੂਰਨ buf_ਮਾਪ,
                 CType *type, ਅਚਲ ਅੱਖਰ *varstr)
{
    ਪੂਰਨ bt, v, t;
    Sym *s, *sa;
    ਅੱਖਰ buf1[256];
    ਅਚਲ ਅੱਖਰ *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ਜੇ (t & VT_EXTERN)
        pstrcat(buf, buf_ਮਾਪ, "extern ");
    ਜੇ (t & VT_STATIC)
        pstrcat(buf, buf_ਮਾਪ, "static ");
    ਜੇ (t & VT_TYPEDEF)
        pstrcat(buf, buf_ਮਾਪ, "typedef ");
    ਜੇ (t & VT_INLINE)
        pstrcat(buf, buf_ਮਾਪ, "inline ");
    ਜੇ (bt != VT_PTR) {
        ਜੇ (t & VT_RESTRICT)
            pstrcat(buf, buf_ਮਾਪ, "restrict ");
        ਜੇ (t & VT_VOLATILE)
            pstrcat(buf, buf_ਮਾਪ, "volatile ");
        ਜੇ (t & VT_CONSTANT)
            pstrcat(buf, buf_ਮਾਪ, "const ");
    }
    ਜੇ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_ਮਾਪ, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_ਮਾਪ -= ਲੜੀ_ਲੰਬਾਈ(buf);
    buf += ਲੜੀ_ਲੰਬਾਈ(buf);

    ਚੋਣ(bt) {
    ਹਾਲਤ VT_VOID:
        tstr = "void";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_BOOL:
        tstr = "_Bool";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_BYTE:
        tstr = "char";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_SHORT:
        tstr = "short";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_INT:
        tstr = "int";
        ਜਾਓ maybe_long;
    ਹਾਲਤ VT_LLONG:
        tstr = "long long";
    maybe_long:
        ਜੇ (t & VT_LONG)
            tstr = "long";
        ਜੇ (!IS_ENUM(t))
            ਜਾਓ ਜੋੜੋ_tstr;
        tstr = "enum ";
        ਜਾਓ tstruct;
    ਹਾਲਤ VT_FLOAT:
        tstr = "float";
        ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_DOUBLE:
        tstr = "double";
        ਜੇ (!(t & VT_LONG))
            ਜਾਓ ਜੋੜੋ_tstr;
    ਹਾਲਤ VT_LDOUBLE:
        tstr = "long double";
    ਜੋੜੋ_tstr:
        pstrcat(buf, buf_ਮਾਪ, tstr);
        ਰੋਕੋ;
    ਹਾਲਤ VT_STRUCT:
        tstr = "struct ";
        ਜੇ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_ਮਾਪ, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ਜੇ (v >= SYM_ਪਹਿਲਾ_ANOM)
            pstrcat(buf, buf_ਮਾਪ, "<anonymous>");
        ਨਹੀਂਤਾਂ
            pstrcat(buf, buf_ਮਾਪ, get_tok_str(v, ਨਿਰਾ));
        ਰੋਕੋ;
    ਹਾਲਤ VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ਜੇ (varstr && '*' == *varstr) {
            pstrcat(buf1, ਆਕਾਰ(buf1), "(");
            pstrcat(buf1, ਆਕਾਰ(buf1), varstr);
            pstrcat(buf1, ਆਕਾਰ(buf1), ")");
        }
        pstrcat(buf1, ਆਕਾਰ(buf1), "(");
        sa = s->ਅਗਲਾ;
        ਜਦੋਂ (sa != ਨਿਰਾ) {
            ਅੱਖਰ buf2[256];
            type_ਮੰਜ਼ਿਲ_str(buf2, ਆਕਾਰ(buf2), &sa->type, ਨਿਰਾ);
            pstrcat(buf1, ਆਕਾਰ(buf1), buf2);
            sa = sa->ਅਗਲਾ;
            ਜੇ (sa)
                pstrcat(buf1, ਆਕਾਰ(buf1), ", ");
        }
        ਜੇ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, ਆਕਾਰ(buf1), ", ...");
        pstrcat(buf1, ਆਕਾਰ(buf1), ")");
        type_ਮੰਜ਼ਿਲ_str(buf, buf_ਮਾਪ, &s->type, buf1);
        ਜਾਓ no_var;
    ਹਾਲਤ VT_PTR:
        s = type->ref;
        ਜੇ (t & (VT_ARRAY|VT_VLA)) {
            ਜੇ (varstr && '*' == *varstr)
                snprintf(buf1, ਆਕਾਰ(buf1), "(%s)[%d]", varstr, s->c);
            ਨਹੀਂਤਾਂ
                snprintf(buf1, ਆਕਾਰ(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_ਮੰਜ਼ਿਲ_str(buf, buf_ਮਾਪ, &s->type, buf1);
            ਜਾਓ no_var;
        }
        pstrcpy(buf1, ਆਕਾਰ(buf1), "*");
        ਜੇ (t & VT_RESTRICT)
            pstrcat(buf1, ਆਕਾਰ(buf1), "restrict ");
        ਜੇ (t & VT_CONSTANT)
            pstrcat(buf1, ਆਕਾਰ(buf1), "const ");
        ਜੇ (t & VT_VOLATILE)
            pstrcat(buf1, ਆਕਾਰ(buf1), "volatile ");
        ਜੇ (varstr)
            pstrcat(buf1, ਆਕਾਰ(buf1), varstr);
        type_ਮੰਜ਼ਿਲ_str(buf, buf_ਮਾਪ, &s->type, buf1);
        ਜਾਓ no_var;
    }
    ਜੇ (varstr) {
        pstrcat(buf, buf_ਮਾਪ, " ");
        pstrcat(buf, buf_ਮਾਪ, varstr);
    }
 no_var: ;
}

ਸਥਿਰ ਖਾਲੀ type_incompatibility_error(CType* st, CType* dt, ਅਚਲ ਅੱਖਰ* fmt)
{
    ਅੱਖਰ buf1[256], buf2[256];
    type_ਮੰਜ਼ਿਲ_str(buf1, ਆਕਾਰ(buf1), st, ਨਿਰਾ);
    type_ਮੰਜ਼ਿਲ_str(buf2, ਆਕਾਰ(buf2), dt, ਨਿਰਾ);
    tcc_error(fmt, buf1, buf2);
}

ਸਥਿਰ ਖਾਲੀ type_incompatibility_warning(CType* st, CType* dt, ਅਚਲ ਅੱਖਰ* fmt)
{
    ਅੱਖਰ buf1[256], buf2[256];
    type_ਮੰਜ਼ਿਲ_str(buf1, ਆਕਾਰ(buf1), st, ਨਿਰਾ);
    type_ਮੰਜ਼ਿਲ_str(buf2, ਆਕਾਰ(buf2), dt, ਨਿਰਾ);
    tcc_warning(fmt, buf1, buf2);
}

ਸਥਿਰ ਪੂਰਨ pointed_ਮਾਪ(CType *type)
{
    ਪੂਰਨ align;
    ਵਾਪਸ type_ਮਾਪ(pointed_type(type), &align);
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ is_null_ਸੂਚਕ(SValue *p)
{
    ਜੇ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ਵਾਪਸ 0;
    ਵਾਪਸ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_ਮਾਪ == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ਸਥਿਰ ਪੂਰਨ is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ਜੇ (s1->f.func_call != s2->f.func_call)
        ਵਾਪਸ 0;
    ਜੇ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ਵਾਪਸ 0;
    ਲਈ (;;) {
        ਜੇ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ਵਾਪਸ 0;
        ਜੇ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ਵਾਪਸ 1;
        s1 = s1->ਅਗਲਾ;
        s2 = s2->ਅਗਲਾ;
        ਜੇ (!s1)
            ਵਾਪਸ !s2;
        ਜੇ (!s2)
            ਵਾਪਸ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ਸਥਿਰ ਪੂਰਨ compare_types(CType *type1, CType *type2, ਪੂਰਨ unqualified)
{
    ਪੂਰਨ bt1, t1, t2;

    ਜੇ (IS_ENUM(type1->t)) {
        ਜੇ (IS_ENUM(type2->t))
            ਵਾਪਸ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ਨਹੀਂਤਾਂ ਜੇ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ਜੇ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ਜੇ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ਜੇ (t1 != t2)
        ਵਾਪਸ 0;

    ਜੇ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ਵਾਪਸ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ਜੇ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ਜੇ (unqualified && (t1 & VT_ARRAY))
            ਵਾਪਸ compare_types(type1, type2, 1);
        ਵਾਪਸ is_compatible_types(type1, type2);
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_STRUCT) {
        ਵਾਪਸ (type1->ref == type2->ref);
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_FUNC) {
        ਵਾਪਸ is_compatible_func(type1, type2);
    } ਨਹੀਂਤਾਂ {
        ਵਾਪਸ 1;
    }
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CMP_OP 'C'
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਿਸਕਾਓ_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ਸਥਿਰ ਪੂਰਨ combine_types(CType *dest, SValue *op1, SValue *op2, ਪੂਰਨ op)
{
    CType *type1, *type2, type;
    ਪੂਰਨ t1, t2, bt1, bt2;
    ਪੂਰਨ ret = 1;

    /* for shifts, 'combine' only left operand */
    ਜੇ (op == ਖਿਸਕਾਓ_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ਨਿਰਾ;

    ਜੇ (bt1 == VT_VOID || bt2 == VT_VOID) {
        ਜੇ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_PTR || bt2 == VT_PTR) {
        ਜੇ (op == '+') {
          ਜੇ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ਨਹੀਂਤਾਂ ਜੇ (is_null_ਸੂਚਕ (op2)) type = *type1;
        ਨਹੀਂਤਾਂ ਜੇ (is_null_ਸੂਚਕ (op1)) type = *type2;
        ਨਹੀਂਤਾਂ ਜੇ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ਜੇ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ਨਹੀਂਤਾਂ ਜੇ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ਨਹੀਂਤਾਂ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            ਪੂਰਨ pbt1 = pt1->t & VT_BTYPE;
            ਪੂਰਨ pbt2 = pt2->t & VT_BTYPE;
            ਪੂਰਨ newquals, copied = 0;
            ਜੇ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ਜੇ (op != '?' && op != CMP_OP)
                  ret = 0;
                ਨਹੀਂਤਾਂ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ਜੇ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ਜੇ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ਜੇ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ਜੇ (!copied)
                      type.ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ਜੇ (op == CMP_OP)
          type.t = VT_ਮਾਪ_T;
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ਜੇ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ਨਹੀਂਤਾਂ ਜੇ (is_float(bt1) || is_float(bt2)) {
        ਜੇ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ਨਹੀਂਤਾਂ {
            type.t = VT_FLOAT;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ਜੇ (bt1 == VT_LLONG)
          type.t &= t1;
        ਜੇ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ਜੇ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ਨਹੀਂਤਾਂ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ਜੇ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ਜੇ (dest)
      *dest = type;
    ਵਾਪਸ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC ਖਾਲੀ gen_op(ਪੂਰਨ op)
{
    ਪੂਰਨ t1, t2, bt1, bt2, t;
    CType type1, combtype;
    ਪੂਰਨ op_class = op;

    ਜੇ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = ਖਿਸਕਾਓ_OP;
    ਨਹੀਂਤਾਂ ਜੇ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ਜੇ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ਜੇ (bt2 == VT_FUNC) {
	    mk_ਸੂਚਕ(&vtop->type);
	    gaddrof();
	}
	ਜੇ (bt1 == VT_FUNC) {
	    vswap();
	    mk_ਸੂਚਕ(&vtop->type);
	    gaddrof();
	    vswap();
	}
	ਜਾਓ redo;
    } ਨਹੀਂਤਾਂ ਜੇ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ਨਹੀਂਤਾਂ ਜੇ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        ਪੂਰਨ align;
        ਜੇ (op_class == CMP_OP)
            ਜਾਓ std_op;
        /* if both pointers, then it must be the '-' op */
        ਜੇ (bt1 == VT_PTR && bt2 == VT_PTR) {
            ਜੇ (op != '-')
                ਜਾਓ op_err;
            vpush_type_ਮਾਪ(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ਨਹੀਂਤਾਂ {
            /* exactly one pointer : must be '+' or '-'. */
            ਜੇ (op != '-' && op != '+')
                ਜਾਓ op_err;
            /* Put pointer as first operand */
            ਜੇ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ਜੇ PTR_ਮਾਪ == 4
            ਜੇ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#ਜੇ_ਅੰਤ
            type1 = vtop[-1].type;
            vpush_type_ਮਾਪ(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
            ਜੇ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ਜੇ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_ਜੋੜੋ();
            } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ਨਹੀਂਤਾਂ {
        /* floats can only be used for a few operations */
        ਜੇ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            ਜਾਓ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ਜੇ (op_class == ਖਿਸਕਾਓ_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ਜੇ (t & VT_UNSIGNED) {
            ਜੇ (op == TOK_SAR)
                op = TOK_SHR;
            ਨਹੀਂਤਾਂ ਜੇ (op == '/')
                op = TOK_UDIV;
            ਨਹੀਂਤਾਂ ਜੇ (op == '%')
                op = TOK_UMOD;
            ਨਹੀਂਤਾਂ ਜੇ (op == TOK_LT)
                op = TOK_ULT;
            ਨਹੀਂਤਾਂ ਜੇ (op == TOK_GT)
                op = TOK_UGT;
            ਨਹੀਂਤਾਂ ਜੇ (op == TOK_LE)
                op = TOK_ULE;
            ਨਹੀਂਤਾਂ ਜੇ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ਜੇ (is_float(t))
            gen_opif(op);
        ਨਹੀਂਤਾਂ
            gen_opic(op);
        ਜੇ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ਨਹੀਂਤਾਂ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ਜੇ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64 || defined TCC_ਨਿਸ਼ਾਨਾ_ARM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gen_cvt_itof1 gen_cvt_itof
#ਨਹੀਂਤਾਂ
/* generic itof for unsigned long long case */
ਸਥਿਰ ਖਾਲੀ gen_cvt_itof1(ਪੂਰਨ t)
{
    ਜੇ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ਜੇ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ਜੇ LDOUBLE_ਮਾਪ != 8
        ਨਹੀਂਤਾਂ ਜੇ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#ਜੇ_ਅੰਤ
        ਨਹੀਂਤਾਂ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ਨਹੀਂਤਾਂ {
        gen_cvt_itof(t);
    }
}
#ਜੇ_ਅੰਤ

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gen_cvt_ftoi1 gen_cvt_ftoi
#ਨਹੀਂਤਾਂ
/* generic ftoi for unsigned long long case */
ਸਥਿਰ ਖਾਲੀ gen_cvt_ftoi1(ਪੂਰਨ t)
{
    ਪੂਰਨ st;
    ਜੇ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ਜੇ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ਜੇ LDOUBLE_ਮਾਪ != 8
        ਨਹੀਂਤਾਂ ਜੇ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#ਜੇ_ਅੰਤ
        ਨਹੀਂਤਾਂ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ਨਹੀਂਤਾਂ {
        gen_cvt_ftoi(t);
    }
}
#ਜੇ_ਅੰਤ

/* special delayed cast for char/short */
ਸਥਿਰ ਖਾਲੀ force_charshort_cast(ਖਾਲੀ)
{
    ਪੂਰਨ sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    ਪੂਰਨ dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ਸਥਿਰ ਖਾਲੀ gen_cast_s(ਪੂਰਨ t)
{
    CType type;
    type.t = t;
    type.ref = ਨਿਰਾ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ਸਥਿਰ ਖਾਲੀ gen_cast(CType *type)
{
    ਪੂਰਨ sbt, dbt, sf, df, c;
    ਪੂਰਨ dbt_bt, sbt_bt, ds, ss, ਬਿੱਟ, trunc;

    /* special delayed cast for char/short */
    ਜੇ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ਜੇ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ਜੇ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ਜੇ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ਜੇ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ਜੇ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            ਜਾਓ ਪੂਰਾ;
        }
        ਜੇ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ਜੇ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ਜੇ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ਨਹੀਂਤਾਂ ਜੇ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ਜੇ (df) {
                ਜੇ (sbt_bt == VT_LLONG) {
                    ਜੇ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ਨਹੀਂਤਾਂ
                        vtop->c.ld = -(ਲੰਮਾ ਦੁੱਗਣਾ)-vtop->c.i;
                } ਨਹੀਂਤਾਂ ਜੇ(!sf) {
                    ਜੇ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ਨਹੀਂਤਾਂ
                        vtop->c.ld = -(ਲੰਮਾ ਦੁੱਗਣਾ)-(uint32_t)vtop->c.i;
                }

                ਜੇ (dbt == VT_FLOAT)
                    vtop->c.f = (ਦਸ਼ਮਲਵ)vtop->c.ld;
                ਨਹੀਂਤਾਂ ਜੇ (dbt == VT_DOUBLE)
                    vtop->c.d = (ਦੁੱਗਣਾ)vtop->c.ld;
            } ਨਹੀਂਤਾਂ ਜੇ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ਨਹੀਂਤਾਂ {
                ਜੇ(sf) {
                    ਜੇ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ਨਹੀਂਤਾਂ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ਨਹੀਂਤਾਂ ਜੇ (sbt_bt == VT_LLONG || (PTR_ਮਾਪ == 8 && sbt == VT_PTR))
                    ;
                ਨਹੀਂਤਾਂ ਜੇ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ਨਹੀਂਤਾਂ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ਜੇ (dbt_bt == VT_LLONG || (PTR_ਮਾਪ == 8 && dbt == VT_PTR))
                    ;
                ਨਹੀਂਤਾਂ ਜੇ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ਨਹੀਂਤਾਂ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ਜੇ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            ਜਾਓ ਪੂਰਾ;

        } ਨਹੀਂਤਾਂ ਜੇ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            ਜਾਓ ਪੂਰਾ;
        }

        /* cannot generate code for global or static initializers */
        ਜੇ (nocode_wanted & ਅੰਕੜੇ_ONLY_WANTED) {
            ਜੇ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            ਜਾਓ ਪੂਰਾ;
        }

        /* non constant case: generate code */
        ਜੇ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            ਜਾਓ ਪੂਰਾ;
        }

        ਜੇ (sf || df) {
            ਜੇ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ਨਹੀਂਤਾਂ ਜੇ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ਨਹੀਂਤਾਂ {
                /* convert fp to int */
                sbt = dbt;
                ਜੇ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                ਜਾਓ again; /* may need char/short cast */
            }
            ਜਾਓ ਪੂਰਾ;
        }

        ds = btype_ਮਾਪ(dbt_bt);
        ss = btype_ਮਾਪ(sbt_bt);
        ਜੇ (ds == 0 || ss == 0)
            ਜਾਓ error;

        /* same size and no sign conversion needed */
        ਜੇ (ds == ss && ds >= 4)
            ਜਾਓ ਪੂਰਾ;
        ਜੇ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ਜੇ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_ਮਾਪ == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOW_SUBTYPE_ACCESS 1

        ਜੇ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ਜੇ (ds <= ss)
                ਜਾਓ ਪੂਰਾ;
            /* ss <= 4 here */
            ਜੇ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                ਜਾਓ ਪੂਰਾ; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ਜੇ PTR_ਮਾਪ == 4
        ਜੇ (ds == 8) {
            /* generate high word */
            ਜੇ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ਨਹੀਂਤਾਂ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ਨਹੀਂਤਾਂ ਜੇ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#ਜਾਂਜੇ PTR_ਮਾਪ == 8
        ਜੇ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ਜੇ (sbt & VT_UNSIGNED) {
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ਨਹੀਂਤਾਂ
                ਜਾਓ ਪੂਰਾ;
#ਜੇ_ਅੰਤ
            } ਨਹੀਂਤਾਂ {
                gen_cvt_sxtw();
                ਜਾਓ ਪੂਰਾ;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ਨਹੀਂਤਾਂ ਜੇ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ {
            ss = 4;
        }
#ਜੇ_ਅੰਤ

        ਜੇ (ds >= ss)
            ਜਾਓ ਪੂਰਾ;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 || defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਜੇ (ss == 4) {
        gen_cvt_csti(dbt);
        ਜਾਓ ਪੂਰਾ;
    }
#ਜੇ_ਅੰਤ
        ਬਿੱਟ = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(ਬਿੱਟ);
        gen_op(TOK_SHL);
        vpushi(ਬਿੱਟ - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
ਪੂਰਾ:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC ਪੂਰਨ type_ਮਾਪ(CType *type, ਪੂਰਨ *a)
{
    Sym *s;
    ਪੂਰਨ bt;

    bt = type->t & VT_BTYPE;
    ਜੇ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ਵਾਪਸ s->c;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_PTR) {
        ਜੇ (type->t & VT_ARRAY) {
            ਪੂਰਨ ts;
            s = type->ref;
            ts = type_ਮਾਪ(&s->type, a);
            ਜੇ (s->c < 0)
                ਵਾਪਸ s->c;
            ਵਾਪਸ ts * s->c;
        } ਨਹੀਂਤਾਂ {
            *a = PTR_ਮਾਪ;
            ਵਾਪਸ PTR_ਮਾਪ;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ਵਾਪਸ -1; /* incomplete enum */
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ਵਾਪਸ LDOUBLE_ਮਾਪ;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_DOUBLE || bt == VT_LLONG) {
#ਜੇ (defined TCC_ਨਿਸ਼ਾਨਾ_I386 && !defined TCC_ਨਿਸ਼ਾਨਾ_PE) \
 || (defined TCC_ਨਿਸ਼ਾਨਾ_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ਨਹੀਂਤਾਂ
        *a = 8;
#ਜੇ_ਅੰਤ
        ਵਾਪਸ 8;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ਵਾਪਸ 4;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_SHORT) {
        *a = 2;
        ਵਾਪਸ 2;
    } ਨਹੀਂਤਾਂ ਜੇ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ਵਾਪਸ 16;
    } ਨਹੀਂਤਾਂ {
        /* char, void, function, _Bool */
        *a = 1;
        ਵਾਪਸ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ਸਥਿਰ ਖਾਲੀ vpush_type_ਮਾਪ(CType *type, ਪੂਰਨ *a)
{
    ਜੇ (type->t & VT_VLA) {
        type_ਮਾਪ(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ਨਹੀਂਤਾਂ {
        ਪੂਰਨ ਮਾਪ = type_ਮਾਪ(type, a);
        ਜੇ (ਮਾਪ < 0)
            tcc_error("unknown type size");
        vpushs(ਮਾਪ);
    }
}

/* return the pointed type of t */
ਸਥਿਰ ਸਤਰਅੰਦਰ CType *pointed_type(CType *type)
{
    ਵਾਪਸ &type->ref->type;
}

ਸਥਿਰ ਖਾਲੀ check_restrict_type(CType *type)
{
    ਜਦੋਂ ((type->t & VT_BTYPE) == VT_PTR) {
        ਜੇ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ਜੇ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ਸਥਿਰ ਪੂਰਨ type_qualifiers(CType *type)
{
    ਜਦੋਂ (type->t & VT_ARRAY)
        type = pointed_type(type);
    ਵਾਪਸ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC ਖਾਲੀ mk_ਸੂਚਕ(CType *type)
{
    Sym *s;
    s = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ਸਥਿਰ ਪੂਰਨ is_compatible_types(CType *type1, CType *type2)
{
    ਵਾਪਸ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ਸਥਿਰ ਪੂਰਨ is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ਵਾਪਸ compare_types(type1,type2,1);
}

ਸਥਿਰ ਖਾਲੀ cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ਸਥਿਰ ਖਾਲੀ verify_ਸੌਂਪੋ_cast(CType *dt)
{
    CType *st, *type1, *type2;
    ਪੂਰਨ dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ਜੇ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    ਚੋਣ(dbt) {
    ਹਾਲਤ VT_VOID:
        ਜੇ (sbt != dbt)
            tcc_error("assignment to void expression");
        ਰੋਕੋ;
    ਹਾਲਤ VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ਜੇ (is_null_ਸੂਚਕ(vtop))
            ਰੋਕੋ;
        /* accept implicit pointer to integer cast with warning */
        ਜੇ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            ਰੋਕੋ;
        }
        type1 = pointed_type(dt);
        ਜੇ (sbt == VT_PTR)
            type2 = pointed_type(st);
        ਨਹੀਂਤਾਂ ਜੇ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ਨਹੀਂਤਾਂ
            ਜਾਓ error;
        ਜੇ (is_compatible_types(type1, type2))
            ਰੋਕੋ;
        ਲਈ (qualwarn = lvl = 0;; ++lvl) {
            ਜੇ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ਜੇ (dbt != VT_PTR || sbt != VT_PTR)
                ਰੋਕੋ;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ਜੇ (!is_compatible_unqualified_types(type1, type2)) {
            ਜੇ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ਨਹੀਂਤਾਂ ਜੇ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ਨਹੀਂਤਾਂ {
                tcc_warning("assignment from incompatible pointer type");
                ਰੋਕੋ;
            }
        }
        ਜੇ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        ਰੋਕੋ;
    ਹਾਲਤ VT_BYTE:
    ਹਾਲਤ VT_SHORT:
    ਹਾਲਤ VT_INT:
    ਹਾਲਤ VT_LLONG:
        ਜੇ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ਨਹੀਂਤਾਂ ਜੇ (sbt == VT_STRUCT) {
            ਜਾਓ case_VT_STRUCT;
        }
        /* XXX: more tests */
        ਰੋਕੋ;
    ਹਾਲਤ VT_STRUCT:
    case_VT_STRUCT:
        ਜੇ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        ਰੋਕੋ;
    }
}

ਸਥਿਰ ਖਾਲੀ gen_ਸੌਂਪੋ_cast(CType *dt)
{
    verify_ਸੌਂਪੋ_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC ਖਾਲੀ vstore(ਖਾਲੀ)
{
    ਪੂਰਨ sbt, dbt, ft, r, ਮਾਪ, align, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2, ਦੋਆਧਾਰੀ_ਅੰਕ_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_ਸੌਂਪੋ_cast(&vtop[-1].type);

    ਜੇ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        ਮਾਪ = type_ਮਾਪ(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#ਜੇ_ਅੰਤ
        vtop->type.t = VT_PTR;
        gaddrof();
        /*ਸਰੋਤ*/
        vswap();
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (vtop->r & VT_MUSTBOUND)
            gbound();
#ਜੇ_ਅੰਤ
        vtop->type.t = VT_PTR;
        gaddrof();

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_NATIVE_STRUCT_COPY
        ਜੇ (1
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#ਜੇ_ਅੰਤ
            ) {
            gen_struct_copy(ਮਾਪ);
        } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
        {
            /* type size */
            vpushi(ਮਾਪ);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_EABI
            ਜੇ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ਨਹੀਂਤਾਂ ਜੇ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ਨਹੀਂਤਾਂ ਜੇ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        ਦੋਆਧਾਰੀ_ਅੰਕ_pos = ਦੋਆਧਾਰੀ_ਅੰਕ_POS(ft);
        ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_ਨਕਾਬ;

        ਜੇ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
        ਜੇ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ਜੇ (r == VT_STRUCT) {
            store_packed_bf(ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
        } ਨਹੀਂਤਾਂ {
            ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਨਕਾਬ = (1ULL << ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2) - 1;
            ਜੇ (dbt != VT_BOOL) {
                /* mask source */
                ਜੇ (dbt == VT_LLONG)
                    vpushll(ਨਕਾਬ);
                ਨਹੀਂਤਾਂ
                    vpushi((ਬਿਨਾਨਿਸ਼ਾਨੀ)ਨਕਾਬ);
                gen_op('&');
            }
            /* shift source */
            vpushi(ਦੋਆਧਾਰੀ_ਅੰਕ_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            ਜੇ (dbt == VT_LLONG)
                vpushll(~(ਨਕਾਬ << ਦੋਆਧਾਰੀ_ਅੰਕ_pos));
            ਨਹੀਂਤਾਂ
                vpushi(~((ਬਿਨਾਨਿਸ਼ਾਨੀ)ਨਕਾਬ << ਦੋਆਧਾਰੀ_ਅੰਕ_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ਨਹੀਂਤਾਂ ਜੇ (dbt == VT_VOID) {
        --vtop;
    } ਨਹੀਂਤਾਂ {
            /* optimize char/short casts */
            delayed_cast = 0;
            ਜੇ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ਜੇ ((vtop->r & VT_MUSTCAST)
                    && btype_ਮਾਪ(dbt) > btype_ਮਾਪ(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ਨਹੀਂਤਾਂ {
                gen_cast(&vtop[-1].type);
            }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
            /* bound check case */
            ਜੇ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#ਜੇ_ਅੰਤ
            gv(RC_TYPE(dbt)); /* generate value */

            ਜੇ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ਜੇ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ਨਿਰਾ;
                ਲੱਦੋ(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ਜੇ (USING_TWO_ਸ਼ਬਦ(dbt)) {
                ਪੂਰਨ ਲੱਦੋ_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = ਲੱਦੋ_type;
                store(r, vtop - 1);
                vswap();
                incr_ਵਿੱਥ(PTR_ਮਾਪ);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ਨਹੀਂਤਾਂ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC ਖਾਲੀ inc(ਪੂਰਨ post, ਪੂਰਨ c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ਜੇ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ਜੇ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
    /* read the string */
    ਜੇ (tok != TOK_STR)
        expect(ਸੁਨੇਹਾ);
    cstr_reset(&initstr);
    ਜਦੋਂ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.ਅੰਕੜੇ, -1);
        ਅਗਲਾ();
    }
    cstr_ccat(&initstr, '\0');
    ਵਾਪਸ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC ਪੂਰਨ exact_log2p1(ਪੂਰਨ i)
{
  ਪੂਰਨ ret;
  ਜੇ (!i)
    ਵਾਪਸ 0;
  ਲਈ (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ਜੇ (i >= 1 << 4)
    ret += 4, i >>= 4;
  ਜੇ (i >= 1 << 2)
    ret += 2, i >>= 2;
  ਜੇ (i >= 1 << 1)
    ret++;
  ਵਾਪਸ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ਸਥਿਰ ਖਾਲੀ parse_attribute(AttributeDef *ad)
{
    ਪੂਰਨ t, n;
    ਅੱਖਰ *astr;
    AttributeDef ad_tmp;
    
redo:
    ਜੇ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ਵਾਪਸ;
    ਜੇ (ਨਿਰਾ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    ਅਗਲਾ();
    skip('(');
    skip('(');
    ਜਦੋਂ (tok != ')') {
        ਜੇ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        ਅਗਲਾ();
        ਚੋਣ(t) {
	ਹਾਲਤ TOK_CLEANUP1:
	ਹਾਲਤ TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_ਲੱਭੋ(tok);
	    ਜੇ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ਨਹੀਂਤਾਂ ਜੇ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    ਅਗਲਾ();
            skip(')');
	    ਰੋਕੋ;
	}
        ਹਾਲਤ TOK_CONSTRUCTOR1:
        ਹਾਲਤ TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_DESTRUCTOR1:
        ਹਾਲਤ TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ALWAYS_INLINE1:
        ਹਾਲਤ TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_SECTION1:
        ਹਾਲਤ TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->ਅੰਕੜੇ;
            n = tcc_state->nb_sections;
            ad->section = ਲੱਭੋ_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ALIAS1:
        ਹਾਲਤ TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->ਅੰਕੜੇ;
            /* save string as token, for later */
            ad->alias_ਨਿਸ਼ਾਨਾ = tok_alloc_const(astr);
            skip(')');
            ਰੋਕੋ;
	ਹਾਲਤ TOK_VISIBILITY1:
	ਹਾਲਤ TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->ਅੰਕੜੇ;
	    ਜੇ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_ਅੰਦਰੂਨੀ;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ਨਹੀਂਤਾਂ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ALIGNED1:
        ਹਾਲਤ TOK_ALIGNED2:
            ਜੇ (tok == '(') {
                ਅਗਲਾ();
                n = ਵਿਅੰਜਕ_const();
                ਜੇ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ਨਹੀਂਤਾਂ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ਜੇ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_PACKED1:
        ਹਾਲਤ TOK_PACKED2:
            ad->a.packed = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_WEAK1:
        ਹਾਲਤ TOK_WEAK2:
            ad->a.weak = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NODEBUG1:
        ਹਾਲਤ TOK_NODEBUG2:
            ad->a.nodebug = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_USED1:
        ਹਾਲਤ TOK_USED2:
        ਹਾਲਤ TOK_UNUSED1:
        ਹਾਲਤ TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            ਰੋਕੋ;
        ਹਾਲਤ TOK_CONST1:
        ਹਾਲਤ TOK_CONST2:
        ਹਾਲਤ TOK_CONST3:
        ਹਾਲਤ TOK_PURE1:
        ਹਾਲਤ TOK_PURE2:
	    /* ignored */
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NOINLINE:
	    /* ignored */
	    ਰੋਕੋ;
        ਹਾਲਤ TOK_FORMAT1:
        ਹਾਲਤ TOK_FORMAT2:
	    /* ignored */
            ਜਾਓ skip_param;
        ਹਾਲਤ TOK_NORETURN1:
        ਹਾਲਤ TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_CDECL1:
        ਹਾਲਤ TOK_CDECL2:
        ਹਾਲਤ TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_STDCALL1:
        ਹਾਲਤ TOK_STDCALL2:
        ਹਾਲਤ TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
        ਹਾਲਤ TOK_REGPARM1:
        ਹਾਲਤ TOK_REGPARM2:
            skip('(');
            n = ਵਿਅੰਜਕ_const();
            ਜੇ (n > 3) 
                n = 3;
            ਨਹੀਂਤਾਂ ਜੇ (n < 0)
                n = 0;
            ਜੇ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            ਰੋਕੋ;
        ਹਾਲਤ TOK_FASTCALL1:
        ਹਾਲਤ TOK_FASTCALL2:
        ਹਾਲਤ TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_THISCALL1:
        ਹਾਲਤ TOK_THISCALL2:
        ਹਾਲਤ TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            ਰੋਕੋ;
#ਜੇ_ਅੰਤ
        ਹਾਲਤ TOK_ਬਹੁਲਕ:
            skip('(');
            ਚੋਣ(tok) {
                ਹਾਲਤ TOK_ਬਹੁਲਕ_DI:
                    ad->attr_ਬਹੁਲਕ = VT_LLONG + 1;
                    ਰੋਕੋ;
                ਹਾਲਤ TOK_ਬਹੁਲਕ_QI:
                    ad->attr_ਬਹੁਲਕ = VT_BYTE + 1;
                    ਰੋਕੋ;
                ਹਾਲਤ TOK_ਬਹੁਲਕ_HI:
                    ad->attr_ਬਹੁਲਕ = VT_SHORT + 1;
                    ਰੋਕੋ;
                ਹਾਲਤ TOK_ਬਹੁਲਕ_SI:
                ਹਾਲਤ TOK_ਬਹੁਲਕ_ਸ਼ਬਦ:
                    ad->attr_ਬਹੁਲਕ = VT_INT + 1;
                    ਰੋਕੋ;
                ਮੂਲ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ਨਿਰਾ));
                    ਰੋਕੋ;
            }
            ਅਗਲਾ();
            skip(')');
            ਰੋਕੋ;
        ਹਾਲਤ TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NODECORATE:
            ad->a.nodecorate = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ਨਿਰਾ));
            /* skip parameters */
skip_param:
            ਜੇ (tok == '(') {
                ਪੂਰਨ parenthesis = 0;
                ਕਰੋ {
                    ਜੇ (tok == '(') 
                        parenthesis++;
                    ਨਹੀਂਤਾਂ ਜੇ (tok == ')') 
                        parenthesis--;
                    ਅਗਲਾ();
                } ਜਦੋਂ (parenthesis && tok != -1);
            }
            ਰੋਕੋ;
        }
        ਜੇ (tok != ',')
            ਰੋਕੋ;
        ਅਗਲਾ();
    }
    skip(')');
    skip(')');
    ਜਾਓ redo;
}

ਸਥਿਰ Sym * ਲੱਭੋ_ਖੇਤਰ (CType *type, ਪੂਰਨ v, ਪੂਰਨ *cumofs)
{
    Sym *s = type->ref;
    ਪੂਰਨ v1 = v | SYM_ਖੇਤਰ;
    ਜੇ (!(v & SYM_ਖੇਤਰ)) { /* top-level call */
        ਜੇ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ਜੇ (v < TOK_UIDENT)
            expect("field name");
        ਜੇ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ਜਦੋਂ ((s = s->ਅਗਲਾ) != ਨਿਰਾ) {
        ਜੇ (s->v == v1) {
            *cumofs = s->c;
            ਵਾਪਸ s;
        }
        ਜੇ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_ਪਹਿਲਾ_ANOM | SYM_ਖੇਤਰ)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = ਲੱਭੋ_ਖੇਤਰ (&s->type, v1, cumofs);
            ਜੇ (ret) {
                *cumofs += s->c;
                ਵਾਪਸ ret;
            }
        }
    }
    ਜੇ (!(v & SYM_ਖੇਤਰ))
        tcc_error("field not found: %s", get_tok_str(v, ਨਿਰਾ));
    ਵਾਪਸ s;
}

ਸਥਿਰ ਖਾਲੀ check_fields (CType *type, ਪੂਰਨ check)
{
    Sym *s = type->ref;

    ਜਦੋਂ ((s = s->ਅਗਲਾ) != ਨਿਰਾ) {
        ਪੂਰਨ v = s->v & ~SYM_ਖੇਤਰ;
        ਜੇ (v < SYM_ਪਹਿਲਾ_ANOM) {
            TokenSym *ts = ਸਾਰਣੀ_ident[v - TOK_IDENT];
            ਜੇ (check && (ts->tok & SYM_ਖੇਤਰ))
                tcc_error("duplicate member '%s'", get_tok_str(v, ਨਿਰਾ));
            ts->tok ^= SYM_ਖੇਤਰ;
        } ਨਹੀਂਤਾਂ ਜੇ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ਸਥਿਰ ਖਾਲੀ struct_layout(CType *type, AttributeDef *ad)
{
    ਪੂਰਨ ਮਾਪ, align, maxalign, ਵਿੱਥ, c, ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
    ਪੂਰਨ packed, a, bt, prevbt, prev_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ;
    ਪੂਰਨ pcc = !tcc_state->ms_bitfields;
    ਪੂਰਨ pragma_pack = *tcc_state->pack_ਢੇਰ_ptr;
    Sym *f;

    maxalign = 1;
    ਵਿੱਥ = 0;
    c = 0;
    ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ = 0;

//#define BF_DEBUG

    ਲਈ (f = type->ref->ਅਗਲਾ; f; f = f->ਅਗਲਾ) {
        ਜੇ (f->type.t & VT_BITFIELD)
            ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(f->type.t);
        ਨਹੀਂਤਾਂ
            ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = -1;
        ਮਾਪ = type_ਮਾਪ(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ਜੇ (pcc && ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ਨਹੀਂਤਾਂ {
            /* in pcc mode, attribute packed overrides if set. */
            ਜੇ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ਜੇ (pragma_pack) {
                packed = 1;
                ਜੇ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ਜੇ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ਜੇ (a)
            align = a;

        ਜੇ (type->ref->type.t == VT_UNION) {
	    ਜੇ (pcc && ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 >= 0)
	        ਮਾਪ = (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 + 7) >> 3;
	    ਵਿੱਥ = 0;
	    ਜੇ (ਮਾਪ > c)
	        c = ਮਾਪ;

	} ਨਹੀਂਤਾਂ ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 < 0) {
            ਜੇ (pcc)
                c += (ਦੋਆਧਾਰੀ_ਅੰਕ_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    ਵਿੱਥ = c;
	    ਜੇ (ਮਾਪ > 0)
	        c += ਮਾਪ;
	    ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ = 0;

	} ਨਹੀਂਤਾਂ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ਜੇ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 0) {
            new_ਖੇਤਰ:
		    c = (c + ((ਦੋਆਧਾਰੀ_ਅੰਕ_pos + 7) >> 3) + align - 1) & -align;
		    ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0;
                } ਨਹੀਂਤਾਂ ਜੇ (f->a.aligned) {
                    ਜਾਓ new_ਖੇਤਰ;
                } ਨਹੀਂਤਾਂ ਜੇ (!packed) {
                    ਪੂਰਨ a8 = align * 8;
	            ਪੂਰਨ ofs = ((c * 8 + ਦੋਆਧਾਰੀ_ਅੰਕ_pos) % a8 + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 + a8 - 1) / a8;
                    ਜੇ (ofs > ਮਾਪ / align)
                        ਜਾਓ new_ਖੇਤਰ;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ਜੇ (ਮਾਪ == 8 && ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, ਮਾਪ = 4;

                ਜਦੋਂ (ਦੋਆਧਾਰੀ_ਅੰਕ_pos >= align * 8)
                    c += align, ਦੋਆਧਾਰੀ_ਅੰਕ_pos -= align * 8;
                ਵਿੱਥ = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ਜੇ (f->v & SYM_ਪਹਿਲਾ_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ਨਹੀਂਤਾਂ {
		bt = f->type.t & VT_BTYPE;
		ਜੇ ((ਦੋਆਧਾਰੀ_ਅੰਕ_pos + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 > ਮਾਪ * 8)
                    || (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    ਵਿੱਥ = c;
		    ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 || prev_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ)
		        c += ਮਾਪ;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ਖਿਸਕਾਓ))
		        | (ਦੋਆਧਾਰੀ_ਅੰਕ_pos << VT_STRUCT_ਖਿਸਕਾਓ);
	    ਦੋਆਧਾਰੀ_ਅੰਕ_pos += ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
	}
	ਜੇ (align > maxalign)
	    maxalign = align;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BF_DEBUG
	ਲਿਖੋ("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_ਖੇਤਰ, ਨਿਰਾ), ਵਿੱਥ, ਮਾਪ, align);
	ਜੇ (f->type.t & VT_BITFIELD) {
	    ਲਿਖੋ(" pos %-2d bits %-2d",
                    ਦੋਆਧਾਰੀ_ਅੰਕ_POS(f->type.t),
                    ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(f->type.t)
                    );
	}
	ਲਿਖੋ("\n");
#ਜੇ_ਅੰਤ

        f->c = ਵਿੱਥ;
	f->r = 0;
    }

    ਜੇ (pcc)
        c += (ਦੋਆਧਾਰੀ_ਅੰਕ_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ਜੇ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ਜੇ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ਜੇ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BF_DEBUG
    ਲਿਖੋ("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#ਜੇ_ਅੰਤ

    /* check whether we can access bitfields by their type */
    ਲਈ (f = type->ref->ਅਗਲਾ; f; f = f->ਅਗਲਾ) {
        ਪੂਰਨ s, px, cx, c0;
        CType t;

        ਜੇ (0 == (f->type.t & VT_BITFIELD))
            ਜਾਰੀ;
        f->type.ref = f;
        f->auxtype = -1;
        ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(f->type.t);
        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 0)
            ਜਾਰੀ;
        ਦੋਆਧਾਰੀ_ਅੰਕ_pos = ਦੋਆਧਾਰੀ_ਅੰਕ_POS(f->type.t);
        ਮਾਪ = type_ਮਾਪ(&f->type, &align);

        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_pos + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 <= ਮਾਪ * 8 && f->c + ਮਾਪ <= c
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
            && !(f->c & (align - 1))
#ਜੇ_ਅੰਤ
            )
            ਜਾਰੀ;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        ਲਈ (;;) {
            px = f->c * 8 + ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ਜੇ (c0 == cx)
                ਰੋਕੋ;
            s = (px + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 + 7) >> 3;
            ਜੇ (s > 4) {
                t.t = VT_LLONG;
            } ਨਹੀਂਤਾਂ ਜੇ (s > 2) {
                t.t = VT_INT;
            } ਨਹੀਂਤਾਂ ਜੇ (s > 1) {
                t.t = VT_SHORT;
            } ਨਹੀਂਤਾਂ {
                t.t = VT_BYTE;
            }
            s = type_ਮਾਪ(&t, &align);
            c0 = cx;
        }

        ਜੇ (px + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 <= s * 8 && cx + s <= c
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
            && !(cx & (align - 1))
#ਜੇ_ਅੰਤ
            ) {
            /* update offset and bit position */
            f->c = cx;
            ਦੋਆਧਾਰੀ_ਅੰਕ_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ਖਿਸਕਾਓ))
		        | (ਦੋਆਧਾਰੀ_ਅੰਕ_pos << VT_STRUCT_ਖਿਸਕਾਓ);
            ਜੇ (s != ਮਾਪ)
                f->auxtype = t.t;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BF_DEBUG
            ਲਿਖੋ("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_ਖੇਤਰ, ਨਿਰਾ),
                cx, s, align, px, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2);
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BF_DEBUG
            ਲਿਖੋ("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_ਖੇਤਰ, ਨਿਰਾ));
#ਜੇ_ਅੰਤ
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ਸਥਿਰ ਪੂਰਨ ਵਿੱਚ_range(ਲੰਮਾ ਲੰਮਾ n, ਪੂਰਨ t)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ m = (1ULL << (btype_ਮਾਪ(t & VT_BTYPE) * 8 - 1)) - 1;
    ਜੇ (t & VT_UNSIGNED)
        ਵਾਪਸ n <= (m << 1) + 1;
    ਵਾਪਸ n >= -(ਲੰਮਾ ਲੰਮਾ)m - 1 && n <= (ਲੰਮਾ ਲੰਮਾ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ਸਥਿਰ ਖਾਲੀ struct_decl(CType *type, ਪੂਰਨ u)
{
    ਪੂਰਨ v, c, ਮਾਪ, align, flexible;
    ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, ਆਕਾਰ ad);
    ਅਗਲਾ();
    parse_attribute(&ad);

    v = 0;
    ਜੇ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, ਅਗਲਾ();

    bt = ut = 0;
    ਜੇ (u == VT_ENUM) {
        ut = VT_INT;
        ਜੇ (tok == ':') { /* C2x enum : <type> ... */
            ਅਗਲਾ();
            ਜੇ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ਜੇ (v) {
        /* struct already defined ? return it */
        s = struct_ਲੱਭੋ(v);
        ਜੇ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ਜੇ (u == s->type.t)
                ਜਾਓ do_decl;
            ਜੇ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                ਜਾਓ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ਨਿਰਾ));
        }
    } ਨਹੀਂਤਾਂ {
        ਜੇ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ਨਿਰਾ;
    /* we put an undefined size for struct/union */
    s = sym_ਧੱਕੋ(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ਜੇ (tok == '{') {
        ਅਗਲਾ();
        ਜੇ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->ਅਗਲਾ;
        ਜੇ (u == VT_ENUM) {
            ਲੰਮਾ ਲੰਮਾ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ਜੇ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            ਲਈ(;;) {
                v = tok;
                ਜੇ (v < TOK_UIDENT)
                    expect("identifier");
                ਅਗਲਾ();
                ਜੇ (tok == '=') {
                    ਅਗਲਾ();
		    ll = ਵਿਅੰਜਕ_const64();
                }
                ਜੇ (bt && !ਵਿੱਚ_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ਨਿਰਾ));
                ss = sym_ਧੱਕੋ(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->ਅਗਲਾ;
                ਜੇ (ll < nl)
                    nl = ll;
                ਜੇ (ll > pl)
                    pl = ll;
                ਜੇ (tok != ',')
                    ਰੋਕੋ;
                ਅਗਲਾ();
                ll++;
                /* NOTE: we accept a trailing comma */
                ਜੇ (tok == '}')
                    ਰੋਕੋ;
            }
            skip('}');

            ਜੇ (bt) {
                t.t = bt;
                s->c = 2;
                ਜਾਓ enum_ਪੂਰਾ;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ਜੇ (nl >= 0) {
                ਜੇ (pl != (ਬਿਨਾਨਿਸ਼ਾਨੀ)pl)
                    t.t = (LONG_ਮਾਪ==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ਨਹੀਂਤਾਂ ਜੇ (pl != (ਪੂਰਨ)pl || nl != (ਪੂਰਨ)nl)
                t.t = (LONG_ਮਾਪ==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            ਲਈ (ss = s->ਅਗਲਾ; ss; ss = ss->ਅਗਲਾ) {
                ll = ss->enum_val;
                ਜੇ (ll == (ਪੂਰਨ)ll) /* default is int if it fits */
                    ਜਾਰੀ;
                ਜੇ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ਜੇ (ll == (ਬਿਨਾਨਿਸ਼ਾਨੀ)ll)
                        ਜਾਰੀ;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_ਮਾਪ==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_ਪੂਰਾ:
            s->type.t = type->t = t.t | VT_ENUM;

        } ਨਹੀਂਤਾਂ {
            c = 0;
            flexible = 0;
            ਜਦੋਂ (tok != '}') {
                ਜੇ (!parse_btype(&btype, &ad1, 0)) {
                    ਜੇ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ਜਾਰੀ;
                    }
		    skip(';');
		    ਜਾਰੀ;
		}
                ਜਦੋਂ (1) {
		    ਜੇ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ਨਿਰਾ));
                    ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = -1;
                    v = 0;
                    type1 = btype;
                    ਜੇ (tok != ':') {
			ਜੇ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_ਸਿੱਧਾ);
                        ਜੇ (v == 0) {
                    	    ਜੇ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ਨਹੀਂਤਾਂ {
				ਪੂਰਨ v = btype.ref->v;
				ਜੇ ((v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM) {
				    ਜੇ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ਜੇ (type_ਮਾਪ(&type1, &align) < 0) {
			    ਜੇ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ਨਹੀਂਤਾਂ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ਨਿਰਾ));
                        }
                        ਜੇ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ਨਿਰਾ));
                    }
                    ਜੇ (tok == ':') {
                        ਅਗਲਾ();
                        ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਵਿਅੰਜਕ_const();
                        /* XXX: handle v = 0 case for messages */
                        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ਨਿਰਾ));
                        ਜੇ (v && ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ਨਿਰਾ));
			parse_attribute(&ad1);
                    }
                    ਮਾਪ = type_ਮਾਪ(&type1, &align);
                    ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ਜੇ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = ਮਾਪ * 8;
                        ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ਨਿਰਾ));
                        } ਨਹੀਂਤਾਂ ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == bsize
				    && !*tcc_state->pack_ਢੇਰ_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ਨਹੀਂਤਾਂ ਜੇ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 == 64) {
                            tcc_error("field width 64 not implemented");
                        } ਨਹੀਂਤਾਂ {
                            type1.t = (type1.t & ~VT_STRUCT_ਨਕਾਬ)
                                | VT_BITFIELD
                                | ((ਬਿਨਾਨਿਸ਼ਾਨੀ)ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 << (VT_STRUCT_ਖਿਸਕਾਓ + 6));
                        }
                    }
                    ਜੇ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ਜੇ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 >= 0)) {
		        v = anon_sym++;
		    }
                    ਜੇ (v) {
                        ss = sym_ਧੱਕੋ(v | SYM_ਖੇਤਰ, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->ਅਗਲਾ;
                    }
                    ਜੇ (tok == ';' || tok == TOK_EOF)
                        ਰੋਕੋ;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ਜੇ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ਜੇ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ਸਥਿਰ ਖਾਲੀ sym_ਮੰਜ਼ਿਲ_attr(AttributeDef *ad, Sym *s)
{
    ਮਿਲਾਓ_symattr(&ad->a, &s->a);
    ਮਿਲਾਓ_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ਸਥਿਰ ਖਾਲੀ parse_btype_qualify(CType *type, ਪੂਰਨ qualifiers)
{
    ਜਦੋਂ (type->t & VT_ARRAY) {
        type->ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ਜੇ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ਸਥਿਰ ਪੂਰਨ parse_btype(CType *type, AttributeDef *ad, ਪੂਰਨ ignore_label)
{
    ਪੂਰਨ t, u, bt, st, type_ਮਿਲਿਆ, typespec_ਮਿਲਿਆ, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, ਆਕਾਰ(AttributeDef));
    type_ਮਿਲਿਆ = 0;
    typespec_ਮਿਲਿਆ = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ਨਿਰਾ;

    ਜਦੋਂ(1) {
        ਚੋਣ(tok) {
        ਹਾਲਤ TOK_EXTENSION:
            /* currently, we really ignore extension */
            ਅਗਲਾ();
            ਜਾਰੀ;

            /* basic types */
        ਹਾਲਤ TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            ਅਗਲਾ();
        basic_type1:
            ਜੇ (u == VT_SHORT || u == VT_LONG) {
                ਜੇ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ਨਹੀਂਤਾਂ {
                ਜੇ (bt != -1 || (st != -1 && u != VT_INT))
                    ਜਾਓ tmbt;
                ਜੇ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    ਜਾਓ tmbt;
                bt = u;
            }
            ਜੇ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_ਮਿਲਿਆ = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_VOID:
            u = VT_VOID;
            ਜਾਓ basic_type;
        ਹਾਲਤ TOK_SHORT:
            u = VT_SHORT;
            ਜਾਓ basic_type;
        ਹਾਲਤ TOK_INT:
            u = VT_INT;
            ਜਾਓ basic_type;
        ਹਾਲਤ TOK_ALIGNAS:
            { ਪੂਰਨ n;
              AttributeDef ad1;
              ਅਗਲਾ();
              skip('(');
              memset(&ad1, 0, ਆਕਾਰ(AttributeDef));
              ਜੇ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ਜੇ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ਨਹੀਂਤਾਂ
                    type_ਮਾਪ(&type1, &n);
              } ਨਹੀਂਤਾਂ {
                  n = ਵਿਅੰਜਕ_const();
                  ਜੇ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ਜਾਰੀ;
        ਹਾਲਤ TOK_LONG:
            ਜੇ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ਨਹੀਂਤਾਂ ਜੇ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ਨਹੀਂਤਾਂ {
                u = VT_LONG;
                ਜਾਓ basic_type;
            }
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_BOOL:
            u = VT_BOOL;
            ਜਾਓ basic_type;
        ਹਾਲਤ TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        ਹਾਲਤ TOK_FLOAT:
            u = VT_FLOAT;
            ਜਾਓ basic_type;
        ਹਾਲਤ TOK_DOUBLE:
            ਜੇ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ਨਹੀਂਤਾਂ {
                u = VT_DOUBLE;
                ਜਾਓ basic_type;
            }
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            ਜਾਓ basic_type1;
        ਹਾਲਤ TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            ਜਾਓ basic_type2;
        ਹਾਲਤ TOK_UNION:
            struct_decl(&type1, VT_UNION);
            ਜਾਓ basic_type2;

            /* type modifiers */
        ਹਾਲਤ TOK__Atomic:
            ਅਗਲਾ();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ਜੇ (tok == '(') {
                parse_ਵਿਅੰਜਕ_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ਜੇ (type1.ref)
                    sym_ਮੰਜ਼ਿਲ_attr(ad, type1.ref);
                ਜਾਓ basic_type2;
            }
            ਰੋਕੋ;
        ਹਾਲਤ TOK_CONST1:
        ਹਾਲਤ TOK_CONST2:
        ਹਾਲਤ TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_VOLATILE1:
        ਹਾਲਤ TOK_VOLATILE2:
        ਹਾਲਤ TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_SIGNED1:
        ਹਾਲਤ TOK_SIGNED2:
        ਹਾਲਤ TOK_SIGNED3:
            ਜੇ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            ਅਗਲਾ();
            typespec_ਮਿਲਿਆ = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_RESTRICT1:
        ਹਾਲਤ TOK_RESTRICT2:
        ਹਾਲਤ TOK_RESTRICT3:
            t |= VT_RESTRICT;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ਰਜਿਸਟਰ:
        ਹਾਲਤ TOK_AUTO:
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_UNSIGNED:
            ਜੇ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            ਅਗਲਾ();
            typespec_ਮਿਲਿਆ = 1;
            ਰੋਕੋ;

            /* storage */
        ਹਾਲਤ TOK_EXTERN:
            g = VT_EXTERN;
            ਜਾਓ storage;
        ਹਾਲਤ TOK_STATIC:
            g = VT_STATIC;
            ਜਾਓ storage;
        ਹਾਲਤ TOK_TYPEDEF:
            g = VT_TYPEDEF;
            ਜਾਓ storage;
       storage:
            ਜੇ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_INLINE1:
        ਹਾਲਤ TOK_INLINE2:
        ਹਾਲਤ TOK_INLINE3:
            t |= VT_INLINE;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਹਾਲਤ TOK_NORETURN3:
            ਅਗਲਾ();
            ad->f.func_noreturn = 1;
            ਰੋਕੋ;
            /* GNUC attribute */
        ਹਾਲਤ TOK_ATTRIBUTE1:
        ਹਾਲਤ TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ਜੇ (ad->attr_ਬਹੁਲਕ) {
                u = ad->attr_ਬਹੁਲਕ -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ਜਾਰੀ;
            /* GNUC typeof */
        ਹਾਲਤ TOK_TYPEOF1:
        ਹਾਲਤ TOK_TYPEOF2:
        ਹਾਲਤ TOK_TYPEOF3:
            ਅਗਲਾ();
            parse_ਵਿਅੰਜਕ_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ਜੇ (type1.ref) {
                sym_ਮੰਜ਼ਿਲ_attr(ad, type1.ref);
                ਜੇ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            ਜਾਓ basic_type2;
        ਹਾਲਤ TOK_THREAD_LOCAL:
        ਹਾਲਤ TOK___thread:
            ਜੇ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            ਅਗਲਾ();
            ਰੋਕੋ;
        ਮੂਲ:
            ਜੇ (typespec_ਮਿਲਿਆ)
                ਜਾਓ the_ਸਿਰਾ;
            s = sym_ਲੱਭੋ(tok);
            ਜੇ (!s || !(s->type.t & VT_TYPEDEF))
                ਜਾਓ the_ਸਿਰਾ;

            n = tok, ਅਗਲਾ();
            ਜੇ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                ਜਾਓ the_ਸਿਰਾ;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ਜੇ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ਜੇ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_ਮੰਜ਼ਿਲ_attr(ad, s);
            typespec_ਮਿਲਿਆ = 1;
            st = bt = -2;
            ਰੋਕੋ;
        }
        type_ਮਿਲਿਆ = 1;
    }
the_ਸਿਰਾ:
    ਜੇ (tcc_state->char_is_unsigned) {
        ਜੇ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ਜੇ (bt == VT_LONG)
        t |= LONG_ਮਾਪ == 8 ? VT_LLONG : VT_INT;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_USING_DOUBLE_FOR_LDOUBLE
    ਜੇ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#ਜੇ_ਅੰਤ
    type->t = t;
    check_restrict_type(type);
    ਵਾਪਸ type_ਮਿਲਿਆ;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ਜੇ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_ਸੂਚਕ(pt);
    }
}

/* apply the conversions required for an expression value */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ convert_ਵਿਅੰਜਕ_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(ਖਾਲੀ)
{
    skip('(');
    ਵਾਪਸ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ਸਥਿਰ ਪੂਰਨ asm_label_instr(ਖਾਲੀ)
{
    ਪੂਰਨ v;
    ਅੱਖਰ *astr;

    ਅਗਲਾ();
    astr = parse_asm_str()->ਅੰਕੜੇ;
    skip(')');
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਿਖੋ("asm_alias: \"%s\"\n", astr);
#ਜੇ_ਅੰਤ
    v = tok_alloc_const(astr);
    ਵਾਪਸ v;
}

ਸਥਿਰ ਪੂਰਨ post_type(CType *type, AttributeDef *ad, ਪੂਰਨ storage, ਪੂਰਨ td)
{
    ਪੂਰਨ n, l, t1, arg_ਮਾਪ, align;
    Sym **plast, *s, *ਪਹਿਲਾ, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ਨਿਰਾ;
    ਪੂਰਨ *vla_array_str = ਨਿਰਾ;

    ਜੇ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        ਅਗਲਾ();
	ਜੇ (TYPE_ਸਿੱਧਾ == (td & (TYPE_ਸਿੱਧਾ|TYPE_ABSTRACT)))
	  ਵਾਪਸ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ਢੇਰ ? &local_ਢੇਰ : &global_ਢੇਰ;
        ++local_scope;
        sr = sym_push2(ps, SYM_ਖੇਤਰ, 0, 0);

	ਜੇ (tok == ')')
	  l = 0;
	ਨਹੀਂਤਾਂ ਜੇ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ਨਹੀਂਤਾਂ ਜੇ (td & (TYPE_ਸਿੱਧਾ|TYPE_ABSTRACT)) {
            sym_ਕੱਢੋ(ps, sr->prev, 0);
            --local_scope;
	    ਮਿਲਾਓ_attr (ad, &ad1);
	    ਵਾਪਸ 0;
	} ਨਹੀਂਤਾਂ
	  l = FUNC_OLD;

        ਪਹਿਲਾ = ਨਿਰਾ;
        plast = &ਪਹਿਲਾ;
        arg_ਮਾਪ = 0;
        ਜੇ (l) {
            ਲਈ(;;) {
                /* read param name and compute offset */
                ਜੇ (l != FUNC_OLD) {
                    ਜੇ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        ਰੋਕੋ;
                    type_decl(&pt, &ad1, &n, TYPE_ਸਿੱਧਾ | TYPE_ABSTRACT | TYPE_PARAM);
                    ਜੇ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ਜੇ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_ਖੇਤਰ;
                } ਨਹੀਂਤਾਂ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ਨਿਰਾ;
                    ਅਗਲਾ();
                }
                ਜੇ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_ਮਾਪ += (type_ਮਾਪ(&pt, &align) + PTR_ਮਾਪ - 1) / PTR_ਮਾਪ;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ਧੱਕੋ(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->ਅਗਲਾ;
                ਜੇ (tok == ')')
                    ਰੋਕੋ;
                skip(',');
                ਜੇ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    ਅਗਲਾ();
                    ਰੋਕੋ;
                }
		ਜੇ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ਨਹੀਂਤਾਂ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ਜੇ (tok == '[') {
            ਅਗਲਾ();
            skip(']'); /* only handle simple "[]" */
            mk_ਸੂਚਕ(type);
        }
        ad->f.func_ਦਲੀਲਾਂ = arg_ਮਾਪ;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->ਅਗਲਾ = ਪਹਿਲਾ;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_ਕੱਢੋ(ps, sr, 1);
        --local_scope;

    } ਨਹੀਂਤਾਂ ਜੇ (tok == '[') {
	ਪੂਰਨ saved_nocode_wanted = nocode_wanted;
        ਪੂਰਨ array_qualifiers = 0;
        /* array definition */
        ਅਗਲਾ();
        n = -1;
        t1 = 0;
        ਜੇ (td & TYPE_PARAM) ਜਦੋਂ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    ਚੋਣ (tok) {
	    ਹਾਲਤ TOK_CONST1: ਹਾਲਤ TOK_CONST2: ਹਾਲਤ TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		ਅਗਲਾ();
		ਜਾਰੀ;
	    ਹਾਲਤ TOK_VOLATILE1: ਹਾਲਤ TOK_VOLATILE2: ਹਾਲਤ TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		ਅਗਲਾ();
		ਜਾਰੀ;
	    ਹਾਲਤ TOK_RESTRICT1: ਹਾਲਤ TOK_RESTRICT2: ਹਾਲਤ TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		ਅਗਲਾ();
		ਜਾਰੀ;
	    ਹਾਲਤ TOK_STATIC:
	    ਹਾਲਤ '*':
		ਅਗਲਾ();
		ਜਾਰੀ;
	    ਮੂਲ:
		ਰੋਕੋ;
	    }
            ਜੇ (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_ਖੰਡ(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		ਅਗਲਾ();
	        gexpr();
		ਸਿਰਾ_macro();
		ਅਗਲਾ();
		ਜਾਓ check;
            }
            ਰੋਕੋ;

	} ਨਹੀਂਤਾਂ ਜੇ (tok != ']') {
            ਜੇ (!local_ਢੇਰ || (storage & VT_STATIC))
                vpushi(ਵਿਅੰਜਕ_const());
            ਨਹੀਂਤਾਂ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ਜੇ (n < 0)
                    tcc_error("invalid array size");
            } ਨਹੀਂਤਾਂ {
                ਜੇ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_ਸਿੱਧਾ|TYPE_ABSTRACT)) | TYPE_NEST);

        ਜੇ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ਜੇ ((type->t & VT_BTYPE) == VT_VOID
            || type_ਮਾਪ(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ਜੇ (t1 & VT_VLA) {
            ਜੇ (n < 0) {
		ਜੇ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ਨਹੀਂਤਾਂ {
                loc -= type_ਮਾਪ(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_ਮਾਪ(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        ਜੇ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ਜੇ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ਜੇ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ਨਹੀਂਤਾਂ
	        tok_str_free_str(vla_array_str);
	}
    }
    ਵਾਪਸ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ਸਥਿਰ CType *type_decl(CType *type, AttributeDef *ad, ਪੂਰਨ *v, ਪੂਰਨ td)
{
    CType *post, *ret;
    ਪੂਰਨ qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ਜਦੋਂ (tok == '*') {
        qualifiers = 0;
    redo:
        ਅਗਲਾ();
        ਚੋਣ(tok) {
        ਹਾਲਤ TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            ਜਾਓ redo;
        ਹਾਲਤ TOK_CONST1:
        ਹਾਲਤ TOK_CONST2:
        ਹਾਲਤ TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            ਜਾਓ redo;
        ਹਾਲਤ TOK_VOLATILE1:
        ਹਾਲਤ TOK_VOLATILE2:
        ਹਾਲਤ TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            ਜਾਓ redo;
        ਹਾਲਤ TOK_RESTRICT1:
        ਹਾਲਤ TOK_RESTRICT2:
        ਹਾਲਤ TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            ਜਾਓ redo;
	/* XXX: clarify attribute handling */
	ਹਾਲਤ TOK_ATTRIBUTE1:
	ਹਾਲਤ TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    ਰੋਕੋ;
        }
        mk_ਸੂਚਕ(type);
        type->t |= qualifiers;
	ਜੇ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ਜੇ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ਜੇ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ਨਹੀਂਤਾਂ
	  ਜਾਓ abstract;
    } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_IDENT && (td & TYPE_ਸਿੱਧਾ)) {
	/* type identifier */
	*v = tok;
	ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
  abstract:
	ਜੇ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_ਸਿੱਧਾ|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ਵਾਪਸ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC ਖਾਲੀ indir(ਖਾਲੀ)
{
    ਜੇ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ਵਾਪਸ;
        expect("pointer");
    }
    ਜੇ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ਜੇ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#ਜੇ_ਅੰਤ
    }
}

/* pass a parameter to a function and do type checking and casting */
ਸਥਿਰ ਖਾਲੀ gfunc_param_typed(Sym *func, Sym *arg)
{
    ਪੂਰਨ func_type;
    CType type;

    func_type = func->f.func_type;
    ਜੇ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ਨਿਰਾ)) {
        /* default casting : only need to convert float to double */
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ਨਹੀਂਤਾਂ ਜੇ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ਨਹੀਂਤਾਂ ਜੇ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ਨਹੀਂਤਾਂ ਜੇ (arg == ਨਿਰਾ) {
        tcc_error("too many arguments to function");
    } ਨਹੀਂਤਾਂ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_ਸੌਂਪੋ_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_type(CType *type, ਖਾਲੀ (*ਵਿਅੰਜਕ_fn)(ਖਾਲੀ))
{
    nocode_wanted++;
    ਵਿਅੰਜਕ_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ਸਥਿਰ ਖਾਲੀ parse_ਵਿਅੰਜਕ_type(CType *type)
{
    ਪੂਰਨ n;
    AttributeDef ad;

    skip('(');
    ਜੇ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ਨਹੀਂਤਾਂ {
        ਵਿਅੰਜਕ_type(type, gexpr);
    }
    skip(')');
}

ਸਥਿਰ ਖਾਲੀ parse_type(CType *type)
{
    AttributeDef ad;
    ਪੂਰਨ n;

    ਜੇ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ਸਥਿਰ ਖਾਲੀ parse_builtin_params(ਪੂਰਨ nc, ਅਚਲ ਅੱਖਰ *ਦਲੀਲਾਂ)
{
    ਅੱਖਰ c, sep = '(';
    CType type;
    ਜੇ (nc)
        nocode_wanted++;
    ਅਗਲਾ();
    ਜੇ (*ਦਲੀਲਾਂ == 0)
	skip(sep);
    ਜਦੋਂ ((c = *ਦਲੀਲਾਂ++)) {
	skip(sep);
	sep = ',';
        ਜੇ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ਜਾਰੀ;
        }
        ਵਿਅੰਜਕ_eq();
        type.ref = ਨਿਰਾ;
        type.t = 0;
	ਚੋਣ (c) {
	    ਹਾਲਤ 'e':
		ਜਾਰੀ;
	    ਹਾਲਤ 'V':
                type.t = VT_CONSTANT;
	    ਹਾਲਤ 'v':
                type.t |= VT_VOID;
                mk_ਸੂਚਕ (&type);
                ਰੋਕੋ;
	    ਹਾਲਤ 'S':
                type.t = VT_CONSTANT;
	    ਹਾਲਤ 's':
                type.t |= char_type.t;
                mk_ਸੂਚਕ (&type);
                ਰੋਕੋ;
	    ਹਾਲਤ 'i':
                type.t = VT_INT;
                ਰੋਕੋ;
	    ਹਾਲਤ 'l':
                type.t = VT_ਮਾਪ_T;
                ਰੋਕੋ;
	    ਮੂਲ:
                ਰੋਕੋ;
	}
        gen_ਸੌਂਪੋ_cast(&type);
    }
    skip(')');
    ਜੇ (nc)
        nocode_wanted--;
}

ਸਥਿਰ ਖਾਲੀ parse_atomic(ਪੂਰਨ atok)
{
    ਪੂਰਨ ਮਾਪ, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    ਅੱਖਰ buf[40];
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ *ਅਚਲ templates[] = {
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
    ਅਚਲ ਅੱਖਰ *ਸਾਂਚਾ = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ਨਿਰਾ;
    ਮਾਪ = 0; /* pacify compiler */
    ਅਗਲਾ();
    skip('(');
    ਲਈ (arg = 0;;) {
        ਵਿਅੰਜਕ_eq();
        ਚੋਣ (ਸਾਂਚਾ[arg]) {
        ਹਾਲਤ 'a':
        ਹਾਲਤ 'A':
            atom_ptr = &vtop->type;
            ਜੇ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            ਮਾਪ = type_ਮਾਪ(atom, &align);
            ਜੇ (ਮਾਪ > 8
                || (ਮਾਪ & (ਮਾਪ - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_ਮਾਪ(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            ਰੋਕੋ;

        ਹਾਲਤ 'p':
            ਜੇ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_ਮਾਪ(pointed_type(&vtop->type), &align) != ਮਾਪ)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_ਸੌਂਪੋ_cast(atom_ptr);
            ਰੋਕੋ;
        ਹਾਲਤ 'v':
            gen_ਸੌਂਪੋ_cast(atom);
            ਰੋਕੋ;
        ਹਾਲਤ 'l':
            indir();
            gen_ਸੌਂਪੋ_cast(atom);
            ਰੋਕੋ;
        ਹਾਲਤ 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            ਰੋਕੋ;
        ਹਾਲਤ 'm':
            gen_ਸੌਂਪੋ_cast(&int_type);
            ਰੋਕੋ;
        ਹਾਲਤ 'b':
            ct.t = VT_BOOL;
            gen_ਸੌਂਪੋ_cast(&ct);
            ਰੋਕੋ;
        }
        ਜੇ ('.' == ਸਾਂਚਾ[++arg])
            ਰੋਕੋ;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    ਚੋਣ (ਸਾਂਚਾ[arg + 1]) {
    ਹਾਲਤ 'b':
        ct.t = VT_BOOL;
        ਰੋਕੋ;
    ਹਾਲਤ 'v':
        ct = *atom;
        ਰੋਕੋ;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), ਮਾਪ);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ਜੇ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ਨਹੀਂਤਾਂ
        vtop->type.t = VT_INT;
#ਜੇ_ਅੰਤ
    }
    gen_cast(&ct);
    ਜੇ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC ਖਾਲੀ unary(ਖਾਲੀ)
{
    ਪੂਰਨ n, t, align, ਮਾਪ, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ਜੇ (debug_modes)
        tcc_debug_ਸਤਰ(tcc_state), tcc_tcov_check_ਸਤਰ (tcc_state, 1);

    type.ref = ਨਿਰਾ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_ਅਗਲਾ:
    ਚੋਣ(tok) {
    ਹਾਲਤ TOK_EXTENSION:
        ਅਗਲਾ();
        ਜਾਓ tok_ਅਗਲਾ;
    ਹਾਲਤ TOK_LCHAR:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        t = VT_SHORT|VT_UNSIGNED;
        ਜਾਓ ਧੱਕੋ_tokc;
#ਜੇ_ਅੰਤ
    ਹਾਲਤ TOK_CINT:
    ਹਾਲਤ TOK_CCHAR: 
	t = VT_INT;
 ਧੱਕੋ_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        ਅਗਲਾ();
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CLLONG:
        t = VT_LLONG;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CFLOAT:
        t = VT_FLOAT;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CDOUBLE:
        t = VT_DOUBLE;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CLDOUBLE:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ਨਹੀਂਤਾਂ
        t = VT_LDOUBLE;
#ਜੇ_ਅੰਤ
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CLONG:
        t = (LONG_ਮਾਪ == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK_CULONG:
        t = (LONG_ਮਾਪ == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	ਜਾਓ ਧੱਕੋ_tokc;
    ਹਾਲਤ TOK___FUNCTION__:
        ਜੇ (!gnu_ext)
            ਜਾਓ tok_identifier;
        /* fall thru */
    ਹਾਲਤ TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.ਮਾਪ = tokcstr.ਮਾਪ;
        tokc.str.ਅੰਕੜੇ = tokcstr.ਅੰਕੜੇ;
        ਜਾਓ case_TOK_STR;
    ਹਾਲਤ TOK_LSTR:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        t = VT_SHORT | VT_UNSIGNED;
#ਨਹੀਂਤਾਂ
        t = VT_INT;
#ਜੇ_ਅੰਤ
        ਜਾਓ str_init;
    ਹਾਲਤ TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ਜੇ (tcc_state->warn_write_ਲੜੀਆਂ & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_ਸੂਚਕ(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, ਆਕਾਰ(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SOTYPE:
    ਹਾਲਤ '(':
        t = tok;
        ਅਗਲਾ();
        /* cast ? */
        ਜੇ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ਜੇ (tok == '{') {
                    /* data is allocated locally by default */
                ਜੇ (global_ਵਿਅੰਜਕ)
                    r = VT_CONST;
                ਨਹੀਂਤਾਂ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ਜੇ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, ਆਕਾਰ(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ਵਾਪਸ;
            } ਨਹੀਂਤਾਂ {
                unary();
                gen_cast(&type);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (tok == '{') {
	    ਪੂਰਨ saved_nocode_wanted = nocode_wanted;
            ਜੇ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ਜੇ (0 == local_scope)
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
            ਖੰਡ(STMT_ਵਿਅੰਜਕ);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ਜੇ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ਨਹੀਂਤਾਂ {
            gexpr();
            skip(')');
        }
        ਰੋਕੋ;
    ਹਾਲਤ '*':
        ਅਗਲਾ();
        unary();
        indir();
        ਰੋਕੋ;
    ਹਾਲਤ '&':
        ਅਗਲਾ();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ਜੇ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ਜੇ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_ਸੂਚਕ(&vtop->type);
        gaddrof();
        ਰੋਕੋ;
    ਹਾਲਤ '!':
        ਅਗਲਾ();
        unary();
        gen_test_zero(TOK_EQ);
        ਰੋਕੋ;
    ਹਾਲਤ '~':
        ਅਗਲਾ();
        unary();
        vpushi(-1);
        gen_op('^');
        ਰੋਕੋ;
    ਹਾਲਤ '+':
        ਅਗਲਾ();
        unary();
        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ਜੇ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        ਰੋਕੋ;
    ਹਾਲਤ TOK_SIZEOF:
    ਹਾਲਤ TOK_ALIGNOF1:
    ਹਾਲਤ TOK_ALIGNOF2:
    ਹਾਲਤ TOK_ALIGNOF3:
        t = tok;
        ਅਗਲਾ();
        ਜੇ (tok == '(')
            tok = TOK_SOTYPE;
        ਵਿਅੰਜਕ_type(&type, unary);
        ਜੇ (t == TOK_SIZEOF) {
            vpush_type_ਮਾਪ(&type, &align);
            gen_cast_s(VT_ਮਾਪ_T);
        } ਨਹੀਂਤਾਂ {
            type_ਮਾਪ(&type, &align);
            s = ਨਿਰਾ;
            ਜੇ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ਜੇ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        ਰੋਕੋ;

    ਹਾਲਤ TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        ਰੋਕੋ;
    ਹਾਲਤ TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_builtin_ਚੁਣੋ_ਵਿਅੰਜਕ:
	{
	    int64_t c;
	    ਅਗਲਾ();
	    skip('(');
	    c = ਵਿਅੰਜਕ_const64();
	    skip(',');
	    ਜੇ (!c) {
		nocode_wanted++;
	    }
	    ਵਿਅੰਜਕ_eq();
	    ਜੇ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ਜੇ (c) {
		nocode_wanted++;
	    }
	    ਵਿਅੰਜਕ_eq();
	    ਜੇ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        ਰੋਕੋ;
    ਹਾਲਤ TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        ਕੋਡ_OFF();
        ਰੋਕੋ;
    ਹਾਲਤ TOK_builtin_ਚੌਖਟਾ_ਪਤਾ:
    ਹਾਲਤ TOK_builtin_return_ਪਤਾ:
        {
            ਪੂਰਨ tok1 = tok;
            ਪੂਰਨ level;
            ਅਗਲਾ();
            skip('(');
            level = ਵਿਅੰਜਕ_const();
            ਜੇ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_ਸੂਚਕ(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ਜਦੋਂ (level--) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
                vpushi(2*PTR_ਮਾਪ);
                gen_op('-');
#ਜੇ_ਅੰਤ
                mk_ਸੂਚਕ(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ਜੇ (tok1 == TOK_builtin_return_ਪਤਾ) {
                // assume return address is just above frame pointer on stack
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
                vpushi(2*PTR_ਮਾਪ);
                gen_op('+');
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
                vpushi(PTR_ਮਾਪ);
                gen_op('-');
#ਨਹੀਂਤਾਂ
                vpushi(PTR_ਮਾਪ);
                gen_op('+');
#ਜੇ_ਅੰਤ
                mk_ਸੂਚਕ(&vtop->type);
                indir();
            }
        }
        ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਹਾਲਤ TOK_builtin_va_ਸ਼ੁਰੂ:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ਜੇ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ਜੇ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_ਸ਼ੁਰੂ();
	vstore();
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਹਾਲਤ TOK_builtin_va_ਸ਼ੁਰੂ:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ਜੇ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ਜੇ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_ਸੂਚਕ_type;
	vtop->c.i += 8;
	vstore();
        ਰੋਕੋ;
#ਨਹੀਂਤਾਂ
    ਹਾਲਤ TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	ਰੋਕੋ;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
    ਹਾਲਤ TOK_builtin_va_ਸ਼ੁਰੂ: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_ਸ਼ੁਰੂ();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ਰੋਕੋ;
    }
    ਹਾਲਤ TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        ਰੋਕੋ;
    }
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
    ਹਾਲਤ TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ਰੋਕੋ;
    }
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਹਾਲਤ TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ਰੋਕੋ;
    }
#ਜੇ_ਅੰਤ

    /* atomic operations */
    ਹਾਲਤ TOK___atomic_store:
    ਹਾਲਤ TOK_atomic_ਲੱਦੋ:
    ਹਾਲਤ TOK___atomic_exchange:
    ਹਾਲਤ TOK___atomic_compare_exchange:
    ਹਾਲਤ TOK_atomic_fetch_ਜੋੜੋ:
    ਹਾਲਤ TOK___atomic_fetch_sub:
    ਹਾਲਤ TOK___atomic_fetch_or:
    ਹਾਲਤ TOK___atomic_fetch_xor:
    ਹਾਲਤ TOK___atomic_fetch_and:
    ਹਾਲਤ TOK___atomic_fetch_nand:
    ਹਾਲਤ TOK_atomic_ਜੋੜੋ_fetch:
    ਹਾਲਤ TOK___atomic_sub_fetch:
    ਹਾਲਤ TOK___atomic_or_fetch:
    ਹਾਲਤ TOK___atomic_xor_fetch:
    ਹਾਲਤ TOK___atomic_and_fetch:
    ਹਾਲਤ TOK___atomic_nand_fetch:
        parse_atomic(tok);
        ਰੋਕੋ;

    /* pre operations */
    ਹਾਲਤ TOK_INC:
    ਹਾਲਤ TOK_DEC:
        t = tok;
        ਅਗਲਾ();
        unary();
        inc(0, t);
        ਰੋਕੋ;
    ਹਾਲਤ '-':
        ਅਗਲਾ();
        unary();
	ਜੇ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ਨਹੀਂਤਾਂ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LAND:
        ਜੇ (!gnu_ext)
            ਜਾਓ tok_identifier;
        ਅਗਲਾ();
        /* allow to take the address of a label */
        ਜੇ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_ਲੱਭੋ(tok);
        ਜੇ (!s) {
            s = label_ਧੱਕੋ(&global_label_ਢੇਰ, tok, LABEL_FORWARD);
        } ਨਹੀਂਤਾਂ {
            ਜੇ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ਜੇ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_ਸੂਚਕ(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        ਅਗਲਾ();
        ਰੋਕੋ;

    ਹਾਲਤ TOK_GENERIC:
    {
	CType controlling_type;
	ਪੂਰਨ has_default = 0;
	ਪੂਰਨ has_ਮੇਲ = 0;
	ਪੂਰਨ learn = 0;
	TokenString *str = ਨਿਰਾ;
	ਪੂਰਨ saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_ਨਕਾਬ;

        ਅਗਲਾ();
	skip('(');
	ਵਿਅੰਜਕ_type(&controlling_type, ਵਿਅੰਜਕ_eq);
	convert_ਵਿਅੰਜਕ_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        ਲਈ (;;) {
	    learn = 0;
	    skip(',');
	    ਜੇ (tok == TOK_DEFAULT) {
		ਜੇ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ਜੇ (!has_ਮੇਲ)
		    learn = 1;
		ਅਗਲਾ();
	    } ਨਹੀਂਤਾਂ {
		ਪੂਰਨ v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ਜੇ (compare_types(&controlling_type, &type, 0)) {
		    ਜੇ (has_ਮੇਲ) {
		      tcc_error("type match twice");
		    }
		    has_ਮੇਲ = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ਜੇ (learn) {
		ਜੇ (str)
		    tok_str_free(str);
		skip_or_save_ਖੰਡ(&str);
	    } ਨਹੀਂਤਾਂ {
		skip_or_save_ਖੰਡ(ਨਿਰਾ);
	    }
	    ਜੇ (tok == ')')
		ਰੋਕੋ;
	}
	ਜੇ (!str) {
	    ਅੱਖਰ buf[60];
	    type_ਮੰਜ਼ਿਲ_str(buf, ਆਕਾਰ buf, &controlling_type, ਨਿਰਾ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	ਅਗਲਾ();
	ਵਿਅੰਜਕ_eq();
	ਜੇ (tok != TOK_EOF)
	    expect(",");
	ਸਿਰਾ_macro();
        ਅਗਲਾ();
	ਰੋਕੋ;
    }
    // special qnan , snan and infinity values
    ਹਾਲਤ TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        ਅਗਲਾ();
        ਰੋਕੋ;
    ਹਾਲਤ TOK___SNAN__:
	n = 0x7f800001;
	ਜਾਓ special_math_val;
    ਹਾਲਤ TOK___INF__:
	n = 0x7f800000;
	ਜਾਓ special_math_val;

    ਮੂਲ:
    tok_identifier:
        ਜੇ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        ਅਗਲਾ();
        s = sym_ਲੱਭੋ(t);
        ਜੇ (!s || IS_ASM_SYM(s)) {
            ਅਚਲ ਅੱਖਰ *name = get_tok_str(t, ਨਿਰਾ);
            ਜੇ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ਜੇ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ਜੇ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ਜੇ (r & VT_SYM) {
            vtop->c.i = 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            ਜੇ (s->a.dllimport) {
                mk_ਸੂਚਕ(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ ਜੇ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        ਰੋਕੋ;
    }
    
    /* post operations */
    ਜਦੋਂ (1) {
        ਜੇ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ ਜੇ (tok == '.' || tok == TOK_ARROW) {
            ਪੂਰਨ qualifiers, cumofs;
            /*ਖੇਤਰ*/ 
            ਜੇ (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            ਅਗਲਾ();
	    s = ਲੱਭੋ_ਖੇਤਰ(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_ਸੂਚਕ_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            ਜੇ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ਜੇ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ਜੇ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#ਜੇ_ਅੰਤ
            }
            ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ ਜੇ (tok == '[') {
            ਅਗਲਾ();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ਨਹੀਂਤਾਂ ਜੇ (tok == '(') {
            SValue ret;
            Sym *sa;
            ਪੂਰਨ nb_ਦਲੀਲਾਂ, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ਜੇ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ਜੇ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ਜੇ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        ਜਾਓ error_func;
                } ਨਹੀਂਤਾਂ {
                error_func:
                    expect("function pointer");
                }
            } ਨਹੀਂਤਾਂ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            ਅਗਲਾ();
            sa = s->ਅਗਲਾ; /* first parameter */
            nb_ਦਲੀਲਾਂ = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ਜੇ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ਜੇ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    ਮਾਪ = type_ਮਾਪ(&s->type, &align);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ਜੇ (ਮਾਪ < 16)
                    ਜਦੋਂ (ਮਾਪ & (ਮਾਪ - 1))
                        ਮਾਪ = (ਮਾਪ | (ਮਾਪ - 1)) + 1;
#ਜੇ_ਅੰਤ
                    loc = (loc - ਮਾਪ) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
                    ਜੇ (tcc_state->do_bounds_check)
                        --loc;
#ਜੇ_ਅੰਤ
                    ret.c = vtop->c;
                    ਜੇ (ret_nregs < 0)
                      vtop--;
                    ਨਹੀਂਤਾਂ
                      nb_ਦਲੀਲਾਂ++;
                }
            } ਨਹੀਂਤਾਂ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ਜੇ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ਨਿਰਾ;
            ਜੇ (tok != ')') {
                r = tcc_state->ਉਲਟ_funcargs;
                ਲਈ(;;) {
                    ਜੇ (r) {
                        skip_or_save_ਖੰਡ(&p2);
                        p2->prev = p, p = p2;
                    } ਨਹੀਂਤਾਂ {
                        ਵਿਅੰਜਕ_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_ਦਲੀਲਾਂ++;
                    ਜੇ (sa)
                        sa = sa->ਅਗਲਾ;
                    ਜੇ (tok == ')')
                        ਰੋਕੋ;
                    skip(',');
                }
            }
            ਜੇ (sa)
                tcc_error("too few arguments to function");

            ਜੇ (p) { /* with reverse_funcargs */
                ਲਈ (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    ਕਰੋ {
                        sa = sa->ਅਗਲਾ, p2 = p2->prev;
                    } ਜਦੋਂ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), ਅਗਲਾ();
                    ਵਿਅੰਜਕ_eq();
                    gfunc_param_typed(s, sa);
                    ਸਿਰਾ_macro();
                }
                vrev(n);
            }

            ਅਗਲਾ();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_ਦਲੀਲਾਂ);

            ਜੇ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
                arch_transfer_ret_regs(1);
#ਜੇ_ਅੰਤ
            } ਨਹੀਂਤਾਂ {
                /* return value */
                n = ret_nregs;
                ਜਦੋਂ (n > 1) {
                    ਪੂਰਨ rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    ਲਈ (r = 0; r < NB_REGS; ++r)
                        ਜੇ (reg_classes[r] & rc)
                            ਰੋਕੋ;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ਜੇ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    ਪੂਰਨ addr, ਵਿੱਥ;

                    ਮਾਪ = type_ਮਾਪ(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    ਮਾਪ = (ਮਾਪ + regsize - 1) & -regsize;
                    ਜੇ (ret_align > align)
                        align = ret_align;
                    loc = (loc - ਮਾਪ) & -align;
                    addr = loc;
                    ਵਿੱਥ = 0;
                    ਲਈ (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + ਵਿੱਥ);
                        vswap();
                        vstore();
                        vtop--;
                        ਜੇ (--ret_nregs == 0)
                          ਰੋਕੋ;
                        ਵਿੱਥ += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                ਜੇ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ਨਹੀਂਤਾਂ
                    vtop->type.t = VT_INT;
#ਜੇ_ਅੰਤ
                }
            }
            ਜੇ (s->f.func_noreturn) {
                ਜੇ (debug_modes)
	            tcc_tcov_ਖੰਡ_ਸਿਰਾ(tcc_state, -1);
                ਕੋਡ_OFF();
	    }
        } ਨਹੀਂਤਾਂ {
            ਰੋਕੋ;
        }
    }
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ precedence_parser /* original top-down parser */

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_prod(ਖਾਲੀ)
{
    ਪੂਰਨ t;

    unary();
    ਜਦੋਂ ((t = tok) == '*' || t == '/' || t == '%') {
        ਅਗਲਾ();
        unary();
        gen_op(t);
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_ਜੋੜ(ਖਾਲੀ)
{
    ਪੂਰਨ t;

    ਵਿਅੰਜਕ_prod();
    ਜਦੋਂ ((t = tok) == '+' || t == '-') {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_prod();
        gen_op(t);
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_ਖਿਸਕਾਓ(ਖਾਲੀ)
{
    ਪੂਰਨ t;

    ਵਿਅੰਜਕ_ਜੋੜ();
    ਜਦੋਂ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_ਜੋੜ();
        gen_op(t);
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_cmp(ਖਾਲੀ)
{
    ਪੂਰਨ t;

    ਵਿਅੰਜਕ_ਖਿਸਕਾਓ();
    ਜਦੋਂ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_ਖਿਸਕਾਓ();
        gen_op(t);
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_cmpeq(ਖਾਲੀ)
{
    ਪੂਰਨ t;

    ਵਿਅੰਜਕ_cmp();
    ਜਦੋਂ ((t = tok) == TOK_EQ || t == TOK_NE) {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_cmp();
        gen_op(t);
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_and(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_cmpeq();
    ਜਦੋਂ (tok == '&') {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_cmpeq();
        gen_op('&');
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_xor(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_and();
    ਜਦੋਂ (tok == '^') {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_and();
        gen_op('^');
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_or(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_xor();
    ਜਦੋਂ (tok == '|') {
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_xor();
        gen_op('|');
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_landor(ਪੂਰਨ op);

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_land(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_or();
    ਜੇ (tok == TOK_LAND)
        ਵਿਅੰਜਕ_landor(tok);
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_lor(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_land();
    ਜੇ (tok == TOK_LOR)
        ਵਿਅੰਜਕ_landor(tok);
}

# define ਵਿਅੰਜਕ_landor_ਅਗਲਾ(op) op == TOK_LAND ? ਵਿਅੰਜਕ_or() : ਵਿਅੰਜਕ_land()
#ਨਹੀਂਤਾਂ /* defined precedence_parser */
# define ਵਿਅੰਜਕ_landor_ਅਗਲਾ(op) unary(), ਵਿਅੰਜਕ_infix(precedence(op) + 1)
# define ਵਿਅੰਜਕ_lor() unary(), ਵਿਅੰਜਕ_infix(1)

ਸਥਿਰ ਪੂਰਨ precedence(ਪੂਰਨ tok)
{
    ਚੋਣ (tok) {
        ਹਾਲਤ TOK_LOR: ਵਾਪਸ 1;
        ਹਾਲਤ TOK_LAND: ਵਾਪਸ 2;
	ਹਾਲਤ '|': ਵਾਪਸ 3;
	ਹਾਲਤ '^': ਵਾਪਸ 4;
	ਹਾਲਤ '&': ਵਾਪਸ 5;
	ਹਾਲਤ TOK_EQ: ਹਾਲਤ TOK_NE: ਵਾਪਸ 6;
 relat: ਹਾਲਤ TOK_ULT: ਹਾਲਤ TOK_UGE: ਵਾਪਸ 7;
	ਹਾਲਤ TOK_SHL: ਹਾਲਤ TOK_SAR: ਵਾਪਸ 8;
	ਹਾਲਤ '+': ਹਾਲਤ '-': ਵਾਪਸ 9;
	ਹਾਲਤ '*': ਹਾਲਤ '/': ਹਾਲਤ '%': ਵਾਪਸ 10;
	ਮੂਲ:
	    ਜੇ (tok >= TOK_ULE && tok <= TOK_GT)
	        ਜਾਓ relat;
	    ਵਾਪਸ 0;
    }
}
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ prec[256];
ਸਥਿਰ ਖਾਲੀ init_prec(ਖਾਲੀ)
{
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ precedence(i) ((ਬਿਨਾਨਿਸ਼ਾਨੀ)i < 256 ? prec[i] : 0)

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_landor(ਪੂਰਨ op);

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_infix(ਪੂਰਨ p)
{
    ਪੂਰਨ t = tok, p2;
    ਜਦੋਂ ((p2 = precedence(t)) >= p) {
        ਜੇ (t == TOK_LOR || t == TOK_LAND) {
            ਵਿਅੰਜਕ_landor(t);
        } ਨਹੀਂਤਾਂ {
            ਅਗਲਾ();
            unary();
            ਜੇ (precedence(tok) > p2)
              ਵਿਅੰਜਕ_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#ਜੇ_ਅੰਤ

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ਸਥਿਰ ਪੂਰਨ condition_3way(ਖਾਲੀ)
{
    ਪੂਰਨ c = -1;
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ਵਾਪਸ c;
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_landor(ਪੂਰਨ op)
{
    ਪੂਰਨ t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    ਲਈ(;;) {
        c = f ? i : condition_3way();
        ਜੇ (c < 0)
            save_regs(1), cc = 0;
        ਨਹੀਂਤਾਂ ਜੇ (c != i)
            nocode_wanted++, f = 1;
        ਜੇ (tok != op)
            ਰੋਕੋ;
        ਜੇ (c < 0)
            t = gvtst(i, t);
        ਨਹੀਂਤਾਂ
            vpop();
        ਅਗਲਾ();
        ਵਿਅੰਜਕ_landor_ਅਗਲਾ(op);
    }
    ਜੇ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ਨਹੀਂਤਾਂ {
        gvtst_ਸੈੱਟ(i, t);
    }
}

ਸਥਿਰ ਪੂਰਨ is_cond_bool(SValue *sv)
{
    ਜੇ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ਵਾਪਸ (ਬਿਨਾਨਿਸ਼ਾਨੀ)sv->c.i < 2;
    ਜੇ (sv->r == VT_CMP)
        ਵਾਪਸ 1;
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_cond(ਖਾਲੀ)
{
    ਪੂਰਨ tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    ਵਿਅੰਜਕ_lor();
    ਜੇ (tok == '?') {
        ਅਗਲਾ();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ਜੇ (!g) {
            ਜੇ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ਨਹੀਂਤਾਂ {
                vpop();
            }
        } ਨਹੀਂਤਾਂ ਜੇ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ਜੇ (c == 0)
          nocode_wanted++;
        ਜੇ (!g)
          gexpr();

        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_ਸੂਚਕ(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ਜੇ (g) {
            u = tt;
        } ਨਹੀਂਤਾਂ ਜੇ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ਨਹੀਂਤਾਂ
          u = 0;

        ਜੇ (c == 0)
          nocode_wanted--;
        ਜੇ (c == 1)
          nocode_wanted++;
        skip(':');
        ਵਿਅੰਜਕ_cond();

        ਜੇ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_ਸੂਚਕ(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ਜੇ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ਜੇ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_ਸੈੱਟ(0, t1);
            gvtst_ਸੈੱਟ(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            ਵਾਪਸ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ਜੇ (c != 1) {
            gen_cast(&type);
            ਜੇ (islv) {
                mk_ਸੂਚਕ(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ਜੇ (USING_TWO_ਸ਼ਬਦ(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ਜੇ (c < 0) {
            ਜੇ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ਜੇ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
ਸੰਕਾਰਜ*/
        ਜੇ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ਜੇ (islv) {
                mk_ਸੂਚਕ(&vtop->type);
                gaddrof();
            }
        }

        ਜੇ (c < 0) {
            ਜੇ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ਜੇ (islv)
          indir();
    }
}

ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_eq(ਖਾਲੀ)
{
    ਪੂਰਨ t;
    
    ਵਿਅੰਜਕ_cond();
    ਜੇ ((t = tok) == '=' || TOK_ਸੌਂਪੋ(t)) {
        test_lvalue();
        ਅਗਲਾ();
        ਜੇ (t == '=') {
            ਵਿਅੰਜਕ_eq();
        } ਨਹੀਂਤਾਂ {
            vdup();
            ਵਿਅੰਜਕ_eq();
            gen_op(TOK_ਸੌਂਪੋ_OP(t));
        }
        vstore();
    }
}

ST_FUNC ਖਾਲੀ gexpr(ਖਾਲੀ)
{
    ਵਿਅੰਜਕ_eq();
    ਜੇ (tok == ',') {
        ਕਰੋ {
            vpop();
            ਅਗਲਾ();
            ਵਿਅੰਜਕ_eq();
        } ਜਦੋਂ (tok == ',');

        /* convert array & function to pointer */
        convert_ਵਿਅੰਜਕ_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ਜੇ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ਜੇ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ਸਥਿਰ ਖਾਲੀ ਵਿਅੰਜਕ_const1(ਖਾਲੀ)
{
    nocode_wanted += CONST_WANTED_ਦੋਆਧਾਰੀ_ਅੰਕ;
    ਵਿਅੰਜਕ_cond();
    nocode_wanted -= CONST_WANTED_ਦੋਆਧਾਰੀ_ਅੰਕ;
}

/* parse an integer constant and return its value. */
ਸਥਿਰ ਸਤਰਅੰਦਰ int64_t ਵਿਅੰਜਕ_const64(ਖਾਲੀ)
{
    int64_t c;
    ਵਿਅੰਜਕ_const1();
    ਜੇ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ਵਾਪਸ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC ਪੂਰਨ ਵਿਅੰਜਕ_const(ਖਾਲੀ)
{
    ਪੂਰਨ c;
    int64_t wc = ਵਿਅੰਜਕ_const64();
    c = wc;
    ਜੇ (c != wc && (ਬਿਨਾਨਿਸ਼ਾਨੀ)c != wc)
        tcc_error("constant exceeds 32 bit");
    ਵਾਪਸ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
ਸਥਿਰ ਖਾਲੀ gfunc_return(CType *func_type)
{
    ਜੇ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        ਪੂਰਨ ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ਜੇ (ret_nregs < 0) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
            arch_transfer_ret_regs(0);
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ ਜੇ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_ਸੂਚਕ(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ਨਹੀਂਤਾਂ {
            /* returning structure packed into registers */
            ਪੂਰਨ ਮਾਪ, addr, align, rc, n;
            ਮਾਪ = type_ਮਾਪ(func_type,&align);
            ਜੇ (ret_nregs * regsize > ਮਾਪ ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ਜੇ (ret_nregs * regsize > ਮਾਪ)
		    ਮਾਪ = ret_nregs * regsize;
		ਜੇ (ret_align > align)
		    align = ret_align;
                loc = (loc - ਮਾਪ) & -align;
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
            ਲਈ (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_ਵਿੱਥ(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } ਨਹੀਂਤਾਂ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ check_func_return(ਖਾਲੀ)
{
    ਜੇ ((func_vt.t & VT_BTYPE) == VT_VOID)
        ਵਾਪਸ;
    ਜੇ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ਨਹੀਂਤਾਂ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ਸਥਿਰ ਪੂਰਨ case_cmp(uint64_t a, uint64_t b)
{
    ਜੇ (cur_switch->sv.type.t & VT_UNSIGNED)
        ਵਾਪਸ a < b ? -1 : a > b;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ਸਥਿਰ ਪੂਰਨ case_cmp_qs(ਅਚਲ ਖਾਲੀ *pa, ਅਚਲ ਖਾਲੀ *pb)
{
    ਵਾਪਸ case_cmp((*(ਬਣਤਰ case_t**)pa)->v1, (*(ਬਣਤਰ case_t**)pb)->v1);
}

ਸਥਿਰ ਖਾਲੀ case_ਛਾਂਟੋ(ਬਣਤਰ switch_t *sw)
{
    ਬਣਤਰ case_t **p;
    ਜੇ (sw->n < 2)
        ਵਾਪਸ;
    qsort(sw->p, sw->n, ਆਕਾਰ *sw->p, case_cmp_qs);
    p = sw->p;
    ਜਦੋਂ (p < sw->p + sw->n - 1) {
        ਜੇ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            ਪੂਰਨ l1 = p[0]->ਸਤਰ, l2 = p[1]->ਸਤਰ;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ਨਹੀਂਤਾਂ ਜੇ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * ਆਕਾਰ *p);
        } ਨਹੀਂਤਾਂ
            ++p;
    }
}

ਸਥਿਰ ਪੂਰਨ gcase(ਬਣਤਰ case_t **ਅਧਾਰ, ਪੂਰਨ len, ਪੂਰਨ dsym)
{
    ਬਣਤਰ case_t *p;
    ਪੂਰਨ t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ਜੇ (t != VT_LLONG)
        t = VT_INT;
    ਜਦੋਂ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = ਅਧਾਰ[l2];
        vdup(), vpush64(t, p->v2);
        ਜੇ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ਨਹੀਂਤਾਂ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ਜੇ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ਨਹੀਂਤਾਂ
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(ਅਧਾਰ, l2, dsym);
            gsym(e);
        }
        ++l2, ਅਧਾਰ += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    ਵਾਪਸ gjmp(dsym);
}

ਸਥਿਰ ਖਾਲੀ ਸਿਰਾ_switch(ਖਾਲੀ)
{
    ਬਣਤਰ switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ਸਥਿਰ ਖਾਲੀ save_lvalues(ਖਾਲੀ)
{
    SValue *sv = vtop;
    ਜਦੋਂ (sv >= vstack) {
        ਜੇ (sv->sym && (sv->r & VT_LVAL)) {
            ਪੂਰਨ align, ਮਾਪ = type_ਮਾਪ(&sv->type, &align);
            ਪੂਰਨ r2, l = get_ਆਰਜ਼ੀ_local_var(ਮਾਪ, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ਸਥਿਰ ਖਾਲੀ try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    ਲਈ (; cls != stop; cls = cls->ਅਗਲਾ) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_ਸੂਚਕ(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


ਸਥਿਰ ਖਾਲੀ try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    ਪੂਰਨ ocd, ccd;

    ਜੇ (!cur_scope->cl.s)
	ਵਾਪਸ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_ਖੇਤਰ : 0;
    ਲਈ (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->ਅਗਲਾ)
      ;
    ਲਈ (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->ਅਗਲਾ)
      ;
    ਲਈ (; cc != oc; cc = cc->ਅਗਲਾ, oc = oc->ਅਗਲਾ, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ਸਥਿਰ ਖਾਲੀ ਖੰਡ_cleanup(ਬਣਤਰ scope *o)
{
    ਪੂਰਨ jmp = 0;
    Sym *g, **pg;
    ਲਈ (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ਜੇ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->ਅਗਲਾ;
            ਜੇ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ਜੇ (!o->cl.n)
                ਜਾਓ remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } ਨਹੀਂਤਾਂ {
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

ਸਥਿਰ ਖਾਲੀ vla_restore(ਪੂਰਨ loc)
{
    ਜੇ (loc)
        gen_vla_sp_restore(loc);
}

ਸਥਿਰ ਖਾਲੀ vla_leave(ਬਣਤਰ scope *o)
{
    ਬਣਤਰ scope *c = cur_scope, *v = ਨਿਰਾ;
    ਲਈ (; c != o && c; c = c->prev)
      ਜੇ (c->vla.ਅੰਕ)
        v = c;
    ਜੇ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ਸਥਿਰ ਖਾਲੀ new_scope(ਬਣਤਰ scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.ਅੰਕ = 0;

    /* record local declaration stack position */
    o->lstk = local_ਢੇਰ;
    o->llstk = local_label_ਢੇਰ;
    ++local_scope;
}

ਸਥਿਰ ਖਾਲੀ prev_scope(ਬਣਤਰ scope *o, ਪੂਰਨ is_ਵਿਅੰਜਕ)
{
    vla_leave(o->prev);

    ਜੇ (o->cl.s != o->prev->cl.s)
        ਖੰਡ_cleanup(o->prev);

    ਜੇ (debug_modes)
        tcc_debug_ਸਿਰਾ_scope(o->lstk, !is_ਵਿਅੰਜਕ);

    /* pop locally defined labels */
    label_ਕੱਢੋ(&local_label_ਢੇਰ, o->llstk, is_ਵਿਅੰਜਕ);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_ਕੱਢੋ(&local_ਢੇਰ, o->lstk, is_ਵਿਅੰਜਕ);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ਸਥਿਰ ਖਾਲੀ leave_scope(ਬਣਤਰ scope *o)
{
    ਜੇ (!o)
        ਵਾਪਸ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ਸਥਿਰ ਖਾਲੀ new_scope_s(ਬਣਤਰ scope *o)
{
    o->lstk = local_ਢੇਰ;
    ++local_scope;
}

ਸਥਿਰ ਖਾਲੀ prev_scope_s(ਬਣਤਰ scope *o)
{
    sym_ਕੱਢੋ(&local_ਢੇਰ, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ਸਥਿਰ ਖਾਲੀ lblock(ਪੂਰਨ *bsym, ਪੂਰਨ *csym)
{
    ਬਣਤਰ scope *lo = loop_scope, *co = cur_scope;
    ਪੂਰਨ *b = co->bsym, *c = co->csym;
    ਜੇ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    ਖੰਡ(0);
    co->bsym = b;
    ਜੇ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ਸਥਿਰ ਖਾਲੀ gexpr_decl(ਖਾਲੀ)
{
    ਪੂਰਨ v = decl(VT_JMP);
    ਜੇ (v > 1 && tok != ';') {
        Sym *s = sym_ਲੱਭੋ(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ਨਹੀਂਤਾਂ {
        ਜੇ (v)
            skip(';');
        gexpr();
    }
}

ਸਥਿਰ ਖਾਲੀ ਖੰਡ(ਪੂਰਨ flags)
{
    ਪੂਰਨ a, b, c, d, e, t;
    ਬਣਤਰ scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ਜੇ (TOK_HAS_ਮੁੱਲ(t))
        ਜਾਓ ਵਿਅੰਜਕ;
    ਅਗਲਾ();

    ਜੇ (debug_modes)
        tcc_tcov_check_ਸਤਰ (tcc_state, 0), tcc_tcov_ਖੰਡ_begin (tcc_state);

    ਜੇ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        ਖੰਡ(0);
        ਜੇ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            ਅਗਲਾ();
            ਖੰਡ(0);
            gsym(d); /* patch else jmp */
        } ਨਹੀਂਤਾਂ {
            gsym(a);
        }
        prev_scope_s(&o);

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_WHILE) {
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

    } ਨਹੀਂਤਾਂ ਜੇ (t == '{') {
        ਜੇ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ਜਦੋਂ (tok == TOK_LABEL) {
            ਕਰੋ {
                ਅਗਲਾ();
                ਜੇ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ਧੱਕੋ(&local_label_ਢੇਰ, tok, LABEL_DECLARED);
                ਅਗਲਾ();
            } ਜਦੋਂ (tok == ',');
            skip(';');
        }

        ਜਦੋਂ (tok != '}') {
	    decl(VT_LOCAL);
            ਜੇ (tok != '}') {
                ਖੰਡ(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_ਵਿਅੰਜਕ);
        ਜੇ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ਜੇ (local_scope)
            ਅਗਲਾ();
        ਨਹੀਂਤਾਂ ਜੇ (!nocode_wanted)
            check_func_return();

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ਜੇ (tok != ';') {
            gexpr();
            ਜੇ (b) {
                gen_ਸੌਂਪੋ_cast(&func_vt);
            } ਨਹੀਂਤਾਂ {
                ਜੇ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ਨਹੀਂਤਾਂ ਜੇ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ਨਹੀਂਤਾਂ ਜੇ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ਜੜ੍ਹ_scope);
        ਜੇ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ਜੇ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ਜੇ (debug_modes)
	    tcc_tcov_ਖੰਡ_ਸਿਰਾ (tcc_state, -1);
        ਕੋਡ_OFF();

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_BREAK) {
        /* compute jump */
        ਜੇ (!cur_scope->bsym)
            tcc_error("cannot break");
        ਜੇ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ਨਹੀਂਤਾਂ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_CONTINUE) {
        /* compute jump */
        ਜੇ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ਜੇ (tok != ';') {
            /* c99 for-loop init decl? */
            ਜੇ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ਜੇ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ਜੇ (tok != ')') {
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

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_DO) {
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

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_SWITCH) {
        ਬਣਤਰ switch_t *sw;

        sw = tcc_mallocz(ਆਕਾਰ *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ਜੇ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ਨਿਰਾ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ਜੇ (sw->nocode_wanted)
            ਜਾਓ skip_switch;
        case_ਛਾਂਟੋ(sw);
        sw->bsym = ਨਿਰਾ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ਜੇ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ਨਹੀਂਤਾਂ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        ਸਿਰਾ_switch();

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_CASE) {
        ਬਣਤਰ case_t *cr;
        ਜੇ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(ਆਕਾਰ(ਬਣਤਰ case_t));
        dynarray_ਜੋੜੋ(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(ਵਿਅੰਜਕ_const64(), t);
        ਜੇ (tok == TOK_DOTS && gnu_ext) {
            ਅਗਲਾ();
            cr->v2 = value64(ਵਿਅੰਜਕ_const64(), t);
            ਜੇ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ਜੇ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->ਸਤਰ = file->ਸਤਰ_ਅੰਕ;
        skip(':');
        ਜਾਓ ਖੰਡ_after_label;

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_DEFAULT) {
        ਜੇ (!cur_switch)
            expect("switch");
        ਜੇ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        ਜਾਓ ਖੰਡ_after_label;

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ਜੇ (tok == '*' && gnu_ext) {
            /* computed goto */
            ਅਗਲਾ();
            gexpr();
            ਜੇ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_UIDENT) {
	    s = label_ਲੱਭੋ(tok);
	    /* put forward definition if needed */
            ਜੇ (!s)
              s = label_ਧੱਕੋ(&global_label_ਢੇਰ, tok, LABEL_FORWARD);
            ਨਹੀਂਤਾਂ ਜੇ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ਜੇ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ਜੇ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_ਖੇਤਰ, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->ਅਗਲਾ, SYM_ਖੇਤਰ, 0, 0);
                    pending_gotos->ਅਗਲਾ = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ਨਹੀਂਤਾਂ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    ਅਗਲਾ();

        } ਨਹੀਂਤਾਂ {
            expect("label identifier");
        }
        skip(';');

    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ਨਹੀਂਤਾਂ {
        ਜੇ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    ਅਗਲਾ();
            s = label_ਲੱਭੋ(t);
            ਜੇ (s) {
                ਜੇ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ਨਿਰਾ));
                s->r = LABEL_DEFINED;
		ਜੇ (s->ਅਗਲਾ) {
		    Sym *pcl; /* pending cleanup goto */
		    ਲਈ (pcl = s->ਅਗਲਾ; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_ਕੱਢੋ(&s->ਅਗਲਾ, ਨਿਰਾ, 0);
		} ਨਹੀਂਤਾਂ
		  gsym(s->jnext);
            } ਨਹੀਂਤਾਂ {
                s = label_ਧੱਕੋ(&global_label_ਢੇਰ, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    ਖੰਡ_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ਨਿਰਾ);

            ਜੇ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ਜੇ (tok != '}') {
                ਜੇ (0 == (flags & STMT_COMPOUND))
                    ਜਾਓ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ਨਹੀਂਤਾਂ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ਨਹੀਂਤਾਂ {
            /* expression case */
            ਜੇ (t != ';') {
                unget_tok(t);
    ਵਿਅੰਜਕ:
                ਜੇ (flags & STMT_ਵਿਅੰਜਕ) {
                    vpop();
                    gexpr();
                } ਨਹੀਂਤਾਂ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ਜੇ (debug_modes)
        tcc_tcov_check_ਸਤਰ (tcc_state, 0), tcc_tcov_ਖੰਡ_ਸਿਰਾ (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ਸਥਿਰ ਖਾਲੀ skip_or_save_ਖੰਡ(TokenString **str)
{
    ਪੂਰਨ braces = tok == '{';
    ਪੂਰਨ level = 0;
    ਜੇ (str)
      *str = tok_str_alloc();

    ਜਦੋਂ (1) {
	ਪੂਰਨ t = tok;
        ਜੇ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             ਰੋਕੋ;
	ਜੇ (t == TOK_EOF) {
	     ਜੇ (str || level > 0)
	       tcc_error("unexpected end of file");
	     ਨਹੀਂਤਾਂ
	       ਰੋਕੋ;
	}
	ਜੇ (str)
	  tok_str_ਜੋੜੋ_tok(*str);
	ਅਗਲਾ();
	ਜੇ (t == '{' || t == '(' || t == '[') {
	    level++;
	} ਨਹੀਂਤਾਂ ਜੇ (t == '}' || t == ')' || t == ']') {
	    level--;
	    ਜੇ (level == 0 && braces && t == '}')
	      ਰੋਕੋ;
	}
    }
    ਜੇ (str)
	tok_str_ਜੋੜੋ(*str, TOK_EOF);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿਅੰਜਕ_CONST 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿਅੰਜਕ_ANY   2

ਸਥਿਰ ਖਾਲੀ parse_init_elem(ਪੂਰਨ ਵਿਅੰਜਕ_type)
{
    ਪੂਰਨ saved_global_ਵਿਅੰਜਕ;
    ਚੋਣ(ਵਿਅੰਜਕ_type) {
    ਹਾਲਤ ਵਿਅੰਜਕ_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_ਵਿਅੰਜਕ = global_ਵਿਅੰਜਕ;
        global_ਵਿਅੰਜਕ = 1;
        ਵਿਅੰਜਕ_const1();
        global_ਵਿਅੰਜਕ = saved_global_ਵਿਅੰਜਕ;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ਜੇ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_ਪਹਿਲਾ_ANOM))
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#ਜੇ_ਅੰਤ
           )
            tcc_error("initializer element is not constant");
        ਰੋਕੋ;
    ਹਾਲਤ ਵਿਅੰਜਕ_ANY:
        ਵਿਅੰਜਕ_eq();
        ਰੋਕੋ;
    }
}

#ਜੇ 1
ਸਥਿਰ ਖਾਲੀ init_assert(init_params *p, ਪੂਰਨ ਵਿੱਥ)
{
    ਜੇ (p->sec ? !NODATA_WANTED && ਵਿੱਥ > p->sec->ਅੰਕੜੇ_ਵਿੱਥ
               : !nocode_wanted && ਵਿੱਥ > p->local_ਵਿੱਥ)
        tcc_ਅੰਦਰੂਨੀ_error("initializer overflow");
}
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ init_assert(sec, ਵਿੱਥ)
#ਜੇ_ਅੰਤ

/* put zeros for variable based init */
ਸਥਿਰ ਖਾਲੀ init_putz(init_params *p, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c, ਪੂਰਨ ਮਾਪ)
{
    init_assert(p, c + ਮਾਪ);
    ਜੇ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ਨਹੀਂਤਾਂ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(ਮਾਪ);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#ਜੇ_ਅੰਤ
        gfunc_call(3);
    }
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIF_ਪਹਿਲਾ     1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIF_ਮਾਪ_ONLY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIF_HAVE_ELEM 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
ਸਥਿਰ ਖਾਲੀ decl_design_delrels(Section *sec, ਪੂਰਨ c, ਪੂਰਨ ਮਾਪ)
{
    ElfW_Rel *rel, *rel2, *rel_ਸਿਰਾ;
    ਜੇ (!sec || !sec->reloc)
        ਵਾਪਸ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->ਅੰਕੜੇ;
    rel_ਸਿਰਾ = (ElfW_Rel*)(sec->reloc->ਅੰਕੜੇ + sec->reloc->ਅੰਕੜੇ_ਵਿੱਥ);
    ਜਦੋਂ (rel < rel_ਸਿਰਾ) {
        ਜੇ (rel->r_ਵਿੱਥ >= c && rel->r_ਵਿੱਥ < c + ਮਾਪ) {
            sec->reloc->ਅੰਕੜੇ_ਵਿੱਥ -= ਆਕਾਰ *rel;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (rel2 != rel)
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(rel2, rel, ਆਕਾਰ *rel);
            ++rel2;
        }
        ++rel;
    }
}

ਸਥਿਰ ਖਾਲੀ decl_design_flex(init_params *p, Sym *ref, ਪੂਰਨ ਸੂਚਕਾਂਕ)
{
    ਜੇ (ref == p->flex_array_ref) {
        ਜੇ (ਸੂਚਕਾਂਕ >= ref->c)
            ref->c = ਸੂਚਕਾਂਕ + 1;
    } ਨਹੀਂਤਾਂ ਜੇ (ref->c < 0 && ਸੂਚਕਾਂਕ >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ਸਥਿਰ ਪੂਰਨ decl_designator(init_params *p, CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c,
                           Sym **cur_ਖੇਤਰ, ਪੂਰਨ flags, ਪੂਰਨ al)
{
    Sym *s, *f;
    ਪੂਰਨ ਸੂਚਕਾਂਕ, ਸੂਚਕਾਂਕ_ਆਖਰੀ, align, l, nb_elems, elem_ਮਾਪ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ corig = c;

    elem_ਮਾਪ = 0;
    nb_elems = 1;

    ਜੇ (flags & DIF_HAVE_ELEM)
        ਜਾਓ no_designator;

    ਜੇ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, ਅਗਲਾ();
        ਜੇ (tok == ':')
            ਜਾਓ struct_ਖੇਤਰ;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ਜਦੋਂ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ਜੇ (tok == '[') {
            ਜੇ (!(type->t & VT_ARRAY))
                expect("array type");
            ਅਗਲਾ();
            ਸੂਚਕਾਂਕ = ਸੂਚਕਾਂਕ_ਆਖਰੀ = ਵਿਅੰਜਕ_const();
            ਜੇ (tok == TOK_DOTS && gnu_ext) {
                ਅਗਲਾ();
                ਸੂਚਕਾਂਕ_ਆਖਰੀ = ਵਿਅੰਜਕ_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, ਸੂਚਕਾਂਕ_ਆਖਰੀ);
            ਜੇ (ਸੂਚਕਾਂਕ < 0 || ਸੂਚਕਾਂਕ_ਆਖਰੀ >= s->c || ਸੂਚਕਾਂਕ_ਆਖਰੀ < ਸੂਚਕਾਂਕ)
	        tcc_error("index exceeds array bounds or range is empty");
            ਜੇ (cur_ਖੇਤਰ)
		(*cur_ਖੇਤਰ)->c = ਸੂਚਕਾਂਕ_ਆਖਰੀ;
            type = pointed_type(type);
            elem_ਮਾਪ = type_ਮਾਪ(type, &align);
            c += ਸੂਚਕਾਂਕ * elem_ਮਾਪ;
            nb_elems = ਸੂਚਕਾਂਕ_ਆਖਰੀ - ਸੂਚਕਾਂਕ + 1;
        } ਨਹੀਂਤਾਂ {
            ਪੂਰਨ cumofs;
            ਅਗਲਾ();
            l = tok;
        struct_ਖੇਤਰ:
            ਅਗਲਾ();
	    f = ਲੱਭੋ_ਖੇਤਰ(type, l, &cumofs);
            ਜੇ (cur_ਖੇਤਰ)
                *cur_ਖੇਤਰ = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_ਖੇਤਰ = ਨਿਰਾ;
    }
    ਜੇ (!cur_ਖੇਤਰ) {
        ਜੇ (tok == '=') {
            ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ ਜੇ (!gnu_ext) {
	    expect("=");
        }
    } ਨਹੀਂਤਾਂ {
    no_designator:
        ਜੇ (type->t & VT_ARRAY) {
	    ਸੂਚਕਾਂਕ = (*cur_ਖੇਤਰ)->c;
            s = type->ref;
            decl_design_flex(p, s, ਸੂਚਕਾਂਕ);
            ਜੇ (ਸੂਚਕਾਂਕ >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_ਮਾਪ = type_ਮਾਪ(type, &align);
            c += ਸੂਚਕਾਂਕ * elem_ਮਾਪ;
        } ਨਹੀਂਤਾਂ {
            f = *cur_ਖੇਤਰ;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ਜਦੋਂ (f && (f->v & SYM_ਪਹਿਲਾ_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_ਖੇਤਰ = f = f->ਅਗਲਾ;
            ਜੇ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ਜੇ (!elem_ਮਾਪ) /* for structs */
        elem_ਮਾਪ = type_ਮਾਪ(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ਜੇ (!(flags & DIF_ਮਾਪ_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_ਮਾਪ * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_ਪਹਿਲਾ);

    ਜੇ (!(flags & DIF_ਮਾਪ_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        ਪੂਰਨ i;
        ਜੇ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_ਮਾਪ;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ਜੇ (p->sec)
            vpush_ref(type, p->sec, c, elem_ਮਾਪ);
        ਨਹੀਂਤਾਂ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        ਲਈ (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_ਮਾਪ * i);
	}
        vpop();
    }

    c += nb_elems * elem_ਮਾਪ;
    ਜੇ (c - corig > al)
      al = c - corig;
    ਵਾਪਸ al;
}

ਸਥਿਰ ਖਾਲੀ write_ldouble(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *d, ਖਾਲੀ *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_CROSS_TEST
    ਜੇ (LDOUBLE_ਮਾਪ >= 10) {
        ਦੁੱਗਣਾ b = *(ਲੰਮਾ ਦੁੱਗਣਾ*)s;
        s = &b;
#ਨਹੀਂਤਾਂ
    ਜੇ (ਆਕਾਰ (ਲੰਮਾ ਦੁੱਗਣਾ) == 8 && LDOUBLE_ਮਾਪ >= 10) {
#ਜੇ_ਅੰਤ
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        ਪੂਰਨ e = m >> 48;
        ਪੂਰਨ f = e >> 4 & 0x7FF;
        m <<= 11;
        ਜੇ (0 == f) {
            ਜੇ (0 == m)
                ਜਾਓ ਸੈੱਟ;
            ਲਈ (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ਜੇ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    ਸੈੱਟ:
    #ਜੇ (defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #ਜਾਂਜੇ LDOUBLE_ਮਾਪ == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ਜੇ_ਅੰਤ
        ;
    } ਨਹੀਂਤਾਂ {
    #ਜੇ LDOUBLE_ਮਾਪ == 8
        /* long double -> double */
        ਦੁੱਗਣਾ b = *(ਲੰਮਾ ਦੁੱਗਣਾ*)s;
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(d, &b, 8);
    #ਜਾਂਜੇ (__i386__ || __x86_64__) && (defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        /* extended -> extended */
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(d, s, 10);
    #ਜਾਂਜੇ (__i386__ || __x86_64__) && (defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        ਪੂਰਨ e = *(uint16_t*)((ਅੱਖਰ*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #ਜਾਂਜੇ (__aarch64__ || __riscv) && (defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((ਅੱਖਰ*)s + 6);
        ਪੂਰਨ e = read16le((ਅੱਖਰ*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ਨਹੀਂਤਾਂ
        /* unknown */
        ਜੇ (ਆਕਾਰ (ਲੰਮਾ ਦੁੱਗਣਾ) == LDOUBLE_ਮਾਪ)
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(d, s, LDOUBLE_ਮਾਪ);
    #ਜੇ_ਅੰਤ
    }
}

/* store a value or an expression directly in global data or in local array */
ਸਥਿਰ ਖਾਲੀ init_putv(init_params *p, CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c)
{
    ਪੂਰਨ bt;
    ਖਾਲੀ *ptr;
    CType dtype;
    ਪੂਰਨ ਮਾਪ, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    ਮਾਪ = type_ਮਾਪ(type, &align);
    ਜੇ (type->t & VT_BITFIELD)
        ਮਾਪ = (ਦੋਆਧਾਰੀ_ਅੰਕ_POS(type->t) + ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(type->t) + 7) / 8;
    init_assert(p, c + ਮਾਪ);

    ਜੇ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_ਸੌਂਪੋ_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ਜੇ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_ਮਾਪ == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_ਪਹਿਲਾ_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ਜੇ (NODATA_WANTED) {
            vtop--;
            ਵਾਪਸ;
        }

        ptr = sec->ਅੰਕੜੇ + c;
        val = vtop->c.i;

	ਜੇ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_ਪਹਿਲਾ_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->ਅੰਕੜੇ + esym->st_ਮੁੱਲ + (ਪੂਰਨ)vtop->c.i, ਮਾਪ);
	    ਜੇ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ relofs = ssec->reloc->ਅੰਕੜੇ_ਵਿੱਥ;
		ਜਦੋਂ (relofs >= ਆਕਾਰ(*rel)) {
                    relofs -= ਆਕਾਰ(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->ਅੰਕੜੇ + relofs);
		    ਜੇ (rel->r_ਵਿੱਥ >= esym->st_ਮੁੱਲ + ਮਾਪ)
		      ਜਾਰੀ;
		    ਜੇ (rel->r_ਵਿੱਥ < esym->st_ਮੁੱਲ)
		      ਰੋਕੋ;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_ਵਿੱਥ - esym->st_ਮੁੱਲ,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ਜੇ PTR_ਮਾਪ == 8
				   rel->r_addend
#ਨਹੀਂਤਾਂ
				   0
#ਜੇ_ਅੰਤ
				  );
		}
	    }
	} ਨਹੀਂਤਾਂ {
            ਜੇ (type->t & VT_BITFIELD) {
                ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ_pos, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2, ਬਿੱਟ, n;
                ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, v, m;
                ਦੋਆਧਾਰੀ_ਅੰਕ_pos = ਦੋਆਧਾਰੀ_ਅੰਕ_POS(vtop->type.t);
                ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(vtop->type.t);
                p = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ*)ptr + (ਦੋਆਧਾਰੀ_ਅੰਕ_pos >> 3);
                ਦੋਆਧਾਰੀ_ਅੰਕ_pos &= 7, ਬਿੱਟ = 0;
                ਜਦੋਂ (ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2) {
                    n = 8 - ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
                    ਜੇ (n > ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2)
                        n = ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2;
                    v = val >> ਬਿੱਟ << ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
                    m = ((1 << n) - 1) << ਦੋਆਧਾਰੀ_ਅੰਕ_pos;
                    *p = (*p & ~m) | (v & m);
                    ਬਿੱਟ += n, ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ_2 -= n, ਦੋਆਧਾਰੀ_ਅੰਕ_pos = 0, ++p;
                }
            } ਨਹੀਂਤਾਂ
            ਚੋਣ(bt) {
	    ਹਾਲਤ VT_BOOL:
		*(ਅੱਖਰ *)ptr = val != 0;
                ਰੋਕੋ;
	    ਹਾਲਤ VT_BYTE:
		*(ਅੱਖਰ *)ptr = val;
		ਰੋਕੋ;
	    ਹਾਲਤ VT_SHORT:
                write16le(ptr, val);
		ਰੋਕੋ;
	    ਹਾਲਤ VT_FLOAT:
                write32le(ptr, val);
		ਰੋਕੋ;
	    ਹਾਲਤ VT_DOUBLE:
                write64le(ptr, val);
		ਰੋਕੋ;
	    ਹਾਲਤ VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		ਰੋਕੋ;

#ਜੇ PTR_ਮਾਪ == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    ਹਾਲਤ VT_LLONG:
	    ਹਾਲਤ VT_PTR:
	        ਜੇ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_ਅੰਕੜੇ_PTR, val);
	        ਨਹੀਂਤਾਂ
	          write64le(ptr, val);
	        ਰੋਕੋ;
            ਹਾਲਤ VT_INT:
                write32le(ptr, val);
                ਰੋਕੋ;
#ਨਹੀਂਤਾਂ
	    ਹਾਲਤ VT_LLONG:
                write64le(ptr, val);
                ਰੋਕੋ;
            ਹਾਲਤ VT_PTR:
            ਹਾਲਤ VT_INT:
	        ਜੇ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_ਅੰਕੜੇ_PTR);
	        write32le(ptr, val);
	        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
	    ਮੂਲ:
                //tcc_internal_error("unexpected type");
                ਰੋਕੋ;
	    }
	}
        vtop--;
    } ਨਹੀਂਤਾਂ {
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
ਸਥਿਰ ਖਾਲੀ decl_initializer(init_params *p, CType *type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ c, ਪੂਰਨ flags)
{
    ਪੂਰਨ len, n, no_oblock, i;
    ਪੂਰਨ size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ਜੇ (debug_modes && !(flags & DIF_ਮਾਪ_ONLY) && !p->sec)
        tcc_debug_ਸਤਰ(tcc_state), tcc_tcov_check_ਸਤਰ (tcc_state, 1);

    ਜੇ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_ਮਾਪ_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        ਪੂਰਨ ncw_prev = nocode_wanted;
        ਜੇ ((flags & DIF_ਮਾਪ_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? ਵਿਅੰਜਕ_ANY : ਵਿਅੰਜਕ_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ਜੇ (type->t & VT_ARRAY) {
        no_oblock = 1;
        ਜੇ (((flags & DIF_ਪਹਿਲਾ) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_ਮਾਪ(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        ਜੇ ((tok == TOK_LSTR && 
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ਨਹੀਂਤਾਂ
             (t1->t & VT_BTYPE) == VT_INT
#ਜੇ_ਅੰਤ
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ਜੇ (size1 != (tok == TOK_STR ? 1 : ਆਕਾਰ(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ਜਦੋਂ (tok == TOK_STR || tok == TOK_LSTR) {
                ਜੇ (initstr.ਮਾਪ)
                  initstr.ਮਾਪ -= size1;
                ਜੇ (tok == TOK_STR)
                  len += tokc.str.ਮਾਪ;
                ਨਹੀਂਤਾਂ
                  len += tokc.str.ਮਾਪ / ਆਕਾਰ(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.ਅੰਕੜੇ, tokc.str.ਮਾਪ);
                ਅਗਲਾ();
            }
            ਜੇ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.ਮਾਪ = initstr.ਮਾਪ;
                tokc.str.ਅੰਕੜੇ = initstr.ਅੰਕੜੇ;
                ਜਾਓ do_init_array;
            }

            decl_design_flex(p, s, len);
            ਜੇ (!(flags & DIF_ਮਾਪ_ONLY)) {
                ਪੂਰਨ nb = n, ch;
                ਜੇ (len < nb)
                    nb = len;
                ਜੇ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ਜੇ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ਜੇ (!NODATA_WANTED)
                      ਸਮ੍ਰਿਤੀ_ਨਕਲ(p->sec->ਅੰਕੜੇ + c, initstr.ਅੰਕੜੇ, nb);
                } ਨਹੀਂਤਾਂ {
                    ਲਈ(i=0;i<n;i++) {
                        ਜੇ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ਜੇ (flags & DIF_CLEAR)
                            ਰੋਕੋ;
                          ਜੇ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            ਰੋਕੋ;
                          }
                          ch = 0;
                        } ਨਹੀਂਤਾਂ ਜੇ (size1 == 1)
                          ch = ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)initstr.ਅੰਕੜੇ)[i];
                        ਨਹੀਂਤਾਂ
                          ch = ((nwchar_t *)initstr.ਅੰਕੜੇ)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ਜੇ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ਜੇ (!(flags & (DIF_CLEAR | DIF_ਮਾਪ_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ਜਦੋਂ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ਜੇ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ਜੇ (no_oblock && len >= n*size1)
		        ਰੋਕੋ;
		} ਨਹੀਂਤਾਂ {
		    ਜੇ (s->type.t == VT_UNION)
		        f = ਨਿਰਾ;
		    ਨਹੀਂਤਾਂ
		        f = f->ਅਗਲਾ;
		    ਜੇ (no_oblock && f == ਨਿਰਾ)
		        ਰੋਕੋ;
		}

		ਜੇ (tok == '}')
		    ਰੋਕੋ;
		skip(',');
	    }
        }
        ਜੇ (!no_oblock)
            skip('}');

    } ਨਹੀਂਤਾਂ ਜੇ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        ਜਾਓ one_elem;

    } ਨਹੀਂਤਾਂ ਜੇ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ਜੇ ((flags & DIF_ਪਹਿਲਾ) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->ਅਗਲਾ;
        n = s->c;
        size1 = 1;
	ਜਾਓ do_init_list;

    } ਨਹੀਂਤਾਂ ਜੇ (tok == '{') {
        ਜੇ (flags & DIF_HAVE_ELEM)
          skip(';');
        ਅਗਲਾ();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ਨਹੀਂਤਾਂ one_elem: ਜੇ ((flags & DIF_ਮਾਪ_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ਜੇ (flags & DIF_HAVE_ELEM)
            vpop();
        ਨਹੀਂਤਾਂ
            skip_or_save_ਖੰਡ(ਨਿਰਾ);

    } ਨਹੀਂਤਾਂ {
	ਜੇ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ਜੇ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? ਵਿਅੰਜਕ_ANY : ਵਿਅੰਜਕ_CONST);
	}
        ਜੇ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_ਮਾਪ(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ਨਹੀਂਤਾਂ
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
ਸਥਿਰ ਖਾਲੀ decl_initializer_alloc(CType *type, AttributeDef *ad, ਪੂਰਨ r, 
                                   ਪੂਰਨ has_init, ਪੂਰਨ v, ਪੂਰਨ scope)
{
    ਪੂਰਨ ਮਾਪ, align, addr;
    TokenString *init_str = ਨਿਰਾ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ਨਿਰਾ;
    ਪੂਰਨ saved_nocode_wanted = nocode_wanted;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਪੂਰਨ bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#ਜੇ_ਅੰਤ
    init_params p = {0};

    ਜੇ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_ਲੱਭੋ(v);
        ਜੇ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ਜੇ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ਵਾਪਸ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ਜੇ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= ਅੰਕੜੇ_ONLY_WANTED;

    flexible_array = ਨਿਰਾ;
    ਮਾਪ = type_ਮਾਪ(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ਜੇ (ਮਾਪ < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ਜੇ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ਜੇ (IS_BT_ARRAY(type->t))
            type->ref = sym_ਧੱਕੋ(SYM_ਖੇਤਰ, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ਨਹੀਂਤਾਂ ਜੇ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ਖੇਤਰ = type->ref->ਅਗਲਾ;
        ਜੇ (ਖੇਤਰ) {
            ਜਦੋਂ (ਖੇਤਰ->ਅਗਲਾ)
                ਖੇਤਰ = ਖੇਤਰ->ਅਗਲਾ;
            ਜੇ (ਖੇਤਰ->type.t & VT_ARRAY && ਖੇਤਰ->type.ref->c < 0) {
                flexible_array = ਖੇਤਰ;
                p.flex_array_ref = ਖੇਤਰ->type.ref;
                ਮਾਪ = -1;
            }
        }
    }

    ਜੇ (ਮਾਪ < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ਜੇ (!has_init)
            ਜਾਓ err_ਮਾਪ;
        ਜੇ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ਜਦੋਂ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_ਜੋੜੋ_tok(init_str);
                ਅਗਲਾ();
            }
            tok_str_ਜੋੜੋ(init_str, TOK_EOF);
        } ਨਹੀਂਤਾਂ
            skip_or_save_ਖੰਡ(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        ਅਗਲਾ();
        decl_initializer(&p, type, 0, DIF_ਪਹਿਲਾ | DIF_ਮਾਪ_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        ਅਗਲਾ();

        /* if still unknown size, error */
        ਮਾਪ = type_ਮਾਪ(type, &align);
        ਜੇ (ਮਾਪ < 0)
    err_ਮਾਪ:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ਜੇ (flexible_array && flexible_array->type.ref->c > 0)
            ਮਾਪ += flexible_array->type.ref->c
                    * pointed_ਮਾਪ(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ਜੇ (ad->a.aligned) {
	ਪੂਰਨ speca = 1 << (ad->a.aligned - 1);
        ਜੇ (speca > align)
            align = speca;
    } ਨਹੀਂਤਾਂ ਜੇ (ad->a.packed) {
        align = 1;
    }

    ਜੇ (!v && NODATA_WANTED)
        ਮਾਪ = 0, align = 1;

    ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ਨਿਰਾ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#ਜੇ_ਅੰਤ
        loc = (loc - ਮਾਪ) & -align;
        addr = loc;
        p.local_ਵਿੱਥ = addr + ਮਾਪ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#ਜੇ_ਅੰਤ
        ਜੇ (v) {
            /* local variable */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_ASM
	    ਜੇ (ad->asm_label) {
		ਪੂਰਨ reg = asm_parse_regvar(ad->asm_label);
		ਜੇ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#ਜੇ_ਅੰਤ
            sym = sym_ਧੱਕੋ(v, type, r, addr);
	    ਜੇ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_ਖੇਤਰ | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->ਅਗਲਾ = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ਨਹੀਂਤਾਂ {
            /* push local reference */
            vset(type, r, addr);
        }
    } ਨਹੀਂਤਾਂ {
        CType *tp = type;
        ਪੂਰਨ is_const;

        ਜਦੋਂ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ਜੇ (!sec) {
            ਜੇ (type->t & VT_TLS) {
                sec = ਲੱਭੋ_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ਨਹੀਂਤਾਂ ਜੇ (is_const) {
		sec = rodata_section;
            } ਨਹੀਂਤਾਂ ਜੇ (has_init) {
		sec = ਅੰਕੜੇ_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ਨਹੀਂਤਾਂ ਜੇ (tcc_state->nocommon)
                sec = bss_section;
        } ਨਹੀਂਤਾਂ ਜੇ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ਜੇ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ਜੇ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (bcheck)
            ਮਾਪ = ਮਾਪ + 1; /* add padding */
#ਜੇ_ਅੰਤ
        ਜੇ (sec) {
	    addr = section_ਜੋੜੋ(sec, ਮਾਪ, align);
        } ਨਹੀਂਤਾਂ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ਜੇ (v) {
            ਜੇ (!sym) {
                sym = sym_ਧੱਕੋ(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ਨਿਰਾ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, ਮਾਪ);
        } ਨਹੀਂਤਾਂ {
            /* push global reference */
            vpush_ref(type, sec, addr, ਮਾਪ);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ਜੇ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->ਅੰਕੜੇ_ਵਿੱਥ, R_ਅੰਕੜੇ_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_ਜੋੜੋ(bounds_section, 2 * ਆਕਾਰ(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = ਮਾਪ - 1;
        }
#ਜੇ_ਅੰਤ
    }

    ਜੇ (type->t & VT_VLA) {
        ਪੂਰਨ a;

        ਜੇ (has_init)
            tcc_error("variable length array cannot be initialized");

        ਜੇ (NODATA_WANTED)
            ਜਾਓ no_alloc;

        /* save before-VLA stack pointer if needed */
        ਜੇ (cur_scope->vla.ਅੰਕ == 0) {
            ਜੇ (cur_scope->prev && cur_scope->prev->vla.ਅੰਕ) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } ਨਹੀਂਤਾਂ {
                gen_vla_sp_save(loc -= PTR_ਮਾਪ);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_ਮਾਪ(type, &a);
        gen_vla_alloc(type, a);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE && defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_ਨਤੀਜਾ(addr), addr = (loc -= PTR_ਮਾਪ);
#ਜੇ_ਅੰਤ
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.ਅੰਕ++;
    } ਨਹੀਂਤਾਂ ਜੇ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_ਪਹਿਲਾ);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ਜੇ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ਜੇ (init_str) {
        ਸਿਰਾ_macro();
        ਅਗਲਾ();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ਸਥਿਰ ਖਾਲੀ func_vla_arg_ਕੋਡ(Sym *arg)
{
    ਪੂਰਨ align;
    TokenString *vla_array_tok = ਨਿਰਾ;

    ਜੇ (arg->type.ref)
        func_vla_arg_ਕੋਡ(arg->type.ref);

    ਜੇ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_ਮਾਪ(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	ਅਗਲਾ();
	gexpr();
	ਸਿਰਾ_macro();
	ਅਗਲਾ();
	vpush_type_ਮਾਪ(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

ਸਥਿਰ ਖਾਲੀ func_vla_arg(Sym *sym)
{
    Sym *arg;

    ਲਈ (arg = sym->type.ref->ਅਗਲਾ; arg; arg = arg->ਅਗਲਾ)
        ਜੇ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_ਕੋਡ(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_ਸੈੱਟ_param(Sym *s, ਪੂਰਨ c, ਪੂਰਨ byref)
{
    s = sym_ਲੱਭੋ(s->v);
    ਜੇ (!s) /* unnamed parameters, not enabled */
        ਵਾਪਸ ਨਿਰਾ;
    s->c = c;
    ਜੇ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ਵਾਪਸ s;
}

/* push parameters (and their types), last first */
ਸਥਿਰ ਖਾਲੀ sym_ਧੱਕੋ_params(Sym *ref)
{
    Sym *s = ref;
    ਜਦੋਂ (s->ਅਗਲਾ)
        s = s->ਅਗਲਾ;
    ਜਦੋਂ (s != ref) {
        ਜੇ ((s->v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM)
            sym_copy(s, &local_ਢੇਰ);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ਸਥਿਰ ਖਾਲੀ gen_function(Sym *sym)
{
    ਬਣਤਰ scope f = { 0 };

    cur_scope = ਜੜ੍ਹ_scope = &f;
    nocode_wanted = 0;

    ind = cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;
    ਜੇ (sym->a.aligned) {
	ਮਾਪ_t newoff = section_ਜੋੜੋ(cur_ਪਾਠ_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ਨਿਰਾ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_ਪਾਠ_section, ind, 0);

    ਜੇ (sym->type.ref->f.func_ctor)
        ਜੋੜੋ_array (tcc_state, ".init_array", sym->c);
    ਜੇ (sym->type.ref->f.func_dtor)
        ਜੋੜੋ_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ਢੇਰ, SYM_ਖੇਤਰ, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ਧੱਕੋ_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_ਆਰਜ਼ੀ_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    ਖੰਡ(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_ਸਿਰਾ_scope(ਨਿਰਾ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_ਮਾਪ = ind - func_ind;
    cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ = ind;

    sym_ਕੱਢੋ(&local_ਢੇਰ, ਨਿਰਾ, 0);
    label_ਕੱਢੋ(&global_label_ਢੇਰ, ਨਿਰਾ, 0);
    sym_ਕੱਢੋ(&all_cleanups, ਨਿਰਾ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_ਪਾਠ_section = ਨਿਰਾ;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = ਅੰਕੜੇ_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    ਅਗਲਾ();
}

ਸਥਿਰ ਖਾਲੀ gen_inline_functions(TCCState *s)
{
    Sym *sym;
    ਪੂਰਨ inline_generated, i;
    ਬਣਤਰ InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    ਕਰੋ {
        inline_generated = 0;
        ਲਈ (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ਜੇ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ਨਿਰਾ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                ਅਗਲਾ();
                cur_ਪਾਠ_section = ਪਾਠ_section;
                gen_function(sym);
                ਸਿਰਾ_macro();

                inline_generated = 1;
            }
        }
    } ਜਦੋਂ (inline_generated);
    tcc_close();
}

ਸਥਿਰ ਖਾਲੀ free_inline_functions(TCCState *s)
{
    ਪੂਰਨ i;
    /* free tokens of unused inline functions */
    ਲਈ (i = 0; i < s->nb_inline_fns; ++i) {
        ਬਣਤਰ InlineFunc *fn = s->inline_fns[i];
        ਜੇ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ਸਥਿਰ ਖਾਲੀ do_Static_assert(ਖਾਲੀ)
{
    ਪੂਰਨ c;
    ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ;

    ਅਗਲਾ();
    skip('(');
    c = ਵਿਅੰਜਕ_const();
    ਸੁਨੇਹਾ = "_Static_assert fail";
    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        ਸੁਨੇਹਾ = parse_mult_str("string constant")->ਅੰਕੜੇ;
    }
    skip(')');
    ਜੇ (c == 0)
        tcc_error("%s", ਸੁਨੇਹਾ);
    skip(';');
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ਸਥਿਰ ਖਾਲੀ pe_check_linkage(CType *type, AttributeDef *ad)
{
    ਜੇ (!ad->a.dllimport && !ad->a.dllexport)
        ਵਾਪਸ;
    ਜੇ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ਜੇ (type->t & VT_TYPEDEF) {
        ਅਚਲ ਅੱਖਰ *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ਨਹੀਂਤਾਂ ਜੇ (ad->a.dllimport) {
        ਜੇ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ਨਹੀਂਤਾਂ
            type->t |= VT_EXTERN;
    }
}
#ਜੇ_ਅੰਤ

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ਸਥਿਰ ਪੂਰਨ decl(ਪੂਰਨ l)
{
    ਪੂਰਨ v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ਜਦੋਂ (1) {

        oldint = 0;
        ਜੇ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ਜੇ (l == VT_JMP)
                ਵਾਪਸ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ਜੇ (tok == ';' && l != VT_CMP) {
                ਅਗਲਾ();
                ਜਾਰੀ;
            }
            ਜੇ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ਜਾਰੀ;
            }
            ਜੇ (l != VT_CONST)
                ਰੋਕੋ;
            ਜੇ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ਜਾਰੀ;
            }
            ਜੇ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ਨਹੀਂਤਾਂ {
                ਜੇ (tok != TOK_EOF)
                    expect("declaration");
                ਰੋਕੋ;
            }
        }

        ਜੇ (tok == ';') {
            ਜੇ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_ਪਹਿਲਾ_ANOM)
                ; /* struct decl with named tag */
            ਨਹੀਂਤਾਂ ਜੇ (IS_ENUM(btype.t))
                ; /* enum decl */
            ਨਹੀਂਤਾਂ
                tcc_warning("useless type defines no instances");
            ਜੇ (l == VT_JMP)
                ਵਾਪਸ 1;
            ਅਗਲਾ();
            ਜਾਰੀ;
        }

        ਜਦੋਂ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_ਸਿੱਧਾ | TYPE_PARAM : TYPE_ਸਿੱਧਾ);
            /*ptype("decl", &type, v);*/
            ਜੇ ((type.t & VT_BTYPE) == VT_FUNC) {
                ਜੇ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ਜੇ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ਜੇ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ਜੇ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ਨਹੀਂਤਾਂ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ਨਹੀਂਤਾਂ ਜੇ (oldint) {
                tcc_warning("type defaults to int");
            }

            ਜੇ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ਜੇ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ਜੇ (tok == '{')
                    expect(";");
            #ਜੇ_ਅੰਤ
            }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            pe_check_linkage(&type, &ad);
#ਜੇ_ਅੰਤ
            ਜੇ (tok == '{') {
                ਜੇ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ਜੇ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                ਮਿਲਾਓ_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                ਲਈ (sa = sym->type.ref; (sa = sa->ਅਗਲਾ) != ਨਿਰਾ;) {
                    ਜੇ (!(sa->v & ~SYM_ਖੇਤਰ))
                        expect("identifier");
                    ਜੇ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ਜੇ (sym->type.t & VT_INLINE) {
                    ਬਣਤਰ InlineFunc *fn;
                    fn = tcc_malloc(ਆਕਾਰ *fn + ਲੜੀ_ਲੰਬਾਈ(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_ਜੋੜੋ(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_ਖੰਡ(&fn->func_str);
                } ਨਹੀਂਤਾਂ {
                    /* compute text section */
                    cur_ਪਾਠ_section = ਪਾਠ_section;
                    ਜੇ (ad.section) {
                        cur_ਪਾਠ_section = ad.section;
                        ਜੇ (ad.new_section)
                            ad.section->sh_flags = ਪਾਠ_section->sh_flags;
                    }
                    gen_function(sym);
                }
                ਰੋਕੋ;
            } ਨਹੀਂਤਾਂ {
                has_init = 0;
		ਜੇ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    ਲਈ (sym = func_vt.ref->ਅਗਲਾ; sym; sym = sym->ਅਗਲਾ)
			ਜੇ ((sym->v & ~SYM_ਖੇਤਰ) == v)
			    ਜਾਓ ਮਿਲਿਆ;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ਨਿਰਾ));
                ਮਿਲਿਆ:
		    ਜੇ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ਨਿਰਾ));
		    ਜੇ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ਨਿਰਾ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ਨਹੀਂਤਾਂ ਜੇ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_ਲੱਭੋ(v);
                    ਜੇ (sym && sym->sym_scope == local_scope) {
                        ਜੇ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ਨਿਰਾ));
                        sym->type = type;
                    } ਨਹੀਂਤਾਂ {
                        sym = sym_ਧੱਕੋ(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ਜੇ ((type.t & VT_BTYPE) == VT_FUNC)
                      ਮਿਲਾਓ_funcattr(&sym->type.ref->f, &ad.f);
                    ਜੇ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ਨਹੀਂਤਾਂ ਜੇ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ਨਹੀਂਤਾਂ {
                    r = 0;
                    ਜੇ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        ਮਿਲਾਓ_funcattr(&type.ref->f, &ad.f);
                    } ਨਹੀਂਤਾਂ ਜੇ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ਜੇ (tok == '=')
                        has_init = 1;

                    ਜੇ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ਨਹੀਂਤਾਂ {
                        ਜੇ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ਨਹੀਂਤਾਂ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ਜੇ (has_init)
                            ਅਗਲਾ();
                        ਨਹੀਂਤਾਂ ਜੇ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ਜੇ (ad.alias_ਨਿਸ਼ਾਨਾ && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_ਲੱਭੋ(ad.alias_ਨਿਸ਼ਾਨਾ));
                        ਜੇ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_ਲੱਭੋ(v), esym->st_shndx,
                                        esym->st_ਮੁੱਲ, esym->st_ਮਾਪ, 1);
                    }
                }
                ਜੇ (tok != ',') {
                    ਜੇ (l == VT_JMP)
                        ਵਾਪਸ has_init ? v : 1;
                    skip(';');
                    ਰੋਕੋ;
                }
                ਅਗਲਾ();
            }
        }
    }
    ਵਾਪਸ 0;
}

/* ------------------------------------------------------------------------- */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ gjmp_addr
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ gjmp
/* ------------------------------------------------------------------------- */
