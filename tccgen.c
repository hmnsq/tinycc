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

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_ڈیٹا صحیح rsym, anon_sym, ind, loc;

ST_ڈیٹا Sym *global_ڈھیر;
ST_ڈیٹا Sym *local_ڈھیر;
ST_ڈیٹا Sym *define_ڈھیر;
ST_ڈیٹا Sym *global_label_ڈھیر;
ST_ڈیٹا Sym *local_label_ڈھیر;

ساکن Sym *sym_free_پہلا;
ساکن خالی **sym_pools;
ساکن صحیح nb_sym_pools;

ساکن Sym *all_cleanups, *pending_gotos;
ساکن صحیح local_scope;
ST_ڈیٹا حرف debug_modes;

ST_ڈیٹا SValue *vtop;
ساکن SValue _vstack[1 + VSTACK_سائز];
#تعریف_کرو vstack (_vstack + 1)

ST_ڈیٹا صحیح nocode_wanted; /* no code generation wanted */
#تعریف_کرو NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#تعریف_کرو ڈیٹا_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#تعریف_کرو رمز_OFF_ثنائی_ہندسہ 0x20000000
#تعریف_کرو رمز_OFF() اگر(!nocode_wanted)(nocode_wanted |= رمز_OFF_ثنائی_ہندسہ)
#تعریف_کرو رمز_ON() (nocode_wanted &= ~رمز_OFF_ثنائی_ہندسہ)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#تعریف_کرو NOEVAL_نقاب 0x0000FFFF
#تعریف_کرو NOEVAL_WANTED (nocode_wanted & NOEVAL_نقاب)

/* no code output when parsing constant expressions */
#تعریف_کرو CONST_WANTED_ثنائی_ہندسہ  0x00010000
#تعریف_کرو CONST_WANTED_نقاب 0x0FFF0000
#تعریف_کرو CONST_WANTED  (nocode_wanted & CONST_WANTED_نقاب)

ST_ڈیٹا صحیح global_اظہاریہ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ڈیٹا CType func_vt; /* current function return type (used by return instruction) */
ST_ڈیٹا صحیح func_var; /* true if current function is variadic (used by return instruction) */
ST_ڈیٹا صحیح func_vc; /* stack address for implicit struct return storage */
ST_ڈیٹا صحیح func_ind; /* function start address */
ساکن صحیح func_old;
ST_ڈیٹا ثابت حرف *funcname;
ST_ڈیٹا CType int_type, func_old_type, char_type, char_اشارہ_گر_type;
ساکن CString initstr;

#اگر PTR_سائز == 4
#تعریف_کرو VT_سائز_T (VT_INT | VT_UNSIGNED)
#تعریف_کرو VT_PTRDIFF_T VT_INT
#وگرنہ_اگر LONG_سائز == 4
#تعریف_کرو VT_سائز_T (VT_LLONG | VT_UNSIGNED)
#تعریف_کرو VT_PTRDIFF_T VT_LLONG
#ورنہ
#تعریف_کرو VT_سائز_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#تعریف_کرو VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#اگر_ختم

ساکن ساخت switch_t {
    ساخت case_t {
        int64_t v1, v2;
        صحیح ind, سطر;
    } **p; صحیح n; /* list of case ranges */
    صحیح def_sym; /* default symbol */
    صحیح nocode_wanted;
    صحیح *bsym;
    ساخت scope *scope;
    ساخت switch_t *پچھلا;
    SValue sv;
} *cur_switch; /* current switch */

#تعریف_کرو MAX_عارضی_LOCAL_VARIABLE_نمبر 8
/*list of temporary local variables on the stack in current function. */
ساکن ساخت عارضی_local_variable {
	صحیح location; //offset on stack. Svalue.c.i
	مختصر سائز;
	مختصر align;
} arr_عارضی_local_vars[MAX_عارضی_LOCAL_VARIABLE_نمبر];
ساکن صحیح nb_عارضی_local_vars;

