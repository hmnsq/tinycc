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

#تعریف_کړه USING_GLOBALS
#ضمن "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_معلومات صحيح rsym, anon_sym, ind, loc;

ST_معلومات Sym *global_ډېری;
ST_معلومات Sym *local_ډېری;
ST_معلومات Sym *define_ډېری;
ST_معلومات Sym *global_label_ډېری;
ST_معلومات Sym *local_label_ډېری;

ساكن Sym *sym_free_لومړی;
ساكن فراغ **sym_pools;
ساكن صحيح nb_sym_pools;

ساكن Sym *all_cleanups, *pending_gotos;
ساكن صحيح local_scope;
ST_معلومات حرف debug_modes;

ST_معلومات SValue *vtop;
ساكن SValue _vstack[1 + VSTACK_اندازه];
#تعریف_کړه vstack (_vstack + 1)

ST_معلومات صحيح nocode_wanted; /* no code generation wanted */
#تعریف_کړه NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#تعریف_کړه معلومات_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#تعریف_کړه کوډ_OFF_بټ 0x20000000
#تعریف_کړه کوډ_OFF() إذا(!nocode_wanted)(nocode_wanted |= کوډ_OFF_بټ)
#تعریف_کړه کوډ_ON() (nocode_wanted &= ~کوډ_OFF_بټ)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#تعریف_کړه NOEVAL_ماسک 0x0000FFFF
#تعریف_کړه NOEVAL_WANTED (nocode_wanted & NOEVAL_ماسک)

/* no code output when parsing constant expressions */
#تعریف_کړه CONST_WANTED_بټ  0x00010000
#تعریف_کړه CONST_WANTED_ماسک 0x0FFF0000
#تعریف_کړه CONST_WANTED  (nocode_wanted & CONST_WANTED_ماسک)

ST_معلومات صحيح global_بیان;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_معلومات CType func_vt; /* current function return type (used by return instruction) */
ST_معلومات صحيح func_var; /* true if current function is variadic (used by return instruction) */
ST_معلومات صحيح func_vc; /* stack address for implicit struct return storage */
ST_معلومات صحيح func_ind; /* function start address */
ساكن صحيح func_old;
ST_معلومات ثابت حرف *funcname;
ST_معلومات CType int_type, func_old_type, char_type, char_اشاره_ګر_type;
ساكن CString initstr;

#إذا PTR_اندازه == 4
#تعریف_کړه VT_اندازه_T (VT_INT | VT_UNSIGNED)
#تعریف_کړه VT_PTRDIFF_T VT_INT
#وإلاإذا LONG_اندازه == 4
#تعریف_کړه VT_اندازه_T (VT_LLONG | VT_UNSIGNED)
#تعریف_کړه VT_PTRDIFF_T VT_LLONG
#وإلا
#تعریف_کړه VT_اندازه_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#تعریف_کړه VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#د_که_پای

