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
#شامل "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA صحیح rsym, anon_sym, ind, loc;

ST_DATA Sym *global_پشته;
ST_DATA Sym *local_پشته;
ST_DATA Sym *define_پشته;
ST_DATA Sym *global_label_پشته;
ST_DATA Sym *local_label_پشته;

ایستا Sym *sym_free_first;
ایستا تهی **sym_pools;
ایستا صحیح nb_sym_pools;

ایستا Sym *all_cleanups, *pending_gotos;
ایستا صحیح local_scope;
ST_DATA نویسه debug_modes;

ST_DATA SValue *vtop;
ایستا SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA صحیح nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() اگر(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA صحیح global_عبارت;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA صحیح func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA صحیح func_vc; /* stack address for implicit struct return storage */
ST_DATA صحیح func_ind; /* function start address */
ایستا صحیح func_old;
ST_DATA ثابت نویسه *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
ایستا CString initstr;

#اگر PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#وگرنهاگر LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#وگرنه
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

ایستا ساختار switch_t {
    ساختار case_t {
        int64_t v1, v2;
        صحیح ind, سطر;
    } **p; صحیح n; /* list of case ranges */
    صحیح def_sym; /* default symbol */
    صحیح nocode_wanted;
    صحیح *bsym;
    ساختار scope *scope;
    ساختار switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_عدد 8
/*list of temporary local variables on the stack in current function. */
ایستا ساختار temp_local_variable {
	صحیح location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_عدد];
ایستا صحیح nb_temp_local_vars;

ایستا ساختار scope {
    ساختار scope *prev;
    ساختار { صحیح loc, locorig, رقم; } vla;
    ساختار { Sym *s; صحیح n; } cl;
    صحیح *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *ریشه_scope;

تعریفنوع ساختار {
    Section *sec;
    صحیح local_offset;
    Sym *flex_array_ref;
} init_params;

#اگر 1
#define precedence_parser
ایستا تهی init_prec(تهی);
#endif

ایستا تهی block(صحیح flags);
#define STMT_عبارت 1
#define STMT_COMPOUND 2

ایستا تهی gen_cast(CType *type);
ایستا تهی gen_cast_s(صحیح t);
ایستا درونخطی CType *pointed_type(CType *type);
ایستا تهی check_restrict_type(CType *type);
ایستا صحیح type_qualifiers(CType *type);
ایستا تهی parse_btype_qualify(CType *type, صحیح qualifiers);
ایستا صحیح is_compatible_types(CType *type1, CType *type2);
ایستا صحیح parse_btype(CType *type, AttributeDef *ad, صحیح ignore_label);
ایستا CType *type_decl(CType *type, AttributeDef *ad, صحیح *v, صحیح td);
ایستا تهی parse_عبارت_type(CType *type);
ایستا تهی init_putv(init_params *p, CType *type, unsigned long c);
ایستا تهی decl_initializer(init_params *p, CType *type, unsigned long c, صحیح flags);
ایستا تهی decl_initializer_alloc(CType *type, AttributeDef *ad, صحیح r, صحیح has_init, صحیح v, صحیح scope);
ایستا صحیح decl(صحیح l);
ایستا تهی عبارت_eq(تهی);
ایستا تهی vpush_type_size(CType *type, صحیح *a);
ایستا صحیح is_compatible_unqualified_types(CType *type1, CType *type2);
ایستا درونخطی int64_t عبارت_const64(تهی);
ایستا تهی vpush64(صحیح ty, unsigned long long v);
ایستا تهی vpush(CType *type);
ایستا صحیح gvtst(صحیح inv, صحیح t);
ایستا تهی gen_inline_functions(TCCState *s);
ایستا تهی free_inline_functions(TCCState *s);
ایستا تهی skip_or_save_block(TokenString **str);
ایستا تهی gv_dup(تهی);
ایستا صحیح get_temp_local_var(صحیح size,صحیح align,صحیح *r2);
ایستا تهی cast_error(CType *st, CType *dt);
ایستا تهی end_switch(تهی);
ایستا تهی do_Static_assert(تهی);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC تهی gsym(صحیح t)
{
  اگر (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
ایستا صحیح gind()
{
  صحیح t = ind;
  CODE_ON();
  اگر (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  بازگشت t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
ایستا تهی gjmp_addr_acs(صحیح t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
ایستا صحیح gjmp_acs(صحیح t)
{
  t = gjmp(t);
  CODE_OFF();
  بازگشت t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN صحیح is_float(صحیح t)
{
    صحیح bt = t & VT_BTYPE;
    بازگشت bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

ایستا درونخطی صحیح is_integer_btype(صحیح bt)
{
    بازگشت bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

ایستا صحیح btype_size(صحیح bt)
{
    بازگشت bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
ایستا صحیح R_RET(صحیح t)
{
    اگر (!is_float(t))
        بازگشت REG_IRET;
#ifdef TCC_TARGET_X86_64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        بازگشت TREG_ST0;
#وگرنهاگر defined TCC_TARGET_RISCV64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        بازگشت REG_IRET;
#endif
    بازگشت REG_FRET;
}

/* returns 2nd function return register, if any */
ایستا صحیح R2_RET(صحیح t)
{
    t &= VT_BTYPE;
#اگر PTR_SIZE == 4
    اگر (t == VT_LLONG)
        بازگشت REG_IRE2;
#وگرنهاگر defined TCC_TARGET_X86_64
    اگر (t == VT_QLONG)
        بازگشت REG_IRE2;
    اگر (t == VT_QFLOAT)
        بازگشت REG_FRE2;
#وگرنهاگر defined TCC_TARGET_RISCV64
    اگر (t == VT_LDOUBLE)
        بازگشت REG_IRE2;
#endif
    بازگشت VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_واژگان(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
ایستا تهی PUT_R_RET(SValue *sv, صحیح t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
ایستا صحیح RC_RET(صحیح t)
{
    بازگشت reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
ایستا صحیح RC_TYPE(صحیح t)
{
    اگر (!is_float(t))
        بازگشت RC_INT;
#ifdef TCC_TARGET_X86_64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        بازگشت RC_ST0;
    اگر ((t & VT_BTYPE) == VT_QFLOAT)
        بازگشت RC_FRET;
#وگرنهاگر defined TCC_TARGET_RISCV64
    اگر ((t & VT_BTYPE) == VT_LDOUBLE)
        بازگشت RC_INT;
#endif
    بازگشت RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
ایستا صحیح RC2_TYPE(صحیح t, صحیح rc)
{
    اگر (!USING_TWO_واژگان(t))
        بازگشت 0;
#ifdef RC_IRE2
    اگر (rc == RC_IRET)
        بازگشت RC_IRE2;
#endif
#ifdef RC_FRE2
    اگر (rc == RC_FRET)
        بازگشت RC_FRE2;
#endif
    اگر (rc & RC_FLOAT)
        بازگشت RC_FLOAT;
    بازگشت RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC صحیح ieee_finite(دوگانه d)
{
    صحیح p[4];
    memcpy(p, &d, اندازه(دوگانه));
    بازگشت ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC تهی test_lvalue(تهی)
{
    اگر (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC تهی check_vstack(تهی)
{
    اگر (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (صحیح)(vtop - vstack + 1));
}

#اگر 0
/* dump 'b' vstack entries starting with 'a'  */
تهی pv (ثابت نویسه *lbl, صحیح a, صحیح b)
{
    صحیح i;
    برای (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (صحیح)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
ایستا درونخطی تهی psyms(ثابت نویسه *پیام, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", پیام);
    وقتی (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

ایستا تهی type_to_str(نویسه *buf, صحیح buf_size, CType *type, ثابت نویسه *varstr);

/* print type */
ایستا تهی ptype(ثابت نویسه *پیام, CType *type, صحیح v)
{
    نویسه buf[500];
    type_to_str(buf, اندازه(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, پوچ) : پوچ);
    printf("%s : %s;\n", پیام, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC تهی tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, اندازه *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    اگر (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_افزودن(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC صحیح tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_عبارت = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_رقم | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#اگر TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    بازگشت 0;
}

ST_FUNC تهی tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_برداشت(&global_پشته, پوچ, 0);
    sym_برداشت(&local_پشته, پوچ, 0);
    /* free preprocessor macros */
    free_defines(پوچ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    وقتی (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = پوچ;
    all_cleanups = پوچ;
    pending_gotos = پوچ;
    nb_temp_local_vars = 0;
    global_label_پشته = پوچ;
    local_label_پشته = پوچ;
    cur_text_section = پوچ;
    sym_free_first = پوچ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  اگر (!s || !s->c)
    بازگشت پوچ;
  بازگشت &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC تهی update_storage(Sym *sym)
{
    ElfSym *esym;
    صحیح sym_bind, old_sym_bind;

    esym = elfsym(sym);
    اگر (!esym)
        بازگشت;

    اگر (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    اگر (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    وگرنه اگر (sym->a.weak)
        sym_bind = STB_WEAK;
    وگرنه
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    اگر (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    اگر (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    اگر (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#اگر 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, پوچ),
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

ST_FUNC تهی put_extern_sym2(Sym *sym, صحیح sh_رقم,
                            addr_t مقدار, unsigned long size,
                            صحیح can_add_underscore)
{
    صحیح sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ثابت نویسه *name;
    نویسه buf1[256];

    اگر (!sym->c) {
        name = get_tok_str(sym->v, پوچ);
        t = sym->type.t;
        اگر ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } وگرنه اگر ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            اگر (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } وگرنه اگر (t & VT_TLS) {
            sym_type = STT_TLS;
        } وگرنه {
            sym_type = STT_OBJECT;
        }
        اگر (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        وگرنه
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        اگر (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            اگر (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            اگر (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        اگر (sym->asm_label) {
            name = get_tok_str(sym->asm_label, پوچ);
            can_add_underscore = 0;
        }

        اگر (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, اندازه(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, مقدار, size, info, other, sh_رقم, name);

        اگر (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_رقم, sym_bind, sym_type);

    } وگرنه {
        esym = elfsym(sym);
        esym->st_مقدار = مقدار;
        esym->st_size = size;
        esym->st_shndx = sh_رقم;
    }
    update_storage(sym);
}

ST_FUNC تهی put_extern_sym(Sym *sym, Section *s, addr_t مقدار, unsigned long size)
{
    اگر (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        بازگشت;
    put_extern_sym2(sym, s ? s->sh_رقم : SHN_UNDEF, مقدار, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC تهی greloca(Section *s, Sym *sym, unsigned long offset, صحیح type,
                     addr_t addend)
{
    صحیح c = 0;

    اگر (nocode_wanted && s == cur_text_section)
        بازگشت;

    اگر (sym) {
        اگر (0 == sym->c) {
            put_extern_sym(sym, پوچ, 0, 0);
            اگر (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                وقتی (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#اگر PTR_SIZE == 4
ST_FUNC تهی greloc(Section *s, Sym *sym, unsigned long offset, صحیح type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
ایستا Sym *__sym_malloc(تهی)
{
    Sym *sym_pool, *sym, *last_sym;
    صحیح i;

    sym_pool = tcc_malloc(SYM_POOL_NB * اندازه(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    برای(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    بازگشت last_sym;
}

ایستا درونخطی Sym *sym_malloc(تهی)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    اگر (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    بازگشت sym;
#وگرنه
    sym = tcc_malloc(اندازه(Sym));
    بازگشت sym;
#endif
}

ST_INLN تهی sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#وگرنه
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, صحیح v, صحیح t, صحیح c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, اندازه *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    بازگشت s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, صحیح v)
{
    وقتی (s) {
        اگر (s->v == v)
            بازگشت s;
        s = s->prev;
    }
    بازگشت پوچ;
}

/* structure lookup */
ST_INLN Sym *struct_find(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        بازگشت پوچ;
    بازگشت table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        بازگشت پوچ;
    بازگشت table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
ایستا درونخطی تهی sym_link(Sym *s, صحیح yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    اگر (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    وگرنه
        ps = &ts->sym_identifier;
    اگر (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } وگرنه {
        *ps = s->prev_tok;
    }
}

ایستا درونخطی صحیح sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    بازگشت IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_افزودن(صحیح v, CType *type, صحیح r, صحیح c)
{
    Sym *s, **ps;
    اگر (local_پشته)
        ps = &local_پشته;
    وگرنه
        ps = &global_پشته;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    اگر ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        اگر (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, پوچ));
    }
    بازگشت s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_افزودن(صحیح v, صحیح t, صحیح c)
{
    Sym *s, **ps;
    s = sym_push2(&global_پشته, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    اگر (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        وقتی (*ps != پوچ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    بازگشت s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC تهی sym_برداشت(Sym **ptop, Sym *b, صحیح keep)
{
    Sym *s, *ss;
    صحیح v;

    s = *ptop;
    وقتی(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        اگر ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	اگر (!keep)
	    sym_free(s);
        s = ss;
    }
    اگر (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        بازگشت پوچ;
    بازگشت table_ident[v]->sym_label;
}

ST_FUNC Sym *label_افزودن(Sym **ptop, صحیح v, صحیح flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    اگر (ptop == &global_label_پشته) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        وقتی (*ps != پوچ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    بازگشت s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC تهی label_برداشت(Sym **ptop, Sym *slast, صحیح keep)
{
    Sym *s, *s1;
    برای(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        اگر (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, پوچ));
        } وگرنه اگر (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, پوچ));
        } وگرنه {
            اگر (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        اگر (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        اگر (!keep)
            sym_free(s);
        وگرنه
            s->r = LABEL_GONE;
    }
    اگر (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
ایستا تهی vcheck_cmp(تهی)
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

    اگر (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

ایستا تهی vsetc(CType *type, صحیح r, CValue *vc)
{
    اگر (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = پوچ;
}

ST_FUNC تهی vswap(تهی)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC تهی vpop(تهی)
{
    صحیح v;
    v = vtop->r & VT_VALMASK;
#اگر defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    اگر (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } وگرنه
#endif
    اگر (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
ایستا تهی vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
ایستا تهی vpush64(صحیح ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = پوچ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC تهی vpushi(صحیح v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
ایستا تهی vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
ایستا درونخطی تهی vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC تهی vset(CType *type, صحیح r, صحیح v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

ایستا تهی vseti(صحیح r, صحیح v)
{
    CType type;
    type.t = VT_INT;
    type.ref = پوچ;
    vset(&type, r, v);
}

ST_FUNC تهی vpushv(SValue *v)
{
    اگر (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

ایستا تهی vdup(تهی)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC تهی vrotb(صحیح n)
{
    SValue tmp;
    اگر (--n < 1)
        بازگشت;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, اندازه *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC تهی vrott(صحیح n)
{
    SValue tmp;
    اگر (--n < 1)
        بازگشت;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, اندازه *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC تهی vrev(صحیح n)
{
    صحیح i;
    SValue tmp;
    vcheck_cmp();
    برای (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC تهی vset_VT_CMP(صحیح op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
ایستا تهی vset_VT_JMP(تهی)
{
    صحیح op = vtop->cmp_op;

    اگر (vtop->jtrue || vtop->jfalse) {
        صحیح origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        صحیح inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } وگرنه {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        اگر (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
ایستا تهی gvtst_set(صحیح inv, صحیح t)
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
ایستا صحیح gvtst(صحیح inv, صحیح t)
{
    صحیح op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    اگر (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    اگر (op > 1)
        t = gjmp_cond(op ^ inv, t);
    وگرنه اگر (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    بازگشت t;
}

/* generate a zero or nozero test */
ایستا تهی gen_test_zero(صحیح op)
{
    اگر (vtop->r == VT_CMP) {
        صحیح j;
        اگر (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } وگرنه {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC تهی vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    صحیح v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_افزودن(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    بازگشت sym;
}

/* push a reference to a section offset by adding a dummy symbol */
ایستا تهی vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(صحیح v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    اگر (!s) {
        /* push forward reference */
        s = global_identifier_افزودن(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } وگرنه اگر (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    بازگشت s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(صحیح v)
{
    CType ct = { VT_ASM_FUNC, پوچ };
    بازگشت external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC تهی vpush_helper_func(صحیح v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
ایستا تهی merge_symattr(ساختار SymAttr *sa, ساختار SymAttr *sa1)
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
ایستا تهی merge_funcattr(ساختار FuncAttr *fa, ساختار FuncAttr *fa1)
{
    اگر (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    اگر (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    اگر (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    اگر (fa1->func_noreturn)
      fa->func_noreturn = 1;
    اگر (fa1->func_ctor)
      fa->func_ctor = 1;
    اگر (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
ایستا تهی merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    اگر (ad1->section)
      ad->section = ad1->section;
    اگر (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    اگر (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    اگر (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
ایستا تهی patch_type(Sym *sym, CType *type)
{
    اگر (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        اگر (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, پوچ));
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
                  get_tok_str(sym->v, پوچ));

    } وگرنه اگر ((sym->type.t & VT_BTYPE) == VT_FUNC) {
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
                get_tok_str(sym->v, پوچ));

        /* set 'inline' if both agree or if one has static */
        اگر ((type->t | sym->type.t) & VT_INLINE) {
            اگر (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        اگر (0 == (type->t & VT_EXTERN)) {
            ساختار FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            اگر (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } وگرنه {
            sym->type.t &= ~VT_INLINE | static_proto;
            اگر (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } وگرنه {
        اگر ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        اگر ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, پوچ));
    }
}

/* Merge some storage attributes.  */
ایستا تهی patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    اگر (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    اگر (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, پوچ));
#endif
    merge_symattr(&sym->a, &ad->a);
    اگر (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
ایستا Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    اگر ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    بازگشت s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
ایستا تهی move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    صحیح n, bt;

    bt = s->type.t & VT_BTYPE;
    اگر (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        بازگشت;

    برای (s = s->type.ref, n = 0; s; s = s->next) {
        برای (lp = &local_پشته; !!(l = *lp); lp = &l->prev) {
            اگر (l == s) {
                *lp = s->prev;
                s->prev = global_پشته, global_پشته = s;
                اگر (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } وگرنه {
                    اگر ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                اگر (bt != VT_PTR)
                    n = 1;
                بشکن;
            }
        }
        اگر (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            بشکن;
    }
}

/* define a new external reference to a symbol 'v' */
ایستا Sym *external_sym(صحیح v, CType *type, صحیح r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    وقتی (s && s->sym_scope)
        s = s->prev_tok;

    اگر (!s) {
        /* push forward reference */
        s = global_identifier_افزودن(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } وگرنه {
        patch_storage(s, ad, type);
    }
    اگر (local_پشته) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_پشته);
    }
    بازگشت s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC تهی save_regs(صحیح n)
{
    SValue *p, *p1;
    برای(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC تهی save_reg(صحیح r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC تهی save_reg_upstack(صحیح r, صحیح n)
{
    صحیح l, size, align, bt, r2;
    SValue *p, *p1, sv;

    اگر ((r &= VT_VALMASK) >= VT_CONST)
        بازگشت;
    اگر (nocode_wanted)
        بازگشت;
    l = r2 = 0;
    برای(p = vstack, p1 = vtop - n; p <= p1; p++) {
        اگر ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            اگر (!l) {
                bt = p->type.t & VT_BTYPE;
                اگر (bt == VT_VOID)
                    ادامه;
                اگر ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = پوچ;
                store(p->r & VT_VALMASK, &sv);
#اگر defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                اگر (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                اگر (p->r2 < VT_CONST && USING_TWO_واژگان(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            اگر (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } وگرنه {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = پوچ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC صحیح get_reg_ex(صحیح rc, صحیح rc2)
{
    صحیح r;
    SValue *p;
    
    برای(r=0;r<NB_REGS;r++) {
        اگر (reg_classes[r] & rc2) {
            صحیح n;
            n=0;
            برای(p = vstack; p <= vtop; p++) {
                اگر ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            اگر (n <= 1)
                بازگشت r;
        }
    }
    بازگشت get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC صحیح get_reg(صحیح rc)
{
    صحیح r;
    SValue *p;

    /* find a free register */
    برای(r=0;r<NB_REGS;r++) {
        اگر (reg_classes[r] & rc) {
            اگر (nocode_wanted)
                بازگشت r;
            برای(p=vstack;p<=vtop;p++) {
                اگر ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    برو notfound;
            }
            بازگشت r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    برای(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        اگر (r < VT_CONST && (reg_classes[r] & rc))
            برو save_found;
        r = p->r & VT_VALMASK;
        اگر (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            بازگشت r;
        }
    }
    /* Should never comes here */
    بازگشت -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
ایستا صحیح get_temp_local_var(صحیح size,صحیح align, صحیح *r2)
{
    صحیح i;
    ساختار temp_local_variable *temp_var;
    SValue *p;
    صحیح r;
    unsigned used = 0;

    /* mark locations that are still in use */
    برای (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	اگر (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    اگر (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_عدد)
	        used |= 1<<r;
	}
    }
    برای (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	اگر(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    بازگشت temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    اگر (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_عدد) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	برو ret_tmp;
    }
    *r2 = VT_CONST;
    بازگشت loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
ایستا تهی move_reg(صحیح r, صحیح s, صحیح t)
{
    SValue sv;

    اگر (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = پوچ;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC تهی gaddrof(تهی)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    اگر ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
ایستا تهی gen_bounded_ptr_add(تهی)
{
    صحیح save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    اگر (save) {
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
    اگر (nocode_wanted)
        بازگشت;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - اندازه(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
ایستا تهی gen_bounded_ptr_deref(تهی)
{
    addr_t func;
    صحیح size, align;
    ElfW_Rel *rel;
    Sym *sym;

    اگر (nocode_wanted)
        بازگشت;

    size = type_size(&vtop->type, &align);
    انتخاب(size) {
    حالت  1: func = TOK___bound_ptr_indir1; بشکن;
    حالت  2: func = TOK___bound_ptr_indir2; بشکن;
    حالت  4: func = TOK___bound_ptr_indir4; بشکن;
    حالت  8: func = TOK___bound_ptr_indir8; بشکن;
    حالت 12: func = TOK___bound_ptr_indir12; بشکن;
    حالت 16: func = TOK___bound_ptr_indir16; بشکن;
    پیشفرض:
        /* may happen with struct member access */
        بازگشت;
    }
    sym = external_helper_sym(func);
    اگر (!sym->c)
        put_extern_sym(sym, پوچ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
ایستا تهی gbound(تهی)
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
ST_FUNC تهی gbound_args(صحیح nb_args)
{
    صحیح i, v;
    SValue *sv;

    برای (i = 1; i <= nb_args; ++i)
        اگر (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    اگر (sv->r & VT_SYM) {
        v = sv->sym->v;
        اگر (v == TOK_setjmp
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
        اگر (v == TOK_alloca)
            func_bound_add_epilog = 1;
#اگر TARGETOS_NetBSD
        اگر (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
ایستا تهی add_local_bounds(Sym *s, Sym *e)
{
    برای (; s != e; s = s->prev) {
        اگر (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ادامه;
        /* Add arrays/structs/unions because we always take address */
        اگر ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            صحیح align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * اندازه(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
ایستا تهی tcc_debug_end_scope(Sym *b, صحیح bounds)
{
#ifdef CONFIG_TCC_BCHECK
    اگر (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_پشته, b);
#endif
    tcc_add_debug_info (tcc_state, local_پشته, b);
}

/* increment an lvalue pointer */
ایستا تهی incr_offset(صحیح offset)
{
    صحیح t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

ایستا تهی incr_bf_adr(صحیح o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
ایستا تهی load_packed_bf(CType *type, صحیح bit_pos, صحیح bit_size)
{
    صحیح n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    انجامبده {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        اگر (n > bit_size)
            n = bit_size;
        اگر (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        اگر (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        اگر (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } وقتی (bit_size);
    vswap(), vpop();
    اگر (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
ایستا تهی store_packed_bf(صحیح bit_pos, صحیح bit_size)
{
    صحیح bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    انجامبده {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        اگر (bits)
            vpushi(bits), gen_op(TOK_SHR);
        اگر (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        اگر (n > bit_size)
            n = bit_size;
        اگر (n < 8) {
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
    } وقتی (bit_size);
    vpop(), vpop();
}

ایستا صحیح adjust_bf(SValue *sv, صحیح bit_pos, صحیح bit_size)
{
    صحیح t;
    اگر (0 == sv->type.ref)
        بازگشت 0;
    t = sv->type.ref->auxtype;
    اگر (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    بازگشت t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC صحیح gv(صحیح rc)
{
    صحیح r, r2, r_ok, r2_ok, rc2, bt;
    صحیح bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    اگر (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = پوچ;
        type.t = vtop->type.t & VT_UNSIGNED;
        اگر ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        اگر ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        وگرنه
            type.t |= VT_INT;

        اگر (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } وگرنه {
            صحیح bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } وگرنه {
        اگر (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            اگر (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        اگر (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            بازگشت vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        اگر (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        اگر (!r_ok || !r2_ok) {

            اگر (!r_ok) {
                اگر (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                وگرنه
                    r = get_reg(rc);
            }

            اگر (rc2) {
                صحیح load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                صحیح original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } وگرنه اگر (vtop->r & VT_LVAL) {
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
                } وگرنه {
                    /* move registers */
                    اگر (!r_ok)
                        load(r, vtop);
                    اگر (r2_ok && vtop->r2 < VT_CONST)
                        برو done;
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
            } وگرنه {
                اگر (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        اگر (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    بازگشت r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC تهی gv2(صحیح rc1, صحیح rc2)
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
    } وگرنه {
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

#اگر PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC تهی lexpand(تهی)
{
    صحیح u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    اگر (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } وگرنه اگر (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } وگرنه {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#اگر PTR_SIZE == 4
/* build a long long from two ints */
ایستا تهی lbuild(صحیح t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
ایستا تهی gv_dup(تهی)
{
    صحیح t, rc, r;

    t = vtop->type.t;
#اگر PTR_SIZE == 4
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
        بازگشت;
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

#اگر PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
ایستا تهی gen_opl(صحیح op)
{
    صحیح t, a, b, op1, c, i;
    صحیح func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    انتخاب(op) {
    حالت '/':
    حالت TOK_PDIV:
        func = TOK___divdi3;
        برو gen_func;
    حالت TOK_UDIV:
        func = TOK___udivdi3;
        برو gen_func;
    حالت '%':
        func = TOK___moddi3;
        برو gen_mod_func;
    حالت TOK_UMOD:
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
        بشکن;
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
            برای(i=0;i<4;i++)
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
        } وگرنه اگر (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            اگر (op == '+')
                op1 = TOK_ADDC1;
            وگرنه
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } وگرنه {
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
        بشکن;
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
                } وگرنه {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } وگرنه {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                اگر (op == TOK_SHL)
                    gen_op(TOK_SHR);
                وگرنه
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                اگر (op == TOK_SHL)
                    gen_op(TOK_SHL);
                وگرنه
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            اگر (op != TOK_SHL)
                vswap();
            lbuild(t);
        } وگرنه {
            /* XXX: should provide a faster fallback on x86 ? */
            انتخاب(op) {
            حالت TOK_SAR:
                func = TOK___ashrdi3;
                برو gen_func;
            حالت TOK_SHR:
                func = TOK___lshrdi3;
                برو gen_func;
            حالت TOK_SHL:
                func = TOK___ashldi3;
                برو gen_func;
            }
        }
        بشکن;
    پیشفرض:
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
        وگرنه اگر (op1 == TOK_GT)
            op1 = TOK_GE;
        وگرنه اگر (op1 == TOK_ULT)
            op1 = TOK_ULE;
        وگرنه اگر (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        اگر (op == TOK_NE) {
            b = gvtst(0, 0);
        } وگرنه {
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
        وگرنه اگر (op1 == TOK_LE)
            op1 = TOK_ULE;
        وگرنه اگر (op1 == TOK_GT)
            op1 = TOK_UGT;
        وگرنه اگر (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#اگر 0//def TCC_TARGET_I386
        اگر (op == TOK_NE) { gsym(b); بشکن; }
        اگر (op == TOK_EQ) { gsym(a); بشکن; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        بشکن;
    }
}
#endif

/* normalize values */
ایستا uint64_t value64(uint64_t l1, صحیح t)
{
    اگر ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        بازگشت l1;
    وگرنه اگر (t & VT_UNSIGNED)
        بازگشت (uint32_t)l1;
    وگرنه
        بازگشت (uint32_t)l1 | -(l1 & 0x80000000);
}

ایستا uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    بازگشت (a ^ b) >> 63 ? -x : x;
}

ایستا صحیح gen_opic_lt(uint64_t a, uint64_t b)
{
    بازگشت (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
ایستا تهی gen_opic(صحیح op)
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
        حالت '+': l1 += l2; بشکن;
        حالت '-': l1 -= l2; بشکن;
        حالت '&': l1 &= l2; بشکن;
        حالت '^': l1 ^= l2; بشکن;
        حالت '|': l1 |= l2; بشکن;
        حالت '*': l1 *= l2; بشکن;

        حالت TOK_PDIV:
        حالت '/':
        حالت '%':
        حالت TOK_UDIV:
        حالت TOK_UMOD:
            /* if division by zero, generate explicit division */
            اگر (l2 == 0) {
                اگر (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                برو general_case;
            }
            انتخاب(op) {
            پیشفرض: l1 = gen_opic_sdiv(l1, l2); بشکن;
            حالت '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); بشکن;
            حالت TOK_UDIV: l1 = l1 / l2; بشکن;
            حالت TOK_UMOD: l1 = l1 % l2; بشکن;
            }
            بشکن;
        حالت TOK_SHL: l1 <<= (l2 & shm); بشکن;
        حالت TOK_SHR: l1 >>= (l2 & shm); بشکن;
        حالت TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            بشکن;
            /* tests */
        حالت TOK_ULT: l1 = l1 < l2; بشکن;
        حالت TOK_UGE: l1 = l1 >= l2; بشکن;
        حالت TOK_EQ: l1 = l1 == l2; بشکن;
        حالت TOK_NE: l1 = l1 != l2; بشکن;
        حالت TOK_ULE: l1 = l1 <= l2; بشکن;
        حالت TOK_UGT: l1 = l1 > l2; بشکن;
        حالت TOK_LT: l1 = gen_opic_lt(l1, l2); بشکن;
        حالت TOK_GE: l1 = !gen_opic_lt(l1, l2); بشکن;
        حالت TOK_LE: l1 = !gen_opic_lt(l2, l1); بشکن;
        حالت TOK_GT: l1 = gen_opic_lt(l2, l1); بشکن;
            /* logical */
        حالت TOK_LAND: l1 = l1 && l2; بشکن;
        حالت TOK_LOR: l1 = l1 || l2; بشکن;
        پیشفرض:
            برو general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } وگرنه {
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
        } وگرنه اگر (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            اگر (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } وگرنه اگر (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } وگرنه اگر (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            اگر (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                صحیح n = -1;
                اگر (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    برو general_case;
                }
                وقتی (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                اگر (op == '*')
                    op = TOK_SHL;
                وگرنه اگر (op == TOK_PDIV)
                    op = TOK_SAR;
                وگرنه
                    op = TOK_SHR;
            }
            برو general_case;
        } وگرنه اگر (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            اگر (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    اگر ((صحیح)l2 != l2)
	        برو general_case;
            vtop--;
            vtop->c.i = l2;
        } وگرنه {
        general_case:
                /* call low level op generator */
                اگر (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                وگرنه
                    gen_opi(op);
        }
        اگر (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#اگر defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#وگرنهاگر defined TCC_TARGET_ARM
تهی gen_negf(صحیح op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#وگرنه
/* XXX: implement in gen_opf() for other backends too */
تهی gen_negf(صحیح op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    صحیح align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#اگر defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    اگر (bt == VT_LDOUBLE)
        size = 10;
#endif
    اگر (nocode_wanted) /* save_reg() wont work */
        برو gv2;
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
ایستا تهی gen_opif(صحیح op)
{
    صحیح c1, c2, i, bt;
    SValue *v1, *v2;
#اگر defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    فرار
#endif
    long دوگانه f1, f2;

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
        } وگرنه اگر (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } وگرنه {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        اگر (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            برو general_case;
        انتخاب(op) {
        حالت '+': f1 += f2; بشکن;
        حالت '-': f1 -= f2; بشکن;
        حالت '*': f1 *= f2; بشکن;
        حالت '/': 
            اگر (f2 == 0.0) {
                اجتماع { اعشاری f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                اگر (!CONST_WANTED)
                    برو general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                اگر (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                وگرنه
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                بشکن;
            }
            f1 /= f2;
            بشکن;
        حالت TOK_NEG:
            f1 = -f1;
            برو unary_result;
        حالت TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            بازگشت;
        حالت TOK_NE:
            i = f1 != f2;
	    برو make_int;
        حالت TOK_LT:
            i = f1 < f2;
	    برو make_int;
        حالت TOK_GE:
            i = f1 >= f2;
	    برو make_int;
        حالت TOK_LE:
            i = f1 <= f2;
	    برو make_int;
        حالت TOK_GT:
            i = f1 > f2;
	    برو make_int;
        پیشفرض:
            برو general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        اگر (bt == VT_FLOAT) {
            v1->c.f = f1;
        } وگرنه اگر (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } وگرنه {
            v1->c.ld = f1;
        }
    } وگرنه {
    general_case:
        اگر (op == TOK_NEG) {
            gen_negf(op);
        } وگرنه {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
ایستا تهی type_to_str(نویسه *buf, صحیح buf_size,
                 CType *type, ثابت نویسه *varstr)
{
    صحیح bt, v, t;
    Sym *s, *sa;
    نویسه buf1[256];
    ثابت نویسه *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    اگر (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    اگر (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    اگر (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    اگر (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    اگر (bt != VT_PTR) {
        اگر (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        اگر (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        اگر (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    اگر (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    انتخاب(bt) {
    حالت VT_VOID:
        tstr = "void";
        برو add_tstr;
    حالت VT_BOOL:
        tstr = "_Bool";
        برو add_tstr;
    حالت VT_BYTE:
        tstr = "char";
        برو add_tstr;
    حالت VT_SHORT:
        tstr = "short";
        برو add_tstr;
    حالت VT_INT:
        tstr = "int";
        برو maybe_long;
    حالت VT_LLONG:
        tstr = "long long";
    maybe_long:
        اگر (t & VT_LONG)
            tstr = "long";
        اگر (!IS_ENUM(t))
            برو add_tstr;
        tstr = "enum ";
        برو tstruct;
    حالت VT_FLOAT:
        tstr = "float";
        برو add_tstr;
    حالت VT_DOUBLE:
        tstr = "double";
        اگر (!(t & VT_LONG))
            برو add_tstr;
    حالت VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        بشکن;
    حالت VT_STRUCT:
        tstr = "struct ";
        اگر (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        اگر (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        وگرنه
            pstrcat(buf, buf_size, get_tok_str(v, پوچ));
        بشکن;
    حالت VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        اگر (varstr && '*' == *varstr) {
            pstrcat(buf1, اندازه(buf1), "(");
            pstrcat(buf1, اندازه(buf1), varstr);
            pstrcat(buf1, اندازه(buf1), ")");
        }
        pstrcat(buf1, اندازه(buf1), "(");
        sa = s->next;
        وقتی (sa != پوچ) {
            نویسه buf2[256];
            type_to_str(buf2, اندازه(buf2), &sa->type, پوچ);
            pstrcat(buf1, اندازه(buf1), buf2);
            sa = sa->next;
            اگر (sa)
                pstrcat(buf1, اندازه(buf1), ", ");
        }
        اگر (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, اندازه(buf1), ", ...");
        pstrcat(buf1, اندازه(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        برو no_var;
    حالت VT_PTR:
        s = type->ref;
        اگر (t & (VT_ARRAY|VT_VLA)) {
            اگر (varstr && '*' == *varstr)
                snprintf(buf1, اندازه(buf1), "(%s)[%d]", varstr, s->c);
            وگرنه
                snprintf(buf1, اندازه(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            برو no_var;
        }
        pstrcpy(buf1, اندازه(buf1), "*");
        اگر (t & VT_RESTRICT)
            pstrcat(buf1, اندازه(buf1), "restrict ");
        اگر (t & VT_CONSTANT)
            pstrcat(buf1, اندازه(buf1), "const ");
        اگر (t & VT_VOLATILE)
            pstrcat(buf1, اندازه(buf1), "volatile ");
        اگر (varstr)
            pstrcat(buf1, اندازه(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        برو no_var;
    }
    اگر (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

ایستا تهی type_incompatibility_error(CType* st, CType* dt, ثابت نویسه* fmt)
{
    نویسه buf1[256], buf2[256];
    type_to_str(buf1, اندازه(buf1), st, پوچ);
    type_to_str(buf2, اندازه(buf2), dt, پوچ);
    tcc_error(fmt, buf1, buf2);
}

ایستا تهی type_incompatibility_warning(CType* st, CType* dt, ثابت نویسه* fmt)
{
    نویسه buf1[256], buf2[256];
    type_to_str(buf1, اندازه(buf1), st, پوچ);
    type_to_str(buf2, اندازه(buf2), dt, پوچ);
    tcc_warning(fmt, buf1, buf2);
}

ایستا صحیح pointed_size(CType *type)
{
    صحیح align;
    بازگشت type_size(pointed_type(type), &align);
}

ایستا درونخطی صحیح is_null_pointer(SValue *p)
{
    اگر ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        بازگشت 0;
    بازگشت ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
ایستا صحیح is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    اگر (s1->f.func_call != s2->f.func_call)
        بازگشت 0;
    اگر (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        بازگشت 0;
    برای (;;) {
        اگر (!is_compatible_unqualified_types(&s1->type, &s2->type))
            بازگشت 0;
        اگر (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            بازگشت 1;
        s1 = s1->next;
        s2 = s2->next;
        اگر (!s1)
            بازگشت !s2;
        اگر (!s2)
            بازگشت 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
ایستا صحیح compare_types(CType *type1, CType *type2, صحیح unqualified)
{
    صحیح bt1, t1, t2;

    اگر (IS_ENUM(type1->t)) {
        اگر (IS_ENUM(type2->t))
            بازگشت type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } وگرنه اگر (IS_ENUM(type2->t))
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
        بازگشت 0;

    اگر ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            بازگشت 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    اگر (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        اگر (unqualified && (t1 & VT_ARRAY))
            بازگشت compare_types(type1, type2, 1);
        بازگشت is_compatible_types(type1, type2);
    } وگرنه اگر (bt1 == VT_STRUCT) {
        بازگشت (type1->ref == type2->ref);
    } وگرنه اگر (bt1 == VT_FUNC) {
        بازگشت is_compatible_func(type1, type2);
    } وگرنه {
        بازگشت 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
ایستا صحیح combine_types(CType *dest, SValue *op1, SValue *op2, صحیح op)
{
    CType *type1, *type2, type;
    صحیح t1, t2, bt1, bt2;
    صحیح ret = 1;

    /* for shifts, 'combine' only left operand */
    اگر (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = پوچ;

    اگر (bt1 == VT_VOID || bt2 == VT_VOID) {
        اگر (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } وگرنه اگر (bt1 == VT_PTR || bt2 == VT_PTR) {
        اگر (op == '+') {
          اگر (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        وگرنه اگر (is_null_pointer (op2)) type = *type1;
        وگرنه اگر (is_null_pointer (op1)) type = *type2;
        وگرنه اگر (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            اگر ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            وگرنه اگر (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } وگرنه {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            صحیح pbt1 = pt1->t & VT_BTYPE;
            صحیح pbt2 = pt2->t & VT_BTYPE;
            صحیح newquals, copied = 0;
            اگر (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                اگر (op != '?' && op != CMP_OP)
                  ret = 0;
                وگرنه
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
                    type.ref = sym_افزودن(SYM_FIELD, &type.ref->type,
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
                      type.ref = sym_افزودن(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_افزودن(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        اگر (op == CMP_OP)
          type.t = VT_SIZE_T;
    } وگرنه اگر (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        اگر (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } وگرنه اگر (is_float(bt1) || is_float(bt2)) {
        اگر (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } وگرنه اگر (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } وگرنه {
            type.t = VT_FLOAT;
        }
    } وگرنه اگر (bt1 == VT_LLONG || bt2 == VT_LLONG) {
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
    } وگرنه {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        اگر (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    اگر (dest)
      *dest = type;
    بازگشت ret;
}

/* generic gen_op: handles types problems */
ST_FUNC تهی gen_op(صحیح op)
{
    صحیح t1, t2, bt1, bt2, t;
    CType type1, combtype;
    صحیح op_class = op;

    اگر (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    وگرنه اگر (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    اگر (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	اگر (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	اگر (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	برو redo;
    } وگرنه اگر (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } وگرنه اگر (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        صحیح align;
        اگر (op_class == CMP_OP)
            برو std_op;
        /* if both pointers, then it must be the '-' op */
        اگر (bt1 == VT_PTR && bt2 == VT_PTR) {
            اگر (op != '-')
                برو op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } وگرنه {
            /* exactly one pointer : must be '+' or '-'. */
            اگر (op != '-' && op != '+')
                برو op_err;
            /* Put pointer as first operand */
            اگر (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#اگر PTR_SIZE == 4
            اگر (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            اگر (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                اگر (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } وگرنه
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } وگرنه {
        /* floats can only be used for a few operations */
        اگر (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            برو op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        اگر (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        اگر (t & VT_UNSIGNED) {
            اگر (op == TOK_SAR)
                op = TOK_SHR;
            وگرنه اگر (op == '/')
                op = TOK_UDIV;
            وگرنه اگر (op == '%')
                op = TOK_UMOD;
            وگرنه اگر (op == TOK_LT)
                op = TOK_ULT;
            وگرنه اگر (op == TOK_GT)
                op = TOK_UGT;
            وگرنه اگر (op == TOK_LE)
                op = TOK_ULE;
            وگرنه اگر (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        اگر (is_float(t))
            gen_opif(op);
        وگرنه
            gen_opic(op);
        اگر (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } وگرنه {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    اگر (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#اگر defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#وگرنه
/* generic itof for unsigned long long case */
ایستا تهی gen_cvt_itof1(صحیح t)
{
    اگر ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        اگر (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#اگر LDOUBLE_SIZE != 8
        وگرنه اگر (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        وگرنه
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } وگرنه {
        gen_cvt_itof(t);
    }
}
#endif

#اگر defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#وگرنه
/* generic ftoi for unsigned long long case */
ایستا تهی gen_cvt_ftoi1(صحیح t)
{
    صحیح st;
    اگر (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        اگر (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#اگر LDOUBLE_SIZE != 8
        وگرنه اگر (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        وگرنه
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } وگرنه {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
ایستا تهی force_charshort_cast(تهی)
{
    صحیح sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    صحیح dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

ایستا تهی gen_cast_s(صحیح t)
{
    CType type;
    type.t = t;
    type.ref = پوچ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
ایستا تهی gen_cast(CType *type)
{
    صحیح sbt, dbt, sf, df, c;
    صحیح dbt_bt, sbt_bt, ds, ss, bits, trunc;

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
            برو done;
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
            وگرنه اگر (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            اگر (df) {
                اگر (sbt_bt == VT_LLONG) {
                    اگر ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    وگرنه
                        vtop->c.ld = -(long دوگانه)-vtop->c.i;
                } وگرنه اگر(!sf) {
                    اگر ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    وگرنه
                        vtop->c.ld = -(long دوگانه)-(uint32_t)vtop->c.i;
                }

                اگر (dbt == VT_FLOAT)
                    vtop->c.f = (اعشاری)vtop->c.ld;
                وگرنه اگر (dbt == VT_DOUBLE)
                    vtop->c.d = (دوگانه)vtop->c.ld;
            } وگرنه اگر (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } وگرنه {
                اگر(sf) {
                    اگر (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    وگرنه
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                وگرنه اگر (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                وگرنه اگر (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                وگرنه
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                اگر (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                وگرنه اگر (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                وگرنه {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    اگر (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            برو done;

        } وگرنه اگر (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            برو done;
        }

        /* cannot generate code for global or static initializers */
        اگر (nocode_wanted & DATA_ONLY_WANTED) {
            اگر (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            برو done;
        }

        /* non constant case: generate code */
        اگر (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            برو done;
        }

        اگر (sf || df) {
            اگر (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } وگرنه اگر (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } وگرنه {
                /* convert fp to int */
                sbt = dbt;
                اگر (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                برو again; /* may need char/short cast */
            }
            برو done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        اگر (ds == 0 || ss == 0)
            برو error;

        /* same size and no sign conversion needed */
        اگر (ds == ss && ds >= 4)
            برو done;
        اگر (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            اگر (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        اگر (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            اگر (ds <= ss)
                برو done;
            /* ss <= 4 here */
            اگر (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                برو done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#اگر PTR_SIZE == 4
        اگر (ds == 8) {
            /* generate high word */
            اگر (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } وگرنه {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } وگرنه اگر (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#وگرنهاگر PTR_SIZE == 8
        اگر (ds == 8) {
            /* need to convert from 32bit to 64bit */
            اگر (sbt & VT_UNSIGNED) {
#اگر defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#وگرنه
                برو done;
#endif
            } وگرنه {
                gen_cvt_sxtw();
                برو done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } وگرنه اگر (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#اگر !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } وگرنه {
            ss = 4;
        }
#endif

        اگر (ds >= ss)
            برو done;
#اگر defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    اگر (ss == 4) {
        gen_cvt_csti(dbt);
        برو done;
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
ST_FUNC صحیح type_size(CType *type, صحیح *a)
{
    Sym *s;
    صحیح bt;

    bt = type->t & VT_BTYPE;
    اگر (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        بازگشت s->c;
    } وگرنه اگر (bt == VT_PTR) {
        اگر (type->t & VT_ARRAY) {
            صحیح ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            اگر (s->c < 0)
                بازگشت s->c;
            بازگشت ts * s->c;
        } وگرنه {
            *a = PTR_SIZE;
            بازگشت PTR_SIZE;
        }
    } وگرنه اگر (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        بازگشت -1; /* incomplete enum */
    } وگرنه اگر (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        بازگشت LDOUBLE_SIZE;
    } وگرنه اگر (bt == VT_DOUBLE || bt == VT_LLONG) {
#اگر (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#وگرنه
        *a = 8;
#endif
        بازگشت 8;
    } وگرنه اگر (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        بازگشت 4;
    } وگرنه اگر (bt == VT_SHORT) {
        *a = 2;
        بازگشت 2;
    } وگرنه اگر (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        بازگشت 16;
    } وگرنه {
        /* char, void, function, _Bool */
        *a = 1;
        بازگشت 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
ایستا تهی vpush_type_size(CType *type, صحیح *a)
{
    اگر (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } وگرنه {
        صحیح size = type_size(type, a);
        اگر (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
ایستا درونخطی CType *pointed_type(CType *type)
{
    بازگشت &type->ref->type;
}

ایستا تهی check_restrict_type(CType *type)
{
    وقتی ((type->t & VT_BTYPE) == VT_PTR) {
        اگر ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    اگر (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
ایستا صحیح type_qualifiers(CType *type)
{
    وقتی (type->t & VT_ARRAY)
        type = pointed_type(type);
    بازگشت type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC تهی mk_pointer(CType *type)
{
    Sym *s;
    s = sym_افزودن(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
ایستا صحیح is_compatible_types(CType *type1, CType *type2)
{
    بازگشت compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
ایستا صحیح is_compatible_unqualified_types(CType *type1, CType *type2)
{
    بازگشت compare_types(type1,type2,1);
}

ایستا تهی cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
ایستا تهی verify_assign_cast(CType *dt)
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
        بشکن;
    حالت VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        اگر (is_null_pointer(vtop))
            بشکن;
        /* accept implicit pointer to integer cast with warning */
        اگر (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            بشکن;
        }
        type1 = pointed_type(dt);
        اگر (sbt == VT_PTR)
            type2 = pointed_type(st);
        وگرنه اگر (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        وگرنه
            برو error;
        اگر (is_compatible_types(type1, type2))
            بشکن;
        برای (qualwarn = lvl = 0;; ++lvl) {
            اگر ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            اگر (dbt != VT_PTR || sbt != VT_PTR)
                بشکن;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        اگر (!is_compatible_unqualified_types(type1, type2)) {
            اگر ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } وگرنه اگر (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } وگرنه {
                tcc_warning("assignment from incompatible pointer type");
                بشکن;
            }
        }
        اگر (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        بشکن;
    حالت VT_BYTE:
    حالت VT_SHORT:
    حالت VT_INT:
    حالت VT_LLONG:
        اگر (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } وگرنه اگر (sbt == VT_STRUCT) {
            برو case_VT_STRUCT;
        }
        /* XXX: more tests */
        بشکن;
    حالت VT_STRUCT:
    case_VT_STRUCT:
        اگر (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        بشکن;
    }
}

ایستا تهی gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC تهی vstore(تهی)
{
    صحیح sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    اگر (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        اگر (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        اگر (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } وگرنه
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            اگر(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            وگرنه اگر(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            وگرنه
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } وگرنه اگر (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        اگر (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        اگر (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        اگر (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } وگرنه {
            unsigned long long mask = (1ULL << bit_size) - 1;
            اگر (dbt != VT_BOOL) {
                /* mask source */
                اگر (dbt == VT_LLONG)
                    vpushll(mask);
                وگرنه
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
            اگر (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            وگرنه
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } وگرنه اگر (dbt == VT_VOID) {
        --vtop;
    } وگرنه {
            /* optimize char/short casts */
            delayed_cast = 0;
            اگر ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                اگر ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } وگرنه {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            اگر (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
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
		sv.sym = پوچ;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            اگر (USING_TWO_واژگان(dbt)) {
                صحیح load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } وگرنه {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC تهی inc(صحیح post, صحیح c)
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

ST_FUNC CString* parse_mult_str (ثابت نویسه *پیام)
{
    /* read the string */
    اگر (tok != TOK_STR)
        expect(پیام);
    cstr_reset(&initstr);
    وقتی (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    بازگشت &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC صحیح exact_log2p1(صحیح i)
{
  صحیح ret;
  اگر (!i)
    بازگشت 0;
  برای (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  اگر (i >= 1 << 4)
    ret += 4, i >>= 4;
  اگر (i >= 1 << 2)
    ret += 2, i >>= 2;
  اگر (i >= 1 << 1)
    ret++;
  بازگشت ret;
}

/* Parse __attribute__((...)) GNUC extension. */
ایستا تهی parse_attribute(AttributeDef *ad)
{
    صحیح t, n;
    نویسه *astr;
    AttributeDef ad_tmp;
    
redo:
    اگر (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        بازگشت;
    اگر (پوچ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    وقتی (tok != ')') {
        اگر (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        انتخاب(t) {
	حالت TOK_CLEANUP1:
	حالت TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    اگر (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } وگرنه اگر ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    بشکن;
	}
        حالت TOK_CONSTRUCTOR1:
        حالت TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            بشکن;
        حالت TOK_DESTRUCTOR1:
        حالت TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            بشکن;
        حالت TOK_ALWAYS_INLINE1:
        حالت TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            بشکن;
        حالت TOK_SECTION1:
        حالت TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            بشکن;
        حالت TOK_ALIAS1:
        حالت TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            بشکن;
	حالت TOK_VISIBILITY1:
	حالت TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    اگر (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    وگرنه اگر (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    وگرنه اگر (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    وگرنه اگر (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    وگرنه
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            بشکن;
        حالت TOK_ALIGNED1:
        حالت TOK_ALIGNED2:
            اگر (tok == '(') {
                next();
                n = عبارت_const();
                اگر (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } وگرنه {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    اگر (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            بشکن;
        حالت TOK_PACKED1:
        حالت TOK_PACKED2:
            ad->a.packed = 1;
            بشکن;
        حالت TOK_WEAK1:
        حالت TOK_WEAK2:
            ad->a.weak = 1;
            بشکن;
        حالت TOK_NODEBUG1:
        حالت TOK_NODEBUG2:
            ad->a.nodebug = 1;
            بشکن;
        حالت TOK_USED1:
        حالت TOK_USED2:
        حالت TOK_UNUSED1:
        حالت TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            بشکن;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
        حالت TOK_PURE1:
        حالت TOK_PURE2:
	    /* ignored */
            بشکن;
        حالت TOK_NOINLINE:
	    /* ignored */
	    بشکن;
        حالت TOK_FORMAT1:
        حالت TOK_FORMAT2:
	    /* ignored */
            برو skip_param;
        حالت TOK_NORETURN1:
        حالت TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            بشکن;
        حالت TOK_CDECL1:
        حالت TOK_CDECL2:
        حالت TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            بشکن;
        حالت TOK_STDCALL1:
        حالت TOK_STDCALL2:
        حالت TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            بشکن;
#ifdef TCC_TARGET_I386
        حالت TOK_REGPARM1:
        حالت TOK_REGPARM2:
            skip('(');
            n = عبارت_const();
            اگر (n > 3) 
                n = 3;
            وگرنه اگر (n < 0)
                n = 0;
            اگر (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            بشکن;
        حالت TOK_FASTCALL1:
        حالت TOK_FASTCALL2:
        حالت TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            بشکن;
        حالت TOK_THISCALL1:
        حالت TOK_THISCALL2:
        حالت TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            بشکن;
#endif
        حالت TOK_MODE:
            skip('(');
            انتخاب(tok) {
                حالت TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    بشکن;
                حالت TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    بشکن;
                حالت TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    بشکن;
                حالت TOK_MODE_SI:
                حالت TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    بشکن;
                پیشفرض:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, پوچ));
                    بشکن;
            }
            next();
            skip(')');
            بشکن;
        حالت TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            بشکن;
        حالت TOK_NODECORATE:
            ad->a.nodecorate = 1;
            بشکن;
        حالت TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            بشکن;
        پیشفرض:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, پوچ));
            /* skip parameters */
skip_param:
            اگر (tok == '(') {
                صحیح parenthesis = 0;
                انجامبده {
                    اگر (tok == '(') 
                        parenthesis++;
                    وگرنه اگر (tok == ')') 
                        parenthesis--;
                    next();
                } وقتی (parenthesis && tok != -1);
            }
            بشکن;
        }
        اگر (tok != ',')
            بشکن;
        next();
    }
    skip(')');
    skip(')');
    برو redo;
}

ایستا Sym * find_field (CType *type, صحیح v, صحیح *cumofs)
{
    Sym *s = type->ref;
    صحیح v1 = v | SYM_FIELD;
    اگر (!(v & SYM_FIELD)) { /* top-level call */
        اگر ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        اگر (v < TOK_UIDENT)
            expect("field name");
        اگر (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    وقتی ((s = s->next) != پوچ) {
        اگر (s->v == v1) {
            *cumofs = s->c;
            بازگشت s;
        }
        اگر ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            اگر (ret) {
                *cumofs += s->c;
                بازگشت ret;
            }
        }
    }
    اگر (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, پوچ));
    بازگشت s;
}

ایستا تهی check_fields (CType *type, صحیح check)
{
    Sym *s = type->ref;

    وقتی ((s = s->next) != پوچ) {
        صحیح v = s->v & ~SYM_FIELD;
        اگر (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            اگر (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, پوچ));
            ts->tok ^= SYM_FIELD;
        } وگرنه اگر ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

ایستا تهی struct_layout(CType *type, AttributeDef *ad)
{
    صحیح size, align, maxalign, offset, c, bit_pos, bit_size;
    صحیح packed, a, bt, prevbt, prev_bit_size;
    صحیح pcc = !tcc_state->ms_bitfields;
    صحیح pragma_pack = *tcc_state->pack_پشته_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    برای (f = type->ref->next; f; f = f->next) {
        اگر (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        وگرنه
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        اگر (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } وگرنه {
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
	    اگر (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    اگر (size > c)
	        c = size;

	} وگرنه اگر (bit_size < 0) {
            اگر (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    اگر (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} وگرنه {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            اگر (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                اگر (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } وگرنه اگر (f->a.aligned) {
                    برو new_field;
                } وگرنه اگر (!packed) {
                    صحیح a8 = align * 8;
	            صحیح ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    اگر (ofs > size / align)
                        برو new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                اگر (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                وقتی (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		اگر (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } وگرنه {
		bt = f->type.t & VT_BTYPE;
		اگر ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    اگر (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		اگر (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	اگر (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, پوچ), offset, size, align);
	اگر (f->type.t & VT_BITFIELD) {
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

    اگر (pcc)
        c += (bit_pos + 7) >> 3;

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

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    برای (f = type->ref->next; f; f = f->next) {
        صحیح s, px, cx, c0;
        CType t;

        اگر (0 == (f->type.t & VT_BITFIELD))
            ادامه;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        اگر (bit_size == 0)
            ادامه;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        اگر (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            ادامه;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        برای (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            اگر (c0 == cx)
                بشکن;
            s = (px + bit_size + 7) >> 3;
            اگر (s > 4) {
                t.t = VT_LLONG;
            } وگرنه اگر (s > 2) {
                t.t = VT_INT;
            } وگرنه اگر (s > 1) {
                t.t = VT_SHORT;
            } وگرنه {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        اگر (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            اگر (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, پوچ),
                cx, s, align, px, bit_size);
#endif
        } وگرنه {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, پوچ));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
ایستا صحیح in_range(long long n, صحیح t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    اگر (t & VT_UNSIGNED)
        بازگشت n <= (m << 1) + 1;
    بازگشت n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
ایستا تهی struct_decl(CType *type, صحیح u)
{
    صحیح v, c, size, align, flexible;
    صحیح bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, اندازه ad);
    next();
    parse_attribute(&ad);

    v = 0;
    اگر (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    اگر (u == VT_ENUM) {
        ut = VT_INT;
        اگر (tok == ':') { /* C2x enum : <type> ... */
            next();
            اگر (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    اگر (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        اگر (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            اگر (u == s->type.t)
                برو do_decl;
            اگر (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                برو do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, پوچ));
        }
    } وگرنه {
        اگر (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = پوچ;
    /* we put an undefined size for struct/union */
    s = sym_افزودن(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    اگر (tok == '{') {
        next();
        اگر (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        اگر (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            اگر (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            برای(;;) {
                v = tok;
                اگر (v < TOK_UIDENT)
                    expect("identifier");
                next();
                اگر (tok == '=') {
                    next();
		    ll = عبارت_const64();
                }
                اگر (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, پوچ));
                ss = sym_افزودن(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                اگر (ll < nl)
                    nl = ll;
                اگر (ll > pl)
                    pl = ll;
                اگر (tok != ',')
                    بشکن;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                اگر (tok == '}')
                    بشکن;
            }
            skip('}');

            اگر (bt) {
                t.t = bt;
                s->c = 2;
                برو enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            اگر (nl >= 0) {
                اگر (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } وگرنه اگر (pl != (صحیح)pl || nl != (صحیح)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            برای (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                اگر (ll == (صحیح)ll) /* default is int if it fits */
                    ادامه;
                اگر (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    اگر (ll == (unsigned)ll)
                        ادامه;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } وگرنه {
            c = 0;
            flexible = 0;
            وقتی (tok != '}') {
                اگر (!parse_btype(&btype, &ad1, 0)) {
                    اگر (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ادامه;
                    }
		    skip(';');
		    ادامه;
		}
                وقتی (1) {
		    اگر (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, پوچ));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    اگر (tok != ':') {
			اگر (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        اگر (v == 0) {
                    	    اگر ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    وگرنه {
				صحیح v = btype.ref->v;
				اگر ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    اگر (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        اگر (type_size(&type1, &align) < 0) {
			    اگر ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    وگرنه
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, پوچ));
                        }
                        اگر ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, پوچ));
                    }
                    اگر (tok == ':') {
                        next();
                        bit_size = عبارت_const();
                        /* XXX: handle v = 0 case for messages */
                        اگر (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, پوچ));
                        اگر (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, پوچ));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    اگر (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        اگر (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        اگر (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, پوچ));
                        } وگرنه اگر (bit_size == bsize
				    && !*tcc_state->pack_پشته_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } وگرنه اگر (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } وگرنه {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
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
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    اگر (v) {
                        ss = sym_افزودن(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    اگر (tok == ';' || tok == TOK_EOF)
                        بشکن;
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

ایستا تهی sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
ایستا تهی parse_btype_qualify(CType *type, صحیح qualifiers)
{
    وقتی (type->t & VT_ARRAY) {
        type->ref = sym_افزودن(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    اگر (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
ایستا صحیح parse_btype(CType *type, AttributeDef *ad, صحیح ignore_label)
{
    صحیح t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, اندازه(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = پوچ;

    وقتی(1) {
        انتخاب(tok) {
        حالت TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            ادامه;

            /* basic types */
        حالت TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            اگر (u == VT_SHORT || u == VT_LONG) {
                اگر (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } وگرنه {
                اگر (bt != -1 || (st != -1 && u != VT_INT))
                    برو tmbt;
                اگر ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    برو tmbt;
                bt = u;
            }
            اگر (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            بشکن;
        حالت TOK_VOID:
            u = VT_VOID;
            برو basic_type;
        حالت TOK_SHORT:
            u = VT_SHORT;
            برو basic_type;
        حالت TOK_INT:
            u = VT_INT;
            برو basic_type;
        حالت TOK_ALIGNAS:
            { صحیح n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, اندازه(AttributeDef));
              اگر (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  اگر (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  وگرنه
                    type_size(&type1, &n);
              } وگرنه {
                  n = عبارت_const();
                  اگر (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ادامه;
        حالت TOK_LONG:
            اگر ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } وگرنه اگر ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } وگرنه {
                u = VT_LONG;
                برو basic_type;
            }
            next();
            بشکن;
        حالت TOK_BOOL:
            u = VT_BOOL;
            برو basic_type;
        حالت TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        حالت TOK_FLOAT:
            u = VT_FLOAT;
            برو basic_type;
        حالت TOK_DOUBLE:
            اگر ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } وگرنه {
                u = VT_DOUBLE;
                برو basic_type;
            }
            next();
            بشکن;
        حالت TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            برو basic_type1;
        حالت TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            برو basic_type2;
        حالت TOK_UNION:
            struct_decl(&type1, VT_UNION);
            برو basic_type2;

            /* type modifiers */
        حالت TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            اگر (tok == '(') {
                parse_عبارت_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                اگر (type1.ref)
                    sym_to_attr(ad, type1.ref);
                برو basic_type2;
            }
            بشکن;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            بشکن;
        حالت TOK_VOLATILE1:
        حالت TOK_VOLATILE2:
        حالت TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            بشکن;
        حالت TOK_SIGNED1:
        حالت TOK_SIGNED2:
        حالت TOK_SIGNED3:
            اگر ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            بشکن;
        حالت TOK_RESTRICT1:
        حالت TOK_RESTRICT2:
        حالت TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            بشکن;
        حالت TOK_REGISTER:
        حالت TOK_AUTO:
            next();
            بشکن;
        حالت TOK_UNSIGNED:
            اگر ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            بشکن;

            /* storage */
        حالت TOK_EXTERN:
            g = VT_EXTERN;
            برو storage;
        حالت TOK_STATIC:
            g = VT_STATIC;
            برو storage;
        حالت TOK_TYPEDEF:
            g = VT_TYPEDEF;
            برو storage;
       storage:
            اگر (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            بشکن;
        حالت TOK_INLINE1:
        حالت TOK_INLINE2:
        حالت TOK_INLINE3:
            t |= VT_INLINE;
            next();
            بشکن;
        حالت TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            بشکن;
            /* GNUC attribute */
        حالت TOK_ATTRIBUTE1:
        حالت TOK_ATTRIBUTE2:
            parse_attribute(ad);
            اگر (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ادامه;
            /* GNUC typeof */
        حالت TOK_TYPEOF1:
        حالت TOK_TYPEOF2:
        حالت TOK_TYPEOF3:
            next();
            parse_عبارت_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            اگر (type1.ref) {
                sym_to_attr(ad, type1.ref);
                اگر (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            برو basic_type2;
        حالت TOK_THREAD_LOCAL:
        حالت TOK___thread:
            اگر (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            بشکن;
        پیشفرض:
            اگر (typespec_found)
                برو the_end;
            s = sym_find(tok);
            اگر (!s || !(s->type.t & VT_TYPEDEF))
                برو the_end;

            n = tok, next();
            اگر (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                برو the_end;
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
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            بشکن;
        }
        type_found = 1;
    }
the_end:
    اگر (tcc_state->char_is_unsigned) {
        اگر ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    اگر (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    اگر (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    بازگشت type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
ایستا درونخطی تهی convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    اگر ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
ایستا درونخطی تهی convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(تهی)
{
    skip('(');
    بازگشت parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
ایستا صحیح asm_label_instr(تهی)
{
    صحیح v;
    نویسه *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    بازگشت v;
}

ایستا صحیح post_type(CType *type, AttributeDef *ad, صحیح storage, صحیح td)
{
    صحیح n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = پوچ;
    صحیح *vla_array_str = پوچ;

    اگر (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	اگر (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  بازگشت 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_پشته ? &local_پشته : &global_پشته;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	اگر (tok == ')')
	  l = 0;
	وگرنه اگر (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	وگرنه اگر (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_برداشت(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    بازگشت 0;
	} وگرنه
	  l = FUNC_OLD;

        first = پوچ;
        plast = &first;
        arg_size = 0;
        اگر (l) {
            برای(;;) {
                /* read param name and compute offset */
                اگر (l != FUNC_OLD) {
                    اگر ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        بشکن;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    اگر ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    اگر (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } وگرنه {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = پوچ;
                    next();
                }
                اگر (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_افزودن(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                اگر (tok == ')')
                    بشکن;
                skip(',');
                اگر (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    بشکن;
                }
		اگر (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } وگرنه
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
        sym_برداشت(ps, sr, 1);
        --local_scope;

    } وگرنه اگر (tok == '[') {
	صحیح saved_nocode_wanted = nocode_wanted;
        صحیح array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        اگر (td & TYPE_PARAM) وقتی (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    انتخاب (tok) {
	    حالت TOK_CONST1: حالت TOK_CONST2: حالت TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		ادامه;
	    حالت TOK_VOLATILE1: حالت TOK_VOLATILE2: حالت TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		ادامه;
	    حالت TOK_RESTRICT1: حالت TOK_RESTRICT2: حالت TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		ادامه;
	    حالت TOK_STATIC:
	    حالت '*':
		next();
		ادامه;
	    پیشفرض:
		بشکن;
	    }
            اگر (tok != ']') {
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
		برو check;
            }
            بشکن;

	} وگرنه اگر (tok != ']') {
            اگر (!local_پشته || (storage & VT_STATIC))
                vpushi(عبارت_const());
            وگرنه {
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
            } وگرنه {
                اگر (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        اگر ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        اگر ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        اگر (t1 & VT_VLA) {
            اگر (n < 0) {
		اگر  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    وگرنه {
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
        اگر (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_افزودن(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        اگر (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    اگر ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    وگرنه
	        tok_str_free_str(vla_array_str);
	}
    }
    بازگشت 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
ایستا CType *type_decl(CType *type, AttributeDef *ad, صحیح *v, صحیح td)
{
    CType *post, *ret;
    صحیح qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    وقتی (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        انتخاب(tok) {
        حالت TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            برو redo;
        حالت TOK_CONST1:
        حالت TOK_CONST2:
        حالت TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            برو redo;
        حالت TOK_VOLATILE1:
        حالت TOK_VOLATILE2:
        حالت TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            برو redo;
        حالت TOK_RESTRICT1:
        حالت TOK_RESTRICT2:
        حالت TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            برو redo;
	/* XXX: clarify attribute handling */
	حالت TOK_ATTRIBUTE1:
	حالت TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    بشکن;
        }
        mk_pointer(type);
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
	} وگرنه
	  برو abstract;
    } وگرنه اگر (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } وگرنه {
  abstract:
	اگر (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    بازگشت ret;
}

/* indirection with full error checking and bound check */
ST_FUNC تهی indir(تهی)
{
    اگر ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        اگر ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            بازگشت;
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
#ifdef CONFIG_TCC_BCHECK
        اگر (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
ایستا تهی gfunc_param_typed(Sym *func, Sym *arg)
{
    صحیح func_type;
    CType type;

    func_type = func->f.func_type;
    اگر (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == پوچ)) {
        /* default casting : only need to convert float to double */
        اگر ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } وگرنه اگر (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } وگرنه اگر (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } وگرنه اگر (arg == پوچ) {
        tcc_error("too many arguments to function");
    } وگرنه {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
ایستا تهی عبارت_type(CType *type, تهی (*عبارت_fn)(تهی))
{
    nocode_wanted++;
    عبارت_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
ایستا تهی parse_عبارت_type(CType *type)
{
    صحیح n;
    AttributeDef ad;

    skip('(');
    اگر (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } وگرنه {
        عبارت_type(type, gexpr);
    }
    skip(')');
}

ایستا تهی parse_type(CType *type)
{
    AttributeDef ad;
    صحیح n;

    اگر (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

ایستا تهی parse_builtin_params(صحیح nc, ثابت نویسه *args)
{
    نویسه c, sep = '(';
    CType type;
    اگر (nc)
        nocode_wanted++;
    next();
    اگر (*args == 0)
	skip(sep);
    وقتی ((c = *args++)) {
	skip(sep);
	sep = ',';
        اگر (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ادامه;
        }
        عبارت_eq();
        type.ref = پوچ;
        type.t = 0;
	انتخاب (c) {
	    حالت 'e':
		ادامه;
	    حالت 'V':
                type.t = VT_CONSTANT;
	    حالت 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                بشکن;
	    حالت 'S':
                type.t = VT_CONSTANT;
	    حالت 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                بشکن;
	    حالت 'i':
                type.t = VT_INT;
                بشکن;
	    حالت 'l':
                type.t = VT_SIZE_T;
                بشکن;
	    پیشفرض:
                بشکن;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    اگر (nc)
        nocode_wanted--;
}

ایستا تهی parse_atomic(صحیح atok)
{
    صحیح size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    نویسه buf[40];
    ایستا ثابت نویسه *ثابت templates[] = {
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
    ثابت نویسه *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = پوچ;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    برای (arg = 0;;) {
        عبارت_eq();
        انتخاب (template[arg]) {
        حالت 'a':
        حالت 'A':
            atom_ptr = &vtop->type;
            اگر ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            اگر (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            بشکن;

        حالت 'p':
            اگر ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            بشکن;
        حالت 'v':
            gen_assign_cast(atom);
            بشکن;
        حالت 'l':
            indir();
            gen_assign_cast(atom);
            بشکن;
        حالت 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            بشکن;
        حالت 'm':
            gen_assign_cast(&int_type);
            بشکن;
        حالت 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            بشکن;
        }
        اگر ('.' == template[++arg])
            بشکن;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    انتخاب (template[arg + 1]) {
    حالت 'b':
        ct.t = VT_BOOL;
        بشکن;
    حالت 'v':
        ct = *atom;
        بشکن;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    اگر (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#وگرنه
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    اگر (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC تهی unary(تهی)
{
    صحیح n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    اگر (debug_modes)
        tcc_debug_سطر(tcc_state), tcc_tcov_check_سطر (tcc_state, 1);

    type.ref = پوچ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    انتخاب(tok) {
    حالت TOK_EXTENSION:
        next();
        برو tok_next;
    حالت TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        برو افزودن_tokc;
#endif
    حالت TOK_CINT:
    حالت TOK_CCHAR: 
	t = VT_INT;
 افزودن_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        بشکن;
    حالت TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        برو افزودن_tokc;
    حالت TOK_CLLONG:
        t = VT_LLONG;
	برو افزودن_tokc;
    حالت TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	برو افزودن_tokc;
    حالت TOK_CFLOAT:
        t = VT_FLOAT;
	برو افزودن_tokc;
    حالت TOK_CDOUBLE:
        t = VT_DOUBLE;
	برو افزودن_tokc;
    حالت TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#وگرنه
        t = VT_LDOUBLE;
#endif
	برو افزودن_tokc;
    حالت TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	برو افزودن_tokc;
    حالت TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	برو افزودن_tokc;
    حالت TOK___FUNCTION__:
        اگر (!gnu_ext)
            برو tok_identifier;
        /* fall thru */
    حالت TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        برو case_TOK_STR;
    حالت TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#وگرنه
        t = VT_INT;
#endif
        برو str_init;
    حالت TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        اگر (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, اندازه(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        بشکن;
    حالت TOK_SOTYPE:
    حالت '(':
        t = tok;
        next();
        /* cast ? */
        اگر (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            اگر (tok == '{') {
                    /* data is allocated locally by default */
                اگر (global_عبارت)
                    r = VT_CONST;
                وگرنه
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                اگر (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, اندازه(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } وگرنه اگر (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                بازگشت;
            } وگرنه {
                unary();
                gen_cast(&type);
            }
        } وگرنه اگر (tok == '{') {
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
            block(STMT_عبارت);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            اگر (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } وگرنه {
            gexpr();
            skip(')');
        }
        بشکن;
    حالت '*':
        next();
        unary();
        indir();
        بشکن;
    حالت '&':
        next();
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
        mk_pointer(&vtop->type);
        gaddrof();
        بشکن;
    حالت '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        بشکن;
    حالت '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        بشکن;
    حالت '+':
        next();
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
        بشکن;
    حالت TOK_SIZEOF:
    حالت TOK_ALIGNOF1:
    حالت TOK_ALIGNOF2:
    حالت TOK_ALIGNOF3:
        t = tok;
        next();
        اگر (tok == '(')
            tok = TOK_SOTYPE;
        عبارت_type(&type, unary);
        اگر (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } وگرنه {
            type_size(&type, &align);
            s = پوچ;
            اگر (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            اگر (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        بشکن;

    حالت TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        بشکن;
    حالت TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        بشکن;
    حالت TOK_builtin_choose_عبارت:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = عبارت_const64();
	    skip(',');
	    اگر (!c) {
		nocode_wanted++;
	    }
	    عبارت_eq();
	    اگر (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    اگر (c) {
		nocode_wanted++;
	    }
	    عبارت_eq();
	    اگر (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        بشکن;
    حالت TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        بشکن;
    حالت TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        بشکن;
    حالت TOK_builtin_frame_address:
    حالت TOK_builtin_return_address:
        {
            صحیح tok1 = tok;
            صحیح level;
            next();
            skip('(');
            level = عبارت_const();
            اگر (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            وقتی (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            اگر (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#وگرنهاگر defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#وگرنه
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        بشکن;
#ifdef TCC_TARGET_RISCV64
    حالت TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        اگر (r == VT_LLOCAL)
            r = VT_LOCAL;
        اگر (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        بشکن;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    حالت TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        اگر (r == VT_LLOCAL)
            r = VT_LOCAL;
        اگر (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        بشکن;
#وگرنه
    حالت TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	بشکن;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    حالت TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        بشکن;
    }
    حالت TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        بشکن;
    }
#endif
#ifdef TCC_TARGET_ARM64
    حالت TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        بشکن;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    حالت TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        بشکن;
    }
#endif

    /* atomic operations */
    حالت TOK___atomic_store:
    حالت TOK___atomic_load:
    حالت TOK___atomic_exchange:
    حالت TOK___atomic_compare_exchange:
    حالت TOK___atomic_fetch_add:
    حالت TOK___atomic_fetch_sub:
    حالت TOK___atomic_fetch_or:
    حالت TOK___atomic_fetch_xor:
    حالت TOK___atomic_fetch_and:
    حالت TOK___atomic_fetch_nand:
    حالت TOK___atomic_add_fetch:
    حالت TOK___atomic_sub_fetch:
    حالت TOK___atomic_or_fetch:
    حالت TOK___atomic_xor_fetch:
    حالت TOK___atomic_and_fetch:
    حالت TOK___atomic_nand_fetch:
        parse_atomic(tok);
        بشکن;

    /* pre operations */
    حالت TOK_INC:
    حالت TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        بشکن;
    حالت '-':
        next();
        unary();
	اگر (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} وگرنه {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        بشکن;
    حالت TOK_LAND:
        اگر (!gnu_ext)
            برو tok_identifier;
        next();
        /* allow to take the address of a label */
        اگر (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        اگر (!s) {
            s = label_افزودن(&global_label_پشته, tok, LABEL_FORWARD);
        } وگرنه {
            اگر (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        اگر ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        بشکن;

    حالت TOK_GENERIC:
    {
	CType controlling_type;
	صحیح has_default = 0;
	صحیح has_match = 0;
	صحیح learn = 0;
	TokenString *str = پوچ;
	صحیح saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	عبارت_type(&controlling_type, عبارت_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        برای (;;) {
	    learn = 0;
	    skip(',');
	    اگر (tok == TOK_DEFAULT) {
		اگر (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		اگر (!has_match)
		    learn = 1;
		next();
	    } وگرنه {
		صحیح v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		اگر (compare_types(&controlling_type, &type, 0)) {
		    اگر (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    اگر (learn) {
		اگر (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } وگرنه {
		skip_or_save_block(پوچ);
	    }
	    اگر (tok == ')')
		بشکن;
	}
	اگر (!str) {
	    نویسه buf[60];
	    type_to_str(buf, اندازه buf, &controlling_type, پوچ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	عبارت_eq();
	اگر (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	بشکن;
    }
    // special qnan , snan and infinity values
    حالت TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        بشکن;
    حالت TOK___SNAN__:
	n = 0x7f800001;
	برو special_math_val;
    حالت TOK___INF__:
	n = 0x7f800000;
	برو special_math_val;

    پیشفرض:
    tok_identifier:
        اگر (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        اگر (!s || IS_ASM_SYM(s)) {
            ثابت نویسه *name = get_tok_str(t, پوچ);
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
#ifdef TCC_TARGET_PE
            اگر (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } وگرنه اگر (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        بشکن;
    }
    
    /* post operations */
    وقتی (1) {
        اگر (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } وگرنه اگر (tok == '.' || tok == TOK_ARROW) {
            صحیح qualifiers, cumofs;
            /* field */ 
            اگر (tok == TOK_ARROW) 
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
            اگر (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            اگر (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                اگر (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } وگرنه اگر (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } وگرنه اگر (tok == '(') {
            SValue ret;
            Sym *sa;
            صحیح nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            اگر ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                اگر ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    اگر ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        برو error_func;
                } وگرنه {
                error_func:
                    expect("function pointer");
                }
            } وگرنه {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            اگر ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                اگر (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                اگر (size < 16)
                    وقتی (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    اگر (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    اگر (ret_nregs < 0)
                      vtop--;
                    وگرنه
                      nb_args++;
                }
            } وگرنه {
                ret_nregs = 1;
                ret.type = s->type;
            }

            اگر (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = پوچ;
            اگر (tok != ')') {
                r = tcc_state->reverse_funcargs;
                برای(;;) {
                    اگر (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } وگرنه {
                        عبارت_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    اگر (sa)
                        sa = sa->next;
                    اگر (tok == ')')
                        بشکن;
                    skip(',');
                }
            }
            اگر (sa)
                tcc_error("too few arguments to function");

            اگر (p) { /* with reverse_funcargs */
                برای (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    انجامبده {
                        sa = sa->next, p2 = p2->prev;
                    } وقتی (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    عبارت_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            اگر (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } وگرنه {
                /* return value */
                n = ret_nregs;
                وقتی (n > 1) {
                    صحیح rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    برای (r = 0; r < NB_REGS; ++r)
                        اگر (reg_classes[r] & rc)
                            بشکن;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                اگر (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    صحیح addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    اگر (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    برای (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        اگر (--ret_nregs == 0)
                          بشکن;
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
                اگر (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#وگرنه
                    vtop->type.t = VT_INT;
#endif
                }
            }
            اگر (s->f.func_noreturn) {
                اگر (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } وگرنه {
            بشکن;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

ایستا تهی عبارت_prod(تهی)
{
    صحیح t;

    unary();
    وقتی ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

ایستا تهی عبارت_sum(تهی)
{
    صحیح t;

    عبارت_prod();
    وقتی ((t = tok) == '+' || t == '-') {
        next();
        عبارت_prod();
        gen_op(t);
    }
}

ایستا تهی عبارت_shift(تهی)
{
    صحیح t;

    عبارت_sum();
    وقتی ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        عبارت_sum();
        gen_op(t);
    }
}

ایستا تهی عبارت_cmp(تهی)
{
    صحیح t;

    عبارت_shift();
    وقتی (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        عبارت_shift();
        gen_op(t);
    }
}

ایستا تهی عبارت_cmpeq(تهی)
{
    صحیح t;

    عبارت_cmp();
    وقتی ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        عبارت_cmp();
        gen_op(t);
    }
}

ایستا تهی عبارت_and(تهی)
{
    عبارت_cmpeq();
    وقتی (tok == '&') {
        next();
        عبارت_cmpeq();
        gen_op('&');
    }
}

ایستا تهی عبارت_xor(تهی)
{
    عبارت_and();
    وقتی (tok == '^') {
        next();
        عبارت_and();
        gen_op('^');
    }
}

ایستا تهی عبارت_or(تهی)
{
    عبارت_xor();
    وقتی (tok == '|') {
        next();
        عبارت_xor();
        gen_op('|');
    }
}

ایستا تهی عبارت_landor(صحیح op);

ایستا تهی عبارت_land(تهی)
{
    عبارت_or();
    اگر (tok == TOK_LAND)
        عبارت_landor(tok);
}

ایستا تهی عبارت_lor(تهی)
{
    عبارت_land();
    اگر (tok == TOK_LOR)
        عبارت_landor(tok);
}

# define عبارت_landor_next(op) op == TOK_LAND ? عبارت_or() : عبارت_land()
#وگرنه /* defined precedence_parser */
# define عبارت_landor_next(op) unary(), عبارت_infix(precedence(op) + 1)
# define عبارت_lor() unary(), عبارت_infix(1)

ایستا صحیح precedence(صحیح tok)
{
    انتخاب (tok) {
        حالت TOK_LOR: بازگشت 1;
        حالت TOK_LAND: بازگشت 2;
	حالت '|': بازگشت 3;
	حالت '^': بازگشت 4;
	حالت '&': بازگشت 5;
	حالت TOK_EQ: حالت TOK_NE: بازگشت 6;
 relat: حالت TOK_ULT: حالت TOK_UGE: بازگشت 7;
	حالت TOK_SHL: حالت TOK_SAR: بازگشت 8;
	حالت '+': حالت '-': بازگشت 9;
	حالت '*': حالت '/': حالت '%': بازگشت 10;
	پیشفرض:
	    اگر (tok >= TOK_ULE && tok <= TOK_GT)
	        برو relat;
	    بازگشت 0;
    }
}
ایستا unsigned نویسه prec[256];
ایستا تهی init_prec(تهی)
{
    صحیح i;
    برای (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

ایستا تهی عبارت_landor(صحیح op);

ایستا تهی عبارت_infix(صحیح p)
{
    صحیح t = tok, p2;
    وقتی ((p2 = precedence(t)) >= p) {
        اگر (t == TOK_LOR || t == TOK_LAND) {
            عبارت_landor(t);
        } وگرنه {
            next();
            unary();
            اگر (precedence(tok) > p2)
              عبارت_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
ایستا صحیح condition_3way(تهی)
{
    صحیح c = -1;
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    بازگشت c;
}

ایستا تهی عبارت_landor(صحیح op)
{
    صحیح t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    برای(;;) {
        c = f ? i : condition_3way();
        اگر (c < 0)
            save_regs(1), cc = 0;
        وگرنه اگر (c != i)
            nocode_wanted++, f = 1;
        اگر (tok != op)
            بشکن;
        اگر (c < 0)
            t = gvtst(i, t);
        وگرنه
            vpop();
        next();
        عبارت_landor_next(op);
    }
    اگر (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } وگرنه {
        gvtst_set(i, t);
    }
}

ایستا صحیح is_cond_bool(SValue *sv)
{
    اگر ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        بازگشت (unsigned)sv->c.i < 2;
    اگر (sv->r == VT_CMP)
        بازگشت 1;
    بازگشت 0;
}

ایستا تهی عبارت_cond(تهی)
{
    صحیح tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    عبارت_lor();
    اگر (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        اگر (!g) {
            اگر (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } وگرنه {
                vpop();
            }
        } وگرنه اگر (c < 0) {
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
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        اگر (g) {
            u = tt;
        } وگرنه اگر (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } وگرنه
          u = 0;

        اگر (c == 0)
          nocode_wanted--;
        اگر (c == 1)
          nocode_wanted++;
        skip(':');
        عبارت_cond();

        اگر ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

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
            gvtst_set(0, t1);
            gvtst_set(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            بازگشت;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        اگر (c != 1) {
            gen_cast(&type);
            اگر (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        اگر (USING_TWO_واژگان(type.t))
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
           operand */
        اگر (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            اگر (islv) {
                mk_pointer(&vtop->type);
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

ایستا تهی عبارت_eq(تهی)
{
    صحیح t;
    
    عبارت_cond();
    اگر ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        اگر (t == '=') {
            عبارت_eq();
        } وگرنه {
            vdup();
            عبارت_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC تهی gexpr(تهی)
{
    عبارت_eq();
    اگر (tok == ',') {
        انجامبده {
            vpop();
            next();
            عبارت_eq();
        } وقتی (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        اگر ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            اگر (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
ایستا تهی عبارت_const1(تهی)
{
    nocode_wanted += CONST_WANTED_BIT;
    عبارت_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
ایستا درونخطی int64_t عبارت_const64(تهی)
{
    int64_t c;
    عبارت_const1();
    اگر ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    بازگشت c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC صحیح عبارت_const(تهی)
{
    صحیح c;
    int64_t wc = عبارت_const64();
    c = wc;
    اگر (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    بازگشت c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
ایستا تهی gfunc_return(CType *func_type)
{
    اگر ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        صحیح ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        اگر (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } وگرنه اگر (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } وگرنه {
            /* returning structure packed into registers */
            صحیح size, addr, align, rc, n;
            size = type_size(func_type,&align);
            اگر (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		اگر (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		اگر (ret_align > align)
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
            برای (n = ret_nregs; --n > 0;) {
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
    } وگرنه {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

ایستا تهی check_func_return(تهی)
{
    اگر ((func_vt.t & VT_BTYPE) == VT_VOID)
        بازگشت;
    اگر ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } وگرنه {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

ایستا صحیح case_cmp(uint64_t a, uint64_t b)
{
    اگر (cur_switch->sv.type.t & VT_UNSIGNED)
        بازگشت a < b ? -1 : a > b;
    وگرنه
        بازگشت (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

ایستا صحیح case_cmp_qs(ثابت تهی *pa, ثابت تهی *pb)
{
    بازگشت case_cmp((*(ساختار case_t**)pa)->v1, (*(ساختار case_t**)pb)->v1);
}

ایستا تهی case_sort(ساختار switch_t *sw)
{
    ساختار case_t **p;
    اگر (sw->n < 2)
        بازگشت;
    qsort(sw->p, sw->n, اندازه *sw->p, case_cmp_qs);
    p = sw->p;
    وقتی (p < sw->p + sw->n - 1) {
        اگر (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            صحیح l1 = p[0]->سطر, l2 = p[1]->سطر;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } وگرنه اگر (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * اندازه *p);
        } وگرنه
            ++p;
    }
}

ایستا صحیح gcase(ساختار case_t **base, صحیح len, صحیح dsym)
{
    ساختار case_t *p;
    صحیح t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    اگر (t != VT_LLONG)
        t = VT_INT;
    وقتی (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        اگر (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } وگرنه {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            اگر (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            وگرنه
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
    بازگشت gjmp(dsym);
}

ایستا تهی end_switch(تهی)
{
    ساختار switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
ایستا تهی save_lvalues(تهی)
{
    SValue *sv = vtop;
    وقتی (sv >= vstack) {
        اگر (sv->sym && (sv->r & VT_LVAL)) {
            صحیح align, size = type_size(&sv->type, &align);
            صحیح r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

ایستا تهی try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    برای (; cls != stop; cls = cls->next) {
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


ایستا تهی try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    صحیح ocd, ccd;

    اگر (!cur_scope->cl.s)
	بازگشت;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    برای (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    برای (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    برای (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
ایستا تهی block_cleanup(ساختار scope *o)
{
    صحیح jmp = 0;
    Sym *g, **pg;
    برای (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        اگر (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            اگر (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            اگر (!o->cl.n)
                برو remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } وگرنه {
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

ایستا تهی vla_restore(صحیح loc)
{
    اگر (loc)
        gen_vla_sp_restore(loc);
}

ایستا تهی vla_leave(ساختار scope *o)
{
    ساختار scope *c = cur_scope, *v = پوچ;
    برای (; c != o && c; c = c->prev)
      اگر (c->vla.رقم)
        v = c;
    اگر (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

ایستا تهی new_scope(ساختار scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.رقم = 0;

    /* record local declaration stack position */
    o->lstk = local_پشته;
    o->llstk = local_label_پشته;
    ++local_scope;
}

ایستا تهی prev_scope(ساختار scope *o, صحیح is_عبارت)
{
    vla_leave(o->prev);

    اگر (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    اگر (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_عبارت);

    /* pop locally defined labels */
    label_برداشت(&local_label_پشته, o->llstk, is_عبارت);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_برداشت(&local_پشته, o->lstk, is_عبارت);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
ایستا تهی leave_scope(ساختار scope *o)
{
    اگر (!o)
        بازگشت;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
ایستا تهی new_scope_s(ساختار scope *o)
{
    o->lstk = local_پشته;
    ++local_scope;
}

ایستا تهی prev_scope_s(ساختار scope *o)
{
    sym_برداشت(&local_پشته, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

ایستا تهی lblock(صحیح *bsym, صحیح *csym)
{
    ساختار scope *lo = loop_scope, *co = cur_scope;
    صحیح *b = co->bsym, *c = co->csym;
    اگر (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    اگر (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
ایستا تهی gexpr_decl(تهی)
{
    صحیح v = decl(VT_JMP);
    اگر (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } وگرنه {
        اگر (v)
            skip(';');
        gexpr();
    }
}

ایستا تهی block(صحیح flags)
{
    صحیح a, b, c, d, e, t;
    ساختار scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    اگر (TOK_HAS_مقدار(t))
        برو عبارت;
    next();

    اگر (debug_modes)
        tcc_tcov_check_سطر (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    اگر (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        اگر (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } وگرنه {
            gsym(a);
        }
        prev_scope_s(&o);

    } وگرنه اگر (t == TOK_WHILE) {
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

    } وگرنه اگر (t == '{') {
        اگر (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        وقتی (tok == TOK_LABEL) {
            انجامبده {
                next();
                اگر (tok < TOK_UIDENT)
                    expect("label identifier");
                label_افزودن(&local_label_پشته, tok, LABEL_DECLARED);
                next();
            } وقتی (tok == ',');
            skip(';');
        }

        وقتی (tok != '}') {
	    decl(VT_LOCAL);
            اگر (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_عبارت);
        اگر (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        اگر (local_scope)
            next();
        وگرنه اگر (!nocode_wanted)
            check_func_return();

    } وگرنه اگر (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        اگر (tok != ';') {
            gexpr();
            اگر (b) {
                gen_assign_cast(&func_vt);
            } وگرنه {
                اگر (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } وگرنه اگر (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } وگرنه اگر (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(ریشه_scope);
        اگر (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        اگر (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        اگر (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } وگرنه اگر (t == TOK_BREAK) {
        /* compute jump */
        اگر (!cur_scope->bsym)
            tcc_error("cannot break");
        اگر (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        وگرنه
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } وگرنه اگر (t == TOK_CONTINUE) {
        /* compute jump */
        اگر (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } وگرنه اگر (t == TOK_FOR) {
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
        prev_scope(&o, 0);

    } وگرنه اگر (t == TOK_DO) {
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

    } وگرنه اگر (t == TOK_SWITCH) {
        ساختار switch_t *sw;

        sw = tcc_mallocz(اندازه *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
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
        lblock(&a, پوچ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        اگر (sw->nocode_wanted)
            برو skip_switch;
        case_sort(sw);
        sw->bsym = پوچ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        اگر (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        وگرنه
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } وگرنه اگر (t == TOK_CASE) {
        ساختار case_t *cr;
        اگر (!cur_switch)
            expect("switch");
        cr = tcc_malloc(اندازه(ساختار case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(عبارت_const64(), t);
        اگر (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(عبارت_const64(), t);
            اگر (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        اگر (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->سطر = file->سطر_رقم;
        skip(':');
        برو block_after_label;

    } وگرنه اگر (t == TOK_DEFAULT) {
        اگر (!cur_switch)
            expect("switch");
        اگر (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        برو block_after_label;

    } وگرنه اگر (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        اگر (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            اگر ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } وگرنه اگر (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            اگر (!s)
              s = label_افزودن(&global_label_پشته, tok, LABEL_FORWARD);
            وگرنه اگر (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    اگر (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		اگر (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } وگرنه {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } وگرنه {
            expect("label identifier");
        }
        skip(';');

    } وگرنه اگر (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } وگرنه {
        اگر (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            اگر (s) {
                اگر (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, پوچ));
                s->r = LABEL_DEFINED;
		اگر (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    برای (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_برداشت(&s->next, پوچ, 0);
		} وگرنه
		  gsym(s->jnext);
            } وگرنه {
                s = label_افزودن(&global_label_پشته, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(پوچ);

            اگر (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            اگر (tok != '}') {
                اگر (0 == (flags & STMT_COMPOUND))
                    برو again;
                /* C23: insert implicit null-statement whithin compound statement */
            } وگرنه {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } وگرنه {
            /* expression case */
            اگر (t != ';') {
                unget_tok(t);
    عبارت:
                اگر (flags & STMT_عبارت) {
                    vpop();
                    gexpr();
                } وگرنه {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    اگر (debug_modes)
        tcc_tcov_check_سطر (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
ایستا تهی skip_or_save_block(TokenString **str)
{
    صحیح braces = tok == '{';
    صحیح level = 0;
    اگر (str)
      *str = tok_str_alloc();

    وقتی (1) {
	صحیح t = tok;
        اگر (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             بشکن;
	اگر (t == TOK_EOF) {
	     اگر (str || level > 0)
	       tcc_error("unexpected end of file");
	     وگرنه
	       بشکن;
	}
	اگر (str)
	  tok_str_add_tok(*str);
	next();
	اگر (t == '{' || t == '(' || t == '[') {
	    level++;
	} وگرنه اگر (t == '}' || t == ')' || t == ']') {
	    level--;
	    اگر (level == 0 && braces && t == '}')
	      بشکن;
	}
    }
    اگر (str)
	tok_str_add(*str, TOK_EOF);
}

#define عبارت_CONST 1
#define عبارت_ANY   2

ایستا تهی parse_init_elem(صحیح عبارت_type)
{
    صحیح saved_global_عبارت;
    انتخاب(عبارت_type) {
    حالت عبارت_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_عبارت = global_عبارت;
        global_عبارت = 1;
        عبارت_const1();
        global_عبارت = saved_global_عبارت;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        اگر (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        بشکن;
    حالت عبارت_ANY:
        عبارت_eq();
        بشکن;
    }
}

#اگر 1
ایستا تهی init_assert(init_params *p, صحیح offset)
{
    اگر (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#وگرنه
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
ایستا تهی init_putz(init_params *p, unsigned long c, صحیح size)
{
    init_assert(p, c + size);
    اگر (p->sec) {
        /* nothing to do because globals are already set to zero */
    } وگرنه {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#اگر defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
ایستا تهی decl_design_delrels(Section *sec, صحیح c, صحیح size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    اگر (!sec || !sec->reloc)
        بازگشت;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    وقتی (rel < rel_end) {
        اگر (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= اندازه *rel;
        } وگرنه {
            اگر (rel2 != rel)
                memcpy(rel2, rel, اندازه *rel);
            ++rel2;
        }
        ++rel;
    }
}

ایستا تهی decl_design_flex(init_params *p, Sym *ref, صحیح index)
{
    اگر (ref == p->flex_array_ref) {
        اگر (index >= ref->c)
            ref->c = index + 1;
    } وگرنه اگر (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
ایستا صحیح decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, صحیح flags, صحیح al)
{
    Sym *s, *f;
    صحیح index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    اگر (flags & DIF_HAVE_ELEM)
        برو no_designator;

    اگر (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        اگر (tok == ':')
            برو struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    وقتی (nb_elems == 1 && (tok == '[' || tok == '.')) {
        اگر (tok == '[') {
            اگر (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = عبارت_const();
            اگر (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = عبارت_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            اگر (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            اگر (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } وگرنه {
            صحیح cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            اگر (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = پوچ;
    }
    اگر (!cur_field) {
        اگر (tok == '=') {
            next();
        } وگرنه اگر (!gnu_ext) {
	    expect("=");
        }
    } وگرنه {
    no_designator:
        اگر (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            اگر (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } وگرنه {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    وقتی (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            اگر (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    اگر (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    اگر (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    اگر (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        صحیح i;
        اگر (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        اگر (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        وگرنه
	    vset(type, VT_LOCAL|VT_LVAL, c);
        برای (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    اگر (c - corig > al)
      al = c - corig;
    بازگشت al;
}

ایستا تهی write_ldouble(unsigned نویسه *d, تهی *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    اگر (LDOUBLE_SIZE >= 10) {
        دوگانه b = *(long دوگانه*)s;
        s = &b;
#وگرنه
    اگر (اندازه (long دوگانه) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        صحیح e = m >> 48;
        صحیح f = e >> 4 & 0x7FF;
        m <<= 11;
        اگر (0 == f) {
            اگر (0 == m)
                برو set;
            برای (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        اگر (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #اگر (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #وگرنهاگر LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } وگرنه {
    #اگر LDOUBLE_SIZE == 8
        /* long double -> double */
        دوگانه b = *(long دوگانه*)s;
        memcpy(d, &b, 8);
    #وگرنهاگر (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #وگرنهاگر (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        صحیح e = *(uint16_t*)((نویسه*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #وگرنهاگر (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((نویسه*)s + 6);
        صحیح e = read16le((نویسه*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #وگرنه
        /* unknown */
        اگر (اندازه (long دوگانه) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
ایستا تهی init_putv(init_params *p, CType *type, unsigned long c)
{
    صحیح bt;
    تهی *ptr;
    CType dtype;
    صحیح size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    اگر (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    اگر (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        اگر ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        اگر (NODATA_WANTED) {
            vtop--;
            بازگشت;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	اگر ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_مقدار + (صحیح)vtop->c.i, size);
	    اگر (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		وقتی (relofs >= اندازه(*rel)) {
                    relofs -= اندازه(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    اگر (rel->r_offset >= esym->st_مقدار + size)
		      ادامه;
		    اگر (rel->r_offset < esym->st_مقدار)
		      بشکن;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_مقدار,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#اگر PTR_SIZE == 8
				   rel->r_addend
#وگرنه
				   0
#endif
				  );
		}
	    }
	} وگرنه {
            اگر (type->t & VT_BITFIELD) {
                صحیح bit_pos, bit_size, bits, n;
                unsigned نویسه *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned نویسه*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                وقتی (bit_size) {
                    n = 8 - bit_pos;
                    اگر (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } وگرنه
            انتخاب(bt) {
	    حالت VT_BOOL:
		*(نویسه *)ptr = val != 0;
                بشکن;
	    حالت VT_BYTE:
		*(نویسه *)ptr = val;
		بشکن;
	    حالت VT_SHORT:
                write16le(ptr, val);
		بشکن;
	    حالت VT_FLOAT:
                write32le(ptr, val);
		بشکن;
	    حالت VT_DOUBLE:
                write64le(ptr, val);
		بشکن;
	    حالت VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		بشکن;

#اگر PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    حالت VT_LLONG:
	    حالت VT_PTR:
	        اگر (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        وگرنه
	          write64le(ptr, val);
	        بشکن;
            حالت VT_INT:
                write32le(ptr, val);
                بشکن;
#وگرنه
	    حالت VT_LLONG:
                write64le(ptr, val);
                بشکن;
            حالت VT_PTR:
            حالت VT_INT:
	        اگر (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        بشکن;
#endif
	    پیشفرض:
                //tcc_internal_error("unexpected type");
                بشکن;
	    }
	}
        vtop--;
    } وگرنه {
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
ایستا تهی decl_initializer(init_params *p, CType *type, unsigned long c, صحیح flags)
{
    صحیح len, n, no_oblock, i;
    صحیح size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    اگر (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_سطر(tcc_state), tcc_tcov_check_سطر (tcc_state, 1);

    اگر (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        صحیح ncw_prev = nocode_wanted;
        اگر ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? عبارت_ANY : عبارت_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    اگر (type->t & VT_ARRAY) {
        no_oblock = 1;
        اگر (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        اگر ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#وگرنه
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            اگر (size1 != (tok == TOK_STR ? 1 : اندازه(nwchar_t)))
              tcc_error("unhandled string literal merging");
            وقتی (tok == TOK_STR || tok == TOK_LSTR) {
                اگر (initstr.size)
                  initstr.size -= size1;
                اگر (tok == TOK_STR)
                  len += tokc.str.size;
                وگرنه
                  len += tokc.str.size / اندازه(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            اگر (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                برو do_init_array;
            }

            decl_design_flex(p, s, len);
            اگر (!(flags & DIF_SIZE_ONLY)) {
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
                      memcpy(p->sec->data + c, initstr.data, nb);
                } وگرنه {
                    برای(i=0;i<n;i++) {
                        اگر (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          اگر (flags & DIF_CLEAR)
                            بشکن;
                          اگر (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            بشکن;
                          }
                          ch = 0;
                        } وگرنه اگر (size1 == 1)
                          ch = ((unsigned نویسه *)initstr.data)[i];
                        وگرنه
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            اگر (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } وگرنه {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            اگر (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    وقتی (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		اگر (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    اگر (no_oblock && len >= n*size1)
		        بشکن;
		} وگرنه {
		    اگر (s->type.t == VT_UNION)
		        f = پوچ;
		    وگرنه
		        f = f->next;
		    اگر (no_oblock && f == پوچ)
		        بشکن;
		}

		اگر (tok == '}')
		    بشکن;
		skip(',');
	    }
        }
        اگر (!no_oblock)
            skip('}');

    } وگرنه اگر ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        برو one_elem;

    } وگرنه اگر ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        اگر ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	برو do_init_list;

    } وگرنه اگر (tok == '{') {
        اگر (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } وگرنه one_elem: اگر ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        اگر (flags & DIF_HAVE_ELEM)
            vpop();
        وگرنه
            skip_or_save_block(پوچ);

    } وگرنه {
	اگر (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    اگر (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? عبارت_ANY : عبارت_CONST);
	}
        اگر (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        وگرنه
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
ایستا تهی decl_initializer_alloc(CType *type, AttributeDef *ad, صحیح r, 
                                   صحیح has_init, صحیح v, صحیح scope)
{
    صحیح size, align, addr;
    TokenString *init_str = پوچ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = پوچ;
    صحیح saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    صحیح bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    اگر (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        اگر (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            اگر (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                بازگشت;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    اگر (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = پوچ;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    اگر (size < 0) {
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
            type->ref = sym_افزودن(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } وگرنه اگر (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        اگر (field) {
            وقتی (field->next)
                field = field->next;
            اگر (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    اگر (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        اگر (!has_init)
            برو err_size;
        اگر (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            وقتی (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } وگرنه
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
        اگر (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        اگر (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    اگر (ad->a.aligned) {
	صحیح speca = 1 << (ad->a.aligned - 1);
        اگر (speca > align)
            align = speca;
    } وگرنه اگر (ad->a.packed) {
        align = 1;
    }

    اگر (!v && NODATA_WANTED)
        size = 0, align = 1;

    اگر ((r & VT_VALMASK) == VT_LOCAL) {
        sec = پوچ;
#ifdef CONFIG_TCC_BCHECK
        اگر (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        اگر (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        اگر (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    اگر (ad->asm_label) {
		صحیح reg = asm_parse_regvar(ad->asm_label);
		اگر (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_افزودن(v, type, r, addr);
	    اگر (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } وگرنه {
            /* push local reference */
            vset(type, r, addr);
        }
    } وگرنه {
        CType *tp = type;
        صحیح is_const;

        وقتی ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        اگر (!sec) {
            اگر (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } وگرنه اگر (is_const) {
		sec = rodata_section;
            } وگرنه اگر (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } وگرنه اگر (tcc_state->nocommon)
                sec = bss_section;
        } وگرنه اگر (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            اگر (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                اگر (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        اگر (bcheck)
            size = size + 1; /* add padding */
#endif
        اگر (sec) {
	    addr = section_add(sec, size, align);
        } وگرنه {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        اگر (v) {
            اگر (!sym) {
                sym = sym_افزودن(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, پوچ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } وگرنه {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        اگر (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * اندازه(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    اگر (type->t & VT_VLA) {
        صحیح a;

        اگر (has_init)
            tcc_error("variable length array cannot be initialized");

        اگر (NODATA_WANTED)
            برو no_alloc;

        /* save before-VLA stack pointer if needed */
        اگر (cur_scope->vla.رقم == 0) {
            اگر (cur_scope->prev && cur_scope->prev->vla.رقم) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } وگرنه {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#اگر defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.رقم++;
    } وگرنه اگر (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        اگر (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    اگر (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
ایستا تهی func_vla_arg_code(Sym *arg)
{
    صحیح align;
    TokenString *vla_array_tok = پوچ;

    اگر (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    اگر ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

ایستا تهی func_vla_arg(Sym *sym)
{
    Sym *arg;

    برای (arg = sym->type.ref->next; arg; arg = arg->next)
        اگر ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, صحیح c, صحیح byref)
{
    s = sym_find(s->v);
    اگر (!s) /* unnamed parameters, not enabled */
        بازگشت پوچ;
    s->c = c;
    اگر (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    بازگشت s;
}

/* push parameters (and their types), last first */
ایستا تهی sym_افزودن_params(Sym *ref)
{
    Sym *s = ref;
    وقتی (s->next)
        s = s->next;
    وقتی (s != ref) {
        اگر ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_پشته);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
ایستا تهی gen_function(Sym *sym)
{
    ساختار scope f = { 0 };

    cur_scope = ریشه_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    اگر (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, پوچ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    اگر (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    اگر (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_پشته, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_افزودن_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(پوچ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_برداشت(&local_پشته, پوچ, 0);
    label_برداشت(&global_label_پشته, پوچ, 0);
    sym_برداشت(&all_cleanups, پوچ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = پوچ;
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

ایستا تهی gen_inline_functions(TCCState *s)
{
    Sym *sym;
    صحیح inline_generated, i;
    ساختار InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    انجامبده {
        inline_generated = 0;
        برای (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            اگر (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = پوچ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } وقتی (inline_generated);
    tcc_close();
}

ایستا تهی free_inline_functions(TCCState *s)
{
    صحیح i;
    /* free tokens of unused inline functions */
    برای (i = 0; i < s->nb_inline_fns; ++i) {
        ساختار InlineFunc *fn = s->inline_fns[i];
        اگر (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

ایستا تهی do_Static_assert(تهی)
{
    صحیح c;
    ثابت نویسه *پیام;

    next();
    skip('(');
    c = عبارت_const();
    پیام = "_Static_assert fail";
    اگر (tok == ',') {
        next();
        پیام = parse_mult_str("string constant")->data;
    }
    skip(')');
    اگر (c == 0)
        tcc_error("%s", پیام);
    skip(';');
}

#ifdef TCC_TARGET_PE
ایستا تهی pe_check_linkage(CType *type, AttributeDef *ad)
{
    اگر (!ad->a.dllimport && !ad->a.dllexport)
        بازگشت;
    اگر (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    اگر (type->t & VT_TYPEDEF) {
        ثابت نویسه *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } وگرنه اگر (ad->a.dllimport) {
        اگر ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        وگرنه
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
ایستا صحیح decl(صحیح l)
{
    صحیح v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    وقتی (1) {

        oldint = 0;
        اگر (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            اگر (l == VT_JMP)
                بازگشت 0;
            /* skip redundant ';' if not in old parameter decl scope */
            اگر (tok == ';' && l != VT_CMP) {
                next();
                ادامه;
            }
            اگر (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ادامه;
            }
            اگر (l != VT_CONST)
                بشکن;
            اگر (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ادامه;
            }
            اگر (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } وگرنه {
                اگر (tok != TOK_EOF)
                    expect("declaration");
                بشکن;
            }
        }

        اگر (tok == ';') {
            اگر ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            وگرنه اگر (IS_ENUM(btype.t))
                ; /* enum decl */
            وگرنه
                tcc_warning("useless type defines no instances");
            اگر (l == VT_JMP)
                بازگشت 1;
            next();
            ادامه;
        }

        وقتی (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
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
                    وگرنه
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } وگرنه اگر (oldint) {
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
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            اگر (tok == '{') {
                اگر (l != VT_CONST)
                    tcc_error("cannot use local functions");
                اگر ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                برای (sa = sym->type.ref; (sa = sa->next) != پوچ;) {
                    اگر (!(sa->v & ~SYM_FIELD))
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
                    ساختار InlineFunc *fn;
                    fn = tcc_malloc(اندازه *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } وگرنه {
                    /* compute text section */
                    cur_text_section = text_section;
                    اگر (ad.section) {
                        cur_text_section = ad.section;
                        اگر (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                بشکن;
            } وگرنه {
                has_init = 0;
		اگر (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    برای (sym = func_vt.ref->next; sym; sym = sym->next)
			اگر ((sym->v & ~SYM_FIELD) == v)
			    برو found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, پوچ));
                found:
		    اگر (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, پوچ));
		    اگر (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, پوچ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} وگرنه اگر (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    اگر (sym && sym->sym_scope == local_scope) {
                        اگر (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, پوچ));
                        sym->type = type;
                    } وگرنه {
                        sym = sym_افزودن(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    اگر ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    اگر (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} وگرنه اگر ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } وگرنه {
                    r = 0;
                    اگر ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } وگرنه اگر (!(type.t & VT_ARRAY)) {
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
                    } وگرنه {
                        اگر (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        وگرنه
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        اگر (has_init)
                            next();
                        وگرنه اگر (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    اگر (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        اگر (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_مقدار, esym->st_size, 1);
                    }
                }
                اگر (tok != ',') {
                    اگر (l == VT_JMP)
                        بازگشت has_init ? v : 1;
                    skip(';');
                    بشکن;
                }
                next();
            }
        }
    }
    بازگشت 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
