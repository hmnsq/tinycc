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
#include "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA puur_naa_nka rsym, anon_sym, ind, loc;

ST_DATA Sym *global_stack;
ST_DATA Sym *local_stack;
ST_DATA Sym *define_stack;
ST_DATA Sym *global_label_stack;
ST_DATA Sym *local_label_stack;

static Sym *sym_free_first;
static void **sym_pools;
static puur_naa_nka nb_sym_pools;

static Sym *all_cleanups, *pending_gotos;
static puur_naa_nka local_scope;
ST_DATA var_na debug_modes;

ST_DATA SValue *vtop;
static SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA puur_naa_nka nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() ᱡᱩᱫᱤ(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA puur_naa_nka global_expr;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA puur_naa_nka func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA puur_naa_nka func_vc; /* stack address for implicit struct return storage */
ST_DATA puur_naa_nka func_ind; /* function start address */
static puur_naa_nka func_old;
ST_DATA const var_na *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
static CString initstr;

#ᱡᱩᱫᱤ PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#elif LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#ᱵᱟᱝ
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

static sa_nracanaa switch_t {
    sa_nracanaa case_t {
        int64_t v1, v2;
        puur_naa_nka ind, line;
    } **p; puur_naa_nka n; /* list of case ranges */
    puur_naa_nka def_sym; /* default symbol */
    puur_naa_nka nocode_wanted;
    puur_naa_nka *bsym;
    sa_nracanaa scope *scope;
    sa_nracanaa switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_NUMBER 8
/*list of temporary local variables on the stack in current function. */
static sa_nracanaa temp_local_variable {
	puur_naa_nka location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_NUMBER];
static puur_naa_nka nb_temp_local_vars;

static sa_nracanaa scope {
    sa_nracanaa scope *prev;
    sa_nracanaa { puur_naa_nka loc, locorig, num; } vla;
    sa_nracanaa { Sym *s; puur_naa_nka n; } cl;
    puur_naa_nka *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *root_scope;

typedef sa_nracanaa {
    Section *sec;
    puur_naa_nka local_offset;
    Sym *flex_array_ref;
} init_params;

#ᱡᱩᱫᱤ 1
#define precedence_parser
static void init_prec(void);
#endif

static void block(puur_naa_nka flags);
#define STMT_EXPR 1
#define STMT_COMPOUND 2

static void gen_cast(CType *type);
static void gen_cast_s(puur_naa_nka t);
static anta_hstha CType *pointed_type(CType *type);
static void check_restrict_type(CType *type);
static puur_naa_nka type_qualifiers(CType *type);
static void parse_btype_qualify(CType *type, puur_naa_nka qualifiers);
static puur_naa_nka is_compatible_types(CType *type1, CType *type2);
static puur_naa_nka parse_btype(CType *type, AttributeDef *ad, puur_naa_nka ignore_label);
static CType *type_decl(CType *type, AttributeDef *ad, puur_naa_nka *v, puur_naa_nka td);
static void parse_expr_type(CType *type);
static void init_putv(init_params *p, CType *type, unsigned long c);
static void decl_initializer(init_params *p, CType *type, unsigned long c, puur_naa_nka flags);
static void decl_initializer_alloc(CType *type, AttributeDef *ad, puur_naa_nka r, puur_naa_nka has_init, puur_naa_nka v, puur_naa_nka scope);
static puur_naa_nka decl(puur_naa_nka l);
static void expr_eq(void);
static void vpush_type_size(CType *type, puur_naa_nka *a);
static puur_naa_nka is_compatible_unqualified_types(CType *type1, CType *type2);
static anta_hstha int64_t expr_const64(void);
static void vpush64(puur_naa_nka ty, unsigned long long v);
static void vpush(CType *type);
static puur_naa_nka gvtst(puur_naa_nka inv, puur_naa_nka t);
static void gen_inline_functions(TCCState *s);
static void free_inline_functions(TCCState *s);
static void skip_or_save_block(TokenString **str);
static void gv_dup(void);
static puur_naa_nka get_temp_local_var(puur_naa_nka size,puur_naa_nka align,puur_naa_nka *r2);
static void cast_error(CType *st, CType *dt);
static void end_switch(void);
static void do_Static_assert(void);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC void gsym(puur_naa_nka t)
{
  ᱡᱩᱫᱤ (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
static puur_naa_nka gind()
{
  puur_naa_nka t = ind;
  CODE_ON();
  ᱡᱩᱫᱤ (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  ᱨᱩᱣᱟᱹᱲ t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
static void gjmp_addr_acs(puur_naa_nka t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
static puur_naa_nka gjmp_acs(puur_naa_nka t)
{
  t = gjmp(t);
  CODE_OFF();
  ᱨᱩᱣᱟᱹᱲ t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN puur_naa_nka is_float(puur_naa_nka t)
{
    puur_naa_nka bt = t & VT_BTYPE;
    ᱨᱩᱣᱟᱹᱲ bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

static anta_hstha puur_naa_nka is_integer_btype(puur_naa_nka bt)
{
    ᱨᱩᱣᱟᱹᱲ bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

static puur_naa_nka btype_size(puur_naa_nka bt)
{
    ᱨᱩᱣᱟᱹᱲ bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
static puur_naa_nka R_RET(puur_naa_nka t)
{
    ᱡᱩᱫᱤ (!is_float(t))
        ᱨᱩᱣᱟᱹᱲ REG_IRET;
#ifdef TCC_TARGET_X86_64
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LDOUBLE)
        ᱨᱩᱣᱟᱹᱲ TREG_ST0;
#elif defined TCC_TARGET_RISCV64
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LDOUBLE)
        ᱨᱩᱣᱟᱹᱲ REG_IRET;
#endif
    ᱨᱩᱣᱟᱹᱲ REG_FRET;
}

/* returns 2nd function return register, if any */
static puur_naa_nka R2_RET(puur_naa_nka t)
{
    t &= VT_BTYPE;
#ᱡᱩᱫᱤ PTR_SIZE == 4
    ᱡᱩᱫᱤ (t == VT_LLONG)
        ᱨᱩᱣᱟᱹᱲ REG_IRE2;
#elif defined TCC_TARGET_X86_64
    ᱡᱩᱫᱤ (t == VT_QLONG)
        ᱨᱩᱣᱟᱹᱲ REG_IRE2;
    ᱡᱩᱫᱤ (t == VT_QFLOAT)
        ᱨᱩᱣᱟᱹᱲ REG_FRE2;
#elif defined TCC_TARGET_RISCV64
    ᱡᱩᱫᱤ (t == VT_LDOUBLE)
        ᱨᱩᱣᱟᱹᱲ REG_IRE2;
#endif
    ᱨᱩᱣᱟᱹᱲ VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_WORDS(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
static void PUT_R_RET(SValue *sv, puur_naa_nka t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
static puur_naa_nka RC_RET(puur_naa_nka t)
{
    ᱨᱩᱣᱟᱹᱲ reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
static puur_naa_nka RC_TYPE(puur_naa_nka t)
{
    ᱡᱩᱫᱤ (!is_float(t))
        ᱨᱩᱣᱟᱹᱲ RC_INT;
#ifdef TCC_TARGET_X86_64
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LDOUBLE)
        ᱨᱩᱣᱟᱹᱲ RC_ST0;
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_QFLOAT)
        ᱨᱩᱣᱟᱹᱲ RC_FRET;
#elif defined TCC_TARGET_RISCV64
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LDOUBLE)
        ᱨᱩᱣᱟᱹᱲ RC_INT;
#endif
    ᱨᱩᱣᱟᱹᱲ RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
static puur_naa_nka RC2_TYPE(puur_naa_nka t, puur_naa_nka rc)
{
    ᱡᱩᱫᱤ (!USING_TWO_WORDS(t))
        ᱨᱩᱣᱟᱹᱲ 0;
#ifdef RC_IRE2
    ᱡᱩᱫᱤ (rc == RC_IRET)
        ᱨᱩᱣᱟᱹᱲ RC_IRE2;
#endif
#ifdef RC_FRE2
    ᱡᱩᱫᱤ (rc == RC_FRET)
        ᱨᱩᱣᱟᱹᱲ RC_FRE2;
#endif
    ᱡᱩᱫᱤ (rc & RC_FLOAT)
        ᱨᱩᱣᱟᱹᱲ RC_FLOAT;
    ᱨᱩᱣᱟᱹᱲ RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC puur_naa_nka ieee_finite(dviguu_na d)
{
    puur_naa_nka p[4];
    memcpy(p, &d, parimaa_na(dviguu_na));
    ᱨᱩᱣᱟᱹᱲ ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC void test_lvalue(void)
{
    ᱡᱩᱫᱤ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC void check_vstack(void)
{
    ᱡᱩᱫᱤ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (puur_naa_nka)(vtop - vstack + 1));
}

#ᱡᱩᱫᱤ 0
/* dump 'b' vstack entries starting with 'a'  */
void pv (const var_na *lbl, puur_naa_nka a, puur_naa_nka b)
{
    puur_naa_nka i;
    for (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (puur_naa_nka)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
static anta_hstha void psyms(const var_na *msg, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", msg);
    ᱡᱚᱠᱷᱚᱱ (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

static void type_to_str(var_na *buf, puur_naa_nka buf_size, CType *type, const var_na *varstr);

/* print type */
static void ptype(const var_na *msg, CType *type, puur_naa_nka v)
{
    var_na buf[500];
    type_to_str(buf, parimaa_na(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, NULL) : NULL);
    printf("%s : %s;\n", msg, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC void tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, parimaa_na *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ᱡᱩᱫᱤ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_push(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC puur_naa_nka tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_expr = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_NUM | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ᱡᱩᱫᱤ TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    ᱨᱩᱣᱟᱹᱲ 0;
}

ST_FUNC void tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_pop(&global_stack, NULL, 0);
    sym_pop(&local_stack, NULL, 0);
    /* free preprocessor macros */
    free_defines(NULL);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    ᱡᱚᱠᱷᱚᱱ (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = NULL;
    all_cleanups = NULL;
    pending_gotos = NULL;
    nb_temp_local_vars = 0;
    global_label_stack = NULL;
    local_label_stack = NULL;
    cur_text_section = NULL;
    sym_free_first = NULL;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ᱡᱩᱫᱤ (!s || !s->c)
    ᱨᱩᱣᱟᱹᱲ NULL;
  ᱨᱩᱣᱟᱹᱲ &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC void update_storage(Sym *sym)
{
    ElfSym *esym;
    puur_naa_nka sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ᱡᱩᱫᱤ (!esym)
        ᱨᱩᱣᱟᱹᱲ;

    ᱡᱩᱫᱤ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ᱡᱩᱫᱤ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    ᱵᱟᱝ ᱡᱩᱫᱤ (sym->a.weak)
        sym_bind = STB_WEAK;
    ᱵᱟᱝ
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ᱡᱩᱫᱤ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    ᱡᱩᱫᱤ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ᱡᱩᱫᱤ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#ᱡᱩᱫᱤ 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, NULL),
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

ST_FUNC void put_extern_sym2(Sym *sym, puur_naa_nka sh_num,
                            addr_t value, unsigned long size,
                            puur_naa_nka can_add_underscore)
{
    puur_naa_nka sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    const var_na *name;
    var_na buf1[256];

    ᱡᱩᱫᱤ (!sym->c) {
        name = get_tok_str(sym->v, NULL);
        t = sym->type.t;
        ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } ᱵᱟᱝ ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ᱡᱩᱫᱤ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (t & VT_TLS) {
            sym_type = STT_TLS;
        } ᱵᱟᱝ {
            sym_type = STT_OBJECT;
        }
        ᱡᱩᱫᱤ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        ᱵᱟᱝ
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        ᱡᱩᱫᱤ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ᱡᱩᱫᱤ (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            ᱡᱩᱫᱤ (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        ᱡᱩᱫᱤ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, NULL);
            can_add_underscore = 0;
        }

        ᱡᱩᱫᱤ (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, parimaa_na(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, value, size, info, other, sh_num, name);

        ᱡᱩᱫᱤ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_num, sym_bind, sym_type);

    } ᱵᱟᱝ {
        esym = elfsym(sym);
        esym->st_value = value;
        esym->st_size = size;
        esym->st_shndx = sh_num;
    }
    update_storage(sym);
}

ST_FUNC void put_extern_sym(Sym *sym, Section *s, addr_t value, unsigned long size)
{
    ᱡᱩᱫᱤ (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        ᱨᱩᱣᱟᱹᱲ;
    put_extern_sym2(sym, s ? s->sh_num : SHN_UNDEF, value, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC void greloca(Section *s, Sym *sym, unsigned long offset, puur_naa_nka type,
                     addr_t addend)
{
    puur_naa_nka c = 0;

    ᱡᱩᱫᱤ (nocode_wanted && s == cur_text_section)
        ᱨᱩᱣᱟᱹᱲ;

    ᱡᱩᱫᱤ (sym) {
        ᱡᱩᱫᱤ (0 == sym->c) {
            put_extern_sym(sym, NULL, 0, 0);
            ᱡᱩᱫᱤ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                ᱡᱚᱠᱷᱚᱱ (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#ᱡᱩᱫᱤ PTR_SIZE == 4
ST_FUNC void greloc(Section *s, Sym *sym, unsigned long offset, puur_naa_nka type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
static Sym *__sym_malloc(void)
{
    Sym *sym_pool, *sym, *last_sym;
    puur_naa_nka i;

    sym_pool = tcc_malloc(SYM_POOL_NB * parimaa_na(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    for(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    ᱨᱩᱣᱟᱹᱲ last_sym;
}

static anta_hstha Sym *sym_malloc(void)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    ᱡᱩᱫᱤ (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    ᱨᱩᱣᱟᱹᱲ sym;
#ᱵᱟᱝ
    sym = tcc_malloc(parimaa_na(Sym));
    ᱨᱩᱣᱟᱹᱲ sym;
#endif
}

ST_INLN void sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#ᱵᱟᱝ
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, puur_naa_nka v, puur_naa_nka t, puur_naa_nka c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, parimaa_na *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    ᱨᱩᱣᱟᱹᱲ s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, puur_naa_nka v)
{
    ᱡᱚᱠᱷᱚᱱ (s) {
        ᱡᱩᱫᱤ (s->v == v)
            ᱨᱩᱣᱟᱹᱲ s;
        s = s->prev;
    }
    ᱨᱩᱣᱟᱹᱲ NULL;
}

/* structure lookup */
ST_INLN Sym *struct_find(puur_naa_nka v)
{
    v -= TOK_IDENT;
    ᱡᱩᱫᱤ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ᱨᱩᱣᱟᱹᱲ NULL;
    ᱨᱩᱣᱟᱹᱲ table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(puur_naa_nka v)
{
    v -= TOK_IDENT;
    ᱡᱩᱫᱤ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ᱨᱩᱣᱟᱹᱲ NULL;
    ᱨᱩᱣᱟᱹᱲ table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
static anta_hstha void sym_link(Sym *s, puur_naa_nka yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ᱡᱩᱫᱤ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    ᱵᱟᱝ
        ps = &ts->sym_identifier;
    ᱡᱩᱫᱤ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } ᱵᱟᱝ {
        *ps = s->prev_tok;
    }
}

static anta_hstha puur_naa_nka sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    ᱨᱩᱣᱟᱹᱲ IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_push(puur_naa_nka v, CType *type, puur_naa_nka r, puur_naa_nka c)
{
    Sym *s, **ps;
    ᱡᱩᱫᱤ (local_stack)
        ps = &local_stack;
    ᱵᱟᱝ
        ps = &global_stack;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ᱡᱩᱫᱤ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ᱡᱩᱫᱤ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, NULL));
    }
    ᱨᱩᱣᱟᱹᱲ s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_push(puur_naa_nka v, puur_naa_nka t, puur_naa_nka c)
{
    Sym *s, **ps;
    s = sym_push2(&global_stack, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ᱡᱩᱫᱤ (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        ᱡᱚᱠᱷᱚᱱ (*ps != NULL && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    ᱨᱩᱣᱟᱹᱲ s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC void sym_pop(Sym **ptop, Sym *b, puur_naa_nka keep)
{
    Sym *s, *ss;
    puur_naa_nka v;

    s = *ptop;
    ᱡᱚᱠᱷᱚᱱ(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ᱡᱩᱫᱤ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	ᱡᱩᱫᱤ (!keep)
	    sym_free(s);
        s = ss;
    }
    ᱡᱩᱫᱤ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(puur_naa_nka v)
{
    v -= TOK_IDENT;
    ᱡᱩᱫᱤ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ᱨᱩᱣᱟᱹᱲ NULL;
    ᱨᱩᱣᱟᱹᱲ table_ident[v]->sym_label;
}

ST_FUNC Sym *label_push(Sym **ptop, puur_naa_nka v, puur_naa_nka flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    ᱡᱩᱫᱤ (ptop == &global_label_stack) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        ᱡᱚᱠᱷᱚᱱ (*ps != NULL)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    ᱨᱩᱣᱟᱹᱲ s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC void label_pop(Sym **ptop, Sym *slast, puur_naa_nka keep)
{
    Sym *s, *s1;
    for(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ᱡᱩᱫᱤ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, NULL));
        } ᱵᱟᱝ ᱡᱩᱫᱤ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, NULL));
        } ᱵᱟᱝ {
            ᱡᱩᱫᱤ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        ᱡᱩᱫᱤ (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ᱡᱩᱫᱤ (!keep)
            sym_free(s);
        ᱵᱟᱝ
            s->r = LABEL_GONE;
    }
    ᱡᱩᱫᱤ (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
static void vcheck_cmp(void)
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

    ᱡᱩᱫᱤ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

static void vsetc(CType *type, puur_naa_nka r, CValue *vc)
{
    ᱡᱩᱫᱤ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = NULL;
}

ST_FUNC void vswap(void)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC void vpop(void)
{
    puur_naa_nka v;
    v = vtop->r & VT_VALMASK;
#ᱡᱩᱫᱤ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    ᱡᱩᱫᱤ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } ᱵᱟᱝ
#endif
    ᱡᱩᱫᱤ (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
static void vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
static void vpush64(puur_naa_nka ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = NULL;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC void vpushi(puur_naa_nka v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
static void vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
static anta_hstha void vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC void vset(CType *type, puur_naa_nka r, puur_naa_nka v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

static void vseti(puur_naa_nka r, puur_naa_nka v)
{
    CType type;
    type.t = VT_INT;
    type.ref = NULL;
    vset(&type, r, v);
}

ST_FUNC void vpushv(SValue *v)
{
    ᱡᱩᱫᱤ (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

static void vdup(void)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC void vrotb(puur_naa_nka n)
{
    SValue tmp;
    ᱡᱩᱫᱤ (--n < 1)
        ᱨᱩᱣᱟᱹᱲ;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, parimaa_na *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC void vrott(puur_naa_nka n)
{
    SValue tmp;
    ᱡᱩᱫᱤ (--n < 1)
        ᱨᱩᱣᱟᱹᱲ;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, parimaa_na *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC void vrev(puur_naa_nka n)
{
    puur_naa_nka i;
    SValue tmp;
    vcheck_cmp();
    for (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC void vset_VT_CMP(puur_naa_nka op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
static void vset_VT_JMP(void)
{
    puur_naa_nka op = vtop->cmp_op;

    ᱡᱩᱫᱤ (vtop->jtrue || vtop->jfalse) {
        puur_naa_nka origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        puur_naa_nka inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } ᱵᱟᱝ {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ᱡᱩᱫᱤ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
static void gvtst_set(puur_naa_nka inv, puur_naa_nka t)
{
    puur_naa_nka *p;

    ᱡᱩᱫᱤ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ᱡᱩᱫᱤ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
static puur_naa_nka gvtst(puur_naa_nka inv, puur_naa_nka t)
{
    puur_naa_nka op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ᱡᱩᱫᱤ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ᱡᱩᱫᱤ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    ᱵᱟᱝ ᱡᱩᱫᱤ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    ᱨᱩᱣᱟᱹᱲ t;
}

/* generate a zero or nozero test */
static void gen_test_zero(puur_naa_nka op)
{
    ᱡᱩᱫᱤ (vtop->r == VT_CMP) {
        puur_naa_nka j;
        ᱡᱩᱫᱤ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } ᱵᱟᱝ {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC void vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    puur_naa_nka v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_push(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    ᱨᱩᱣᱟᱹᱲ sym;
}

/* push a reference to a section offset by adding a dummy symbol */
static void vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(puur_naa_nka v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    ᱡᱩᱫᱤ (!s) {
        /* push forward reference */
        s = global_identifier_push(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    ᱨᱩᱣᱟᱹᱲ s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(puur_naa_nka v)
{
    CType ct = { VT_ASM_FUNC, NULL };
    ᱨᱩᱣᱟᱹᱲ external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC void vpush_helper_func(puur_naa_nka v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
static void merge_symattr(sa_nracanaa SymAttr *sa, sa_nracanaa SymAttr *sa1)
{
    ᱡᱩᱫᱤ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ᱡᱩᱫᱤ (sa1->visibility != STV_DEFAULT) {
	puur_naa_nka vis = sa->visibility;
	ᱡᱩᱫᱤ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
static void merge_funcattr(sa_nracanaa FuncAttr *fa, sa_nracanaa FuncAttr *fa1)
{
    ᱡᱩᱫᱤ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ᱡᱩᱫᱤ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ᱡᱩᱫᱤ (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    ᱡᱩᱫᱤ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ᱡᱩᱫᱤ (fa1->func_ctor)
      fa->func_ctor = 1;
    ᱡᱩᱫᱤ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
static void merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    ᱡᱩᱫᱤ (ad1->section)
      ad->section = ad1->section;
    ᱡᱩᱫᱤ (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    ᱡᱩᱫᱤ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ᱡᱩᱫᱤ (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
static void patch_type(Sym *sym, CType *type)
{
    ᱡᱩᱫᱤ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ᱡᱩᱫᱤ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, NULL));
        sym->type.t &= ~VT_EXTERN;
    }

    ᱡᱩᱫᱤ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ᱡᱩᱫᱤ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ᱡᱩᱫᱤ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, NULL));

    } ᱵᱟᱝ ᱡᱩᱫᱤ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        puur_naa_nka static_proto = sym->type.t & VT_STATIC;
        puur_naa_nka ft1 = sym->type.ref->f.func_type;
        puur_naa_nka ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ᱡᱩᱫᱤ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, NULL));

        /* set 'inline' if both agree or if one has static */
        ᱡᱩᱫᱤ ((type->t | sym->type.t) & VT_INLINE) {
            ᱡᱩᱫᱤ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ᱡᱩᱫᱤ (0 == (type->t & VT_EXTERN)) {
            sa_nracanaa FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ᱡᱩᱫᱤ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } ᱵᱟᱝ {
            sym->type.t &= ~VT_INLINE | static_proto;
            ᱡᱩᱫᱤ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } ᱵᱟᱝ {
        ᱡᱩᱫᱤ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ᱡᱩᱫᱤ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, NULL));
    }
}

/* Merge some storage attributes.  */
static void patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ᱡᱩᱫᱤ (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    ᱡᱩᱫᱤ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, NULL));
#endif
    merge_symattr(&sym->a, &ad->a);
    ᱡᱩᱫᱤ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
static Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ᱡᱩᱫᱤ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    ᱨᱩᱣᱟᱹᱲ s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
static void move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    puur_naa_nka n, bt;

    bt = s->type.t & VT_BTYPE;
    ᱡᱩᱫᱤ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        ᱨᱩᱣᱟᱹᱲ;

    for (s = s->type.ref, n = 0; s; s = s->next) {
        for (lp = &local_stack; !!(l = *lp); lp = &l->prev) {
            ᱡᱩᱫᱤ (l == s) {
                *lp = s->prev;
                s->prev = global_stack, global_stack = s;
                ᱡᱩᱫᱤ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } ᱵᱟᱝ {
                    ᱡᱩᱫᱤ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                ᱡᱩᱫᱤ (bt != VT_PTR)
                    n = 1;
                bha_nga;
            }
        }
        ᱡᱩᱫᱤ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            bha_nga;
    }
}

/* define a new external reference to a symbol 'v' */
static Sym *external_sym(puur_naa_nka v, CType *type, puur_naa_nka r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    ᱡᱚᱠᱷᱚᱱ (s && s->sym_scope)
        s = s->prev_tok;

    ᱡᱩᱫᱤ (!s) {
        /* push forward reference */
        s = global_identifier_push(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } ᱵᱟᱝ {
        patch_storage(s, ad, type);
    }
    ᱡᱩᱫᱤ (local_stack) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_stack);
    }
    ᱨᱩᱣᱟᱹᱲ s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC void save_regs(puur_naa_nka n)
{
    SValue *p, *p1;
    for(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC void save_reg(puur_naa_nka r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC void save_reg_upstack(puur_naa_nka r, puur_naa_nka n)
{
    puur_naa_nka l, size, align, bt, r2;
    SValue *p, *p1, sv;

    ᱡᱩᱫᱤ ((r &= VT_VALMASK) >= VT_CONST)
        ᱨᱩᱣᱟᱹᱲ;
    ᱡᱩᱫᱤ (nocode_wanted)
        ᱨᱩᱣᱟᱹᱲ;
    l = r2 = 0;
    for(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ᱡᱩᱫᱤ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ᱡᱩᱫᱤ (!l) {
                bt = p->type.t & VT_BTYPE;
                ᱡᱩᱫᱤ (bt == VT_VOID)
                    continue;
                ᱡᱩᱫᱤ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = NULL;
                store(p->r & VT_VALMASK, &sv);
#ᱡᱩᱫᱤ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ᱡᱩᱫᱤ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                ᱡᱩᱫᱤ (p->r2 < VT_CONST && USING_TWO_WORDS(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ᱡᱩᱫᱤ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } ᱵᱟᱝ {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = NULL;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC puur_naa_nka get_reg_ex(puur_naa_nka rc, puur_naa_nka rc2)
{
    puur_naa_nka r;
    SValue *p;
    
    for(r=0;r<NB_REGS;r++) {
        ᱡᱩᱫᱤ (reg_classes[r] & rc2) {
            puur_naa_nka n;
            n=0;
            for(p = vstack; p <= vtop; p++) {
                ᱡᱩᱫᱤ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ᱡᱩᱫᱤ (n <= 1)
                ᱨᱩᱣᱟᱹᱲ r;
        }
    }
    ᱨᱩᱣᱟᱹᱲ get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC puur_naa_nka get_reg(puur_naa_nka rc)
{
    puur_naa_nka r;
    SValue *p;

    /* find a free register */
    for(r=0;r<NB_REGS;r++) {
        ᱡᱩᱫᱤ (reg_classes[r] & rc) {
            ᱡᱩᱫᱤ (nocode_wanted)
                ᱨᱩᱣᱟᱹᱲ r;
            for(p=vstack;p<=vtop;p++) {
                ᱡᱩᱫᱤ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    goto notfound;
            }
            ᱨᱩᱣᱟᱹᱲ r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    for(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ᱡᱩᱫᱤ (r < VT_CONST && (reg_classes[r] & rc))
            goto save_found;
        r = p->r & VT_VALMASK;
        ᱡᱩᱫᱤ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            ᱨᱩᱣᱟᱹᱲ r;
        }
    }
    /* Should never comes here */
    ᱨᱩᱣᱟᱹᱲ -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
static puur_naa_nka get_temp_local_var(puur_naa_nka size,puur_naa_nka align, puur_naa_nka *r2)
{
    puur_naa_nka i;
    sa_nracanaa temp_local_variable *temp_var;
    SValue *p;
    puur_naa_nka r;
    unsigned used = 0;

    /* mark locations that are still in use */
    for (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ᱡᱩᱫᱤ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ᱡᱩᱫᱤ (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_NUMBER)
	        used |= 1<<r;
	}
    }
    for (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	ᱡᱩᱫᱤ(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    ᱨᱩᱣᱟᱹᱲ temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    ᱡᱩᱫᱤ (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_NUMBER) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	goto ret_tmp;
    }
    *r2 = VT_CONST;
    ᱨᱩᱣᱟᱹᱲ loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
static void move_reg(puur_naa_nka r, puur_naa_nka s, puur_naa_nka t)
{
    SValue sv;

    ᱡᱩᱫᱤ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = NULL;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC void gaddrof(void)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ᱡᱩᱫᱤ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
static void gen_bounded_ptr_add(void)
{
    puur_naa_nka save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ᱡᱩᱫᱤ (save) {
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
    ᱡᱩᱫᱤ (nocode_wanted)
        ᱨᱩᱣᱟᱹᱲ;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - parimaa_na(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
static void gen_bounded_ptr_deref(void)
{
    addr_t func;
    puur_naa_nka size, align;
    ElfW_Rel *rel;
    Sym *sym;

    ᱡᱩᱫᱤ (nocode_wanted)
        ᱨᱩᱣᱟᱹᱲ;

    size = type_size(&vtop->type, &align);
    switch(size) {
    pak_sa  1: func = TOK___bound_ptr_indir1; bha_nga;
    pak_sa  2: func = TOK___bound_ptr_indir2; bha_nga;
    pak_sa  4: func = TOK___bound_ptr_indir4; bha_nga;
    pak_sa  8: func = TOK___bound_ptr_indir8; bha_nga;
    pak_sa 12: func = TOK___bound_ptr_indir12; bha_nga;
    pak_sa 16: func = TOK___bound_ptr_indir16; bha_nga;
    default:
        /* may happen with struct member access */
        ᱨᱩᱣᱟᱹᱲ;
    }
    sym = external_helper_sym(func);
    ᱡᱩᱫᱤ (!sym->c)
        put_extern_sym(sym, NULL, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
static void gbound(void)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ᱡᱩᱫᱤ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ᱡᱩᱫᱤ (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC void gbound_args(puur_naa_nka nb_args)
{
    puur_naa_nka i, v;
    SValue *sv;

    for (i = 1; i <= nb_args; ++i)
        ᱡᱩᱫᱤ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    ᱡᱩᱫᱤ (sv->r & VT_SYM) {
        v = sv->sym->v;
        ᱡᱩᱫᱤ (v == TOK_setjmp
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
        ᱡᱩᱫᱤ (v == TOK_alloca)
            func_bound_add_epilog = 1;
#ᱡᱩᱫᱤ TARGETOS_NetBSD
        ᱡᱩᱫᱤ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
static void add_local_bounds(Sym *s, Sym *e)
{
    for (; s != e; s = s->prev) {
        ᱡᱩᱫᱤ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          continue;
        /* Add arrays/structs/unions because we always take address */
        ᱡᱩᱫᱤ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            puur_naa_nka align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * parimaa_na(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
static void tcc_debug_end_scope(Sym *b, puur_naa_nka bounds)
{
#ifdef CONFIG_TCC_BCHECK
    ᱡᱩᱫᱤ (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_stack, b);
#endif
    tcc_add_debug_info (tcc_state, local_stack, b);
}

/* increment an lvalue pointer */
static void incr_offset(puur_naa_nka offset)
{
    puur_naa_nka t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

static void incr_bf_adr(puur_naa_nka o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
static void load_packed_bf(CType *type, puur_naa_nka bit_pos, puur_naa_nka bit_size)
{
    puur_naa_nka n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    do {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        ᱡᱩᱫᱤ (n > bit_size)
            n = bit_size;
        ᱡᱩᱫᱤ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        ᱡᱩᱫᱤ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ᱡᱩᱫᱤ (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } ᱡᱚᱠᱷᱚᱱ (bit_size);
    vswap(), vpop();
    ᱡᱩᱫᱤ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
static void store_packed_bf(puur_naa_nka bit_pos, puur_naa_nka bit_size)
{
    puur_naa_nka bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    do {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ᱡᱩᱫᱤ (bits)
            vpushi(bits), gen_op(TOK_SHR);
        ᱡᱩᱫᱤ (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        ᱡᱩᱫᱤ (n > bit_size)
            n = bit_size;
        ᱡᱩᱫᱤ (n < 8) {
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
    } ᱡᱚᱠᱷᱚᱱ (bit_size);
    vpop(), vpop();
}

static puur_naa_nka adjust_bf(SValue *sv, puur_naa_nka bit_pos, puur_naa_nka bit_size)
{
    puur_naa_nka t;
    ᱡᱩᱫᱤ (0 == sv->type.ref)
        ᱨᱩᱣᱟᱹᱲ 0;
    t = sv->type.ref->auxtype;
    ᱡᱩᱫᱤ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    ᱨᱩᱣᱟᱹᱲ t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC puur_naa_nka gv(puur_naa_nka rc)
{
    puur_naa_nka r, r2, r_ok, r2_ok, rc2, bt;
    puur_naa_nka bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    ᱡᱩᱫᱤ (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = NULL;
        type.t = vtop->type.t & VT_UNSIGNED;
        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        ᱵᱟᱝ
            type.t |= VT_INT;

        ᱡᱩᱫᱤ (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } ᱵᱟᱝ {
            puur_naa_nka bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } ᱵᱟᱝ {
        ᱡᱩᱫᱤ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            ᱡᱩᱫᱤ (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        ᱡᱩᱫᱤ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            ᱨᱩᱣᱟᱹᱲ vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        ᱡᱩᱫᱤ (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        ᱡᱩᱫᱤ (!r_ok || !r2_ok) {

            ᱡᱩᱫᱤ (!r_ok) {
                ᱡᱩᱫᱤ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                ᱵᱟᱝ
                    r = get_reg(rc);
            }

            ᱡᱩᱫᱤ (rc2) {
                puur_naa_nka load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                puur_naa_nka original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } ᱵᱟᱝ ᱡᱩᱫᱤ (vtop->r & VT_LVAL) {
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
                } ᱵᱟᱝ {
                    /* move registers */
                    ᱡᱩᱫᱤ (!r_ok)
                        load(r, vtop);
                    ᱡᱩᱫᱤ (r2_ok && vtop->r2 < VT_CONST)
                        goto done;
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
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        ᱡᱩᱫᱤ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    ᱨᱩᱣᱟᱹᱲ r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC void gv2(puur_naa_nka rc1, puur_naa_nka rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ᱡᱩᱫᱤ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ᱡᱩᱫᱤ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } ᱵᱟᱝ {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ᱡᱩᱫᱤ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ᱡᱩᱫᱤ PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC void lexpand(void)
{
    puur_naa_nka u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ᱡᱩᱫᱤ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } ᱵᱟᱝ {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#ᱡᱩᱫᱤ PTR_SIZE == 4
/* build a long long from two ints */
static void lbuild(puur_naa_nka t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
static void gv_dup(void)
{
    puur_naa_nka t, rc, r;

    t = vtop->type.t;
#ᱡᱩᱫᱤ PTR_SIZE == 4
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LLONG) {
        ᱡᱩᱫᱤ (t & VT_BITFIELD) {
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
        ᱨᱩᱣᱟᱹᱲ;
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

#ᱡᱩᱫᱤ PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
static void gen_opl(puur_naa_nka op)
{
    puur_naa_nka t, a, b, op1, c, i;
    puur_naa_nka func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    switch(op) {
    pak_sa '/':
    pak_sa TOK_PDIV:
        func = TOK___divdi3;
        goto gen_func;
    pak_sa TOK_UDIV:
        func = TOK___udivdi3;
        goto gen_func;
    pak_sa '%':
        func = TOK___moddi3;
        goto gen_mod_func;
    pak_sa TOK_UMOD:
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
        bha_nga;
    pak_sa '^':
    pak_sa '&':
    pak_sa '|':
    pak_sa '*':
    pak_sa '+':
    pak_sa '-':
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
        ᱡᱩᱫᱤ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            for(i=0;i<4;i++)
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
        } ᱵᱟᱝ ᱡᱩᱫᱤ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ᱡᱩᱫᱤ (op == '+')
                op1 = TOK_ADDC1;
            ᱵᱟᱝ
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } ᱵᱟᱝ {
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
        bha_nga;
    pak_sa TOK_SAR:
    pak_sa TOK_SHR:
    pak_sa TOK_SHL:
        ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (puur_naa_nka)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ᱡᱩᱫᱤ (op != TOK_SHL)
                vswap();
            ᱡᱩᱫᱤ (c >= 32) {
                /* stack: L H */
                vpop();
                ᱡᱩᱫᱤ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ᱡᱩᱫᱤ (op != TOK_SAR) {
                    vpushi(0);
                } ᱵᱟᱝ {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } ᱵᱟᱝ {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ᱡᱩᱫᱤ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                ᱵᱟᱝ
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ᱡᱩᱫᱤ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                ᱵᱟᱝ
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ᱡᱩᱫᱤ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } ᱵᱟᱝ {
            /* XXX: should provide a faster fallback on x86 ? */
            switch(op) {
            pak_sa TOK_SAR:
                func = TOK___ashrdi3;
                goto gen_func;
            pak_sa TOK_SHR:
                func = TOK___lshrdi3;
                goto gen_func;
            pak_sa TOK_SHL:
                func = TOK___ashldi3;
                goto gen_func;
            }
        }
        bha_nga;
    default:
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
        ᱡᱩᱫᱤ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ᱡᱩᱫᱤ (op1 == TOK_LT)
            op1 = TOK_LE;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_GT)
            op1 = TOK_GE;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ᱡᱩᱫᱤ (op == TOK_NE) {
            b = gvtst(0, 0);
        } ᱵᱟᱝ {
            a = gvtst(1, 0);
            ᱡᱩᱫᱤ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ᱡᱩᱫᱤ (op1 == TOK_LT)
            op1 = TOK_ULT;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_LE)
            op1 = TOK_ULE;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_GT)
            op1 = TOK_UGT;
        ᱵᱟᱝ ᱡᱩᱫᱤ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ᱡᱩᱫᱤ 0//def TCC_TARGET_I386
        ᱡᱩᱫᱤ (op == TOK_NE) { gsym(b); bha_nga; }
        ᱡᱩᱫᱤ (op == TOK_EQ) { gsym(a); bha_nga; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        bha_nga;
    }
}
#endif

/* normalize values */
static uint64_t value64(uint64_t l1, puur_naa_nka t)
{
    ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        ᱨᱩᱣᱟᱹᱲ l1;
    ᱵᱟᱝ ᱡᱩᱫᱤ (t & VT_UNSIGNED)
        ᱨᱩᱣᱟᱹᱲ (uint32_t)l1;
    ᱵᱟᱝ
        ᱨᱩᱣᱟᱹᱲ (uint32_t)l1 | -(l1 & 0x80000000);
}

static uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    ᱨᱩᱣᱟᱹᱲ (a ^ b) >> 63 ? -x : x;
}

static puur_naa_nka gen_opic_lt(uint64_t a, uint64_t b)
{
    ᱨᱩᱣᱟᱹᱲ (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
static void gen_opic(puur_naa_nka op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    puur_naa_nka t1 = v1->type.t & VT_BTYPE;
    puur_naa_nka t2 = v2->type.t & VT_BTYPE;
    puur_naa_nka c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    puur_naa_nka c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    puur_naa_nka shm = (t1 == VT_LLONG) ? 63 : 31;
    puur_naa_nka r;

    ᱡᱩᱫᱤ (c1 && c2) {
        switch(op) {
        pak_sa '+': l1 += l2; bha_nga;
        pak_sa '-': l1 -= l2; bha_nga;
        pak_sa '&': l1 &= l2; bha_nga;
        pak_sa '^': l1 ^= l2; bha_nga;
        pak_sa '|': l1 |= l2; bha_nga;
        pak_sa '*': l1 *= l2; bha_nga;

        pak_sa TOK_PDIV:
        pak_sa '/':
        pak_sa '%':
        pak_sa TOK_UDIV:
        pak_sa TOK_UMOD:
            /* if division by zero, generate explicit division */
            ᱡᱩᱫᱤ (l2 == 0) {
                ᱡᱩᱫᱤ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                goto general_case;
            }
            switch(op) {
            default: l1 = gen_opic_sdiv(l1, l2); bha_nga;
            pak_sa '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); bha_nga;
            pak_sa TOK_UDIV: l1 = l1 / l2; bha_nga;
            pak_sa TOK_UMOD: l1 = l1 % l2; bha_nga;
            }
            bha_nga;
        pak_sa TOK_SHL: l1 <<= (l2 & shm); bha_nga;
        pak_sa TOK_SHR: l1 >>= (l2 & shm); bha_nga;
        pak_sa TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            bha_nga;
            /* tests */
        pak_sa TOK_ULT: l1 = l1 < l2; bha_nga;
        pak_sa TOK_UGE: l1 = l1 >= l2; bha_nga;
        pak_sa TOK_EQ: l1 = l1 == l2; bha_nga;
        pak_sa TOK_NE: l1 = l1 != l2; bha_nga;
        pak_sa TOK_ULE: l1 = l1 <= l2; bha_nga;
        pak_sa TOK_UGT: l1 = l1 > l2; bha_nga;
        pak_sa TOK_LT: l1 = gen_opic_lt(l1, l2); bha_nga;
        pak_sa TOK_GE: l1 = !gen_opic_lt(l1, l2); bha_nga;
        pak_sa TOK_LE: l1 = !gen_opic_lt(l2, l1); bha_nga;
        pak_sa TOK_GT: l1 = gen_opic_lt(l2, l1); bha_nga;
            /* logical */
        pak_sa TOK_LAND: l1 = l1 && l2; bha_nga;
        pak_sa TOK_LOR: l1 = l1 || l2; bha_nga;
        default:
            goto general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } ᱵᱟᱝ {
        /* if commutative ops, put c2 as constant */
        ᱡᱩᱫᱤ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ᱡᱩᱫᱤ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ᱡᱩᱫᱤ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ᱡᱩᱫᱤ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                puur_naa_nka n = -1;
                ᱡᱩᱫᱤ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    goto general_case;
                }
                ᱡᱚᱠᱷᱚᱱ (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ᱡᱩᱫᱤ (op == '*')
                    op = TOK_SHL;
                ᱵᱟᱝ ᱡᱩᱫᱤ (op == TOK_PDIV)
                    op = TOK_SAR;
                ᱵᱟᱝ
                    op = TOK_SHR;
            }
            goto general_case;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ᱡᱩᱫᱤ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ᱡᱩᱫᱤ ((puur_naa_nka)l2 != l2)
	        goto general_case;
            vtop--;
            vtop->c.i = l2;
        } ᱵᱟᱝ {
        general_case:
                /* call low level op generator */
                ᱡᱩᱫᱤ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                ᱵᱟᱝ
                    gen_opi(op);
        }
        ᱡᱩᱫᱤ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ᱡᱩᱫᱤ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#elif defined TCC_TARGET_ARM
void gen_negf(puur_naa_nka op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#ᱵᱟᱝ
/* XXX: implement in gen_opf() for other backends too */
void gen_negf(puur_naa_nka op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    puur_naa_nka align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ᱡᱩᱫᱤ defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ᱡᱩᱫᱤ (bt == VT_LDOUBLE)
        size = 10;
#endif
    ᱡᱩᱫᱤ (nocode_wanted) /* save_reg() wont work */
        goto gv2;
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
static void gen_opif(puur_naa_nka op)
{
    puur_naa_nka c1, c2, i, bt;
    SValue *v1, *v2;
#ᱡᱩᱫᱤ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    ca_ncala
#endif
    long dviguu_na f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ᱡᱩᱫᱤ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ᱡᱩᱫᱤ (c1 && c2) {
        ᱡᱩᱫᱤ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } ᱵᱟᱝ {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ᱡᱩᱫᱤ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            goto general_case;
        switch(op) {
        pak_sa '+': f1 += f2; bha_nga;
        pak_sa '-': f1 -= f2; bha_nga;
        pak_sa '*': f1 *= f2; bha_nga;
        pak_sa '/': 
            ᱡᱩᱫᱤ (f2 == 0.0) {
                sa_ngha { float f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ᱡᱩᱫᱤ (!CONST_WANTED)
                    goto general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ᱡᱩᱫᱤ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                ᱵᱟᱝ
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                bha_nga;
            }
            f1 /= f2;
            bha_nga;
        pak_sa TOK_NEG:
            f1 = -f1;
            goto unary_result;
        pak_sa TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            ᱨᱩᱣᱟᱹᱲ;
        pak_sa TOK_NE:
            i = f1 != f2;
	    goto make_int;
        pak_sa TOK_LT:
            i = f1 < f2;
	    goto make_int;
        pak_sa TOK_GE:
            i = f1 >= f2;
	    goto make_int;
        pak_sa TOK_LE:
            i = f1 <= f2;
	    goto make_int;
        pak_sa TOK_GT:
            i = f1 > f2;
	    goto make_int;
        default:
            goto general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        ᱡᱩᱫᱤ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } ᱵᱟᱝ {
            v1->c.ld = f1;
        }
    } ᱵᱟᱝ {
    general_case:
        ᱡᱩᱫᱤ (op == TOK_NEG) {
            gen_negf(op);
        } ᱵᱟᱝ {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
static void type_to_str(var_na *buf, puur_naa_nka buf_size,
                 CType *type, const var_na *varstr)
{
    puur_naa_nka bt, v, t;
    Sym *s, *sa;
    var_na buf1[256];
    const var_na *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ᱡᱩᱫᱤ (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    ᱡᱩᱫᱤ (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    ᱡᱩᱫᱤ (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    ᱡᱩᱫᱤ (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    ᱡᱩᱫᱤ (bt != VT_PTR) {
        ᱡᱩᱫᱤ (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        ᱡᱩᱫᱤ (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        ᱡᱩᱫᱤ (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    ᱡᱩᱫᱤ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    switch(bt) {
    pak_sa VT_VOID:
        tstr = "void";
        goto add_tstr;
    pak_sa VT_BOOL:
        tstr = "_Bool";
        goto add_tstr;
    pak_sa VT_BYTE:
        tstr = "char";
        goto add_tstr;
    pak_sa VT_SHORT:
        tstr = "short";
        goto add_tstr;
    pak_sa VT_INT:
        tstr = "int";
        goto maybe_long;
    pak_sa VT_LLONG:
        tstr = "long long";
    maybe_long:
        ᱡᱩᱫᱤ (t & VT_LONG)
            tstr = "long";
        ᱡᱩᱫᱤ (!IS_ENUM(t))
            goto add_tstr;
        tstr = "enum ";
        goto tstruct;
    pak_sa VT_FLOAT:
        tstr = "float";
        goto add_tstr;
    pak_sa VT_DOUBLE:
        tstr = "double";
        ᱡᱩᱫᱤ (!(t & VT_LONG))
            goto add_tstr;
    pak_sa VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        bha_nga;
    pak_sa VT_STRUCT:
        tstr = "struct ";
        ᱡᱩᱫᱤ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ᱡᱩᱫᱤ (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        ᱵᱟᱝ
            pstrcat(buf, buf_size, get_tok_str(v, NULL));
        bha_nga;
    pak_sa VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ᱡᱩᱫᱤ (varstr && '*' == *varstr) {
            pstrcat(buf1, parimaa_na(buf1), "(");
            pstrcat(buf1, parimaa_na(buf1), varstr);
            pstrcat(buf1, parimaa_na(buf1), ")");
        }
        pstrcat(buf1, parimaa_na(buf1), "(");
        sa = s->next;
        ᱡᱚᱠᱷᱚᱱ (sa != NULL) {
            var_na buf2[256];
            type_to_str(buf2, parimaa_na(buf2), &sa->type, NULL);
            pstrcat(buf1, parimaa_na(buf1), buf2);
            sa = sa->next;
            ᱡᱩᱫᱤ (sa)
                pstrcat(buf1, parimaa_na(buf1), ", ");
        }
        ᱡᱩᱫᱤ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, parimaa_na(buf1), ", ...");
        pstrcat(buf1, parimaa_na(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        goto no_var;
    pak_sa VT_PTR:
        s = type->ref;
        ᱡᱩᱫᱤ (t & (VT_ARRAY|VT_VLA)) {
            ᱡᱩᱫᱤ (varstr && '*' == *varstr)
                snprintf(buf1, parimaa_na(buf1), "(%s)[%d]", varstr, s->c);
            ᱵᱟᱝ
                snprintf(buf1, parimaa_na(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            goto no_var;
        }
        pstrcpy(buf1, parimaa_na(buf1), "*");
        ᱡᱩᱫᱤ (t & VT_RESTRICT)
            pstrcat(buf1, parimaa_na(buf1), "restrict ");
        ᱡᱩᱫᱤ (t & VT_CONSTANT)
            pstrcat(buf1, parimaa_na(buf1), "const ");
        ᱡᱩᱫᱤ (t & VT_VOLATILE)
            pstrcat(buf1, parimaa_na(buf1), "volatile ");
        ᱡᱩᱫᱤ (varstr)
            pstrcat(buf1, parimaa_na(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        goto no_var;
    }
    ᱡᱩᱫᱤ (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

static void type_incompatibility_error(CType* st, CType* dt, const var_na* fmt)
{
    var_na buf1[256], buf2[256];
    type_to_str(buf1, parimaa_na(buf1), st, NULL);
    type_to_str(buf2, parimaa_na(buf2), dt, NULL);
    tcc_error(fmt, buf1, buf2);
}

static void type_incompatibility_warning(CType* st, CType* dt, const var_na* fmt)
{
    var_na buf1[256], buf2[256];
    type_to_str(buf1, parimaa_na(buf1), st, NULL);
    type_to_str(buf2, parimaa_na(buf2), dt, NULL);
    tcc_warning(fmt, buf1, buf2);
}

static puur_naa_nka pointed_size(CType *type)
{
    puur_naa_nka align;
    ᱨᱩᱣᱟᱹᱲ type_size(pointed_type(type), &align);
}

static anta_hstha puur_naa_nka is_null_pointer(SValue *p)
{
    ᱡᱩᱫᱤ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        ᱨᱩᱣᱟᱹᱲ 0;
    ᱨᱩᱣᱟᱹᱲ ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
static puur_naa_nka is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ᱡᱩᱫᱤ (s1->f.func_call != s2->f.func_call)
        ᱨᱩᱣᱟᱹᱲ 0;
    ᱡᱩᱫᱤ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        ᱨᱩᱣᱟᱹᱲ 0;
    for (;;) {
        ᱡᱩᱫᱤ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            ᱨᱩᱣᱟᱹᱲ 0;
        ᱡᱩᱫᱤ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            ᱨᱩᱣᱟᱹᱲ 1;
        s1 = s1->next;
        s2 = s2->next;
        ᱡᱩᱫᱤ (!s1)
            ᱨᱩᱣᱟᱹᱲ !s2;
        ᱡᱩᱫᱤ (!s2)
            ᱨᱩᱣᱟᱹᱲ 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
static puur_naa_nka compare_types(CType *type1, CType *type2, puur_naa_nka unqualified)
{
    puur_naa_nka bt1, t1, t2;

    ᱡᱩᱫᱤ (IS_ENUM(type1->t)) {
        ᱡᱩᱫᱤ (IS_ENUM(type2->t))
            ᱨᱩᱣᱟᱹᱲ type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ᱡᱩᱫᱤ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ᱡᱩᱫᱤ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ᱡᱩᱫᱤ (t1 != t2)
        ᱨᱩᱣᱟᱹᱲ 0;

    ᱡᱩᱫᱤ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            ᱨᱩᱣᱟᱹᱲ 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ᱡᱩᱫᱤ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ᱡᱩᱫᱤ (unqualified && (t1 & VT_ARRAY))
            ᱨᱩᱣᱟᱹᱲ compare_types(type1, type2, 1);
        ᱨᱩᱣᱟᱹᱲ is_compatible_types(type1, type2);
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_STRUCT) {
        ᱨᱩᱣᱟᱹᱲ (type1->ref == type2->ref);
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_FUNC) {
        ᱨᱩᱣᱟᱹᱲ is_compatible_func(type1, type2);
    } ᱵᱟᱝ {
        ᱨᱩᱣᱟᱹᱲ 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
static puur_naa_nka combine_types(CType *dest, SValue *op1, SValue *op2, puur_naa_nka op)
{
    CType *type1, *type2, type;
    puur_naa_nka t1, t2, bt1, bt2;
    puur_naa_nka ret = 1;

    /* for shifts, 'combine' only left operand */
    ᱡᱩᱫᱤ (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = NULL;

    ᱡᱩᱫᱤ (bt1 == VT_VOID || bt2 == VT_VOID) {
        ᱡᱩᱫᱤ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_PTR || bt2 == VT_PTR) {
        ᱡᱩᱫᱤ (op == '+') {
          ᱡᱩᱫᱤ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        ᱵᱟᱝ ᱡᱩᱫᱤ (is_null_pointer (op2)) type = *type1;
        ᱵᱟᱝ ᱡᱩᱫᱤ (is_null_pointer (op1)) type = *type2;
        ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ᱡᱩᱫᱤ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            ᱵᱟᱝ ᱡᱩᱫᱤ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } ᱵᱟᱝ {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            puur_naa_nka pbt1 = pt1->t & VT_BTYPE;
            puur_naa_nka pbt2 = pt2->t & VT_BTYPE;
            puur_naa_nka newquals, copied = 0;
            ᱡᱩᱫᱤ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ᱡᱩᱫᱤ (op != '?' && op != CMP_OP)
                  ret = 0;
                ᱵᱟᱝ
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ᱡᱩᱫᱤ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ᱡᱩᱫᱤ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_push(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ᱡᱩᱫᱤ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ᱡᱩᱫᱤ (!copied)
                      type.ref = sym_push(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_push(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ᱡᱩᱫᱤ (op == CMP_OP)
          type.t = VT_SIZE_T;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ᱡᱩᱫᱤ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (is_float(bt1) || is_float(bt2)) {
        ᱡᱩᱫᱤ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } ᱵᱟᱝ {
            type.t = VT_FLOAT;
        }
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ᱡᱩᱫᱤ (bt1 == VT_LLONG)
          type.t &= t1;
        ᱡᱩᱫᱤ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ᱡᱩᱫᱤ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } ᱵᱟᱝ {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ᱡᱩᱫᱤ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ᱡᱩᱫᱤ (dest)
      *dest = type;
    ᱨᱩᱣᱟᱹᱲ ret;
}

/* generic gen_op: handles types problems */
ST_FUNC void gen_op(puur_naa_nka op)
{
    puur_naa_nka t1, t2, bt1, bt2, t;
    CType type1, combtype;
    puur_naa_nka op_class = op;

    ᱡᱩᱫᱤ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    ᱵᱟᱝ ᱡᱩᱫᱤ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ᱡᱩᱫᱤ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ᱡᱩᱫᱤ (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	ᱡᱩᱫᱤ (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	goto redo;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        puur_naa_nka align;
        ᱡᱩᱫᱤ (op_class == CMP_OP)
            goto std_op;
        /* if both pointers, then it must be the '-' op */
        ᱡᱩᱫᱤ (bt1 == VT_PTR && bt2 == VT_PTR) {
            ᱡᱩᱫᱤ (op != '-')
                goto op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } ᱵᱟᱝ {
            /* exactly one pointer : must be '+' or '-'. */
            ᱡᱩᱫᱤ (op != '-' && op != '+')
                goto op_err;
            /* Put pointer as first operand */
            ᱡᱩᱫᱤ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ᱡᱩᱫᱤ PTR_SIZE == 4
            ᱡᱩᱫᱤ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            ᱡᱩᱫᱤ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ᱡᱩᱫᱤ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } ᱵᱟᱝ
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } ᱵᱟᱝ {
        /* floats can only be used for a few operations */
        ᱡᱩᱫᱤ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            goto op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ᱡᱩᱫᱤ (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ᱡᱩᱫᱤ (t & VT_UNSIGNED) {
            ᱡᱩᱫᱤ (op == TOK_SAR)
                op = TOK_SHR;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == '/')
                op = TOK_UDIV;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == '%')
                op = TOK_UMOD;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == TOK_LT)
                op = TOK_ULT;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == TOK_GT)
                op = TOK_UGT;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == TOK_LE)
                op = TOK_ULE;
            ᱵᱟᱝ ᱡᱩᱫᱤ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ᱡᱩᱫᱤ (is_float(t))
            gen_opif(op);
        ᱵᱟᱝ
            gen_opic(op);
        ᱡᱩᱫᱤ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } ᱵᱟᱝ {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ᱡᱩᱫᱤ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ᱡᱩᱫᱤ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#ᱵᱟᱝ
/* generic itof for unsigned long long case */
static void gen_cvt_itof1(puur_naa_nka t)
{
    ᱡᱩᱫᱤ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ᱡᱩᱫᱤ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ᱡᱩᱫᱤ LDOUBLE_SIZE != 8
        ᱵᱟᱝ ᱡᱩᱫᱤ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        ᱵᱟᱝ
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ᱵᱟᱝ {
        gen_cvt_itof(t);
    }
}
#endif

#ᱡᱩᱫᱤ defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#ᱵᱟᱝ
/* generic ftoi for unsigned long long case */
static void gen_cvt_ftoi1(puur_naa_nka t)
{
    puur_naa_nka st;
    ᱡᱩᱫᱤ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ᱡᱩᱫᱤ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ᱡᱩᱫᱤ LDOUBLE_SIZE != 8
        ᱵᱟᱝ ᱡᱩᱫᱤ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        ᱵᱟᱝ
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } ᱵᱟᱝ {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
static void force_charshort_cast(void)
{
    puur_naa_nka sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    puur_naa_nka dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

static void gen_cast_s(puur_naa_nka t)
{
    CType type;
    type.t = t;
    type.ref = NULL;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
static void gen_cast(CType *type)
{
    puur_naa_nka sbt, dbt, sf, df, c;
    puur_naa_nka dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    ᱡᱩᱫᱤ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ᱡᱩᱫᱤ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ᱡᱩᱫᱤ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ᱡᱩᱫᱤ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ᱡᱩᱫᱤ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ᱡᱩᱫᱤ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            goto done;
        }
        ᱡᱩᱫᱤ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ᱡᱩᱫᱤ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ᱡᱩᱫᱤ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            ᱵᱟᱝ ᱡᱩᱫᱤ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ᱡᱩᱫᱤ (df) {
                ᱡᱩᱫᱤ (sbt_bt == VT_LLONG) {
                    ᱡᱩᱫᱤ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    ᱵᱟᱝ
                        vtop->c.ld = -(long dviguu_na)-vtop->c.i;
                } ᱵᱟᱝ ᱡᱩᱫᱤ(!sf) {
                    ᱡᱩᱫᱤ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    ᱵᱟᱝ
                        vtop->c.ld = -(long dviguu_na)-(uint32_t)vtop->c.i;
                }

                ᱡᱩᱫᱤ (dbt == VT_FLOAT)
                    vtop->c.f = (float)vtop->c.ld;
                ᱵᱟᱝ ᱡᱩᱫᱤ (dbt == VT_DOUBLE)
                    vtop->c.d = (dviguu_na)vtop->c.ld;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ(sf) {
                    ᱡᱩᱫᱤ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    ᱵᱟᱝ
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                ᱵᱟᱝ ᱡᱩᱫᱤ (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                ᱵᱟᱝ ᱡᱩᱫᱤ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                ᱵᱟᱝ
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ᱡᱩᱫᱤ (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                ᱵᱟᱝ ᱡᱩᱫᱤ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                ᱵᱟᱝ {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ᱡᱩᱫᱤ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            goto done;

        } ᱵᱟᱝ ᱡᱩᱫᱤ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            goto done;
        }

        /* cannot generate code for global or static initializers */
        ᱡᱩᱫᱤ (nocode_wanted & DATA_ONLY_WANTED) {
            ᱡᱩᱫᱤ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            goto done;
        }

        /* non constant case: generate code */
        ᱡᱩᱫᱤ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            goto done;
        }

        ᱡᱩᱫᱤ (sf || df) {
            ᱡᱩᱫᱤ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } ᱵᱟᱝ ᱡᱩᱫᱤ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } ᱵᱟᱝ {
                /* convert fp to int */
                sbt = dbt;
                ᱡᱩᱫᱤ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                goto again; /* may need char/short cast */
            }
            goto done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        ᱡᱩᱫᱤ (ds == 0 || ss == 0)
            goto error;

        /* same size and no sign conversion needed */
        ᱡᱩᱫᱤ (ds == ss && ds >= 4)
            goto done;
        ᱡᱩᱫᱤ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ᱡᱩᱫᱤ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        ᱡᱩᱫᱤ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ᱡᱩᱫᱤ (ds <= ss)
                goto done;
            /* ss <= 4 here */
            ᱡᱩᱫᱤ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                goto done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ᱡᱩᱫᱤ PTR_SIZE == 4
        ᱡᱩᱫᱤ (ds == 8) {
            /* generate high word */
            ᱡᱩᱫᱤ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } ᱵᱟᱝ {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } ᱵᱟᱝ ᱡᱩᱫᱤ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#elif PTR_SIZE == 8
        ᱡᱩᱫᱤ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ᱡᱩᱫᱤ (sbt & VT_UNSIGNED) {
#ᱡᱩᱫᱤ defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#ᱵᱟᱝ
                goto done;
#endif
            } ᱵᱟᱝ {
                gen_cvt_sxtw();
                goto done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ᱡᱩᱫᱤ !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } ᱵᱟᱝ {
            ss = 4;
        }
#endif

        ᱡᱩᱫᱤ (ds >= ss)
            goto done;
#ᱡᱩᱫᱤ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ᱡᱩᱫᱤ (ss == 4) {
        gen_cvt_csti(dbt);
        goto done;
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
ST_FUNC puur_naa_nka type_size(CType *type, puur_naa_nka *a)
{
    Sym *s;
    puur_naa_nka bt;

    bt = type->t & VT_BTYPE;
    ᱡᱩᱫᱤ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        ᱨᱩᱣᱟᱹᱲ s->c;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_PTR) {
        ᱡᱩᱫᱤ (type->t & VT_ARRAY) {
            puur_naa_nka ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            ᱡᱩᱫᱤ (s->c < 0)
                ᱨᱩᱣᱟᱹᱲ s->c;
            ᱨᱩᱣᱟᱹᱲ ts * s->c;
        } ᱵᱟᱝ {
            *a = PTR_SIZE;
            ᱨᱩᱣᱟᱹᱲ PTR_SIZE;
        }
    } ᱵᱟᱝ ᱡᱩᱫᱤ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        ᱨᱩᱣᱟᱹᱲ -1; /* incomplete enum */
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        ᱨᱩᱣᱟᱹᱲ LDOUBLE_SIZE;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_DOUBLE || bt == VT_LLONG) {
#ᱡᱩᱫᱤ (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#ᱵᱟᱝ
        *a = 8;
#endif
        ᱨᱩᱣᱟᱹᱲ 8;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        ᱨᱩᱣᱟᱹᱲ 4;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_SHORT) {
        *a = 2;
        ᱨᱩᱣᱟᱹᱲ 2;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        ᱨᱩᱣᱟᱹᱲ 16;
    } ᱵᱟᱝ {
        /* char, void, function, _Bool */
        *a = 1;
        ᱨᱩᱣᱟᱹᱲ 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
static void vpush_type_size(CType *type, puur_naa_nka *a)
{
    ᱡᱩᱫᱤ (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } ᱵᱟᱝ {
        puur_naa_nka size = type_size(type, a);
        ᱡᱩᱫᱤ (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
static anta_hstha CType *pointed_type(CType *type)
{
    ᱨᱩᱣᱟᱹᱲ &type->ref->type;
}

static void check_restrict_type(CType *type)
{
    ᱡᱚᱠᱷᱚᱱ ((type->t & VT_BTYPE) == VT_PTR) {
        ᱡᱩᱫᱤ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ᱡᱩᱫᱤ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
static puur_naa_nka type_qualifiers(CType *type)
{
    ᱡᱚᱠᱷᱚᱱ (type->t & VT_ARRAY)
        type = pointed_type(type);
    ᱨᱩᱣᱟᱹᱲ type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC void mk_pointer(CType *type)
{
    Sym *s;
    s = sym_push(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
static puur_naa_nka is_compatible_types(CType *type1, CType *type2)
{
    ᱨᱩᱣᱟᱹᱲ compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
static puur_naa_nka is_compatible_unqualified_types(CType *type1, CType *type2)
{
    ᱨᱩᱣᱟᱹᱲ compare_types(type1,type2,1);
}

static void cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
static void verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    puur_naa_nka dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ᱡᱩᱫᱤ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    switch(dbt) {
    pak_sa VT_VOID:
        ᱡᱩᱫᱤ (sbt != dbt)
            tcc_error("assignment to void expression");
        bha_nga;
    pak_sa VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ᱡᱩᱫᱤ (is_null_pointer(vtop))
            bha_nga;
        /* accept implicit pointer to integer cast with warning */
        ᱡᱩᱫᱤ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            bha_nga;
        }
        type1 = pointed_type(dt);
        ᱡᱩᱫᱤ (sbt == VT_PTR)
            type2 = pointed_type(st);
        ᱵᱟᱝ ᱡᱩᱫᱤ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        ᱵᱟᱝ
            goto error;
        ᱡᱩᱫᱤ (is_compatible_types(type1, type2))
            bha_nga;
        for (qualwarn = lvl = 0;; ++lvl) {
            ᱡᱩᱫᱤ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ᱡᱩᱫᱤ (dbt != VT_PTR || sbt != VT_PTR)
                bha_nga;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ᱡᱩᱫᱤ (!is_compatible_unqualified_types(type1, type2)) {
            ᱡᱩᱫᱤ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } ᱵᱟᱝ ᱡᱩᱫᱤ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } ᱵᱟᱝ {
                tcc_warning("assignment from incompatible pointer type");
                bha_nga;
            }
        }
        ᱡᱩᱫᱤ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        bha_nga;
    pak_sa VT_BYTE:
    pak_sa VT_SHORT:
    pak_sa VT_INT:
    pak_sa VT_LLONG:
        ᱡᱩᱫᱤ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } ᱵᱟᱝ ᱡᱩᱫᱤ (sbt == VT_STRUCT) {
            goto case_VT_STRUCT;
        }
        /* XXX: more tests */
        bha_nga;
    pak_sa VT_STRUCT:
    case_VT_STRUCT:
        ᱡᱩᱫᱤ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        bha_nga;
    }
}

static void gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC void vstore(void)
{
    puur_naa_nka sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    ᱡᱩᱫᱤ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        ᱡᱩᱫᱤ (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } ᱵᱟᱝ
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            ᱡᱩᱫᱤ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            ᱵᱟᱝ ᱡᱩᱫᱤ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            ᱵᱟᱝ
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } ᱵᱟᱝ ᱡᱩᱫᱤ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        ᱡᱩᱫᱤ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        ᱡᱩᱫᱤ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ᱡᱩᱫᱤ (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } ᱵᱟᱝ {
            unsigned long long mask = (1ULL << bit_size) - 1;
            ᱡᱩᱫᱤ (dbt != VT_BOOL) {
                /* mask source */
                ᱡᱩᱫᱤ (dbt == VT_LLONG)
                    vpushll(mask);
                ᱵᱟᱝ
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
            ᱡᱩᱫᱤ (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            ᱵᱟᱝ
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } ᱵᱟᱝ ᱡᱩᱫᱤ (dbt == VT_VOID) {
        --vtop;
    } ᱵᱟᱝ {
            /* optimize char/short casts */
            delayed_cast = 0;
            ᱡᱩᱫᱤ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ᱡᱩᱫᱤ ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } ᱵᱟᱝ {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            ᱡᱩᱫᱤ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            ᱡᱩᱫᱤ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ᱡᱩᱫᱤ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = NULL;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ᱡᱩᱫᱤ (USING_TWO_WORDS(dbt)) {
                puur_naa_nka load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } ᱵᱟᱝ {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC void inc(puur_naa_nka post, puur_naa_nka c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ᱡᱩᱫᱤ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ᱡᱩᱫᱤ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (const var_na *msg)
{
    /* read the string */
    ᱡᱩᱫᱤ (tok != TOK_STR)
        expect(msg);
    cstr_reset(&initstr);
    ᱡᱚᱠᱷᱚᱱ (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    ᱨᱩᱣᱟᱹᱲ &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC puur_naa_nka exact_log2p1(puur_naa_nka i)
{
  puur_naa_nka ret;
  ᱡᱩᱫᱤ (!i)
    ᱨᱩᱣᱟᱹᱲ 0;
  for (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ᱡᱩᱫᱤ (i >= 1 << 4)
    ret += 4, i >>= 4;
  ᱡᱩᱫᱤ (i >= 1 << 2)
    ret += 2, i >>= 2;
  ᱡᱩᱫᱤ (i >= 1 << 1)
    ret++;
  ᱨᱩᱣᱟᱹᱲ ret;
}

/* Parse __attribute__((...)) GNUC extension. */
static void parse_attribute(AttributeDef *ad)
{
    puur_naa_nka t, n;
    var_na *astr;
    AttributeDef ad_tmp;
    
redo:
    ᱡᱩᱫᱤ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        ᱨᱩᱣᱟᱹᱲ;
    ᱡᱩᱫᱤ (NULL == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    ᱡᱚᱠᱷᱚᱱ (tok != ')') {
        ᱡᱩᱫᱤ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        switch(t) {
	pak_sa TOK_CLEANUP1:
	pak_sa TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    ᱡᱩᱫᱤ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } ᱵᱟᱝ ᱡᱩᱫᱤ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    bha_nga;
	}
        pak_sa TOK_CONSTRUCTOR1:
        pak_sa TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            bha_nga;
        pak_sa TOK_DESTRUCTOR1:
        pak_sa TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            bha_nga;
        pak_sa TOK_ALWAYS_INLINE1:
        pak_sa TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            bha_nga;
        pak_sa TOK_SECTION1:
        pak_sa TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            bha_nga;
        pak_sa TOK_ALIAS1:
        pak_sa TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            bha_nga;
	pak_sa TOK_VISIBILITY1:
	pak_sa TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    ᱡᱩᱫᱤ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    ᱵᱟᱝ ᱡᱩᱫᱤ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    ᱵᱟᱝ ᱡᱩᱫᱤ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    ᱵᱟᱝ ᱡᱩᱫᱤ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    ᱵᱟᱝ
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            bha_nga;
        pak_sa TOK_ALIGNED1:
        pak_sa TOK_ALIGNED2:
            ᱡᱩᱫᱤ (tok == '(') {
                next();
                n = expr_const();
                ᱡᱩᱫᱤ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } ᱵᱟᱝ {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ᱡᱩᱫᱤ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            bha_nga;
        pak_sa TOK_PACKED1:
        pak_sa TOK_PACKED2:
            ad->a.packed = 1;
            bha_nga;
        pak_sa TOK_WEAK1:
        pak_sa TOK_WEAK2:
            ad->a.weak = 1;
            bha_nga;
        pak_sa TOK_NODEBUG1:
        pak_sa TOK_NODEBUG2:
            ad->a.nodebug = 1;
            bha_nga;
        pak_sa TOK_USED1:
        pak_sa TOK_USED2:
        pak_sa TOK_UNUSED1:
        pak_sa TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            bha_nga;
        pak_sa TOK_CONST1:
        pak_sa TOK_CONST2:
        pak_sa TOK_CONST3:
        pak_sa TOK_PURE1:
        pak_sa TOK_PURE2:
	    /* ignored */
            bha_nga;
        pak_sa TOK_NOINLINE:
	    /* ignored */
	    bha_nga;
        pak_sa TOK_FORMAT1:
        pak_sa TOK_FORMAT2:
	    /* ignored */
            goto skip_param;
        pak_sa TOK_NORETURN1:
        pak_sa TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            bha_nga;
        pak_sa TOK_CDECL1:
        pak_sa TOK_CDECL2:
        pak_sa TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            bha_nga;
        pak_sa TOK_STDCALL1:
        pak_sa TOK_STDCALL2:
        pak_sa TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            bha_nga;
#ifdef TCC_TARGET_I386
        pak_sa TOK_REGPARM1:
        pak_sa TOK_REGPARM2:
            skip('(');
            n = expr_const();
            ᱡᱩᱫᱤ (n > 3) 
                n = 3;
            ᱵᱟᱝ ᱡᱩᱫᱤ (n < 0)
                n = 0;
            ᱡᱩᱫᱤ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            bha_nga;
        pak_sa TOK_FASTCALL1:
        pak_sa TOK_FASTCALL2:
        pak_sa TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            bha_nga;
        pak_sa TOK_THISCALL1:
        pak_sa TOK_THISCALL2:
        pak_sa TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            bha_nga;
#endif
        pak_sa TOK_MODE:
            skip('(');
            switch(tok) {
                pak_sa TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    bha_nga;
                pak_sa TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    bha_nga;
                pak_sa TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    bha_nga;
                pak_sa TOK_MODE_SI:
                pak_sa TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    bha_nga;
                default:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, NULL));
                    bha_nga;
            }
            next();
            skip(')');
            bha_nga;
        pak_sa TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            bha_nga;
        pak_sa TOK_NODECORATE:
            ad->a.nodecorate = 1;
            bha_nga;
        pak_sa TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            bha_nga;
        default:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, NULL));
            /* skip parameters */
skip_param:
            ᱡᱩᱫᱤ (tok == '(') {
                puur_naa_nka parenthesis = 0;
                do {
                    ᱡᱩᱫᱤ (tok == '(') 
                        parenthesis++;
                    ᱵᱟᱝ ᱡᱩᱫᱤ (tok == ')') 
                        parenthesis--;
                    next();
                } ᱡᱚᱠᱷᱚᱱ (parenthesis && tok != -1);
            }
            bha_nga;
        }
        ᱡᱩᱫᱤ (tok != ',')
            bha_nga;
        next();
    }
    skip(')');
    skip(')');
    goto redo;
}

static Sym * find_field (CType *type, puur_naa_nka v, puur_naa_nka *cumofs)
{
    Sym *s = type->ref;
    puur_naa_nka v1 = v | SYM_FIELD;
    ᱡᱩᱫᱤ (!(v & SYM_FIELD)) { /* top-level call */
        ᱡᱩᱫᱤ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ᱡᱩᱫᱤ (v < TOK_UIDENT)
            expect("field name");
        ᱡᱩᱫᱤ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    ᱡᱚᱠᱷᱚᱱ ((s = s->next) != NULL) {
        ᱡᱩᱫᱤ (s->v == v1) {
            *cumofs = s->c;
            ᱨᱩᱣᱟᱹᱲ s;
        }
        ᱡᱩᱫᱤ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            ᱡᱩᱫᱤ (ret) {
                *cumofs += s->c;
                ᱨᱩᱣᱟᱹᱲ ret;
            }
        }
    }
    ᱡᱩᱫᱤ (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, NULL));
    ᱨᱩᱣᱟᱹᱲ s;
}

static void check_fields (CType *type, puur_naa_nka check)
{
    Sym *s = type->ref;

    ᱡᱚᱠᱷᱚᱱ ((s = s->next) != NULL) {
        puur_naa_nka v = s->v & ~SYM_FIELD;
        ᱡᱩᱫᱤ (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            ᱡᱩᱫᱤ (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, NULL));
            ts->tok ^= SYM_FIELD;
        } ᱵᱟᱝ ᱡᱩᱫᱤ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

static void struct_layout(CType *type, AttributeDef *ad)
{
    puur_naa_nka size, align, maxalign, offset, c, bit_pos, bit_size;
    puur_naa_nka packed, a, bt, prevbt, prev_bit_size;
    puur_naa_nka pcc = !tcc_state->ms_bitfields;
    puur_naa_nka pragma_pack = *tcc_state->pack_stack_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    for (f = type->ref->next; f; f = f->next) {
        ᱡᱩᱫᱤ (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        ᱵᱟᱝ
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ᱡᱩᱫᱤ (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } ᱵᱟᱝ {
            /* in pcc mode, attribute packed overrides if set. */
            ᱡᱩᱫᱤ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ᱡᱩᱫᱤ (pragma_pack) {
                packed = 1;
                ᱡᱩᱫᱤ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ᱡᱩᱫᱤ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ᱡᱩᱫᱤ (a)
            align = a;

        ᱡᱩᱫᱤ (type->ref->type.t == VT_UNION) {
	    ᱡᱩᱫᱤ (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    ᱡᱩᱫᱤ (size > c)
	        c = size;

	} ᱵᱟᱝ ᱡᱩᱫᱤ (bit_size < 0) {
            ᱡᱩᱫᱤ (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    ᱡᱩᱫᱤ (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} ᱵᱟᱝ {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ᱡᱩᱫᱤ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ᱡᱩᱫᱤ (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } ᱵᱟᱝ ᱡᱩᱫᱤ (f->a.aligned) {
                    goto new_field;
                } ᱵᱟᱝ ᱡᱩᱫᱤ (!packed) {
                    puur_naa_nka a8 = align * 8;
	            puur_naa_nka ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    ᱡᱩᱫᱤ (ofs > size / align)
                        goto new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ᱡᱩᱫᱤ (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                ᱡᱚᱠᱷᱚᱱ (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ᱡᱩᱫᱤ (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } ᱵᱟᱝ {
		bt = f->type.t & VT_BTYPE;
		ᱡᱩᱫᱤ ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ᱡᱩᱫᱤ (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ᱡᱩᱫᱤ (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	ᱡᱩᱫᱤ (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, NULL), offset, size, align);
	ᱡᱩᱫᱤ (f->type.t & VT_BITFIELD) {
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

    ᱡᱩᱫᱤ (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ᱡᱩᱫᱤ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ᱡᱩᱫᱤ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ᱡᱩᱫᱤ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    for (f = type->ref->next; f; f = f->next) {
        puur_naa_nka s, px, cx, c0;
        CType t;

        ᱡᱩᱫᱤ (0 == (f->type.t & VT_BITFIELD))
            continue;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        ᱡᱩᱫᱤ (bit_size == 0)
            continue;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        ᱡᱩᱫᱤ (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            continue;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        for (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ᱡᱩᱫᱤ (c0 == cx)
                bha_nga;
            s = (px + bit_size + 7) >> 3;
            ᱡᱩᱫᱤ (s > 4) {
                t.t = VT_LLONG;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (s > 2) {
                t.t = VT_INT;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (s > 1) {
                t.t = VT_SHORT;
            } ᱵᱟᱝ {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        ᱡᱩᱫᱤ (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            ᱡᱩᱫᱤ (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, NULL),
                cx, s, align, px, bit_size);
#endif
        } ᱵᱟᱝ {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, NULL));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
static puur_naa_nka in_range(long long n, puur_naa_nka t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    ᱡᱩᱫᱤ (t & VT_UNSIGNED)
        ᱨᱩᱣᱟᱹᱲ n <= (m << 1) + 1;
    ᱨᱩᱣᱟᱹᱲ n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
static void struct_decl(CType *type, puur_naa_nka u)
{
    puur_naa_nka v, c, size, align, flexible;
    puur_naa_nka bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, parimaa_na ad);
    next();
    parse_attribute(&ad);

    v = 0;
    ᱡᱩᱫᱤ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    ᱡᱩᱫᱤ (u == VT_ENUM) {
        ut = VT_INT;
        ᱡᱩᱫᱤ (tok == ':') { /* C2x enum : <type> ... */
            next();
            ᱡᱩᱫᱤ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ᱡᱩᱫᱤ (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        ᱡᱩᱫᱤ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ᱡᱩᱫᱤ (u == s->type.t)
                goto do_decl;
            ᱡᱩᱫᱤ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                goto do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, NULL));
        }
    } ᱵᱟᱝ {
        ᱡᱩᱫᱤ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = NULL;
    /* we put an undefined size for struct/union */
    s = sym_push(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ᱡᱩᱫᱤ (tok == '{') {
        next();
        ᱡᱩᱫᱤ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        ᱡᱩᱫᱤ (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ᱡᱩᱫᱤ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            for(;;) {
                v = tok;
                ᱡᱩᱫᱤ (v < TOK_UIDENT)
                    expect("identifier");
                next();
                ᱡᱩᱫᱤ (tok == '=') {
                    next();
		    ll = expr_const64();
                }
                ᱡᱩᱫᱤ (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, NULL));
                ss = sym_push(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                ᱡᱩᱫᱤ (ll < nl)
                    nl = ll;
                ᱡᱩᱫᱤ (ll > pl)
                    pl = ll;
                ᱡᱩᱫᱤ (tok != ',')
                    bha_nga;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                ᱡᱩᱫᱤ (tok == '}')
                    bha_nga;
            }
            skip('}');

            ᱡᱩᱫᱤ (bt) {
                t.t = bt;
                s->c = 2;
                goto enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ᱡᱩᱫᱤ (nl >= 0) {
                ᱡᱩᱫᱤ (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (pl != (puur_naa_nka)pl || nl != (puur_naa_nka)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            for (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                ᱡᱩᱫᱤ (ll == (puur_naa_nka)ll) /* default is int if it fits */
                    continue;
                ᱡᱩᱫᱤ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ᱡᱩᱫᱤ (ll == (unsigned)ll)
                        continue;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } ᱵᱟᱝ {
            c = 0;
            flexible = 0;
            ᱡᱚᱠᱷᱚᱱ (tok != '}') {
                ᱡᱩᱫᱤ (!parse_btype(&btype, &ad1, 0)) {
                    ᱡᱩᱫᱤ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        continue;
                    }
		    skip(';');
		    continue;
		}
                ᱡᱚᱠᱷᱚᱱ (1) {
		    ᱡᱩᱫᱤ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, NULL));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    ᱡᱩᱫᱤ (tok != ':') {
			ᱡᱩᱫᱤ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        ᱡᱩᱫᱤ (v == 0) {
                    	    ᱡᱩᱫᱤ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    ᱵᱟᱝ {
				puur_naa_nka v = btype.ref->v;
				ᱡᱩᱫᱤ ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    ᱡᱩᱫᱤ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ᱡᱩᱫᱤ (type_size(&type1, &align) < 0) {
			    ᱡᱩᱫᱤ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    ᱵᱟᱝ
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, NULL));
                        }
                        ᱡᱩᱫᱤ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, NULL));
                    }
                    ᱡᱩᱫᱤ (tok == ':') {
                        next();
                        bit_size = expr_const();
                        /* XXX: handle v = 0 case for messages */
                        ᱡᱩᱫᱤ (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, NULL));
                        ᱡᱩᱫᱤ (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, NULL));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    ᱡᱩᱫᱤ (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ᱡᱩᱫᱤ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        ᱡᱩᱫᱤ (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, NULL));
                        } ᱵᱟᱝ ᱡᱩᱫᱤ (bit_size == bsize
				    && !*tcc_state->pack_stack_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } ᱵᱟᱝ ᱡᱩᱫᱤ (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } ᱵᱟᱝ {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    ᱡᱩᱫᱤ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ᱡᱩᱫᱤ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    ᱡᱩᱫᱤ (v) {
                        ss = sym_push(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    ᱡᱩᱫᱤ (tok == ';' || tok == TOK_EOF)
                        bha_nga;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ᱡᱩᱫᱤ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ᱡᱩᱫᱤ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

static void sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
static void parse_btype_qualify(CType *type, puur_naa_nka qualifiers)
{
    ᱡᱚᱠᱷᱚᱱ (type->t & VT_ARRAY) {
        type->ref = sym_push(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ᱡᱩᱫᱤ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
static puur_naa_nka parse_btype(CType *type, AttributeDef *ad, puur_naa_nka ignore_label)
{
    puur_naa_nka t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, parimaa_na(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = NULL;

    ᱡᱚᱠᱷᱚᱱ(1) {
        switch(tok) {
        pak_sa TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            continue;

            /* basic types */
        pak_sa TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            ᱡᱩᱫᱤ (u == VT_SHORT || u == VT_LONG) {
                ᱡᱩᱫᱤ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ (bt != -1 || (st != -1 && u != VT_INT))
                    goto tmbt;
                ᱡᱩᱫᱤ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    goto tmbt;
                bt = u;
            }
            ᱡᱩᱫᱤ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            bha_nga;
        pak_sa TOK_VOID:
            u = VT_VOID;
            goto basic_type;
        pak_sa TOK_SHORT:
            u = VT_SHORT;
            goto basic_type;
        pak_sa TOK_INT:
            u = VT_INT;
            goto basic_type;
        pak_sa TOK_ALIGNAS:
            { puur_naa_nka n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, parimaa_na(AttributeDef));
              ᱡᱩᱫᱤ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ᱡᱩᱫᱤ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  ᱵᱟᱝ
                    type_size(&type1, &n);
              } ᱵᱟᱝ {
                  n = expr_const();
                  ᱡᱩᱫᱤ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            continue;
        pak_sa TOK_LONG:
            ᱡᱩᱫᱤ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ᱵᱟᱝ ᱡᱩᱫᱤ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } ᱵᱟᱝ {
                u = VT_LONG;
                goto basic_type;
            }
            next();
            bha_nga;
        pak_sa TOK_BOOL:
            u = VT_BOOL;
            goto basic_type;
        pak_sa TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        pak_sa TOK_FLOAT:
            u = VT_FLOAT;
            goto basic_type;
        pak_sa TOK_DOUBLE:
            ᱡᱩᱫᱤ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } ᱵᱟᱝ {
                u = VT_DOUBLE;
                goto basic_type;
            }
            next();
            bha_nga;
        pak_sa TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            goto basic_type1;
        pak_sa TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            goto basic_type2;
        pak_sa TOK_UNION:
            struct_decl(&type1, VT_UNION);
            goto basic_type2;

            /* type modifiers */
        pak_sa TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ᱡᱩᱫᱤ (tok == '(') {
                parse_expr_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ᱡᱩᱫᱤ (type1.ref)
                    sym_to_attr(ad, type1.ref);
                goto basic_type2;
            }
            bha_nga;
        pak_sa TOK_CONST1:
        pak_sa TOK_CONST2:
        pak_sa TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            bha_nga;
        pak_sa TOK_VOLATILE1:
        pak_sa TOK_VOLATILE2:
        pak_sa TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            bha_nga;
        pak_sa TOK_SIGNED1:
        pak_sa TOK_SIGNED2:
        pak_sa TOK_SIGNED3:
            ᱡᱩᱫᱤ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            bha_nga;
        pak_sa TOK_RESTRICT1:
        pak_sa TOK_RESTRICT2:
        pak_sa TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            bha_nga;
        pak_sa TOK_REGISTER:
        pak_sa TOK_AUTO:
            next();
            bha_nga;
        pak_sa TOK_UNSIGNED:
            ᱡᱩᱫᱤ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            bha_nga;

            /* storage */
        pak_sa TOK_EXTERN:
            g = VT_EXTERN;
            goto storage;
        pak_sa TOK_STATIC:
            g = VT_STATIC;
            goto storage;
        pak_sa TOK_TYPEDEF:
            g = VT_TYPEDEF;
            goto storage;
       storage:
            ᱡᱩᱫᱤ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            bha_nga;
        pak_sa TOK_INLINE1:
        pak_sa TOK_INLINE2:
        pak_sa TOK_INLINE3:
            t |= VT_INLINE;
            next();
            bha_nga;
        pak_sa TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            bha_nga;
            /* GNUC attribute */
        pak_sa TOK_ATTRIBUTE1:
        pak_sa TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ᱡᱩᱫᱤ (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            continue;
            /* GNUC typeof */
        pak_sa TOK_TYPEOF1:
        pak_sa TOK_TYPEOF2:
        pak_sa TOK_TYPEOF3:
            next();
            parse_expr_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ᱡᱩᱫᱤ (type1.ref) {
                sym_to_attr(ad, type1.ref);
                ᱡᱩᱫᱤ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            goto basic_type2;
        pak_sa TOK_THREAD_LOCAL:
        pak_sa TOK___thread:
            ᱡᱩᱫᱤ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            bha_nga;
        default:
            ᱡᱩᱫᱤ (typespec_found)
                goto the_end;
            s = sym_find(tok);
            ᱡᱩᱫᱤ (!s || !(s->type.t & VT_TYPEDEF))
                goto the_end;

            n = tok, next();
            ᱡᱩᱫᱤ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                goto the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ᱡᱩᱫᱤ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ᱡᱩᱫᱤ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            bha_nga;
        }
        type_found = 1;
    }
the_end:
    ᱡᱩᱫᱤ (tcc_state->char_is_unsigned) {
        ᱡᱩᱫᱤ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ᱡᱩᱫᱤ (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    ᱡᱩᱫᱤ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    ᱨᱩᱣᱟᱹᱲ type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
static anta_hstha void convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ᱡᱩᱫᱤ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
static anta_hstha void convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(void)
{
    skip('(');
    ᱨᱩᱣᱟᱹᱲ parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
static puur_naa_nka asm_label_instr(void)
{
    puur_naa_nka v;
    var_na *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    ᱨᱩᱣᱟᱹᱲ v;
}

static puur_naa_nka post_type(CType *type, AttributeDef *ad, puur_naa_nka storage, puur_naa_nka td)
{
    puur_naa_nka n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = NULL;
    puur_naa_nka *vla_array_str = NULL;

    ᱡᱩᱫᱤ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	ᱡᱩᱫᱤ (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  ᱨᱩᱣᱟᱹᱲ 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_stack ? &local_stack : &global_stack;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	ᱡᱩᱫᱤ (tok == ')')
	  l = 0;
	ᱵᱟᱝ ᱡᱩᱫᱤ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	ᱵᱟᱝ ᱡᱩᱫᱤ (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_pop(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    ᱨᱩᱣᱟᱹᱲ 0;
	} ᱵᱟᱝ
	  l = FUNC_OLD;

        first = NULL;
        plast = &first;
        arg_size = 0;
        ᱡᱩᱫᱤ (l) {
            for(;;) {
                /* read param name and compute offset */
                ᱡᱩᱫᱤ (l != FUNC_OLD) {
                    ᱡᱩᱫᱤ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        bha_nga;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    ᱡᱩᱫᱤ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ᱡᱩᱫᱤ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } ᱵᱟᱝ {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = NULL;
                    next();
                }
                ᱡᱩᱫᱤ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_push(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                ᱡᱩᱫᱤ (tok == ')')
                    bha_nga;
                skip(',');
                ᱡᱩᱫᱤ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    bha_nga;
                }
		ᱡᱩᱫᱤ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } ᱵᱟᱝ
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ᱡᱩᱫᱤ (tok == '[') {
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
        sym_pop(ps, sr, 1);
        --local_scope;

    } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '[') {
	puur_naa_nka saved_nocode_wanted = nocode_wanted;
        puur_naa_nka array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        ᱡᱩᱫᱤ (td & TYPE_PARAM) ᱡᱚᱠᱷᱚᱱ (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    switch (tok) {
	    pak_sa TOK_CONST1: pak_sa TOK_CONST2: pak_sa TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		continue;
	    pak_sa TOK_VOLATILE1: pak_sa TOK_VOLATILE2: pak_sa TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		continue;
	    pak_sa TOK_RESTRICT1: pak_sa TOK_RESTRICT2: pak_sa TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		continue;
	    pak_sa TOK_STATIC:
	    pak_sa '*':
		next();
		continue;
	    default:
		bha_nga;
	    }
            ᱡᱩᱫᱤ (tok != ']') {
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
		goto check;
            }
            bha_nga;

	} ᱵᱟᱝ ᱡᱩᱫᱤ (tok != ']') {
            ᱡᱩᱫᱤ (!local_stack || (storage & VT_STATIC))
                vpushi(expr_const());
            ᱵᱟᱝ {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ᱡᱩᱫᱤ (n < 0)
                    tcc_error("invalid array size");
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        ᱡᱩᱫᱤ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ᱡᱩᱫᱤ ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ᱡᱩᱫᱤ (t1 & VT_VLA) {
            ᱡᱩᱫᱤ (n < 0) {
		ᱡᱩᱫᱤ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    ᱵᱟᱝ {
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
        ᱡᱩᱫᱤ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_push(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ᱡᱩᱫᱤ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ᱡᱩᱫᱤ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    ᱵᱟᱝ
	        tok_str_free_str(vla_array_str);
	}
    }
    ᱨᱩᱣᱟᱹᱲ 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
static CType *type_decl(CType *type, AttributeDef *ad, puur_naa_nka *v, puur_naa_nka td)
{
    CType *post, *ret;
    puur_naa_nka qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    ᱡᱚᱠᱷᱚᱱ (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        switch(tok) {
        pak_sa TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            goto redo;
        pak_sa TOK_CONST1:
        pak_sa TOK_CONST2:
        pak_sa TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            goto redo;
        pak_sa TOK_VOLATILE1:
        pak_sa TOK_VOLATILE2:
        pak_sa TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            goto redo;
        pak_sa TOK_RESTRICT1:
        pak_sa TOK_RESTRICT2:
        pak_sa TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            goto redo;
	/* XXX: clarify attribute handling */
	pak_sa TOK_ATTRIBUTE1:
	pak_sa TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    bha_nga;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	ᱡᱩᱫᱤ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ᱡᱩᱫᱤ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ᱡᱩᱫᱤ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} ᱵᱟᱝ
	  goto abstract;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } ᱵᱟᱝ {
  abstract:
	ᱡᱩᱫᱤ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    ᱨᱩᱣᱟᱹᱲ ret;
}

/* indirection with full error checking and bound check */
ST_FUNC void indir(void)
{
    ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            ᱨᱩᱣᱟᱹᱲ;
        expect("pointer");
    }
    ᱡᱩᱫᱤ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ᱡᱩᱫᱤ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
static void gfunc_param_typed(Sym *func, Sym *arg)
{
    puur_naa_nka func_type;
    CType type;

    func_type = func->f.func_type;
    ᱡᱩᱫᱤ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == NULL)) {
        /* default casting : only need to convert float to double */
        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } ᱵᱟᱝ ᱡᱩᱫᱤ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } ᱵᱟᱝ ᱡᱩᱫᱤ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } ᱵᱟᱝ ᱡᱩᱫᱤ (arg == NULL) {
        tcc_error("too many arguments to function");
    } ᱵᱟᱝ {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
static void expr_type(CType *type, void (*expr_fn)(void))
{
    nocode_wanted++;
    expr_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
static void parse_expr_type(CType *type)
{
    puur_naa_nka n;
    AttributeDef ad;

    skip('(');
    ᱡᱩᱫᱤ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } ᱵᱟᱝ {
        expr_type(type, gexpr);
    }
    skip(')');
}

static void parse_type(CType *type)
{
    AttributeDef ad;
    puur_naa_nka n;

    ᱡᱩᱫᱤ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

static void parse_builtin_params(puur_naa_nka nc, const var_na *args)
{
    var_na c, sep = '(';
    CType type;
    ᱡᱩᱫᱤ (nc)
        nocode_wanted++;
    next();
    ᱡᱩᱫᱤ (*args == 0)
	skip(sep);
    ᱡᱚᱠᱷᱚᱱ ((c = *args++)) {
	skip(sep);
	sep = ',';
        ᱡᱩᱫᱤ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    continue;
        }
        expr_eq();
        type.ref = NULL;
        type.t = 0;
	switch (c) {
	    pak_sa 'e':
		continue;
	    pak_sa 'V':
                type.t = VT_CONSTANT;
	    pak_sa 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                bha_nga;
	    pak_sa 'S':
                type.t = VT_CONSTANT;
	    pak_sa 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                bha_nga;
	    pak_sa 'i':
                type.t = VT_INT;
                bha_nga;
	    pak_sa 'l':
                type.t = VT_SIZE_T;
                bha_nga;
	    default:
                bha_nga;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    ᱡᱩᱫᱤ (nc)
        nocode_wanted--;
}

static void parse_atomic(puur_naa_nka atok)
{
    puur_naa_nka size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    var_na buf[40];
    static const var_na *const templates[] = {
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
    const var_na *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = NULL;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    for (arg = 0;;) {
        expr_eq();
        switch (template[arg]) {
        pak_sa 'a':
        pak_sa 'A':
            atom_ptr = &vtop->type;
            ᱡᱩᱫᱤ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            ᱡᱩᱫᱤ (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            bha_nga;

        pak_sa 'p':
            ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            bha_nga;
        pak_sa 'v':
            gen_assign_cast(atom);
            bha_nga;
        pak_sa 'l':
            indir();
            gen_assign_cast(atom);
            bha_nga;
        pak_sa 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            bha_nga;
        pak_sa 'm':
            gen_assign_cast(&int_type);
            bha_nga;
        pak_sa 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            bha_nga;
        }
        ᱡᱩᱫᱤ ('.' == template[++arg])
            bha_nga;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    switch (template[arg + 1]) {
    pak_sa 'b':
        ct.t = VT_BOOL;
        bha_nga;
    pak_sa 'v':
        ct = *atom;
        bha_nga;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ᱡᱩᱫᱤ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ᱵᱟᱝ
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    ᱡᱩᱫᱤ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC void unary(void)
{
    puur_naa_nka n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ᱡᱩᱫᱤ (debug_modes)
        tcc_debug_line(tcc_state), tcc_tcov_check_line (tcc_state, 1);

    type.ref = NULL;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    switch(tok) {
    pak_sa TOK_EXTENSION:
        next();
        goto tok_next;
    pak_sa TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        goto push_tokc;
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR: 
	t = VT_INT;
 push_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        bha_nga;
    pak_sa TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        goto push_tokc;
    pak_sa TOK_CLLONG:
        t = VT_LLONG;
	goto push_tokc;
    pak_sa TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	goto push_tokc;
    pak_sa TOK_CFLOAT:
        t = VT_FLOAT;
	goto push_tokc;
    pak_sa TOK_CDOUBLE:
        t = VT_DOUBLE;
	goto push_tokc;
    pak_sa TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#ᱵᱟᱝ
        t = VT_LDOUBLE;
#endif
	goto push_tokc;
    pak_sa TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	goto push_tokc;
    pak_sa TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	goto push_tokc;
    pak_sa TOK___FUNCTION__:
        ᱡᱩᱫᱤ (!gnu_ext)
            goto tok_identifier;
        /* fall thru */
    pak_sa TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        goto case_TOK_STR;
    pak_sa TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#ᱵᱟᱝ
        t = VT_INT;
#endif
        goto str_init;
    pak_sa TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ᱡᱩᱫᱤ (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, parimaa_na(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        bha_nga;
    pak_sa TOK_SOTYPE:
    pak_sa '(':
        t = tok;
        next();
        /* cast ? */
        ᱡᱩᱫᱤ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ᱡᱩᱫᱤ (tok == '{') {
                    /* data is allocated locally by default */
                ᱡᱩᱫᱤ (global_expr)
                    r = VT_CONST;
                ᱵᱟᱝ
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ᱡᱩᱫᱤ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, parimaa_na(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                ᱨᱩᱣᱟᱹᱲ;
            } ᱵᱟᱝ {
                unary();
                gen_cast(&type);
            }
        } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '{') {
	    puur_naa_nka saved_nocode_wanted = nocode_wanted;
            ᱡᱩᱫᱤ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ᱡᱩᱫᱤ (0 == local_scope)
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
            block(STMT_EXPR);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ᱡᱩᱫᱤ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } ᱵᱟᱝ {
            gexpr();
            skip(')');
        }
        bha_nga;
    pak_sa '*':
        next();
        unary();
        indir();
        bha_nga;
    pak_sa '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ᱡᱩᱫᱤ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        bha_nga;
    pak_sa '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        bha_nga;
    pak_sa '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        bha_nga;
    pak_sa '+':
        next();
        unary();
        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ᱡᱩᱫᱤ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        bha_nga;
    pak_sa TOK_SIZEOF:
    pak_sa TOK_ALIGNOF1:
    pak_sa TOK_ALIGNOF2:
    pak_sa TOK_ALIGNOF3:
        t = tok;
        next();
        ᱡᱩᱫᱤ (tok == '(')
            tok = TOK_SOTYPE;
        expr_type(&type, unary);
        ᱡᱩᱫᱤ (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } ᱵᱟᱝ {
            type_size(&type, &align);
            s = NULL;
            ᱡᱩᱫᱤ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ᱡᱩᱫᱤ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        bha_nga;

    pak_sa TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        bha_nga;
    pak_sa TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        bha_nga;
    pak_sa TOK_builtin_choose_expr:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = expr_const64();
	    skip(',');
	    ᱡᱩᱫᱤ (!c) {
		nocode_wanted++;
	    }
	    expr_eq();
	    ᱡᱩᱫᱤ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ᱡᱩᱫᱤ (c) {
		nocode_wanted++;
	    }
	    expr_eq();
	    ᱡᱩᱫᱤ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        bha_nga;
    pak_sa TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        bha_nga;
    pak_sa TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        bha_nga;
    pak_sa TOK_builtin_frame_address:
    pak_sa TOK_builtin_return_address:
        {
            puur_naa_nka tok1 = tok;
            puur_naa_nka level;
            next();
            skip('(');
            level = expr_const();
            ᱡᱩᱫᱤ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            ᱡᱚᱠᱷᱚᱱ (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ᱡᱩᱫᱤ (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#elif defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#ᱵᱟᱝ
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        bha_nga;
#ifdef TCC_TARGET_RISCV64
    pak_sa TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ᱡᱩᱫᱤ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ᱡᱩᱫᱤ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        bha_nga;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    pak_sa TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ᱡᱩᱫᱤ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ᱡᱩᱫᱤ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        bha_nga;
#ᱵᱟᱝ
    pak_sa TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	bha_nga;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    pak_sa TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        bha_nga;
    }
    pak_sa TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        bha_nga;
    }
#endif
#ifdef TCC_TARGET_ARM64
    pak_sa TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        bha_nga;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    pak_sa TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        bha_nga;
    }
#endif

    /* atomic operations */
    pak_sa TOK___atomic_store:
    pak_sa TOK___atomic_load:
    pak_sa TOK___atomic_exchange:
    pak_sa TOK___atomic_compare_exchange:
    pak_sa TOK___atomic_fetch_add:
    pak_sa TOK___atomic_fetch_sub:
    pak_sa TOK___atomic_fetch_or:
    pak_sa TOK___atomic_fetch_xor:
    pak_sa TOK___atomic_fetch_and:
    pak_sa TOK___atomic_fetch_nand:
    pak_sa TOK___atomic_add_fetch:
    pak_sa TOK___atomic_sub_fetch:
    pak_sa TOK___atomic_or_fetch:
    pak_sa TOK___atomic_xor_fetch:
    pak_sa TOK___atomic_and_fetch:
    pak_sa TOK___atomic_nand_fetch:
        parse_atomic(tok);
        bha_nga;

    /* pre operations */
    pak_sa TOK_INC:
    pak_sa TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        bha_nga;
    pak_sa '-':
        next();
        unary();
	ᱡᱩᱫᱤ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} ᱵᱟᱝ {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        bha_nga;
    pak_sa TOK_LAND:
        ᱡᱩᱫᱤ (!gnu_ext)
            goto tok_identifier;
        next();
        /* allow to take the address of a label */
        ᱡᱩᱫᱤ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        ᱡᱩᱫᱤ (!s) {
            s = label_push(&global_label_stack, tok, LABEL_FORWARD);
        } ᱵᱟᱝ {
            ᱡᱩᱫᱤ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ᱡᱩᱫᱤ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        bha_nga;

    pak_sa TOK_GENERIC:
    {
	CType controlling_type;
	puur_naa_nka has_default = 0;
	puur_naa_nka has_match = 0;
	puur_naa_nka learn = 0;
	TokenString *str = NULL;
	puur_naa_nka saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	expr_type(&controlling_type, expr_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        for (;;) {
	    learn = 0;
	    skip(',');
	    ᱡᱩᱫᱤ (tok == TOK_DEFAULT) {
		ᱡᱩᱫᱤ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ᱡᱩᱫᱤ (!has_match)
		    learn = 1;
		next();
	    } ᱵᱟᱝ {
		puur_naa_nka v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ᱡᱩᱫᱤ (compare_types(&controlling_type, &type, 0)) {
		    ᱡᱩᱫᱤ (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ᱡᱩᱫᱤ (learn) {
		ᱡᱩᱫᱤ (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } ᱵᱟᱝ {
		skip_or_save_block(NULL);
	    }
	    ᱡᱩᱫᱤ (tok == ')')
		bha_nga;
	}
	ᱡᱩᱫᱤ (!str) {
	    var_na buf[60];
	    type_to_str(buf, parimaa_na buf, &controlling_type, NULL);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	expr_eq();
	ᱡᱩᱫᱤ (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	bha_nga;
    }
    // special qnan , snan and infinity values
    pak_sa TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        bha_nga;
    pak_sa TOK___SNAN__:
	n = 0x7f800001;
	goto special_math_val;
    pak_sa TOK___INF__:
	n = 0x7f800000;
	goto special_math_val;

    default:
    tok_identifier:
        ᱡᱩᱫᱤ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        ᱡᱩᱫᱤ (!s || IS_ASM_SYM(s)) {
            const var_na *name = get_tok_str(t, NULL);
            ᱡᱩᱫᱤ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ᱡᱩᱫᱤ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ᱡᱩᱫᱤ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ᱡᱩᱫᱤ (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            ᱡᱩᱫᱤ (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } ᱵᱟᱝ ᱡᱩᱫᱤ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        bha_nga;
    }
    
    /* post operations */
    ᱡᱚᱠᱷᱚᱱ (1) {
        ᱡᱩᱫᱤ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '.' || tok == TOK_ARROW) {
            puur_naa_nka qualifiers, cumofs;
            /* field */ 
            ᱡᱩᱫᱤ (tok == TOK_ARROW) 
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
            ᱡᱩᱫᱤ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ᱡᱩᱫᱤ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ᱡᱩᱫᱤ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '(') {
            SValue ret;
            Sym *sa;
            puur_naa_nka nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ᱡᱩᱫᱤ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        goto error_func;
                } ᱵᱟᱝ {
                error_func:
                    expect("function pointer");
                }
            } ᱵᱟᱝ {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ᱡᱩᱫᱤ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ᱡᱩᱫᱤ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ᱡᱩᱫᱤ (size < 16)
                    ᱡᱚᱠᱷᱚᱱ (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    ᱡᱩᱫᱤ (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    ᱡᱩᱫᱤ (ret_nregs < 0)
                      vtop--;
                    ᱵᱟᱝ
                      nb_args++;
                }
            } ᱵᱟᱝ {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ᱡᱩᱫᱤ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = NULL;
            ᱡᱩᱫᱤ (tok != ')') {
                r = tcc_state->reverse_funcargs;
                for(;;) {
                    ᱡᱩᱫᱤ (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } ᱵᱟᱝ {
                        expr_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    ᱡᱩᱫᱤ (sa)
                        sa = sa->next;
                    ᱡᱩᱫᱤ (tok == ')')
                        bha_nga;
                    skip(',');
                }
            }
            ᱡᱩᱫᱤ (sa)
                tcc_error("too few arguments to function");

            ᱡᱩᱫᱤ (p) { /* with reverse_funcargs */
                for (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    do {
                        sa = sa->next, p2 = p2->prev;
                    } ᱡᱚᱠᱷᱚᱱ (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    expr_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            ᱡᱩᱫᱤ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } ᱵᱟᱝ {
                /* return value */
                n = ret_nregs;
                ᱡᱚᱠᱷᱚᱱ (n > 1) {
                    puur_naa_nka rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    for (r = 0; r < NB_REGS; ++r)
                        ᱡᱩᱫᱤ (reg_classes[r] & rc)
                            bha_nga;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ᱡᱩᱫᱤ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    puur_naa_nka addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    ᱡᱩᱫᱤ (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    for (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        ᱡᱩᱫᱤ (--ret_nregs == 0)
                          bha_nga;
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
                ᱡᱩᱫᱤ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#ᱵᱟᱝ
                    vtop->type.t = VT_INT;
#endif
                }
            }
            ᱡᱩᱫᱤ (s->f.func_noreturn) {
                ᱡᱩᱫᱤ (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } ᱵᱟᱝ {
            bha_nga;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

static void expr_prod(void)
{
    puur_naa_nka t;

    unary();
    ᱡᱚᱠᱷᱚᱱ ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

static void expr_sum(void)
{
    puur_naa_nka t;

    expr_prod();
    ᱡᱚᱠᱷᱚᱱ ((t = tok) == '+' || t == '-') {
        next();
        expr_prod();
        gen_op(t);
    }
}

static void expr_shift(void)
{
    puur_naa_nka t;

    expr_sum();
    ᱡᱚᱠᱷᱚᱱ ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        expr_sum();
        gen_op(t);
    }
}

static void expr_cmp(void)
{
    puur_naa_nka t;

    expr_shift();
    ᱡᱚᱠᱷᱚᱱ (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        expr_shift();
        gen_op(t);
    }
}

static void expr_cmpeq(void)
{
    puur_naa_nka t;

    expr_cmp();
    ᱡᱚᱠᱷᱚᱱ ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        expr_cmp();
        gen_op(t);
    }
}

static void expr_and(void)
{
    expr_cmpeq();
    ᱡᱚᱠᱷᱚᱱ (tok == '&') {
        next();
        expr_cmpeq();
        gen_op('&');
    }
}

static void expr_xor(void)
{
    expr_and();
    ᱡᱚᱠᱷᱚᱱ (tok == '^') {
        next();
        expr_and();
        gen_op('^');
    }
}

static void expr_or(void)
{
    expr_xor();
    ᱡᱚᱠᱷᱚᱱ (tok == '|') {
        next();
        expr_xor();
        gen_op('|');
    }
}

static void expr_landor(puur_naa_nka op);

static void expr_land(void)
{
    expr_or();
    ᱡᱩᱫᱤ (tok == TOK_LAND)
        expr_landor(tok);
}

static void expr_lor(void)
{
    expr_land();
    ᱡᱩᱫᱤ (tok == TOK_LOR)
        expr_landor(tok);
}

# define expr_landor_next(op) op == TOK_LAND ? expr_or() : expr_land()
#ᱵᱟᱝ /* defined precedence_parser */
# define expr_landor_next(op) unary(), expr_infix(precedence(op) + 1)
# define expr_lor() unary(), expr_infix(1)

static puur_naa_nka precedence(puur_naa_nka tok)
{
    switch (tok) {
        pak_sa TOK_LOR: ᱨᱩᱣᱟᱹᱲ 1;
        pak_sa TOK_LAND: ᱨᱩᱣᱟᱹᱲ 2;
	pak_sa '|': ᱨᱩᱣᱟᱹᱲ 3;
	pak_sa '^': ᱨᱩᱣᱟᱹᱲ 4;
	pak_sa '&': ᱨᱩᱣᱟᱹᱲ 5;
	pak_sa TOK_EQ: pak_sa TOK_NE: ᱨᱩᱣᱟᱹᱲ 6;
 relat: pak_sa TOK_ULT: pak_sa TOK_UGE: ᱨᱩᱣᱟᱹᱲ 7;
	pak_sa TOK_SHL: pak_sa TOK_SAR: ᱨᱩᱣᱟᱹᱲ 8;
	pak_sa '+': pak_sa '-': ᱨᱩᱣᱟᱹᱲ 9;
	pak_sa '*': pak_sa '/': pak_sa '%': ᱨᱩᱣᱟᱹᱲ 10;
	default:
	    ᱡᱩᱫᱤ (tok >= TOK_ULE && tok <= TOK_GT)
	        goto relat;
	    ᱨᱩᱣᱟᱹᱲ 0;
    }
}
static unsigned var_na prec[256];
static void init_prec(void)
{
    puur_naa_nka i;
    for (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

static void expr_landor(puur_naa_nka op);

static void expr_infix(puur_naa_nka p)
{
    puur_naa_nka t = tok, p2;
    ᱡᱚᱠᱷᱚᱱ ((p2 = precedence(t)) >= p) {
        ᱡᱩᱫᱤ (t == TOK_LOR || t == TOK_LAND) {
            expr_landor(t);
        } ᱵᱟᱝ {
            next();
            unary();
            ᱡᱩᱫᱤ (precedence(tok) > p2)
              expr_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
static puur_naa_nka condition_3way(void)
{
    puur_naa_nka c = -1;
    ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    ᱨᱩᱣᱟᱹᱲ c;
}

static void expr_landor(puur_naa_nka op)
{
    puur_naa_nka t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    for(;;) {
        c = f ? i : condition_3way();
        ᱡᱩᱫᱤ (c < 0)
            save_regs(1), cc = 0;
        ᱵᱟᱝ ᱡᱩᱫᱤ (c != i)
            nocode_wanted++, f = 1;
        ᱡᱩᱫᱤ (tok != op)
            bha_nga;
        ᱡᱩᱫᱤ (c < 0)
            t = gvtst(i, t);
        ᱵᱟᱝ
            vpop();
        next();
        expr_landor_next(op);
    }
    ᱡᱩᱫᱤ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } ᱵᱟᱝ {
        gvtst_set(i, t);
    }
}

static puur_naa_nka is_cond_bool(SValue *sv)
{
    ᱡᱩᱫᱤ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        ᱨᱩᱣᱟᱹᱲ (unsigned)sv->c.i < 2;
    ᱡᱩᱫᱤ (sv->r == VT_CMP)
        ᱨᱩᱣᱟᱹᱲ 1;
    ᱨᱩᱣᱟᱹᱲ 0;
}

static void expr_cond(void)
{
    puur_naa_nka tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    expr_lor();
    ᱡᱩᱫᱤ (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ᱡᱩᱫᱤ (!g) {
            ᱡᱩᱫᱤ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } ᱵᱟᱝ {
                vpop();
            }
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ᱡᱩᱫᱤ (c == 0)
          nocode_wanted++;
        ᱡᱩᱫᱤ (!g)
          gexpr();

        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ᱡᱩᱫᱤ (g) {
            u = tt;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } ᱵᱟᱝ
          u = 0;

        ᱡᱩᱫᱤ (c == 0)
          nocode_wanted--;
        ᱡᱩᱫᱤ (c == 1)
          nocode_wanted++;
        skip(':');
        expr_cond();

        ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ᱡᱩᱫᱤ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ᱡᱩᱫᱤ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            ᱨᱩᱣᱟᱹᱲ;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ᱡᱩᱫᱤ (c != 1) {
            gen_cast(&type);
            ᱡᱩᱫᱤ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ᱡᱩᱫᱤ (USING_TWO_WORDS(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ᱡᱩᱫᱤ (c < 0) {
            ᱡᱩᱫᱤ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ᱡᱩᱫᱤ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        ᱡᱩᱫᱤ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ᱡᱩᱫᱤ (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        ᱡᱩᱫᱤ (c < 0) {
            ᱡᱩᱫᱤ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ᱡᱩᱫᱤ (islv)
          indir();
    }
}

static void expr_eq(void)
{
    puur_naa_nka t;
    
    expr_cond();
    ᱡᱩᱫᱤ ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        ᱡᱩᱫᱤ (t == '=') {
            expr_eq();
        } ᱵᱟᱝ {
            vdup();
            expr_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC void gexpr(void)
{
    expr_eq();
    ᱡᱩᱫᱤ (tok == ',') {
        do {
            vpop();
            next();
            expr_eq();
        } ᱡᱚᱠᱷᱚᱱ (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ᱡᱩᱫᱤ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ᱡᱩᱫᱤ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
static void expr_const1(void)
{
    nocode_wanted += CONST_WANTED_BIT;
    expr_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
static anta_hstha int64_t expr_const64(void)
{
    int64_t c;
    expr_const1();
    ᱡᱩᱫᱤ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    ᱨᱩᱣᱟᱹᱲ c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC puur_naa_nka expr_const(void)
{
    puur_naa_nka c;
    int64_t wc = expr_const64();
    c = wc;
    ᱡᱩᱫᱤ (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    ᱨᱩᱣᱟᱹᱲ c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
static void gfunc_return(CType *func_type)
{
    ᱡᱩᱫᱤ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        puur_naa_nka ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ᱡᱩᱫᱤ (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } ᱵᱟᱝ ᱡᱩᱫᱤ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } ᱵᱟᱝ {
            /* returning structure packed into registers */
            puur_naa_nka size, addr, align, rc, n;
            size = type_size(func_type,&align);
            ᱡᱩᱫᱤ (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ᱡᱩᱫᱤ (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		ᱡᱩᱫᱤ (ret_align > align)
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
            for (n = ret_nregs; --n > 0;) {
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
    } ᱵᱟᱝ {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

static void check_func_return(void)
{
    ᱡᱩᱫᱤ ((func_vt.t & VT_BTYPE) == VT_VOID)
        ᱨᱩᱣᱟᱹᱲ;
    ᱡᱩᱫᱤ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } ᱵᱟᱝ {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

static puur_naa_nka case_cmp(uint64_t a, uint64_t b)
{
    ᱡᱩᱫᱤ (cur_switch->sv.type.t & VT_UNSIGNED)
        ᱨᱩᱣᱟᱹᱲ a < b ? -1 : a > b;
    ᱵᱟᱝ
        ᱨᱩᱣᱟᱹᱲ (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

static puur_naa_nka case_cmp_qs(const void *pa, const void *pb)
{
    ᱨᱩᱣᱟᱹᱲ case_cmp((*(sa_nracanaa case_t**)pa)->v1, (*(sa_nracanaa case_t**)pb)->v1);
}

static void case_sort(sa_nracanaa switch_t *sw)
{
    sa_nracanaa case_t **p;
    ᱡᱩᱫᱤ (sw->n < 2)
        ᱨᱩᱣᱟᱹᱲ;
    qsort(sw->p, sw->n, parimaa_na *sw->p, case_cmp_qs);
    p = sw->p;
    ᱡᱚᱠᱷᱚᱱ (p < sw->p + sw->n - 1) {
        ᱡᱩᱫᱤ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            puur_naa_nka l1 = p[0]->line, l2 = p[1]->line;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } ᱵᱟᱝ ᱡᱩᱫᱤ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * parimaa_na *p);
        } ᱵᱟᱝ
            ++p;
    }
}

static puur_naa_nka gcase(sa_nracanaa case_t **base, puur_naa_nka len, puur_naa_nka dsym)
{
    sa_nracanaa case_t *p;
    puur_naa_nka t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ᱡᱩᱫᱤ (t != VT_LLONG)
        t = VT_INT;
    ᱡᱚᱠᱷᱚᱱ (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        ᱡᱩᱫᱤ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } ᱵᱟᱝ {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ᱡᱩᱫᱤ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            ᱵᱟᱝ
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
    ᱨᱩᱣᱟᱹᱲ gjmp(dsym);
}

static void end_switch(void)
{
    sa_nracanaa switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
static void save_lvalues(void)
{
    SValue *sv = vtop;
    ᱡᱚᱠᱷᱚᱱ (sv >= vstack) {
        ᱡᱩᱫᱤ (sv->sym && (sv->r & VT_LVAL)) {
            puur_naa_nka align, size = type_size(&sv->type, &align);
            puur_naa_nka r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

static void try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    for (; cls != stop; cls = cls->next) {
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


static void try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    puur_naa_nka ocd, ccd;

    ᱡᱩᱫᱤ (!cur_scope->cl.s)
	ᱨᱩᱣᱟᱹᱲ;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    for (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    for (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    for (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
static void block_cleanup(sa_nracanaa scope *o)
{
    puur_naa_nka jmp = 0;
    Sym *g, **pg;
    for (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ᱡᱩᱫᱤ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            ᱡᱩᱫᱤ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ᱡᱩᱫᱤ (!o->cl.n)
                goto remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } ᱵᱟᱝ {
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

static void vla_restore(puur_naa_nka loc)
{
    ᱡᱩᱫᱤ (loc)
        gen_vla_sp_restore(loc);
}

static void vla_leave(sa_nracanaa scope *o)
{
    sa_nracanaa scope *c = cur_scope, *v = NULL;
    for (; c != o && c; c = c->prev)
      ᱡᱩᱫᱤ (c->vla.num)
        v = c;
    ᱡᱩᱫᱤ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

static void new_scope(sa_nracanaa scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.num = 0;

    /* record local declaration stack position */
    o->lstk = local_stack;
    o->llstk = local_label_stack;
    ++local_scope;
}

static void prev_scope(sa_nracanaa scope *o, puur_naa_nka is_expr)
{
    vla_leave(o->prev);

    ᱡᱩᱫᱤ (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    ᱡᱩᱫᱤ (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_expr);

    /* pop locally defined labels */
    label_pop(&local_label_stack, o->llstk, is_expr);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_pop(&local_stack, o->lstk, is_expr);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
static void leave_scope(sa_nracanaa scope *o)
{
    ᱡᱩᱫᱤ (!o)
        ᱨᱩᱣᱟᱹᱲ;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
static void new_scope_s(sa_nracanaa scope *o)
{
    o->lstk = local_stack;
    ++local_scope;
}

static void prev_scope_s(sa_nracanaa scope *o)
{
    sym_pop(&local_stack, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

static void lblock(puur_naa_nka *bsym, puur_naa_nka *csym)
{
    sa_nracanaa scope *lo = loop_scope, *co = cur_scope;
    puur_naa_nka *b = co->bsym, *c = co->csym;
    ᱡᱩᱫᱤ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    ᱡᱩᱫᱤ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
static void gexpr_decl(void)
{
    puur_naa_nka v = decl(VT_JMP);
    ᱡᱩᱫᱤ (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } ᱵᱟᱝ {
        ᱡᱩᱫᱤ (v)
            skip(';');
        gexpr();
    }
}

static void block(puur_naa_nka flags)
{
    puur_naa_nka a, b, c, d, e, t;
    sa_nracanaa scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ᱡᱩᱫᱤ (TOK_HAS_VALUE(t))
        goto expr;
    next();

    ᱡᱩᱫᱤ (debug_modes)
        tcc_tcov_check_line (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    ᱡᱩᱫᱤ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        ᱡᱩᱫᱤ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } ᱵᱟᱝ {
            gsym(a);
        }
        prev_scope_s(&o);

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_WHILE) {
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

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == '{') {
        ᱡᱩᱫᱤ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        ᱡᱚᱠᱷᱚᱱ (tok == TOK_LABEL) {
            do {
                next();
                ᱡᱩᱫᱤ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_push(&local_label_stack, tok, LABEL_DECLARED);
                next();
            } ᱡᱚᱠᱷᱚᱱ (tok == ',');
            skip(';');
        }

        ᱡᱚᱠᱷᱚᱱ (tok != '}') {
	    decl(VT_LOCAL);
            ᱡᱩᱫᱤ (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_EXPR);
        ᱡᱩᱫᱤ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ᱡᱩᱫᱤ (local_scope)
            next();
        ᱵᱟᱝ ᱡᱩᱫᱤ (!nocode_wanted)
            check_func_return();

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ᱡᱩᱫᱤ (tok != ';') {
            gexpr();
            ᱡᱩᱫᱤ (b) {
                gen_assign_cast(&func_vt);
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } ᱵᱟᱝ ᱡᱩᱫᱤ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } ᱵᱟᱝ ᱡᱩᱫᱤ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(root_scope);
        ᱡᱩᱫᱤ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ᱡᱩᱫᱤ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ᱡᱩᱫᱤ (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_BREAK) {
        /* compute jump */
        ᱡᱩᱫᱤ (!cur_scope->bsym)
            tcc_error("cannot break");
        ᱡᱩᱫᱤ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        ᱵᱟᱝ
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_CONTINUE) {
        /* compute jump */
        ᱡᱩᱫᱤ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ᱡᱩᱫᱤ (tok != ';') {
            /* c99 for-loop init decl? */
            ᱡᱩᱫᱤ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ᱡᱩᱫᱤ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ᱡᱩᱫᱤ (tok != ')') {
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

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_DO) {
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

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_SWITCH) {
        sa_nracanaa switch_t *sw;

        sw = tcc_mallocz(parimaa_na *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ᱡᱩᱫᱤ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, NULL);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ᱡᱩᱫᱤ (sw->nocode_wanted)
            goto skip_switch;
        case_sort(sw);
        sw->bsym = NULL; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ᱡᱩᱫᱤ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        ᱵᱟᱝ
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_CASE) {
        sa_nracanaa case_t *cr;
        ᱡᱩᱫᱤ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(parimaa_na(sa_nracanaa case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(expr_const64(), t);
        ᱡᱩᱫᱤ (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(expr_const64(), t);
            ᱡᱩᱫᱤ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ᱡᱩᱫᱤ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->line = file->line_num;
        skip(':');
        goto block_after_label;

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_DEFAULT) {
        ᱡᱩᱫᱤ (!cur_switch)
            expect("switch");
        ᱡᱩᱫᱤ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        goto block_after_label;

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ᱡᱩᱫᱤ (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            ᱡᱩᱫᱤ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } ᱵᱟᱝ ᱡᱩᱫᱤ (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            ᱡᱩᱫᱤ (!s)
              s = label_push(&global_label_stack, tok, LABEL_FORWARD);
            ᱵᱟᱝ ᱡᱩᱫᱤ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ᱡᱩᱫᱤ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ᱡᱩᱫᱤ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } ᱵᱟᱝ {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } ᱵᱟᱝ {
            expect("label identifier");
        }
        skip(';');

    } ᱵᱟᱝ ᱡᱩᱫᱤ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } ᱵᱟᱝ {
        ᱡᱩᱫᱤ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            ᱡᱩᱫᱤ (s) {
                ᱡᱩᱫᱤ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, NULL));
                s->r = LABEL_DEFINED;
		ᱡᱩᱫᱤ (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    for (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_pop(&s->next, NULL, 0);
		} ᱵᱟᱝ
		  gsym(s->jnext);
            } ᱵᱟᱝ {
                s = label_push(&global_label_stack, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(NULL);

            ᱡᱩᱫᱤ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ᱡᱩᱫᱤ (tok != '}') {
                ᱡᱩᱫᱤ (0 == (flags & STMT_COMPOUND))
                    goto again;
                /* C23: insert implicit null-statement whithin compound statement */
            } ᱵᱟᱝ {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } ᱵᱟᱝ {
            /* expression case */
            ᱡᱩᱫᱤ (t != ';') {
                unget_tok(t);
    expr:
                ᱡᱩᱫᱤ (flags & STMT_EXPR) {
                    vpop();
                    gexpr();
                } ᱵᱟᱝ {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ᱡᱩᱫᱤ (debug_modes)
        tcc_tcov_check_line (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
static void skip_or_save_block(TokenString **str)
{
    puur_naa_nka braces = tok == '{';
    puur_naa_nka level = 0;
    ᱡᱩᱫᱤ (str)
      *str = tok_str_alloc();

    ᱡᱚᱠᱷᱚᱱ (1) {
	puur_naa_nka t = tok;
        ᱡᱩᱫᱤ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             bha_nga;
	ᱡᱩᱫᱤ (t == TOK_EOF) {
	     ᱡᱩᱫᱤ (str || level > 0)
	       tcc_error("unexpected end of file");
	     ᱵᱟᱝ
	       bha_nga;
	}
	ᱡᱩᱫᱤ (str)
	  tok_str_add_tok(*str);
	next();
	ᱡᱩᱫᱤ (t == '{' || t == '(' || t == '[') {
	    level++;
	} ᱵᱟᱝ ᱡᱩᱫᱤ (t == '}' || t == ')' || t == ']') {
	    level--;
	    ᱡᱩᱫᱤ (level == 0 && braces && t == '}')
	      bha_nga;
	}
    }
    ᱡᱩᱫᱤ (str)
	tok_str_add(*str, TOK_EOF);
}

#define EXPR_CONST 1
#define EXPR_ANY   2

static void parse_init_elem(puur_naa_nka expr_type)
{
    puur_naa_nka saved_global_expr;
    switch(expr_type) {
    pak_sa EXPR_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_expr = global_expr;
        global_expr = 1;
        expr_const1();
        global_expr = saved_global_expr;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ᱡᱩᱫᱤ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        bha_nga;
    pak_sa EXPR_ANY:
        expr_eq();
        bha_nga;
    }
}

#ᱡᱩᱫᱤ 1
static void init_assert(init_params *p, puur_naa_nka offset)
{
    ᱡᱩᱫᱤ (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#ᱵᱟᱝ
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
static void init_putz(init_params *p, unsigned long c, puur_naa_nka size)
{
    init_assert(p, c + size);
    ᱡᱩᱫᱤ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } ᱵᱟᱝ {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#ᱡᱩᱫᱤ defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
static void decl_design_delrels(Section *sec, puur_naa_nka c, puur_naa_nka size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    ᱡᱩᱫᱤ (!sec || !sec->reloc)
        ᱨᱩᱣᱟᱹᱲ;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    ᱡᱚᱠᱷᱚᱱ (rel < rel_end) {
        ᱡᱩᱫᱤ (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= parimaa_na *rel;
        } ᱵᱟᱝ {
            ᱡᱩᱫᱤ (rel2 != rel)
                memcpy(rel2, rel, parimaa_na *rel);
            ++rel2;
        }
        ++rel;
    }
}

static void decl_design_flex(init_params *p, Sym *ref, puur_naa_nka index)
{
    ᱡᱩᱫᱤ (ref == p->flex_array_ref) {
        ᱡᱩᱫᱤ (index >= ref->c)
            ref->c = index + 1;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
static puur_naa_nka decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, puur_naa_nka flags, puur_naa_nka al)
{
    Sym *s, *f;
    puur_naa_nka index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    ᱡᱩᱫᱤ (flags & DIF_HAVE_ELEM)
        goto no_designator;

    ᱡᱩᱫᱤ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        ᱡᱩᱫᱤ (tok == ':')
            goto struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    ᱡᱚᱠᱷᱚᱱ (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ᱡᱩᱫᱤ (tok == '[') {
            ᱡᱩᱫᱤ (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = expr_const();
            ᱡᱩᱫᱤ (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = expr_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            ᱡᱩᱫᱤ (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            ᱡᱩᱫᱤ (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } ᱵᱟᱝ {
            puur_naa_nka cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            ᱡᱩᱫᱤ (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = NULL;
    }
    ᱡᱩᱫᱤ (!cur_field) {
        ᱡᱩᱫᱤ (tok == '=') {
            next();
        } ᱵᱟᱝ ᱡᱩᱫᱤ (!gnu_ext) {
	    expect("=");
        }
    } ᱵᱟᱝ {
    no_designator:
        ᱡᱩᱫᱤ (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            ᱡᱩᱫᱤ (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } ᱵᱟᱝ {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    ᱡᱚᱠᱷᱚᱱ (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            ᱡᱩᱫᱤ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ᱡᱩᱫᱤ (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ᱡᱩᱫᱤ (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    ᱡᱩᱫᱤ (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        puur_naa_nka i;
        ᱡᱩᱫᱤ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ᱡᱩᱫᱤ (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        ᱵᱟᱝ
	    vset(type, VT_LOCAL|VT_LVAL, c);
        for (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    ᱡᱩᱫᱤ (c - corig > al)
      al = c - corig;
    ᱨᱩᱣᱟᱹᱲ al;
}

static void write_ldouble(unsigned var_na *d, void *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    ᱡᱩᱫᱤ (LDOUBLE_SIZE >= 10) {
        dviguu_na b = *(long dviguu_na*)s;
        s = &b;
#ᱵᱟᱝ
    ᱡᱩᱫᱤ (parimaa_na (long dviguu_na) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        puur_naa_nka e = m >> 48;
        puur_naa_nka f = e >> 4 & 0x7FF;
        m <<= 11;
        ᱡᱩᱫᱤ (0 == f) {
            ᱡᱩᱫᱤ (0 == m)
                goto set;
            for (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ᱡᱩᱫᱤ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #ᱡᱩᱫᱤ (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #elif LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } ᱵᱟᱝ {
    #ᱡᱩᱫᱤ LDOUBLE_SIZE == 8
        /* long double -> double */
        dviguu_na b = *(long dviguu_na*)s;
        memcpy(d, &b, 8);
    #elif (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #elif (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        puur_naa_nka e = *(uint16_t*)((var_na*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #elif (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((var_na*)s + 6);
        puur_naa_nka e = read16le((var_na*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #ᱵᱟᱝ
        /* unknown */
        ᱡᱩᱫᱤ (parimaa_na (long dviguu_na) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
static void init_putv(init_params *p, CType *type, unsigned long c)
{
    puur_naa_nka bt;
    void *ptr;
    CType dtype;
    puur_naa_nka size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    ᱡᱩᱫᱤ (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    ᱡᱩᱫᱤ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ᱡᱩᱫᱤ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ᱡᱩᱫᱤ (NODATA_WANTED) {
            vtop--;
            ᱨᱩᱣᱟᱹᱲ;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	ᱡᱩᱫᱤ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_value + (puur_naa_nka)vtop->c.i, size);
	    ᱡᱩᱫᱤ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		ᱡᱚᱠᱷᱚᱱ (relofs >= parimaa_na(*rel)) {
                    relofs -= parimaa_na(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    ᱡᱩᱫᱤ (rel->r_offset >= esym->st_value + size)
		      continue;
		    ᱡᱩᱫᱤ (rel->r_offset < esym->st_value)
		      bha_nga;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_value,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ᱡᱩᱫᱤ PTR_SIZE == 8
				   rel->r_addend
#ᱵᱟᱝ
				   0
#endif
				  );
		}
	    }
	} ᱵᱟᱝ {
            ᱡᱩᱫᱤ (type->t & VT_BITFIELD) {
                puur_naa_nka bit_pos, bit_size, bits, n;
                unsigned var_na *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned var_na*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                ᱡᱚᱠᱷᱚᱱ (bit_size) {
                    n = 8 - bit_pos;
                    ᱡᱩᱫᱤ (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } ᱵᱟᱝ
            switch(bt) {
	    pak_sa VT_BOOL:
		*(var_na *)ptr = val != 0;
                bha_nga;
	    pak_sa VT_BYTE:
		*(var_na *)ptr = val;
		bha_nga;
	    pak_sa VT_SHORT:
                write16le(ptr, val);
		bha_nga;
	    pak_sa VT_FLOAT:
                write32le(ptr, val);
		bha_nga;
	    pak_sa VT_DOUBLE:
                write64le(ptr, val);
		bha_nga;
	    pak_sa VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		bha_nga;

#ᱡᱩᱫᱤ PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    pak_sa VT_LLONG:
	    pak_sa VT_PTR:
	        ᱡᱩᱫᱤ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        ᱵᱟᱝ
	          write64le(ptr, val);
	        bha_nga;
            pak_sa VT_INT:
                write32le(ptr, val);
                bha_nga;
#ᱵᱟᱝ
	    pak_sa VT_LLONG:
                write64le(ptr, val);
                bha_nga;
            pak_sa VT_PTR:
            pak_sa VT_INT:
	        ᱡᱩᱫᱤ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        bha_nga;
#endif
	    default:
                //tcc_internal_error("unexpected type");
                bha_nga;
	    }
	}
        vtop--;
    } ᱵᱟᱝ {
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
static void decl_initializer(init_params *p, CType *type, unsigned long c, puur_naa_nka flags)
{
    puur_naa_nka len, n, no_oblock, i;
    puur_naa_nka size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ᱡᱩᱫᱤ (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_line(tcc_state), tcc_tcov_check_line (tcc_state, 1);

    ᱡᱩᱫᱤ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        puur_naa_nka ncw_prev = nocode_wanted;
        ᱡᱩᱫᱤ ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? EXPR_ANY : EXPR_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ᱡᱩᱫᱤ (type->t & VT_ARRAY) {
        no_oblock = 1;
        ᱡᱩᱫᱤ (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        ᱡᱩᱫᱤ ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#ᱵᱟᱝ
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ᱡᱩᱫᱤ (size1 != (tok == TOK_STR ? 1 : parimaa_na(nwchar_t)))
              tcc_error("unhandled string literal merging");
            ᱡᱚᱠᱷᱚᱱ (tok == TOK_STR || tok == TOK_LSTR) {
                ᱡᱩᱫᱤ (initstr.size)
                  initstr.size -= size1;
                ᱡᱩᱫᱤ (tok == TOK_STR)
                  len += tokc.str.size;
                ᱵᱟᱝ
                  len += tokc.str.size / parimaa_na(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            ᱡᱩᱫᱤ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                goto do_init_array;
            }

            decl_design_flex(p, s, len);
            ᱡᱩᱫᱤ (!(flags & DIF_SIZE_ONLY)) {
                puur_naa_nka nb = n, ch;
                ᱡᱩᱫᱤ (len < nb)
                    nb = len;
                ᱡᱩᱫᱤ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ᱡᱩᱫᱤ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ᱡᱩᱫᱤ (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } ᱵᱟᱝ {
                    for(i=0;i<n;i++) {
                        ᱡᱩᱫᱤ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ᱡᱩᱫᱤ (flags & DIF_CLEAR)
                            bha_nga;
                          ᱡᱩᱫᱤ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            bha_nga;
                          }
                          ch = 0;
                        } ᱵᱟᱝ ᱡᱩᱫᱤ (size1 == 1)
                          ch = ((unsigned var_na *)initstr.data)[i];
                        ᱵᱟᱝ
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ᱡᱩᱫᱤ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } ᱵᱟᱝ {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ᱡᱩᱫᱤ (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    ᱡᱚᱠᱷᱚᱱ (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ᱡᱩᱫᱤ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ᱡᱩᱫᱤ (no_oblock && len >= n*size1)
		        bha_nga;
		} ᱵᱟᱝ {
		    ᱡᱩᱫᱤ (s->type.t == VT_UNION)
		        f = NULL;
		    ᱵᱟᱝ
		        f = f->next;
		    ᱡᱩᱫᱤ (no_oblock && f == NULL)
		        bha_nga;
		}

		ᱡᱩᱫᱤ (tok == '}')
		    bha_nga;
		skip(',');
	    }
        }
        ᱡᱩᱫᱤ (!no_oblock)
            skip('}');

    } ᱵᱟᱝ ᱡᱩᱫᱤ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        goto one_elem;

    } ᱵᱟᱝ ᱡᱩᱫᱤ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ᱡᱩᱫᱤ ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	goto do_init_list;

    } ᱵᱟᱝ ᱡᱩᱫᱤ (tok == '{') {
        ᱡᱩᱫᱤ (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } ᱵᱟᱝ one_elem: ᱡᱩᱫᱤ ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ᱡᱩᱫᱤ (flags & DIF_HAVE_ELEM)
            vpop();
        ᱵᱟᱝ
            skip_or_save_block(NULL);

    } ᱵᱟᱝ {
	ᱡᱩᱫᱤ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ᱡᱩᱫᱤ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? EXPR_ANY : EXPR_CONST);
	}
        ᱡᱩᱫᱤ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        ᱵᱟᱝ
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
static void decl_initializer_alloc(CType *type, AttributeDef *ad, puur_naa_nka r, 
                                   puur_naa_nka has_init, puur_naa_nka v, puur_naa_nka scope)
{
    puur_naa_nka size, align, addr;
    TokenString *init_str = NULL;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = NULL;
    puur_naa_nka saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    puur_naa_nka bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    ᱡᱩᱫᱤ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        ᱡᱩᱫᱤ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ᱡᱩᱫᱤ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                ᱨᱩᱣᱟᱹᱲ;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ᱡᱩᱫᱤ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = NULL;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ᱡᱩᱫᱤ (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ᱡᱩᱫᱤ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ᱡᱩᱫᱤ (IS_BT_ARRAY(type->t))
            type->ref = sym_push(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } ᱵᱟᱝ ᱡᱩᱫᱤ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        ᱡᱩᱫᱤ (field) {
            ᱡᱚᱠᱷᱚᱱ (field->next)
                field = field->next;
            ᱡᱩᱫᱤ (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    ᱡᱩᱫᱤ (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ᱡᱩᱫᱤ (!has_init)
            goto err_size;
        ᱡᱩᱫᱤ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            ᱡᱚᱠᱷᱚᱱ (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } ᱵᱟᱝ
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
        ᱡᱩᱫᱤ (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ᱡᱩᱫᱤ (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ᱡᱩᱫᱤ (ad->a.aligned) {
	puur_naa_nka speca = 1 << (ad->a.aligned - 1);
        ᱡᱩᱫᱤ (speca > align)
            align = speca;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (ad->a.packed) {
        align = 1;
    }

    ᱡᱩᱫᱤ (!v && NODATA_WANTED)
        size = 0, align = 1;

    ᱡᱩᱫᱤ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = NULL;
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        ᱡᱩᱫᱤ (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    ᱡᱩᱫᱤ (ad->asm_label) {
		puur_naa_nka reg = asm_parse_regvar(ad->asm_label);
		ᱡᱩᱫᱤ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_push(v, type, r, addr);
	    ᱡᱩᱫᱤ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } ᱵᱟᱝ {
            /* push local reference */
            vset(type, r, addr);
        }
    } ᱵᱟᱝ {
        CType *tp = type;
        puur_naa_nka is_const;

        ᱡᱚᱠᱷᱚᱱ ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ᱡᱩᱫᱤ (!sec) {
            ᱡᱩᱫᱤ (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (is_const) {
		sec = rodata_section;
            } ᱵᱟᱝ ᱡᱩᱫᱤ (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } ᱵᱟᱝ ᱡᱩᱫᱤ (tcc_state->nocommon)
                sec = bss_section;
        } ᱵᱟᱝ ᱡᱩᱫᱤ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ᱡᱩᱫᱤ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ᱡᱩᱫᱤ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        ᱡᱩᱫᱤ (bcheck)
            size = size + 1; /* add padding */
#endif
        ᱡᱩᱫᱤ (sec) {
	    addr = section_add(sec, size, align);
        } ᱵᱟᱝ {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ᱡᱩᱫᱤ (v) {
            ᱡᱩᱫᱤ (!sym) {
                sym = sym_push(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, NULL);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } ᱵᱟᱝ {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ᱡᱩᱫᱤ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * parimaa_na(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    ᱡᱩᱫᱤ (type->t & VT_VLA) {
        puur_naa_nka a;

        ᱡᱩᱫᱤ (has_init)
            tcc_error("variable length array cannot be initialized");

        ᱡᱩᱫᱤ (NODATA_WANTED)
            goto no_alloc;

        /* save before-VLA stack pointer if needed */
        ᱡᱩᱫᱤ (cur_scope->vla.num == 0) {
            ᱡᱩᱫᱤ (cur_scope->prev && cur_scope->prev->vla.num) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } ᱵᱟᱝ {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#ᱡᱩᱫᱤ defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.num++;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ᱡᱩᱫᱤ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ᱡᱩᱫᱤ (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
static void func_vla_arg_code(Sym *arg)
{
    puur_naa_nka align;
    TokenString *vla_array_tok = NULL;

    ᱡᱩᱫᱤ (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    ᱡᱩᱫᱤ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

static void func_vla_arg(Sym *sym)
{
    Sym *arg;

    for (arg = sym->type.ref->next; arg; arg = arg->next)
        ᱡᱩᱫᱤ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, puur_naa_nka c, puur_naa_nka byref)
{
    s = sym_find(s->v);
    ᱡᱩᱫᱤ (!s) /* unnamed parameters, not enabled */
        ᱨᱩᱣᱟᱹᱲ NULL;
    s->c = c;
    ᱡᱩᱫᱤ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    ᱨᱩᱣᱟᱹᱲ s;
}

/* push parameters (and their types), last first */
static void sym_push_params(Sym *ref)
{
    Sym *s = ref;
    ᱡᱚᱠᱷᱚᱱ (s->next)
        s = s->next;
    ᱡᱚᱠᱷᱚᱱ (s != ref) {
        ᱡᱩᱫᱤ ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_stack);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
static void gen_function(Sym *sym)
{
    sa_nracanaa scope f = { 0 };

    cur_scope = root_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    ᱡᱩᱫᱤ (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, NULL);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    ᱡᱩᱫᱤ (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    ᱡᱩᱫᱤ (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_stack, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_push_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(NULL, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_pop(&local_stack, NULL, 0);
    label_pop(&global_label_stack, NULL, 0);
    sym_pop(&all_cleanups, NULL, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = NULL;
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

static void gen_inline_functions(TCCState *s)
{
    Sym *sym;
    puur_naa_nka inline_generated, i;
    sa_nracanaa InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    do {
        inline_generated = 0;
        for (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ᱡᱩᱫᱤ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = NULL;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } ᱡᱚᱠᱷᱚᱱ (inline_generated);
    tcc_close();
}

static void free_inline_functions(TCCState *s)
{
    puur_naa_nka i;
    /* free tokens of unused inline functions */
    for (i = 0; i < s->nb_inline_fns; ++i) {
        sa_nracanaa InlineFunc *fn = s->inline_fns[i];
        ᱡᱩᱫᱤ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

static void do_Static_assert(void)
{
    puur_naa_nka c;
    const var_na *msg;

    next();
    skip('(');
    c = expr_const();
    msg = "_Static_assert fail";
    ᱡᱩᱫᱤ (tok == ',') {
        next();
        msg = parse_mult_str("string constant")->data;
    }
    skip(')');
    ᱡᱩᱫᱤ (c == 0)
        tcc_error("%s", msg);
    skip(';');
}

#ifdef TCC_TARGET_PE
static void pe_check_linkage(CType *type, AttributeDef *ad)
{
    ᱡᱩᱫᱤ (!ad->a.dllimport && !ad->a.dllexport)
        ᱨᱩᱣᱟᱹᱲ;
    ᱡᱩᱫᱤ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ᱡᱩᱫᱤ (type->t & VT_TYPEDEF) {
        const var_na *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } ᱵᱟᱝ ᱡᱩᱫᱤ (ad->a.dllimport) {
        ᱡᱩᱫᱤ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        ᱵᱟᱝ
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
static puur_naa_nka decl(puur_naa_nka l)
{
    puur_naa_nka v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    ᱡᱚᱠᱷᱚᱱ (1) {

        oldint = 0;
        ᱡᱩᱫᱤ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ᱡᱩᱫᱤ (l == VT_JMP)
                ᱨᱩᱣᱟᱹᱲ 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ᱡᱩᱫᱤ (tok == ';' && l != VT_CMP) {
                next();
                continue;
            }
            ᱡᱩᱫᱤ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                continue;
            }
            ᱡᱩᱫᱤ (l != VT_CONST)
                bha_nga;
            ᱡᱩᱫᱤ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                continue;
            }
            ᱡᱩᱫᱤ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } ᱵᱟᱝ {
                ᱡᱩᱫᱤ (tok != TOK_EOF)
                    expect("declaration");
                bha_nga;
            }
        }

        ᱡᱩᱫᱤ (tok == ';') {
            ᱡᱩᱫᱤ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            ᱵᱟᱝ ᱡᱩᱫᱤ (IS_ENUM(btype.t))
                ; /* enum decl */
            ᱵᱟᱝ
                tcc_warning("useless type defines no instances");
            ᱡᱩᱫᱤ (l == VT_JMP)
                ᱨᱩᱣᱟᱹᱲ 1;
            next();
            continue;
        }

        ᱡᱚᱠᱷᱚᱱ (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            ᱡᱩᱫᱤ ((type.t & VT_BTYPE) == VT_FUNC) {
                ᱡᱩᱫᱤ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ᱡᱩᱫᱤ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ᱡᱩᱫᱤ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ᱡᱩᱫᱤ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    ᱵᱟᱝ
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } ᱵᱟᱝ ᱡᱩᱫᱤ (oldint) {
                tcc_warning("type defaults to int");
            }

            ᱡᱩᱫᱤ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ᱡᱩᱫᱤ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ᱡᱩᱫᱤ (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            ᱡᱩᱫᱤ (tok == '{') {
                ᱡᱩᱫᱤ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ᱡᱩᱫᱤ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                for (sa = sym->type.ref; (sa = sa->next) != NULL;) {
                    ᱡᱩᱫᱤ (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    ᱡᱩᱫᱤ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ᱡᱩᱫᱤ (sym->type.t & VT_INLINE) {
                    sa_nracanaa InlineFunc *fn;
                    fn = tcc_malloc(parimaa_na *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } ᱵᱟᱝ {
                    /* compute text section */
                    cur_text_section = text_section;
                    ᱡᱩᱫᱤ (ad.section) {
                        cur_text_section = ad.section;
                        ᱡᱩᱫᱤ (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                bha_nga;
            } ᱵᱟᱝ {
                has_init = 0;
		ᱡᱩᱫᱤ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    for (sym = func_vt.ref->next; sym; sym = sym->next)
			ᱡᱩᱫᱤ ((sym->v & ~SYM_FIELD) == v)
			    goto found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, NULL));
                found:
		    ᱡᱩᱫᱤ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, NULL));
		    ᱡᱩᱫᱤ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, NULL));
		    convert_parameter_type(&type);
		    sym->type = type;
		} ᱵᱟᱝ ᱡᱩᱫᱤ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    ᱡᱩᱫᱤ (sym && sym->sym_scope == local_scope) {
                        ᱡᱩᱫᱤ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, NULL));
                        sym->type = type;
                    } ᱵᱟᱝ {
                        sym = sym_push(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ᱡᱩᱫᱤ ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    ᱡᱩᱫᱤ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} ᱵᱟᱝ ᱡᱩᱫᱤ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } ᱵᱟᱝ {
                    r = 0;
                    ᱡᱩᱫᱤ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } ᱵᱟᱝ ᱡᱩᱫᱤ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ᱡᱩᱫᱤ (tok == '=')
                        has_init = 1;

                    ᱡᱩᱫᱤ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } ᱵᱟᱝ {
                        ᱡᱩᱫᱤ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        ᱵᱟᱝ
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ᱡᱩᱫᱤ (has_init)
                            next();
                        ᱵᱟᱝ ᱡᱩᱫᱤ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ᱡᱩᱫᱤ (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        ᱡᱩᱫᱤ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_value, esym->st_size, 1);
                    }
                }
                ᱡᱩᱫᱤ (tok != ',') {
                    ᱡᱩᱫᱤ (l == VT_JMP)
                        ᱨᱩᱣᱟᱹᱲ has_init ? v : 1;
                    skip(';');
                    bha_nga;
                }
                next();
            }
        }
    }
    ᱨᱩᱣᱟᱹᱲ 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