ساکن ساخت scope {
    ساخت scope *پچھلا;
    ساخت { صحیح loc, locorig, عدد; } vla;
    ساخت { Sym *s; صحیح n; } cl;
    صحیح *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *جڑ_scope;

قسمتعریف ساخت {
    Section *sec;
    صحیح local_انحراف;
    Sym *flex_array_ref;
} init_params;

#اگر 1
#تعریف_کرو precedence_parser
ساکن خالی init_prec(خالی);
#اگر_ختم

ساکن خالی بلاک(صحیح flags);
#تعریف_کرو STMT_اظہاریہ 1
#تعریف_کرو STMT_COMPOUND 2

ساکن خالی gen_cast(CType *type);
ساکن خالی gen_cast_s(صحیح t);
ساکن اندرونی CType *pointed_type(CType *type);
ساکن خالی check_restrict_type(CType *type);
ساکن صحیح type_qualifiers(CType *type);
ساکن خالی parse_btype_qualify(CType *type, صحیح qualifiers);
ساکن صحیح is_compatible_types(CType *type1, CType *type2);
ساکن صحیح parse_btype(CType *type, AttributeDef *ad, صحیح ignore_label);
ساکن CType *type_decl(CType *type, AttributeDef *ad, صحیح *v, صحیح td);
ساکن خالی parse_اظہاریہ_type(CType *type);
ساکن خالی init_putv(init_params *p, CType *type, غیرعلامتی طویل c);
ساکن خالی decl_initializer(init_params *p, CType *type, غیرعلامتی طویل c, صحیح flags);
ساکن خالی decl_initializer_alloc(CType *type, AttributeDef *ad, صحیح r, صحیح has_init, صحیح v, صحیح scope);
ساکن صحیح decl(صحیح l);
ساکن خالی اظہاریہ_eq(خالی);
ساکن خالی vpush_type_سائز(CType *type, صحیح *a);
ساکن صحیح is_compatible_unqualified_types(CType *type1, CType *type2);
ساکن اندرونی int64_t اظہاریہ_const64(خالی);
ساکن خالی vpush64(صحیح ty, غیرعلامتی طویل طویل v);
ساکن خالی vpush(CType *type);
ساکن صحیح gvtst(صحیح inv, صحیح t);
ساکن خالی gen_inline_functions(TCCState *s);
ساکن خالی free_inline_functions(TCCState *s);
ساکن خالی skip_or_save_بلاک(TokenString **str);
ساکن خالی gv_dup(خالی);
ساکن صحیح get_عارضی_local_var(صحیح سائز,صحیح align,صحیح *r2);
ساکن خالی cast_error(CType *st, CType *dt);
ساکن خالی انتہا_switch(خالی);
ساکن خالی do_Static_assert(خالی);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC خالی gsym(صحیح t)
{
  اگر (t) {
    gsym_addr(t, ind);
    رمز_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ساکن صحیح gind()
{
  صحیح t = ind;
  رمز_ON();
  اگر (debug_modes)
    tcc_tcov_بلاک_begin(tcc_state);
  واپس t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ساکن خالی gjmp_addr_acs(صحیح t)
{
  gjmp_addr(t);
  رمز_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ساکن صحیح gjmp_acs(صحیح t)
{
  t = gjmp(t);
  رمز_OFF();
  واپس t;
}

/* These are #undef'd at the end of this file */
#تعریف_کرو gjmp_addr gjmp_addr_acs
#تعریف_کرو gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN صحیح is_float(صحیح t)
{
    صحیح bt = t & VT_BTYPE;
    واپس bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ساکن اندرونی صحیح is_integer_btype(صحیح bt)
{
    واپس bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ساکن صحیح btype_سائز(صحیح bt)
{
    واپس bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_سائز : 0;
}

/* returns function return register from type */
ساکن صحیح R_RET(صحیح t)
{
    اگر (!is_float(t))
        واپس REG_IRET;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        واپس TREG_ST0;
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        واپس REG_IRET;
#اگر_ختم
    واپس REG_FRET;
}

/* returns 2nd function return register, if any */
ساکن صحیح R2_RET(صحیح t)
{
    t &= VT_BTYPE;
#اگر PTR_سائز == 4
    اگر (t == VT_LLONG)
        واپس REG_IRE2;
#وگرنہ_اگر defined TCC_ہدف_X86_64
    اگر (t == VT_QLONG)
        واپس REG_IRE2;
    اگر (t == VT_QFLOAT)
        واپس REG_FRE2;
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    اگر (t == VT_LDOUBLE)
        واپس REG_IRE2;
#اگر_ختم
    واپس VT_CONST;
}

/* returns true for two-word types */
#تعریف_کرو USING_TWO_الفاظ(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ساکن خالی PUT_R_RET(SValue *sv, صحیح t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ساکن صحیح RC_RET(صحیح t)
{
    واپس reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ساکن صحیح RC_TYPE(صحیح t)
{
    اگر (!is_float(t))
        واپس RC_INT;
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        واپس RC_ST0;
    اگر ((t & VT_BTYPE) == VT_QFLOAT)
        واپس RC_FRET;
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        واپس RC_INT;
#اگر_ختم
    واپس RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ساکن صحیح RC2_TYPE(صحیح t, صحیح rc)
{
    اگر (!USING_TWO_الفاظ(t))
        واپس 0;
#اگر_تعریف_شدہ RC_IRE2
    اگر (rc == RC_IRET)
        واپس RC_IRE2;
#اگر_ختم
#اگر_تعریف_شدہ RC_FRE2
    اگر (rc == RC_FRET)
        واپس RC_FRE2;
#اگر_ختم
    اگر (rc & RC_FLOAT)
        واپس RC_FLOAT;
    واپس RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC صحیح ieee_finite(دوہرا d)
{
    صحیح p[4];
    حافظہ_نقل(p, &d, حجم(دوہرا));
    واپس ((غیرعلامتی)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC خالی test_lvalue(خالی)
{
    اگر (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC خالی check_vstack(خالی)
{
    اگر (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (صحیح)(vtop - vstack + 1));
}

#اگر 0
/* dump 'b' vstack entries starting with 'a'  */
خالی pv (ثابت حرف *lbl, صحیح a, صحیح b)
{
    صحیح i;
    برائے (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        لکھو("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (صحیح)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ساکن اندرونی خالی psyms(ثابت حرف *پیغام, Sym *s, Sym *آخری)
{
    لکھو("%-8s scope         v        c        r   type.t\n", پیغام);
    جب (s && s != آخری) {
        لکھو("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->پچھلا;
    }
}

ساکن خالی type_مقصد_str(حرف *buf, صحیح buf_سائز, CType *type, ثابت حرف *varstr);

/* print type */
ساکن خالی ptype(ثابت حرف *پیغام, CType *type, صحیح v)
{
    حرف buf[500];
    type_مقصد_str(buf, حجم(buf), type,
        (v & ~SYM_میدان) ? get_tok_str(v, تہی) : تہی);
    لکھو("%s : %s;\n", پیغام, buf);
}
#اگر_ختم

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC خالی tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, حجم *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    اگر (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_اشارہ_گر_type = char_type;
    mk_اشارہ_گر(&char_اشارہ_گر_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ڈالو(SYM_میدان, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#اگر_تعریف_شدہ precedence_parser
    init_prec();
#اگر_ختم
    cstr_new(&initstr);
}

ST_FUNC صحیح tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_پہلا_ANOM;
    nocode_wanted = ڈیٹا_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_اظہاریہ = 0;

    tcc_debug_آغاز(s1);
    tcc_tcov_آغاز (s1);
#اگر_تعریف_شدہ TCC_ہدف_ARM
    arm_init(s1);
#اگر_ختم
#اگر_تعریف_شدہ INC_DEBUG
    لکھو("%s: **** new file\n", file->filename);
#اگر_ختم
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_عدد | PARSE_FLAG_TOK_STR;
    اگلا();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#اگر TCC_EH_چوکھٹا
    tcc_eh_چوکھٹا_انتہا(s1);
#اگر_ختم
    tcc_debug_انتہا(s1);
    tcc_tcov_انتہا(s1);
    واپس 0;
}

ST_FUNC خالی tccgen_اختتام(TCCState *s1)
{
    tcc_debug_انتہا(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_نکالو(&global_ڈھیر, تہی, 0);
    sym_نکالو(&local_ڈھیر, تہی, 0);
    /* free preprocessor macros */
    free_متعین_کرتا(تہی);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_ڈیٹا, &nb_stk_ڈیٹا);
    جب (cur_switch)
        انتہا_switch();
    local_scope = 0;
    loop_scope = تہی;
    all_cleanups = تہی;
    pending_gotos = تہی;
    nb_عارضی_local_vars = 0;
    global_label_ڈھیر = تہی;
    local_label_ڈھیر = تہی;
    cur_متن_section = تہی;
    sym_free_پہلا = تہی;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  اگر (!s || !s->c)
    واپس تہی;
  واپس &((ElfSym *)symtab_section->ڈیٹا)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC خالی update_storage(Sym *sym)
{
    ElfSym *esym;
    صحیح sym_bind, old_sym_bind;

    esym = elfsym(sym);
    اگر (!esym)
        واپس;

    اگر (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    اگر (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ورنہ اگر (sym->a.weak)
        sym_bind = STB_WEAK;
    ورنہ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    اگر (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    اگر (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#اگر_ختم

#اگر 0
    لکھو("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, تہی),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#اگر_ختم
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC خالی put_extern_sym2(Sym *sym, صحیح sh_عدد,
                            addr_t قدر, غیرعلامتی طویل سائز,
                            صحیح can_جوڑو_underscore)
{
    صحیح sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ثابت حرف *name;
    حرف buf1[256];

    اگر (!sym->c) {
        name = get_tok_str(sym->v, تہی);
        t = sym->type.t;
        اگر ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ورنہ اگر ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            اگر (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ورنہ اگر (t & VT_TLS) {
            sym_type = STT_TLS;
        } ورنہ {
            sym_type = STT_OBJECT;
        }
        اگر (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ورنہ
            sym_bind = STB_GLOBAL;
        other = 0;

#اگر_تعریف_شدہ TCC_ہدف_PE
        اگر (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            اگر (ref->a.nodecorate) {
                can_جوڑو_underscore = 0;
            }
            اگر (ref->f.func_call == FUNC_STDCALL && can_جوڑو_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_دلائل * PTR_سائز);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_جوڑو_underscore = 0;
            }
        }
#اگر_ختم

        اگر (sym->asm_label) {
            name = get_tok_str(sym->asm_label, تہی);
            can_جوڑو_underscore = 0;
        }

        اگر (tcc_state->leading_underscore && can_جوڑو_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, حجم(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, قدر, سائز, info, other, sh_عدد, name);

        اگر (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_عدد, sym_bind, sym_type);

    } ورنہ {
        esym = elfsym(sym);
        esym->st_قدر = قدر;
        esym->st_سائز = سائز;
        esym->st_shndx = sh_عدد;
    }
    update_storage(sym);
}

ST_FUNC خالی put_extern_sym(Sym *sym, Section *s, addr_t قدر, غیرعلامتی طویل سائز)
{
    اگر (nocode_wanted && (NODATA_WANTED || (s && s == cur_متن_section)))
        واپس;
    put_extern_sym2(sym, s ? s->sh_عدد : SHN_UNDEF, قدر, سائز, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC خالی greloca(Section *s, Sym *sym, غیرعلامتی طویل انحراف, صحیح type,
                     addr_t addend)
{
    صحیح c = 0;

    اگر (nocode_wanted && s == cur_متن_section)
        واپس;

    اگر (sym) {
        اگر (0 == sym->c) {
            put_extern_sym(sym, تہی, 0, 0);
            اگر (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                جب (s->پچھلا_tok)
                    s = s->پچھلا_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, انحراف, type, c, addend);
}

#اگر PTR_سائز == 4
ST_FUNC خالی greloc(Section *s, Sym *sym, غیرعلامتی طویل انحراف, صحیح type)
{
    greloca(s, sym, انحراف, type, 0);
}
#اگر_ختم

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ساکن Sym *__sym_malloc(خالی)
{
    Sym *sym_pool, *sym, *آخری_sym;
    صحیح i;

    sym_pool = tcc_malloc(SYM_POOL_NB * حجم(Sym));
    dynarray_جوڑو(&sym_pools, &nb_sym_pools, sym_pool);

    آخری_sym = sym_free_پہلا;
    sym = sym_pool;
    برائے(i = 0; i < SYM_POOL_NB; i++) {
        sym->اگلا = آخری_sym;
        آخری_sym = sym;
        sym++;
    }
    sym_free_پہلا = آخری_sym;
    واپس آخری_sym;
}

ساکن اندرونی Sym *sym_malloc(خالی)
{
    Sym *sym;
#اگر_غیر_تعریف_شدہ SYM_DEBUG
    sym = sym_free_پہلا;
    اگر (!sym)
        sym = __sym_malloc();
    sym_free_پہلا = sym->اگلا;
    واپس sym;
#ورنہ
    sym = tcc_malloc(حجم(Sym));
    واپس sym;
#اگر_ختم
}

ST_INLN خالی sym_free(Sym *sym)
{
#اگر_غیر_تعریف_شدہ SYM_DEBUG
    sym->اگلا = sym_free_پہلا;
    sym_free_پہلا = sym;
#ورنہ
    tcc_free(sym);
#اگر_ختم
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, صحیح v, صحیح t, صحیح c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, حجم *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->پچھلا = *ps;
    *ps = s;
    واپس s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, صحیح v)
{
    جب (s) {
        اگر (s->v == v)
            واپس s;
        s = s->پچھلا;
    }
    واپس تہی;
}

/* structure lookup */
ST_INLN Sym *struct_ڈھونڈو(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((غیرعلامتی)v >= (غیرعلامتی)(tok_ident - TOK_IDENT))
        واپس تہی;
    واپس جدول_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_ڈھونڈو(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((غیرعلامتی)v >= (غیرعلامتی)(tok_ident - TOK_IDENT))
        واپس تہی;
    واپس جدول_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ساکن اندرونی خالی sym_link(Sym *s, صحیح yes)
{
    TokenSym *ts = جدول_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    اگر (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ورنہ
        ps = &ts->sym_identifier;
    اگر (yes) {
        s->پچھلا_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ورنہ {
        *ps = s->پچھلا_tok;
    }
}

ساکن اندرونی صحیح sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    واپس IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ڈالو(صحیح v, CType *type, صحیح r, صحیح c)
{
    Sym *s, **ps;
    اگر (local_ڈھیر)
        ps = &local_ڈھیر;
    ورنہ
        ps = &global_ڈھیر;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    اگر ((v & ~SYM_STRUCT) < SYM_پہلا_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        اگر (s->پچھلا_tok && sym_scope_ex(s->پچھلا_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, تہی));
    }
    واپس s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ڈالو(صحیح v, صحیح t, صحیح c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ڈھیر, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    اگر (v < SYM_پہلا_ANOM) {
        ps = &جدول_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        جب (*ps != تہی && (*ps)->sym_scope)
            ps = &(*ps)->پچھلا_tok;
        s->پچھلا_tok = *ps;
        *ps = s;
    }
    واپس s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC خالی sym_نکالو(Sym **ptop, Sym *b, صحیح keep)
{
    Sym *s, *ss;
    صحیح v;

    s = *ptop;
    جب(s != b) {
        ss = s->پچھلا;
        v = s->v;
        /* remove symbol in token array */
        اگر ((v & ~SYM_STRUCT) < SYM_پہلا_ANOM)
            sym_link(s, 0);
	اگر (!keep)
	    sym_free(s);
        s = ss;
    }
    اگر (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_ڈھونڈو(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((غیرعلامتی)v >= (غیرعلامتی)(tok_ident - TOK_IDENT))
        واپس تہی;
    واپس جدول_ident[v]->sym_label;
}

ST_FUNC Sym *label_ڈالو(Sym **ptop, صحیح v, صحیح flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &جدول_ident[v - TOK_IDENT]->sym_label;
    اگر (ptop == &global_label_ڈھیر) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        جب (*ps != تہی)
            ps = &(*ps)->پچھلا_tok;
    }
    s->پچھلا_tok = *ps;
    *ps = s;
    واپس s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC خالی label_نکالو(Sym **ptop, Sym *slast, صحیح keep)
{
    Sym *s, *s1;
    برائے(s = *ptop; s != slast; s = s1) {
        s1 = s->پچھلا;
        اگر (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, تہی));
        } ورنہ اگر (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, تہی));
        } ورنہ {
            اگر (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_متن_section, s->jind, 1);
            }
        }
        /* remove label */
        اگر (s->r != LABEL_GONE)
            جدول_ident[s->v - TOK_IDENT]->sym_label = s->پچھلا_tok;
        اگر (!keep)
            sym_free(s);
        ورنہ
            s->r = LABEL_GONE;
    }
    اگر (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ساکن خالی vcheck_cmp(خالی)
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

    اگر (vtop->r == VT_CMP && 0 == (nocode_wanted & ~رمز_OFF_ثنائی_ہندسہ))
        gv(RC_INT);
}

ساکن خالی vsetc(CType *type, صحیح r, CValue *vc)
{
    اگر (vtop >= vstack + (VSTACK_سائز - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = تہی;
}

ST_FUNC خالی vswap(خالی)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC خالی vpop(خالی)
{
    صحیح v;
    v = vtop->r & VT_VALMASK;
#اگر defined(TCC_ہدف_I386) || defined(TCC_ہدف_X86_64)
    /* for x86, we need to pop the FP stack */
    اگر (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ورنہ
#اگر_ختم
    اگر (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ساکن خالی vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ساکن خالی vpush64(صحیح ty, غیرعلامتی طویل طویل v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = تہی;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC خالی vpushi(صحیح v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ساکن خالی vpushs(addr_t v)
{
    vpush64(VT_سائز_T, v);
}

/* push long long constant */
ساکن اندرونی خالی vpushll(طویل طویل v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC خالی vset(CType *type, صحیح r, صحیح v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ساکن خالی vseti(صحیح r, صحیح v)
{
    CType type;
    type.t = VT_INT;
    type.ref = تہی;
    vset(&type, r, v);
}

ST_FUNC خالی vpushv(SValue *v)
{
    اگر (vtop >= vstack + (VSTACK_سائز - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ساکن خالی vdup(خالی)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC خالی vrotb(صحیح n)
{
    SValue tmp;
    اگر (--n < 1)
        واپس;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, حجم *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC خالی vrott(صحیح n)
{
    SValue tmp;
    اگر (--n < 1)
        واپس;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, حجم *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC خالی vrev(صحیح n)
{
    صحیح i;
    SValue tmp;
    vcheck_cmp();
    برائے (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC خالی vset_VT_CMP(صحیح op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ساکن خالی vset_VT_JMP(خالی)
{
    صحیح op = vtop->cmp_op;

    اگر (vtop->jtrue || vtop->jfalse) {
        صحیح origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        صحیح inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ورنہ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        اگر (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ساکن خالی gvtst_سیٹ(صحیح inv, صحیح t)
{
    صحیح *p;

    اگر (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        اگر (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
ساکن صحیح gvtst(صحیح inv, صحیح t)
{
    صحیح op, x, u;

    gvtst_سیٹ(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    اگر (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    اگر (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ورنہ اگر (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    واپس t;
}

/* generate a zero or nozero test */
ساکن خالی gen_test_zero(صحیح op)
{
    اگر (vtop->r == VT_CMP) {
        صحیح j;
        اگر (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ورنہ {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC خالی vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, غیرعلامتی طویل انحراف, غیرعلامتی طویل سائز)
{
    صحیح v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ڈالو(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, انحراف, سائز);
    واپس sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ساکن خالی vpush_ref(CType *type, Section *sec, غیرعلامتی طویل انحراف, غیرعلامتی طویل سائز)
{
    vpushsym(type, get_sym_ref(type, sec, انحراف, سائز));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(صحیح v, CType *type)
{
    Sym *s;

    s = sym_ڈھونڈو(v);
    اگر (!s) {
        /* push forward reference */
        s = global_identifier_ڈالو(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ورنہ اگر (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    واپس s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(صحیح v)
{
    CType ct = { VT_ASM_FUNC, تہی };
    واپس external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC خالی vpush_helper_func(صحیح v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ساکن خالی ملاؤ_symattr(ساخت SymAttr *sa, ساخت SymAttr *sa1)
{
    اگر (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    اگر (sa1->visibility != STV_DEFAULT) {
	صحیح vis = sa->visibility;
	اگر (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
ساکن خالی ملاؤ_funcattr(ساخت FuncAttr *fa, ساخت FuncAttr *fa1)
{
    اگر (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    اگر (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    اگر (fa1->func_دلائل && !fa->func_دلائل)
      fa->func_دلائل = fa1->func_دلائل;
    اگر (fa1->func_noreturn)
      fa->func_noreturn = 1;
    اگر (fa1->func_ctor)
      fa->func_ctor = 1;
    اگر (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ساکن خالی ملاؤ_attr(AttributeDef *ad, AttributeDef *ad1)
{
    ملاؤ_symattr(&ad->a, &ad1->a);
    ملاؤ_funcattr(&ad->f, &ad1->f);

    اگر (ad1->section)
      ad->section = ad1->section;
    اگر (ad1->alias_ہدف)
      ad->alias_ہدف = ad1->alias_ہدف;
    اگر (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    اگر (ad1->attr_منوال)
      ad->attr_منوال = ad1->attr_منوال;
}

/* Merge some type attributes.  */
ساکن خالی patch_type(Sym *sym, CType *type)
{
    اگر (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        اگر (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, تہی));
        sym->type.t &= ~VT_EXTERN;
    }

    اگر (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        اگر ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    اگر (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, تہی));

    } ورنہ اگر ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        صحیح static_proto = sym->type.t & VT_STATIC;
        صحیح ft1 = sym->type.ref->f.func_type;
        صحیح ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        اگر ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, تہی));

        /* set 'inline' if both agree or if one has static */
        اگر ((type->t | sym->type.t) & VT_INLINE) {
            اگر (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        اگر (0 == (type->t & VT_EXTERN)) {
            ساخت FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            اگر (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            ملاؤ_funcattr(&sym->type.ref->f, &f);
        } ورنہ {
            sym->type.t &= ~VT_INLINE | static_proto;
            اگر (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ورنہ {
        اگر ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        اگر ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, تہی));
    }
}

/* Merge some storage attributes.  */
ساکن خالی patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    اگر (type)
        patch_type(sym, type);

#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, تہی));
#اگر_ختم
    ملاؤ_symattr(&sym->a, &ad->a);
    اگر (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ساکن Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->پچھلا = *ps, *ps = s;
    اگر ((s->v & ~SYM_STRUCT) < SYM_پہلا_ANOM)
        sym_link(s, 1);
    واپس s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ساکن خالی move_ref_مقصد_global(Sym *s)
{
    Sym *l, **lp;
    صحیح n, bt;

    bt = s->type.t & VT_BTYPE;
    اگر (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        واپس;

    برائے (s = s->type.ref, n = 0; s; s = s->اگلا) {
        برائے (lp = &local_ڈھیر; !!(l = *lp); lp = &l->پچھلا) {
            اگر (l == s) {
                *lp = s->پچھلا;
                s->پچھلا = global_ڈھیر, global_ڈھیر = s;
                اگر (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_مقصد_global(s);
                } ورنہ {
                    اگر ((s->v & ~SYM_STRUCT) < SYM_پہلا_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_میدان;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_میدان;
                    }
                }
                اگر (bt != VT_PTR)
                    n = 1;
                توڑو;
            }
        }
        اگر (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            توڑو;
    }
}

/* define a new external reference to a symbol 'v' */
ساکن Sym *external_sym(صحیح v, CType *type, صحیح r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_ڈھونڈو(v);
    جب (s && s->sym_scope)
        s = s->پچھلا_tok;

    اگر (!s) {
        /* push forward reference */
        s = global_identifier_ڈالو(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ورنہ {
        patch_storage(s, ad, type);
    }
    اگر (local_ڈھیر) {
        /* make sure that type->ref is on global stack */
        move_ref_مقصد_global(s);
        /* put into local scope */
        sym_copy(s, &local_ڈھیر);
    }
    واپس s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC خالی save_regs(صحیح n)
{
    SValue *p, *p1;
    برائے(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC خالی save_reg(صحیح r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC خالی save_reg_upstack(صحیح r, صحیح n)
{
    صحیح l, سائز, align, bt, r2;
    SValue *p, *p1, sv;

    اگر ((r &= VT_VALMASK) >= VT_CONST)
        واپس;
    اگر (nocode_wanted)
        واپس;
    l = r2 = 0;
    برائے(p = vstack, p1 = vtop - n; p <= p1; p++) {
        اگر ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            اگر (!l) {
                bt = p->type.t & VT_BTYPE;
                اگر (bt == VT_VOID)
                    جاری;
                اگر ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                سائز = type_سائز(&sv.type, &align);
                l = get_عارضی_local_var(سائز, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = تہی;
                store(p->r & VT_VALMASK, &sv);
#اگر defined(TCC_ہدف_I386) || defined(TCC_ہدف_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                اگر (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#اگر_ختم
                /* special long long case */
                اگر (p->r2 < VT_CONST && USING_TWO_الفاظ(bt)) {
                    sv.c.i += PTR_سائز;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            اگر (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ورنہ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = تہی;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#اگر_تعریف_شدہ TCC_ہدف_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC صحیح get_reg_ex(صحیح rc, صحیح rc2)
{
    صحیح r;
    SValue *p;
    
    برائے(r=0;r<NB_REGS;r++) {
        اگر (reg_classes[r] & rc2) {
            صحیح n;
            n=0;
            برائے(p = vstack; p <= vtop; p++) {
                اگر ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            اگر (n <= 1)
                واپس r;
        }
    }
    واپس get_reg(rc);
}
#اگر_ختم

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC صحیح get_reg(صحیح rc)
{
    صحیح r;
    SValue *p;

    /* find a free register */
    برائے(r=0;r<NB_REGS;r++) {
        اگر (reg_classes[r] & rc) {
            اگر (nocode_wanted)
                واپس r;
            برائے(p=vstack;p<=vtop;p++) {
                اگر ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    جاؤ notfound;
            }
            واپس r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    برائے(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        اگر (r < VT_CONST && (reg_classes[r] & rc))
            جاؤ save_ملا;
        r = p->r & VT_VALMASK;
        اگر (r < VT_CONST && (reg_classes[r] & rc)) {
        save_ملا:
            save_reg(r);
            واپس r;
        }
    }
    /* Should never comes here */
    واپس -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ساکن صحیح get_عارضی_local_var(صحیح سائز,صحیح align, صحیح *r2)
{
    صحیح i;
    ساخت عارضی_local_variable *عارضی_var;
    SValue *p;
    صحیح r;
    غیرعلامتی مستعمل = 0;

    /* mark locations that are still in use */
    برائے (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	اگر (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    اگر (r >= 0 && r < MAX_عارضی_LOCAL_VARIABLE_نمبر)
	        مستعمل |= 1<<r;
	}
    }
    برائے (i=0;i<nb_عارضی_local_vars;i++) {
	عارضی_var=&arr_عارضی_local_vars[i];
	اگر(!(مستعمل & 1<<i)
	 && عارضی_var->سائز>=سائز
	 && عارضی_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    واپس عارضی_var->location;
	}
    }
    loc = (loc - سائز) & -align;
    اگر (nb_عارضی_local_vars<MAX_عارضی_LOCAL_VARIABLE_نمبر) {
	عارضی_var=&arr_عارضی_local_vars[i];
	عارضی_var->location=loc;
	عارضی_var->سائز=سائز;
	عارضی_var->align=align;
	nb_عارضی_local_vars++;
	جاؤ ret_tmp;
    }
    *r2 = VT_CONST;
    واپس loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ساکن خالی move_reg(صحیح r, صحیح s, صحیح t)
{
    SValue sv;

    اگر (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = تہی;
        sv.r = s;
        sv.c.i = 0;
        بھرو(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC خالی gaddrof(خالی)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    اگر ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ساکن خالی gen_bounded_ptr_جوڑو(خالی)
{
    صحیح save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    اگر (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_جوڑو);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    اگر (nocode_wanted)
        واپس;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_متن_section->reloc->ڈیٹا_انحراف - حجم(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ساکن خالی gen_bounded_ptr_deref(خالی)
{
    addr_t func;
    صحیح سائز, align;
    ElfW_Rel *rel;
    Sym *sym;

    اگر (nocode_wanted)
        واپس;

    سائز = type_سائز(&vtop->type, &align);
    انتخاب(سائز) {
    حالت  1: func = TOK___bound_ptr_indir1; توڑو;
    حالت  2: func = TOK___bound_ptr_indir2; توڑو;
    حالت  4: func = TOK___bound_ptr_indir4; توڑو;
    حالت  8: func = TOK___bound_ptr_indir8; توڑو;
    حالت 12: func = TOK___bound_ptr_indir12; توڑو;
    حالت 16: func = TOK___bound_ptr_indir16; توڑو;
    طےشدہ:
        /* may happen with struct member access */
        واپس;
    }
    sym = external_helper_sym(func);
    اگر (!sym->c)
        put_extern_sym(sym, تہی, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_متن_section->reloc->ڈیٹا + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ساکن خالی gbound(خالی)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    اگر (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        اگر (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_جوڑو();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC خالی gbound_دلائل(صحیح nb_دلائل)
{
    صحیح i, v;
    SValue *sv;

    برائے (i = 1; i <= nb_دلائل; ++i)
        اگر (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_دلائل;
    اگر (sv->r & VT_SYM) {
        v = sv->sym->v;
        اگر (v == TOK_setjmp
          || v == TOK__setjmp
#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#اگر_ختم
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_جوڑو_epilog = 1;
        }
        اگر (v == TOK_alloca)
            func_bound_جوڑو_epilog = 1;
#اگر TARGETOS_NetBSD
        اگر (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#اگر_ختم
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ساکن خالی جوڑو_local_bounds(Sym *s, Sym *e)
{
    برائے (; s != e; s = s->پچھلا) {
        اگر (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          جاری;
        /* Add arrays/structs/unions because we always take address */
        اگر ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            صحیح align, سائز = type_سائز(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_جوڑو(lbounds_section,
                                                 2 * حجم(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = سائز;
        }
    }
}
#اگر_ختم

/* add debug info for locals or function parameters, optionally
   register bounds */
ساکن خالی tcc_debug_انتہا_scope(Sym *b, صحیح bounds)
{
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check && bounds)
        جوڑو_local_bounds(local_ڈھیر, b);
#اگر_ختم
    tcc_جوڑو_debug_info (tcc_state, local_ڈھیر, b);
}

/* increment an lvalue pointer */
ساکن خالی incr_انحراف(صحیح انحراف)
{
    صحیح t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(انحراف);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ساکن خالی incr_bf_adr(صحیح o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_انحراف(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ساکن خالی بھرو_packed_bf(CType *type, صحیح ثنائی_ہندسہ_pos, صحیح ثنائی_ہندسہ_سائز_2)
{
    صحیح n, o, بٹ;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    بٹ = 0, o = ثنائی_ہندسہ_pos >> 3, ثنائی_ہندسہ_pos &= 7;
    کرو {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - ثنائی_ہندسہ_pos;
        اگر (n > ثنائی_ہندسہ_سائز_2)
            n = ثنائی_ہندسہ_سائز_2;
        اگر (ثنائی_ہندسہ_pos)
            vpushi(ثنائی_ہندسہ_pos), gen_op(TOK_SHR), ثنائی_ہندسہ_pos = 0; // X B Y
        اگر (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        اگر (بٹ)
            vpushi(بٹ), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        بٹ += n, ثنائی_ہندسہ_سائز_2 -= n, o = 1;
    } جب (ثنائی_ہندسہ_سائز_2);
    vswap(), vpop();
    اگر (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - بٹ;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ساکن خالی store_packed_bf(صحیح ثنائی_ہندسہ_pos, صحیح ثنائی_ہندسہ_سائز_2)
{
    صحیح بٹ, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    بٹ = 0, o = ثنائی_ہندسہ_pos >> 3, ثنائی_ہندسہ_pos &= 7;
    کرو {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        اگر (بٹ)
            vpushi(بٹ), gen_op(TOK_SHR);
        اگر (ثنائی_ہندسہ_pos)
            vpushi(ثنائی_ہندسہ_pos), gen_op(TOK_SHL);
        n = 8 - ثنائی_ہندسہ_pos;
        اگر (n > ثنائی_ہندسہ_سائز_2)
            n = ثنائی_ہندسہ_سائز_2;
        اگر (n < 8) {
            m = ((1 << n) - 1) << ثنائی_ہندسہ_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        بٹ += n, ثنائی_ہندسہ_سائز_2 -= n, ثنائی_ہندسہ_pos = 0, o = 1;
    } جب (ثنائی_ہندسہ_سائز_2);
    vpop(), vpop();
}

ساکن صحیح adjust_bf(SValue *sv, صحیح ثنائی_ہندسہ_pos, صحیح ثنائی_ہندسہ_سائز_2)
{
    صحیح t;
    اگر (0 == sv->type.ref)
        واپس 0;
    t = sv->type.ref->auxtype;
    اگر (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    واپس t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC صحیح gv(صحیح rc)
{
    صحیح r, r2, r_ok, r2_ok, rc2, bt;
    صحیح ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2, سائز, align;

    /* NOTE: get_reg can modify vstack[] */
    اگر (vtop->type.t & VT_BITFIELD) {
        CType type;

        ثنائی_ہندسہ_pos = ثنائی_ہندسہ_POS(vtop->type.t);
        ثنائی_ہندسہ_سائز_2 = ثنائی_ہندسہ_سائز(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_نقاب;

        type.ref = تہی;
        type.t = vtop->type.t & VT_UNSIGNED;
        اگر ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2);

        اگر ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ورنہ
            type.t |= VT_INT;

        اگر (r == VT_STRUCT) {
            بھرو_packed_bf(&type, ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2);
        } ورنہ {
            صحیح بٹ = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(بٹ - (ثنائی_ہندسہ_pos + ثنائی_ہندسہ_سائز_2));
            gen_op(TOK_SHL);
            vpushi(بٹ - ثنائی_ہندسہ_سائز_2);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } ورنہ {
        اگر (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            غیرعلامتی طویل انحراف;
            سائز = type_سائز(&vtop->type, &align);
            اگر (NODATA_WANTED)
                سائز = 0, align = 1;
            انحراف = section_جوڑو(p.sec, سائز, align);
            vpush_ref(&vtop->type, p.sec, انحراف, سائز);
	    vswap();
	    init_putv(&p, &vtop->type, انحراف);
	    vtop->r |= VT_LVAL;
        }
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND) 
            gbound();
#اگر_ختم

        bt = vtop->type.t & VT_BTYPE;
        اگر (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            واپس vtop->r;

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
        /* XXX mega hack */
        اگر (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#اگر_ختم
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        اگر (!r_ok || !r2_ok) {

            اگر (!r_ok) {
                اگر (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ورنہ
                    r = get_reg(rc);
            }

            اگر (rc2) {
                صحیح بھرو_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                صحیح original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    غیرعلامتی طویل طویل ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    بھرو(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ورنہ اگر (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = بھرو_type;
                    بھرو(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_انحراف(PTR_سائز);
                } ورنہ {
                    /* move registers */
                    اگر (!r_ok)
                        بھرو(r, vtop);
                    اگر (r2_ok && vtop->r2 < VT_CONST)
                        جاؤ مکمل;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                بھرو(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            مکمل:
                vtop->type.t = original_type;
            } ورنہ {
                اگر (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                بھرو(r, vtop);
            }
        }
        vtop->r = r;
#اگر_تعریف_شدہ TCC_ہدف_C67
        /* uses register pairs for doubles */
        اگر (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#اگر_ختم
    }
    واپس r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC خالی gv2(صحیح rc1, صحیح rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    اگر (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        اگر ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ورنہ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        اگر ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#اگر PTR_سائز == 4
/* expand 64bit on stack in two ints */
ST_FUNC خالی lexpand(خالی)
{
    صحیح u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    اگر (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ورنہ اگر (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ورنہ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#اگر_ختم

#اگر PTR_سائز == 4
/* build a long long from two ints */
ساکن خالی lbuild(صحیح t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#اگر_ختم

/* convert stack entry to register and duplicate its value in another
رجسٹر*/
ساکن خالی gv_dup(خالی)
{
    صحیح t, rc, r;

    t = vtop->type.t;
#اگر PTR_سائز == 4
    اگر ((t & VT_BTYPE) == VT_LLONG) {
        اگر (t & VT_BITFIELD) {
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
        واپس;
    }
#اگر_ختم
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    بھرو(r, vtop);
    vtop->r = r;
}

#اگر PTR_سائز == 4
/* generate CPU independent (unsigned) long long operations */
ساکن خالی gen_opl(صحیح op)
{
    صحیح t, a, b, op1, c, i;
    صحیح func;
    غیرعلامتی مختصر reg_iret = REG_IRET;
    غیرعلامتی مختصر reg_lret = REG_IRE2;
    SValue tmp;

    انتخاب(op) {
    حالت '/':
    حالت TOK_PDIV:
        func = TOK___divdi3;
        جاؤ gen_func;
    حالت TOK_UDIV:
        func = TOK___udivdi3;
        جاؤ gen_func;
    حالت '%':
        func = TOK___moddi3;
        جاؤ gen_mod_func;
    حالت TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#اگر_تعریف_شدہ TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#اگر_ختم
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        توڑو;
    حالت '^':
    حالت '&':
    حالت '|':
    حالت '*':
    حالت '+':
    حالت '-':
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
        اگر (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            برائے(i=0;i<4;i++)
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
        } ورنہ اگر (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            اگر (op == '+')
                op1 = TOK_ADDC1;
            ورنہ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ورنہ {
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
        توڑو;
    حالت TOK_SAR:
    حالت TOK_SHR:
    حالت TOK_SHL:
        اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (صحیح)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            اگر (op != TOK_SHL)
                vswap();
            اگر (c >= 32) {
                /* stack: L H */
                vpop();
                اگر (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                اگر (op != TOK_SAR) {
                    vpushi(0);
                } ورنہ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ورنہ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                اگر (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ورنہ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                اگر (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ورنہ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            اگر (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ورنہ {
            /* XXX: should provide a faster fallback on x86 ? */
            انتخاب(op) {
            حالت TOK_SAR:
                func = TOK___ashrdi3;
                جاؤ gen_func;
            حالت TOK_SHR:
                func = TOK___lshrdi3;
                جاؤ gen_func;
            حالت TOK_SHL:
                func = TOK___ashldi3;
                جاؤ gen_func;
            }
        }
        توڑو;
    طےشدہ:
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
        اگر (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        اگر (op1 == TOK_LT)
            op1 = TOK_LE;
        ورنہ اگر (op1 == TOK_GT)
            op1 = TOK_GE;
        ورنہ اگر (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ورنہ اگر (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        اگر (op == TOK_NE) {
            b = gvtst(0, 0);
        } ورنہ {
            a = gvtst(1, 0);
            اگر (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        اگر (op1 == TOK_LT)
            op1 = TOK_ULT;
        ورنہ اگر (op1 == TOK_LE)
            op1 = TOK_ULE;
        ورنہ اگر (op1 == TOK_GT)
            op1 = TOK_UGT;
        ورنہ اگر (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#اگر 0//def TCC_TARGET_I386
        اگر (op == TOK_NE) { gsym(b); توڑو; }
        اگر (op == TOK_EQ) { gsym(a); توڑو; }
#اگر_ختم
        gvtst_سیٹ(1, a);
        gvtst_سیٹ(0, b);
        توڑو;
    }
}
#اگر_ختم

/* normalize values */
ساکن uint64_t value64(uint64_t l1, صحیح t)
{
    اگر ((t & VT_BTYPE) == VT_LLONG
        || (PTR_سائز == 8 && (t & VT_BTYPE) == VT_PTR))
        واپس l1;
    ورنہ اگر (t & VT_UNSIGNED)
        واپس (uint32_t)l1;
    ورنہ
        واپس (uint32_t)l1 | -(l1 & 0x80000000);
}

ساکن uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    واپس (a ^ b) >> 63 ? -x : x;
}

ساکن صحیح gen_opic_lt(uint64_t a, uint64_t b)
{
    واپس (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ساکن خالی gen_opic(صحیح op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    صحیح t1 = v1->type.t & VT_BTYPE;
    صحیح t2 = v2->type.t & VT_BTYPE;
    صحیح c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    صحیح c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    صحیح shm = (t1 == VT_LLONG) ? 63 : 31;
    صحیح r;

    اگر (c1 && c2) {
        انتخاب(op) {
        حالت '+': l1 += l2; توڑو;
        حالت '-': l1 -= l2; توڑو;
        حالت '&': l1 &= l2; توڑو;
        حالت '^': l1 ^= l2; توڑو;
        حالت '|': l1 |= l2; توڑو;
        حالت '*': l1 *= l2; توڑو;

        حالت TOK_PDIV:
        حالت '/':
        حالت '%':
        حالت TOK_UDIV:
        حالت TOK_UMOD:
            /* if division by zero, generate explicit division */
            اگر (l2 == 0) {
                اگر (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                جاؤ general_case;
            }
            انتخاب(op) {
            طےشدہ: l1 = gen_opic_sdiv(l1, l2); توڑو;
            حالت '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); توڑو;
            حالت TOK_UDIV: l1 = l1 / l2; توڑو;
            حالت TOK_UMOD: l1 = l1 % l2; توڑو;
            }
            توڑو;
        حالت TOK_SHL: l1 <<= (l2 & shm); توڑو;
        حالت TOK_SHR: l1 >>= (l2 & shm); توڑو;
        حالت TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            توڑو;
            /* tests */
        حالت TOK_ULT: l1 = l1 < l2; توڑو;
        حالت TOK_UGE: l1 = l1 >= l2; توڑو;
        حالت TOK_EQ: l1 = l1 == l2; توڑو;
        حالت TOK_NE: l1 = l1 != l2; توڑو;
        حالت TOK_ULE: l1 = l1 <= l2; توڑو;
        حالت TOK_UGT: l1 = l1 > l2; توڑو;
        حالت TOK_LT: l1 = gen_opic_lt(l1, l2); توڑو;
        حالت TOK_GE: l1 = !gen_opic_lt(l1, l2); توڑو;
        حالت TOK_LE: l1 = !gen_opic_lt(l2, l1); توڑو;
        حالت TOK_GT: l1 = gen_opic_lt(l2, l1); توڑو;
            /* logical */
        حالت TOK_LAND: l1 = l1 && l2; توڑو;
        حالت TOK_LOR: l1 = l1 || l2; توڑو;
        طےشدہ:
            جاؤ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ورنہ {
        /* if commutative ops, put c2 as constant */
        اگر (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        اگر (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ورنہ اگر (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            اگر (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ورنہ اگر (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ورنہ اگر (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            اگر (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                صحیح n = -1;
                اگر (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    جاؤ general_case;
                }
                جب (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                اگر (op == '*')
                    op = TOK_SHL;
                ورنہ اگر (op == TOK_PDIV)
                    op = TOK_SAR;
                ورنہ
                    op = TOK_SHR;
            }
            جاؤ general_case;
        } ورنہ اگر (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            اگر (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    اگر ((صحیح)l2 != l2)
	        جاؤ general_case;
            vtop--;
            vtop->c.i = l2;
        } ورنہ {
        general_case:
                /* call low level op generator */
                اگر (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_سائز == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ورنہ
                    gen_opi(op);
        }
        اگر (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#اگر defined TCC_ہدف_X86_64 || defined TCC_ہدف_I386 || defined TCC_ہدف_ARM64
# define gen_negf gen_opf
#وگرنہ_اگر defined TCC_ہدف_ARM
خالی gen_negf(صحیح op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ورنہ
/* XXX: implement in gen_opf() for other backends too */
خالی gen_negf(صحیح op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    صحیح align, سائز, bt;
    سائز = type_سائز(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#اگر defined TCC_ہدف_X86_64 || defined TCC_ہدف_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    اگر (bt == VT_LDOUBLE)
        سائز = 10;
#اگر_ختم
    اگر (nocode_wanted) /* save_reg() wont work */
        جاؤ gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(سائز - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#اگر_ختم

/* generate a floating point operation with constant propagation */
ساکن خالی gen_opif(صحیح op)
{
    صحیح c1, c2, i, bt;
    SValue *v1, *v2;
#اگر defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    متلون
#اگر_ختم
    طویل دوہرا f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    اگر (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    اگر (c1 && c2) {
        اگر (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ورنہ اگر (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ورنہ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        اگر (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            جاؤ general_case;
        انتخاب(op) {
        حالت '+': f1 += f2; توڑو;
        حالت '-': f1 -= f2; توڑو;
        حالت '*': f1 *= f2; توڑو;
        حالت '/': 
            اگر (f2 == 0.0) {
                اتحاد { اعشاری f; غیرعلامتی u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                اگر (!CONST_WANTED)
                    جاؤ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                اگر (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ورنہ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                توڑو;
            }
            f1 /= f2;
            توڑو;
        حالت TOK_NEG:
            f1 = -f1;
            جاؤ unary_نتیجہ;
        حالت TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            واپس;
        حالت TOK_NE:
            i = f1 != f2;
	    جاؤ make_int;
        حالت TOK_LT:
            i = f1 < f2;
	    جاؤ make_int;
        حالت TOK_GE:
            i = f1 >= f2;
	    جاؤ make_int;
        حالت TOK_LE:
            i = f1 <= f2;
	    جاؤ make_int;
        حالت TOK_GT:
            i = f1 > f2;
	    جاؤ make_int;
        طےشدہ:
            جاؤ general_case;
        }
        vtop--;
    unary_نتیجہ:
        /* XXX: overflow test ? */
        اگر (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ورنہ اگر (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ورنہ {
            v1->c.ld = f1;
        }
    } ورنہ {
    general_case:
        اگر (op == TOK_NEG) {
            gen_negf(op);
        } ورنہ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ساکن خالی type_مقصد_str(حرف *buf, صحیح buf_سائز,
                 CType *type, ثابت حرف *varstr)
{
    صحیح bt, v, t;
    Sym *s, *sa;
    حرف buf1[256];
    ثابت حرف *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    اگر (t & VT_EXTERN)
        pstrcat(buf, buf_سائز, "extern ");
    اگر (t & VT_STATIC)
        pstrcat(buf, buf_سائز, "static ");
    اگر (t & VT_TYPEDEF)
        pstrcat(buf, buf_سائز, "typedef ");
    اگر (t & VT_INLINE)
        pstrcat(buf, buf_سائز, "inline ");
    اگر (bt != VT_PTR) {
        اگر (t & VT_RESTRICT)
            pstrcat(buf, buf_سائز, "restrict ");
        اگر (t & VT_VOLATILE)
            pstrcat(buf, buf_سائز, "volatile ");
        اگر (t & VT_CONSTANT)
            pstrcat(buf, buf_سائز, "const ");
    }
    اگر (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_سائز, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_سائز -= لڑی_لمبائی(buf);
    buf += لڑی_لمبائی(buf);

    انتخاب(bt) {
    حالت VT_VOID:
        tstr = "void";
        جاؤ جوڑو_tstr;
    حالت VT_BOOL:
        tstr = "_Bool";
        جاؤ جوڑو_tstr;
    حالت VT_BYTE:
        tstr = "char";
        جاؤ جوڑو_tstr;
    حالت VT_SHORT:
        tstr = "short";
        جاؤ جوڑو_tstr;
    حالت VT_INT:
        tstr = "int";
        جاؤ maybe_long;
    حالت VT_LLONG:
        tstr = "long long";
    maybe_long:
        اگر (t & VT_LONG)
            tstr = "long";
        اگر (!IS_ENUM(t))
            جاؤ جوڑو_tstr;
        tstr = "enum ";
        جاؤ tstruct;
    حالت VT_FLOAT:
        tstr = "float";
        جاؤ جوڑو_tstr;
    حالت VT_DOUBLE:
        tstr = "double";
        اگر (!(t & VT_LONG))
            جاؤ جوڑو_tstr;
    حالت VT_LDOUBLE:
        tstr = "long double";
    جوڑو_tstr:
        pstrcat(buf, buf_سائز, tstr);
        توڑو;
    حالت VT_STRUCT:
        tstr = "struct ";
        اگر (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_سائز, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        اگر (v >= SYM_پہلا_ANOM)
            pstrcat(buf, buf_سائز, "<anonymous>");
        ورنہ
            pstrcat(buf, buf_سائز, get_tok_str(v, تہی));
        توڑو;
    حالت VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        اگر (varstr && '*' == *varstr) {
            pstrcat(buf1, حجم(buf1), "(");
            pstrcat(buf1, حجم(buf1), varstr);
            pstrcat(buf1, حجم(buf1), ")");
        }
        pstrcat(buf1, حجم(buf1), "(");
        sa = s->اگلا;
        جب (sa != تہی) {
            حرف buf2[256];
            type_مقصد_str(buf2, حجم(buf2), &sa->type, تہی);
            pstrcat(buf1, حجم(buf1), buf2);
            sa = sa->اگلا;
            اگر (sa)
                pstrcat(buf1, حجم(buf1), ", ");
        }
        اگر (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, حجم(buf1), ", ...");
        pstrcat(buf1, حجم(buf1), ")");
        type_مقصد_str(buf, buf_سائز, &s->type, buf1);
        جاؤ no_var;
    حالت VT_PTR:
        s = type->ref;
        اگر (t & (VT_ARRAY|VT_VLA)) {
            اگر (varstr && '*' == *varstr)
                snprintf(buf1, حجم(buf1), "(%s)[%d]", varstr, s->c);
            ورنہ
                snprintf(buf1, حجم(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_مقصد_str(buf, buf_سائز, &s->type, buf1);
            جاؤ no_var;
        }
        pstrcpy(buf1, حجم(buf1), "*");
        اگر (t & VT_RESTRICT)
            pstrcat(buf1, حجم(buf1), "restrict ");
        اگر (t & VT_CONSTANT)
            pstrcat(buf1, حجم(buf1), "const ");
        اگر (t & VT_VOLATILE)
            pstrcat(buf1, حجم(buf1), "volatile ");
        اگر (varstr)
            pstrcat(buf1, حجم(buf1), varstr);
        type_مقصد_str(buf, buf_سائز, &s->type, buf1);
        جاؤ no_var;
    }
    اگر (varstr) {
        pstrcat(buf, buf_سائز, " ");
        pstrcat(buf, buf_سائز, varstr);
    }
 no_var: ;
}

ساکن خالی type_incompatibility_error(CType* st, CType* dt, ثابت حرف* fmt)
{
    حرف buf1[256], buf2[256];
    type_مقصد_str(buf1, حجم(buf1), st, تہی);
    type_مقصد_str(buf2, حجم(buf2), dt, تہی);
    tcc_error(fmt, buf1, buf2);
}

ساکن خالی type_incompatibility_warning(CType* st, CType* dt, ثابت حرف* fmt)
{
    حرف buf1[256], buf2[256];
    type_مقصد_str(buf1, حجم(buf1), st, تہی);
    type_مقصد_str(buf2, حجم(buf2), dt, تہی);
    tcc_warning(fmt, buf1, buf2);
}

ساکن صحیح pointed_سائز(CType *type)
{
    صحیح align;
    واپس type_سائز(pointed_type(type), &align);
}

ساکن اندرونی صحیح is_null_اشارہ_گر(SValue *p)
{
    اگر ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        واپس 0;
    واپس ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_سائز == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ساکن صحیح is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    اگر (s1->f.func_call != s2->f.func_call)
        واپس 0;
    اگر (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        واپس 0;
    برائے (;;) {
        اگر (!is_compatible_unqualified_types(&s1->type, &s2->type))
            واپس 0;
        اگر (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            واپس 1;
        s1 = s1->اگلا;
        s2 = s2->اگلا;
        اگر (!s1)
            واپس !s2;
        اگر (!s2)
            واپس 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ساکن صحیح compare_types(CType *type1, CType *type2, صحیح unqualified)
{
    صحیح bt1, t1, t2;

    اگر (IS_ENUM(type1->t)) {
        اگر (IS_ENUM(type2->t))
            واپس type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ورنہ اگر (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    اگر (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    اگر ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    اگر (t1 != t2)
        واپس 0;

    اگر ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            واپس 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    اگر (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        اگر (unqualified && (t1 & VT_ARRAY))
            واپس compare_types(type1, type2, 1);
        واپس is_compatible_types(type1, type2);
    } ورنہ اگر (bt1 == VT_STRUCT) {
        واپس (type1->ref == type2->ref);
    } ورنہ اگر (bt1 == VT_FUNC) {
        واپس is_compatible_func(type1, type2);
    } ورنہ {
        واپس 1;
    }
}

#تعریف_کرو CMP_OP 'C'
#تعریف_کرو سرکاؤ_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ساکن صحیح combine_types(CType *dest, SValue *op1, SValue *op2, صحیح op)
{
    CType *type1, *type2, type;
    صحیح t1, t2, bt1, bt2;
    صحیح ret = 1;

    /* for shifts, 'combine' only left operand */
    اگر (op == سرکاؤ_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = تہی;

    اگر (bt1 == VT_VOID || bt2 == VT_VOID) {
        اگر (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ورنہ اگر (bt1 == VT_PTR || bt2 == VT_PTR) {
        اگر (op == '+') {
          اگر (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ورنہ اگر (is_null_اشارہ_گر (op2)) type = *type1;
        ورنہ اگر (is_null_اشارہ_گر (op1)) type = *type2;
        ورنہ اگر (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            اگر ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ورنہ اگر (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ورنہ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            صحیح pbt1 = pt1->t & VT_BTYPE;
            صحیح pbt2 = pt2->t & VT_BTYPE;
            صحیح newquals, copied = 0;
            اگر (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                اگر (op != '?' && op != CMP_OP)
                  ret = 0;
                ورنہ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            اگر (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                اگر ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ڈالو(SYM_میدان, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                اگر (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    اگر (!copied)
                      type.ref = sym_ڈالو(SYM_میدان, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ڈالو(SYM_میدان, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        اگر (op == CMP_OP)
          type.t = VT_سائز_T;
    } ورنہ اگر (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        اگر (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ورنہ اگر (is_float(bt1) || is_float(bt2)) {
        اگر (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ورنہ اگر (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ورنہ {
            type.t = VT_FLOAT;
        }
    } ورنہ اگر (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        اگر (bt1 == VT_LLONG)
          type.t &= t1;
        اگر (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        اگر ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ورنہ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        اگر (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || ثنائی_ہندسہ_سائز(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || ثنائی_ہندسہ_سائز(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    اگر (dest)
      *dest = type;
    واپس ret;
}

/* generic gen_op: handles types problems */
ST_FUNC خالی gen_op(صحیح op)
{
    صحیح t1, t2, bt1, bt2, t;
    CType type1, combtype;
    صحیح op_class = op;

    اگر (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = سرکاؤ_OP;
    ورنہ اگر (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    اگر (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	اگر (bt2 == VT_FUNC) {
	    mk_اشارہ_گر(&vtop->type);
	    gaddrof();
	}
	اگر (bt1 == VT_FUNC) {
	    vswap();
	    mk_اشارہ_گر(&vtop->type);
	    gaddrof();
	    vswap();
	}
	جاؤ redo;
    } ورنہ اگر (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ورنہ اگر (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        صحیح align;
        اگر (op_class == CMP_OP)
            جاؤ std_op;
        /* if both pointers, then it must be the '-' op */
        اگر (bt1 == VT_PTR && bt2 == VT_PTR) {
            اگر (op != '-')
                جاؤ op_err;
            vpush_type_سائز(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ورنہ {
            /* exactly one pointer : must be '+' or '-'. */
            اگر (op != '-' && op != '+')
                جاؤ op_err;
            /* Put pointer as first operand */
            اگر (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#اگر PTR_سائز == 4
            اگر (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#اگر_ختم
            type1 = vtop[-1].type;
            vpush_type_سائز(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
            اگر (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                اگر (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_جوڑو();
            } ورنہ
#اگر_ختم
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ورنہ {
        /* floats can only be used for a few operations */
        اگر (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            جاؤ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        اگر (op_class == سرکاؤ_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        اگر (t & VT_UNSIGNED) {
            اگر (op == TOK_SAR)
                op = TOK_SHR;
            ورنہ اگر (op == '/')
                op = TOK_UDIV;
            ورنہ اگر (op == '%')
                op = TOK_UMOD;
            ورنہ اگر (op == TOK_LT)
                op = TOK_ULT;
            ورنہ اگر (op == TOK_GT)
                op = TOK_UGT;
            ورنہ اگر (op == TOK_LE)
                op = TOK_ULE;
            ورنہ اگر (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        اگر (is_float(t))
            gen_opif(op);
        ورنہ
            gen_opic(op);
        اگر (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ورنہ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    اگر (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#اگر defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64 || defined TCC_ہدف_ARM
#تعریف_کرو gen_cvt_itof1 gen_cvt_itof
#ورنہ
/* generic itof for unsigned long long case */
ساکن خالی gen_cvt_itof1(صحیح t)
{
    اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        اگر (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#اگر LDOUBLE_سائز != 8
        ورنہ اگر (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#اگر_ختم
        ورنہ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ورنہ {
        gen_cvt_itof(t);
    }
}
#اگر_ختم

#اگر defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64
#تعریف_کرو gen_cvt_ftoi1 gen_cvt_ftoi
#ورنہ
/* generic ftoi for unsigned long long case */
ساکن خالی gen_cvt_ftoi1(صحیح t)
{
    صحیح st;
    اگر (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        اگر (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#اگر LDOUBLE_سائز != 8
        ورنہ اگر (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#اگر_ختم
        ورنہ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ورنہ {
        gen_cvt_ftoi(t);
    }
}
#اگر_ختم

/* special delayed cast for char/short */
ساکن خالی force_charshort_cast(خالی)
{
    صحیح sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    صحیح dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ساکن خالی gen_cast_s(صحیح t)
{
    CType type;
    type.t = t;
    type.ref = تہی;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ساکن خالی gen_cast(CType *type)
{
    صحیح sbt, dbt, sf, df, c;
    صحیح dbt_bt, sbt_bt, ds, ss, بٹ, trunc;

    /* special delayed cast for char/short */
    اگر (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    اگر (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    اگر (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    اگر (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    اگر (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        اگر (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            جاؤ مکمل;
        }
        اگر (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        اگر (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            اگر (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ورنہ اگر (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            اگر (df) {
                اگر (sbt_bt == VT_LLONG) {
                    اگر ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ورنہ
                        vtop->c.ld = -(طویل دوہرا)-vtop->c.i;
                } ورنہ اگر(!sf) {
                    اگر ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ورنہ
                        vtop->c.ld = -(طویل دوہرا)-(uint32_t)vtop->c.i;
                }

                اگر (dbt == VT_FLOAT)
                    vtop->c.f = (اعشاری)vtop->c.ld;
                ورنہ اگر (dbt == VT_DOUBLE)
                    vtop->c.d = (دوہرا)vtop->c.ld;
            } ورنہ اگر (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ورنہ {
                اگر(sf) {
                    اگر (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ورنہ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ورنہ اگر (sbt_bt == VT_LLONG || (PTR_سائز == 8 && sbt == VT_PTR))
                    ;
                ورنہ اگر (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ورنہ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                اگر (dbt_bt == VT_LLONG || (PTR_سائز == 8 && dbt == VT_PTR))
                    ;
                ورنہ اگر (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ورنہ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    اگر (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            جاؤ مکمل;

        } ورنہ اگر (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            جاؤ مکمل;
        }

        /* cannot generate code for global or static initializers */
        اگر (nocode_wanted & ڈیٹا_ONLY_WANTED) {
            اگر (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            جاؤ مکمل;
        }

        /* non constant case: generate code */
        اگر (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            جاؤ مکمل;
        }

        اگر (sf || df) {
            اگر (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ورنہ اگر (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ورنہ {
                /* convert fp to int */
                sbt = dbt;
                اگر (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                جاؤ again; /* may need char/short cast */
            }
            جاؤ مکمل;
        }

        ds = btype_سائز(dbt_bt);
        ss = btype_سائز(sbt_bt);
        اگر (ds == 0 || ss == 0)
            جاؤ error;

        /* same size and no sign conversion needed */
        اگر (ds == ss && ds >= 4)
            جاؤ مکمل;
        اگر (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            اگر (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_سائز == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #تعریف_کرو ALLOW_SUBTYPE_ACCESS 1

        اگر (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            اگر (ds <= ss)
                جاؤ مکمل;
            /* ss <= 4 here */
            اگر (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                جاؤ مکمل; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#اگر PTR_سائز == 4
        اگر (ds == 8) {
            /* generate high word */
            اگر (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ورنہ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ورنہ اگر (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#وگرنہ_اگر PTR_سائز == 8
        اگر (ds == 8) {
            /* need to convert from 32bit to 64bit */
            اگر (sbt & VT_UNSIGNED) {
#اگر defined(TCC_ہدف_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ورنہ
                جاؤ مکمل;
#اگر_ختم
            } ورنہ {
                gen_cvt_sxtw();
                جاؤ مکمل;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ورنہ اگر (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#اگر !defined(TCC_ہدف_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#اگر_ختم
        } ورنہ {
            ss = 4;
        }
#اگر_ختم

        اگر (ds >= ss)
            جاؤ مکمل;
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64 || defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64
    اگر (ss == 4) {
        gen_cvt_csti(dbt);
        جاؤ مکمل;
    }
#اگر_ختم
        بٹ = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(بٹ);
        gen_op(TOK_SHL);
        vpushi(بٹ - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
مکمل:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC صحیح type_سائز(CType *type, صحیح *a)
{
    Sym *s;
    صحیح bt;

    bt = type->t & VT_BTYPE;
    اگر (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        واپس s->c;
    } ورنہ اگر (bt == VT_PTR) {
        اگر (type->t & VT_ARRAY) {
            صحیح ts;
            s = type->ref;
            ts = type_سائز(&s->type, a);
            اگر (s->c < 0)
                واپس s->c;
            واپس ts * s->c;
        } ورنہ {
            *a = PTR_سائز;
            واپس PTR_سائز;
        }
    } ورنہ اگر (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        واپس -1; /* incomplete enum */
    } ورنہ اگر (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        واپس LDOUBLE_سائز;
    } ورنہ اگر (bt == VT_DOUBLE || bt == VT_LLONG) {
#اگر (defined TCC_ہدف_I386 && !defined TCC_ہدف_PE) \
 || (defined TCC_ہدف_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ورنہ
        *a = 8;
#اگر_ختم
        واپس 8;
    } ورنہ اگر (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        واپس 4;
    } ورنہ اگر (bt == VT_SHORT) {
        *a = 2;
        واپس 2;
    } ورنہ اگر (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        واپس 16;
    } ورنہ {
        /* char, void, function, _Bool */
        *a = 1;
        واپس 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ساکن خالی vpush_type_سائز(CType *type, صحیح *a)
{
    اگر (type->t & VT_VLA) {
        type_سائز(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ورنہ {
        صحیح سائز = type_سائز(type, a);
        اگر (سائز < 0)
            tcc_error("unknown type size");
        vpushs(سائز);
    }
}

/* return the pointed type of t */
ساکن اندرونی CType *pointed_type(CType *type)
{
    واپس &type->ref->type;
}

ساکن خالی check_restrict_type(CType *type)
{
    جب ((type->t & VT_BTYPE) == VT_PTR) {
        اگر ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    اگر (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ساکن صحیح type_qualifiers(CType *type)
{
    جب (type->t & VT_ARRAY)
        type = pointed_type(type);
    واپس type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC خالی mk_اشارہ_گر(CType *type)
{
    Sym *s;
    s = sym_ڈالو(SYM_میدان, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ساکن صحیح is_compatible_types(CType *type1, CType *type2)
{
    واپس compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ساکن صحیح is_compatible_unqualified_types(CType *type1, CType *type2)
{
    واپس compare_types(type1,type2,1);
}

ساکن خالی cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ساکن خالی verify_تفویض_cast(CType *dt)
{
    CType *st, *type1, *type2;
    صحیح dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    اگر (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    انتخاب(dbt) {
    حالت VT_VOID:
        اگر (sbt != dbt)
            tcc_error("assignment to void expression");
        توڑو;
    حالت VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        اگر (is_null_اشارہ_گر(vtop))
            توڑو;
        /* accept implicit pointer to integer cast with warning */
        اگر (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            توڑو;
        }
        type1 = pointed_type(dt);
        اگر (sbt == VT_PTR)
            type2 = pointed_type(st);
        ورنہ اگر (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ورنہ
            جاؤ error;
        اگر (is_compatible_types(type1, type2))
            توڑو;
        برائے (qualwarn = lvl = 0;; ++lvl) {
            اگر ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            اگر (dbt != VT_PTR || sbt != VT_PTR)
                توڑو;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        اگر (!is_compatible_unqualified_types(type1, type2)) {
            اگر ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ورنہ اگر (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ورنہ {
                tcc_warning("assignment from incompatible pointer type");
                توڑو;
            }
        }
        اگر (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        توڑو;
    حالت VT_BYTE:
    حالت VT_SHORT:
    حالت VT_INT:
    حالت VT_LLONG:
        اگر (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ورنہ اگر (sbt == VT_STRUCT) {
            جاؤ case_VT_STRUCT;
        }
        /* XXX: more tests */
        توڑو;
    حالت VT_STRUCT:
    case_VT_STRUCT:
        اگر (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        توڑو;
    }
}

ساکن خالی gen_تفویض_cast(CType *dt)
{
    verify_تفویض_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC خالی vstore(خالی)
{
    صحیح sbt, dbt, ft, r, سائز, align, ثنائی_ہندسہ_سائز_2, ثنائی_ہندسہ_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_تفویض_cast(&vtop[-1].type);

    اگر (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        سائز = type_سائز(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#اگر_ختم
        vtop->type.t = VT_PTR;
        gaddrof();
        /*ماخذ*/
        vswap();
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND)
            gbound();
#اگر_ختم
        vtop->type.t = VT_PTR;
        gaddrof();

#اگر_تعریف_شدہ TCC_ہدف_NATIVE_STRUCT_COPY
        اگر (1
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#اگر_ختم
            ) {
            gen_struct_copy(سائز);
        } ورنہ
#اگر_ختم
        {
            /* type size */
            vpushi(سائز);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#اگر_تعریف_شدہ TCC_ARM_EABI
            اگر(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ورنہ اگر(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ورنہ
#اگر_ختم
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ورنہ اگر (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        ثنائی_ہندسہ_pos = ثنائی_ہندسہ_POS(ft);
        ثنائی_ہندسہ_سائز_2 = ثنائی_ہندسہ_سائز(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_نقاب;

        اگر (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2);
        اگر (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        اگر (r == VT_STRUCT) {
            store_packed_bf(ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2);
        } ورنہ {
            غیرعلامتی طویل طویل نقاب = (1ULL << ثنائی_ہندسہ_سائز_2) - 1;
            اگر (dbt != VT_BOOL) {
                /* mask source */
                اگر (dbt == VT_LLONG)
                    vpushll(نقاب);
                ورنہ
                    vpushi((غیرعلامتی)نقاب);
                gen_op('&');
            }
            /* shift source */
            vpushi(ثنائی_ہندسہ_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            اگر (dbt == VT_LLONG)
                vpushll(~(نقاب << ثنائی_ہندسہ_pos));
            ورنہ
                vpushi(~((غیرعلامتی)نقاب << ثنائی_ہندسہ_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ورنہ اگر (dbt == VT_VOID) {
        --vtop;
    } ورنہ {
            /* optimize char/short casts */
            delayed_cast = 0;
            اگر ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                اگر ((vtop->r & VT_MUSTCAST)
                    && btype_سائز(dbt) > btype_سائز(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ورنہ {
                gen_cast(&vtop[-1].type);
            }

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
            /* bound check case */
            اگر (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#اگر_ختم
            gv(RC_TYPE(dbt)); /* generate value */

            اگر (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            اگر ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = تہی;
                بھرو(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            اگر (USING_TWO_الفاظ(dbt)) {
                صحیح بھرو_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = بھرو_type;
                store(r, vtop - 1);
                vswap();
                incr_انحراف(PTR_سائز);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ورنہ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC خالی inc(صحیح post, صحیح c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    اگر (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    اگر (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ثابت حرف *پیغام)
{
    /* read the string */
    اگر (tok != TOK_STR)
        expect(پیغام);
    cstr_reset(&initstr);
    جب (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.ڈیٹا, -1);
        اگلا();
    }
    cstr_ccat(&initstr, '\0');
    واپس &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC صحیح exact_log2p1(صحیح i)
{
  صحیح ret;
  اگر (!i)
    واپس 0;
  برائے (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  اگر (i >= 1 << 4)
    ret += 4, i >>= 4;
  اگر (i >= 1 << 2)
    ret += 2, i >>= 2;
  اگر (i >= 1 << 1)
    ret++;
  واپس ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ساکن خالی parse_attribute(AttributeDef *ad)
{
    صحیح t, n;
    حرف *astr;
    AttributeDef ad_tmp;
    
redo:
    اگر (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        واپس;
    اگر (تہی == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    اگلا();
    skip('(');
    skip('(');
    جب (tok != ')') {
        اگر (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        اگلا();
        انتخاب(t) {
	حالت TOK_CLEANUP1:
	حالت TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_ڈھونڈو(tok);
	    اگر (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ورنہ اگر ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    اگلا();
            skip(')');
	    توڑو;
	}
        حالت TOK_CONSTRUCTOR1:
        حالت TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            توڑو;
        حالت TOK_DESTRUCTOR1:
        حالت TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            توڑو;
        حالت TOK_ALWAYS_INLINE1:
        حالت TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            توڑو;
        حالت TOK_SECTION1:
        حالت TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->ڈیٹا;
            n = tcc_state->nb_sections;
            ad->section = ڈھونڈو_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            توڑو;
        حالت TOK_ALIAS1:
        حالت TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->ڈیٹا;
            /* save string as token, for later */
            ad->alias_ہدف = tok_alloc_const(astr);
            skip(')');
            توڑو;
	حالت TOK_VISIBILITY1:
	حالت TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->ڈیٹا;
	    اگر (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ورنہ اگر (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ورنہ اگر (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_اندرونی;
	    ورنہ اگر (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ورنہ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            توڑو;
        حالت TOK_ALIGNED1:
        حالت TOK_ALIGNED2:
            اگر (tok == '(') {
                اگلا();
                n = اظہاریہ_const();
                اگر (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ورنہ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    اگر (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            توڑو;
        حالت TOK_PACKED1:
        حالت TOK_PACKED2:
            ad->a.packed = 1;
            توڑو;
        حالت TOK_WEAK1:
        حالت TOK_WEAK2:
            ad->a.weak = 1;
            توڑو;
        حالت TOK_NODEBUG1:
        حالت TOK_NODEBUG2:
            ad->a.nodebug = 1;
            توڑو;
        حالت TOK_USED1:
        حالت TOK_USED2:
        حالت TOK_UNUSED1:
        حالت TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            توڑو;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
        حالت TOK_PURE1:
        حالت TOK_PURE2:
	    /* ignored */
            توڑو;
        حالت TOK_NOINLINE:
	    /* ignored */
	    توڑو;
        حالت TOK_FORMAT1:
        حالت TOK_FORMAT2:
	    /* ignored */
            جاؤ skip_param;
        حالت TOK_NORETURN1:
        حالت TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            توڑو;
        حالت TOK_CDECL1:
        حالت TOK_CDECL2:
        حالت TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            توڑو;
        حالت TOK_STDCALL1:
        حالت TOK_STDCALL2:
        حالت TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            توڑو;
#اگر_تعریف_شدہ TCC_ہدف_I386
        حالت TOK_REGPARM1:
        حالت TOK_REGPARM2:
            skip('(');
            n = اظہاریہ_const();
            اگر (n > 3) 
                n = 3;
            ورنہ اگر (n < 0)
                n = 0;
            اگر (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            توڑو;
        حالت TOK_FASTCALL1:
        حالت TOK_FASTCALL2:
        حالت TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            توڑو;
        حالت TOK_THISCALL1:
        حالت TOK_THISCALL2:
        حالت TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            توڑو;
#اگر_ختم
        حالت TOK_منوال:
            skip('(');
            انتخاب(tok) {
                حالت TOK_منوال_DI:
                    ad->attr_منوال = VT_LLONG + 1;
                    توڑو;
                حالت TOK_منوال_QI:
                    ad->attr_منوال = VT_BYTE + 1;
                    توڑو;
                حالت TOK_منوال_HI:
                    ad->attr_منوال = VT_SHORT + 1;
                    توڑو;
                حالت TOK_منوال_SI:
                حالت TOK_منوال_لفظ:
                    ad->attr_منوال = VT_INT + 1;
                    توڑو;
                طےشدہ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, تہی));
                    توڑو;
            }
            اگلا();
            skip(')');
            توڑو;
        حالت TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            توڑو;
        حالت TOK_NODECORATE:
            ad->a.nodecorate = 1;
            توڑو;
        حالت TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            توڑو;
        طےشدہ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, تہی));
            /* skip parameters */
skip_param:
            اگر (tok == '(') {
                صحیح parenthesis = 0;
                کرو {
                    اگر (tok == '(') 
                        parenthesis++;
                    ورنہ اگر (tok == ')') 
                        parenthesis--;
                    اگلا();
                } جب (parenthesis && tok != -1);
            }
            توڑو;
        }
        اگر (tok != ',')
            توڑو;
        اگلا();
    }
    skip(')');
    skip(')');
    جاؤ redo;
}

ساکن Sym * ڈھونڈو_میدان (CType *type, صحیح v, صحیح *cumofs)
{
    Sym *s = type->ref;
    صحیح v1 = v | SYM_میدان;
    اگر (!(v & SYM_میدان)) { /* top-level call */
        اگر ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        اگر (v < TOK_UIDENT)
            expect("field name");
        اگر (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    جب ((s = s->اگلا) != تہی) {
        اگر (s->v == v1) {
            *cumofs = s->c;
            واپس s;
        }
        اگر ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_پہلا_ANOM | SYM_میدان)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = ڈھونڈو_میدان (&s->type, v1, cumofs);
            اگر (ret) {
                *cumofs += s->c;
                واپس ret;
            }
        }
    }
    اگر (!(v & SYM_میدان))
        tcc_error("field not found: %s", get_tok_str(v, تہی));
    واپس s;
}

ساکن خالی check_fields (CType *type, صحیح check)
{
    Sym *s = type->ref;

    جب ((s = s->اگلا) != تہی) {
        صحیح v = s->v & ~SYM_میدان;
        اگر (v < SYM_پہلا_ANOM) {
            TokenSym *ts = جدول_ident[v - TOK_IDENT];
            اگر (check && (ts->tok & SYM_میدان))
                tcc_error("duplicate member '%s'", get_tok_str(v, تہی));
            ts->tok ^= SYM_میدان;
        } ورنہ اگر ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ساکن خالی struct_layout(CType *type, AttributeDef *ad)
{
    صحیح سائز, align, maxalign, انحراف, c, ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2;
    صحیح packed, a, bt, prevbt, پچھلا_ثنائی_ہندسہ_سائز;
    صحیح pcc = !tcc_state->ms_bitfields;
    صحیح pragma_pack = *tcc_state->pack_ڈھیر_ptr;
    Sym *f;

    maxalign = 1;
    انحراف = 0;
    c = 0;
    ثنائی_ہندسہ_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    پچھلا_ثنائی_ہندسہ_سائز = 0;

//#define BF_DEBUG

    برائے (f = type->ref->اگلا; f; f = f->اگلا) {
        اگر (f->type.t & VT_BITFIELD)
            ثنائی_ہندسہ_سائز_2 = ثنائی_ہندسہ_سائز(f->type.t);
        ورنہ
            ثنائی_ہندسہ_سائز_2 = -1;
        سائز = type_سائز(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        اگر (pcc && ثنائی_ہندسہ_سائز_2 == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ورنہ {
            /* in pcc mode, attribute packed overrides if set. */
            اگر (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            اگر (pragma_pack) {
                packed = 1;
                اگر (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                اگر (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        اگر (a)
            align = a;

        اگر (type->ref->type.t == VT_UNION) {
	    اگر (pcc && ثنائی_ہندسہ_سائز_2 >= 0)
	        سائز = (ثنائی_ہندسہ_سائز_2 + 7) >> 3;
	    انحراف = 0;
	    اگر (سائز > c)
	        c = سائز;

	} ورنہ اگر (ثنائی_ہندسہ_سائز_2 < 0) {
            اگر (pcc)
                c += (ثنائی_ہندسہ_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    انحراف = c;
	    اگر (سائز > 0)
	        c += سائز;
	    ثنائی_ہندسہ_pos = 0;
	    prevbt = VT_STRUCT;
	    پچھلا_ثنائی_ہندسہ_سائز = 0;

	} ورنہ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            اگر (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                اگر (ثنائی_ہندسہ_سائز_2 == 0) {
            new_میدان:
		    c = (c + ((ثنائی_ہندسہ_pos + 7) >> 3) + align - 1) & -align;
		    ثنائی_ہندسہ_pos = 0;
                } ورنہ اگر (f->a.aligned) {
                    جاؤ new_میدان;
                } ورنہ اگر (!packed) {
                    صحیح a8 = align * 8;
	            صحیح ofs = ((c * 8 + ثنائی_ہندسہ_pos) % a8 + ثنائی_ہندسہ_سائز_2 + a8 - 1) / a8;
                    اگر (ofs > سائز / align)
                        جاؤ new_میدان;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                اگر (سائز == 8 && ثنائی_ہندسہ_سائز_2 <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, سائز = 4;

                جب (ثنائی_ہندسہ_pos >= align * 8)
                    c += align, ثنائی_ہندسہ_pos -= align * 8;
                انحراف = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		اگر (f->v & SYM_پہلا_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ورنہ {
		bt = f->type.t & VT_BTYPE;
		اگر ((ثنائی_ہندسہ_pos + ثنائی_ہندسہ_سائز_2 > سائز * 8)
                    || (ثنائی_ہندسہ_سائز_2 > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    انحراف = c;
		    ثنائی_ہندسہ_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    اگر (ثنائی_ہندسہ_سائز_2 || پچھلا_ثنائی_ہندسہ_سائز)
		        c += سائز;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		اگر (ثنائی_ہندسہ_سائز_2 == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                پچھلا_ثنائی_ہندسہ_سائز = ثنائی_ہندسہ_سائز_2;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_سرکاؤ))
		        | (ثنائی_ہندسہ_pos << VT_STRUCT_سرکاؤ);
	    ثنائی_ہندسہ_pos += ثنائی_ہندسہ_سائز_2;
	}
	اگر (align > maxalign)
	    maxalign = align;

#اگر_تعریف_شدہ BF_DEBUG
	لکھو("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_میدان, تہی), انحراف, سائز, align);
	اگر (f->type.t & VT_BITFIELD) {
	    لکھو(" pos %-2d bits %-2d",
                    ثنائی_ہندسہ_POS(f->type.t),
                    ثنائی_ہندسہ_سائز(f->type.t)
                    );
	}
	لکھو("\n");
#اگر_ختم

        f->c = انحراف;
	f->r = 0;
    }

    اگر (pcc)
        c += (ثنائی_ہندسہ_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    اگر (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    اگر (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        اگر (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#اگر_تعریف_شدہ BF_DEBUG
    لکھو("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#اگر_ختم

    /* check whether we can access bitfields by their type */
    برائے (f = type->ref->اگلا; f; f = f->اگلا) {
        صحیح s, px, cx, c0;
        CType t;

        اگر (0 == (f->type.t & VT_BITFIELD))
            جاری;
        f->type.ref = f;
        f->auxtype = -1;
        ثنائی_ہندسہ_سائز_2 = ثنائی_ہندسہ_سائز(f->type.t);
        اگر (ثنائی_ہندسہ_سائز_2 == 0)
            جاری;
        ثنائی_ہندسہ_pos = ثنائی_ہندسہ_POS(f->type.t);
        سائز = type_سائز(&f->type, &align);

        اگر (ثنائی_ہندسہ_pos + ثنائی_ہندسہ_سائز_2 <= سائز * 8 && f->c + سائز <= c
#اگر_تعریف_شدہ TCC_ہدف_ARM
            && !(f->c & (align - 1))
#اگر_ختم
            )
            جاری;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        برائے (;;) {
            px = f->c * 8 + ثنائی_ہندسہ_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            اگر (c0 == cx)
                توڑو;
            s = (px + ثنائی_ہندسہ_سائز_2 + 7) >> 3;
            اگر (s > 4) {
                t.t = VT_LLONG;
            } ورنہ اگر (s > 2) {
                t.t = VT_INT;
            } ورنہ اگر (s > 1) {
                t.t = VT_SHORT;
            } ورنہ {
                t.t = VT_BYTE;
            }
            s = type_سائز(&t, &align);
            c0 = cx;
        }

        اگر (px + ثنائی_ہندسہ_سائز_2 <= s * 8 && cx + s <= c
#اگر_تعریف_شدہ TCC_ہدف_ARM
            && !(cx & (align - 1))
#اگر_ختم
            ) {
            /* update offset and bit position */
            f->c = cx;
            ثنائی_ہندسہ_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_سرکاؤ))
		        | (ثنائی_ہندسہ_pos << VT_STRUCT_سرکاؤ);
            اگر (s != سائز)
                f->auxtype = t.t;
#اگر_تعریف_شدہ BF_DEBUG
            لکھو("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_میدان, تہی),
                cx, s, align, px, ثنائی_ہندسہ_سائز_2);
#اگر_ختم
        } ورنہ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#اگر_تعریف_شدہ BF_DEBUG
            لکھو("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_میدان, تہی));
#اگر_ختم
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ساکن صحیح اندر_range(طویل طویل n, صحیح t)
{
    غیرعلامتی طویل طویل m = (1ULL << (btype_سائز(t & VT_BTYPE) * 8 - 1)) - 1;
    اگر (t & VT_UNSIGNED)
        واپس n <= (m << 1) + 1;
    واپس n >= -(طویل طویل)m - 1 && n <= (طویل طویل)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ساکن خالی struct_decl(CType *type, صحیح u)
{
    صحیح v, c, سائز, align, flexible;
    صحیح ثنائی_ہندسہ_سائز_2, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, حجم ad);
    اگلا();
    parse_attribute(&ad);

    v = 0;
    اگر (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, اگلا();

    bt = ut = 0;
    اگر (u == VT_ENUM) {
        ut = VT_INT;
        اگر (tok == ':') { /* C2x enum : <type> ... */
            اگلا();
            اگر (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    اگر (v) {
        /* struct already defined ? return it */
        s = struct_ڈھونڈو(v);
        اگر (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            اگر (u == s->type.t)
                جاؤ do_decl;
            اگر (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                جاؤ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, تہی));
        }
    } ورنہ {
        اگر (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = تہی;
    /* we put an undefined size for struct/union */
    s = sym_ڈالو(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    اگر (tok == '{') {
        اگلا();
        اگر (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->اگلا;
        اگر (u == VT_ENUM) {
            طویل طویل ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            اگر (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            برائے(;;) {
                v = tok;
                اگر (v < TOK_UIDENT)
                    expect("identifier");
                اگلا();
                اگر (tok == '=') {
                    اگلا();
		    ll = اظہاریہ_const64();
                }
                اگر (bt && !اندر_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, تہی));
                ss = sym_ڈالو(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->اگلا;
                اگر (ll < nl)
                    nl = ll;
                اگر (ll > pl)
                    pl = ll;
                اگر (tok != ',')
                    توڑو;
                اگلا();
                ll++;
                /* NOTE: we accept a trailing comma */
                اگر (tok == '}')
                    توڑو;
            }
            skip('}');

            اگر (bt) {
                t.t = bt;
                s->c = 2;
                جاؤ enum_مکمل;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            اگر (nl >= 0) {
                اگر (pl != (غیرعلامتی)pl)
                    t.t = (LONG_سائز==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ورنہ اگر (pl != (صحیح)pl || nl != (صحیح)nl)
                t.t = (LONG_سائز==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            برائے (ss = s->اگلا; ss; ss = ss->اگلا) {
                ll = ss->enum_val;
                اگر (ll == (صحیح)ll) /* default is int if it fits */
                    جاری;
                اگر (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    اگر (ll == (غیرعلامتی)ll)
                        جاری;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_سائز==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_مکمل:
            s->type.t = type->t = t.t | VT_ENUM;

        } ورنہ {
            c = 0;
            flexible = 0;
            جب (tok != '}') {
                اگر (!parse_btype(&btype, &ad1, 0)) {
                    اگر (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        جاری;
                    }
		    skip(';');
		    جاری;
		}
                جب (1) {
		    اگر (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, تہی));
                    ثنائی_ہندسہ_سائز_2 = -1;
                    v = 0;
                    type1 = btype;
                    اگر (tok != ':') {
			اگر (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_براہ_راست);
                        اگر (v == 0) {
                    	    اگر ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ورنہ {
				صحیح v = btype.ref->v;
				اگر ((v & ~SYM_STRUCT) < SYM_پہلا_ANOM) {
				    اگر (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        اگر (type_سائز(&type1, &align) < 0) {
			    اگر ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ورنہ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, تہی));
                        }
                        اگر ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, تہی));
                    }
                    اگر (tok == ':') {
                        اگلا();
                        ثنائی_ہندسہ_سائز_2 = اظہاریہ_const();
                        /* XXX: handle v = 0 case for messages */
                        اگر (ثنائی_ہندسہ_سائز_2 < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, تہی));
                        اگر (v && ثنائی_ہندسہ_سائز_2 == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, تہی));
			parse_attribute(&ad1);
                    }
                    سائز = type_سائز(&type1, &align);
                    اگر (ثنائی_ہندسہ_سائز_2 >= 0) {
                        bt = type1.t & VT_BTYPE;
                        اگر (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = سائز * 8;
                        اگر (ثنائی_ہندسہ_سائز_2 > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, تہی));
                        } ورنہ اگر (ثنائی_ہندسہ_سائز_2 == bsize
				    && !*tcc_state->pack_ڈھیر_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ورنہ اگر (ثنائی_ہندسہ_سائز_2 == 64) {
                            tcc_error("field width 64 not implemented");
                        } ورنہ {
                            type1.t = (type1.t & ~VT_STRUCT_نقاب)
                                | VT_BITFIELD
                                | ((غیرعلامتی)ثنائی_ہندسہ_سائز_2 << (VT_STRUCT_سرکاؤ + 6));
                        }
                    }
                    اگر (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    اگر (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 ثنائی_ہندسہ_سائز_2 >= 0)) {
		        v = anon_sym++;
		    }
                    اگر (v) {
                        ss = sym_ڈالو(v | SYM_میدان, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->اگلا;
                    }
                    اگر (tok == ';' || tok == TOK_EOF)
                        توڑو;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            اگر (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        اگر (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

ساکن خالی sym_مقصد_attr(AttributeDef *ad, Sym *s)
{
    ملاؤ_symattr(&ad->a, &s->a);
    ملاؤ_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ساکن خالی parse_btype_qualify(CType *type, صحیح qualifiers)
{
    جب (type->t & VT_ARRAY) {
        type->ref = sym_ڈالو(SYM_میدان, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    اگر (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ساکن صحیح parse_btype(CType *type, AttributeDef *ad, صحیح ignore_label)
{
    صحیح t, u, bt, st, type_ملا, typespec_ملا, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, حجم(AttributeDef));
    type_ملا = 0;
    typespec_ملا = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = تہی;

    جب(1) {
        انتخاب(tok) {
        حالت TOK_EXTENSION:
            /* currently, we really ignore extension */
            اگلا();
            جاری;

            /* basic types */
        حالت TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            اگلا();
        basic_type1:
            اگر (u == VT_SHORT || u == VT_LONG) {
                اگر (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ورنہ {
                اگر (bt != -1 || (st != -1 && u != VT_INT))
                    جاؤ tmbt;
                اگر ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    جاؤ tmbt;
                bt = u;
            }
            اگر (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_ملا = 1;
            توڑو;
        حالت TOK_VOID:
            u = VT_VOID;
            جاؤ basic_type;
        حالت TOK_SHORT:
            u = VT_SHORT;
            جاؤ basic_type;
        حالت TOK_INT:
            u = VT_INT;
            جاؤ basic_type;
        حالت TOK_ALIGNAS:
            { صحیح n;
              AttributeDef ad1;
              اگلا();
              skip('(');
              memset(&ad1, 0, حجم(AttributeDef));
              اگر (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  اگر (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ورنہ
                    type_سائز(&type1, &n);
              } ورنہ {
                  n = اظہاریہ_const();
                  اگر (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            جاری;
        حالت TOK_LONG:
            اگر ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ورنہ اگر ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ورنہ {
                u = VT_LONG;
                جاؤ basic_type;
            }
            اگلا();
            توڑو;
        حالت TOK_BOOL:
            u = VT_BOOL;
            جاؤ basic_type;
        حالت TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        حالت TOK_FLOAT:
            u = VT_FLOAT;
            جاؤ basic_type;
        حالت TOK_DOUBLE:
            اگر ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ورنہ {
                u = VT_DOUBLE;
                جاؤ basic_type;
            }
            اگلا();
            توڑو;
        حالت TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            جاؤ basic_type1;
        حالت TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            جاؤ basic_type2;
        حالت TOK_UNION:
            struct_decl(&type1, VT_UNION);
            جاؤ basic_type2;

            /* type modifiers */
        حالت TOK__Atomic:
            اگلا();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            اگر (tok == '(') {
                parse_اظہاریہ_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                اگر (type1.ref)
                    sym_مقصد_attr(ad, type1.ref);
                جاؤ basic_type2;
            }
            توڑو;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            اگلا();
            توڑو;
        حالت TOK_VOLATILE1:
        حالت TOK_VOLATILE2:
        حالت TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            اگلا();
            توڑو;
        حالت TOK_SIGNED1:
        حالت TOK_SIGNED2:
        حالت TOK_SIGNED3:
            اگر ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            اگلا();
            typespec_ملا = 1;
            توڑو;
        حالت TOK_RESTRICT1:
        حالت TOK_RESTRICT2:
        حالت TOK_RESTRICT3:
            t |= VT_RESTRICT;
            اگلا();
            توڑو;
        حالت TOK_رجسٹر:
        حالت TOK_AUTO:
            اگلا();
            توڑو;
        حالت TOK_UNSIGNED:
            اگر ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            اگلا();
            typespec_ملا = 1;
            توڑو;

            /* storage */
        حالت TOK_EXTERN:
            g = VT_EXTERN;
            جاؤ storage;
        حالت TOK_STATIC:
            g = VT_STATIC;
            جاؤ storage;
        حالت TOK_TYPEDEF:
            g = VT_TYPEDEF;
            جاؤ storage;
       storage:
            اگر (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            اگلا();
            توڑو;
        حالت TOK_INLINE1:
        حالت TOK_INLINE2:
        حالت TOK_INLINE3:
            t |= VT_INLINE;
            اگلا();
            توڑو;
        حالت TOK_NORETURN3:
            اگلا();
            ad->f.func_noreturn = 1;
            توڑو;
            /* GNUC attribute */
        حالت TOK_ATTRIBUTE1:
        حالت TOK_ATTRIBUTE2:
            parse_attribute(ad);
            اگر (ad->attr_منوال) {
                u = ad->attr_منوال -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            جاری;
            /* GNUC typeof */
        حالت TOK_TYPEOF1:
        حالت TOK_TYPEOF2:
        حالت TOK_TYPEOF3:
            اگلا();
            parse_اظہاریہ_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            اگر (type1.ref) {
                sym_مقصد_attr(ad, type1.ref);
                اگر (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            جاؤ basic_type2;
        حالت TOK_THREAD_LOCAL:
        حالت TOK___thread:
            اگر (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            اگلا();
            توڑو;
        طےشدہ:
            اگر (typespec_ملا)
                جاؤ the_انتہا;
            s = sym_ڈھونڈو(tok);
            اگر (!s || !(s->type.t & VT_TYPEDEF))
                جاؤ the_انتہا;

            n = tok, اگلا();
            اگر (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                جاؤ the_انتہا;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            اگر (t)
                parse_btype_qualify(type, t);
            t = type->t;
            اگر (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_مقصد_attr(ad, s);
            typespec_ملا = 1;
            st = bt = -2;
            توڑو;
        }
        type_ملا = 1;
    }
the_انتہا:
    اگر (tcc_state->char_is_unsigned) {
        اگر ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    اگر (bt == VT_LONG)
        t |= LONG_سائز == 8 ? VT_LLONG : VT_INT;
#اگر_تعریف_شدہ TCC_USING_DOUBLE_FOR_LDOUBLE
    اگر (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#اگر_ختم
    type->t = t;
    check_restrict_type(type);
    واپس type_ملا;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ساکن اندرونی خالی convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    اگر ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_اشارہ_گر(pt);
    }
}

/* apply the conversions required for an expression value */
ساکن اندرونی خالی convert_عبارت_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(خالی)
{
    skip('(');
    واپس parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ساکن صحیح asm_label_instr(خالی)
{
    صحیح v;
    حرف *astr;

    اگلا();
    astr = parse_asm_str()->ڈیٹا;
    skip(')');
#اگر_تعریف_شدہ ASM_DEBUG
    لکھو("asm_alias: \"%s\"\n", astr);
#اگر_ختم
    v = tok_alloc_const(astr);
    واپس v;
}

ساکن صحیح post_type(CType *type, AttributeDef *ad, صحیح storage, صحیح td)
{
    صحیح n, l, t1, arg_سائز, align;
    Sym **plast, *s, *پہلا, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = تہی;
    صحیح *vla_array_str = تہی;

    اگر (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        اگلا();
	اگر (TYPE_براہ_راست == (td & (TYPE_براہ_راست|TYPE_ABSTRACT)))
	  واپس 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ڈھیر ? &local_ڈھیر : &global_ڈھیر;
        ++local_scope;
        sr = sym_push2(ps, SYM_میدان, 0, 0);

	اگر (tok == ')')
	  l = 0;
	ورنہ اگر (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ورنہ اگر (td & (TYPE_براہ_راست|TYPE_ABSTRACT)) {
            sym_نکالو(ps, sr->پچھلا, 0);
            --local_scope;
	    ملاؤ_attr (ad, &ad1);
	    واپس 0;
	} ورنہ
	  l = FUNC_OLD;

        پہلا = تہی;
        plast = &پہلا;
        arg_سائز = 0;
        اگر (l) {
            برائے(;;) {
                /* read param name and compute offset */
                اگر (l != FUNC_OLD) {
                    اگر ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        توڑو;
                    type_decl(&pt, &ad1, &n, TYPE_براہ_راست | TYPE_ABSTRACT | TYPE_PARAM);
                    اگر ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    اگر (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_میدان;
                } ورنہ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = تہی;
                    اگلا();
                }
                اگر (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_سائز += (type_سائز(&pt, &align) + PTR_سائز - 1) / PTR_سائز;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ڈالو(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->اگلا;
                اگر (tok == ')')
                    توڑو;
                skip(',');
                اگر (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    اگلا();
                    توڑو;
                }
		اگر (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ورنہ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        اگر (tok == '[') {
            اگلا();
            skip(']'); /* only handle simple "[]" */
            mk_اشارہ_گر(type);
        }
        ad->f.func_دلائل = arg_سائز;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->اگلا = پہلا;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_نکالو(ps, sr, 1);
        --local_scope;

    } ورنہ اگر (tok == '[') {
	صحیح saved_nocode_wanted = nocode_wanted;
        صحیح array_qualifiers = 0;
        /* array definition */
        اگلا();
        n = -1;
        t1 = 0;
        اگر (td & TYPE_PARAM) جب (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    انتخاب (tok) {
	    حالت TOK_CONST1: حالت TOK_CONST2: حالت TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		اگلا();
		جاری;
	    حالت TOK_VOLATILE1: حالت TOK_VOLATILE2: حالت TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		اگلا();
		جاری;
	    حالت TOK_RESTRICT1: حالت TOK_RESTRICT2: حالت TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		اگلا();
		جاری;
	    حالت TOK_STATIC:
	    حالت '*':
		اگلا();
		جاری;
	    طےشدہ:
		توڑو;
	    }
            اگر (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_بلاک(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		اگلا();
	        gexpr();
		انتہا_macro();
		اگلا();
		جاؤ check;
            }
            توڑو;

	} ورنہ اگر (tok != ']') {
            اگر (!local_ڈھیر || (storage & VT_STATIC))
                vpushi(اظہاریہ_const());
            ورنہ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                اگر (n < 0)
                    tcc_error("invalid array size");
            } ورنہ {
                اگر (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_براہ_راست|TYPE_ABSTRACT)) | TYPE_NEST);

        اگر ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        اگر ((type->t & VT_BTYPE) == VT_VOID
            || type_سائز(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        اگر (t1 & VT_VLA) {
            اگر (n < 0) {
		اگر  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ورنہ {
                loc -= type_سائز(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_سائز(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        اگر (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ڈالو(SYM_میدان, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        اگر (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    اگر ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ورنہ
	        tok_str_free_str(vla_array_str);
	}
    }
    واپس 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ساکن CType *type_decl(CType *type, AttributeDef *ad, صحیح *v, صحیح td)
{
    CType *post, *ret;
    صحیح qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    جب (tok == '*') {
        qualifiers = 0;
    redo:
        اگلا();
        انتخاب(tok) {
        حالت TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            جاؤ redo;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            جاؤ redo;
        حالت TOK_VOLATILE1:
        حالت TOK_VOLATILE2:
        حالت TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            جاؤ redo;
        حالت TOK_RESTRICT1:
        حالت TOK_RESTRICT2:
        حالت TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            جاؤ redo;
	/* XXX: clarify attribute handling */
	حالت TOK_ATTRIBUTE1:
	حالت TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    توڑو;
        }
        mk_اشارہ_گر(type);
        type->t |= qualifiers;
	اگر (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    اگر (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	اگر (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ورنہ
	  جاؤ abstract;
    } ورنہ اگر (tok >= TOK_IDENT && (td & TYPE_براہ_راست)) {
	/* type identifier */
	*v = tok;
	اگلا();
    } ورنہ {
  abstract:
	اگر (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_براہ_راست|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    واپس ret;
}

/* indirection with full error checking and bound check */
ST_FUNC خالی indir(خالی)
{
    اگر ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        اگر ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            واپس;
        expect("pointer");
    }
    اگر (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    اگر (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#اگر_ختم
    }
}

/* pass a parameter to a function and do type checking and casting */
ساکن خالی gfunc_param_typed(Sym *func, Sym *arg)
{
    صحیح func_type;
    CType type;

    func_type = func->f.func_type;
    اگر (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == تہی)) {
        /* default casting : only need to convert float to double */
        اگر ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ورنہ اگر (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ورنہ اگر (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ورنہ اگر (arg == تہی) {
        tcc_error("too many arguments to function");
    } ورنہ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_تفویض_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ساکن خالی اظہاریہ_type(CType *type, خالی (*اظہاریہ_fn)(خالی))
{
    nocode_wanted++;
    اظہاریہ_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ساکن خالی parse_اظہاریہ_type(CType *type)
{
    صحیح n;
    AttributeDef ad;

    skip('(');
    اگر (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ورنہ {
        اظہاریہ_type(type, gexpr);
    }
    skip(')');
}

ساکن خالی parse_type(CType *type)
{
    AttributeDef ad;
    صحیح n;

    اگر (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ساکن خالی parse_builtin_params(صحیح nc, ثابت حرف *دلائل)
{
    حرف c, sep = '(';
    CType type;
    اگر (nc)
        nocode_wanted++;
    اگلا();
    اگر (*دلائل == 0)
	skip(sep);
    جب ((c = *دلائل++)) {
	skip(sep);
	sep = ',';
        اگر (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    جاری;
        }
        اظہاریہ_eq();
        type.ref = تہی;
        type.t = 0;
	انتخاب (c) {
	    حالت 'e':
		جاری;
	    حالت 'V':
                type.t = VT_CONSTANT;
	    حالت 'v':
                type.t |= VT_VOID;
                mk_اشارہ_گر (&type);
                توڑو;
	    حالت 'S':
                type.t = VT_CONSTANT;
	    حالت 's':
                type.t |= char_type.t;
                mk_اشارہ_گر (&type);
                توڑو;
	    حالت 'i':
                type.t = VT_INT;
                توڑو;
	    حالت 'l':
                type.t = VT_سائز_T;
                توڑو;
	    طےشدہ:
                توڑو;
	}
        gen_تفویض_cast(&type);
    }
    skip(')');
    اگر (nc)
        nocode_wanted--;
}

ساکن خالی parse_atomic(صحیح atok)
{
    صحیح سائز, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    حرف buf[40];
    ساکن ثابت حرف *ثابت templates[] = {
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
    ثابت حرف *سانچہ = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = تہی;
    سائز = 0; /* pacify compiler */
    اگلا();
    skip('(');
    برائے (arg = 0;;) {
        اظہاریہ_eq();
        انتخاب (سانچہ[arg]) {
        حالت 'a':
        حالت 'A':
            atom_ptr = &vtop->type;
            اگر ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            سائز = type_سائز(atom, &align);
            اگر (سائز > 8
                || (سائز & (سائز - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_سائز(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            توڑو;

        حالت 'p':
            اگر ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_سائز(pointed_type(&vtop->type), &align) != سائز)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_تفویض_cast(atom_ptr);
            توڑو;
        حالت 'v':
            gen_تفویض_cast(atom);
            توڑو;
        حالت 'l':
            indir();
            gen_تفویض_cast(atom);
            توڑو;
        حالت 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            توڑو;
        حالت 'm':
            gen_تفویض_cast(&int_type);
            توڑو;
        حالت 'b':
            ct.t = VT_BOOL;
            gen_تفویض_cast(&ct);
            توڑو;
        }
        اگر ('.' == سانچہ[++arg])
            توڑو;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    انتخاب (سانچہ[arg + 1]) {
    حالت 'b':
        ct.t = VT_BOOL;
        توڑو;
    حالت 'v':
        ct = *atom;
        توڑو;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), سائز);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    اگر (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#اگر_تعریف_شدہ PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ورنہ
        vtop->type.t = VT_INT;
#اگر_ختم
    }
    gen_cast(&ct);
    اگر (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC خالی unary(خالی)
{
    صحیح n, t, align, سائز, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    اگر (debug_modes)
        tcc_debug_سطر(tcc_state), tcc_tcov_check_سطر (tcc_state, 1);

    type.ref = تہی;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_اگلا:
    انتخاب(tok) {
    حالت TOK_EXTENSION:
        اگلا();
        جاؤ tok_اگلا;
    حالت TOK_LCHAR:
#اگر_تعریف_شدہ TCC_ہدف_PE
        t = VT_SHORT|VT_UNSIGNED;
        جاؤ ڈالو_tokc;
#اگر_ختم
    حالت TOK_CINT:
    حالت TOK_CCHAR: 
	t = VT_INT;
 ڈالو_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        اگلا();
        توڑو;
    حالت TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        جاؤ ڈالو_tokc;
    حالت TOK_CLLONG:
        t = VT_LLONG;
	جاؤ ڈالو_tokc;
    حالت TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	جاؤ ڈالو_tokc;
    حالت TOK_CFLOAT:
        t = VT_FLOAT;
	جاؤ ڈالو_tokc;
    حالت TOK_CDOUBLE:
        t = VT_DOUBLE;
	جاؤ ڈالو_tokc;
    حالت TOK_CLDOUBLE:
#اگر_تعریف_شدہ TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ورنہ
        t = VT_LDOUBLE;
#اگر_ختم
	جاؤ ڈالو_tokc;
    حالت TOK_CLONG:
        t = (LONG_سائز == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	جاؤ ڈالو_tokc;
    حالت TOK_CULONG:
        t = (LONG_سائز == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	جاؤ ڈالو_tokc;
    حالت TOK___FUNCTION__:
        اگر (!gnu_ext)
            جاؤ tok_identifier;
        /* fall thru */
    حالت TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.سائز = tokcstr.سائز;
        tokc.str.ڈیٹا = tokcstr.ڈیٹا;
        جاؤ case_TOK_STR;
    حالت TOK_LSTR:
#اگر_تعریف_شدہ TCC_ہدف_PE
        t = VT_SHORT | VT_UNSIGNED;
#ورنہ
        t = VT_INT;
#اگر_ختم
        جاؤ str_init;
    حالت TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        اگر (tcc_state->warn_write_لڑیاں & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_اشارہ_گر(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, حجم(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        توڑو;
    حالت TOK_SOTYPE:
    حالت '(':
        t = tok;
        اگلا();
        /* cast ? */
        اگر (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            اگر (tok == '{') {
                    /* data is allocated locally by default */
                اگر (global_اظہاریہ)
                    r = VT_CONST;
                ورنہ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                اگر (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, حجم(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ورنہ اگر (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                واپس;
            } ورنہ {
                unary();
                gen_cast(&type);
            }
        } ورنہ اگر (tok == '{') {
	    صحیح saved_nocode_wanted = nocode_wanted;
            اگر (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            اگر (0 == local_scope)
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
            بلاک(STMT_اظہاریہ);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            اگر (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ورنہ {
            gexpr();
            skip(')');
        }
        توڑو;
    حالت '*':
        اگلا();
        unary();
        indir();
        توڑو;
    حالت '&':
        اگلا();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        اگر ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        اگر (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_اشارہ_گر(&vtop->type);
        gaddrof();
        توڑو;
    حالت '!':
        اگلا();
        unary();
        gen_test_zero(TOK_EQ);
        توڑو;
    حالت '~':
        اگلا();
        unary();
        vpushi(-1);
        gen_op('^');
        توڑو;
    حالت '+':
        اگلا();
        unary();
        اگر ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	اگر (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        توڑو;
    حالت TOK_SIZEOF:
    حالت TOK_ALIGNOF1:
    حالت TOK_ALIGNOF2:
    حالت TOK_ALIGNOF3:
        t = tok;
        اگلا();
        اگر (tok == '(')
            tok = TOK_SOTYPE;
        اظہاریہ_type(&type, unary);
        اگر (t == TOK_SIZEOF) {
            vpush_type_سائز(&type, &align);
            gen_cast_s(VT_سائز_T);
        } ورنہ {
            type_سائز(&type, &align);
            s = تہی;
            اگر (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            اگر (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        توڑو;

    حالت TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        توڑو;
    حالت TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        توڑو;
    حالت TOK_builtin_انتخاب_اظہاریہ:
	{
	    int64_t c;
	    اگلا();
	    skip('(');
	    c = اظہاریہ_const64();
	    skip(',');
	    اگر (!c) {
		nocode_wanted++;
	    }
	    اظہاریہ_eq();
	    اگر (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    اگر (c) {
		nocode_wanted++;
	    }
	    اظہاریہ_eq();
	    اگر (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        توڑو;
    حالت TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        توڑو;
    حالت TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        رمز_OFF();
        توڑو;
    حالت TOK_builtin_چوکھٹا_پتہ:
    حالت TOK_builtin_return_پتہ:
        {
            صحیح tok1 = tok;
            صحیح level;
            اگلا();
            skip('(');
            level = اظہاریہ_const();
            اگر (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_اشارہ_گر(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            جب (level--) {
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
                vpushi(2*PTR_سائز);
                gen_op('-');
#اگر_ختم
                mk_اشارہ_گر(&vtop->type);
                indir();                    /* -> parent frame */
            }
            اگر (tok1 == TOK_builtin_return_پتہ) {
                // assume return address is just above frame pointer on stack
#اگر_تعریف_شدہ TCC_ہدف_ARM
                vpushi(2*PTR_سائز);
                gen_op('+');
#وگرنہ_اگر defined TCC_ہدف_RISCV64
                vpushi(PTR_سائز);
                gen_op('-');
#ورنہ
                vpushi(PTR_سائز);
                gen_op('+');
#اگر_ختم
                mk_اشارہ_گر(&vtop->type);
                indir();
            }
        }
        توڑو;
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    حالت TOK_builtin_va_آغاز:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        اگر (r == VT_LLOCAL)
            r = VT_LOCAL;
        اگر (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_آغاز();
	vstore();
        توڑو;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_X86_64
#اگر_تعریف_شدہ TCC_ہدف_PE
    حالت TOK_builtin_va_آغاز:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        اگر (r == VT_LLOCAL)
            r = VT_LOCAL;
        اگر (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_اشارہ_گر_type;
	vtop->c.i += 8;
	vstore();
        توڑو;
#ورنہ
    حالت TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	توڑو;
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_ARM64
    حالت TOK_builtin_va_آغاز: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_آغاز();
        vpushi(0);
        vtop->type.t = VT_VOID;
        توڑو;
    }
    حالت TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        توڑو;
    }
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_ARM64
    حالت TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        توڑو;
    }
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    حالت TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        توڑو;
    }
#اگر_ختم

    /* atomic operations */
    حالت TOK___atomic_store:
    حالت TOK_atomic_بھرو:
    حالت TOK___atomic_exchange:
    حالت TOK___atomic_compare_exchange:
    حالت TOK_atomic_fetch_جوڑو:
    حالت TOK___atomic_fetch_sub:
    حالت TOK___atomic_fetch_or:
    حالت TOK___atomic_fetch_xor:
    حالت TOK___atomic_fetch_and:
    حالت TOK___atomic_fetch_nand:
    حالت TOK_atomic_جوڑو_fetch:
    حالت TOK___atomic_sub_fetch:
    حالت TOK___atomic_or_fetch:
    حالت TOK___atomic_xor_fetch:
    حالت TOK___atomic_and_fetch:
    حالت TOK___atomic_nand_fetch:
        parse_atomic(tok);
        توڑو;

    /* pre operations */
    حالت TOK_INC:
    حالت TOK_DEC:
        t = tok;
        اگلا();
        unary();
        inc(0, t);
        توڑو;
    حالت '-':
        اگلا();
        unary();
	اگر (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ورنہ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        توڑو;
    حالت TOK_LAND:
        اگر (!gnu_ext)
            جاؤ tok_identifier;
        اگلا();
        /* allow to take the address of a label */
        اگر (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_ڈھونڈو(tok);
        اگر (!s) {
            s = label_ڈالو(&global_label_ڈھیر, tok, LABEL_FORWARD);
        } ورنہ {
            اگر (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        اگر ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_اشارہ_گر(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        اگلا();
        توڑو;

    حالت TOK_GENERIC:
    {
	CType controlling_type;
	صحیح has_default = 0;
	صحیح has_مطابقت = 0;
	صحیح learn = 0;
	TokenString *str = تہی;
	صحیح saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_نقاب;

        اگلا();
	skip('(');
	اظہاریہ_type(&controlling_type, اظہاریہ_eq);
	convert_عبارت_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        برائے (;;) {
	    learn = 0;
	    skip(',');
	    اگر (tok == TOK_DEFAULT) {
		اگر (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		اگر (!has_مطابقت)
		    learn = 1;
		اگلا();
	    } ورنہ {
		صحیح v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		اگر (compare_types(&controlling_type, &type, 0)) {
		    اگر (has_مطابقت) {
		      tcc_error("type match twice");
		    }
		    has_مطابقت = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    اگر (learn) {
		اگر (str)
		    tok_str_free(str);
		skip_or_save_بلاک(&str);
	    } ورنہ {
		skip_or_save_بلاک(تہی);
	    }
	    اگر (tok == ')')
		توڑو;
	}
	اگر (!str) {
	    حرف buf[60];
	    type_مقصد_str(buf, حجم buf, &controlling_type, تہی);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	اگلا();
	اظہاریہ_eq();
	اگر (tok != TOK_EOF)
	    expect(",");
	انتہا_macro();
        اگلا();
	توڑو;
    }
    // special qnan , snan and infinity values
    حالت TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        اگلا();
        توڑو;
    حالت TOK___SNAN__:
	n = 0x7f800001;
	جاؤ special_math_val;
    حالت TOK___INF__:
	n = 0x7f800000;
	جاؤ special_math_val;

    طےشدہ:
    tok_identifier:
        اگر (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        اگلا();
        s = sym_ڈھونڈو(t);
        اگر (!s || IS_ASM_SYM(s)) {
            ثابت حرف *name = get_tok_str(t, تہی);
            اگر (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            اگر (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        اگر ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        اگر (r & VT_SYM) {
            vtop->c.i = 0;
#اگر_تعریف_شدہ TCC_ہدف_PE
            اگر (s->a.dllimport) {
                mk_اشارہ_گر(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#اگر_ختم
        } ورنہ اگر (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        توڑو;
    }
    
    /* post operations */
    جب (1) {
        اگر (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            اگلا();
        } ورنہ اگر (tok == '.' || tok == TOK_ARROW) {
            صحیح qualifiers, cumofs;
            /*میدان*/ 
            اگر (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            اگلا();
	    s = ڈھونڈو_میدان(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_اشارہ_گر_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            اگر (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            اگر (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                اگر (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#اگر_ختم
            }
            اگلا();
        } ورنہ اگر (tok == '[') {
            اگلا();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ورنہ اگر (tok == '(') {
            SValue ret;
            Sym *sa;
            صحیح nb_دلائل, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            اگر ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                اگر ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    اگر ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        جاؤ error_func;
                } ورنہ {
                error_func:
                    expect("function pointer");
                }
            } ورنہ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            اگلا();
            sa = s->اگلا; /* first parameter */
            nb_دلائل = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            اگر ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                اگر (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    سائز = type_سائز(&s->type, &align);
#اگر_تعریف_شدہ TCC_ہدف_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                اگر (سائز < 16)
                    جب (سائز & (سائز - 1))
                        سائز = (سائز | (سائز - 1)) + 1;
#اگر_ختم
                    loc = (loc - سائز) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
                    اگر (tcc_state->do_bounds_check)
                        --loc;
#اگر_ختم
                    ret.c = vtop->c;
                    اگر (ret_nregs < 0)
                      vtop--;
                    ورنہ
                      nb_دلائل++;
                }
            } ورنہ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            اگر (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = تہی;
            اگر (tok != ')') {
                r = tcc_state->الٹ_funcargs;
                برائے(;;) {
                    اگر (r) {
                        skip_or_save_بلاک(&p2);
                        p2->پچھلا = p, p = p2;
                    } ورنہ {
                        اظہاریہ_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_دلائل++;
                    اگر (sa)
                        sa = sa->اگلا;
                    اگر (tok == ')')
                        توڑو;
                    skip(',');
                }
            }
            اگر (sa)
                tcc_error("too few arguments to function");

            اگر (p) { /* with reverse_funcargs */
                برائے (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    کرو {
                        sa = sa->اگلا, p2 = p2->پچھلا;
                    } جب (p2 && sa);
                    p2 = p->پچھلا;
                    begin_macro(p, 1), اگلا();
                    اظہاریہ_eq();
                    gfunc_param_typed(s, sa);
                    انتہا_macro();
                }
                vrev(n);
            }

            اگلا();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_دلائل);

            اگر (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
                arch_transfer_ret_regs(1);
#اگر_ختم
            } ورنہ {
                /* return value */
                n = ret_nregs;
                جب (n > 1) {
                    صحیح rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    برائے (r = 0; r < NB_REGS; ++r)
                        اگر (reg_classes[r] & rc)
                            توڑو;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                اگر (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    صحیح addr, انحراف;

                    سائز = type_سائز(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    سائز = (سائز + regsize - 1) & -regsize;
                    اگر (ret_align > align)
                        align = ret_align;
                    loc = (loc - سائز) & -align;
                    addr = loc;
                    انحراف = 0;
                    برائے (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + انحراف);
                        vswap();
                        vstore();
                        vtop--;
                        اگر (--ret_nregs == 0)
                          توڑو;
                        انحراف += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                اگر (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#اگر_تعریف_شدہ PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ورنہ
                    vtop->type.t = VT_INT;
#اگر_ختم
                }
            }
            اگر (s->f.func_noreturn) {
                اگر (debug_modes)
	            tcc_tcov_بلاک_انتہا(tcc_state, -1);
                رمز_OFF();
	    }
        } ورنہ {
            توڑو;
        }
    }
}

#اگر_غیر_تعریف_شدہ precedence_parser /* original top-down parser */

ساکن خالی اظہاریہ_prod(خالی)
{
    صحیح t;

    unary();
    جب ((t = tok) == '*' || t == '/' || t == '%') {
        اگلا();
        unary();
        gen_op(t);
    }
}

ساکن خالی اظہاریہ_مجموع(خالی)
{
    صحیح t;

    اظہاریہ_prod();
    جب ((t = tok) == '+' || t == '-') {
        اگلا();
        اظہاریہ_prod();
        gen_op(t);
    }
}

ساکن خالی اظہاریہ_سرکاؤ(خالی)
{
    صحیح t;

    اظہاریہ_مجموع();
    جب ((t = tok) == TOK_SHL || t == TOK_SAR) {
        اگلا();
        اظہاریہ_مجموع();
        gen_op(t);
    }
}

ساکن خالی اظہاریہ_cmp(خالی)
{
    صحیح t;

    اظہاریہ_سرکاؤ();
    جب (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        اگلا();
        اظہاریہ_سرکاؤ();
        gen_op(t);
    }
}

ساکن خالی اظہاریہ_cmpeq(خالی)
{
    صحیح t;

    اظہاریہ_cmp();
    جب ((t = tok) == TOK_EQ || t == TOK_NE) {
        اگلا();
        اظہاریہ_cmp();
        gen_op(t);
    }
}

ساکن خالی اظہاریہ_and(خالی)
{
    اظہاریہ_cmpeq();
    جب (tok == '&') {
        اگلا();
        اظہاریہ_cmpeq();
        gen_op('&');
    }
}

ساکن خالی اظہاریہ_xor(خالی)
{
    اظہاریہ_and();
    جب (tok == '^') {
        اگلا();
        اظہاریہ_and();
        gen_op('^');
    }
}

ساکن خالی اظہاریہ_or(خالی)
{
    اظہاریہ_xor();
    جب (tok == '|') {
        اگلا();
        اظہاریہ_xor();
        gen_op('|');
    }
}

ساکن خالی اظہاریہ_landor(صحیح op);

ساکن خالی اظہاریہ_land(خالی)
{
    اظہاریہ_or();
    اگر (tok == TOK_LAND)
        اظہاریہ_landor(tok);
}

ساکن خالی اظہاریہ_lor(خالی)
{
    اظہاریہ_land();
    اگر (tok == TOK_LOR)
        اظہاریہ_landor(tok);
}

# define اظہاریہ_landor_اگلا(op) op == TOK_LAND ? اظہاریہ_or() : اظہاریہ_land()
#ورنہ /* defined precedence_parser */
# define اظہاریہ_landor_اگلا(op) unary(), اظہاریہ_infix(precedence(op) + 1)
# define اظہاریہ_lor() unary(), اظہاریہ_infix(1)

ساکن صحیح precedence(صحیح tok)
{
    انتخاب (tok) {
        حالت TOK_LOR: واپس 1;
        حالت TOK_LAND: واپس 2;
	حالت '|': واپس 3;
	حالت '^': واپس 4;
	حالت '&': واپس 5;
	حالت TOK_EQ: حالت TOK_NE: واپس 6;
 relat: حالت TOK_ULT: حالت TOK_UGE: واپس 7;
	حالت TOK_SHL: حالت TOK_SAR: واپس 8;
	حالت '+': حالت '-': واپس 9;
	حالت '*': حالت '/': حالت '%': واپس 10;
	طےشدہ:
	    اگر (tok >= TOK_ULE && tok <= TOK_GT)
	        جاؤ relat;
	    واپس 0;
    }
}
ساکن غیرعلامتی حرف prec[256];
ساکن خالی init_prec(خالی)
{
    صحیح i;
    برائے (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#تعریف_کرو precedence(i) ((غیرعلامتی)i < 256 ? prec[i] : 0)

ساکن خالی اظہاریہ_landor(صحیح op);

ساکن خالی اظہاریہ_infix(صحیح p)
{
    صحیح t = tok, p2;
    جب ((p2 = precedence(t)) >= p) {
        اگر (t == TOK_LOR || t == TOK_LAND) {
            اظہاریہ_landor(t);
        } ورنہ {
            اگلا();
            unary();
            اگر (precedence(tok) > p2)
              اظہاریہ_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#اگر_ختم

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ساکن صحیح condition_3way(خالی)
{
    صحیح c = -1;
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    واپس c;
}

ساکن خالی اظہاریہ_landor(صحیح op)
{
    صحیح t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    برائے(;;) {
        c = f ? i : condition_3way();
        اگر (c < 0)
            save_regs(1), cc = 0;
        ورنہ اگر (c != i)
            nocode_wanted++, f = 1;
        اگر (tok != op)
            توڑو;
        اگر (c < 0)
            t = gvtst(i, t);
        ورنہ
            vpop();
        اگلا();
        اظہاریہ_landor_اگلا(op);
    }
    اگر (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ورنہ {
        gvtst_سیٹ(i, t);
    }
}

ساکن صحیح is_cond_bool(SValue *sv)
{
    اگر ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        واپس (غیرعلامتی)sv->c.i < 2;
    اگر (sv->r == VT_CMP)
        واپس 1;
    واپس 0;
}

ساکن خالی اظہاریہ_cond(خالی)
{
    صحیح tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    اظہاریہ_lor();
    اگر (tok == '?') {
        اگلا();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        اگر (!g) {
            اگر (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ورنہ {
                vpop();
            }
        } ورنہ اگر (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        اگر (c == 0)
          nocode_wanted++;
        اگر (!g)
          gexpr();

        اگر ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_اشارہ_گر(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        اگر (g) {
            u = tt;
        } ورنہ اگر (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ورنہ
          u = 0;

        اگر (c == 0)
          nocode_wanted--;
        اگر (c == 1)
          nocode_wanted++;
        skip(':');
        اظہاریہ_cond();

        اگر ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_اشارہ_گر(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        اگر (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        اگر (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_سیٹ(0, t1);
            gvtst_سیٹ(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            واپس;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        اگر (c != 1) {
            gen_cast(&type);
            اگر (islv) {
                mk_اشارہ_گر(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        اگر (USING_TWO_الفاظ(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        اگر (c < 0) {
            اگر (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        اگر (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
عملیہ*/
        اگر (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            اگر (islv) {
                mk_اشارہ_گر(&vtop->type);
                gaddrof();
            }
        }

        اگر (c < 0) {
            اگر (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        اگر (islv)
          indir();
    }
}

ساکن خالی اظہاریہ_eq(خالی)
{
    صحیح t;
    
    اظہاریہ_cond();
    اگر ((t = tok) == '=' || TOK_تفویض(t)) {
        test_lvalue();
        اگلا();
        اگر (t == '=') {
            اظہاریہ_eq();
        } ورنہ {
            vdup();
            اظہاریہ_eq();
            gen_op(TOK_تفویض_OP(t));
        }
        vstore();
    }
}

ST_FUNC خالی gexpr(خالی)
{
    اظہاریہ_eq();
    اگر (tok == ',') {
        کرو {
            vpop();
            اگلا();
            اظہاریہ_eq();
        } جب (tok == ',');

        /* convert array & function to pointer */
        convert_عبارت_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        اگر ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            اگر (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ساکن خالی اظہاریہ_const1(خالی)
{
    nocode_wanted += CONST_WANTED_ثنائی_ہندسہ;
    اظہاریہ_cond();
    nocode_wanted -= CONST_WANTED_ثنائی_ہندسہ;
}

/* parse an integer constant and return its value. */
ساکن اندرونی int64_t اظہاریہ_const64(خالی)
{
    int64_t c;
    اظہاریہ_const1();
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    واپس c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC صحیح اظہاریہ_const(خالی)
{
    صحیح c;
    int64_t wc = اظہاریہ_const64();
    c = wc;
    اگر (c != wc && (غیرعلامتی)c != wc)
        tcc_error("constant exceeds 32 bit");
    واپس c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#اگر_غیر_تعریف_شدہ TCC_ہدف_ARM64
ساکن خالی gfunc_return(CType *func_type)
{
    اگر ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        صحیح ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        اگر (ret_nregs < 0) {
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
            arch_transfer_ret_regs(0);
#اگر_ختم
        } ورنہ اگر (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_اشارہ_گر(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ورنہ {
            /* returning structure packed into registers */
            صحیح سائز, addr, align, rc, n;
            سائز = type_سائز(func_type,&align);
            اگر (ret_nregs * regsize > سائز ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		اگر (ret_nregs * regsize > سائز)
		    سائز = ret_nregs * regsize;
		اگر (ret_align > align)
		    align = ret_align;
                loc = (loc - سائز) & -align;
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
            برائے (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_انحراف(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } ورنہ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#اگر_ختم

ساکن خالی check_func_return(خالی)
{
    اگر ((func_vt.t & VT_BTYPE) == VT_VOID)
        واپس;
    اگر ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ورنہ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ساکن صحیح case_cmp(uint64_t a, uint64_t b)
{
    اگر (cur_switch->sv.type.t & VT_UNSIGNED)
        واپس a < b ? -1 : a > b;
    ورنہ
        واپس (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ساکن صحیح case_cmp_qs(ثابت خالی *pa, ثابت خالی *pb)
{
    واپس case_cmp((*(ساخت case_t**)pa)->v1, (*(ساخت case_t**)pb)->v1);
}

ساکن خالی case_ترتیب_دو(ساخت switch_t *sw)
{
    ساخت case_t **p;
    اگر (sw->n < 2)
        واپس;
    qsort(sw->p, sw->n, حجم *sw->p, case_cmp_qs);
    p = sw->p;
    جب (p < sw->p + sw->n - 1) {
        اگر (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            صحیح l1 = p[0]->سطر, l2 = p[1]->سطر;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ورنہ اگر (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * حجم *p);
        } ورنہ
            ++p;
    }
}

ساکن صحیح gcase(ساخت case_t **بنیاد, صحیح len, صحیح dsym)
{
    ساخت case_t *p;
    صحیح t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    اگر (t != VT_LLONG)
        t = VT_INT;
    جب (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = بنیاد[l2];
        vdup(), vpush64(t, p->v2);
        اگر (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ورنہ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            اگر (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ورنہ
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(بنیاد, l2, dsym);
            gsym(e);
        }
        ++l2, بنیاد += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    واپس gjmp(dsym);
}

ساکن خالی انتہا_switch(خالی)
{
    ساخت switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->پچھلا;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ساکن خالی save_lvalues(خالی)
{
    SValue *sv = vtop;
    جب (sv >= vstack) {
        اگر (sv->sym && (sv->r & VT_LVAL)) {
            صحیح align, سائز = type_سائز(&sv->type, &align);
            صحیح r2, l = get_عارضی_local_var(سائز, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ساکن خالی try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    برائے (; cls != stop; cls = cls->اگلا) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_اشارہ_گر(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


ساکن خالی try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    صحیح ocd, ccd;

    اگر (!cur_scope->cl.s)
	واپس;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_میدان : 0;
    برائے (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->اگلا)
      ;
    برائے (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->اگلا)
      ;
    برائے (; cc != oc; cc = cc->اگلا, oc = oc->اگلا, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ساکن خالی بلاک_cleanup(ساخت scope *o)
{
    صحیح jmp = 0;
    Sym *g, **pg;
    برائے (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        اگر (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->اگلا;
            اگر (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            اگر (!o->cl.n)
                جاؤ remove_pending;
            g->c = o->cl.n;
            pg = &g->پچھلا;
        } ورنہ {
    remove_pending:
            *pg = g->پچھلا;
            sym_free(g);
        }
    }
    gsym(jmp);
    try_call_scope_cleanup(o->cl.s);
}

/* ------------------------------------------------------------------------- */
/* VLA */

ساکن خالی vla_restore(صحیح loc)
{
    اگر (loc)
        gen_vla_sp_restore(loc);
}

ساکن خالی vla_leave(ساخت scope *o)
{
    ساخت scope *c = cur_scope, *v = تہی;
    برائے (; c != o && c; c = c->پچھلا)
      اگر (c->vla.عدد)
        v = c;
    اگر (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ساکن خالی new_scope(ساخت scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->پچھلا = cur_scope;
    cur_scope = o;
    cur_scope->vla.عدد = 0;

    /* record local declaration stack position */
    o->lstk = local_ڈھیر;
    o->llstk = local_label_ڈھیر;
    ++local_scope;
}

ساکن خالی پچھلا_scope(ساخت scope *o, صحیح is_اظہاریہ)
{
    vla_leave(o->پچھلا);

    اگر (o->cl.s != o->پچھلا->cl.s)
        بلاک_cleanup(o->پچھلا);

    اگر (debug_modes)
        tcc_debug_انتہا_scope(o->lstk, !is_اظہاریہ);

    /* pop locally defined labels */
    label_نکالو(&local_label_ڈھیر, o->llstk, is_اظہاریہ);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_نکالو(&local_ڈھیر, o->lstk, is_اظہاریہ);
    cur_scope = o->پچھلا;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ساکن خالی leave_scope(ساخت scope *o)
{
    اگر (!o)
        واپس;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ساکن خالی new_scope_s(ساخت scope *o)
{
    o->lstk = local_ڈھیر;
    ++local_scope;
}

ساکن خالی پچھلا_scope_s(ساخت scope *o)
{
    sym_نکالو(&local_ڈھیر, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ساکن خالی lblock(صحیح *bsym, صحیح *csym)
{
    ساخت scope *lo = loop_scope, *co = cur_scope;
    صحیح *b = co->bsym, *c = co->csym;
    اگر (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    بلاک(0);
    co->bsym = b;
    اگر (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ساکن خالی gexpr_decl(خالی)
{
    صحیح v = decl(VT_JMP);
    اگر (v > 1 && tok != ';') {
        Sym *s = sym_ڈھونڈو(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ورنہ {
        اگر (v)
            skip(';');
        gexpr();
    }
}

ساکن خالی بلاک(صحیح flags)
{
    صحیح a, b, c, d, e, t;
    ساخت scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    اگر (TOK_HAS_قدر(t))
        جاؤ اظہاریہ;
    اگلا();

    اگر (debug_modes)
        tcc_tcov_check_سطر (tcc_state, 0), tcc_tcov_بلاک_begin (tcc_state);

    اگر (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        بلاک(0);
        اگر (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            اگلا();
            بلاک(0);
            gsym(d); /* patch else jmp */
        } ورنہ {
            gsym(a);
        }
        پچھلا_scope_s(&o);

    } ورنہ اگر (t == TOK_WHILE) {
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
        پچھلا_scope_s(&o);

    } ورنہ اگر (t == '{') {
        اگر (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        جب (tok == TOK_LABEL) {
            کرو {
                اگلا();
                اگر (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ڈالو(&local_label_ڈھیر, tok, LABEL_DECLARED);
                اگلا();
            } جب (tok == ',');
            skip(';');
        }

        جب (tok != '}') {
	    decl(VT_LOCAL);
            اگر (tok != '}') {
                بلاک(flags | STMT_COMPOUND);
            }
        }

        پچھلا_scope(&o, flags & STMT_اظہاریہ);
        اگر (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        اگر (local_scope)
            اگلا();
        ورنہ اگر (!nocode_wanted)
            check_func_return();

    } ورنہ اگر (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        اگر (tok != ';') {
            gexpr();
            اگر (b) {
                gen_تفویض_cast(&func_vt);
            } ورنہ {
                اگر (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ورنہ اگر (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ورنہ اگر (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(جڑ_scope);
        اگر (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        اگر (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        اگر (debug_modes)
	    tcc_tcov_بلاک_انتہا (tcc_state, -1);
        رمز_OFF();

    } ورنہ اگر (t == TOK_BREAK) {
        /* compute jump */
        اگر (!cur_scope->bsym)
            tcc_error("cannot break");
        اگر (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ورنہ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ورنہ اگر (t == TOK_CONTINUE) {
        /* compute jump */
        اگر (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ورنہ اگر (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        اگر (tok != ';') {
            /* c99 for-loop init decl? */
            اگر (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        اگر (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        اگر (tok != ')') {
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
        پچھلا_scope(&o, 0);

    } ورنہ اگر (t == TOK_DO) {
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
        پچھلا_scope_s(&o);

    } ورنہ اگر (t == TOK_SWITCH) {
        ساخت switch_t *sw;

        sw = tcc_mallocz(حجم *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->پچھلا = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        اگر (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, تہی);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        پچھلا_scope_s(&o);
        اگر (sw->nocode_wanted)
            جاؤ skip_switch;
        case_ترتیب_دو(sw);
        sw->bsym = تہی; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        اگر (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ورنہ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        انتہا_switch();

    } ورنہ اگر (t == TOK_CASE) {
        ساخت case_t *cr;
        اگر (!cur_switch)
            expect("switch");
        cr = tcc_malloc(حجم(ساخت case_t));
        dynarray_جوڑو(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(اظہاریہ_const64(), t);
        اگر (tok == TOK_DOTS && gnu_ext) {
            اگلا();
            cr->v2 = value64(اظہاریہ_const64(), t);
            اگر (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        اگر (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->سطر = file->سطر_عدد;
        skip(':');
        جاؤ بلاک_after_label;

    } ورنہ اگر (t == TOK_DEFAULT) {
        اگر (!cur_switch)
            expect("switch");
        اگر (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        جاؤ بلاک_after_label;

    } ورنہ اگر (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        اگر (tok == '*' && gnu_ext) {
            /* computed goto */
            اگلا();
            gexpr();
            اگر ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ورنہ اگر (tok >= TOK_UIDENT) {
	    s = label_ڈھونڈو(tok);
	    /* put forward definition if needed */
            اگر (!s)
              s = label_ڈالو(&global_label_ڈھیر, tok, LABEL_FORWARD);
            ورنہ اگر (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    اگر (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		اگر (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_میدان, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->اگلا, SYM_میدان, 0, 0);
                    pending_gotos->اگلا = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ورنہ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    اگلا();

        } ورنہ {
            expect("label identifier");
        }
        skip(';');

    } ورنہ اگر (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ورنہ {
        اگر (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    اگلا();
            s = label_ڈھونڈو(t);
            اگر (s) {
                اگر (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, تہی));
                s->r = LABEL_DEFINED;
		اگر (s->اگلا) {
		    Sym *pcl; /* pending cleanup goto */
		    برائے (pcl = s->اگلا; pcl; pcl = pcl->پچھلا)
		      gsym(pcl->jnext);
		    sym_نکالو(&s->اگلا, تہی, 0);
		} ورنہ
		  gsym(s->jnext);
            } ورنہ {
                s = label_ڈالو(&global_label_ڈھیر, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    بلاک_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(تہی);

            اگر (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            اگر (tok != '}') {
                اگر (0 == (flags & STMT_COMPOUND))
                    جاؤ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ورنہ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ورنہ {
            /* expression case */
            اگر (t != ';') {
                unget_tok(t);
    اظہاریہ:
                اگر (flags & STMT_اظہاریہ) {
                    vpop();
                    gexpr();
                } ورنہ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    اگر (debug_modes)
        tcc_tcov_check_سطر (tcc_state, 0), tcc_tcov_بلاک_انتہا (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ساکن خالی skip_or_save_بلاک(TokenString **str)
{
    صحیح braces = tok == '{';
    صحیح level = 0;
    اگر (str)
      *str = tok_str_alloc();

    جب (1) {
	صحیح t = tok;
        اگر (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             توڑو;
	اگر (t == TOK_EOF) {
	     اگر (str || level > 0)
	       tcc_error("unexpected end of file");
	     ورنہ
	       توڑو;
	}
	اگر (str)
	  tok_str_جوڑو_tok(*str);
	اگلا();
	اگر (t == '{' || t == '(' || t == '[') {
	    level++;
	} ورنہ اگر (t == '}' || t == ')' || t == ']') {
	    level--;
	    اگر (level == 0 && braces && t == '}')
	      توڑو;
	}
    }
    اگر (str)
	tok_str_جوڑو(*str, TOK_EOF);
}

#تعریف_کرو اظہاریہ_CONST 1
#تعریف_کرو اظہاریہ_ANY   2

ساکن خالی parse_init_elem(صحیح اظہاریہ_type)
{
    صحیح saved_global_اظہاریہ;
    انتخاب(اظہاریہ_type) {
    حالت اظہاریہ_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_اظہاریہ = global_اظہاریہ;
        global_اظہاریہ = 1;
        اظہاریہ_const1();
        global_اظہاریہ = saved_global_اظہاریہ;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        اگر (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_پہلا_ANOM))
#اگر_تعریف_شدہ TCC_ہدف_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#اگر_ختم
           )
            tcc_error("initializer element is not constant");
        توڑو;
    حالت اظہاریہ_ANY:
        اظہاریہ_eq();
        توڑو;
    }
}

#اگر 1
ساکن خالی init_assert(init_params *p, صحیح انحراف)
{
    اگر (p->sec ? !NODATA_WANTED && انحراف > p->sec->ڈیٹا_انحراف
               : !nocode_wanted && انحراف > p->local_انحراف)
        tcc_اندرونی_error("initializer overflow");
}
#ورنہ
#تعریف_کرو init_assert(sec, انحراف)
#اگر_ختم

/* put zeros for variable based init */
ساکن خالی init_putz(init_params *p, غیرعلامتی طویل c, صحیح سائز)
{
    init_assert(p, c + سائز);
    اگر (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ورنہ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(سائز);
#اگر defined TCC_ہدف_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#اگر_ختم
        gfunc_call(3);
    }
}

#تعریف_کرو DIF_پہلا     1
#تعریف_کرو DIF_سائز_ONLY 2
#تعریف_کرو DIF_HAVE_ELEM 4
#تعریف_کرو DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
ساکن خالی decl_design_delrels(Section *sec, صحیح c, صحیح سائز)
{
    ElfW_Rel *rel, *rel2, *rel_انتہا;
    اگر (!sec || !sec->reloc)
        واپس;
    rel = rel2 = (ElfW_Rel*)sec->reloc->ڈیٹا;
    rel_انتہا = (ElfW_Rel*)(sec->reloc->ڈیٹا + sec->reloc->ڈیٹا_انحراف);
    جب (rel < rel_انتہا) {
        اگر (rel->r_انحراف >= c && rel->r_انحراف < c + سائز) {
            sec->reloc->ڈیٹا_انحراف -= حجم *rel;
        } ورنہ {
            اگر (rel2 != rel)
                حافظہ_نقل(rel2, rel, حجم *rel);
            ++rel2;
        }
        ++rel;
    }
}

ساکن خالی decl_design_flex(init_params *p, Sym *ref, صحیح اشاریہ)
{
    اگر (ref == p->flex_array_ref) {
        اگر (اشاریہ >= ref->c)
            ref->c = اشاریہ + 1;
    } ورنہ اگر (ref->c < 0 && اشاریہ >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ساکن صحیح decl_designator(init_params *p, CType *type, غیرعلامتی طویل c,
                           Sym **cur_میدان, صحیح flags, صحیح al)
{
    Sym *s, *f;
    صحیح اشاریہ, اشاریہ_آخری, align, l, nb_elems, elem_سائز;
    غیرعلامتی طویل corig = c;

    elem_سائز = 0;
    nb_elems = 1;

    اگر (flags & DIF_HAVE_ELEM)
        جاؤ no_designator;

    اگر (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, اگلا();
        اگر (tok == ':')
            جاؤ struct_میدان;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    جب (nb_elems == 1 && (tok == '[' || tok == '.')) {
        اگر (tok == '[') {
            اگر (!(type->t & VT_ARRAY))
                expect("array type");
            اگلا();
            اشاریہ = اشاریہ_آخری = اظہاریہ_const();
            اگر (tok == TOK_DOTS && gnu_ext) {
                اگلا();
                اشاریہ_آخری = اظہاریہ_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, اشاریہ_آخری);
            اگر (اشاریہ < 0 || اشاریہ_آخری >= s->c || اشاریہ_آخری < اشاریہ)
	        tcc_error("index exceeds array bounds or range is empty");
            اگر (cur_میدان)
		(*cur_میدان)->c = اشاریہ_آخری;
            type = pointed_type(type);
            elem_سائز = type_سائز(type, &align);
            c += اشاریہ * elem_سائز;
            nb_elems = اشاریہ_آخری - اشاریہ + 1;
        } ورنہ {
            صحیح cumofs;
            اگلا();
            l = tok;
        struct_میدان:
            اگلا();
	    f = ڈھونڈو_میدان(type, l, &cumofs);
            اگر (cur_میدان)
                *cur_میدان = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_میدان = تہی;
    }
    اگر (!cur_میدان) {
        اگر (tok == '=') {
            اگلا();
        } ورنہ اگر (!gnu_ext) {
	    expect("=");
        }
    } ورنہ {
    no_designator:
        اگر (type->t & VT_ARRAY) {
	    اشاریہ = (*cur_میدان)->c;
            s = type->ref;
            decl_design_flex(p, s, اشاریہ);
            اگر (اشاریہ >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_سائز = type_سائز(type, &align);
            c += اشاریہ * elem_سائز;
        } ورنہ {
            f = *cur_میدان;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    جب (f && (f->v & SYM_پہلا_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_میدان = f = f->اگلا;
            اگر (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    اگر (!elem_سائز) /* for structs */
        elem_سائز = type_سائز(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    اگر (!(flags & DIF_سائز_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_سائز * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_پہلا);

    اگر (!(flags & DIF_سائز_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        صحیح i;
        اگر (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_سائز;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        اگر (p->sec)
            vpush_ref(type, p->sec, c, elem_سائز);
        ورنہ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        برائے (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_سائز * i);
	}
        vpop();
    }

    c += nb_elems * elem_سائز;
    اگر (c - corig > al)
      al = c - corig;
    واپس al;
}

ساکن خالی write_ldouble(غیرعلامتی حرف *d, خالی *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#اگر_تعریف_شدہ TCC_CROSS_TEST
    اگر (LDOUBLE_سائز >= 10) {
        دوہرا b = *(طویل دوہرا*)s;
        s = &b;
#ورنہ
    اگر (حجم (طویل دوہرا) == 8 && LDOUBLE_سائز >= 10) {
#اگر_ختم
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        صحیح e = m >> 48;
        صحیح f = e >> 4 & 0x7FF;
        m <<= 11;
        اگر (0 == f) {
            اگر (0 == m)
                جاؤ سیٹ;
            برائے (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        اگر (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    سیٹ:
    #اگر (defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #وگرنہ_اگر LDOUBLE_سائز == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #اگر_ختم
        ;
    } ورنہ {
    #اگر LDOUBLE_سائز == 8
        /* long double -> double */
        دوہرا b = *(طویل دوہرا*)s;
        حافظہ_نقل(d, &b, 8);
    #وگرنہ_اگر (__i386__ || __x86_64__) && (defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64)
        /* extended -> extended */
        حافظہ_نقل(d, s, 10);
    #وگرنہ_اگر (__i386__ || __x86_64__) && (defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        صحیح e = *(uint16_t*)((حرف*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #وگرنہ_اگر (__aarch64__ || __riscv) && (defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((حرف*)s + 6);
        صحیح e = read16le((حرف*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ورنہ
        /* unknown */
        اگر (حجم (طویل دوہرا) == LDOUBLE_سائز)
            حافظہ_نقل(d, s, LDOUBLE_سائز);
    #اگر_ختم
    }
}

/* store a value or an expression directly in global data or in local array */
ساکن خالی init_putv(init_params *p, CType *type, غیرعلامتی طویل c)
{
    صحیح bt;
    خالی *ptr;
    CType dtype;
    صحیح سائز, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    سائز = type_سائز(type, &align);
    اگر (type->t & VT_BITFIELD)
        سائز = (ثنائی_ہندسہ_POS(type->t) + ثنائی_ہندسہ_سائز(type->t) + 7) / 8;
    init_assert(p, c + سائز);

    اگر (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_تفویض_cast(&dtype);
        bt = type->t & VT_BTYPE;

        اگر ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_سائز == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_پہلا_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        اگر (NODATA_WANTED) {
            vtop--;
            واپس;
        }

        ptr = sec->ڈیٹا + c;
        val = vtop->c.i;

	اگر ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_پہلا_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->ڈیٹا + esym->st_قدر + (صحیح)vtop->c.i, سائز);
	    اگر (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                غیرعلامتی طویل relofs = ssec->reloc->ڈیٹا_انحراف;
		جب (relofs >= حجم(*rel)) {
                    relofs -= حجم(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->ڈیٹا + relofs);
		    اگر (rel->r_انحراف >= esym->st_قدر + سائز)
		      جاری;
		    اگر (rel->r_انحراف < esym->st_قدر)
		      توڑو;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_انحراف - esym->st_قدر,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#اگر PTR_سائز == 8
				   rel->r_addend
#ورنہ
				   0
#اگر_ختم
				  );
		}
	    }
	} ورنہ {
            اگر (type->t & VT_BITFIELD) {
                صحیح ثنائی_ہندسہ_pos, ثنائی_ہندسہ_سائز_2, بٹ, n;
                غیرعلامتی حرف *p, v, m;
                ثنائی_ہندسہ_pos = ثنائی_ہندسہ_POS(vtop->type.t);
                ثنائی_ہندسہ_سائز_2 = ثنائی_ہندسہ_سائز(vtop->type.t);
                p = (غیرعلامتی حرف*)ptr + (ثنائی_ہندسہ_pos >> 3);
                ثنائی_ہندسہ_pos &= 7, بٹ = 0;
                جب (ثنائی_ہندسہ_سائز_2) {
                    n = 8 - ثنائی_ہندسہ_pos;
                    اگر (n > ثنائی_ہندسہ_سائز_2)
                        n = ثنائی_ہندسہ_سائز_2;
                    v = val >> بٹ << ثنائی_ہندسہ_pos;
                    m = ((1 << n) - 1) << ثنائی_ہندسہ_pos;
                    *p = (*p & ~m) | (v & m);
                    بٹ += n, ثنائی_ہندسہ_سائز_2 -= n, ثنائی_ہندسہ_pos = 0, ++p;
                }
            } ورنہ
            انتخاب(bt) {
	    حالت VT_BOOL:
		*(حرف *)ptr = val != 0;
                توڑو;
	    حالت VT_BYTE:
		*(حرف *)ptr = val;
		توڑو;
	    حالت VT_SHORT:
                write16le(ptr, val);
		توڑو;
	    حالت VT_FLOAT:
                write32le(ptr, val);
		توڑو;
	    حالت VT_DOUBLE:
                write64le(ptr, val);
		توڑو;
	    حالت VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		توڑو;

#اگر PTR_سائز == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    حالت VT_LLONG:
	    حالت VT_PTR:
	        اگر (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_ڈیٹا_PTR, val);
	        ورنہ
	          write64le(ptr, val);
	        توڑو;
            حالت VT_INT:
                write32le(ptr, val);
                توڑو;
#ورنہ
	    حالت VT_LLONG:
                write64le(ptr, val);
                توڑو;
            حالت VT_PTR:
            حالت VT_INT:
	        اگر (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_ڈیٹا_PTR);
	        write32le(ptr, val);
	        توڑو;
#اگر_ختم
	    طےشدہ:
                //tcc_internal_error("unexpected type");
                توڑو;
	    }
	}
        vtop--;
    } ورنہ {
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
ساکن خالی decl_initializer(init_params *p, CType *type, غیرعلامتی طویل c, صحیح flags)
{
    صحیح len, n, no_oblock, i;
    صحیح size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    اگر (debug_modes && !(flags & DIF_سائز_ONLY) && !p->sec)
        tcc_debug_سطر(tcc_state), tcc_tcov_check_سطر (tcc_state, 1);

    اگر (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_سائز_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        صحیح ncw_پچھلا = nocode_wanted;
        اگر ((flags & DIF_سائز_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? اظہاریہ_ANY : اظہاریہ_CONST);
        nocode_wanted = ncw_پچھلا;
        flags |= DIF_HAVE_ELEM;
    }

    اگر (type->t & VT_ARRAY) {
        no_oblock = 1;
        اگر (((flags & DIF_پہلا) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_سائز(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        اگر ((tok == TOK_LSTR && 
#اگر_تعریف_شدہ TCC_ہدف_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ورنہ
             (t1->t & VT_BTYPE) == VT_INT
#اگر_ختم
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            اگر (size1 != (tok == TOK_STR ? 1 : حجم(nwchar_t)))
              tcc_error("unhandled string literal merging");
            جب (tok == TOK_STR || tok == TOK_LSTR) {
                اگر (initstr.سائز)
                  initstr.سائز -= size1;
                اگر (tok == TOK_STR)
                  len += tokc.str.سائز;
                ورنہ
                  len += tokc.str.سائز / حجم(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.ڈیٹا, tokc.str.سائز);
                اگلا();
            }
            اگر (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.سائز = initstr.سائز;
                tokc.str.ڈیٹا = initstr.ڈیٹا;
                جاؤ do_init_array;
            }

            decl_design_flex(p, s, len);
            اگر (!(flags & DIF_سائز_ONLY)) {
                صحیح nb = n, ch;
                اگر (len < nb)
                    nb = len;
                اگر (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                اگر (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    اگر (!NODATA_WANTED)
                      حافظہ_نقل(p->sec->ڈیٹا + c, initstr.ڈیٹا, nb);
                } ورنہ {
                    برائے(i=0;i<n;i++) {
                        اگر (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          اگر (flags & DIF_CLEAR)
                            توڑو;
                          اگر (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            توڑو;
                          }
                          ch = 0;
                        } ورنہ اگر (size1 == 1)
                          ch = ((غیرعلامتی حرف *)initstr.ڈیٹا)[i];
                        ورنہ
                          ch = ((nwchar_t *)initstr.ڈیٹا)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            اگر (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                اگلا();
        } ورنہ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            اگر (!(flags & (DIF_CLEAR | DIF_سائز_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    جب (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		اگر (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    اگر (no_oblock && len >= n*size1)
		        توڑو;
		} ورنہ {
		    اگر (s->type.t == VT_UNION)
		        f = تہی;
		    ورنہ
		        f = f->اگلا;
		    اگر (no_oblock && f == تہی)
		        توڑو;
		}

		اگر (tok == '}')
		    توڑو;
		skip(',');
	    }
        }
        اگر (!no_oblock)
            skip('}');

    } ورنہ اگر ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        جاؤ one_elem;

    } ورنہ اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        اگر ((flags & DIF_پہلا) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->اگلا;
        n = s->c;
        size1 = 1;
	جاؤ do_init_list;

    } ورنہ اگر (tok == '{') {
        اگر (flags & DIF_HAVE_ELEM)
          skip(';');
        اگلا();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ورنہ one_elem: اگر ((flags & DIF_سائز_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        اگر (flags & DIF_HAVE_ELEM)
            vpop();
        ورنہ
            skip_or_save_بلاک(تہی);

    } ورنہ {
	اگر (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    اگر (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? اظہاریہ_ANY : اظہاریہ_CONST);
	}
        اگر (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_سائز(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ورنہ
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
ساکن خالی decl_initializer_alloc(CType *type, AttributeDef *ad, صحیح r, 
                                   صحیح has_init, صحیح v, صحیح scope)
{
    صحیح سائز, align, addr;
    TokenString *init_str = تہی;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = تہی;
    صحیح saved_nocode_wanted = nocode_wanted;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    صحیح bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#اگر_ختم
    init_params p = {0};

    اگر (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_ڈھونڈو(v);
        اگر (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            اگر (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                واپس;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    اگر (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= ڈیٹا_ONLY_WANTED;

    flexible_array = تہی;
    سائز = type_سائز(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    اگر (سائز < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        اگر (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        اگر (IS_BT_ARRAY(type->t))
            type->ref = sym_ڈالو(SYM_میدان, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ورنہ اگر (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *میدان = type->ref->اگلا;
        اگر (میدان) {
            جب (میدان->اگلا)
                میدان = میدان->اگلا;
            اگر (میدان->type.t & VT_ARRAY && میدان->type.ref->c < 0) {
                flexible_array = میدان;
                p.flex_array_ref = میدان->type.ref;
                سائز = -1;
            }
        }
    }

    اگر (سائز < 0) {
        /* If unknown size, do a dry-run 1st pass */
        اگر (!has_init)
            جاؤ err_سائز;
        اگر (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            جب (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_جوڑو_tok(init_str);
                اگلا();
            }
            tok_str_جوڑو(init_str, TOK_EOF);
        } ورنہ
            skip_or_save_بلاک(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        اگلا();
        decl_initializer(&p, type, 0, DIF_پہلا | DIF_سائز_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        اگلا();

        /* if still unknown size, error */
        سائز = type_سائز(type, &align);
        اگر (سائز < 0)
    err_سائز:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        اگر (flexible_array && flexible_array->type.ref->c > 0)
            سائز += flexible_array->type.ref->c
                    * pointed_سائز(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    اگر (ad->a.aligned) {
	صحیح speca = 1 << (ad->a.aligned - 1);
        اگر (speca > align)
            align = speca;
    } ورنہ اگر (ad->a.packed) {
        align = 1;
    }

    اگر (!v && NODATA_WANTED)
        سائز = 0, align = 1;

    اگر ((r & VT_VALMASK) == VT_LOCAL) {
        sec = تہی;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#اگر_ختم
        loc = (loc - سائز) & -align;
        addr = loc;
        p.local_انحراف = addr + سائز;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#اگر_ختم
        اگر (v) {
            /* local variable */
#اگر_تعریف_شدہ CONFIG_TCC_ASM
	    اگر (ad->asm_label) {
		صحیح reg = asm_parse_regvar(ad->asm_label);
		اگر (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#اگر_ختم
            sym = sym_ڈالو(v, type, r, addr);
	    اگر (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_میدان | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->اگلا = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ورنہ {
            /* push local reference */
            vset(type, r, addr);
        }
    } ورنہ {
        CType *tp = type;
        صحیح is_const;

        جب ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        اگر (!sec) {
            اگر (type->t & VT_TLS) {
                sec = ڈھونڈو_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ورنہ اگر (is_const) {
		sec = rodata_section;
            } ورنہ اگر (has_init) {
		sec = ڈیٹا_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ورنہ اگر (tcc_state->nocommon)
                sec = bss_section;
        } ورنہ اگر (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            اگر (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                اگر (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (bcheck)
            سائز = سائز + 1; /* add padding */
#اگر_ختم
        اگر (sec) {
	    addr = section_جوڑو(sec, سائز, align);
        } ورنہ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        اگر (v) {
            اگر (!sym) {
                sym = sym_ڈالو(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, تہی);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, سائز);
        } ورنہ {
            /* push global reference */
            vpush_ref(type, sec, addr, سائز);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        اگر (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->ڈیٹا_انحراف, R_ڈیٹا_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_جوڑو(bounds_section, 2 * حجم(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = سائز - 1;
        }
#اگر_ختم
    }

    اگر (type->t & VT_VLA) {
        صحیح a;

        اگر (has_init)
            tcc_error("variable length array cannot be initialized");

        اگر (NODATA_WANTED)
            جاؤ no_alloc;

        /* save before-VLA stack pointer if needed */
        اگر (cur_scope->vla.عدد == 0) {
            اگر (cur_scope->پچھلا && cur_scope->پچھلا->vla.عدد) {
                cur_scope->vla.locorig = cur_scope->پچھلا->vla.loc;
            } ورنہ {
                gen_vla_sp_save(loc -= PTR_سائز);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_سائز(type, &a);
        gen_vla_alloc(type, a);
#اگر defined TCC_ہدف_PE && defined TCC_ہدف_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_نتیجہ(addr), addr = (loc -= PTR_سائز);
#اگر_ختم
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.عدد++;
    } ورنہ اگر (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_پہلا);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        اگر (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    اگر (init_str) {
        انتہا_macro();
        اگلا();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ساکن خالی func_vla_arg_رمز(Sym *arg)
{
    صحیح align;
    TokenString *vla_array_tok = تہی;

    اگر (arg->type.ref)
        func_vla_arg_رمز(arg->type.ref);

    اگر ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_سائز(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	اگلا();
	gexpr();
	انتہا_macro();
	اگلا();
	vpush_type_سائز(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

ساکن خالی func_vla_arg(Sym *sym)
{
    Sym *arg;

    برائے (arg = sym->type.ref->اگلا; arg; arg = arg->اگلا)
        اگر ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_رمز(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_سیٹ_param(Sym *s, صحیح c, صحیح byref)
{
    s = sym_ڈھونڈو(s->v);
    اگر (!s) /* unnamed parameters, not enabled */
        واپس تہی;
    s->c = c;
    اگر (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    واپس s;
}

/* push parameters (and their types), last first */
ساکن خالی sym_ڈالو_params(Sym *ref)
{
    Sym *s = ref;
    جب (s->اگلا)
        s = s->اگلا;
    جب (s != ref) {
        اگر ((s->v & ~SYM_STRUCT) < SYM_پہلا_ANOM)
            sym_copy(s, &local_ڈھیر);
        s = s->پچھلا;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ساکن خالی gen_function(Sym *sym)
{
    ساخت scope f = { 0 };

    cur_scope = جڑ_scope = &f;
    nocode_wanted = 0;

    ind = cur_متن_section->ڈیٹا_انحراف;
    اگر (sym->a.aligned) {
	سائز_t newoff = section_جوڑو(cur_متن_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, تہی);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_متن_section, ind, 0);

    اگر (sym->type.ref->f.func_ctor)
        جوڑو_array (tcc_state, ".init_array", sym->c);
    اگر (sym->type.ref->f.func_dtor)
        جوڑو_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ڈھیر, SYM_میدان, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ڈالو_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_عارضی_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    بلاک(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_انتہا_scope(تہی, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_سائز = ind - func_ind;
    cur_متن_section->ڈیٹا_انحراف = ind;

    sym_نکالو(&local_ڈھیر, تہی, 0);
    label_نکالو(&global_label_ڈھیر, تہی, 0);
    sym_نکالو(&all_cleanups, تہی, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_متن_section = تہی;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = ڈیٹا_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    اگلا();
}

ساکن خالی gen_inline_functions(TCCState *s)
{
    Sym *sym;
    صحیح inline_generated, i;
    ساخت InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    کرو {
        inline_generated = 0;
        برائے (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            اگر (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = تہی;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                اگلا();
                cur_متن_section = متن_section;
                gen_function(sym);
                انتہا_macro();

                inline_generated = 1;
            }
        }
    } جب (inline_generated);
    tcc_close();
}

ساکن خالی free_inline_functions(TCCState *s)
{
    صحیح i;
    /* free tokens of unused inline functions */
    برائے (i = 0; i < s->nb_inline_fns; ++i) {
        ساخت InlineFunc *fn = s->inline_fns[i];
        اگر (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ساکن خالی do_Static_assert(خالی)
{
    صحیح c;
    ثابت حرف *پیغام;

    اگلا();
    skip('(');
    c = اظہاریہ_const();
    پیغام = "_Static_assert fail";
    اگر (tok == ',') {
        اگلا();
        پیغام = parse_mult_str("string constant")->ڈیٹا;
    }
    skip(')');
    اگر (c == 0)
        tcc_error("%s", پیغام);
    skip(';');
}

#اگر_تعریف_شدہ TCC_ہدف_PE
ساکن خالی pe_check_linkage(CType *type, AttributeDef *ad)
{
    اگر (!ad->a.dllimport && !ad->a.dllexport)
        واپس;
    اگر (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    اگر (type->t & VT_TYPEDEF) {
        ثابت حرف *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ورنہ اگر (ad->a.dllimport) {
        اگر ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ورنہ
            type->t |= VT_EXTERN;
    }
}
#اگر_ختم

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ساکن صحیح decl(صحیح l)
{
    صحیح v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    جب (1) {

        oldint = 0;
        اگر (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            اگر (l == VT_JMP)
                واپس 0;
            /* skip redundant ';' if not in old parameter decl scope */
            اگر (tok == ';' && l != VT_CMP) {
                اگلا();
                جاری;
            }
            اگر (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                جاری;
            }
            اگر (l != VT_CONST)
                توڑو;
            اگر (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                جاری;
            }
            اگر (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ورنہ {
                اگر (tok != TOK_EOF)
                    expect("declaration");
                توڑو;
            }
        }

        اگر (tok == ';') {
            اگر ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_پہلا_ANOM)
                ; /* struct decl with named tag */
            ورنہ اگر (IS_ENUM(btype.t))
                ; /* enum decl */
            ورنہ
                tcc_warning("useless type defines no instances");
            اگر (l == VT_JMP)
                واپس 1;
            اگلا();
            جاری;
        }

        جب (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_براہ_راست | TYPE_PARAM : TYPE_براہ_راست);
            /*ptype("decl", &type, v);*/
            اگر ((type.t & VT_BTYPE) == VT_FUNC) {
                اگر ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                اگر (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                اگر ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    اگر (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ورنہ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ورنہ اگر (oldint) {
                tcc_warning("type defaults to int");
            }

            اگر (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #اگر 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                اگر (tok == '{')
                    expect(";");
            #اگر_ختم
            }

#اگر_تعریف_شدہ TCC_ہدف_PE
            pe_check_linkage(&type, &ad);
#اگر_ختم
            اگر (tok == '{') {
                اگر (l != VT_CONST)
                    tcc_error("cannot use local functions");
                اگر ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                ملاؤ_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                برائے (sa = sym->type.ref; (sa = sa->اگلا) != تہی;) {
                    اگر (!(sa->v & ~SYM_میدان))
                        expect("identifier");
                    اگر (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                اگر (sym->type.t & VT_INLINE) {
                    ساخت InlineFunc *fn;
                    fn = tcc_malloc(حجم *fn + لڑی_لمبائی(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_جوڑو(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_بلاک(&fn->func_str);
                } ورنہ {
                    /* compute text section */
                    cur_متن_section = متن_section;
                    اگر (ad.section) {
                        cur_متن_section = ad.section;
                        اگر (ad.new_section)
                            ad.section->sh_flags = متن_section->sh_flags;
                    }
                    gen_function(sym);
                }
                توڑو;
            } ورنہ {
                has_init = 0;
		اگر (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    برائے (sym = func_vt.ref->اگلا; sym; sym = sym->اگلا)
			اگر ((sym->v & ~SYM_میدان) == v)
			    جاؤ ملا;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, تہی));
                ملا:
		    اگر (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, تہی));
		    اگر (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, تہی));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ورنہ اگر (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_ڈھونڈو(v);
                    اگر (sym && sym->sym_scope == local_scope) {
                        اگر (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, تہی));
                        sym->type = type;
                    } ورنہ {
                        sym = sym_ڈالو(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    اگر ((type.t & VT_BTYPE) == VT_FUNC)
                      ملاؤ_funcattr(&sym->type.ref->f, &ad.f);
                    اگر (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ورنہ اگر ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ورنہ {
                    r = 0;
                    اگر ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        ملاؤ_funcattr(&type.ref->f, &ad.f);
                    } ورنہ اگر (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    اگر (tok == '=')
                        has_init = 1;

                    اگر (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ورنہ {
                        اگر (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ورنہ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        اگر (has_init)
                            اگلا();
                        ورنہ اگر (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    اگر (ad.alias_ہدف && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_ڈھونڈو(ad.alias_ہدف));
                        اگر (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_ڈھونڈو(v), esym->st_shndx,
                                        esym->st_قدر, esym->st_سائز, 1);
                    }
                }
                اگر (tok != ',') {
                    اگر (l == VT_JMP)
                        واپس has_init ? v : 1;
                    skip(';');
                    توڑو;
                }
                اگلا();
            }
        }
    }
    واپس 0;
}

/* ------------------------------------------------------------------------- */
#تعریف_منسوخ gjmp_addr
#تعریف_منسوخ gjmp
/* ------------------------------------------------------------------------- */