ساكن بنية switch_t {
    بنية case_t {
        int64_t v1, v2;
        صحيح ind, کرښه;
    } **p; صحيح n; /* list of case ranges */
    صحيح def_sym; /* default symbol */
    صحيح nocode_wanted;
    صحيح *bsym;
    بنية scope *scope;
    بنية switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#تعریف_کړه MAX_لنډمهاله_LOCAL_VARIABLE_شمېره 8
/*list of temporary local variables on the stack in current function. */
ساكن بنية لنډمهاله_local_variable {
	صحيح location; //offset on stack. Svalue.c.i
	لنډ اندازه;
	لنډ align;
} arr_لنډمهاله_local_vars[MAX_لنډمهاله_LOCAL_VARIABLE_شمېره];
ساكن صحيح nb_لنډمهاله_local_vars;

ساكن بنية scope {
    بنية scope *prev;
    بنية { صحيح loc, locorig, عدد; } vla;
    بنية { Sym *s; صحيح n; } cl;
    صحيح *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ریښه_scope;

تعريفنوع بنية {
    Section *sec;
    صحيح local_دننه_واټن;
    Sym *flex_array_ref;
} init_params;

#إذا 1
#تعریف_کړه precedence_parser
ساكن فراغ init_prec(فراغ);
#د_که_پای

ساكن فراغ بلاک(صحيح flags);
#تعریف_کړه STMT_بیان 1
#تعریف_کړه STMT_COMPOUND 2

ساكن فراغ gen_cast(CType *type);
ساكن فراغ gen_cast_s(صحيح t);
ساكن مضمن CType *pointed_type(CType *type);
ساكن فراغ check_restrict_type(CType *type);
ساكن صحيح type_qualifiers(CType *type);
ساكن فراغ parse_btype_qualify(CType *type, صحيح qualifiers);
ساكن صحيح is_compatible_types(CType *type1, CType *type2);
ساكن صحيح parse_btype(CType *type, AttributeDef *ad, صحيح ignore_label);
ساكن CType *type_decl(CType *type, AttributeDef *ad, صحيح *v, صحيح td);
ساكن فراغ parse_بیان_type(CType *type);
ساكن فراغ init_putv(init_params *p, CType *type, بینښه اوږد c);
ساكن فراغ decl_initializer(init_params *p, CType *type, بینښه اوږد c, صحيح flags);
ساكن فراغ decl_initializer_alloc(CType *type, AttributeDef *ad, صحيح r, صحيح has_init, صحيح v, صحيح scope);
ساكن صحيح decl(صحيح l);
ساكن فراغ بیان_eq(فراغ);
ساكن فراغ vpush_type_اندازه(CType *type, صحيح *a);
ساكن صحيح is_compatible_unqualified_types(CType *type1, CType *type2);
ساكن مضمن int64_t بیان_const64(فراغ);
ساكن فراغ vpush64(صحيح ty, بینښه اوږد اوږد v);
ساكن فراغ vpush(CType *type);
ساكن صحيح gvtst(صحيح inv, صحيح t);
ساكن فراغ gen_inline_functions(TCCState *s);
ساكن فراغ free_inline_functions(TCCState *s);
ساكن فراغ skip_or_save_بلاک(TokenString **str);
ساكن فراغ gv_dup(فراغ);
ساكن صحيح get_لنډمهاله_local_var(صحيح اندازه,صحيح align,صحيح *r2);
ساكن فراغ cast_error(CType *st, CType *dt);
ساكن فراغ پای_ټکی_switch(فراغ);
ساكن فراغ do_Static_assert(فراغ);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC فراغ gsym(صحيح t)
{
  إذا (t) {
    gsym_addr(t, ind);
    کوډ_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ساكن صحيح gind()
{
  صحيح t = ind;
  کوډ_ON();
  إذا (debug_modes)
    tcc_tcov_بلاک_begin(tcc_state);
  أرجع t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ساكن فراغ gjmp_addr_acs(صحيح t)
{
  gjmp_addr(t);
  کوډ_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ساكن صحيح gjmp_acs(صحيح t)
{
  t = gjmp(t);
  کوډ_OFF();
  أرجع t;
}

/* These are #undef'd at the end of this file */
#تعریف_کړه gjmp_addr gjmp_addr_acs
#تعریف_کړه gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN صحيح is_float(صحيح t)
{
    صحيح bt = t & VT_BTYPE;
    أرجع bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ساكن مضمن صحيح is_integer_btype(صحيح bt)
{
    أرجع bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ساكن صحيح btype_اندازه(صحيح bt)
{
    أرجع bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_اندازه : 0;
}

/* returns function return register from type */
ساكن صحيح R_RET(صحيح t)
{
    إذا (!is_float(t))
        أرجع REG_IRET;
#که_تعریف_شوی TCC_موخه_X86_64
    إذا ((t & VT_BTYPE) == VT_LDOUBLE)
        أرجع TREG_ST0;
#وإلاإذا defined TCC_موخه_RISCV64
    إذا ((t & VT_BTYPE) == VT_LDOUBLE)
        أرجع REG_IRET;
#د_که_پای
    أرجع REG_FRET;
}

/* returns 2nd function return register, if any */
ساكن صحيح R2_RET(صحيح t)
{
    t &= VT_BTYPE;
#إذا PTR_اندازه == 4
    إذا (t == VT_LLONG)
        أرجع REG_IRE2;
#وإلاإذا defined TCC_موخه_X86_64
    إذا (t == VT_QLONG)
        أرجع REG_IRE2;
    إذا (t == VT_QFLOAT)
        أرجع REG_FRE2;
#وإلاإذا defined TCC_موخه_RISCV64
    إذا (t == VT_LDOUBLE)
        أرجع REG_IRE2;
#د_که_پای
    أرجع VT_CONST;
}

/* returns true for two-word types */
#تعریف_کړه USING_TWO_ټکي(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ساكن فراغ PUT_R_RET(SValue *sv, صحيح t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ساكن صحيح RC_RET(صحيح t)
{
    أرجع reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ساكن صحيح RC_TYPE(صحيح t)
{
    إذا (!is_float(t))
        أرجع RC_INT;
#که_تعریف_شوی TCC_موخه_X86_64
    إذا ((t & VT_BTYPE) == VT_LDOUBLE)
        أرجع RC_ST0;
    إذا ((t & VT_BTYPE) == VT_QFLOAT)
        أرجع RC_FRET;
#وإلاإذا defined TCC_موخه_RISCV64
    إذا ((t & VT_BTYPE) == VT_LDOUBLE)
        أرجع RC_INT;
#د_که_پای
    أرجع RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ساكن صحيح RC2_TYPE(صحيح t, صحيح rc)
{
    إذا (!USING_TWO_ټکي(t))
        أرجع 0;
#که_تعریف_شوی RC_IRE2
    إذا (rc == RC_IRET)
        أرجع RC_IRE2;
#د_که_پای
#که_تعریف_شوی RC_FRE2
    إذا (rc == RC_FRET)
        أرجع RC_FRE2;
#د_که_پای
    إذا (rc & RC_FLOAT)
        أرجع RC_FLOAT;
    أرجع RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC صحيح ieee_finite(مزدوج d)
{
    صحيح p[4];
    حافظه_نقل(p, &d, حجم(مزدوج));
    أرجع ((بینښه)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC فراغ test_lvalue(فراغ)
{
    إذا (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC فراغ check_vstack(فراغ)
{
    إذا (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (صحيح)(vtop - vstack + 1));
}

#إذا 0
/* dump 'b' vstack entries starting with 'a'  */
فراغ pv (ثابت حرف *lbl, صحيح a, صحيح b)
{
    صحيح i;
    لكل (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        چاپ_کړه("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (صحيح)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ساكن مضمن فراغ psyms(ثابت حرف *پیغام, Sym *s, Sym *وروستی)
{
    چاپ_کړه("%-8s scope         v        c        r   type.t\n", پیغام);
    طالما (s && s != وروستی) {
        چاپ_کړه("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ساكن فراغ type_منزل_str(حرف *buf, صحيح buf_اندازه, CType *type, ثابت حرف *varstr);

/* print type */
ساكن فراغ ptype(ثابت حرف *پیغام, CType *type, صحيح v)
{
    حرف buf[500];
    type_منزل_str(buf, حجم(buf), type,
        (v & ~SYM_ډګر) ? get_tok_str(v, عدم) : عدم);
    چاپ_کړه("%s : %s;\n", پیغام, buf);
}
#د_که_پای

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC فراغ tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, حجم *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    إذا (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_اشاره_ګر_type = char_type;
    mk_اشاره_ګر(&char_اشاره_ګر_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ټېل(SYM_ډګر, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#که_تعریف_شوی precedence_parser
    init_prec();
#د_که_پای
    cstr_new(&initstr);
}

ST_FUNC صحيح tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_لومړی_ANOM;
    nocode_wanted = معلومات_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_بیان = 0;

    tcc_debug_پیل(s1);
    tcc_tcov_پیل (s1);
#که_تعریف_شوی TCC_موخه_ARM
    arm_init(s1);
#د_که_پای
#که_تعریف_شوی INC_DEBUG
    چاپ_کړه("%s: **** new file\n", file->filename);
#د_که_پای
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_عدد | PARSE_FLAG_TOK_STR;
    بل();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#إذا TCC_EH_چوکاټ
    tcc_eh_چوکاټ_پای_ټکی(s1);
#د_که_پای
    tcc_debug_پای_ټکی(s1);
    tcc_tcov_پای_ټکی(s1);
    أرجع 0;
}

ST_FUNC فراغ tccgen_پای(TCCState *s1)
{
    tcc_debug_پای_ټکی(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_راوباسه(&global_ډېری, عدم, 0);
    sym_راوباسه(&local_ډېری, عدم, 0);
    /* free preprocessor macros */
    free_تعریفوي(عدم);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_معلومات, &nb_stk_معلومات);
    طالما (cur_switch)
        پای_ټکی_switch();
    local_scope = 0;
    loop_scope = عدم;
    all_cleanups = عدم;
    pending_gotos = عدم;
    nb_لنډمهاله_local_vars = 0;
    global_label_ډېری = عدم;
    local_label_ډېری = عدم;
    cur_متن_section = عدم;
    sym_free_لومړی = عدم;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  إذا (!s || !s->c)
    أرجع عدم;
  أرجع &((ElfSym *)symtab_section->معلومات)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC فراغ update_storage(Sym *sym)
{
    ElfSym *esym;
    صحيح sym_bind, old_sym_bind;

    esym = elfsym(sym);
    إذا (!esym)
        أرجع;

    إذا (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    إذا (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    وإلا إذا (sym->a.weak)
        sym_bind = STB_WEAK;
    وإلا
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    إذا (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#که_تعریف_شوی TCC_موخه_PE
    إذا (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    إذا (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#د_که_پای

#إذا 0
    چاپ_کړه("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, عدم),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#د_که_پای
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_عدد,
                            addr_t ارزښت, بینښه اوږد اندازه,
                            صحيح can_جمع_کړه_underscore)
{
    صحيح sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ثابت حرف *name;
    حرف buf1[256];

    إذا (!sym->c) {
        name = get_tok_str(sym->v, عدم);
        t = sym->type.t;
        إذا ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } وإلا إذا ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            إذا (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } وإلا إذا (t & VT_TLS) {
            sym_type = STT_TLS;
        } وإلا {
            sym_type = STT_OBJECT;
        }
        إذا (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        وإلا
            sym_bind = STB_GLOBAL;
        other = 0;

#که_تعریف_شوی TCC_موخه_PE
        إذا (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            إذا (ref->a.nodecorate) {
                can_جمع_کړه_underscore = 0;
            }
            إذا (ref->f.func_call == FUNC_STDCALL && can_جمع_کړه_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_دلیلونه * PTR_اندازه);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_جمع_کړه_underscore = 0;
            }
        }
#د_که_پای

        إذا (sym->asm_label) {
            name = get_tok_str(sym->asm_label, عدم);
            can_جمع_کړه_underscore = 0;
        }

        إذا (tcc_state->leading_underscore && can_جمع_کړه_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, حجم(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, ارزښت, اندازه, info, other, sh_عدد, name);

        إذا (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_عدد, sym_bind, sym_type);

    } وإلا {
        esym = elfsym(sym);
        esym->st_ارزښت = ارزښت;
        esym->st_اندازه = اندازه;
        esym->st_shndx = sh_عدد;
    }
    update_storage(sym);
}

ST_FUNC فراغ put_extern_sym(Sym *sym, Section *s, addr_t ارزښت, بینښه اوږد اندازه)
{
    إذا (nocode_wanted && (NODATA_WANTED || (s && s == cur_متن_section)))
        أرجع;
    put_extern_sym2(sym, s ? s->sh_عدد : SHN_UNDEF, ارزښت, اندازه, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC فراغ greloca(Section *s, Sym *sym, بینښه اوږد دننه_واټن, صحيح type,
                     addr_t addend)
{
    صحيح c = 0;

    إذا (nocode_wanted && s == cur_متن_section)
        أرجع;

    إذا (sym) {
        إذا (0 == sym->c) {
            put_extern_sym(sym, عدم, 0, 0);
            إذا (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                طالما (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, دننه_واټن, type, c, addend);
}

#إذا PTR_اندازه == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, بینښه اوږد دننه_واټن, صحيح type)
{
    greloca(s, sym, دننه_واټن, type, 0);
}
#د_که_پای

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ساكن Sym *__sym_malloc(فراغ)
{
    Sym *sym_pool, *sym, *وروستی_sym;
    صحيح i;

    sym_pool = tcc_malloc(SYM_POOL_NB * حجم(Sym));
    dynarray_جمع_کړه(&sym_pools, &nb_sym_pools, sym_pool);

    وروستی_sym = sym_free_لومړی;
    sym = sym_pool;
    لكل(i = 0; i < SYM_POOL_NB; i++) {
        sym->بل = وروستی_sym;
        وروستی_sym = sym;
        sym++;
    }
    sym_free_لومړی = وروستی_sym;
    أرجع وروستی_sym;
}

ساكن مضمن Sym *sym_malloc(فراغ)
{
    Sym *sym;
#که_نه_تعریف_شوی SYM_DEBUG
    sym = sym_free_لومړی;
    إذا (!sym)
        sym = __sym_malloc();
    sym_free_لومړی = sym->بل;
    أرجع sym;
#وإلا
    sym = tcc_malloc(حجم(Sym));
    أرجع sym;
#د_که_پای
}

ST_INLN فراغ sym_free(Sym *sym)
{
#که_نه_تعریف_شوی SYM_DEBUG
    sym->بل = sym_free_لومړی;
    sym_free_لومړی = sym;
#وإلا
    tcc_free(sym);
#د_که_پای
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, حجم *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    أرجع s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, صحيح v)
{
    طالما (s) {
        إذا (s->v == v)
            أرجع s;
        s = s->prev;
    }
    أرجع عدم;
}

/* structure lookup */
ST_INLN Sym *struct_پیدا_کړه(صحيح v)
{
    v -= TOK_IDENT;
    إذا ((بینښه)v >= (بینښه)(tok_ident - TOK_IDENT))
        أرجع عدم;
    أرجع جدول_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_پیدا_کړه(صحيح v)
{
    v -= TOK_IDENT;
    إذا ((بینښه)v >= (بینښه)(tok_ident - TOK_IDENT))
        أرجع عدم;
    أرجع جدول_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ساكن مضمن فراغ sym_link(Sym *s, صحيح yes)
{
    TokenSym *ts = جدول_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    إذا (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    وإلا
        ps = &ts->sym_identifier;
    إذا (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } وإلا {
        *ps = s->prev_tok;
    }
}

ساكن مضمن صحيح sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    أرجع IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ټېل(صحيح v, CType *type, صحيح r, صحيح c)
{
    Sym *s, **ps;
    إذا (local_ډېری)
        ps = &local_ډېری;
    وإلا
        ps = &global_ډېری;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    إذا ((v & ~SYM_STRUCT) < SYM_لومړی_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        إذا (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, عدم));
    }
    أرجع s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ټېل(صحيح v, صحيح t, صحيح c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ډېری, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    إذا (v < SYM_لومړی_ANOM) {
        ps = &جدول_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        طالما (*ps != عدم && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    أرجع s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC فراغ sym_راوباسه(Sym **ptop, Sym *b, صحيح keep)
{
    Sym *s, *ss;
    صحيح v;

    s = *ptop;
    طالما(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        إذا ((v & ~SYM_STRUCT) < SYM_لومړی_ANOM)
            sym_link(s, 0);
	إذا (!keep)
	    sym_free(s);
        s = ss;
    }
    إذا (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_پیدا_کړه(صحيح v)
{
    v -= TOK_IDENT;
    إذا ((بینښه)v >= (بینښه)(tok_ident - TOK_IDENT))
        أرجع عدم;
    أرجع جدول_ident[v]->sym_label;
}

ST_FUNC Sym *label_ټېل(Sym **ptop, صحيح v, صحيح flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &جدول_ident[v - TOK_IDENT]->sym_label;
    إذا (ptop == &global_label_ډېری) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        طالما (*ps != عدم)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    أرجع s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC فراغ label_راوباسه(Sym **ptop, Sym *slast, صحيح keep)
{
    Sym *s, *s1;
    لكل(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        إذا (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, عدم));
        } وإلا إذا (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, عدم));
        } وإلا {
            إذا (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_متن_section, s->jind, 1);
            }
        }
        /* remove label */
        إذا (s->r != LABEL_GONE)
            جدول_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        إذا (!keep)
            sym_free(s);
        وإلا
            s->r = LABEL_GONE;
    }
    إذا (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ساكن فراغ vcheck_cmp(فراغ)
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

    إذا (vtop->r == VT_CMP && 0 == (nocode_wanted & ~کوډ_OFF_بټ))
        gv(RC_INT);
}

ساكن فراغ vsetc(CType *type, صحيح r, CValue *vc)
{
    إذا (vtop >= vstack + (VSTACK_اندازه - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = عدم;
}

ST_FUNC فراغ vswap(فراغ)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC فراغ vpop(فراغ)
{
    صحيح v;
    v = vtop->r & VT_VALMASK;
#إذا defined(TCC_موخه_I386) || defined(TCC_موخه_X86_64)
    /* for x86, we need to pop the FP stack */
    إذا (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } وإلا
#د_که_پای
    إذا (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ساكن فراغ vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ساكن فراغ vpush64(صحيح ty, بینښه اوږد اوږد v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = عدم;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC فراغ vpushi(صحيح v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ساكن فراغ vpushs(addr_t v)
{
    vpush64(VT_اندازه_T, v);
}

/* push long long constant */
ساكن مضمن فراغ vpushll(اوږد اوږد v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC فراغ vset(CType *type, صحيح r, صحيح v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ساكن فراغ vseti(صحيح r, صحيح v)
{
    CType type;
    type.t = VT_INT;
    type.ref = عدم;
    vset(&type, r, v);
}

ST_FUNC فراغ vpushv(SValue *v)
{
    إذا (vtop >= vstack + (VSTACK_اندازه - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ساكن فراغ vdup(فراغ)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC فراغ vrotb(صحيح n)
{
    SValue tmp;
    إذا (--n < 1)
        أرجع;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, حجم *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC فراغ vrott(صحيح n)
{
    SValue tmp;
    إذا (--n < 1)
        أرجع;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, حجم *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC فراغ vrev(صحيح n)
{
    صحيح i;
    SValue tmp;
    vcheck_cmp();
    لكل (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC فراغ vset_VT_CMP(صحيح op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ساكن فراغ vset_VT_JMP(فراغ)
{
    صحيح op = vtop->cmp_op;

    إذا (vtop->jtrue || vtop->jfalse) {
        صحيح origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        صحيح inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } وإلا {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        إذا (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ساكن فراغ gvtst_سېټ(صحيح inv, صحيح t)
{
    صحيح *p;

    إذا (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        إذا (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ساكن صحيح gvtst(صحيح inv, صحيح t)
{
    صحيح op, x, u;

    gvtst_سېټ(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    إذا (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    إذا (op > 1)
        t = gjmp_cond(op ^ inv, t);
    وإلا إذا (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    أرجع t;
}

/* generate a zero or nozero test */
ساكن فراغ gen_test_zero(صحيح op)
{
    إذا (vtop->r == VT_CMP) {
        صحيح j;
        إذا (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } وإلا {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC فراغ vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, بینښه اوږد دننه_واټن, بینښه اوږد اندازه)
{
    صحيح v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ټېل(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, دننه_واټن, اندازه);
    أرجع sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ساكن فراغ vpush_ref(CType *type, Section *sec, بینښه اوږد دننه_واټن, بینښه اوږد اندازه)
{
    vpushsym(type, get_sym_ref(type, sec, دننه_واټن, اندازه));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(صحيح v, CType *type)
{
    Sym *s;

    s = sym_پیدا_کړه(v);
    إذا (!s) {
        /* push forward reference */
        s = global_identifier_ټېل(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } وإلا إذا (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    أرجع s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(صحيح v)
{
    CType ct = { VT_ASM_FUNC, عدم };
    أرجع external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC فراغ vpush_helper_func(صحيح v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ساكن فراغ یوځای_symattr(بنية SymAttr *sa, بنية SymAttr *sa1)
{
    إذا (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    إذا (sa1->visibility != STV_DEFAULT) {
	صحيح vis = sa->visibility;
	إذا (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ساكن فراغ یوځای_funcattr(بنية FuncAttr *fa, بنية FuncAttr *fa1)
{
    إذا (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    إذا (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    إذا (fa1->func_دلیلونه && !fa->func_دلیلونه)
      fa->func_دلیلونه = fa1->func_دلیلونه;
    إذا (fa1->func_noreturn)
      fa->func_noreturn = 1;
    إذا (fa1->func_ctor)
      fa->func_ctor = 1;
    إذا (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ساكن فراغ یوځای_attr(AttributeDef *ad, AttributeDef *ad1)
{
    یوځای_symattr(&ad->a, &ad1->a);
    یوځای_funcattr(&ad->f, &ad1->f);

    إذا (ad1->section)
      ad->section = ad1->section;
    إذا (ad1->alias_موخه)
      ad->alias_موخه = ad1->alias_موخه;
    إذا (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    إذا (ad1->attr_ډېرپېښ)
      ad->attr_ډېرپېښ = ad1->attr_ډېرپېښ;
}

/* Merge some type attributes.  */
ساكن فراغ patch_type(Sym *sym, CType *type)
{
    إذا (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        إذا (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, عدم));
        sym->type.t &= ~VT_EXTERN;
    }

    إذا (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        إذا ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    إذا (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, عدم));

    } وإلا إذا ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        صحيح static_proto = sym->type.t & VT_STATIC;
        صحيح ft1 = sym->type.ref->f.func_type;
        صحيح ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        إذا ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, عدم));

        /* set 'inline' if both agree or if one has static */
        إذا ((type->t | sym->type.t) & VT_INLINE) {
            إذا (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        إذا (0 == (type->t & VT_EXTERN)) {
            بنية FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            إذا (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            یوځای_funcattr(&sym->type.ref->f, &f);
        } وإلا {
            sym->type.t &= ~VT_INLINE | static_proto;
            إذا (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } وإلا {
        إذا ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        إذا ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, عدم));
    }
}

/* Merge some storage attributes.  */
ساكن فراغ patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    إذا (type)
        patch_type(sym, type);

#که_تعریف_شوی TCC_موخه_PE
    إذا (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, عدم));
#د_که_پای
    یوځای_symattr(&sym->a, &ad->a);
    إذا (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ساكن Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    إذا ((s->v & ~SYM_STRUCT) < SYM_لومړی_ANOM)
        sym_link(s, 1);
    أرجع s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ساكن فراغ move_ref_منزل_global(Sym *s)
{
    Sym *l, **lp;
    صحيح n, bt;

    bt = s->type.t & VT_BTYPE;
    إذا (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        أرجع;

    لكل (s = s->type.ref, n = 0; s; s = s->بل) {
        لكل (lp = &local_ډېری; !!(l = *lp); lp = &l->prev) {
            إذا (l == s) {
                *lp = s->prev;
                s->prev = global_ډېری, global_ډېری = s;
                إذا (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_منزل_global(s);
                } وإلا {
                    إذا ((s->v & ~SYM_STRUCT) < SYM_لومړی_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_ډګر;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_ډګر;
                    }
                }
                إذا (bt != VT_PTR)
                    n = 1;
                اكسر;
            }
        }
        إذا (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            اكسر;
    }
}

/* define a new external reference to a symbol 'v' */
ساكن Sym *external_sym(صحيح v, CType *type, صحيح r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_پیدا_کړه(v);
    طالما (s && s->sym_scope)
        s = s->prev_tok;

    إذا (!s) {
        /* push forward reference */
        s = global_identifier_ټېل(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } وإلا {
        patch_storage(s, ad, type);
    }
    إذا (local_ډېری) {
        /* make sure that type->ref is on global stack */
        move_ref_منزل_global(s);
        /* put into local scope */
        sym_copy(s, &local_ډېری);
    }
    أرجع s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC فراغ save_regs(صحيح n)
{
    SValue *p, *p1;
    لكل(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC فراغ save_reg(صحيح r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n)
{
    صحيح l, اندازه, align, bt, r2;
    SValue *p, *p1, sv;

    إذا ((r &= VT_VALMASK) >= VT_CONST)
        أرجع;
    إذا (nocode_wanted)
        أرجع;
    l = r2 = 0;
    لكل(p = vstack, p1 = vtop - n; p <= p1; p++) {
        إذا ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            إذا (!l) {
                bt = p->type.t & VT_BTYPE;
                إذا (bt == VT_VOID)
                    استمر;
                إذا ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                اندازه = type_اندازه(&sv.type, &align);
                l = get_لنډمهاله_local_var(اندازه, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = عدم;
                store(p->r & VT_VALMASK, &sv);
#إذا defined(TCC_موخه_I386) || defined(TCC_موخه_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                إذا (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#د_که_پای
                /* special long long case */
                إذا (p->r2 < VT_CONST && USING_TWO_ټکي(bt)) {
                    sv.c.i += PTR_اندازه;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            إذا (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } وإلا {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = عدم;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#که_تعریف_شوی TCC_موخه_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2)
{
    صحيح r;
    SValue *p;
    
    لكل(r=0;r<NB_REGS;r++) {
        إذا (reg_classes[r] & rc2) {
            صحيح n;
            n=0;
            لكل(p = vstack; p <= vtop; p++) {
                إذا ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            إذا (n <= 1)
                أرجع r;
        }
    }
    أرجع get_reg(rc);
}
#د_که_پای

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC صحيح get_reg(صحيح rc)
{
    صحيح r;
    SValue *p;

    /* find a free register */
    لكل(r=0;r<NB_REGS;r++) {
        إذا (reg_classes[r] & rc) {
            إذا (nocode_wanted)
                أرجع r;
            لكل(p=vstack;p<=vtop;p++) {
                إذا ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    اذهب notfound;
            }
            أرجع r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    لكل(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        إذا (r < VT_CONST && (reg_classes[r] & rc))
            اذهب save_وموندل;
        r = p->r & VT_VALMASK;
        إذا (r < VT_CONST && (reg_classes[r] & rc)) {
        save_وموندل:
            save_reg(r);
            أرجع r;
        }
    }
    /* Should never comes here */
    أرجع -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ساكن صحيح get_لنډمهاله_local_var(صحيح اندازه,صحيح align, صحيح *r2)
{
    صحيح i;
    بنية لنډمهاله_local_variable *لنډمهاله_var;
    SValue *p;
    صحيح r;
    بینښه کارول_شوی = 0;

    /* mark locations that are still in use */
    لكل (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	إذا (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    إذا (r >= 0 && r < MAX_لنډمهاله_LOCAL_VARIABLE_شمېره)
	        کارول_شوی |= 1<<r;
	}
    }
    لكل (i=0;i<nb_لنډمهاله_local_vars;i++) {
	لنډمهاله_var=&arr_لنډمهاله_local_vars[i];
	إذا(!(کارول_شوی & 1<<i)
	 && لنډمهاله_var->اندازه>=اندازه
	 && لنډمهاله_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    أرجع لنډمهاله_var->location;
	}
    }
    loc = (loc - اندازه) & -align;
    إذا (nb_لنډمهاله_local_vars<MAX_لنډمهاله_LOCAL_VARIABLE_شمېره) {
	لنډمهاله_var=&arr_لنډمهاله_local_vars[i];
	لنډمهاله_var->location=loc;
	لنډمهاله_var->اندازه=اندازه;
	لنډمهاله_var->align=align;
	nb_لنډمهاله_local_vars++;
	اذهب ret_tmp;
    }
    *r2 = VT_CONST;
    أرجع loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ساكن فراغ move_reg(صحيح r, صحيح s, صحيح t)
{
    SValue sv;

    إذا (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = عدم;
        sv.r = s;
        sv.c.i = 0;
        بارول(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC فراغ gaddrof(فراغ)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    إذا ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#که_تعریف_شوی CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ساكن فراغ gen_bounded_ptr_جمع_کړه(فراغ)
{
    صحيح save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    إذا (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_جمع_کړه);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    إذا (nocode_wanted)
        أرجع;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_متن_section->reloc->معلومات_دننه_واټن - حجم(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ساكن فراغ gen_bounded_ptr_deref(فراغ)
{
    addr_t func;
    صحيح اندازه, align;
    ElfW_Rel *rel;
    Sym *sym;

    إذا (nocode_wanted)
        أرجع;

    اندازه = type_اندازه(&vtop->type, &align);
    بدل(اندازه) {
    حالة  1: func = TOK___bound_ptr_indir1; اكسر;
    حالة  2: func = TOK___bound_ptr_indir2; اكسر;
    حالة  4: func = TOK___bound_ptr_indir4; اكسر;
    حالة  8: func = TOK___bound_ptr_indir8; اكسر;
    حالة 12: func = TOK___bound_ptr_indir12; اكسر;
    حالة 16: func = TOK___bound_ptr_indir16; اكسر;
    افتراضي:
        /* may happen with struct member access */
        أرجع;
    }
    sym = external_helper_sym(func);
    إذا (!sym->c)
        put_extern_sym(sym, عدم, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_متن_section->reloc->معلومات + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ساكن فراغ gbound(فراغ)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    إذا (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        إذا (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_جمع_کړه();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC فراغ gbound_دلیلونه(صحيح nb_دلیلونه)
{
    صحيح i, v;
    SValue *sv;

    لكل (i = 1; i <= nb_دلیلونه; ++i)
        إذا (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_دلیلونه;
    إذا (sv->r & VT_SYM) {
        v = sv->sym->v;
        إذا (v == TOK_setjmp
          || v == TOK__setjmp
#که_نه_تعریف_شوی TCC_موخه_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#د_که_پای
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_جمع_کړه_epilog = 1;
        }
        إذا (v == TOK_alloca)
            func_bound_جمع_کړه_epilog = 1;
#إذا TARGETOS_NetBSD
        إذا (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#د_که_پای
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ساكن فراغ جمع_کړه_local_bounds(Sym *s, Sym *e)
{
    لكل (; s != e; s = s->prev) {
        إذا (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          استمر;
        /* Add arrays/structs/unions because we always take address */
        إذا ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            صحيح align, اندازه = type_اندازه(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_جمع_کړه(lbounds_section,
                                                 2 * حجم(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = اندازه;
        }
    }
}
#د_که_پای

/* add debug info for locals or function parameters, optionally
   register bounds */
ساكن فراغ tcc_debug_پای_ټکی_scope(Sym *b, صحيح bounds)
{
#که_تعریف_شوی CONFIG_TCC_BCHECK
    إذا (tcc_state->do_bounds_check && bounds)
        جمع_کړه_local_bounds(local_ډېری, b);
#د_که_پای
    tcc_جمع_کړه_debug_info (tcc_state, local_ډېری, b);
}

/* increment an lvalue pointer */
ساكن فراغ incr_دننه_واټن(صحيح دننه_واټن)
{
    صحيح t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(دننه_واټن);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ساكن فراغ incr_bf_adr(صحيح o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_دننه_واټن(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ساكن فراغ بارول_packed_bf(CType *type, صحيح بټ_pos, صحيح بټ_اندازه_2)
{
    صحيح n, o, بټونه;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    بټونه = 0, o = بټ_pos >> 3, بټ_pos &= 7;
    افعل {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - بټ_pos;
        إذا (n > بټ_اندازه_2)
            n = بټ_اندازه_2;
        إذا (بټ_pos)
            vpushi(بټ_pos), gen_op(TOK_SHR), بټ_pos = 0; // X B Y
        إذا (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        إذا (بټونه)
            vpushi(بټونه), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        بټونه += n, بټ_اندازه_2 -= n, o = 1;
    } طالما (بټ_اندازه_2);
    vswap(), vpop();
    إذا (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - بټونه;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ساكن فراغ store_packed_bf(صحيح بټ_pos, صحيح بټ_اندازه_2)
{
    صحيح بټونه, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    بټونه = 0, o = بټ_pos >> 3, بټ_pos &= 7;
    افعل {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        إذا (بټونه)
            vpushi(بټونه), gen_op(TOK_SHR);
        إذا (بټ_pos)
            vpushi(بټ_pos), gen_op(TOK_SHL);
        n = 8 - بټ_pos;
        إذا (n > بټ_اندازه_2)
            n = بټ_اندازه_2;
        إذا (n < 8) {
            m = ((1 << n) - 1) << بټ_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        بټونه += n, بټ_اندازه_2 -= n, بټ_pos = 0, o = 1;
    } طالما (بټ_اندازه_2);
    vpop(), vpop();
}

ساكن صحيح adjust_bf(SValue *sv, صحيح بټ_pos, صحيح بټ_اندازه_2)
{
    صحيح t;
    إذا (0 == sv->type.ref)
        أرجع 0;
    t = sv->type.ref->auxtype;
    إذا (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    أرجع t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC صحيح gv(صحيح rc)
{
    صحيح r, r2, r_ok, r2_ok, rc2, bt;
    صحيح بټ_pos, بټ_اندازه_2, اندازه, align;

    /* NOTE: get_reg can modify vstack[] */
    إذا (vtop->type.t & VT_BITFIELD) {
        CType type;

        بټ_pos = بټ_POS(vtop->type.t);
        بټ_اندازه_2 = بټ_اندازه(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_ماسک;

        type.ref = عدم;
        type.t = vtop->type.t & VT_UNSIGNED;
        إذا ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, بټ_pos, بټ_اندازه_2);

        إذا ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        وإلا
            type.t |= VT_INT;

        إذا (r == VT_STRUCT) {
            بارول_packed_bf(&type, بټ_pos, بټ_اندازه_2);
        } وإلا {
            صحيح بټونه = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(بټونه - (بټ_pos + بټ_اندازه_2));
            gen_op(TOK_SHL);
            vpushi(بټونه - بټ_اندازه_2);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } وإلا {
        إذا (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            بینښه اوږد دننه_واټن;
            اندازه = type_اندازه(&vtop->type, &align);
            إذا (NODATA_WANTED)
                اندازه = 0, align = 1;
            دننه_واټن = section_جمع_کړه(p.sec, اندازه, align);
            vpush_ref(&vtop->type, p.sec, دننه_واټن, اندازه);
	    vswap();
	    init_putv(&p, &vtop->type, دننه_واټن);
	    vtop->r |= VT_LVAL;
        }
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (vtop->r & VT_MUSTBOUND) 
            gbound();
#د_که_پای

        bt = vtop->type.t & VT_BTYPE;
        إذا (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            أرجع vtop->r;

#که_تعریف_شوی TCC_موخه_RISCV64
        /* XXX mega hack */
        إذا (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#د_که_پای
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        إذا (!r_ok || !r2_ok) {

            إذا (!r_ok) {
                إذا (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                وإلا
                    r = get_reg(rc);
            }

            إذا (rc2) {
                صحيح بارول_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                صحيح original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    بینښه اوږد اوږد ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    بارول(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } وإلا إذا (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = بارول_type;
                    بارول(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_دننه_واټن(PTR_اندازه);
                } وإلا {
                    /* move registers */
                    إذا (!r_ok)
                        بارول(r, vtop);
                    إذا (r2_ok && vtop->r2 < VT_CONST)
                        اذهب بشپړ;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                بارول(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            بشپړ:
                vtop->type.t = original_type;
            } وإلا {
                إذا (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                بارول(r, vtop);
            }
        }
        vtop->r = r;
#که_تعریف_شوی TCC_موخه_C67
        /* uses register pairs for doubles */
        إذا (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#د_که_پای
    }
    أرجع r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    إذا (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        إذا ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } وإلا {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        إذا ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#إذا PTR_اندازه == 4
/* expand 64bit on stack in two ints */
ST_FUNC فراغ lexpand(فراغ)
{
    صحيح u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    إذا (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } وإلا إذا (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } وإلا {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#د_که_پای

#إذا PTR_اندازه == 4
/* build a long long from two ints */
ساكن فراغ lbuild(صحيح t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#د_که_پای

/* convert stack entry to register and duplicate its value in another
ثبتوونکی*/
ساكن فراغ gv_dup(فراغ)
{
    صحيح t, rc, r;

    t = vtop->type.t;
#إذا PTR_اندازه == 4
    إذا ((t & VT_BTYPE) == VT_LLONG) {
        إذا (t & VT_BITFIELD) {
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
        أرجع;
    }
#د_که_پای
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    بارول(r, vtop);
    vtop->r = r;
}

#إذا PTR_اندازه == 4
/* generate CPU independent (unsigned) long long operations */
ساكن فراغ gen_opl(صحيح op)
{
    صحيح t, a, b, op1, c, i;
    صحيح func;
    بینښه لنډ reg_iret = REG_IRET;
    بینښه لنډ reg_lret = REG_IRE2;
    SValue tmp;

    بدل(op) {
    حالة '/':
    حالة TOK_PDIV:
        func = TOK___divdi3;
        اذهب gen_func;
    حالة TOK_UDIV:
        func = TOK___udivdi3;
        اذهب gen_func;
    حالة '%':
        func = TOK___moddi3;
        اذهب gen_mod_func;
    حالة TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#که_تعریف_شوی TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#د_که_پای
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        اكسر;
    حالة '^':
    حالة '&':
    حالة '|':
    حالة '*':
    حالة '+':
    حالة '-':
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
        إذا (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            لكل(i=0;i<4;i++)
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
        } وإلا إذا (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            إذا (op == '+')
                op1 = TOK_ADDC1;
            وإلا
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } وإلا {
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
        اكسر;
    حالة TOK_SAR:
    حالة TOK_SHR:
    حالة TOK_SHL:
        إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (صحيح)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            إذا (op != TOK_SHL)
                vswap();
            إذا (c >= 32) {
                /* stack: L H */
                vpop();
                إذا (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                إذا (op != TOK_SAR) {
                    vpushi(0);
                } وإلا {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } وإلا {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                إذا (op == TOK_SHL)
                    gen_op(TOK_SHR);
                وإلا
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                إذا (op == TOK_SHL)
                    gen_op(TOK_SHL);
                وإلا
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            إذا (op != TOK_SHL)
                vswap();
            lbuild(t);
        } وإلا {
            /* XXX: should provide a faster fallback on x86 ? */
            بدل(op) {
            حالة TOK_SAR:
                func = TOK___ashrdi3;
                اذهب gen_func;
            حالة TOK_SHR:
                func = TOK___lshrdi3;
                اذهب gen_func;
            حالة TOK_SHL:
                func = TOK___ashldi3;
                اذهب gen_func;
            }
        }
        اكسر;
    افتراضي:
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
        إذا (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        إذا (op1 == TOK_LT)
            op1 = TOK_LE;
        وإلا إذا (op1 == TOK_GT)
            op1 = TOK_GE;
        وإلا إذا (op1 == TOK_ULT)
            op1 = TOK_ULE;
        وإلا إذا (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        إذا (op == TOK_NE) {
            b = gvtst(0, 0);
        } وإلا {
            a = gvtst(1, 0);
            إذا (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        إذا (op1 == TOK_LT)
            op1 = TOK_ULT;
        وإلا إذا (op1 == TOK_LE)
            op1 = TOK_ULE;
        وإلا إذا (op1 == TOK_GT)
            op1 = TOK_UGT;
        وإلا إذا (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#إذا 0//def TCC_TARGET_I386
        إذا (op == TOK_NE) { gsym(b); اكسر; }
        إذا (op == TOK_EQ) { gsym(a); اكسر; }
#د_که_پای
        gvtst_سېټ(1, a);
        gvtst_سېټ(0, b);
        اكسر;
    }
}
#د_که_پای

/* normalize values */
ساكن uint64_t value64(uint64_t l1, صحيح t)
{
    إذا ((t & VT_BTYPE) == VT_LLONG
        || (PTR_اندازه == 8 && (t & VT_BTYPE) == VT_PTR))
        أرجع l1;
    وإلا إذا (t & VT_UNSIGNED)
        أرجع (uint32_t)l1;
    وإلا
        أرجع (uint32_t)l1 | -(l1 & 0x80000000);
}

ساكن uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    أرجع (a ^ b) >> 63 ? -x : x;
}

ساكن صحيح gen_opic_lt(uint64_t a, uint64_t b)
{
    أرجع (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ساكن فراغ gen_opic(صحيح op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    صحيح t1 = v1->type.t & VT_BTYPE;
    صحيح t2 = v2->type.t & VT_BTYPE;
    صحيح c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    صحيح c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    صحيح shm = (t1 == VT_LLONG) ? 63 : 31;
    صحيح r;

    إذا (c1 && c2) {
        بدل(op) {
        حالة '+': l1 += l2; اكسر;
        حالة '-': l1 -= l2; اكسر;
        حالة '&': l1 &= l2; اكسر;
        حالة '^': l1 ^= l2; اكسر;
        حالة '|': l1 |= l2; اكسر;
        حالة '*': l1 *= l2; اكسر;

        حالة TOK_PDIV:
        حالة '/':
        حالة '%':
        حالة TOK_UDIV:
        حالة TOK_UMOD:
            /* if division by zero, generate explicit division */
            إذا (l2 == 0) {
                إذا (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                اذهب general_case;
            }
            بدل(op) {
            افتراضي: l1 = gen_opic_sdiv(l1, l2); اكسر;
            حالة '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); اكسر;
            حالة TOK_UDIV: l1 = l1 / l2; اكسر;
            حالة TOK_UMOD: l1 = l1 % l2; اكسر;
            }
            اكسر;
        حالة TOK_SHL: l1 <<= (l2 & shm); اكسر;
        حالة TOK_SHR: l1 >>= (l2 & shm); اكسر;
        حالة TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            اكسر;
            /* tests */
        حالة TOK_ULT: l1 = l1 < l2; اكسر;
        حالة TOK_UGE: l1 = l1 >= l2; اكسر;
        حالة TOK_EQ: l1 = l1 == l2; اكسر;
        حالة TOK_NE: l1 = l1 != l2; اكسر;
        حالة TOK_ULE: l1 = l1 <= l2; اكسر;
        حالة TOK_UGT: l1 = l1 > l2; اكسر;
        حالة TOK_LT: l1 = gen_opic_lt(l1, l2); اكسر;
        حالة TOK_GE: l1 = !gen_opic_lt(l1, l2); اكسر;
        حالة TOK_LE: l1 = !gen_opic_lt(l2, l1); اكسر;
        حالة TOK_GT: l1 = gen_opic_lt(l2, l1); اكسر;
            /* logical */
        حالة TOK_LAND: l1 = l1 && l2; اكسر;
        حالة TOK_LOR: l1 = l1 || l2; اكسر;
        افتراضي:
            اذهب general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } وإلا {
        /* if commutative ops, put c2 as constant */
        إذا (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        إذا (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } وإلا إذا (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            إذا (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } وإلا إذا (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } وإلا إذا (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            إذا (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                صحيح n = -1;
                إذا (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    اذهب general_case;
                }
                طالما (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                إذا (op == '*')
                    op = TOK_SHL;
                وإلا إذا (op == TOK_PDIV)
                    op = TOK_SAR;
                وإلا
                    op = TOK_SHR;
            }
            اذهب general_case;
        } وإلا إذا (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            إذا (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    إذا ((صحيح)l2 != l2)
	        اذهب general_case;
            vtop--;
            vtop->c.i = l2;
        } وإلا {
        general_case:
                /* call low level op generator */
                إذا (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_اندازه == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                وإلا
                    gen_opi(op);
        }
        إذا (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#إذا defined TCC_موخه_X86_64 || defined TCC_موخه_I386 || defined TCC_موخه_ARM64
# define gen_negf gen_opf
#وإلاإذا defined TCC_موخه_ARM
فراغ gen_negf(صحيح op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#وإلا
/* XXX: implement in gen_opf() for other backends too */
فراغ gen_negf(صحيح op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    صحيح align, اندازه, bt;
    اندازه = type_اندازه(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#إذا defined TCC_موخه_X86_64 || defined TCC_موخه_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    إذا (bt == VT_LDOUBLE)
        اندازه = 10;
#د_که_پای
    إذا (nocode_wanted) /* save_reg() wont work */
        اذهب gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(اندازه - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#د_که_پای

/* generate a floating point operation with constant propagation */
ساكن فراغ gen_opif(صحيح op)
{
    صحيح c1, c2, i, bt;
    SValue *v1, *v2;
#إذا defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    متطاير
#د_که_پای
    اوږد مزدوج f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    إذا (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    إذا (c1 && c2) {
        إذا (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } وإلا إذا (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } وإلا {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        إذا (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            اذهب general_case;
        بدل(op) {
        حالة '+': f1 += f2; اكسر;
        حالة '-': f1 -= f2; اكسر;
        حالة '*': f1 *= f2; اكسر;
        حالة '/': 
            إذا (f2 == 0.0) {
                اتحاد { عائم f; بینښه u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                إذا (!CONST_WANTED)
                    اذهب general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                إذا (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                وإلا
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                اكسر;
            }
            f1 /= f2;
            اكسر;
        حالة TOK_NEG:
            f1 = -f1;
            اذهب unary_پایله;
        حالة TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            أرجع;
        حالة TOK_NE:
            i = f1 != f2;
	    اذهب make_int;
        حالة TOK_LT:
            i = f1 < f2;
	    اذهب make_int;
        حالة TOK_GE:
            i = f1 >= f2;
	    اذهب make_int;
        حالة TOK_LE:
            i = f1 <= f2;
	    اذهب make_int;
        حالة TOK_GT:
            i = f1 > f2;
	    اذهب make_int;
        افتراضي:
            اذهب general_case;
        }
        vtop--;
    unary_پایله:
        /* XXX: overflow test ? */
        إذا (bt == VT_FLOAT) {
            v1->c.f = f1;
        } وإلا إذا (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } وإلا {
            v1->c.ld = f1;
        }
    } وإلا {
    general_case:
        إذا (op == TOK_NEG) {
            gen_negf(op);
        } وإلا {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ساكن فراغ type_منزل_str(حرف *buf, صحيح buf_اندازه,
                 CType *type, ثابت حرف *varstr)
{
    صحيح bt, v, t;
    Sym *s, *sa;
    حرف buf1[256];
    ثابت حرف *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    إذا (t & VT_EXTERN)
        pstrcat(buf, buf_اندازه, "extern ");
    إذا (t & VT_STATIC)
        pstrcat(buf, buf_اندازه, "static ");
    إذا (t & VT_TYPEDEF)
        pstrcat(buf, buf_اندازه, "typedef ");
    إذا (t & VT_INLINE)
        pstrcat(buf, buf_اندازه, "inline ");
    إذا (bt != VT_PTR) {
        إذا (t & VT_RESTRICT)
            pstrcat(buf, buf_اندازه, "restrict ");
        إذا (t & VT_VOLATILE)
            pstrcat(buf, buf_اندازه, "volatile ");
        إذا (t & VT_CONSTANT)
            pstrcat(buf, buf_اندازه, "const ");
    }
    إذا (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_اندازه, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_اندازه -= مزي_اوږدوالی(buf);
    buf += مزي_اوږدوالی(buf);

    بدل(bt) {
    حالة VT_VOID:
        tstr = "void";
        اذهب جمع_کړه_tstr;
    حالة VT_BOOL:
        tstr = "_Bool";
        اذهب جمع_کړه_tstr;
    حالة VT_BYTE:
        tstr = "char";
        اذهب جمع_کړه_tstr;
    حالة VT_SHORT:
        tstr = "short";
        اذهب جمع_کړه_tstr;
    حالة VT_INT:
        tstr = "int";
        اذهب maybe_long;
    حالة VT_LLONG:
        tstr = "long long";
    maybe_long:
        إذا (t & VT_LONG)
            tstr = "long";
        إذا (!IS_ENUM(t))
            اذهب جمع_کړه_tstr;
        tstr = "enum ";
        اذهب tstruct;
    حالة VT_FLOAT:
        tstr = "float";
        اذهب جمع_کړه_tstr;
    حالة VT_DOUBLE:
        tstr = "double";
        إذا (!(t & VT_LONG))
            اذهب جمع_کړه_tstr;
    حالة VT_LDOUBLE:
        tstr = "long double";
    جمع_کړه_tstr:
        pstrcat(buf, buf_اندازه, tstr);
        اكسر;
    حالة VT_STRUCT:
        tstr = "struct ";
        إذا (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_اندازه, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        إذا (v >= SYM_لومړی_ANOM)
            pstrcat(buf, buf_اندازه, "<anonymous>");
        وإلا
            pstrcat(buf, buf_اندازه, get_tok_str(v, عدم));
        اكسر;
    حالة VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        إذا (varstr && '*' == *varstr) {
            pstrcat(buf1, حجم(buf1), "(");
            pstrcat(buf1, حجم(buf1), varstr);
            pstrcat(buf1, حجم(buf1), ")");
        }
        pstrcat(buf1, حجم(buf1), "(");
        sa = s->بل;
        طالما (sa != عدم) {
            حرف buf2[256];
            type_منزل_str(buf2, حجم(buf2), &sa->type, عدم);
            pstrcat(buf1, حجم(buf1), buf2);
            sa = sa->بل;
            إذا (sa)
                pstrcat(buf1, حجم(buf1), ", ");
        }
        إذا (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, حجم(buf1), ", ...");
        pstrcat(buf1, حجم(buf1), ")");
        type_منزل_str(buf, buf_اندازه, &s->type, buf1);
        اذهب no_var;
    حالة VT_PTR:
        s = type->ref;
        إذا (t & (VT_ARRAY|VT_VLA)) {
            إذا (varstr && '*' == *varstr)
                snprintf(buf1, حجم(buf1), "(%s)[%d]", varstr, s->c);
            وإلا
                snprintf(buf1, حجم(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_منزل_str(buf, buf_اندازه, &s->type, buf1);
            اذهب no_var;
        }
        pstrcpy(buf1, حجم(buf1), "*");
        إذا (t & VT_RESTRICT)
            pstrcat(buf1, حجم(buf1), "restrict ");
        إذا (t & VT_CONSTANT)
            pstrcat(buf1, حجم(buf1), "const ");
        إذا (t & VT_VOLATILE)
            pstrcat(buf1, حجم(buf1), "volatile ");
        إذا (varstr)
            pstrcat(buf1, حجم(buf1), varstr);
        type_منزل_str(buf, buf_اندازه, &s->type, buf1);
        اذهب no_var;
    }
    إذا (varstr) {
        pstrcat(buf, buf_اندازه, " ");
        pstrcat(buf, buf_اندازه, varstr);
    }
 no_var: ;
}

ساكن فراغ type_incompatibility_error(CType* st, CType* dt, ثابت حرف* fmt)
{
    حرف buf1[256], buf2[256];
    type_منزل_str(buf1, حجم(buf1), st, عدم);
    type_منزل_str(buf2, حجم(buf2), dt, عدم);
    tcc_error(fmt, buf1, buf2);
}

ساكن فراغ type_incompatibility_warning(CType* st, CType* dt, ثابت حرف* fmt)
{
    حرف buf1[256], buf2[256];
    type_منزل_str(buf1, حجم(buf1), st, عدم);
    type_منزل_str(buf2, حجم(buf2), dt, عدم);
    tcc_warning(fmt, buf1, buf2);
}

ساكن صحيح pointed_اندازه(CType *type)
{
    صحيح align;
    أرجع type_اندازه(pointed_type(type), &align);
}

ساكن مضمن صحيح is_null_اشاره_ګر(SValue *p)
{
    إذا ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        أرجع 0;
    أرجع ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_اندازه == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ساكن صحيح is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    إذا (s1->f.func_call != s2->f.func_call)
        أرجع 0;
    إذا (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        أرجع 0;
    لكل (;;) {
        إذا (!is_compatible_unqualified_types(&s1->type, &s2->type))
            أرجع 0;
        إذا (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            أرجع 1;
        s1 = s1->بل;
        s2 = s2->بل;
        إذا (!s1)
            أرجع !s2;
        إذا (!s2)
            أرجع 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ساكن صحيح compare_types(CType *type1, CType *type2, صحيح unqualified)
{
    صحيح bt1, t1, t2;

    إذا (IS_ENUM(type1->t)) {
        إذا (IS_ENUM(type2->t))
            أرجع type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } وإلا إذا (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    إذا (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    إذا ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    إذا (t1 != t2)
        أرجع 0;

    إذا ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            أرجع 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    إذا (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        إذا (unqualified && (t1 & VT_ARRAY))
            أرجع compare_types(type1, type2, 1);
        أرجع is_compatible_types(type1, type2);
    } وإلا إذا (bt1 == VT_STRUCT) {
        أرجع (type1->ref == type2->ref);
    } وإلا إذا (bt1 == VT_FUNC) {
        أرجع is_compatible_func(type1, type2);
    } وإلا {
        أرجع 1;
    }
}

#تعریف_کړه CMP_OP 'C'
#تعریف_کړه ښويدنه_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ساكن صحيح combine_types(CType *dest, SValue *op1, SValue *op2, صحيح op)
{
    CType *type1, *type2, type;
    صحيح t1, t2, bt1, bt2;
    صحيح ret = 1;

    /* for shifts, 'combine' only left operand */
    إذا (op == ښويدنه_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = عدم;

    إذا (bt1 == VT_VOID || bt2 == VT_VOID) {
        إذا (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } وإلا إذا (bt1 == VT_PTR || bt2 == VT_PTR) {
        إذا (op == '+') {
          إذا (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        وإلا إذا (is_null_اشاره_ګر (op2)) type = *type1;
        وإلا إذا (is_null_اشاره_ګر (op1)) type = *type2;
        وإلا إذا (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            إذا ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            وإلا إذا (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } وإلا {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            صحيح pbt1 = pt1->t & VT_BTYPE;
            صحيح pbt2 = pt2->t & VT_BTYPE;
            صحيح newquals, copied = 0;
            إذا (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                إذا (op != '?' && op != CMP_OP)
                  ret = 0;
                وإلا
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            إذا (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                إذا ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ټېل(SYM_ډګر, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                إذا (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    إذا (!copied)
                      type.ref = sym_ټېل(SYM_ډګر, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ټېل(SYM_ډګر, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        إذا (op == CMP_OP)
          type.t = VT_اندازه_T;
    } وإلا إذا (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        إذا (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } وإلا إذا (is_float(bt1) || is_float(bt2)) {
        إذا (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } وإلا إذا (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } وإلا {
            type.t = VT_FLOAT;
        }
    } وإلا إذا (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        إذا (bt1 == VT_LLONG)
          type.t &= t1;
        إذا (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        إذا ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } وإلا {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        إذا (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || بټ_اندازه(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || بټ_اندازه(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    إذا (dest)
      *dest = type;
    أرجع ret;
}

/* generic gen_op: handles types problems */
ST_FUNC فراغ gen_op(صحيح op)
{
    صحيح t1, t2, bt1, bt2, t;
    CType type1, combtype;
    صحيح op_class = op;

    إذا (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = ښويدنه_OP;
    وإلا إذا (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    إذا (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	إذا (bt2 == VT_FUNC) {
	    mk_اشاره_ګر(&vtop->type);
	    gaddrof();
	}
	إذا (bt1 == VT_FUNC) {
	    vswap();
	    mk_اشاره_ګر(&vtop->type);
	    gaddrof();
	    vswap();
	}
	اذهب redo;
    } وإلا إذا (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } وإلا إذا (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        صحيح align;
        إذا (op_class == CMP_OP)
            اذهب std_op;
        /* if both pointers, then it must be the '-' op */
        إذا (bt1 == VT_PTR && bt2 == VT_PTR) {
            إذا (op != '-')
                اذهب op_err;
            vpush_type_اندازه(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } وإلا {
            /* exactly one pointer : must be '+' or '-'. */
            إذا (op != '-' && op != '+')
                اذهب op_err;
            /* Put pointer as first operand */
            إذا (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#إذا PTR_اندازه == 4
            إذا (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#د_که_پای
            type1 = vtop[-1].type;
            vpush_type_اندازه(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#که_تعریف_شوی CONFIG_TCC_BCHECK
            إذا (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                إذا (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_جمع_کړه();
            } وإلا
#د_که_پای
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } وإلا {
        /* floats can only be used for a few operations */
        إذا (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            اذهب op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        إذا (op_class == ښويدنه_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        إذا (t & VT_UNSIGNED) {
            إذا (op == TOK_SAR)
                op = TOK_SHR;
            وإلا إذا (op == '/')
                op = TOK_UDIV;
            وإلا إذا (op == '%')
                op = TOK_UMOD;
            وإلا إذا (op == TOK_LT)
                op = TOK_ULT;
            وإلا إذا (op == TOK_GT)
                op = TOK_UGT;
            وإلا إذا (op == TOK_LE)
                op = TOK_ULE;
            وإلا إذا (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        إذا (is_float(t))
            gen_opif(op);
        وإلا
            gen_opic(op);
        إذا (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } وإلا {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    إذا (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#إذا defined TCC_موخه_ARM64 || defined TCC_موخه_RISCV64 || defined TCC_موخه_ARM
#تعریف_کړه gen_cvt_itof1 gen_cvt_itof
#وإلا
/* generic itof for unsigned long long case */
ساكن فراغ gen_cvt_itof1(صحيح t)
{
    إذا ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        إذا (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#إذا LDOUBLE_اندازه != 8
        وإلا إذا (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#د_که_پای
        وإلا
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } وإلا {
        gen_cvt_itof(t);
    }
}
#د_که_پای

#إذا defined TCC_موخه_ARM64 || defined TCC_موخه_RISCV64
#تعریف_کړه gen_cvt_ftoi1 gen_cvt_ftoi
#وإلا
/* generic ftoi for unsigned long long case */
ساكن فراغ gen_cvt_ftoi1(صحيح t)
{
    صحيح st;
    إذا (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        إذا (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#إذا LDOUBLE_اندازه != 8
        وإلا إذا (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#د_که_پای
        وإلا
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } وإلا {
        gen_cvt_ftoi(t);
    }
}
#د_که_پای

/* special delayed cast for char/short */
ساكن فراغ force_charshort_cast(فراغ)
{
    صحيح sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    صحيح dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ساكن فراغ gen_cast_s(صحيح t)
{
    CType type;
    type.t = t;
    type.ref = عدم;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ساكن فراغ gen_cast(CType *type)
{
    صحيح sbt, dbt, sf, df, c;
    صحيح dbt_bt, sbt_bt, ds, ss, بټونه, trunc;

    /* special delayed cast for char/short */
    إذا (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    إذا (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    إذا (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    إذا (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    إذا (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        إذا (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            اذهب بشپړ;
        }
        إذا (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        إذا (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            إذا (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            وإلا إذا (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            إذا (df) {
                إذا (sbt_bt == VT_LLONG) {
                    إذا ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    وإلا
                        vtop->c.ld = -(اوږد مزدوج)-vtop->c.i;
                } وإلا إذا(!sf) {
                    إذا ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    وإلا
                        vtop->c.ld = -(اوږد مزدوج)-(uint32_t)vtop->c.i;
                }

                إذا (dbt == VT_FLOAT)
                    vtop->c.f = (عائم)vtop->c.ld;
                وإلا إذا (dbt == VT_DOUBLE)
                    vtop->c.d = (مزدوج)vtop->c.ld;
            } وإلا إذا (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } وإلا {
                إذا(sf) {
                    إذا (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    وإلا
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                وإلا إذا (sbt_bt == VT_LLONG || (PTR_اندازه == 8 && sbt == VT_PTR))
                    ;
                وإلا إذا (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                وإلا
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                إذا (dbt_bt == VT_LLONG || (PTR_اندازه == 8 && dbt == VT_PTR))
                    ;
                وإلا إذا (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                وإلا {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    إذا (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            اذهب بشپړ;

        } وإلا إذا (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            اذهب بشپړ;
        }

        /* cannot generate code for global or static initializers */
        إذا (nocode_wanted & معلومات_ONLY_WANTED) {
            إذا (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            اذهب بشپړ;
        }

        /* non constant case: generate code */
        إذا (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            اذهب بشپړ;
        }

        إذا (sf || df) {
            إذا (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } وإلا إذا (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } وإلا {
                /* convert fp to int */
                sbt = dbt;
                إذا (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                اذهب again; /* may need char/short cast */
            }
            اذهب بشپړ;
        }

        ds = btype_اندازه(dbt_bt);
        ss = btype_اندازه(sbt_bt);
        إذا (ds == 0 || ss == 0)
            اذهب error;

        /* same size and no sign conversion needed */
        إذا (ds == ss && ds >= 4)
            اذهب بشپړ;
        إذا (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            إذا (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_اندازه == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #تعریف_کړه ALLOW_SUBTYPE_ACCESS 1

        إذا (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            إذا (ds <= ss)
                اذهب بشپړ;
            /* ss <= 4 here */
            إذا (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                اذهب بشپړ; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#إذا PTR_اندازه == 4
        إذا (ds == 8) {
            /* generate high word */
            إذا (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } وإلا {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } وإلا إذا (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#وإلاإذا PTR_اندازه == 8
        إذا (ds == 8) {
            /* need to convert from 32bit to 64bit */
            إذا (sbt & VT_UNSIGNED) {
#إذا defined(TCC_موخه_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#وإلا
                اذهب بشپړ;
#د_که_پای
            } وإلا {
                gen_cvt_sxtw();
                اذهب بشپړ;
            }
            ss = ds, ds = 4, dbt = sbt;
        } وإلا إذا (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#إذا !defined(TCC_موخه_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#د_که_پای
        } وإلا {
            ss = 4;
        }
#د_که_پای

        إذا (ds >= ss)
            اذهب بشپړ;
#إذا defined TCC_موخه_I386 || defined TCC_موخه_X86_64 || defined TCC_موخه_ARM64 || defined TCC_موخه_RISCV64
    إذا (ss == 4) {
        gen_cvt_csti(dbt);
        اذهب بشپړ;
    }
#د_که_پای
        بټونه = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(بټونه);
        gen_op(TOK_SHL);
        vpushi(بټونه - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
بشپړ:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC صحيح type_اندازه(CType *type, صحيح *a)
{
    Sym *s;
    صحيح bt;

    bt = type->t & VT_BTYPE;
    إذا (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        أرجع s->c;
    } وإلا إذا (bt == VT_PTR) {
        إذا (type->t & VT_ARRAY) {
            صحيح ts;
            s = type->ref;
            ts = type_اندازه(&s->type, a);
            إذا (s->c < 0)
                أرجع s->c;
            أرجع ts * s->c;
        } وإلا {
            *a = PTR_اندازه;
            أرجع PTR_اندازه;
        }
    } وإلا إذا (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        أرجع -1; /* incomplete enum */
    } وإلا إذا (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        أرجع LDOUBLE_اندازه;
    } وإلا إذا (bt == VT_DOUBLE || bt == VT_LLONG) {
#إذا (defined TCC_موخه_I386 && !defined TCC_موخه_PE) \
 || (defined TCC_موخه_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#وإلا
        *a = 8;
#د_که_پای
        أرجع 8;
    } وإلا إذا (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        أرجع 4;
    } وإلا إذا (bt == VT_SHORT) {
        *a = 2;
        أرجع 2;
    } وإلا إذا (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        أرجع 16;
    } وإلا {
        /* char, void, function, _Bool */
        *a = 1;
        أرجع 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ساكن فراغ vpush_type_اندازه(CType *type, صحيح *a)
{
    إذا (type->t & VT_VLA) {
        type_اندازه(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } وإلا {
        صحيح اندازه = type_اندازه(type, a);
        إذا (اندازه < 0)
            tcc_error("unknown type size");
        vpushs(اندازه);
    }
}

/* return the pointed type of t */
ساكن مضمن CType *pointed_type(CType *type)
{
    أرجع &type->ref->type;
}

ساكن فراغ check_restrict_type(CType *type)
{
    طالما ((type->t & VT_BTYPE) == VT_PTR) {
        إذا ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    إذا (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ساكن صحيح type_qualifiers(CType *type)
{
    طالما (type->t & VT_ARRAY)
        type = pointed_type(type);
    أرجع type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC فراغ mk_اشاره_ګر(CType *type)
{
    Sym *s;
    s = sym_ټېل(SYM_ډګر, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ساكن صحيح is_compatible_types(CType *type1, CType *type2)
{
    أرجع compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ساكن صحيح is_compatible_unqualified_types(CType *type1, CType *type2)
{
    أرجع compare_types(type1,type2,1);
}

ساكن فراغ cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ساكن فراغ verify_ټاکل_cast(CType *dt)
{
    CType *st, *type1, *type2;
    صحيح dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    إذا (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    بدل(dbt) {
    حالة VT_VOID:
        إذا (sbt != dbt)
            tcc_error("assignment to void expression");
        اكسر;
    حالة VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        إذا (is_null_اشاره_ګر(vtop))
            اكسر;
        /* accept implicit pointer to integer cast with warning */
        إذا (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            اكسر;
        }
        type1 = pointed_type(dt);
        إذا (sbt == VT_PTR)
            type2 = pointed_type(st);
        وإلا إذا (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        وإلا
            اذهب error;
        إذا (is_compatible_types(type1, type2))
            اكسر;
        لكل (qualwarn = lvl = 0;; ++lvl) {
            إذا ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            إذا (dbt != VT_PTR || sbt != VT_PTR)
                اكسر;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        إذا (!is_compatible_unqualified_types(type1, type2)) {
            إذا ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } وإلا إذا (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } وإلا {
                tcc_warning("assignment from incompatible pointer type");
                اكسر;
            }
        }
        إذا (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        اكسر;
    حالة VT_BYTE:
    حالة VT_SHORT:
    حالة VT_INT:
    حالة VT_LLONG:
        إذا (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } وإلا إذا (sbt == VT_STRUCT) {
            اذهب case_VT_STRUCT;
        }
        /* XXX: more tests */
        اكسر;
    حالة VT_STRUCT:
    case_VT_STRUCT:
        إذا (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        اكسر;
    }
}

ساكن فراغ gen_ټاکل_cast(CType *dt)
{
    verify_ټاکل_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC فراغ vstore(فراغ)
{
    صحيح sbt, dbt, ft, r, اندازه, align, بټ_اندازه_2, بټ_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_ټاکل_cast(&vtop[-1].type);

    إذا (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        اندازه = type_اندازه(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#د_که_پای
        vtop->type.t = VT_PTR;
        gaddrof();
        /*سرچینه*/
        vswap();
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (vtop->r & VT_MUSTBOUND)
            gbound();
#د_که_پای
        vtop->type.t = VT_PTR;
        gaddrof();

#که_تعریف_شوی TCC_موخه_NATIVE_STRUCT_COPY
        إذا (1
#که_تعریف_شوی CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#د_که_پای
            ) {
            gen_struct_copy(اندازه);
        } وإلا
#د_که_پای
        {
            /* type size */
            vpushi(اندازه);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#که_تعریف_شوی TCC_ARM_EABI
            إذا(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            وإلا إذا(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            وإلا
#د_که_پای
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } وإلا إذا (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        بټ_pos = بټ_POS(ft);
        بټ_اندازه_2 = بټ_اندازه(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_ماسک;

        إذا (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, بټ_pos, بټ_اندازه_2);
        إذا (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        إذا (r == VT_STRUCT) {
            store_packed_bf(بټ_pos, بټ_اندازه_2);
        } وإلا {
            بینښه اوږد اوږد ماسک = (1ULL << بټ_اندازه_2) - 1;
            إذا (dbt != VT_BOOL) {
                /* mask source */
                إذا (dbt == VT_LLONG)
                    vpushll(ماسک);
                وإلا
                    vpushi((بینښه)ماسک);
                gen_op('&');
            }
            /* shift source */
            vpushi(بټ_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            إذا (dbt == VT_LLONG)
                vpushll(~(ماسک << بټ_pos));
            وإلا
                vpushi(~((بینښه)ماسک << بټ_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } وإلا إذا (dbt == VT_VOID) {
        --vtop;
    } وإلا {
            /* optimize char/short casts */
            delayed_cast = 0;
            إذا ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                إذا ((vtop->r & VT_MUSTCAST)
                    && btype_اندازه(dbt) > btype_اندازه(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } وإلا {
                gen_cast(&vtop[-1].type);
            }

#که_تعریف_شوی CONFIG_TCC_BCHECK
            /* bound check case */
            إذا (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#د_که_پای
            gv(RC_TYPE(dbt)); /* generate value */

            إذا (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            إذا ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = عدم;
                بارول(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            إذا (USING_TWO_ټکي(dbt)) {
                صحيح بارول_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = بارول_type;
                store(r, vtop - 1);
                vswap();
                incr_دننه_واټن(PTR_اندازه);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } وإلا {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC فراغ inc(صحيح post, صحيح c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    إذا (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    إذا (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ثابت حرف *پیغام)
{
    /* read the string */
    إذا (tok != TOK_STR)
        expect(پیغام);
    cstr_reset(&initstr);
    طالما (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.معلومات, -1);
        بل();
    }
    cstr_ccat(&initstr, '\0');
    أرجع &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC صحيح exact_log2p1(صحيح i)
{
  صحيح ret;
  إذا (!i)
    أرجع 0;
  لكل (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  إذا (i >= 1 << 4)
    ret += 4, i >>= 4;
  إذا (i >= 1 << 2)
    ret += 2, i >>= 2;
  إذا (i >= 1 << 1)
    ret++;
  أرجع ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ساكن فراغ parse_attribute(AttributeDef *ad)
{
    صحيح t, n;
    حرف *astr;
    AttributeDef ad_tmp;
    
redo:
    إذا (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        أرجع;
    إذا (عدم == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    بل();
    skip('(');
    skip('(');
    طالما (tok != ')') {
        إذا (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        بل();
        بدل(t) {
	حالة TOK_CLEANUP1:
	حالة TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_پیدا_کړه(tok);
	    إذا (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } وإلا إذا ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    بل();
            skip(')');
	    اكسر;
	}
        حالة TOK_CONSTRUCTOR1:
        حالة TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            اكسر;
        حالة TOK_DESTRUCTOR1:
        حالة TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            اكسر;
        حالة TOK_ALWAYS_INLINE1:
        حالة TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            اكسر;
        حالة TOK_SECTION1:
        حالة TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->معلومات;
            n = tcc_state->nb_sections;
            ad->section = پیدا_کړه_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            اكسر;
        حالة TOK_ALIAS1:
        حالة TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->معلومات;
            /* save string as token, for later */
            ad->alias_موخه = tok_alloc_const(astr);
            skip(')');
            اكسر;
	حالة TOK_VISIBILITY1:
	حالة TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->معلومات;
	    إذا (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    وإلا إذا (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    وإلا إذا (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_دننی;
	    وإلا إذا (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    وإلا
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            اكسر;
        حالة TOK_ALIGNED1:
        حالة TOK_ALIGNED2:
            إذا (tok == '(') {
                بل();
                n = بیان_const();
                إذا (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } وإلا {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    إذا (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            اكسر;
        حالة TOK_PACKED1:
        حالة TOK_PACKED2:
            ad->a.packed = 1;
            اكسر;
        حالة TOK_WEAK1:
        حالة TOK_WEAK2:
            ad->a.weak = 1;
            اكسر;
        حالة TOK_NODEBUG1:
        حالة TOK_NODEBUG2:
            ad->a.nodebug = 1;
            اكسر;
        حالة TOK_USED1:
        حالة TOK_USED2:
        حالة TOK_UNUSED1:
        حالة TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            اكسر;
        حالة TOK_CONST1:
        حالة TOK_CONST2:
        حالة TOK_CONST3:
        حالة TOK_PURE1:
        حالة TOK_PURE2:
	    /* ignored */
            اكسر;
        حالة TOK_NOINLINE:
	    /* ignored */
	    اكسر;
        حالة TOK_FORMAT1:
        حالة TOK_FORMAT2:
	    /* ignored */
            اذهب skip_param;
        حالة TOK_NORETURN1:
        حالة TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            اكسر;
        حالة TOK_CDECL1:
        حالة TOK_CDECL2:
        حالة TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            اكسر;
        حالة TOK_STDCALL1:
        حالة TOK_STDCALL2:
        حالة TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            اكسر;
#که_تعریف_شوی TCC_موخه_I386
        حالة TOK_REGPARM1:
        حالة TOK_REGPARM2:
            skip('(');
            n = بیان_const();
            إذا (n > 3) 
                n = 3;
            وإلا إذا (n < 0)
                n = 0;
            إذا (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            اكسر;
        حالة TOK_FASTCALL1:
        حالة TOK_FASTCALL2:
        حالة TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            اكسر;
        حالة TOK_THISCALL1:
        حالة TOK_THISCALL2:
        حالة TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            اكسر;
#د_که_پای
        حالة TOK_ډېرپېښ:
            skip('(');
            بدل(tok) {
                حالة TOK_ډېرپېښ_DI:
                    ad->attr_ډېرپېښ = VT_LLONG + 1;
                    اكسر;
                حالة TOK_ډېرپېښ_QI:
                    ad->attr_ډېرپېښ = VT_BYTE + 1;
                    اكسر;
                حالة TOK_ډېرپېښ_HI:
                    ad->attr_ډېرپېښ = VT_SHORT + 1;
                    اكسر;
                حالة TOK_ډېرپېښ_SI:
                حالة TOK_ډېرپېښ_کلمه:
                    ad->attr_ډېرپېښ = VT_INT + 1;
                    اكسر;
                افتراضي:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, عدم));
                    اكسر;
            }
            بل();
            skip(')');
            اكسر;
        حالة TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            اكسر;
        حالة TOK_NODECORATE:
            ad->a.nodecorate = 1;
            اكسر;
        حالة TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            اكسر;
        افتراضي:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, عدم));
            /* skip parameters */
skip_param:
            إذا (tok == '(') {
                صحيح parenthesis = 0;
                افعل {
                    إذا (tok == '(') 
                        parenthesis++;
                    وإلا إذا (tok == ')') 
                        parenthesis--;
                    بل();
                } طالما (parenthesis && tok != -1);
            }
            اكسر;
        }
        إذا (tok != ',')
            اكسر;
        بل();
    }
    skip(')');
    skip(')');
    اذهب redo;
}

ساكن Sym * پیدا_کړه_ډګر (CType *type, صحيح v, صحيح *cumofs)
{
    Sym *s = type->ref;
    صحيح v1 = v | SYM_ډګر;
    إذا (!(v & SYM_ډګر)) { /* top-level call */
        إذا ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        إذا (v < TOK_UIDENT)
            expect("field name");
        إذا (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    طالما ((s = s->بل) != عدم) {
        إذا (s->v == v1) {
            *cumofs = s->c;
            أرجع s;
        }
        إذا ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_لومړی_ANOM | SYM_ډګر)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = پیدا_کړه_ډګر (&s->type, v1, cumofs);
            إذا (ret) {
                *cumofs += s->c;
                أرجع ret;
            }
        }
    }
    إذا (!(v & SYM_ډګر))
        tcc_error("field not found: %s", get_tok_str(v, عدم));
    أرجع s;
}

ساكن فراغ check_fields (CType *type, صحيح check)
{
    Sym *s = type->ref;

    طالما ((s = s->بل) != عدم) {
        صحيح v = s->v & ~SYM_ډګر;
        إذا (v < SYM_لومړی_ANOM) {
            TokenSym *ts = جدول_ident[v - TOK_IDENT];
            إذا (check && (ts->tok & SYM_ډګر))
                tcc_error("duplicate member '%s'", get_tok_str(v, عدم));
            ts->tok ^= SYM_ډګر;
        } وإلا إذا ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ساكن فراغ struct_layout(CType *type, AttributeDef *ad)
{
    صحيح اندازه, align, maxalign, دننه_واټن, c, بټ_pos, بټ_اندازه_2;
    صحيح packed, a, bt, prevbt, prev_بټ_اندازه;
    صحيح pcc = !tcc_state->ms_bitfields;
    صحيح pragma_pack = *tcc_state->pack_ډېری_ptr;
    Sym *f;

    maxalign = 1;
    دننه_واټن = 0;
    c = 0;
    بټ_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_بټ_اندازه = 0;

//#define BF_DEBUG

    لكل (f = type->ref->بل; f; f = f->بل) {
        إذا (f->type.t & VT_BITFIELD)
            بټ_اندازه_2 = بټ_اندازه(f->type.t);
        وإلا
            بټ_اندازه_2 = -1;
        اندازه = type_اندازه(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        إذا (pcc && بټ_اندازه_2 == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } وإلا {
            /* in pcc mode, attribute packed overrides if set. */
            إذا (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            إذا (pragma_pack) {
                packed = 1;
                إذا (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                إذا (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        إذا (a)
            align = a;

        إذا (type->ref->type.t == VT_UNION) {
	    إذا (pcc && بټ_اندازه_2 >= 0)
	        اندازه = (بټ_اندازه_2 + 7) >> 3;
	    دننه_واټن = 0;
	    إذا (اندازه > c)
	        c = اندازه;

	} وإلا إذا (بټ_اندازه_2 < 0) {
            إذا (pcc)
                c += (بټ_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    دننه_واټن = c;
	    إذا (اندازه > 0)
	        c += اندازه;
	    بټ_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_بټ_اندازه = 0;

	} وإلا {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            إذا (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                إذا (بټ_اندازه_2 == 0) {
            new_ډګر:
		    c = (c + ((بټ_pos + 7) >> 3) + align - 1) & -align;
		    بټ_pos = 0;
                } وإلا إذا (f->a.aligned) {
                    اذهب new_ډګر;
                } وإلا إذا (!packed) {
                    صحيح a8 = align * 8;
	            صحيح ofs = ((c * 8 + بټ_pos) % a8 + بټ_اندازه_2 + a8 - 1) / a8;
                    إذا (ofs > اندازه / align)
                        اذهب new_ډګر;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                إذا (اندازه == 8 && بټ_اندازه_2 <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, اندازه = 4;

                طالما (بټ_pos >= align * 8)
                    c += align, بټ_pos -= align * 8;
                دننه_واټن = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		إذا (f->v & SYM_لومړی_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } وإلا {
		bt = f->type.t & VT_BTYPE;
		إذا ((بټ_pos + بټ_اندازه_2 > اندازه * 8)
                    || (بټ_اندازه_2 > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    دننه_واټن = c;
		    بټ_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    إذا (بټ_اندازه_2 || prev_بټ_اندازه)
		        c += اندازه;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		إذا (بټ_اندازه_2 == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_بټ_اندازه = بټ_اندازه_2;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ښويدنه))
		        | (بټ_pos << VT_STRUCT_ښويدنه);
	    بټ_pos += بټ_اندازه_2;
	}
	إذا (align > maxalign)
	    maxalign = align;

#که_تعریف_شوی BF_DEBUG
	چاپ_کړه("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_ډګر, عدم), دننه_واټن, اندازه, align);
	إذا (f->type.t & VT_BITFIELD) {
	    چاپ_کړه(" pos %-2d bits %-2d",
                    بټ_POS(f->type.t),
                    بټ_اندازه(f->type.t)
                    );
	}
	چاپ_کړه("\n");
#د_که_پای

        f->c = دننه_واټن;
	f->r = 0;
    }

    إذا (pcc)
        c += (بټ_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    إذا (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    إذا (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        إذا (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#که_تعریف_شوی BF_DEBUG
    چاپ_کړه("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#د_که_پای

    /* check whether we can access bitfields by their type */
    لكل (f = type->ref->بل; f; f = f->بل) {
        صحيح s, px, cx, c0;
        CType t;

        إذا (0 == (f->type.t & VT_BITFIELD))
            استمر;
        f->type.ref = f;
        f->auxtype = -1;
        بټ_اندازه_2 = بټ_اندازه(f->type.t);
        إذا (بټ_اندازه_2 == 0)
            استمر;
        بټ_pos = بټ_POS(f->type.t);
        اندازه = type_اندازه(&f->type, &align);

        إذا (بټ_pos + بټ_اندازه_2 <= اندازه * 8 && f->c + اندازه <= c
#که_تعریف_شوی TCC_موخه_ARM
            && !(f->c & (align - 1))
#د_که_پای
            )
            استمر;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        لكل (;;) {
            px = f->c * 8 + بټ_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            إذا (c0 == cx)
                اكسر;
            s = (px + بټ_اندازه_2 + 7) >> 3;
            إذا (s > 4) {
                t.t = VT_LLONG;
            } وإلا إذا (s > 2) {
                t.t = VT_INT;
            } وإلا إذا (s > 1) {
                t.t = VT_SHORT;
            } وإلا {
                t.t = VT_BYTE;
            }
            s = type_اندازه(&t, &align);
            c0 = cx;
        }

        إذا (px + بټ_اندازه_2 <= s * 8 && cx + s <= c
#که_تعریف_شوی TCC_موخه_ARM
            && !(cx & (align - 1))
#د_که_پای
            ) {
            /* update offset and bit position */
            f->c = cx;
            بټ_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_ښويدنه))
		        | (بټ_pos << VT_STRUCT_ښويدنه);
            إذا (s != اندازه)
                f->auxtype = t.t;
#که_تعریف_شوی BF_DEBUG
            چاپ_کړه("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_ډګر, عدم),
                cx, s, align, px, بټ_اندازه_2);
#د_که_پای
        } وإلا {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#که_تعریف_شوی BF_DEBUG
            چاپ_کړه("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_ډګر, عدم));
#د_که_پای
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ساكن صحيح دننه_range(اوږد اوږد n, صحيح t)
{
    بینښه اوږد اوږد m = (1ULL << (btype_اندازه(t & VT_BTYPE) * 8 - 1)) - 1;
    إذا (t & VT_UNSIGNED)
        أرجع n <= (m << 1) + 1;
    أرجع n >= -(اوږد اوږد)m - 1 && n <= (اوږد اوږد)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ساكن فراغ struct_decl(CType *type, صحيح u)
{
    صحيح v, c, اندازه, align, flexible;
    صحيح بټ_اندازه_2, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, حجم ad);
    بل();
    parse_attribute(&ad);

    v = 0;
    إذا (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, بل();

    bt = ut = 0;
    إذا (u == VT_ENUM) {
        ut = VT_INT;
        إذا (tok == ':') { /* C2x enum : <type> ... */
            بل();
            إذا (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    إذا (v) {
        /* struct already defined ? return it */
        s = struct_پیدا_کړه(v);
        إذا (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            إذا (u == s->type.t)
                اذهب do_decl;
            إذا (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                اذهب do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, عدم));
        }
    } وإلا {
        إذا (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = عدم;
    /* we put an undefined size for struct/union */
    s = sym_ټېل(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    إذا (tok == '{') {
        بل();
        إذا (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->بل;
        إذا (u == VT_ENUM) {
            اوږد اوږد ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            إذا (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            لكل(;;) {
                v = tok;
                إذا (v < TOK_UIDENT)
                    expect("identifier");
                بل();
                إذا (tok == '=') {
                    بل();
		    ll = بیان_const64();
                }
                إذا (bt && !دننه_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, عدم));
                ss = sym_ټېل(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->بل;
                إذا (ll < nl)
                    nl = ll;
                إذا (ll > pl)
                    pl = ll;
                إذا (tok != ',')
                    اكسر;
                بل();
                ll++;
                /* NOTE: we accept a trailing comma */
                إذا (tok == '}')
                    اكسر;
            }
            skip('}');

            إذا (bt) {
                t.t = bt;
                s->c = 2;
                اذهب enum_بشپړ;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            إذا (nl >= 0) {
                إذا (pl != (بینښه)pl)
                    t.t = (LONG_اندازه==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } وإلا إذا (pl != (صحيح)pl || nl != (صحيح)nl)
                t.t = (LONG_اندازه==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            لكل (ss = s->بل; ss; ss = ss->بل) {
                ll = ss->enum_val;
                إذا (ll == (صحيح)ll) /* default is int if it fits */
                    استمر;
                إذا (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    إذا (ll == (بینښه)ll)
                        استمر;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_اندازه==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_بشپړ:
            s->type.t = type->t = t.t | VT_ENUM;

        } وإلا {
            c = 0;
            flexible = 0;
            طالما (tok != '}') {
                إذا (!parse_btype(&btype, &ad1, 0)) {
                    إذا (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        استمر;
                    }
		    skip(';');
		    استمر;
		}
                طالما (1) {
		    إذا (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, عدم));
                    بټ_اندازه_2 = -1;
                    v = 0;
                    type1 = btype;
                    إذا (tok != ':') {
			إذا (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_مستقیم);
                        إذا (v == 0) {
                    	    إذا ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    وإلا {
				صحيح v = btype.ref->v;
				إذا ((v & ~SYM_STRUCT) < SYM_لومړی_ANOM) {
				    إذا (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        إذا (type_اندازه(&type1, &align) < 0) {
			    إذا ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    وإلا
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, عدم));
                        }
                        إذا ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, عدم));
                    }
                    إذا (tok == ':') {
                        بل();
                        بټ_اندازه_2 = بیان_const();
                        /* XXX: handle v = 0 case for messages */
                        إذا (بټ_اندازه_2 < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, عدم));
                        إذا (v && بټ_اندازه_2 == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, عدم));
			parse_attribute(&ad1);
                    }
                    اندازه = type_اندازه(&type1, &align);
                    إذا (بټ_اندازه_2 >= 0) {
                        bt = type1.t & VT_BTYPE;
                        إذا (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = اندازه * 8;
                        إذا (بټ_اندازه_2 > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, عدم));
                        } وإلا إذا (بټ_اندازه_2 == bsize
				    && !*tcc_state->pack_ډېری_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } وإلا إذا (بټ_اندازه_2 == 64) {
                            tcc_error("field width 64 not implemented");
                        } وإلا {
                            type1.t = (type1.t & ~VT_STRUCT_ماسک)
                                | VT_BITFIELD
                                | ((بینښه)بټ_اندازه_2 << (VT_STRUCT_ښويدنه + 6));
                        }
                    }
                    إذا (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    إذا (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 بټ_اندازه_2 >= 0)) {
		        v = anon_sym++;
		    }
                    إذا (v) {
                        ss = sym_ټېل(v | SYM_ډګر, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->بل;
                    }
                    إذا (tok == ';' || tok == TOK_EOF)
                        اكسر;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            إذا (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        إذا (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ساكن فراغ sym_منزل_attr(AttributeDef *ad, Sym *s)
{
    یوځای_symattr(&ad->a, &s->a);
    یوځای_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ساكن فراغ parse_btype_qualify(CType *type, صحيح qualifiers)
{
    طالما (type->t & VT_ARRAY) {
        type->ref = sym_ټېل(SYM_ډګر, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    إذا (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ساكن صحيح parse_btype(CType *type, AttributeDef *ad, صحيح ignore_label)
{
    صحيح t, u, bt, st, type_وموندل, typespec_وموندل, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, حجم(AttributeDef));
    type_وموندل = 0;
    typespec_وموندل = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = عدم;

    طالما(1) {
        بدل(tok) {
        حالة TOK_EXTENSION:
            /* currently, we really ignore extension */
            بل();
            استمر;

            /* basic types */
        حالة TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            بل();
        basic_type1:
            إذا (u == VT_SHORT || u == VT_LONG) {
                إذا (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } وإلا {
                إذا (bt != -1 || (st != -1 && u != VT_INT))
                    اذهب tmbt;
                إذا ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    اذهب tmbt;
                bt = u;
            }
            إذا (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_وموندل = 1;
            اكسر;
        حالة TOK_VOID:
            u = VT_VOID;
            اذهب basic_type;
        حالة TOK_SHORT:
            u = VT_SHORT;
            اذهب basic_type;
        حالة TOK_INT:
            u = VT_INT;
            اذهب basic_type;
        حالة TOK_ALIGNAS:
            { صحيح n;
              AttributeDef ad1;
              بل();
              skip('(');
              memset(&ad1, 0, حجم(AttributeDef));
              إذا (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  إذا (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  وإلا
                    type_اندازه(&type1, &n);
              } وإلا {
                  n = بیان_const();
                  إذا (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            استمر;
        حالة TOK_LONG:
            إذا ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } وإلا إذا ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } وإلا {
                u = VT_LONG;
                اذهب basic_type;
            }
            بل();
            اكسر;
        حالة TOK_BOOL:
            u = VT_BOOL;
            اذهب basic_type;
        حالة TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        حالة TOK_FLOAT:
            u = VT_FLOAT;
            اذهب basic_type;
        حالة TOK_DOUBLE:
            إذا ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } وإلا {
                u = VT_DOUBLE;
                اذهب basic_type;
            }
            بل();
            اكسر;
        حالة TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            اذهب basic_type1;
        حالة TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            اذهب basic_type2;
        حالة TOK_UNION:
            struct_decl(&type1, VT_UNION);
            اذهب basic_type2;

            /* type modifiers */
        حالة TOK__Atomic:
            بل();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            إذا (tok == '(') {
                parse_بیان_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                إذا (type1.ref)
                    sym_منزل_attr(ad, type1.ref);
                اذهب basic_type2;
            }
            اكسر;
        حالة TOK_CONST1:
        حالة TOK_CONST2:
        حالة TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            بل();
            اكسر;
        حالة TOK_VOLATILE1:
        حالة TOK_VOLATILE2:
        حالة TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            بل();
            اكسر;
        حالة TOK_SIGNED1:
        حالة TOK_SIGNED2:
        حالة TOK_SIGNED3:
            إذا ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            بل();
            typespec_وموندل = 1;
            اكسر;
        حالة TOK_RESTRICT1:
        حالة TOK_RESTRICT2:
        حالة TOK_RESTRICT3:
            t |= VT_RESTRICT;
            بل();
            اكسر;
        حالة TOK_ثبتوونکی:
        حالة TOK_AUTO:
            بل();
            اكسر;
        حالة TOK_UNSIGNED:
            إذا ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            بل();
            typespec_وموندل = 1;
            اكسر;

            /* storage */
        حالة TOK_EXTERN:
            g = VT_EXTERN;
            اذهب storage;
        حالة TOK_STATIC:
            g = VT_STATIC;
            اذهب storage;
        حالة TOK_TYPEDEF:
            g = VT_TYPEDEF;
            اذهب storage;
       storage:
            إذا (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            بل();
            اكسر;
        حالة TOK_INLINE1:
        حالة TOK_INLINE2:
        حالة TOK_INLINE3:
            t |= VT_INLINE;
            بل();
            اكسر;
        حالة TOK_NORETURN3:
            بل();
            ad->f.func_noreturn = 1;
            اكسر;
            /* GNUC attribute */
        حالة TOK_ATTRIBUTE1:
        حالة TOK_ATTRIBUTE2:
            parse_attribute(ad);
            إذا (ad->attr_ډېرپېښ) {
                u = ad->attr_ډېرپېښ -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            استمر;
            /* GNUC typeof */
        حالة TOK_TYPEOF1:
        حالة TOK_TYPEOF2:
        حالة TOK_TYPEOF3:
            بل();
            parse_بیان_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            إذا (type1.ref) {
                sym_منزل_attr(ad, type1.ref);
                إذا (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            اذهب basic_type2;
        حالة TOK_THREAD_LOCAL:
        حالة TOK___thread:
            إذا (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            بل();
            اكسر;
        افتراضي:
            إذا (typespec_وموندل)
                اذهب the_پای_ټکی;
            s = sym_پیدا_کړه(tok);
            إذا (!s || !(s->type.t & VT_TYPEDEF))
                اذهب the_پای_ټکی;

            n = tok, بل();
            إذا (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                اذهب the_پای_ټکی;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            إذا (t)
                parse_btype_qualify(type, t);
            t = type->t;
            إذا (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_منزل_attr(ad, s);
            typespec_وموندل = 1;
            st = bt = -2;
            اكسر;
        }
        type_وموندل = 1;
    }
the_پای_ټکی:
    إذا (tcc_state->char_is_unsigned) {
        إذا ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    إذا (bt == VT_LONG)
        t |= LONG_اندازه == 8 ? VT_LLONG : VT_INT;
#که_تعریف_شوی TCC_USING_DOUBLE_FOR_LDOUBLE
    إذا (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#د_که_پای
    type->t = t;
    check_restrict_type(type);
    أرجع type_وموندل;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ساكن مضمن فراغ convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    إذا ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_اشاره_ګر(pt);
    }
}

/* apply the conversions required for an expression value */
ساكن مضمن فراغ convert_افاده_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(فراغ)
{
    skip('(');
    أرجع parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ساكن صحيح asm_label_instr(فراغ)
{
    صحيح v;
    حرف *astr;

    بل();
    astr = parse_asm_str()->معلومات;
    skip(')');
#که_تعریف_شوی ASM_DEBUG
    چاپ_کړه("asm_alias: \"%s\"\n", astr);
#د_که_پای
    v = tok_alloc_const(astr);
    أرجع v;
}

ساكن صحيح post_type(CType *type, AttributeDef *ad, صحيح storage, صحيح td)
{
    صحيح n, l, t1, arg_اندازه, align;
    Sym **plast, *s, *لومړی, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = عدم;
    صحيح *vla_array_str = عدم;

    إذا (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        بل();
	إذا (TYPE_مستقیم == (td & (TYPE_مستقیم|TYPE_ABSTRACT)))
	  أرجع 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ډېری ? &local_ډېری : &global_ډېری;
        ++local_scope;
        sr = sym_push2(ps, SYM_ډګر, 0, 0);

	إذا (tok == ')')
	  l = 0;
	وإلا إذا (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	وإلا إذا (td & (TYPE_مستقیم|TYPE_ABSTRACT)) {
            sym_راوباسه(ps, sr->prev, 0);
            --local_scope;
	    یوځای_attr (ad, &ad1);
	    أرجع 0;
	} وإلا
	  l = FUNC_OLD;

        لومړی = عدم;
        plast = &لومړی;
        arg_اندازه = 0;
        إذا (l) {
            لكل(;;) {
                /* read param name and compute offset */
                إذا (l != FUNC_OLD) {
                    إذا ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        اكسر;
                    type_decl(&pt, &ad1, &n, TYPE_مستقیم | TYPE_ABSTRACT | TYPE_PARAM);
                    إذا ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    إذا (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_ډګر;
                } وإلا {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = عدم;
                    بل();
                }
                إذا (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_اندازه += (type_اندازه(&pt, &align) + PTR_اندازه - 1) / PTR_اندازه;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ټېل(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->بل;
                إذا (tok == ')')
                    اكسر;
                skip(',');
                إذا (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    بل();
                    اكسر;
                }
		إذا (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } وإلا
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        إذا (tok == '[') {
            بل();
            skip(']'); /* only handle simple "[]" */
            mk_اشاره_ګر(type);
        }
        ad->f.func_دلیلونه = arg_اندازه;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->بل = لومړی;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_راوباسه(ps, sr, 1);
        --local_scope;

    } وإلا إذا (tok == '[') {
	صحيح saved_nocode_wanted = nocode_wanted;
        صحيح array_qualifiers = 0;
        /* array definition */
        بل();
        n = -1;
        t1 = 0;
        إذا (td & TYPE_PARAM) طالما (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    بدل (tok) {
	    حالة TOK_CONST1: حالة TOK_CONST2: حالة TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		بل();
		استمر;
	    حالة TOK_VOLATILE1: حالة TOK_VOLATILE2: حالة TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		بل();
		استمر;
	    حالة TOK_RESTRICT1: حالة TOK_RESTRICT2: حالة TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		بل();
		استمر;
	    حالة TOK_STATIC:
	    حالة '*':
		بل();
		استمر;
	    افتراضي:
		اكسر;
	    }
            إذا (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_بلاک(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		بل();
	        gexpr();
		پای_ټکی_macro();
		بل();
		اذهب check;
            }
            اكسر;

	} وإلا إذا (tok != ']') {
            إذا (!local_ډېری || (storage & VT_STATIC))
                vpushi(بیان_const());
            وإلا {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                إذا (n < 0)
                    tcc_error("invalid array size");
            } وإلا {
                إذا (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_مستقیم|TYPE_ABSTRACT)) | TYPE_NEST);

        إذا ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        إذا ((type->t & VT_BTYPE) == VT_VOID
            || type_اندازه(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        إذا (t1 & VT_VLA) {
            إذا (n < 0) {
		إذا  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    وإلا {
                loc -= type_اندازه(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_اندازه(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        إذا (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ټېل(SYM_ډګر, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        إذا (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    إذا ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    وإلا
	        tok_str_free_str(vla_array_str);
	}
    }
    أرجع 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ساكن CType *type_decl(CType *type, AttributeDef *ad, صحيح *v, صحيح td)
{
    CType *post, *ret;
    صحيح qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    طالما (tok == '*') {
        qualifiers = 0;
    redo:
        بل();
        بدل(tok) {
        حالة TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            اذهب redo;
        حالة TOK_CONST1:
        حالة TOK_CONST2:
        حالة TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            اذهب redo;
        حالة TOK_VOLATILE1:
        حالة TOK_VOLATILE2:
        حالة TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            اذهب redo;
        حالة TOK_RESTRICT1:
        حالة TOK_RESTRICT2:
        حالة TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            اذهب redo;
	/* XXX: clarify attribute handling */
	حالة TOK_ATTRIBUTE1:
	حالة TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    اكسر;
        }
        mk_اشاره_ګر(type);
        type->t |= qualifiers;
	إذا (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    إذا (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	إذا (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} وإلا
	  اذهب abstract;
    } وإلا إذا (tok >= TOK_IDENT && (td & TYPE_مستقیم)) {
	/* type identifier */
	*v = tok;
	بل();
    } وإلا {
  abstract:
	إذا (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_مستقیم|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    أرجع ret;
}

/* indirection with full error checking and bound check */
ST_FUNC فراغ indir(فراغ)
{
    إذا ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        إذا ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            أرجع;
        expect("pointer");
    }
    إذا (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    إذا (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#د_که_پای
    }
}

/* pass a parameter to a function and do type checking and casting */
ساكن فراغ gfunc_param_typed(Sym *func, Sym *arg)
{
    صحيح func_type;
    CType type;

    func_type = func->f.func_type;
    إذا (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == عدم)) {
        /* default casting : only need to convert float to double */
        إذا ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } وإلا إذا (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } وإلا إذا (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } وإلا إذا (arg == عدم) {
        tcc_error("too many arguments to function");
    } وإلا {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_ټاکل_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ساكن فراغ بیان_type(CType *type, فراغ (*بیان_fn)(فراغ))
{
    nocode_wanted++;
    بیان_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ساكن فراغ parse_بیان_type(CType *type)
{
    صحيح n;
    AttributeDef ad;

    skip('(');
    إذا (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } وإلا {
        بیان_type(type, gexpr);
    }
    skip(')');
}

ساكن فراغ parse_type(CType *type)
{
    AttributeDef ad;
    صحيح n;

    إذا (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ساكن فراغ parse_builtin_params(صحيح nc, ثابت حرف *دلیلونه)
{
    حرف c, sep = '(';
    CType type;
    إذا (nc)
        nocode_wanted++;
    بل();
    إذا (*دلیلونه == 0)
	skip(sep);
    طالما ((c = *دلیلونه++)) {
	skip(sep);
	sep = ',';
        إذا (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    استمر;
        }
        بیان_eq();
        type.ref = عدم;
        type.t = 0;
	بدل (c) {
	    حالة 'e':
		استمر;
	    حالة 'V':
                type.t = VT_CONSTANT;
	    حالة 'v':
                type.t |= VT_VOID;
                mk_اشاره_ګر (&type);
                اكسر;
	    حالة 'S':
                type.t = VT_CONSTANT;
	    حالة 's':
                type.t |= char_type.t;
                mk_اشاره_ګر (&type);
                اكسر;
	    حالة 'i':
                type.t = VT_INT;
                اكسر;
	    حالة 'l':
                type.t = VT_اندازه_T;
                اكسر;
	    افتراضي:
                اكسر;
	}
        gen_ټاکل_cast(&type);
    }
    skip(')');
    إذا (nc)
        nocode_wanted--;
}

ساكن فراغ parse_atomic(صحيح atok)
{
    صحيح اندازه, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    حرف buf[40];
    ساكن ثابت حرف *ثابت templates[] = {
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
    ثابت حرف *کينډۍ = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = عدم;
    اندازه = 0; /* pacify compiler */
    بل();
    skip('(');
    لكل (arg = 0;;) {
        بیان_eq();
        بدل (کينډۍ[arg]) {
        حالة 'a':
        حالة 'A':
            atom_ptr = &vtop->type;
            إذا ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            اندازه = type_اندازه(atom, &align);
            إذا (اندازه > 8
                || (اندازه & (اندازه - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_اندازه(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            اكسر;

        حالة 'p':
            إذا ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_اندازه(pointed_type(&vtop->type), &align) != اندازه)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_ټاکل_cast(atom_ptr);
            اكسر;
        حالة 'v':
            gen_ټاکل_cast(atom);
            اكسر;
        حالة 'l':
            indir();
            gen_ټاکل_cast(atom);
            اكسر;
        حالة 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            اكسر;
        حالة 'm':
            gen_ټاکل_cast(&int_type);
            اكسر;
        حالة 'b':
            ct.t = VT_BOOL;
            gen_ټاکل_cast(&ct);
            اكسر;
        }
        إذا ('.' == کينډۍ[++arg])
            اكسر;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    بدل (کينډۍ[arg + 1]) {
    حالة 'b':
        ct.t = VT_BOOL;
        اكسر;
    حالة 'v':
        ct = *atom;
        اكسر;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), اندازه);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    إذا (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#که_تعریف_شوی PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#وإلا
        vtop->type.t = VT_INT;
#د_که_پای
    }
    gen_cast(&ct);
    إذا (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC فراغ unary(فراغ)
{
    صحيح n, t, align, اندازه, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    إذا (debug_modes)
        tcc_debug_کرښه(tcc_state), tcc_tcov_check_کرښه (tcc_state, 1);

    type.ref = عدم;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_بل:
    بدل(tok) {
    حالة TOK_EXTENSION:
        بل();
        اذهب tok_بل;
    حالة TOK_LCHAR:
#که_تعریف_شوی TCC_موخه_PE
        t = VT_SHORT|VT_UNSIGNED;
        اذهب ټېل_tokc;
#د_که_پای
    حالة TOK_CINT:
    حالة TOK_CCHAR: 
	t = VT_INT;
 ټېل_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        بل();
        اكسر;
    حالة TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        اذهب ټېل_tokc;
    حالة TOK_CLLONG:
        t = VT_LLONG;
	اذهب ټېل_tokc;
    حالة TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	اذهب ټېل_tokc;
    حالة TOK_CFLOAT:
        t = VT_FLOAT;
	اذهب ټېل_tokc;
    حالة TOK_CDOUBLE:
        t = VT_DOUBLE;
	اذهب ټېل_tokc;
    حالة TOK_CLDOUBLE:
#که_تعریف_شوی TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#وإلا
        t = VT_LDOUBLE;
#د_که_پای
	اذهب ټېل_tokc;
    حالة TOK_CLONG:
        t = (LONG_اندازه == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	اذهب ټېل_tokc;
    حالة TOK_CULONG:
        t = (LONG_اندازه == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	اذهب ټېل_tokc;
    حالة TOK___FUNCTION__:
        إذا (!gnu_ext)
            اذهب tok_identifier;
        /* fall thru */
    حالة TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.اندازه = tokcstr.اندازه;
        tokc.str.معلومات = tokcstr.معلومات;
        اذهب case_TOK_STR;
    حالة TOK_LSTR:
#که_تعریف_شوی TCC_موخه_PE
        t = VT_SHORT | VT_UNSIGNED;
#وإلا
        t = VT_INT;
#د_که_پای
        اذهب str_init;
    حالة TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        إذا (tcc_state->warn_write_مزي_ګانې & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_اشاره_ګر(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, حجم(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        اكسر;
    حالة TOK_SOTYPE:
    حالة '(':
        t = tok;
        بل();
        /* cast ? */
        إذا (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            إذا (tok == '{') {
                    /* data is allocated locally by default */
                إذا (global_بیان)
                    r = VT_CONST;
                وإلا
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                إذا (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, حجم(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } وإلا إذا (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                أرجع;
            } وإلا {
                unary();
                gen_cast(&type);
            }
        } وإلا إذا (tok == '{') {
	    صحيح saved_nocode_wanted = nocode_wanted;
            إذا (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            إذا (0 == local_scope)
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
            بلاک(STMT_بیان);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            إذا (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } وإلا {
            gexpr();
            skip(')');
        }
        اكسر;
    حالة '*':
        بل();
        unary();
        indir();
        اكسر;
    حالة '&':
        بل();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        إذا ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        إذا (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_اشاره_ګر(&vtop->type);
        gaddrof();
        اكسر;
    حالة '!':
        بل();
        unary();
        gen_test_zero(TOK_EQ);
        اكسر;
    حالة '~':
        بل();
        unary();
        vpushi(-1);
        gen_op('^');
        اكسر;
    حالة '+':
        بل();
        unary();
        إذا ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	إذا (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        اكسر;
    حالة TOK_SIZEOF:
    حالة TOK_ALIGNOF1:
    حالة TOK_ALIGNOF2:
    حالة TOK_ALIGNOF3:
        t = tok;
        بل();
        إذا (tok == '(')
            tok = TOK_SOTYPE;
        بیان_type(&type, unary);
        إذا (t == TOK_SIZEOF) {
            vpush_type_اندازه(&type, &align);
            gen_cast_s(VT_اندازه_T);
        } وإلا {
            type_اندازه(&type, &align);
            s = عدم;
            إذا (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            إذا (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        اكسر;

    حالة TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        اكسر;
    حالة TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        اكسر;
    حالة TOK_builtin_ټاکنه_بیان:
	{
	    int64_t c;
	    بل();
	    skip('(');
	    c = بیان_const64();
	    skip(',');
	    إذا (!c) {
		nocode_wanted++;
	    }
	    بیان_eq();
	    إذا (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    إذا (c) {
		nocode_wanted++;
	    }
	    بیان_eq();
	    إذا (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        اكسر;
    حالة TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        اكسر;
    حالة TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        کوډ_OFF();
        اكسر;
    حالة TOK_builtin_چوکاټ_پته:
    حالة TOK_builtin_return_پته:
        {
            صحيح tok1 = tok;
            صحيح level;
            بل();
            skip('(');
            level = بیان_const();
            إذا (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_اشاره_ګر(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            طالما (level--) {
#که_تعریف_شوی TCC_موخه_RISCV64
                vpushi(2*PTR_اندازه);
                gen_op('-');
#د_که_پای
                mk_اشاره_ګر(&vtop->type);
                indir();                    /* -> parent frame */
            }
            إذا (tok1 == TOK_builtin_return_پته) {
                // assume return address is just above frame pointer on stack
#که_تعریف_شوی TCC_موخه_ARM
                vpushi(2*PTR_اندازه);
                gen_op('+');
#وإلاإذا defined TCC_موخه_RISCV64
                vpushi(PTR_اندازه);
                gen_op('-');
#وإلا
                vpushi(PTR_اندازه);
                gen_op('+');
#د_که_پای
                mk_اشاره_ګر(&vtop->type);
                indir();
            }
        }
        اكسر;
#که_تعریف_شوی TCC_موخه_RISCV64
    حالة TOK_builtin_va_پیل:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        إذا (r == VT_LLOCAL)
            r = VT_LOCAL;
        إذا (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_پیل();
	vstore();
        اكسر;
#د_که_پای
#که_تعریف_شوی TCC_موخه_X86_64
#که_تعریف_شوی TCC_موخه_PE
    حالة TOK_builtin_va_پیل:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        إذا (r == VT_LLOCAL)
            r = VT_LOCAL;
        إذا (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_اشاره_ګر_type;
	vtop->c.i += 8;
	vstore();
        اكسر;
#وإلا
    حالة TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	اكسر;
#د_که_پای
#د_که_پای

#که_تعریف_شوی TCC_موخه_ARM64
    حالة TOK_builtin_va_پیل: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_پیل();
        vpushi(0);
        vtop->type.t = VT_VOID;
        اكسر;
    }
    حالة TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        اكسر;
    }
#د_که_پای
#که_تعریف_شوی TCC_موخه_ARM64
    حالة TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        اكسر;
    }
#د_که_پای
#که_تعریف_شوی TCC_موخه_RISCV64
    حالة TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        اكسر;
    }
#د_که_پای

    /* atomic operations */
    حالة TOK___atomic_store:
    حالة TOK_atomic_بارول:
    حالة TOK___atomic_exchange:
    حالة TOK___atomic_compare_exchange:
    حالة TOK_atomic_fetch_جمع_کړه:
    حالة TOK___atomic_fetch_sub:
    حالة TOK___atomic_fetch_or:
    حالة TOK___atomic_fetch_xor:
    حالة TOK___atomic_fetch_and:
    حالة TOK___atomic_fetch_nand:
    حالة TOK_atomic_جمع_کړه_fetch:
    حالة TOK___atomic_sub_fetch:
    حالة TOK___atomic_or_fetch:
    حالة TOK___atomic_xor_fetch:
    حالة TOK___atomic_and_fetch:
    حالة TOK___atomic_nand_fetch:
        parse_atomic(tok);
        اكسر;

    /* pre operations */
    حالة TOK_INC:
    حالة TOK_DEC:
        t = tok;
        بل();
        unary();
        inc(0, t);
        اكسر;
    حالة '-':
        بل();
        unary();
	إذا (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} وإلا {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        اكسر;
    حالة TOK_LAND:
        إذا (!gnu_ext)
            اذهب tok_identifier;
        بل();
        /* allow to take the address of a label */
        إذا (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_پیدا_کړه(tok);
        إذا (!s) {
            s = label_ټېل(&global_label_ډېری, tok, LABEL_FORWARD);
        } وإلا {
            إذا (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        إذا ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_اشاره_ګر(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        بل();
        اكسر;

    حالة TOK_GENERIC:
    {
	CType controlling_type;
	صحيح has_default = 0;
	صحيح has_سمون = 0;
	صحيح learn = 0;
	TokenString *str = عدم;
	صحيح saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_ماسک;

        بل();
	skip('(');
	بیان_type(&controlling_type, بیان_eq);
	convert_افاده_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        لكل (;;) {
	    learn = 0;
	    skip(',');
	    إذا (tok == TOK_DEFAULT) {
		إذا (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		إذا (!has_سمون)
		    learn = 1;
		بل();
	    } وإلا {
		صحيح v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		إذا (compare_types(&controlling_type, &type, 0)) {
		    إذا (has_سمون) {
		      tcc_error("type match twice");
		    }
		    has_سمون = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    إذا (learn) {
		إذا (str)
		    tok_str_free(str);
		skip_or_save_بلاک(&str);
	    } وإلا {
		skip_or_save_بلاک(عدم);
	    }
	    إذا (tok == ')')
		اكسر;
	}
	إذا (!str) {
	    حرف buf[60];
	    type_منزل_str(buf, حجم buf, &controlling_type, عدم);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	بل();
	بیان_eq();
	إذا (tok != TOK_EOF)
	    expect(",");
	پای_ټکی_macro();
        بل();
	اكسر;
    }
    // special qnan , snan and infinity values
    حالة TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        بل();
        اكسر;
    حالة TOK___SNAN__:
	n = 0x7f800001;
	اذهب special_math_val;
    حالة TOK___INF__:
	n = 0x7f800000;
	اذهب special_math_val;

    افتراضي:
    tok_identifier:
        إذا (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        بل();
        s = sym_پیدا_کړه(t);
        إذا (!s || IS_ASM_SYM(s)) {
            ثابت حرف *name = get_tok_str(t, عدم);
            إذا (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            إذا (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        إذا ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        إذا (r & VT_SYM) {
            vtop->c.i = 0;
#که_تعریف_شوی TCC_موخه_PE
            إذا (s->a.dllimport) {
                mk_اشاره_ګر(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#د_که_پای
        } وإلا إذا (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        اكسر;
    }
    
    /* post operations */
    طالما (1) {
        إذا (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            بل();
        } وإلا إذا (tok == '.' || tok == TOK_ARROW) {
            صحيح qualifiers, cumofs;
            /*ډګر*/ 
            إذا (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            بل();
	    s = پیدا_کړه_ډګر(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_اشاره_ګر_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            إذا (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            إذا (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#که_تعریف_شوی CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                إذا (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#د_که_پای
            }
            بل();
        } وإلا إذا (tok == '[') {
            بل();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } وإلا إذا (tok == '(') {
            SValue ret;
            Sym *sa;
            صحيح nb_دلیلونه, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            إذا ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                إذا ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    إذا ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        اذهب error_func;
                } وإلا {
                error_func:
                    expect("function pointer");
                }
            } وإلا {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            بل();
            sa = s->بل; /* first parameter */
            nb_دلیلونه = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            إذا ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                إذا (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    اندازه = type_اندازه(&s->type, &align);
#که_تعریف_شوی TCC_موخه_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                إذا (اندازه < 16)
                    طالما (اندازه & (اندازه - 1))
                        اندازه = (اندازه | (اندازه - 1)) + 1;
#د_که_پای
                    loc = (loc - اندازه) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#که_تعریف_شوی CONFIG_TCC_BCHECK
                    إذا (tcc_state->do_bounds_check)
                        --loc;
#د_که_پای
                    ret.c = vtop->c;
                    إذا (ret_nregs < 0)
                      vtop--;
                    وإلا
                      nb_دلیلونه++;
                }
            } وإلا {
                ret_nregs = 1;
                ret.type = s->type;
            }

            إذا (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = عدم;
            إذا (tok != ')') {
                r = tcc_state->سرچپه_funcargs;
                لكل(;;) {
                    إذا (r) {
                        skip_or_save_بلاک(&p2);
                        p2->prev = p, p = p2;
                    } وإلا {
                        بیان_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_دلیلونه++;
                    إذا (sa)
                        sa = sa->بل;
                    إذا (tok == ')')
                        اكسر;
                    skip(',');
                }
            }
            إذا (sa)
                tcc_error("too few arguments to function");

            إذا (p) { /* with reverse_funcargs */
                لكل (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    افعل {
                        sa = sa->بل, p2 = p2->prev;
                    } طالما (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), بل();
                    بیان_eq();
                    gfunc_param_typed(s, sa);
                    پای_ټکی_macro();
                }
                vrev(n);
            }

            بل();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_دلیلونه);

            إذا (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#که_تعریف_شوی TCC_موخه_RISCV64
                arch_transfer_ret_regs(1);
#د_که_پای
            } وإلا {
                /* return value */
                n = ret_nregs;
                طالما (n > 1) {
                    صحيح rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    لكل (r = 0; r < NB_REGS; ++r)
                        إذا (reg_classes[r] & rc)
                            اكسر;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                إذا (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    صحيح addr, دننه_واټن;

                    اندازه = type_اندازه(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    اندازه = (اندازه + regsize - 1) & -regsize;
                    إذا (ret_align > align)
                        align = ret_align;
                    loc = (loc - اندازه) & -align;
                    addr = loc;
                    دننه_واټن = 0;
                    لكل (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + دننه_واټن);
                        vswap();
                        vstore();
                        vtop--;
                        إذا (--ret_nregs == 0)
                          اكسر;
                        دننه_واټن += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                إذا (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#که_تعریف_شوی PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#وإلا
                    vtop->type.t = VT_INT;
#د_که_پای
                }
            }
            إذا (s->f.func_noreturn) {
                إذا (debug_modes)
	            tcc_tcov_بلاک_پای_ټکی(tcc_state, -1);
                کوډ_OFF();
	    }
        } وإلا {
            اكسر;
        }
    }
}

#که_نه_تعریف_شوی precedence_parser /* original top-down parser */

ساكن فراغ بیان_prod(فراغ)
{
    صحيح t;

    unary();
    طالما ((t = tok) == '*' || t == '/' || t == '%') {
        بل();
        unary();
        gen_op(t);
    }
}

ساكن فراغ بیان_مجموعه(فراغ)
{
    صحيح t;

    بیان_prod();
    طالما ((t = tok) == '+' || t == '-') {
        بل();
        بیان_prod();
        gen_op(t);
    }
}

ساكن فراغ بیان_ښويدنه(فراغ)
{
    صحيح t;

    بیان_مجموعه();
    طالما ((t = tok) == TOK_SHL || t == TOK_SAR) {
        بل();
        بیان_مجموعه();
        gen_op(t);
    }
}

ساكن فراغ بیان_cmp(فراغ)
{
    صحيح t;

    بیان_ښويدنه();
    طالما (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        بل();
        بیان_ښويدنه();
        gen_op(t);
    }
}

ساكن فراغ بیان_cmpeq(فراغ)
{
    صحيح t;

    بیان_cmp();
    طالما ((t = tok) == TOK_EQ || t == TOK_NE) {
        بل();
        بیان_cmp();
        gen_op(t);
    }
}

ساكن فراغ بیان_and(فراغ)
{
    بیان_cmpeq();
    طالما (tok == '&') {
        بل();
        بیان_cmpeq();
        gen_op('&');
    }
}

ساكن فراغ بیان_xor(فراغ)
{
    بیان_and();
    طالما (tok == '^') {
        بل();
        بیان_and();
        gen_op('^');
    }
}

ساكن فراغ بیان_or(فراغ)
{
    بیان_xor();
    طالما (tok == '|') {
        بل();
        بیان_xor();
        gen_op('|');
    }
}

ساكن فراغ بیان_landor(صحيح op);

ساكن فراغ بیان_land(فراغ)
{
    بیان_or();
    إذا (tok == TOK_LAND)
        بیان_landor(tok);
}

ساكن فراغ بیان_lor(فراغ)
{
    بیان_land();
    إذا (tok == TOK_LOR)
        بیان_landor(tok);
}

# define بیان_landor_بل(op) op == TOK_LAND ? بیان_or() : بیان_land()
#وإلا /* defined precedence_parser */
# define بیان_landor_بل(op) unary(), بیان_infix(precedence(op) + 1)
# define بیان_lor() unary(), بیان_infix(1)

ساكن صحيح precedence(صحيح tok)
{
    بدل (tok) {
        حالة TOK_LOR: أرجع 1;
        حالة TOK_LAND: أرجع 2;
	حالة '|': أرجع 3;
	حالة '^': أرجع 4;
	حالة '&': أرجع 5;
	حالة TOK_EQ: حالة TOK_NE: أرجع 6;
 relat: حالة TOK_ULT: حالة TOK_UGE: أرجع 7;
	حالة TOK_SHL: حالة TOK_SAR: أرجع 8;
	حالة '+': حالة '-': أرجع 9;
	حالة '*': حالة '/': حالة '%': أرجع 10;
	افتراضي:
	    إذا (tok >= TOK_ULE && tok <= TOK_GT)
	        اذهب relat;
	    أرجع 0;
    }
}
ساكن بینښه حرف prec[256];
ساكن فراغ init_prec(فراغ)
{
    صحيح i;
    لكل (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#تعریف_کړه precedence(i) ((بینښه)i < 256 ? prec[i] : 0)

ساكن فراغ بیان_landor(صحيح op);

ساكن فراغ بیان_infix(صحيح p)
{
    صحيح t = tok, p2;
    طالما ((p2 = precedence(t)) >= p) {
        إذا (t == TOK_LOR || t == TOK_LAND) {
            بیان_landor(t);
        } وإلا {
            بل();
            unary();
            إذا (precedence(tok) > p2)
              بیان_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#د_که_پای

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ساكن صحيح condition_3way(فراغ)
{
    صحيح c = -1;
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    أرجع c;
}

ساكن فراغ بیان_landor(صحيح op)
{
    صحيح t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    لكل(;;) {
        c = f ? i : condition_3way();
        إذا (c < 0)
            save_regs(1), cc = 0;
        وإلا إذا (c != i)
            nocode_wanted++, f = 1;
        إذا (tok != op)
            اكسر;
        إذا (c < 0)
            t = gvtst(i, t);
        وإلا
            vpop();
        بل();
        بیان_landor_بل(op);
    }
    إذا (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } وإلا {
        gvtst_سېټ(i, t);
    }
}

ساكن صحيح is_cond_bool(SValue *sv)
{
    إذا ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        أرجع (بینښه)sv->c.i < 2;
    إذا (sv->r == VT_CMP)
        أرجع 1;
    أرجع 0;
}

ساكن فراغ بیان_cond(فراغ)
{
    صحيح tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    بیان_lor();
    إذا (tok == '?') {
        بل();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        إذا (!g) {
            إذا (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } وإلا {
                vpop();
            }
        } وإلا إذا (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        إذا (c == 0)
          nocode_wanted++;
        إذا (!g)
          gexpr();

        إذا ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_اشاره_ګر(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        إذا (g) {
            u = tt;
        } وإلا إذا (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } وإلا
          u = 0;

        إذا (c == 0)
          nocode_wanted--;
        إذا (c == 1)
          nocode_wanted++;
        skip(':');
        بیان_cond();

        إذا ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_اشاره_ګر(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        إذا (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        إذا (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_سېټ(0, t1);
            gvtst_سېټ(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            أرجع;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        إذا (c != 1) {
            gen_cast(&type);
            إذا (islv) {
                mk_اشاره_ګر(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        إذا (USING_TWO_ټکي(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        إذا (c < 0) {
            إذا (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        إذا (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
عملوند*/
        إذا (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            إذا (islv) {
                mk_اشاره_ګر(&vtop->type);
                gaddrof();
            }
        }

        إذا (c < 0) {
            إذا (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        إذا (islv)
          indir();
    }
}

ساكن فراغ بیان_eq(فراغ)
{
    صحيح t;
    
    بیان_cond();
    إذا ((t = tok) == '=' || TOK_ټاکل(t)) {
        test_lvalue();
        بل();
        إذا (t == '=') {
            بیان_eq();
        } وإلا {
            vdup();
            بیان_eq();
            gen_op(TOK_ټاکل_OP(t));
        }
        vstore();
    }
}

ST_FUNC فراغ gexpr(فراغ)
{
    بیان_eq();
    إذا (tok == ',') {
        افعل {
            vpop();
            بل();
            بیان_eq();
        } طالما (tok == ',');

        /* convert array & function to pointer */
        convert_افاده_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        إذا ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            إذا (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ساكن فراغ بیان_const1(فراغ)
{
    nocode_wanted += CONST_WANTED_بټ;
    بیان_cond();
    nocode_wanted -= CONST_WANTED_بټ;
}

/* parse an integer constant and return its value. */
ساكن مضمن int64_t بیان_const64(فراغ)
{
    int64_t c;
    بیان_const1();
    إذا ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    أرجع c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC صحيح بیان_const(فراغ)
{
    صحيح c;
    int64_t wc = بیان_const64();
    c = wc;
    إذا (c != wc && (بینښه)c != wc)
        tcc_error("constant exceeds 32 bit");
    أرجع c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#که_نه_تعریف_شوی TCC_موخه_ARM64
ساكن فراغ gfunc_return(CType *func_type)
{
    إذا ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        صحيح ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        إذا (ret_nregs < 0) {
#که_تعریف_شوی TCC_موخه_RISCV64
            arch_transfer_ret_regs(0);
#د_که_پای
        } وإلا إذا (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_اشاره_ګر(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } وإلا {
            /* returning structure packed into registers */
            صحيح اندازه, addr, align, rc, n;
            اندازه = type_اندازه(func_type,&align);
            إذا (ret_nregs * regsize > اندازه ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		إذا (ret_nregs * regsize > اندازه)
		    اندازه = ret_nregs * regsize;
		إذا (ret_align > align)
		    align = ret_align;
                loc = (loc - اندازه) & -align;
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
            لكل (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_دننه_واټن(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } وإلا {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#د_که_پای

ساكن فراغ check_func_return(فراغ)
{
    إذا ((func_vt.t & VT_BTYPE) == VT_VOID)
        أرجع;
    إذا ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } وإلا {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ساكن صحيح case_cmp(uint64_t a, uint64_t b)
{
    إذا (cur_switch->sv.type.t & VT_UNSIGNED)
        أرجع a < b ? -1 : a > b;
    وإلا
        أرجع (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ساكن صحيح case_cmp_qs(ثابت فراغ *pa, ثابت فراغ *pb)
{
    أرجع case_cmp((*(بنية case_t**)pa)->v1, (*(بنية case_t**)pb)->v1);
}

ساكن فراغ case_ترتیبول(بنية switch_t *sw)
{
    بنية case_t **p;
    إذا (sw->n < 2)
        أرجع;
    qsort(sw->p, sw->n, حجم *sw->p, case_cmp_qs);
    p = sw->p;
    طالما (p < sw->p + sw->n - 1) {
        إذا (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            صحيح l1 = p[0]->کرښه, l2 = p[1]->کرښه;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } وإلا إذا (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * حجم *p);
        } وإلا
            ++p;
    }
}

ساكن صحيح gcase(بنية case_t **بنسټ, صحيح len, صحيح dsym)
{
    بنية case_t *p;
    صحيح t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    إذا (t != VT_LLONG)
        t = VT_INT;
    طالما (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = بنسټ[l2];
        vdup(), vpush64(t, p->v2);
        إذا (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } وإلا {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            إذا (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            وإلا
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(بنسټ, l2, dsym);
            gsym(e);
        }
        ++l2, بنسټ += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    أرجع gjmp(dsym);
}

ساكن فراغ پای_ټکی_switch(فراغ)
{
    بنية switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ساكن فراغ save_lvalues(فراغ)
{
    SValue *sv = vtop;
    طالما (sv >= vstack) {
        إذا (sv->sym && (sv->r & VT_LVAL)) {
            صحيح align, اندازه = type_اندازه(&sv->type, &align);
            صحيح r2, l = get_لنډمهاله_local_var(اندازه, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ساكن فراغ try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    لكل (; cls != stop; cls = cls->بل) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_اشاره_ګر(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


ساكن فراغ try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    صحيح ocd, ccd;

    إذا (!cur_scope->cl.s)
	أرجع;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_ډګر : 0;
    لكل (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->بل)
      ;
    لكل (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->بل)
      ;
    لكل (; cc != oc; cc = cc->بل, oc = oc->بل, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ساكن فراغ بلاک_cleanup(بنية scope *o)
{
    صحيح jmp = 0;
    Sym *g, **pg;
    لكل (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        إذا (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->بل;
            إذا (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            إذا (!o->cl.n)
                اذهب remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } وإلا {
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

ساكن فراغ vla_restore(صحيح loc)
{
    إذا (loc)
        gen_vla_sp_restore(loc);
}

ساكن فراغ vla_leave(بنية scope *o)
{
    بنية scope *c = cur_scope, *v = عدم;
    لكل (; c != o && c; c = c->prev)
      إذا (c->vla.عدد)
        v = c;
    إذا (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ساكن فراغ new_scope(بنية scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.عدد = 0;

    /* record local declaration stack position */
    o->lstk = local_ډېری;
    o->llstk = local_label_ډېری;
    ++local_scope;
}

ساكن فراغ prev_scope(بنية scope *o, صحيح is_بیان)
{
    vla_leave(o->prev);

    إذا (o->cl.s != o->prev->cl.s)
        بلاک_cleanup(o->prev);

    إذا (debug_modes)
        tcc_debug_پای_ټکی_scope(o->lstk, !is_بیان);

    /* pop locally defined labels */
    label_راوباسه(&local_label_ډېری, o->llstk, is_بیان);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_راوباسه(&local_ډېری, o->lstk, is_بیان);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ساكن فراغ leave_scope(بنية scope *o)
{
    إذا (!o)
        أرجع;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ساكن فراغ new_scope_s(بنية scope *o)
{
    o->lstk = local_ډېری;
    ++local_scope;
}

ساكن فراغ prev_scope_s(بنية scope *o)
{
    sym_راوباسه(&local_ډېری, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ساكن فراغ lblock(صحيح *bsym, صحيح *csym)
{
    بنية scope *lo = loop_scope, *co = cur_scope;
    صحيح *b = co->bsym, *c = co->csym;
    إذا (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    بلاک(0);
    co->bsym = b;
    إذا (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ساكن فراغ gexpr_decl(فراغ)
{
    صحيح v = decl(VT_JMP);
    إذا (v > 1 && tok != ';') {
        Sym *s = sym_پیدا_کړه(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } وإلا {
        إذا (v)
            skip(';');
        gexpr();
    }
}

ساكن فراغ بلاک(صحيح flags)
{
    صحيح a, b, c, d, e, t;
    بنية scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    إذا (TOK_HAS_ارزښت(t))
        اذهب بیان;
    بل();

    إذا (debug_modes)
        tcc_tcov_check_کرښه (tcc_state, 0), tcc_tcov_بلاک_begin (tcc_state);

    إذا (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        بلاک(0);
        إذا (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            بل();
            بلاک(0);
            gsym(d); /* patch else jmp */
        } وإلا {
            gsym(a);
        }
        prev_scope_s(&o);

    } وإلا إذا (t == TOK_WHILE) {
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

    } وإلا إذا (t == '{') {
        إذا (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        طالما (tok == TOK_LABEL) {
            افعل {
                بل();
                إذا (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ټېل(&local_label_ډېری, tok, LABEL_DECLARED);
                بل();
            } طالما (tok == ',');
            skip(';');
        }

        طالما (tok != '}') {
	    decl(VT_LOCAL);
            إذا (tok != '}') {
                بلاک(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_بیان);
        إذا (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        إذا (local_scope)
            بل();
        وإلا إذا (!nocode_wanted)
            check_func_return();

    } وإلا إذا (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        إذا (tok != ';') {
            gexpr();
            إذا (b) {
                gen_ټاکل_cast(&func_vt);
            } وإلا {
                إذا (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } وإلا إذا (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } وإلا إذا (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ریښه_scope);
        إذا (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        إذا (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        إذا (debug_modes)
	    tcc_tcov_بلاک_پای_ټکی (tcc_state, -1);
        کوډ_OFF();

    } وإلا إذا (t == TOK_BREAK) {
        /* compute jump */
        إذا (!cur_scope->bsym)
            tcc_error("cannot break");
        إذا (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        وإلا
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } وإلا إذا (t == TOK_CONTINUE) {
        /* compute jump */
        إذا (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } وإلا إذا (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        إذا (tok != ';') {
            /* c99 for-loop init decl? */
            إذا (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        إذا (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        إذا (tok != ')') {
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

    } وإلا إذا (t == TOK_DO) {
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

    } وإلا إذا (t == TOK_SWITCH) {
        بنية switch_t *sw;

        sw = tcc_mallocz(حجم *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        إذا (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, عدم);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        إذا (sw->nocode_wanted)
            اذهب skip_switch;
        case_ترتیبول(sw);
        sw->bsym = عدم; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        إذا (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        وإلا
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        پای_ټکی_switch();

    } وإلا إذا (t == TOK_CASE) {
        بنية case_t *cr;
        إذا (!cur_switch)
            expect("switch");
        cr = tcc_malloc(حجم(بنية case_t));
        dynarray_جمع_کړه(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(بیان_const64(), t);
        إذا (tok == TOK_DOTS && gnu_ext) {
            بل();
            cr->v2 = value64(بیان_const64(), t);
            إذا (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        إذا (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->کرښه = file->کرښه_عدد;
        skip(':');
        اذهب بلاک_after_label;

    } وإلا إذا (t == TOK_DEFAULT) {
        إذا (!cur_switch)
            expect("switch");
        إذا (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        اذهب بلاک_after_label;

    } وإلا إذا (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        إذا (tok == '*' && gnu_ext) {
            /* computed goto */
            بل();
            gexpr();
            إذا ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } وإلا إذا (tok >= TOK_UIDENT) {
	    s = label_پیدا_کړه(tok);
	    /* put forward definition if needed */
            إذا (!s)
              s = label_ټېل(&global_label_ډېری, tok, LABEL_FORWARD);
            وإلا إذا (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    إذا (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		إذا (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_ډګر, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->بل, SYM_ډګر, 0, 0);
                    pending_gotos->بل = s;
                }
		s->jnext = gjmp(s->jnext);
	    } وإلا {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    بل();

        } وإلا {
            expect("label identifier");
        }
        skip(';');

    } وإلا إذا (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } وإلا {
        إذا (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    بل();
            s = label_پیدا_کړه(t);
            إذا (s) {
                إذا (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, عدم));
                s->r = LABEL_DEFINED;
		إذا (s->بل) {
		    Sym *pcl; /* pending cleanup goto */
		    لكل (pcl = s->بل; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_راوباسه(&s->بل, عدم, 0);
		} وإلا
		  gsym(s->jnext);
            } وإلا {
                s = label_ټېل(&global_label_ډېری, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    بلاک_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(عدم);

            إذا (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            إذا (tok != '}') {
                إذا (0 == (flags & STMT_COMPOUND))
                    اذهب again;
                /* C23: insert implicit null-statement whithin compound statement */
            } وإلا {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } وإلا {
            /* expression case */
            إذا (t != ';') {
                unget_tok(t);
    بیان:
                إذا (flags & STMT_بیان) {
                    vpop();
                    gexpr();
                } وإلا {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    إذا (debug_modes)
        tcc_tcov_check_کرښه (tcc_state, 0), tcc_tcov_بلاک_پای_ټکی (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ساكن فراغ skip_or_save_بلاک(TokenString **str)
{
    صحيح braces = tok == '{';
    صحيح level = 0;
    إذا (str)
      *str = tok_str_alloc();

    طالما (1) {
	صحيح t = tok;
        إذا (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             اكسر;
	إذا (t == TOK_EOF) {
	     إذا (str || level > 0)
	       tcc_error("unexpected end of file");
	     وإلا
	       اكسر;
	}
	إذا (str)
	  tok_str_جمع_کړه_tok(*str);
	بل();
	إذا (t == '{' || t == '(' || t == '[') {
	    level++;
	} وإلا إذا (t == '}' || t == ')' || t == ']') {
	    level--;
	    إذا (level == 0 && braces && t == '}')
	      اكسر;
	}
    }
    إذا (str)
	tok_str_جمع_کړه(*str, TOK_EOF);
}

#تعریف_کړه بیان_CONST 1
#تعریف_کړه بیان_ANY   2

ساكن فراغ parse_init_elem(صحيح بیان_type)
{
    صحيح saved_global_بیان;
    بدل(بیان_type) {
    حالة بیان_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_بیان = global_بیان;
        global_بیان = 1;
        بیان_const1();
        global_بیان = saved_global_بیان;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        إذا (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_لومړی_ANOM))
#که_تعریف_شوی TCC_موخه_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#د_که_پای
           )
            tcc_error("initializer element is not constant");
        اكسر;
    حالة بیان_ANY:
        بیان_eq();
        اكسر;
    }
}

#إذا 1
ساكن فراغ init_assert(init_params *p, صحيح دننه_واټن)
{
    إذا (p->sec ? !NODATA_WANTED && دننه_واټن > p->sec->معلومات_دننه_واټن
               : !nocode_wanted && دننه_واټن > p->local_دننه_واټن)
        tcc_دننی_error("initializer overflow");
}
#وإلا
#تعریف_کړه init_assert(sec, دننه_واټن)
#د_که_پای

/* put zeros for variable based init */
ساكن فراغ init_putz(init_params *p, بینښه اوږد c, صحيح اندازه)
{
    init_assert(p, c + اندازه);
    إذا (p->sec) {
        /* nothing to do because globals are already set to zero */
    } وإلا {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(اندازه);
#إذا defined TCC_موخه_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#د_که_پای
        gfunc_call(3);
    }
}

#تعریف_کړه DIF_لومړی     1
#تعریف_کړه DIF_اندازه_ONLY 2
#تعریف_کړه DIF_HAVE_ELEM 4
#تعریف_کړه DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
ساكن فراغ decl_design_delrels(Section *sec, صحيح c, صحيح اندازه)
{
    ElfW_Rel *rel, *rel2, *rel_پای_ټکی;
    إذا (!sec || !sec->reloc)
        أرجع;
    rel = rel2 = (ElfW_Rel*)sec->reloc->معلومات;
    rel_پای_ټکی = (ElfW_Rel*)(sec->reloc->معلومات + sec->reloc->معلومات_دننه_واټن);
    طالما (rel < rel_پای_ټکی) {
        إذا (rel->r_دننه_واټن >= c && rel->r_دننه_واټن < c + اندازه) {
            sec->reloc->معلومات_دننه_واټن -= حجم *rel;
        } وإلا {
            إذا (rel2 != rel)
                حافظه_نقل(rel2, rel, حجم *rel);
            ++rel2;
        }
        ++rel;
    }
}

ساكن فراغ decl_design_flex(init_params *p, Sym *ref, صحيح شاخص)
{
    إذا (ref == p->flex_array_ref) {
        إذا (شاخص >= ref->c)
            ref->c = شاخص + 1;
    } وإلا إذا (ref->c < 0 && شاخص >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ساكن صحيح decl_designator(init_params *p, CType *type, بینښه اوږد c,
                           Sym **cur_ډګر, صحيح flags, صحيح al)
{
    Sym *s, *f;
    صحيح شاخص, شاخص_وروستی, align, l, nb_elems, elem_اندازه;
    بینښه اوږد corig = c;

    elem_اندازه = 0;
    nb_elems = 1;

    إذا (flags & DIF_HAVE_ELEM)
        اذهب no_designator;

    إذا (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, بل();
        إذا (tok == ':')
            اذهب struct_ډګر;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    طالما (nb_elems == 1 && (tok == '[' || tok == '.')) {
        إذا (tok == '[') {
            إذا (!(type->t & VT_ARRAY))
                expect("array type");
            بل();
            شاخص = شاخص_وروستی = بیان_const();
            إذا (tok == TOK_DOTS && gnu_ext) {
                بل();
                شاخص_وروستی = بیان_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, شاخص_وروستی);
            إذا (شاخص < 0 || شاخص_وروستی >= s->c || شاخص_وروستی < شاخص)
	        tcc_error("index exceeds array bounds or range is empty");
            إذا (cur_ډګر)
		(*cur_ډګر)->c = شاخص_وروستی;
            type = pointed_type(type);
            elem_اندازه = type_اندازه(type, &align);
            c += شاخص * elem_اندازه;
            nb_elems = شاخص_وروستی - شاخص + 1;
        } وإلا {
            صحيح cumofs;
            بل();
            l = tok;
        struct_ډګر:
            بل();
	    f = پیدا_کړه_ډګر(type, l, &cumofs);
            إذا (cur_ډګر)
                *cur_ډګر = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_ډګر = عدم;
    }
    إذا (!cur_ډګر) {
        إذا (tok == '=') {
            بل();
        } وإلا إذا (!gnu_ext) {
	    expect("=");
        }
    } وإلا {
    no_designator:
        إذا (type->t & VT_ARRAY) {
	    شاخص = (*cur_ډګر)->c;
            s = type->ref;
            decl_design_flex(p, s, شاخص);
            إذا (شاخص >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_اندازه = type_اندازه(type, &align);
            c += شاخص * elem_اندازه;
        } وإلا {
            f = *cur_ډګر;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    طالما (f && (f->v & SYM_لومړی_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_ډګر = f = f->بل;
            إذا (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    إذا (!elem_اندازه) /* for structs */
        elem_اندازه = type_اندازه(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    إذا (!(flags & DIF_اندازه_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_اندازه * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_لومړی);

    إذا (!(flags & DIF_اندازه_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        صحيح i;
        إذا (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_اندازه;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        إذا (p->sec)
            vpush_ref(type, p->sec, c, elem_اندازه);
        وإلا
	    vset(type, VT_LOCAL|VT_LVAL, c);
        لكل (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_اندازه * i);
	}
        vpop();
    }

    c += nb_elems * elem_اندازه;
    إذا (c - corig > al)
      al = c - corig;
    أرجع al;
}

ساكن فراغ write_ldouble(بینښه حرف *d, فراغ *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#که_تعریف_شوی TCC_CROSS_TEST
    إذا (LDOUBLE_اندازه >= 10) {
        مزدوج b = *(اوږد مزدوج*)s;
        s = &b;
#وإلا
    إذا (حجم (اوږد مزدوج) == 8 && LDOUBLE_اندازه >= 10) {
#د_که_پای
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        صحيح e = m >> 48;
        صحيح f = e >> 4 & 0x7FF;
        m <<= 11;
        إذا (0 == f) {
            إذا (0 == m)
                اذهب سېټ;
            لكل (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        إذا (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    سېټ:
    #إذا (defined TCC_موخه_I386 || defined TCC_موخه_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #وإلاإذا LDOUBLE_اندازه == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #د_که_پای
        ;
    } وإلا {
    #إذا LDOUBLE_اندازه == 8
        /* long double -> double */
        مزدوج b = *(اوږد مزدوج*)s;
        حافظه_نقل(d, &b, 8);
    #وإلاإذا (__i386__ || __x86_64__) && (defined TCC_موخه_I386 || defined TCC_موخه_X86_64)
        /* extended -> extended */
        حافظه_نقل(d, s, 10);
    #وإلاإذا (__i386__ || __x86_64__) && (defined TCC_موخه_ARM64 || defined TCC_موخه_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        صحيح e = *(uint16_t*)((حرف*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #وإلاإذا (__aarch64__ || __riscv) && (defined TCC_موخه_I386 || defined TCC_موخه_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((حرف*)s + 6);
        صحيح e = read16le((حرف*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #وإلا
        /* unknown */
        إذا (حجم (اوږد مزدوج) == LDOUBLE_اندازه)
            حافظه_نقل(d, s, LDOUBLE_اندازه);
    #د_که_پای
    }
}

/* store a value or an expression directly in global data or in local array */
ساكن فراغ init_putv(init_params *p, CType *type, بینښه اوږد c)
{
    صحيح bt;
    فراغ *ptr;
    CType dtype;
    صحيح اندازه, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    اندازه = type_اندازه(type, &align);
    إذا (type->t & VT_BITFIELD)
        اندازه = (بټ_POS(type->t) + بټ_اندازه(type->t) + 7) / 8;
    init_assert(p, c + اندازه);

    إذا (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_ټاکل_cast(&dtype);
        bt = type->t & VT_BTYPE;

        إذا ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_اندازه == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_لومړی_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        إذا (NODATA_WANTED) {
            vtop--;
            أرجع;
        }

        ptr = sec->معلومات + c;
        val = vtop->c.i;

	إذا ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_لومړی_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->معلومات + esym->st_ارزښت + (صحيح)vtop->c.i, اندازه);
	    إذا (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                بینښه اوږد relofs = ssec->reloc->معلومات_دننه_واټن;
		طالما (relofs >= حجم(*rel)) {
                    relofs -= حجم(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->معلومات + relofs);
		    إذا (rel->r_دننه_واټن >= esym->st_ارزښت + اندازه)
		      استمر;
		    إذا (rel->r_دننه_واټن < esym->st_ارزښت)
		      اكسر;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_دننه_واټن - esym->st_ارزښت,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#إذا PTR_اندازه == 8
				   rel->r_addend
#وإلا
				   0
#د_که_پای
				  );
		}
	    }
	} وإلا {
            إذا (type->t & VT_BITFIELD) {
                صحيح بټ_pos, بټ_اندازه_2, بټونه, n;
                بینښه حرف *p, v, m;
                بټ_pos = بټ_POS(vtop->type.t);
                بټ_اندازه_2 = بټ_اندازه(vtop->type.t);
                p = (بینښه حرف*)ptr + (بټ_pos >> 3);
                بټ_pos &= 7, بټونه = 0;
                طالما (بټ_اندازه_2) {
                    n = 8 - بټ_pos;
                    إذا (n > بټ_اندازه_2)
                        n = بټ_اندازه_2;
                    v = val >> بټونه << بټ_pos;
                    m = ((1 << n) - 1) << بټ_pos;
                    *p = (*p & ~m) | (v & m);
                    بټونه += n, بټ_اندازه_2 -= n, بټ_pos = 0, ++p;
                }
            } وإلا
            بدل(bt) {
	    حالة VT_BOOL:
		*(حرف *)ptr = val != 0;
                اكسر;
	    حالة VT_BYTE:
		*(حرف *)ptr = val;
		اكسر;
	    حالة VT_SHORT:
                write16le(ptr, val);
		اكسر;
	    حالة VT_FLOAT:
                write32le(ptr, val);
		اكسر;
	    حالة VT_DOUBLE:
                write64le(ptr, val);
		اكسر;
	    حالة VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		اكسر;

#إذا PTR_اندازه == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    حالة VT_LLONG:
	    حالة VT_PTR:
	        إذا (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_معلومات_PTR, val);
	        وإلا
	          write64le(ptr, val);
	        اكسر;
            حالة VT_INT:
                write32le(ptr, val);
                اكسر;
#وإلا
	    حالة VT_LLONG:
                write64le(ptr, val);
                اكسر;
            حالة VT_PTR:
            حالة VT_INT:
	        إذا (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_معلومات_PTR);
	        write32le(ptr, val);
	        اكسر;
#د_که_پای
	    افتراضي:
                //tcc_internal_error("unexpected type");
                اكسر;
	    }
	}
        vtop--;
    } وإلا {
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
ساكن فراغ decl_initializer(init_params *p, CType *type, بینښه اوږد c, صحيح flags)
{
    صحيح len, n, no_oblock, i;
    صحيح size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    إذا (debug_modes && !(flags & DIF_اندازه_ONLY) && !p->sec)
        tcc_debug_کرښه(tcc_state), tcc_tcov_check_کرښه (tcc_state, 1);

    إذا (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_اندازه_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        صحيح ncw_prev = nocode_wanted;
        إذا ((flags & DIF_اندازه_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? بیان_ANY : بیان_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    إذا (type->t & VT_ARRAY) {
        no_oblock = 1;
        إذا (((flags & DIF_لومړی) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_اندازه(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        إذا ((tok == TOK_LSTR && 
#که_تعریف_شوی TCC_موخه_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#وإلا
             (t1->t & VT_BTYPE) == VT_INT
#د_که_پای
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            إذا (size1 != (tok == TOK_STR ? 1 : حجم(nwchar_t)))
              tcc_error("unhandled string literal merging");
            طالما (tok == TOK_STR || tok == TOK_LSTR) {
                إذا (initstr.اندازه)
                  initstr.اندازه -= size1;
                إذا (tok == TOK_STR)
                  len += tokc.str.اندازه;
                وإلا
                  len += tokc.str.اندازه / حجم(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.معلومات, tokc.str.اندازه);
                بل();
            }
            إذا (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.اندازه = initstr.اندازه;
                tokc.str.معلومات = initstr.معلومات;
                اذهب do_init_array;
            }

            decl_design_flex(p, s, len);
            إذا (!(flags & DIF_اندازه_ONLY)) {
                صحيح nb = n, ch;
                إذا (len < nb)
                    nb = len;
                إذا (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                إذا (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    إذا (!NODATA_WANTED)
                      حافظه_نقل(p->sec->معلومات + c, initstr.معلومات, nb);
                } وإلا {
                    لكل(i=0;i<n;i++) {
                        إذا (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          إذا (flags & DIF_CLEAR)
                            اكسر;
                          إذا (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            اكسر;
                          }
                          ch = 0;
                        } وإلا إذا (size1 == 1)
                          ch = ((بینښه حرف *)initstr.معلومات)[i];
                        وإلا
                          ch = ((nwchar_t *)initstr.معلومات)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            إذا (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                بل();
        } وإلا {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            إذا (!(flags & (DIF_CLEAR | DIF_اندازه_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    طالما (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		إذا (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    إذا (no_oblock && len >= n*size1)
		        اكسر;
		} وإلا {
		    إذا (s->type.t == VT_UNION)
		        f = عدم;
		    وإلا
		        f = f->بل;
		    إذا (no_oblock && f == عدم)
		        اكسر;
		}

		إذا (tok == '}')
		    اكسر;
		skip(',');
	    }
        }
        إذا (!no_oblock)
            skip('}');

    } وإلا إذا ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        اذهب one_elem;

    } وإلا إذا ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        إذا ((flags & DIF_لومړی) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->بل;
        n = s->c;
        size1 = 1;
	اذهب do_init_list;

    } وإلا إذا (tok == '{') {
        إذا (flags & DIF_HAVE_ELEM)
          skip(';');
        بل();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } وإلا one_elem: إذا ((flags & DIF_اندازه_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        إذا (flags & DIF_HAVE_ELEM)
            vpop();
        وإلا
            skip_or_save_بلاک(عدم);

    } وإلا {
	إذا (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    إذا (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? بیان_ANY : بیان_CONST);
	}
        إذا (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_اندازه(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        وإلا
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
ساكن فراغ decl_initializer_alloc(CType *type, AttributeDef *ad, صحيح r, 
                                   صحيح has_init, صحيح v, صحيح scope)
{
    صحيح اندازه, align, addr;
    TokenString *init_str = عدم;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = عدم;
    صحيح saved_nocode_wanted = nocode_wanted;
#که_تعریف_شوی CONFIG_TCC_BCHECK
    صحيح bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#د_که_پای
    init_params p = {0};

    إذا (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_پیدا_کړه(v);
        إذا (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            إذا (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                أرجع;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    إذا (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= معلومات_ONLY_WANTED;

    flexible_array = عدم;
    اندازه = type_اندازه(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    إذا (اندازه < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        إذا (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        إذا (IS_BT_ARRAY(type->t))
            type->ref = sym_ټېل(SYM_ډګر, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } وإلا إذا (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *ډګر = type->ref->بل;
        إذا (ډګر) {
            طالما (ډګر->بل)
                ډګر = ډګر->بل;
            إذا (ډګر->type.t & VT_ARRAY && ډګر->type.ref->c < 0) {
                flexible_array = ډګر;
                p.flex_array_ref = ډګر->type.ref;
                اندازه = -1;
            }
        }
    }

    إذا (اندازه < 0) {
        /* If unknown size, do a dry-run 1st pass */
        إذا (!has_init)
            اذهب err_اندازه;
        إذا (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            طالما (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_جمع_کړه_tok(init_str);
                بل();
            }
            tok_str_جمع_کړه(init_str, TOK_EOF);
        } وإلا
            skip_or_save_بلاک(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        بل();
        decl_initializer(&p, type, 0, DIF_لومړی | DIF_اندازه_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        بل();

        /* if still unknown size, error */
        اندازه = type_اندازه(type, &align);
        إذا (اندازه < 0)
    err_اندازه:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        إذا (flexible_array && flexible_array->type.ref->c > 0)
            اندازه += flexible_array->type.ref->c
                    * pointed_اندازه(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    إذا (ad->a.aligned) {
	صحيح speca = 1 << (ad->a.aligned - 1);
        إذا (speca > align)
            align = speca;
    } وإلا إذا (ad->a.packed) {
        align = 1;
    }

    إذا (!v && NODATA_WANTED)
        اندازه = 0, align = 1;

    إذا ((r & VT_VALMASK) == VT_LOCAL) {
        sec = عدم;
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#د_که_پای
        loc = (loc - اندازه) & -align;
        addr = loc;
        p.local_دننه_واټن = addr + اندازه;
#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#د_که_پای
        إذا (v) {
            /* local variable */
#که_تعریف_شوی CONFIG_TCC_ASM
	    إذا (ad->asm_label) {
		صحيح reg = asm_parse_regvar(ad->asm_label);
		إذا (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#د_که_پای
            sym = sym_ټېل(v, type, r, addr);
	    إذا (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_ډګر | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->بل = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } وإلا {
            /* push local reference */
            vset(type, r, addr);
        }
    } وإلا {
        CType *tp = type;
        صحيح is_const;

        طالما ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        إذا (!sec) {
            إذا (type->t & VT_TLS) {
                sec = پیدا_کړه_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } وإلا إذا (is_const) {
		sec = rodata_section;
            } وإلا إذا (has_init) {
		sec = معلومات_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } وإلا إذا (tcc_state->nocommon)
                sec = bss_section;
        } وإلا إذا (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            إذا (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                إذا (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#که_تعریف_شوی CONFIG_TCC_BCHECK
        إذا (bcheck)
            اندازه = اندازه + 1; /* add padding */
#د_که_پای
        إذا (sec) {
	    addr = section_جمع_کړه(sec, اندازه, align);
        } وإلا {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        إذا (v) {
            إذا (!sym) {
                sym = sym_ټېل(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, عدم);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, اندازه);
        } وإلا {
            /* push global reference */
            vpush_ref(type, sec, addr, اندازه);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#که_تعریف_شوی CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        إذا (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->معلومات_دننه_واټن, R_معلومات_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_جمع_کړه(bounds_section, 2 * حجم(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = اندازه - 1;
        }
#د_که_پای
    }

    إذا (type->t & VT_VLA) {
        صحيح a;

        إذا (has_init)
            tcc_error("variable length array cannot be initialized");

        إذا (NODATA_WANTED)
            اذهب no_alloc;

        /* save before-VLA stack pointer if needed */
        إذا (cur_scope->vla.عدد == 0) {
            إذا (cur_scope->prev && cur_scope->prev->vla.عدد) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } وإلا {
                gen_vla_sp_save(loc -= PTR_اندازه);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_اندازه(type, &a);
        gen_vla_alloc(type, a);
#إذا defined TCC_موخه_PE && defined TCC_موخه_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_پایله(addr), addr = (loc -= PTR_اندازه);
#د_که_پای
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.عدد++;
    } وإلا إذا (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_لومړی);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        إذا (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    إذا (init_str) {
        پای_ټکی_macro();
        بل();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ساكن فراغ func_vla_arg_کوډ(Sym *arg)
{
    صحيح align;
    TokenString *vla_array_tok = عدم;

    إذا (arg->type.ref)
        func_vla_arg_کوډ(arg->type.ref);

    إذا ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_اندازه(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	بل();
	gexpr();
	پای_ټکی_macro();
	بل();
	vpush_type_اندازه(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

ساكن فراغ func_vla_arg(Sym *sym)
{
    Sym *arg;

    لكل (arg = sym->type.ref->بل; arg; arg = arg->بل)
        إذا ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_کوډ(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_سېټ_param(Sym *s, صحيح c, صحيح byref)
{
    s = sym_پیدا_کړه(s->v);
    إذا (!s) /* unnamed parameters, not enabled */
        أرجع عدم;
    s->c = c;
    إذا (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    أرجع s;
}

/* push parameters (and their types), last first */
ساكن فراغ sym_ټېل_params(Sym *ref)
{
    Sym *s = ref;
    طالما (s->بل)
        s = s->بل;
    طالما (s != ref) {
        إذا ((s->v & ~SYM_STRUCT) < SYM_لومړی_ANOM)
            sym_copy(s, &local_ډېری);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ساكن فراغ gen_function(Sym *sym)
{
    بنية scope f = { 0 };

    cur_scope = ریښه_scope = &f;
    nocode_wanted = 0;

    ind = cur_متن_section->معلومات_دننه_واټن;
    إذا (sym->a.aligned) {
	اندازه_t newoff = section_جمع_کړه(cur_متن_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, عدم);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_متن_section, ind, 0);

    إذا (sym->type.ref->f.func_ctor)
        جمع_کړه_array (tcc_state, ".init_array", sym->c);
    إذا (sym->type.ref->f.func_dtor)
        جمع_کړه_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ډېری, SYM_ډګر, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ټېل_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_لنډمهاله_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    بلاک(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_پای_ټکی_scope(عدم, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_اندازه = ind - func_ind;
    cur_متن_section->معلومات_دننه_واټن = ind;

    sym_راوباسه(&local_ډېری, عدم, 0);
    label_راوباسه(&global_label_ډېری, عدم, 0);
    sym_راوباسه(&all_cleanups, عدم, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_متن_section = عدم;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = معلومات_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    بل();
}

ساكن فراغ gen_inline_functions(TCCState *s)
{
    Sym *sym;
    صحيح inline_generated, i;
    بنية InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    افعل {
        inline_generated = 0;
        لكل (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            إذا (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = عدم;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                بل();
                cur_متن_section = متن_section;
                gen_function(sym);
                پای_ټکی_macro();

                inline_generated = 1;
            }
        }
    } طالما (inline_generated);
    tcc_close();
}

ساكن فراغ free_inline_functions(TCCState *s)
{
    صحيح i;
    /* free tokens of unused inline functions */
    لكل (i = 0; i < s->nb_inline_fns; ++i) {
        بنية InlineFunc *fn = s->inline_fns[i];
        إذا (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ساكن فراغ do_Static_assert(فراغ)
{
    صحيح c;
    ثابت حرف *پیغام;

    بل();
    skip('(');
    c = بیان_const();
    پیغام = "_Static_assert fail";
    إذا (tok == ',') {
        بل();
        پیغام = parse_mult_str("string constant")->معلومات;
    }
    skip(')');
    إذا (c == 0)
        tcc_error("%s", پیغام);
    skip(';');
}

#که_تعریف_شوی TCC_موخه_PE
ساكن فراغ pe_check_linkage(CType *type, AttributeDef *ad)
{
    إذا (!ad->a.dllimport && !ad->a.dllexport)
        أرجع;
    إذا (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    إذا (type->t & VT_TYPEDEF) {
        ثابت حرف *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } وإلا إذا (ad->a.dllimport) {
        إذا ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        وإلا
            type->t |= VT_EXTERN;
    }
}
#د_که_پای

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ساكن صحيح decl(صحيح l)
{
    صحيح v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    طالما (1) {

        oldint = 0;
        إذا (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            إذا (l == VT_JMP)
                أرجع 0;
            /* skip redundant ';' if not in old parameter decl scope */
            إذا (tok == ';' && l != VT_CMP) {
                بل();
                استمر;
            }
            إذا (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                استمر;
            }
            إذا (l != VT_CONST)
                اكسر;
            إذا (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                استمر;
            }
            إذا (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } وإلا {
                إذا (tok != TOK_EOF)
                    expect("declaration");
                اكسر;
            }
        }

        إذا (tok == ';') {
            إذا ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_لومړی_ANOM)
                ; /* struct decl with named tag */
            وإلا إذا (IS_ENUM(btype.t))
                ; /* enum decl */
            وإلا
                tcc_warning("useless type defines no instances");
            إذا (l == VT_JMP)
                أرجع 1;
            بل();
            استمر;
        }

        طالما (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_مستقیم | TYPE_PARAM : TYPE_مستقیم);
            /*ptype("decl", &type, v);*/
            إذا ((type.t & VT_BTYPE) == VT_FUNC) {
                إذا ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                إذا (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                إذا ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    إذا (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    وإلا
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } وإلا إذا (oldint) {
                tcc_warning("type defaults to int");
            }

            إذا (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #إذا 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                إذا (tok == '{')
                    expect(";");
            #د_که_پای
            }

#که_تعریف_شوی TCC_موخه_PE
            pe_check_linkage(&type, &ad);
#د_که_پای
            إذا (tok == '{') {
                إذا (l != VT_CONST)
                    tcc_error("cannot use local functions");
                إذا ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                یوځای_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                لكل (sa = sym->type.ref; (sa = sa->بل) != عدم;) {
                    إذا (!(sa->v & ~SYM_ډګر))
                        expect("identifier");
                    إذا (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                إذا (sym->type.t & VT_INLINE) {
                    بنية InlineFunc *fn;
                    fn = tcc_malloc(حجم *fn + مزي_اوږدوالی(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_جمع_کړه(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_بلاک(&fn->func_str);
                } وإلا {
                    /* compute text section */
                    cur_متن_section = متن_section;
                    إذا (ad.section) {
                        cur_متن_section = ad.section;
                        إذا (ad.new_section)
                            ad.section->sh_flags = متن_section->sh_flags;
                    }
                    gen_function(sym);
                }
                اكسر;
            } وإلا {
                has_init = 0;
		إذا (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    لكل (sym = func_vt.ref->بل; sym; sym = sym->بل)
			إذا ((sym->v & ~SYM_ډګر) == v)
			    اذهب وموندل;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, عدم));
                وموندل:
		    إذا (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, عدم));
		    إذا (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, عدم));
		    convert_parameter_type(&type);
		    sym->type = type;
		} وإلا إذا (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_پیدا_کړه(v);
                    إذا (sym && sym->sym_scope == local_scope) {
                        إذا (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, عدم));
                        sym->type = type;
                    } وإلا {
                        sym = sym_ټېل(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    إذا ((type.t & VT_BTYPE) == VT_FUNC)
                      یوځای_funcattr(&sym->type.ref->f, &ad.f);
                    إذا (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} وإلا إذا ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } وإلا {
                    r = 0;
                    إذا ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        یوځای_funcattr(&type.ref->f, &ad.f);
                    } وإلا إذا (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    إذا (tok == '=')
                        has_init = 1;

                    إذا (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } وإلا {
                        إذا (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        وإلا
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        إذا (has_init)
                            بل();
                        وإلا إذا (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    إذا (ad.alias_موخه && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_پیدا_کړه(ad.alias_موخه));
                        إذا (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_پیدا_کړه(v), esym->st_shndx,
                                        esym->st_ارزښت, esym->st_اندازه, 1);
                    }
                }
                إذا (tok != ',') {
                    إذا (l == VT_JMP)
                        أرجع has_init ? v : 1;
                    skip(';');
                    اكسر;
                }
                بل();
            }
        }
    }
    أرجع 0;
}

/* ------------------------------------------------------------------------- */
#تعریف_لغوه gjmp_addr
#تعریف_لغوه gjmp
/* ------------------------------------------------------------------------- */
