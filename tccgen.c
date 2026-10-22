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
#അന്തര്ഭാവ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA പൂർണ്ണസംഖ്യ rsym, anon_sym, ind, loc;

ST_DATA Sym *global_അട്ടി;
ST_DATA Sym *local_അട്ടി;
ST_DATA Sym *define_അട്ടി;
ST_DATA Sym *global_label_അട്ടി;
ST_DATA Sym *local_label_അട്ടി;

സ്ഥിതം Sym *sym_free_first;
സ്ഥിതം ശൂന്യം **sym_pools;
സ്ഥിതം പൂർണ്ണസംഖ്യ nb_sym_pools;

സ്ഥിതം Sym *all_cleanups, *pending_gotos;
സ്ഥിതം പൂർണ്ണസംഖ്യ local_scope;
ST_DATA അക്ഷരം debug_modes;

ST_DATA SValue *vtop;
സ്ഥിതം SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA പൂർണ്ണസംഖ്യ nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() എങ്കിൽ(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA പൂർണ്ണസംഖ്യ global_വ്യഞ്ജകം;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA പൂർണ്ണസംഖ്യ func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA പൂർണ്ണസംഖ്യ func_vc; /* stack address for implicit struct return storage */
ST_DATA പൂർണ്ണസംഖ്യ func_ind; /* function start address */
സ്ഥിതം പൂർണ്ണസംഖ്യ func_old;
ST_DATA സ്ഥിരം അക്ഷരം *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
സ്ഥിതം CString initstr;

#എങ്കിൽ PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#അല്ലെങ്കിലെങ്കിൽ LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#അല്ലെങ്കിൽ
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

സ്ഥിതം ഘടന switch_t {
    ഘടന case_t {
        int64_t v1, v2;
        പൂർണ്ണസംഖ്യ ind, വരി;
    } **p; പൂർണ്ണസംഖ്യ n; /* list of case ranges */
    പൂർണ്ണസംഖ്യ def_sym; /* default symbol */
    പൂർണ്ണസംഖ്യ nocode_wanted;
    പൂർണ്ണസംഖ്യ *bsym;
    ഘടന scope *scope;
    ഘടന switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_സംഖ്യ 8
/*list of temporary local variables on the stack in current function. */
സ്ഥിതം ഘടന temp_local_variable {
	പൂർണ്ണസംഖ്യ location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_സംഖ്യ];
സ്ഥിതം പൂർണ്ണസംഖ്യ nb_temp_local_vars;

സ്ഥിതം ഘടന scope {
    ഘടന scope *prev;
    ഘടന { പൂർണ്ണസംഖ്യ loc, locorig, അക്കം; } vla;
    ഘടന { Sym *s; പൂർണ്ണസംഖ്യ n; } cl;
    പൂർണ്ണസംഖ്യ *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *വേര്_scope;

തരനിർവചനം ഘടന {
    Section *sec;
    പൂർണ്ണസംഖ്യ local_offset;
    Sym *flex_array_ref;
} init_params;

#എങ്കിൽ 1
#define precedence_parser
സ്ഥിതം ശൂന്യം init_prec(ശൂന്യം);
#endif

സ്ഥിതം ശൂന്യം block(പൂർണ്ണസംഖ്യ flags);
#define STMT_വ്യഞ്ജകം 1
#define STMT_COMPOUND 2

സ്ഥിതം ശൂന്യം gen_cast(CType *type);
സ്ഥിതം ശൂന്യം gen_cast_s(പൂർണ്ണസംഖ്യ t);
സ്ഥിതം വരിയിൽ CType *pointed_type(CType *type);
സ്ഥിതം ശൂന്യം check_restrict_type(CType *type);
സ്ഥിതം പൂർണ്ണസംഖ്യ type_qualifiers(CType *type);
സ്ഥിതം ശൂന്യം parse_btype_qualify(CType *type, പൂർണ്ണസംഖ്യ qualifiers);
സ്ഥിതം പൂർണ്ണസംഖ്യ is_compatible_types(CType *type1, CType *type2);
സ്ഥിതം പൂർണ്ണസംഖ്യ parse_btype(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ ignore_label);
സ്ഥിതം CType *type_decl(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ *v, പൂർണ്ണസംഖ്യ td);
സ്ഥിതം ശൂന്യം parse_വ്യഞ്ജകം_type(CType *type);
സ്ഥിതം ശൂന്യം init_putv(init_params *p, CType *type, unsigned long c);
സ്ഥിതം ശൂന്യം decl_initializer(init_params *p, CType *type, unsigned long c, പൂർണ്ണസംഖ്യ flags);
സ്ഥിതം ശൂന്യം decl_initializer_alloc(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ has_init, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ scope);
സ്ഥിതം പൂർണ്ണസംഖ്യ decl(പൂർണ്ണസംഖ്യ l);
സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_eq(ശൂന്യം);
സ്ഥിതം ശൂന്യം vpush_type_size(CType *type, പൂർണ്ണസംഖ്യ *a);
സ്ഥിതം പൂർണ്ണസംഖ്യ is_compatible_unqualified_types(CType *type1, CType *type2);
സ്ഥിതം വരിയിൽ int64_t വ്യഞ്ജകം_const64(ശൂന്യം);
സ്ഥിതം ശൂന്യം vpush64(പൂർണ്ണസംഖ്യ ty, unsigned long long v);
സ്ഥിതം ശൂന്യം vpush(CType *type);
സ്ഥിതം പൂർണ്ണസംഖ്യ gvtst(പൂർണ്ണസംഖ്യ inv, പൂർണ്ണസംഖ്യ t);
സ്ഥിതം ശൂന്യം gen_inline_functions(TCCState *s);
സ്ഥിതം ശൂന്യം free_inline_functions(TCCState *s);
സ്ഥിതം ശൂന്യം skip_or_save_block(TokenString **str);
സ്ഥിതം ശൂന്യം gv_dup(ശൂന്യം);
സ്ഥിതം പൂർണ്ണസംഖ്യ get_temp_local_var(പൂർണ്ണസംഖ്യ size,പൂർണ്ണസംഖ്യ align,പൂർണ്ണസംഖ്യ *r2);
സ്ഥിതം ശൂന്യം cast_error(CType *st, CType *dt);
സ്ഥിതം ശൂന്യം end_switch(ശൂന്യം);
സ്ഥിതം ശൂന്യം do_Static_assert(ശൂന്യം);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC ശൂന്യം gsym(പൂർണ്ണസംഖ്യ t)
{
  എങ്കിൽ (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
സ്ഥിതം പൂർണ്ണസംഖ്യ gind()
{
  പൂർണ്ണസംഖ്യ t = ind;
  CODE_ON();
  എങ്കിൽ (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  തിരികെ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
സ്ഥിതം ശൂന്യം gjmp_addr_acs(പൂർണ്ണസംഖ്യ t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
സ്ഥിതം പൂർണ്ണസംഖ്യ gjmp_acs(പൂർണ്ണസംഖ്യ t)
{
  t = gjmp(t);
  CODE_OFF();
  തിരികെ t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN പൂർണ്ണസംഖ്യ is_float(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ bt = t & VT_BTYPE;
    തിരികെ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ is_integer_btype(പൂർണ്ണസംഖ്യ bt)
{
    തിരികെ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ btype_size(പൂർണ്ണസംഖ്യ bt)
{
    തിരികെ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
സ്ഥിതം പൂർണ്ണസംഖ്യ R_RET(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ (!is_float(t))
        തിരികെ REG_IRET;
#ifdef TCC_TARGET_X86_64
    എങ്കിൽ ((t & VT_BTYPE) == VT_LDOUBLE)
        തിരികെ TREG_ST0;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    എങ്കിൽ ((t & VT_BTYPE) == VT_LDOUBLE)
        തിരികെ REG_IRET;
#endif
    തിരികെ REG_FRET;
}

/* returns 2nd function return register, if any */
സ്ഥിതം പൂർണ്ണസംഖ്യ R2_RET(പൂർണ്ണസംഖ്യ t)
{
    t &= VT_BTYPE;
#എങ്കിൽ PTR_SIZE == 4
    എങ്കിൽ (t == VT_LLONG)
        തിരികെ REG_IRE2;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
    എങ്കിൽ (t == VT_QLONG)
        തിരികെ REG_IRE2;
    എങ്കിൽ (t == VT_QFLOAT)
        തിരികെ REG_FRE2;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    എങ്കിൽ (t == VT_LDOUBLE)
        തിരികെ REG_IRE2;
#endif
    തിരികെ VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_വാക്കുകൾ(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
സ്ഥിതം ശൂന്യം PUT_R_RET(SValue *sv, പൂർണ്ണസംഖ്യ t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
സ്ഥിതം പൂർണ്ണസംഖ്യ RC_RET(പൂർണ്ണസംഖ്യ t)
{
    തിരികെ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
സ്ഥിതം പൂർണ്ണസംഖ്യ RC_TYPE(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ (!is_float(t))
        തിരികെ RC_INT;
#ifdef TCC_TARGET_X86_64
    എങ്കിൽ ((t & VT_BTYPE) == VT_LDOUBLE)
        തിരികെ RC_ST0;
    എങ്കിൽ ((t & VT_BTYPE) == VT_QFLOAT)
        തിരികെ RC_FRET;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    എങ്കിൽ ((t & VT_BTYPE) == VT_LDOUBLE)
        തിരികെ RC_INT;
#endif
    തിരികെ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
സ്ഥിതം പൂർണ്ണസംഖ്യ RC2_TYPE(പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ rc)
{
    എങ്കിൽ (!USING_TWO_വാക്കുകൾ(t))
        തിരികെ 0;
#ifdef RC_IRE2
    എങ്കിൽ (rc == RC_IRET)
        തിരികെ RC_IRE2;
#endif
#ifdef RC_FRE2
    എങ്കിൽ (rc == RC_FRET)
        തിരികെ RC_FRE2;
#endif
    എങ്കിൽ (rc & RC_FLOAT)
        തിരികെ RC_FLOAT;
    തിരികെ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC പൂർണ്ണസംഖ്യ ieee_finite(ഇരട്ട d)
{
    പൂർണ്ണസംഖ്യ p[4];
    memcpy(p, &d, വലുപ്പം(ഇരട്ട));
    തിരികെ ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC ശൂന്യം test_lvalue(ശൂന്യം)
{
    എങ്കിൽ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC ശൂന്യം check_vstack(ശൂന്യം)
{
    എങ്കിൽ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (പൂർണ്ണസംഖ്യ)(vtop - vstack + 1));
}

#എങ്കിൽ 0
/* dump 'b' vstack entries starting with 'a'  */
ശൂന്യം pv (സ്ഥിരം അക്ഷരം *lbl, പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (പൂർണ്ണസംഖ്യ)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
സ്ഥിതം വരിയിൽ ശൂന്യം psyms(സ്ഥിരം അക്ഷരം *സന്ദേശം, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", സന്ദേശം);
    ആകുമ്പോൾ (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

സ്ഥിതം ശൂന്യം type_to_str(അക്ഷരം *buf, പൂർണ്ണസംഖ്യ buf_size, CType *type, സ്ഥിരം അക്ഷരം *varstr);

/* print type */
സ്ഥിതം ശൂന്യം ptype(സ്ഥിരം അക്ഷരം *സന്ദേശം, CType *type, പൂർണ്ണസംഖ്യ v)
{
    അക്ഷരം buf[500];
    type_to_str(buf, വലുപ്പം(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, ശൂന്യ) : ശൂന്യ);
    printf("%s : %s;\n", സന്ദേശം, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC ശൂന്യം tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, വലുപ്പം *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    എങ്കിൽ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_തള്ളുക(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC പൂർണ്ണസംഖ്യ tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_വ്യഞ്ജകം = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_അക്കം | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#എങ്കിൽ TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    തിരികെ 0;
}

ST_FUNC ശൂന്യം tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_എടുക്കുക(&global_അട്ടി, ശൂന്യ, 0);
    sym_എടുക്കുക(&local_അട്ടി, ശൂന്യ, 0);
    /* free preprocessor macros */
    free_defines(ശൂന്യ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    ആകുമ്പോൾ (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = ശൂന്യ;
    all_cleanups = ശൂന്യ;
    pending_gotos = ശൂന്യ;
    nb_temp_local_vars = 0;
    global_label_അട്ടി = ശൂന്യ;
    local_label_അട്ടി = ശൂന്യ;
    cur_text_section = ശൂന്യ;
    sym_free_first = ശൂന്യ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  എങ്കിൽ (!s || !s->c)
    തിരികെ ശൂന്യ;
  തിരികെ &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC ശൂന്യം update_storage(Sym *sym)
{
    ElfSym *esym;
    പൂർണ്ണസംഖ്യ sym_bind, old_sym_bind;

    esym = elfsym(sym);
    എങ്കിൽ (!esym)
        തിരികെ;

    എങ്കിൽ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    എങ്കിൽ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    അല്ലെങ്കിൽ എങ്കിൽ (sym->a.weak)
        sym_bind = STB_WEAK;
    അല്ലെങ്കിൽ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    എങ്കിൽ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    എങ്കിൽ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    എങ്കിൽ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#എങ്കിൽ 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ശൂന്യ),
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

ST_FUNC ശൂന്യം put_extern_sym2(Sym *sym, പൂർണ്ണസംഖ്യ sh_അക്കം,
                            addr_t മൂല്യം, unsigned long size,
                            പൂർണ്ണസംഖ്യ can_add_underscore)
{
    പൂർണ്ണസംഖ്യ sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    സ്ഥിരം അക്ഷരം *name;
    അക്ഷരം buf1[256];

    എങ്കിൽ (!sym->c) {
        name = get_tok_str(sym->v, ശൂന്യ);
        t = sym->type.t;
        എങ്കിൽ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } അല്ലെങ്കിൽ എങ്കിൽ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            എങ്കിൽ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } അല്ലെങ്കിൽ എങ്കിൽ (t & VT_TLS) {
            sym_type = STT_TLS;
        } അല്ലെങ്കിൽ {
            sym_type = STT_OBJECT;
        }
        എങ്കിൽ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        അല്ലെങ്കിൽ
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        എങ്കിൽ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            എങ്കിൽ (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            എങ്കിൽ (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        എങ്കിൽ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ശൂന്യ);
            can_add_underscore = 0;
        }

        എങ്കിൽ (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, വലുപ്പം(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, മൂല്യം, size, info, other, sh_അക്കം, name);

        എങ്കിൽ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_അക്കം, sym_bind, sym_type);

    } അല്ലെങ്കിൽ {
        esym = elfsym(sym);
        esym->st_മൂല്യം = മൂല്യം;
        esym->st_size = size;
        esym->st_shndx = sh_അക്കം;
    }
    update_storage(sym);
}

ST_FUNC ശൂന്യം put_extern_sym(Sym *sym, Section *s, addr_t മൂല്യം, unsigned long size)
{
    എങ്കിൽ (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        തിരികെ;
    put_extern_sym2(sym, s ? s->sh_അക്കം : SHN_UNDEF, മൂല്യം, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC ശൂന്യം greloca(Section *s, Sym *sym, unsigned long offset, പൂർണ്ണസംഖ്യ type,
                     addr_t addend)
{
    പൂർണ്ണസംഖ്യ c = 0;

    എങ്കിൽ (nocode_wanted && s == cur_text_section)
        തിരികെ;

    എങ്കിൽ (sym) {
        എങ്കിൽ (0 == sym->c) {
            put_extern_sym(sym, ശൂന്യ, 0, 0);
            എങ്കിൽ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ആകുമ്പോൾ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#എങ്കിൽ PTR_SIZE == 4
ST_FUNC ശൂന്യം greloc(Section *s, Sym *sym, unsigned long offset, പൂർണ്ണസംഖ്യ type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
സ്ഥിതം Sym *__sym_malloc(ശൂന്യം)
{
    Sym *sym_pool, *sym, *last_sym;
    പൂർണ്ണസംഖ്യ i;

    sym_pool = tcc_malloc(SYM_POOL_NB * വലുപ്പം(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    വേണ്ടി(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    തിരികെ last_sym;
}

സ്ഥിതം വരിയിൽ Sym *sym_malloc(ശൂന്യം)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    എങ്കിൽ (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    തിരികെ sym;
#അല്ലെങ്കിൽ
    sym = tcc_malloc(വലുപ്പം(Sym));
    തിരികെ sym;
#endif
}

ST_INLN ശൂന്യം sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#അല്ലെങ്കിൽ
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, വലുപ്പം *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    തിരികെ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, പൂർണ്ണസംഖ്യ v)
{
    ആകുമ്പോൾ (s) {
        എങ്കിൽ (s->v == v)
            തിരികെ s;
        s = s->prev;
    }
    തിരികെ ശൂന്യ;
}

/* structure lookup */
ST_INLN Sym *struct_find(പൂർണ്ണസംഖ്യ v)
{
    v -= TOK_IDENT;
    എങ്കിൽ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        തിരികെ ശൂന്യ;
    തിരികെ table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(പൂർണ്ണസംഖ്യ v)
{
    v -= TOK_IDENT;
    എങ്കിൽ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        തിരികെ ശൂന്യ;
    തിരികെ table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
സ്ഥിതം വരിയിൽ ശൂന്യം sym_link(Sym *s, പൂർണ്ണസംഖ്യ yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    എങ്കിൽ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    അല്ലെങ്കിൽ
        ps = &ts->sym_identifier;
    എങ്കിൽ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } അല്ലെങ്കിൽ {
        *ps = s->prev_tok;
    }
}

സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    തിരികെ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_തള്ളുക(പൂർണ്ണസംഖ്യ v, CType *type, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ c)
{
    Sym *s, **ps;
    എങ്കിൽ (local_അട്ടി)
        ps = &local_അട്ടി;
    അല്ലെങ്കിൽ
        ps = &global_അട്ടി;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    എങ്കിൽ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        എങ്കിൽ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ശൂന്യ));
    }
    തിരികെ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_തള്ളുക(പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ c)
{
    Sym *s, **ps;
    s = sym_push2(&global_അട്ടി, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    എങ്കിൽ (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ആകുമ്പോൾ (*ps != ശൂന്യ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    തിരികെ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC ശൂന്യം sym_എടുക്കുക(Sym **ptop, Sym *b, പൂർണ്ണസംഖ്യ keep)
{
    Sym *s, *ss;
    പൂർണ്ണസംഖ്യ v;

    s = *ptop;
    ആകുമ്പോൾ(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        എങ്കിൽ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	എങ്കിൽ (!keep)
	    sym_free(s);
        s = ss;
    }
    എങ്കിൽ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(പൂർണ്ണസംഖ്യ v)
{
    v -= TOK_IDENT;
    എങ്കിൽ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        തിരികെ ശൂന്യ;
    തിരികെ table_ident[v]->sym_label;
}

ST_FUNC Sym *label_തള്ളുക(Sym **ptop, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    എങ്കിൽ (ptop == &global_label_അട്ടി) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ആകുമ്പോൾ (*ps != ശൂന്യ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    തിരികെ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC ശൂന്യം label_എടുക്കുക(Sym **ptop, Sym *slast, പൂർണ്ണസംഖ്യ keep)
{
    Sym *s, *s1;
    വേണ്ടി(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        എങ്കിൽ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ശൂന്യ));
        } അല്ലെങ്കിൽ എങ്കിൽ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ശൂന്യ));
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        എങ്കിൽ (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        എങ്കിൽ (!keep)
            sym_free(s);
        അല്ലെങ്കിൽ
            s->r = LABEL_GONE;
    }
    എങ്കിൽ (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
സ്ഥിതം ശൂന്യം vcheck_cmp(ശൂന്യം)
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

    എങ്കിൽ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

സ്ഥിതം ശൂന്യം vsetc(CType *type, പൂർണ്ണസംഖ്യ r, CValue *vc)
{
    എങ്കിൽ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ശൂന്യ;
}

ST_FUNC ശൂന്യം vswap(ശൂന്യം)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC ശൂന്യം vpop(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ v;
    v = vtop->r & VT_VALMASK;
#എങ്കിൽ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    എങ്കിൽ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } അല്ലെങ്കിൽ
#endif
    എങ്കിൽ (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
സ്ഥിതം ശൂന്യം vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
സ്ഥിതം ശൂന്യം vpush64(പൂർണ്ണസംഖ്യ ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ശൂന്യ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC ശൂന്യം vpushi(പൂർണ്ണസംഖ്യ v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
സ്ഥിതം ശൂന്യം vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
സ്ഥിതം വരിയിൽ ശൂന്യം vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC ശൂന്യം vset(CType *type, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

സ്ഥിതം ശൂന്യം vseti(പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ശൂന്യ;
    vset(&type, r, v);
}

ST_FUNC ശൂന്യം vpushv(SValue *v)
{
    എങ്കിൽ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

സ്ഥിതം ശൂന്യം vdup(ശൂന്യം)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC ശൂന്യം vrotb(പൂർണ്ണസംഖ്യ n)
{
    SValue tmp;
    എങ്കിൽ (--n < 1)
        തിരികെ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, വലുപ്പം *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC ശൂന്യം vrott(പൂർണ്ണസംഖ്യ n)
{
    SValue tmp;
    എങ്കിൽ (--n < 1)
        തിരികെ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, വലുപ്പം *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC ശൂന്യം vrev(പൂർണ്ണസംഖ്യ n)
{
    പൂർണ്ണസംഖ്യ i;
    SValue tmp;
    vcheck_cmp();
    വേണ്ടി (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC ശൂന്യം vset_VT_CMP(പൂർണ്ണസംഖ്യ op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
സ്ഥിതം ശൂന്യം vset_VT_JMP(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ op = vtop->cmp_op;

    എങ്കിൽ (vtop->jtrue || vtop->jfalse) {
        പൂർണ്ണസംഖ്യ origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        പൂർണ്ണസംഖ്യ inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } അല്ലെങ്കിൽ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        എങ്കിൽ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
സ്ഥിതം ശൂന്യം gvtst_set(പൂർണ്ണസംഖ്യ inv, പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ *p;

    എങ്കിൽ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        എങ്കിൽ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
സ്ഥിതം പൂർണ്ണസംഖ്യ gvtst(പൂർണ്ണസംഖ്യ inv, പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    എങ്കിൽ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    എങ്കിൽ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    അല്ലെങ്കിൽ എങ്കിൽ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    തിരികെ t;
}

/* generate a zero or nozero test */
സ്ഥിതം ശൂന്യം gen_test_zero(പൂർണ്ണസംഖ്യ op)
{
    എങ്കിൽ (vtop->r == VT_CMP) {
        പൂർണ്ണസംഖ്യ j;
        എങ്കിൽ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } അല്ലെങ്കിൽ {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC ശൂന്യം vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    പൂർണ്ണസംഖ്യ v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_തള്ളുക(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    തിരികെ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
സ്ഥിതം ശൂന്യം vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(പൂർണ്ണസംഖ്യ v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    എങ്കിൽ (!s) {
        /* push forward reference */
        s = global_identifier_തള്ളുക(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } അല്ലെങ്കിൽ എങ്കിൽ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    തിരികെ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(പൂർണ്ണസംഖ്യ v)
{
    CType ct = { VT_ASM_FUNC, ശൂന്യ };
    തിരികെ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC ശൂന്യം vpush_helper_func(പൂർണ്ണസംഖ്യ v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
സ്ഥിതം ശൂന്യം merge_symattr(ഘടന SymAttr *sa, ഘടന SymAttr *sa1)
{
    എങ്കിൽ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    എങ്കിൽ (sa1->visibility != STV_DEFAULT) {
	പൂർണ്ണസംഖ്യ vis = sa->visibility;
	എങ്കിൽ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
സ്ഥിതം ശൂന്യം merge_funcattr(ഘടന FuncAttr *fa, ഘടന FuncAttr *fa1)
{
    എങ്കിൽ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    എങ്കിൽ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    എങ്കിൽ (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    എങ്കിൽ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    എങ്കിൽ (fa1->func_ctor)
      fa->func_ctor = 1;
    എങ്കിൽ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
സ്ഥിതം ശൂന്യം merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    എങ്കിൽ (ad1->section)
      ad->section = ad1->section;
    എങ്കിൽ (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    എങ്കിൽ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    എങ്കിൽ (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
സ്ഥിതം ശൂന്യം patch_type(Sym *sym, CType *type)
{
    എങ്കിൽ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        എങ്കിൽ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ശൂന്യ));
        sym->type.t &= ~VT_EXTERN;
    }

    എങ്കിൽ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        എങ്കിൽ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    എങ്കിൽ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ശൂന്യ));

    } അല്ലെങ്കിൽ എങ്കിൽ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        പൂർണ്ണസംഖ്യ static_proto = sym->type.t & VT_STATIC;
        പൂർണ്ണസംഖ്യ ft1 = sym->type.ref->f.func_type;
        പൂർണ്ണസംഖ്യ ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        എങ്കിൽ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ശൂന്യ));

        /* set 'inline' if both agree or if one has static */
        എങ്കിൽ ((type->t | sym->type.t) & VT_INLINE) {
            എങ്കിൽ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        എങ്കിൽ (0 == (type->t & VT_EXTERN)) {
            ഘടന FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            എങ്കിൽ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } അല്ലെങ്കിൽ {
            sym->type.t &= ~VT_INLINE | static_proto;
            എങ്കിൽ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } അല്ലെങ്കിൽ {
        എങ്കിൽ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        എങ്കിൽ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ശൂന്യ));
    }
}

/* Merge some storage attributes.  */
സ്ഥിതം ശൂന്യം patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    എങ്കിൽ (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    എങ്കിൽ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ശൂന്യ));
#endif
    merge_symattr(&sym->a, &ad->a);
    എങ്കിൽ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
സ്ഥിതം Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    എങ്കിൽ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    തിരികെ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
സ്ഥിതം ശൂന്യം move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    പൂർണ്ണസംഖ്യ n, bt;

    bt = s->type.t & VT_BTYPE;
    എങ്കിൽ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        തിരികെ;

    വേണ്ടി (s = s->type.ref, n = 0; s; s = s->next) {
        വേണ്ടി (lp = &local_അട്ടി; !!(l = *lp); lp = &l->prev) {
            എങ്കിൽ (l == s) {
                *lp = s->prev;
                s->prev = global_അട്ടി, global_അട്ടി = s;
                എങ്കിൽ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } അല്ലെങ്കിൽ {
                    എങ്കിൽ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                എങ്കിൽ (bt != VT_PTR)
                    n = 1;
                നിർത്തുക;
            }
        }
        എങ്കിൽ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            നിർത്തുക;
    }
}

/* define a new external reference to a symbol 'v' */
സ്ഥിതം Sym *external_sym(പൂർണ്ണസംഖ്യ v, CType *type, പൂർണ്ണസംഖ്യ r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    ആകുമ്പോൾ (s && s->sym_scope)
        s = s->prev_tok;

    എങ്കിൽ (!s) {
        /* push forward reference */
        s = global_identifier_തള്ളുക(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } അല്ലെങ്കിൽ {
        patch_storage(s, ad, type);
    }
    എങ്കിൽ (local_അട്ടി) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_അട്ടി);
    }
    തിരികെ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC ശൂന്യം save_regs(പൂർണ്ണസംഖ്യ n)
{
    SValue *p, *p1;
    വേണ്ടി(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC ശൂന്യം save_reg(പൂർണ്ണസംഖ്യ r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC ശൂന്യം save_reg_upstack(പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ n)
{
    പൂർണ്ണസംഖ്യ l, size, align, bt, r2;
    SValue *p, *p1, sv;

    എങ്കിൽ ((r &= VT_VALMASK) >= VT_CONST)
        തിരികെ;
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    l = r2 = 0;
    വേണ്ടി(p = vstack, p1 = vtop - n; p <= p1; p++) {
        എങ്കിൽ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            എങ്കിൽ (!l) {
                bt = p->type.t & VT_BTYPE;
                എങ്കിൽ (bt == VT_VOID)
                    തുടരുക;
                എങ്കിൽ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ശൂന്യ;
                store(p->r & VT_VALMASK, &sv);
#എങ്കിൽ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                എങ്കിൽ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                എങ്കിൽ (p->r2 < VT_CONST && USING_TWO_വാക്കുകൾ(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            എങ്കിൽ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } അല്ലെങ്കിൽ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ശൂന്യ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC പൂർണ്ണസംഖ്യ get_reg_ex(പൂർണ്ണസംഖ്യ rc, പൂർണ്ണസംഖ്യ rc2)
{
    പൂർണ്ണസംഖ്യ r;
    SValue *p;
    
    വേണ്ടി(r=0;r<NB_REGS;r++) {
        എങ്കിൽ (reg_classes[r] & rc2) {
            പൂർണ്ണസംഖ്യ n;
            n=0;
            വേണ്ടി(p = vstack; p <= vtop; p++) {
                എങ്കിൽ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            എങ്കിൽ (n <= 1)
                തിരികെ r;
        }
    }
    തിരികെ get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC പൂർണ്ണസംഖ്യ get_reg(പൂർണ്ണസംഖ്യ rc)
{
    പൂർണ്ണസംഖ്യ r;
    SValue *p;

    /* find a free register */
    വേണ്ടി(r=0;r<NB_REGS;r++) {
        എങ്കിൽ (reg_classes[r] & rc) {
            എങ്കിൽ (nocode_wanted)
                തിരികെ r;
            വേണ്ടി(p=vstack;p<=vtop;p++) {
                എങ്കിൽ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    പോകുക notfound;
            }
            തിരികെ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    വേണ്ടി(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        എങ്കിൽ (r < VT_CONST && (reg_classes[r] & rc))
            പോകുക save_found;
        r = p->r & VT_VALMASK;
        എങ്കിൽ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            തിരികെ r;
        }
    }
    /* Should never comes here */
    തിരികെ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
സ്ഥിതം പൂർണ്ണസംഖ്യ get_temp_local_var(പൂർണ്ണസംഖ്യ size,പൂർണ്ണസംഖ്യ align, പൂർണ്ണസംഖ്യ *r2)
{
    പൂർണ്ണസംഖ്യ i;
    ഘടന temp_local_variable *temp_var;
    SValue *p;
    പൂർണ്ണസംഖ്യ r;
    unsigned used = 0;

    /* mark locations that are still in use */
    വേണ്ടി (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	എങ്കിൽ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    എങ്കിൽ (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_സംഖ്യ)
	        used |= 1<<r;
	}
    }
    വേണ്ടി (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	എങ്കിൽ(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    തിരികെ temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    എങ്കിൽ (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_സംഖ്യ) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	പോകുക ret_tmp;
    }
    *r2 = VT_CONST;
    തിരികെ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
സ്ഥിതം ശൂന്യം move_reg(പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ s, പൂർണ്ണസംഖ്യ t)
{
    SValue sv;

    എങ്കിൽ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ശൂന്യ;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC ശൂന്യം gaddrof(ശൂന്യം)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    എങ്കിൽ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
സ്ഥിതം ശൂന്യം gen_bounded_ptr_add(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    എങ്കിൽ (save) {
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
    എങ്കിൽ (nocode_wanted)
        തിരികെ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - വലുപ്പം(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
സ്ഥിതം ശൂന്യം gen_bounded_ptr_deref(ശൂന്യം)
{
    addr_t func;
    പൂർണ്ണസംഖ്യ size, align;
    ElfW_Rel *rel;
    Sym *sym;

    എങ്കിൽ (nocode_wanted)
        തിരികെ;

    size = type_size(&vtop->type, &align);
    തിരഞ്ഞെടുപ്പ്(size) {
    അവസ്ഥ  1: func = TOK___bound_ptr_indir1; നിർത്തുക;
    അവസ്ഥ  2: func = TOK___bound_ptr_indir2; നിർത്തുക;
    അവസ്ഥ  4: func = TOK___bound_ptr_indir4; നിർത്തുക;
    അവസ്ഥ  8: func = TOK___bound_ptr_indir8; നിർത്തുക;
    അവസ്ഥ 12: func = TOK___bound_ptr_indir12; നിർത്തുക;
    അവസ്ഥ 16: func = TOK___bound_ptr_indir16; നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        /* may happen with struct member access */
        തിരികെ;
    }
    sym = external_helper_sym(func);
    എങ്കിൽ (!sym->c)
        put_extern_sym(sym, ശൂന്യ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
സ്ഥിതം ശൂന്യം gbound(ശൂന്യം)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    എങ്കിൽ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        എങ്കിൽ (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC ശൂന്യം gbound_args(പൂർണ്ണസംഖ്യ nb_args)
{
    പൂർണ്ണസംഖ്യ i, v;
    SValue *sv;

    വേണ്ടി (i = 1; i <= nb_args; ++i)
        എങ്കിൽ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    എങ്കിൽ (sv->r & VT_SYM) {
        v = sv->sym->v;
        എങ്കിൽ (v == TOK_setjmp
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
        എങ്കിൽ (v == TOK_alloca)
            func_bound_add_epilog = 1;
#എങ്കിൽ TARGETOS_NetBSD
        എങ്കിൽ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
സ്ഥിതം ശൂന്യം add_local_bounds(Sym *s, Sym *e)
{
    വേണ്ടി (; s != e; s = s->prev) {
        എങ്കിൽ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          തുടരുക;
        /* Add arrays/structs/unions because we always take address */
        എങ്കിൽ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            പൂർണ്ണസംഖ്യ align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * വലുപ്പം(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
സ്ഥിതം ശൂന്യം tcc_debug_end_scope(Sym *b, പൂർണ്ണസംഖ്യ bounds)
{
#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_അട്ടി, b);
#endif
    tcc_add_debug_info (tcc_state, local_അട്ടി, b);
}

/* increment an lvalue pointer */
സ്ഥിതം ശൂന്യം incr_offset(പൂർണ്ണസംഖ്യ offset)
{
    പൂർണ്ണസംഖ്യ t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

സ്ഥിതം ശൂന്യം incr_bf_adr(പൂർണ്ണസംഖ്യ o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
സ്ഥിതം ശൂന്യം load_packed_bf(CType *type, പൂർണ്ണസംഖ്യ bit_pos, പൂർണ്ണസംഖ്യ bit_size)
{
    പൂർണ്ണസംഖ്യ n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    ചെയ്യുക {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        എങ്കിൽ (n > bit_size)
            n = bit_size;
        എങ്കിൽ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        എങ്കിൽ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        എങ്കിൽ (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } ആകുമ്പോൾ (bit_size);
    vswap(), vpop();
    എങ്കിൽ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
സ്ഥിതം ശൂന്യം store_packed_bf(പൂർണ്ണസംഖ്യ bit_pos, പൂർണ്ണസംഖ്യ bit_size)
{
    പൂർണ്ണസംഖ്യ bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    ചെയ്യുക {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        എങ്കിൽ (bits)
            vpushi(bits), gen_op(TOK_SHR);
        എങ്കിൽ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        എങ്കിൽ (n > bit_size)
            n = bit_size;
        എങ്കിൽ (n < 8) {
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
    } ആകുമ്പോൾ (bit_size);
    vpop(), vpop();
}

സ്ഥിതം പൂർണ്ണസംഖ്യ adjust_bf(SValue *sv, പൂർണ്ണസംഖ്യ bit_pos, പൂർണ്ണസംഖ്യ bit_size)
{
    പൂർണ്ണസംഖ്യ t;
    എങ്കിൽ (0 == sv->type.ref)
        തിരികെ 0;
    t = sv->type.ref->auxtype;
    എങ്കിൽ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    തിരികെ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC പൂർണ്ണസംഖ്യ gv(പൂർണ്ണസംഖ്യ rc)
{
    പൂർണ്ണസംഖ്യ r, r2, r_ok, r2_ok, rc2, bt;
    പൂർണ്ണസംഖ്യ bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    എങ്കിൽ (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = ശൂന്യ;
        type.t = vtop->type.t & VT_UNSIGNED;
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        അല്ലെങ്കിൽ
            type.t |= VT_INT;

        എങ്കിൽ (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } അല്ലെങ്കിൽ {
            പൂർണ്ണസംഖ്യ bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            എങ്കിൽ (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        എങ്കിൽ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            തിരികെ vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        എങ്കിൽ (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        എങ്കിൽ (!r_ok || !r2_ok) {

            എങ്കിൽ (!r_ok) {
                എങ്കിൽ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                അല്ലെങ്കിൽ
                    r = get_reg(rc);
            }

            എങ്കിൽ (rc2) {
                പൂർണ്ണസംഖ്യ load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                പൂർണ്ണസംഖ്യ original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } അല്ലെങ്കിൽ എങ്കിൽ (vtop->r & VT_LVAL) {
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
                } അല്ലെങ്കിൽ {
                    /* move registers */
                    എങ്കിൽ (!r_ok)
                        load(r, vtop);
                    എങ്കിൽ (r2_ok && vtop->r2 < VT_CONST)
                        പോകുക done;
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
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        എങ്കിൽ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    തിരികെ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC ശൂന്യം gv2(പൂർണ്ണസംഖ്യ rc1, പൂർണ്ണസംഖ്യ rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    എങ്കിൽ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        എങ്കിൽ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } അല്ലെങ്കിൽ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        എങ്കിൽ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#എങ്കിൽ PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC ശൂന്യം lexpand(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    എങ്കിൽ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } അല്ലെങ്കിൽ എങ്കിൽ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } അല്ലെങ്കിൽ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#എങ്കിൽ PTR_SIZE == 4
/* build a long long from two ints */
സ്ഥിതം ശൂന്യം lbuild(പൂർണ്ണസംഖ്യ t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
സ്ഥിതം ശൂന്യം gv_dup(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t, rc, r;

    t = vtop->type.t;
#എങ്കിൽ PTR_SIZE == 4
    എങ്കിൽ ((t & VT_BTYPE) == VT_LLONG) {
        എങ്കിൽ (t & VT_BITFIELD) {
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
        തിരികെ;
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

#എങ്കിൽ PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
സ്ഥിതം ശൂന്യം gen_opl(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ t, a, b, op1, c, i;
    പൂർണ്ണസംഖ്യ func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    തിരഞ്ഞെടുപ്പ്(op) {
    അവസ്ഥ '/':
    അവസ്ഥ TOK_PDIV:
        func = TOK___divdi3;
        പോകുക gen_func;
    അവസ്ഥ TOK_UDIV:
        func = TOK___udivdi3;
        പോകുക gen_func;
    അവസ്ഥ '%':
        func = TOK___moddi3;
        പോകുക gen_mod_func;
    അവസ്ഥ TOK_UMOD:
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
        നിർത്തുക;
    അവസ്ഥ '^':
    അവസ്ഥ '&':
    അവസ്ഥ '|':
    അവസ്ഥ '*':
    അവസ്ഥ '+':
    അവസ്ഥ '-':
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
        എങ്കിൽ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            വേണ്ടി(i=0;i<4;i++)
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
        } അല്ലെങ്കിൽ എങ്കിൽ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            എങ്കിൽ (op == '+')
                op1 = TOK_ADDC1;
            അല്ലെങ്കിൽ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } അല്ലെങ്കിൽ {
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
        നിർത്തുക;
    അവസ്ഥ TOK_SAR:
    അവസ്ഥ TOK_SHR:
    അവസ്ഥ TOK_SHL:
        എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (പൂർണ്ണസംഖ്യ)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            എങ്കിൽ (op != TOK_SHL)
                vswap();
            എങ്കിൽ (c >= 32) {
                /* stack: L H */
                vpop();
                എങ്കിൽ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                എങ്കിൽ (op != TOK_SAR) {
                    vpushi(0);
                } അല്ലെങ്കിൽ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } അല്ലെങ്കിൽ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                എങ്കിൽ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                അല്ലെങ്കിൽ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                എങ്കിൽ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                അല്ലെങ്കിൽ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            എങ്കിൽ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } അല്ലെങ്കിൽ {
            /* XXX: should provide a faster fallback on x86 ? */
            തിരഞ്ഞെടുപ്പ്(op) {
            അവസ്ഥ TOK_SAR:
                func = TOK___ashrdi3;
                പോകുക gen_func;
            അവസ്ഥ TOK_SHR:
                func = TOK___lshrdi3;
                പോകുക gen_func;
            അവസ്ഥ TOK_SHL:
                func = TOK___ashldi3;
                പോകുക gen_func;
            }
        }
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
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
        എങ്കിൽ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        എങ്കിൽ (op1 == TOK_LT)
            op1 = TOK_LE;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_GT)
            op1 = TOK_GE;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        എങ്കിൽ (op == TOK_NE) {
            b = gvtst(0, 0);
        } അല്ലെങ്കിൽ {
            a = gvtst(1, 0);
            എങ്കിൽ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        എങ്കിൽ (op1 == TOK_LT)
            op1 = TOK_ULT;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_LE)
            op1 = TOK_ULE;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_GT)
            op1 = TOK_UGT;
        അല്ലെങ്കിൽ എങ്കിൽ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#എങ്കിൽ 0//def TCC_TARGET_I386
        എങ്കിൽ (op == TOK_NE) { gsym(b); നിർത്തുക; }
        എങ്കിൽ (op == TOK_EQ) { gsym(a); നിർത്തുക; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        നിർത്തുക;
    }
}
#endif

/* normalize values */
സ്ഥിതം uint64_t value64(uint64_t l1, പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        തിരികെ l1;
    അല്ലെങ്കിൽ എങ്കിൽ (t & VT_UNSIGNED)
        തിരികെ (uint32_t)l1;
    അല്ലെങ്കിൽ
        തിരികെ (uint32_t)l1 | -(l1 & 0x80000000);
}

സ്ഥിതം uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    തിരികെ (a ^ b) >> 63 ? -x : x;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ gen_opic_lt(uint64_t a, uint64_t b)
{
    തിരികെ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
സ്ഥിതം ശൂന്യം gen_opic(പൂർണ്ണസംഖ്യ op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    പൂർണ്ണസംഖ്യ t1 = v1->type.t & VT_BTYPE;
    പൂർണ്ണസംഖ്യ t2 = v2->type.t & VT_BTYPE;
    പൂർണ്ണസംഖ്യ c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    പൂർണ്ണസംഖ്യ c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    പൂർണ്ണസംഖ്യ shm = (t1 == VT_LLONG) ? 63 : 31;
    പൂർണ്ണസംഖ്യ r;

    എങ്കിൽ (c1 && c2) {
        തിരഞ്ഞെടുപ്പ്(op) {
        അവസ്ഥ '+': l1 += l2; നിർത്തുക;
        അവസ്ഥ '-': l1 -= l2; നിർത്തുക;
        അവസ്ഥ '&': l1 &= l2; നിർത്തുക;
        അവസ്ഥ '^': l1 ^= l2; നിർത്തുക;
        അവസ്ഥ '|': l1 |= l2; നിർത്തുക;
        അവസ്ഥ '*': l1 *= l2; നിർത്തുക;

        അവസ്ഥ TOK_PDIV:
        അവസ്ഥ '/':
        അവസ്ഥ '%':
        അവസ്ഥ TOK_UDIV:
        അവസ്ഥ TOK_UMOD:
            /* if division by zero, generate explicit division */
            എങ്കിൽ (l2 == 0) {
                എങ്കിൽ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                പോകുക general_case;
            }
            തിരഞ്ഞെടുപ്പ്(op) {
            സ്ഥിരസ്ഥിതി: l1 = gen_opic_sdiv(l1, l2); നിർത്തുക;
            അവസ്ഥ '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); നിർത്തുക;
            അവസ്ഥ TOK_UDIV: l1 = l1 / l2; നിർത്തുക;
            അവസ്ഥ TOK_UMOD: l1 = l1 % l2; നിർത്തുക;
            }
            നിർത്തുക;
        അവസ്ഥ TOK_SHL: l1 <<= (l2 & shm); നിർത്തുക;
        അവസ്ഥ TOK_SHR: l1 >>= (l2 & shm); നിർത്തുക;
        അവസ്ഥ TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            നിർത്തുക;
            /* tests */
        അവസ്ഥ TOK_ULT: l1 = l1 < l2; നിർത്തുക;
        അവസ്ഥ TOK_UGE: l1 = l1 >= l2; നിർത്തുക;
        അവസ്ഥ TOK_EQ: l1 = l1 == l2; നിർത്തുക;
        അവസ്ഥ TOK_NE: l1 = l1 != l2; നിർത്തുക;
        അവസ്ഥ TOK_ULE: l1 = l1 <= l2; നിർത്തുക;
        അവസ്ഥ TOK_UGT: l1 = l1 > l2; നിർത്തുക;
        അവസ്ഥ TOK_LT: l1 = gen_opic_lt(l1, l2); നിർത്തുക;
        അവസ്ഥ TOK_GE: l1 = !gen_opic_lt(l1, l2); നിർത്തുക;
        അവസ്ഥ TOK_LE: l1 = !gen_opic_lt(l2, l1); നിർത്തുക;
        അവസ്ഥ TOK_GT: l1 = gen_opic_lt(l2, l1); നിർത്തുക;
            /* logical */
        അവസ്ഥ TOK_LAND: l1 = l1 && l2; നിർത്തുക;
        അവസ്ഥ TOK_LOR: l1 = l1 || l2; നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            പോകുക general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } അല്ലെങ്കിൽ {
        /* if commutative ops, put c2 as constant */
        എങ്കിൽ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        എങ്കിൽ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } അല്ലെങ്കിൽ എങ്കിൽ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            എങ്കിൽ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } അല്ലെങ്കിൽ എങ്കിൽ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } അല്ലെങ്കിൽ എങ്കിൽ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            എങ്കിൽ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                പൂർണ്ണസംഖ്യ n = -1;
                എങ്കിൽ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    പോകുക general_case;
                }
                ആകുമ്പോൾ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                എങ്കിൽ (op == '*')
                    op = TOK_SHL;
                അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_PDIV)
                    op = TOK_SAR;
                അല്ലെങ്കിൽ
                    op = TOK_SHR;
            }
            പോകുക general_case;
        } അല്ലെങ്കിൽ എങ്കിൽ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            എങ്കിൽ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    എങ്കിൽ ((പൂർണ്ണസംഖ്യ)l2 != l2)
	        പോകുക general_case;
            vtop--;
            vtop->c.i = l2;
        } അല്ലെങ്കിൽ {
        general_case:
                /* call low level op generator */
                എങ്കിൽ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                അല്ലെങ്കിൽ
                    gen_opi(op);
        }
        എങ്കിൽ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#എങ്കിൽ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
ശൂന്യം gen_negf(പൂർണ്ണസംഖ്യ op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#അല്ലെങ്കിൽ
/* XXX: implement in gen_opf() for other backends too */
ശൂന്യം gen_negf(പൂർണ്ണസംഖ്യ op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    പൂർണ്ണസംഖ്യ align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#എങ്കിൽ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    എങ്കിൽ (bt == VT_LDOUBLE)
        size = 10;
#endif
    എങ്കിൽ (nocode_wanted) /* save_reg() wont work */
        പോകുക gv2;
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
സ്ഥിതം ശൂന്യം gen_opif(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ c1, c2, i, bt;
    SValue *v1, *v2;
#എങ്കിൽ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    അസ്ഥിര
#endif
    long ഇരട്ട f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    എങ്കിൽ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    എങ്കിൽ (c1 && c2) {
        എങ്കിൽ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } അല്ലെങ്കിൽ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        എങ്കിൽ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            പോകുക general_case;
        തിരഞ്ഞെടുപ്പ്(op) {
        അവസ്ഥ '+': f1 += f2; നിർത്തുക;
        അവസ്ഥ '-': f1 -= f2; നിർത്തുക;
        അവസ്ഥ '*': f1 *= f2; നിർത്തുക;
        അവസ്ഥ '/': 
            എങ്കിൽ (f2 == 0.0) {
                സംഘം { ദശാംശം f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                എങ്കിൽ (!CONST_WANTED)
                    പോകുക general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                എങ്കിൽ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                അല്ലെങ്കിൽ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                നിർത്തുക;
            }
            f1 /= f2;
            നിർത്തുക;
        അവസ്ഥ TOK_NEG:
            f1 = -f1;
            പോകുക unary_result;
        അവസ്ഥ TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            തിരികെ;
        അവസ്ഥ TOK_NE:
            i = f1 != f2;
	    പോകുക make_int;
        അവസ്ഥ TOK_LT:
            i = f1 < f2;
	    പോകുക make_int;
        അവസ്ഥ TOK_GE:
            i = f1 >= f2;
	    പോകുക make_int;
        അവസ്ഥ TOK_LE:
            i = f1 <= f2;
	    പോകുക make_int;
        അവസ്ഥ TOK_GT:
            i = f1 > f2;
	    പോകുക make_int;
        സ്ഥിരസ്ഥിതി:
            പോകുക general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        എങ്കിൽ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } അല്ലെങ്കിൽ {
            v1->c.ld = f1;
        }
    } അല്ലെങ്കിൽ {
    general_case:
        എങ്കിൽ (op == TOK_NEG) {
            gen_negf(op);
        } അല്ലെങ്കിൽ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
സ്ഥിതം ശൂന്യം type_to_str(അക്ഷരം *buf, പൂർണ്ണസംഖ്യ buf_size,
                 CType *type, സ്ഥിരം അക്ഷരം *varstr)
{
    പൂർണ്ണസംഖ്യ bt, v, t;
    Sym *s, *sa;
    അക്ഷരം buf1[256];
    സ്ഥിരം അക്ഷരം *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    എങ്കിൽ (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    എങ്കിൽ (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    എങ്കിൽ (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    എങ്കിൽ (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    എങ്കിൽ (bt != VT_PTR) {
        എങ്കിൽ (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        എങ്കിൽ (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        എങ്കിൽ (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    എങ്കിൽ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    തിരഞ്ഞെടുപ്പ്(bt) {
    അവസ്ഥ VT_VOID:
        tstr = "void";
        പോകുക add_tstr;
    അവസ്ഥ VT_BOOL:
        tstr = "_Bool";
        പോകുക add_tstr;
    അവസ്ഥ VT_BYTE:
        tstr = "char";
        പോകുക add_tstr;
    അവസ്ഥ VT_SHORT:
        tstr = "short";
        പോകുക add_tstr;
    അവസ്ഥ VT_INT:
        tstr = "int";
        പോകുക maybe_long;
    അവസ്ഥ VT_LLONG:
        tstr = "long long";
    maybe_long:
        എങ്കിൽ (t & VT_LONG)
            tstr = "long";
        എങ്കിൽ (!IS_ENUM(t))
            പോകുക add_tstr;
        tstr = "enum ";
        പോകുക tstruct;
    അവസ്ഥ VT_FLOAT:
        tstr = "float";
        പോകുക add_tstr;
    അവസ്ഥ VT_DOUBLE:
        tstr = "double";
        എങ്കിൽ (!(t & VT_LONG))
            പോകുക add_tstr;
    അവസ്ഥ VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        നിർത്തുക;
    അവസ്ഥ VT_STRUCT:
        tstr = "struct ";
        എങ്കിൽ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        എങ്കിൽ (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        അല്ലെങ്കിൽ
            pstrcat(buf, buf_size, get_tok_str(v, ശൂന്യ));
        നിർത്തുക;
    അവസ്ഥ VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        എങ്കിൽ (varstr && '*' == *varstr) {
            pstrcat(buf1, വലുപ്പം(buf1), "(");
            pstrcat(buf1, വലുപ്പം(buf1), varstr);
            pstrcat(buf1, വലുപ്പം(buf1), ")");
        }
        pstrcat(buf1, വലുപ്പം(buf1), "(");
        sa = s->next;
        ആകുമ്പോൾ (sa != ശൂന്യ) {
            അക്ഷരം buf2[256];
            type_to_str(buf2, വലുപ്പം(buf2), &sa->type, ശൂന്യ);
            pstrcat(buf1, വലുപ്പം(buf1), buf2);
            sa = sa->next;
            എങ്കിൽ (sa)
                pstrcat(buf1, വലുപ്പം(buf1), ", ");
        }
        എങ്കിൽ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, വലുപ്പം(buf1), ", ...");
        pstrcat(buf1, വലുപ്പം(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        പോകുക no_var;
    അവസ്ഥ VT_PTR:
        s = type->ref;
        എങ്കിൽ (t & (VT_ARRAY|VT_VLA)) {
            എങ്കിൽ (varstr && '*' == *varstr)
                snprintf(buf1, വലുപ്പം(buf1), "(%s)[%d]", varstr, s->c);
            അല്ലെങ്കിൽ
                snprintf(buf1, വലുപ്പം(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            പോകുക no_var;
        }
        pstrcpy(buf1, വലുപ്പം(buf1), "*");
        എങ്കിൽ (t & VT_RESTRICT)
            pstrcat(buf1, വലുപ്പം(buf1), "restrict ");
        എങ്കിൽ (t & VT_CONSTANT)
            pstrcat(buf1, വലുപ്പം(buf1), "const ");
        എങ്കിൽ (t & VT_VOLATILE)
            pstrcat(buf1, വലുപ്പം(buf1), "volatile ");
        എങ്കിൽ (varstr)
            pstrcat(buf1, വലുപ്പം(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        പോകുക no_var;
    }
    എങ്കിൽ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

സ്ഥിതം ശൂന്യം type_incompatibility_error(CType* st, CType* dt, സ്ഥിരം അക്ഷരം* fmt)
{
    അക്ഷരം buf1[256], buf2[256];
    type_to_str(buf1, വലുപ്പം(buf1), st, ശൂന്യ);
    type_to_str(buf2, വലുപ്പം(buf2), dt, ശൂന്യ);
    tcc_error(fmt, buf1, buf2);
}

സ്ഥിതം ശൂന്യം type_incompatibility_warning(CType* st, CType* dt, സ്ഥിരം അക്ഷരം* fmt)
{
    അക്ഷരം buf1[256], buf2[256];
    type_to_str(buf1, വലുപ്പം(buf1), st, ശൂന്യ);
    type_to_str(buf2, വലുപ്പം(buf2), dt, ശൂന്യ);
    tcc_warning(fmt, buf1, buf2);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ pointed_size(CType *type)
{
    പൂർണ്ണസംഖ്യ align;
    തിരികെ type_size(pointed_type(type), &align);
}

സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ is_null_pointer(SValue *p)
{
    എങ്കിൽ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        തിരികെ 0;
    തിരികെ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
സ്ഥിതം പൂർണ്ണസംഖ്യ is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    എങ്കിൽ (s1->f.func_call != s2->f.func_call)
        തിരികെ 0;
    എങ്കിൽ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        തിരികെ 0;
    വേണ്ടി (;;) {
        എങ്കിൽ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            തിരികെ 0;
        എങ്കിൽ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            തിരികെ 1;
        s1 = s1->next;
        s2 = s2->next;
        എങ്കിൽ (!s1)
            തിരികെ !s2;
        എങ്കിൽ (!s2)
            തിരികെ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
സ്ഥിതം പൂർണ്ണസംഖ്യ compare_types(CType *type1, CType *type2, പൂർണ്ണസംഖ്യ unqualified)
{
    പൂർണ്ണസംഖ്യ bt1, t1, t2;

    എങ്കിൽ (IS_ENUM(type1->t)) {
        എങ്കിൽ (IS_ENUM(type2->t))
            തിരികെ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } അല്ലെങ്കിൽ എങ്കിൽ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    എങ്കിൽ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    എങ്കിൽ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    എങ്കിൽ (t1 != t2)
        തിരികെ 0;

    എങ്കിൽ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            തിരികെ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    എങ്കിൽ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        എങ്കിൽ (unqualified && (t1 & VT_ARRAY))
            തിരികെ compare_types(type1, type2, 1);
        തിരികെ is_compatible_types(type1, type2);
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_STRUCT) {
        തിരികെ (type1->ref == type2->ref);
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_FUNC) {
        തിരികെ is_compatible_func(type1, type2);
    } അല്ലെങ്കിൽ {
        തിരികെ 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
സ്ഥിതം പൂർണ്ണസംഖ്യ combine_types(CType *dest, SValue *op1, SValue *op2, പൂർണ്ണസംഖ്യ op)
{
    CType *type1, *type2, type;
    പൂർണ്ണസംഖ്യ t1, t2, bt1, bt2;
    പൂർണ്ണസംഖ്യ ret = 1;

    /* for shifts, 'combine' only left operand */
    എങ്കിൽ (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ശൂന്യ;

    എങ്കിൽ (bt1 == VT_VOID || bt2 == VT_VOID) {
        എങ്കിൽ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_PTR || bt2 == VT_PTR) {
        എങ്കിൽ (op == '+') {
          എങ്കിൽ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        അല്ലെങ്കിൽ എങ്കിൽ (is_null_pointer (op2)) type = *type1;
        അല്ലെങ്കിൽ എങ്കിൽ (is_null_pointer (op1)) type = *type2;
        അല്ലെങ്കിൽ എങ്കിൽ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            എങ്കിൽ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            അല്ലെങ്കിൽ എങ്കിൽ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } അല്ലെങ്കിൽ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            പൂർണ്ണസംഖ്യ pbt1 = pt1->t & VT_BTYPE;
            പൂർണ്ണസംഖ്യ pbt2 = pt2->t & VT_BTYPE;
            പൂർണ്ണസംഖ്യ newquals, copied = 0;
            എങ്കിൽ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                എങ്കിൽ (op != '?' && op != CMP_OP)
                  ret = 0;
                അല്ലെങ്കിൽ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            എങ്കിൽ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                എങ്കിൽ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_തള്ളുക(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                എങ്കിൽ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    എങ്കിൽ (!copied)
                      type.ref = sym_തള്ളുക(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_തള്ളുക(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        എങ്കിൽ (op == CMP_OP)
          type.t = VT_SIZE_T;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        എങ്കിൽ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } അല്ലെങ്കിൽ എങ്കിൽ (is_float(bt1) || is_float(bt2)) {
        എങ്കിൽ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } അല്ലെങ്കിൽ {
            type.t = VT_FLOAT;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        എങ്കിൽ (bt1 == VT_LLONG)
          type.t &= t1;
        എങ്കിൽ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        എങ്കിൽ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } അല്ലെങ്കിൽ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        എങ്കിൽ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    എങ്കിൽ (dest)
      *dest = type;
    തിരികെ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC ശൂന്യം gen_op(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ t1, t2, bt1, bt2, t;
    CType type1, combtype;
    പൂർണ്ണസംഖ്യ op_class = op;

    എങ്കിൽ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    അല്ലെങ്കിൽ എങ്കിൽ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    എങ്കിൽ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	എങ്കിൽ (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	എങ്കിൽ (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	പോകുക redo;
    } അല്ലെങ്കിൽ എങ്കിൽ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } അല്ലെങ്കിൽ എങ്കിൽ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        പൂർണ്ണസംഖ്യ align;
        എങ്കിൽ (op_class == CMP_OP)
            പോകുക std_op;
        /* if both pointers, then it must be the '-' op */
        എങ്കിൽ (bt1 == VT_PTR && bt2 == VT_PTR) {
            എങ്കിൽ (op != '-')
                പോകുക op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } അല്ലെങ്കിൽ {
            /* exactly one pointer : must be '+' or '-'. */
            എങ്കിൽ (op != '-' && op != '+')
                പോകുക op_err;
            /* Put pointer as first operand */
            എങ്കിൽ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#എങ്കിൽ PTR_SIZE == 4
            എങ്കിൽ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            എങ്കിൽ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                എങ്കിൽ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } അല്ലെങ്കിൽ
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } അല്ലെങ്കിൽ {
        /* floats can only be used for a few operations */
        എങ്കിൽ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            പോകുക op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        എങ്കിൽ (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        എങ്കിൽ (t & VT_UNSIGNED) {
            എങ്കിൽ (op == TOK_SAR)
                op = TOK_SHR;
            അല്ലെങ്കിൽ എങ്കിൽ (op == '/')
                op = TOK_UDIV;
            അല്ലെങ്കിൽ എങ്കിൽ (op == '%')
                op = TOK_UMOD;
            അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_LT)
                op = TOK_ULT;
            അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_GT)
                op = TOK_UGT;
            അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_LE)
                op = TOK_ULE;
            അല്ലെങ്കിൽ എങ്കിൽ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        എങ്കിൽ (is_float(t))
            gen_opif(op);
        അല്ലെങ്കിൽ
            gen_opic(op);
        എങ്കിൽ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } അല്ലെങ്കിൽ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    എങ്കിൽ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#എങ്കിൽ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#അല്ലെങ്കിൽ
/* generic itof for unsigned long long case */
സ്ഥിതം ശൂന്യം gen_cvt_itof1(പൂർണ്ണസംഖ്യ t)
{
    എങ്കിൽ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        എങ്കിൽ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#എങ്കിൽ LDOUBLE_SIZE != 8
        അല്ലെങ്കിൽ എങ്കിൽ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        അല്ലെങ്കിൽ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } അല്ലെങ്കിൽ {
        gen_cvt_itof(t);
    }
}
#endif

#എങ്കിൽ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#അല്ലെങ്കിൽ
/* generic ftoi for unsigned long long case */
സ്ഥിതം ശൂന്യം gen_cvt_ftoi1(പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ st;
    എങ്കിൽ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        എങ്കിൽ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#എങ്കിൽ LDOUBLE_SIZE != 8
        അല്ലെങ്കിൽ എങ്കിൽ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        അല്ലെങ്കിൽ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } അല്ലെങ്കിൽ {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
സ്ഥിതം ശൂന്യം force_charshort_cast(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    പൂർണ്ണസംഖ്യ dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

സ്ഥിതം ശൂന്യം gen_cast_s(പൂർണ്ണസംഖ്യ t)
{
    CType type;
    type.t = t;
    type.ref = ശൂന്യ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
സ്ഥിതം ശൂന്യം gen_cast(CType *type)
{
    പൂർണ്ണസംഖ്യ sbt, dbt, sf, df, c;
    പൂർണ്ണസംഖ്യ dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    എങ്കിൽ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    എങ്കിൽ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    എങ്കിൽ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    എങ്കിൽ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    എങ്കിൽ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        എങ്കിൽ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            പോകുക done;
        }
        എങ്കിൽ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        എങ്കിൽ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            എങ്കിൽ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            അല്ലെങ്കിൽ എങ്കിൽ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            എങ്കിൽ (df) {
                എങ്കിൽ (sbt_bt == VT_LLONG) {
                    എങ്കിൽ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    അല്ലെങ്കിൽ
                        vtop->c.ld = -(long ഇരട്ട)-vtop->c.i;
                } അല്ലെങ്കിൽ എങ്കിൽ(!sf) {
                    എങ്കിൽ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    അല്ലെങ്കിൽ
                        vtop->c.ld = -(long ഇരട്ട)-(uint32_t)vtop->c.i;
                }

                എങ്കിൽ (dbt == VT_FLOAT)
                    vtop->c.f = (ദശാംശം)vtop->c.ld;
                അല്ലെങ്കിൽ എങ്കിൽ (dbt == VT_DOUBLE)
                    vtop->c.d = (ഇരട്ട)vtop->c.ld;
            } അല്ലെങ്കിൽ എങ്കിൽ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } അല്ലെങ്കിൽ {
                എങ്കിൽ(sf) {
                    എങ്കിൽ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    അല്ലെങ്കിൽ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                അല്ലെങ്കിൽ എങ്കിൽ (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                അല്ലെങ്കിൽ എങ്കിൽ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                അല്ലെങ്കിൽ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                എങ്കിൽ (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                അല്ലെങ്കിൽ എങ്കിൽ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                അല്ലെങ്കിൽ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    എങ്കിൽ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            പോകുക done;

        } അല്ലെങ്കിൽ എങ്കിൽ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            പോകുക done;
        }

        /* cannot generate code for global or static initializers */
        എങ്കിൽ (nocode_wanted & DATA_ONLY_WANTED) {
            എങ്കിൽ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            പോകുക done;
        }

        /* non constant case: generate code */
        എങ്കിൽ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            പോകുക done;
        }

        എങ്കിൽ (sf || df) {
            എങ്കിൽ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } അല്ലെങ്കിൽ എങ്കിൽ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } അല്ലെങ്കിൽ {
                /* convert fp to int */
                sbt = dbt;
                എങ്കിൽ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                പോകുക again; /* may need char/short cast */
            }
            പോകുക done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        എങ്കിൽ (ds == 0 || ss == 0)
            പോകുക error;

        /* same size and no sign conversion needed */
        എങ്കിൽ (ds == ss && ds >= 4)
            പോകുക done;
        എങ്കിൽ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            എങ്കിൽ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        എങ്കിൽ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            എങ്കിൽ (ds <= ss)
                പോകുക done;
            /* ss <= 4 here */
            എങ്കിൽ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                പോകുക done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#എങ്കിൽ PTR_SIZE == 4
        എങ്കിൽ (ds == 8) {
            /* generate high word */
            എങ്കിൽ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } അല്ലെങ്കിൽ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } അല്ലെങ്കിൽ എങ്കിൽ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#അല്ലെങ്കിലെങ്കിൽ PTR_SIZE == 8
        എങ്കിൽ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            എങ്കിൽ (sbt & VT_UNSIGNED) {
#എങ്കിൽ defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#അല്ലെങ്കിൽ
                പോകുക done;
#endif
            } അല്ലെങ്കിൽ {
                gen_cvt_sxtw();
                പോകുക done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } അല്ലെങ്കിൽ എങ്കിൽ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#എങ്കിൽ !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } അല്ലെങ്കിൽ {
            ss = 4;
        }
#endif

        എങ്കിൽ (ds >= ss)
            പോകുക done;
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    എങ്കിൽ (ss == 4) {
        gen_cvt_csti(dbt);
        പോകുക done;
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
ST_FUNC പൂർണ്ണസംഖ്യ type_size(CType *type, പൂർണ്ണസംഖ്യ *a)
{
    Sym *s;
    പൂർണ്ണസംഖ്യ bt;

    bt = type->t & VT_BTYPE;
    എങ്കിൽ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        തിരികെ s->c;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_PTR) {
        എങ്കിൽ (type->t & VT_ARRAY) {
            പൂർണ്ണസംഖ്യ ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            എങ്കിൽ (s->c < 0)
                തിരികെ s->c;
            തിരികെ ts * s->c;
        } അല്ലെങ്കിൽ {
            *a = PTR_SIZE;
            തിരികെ PTR_SIZE;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        തിരികെ -1; /* incomplete enum */
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        തിരികെ LDOUBLE_SIZE;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_DOUBLE || bt == VT_LLONG) {
#എങ്കിൽ (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#അല്ലെങ്കിൽ
        *a = 8;
#endif
        തിരികെ 8;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        തിരികെ 4;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_SHORT) {
        *a = 2;
        തിരികെ 2;
    } അല്ലെങ്കിൽ എങ്കിൽ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        തിരികെ 16;
    } അല്ലെങ്കിൽ {
        /* char, void, function, _Bool */
        *a = 1;
        തിരികെ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
സ്ഥിതം ശൂന്യം vpush_type_size(CType *type, പൂർണ്ണസംഖ്യ *a)
{
    എങ്കിൽ (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } അല്ലെങ്കിൽ {
        പൂർണ്ണസംഖ്യ size = type_size(type, a);
        എങ്കിൽ (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
സ്ഥിതം വരിയിൽ CType *pointed_type(CType *type)
{
    തിരികെ &type->ref->type;
}

സ്ഥിതം ശൂന്യം check_restrict_type(CType *type)
{
    ആകുമ്പോൾ ((type->t & VT_BTYPE) == VT_PTR) {
        എങ്കിൽ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    എങ്കിൽ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
സ്ഥിതം പൂർണ്ണസംഖ്യ type_qualifiers(CType *type)
{
    ആകുമ്പോൾ (type->t & VT_ARRAY)
        type = pointed_type(type);
    തിരികെ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC ശൂന്യം mk_pointer(CType *type)
{
    Sym *s;
    s = sym_തള്ളുക(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
സ്ഥിതം പൂർണ്ണസംഖ്യ is_compatible_types(CType *type1, CType *type2)
{
    തിരികെ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
സ്ഥിതം പൂർണ്ണസംഖ്യ is_compatible_unqualified_types(CType *type1, CType *type2)
{
    തിരികെ compare_types(type1,type2,1);
}

സ്ഥിതം ശൂന്യം cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
സ്ഥിതം ശൂന്യം verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    പൂർണ്ണസംഖ്യ dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    എങ്കിൽ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    തിരഞ്ഞെടുപ്പ്(dbt) {
    അവസ്ഥ VT_VOID:
        എങ്കിൽ (sbt != dbt)
            tcc_error("assignment to void expression");
        നിർത്തുക;
    അവസ്ഥ VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        എങ്കിൽ (is_null_pointer(vtop))
            നിർത്തുക;
        /* accept implicit pointer to integer cast with warning */
        എങ്കിൽ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            നിർത്തുക;
        }
        type1 = pointed_type(dt);
        എങ്കിൽ (sbt == VT_PTR)
            type2 = pointed_type(st);
        അല്ലെങ്കിൽ എങ്കിൽ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        അല്ലെങ്കിൽ
            പോകുക error;
        എങ്കിൽ (is_compatible_types(type1, type2))
            നിർത്തുക;
        വേണ്ടി (qualwarn = lvl = 0;; ++lvl) {
            എങ്കിൽ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            എങ്കിൽ (dbt != VT_PTR || sbt != VT_PTR)
                നിർത്തുക;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        എങ്കിൽ (!is_compatible_unqualified_types(type1, type2)) {
            എങ്കിൽ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } അല്ലെങ്കിൽ എങ്കിൽ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } അല്ലെങ്കിൽ {
                tcc_warning("assignment from incompatible pointer type");
                നിർത്തുക;
            }
        }
        എങ്കിൽ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        നിർത്തുക;
    അവസ്ഥ VT_BYTE:
    അവസ്ഥ VT_SHORT:
    അവസ്ഥ VT_INT:
    അവസ്ഥ VT_LLONG:
        എങ്കിൽ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } അല്ലെങ്കിൽ എങ്കിൽ (sbt == VT_STRUCT) {
            പോകുക case_VT_STRUCT;
        }
        /* XXX: more tests */
        നിർത്തുക;
    അവസ്ഥ VT_STRUCT:
    case_VT_STRUCT:
        എങ്കിൽ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        നിർത്തുക;
    }
}

സ്ഥിതം ശൂന്യം gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC ശൂന്യം vstore(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    എങ്കിൽ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        എങ്കിൽ (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } അല്ലെങ്കിൽ
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            എങ്കിൽ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            അല്ലെങ്കിൽ എങ്കിൽ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            അല്ലെങ്കിൽ
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } അല്ലെങ്കിൽ എങ്കിൽ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        എങ്കിൽ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        എങ്കിൽ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        എങ്കിൽ (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } അല്ലെങ്കിൽ {
            unsigned long long mask = (1ULL << bit_size) - 1;
            എങ്കിൽ (dbt != VT_BOOL) {
                /* mask source */
                എങ്കിൽ (dbt == VT_LLONG)
                    vpushll(mask);
                അല്ലെങ്കിൽ
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
            എങ്കിൽ (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            അല്ലെങ്കിൽ
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (dbt == VT_VOID) {
        --vtop;
    } അല്ലെങ്കിൽ {
            /* optimize char/short casts */
            delayed_cast = 0;
            എങ്കിൽ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                എങ്കിൽ ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } അല്ലെങ്കിൽ {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            എങ്കിൽ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            എങ്കിൽ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            എങ്കിൽ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ശൂന്യ;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            എങ്കിൽ (USING_TWO_വാക്കുകൾ(dbt)) {
                പൂർണ്ണസംഖ്യ load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } അല്ലെങ്കിൽ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC ശൂന്യം inc(പൂർണ്ണസംഖ്യ post, പൂർണ്ണസംഖ്യ c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    എങ്കിൽ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    എങ്കിൽ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
    /* read the string */
    എങ്കിൽ (tok != TOK_STR)
        expect(സന്ദേശം);
    cstr_reset(&initstr);
    ആകുമ്പോൾ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    തിരികെ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC പൂർണ്ണസംഖ്യ exact_log2p1(പൂർണ്ണസംഖ്യ i)
{
  പൂർണ്ണസംഖ്യ ret;
  എങ്കിൽ (!i)
    തിരികെ 0;
  വേണ്ടി (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  എങ്കിൽ (i >= 1 << 4)
    ret += 4, i >>= 4;
  എങ്കിൽ (i >= 1 << 2)
    ret += 2, i >>= 2;
  എങ്കിൽ (i >= 1 << 1)
    ret++;
  തിരികെ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
സ്ഥിതം ശൂന്യം parse_attribute(AttributeDef *ad)
{
    പൂർണ്ണസംഖ്യ t, n;
    അക്ഷരം *astr;
    AttributeDef ad_tmp;
    
redo:
    എങ്കിൽ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        തിരികെ;
    എങ്കിൽ (ശൂന്യ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    ആകുമ്പോൾ (tok != ')') {
        എങ്കിൽ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        തിരഞ്ഞെടുപ്പ്(t) {
	അവസ്ഥ TOK_CLEANUP1:
	അവസ്ഥ TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    എങ്കിൽ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } അല്ലെങ്കിൽ എങ്കിൽ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    നിർത്തുക;
	}
        അവസ്ഥ TOK_CONSTRUCTOR1:
        അവസ്ഥ TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_DESTRUCTOR1:
        അവസ്ഥ TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_ALWAYS_INLINE1:
        അവസ്ഥ TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_SECTION1:
        അവസ്ഥ TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            നിർത്തുക;
        അവസ്ഥ TOK_ALIAS1:
        അവസ്ഥ TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            നിർത്തുക;
	അവസ്ഥ TOK_VISIBILITY1:
	അവസ്ഥ TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    എങ്കിൽ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    അല്ലെങ്കിൽ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            നിർത്തുക;
        അവസ്ഥ TOK_ALIGNED1:
        അവസ്ഥ TOK_ALIGNED2:
            എങ്കിൽ (tok == '(') {
                next();
                n = വ്യഞ്ജകം_const();
                എങ്കിൽ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } അല്ലെങ്കിൽ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    എങ്കിൽ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            നിർത്തുക;
        അവസ്ഥ TOK_PACKED1:
        അവസ്ഥ TOK_PACKED2:
            ad->a.packed = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_WEAK1:
        അവസ്ഥ TOK_WEAK2:
            ad->a.weak = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_NODEBUG1:
        അവസ്ഥ TOK_NODEBUG2:
            ad->a.nodebug = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_USED1:
        അവസ്ഥ TOK_USED2:
        അവസ്ഥ TOK_UNUSED1:
        അവസ്ഥ TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            നിർത്തുക;
        അവസ്ഥ TOK_CONST1:
        അവസ്ഥ TOK_CONST2:
        അവസ്ഥ TOK_CONST3:
        അവസ്ഥ TOK_PURE1:
        അവസ്ഥ TOK_PURE2:
	    /* ignored */
            നിർത്തുക;
        അവസ്ഥ TOK_NOINLINE:
	    /* ignored */
	    നിർത്തുക;
        അവസ്ഥ TOK_FORMAT1:
        അവസ്ഥ TOK_FORMAT2:
	    /* ignored */
            പോകുക skip_param;
        അവസ്ഥ TOK_NORETURN1:
        അവസ്ഥ TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_CDECL1:
        അവസ്ഥ TOK_CDECL2:
        അവസ്ഥ TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            നിർത്തുക;
        അവസ്ഥ TOK_STDCALL1:
        അവസ്ഥ TOK_STDCALL2:
        അവസ്ഥ TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            നിർത്തുക;
#ifdef TCC_TARGET_I386
        അവസ്ഥ TOK_REGPARM1:
        അവസ്ഥ TOK_REGPARM2:
            skip('(');
            n = വ്യഞ്ജകം_const();
            എങ്കിൽ (n > 3) 
                n = 3;
            അല്ലെങ്കിൽ എങ്കിൽ (n < 0)
                n = 0;
            എങ്കിൽ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            നിർത്തുക;
        അവസ്ഥ TOK_FASTCALL1:
        അവസ്ഥ TOK_FASTCALL2:
        അവസ്ഥ TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            നിർത്തുക;
        അവസ്ഥ TOK_THISCALL1:
        അവസ്ഥ TOK_THISCALL2:
        അവസ്ഥ TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            നിർത്തുക;
#endif
        അവസ്ഥ TOK_MODE:
            skip('(');
            തിരഞ്ഞെടുപ്പ്(tok) {
                അവസ്ഥ TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    നിർത്തുക;
                അവസ്ഥ TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    നിർത്തുക;
                അവസ്ഥ TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    നിർത്തുക;
                അവസ്ഥ TOK_MODE_SI:
                അവസ്ഥ TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    നിർത്തുക;
                സ്ഥിരസ്ഥിതി:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ശൂന്യ));
                    നിർത്തുക;
            }
            next();
            skip(')');
            നിർത്തുക;
        അവസ്ഥ TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_NODECORATE:
            ad->a.nodecorate = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ശൂന്യ));
            /* skip parameters */
skip_param:
            എങ്കിൽ (tok == '(') {
                പൂർണ്ണസംഖ്യ parenthesis = 0;
                ചെയ്യുക {
                    എങ്കിൽ (tok == '(') 
                        parenthesis++;
                    അല്ലെങ്കിൽ എങ്കിൽ (tok == ')') 
                        parenthesis--;
                    next();
                } ആകുമ്പോൾ (parenthesis && tok != -1);
            }
            നിർത്തുക;
        }
        എങ്കിൽ (tok != ',')
            നിർത്തുക;
        next();
    }
    skip(')');
    skip(')');
    പോകുക redo;
}

സ്ഥിതം Sym * find_field (CType *type, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ *cumofs)
{
    Sym *s = type->ref;
    പൂർണ്ണസംഖ്യ v1 = v | SYM_FIELD;
    എങ്കിൽ (!(v & SYM_FIELD)) { /* top-level call */
        എങ്കിൽ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        എങ്കിൽ (v < TOK_UIDENT)
            expect("field name");
        എങ്കിൽ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ആകുമ്പോൾ ((s = s->next) != ശൂന്യ) {
        എങ്കിൽ (s->v == v1) {
            *cumofs = s->c;
            തിരികെ s;
        }
        എങ്കിൽ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            എങ്കിൽ (ret) {
                *cumofs += s->c;
                തിരികെ ret;
            }
        }
    }
    എങ്കിൽ (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, ശൂന്യ));
    തിരികെ s;
}

സ്ഥിതം ശൂന്യം check_fields (CType *type, പൂർണ്ണസംഖ്യ check)
{
    Sym *s = type->ref;

    ആകുമ്പോൾ ((s = s->next) != ശൂന്യ) {
        പൂർണ്ണസംഖ്യ v = s->v & ~SYM_FIELD;
        എങ്കിൽ (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            എങ്കിൽ (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, ശൂന്യ));
            ts->tok ^= SYM_FIELD;
        } അല്ലെങ്കിൽ എങ്കിൽ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

സ്ഥിതം ശൂന്യം struct_layout(CType *type, AttributeDef *ad)
{
    പൂർണ്ണസംഖ്യ size, align, maxalign, offset, c, bit_pos, bit_size;
    പൂർണ്ണസംഖ്യ packed, a, bt, prevbt, prev_bit_size;
    പൂർണ്ണസംഖ്യ pcc = !tcc_state->ms_bitfields;
    പൂർണ്ണസംഖ്യ pragma_pack = *tcc_state->pack_അട്ടി_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    വേണ്ടി (f = type->ref->next; f; f = f->next) {
        എങ്കിൽ (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        അല്ലെങ്കിൽ
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        എങ്കിൽ (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } അല്ലെങ്കിൽ {
            /* in pcc mode, attribute packed overrides if set. */
            എങ്കിൽ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            എങ്കിൽ (pragma_pack) {
                packed = 1;
                എങ്കിൽ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                എങ്കിൽ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        എങ്കിൽ (a)
            align = a;

        എങ്കിൽ (type->ref->type.t == VT_UNION) {
	    എങ്കിൽ (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    എങ്കിൽ (size > c)
	        c = size;

	} അല്ലെങ്കിൽ എങ്കിൽ (bit_size < 0) {
            എങ്കിൽ (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    എങ്കിൽ (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} അല്ലെങ്കിൽ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            എങ്കിൽ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                എങ്കിൽ (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } അല്ലെങ്കിൽ എങ്കിൽ (f->a.aligned) {
                    പോകുക new_field;
                } അല്ലെങ്കിൽ എങ്കിൽ (!packed) {
                    പൂർണ്ണസംഖ്യ a8 = align * 8;
	            പൂർണ്ണസംഖ്യ ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    എങ്കിൽ (ofs > size / align)
                        പോകുക new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                എങ്കിൽ (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                ആകുമ്പോൾ (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		എങ്കിൽ (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } അല്ലെങ്കിൽ {
		bt = f->type.t & VT_BTYPE;
		എങ്കിൽ ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    എങ്കിൽ (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		എങ്കിൽ (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	എങ്കിൽ (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, ശൂന്യ), offset, size, align);
	എങ്കിൽ (f->type.t & VT_BITFIELD) {
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

    എങ്കിൽ (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    എങ്കിൽ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    എങ്കിൽ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        എങ്കിൽ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    വേണ്ടി (f = type->ref->next; f; f = f->next) {
        പൂർണ്ണസംഖ്യ s, px, cx, c0;
        CType t;

        എങ്കിൽ (0 == (f->type.t & VT_BITFIELD))
            തുടരുക;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        എങ്കിൽ (bit_size == 0)
            തുടരുക;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        എങ്കിൽ (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            തുടരുക;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        വേണ്ടി (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            എങ്കിൽ (c0 == cx)
                നിർത്തുക;
            s = (px + bit_size + 7) >> 3;
            എങ്കിൽ (s > 4) {
                t.t = VT_LLONG;
            } അല്ലെങ്കിൽ എങ്കിൽ (s > 2) {
                t.t = VT_INT;
            } അല്ലെങ്കിൽ എങ്കിൽ (s > 1) {
                t.t = VT_SHORT;
            } അല്ലെങ്കിൽ {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        എങ്കിൽ (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            എങ്കിൽ (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, ശൂന്യ),
                cx, s, align, px, bit_size);
#endif
        } അല്ലെങ്കിൽ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, ശൂന്യ));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
സ്ഥിതം പൂർണ്ണസംഖ്യ in_range(long long n, പൂർണ്ണസംഖ്യ t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    എങ്കിൽ (t & VT_UNSIGNED)
        തിരികെ n <= (m << 1) + 1;
    തിരികെ n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
സ്ഥിതം ശൂന്യം struct_decl(CType *type, പൂർണ്ണസംഖ്യ u)
{
    പൂർണ്ണസംഖ്യ v, c, size, align, flexible;
    പൂർണ്ണസംഖ്യ bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, വലുപ്പം ad);
    next();
    parse_attribute(&ad);

    v = 0;
    എങ്കിൽ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    എങ്കിൽ (u == VT_ENUM) {
        ut = VT_INT;
        എങ്കിൽ (tok == ':') { /* C2x enum : <type> ... */
            next();
            എങ്കിൽ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    എങ്കിൽ (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        എങ്കിൽ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            എങ്കിൽ (u == s->type.t)
                പോകുക do_decl;
            എങ്കിൽ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                പോകുക do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ശൂന്യ));
        }
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ശൂന്യ;
    /* we put an undefined size for struct/union */
    s = sym_തള്ളുക(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    എങ്കിൽ (tok == '{') {
        next();
        എങ്കിൽ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        എങ്കിൽ (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            എങ്കിൽ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            വേണ്ടി(;;) {
                v = tok;
                എങ്കിൽ (v < TOK_UIDENT)
                    expect("identifier");
                next();
                എങ്കിൽ (tok == '=') {
                    next();
		    ll = വ്യഞ്ജകം_const64();
                }
                എങ്കിൽ (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ശൂന്യ));
                ss = sym_തള്ളുക(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                എങ്കിൽ (ll < nl)
                    nl = ll;
                എങ്കിൽ (ll > pl)
                    pl = ll;
                എങ്കിൽ (tok != ',')
                    നിർത്തുക;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                എങ്കിൽ (tok == '}')
                    നിർത്തുക;
            }
            skip('}');

            എങ്കിൽ (bt) {
                t.t = bt;
                s->c = 2;
                പോകുക enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            എങ്കിൽ (nl >= 0) {
                എങ്കിൽ (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } അല്ലെങ്കിൽ എങ്കിൽ (pl != (പൂർണ്ണസംഖ്യ)pl || nl != (പൂർണ്ണസംഖ്യ)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            വേണ്ടി (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                എങ്കിൽ (ll == (പൂർണ്ണസംഖ്യ)ll) /* default is int if it fits */
                    തുടരുക;
                എങ്കിൽ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    എങ്കിൽ (ll == (unsigned)ll)
                        തുടരുക;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } അല്ലെങ്കിൽ {
            c = 0;
            flexible = 0;
            ആകുമ്പോൾ (tok != '}') {
                എങ്കിൽ (!parse_btype(&btype, &ad1, 0)) {
                    എങ്കിൽ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        തുടരുക;
                    }
		    skip(';');
		    തുടരുക;
		}
                ആകുമ്പോൾ (1) {
		    എങ്കിൽ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ശൂന്യ));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    എങ്കിൽ (tok != ':') {
			എങ്കിൽ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        എങ്കിൽ (v == 0) {
                    	    എങ്കിൽ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    അല്ലെങ്കിൽ {
				പൂർണ്ണസംഖ്യ v = btype.ref->v;
				എങ്കിൽ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    എങ്കിൽ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        എങ്കിൽ (type_size(&type1, &align) < 0) {
			    എങ്കിൽ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    അല്ലെങ്കിൽ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ശൂന്യ));
                        }
                        എങ്കിൽ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ശൂന്യ));
                    }
                    എങ്കിൽ (tok == ':') {
                        next();
                        bit_size = വ്യഞ്ജകം_const();
                        /* XXX: handle v = 0 case for messages */
                        എങ്കിൽ (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ശൂന്യ));
                        എങ്കിൽ (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ശൂന്യ));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    എങ്കിൽ (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        എങ്കിൽ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        എങ്കിൽ (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ശൂന്യ));
                        } അല്ലെങ്കിൽ എങ്കിൽ (bit_size == bsize
				    && !*tcc_state->pack_അട്ടി_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } അല്ലെങ്കിൽ എങ്കിൽ (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } അല്ലെങ്കിൽ {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    എങ്കിൽ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    എങ്കിൽ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    എങ്കിൽ (v) {
                        ss = sym_തള്ളുക(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    എങ്കിൽ (tok == ';' || tok == TOK_EOF)
                        നിർത്തുക;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            എങ്കിൽ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        എങ്കിൽ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

സ്ഥിതം ശൂന്യം sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
സ്ഥിതം ശൂന്യം parse_btype_qualify(CType *type, പൂർണ്ണസംഖ്യ qualifiers)
{
    ആകുമ്പോൾ (type->t & VT_ARRAY) {
        type->ref = sym_തള്ളുക(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    എങ്കിൽ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
സ്ഥിതം പൂർണ്ണസംഖ്യ parse_btype(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ ignore_label)
{
    പൂർണ്ണസംഖ്യ t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, വലുപ്പം(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ശൂന്യ;

    ആകുമ്പോൾ(1) {
        തിരഞ്ഞെടുപ്പ്(tok) {
        അവസ്ഥ TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            തുടരുക;

            /* basic types */
        അവസ്ഥ TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            എങ്കിൽ (u == VT_SHORT || u == VT_LONG) {
                എങ്കിൽ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (bt != -1 || (st != -1 && u != VT_INT))
                    പോകുക tmbt;
                എങ്കിൽ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    പോകുക tmbt;
                bt = u;
            }
            എങ്കിൽ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_VOID:
            u = VT_VOID;
            പോകുക basic_type;
        അവസ്ഥ TOK_SHORT:
            u = VT_SHORT;
            പോകുക basic_type;
        അവസ്ഥ TOK_INT:
            u = VT_INT;
            പോകുക basic_type;
        അവസ്ഥ TOK_ALIGNAS:
            { പൂർണ്ണസംഖ്യ n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, വലുപ്പം(AttributeDef));
              എങ്കിൽ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  എങ്കിൽ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  അല്ലെങ്കിൽ
                    type_size(&type1, &n);
              } അല്ലെങ്കിൽ {
                  n = വ്യഞ്ജകം_const();
                  എങ്കിൽ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            തുടരുക;
        അവസ്ഥ TOK_LONG:
            എങ്കിൽ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } അല്ലെങ്കിൽ എങ്കിൽ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } അല്ലെങ്കിൽ {
                u = VT_LONG;
                പോകുക basic_type;
            }
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_BOOL:
            u = VT_BOOL;
            പോകുക basic_type;
        അവസ്ഥ TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        അവസ്ഥ TOK_FLOAT:
            u = VT_FLOAT;
            പോകുക basic_type;
        അവസ്ഥ TOK_DOUBLE:
            എങ്കിൽ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } അല്ലെങ്കിൽ {
                u = VT_DOUBLE;
                പോകുക basic_type;
            }
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            പോകുക basic_type1;
        അവസ്ഥ TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            പോകുക basic_type2;
        അവസ്ഥ TOK_UNION:
            struct_decl(&type1, VT_UNION);
            പോകുക basic_type2;

            /* type modifiers */
        അവസ്ഥ TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            എങ്കിൽ (tok == '(') {
                parse_വ്യഞ്ജകം_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                എങ്കിൽ (type1.ref)
                    sym_to_attr(ad, type1.ref);
                പോകുക basic_type2;
            }
            നിർത്തുക;
        അവസ്ഥ TOK_CONST1:
        അവസ്ഥ TOK_CONST2:
        അവസ്ഥ TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_VOLATILE1:
        അവസ്ഥ TOK_VOLATILE2:
        അവസ്ഥ TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_SIGNED1:
        അവസ്ഥ TOK_SIGNED2:
        അവസ്ഥ TOK_SIGNED3:
            എങ്കിൽ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            നിർത്തുക;
        അവസ്ഥ TOK_RESTRICT1:
        അവസ്ഥ TOK_RESTRICT2:
        അവസ്ഥ TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_REGISTER:
        അവസ്ഥ TOK_AUTO:
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_UNSIGNED:
            എങ്കിൽ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            നിർത്തുക;

            /* storage */
        അവസ്ഥ TOK_EXTERN:
            g = VT_EXTERN;
            പോകുക storage;
        അവസ്ഥ TOK_STATIC:
            g = VT_STATIC;
            പോകുക storage;
        അവസ്ഥ TOK_TYPEDEF:
            g = VT_TYPEDEF;
            പോകുക storage;
       storage:
            എങ്കിൽ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_INLINE1:
        അവസ്ഥ TOK_INLINE2:
        അവസ്ഥ TOK_INLINE3:
            t |= VT_INLINE;
            next();
            നിർത്തുക;
        അവസ്ഥ TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            നിർത്തുക;
            /* GNUC attribute */
        അവസ്ഥ TOK_ATTRIBUTE1:
        അവസ്ഥ TOK_ATTRIBUTE2:
            parse_attribute(ad);
            എങ്കിൽ (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            തുടരുക;
            /* GNUC typeof */
        അവസ്ഥ TOK_TYPEOF1:
        അവസ്ഥ TOK_TYPEOF2:
        അവസ്ഥ TOK_TYPEOF3:
            next();
            parse_വ്യഞ്ജകം_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            എങ്കിൽ (type1.ref) {
                sym_to_attr(ad, type1.ref);
                എങ്കിൽ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            പോകുക basic_type2;
        അവസ്ഥ TOK_THREAD_LOCAL:
        അവസ്ഥ TOK___thread:
            എങ്കിൽ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            എങ്കിൽ (typespec_found)
                പോകുക the_end;
            s = sym_find(tok);
            എങ്കിൽ (!s || !(s->type.t & VT_TYPEDEF))
                പോകുക the_end;

            n = tok, next();
            എങ്കിൽ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                പോകുക the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            എങ്കിൽ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            എങ്കിൽ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            നിർത്തുക;
        }
        type_found = 1;
    }
the_end:
    എങ്കിൽ (tcc_state->char_is_unsigned) {
        എങ്കിൽ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    എങ്കിൽ (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    എങ്കിൽ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    തിരികെ type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
സ്ഥിതം വരിയിൽ ശൂന്യം convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    എങ്കിൽ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
സ്ഥിതം വരിയിൽ ശൂന്യം convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(ശൂന്യം)
{
    skip('(');
    തിരികെ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
സ്ഥിതം പൂർണ്ണസംഖ്യ asm_label_instr(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ v;
    അക്ഷരം *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    തിരികെ v;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ post_type(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ storage, പൂർണ്ണസംഖ്യ td)
{
    പൂർണ്ണസംഖ്യ n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ശൂന്യ;
    പൂർണ്ണസംഖ്യ *vla_array_str = ശൂന്യ;

    എങ്കിൽ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	എങ്കിൽ (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  തിരികെ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_അട്ടി ? &local_അട്ടി : &global_അട്ടി;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	എങ്കിൽ (tok == ')')
	  l = 0;
	അല്ലെങ്കിൽ എങ്കിൽ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	അല്ലെങ്കിൽ എങ്കിൽ (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_എടുക്കുക(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    തിരികെ 0;
	} അല്ലെങ്കിൽ
	  l = FUNC_OLD;

        first = ശൂന്യ;
        plast = &first;
        arg_size = 0;
        എങ്കിൽ (l) {
            വേണ്ടി(;;) {
                /* read param name and compute offset */
                എങ്കിൽ (l != FUNC_OLD) {
                    എങ്കിൽ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        നിർത്തുക;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    എങ്കിൽ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    എങ്കിൽ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } അല്ലെങ്കിൽ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ശൂന്യ;
                    next();
                }
                എങ്കിൽ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_തള്ളുക(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                എങ്കിൽ (tok == ')')
                    നിർത്തുക;
                skip(',');
                എങ്കിൽ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    നിർത്തുക;
                }
		എങ്കിൽ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } അല്ലെങ്കിൽ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        എങ്കിൽ (tok == '[') {
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
        sym_എടുക്കുക(ps, sr, 1);
        --local_scope;

    } അല്ലെങ്കിൽ എങ്കിൽ (tok == '[') {
	പൂർണ്ണസംഖ്യ saved_nocode_wanted = nocode_wanted;
        പൂർണ്ണസംഖ്യ array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        എങ്കിൽ (td & TYPE_PARAM) ആകുമ്പോൾ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    തിരഞ്ഞെടുപ്പ് (tok) {
	    അവസ്ഥ TOK_CONST1: അവസ്ഥ TOK_CONST2: അവസ്ഥ TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		തുടരുക;
	    അവസ്ഥ TOK_VOLATILE1: അവസ്ഥ TOK_VOLATILE2: അവസ്ഥ TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		തുടരുക;
	    അവസ്ഥ TOK_RESTRICT1: അവസ്ഥ TOK_RESTRICT2: അവസ്ഥ TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		തുടരുക;
	    അവസ്ഥ TOK_STATIC:
	    അവസ്ഥ '*':
		next();
		തുടരുക;
	    സ്ഥിരസ്ഥിതി:
		നിർത്തുക;
	    }
            എങ്കിൽ (tok != ']') {
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
		പോകുക check;
            }
            നിർത്തുക;

	} അല്ലെങ്കിൽ എങ്കിൽ (tok != ']') {
            എങ്കിൽ (!local_അട്ടി || (storage & VT_STATIC))
                vpushi(വ്യഞ്ജകം_const());
            അല്ലെങ്കിൽ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                എങ്കിൽ (n < 0)
                    tcc_error("invalid array size");
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        എങ്കിൽ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        എങ്കിൽ ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        എങ്കിൽ (t1 & VT_VLA) {
            എങ്കിൽ (n < 0) {
		എങ്കിൽ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    അല്ലെങ്കിൽ {
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
        എങ്കിൽ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_തള്ളുക(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        എങ്കിൽ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    എങ്കിൽ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    അല്ലെങ്കിൽ
	        tok_str_free_str(vla_array_str);
	}
    }
    തിരികെ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
സ്ഥിതം CType *type_decl(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ *v, പൂർണ്ണസംഖ്യ td)
{
    CType *post, *ret;
    പൂർണ്ണസംഖ്യ qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ആകുമ്പോൾ (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        തിരഞ്ഞെടുപ്പ്(tok) {
        അവസ്ഥ TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            പോകുക redo;
        അവസ്ഥ TOK_CONST1:
        അവസ്ഥ TOK_CONST2:
        അവസ്ഥ TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            പോകുക redo;
        അവസ്ഥ TOK_VOLATILE1:
        അവസ്ഥ TOK_VOLATILE2:
        അവസ്ഥ TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            പോകുക redo;
        അവസ്ഥ TOK_RESTRICT1:
        അവസ്ഥ TOK_RESTRICT2:
        അവസ്ഥ TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            പോകുക redo;
	/* XXX: clarify attribute handling */
	അവസ്ഥ TOK_ATTRIBUTE1:
	അവസ്ഥ TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    നിർത്തുക;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	എങ്കിൽ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    എങ്കിൽ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	എങ്കിൽ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} അല്ലെങ്കിൽ
	  പോകുക abstract;
    } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } അല്ലെങ്കിൽ {
  abstract:
	എങ്കിൽ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    തിരികെ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC ശൂന്യം indir(ശൂന്യം)
{
    എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            തിരികെ;
        expect("pointer");
    }
    എങ്കിൽ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    എങ്കിൽ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
സ്ഥിതം ശൂന്യം gfunc_param_typed(Sym *func, Sym *arg)
{
    പൂർണ്ണസംഖ്യ func_type;
    CType type;

    func_type = func->f.func_type;
    എങ്കിൽ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ശൂന്യ)) {
        /* default casting : only need to convert float to double */
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } അല്ലെങ്കിൽ എങ്കിൽ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } അല്ലെങ്കിൽ എങ്കിൽ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (arg == ശൂന്യ) {
        tcc_error("too many arguments to function");
    } അല്ലെങ്കിൽ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_type(CType *type, ശൂന്യം (*വ്യഞ്ജകം_fn)(ശൂന്യം))
{
    nocode_wanted++;
    വ്യഞ്ജകം_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
സ്ഥിതം ശൂന്യം parse_വ്യഞ്ജകം_type(CType *type)
{
    പൂർണ്ണസംഖ്യ n;
    AttributeDef ad;

    skip('(');
    എങ്കിൽ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } അല്ലെങ്കിൽ {
        വ്യഞ്ജകം_type(type, gexpr);
    }
    skip(')');
}

സ്ഥിതം ശൂന്യം parse_type(CType *type)
{
    AttributeDef ad;
    പൂർണ്ണസംഖ്യ n;

    എങ്കിൽ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

സ്ഥിതം ശൂന്യം parse_builtin_params(പൂർണ്ണസംഖ്യ nc, സ്ഥിരം അക്ഷരം *args)
{
    അക്ഷരം c, sep = '(';
    CType type;
    എങ്കിൽ (nc)
        nocode_wanted++;
    next();
    എങ്കിൽ (*args == 0)
	skip(sep);
    ആകുമ്പോൾ ((c = *args++)) {
	skip(sep);
	sep = ',';
        എങ്കിൽ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    തുടരുക;
        }
        വ്യഞ്ജകം_eq();
        type.ref = ശൂന്യ;
        type.t = 0;
	തിരഞ്ഞെടുപ്പ് (c) {
	    അവസ്ഥ 'e':
		തുടരുക;
	    അവസ്ഥ 'V':
                type.t = VT_CONSTANT;
	    അവസ്ഥ 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                നിർത്തുക;
	    അവസ്ഥ 'S':
                type.t = VT_CONSTANT;
	    അവസ്ഥ 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                നിർത്തുക;
	    അവസ്ഥ 'i':
                type.t = VT_INT;
                നിർത്തുക;
	    അവസ്ഥ 'l':
                type.t = VT_SIZE_T;
                നിർത്തുക;
	    സ്ഥിരസ്ഥിതി:
                നിർത്തുക;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    എങ്കിൽ (nc)
        nocode_wanted--;
}

സ്ഥിതം ശൂന്യം parse_atomic(പൂർണ്ണസംഖ്യ atok)
{
    പൂർണ്ണസംഖ്യ size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    അക്ഷരം buf[40];
    സ്ഥിതം സ്ഥിരം അക്ഷരം *സ്ഥിരം templates[] = {
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
    സ്ഥിരം അക്ഷരം *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ശൂന്യ;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    വേണ്ടി (arg = 0;;) {
        വ്യഞ്ജകം_eq();
        തിരഞ്ഞെടുപ്പ് (template[arg]) {
        അവസ്ഥ 'a':
        അവസ്ഥ 'A':
            atom_ptr = &vtop->type;
            എങ്കിൽ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            എങ്കിൽ (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            നിർത്തുക;

        അവസ്ഥ 'p':
            എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            നിർത്തുക;
        അവസ്ഥ 'v':
            gen_assign_cast(atom);
            നിർത്തുക;
        അവസ്ഥ 'l':
            indir();
            gen_assign_cast(atom);
            നിർത്തുക;
        അവസ്ഥ 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            നിർത്തുക;
        അവസ്ഥ 'm':
            gen_assign_cast(&int_type);
            നിർത്തുക;
        അവസ്ഥ 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            നിർത്തുക;
        }
        എങ്കിൽ ('.' == template[++arg])
            നിർത്തുക;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    തിരഞ്ഞെടുപ്പ് (template[arg + 1]) {
    അവസ്ഥ 'b':
        ct.t = VT_BOOL;
        നിർത്തുക;
    അവസ്ഥ 'v':
        ct = *atom;
        നിർത്തുക;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    എങ്കിൽ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#അല്ലെങ്കിൽ
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    എങ്കിൽ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC ശൂന്യം unary(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    എങ്കിൽ (debug_modes)
        tcc_debug_വരി(tcc_state), tcc_tcov_check_വരി (tcc_state, 1);

    type.ref = ശൂന്യ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    തിരഞ്ഞെടുപ്പ്(tok) {
    അവസ്ഥ TOK_EXTENSION:
        next();
        പോകുക tok_next;
    അവസ്ഥ TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        പോകുക തള്ളുക_tokc;
#endif
    അവസ്ഥ TOK_CINT:
    അവസ്ഥ TOK_CCHAR: 
	t = VT_INT;
 തള്ളുക_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        നിർത്തുക;
    അവസ്ഥ TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CLLONG:
        t = VT_LLONG;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CFLOAT:
        t = VT_FLOAT;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CDOUBLE:
        t = VT_DOUBLE;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#അല്ലെങ്കിൽ
        t = VT_LDOUBLE;
#endif
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	പോകുക തള്ളുക_tokc;
    അവസ്ഥ TOK___FUNCTION__:
        എങ്കിൽ (!gnu_ext)
            പോകുക tok_identifier;
        /* fall thru */
    അവസ്ഥ TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        പോകുക case_TOK_STR;
    അവസ്ഥ TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#അല്ലെങ്കിൽ
        t = VT_INT;
#endif
        പോകുക str_init;
    അവസ്ഥ TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        എങ്കിൽ (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, വലുപ്പം(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        നിർത്തുക;
    അവസ്ഥ TOK_SOTYPE:
    അവസ്ഥ '(':
        t = tok;
        next();
        /* cast ? */
        എങ്കിൽ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            എങ്കിൽ (tok == '{') {
                    /* data is allocated locally by default */
                എങ്കിൽ (global_വ്യഞ്ജകം)
                    r = VT_CONST;
                അല്ലെങ്കിൽ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                എങ്കിൽ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, വലുപ്പം(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                തിരികെ;
            } അല്ലെങ്കിൽ {
                unary();
                gen_cast(&type);
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == '{') {
	    പൂർണ്ണസംഖ്യ saved_nocode_wanted = nocode_wanted;
            എങ്കിൽ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            എങ്കിൽ (0 == local_scope)
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
            block(STMT_വ്യഞ്ജകം);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            എങ്കിൽ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } അല്ലെങ്കിൽ {
            gexpr();
            skip(')');
        }
        നിർത്തുക;
    അവസ്ഥ '*':
        next();
        unary();
        indir();
        നിർത്തുക;
    അവസ്ഥ '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        എങ്കിൽ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        നിർത്തുക;
    അവസ്ഥ '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        നിർത്തുക;
    അവസ്ഥ '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        നിർത്തുക;
    അവസ്ഥ '+':
        next();
        unary();
        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	എങ്കിൽ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        നിർത്തുക;
    അവസ്ഥ TOK_SIZEOF:
    അവസ്ഥ TOK_ALIGNOF1:
    അവസ്ഥ TOK_ALIGNOF2:
    അവസ്ഥ TOK_ALIGNOF3:
        t = tok;
        next();
        എങ്കിൽ (tok == '(')
            tok = TOK_SOTYPE;
        വ്യഞ്ജകം_type(&type, unary);
        എങ്കിൽ (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } അല്ലെങ്കിൽ {
            type_size(&type, &align);
            s = ശൂന്യ;
            എങ്കിൽ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            എങ്കിൽ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        നിർത്തുക;

    അവസ്ഥ TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        നിർത്തുക;
    അവസ്ഥ TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        നിർത്തുക;
    അവസ്ഥ TOK_builtin_choose_വ്യഞ്ജകം:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = വ്യഞ്ജകം_const64();
	    skip(',');
	    എങ്കിൽ (!c) {
		nocode_wanted++;
	    }
	    വ്യഞ്ജകം_eq();
	    എങ്കിൽ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    എങ്കിൽ (c) {
		nocode_wanted++;
	    }
	    വ്യഞ്ജകം_eq();
	    എങ്കിൽ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        നിർത്തുക;
    അവസ്ഥ TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        നിർത്തുക;
    അവസ്ഥ TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        നിർത്തുക;
    അവസ്ഥ TOK_builtin_frame_address:
    അവസ്ഥ TOK_builtin_return_address:
        {
            പൂർണ്ണസംഖ്യ tok1 = tok;
            പൂർണ്ണസംഖ്യ level;
            next();
            skip('(');
            level = വ്യഞ്ജകം_const();
            എങ്കിൽ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ആകുമ്പോൾ (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            എങ്കിൽ (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#അല്ലെങ്കിൽ
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        നിർത്തുക;
#ifdef TCC_TARGET_RISCV64
    അവസ്ഥ TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        എങ്കിൽ (r == VT_LLOCAL)
            r = VT_LOCAL;
        എങ്കിൽ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        നിർത്തുക;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    അവസ്ഥ TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        എങ്കിൽ (r == VT_LLOCAL)
            r = VT_LOCAL;
        എങ്കിൽ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        നിർത്തുക;
#അല്ലെങ്കിൽ
    അവസ്ഥ TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	നിർത്തുക;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    അവസ്ഥ TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        നിർത്തുക;
    }
    അവസ്ഥ TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        നിർത്തുക;
    }
#endif
#ifdef TCC_TARGET_ARM64
    അവസ്ഥ TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        നിർത്തുക;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    അവസ്ഥ TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        നിർത്തുക;
    }
#endif

    /* atomic operations */
    അവസ്ഥ TOK___atomic_store:
    അവസ്ഥ TOK___atomic_load:
    അവസ്ഥ TOK___atomic_exchange:
    അവസ്ഥ TOK___atomic_compare_exchange:
    അവസ്ഥ TOK___atomic_fetch_add:
    അവസ്ഥ TOK___atomic_fetch_sub:
    അവസ്ഥ TOK___atomic_fetch_or:
    അവസ്ഥ TOK___atomic_fetch_xor:
    അവസ്ഥ TOK___atomic_fetch_and:
    അവസ്ഥ TOK___atomic_fetch_nand:
    അവസ്ഥ TOK___atomic_add_fetch:
    അവസ്ഥ TOK___atomic_sub_fetch:
    അവസ്ഥ TOK___atomic_or_fetch:
    അവസ്ഥ TOK___atomic_xor_fetch:
    അവസ്ഥ TOK___atomic_and_fetch:
    അവസ്ഥ TOK___atomic_nand_fetch:
        parse_atomic(tok);
        നിർത്തുക;

    /* pre operations */
    അവസ്ഥ TOK_INC:
    അവസ്ഥ TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        നിർത്തുക;
    അവസ്ഥ '-':
        next();
        unary();
	എങ്കിൽ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} അല്ലെങ്കിൽ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        നിർത്തുക;
    അവസ്ഥ TOK_LAND:
        എങ്കിൽ (!gnu_ext)
            പോകുക tok_identifier;
        next();
        /* allow to take the address of a label */
        എങ്കിൽ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        എങ്കിൽ (!s) {
            s = label_തള്ളുക(&global_label_അട്ടി, tok, LABEL_FORWARD);
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        എങ്കിൽ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        നിർത്തുക;

    അവസ്ഥ TOK_GENERIC:
    {
	CType controlling_type;
	പൂർണ്ണസംഖ്യ has_default = 0;
	പൂർണ്ണസംഖ്യ has_match = 0;
	പൂർണ്ണസംഖ്യ learn = 0;
	TokenString *str = ശൂന്യ;
	പൂർണ്ണസംഖ്യ saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	വ്യഞ്ജകം_type(&controlling_type, വ്യഞ്ജകം_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        വേണ്ടി (;;) {
	    learn = 0;
	    skip(',');
	    എങ്കിൽ (tok == TOK_DEFAULT) {
		എങ്കിൽ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		എങ്കിൽ (!has_match)
		    learn = 1;
		next();
	    } അല്ലെങ്കിൽ {
		പൂർണ്ണസംഖ്യ v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		എങ്കിൽ (compare_types(&controlling_type, &type, 0)) {
		    എങ്കിൽ (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    എങ്കിൽ (learn) {
		എങ്കിൽ (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } അല്ലെങ്കിൽ {
		skip_or_save_block(ശൂന്യ);
	    }
	    എങ്കിൽ (tok == ')')
		നിർത്തുക;
	}
	എങ്കിൽ (!str) {
	    അക്ഷരം buf[60];
	    type_to_str(buf, വലുപ്പം buf, &controlling_type, ശൂന്യ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	വ്യഞ്ജകം_eq();
	എങ്കിൽ (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	നിർത്തുക;
    }
    // special qnan , snan and infinity values
    അവസ്ഥ TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        നിർത്തുക;
    അവസ്ഥ TOK___SNAN__:
	n = 0x7f800001;
	പോകുക special_math_val;
    അവസ്ഥ TOK___INF__:
	n = 0x7f800000;
	പോകുക special_math_val;

    സ്ഥിരസ്ഥിതി:
    tok_identifier:
        എങ്കിൽ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        എങ്കിൽ (!s || IS_ASM_SYM(s)) {
            സ്ഥിരം അക്ഷരം *name = get_tok_str(t, ശൂന്യ);
            എങ്കിൽ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            എങ്കിൽ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        എങ്കിൽ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        എങ്കിൽ (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            എങ്കിൽ (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } അല്ലെങ്കിൽ എങ്കിൽ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        നിർത്തുക;
    }
    
    /* post operations */
    ആകുമ്പോൾ (1) {
        എങ്കിൽ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == '.' || tok == TOK_ARROW) {
            പൂർണ്ണസംഖ്യ qualifiers, cumofs;
            /* field */ 
            എങ്കിൽ (tok == TOK_ARROW) 
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
            എങ്കിൽ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            എങ്കിൽ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                എങ്കിൽ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == '(') {
            SValue ret;
            Sym *sa;
            പൂർണ്ണസംഖ്യ nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                എങ്കിൽ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        പോകുക error_func;
                } അല്ലെങ്കിൽ {
                error_func:
                    expect("function pointer");
                }
            } അല്ലെങ്കിൽ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            എങ്കിൽ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                എങ്കിൽ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                എങ്കിൽ (size < 16)
                    ആകുമ്പോൾ (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    എങ്കിൽ (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    എങ്കിൽ (ret_nregs < 0)
                      vtop--;
                    അല്ലെങ്കിൽ
                      nb_args++;
                }
            } അല്ലെങ്കിൽ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            എങ്കിൽ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ശൂന്യ;
            എങ്കിൽ (tok != ')') {
                r = tcc_state->reverse_funcargs;
                വേണ്ടി(;;) {
                    എങ്കിൽ (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } അല്ലെങ്കിൽ {
                        വ്യഞ്ജകം_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    എങ്കിൽ (sa)
                        sa = sa->next;
                    എങ്കിൽ (tok == ')')
                        നിർത്തുക;
                    skip(',');
                }
            }
            എങ്കിൽ (sa)
                tcc_error("too few arguments to function");

            എങ്കിൽ (p) { /* with reverse_funcargs */
                വേണ്ടി (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    ചെയ്യുക {
                        sa = sa->next, p2 = p2->prev;
                    } ആകുമ്പോൾ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    വ്യഞ്ജകം_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            എങ്കിൽ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } അല്ലെങ്കിൽ {
                /* return value */
                n = ret_nregs;
                ആകുമ്പോൾ (n > 1) {
                    പൂർണ്ണസംഖ്യ rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    വേണ്ടി (r = 0; r < NB_REGS; ++r)
                        എങ്കിൽ (reg_classes[r] & rc)
                            നിർത്തുക;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                എങ്കിൽ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    പൂർണ്ണസംഖ്യ addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    എങ്കിൽ (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    വേണ്ടി (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        എങ്കിൽ (--ret_nregs == 0)
                          നിർത്തുക;
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
                എങ്കിൽ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#അല്ലെങ്കിൽ
                    vtop->type.t = VT_INT;
#endif
                }
            }
            എങ്കിൽ (s->f.func_noreturn) {
                എങ്കിൽ (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } അല്ലെങ്കിൽ {
            നിർത്തുക;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_prod(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;

    unary();
    ആകുമ്പോൾ ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_sum(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;

    വ്യഞ്ജകം_prod();
    ആകുമ്പോൾ ((t = tok) == '+' || t == '-') {
        next();
        വ്യഞ്ജകം_prod();
        gen_op(t);
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_shift(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;

    വ്യഞ്ജകം_sum();
    ആകുമ്പോൾ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        വ്യഞ്ജകം_sum();
        gen_op(t);
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_cmp(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;

    വ്യഞ്ജകം_shift();
    ആകുമ്പോൾ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        വ്യഞ്ജകം_shift();
        gen_op(t);
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_cmpeq(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;

    വ്യഞ്ജകം_cmp();
    ആകുമ്പോൾ ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        വ്യഞ്ജകം_cmp();
        gen_op(t);
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_and(ശൂന്യം)
{
    വ്യഞ്ജകം_cmpeq();
    ആകുമ്പോൾ (tok == '&') {
        next();
        വ്യഞ്ജകം_cmpeq();
        gen_op('&');
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_xor(ശൂന്യം)
{
    വ്യഞ്ജകം_and();
    ആകുമ്പോൾ (tok == '^') {
        next();
        വ്യഞ്ജകം_and();
        gen_op('^');
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_or(ശൂന്യം)
{
    വ്യഞ്ജകം_xor();
    ആകുമ്പോൾ (tok == '|') {
        next();
        വ്യഞ്ജകം_xor();
        gen_op('|');
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_landor(പൂർണ്ണസംഖ്യ op);

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_land(ശൂന്യം)
{
    വ്യഞ്ജകം_or();
    എങ്കിൽ (tok == TOK_LAND)
        വ്യഞ്ജകം_landor(tok);
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_lor(ശൂന്യം)
{
    വ്യഞ്ജകം_land();
    എങ്കിൽ (tok == TOK_LOR)
        വ്യഞ്ജകം_landor(tok);
}

# define വ്യഞ്ജകം_landor_next(op) op == TOK_LAND ? വ്യഞ്ജകം_or() : വ്യഞ്ജകം_land()
#അല്ലെങ്കിൽ /* defined precedence_parser */
# define വ്യഞ്ജകം_landor_next(op) unary(), വ്യഞ്ജകം_infix(precedence(op) + 1)
# define വ്യഞ്ജകം_lor() unary(), വ്യഞ്ജകം_infix(1)

സ്ഥിതം പൂർണ്ണസംഖ്യ precedence(പൂർണ്ണസംഖ്യ tok)
{
    തിരഞ്ഞെടുപ്പ് (tok) {
        അവസ്ഥ TOK_LOR: തിരികെ 1;
        അവസ്ഥ TOK_LAND: തിരികെ 2;
	അവസ്ഥ '|': തിരികെ 3;
	അവസ്ഥ '^': തിരികെ 4;
	അവസ്ഥ '&': തിരികെ 5;
	അവസ്ഥ TOK_EQ: അവസ്ഥ TOK_NE: തിരികെ 6;
 relat: അവസ്ഥ TOK_ULT: അവസ്ഥ TOK_UGE: തിരികെ 7;
	അവസ്ഥ TOK_SHL: അവസ്ഥ TOK_SAR: തിരികെ 8;
	അവസ്ഥ '+': അവസ്ഥ '-': തിരികെ 9;
	അവസ്ഥ '*': അവസ്ഥ '/': അവസ്ഥ '%': തിരികെ 10;
	സ്ഥിരസ്ഥിതി:
	    എങ്കിൽ (tok >= TOK_ULE && tok <= TOK_GT)
	        പോകുക relat;
	    തിരികെ 0;
    }
}
സ്ഥിതം unsigned അക്ഷരം prec[256];
സ്ഥിതം ശൂന്യം init_prec(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_landor(പൂർണ്ണസംഖ്യ op);

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_infix(പൂർണ്ണസംഖ്യ p)
{
    പൂർണ്ണസംഖ്യ t = tok, p2;
    ആകുമ്പോൾ ((p2 = precedence(t)) >= p) {
        എങ്കിൽ (t == TOK_LOR || t == TOK_LAND) {
            വ്യഞ്ജകം_landor(t);
        } അല്ലെങ്കിൽ {
            next();
            unary();
            എങ്കിൽ (precedence(tok) > p2)
              വ്യഞ്ജകം_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
സ്ഥിതം പൂർണ്ണസംഖ്യ condition_3way(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ c = -1;
    എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    തിരികെ c;
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_landor(പൂർണ്ണസംഖ്യ op)
{
    പൂർണ്ണസംഖ്യ t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    വേണ്ടി(;;) {
        c = f ? i : condition_3way();
        എങ്കിൽ (c < 0)
            save_regs(1), cc = 0;
        അല്ലെങ്കിൽ എങ്കിൽ (c != i)
            nocode_wanted++, f = 1;
        എങ്കിൽ (tok != op)
            നിർത്തുക;
        എങ്കിൽ (c < 0)
            t = gvtst(i, t);
        അല്ലെങ്കിൽ
            vpop();
        next();
        വ്യഞ്ജകം_landor_next(op);
    }
    എങ്കിൽ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } അല്ലെങ്കിൽ {
        gvtst_set(i, t);
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ is_cond_bool(SValue *sv)
{
    എങ്കിൽ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        തിരികെ (unsigned)sv->c.i < 2;
    എങ്കിൽ (sv->r == VT_CMP)
        തിരികെ 1;
    തിരികെ 0;
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_cond(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    വ്യഞ്ജകം_lor();
    എങ്കിൽ (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        എങ്കിൽ (!g) {
            എങ്കിൽ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } അല്ലെങ്കിൽ {
                vpop();
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        എങ്കിൽ (c == 0)
          nocode_wanted++;
        എങ്കിൽ (!g)
          gexpr();

        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        എങ്കിൽ (g) {
            u = tt;
        } അല്ലെങ്കിൽ എങ്കിൽ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } അല്ലെങ്കിൽ
          u = 0;

        എങ്കിൽ (c == 0)
          nocode_wanted--;
        എങ്കിൽ (c == 1)
          nocode_wanted++;
        skip(':');
        വ്യഞ്ജകം_cond();

        എങ്കിൽ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        എങ്കിൽ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        എങ്കിൽ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            തിരികെ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        എങ്കിൽ (c != 1) {
            gen_cast(&type);
            എങ്കിൽ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        എങ്കിൽ (USING_TWO_വാക്കുകൾ(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        എങ്കിൽ (c < 0) {
            എങ്കിൽ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        എങ്കിൽ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        എങ്കിൽ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            എങ്കിൽ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        എങ്കിൽ (c < 0) {
            എങ്കിൽ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        എങ്കിൽ (islv)
          indir();
    }
}

സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_eq(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;
    
    വ്യഞ്ജകം_cond();
    എങ്കിൽ ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        എങ്കിൽ (t == '=') {
            വ്യഞ്ജകം_eq();
        } അല്ലെങ്കിൽ {
            vdup();
            വ്യഞ്ജകം_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC ശൂന്യം gexpr(ശൂന്യം)
{
    വ്യഞ്ജകം_eq();
    എങ്കിൽ (tok == ',') {
        ചെയ്യുക {
            vpop();
            next();
            വ്യഞ്ജകം_eq();
        } ആകുമ്പോൾ (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        എങ്കിൽ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            എങ്കിൽ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
സ്ഥിതം ശൂന്യം വ്യഞ്ജകം_const1(ശൂന്യം)
{
    nocode_wanted += CONST_WANTED_BIT;
    വ്യഞ്ജകം_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
സ്ഥിതം വരിയിൽ int64_t വ്യഞ്ജകം_const64(ശൂന്യം)
{
    int64_t c;
    വ്യഞ്ജകം_const1();
    എങ്കിൽ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    തിരികെ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC പൂർണ്ണസംഖ്യ വ്യഞ്ജകം_const(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ c;
    int64_t wc = വ്യഞ്ജകം_const64();
    c = wc;
    എങ്കിൽ (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    തിരികെ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
സ്ഥിതം ശൂന്യം gfunc_return(CType *func_type)
{
    എങ്കിൽ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        പൂർണ്ണസംഖ്യ ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        എങ്കിൽ (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } അല്ലെങ്കിൽ എങ്കിൽ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } അല്ലെങ്കിൽ {
            /* returning structure packed into registers */
            പൂർണ്ണസംഖ്യ size, addr, align, rc, n;
            size = type_size(func_type,&align);
            എങ്കിൽ (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		എങ്കിൽ (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		എങ്കിൽ (ret_align > align)
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
            വേണ്ടി (n = ret_nregs; --n > 0;) {
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
    } അല്ലെങ്കിൽ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

സ്ഥിതം ശൂന്യം check_func_return(ശൂന്യം)
{
    എങ്കിൽ ((func_vt.t & VT_BTYPE) == VT_VOID)
        തിരികെ;
    എങ്കിൽ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } അല്ലെങ്കിൽ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

സ്ഥിതം പൂർണ്ണസംഖ്യ case_cmp(uint64_t a, uint64_t b)
{
    എങ്കിൽ (cur_switch->sv.type.t & VT_UNSIGNED)
        തിരികെ a < b ? -1 : a > b;
    അല്ലെങ്കിൽ
        തിരികെ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ case_cmp_qs(സ്ഥിരം ശൂന്യം *pa, സ്ഥിരം ശൂന്യം *pb)
{
    തിരികെ case_cmp((*(ഘടന case_t**)pa)->v1, (*(ഘടന case_t**)pb)->v1);
}

സ്ഥിതം ശൂന്യം case_sort(ഘടന switch_t *sw)
{
    ഘടന case_t **p;
    എങ്കിൽ (sw->n < 2)
        തിരികെ;
    qsort(sw->p, sw->n, വലുപ്പം *sw->p, case_cmp_qs);
    p = sw->p;
    ആകുമ്പോൾ (p < sw->p + sw->n - 1) {
        എങ്കിൽ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            പൂർണ്ണസംഖ്യ l1 = p[0]->വരി, l2 = p[1]->വരി;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } അല്ലെങ്കിൽ എങ്കിൽ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * വലുപ്പം *p);
        } അല്ലെങ്കിൽ
            ++p;
    }
}

സ്ഥിതം പൂർണ്ണസംഖ്യ gcase(ഘടന case_t **base, പൂർണ്ണസംഖ്യ len, പൂർണ്ണസംഖ്യ dsym)
{
    ഘടന case_t *p;
    പൂർണ്ണസംഖ്യ t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    എങ്കിൽ (t != VT_LLONG)
        t = VT_INT;
    ആകുമ്പോൾ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        എങ്കിൽ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } അല്ലെങ്കിൽ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            എങ്കിൽ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            അല്ലെങ്കിൽ
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
    തിരികെ gjmp(dsym);
}

സ്ഥിതം ശൂന്യം end_switch(ശൂന്യം)
{
    ഘടന switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
സ്ഥിതം ശൂന്യം save_lvalues(ശൂന്യം)
{
    SValue *sv = vtop;
    ആകുമ്പോൾ (sv >= vstack) {
        എങ്കിൽ (sv->sym && (sv->r & VT_LVAL)) {
            പൂർണ്ണസംഖ്യ align, size = type_size(&sv->type, &align);
            പൂർണ്ണസംഖ്യ r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

സ്ഥിതം ശൂന്യം try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    വേണ്ടി (; cls != stop; cls = cls->next) {
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


സ്ഥിതം ശൂന്യം try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    പൂർണ്ണസംഖ്യ ocd, ccd;

    എങ്കിൽ (!cur_scope->cl.s)
	തിരികെ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    വേണ്ടി (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    വേണ്ടി (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    വേണ്ടി (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
സ്ഥിതം ശൂന്യം block_cleanup(ഘടന scope *o)
{
    പൂർണ്ണസംഖ്യ jmp = 0;
    Sym *g, **pg;
    വേണ്ടി (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        എങ്കിൽ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            എങ്കിൽ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            എങ്കിൽ (!o->cl.n)
                പോകുക remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } അല്ലെങ്കിൽ {
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

സ്ഥിതം ശൂന്യം vla_restore(പൂർണ്ണസംഖ്യ loc)
{
    എങ്കിൽ (loc)
        gen_vla_sp_restore(loc);
}

സ്ഥിതം ശൂന്യം vla_leave(ഘടന scope *o)
{
    ഘടന scope *c = cur_scope, *v = ശൂന്യ;
    വേണ്ടി (; c != o && c; c = c->prev)
      എങ്കിൽ (c->vla.അക്കം)
        v = c;
    എങ്കിൽ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

സ്ഥിതം ശൂന്യം new_scope(ഘടന scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.അക്കം = 0;

    /* record local declaration stack position */
    o->lstk = local_അട്ടി;
    o->llstk = local_label_അട്ടി;
    ++local_scope;
}

സ്ഥിതം ശൂന്യം prev_scope(ഘടന scope *o, പൂർണ്ണസംഖ്യ is_വ്യഞ്ജകം)
{
    vla_leave(o->prev);

    എങ്കിൽ (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    എങ്കിൽ (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_വ്യഞ്ജകം);

    /* pop locally defined labels */
    label_എടുക്കുക(&local_label_അട്ടി, o->llstk, is_വ്യഞ്ജകം);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_എടുക്കുക(&local_അട്ടി, o->lstk, is_വ്യഞ്ജകം);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
സ്ഥിതം ശൂന്യം leave_scope(ഘടന scope *o)
{
    എങ്കിൽ (!o)
        തിരികെ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
സ്ഥിതം ശൂന്യം new_scope_s(ഘടന scope *o)
{
    o->lstk = local_അട്ടി;
    ++local_scope;
}

സ്ഥിതം ശൂന്യം prev_scope_s(ഘടന scope *o)
{
    sym_എടുക്കുക(&local_അട്ടി, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

സ്ഥിതം ശൂന്യം lblock(പൂർണ്ണസംഖ്യ *bsym, പൂർണ്ണസംഖ്യ *csym)
{
    ഘടന scope *lo = loop_scope, *co = cur_scope;
    പൂർണ്ണസംഖ്യ *b = co->bsym, *c = co->csym;
    എങ്കിൽ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    എങ്കിൽ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
സ്ഥിതം ശൂന്യം gexpr_decl(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ v = decl(VT_JMP);
    എങ്കിൽ (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (v)
            skip(';');
        gexpr();
    }
}

സ്ഥിതം ശൂന്യം block(പൂർണ്ണസംഖ്യ flags)
{
    പൂർണ്ണസംഖ്യ a, b, c, d, e, t;
    ഘടന scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    എങ്കിൽ (TOK_HAS_മൂല്യം(t))
        പോകുക വ്യഞ്ജകം;
    next();

    എങ്കിൽ (debug_modes)
        tcc_tcov_check_വരി (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    എങ്കിൽ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        എങ്കിൽ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } അല്ലെങ്കിൽ {
            gsym(a);
        }
        prev_scope_s(&o);

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_WHILE) {
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

    } അല്ലെങ്കിൽ എങ്കിൽ (t == '{') {
        എങ്കിൽ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ആകുമ്പോൾ (tok == TOK_LABEL) {
            ചെയ്യുക {
                next();
                എങ്കിൽ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_തള്ളുക(&local_label_അട്ടി, tok, LABEL_DECLARED);
                next();
            } ആകുമ്പോൾ (tok == ',');
            skip(';');
        }

        ആകുമ്പോൾ (tok != '}') {
	    decl(VT_LOCAL);
            എങ്കിൽ (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_വ്യഞ്ജകം);
        എങ്കിൽ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        എങ്കിൽ (local_scope)
            next();
        അല്ലെങ്കിൽ എങ്കിൽ (!nocode_wanted)
            check_func_return();

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        എങ്കിൽ (tok != ';') {
            gexpr();
            എങ്കിൽ (b) {
                gen_assign_cast(&func_vt);
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } അല്ലെങ്കിൽ എങ്കിൽ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(വേര്_scope);
        എങ്കിൽ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        എങ്കിൽ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        എങ്കിൽ (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_BREAK) {
        /* compute jump */
        എങ്കിൽ (!cur_scope->bsym)
            tcc_error("cannot break");
        എങ്കിൽ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        അല്ലെങ്കിൽ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_CONTINUE) {
        /* compute jump */
        എങ്കിൽ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        എങ്കിൽ (tok != ';') {
            /* c99 for-loop init decl? */
            എങ്കിൽ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        എങ്കിൽ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        എങ്കിൽ (tok != ')') {
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

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_DO) {
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

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_SWITCH) {
        ഘടന switch_t *sw;

        sw = tcc_mallocz(വലുപ്പം *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        എങ്കിൽ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ശൂന്യ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        എങ്കിൽ (sw->nocode_wanted)
            പോകുക skip_switch;
        case_sort(sw);
        sw->bsym = ശൂന്യ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        എങ്കിൽ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        അല്ലെങ്കിൽ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_CASE) {
        ഘടന case_t *cr;
        എങ്കിൽ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(വലുപ്പം(ഘടന case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(വ്യഞ്ജകം_const64(), t);
        എങ്കിൽ (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(വ്യഞ്ജകം_const64(), t);
            എങ്കിൽ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        എങ്കിൽ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->വരി = file->വരി_അക്കം;
        skip(':');
        പോകുക block_after_label;

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_DEFAULT) {
        എങ്കിൽ (!cur_switch)
            expect("switch");
        എങ്കിൽ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        പോകുക block_after_label;

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        എങ്കിൽ (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            എങ്കിൽ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            എങ്കിൽ (!s)
              s = label_തള്ളുക(&global_label_അട്ടി, tok, LABEL_FORWARD);
            അല്ലെങ്കിൽ എങ്കിൽ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    എങ്കിൽ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		എങ്കിൽ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } അല്ലെങ്കിൽ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } അല്ലെങ്കിൽ {
            expect("label identifier");
        }
        skip(';');

    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } അല്ലെങ്കിൽ {
        എങ്കിൽ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            എങ്കിൽ (s) {
                എങ്കിൽ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ശൂന്യ));
                s->r = LABEL_DEFINED;
		എങ്കിൽ (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    വേണ്ടി (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_എടുക്കുക(&s->next, ശൂന്യ, 0);
		} അല്ലെങ്കിൽ
		  gsym(s->jnext);
            } അല്ലെങ്കിൽ {
                s = label_തള്ളുക(&global_label_അട്ടി, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ശൂന്യ);

            എങ്കിൽ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            എങ്കിൽ (tok != '}') {
                എങ്കിൽ (0 == (flags & STMT_COMPOUND))
                    പോകുക again;
                /* C23: insert implicit null-statement whithin compound statement */
            } അല്ലെങ്കിൽ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } അല്ലെങ്കിൽ {
            /* expression case */
            എങ്കിൽ (t != ';') {
                unget_tok(t);
    വ്യഞ്ജകം:
                എങ്കിൽ (flags & STMT_വ്യഞ്ജകം) {
                    vpop();
                    gexpr();
                } അല്ലെങ്കിൽ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    എങ്കിൽ (debug_modes)
        tcc_tcov_check_വരി (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
സ്ഥിതം ശൂന്യം skip_or_save_block(TokenString **str)
{
    പൂർണ്ണസംഖ്യ braces = tok == '{';
    പൂർണ്ണസംഖ്യ level = 0;
    എങ്കിൽ (str)
      *str = tok_str_alloc();

    ആകുമ്പോൾ (1) {
	പൂർണ്ണസംഖ്യ t = tok;
        എങ്കിൽ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             നിർത്തുക;
	എങ്കിൽ (t == TOK_EOF) {
	     എങ്കിൽ (str || level > 0)
	       tcc_error("unexpected end of file");
	     അല്ലെങ്കിൽ
	       നിർത്തുക;
	}
	എങ്കിൽ (str)
	  tok_str_add_tok(*str);
	next();
	എങ്കിൽ (t == '{' || t == '(' || t == '[') {
	    level++;
	} അല്ലെങ്കിൽ എങ്കിൽ (t == '}' || t == ')' || t == ']') {
	    level--;
	    എങ്കിൽ (level == 0 && braces && t == '}')
	      നിർത്തുക;
	}
    }
    എങ്കിൽ (str)
	tok_str_add(*str, TOK_EOF);
}

#define വ്യഞ്ജകം_CONST 1
#define വ്യഞ്ജകം_ANY   2

സ്ഥിതം ശൂന്യം parse_init_elem(പൂർണ്ണസംഖ്യ വ്യഞ്ജകം_type)
{
    പൂർണ്ണസംഖ്യ saved_global_വ്യഞ്ജകം;
    തിരഞ്ഞെടുപ്പ്(വ്യഞ്ജകം_type) {
    അവസ്ഥ വ്യഞ്ജകം_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_വ്യഞ്ജകം = global_വ്യഞ്ജകം;
        global_വ്യഞ്ജകം = 1;
        വ്യഞ്ജകം_const1();
        global_വ്യഞ്ജകം = saved_global_വ്യഞ്ജകം;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        എങ്കിൽ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        നിർത്തുക;
    അവസ്ഥ വ്യഞ്ജകം_ANY:
        വ്യഞ്ജകം_eq();
        നിർത്തുക;
    }
}

#എങ്കിൽ 1
സ്ഥിതം ശൂന്യം init_assert(init_params *p, പൂർണ്ണസംഖ്യ offset)
{
    എങ്കിൽ (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#അല്ലെങ്കിൽ
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
സ്ഥിതം ശൂന്യം init_putz(init_params *p, unsigned long c, പൂർണ്ണസംഖ്യ size)
{
    init_assert(p, c + size);
    എങ്കിൽ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } അല്ലെങ്കിൽ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#എങ്കിൽ defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
സ്ഥിതം ശൂന്യം decl_design_delrels(Section *sec, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    എങ്കിൽ (!sec || !sec->reloc)
        തിരികെ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    ആകുമ്പോൾ (rel < rel_end) {
        എങ്കിൽ (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= വലുപ്പം *rel;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (rel2 != rel)
                memcpy(rel2, rel, വലുപ്പം *rel);
            ++rel2;
        }
        ++rel;
    }
}

സ്ഥിതം ശൂന്യം decl_design_flex(init_params *p, Sym *ref, പൂർണ്ണസംഖ്യ index)
{
    എങ്കിൽ (ref == p->flex_array_ref) {
        എങ്കിൽ (index >= ref->c)
            ref->c = index + 1;
    } അല്ലെങ്കിൽ എങ്കിൽ (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
സ്ഥിതം പൂർണ്ണസംഖ്യ decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, പൂർണ്ണസംഖ്യ flags, പൂർണ്ണസംഖ്യ al)
{
    Sym *s, *f;
    പൂർണ്ണസംഖ്യ index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    എങ്കിൽ (flags & DIF_HAVE_ELEM)
        പോകുക no_designator;

    എങ്കിൽ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        എങ്കിൽ (tok == ':')
            പോകുക struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ആകുമ്പോൾ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        എങ്കിൽ (tok == '[') {
            എങ്കിൽ (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = വ്യഞ്ജകം_const();
            എങ്കിൽ (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = വ്യഞ്ജകം_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            എങ്കിൽ (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            എങ്കിൽ (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } അല്ലെങ്കിൽ {
            പൂർണ്ണസംഖ്യ cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            എങ്കിൽ (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = ശൂന്യ;
    }
    എങ്കിൽ (!cur_field) {
        എങ്കിൽ (tok == '=') {
            next();
        } അല്ലെങ്കിൽ എങ്കിൽ (!gnu_ext) {
	    expect("=");
        }
    } അല്ലെങ്കിൽ {
    no_designator:
        എങ്കിൽ (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            എങ്കിൽ (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } അല്ലെങ്കിൽ {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ആകുമ്പോൾ (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            എങ്കിൽ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    എങ്കിൽ (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    എങ്കിൽ (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    എങ്കിൽ (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        പൂർണ്ണസംഖ്യ i;
        എങ്കിൽ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        എങ്കിൽ (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        അല്ലെങ്കിൽ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        വേണ്ടി (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    എങ്കിൽ (c - corig > al)
      al = c - corig;
    തിരികെ al;
}

സ്ഥിതം ശൂന്യം write_ldouble(unsigned അക്ഷരം *d, ശൂന്യം *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    എങ്കിൽ (LDOUBLE_SIZE >= 10) {
        ഇരട്ട b = *(long ഇരട്ട*)s;
        s = &b;
#അല്ലെങ്കിൽ
    എങ്കിൽ (വലുപ്പം (long ഇരട്ട) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        പൂർണ്ണസംഖ്യ e = m >> 48;
        പൂർണ്ണസംഖ്യ f = e >> 4 & 0x7FF;
        m <<= 11;
        എങ്കിൽ (0 == f) {
            എങ്കിൽ (0 == m)
                പോകുക set;
            വേണ്ടി (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        എങ്കിൽ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #എങ്കിൽ (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #അല്ലെങ്കിലെങ്കിൽ LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } അല്ലെങ്കിൽ {
    #എങ്കിൽ LDOUBLE_SIZE == 8
        /* long double -> double */
        ഇരട്ട b = *(long ഇരട്ട*)s;
        memcpy(d, &b, 8);
    #അല്ലെങ്കിലെങ്കിൽ (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #അല്ലെങ്കിലെങ്കിൽ (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        പൂർണ്ണസംഖ്യ e = *(uint16_t*)((അക്ഷരം*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #അല്ലെങ്കിലെങ്കിൽ (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((അക്ഷരം*)s + 6);
        പൂർണ്ണസംഖ്യ e = read16le((അക്ഷരം*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #അല്ലെങ്കിൽ
        /* unknown */
        എങ്കിൽ (വലുപ്പം (long ഇരട്ട) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
സ്ഥിതം ശൂന്യം init_putv(init_params *p, CType *type, unsigned long c)
{
    പൂർണ്ണസംഖ്യ bt;
    ശൂന്യം *ptr;
    CType dtype;
    പൂർണ്ണസംഖ്യ size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    എങ്കിൽ (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    എങ്കിൽ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        എങ്കിൽ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        എങ്കിൽ (NODATA_WANTED) {
            vtop--;
            തിരികെ;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	എങ്കിൽ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_മൂല്യം + (പൂർണ്ണസംഖ്യ)vtop->c.i, size);
	    എങ്കിൽ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		ആകുമ്പോൾ (relofs >= വലുപ്പം(*rel)) {
                    relofs -= വലുപ്പം(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    എങ്കിൽ (rel->r_offset >= esym->st_മൂല്യം + size)
		      തുടരുക;
		    എങ്കിൽ (rel->r_offset < esym->st_മൂല്യം)
		      നിർത്തുക;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_മൂല്യം,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#എങ്കിൽ PTR_SIZE == 8
				   rel->r_addend
#അല്ലെങ്കിൽ
				   0
#endif
				  );
		}
	    }
	} അല്ലെങ്കിൽ {
            എങ്കിൽ (type->t & VT_BITFIELD) {
                പൂർണ്ണസംഖ്യ bit_pos, bit_size, bits, n;
                unsigned അക്ഷരം *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned അക്ഷരം*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                ആകുമ്പോൾ (bit_size) {
                    n = 8 - bit_pos;
                    എങ്കിൽ (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } അല്ലെങ്കിൽ
            തിരഞ്ഞെടുപ്പ്(bt) {
	    അവസ്ഥ VT_BOOL:
		*(അക്ഷരം *)ptr = val != 0;
                നിർത്തുക;
	    അവസ്ഥ VT_BYTE:
		*(അക്ഷരം *)ptr = val;
		നിർത്തുക;
	    അവസ്ഥ VT_SHORT:
                write16le(ptr, val);
		നിർത്തുക;
	    അവസ്ഥ VT_FLOAT:
                write32le(ptr, val);
		നിർത്തുക;
	    അവസ്ഥ VT_DOUBLE:
                write64le(ptr, val);
		നിർത്തുക;
	    അവസ്ഥ VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		നിർത്തുക;

#എങ്കിൽ PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    അവസ്ഥ VT_LLONG:
	    അവസ്ഥ VT_PTR:
	        എങ്കിൽ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        അല്ലെങ്കിൽ
	          write64le(ptr, val);
	        നിർത്തുക;
            അവസ്ഥ VT_INT:
                write32le(ptr, val);
                നിർത്തുക;
#അല്ലെങ്കിൽ
	    അവസ്ഥ VT_LLONG:
                write64le(ptr, val);
                നിർത്തുക;
            അവസ്ഥ VT_PTR:
            അവസ്ഥ VT_INT:
	        എങ്കിൽ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        നിർത്തുക;
#endif
	    സ്ഥിരസ്ഥിതി:
                //tcc_internal_error("unexpected type");
                നിർത്തുക;
	    }
	}
        vtop--;
    } അല്ലെങ്കിൽ {
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
സ്ഥിതം ശൂന്യം decl_initializer(init_params *p, CType *type, unsigned long c, പൂർണ്ണസംഖ്യ flags)
{
    പൂർണ്ണസംഖ്യ len, n, no_oblock, i;
    പൂർണ്ണസംഖ്യ size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    എങ്കിൽ (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_വരി(tcc_state), tcc_tcov_check_വരി (tcc_state, 1);

    എങ്കിൽ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        പൂർണ്ണസംഖ്യ ncw_prev = nocode_wanted;
        എങ്കിൽ ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? വ്യഞ്ജകം_ANY : വ്യഞ്ജകം_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    എങ്കിൽ (type->t & VT_ARRAY) {
        no_oblock = 1;
        എങ്കിൽ (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        എങ്കിൽ ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#അല്ലെങ്കിൽ
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            എങ്കിൽ (size1 != (tok == TOK_STR ? 1 : വലുപ്പം(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ആകുമ്പോൾ (tok == TOK_STR || tok == TOK_LSTR) {
                എങ്കിൽ (initstr.size)
                  initstr.size -= size1;
                എങ്കിൽ (tok == TOK_STR)
                  len += tokc.str.size;
                അല്ലെങ്കിൽ
                  len += tokc.str.size / വലുപ്പം(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            എങ്കിൽ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                പോകുക do_init_array;
            }

            decl_design_flex(p, s, len);
            എങ്കിൽ (!(flags & DIF_SIZE_ONLY)) {
                പൂർണ്ണസംഖ്യ nb = n, ch;
                എങ്കിൽ (len < nb)
                    nb = len;
                എങ്കിൽ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                എങ്കിൽ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    എങ്കിൽ (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } അല്ലെങ്കിൽ {
                    വേണ്ടി(i=0;i<n;i++) {
                        എങ്കിൽ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          എങ്കിൽ (flags & DIF_CLEAR)
                            നിർത്തുക;
                          എങ്കിൽ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            നിർത്തുക;
                          }
                          ch = 0;
                        } അല്ലെങ്കിൽ എങ്കിൽ (size1 == 1)
                          ch = ((unsigned അക്ഷരം *)initstr.data)[i];
                        അല്ലെങ്കിൽ
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            എങ്കിൽ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } അല്ലെങ്കിൽ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            എങ്കിൽ (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ആകുമ്പോൾ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		എങ്കിൽ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    എങ്കിൽ (no_oblock && len >= n*size1)
		        നിർത്തുക;
		} അല്ലെങ്കിൽ {
		    എങ്കിൽ (s->type.t == VT_UNION)
		        f = ശൂന്യ;
		    അല്ലെങ്കിൽ
		        f = f->next;
		    എങ്കിൽ (no_oblock && f == ശൂന്യ)
		        നിർത്തുക;
		}

		എങ്കിൽ (tok == '}')
		    നിർത്തുക;
		skip(',');
	    }
        }
        എങ്കിൽ (!no_oblock)
            skip('}');

    } അല്ലെങ്കിൽ എങ്കിൽ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        പോകുക one_elem;

    } അല്ലെങ്കിൽ എങ്കിൽ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        എങ്കിൽ ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	പോകുക do_init_list;

    } അല്ലെങ്കിൽ എങ്കിൽ (tok == '{') {
        എങ്കിൽ (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } അല്ലെങ്കിൽ one_elem: എങ്കിൽ ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        എങ്കിൽ (flags & DIF_HAVE_ELEM)
            vpop();
        അല്ലെങ്കിൽ
            skip_or_save_block(ശൂന്യ);

    } അല്ലെങ്കിൽ {
	എങ്കിൽ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    എങ്കിൽ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? വ്യഞ്ജകം_ANY : വ്യഞ്ജകം_CONST);
	}
        എങ്കിൽ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        അല്ലെങ്കിൽ
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
സ്ഥിതം ശൂന്യം decl_initializer_alloc(CType *type, AttributeDef *ad, പൂർണ്ണസംഖ്യ r, 
                                   പൂർണ്ണസംഖ്യ has_init, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ scope)
{
    പൂർണ്ണസംഖ്യ size, align, addr;
    TokenString *init_str = ശൂന്യ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ശൂന്യ;
    പൂർണ്ണസംഖ്യ saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    പൂർണ്ണസംഖ്യ bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    എങ്കിൽ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        എങ്കിൽ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            എങ്കിൽ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                തിരികെ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    എങ്കിൽ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = ശൂന്യ;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    എങ്കിൽ (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        എങ്കിൽ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        എങ്കിൽ (IS_BT_ARRAY(type->t))
            type->ref = sym_തള്ളുക(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } അല്ലെങ്കിൽ എങ്കിൽ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        എങ്കിൽ (field) {
            ആകുമ്പോൾ (field->next)
                field = field->next;
            എങ്കിൽ (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    എങ്കിൽ (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        എങ്കിൽ (!has_init)
            പോകുക err_size;
        എങ്കിൽ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ആകുമ്പോൾ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } അല്ലെങ്കിൽ
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
        എങ്കിൽ (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        എങ്കിൽ (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    എങ്കിൽ (ad->a.aligned) {
	പൂർണ്ണസംഖ്യ speca = 1 << (ad->a.aligned - 1);
        എങ്കിൽ (speca > align)
            align = speca;
    } അല്ലെങ്കിൽ എങ്കിൽ (ad->a.packed) {
        align = 1;
    }

    എങ്കിൽ (!v && NODATA_WANTED)
        size = 0, align = 1;

    എങ്കിൽ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ശൂന്യ;
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        എങ്കിൽ (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    എങ്കിൽ (ad->asm_label) {
		പൂർണ്ണസംഖ്യ reg = asm_parse_regvar(ad->asm_label);
		എങ്കിൽ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_തള്ളുക(v, type, r, addr);
	    എങ്കിൽ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } അല്ലെങ്കിൽ {
            /* push local reference */
            vset(type, r, addr);
        }
    } അല്ലെങ്കിൽ {
        CType *tp = type;
        പൂർണ്ണസംഖ്യ is_const;

        ആകുമ്പോൾ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        എങ്കിൽ (!sec) {
            എങ്കിൽ (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } അല്ലെങ്കിൽ എങ്കിൽ (is_const) {
		sec = rodata_section;
            } അല്ലെങ്കിൽ എങ്കിൽ (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } അല്ലെങ്കിൽ എങ്കിൽ (tcc_state->nocommon)
                sec = bss_section;
        } അല്ലെങ്കിൽ എങ്കിൽ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            എങ്കിൽ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                എങ്കിൽ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (bcheck)
            size = size + 1; /* add padding */
#endif
        എങ്കിൽ (sec) {
	    addr = section_add(sec, size, align);
        } അല്ലെങ്കിൽ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        എങ്കിൽ (v) {
            എങ്കിൽ (!sym) {
                sym = sym_തള്ളുക(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ശൂന്യ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } അല്ലെങ്കിൽ {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        എങ്കിൽ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * വലുപ്പം(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    എങ്കിൽ (type->t & VT_VLA) {
        പൂർണ്ണസംഖ്യ a;

        എങ്കിൽ (has_init)
            tcc_error("variable length array cannot be initialized");

        എങ്കിൽ (NODATA_WANTED)
            പോകുക no_alloc;

        /* save before-VLA stack pointer if needed */
        എങ്കിൽ (cur_scope->vla.അക്കം == 0) {
            എങ്കിൽ (cur_scope->prev && cur_scope->prev->vla.അക്കം) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } അല്ലെങ്കിൽ {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#എങ്കിൽ defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.അക്കം++;
    } അല്ലെങ്കിൽ എങ്കിൽ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        എങ്കിൽ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    എങ്കിൽ (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
സ്ഥിതം ശൂന്യം func_vla_arg_code(Sym *arg)
{
    പൂർണ്ണസംഖ്യ align;
    TokenString *vla_array_tok = ശൂന്യ;

    എങ്കിൽ (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    എങ്കിൽ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

സ്ഥിതം ശൂന്യം func_vla_arg(Sym *sym)
{
    Sym *arg;

    വേണ്ടി (arg = sym->type.ref->next; arg; arg = arg->next)
        എങ്കിൽ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ byref)
{
    s = sym_find(s->v);
    എങ്കിൽ (!s) /* unnamed parameters, not enabled */
        തിരികെ ശൂന്യ;
    s->c = c;
    എങ്കിൽ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    തിരികെ s;
}

/* push parameters (and their types), last first */
സ്ഥിതം ശൂന്യം sym_തള്ളുക_params(Sym *ref)
{
    Sym *s = ref;
    ആകുമ്പോൾ (s->next)
        s = s->next;
    ആകുമ്പോൾ (s != ref) {
        എങ്കിൽ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_അട്ടി);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
സ്ഥിതം ശൂന്യം gen_function(Sym *sym)
{
    ഘടന scope f = { 0 };

    cur_scope = വേര്_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    എങ്കിൽ (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ശൂന്യ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    എങ്കിൽ (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    എങ്കിൽ (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_അട്ടി, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_തള്ളുക_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(ശൂന്യ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_എടുക്കുക(&local_അട്ടി, ശൂന്യ, 0);
    label_എടുക്കുക(&global_label_അട്ടി, ശൂന്യ, 0);
    sym_എടുക്കുക(&all_cleanups, ശൂന്യ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = ശൂന്യ;
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

സ്ഥിതം ശൂന്യം gen_inline_functions(TCCState *s)
{
    Sym *sym;
    പൂർണ്ണസംഖ്യ inline_generated, i;
    ഘടന InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    ചെയ്യുക {
        inline_generated = 0;
        വേണ്ടി (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            എങ്കിൽ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ശൂന്യ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } ആകുമ്പോൾ (inline_generated);
    tcc_close();
}

സ്ഥിതം ശൂന്യം free_inline_functions(TCCState *s)
{
    പൂർണ്ണസംഖ്യ i;
    /* free tokens of unused inline functions */
    വേണ്ടി (i = 0; i < s->nb_inline_fns; ++i) {
        ഘടന InlineFunc *fn = s->inline_fns[i];
        എങ്കിൽ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

സ്ഥിതം ശൂന്യം do_Static_assert(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ c;
    സ്ഥിരം അക്ഷരം *സന്ദേശം;

    next();
    skip('(');
    c = വ്യഞ്ജകം_const();
    സന്ദേശം = "_Static_assert fail";
    എങ്കിൽ (tok == ',') {
        next();
        സന്ദേശം = parse_mult_str("string constant")->data;
    }
    skip(')');
    എങ്കിൽ (c == 0)
        tcc_error("%s", സന്ദേശം);
    skip(';');
}

#ifdef TCC_TARGET_PE
സ്ഥിതം ശൂന്യം pe_check_linkage(CType *type, AttributeDef *ad)
{
    എങ്കിൽ (!ad->a.dllimport && !ad->a.dllexport)
        തിരികെ;
    എങ്കിൽ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    എങ്കിൽ (type->t & VT_TYPEDEF) {
        സ്ഥിരം അക്ഷരം *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } അല്ലെങ്കിൽ എങ്കിൽ (ad->a.dllimport) {
        എങ്കിൽ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        അല്ലെങ്കിൽ
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
സ്ഥിതം പൂർണ്ണസംഖ്യ decl(പൂർണ്ണസംഖ്യ l)
{
    പൂർണ്ണസംഖ്യ v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ആകുമ്പോൾ (1) {

        oldint = 0;
        എങ്കിൽ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            എങ്കിൽ (l == VT_JMP)
                തിരികെ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            എങ്കിൽ (tok == ';' && l != VT_CMP) {
                next();
                തുടരുക;
            }
            എങ്കിൽ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                തുടരുക;
            }
            എങ്കിൽ (l != VT_CONST)
                നിർത്തുക;
            എങ്കിൽ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                തുടരുക;
            }
            എങ്കിൽ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (tok != TOK_EOF)
                    expect("declaration");
                നിർത്തുക;
            }
        }

        എങ്കിൽ (tok == ';') {
            എങ്കിൽ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            അല്ലെങ്കിൽ എങ്കിൽ (IS_ENUM(btype.t))
                ; /* enum decl */
            അല്ലെങ്കിൽ
                tcc_warning("useless type defines no instances");
            എങ്കിൽ (l == VT_JMP)
                തിരികെ 1;
            next();
            തുടരുക;
        }

        ആകുമ്പോൾ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            എങ്കിൽ ((type.t & VT_BTYPE) == VT_FUNC) {
                എങ്കിൽ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                എങ്കിൽ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                എങ്കിൽ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    എങ്കിൽ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    അല്ലെങ്കിൽ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } അല്ലെങ്കിൽ എങ്കിൽ (oldint) {
                tcc_warning("type defaults to int");
            }

            എങ്കിൽ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #എങ്കിൽ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                എങ്കിൽ (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            എങ്കിൽ (tok == '{') {
                എങ്കിൽ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                എങ്കിൽ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                വേണ്ടി (sa = sym->type.ref; (sa = sa->next) != ശൂന്യ;) {
                    എങ്കിൽ (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    എങ്കിൽ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                എങ്കിൽ (sym->type.t & VT_INLINE) {
                    ഘടന InlineFunc *fn;
                    fn = tcc_malloc(വലുപ്പം *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } അല്ലെങ്കിൽ {
                    /* compute text section */
                    cur_text_section = text_section;
                    എങ്കിൽ (ad.section) {
                        cur_text_section = ad.section;
                        എങ്കിൽ (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                നിർത്തുക;
            } അല്ലെങ്കിൽ {
                has_init = 0;
		എങ്കിൽ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    വേണ്ടി (sym = func_vt.ref->next; sym; sym = sym->next)
			എങ്കിൽ ((sym->v & ~SYM_FIELD) == v)
			    പോകുക found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ശൂന്യ));
                found:
		    എങ്കിൽ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ശൂന്യ));
		    എങ്കിൽ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ശൂന്യ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} അല്ലെങ്കിൽ എങ്കിൽ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    എങ്കിൽ (sym && sym->sym_scope == local_scope) {
                        എങ്കിൽ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ശൂന്യ));
                        sym->type = type;
                    } അല്ലെങ്കിൽ {
                        sym = sym_തള്ളുക(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    എങ്കിൽ ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    എങ്കിൽ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} അല്ലെങ്കിൽ എങ്കിൽ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } അല്ലെങ്കിൽ {
                    r = 0;
                    എങ്കിൽ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } അല്ലെങ്കിൽ എങ്കിൽ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    എങ്കിൽ (tok == '=')
                        has_init = 1;

                    എങ്കിൽ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } അല്ലെങ്കിൽ {
                        എങ്കിൽ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        അല്ലെങ്കിൽ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        എങ്കിൽ (has_init)
                            next();
                        അല്ലെങ്കിൽ എങ്കിൽ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    എങ്കിൽ (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        എങ്കിൽ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_മൂല്യം, esym->st_size, 1);
                    }
                }
                എങ്കിൽ (tok != ',') {
                    എങ്കിൽ (l == VT_JMP)
                        തിരികെ has_init ? v : 1;
                    skip(';');
                    നിർത്തുക;
                }
                next();
            }
        }
    }
    തിരികെ 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
