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
#অন্তর্ভাব "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_তথ্য পূর্ণসংখ্যা rsym, anon_sym, ind, loc;

ST_তথ্য Sym *global_স্তূপ;
ST_তথ্য Sym *local_স্তূপ;
ST_তথ্য Sym *define_স্তূপ;
ST_তথ্য Sym *global_label_স্তূপ;
ST_তথ্য Sym *local_label_স্তূপ;

স্থির Sym *sym_free_first;
স্থির শূন্য **sym_pools;
স্থির পূর্ণসংখ্যা nb_sym_pools;

স্থির Sym *all_cleanups, *pending_gotos;
স্থির পূর্ণসংখ্যা local_scope;
ST_তথ্য অক্ষর debug_modes;

ST_তথ্য SValue *vtop;
স্থির SValue _vstack[1 + VSTACK_আকার];
#define vstack (_vstack + 1)

ST_তথ্য পূর্ণসংখ্যা nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define তথ্য_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() যদি(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_তথ্য পূর্ণসংখ্যা global_রাশিমালা;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_তথ্য CType func_vt; /* current function return type (used by return instruction) */
ST_তথ্য পূর্ণসংখ্যা func_var; /* true if current function is variadic (used by return instruction) */
ST_তথ্য পূর্ণসংখ্যা func_vc; /* stack address for implicit struct return storage */
ST_তথ্য পূর্ণসংখ্যা func_ind; /* function start address */
স্থির পূর্ণসংখ্যা func_old;
ST_তথ্য ধ্রুবক অক্ষর *funcname;
ST_তথ্য CType int_type, func_old_type, char_type, char_pointer_type;
স্থির CString initstr;

#যদি PTR_আকার == 4
#define VT_আকার_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#নতুবা_যদি LONG_আকার == 4
#define VT_আকার_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#অন্যথা
#define VT_আকার_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

স্থির কাঠামো switch_t {
    কাঠামো case_t {
        int64_t v1, v2;
        পূর্ণসংখ্যা ind, সারি;
    } **p; পূর্ণসংখ্যা n; /* list of case ranges */
    পূর্ণসংখ্যা def_sym; /* default symbol */
    পূর্ণসংখ্যা nocode_wanted;
    পূর্ণসংখ্যা *bsym;
    কাঠামো scope *scope;
    কাঠামো switch_t *পূর্ব;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_অস্থায়ী_LOCAL_VARIABLE_সংখ্যা 8
/*list of temporary local variables on the stack in current function. */
স্থির কাঠামো অস্থায়ী_local_variable {
	পূর্ণসংখ্যা location; //offset on stack. Svalue.c.i
	short আকার_2;
	short align;
} arr_অস্থায়ী_local_vars[MAX_অস্থায়ী_LOCAL_VARIABLE_সংখ্যা];
স্থির পূর্ণসংখ্যা nb_অস্থায়ী_local_vars;

স্থির কাঠামো scope {
    কাঠামো scope *পূর্ব;
    কাঠামো { পূর্ণসংখ্যা loc, locorig, অঙ্ক; } vla;
    কাঠামো { Sym *s; পূর্ণসংখ্যা n; } cl;
    পূর্ণসংখ্যা *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *মূল_scope;

প্রকারলেখ কাঠামো {
    Section *sec;
    পূর্ণসংখ্যা local_offset;
    Sym *flex_array_ref;
} init_params;

#যদি 1
#define precedence_parser
স্থির শূন্য init_prec(শূন্য);
#endif

স্থির শূন্য block(পূর্ণসংখ্যা flags);
#define STMT_রাশিমালা 1
#define STMT_COMPOUND 2

স্থির শূন্য gen_cast(CType *type);
স্থির শূন্য gen_cast_s(পূর্ণসংখ্যা t);
স্থির অন্তঃরেখ CType *pointed_type(CType *type);
স্থির শূন্য check_restrict_type(CType *type);
স্থির পূর্ণসংখ্যা type_qualifiers(CType *type);
স্থির শূন্য parse_btype_qualify(CType *type, পূর্ণসংখ্যা qualifiers);
স্থির পূর্ণসংখ্যা is_compatible_types(CType *type1, CType *type2);
স্থির পূর্ণসংখ্যা parse_btype(CType *type, AttributeDef *ad, পূর্ণসংখ্যা ignore_label);
স্থির CType *type_decl(CType *type, AttributeDef *ad, পূর্ণসংখ্যা *v, পূর্ণসংখ্যা td);
স্থির শূন্য parse_রাশিমালা_type(CType *type);
স্থির শূন্য init_putv(init_params *p, CType *type, unsigned long c);
স্থির শূন্য decl_initializer(init_params *p, CType *type, unsigned long c, পূর্ণসংখ্যা flags);
স্থির শূন্য decl_initializer_alloc(CType *type, AttributeDef *ad, পূর্ণসংখ্যা r, পূর্ণসংখ্যা has_init, পূর্ণসংখ্যা v, পূর্ণসংখ্যা scope);
স্থির পূর্ণসংখ্যা decl(পূর্ণসংখ্যা l);
স্থির শূন্য রাশিমালা_eq(শূন্য);
স্থির শূন্য vpush_type_আকার(CType *type, পূর্ণসংখ্যা *a);
স্থির পূর্ণসংখ্যা is_compatible_unqualified_types(CType *type1, CType *type2);
স্থির অন্তঃরেখ int64_t রাশিমালা_const64(শূন্য);
স্থির শূন্য vpush64(পূর্ণসংখ্যা ty, unsigned long long v);
স্থির শূন্য vpush(CType *type);
স্থির পূর্ণসংখ্যা gvtst(পূর্ণসংখ্যা inv, পূর্ণসংখ্যা t);
স্থির শূন্য gen_inline_functions(TCCState *s);
স্থির শূন্য free_inline_functions(TCCState *s);
স্থির শূন্য skip_or_save_block(TokenString **str);
স্থির শূন্য gv_dup(শূন্য);
স্থির পূর্ণসংখ্যা get_অস্থায়ী_local_var(পূর্ণসংখ্যা আকার_2,পূর্ণসংখ্যা align,পূর্ণসংখ্যা *r2);
স্থির শূন্য cast_error(CType *st, CType *dt);
স্থির শূন্য end_switch(শূন্য);
স্থির শূন্য do_Static_assert(শূন্য);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC শূন্য gsym(পূর্ণসংখ্যা t)
{
  যদি (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
স্থির পূর্ণসংখ্যা gind()
{
  পূর্ণসংখ্যা t = ind;
  CODE_ON();
  যদি (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  ফেরত t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
স্থির শূন্য gjmp_addr_acs(পূর্ণসংখ্যা t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
স্থির পূর্ণসংখ্যা gjmp_acs(পূর্ণসংখ্যা t)
{
  t = gjmp(t);
  CODE_OFF();
  ফেরত t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN পূর্ণসংখ্যা is_float(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা bt = t & VT_BTYPE;
    ফেরত bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

স্থির অন্তঃরেখ পূর্ণসংখ্যা is_integer_btype(পূর্ণসংখ্যা bt)
{
    ফেরত bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

স্থির পূর্ণসংখ্যা btype_আকার(পূর্ণসংখ্যা bt)
{
    ফেরত bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_আকার : 0;
}

/* returns function return register from type */
স্থির পূর্ণসংখ্যা R_RET(পূর্ণসংখ্যা t)
{
    যদি (!is_float(t))
        ফেরত REG_IRET;
#ifdef TCC_TARGET_X86_64
    যদি ((t & VT_BTYPE) == VT_LDOUBLE)
        ফেরত TREG_ST0;
#নতুবা_যদি defined TCC_TARGET_RISCV64
    যদি ((t & VT_BTYPE) == VT_LDOUBLE)
        ফেরত REG_IRET;
#endif
    ফেরত REG_FRET;
}

/* returns 2nd function return register, if any */
স্থির পূর্ণসংখ্যা R2_RET(পূর্ণসংখ্যা t)
{
    t &= VT_BTYPE;
#যদি PTR_আকার == 4
    যদি (t == VT_LLONG)
        ফেরত REG_IRE2;
#নতুবা_যদি defined TCC_TARGET_X86_64
    যদি (t == VT_QLONG)
        ফেরত REG_IRE2;
    যদি (t == VT_QFLOAT)
        ফেরত REG_FRE2;
#নতুবা_যদি defined TCC_TARGET_RISCV64
    যদি (t == VT_LDOUBLE)
        ফেরত REG_IRE2;
#endif
    ফেরত VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_শব্দগুলি(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
স্থির শূন্য PUT_R_RET(SValue *sv, পূর্ণসংখ্যা t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
স্থির পূর্ণসংখ্যা RC_RET(পূর্ণসংখ্যা t)
{
    ফেরত reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
স্থির পূর্ণসংখ্যা RC_TYPE(পূর্ণসংখ্যা t)
{
    যদি (!is_float(t))
        ফেরত RC_INT;
#ifdef TCC_TARGET_X86_64
    যদি ((t & VT_BTYPE) == VT_LDOUBLE)
        ফেরত RC_ST0;
    যদি ((t & VT_BTYPE) == VT_QFLOAT)
        ফেরত RC_FRET;
#নতুবা_যদি defined TCC_TARGET_RISCV64
    যদি ((t & VT_BTYPE) == VT_LDOUBLE)
        ফেরত RC_INT;
#endif
    ফেরত RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
স্থির পূর্ণসংখ্যা RC2_TYPE(পূর্ণসংখ্যা t, পূর্ণসংখ্যা rc)
{
    যদি (!USING_TWO_শব্দগুলি(t))
        ফেরত 0;
#ifdef RC_IRE2
    যদি (rc == RC_IRET)
        ফেরত RC_IRE2;
#endif
#ifdef RC_FRE2
    যদি (rc == RC_FRET)
        ফেরত RC_FRE2;
#endif
    যদি (rc & RC_FLOAT)
        ফেরত RC_FLOAT;
    ফেরত RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC পূর্ণসংখ্যা ieee_finite(দ্বিগুণ d)
{
    পূর্ণসংখ্যা p[4];
    memcpy(p, &d, আকার(দ্বিগুণ));
    ফেরত ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC শূন্য test_lvalue(শূন্য)
{
    যদি (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC শূন্য check_vstack(শূন্য)
{
    যদি (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (পূর্ণসংখ্যা)(vtop - vstack + 1));
}

#যদি 0
/* dump 'b' vstack entries starting with 'a'  */
শূন্য pv (ধ্রুবক অক্ষর *lbl, পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
    পূর্ণসংখ্যা i;
    জন্য (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (পূর্ণসংখ্যা)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
স্থির অন্তঃরেখ শূন্য psyms(ধ্রুবক অক্ষর *বার্তা, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", বার্তা);
    যখন (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->পূর্ব;
    }
}

স্থির শূন্য type_to_str(অক্ষর *buf, পূর্ণসংখ্যা buf_আকার, CType *type, ধ্রুবক অক্ষর *varstr);

/* print type */
স্থির শূন্য ptype(ধ্রুবক অক্ষর *বার্তা, CType *type, পূর্ণসংখ্যা v)
{
    অক্ষর buf[500];
    type_to_str(buf, আকার(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, ফাঁকা) : ফাঁকা);
    printf("%s : %s;\n", বার্তা, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC শূন্য tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, আকার *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    যদি (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ঠেলো(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC পূর্ণসংখ্যা tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = তথ্য_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_রাশিমালা = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_অঙ্ক | PARSE_FLAG_TOK_STR;
    পরবর্তী();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#যদি TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    ফেরত 0;
}

ST_FUNC শূন্য tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_বের_করো(&global_স্তূপ, ফাঁকা, 0);
    sym_বের_করো(&local_স্তূপ, ফাঁকা, 0);
    /* free preprocessor macros */
    free_defines(ফাঁকা);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_তথ্য, &nb_stk_তথ্য);
    যখন (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = ফাঁকা;
    all_cleanups = ফাঁকা;
    pending_gotos = ফাঁকা;
    nb_অস্থায়ী_local_vars = 0;
    global_label_স্তূপ = ফাঁকা;
    local_label_স্তূপ = ফাঁকা;
    cur_text_section = ফাঁকা;
    sym_free_first = ফাঁকা;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  যদি (!s || !s->c)
    ফেরত ফাঁকা;
  ফেরত &((ElfSym *)symtab_section->তথ্য)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC শূন্য update_storage(Sym *sym)
{
    ElfSym *esym;
    পূর্ণসংখ্যা sym_bind, old_sym_bind;

    esym = elfsym(sym);
    যদি (!esym)
        ফেরত;

    যদি (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    যদি (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    অন্যথা যদি (sym->a.weak)
        sym_bind = STB_WEAK;
    অন্যথা
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    যদি (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    যদি (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    যদি (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#যদি 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ফাঁকা),
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

ST_FUNC শূন্য put_extern_sym2(Sym *sym, পূর্ণসংখ্যা sh_অঙ্ক,
                            addr_t মান, unsigned long আকার_2,
                            পূর্ণসংখ্যা can_add_underscore)
{
    পূর্ণসংখ্যা sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ধ্রুবক অক্ষর *name;
    অক্ষর buf1[256];

    যদি (!sym->c) {
        name = get_tok_str(sym->v, ফাঁকা);
        t = sym->type.t;
        যদি ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } অন্যথা যদি ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            যদি (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } অন্যথা যদি (t & VT_TLS) {
            sym_type = STT_TLS;
        } অন্যথা {
            sym_type = STT_OBJECT;
        }
        যদি (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        অন্যথা
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        যদি (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            যদি (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            যদি (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_আকার);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        যদি (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ফাঁকা);
            can_add_underscore = 0;
        }

        যদি (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, আকার(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, মান, আকার_2, info, other, sh_অঙ্ক, name);

        যদি (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_অঙ্ক, sym_bind, sym_type);

    } অন্যথা {
        esym = elfsym(sym);
        esym->st_মান = মান;
        esym->st_আকার = আকার_2;
        esym->st_shndx = sh_অঙ্ক;
    }
    update_storage(sym);
}

ST_FUNC শূন্য put_extern_sym(Sym *sym, Section *s, addr_t মান, unsigned long আকার_2)
{
    যদি (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        ফেরত;
    put_extern_sym2(sym, s ? s->sh_অঙ্ক : SHN_UNDEF, মান, আকার_2, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC শূন্য greloca(Section *s, Sym *sym, unsigned long offset, পূর্ণসংখ্যা type,
                     addr_t addend)
{
    পূর্ণসংখ্যা c = 0;

    যদি (nocode_wanted && s == cur_text_section)
        ফেরত;

    যদি (sym) {
        যদি (0 == sym->c) {
            put_extern_sym(sym, ফাঁকা, 0, 0);
            যদি (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                যখন (s->পূর্ব_tok)
                    s = s->পূর্ব_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#যদি PTR_আকার == 4
ST_FUNC শূন্য greloc(Section *s, Sym *sym, unsigned long offset, পূর্ণসংখ্যা type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
স্থির Sym *__sym_malloc(শূন্য)
{
    Sym *sym_pool, *sym, *last_sym;
    পূর্ণসংখ্যা i;

    sym_pool = tcc_malloc(SYM_POOL_NB * আকার(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    জন্য(i = 0; i < SYM_POOL_NB; i++) {
        sym->পরবর্তী = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    ফেরত last_sym;
}

স্থির অন্তঃরেখ Sym *sym_malloc(শূন্য)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    যদি (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->পরবর্তী;
    ফেরত sym;
#অন্যথা
    sym = tcc_malloc(আকার(Sym));
    ফেরত sym;
#endif
}

ST_INLN শূন্য sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->পরবর্তী = sym_free_first;
    sym_free_first = sym;
#অন্যথা
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, পূর্ণসংখ্যা v, পূর্ণসংখ্যা t, পূর্ণসংখ্যা c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, আকার *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->পূর্ব = *ps;
    *ps = s;
    ফেরত s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, পূর্ণসংখ্যা v)
{
    যখন (s) {
        যদি (s->v == v)
            ফেরত s;
        s = s->পূর্ব;
    }
    ফেরত ফাঁকা;
}

/* structure lookup */
ST_INLN Sym *struct_find(পূর্ণসংখ্যা v)
{
    v -= TOK_IDENT;
    যদি ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ফেরত ফাঁকা;
    ফেরত table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(পূর্ণসংখ্যা v)
{
    v -= TOK_IDENT;
    যদি ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ফেরত ফাঁকা;
    ফেরত table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
স্থির অন্তঃরেখ শূন্য sym_link(Sym *s, পূর্ণসংখ্যা yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    যদি (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    অন্যথা
        ps = &ts->sym_identifier;
    যদি (yes) {
        s->পূর্ব_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } অন্যথা {
        *ps = s->পূর্ব_tok;
    }
}

স্থির অন্তঃরেখ পূর্ণসংখ্যা sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ফেরত IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ঠেলো(পূর্ণসংখ্যা v, CType *type, পূর্ণসংখ্যা r, পূর্ণসংখ্যা c)
{
    Sym *s, **ps;
    যদি (local_স্তূপ)
        ps = &local_স্তূপ;
    অন্যথা
        ps = &global_স্তূপ;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    যদি ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        যদি (s->পূর্ব_tok && sym_scope_ex(s->পূর্ব_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ফাঁকা));
    }
    ফেরত s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ঠেলো(পূর্ণসংখ্যা v, পূর্ণসংখ্যা t, পূর্ণসংখ্যা c)
{
    Sym *s, **ps;
    s = sym_push2(&global_স্তূপ, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    যদি (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        যখন (*ps != ফাঁকা && (*ps)->sym_scope)
            ps = &(*ps)->পূর্ব_tok;
        s->পূর্ব_tok = *ps;
        *ps = s;
    }
    ফেরত s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC শূন্য sym_বের_করো(Sym **ptop, Sym *b, পূর্ণসংখ্যা keep)
{
    Sym *s, *ss;
    পূর্ণসংখ্যা v;

    s = *ptop;
    যখন(s != b) {
        ss = s->পূর্ব;
        v = s->v;
        /* remove symbol in token array */
        যদি ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	যদি (!keep)
	    sym_free(s);
        s = ss;
    }
    যদি (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(পূর্ণসংখ্যা v)
{
    v -= TOK_IDENT;
    যদি ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ফেরত ফাঁকা;
    ফেরত table_ident[v]->sym_label;
}

ST_FUNC Sym *label_ঠেলো(Sym **ptop, পূর্ণসংখ্যা v, পূর্ণসংখ্যা flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    যদি (ptop == &global_label_স্তূপ) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        যখন (*ps != ফাঁকা)
            ps = &(*ps)->পূর্ব_tok;
    }
    s->পূর্ব_tok = *ps;
    *ps = s;
    ফেরত s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC শূন্য label_বের_করো(Sym **ptop, Sym *slast, পূর্ণসংখ্যা keep)
{
    Sym *s, *s1;
    জন্য(s = *ptop; s != slast; s = s1) {
        s1 = s->পূর্ব;
        যদি (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ফাঁকা));
        } অন্যথা যদি (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ফাঁকা));
        } অন্যথা {
            যদি (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        যদি (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->পূর্ব_tok;
        যদি (!keep)
            sym_free(s);
        অন্যথা
            s->r = LABEL_GONE;
    }
    যদি (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
স্থির শূন্য vcheck_cmp(শূন্য)
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

    যদি (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

স্থির শূন্য vsetc(CType *type, পূর্ণসংখ্যা r, CValue *vc)
{
    যদি (vtop >= vstack + (VSTACK_আকার - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ফাঁকা;
}

ST_FUNC শূন্য vswap(শূন্য)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC শূন্য vpop(শূন্য)
{
    পূর্ণসংখ্যা v;
    v = vtop->r & VT_VALMASK;
#যদি defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    যদি (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } অন্যথা
#endif
    যদি (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
স্থির শূন্য vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
স্থির শূন্য vpush64(পূর্ণসংখ্যা ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ফাঁকা;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC শূন্য vpushi(পূর্ণসংখ্যা v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
স্থির শূন্য vpushs(addr_t v)
{
    vpush64(VT_আকার_T, v);
}

/* push long long constant */
স্থির অন্তঃরেখ শূন্য vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC শূন্য vset(CType *type, পূর্ণসংখ্যা r, পূর্ণসংখ্যা v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

স্থির শূন্য vseti(পূর্ণসংখ্যা r, পূর্ণসংখ্যা v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ফাঁকা;
    vset(&type, r, v);
}

ST_FUNC শূন্য vpushv(SValue *v)
{
    যদি (vtop >= vstack + (VSTACK_আকার - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

স্থির শূন্য vdup(শূন্য)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC শূন্য vrotb(পূর্ণসংখ্যা n)
{
    SValue tmp;
    যদি (--n < 1)
        ফেরত;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, আকার *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC শূন্য vrott(পূর্ণসংখ্যা n)
{
    SValue tmp;
    যদি (--n < 1)
        ফেরত;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, আকার *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC শূন্য vrev(পূর্ণসংখ্যা n)
{
    পূর্ণসংখ্যা i;
    SValue tmp;
    vcheck_cmp();
    জন্য (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC শূন্য vset_VT_CMP(পূর্ণসংখ্যা op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
স্থির শূন্য vset_VT_JMP(শূন্য)
{
    পূর্ণসংখ্যা op = vtop->cmp_op;

    যদি (vtop->jtrue || vtop->jfalse) {
        পূর্ণসংখ্যা origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        পূর্ণসংখ্যা inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } অন্যথা {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        যদি (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
স্থির শূন্য gvtst_set(পূর্ণসংখ্যা inv, পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা *p;

    যদি (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        যদি (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
স্থির পূর্ণসংখ্যা gvtst(পূর্ণসংখ্যা inv, পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    যদি (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    যদি (op > 1)
        t = gjmp_cond(op ^ inv, t);
    অন্যথা যদি (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ফেরত t;
}

/* generate a zero or nozero test */
স্থির শূন্য gen_test_zero(পূর্ণসংখ্যা op)
{
    যদি (vtop->r == VT_CMP) {
        পূর্ণসংখ্যা j;
        যদি (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } অন্যথা {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC শূন্য vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long আকার_2)
{
    পূর্ণসংখ্যা v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ঠেলো(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, আকার_2);
    ফেরত sym;
}

/* push a reference to a section offset by adding a dummy symbol */
স্থির শূন্য vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long আকার_2)
{
    vpushsym(type, get_sym_ref(type, sec, offset, আকার_2));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(পূর্ণসংখ্যা v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    যদি (!s) {
        /* push forward reference */
        s = global_identifier_ঠেলো(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } অন্যথা যদি (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ফেরত s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(পূর্ণসংখ্যা v)
{
    CType ct = { VT_ASM_FUNC, ফাঁকা };
    ফেরত external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC শূন্য vpush_helper_func(পূর্ণসংখ্যা v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
স্থির শূন্য merge_symattr(কাঠামো SymAttr *sa, কাঠামো SymAttr *sa1)
{
    যদি (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    যদি (sa1->visibility != STV_DEFAULT) {
	পূর্ণসংখ্যা vis = sa->visibility;
	যদি (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
স্থির শূন্য merge_funcattr(কাঠামো FuncAttr *fa, কাঠামো FuncAttr *fa1)
{
    যদি (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    যদি (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    যদি (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    যদি (fa1->func_noreturn)
      fa->func_noreturn = 1;
    যদি (fa1->func_ctor)
      fa->func_ctor = 1;
    যদি (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
স্থির শূন্য merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    যদি (ad1->section)
      ad->section = ad1->section;
    যদি (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    যদি (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    যদি (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
স্থির শূন্য patch_type(Sym *sym, CType *type)
{
    যদি (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        যদি (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ফাঁকা));
        sym->type.t &= ~VT_EXTERN;
    }

    যদি (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        যদি ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    যদি (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ফাঁকা));

    } অন্যথা যদি ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        পূর্ণসংখ্যা static_proto = sym->type.t & VT_STATIC;
        পূর্ণসংখ্যা ft1 = sym->type.ref->f.func_type;
        পূর্ণসংখ্যা ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        যদি ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ফাঁকা));

        /* set 'inline' if both agree or if one has static */
        যদি ((type->t | sym->type.t) & VT_INLINE) {
            যদি (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        যদি (0 == (type->t & VT_EXTERN)) {
            কাঠামো FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            যদি (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } অন্যথা {
            sym->type.t &= ~VT_INLINE | static_proto;
            যদি (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } অন্যথা {
        যদি ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        যদি ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ফাঁকা));
    }
}

/* Merge some storage attributes.  */
স্থির শূন্য patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    যদি (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    যদি (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ফাঁকা));
#endif
    merge_symattr(&sym->a, &ad->a);
    যদি (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
স্থির Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->পূর্ব = *ps, *ps = s;
    যদি ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    ফেরত s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
স্থির শূন্য move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    পূর্ণসংখ্যা n, bt;

    bt = s->type.t & VT_BTYPE;
    যদি (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ফেরত;

    জন্য (s = s->type.ref, n = 0; s; s = s->পরবর্তী) {
        জন্য (lp = &local_স্তূপ; !!(l = *lp); lp = &l->পূর্ব) {
            যদি (l == s) {
                *lp = s->পূর্ব;
                s->পূর্ব = global_স্তূপ, global_স্তূপ = s;
                যদি (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } অন্যথা {
                    যদি ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                যদি (bt != VT_PTR)
                    n = 1;
                বিরতি;
            }
        }
        যদি (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            বিরতি;
    }
}

/* define a new external reference to a symbol 'v' */
স্থির Sym *external_sym(পূর্ণসংখ্যা v, CType *type, পূর্ণসংখ্যা r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    যখন (s && s->sym_scope)
        s = s->পূর্ব_tok;

    যদি (!s) {
        /* push forward reference */
        s = global_identifier_ঠেলো(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } অন্যথা {
        patch_storage(s, ad, type);
    }
    যদি (local_স্তূপ) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_স্তূপ);
    }
    ফেরত s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC শূন্য save_regs(পূর্ণসংখ্যা n)
{
    SValue *p, *p1;
    জন্য(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC শূন্য save_reg(পূর্ণসংখ্যা r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC শূন্য save_reg_upstack(পূর্ণসংখ্যা r, পূর্ণসংখ্যা n)
{
    পূর্ণসংখ্যা l, আকার_2, align, bt, r2;
    SValue *p, *p1, sv;

    যদি ((r &= VT_VALMASK) >= VT_CONST)
        ফেরত;
    যদি (nocode_wanted)
        ফেরত;
    l = r2 = 0;
    জন্য(p = vstack, p1 = vtop - n; p <= p1; p++) {
        যদি ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            যদি (!l) {
                bt = p->type.t & VT_BTYPE;
                যদি (bt == VT_VOID)
                    চালু;
                যদি ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                আকার_2 = type_আকার(&sv.type, &align);
                l = get_অস্থায়ী_local_var(আকার_2, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ফাঁকা;
                store(p->r & VT_VALMASK, &sv);
#যদি defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                যদি (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                যদি (p->r2 < VT_CONST && USING_TWO_শব্দগুলি(bt)) {
                    sv.c.i += PTR_আকার;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            যদি (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } অন্যথা {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ফাঁকা;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC পূর্ণসংখ্যা get_reg_ex(পূর্ণসংখ্যা rc, পূর্ণসংখ্যা rc2)
{
    পূর্ণসংখ্যা r;
    SValue *p;
    
    জন্য(r=0;r<NB_REGS;r++) {
        যদি (reg_classes[r] & rc2) {
            পূর্ণসংখ্যা n;
            n=0;
            জন্য(p = vstack; p <= vtop; p++) {
                যদি ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            যদি (n <= 1)
                ফেরত r;
        }
    }
    ফেরত get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC পূর্ণসংখ্যা get_reg(পূর্ণসংখ্যা rc)
{
    পূর্ণসংখ্যা r;
    SValue *p;

    /* find a free register */
    জন্য(r=0;r<NB_REGS;r++) {
        যদি (reg_classes[r] & rc) {
            যদি (nocode_wanted)
                ফেরত r;
            জন্য(p=vstack;p<=vtop;p++) {
                যদি ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    যাও notfound;
            }
            ফেরত r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    জন্য(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        যদি (r < VT_CONST && (reg_classes[r] & rc))
            যাও save_found;
        r = p->r & VT_VALMASK;
        যদি (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            ফেরত r;
        }
    }
    /* Should never comes here */
    ফেরত -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
স্থির পূর্ণসংখ্যা get_অস্থায়ী_local_var(পূর্ণসংখ্যা আকার_2,পূর্ণসংখ্যা align, পূর্ণসংখ্যা *r2)
{
    পূর্ণসংখ্যা i;
    কাঠামো অস্থায়ী_local_variable *অস্থায়ী_var;
    SValue *p;
    পূর্ণসংখ্যা r;
    unsigned used = 0;

    /* mark locations that are still in use */
    জন্য (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	যদি (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    যদি (r >= 0 && r < MAX_অস্থায়ী_LOCAL_VARIABLE_সংখ্যা)
	        used |= 1<<r;
	}
    }
    জন্য (i=0;i<nb_অস্থায়ী_local_vars;i++) {
	অস্থায়ী_var=&arr_অস্থায়ী_local_vars[i];
	যদি(!(used & 1<<i)
	 && অস্থায়ী_var->আকার_2>=আকার_2
	 && অস্থায়ী_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ফেরত অস্থায়ী_var->location;
	}
    }
    loc = (loc - আকার_2) & -align;
    যদি (nb_অস্থায়ী_local_vars<MAX_অস্থায়ী_LOCAL_VARIABLE_সংখ্যা) {
	অস্থায়ী_var=&arr_অস্থায়ী_local_vars[i];
	অস্থায়ী_var->location=loc;
	অস্থায়ী_var->আকার_2=আকার_2;
	অস্থায়ী_var->align=align;
	nb_অস্থায়ী_local_vars++;
	যাও ret_tmp;
    }
    *r2 = VT_CONST;
    ফেরত loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
স্থির শূন্য move_reg(পূর্ণসংখ্যা r, পূর্ণসংখ্যা s, পূর্ণসংখ্যা t)
{
    SValue sv;

    যদি (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ফাঁকা;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC শূন্য gaddrof(শূন্য)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    যদি ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
স্থির শূন্য gen_bounded_ptr_add(শূন্য)
{
    পূর্ণসংখ্যা save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    যদি (save) {
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
    যদি (nocode_wanted)
        ফেরত;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->তথ্য_offset - আকার(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
স্থির শূন্য gen_bounded_ptr_deref(শূন্য)
{
    addr_t func;
    পূর্ণসংখ্যা আকার_2, align;
    ElfW_Rel *rel;
    Sym *sym;

    যদি (nocode_wanted)
        ফেরত;

    আকার_2 = type_আকার(&vtop->type, &align);
    নির্বাচন(আকার_2) {
    ক্ষেত্র  1: func = TOK___bound_ptr_indir1; বিরতি;
    ক্ষেত্র  2: func = TOK___bound_ptr_indir2; বিরতি;
    ক্ষেত্র  4: func = TOK___bound_ptr_indir4; বিরতি;
    ক্ষেত্র  8: func = TOK___bound_ptr_indir8; বিরতি;
    ক্ষেত্র 12: func = TOK___bound_ptr_indir12; বিরতি;
    ক্ষেত্র 16: func = TOK___bound_ptr_indir16; বিরতি;
    পূর্বনির্ধারিত:
        /* may happen with struct member access */
        ফেরত;
    }
    sym = external_helper_sym(func);
    যদি (!sym->c)
        put_extern_sym(sym, ফাঁকা, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->তথ্য + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
স্থির শূন্য gbound(শূন্য)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    যদি (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        যদি (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC শূন্য gbound_args(পূর্ণসংখ্যা nb_args)
{
    পূর্ণসংখ্যা i, v;
    SValue *sv;

    জন্য (i = 1; i <= nb_args; ++i)
        যদি (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    যদি (sv->r & VT_SYM) {
        v = sv->sym->v;
        যদি (v == TOK_setjmp
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
        যদি (v == TOK_alloca)
            func_bound_add_epilog = 1;
#যদি TARGETOS_NetBSD
        যদি (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
স্থির শূন্য add_local_bounds(Sym *s, Sym *e)
{
    জন্য (; s != e; s = s->পূর্ব) {
        যদি (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          চালু;
        /* Add arrays/structs/unions because we always take address */
        যদি ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            পূর্ণসংখ্যা align, আকার_2 = type_আকার(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * আকার(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = আকার_2;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
স্থির শূন্য tcc_debug_end_scope(Sym *b, পূর্ণসংখ্যা bounds)
{
#ifdef CONFIG_TCC_BCHECK
    যদি (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_স্তূপ, b);
#endif
    tcc_add_debug_info (tcc_state, local_স্তূপ, b);
}

/* increment an lvalue pointer */
স্থির শূন্য incr_offset(পূর্ণসংখ্যা offset)
{
    পূর্ণসংখ্যা t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

স্থির শূন্য incr_bf_adr(পূর্ণসংখ্যা o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
স্থির শূন্য load_packed_bf(CType *type, পূর্ণসংখ্যা bit_pos, পূর্ণসংখ্যা bit_আকার)
{
    পূর্ণসংখ্যা n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    করো {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        যদি (n > bit_আকার)
            n = bit_আকার;
        যদি (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        যদি (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        যদি (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_আকার -= n, o = 1;
    } যখন (bit_আকার);
    vswap(), vpop();
    যদি (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
স্থির শূন্য store_packed_bf(পূর্ণসংখ্যা bit_pos, পূর্ণসংখ্যা bit_আকার)
{
    পূর্ণসংখ্যা bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    করো {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        যদি (bits)
            vpushi(bits), gen_op(TOK_SHR);
        যদি (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        যদি (n > bit_আকার)
            n = bit_আকার;
        যদি (n < 8) {
            m = ((1 << n) - 1) << bit_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        bits += n, bit_আকার -= n, bit_pos = 0, o = 1;
    } যখন (bit_আকার);
    vpop(), vpop();
}

স্থির পূর্ণসংখ্যা adjust_bf(SValue *sv, পূর্ণসংখ্যা bit_pos, পূর্ণসংখ্যা bit_আকার)
{
    পূর্ণসংখ্যা t;
    যদি (0 == sv->type.ref)
        ফেরত 0;
    t = sv->type.ref->auxtype;
    যদি (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ফেরত t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC পূর্ণসংখ্যা gv(পূর্ণসংখ্যা rc)
{
    পূর্ণসংখ্যা r, r2, r_ok, r2_ok, rc2, bt;
    পূর্ণসংখ্যা bit_pos, bit_আকার, আকার_2, align;

    /* NOTE: get_reg can modify vstack[] */
    যদি (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_আকার = BIT_আকার(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = ফাঁকা;
        type.t = vtop->type.t & VT_UNSIGNED;
        যদি ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_আকার);

        যদি ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        অন্যথা
            type.t |= VT_INT;

        যদি (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_আকার);
        } অন্যথা {
            পূর্ণসংখ্যা bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(bits - (bit_pos + bit_আকার));
            gen_op(TOK_SHL);
            vpushi(bits - bit_আকার);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } অন্যথা {
        যদি (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            আকার_2 = type_আকার(&vtop->type, &align);
            যদি (NODATA_WANTED)
                আকার_2 = 0, align = 1;
            offset = section_add(p.sec, আকার_2, align);
            vpush_ref(&vtop->type, p.sec, offset, আকার_2);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        যদি (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        যদি (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ফেরত vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        যদি (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        যদি (!r_ok || !r2_ok) {

            যদি (!r_ok) {
                যদি (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                অন্যথা
                    r = get_reg(rc);
            }

            যদি (rc2) {
                পূর্ণসংখ্যা load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                পূর্ণসংখ্যা original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } অন্যথা যদি (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = load_type;
                    load(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_offset(PTR_আকার);
                } অন্যথা {
                    /* move registers */
                    যদি (!r_ok)
                        load(r, vtop);
                    যদি (r2_ok && vtop->r2 < VT_CONST)
                        যাও done;
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
            } অন্যথা {
                যদি (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        যদি (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    ফেরত r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC শূন্য gv2(পূর্ণসংখ্যা rc1, পূর্ণসংখ্যা rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    যদি (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        যদি ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } অন্যথা {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        যদি ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#যদি PTR_আকার == 4
/* expand 64bit on stack in two ints */
ST_FUNC শূন্য lexpand(শূন্য)
{
    পূর্ণসংখ্যা u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    যদি (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } অন্যথা যদি (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } অন্যথা {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#যদি PTR_আকার == 4
/* build a long long from two ints */
স্থির শূন্য lbuild(পূর্ণসংখ্যা t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
স্থির শূন্য gv_dup(শূন্য)
{
    পূর্ণসংখ্যা t, rc, r;

    t = vtop->type.t;
#যদি PTR_আকার == 4
    যদি ((t & VT_BTYPE) == VT_LLONG) {
        যদি (t & VT_BITFIELD) {
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
        ফেরত;
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

#যদি PTR_আকার == 4
/* generate CPU independent (unsigned) long long operations */
স্থির শূন্য gen_opl(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা t, a, b, op1, c, i;
    পূর্ণসংখ্যা func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    নির্বাচন(op) {
    ক্ষেত্র '/':
    ক্ষেত্র TOK_PDIV:
        func = TOK___divdi3;
        যাও gen_func;
    ক্ষেত্র TOK_UDIV:
        func = TOK___udivdi3;
        যাও gen_func;
    ক্ষেত্র '%':
        func = TOK___moddi3;
        যাও gen_mod_func;
    ক্ষেত্র TOK_UMOD:
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
        বিরতি;
    ক্ষেত্র '^':
    ক্ষেত্র '&':
    ক্ষেত্র '|':
    ক্ষেত্র '*':
    ক্ষেত্র '+':
    ক্ষেত্র '-':
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
        যদি (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            জন্য(i=0;i<4;i++)
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
        } অন্যথা যদি (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            যদি (op == '+')
                op1 = TOK_ADDC1;
            অন্যথা
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } অন্যথা {
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
        বিরতি;
    ক্ষেত্র TOK_SAR:
    ক্ষেত্র TOK_SHR:
    ক্ষেত্র TOK_SHL:
        যদি ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (পূর্ণসংখ্যা)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            যদি (op != TOK_SHL)
                vswap();
            যদি (c >= 32) {
                /* stack: L H */
                vpop();
                যদি (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                যদি (op != TOK_SAR) {
                    vpushi(0);
                } অন্যথা {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } অন্যথা {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                যদি (op == TOK_SHL)
                    gen_op(TOK_SHR);
                অন্যথা
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                যদি (op == TOK_SHL)
                    gen_op(TOK_SHL);
                অন্যথা
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            যদি (op != TOK_SHL)
                vswap();
            lbuild(t);
        } অন্যথা {
            /* XXX: should provide a faster fallback on x86 ? */
            নির্বাচন(op) {
            ক্ষেত্র TOK_SAR:
                func = TOK___ashrdi3;
                যাও gen_func;
            ক্ষেত্র TOK_SHR:
                func = TOK___lshrdi3;
                যাও gen_func;
            ক্ষেত্র TOK_SHL:
                func = TOK___ashldi3;
                যাও gen_func;
            }
        }
        বিরতি;
    পূর্বনির্ধারিত:
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
        যদি (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        যদি (op1 == TOK_LT)
            op1 = TOK_LE;
        অন্যথা যদি (op1 == TOK_GT)
            op1 = TOK_GE;
        অন্যথা যদি (op1 == TOK_ULT)
            op1 = TOK_ULE;
        অন্যথা যদি (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        যদি (op == TOK_NE) {
            b = gvtst(0, 0);
        } অন্যথা {
            a = gvtst(1, 0);
            যদি (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        যদি (op1 == TOK_LT)
            op1 = TOK_ULT;
        অন্যথা যদি (op1 == TOK_LE)
            op1 = TOK_ULE;
        অন্যথা যদি (op1 == TOK_GT)
            op1 = TOK_UGT;
        অন্যথা যদি (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#যদি 0//def TCC_TARGET_I386
        যদি (op == TOK_NE) { gsym(b); বিরতি; }
        যদি (op == TOK_EQ) { gsym(a); বিরতি; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        বিরতি;
    }
}
#endif

/* normalize values */
স্থির uint64_t value64(uint64_t l1, পূর্ণসংখ্যা t)
{
    যদি ((t & VT_BTYPE) == VT_LLONG
        || (PTR_আকার == 8 && (t & VT_BTYPE) == VT_PTR))
        ফেরত l1;
    অন্যথা যদি (t & VT_UNSIGNED)
        ফেরত (uint32_t)l1;
    অন্যথা
        ফেরত (uint32_t)l1 | -(l1 & 0x80000000);
}

স্থির uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ফেরত (a ^ b) >> 63 ? -x : x;
}

স্থির পূর্ণসংখ্যা gen_opic_lt(uint64_t a, uint64_t b)
{
    ফেরত (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
স্থির শূন্য gen_opic(পূর্ণসংখ্যা op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    পূর্ণসংখ্যা t1 = v1->type.t & VT_BTYPE;
    পূর্ণসংখ্যা t2 = v2->type.t & VT_BTYPE;
    পূর্ণসংখ্যা c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    পূর্ণসংখ্যা c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    পূর্ণসংখ্যা shm = (t1 == VT_LLONG) ? 63 : 31;
    পূর্ণসংখ্যা r;

    যদি (c1 && c2) {
        নির্বাচন(op) {
        ক্ষেত্র '+': l1 += l2; বিরতি;
        ক্ষেত্র '-': l1 -= l2; বিরতি;
        ক্ষেত্র '&': l1 &= l2; বিরতি;
        ক্ষেত্র '^': l1 ^= l2; বিরতি;
        ক্ষেত্র '|': l1 |= l2; বিরতি;
        ক্ষেত্র '*': l1 *= l2; বিরতি;

        ক্ষেত্র TOK_PDIV:
        ক্ষেত্র '/':
        ক্ষেত্র '%':
        ক্ষেত্র TOK_UDIV:
        ক্ষেত্র TOK_UMOD:
            /* if division by zero, generate explicit division */
            যদি (l2 == 0) {
                যদি (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                যাও general_case;
            }
            নির্বাচন(op) {
            পূর্বনির্ধারিত: l1 = gen_opic_sdiv(l1, l2); বিরতি;
            ক্ষেত্র '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); বিরতি;
            ক্ষেত্র TOK_UDIV: l1 = l1 / l2; বিরতি;
            ক্ষেত্র TOK_UMOD: l1 = l1 % l2; বিরতি;
            }
            বিরতি;
        ক্ষেত্র TOK_SHL: l1 <<= (l2 & shm); বিরতি;
        ক্ষেত্র TOK_SHR: l1 >>= (l2 & shm); বিরতি;
        ক্ষেত্র TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            বিরতি;
            /* tests */
        ক্ষেত্র TOK_ULT: l1 = l1 < l2; বিরতি;
        ক্ষেত্র TOK_UGE: l1 = l1 >= l2; বিরতি;
        ক্ষেত্র TOK_EQ: l1 = l1 == l2; বিরতি;
        ক্ষেত্র TOK_NE: l1 = l1 != l2; বিরতি;
        ক্ষেত্র TOK_ULE: l1 = l1 <= l2; বিরতি;
        ক্ষেত্র TOK_UGT: l1 = l1 > l2; বিরতি;
        ক্ষেত্র TOK_LT: l1 = gen_opic_lt(l1, l2); বিরতি;
        ক্ষেত্র TOK_GE: l1 = !gen_opic_lt(l1, l2); বিরতি;
        ক্ষেত্র TOK_LE: l1 = !gen_opic_lt(l2, l1); বিরতি;
        ক্ষেত্র TOK_GT: l1 = gen_opic_lt(l2, l1); বিরতি;
            /* logical */
        ক্ষেত্র TOK_LAND: l1 = l1 && l2; বিরতি;
        ক্ষেত্র TOK_LOR: l1 = l1 || l2; বিরতি;
        পূর্বনির্ধারিত:
            যাও general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } অন্যথা {
        /* if commutative ops, put c2 as constant */
        যদি (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        যদি (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } অন্যথা যদি (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            যদি (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } অন্যথা যদি (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } অন্যথা যদি (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            যদি (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                পূর্ণসংখ্যা n = -1;
                যদি (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    যাও general_case;
                }
                যখন (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                যদি (op == '*')
                    op = TOK_SHL;
                অন্যথা যদি (op == TOK_PDIV)
                    op = TOK_SAR;
                অন্যথা
                    op = TOK_SHR;
            }
            যাও general_case;
        } অন্যথা যদি (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            যদি (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    যদি ((পূর্ণসংখ্যা)l2 != l2)
	        যাও general_case;
            vtop--;
            vtop->c.i = l2;
        } অন্যথা {
        general_case:
                /* call low level op generator */
                যদি (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_আকার == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                অন্যথা
                    gen_opi(op);
        }
        যদি (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#যদি defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#নতুবা_যদি defined TCC_TARGET_ARM
শূন্য gen_negf(পূর্ণসংখ্যা op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#অন্যথা
/* XXX: implement in gen_opf() for other backends too */
শূন্য gen_negf(পূর্ণসংখ্যা op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    পূর্ণসংখ্যা align, আকার_2, bt;
    আকার_2 = type_আকার(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#যদি defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    যদি (bt == VT_LDOUBLE)
        আকার_2 = 10;
#endif
    যদি (nocode_wanted) /* save_reg() wont work */
        যাও gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(আকার_2 - 1);
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
স্থির শূন্য gen_opif(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা c1, c2, i, bt;
    SValue *v1, *v2;
#যদি defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    অস্থির
#endif
    long দ্বিগুণ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    যদি (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    যদি (c1 && c2) {
        যদি (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } অন্যথা যদি (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } অন্যথা {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        যদি (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            যাও general_case;
        নির্বাচন(op) {
        ক্ষেত্র '+': f1 += f2; বিরতি;
        ক্ষেত্র '-': f1 -= f2; বিরতি;
        ক্ষেত্র '*': f1 *= f2; বিরতি;
        ক্ষেত্র '/': 
            যদি (f2 == 0.0) {
                সংঘ { দশমিক f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                যদি (!CONST_WANTED)
                    যাও general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                যদি (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                অন্যথা
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                বিরতি;
            }
            f1 /= f2;
            বিরতি;
        ক্ষেত্র TOK_NEG:
            f1 = -f1;
            যাও unary_ফলাফল;
        ক্ষেত্র TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ফেরত;
        ক্ষেত্র TOK_NE:
            i = f1 != f2;
	    যাও make_int;
        ক্ষেত্র TOK_LT:
            i = f1 < f2;
	    যাও make_int;
        ক্ষেত্র TOK_GE:
            i = f1 >= f2;
	    যাও make_int;
        ক্ষেত্র TOK_LE:
            i = f1 <= f2;
	    যাও make_int;
        ক্ষেত্র TOK_GT:
            i = f1 > f2;
	    যাও make_int;
        পূর্বনির্ধারিত:
            যাও general_case;
        }
        vtop--;
    unary_ফলাফল:
        /* XXX: overflow test ? */
        যদি (bt == VT_FLOAT) {
            v1->c.f = f1;
        } অন্যথা যদি (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } অন্যথা {
            v1->c.ld = f1;
        }
    } অন্যথা {
    general_case:
        যদি (op == TOK_NEG) {
            gen_negf(op);
        } অন্যথা {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
স্থির শূন্য type_to_str(অক্ষর *buf, পূর্ণসংখ্যা buf_আকার,
                 CType *type, ধ্রুবক অক্ষর *varstr)
{
    পূর্ণসংখ্যা bt, v, t;
    Sym *s, *sa;
    অক্ষর buf1[256];
    ধ্রুবক অক্ষর *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    যদি (t & VT_EXTERN)
        pstrcat(buf, buf_আকার, "extern ");
    যদি (t & VT_STATIC)
        pstrcat(buf, buf_আকার, "static ");
    যদি (t & VT_TYPEDEF)
        pstrcat(buf, buf_আকার, "typedef ");
    যদি (t & VT_INLINE)
        pstrcat(buf, buf_আকার, "inline ");
    যদি (bt != VT_PTR) {
        যদি (t & VT_RESTRICT)
            pstrcat(buf, buf_আকার, "restrict ");
        যদি (t & VT_VOLATILE)
            pstrcat(buf, buf_আকার, "volatile ");
        যদি (t & VT_CONSTANT)
            pstrcat(buf, buf_আকার, "const ");
    }
    যদি (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_আকার, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_আকার -= strlen(buf);
    buf += strlen(buf);

    নির্বাচন(bt) {
    ক্ষেত্র VT_VOID:
        tstr = "void";
        যাও add_tstr;
    ক্ষেত্র VT_BOOL:
        tstr = "_Bool";
        যাও add_tstr;
    ক্ষেত্র VT_BYTE:
        tstr = "char";
        যাও add_tstr;
    ক্ষেত্র VT_SHORT:
        tstr = "short";
        যাও add_tstr;
    ক্ষেত্র VT_INT:
        tstr = "int";
        যাও maybe_long;
    ক্ষেত্র VT_LLONG:
        tstr = "long long";
    maybe_long:
        যদি (t & VT_LONG)
            tstr = "long";
        যদি (!IS_ENUM(t))
            যাও add_tstr;
        tstr = "enum ";
        যাও tstruct;
    ক্ষেত্র VT_FLOAT:
        tstr = "float";
        যাও add_tstr;
    ক্ষেত্র VT_DOUBLE:
        tstr = "double";
        যদি (!(t & VT_LONG))
            যাও add_tstr;
    ক্ষেত্র VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_আকার, tstr);
        বিরতি;
    ক্ষেত্র VT_STRUCT:
        tstr = "struct ";
        যদি (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_আকার, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        যদি (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_আকার, "<anonymous>");
        অন্যথা
            pstrcat(buf, buf_আকার, get_tok_str(v, ফাঁকা));
        বিরতি;
    ক্ষেত্র VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        যদি (varstr && '*' == *varstr) {
            pstrcat(buf1, আকার(buf1), "(");
            pstrcat(buf1, আকার(buf1), varstr);
            pstrcat(buf1, আকার(buf1), ")");
        }
        pstrcat(buf1, আকার(buf1), "(");
        sa = s->পরবর্তী;
        যখন (sa != ফাঁকা) {
            অক্ষর buf2[256];
            type_to_str(buf2, আকার(buf2), &sa->type, ফাঁকা);
            pstrcat(buf1, আকার(buf1), buf2);
            sa = sa->পরবর্তী;
            যদি (sa)
                pstrcat(buf1, আকার(buf1), ", ");
        }
        যদি (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, আকার(buf1), ", ...");
        pstrcat(buf1, আকার(buf1), ")");
        type_to_str(buf, buf_আকার, &s->type, buf1);
        যাও no_var;
    ক্ষেত্র VT_PTR:
        s = type->ref;
        যদি (t & (VT_ARRAY|VT_VLA)) {
            যদি (varstr && '*' == *varstr)
                snprintf(buf1, আকার(buf1), "(%s)[%d]", varstr, s->c);
            অন্যথা
                snprintf(buf1, আকার(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_আকার, &s->type, buf1);
            যাও no_var;
        }
        pstrcpy(buf1, আকার(buf1), "*");
        যদি (t & VT_RESTRICT)
            pstrcat(buf1, আকার(buf1), "restrict ");
        যদি (t & VT_CONSTANT)
            pstrcat(buf1, আকার(buf1), "const ");
        যদি (t & VT_VOLATILE)
            pstrcat(buf1, আকার(buf1), "volatile ");
        যদি (varstr)
            pstrcat(buf1, আকার(buf1), varstr);
        type_to_str(buf, buf_আকার, &s->type, buf1);
        যাও no_var;
    }
    যদি (varstr) {
        pstrcat(buf, buf_আকার, " ");
        pstrcat(buf, buf_আকার, varstr);
    }
 no_var: ;
}

স্থির শূন্য type_incompatibility_error(CType* st, CType* dt, ধ্রুবক অক্ষর* fmt)
{
    অক্ষর buf1[256], buf2[256];
    type_to_str(buf1, আকার(buf1), st, ফাঁকা);
    type_to_str(buf2, আকার(buf2), dt, ফাঁকা);
    tcc_error(fmt, buf1, buf2);
}

স্থির শূন্য type_incompatibility_warning(CType* st, CType* dt, ধ্রুবক অক্ষর* fmt)
{
    অক্ষর buf1[256], buf2[256];
    type_to_str(buf1, আকার(buf1), st, ফাঁকা);
    type_to_str(buf2, আকার(buf2), dt, ফাঁকা);
    tcc_warning(fmt, buf1, buf2);
}

স্থির পূর্ণসংখ্যা pointed_আকার(CType *type)
{
    পূর্ণসংখ্যা align;
    ফেরত type_আকার(pointed_type(type), &align);
}

স্থির অন্তঃরেখ পূর্ণসংখ্যা is_null_pointer(SValue *p)
{
    যদি ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ফেরত 0;
    ফেরত ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_আকার == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
স্থির পূর্ণসংখ্যা is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    যদি (s1->f.func_call != s2->f.func_call)
        ফেরত 0;
    যদি (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ফেরত 0;
    জন্য (;;) {
        যদি (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ফেরত 0;
        যদি (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ফেরত 1;
        s1 = s1->পরবর্তী;
        s2 = s2->পরবর্তী;
        যদি (!s1)
            ফেরত !s2;
        যদি (!s2)
            ফেরত 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
স্থির পূর্ণসংখ্যা compare_types(CType *type1, CType *type2, পূর্ণসংখ্যা unqualified)
{
    পূর্ণসংখ্যা bt1, t1, t2;

    যদি (IS_ENUM(type1->t)) {
        যদি (IS_ENUM(type2->t))
            ফেরত type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } অন্যথা যদি (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    যদি (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    যদি ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    যদি (t1 != t2)
        ফেরত 0;

    যদি ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ফেরত 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    যদি (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        যদি (unqualified && (t1 & VT_ARRAY))
            ফেরত compare_types(type1, type2, 1);
        ফেরত is_compatible_types(type1, type2);
    } অন্যথা যদি (bt1 == VT_STRUCT) {
        ফেরত (type1->ref == type2->ref);
    } অন্যথা যদি (bt1 == VT_FUNC) {
        ফেরত is_compatible_func(type1, type2);
    } অন্যথা {
        ফেরত 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
স্থির পূর্ণসংখ্যা combine_types(CType *dest, SValue *op1, SValue *op2, পূর্ণসংখ্যা op)
{
    CType *type1, *type2, type;
    পূর্ণসংখ্যা t1, t2, bt1, bt2;
    পূর্ণসংখ্যা ret = 1;

    /* for shifts, 'combine' only left operand */
    যদি (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ফাঁকা;

    যদি (bt1 == VT_VOID || bt2 == VT_VOID) {
        যদি (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } অন্যথা যদি (bt1 == VT_PTR || bt2 == VT_PTR) {
        যদি (op == '+') {
          যদি (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        অন্যথা যদি (is_null_pointer (op2)) type = *type1;
        অন্যথা যদি (is_null_pointer (op1)) type = *type2;
        অন্যথা যদি (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            যদি ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            অন্যথা যদি (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } অন্যথা {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            পূর্ণসংখ্যা pbt1 = pt1->t & VT_BTYPE;
            পূর্ণসংখ্যা pbt2 = pt2->t & VT_BTYPE;
            পূর্ণসংখ্যা newquals, copied = 0;
            যদি (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                যদি (op != '?' && op != CMP_OP)
                  ret = 0;
                অন্যথা
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            যদি (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                যদি ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ঠেলো(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                যদি (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    যদি (!copied)
                      type.ref = sym_ঠেলো(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ঠেলো(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        যদি (op == CMP_OP)
          type.t = VT_আকার_T;
    } অন্যথা যদি (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        যদি (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } অন্যথা যদি (is_float(bt1) || is_float(bt2)) {
        যদি (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } অন্যথা যদি (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } অন্যথা {
            type.t = VT_FLOAT;
        }
    } অন্যথা যদি (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        যদি (bt1 == VT_LLONG)
          type.t &= t1;
        যদি (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        যদি ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } অন্যথা {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        যদি (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_আকার(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_আকার(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    যদি (dest)
      *dest = type;
    ফেরত ret;
}

/* generic gen_op: handles types problems */
ST_FUNC শূন্য gen_op(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা t1, t2, bt1, bt2, t;
    CType type1, combtype;
    পূর্ণসংখ্যা op_class = op;

    যদি (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    অন্যথা যদি (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    যদি (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	যদি (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	যদি (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	যাও redo;
    } অন্যথা যদি (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } অন্যথা যদি (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        পূর্ণসংখ্যা align;
        যদি (op_class == CMP_OP)
            যাও std_op;
        /* if both pointers, then it must be the '-' op */
        যদি (bt1 == VT_PTR && bt2 == VT_PTR) {
            যদি (op != '-')
                যাও op_err;
            vpush_type_আকার(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } অন্যথা {
            /* exactly one pointer : must be '+' or '-'. */
            যদি (op != '-' && op != '+')
                যাও op_err;
            /* Put pointer as first operand */
            যদি (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#যদি PTR_আকার == 4
            যদি (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_আকার(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            যদি (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                যদি (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } অন্যথা
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } অন্যথা {
        /* floats can only be used for a few operations */
        যদি (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            যাও op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        যদি (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        যদি (t & VT_UNSIGNED) {
            যদি (op == TOK_SAR)
                op = TOK_SHR;
            অন্যথা যদি (op == '/')
                op = TOK_UDIV;
            অন্যথা যদি (op == '%')
                op = TOK_UMOD;
            অন্যথা যদি (op == TOK_LT)
                op = TOK_ULT;
            অন্যথা যদি (op == TOK_GT)
                op = TOK_UGT;
            অন্যথা যদি (op == TOK_LE)
                op = TOK_ULE;
            অন্যথা যদি (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        যদি (is_float(t))
            gen_opif(op);
        অন্যথা
            gen_opic(op);
        যদি (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } অন্যথা {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    যদি (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#যদি defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#অন্যথা
/* generic itof for unsigned long long case */
স্থির শূন্য gen_cvt_itof1(পূর্ণসংখ্যা t)
{
    যদি ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        যদি (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#যদি LDOUBLE_আকার != 8
        অন্যথা যদি (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        অন্যথা
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } অন্যথা {
        gen_cvt_itof(t);
    }
}
#endif

#যদি defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#অন্যথা
/* generic ftoi for unsigned long long case */
স্থির শূন্য gen_cvt_ftoi1(পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা st;
    যদি (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        যদি (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#যদি LDOUBLE_আকার != 8
        অন্যথা যদি (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        অন্যথা
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } অন্যথা {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
স্থির শূন্য force_charshort_cast(শূন্য)
{
    পূর্ণসংখ্যা sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    পূর্ণসংখ্যা dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

স্থির শূন্য gen_cast_s(পূর্ণসংখ্যা t)
{
    CType type;
    type.t = t;
    type.ref = ফাঁকা;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
স্থির শূন্য gen_cast(CType *type)
{
    পূর্ণসংখ্যা sbt, dbt, sf, df, c;
    পূর্ণসংখ্যা dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    যদি (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    যদি (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    যদি (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    যদি (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    যদি (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        যদি (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            যাও done;
        }
        যদি (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        যদি (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            যদি (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            অন্যথা যদি (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            যদি (df) {
                যদি (sbt_bt == VT_LLONG) {
                    যদি ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    অন্যথা
                        vtop->c.ld = -(long দ্বিগুণ)-vtop->c.i;
                } অন্যথা যদি(!sf) {
                    যদি ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    অন্যথা
                        vtop->c.ld = -(long দ্বিগুণ)-(uint32_t)vtop->c.i;
                }

                যদি (dbt == VT_FLOAT)
                    vtop->c.f = (দশমিক)vtop->c.ld;
                অন্যথা যদি (dbt == VT_DOUBLE)
                    vtop->c.d = (দ্বিগুণ)vtop->c.ld;
            } অন্যথা যদি (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } অন্যথা {
                যদি(sf) {
                    যদি (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    অন্যথা
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                অন্যথা যদি (sbt_bt == VT_LLONG || (PTR_আকার == 8 && sbt == VT_PTR))
                    ;
                অন্যথা যদি (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                অন্যথা
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                যদি (dbt_bt == VT_LLONG || (PTR_আকার == 8 && dbt == VT_PTR))
                    ;
                অন্যথা যদি (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                অন্যথা {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    যদি (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            যাও done;

        } অন্যথা যদি (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            যাও done;
        }

        /* cannot generate code for global or static initializers */
        যদি (nocode_wanted & তথ্য_ONLY_WANTED) {
            যদি (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            যাও done;
        }

        /* non constant case: generate code */
        যদি (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            যাও done;
        }

        যদি (sf || df) {
            যদি (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } অন্যথা যদি (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } অন্যথা {
                /* convert fp to int */
                sbt = dbt;
                যদি (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                যাও again; /* may need char/short cast */
            }
            যাও done;
        }

        ds = btype_আকার(dbt_bt);
        ss = btype_আকার(sbt_bt);
        যদি (ds == 0 || ss == 0)
            যাও error;

        /* same size and no sign conversion needed */
        যদি (ds == ss && ds >= 4)
            যাও done;
        যদি (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            যদি (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_আকার == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        যদি (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            যদি (ds <= ss)
                যাও done;
            /* ss <= 4 here */
            যদি (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                যাও done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#যদি PTR_আকার == 4
        যদি (ds == 8) {
            /* generate high word */
            যদি (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } অন্যথা {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } অন্যথা যদি (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#নতুবা_যদি PTR_আকার == 8
        যদি (ds == 8) {
            /* need to convert from 32bit to 64bit */
            যদি (sbt & VT_UNSIGNED) {
#যদি defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#অন্যথা
                যাও done;
#endif
            } অন্যথা {
                gen_cvt_sxtw();
                যাও done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } অন্যথা যদি (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#যদি !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } অন্যথা {
            ss = 4;
        }
#endif

        যদি (ds >= ss)
            যাও done;
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    যদি (ss == 4) {
        gen_cvt_csti(dbt);
        যাও done;
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
ST_FUNC পূর্ণসংখ্যা type_আকার(CType *type, পূর্ণসংখ্যা *a)
{
    Sym *s;
    পূর্ণসংখ্যা bt;

    bt = type->t & VT_BTYPE;
    যদি (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ফেরত s->c;
    } অন্যথা যদি (bt == VT_PTR) {
        যদি (type->t & VT_ARRAY) {
            পূর্ণসংখ্যা ts;
            s = type->ref;
            ts = type_আকার(&s->type, a);
            যদি (s->c < 0)
                ফেরত s->c;
            ফেরত ts * s->c;
        } অন্যথা {
            *a = PTR_আকার;
            ফেরত PTR_আকার;
        }
    } অন্যথা যদি (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ফেরত -1; /* incomplete enum */
    } অন্যথা যদি (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ফেরত LDOUBLE_আকার;
    } অন্যথা যদি (bt == VT_DOUBLE || bt == VT_LLONG) {
#যদি (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#অন্যথা
        *a = 8;
#endif
        ফেরত 8;
    } অন্যথা যদি (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ফেরত 4;
    } অন্যথা যদি (bt == VT_SHORT) {
        *a = 2;
        ফেরত 2;
    } অন্যথা যদি (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ফেরত 16;
    } অন্যথা {
        /* char, void, function, _Bool */
        *a = 1;
        ফেরত 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
স্থির শূন্য vpush_type_আকার(CType *type, পূর্ণসংখ্যা *a)
{
    যদি (type->t & VT_VLA) {
        type_আকার(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } অন্যথা {
        পূর্ণসংখ্যা আকার_2 = type_আকার(type, a);
        যদি (আকার_2 < 0)
            tcc_error("unknown type size");
        vpushs(আকার_2);
    }
}

/* return the pointed type of t */
স্থির অন্তঃরেখ CType *pointed_type(CType *type)
{
    ফেরত &type->ref->type;
}

স্থির শূন্য check_restrict_type(CType *type)
{
    যখন ((type->t & VT_BTYPE) == VT_PTR) {
        যদি ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    যদি (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
স্থির পূর্ণসংখ্যা type_qualifiers(CType *type)
{
    যখন (type->t & VT_ARRAY)
        type = pointed_type(type);
    ফেরত type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC শূন্য mk_pointer(CType *type)
{
    Sym *s;
    s = sym_ঠেলো(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
স্থির পূর্ণসংখ্যা is_compatible_types(CType *type1, CType *type2)
{
    ফেরত compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
স্থির পূর্ণসংখ্যা is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ফেরত compare_types(type1,type2,1);
}

স্থির শূন্য cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
স্থির শূন্য verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    পূর্ণসংখ্যা dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    যদি (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    নির্বাচন(dbt) {
    ক্ষেত্র VT_VOID:
        যদি (sbt != dbt)
            tcc_error("assignment to void expression");
        বিরতি;
    ক্ষেত্র VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        যদি (is_null_pointer(vtop))
            বিরতি;
        /* accept implicit pointer to integer cast with warning */
        যদি (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            বিরতি;
        }
        type1 = pointed_type(dt);
        যদি (sbt == VT_PTR)
            type2 = pointed_type(st);
        অন্যথা যদি (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        অন্যথা
            যাও error;
        যদি (is_compatible_types(type1, type2))
            বিরতি;
        জন্য (qualwarn = lvl = 0;; ++lvl) {
            যদি ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            যদি (dbt != VT_PTR || sbt != VT_PTR)
                বিরতি;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        যদি (!is_compatible_unqualified_types(type1, type2)) {
            যদি ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } অন্যথা যদি (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } অন্যথা {
                tcc_warning("assignment from incompatible pointer type");
                বিরতি;
            }
        }
        যদি (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        বিরতি;
    ক্ষেত্র VT_BYTE:
    ক্ষেত্র VT_SHORT:
    ক্ষেত্র VT_INT:
    ক্ষেত্র VT_LLONG:
        যদি (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } অন্যথা যদি (sbt == VT_STRUCT) {
            যাও case_VT_STRUCT;
        }
        /* XXX: more tests */
        বিরতি;
    ক্ষেত্র VT_STRUCT:
    case_VT_STRUCT:
        যদি (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        বিরতি;
    }
}

স্থির শূন্য gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC শূন্য vstore(শূন্য)
{
    পূর্ণসংখ্যা sbt, dbt, ft, r, আকার_2, align, bit_আকার, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    যদি (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        আকার_2 = type_আকার(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        যদি (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        যদি (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        যদি (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(আকার_2);
        } অন্যথা
#endif
        {
            /* type size */
            vpushi(আকার_2);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            যদি(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            অন্যথা যদি(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            অন্যথা
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } অন্যথা যদি (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_আকার = BIT_আকার(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        যদি (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_আকার);
        যদি (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        যদি (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_আকার);
        } অন্যথা {
            unsigned long long mask = (1ULL << bit_আকার) - 1;
            যদি (dbt != VT_BOOL) {
                /* mask source */
                যদি (dbt == VT_LLONG)
                    vpushll(mask);
                অন্যথা
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
            যদি (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            অন্যথা
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } অন্যথা যদি (dbt == VT_VOID) {
        --vtop;
    } অন্যথা {
            /* optimize char/short casts */
            delayed_cast = 0;
            যদি ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                যদি ((vtop->r & VT_MUSTCAST)
                    && btype_আকার(dbt) > btype_আকার(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } অন্যথা {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            যদি (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            যদি (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            যদি ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ফাঁকা;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            যদি (USING_TWO_শব্দগুলি(dbt)) {
                পূর্ণসংখ্যা load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_আকার);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } অন্যথা {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC শূন্য inc(পূর্ণসংখ্যা post, পূর্ণসংখ্যা c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    যদি (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    যদি (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ধ্রুবক অক্ষর *বার্তা)
{
    /* read the string */
    যদি (tok != TOK_STR)
        expect(বার্তা);
    cstr_reset(&initstr);
    যখন (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.তথ্য, -1);
        পরবর্তী();
    }
    cstr_ccat(&initstr, '\0');
    ফেরত &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC পূর্ণসংখ্যা exact_log2p1(পূর্ণসংখ্যা i)
{
  পূর্ণসংখ্যা ret;
  যদি (!i)
    ফেরত 0;
  জন্য (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  যদি (i >= 1 << 4)
    ret += 4, i >>= 4;
  যদি (i >= 1 << 2)
    ret += 2, i >>= 2;
  যদি (i >= 1 << 1)
    ret++;
  ফেরত ret;
}

/* Parse __attribute__((...)) GNUC extension. */
স্থির শূন্য parse_attribute(AttributeDef *ad)
{
    পূর্ণসংখ্যা t, n;
    অক্ষর *astr;
    AttributeDef ad_tmp;
    
redo:
    যদি (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ফেরত;
    যদি (ফাঁকা == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    পরবর্তী();
    skip('(');
    skip('(');
    যখন (tok != ')') {
        যদি (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        পরবর্তী();
        নির্বাচন(t) {
	ক্ষেত্র TOK_CLEANUP1:
	ক্ষেত্র TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    যদি (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } অন্যথা যদি ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    পরবর্তী();
            skip(')');
	    বিরতি;
	}
        ক্ষেত্র TOK_CONSTRUCTOR1:
        ক্ষেত্র TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            বিরতি;
        ক্ষেত্র TOK_DESTRUCTOR1:
        ক্ষেত্র TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            বিরতি;
        ক্ষেত্র TOK_ALWAYS_INLINE1:
        ক্ষেত্র TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            বিরতি;
        ক্ষেত্র TOK_SECTION1:
        ক্ষেত্র TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->তথ্য;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            বিরতি;
        ক্ষেত্র TOK_ALIAS1:
        ক্ষেত্র TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->তথ্য;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            বিরতি;
	ক্ষেত্র TOK_VISIBILITY1:
	ক্ষেত্র TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->তথ্য;
	    যদি (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    অন্যথা যদি (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    অন্যথা যদি (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    অন্যথা যদি (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    অন্যথা
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            বিরতি;
        ক্ষেত্র TOK_ALIGNED1:
        ক্ষেত্র TOK_ALIGNED2:
            যদি (tok == '(') {
                পরবর্তী();
                n = রাশিমালা_const();
                যদি (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } অন্যথা {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    যদি (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            বিরতি;
        ক্ষেত্র TOK_PACKED1:
        ক্ষেত্র TOK_PACKED2:
            ad->a.packed = 1;
            বিরতি;
        ক্ষেত্র TOK_WEAK1:
        ক্ষেত্র TOK_WEAK2:
            ad->a.weak = 1;
            বিরতি;
        ক্ষেত্র TOK_NODEBUG1:
        ক্ষেত্র TOK_NODEBUG2:
            ad->a.nodebug = 1;
            বিরতি;
        ক্ষেত্র TOK_USED1:
        ক্ষেত্র TOK_USED2:
        ক্ষেত্র TOK_UNUSED1:
        ক্ষেত্র TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            বিরতি;
        ক্ষেত্র TOK_CONST1:
        ক্ষেত্র TOK_CONST2:
        ক্ষেত্র TOK_CONST3:
        ক্ষেত্র TOK_PURE1:
        ক্ষেত্র TOK_PURE2:
	    /* ignored */
            বিরতি;
        ক্ষেত্র TOK_NOINLINE:
	    /* ignored */
	    বিরতি;
        ক্ষেত্র TOK_FORMAT1:
        ক্ষেত্র TOK_FORMAT2:
	    /* ignored */
            যাও skip_param;
        ক্ষেত্র TOK_NORETURN1:
        ক্ষেত্র TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            বিরতি;
        ক্ষেত্র TOK_CDECL1:
        ক্ষেত্র TOK_CDECL2:
        ক্ষেত্র TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            বিরতি;
        ক্ষেত্র TOK_STDCALL1:
        ক্ষেত্র TOK_STDCALL2:
        ক্ষেত্র TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            বিরতি;
#ifdef TCC_TARGET_I386
        ক্ষেত্র TOK_REGPARM1:
        ক্ষেত্র TOK_REGPARM2:
            skip('(');
            n = রাশিমালা_const();
            যদি (n > 3) 
                n = 3;
            অন্যথা যদি (n < 0)
                n = 0;
            যদি (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            বিরতি;
        ক্ষেত্র TOK_FASTCALL1:
        ক্ষেত্র TOK_FASTCALL2:
        ক্ষেত্র TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            বিরতি;
        ক্ষেত্র TOK_THISCALL1:
        ক্ষেত্র TOK_THISCALL2:
        ক্ষেত্র TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            বিরতি;
#endif
        ক্ষেত্র TOK_MODE:
            skip('(');
            নির্বাচন(tok) {
                ক্ষেত্র TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    বিরতি;
                ক্ষেত্র TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    বিরতি;
                ক্ষেত্র TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    বিরতি;
                ক্ষেত্র TOK_MODE_SI:
                ক্ষেত্র TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    বিরতি;
                পূর্বনির্ধারিত:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ফাঁকা));
                    বিরতি;
            }
            পরবর্তী();
            skip(')');
            বিরতি;
        ক্ষেত্র TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            বিরতি;
        ক্ষেত্র TOK_NODECORATE:
            ad->a.nodecorate = 1;
            বিরতি;
        ক্ষেত্র TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            বিরতি;
        পূর্বনির্ধারিত:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ফাঁকা));
            /* skip parameters */
skip_param:
            যদি (tok == '(') {
                পূর্ণসংখ্যা parenthesis = 0;
                করো {
                    যদি (tok == '(') 
                        parenthesis++;
                    অন্যথা যদি (tok == ')') 
                        parenthesis--;
                    পরবর্তী();
                } যখন (parenthesis && tok != -1);
            }
            বিরতি;
        }
        যদি (tok != ',')
            বিরতি;
        পরবর্তী();
    }
    skip(')');
    skip(')');
    যাও redo;
}

স্থির Sym * find_field (CType *type, পূর্ণসংখ্যা v, পূর্ণসংখ্যা *cumofs)
{
    Sym *s = type->ref;
    পূর্ণসংখ্যা v1 = v | SYM_FIELD;
    যদি (!(v & SYM_FIELD)) { /* top-level call */
        যদি ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        যদি (v < TOK_UIDENT)
            expect("field name");
        যদি (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    যখন ((s = s->পরবর্তী) != ফাঁকা) {
        যদি (s->v == v1) {
            *cumofs = s->c;
            ফেরত s;
        }
        যদি ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            যদি (ret) {
                *cumofs += s->c;
                ফেরত ret;
            }
        }
    }
    যদি (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, ফাঁকা));
    ফেরত s;
}

স্থির শূন্য check_fields (CType *type, পূর্ণসংখ্যা check)
{
    Sym *s = type->ref;

    যখন ((s = s->পরবর্তী) != ফাঁকা) {
        পূর্ণসংখ্যা v = s->v & ~SYM_FIELD;
        যদি (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            যদি (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, ফাঁকা));
            ts->tok ^= SYM_FIELD;
        } অন্যথা যদি ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

স্থির শূন্য struct_layout(CType *type, AttributeDef *ad)
{
    পূর্ণসংখ্যা আকার_2, align, maxalign, offset, c, bit_pos, bit_আকার;
    পূর্ণসংখ্যা packed, a, bt, prevbt, পূর্ব_bit_আকার;
    পূর্ণসংখ্যা pcc = !tcc_state->ms_bitfields;
    পূর্ণসংখ্যা pragma_pack = *tcc_state->pack_স্তূপ_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    পূর্ব_bit_আকার = 0;

//#define BF_DEBUG

    জন্য (f = type->ref->পরবর্তী; f; f = f->পরবর্তী) {
        যদি (f->type.t & VT_BITFIELD)
            bit_আকার = BIT_আকার(f->type.t);
        অন্যথা
            bit_আকার = -1;
        আকার_2 = type_আকার(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        যদি (pcc && bit_আকার == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } অন্যথা {
            /* in pcc mode, attribute packed overrides if set. */
            যদি (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            যদি (pragma_pack) {
                packed = 1;
                যদি (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                যদি (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        যদি (a)
            align = a;

        যদি (type->ref->type.t == VT_UNION) {
	    যদি (pcc && bit_আকার >= 0)
	        আকার_2 = (bit_আকার + 7) >> 3;
	    offset = 0;
	    যদি (আকার_2 > c)
	        c = আকার_2;

	} অন্যথা যদি (bit_আকার < 0) {
            যদি (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    যদি (আকার_2 > 0)
	        c += আকার_2;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    পূর্ব_bit_আকার = 0;

	} অন্যথা {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            যদি (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                যদি (bit_আকার == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } অন্যথা যদি (f->a.aligned) {
                    যাও new_field;
                } অন্যথা যদি (!packed) {
                    পূর্ণসংখ্যা a8 = align * 8;
	            পূর্ণসংখ্যা ofs = ((c * 8 + bit_pos) % a8 + bit_আকার + a8 - 1) / a8;
                    যদি (ofs > আকার_2 / align)
                        যাও new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                যদি (আকার_2 == 8 && bit_আকার <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, আকার_2 = 4;

                যখন (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		যদি (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } অন্যথা {
		bt = f->type.t & VT_BTYPE;
		যদি ((bit_pos + bit_আকার > আকার_2 * 8)
                    || (bit_আকার > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    যদি (bit_আকার || পূর্ব_bit_আকার)
		        c += আকার_2;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		যদি (bit_আকার == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                পূর্ব_bit_আকার = bit_আকার;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_আকার;
	}
	যদি (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, ফাঁকা), offset, আকার_2, align);
	যদি (f->type.t & VT_BITFIELD) {
	    printf(" pos %-2d bits %-2d",
                    BIT_POS(f->type.t),
                    BIT_আকার(f->type.t)
                    );
	}
	printf("\n");
#endif

        f->c = offset;
	f->r = 0;
    }

    যদি (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    যদি (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    যদি (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        যদি (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    জন্য (f = type->ref->পরবর্তী; f; f = f->পরবর্তী) {
        পূর্ণসংখ্যা s, px, cx, c0;
        CType t;

        যদি (0 == (f->type.t & VT_BITFIELD))
            চালু;
        f->type.ref = f;
        f->auxtype = -1;
        bit_আকার = BIT_আকার(f->type.t);
        যদি (bit_আকার == 0)
            চালু;
        bit_pos = BIT_POS(f->type.t);
        আকার_2 = type_আকার(&f->type, &align);

        যদি (bit_pos + bit_আকার <= আকার_2 * 8 && f->c + আকার_2 <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            চালু;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        জন্য (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            যদি (c0 == cx)
                বিরতি;
            s = (px + bit_আকার + 7) >> 3;
            যদি (s > 4) {
                t.t = VT_LLONG;
            } অন্যথা যদি (s > 2) {
                t.t = VT_INT;
            } অন্যথা যদি (s > 1) {
                t.t = VT_SHORT;
            } অন্যথা {
                t.t = VT_BYTE;
            }
            s = type_আকার(&t, &align);
            c0 = cx;
        }

        যদি (px + bit_আকার <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            যদি (s != আকার_2)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, ফাঁকা),
                cx, s, align, px, bit_আকার);
#endif
        } অন্যথা {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, ফাঁকা));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
স্থির পূর্ণসংখ্যা in_range(long long n, পূর্ণসংখ্যা t)
{
    unsigned long long m = (1ULL << (btype_আকার(t & VT_BTYPE) * 8 - 1)) - 1;
    যদি (t & VT_UNSIGNED)
        ফেরত n <= (m << 1) + 1;
    ফেরত n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
স্থির শূন্য struct_decl(CType *type, পূর্ণসংখ্যা u)
{
    পূর্ণসংখ্যা v, c, আকার_2, align, flexible;
    পূর্ণসংখ্যা bit_আকার, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, আকার ad);
    পরবর্তী();
    parse_attribute(&ad);

    v = 0;
    যদি (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, পরবর্তী();

    bt = ut = 0;
    যদি (u == VT_ENUM) {
        ut = VT_INT;
        যদি (tok == ':') { /* C2x enum : <type> ... */
            পরবর্তী();
            যদি (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    যদি (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        যদি (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            যদি (u == s->type.t)
                যাও do_decl;
            যদি (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                যাও do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ফাঁকা));
        }
    } অন্যথা {
        যদি (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ফাঁকা;
    /* we put an undefined size for struct/union */
    s = sym_ঠেলো(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    যদি (tok == '{') {
        পরবর্তী();
        যদি (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->পরবর্তী;
        যদি (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            যদি (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            জন্য(;;) {
                v = tok;
                যদি (v < TOK_UIDENT)
                    expect("identifier");
                পরবর্তী();
                যদি (tok == '=') {
                    পরবর্তী();
		    ll = রাশিমালা_const64();
                }
                যদি (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ফাঁকা));
                ss = sym_ঠেলো(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->পরবর্তী;
                যদি (ll < nl)
                    nl = ll;
                যদি (ll > pl)
                    pl = ll;
                যদি (tok != ',')
                    বিরতি;
                পরবর্তী();
                ll++;
                /* NOTE: we accept a trailing comma */
                যদি (tok == '}')
                    বিরতি;
            }
            skip('}');

            যদি (bt) {
                t.t = bt;
                s->c = 2;
                যাও enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            যদি (nl >= 0) {
                যদি (pl != (unsigned)pl)
                    t.t = (LONG_আকার==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } অন্যথা যদি (pl != (পূর্ণসংখ্যা)pl || nl != (পূর্ণসংখ্যা)nl)
                t.t = (LONG_আকার==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            জন্য (ss = s->পরবর্তী; ss; ss = ss->পরবর্তী) {
                ll = ss->enum_val;
                যদি (ll == (পূর্ণসংখ্যা)ll) /* default is int if it fits */
                    চালু;
                যদি (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    যদি (ll == (unsigned)ll)
                        চালু;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_আকার==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } অন্যথা {
            c = 0;
            flexible = 0;
            যখন (tok != '}') {
                যদি (!parse_btype(&btype, &ad1, 0)) {
                    যদি (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        চালু;
                    }
		    skip(';');
		    চালু;
		}
                যখন (1) {
		    যদি (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ফাঁকা));
                    bit_আকার = -1;
                    v = 0;
                    type1 = btype;
                    যদি (tok != ':') {
			যদি (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        যদি (v == 0) {
                    	    যদি ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    অন্যথা {
				পূর্ণসংখ্যা v = btype.ref->v;
				যদি ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    যদি (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        যদি (type_আকার(&type1, &align) < 0) {
			    যদি ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    অন্যথা
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ফাঁকা));
                        }
                        যদি ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ফাঁকা));
                    }
                    যদি (tok == ':') {
                        পরবর্তী();
                        bit_আকার = রাশিমালা_const();
                        /* XXX: handle v = 0 case for messages */
                        যদি (bit_আকার < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ফাঁকা));
                        যদি (v && bit_আকার == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ফাঁকা));
			parse_attribute(&ad1);
                    }
                    আকার_2 = type_আকার(&type1, &align);
                    যদি (bit_আকার >= 0) {
                        bt = type1.t & VT_BTYPE;
                        যদি (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = আকার_2 * 8;
                        যদি (bit_আকার > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ফাঁকা));
                        } অন্যথা যদি (bit_আকার == bsize
				    && !*tcc_state->pack_স্তূপ_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } অন্যথা যদি (bit_আকার == 64) {
                            tcc_error("field width 64 not implemented");
                        } অন্যথা {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_আকার << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    যদি (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    যদি (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_আকার >= 0)) {
		        v = anon_sym++;
		    }
                    যদি (v) {
                        ss = sym_ঠেলো(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->পরবর্তী;
                    }
                    যদি (tok == ';' || tok == TOK_EOF)
                        বিরতি;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            যদি (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        যদি (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

স্থির শূন্য sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
স্থির শূন্য parse_btype_qualify(CType *type, পূর্ণসংখ্যা qualifiers)
{
    যখন (type->t & VT_ARRAY) {
        type->ref = sym_ঠেলো(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    যদি (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
স্থির পূর্ণসংখ্যা parse_btype(CType *type, AttributeDef *ad, পূর্ণসংখ্যা ignore_label)
{
    পূর্ণসংখ্যা t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, আকার(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ফাঁকা;

    যখন(1) {
        নির্বাচন(tok) {
        ক্ষেত্র TOK_EXTENSION:
            /* currently, we really ignore extension */
            পরবর্তী();
            চালু;

            /* basic types */
        ক্ষেত্র TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            পরবর্তী();
        basic_type1:
            যদি (u == VT_SHORT || u == VT_LONG) {
                যদি (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } অন্যথা {
                যদি (bt != -1 || (st != -1 && u != VT_INT))
                    যাও tmbt;
                যদি ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    যাও tmbt;
                bt = u;
            }
            যদি (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            বিরতি;
        ক্ষেত্র TOK_VOID:
            u = VT_VOID;
            যাও basic_type;
        ক্ষেত্র TOK_SHORT:
            u = VT_SHORT;
            যাও basic_type;
        ক্ষেত্র TOK_INT:
            u = VT_INT;
            যাও basic_type;
        ক্ষেত্র TOK_ALIGNAS:
            { পূর্ণসংখ্যা n;
              AttributeDef ad1;
              পরবর্তী();
              skip('(');
              memset(&ad1, 0, আকার(AttributeDef));
              যদি (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  যদি (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  অন্যথা
                    type_আকার(&type1, &n);
              } অন্যথা {
                  n = রাশিমালা_const();
                  যদি (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            চালু;
        ক্ষেত্র TOK_LONG:
            যদি ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } অন্যথা যদি ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } অন্যথা {
                u = VT_LONG;
                যাও basic_type;
            }
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_BOOL:
            u = VT_BOOL;
            যাও basic_type;
        ক্ষেত্র TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        ক্ষেত্র TOK_FLOAT:
            u = VT_FLOAT;
            যাও basic_type;
        ক্ষেত্র TOK_DOUBLE:
            যদি ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } অন্যথা {
                u = VT_DOUBLE;
                যাও basic_type;
            }
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            যাও basic_type1;
        ক্ষেত্র TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            যাও basic_type2;
        ক্ষেত্র TOK_UNION:
            struct_decl(&type1, VT_UNION);
            যাও basic_type2;

            /* type modifiers */
        ক্ষেত্র TOK__Atomic:
            পরবর্তী();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            যদি (tok == '(') {
                parse_রাশিমালা_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                যদি (type1.ref)
                    sym_to_attr(ad, type1.ref);
                যাও basic_type2;
            }
            বিরতি;
        ক্ষেত্র TOK_CONST1:
        ক্ষেত্র TOK_CONST2:
        ক্ষেত্র TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_VOLATILE1:
        ক্ষেত্র TOK_VOLATILE2:
        ক্ষেত্র TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_SIGNED1:
        ক্ষেত্র TOK_SIGNED2:
        ক্ষেত্র TOK_SIGNED3:
            যদি ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            পরবর্তী();
            typespec_found = 1;
            বিরতি;
        ক্ষেত্র TOK_RESTRICT1:
        ক্ষেত্র TOK_RESTRICT2:
        ক্ষেত্র TOK_RESTRICT3:
            t |= VT_RESTRICT;
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_REGISTER:
        ক্ষেত্র TOK_AUTO:
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_UNSIGNED:
            যদি ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            পরবর্তী();
            typespec_found = 1;
            বিরতি;

            /* storage */
        ক্ষেত্র TOK_EXTERN:
            g = VT_EXTERN;
            যাও storage;
        ক্ষেত্র TOK_STATIC:
            g = VT_STATIC;
            যাও storage;
        ক্ষেত্র TOK_TYPEDEF:
            g = VT_TYPEDEF;
            যাও storage;
       storage:
            যদি (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_INLINE1:
        ক্ষেত্র TOK_INLINE2:
        ক্ষেত্র TOK_INLINE3:
            t |= VT_INLINE;
            পরবর্তী();
            বিরতি;
        ক্ষেত্র TOK_NORETURN3:
            পরবর্তী();
            ad->f.func_noreturn = 1;
            বিরতি;
            /* GNUC attribute */
        ক্ষেত্র TOK_ATTRIBUTE1:
        ক্ষেত্র TOK_ATTRIBUTE2:
            parse_attribute(ad);
            যদি (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            চালু;
            /* GNUC typeof */
        ক্ষেত্র TOK_TYPEOF1:
        ক্ষেত্র TOK_TYPEOF2:
        ক্ষেত্র TOK_TYPEOF3:
            পরবর্তী();
            parse_রাশিমালা_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            যদি (type1.ref) {
                sym_to_attr(ad, type1.ref);
                যদি (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            যাও basic_type2;
        ক্ষেত্র TOK_THREAD_LOCAL:
        ক্ষেত্র TOK___thread:
            যদি (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            পরবর্তী();
            বিরতি;
        পূর্বনির্ধারিত:
            যদি (typespec_found)
                যাও the_end;
            s = sym_find(tok);
            যদি (!s || !(s->type.t & VT_TYPEDEF))
                যাও the_end;

            n = tok, পরবর্তী();
            যদি (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                যাও the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            যদি (t)
                parse_btype_qualify(type, t);
            t = type->t;
            যদি (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            বিরতি;
        }
        type_found = 1;
    }
the_end:
    যদি (tcc_state->char_is_unsigned) {
        যদি ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    যদি (bt == VT_LONG)
        t |= LONG_আকার == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    যদি (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    ফেরত type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
স্থির অন্তঃরেখ শূন্য convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    যদি ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
স্থির অন্তঃরেখ শূন্য convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(শূন্য)
{
    skip('(');
    ফেরত parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
স্থির পূর্ণসংখ্যা asm_label_instr(শূন্য)
{
    পূর্ণসংখ্যা v;
    অক্ষর *astr;

    পরবর্তী();
    astr = parse_asm_str()->তথ্য;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    ফেরত v;
}

স্থির পূর্ণসংখ্যা post_type(CType *type, AttributeDef *ad, পূর্ণসংখ্যা storage, পূর্ণসংখ্যা td)
{
    পূর্ণসংখ্যা n, l, t1, arg_আকার, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ফাঁকা;
    পূর্ণসংখ্যা *vla_array_str = ফাঁকা;

    যদি (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        পরবর্তী();
	যদি (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  ফেরত 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_স্তূপ ? &local_স্তূপ : &global_স্তূপ;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	যদি (tok == ')')
	  l = 0;
	অন্যথা যদি (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	অন্যথা যদি (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_বের_করো(ps, sr->পূর্ব, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    ফেরত 0;
	} অন্যথা
	  l = FUNC_OLD;

        first = ফাঁকা;
        plast = &first;
        arg_আকার = 0;
        যদি (l) {
            জন্য(;;) {
                /* read param name and compute offset */
                যদি (l != FUNC_OLD) {
                    যদি ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        বিরতি;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    যদি ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    যদি (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } অন্যথা {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ফাঁকা;
                    পরবর্তী();
                }
                যদি (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_আকার += (type_আকার(&pt, &align) + PTR_আকার - 1) / PTR_আকার;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ঠেলো(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->পরবর্তী;
                যদি (tok == ')')
                    বিরতি;
                skip(',');
                যদি (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    পরবর্তী();
                    বিরতি;
                }
		যদি (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } অন্যথা
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        যদি (tok == '[') {
            পরবর্তী();
            skip(']'); /* only handle simple "[]" */
            mk_pointer(type);
        }
        ad->f.func_args = arg_আকার;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->পরবর্তী = first;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_বের_করো(ps, sr, 1);
        --local_scope;

    } অন্যথা যদি (tok == '[') {
	পূর্ণসংখ্যা saved_nocode_wanted = nocode_wanted;
        পূর্ণসংখ্যা array_qualifiers = 0;
        /* array definition */
        পরবর্তী();
        n = -1;
        t1 = 0;
        যদি (td & TYPE_PARAM) যখন (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    নির্বাচন (tok) {
	    ক্ষেত্র TOK_CONST1: ক্ষেত্র TOK_CONST2: ক্ষেত্র TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		পরবর্তী();
		চালু;
	    ক্ষেত্র TOK_VOLATILE1: ক্ষেত্র TOK_VOLATILE2: ক্ষেত্র TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		পরবর্তী();
		চালু;
	    ক্ষেত্র TOK_RESTRICT1: ক্ষেত্র TOK_RESTRICT2: ক্ষেত্র TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		পরবর্তী();
		চালু;
	    ক্ষেত্র TOK_STATIC:
	    ক্ষেত্র '*':
		পরবর্তী();
		চালু;
	    পূর্বনির্ধারিত:
		বিরতি;
	    }
            যদি (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_block(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		পরবর্তী();
	        gexpr();
		end_macro();
		পরবর্তী();
		যাও check;
            }
            বিরতি;

	} অন্যথা যদি (tok != ']') {
            যদি (!local_স্তূপ || (storage & VT_STATIC))
                vpushi(রাশিমালা_const());
            অন্যথা {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            যদি ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                যদি (n < 0)
                    tcc_error("invalid array size");
            } অন্যথা {
                যদি (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        যদি ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        যদি ((type->t & VT_BTYPE) == VT_VOID
            || type_আকার(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        যদি (t1 & VT_VLA) {
            যদি (n < 0) {
		যদি  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    অন্যথা {
                loc -= type_আকার(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_আকার(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        যদি (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ঠেলো(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        যদি (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    যদি ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    অন্যথা
	        tok_str_free_str(vla_array_str);
	}
    }
    ফেরত 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
স্থির CType *type_decl(CType *type, AttributeDef *ad, পূর্ণসংখ্যা *v, পূর্ণসংখ্যা td)
{
    CType *post, *ret;
    পূর্ণসংখ্যা qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    যখন (tok == '*') {
        qualifiers = 0;
    redo:
        পরবর্তী();
        নির্বাচন(tok) {
        ক্ষেত্র TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            যাও redo;
        ক্ষেত্র TOK_CONST1:
        ক্ষেত্র TOK_CONST2:
        ক্ষেত্র TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            যাও redo;
        ক্ষেত্র TOK_VOLATILE1:
        ক্ষেত্র TOK_VOLATILE2:
        ক্ষেত্র TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            যাও redo;
        ক্ষেত্র TOK_RESTRICT1:
        ক্ষেত্র TOK_RESTRICT2:
        ক্ষেত্র TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            যাও redo;
	/* XXX: clarify attribute handling */
	ক্ষেত্র TOK_ATTRIBUTE1:
	ক্ষেত্র TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    বিরতি;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	যদি (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    যদি (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	যদি (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} অন্যথা
	  যাও abstract;
    } অন্যথা যদি (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	পরবর্তী();
    } অন্যথা {
  abstract:
	যদি (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ফেরত ret;
}

/* indirection with full error checking and bound check */
ST_FUNC শূন্য indir(শূন্য)
{
    যদি ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        যদি ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ফেরত;
        expect("pointer");
    }
    যদি (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    যদি (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        যদি (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
স্থির শূন্য gfunc_param_typed(Sym *func, Sym *arg)
{
    পূর্ণসংখ্যা func_type;
    CType type;

    func_type = func->f.func_type;
    যদি (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ফাঁকা)) {
        /* default casting : only need to convert float to double */
        যদি ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } অন্যথা যদি (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } অন্যথা যদি (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } অন্যথা যদি (arg == ফাঁকা) {
        tcc_error("too many arguments to function");
    } অন্যথা {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
স্থির শূন্য রাশিমালা_type(CType *type, শূন্য (*রাশিমালা_fn)(শূন্য))
{
    nocode_wanted++;
    রাশিমালা_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
স্থির শূন্য parse_রাশিমালা_type(CType *type)
{
    পূর্ণসংখ্যা n;
    AttributeDef ad;

    skip('(');
    যদি (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } অন্যথা {
        রাশিমালা_type(type, gexpr);
    }
    skip(')');
}

স্থির শূন্য parse_type(CType *type)
{
    AttributeDef ad;
    পূর্ণসংখ্যা n;

    যদি (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

স্থির শূন্য parse_builtin_params(পূর্ণসংখ্যা nc, ধ্রুবক অক্ষর *args)
{
    অক্ষর c, sep = '(';
    CType type;
    যদি (nc)
        nocode_wanted++;
    পরবর্তী();
    যদি (*args == 0)
	skip(sep);
    যখন ((c = *args++)) {
	skip(sep);
	sep = ',';
        যদি (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    চালু;
        }
        রাশিমালা_eq();
        type.ref = ফাঁকা;
        type.t = 0;
	নির্বাচন (c) {
	    ক্ষেত্র 'e':
		চালু;
	    ক্ষেত্র 'V':
                type.t = VT_CONSTANT;
	    ক্ষেত্র 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                বিরতি;
	    ক্ষেত্র 'S':
                type.t = VT_CONSTANT;
	    ক্ষেত্র 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                বিরতি;
	    ক্ষেত্র 'i':
                type.t = VT_INT;
                বিরতি;
	    ক্ষেত্র 'l':
                type.t = VT_আকার_T;
                বিরতি;
	    পূর্বনির্ধারিত:
                বিরতি;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    যদি (nc)
        nocode_wanted--;
}

স্থির শূন্য parse_atomic(পূর্ণসংখ্যা atok)
{
    পূর্ণসংখ্যা আকার_2, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    অক্ষর buf[40];
    স্থির ধ্রুবক অক্ষর *ধ্রুবক templates[] = {
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
    ধ্রুবক অক্ষর *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ফাঁকা;
    আকার_2 = 0; /* pacify compiler */
    পরবর্তী();
    skip('(');
    জন্য (arg = 0;;) {
        রাশিমালা_eq();
        নির্বাচন (template[arg]) {
        ক্ষেত্র 'a':
        ক্ষেত্র 'A':
            atom_ptr = &vtop->type;
            যদি ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            আকার_2 = type_আকার(atom, &align);
            যদি (আকার_2 > 8
                || (আকার_2 & (আকার_2 - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_আকার(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            বিরতি;

        ক্ষেত্র 'p':
            যদি ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_আকার(pointed_type(&vtop->type), &align) != আকার_2)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            বিরতি;
        ক্ষেত্র 'v':
            gen_assign_cast(atom);
            বিরতি;
        ক্ষেত্র 'l':
            indir();
            gen_assign_cast(atom);
            বিরতি;
        ক্ষেত্র 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            বিরতি;
        ক্ষেত্র 'm':
            gen_assign_cast(&int_type);
            বিরতি;
        ক্ষেত্র 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            বিরতি;
        }
        যদি ('.' == template[++arg])
            বিরতি;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    নির্বাচন (template[arg + 1]) {
    ক্ষেত্র 'b':
        ct.t = VT_BOOL;
        বিরতি;
    ক্ষেত্র 'v':
        ct = *atom;
        বিরতি;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), আকার_2);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    যদি (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#অন্যথা
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    যদি (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC শূন্য unary(শূন্য)
{
    পূর্ণসংখ্যা n, t, align, আকার_2, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    যদি (debug_modes)
        tcc_debug_সারি(tcc_state), tcc_tcov_check_সারি (tcc_state, 1);

    type.ref = ফাঁকা;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_পরবর্তী:
    নির্বাচন(tok) {
    ক্ষেত্র TOK_EXTENSION:
        পরবর্তী();
        যাও tok_পরবর্তী;
    ক্ষেত্র TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        যাও ঠেলো_tokc;
#endif
    ক্ষেত্র TOK_CINT:
    ক্ষেত্র TOK_CCHAR: 
	t = VT_INT;
 ঠেলো_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        পরবর্তী();
        বিরতি;
    ক্ষেত্র TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CLLONG:
        t = VT_LLONG;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CFLOAT:
        t = VT_FLOAT;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CDOUBLE:
        t = VT_DOUBLE;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#অন্যথা
        t = VT_LDOUBLE;
#endif
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CLONG:
        t = (LONG_আকার == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK_CULONG:
        t = (LONG_আকার == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	যাও ঠেলো_tokc;
    ক্ষেত্র TOK___FUNCTION__:
        যদি (!gnu_ext)
            যাও tok_identifier;
        /* fall thru */
    ক্ষেত্র TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.আকার_2 = tokcstr.আকার_2;
        tokc.str.তথ্য = tokcstr.তথ্য;
        যাও case_TOK_STR;
    ক্ষেত্র TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#অন্যথা
        t = VT_INT;
#endif
        যাও str_init;
    ক্ষেত্র TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        যদি (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, আকার(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        বিরতি;
    ক্ষেত্র TOK_SOTYPE:
    ক্ষেত্র '(':
        t = tok;
        পরবর্তী();
        /* cast ? */
        যদি (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            যদি (tok == '{') {
                    /* data is allocated locally by default */
                যদি (global_রাশিমালা)
                    r = VT_CONST;
                অন্যথা
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                যদি (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, আকার(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } অন্যথা যদি (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ফেরত;
            } অন্যথা {
                unary();
                gen_cast(&type);
            }
        } অন্যথা যদি (tok == '{') {
	    পূর্ণসংখ্যা saved_nocode_wanted = nocode_wanted;
            যদি (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            যদি (0 == local_scope)
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
            block(STMT_রাশিমালা);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            যদি (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } অন্যথা {
            gexpr();
            skip(')');
        }
        বিরতি;
    ক্ষেত্র '*':
        পরবর্তী();
        unary();
        indir();
        বিরতি;
    ক্ষেত্র '&':
        পরবর্তী();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        যদি ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        যদি (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        বিরতি;
    ক্ষেত্র '!':
        পরবর্তী();
        unary();
        gen_test_zero(TOK_EQ);
        বিরতি;
    ক্ষেত্র '~':
        পরবর্তী();
        unary();
        vpushi(-1);
        gen_op('^');
        বিরতি;
    ক্ষেত্র '+':
        পরবর্তী();
        unary();
        যদি ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	যদি (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        বিরতি;
    ক্ষেত্র TOK_SIZEOF:
    ক্ষেত্র TOK_ALIGNOF1:
    ক্ষেত্র TOK_ALIGNOF2:
    ক্ষেত্র TOK_ALIGNOF3:
        t = tok;
        পরবর্তী();
        যদি (tok == '(')
            tok = TOK_SOTYPE;
        রাশিমালা_type(&type, unary);
        যদি (t == TOK_SIZEOF) {
            vpush_type_আকার(&type, &align);
            gen_cast_s(VT_আকার_T);
        } অন্যথা {
            type_আকার(&type, &align);
            s = ফাঁকা;
            যদি (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            যদি (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        বিরতি;

    ক্ষেত্র TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        বিরতি;
    ক্ষেত্র TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        বিরতি;
    ক্ষেত্র TOK_builtin_choose_রাশিমালা:
	{
	    int64_t c;
	    পরবর্তী();
	    skip('(');
	    c = রাশিমালা_const64();
	    skip(',');
	    যদি (!c) {
		nocode_wanted++;
	    }
	    রাশিমালা_eq();
	    যদি (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    যদি (c) {
		nocode_wanted++;
	    }
	    রাশিমালা_eq();
	    যদি (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        বিরতি;
    ক্ষেত্র TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        বিরতি;
    ক্ষেত্র TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        বিরতি;
    ক্ষেত্র TOK_builtin_frame_address:
    ক্ষেত্র TOK_builtin_return_address:
        {
            পূর্ণসংখ্যা tok1 = tok;
            পূর্ণসংখ্যা level;
            পরবর্তী();
            skip('(');
            level = রাশিমালা_const();
            যদি (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            যখন (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_আকার);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            যদি (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_আকার);
                gen_op('+');
#নতুবা_যদি defined TCC_TARGET_RISCV64
                vpushi(PTR_আকার);
                gen_op('-');
#অন্যথা
                vpushi(PTR_আকার);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        বিরতি;
#ifdef TCC_TARGET_RISCV64
    ক্ষেত্র TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        যদি (r == VT_LLOCAL)
            r = VT_LOCAL;
        যদি (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        বিরতি;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    ক্ষেত্র TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        যদি (r == VT_LLOCAL)
            r = VT_LOCAL;
        যদি (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        বিরতি;
#অন্যথা
    ক্ষেত্র TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	বিরতি;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    ক্ষেত্র TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        বিরতি;
    }
    ক্ষেত্র TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        বিরতি;
    }
#endif
#ifdef TCC_TARGET_ARM64
    ক্ষেত্র TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        বিরতি;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    ক্ষেত্র TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        বিরতি;
    }
#endif

    /* atomic operations */
    ক্ষেত্র TOK___atomic_store:
    ক্ষেত্র TOK___atomic_load:
    ক্ষেত্র TOK___atomic_exchange:
    ক্ষেত্র TOK___atomic_compare_exchange:
    ক্ষেত্র TOK___atomic_fetch_add:
    ক্ষেত্র TOK___atomic_fetch_sub:
    ক্ষেত্র TOK___atomic_fetch_or:
    ক্ষেত্র TOK___atomic_fetch_xor:
    ক্ষেত্র TOK___atomic_fetch_and:
    ক্ষেত্র TOK___atomic_fetch_nand:
    ক্ষেত্র TOK___atomic_add_fetch:
    ক্ষেত্র TOK___atomic_sub_fetch:
    ক্ষেত্র TOK___atomic_or_fetch:
    ক্ষেত্র TOK___atomic_xor_fetch:
    ক্ষেত্র TOK___atomic_and_fetch:
    ক্ষেত্র TOK___atomic_nand_fetch:
        parse_atomic(tok);
        বিরতি;

    /* pre operations */
    ক্ষেত্র TOK_INC:
    ক্ষেত্র TOK_DEC:
        t = tok;
        পরবর্তী();
        unary();
        inc(0, t);
        বিরতি;
    ক্ষেত্র '-':
        পরবর্তী();
        unary();
	যদি (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} অন্যথা {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        বিরতি;
    ক্ষেত্র TOK_LAND:
        যদি (!gnu_ext)
            যাও tok_identifier;
        পরবর্তী();
        /* allow to take the address of a label */
        যদি (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        যদি (!s) {
            s = label_ঠেলো(&global_label_স্তূপ, tok, LABEL_FORWARD);
        } অন্যথা {
            যদি (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        যদি ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        পরবর্তী();
        বিরতি;

    ক্ষেত্র TOK_GENERIC:
    {
	CType controlling_type;
	পূর্ণসংখ্যা has_default = 0;
	পূর্ণসংখ্যা has_match = 0;
	পূর্ণসংখ্যা learn = 0;
	TokenString *str = ফাঁকা;
	পূর্ণসংখ্যা saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        পরবর্তী();
	skip('(');
	রাশিমালা_type(&controlling_type, রাশিমালা_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        জন্য (;;) {
	    learn = 0;
	    skip(',');
	    যদি (tok == TOK_DEFAULT) {
		যদি (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		যদি (!has_match)
		    learn = 1;
		পরবর্তী();
	    } অন্যথা {
		পূর্ণসংখ্যা v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		যদি (compare_types(&controlling_type, &type, 0)) {
		    যদি (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    যদি (learn) {
		যদি (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } অন্যথা {
		skip_or_save_block(ফাঁকা);
	    }
	    যদি (tok == ')')
		বিরতি;
	}
	যদি (!str) {
	    অক্ষর buf[60];
	    type_to_str(buf, আকার buf, &controlling_type, ফাঁকা);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	পরবর্তী();
	রাশিমালা_eq();
	যদি (tok != TOK_EOF)
	    expect(",");
	end_macro();
        পরবর্তী();
	বিরতি;
    }
    // special qnan , snan and infinity values
    ক্ষেত্র TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        পরবর্তী();
        বিরতি;
    ক্ষেত্র TOK___SNAN__:
	n = 0x7f800001;
	যাও special_math_val;
    ক্ষেত্র TOK___INF__:
	n = 0x7f800000;
	যাও special_math_val;

    পূর্বনির্ধারিত:
    tok_identifier:
        যদি (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        পরবর্তী();
        s = sym_find(t);
        যদি (!s || IS_ASM_SYM(s)) {
            ধ্রুবক অক্ষর *name = get_tok_str(t, ফাঁকা);
            যদি (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            যদি (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        যদি ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        যদি (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            যদি (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } অন্যথা যদি (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        বিরতি;
    }
    
    /* post operations */
    যখন (1) {
        যদি (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            পরবর্তী();
        } অন্যথা যদি (tok == '.' || tok == TOK_ARROW) {
            পূর্ণসংখ্যা qualifiers, cumofs;
            /* field */ 
            যদি (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            পরবর্তী();
	    s = find_field(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_pointer_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            যদি (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            যদি (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                যদি (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            পরবর্তী();
        } অন্যথা যদি (tok == '[') {
            পরবর্তী();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } অন্যথা যদি (tok == '(') {
            SValue ret;
            Sym *sa;
            পূর্ণসংখ্যা nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            যদি ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                যদি ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    যদি ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        যাও error_func;
                } অন্যথা {
                error_func:
                    expect("function pointer");
                }
            } অন্যথা {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            পরবর্তী();
            sa = s->পরবর্তী; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            যদি ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                যদি (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    আকার_2 = type_আকার(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                যদি (আকার_2 < 16)
                    যখন (আকার_2 & (আকার_2 - 1))
                        আকার_2 = (আকার_2 | (আকার_2 - 1)) + 1;
#endif
                    loc = (loc - আকার_2) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    যদি (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    যদি (ret_nregs < 0)
                      vtop--;
                    অন্যথা
                      nb_args++;
                }
            } অন্যথা {
                ret_nregs = 1;
                ret.type = s->type;
            }

            যদি (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ফাঁকা;
            যদি (tok != ')') {
                r = tcc_state->reverse_funcargs;
                জন্য(;;) {
                    যদি (r) {
                        skip_or_save_block(&p2);
                        p2->পূর্ব = p, p = p2;
                    } অন্যথা {
                        রাশিমালা_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    যদি (sa)
                        sa = sa->পরবর্তী;
                    যদি (tok == ')')
                        বিরতি;
                    skip(',');
                }
            }
            যদি (sa)
                tcc_error("too few arguments to function");

            যদি (p) { /* with reverse_funcargs */
                জন্য (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    করো {
                        sa = sa->পরবর্তী, p2 = p2->পূর্ব;
                    } যখন (p2 && sa);
                    p2 = p->পূর্ব;
                    begin_macro(p, 1), পরবর্তী();
                    রাশিমালা_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            পরবর্তী();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            যদি (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } অন্যথা {
                /* return value */
                n = ret_nregs;
                যখন (n > 1) {
                    পূর্ণসংখ্যা rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    জন্য (r = 0; r < NB_REGS; ++r)
                        যদি (reg_classes[r] & rc)
                            বিরতি;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                যদি (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    পূর্ণসংখ্যা addr, offset;

                    আকার_2 = type_আকার(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    আকার_2 = (আকার_2 + regsize - 1) & -regsize;
                    যদি (ret_align > align)
                        align = ret_align;
                    loc = (loc - আকার_2) & -align;
                    addr = loc;
                    offset = 0;
                    জন্য (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        যদি (--ret_nregs == 0)
                          বিরতি;
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
                যদি (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#অন্যথা
                    vtop->type.t = VT_INT;
#endif
                }
            }
            যদি (s->f.func_noreturn) {
                যদি (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } অন্যথা {
            বিরতি;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

স্থির শূন্য রাশিমালা_prod(শূন্য)
{
    পূর্ণসংখ্যা t;

    unary();
    যখন ((t = tok) == '*' || t == '/' || t == '%') {
        পরবর্তী();
        unary();
        gen_op(t);
    }
}

স্থির শূন্য রাশিমালা_যোগ(শূন্য)
{
    পূর্ণসংখ্যা t;

    রাশিমালা_prod();
    যখন ((t = tok) == '+' || t == '-') {
        পরবর্তী();
        রাশিমালা_prod();
        gen_op(t);
    }
}

স্থির শূন্য রাশিমালা_shift(শূন্য)
{
    পূর্ণসংখ্যা t;

    রাশিমালা_যোগ();
    যখন ((t = tok) == TOK_SHL || t == TOK_SAR) {
        পরবর্তী();
        রাশিমালা_যোগ();
        gen_op(t);
    }
}

স্থির শূন্য রাশিমালা_cmp(শূন্য)
{
    পূর্ণসংখ্যা t;

    রাশিমালা_shift();
    যখন (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        পরবর্তী();
        রাশিমালা_shift();
        gen_op(t);
    }
}

স্থির শূন্য রাশিমালা_cmpeq(শূন্য)
{
    পূর্ণসংখ্যা t;

    রাশিমালা_cmp();
    যখন ((t = tok) == TOK_EQ || t == TOK_NE) {
        পরবর্তী();
        রাশিমালা_cmp();
        gen_op(t);
    }
}

স্থির শূন্য রাশিমালা_and(শূন্য)
{
    রাশিমালা_cmpeq();
    যখন (tok == '&') {
        পরবর্তী();
        রাশিমালা_cmpeq();
        gen_op('&');
    }
}

স্থির শূন্য রাশিমালা_xor(শূন্য)
{
    রাশিমালা_and();
    যখন (tok == '^') {
        পরবর্তী();
        রাশিমালা_and();
        gen_op('^');
    }
}

স্থির শূন্য রাশিমালা_or(শূন্য)
{
    রাশিমালা_xor();
    যখন (tok == '|') {
        পরবর্তী();
        রাশিমালা_xor();
        gen_op('|');
    }
}

স্থির শূন্য রাশিমালা_landor(পূর্ণসংখ্যা op);

স্থির শূন্য রাশিমালা_land(শূন্য)
{
    রাশিমালা_or();
    যদি (tok == TOK_LAND)
        রাশিমালা_landor(tok);
}

স্থির শূন্য রাশিমালা_lor(শূন্য)
{
    রাশিমালা_land();
    যদি (tok == TOK_LOR)
        রাশিমালা_landor(tok);
}

# define রাশিমালা_landor_পরবর্তী(op) op == TOK_LAND ? রাশিমালা_or() : রাশিমালা_land()
#অন্যথা /* defined precedence_parser */
# define রাশিমালা_landor_পরবর্তী(op) unary(), রাশিমালা_infix(precedence(op) + 1)
# define রাশিমালা_lor() unary(), রাশিমালা_infix(1)

স্থির পূর্ণসংখ্যা precedence(পূর্ণসংখ্যা tok)
{
    নির্বাচন (tok) {
        ক্ষেত্র TOK_LOR: ফেরত 1;
        ক্ষেত্র TOK_LAND: ফেরত 2;
	ক্ষেত্র '|': ফেরত 3;
	ক্ষেত্র '^': ফেরত 4;
	ক্ষেত্র '&': ফেরত 5;
	ক্ষেত্র TOK_EQ: ক্ষেত্র TOK_NE: ফেরত 6;
 relat: ক্ষেত্র TOK_ULT: ক্ষেত্র TOK_UGE: ফেরত 7;
	ক্ষেত্র TOK_SHL: ক্ষেত্র TOK_SAR: ফেরত 8;
	ক্ষেত্র '+': ক্ষেত্র '-': ফেরত 9;
	ক্ষেত্র '*': ক্ষেত্র '/': ক্ষেত্র '%': ফেরত 10;
	পূর্বনির্ধারিত:
	    যদি (tok >= TOK_ULE && tok <= TOK_GT)
	        যাও relat;
	    ফেরত 0;
    }
}
স্থির unsigned অক্ষর prec[256];
স্থির শূন্য init_prec(শূন্য)
{
    পূর্ণসংখ্যা i;
    জন্য (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

স্থির শূন্য রাশিমালা_landor(পূর্ণসংখ্যা op);

স্থির শূন্য রাশিমালা_infix(পূর্ণসংখ্যা p)
{
    পূর্ণসংখ্যা t = tok, p2;
    যখন ((p2 = precedence(t)) >= p) {
        যদি (t == TOK_LOR || t == TOK_LAND) {
            রাশিমালা_landor(t);
        } অন্যথা {
            পরবর্তী();
            unary();
            যদি (precedence(tok) > p2)
              রাশিমালা_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
স্থির পূর্ণসংখ্যা condition_3way(শূন্য)
{
    পূর্ণসংখ্যা c = -1;
    যদি ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ফেরত c;
}

স্থির শূন্য রাশিমালা_landor(পূর্ণসংখ্যা op)
{
    পূর্ণসংখ্যা t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    জন্য(;;) {
        c = f ? i : condition_3way();
        যদি (c < 0)
            save_regs(1), cc = 0;
        অন্যথা যদি (c != i)
            nocode_wanted++, f = 1;
        যদি (tok != op)
            বিরতি;
        যদি (c < 0)
            t = gvtst(i, t);
        অন্যথা
            vpop();
        পরবর্তী();
        রাশিমালা_landor_পরবর্তী(op);
    }
    যদি (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } অন্যথা {
        gvtst_set(i, t);
    }
}

স্থির পূর্ণসংখ্যা is_cond_bool(SValue *sv)
{
    যদি ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ফেরত (unsigned)sv->c.i < 2;
    যদি (sv->r == VT_CMP)
        ফেরত 1;
    ফেরত 0;
}

স্থির শূন্য রাশিমালা_cond(শূন্য)
{
    পূর্ণসংখ্যা tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    রাশিমালা_lor();
    যদি (tok == '?') {
        পরবর্তী();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        যদি (!g) {
            যদি (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } অন্যথা {
                vpop();
            }
        } অন্যথা যদি (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        যদি (c == 0)
          nocode_wanted++;
        যদি (!g)
          gexpr();

        যদি ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        যদি (g) {
            u = tt;
        } অন্যথা যদি (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } অন্যথা
          u = 0;

        যদি (c == 0)
          nocode_wanted--;
        যদি (c == 1)
          nocode_wanted++;
        skip(':');
        রাশিমালা_cond();

        যদি ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        যদি (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        যদি (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            ফেরত;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        যদি (c != 1) {
            gen_cast(&type);
            যদি (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        যদি (USING_TWO_শব্দগুলি(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        যদি (c < 0) {
            যদি (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        যদি (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        যদি (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            যদি (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        যদি (c < 0) {
            যদি (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        যদি (islv)
          indir();
    }
}

স্থির শূন্য রাশিমালা_eq(শূন্য)
{
    পূর্ণসংখ্যা t;
    
    রাশিমালা_cond();
    যদি ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        পরবর্তী();
        যদি (t == '=') {
            রাশিমালা_eq();
        } অন্যথা {
            vdup();
            রাশিমালা_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC শূন্য gexpr(শূন্য)
{
    রাশিমালা_eq();
    যদি (tok == ',') {
        করো {
            vpop();
            পরবর্তী();
            রাশিমালা_eq();
        } যখন (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        যদি ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            যদি (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
স্থির শূন্য রাশিমালা_const1(শূন্য)
{
    nocode_wanted += CONST_WANTED_BIT;
    রাশিমালা_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
স্থির অন্তঃরেখ int64_t রাশিমালা_const64(শূন্য)
{
    int64_t c;
    রাশিমালা_const1();
    যদি ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ফেরত c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC পূর্ণসংখ্যা রাশিমালা_const(শূন্য)
{
    পূর্ণসংখ্যা c;
    int64_t wc = রাশিমালা_const64();
    c = wc;
    যদি (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    ফেরত c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
স্থির শূন্য gfunc_return(CType *func_type)
{
    যদি ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        পূর্ণসংখ্যা ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        যদি (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } অন্যথা যদি (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } অন্যথা {
            /* returning structure packed into registers */
            পূর্ণসংখ্যা আকার_2, addr, align, rc, n;
            আকার_2 = type_আকার(func_type,&align);
            যদি (ret_nregs * regsize > আকার_2 ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		যদি (ret_nregs * regsize > আকার_2)
		    আকার_2 = ret_nregs * regsize;
		যদি (ret_align > align)
		    align = ret_align;
                loc = (loc - আকার_2) & -align;
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
            জন্য (n = ret_nregs; --n > 0;) {
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
    } অন্যথা {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

স্থির শূন্য check_func_return(শূন্য)
{
    যদি ((func_vt.t & VT_BTYPE) == VT_VOID)
        ফেরত;
    যদি ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } অন্যথা {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

স্থির পূর্ণসংখ্যা case_cmp(uint64_t a, uint64_t b)
{
    যদি (cur_switch->sv.type.t & VT_UNSIGNED)
        ফেরত a < b ? -1 : a > b;
    অন্যথা
        ফেরত (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

স্থির পূর্ণসংখ্যা case_cmp_qs(ধ্রুবক শূন্য *pa, ধ্রুবক শূন্য *pb)
{
    ফেরত case_cmp((*(কাঠামো case_t**)pa)->v1, (*(কাঠামো case_t**)pb)->v1);
}

স্থির শূন্য case_sort(কাঠামো switch_t *sw)
{
    কাঠামো case_t **p;
    যদি (sw->n < 2)
        ফেরত;
    qsort(sw->p, sw->n, আকার *sw->p, case_cmp_qs);
    p = sw->p;
    যখন (p < sw->p + sw->n - 1) {
        যদি (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            পূর্ণসংখ্যা l1 = p[0]->সারি, l2 = p[1]->সারি;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } অন্যথা যদি (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * আকার *p);
        } অন্যথা
            ++p;
    }
}

স্থির পূর্ণসংখ্যা gcase(কাঠামো case_t **base, পূর্ণসংখ্যা len, পূর্ণসংখ্যা dsym)
{
    কাঠামো case_t *p;
    পূর্ণসংখ্যা t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    যদি (t != VT_LLONG)
        t = VT_INT;
    যখন (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        যদি (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } অন্যথা {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            যদি (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            অন্যথা
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
    ফেরত gjmp(dsym);
}

স্থির শূন্য end_switch(শূন্য)
{
    কাঠামো switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->পূর্ব;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
স্থির শূন্য save_lvalues(শূন্য)
{
    SValue *sv = vtop;
    যখন (sv >= vstack) {
        যদি (sv->sym && (sv->r & VT_LVAL)) {
            পূর্ণসংখ্যা align, আকার_2 = type_আকার(&sv->type, &align);
            পূর্ণসংখ্যা r2, l = get_অস্থায়ী_local_var(আকার_2, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

স্থির শূন্য try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    জন্য (; cls != stop; cls = cls->পরবর্তী) {
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


স্থির শূন্য try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    পূর্ণসংখ্যা ocd, ccd;

    যদি (!cur_scope->cl.s)
	ফেরত;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    জন্য (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->পরবর্তী)
      ;
    জন্য (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->পরবর্তী)
      ;
    জন্য (; cc != oc; cc = cc->পরবর্তী, oc = oc->পরবর্তী, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
স্থির শূন্য block_cleanup(কাঠামো scope *o)
{
    পূর্ণসংখ্যা jmp = 0;
    Sym *g, **pg;
    জন্য (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        যদি (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->পরবর্তী;
            যদি (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            যদি (!o->cl.n)
                যাও remove_pending;
            g->c = o->cl.n;
            pg = &g->পূর্ব;
        } অন্যথা {
    remove_pending:
            *pg = g->পূর্ব;
            sym_free(g);
        }
    }
    gsym(jmp);
    try_call_scope_cleanup(o->cl.s);
}

/* ------------------------------------------------------------------------- */
/* VLA */

স্থির শূন্য vla_restore(পূর্ণসংখ্যা loc)
{
    যদি (loc)
        gen_vla_sp_restore(loc);
}

স্থির শূন্য vla_leave(কাঠামো scope *o)
{
    কাঠামো scope *c = cur_scope, *v = ফাঁকা;
    জন্য (; c != o && c; c = c->পূর্ব)
      যদি (c->vla.অঙ্ক)
        v = c;
    যদি (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

স্থির শূন্য new_scope(কাঠামো scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->পূর্ব = cur_scope;
    cur_scope = o;
    cur_scope->vla.অঙ্ক = 0;

    /* record local declaration stack position */
    o->lstk = local_স্তূপ;
    o->llstk = local_label_স্তূপ;
    ++local_scope;
}

স্থির শূন্য পূর্ব_scope(কাঠামো scope *o, পূর্ণসংখ্যা is_রাশিমালা)
{
    vla_leave(o->পূর্ব);

    যদি (o->cl.s != o->পূর্ব->cl.s)
        block_cleanup(o->পূর্ব);

    যদি (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_রাশিমালা);

    /* pop locally defined labels */
    label_বের_করো(&local_label_স্তূপ, o->llstk, is_রাশিমালা);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_বের_করো(&local_স্তূপ, o->lstk, is_রাশিমালা);
    cur_scope = o->পূর্ব;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
স্থির শূন্য leave_scope(কাঠামো scope *o)
{
    যদি (!o)
        ফেরত;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
স্থির শূন্য new_scope_s(কাঠামো scope *o)
{
    o->lstk = local_স্তূপ;
    ++local_scope;
}

স্থির শূন্য পূর্ব_scope_s(কাঠামো scope *o)
{
    sym_বের_করো(&local_স্তূপ, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

স্থির শূন্য lblock(পূর্ণসংখ্যা *bsym, পূর্ণসংখ্যা *csym)
{
    কাঠামো scope *lo = loop_scope, *co = cur_scope;
    পূর্ণসংখ্যা *b = co->bsym, *c = co->csym;
    যদি (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    যদি (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
স্থির শূন্য gexpr_decl(শূন্য)
{
    পূর্ণসংখ্যা v = decl(VT_JMP);
    যদি (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } অন্যথা {
        যদি (v)
            skip(';');
        gexpr();
    }
}

স্থির শূন্য block(পূর্ণসংখ্যা flags)
{
    পূর্ণসংখ্যা a, b, c, d, e, t;
    কাঠামো scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    যদি (TOK_HAS_মান(t))
        যাও রাশিমালা;
    পরবর্তী();

    যদি (debug_modes)
        tcc_tcov_check_সারি (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    যদি (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        যদি (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            পরবর্তী();
            block(0);
            gsym(d); /* patch else jmp */
        } অন্যথা {
            gsym(a);
        }
        পূর্ব_scope_s(&o);

    } অন্যথা যদি (t == TOK_WHILE) {
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
        পূর্ব_scope_s(&o);

    } অন্যথা যদি (t == '{') {
        যদি (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        যখন (tok == TOK_LABEL) {
            করো {
                পরবর্তী();
                যদি (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ঠেলো(&local_label_স্তূপ, tok, LABEL_DECLARED);
                পরবর্তী();
            } যখন (tok == ',');
            skip(';');
        }

        যখন (tok != '}') {
	    decl(VT_LOCAL);
            যদি (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        পূর্ব_scope(&o, flags & STMT_রাশিমালা);
        যদি (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        যদি (local_scope)
            পরবর্তী();
        অন্যথা যদি (!nocode_wanted)
            check_func_return();

    } অন্যথা যদি (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        যদি (tok != ';') {
            gexpr();
            যদি (b) {
                gen_assign_cast(&func_vt);
            } অন্যথা {
                যদি (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } অন্যথা যদি (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } অন্যথা যদি (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(মূল_scope);
        যদি (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        যদি (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        যদি (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } অন্যথা যদি (t == TOK_BREAK) {
        /* compute jump */
        যদি (!cur_scope->bsym)
            tcc_error("cannot break");
        যদি (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        অন্যথা
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } অন্যথা যদি (t == TOK_CONTINUE) {
        /* compute jump */
        যদি (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } অন্যথা যদি (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        যদি (tok != ';') {
            /* c99 for-loop init decl? */
            যদি (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        যদি (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        যদি (tok != ')') {
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
        পূর্ব_scope(&o, 0);

    } অন্যথা যদি (t == TOK_DO) {
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
        পূর্ব_scope_s(&o);

    } অন্যথা যদি (t == TOK_SWITCH) {
        কাঠামো switch_t *sw;

        sw = tcc_mallocz(আকার *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->পূর্ব = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        যদি (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ফাঁকা);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        পূর্ব_scope_s(&o);
        যদি (sw->nocode_wanted)
            যাও skip_switch;
        case_sort(sw);
        sw->bsym = ফাঁকা; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        যদি (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        অন্যথা
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } অন্যথা যদি (t == TOK_CASE) {
        কাঠামো case_t *cr;
        যদি (!cur_switch)
            expect("switch");
        cr = tcc_malloc(আকার(কাঠামো case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(রাশিমালা_const64(), t);
        যদি (tok == TOK_DOTS && gnu_ext) {
            পরবর্তী();
            cr->v2 = value64(রাশিমালা_const64(), t);
            যদি (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        যদি (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->সারি = file->সারি_অঙ্ক;
        skip(':');
        যাও block_after_label;

    } অন্যথা যদি (t == TOK_DEFAULT) {
        যদি (!cur_switch)
            expect("switch");
        যদি (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        যাও block_after_label;

    } অন্যথা যদি (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        যদি (tok == '*' && gnu_ext) {
            /* computed goto */
            পরবর্তী();
            gexpr();
            যদি ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } অন্যথা যদি (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            যদি (!s)
              s = label_ঠেলো(&global_label_স্তূপ, tok, LABEL_FORWARD);
            অন্যথা যদি (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    যদি (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		যদি (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->পরবর্তী, SYM_FIELD, 0, 0);
                    pending_gotos->পরবর্তী = s;
                }
		s->jnext = gjmp(s->jnext);
	    } অন্যথা {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    পরবর্তী();

        } অন্যথা {
            expect("label identifier");
        }
        skip(';');

    } অন্যথা যদি (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } অন্যথা {
        যদি (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    পরবর্তী();
            s = label_find(t);
            যদি (s) {
                যদি (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ফাঁকা));
                s->r = LABEL_DEFINED;
		যদি (s->পরবর্তী) {
		    Sym *pcl; /* pending cleanup goto */
		    জন্য (pcl = s->পরবর্তী; pcl; pcl = pcl->পূর্ব)
		      gsym(pcl->jnext);
		    sym_বের_করো(&s->পরবর্তী, ফাঁকা, 0);
		} অন্যথা
		  gsym(s->jnext);
            } অন্যথা {
                s = label_ঠেলো(&global_label_স্তূপ, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ফাঁকা);

            যদি (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            যদি (tok != '}') {
                যদি (0 == (flags & STMT_COMPOUND))
                    যাও again;
                /* C23: insert implicit null-statement whithin compound statement */
            } অন্যথা {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } অন্যথা {
            /* expression case */
            যদি (t != ';') {
                unget_tok(t);
    রাশিমালা:
                যদি (flags & STMT_রাশিমালা) {
                    vpop();
                    gexpr();
                } অন্যথা {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    যদি (debug_modes)
        tcc_tcov_check_সারি (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
স্থির শূন্য skip_or_save_block(TokenString **str)
{
    পূর্ণসংখ্যা braces = tok == '{';
    পূর্ণসংখ্যা level = 0;
    যদি (str)
      *str = tok_str_alloc();

    যখন (1) {
	পূর্ণসংখ্যা t = tok;
        যদি (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             বিরতি;
	যদি (t == TOK_EOF) {
	     যদি (str || level > 0)
	       tcc_error("unexpected end of file");
	     অন্যথা
	       বিরতি;
	}
	যদি (str)
	  tok_str_add_tok(*str);
	পরবর্তী();
	যদি (t == '{' || t == '(' || t == '[') {
	    level++;
	} অন্যথা যদি (t == '}' || t == ')' || t == ']') {
	    level--;
	    যদি (level == 0 && braces && t == '}')
	      বিরতি;
	}
    }
    যদি (str)
	tok_str_add(*str, TOK_EOF);
}

#define রাশিমালা_CONST 1
#define রাশিমালা_ANY   2

স্থির শূন্য parse_init_elem(পূর্ণসংখ্যা রাশিমালা_type)
{
    পূর্ণসংখ্যা saved_global_রাশিমালা;
    নির্বাচন(রাশিমালা_type) {
    ক্ষেত্র রাশিমালা_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_রাশিমালা = global_রাশিমালা;
        global_রাশিমালা = 1;
        রাশিমালা_const1();
        global_রাশিমালা = saved_global_রাশিমালা;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        যদি (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        বিরতি;
    ক্ষেত্র রাশিমালা_ANY:
        রাশিমালা_eq();
        বিরতি;
    }
}

#যদি 1
স্থির শূন্য init_assert(init_params *p, পূর্ণসংখ্যা offset)
{
    যদি (p->sec ? !NODATA_WANTED && offset > p->sec->তথ্য_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#অন্যথা
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
স্থির শূন্য init_putz(init_params *p, unsigned long c, পূর্ণসংখ্যা আকার_2)
{
    init_assert(p, c + আকার_2);
    যদি (p->sec) {
        /* nothing to do because globals are already set to zero */
    } অন্যথা {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(আকার_2);
#যদি defined TCC_TARGET_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#endif
        gfunc_call(3);
    }
}

#define DIF_FIRST     1
#define DIF_আকার_ONLY 2
#define DIF_HAVE_ELEM 4
#define DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
স্থির শূন্য decl_design_delrels(Section *sec, পূর্ণসংখ্যা c, পূর্ণসংখ্যা আকার_2)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    যদি (!sec || !sec->reloc)
        ফেরত;
    rel = rel2 = (ElfW_Rel*)sec->reloc->তথ্য;
    rel_end = (ElfW_Rel*)(sec->reloc->তথ্য + sec->reloc->তথ্য_offset);
    যখন (rel < rel_end) {
        যদি (rel->r_offset >= c && rel->r_offset < c + আকার_2) {
            sec->reloc->তথ্য_offset -= আকার *rel;
        } অন্যথা {
            যদি (rel2 != rel)
                memcpy(rel2, rel, আকার *rel);
            ++rel2;
        }
        ++rel;
    }
}

স্থির শূন্য decl_design_flex(init_params *p, Sym *ref, পূর্ণসংখ্যা সূচক)
{
    যদি (ref == p->flex_array_ref) {
        যদি (সূচক >= ref->c)
            ref->c = সূচক + 1;
    } অন্যথা যদি (ref->c < 0 && সূচক >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
স্থির পূর্ণসংখ্যা decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, পূর্ণসংখ্যা flags, পূর্ণসংখ্যা al)
{
    Sym *s, *f;
    পূর্ণসংখ্যা সূচক, সূচক_last, align, l, nb_elems, elem_আকার;
    unsigned long corig = c;

    elem_আকার = 0;
    nb_elems = 1;

    যদি (flags & DIF_HAVE_ELEM)
        যাও no_designator;

    যদি (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, পরবর্তী();
        যদি (tok == ':')
            যাও struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    যখন (nb_elems == 1 && (tok == '[' || tok == '.')) {
        যদি (tok == '[') {
            যদি (!(type->t & VT_ARRAY))
                expect("array type");
            পরবর্তী();
            সূচক = সূচক_last = রাশিমালা_const();
            যদি (tok == TOK_DOTS && gnu_ext) {
                পরবর্তী();
                সূচক_last = রাশিমালা_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, সূচক_last);
            যদি (সূচক < 0 || সূচক_last >= s->c || সূচক_last < সূচক)
	        tcc_error("index exceeds array bounds or range is empty");
            যদি (cur_field)
		(*cur_field)->c = সূচক_last;
            type = pointed_type(type);
            elem_আকার = type_আকার(type, &align);
            c += সূচক * elem_আকার;
            nb_elems = সূচক_last - সূচক + 1;
        } অন্যথা {
            পূর্ণসংখ্যা cumofs;
            পরবর্তী();
            l = tok;
        struct_field:
            পরবর্তী();
	    f = find_field(type, l, &cumofs);
            যদি (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = ফাঁকা;
    }
    যদি (!cur_field) {
        যদি (tok == '=') {
            পরবর্তী();
        } অন্যথা যদি (!gnu_ext) {
	    expect("=");
        }
    } অন্যথা {
    no_designator:
        যদি (type->t & VT_ARRAY) {
	    সূচক = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, সূচক);
            যদি (সূচক >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_আকার = type_আকার(type, &align);
            c += সূচক * elem_আকার;
        } অন্যথা {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    যখন (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->পরবর্তী;
            যদি (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    যদি (!elem_আকার) /* for structs */
        elem_আকার = type_আকার(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    যদি (!(flags & DIF_আকার_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_আকার * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    যদি (!(flags & DIF_আকার_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        পূর্ণসংখ্যা i;
        যদি (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_আকার;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        যদি (p->sec)
            vpush_ref(type, p->sec, c, elem_আকার);
        অন্যথা
	    vset(type, VT_LOCAL|VT_LVAL, c);
        জন্য (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_আকার * i);
	}
        vpop();
    }

    c += nb_elems * elem_আকার;
    যদি (c - corig > al)
      al = c - corig;
    ফেরত al;
}

স্থির শূন্য write_ldouble(unsigned অক্ষর *d, শূন্য *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    যদি (LDOUBLE_আকার >= 10) {
        দ্বিগুণ b = *(long দ্বিগুণ*)s;
        s = &b;
#অন্যথা
    যদি (আকার (long দ্বিগুণ) == 8 && LDOUBLE_আকার >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        পূর্ণসংখ্যা e = m >> 48;
        পূর্ণসংখ্যা f = e >> 4 & 0x7FF;
        m <<= 11;
        যদি (0 == f) {
            যদি (0 == m)
                যাও set;
            জন্য (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        যদি (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #যদি (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #নতুবা_যদি LDOUBLE_আকার == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } অন্যথা {
    #যদি LDOUBLE_আকার == 8
        /* long double -> double */
        দ্বিগুণ b = *(long দ্বিগুণ*)s;
        memcpy(d, &b, 8);
    #নতুবা_যদি (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #নতুবা_যদি (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        পূর্ণসংখ্যা e = *(uint16_t*)((অক্ষর*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #নতুবা_যদি (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((অক্ষর*)s + 6);
        পূর্ণসংখ্যা e = read16le((অক্ষর*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #অন্যথা
        /* unknown */
        যদি (আকার (long দ্বিগুণ) == LDOUBLE_আকার)
            memcpy(d, s, LDOUBLE_আকার);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
স্থির শূন্য init_putv(init_params *p, CType *type, unsigned long c)
{
    পূর্ণসংখ্যা bt;
    শূন্য *ptr;
    CType dtype;
    পূর্ণসংখ্যা আকার_2, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    আকার_2 = type_আকার(type, &align);
    যদি (type->t & VT_BITFIELD)
        আকার_2 = (BIT_POS(type->t) + BIT_আকার(type->t) + 7) / 8;
    init_assert(p, c + আকার_2);

    যদি (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        যদি ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_আকার == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        যদি (NODATA_WANTED) {
            vtop--;
            ফেরত;
        }

        ptr = sec->তথ্য + c;
        val = vtop->c.i;

	যদি ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->তথ্য + esym->st_মান + (পূর্ণসংখ্যা)vtop->c.i, আকার_2);
	    যদি (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->তথ্য_offset;
		যখন (relofs >= আকার(*rel)) {
                    relofs -= আকার(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->তথ্য + relofs);
		    যদি (rel->r_offset >= esym->st_মান + আকার_2)
		      চালু;
		    যদি (rel->r_offset < esym->st_মান)
		      বিরতি;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_মান,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#যদি PTR_আকার == 8
				   rel->r_addend
#অন্যথা
				   0
#endif
				  );
		}
	    }
	} অন্যথা {
            যদি (type->t & VT_BITFIELD) {
                পূর্ণসংখ্যা bit_pos, bit_আকার, bits, n;
                unsigned অক্ষর *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_আকার = BIT_আকার(vtop->type.t);
                p = (unsigned অক্ষর*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                যখন (bit_আকার) {
                    n = 8 - bit_pos;
                    যদি (n > bit_আকার)
                        n = bit_আকার;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_আকার -= n, bit_pos = 0, ++p;
                }
            } অন্যথা
            নির্বাচন(bt) {
	    ক্ষেত্র VT_BOOL:
		*(অক্ষর *)ptr = val != 0;
                বিরতি;
	    ক্ষেত্র VT_BYTE:
		*(অক্ষর *)ptr = val;
		বিরতি;
	    ক্ষেত্র VT_SHORT:
                write16le(ptr, val);
		বিরতি;
	    ক্ষেত্র VT_FLOAT:
                write32le(ptr, val);
		বিরতি;
	    ক্ষেত্র VT_DOUBLE:
                write64le(ptr, val);
		বিরতি;
	    ক্ষেত্র VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		বিরতি;

#যদি PTR_আকার == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    ক্ষেত্র VT_LLONG:
	    ক্ষেত্র VT_PTR:
	        যদি (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_তথ্য_PTR, val);
	        অন্যথা
	          write64le(ptr, val);
	        বিরতি;
            ক্ষেত্র VT_INT:
                write32le(ptr, val);
                বিরতি;
#অন্যথা
	    ক্ষেত্র VT_LLONG:
                write64le(ptr, val);
                বিরতি;
            ক্ষেত্র VT_PTR:
            ক্ষেত্র VT_INT:
	        যদি (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_তথ্য_PTR);
	        write32le(ptr, val);
	        বিরতি;
#endif
	    পূর্বনির্ধারিত:
                //tcc_internal_error("unexpected type");
                বিরতি;
	    }
	}
        vtop--;
    } অন্যথা {
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
স্থির শূন্য decl_initializer(init_params *p, CType *type, unsigned long c, পূর্ণসংখ্যা flags)
{
    পূর্ণসংখ্যা len, n, no_oblock, i;
    পূর্ণসংখ্যা size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    যদি (debug_modes && !(flags & DIF_আকার_ONLY) && !p->sec)
        tcc_debug_সারি(tcc_state), tcc_tcov_check_সারি (tcc_state, 1);

    যদি (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_আকার_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        পূর্ণসংখ্যা ncw_পূর্ব = nocode_wanted;
        যদি ((flags & DIF_আকার_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? রাশিমালা_ANY : রাশিমালা_CONST);
        nocode_wanted = ncw_পূর্ব;
        flags |= DIF_HAVE_ELEM;
    }

    যদি (type->t & VT_ARRAY) {
        no_oblock = 1;
        যদি (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_আকার(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        যদি ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#অন্যথা
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            যদি (size1 != (tok == TOK_STR ? 1 : আকার(nwchar_t)))
              tcc_error("unhandled string literal merging");
            যখন (tok == TOK_STR || tok == TOK_LSTR) {
                যদি (initstr.আকার_2)
                  initstr.আকার_2 -= size1;
                যদি (tok == TOK_STR)
                  len += tokc.str.আকার_2;
                অন্যথা
                  len += tokc.str.আকার_2 / আকার(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.তথ্য, tokc.str.আকার_2);
                পরবর্তী();
            }
            যদি (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.আকার_2 = initstr.আকার_2;
                tokc.str.তথ্য = initstr.তথ্য;
                যাও do_init_array;
            }

            decl_design_flex(p, s, len);
            যদি (!(flags & DIF_আকার_ONLY)) {
                পূর্ণসংখ্যা nb = n, ch;
                যদি (len < nb)
                    nb = len;
                যদি (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                যদি (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    যদি (!NODATA_WANTED)
                      memcpy(p->sec->তথ্য + c, initstr.তথ্য, nb);
                } অন্যথা {
                    জন্য(i=0;i<n;i++) {
                        যদি (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          যদি (flags & DIF_CLEAR)
                            বিরতি;
                          যদি (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            বিরতি;
                          }
                          ch = 0;
                        } অন্যথা যদি (size1 == 1)
                          ch = ((unsigned অক্ষর *)initstr.তথ্য)[i];
                        অন্যথা
                          ch = ((nwchar_t *)initstr.তথ্য)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            যদি (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                পরবর্তী();
        } অন্যথা {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            যদি (!(flags & (DIF_CLEAR | DIF_আকার_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    যখন (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		যদি (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    যদি (no_oblock && len >= n*size1)
		        বিরতি;
		} অন্যথা {
		    যদি (s->type.t == VT_UNION)
		        f = ফাঁকা;
		    অন্যথা
		        f = f->পরবর্তী;
		    যদি (no_oblock && f == ফাঁকা)
		        বিরতি;
		}

		যদি (tok == '}')
		    বিরতি;
		skip(',');
	    }
        }
        যদি (!no_oblock)
            skip('}');

    } অন্যথা যদি ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        যাও one_elem;

    } অন্যথা যদি ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        যদি ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->পরবর্তী;
        n = s->c;
        size1 = 1;
	যাও do_init_list;

    } অন্যথা যদি (tok == '{') {
        যদি (flags & DIF_HAVE_ELEM)
          skip(';');
        পরবর্তী();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } অন্যথা one_elem: যদি ((flags & DIF_আকার_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        যদি (flags & DIF_HAVE_ELEM)
            vpop();
        অন্যথা
            skip_or_save_block(ফাঁকা);

    } অন্যথা {
	যদি (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    যদি (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? রাশিমালা_ANY : রাশিমালা_CONST);
	}
        যদি (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_আকার(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        অন্যথা
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
স্থির শূন্য decl_initializer_alloc(CType *type, AttributeDef *ad, পূর্ণসংখ্যা r, 
                                   পূর্ণসংখ্যা has_init, পূর্ণসংখ্যা v, পূর্ণসংখ্যা scope)
{
    পূর্ণসংখ্যা আকার_2, align, addr;
    TokenString *init_str = ফাঁকা;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ফাঁকা;
    পূর্ণসংখ্যা saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    পূর্ণসংখ্যা bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    যদি (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        যদি (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            যদি (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ফেরত;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    যদি (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= তথ্য_ONLY_WANTED;

    flexible_array = ফাঁকা;
    আকার_2 = type_আকার(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    যদি (আকার_2 < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        যদি (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        যদি (IS_BT_ARRAY(type->t))
            type->ref = sym_ঠেলো(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } অন্যথা যদি (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->পরবর্তী;
        যদি (field) {
            যখন (field->পরবর্তী)
                field = field->পরবর্তী;
            যদি (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                আকার_2 = -1;
            }
        }
    }

    যদি (আকার_2 < 0) {
        /* If unknown size, do a dry-run 1st pass */
        যদি (!has_init)
            যাও err_আকার;
        যদি (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            যখন (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                পরবর্তী();
            }
            tok_str_add(init_str, TOK_EOF);
        } অন্যথা
            skip_or_save_block(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        পরবর্তী();
        decl_initializer(&p, type, 0, DIF_FIRST | DIF_আকার_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        পরবর্তী();

        /* if still unknown size, error */
        আকার_2 = type_আকার(type, &align);
        যদি (আকার_2 < 0)
    err_আকার:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        যদি (flexible_array && flexible_array->type.ref->c > 0)
            আকার_2 += flexible_array->type.ref->c
                    * pointed_আকার(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    যদি (ad->a.aligned) {
	পূর্ণসংখ্যা speca = 1 << (ad->a.aligned - 1);
        যদি (speca > align)
            align = speca;
    } অন্যথা যদি (ad->a.packed) {
        align = 1;
    }

    যদি (!v && NODATA_WANTED)
        আকার_2 = 0, align = 1;

    যদি ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ফাঁকা;
#ifdef CONFIG_TCC_BCHECK
        যদি (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - আকার_2) & -align;
        addr = loc;
        p.local_offset = addr + আকার_2;
#ifdef CONFIG_TCC_BCHECK
        যদি (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        যদি (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    যদি (ad->asm_label) {
		পূর্ণসংখ্যা reg = asm_parse_regvar(ad->asm_label);
		যদি (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_ঠেলো(v, type, r, addr);
	    যদি (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->পরবর্তী = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } অন্যথা {
            /* push local reference */
            vset(type, r, addr);
        }
    } অন্যথা {
        CType *tp = type;
        পূর্ণসংখ্যা is_const;

        যখন ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        যদি (!sec) {
            যদি (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } অন্যথা যদি (is_const) {
		sec = rodata_section;
            } অন্যথা যদি (has_init) {
		sec = তথ্য_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } অন্যথা যদি (tcc_state->nocommon)
                sec = bss_section;
        } অন্যথা যদি (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            যদি (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                যদি (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        যদি (bcheck)
            আকার_2 = আকার_2 + 1; /* add padding */
#endif
        যদি (sec) {
	    addr = section_add(sec, আকার_2, align);
        } অন্যথা {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        যদি (v) {
            যদি (!sym) {
                sym = sym_ঠেলো(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ফাঁকা);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, আকার_2);
        } অন্যথা {
            /* push global reference */
            vpush_ref(type, sec, addr, আকার_2);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        যদি (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->তথ্য_offset, R_তথ্য_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * আকার(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = আকার_2 - 1;
        }
#endif
    }

    যদি (type->t & VT_VLA) {
        পূর্ণসংখ্যা a;

        যদি (has_init)
            tcc_error("variable length array cannot be initialized");

        যদি (NODATA_WANTED)
            যাও no_alloc;

        /* save before-VLA stack pointer if needed */
        যদি (cur_scope->vla.অঙ্ক == 0) {
            যদি (cur_scope->পূর্ব && cur_scope->পূর্ব->vla.অঙ্ক) {
                cur_scope->vla.locorig = cur_scope->পূর্ব->vla.loc;
            } অন্যথা {
                gen_vla_sp_save(loc -= PTR_আকার);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_আকার(type, &a);
        gen_vla_alloc(type, a);
#যদি defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_ফলাফল(addr), addr = (loc -= PTR_আকার);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.অঙ্ক++;
    } অন্যথা যদি (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        যদি (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    যদি (init_str) {
        end_macro();
        পরবর্তী();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
স্থির শূন্য func_vla_arg_code(Sym *arg)
{
    পূর্ণসংখ্যা align;
    TokenString *vla_array_tok = ফাঁকা;

    যদি (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    যদি ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_আকার(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	পরবর্তী();
	gexpr();
	end_macro();
	পরবর্তী();
	vpush_type_আকার(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

স্থির শূন্য func_vla_arg(Sym *sym)
{
    Sym *arg;

    জন্য (arg = sym->type.ref->পরবর্তী; arg; arg = arg->পরবর্তী)
        যদি ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, পূর্ণসংখ্যা c, পূর্ণসংখ্যা byref)
{
    s = sym_find(s->v);
    যদি (!s) /* unnamed parameters, not enabled */
        ফেরত ফাঁকা;
    s->c = c;
    যদি (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ফেরত s;
}

/* push parameters (and their types), last first */
স্থির শূন্য sym_ঠেলো_params(Sym *ref)
{
    Sym *s = ref;
    যখন (s->পরবর্তী)
        s = s->পরবর্তী;
    যখন (s != ref) {
        যদি ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_স্তূপ);
        s = s->পূর্ব;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
স্থির শূন্য gen_function(Sym *sym)
{
    কাঠামো scope f = { 0 };

    cur_scope = মূল_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->তথ্য_offset;
    যদি (sym->a.aligned) {
	আকার_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ফাঁকা);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    যদি (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    যদি (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_স্তূপ, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ঠেলো_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_অস্থায়ী_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(ফাঁকা, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_আকার = ind - func_ind;
    cur_text_section->তথ্য_offset = ind;

    sym_বের_করো(&local_স্তূপ, ফাঁকা, 0);
    label_বের_করো(&global_label_স্তূপ, ফাঁকা, 0);
    sym_বের_করো(&all_cleanups, ফাঁকা, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = ফাঁকা;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = তথ্য_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    পরবর্তী();
}

স্থির শূন্য gen_inline_functions(TCCState *s)
{
    Sym *sym;
    পূর্ণসংখ্যা inline_generated, i;
    কাঠামো InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    করো {
        inline_generated = 0;
        জন্য (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            যদি (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ফাঁকা;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                পরবর্তী();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } যখন (inline_generated);
    tcc_close();
}

স্থির শূন্য free_inline_functions(TCCState *s)
{
    পূর্ণসংখ্যা i;
    /* free tokens of unused inline functions */
    জন্য (i = 0; i < s->nb_inline_fns; ++i) {
        কাঠামো InlineFunc *fn = s->inline_fns[i];
        যদি (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

স্থির শূন্য do_Static_assert(শূন্য)
{
    পূর্ণসংখ্যা c;
    ধ্রুবক অক্ষর *বার্তা;

    পরবর্তী();
    skip('(');
    c = রাশিমালা_const();
    বার্তা = "_Static_assert fail";
    যদি (tok == ',') {
        পরবর্তী();
        বার্তা = parse_mult_str("string constant")->তথ্য;
    }
    skip(')');
    যদি (c == 0)
        tcc_error("%s", বার্তা);
    skip(';');
}

#ifdef TCC_TARGET_PE
স্থির শূন্য pe_check_linkage(CType *type, AttributeDef *ad)
{
    যদি (!ad->a.dllimport && !ad->a.dllexport)
        ফেরত;
    যদি (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    যদি (type->t & VT_TYPEDEF) {
        ধ্রুবক অক্ষর *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } অন্যথা যদি (ad->a.dllimport) {
        যদি ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        অন্যথা
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
স্থির পূর্ণসংখ্যা decl(পূর্ণসংখ্যা l)
{
    পূর্ণসংখ্যা v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    যখন (1) {

        oldint = 0;
        যদি (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            যদি (l == VT_JMP)
                ফেরত 0;
            /* skip redundant ';' if not in old parameter decl scope */
            যদি (tok == ';' && l != VT_CMP) {
                পরবর্তী();
                চালু;
            }
            যদি (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                চালু;
            }
            যদি (l != VT_CONST)
                বিরতি;
            যদি (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                চালু;
            }
            যদি (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } অন্যথা {
                যদি (tok != TOK_EOF)
                    expect("declaration");
                বিরতি;
            }
        }

        যদি (tok == ';') {
            যদি ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            অন্যথা যদি (IS_ENUM(btype.t))
                ; /* enum decl */
            অন্যথা
                tcc_warning("useless type defines no instances");
            যদি (l == VT_JMP)
                ফেরত 1;
            পরবর্তী();
            চালু;
        }

        যখন (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            যদি ((type.t & VT_BTYPE) == VT_FUNC) {
                যদি ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                যদি (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                যদি ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    যদি (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    অন্যথা
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } অন্যথা যদি (oldint) {
                tcc_warning("type defaults to int");
            }

            যদি (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #যদি 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                যদি (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            যদি (tok == '{') {
                যদি (l != VT_CONST)
                    tcc_error("cannot use local functions");
                যদি ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                জন্য (sa = sym->type.ref; (sa = sa->পরবর্তী) != ফাঁকা;) {
                    যদি (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    যদি (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                যদি (sym->type.t & VT_INLINE) {
                    কাঠামো InlineFunc *fn;
                    fn = tcc_malloc(আকার *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } অন্যথা {
                    /* compute text section */
                    cur_text_section = text_section;
                    যদি (ad.section) {
                        cur_text_section = ad.section;
                        যদি (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                বিরতি;
            } অন্যথা {
                has_init = 0;
		যদি (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    জন্য (sym = func_vt.ref->পরবর্তী; sym; sym = sym->পরবর্তী)
			যদি ((sym->v & ~SYM_FIELD) == v)
			    যাও found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ফাঁকা));
                found:
		    যদি (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ফাঁকা));
		    যদি (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ফাঁকা));
		    convert_parameter_type(&type);
		    sym->type = type;
		} অন্যথা যদি (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    যদি (sym && sym->sym_scope == local_scope) {
                        যদি (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ফাঁকা));
                        sym->type = type;
                    } অন্যথা {
                        sym = sym_ঠেলো(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    যদি ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    যদি (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} অন্যথা যদি ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } অন্যথা {
                    r = 0;
                    যদি ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } অন্যথা যদি (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    যদি (tok == '=')
                        has_init = 1;

                    যদি (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } অন্যথা {
                        যদি (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        অন্যথা
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        যদি (has_init)
                            পরবর্তী();
                        অন্যথা যদি (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    যদি (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        যদি (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_মান, esym->st_আকার, 1);
                    }
                }
                যদি (tok != ',') {
                    যদি (l == VT_JMP)
                        ফেরত has_init ? v : 1;
                    skip(';');
                    বিরতি;
                }
                পরবর্তী();
            }
        }
    }
    ফেরত 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
