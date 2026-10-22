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
#અન્તર્ભાવ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA પૂર્ણાંક rsym, anon_sym, ind, loc;

ST_DATA Sym *global_ઢગલો;
ST_DATA Sym *local_ઢગલો;
ST_DATA Sym *define_ઢગલો;
ST_DATA Sym *global_label_ઢગલો;
ST_DATA Sym *local_label_ઢગલો;

સ્થિર Sym *sym_free_first;
સ્થિર શૂન્ય **sym_pools;
સ્થિર પૂર્ણાંક nb_sym_pools;

સ્થિર Sym *all_cleanups, *pending_gotos;
સ્થિર પૂર્ણાંક local_scope;
ST_DATA અક્ષર debug_modes;

ST_DATA SValue *vtop;
સ્થિર SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA પૂર્ણાંક nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() જો(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA પૂર્ણાંક global_પદાવલિ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA પૂર્ણાંક func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA પૂર્ણાંક func_vc; /* stack address for implicit struct return storage */
ST_DATA પૂર્ણાંક func_ind; /* function start address */
સ્થિર પૂર્ણાંક func_old;
ST_DATA અચલ અક્ષર *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
સ્થિર CString initstr;

#જો PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#અથવાજો LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#નહીંતર
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

સ્થિર સંરચના switch_t {
    સંરચના case_t {
        int64_t v1, v2;
        પૂર્ણાંક ind, લીટી;
    } **p; પૂર્ણાંક n; /* list of case ranges */
    પૂર્ણાંક def_sym; /* default symbol */
    પૂર્ણાંક nocode_wanted;
    પૂર્ણાંક *bsym;
    સંરચના scope *scope;
    સંરચના switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_સંખ્યા 8
/*list of temporary local variables on the stack in current function. */
સ્થિર સંરચના temp_local_variable {
	પૂર્ણાંક location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_સંખ્યા];
સ્થિર પૂર્ણાંક nb_temp_local_vars;

સ્થિર સંરચના scope {
    સંરચના scope *prev;
    સંરચના { પૂર્ણાંક loc, locorig, અંક; } vla;
    સંરચના { Sym *s; પૂર્ણાંક n; } cl;
    પૂર્ણાંક *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *મૂળ_scope;

પ્રકારવ્યાખ્યા સંરચના {
    Section *sec;
    પૂર્ણાંક local_offset;
    Sym *flex_array_ref;
} init_params;

#જો 1
#define precedence_parser
સ્થિર શૂન્ય init_prec(શૂન્ય);
#endif

સ્થિર શૂન્ય block(પૂર્ણાંક flags);
#define STMT_પદાવલિ 1
#define STMT_COMPOUND 2

સ્થિર શૂન્ય gen_cast(CType *type);
સ્થિર શૂન્ય gen_cast_s(પૂર્ણાંક t);
સ્થિર અંતઃરેખ CType *pointed_type(CType *type);
સ્થિર શૂન્ય check_restrict_type(CType *type);
સ્થિર પૂર્ણાંક type_qualifiers(CType *type);
સ્થિર શૂન્ય parse_btype_qualify(CType *type, પૂર્ણાંક qualifiers);
સ્થિર પૂર્ણાંક is_compatible_types(CType *type1, CType *type2);
સ્થિર પૂર્ણાંક parse_btype(CType *type, AttributeDef *ad, પૂર્ણાંક ignore_label);
સ્થિર CType *type_decl(CType *type, AttributeDef *ad, પૂર્ણાંક *v, પૂર્ણાંક td);
સ્થિર શૂન્ય parse_પદાવલિ_type(CType *type);
સ્થિર શૂન્ય init_putv(init_params *p, CType *type, unsigned long c);
સ્થિર શૂન્ય decl_initializer(init_params *p, CType *type, unsigned long c, પૂર્ણાંક flags);
સ્થિર શૂન્ય decl_initializer_alloc(CType *type, AttributeDef *ad, પૂર્ણાંક r, પૂર્ણાંક has_init, પૂર્ણાંક v, પૂર્ણાંક scope);
સ્થિર પૂર્ણાંક decl(પૂર્ણાંક l);
સ્થિર શૂન્ય પદાવલિ_eq(શૂન્ય);
સ્થિર શૂન્ય vpush_type_size(CType *type, પૂર્ણાંક *a);
સ્થિર પૂર્ણાંક is_compatible_unqualified_types(CType *type1, CType *type2);
સ્થિર અંતઃરેખ int64_t પદાવલિ_const64(શૂન્ય);
સ્થિર શૂન્ય vpush64(પૂર્ણાંક ty, unsigned long long v);
સ્થિર શૂન્ય vpush(CType *type);
સ્થિર પૂર્ણાંક gvtst(પૂર્ણાંક inv, પૂર્ણાંક t);
સ્થિર શૂન્ય gen_inline_functions(TCCState *s);
સ્થિર શૂન્ય free_inline_functions(TCCState *s);
સ્થિર શૂન્ય skip_or_save_block(TokenString **str);
સ્થિર શૂન્ય gv_dup(શૂન્ય);
સ્થિર પૂર્ણાંક get_temp_local_var(પૂર્ણાંક size,પૂર્ણાંક align,પૂર્ણાંક *r2);
સ્થિર શૂન્ય cast_error(CType *st, CType *dt);
સ્થિર શૂન્ય end_switch(શૂન્ય);
સ્થિર શૂન્ય do_Static_assert(શૂન્ય);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC શૂન્ય gsym(પૂર્ણાંક t)
{
  જો (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
સ્થિર પૂર્ણાંક gind()
{
  પૂર્ણાંક t = ind;
  CODE_ON();
  જો (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  પાછા t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
સ્થિર શૂન્ય gjmp_addr_acs(પૂર્ણાંક t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
સ્થિર પૂર્ણાંક gjmp_acs(પૂર્ણાંક t)
{
  t = gjmp(t);
  CODE_OFF();
  પાછા t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN પૂર્ણાંક is_float(પૂર્ણાંક t)
{
    પૂર્ણાંક bt = t & VT_BTYPE;
    પાછા bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

સ્થિર અંતઃરેખ પૂર્ણાંક is_integer_btype(પૂર્ણાંક bt)
{
    પાછા bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

સ્થિર પૂર્ણાંક btype_size(પૂર્ણાંક bt)
{
    પાછા bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
સ્થિર પૂર્ણાંક R_RET(પૂર્ણાંક t)
{
    જો (!is_float(t))
        પાછા REG_IRET;
#ifdef TCC_TARGET_X86_64
    જો ((t & VT_BTYPE) == VT_LDOUBLE)
        પાછા TREG_ST0;
#અથવાજો defined TCC_TARGET_RISCV64
    જો ((t & VT_BTYPE) == VT_LDOUBLE)
        પાછા REG_IRET;
#endif
    પાછા REG_FRET;
}

/* returns 2nd function return register, if any */
સ્થિર પૂર્ણાંક R2_RET(પૂર્ણાંક t)
{
    t &= VT_BTYPE;
#જો PTR_SIZE == 4
    જો (t == VT_LLONG)
        પાછા REG_IRE2;
#અથવાજો defined TCC_TARGET_X86_64
    જો (t == VT_QLONG)
        પાછા REG_IRE2;
    જો (t == VT_QFLOAT)
        પાછા REG_FRE2;
#અથવાજો defined TCC_TARGET_RISCV64
    જો (t == VT_LDOUBLE)
        પાછા REG_IRE2;
#endif
    પાછા VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_શબ્દો(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
સ્થિર શૂન્ય PUT_R_RET(SValue *sv, પૂર્ણાંક t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
સ્થિર પૂર્ણાંક RC_RET(પૂર્ણાંક t)
{
    પાછા reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
સ્થિર પૂર્ણાંક RC_TYPE(પૂર્ણાંક t)
{
    જો (!is_float(t))
        પાછા RC_INT;
#ifdef TCC_TARGET_X86_64
    જો ((t & VT_BTYPE) == VT_LDOUBLE)
        પાછા RC_ST0;
    જો ((t & VT_BTYPE) == VT_QFLOAT)
        પાછા RC_FRET;
#અથવાજો defined TCC_TARGET_RISCV64
    જો ((t & VT_BTYPE) == VT_LDOUBLE)
        પાછા RC_INT;
#endif
    પાછા RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
સ્થિર પૂર્ણાંક RC2_TYPE(પૂર્ણાંક t, પૂર્ણાંક rc)
{
    જો (!USING_TWO_શબ્દો(t))
        પાછા 0;
#ifdef RC_IRE2
    જો (rc == RC_IRET)
        પાછા RC_IRE2;
#endif
#ifdef RC_FRE2
    જો (rc == RC_FRET)
        પાછા RC_FRE2;
#endif
    જો (rc & RC_FLOAT)
        પાછા RC_FLOAT;
    પાછા RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC પૂર્ણાંક ieee_finite(દ્વિગુણ d)
{
    પૂર્ણાંક p[4];
    memcpy(p, &d, કદ(દ્વિગુણ));
    પાછા ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC શૂન્ય test_lvalue(શૂન્ય)
{
    જો (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC શૂન્ય check_vstack(શૂન્ય)
{
    જો (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (પૂર્ણાંક)(vtop - vstack + 1));
}

#જો 0
/* dump 'b' vstack entries starting with 'a'  */
શૂન્ય pv (અચલ અક્ષર *lbl, પૂર્ણાંક a, પૂર્ણાંક b)
{
    પૂર્ણાંક i;
    માટે (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (પૂર્ણાંક)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
સ્થિર અંતઃરેખ શૂન્ય psyms(અચલ અક્ષર *સંદેશ, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", સંદેશ);
    જ્યારે (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

સ્થિર શૂન્ય type_to_str(અક્ષર *buf, પૂર્ણાંક buf_size, CType *type, અચલ અક્ષર *varstr);

/* print type */
સ્થિર શૂન્ય ptype(અચલ અક્ષર *સંદેશ, CType *type, પૂર્ણાંક v)
{
    અક્ષર buf[500];
    type_to_str(buf, કદ(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, ખાલી) : ખાલી);
    printf("%s : %s;\n", સંદેશ, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC શૂન્ય tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, કદ *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    જો (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ધકેલો(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC પૂર્ણાંક tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_પદાવલિ = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_અંક | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#જો TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    પાછા 0;
}

ST_FUNC શૂન્ય tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_કાઢો(&global_ઢગલો, ખાલી, 0);
    sym_કાઢો(&local_ઢગલો, ખાલી, 0);
    /* free preprocessor macros */
    free_defines(ખાલી);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    જ્યારે (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = ખાલી;
    all_cleanups = ખાલી;
    pending_gotos = ખાલી;
    nb_temp_local_vars = 0;
    global_label_ઢગલો = ખાલી;
    local_label_ઢગલો = ખાલી;
    cur_text_section = ખાલી;
    sym_free_first = ખાલી;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  જો (!s || !s->c)
    પાછા ખાલી;
  પાછા &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC શૂન્ય update_storage(Sym *sym)
{
    ElfSym *esym;
    પૂર્ણાંક sym_bind, old_sym_bind;

    esym = elfsym(sym);
    જો (!esym)
        પાછા;

    જો (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    જો (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    નહીંતર જો (sym->a.weak)
        sym_bind = STB_WEAK;
    નહીંતર
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    જો (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    જો (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    જો (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#જો 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ખાલી),
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

ST_FUNC શૂન્ય put_extern_sym2(Sym *sym, પૂર્ણાંક sh_અંક,
                            addr_t કિંમત, unsigned long size,
                            પૂર્ણાંક can_add_underscore)
{
    પૂર્ણાંક sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    અચલ અક્ષર *name;
    અક્ષર buf1[256];

    જો (!sym->c) {
        name = get_tok_str(sym->v, ખાલી);
        t = sym->type.t;
        જો ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } નહીંતર જો ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            જો (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } નહીંતર જો (t & VT_TLS) {
            sym_type = STT_TLS;
        } નહીંતર {
            sym_type = STT_OBJECT;
        }
        જો (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        નહીંતર
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        જો (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            જો (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            જો (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        જો (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ખાલી);
            can_add_underscore = 0;
        }

        જો (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, કદ(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, કિંમત, size, info, other, sh_અંક, name);

        જો (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_અંક, sym_bind, sym_type);

    } નહીંતર {
        esym = elfsym(sym);
        esym->st_કિંમત = કિંમત;
        esym->st_size = size;
        esym->st_shndx = sh_અંક;
    }
    update_storage(sym);
}

ST_FUNC શૂન્ય put_extern_sym(Sym *sym, Section *s, addr_t કિંમત, unsigned long size)
{
    જો (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        પાછા;
    put_extern_sym2(sym, s ? s->sh_અંક : SHN_UNDEF, કિંમત, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC શૂન્ય greloca(Section *s, Sym *sym, unsigned long offset, પૂર્ણાંક type,
                     addr_t addend)
{
    પૂર્ણાંક c = 0;

    જો (nocode_wanted && s == cur_text_section)
        પાછા;

    જો (sym) {
        જો (0 == sym->c) {
            put_extern_sym(sym, ખાલી, 0, 0);
            જો (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                જ્યારે (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#જો PTR_SIZE == 4
ST_FUNC શૂન્ય greloc(Section *s, Sym *sym, unsigned long offset, પૂર્ણાંક type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
સ્થિર Sym *__sym_malloc(શૂન્ય)
{
    Sym *sym_pool, *sym, *last_sym;
    પૂર્ણાંક i;

    sym_pool = tcc_malloc(SYM_POOL_NB * કદ(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    માટે(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    પાછા last_sym;
}

સ્થિર અંતઃરેખ Sym *sym_malloc(શૂન્ય)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    જો (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    પાછા sym;
#નહીંતર
    sym = tcc_malloc(કદ(Sym));
    પાછા sym;
#endif
}

ST_INLN શૂન્ય sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#નહીંતર
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, પૂર્ણાંક v, પૂર્ણાંક t, પૂર્ણાંક c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, કદ *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    પાછા s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, પૂર્ણાંક v)
{
    જ્યારે (s) {
        જો (s->v == v)
            પાછા s;
        s = s->prev;
    }
    પાછા ખાલી;
}

/* structure lookup */
ST_INLN Sym *struct_find(પૂર્ણાંક v)
{
    v -= TOK_IDENT;
    જો ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        પાછા ખાલી;
    પાછા table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(પૂર્ણાંક v)
{
    v -= TOK_IDENT;
    જો ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        પાછા ખાલી;
    પાછા table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
સ્થિર અંતઃરેખ શૂન્ય sym_link(Sym *s, પૂર્ણાંક yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    જો (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    નહીંતર
        ps = &ts->sym_identifier;
    જો (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } નહીંતર {
        *ps = s->prev_tok;
    }
}

સ્થિર અંતઃરેખ પૂર્ણાંક sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    પાછા IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ધકેલો(પૂર્ણાંક v, CType *type, પૂર્ણાંક r, પૂર્ણાંક c)
{
    Sym *s, **ps;
    જો (local_ઢગલો)
        ps = &local_ઢગલો;
    નહીંતર
        ps = &global_ઢગલો;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    જો ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        જો (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ખાલી));
    }
    પાછા s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ધકેલો(પૂર્ણાંક v, પૂર્ણાંક t, પૂર્ણાંક c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ઢગલો, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    જો (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        જ્યારે (*ps != ખાલી && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    પાછા s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC શૂન્ય sym_કાઢો(Sym **ptop, Sym *b, પૂર્ણાંક keep)
{
    Sym *s, *ss;
    પૂર્ણાંક v;

    s = *ptop;
    જ્યારે(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        જો ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	જો (!keep)
	    sym_free(s);
        s = ss;
    }
    જો (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(પૂર્ણાંક v)
{
    v -= TOK_IDENT;
    જો ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        પાછા ખાલી;
    પાછા table_ident[v]->sym_label;
}

ST_FUNC Sym *label_ધકેલો(Sym **ptop, પૂર્ણાંક v, પૂર્ણાંક flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    જો (ptop == &global_label_ઢગલો) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        જ્યારે (*ps != ખાલી)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    પાછા s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC શૂન્ય label_કાઢો(Sym **ptop, Sym *slast, પૂર્ણાંક keep)
{
    Sym *s, *s1;
    માટે(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        જો (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ખાલી));
        } નહીંતર જો (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ખાલી));
        } નહીંતર {
            જો (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        જો (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        જો (!keep)
            sym_free(s);
        નહીંતર
            s->r = LABEL_GONE;
    }
    જો (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
સ્થિર શૂન્ય vcheck_cmp(શૂન્ય)
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

    જો (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

સ્થિર શૂન્ય vsetc(CType *type, પૂર્ણાંક r, CValue *vc)
{
    જો (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ખાલી;
}

ST_FUNC શૂન્ય vswap(શૂન્ય)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC શૂન્ય vpop(શૂન્ય)
{
    પૂર્ણાંક v;
    v = vtop->r & VT_VALMASK;
#જો defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    જો (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } નહીંતર
#endif
    જો (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
સ્થિર શૂન્ય vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
સ્થિર શૂન્ય vpush64(પૂર્ણાંક ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ખાલી;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC શૂન્ય vpushi(પૂર્ણાંક v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
સ્થિર શૂન્ય vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
સ્થિર અંતઃરેખ શૂન્ય vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC શૂન્ય vset(CType *type, પૂર્ણાંક r, પૂર્ણાંક v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

સ્થિર શૂન્ય vseti(પૂર્ણાંક r, પૂર્ણાંક v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ખાલી;
    vset(&type, r, v);
}

ST_FUNC શૂન્ય vpushv(SValue *v)
{
    જો (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

સ્થિર શૂન્ય vdup(શૂન્ય)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC શૂન્ય vrotb(પૂર્ણાંક n)
{
    SValue tmp;
    જો (--n < 1)
        પાછા;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, કદ *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC શૂન્ય vrott(પૂર્ણાંક n)
{
    SValue tmp;
    જો (--n < 1)
        પાછા;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, કદ *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC શૂન્ય vrev(પૂર્ણાંક n)
{
    પૂર્ણાંક i;
    SValue tmp;
    vcheck_cmp();
    માટે (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC શૂન્ય vset_VT_CMP(પૂર્ણાંક op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
સ્થિર શૂન્ય vset_VT_JMP(શૂન્ય)
{
    પૂર્ણાંક op = vtop->cmp_op;

    જો (vtop->jtrue || vtop->jfalse) {
        પૂર્ણાંક origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        પૂર્ણાંક inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } નહીંતર {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        જો (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
સ્થિર શૂન્ય gvtst_set(પૂર્ણાંક inv, પૂર્ણાંક t)
{
    પૂર્ણાંક *p;

    જો (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        જો (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
સ્થિર પૂર્ણાંક gvtst(પૂર્ણાંક inv, પૂર્ણાંક t)
{
    પૂર્ણાંક op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    જો (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    જો (op > 1)
        t = gjmp_cond(op ^ inv, t);
    નહીંતર જો (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    પાછા t;
}

/* generate a zero or nozero test */
સ્થિર શૂન્ય gen_test_zero(પૂર્ણાંક op)
{
    જો (vtop->r == VT_CMP) {
        પૂર્ણાંક j;
        જો (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } નહીંતર {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC શૂન્ય vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    પૂર્ણાંક v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ધકેલો(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    પાછા sym;
}

/* push a reference to a section offset by adding a dummy symbol */
સ્થિર શૂન્ય vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(પૂર્ણાંક v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    જો (!s) {
        /* push forward reference */
        s = global_identifier_ધકેલો(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } નહીંતર જો (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    પાછા s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(પૂર્ણાંક v)
{
    CType ct = { VT_ASM_FUNC, ખાલી };
    પાછા external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC શૂન્ય vpush_helper_func(પૂર્ણાંક v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
સ્થિર શૂન્ય merge_symattr(સંરચના SymAttr *sa, સંરચના SymAttr *sa1)
{
    જો (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    જો (sa1->visibility != STV_DEFAULT) {
	પૂર્ણાંક vis = sa->visibility;
	જો (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
સ્થિર શૂન્ય merge_funcattr(સંરચના FuncAttr *fa, સંરચના FuncAttr *fa1)
{
    જો (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    જો (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    જો (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    જો (fa1->func_noreturn)
      fa->func_noreturn = 1;
    જો (fa1->func_ctor)
      fa->func_ctor = 1;
    જો (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
સ્થિર શૂન્ય merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    જો (ad1->section)
      ad->section = ad1->section;
    જો (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    જો (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    જો (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
સ્થિર શૂન્ય patch_type(Sym *sym, CType *type)
{
    જો (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        જો (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ખાલી));
        sym->type.t &= ~VT_EXTERN;
    }

    જો (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        જો ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    જો (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ખાલી));

    } નહીંતર જો ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        પૂર્ણાંક static_proto = sym->type.t & VT_STATIC;
        પૂર્ણાંક ft1 = sym->type.ref->f.func_type;
        પૂર્ણાંક ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        જો ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ખાલી));

        /* set 'inline' if both agree or if one has static */
        જો ((type->t | sym->type.t) & VT_INLINE) {
            જો (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        જો (0 == (type->t & VT_EXTERN)) {
            સંરચના FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            જો (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } નહીંતર {
            sym->type.t &= ~VT_INLINE | static_proto;
            જો (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } નહીંતર {
        જો ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        જો ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ખાલી));
    }
}

/* Merge some storage attributes.  */
સ્થિર શૂન્ય patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    જો (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    જો (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ખાલી));
#endif
    merge_symattr(&sym->a, &ad->a);
    જો (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
સ્થિર Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    જો ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    પાછા s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
સ્થિર શૂન્ય move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    પૂર્ણાંક n, bt;

    bt = s->type.t & VT_BTYPE;
    જો (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        પાછા;

    માટે (s = s->type.ref, n = 0; s; s = s->next) {
        માટે (lp = &local_ઢગલો; !!(l = *lp); lp = &l->prev) {
            જો (l == s) {
                *lp = s->prev;
                s->prev = global_ઢગલો, global_ઢગલો = s;
                જો (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } નહીંતર {
                    જો ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                જો (bt != VT_PTR)
                    n = 1;
                તોડો;
            }
        }
        જો (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            તોડો;
    }
}

/* define a new external reference to a symbol 'v' */
સ્થિર Sym *external_sym(પૂર્ણાંક v, CType *type, પૂર્ણાંક r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    જ્યારે (s && s->sym_scope)
        s = s->prev_tok;

    જો (!s) {
        /* push forward reference */
        s = global_identifier_ધકેલો(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } નહીંતર {
        patch_storage(s, ad, type);
    }
    જો (local_ઢગલો) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_ઢગલો);
    }
    પાછા s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC શૂન્ય save_regs(પૂર્ણાંક n)
{
    SValue *p, *p1;
    માટે(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC શૂન્ય save_reg(પૂર્ણાંક r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC શૂન્ય save_reg_upstack(પૂર્ણાંક r, પૂર્ણાંક n)
{
    પૂર્ણાંક l, size, align, bt, r2;
    SValue *p, *p1, sv;

    જો ((r &= VT_VALMASK) >= VT_CONST)
        પાછા;
    જો (nocode_wanted)
        પાછા;
    l = r2 = 0;
    માટે(p = vstack, p1 = vtop - n; p <= p1; p++) {
        જો ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            જો (!l) {
                bt = p->type.t & VT_BTYPE;
                જો (bt == VT_VOID)
                    ચાલુ;
                જો ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ખાલી;
                store(p->r & VT_VALMASK, &sv);
#જો defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                જો (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                જો (p->r2 < VT_CONST && USING_TWO_શબ્દો(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            જો (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } નહીંતર {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ખાલી;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC પૂર્ણાંક get_reg_ex(પૂર્ણાંક rc, પૂર્ણાંક rc2)
{
    પૂર્ણાંક r;
    SValue *p;
    
    માટે(r=0;r<NB_REGS;r++) {
        જો (reg_classes[r] & rc2) {
            પૂર્ણાંક n;
            n=0;
            માટે(p = vstack; p <= vtop; p++) {
                જો ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            જો (n <= 1)
                પાછા r;
        }
    }
    પાછા get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC પૂર્ણાંક get_reg(પૂર્ણાંક rc)
{
    પૂર્ણાંક r;
    SValue *p;

    /* find a free register */
    માટે(r=0;r<NB_REGS;r++) {
        જો (reg_classes[r] & rc) {
            જો (nocode_wanted)
                પાછા r;
            માટે(p=vstack;p<=vtop;p++) {
                જો ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    જાઓ notfound;
            }
            પાછા r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    માટે(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        જો (r < VT_CONST && (reg_classes[r] & rc))
            જાઓ save_found;
        r = p->r & VT_VALMASK;
        જો (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            પાછા r;
        }
    }
    /* Should never comes here */
    પાછા -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
સ્થિર પૂર્ણાંક get_temp_local_var(પૂર્ણાંક size,પૂર્ણાંક align, પૂર્ણાંક *r2)
{
    પૂર્ણાંક i;
    સંરચના temp_local_variable *temp_var;
    SValue *p;
    પૂર્ણાંક r;
    unsigned used = 0;

    /* mark locations that are still in use */
    માટે (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	જો (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    જો (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_સંખ્યા)
	        used |= 1<<r;
	}
    }
    માટે (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	જો(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    પાછા temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    જો (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_સંખ્યા) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	જાઓ ret_tmp;
    }
    *r2 = VT_CONST;
    પાછા loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
સ્થિર શૂન્ય move_reg(પૂર્ણાંક r, પૂર્ણાંક s, પૂર્ણાંક t)
{
    SValue sv;

    જો (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ખાલી;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC શૂન્ય gaddrof(શૂન્ય)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    જો ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
સ્થિર શૂન્ય gen_bounded_ptr_add(શૂન્ય)
{
    પૂર્ણાંક save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    જો (save) {
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
    જો (nocode_wanted)
        પાછા;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - કદ(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
સ્થિર શૂન્ય gen_bounded_ptr_deref(શૂન્ય)
{
    addr_t func;
    પૂર્ણાંક size, align;
    ElfW_Rel *rel;
    Sym *sym;

    જો (nocode_wanted)
        પાછા;

    size = type_size(&vtop->type, &align);
    પસંદગી(size) {
    સ્થિતિ  1: func = TOK___bound_ptr_indir1; તોડો;
    સ્થિતિ  2: func = TOK___bound_ptr_indir2; તોડો;
    સ્થિતિ  4: func = TOK___bound_ptr_indir4; તોડો;
    સ્થિતિ  8: func = TOK___bound_ptr_indir8; તોડો;
    સ્થિતિ 12: func = TOK___bound_ptr_indir12; તોડો;
    સ્થિતિ 16: func = TOK___bound_ptr_indir16; તોડો;
    મૂળભૂત:
        /* may happen with struct member access */
        પાછા;
    }
    sym = external_helper_sym(func);
    જો (!sym->c)
        put_extern_sym(sym, ખાલી, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
સ્થિર શૂન્ય gbound(શૂન્ય)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    જો (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        જો (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC શૂન્ય gbound_args(પૂર્ણાંક nb_args)
{
    પૂર્ણાંક i, v;
    SValue *sv;

    માટે (i = 1; i <= nb_args; ++i)
        જો (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    જો (sv->r & VT_SYM) {
        v = sv->sym->v;
        જો (v == TOK_setjmp
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
        જો (v == TOK_alloca)
            func_bound_add_epilog = 1;
#જો TARGETOS_NetBSD
        જો (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
સ્થિર શૂન્ય add_local_bounds(Sym *s, Sym *e)
{
    માટે (; s != e; s = s->prev) {
        જો (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          ચાલુ;
        /* Add arrays/structs/unions because we always take address */
        જો ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            પૂર્ણાંક align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * કદ(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
સ્થિર શૂન્ય tcc_debug_end_scope(Sym *b, પૂર્ણાંક bounds)
{
#ifdef CONFIG_TCC_BCHECK
    જો (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_ઢગલો, b);
#endif
    tcc_add_debug_info (tcc_state, local_ઢગલો, b);
}

/* increment an lvalue pointer */
સ્થિર શૂન્ય incr_offset(પૂર્ણાંક offset)
{
    પૂર્ણાંક t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

સ્થિર શૂન્ય incr_bf_adr(પૂર્ણાંક o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
સ્થિર શૂન્ય load_packed_bf(CType *type, પૂર્ણાંક bit_pos, પૂર્ણાંક bit_size)
{
    પૂર્ણાંક n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    કરો {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        જો (n > bit_size)
            n = bit_size;
        જો (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        જો (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        જો (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } જ્યારે (bit_size);
    vswap(), vpop();
    જો (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
સ્થિર શૂન્ય store_packed_bf(પૂર્ણાંક bit_pos, પૂર્ણાંક bit_size)
{
    પૂર્ણાંક bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    કરો {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        જો (bits)
            vpushi(bits), gen_op(TOK_SHR);
        જો (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        જો (n > bit_size)
            n = bit_size;
        જો (n < 8) {
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
    } જ્યારે (bit_size);
    vpop(), vpop();
}

સ્થિર પૂર્ણાંક adjust_bf(SValue *sv, પૂર્ણાંક bit_pos, પૂર્ણાંક bit_size)
{
    પૂર્ણાંક t;
    જો (0 == sv->type.ref)
        પાછા 0;
    t = sv->type.ref->auxtype;
    જો (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    પાછા t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC પૂર્ણાંક gv(પૂર્ણાંક rc)
{
    પૂર્ણાંક r, r2, r_ok, r2_ok, rc2, bt;
    પૂર્ણાંક bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    જો (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = ખાલી;
        type.t = vtop->type.t & VT_UNSIGNED;
        જો ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        જો ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        નહીંતર
            type.t |= VT_INT;

        જો (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } નહીંતર {
            પૂર્ણાંક bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } નહીંતર {
        જો (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            જો (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        જો (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        જો (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            પાછા vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        જો (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        જો (!r_ok || !r2_ok) {

            જો (!r_ok) {
                જો (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                નહીંતર
                    r = get_reg(rc);
            }

            જો (rc2) {
                પૂર્ણાંક load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                પૂર્ણાંક original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                જો ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } નહીંતર જો (vtop->r & VT_LVAL) {
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
                } નહીંતર {
                    /* move registers */
                    જો (!r_ok)
                        load(r, vtop);
                    જો (r2_ok && vtop->r2 < VT_CONST)
                        જાઓ done;
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
            } નહીંતર {
                જો (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        જો (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    પાછા r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC શૂન્ય gv2(પૂર્ણાંક rc1, પૂર્ણાંક rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    જો (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        જો ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } નહીંતર {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        જો ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#જો PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC શૂન્ય lexpand(શૂન્ય)
{
    પૂર્ણાંક u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    જો (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } નહીંતર જો (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } નહીંતર {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#જો PTR_SIZE == 4
/* build a long long from two ints */
સ્થિર શૂન્ય lbuild(પૂર્ણાંક t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
સ્થિર શૂન્ય gv_dup(શૂન્ય)
{
    પૂર્ણાંક t, rc, r;

    t = vtop->type.t;
#જો PTR_SIZE == 4
    જો ((t & VT_BTYPE) == VT_LLONG) {
        જો (t & VT_BITFIELD) {
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
        પાછા;
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

#જો PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
સ્થિર શૂન્ય gen_opl(પૂર્ણાંક op)
{
    પૂર્ણાંક t, a, b, op1, c, i;
    પૂર્ણાંક func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    પસંદગી(op) {
    સ્થિતિ '/':
    સ્થિતિ TOK_PDIV:
        func = TOK___divdi3;
        જાઓ gen_func;
    સ્થિતિ TOK_UDIV:
        func = TOK___udivdi3;
        જાઓ gen_func;
    સ્થિતિ '%':
        func = TOK___moddi3;
        જાઓ gen_mod_func;
    સ્થિતિ TOK_UMOD:
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
        તોડો;
    સ્થિતિ '^':
    સ્થિતિ '&':
    સ્થિતિ '|':
    સ્થિતિ '*':
    સ્થિતિ '+':
    સ્થિતિ '-':
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
        જો (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            માટે(i=0;i<4;i++)
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
        } નહીંતર જો (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            જો (op == '+')
                op1 = TOK_ADDC1;
            નહીંતર
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } નહીંતર {
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
        તોડો;
    સ્થિતિ TOK_SAR:
    સ્થિતિ TOK_SHR:
    સ્થિતિ TOK_SHL:
        જો ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (પૂર્ણાંક)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            જો (op != TOK_SHL)
                vswap();
            જો (c >= 32) {
                /* stack: L H */
                vpop();
                જો (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                જો (op != TOK_SAR) {
                    vpushi(0);
                } નહીંતર {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } નહીંતર {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                જો (op == TOK_SHL)
                    gen_op(TOK_SHR);
                નહીંતર
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                જો (op == TOK_SHL)
                    gen_op(TOK_SHL);
                નહીંતર
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            જો (op != TOK_SHL)
                vswap();
            lbuild(t);
        } નહીંતર {
            /* XXX: should provide a faster fallback on x86 ? */
            પસંદગી(op) {
            સ્થિતિ TOK_SAR:
                func = TOK___ashrdi3;
                જાઓ gen_func;
            સ્થિતિ TOK_SHR:
                func = TOK___lshrdi3;
                જાઓ gen_func;
            સ્થિતિ TOK_SHL:
                func = TOK___ashldi3;
                જાઓ gen_func;
            }
        }
        તોડો;
    મૂળભૂત:
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
        જો (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        જો (op1 == TOK_LT)
            op1 = TOK_LE;
        નહીંતર જો (op1 == TOK_GT)
            op1 = TOK_GE;
        નહીંતર જો (op1 == TOK_ULT)
            op1 = TOK_ULE;
        નહીંતર જો (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        જો (op == TOK_NE) {
            b = gvtst(0, 0);
        } નહીંતર {
            a = gvtst(1, 0);
            જો (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        જો (op1 == TOK_LT)
            op1 = TOK_ULT;
        નહીંતર જો (op1 == TOK_LE)
            op1 = TOK_ULE;
        નહીંતર જો (op1 == TOK_GT)
            op1 = TOK_UGT;
        નહીંતર જો (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#જો 0//def TCC_TARGET_I386
        જો (op == TOK_NE) { gsym(b); તોડો; }
        જો (op == TOK_EQ) { gsym(a); તોડો; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        તોડો;
    }
}
#endif

/* normalize values */
સ્થિર uint64_t value64(uint64_t l1, પૂર્ણાંક t)
{
    જો ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        પાછા l1;
    નહીંતર જો (t & VT_UNSIGNED)
        પાછા (uint32_t)l1;
    નહીંતર
        પાછા (uint32_t)l1 | -(l1 & 0x80000000);
}

સ્થિર uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    પાછા (a ^ b) >> 63 ? -x : x;
}

સ્થિર પૂર્ણાંક gen_opic_lt(uint64_t a, uint64_t b)
{
    પાછા (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
સ્થિર શૂન્ય gen_opic(પૂર્ણાંક op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    પૂર્ણાંક t1 = v1->type.t & VT_BTYPE;
    પૂર્ણાંક t2 = v2->type.t & VT_BTYPE;
    પૂર્ણાંક c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    પૂર્ણાંક c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    પૂર્ણાંક shm = (t1 == VT_LLONG) ? 63 : 31;
    પૂર્ણાંક r;

    જો (c1 && c2) {
        પસંદગી(op) {
        સ્થિતિ '+': l1 += l2; તોડો;
        સ્થિતિ '-': l1 -= l2; તોડો;
        સ્થિતિ '&': l1 &= l2; તોડો;
        સ્થિતિ '^': l1 ^= l2; તોડો;
        સ્થિતિ '|': l1 |= l2; તોડો;
        સ્થિતિ '*': l1 *= l2; તોડો;

        સ્થિતિ TOK_PDIV:
        સ્થિતિ '/':
        સ્થિતિ '%':
        સ્થિતિ TOK_UDIV:
        સ્થિતિ TOK_UMOD:
            /* if division by zero, generate explicit division */
            જો (l2 == 0) {
                જો (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                જાઓ general_case;
            }
            પસંદગી(op) {
            મૂળભૂત: l1 = gen_opic_sdiv(l1, l2); તોડો;
            સ્થિતિ '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); તોડો;
            સ્થિતિ TOK_UDIV: l1 = l1 / l2; તોડો;
            સ્થિતિ TOK_UMOD: l1 = l1 % l2; તોડો;
            }
            તોડો;
        સ્થિતિ TOK_SHL: l1 <<= (l2 & shm); તોડો;
        સ્થિતિ TOK_SHR: l1 >>= (l2 & shm); તોડો;
        સ્થિતિ TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            તોડો;
            /* tests */
        સ્થિતિ TOK_ULT: l1 = l1 < l2; તોડો;
        સ્થિતિ TOK_UGE: l1 = l1 >= l2; તોડો;
        સ્થિતિ TOK_EQ: l1 = l1 == l2; તોડો;
        સ્થિતિ TOK_NE: l1 = l1 != l2; તોડો;
        સ્થિતિ TOK_ULE: l1 = l1 <= l2; તોડો;
        સ્થિતિ TOK_UGT: l1 = l1 > l2; તોડો;
        સ્થિતિ TOK_LT: l1 = gen_opic_lt(l1, l2); તોડો;
        સ્થિતિ TOK_GE: l1 = !gen_opic_lt(l1, l2); તોડો;
        સ્થિતિ TOK_LE: l1 = !gen_opic_lt(l2, l1); તોડો;
        સ્થિતિ TOK_GT: l1 = gen_opic_lt(l2, l1); તોડો;
            /* logical */
        સ્થિતિ TOK_LAND: l1 = l1 && l2; તોડો;
        સ્થિતિ TOK_LOR: l1 = l1 || l2; તોડો;
        મૂળભૂત:
            જાઓ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } નહીંતર {
        /* if commutative ops, put c2 as constant */
        જો (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        જો (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } નહીંતર જો (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            જો (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } નહીંતર જો (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } નહીંતર જો (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            જો (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                પૂર્ણાંક n = -1;
                જો (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    જાઓ general_case;
                }
                જ્યારે (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                જો (op == '*')
                    op = TOK_SHL;
                નહીંતર જો (op == TOK_PDIV)
                    op = TOK_SAR;
                નહીંતર
                    op = TOK_SHR;
            }
            જાઓ general_case;
        } નહીંતર જો (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            જો (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    જો ((પૂર્ણાંક)l2 != l2)
	        જાઓ general_case;
            vtop--;
            vtop->c.i = l2;
        } નહીંતર {
        general_case:
                /* call low level op generator */
                જો (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                નહીંતર
                    gen_opi(op);
        }
        જો (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#જો defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#અથવાજો defined TCC_TARGET_ARM
શૂન્ય gen_negf(પૂર્ણાંક op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#નહીંતર
/* XXX: implement in gen_opf() for other backends too */
શૂન્ય gen_negf(પૂર્ણાંક op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    પૂર્ણાંક align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#જો defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    જો (bt == VT_LDOUBLE)
        size = 10;
#endif
    જો (nocode_wanted) /* save_reg() wont work */
        જાઓ gv2;
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
સ્થિર શૂન્ય gen_opif(પૂર્ણાંક op)
{
    પૂર્ણાંક c1, c2, i, bt;
    SValue *v1, *v2;
#જો defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    અસ્થિર
#endif
    long દ્વિગુણ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    જો (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    જો (c1 && c2) {
        જો (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } નહીંતર જો (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } નહીંતર {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        જો (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            જાઓ general_case;
        પસંદગી(op) {
        સ્થિતિ '+': f1 += f2; તોડો;
        સ્થિતિ '-': f1 -= f2; તોડો;
        સ્થિતિ '*': f1 *= f2; તોડો;
        સ્થિતિ '/': 
            જો (f2 == 0.0) {
                સંઘ { દશાંશ f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                જો (!CONST_WANTED)
                    જાઓ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                જો (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                નહીંતર
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                તોડો;
            }
            f1 /= f2;
            તોડો;
        સ્થિતિ TOK_NEG:
            f1 = -f1;
            જાઓ unary_result;
        સ્થિતિ TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            પાછા;
        સ્થિતિ TOK_NE:
            i = f1 != f2;
	    જાઓ make_int;
        સ્થિતિ TOK_LT:
            i = f1 < f2;
	    જાઓ make_int;
        સ્થિતિ TOK_GE:
            i = f1 >= f2;
	    જાઓ make_int;
        સ્થિતિ TOK_LE:
            i = f1 <= f2;
	    જાઓ make_int;
        સ્થિતિ TOK_GT:
            i = f1 > f2;
	    જાઓ make_int;
        મૂળભૂત:
            જાઓ general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        જો (bt == VT_FLOAT) {
            v1->c.f = f1;
        } નહીંતર જો (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } નહીંતર {
            v1->c.ld = f1;
        }
    } નહીંતર {
    general_case:
        જો (op == TOK_NEG) {
            gen_negf(op);
        } નહીંતર {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
સ્થિર શૂન્ય type_to_str(અક્ષર *buf, પૂર્ણાંક buf_size,
                 CType *type, અચલ અક્ષર *varstr)
{
    પૂર્ણાંક bt, v, t;
    Sym *s, *sa;
    અક્ષર buf1[256];
    અચલ અક્ષર *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    જો (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    જો (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    જો (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    જો (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    જો (bt != VT_PTR) {
        જો (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        જો (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        જો (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    જો (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    પસંદગી(bt) {
    સ્થિતિ VT_VOID:
        tstr = "void";
        જાઓ add_tstr;
    સ્થિતિ VT_BOOL:
        tstr = "_Bool";
        જાઓ add_tstr;
    સ્થિતિ VT_BYTE:
        tstr = "char";
        જાઓ add_tstr;
    સ્થિતિ VT_SHORT:
        tstr = "short";
        જાઓ add_tstr;
    સ્થિતિ VT_INT:
        tstr = "int";
        જાઓ maybe_long;
    સ્થિતિ VT_LLONG:
        tstr = "long long";
    maybe_long:
        જો (t & VT_LONG)
            tstr = "long";
        જો (!IS_ENUM(t))
            જાઓ add_tstr;
        tstr = "enum ";
        જાઓ tstruct;
    સ્થિતિ VT_FLOAT:
        tstr = "float";
        જાઓ add_tstr;
    સ્થિતિ VT_DOUBLE:
        tstr = "double";
        જો (!(t & VT_LONG))
            જાઓ add_tstr;
    સ્થિતિ VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        તોડો;
    સ્થિતિ VT_STRUCT:
        tstr = "struct ";
        જો (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        જો (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        નહીંતર
            pstrcat(buf, buf_size, get_tok_str(v, ખાલી));
        તોડો;
    સ્થિતિ VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        જો (varstr && '*' == *varstr) {
            pstrcat(buf1, કદ(buf1), "(");
            pstrcat(buf1, કદ(buf1), varstr);
            pstrcat(buf1, કદ(buf1), ")");
        }
        pstrcat(buf1, કદ(buf1), "(");
        sa = s->next;
        જ્યારે (sa != ખાલી) {
            અક્ષર buf2[256];
            type_to_str(buf2, કદ(buf2), &sa->type, ખાલી);
            pstrcat(buf1, કદ(buf1), buf2);
            sa = sa->next;
            જો (sa)
                pstrcat(buf1, કદ(buf1), ", ");
        }
        જો (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, કદ(buf1), ", ...");
        pstrcat(buf1, કદ(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        જાઓ no_var;
    સ્થિતિ VT_PTR:
        s = type->ref;
        જો (t & (VT_ARRAY|VT_VLA)) {
            જો (varstr && '*' == *varstr)
                snprintf(buf1, કદ(buf1), "(%s)[%d]", varstr, s->c);
            નહીંતર
                snprintf(buf1, કદ(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            જાઓ no_var;
        }
        pstrcpy(buf1, કદ(buf1), "*");
        જો (t & VT_RESTRICT)
            pstrcat(buf1, કદ(buf1), "restrict ");
        જો (t & VT_CONSTANT)
            pstrcat(buf1, કદ(buf1), "const ");
        જો (t & VT_VOLATILE)
            pstrcat(buf1, કદ(buf1), "volatile ");
        જો (varstr)
            pstrcat(buf1, કદ(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        જાઓ no_var;
    }
    જો (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

સ્થિર શૂન્ય type_incompatibility_error(CType* st, CType* dt, અચલ અક્ષર* fmt)
{
    અક્ષર buf1[256], buf2[256];
    type_to_str(buf1, કદ(buf1), st, ખાલી);
    type_to_str(buf2, કદ(buf2), dt, ખાલી);
    tcc_error(fmt, buf1, buf2);
}

સ્થિર શૂન્ય type_incompatibility_warning(CType* st, CType* dt, અચલ અક્ષર* fmt)
{
    અક્ષર buf1[256], buf2[256];
    type_to_str(buf1, કદ(buf1), st, ખાલી);
    type_to_str(buf2, કદ(buf2), dt, ખાલી);
    tcc_warning(fmt, buf1, buf2);
}

સ્થિર પૂર્ણાંક pointed_size(CType *type)
{
    પૂર્ણાંક align;
    પાછા type_size(pointed_type(type), &align);
}

સ્થિર અંતઃરેખ પૂર્ણાંક is_null_pointer(SValue *p)
{
    જો ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        પાછા 0;
    પાછા ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
સ્થિર પૂર્ણાંક is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    જો (s1->f.func_call != s2->f.func_call)
        પાછા 0;
    જો (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        પાછા 0;
    માટે (;;) {
        જો (!is_compatible_unqualified_types(&s1->type, &s2->type))
            પાછા 0;
        જો (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            પાછા 1;
        s1 = s1->next;
        s2 = s2->next;
        જો (!s1)
            પાછા !s2;
        જો (!s2)
            પાછા 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
સ્થિર પૂર્ણાંક compare_types(CType *type1, CType *type2, પૂર્ણાંક unqualified)
{
    પૂર્ણાંક bt1, t1, t2;

    જો (IS_ENUM(type1->t)) {
        જો (IS_ENUM(type2->t))
            પાછા type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } નહીંતર જો (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    જો (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    જો ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    જો (t1 != t2)
        પાછા 0;

    જો ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            પાછા 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    જો (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        જો (unqualified && (t1 & VT_ARRAY))
            પાછા compare_types(type1, type2, 1);
        પાછા is_compatible_types(type1, type2);
    } નહીંતર જો (bt1 == VT_STRUCT) {
        પાછા (type1->ref == type2->ref);
    } નહીંતર જો (bt1 == VT_FUNC) {
        પાછા is_compatible_func(type1, type2);
    } નહીંતર {
        પાછા 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
સ્થિર પૂર્ણાંક combine_types(CType *dest, SValue *op1, SValue *op2, પૂર્ણાંક op)
{
    CType *type1, *type2, type;
    પૂર્ણાંક t1, t2, bt1, bt2;
    પૂર્ણાંક ret = 1;

    /* for shifts, 'combine' only left operand */
    જો (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ખાલી;

    જો (bt1 == VT_VOID || bt2 == VT_VOID) {
        જો (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } નહીંતર જો (bt1 == VT_PTR || bt2 == VT_PTR) {
        જો (op == '+') {
          જો (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        નહીંતર જો (is_null_pointer (op2)) type = *type1;
        નહીંતર જો (is_null_pointer (op1)) type = *type2;
        નહીંતર જો (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            જો ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            નહીંતર જો (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } નહીંતર {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            પૂર્ણાંક pbt1 = pt1->t & VT_BTYPE;
            પૂર્ણાંક pbt2 = pt2->t & VT_BTYPE;
            પૂર્ણાંક newquals, copied = 0;
            જો (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                જો (op != '?' && op != CMP_OP)
                  ret = 0;
                નહીંતર
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            જો (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                જો ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ધકેલો(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                જો (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    જો (!copied)
                      type.ref = sym_ધકેલો(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ધકેલો(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        જો (op == CMP_OP)
          type.t = VT_SIZE_T;
    } નહીંતર જો (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        જો (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } નહીંતર જો (is_float(bt1) || is_float(bt2)) {
        જો (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } નહીંતર જો (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } નહીંતર {
            type.t = VT_FLOAT;
        }
    } નહીંતર જો (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        જો (bt1 == VT_LLONG)
          type.t &= t1;
        જો (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        જો ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } નહીંતર {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        જો (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    જો (dest)
      *dest = type;
    પાછા ret;
}

/* generic gen_op: handles types problems */
ST_FUNC શૂન્ય gen_op(પૂર્ણાંક op)
{
    પૂર્ણાંક t1, t2, bt1, bt2, t;
    CType type1, combtype;
    પૂર્ણાંક op_class = op;

    જો (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    નહીંતર જો (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    જો (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	જો (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	જો (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	જાઓ redo;
    } નહીંતર જો (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } નહીંતર જો (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        પૂર્ણાંક align;
        જો (op_class == CMP_OP)
            જાઓ std_op;
        /* if both pointers, then it must be the '-' op */
        જો (bt1 == VT_PTR && bt2 == VT_PTR) {
            જો (op != '-')
                જાઓ op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } નહીંતર {
            /* exactly one pointer : must be '+' or '-'. */
            જો (op != '-' && op != '+')
                જાઓ op_err;
            /* Put pointer as first operand */
            જો (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#જો PTR_SIZE == 4
            જો (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            જો (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                જો (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } નહીંતર
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } નહીંતર {
        /* floats can only be used for a few operations */
        જો (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            જાઓ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        જો (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        જો (t & VT_UNSIGNED) {
            જો (op == TOK_SAR)
                op = TOK_SHR;
            નહીંતર જો (op == '/')
                op = TOK_UDIV;
            નહીંતર જો (op == '%')
                op = TOK_UMOD;
            નહીંતર જો (op == TOK_LT)
                op = TOK_ULT;
            નહીંતર જો (op == TOK_GT)
                op = TOK_UGT;
            નહીંતર જો (op == TOK_LE)
                op = TOK_ULE;
            નહીંતર જો (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        જો (is_float(t))
            gen_opif(op);
        નહીંતર
            gen_opic(op);
        જો (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } નહીંતર {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    જો (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#જો defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#નહીંતર
/* generic itof for unsigned long long case */
સ્થિર શૂન્ય gen_cvt_itof1(પૂર્ણાંક t)
{
    જો ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        જો (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#જો LDOUBLE_SIZE != 8
        નહીંતર જો (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        નહીંતર
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } નહીંતર {
        gen_cvt_itof(t);
    }
}
#endif

#જો defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#નહીંતર
/* generic ftoi for unsigned long long case */
સ્થિર શૂન્ય gen_cvt_ftoi1(પૂર્ણાંક t)
{
    પૂર્ણાંક st;
    જો (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        જો (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#જો LDOUBLE_SIZE != 8
        નહીંતર જો (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        નહીંતર
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } નહીંતર {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
સ્થિર શૂન્ય force_charshort_cast(શૂન્ય)
{
    પૂર્ણાંક sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    પૂર્ણાંક dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

સ્થિર શૂન્ય gen_cast_s(પૂર્ણાંક t)
{
    CType type;
    type.t = t;
    type.ref = ખાલી;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
સ્થિર શૂન્ય gen_cast(CType *type)
{
    પૂર્ણાંક sbt, dbt, sf, df, c;
    પૂર્ણાંક dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    જો (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    જો (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    જો (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    જો (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    જો (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        જો (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            જાઓ done;
        }
        જો (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        જો (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            જો (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            નહીંતર જો (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            જો (df) {
                જો (sbt_bt == VT_LLONG) {
                    જો ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    નહીંતર
                        vtop->c.ld = -(long દ્વિગુણ)-vtop->c.i;
                } નહીંતર જો(!sf) {
                    જો ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    નહીંતર
                        vtop->c.ld = -(long દ્વિગુણ)-(uint32_t)vtop->c.i;
                }

                જો (dbt == VT_FLOAT)
                    vtop->c.f = (દશાંશ)vtop->c.ld;
                નહીંતર જો (dbt == VT_DOUBLE)
                    vtop->c.d = (દ્વિગુણ)vtop->c.ld;
            } નહીંતર જો (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } નહીંતર {
                જો(sf) {
                    જો (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    નહીંતર
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                નહીંતર જો (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                નહીંતર જો (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                નહીંતર
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                જો (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                નહીંતર જો (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                નહીંતર {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    જો (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            જાઓ done;

        } નહીંતર જો (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            જાઓ done;
        }

        /* cannot generate code for global or static initializers */
        જો (nocode_wanted & DATA_ONLY_WANTED) {
            જો (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            જાઓ done;
        }

        /* non constant case: generate code */
        જો (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            જાઓ done;
        }

        જો (sf || df) {
            જો (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } નહીંતર જો (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } નહીંતર {
                /* convert fp to int */
                sbt = dbt;
                જો (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                જાઓ again; /* may need char/short cast */
            }
            જાઓ done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        જો (ds == 0 || ss == 0)
            જાઓ error;

        /* same size and no sign conversion needed */
        જો (ds == ss && ds >= 4)
            જાઓ done;
        જો (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            જો (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        જો (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            જો (ds <= ss)
                જાઓ done;
            /* ss <= 4 here */
            જો (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                જાઓ done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#જો PTR_SIZE == 4
        જો (ds == 8) {
            /* generate high word */
            જો (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } નહીંતર {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } નહીંતર જો (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#અથવાજો PTR_SIZE == 8
        જો (ds == 8) {
            /* need to convert from 32bit to 64bit */
            જો (sbt & VT_UNSIGNED) {
#જો defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#નહીંતર
                જાઓ done;
#endif
            } નહીંતર {
                gen_cvt_sxtw();
                જાઓ done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } નહીંતર જો (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#જો !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } નહીંતર {
            ss = 4;
        }
#endif

        જો (ds >= ss)
            જાઓ done;
#જો defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    જો (ss == 4) {
        gen_cvt_csti(dbt);
        જાઓ done;
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
ST_FUNC પૂર્ણાંક type_size(CType *type, પૂર્ણાંક *a)
{
    Sym *s;
    પૂર્ણાંક bt;

    bt = type->t & VT_BTYPE;
    જો (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        પાછા s->c;
    } નહીંતર જો (bt == VT_PTR) {
        જો (type->t & VT_ARRAY) {
            પૂર્ણાંક ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            જો (s->c < 0)
                પાછા s->c;
            પાછા ts * s->c;
        } નહીંતર {
            *a = PTR_SIZE;
            પાછા PTR_SIZE;
        }
    } નહીંતર જો (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        પાછા -1; /* incomplete enum */
    } નહીંતર જો (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        પાછા LDOUBLE_SIZE;
    } નહીંતર જો (bt == VT_DOUBLE || bt == VT_LLONG) {
#જો (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#નહીંતર
        *a = 8;
#endif
        પાછા 8;
    } નહીંતર જો (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        પાછા 4;
    } નહીંતર જો (bt == VT_SHORT) {
        *a = 2;
        પાછા 2;
    } નહીંતર જો (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        પાછા 16;
    } નહીંતર {
        /* char, void, function, _Bool */
        *a = 1;
        પાછા 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
સ્થિર શૂન્ય vpush_type_size(CType *type, પૂર્ણાંક *a)
{
    જો (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } નહીંતર {
        પૂર્ણાંક size = type_size(type, a);
        જો (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
સ્થિર અંતઃરેખ CType *pointed_type(CType *type)
{
    પાછા &type->ref->type;
}

સ્થિર શૂન્ય check_restrict_type(CType *type)
{
    જ્યારે ((type->t & VT_BTYPE) == VT_PTR) {
        જો ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    જો (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
સ્થિર પૂર્ણાંક type_qualifiers(CType *type)
{
    જ્યારે (type->t & VT_ARRAY)
        type = pointed_type(type);
    પાછા type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC શૂન્ય mk_pointer(CType *type)
{
    Sym *s;
    s = sym_ધકેલો(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
સ્થિર પૂર્ણાંક is_compatible_types(CType *type1, CType *type2)
{
    પાછા compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
સ્થિર પૂર્ણાંક is_compatible_unqualified_types(CType *type1, CType *type2)
{
    પાછા compare_types(type1,type2,1);
}

સ્થિર શૂન્ય cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
સ્થિર શૂન્ય verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    પૂર્ણાંક dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    જો (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    પસંદગી(dbt) {
    સ્થિતિ VT_VOID:
        જો (sbt != dbt)
            tcc_error("assignment to void expression");
        તોડો;
    સ્થિતિ VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        જો (is_null_pointer(vtop))
            તોડો;
        /* accept implicit pointer to integer cast with warning */
        જો (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            તોડો;
        }
        type1 = pointed_type(dt);
        જો (sbt == VT_PTR)
            type2 = pointed_type(st);
        નહીંતર જો (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        નહીંતર
            જાઓ error;
        જો (is_compatible_types(type1, type2))
            તોડો;
        માટે (qualwarn = lvl = 0;; ++lvl) {
            જો ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            જો (dbt != VT_PTR || sbt != VT_PTR)
                તોડો;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        જો (!is_compatible_unqualified_types(type1, type2)) {
            જો ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } નહીંતર જો (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } નહીંતર {
                tcc_warning("assignment from incompatible pointer type");
                તોડો;
            }
        }
        જો (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        તોડો;
    સ્થિતિ VT_BYTE:
    સ્થિતિ VT_SHORT:
    સ્થિતિ VT_INT:
    સ્થિતિ VT_LLONG:
        જો (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } નહીંતર જો (sbt == VT_STRUCT) {
            જાઓ case_VT_STRUCT;
        }
        /* XXX: more tests */
        તોડો;
    સ્થિતિ VT_STRUCT:
    case_VT_STRUCT:
        જો (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        તોડો;
    }
}

સ્થિર શૂન્ય gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC શૂન્ય vstore(શૂન્ય)
{
    પૂર્ણાંક sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    જો (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        જો (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        જો (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        જો (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } નહીંતર
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            જો(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            નહીંતર જો(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            નહીંતર
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } નહીંતર જો (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        જો (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        જો (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        જો (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } નહીંતર {
            unsigned long long mask = (1ULL << bit_size) - 1;
            જો (dbt != VT_BOOL) {
                /* mask source */
                જો (dbt == VT_LLONG)
                    vpushll(mask);
                નહીંતર
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
            જો (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            નહીંતર
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } નહીંતર જો (dbt == VT_VOID) {
        --vtop;
    } નહીંતર {
            /* optimize char/short casts */
            delayed_cast = 0;
            જો ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                જો ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } નહીંતર {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            જો (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            જો (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            જો ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ખાલી;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            જો (USING_TWO_શબ્દો(dbt)) {
                પૂર્ણાંક load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } નહીંતર {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC શૂન્ય inc(પૂર્ણાંક post, પૂર્ણાંક c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    જો (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    જો (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (અચલ અક્ષર *સંદેશ)
{
    /* read the string */
    જો (tok != TOK_STR)
        expect(સંદેશ);
    cstr_reset(&initstr);
    જ્યારે (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    પાછા &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC પૂર્ણાંક exact_log2p1(પૂર્ણાંક i)
{
  પૂર્ણાંક ret;
  જો (!i)
    પાછા 0;
  માટે (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  જો (i >= 1 << 4)
    ret += 4, i >>= 4;
  જો (i >= 1 << 2)
    ret += 2, i >>= 2;
  જો (i >= 1 << 1)
    ret++;
  પાછા ret;
}

/* Parse __attribute__((...)) GNUC extension. */
સ્થિર શૂન્ય parse_attribute(AttributeDef *ad)
{
    પૂર્ણાંક t, n;
    અક્ષર *astr;
    AttributeDef ad_tmp;
    
redo:
    જો (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        પાછા;
    જો (ખાલી == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    જ્યારે (tok != ')') {
        જો (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        પસંદગી(t) {
	સ્થિતિ TOK_CLEANUP1:
	સ્થિતિ TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    જો (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } નહીંતર જો ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    તોડો;
	}
        સ્થિતિ TOK_CONSTRUCTOR1:
        સ્થિતિ TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            તોડો;
        સ્થિતિ TOK_DESTRUCTOR1:
        સ્થિતિ TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            તોડો;
        સ્થિતિ TOK_ALWAYS_INLINE1:
        સ્થિતિ TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            તોડો;
        સ્થિતિ TOK_SECTION1:
        સ્થિતિ TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            તોડો;
        સ્થિતિ TOK_ALIAS1:
        સ્થિતિ TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            તોડો;
	સ્થિતિ TOK_VISIBILITY1:
	સ્થિતિ TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    જો (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    નહીંતર જો (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    નહીંતર જો (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    નહીંતર જો (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    નહીંતર
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            તોડો;
        સ્થિતિ TOK_ALIGNED1:
        સ્થિતિ TOK_ALIGNED2:
            જો (tok == '(') {
                next();
                n = પદાવલિ_const();
                જો (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } નહીંતર {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    જો (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            તોડો;
        સ્થિતિ TOK_PACKED1:
        સ્થિતિ TOK_PACKED2:
            ad->a.packed = 1;
            તોડો;
        સ્થિતિ TOK_WEAK1:
        સ્થિતિ TOK_WEAK2:
            ad->a.weak = 1;
            તોડો;
        સ્થિતિ TOK_NODEBUG1:
        સ્થિતિ TOK_NODEBUG2:
            ad->a.nodebug = 1;
            તોડો;
        સ્થિતિ TOK_USED1:
        સ્થિતિ TOK_USED2:
        સ્થિતિ TOK_UNUSED1:
        સ્થિતિ TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            તોડો;
        સ્થિતિ TOK_CONST1:
        સ્થિતિ TOK_CONST2:
        સ્થિતિ TOK_CONST3:
        સ્થિતિ TOK_PURE1:
        સ્થિતિ TOK_PURE2:
	    /* ignored */
            તોડો;
        સ્થિતિ TOK_NOINLINE:
	    /* ignored */
	    તોડો;
        સ્થિતિ TOK_FORMAT1:
        સ્થિતિ TOK_FORMAT2:
	    /* ignored */
            જાઓ skip_param;
        સ્થિતિ TOK_NORETURN1:
        સ્થિતિ TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            તોડો;
        સ્થિતિ TOK_CDECL1:
        સ્થિતિ TOK_CDECL2:
        સ્થિતિ TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            તોડો;
        સ્થિતિ TOK_STDCALL1:
        સ્થિતિ TOK_STDCALL2:
        સ્થિતિ TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            તોડો;
#ifdef TCC_TARGET_I386
        સ્થિતિ TOK_REGPARM1:
        સ્થિતિ TOK_REGPARM2:
            skip('(');
            n = પદાવલિ_const();
            જો (n > 3) 
                n = 3;
            નહીંતર જો (n < 0)
                n = 0;
            જો (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            તોડો;
        સ્થિતિ TOK_FASTCALL1:
        સ્થિતિ TOK_FASTCALL2:
        સ્થિતિ TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            તોડો;
        સ્થિતિ TOK_THISCALL1:
        સ્થિતિ TOK_THISCALL2:
        સ્થિતિ TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            તોડો;
#endif
        સ્થિતિ TOK_MODE:
            skip('(');
            પસંદગી(tok) {
                સ્થિતિ TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    તોડો;
                સ્થિતિ TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    તોડો;
                સ્થિતિ TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    તોડો;
                સ્થિતિ TOK_MODE_SI:
                સ્થિતિ TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    તોડો;
                મૂળભૂત:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ખાલી));
                    તોડો;
            }
            next();
            skip(')');
            તોડો;
        સ્થિતિ TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            તોડો;
        સ્થિતિ TOK_NODECORATE:
            ad->a.nodecorate = 1;
            તોડો;
        સ્થિતિ TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            તોડો;
        મૂળભૂત:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ખાલી));
            /* skip parameters */
skip_param:
            જો (tok == '(') {
                પૂર્ણાંક parenthesis = 0;
                કરો {
                    જો (tok == '(') 
                        parenthesis++;
                    નહીંતર જો (tok == ')') 
                        parenthesis--;
                    next();
                } જ્યારે (parenthesis && tok != -1);
            }
            તોડો;
        }
        જો (tok != ',')
            તોડો;
        next();
    }
    skip(')');
    skip(')');
    જાઓ redo;
}

સ્થિર Sym * find_field (CType *type, પૂર્ણાંક v, પૂર્ણાંક *cumofs)
{
    Sym *s = type->ref;
    પૂર્ણાંક v1 = v | SYM_FIELD;
    જો (!(v & SYM_FIELD)) { /* top-level call */
        જો ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        જો (v < TOK_UIDENT)
            expect("field name");
        જો (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    જ્યારે ((s = s->next) != ખાલી) {
        જો (s->v == v1) {
            *cumofs = s->c;
            પાછા s;
        }
        જો ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            જો (ret) {
                *cumofs += s->c;
                પાછા ret;
            }
        }
    }
    જો (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, ખાલી));
    પાછા s;
}

સ્થિર શૂન્ય check_fields (CType *type, પૂર્ણાંક check)
{
    Sym *s = type->ref;

    જ્યારે ((s = s->next) != ખાલી) {
        પૂર્ણાંક v = s->v & ~SYM_FIELD;
        જો (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            જો (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, ખાલી));
            ts->tok ^= SYM_FIELD;
        } નહીંતર જો ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

સ્થિર શૂન્ય struct_layout(CType *type, AttributeDef *ad)
{
    પૂર્ણાંક size, align, maxalign, offset, c, bit_pos, bit_size;
    પૂર્ણાંક packed, a, bt, prevbt, prev_bit_size;
    પૂર્ણાંક pcc = !tcc_state->ms_bitfields;
    પૂર્ણાંક pragma_pack = *tcc_state->pack_ઢગલો_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    માટે (f = type->ref->next; f; f = f->next) {
        જો (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        નહીંતર
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        જો (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } નહીંતર {
            /* in pcc mode, attribute packed overrides if set. */
            જો (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            જો (pragma_pack) {
                packed = 1;
                જો (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                જો (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        જો (a)
            align = a;

        જો (type->ref->type.t == VT_UNION) {
	    જો (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    જો (size > c)
	        c = size;

	} નહીંતર જો (bit_size < 0) {
            જો (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    જો (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} નહીંતર {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            જો (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                જો (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } નહીંતર જો (f->a.aligned) {
                    જાઓ new_field;
                } નહીંતર જો (!packed) {
                    પૂર્ણાંક a8 = align * 8;
	            પૂર્ણાંક ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    જો (ofs > size / align)
                        જાઓ new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                જો (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                જ્યારે (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		જો (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } નહીંતર {
		bt = f->type.t & VT_BTYPE;
		જો ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    જો (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		જો (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	જો (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, ખાલી), offset, size, align);
	જો (f->type.t & VT_BITFIELD) {
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

    જો (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    જો (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    જો (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        જો (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    માટે (f = type->ref->next; f; f = f->next) {
        પૂર્ણાંક s, px, cx, c0;
        CType t;

        જો (0 == (f->type.t & VT_BITFIELD))
            ચાલુ;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        જો (bit_size == 0)
            ચાલુ;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        જો (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            ચાલુ;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        માટે (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            જો (c0 == cx)
                તોડો;
            s = (px + bit_size + 7) >> 3;
            જો (s > 4) {
                t.t = VT_LLONG;
            } નહીંતર જો (s > 2) {
                t.t = VT_INT;
            } નહીંતર જો (s > 1) {
                t.t = VT_SHORT;
            } નહીંતર {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        જો (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            જો (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, ખાલી),
                cx, s, align, px, bit_size);
#endif
        } નહીંતર {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, ખાલી));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
સ્થિર પૂર્ણાંક in_range(long long n, પૂર્ણાંક t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    જો (t & VT_UNSIGNED)
        પાછા n <= (m << 1) + 1;
    પાછા n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
સ્થિર શૂન્ય struct_decl(CType *type, પૂર્ણાંક u)
{
    પૂર્ણાંક v, c, size, align, flexible;
    પૂર્ણાંક bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, કદ ad);
    next();
    parse_attribute(&ad);

    v = 0;
    જો (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    જો (u == VT_ENUM) {
        ut = VT_INT;
        જો (tok == ':') { /* C2x enum : <type> ... */
            next();
            જો (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    જો (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        જો (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            જો (u == s->type.t)
                જાઓ do_decl;
            જો (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                જાઓ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ખાલી));
        }
    } નહીંતર {
        જો (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ખાલી;
    /* we put an undefined size for struct/union */
    s = sym_ધકેલો(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    જો (tok == '{') {
        next();
        જો (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        જો (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            જો (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            માટે(;;) {
                v = tok;
                જો (v < TOK_UIDENT)
                    expect("identifier");
                next();
                જો (tok == '=') {
                    next();
		    ll = પદાવલિ_const64();
                }
                જો (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ખાલી));
                ss = sym_ધકેલો(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                જો (ll < nl)
                    nl = ll;
                જો (ll > pl)
                    pl = ll;
                જો (tok != ',')
                    તોડો;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                જો (tok == '}')
                    તોડો;
            }
            skip('}');

            જો (bt) {
                t.t = bt;
                s->c = 2;
                જાઓ enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            જો (nl >= 0) {
                જો (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } નહીંતર જો (pl != (પૂર્ણાંક)pl || nl != (પૂર્ણાંક)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            માટે (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                જો (ll == (પૂર્ણાંક)ll) /* default is int if it fits */
                    ચાલુ;
                જો (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    જો (ll == (unsigned)ll)
                        ચાલુ;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } નહીંતર {
            c = 0;
            flexible = 0;
            જ્યારે (tok != '}') {
                જો (!parse_btype(&btype, &ad1, 0)) {
                    જો (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        ચાલુ;
                    }
		    skip(';');
		    ચાલુ;
		}
                જ્યારે (1) {
		    જો (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ખાલી));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    જો (tok != ':') {
			જો (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        જો (v == 0) {
                    	    જો ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    નહીંતર {
				પૂર્ણાંક v = btype.ref->v;
				જો ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    જો (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        જો (type_size(&type1, &align) < 0) {
			    જો ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    નહીંતર
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ખાલી));
                        }
                        જો ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ખાલી));
                    }
                    જો (tok == ':') {
                        next();
                        bit_size = પદાવલિ_const();
                        /* XXX: handle v = 0 case for messages */
                        જો (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ખાલી));
                        જો (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ખાલી));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    જો (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        જો (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        જો (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ખાલી));
                        } નહીંતર જો (bit_size == bsize
				    && !*tcc_state->pack_ઢગલો_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } નહીંતર જો (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } નહીંતર {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    જો (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    જો (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    જો (v) {
                        ss = sym_ધકેલો(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    જો (tok == ';' || tok == TOK_EOF)
                        તોડો;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            જો (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        જો (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

સ્થિર શૂન્ય sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
સ્થિર શૂન્ય parse_btype_qualify(CType *type, પૂર્ણાંક qualifiers)
{
    જ્યારે (type->t & VT_ARRAY) {
        type->ref = sym_ધકેલો(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    જો (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
સ્થિર પૂર્ણાંક parse_btype(CType *type, AttributeDef *ad, પૂર્ણાંક ignore_label)
{
    પૂર્ણાંક t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, કદ(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ખાલી;

    જ્યારે(1) {
        પસંદગી(tok) {
        સ્થિતિ TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            ચાલુ;

            /* basic types */
        સ્થિતિ TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            જો (u == VT_SHORT || u == VT_LONG) {
                જો (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } નહીંતર {
                જો (bt != -1 || (st != -1 && u != VT_INT))
                    જાઓ tmbt;
                જો ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    જાઓ tmbt;
                bt = u;
            }
            જો (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            તોડો;
        સ્થિતિ TOK_VOID:
            u = VT_VOID;
            જાઓ basic_type;
        સ્થિતિ TOK_SHORT:
            u = VT_SHORT;
            જાઓ basic_type;
        સ્થિતિ TOK_INT:
            u = VT_INT;
            જાઓ basic_type;
        સ્થિતિ TOK_ALIGNAS:
            { પૂર્ણાંક n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, કદ(AttributeDef));
              જો (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  જો (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  નહીંતર
                    type_size(&type1, &n);
              } નહીંતર {
                  n = પદાવલિ_const();
                  જો (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            ચાલુ;
        સ્થિતિ TOK_LONG:
            જો ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } નહીંતર જો ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } નહીંતર {
                u = VT_LONG;
                જાઓ basic_type;
            }
            next();
            તોડો;
        સ્થિતિ TOK_BOOL:
            u = VT_BOOL;
            જાઓ basic_type;
        સ્થિતિ TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        સ્થિતિ TOK_FLOAT:
            u = VT_FLOAT;
            જાઓ basic_type;
        સ્થિતિ TOK_DOUBLE:
            જો ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } નહીંતર {
                u = VT_DOUBLE;
                જાઓ basic_type;
            }
            next();
            તોડો;
        સ્થિતિ TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            જાઓ basic_type1;
        સ્થિતિ TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            જાઓ basic_type2;
        સ્થિતિ TOK_UNION:
            struct_decl(&type1, VT_UNION);
            જાઓ basic_type2;

            /* type modifiers */
        સ્થિતિ TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            જો (tok == '(') {
                parse_પદાવલિ_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                જો (type1.ref)
                    sym_to_attr(ad, type1.ref);
                જાઓ basic_type2;
            }
            તોડો;
        સ્થિતિ TOK_CONST1:
        સ્થિતિ TOK_CONST2:
        સ્થિતિ TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            તોડો;
        સ્થિતિ TOK_VOLATILE1:
        સ્થિતિ TOK_VOLATILE2:
        સ્થિતિ TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            તોડો;
        સ્થિતિ TOK_SIGNED1:
        સ્થિતિ TOK_SIGNED2:
        સ્થિતિ TOK_SIGNED3:
            જો ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            તોડો;
        સ્થિતિ TOK_RESTRICT1:
        સ્થિતિ TOK_RESTRICT2:
        સ્થિતિ TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            તોડો;
        સ્થિતિ TOK_REGISTER:
        સ્થિતિ TOK_AUTO:
            next();
            તોડો;
        સ્થિતિ TOK_UNSIGNED:
            જો ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            તોડો;

            /* storage */
        સ્થિતિ TOK_EXTERN:
            g = VT_EXTERN;
            જાઓ storage;
        સ્થિતિ TOK_STATIC:
            g = VT_STATIC;
            જાઓ storage;
        સ્થિતિ TOK_TYPEDEF:
            g = VT_TYPEDEF;
            જાઓ storage;
       storage:
            જો (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            તોડો;
        સ્થિતિ TOK_INLINE1:
        સ્થિતિ TOK_INLINE2:
        સ્થિતિ TOK_INLINE3:
            t |= VT_INLINE;
            next();
            તોડો;
        સ્થિતિ TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            તોડો;
            /* GNUC attribute */
        સ્થિતિ TOK_ATTRIBUTE1:
        સ્થિતિ TOK_ATTRIBUTE2:
            parse_attribute(ad);
            જો (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            ચાલુ;
            /* GNUC typeof */
        સ્થિતિ TOK_TYPEOF1:
        સ્થિતિ TOK_TYPEOF2:
        સ્થિતિ TOK_TYPEOF3:
            next();
            parse_પદાવલિ_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            જો (type1.ref) {
                sym_to_attr(ad, type1.ref);
                જો (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            જાઓ basic_type2;
        સ્થિતિ TOK_THREAD_LOCAL:
        સ્થિતિ TOK___thread:
            જો (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            તોડો;
        મૂળભૂત:
            જો (typespec_found)
                જાઓ the_end;
            s = sym_find(tok);
            જો (!s || !(s->type.t & VT_TYPEDEF))
                જાઓ the_end;

            n = tok, next();
            જો (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                જાઓ the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            જો (t)
                parse_btype_qualify(type, t);
            t = type->t;
            જો (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            તોડો;
        }
        type_found = 1;
    }
the_end:
    જો (tcc_state->char_is_unsigned) {
        જો ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    જો (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    જો (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    પાછા type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
સ્થિર અંતઃરેખ શૂન્ય convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    જો ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
સ્થિર અંતઃરેખ શૂન્ય convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(શૂન્ય)
{
    skip('(');
    પાછા parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
સ્થિર પૂર્ણાંક asm_label_instr(શૂન્ય)
{
    પૂર્ણાંક v;
    અક્ષર *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    પાછા v;
}

સ્થિર પૂર્ણાંક post_type(CType *type, AttributeDef *ad, પૂર્ણાંક storage, પૂર્ણાંક td)
{
    પૂર્ણાંક n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ખાલી;
    પૂર્ણાંક *vla_array_str = ખાલી;

    જો (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	જો (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  પાછા 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ઢગલો ? &local_ઢગલો : &global_ઢગલો;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	જો (tok == ')')
	  l = 0;
	નહીંતર જો (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	નહીંતર જો (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_કાઢો(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    પાછા 0;
	} નહીંતર
	  l = FUNC_OLD;

        first = ખાલી;
        plast = &first;
        arg_size = 0;
        જો (l) {
            માટે(;;) {
                /* read param name and compute offset */
                જો (l != FUNC_OLD) {
                    જો ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        તોડો;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    જો ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    જો (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } નહીંતર {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ખાલી;
                    next();
                }
                જો (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ધકેલો(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                જો (tok == ')')
                    તોડો;
                skip(',');
                જો (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    તોડો;
                }
		જો (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } નહીંતર
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        જો (tok == '[') {
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
        sym_કાઢો(ps, sr, 1);
        --local_scope;

    } નહીંતર જો (tok == '[') {
	પૂર્ણાંક saved_nocode_wanted = nocode_wanted;
        પૂર્ણાંક array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        જો (td & TYPE_PARAM) જ્યારે (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    પસંદગી (tok) {
	    સ્થિતિ TOK_CONST1: સ્થિતિ TOK_CONST2: સ્થિતિ TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		ચાલુ;
	    સ્થિતિ TOK_VOLATILE1: સ્થિતિ TOK_VOLATILE2: સ્થિતિ TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		ચાલુ;
	    સ્થિતિ TOK_RESTRICT1: સ્થિતિ TOK_RESTRICT2: સ્થિતિ TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		ચાલુ;
	    સ્થિતિ TOK_STATIC:
	    સ્થિતિ '*':
		next();
		ચાલુ;
	    મૂળભૂત:
		તોડો;
	    }
            જો (tok != ']') {
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
		જાઓ check;
            }
            તોડો;

	} નહીંતર જો (tok != ']') {
            જો (!local_ઢગલો || (storage & VT_STATIC))
                vpushi(પદાવલિ_const());
            નહીંતર {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            જો ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                જો (n < 0)
                    tcc_error("invalid array size");
            } નહીંતર {
                જો (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        જો ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        જો ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        જો (t1 & VT_VLA) {
            જો (n < 0) {
		જો  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    નહીંતર {
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
        જો (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ધકેલો(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        જો (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    જો ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    નહીંતર
	        tok_str_free_str(vla_array_str);
	}
    }
    પાછા 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
સ્થિર CType *type_decl(CType *type, AttributeDef *ad, પૂર્ણાંક *v, પૂર્ણાંક td)
{
    CType *post, *ret;
    પૂર્ણાંક qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    જ્યારે (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        પસંદગી(tok) {
        સ્થિતિ TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            જાઓ redo;
        સ્થિતિ TOK_CONST1:
        સ્થિતિ TOK_CONST2:
        સ્થિતિ TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            જાઓ redo;
        સ્થિતિ TOK_VOLATILE1:
        સ્થિતિ TOK_VOLATILE2:
        સ્થિતિ TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            જાઓ redo;
        સ્થિતિ TOK_RESTRICT1:
        સ્થિતિ TOK_RESTRICT2:
        સ્થિતિ TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            જાઓ redo;
	/* XXX: clarify attribute handling */
	સ્થિતિ TOK_ATTRIBUTE1:
	સ્થિતિ TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    તોડો;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	જો (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    જો (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	જો (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} નહીંતર
	  જાઓ abstract;
    } નહીંતર જો (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } નહીંતર {
  abstract:
	જો (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    પાછા ret;
}

/* indirection with full error checking and bound check */
ST_FUNC શૂન્ય indir(શૂન્ય)
{
    જો ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        જો ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            પાછા;
        expect("pointer");
    }
    જો (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    જો (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        જો (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
સ્થિર શૂન્ય gfunc_param_typed(Sym *func, Sym *arg)
{
    પૂર્ણાંક func_type;
    CType type;

    func_type = func->f.func_type;
    જો (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ખાલી)) {
        /* default casting : only need to convert float to double */
        જો ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } નહીંતર જો (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } નહીંતર જો (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } નહીંતર જો (arg == ખાલી) {
        tcc_error("too many arguments to function");
    } નહીંતર {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
સ્થિર શૂન્ય પદાવલિ_type(CType *type, શૂન્ય (*પદાવલિ_fn)(શૂન્ય))
{
    nocode_wanted++;
    પદાવલિ_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
સ્થિર શૂન્ય parse_પદાવલિ_type(CType *type)
{
    પૂર્ણાંક n;
    AttributeDef ad;

    skip('(');
    જો (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } નહીંતર {
        પદાવલિ_type(type, gexpr);
    }
    skip(')');
}

સ્થિર શૂન્ય parse_type(CType *type)
{
    AttributeDef ad;
    પૂર્ણાંક n;

    જો (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

સ્થિર શૂન્ય parse_builtin_params(પૂર્ણાંક nc, અચલ અક્ષર *args)
{
    અક્ષર c, sep = '(';
    CType type;
    જો (nc)
        nocode_wanted++;
    next();
    જો (*args == 0)
	skip(sep);
    જ્યારે ((c = *args++)) {
	skip(sep);
	sep = ',';
        જો (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    ચાલુ;
        }
        પદાવલિ_eq();
        type.ref = ખાલી;
        type.t = 0;
	પસંદગી (c) {
	    સ્થિતિ 'e':
		ચાલુ;
	    સ્થિતિ 'V':
                type.t = VT_CONSTANT;
	    સ્થિતિ 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                તોડો;
	    સ્થિતિ 'S':
                type.t = VT_CONSTANT;
	    સ્થિતિ 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                તોડો;
	    સ્થિતિ 'i':
                type.t = VT_INT;
                તોડો;
	    સ્થિતિ 'l':
                type.t = VT_SIZE_T;
                તોડો;
	    મૂળભૂત:
                તોડો;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    જો (nc)
        nocode_wanted--;
}

સ્થિર શૂન્ય parse_atomic(પૂર્ણાંક atok)
{
    પૂર્ણાંક size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    અક્ષર buf[40];
    સ્થિર અચલ અક્ષર *અચલ templates[] = {
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
    અચલ અક્ષર *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ખાલી;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    માટે (arg = 0;;) {
        પદાવલિ_eq();
        પસંદગી (template[arg]) {
        સ્થિતિ 'a':
        સ્થિતિ 'A':
            atom_ptr = &vtop->type;
            જો ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            જો (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            તોડો;

        સ્થિતિ 'p':
            જો ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            તોડો;
        સ્થિતિ 'v':
            gen_assign_cast(atom);
            તોડો;
        સ્થિતિ 'l':
            indir();
            gen_assign_cast(atom);
            તોડો;
        સ્થિતિ 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            તોડો;
        સ્થિતિ 'm':
            gen_assign_cast(&int_type);
            તોડો;
        સ્થિતિ 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            તોડો;
        }
        જો ('.' == template[++arg])
            તોડો;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    પસંદગી (template[arg + 1]) {
    સ્થિતિ 'b':
        ct.t = VT_BOOL;
        તોડો;
    સ્થિતિ 'v':
        ct = *atom;
        તોડો;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    જો (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#નહીંતર
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    જો (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC શૂન્ય unary(શૂન્ય)
{
    પૂર્ણાંક n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    જો (debug_modes)
        tcc_debug_લીટી(tcc_state), tcc_tcov_check_લીટી (tcc_state, 1);

    type.ref = ખાલી;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    પસંદગી(tok) {
    સ્થિતિ TOK_EXTENSION:
        next();
        જાઓ tok_next;
    સ્થિતિ TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        જાઓ ધકેલો_tokc;
#endif
    સ્થિતિ TOK_CINT:
    સ્થિતિ TOK_CCHAR: 
	t = VT_INT;
 ધકેલો_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        તોડો;
    સ્થિતિ TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CLLONG:
        t = VT_LLONG;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CFLOAT:
        t = VT_FLOAT;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CDOUBLE:
        t = VT_DOUBLE;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#નહીંતર
        t = VT_LDOUBLE;
#endif
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	જાઓ ધકેલો_tokc;
    સ્થિતિ TOK___FUNCTION__:
        જો (!gnu_ext)
            જાઓ tok_identifier;
        /* fall thru */
    સ્થિતિ TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        જાઓ case_TOK_STR;
    સ્થિતિ TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#નહીંતર
        t = VT_INT;
#endif
        જાઓ str_init;
    સ્થિતિ TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        જો (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, કદ(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        તોડો;
    સ્થિતિ TOK_SOTYPE:
    સ્થિતિ '(':
        t = tok;
        next();
        /* cast ? */
        જો (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            જો (tok == '{') {
                    /* data is allocated locally by default */
                જો (global_પદાવલિ)
                    r = VT_CONST;
                નહીંતર
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                જો (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, કદ(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } નહીંતર જો (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                પાછા;
            } નહીંતર {
                unary();
                gen_cast(&type);
            }
        } નહીંતર જો (tok == '{') {
	    પૂર્ણાંક saved_nocode_wanted = nocode_wanted;
            જો (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            જો (0 == local_scope)
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
            block(STMT_પદાવલિ);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            જો (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } નહીંતર {
            gexpr();
            skip(')');
        }
        તોડો;
    સ્થિતિ '*':
        next();
        unary();
        indir();
        તોડો;
    સ્થિતિ '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        જો ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        જો (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        તોડો;
    સ્થિતિ '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        તોડો;
    સ્થિતિ '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        તોડો;
    સ્થિતિ '+':
        next();
        unary();
        જો ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	જો (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        તોડો;
    સ્થિતિ TOK_SIZEOF:
    સ્થિતિ TOK_ALIGNOF1:
    સ્થિતિ TOK_ALIGNOF2:
    સ્થિતિ TOK_ALIGNOF3:
        t = tok;
        next();
        જો (tok == '(')
            tok = TOK_SOTYPE;
        પદાવલિ_type(&type, unary);
        જો (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } નહીંતર {
            type_size(&type, &align);
            s = ખાલી;
            જો (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            જો (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        તોડો;

    સ્થિતિ TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        તોડો;
    સ્થિતિ TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        તોડો;
    સ્થિતિ TOK_builtin_choose_પદાવલિ:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = પદાવલિ_const64();
	    skip(',');
	    જો (!c) {
		nocode_wanted++;
	    }
	    પદાવલિ_eq();
	    જો (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    જો (c) {
		nocode_wanted++;
	    }
	    પદાવલિ_eq();
	    જો (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        તોડો;
    સ્થિતિ TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	જો ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        તોડો;
    સ્થિતિ TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        તોડો;
    સ્થિતિ TOK_builtin_frame_address:
    સ્થિતિ TOK_builtin_return_address:
        {
            પૂર્ણાંક tok1 = tok;
            પૂર્ણાંક level;
            next();
            skip('(');
            level = પદાવલિ_const();
            જો (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            જ્યારે (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            જો (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#અથવાજો defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#નહીંતર
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        તોડો;
#ifdef TCC_TARGET_RISCV64
    સ્થિતિ TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        જો (r == VT_LLOCAL)
            r = VT_LOCAL;
        જો (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        તોડો;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    સ્થિતિ TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        જો (r == VT_LLOCAL)
            r = VT_LOCAL;
        જો (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        તોડો;
#નહીંતર
    સ્થિતિ TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	તોડો;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    સ્થિતિ TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        તોડો;
    }
    સ્થિતિ TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        તોડો;
    }
#endif
#ifdef TCC_TARGET_ARM64
    સ્થિતિ TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        તોડો;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    સ્થિતિ TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        તોડો;
    }
#endif

    /* atomic operations */
    સ્થિતિ TOK___atomic_store:
    સ્થિતિ TOK___atomic_load:
    સ્થિતિ TOK___atomic_exchange:
    સ્થિતિ TOK___atomic_compare_exchange:
    સ્થિતિ TOK___atomic_fetch_add:
    સ્થિતિ TOK___atomic_fetch_sub:
    સ્થિતિ TOK___atomic_fetch_or:
    સ્થિતિ TOK___atomic_fetch_xor:
    સ્થિતિ TOK___atomic_fetch_and:
    સ્થિતિ TOK___atomic_fetch_nand:
    સ્થિતિ TOK___atomic_add_fetch:
    સ્થિતિ TOK___atomic_sub_fetch:
    સ્થિતિ TOK___atomic_or_fetch:
    સ્થિતિ TOK___atomic_xor_fetch:
    સ્થિતિ TOK___atomic_and_fetch:
    સ્થિતિ TOK___atomic_nand_fetch:
        parse_atomic(tok);
        તોડો;

    /* pre operations */
    સ્થિતિ TOK_INC:
    સ્થિતિ TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        તોડો;
    સ્થિતિ '-':
        next();
        unary();
	જો (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} નહીંતર {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        તોડો;
    સ્થિતિ TOK_LAND:
        જો (!gnu_ext)
            જાઓ tok_identifier;
        next();
        /* allow to take the address of a label */
        જો (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        જો (!s) {
            s = label_ધકેલો(&global_label_ઢગલો, tok, LABEL_FORWARD);
        } નહીંતર {
            જો (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        જો ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        તોડો;

    સ્થિતિ TOK_GENERIC:
    {
	CType controlling_type;
	પૂર્ણાંક has_default = 0;
	પૂર્ણાંક has_match = 0;
	પૂર્ણાંક learn = 0;
	TokenString *str = ખાલી;
	પૂર્ણાંક saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	પદાવલિ_type(&controlling_type, પદાવલિ_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        માટે (;;) {
	    learn = 0;
	    skip(',');
	    જો (tok == TOK_DEFAULT) {
		જો (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		જો (!has_match)
		    learn = 1;
		next();
	    } નહીંતર {
		પૂર્ણાંક v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		જો (compare_types(&controlling_type, &type, 0)) {
		    જો (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    જો (learn) {
		જો (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } નહીંતર {
		skip_or_save_block(ખાલી);
	    }
	    જો (tok == ')')
		તોડો;
	}
	જો (!str) {
	    અક્ષર buf[60];
	    type_to_str(buf, કદ buf, &controlling_type, ખાલી);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	પદાવલિ_eq();
	જો (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	તોડો;
    }
    // special qnan , snan and infinity values
    સ્થિતિ TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        તોડો;
    સ્થિતિ TOK___SNAN__:
	n = 0x7f800001;
	જાઓ special_math_val;
    સ્થિતિ TOK___INF__:
	n = 0x7f800000;
	જાઓ special_math_val;

    મૂળભૂત:
    tok_identifier:
        જો (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        જો (!s || IS_ASM_SYM(s)) {
            અચલ અક્ષર *name = get_tok_str(t, ખાલી);
            જો (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            જો (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        જો ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        જો (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            જો (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } નહીંતર જો (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        તોડો;
    }
    
    /* post operations */
    જ્યારે (1) {
        જો (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } નહીંતર જો (tok == '.' || tok == TOK_ARROW) {
            પૂર્ણાંક qualifiers, cumofs;
            /* field */ 
            જો (tok == TOK_ARROW) 
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
            જો (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            જો (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                જો (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } નહીંતર જો (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } નહીંતર જો (tok == '(') {
            SValue ret;
            Sym *sa;
            પૂર્ણાંક nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            જો ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                જો ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    જો ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        જાઓ error_func;
                } નહીંતર {
                error_func:
                    expect("function pointer");
                }
            } નહીંતર {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            જો ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                જો (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                જો (size < 16)
                    જ્યારે (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    જો (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    જો (ret_nregs < 0)
                      vtop--;
                    નહીંતર
                      nb_args++;
                }
            } નહીંતર {
                ret_nregs = 1;
                ret.type = s->type;
            }

            જો (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ખાલી;
            જો (tok != ')') {
                r = tcc_state->reverse_funcargs;
                માટે(;;) {
                    જો (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } નહીંતર {
                        પદાવલિ_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    જો (sa)
                        sa = sa->next;
                    જો (tok == ')')
                        તોડો;
                    skip(',');
                }
            }
            જો (sa)
                tcc_error("too few arguments to function");

            જો (p) { /* with reverse_funcargs */
                માટે (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    કરો {
                        sa = sa->next, p2 = p2->prev;
                    } જ્યારે (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    પદાવલિ_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            જો (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } નહીંતર {
                /* return value */
                n = ret_nregs;
                જ્યારે (n > 1) {
                    પૂર્ણાંક rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    માટે (r = 0; r < NB_REGS; ++r)
                        જો (reg_classes[r] & rc)
                            તોડો;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                જો (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    પૂર્ણાંક addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    જો (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    માટે (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        જો (--ret_nregs == 0)
                          તોડો;
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
                જો (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#નહીંતર
                    vtop->type.t = VT_INT;
#endif
                }
            }
            જો (s->f.func_noreturn) {
                જો (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } નહીંતર {
            તોડો;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

સ્થિર શૂન્ય પદાવલિ_prod(શૂન્ય)
{
    પૂર્ણાંક t;

    unary();
    જ્યારે ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

સ્થિર શૂન્ય પદાવલિ_sum(શૂન્ય)
{
    પૂર્ણાંક t;

    પદાવલિ_prod();
    જ્યારે ((t = tok) == '+' || t == '-') {
        next();
        પદાવલિ_prod();
        gen_op(t);
    }
}

સ્થિર શૂન્ય પદાવલિ_shift(શૂન્ય)
{
    પૂર્ણાંક t;

    પદાવલિ_sum();
    જ્યારે ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        પદાવલિ_sum();
        gen_op(t);
    }
}

સ્થિર શૂન્ય પદાવલિ_cmp(શૂન્ય)
{
    પૂર્ણાંક t;

    પદાવલિ_shift();
    જ્યારે (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        પદાવલિ_shift();
        gen_op(t);
    }
}

સ્થિર શૂન્ય પદાવલિ_cmpeq(શૂન્ય)
{
    પૂર્ણાંક t;

    પદાવલિ_cmp();
    જ્યારે ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        પદાવલિ_cmp();
        gen_op(t);
    }
}

સ્થિર શૂન્ય પદાવલિ_and(શૂન્ય)
{
    પદાવલિ_cmpeq();
    જ્યારે (tok == '&') {
        next();
        પદાવલિ_cmpeq();
        gen_op('&');
    }
}

સ્થિર શૂન્ય પદાવલિ_xor(શૂન્ય)
{
    પદાવલિ_and();
    જ્યારે (tok == '^') {
        next();
        પદાવલિ_and();
        gen_op('^');
    }
}

સ્થિર શૂન્ય પદાવલિ_or(શૂન્ય)
{
    પદાવલિ_xor();
    જ્યારે (tok == '|') {
        next();
        પદાવલિ_xor();
        gen_op('|');
    }
}

સ્થિર શૂન્ય પદાવલિ_landor(પૂર્ણાંક op);

સ્થિર શૂન્ય પદાવલિ_land(શૂન્ય)
{
    પદાવલિ_or();
    જો (tok == TOK_LAND)
        પદાવલિ_landor(tok);
}

સ્થિર શૂન્ય પદાવલિ_lor(શૂન્ય)
{
    પદાવલિ_land();
    જો (tok == TOK_LOR)
        પદાવલિ_landor(tok);
}

# define પદાવલિ_landor_next(op) op == TOK_LAND ? પદાવલિ_or() : પદાવલિ_land()
#નહીંતર /* defined precedence_parser */
# define પદાવલિ_landor_next(op) unary(), પદાવલિ_infix(precedence(op) + 1)
# define પદાવલિ_lor() unary(), પદાવલિ_infix(1)

સ્થિર પૂર્ણાંક precedence(પૂર્ણાંક tok)
{
    પસંદગી (tok) {
        સ્થિતિ TOK_LOR: પાછા 1;
        સ્થિતિ TOK_LAND: પાછા 2;
	સ્થિતિ '|': પાછા 3;
	સ્થિતિ '^': પાછા 4;
	સ્થિતિ '&': પાછા 5;
	સ્થિતિ TOK_EQ: સ્થિતિ TOK_NE: પાછા 6;
 relat: સ્થિતિ TOK_ULT: સ્થિતિ TOK_UGE: પાછા 7;
	સ્થિતિ TOK_SHL: સ્થિતિ TOK_SAR: પાછા 8;
	સ્થિતિ '+': સ્થિતિ '-': પાછા 9;
	સ્થિતિ '*': સ્થિતિ '/': સ્થિતિ '%': પાછા 10;
	મૂળભૂત:
	    જો (tok >= TOK_ULE && tok <= TOK_GT)
	        જાઓ relat;
	    પાછા 0;
    }
}
સ્થિર unsigned અક્ષર prec[256];
સ્થિર શૂન્ય init_prec(શૂન્ય)
{
    પૂર્ણાંક i;
    માટે (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

સ્થિર શૂન્ય પદાવલિ_landor(પૂર્ણાંક op);

સ્થિર શૂન્ય પદાવલિ_infix(પૂર્ણાંક p)
{
    પૂર્ણાંક t = tok, p2;
    જ્યારે ((p2 = precedence(t)) >= p) {
        જો (t == TOK_LOR || t == TOK_LAND) {
            પદાવલિ_landor(t);
        } નહીંતર {
            next();
            unary();
            જો (precedence(tok) > p2)
              પદાવલિ_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
સ્થિર પૂર્ણાંક condition_3way(શૂન્ય)
{
    પૂર્ણાંક c = -1;
    જો ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    પાછા c;
}

સ્થિર શૂન્ય પદાવલિ_landor(પૂર્ણાંક op)
{
    પૂર્ણાંક t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    માટે(;;) {
        c = f ? i : condition_3way();
        જો (c < 0)
            save_regs(1), cc = 0;
        નહીંતર જો (c != i)
            nocode_wanted++, f = 1;
        જો (tok != op)
            તોડો;
        જો (c < 0)
            t = gvtst(i, t);
        નહીંતર
            vpop();
        next();
        પદાવલિ_landor_next(op);
    }
    જો (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } નહીંતર {
        gvtst_set(i, t);
    }
}

સ્થિર પૂર્ણાંક is_cond_bool(SValue *sv)
{
    જો ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        પાછા (unsigned)sv->c.i < 2;
    જો (sv->r == VT_CMP)
        પાછા 1;
    પાછા 0;
}

સ્થિર શૂન્ય પદાવલિ_cond(શૂન્ય)
{
    પૂર્ણાંક tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    પદાવલિ_lor();
    જો (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        જો (!g) {
            જો (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } નહીંતર {
                vpop();
            }
        } નહીંતર જો (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        જો (c == 0)
          nocode_wanted++;
        જો (!g)
          gexpr();

        જો ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        જો (g) {
            u = tt;
        } નહીંતર જો (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } નહીંતર
          u = 0;

        જો (c == 0)
          nocode_wanted--;
        જો (c == 1)
          nocode_wanted++;
        skip(':');
        પદાવલિ_cond();

        જો ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        જો (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        જો (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            પાછા;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        જો (c != 1) {
            gen_cast(&type);
            જો (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        જો (USING_TWO_શબ્દો(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        જો (c < 0) {
            જો (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        જો (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        જો (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            જો (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        જો (c < 0) {
            જો (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        જો (islv)
          indir();
    }
}

સ્થિર શૂન્ય પદાવલિ_eq(શૂન્ય)
{
    પૂર્ણાંક t;
    
    પદાવલિ_cond();
    જો ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        જો (t == '=') {
            પદાવલિ_eq();
        } નહીંતર {
            vdup();
            પદાવલિ_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC શૂન્ય gexpr(શૂન્ય)
{
    પદાવલિ_eq();
    જો (tok == ',') {
        કરો {
            vpop();
            next();
            પદાવલિ_eq();
        } જ્યારે (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        જો ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            જો (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
સ્થિર શૂન્ય પદાવલિ_const1(શૂન્ય)
{
    nocode_wanted += CONST_WANTED_BIT;
    પદાવલિ_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
સ્થિર અંતઃરેખ int64_t પદાવલિ_const64(શૂન્ય)
{
    int64_t c;
    પદાવલિ_const1();
    જો ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    પાછા c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC પૂર્ણાંક પદાવલિ_const(શૂન્ય)
{
    પૂર્ણાંક c;
    int64_t wc = પદાવલિ_const64();
    c = wc;
    જો (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    પાછા c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
સ્થિર શૂન્ય gfunc_return(CType *func_type)
{
    જો ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        પૂર્ણાંક ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        જો (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } નહીંતર જો (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } નહીંતર {
            /* returning structure packed into registers */
            પૂર્ણાંક size, addr, align, rc, n;
            size = type_size(func_type,&align);
            જો (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		જો (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		જો (ret_align > align)
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
            માટે (n = ret_nregs; --n > 0;) {
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
    } નહીંતર {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

સ્થિર શૂન્ય check_func_return(શૂન્ય)
{
    જો ((func_vt.t & VT_BTYPE) == VT_VOID)
        પાછા;
    જો ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } નહીંતર {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

સ્થિર પૂર્ણાંક case_cmp(uint64_t a, uint64_t b)
{
    જો (cur_switch->sv.type.t & VT_UNSIGNED)
        પાછા a < b ? -1 : a > b;
    નહીંતર
        પાછા (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

સ્થિર પૂર્ણાંક case_cmp_qs(અચલ શૂન્ય *pa, અચલ શૂન્ય *pb)
{
    પાછા case_cmp((*(સંરચના case_t**)pa)->v1, (*(સંરચના case_t**)pb)->v1);
}

સ્થિર શૂન્ય case_sort(સંરચના switch_t *sw)
{
    સંરચના case_t **p;
    જો (sw->n < 2)
        પાછા;
    qsort(sw->p, sw->n, કદ *sw->p, case_cmp_qs);
    p = sw->p;
    જ્યારે (p < sw->p + sw->n - 1) {
        જો (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            પૂર્ણાંક l1 = p[0]->લીટી, l2 = p[1]->લીટી;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } નહીંતર જો (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * કદ *p);
        } નહીંતર
            ++p;
    }
}

સ્થિર પૂર્ણાંક gcase(સંરચના case_t **base, પૂર્ણાંક len, પૂર્ણાંક dsym)
{
    સંરચના case_t *p;
    પૂર્ણાંક t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    જો (t != VT_LLONG)
        t = VT_INT;
    જ્યારે (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        જો (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } નહીંતર {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            જો (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            નહીંતર
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
    પાછા gjmp(dsym);
}

સ્થિર શૂન્ય end_switch(શૂન્ય)
{
    સંરચના switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
સ્થિર શૂન્ય save_lvalues(શૂન્ય)
{
    SValue *sv = vtop;
    જ્યારે (sv >= vstack) {
        જો (sv->sym && (sv->r & VT_LVAL)) {
            પૂર્ણાંક align, size = type_size(&sv->type, &align);
            પૂર્ણાંક r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

સ્થિર શૂન્ય try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    માટે (; cls != stop; cls = cls->next) {
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


સ્થિર શૂન્ય try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    પૂર્ણાંક ocd, ccd;

    જો (!cur_scope->cl.s)
	પાછા;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    માટે (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    માટે (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    માટે (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
સ્થિર શૂન્ય block_cleanup(સંરચના scope *o)
{
    પૂર્ણાંક jmp = 0;
    Sym *g, **pg;
    માટે (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        જો (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            જો (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            જો (!o->cl.n)
                જાઓ remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } નહીંતર {
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

સ્થિર શૂન્ય vla_restore(પૂર્ણાંક loc)
{
    જો (loc)
        gen_vla_sp_restore(loc);
}

સ્થિર શૂન્ય vla_leave(સંરચના scope *o)
{
    સંરચના scope *c = cur_scope, *v = ખાલી;
    માટે (; c != o && c; c = c->prev)
      જો (c->vla.અંક)
        v = c;
    જો (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

સ્થિર શૂન્ય new_scope(સંરચના scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.અંક = 0;

    /* record local declaration stack position */
    o->lstk = local_ઢગલો;
    o->llstk = local_label_ઢગલો;
    ++local_scope;
}

સ્થિર શૂન્ય prev_scope(સંરચના scope *o, પૂર્ણાંક is_પદાવલિ)
{
    vla_leave(o->prev);

    જો (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    જો (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_પદાવલિ);

    /* pop locally defined labels */
    label_કાઢો(&local_label_ઢગલો, o->llstk, is_પદાવલિ);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_કાઢો(&local_ઢગલો, o->lstk, is_પદાવલિ);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
સ્થિર શૂન્ય leave_scope(સંરચના scope *o)
{
    જો (!o)
        પાછા;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
સ્થિર શૂન્ય new_scope_s(સંરચના scope *o)
{
    o->lstk = local_ઢગલો;
    ++local_scope;
}

સ્થિર શૂન્ય prev_scope_s(સંરચના scope *o)
{
    sym_કાઢો(&local_ઢગલો, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

સ્થિર શૂન્ય lblock(પૂર્ણાંક *bsym, પૂર્ણાંક *csym)
{
    સંરચના scope *lo = loop_scope, *co = cur_scope;
    પૂર્ણાંક *b = co->bsym, *c = co->csym;
    જો (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    જો (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
સ્થિર શૂન્ય gexpr_decl(શૂન્ય)
{
    પૂર્ણાંક v = decl(VT_JMP);
    જો (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } નહીંતર {
        જો (v)
            skip(';');
        gexpr();
    }
}

સ્થિર શૂન્ય block(પૂર્ણાંક flags)
{
    પૂર્ણાંક a, b, c, d, e, t;
    સંરચના scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    જો (TOK_HAS_કિંમત(t))
        જાઓ પદાવલિ;
    next();

    જો (debug_modes)
        tcc_tcov_check_લીટી (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    જો (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        જો (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } નહીંતર {
            gsym(a);
        }
        prev_scope_s(&o);

    } નહીંતર જો (t == TOK_WHILE) {
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

    } નહીંતર જો (t == '{') {
        જો (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        જ્યારે (tok == TOK_LABEL) {
            કરો {
                next();
                જો (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ધકેલો(&local_label_ઢગલો, tok, LABEL_DECLARED);
                next();
            } જ્યારે (tok == ',');
            skip(';');
        }

        જ્યારે (tok != '}') {
	    decl(VT_LOCAL);
            જો (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_પદાવલિ);
        જો (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        જો (local_scope)
            next();
        નહીંતર જો (!nocode_wanted)
            check_func_return();

    } નહીંતર જો (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        જો (tok != ';') {
            gexpr();
            જો (b) {
                gen_assign_cast(&func_vt);
            } નહીંતર {
                જો (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } નહીંતર જો (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } નહીંતર જો (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(મૂળ_scope);
        જો (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        જો (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        જો (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } નહીંતર જો (t == TOK_BREAK) {
        /* compute jump */
        જો (!cur_scope->bsym)
            tcc_error("cannot break");
        જો (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        નહીંતર
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } નહીંતર જો (t == TOK_CONTINUE) {
        /* compute jump */
        જો (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } નહીંતર જો (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        જો (tok != ';') {
            /* c99 for-loop init decl? */
            જો (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        જો (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        જો (tok != ')') {
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

    } નહીંતર જો (t == TOK_DO) {
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

    } નહીંતર જો (t == TOK_SWITCH) {
        સંરચના switch_t *sw;

        sw = tcc_mallocz(કદ *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        જો (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ખાલી);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        જો (sw->nocode_wanted)
            જાઓ skip_switch;
        case_sort(sw);
        sw->bsym = ખાલી; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        જો (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        નહીંતર
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } નહીંતર જો (t == TOK_CASE) {
        સંરચના case_t *cr;
        જો (!cur_switch)
            expect("switch");
        cr = tcc_malloc(કદ(સંરચના case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(પદાવલિ_const64(), t);
        જો (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(પદાવલિ_const64(), t);
            જો (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        જો (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->લીટી = file->લીટી_અંક;
        skip(':');
        જાઓ block_after_label;

    } નહીંતર જો (t == TOK_DEFAULT) {
        જો (!cur_switch)
            expect("switch");
        જો (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        જાઓ block_after_label;

    } નહીંતર જો (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        જો (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            જો ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } નહીંતર જો (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            જો (!s)
              s = label_ધકેલો(&global_label_ઢગલો, tok, LABEL_FORWARD);
            નહીંતર જો (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    જો (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		જો (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } નહીંતર {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } નહીંતર {
            expect("label identifier");
        }
        skip(';');

    } નહીંતર જો (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } નહીંતર {
        જો (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            જો (s) {
                જો (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ખાલી));
                s->r = LABEL_DEFINED;
		જો (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    માટે (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_કાઢો(&s->next, ખાલી, 0);
		} નહીંતર
		  gsym(s->jnext);
            } નહીંતર {
                s = label_ધકેલો(&global_label_ઢગલો, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ખાલી);

            જો (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            જો (tok != '}') {
                જો (0 == (flags & STMT_COMPOUND))
                    જાઓ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } નહીંતર {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } નહીંતર {
            /* expression case */
            જો (t != ';') {
                unget_tok(t);
    પદાવલિ:
                જો (flags & STMT_પદાવલિ) {
                    vpop();
                    gexpr();
                } નહીંતર {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    જો (debug_modes)
        tcc_tcov_check_લીટી (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
સ્થિર શૂન્ય skip_or_save_block(TokenString **str)
{
    પૂર્ણાંક braces = tok == '{';
    પૂર્ણાંક level = 0;
    જો (str)
      *str = tok_str_alloc();

    જ્યારે (1) {
	પૂર્ણાંક t = tok;
        જો (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             તોડો;
	જો (t == TOK_EOF) {
	     જો (str || level > 0)
	       tcc_error("unexpected end of file");
	     નહીંતર
	       તોડો;
	}
	જો (str)
	  tok_str_add_tok(*str);
	next();
	જો (t == '{' || t == '(' || t == '[') {
	    level++;
	} નહીંતર જો (t == '}' || t == ')' || t == ']') {
	    level--;
	    જો (level == 0 && braces && t == '}')
	      તોડો;
	}
    }
    જો (str)
	tok_str_add(*str, TOK_EOF);
}

#define પદાવલિ_CONST 1
#define પદાવલિ_ANY   2

સ્થિર શૂન્ય parse_init_elem(પૂર્ણાંક પદાવલિ_type)
{
    પૂર્ણાંક saved_global_પદાવલિ;
    પસંદગી(પદાવલિ_type) {
    સ્થિતિ પદાવલિ_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_પદાવલિ = global_પદાવલિ;
        global_પદાવલિ = 1;
        પદાવલિ_const1();
        global_પદાવલિ = saved_global_પદાવલિ;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        જો (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        તોડો;
    સ્થિતિ પદાવલિ_ANY:
        પદાવલિ_eq();
        તોડો;
    }
}

#જો 1
સ્થિર શૂન્ય init_assert(init_params *p, પૂર્ણાંક offset)
{
    જો (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#નહીંતર
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
સ્થિર શૂન્ય init_putz(init_params *p, unsigned long c, પૂર્ણાંક size)
{
    init_assert(p, c + size);
    જો (p->sec) {
        /* nothing to do because globals are already set to zero */
    } નહીંતર {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#જો defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
સ્થિર શૂન્ય decl_design_delrels(Section *sec, પૂર્ણાંક c, પૂર્ણાંક size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    જો (!sec || !sec->reloc)
        પાછા;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    જ્યારે (rel < rel_end) {
        જો (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= કદ *rel;
        } નહીંતર {
            જો (rel2 != rel)
                memcpy(rel2, rel, કદ *rel);
            ++rel2;
        }
        ++rel;
    }
}

સ્થિર શૂન્ય decl_design_flex(init_params *p, Sym *ref, પૂર્ણાંક index)
{
    જો (ref == p->flex_array_ref) {
        જો (index >= ref->c)
            ref->c = index + 1;
    } નહીંતર જો (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
સ્થિર પૂર્ણાંક decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, પૂર્ણાંક flags, પૂર્ણાંક al)
{
    Sym *s, *f;
    પૂર્ણાંક index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    જો (flags & DIF_HAVE_ELEM)
        જાઓ no_designator;

    જો (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        જો (tok == ':')
            જાઓ struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    જ્યારે (nb_elems == 1 && (tok == '[' || tok == '.')) {
        જો (tok == '[') {
            જો (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = પદાવલિ_const();
            જો (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = પદાવલિ_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            જો (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            જો (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } નહીંતર {
            પૂર્ણાંક cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            જો (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = ખાલી;
    }
    જો (!cur_field) {
        જો (tok == '=') {
            next();
        } નહીંતર જો (!gnu_ext) {
	    expect("=");
        }
    } નહીંતર {
    no_designator:
        જો (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            જો (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } નહીંતર {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    જ્યારે (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            જો (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    જો (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    જો (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    જો (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        પૂર્ણાંક i;
        જો (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        જો (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        નહીંતર
	    vset(type, VT_LOCAL|VT_LVAL, c);
        માટે (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    જો (c - corig > al)
      al = c - corig;
    પાછા al;
}

સ્થિર શૂન્ય write_ldouble(unsigned અક્ષર *d, શૂન્ય *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    જો (LDOUBLE_SIZE >= 10) {
        દ્વિગુણ b = *(long દ્વિગુણ*)s;
        s = &b;
#નહીંતર
    જો (કદ (long દ્વિગુણ) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        પૂર્ણાંક e = m >> 48;
        પૂર્ણાંક f = e >> 4 & 0x7FF;
        m <<= 11;
        જો (0 == f) {
            જો (0 == m)
                જાઓ set;
            માટે (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        જો (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #જો (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #અથવાજો LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } નહીંતર {
    #જો LDOUBLE_SIZE == 8
        /* long double -> double */
        દ્વિગુણ b = *(long દ્વિગુણ*)s;
        memcpy(d, &b, 8);
    #અથવાજો (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #અથવાજો (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        પૂર્ણાંક e = *(uint16_t*)((અક્ષર*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #અથવાજો (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((અક્ષર*)s + 6);
        પૂર્ણાંક e = read16le((અક્ષર*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #નહીંતર
        /* unknown */
        જો (કદ (long દ્વિગુણ) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
સ્થિર શૂન્ય init_putv(init_params *p, CType *type, unsigned long c)
{
    પૂર્ણાંક bt;
    શૂન્ય *ptr;
    CType dtype;
    પૂર્ણાંક size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    જો (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    જો (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        જો ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        જો (NODATA_WANTED) {
            vtop--;
            પાછા;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	જો ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_કિંમત + (પૂર્ણાંક)vtop->c.i, size);
	    જો (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		જ્યારે (relofs >= કદ(*rel)) {
                    relofs -= કદ(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    જો (rel->r_offset >= esym->st_કિંમત + size)
		      ચાલુ;
		    જો (rel->r_offset < esym->st_કિંમત)
		      તોડો;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_કિંમત,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#જો PTR_SIZE == 8
				   rel->r_addend
#નહીંતર
				   0
#endif
				  );
		}
	    }
	} નહીંતર {
            જો (type->t & VT_BITFIELD) {
                પૂર્ણાંક bit_pos, bit_size, bits, n;
                unsigned અક્ષર *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned અક્ષર*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                જ્યારે (bit_size) {
                    n = 8 - bit_pos;
                    જો (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } નહીંતર
            પસંદગી(bt) {
	    સ્થિતિ VT_BOOL:
		*(અક્ષર *)ptr = val != 0;
                તોડો;
	    સ્થિતિ VT_BYTE:
		*(અક્ષર *)ptr = val;
		તોડો;
	    સ્થિતિ VT_SHORT:
                write16le(ptr, val);
		તોડો;
	    સ્થિતિ VT_FLOAT:
                write32le(ptr, val);
		તોડો;
	    સ્થિતિ VT_DOUBLE:
                write64le(ptr, val);
		તોડો;
	    સ્થિતિ VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		તોડો;

#જો PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    સ્થિતિ VT_LLONG:
	    સ્થિતિ VT_PTR:
	        જો (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        નહીંતર
	          write64le(ptr, val);
	        તોડો;
            સ્થિતિ VT_INT:
                write32le(ptr, val);
                તોડો;
#નહીંતર
	    સ્થિતિ VT_LLONG:
                write64le(ptr, val);
                તોડો;
            સ્થિતિ VT_PTR:
            સ્થિતિ VT_INT:
	        જો (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        તોડો;
#endif
	    મૂળભૂત:
                //tcc_internal_error("unexpected type");
                તોડો;
	    }
	}
        vtop--;
    } નહીંતર {
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
સ્થિર શૂન્ય decl_initializer(init_params *p, CType *type, unsigned long c, પૂર્ણાંક flags)
{
    પૂર્ણાંક len, n, no_oblock, i;
    પૂર્ણાંક size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    જો (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_લીટી(tcc_state), tcc_tcov_check_લીટી (tcc_state, 1);

    જો (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        પૂર્ણાંક ncw_prev = nocode_wanted;
        જો ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? પદાવલિ_ANY : પદાવલિ_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    જો (type->t & VT_ARRAY) {
        no_oblock = 1;
        જો (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        જો ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#નહીંતર
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            જો (size1 != (tok == TOK_STR ? 1 : કદ(nwchar_t)))
              tcc_error("unhandled string literal merging");
            જ્યારે (tok == TOK_STR || tok == TOK_LSTR) {
                જો (initstr.size)
                  initstr.size -= size1;
                જો (tok == TOK_STR)
                  len += tokc.str.size;
                નહીંતર
                  len += tokc.str.size / કદ(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            જો (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                જાઓ do_init_array;
            }

            decl_design_flex(p, s, len);
            જો (!(flags & DIF_SIZE_ONLY)) {
                પૂર્ણાંક nb = n, ch;
                જો (len < nb)
                    nb = len;
                જો (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                જો (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    જો (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } નહીંતર {
                    માટે(i=0;i<n;i++) {
                        જો (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          જો (flags & DIF_CLEAR)
                            તોડો;
                          જો (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            તોડો;
                          }
                          ch = 0;
                        } નહીંતર જો (size1 == 1)
                          ch = ((unsigned અક્ષર *)initstr.data)[i];
                        નહીંતર
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            જો (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } નહીંતર {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            જો (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    જ્યારે (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		જો (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    જો (no_oblock && len >= n*size1)
		        તોડો;
		} નહીંતર {
		    જો (s->type.t == VT_UNION)
		        f = ખાલી;
		    નહીંતર
		        f = f->next;
		    જો (no_oblock && f == ખાલી)
		        તોડો;
		}

		જો (tok == '}')
		    તોડો;
		skip(',');
	    }
        }
        જો (!no_oblock)
            skip('}');

    } નહીંતર જો ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        જાઓ one_elem;

    } નહીંતર જો ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        જો ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	જાઓ do_init_list;

    } નહીંતર જો (tok == '{') {
        જો (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } નહીંતર one_elem: જો ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        જો (flags & DIF_HAVE_ELEM)
            vpop();
        નહીંતર
            skip_or_save_block(ખાલી);

    } નહીંતર {
	જો (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    જો (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? પદાવલિ_ANY : પદાવલિ_CONST);
	}
        જો (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        નહીંતર
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
સ્થિર શૂન્ય decl_initializer_alloc(CType *type, AttributeDef *ad, પૂર્ણાંક r, 
                                   પૂર્ણાંક has_init, પૂર્ણાંક v, પૂર્ણાંક scope)
{
    પૂર્ણાંક size, align, addr;
    TokenString *init_str = ખાલી;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ખાલી;
    પૂર્ણાંક saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    પૂર્ણાંક bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    જો (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        જો (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            જો (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                પાછા;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    જો (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = ખાલી;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    જો (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        જો (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        જો (IS_BT_ARRAY(type->t))
            type->ref = sym_ધકેલો(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } નહીંતર જો (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        જો (field) {
            જ્યારે (field->next)
                field = field->next;
            જો (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    જો (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        જો (!has_init)
            જાઓ err_size;
        જો (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            જ્યારે (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } નહીંતર
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
        જો (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        જો (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    જો (ad->a.aligned) {
	પૂર્ણાંક speca = 1 << (ad->a.aligned - 1);
        જો (speca > align)
            align = speca;
    } નહીંતર જો (ad->a.packed) {
        align = 1;
    }

    જો (!v && NODATA_WANTED)
        size = 0, align = 1;

    જો ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ખાલી;
#ifdef CONFIG_TCC_BCHECK
        જો (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        જો (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        જો (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    જો (ad->asm_label) {
		પૂર્ણાંક reg = asm_parse_regvar(ad->asm_label);
		જો (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_ધકેલો(v, type, r, addr);
	    જો (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } નહીંતર {
            /* push local reference */
            vset(type, r, addr);
        }
    } નહીંતર {
        CType *tp = type;
        પૂર્ણાંક is_const;

        જ્યારે ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        જો (!sec) {
            જો (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } નહીંતર જો (is_const) {
		sec = rodata_section;
            } નહીંતર જો (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } નહીંતર જો (tcc_state->nocommon)
                sec = bss_section;
        } નહીંતર જો (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            જો (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                જો (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        જો (bcheck)
            size = size + 1; /* add padding */
#endif
        જો (sec) {
	    addr = section_add(sec, size, align);
        } નહીંતર {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        જો (v) {
            જો (!sym) {
                sym = sym_ધકેલો(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ખાલી);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } નહીંતર {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        જો (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * કદ(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    જો (type->t & VT_VLA) {
        પૂર્ણાંક a;

        જો (has_init)
            tcc_error("variable length array cannot be initialized");

        જો (NODATA_WANTED)
            જાઓ no_alloc;

        /* save before-VLA stack pointer if needed */
        જો (cur_scope->vla.અંક == 0) {
            જો (cur_scope->prev && cur_scope->prev->vla.અંક) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } નહીંતર {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#જો defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.અંક++;
    } નહીંતર જો (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        જો (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    જો (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
સ્થિર શૂન્ય func_vla_arg_code(Sym *arg)
{
    પૂર્ણાંક align;
    TokenString *vla_array_tok = ખાલી;

    જો (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    જો ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

સ્થિર શૂન્ય func_vla_arg(Sym *sym)
{
    Sym *arg;

    માટે (arg = sym->type.ref->next; arg; arg = arg->next)
        જો ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, પૂર્ણાંક c, પૂર્ણાંક byref)
{
    s = sym_find(s->v);
    જો (!s) /* unnamed parameters, not enabled */
        પાછા ખાલી;
    s->c = c;
    જો (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    પાછા s;
}

/* push parameters (and their types), last first */
સ્થિર શૂન્ય sym_ધકેલો_params(Sym *ref)
{
    Sym *s = ref;
    જ્યારે (s->next)
        s = s->next;
    જ્યારે (s != ref) {
        જો ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_ઢગલો);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
સ્થિર શૂન્ય gen_function(Sym *sym)
{
    સંરચના scope f = { 0 };

    cur_scope = મૂળ_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    જો (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ખાલી);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    જો (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    જો (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ઢગલો, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ધકેલો_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(ખાલી, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_કાઢો(&local_ઢગલો, ખાલી, 0);
    label_કાઢો(&global_label_ઢગલો, ખાલી, 0);
    sym_કાઢો(&all_cleanups, ખાલી, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = ખાલી;
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

સ્થિર શૂન્ય gen_inline_functions(TCCState *s)
{
    Sym *sym;
    પૂર્ણાંક inline_generated, i;
    સંરચના InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    કરો {
        inline_generated = 0;
        માટે (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            જો (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ખાલી;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } જ્યારે (inline_generated);
    tcc_close();
}

સ્થિર શૂન્ય free_inline_functions(TCCState *s)
{
    પૂર્ણાંક i;
    /* free tokens of unused inline functions */
    માટે (i = 0; i < s->nb_inline_fns; ++i) {
        સંરચના InlineFunc *fn = s->inline_fns[i];
        જો (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

સ્થિર શૂન્ય do_Static_assert(શૂન્ય)
{
    પૂર્ણાંક c;
    અચલ અક્ષર *સંદેશ;

    next();
    skip('(');
    c = પદાવલિ_const();
    સંદેશ = "_Static_assert fail";
    જો (tok == ',') {
        next();
        સંદેશ = parse_mult_str("string constant")->data;
    }
    skip(')');
    જો (c == 0)
        tcc_error("%s", સંદેશ);
    skip(';');
}

#ifdef TCC_TARGET_PE
સ્થિર શૂન્ય pe_check_linkage(CType *type, AttributeDef *ad)
{
    જો (!ad->a.dllimport && !ad->a.dllexport)
        પાછા;
    જો (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    જો (type->t & VT_TYPEDEF) {
        અચલ અક્ષર *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } નહીંતર જો (ad->a.dllimport) {
        જો ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        નહીંતર
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
સ્થિર પૂર્ણાંક decl(પૂર્ણાંક l)
{
    પૂર્ણાંક v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    જ્યારે (1) {

        oldint = 0;
        જો (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            જો (l == VT_JMP)
                પાછા 0;
            /* skip redundant ';' if not in old parameter decl scope */
            જો (tok == ';' && l != VT_CMP) {
                next();
                ચાલુ;
            }
            જો (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                ચાલુ;
            }
            જો (l != VT_CONST)
                તોડો;
            જો (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                ચાલુ;
            }
            જો (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } નહીંતર {
                જો (tok != TOK_EOF)
                    expect("declaration");
                તોડો;
            }
        }

        જો (tok == ';') {
            જો ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            નહીંતર જો (IS_ENUM(btype.t))
                ; /* enum decl */
            નહીંતર
                tcc_warning("useless type defines no instances");
            જો (l == VT_JMP)
                પાછા 1;
            next();
            ચાલુ;
        }

        જ્યારે (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            જો ((type.t & VT_BTYPE) == VT_FUNC) {
                જો ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                જો (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                જો ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    જો (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    નહીંતર
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } નહીંતર જો (oldint) {
                tcc_warning("type defaults to int");
            }

            જો (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #જો 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                જો (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            જો (tok == '{') {
                જો (l != VT_CONST)
                    tcc_error("cannot use local functions");
                જો ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                માટે (sa = sym->type.ref; (sa = sa->next) != ખાલી;) {
                    જો (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    જો (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                જો (sym->type.t & VT_INLINE) {
                    સંરચના InlineFunc *fn;
                    fn = tcc_malloc(કદ *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } નહીંતર {
                    /* compute text section */
                    cur_text_section = text_section;
                    જો (ad.section) {
                        cur_text_section = ad.section;
                        જો (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                તોડો;
            } નહીંતર {
                has_init = 0;
		જો (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    માટે (sym = func_vt.ref->next; sym; sym = sym->next)
			જો ((sym->v & ~SYM_FIELD) == v)
			    જાઓ found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ખાલી));
                found:
		    જો (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ખાલી));
		    જો (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ખાલી));
		    convert_parameter_type(&type);
		    sym->type = type;
		} નહીંતર જો (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    જો (sym && sym->sym_scope == local_scope) {
                        જો (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ખાલી));
                        sym->type = type;
                    } નહીંતર {
                        sym = sym_ધકેલો(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    જો ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    જો (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} નહીંતર જો ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } નહીંતર {
                    r = 0;
                    જો ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } નહીંતર જો (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    જો (tok == '=')
                        has_init = 1;

                    જો (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } નહીંતર {
                        જો (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        નહીંતર
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        જો (has_init)
                            next();
                        નહીંતર જો (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    જો (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        જો (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_કિંમત, esym->st_size, 1);
                    }
                }
                જો (tok != ',') {
                    જો (l == VT_JMP)
                        પાછા has_init ? v : 1;
                    skip(';');
                    તોડો;
                }
                next();
            }
        }
    }
    પાછા 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
